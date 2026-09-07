// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_particle_fire.cpp
// Functions: 12
// ============================================================

#include "game\client\c_particle_fire.h"

//------------------------------------------------------------------------------
// Address: 0x10246290
// Name: public: virtual class ClientClass __near * C_ParticleFire::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ParticleFire::GetClientClass(C_ParticleFire *this)
{
  return &__g_C_ParticleFireClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10246320
// Name: public: virtual C_ParticleFire::~C_ParticleFire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleFire::~C_ParticleFire(C_ParticleFire *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleFire_vtbl *)&C_ParticleFire::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleFire::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleFire::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleFire::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleFire::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleFire::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleFire::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x102463E0
// Name: public: virtual void C_ParticleFire::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleFire::Start(C_ParticleFire *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax

  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)pParticleMgr;
  if ( this == (C_ParticleFire *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4);
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)CParticleEffectBinding::FindOrAddMaterial(this: (CParticleEffectBinding *)((char *)this - 228), pMaterialName: "particle/particle_fire");
  *(_DWORD *)&this->m_Emitters[32].m_DirectionsTested = 0;
  this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount = 1032358025;
  this->m_VarMap.m_Entries.m_Memory.m_nGrowSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10246450
// Name: public: virtual void C_ParticleFire::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleFire::SimulateParticles(C_ParticleFire *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  __m128 m_flTimeDelta_low; // xmm0
  __m128i v5; // xmm0
  double v6; // xmm0_8
  float v7; // xmm1_4
  float v8; // xmm2_4

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      m_flTimeDelta_low = (__m128)LODWORD(pIterator->m_flTimeDelta);
      m_flTimeDelta_low.m128_f32[0] = m_flTimeDelta_low.m128_f32[0] + *(float *)&m_pNext[2].m_pPrev;
      m_pNext[2].m_pPrev = (Particle *)m_flTimeDelta_low.m128_i32[0];
      if ( m_flTimeDelta_low.m128_f32[0] <= 2.0 )
      {
        v5 = (__m128i)_mm_cvtps_pd(m_flTimeDelta_low);
        *(double *)v5.m128i_i64 = *(double *)v5.m128i_i64 * 3.14159 * 0.5;
        __libm_sse2_cos(X: v5);
        *(float *)&v6 = 1.0 - (v6 + 1.0) * 0.5;
        v7 = *(float *)&m_pNext[1].m_pNext + (float)(m_pNext[1].m_Pos.y * *(float *)&v6);
        v8 = *(float *)&m_pNext[1].m_pSubTexture + (float)(m_pNext[1].m_Pos.z * *(float *)&v6);
        m_pNext->m_Pos.x = *(float *)&m_pNext[1].m_pPrev + (float)(m_pNext[1].m_Pos.x * *(float *)&v6);
        m_pNext->m_Pos.y = v7;
        m_pNext->m_Pos.z = v8;
      }
      else
      {
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      }
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246530
// Name: public: C_ParticleFire::C_ParticleFire(void)
// Source: json
//------------------------------------------------------------------------------
C_ParticleFire *__thiscall C_ParticleFire::C_ParticleFire(C_ParticleFire *this)
{
  int v2; // ecx
  TimedEvent *p_m_SpawnEvent; // eax

  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleFire_vtbl *)&C_ParticleFire::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleFire::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleFire::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleFire::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleFire::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleFire::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleFire::`vftable';
  this->m_EmitterSpawn.m_TimeBetweenEvents = -1.0;
  this->m_EmitterSpawn.m_fNextEvent = 0.0;
  v2 = 127;
  p_m_SpawnEvent = &this->m_Emitters[0].m_SpawnEvent;
  do
  {
    p_m_SpawnEvent->m_TimeBetweenEvents = -1.0;
    p_m_SpawnEvent->m_fNextEvent = 0.0;
    p_m_SpawnEvent = (TimedEvent *)((char *)p_m_SpawnEvent + 28);
    --v2;
  }
  while ( v2 >= 0 );
  this->m_pParticleMgr = nullptr;
  this->m_MaterialHandle = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102465D0
// Name: public: virtual void C_ParticleFire::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleFire::Update(C_ParticleFire *this, float fTimeDelta)
{
  C_ParticleFire *v2; // edi
  int v3; // esi
  float z; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float y; // eax
  float v10; // xmm1_4
  int v11; // eax
  float v12; // xmm2_4
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  float v16; // xmm3_4
  float x; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float *p_z; // esi
  float v21; // xmm1_4
  float v22; // xmm2_4
  int v23; // esi
  int v24; // eax
  int v25; // eax
  float *p_x; // ebx
  float j; // xmm1_4
  float v28; // xmm0_4
  float *v29; // eax
  IUniformRandomStream *v30; // ecx
  float v31; // xmm0_4
  double v32; // st7
  IUniformRandomStream *v33; // ecx
  IUniformRandomStream *v34; // ecx
  float v35; // xmm1_4
  float v36; // xmm2_4
  IUniformRandomStream *v37; // ecx
  int v38; // eax
  CParticleSubTexture *m_nNextThinkTick; // [esp+4h] [ebp-9Ch]
  CGameTrace trace; // [esp+14h] [ebp-8Ch] BYREF
  Vector vecAbsEnd; // [esp+68h] [ebp-38h] BYREF
  Vector vCorner; // [esp+74h] [ebp-2Ch] BYREF
  int iOffset; // [esp+80h] [ebp-20h]
  int nSolidCorners; // [esp+84h] [ebp-1Ch]
  Vector basePos; // [esp+88h] [ebp-18h]
  int iTry; // [esp+94h] [ebp-Ch]
  float tempDelta; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+A0h] [ebp+0h] BYREF

  v2 = this;
  v3 = 0;
  if ( this->m_iTeamNum != 0 )
  {
    if ( SLODWORD(this->m_Emitters[41].m_Pos.y) < 128 )
    {
      tempDelta = fTimeDelta;
      while ( 1 )
      {
        while ( 1 )
        {
          z = v2->m_vecVelocity.z;
          v5 = tempDelta;
          if ( tempDelta < z )
          {
            v2->m_vecVelocity.z = v2->m_vecVelocity.z - tempDelta;
            goto LABEL_22;
          }
          v2->m_vecVelocity.z = v2->m_vecVelocity.y;
          tempDelta = v5 - z;
          i = 0;
          if ( LODWORD(v2->m_Emitters[41].m_Pos.y) != 0 )
            break;
          v6 = v2->m_vecVelocity.x * 1000.0;
          v7 = *(float *)&v2->m_iHealth + (float)(v2->m_vecViewOffset.y * 1000.0);
          vecAbsEnd.y = *(float *)&v2->m_fFlags + (float)(v2->m_vecViewOffset.z * 1000.0);
          v8 = v2->m_vecViewOffset.x + v6;
          vecAbsEnd.x = v7;
          vecAbsEnd.z = v8;
          UTIL_TraceLine(
            a1: &savedregs,
            a2: 0,
            vecAbsStart: (const Vector *)&v2->m_iHealth,
            &vecAbsEnd,
            mask: 0x400Bu,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &trace);
          if ( trace.fraction < 1.0 )
          {
            y = v2->m_Emitters[41].m_Pos.y;
            v10 = trace.endpos.y + (float)(trace.plane.normal.y * (float)(*(float *)&size - 1.0));
            this = (C_ParticleFire *)(7 * LODWORD(y));
            v11 = (int)&v2->m_vecBaseVelocity + 28 * LODWORD(y);
            v12 = trace.endpos.z + (float)(trace.plane.normal.z * (float)(*(float *)&size - 1.0));
            i = v11;
            *(float *)v11 = trace.endpos.x + (float)(trace.plane.normal.x * (float)(*(float *)&size - 1.0));
            *(float *)(v11 + 4) = v10;
            *(float *)(v11 + 8) = v12;
            *(_BYTE *)(v11 + 24) = 0;
            goto LABEL_19;
          }
        }
        iTry = 0;
        if ( nTries > 0 )
        {
          do
          {
            v13 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: LODWORD(v2->m_Emitters[41].m_Pos.y) - 1);
            v14 = (int)&v2->m_vecBaseVelocity + 28 * v13;
            v15 = _RandomInt(this: (IUniformRandomStream *)(7 * v13), a2: 0, a3: 7);
            this = (C_ParticleFire *)v15;
            iOffset = v15;
            if ( ((unsigned __int8)(1 << v15) & *(_BYTE *)(v14 + 24)) == 0 )
            {
              v16 = fireSpreadDist;
              x = *(float *)v14 + (float)(fireSpreadDist * g_Offsets[v15].x);
              v18 = *(float *)(v14 + 4) + (float)(g_Offsets[v15].y * fireSpreadDist);
              v19 = *(float *)(v14 + 8) + (float)(g_Offsets[v15].z * fireSpreadDist);
              basePos.x = x;
              basePos.y = v18;
              basePos.z = v19;
              nSolidCorners = 0;
              p_z = &g_Offsets[0].z;
              while ( 1 )
              {
                v21 = *(p_z - 1);
                v22 = *p_z;
                vCorner.x = (float)(*(p_z - 2) * v16) + x;
                vCorner.y = (float)(v21 * v16) + v18;
                vCorner.z = (float)(v22 * v16) + v19;
                if ( (enginetrace->GetPointContents(this: enginetrace, a2: &vCorner, a3: -1, a4: nullptr) & 1) != 0 )
                  ++nSolidCorners;
                p_z += 3;
                if ( (int)p_z >= (int)&__g_C_ParticleFireClientClass.m_pNetworkName )
                  break;
                v16 = fireSpreadDist;
                v19 = basePos.z;
                v18 = basePos.y;
                x = basePos.x;
              }
              v23 = iOffset;
              this = (C_ParticleFire *)iOffset;
              *(_BYTE *)(v14 + 24) |= 1 << iOffset;
              if ( nSolidCorners != 0 && nSolidCorners != 8 )
              {
                v24 = (int)&v2->m_vecBaseVelocity + 28 * LODWORD(v2->m_Emitters[41].m_Pos.y);
                this = (C_ParticleFire *)(7 - v23);
                *(float *)v24 = basePos.x;
                *(float *)(v24 + 4) = basePos.y;
                i = v24;
                *(float *)(v24 + 8) = basePos.z;
                *(_BYTE *)(v24 + 24) = 1 << (7 - v23);
              }
            }
            ++iTry;
          }
          while ( iTry < nTries );
LABEL_19:
          v25 = i;
          v3 = 0;
          if ( i != 0 )
          {
            *(_DWORD *)(i + 20) = 0;
            *(_DWORD *)(v25 + 12) = 1065353216;
            *(_DWORD *)(v25 + 16) = 0;
            ++LODWORD(v2->m_Emitters[41].m_Pos.y);
          }
        }
      }
    }
LABEL_22:
    i = 0;
    if ( SLODWORD(v2->m_Emitters[41].m_Pos.y) > 0 )
    {
      p_x = &v2->m_angNetworkAngles.x;
      do
      {
        for ( j = fTimeDelta; ; j = tempDelta )
        {
          v28 = p_x[1];
          if ( j < v28 )
            break;
          p_x[1] = *p_x;
          m_nNextThinkTick = (CParticleSubTexture *)v2->m_nNextThinkTick;
          tempDelta = j - v28;
          v29 = (float *)CParticleEffectBinding::AddParticle(
                           this: (CParticleEffectBinding *)&v2->IClientRenderable,
                           a2: v3,
                           sizeInBytes: 60,
                           hMaterial: m_nNextThinkTick);
          v3 = (int)v29;
          if ( v29 != nullptr )
          {
            v31 = particleSpeed * 0.5;
            v29[6] = *(p_x - 3);
            v29[7] = *(p_x - 2);
            v32 = *(p_x - 1);
            iTry = LODWORD(v31);
            v29[8] = v32;
            basePos.x = _RandomFloat(this: v30, a2: 0.0, a3: v31);
            basePos.y = _RandomFloat(this: v33, a2: 0.0, a3: *(float *)&iTry);
            basePos.z = _RandomFloat(this: v34, a2: 0.0, a3: *(float *)&iTry);
            v35 = (float)(g_FireSpreadDirection.y * particleSpeed) + basePos.y;
            v36 = (float)(g_FireSpreadDirection.z * particleSpeed) + basePos.z;
            LODWORD(trace.startpos.x) = 1;
            *(float *)(v3 + 36) = (float)(g_FireSpreadDirection.x * particleSpeed) + basePos.x;
            *(float *)(v3 + 40) = v35;
            *(float *)(v3 + 44) = v36;
            *(_BYTE *)(v3 + 56) = _RandomInt(this: v37, a2: 0, a3: SLODWORD(trace.startpos.x));
            *(_DWORD *)(v3 + 48) = 0;
          }
        }
        v38 = i;
        p_x[1] = p_x[1] - j;
        p_x += 7;
        i = v38 + 1;
      }
      while ( v38 + 1 < SLODWORD(v2->m_Emitters[41].m_Pos.y) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246AA0
// Name: public: virtual void C_ParticleFire::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleFire::RenderParticles(C_ParticleFire *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  __m128i v6; // xmm0
  double v7; // xmm0_8
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  float *m_iTeamNum; // eax
  float v14; // xmm2_4
  float y; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float z; // xmm3_4
  float v20; // xmm4_4
  __m128i v21; // xmm0
  double v22; // xmm0_8
  float alpha; // [esp+0h] [ebp-34h]
  float x; // [esp+4h] [ebp-30h]
  Vector curColor; // [esp+14h] [ebp-20h] BYREF
  Vector tPos; // [esp+20h] [ebp-14h] BYREF
  unsigned __int64 v27; // [esp+2Ch] [ebp-8h]

  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur;
          i != nullptr;
          i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: (float)(int)tPos.z) )
    {
      v6 = (__m128i)_mm_cvtps_pd((__m128)(unsigned int)i[2].m_pPrev);
      *(double *)&v27 = *(double *)v6.m128i_i64 * 3.14159;
      *(double *)v6.m128i_i64 = *(double *)v6.m128i_i64 * 3.14159 * 0.5;
      __libm_sse2_cos(X: v6);
      v8 = 1.0 - (v7 + 1.0) * 0.5;
      v9 = *(float *)&dword_105B7704[6 * LOBYTE(i[2].m_pSubTexture)];
      v10 = *(float *)&dword_105B7708[6 * LOBYTE(i[2].m_pSubTexture)];
      v11 = g_FireRamps[LOBYTE(i[2].m_pSubTexture)].m_Start.x;
      v12 = v11 + (float)((float)(*(float *)&dword_105B770C[6 * LOBYTE(i[2].m_pSubTexture)] - v11) * v8);
      m_iTeamNum = (float *)this->m_iTeamNum;
      v14 = dword_105B7714[6 * LOBYTE(i[2].m_pSubTexture)] - v10;
      y = i->m_Pos.y;
      *(float *)&v7 = m_iTeamNum[26] * y;
      curColor.y = v9 + (float)((float)(*(float *)&dword_105B7710[6 * LOBYTE(i[2].m_pSubTexture)] - v9) * v8);
      v16 = v10 + (float)(v14 * v8);
      v17 = i->m_Pos.x;
      *(float *)&v7 = *(float *)&v7 + (float)(v17 * m_iTeamNum[25]);
      v18 = m_iTeamNum[27];
      curColor.x = v12;
      z = i->m_Pos.z;
      *(float *)&v7 = (float)(*(float *)&v7 + (float)(v18 * z)) + m_iTeamNum[28];
      v20 = m_iTeamNum[30];
      tPos.x = *(float *)&v7;
      tPos.y = (float)((float)((float)(m_iTeamNum[29] * v17) + (float)(v20 * y)) + (float)(m_iTeamNum[31] * z))
             + m_iTeamNum[32];
      tPos.z = (float)((float)((float)(m_iTeamNum[33] * v17) + (float)(m_iTeamNum[34] * y)) + (float)(m_iTeamNum[35] * z))
             + m_iTeamNum[36];
      x = *(float *)&size;
      v21 = (__m128i)v27;
      *(double *)v21.m128i_i64 = *(double *)&v27 * 2.0 * 0.5;
      curColor.z = v16;
      __libm_sse2_cos(X: v21);
      alpha = 1.0 - (v22 + 1.0) * 0.5;
      RenderParticle_ColorSize(pDraw: pIterator->m_pParticleDraw, pos: &tPos, color: &curColor, alpha, size: x);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042AAB0
// Name: DT_ParticleFire::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleFire::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ParticleFire::g_RecvTable);
  return atexit(func: DT_ParticleFire::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AAD0
// Name: DT_ParticleFire::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleFire::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ParticleFire::ignored>();
  DT_ParticleFire::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436600
// Name: DT_ParticleFire::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleFire::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ParticleFire::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10246CE0
// Name: _C_ParticleFire_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ParticleFire_CreateObject(int entnum, int serialNum)
{
  C_ParticleFire *v2; // eax
  C_ParticleFire *v3; // eax
  C_ParticleFire *v4; // esi

  v2 = (C_ParticleFire *)C_BaseEntity::operator new(stAllocateBlock: 0x1898u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_ParticleFire::C_ParticleFire(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AAE0
// Name: _dynamic_initializer_for____g_C_ParticleSmokeGrenadeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ParticleSmokeGrenadeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ParticleSmokeGrenadeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ParticleSmokeGrenadeClientClass;
  return result;
}
