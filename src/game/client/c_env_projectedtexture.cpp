// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_projectedtexture.cpp
// Functions: 24
// ============================================================

#include "game\client\c_env_projectedtexture.h"

//------------------------------------------------------------------------------
// Address: 0x100683F0
// Name: public: virtual class ClientClass __near * C_EnvProjectedTexture::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvProjectedTexture::GetClientClass(C_EnvProjectedTexture *this)
{
  return &__g_C_EnvProjectedTextureClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100686B0
// Name: public: void C_EnvProjectedTexture::ShutDownLightHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::ShutDownLightHandle(C_EnvProjectedTexture *this)
{
  int m_LightHandle; // eax
  IClientShadowMgr_vtbl *v3; // edx

  m_LightHandle = this->m_LightHandle;
  if ( (_WORD)m_LightHandle != 0xFFFF )
  {
    v3 = g_pClientShadowMgr->__vftable;
    if ( this->m_bSimpleProjection )
      ((void (__stdcall *)(int))v3->DestroyProjection)(a1: m_LightHandle);
    else
      ((void (__stdcall *)(int))v3->DestroyFlashlight)(a1: m_LightHandle);
    this->m_LightHandle = -1;
  }
  this->m_bIsCurrentlyProjected = false;
}

//------------------------------------------------------------------------------
// Address: 0x10068700
// Name: public: void C_EnvProjectedTexture::SetLightColor(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::SetLightColor(
        C_EnvProjectedTexture *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a)
{
  this->m_LightColor.r = r;
  this->m_LightColor.g = g;
  this->m_LightColor.b = b;
  this->m_LightColor.a = a;
}

//------------------------------------------------------------------------------
// Address: 0x10068730
// Name: public: void C_EnvProjectedTexture::SetSize(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::SetSize(C_EnvProjectedTexture *this, float flSize)
{
  this->m_flProjectionSize = flSize;
}

//------------------------------------------------------------------------------
// Address: 0x10068750
// Name: public: void C_EnvProjectedTexture::SetRotation(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::SetRotation(C_EnvProjectedTexture *this, float flRotation)
{
  this->m_flRotation = flRotation;
}

