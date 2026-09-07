// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeshape.cpp
// Functions: 4
// ============================================================

#include "movieobjects\dmeshape.h"

//------------------------------------------------------------------------------
// Address: 0x004B2520
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004B2530
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004B2560
// Name: public: class CDmeDag __near * CDmeShape::GetParent(int)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmeShape::GetParent(CDmeShape *this, int nParentIndex)
{
  IDataModel_vtbl *v2; // esi
  int v3; // eax
  DmAttributeReferenceIterator_t v4; // edi
  CDmAttribute *v5; // ebx
  CDmElement *m_pOwner; // esi
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  int nReferringDags; // [esp+10h] [ebp-4h]

  v2 = g_pDataModel->__vftable;
  nReferringDags = 0;
  v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
  v4 = v2->FirstAttributeReferencingElement(this: g_pDataModel, a2: (DmElementHandle_t)v3);
  if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    v5 = g_pDataModel->GetAttribute(this: g_pDataModel, a2: v4);
    m_pOwner = v5->m_pOwner;
    if ( m_pOwner == nullptr || !m_pOwner->IsA(this: m_pOwner, a2: CDmeDag::m_classType) )
      m_pOwner = nullptr;
    if ( (_S2_2 & 1) == 0 )
    {
      GetSymbol = g_pDataModel->GetSymbol;
      _S2_2 |= 1u;
      GetSymbol(this: g_pDataModel, result: &symShape, a3: "shape");
    }
    if ( m_pOwner != nullptr && v5->m_Name.u.m_Id == symShape.u.m_Id && m_pOwner->m_fileId == this->m_fileId )
    {
      if ( nReferringDags == nParentIndex )
        break;
      ++nReferringDags;
    }
    v4 = g_pDataModel->NextAttributeReferencingElement(this: g_pDataModel, a2: v4);
    if ( v4 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return (CDmeDag *)m_pOwner;
}

//------------------------------------------------------------------------------
// Address: 0x004B2660
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004FA9B0
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004FA9E0
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004FAA70
// Name: public: virtual void CDmeShape::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingBox(CDmeShape *this, Vector *min, Vector *max)
{
  *(_QWORD *)&min->y = 0;
  min->x = 0.0;
  *(_QWORD *)&max->y = 0;
  max->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004FAAD0
// Name: public: virtual bool CDmeShape::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeShape::IsA(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FAB00
// Name: public: virtual int CDmeShape::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeShape::GetInheritanceDepth(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FABB0
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmAttribute *v2; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  this->m_visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0067CFE0
// Name: _dynamic_initializer_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeShape::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeShape pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeShape::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681E60
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D010
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D020
// Name: _dynamic_initializer_for__g_CDmeShape_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeShape_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeShape_Helper,
           classname: "DmeShape",
           pFactory: &g_CDmeShape_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681E70
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1058EBD0
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1058EC00
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004AFB00
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004AFB10
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004AFB40
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050BD40
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0050BD50
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0050BD80
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00467990
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004679A0
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004679D0
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00467A60
// Name: public: virtual void CDmeShape::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingBox(CDmeShape *this, Vector *min, Vector *max)
{
  *(_QWORD *)&min->y = 0;
  min->x = 0.0;
  *(_QWORD *)&max->y = 0;
  max->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00467AC0
// Name: public: virtual bool CDmeShape::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeShape::IsA(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467AF0
// Name: public: virtual int CDmeShape::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeShape::GetInheritanceDepth(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00467BB0
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmAttribute *v2; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  this->m_visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00569BC0
// Name: _dynamic_initializer_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeShape::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeShape pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeShape::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E040
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569BF0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569C00
// Name: _dynamic_initializer_for__g_CDmeShape_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeShape_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeShape_Helper,
           classname: "DmeShape",
           pFactory: &g_CDmeShape_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E050
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0046AD20
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046AD30
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046AD60
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0046ADF0
// Name: public: virtual void CDmeShape::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingBox(CDmeShape *this, Vector *min, Vector *max)
{
  *(_QWORD *)&min->y = 0;
  min->x = 0.0;
  *(_QWORD *)&max->y = 0;
  max->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046AE50
// Name: public: virtual bool CDmeShape::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeShape::IsA(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AE80
// Name: public: virtual int CDmeShape::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeShape::GetInheritanceDepth(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046AF30
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmAttribute *v2; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  this->m_visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00579CC0
// Name: _dynamic_initializer_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeShape::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeShape pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeShape::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E170
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579CF0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579D00
// Name: _dynamic_initializer_for__g_CDmeShape_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeShape_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeShape_Helper,
           classname: "DmeShape",
           pFactory: &g_CDmeShape_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E180
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D3F70
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x005D3FA0
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0046BA60
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0046BA70
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046BAA0
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0046BB30
// Name: public: virtual void CDmeShape::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingBox(CDmeShape *this, Vector *min, Vector *max)
{
  *(_QWORD *)&min->y = 0;
  min->x = 0.0;
  *(_QWORD *)&max->y = 0;
  max->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0046BB90
// Name: public: virtual bool CDmeShape::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeShape::IsA(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046BBC0
// Name: public: virtual int CDmeShape::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeShape::GetInheritanceDepth(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046BC60
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmAttribute *v2; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  this->m_visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCB0
// Name: _dynamic_initializer_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeShape::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeShape pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeShape::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580150
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCE0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCF0
// Name: _dynamic_initializer_for__g_CDmeShape_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeShape_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeShape_Helper,
           classname: "DmeShape",
           pFactory: &g_CDmeShape_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580160
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00504DA0
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00504DB0
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00504DE0
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047E8F0
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0047E900
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x0047E930
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00578EF0
// Name: public: virtual void CDmeShape::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::Draw(CDmeShape *this, const matrix3x4_t *shapeToWorld, const matrix3x4_t *pDrawSettings)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00578F00
// Name: public: virtual void CDmeShape::GetBoundingSphere(class Vector __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingSphere(CDmeShape *this, Vector *c, float *r)
{
  *(_QWORD *)&c->y = 0;
  c->x = 0.0;
  *r = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00578F30
// Name: protected: void CDmeShape::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::OnConstruction(CDmeShape *this)
{
  CDmaVar<bool> *p_m_visible; // esi
  CDmAttribute *v2; // eax
  bool value; // [esp+7h] [ebp-1h] BYREF

  p_m_visible = &this->m_visible;
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  p_m_visible->m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00578FC0
// Name: public: virtual void CDmeShape::GetBoundingBox(class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::GetBoundingBox(CDmeShape *this, Vector *min, Vector *max)
{
  *(_QWORD *)&min->y = 0;
  min->x = 0.0;
  *(_QWORD *)&max->y = 0;
  max->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00579020
// Name: public: virtual bool CDmeShape::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeShape::IsA(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00579050
// Name: public: virtual int CDmeShape::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeShape::GetInheritanceDepth(CDmeShape *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005790F0
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmAttribute *v2; // eax
  bool value; // [esp+Bh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  value = true;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "visible", type: AT_BOOL, pMemory: &this->m_visible);
  this->m_visible.m_pAttribute = v2;
  CDmAttribute::SetValue<bool>(this: v2, &value);
}

//------------------------------------------------------------------------------
// Address: 0x006B7470
// Name: _dynamic_initializer_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeShape::s_Allocator,
    blockSize: 0x4Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeShape pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeShape::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC660
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B74A0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B74B0
// Name: _dynamic_initializer_for__g_CDmeShape_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeShape_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeShape_Helper,
           classname: "DmeShape",
           pFactory: &g_CDmeShape_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC670
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace vmap
