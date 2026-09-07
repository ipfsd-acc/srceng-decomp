// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebbox.cpp
// Functions: 7
// ============================================================

#include "mdlobjects\dmebbox.h"

//------------------------------------------------------------------------------
// Address: 0x0049C690
// Name: protected: void CDmeBBox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::OnConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector vMax; // [esp+8h] [ebp-18h] BYREF
  Vector vMin; // [esp+14h] [ebp-Ch] BYREF

  ClearBounds(mins: &vMin, maxs: &vMax);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &vMin);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vMax);
}

//------------------------------------------------------------------------------
// Address: 0x0049C6F0
// Name: public: virtual void CDmeBBox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::Draw(CDmeBBox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+14h] [ebp-Ch] BYREF

  if ( (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    cRenderColor = (Color)49152;
  }
  MatrixAngles(a1: (int)shapeToWorld, matrix: shapeToWorld, angles: &angles.x);
  vOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    &vOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: cRenderColor,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x00598760
// Name: _dynamic_initializer_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBBox::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBBox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF80
// Name: _dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBBox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598790
// Name: _dynamic_initializer_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBBox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBBox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005987A0
// Name: _dynamic_initializer_for__g_CDmeBBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBBox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBBox_Helper,
           classname: "DmeBBox",
           pFactory: &g_CDmeBBox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059DF90
// Name: _dynamic_atexit_destructor_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBBox_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBBox_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E1B40
// Name: protected: void CDmeBBox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::OnConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector vMax; // [esp+8h] [ebp-18h] BYREF
  Vector vMin; // [esp+14h] [ebp-Ch] BYREF

  ClearBounds(mins: &vMin, maxs: &vMax);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &vMin);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vMax);
}

//------------------------------------------------------------------------------
// Address: 0x004E1BA0
// Name: public: virtual void CDmeBBox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::Draw(CDmeBBox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+14h] [ebp-Ch] BYREF

  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    cRenderColor = (Color)49152;
  }
  MatrixAngles(a1: (int)shapeToWorld, matrix: shapeToWorld, angles: &angles.x);
  vOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    &vOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: cRenderColor,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x004E1C20
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004E1C30
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
// Address: 0x004E1CF0
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
// Address: 0x004E1D20
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
// Address: 0x004E1D90
// Name: public: virtual bool CDmeBBox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBBox::IsA(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1DC0
// Name: public: virtual int CDmeBBox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::GetInheritanceDepth(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1E90
// Name: protected: virtual void CDmeBBox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::PerformConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector maxs; // [esp+8h] [ebp-18h] BYREF
  Vector mins; // [esp+14h] [ebp-Ch] BYREF

  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  ClearBounds(&mins, &maxs);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &mins);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x004E9FD0
// Name: protected: virtual int CDmeBBox::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x005ED280
// Name: _dynamic_initializer_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBBox::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBBox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0210
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
// Address: 0x005F3210
// Name: _dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBBox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4200
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2B0
// Name: _dynamic_initializer_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBBox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBBox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2C0
// Name: _dynamic_initializer_for__g_CDmeBBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBBox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBBox_Helper,
           classname: "DmeBBox",
           pFactory: &g_CDmeBBox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0240
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0250
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
// Address: 0x005F3220
// Name: _dynamic_atexit_destructor_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBBox_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBBox_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4210
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050B930
// Name: protected: void CDmeBBox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::OnConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector vMax; // [esp+8h] [ebp-18h] BYREF
  Vector vMin; // [esp+14h] [ebp-Ch] BYREF

  ClearBounds(mins: &vMin, maxs: &vMax);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &vMin);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vMax);
}

//------------------------------------------------------------------------------
// Address: 0x0050B990
// Name: public: virtual void CDmeBBox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::Draw(CDmeBBox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+14h] [ebp-Ch] BYREF

  if ( (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    cRenderColor = (Color)49152;
  }
  MatrixAngles(a1: (int)shapeToWorld, matrix: shapeToWorld, angles: &angles.x);
  vOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    &vOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: cRenderColor,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x0050BA10
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0050BA20
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
// Address: 0x0050BAE0
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
// Address: 0x0050BB10
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
// Address: 0x0050BB80
// Name: public: virtual bool CDmeBBox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBBox::IsA(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BBB0
// Name: public: virtual int CDmeBBox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::GetInheritanceDepth(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BC80
// Name: protected: virtual void CDmeBBox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::PerformConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector maxs; // [esp+8h] [ebp-18h] BYREF
  Vector mins; // [esp+14h] [ebp-Ch] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  ClearBounds(&mins, &maxs);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &mins);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x0051DBF0
// Name: protected: virtual int CDmeBBox::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x006ACA40
// Name: _dynamic_initializer_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBBox::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBBox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0470
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
// Address: 0x006B3CF0
// Name: _dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBBox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B50B0
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACA70
// Name: _dynamic_initializer_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBBox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBBox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACA80
// Name: _dynamic_initializer_for__g_CDmeBBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBBox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBBox_Helper,
           classname: "DmeBBox",
           pFactory: &g_CDmeBBox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B04A0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B04B0
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
// Address: 0x006B3D00
// Name: _dynamic_atexit_destructor_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBBox_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBBox_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B50C0
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DB3D0
// Name: protected: void CDmeBBox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::OnConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector vMax; // [esp+8h] [ebp-18h] BYREF
  Vector vMin; // [esp+14h] [ebp-Ch] BYREF

  ClearBounds(mins: &vMin, maxs: &vMax);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &vMin);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &vMax);
}

//------------------------------------------------------------------------------
// Address: 0x004DB430
// Name: public: virtual void CDmeBBox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::Draw(CDmeBBox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vOrigin; // [esp+14h] [ebp-Ch] BYREF

  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    cRenderColor = (Color)49152;
  }
  MatrixAngles(a1: (int)shapeToWorld, matrix: shapeToWorld, angles: &angles.x);
  vOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    &vOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: cRenderColor,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x004DB4B0
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004DB4C0
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
// Address: 0x004DB580
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
// Address: 0x004DB5B0
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
// Address: 0x004DB620
// Name: public: virtual bool CDmeBBox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBBox::IsA(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB650
// Name: public: virtual int CDmeBBox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::GetInheritanceDepth(CDmeBBox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DB720
// Name: protected: virtual void CDmeBBox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::PerformConstruction(CDmeBBox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Vector maxs; // [esp+8h] [ebp-18h] BYREF
  Vector mins; // [esp+14h] [ebp-Ch] BYREF

  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  ClearBounds(&mins, &maxs);
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "minBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMinBounds);
  this->m_vMinBounds.m_pAttribute = v2;
  CDmAttribute::SetValue<Vector>(this: v2, value: &mins);
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxBounds",
         type: AT_VECTOR3,
         pMemory: &this->m_vMaxBounds);
  this->m_vMaxBounds.m_pAttribute = v3;
  CDmAttribute::SetValue<Vector>(this: v3, value: &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x004DEDD0
// Name: protected: virtual int CDmeBBox::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x005E6110
// Name: _dynamic_initializer_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBBox::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBBox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E90B0
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
// Address: 0x005EC0B0
// Name: _dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBBox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBBox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0A0
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6140
// Name: _dynamic_initializer_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBBox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBBox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6150
// Name: _dynamic_initializer_for__g_CDmeBBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBBox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBBox_Helper,
           classname: "DmeBBox",
           pFactory: &g_CDmeBBox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E90E0
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E90F0
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
// Address: 0x005EC0C0
// Name: _dynamic_atexit_destructor_for__g_CDmeBBox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBBox_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBBox_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0B0
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

} // namespace studiomdl
