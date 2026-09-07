// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_dust.cpp
// Functions: 26
// ============================================================

#include "game\client\c_func_dust.h"

//------------------------------------------------------------------------------
// Address: 0x1006F6D0
// Name: public: virtual class ClientClass __near * C_Func_Dust::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Func_Dust::GetClientClass(C_Func_Dust *this)
{
  return &__g_C_Func_DustClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006F880
// Name: public: virtual class ClientClass __near * C_TEDust::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEDust::GetClientClass(C_TEDust *this)
{
  return &__g_C_TEDustClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006F960
// Name: public: virtual bool CParticleEffect::ShouldSimulate(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleEffect::ShouldSimulate(CParticleEffect *this)
{
  return this->m_bSimulate;
}

//------------------------------------------------------------------------------
// Address: 0x1006F970
// Name: public: virtual void CParticleEffect::SetShouldSimulate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::SetShouldSimulate(CParticleEffect *this, bool bSim)
{
  this->m_bSimulate = bSim;
}

//------------------------------------------------------------------------------
// Address: 0x1006F9B0
// Name: public: virtual void CDustEffect::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDustEffect::SimulateParticles(CDustEffect *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  float v5; // xmm0_4
  bool v6; // cf
  float v7; // xmm0_4
  float v8; // xmm1_4
  float x; // xmm0_4
  bool v10; // cc
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float y; // xmm0_4
  bool v15; // cc
  float v16; // xmm1_4
  float m_flTimeDelta; // xmm0_4
  Vector vecWind; // [esp+10h] [ebp-Ch] BYREF

  GetWindspeedAtTime(flTime: *(float *)(gpGlobals.m_Index + 12), vecVelocity: &vecWind);
  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      if ( (this->m_pDust->m_DustFlags & 4) != 0 )
        goto LABEL_19;
      v5 = pIterator->m_flTimeDelta + m_pNext[1].m_Pos.x;
      v6 = v5 < m_pNext[1].m_Pos.y;
      m_pNext[1].m_Pos.x = v5;
      if ( !v6 )
      {
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
        goto LABEL_19;
      }
      v7 = *(float *)&m_pNext[1].m_pPrev;
      if ( vecWind.x <= v7 )
      {
        if ( v7 <= vecWind.x )
          goto LABEL_12;
        v11 = *(float *)&m_pNext[1].m_pPrev - (float)(*(float *)(gpGlobals.m_Index + 16) * 50.0);
        *(float *)&m_pNext[1].m_pPrev = v11;
        x = vecWind.x;
        v10 = vecWind.x <= v11;
      }
      else
      {
        v8 = (float)(*(float *)(gpGlobals.m_Index + 16) * 50.0) + *(float *)&m_pNext[1].m_pPrev;
        *(float *)&m_pNext[1].m_pPrev = v8;
        x = vecWind.x;
        v10 = v8 <= vecWind.x;
      }
      if ( !v10 )
        *(float *)&m_pNext[1].m_pPrev = x;
LABEL_12:
      v12 = *(float *)&m_pNext[1].m_pNext;
      if ( vecWind.y > v12 )
      {
        v13 = (float)(*(float *)(gpGlobals.m_Index + 16) * 50.0) + *(float *)&m_pNext[1].m_pNext;
        *(float *)&m_pNext[1].m_pNext = v13;
        y = vecWind.y;
        v15 = v13 <= vecWind.y;
        goto LABEL_16;
      }
      if ( v12 > vecWind.y )
      {
        v16 = *(float *)&m_pNext[1].m_pNext - (float)(*(float *)(gpGlobals.m_Index + 16) * 50.0);
        *(float *)&m_pNext[1].m_pNext = v16;
        y = vecWind.y;
        v15 = vecWind.y <= v16;
LABEL_16:
        if ( !v15 )
          *(float *)&m_pNext[1].m_pNext = y;
      }
      m_flTimeDelta = pIterator->m_flTimeDelta;
      m_pNext->m_Pos.x = (float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta) + m_pNext->m_Pos.x;
      m_pNext->m_Pos.y = (float)(*(float *)&m_pNext[1].m_pNext * m_flTimeDelta) + m_pNext->m_Pos.y;
      m_pNext->m_Pos.z = (float)(*(float *)&m_pNext[1].m_pSubTexture * m_flTimeDelta) + m_pNext->m_Pos.z;
LABEL_19:
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FB70
// Name: public: C_Func_Dust::C_Func_Dust(void)
// Source: json
//------------------------------------------------------------------------------
C_Func_Dust *__thiscall C_Func_Dust::C_Func_Dust(C_Func_Dust *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Func_Dust_vtbl *)&C_Func_Dust::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Func_Dust::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Func_Dust::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Func_Dust::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Func_Dust::`vftable';
  CParticleEffect::CParticleEffect(this: &this->m_Effect, pName: "C_Func_Dust");
  this->m_Effect.__vftable = (CDustEffect_vtbl *)&CDustEffect::`vftable';
  this->m_Spawner.m_TimeBetweenEvents = -1.0;
  this->m_Spawner.m_fNextEvent = 0.0;
  this->m_Effect.m_pDust = this;
  CParticleEffect::SetDynamicallyAllocated(this: &this->m_Effect, bDynamic: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006FC40
// Name: private: void C_Func_Dust::AttemptSpawnNewParticle(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_Func_Dust::AttemptSpawnNewParticle(C_Func_Dust *this)
{
  int v1; // ebx
  IUniformRandomStream *v3; // ecx
  IUniformRandomStream *v4; // ecx
  const Vector *v5; // edi
  const Vector *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  const Vector *(__thiscall *WorldAlignMins)(C_BaseEntity *); // edx
  float *v10; // eax
  C_Func_Dust_vtbl *v11; // edx
  IEngineTrace_vtbl *v12; // edi
  ICollideable *(__thiscall *GetCollideable)(IClientUnknown *); // eax
  int v14; // eax
  IUniformRandomStream *v15; // ecx
  Particle *v16; // edi
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  double v19; // st7
  IUniformRandomStream *v20; // ecx
  IUniformRandomStream *v21; // ecx
  float m_SpeedMax; // [esp+Ch] [ebp-34h]
  Vector vTest; // [esp+14h] [ebp-2Ch] BYREF
  float v24; // [esp+20h] [ebp-20h]
  float v25; // [esp+24h] [ebp-1Ch]
  float m_flSizeMin; // [esp+28h] [ebp-18h]
  Vector vPercent; // [esp+2Ch] [ebp-14h]
  float v28; // [esp+38h] [ebp-8h]
  float v29; // [esp+3Ch] [ebp-4h]

  v1 = 0;
  if ( nTests > 0 )
  {
    while ( 1 )
    {
      vPercent.x = _RandomFloat((IUniformRandomStream *)this, a2: 0.0, a3: 1.0);
      vPercent.y = _RandomFloat(this: v3, a2: 0.0, a3: 1.0);
      vPercent.z = _RandomFloat(this: v4, a2: 0.0, a3: 1.0);
      v5 = this->WorldAlignMins(this);
      v6 = this->WorldAlignMaxs(this);
      v7 = (float)(v6->y - v5->y) * vPercent.y;
      v8 = (float)(v6->z - v5->z) * vPercent.z;
      WorldAlignMins = this->WorldAlignMins;
      v24 = (float)(v6->x - v5->x) * vPercent.x;
      v25 = v7;
      m_flSizeMin = v8;
      v10 = (float *)WorldAlignMins(this);
      v11 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      vTest.x = v24 + *v10;
      vTest.y = v10[1] + v25;
      vTest.z = v10[2] + m_flSizeMin;
      v12 = enginetrace->__vftable;
      GetCollideable = v11->GetCollideable;
      LODWORD(vTest.x) = &vTest;
      v14 = (int)GetCollideable(this);
      if ( (((int (__thiscall *)(IEngineTrace *, int))v12->GetPointContents_Collideable)(a1: enginetrace, a2: v14) & 1) != 0 )
        break;
      if ( ++v1 >= nTests )
        return;
    }
    v16 = CParticleEffect::AddParticle(
            this: &this->m_Effect,
            particleSize: 0xAu,
            material: this->m_hMaterial,
            origin: &vTest);
    if ( v16 != nullptr )
    {
      m_SpeedMax = (float)this->m_SpeedMax;
      v28 = (float)-this->m_SpeedMax;
      v29 = m_SpeedMax;
      v24 = _RandomFloat(this: v15, a2: v28, a3: m_SpeedMax);
      v25 = _RandomFloat(this: v17, a2: v28, a3: v29);
      v19 = _RandomFloat(this: v18, a2: v28, a3: v29);
      *(float *)&v16[1].m_pPrev = v24;
      *(float *)&v16[1].m_pNext = v25;
      *(float *)&v16[1].m_pSubTexture = v19;
      *(float *)&v16[1].m_pSubTexture = *(float *)&v16[1].m_pSubTexture - this->m_FallSpeed;
      v16[1].m_Pos.x = 0.0;
      v16[1].m_Pos.y = _RandomFloat(this: v20, a2: (float)this->m_LifetimeMin, a3: (float)this->m_LifetimeMax);
      if ( (this->m_DustFlags & 2) != 0 )
      {
        vPercent.x = this->m_flSizeMax * 0.000099999997;
        m_flSizeMin = this->m_flSizeMin * 0.000099999997;
      }
      else
      {
        vPercent.x = this->m_flSizeMax;
        m_flSizeMin = this->m_flSizeMin;
      }
      v16[1].m_Pos.z = _RandomFloat(this: v21, a2: m_flSizeMin, a3: vPercent.x);
      v16[2].m_pPrev = (Particle *)this->m_Color;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FF20
// Name: void RenderParticle_Color255Size(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_Color255Size(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  float *m_pCurrPosition; // eax
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // ebx
  float *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // ecx
  float v16; // xmm0_4
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm0_4
  _DWORD *m_pCurrColor; // edx
  float *v21; // ecx
  float v22; // xmm0_4
  float *v23; // eax
  float v24; // xmm2_4
  float v25; // xmm0_4
  _DWORD *v26; // ecx
  float *v27; // esi
  float v28; // xmm0_4
  int z; // [esp+0h] [ebp-10h]
  int y; // [esp+4h] [ebp-Ch]
  int x; // [esp+8h] [ebp-8h]
  CVertexBuilder *alphaa; // [esp+24h] [ebp+14h]

  if ( alpha >= 0.5 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      x = (int)color->x;
      y = (int)color->y;
      z = (int)color->z;
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v7 = pos->z;
      v8 = pos->y - size;
      *m_pCurrPosition = pos->x - size;
      m_pCurrPosition[1] = v8;
      m_pCurrPosition[2] = v7;
      v9 = (unsigned __int8)z
         | (((unsigned __int8)y | (((unsigned __int8)x | ((unsigned __int8)(int)alpha << 8)) << 8)) << 8);
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v9;
      v10 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v11 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v10 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v10[1] = v11;
      alphaa = &m_pMeshBuilder->m_VertexBuilder;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v12 = pos->z;
      v13 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v14 = pos->y + size;
      *v13 = pos->x - size;
      v13[1] = v14;
      v13[2] = v12;
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v9;
      v15 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v16 = pDraw->m_pSubTexture->m_tCoordMins[1];
      *v15 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v15[1] = v16;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v17 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v18 = pos->z;
      v19 = pos->y + size;
      m_pCurrColor = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v17 = pos->x + size;
      v17[1] = v19;
      v17[2] = v18;
      *m_pCurrColor = v9;
      v21 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v22 = pDraw->m_pSubTexture->m_tCoordMins[1];
      *v21 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v21[1] = v22;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v23 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v24 = pos->z;
      v25 = pos->y - size;
      v26 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v23 = pos->x + size;
      v23[1] = v25;
      v23[2] = v24;
      *v26 = v9;
      v27 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v28 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v27 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v27[1] = v28;
      CVertexBuilder::AdvanceVertex(this: alphaa);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070160
// Name: public: virtual void CDustEffect::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDustEffect::RenderParticles(CDustEffect *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // edx
  Particle *m_pNext; // ecx
  Particle *i; // esi
  float v6; // xmm0_4
  __m128 x_low; // xmm0
  __m128d v8; // xmm0
  __m128i v9; // xmm0
  double v10; // xmm0_8
  CParticleMgr *v11; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  C_Func_Dust *m_pDust; // ecx
  float v16; // xmm4_4
  float v17; // xmm0_4
  __m128i v18; // xmm2
  float v19; // xmm0_4
  unsigned __int8 *v20; // eax
  float v21; // xmm1_4
  float size; // xmm2_4
  int g; // ecx
  float v24; // xmm0_4
  int v25; // edx
  int v26; // eax
  Vector tPos; // [esp+10h] [ebp-20h] BYREF
  Vector color; // [esp+1Ch] [ebp-14h] BYREF
  float sortKey; // [esp+28h] [ebp-8h]
  float flAlpha; // [esp+2Ch] [ebp-4h]

  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur; i != nullptr; i = (Particle *)CParticleRenderIterator::GetNext(
                                                                 this: pIterator,
                                                                 sortKey) )
    {
      if ( (this->m_pDust->m_DustFlags & 4) != 0 )
      {
        v6 = 1.0;
      }
      else
      {
        x_low = (__m128)LODWORD(i[1].m_Pos.x);
        x_low.m128_f32[0] = x_low.m128_f32[0] / i[1].m_Pos.y;
        v8 = _mm_cvtps_pd(x_low);
        v8.m128d_f64[0] = v8.m128d_f64[0] * 3.141592653589793 * 2.0;
        v9 = (__m128i)_mm_cvtpd_ps(v8);
        *(double *)v9.m128i_i64 = *(float *)v9.m128i_i32 - 1.570796326794897;
        __libm_sse2_sin(X: v9);
        v6 = (v10 + 1.0) * 0.5;
      }
      flAlpha = v6;
      v11 = ParticleMgr();
      y = i->m_Pos.y;
      x = i->m_Pos.x;
      z = i->m_Pos.z;
      m_pDust = this->m_pDust;
      v16 = v11->m_mModelView.m[1][1];
      tPos.x = (float)((float)((float)(v11->m_mModelView.m[0][1] * y) + (float)(v11->m_mModelView.m[0][0] * x))
                     + (float)(v11->m_mModelView.m[0][2] * z))
             + v11->m_mModelView.m[0][3];
      tPos.y = (float)((float)((float)(v11->m_mModelView.m[1][0] * x) + (float)(v16 * y))
                     + (float)(v11->m_mModelView.m[1][2] * z))
             + v11->m_mModelView.m[1][3];
      v17 = (float)(v11->m_mModelView.m[2][0] * x) + (float)(v11->m_mModelView.m[2][1] * y);
      v18 = _mm_cvtsi32_si128(m_pDust->m_DistMax);
      v19 = (float)(v17 + (float)(v11->m_mModelView.m[2][2] * z)) + v11->m_mModelView.m[2][3];
      sortKey = (float)(int)v19;
      tPos.z = v19;
      if ( _mm_cvtepi32_ps(v18).m128_f32[0] >= (float)-v19 )
      {
        v20 = (unsigned __int8 *)m_pDust;
        v21 = (float)((float)(v19 / (float)m_pDust->m_DistMax) + 1.0) * flAlpha;
        size = i[1].m_Pos.z;
        if ( (m_pDust->m_DustFlags & 2) != 0 )
          size = -(float)(size * v19);
        g = m_pDust->m_Color.g;
        v24 = (float)v20[2432];
        v25 = v20[2434];
        v26 = v20[2435];
        color.x = v24;
        color.y = (float)g;
        color.z = (float)v25;
        RenderParticle_Color255Size(
          pDraw: pIterator->m_pParticleDraw,
          pos: &tPos,
          &color,
          alpha: (float)v26 * v21,
          size);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100703C0
// Name: public: virtual void C_Func_Dust::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_Func_Dust::OnDataChanged(C_Func_Dust *this@<ecx>, int a2@<ebx>, DataUpdateType_t updateType)
{
  C_Func_Dust *v3; // edi
  char *p_m_fNextEvent; // esi
  const Vector *v5; // eax
  IUniformRandomStream *v6; // ecx
  bool v7; // cc
  int v8; // ebx
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  float *v11; // edi
  float *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  int (__thiscall *v15)(char *); // edx
  float *v16; // eax
  int v17; // edx
  IEngineTrace_vtbl *v18; // edi
  int v19; // eax
  Particle *v20; // edi
  float v21; // xmm1_4
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  double v24; // st7
  IUniformRandomStream *v25; // ecx
  IUniformRandomStream *v26; // ecx
  Particle *v27; // [esp+18h] [ebp-3Ch]
  float v28; // [esp+1Ch] [ebp-38h]
  Vector origin; // [esp+24h] [ebp-30h] BYREF
  float v30; // [esp+30h] [ebp-24h]
  float v31; // [esp+34h] [ebp-20h]
  float v32; // [esp+38h] [ebp-1Ch]
  float v33; // [esp+3Ch] [ebp-18h]
  float v34; // [esp+40h] [ebp-14h]
  float v35; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  float v37; // [esp+4Ch] [ebp-8h]
  C_Func_Dust *v38; // [esp+50h] [ebp-4h]

  v3 = this;
  v38 = this;
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    p_m_fNextEvent = (char *)&v3[-1].m_Spawner.m_fNextEvent;
    v3->m_Effect.m_RefCount = (int)CParticleEffect::GetPMaterial(
                                     this: (CParticleEffect *)&v3->m_FallSpeed,
                                     name: "particle/sparkles");
    v5 = (const Vector *)(*(int (__thiscall **)(float *, int))(LODWORD(v3[-1].m_Spawner.m_fNextEvent) + 300))(
                           a1: &v3[-1].m_Spawner.m_fNextEvent,
                           a2);
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)&v3->m_FallSpeed, vSortOrigin: v5);
    (*(void (__thiscall **)(float *, int))(LODWORD(v3[-1].m_Spawner.m_fNextEvent) + 456))(
      a1: &v3[-1].m_Spawner.m_fNextEvent,
      a2: -996040704);
    if ( (v3->m_DistMax & 4) != 0 )
    {
      v7 = *((_DWORD *)&v3->m_bIsBlurred + 1) <= 0;
      i = 0;
      if ( !v7 )
      {
        do
        {
          v8 = 0;
          if ( nTests > 0 )
          {
            while ( 1 )
            {
              v33 = _RandomFloat(this: v6, a2: 0.0, a3: 1.0);
              v34 = _RandomFloat(this: v9, a2: 0.0, a3: 1.0);
              v35 = _RandomFloat(this: v10, a2: 0.0, a3: 1.0);
              v11 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)p_m_fNextEvent + 292))(a1: p_m_fNextEvent);
              v12 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)p_m_fNextEvent + 296))(a1: p_m_fNextEvent);
              v13 = (float)(v12[1] - v11[1]) * v34;
              v14 = (float)(v12[2] - v11[2]) * v35;
              v15 = *(int (__thiscall **)(char *))(*(_DWORD *)p_m_fNextEvent + 292);
              v30 = (float)(*v12 - *v11) * v33;
              v31 = v13;
              v32 = v14;
              v16 = (float *)v15(a1: p_m_fNextEvent);
              v17 = *(_DWORD *)p_m_fNextEvent;
              origin.x = *v16 + v30;
              origin.y = v16[1] + v31;
              origin.z = v16[2] + v32;
              v18 = enginetrace->__vftable;
              v19 = (*(int (__thiscall **)(char *, Vector *))(v17 + 12))(a1: p_m_fNextEvent, a2: &origin);
              if ( (((int (__thiscall *)(IEngineTrace *, int))v18->GetPointContents_Collideable)(
                      a1: enginetrace,
                      a2: v19)
                  & 1) != 0 )
                break;
              if ( ++v8 >= nTests )
                goto LABEL_13;
            }
            v20 = CParticleEffect::AddParticle(
                    this: (CParticleEffect *)(p_m_fNextEvent + 2472),
                    particleSize: 0xAu,
                    material: *((CParticleSubTexture **)p_m_fNextEvent + 682),
                    &origin);
            if ( v20 != nullptr )
            {
              v21 = (float)*((int *)p_m_fNextEvent + 612);
              v37 = (float)-*((_DWORD *)p_m_fNextEvent + 612);
              _RandomFloat(this: v6, a2: v37, a3: v21);
              v28 = _RandomFloat(this: v22, a2: v37, a3: v21);
              v24 = _RandomFloat(this: v23, a2: v37, a3: v21);
              v20[1].m_pPrev = v27;
              *(float *)&v20[1].m_pNext = v28;
              *(float *)&v20[1].m_pSubTexture = v24;
              *(float *)&v20[1].m_pSubTexture = *(float *)&v20[1].m_pSubTexture - *((float *)p_m_fNextEvent + 616);
              v20[1].m_Pos.x = 0.0;
              v20[1].m_Pos.y = _RandomFloat(
                                 this: v25,
                                 a2: (float)*((int *)p_m_fNextEvent + 613),
                                 a3: (float)*((int *)p_m_fNextEvent + 614));
              if ( (p_m_fNextEvent[2468] & 2) != 0 )
              {
                v31 = *((float *)p_m_fNextEvent + 611) * 0.000099999997;
                v30 = *((float *)p_m_fNextEvent + 610) * 0.000099999997;
              }
              else
              {
                v31 = *((float *)p_m_fNextEvent + 611);
                v30 = *((float *)p_m_fNextEvent + 610);
              }
              v20[1].m_Pos.z = _RandomFloat(this: v26, a2: v30, a3: v31);
              v20[2].m_pPrev = *((Particle **)p_m_fNextEvent + 608);
            }
LABEL_13:
            v3 = v38;
          }
          ++i;
        }
        while ( i < *((_DWORD *)&v3->m_bIsBlurred + 1) );
      }
    }
  }
  *(float *)&v3->m_Effect.m_pDust = 1.0 / (float)*((int *)&v3->m_bIsBlurred + 1);
  v3->m_hMaterial = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10070730
