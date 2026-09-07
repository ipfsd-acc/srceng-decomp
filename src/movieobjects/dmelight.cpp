// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmelight.cpp
// Functions: 49
// ============================================================

#include "movieobjects\dmelight.h"

//------------------------------------------------------------------------------
// Address: 0x00557BC0
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x00557C90
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00557D90
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00557E60
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00557F20
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00557FC0
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005582B0
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00558340
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558370
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005583C0
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005583D0
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00558490
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005584D0
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558530
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00558580
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005585C0
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558620
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x00558630
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00558680
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00558720
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558760
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005587E0
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00558840
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00558880
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AD8F0
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD950
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD9B0
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADA10
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADA70
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0450
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0460
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0470
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0480
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0490
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AD920
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD930
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AD980
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD990
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AD9E0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD9F0
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADA40
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADA50
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ADAA0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADAB0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B04A0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B04B0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B04C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B04D0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B04E0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005AED20
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x005AEDF0
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEEF0
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005AEFC0
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF080
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005AF120
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF410
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AF4A0
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF4D0
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF530
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x005AF5F0
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF630
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF6D0
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF710
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF770
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x005AF780
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AF7D0
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005AF870
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF8B0
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF920
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AF980
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AF9C0
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AFA20
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C2750
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0067F0E0
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F140
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F1A0
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F200
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F260
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682960
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682970
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682980
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682990
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006829A0
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F110
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F120
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F170
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F180
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F1D0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F1E0
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F230
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F240
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067F290
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F2A0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006829B0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006829C0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006829D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006829E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006829F0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0046FCB0
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00519410
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x005194E0
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005195E0
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005196B0
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00519770
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00519810
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00519B00
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00519B90
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519BC0
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519C10
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x00519CD0
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519D10
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519DB0
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519DF0
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519E50
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x00519E60
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00519EB0
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00519F50
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519F90
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051A010
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051A070
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051A0B0
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051A110
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056BCC0
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BD20
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BD80
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BDE0
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BE40
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB40
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB50
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB60
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB70
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB80
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BCF0
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BD00
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BD50
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BD60
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BDB0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BDC0
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BE10
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BE20
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BE70
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BE80
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB90
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBA0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBB0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBC0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EBD0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004741D0
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051EDC0
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x0051EE90
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051EFA0
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051F070
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F130
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051F1D0
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F4C0
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051F550
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F580
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F5D0
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x0051F690
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F6D0
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F740
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051F790
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F7D0
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F830
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x0051F840
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051F890
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0051F930
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F970
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051F9E0
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051FA40
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FA80
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0057BDD0
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE30
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE90
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEF0
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF50
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC70
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC80
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC90
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECA0
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECB0
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE00
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE10
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE60
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE70
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BEC0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BED0
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF20
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF30
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF80
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BF90
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECC0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECD0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECE0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECF0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057ED00
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050DA90
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x005DC580
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x005DC650
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005DC750
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005DC820
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005DC8E0
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005DC980
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCC70
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DCD00
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCD30
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCDA0
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x005DCE60
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCEA0
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCF40
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCF80
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DCFE0
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DD030
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005DD0D0
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DD110
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DD190
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005DD1F0
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DD230
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005DD290
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0F20
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0F80
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0FF0
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1050
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B10B0
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5460
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5470
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5480
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5490
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B54A0
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0F50
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0F60
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0FB0
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0FC0
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1020
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1030
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B1080
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1090
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B10E0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B10F0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B54B0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B54C0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B54D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B54E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B54F0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051FEF0
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x0051FFC0
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005200C0
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00520190
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00520250
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005202F0
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005205E0
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00520680
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005206B0
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520700
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction();
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x005207C0
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520800
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005208A0
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005208E0
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520940
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x00520950
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005209A0
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00520A40
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520A80
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520B00
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00520B60
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520BA0
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00520C00
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00520C10
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057DDB0
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DE10
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DE70
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DED0
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF30
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580C50
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580C60
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580C70
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580C80
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580C90
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DDE0
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DDF0
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DE40
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DE50
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DEA0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DEB0
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF00
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF10
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF60
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DF70
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580CA0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580CB0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580CC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580CD0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580CE0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00527CF0
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x00527DC0
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (int)pDesc, value: nullptr, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00527EC0
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00527F90
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (int)pDesc, value: nullptr, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00528050
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005280F0
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (int)pDesc, value: nullptr, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005283E0
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00528470
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005284A0
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005284F0
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (const float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x005285B0
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005285F0
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00528650
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005286A0
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005286E0
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00528740
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmePointLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x00528750
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005287A0
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00528840
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00528880
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00528900
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00528960
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005289A0
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00529A50
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0057B600
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B660
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B6C0
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 184,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B720
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 208,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B780
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 152,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E340
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E350
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E360
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E370
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E380
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B630
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B640
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B690
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B6A0
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B6F0
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B700
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B750
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B760
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B7B0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B7C0
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E390
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3A0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3C0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3D0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062AD60
// Name: protected: void CDmeLight::SetupRenderStateInternal(struct LightDesc_t __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::SetupRenderStateInternal(
        CDmeLight *this,
        LightDesc_t *desc,
        float flAtten0,
        float flAtten1,
        float flAtten2)
{
  float v5; // xmm0_4

  desc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  desc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  desc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v5 = this->m_flIntensity.m_Storage * 0.0039215689;
  desc->m_Color.x = desc->m_Color.x * v5;
  desc->m_Color.y = desc->m_Color.y * v5;
  desc->m_Color.z = desc->m_Color.z * v5;
  desc->m_Attenuation0 = flAtten0;
  desc->m_Attenuation1 = flAtten1;
  desc->m_Attenuation2 = flAtten2;
  desc->m_Flags = 0;
  if ( flAtten0 != 0.0 )
    desc->m_Flags = 1;
  if ( flAtten1 != 0.0 )
    desc->m_Flags |= 2u;
  if ( flAtten2 != 0.0 )
    desc->m_Flags |= 4u;
}

