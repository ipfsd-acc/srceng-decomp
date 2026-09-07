// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmecamera.cpp
// Functions: 11
// ============================================================

#include "movieobjects\dmecamera.h"

//------------------------------------------------------------------------------
// Address: 0x005569C0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x00556EB0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00557130
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00557160
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005571B0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005571C0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AD7D0
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B03F0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AD800
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD810
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0400
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005ADB60
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (const float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (const float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (const float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (const float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005AE050
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AE2D0
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE300
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AE350
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005AE360
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0067EFC0
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682900
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067EFF0
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F000
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682910
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x105954E0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int v27; // ecx
  char sec[16]; // [esp+0h] [ebp-2Ch] BYREF
  char sz[32]; // [esp+10h] [ebp-1Ch] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  *(_DWORD *)&sz[20] = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, value: (const DmeTime_t *)&sz[20]);
  *(_DWORD *)&sz[20] = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&sz[20]);
  *(_DWORD *)&sz[20] = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: (int *)&sz[20]);
  *(_DWORD *)&sz[20] = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: (int *)&sz[20]);
  *(_DWORD *)&sz[20] = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&sz[20]);
  sz[27] = 0;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: (bool *)&sz[27]);
  *(_DWORD *)&sz[20] = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: (int *)&sz[20]);
  sz[27] = 0;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: (bool *)&sz[27]);
  *(_DWORD *)&sz[20] = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&sz[20]);
  v23 = 0;
  *(_DWORD *)&sz[20] = this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sec, maxLen: 0x20u, pFormat: "scale%d", v23);
    *(_DWORD *)&sz[16] = 1065353216;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sec, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: (float *)&sz[16]);
    V_snprintf(pDest: sec, maxLen: 0x20u, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sec, type: AT_VECTOR3, pMemory: *(void **)&sz[20]);
    v27 = *(_DWORD *)&sz[20];
    *(_DWORD *)(*(_DWORD *)&sz[20] + 12) = v26;
    ++v23;
    ++m_flScale;
    *(_DWORD *)&sz[20] = v27 + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x105959D0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10595C50
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10595C80
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10595CD0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x10595CE0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9830
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 0x20Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAD0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9860
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9870
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9890
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 0x4Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C98C0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C98D0
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAE0
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDAF0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB00
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x005662B0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005667A0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00566A20
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566A50
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00566AA0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x00566AB0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D290
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8C0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D2C0
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D2D0
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D2F0
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D320
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D330
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8D0
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8E0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F8F0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AF330
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005AF820
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AFAA0
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AFAD0
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AFB20
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005AFB30
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F1F20
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BD0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1F50
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1F60
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1F80
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1FB0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1FC0
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BE0
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4BF0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4C00
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00518250
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x00518740
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005189C0
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005189F0
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00518A40
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x00518A50
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056BBA0
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAE0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BBD0
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BBE0
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EAF0
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0051DBA0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (const float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (const float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (const float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (const float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x0051E090
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051E310
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E340
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051E390
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x0051E3A0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCB0
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC10
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCE0
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BCF0
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC20
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DB5B0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (const float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (const float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (const float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (const float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005DBAA0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DBD20
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DBD50
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DBDA0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005DBDB0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0E60
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5420
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0E90
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0EA0
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5430
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051ECA0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (const float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (const float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (const float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (const float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x0051F130
// Name: public: void CDmeCamera::SetFOVx(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::SetFOVx(CDmeCamera *this, float fov)
{
  CDmAttribute::SetValue<float>(this: this->m_flFieldOfView.m_pAttribute, value: &fov);
}

//------------------------------------------------------------------------------
// Address: 0x0051F1B0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051F430
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F460
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F4B0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x0051F4C0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057DC90
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580BF0
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DCC0
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DCD0
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580C00
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A8290
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005A8780
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A8A00
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A8A30
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A8A80
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005A8A90
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EADD0
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA70
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE00
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE10
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE30
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE60
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE70
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA80
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA90
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAA0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00526CE0
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (const float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (const float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (const float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (const float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (const float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (const float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (const float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (const float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (const float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (const float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (const float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (const float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (const float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x005271D0
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00527450
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00527480
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005274D0
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x005274E0
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057B540
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 524,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E300
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B570
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B580
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E310
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00629B10
// Name: protected: void CDmeCamera::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::OnConstruction(CDmeCamera *this)
{
  CDmaVar<float> *p_m_flFieldOfView; // edi
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
  CDmAttribute *v18; // eax
  CDmAttribute *v19; // eax
  CDmAttribute *v20; // eax
  CDmAttribute *v21; // eax
  CDmAttribute *v22; // eax
  int v23; // edi
  CDmaVar<float> *m_flScale; // ebx
  CDmAttribute *v25; // eax
  CDmAttribute *v26; // eax
  int m_tms; // ecx
  char sz[32]; // [esp+10h] [ebp-2Ch] BYREF
  float v29; // [esp+30h] [ebp-Ch] BYREF
  DmeTime_t value; // [esp+34h] [ebp-8h] BYREF
  bool v31; // [esp+3Bh] [ebp-1h] BYREF

  p_m_flFieldOfView = &this->m_flFieldOfView;
  value.m_tms = 1106247680;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "fieldOfView",
         type: AT_FLOAT,
         pMemory: &this->m_flFieldOfView);
  p_m_flFieldOfView->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, value: (float *)&value.m_tms);
  value.m_tms = 1077936128;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "znear", type: AT_FLOAT, pMemory: &this->m_zNear);
  this->m_zNear.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, value: (float *)&value.m_tms);
  value.m_tms = 1188934615;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "zfar", type: AT_FLOAT, pMemory: &this->m_zFar);
  this->m_zFar.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, value: (float *)&value.m_tms);
  value.m_tms = 1116733440;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "focalDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flFocalDistance);
  this->m_flFocalDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
  value.m_tms = 1117126656;
  v7 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "zeroParallaxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flZeroParallaxDistance);
  this->m_flZeroParallaxDistance.m_pAttribute = v7;
  CDmAttribute::SetValue<float>(this: v7, value: (float *)&value.m_tms);
  value.m_tms = 1061158912;
  v8 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "eyeSeparation",
         type: AT_FLOAT,
         pMemory: &this->m_flEyeSeparation);
  this->m_flEyeSeparation.m_pAttribute = v8;
  CDmAttribute::SetValue<float>(this: v8, value: (float *)&value.m_tms);
  value.m_tms = 1045220557;
  v9 = CDmElement::AddExternalAttribute(this, pAttributeName: "aperture", type: AT_FLOAT, pMemory: &this->m_flAperture);
  this->m_flAperture.m_pAttribute = v9;
  CDmAttribute::SetValue<float>(this: v9, value: (float *)&value.m_tms);
  value.m_tms = DmeTime_t::RoundSecondsToTMS(sec: 0x3CAAAAABu);
  v10 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "shutterSpeed",
          type: AT_TIME,
          pMemory: &this->m_shutterSpeed);
  this->m_shutterSpeed.m_pAttribute = v10;
  CDmAttribute::SetValue<DmeTime_t>(this: v10, &value);
  value.m_tms = 1065353216;
  v11 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "toneMapScale",
          type: AT_FLOAT,
          pMemory: &this->m_flToneMapScale);
  this->m_flToneMapScale.m_pAttribute = v11;
  CDmAttribute::SetValue<float>(this: v11, value: (float *)&value.m_tms);
  value.m_tms = 973279855;
  v12 = CDmElement::AddExternalAttribute(this, pAttributeName: "SSAOBias", type: AT_FLOAT, pMemory: &this->m_flAOBias);
  this->m_flAOBias.m_pAttribute = v12;
  CDmAttribute::SetValue<float>(this: v12, value: (float *)&value.m_tms);
  value.m_tms = 1065353216;
  v13 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAOStrength",
          type: AT_FLOAT,
          pMemory: &this->m_flAOStrength);
  this->m_flAOStrength.m_pAttribute = v13;
  CDmAttribute::SetValue<float>(this: v13, value: (float *)&value.m_tms);
  value.m_tms = 1097859072;
  v14 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "SSAORadius",
          type: AT_FLOAT,
          pMemory: &this->m_flAORadius);
  this->m_flAORadius.m_pAttribute = v14;
  CDmAttribute::SetValue<float>(this: v14, value: (float *)&value.m_tms);
  value.m_tms = 1049582633;
  v15 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomScale",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomScale);
  this->m_flBloomScale.m_pAttribute = v15;
  CDmAttribute::SetValue<float>(this: v15, value: (float *)&value.m_tms);
  value.m_tms = 0;
  v16 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "depthOfFieldQuality",
          type: AT_INT,
          pMemory: &this->m_nDoFQuality);
  this->m_nDoFQuality.m_pAttribute = v16;
  CDmAttribute::SetValue<int>(this: v16, value: &value.m_tms);
  value.m_tms = 0;
  v17 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "motionBlurQuality",
          type: AT_INT,
          pMemory: &this->m_nMotionBlurQuality);
  this->m_nMotionBlurQuality.m_pAttribute = v17;
  CDmAttribute::SetValue<int>(this: v17, value: &value.m_tms);
  value.m_tms = 1091567616;
  v18 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "bloomWidth",
          type: AT_FLOAT,
          pMemory: &this->m_flBloomWidth);
  this->m_flBloomWidth.m_pAttribute = v18;
  CDmAttribute::SetValue<float>(this: v18, value: (float *)&value.m_tms);
  v31 = false;
  v19 = CDmElement::AddExternalAttribute(this, pAttributeName: "ortho", type: AT_BOOL, pMemory: &this->m_bOrtho);
  this->m_bOrtho.m_pAttribute = v19;
  CDmAttribute::SetValue<bool>(this: v19, value: &v31);
  value.m_tms = 0;
  v20 = CDmElement::AddExternalAttribute(this, pAttributeName: "axis", type: AT_INT, pMemory: &this->m_nAxis);
  this->m_nAxis.m_pAttribute = v20;
  CDmAttribute::SetValue<int>(this: v20, value: &value.m_tms);
  v31 = false;
  v21 = CDmElement::AddExternalAttribute(
          this,
          pAttributeName: "behindfrustum",
          type: AT_BOOL,
          pMemory: &this->m_bWasBehindFrustum);
  this->m_bWasBehindFrustum.m_pAttribute = v21;
  CDmAttribute::SetValue<bool>(this: v21, value: &v31);
  value.m_tms = 1107296256;
  v22 = CDmElement::AddExternalAttribute(this, pAttributeName: "distance", type: AT_FLOAT, pMemory: &this->m_flDistance);
  this->m_flDistance.m_pAttribute = v22;
  CDmAttribute::SetValue<float>(this: v22, value: (float *)&value.m_tms);
  v23 = 0;
  value.m_tms = (int)this->m_vecLookAt;
  m_flScale = this->m_flScale;
  do
  {
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "scale%d", v23);
    v29 = 1.0;
    v25 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_FLOAT, pMemory: m_flScale);
    m_flScale->m_pAttribute = v25;
    CDmAttribute::SetValue<float>(this: v25, value: &v29);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "lookat%d", v23);
    v26 = CDmElement::AddExternalAttribute(this, pAttributeName: sz, type: AT_VECTOR3, pMemory: (void *)value.m_tms);
    m_tms = value.m_tms;
    *(_DWORD *)(value.m_tms + 12) = v26;
    ++v23;
    ++m_flScale;
    value.m_tms = m_tms + 16;
  }
  while ( v23 < 6 );
  this->m_vecAxis.x = 0.0;
  this->m_vecAxis.y = 0.0;
  this->m_vecAxis.z = 0.0;
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  this->m_angRotation.x = 0.0;
  this->m_angRotation.y = 0.0;
  this->m_angRotation.z = 0.0;
  SetIdentityMatrix(matrix: &this->m_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x0062A000
// Name: protected: CDmeCamera::CDmeCamera(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeCamera *__thiscall CDmeCamera::CDmeCamera(
        CDmeCamera *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->CDmeDag::m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->CDmeDag::m_Transform.m_pAttribute = nullptr;
  this->CDmeDag::m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeCamera_vtbl *)&CDmeCamera::`vftable';
  this->m_flFieldOfView.m_pAttribute = nullptr;
  this->m_flFieldOfView.m_Storage = 0.0;
  this->m_zNear.m_pAttribute = nullptr;
  this->m_zNear.m_Storage = 0.0;
  this->m_zFar.m_pAttribute = nullptr;
  this->m_zFar.m_Storage = 0.0;
  this->m_flFocalDistance.m_pAttribute = nullptr;
  this->m_flFocalDistance.m_Storage = 0.0;
  this->m_flZeroParallaxDistance.m_pAttribute = nullptr;
  this->m_flZeroParallaxDistance.m_Storage = 0.0;
  this->m_flEyeSeparation.m_pAttribute = nullptr;
  this->m_flEyeSeparation.m_Storage = 0.0;
  this->m_flAperture.m_pAttribute = nullptr;
  this->m_flAperture.m_Storage = 0.0;
  this->m_shutterSpeed.m_pAttribute = nullptr;
  this->m_shutterSpeed.m_Storage.m_tms = 0;
  this->m_flToneMapScale.m_pAttribute = nullptr;
  this->m_flToneMapScale.m_Storage = 0.0;
  this->m_flAOBias.m_pAttribute = nullptr;
  this->m_flAOBias.m_Storage = 0.0;
  this->m_flAOStrength.m_pAttribute = nullptr;
  this->m_flAOStrength.m_Storage = 0.0;
  this->m_flAORadius.m_pAttribute = nullptr;
  this->m_flAORadius.m_Storage = 0.0;
  this->m_flBloomScale.m_pAttribute = nullptr;
  this->m_flBloomScale.m_Storage = 0.0;
  this->m_flBloomWidth.m_pAttribute = nullptr;
  this->m_flBloomWidth.m_Storage = 0.0;
  this->m_nDoFQuality.m_pAttribute = nullptr;
  this->m_nDoFQuality.m_Storage = 0;
  this->m_nMotionBlurQuality.m_pAttribute = nullptr;
  this->m_nMotionBlurQuality.m_Storage = 0;
  this->m_bOrtho.m_pAttribute = nullptr;
  this->m_bOrtho.m_Storage = false;
  this->m_vecLookAt[0].m_pAttribute = nullptr;
  this->m_vecLookAt[0].m_Storage.x = 0.0;
  this->m_vecLookAt[0].m_Storage.y = 0.0;
  this->m_vecLookAt[0].m_Storage.z = 0.0;
  this->m_vecLookAt[1].m_pAttribute = nullptr;
  this->m_vecLookAt[1].m_Storage.x = 0.0;
  this->m_vecLookAt[1].m_Storage.y = 0.0;
  this->m_vecLookAt[1].m_Storage.z = 0.0;
  this->m_vecLookAt[2].m_pAttribute = nullptr;
  this->m_vecLookAt[2].m_Storage.x = 0.0;
  this->m_vecLookAt[2].m_Storage.y = 0.0;
  this->m_vecLookAt[2].m_Storage.z = 0.0;
  this->m_vecLookAt[3].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.x = 0.0;
  this->m_vecLookAt[3].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_pAttribute = nullptr;
  this->m_vecLookAt[5].m_pAttribute = nullptr;
  this->m_vecLookAt[3].m_Storage.z = 0.0;
  this->m_vecLookAt[4].m_Storage.x = 0.0;
  this->m_vecLookAt[4].m_Storage.y = 0.0;
  this->m_vecLookAt[4].m_Storage.z = 0.0;
  this->m_vecLookAt[5].m_Storage.x = 0.0;
  this->m_vecLookAt[5].m_Storage.y = 0.0;
  this->m_vecLookAt[5].m_Storage.z = 0.0;
  this->m_flScale[0].m_pAttribute = nullptr;
  this->m_flScale[1].m_pAttribute = nullptr;
  this->m_flScale[2].m_pAttribute = nullptr;
  this->m_flScale[3].m_pAttribute = nullptr;
  this->m_flScale[4].m_pAttribute = nullptr;
  this->m_flScale[5].m_pAttribute = nullptr;
  this->m_flScale[0].m_Storage = 0.0;
  this->m_flScale[1].m_Storage = 0.0;
  this->m_flScale[2].m_Storage = 0.0;
  this->m_flScale[3].m_Storage = 0.0;
  this->m_flScale[4].m_Storage = 0.0;
  this->m_flScale[5].m_Storage = 0.0;
  this->m_flDistance.m_pAttribute = nullptr;
  this->m_flDistance.m_Storage = 0.0;
  this->m_nAxis.m_pAttribute = nullptr;
  this->m_nAxis.m_Storage = 0;
  this->m_bWasBehindFrustum.m_pAttribute = nullptr;
  this->m_bWasBehindFrustum.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062A280
// Name: public: virtual bool CDmeCamera::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeCamera::IsA(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062A2B0
// Name: public: virtual int CDmeCamera::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::GetInheritanceDepth(CDmeCamera *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeCamera::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062A300
// Name: protected: virtual int CDmeCamera::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeCamera::AllocatedSize(CDmeCamera *this)
{
  return 524;
}

//------------------------------------------------------------------------------
// Address: 0x0062A310
// Name: protected: virtual void CDmeCamera::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCamera::PerformConstruction(CDmeCamera *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  CDmeCamera::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B9450
// Name: _dynamic_initializer_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeCamera::s_Allocator,
    blockSize: 0x20Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeCamera pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD100
// Name: _dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeCamera::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeCamera::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9480
// Name: _dynamic_initializer_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeCamera_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeCamera_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9490
// Name: _dynamic_initializer_for__g_CDmeCamera_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeCamera_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeCamera_Helper,
           classname: "DmeCamera",
           pFactory: &g_CDmeCamera_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD110
// Name: _dynamic_atexit_destructor_for__g_CDmeCamera_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeCamera_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeCamera_Factory.m_CallBackList);
}

} // namespace vmap
