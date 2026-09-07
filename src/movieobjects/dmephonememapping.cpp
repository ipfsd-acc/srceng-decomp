// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmephonememapping.cpp
// Functions: 8
// ============================================================

#include "movieobjects\dmephonememapping.h"

//------------------------------------------------------------------------------
// Address: 0x0055F6C0
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F6F0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F7A0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005AE620
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B08B0
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AE650
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AE660
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B08C0
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005BBB00
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BBB30
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005BBBE0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0067FFE0
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682E60
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680010
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680020
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682E70
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1059A6C0
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A6F0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A7A0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x105C9D80
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCD0
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9DB0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9DC0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCE0
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056B570
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B5A0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056B650
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0059D660
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA00
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D690
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D6A0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059FA10
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005B45B0
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B45E0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B4690
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005F2300
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D10
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F2330
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2340
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4D20
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00523D60
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523D90
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523E50
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0056CBC0
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F040
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056CBF0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC00
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F050
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0052B0C0
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B0F0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052B1A0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0057CCE0
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F170
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD10
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CD20
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F180
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E9300
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E9330
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E93E0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x006B1E30
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5960
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1E60
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1E70
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5970
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0052C210
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C240
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C2F0
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECB0
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581150
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECE0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECF0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581160
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005AD530
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD560
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD610
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005EB1A0
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBB0
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EB1D0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EB1E0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDBC0
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00532690
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005326C0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00532770
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0057C500
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E840
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C530
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C540
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E850
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x006357B0
// Name: public: virtual bool CDmePhonemeMapping::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePhonemeMapping::IsA(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x006357E0
// Name: public: virtual int CDmePhonemeMapping::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePhonemeMapping::GetInheritanceDepth(CDmePhonemeMapping *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePhonemeMapping::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00635890
// Name: protected: virtual void CDmePhonemeMapping::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePhonemeMapping::PerformConstruction(CDmePhonemeMapping *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Preset.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "preset",
                                  type: AT_STRING,
                                  pMemory: &this->m_Preset);
  value = 1.0;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "weight", type: AT_FLOAT, pMemory: &this->m_Weight);
  this->m_Weight.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x006BA470
// Name: _dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePhonemeMapping::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePhonemeMapping pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD660
// Name: _dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePhonemeMapping::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePhonemeMapping::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BA4A0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePhonemeMapping_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BA4B0
// Name: _dynamic_initializer_for__g_CDmePhonemeMapping_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePhonemeMapping_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePhonemeMapping_Helper,
           classname: "DmePhonemeMapping",
           pFactory: &g_CDmePhonemeMapping_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD670
// Name: _dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePhonemeMapping_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePhonemeMapping_Factory.m_CallBackList);
}

} // namespace vmap
