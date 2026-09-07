// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmecollisionmodel.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmecollisionmodel.h"

//------------------------------------------------------------------------------
// Address: 0x0049D190
// Name: protected: void CDmeCollisionModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::OnConstruction(CDmeCollisionModel *this)
{
  CDmaVar<float> *p_m_flMass; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  Vector v18; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+Ch] [ebp-8h] BYREF
  bool v20; // [esp+13h] [ebp-1h] BYREF

  p_m_flMass = &this->m_flMass;
  value.u.m_Id = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "mass", type: AT_FLOAT, pMemory: &this->m_flMass);
  p_m_flMass->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.u.m_Id);
  v20 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "automaticMassComputation",
         type: AT_BOOL,
         pMemory: &this->m_bAutomaticMassComputation);
  this->m_bAutomaticMassComputation.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v20);
  value.u.m_Id = 1065353216;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotationalDamping);
  this->m_flRotationalDamping.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.u.m_Id);
  value.u.m_Id = -1082130432;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "drag", type: AT_FLOAT, pMemory: &this->m_flDrag);
  this->m_flDrag.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.u.m_Id);
  value.u.m_Id = 40;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxConvexPieces",
         type: AT_INT,
         pMemory: &this->m_nMaxConvexPieces);
  this->m_nMaxConvexPieces.m_pAttribute = v9;
  CDmAttribute::SetValue<int>(this: v9, value: &value.u.m_Id);
  v20 = false;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "remove2d", type: AT_BOOL, pMemory: &this->m_bRemove2D);
  this->m_bRemove2D.m_pAttribute = v10;
  CDmAttribute::SetValue<bool>(this: v10, value: &v20);
  value.u.m_Id = 0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldPositionTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldPositionTolerance);
  this->m_flWeldPositionTolerance.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.u.m_Id);
  value.u.m_Id = 1065336439;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldNormalTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldNormalTolerance);
  this->m_flWeldNormalTolerance.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.u.m_Id);
  v20 = false;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "concave", type: AT_BOOL, pMemory: &this->m_bConcave);
  this->m_bConcave.m_pAttribute = v13;
  CDmAttribute::SetValue<bool>(this: v13, value: &v20);
  v20 = false;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "forceMassCenter",
          type: AT_BOOL,
          pMemory: &this->m_bForceMassCenter);
  this->m_bForceMassCenter.m_pAttribute = v14;
  CDmAttribute::SetValue<bool>(this: v14, value: &v20);
  memset(&v18, 0, sizeof(v18));
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "massCenter",
          type: AT_VECTOR3,
          pMemory: &this->m_vecMassCenter);
  this->m_vecMassCenter.m_pAttribute = v15;
  CDmAttribute::SetValue<Vector>(this: v15, value: &v18);
  v20 = false;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "assumeWorldSpace",
          type: AT_BOOL,
          pMemory: &this->m_bAssumeWorldSpace);
  this->m_bAssumeWorldSpace.m_pAttribute = v16;
  CDmAttribute::SetValue<bool>(this: v16, value: &v20);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "default");
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "surfaceProperty",
          type: AT_STRING,
          pMemory: &this->m_SurfaceProperty);
  this->m_SurfaceProperty.m_pAttribute = v17;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v17, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0049D480