// Name: public: virtual void C_Func_Dust::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Func_Dust::ClientThink(C_Func_Dust *this)
{
  int m_LifetimeMax; // eax
  float v3; // xmm0_4
  C_Func_Dust *m_pDust; // xmm1_4
  float v5; // xmm0_4
  Vector vWorldMins; // [esp+4h] [ebp-1Ch] BYREF
  Vector vWorldMaxs; // [esp+10h] [ebp-10h] BYREF
  float flDelta; // [esp+1Ch] [ebp-4h]

  m_LifetimeMax = this->m_LifetimeMax;
  if ( (m_LifetimeMax & 4) == 0 )
  {
    if ( (m_LifetimeMax & 1) != 0 )
    {
      v3 = *(float *)(gpGlobals.m_Index + 16);
      if ( v3 >= 0.1 )
        v3 = 0.1;
      while ( 1 )
      {
        m_pDust = this->m_Effect.m_pDust;
        if ( v3 < *(float *)&m_pDust )
          break;
        this->m_Effect.m_pDust = (C_Func_Dust *)this->m_Effect.m_RefCount;
        flDelta = v3 - *(float *)&m_pDust;
        C_Func_Dust::AttemptSpawnNewParticle(this: (C_Func_Dust *)((char *)this - 12));
        v3 = v3 - *(float *)&m_pDust;
      }
      *(float *)&this->m_Effect.m_pDust = *(float *)&this->m_Effect.m_pDust - v3;
    }
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: (CCollisionProperty *)&this->m_pMovePrevPeer,
      entityMins: (const Vector *)&this->m_ModelName,
      entityMaxs: &this->m_Collision.m_vecMins.m_Value,
      pWorldMins: &vWorldMins,
      pWorldMaxs: &vWorldMaxs);
    v5 = *(float *)&this->m_Color;
    vWorldMins.x = vWorldMins.x - v5;
    vWorldMins.z = vWorldMins.z - v5;
    vWorldMins.y = vWorldMins.y - v5;
    vWorldMaxs.y = vWorldMaxs.y + v5;
    vWorldMaxs.x = vWorldMaxs.x + v5;
    vWorldMaxs.z = vWorldMaxs.z + v5;
    CParticleEffectBinding::SetBBox(
      this: (CParticleEffectBinding *)&this->m_DustFlags,
      bbMin: &vWorldMins,
      bbMax: &vWorldMaxs,
      bDisableAutoUpdate: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070850
// Name: void FX_Dust(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_Dust(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *vecOrigin,
        const Vector *vecDirection,
        float flSize,
        float flSpeed)
{
  int v7; // eax
  float v8; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  IUniformRandomStream *v14; // ecx
  int v15; // ebx
  float v16; // xmm0_4
  float v17; // xmm1_4
  IUniformRandomStream *v18; // ecx
  IUniformRandomStream *v19; // ecx
  float v20; // xmm3_4
  float z; // xmm2_4
  float v22; // xmm1_4
  float y; // xmm1_4
  int v24; // eax
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  int v26; // eax
  SimpleParticle particle; // [esp+54h] [ebp-60h] BYREF
  Vector worldLight; // [esp+90h] [ebp-24h] BYREF
  Vector offset; // [esp+9Ch] [ebp-18h] BYREF
  float v32; // [esp+A8h] [ebp-Ch]
  float v33; // [esp+ACh] [ebp-8h]
  int numPuffs; // [esp+B0h] [ebp-4h]
  const Vector *vecOrigina; // [esp+BCh] [ebp+8h]
  float vecDirectiona; // [esp+C0h] [ebp+Ch]
  float speed; // [esp+C8h] [ebp+14h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Dust",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v7 = (int)(float)(flSize * 0.5);
  numPuffs = v7;
  if ( v7 >= 1 )
  {
    if ( v7 > 32 )
      numPuffs = 32;
  }
  else
  {
    numPuffs = 1;
  }
  v8 = flSpeed * 0.1;
  speed = flSpeed * 0.1;
  if ( speed >= 0.0 )
  {
    if ( v8 > 48.0 )
      speed = 48.0;
  }
  else
  {
    speed = 1.0;
  }
  v11 = vecDirection->z * flSize;
  v12 = vecOrigin->x + (float)(vecDirection->x * flSize);
  offset.y = vecOrigin->y + (float)(vecDirection->y * flSize);
  v13 = vecOrigin->z + v11;
  offset.x = v12;
  offset.z = v13;
  ((void (__thiscall *)(IVEngineClient *, Vector *, Vector *, int, int, int, int))engine->GetLightForPoint)(
    a1: engine,
    a2: &worldLight,
    a3: &offset,
    a4: 1,
    a5: a2,
    a6: a3,
    a7: a1);
  v15 = 0;
  particle.m_iFlags = 0;
  if ( numPuffs > 0 )
  {
    v16 = flSize * 0.25;
    LODWORD(v17) = COERCE_UNSIGNED_INT(flSize * 0.25) ^ _mask__NegFloat_;
    vecDirectiona = flSize * 0.25;
    vecOrigina = (const Vector *)LODWORD(v17);
    v33 = speed * 0.5;
    while ( 1 )
    {
      offset.x = _RandomFloat(this: v14, a2: v17, a3: v16);
      offset.y = _RandomFloat(this: v18, a2: *(float *)&vecOrigina, a3: vecDirectiona);
      offset.z = _RandomFloat(this: v19, a2: *(float *)&vecOrigina, a3: vecDirectiona);
      v20 = vecDirection->z * flSize;
      z = vecOrigin->z;
      v22 = (float)(vecOrigin->y + (float)(vecDirection->y * flSize)) + offset.y;
      offset.x = (float)(vecOrigin->x + (float)(vecDirection->x * flSize)) + offset.x;
      particle.m_Pos.x = offset.x;
      particle.m_flLifetime = 0.0;
      offset.y = v22;
      offset.z = (float)(z + v20) + offset.z;
      particle.m_Pos.y = v22;
      particle.m_Pos.z = offset.z;
      particle.m_flDieTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1053609165,
                               a3: 1065353216);
      v32 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
              a1: random,
              a2: LODWORD(v33),
              a3: LODWORD(speed));
      y = vecDirection->y;
      particle.m_vecVelocity.x = (float)(vecDirection->x * v32) * (float)v15;
      particle.m_vecVelocity.y = (float)(y * v32) * (float)v15;
      particle.m_vecVelocity.z = 0.0;
      v24 = random->RandomInt(this: random, a2: 48, a3: 64);
      particle.m_uchColor[2] = (int)(float)((float)((float)v24 * worldLight.z) + (float)v24);
      particle.m_uchColor[1] = (int)(float)((float)((float)v24 * worldLight.y) + (float)(v24 + 8));
      particle.m_uchColor[0] = (int)(float)((float)((float)v24 * worldLight.x) + (float)(v24 + 16));
      particle.m_uchStartAlpha = random->RandomInt(this: random, a2: 64, a3: 128);
      particle.m_uchEndAlpha = 0;
      particle.m_uchStartSize = random->RandomInt(this: random, a2: 2, a3: 8);
      particle.m_uchEndSize = random->RandomInt(this: random, a2: 24, a3: 48);
      particle.m_flRoll = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      particle.m_flRollDelta = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: -1090519040,
                                 a3: 1056964608);
      RandomInt = random->RandomInt;
      particle.m_pNext = nullptr;
      particle.m_pPrev = (Particle *)1;
      v26 = ((int (__thiscall *)(IUniformRandomStream *))RandomInt)(a1: random);
      AddSimpleParticle(pParticle: &particle, hMaterial: g_Mat_DustPuff[v26], bInSkybox: false);
      if ( ++v15 >= numPuffs )
        break;
      LODWORD(v17) = COERCE_UNSIGNED_INT(flSize * 0.25) ^ _mask__NegFloat_;
      v16 = flSize * 0.25;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10070C20
// Name: public: virtual void C_TEDust::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TEDust::PostDataUpdate(
        C_TEDust *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        DataUpdateType_t updateType)
{
  FX_Dust(
    a1: a2,
    a2: a3,
    a3: a4,
    vecOrigin: (const Vector *)&this->m_pNextDynamic,
    vecDirection: (const Vector *)&this->m_flSpeed,
    flSize: this->m_vecOrigin.z,
    flSpeed: this->m_flSize);
}

