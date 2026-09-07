// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_steamjet.cpp
// Functions: 18
// ============================================================

#include "game\client\c_steamjet.h"

//------------------------------------------------------------------------------
// Address: 0x10251160
// Name: public: virtual class ClientClass __near * C_SteamJet::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SteamJet::GetClientClass(C_SteamJet *this)
{
  return &__g_C_SteamJetClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10251320
// Name: public: virtual C_SteamJet::~C_SteamJet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::~C_SteamJet(C_SteamJet *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SteamJet_vtbl *)&C_SteamJet::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SteamJet::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SteamJet::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SteamJet::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SteamJet::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SteamJet::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SteamJet::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10251390
// Name: public: virtual void C_SteamJet::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::OnDataChanged(C_SteamJet *this, DataUpdateType_t updateType)
{
  int v3; // ebx
  CParticleMgr *v4; // eax
  float m_Speed; // xmm1_4
  float flMaxParticleRadius; // xmm0_4

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = *(_DWORD *)&this->m_bSimulate;
    v4 = ParticleMgr();
    (*(void (__thiscall **)(bool *, CParticleMgr *, _DWORD))(v3 + 4))(a1: &this->m_bSimulate, a2: v4, a3: 0);
  }
  m_Speed = this->m_Speed;
  this->m_vLastRampUpdateAngles.y = this->m_EndSize / *(float *)&this->IPrototypeAppEffect::__vftable;
  flMaxParticleRadius = this->m_SpreadSpeed;
  if ( flMaxParticleRadius <= m_Speed )
    flMaxParticleRadius = m_Speed;
  CParticleEffectBinding::SetParticleCullRadius(
    this: (CParticleEffectBinding *)(&this->m_bIsBlurred + 4),
    flMaxParticleRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10251410
// Name: public: virtual bool C_SteamJet::GetPropEditInfo(class RecvTable __near * __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_SteamJet::GetPropEditInfo(C_SteamJet *this, RecvTable **ppTable, void **ppObj)
{
  *ppTable = &DT_SteamJet::g_RecvTable;
  *ppObj = (char *)this - 2664;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10251480
// Name: public: C_SteamJet::C_SteamJet(void)
// Source: json
//------------------------------------------------------------------------------
C_SteamJet *__thiscall C_SteamJet::C_SteamJet(C_SteamJet *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SteamJet_vtbl *)&C_SteamJet::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SteamJet::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SteamJet::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SteamJet::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SteamJet::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SteamJet::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SteamJet::`vftable';
  this->m_ParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  this->m_SpreadSpeed = 15.0;
  this->m_Speed = 120.0;
  this->m_StartSize = 10.0;
  this->m_EndSize = 25.0;
  this->m_Rate = 26.0;
  this->m_JetLength = 80.0;
  this->m_bEmit = 1;
  this->m_pParticleMgr = nullptr;
  this->m_MaterialHandle = nullptr;
  this->m_bFaceLeft = false;
  this->m_ParticleEffect.m_Flags &= ~0x10u;
  this->m_vLastRampUpdatePos.x = 1.0e24;
  this->m_vLastRampUpdatePos.y = 1.0e24;
  this->m_vLastRampUpdatePos.z = 1.0e24;
  this->m_vLastRampUpdateAngles.x = 1.0e24;
  this->m_vLastRampUpdateAngles.y = 1.0e24;
  this->m_vLastRampUpdateAngles.z = 1.0e24;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102515B0
// Name: void RenderParticle_ColorSizePerturbNormal(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_ColorSizePerturbNormal(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size)
{
  IUniformRandomStream *v5; // ecx
  CMeshBuilder *m_pMeshBuilder; // esi
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float *m_pCurrPosition; // eax
  float z; // xmm2_4
  float v11; // xmm0_4
  int v12; // ebx
  float *m_pCurrNormal; // eax
  float *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm2_4
  float *v17; // eax
  _DWORD *m_pCurrColor; // edx
  float *v19; // eax
  float *v20; // eax
  float v21; // xmm2_4
  float *v22; // eax
  float v23; // xmm0_4
  float *v24; // eax
  float *v25; // eax
  float v26; // xmm2_4
  float *v27; // eax
  float v28; // xmm0_4
  _DWORD *v29; // ecx
  float *v30; // eax
  float *v31; // esi
  int vNorm; // [esp+14h] [ebp-1Ch]
  float vNorm_4; // [esp+18h] [ebp-18h]
  float vNorm_8; // [esp+1Ch] [ebp-14h]
  int v35; // [esp+24h] [ebp-Ch]
  int v36; // [esp+28h] [ebp-8h]
  int v37; // [esp+2Ch] [ebp-4h]
  CVertexBuilder *alphaa; // [esp+44h] [ebp+14h]

  if ( alpha >= 0.001 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      v37 = (int)(float)(color->x * 254.89999);
      v36 = (int)(float)(color->y * 254.89999);
      v35 = (int)(float)(color->z * 254.89999);
      _RandomFloat(this: v5, a2: -1.0, a3: 1.0);
      vNorm_4 = _RandomFloat(this: v7, a2: -1.0, a3: 1.0);
      vNorm_8 = _RandomFloat(this: v8, a2: -1.0, a3: 1.0);
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      z = pos->z;
      v11 = pos->y - size;
      *m_pCurrPosition = pos->x - size;
      m_pCurrPosition[1] = v11;
      m_pCurrPosition[2] = z;
      v12 = (unsigned __int8)v35
          | (((unsigned __int8)v36
            | (((unsigned __int8)v37 | ((unsigned __int8)(int)(float)(alpha * 254.89999) << 8)) << 8)) << 8);
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v12;
      m_pCurrNormal = m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *(_DWORD *)m_pCurrNormal = vNorm;
      m_pCurrNormal[1] = vNorm_4;
      m_pCurrNormal[2] = vNorm_8;
      v14 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v14 = 0.0;
      v14[1] = 1.0;
      alphaa = &m_pMeshBuilder->m_VertexBuilder;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v15 = pos->y + size;
      v16 = pos->z;
      v17 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      m_pCurrColor = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v17 = pos->x - size;
      v17[1] = v15;
      v17[2] = v16;
      *m_pCurrColor = v12;
      v19 = m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *(_DWORD *)v19 = vNorm;
      v19[1] = vNorm_4;
      v19[2] = vNorm_8;
      v20 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v20 = 0.0;
      v20[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v21 = pos->z;
      v22 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v23 = pos->y + size;
      *v22 = pos->x + size;
      v22[1] = v23;
      v22[2] = v21;
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v12;
      v24 = m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *(_DWORD *)v24 = vNorm;
      v24[1] = vNorm_4;
      v24[2] = vNorm_8;
      v25 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v25 = 1.0;
      v25[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v26 = pos->z;
      v27 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v28 = pos->y - size;
      v29 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v27 = pos->x + size;
      v27[1] = v28;
      v27[2] = v26;
      *v29 = v12;
      v30 = m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      v31 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)v30 = vNorm;
      v30[1] = vNorm_4;
      v30[2] = vNorm_8;
      *v31 = 1.0;
      v31[1] = 1.0;
      CVertexBuilder::AdvanceVertex(this: alphaa);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102518B0
// Name: public: virtual void C_SteamJet::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::RenderParticles(C_SteamJet *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  float *v7; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  __m128 v19; // xmm0
  bool v20; // zf
  double v21; // xmm0_8
  ParticleDraw *m_pParticleDraw; // esi
  unsigned __int8 RenderAlpha; // al
  float v24; // xmm0_4
  unsigned __int8 v25; // al
  float size; // [esp+8h] [ebp-30h]
  float sizea; // [esp+8h] [ebp-30h]
  Vector tPos; // [esp+18h] [ebp-20h] BYREF
  Vector vRampColor; // [esp+24h] [ebp-14h] BYREF
  ParticleDraw *pDraw; // [esp+30h] [ebp-8h]
  float sinLifetime; // [esp+34h] [ebp-4h]
  float pIteratora; // [esp+40h] [ebp+8h]

  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur;
          i != nullptr;
          i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: tPos.z) )
    {
      v7 = *(float **)&this->m_iName[40];
      y = i->m_Pos.y;
      x = i->m_Pos.x;
      z = i->m_Pos.z;
      v11 = v7[30];
      tPos.x = (float)((float)((float)(v7[26] * y) + (float)(x * v7[25])) + (float)(v7[27] * z)) + v7[28];
      v12 = *(float *)&i[2].m_pPrev;
      tPos.y = (float)((float)((float)(v7[29] * x) + (float)(v11 * y)) + (float)(v7[31] * z)) + v7[32];
      tPos.z = (float)((float)((float)(v7[33] * x) + (float)(v7[34] * y)) + (float)(v7[35] * z)) + v7[36];
      pIteratora = i[1].m_Pos.z;
      v13 = pIteratora / (v12 + 0.001);
      v14 = v13 * 4.0;
      v15 = (int)v14;
      v16 = v14 - (float)(int)v14;
      v15 *= 3;
      v17 = *(&this->m_flFriction + v15)
          + (float)((float)(*((float *)&this->m_hGroundEntity.m_Index + v15) - *(&this->m_flFriction + v15)) * v16);
      v18 = *((float *)&this->m_hNetworkMoveParent.m_Index + v15)
          + (float)((float)(*(float *)&this->m_iName[4 * v15] - *((float *)&this->m_hNetworkMoveParent.m_Index + v15))
                  * v16);
      vRampColor.x = *(&this->m_vecNetworkOrigin.z + v15)
                   + (float)((float)(*((float *)&this->m_hOwnerEntity.m_Index + v15)
                                   - *(&this->m_vecNetworkOrigin.z + v15))
                           * v16);
      vRampColor.y = v17;
      vRampColor.z = v18;
      if ( vRampColor.x > 1.0 )
        vRampColor.x = 1.0;
      if ( v17 > 1.0 )
        vRampColor.y = 1.0;
      if ( v18 > 1.0 )
        vRampColor.z = 1.0;
      v19 = (__m128)LODWORD(pIteratora);
      v19.m128_f32[0] = (float)(pIteratora * 3.1415901) / v12;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v19));
      v20 = LODWORD(this->m_vecVelocity.x) == 1;
      *(float *)&v21 = v21;
      sinLifetime = *(float *)&v21;
      if ( v20 )
      {
        m_pParticleDraw = pIterator->m_pParticleDraw;
        size = (float)((float)(*(float *)&this->m_fFlags - *(float *)&this->m_iHealth) * pIteratora)
             + *(float *)&this->m_iHealth;
        RenderAlpha = C_BaseEntity::GetRenderAlpha(this: (C_SteamJet *)((char *)this - 2432));
        RenderParticle_ColorSizePerturbNormal(
          pDraw: m_pParticleDraw,
          pos: &tPos,
          color: &vRampColor,
          alpha: (float)((float)RenderAlpha * 0.0039215689) * sinLifetime,
          size);
      }
      else
      {
        v24 = (float)((float)((float)BYTE1(i[2].m_pNext) - (float)LOBYTE(i[2].m_pNext)) * pIteratora)
            + (float)LOBYTE(i[2].m_pNext);
        sizea = i[1].m_Pos.x;
        pDraw = pIterator->m_pParticleDraw;
        v25 = C_BaseEntity::GetRenderAlpha(this: (C_SteamJet *)((char *)this - 2432));
        RenderParticle_ColorSizeAngle(
          pDraw,
          pos: &tPos,
          color: &vRampColor,
          alpha: (float)((float)v25 * 0.0039215689) * sinLifetime,
          size: v24,
          angle: sizea);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251BB0
// Name: public: virtual void C_SteamJet::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::SimulateParticles(C_SteamJet *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  bool i; // zf
  float m_flTimeDelta; // xmm0_4
  float v6; // xmm0_4
  bool v7; // cc
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  if ( (LOBYTE(this->m_vecAbsVelocity.z) & 0x40) != 0 || LODWORD(this->m_vecViewOffset.z) == 0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    for ( i = m_pNext == &m_pMaterial->m_Particles; !i; i = m_pNext == &pIterator->m_pMaterial->m_Particles )
    {
      m_flTimeDelta = pIterator->m_flTimeDelta;
      pIterator->m_pNextParticle = m_pNext->m_pNext;
      v6 = m_flTimeDelta + m_pNext[1].m_Pos.z;
      v7 = v6 <= *(float *)&m_pNext[2].m_pPrev;
      m_pNext[1].m_Pos.z = v6;
      if ( v7 )
      {
        m_pNext[1].m_Pos.x = (float)(m_pNext[1].m_Pos.y * pIterator->m_flTimeDelta) + m_pNext[1].m_Pos.x;
        v8 = pIterator->m_flTimeDelta;
        v9 = (float)(*(float *)&m_pNext[1].m_pNext * v8) + m_pNext->m_Pos.y;
        v10 = (float)(*(float *)&m_pNext[1].m_pSubTexture * v8) + m_pNext->m_Pos.z;
        m_pNext->m_Pos.x = m_pNext->m_Pos.x + (float)(*(float *)&m_pNext[1].m_pPrev * v8);
        m_pNext->m_Pos.y = v9;
        m_pNext->m_Pos.z = v10;
      }
      else
      {
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      }
      m_pNext = pIterator->m_pNextParticle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10251C80
// Name: private: void C_SteamJet::UpdateLightingRamp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::UpdateLightingRamp(C_SteamJet *this)
{
  const Vector *v2; // eax
  const QAngle *v3; // eax
  const Vector *v4; // eax
  const QAngle *v5; // eax
  const QAngle *v6; // eax
  const Vector *v7; // eax
  __int64 v8; // xmm0_8
  float z; // ecx
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // eax
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // ebx
  float *p_z; // edi
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm4_4
  int v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  Vector up; // [esp+4h] [ebp-54h] BYREF
  _DWORD v31[3]; // [esp+10h] [ebp-48h] BYREF
  Vector vTestPos; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector temp; // [esp+28h] [ebp-30h]
  Vector right; // [esp+34h] [ebp-24h] BYREF
  Vector startPos; // [esp+40h] [ebp-18h]
  Vector forward; // [esp+4Ch] [ebp-Ch] BYREF

  v2 = this->GetAbsOrigin(this);
  if ( fabs(this->m_vLastRampUpdatePos.x - v2->x) > 0.1
    || fabs(this->m_vLastRampUpdatePos.y - v2->y) > 0.1
    || fabs(this->m_vLastRampUpdatePos.z - v2->z) > 0.1
    || (v3 = this->GetAbsAngles(this), fabs(this->m_vLastRampUpdateAngles.x - v3->x) > 0.1)
    || fabs(this->m_vLastRampUpdateAngles.y - v3->y) > 0.1
    || fabs(this->m_vLastRampUpdateAngles.z - v3->z) > 0.1 )
  {
    v4 = this->GetAbsOrigin(this);
    this->m_vLastRampUpdatePos.x = v4->x;
    this->m_vLastRampUpdatePos.y = v4->y;
    this->m_vLastRampUpdatePos.z = v4->z;
    v5 = this->GetAbsAngles(this);
    this->m_vLastRampUpdateAngles.x = v5->x;
    this->m_vLastRampUpdateAngles.y = v5->y;
    this->m_vLastRampUpdateAngles.z = v5->z;
    v6 = this->GetAbsAngles(this);
    AngleVectors(angles: v6, &forward, &right, &up);
    if ( this->m_bFaceLeft )
    {
      temp = forward;
      forward.x = -right.x;
      forward.y = -right.y;
      forward.z = -right.z;
      right = temp;
    }
    v7 = this->GetAbsOrigin(this);
    v8 = *(_QWORD *)&v7->x;
    z = v7->z;
    GetAbsOrigin = this->GetAbsOrigin;
    *(_QWORD *)&startPos.x = v8;
    *(float *)&v8 = this->m_Lifetime * this->m_Speed;
    temp.x = forward.x * *(float *)&v8;
    temp.y = forward.y * *(float *)&v8;
    startPos.z = z;
    temp.z = forward.z * *(float *)&v8;
    v11 = (float *)GetAbsOrigin(this);
    v12 = (float)(v11[1] + temp.y) - startPos.y;
    v13 = (float)(v11[2] + temp.z) - startPos.z;
    v14 = 0;
    temp.x = (float)(*v11 + temp.x) - startPos.x;
    temp.y = v12;
    temp.z = v13;
    p_z = &this->m_Ramps[0].z;
    do
    {
      v16 = (float)v14 * 0.25;
      vTestPos.x = (float)(temp.x * v16) + startPos.x;
      vTestPos.y = (float)(temp.y * v16) + startPos.y;
      vTestPos.z = (float)(temp.z * v16) + startPos.z;
      engine->GetLightForPoint(this: engine, result: (Vector *)v31, a3: &vTestPos, a4: false);
      v17 = *(float *)v31;
      v18 = *(float *)&v31[1];
      v19 = *(float *)&v31[2];
      *(p_z - 2) = *(float *)v31;
      *(p_z - 1) = v18;
      *p_z = v19;
      v20 = (float)this->m_clrRender.m_Value.r * 0.0039215689;
      if ( (this->m_spawnflags & 1) != 0 )
      {
        v21 = v20 + v17;
        *(p_z - 2) = v21;
        *(p_z - 1) = (float)((float)this->m_clrRender.m_Value.g * 0.0039215689) + v18;
        v22 = LODWORD(v21);
        *p_z = (float)((float)this->m_clrRender.m_Value.b * 0.0039215689) + v19;
        if ( v21 >= 0.0 )
        {
          if ( v21 > 1.0 )
            v22 = 1065353216;
        }
        else
        {
          v22 = 0;
        }
        *((_DWORD *)p_z - 2) = v22;
        v23 = *(p_z - 1);
        if ( v23 >= 0.0 )
        {
          if ( v23 > 1.0 )
            v23 = 1.0;
        }
        else
        {
          v23 = 0.0;
        }
        *(p_z - 1) = v23;
        v24 = *p_z;
        if ( *p_z >= 0.0 )
        {
          if ( v24 > 1.0 )
            v24 = 1.0;
          *p_z = v24;
        }
        else
        {
          *p_z = 0.0;
        }
      }
      else
      {
        *(p_z - 2) = v20 * v17;
        *(p_z - 1) = (float)((float)this->m_clrRender.m_Value.g * 0.0039215689) * v18;
        *p_z = (float)((float)this->m_clrRender.m_Value.b * 0.0039215689) * v19;
      }
      v25 = *(p_z - 1);
      v26 = *p_z;
      if ( v25 <= *p_z )
        v27 = *p_z;
      else
        v27 = *(p_z - 1);
      v28 = *(p_z - 2);
      if ( v28 <= v27 )
      {
        if ( v25 <= v26 )
          v29 = *p_z;
        else
          v29 = *(p_z - 1);
      }
      else
      {
        v29 = *(p_z - 2);
      }
      if ( v29 > 1.0 )
      {
        *(p_z - 2) = v28 * (float)(1.0 / v29);
        *(p_z - 1) = v25 * (float)(1.0 / v29);
        *p_z = v26 * (float)(1.0 / v29);
      }
      ++v14;
      p_z += 3;
    }
    while ( v14 < 5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102520F0
// Name: public: virtual void C_SteamJet::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::Start(C_SteamJet *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax

  if ( this == (C_SteamJet *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4);
  if ( this->m_VarMap.m_Entries.m_Memory.m_pMemory == (VarMapEntry_t *)1 )
    LODWORD(this->m_vecCellOrigin.z) = CParticleEffectBinding::FindOrAddMaterial(
                                         this: (CParticleEffectBinding *)((char *)this - 228),
                                         pMaterialName: "sprites/heatwave");
  else
    *(float **)&this->m_vecCellOrigin.z = g_Mat_DustPuff[0]->m_tCoordMins;
  this->m_vecAbsVelocity.x = 1.0 / *(float *)&this->m_iClassname;
  this->m_vecAbsVelocity.y = 0.0;
  *((float *)&this->m_pfnThink + 2) = *(float *)&this->m_hScriptInstance
                                    / *(float *)&this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable;
  LODWORD(this->m_vecCellOrigin.y) = pParticleMgr;
  C_SteamJet::UpdateLightingRamp(this: (C_SteamJet *)((char *)this - 2664));
}

//------------------------------------------------------------------------------
// Address: 0x10252190
// Name: public: virtual void C_SteamJet::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SteamJet::Update(C_SteamJet *this, float fTimeDelta)
{
  int i; // esi
  float v5; // xmm1_4
  const QAngle *v6; // eax
  float x; // xmm3_4
  float y; // xmm2_4
  float v9; // xmm1_4
  float z; // xmm0_4
  int m_nNextThinkTick; // xmm0_4
  int (__thiscall *v12)(char *); // eax
  float *v13; // eax
  int v14; // edx
  float v15; // xmm0_4
  int (__thiscall *v16)(char *); // eax
  float *v17; // eax
  double v18; // xmm0_8
  float v19; // xmm0_4
  double v20; // xmm0_8
  float v21; // xmm0_4
  double v22; // xmm0_8
  int (__thiscall *v23)(char *); // eax
  float *v24; // eax
  double v25; // xmm0_8
  float v26; // xmm0_4
  double v27; // xmm0_8
  float v28; // xmm0_4
  double v29; // xmm0_8
  Particle *v30; // esi
  float *v31; // eax
  int v32; // xmm0_4
  IUniformRandomStream *v33; // ecx
  double v34; // st7
  int m_iTeamNum; // xmm1_4
  IUniformRandomStream *v36; // ecx
  double v37; // st7
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  Vector up; // [esp+14h] [ebp-58h] BYREF
  Vector vMin; // [esp+20h] [ebp-4Ch] BYREF
  Vector vMax; // [esp+2Ch] [ebp-40h] BYREF
  Vector temp; // [esp+38h] [ebp-34h]
  Vector vEndPoint; // [esp+44h] [ebp-28h]
  Vector right; // [esp+50h] [ebp-1Ch] BYREF
  Vector forward; // [esp+5Ch] [ebp-10h] BYREF
  float v49; // [esp+68h] [ebp-4h]
  int nToEmit; // [esp+74h] [ebp+8h]

  if ( *(_DWORD *)&this->m_iName[40] != 0 && LODWORD(this->m_vecViewOffset.z) != 0 )
  {
    for ( i = 0; ; ++i )
    {
      v5 = *(float *)&this->m_iName[52];
      if ( fTimeDelta < v5 )
        break;
      fTimeDelta = fTimeDelta - v5;
      *(float *)&this->m_iName[52] = *(float *)&this->m_iName[48];
    }
    *(float *)&this->m_iName[52] = *(float *)&this->m_iName[52] - fTimeDelta;
    if ( i > 0 )
    {
      v6 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 44))(a1: (char *)this - 2432);
      AngleVectors(angles: v6, &forward, &right, &up);
      if ( LOBYTE(this->m_vecVelocity.y) != 0 )
      {
        temp = forward;
        x = -right.x;
        y = -right.y;
        v9 = -right.z;
        *(_QWORD *)&right.x = *(_QWORD *)&forward.x;
        z = forward.z;
        forward.x = x;
        forward.y = y;
        forward.z = -right.z;
        right.z = z;
      }
      else
      {
        v9 = forward.z;
        y = forward.y;
        x = forward.x;
      }
      m_nNextThinkTick = this->m_nNextThinkTick;
      v12 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
      temp.x = x * *(float *)&m_nNextThinkTick;
      temp.y = y * *(float *)&m_nNextThinkTick;
      temp.z = v9 * *(float *)&m_nNextThinkTick;
      v13 = (float *)v12(a1: (char *)this - 2432);
      v14 = *((_DWORD *)this - 608);
      vEndPoint.x = *v13 + temp.x;
      vEndPoint.y = v13[1] + temp.y;
      v15 = v13[2] + temp.z;
      v16 = *(int (__thiscall **)(char *))(v14 + 40);
      vEndPoint.z = v15;
      v17 = (float *)v16(a1: (char *)this - 2432);
      v18 = *v17;
      if ( v18 > vEndPoint.x )
        v18 = vEndPoint.x;
      v19 = v18;
      vMin.x = v19;
      v20 = v17[1];
      if ( v20 > vEndPoint.y )
        v20 = vEndPoint.y;
      v21 = v20;
      vMin.y = v21;
      v22 = v17[2];
      if ( v22 > vEndPoint.z )
        v22 = vEndPoint.z;
      v23 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
      vMin.z = v22;
      v24 = (float *)v23(a1: (char *)this - 2432);
      v25 = *v24;
      if ( v25 < vEndPoint.x )
        v25 = vEndPoint.x;
      v26 = v25;
      vMax.x = v26;
      v27 = v24[1];
      if ( v27 < vEndPoint.y )
        v27 = vEndPoint.y;
      v28 = v27;
      vMax.y = v28;
      v29 = v24[2];
      if ( v29 < vEndPoint.z )
        v29 = vEndPoint.z;
      vMax.z = v29;
      CParticleEffectBinding::SetBBox(
        this: (CParticleEffectBinding *)&this->IClientRenderable,
        bbMin: &vMin,
        bbMax: &vMax,
        bDisableAutoUpdate: true);
      if ( (LOBYTE(this->m_vecAbsVelocity.z) & 0x40) != 0 )
      {
        while ( 1 )
        {
          nToEmit = i - 1;
          v30 = CParticleEffectBinding::AddParticle(
                  this: (CParticleEffectBinding *)&this->IClientRenderable,
                  a2: i - 1,
                  sizeInBytes: 56,
                  hMaterial: *(CParticleSubTexture **)&this->m_iName[44]);
          if ( v30 != nullptr )
          {
            v31 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
            v30->m_Pos.x = *v31;
            v30->m_Pos.y = v31[1];
            v30->m_Pos.z = v31[2];
            v32 = this->m_nNextThinkTick;
            vEndPoint.x = *(float *)&v32 * forward.x;
            vEndPoint.y = forward.y * *(float *)&v32;
            vEndPoint.z = forward.z * *(float *)&v32;
            v34 = _RandomFloat(
                    this: v33,
                    a2: COERCE_FLOAT(this->m_iTeamNum ^ _mask__NegFloat_),
                    a3: *(float *)&this->m_iTeamNum);
            m_iTeamNum = this->m_iTeamNum;
            temp.x = up.x * v34;
            temp.y = up.y * v34;
            temp.z = v34 * up.z;
            v37 = _RandomFloat(this: v36, a2: COERCE_FLOAT(m_iTeamNum ^ _mask__NegFloat_), a3: *(float *)&m_iTeamNum);
            v38 = right.y;
            v49 = v37;
            v39 = right.z;
            v40 = v49;
            *(float *)&v30[1].m_pPrev = (float)((float)(v49 * right.x) + temp.x) + vEndPoint.x;
            *(float *)&v30[1].m_pNext = (float)((float)(v38 * v40) + temp.y) + vEndPoint.y;
            *(float *)&v30[1].m_pSubTexture = (float)((float)(v39 * v40) + temp.z) + vEndPoint.z;
            v30[1].m_Pos.z = 0.0;
            *(float *)&v30[2].m_pPrev = this->m_vecNetworkOrigin.y;
            LOBYTE(v30[2].m_pNext) = (int)*(float *)&this->m_iHealth;
            BYTE1(v30[2].m_pNext) = (int)*(float *)&this->m_fFlags;
            RandomFloat = random->RandomFloat;
            up.x = 360.0;
            v30[1].m_Pos.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD))RandomFloat)(a1: random, a2: 0);
            v30[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
                               a1: random,
                               a2: LODWORD(this->m_vecBaseVelocity.x) ^ (unsigned int)_mask__NegFloat_,
                               a3: LODWORD(this->m_vecBaseVelocity.x));
          }
          if ( nToEmit == 0 )
            break;
          i = nToEmit;
        }
      }
      C_SteamJet::UpdateLightingRamp(this: (C_SteamJet *)((char *)this - 2432));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042AEC0
// Name: DT_SteamJet::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SteamJet::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SteamJet::g_RecvTable);
  return atexit(func: DT_SteamJet::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AEE0
// Name: DT_SteamJet::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SteamJet::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SteamJet::ignored>();
  DT_SteamJet::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104366E0
// Name: DT_SteamJet::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SteamJet::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SteamJet::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102520A0
// Name: _C_SteamJet_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SteamJet_CreateObject(int entnum, int serialNum)
{
  C_SteamJet *v2; // eax
  C_SteamJet *v3; // eax
  C_SteamJet *v4; // esi

  v2 = (C_SteamJet *)C_BaseEntity::operator new(stAllocateBlock: 0xB00u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SteamJet::C_SteamJet(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AEF0
// Name: _dynamic_initializer_for__ClientEffectReg_StickyBoltCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_StickyBoltCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_StickyBoltCallback,
           pEffectName: "BoltImpact",
           fn: StickyBoltCallback);
}

//------------------------------------------------------------------------------
// Address: 0x104366F0
// Name: _dynamic_atexit_destructor_for__g_TESystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESystem__()
{
  g_TESystem.__vftable = (C_TempEntsSystem_vtbl *)&IPredictionSystem::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10436700
// Name: _dynamic_atexit_destructor_for____g_C_TEMetalSparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEMetalSparks__()
{
  _g_C_TEMetalSparks.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEMetalSparks_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientUnknown'};
  _g_C_TEMetalSparks.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEMetalSparks);
}