// Name: protected: CDmeCollisionModel::CDmeCollisionModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionModel *__thiscall CDmeCollisionModel::CDmeCollisionModel(
        CDmeCollisionModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionModel_vtbl *)&CDmeCollisionModel::`vftable';
  this->m_flMass.m_Storage = 0.0;
  this->m_flMass.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_Storage = false;
  this->m_flInertia = 0;
  this->m_flDamping = 0;
  this->m_flRotationalDamping = 0;
  this->m_flDrag = 0;
  this->m_nMaxConvexPieces.m_pAttribute = nullptr;
  this->m_nMaxConvexPieces.m_Storage = 0;
  this->m_bRemove2D.m_pAttribute = nullptr;
  this->m_bRemove2D.m_Storage = false;
  this->m_flWeldPositionTolerance = 0;
  this->m_flWeldNormalTolerance = 0;
  this->m_bConcave.m_pAttribute = nullptr;
  this->m_bConcave.m_Storage = false;
  this->m_bForceMassCenter.m_pAttribute = nullptr;
  this->m_bForceMassCenter.m_Storage = false;
  this->m_vecMassCenter.m_pAttribute = nullptr;
  this->m_vecMassCenter.m_Storage.x = 0.0;
  this->m_vecMassCenter.m_Storage.y = 0.0;
  this->m_vecMassCenter.m_Storage.z = 0.0;
  this->m_bAssumeWorldSpace.m_pAttribute = nullptr;
  this->m_bAssumeWorldSpace.m_Storage = false;
  this->m_SurfaceProperty.m_pAttribute = nullptr;
  this->m_SurfaceProperty.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049D590
// Name: public: virtual bool CDmeCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionModel::IsA(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049D5C0
// Name: public: virtual int CDmeCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionModel::GetInheritanceDepth(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049D640
// Name: protected: virtual void CDmeCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::PerformConstruction(CDmeCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00598940
// Name: _dynamic_initializer_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionModel::s_Allocator,
    blockSize: 196,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E020
// Name: _dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598970
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598980
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionModel_Helper,
           classname: "DmeCollisionModel",
           pFactory: &g_CDmeCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E030
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionModel_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E0B60
// Name: protected: void CDmeCollisionModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::OnConstruction(CDmeCollisionModel *this)
{
  CDmaVar<float> *p_m_flMass; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  Vector v18; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+Ch] [ebp-8h] BYREF
  bool v20; // [esp+13h] [ebp-1h] BYREF

  p_m_flMass = &this->m_flMass;
  value.u.m_Id = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "mass", type: AT_FLOAT, pMemory: &this->m_flMass);
  p_m_flMass->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.u.m_Id);
  v20 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "automaticMassComputation",
         type: AT_BOOL,
         pMemory: &this->m_bAutomaticMassComputation);
  this->m_bAutomaticMassComputation.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v20);
  value.u.m_Id = 1065353216;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotationalDamping);
  this->m_flRotationalDamping.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.u.m_Id);
  value.u.m_Id = -1082130432;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "drag", type: AT_FLOAT, pMemory: &this->m_flDrag);
  this->m_flDrag.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.u.m_Id);
  value.u.m_Id = 40;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxConvexPieces",
         type: AT_INT,
         pMemory: &this->m_nMaxConvexPieces);
  this->m_nMaxConvexPieces.m_pAttribute = v9;
  CDmAttribute::SetValue<int>(this: v9, value: &value.u.m_Id);
  v20 = false;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "remove2d", type: AT_BOOL, pMemory: &this->m_bRemove2D);
  this->m_bRemove2D.m_pAttribute = v10;
  CDmAttribute::SetValue<bool>(this: v10, value: &v20);
  value.u.m_Id = 0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldPositionTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldPositionTolerance);
  this->m_flWeldPositionTolerance.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.u.m_Id);
  value.u.m_Id = 1065336439;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldNormalTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldNormalTolerance);
  this->m_flWeldNormalTolerance.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.u.m_Id);
  v20 = false;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "concave", type: AT_BOOL, pMemory: &this->m_bConcave);
  this->m_bConcave.m_pAttribute = v13;
  CDmAttribute::SetValue<bool>(this: v13, value: &v20);
  v20 = false;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "forceMassCenter",
          type: AT_BOOL,
          pMemory: &this->m_bForceMassCenter);
  this->m_bForceMassCenter.m_pAttribute = v14;
  CDmAttribute::SetValue<bool>(this: v14, value: &v20);
  memset(&v18, 0, sizeof(v18));
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "massCenter",
          type: AT_VECTOR3,
          pMemory: &this->m_vecMassCenter);
  this->m_vecMassCenter.m_pAttribute = v15;
  CDmAttribute::SetValue<Vector>(this: v15, value: &v18);
  v20 = false;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "assumeWorldSpace",
          type: AT_BOOL,
          pMemory: &this->m_bAssumeWorldSpace);
  this->m_bAssumeWorldSpace.m_pAttribute = v16;
  CDmAttribute::SetValue<bool>(this: v16, value: &v20);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: pszFlexControllerType);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "surfaceProperty",
          type: AT_STRING,
          pMemory: &this->m_SurfaceProperty);
  this->m_SurfaceProperty.m_pAttribute = v17;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v17, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004E0E50
// Name: protected: CDmeCollisionModel::CDmeCollisionModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionModel *__thiscall CDmeCollisionModel::CDmeCollisionModel(
        CDmeCollisionModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionModel_vtbl *)&CDmeCollisionModel::`vftable';
  this->m_flMass.m_Storage = 0.0;
  this->m_flMass.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_Storage = false;
  this->m_flInertia = 0;
  this->m_flDamping = 0;
  this->m_flRotationalDamping = 0;
  this->m_flDrag = 0;
  this->m_nMaxConvexPieces.m_pAttribute = nullptr;
  this->m_nMaxConvexPieces.m_Storage = 0;
  this->m_bRemove2D.m_pAttribute = nullptr;
  this->m_bRemove2D.m_Storage = false;
  this->m_flWeldPositionTolerance = 0;
  this->m_flWeldNormalTolerance = 0;
  this->m_bConcave.m_pAttribute = nullptr;
  this->m_bConcave.m_Storage = false;
  this->m_bForceMassCenter.m_pAttribute = nullptr;
  this->m_bForceMassCenter.m_Storage = false;
  this->m_vecMassCenter.m_pAttribute = nullptr;
  this->m_vecMassCenter.m_Storage.x = 0.0;
  this->m_vecMassCenter.m_Storage.y = 0.0;
  this->m_vecMassCenter.m_Storage.z = 0.0;
  this->m_bAssumeWorldSpace.m_pAttribute = nullptr;
  this->m_bAssumeWorldSpace.m_Storage = false;
  this->m_SurfaceProperty.m_pAttribute = nullptr;
  this->m_SurfaceProperty.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004E0F60
