// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmehitbox.cpp
// Functions: 25
// ============================================================

#include "mdlobjects\dmehitbox.h"

//------------------------------------------------------------------------------
// Address: 0x0049BCB0
// Name: protected: void CDmeHitbox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::OnConstruction(CDmeHitbox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  Vector v5; // [esp+8h] [ebp-10h] BYREF
  Color value; // [esp+14h] [ebp-4h] BYREF

  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_nGroupId.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "groupId",
                                    type: AT_INT,
                                    pMemory: &this->m_nGroupId);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  value = (Color)1090519039;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderColor",
         type: AT_COLOR,
         pMemory: &this->m_cRenderColor);
  this->m_cRenderColor.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  m_pAttribute = this->m_vMinBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &v5);
  v4 = this->m_vMaxBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: v4, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0049BD70
// Name: public: virtual void CDmeHitbox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::Draw(CDmeHitbox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  Color m_Storage; // [esp-14h] [ebp-34h]
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(a1: (int)this, matrix: shapeToWorld, angles: &angles.x);
  m_Storage = this->m_cRenderColor.m_Storage;
  vecOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vecOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vecOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    vOrigin: &vecOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: m_Storage,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x0049BDD0
// Name: protected: virtual void CDmeShape::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeShape::PerformConstruction(CDmeShape *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049BDE0
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
// Address: 0x0049BEA0
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
// Address: 0x0049BED0
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
// Address: 0x0049BF10
// Name: protected: virtual void CDmeBBox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::PerformConstruction(CDmeBBox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeBBox::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049BF60
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
// Address: 0x0049BF90
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
// Address: 0x0049BFE0
// Name: protected: CDmeHitbox::CDmeHitbox(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeHitbox *__thiscall CDmeHitbox::CDmeHitbox(
        CDmeHitbox *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->m_vMinBounds.m_pAttribute = nullptr;
  this->m_vMinBounds.m_Storage.x = 0.0;
  this->m_vMinBounds.m_Storage.y = 0.0;
  this->m_vMinBounds.m_Storage.z = 0.0;
  this->m_vMaxBounds.m_pAttribute = nullptr;
  this->m_vMaxBounds.m_Storage.x = 0.0;
  this->m_vMaxBounds.m_Storage.y = 0.0;
  this->m_vMaxBounds.m_Storage.z = 0.0;
  this->__vftable = (CDmeHitbox_vtbl *)&CDmeHitbox::`vftable';
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  this->m_nGroupId.m_pAttribute = nullptr;
  this->m_nGroupId.m_Storage = 0;
  this->m_sBoneName.m_pAttribute = nullptr;
  this->m_sBoneName.m_Storage.u.m_Id = -1;
  this->m_cRenderColor.m_pAttribute = nullptr;
  this->m_cRenderColor.m_Storage = (Color)-16777216;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049C0A0
// Name: public: virtual bool CDmeHitbox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitbox::IsA(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C0E0
// Name: public: virtual int CDmeHitbox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitbox::GetInheritanceDepth(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049C140
// Name: protected: virtual void CDmeBBox::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBBox::PerformDestruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0049C1A0
// Name: protected: virtual void CDmeHitbox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformConstruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeBBox::OnConstruction(this);
  CDmeHitbox::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049F7D0
// Name: protected: virtual int CDmeBBox::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBBox::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x005985E0
// Name: _dynamic_initializer_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitbox::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitbox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AA00
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
// Address: 0x0059DF00
// Name: _dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitbox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB40
// Name: _dynamic_atexit_destructor_for__CDmeShape::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeShape::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeShape::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598610
// Name: _dynamic_initializer_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitbox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598620
// Name: _dynamic_initializer_for__g_CDmeHitbox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitbox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitbox_Helper,
           classname: "DmeHitbox",
           pFactory: &g_CDmeHitbox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059AA30
// Name: _dynamic_initializer_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeShape_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeShape_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AA40
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
// Address: 0x0059DF10
// Name: _dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitbox_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059EB50
// Name: _dynamic_atexit_destructor_for__g_CDmeShape_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeShape_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeShape_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E2CA0
// Name: protected: void CDmeHitbox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::OnConstruction(CDmeHitbox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  Vector v5; // [esp+8h] [ebp-10h] BYREF
  Color value; // [esp+14h] [ebp-4h] BYREF

  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_nGroupId.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "groupId",
                                    type: AT_INT,
                                    pMemory: &this->m_nGroupId);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  value = (Color)1090519039;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderColor",
         type: AT_COLOR,
         pMemory: &this->m_cRenderColor);
  this->m_cRenderColor.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  m_pAttribute = this->m_vMinBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &v5);
  v4 = this->m_vMaxBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: v4, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x004E2D60
// Name: public: virtual void CDmeHitbox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::Draw(CDmeHitbox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  Color m_Storage; // [esp-14h] [ebp-34h]
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(a1: (int)this, matrix: shapeToWorld, angles: &angles.x);
  m_Storage = this->m_cRenderColor.m_Storage;
  vecOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vecOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vecOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    vOrigin: &vecOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: m_Storage,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x004E2E20
// Name: protected: CDmeHitbox::CDmeHitbox(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeHitbox *__thiscall CDmeHitbox::CDmeHitbox(
        CDmeHitbox *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->m_vMinBounds.m_pAttribute = nullptr;
  this->m_vMinBounds.m_Storage.x = 0.0;
  this->m_vMinBounds.m_Storage.y = 0.0;
  this->m_vMinBounds.m_Storage.z = 0.0;
  this->m_vMaxBounds.m_pAttribute = nullptr;
  this->m_vMaxBounds.m_Storage.x = 0.0;
  this->m_vMaxBounds.m_Storage.y = 0.0;
  this->m_vMaxBounds.m_Storage.z = 0.0;
  this->__vftable = (CDmeHitbox_vtbl *)&CDmeHitbox::`vftable';
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  this->m_nGroupId.m_pAttribute = nullptr;
  this->m_nGroupId.m_Storage = 0;
  this->m_sBoneName.m_pAttribute = nullptr;
  this->m_sBoneName.m_Storage.u.m_Id = -1;
  this->m_cRenderColor.m_pAttribute = nullptr;
  this->m_cRenderColor.m_Storage = (Color)-16777216;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E2EE0