//------------------------------------------------------------------------------
// Address: 0x10070C50
// Name: void TE_Dust(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_Dust(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        float size,
        float speed)
{
  FX_Dust(a1, a2, a3, vecOrigin: pos, vecDirection: dir, flSize: size, flSpeed: speed);
}

//------------------------------------------------------------------------------
// Address: 0x10412120
// Name: DT_Func_Dust::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_Dust::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Func_Dust::g_RecvTable);
  return atexit(func: DT_Func_Dust::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412140
// Name: DT_Func_Dust::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Func_Dust::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Func_Dust::ignored>();
  DT_Func_Dust::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104121A0
// Name: DT_TEDust::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDust::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEDust::g_RecvTable);
  return atexit(func: DT_TEDust::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104121C0
// Name: DT_TEDust::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDust::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEDust::ignored>();
  DT_TEDust::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104302F0
// Name: DT_Func_Dust::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Func_Dust::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Func_Dust::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430300
// Name: DT_TEDust::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDust::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEDust::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1006F890
// Name: _C_TEDust_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEDust_CreateObject()
{
  return &_g_C_TEDust.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10070110
// Name: _C_Func_Dust_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Func_Dust_CreateObject(int entnum, int serialNum)
{
  C_Func_Dust *v2; // eax
  C_Func_Dust *v3; // eax
  C_Func_Dust *v4; // esi

  v2 = (C_Func_Dust *)C_BaseEntity::operator new(stAllocateBlock: 0xAB8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Func_Dust::C_Func_Dust(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412150
// Name: _dynamic_initializer_for____g_C_TEDust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEDust__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TEDust);
  _g_C_TEDust.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDust_vtbl *)&C_TEDust::`vftable'{for `IClientUnknown'};
  _g_C_TEDust.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDust::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEDust__);
}

//------------------------------------------------------------------------------
// Address: 0x10412180
// Name: _dynamic_initializer_for____g_C_TEDustClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEDustClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEDustClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEDustClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104121D0
// Name: _dynamic_initializer_for____g_C_Func_LODClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_Func_LODClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_Func_LODClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_Func_LODClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430310
// Name: _dynamic_atexit_destructor_for____g_C_TEDust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEDust__()
{
  _g_C_TEDust.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDust_vtbl *)&C_TEDust::`vftable'{for `IClientUnknown'};
  _g_C_TEDust.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDust::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEDust);
}
