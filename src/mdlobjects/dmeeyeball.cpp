// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmeeyeball.cpp
// Functions: 9
// ============================================================

#include "mdlobjects\dmeeyeball.h"

//------------------------------------------------------------------------------
// Address: 0x004A4D30
// Name: protected: void CDmeEyeball::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::OnConstruction(CDmeEyeball *this)
{
  CDmaVar<float> *p_m_flRadius; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flRadius = &this->m_flRadius;
  value = 0.5;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "radius", type: AT_FLOAT, pMemory: &this->m_flRadius);
  p_m_flRadius->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 2.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "angle", type: AT_FLOAT, pMemory: &this->m_flYawAngle);
  this->m_flYawAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "irisScale",
         type: AT_FLOAT,
         pMemory: &this->m_flIrisScale);
  this->m_flIrisScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_sMaterialName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "materialName",
                                         type: AT_STRING,
                                         pMemory: &this->m_sMaterialName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_vPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "position",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_vPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004A4EA0
// Name: public: virtual bool CDmeEyeball::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeball::IsA(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4ED0
// Name: public: virtual int CDmeEyeball::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeball::GetInheritanceDepth(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A4FA0
// Name: protected: virtual void CDmeEyeball::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::PerformConstruction(CDmeEyeball *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyeball::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00599CC0
// Name: _dynamic_initializer_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeball::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeball pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6A0
// Name: _dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeball::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00599CF0
// Name: _dynamic_initializer_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeball_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00599D00
// Name: _dynamic_initializer_for__g_CDmeEyeball_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeball_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeball_Helper,
           classname: "DmeEyeball",
           pFactory: &g_CDmeEyeball_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E6B0
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeball_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E68B0
// Name: protected: void CDmeEyeball::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::OnConstruction(CDmeEyeball *this)
{
  CDmaVar<float> *p_m_flRadius; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flRadius = &this->m_flRadius;
  value = 0.5;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "radius", type: AT_FLOAT, pMemory: &this->m_flRadius);
  p_m_flRadius->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 2.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "angle", type: AT_FLOAT, pMemory: &this->m_flYawAngle);
  this->m_flYawAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "irisScale",
         type: AT_FLOAT,
         pMemory: &this->m_flIrisScale);
  this->m_flIrisScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_sMaterialName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "materialName",
                                         type: AT_STRING,
                                         pMemory: &this->m_sMaterialName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_vPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "position",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_vPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004E6A20
// Name: public: virtual bool CDmeEyeball::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeball::IsA(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6A50
// Name: public: virtual int CDmeEyeball::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeball::GetInheritanceDepth(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E6B30
// Name: protected: virtual void CDmeEyeball::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::PerformConstruction(CDmeEyeball *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyeball::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC40
// Name: _dynamic_initializer_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeball::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeball pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3550
// Name: _dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeball::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC70
// Name: _dynamic_initializer_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeball_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDC80
// Name: _dynamic_initializer_for__g_CDmeEyeball_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeball_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeball_Helper,
           classname: "DmeEyeball",
           pFactory: &g_CDmeEyeball_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3560
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeball_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00514890
// Name: protected: void CDmeEyeball::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::OnConstruction(CDmeEyeball *this)
{
  CDmaVar<float> *p_m_flRadius; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flRadius = &this->m_flRadius;
  value = 0.5;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "radius", type: AT_FLOAT, pMemory: &this->m_flRadius);
  p_m_flRadius->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 2.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "angle", type: AT_FLOAT, pMemory: &this->m_flYawAngle);
  this->m_flYawAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "irisScale",
         type: AT_FLOAT,
         pMemory: &this->m_flIrisScale);
  this->m_flIrisScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_sMaterialName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "materialName",
                                         type: AT_STRING,
                                         pMemory: &this->m_sMaterialName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_vPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "position",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_vPosition);
}

//------------------------------------------------------------------------------
// Address: 0x00514A00
// Name: public: virtual bool CDmeEyeball::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeball::IsA(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514A30
// Name: public: virtual int CDmeEyeball::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeball::GetInheritanceDepth(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00514B00
// Name: protected: virtual void CDmeEyeball::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::PerformConstruction(CDmeEyeball *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeEyeball::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AE0C0
// Name: _dynamic_initializer_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeball::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeball pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4470
// Name: _dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeball::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AE0F0
// Name: _dynamic_initializer_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeball_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AE100
// Name: _dynamic_initializer_for__g_CDmeEyeball_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeball_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeball_Helper,
           classname: "DmeEyeball",
           pFactory: &g_CDmeEyeball_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4480
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeEyeball_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D9F20
// Name: protected: void CDmeEyeball::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::OnConstruction(CDmeEyeball *this)
{
  CDmaVar<float> *p_m_flRadius; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flRadius = &this->m_flRadius;
  value = 0.5;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "radius", type: AT_FLOAT, pMemory: &this->m_flRadius);
  p_m_flRadius->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 2.0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "angle", type: AT_FLOAT, pMemory: &this->m_flYawAngle);
  this->m_flYawAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "irisScale",
         type: AT_FLOAT,
         pMemory: &this->m_flIrisScale);
  this->m_flIrisScale.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  this->m_sMaterialName.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "materialName",
                                         type: AT_STRING,
                                         pMemory: &this->m_sMaterialName);
  this->m_sParentBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "parentBoneName",
                                           type: AT_STRING,
                                           pMemory: &this->m_sParentBoneName);
  this->m_vPosition.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "position",
                                     type: AT_VECTOR3,
                                     pMemory: &this->m_vPosition);
}

//------------------------------------------------------------------------------
// Address: 0x004DA090
// Name: public: virtual bool CDmeEyeball::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeEyeball::IsA(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA0C0
// Name: public: virtual int CDmeEyeball::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeEyeball::GetInheritanceDepth(CDmeEyeball *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeEyeball::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DA190
// Name: protected: virtual void CDmeEyeball::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEyeball::PerformConstruction(CDmeEyeball *this)
{
  CDmeFXClip::OnDestruction();
  CDmeEyeball::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E5F30
// Name: _dynamic_initializer_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeEyeball::s_Allocator,
    blockSize: 124,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeEyeball pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC010
// Name: _dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeEyeball::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeEyeball::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E5F60
// Name: _dynamic_initializer_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeEyeball_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E5F70
// Name: _dynamic_initializer_for__g_CDmeEyeball_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeEyeball_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeEyeball_Helper,
           classname: "DmeEyeball",
           pFactory: &g_CDmeEyeball_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC020
// Name: _dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeEyeball_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeEyeball_Factory.m_CallBackList);
}

} // namespace studiomdl