// Name: public: virtual bool CDmeHitbox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitbox::IsA(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2F20
// Name: public: virtual int CDmeHitbox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitbox::GetInheritanceDepth(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2F80
// Name: protected: virtual void CDmeHitbox::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformDestruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004E2FE0
// Name: protected: virtual void CDmeHitbox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformConstruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeBBox::OnConstruction(this);
  CDmeHitbox::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ED4C0
// Name: _dynamic_initializer_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitbox::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitbox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F32D0
// Name: _dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitbox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED4F0
// Name: _dynamic_initializer_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitbox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED500
// Name: _dynamic_initializer_for__g_CDmeHitbox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitbox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitbox_Helper,
           classname: "DmeHitbox",
           pFactory: &g_CDmeHitbox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F32E0
// Name: _dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitbox_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050BCF0
// Name: protected: void CDmeHitbox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::OnConstruction(CDmeHitbox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  Vector v5; // [esp+8h] [ebp-10h] BYREF
  Color value; // [esp+14h] [ebp-4h] BYREF

  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_nGroupId.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "groupId",
                                    type: AT_INT,
                                    pMemory: &this->m_nGroupId);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  value = (Color)1090519039;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderColor",
         type: AT_COLOR,
         pMemory: &this->m_cRenderColor);
  this->m_cRenderColor.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  m_pAttribute = this->m_vMinBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &v5);
  v4 = this->m_vMaxBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: v4, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0050BDB0
// Name: public: virtual void CDmeHitbox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::Draw(CDmeHitbox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  Color m_Storage; // [esp-14h] [ebp-34h]
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(a1: (int)this, matrix: shapeToWorld, angles: &angles.x);
  m_Storage = this->m_cRenderColor.m_Storage;
  vecOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vecOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vecOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    vOrigin: &vecOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: m_Storage,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x0050BE70