// Name: public: virtual bool CDmeCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionModel::IsA(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0F90
// Name: public: virtual int CDmeCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionModel::GetInheritanceDepth(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E1010
// Name: protected: virtual void CDmeCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::PerformConstruction(CDmeCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0A0
// Name: _dynamic_initializer_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionModel::s_Allocator,
    blockSize: 196,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3170
// Name: _dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0D0
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0E0
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionModel_Helper,
           classname: "DmeCollisionModel",
           pFactory: &g_CDmeCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3180
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionModel_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050CD30
// Name: protected: void CDmeCollisionModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::OnConstruction(CDmeCollisionModel *this)
{
  CDmaVar<float> *p_m_flMass; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  Vector v18; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+Ch] [ebp-8h] BYREF
  bool v20; // [esp+13h] [ebp-1h] BYREF

  p_m_flMass = &this->m_flMass;
  value.u.m_Id = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "mass", type: AT_FLOAT, pMemory: &this->m_flMass);
  p_m_flMass->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.u.m_Id);
  v20 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "automaticMassComputation",
         type: AT_BOOL,
         pMemory: &this->m_bAutomaticMassComputation);
  this->m_bAutomaticMassComputation.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v20);
  value.u.m_Id = 1065353216;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotationalDamping);
  this->m_flRotationalDamping.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.u.m_Id);
  value.u.m_Id = -1082130432;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "drag", type: AT_FLOAT, pMemory: &this->m_flDrag);
  this->m_flDrag.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.u.m_Id);
  value.u.m_Id = 40;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxConvexPieces",
         type: AT_INT,
         pMemory: &this->m_nMaxConvexPieces);
  this->m_nMaxConvexPieces.m_pAttribute = v9;
  CDmAttribute::SetValue<int>(this: v9, value: &value.u.m_Id);
  v20 = false;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "remove2d", type: AT_BOOL, pMemory: &this->m_bRemove2D);
  this->m_bRemove2D.m_pAttribute = v10;
  CDmAttribute::SetValue<bool>(this: v10, value: &v20);
  value.u.m_Id = 0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldPositionTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldPositionTolerance);
  this->m_flWeldPositionTolerance.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.u.m_Id);
  value.u.m_Id = 1065336439;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldNormalTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldNormalTolerance);
  this->m_flWeldNormalTolerance.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.u.m_Id);
  v20 = false;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "concave", type: AT_BOOL, pMemory: &this->m_bConcave);
  this->m_bConcave.m_pAttribute = v13;
  CDmAttribute::SetValue<bool>(this: v13, value: &v20);
  v20 = false;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "forceMassCenter",
          type: AT_BOOL,
          pMemory: &this->m_bForceMassCenter);
  this->m_bForceMassCenter.m_pAttribute = v14;
  CDmAttribute::SetValue<bool>(this: v14, value: &v20);
  memset(&v18, 0, sizeof(v18));
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "massCenter",
          type: AT_VECTOR3,
          pMemory: &this->m_vecMassCenter);
  this->m_vecMassCenter.m_pAttribute = v15;
  CDmAttribute::SetValue<Vector>(this: v15, value: &v18);
  v20 = false;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "assumeWorldSpace",
          type: AT_BOOL,
          pMemory: &this->m_bAssumeWorldSpace);
  this->m_bAssumeWorldSpace.m_pAttribute = v16;
  CDmAttribute::SetValue<bool>(this: v16, value: &v20);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: "default");
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "surfaceProperty",
          type: AT_STRING,
          pMemory: &this->m_SurfaceProperty);
  this->m_SurfaceProperty.m_pAttribute = v17;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v17, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0050D030