//------------------------------------------------------------------------------
// Address: 0x10068770
// Name: public: matrix3x4_t::matrix3x4_t(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__thiscall matrix3x4_t::matrix3x4_t(
        matrix3x4_t *this,
        const Vector *xAxis,
        const Vector *yAxis,
        const Vector *zAxis,
        const Vector *vecOrigin)
{
  this->m_flMatVal[0][0] = xAxis->x;
  *(Vector *)&this->m_flMatVal[0][1] = *yAxis;
  this->m_flMatVal[1][0] = xAxis->y;
  this->m_flMatVal[1][1] = yAxis->y;
  this->m_flMatVal[1][2] = zAxis->y;
  this->m_flMatVal[1][3] = vecOrigin->y;
  this->m_flMatVal[2][0] = xAxis->z;
  this->m_flMatVal[2][1] = yAxis->z;
  this->m_flMatVal[2][2] = zAxis->z;
  this->m_flMatVal[2][3] = vecOrigin->z;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100687D0
// Name: float Approach(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Approach(float target, float value, float speed)
{
  if ( (float)(target - value) > speed )
    return (float)(value + speed);
  if ( COERCE_FLOAT(LODWORD(speed) ^ _mask__NegFloat_) <= (float)(target - value) )
    return target;
  return (float)(value - speed);
}

//------------------------------------------------------------------------------
// Address: 0x10068830
// Name: public: FlashlightState_t::FlashlightState_t(void)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall FlashlightState_t::FlashlightState_t(FlashlightState_t *this)
{
  this->m_uberlightState.m_fNearEdge = 2.0;
  this->m_uberlightState.m_fFarEdge = 100.0;
  this->m_uberlightState.m_fCutOn = 10.0;
  this->m_uberlightState.m_fWedge = 0.050000001;
  this->m_uberlightState.m_fHedge = 0.050000001;
  this->m_uberlightState.m_fCutOff = 650.0;
  this->m_uberlightState.m_fWidth = 0.30000001;
  this->m_uberlightState.m_fHeight = 0.30000001;
  this->m_uberlightState.m_fShearx = 0.0;
  this->m_uberlightState.m_fSheary = 0.0;
  this->m_uberlightState.m_fRoundness = 0.80000001;
  this->m_flShadowMapResolution = 1024.0;
  this->m_flShadowFilterSize = 3.0;
  this->m_flShadowSlopeScaleDepthBias = 16.0;
  this->m_flShadowJitterSeed = 0.0;
  this->m_flShadowAtten = 0.0;
  this->m_flAmbientOcclusion = 0.0;
  this->m_flNoiseStrength = 0.80000001;
  this->m_flFlashlightTime = 0.0;
  this->m_flPlaneOffset = 0.0;
  *(_WORD *)&this->m_bEnableShadows = 0;
  this->m_flShadowDepthBias = 0.00050000002;
  this->m_nShadowQuality = 0;
  this->m_bShadowHighRes = false;
  this->m_nLeft = -1;
  this->m_nTop = -1;
  this->m_nRight = -1;
  this->m_nBottom = -1;
  this->m_bUberlight = false;
  this->m_bVolumetric = false;
  this->m_nNumPlanes = 64;
  this->m_flVolumetricIntensity = 1.0;
  this->m_bOrtho = false;
  this->m_fOrthoLeft = -1.0;
  this->m_fOrthoRight = 1.0;
  this->m_fOrthoTop = -1.0;
  this->m_fOrthoBottom = 1.0;
  this->m_fBrightnessScale = 1.0;
  this->m_pSpotlightTexture = nullptr;
  this->m_pProjectedMaterial = nullptr;
  *(_WORD *)&this->m_bShareBetweenSplitscreenPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100689C0
// Name: private: bool C_EnvProjectedTexture::IsBBoxVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_EnvProjectedTexture::IsBBoxVisible(C_EnvProjectedTexture *this)
{
  const Vector *v2; // eax
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm0_4
  __int64 v8; // [esp+4h] [ebp-30h] BYREF
  float v9; // [esp+Ch] [ebp-28h]
  __int64 v10; // [esp+10h] [ebp-24h] BYREF
  float v11; // [esp+18h] [ebp-1Ch]
  __int64 v12; // [esp+1Ch] [ebp-18h]
  float v13; // [esp+24h] [ebp-10h]
  __int64 v14; // [esp+28h] [ebp-Ch]
  float v15; // [esp+30h] [ebp-4h]

  v2 = this->GetAbsOrigin(this);
  *(float *)&v14 = this->m_vecExtentsMax.x + v2->x;
  *((float *)&v14 + 1) = this->m_vecExtentsMax.y + v2->y;
  GetAbsOrigin = this->GetAbsOrigin;
  v15 = this->m_vecExtentsMax.z + v2->z;
  v4 = (float *)GetAbsOrigin(this);
  v5 = this->m_vecExtentsMin.z + v4[2];
  *(float *)&v12 = *v4 + this->m_vecExtentsMin.x;
  *((float *)&v12 + 1) = this->m_vecExtentsMin.y + v4[1];
  v8 = v14;
  v10 = v12;
  v6 = v15 - 1.0;
  v13 = v5;
  v9 = v15;
  v11 = v5;
  if ( C_EnvProjectedTexture::m_flVisibleBBoxMinHeight <= (float)(v15 - 1.0) )
    v6 = C_EnvProjectedTexture::m_flVisibleBBoxMinHeight;
  if ( v5 <= v6 )
    v11 = v6;
  return !engine->CullBox(this: engine, a2: (const Vector *)&v10, a3: (const Vector *)&v8);
}

//------------------------------------------------------------------------------
// Address: 0x10068AB0
// Name: public: C_EnvProjectedTexture::C_EnvProjectedTexture(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvProjectedTexture *__thiscall C_EnvProjectedTexture::C_EnvProjectedTexture(C_EnvProjectedTexture *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvProjectedTexture_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvProjectedTexture::`vftable';
  this->m_hTargetEntity.m_Index = -1;
  CTextureReference::CTextureReference(this: &this->m_SpotlightTexture);
  CMaterialReference::CMaterialReference(
    this: &this->m_ProjectedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_LightHandle = -1;
  this->m_bForceUpdate = true;
  this->m_pMaterial = nullptr;
  this->m_bIsCurrentlyProjected = false;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068B40
// Name: public: virtual C_EnvProjectedTexture::~C_EnvProjectedTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::~C_EnvProjectedTexture(C_EnvProjectedTexture *this)
{
  int m_LightHandle; // eax
  IClientShadowMgr_vtbl *v3; // edx

  m_LightHandle = this->m_LightHandle;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvProjectedTexture_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvProjectedTexture::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvProjectedTexture::`vftable';
  if ( (_WORD)m_LightHandle != 0xFFFF )
  {
    v3 = g_pClientShadowMgr->__vftable;
    if ( this->m_bSimpleProjection )
      ((void (__stdcall *)(int))v3->DestroyProjection)(a1: m_LightHandle);
    else
      ((void (__stdcall *)(int))v3->DestroyFlashlight)(a1: m_LightHandle);
    this->m_LightHandle = -1;
  }
  this->m_bIsCurrentlyProjected = false;
  CMaterialReference::~CMaterialReference(this: &this->m_ProjectedMaterial);
  CTextureReference::~CTextureReference(this: &this->m_SpotlightTexture);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10068BD0
// Name: public: void C_EnvProjectedTexture::SetMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::SetMaterial(C_EnvProjectedTexture *this, IMaterial *pMaterial)
{
  CMaterialReference *p_m_ProjectedMaterial; // ecx

  p_m_ProjectedMaterial = &this->m_ProjectedMaterial;
  if ( pMaterial != p_m_ProjectedMaterial->m_pMaterial )
  {
    CMaterialReference::Init(this: p_m_ProjectedMaterial, pMaterial);
    pMaterial->IncrementReferenceCount(this: pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068C00
// Name: public: bool C_EnvProjectedTexture::ShouldUpdate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_EnvProjectedTexture::ShouldUpdate(C_EnvProjectedTexture *this)
{
  CPULevel_t ActualCPULevel; // eax
  unsigned __int8 m_nMinCPULevel; // cl
  unsigned __int8 m_nMaxCPULevel; // cl
  bool result; // al
  GPULevel_t GPULevel; // eax
  unsigned __int8 m_nMinGPULevel; // cl
  unsigned __int8 m_nMaxGPULevel; // cl

  ActualCPULevel = GetActualCPULevel();
  m_nMinCPULevel = this->m_nMinCPULevel;
  result = false;
  if ( m_nMinCPULevel == 0 || m_nMinCPULevel - 1 <= ActualCPULevel )
  {
    m_nMaxCPULevel = this->m_nMaxCPULevel;
    if ( m_nMaxCPULevel == 0 || m_nMaxCPULevel - 1 >= ActualCPULevel )
    {
      GPULevel = GetGPULevel();
      m_nMinGPULevel = this->m_nMinGPULevel;
      if ( m_nMinGPULevel == 0 || m_nMinGPULevel - 1 <= GPULevel )
      {
        m_nMaxGPULevel = this->m_nMaxGPULevel;
        if ( m_nMaxGPULevel == 0 || m_nMaxGPULevel - 1 >= GPULevel )
          return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068CB0
// Name: public: static class C_EnvProjectedTexture __near * C_EnvProjectedTexture::Create(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvProjectedTexture *__cdecl C_EnvProjectedTexture::Create()
{
  C_EnvProjectedTexture *v0; // eax
  C_EnvProjectedTexture *v1; // esi
  QAngle absAngles; // [esp+8h] [ebp-Ch] BYREF

  v0 = (C_EnvProjectedTexture *)C_BaseEntity::operator new(stAllocateBlock: 0xB00u);
  if ( v0 != nullptr )
    v1 = C_EnvProjectedTexture::C_EnvProjectedTexture(this: v0);
  else
    v1 = nullptr;
  v1->m_flNearZ = 4.0;
  v1->m_flFarZ = 2000.0;
  v1->m_flLightFOV = 10.0;
  v1->m_flColorTransitionTime = 1.0;
  absAngles.x = 90.0;
  v1->m_nShadowQuality = 1;
  v1->m_LightColor = (color32_s)-1;
  *(_DWORD *)&v1->m_bEnableShadows = 16777472;
  v1->m_bCameraSpace = false;
  absAngles.y = 0.0;
  absAngles.z = 0.0;
  C_BaseEntity::SetAbsAngles(this: v1, &absAngles);
  v1->m_flProjectionSize = 500.0;
  *(_WORD *)&v1->m_bState = 257;
  v1->m_flRotation = 0.0;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10068DC0
// Name: public: void C_EnvProjectedTexture::UpdateLight(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall C_EnvProjectedTexture::UpdateLight(C_EnvProjectedTexture *this@<ecx>, float a2@<ebp>)
{
  bool v3; // zf
  float r; // xmm3_4
  float g; // xmm4_4
  float b; // xmm5_4
  float a; // xmm7_4
  bool IsBBoxVisible; // cl
  float x; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float y; // xmm1_4
  float v13; // xmm1_4
  float z; // xmm1_4
  float v15; // xmm1_4
  float m_flCurrentLinearFloatLightAlpha; // xmm1_4
  float v17; // xmm1_4
  const Vector *v18; // eax
  __int64 v19; // xmm0_8
  const QAngle *LocalAngles; // edi
  C_BasePlayer *LocalPlayer; // eax
  C_BaseCombatWeapon *v22; // eax
  C_EnvProjectedTexture_vtbl *v23; // edx
  float *v24; // edi
  float *v25; // eax
  VectorAligned v26; // xmm0
  C_BaseCombatWeapon *v27; // eax
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  C_BaseCombatWeapon *v31; // eax
  C_EnvProjectedTexture_vtbl *v32; // edx
  float *v33; // edi
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  const QAngle *v37; // eax
  __m128i v38; // xmm0
  double v39; // xmm0_8
  float v40; // xmm2_4
  int i; // edi
  int j; // edi
  __m128 y_low; // xmm5
  __m128 x_low; // xmm6
  __m128 v45; // xmm7
  float *v46; // eax
  int k; // ecx
  __m128 v48; // xmm4
  double v49; // xmm0_8
  __m128 v50; // xmm3
  float v51; // xmm0_4
  __m128d v52; // xmm0
  __m128d v53; // xmm1
  float v54; // xmm2_4
  double v55; // xmm0_8
  double v56; // xmm1_8
  float v57; // xmm0_4
  __m128d v58; // xmm0
  __m128d v59; // xmm1
  __m128d v60; // xmm0
  __m128d v61; // xmm1
  double v62; // xmm0_8
  float v63; // xmm0_4
  float v64; // xmm0_4
  IClientShadowMgr_vtbl *v65; // edx
  float (__thiscall *LightStyleValue)(IVEngineClient *, int); // edx
  double v67; // st7
  double v68; // st7
  double v69; // st5
  float m_flBrightnessScale; // xmm1_4
  double v71; // st5
  bool m_bSimpleProjection; // al
  IMaterial *m_pMaterial; // edx
  int m_nSpotlightTextureFrame; // ecx
  float m_flProjectionSize; // xmm0_4
  int v76; // edx
  unsigned __int16 v77; // ax
  IClientShadowMgr_vtbl *v78; // eax
  const Vector *v79; // eax
  float v80; // xmm1_4
  float v81; // xmm2_4
  const Vector *v82; // eax
  float v83; // xmm1_4
  float v84; // xmm2_4
  void (__thiscall *SetFlashlightLightWorld)(IClientShadowMgr *, unsigned __int16, bool); // edx
  int m_LightHandle; // [esp-20h] [ebp-2E0h]
  int m_iStyle; // [esp-20h] [ebp-2E0h]
  _BYTE *v88; // [esp-10h] [ebp-2D0h]
  Vector v89; // [esp-Ch] [ebp-2CCh] BYREF
  _BYTE vOutRects_12[124]; // [esp+Ch] [ebp-2B4h] OVERLAPPED BYREF
  FlashlightState_t state; // [esp+88h] [ebp-238h] BYREF
  matrix3x4_t matOrientation; // [esp+188h] [ebp-138h] BYREF
  Vector vPlayerRight; // [esp+1B8h] [ebp-108h] BYREF
  Vector vPlayerUp; // [esp+1C4h] [ebp-FCh] BYREF
  VectorAligned vNearRect[4]; // [esp+1D0h] [ebp-F0h] BYREF
  VectorAligned vFarRect_4[4]; // [esp+214h] [ebp-ACh] OVERLAPPED
  Vector v97; // [esp+258h] [ebp-68h] BYREF
  Vector vUp; // [esp+264h] [ebp-5Ch] BYREF
  Vector vPlayerForward; // [esp+270h] [ebp-50h] BYREF
  QAngle playerAngles; // [esp+27Ch] [ebp-44h] BYREF
  Vector vRight; // [esp+288h] [ebp-38h] BYREF
  float flAlpha; // [esp+294h] [ebp-2Ch]
  Vector vForward; // [esp+298h] [ebp-28h] BYREF
  Vector mins; // [esp+2A4h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+2B0h] [ebp-10h]
  float retaddr; // [esp+2C0h] [ebp+0h]

  maxs.y = a2;
  maxs.z = retaddr;
  if ( !C_EnvProjectedTexture::ShouldUpdate(this) )
  {
    if ( this->m_bIsCurrentlyProjected )
      C_EnvProjectedTexture::ShutDownLightHandle(this);
    return;
  }
  v3 = !this->m_bAlwaysUpdate;
  r = (float)this->m_LightColor.r;
  g = (float)this->m_LightColor.g;
  b = (float)this->m_LightColor.b;
  a = (float)this->m_LightColor.a;
  IsBBoxVisible = true;
  maxs.x = a;
  if ( !v3 )
    this->m_bForceUpdate = true;
  if ( r != this->m_CurrentLinearFloatLightColor.x
    || g != this->m_CurrentLinearFloatLightColor.y
    || b != this->m_CurrentLinearFloatLightColor.z
    || this->m_flCurrentLinearFloatLightAlpha != a )
  {
    x = this->m_CurrentLinearFloatLightColor.x;
    v10 = (float)(this->m_flColorTransitionTime * *(float *)(gpGlobals.m_Index + 16)) * 255.0;
    if ( (float)(r - x) <= v10 )
    {
      a = maxs.x;
      if ( (float)-v10 <= (float)(r - x) )
        v11 = r;
      else
        v11 = x - v10;
    }
    else
    {
      v11 = x + v10;
    }
    this->m_CurrentLinearFloatLightColor.x = v11;
    y = this->m_CurrentLinearFloatLightColor.y;
    if ( (float)(g - y) <= v10 )
    {
      if ( (float)-v10 <= (float)(g - y) )
        v13 = g;
      else
        v13 = y - v10;
    }
    else
    {
      v13 = y + v10;
    }
    this->m_CurrentLinearFloatLightColor.y = v13;
    z = this->m_CurrentLinearFloatLightColor.z;
    if ( (float)(b - z) <= v10 )
    {
      if ( (float)-v10 <= (float)(b - z) )
        v15 = b;
      else
        v15 = z - v10;
    }
    else
    {
      v15 = z + v10;
    }
    this->m_CurrentLinearFloatLightColor.z = v15;
    m_flCurrentLinearFloatLightAlpha = this->m_flCurrentLinearFloatLightAlpha;
    if ( (float)(a - m_flCurrentLinearFloatLightAlpha) <= v10 )
    {
      if ( (float)-v10 <= (float)(a - m_flCurrentLinearFloatLightAlpha) )
        v17 = a;
      else
        v17 = m_flCurrentLinearFloatLightAlpha - v10;
    }
    else
    {
      v17 = m_flCurrentLinearFloatLightAlpha + v10;
    }
    this->m_flCurrentLinearFloatLightAlpha = v17;
    this->m_bForceUpdate = true;
  }
  if ( !this->m_bForceUpdate
    && r_flashlightenableculling.m_pParent != nullptr
    && r_flashlightenableculling.m_pParent->m_Value.m_nValue != 0 )
  {
    IsBBoxVisible = C_EnvProjectedTexture::IsBBoxVisible(this);
  }
  if ( !this->m_bState || !IsBBoxVisible )
  {
    if ( this->m_LightHandle == 0xFFFF )
    {
LABEL_101:
      this->m_bIsCurrentlyProjected = false;
      return;
    }
    v65 = g_pClientShadowMgr->__vftable;
    m_LightHandle = this->m_LightHandle;
    if ( this->m_bSimpleProjection )
    {
      ((void (__stdcall *)(int))v65->DestroyProjection)(a1: m_LightHandle);
      goto LABEL_100;
    }
LABEL_99:
    ((void (__stdcall *)(int))v65->DestroyFlashlight)(a1: m_LightHandle);
    goto LABEL_100;
  }
  if ( this->m_LightHandle == 0xFFFF
    || CHandle<C_BaseEntity>::operator!=(this: &this->m_hTargetEntity, val: nullptr)
    || this->m_bForceUpdate )
  {
    v18 = this->GetAbsOrigin(this);
    v19 = *(_QWORD *)&v18->x;
    vForward.z = v18->z;
    *(_QWORD *)&vForward.x = v19;
    FlashlightState_t::FlashlightState_t(this: (FlashlightState_t *)&vOutRects_12[112]);
    if ( CHandle<C_BaseEntity>::operator!=(this: &this->m_hTargetEntity, val: nullptr) )
    {
      if ( this->m_bCameraSpace )
      {
        LocalAngles = C_BaseEntity::GetLocalAngles(this);
        LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
        if ( LocalPlayer != nullptr )
        {
          vPlayerForward = (Vector)*LocalPlayer->GetAbsAngles(this: LocalPlayer);
          AngleVectors(
            angles: (const QAngle *)&vPlayerForward,
            forward: &vUp,
            right: (Vector *)&matOrientation.m_flMatVal[2][1],
            up: &vPlayerRight);
          AngleMatrix(angles: LocalAngles, matrix: (matrix3x4_t *)&state.m_nRight);
          VectorITransform(in1: &vUp.x, in2: (const matrix3x4_t *)&state.m_nRight, out: &vRight.y);
          VectorITransform(
            in1: &matOrientation.m_flMatVal[2][1],
            in2: (const matrix3x4_t *)&state.m_nRight,
            out: &playerAngles.x);
          VectorITransform(in1: &vPlayerRight.x, in2: (const matrix3x4_t *)&state.m_nRight, out: &v97.x);
          v22 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hTargetEntity);
          v23 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
          LODWORD(maxs.x) = v22;
          v24 = (float *)v23->GetAbsOrigin(this);
          v25 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(maxs.x) + 40))(a1: LODWORD(maxs.x));
          v26 = 0;
          v26.x = fsqrt(
                    (float)((float)((float)(v25[1] - v24[1]) * (float)(v25[1] - v24[1]))
                          + (float)((float)(v25[2] - v24[2]) * (float)(v25[2] - v24[2])))
                  + (float)((float)(*v25 - *v24) * (float)(*v25 - *v24)));
          vFarRect_4[3] = v26;
          v27 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hTargetEntity);
          mins.x = vRight.y * vFarRect_4[3].x;
          mins.y = vRight.z * vFarRect_4[3].x;
          mins.z = flAlpha * vFarRect_4[3].x;
          v28 = (float *)v27->GetAbsOrigin(this: v27);
          v29 = v28[1] - mins.y;
          v30 = v28[2] - mins.z;
          vForward.x = *v28 - mins.x;
          vForward.y = v29;
          vForward.z = v30;
          VectorNormalize(vec: (Vector *)&vRight.y);
          VectorNormalize(vec: (Vector *)&playerAngles);
          VectorNormalize(vec: &v97);
        }
      }
      else
      {
        v31 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_hTargetEntity);
        v32 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
        LODWORD(maxs.x) = v31;
        v33 = (float *)v32->GetAbsOrigin(this);
        v34 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(maxs.x) + 40))(a1: LODWORD(maxs.x));
        v35 = v34[1] - v33[1];
        v36 = v34[2] - v33[2];
        vRight.y = *v34 - *v33;
        vRight.z = v35;
        flAlpha = v36;
        VectorNormalize(vec: (Vector *)&vRight.y);
      }
    }
    else
    {
      v37 = this->GetAbsAngles(this);
      AngleVectors(angles: v37, forward: (Vector *)&vRight.y, right: (Vector *)&playerAngles, up: &v97);
    }
    state.m_quatOrientation.w = this->m_flLightFOV;
    state.m_NearZ = state.m_quatOrientation.w;
    *(Vector *)&vOutRects_12[112] = vForward;
    BasisToQuaternion(
      vecForward: (Vector *)&vRight.y,
      vecRight: (const Vector *)&playerAngles,
      vecUp: &v97,
      q: (Quaternion *)&state);
    maxs.x = this->m_flNearZ;
    state.m_quatOrientation.y = maxs.x;
    vRight.x = this->m_flFarZ;
    state.m_quatOrientation.z = vRight.x;
    if ( r_flashlightenableculling.m_pParent != nullptr && r_flashlightenableculling.m_pParent->m_Value.m_nValue != 0 )
    {
      v38 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_flLightFOV));
      *(double *)v38.m128i_i64 = *(double *)v38.m128i_i64 * 0.0174532925199433 * 0.5;
      __libm_sse2_tan(X: v38);
      v40 = v39;
      vNearRect[0].z = maxs.x * v40;
      vNearRect[1].z = maxs.x * v40;
      vNearRect[1].w = maxs.x * v40;
      vNearRect[2].w = maxs.x * v40;
      vNearRect[3].z = -(float)(vRight.x * v40);
      vNearRect[3].w = vNearRect[3].z;
      vFarRect_4[0].z = vNearRect[3].z;
      vFarRect_4[2].y = vNearRect[3].z;
      mins.x = -playerAngles.x;
      mins.y = -playerAngles.y;
      vPlayerUp.x = maxs.x;
      vPlayerUp.y = -(float)(maxs.x * v40);
      vPlayerUp.z = vPlayerUp.y;
      vNearRect[0].y = maxs.x;
      vNearRect[0].w = vPlayerUp.y;
      vNearRect[1].y = maxs.x;
      vNearRect[2].y = maxs.x;
      vNearRect[2].z = vPlayerUp.y;
      vNearRect[3].y = vRight.x;
      vFarRect_4[0].x = vRight.x;
      vFarRect_4[0].y = vRight.x * v40;
      vFarRect_4[1].x = vRight.x;
      vFarRect_4[1].y = vRight.x * v40;
      vFarRect_4[1].z = vRight.x * v40;
      vFarRect_4[2].x = vRight.x;
      vFarRect_4[2].z = vRight.x * v40;
      mins.z = -playerAngles.z;
      matrix3x4_t::matrix3x4_t(
        this: (matrix3x4_t *)&state.m_nRight,
        xAxis: (Vector *)&vRight.y,
        yAxis: &mins,
        zAxis: &v97,
        vecOrigin: &vForward);
      for ( i = 0; i < 64; i += 16 )
        VectorTransform(
          in1: (float *)((char *)&vPlayerUp.x + i),
          in2: (const matrix3x4_t *)&state.m_nRight,
          out: (float *)((char *)&v89.x + i));
      for ( j = 0; j < 64; j += 16 )
        VectorTransform(
          in1: (float *)((char *)&vNearRect[3].y + j),
          in2: (const matrix3x4_t *)&state.m_nRight,
          out: (float *)&vOutRects_12[j + 40]);
      mins = v89;
      y_low = (__m128)LODWORD(v89.y);
      x_low = (__m128)LODWORD(v89.x);
      vForward = v89;
      v45 = (__m128)LODWORD(v89.y);
      v46 = (float *)vOutRects_12;
      for ( k = 7; k != 0; --k )
      {
        v48 = (__m128)*((unsigned int *)v46 - 2);
        v49 = vForward.x;
        if ( vForward.x > (double)v48.m128_f32[0] )
          v49 = v48.m128_f32[0];
        v50 = (__m128)*((unsigned int *)v46 - 1);
        v51 = v49;
        vForward.x = v51;
        v52 = _mm_cvtps_pd(v45);
        v53 = _mm_cvtps_pd(v50);
        if ( v52.m128d_f64[0] > v53.m128d_f64[0] )
          v52 = v53;
        v54 = *v46;
        v45 = _mm_cvtpd_ps(v52);
        v55 = vForward.z;
        v56 = *v46;
        if ( vForward.z > v56 )
          v55 = v56;
        v57 = v55;
        vForward.z = v57;
        v58 = _mm_cvtps_pd(x_low);
        v59 = _mm_cvtps_pd(v48);
        if ( v58.m128d_f64[0] < v59.m128d_f64[0] )
          v58 = v59;
        x_low = _mm_cvtpd_ps(v58);
        v60 = _mm_cvtps_pd(y_low);
        v61 = _mm_cvtps_pd(v50);
        if ( v60.m128d_f64[0] < v61.m128d_f64[0] )
          v60 = v61;
        y_low = _mm_cvtpd_ps(v60);
        v62 = mins.z;
        if ( mins.z < (double)v54 )
          v62 = v54;
        v46 += 4;
        v63 = v62;
        mins.z = v63;
      }
      *(_QWORD *)&mins.x = __PAIR64__(y_low.m128_u32[0], x_low.m128_u32[0]);
      *(_QWORD *)&vUp.x = __PAIR64__(y_low.m128_u32[0], x_low.m128_u32[0]);
      LODWORD(vForward.y) = v45.m128_i32[0];
      vPlayerForward = vForward;
      v64 = mins.z - 1.0;
      vUp.z = mins.z;
      if ( C_EnvProjectedTexture::m_flVisibleBBoxMinHeight <= (float)(mins.z - 1.0) )
        v64 = C_EnvProjectedTexture::m_flVisibleBBoxMinHeight;
      if ( vForward.z <= v64 )
        vPlayerForward.z = v64;
      if ( engine->CullBox(this: engine, a2: &vPlayerForward, a3: &vUp) )
      {
        if ( this->m_LightHandle == 0xFFFF )
          return;
        v65 = g_pClientShadowMgr->__vftable;
        m_LightHandle = this->m_LightHandle;
        if ( this->m_bSimpleProjection )
        {
          ((void (__stdcall *)(int))v65->DestroyProjection)(a1: m_LightHandle);
LABEL_100:
          this->m_LightHandle = -1;
          goto LABEL_101;
        }
        goto LABEL_99;
      }
    }
    LightStyleValue = engine->LightStyleValue;
    m_iStyle = this->m_iStyle;
    vRight.x = this->m_flCurrentLinearFloatLightAlpha * 0.0039215689;
    v67 = ((double (__thiscall *)(IVEngineClient *, int))LightStyleValue)(a1: engine, a2: m_iStyle);
    v68 = v67 * vRight.x;
    v69 = this->m_CurrentLinearFloatLightColor.x * 0.0039215689;
    state.m_fOrthoTop = 100.0;
    state.m_fQuadraticAtten = this->m_flFarZ;
    m_flBrightnessScale = this->m_flBrightnessScale;
    state.m_fOrthoRight = 0.0;
    state.m_fLinearAtten = v69 * v68;
    state.m_fOrthoBottom = 0.0;
    v71 = this->m_CurrentLinearFloatLightColor.y;
    state.m_Color[1] = m_flBrightnessScale;
    state.m_Color[0] = 0.0;
    state.m_fConstantAtten = v71 * 0.0039215689 * v68;
    state.m_FarZAtten = v68 * (0.0039215689 * this->m_CurrentLinearFloatLightColor.z);
    *(float *)&state.m_bEnableShadows = g_pMaterialSystemHardwareConfig->GetShadowSlopeScaleDepthBias(this: g_pMaterialSystemHardwareConfig);
    state.m_flShadowMapResolution = g_pMaterialSystemHardwareConfig->GetShadowDepthBias(this: g_pMaterialSystemHardwareConfig);
    LOBYTE(state.m_pSpotlightTexture) = this->m_bEnableShadows;
    m_bSimpleProjection = this->m_bSimpleProjection;
    state.m_pProjectedMaterial = (IMaterial *)LODWORD(r_flashlightdepthres.m_pParent->m_Value.m_fValue);
    if ( m_bSimpleProjection )
    {
      m_pMaterial = this->m_ProjectedMaterial.m_pMaterial;
      state.m_Color[2] = 0.0;
      LODWORD(state.m_Color[3]) = m_pMaterial;
    }
    else
    {
      LODWORD(state.m_Color[2]) = this->m_SpotlightTexture.m_pTexture;
      state.m_Color[3] = 0.0;
    }
    m_nSpotlightTextureFrame = this->m_nSpotlightTextureFrame;
    m_flProjectionSize = this->m_flProjectionSize;
    LODWORD(state.m_flShadowJitterSeed) = this->m_nShadowQuality;
    v76 = this->m_LightHandle;
    LODWORD(state.m_fBrightnessScale) = m_nSpotlightTextureFrame;
    state.m_flAmbientOcclusion = m_flProjectionSize;
    state.m_nShadowQuality = LODWORD(this->m_flRotation);
    LOBYTE(state.m_nNumPlanes) = 1;
    if ( (_WORD)v76 == 0xFFFF )
    {
      if ( m_bSimpleProjection )
        v77 = g_pClientShadowMgr->CreateProjection(
                this: g_pClientShadowMgr,
                a2: (const FlashlightState_t *)&vOutRects_12[112]);
      else
        v77 = g_pClientShadowMgr->CreateFlashlight(
                this: g_pClientShadowMgr,
                a2: (const FlashlightState_t *)&vOutRects_12[112]);
      this->m_LightHandle = v77;
      if ( v77 == 0xFFFF )
        goto LABEL_87;
    }
    else
    {
      v88 = &vOutRects_12[112];
      v3 = m_bSimpleProjection;
      v78 = g_pClientShadowMgr->__vftable;
      if ( v3 )
        ((void (__stdcall *)(int))v78->UpdateProjectionState)(a1: v76);
      else
        ((void (__stdcall *)(int))v78->UpdateFlashlightState)(a1: v76);
    }
    this->m_bForceUpdate = false;
LABEL_87:
    ((void (__cdecl *)(_DWORD, Vector *, Vector *, _BYTE *))g_pClientShadowMgr->GetFrustumExtents)(
      a1: this->m_LightHandle,
      a2: &this->m_vecExtentsMin,
      a3: &this->m_vecExtentsMax,
      a4: v88);
    v79 = this->GetAbsOrigin(this);
    v80 = this->m_vecExtentsMin.y - v79->y;
    v81 = this->m_vecExtentsMin.z - v79->z;
    this->m_vecExtentsMin.x = this->m_vecExtentsMin.x - v79->x;
    this->m_vecExtentsMin.y = v80;
    this->m_vecExtentsMin.z = v81;
    v82 = this->GetAbsOrigin(this);
    v83 = this->m_vecExtentsMax.y - v82->y;
    v84 = this->m_vecExtentsMax.z - v82->z;
    this->m_vecExtentsMax.x = this->m_vecExtentsMax.x - v82->x;
    this->m_vecExtentsMax.y = v83;
    this->m_vecExtentsMax.z = v84;
  }
  if ( this->m_bLightOnlyTarget )
    ((void (__cdecl *)(_DWORD, unsigned int))g_pClientShadowMgr->SetFlashlightTarget)(
      a1: this->m_LightHandle,
      a2: this->m_hTargetEntity.m_Index);
  else
    ((void (__cdecl *)(_DWORD, int))g_pClientShadowMgr->SetFlashlightTarget)(a1: this->m_LightHandle, a2: -1);
  SetFlashlightLightWorld = g_pClientShadowMgr->SetFlashlightLightWorld;
  LODWORD(maxs.x) = this->m_bLightWorld;
  ((void (__stdcall *)(_DWORD))SetFlashlightLightWorld)(a1: this->m_LightHandle);
  if ( (asw_perf_wtf.m_pParent == nullptr || asw_perf_wtf.m_pParent->m_Value.m_nValue == 0) && !this->m_bForceUpdate )
    g_pClientShadowMgr->UpdateProjectedTexture(this: g_pClientShadowMgr, a2: this->m_LightHandle, a3: true);
  this->m_bIsCurrentlyProjected = true;
}

//------------------------------------------------------------------------------
// Address: 0x100699C0
// Name: public: virtual bool C_EnvProjectedTexture::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall C_EnvProjectedTexture::Simulate@<al>(C_EnvProjectedTexture *this@<ecx>, float a2@<ebp>)
{
  C_EnvProjectedTexture::UpdateLight(this, a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100699D0
// Name: public: virtual void C_EnvProjectedTexture::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvProjectedTexture::OnDataChanged(C_EnvProjectedTexture *this, DataUpdateType_t updateType)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( updateType == DATA_UPDATE_CREATED )
  {
    CTextureReference::Init(
      this: (CTextureReference *)&this->m_SpotlightTextureName[252],
      pTextureName: (const char *)&this->m_flNearZ,
      pTextureGroupName: "Other textures",
      bComplain: true,
      nAdditionalCreationFlags: 0);
    CMaterialReference::Init(
      this: (CMaterialReference *)&this->m_SpotlightTextureName[256],
      pMaterialName: (const char *)&this->m_flNearZ,
      pTextureGroupName: "Other textures",
      bComplain: true);
  }
  *(&this->m_bIsBlurred + 2) = true;
  C_EnvProjectedTexture::UpdateLight(this: (C_EnvProjectedTexture *)((char *)this - 8), a2: COERCE_FLOAT(&savedregs));
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10411D30
// Name: DT_EnvProjectedTexture::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvProjectedTexture::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvProjectedTexture::g_RecvTable);
  return atexit(func: DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411D50
// Name: DT_EnvProjectedTexture::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvProjectedTexture::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvProjectedTexture::ignored>();
  DT_EnvProjectedTexture::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430220
// Name: DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvProjectedTexture::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvProjectedTexture::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10068C60
// Name: _C_EnvProjectedTexture_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvProjectedTexture_CreateObject(int entnum, int serialNum)
{
  C_EnvProjectedTexture *v2; // eax
  C_EnvProjectedTexture *v3; // eax
  C_EnvProjectedTexture *v4; // esi

  v2 = (C_EnvProjectedTexture *)C_BaseEntity::operator new(stAllocateBlock: 0xB00u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EnvProjectedTexture::C_EnvProjectedTexture(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411D60
// Name: _dynamic_initializer_for__asw_perf_wtf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__asw_perf_wtf__()
{
  ConVar::ConVar(
    this: &asw_perf_wtf,
    pName: "asw_perf_wtf",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Disable updating of projected shadow textures from UpdateLight");
  return atexit(func: dynamic_atexit_destructor_for__asw_perf_wtf__);
}

//------------------------------------------------------------------------------
// Address: 0x10411D90
// Name: _dynamic_initializer_for____g_C_EnvScreenOverlayClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvScreenOverlayClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvScreenOverlayClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvScreenOverlayClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430230
// Name: _dynamic_atexit_destructor_for__asw_perf_wtf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__asw_perf_wtf__()
{
  ConVar::~ConVar(this: &asw_perf_wtf);
}
