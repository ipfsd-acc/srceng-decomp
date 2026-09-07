// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_particle_smokegrenade.cpp
// Functions: 24
// ============================================================

#include "game\client\c_particle_smokegrenade.h"

//------------------------------------------------------------------------------
// Address: 0x10246D30
// Name: public: virtual class ClientClass __near * C_ParticleSmokeGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ParticleSmokeGrenade::GetClientClass(C_ParticleSmokeGrenade *this)
{
  return &__g_C_ParticleSmokeGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10246D40
// Name: public: virtual C_ParticleSmokeGrenade::~C_ParticleSmokeGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::~C_ParticleSmokeGrenade(C_ParticleSmokeGrenade *this)
{
  CParticleMgr *v2; // eax
  CParticleEffectBinding *p_m_ParticleEffect; // [esp-4h] [ebp-8h]

  p_m_ParticleEffect = &this->m_ParticleEffect;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleSmokeGrenade_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleSmokeGrenade::`vftable';
  v2 = ParticleMgr();
  CParticleMgr::RemoveEffect(this: v2, pEffect: p_m_ParticleEffect);
  C_SmokeTrail::~C_SmokeTrail(this: &this->m_SmokeTrail);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10246DD0
// Name: public: int C_BaseParticleEntity::AllocateToolParticleEffectId(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseParticleEntity::AllocateToolParticleEffectId(C_BaseParticleEntity *this)
{
  CParticleMgr *v2; // ecx
  int result; // eax

  v2 = ParticleMgr();
  result = v2->m_nToolParticleEffectId;
  v2->m_nToolParticleEffectId = result + 1;
  this->m_nToolParticleEffectId = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10246E30
// Name: public: virtual void C_ParticleSmokeGrenade::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::ClientThink(C_ParticleSmokeGrenade *this)
{
  const Vector *v2; // eax
  float v3; // xmm1_4
  int m_zCount; // xmm0_4
  float v5; // xmm1_4
  float m_flSpawnTime; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // [esp-10h] [ebp-1Ch]

  if ( this->m_bSimulate )
  {
    v2 = MainViewOrigin(nSlot: 0);
    v3 = v2->y - *(float *)&this->IPrototypeAppEffect::__vftable;
    v9 = fsqrt(
           (float)((float)(v3 * v3)
                 + (float)((float)(v2->z - *(float *)&this->m_CurrentStage)
                         * (float)(v2->z - *(float *)&this->m_CurrentStage)))
         + (float)((float)(v2->x - *((float *)&this->m_bSimulate + 1))
                 * (float)(v2->x - *((float *)&this->m_bSimulate + 1))));
    m_zCount = this->m_zCount;
    v5 = *(float *)&m_zCount * 0.15;
    if ( *(float *)&m_zCount > v9 )
    {
      if ( v5 <= v9 )
        m_flSpawnTime = (float)(1.0 - (float)((float)(v9 - v5) / (float)(*(float *)&m_zCount - v5)))
                      * this->m_flSpawnTime;
      else
        m_flSpawnTime = this->m_flSpawnTime;
      g_SmokeFogOverlayAlpha = g_SmokeFogOverlayAlpha + m_flSpawnTime;
      v7 = (float)((float)(this->m_MinColor.y * 0.5) * m_flSpawnTime) + g_SmokeFogOverlayColor.y;
      v8 = (float)((float)(this->m_MinColor.z * 0.5) * m_flSpawnTime) + g_SmokeFogOverlayColor.z;
      g_SmokeFogOverlayColor.x = g_SmokeFogOverlayColor.x + (float)((float)(this->m_MinColor.x * 0.5) * m_flSpawnTime);
      g_SmokeFogOverlayColor.y = v7;
      g_SmokeFogOverlayColor.z = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246F90
// Name: private: void C_ParticleSmokeGrenade::UpdateSmokeTrail(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::UpdateSmokeTrail(C_ParticleSmokeGrenade *this, float fTimeDelta)
{
  C_BaseEntity *FollowedEntity; // edi
  const Vector *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  const QAngle *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  const Vector *v10; // eax
  Vector right; // [esp+18h] [ebp-30h] BYREF
  Vector up; // [esp+24h] [ebp-24h] BYREF
  Vector forward; // [esp+30h] [ebp-18h] BYREF
  float v14[3]; // [esp+3Ch] [ebp-Ch] BYREF

  FollowedEntity = C_BaseEntity::GetFollowedEntity(this);
  if ( FollowedEntity != nullptr )
  {
    if ( this->m_CurrentStage == 0 )
    {
      v4 = this->GetAbsOrigin(this);
      engine->GetLightForPoint(this: engine, result: (Vector *)v14, a3: v4, a4: true);
      v5 = v14[1];
      v6 = v14[2];
      this->m_SmokeTrail.m_StartColor.x = v14[0] * 0.5;
      this->m_SmokeTrail.m_StartColor.y = v5 * 0.5;
      this->m_SmokeTrail.m_StartColor.z = v6 * 0.5;
      this->m_SmokeTrail.m_EndColor.x = this->m_SmokeTrail.m_StartColor.x;
      this->m_SmokeTrail.m_EndColor.y = this->m_SmokeTrail.m_StartColor.y;
      this->m_SmokeTrail.m_EndColor.z = this->m_SmokeTrail.m_StartColor.z;
    }
    v7 = FollowedEntity->GetAbsAngles(this: FollowedEntity);
    AngleVectors(angles: v7, &forward, &right, &up);
    C_BaseEntity::CalcAbsoluteVelocity(this);
    v8 = this->m_vecAbsVelocity.y + (float)(forward.y * 30.0);
    v9 = this->m_vecAbsVelocity.z + (float)(forward.z * 30.0);
    this->m_SmokeTrail.m_VelocityOffset.x = this->m_vecAbsVelocity.x + (float)(forward.x * 30.0);
    this->m_SmokeTrail.m_VelocityOffset.y = v8;
    this->m_SmokeTrail.m_VelocityOffset.z = v9;
    v10 = this->GetAbsOrigin(this);
    C_BaseEntity::SetLocalOrigin(this: &this->m_SmokeTrail, origin: v10);
    ((void (__stdcall *)(_DWORD))this->m_SmokeTrail.Update)(a1: LODWORD(fTimeDelta));
  }
}

//------------------------------------------------------------------------------
// Address: 0x102470F0
// Name: private: void C_ParticleSmokeGrenade::UpdateParticleDuringTrade(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::UpdateParticleDuringTrade(
        C_ParticleSmokeGrenade *this,
        int iParticle,
        float fTimeDelta)
{
  C_ParticleSmokeGrenade::SmokeParticleInfo *v3; // esi
  C_ParticleSmokeGrenade::SmokeParticleInfo *v4; // edi
  __m128 m_TradeClock_low; // xmm1
  int v6; // ebx
  int v7; // eax
  float m_SpacingRadius; // xmm0_4
  float z; // xmm7_4
  int v10; // ebx
  __int64 v11; // rax
  int m_yCount; // ebx
  float v13; // xmm2_4
  float x; // xmm6_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float m_TradeDuration; // xmm0_4
  float v19; // xmm2_4
  float *v20; // eax
  float *v21; // eax
  C_ParticleSmokeGrenade::SmokeGrenadeParticle *v22; // eax
  double v23; // xmm0_8
  C_ParticleSmokeGrenade::SmokeGrenadeParticle *m_pParticle; // eax
  C_ParticleSmokeGrenade::SmokeGrenadeParticle *v25; // eax
  float *v26; // esi
  float *v27; // edi
  float myPos; // [esp+14h] [ebp-24h]
  float myPos_4; // [esp+18h] [ebp-20h]
  float myPos_8; // [esp+1Ch] [ebp-1Ch]
  float v31; // [esp+20h] [ebp-18h]
  int v32; // [esp+24h] [ebp-14h]
  int otherZ; // [esp+28h] [ebp-10h]
  float y; // [esp+2Ch] [ebp-Ch]
  int v35; // [esp+30h] [ebp-8h]
  float v36; // [esp+30h] [ebp-8h]
  int iParticlea; // [esp+40h] [ebp+8h]

  v3 = &this->m_SmokeParticleInfos[iParticle];
  v4 = &this->m_SmokeParticleInfos[this->m_SmokeParticleInfos[iParticle].m_TradeIndex];
  if ( v3 < v4 )
  {
    m_TradeClock_low = (__m128)LODWORD(this->m_SmokeParticleInfos[this->m_SmokeParticleInfos[iParticle].m_TradeIndex].m_TradeClock);
    m_TradeClock_low.m128_f32[0] = m_TradeClock_low.m128_f32[0] + fTimeDelta;
    LODWORD(this->m_SmokeParticleInfos[this->m_SmokeParticleInfos[iParticle].m_TradeIndex].m_TradeClock) = m_TradeClock_low.m128_i32[0];
    LODWORD(this->m_SmokeParticleInfos[iParticle].m_TradeClock) = m_TradeClock_low.m128_i32[0];
    v6 = this->m_yCount * this->m_xCount;
    v7 = iParticle / v6;
    v32 = v6;
    m_SpacingRadius = this->m_SpacingRadius;
    z = this->m_SmokeBasePos.z;
    v10 = iParticle / v6 * v6;
    otherZ = v7;
    v11 = iParticle - v10;
    v35 = v10;
    m_yCount = this->m_yCount;
    LODWORD(v11) = v11 / m_yCount;
    v31 = (float)(this->m_xCount - 1);
    v13 = (float)(iParticle - v11 * m_yCount - v35);
    iParticlea = this->m_SmokeParticleInfos[iParticle].m_TradeIndex;
    v36 = (float)(m_yCount - 1);
    y = (float)(this->m_zCount - 1);
    x = this->m_SmokeBasePos.x;
    myPos = (float)((float)((float)((float)((float)(v13 / v31) * m_SpacingRadius) * 2.0) - m_SpacingRadius) + x) - x;
    myPos_4 = (float)((float)((float)((float)((float)((float)(int)v11 / v36) * m_SpacingRadius) * 2.0) - m_SpacingRadius)
                    + this->m_SmokeBasePos.y)
            - this->m_SmokeBasePos.y;
    myPos_8 = (float)((float)((float)((float)((float)((float)otherZ / y) * m_SpacingRadius) * 2.0) - m_SpacingRadius) + z)
            - z;
    LODWORD(v11) = iParticlea % v32 / m_yCount;
    v15 = (float)((float)((float)((float)((float)((float)(iParticlea / v32) / y) * m_SpacingRadius) * 2.0)
                        - m_SpacingRadius)
                + z)
        - z;
    v16 = (float)((float)((float)((float)(iParticlea - v11 * m_yCount - iParticlea / v32 * v32) / v31) * m_SpacingRadius)
                * 2.0)
        - m_SpacingRadius;
    v17 = (float)((float)((float)((float)((float)((float)(int)v11 / v36) * m_SpacingRadius) * 2.0) - m_SpacingRadius)
                + this->m_SmokeBasePos.y)
        - this->m_SmokeBasePos.y;
    m_TradeDuration = v3->m_TradeDuration;
    v19 = (float)(v16 + x) - x;
    if ( m_TradeClock_low.m128_f32[0] < m_TradeDuration )
    {
      m_TradeClock_low.m128_f32[0] = (float)((float)(m_TradeClock_low.m128_f32[0] * 2.0) * 1.5707964) / m_TradeDuration;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_TradeClock_low));
      *(float *)&v23 = v23;
      *(float *)&v23 = (float)(*(float *)&v23 + 1.0) * 0.5;
      v3->m_pParticle->m_FadeAlpha = (float)((float)(v4->m_FadeAlpha - v3->m_FadeAlpha) * (float)(1.0 - *(float *)&v23))
                                   + v3->m_FadeAlpha;
      v4->m_pParticle->m_FadeAlpha = (float)((float)(v4->m_FadeAlpha - v3->m_FadeAlpha) * *(float *)&v23)
                                   + v3->m_FadeAlpha;
      m_pParticle = v3->m_pParticle;
      m_pParticle->m_Color[0] = (int)(float)((float)((float)(v4->m_Color[0] - v3->m_Color[0])
                                                   * (float)(1.0 - *(float *)&v23))
                                           + (float)v3->m_Color[0]);
      m_pParticle->m_Color[1] = (int)(float)((float)((float)(v4->m_Color[1] - v3->m_Color[1])
                                                   * (float)(1.0 - *(float *)&v23))
                                           + (float)v3->m_Color[1]);
      m_pParticle->m_Color[2] = (int)(float)((float)((float)(v4->m_Color[2] - v3->m_Color[2])
                                                   * (float)(1.0 - *(float *)&v23))
                                           + (float)v3->m_Color[2]);
      v25 = v4->m_pParticle;
      v25->m_Color[0] = (int)(float)((float)((float)(v4->m_Color[0] - v3->m_Color[0]) * *(float *)&v23)
                                   + (float)v3->m_Color[0]);
      v25->m_Color[1] = (int)(float)((float)((float)(v4->m_Color[1] - v3->m_Color[1]) * *(float *)&v23)
                                   + (float)v3->m_Color[1]);
      v25->m_Color[2] = (int)(float)((float)((float)(v4->m_Color[2] - v3->m_Color[2]) * *(float *)&v23)
                                   + (float)v3->m_Color[2]);
      v26 = (float *)v3->m_pParticle;
      v26[3] = (float)((float)(v19 - myPos) * (float)(1.0 - *(float *)&v23)) + myPos;
      v26[4] = (float)((float)(v17 - myPos_4) * (float)(1.0 - *(float *)&v23)) + myPos_4;
      v26[5] = (float)((float)(v15 - myPos_8) * (float)(1.0 - *(float *)&v23)) + myPos_8;
      v27 = (float *)v4->m_pParticle;
      v27[3] = (float)((float)(v19 - myPos) * *(float *)&v23) + myPos;
      v27[4] = (float)((float)(v17 - myPos_4) * *(float *)&v23) + myPos_4;
      v27[5] = (float)((float)(v15 - myPos_8) * *(float *)&v23) + myPos_8;
    }
    else
    {
      v4->m_TradeIndex = -1;
      v3->m_TradeIndex = -1;
      v20 = (float *)v3->m_pParticle;
      v20[3] = v19;
      v20[4] = v17;
      v20[5] = v15;
      v21 = (float *)v4->m_pParticle;
      v21[3] = myPos;
      v21[4] = myPos_4;
      v21[5] = myPos_8;
      v22 = v3->m_pParticle;
      v3->m_pParticle = v4->m_pParticle;
      v4->m_pParticle = v22;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247510
// Name: private: void C_ParticleSmokeGrenade::UpdateParticleAndFindTrade(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::UpdateParticleAndFindTrade(
        C_ParticleSmokeGrenade *this,
        int iParticle,
        float fTimeDelta)
{
  C_ParticleSmokeGrenade::SmokeParticleInfo *v4; // eax
  int m_yCount; // esi
  int v6; // ecx
  int v7; // eax
  IUniformRandomStream *v8; // ecx
  int v9; // ebx
  IUniformRandomStream *v10; // ecx
  IUniformRandomStream *v11; // ecx
  int v12; // esi
  int v13; // ebx
  int v14; // ecx
  int m_xCount; // eax
  bool v16; // zf
  C_ParticleSmokeGrenade::SmokeParticleInfo *v17; // eax
  C_ParticleSmokeGrenade::SmokeParticleInfo *pInfo; // [esp+Ch] [ebp-2Ch]
  int z; // [esp+10h] [ebp-28h]
  int zCountOffset; // [esp+14h] [ebp-24h]
  int yCountOffset; // [esp+18h] [ebp-20h]
  int xCountOffset; // [esp+1Ch] [ebp-1Ch]
  int y; // [esp+20h] [ebp-18h]
  int xCount; // [esp+24h] [ebp-14h]
  int x; // [esp+28h] [ebp-10h]
  int yCount; // [esp+2Ch] [ebp-Ch]
  int zCount; // [esp+30h] [ebp-8h]
  bool bFound; // [esp+37h] [ebp-1h]

  v4 = &this->m_SmokeParticleInfos[iParticle];
  v4->m_pParticle->m_FadeAlpha = this->m_SmokeParticleInfos[iParticle].m_FadeAlpha;
  v4->m_pParticle->m_Color[0] = v4->m_Color[0];
  v4->m_pParticle->m_Color[1] = v4->m_Color[1];
  pInfo = v4;
  v4->m_pParticle->m_Color[2] = v4->m_Color[2];
  m_yCount = this->m_yCount;
  v6 = m_yCount * this->m_xCount;
  v7 = iParticle / v6;
  v8 = (IUniformRandomStream *)(iParticle / v6 * v6);
  z = v7;
  v9 = iParticle - (iParticle - (int)v8) / m_yCount * m_yCount - (_DWORD)v8;
  y = (iParticle - (int)v8) / m_yCount;
  x = v9;
  xCountOffset = _RandomInt(this: v8, a2: 0, a3: 0x7FFF);
  yCountOffset = _RandomInt(this: v10, a2: 0, a3: 0x7FFF);
  zCountOffset = _RandomInt(this: v11, a2: 0, a3: 0x7FFF);
  bFound = false;
  for ( xCount = 0; xCount < 3; ++xCount )
  {
    if ( bFound )
      break;
    for ( yCount = 0; yCount < 3; ++yCount )
    {
      if ( bFound )
        break;
      zCount = 0;
      v12 = v9 + g_OffsetLookup[(xCount + xCountOffset) % 3];
      v13 = y + g_OffsetLookup[(yCountOffset + yCount) % 3];
      while ( 1 )
      {
        v14 = z + g_OffsetLookup[(zCount + zCountOffset) % 3];
        if ( (v12 != x || v13 != y || v14 != z) && v12 >= 0 && v13 >= 0 && v14 >= 0 )
        {
          m_xCount = this->m_xCount;
          if ( v12 < m_xCount && v13 < this->m_yCount && v14 < this->m_zCount )
          {
            v16 = this->m_SmokeParticleInfos[v12 + this->m_yCount * (v13 + v14 * m_xCount)].m_pParticle == nullptr;
            v17 = &this->m_SmokeParticleInfos[v12 + this->m_yCount * (v13 + v14 * m_xCount)];
            if ( !v16 && v17->m_TradeIndex == -1 )
              break;
          }
        }
        if ( ++zCount >= 3 )
          goto LABEL_20;
      }
      pInfo->m_TradeIndex = v12 + this->m_yCount * (v13 + v14 * this->m_xCount);
      v17->m_TradeClock = 0.0;
      v17->m_TradeIndex = iParticle;
      pInfo->m_TradeClock = 0.0;
      pInfo->m_TradeDuration = _RandomFloat(this: (IUniformRandomStream *)iParticle, a2: 5.0, a3: 10.0);
      bFound = true;
LABEL_20:
      v9 = x;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247720
// Name: private: void C_ParticleSmokeGrenade::UpdateDynamicLightList(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::UpdateDynamicLightList(
        C_ParticleSmokeGrenade *this,
        const Vector *vMins,
        const Vector *vMaxs)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  dlight_t *v7; // edi
  float radius; // xmm0_4
  C_ParticleSmokeGrenade::CActiveLight *v9; // esi
  dlight_t *lights[32]; // [esp+4h] [ebp-88h] BYREF
  int nLights; // [esp+84h] [ebp-8h]
  int i; // [esp+88h] [ebp-4h]

  v4 = effects->CL_GetActiveDLights(this: effects, a2: lights);
  v5 = 0;
  v6 = v4;
  nLights = v4;
  this->m_nActiveLights = 0;
  for ( i = 0; v5 < v6; i = v5 )
  {
    v7 = lights[v5];
    radius = v7->radius;
    if ( vMins->x < (float)(v7->origin.x + radius)
      && vMins->y < (float)(v7->origin.y + radius)
      && vMins->z < (float)(v7->origin.z + radius)
      && (float)(v7->origin.x - radius) < vMaxs->x
      && (float)(v7->origin.y - radius) < vMaxs->y
      && (float)(v7->origin.z - radius) < vMaxs->z )
    {
      v9 = &this->m_ActiveLights[this->m_nActiveLights];
      if ( (v7->color.r != 0 || v7->color.g != 0 || v7->color.b != 0) && v7->color.exponent != 0 )
      {
        ColorRGBExp32ToVector(in: &v7->color, out: &this->m_ActiveLights[this->m_nActiveLights].m_vColor);
        v5 = i;
        v6 = nLights;
        v9->m_vColor.x = v9->m_vColor.x * 0.0039215689;
        v9->m_vColor.y = v9->m_vColor.y * 0.0039215689;
        v9->m_vColor.z = v9->m_vColor.z * 0.0039215689;
        v9->m_flRadiusSqr = (float)(v7->radius + 55.0) * (float)(v7->radius + 55.0);
        v9->m_vOrigin.x = v7->origin.x;
        v9->m_vOrigin.y = v7->origin.y;
        v9->m_vOrigin.z = v7->origin.z;
        ++this->m_nActiveLights;
      }
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102478A0
// Name: private: void C_ParticleSmokeGrenade::ApplyDynamicLight(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::ApplyDynamicLight(
        C_ParticleSmokeGrenade *this,
        const Vector *vParticlePos,
        Vector *color)
{
  int m_nActiveLights; // eax
  int v4; // esi
  float *p_z; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v15; // xmm3_4
  float x; // xmm3_4

  m_nActiveLights = this->m_nActiveLights;
  if ( m_nActiveLights != 0 )
  {
    v4 = 0;
    if ( m_nActiveLights > 0 )
    {
      p_z = &this->m_ActiveLights[0].m_vOrigin.z;
      do
      {
        v6 = vParticlePos->y - *(p_z - 1);
        v7 = (float)((float)(vParticlePos->x - *(p_z - 2)) * (float)(vParticlePos->x - *(p_z - 2))) + (float)(v6 * v6);
        v8 = p_z[1];
        v9 = v7 + (float)((float)(vParticlePos->z - *p_z) * (float)(vParticlePos->z - *p_z));
        if ( v8 > v9 )
        {
          v10 = *(p_z - 4);
          v11 = 1.0 - (float)(v9 / v8);
          v12 = *(p_z - 3) * v11;
          color->x = color->x + (float)((float)(*(p_z - 5) * v11) * 0.1);
          color->y = color->y + (float)((float)(v10 * v11) * 0.1);
          color->z = color->z + (float)(v12 * 0.1);
        }
        ++v4;
        p_z += 7;
      }
      while ( v4 < this->m_nActiveLights );
    }
    y = color->y;
    z = color->z;
    if ( y <= z )
      v15 = color->z;
    else
      v15 = color->y;
    if ( color->x <= v15 )
    {
      if ( y <= z )
        x = color->z;
      else
        x = color->y;
    }
    else
    {
      x = color->x;
    }
    if ( x > 1.0 )
    {
      color->x = color->x * (float)(1.0 / x);
      color->y = y * (float)(1.0 / x);
      color->z = z * (float)(1.0 / x);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102479E0
// Name: public: virtual void C_ParticleSmokeGrenade::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::SimulateParticles(
        C_ParticleSmokeGrenade *this,
        CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // edx
  Particle *m_pNext; // ecx

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  while ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    *(float *)&m_pNext[1].m_pNext = (float)(*(float *)&m_pNext[1].m_pPrev * pIterator->m_flTimeDelta)
                                  + *(float *)&m_pNext[1].m_pNext;
    m_pNext = pIterator->m_pNextParticle;
    m_pMaterial = pIterator->m_pMaterial;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247A20
// Name: public: virtual void C_ParticleSmokeGrenade::GetParticlePosition(struct Particle __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::GetParticlePosition(
        C_ParticleSmokeGrenade *this,
        Particle *pParticle,
        Vector *worldpos)
{
  float v3; // xmm1_4
  float v4; // xmm2_4

  v3 = this->m_SmokeBasePos.y + pParticle->m_Pos.y;
  v4 = this->m_SmokeBasePos.z + pParticle->m_Pos.z;
  worldpos->x = this->m_SmokeBasePos.x + pParticle->m_Pos.x;
  worldpos->y = v3;
  worldpos->z = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10247A70
// Name: private: void C_ParticleSmokeGrenade::FillVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::FillVolume(C_ParticleSmokeGrenade *this)
{
  int (*GetAbsOrigin)(void); // edx
  int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  C_ParticleSmokeGrenade::SmokeParticleInfo *v7; // ebx
  Particle *v8; // eax
  IUniformRandomStream *v9; // ecx
  C_ParticleSmokeGrenade::SmokeGrenadeParticle *v10; // edi
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // eax
  IUniformRandomStream *v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  Vector vColor; // [esp+20h] [ebp-24h] BYREF
  Vector vPos; // [esp+2Ch] [ebp-18h] BYREF
  int z; // [esp+38h] [ebp-Ch]
  int x; // [esp+3Ch] [ebp-8h]
  int y; // [esp+40h] [ebp-4h]

  GetAbsOrigin = (int (*)(void))this->GetAbsOrigin;
  this->m_CurrentStage = 1;
  this->m_SmokeBasePos = *(Vector *)GetAbsOrigin();
  C_SmokeTrail::SetEmit(this: &this->m_SmokeTrail, bEmit: false);
  this->m_zCount = 6;
  this->m_yCount = 6;
  this->m_xCount = 6;
  this->m_ExpandRadius = 0.0;
  this->m_ExpandTimeCounter = 0.0;
  v3 = 0;
  this->m_bVolumeFilled = true;
  this->m_SpacingRadius = 165.0;
  x = 0;
  do
  {
    v4 = 0;
    vPos.x = (float)((float)((float)((float)((float)v3 * 0.2) * this->m_SpacingRadius) * 2.0) + this->m_SmokeBasePos.x)
           - this->m_SpacingRadius;
    y = 0;
    if ( this->m_yCount > 0 )
    {
      do
      {
        v5 = 0;
        vPos.y = (float)((float)((float)((float)((float)v4 * 0.2) * this->m_SpacingRadius) * 2.0)
                       + this->m_SmokeBasePos.y)
               - this->m_SpacingRadius;
        for ( z = 0; v5 < this->m_zCount; z = v5 )
        {
          vPos.z = (float)((float)((float)((float)((float)v5 * 0.2) * this->m_SpacingRadius) * 2.0)
                         + this->m_SmokeBasePos.z)
                 - this->m_SpacingRadius;
          if ( (enginetrace->GetPointContents(this: enginetrace, a2: &vPos, a3: -1, a4: nullptr) & 1) == 0 )
          {
            v6 = x + this->m_yCount * (v4 + v5 * this->m_xCount);
            v7 = &this->m_SmokeParticleInfos[v6];
            if ( (C_ParticleSmokeGrenade *)((char *)this + 24 * v6) != (C_ParticleSmokeGrenade *)-3632 )
            {
              rand(this: (IUniformRandomStream *)(3 * v6));
              v8 = CParticleEffectBinding::AddParticle(
                     this: &this->m_ParticleEffect,
                     a2: (int)this,
                     sizeInBytes: 44,
                     hMaterial: this->m_MaterialHandles[0]);
              v10 = (C_ParticleSmokeGrenade::SmokeGrenadeParticle *)v8;
              if ( v8 != nullptr )
              {
                v11 = vPos.y - this->m_SmokeBasePos.y;
                v12 = vPos.z - this->m_SmokeBasePos.z;
                v8->m_Pos.x = vPos.x - this->m_SmokeBasePos.x;
                v8->m_Pos.y = v11;
                v8->m_Pos.z = v12;
                v13 = rand(this: v9);
                v10->m_ColorInterp = 255 * v13 / 0x7FFF;
                v10->m_RotationSpeed = _RandomFloat(
                                         this: (IUniformRandomStream *)(255 * v13),
                                         a2: -0.60000002,
                                         a3: 0.60000002);
                v10->m_CurRotation = _RandomFloat(this: v14, a2: -6.0, a3: 6.0);
              }
              engine->GetLightForPoint(this: engine, result: &vColor, a3: &vPos, a4: true);
              v15 = (int)(float)(vColor.x * 255.89999);
              v16 = (int)(float)(vColor.y * 255.89999);
              v17 = (int)(float)(vColor.z * 255.89999);
              v7->m_pParticle = v10;
              v5 = z;
              v7->m_Color[0] = v15;
              v7->m_Color[1] = v16;
              v7->m_Color[2] = v17;
              v7->m_FadeAlpha = 1.0;
              v7->m_TradeIndex = -1;
            }
          }
          v4 = y;
          ++v5;
        }
        y = ++v4;
      }
      while ( v4 < this->m_yCount );
      v3 = x;
    }
    x = ++v3;
  }
  while ( v3 < this->m_xCount );
}

//------------------------------------------------------------------------------
// Address: 0x10247D80
// Name: public: virtual void C_ParticleSmokeGrenade::CleanupToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::CleanupToolRecordingState(C_ParticleSmokeGrenade *this, KeyValues *msg)
{
  int value; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues *Key; // ebx
  KeyValues *v7; // edi
  void *v8; // eax
  KeyValues *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  KeyValues *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // edi
  KeyValues *pColor; // [esp+14h] [ebp-Ch]
  KeyValues *msga; // [esp+18h] [ebp-8h]
  Color c2; // [esp+1Ch] [ebp-4h]
  KeyValues *pRolla; // [esp+28h] [ebp+8h]
  KeyValues *pRollb; // [esp+28h] [ebp+8h]
  KeyValues *pRollc; // [esp+28h] [ebp+8h]
  KeyValues *pRolld; // [esp+28h] [ebp+8h]
  KeyValues *pRolle; // [esp+28h] [ebp+8h]
  KeyValues *pRoll; // [esp+28h] [ebp+8h]
  KeyValues *pRollf; // [esp+28h] [ebp+8h]
  KeyValues *pRollg; // [esp+28h] [ebp+8h]

  if ( ToolsEnabled() )
  {
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)msg);
    this->m_SmokeTrail.CleanupToolRecordingState(this: &this->m_SmokeTrail, a2: msg);
    if ( clienttools->IsInRecordingMode(this: clienttools)
      && this->m_bVolumeFilled
      && this->m_nToolParticleEffectId == -1 )
    {
      this->m_bVolumeFilled = false;
      value = C_BaseParticleEntity::AllocateToolParticleEffectId(this);
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "OldParticleSystem_Create");
        msga = v5;
      }
      else
      {
        msga = nullptr;
        v5 = nullptr;
      }
      KeyValues::SetString(this: v5, keyName: "name", value: "C_ParticleSmokeGrenade");
      KeyValues::SetInt(this: v5, keyName: "id", value);
      KeyValues::SetFloat(this: v5, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
      Key = KeyValues::FindKey(this: v5, keyName: "DmeSpriteEmitter", bCreate: true);
      KeyValues::SetInt(this: Key, keyName: "count", value: 216);
      KeyValues::SetFloat(this: Key, keyName: "duration", value: 0.0);
      KeyValues::SetString(this: Key, keyName: "material", value: "particle/particle_smokegrenade1");
      KeyValues::SetInt(this: Key, keyName: "active", value: 1);
      v7 = KeyValues::FindKey(this: Key, keyName: "initializers", bCreate: true);
      pRolla = KeyValues::FindKey(this: v7, keyName: "DmeVoxelPositionInitializer", bCreate: true);
      KeyValues::SetFloat(this: pRolla, keyName: "centerx", value: this->m_SmokeBasePos.x);
      KeyValues::SetFloat(this: pRolla, keyName: "centery", value: this->m_SmokeBasePos.y);
      KeyValues::SetFloat(this: pRolla, keyName: "centerz", value: this->m_SmokeBasePos.z);
      KeyValues::SetFloat(this: pRolla, keyName: "particlesPerDimension", value: (float)this->m_xCount);
      KeyValues::SetFloat(this: pRolla, keyName: "particleSpacing", value: this->m_SpacingRadius);
      pRollb = KeyValues::FindKey(this: v7, keyName: "DmeRandomLifetimeInitializer", bCreate: true);
      KeyValues::SetFloat(this: pRollb, keyName: "minLifetime", value: this->m_FadeEndTime);
      KeyValues::SetFloat(this: pRollb, keyName: "maxLifetime", value: this->m_FadeEndTime);
      pRollc = KeyValues::FindKey(this: v7, keyName: "DmeAttachmentVelocityInitializer", bCreate: true);
      v8 = (void *)this->entindex(this: &this->IClientNetworkable);
      KeyValues::SetPtr(this: pRollc, keyName: "entindex", value: v8);
      KeyValues::SetFloat(this: pRollc, keyName: "minRandomSpeed", value: 10.0);
      KeyValues::SetFloat(this: pRollc, keyName: "maxRandomSpeed", value: 20.0);
      pRolld = KeyValues::FindKey(this: v7, keyName: "DmeRandomRollInitializer", bCreate: true);
      KeyValues::SetFloat(this: pRolld, keyName: "minRoll", value: -6.0);
      KeyValues::SetFloat(this: pRolld, keyName: "maxRoll", value: 6.0);
      pRolle = KeyValues::FindKey(this: v7, keyName: "DmeRandomRollSpeedInitializer", bCreate: true);
      KeyValues::SetFloat(this: pRolle, keyName: "minRollSpeed", value: -0.60000002);
      KeyValues::SetFloat(this: pRolle, keyName: "maxRollSpeed", value: 0.60000002);
      v9 = KeyValues::FindKey(this: v7, keyName: "DmeRandomInterpolatedColorInitializer", bCreate: true);
      v10 = 255.0;
      pColor = v9;
      v11 = this->m_MinColor.z * 255.0;
      v12 = this->m_MinColor.y * 255.0;
      v13 = this->m_MinColor.x * 255.0;
      if ( v11 >= 0.0 )
      {
        if ( v11 > 255.0 )
          v11 = 255.0;
      }
      else
      {
        v11 = 0.0;
      }
      if ( v12 >= 0.0 )
      {
        if ( v12 > 255.0 )
          v12 = 255.0;
      }
      else
      {
        v12 = 0.0;
      }
      if ( v13 >= 0.0 )
      {
        if ( v13 > 255.0 )
          v13 = 255.0;
      }
      else
      {
        v13 = 0.0;
      }
      LOBYTE(pRoll) = (int)v13;
      v14 = (int)v11;
      v15 = this->m_MaxColor.z * 255.0;
      BYTE1(pRoll) = (int)v12;
      BYTE2(pRoll) = v14;
      HIBYTE(pRoll) = -1;
      v16 = this->m_MaxColor.y * 255.0;
      v17 = this->m_MaxColor.x * 255.0;
      if ( v15 >= 0.0 )
      {
        if ( v15 > 255.0 )
          v15 = 255.0;
      }
      else
      {
        v15 = 0.0;
      }
      if ( v16 >= 0.0 )
      {
        if ( v16 > 255.0 )
          v16 = 255.0;
      }
      else
      {
        v16 = 0.0;
      }
      if ( v17 >= 0.0 )
      {
        if ( v17 <= 255.0 )
          v10 = this->m_MaxColor.x * 255.0;
      }
      else
      {
        v10 = 0.0;
      }
      c2._color[1] = (int)v16;
      c2._color[0] = (int)v10;
      c2._color[2] = (int)v15;
      c2._color[3] = -1;
      KeyValues::SetColor(this: v9, keyName: "color1", value: (Color)pRoll);
      KeyValues::SetColor(this: pColor, keyName: "color2", value: c2);
      pRollf = KeyValues::FindKey(this: v7, keyName: "DmeRandomAlphaInitializer", bCreate: true);
      KeyValues::SetInt(this: pRollf, keyName: "minStartAlpha", value: 255);
      KeyValues::SetInt(this: pRollf, keyName: "maxStartAlpha", value: 255);
      KeyValues::SetInt(this: pRollf, keyName: "minEndAlpha", value: 0);
      KeyValues::SetInt(this: pRollf, keyName: "maxEndAlpha", value: 0);
      pRollg = KeyValues::FindKey(this: v7, keyName: "DmeRandomSizeInitializer", bCreate: true);
      KeyValues::SetFloat(this: pRollg, keyName: "minStartSize", value: 55.0);
      KeyValues::SetFloat(this: pRollg, keyName: "maxStartSize", value: 55.0);
      KeyValues::SetFloat(this: pRollg, keyName: "minEndSize", value: 55.0);
      KeyValues::SetFloat(this: pRollg, keyName: "maxEndSize", value: 55.0);
      KeyValues::FindKey(this: v7, keyName: "DmeSolidKillInitializer", bCreate: true);
      v18 = KeyValues::FindKey(this: Key, keyName: "updaters", bCreate: true);
      KeyValues::FindKey(this: v18, keyName: "DmeRollUpdater", bCreate: true);
      KeyValues::FindKey(this: v18, keyName: "DmeColorUpdater", bCreate: true);
      v19 = KeyValues::FindKey(this: v18, keyName: "DmeAlphaCosineUpdater", bCreate: true);
      KeyValues::SetFloat(this: v19, keyName: "duration", value: this->m_FadeEndTime - this->m_FadeStartTime);
      KeyValues::FindKey(this: v18, keyName: "DmeColorDynamicLightUpdater", bCreate: true);
      v20 = KeyValues::FindKey(this: v18, keyName: "DmeSmokeGrenadeUpdater", bCreate: true);
      KeyValues::SetFloat(this: v20, keyName: "centerx", value: this->m_SmokeBasePos.x);
      KeyValues::SetFloat(this: v20, keyName: "centery", value: this->m_SmokeBasePos.y);
      KeyValues::SetFloat(this: v20, keyName: "centerz", value: this->m_SmokeBasePos.z);
      KeyValues::SetFloat(this: v20, keyName: "particlesPerDimension", value: (float)this->m_xCount);
      KeyValues::SetFloat(this: v20, keyName: "particleSpacing", value: this->m_SpacingRadius);
      KeyValues::SetFloat(this: v20, keyName: "radiusExpandTime", value: 5.5);
      KeyValues::SetFloat(this: v20, keyName: "cutoffFraction", value: 0.69999999);
      ToolFramework_PostToolMessage(hEntity: 0, msg: msga);
      KeyValues::deleteThis(this: msga);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102483E0
// Name: public: C_ParticleSmokeGrenade::C_ParticleSmokeGrenade(void)
// Source: json
//------------------------------------------------------------------------------
C_ParticleSmokeGrenade *__thiscall C_ParticleSmokeGrenade::C_ParticleSmokeGrenade(C_ParticleSmokeGrenade *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleSmokeGrenade_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleSmokeGrenade::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleSmokeGrenade::`vftable';
  C_SmokeTrail::C_SmokeTrail(this: &this->m_SmokeTrail);
  this->m_MaterialHandles[0] = nullptr;
  this->m_MinColor.x = 0.5;
  this->m_MinColor.y = 0.5;
  this->m_MinColor.z = 0.5;
  this->m_MaxColor.x = 0.60000002;
  this->m_MaxColor.y = 0.60000002;
  this->m_MaxColor.z = 0.60000002;
  this->m_nActiveLights = 0;
  this->m_CurrentStage = 0;
  *(_WORD *)&this->m_bStarted = 0;
  *(_QWORD *)&this->m_ExpandTimeCounter = 0;
  this->m_FadeStartTime = 0.0;
  this->m_FadeEndTime = 0.0;
  this->m_flSpawnTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102484C0
// Name: public: virtual void C_ParticleSmokeGrenade::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::Update(C_ParticleSmokeGrenade *this, float fTimeDelta)
{
  float y; // xmm1_4
  __m128 v4; // xmm2
  float v5; // xmm0_4
  float z; // xmm0_4
  __m128i v7; // xmm0
  double v8; // xmm0_8
  float m_TradeDuration; // xmm2_4
  int m_TradeIndex; // xmm0_4
  int m_nNextThinkTick; // xmm1_4
  int m_iHealth; // xmm2_4
  int m_fFlags; // xmm3_4
  bool v14; // cc
  __m128i v15; // xmm0
  int v16; // ebx
  double v17; // xmm0_8
  int v18; // edi
  unsigned __int8 **v19; // eax
  C_ParticleSmokeGrenade *v20; // ecx
  int *v21; // eax
  Vector vMins; // [esp+10h] [ebp-1Ch] BYREF
  Vector vMaxs; // [esp+1Ch] [ebp-10h] BYREF
  float flLifetime; // [esp+28h] [ebp-4h]

  flLifetime = *(float *)(gpGlobals.m_Index + 12) - this->m_vecViewOffset.x;
  C_ParticleSmokeGrenade::UpdateSmokeTrail(this: (C_ParticleSmokeGrenade *)((char *)this - 2432), fTimeDelta);
  y = this->m_vecViewOffset.y;
  v4 = (__m128)LODWORD(flLifetime);
  if ( y <= flLifetime )
  {
    z = this->m_vecViewOffset.z;
    if ( z <= flLifetime )
    {
      v5 = 0.0;
    }
    else
    {
      v4.m128_f32[0] = (float)(flLifetime - y) / (float)(z - y);
      v7 = (__m128i)_mm_cvtps_pd(v4);
      *(double *)v7.m128i_i64 = *(double *)v7.m128i_i64 * 3.14159;
      __libm_sse2_cos(X: v7);
      v5 = (v8 + 1.0) * 0.5;
    }
  }
  else
  {
    v5 = 1.0;
  }
  m_TradeDuration = this->m_SmokeParticleInfos[115].m_TradeDuration;
  this->m_vecVelocity.x = v5;
  m_TradeIndex = this->m_SmokeParticleInfos[115].m_TradeIndex;
  this->m_vecVelocity.x = (float)(m_TradeDuration / (float)(*(float *)&m_TradeIndex * 2.0)) * this->m_vecVelocity.x;
  m_nNextThinkTick = this->m_nNextThinkTick;
  vMins.x = *(float *)&m_nNextThinkTick - *(float *)&m_TradeIndex;
  m_iHealth = this->m_iHealth;
  m_fFlags = this->m_fFlags;
  vMins.y = *(float *)&m_iHealth - *(float *)&m_TradeIndex;
  vMins.z = *(float *)&m_fFlags - *(float *)&m_TradeIndex;
  vMaxs.x = *(float *)&m_nNextThinkTick + *(float *)&m_TradeIndex;
  vMaxs.y = *(float *)&m_iHealth + *(float *)&m_TradeIndex;
  vMaxs.z = *(float *)&m_fFlags + *(float *)&m_TradeIndex;
  CParticleEffectBinding::SetBBox(
    this: (CParticleEffectBinding *)&this->IClientRenderable,
    bbMin: &vMins,
    bbMax: &vMaxs,
    bDisableAutoUpdate: true);
  C_ParticleSmokeGrenade::UpdateDynamicLightList(this: (C_ParticleSmokeGrenade *)((char *)this - 2432), &vMins, &vMaxs);
  if ( LOBYTE(this->m_iTeamNum) == 1 )
  {
    v14 = flLifetime <= 5.5;
    this->m_SmokeParticleInfos[115].m_TradeClock = flLifetime;
    if ( !v14 )
      this->m_SmokeParticleInfos[115].m_TradeClock = 5.5;
    v15 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(this->m_SmokeParticleInfos[115].m_TradeClock));
    *(double *)v15.m128i_i64 = *(double *)v15.m128i_i64 * 3.141592653589793 * 0.5 * 0.1818181818181818;
    __libm_sse2_sin(X: v15);
    v16 = LODWORD(this->m_SmokeParticleInfos[114].m_FadeAlpha)
        * *(_DWORD *)this->m_SmokeParticleInfos[114].m_Color
        * (int)this->m_SmokeParticleInfos[115].m_pParticle;
    *(float *)&v17 = v17;
    v18 = 0;
    this->m_SmokeParticleInfos[115].m_TradeDuration = *(float *)&v17
                                                    * (float)(*(float *)&this->m_SmokeParticleInfos[115].m_TradeIndex
                                                            * 2.0);
    if ( v16 > 0 )
    {
      v19 = &this->m_pIntermediateData[18];
      LODWORD(flLifetime) = &this->m_pIntermediateData[18];
      do
      {
        if ( *v19 != nullptr )
        {
          v20 = (C_ParticleSmokeGrenade *)((char *)this - 2432);
          if ( v19[1] == (unsigned __int8 *)-1 )
            C_ParticleSmokeGrenade::UpdateParticleAndFindTrade(this: v20, iParticle: v18, fTimeDelta);
          else
            C_ParticleSmokeGrenade::UpdateParticleDuringTrade(this: v20, iParticle: v18, fTimeDelta);
        }
        ++v18;
        v19 = (unsigned __int8 **)(LODWORD(flLifetime) + 24);
        LODWORD(flLifetime) += 24;
      }
      while ( v18 < v16 );
    }
  }
  v21 = (int *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
  this->m_nNextThinkTick = *v21;
  this->m_iHealth = v21[1];
  this->m_fFlags = v21[2];
}

//------------------------------------------------------------------------------
// Address: 0x10248720
// Name: public: virtual void C_ParticleSmokeGrenade::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_ParticleSmokeGrenade::RenderParticles(
        C_ParticleSmokeGrenade *this@<ecx>,
        float a2@<ebp>,
        CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // edx
  Particle *m_pNext; // ecx
  Particle *i; // esi
  float x; // xmm0_4
  int m_nNextThinkTick; // xmm1_4
  int m_iHealth; // xmm3_4
  float y; // xmm2_4
  float z; // xmm4_4
  float m_TradeDuration; // xmm5_4
  CParticleMgr *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  int x_low; // edx
  float v21; // xmm5_4
  float v22; // xmm4_4
  int v23; // eax
  int v24; // ecx
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  int x_high; // edx
  CParticleMgr *v31; // eax
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // [esp+1Ch] [ebp-5Ch]
  Vector v36; // [esp+30h] [ebp-48h] BYREF
  Vector tRenderPos; // [esp+3Ch] [ebp-3Ch] BYREF
  Vector color; // [esp+48h] [ebp-30h]
  Vector vWorldSpacePos; // [esp+54h] [ebp-24h] BYREF
  Vector renderPos; // [esp+60h] [ebp-18h]
  float sortKey; // [esp+6Ch] [ebp-Ch]
  float alpha; // [esp+70h] [ebp-8h]
  float retaddr; // [esp+78h] [ebp+0h]

  sortKey = a2;
  alpha = retaddr;
  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur;
          i != nullptr;
          i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: v14) )
    {
      x = i->m_Pos.x;
      m_nNextThinkTick = this->m_nNextThinkTick;
      m_iHealth = this->m_iHealth;
      LODWORD(renderPos.z) = this->m_fFlags;
      color.x = *(float *)&m_nNextThinkTick + x;
      y = i->m_Pos.y;
      color.y = *(float *)&m_iHealth + y;
      z = i->m_Pos.z;
      color.z = renderPos.z + z;
      v35 = fsqrt((float)((float)(x * x) + (float)(y * y)) + (float)(z * z));
      m_TradeDuration = this->m_SmokeParticleInfos[115].m_TradeDuration;
      if ( v35 <= m_TradeDuration )
      {
        v15 = m_TradeDuration * 0.5;
        if ( v35 <= v15 )
        {
          vWorldSpacePos.x = color.x;
          vWorldSpacePos.y = color.y;
          v17 = color.z;
        }
        else
        {
          v16 = x * v15;
          v17 = renderPos.z + (float)((float)(z * v15) * (float)(1.0 / v35));
          vWorldSpacePos.x = *(float *)&m_nNextThinkTick + (float)((float)(1.0 / v35) * v16);
          vWorldSpacePos.y = *(float *)&m_iHealth + (float)((float)(y * v15) * (float)(1.0 / v35));
        }
        v18 = v35 / this->m_SmokeParticleInfos[115].m_TradeDuration;
        vWorldSpacePos.z = v17;
        if ( (float)(1.0 - v18) <= testCutoff )
          v19 = (float)(1.0 - v18) / testCutoff;
        else
          v19 = 1.0;
        x_low = LOBYTE(i[1].m_Pos.x);
        v21 = this->m_vecVelocity.z;
        v22 = this->m_vecVelocity.y;
        v23 = BYTE1(i[1].m_Pos.x);
        v24 = BYTE2(i[1].m_Pos.x);
        v25 = (float)(this->m_vecVelocity.x * v19) * *(float *)&i[1].m_pSubTexture;
        v26 = this->m_vecBaseVelocity.x;
        v27 = this->m_angNetworkAngles.x;
        v28 = this->m_vecBaseVelocity.z - v21;
        renderPos.y = v25;
        v29 = (float)x_low * 0.0039200312;
        x_high = HIBYTE(i[1].m_Pos.x);
        tRenderPos.x = (float)((float)v23 * 0.0039215689)
                     * (float)(v22 + (float)((float)(this->m_vecBaseVelocity.y - v22) * v29));
        tRenderPos.y = (float)((float)v24 * 0.0039215689) * (float)(v21 + (float)(v28 * v29));
        tRenderPos.z = (float)((float)x_high * 0.0039215689) * (float)(v26 + (float)((float)(v27 - v26) * v29));
        C_ParticleSmokeGrenade::ApplyDynamicLight(
          this: (C_ParticleSmokeGrenade *)((char *)this - 2432),
          vParticlePos: &vWorldSpacePos,
          color: &tRenderPos);
        v31 = ParticleMgr();
        v32 = v31->m_mModelView.m[1][0];
        v36.x = (float)((float)((float)(v31->m_mModelView.m[0][1] * vWorldSpacePos.y)
                              + (float)(v31->m_mModelView.m[0][0] * vWorldSpacePos.x))
                      + (float)(v31->m_mModelView.m[0][2] * vWorldSpacePos.z))
              + v31->m_mModelView.m[0][3];
        v36.y = (float)((float)((float)(v31->m_mModelView.m[1][1] * vWorldSpacePos.y) + (float)(v32 * vWorldSpacePos.x))
                      + (float)(v31->m_mModelView.m[1][2] * vWorldSpacePos.z))
              + v31->m_mModelView.m[1][3];
        v36.z = (float)((float)((float)(v31->m_mModelView.m[2][1] * vWorldSpacePos.y)
                              + (float)(v31->m_mModelView.m[2][0] * vWorldSpacePos.x))
                      + (float)(v31->m_mModelView.m[2][2] * vWorldSpacePos.z))
              + v31->m_mModelView.m[2][3];
        renderPos.x = v36.z;
        v33 = -v36.z;
        if ( (float)-v36.z <= 200.0 )
        {
          if ( v33 <= 100.0 )
            v34 = 0.0;
          else
            v34 = (float)(v33 - 100.0) * 0.0099999998;
        }
        else
        {
          v34 = 1.0;
        }
        RenderParticle_ColorSizeAngle(
          pDraw: pIterator->m_pParticleDraw,
          pos: &v36,
          color: &tRenderPos,
          alpha: v34 * renderPos.y,
          size: 55.0,
          angle: *(float *)&i[1].m_pNext);
        v14 = renderPos.x;
      }
      else
      {
        v13 = ParticleMgr();
        v14 = (float)((float)((float)(v13->m_mModelView.m[2][1] * color.y) + (float)(v13->m_mModelView.m[2][0] * color.x))
                    + (float)(v13->m_mModelView.m[2][2] * color.z))
            + v13->m_mModelView.m[2][3];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248B20
// Name: public: static void C_ParticleSmokeGrenade::RecvProxy_CurrentStage(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_ParticleSmokeGrenade::RecvProxy_CurrentStage(
        const CRecvProxyData *pData,
        C_ParticleSmokeGrenade *pStruct)
{
  if ( pStruct != nullptr && pStruct->m_CurrentStage == 0 && pData->m_Value.m_Int == 1 )
  {
    if ( pStruct->m_bStarted )
      C_ParticleSmokeGrenade::FillVolume(this: pStruct);
    else
      pStruct->m_CurrentStage = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248CD0
// Name: public: virtual void C_ParticleSmokeGrenade::NotifyRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSmokeGrenade::NotifyRemove(C_ParticleSmokeGrenade *this)
{
  C_CSPlayer *LocalPlayer; // eax
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->m_SmokeParticleInfos[115].m_pParticle = nullptr;
  *(_DWORD *)this->m_SmokeParticleInfos[114].m_Color = 0;
  this->m_SmokeParticleInfos[114].m_FadeAlpha = 0.0;
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    src = (vgui::TreeNode *)((char *)this - 2432);
    CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&LocalPlayer->m_SmokeGrenades,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248D20
// Name: public: virtual void C_ParticleSmokeGrenade::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_ParticleSmokeGrenade::Start(
        C_ParticleSmokeGrenade *this@<ecx>,
        int a2@<ebx>,
        CParticleMgr *pParticleMgr,
        IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v5; // ecx
  int (__thiscall *v6)(char *); // edx
  vgui::TreeNode *v7; // ebx
  const Vector *v8; // eax
  bool (__thiscall *IsValidKeyBindingsContext)(vgui::Panel *); // eax
  C_CSPlayer *LocalPlayer; // eax
  int m_Size; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_SmokeGrenades; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v15; // eax
  vgui::TreeNode **v16; // edi
  char str[256]; // [esp+20h] [ebp-100h] BYREF

  if ( this == (C_ParticleSmokeGrenade *)2664 )
    v5 = nullptr;
  else
    v5 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v5) != 0 )
  {
    ((void (__thiscall *)(C_SmokeTrail *, CParticleMgr *, IPrototypeArgAccess *, int))this->m_SmokeTrail.SetRefEHandle)(
      a1: &this->m_SmokeTrail,
      a2: pParticleMgr,
      a3: pArgs,
      a4: a2);
    this->m_SmokeTrail.m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 1056964608;
    C_SmokeTrail::SetSpawnRate(this: (C_SmokeTrail *)&this->m_SmokeParticleInfos[106], rate: 40.0);
    v6 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40);
    v7 = (vgui::TreeNode *)((char *)this - 2664);
    *((_DWORD *)&this->m_SmokeTrail.m_VarMap + 7) = 1077936128;
    this->m_SmokeTrail.m_VarMap.m_Entries.m_Size = 0;
    this->m_SmokeTrail.m_VarMap.m_Entries.m_pElements = nullptr;
    LODWORD(this->m_SmokeTrail.m_pfnThink) = 1092616192;
    DWORD1(this->m_SmokeTrail.m_pfnThink) = 0;
    v8 = (const Vector *)v6(a1: (char *)this - 2664);
    C_BaseEntity::SetLocalOrigin(this: (C_BaseEntity *)&this->m_SmokeParticleInfos[106], origin: v8);
    V_snprintf(pDest: str, maxLen: 0x100u, pFormat: "particle/particle_smokegrenade%d", 1);
    *(_DWORD *)&this->m_iv_vecOrigin.m_VarHistory.m_count = CParticleEffectBinding::FindOrAddMaterial(
                                                              this: (CParticleEffectBinding *)((char *)this - 228),
                                                              pMaterialName: str);
    if ( LOBYTE(this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable) == 2 )
      C_ParticleSmokeGrenade::FillVolume(this: (C_ParticleSmokeGrenade *)((char *)this - 2664));
    if ( pArgs != nullptr && pArgs->FindArg(this: pArgs, a2: "-FillVolume", a3: nullptr) != 0 )
      C_ParticleSmokeGrenade::FillVolume(this: (C_ParticleSmokeGrenade *)((char *)this - 2664));
    IsValidKeyBindingsContext = v7->IsValidKeyBindingsContext;
    LOBYTE(this->m_iv_vecOrigin.m_VarHistory.m_maxElement) = 1;
    ((void (__thiscall *)(char *, int))IsValidKeyBindingsContext)(a1: (char *)this - 2664, a2: -996040704);
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr )
    {
      m_Size = LocalPlayer->m_SmokeGrenades.m_Size;
      p_m_SmokeGrenades = (CUtlMemory<vgui::TreeNode *,int> *)&LocalPlayer->m_SmokeGrenades;
      m_nAllocationCount = LocalPlayer->m_SmokeGrenades.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_SmokeGrenades, num: m_Size - m_nAllocationCount + 1);
      ++p_m_SmokeGrenades[1].m_pMemory;
      m_pMemory = p_m_SmokeGrenades->m_pMemory;
      v15 = (int)p_m_SmokeGrenades[1].m_pMemory - m_Size - 1;
      p_m_SmokeGrenades[1].m_nAllocationCount = (int)p_m_SmokeGrenades->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v15);
      v16 = &p_m_SmokeGrenades->m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042AB00
// Name: DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ParticleSmokeGrenade::g_RecvTable);
  return atexit(func: DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AB20
// Name: DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ParticleSmokeGrenade::ignored>();
  DT_ParticleSmokeGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436610
// Name: DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ParticleSmokeGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10248B60
// Name: _C_ParticleSmokeGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ParticleSmokeGrenade_CreateObject(int entnum, int serialNum)
{
  C_ParticleSmokeGrenade *v2; // eax
  C_ParticleSmokeGrenade *v3; // eax
  C_ParticleSmokeGrenade *v4; // esi

  v2 = (C_ParticleSmokeGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0x2D68u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_ParticleSmokeGrenade::C_ParticleSmokeGrenade(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AB30
// Name: _dynamic_initializer_for____g_C_PropVehicleDriveableClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PropVehicleDriveableClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PropVehicleDriveableClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PropVehicleDriveableClientClass;
  return result;
}