// Name: protected: CDmeHitbox::CDmeHitbox(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeHitbox *__thiscall CDmeHitbox::CDmeHitbox(
        CDmeHitbox *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->m_vMinBounds.m_pAttribute = nullptr;
  this->m_vMinBounds.m_Storage.x = 0.0;
  this->m_vMinBounds.m_Storage.y = 0.0;
  this->m_vMinBounds.m_Storage.z = 0.0;
  this->m_vMaxBounds.m_pAttribute = nullptr;
  this->m_vMaxBounds.m_Storage.x = 0.0;
  this->m_vMaxBounds.m_Storage.y = 0.0;
  this->m_vMaxBounds.m_Storage.z = 0.0;
  this->__vftable = (CDmeHitbox_vtbl *)&CDmeHitbox::`vftable';
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  this->m_nGroupId.m_pAttribute = nullptr;
  this->m_nGroupId.m_Storage = 0;
  this->m_sBoneName.m_pAttribute = nullptr;
  this->m_sBoneName.m_Storage.u.m_Id = -1;
  this->m_cRenderColor.m_pAttribute = nullptr;
  this->m_cRenderColor.m_Storage = (Color)-16777216;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050BF30
// Name: public: virtual bool CDmeHitbox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitbox::IsA(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BF70
// Name: public: virtual int CDmeHitbox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitbox::GetInheritanceDepth(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C040
// Name: protected: virtual void CDmeHitbox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformConstruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeShape::OnConstruction(this);
  CDmeBBox::OnConstruction(this);
  CDmeHitbox::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006ACAA0
// Name: _dynamic_initializer_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitbox::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitbox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D10
// Name: _dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitbox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACAD0
// Name: _dynamic_initializer_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitbox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACAE0
// Name: _dynamic_initializer_for__g_CDmeHitbox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitbox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitbox_Helper,
           classname: "DmeHitbox",
           pFactory: &g_CDmeHitbox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3D20
// Name: _dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeHitbox_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DB790
// Name: protected: void CDmeHitbox::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::OnConstruction(CDmeHitbox *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v4; // ecx
  Vector v5; // [esp+8h] [ebp-10h] BYREF
  Color value; // [esp+14h] [ebp-4h] BYREF

  this->m_sSurfaceProperty.m_pAttribute = CDmElement::AddExternalAttribute(
                                            this,
                                            pAttributeName: "surfaceProperty",
                                            type: AT_STRING,
                                            pMemory: &this->m_sSurfaceProperty);
  this->m_nGroupId.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "groupId",
                                    type: AT_INT,
                                    pMemory: &this->m_nGroupId);
  this->m_sBoneName.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "boneName",
                                     type: AT_STRING,
                                     pMemory: &this->m_sBoneName);
  value = (Color)1090519039;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "renderColor",
         type: AT_COLOR,
         pMemory: &this->m_cRenderColor);
  this->m_cRenderColor.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  m_pAttribute = this->m_vMinBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: m_pAttribute, value: &v5);
  v4 = this->m_vMaxBounds.m_pAttribute;
  memset(&v5, 0, sizeof(v5));
  CDmAttribute::SetValue<Vector>(this: v4, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x004DB850
// Name: public: virtual void CDmeHitbox::Draw(struct matrix3x4_t const __near &,class CDmeDrawSettings __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::Draw(CDmeHitbox *this, const matrix3x4_t *shapeToWorld, CDmeDrawSettings *pDrawSettings)
{
  Color m_Storage; // [esp-14h] [ebp-34h]
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+14h] [ebp-Ch] BYREF

  MatrixAngles(a1: (int)this, matrix: shapeToWorld, angles: &angles.x);
  m_Storage = this->m_cRenderColor.m_Storage;
  vecOrigin.x = shapeToWorld->m_flMatVal[0][3];
  vecOrigin.y = shapeToWorld->m_flMatVal[1][3];
  vecOrigin.z = shapeToWorld->m_flMatVal[2][3];
  RenderBox(
    vOrigin: &vecOrigin,
    &angles,
    vMins: &this->m_vMinBounds.m_Storage,
    vMaxs: &this->m_vMaxBounds.m_Storage,
    c: m_Storage,
    bZBuffer: true,
    bInsideOut: false);
}

//------------------------------------------------------------------------------
// Address: 0x004DB910
// Name: protected: CDmeHitbox::CDmeHitbox(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeHitbox *__thiscall CDmeHitbox::CDmeHitbox(
        CDmeHitbox *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->m_visible.m_pAttribute = nullptr;
  this->m_visible.m_Storage = false;
  this->m_vMinBounds.m_pAttribute = nullptr;
  this->m_vMinBounds.m_Storage.x = 0.0;
  this->m_vMinBounds.m_Storage.y = 0.0;
  this->m_vMinBounds.m_Storage.z = 0.0;
  this->m_vMaxBounds.m_pAttribute = nullptr;
  this->m_vMaxBounds.m_Storage.x = 0.0;
  this->m_vMaxBounds.m_Storage.y = 0.0;
  this->m_vMaxBounds.m_Storage.z = 0.0;
  this->__vftable = (CDmeHitbox_vtbl *)&CDmeHitbox::`vftable';
  this->m_sSurfaceProperty.m_pAttribute = nullptr;
  this->m_sSurfaceProperty.m_Storage.u.m_Id = -1;
  this->m_nGroupId.m_pAttribute = nullptr;
  this->m_nGroupId.m_Storage = 0;
  this->m_sBoneName.m_pAttribute = nullptr;
  this->m_sBoneName.m_Storage.u.m_Id = -1;
  this->m_cRenderColor.m_pAttribute = nullptr;
  this->m_cRenderColor.m_Storage = (Color)-16777216;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DB9D0
// Name: public: virtual bool CDmeHitbox::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeHitbox::IsA(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBA10
// Name: public: virtual int CDmeHitbox::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeHitbox::GetInheritanceDepth(CDmeHitbox *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeHitbox::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeBBox::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeShape::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DBA70
// Name: protected: virtual void CDmeHitbox::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformDestruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004DBAD0
// Name: protected: virtual void CDmeHitbox::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeHitbox::PerformConstruction(CDmeHitbox *this)
{
  CDmeFXClip::OnDestruction();
  CDmeShape::OnConstruction(this);
  CDmeBBox::OnConstruction(this);
  CDmeHitbox::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E6170
// Name: _dynamic_initializer_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeHitbox::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeHitbox pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC0D0
// Name: _dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeHitbox::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeHitbox::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E61A0
// Name: _dynamic_initializer_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeHitbox_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E61B0
// Name: _dynamic_initializer_for__g_CDmeHitbox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeHitbox_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeHitbox_Helper,
           classname: "DmeHitbox",
           pFactory: &g_CDmeHitbox_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC0E0
// Name: _dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeHitbox_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeHitbox_Factory.m_CallBackList);
}

} // namespace studiomdl