//------------------------------------------------------------------------------
// Address: 0x0062AE30
// Name: public: virtual bool CDmeDirectionalLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeDirectionalLight::GetLightDesc(CDmeDirectionalLight *this, LightDesc_t *pDesc)
{
  float v3; // xmm0_4
  matrix3x4_t m; // [esp+8h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_DIRECTIONAL;
  pDesc->m_Color.x = (float)this->m_Color.m_Storage._color[0];
  pDesc->m_Color.y = (float)this->m_Color.m_Storage._color[1];
  pDesc->m_Color.z = (float)this->m_Color.m_Storage._color[2];
  v3 = this->m_flIntensity.m_Storage * 0.0039215689;
  pDesc->m_Color.x = pDesc->m_Color.x * v3;
  pDesc->m_Color.y = pDesc->m_Color.y * v3;
  pDesc->m_Color.z = pDesc->m_Color.z * v3;
  pDesc->m_Attenuation0 = 1.0;
  pDesc->m_Attenuation1 = 0.0;
  pDesc->m_Attenuation2 = 0.0;
  pDesc->m_Flags = 1;
  CDmeDag::GetAbsTransform(this, matAbsTransform: &m);
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0062AF30
// Name: protected: void CDmePointLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::OnConstruction(CDmePointLight *this)
{
  CDmaVar<float> *p_m_flAttenuation0; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flAttenuation0 = &this->m_flAttenuation0;
  value = 1.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "constantAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation0);
  p_m_flAttenuation0->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 0.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "linearAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation1);
  this->m_flAttenuation1.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 0.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "quadraticAttenuation",
         type: AT_FLOAT,
         pMemory: &this->m_flAttenuation2);
  this->m_flAttenuation2.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
  value = 600.0;
  v6 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "maxDistance",
         type: AT_FLOAT,
         pMemory: &this->m_flMaxDistance);
  this->m_flMaxDistance.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0062B000
// Name: public: virtual bool CDmePointLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmePointLight::GetLightDesc(CDmePointLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_POINT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  pDesc->m_Direction.x = 0.0;
  pDesc->m_Direction.y = 0.0;
  pDesc->m_Direction.z = 1.0;
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  pDesc->m_Theta = 0.0;
  pDesc->m_Phi = 0.0;
  pDesc->m_Falloff = 1.0;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B0C0