// Name: protected: CDmeCollisionModel::CDmeCollisionModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionModel *__thiscall CDmeCollisionModel::CDmeCollisionModel(
        CDmeCollisionModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionModel_vtbl *)&CDmeCollisionModel::`vftable';
  this->m_flMass.m_Storage = 0.0;
  this->m_flMass.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_Storage = false;
  this->m_flInertia = 0;
  this->m_flDamping = 0;
  this->m_flRotationalDamping = 0;
  this->m_flDrag = 0;
  this->m_nMaxConvexPieces.m_pAttribute = nullptr;
  this->m_nMaxConvexPieces.m_Storage = 0;
  this->m_bRemove2D.m_pAttribute = nullptr;
  this->m_bRemove2D.m_Storage = false;
  this->m_flWeldPositionTolerance = 0;
  this->m_flWeldNormalTolerance = 0;
  this->m_bConcave.m_pAttribute = nullptr;
  this->m_bConcave.m_Storage = false;
  this->m_bForceMassCenter.m_pAttribute = nullptr;
  this->m_bForceMassCenter.m_Storage = false;
  this->m_vecMassCenter.m_pAttribute = nullptr;
  this->m_vecMassCenter.m_Storage.x = 0.0;
  this->m_vecMassCenter.m_Storage.y = 0.0;
  this->m_vecMassCenter.m_Storage.z = 0.0;
  this->m_bAssumeWorldSpace.m_pAttribute = nullptr;
  this->m_bAssumeWorldSpace.m_Storage = false;
  this->m_SurfaceProperty.m_pAttribute = nullptr;
  this->m_SurfaceProperty.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050D140
// Name: public: virtual bool CDmeCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionModel::IsA(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D170
// Name: public: virtual int CDmeCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionModel::GetInheritanceDepth(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050D1F0
// Name: protected: virtual void CDmeCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::PerformConstruction(CDmeCollisionModel *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeCollisionModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006ACD40
// Name: _dynamic_initializer_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionModel::s_Allocator,
    blockSize: 196,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3DF0
// Name: _dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACD70
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACD80
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionModel_Helper,
           classname: "DmeCollisionModel",
           pFactory: &g_CDmeCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E00
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeCollisionModel_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DC7B0
// Name: protected: void CDmeCollisionModel::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::OnConstruction(CDmeCollisionModel *this)
{
  CDmaVar<float> *p_m_flMass; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  CDmAttribute *v7; // eax
  CDmAttribute *v8; // eax
  CDmAttribute *v9; // eax
  CDmAttribute *v10; // eax
  CDmAttribute *v11; // eax
  CDmAttribute *v12; // eax
  CDmAttribute *v13; // eax
  CDmAttribute *v14; // eax
  CDmAttribute *v15; // eax
  CDmAttribute *v16; // eax
  CDmAttribute *v17; // eax
  Vector v18; // [esp+0h] [ebp-14h] BYREF
  CUtlSymbolLarge value; // [esp+Ch] [ebp-8h] BYREF
  bool v20; // [esp+13h] [ebp-1h] BYREF

  p_m_flMass = &this->m_flMass;
  value.u.m_Id = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "mass", type: AT_FLOAT, pMemory: &this->m_flMass);
  p_m_flMass->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.u.m_Id);
  v20 = true;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "automaticMassComputation",
         type: AT_BOOL,
         pMemory: &this->m_bAutomaticMassComputation);
  this->m_bAutomaticMassComputation.m_pAttribute = v4;
  CDmAttribute::SetValue<bool>(this: v4, value: &v20);
  value.u.m_Id = 1065353216;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "inertia", type: AT_FLOAT, pMemory: &this->m_flInertia);
  this->m_flInertia.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "damping", type: AT_FLOAT, pMemory: &this->m_flDamping);
  this->m_flDamping.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.u.m_Id);
  value.u.m_Id = 0;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "rotationalDamping",
         type: AT_FLOAT,
         pMemory: &this->m_flRotationalDamping);
  this->m_flRotationalDamping.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.u.m_Id);
  value.u.m_Id = -1082130432;
  v8 = CDmElement::AddExternalAttribute(this, pAttributeName: "drag", type: AT_FLOAT, pMemory: &this->m_flDrag);
  this->m_flDrag.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.u.m_Id);
  value.u.m_Id = 40;
  v9 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxConvexPieces",
         type: AT_INT,
         pMemory: &this->m_nMaxConvexPieces);
  this->m_nMaxConvexPieces.m_pAttribute = v9;
  CDmAttribute::SetValue<int>(this: v9, value: &value.u.m_Id);
  v20 = false;
  v10 = CDmElement::AddExternalAttribute(this, pAttributeName: "remove2d", type: AT_BOOL, pMemory: &this->m_bRemove2D);
  this->m_bRemove2D.m_pAttribute = v10;
  CDmAttribute::SetValue<bool>(this: v10, value: &v20);
  value.u.m_Id = 0;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldPositionTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldPositionTolerance);
  this->m_flWeldPositionTolerance.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.u.m_Id);
  value.u.m_Id = 1065336439;
  v12 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "weldNormalTolerance",
          type: AT_FLOAT,
          pMemory: &this->m_flWeldNormalTolerance);
  this->m_flWeldNormalTolerance.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.u.m_Id);
  v20 = false;
  v13 = CDmElement::AddExternalAttribute(this, pAttributeName: "concave", type: AT_BOOL, pMemory: &this->m_bConcave);
  this->m_bConcave.m_pAttribute = v13;
  CDmAttribute::SetValue<bool>(this: v13, value: &v20);
  v20 = false;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "forceMassCenter",
          type: AT_BOOL,
          pMemory: &this->m_bForceMassCenter);
  this->m_bForceMassCenter.m_pAttribute = v14;
  CDmAttribute::SetValue<bool>(this: v14, value: &v20);
  memset(&v18, 0, sizeof(v18));
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "massCenter",
          type: AT_VECTOR3,
          pMemory: &this->m_vecMassCenter);
  this->m_vecMassCenter.m_pAttribute = v15;
  CDmAttribute::SetValue<Vector>(this: v15, value: &v18);
  v20 = false;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "assumeWorldSpace",
          type: AT_BOOL,
          pMemory: &this->m_bAssumeWorldSpace);
  this->m_bAssumeWorldSpace.m_pAttribute = v16;
  CDmAttribute::SetValue<bool>(this: v16, value: &v20);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
    a1: g_pDataModel.u,
    a2: &value,
    a3: pszFlexControllerType);
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "surfaceProperty",
          type: AT_STRING,
          pMemory: &this->m_SurfaceProperty);
  this->m_SurfaceProperty.m_pAttribute = v17;
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: v17, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004DCAA0
// Name: protected: CDmeCollisionModel::CDmeCollisionModel(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCollisionModel *__thiscall CDmeCollisionModel::CDmeCollisionModel(
        CDmeCollisionModel *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCollisionModel_vtbl *)&CDmeCollisionModel::`vftable';
  this->m_flMass.m_Storage = 0.0;
  this->m_flMass.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_pAttribute = nullptr;
  this->m_bAutomaticMassComputation.m_Storage = false;
  this->m_flInertia = 0;
  this->m_flDamping = 0;
  this->m_flRotationalDamping = 0;
  this->m_flDrag = 0;
  this->m_nMaxConvexPieces.m_pAttribute = nullptr;
  this->m_nMaxConvexPieces.m_Storage = 0;
  this->m_bRemove2D.m_pAttribute = nullptr;
  this->m_bRemove2D.m_Storage = false;
  this->m_flWeldPositionTolerance = 0;
  this->m_flWeldNormalTolerance = 0;
  this->m_bConcave.m_pAttribute = nullptr;
  this->m_bConcave.m_Storage = false;
  this->m_bForceMassCenter.m_pAttribute = nullptr;
  this->m_bForceMassCenter.m_Storage = false;
  this->m_vecMassCenter.m_pAttribute = nullptr;
  this->m_vecMassCenter.m_Storage.x = 0.0;
  this->m_vecMassCenter.m_Storage.y = 0.0;
  this->m_vecMassCenter.m_Storage.z = 0.0;
  this->m_bAssumeWorldSpace.m_pAttribute = nullptr;
  this->m_bAssumeWorldSpace.m_Storage = false;
  this->m_SurfaceProperty.m_pAttribute = nullptr;
  this->m_SurfaceProperty.m_Storage.u.m_Id = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DCBB0
// Name: public: virtual bool CDmeCollisionModel::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCollisionModel::IsA(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DCBE0
// Name: public: virtual int CDmeCollisionModel::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCollisionModel::GetInheritanceDepth(CDmeCollisionModel *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCollisionModel::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DCC60
// Name: protected: virtual void CDmeCollisionModel::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCollisionModel::PerformConstruction(CDmeCollisionModel *this)
{
  CDmeFXClip::OnDestruction();
  CDmeCollisionModel::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E6410
// Name: _dynamic_initializer_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCollisionModel::s_Allocator,
    blockSize: 196,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCollisionModel pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1B0
// Name: _dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCollisionModel::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCollisionModel::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6440
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCollisionModel_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6450
// Name: _dynamic_initializer_for__g_CDmeCollisionModel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCollisionModel_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCollisionModel_Helper,
           classname: "DmeCollisionModel",
           pFactory: &g_CDmeCollisionModel_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC1C0
// Name: _dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCollisionModel_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCollisionModel_Factory.m_CallBackList);
}

} // namespace studiomdl
