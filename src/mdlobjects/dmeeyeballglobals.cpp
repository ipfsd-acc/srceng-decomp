// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeeyeballglobals.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmeeyeballglobals.h"

//------------------------------------------------------------------------------
// Address: 0x004A4BE0
// Name: public: virtual bool CDmeEyeballGlobals::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeballGlobals::IsA(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4C10
// Name: public: virtual int CDmeEyeballGlobals::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeballGlobals::GetInheritanceDepth(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4CD0
// Name: protected: virtual void CDmeEyeballGlobals::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeballGlobals::PerformConstruction(CDmeEyeballGlobals *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_vEyePosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "eyePosition",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vEyePosition);
  value = 90.0;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maximumEyeDeflection",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxEyeDeflection);
  this->m_flMaxEyeDeflection.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00599C60
// Name: _dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeballGlobals::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeballGlobals pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E680
// Name: _dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeballGlobals::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599C90
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599CA0
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeballGlobals_Helper,
           classname: "DmeEyeballGlobals",
           pFactory: &g_CDmeEyeballGlobals_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E690
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeballGlobals_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E6BD0
// Name: public: virtual bool CDmeEyeballGlobals::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeballGlobals::IsA(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6C00
// Name: public: virtual int CDmeEyeballGlobals::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeballGlobals::GetInheritanceDepth(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6CB0
// Name: protected: virtual void CDmeEyeballGlobals::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeballGlobals::PerformConstruction(CDmeEyeballGlobals *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_vEyePosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "eyePosition",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vEyePosition);
  value = 90.0;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maximumEyeDeflection",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxEyeDeflection);
  this->m_flMaxEyeDeflection.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005EDCA0
// Name: _dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeballGlobals::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeballGlobals pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3570
// Name: _dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeballGlobals::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDCD0
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDCE0
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeballGlobals_Helper,
           classname: "DmeEyeballGlobals",
           pFactory: &g_CDmeEyeballGlobals_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3580
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeballGlobals_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00514750
// Name: public: virtual bool CDmeEyeballGlobals::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeballGlobals::IsA(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514780
// Name: public: virtual int CDmeEyeballGlobals::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeballGlobals::GetInheritanceDepth(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514830
// Name: protected: virtual void CDmeEyeballGlobals::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeballGlobals::PerformConstruction(CDmeEyeballGlobals *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_vEyePosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "eyePosition",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vEyePosition);
  value = 90.0;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maximumEyeDeflection",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxEyeDeflection);
  this->m_flMaxEyeDeflection.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x006AE060
// Name: _dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeballGlobals::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeballGlobals pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4450
// Name: _dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeballGlobals::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE090
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE0A0
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeballGlobals_Helper,
           classname: "DmeEyeballGlobals",
           pFactory: &g_CDmeEyeballGlobals_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4460
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEyeballGlobals_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E41E0
// Name: public: virtual bool CDmeEyeballGlobals::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeballGlobals::IsA(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E4210
// Name: public: virtual int CDmeEyeballGlobals::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeballGlobals::GetInheritanceDepth(CDmeEyeballGlobals *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeballGlobals::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E42D0
// Name: protected: virtual void CDmeEyeballGlobals::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeballGlobals::PerformConstruction(CDmeEyeballGlobals *this)
{
  CDmAttribute *v2; // eax
  float value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  this->m_vEyePosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "eyePosition",
                                        type: AT_VECTOR3,
                                        pMemory: &this->m_vEyePosition);
  value = 90.0;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maximumEyeDeflection",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxEyeDeflection);
  this->m_flMaxEyeDeflection.m_pAttribute = v2;
  CDmAttribute::SetValue<float>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005E7740
// Name: _dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeballGlobals::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeballGlobals pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC810
// Name: _dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeballGlobals::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeballGlobals::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E7770
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeballGlobals_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E7780
// Name: _dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeballGlobals_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeballGlobals_Helper,
           classname: "DmeEyeballGlobals",
           pFactory: &g_CDmeEyeballGlobals_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC820
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeballGlobals_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeballGlobals_Factory.m_CallBackList);
}

} // namespace studiomdl