// Name: protected: void CDmeSpotLight::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::OnConstruction(CDmeSpotLight *this)
{
  CDmaVar<float> *p_m_flSpotInnerAngle; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  float value; // [esp+0h] [ebp-4h] BYREF

  p_m_flSpotInnerAngle = &this->m_flSpotInnerAngle;
  value = 60.0;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotInnerAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotInnerAngle);
  p_m_flSpotInnerAngle->m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, &value);
  value = 90.0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotOuterAngle",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotOuterAngle);
  this->m_flSpotOuterAngle.m_pAttribute = v4;
  CDmAttribute::SetValue<float>(this: v4, &value);
  value = 1.0;
  v5 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "spotAngularFalloff",
         type: AT_FLOAT,
         pMemory: &this->m_flSpotAngularFalloff);
  this->m_flSpotAngularFalloff.m_pAttribute = v5;
  CDmAttribute::SetValue<float>(this: v5, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0062B160
// Name: public: virtual bool CDmeSpotLight::GetLightDesc(struct LightDesc_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSpotLight::GetLightDesc(CDmeSpotLight *this, LightDesc_t *pDesc)
{
  CDmeDag *v3; // ecx
  float v4; // xmm3_4
  matrix3x4_t m; // [esp+14h] [ebp-30h] BYREF

  memset(dst: (unsigned __int8 *)pDesc, value: 0, count: sizeof(LightDesc_t));
  pDesc->m_Type = MATERIAL_LIGHT_SPOT;
  CDmeLight::SetupRenderStateInternal(
    this,
    desc: pDesc,
    flAtten0: this->m_flAttenuation0.m_Storage,
    flAtten1: this->m_flAttenuation1.m_Storage,
    flAtten2: this->m_flAttenuation2.m_Storage);
  CDmeDag::GetAbsTransform(this: v3, matAbsTransform: &m);
  pDesc->m_Position.x = m.m_flMatVal[0][3];
  pDesc->m_Position.y = m.m_flMatVal[1][3];
  pDesc->m_Position.z = m.m_flMatVal[2][3];
  MatrixGetColumn(in: &m, column: 0, out: &pDesc->m_Direction);
  pDesc->m_Range = this->m_flMaxDistance.m_Storage;
  v4 = (float)(this->m_flSpotInnerAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Theta = v4;
  pDesc->m_Phi = (float)(this->m_flSpotOuterAngle.m_Storage * 0.5) * 3.141592653589793 * 0.005555555555555556;
  pDesc->m_Falloff = this->m_flSpotAngularFalloff.m_Storage;
  LightDesc_t::RecalculateDerivedValues(this: pDesc);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B450
// Name: protected: CDmeLight::CDmeLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeLight *__thiscall CDmeLight::CDmeLight(
        CDmeLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeLight_vtbl *)&CDmeDag::`vftable';
  this->m_Visible.m_pAttribute = nullptr;
  this->m_Visible.m_Storage = false;
  this->m_bDisableOverrideParent.m_pAttribute = nullptr;
  this->m_bDisableOverrideParent.m_Storage = false;
  this->m_Transform.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Transform.m_pAttribute = nullptr;
  this->m_Transform.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_Shape.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_Shape.m_pAttribute = nullptr;
  this->m_Shape.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_Children);
  this->__vftable = (CDmeLight_vtbl *)&CDmeLight::`vftable';
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_flIntensity.m_pAttribute = nullptr;
  this->m_flIntensity.m_Storage = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062B4F0
// Name: public: virtual bool CDmeLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeLight::IsA(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B520
// Name: public: virtual int CDmeLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeLight::GetInheritanceDepth(CDmeLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B570
// Name: protected: virtual void CDmeLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeLight::PerformConstruction(CDmeLight *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  Color value; // [esp+8h] [ebp-4h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeDag::OnConstruction(this);
  value = (Color)-1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "color", type: AT_COLOR, pMemory: &this->m_Color);
  this->m_Color.m_pAttribute = v2;
  CDmAttribute::SetValue<Color>(this: v2, &value);
  value = (Color)1065353216;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "intensity",
         type: AT_FLOAT,
         pMemory: &this->m_flIntensity);
  this->m_flIntensity.m_pAttribute = v3;
  CDmAttribute::SetValue<float>(this: v3, (float *)&value);
}

//------------------------------------------------------------------------------
// Address: 0x0062B630
// Name: public: virtual bool CDmeDirectionalLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeDirectionalLight::IsA(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B670
// Name: public: virtual int CDmeDirectionalLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeDirectionalLight::GetInheritanceDepth(CDmeDirectionalLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeDirectionalLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B6E0
// Name: protected: virtual void CDmeDirectionalLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDmeDirectionalLight::PerformConstruction(CDmeAmbientLight *this)
{
  CDmeLight::PerformConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062B730
// Name: public: virtual bool CDmePointLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmePointLight::IsA(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B770
// Name: public: virtual int CDmePointLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::GetInheritanceDepth(CDmePointLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B7D0
// Name: protected: virtual void CDmePointLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmePointLight::PerformConstruction(CDmePointLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062B820
// Name: protected: CDmeSpotLight::CDmeSpotLight(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeSpotLight *__thiscall CDmeSpotLight::CDmeSpotLight(
        CDmeSpotLight *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmeLight::CDmeLight(this, handle, pElementTypeName, id, pElementName, fileid);
  this->m_flAttenuation0.m_Storage = 0.0;
  this->m_flAttenuation0.m_pAttribute = nullptr;
  this->m_flAttenuation1 = 0;
  this->m_flAttenuation2 = 0;
  this->m_flMaxDistance = 0;
  this->__vftable = (CDmeSpotLight_vtbl *)&CDmeSpotLight::`vftable';
  this->m_flSpotInnerAngle = 0;
  this->m_flSpotOuterAngle = 0;
  this->m_flSpotAngularFalloff = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0062B8C0
// Name: public: virtual bool CDmeSpotLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSpotLight::IsA(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B900
// Name: public: virtual int CDmeSpotLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSpotLight::GetInheritanceDepth(CDmeSpotLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSpotLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmePointLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 2;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 3;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062B970
// Name: protected: virtual void CDmeSpotLight::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformDestruction(CDmeRigHandle *this)
{
  CDmeDag::OnDestruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0062B990
// Name: protected: virtual void CDmeSpotLight::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSpotLight::PerformConstruction(CDmeSpotLight *this)
{
  CDmeLight::PerformConstruction(this);
  CDmePointLight::OnConstruction(this);
  CDmeSpotLight::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062B9F0
// Name: public: virtual bool CDmeAmbientLight::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAmbientLight::IsA(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062BA30
// Name: public: virtual int CDmeAmbientLight::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAmbientLight::GetInheritanceDepth(CDmeAmbientLight *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAmbientLight::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeLight::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeDag::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006584C0
// Name: protected: virtual int CDmePointLight::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmePointLight::AllocatedSize(CDmeWorldSpotLight *this)
{
  return 184;
}

//------------------------------------------------------------------------------
// Address: 0x006B9570
// Name: _dynamic_initializer_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeLight::s_Allocator,
    blockSize: 0x98u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B95D0
// Name: _dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeDirectionalLight::s_Allocator,
    blockSize: 0x98u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeDirectionalLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9630
// Name: _dynamic_initializer_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmePointLight::s_Allocator,
    blockSize: 0xB8u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmePointLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9690
// Name: _dynamic_initializer_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSpotLight::s_Allocator,
    blockSize: 0xD0u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSpotLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B96F0
// Name: _dynamic_initializer_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAmbientLight::s_Allocator,
    blockSize: 0x98u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAmbientLight pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD160
// Name: _dynamic_atexit_destructor_for__CDmeLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD170
// Name: _dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeDirectionalLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeDirectionalLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD180
// Name: _dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmePointLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmePointLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD190
// Name: _dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSpotLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSpotLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1A0
// Name: _dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAmbientLight::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAmbientLight::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B95A0
// Name: _dynamic_initializer_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B95B0
// Name: _dynamic_initializer_for__g_CDmeLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeLight_Helper,
           classname: "DmeLight",
           pFactory: &g_CDmeLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9600
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeDirectionalLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9610
// Name: _dynamic_initializer_for__g_CDmeDirectionalLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeDirectionalLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeDirectionalLight_Helper,
           classname: "DmeDirectionalLight",
           pFactory: &g_CDmeDirectionalLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9660
// Name: _dynamic_initializer_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmePointLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmePointLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9670
// Name: _dynamic_initializer_for__g_CDmePointLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmePointLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmePointLight_Helper,
           classname: "DmePointLight",
           pFactory: &g_CDmePointLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B96C0
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSpotLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B96D0
// Name: _dynamic_initializer_for__g_CDmeSpotLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSpotLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSpotLight_Helper,
           classname: "DmeSpotLight",
           pFactory: &g_CDmeSpotLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9720
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAmbientLight_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9730
// Name: _dynamic_initializer_for__g_CDmeAmbientLight_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAmbientLight_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAmbientLight_Helper,
           classname: "DmeAmbientLight",
           pFactory: &g_CDmeAmbientLight_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1B0
// Name: _dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeDirectionalLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeDirectionalLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1C0
// Name: _dynamic_atexit_destructor_for__g_CDmePointLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmePointLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmePointLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSpotLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSpotLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1E0
// Name: _dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAmbientLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAmbientLight_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD1F0
// Name: _dynamic_atexit_destructor_for__g_CDmeLight_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeLight_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeLight_Factory.m_CallBackList);
}

} // namespace vmap
