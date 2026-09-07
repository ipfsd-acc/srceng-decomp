// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: particles/builtin_particle_emitters.cpp
// Functions: 45
// ============================================================

#include "particles\builtin_particle_emitters.h"

//------------------------------------------------------------------------------
// Address: 0x101B9FB0
// Name: private: virtual unsigned int C_OP_InstantaneousEmitter::GetRequiredContextBytes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_InstantaneousEmitter::GetRequiredContextBytes(C_OP_InstantaneousEmitter *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x10229F90
// Name: private: void C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(class CParticleCollection __near *,struct InstantaneousEmitterContext_t __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pCtx,
        bool bForceUpdate)
{
  int m_nSnapshotControlPoint; // eax
  int m_StartingParticlesToEmit; // edx
  CParticleSnapshot *m_pSnapshot; // eax
  int m_nScaleControlPoint; // eax
  float v9; // xmm0_4
  float m_flCurTime; // xmm1_4
  Vector pControlPoint; // [esp+8h] [ebp-Ch] BYREF

  if ( bForceUpdate || !pCtx->m_bComputedActualParticlesToEmit )
  {
    m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
    m_StartingParticlesToEmit = pCtx->m_StartingParticlesToEmit;
    if ( m_nSnapshotControlPoint < 0 )
    {
      m_nScaleControlPoint = this->m_nScaleControlPoint;
      if ( m_nScaleControlPoint >= 0 )
      {
        v9 = this->m_flStartTime + pCtx->m_flTimeOffset;
        m_flCurTime = pParticles->m_flCurTime;
        if ( m_flCurTime < v9 || v9 < (float)(m_flCurTime - pParticles->m_flPreviousDt) )
          CParticleCollection::GetControlPointAtPrevTime(
            this: pParticles,
            nControlPoint: m_nScaleControlPoint,
            &pControlPoint);
        else
          CParticleCollection::GetControlPointAtTime(
            this: pParticles,
            nControlPoint: m_nScaleControlPoint,
            flTime: v9,
            &pControlPoint);
        m_StartingParticlesToEmit = (int)(float)((float)pCtx->m_StartingParticlesToEmit
                                               * *(&pControlPoint.x + this->m_nScaleControlPointField));
      }
    }
    else
    {
      if ( m_nSnapshotControlPoint >= pParticles->m_nNumControlPointsAllocated - 1 )
        m_nSnapshotControlPoint = pParticles->m_nNumControlPointsAllocated - 1;
      m_pSnapshot = pParticles->m_pCPInfo[m_nSnapshotControlPoint].m_ControlPoint.m_pSnapshot;
      if ( m_pSnapshot != nullptr )
        m_StartingParticlesToEmit = m_pSnapshot->m_pContainer->m_nColumns;
    }
    pCtx->m_bComputedActualParticlesToEmit = true;
    pCtx->m_nRemainingParticles = m_StartingParticlesToEmit < 0 ? 0 : m_StartingParticlesToEmit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022A760
// Name: private: virtual unsigned int C_OP_InstantaneousEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_InstantaneousEmitter::Emit(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        float flCurStrength,
        float *pContext)
{
  int v7; // eax
  int m_nMaxEmittedPerFrame; // edx
  int m_nActiveParticles; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // eax
  float flStartTime; // [esp+18h] [ebp+10h]

  if ( *((_BYTE *)pContext + 20) == 0 )
    return 0;
  flStartTime = pContext[4] + pContext[3];
  if ( flStartTime > pParticles->m_flCurTime )
    return 0;
  C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(
    this,
    pParticles,
    pCtx: (InstantaneousEmitterContext_t *)pContext,
    bForceUpdate: false);
  v7 = *(_DWORD *)pContext;
  if ( *(int *)pContext <= 0 )
    return 0;
  m_nMaxEmittedPerFrame = this->m_nMaxEmittedPerFrame;
  if ( m_nMaxEmittedPerFrame >= v7 )
    m_nMaxEmittedPerFrame = *(_DWORD *)pContext;
  *(_DWORD *)pContext = v7 - m_nMaxEmittedPerFrame;
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v10 = pParticles->m_nMaxAllowedParticles - m_nActiveParticles;
  if ( v10 >= m_nMaxEmittedPerFrame )
    v10 = m_nMaxEmittedPerFrame;
  if ( v10 == 0 )
    return 0;
  v11 = m_nActiveParticles + v10;
  pParticles->m_nActiveParticles = m_nActiveParticles + v10;
  pParticles->m_nPaddedActiveParticles = (m_nActiveParticles + v10 + 3) / 4;
  if ( m_nActiveParticles < m_nActiveParticles + v10 )
  {
    if ( v10 >= 4 )
    {
      v12 = m_nActiveParticles + 1;
      do
      {
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v12 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v12
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v12 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v12 + 1)
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v12 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v12 + 2)
                                                         / 4)] = flStartTime;
        m_nActiveParticles += 4;
        v12 += 4;
      }
      while ( m_nActiveParticles < v11 - 3 );
    }
    for ( ; m_nActiveParticles < v11; pParticles->m_ParticleAttributes.m_pAttributes[8][v13] = flStartTime )
    {
      v13 = (m_nActiveParticles & 3) + pParticles->m_ParticleAttributes.m_nFloatStrides[8] * (m_nActiveParticles / 4);
      ++m_nActiveParticles;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x1022A8F0
// Name: private: virtual bool C_OP_ContinuousEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_ContinuousEmitter::MayCreateMoreParticles(
        C_OP_ContinuousEmitter *this,
        const CParticleCollection *pParticles,
        float *pContext)
{
  bool result; // al
  float m_flEmissionDuration; // xmm0_4

  result = false;
  if ( *((_BYTE *)pContext + 16) != 0 && !this->m_bInitFromKilledParentParticles && this->m_flEmitRate > 0.0 )
  {
    m_flEmissionDuration = this->m_flEmissionDuration;
    if ( m_flEmissionDuration == 0.0
      || (float)(pParticles->m_flCurTime - pParticles->m_flDt) <= (float)((float)(this->m_flStartTime + pContext[3])
                                                                        + m_flEmissionDuration) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022B050
// Name: private: virtual bool C_OP_NoiseEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_NoiseEmitter::MayCreateMoreParticles(
        C_OP_NoiseEmitter *this,
        const CParticleCollection *pParticles,
        float *pContext)
{
  bool result; // al
  float m_flEmissionDuration; // xmm0_4

  result = false;
  if ( *((_BYTE *)pContext + 16) != 0 )
  {
    m_flEmissionDuration = this->m_flEmissionDuration;
    if ( m_flEmissionDuration == 0.0
      || (float)(pParticles->m_flCurTime - pParticles->m_flDt) <= (float)((float)(this->m_flStartTime + pContext[3])
                                                                        + m_flEmissionDuration) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022B830
// Name: private: void C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(class CParticleCollection __near *,struct MaintainEmitterContext_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        MaintainEmitterContext_t *pCtx)
{
  int m_nSnapshotControlPoint; // eax
  CParticleSnapshot *m_pSnapshot; // eax
  int m_nColumns; // ecx
  int m_nScaleControlPoint; // eax
  float v8; // xmm0_4
  float m_flCurTime; // xmm1_4
  Vector pControlPoint; // [esp+Ch] [ebp-Ch] BYREF

  pCtx->m_ActualParticlesToMaintain = this->m_nParticlesToMaintain;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
  {
    m_nScaleControlPoint = this->m_nScaleControlPoint;
    if ( m_nScaleControlPoint >= 0 )
    {
      v8 = this->m_flStartTime + pCtx->m_flTimeOffset;
      m_flCurTime = pParticles->m_flCurTime;
      if ( m_flCurTime < v8 || v8 < (float)(m_flCurTime - pParticles->m_flPreviousDt) )
        CParticleCollection::GetControlPointAtPrevTime(
          this: pParticles,
          nControlPoint: m_nScaleControlPoint,
          &pControlPoint);
      else
        CParticleCollection::GetControlPointAtTime(
          this: pParticles,
          nControlPoint: m_nScaleControlPoint,
          flTime: v8,
          &pControlPoint);
      m_nColumns = (int)(float)((float)this->m_nParticlesToMaintain
                              * *(&pControlPoint.x + this->m_nScaleControlPointField));
      goto LABEL_12;
    }
  }
  else
  {
    if ( m_nSnapshotControlPoint >= pParticles->m_nNumControlPointsAllocated - 1 )
      m_nSnapshotControlPoint = pParticles->m_nNumControlPointsAllocated - 1;
    m_pSnapshot = pParticles->m_pCPInfo[m_nSnapshotControlPoint].m_ControlPoint.m_pSnapshot;
    if ( m_pSnapshot != nullptr )
    {
      m_nColumns = m_pSnapshot->m_pContainer->m_nColumns;
LABEL_12:
      pCtx->m_ActualParticlesToMaintain = m_nColumns;
    }
  }
  pCtx->m_ActualParticlesToMaintain &= (pCtx->m_ActualParticlesToMaintain < 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022BF20
// Name: private: virtual unsigned int C_OP_MaintainEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_MaintainEmitter::Emit(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        float flCurStrength,
        float *pContext)
{
  int m_nActiveParticles; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  float m_flPrevSimTime; // xmm0_4
  int v11; // ebx
  float v12; // xmm1_4
  int v13; // ecx
  float m_flCurTime; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float *v17; // eax
  float flStartTime; // [esp+14h] [ebp+10h]

  if ( *((_BYTE *)pContext + 8) == 0 )
    return 0;
  flStartTime = this->m_flStartTime + pContext[1];
  if ( flStartTime > pParticles->m_flCurTime )
    return 0;
  C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(this, pParticles, pCtx: (MaintainEmitterContext_t *)pContext);
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v7 = *(_DWORD *)pContext;
  if ( m_nActiveParticles >= *(_DWORD *)pContext || v7 <= 0 )
    return 0;
  v8 = pParticles->m_nMaxAllowedParticles - m_nActiveParticles;
  v9 = v7 - m_nActiveParticles;
  if ( v8 >= v9 )
    v8 = v9;
  if ( v8 < 0 )
    return 0;
  m_flPrevSimTime = pParticles->m_flPrevSimTime;
  v11 = m_nActiveParticles + v8;
  pParticles->m_nActiveParticles = m_nActiveParticles + v8;
  pParticles->m_nPaddedActiveParticles = (m_nActiveParticles + v8 + 3) / 4;
  if ( m_flPrevSimTime <= flStartTime )
    m_flPrevSimTime = flStartTime;
  v12 = (float)(pParticles->m_flCurTime - m_flPrevSimTime) / (float)v8;
  if ( m_nActiveParticles < v11 )
  {
    if ( v8 >= 4 )
    {
      v13 = m_nActiveParticles + 1;
      do
      {
        if ( pParticles->m_flCurTime <= m_flPrevSimTime )
          m_flPrevSimTime = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = m_flPrevSimTime;
        m_flCurTime = m_flPrevSimTime + v12;
        if ( pParticles->m_flCurTime <= m_flCurTime )
          m_flCurTime = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v13 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v13
                                                         / 4)] = m_flCurTime;
        v15 = m_flCurTime + v12;
        if ( pParticles->m_flCurTime <= v15 )
          v15 = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v13 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v13 + 1)
                                                         / 4)] = v15;
        v16 = v15 + v12;
        if ( pParticles->m_flCurTime <= v16 )
          v16 = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v13 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v13 + 2)
                                                         / 4)] = v16;
        m_nActiveParticles += 4;
        v13 += 4;
        m_flPrevSimTime = v16 + v12;
      }
      while ( m_nActiveParticles < v11 - 3 );
    }
    for ( ; m_nActiveParticles < v11; m_flPrevSimTime = m_flPrevSimTime + v12 )
    {
      v17 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                             + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                             * (m_nActiveParticles
                                                              / 4)];
      if ( pParticles->m_flCurTime <= m_flPrevSimTime )
        m_flPrevSimTime = pParticles->m_flCurTime;
      ++m_nActiveParticles;
      *v17 = m_flPrevSimTime;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x1022C130
// Name: void AddBuiltInParticleEmitters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBuiltInParticleEmitters()
{
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_ContinuousEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_InstantaneousEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_NoiseEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_MaintainEmitterFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1022C180
// Name: private: virtual unsigned int C_OP_ContinuousEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_ContinuousEmitter::Emit(
        C_OP_ContinuousEmitter *this,
        float pParticles,
        float flCurStrength,
        float pContext)
{
  float v4; // ebx
  CParticleCollection *v5; // esi
  bool v7; // cc
  float m_flEmissionDuration; // xmm0_4
  float v10; // xmm6_4
  float m_flCurTime; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float HighestControlPoint; // xmm0_4
  int m_nScaleControlPoint; // eax
  float m_flEmissionScale; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  CParticleCollection *m_pParent; // eax
  float v22; // xmm1_4
  float v23; // xmm1_4
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  int v26; // eax
  float v27; // xmm2_4
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  int v30; // ecx
  int m_nActiveParticles; // edi
  int v32; // ebx
  float v33; // xmm6_4
  float v34; // xmm0_4
  int v35; // ecx
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float *v39; // eax
  Vector pControlPoint; // [esp+14h] [ebp-10h] BYREF
  float v41; // [esp+20h] [ebp-4h]

  v4 = pContext;
  v5 = (CParticleCollection *)LODWORD(pParticles);
  v7 = (float)(*(float *)(LODWORD(pContext) + 12) + this->m_flStartTime) <= *(float *)(LODWORD(pParticles) + 36);
  pContext = *(float *)(LODWORD(pContext) + 12) + this->m_flStartTime;
  if ( !v7 )
    return 0;
  if ( this->m_bInitFromKilledParentParticles )
  {
    CParticleOperatorInstance::GetParentKillList(
      this,
      pParticles: (CParticleCollection *)LODWORD(pParticles),
      nNumParticlesToKill: (int *)&pParticles);
    m_flEmissionDuration = this->m_flEmissionDuration;
    v10 = 0.0;
    m_flCurTime = v5->m_flCurTime;
    v12 = (float)SLODWORD(pParticles);
    if ( m_flEmissionDuration != 0.0 )
    {
      v13 = pContext;
      v14 = m_flEmissionDuration + pContext;
      if ( pContext <= m_flCurTime )
      {
        if ( m_flCurTime > v14 )
        {
          m_flCurTime = v14;
          v15 = v14;
          goto LABEL_34;
        }
        v13 = v5->m_flCurTime;
      }
      m_flCurTime = v13;
    }
    v15 = m_flCurTime;
    goto LABEL_34;
  }
  HighestControlPoint = (float)CParticleCollection::GetHighestControlPoint(this: (CParticleCollection *)LODWORD(pParticles));
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  m_flEmissionScale = this->m_flEmissionScale * HighestControlPoint;
  v19 = this->m_flEmitRate * flCurStrength;
  v41 = m_flEmissionScale;
  pParticles = v19;
  if ( m_nScaleControlPoint >= 0 )
  {
    CParticleCollection::GetControlPointAtTime(
      this: v5,
      nControlPoint: m_nScaleControlPoint,
      flTime: v5->m_flCurTime,
      &pControlPoint);
    v20 = *(&pControlPoint.x + this->m_nScaleControlPointField);
    if ( v20 < 0.0 )
      v20 = 0.0;
    v19 = v20 * pParticles;
    m_flEmissionScale = v41;
  }
  if ( m_flEmissionScale != 0.0 || this->m_bScalePerParticle )
  {
    if ( this->m_bScalePerParticle )
    {
      m_pParent = v5->m_pParent;
      if ( m_pParent != nullptr )
        m_flEmissionScale = (float)m_pParent->m_nActiveParticles * this->m_flEmissionScale;
      else
        m_flEmissionScale = this->m_flEmissionScale;
    }
    v19 = v19 * m_flEmissionScale;
  }
  if ( v19 == 0.0 )
    return 0;
  if ( *(_BYTE *)(LODWORD(v4) + 16) == 0 )
    return 0;
  if ( this->m_bInitFromKilledParentParticles )
    return 0;
  if ( this->m_flEmitRate <= 0.0 )
    return 0;
  v22 = this->m_flEmissionDuration;
  if ( v22 != 0.0
    && (float)(v5->m_flCurTime - v5->m_flDt) > (float)((float)(*(float *)(LODWORD(v4) + 12) + this->m_flStartTime) + v22) )
  {
    return 0;
  }
  m_flCurTime = v5->m_flCurTime;
  v15 = m_flCurTime - v5->m_flDt;
  if ( v22 != 0.0 )
  {
    if ( v15 <= pContext )
      v15 = pContext;
    v23 = v22 + pContext;
    if ( v23 <= m_flCurTime )
      m_flCurTime = v23;
  }
  v10 = m_flCurTime - v15;
  v12 = v19 * (float)(m_flCurTime - v15);
LABEL_34:
  v24 = (__m128)(unsigned int)*(_DWORD *)LODWORD(v4);
  v24.m128_f32[0] = v24.m128_f32[0] + v12;
  v25.m128_i32[0] = 1258291200;
  v26 = *(_DWORD *)(LODWORD(v4) + 4);
  v27 = v24.m128_f32[0];
  *(_DWORD *)LODWORD(v4) = v24.m128_i32[0];
  v28 = _mm_and_ps((__m128)0x80000000, v24);
  v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v24, v28), v25).m128_f32[0]) & 0x4B000000
                  | v28.m128_i32[0];
  v24.m128_f32[0] = (float)(v24.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
  v29 = v24;
  v29.m128_f32[0] = v24.m128_f32[0] - v27;
  v30 = (int)(float)((float)(v24.m128_f32[0]
                           - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v29, v28).m128_f32[0]) & 0x3F800000))
                   - (float)v26);
  *(_DWORD *)(LODWORD(v4) + 4) = v30 + v26;
  if ( v30 == 0 )
    return 0;
  m_nActiveParticles = v5->m_nActiveParticles;
  if ( v5->m_nMaxAllowedParticles - m_nActiveParticles < v30 )
    v30 = v5->m_nMaxAllowedParticles - m_nActiveParticles;
  if ( v30 == 0 )
    return 0;
  v32 = m_nActiveParticles + v30;
  v33 = v10 / (float)v30;
  v5->m_nActiveParticles = m_nActiveParticles + v30;
  v5->m_nPaddedActiveParticles = (m_nActiveParticles + v30 + 3) / 4;
  v34 = v33 + v15;
  if ( m_nActiveParticles < m_nActiveParticles + v30 )
  {
    if ( v30 >= 4 )
    {
      v35 = m_nActiveParticles + 1;
      do
      {
        if ( m_flCurTime <= v34 )
          v34 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * (m_nActiveParticles / 4)] = v34;
        v36 = v34 + v33;
        if ( m_flCurTime <= v36 )
          v36 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(v35 & 3) + v5->m_ParticleAttributes.m_nFloatStrides[8] * (v35 / 4)] = v36;
        v37 = v36 + v33;
        if ( m_flCurTime <= v37 )
          v37 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v35 + 1) & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * ((v35 + 1) / 4)] = v37;
        v38 = v37 + v33;
        if ( m_flCurTime <= v38 )
          v38 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v35 - 2) & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * ((v35 + 2) / 4)] = v38;
        m_nActiveParticles += 4;
        v35 += 4;
        v34 = v38 + v33;
      }
      while ( m_nActiveParticles < v32 - 3 );
    }
    for ( ; m_nActiveParticles < v32; v34 = v34 + v33 )
    {
      v39 = &v5->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                     + v5->m_ParticleAttributes.m_nFloatStrides[8]
                                                     * (m_nActiveParticles
                                                      / 4)];
      if ( m_flCurTime <= v34 )
        v34 = m_flCurTime;
      ++m_nActiveParticles;
      *v39 = v34;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x1022C550
// Name: private: virtual unsigned int C_OP_NoiseEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
unsigned int __userpurge C_OP_NoiseEmitter::Emit@<eax>(
        C_OP_NoiseEmitter *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CParticleCollection *pParticles,
        float flCurStrength,
        _BYTE *pContext)
{
  int HighestControlPoint; // eax
  bool v9; // zf
  float m_flNoiseScale; // xmm1_4
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm0
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  __m128 m_flEmissionDuration_low; // xmm0
  float v20; // xmm3_4
  __m128 m_flCurTime_low; // xmm5
  float v22; // xmm7_4
  __m128 v23; // xmm2
  int v24; // eax
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  int v30; // ecx
  int m_nActiveParticles; // edi
  const FourVectors *v32; // eax
  float v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm0_4
  int v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float *v40; // eax
  _BYTE v42[64]; // [esp-Ch] [ebp-7Ch] OVERLAPPED BYREF
  float v43; // [esp+40h] [ebp-30h]
  float v44; // [esp+44h] [ebp-2Ch]
  float v45; // [esp+48h] [ebp-28h]
  float v46; // [esp+4Ch] [ebp-24h]
  float m_flOutputMin; // [esp+50h] [ebp-20h]
  float m_flOutputMax; // [esp+54h] [ebp-1Ch]
  float flControlPointScale; // [esp+58h] [ebp-18h]
  float fMin; // [esp+5Ch] [ebp-14h]
  float fMax; // [esp+60h] [ebp-10h]
  int flAbsScale; // [esp+64h] [ebp-Ch]
  int nAbsVal; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  flAbsScale = a2;
  nAbsVal = retaddr;
  HighestControlPoint = CParticleCollection::GetHighestControlPoint(this: pParticles);
  v9 = !this->m_bAbsVal;
  v46 = this->m_flEmissionScale * (float)HighestControlPoint;
  fMin = NAN;
  flControlPointScale = 0.5;
  if ( !v9 )
  {
    fMin = NAN;
    flControlPointScale = 1.0;
  }
  m_flNoiseScale = this->m_flNoiseScale;
  m_flOutputMin = this->m_flOutputMin;
  m_flOutputMax = this->m_flOutputMax;
  *(float *)&v42[52] = (float)(pParticles->m_flCurTime + this->m_flOffset) * m_flNoiseScale;
  *(float *)&v42[56] = *(float *)&v42[52];
  *(float *)&v42[60] = *(float *)&v42[52];
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: a3, a2: a4));
  v43 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: LODWORD(fMax), a2: flAbsScale));
  v44 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: LODWORD(fMax), a2: flAbsScale));
  v45 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  v11 = 0;
  v11.m128_f32[0] = v43 + *(float *)&v42[52];
  *(__m128 *)v42 = _mm_shuffle_ps(v11, v11, 0);
  v12 = 0;
  v12.m128_f32[0] = v44 + *(float *)&v42[52];
  *(__m128 *)&v42[16] = _mm_shuffle_ps(v12, v12, 0);
  v13 = 0;
  v13.m128_f32[0] = v45 + *(float *)&v42[52];
  v14 = _mm_shuffle_ps(v13, v13, 0);
  *(__m128 *)&v42[32] = v14;
  NoiseSIMD(result: (__m128 *)v42, pos: (const FourVectors *)LODWORD(fMax));
  *(__m128 *)&v42[48] = v14;
  LODWORD(fMax) = LODWORD(fMin) & v14.m128_i32[0];
  if ( this->m_bAbsValInv )
    v15 = 1.0 - fMax;
  else
    v15 = fMax;
  v16 = (float)((float)((float)(m_flOutputMax - m_flOutputMin) * flControlPointScale) * v15)
      + (float)((float)((float)(1.0 - flControlPointScale) * (float)(m_flOutputMax - m_flOutputMin)) + m_flOutputMin);
  if ( v16 >= 0.0 )
  {
    if ( v16 > 2147483600.0 )
      v16 = 2147483600.0;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = v16 * flCurStrength;
  if ( v46 != 0.0 )
    v17 = v17 * v46;
  if ( v17 == 0.0 )
    return 0;
  if ( pContext[16] == 0 )
    return 0;
  m_flEmissionDuration_low = (__m128)LODWORD(this->m_flEmissionDuration);
  if ( m_flEmissionDuration_low.m128_f32[0] != 0.0
    && (float)(pParticles->m_flCurTime - pParticles->m_flDt) > (float)((float)(this->m_flStartTime
                                                                             + *((float *)pContext + 3))
                                                                     + m_flEmissionDuration_low.m128_f32[0]) )
  {
    return 0;
  }
  v20 = this->m_flStartTime + *((float *)pContext + 3);
  m_flCurTime_low = (__m128)LODWORD(pParticles->m_flCurTime);
  if ( v20 > m_flCurTime_low.m128_f32[0] )
    return 0;
  v22 = m_flCurTime_low.m128_f32[0] - pParticles->m_flDt;
  if ( m_flEmissionDuration_low.m128_f32[0] != 0.0 )
  {
    if ( v20 > v22 )
      v22 = this->m_flStartTime + *((float *)pContext + 3);
    m_flEmissionDuration_low.m128_f32[0] = m_flEmissionDuration_low.m128_f32[0] + v20;
    if ( m_flCurTime_low.m128_f32[0] > m_flEmissionDuration_low.m128_f32[0] )
      m_flCurTime_low = m_flEmissionDuration_low;
  }
  v23.m128_i32[0] = 1258291200;
  v24 = *((_DWORD *)pContext + 1);
  v25 = m_flCurTime_low;
  v25.m128_f32[0] = m_flCurTime_low.m128_f32[0] - v22;
  v26 = v25;
  v26.m128_f32[0] = (float)((float)(m_flCurTime_low.m128_f32[0] - v22) * v17) + *(float *)pContext;
  v27 = _mm_and_ps((__m128)0x80000000, v26);
  v23.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v26, v27), v23).m128_f32[0]) & 0x4B000000
                  | v27.m128_i32[0];
  v28 = v26;
  v28.m128_f32[0] = (float)(v26.m128_f32[0] + v23.m128_f32[0]) - v23.m128_f32[0];
  v29 = v28;
  v29.m128_f32[0] = v28.m128_f32[0] - v26.m128_f32[0];
  *(_DWORD *)pContext = v26.m128_i32[0];
  v30 = (int)(float)((float)(v28.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v29, v27).m128_u32[0] & 0x3F800000))
                   - (float)v24);
  *((_DWORD *)pContext + 1) = v30 + v24;
  if ( *(float *)&v30 == 0.0 )
    return 0;
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v32 = (const FourVectors *)(pParticles->m_nMaxAllowedParticles - m_nActiveParticles);
  fMax = *(float *)&v30;
  if ( (int)v32 < v30 )
  {
    fMax = *(float *)&v32;
    v30 = (int)v32;
  }
  if ( v30 <= 0 )
    return 0;
  LODWORD(v33) = m_nActiveParticles + v30;
  v34 = v25.m128_f32[0] / (float)SLODWORD(fMax);
  flControlPointScale = v33;
  *(float *)&pParticles->m_nActiveParticles = v33;
  pParticles->m_nPaddedActiveParticles = (LODWORD(v33) + 3) / 4;
  v35 = v34 + v22;
  if ( m_nActiveParticles < SLODWORD(v33) )
  {
    if ( LODWORD(v33) - m_nActiveParticles >= 4 )
    {
      v36 = m_nActiveParticles + 1;
      do
      {
        if ( m_flCurTime_low.m128_f32[0] <= v35 )
          v35 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = v35;
        v37 = v35 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v37 )
          v37 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v36 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v36
                                                         / 4)] = v37;
        v38 = v37 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v38 )
          v38 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v36 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v36 + 1)
                                                         / 4)] = v38;
        v39 = v38 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v39 )
          v39 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v36 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v36 + 2)
                                                         / 4)] = v39;
        m_nActiveParticles += 4;
        v36 += 4;
        v35 = v39 + v34;
      }
      while ( m_nActiveParticles < LODWORD(flControlPointScale) - 3 );
      v33 = flControlPointScale;
    }
    for ( ; m_nActiveParticles < SLODWORD(v33); v35 = v35 + v34 )
    {
      v40 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                             + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                             * (m_nActiveParticles
                                                              / 4)];
      if ( m_flCurTime_low.m128_f32[0] <= v35 )
        v35 = m_flCurTime_low.m128_f32[0];
      ++m_nActiveParticles;
      *v40 = v35;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x1022CA20
// Name: private: virtual unsigned __int64 C_OP_InstantaneousEmitter::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_OP_InstantaneousEmitter::GetReadControlPointMask(C_OP_InstantaneousEmitter *this)
{
  int m_nScaleControlPoint; // ecx
  int v3; // esi
  int m_nSnapshotControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    v3 = 0;
  else
    v3 = 1LL << m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
    return v3;
  else
    return v3 | (1LL << m_nSnapshotControlPoint);
}

//------------------------------------------------------------------------------
// Address: 0x1022CA80
// Name: private: virtual unsigned __int64 C_OP_ContinuousEmitter::GetNonPositionalControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_ContinuousEmitter::GetNonPositionalControlPointMask(C_OP_ContinuousEmitter *this)
{
  int m_nScaleControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    return 0;
  else
    return 1LL << m_nScaleControlPoint;
}

//------------------------------------------------------------------------------
// Address: 0x1022CAA0
// Name: private: virtual void C_OP_InstantaneousEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::StopEmission(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly )
    pContext[20] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022CAC0
// Name: private: virtual void C_OP_InstantaneousEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::SkipToTime(
        C_OP_InstantaneousEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  if ( flTime > (float)((float)(this->m_flStartTime + pContext[3]) + 2.0) )
    *((_BYTE *)pContext + 20) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022CAF0
// Name: private: virtual void C_OP_InstantaneousEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::InitializeContextData(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        int *pContext)
{
  int m_nParticlesToEmit; // eax
  int m_nRandomQueryCount; // edi
  __int16 v5; // bx
  float m_flStartTimeMax; // xmm0_4
  float m_flStartTime; // xmm1_4
  int v8; // eax
  int m_nMinParticlesToEmit; // [esp+4h] [ebp-4h]

  m_nMinParticlesToEmit = this->m_nMinParticlesToEmit;
  m_nParticlesToEmit = this->m_nParticlesToEmit;
  if ( m_nMinParticlesToEmit >= 0 )
  {
    m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
    v5 = m_nRandomQueryCount + pParticles->m_nRandomSeed;
    pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
    m_nParticlesToEmit = m_nMinParticlesToEmit
                       + (int)(float)((float)(m_nParticlesToEmit - m_nMinParticlesToEmit + 1)
                                    * s_pRandomFloats[v5 & 0xFFF]);
  }
  pContext[1] = m_nParticlesToEmit;
  *pContext = m_nParticlesToEmit;
  *((_BYTE *)pContext + 8) = 0;
  pContext[3] = 0;
  *((_BYTE *)pContext + 20) = 1;
  m_flStartTimeMax = this->m_flStartTimeMax;
  if ( m_flStartTimeMax <= 0.0 )
  {
    pContext[4] = SLODWORD(this->m_flStartTime);
  }
  else
  {
    m_flStartTime = this->m_flStartTime;
    v8 = pParticles->m_nRandomQueryCount;
    pParticles->m_nRandomQueryCount = v8 + 1;
    *((float *)pContext + 4) = (float)((float)(m_flStartTimeMax - m_flStartTime)
                                     * s_pRandomFloats[((_WORD)v8 + (unsigned __int16)pParticles->m_nRandomSeed) & 0xFFF])
                             + m_flStartTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CBB0
// Name: private: virtual bool C_OP_InstantaneousEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_OP_InstantaneousEmitter::MayCreateMoreParticles(
        C_OP_InstantaneousEmitter *this,
        const CParticleCollection *pParticles,
        int *pContext)
{
  return *((_BYTE *)pContext + 20) != 0 && *pContext > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022CBD0
// Name: private: virtual void C_OP_InstantaneousEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::InitParams(C_OP_InstantaneousEmitter *this, CParticleSystemDefinition *pDef)
{
  int m_nMinParticlesToEmit; // eax
  int m_nParticlesToEmit; // eax
  int m_nMaxParticles; // eax
  int m_nScaleControlPointField; // eax
  int m_nScaleControlPoint; // eax
  int m_nSnapshotControlPoint; // eax

  m_nMinParticlesToEmit = this->m_nMinParticlesToEmit;
  if ( m_nMinParticlesToEmit >= 0 && m_nMinParticlesToEmit > this->m_nParticlesToEmit )
  {
    m_nParticlesToEmit = this->m_nParticlesToEmit;
    this->m_nParticlesToEmit = this->m_nMinParticlesToEmit;
    this->m_nMinParticlesToEmit = m_nParticlesToEmit;
  }
  if ( this->m_nMaxEmittedPerFrame < 0 )
  {
    m_nMaxParticles = pDef->m_nMaxParticles;
    if ( m_nMaxParticles >= 5000 )
      m_nMaxParticles = 5000;
    this->m_nMaxEmittedPerFrame = m_nMaxParticles;
  }
  m_nScaleControlPointField = this->m_nScaleControlPointField;
  if ( m_nScaleControlPointField >= 0 )
  {
    if ( m_nScaleControlPointField > 2 )
      m_nScaleControlPointField = 2;
  }
  else
  {
    m_nScaleControlPointField = 0;
  }
  this->m_nScaleControlPointField = m_nScaleControlPointField;
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint >= -1 )
  {
    if ( m_nScaleControlPoint > 64 )
      m_nScaleControlPoint = 64;
  }
  else
  {
    m_nScaleControlPoint = -1;
  }
  this->m_nScaleControlPoint = m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint >= -1 )
  {
    if ( m_nSnapshotControlPoint > 64 )
      m_nSnapshotControlPoint = 64;
    this->m_nSnapshotControlPoint = m_nSnapshotControlPoint;
  }
  else
  {
    this->m_nSnapshotControlPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CC60
// Name: private: virtual void C_OP_InstantaneousEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::StartEmission(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly )
  {
    C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(this, pParticles, pCtx: pContext, bForceUpdate: true);
    ((void (__thiscall *)(C_OP_InstantaneousEmitter *, _DWORD, CParticleCollection *, InstantaneousEmitterContext_t *))this->SkipToTime)(
      a1: this,
      a2: LODWORD(pParticles->m_flCurTime),
      a3: pParticles,
      a4: pContext);
    pContext->m_bOn = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CCB0
// Name: private: virtual void C_OP_InstantaneousEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::Restart(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pContext)
{
  float m_flStartTimeMax; // xmm0_4
  int m_nRandomQueryCount; // eax
  float m_flStartTime; // xmm1_4
  __int16 v7; // dx

  C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(this, pParticles, pCtx: pContext, bForceUpdate: true);
  pContext->m_flTimeOffset = pParticles->m_flCurTime;
  pContext->m_bOn = true;
  m_flStartTimeMax = this->m_flStartTimeMax;
  if ( m_flStartTimeMax <= 0.0 )
  {
    pContext->m_flRandomStartTime = this->m_flStartTime;
  }
  else
  {
    m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
    m_flStartTime = this->m_flStartTime;
    v7 = m_nRandomQueryCount + pParticles->m_nRandomSeed;
    pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
    pContext->m_flRandomStartTime = (float)((float)(m_flStartTimeMax - m_flStartTime) * s_pRandomFloats[v7 & 0xFFF])
                                  + m_flStartTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CD30
// Name: private: virtual void C_OP_ContinuousEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::InitParams(C_OP_ContinuousEmitter *this, CParticleSystemDefinition *pDef)
{
  if ( this->m_flEmitRate < 0.0 )
    this->m_flEmitRate = 0.0;
  if ( this->m_flEmissionDuration < 0.0 )
    this->m_flEmissionDuration = 0.0;
  this->m_flEmitRate = (float)g_nParticle_Multiplier * this->m_flEmitRate;
}

//------------------------------------------------------------------------------
// Address: 0x1022CD70
// Name: private: virtual void C_OP_NoiseEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::StopEmission(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly || this->m_flEmissionDuration == 0.0 )
    pContext[16] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022CDA0
// Name: private: virtual void C_OP_ContinuousEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::InitializeContextData(
        C_OP_ContinuousEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[2] = this->m_flStartTime;
  *(_QWORD *)pContext = 0;
  pContext[3] = 0.0;
  *((_BYTE *)pContext + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022CDD0
// Name: private: virtual void C_OP_ContinuousEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::Restart(
        C_OP_ContinuousEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  if ( this->m_flEmissionDuration != 0.0 )
  {
    pContext[2] = this->m_flStartTime + pParticles->m_flCurTime;
    *pContext = 0.0;
    pContext[1] = 0.0;
    pContext[3] = pParticles->m_flCurTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022CE10
// Name: private: virtual bool C_OP_ContinuousEmitter::ShouldRun(bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_ContinuousEmitter::ShouldRun(C_OP_ContinuousEmitter *this, bool bApplyingParentKillList)
{
  if ( this->m_bInitFromKilledParentParticles )
    return bApplyingParentKillList;
  else
    return !bApplyingParentKillList;
}

//------------------------------------------------------------------------------
// Address: 0x1022CE30
// Name: private: virtual void C_OP_ContinuousEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::SkipToTime(
        C_OP_ContinuousEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  int HighestControlPoint; // eax
  float m_flEmitRate; // xmm0_4
  float v8; // xmm1_4
  int m_nScaleControlPoint; // eax
  float v10; // xmm1_4
  float m_flCurTime; // xmm5_4
  float x; // xmm0_4
  __m128 m_flCurTime_low; // xmm2
  __m128d v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  float v18; // xmm2_4
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  int m_nActiveParticles; // edi
  int m_nMaxAllowedParticles; // eax
  int v23; // ecx
  float v24; // xmm6_4
  int v25; // ecx
  float v26; // xmm4_4
  float v27; // xmm0_4
  int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float *v32; // eax
  __m128 v33; // xmm0
  float v34; // xmm0_4
  Vector dt; // [esp+4h] [ebp-18h] BYREF
  Vector vecScale; // [esp+10h] [ebp-Ch] BYREF
  int flEmitStrength; // [esp+24h] [ebp+8h]
  float flEmitStrengtha; // [esp+24h] [ebp+8h]
  float v39; // [esp+28h] [ebp+Ch]
  int v40; // [esp+2Ch] [ebp+10h]

  vecScale.x = this->m_flStartTime + pContext[3];
  if ( vecScale.x < flTime && !this->m_bInitFromKilledParentParticles )
  {
    HighestControlPoint = CParticleCollection::GetHighestControlPoint(this: pParticles);
    m_flEmitRate = this->m_flEmitRate;
    vecScale.y = this->m_flEmissionScale * (float)HighestControlPoint;
    v39 = m_flEmitRate;
    if ( CParticleCollection::CheckIfOperatorShouldRun(
           this: pParticles,
           pOp: this,
           pflCurStrength: &vecScale.z,
           bApplyingParentKillList: false) )
    {
      v8 = vecScale.z * m_flEmitRate;
      v39 = vecScale.z * m_flEmitRate;
    }
    else
    {
      v8 = m_flEmitRate;
    }
    m_nScaleControlPoint = this->m_nScaleControlPoint;
    if ( m_nScaleControlPoint >= 0 )
    {
      CParticleCollection::GetControlPointAtTime(
        this: pParticles,
        nControlPoint: m_nScaleControlPoint,
        flTime: pParticles->m_flCurTime,
        pControlPoint: &dt);
      v10 = *(&dt.x + this->m_nScaleControlPointField);
      if ( v10 < 0.0 )
        v10 = 0.0;
      v8 = v10 * v39;
    }
    if ( vecScale.y != 0.0 )
      v8 = v8 * vecScale.y;
    m_flCurTime = pParticles->m_flCurTime;
    x = m_flCurTime - flTime;
    if ( this->m_flEmissionDuration != 0.0 && vecScale.x > x )
      x = vecScale.x;
    m_flCurTime_low = (__m128)LODWORD(pParticles->m_flCurTime);
    m_flCurTime_low.m128_f32[0] = m_flCurTime - x;
    v14 = _mm_cvtps_pd(m_flCurTime_low);
    if ( v14.m128d_f64[0] > 4.0 )
      v14 = (__m128d)0x4010000000000000uLL;
    v15 = _mm_cvtpd_ps(v14);
    v16 = v15;
    v16.m128_f32[0] = v15.m128_f32[0] * v8;
    v17.m128_i32[0] = 1258291200;
    *pContext = v16.m128_f32[0];
    v18 = v16.m128_f32[0];
    v19 = _mm_and_ps((__m128)0x80000000, v16);
    v17.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v19), v17).m128_f32[0]) & 0x4B000000
                    | v19.m128_i32[0];
    v16.m128_f32[0] = (float)(v16.m128_f32[0] + v17.m128_f32[0]) - v17.m128_f32[0];
    v20 = v16;
    v20.m128_f32[0] = v16.m128_f32[0] - v18;
    pContext[1] = 0.0;
    m_nActiveParticles = pParticles->m_nActiveParticles;
    m_nMaxAllowedParticles = pParticles->m_nMaxAllowedParticles;
    v23 = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v20, v19).m128_u32[0] & 0x3F800000));
    v24 = m_flCurTime - v15.m128_f32[0];
    flEmitStrength = v23;
    if ( m_nMaxAllowedParticles < m_nActiveParticles + v23 )
    {
      flEmitStrength = m_nMaxAllowedParticles - m_nActiveParticles;
      v23 = m_nMaxAllowedParticles - m_nActiveParticles;
    }
    v25 = m_nActiveParticles + v23;
    v26 = v15.m128_f32[0] / (float)flEmitStrength;
    v40 = v25;
    pParticles->m_nActiveParticles = v25;
    pParticles->m_nPaddedActiveParticles = (v25 + 3) / 4;
    v27 = v26 + v24;
    if ( m_nActiveParticles < v25 )
    {
      if ( v25 - m_nActiveParticles >= 4 )
      {
        v28 = m_nActiveParticles + 1;
        do
        {
          if ( m_flCurTime <= v27 )
            v27 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * (m_nActiveParticles
                                                           / 4)] = v27;
          v29 = v27 + v26;
          if ( m_flCurTime <= v29 )
            v29 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(v28 & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * (v28
                                                           / 4)] = v29;
          v30 = v29 + v26;
          if ( m_flCurTime <= v30 )
            v30 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v28 + 1) & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * ((v28 + 1)
                                                           / 4)] = v30;
          v31 = v30 + v26;
          if ( m_flCurTime <= v31 )
            v31 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v28 - 2) & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * ((v28 + 2)
                                                           / 4)] = v31;
          m_nActiveParticles += 4;
          v28 += 4;
          v27 = v31 + v26;
        }
        while ( m_nActiveParticles < v40 - 3 );
        v25 = v40;
      }
      for ( ; m_nActiveParticles < v25; v27 = v27 + v26 )
      {
        v32 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                               + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                               * (m_nActiveParticles
                                                                / 4)];
        if ( m_flCurTime <= v27 )
          v27 = m_flCurTime;
        ++m_nActiveParticles;
        *v32 = v27;
      }
    }
    if ( !g_bDontMakeSkipToTimeTakeForever )
    {
      if ( v24 <= (float)(m_flCurTime - pParticles->m_pDef.m_pObject->m_flNoDrawTimeToGoToSleep) )
        v24 = m_flCurTime - pParticles->m_pDef.m_pObject->m_flNoDrawTimeToGoToSleep;
      v33 = 0;
      v33.m128_f32[0] = v24;
      pParticles->m_flCurTime = v24;
      pParticles->m_fl4CurTime = _mm_shuffle_ps(v33, v33, 0);
      pParticles->m_flTargetDrawTime = v24;
      flEmitStrengtha = v24;
      if ( m_flCurTime > v24 )
      {
        do
        {
          CParticleCollection::Simulate(this: pParticles, a2: m_nActiveParticles, dt: 0.1);
          v34 = flEmitStrengtha + 0.1;
          flEmitStrengtha = v34;
        }
        while ( m_flCurTime > v34 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D1C0
// Name: private: virtual void C_OP_NoiseEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::InitParams(C_OP_NoiseEmitter *this, CParticleSystemDefinition *pDef)
{
  if ( this->m_flEmissionDuration < 0.0 )
    this->m_flEmissionDuration = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1022D1E0
// Name: private: virtual void C_OP_NoiseEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::StartEmission(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly || this->m_flEmissionDuration == 0.0 )
  {
    pContext[16] = 1;
    ((void (__stdcall *)(_DWORD, CParticleCollection *, _BYTE *))this->SkipToTime)(
      a1: LODWORD(pParticles->m_flCurTime),
      a2: pParticles,
      a3: pContext);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D220
// Name: private: virtual void C_OP_NoiseEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::InitializeContextData(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[2] = this->m_flStartTime;
  *pContext = 1.0;
  pContext[1] = 0.0;
  pContext[3] = 0.0;
  *((_BYTE *)pContext + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D250
// Name: private: virtual void C_OP_NoiseEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::Restart(C_OP_NoiseEmitter *this, CParticleCollection *pParticles, float *pContext)
{
  if ( this->m_flEmissionDuration != 0.0 )
  {
    pContext[2] = this->m_flStartTime + pParticles->m_flCurTime;
    *(_QWORD *)pContext = 1065353216;
    pContext[3] = pParticles->m_flCurTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D2A0
// Name: private: virtual void C_OP_NoiseEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::SkipToTime(
        C_OP_NoiseEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  float *v4; // esi

  v4 = pContext;
  if ( (float)(this->m_flStartTime + pContext[3]) < flTime )
  {
    CParticleCollection::GetHighestControlPoint(this: pParticles);
    CParticleCollection::CheckIfOperatorShouldRun(
      this: pParticles,
      pOp: this,
      pflCurStrength: (float *)&pContext,
      bApplyingParentKillList: false);
    *(_QWORD *)v4 = 1065353216;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022D2F0
// Name: private: virtual unsigned __int64 C_OP_MaintainEmitter::GetNonPositionalControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_OP_MaintainEmitter::GetNonPositionalControlPointMask(C_OP_MaintainEmitter *this)
{
  int m_nScaleControlPoint; // ecx
  int v3; // esi
  int m_nSnapshotControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    v3 = 0;
  else
    v3 = 1LL << m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
    return v3;
  else
    return v3 | (1LL << m_nSnapshotControlPoint);
}

//------------------------------------------------------------------------------
// Address: 0x1022D350
// Name: private: virtual void C_OP_MaintainEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::InitializeContextData(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        int *pContext)
{
  pContext[1] = 0;
  *((_BYTE *)pContext + 8) = 1;
  *pContext = this->m_nParticlesToMaintain;
}

//------------------------------------------------------------------------------
// Address: 0x1022D370
// Name: private: virtual void C_OP_MaintainEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::StartEmission(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  pContext[8] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D380
// Name: private: virtual void C_OP_MaintainEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::StopEmission(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  pContext[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1022D390
// Name: private: virtual void C_OP_MaintainEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::Restart(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[1] = pParticles->m_flCurTime;
  *((_BYTE *)pContext + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1022D3B0
// Name: private: virtual bool C_OP_MaintainEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_MaintainEmitter::MayCreateMoreParticles(
        C_OP_MaintainEmitter *this,
        const CParticleCollection *pParticles,
        _BYTE *pContext)
{
  return pContext[8];
}

//------------------------------------------------------------------------------
// Address: 0x1022D3C0
// Name: private: virtual void C_OP_MaintainEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::InitParams(C_OP_MaintainEmitter *this, CParticleSystemDefinition *pDef)
{
  int m_nScaleControlPointField; // eax
  int m_nScaleControlPoint; // eax
  int m_nSnapshotControlPoint; // eax

  m_nScaleControlPointField = this->m_nScaleControlPointField;
  if ( m_nScaleControlPointField >= 0 )
  {
    if ( m_nScaleControlPointField > 2 )
      m_nScaleControlPointField = 2;
  }
  else
  {
    m_nScaleControlPointField = 0;
  }
  this->m_nScaleControlPointField = m_nScaleControlPointField;
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint >= -1 )
  {
    if ( m_nScaleControlPoint > 64 )
      m_nScaleControlPoint = 64;
  }
  else
  {
    m_nScaleControlPoint = -1;
  }
  this->m_nScaleControlPoint = m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint >= -1 )
  {
    if ( m_nSnapshotControlPoint > 64 )
      m_nSnapshotControlPoint = 64;
    this->m_nSnapshotControlPoint = m_nSnapshotControlPoint;
  }
  else
  {
    this->m_nSnapshotControlPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C2DF0
// Name: C_OP_InstantaneousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_InstantaneousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_InstantaneousEmitter>(__formal: nullptr);
  s_pUnpack_17 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2E10
// Name: C_OP_ContinuousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ContinuousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ContinuousEmitter>(__formal: nullptr);
  s_pUnpack_15 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2E30
// Name: C_OP_NoiseEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_NoiseEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_NoiseEmitter>(__formal: nullptr);
  s_pUnpack_14 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2E50
// Name: C_OP_MaintainEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_MaintainEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_MaintainEmitter>(__formal: nullptr);
  s_pUnpack_16 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022A060
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_InstantaneousEmitter>(class C_OP_InstantaneousEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_InstantaneousEmitter>()
{
  if ( (_S2_13 & 1) == 0 )
  {
    _S2_13 |= 1u;
    dword_1073F2A0 = 3;
    dword_1073F2A4 = 4;
    dword_1073F2A8 = 4;
    dword_1073F2AC = -1;
    dword_1073F2B0 = 0;
    dword_1073F2B4 = 0;
    dword_1073F2B8 = 0;
    dword_1073F2BC = 0;
    dword_1073F2C0 = 0;
    dword_1073F2C4 = (int)"operator end fadein";
    dword_1073F2C8 = (int)"0";
    dword_1073F2CC = 3;
    dword_1073F2D0 = 8;
    dword_1073F2D4 = 4;
    dword_1073F2D8 = -1;
    dword_1073F2DC = 0;
    dword_1073F2E0 = 0;
    dword_1073F2E4 = 0;
    dword_1073F2E8 = 0;
    dword_1073F2EC = 0;
    dword_1073F2F0 = (int)"operator start fadeout";
    dword_1073F2F4 = (int)"0";
    dword_1073F2F8 = 3;
    dword_1073F2FC = 12;
    dword_1073F300 = 4;
    dword_1073F304 = -1;
    dword_1073F308 = 0;
    dword_1073F30C = 0;
    dword_1073F310 = 0;
    dword_1073F314 = 0;
    dword_1073F318 = 0;
    dword_1073F31C = (int)"operator end fadeout";
    dword_1073F320 = (int)"0";
    dword_1073F324 = 3;
    dword_1073F328 = 16;
    dword_1073F32C = 4;
    dword_1073F330 = -1;
    dword_1073F334 = 0;
    dword_1073F338 = 0;
    dword_1073F33C = 0;
    dword_1073F340 = 0;
    dword_1073F344 = 0;
    dword_1073F348 = (int)"operator fade oscillate";
    dword_1073F34C = (int)"0";
    dword_1073F350 = 3;
    dword_1073F354 = 20;
    dword_1073F358 = 4;
    dword_1073F35C = -1;
    dword_1073F360 = 0;
    dword_1073F364 = 0;
    dword_1073F368 = 0;
    dword_1073F36C = 0;
    dword_1073F370 = 0;
    dword_1073F374 = (int)"operator time offset seed";
    dword_1073F378 = (int)"0";
    dword_1073F37C = 2;
    dword_1073F380 = 32;
    dword_1073F384 = 4;
    dword_1073F388 = -1;
    dword_1073F38C = 0;
    dword_1073F390 = 0;
    dword_1073F394 = 0;
    dword_1073F398 = 0;
    dword_1073F39C = 0;
    dword_1073F3A0 = (int)"operator time offset min";
    dword_1073F3A4 = (int)"0";
    dword_1073F3A8 = 3;
    dword_1073F3AC = 24;
    dword_1073F3B0 = 4;
    dword_1073F3B4 = -1;
    dword_1073F3B8 = 0;
    dword_1073F3BC = 0;
    dword_1073F3C0 = 0;
    dword_1073F3C4 = 0;
    dword_1073F3C8 = 0;
    dword_1073F3CC = (int)"operator time offset max";
    dword_1073F3D0 = (int)"0";
    dword_1073F3D4 = 3;
    dword_1073F3D8 = 28;
    dword_1073F3DC = 4;
    dword_1073F3E0 = -1;
    dword_1073F3E4 = 0;
    dword_1073F3E8 = 0;
    dword_1073F3EC = 0;
    dword_1073F3F0 = 0;
    dword_1073F3F4 = 0;
    dword_1073F3F8 = (int)"operator time scale seed";
    dword_1073F3FC = (int)"0";
    dword_1073F400 = 2;
    dword_1073F404 = 48;
    dword_1073F408 = 4;
    dword_1073F40C = -1;
    dword_1073F410 = 0;
    dword_1073F414 = 0;
    dword_1073F418 = 0;
    dword_1073F41C = 0;
    dword_1073F420 = 0;
    dword_1073F424 = (int)"operator time scale min";
    dword_1073F428 = (int)"1";
    dword_1073F42C = 3;
    dword_1073F430 = 52;
    dword_1073F434 = 4;
    dword_1073F438 = -1;
    dword_1073F43C = 0;
    dword_1073F440 = 0;
    dword_1073F444 = 0;
    dword_1073F448 = 0;
    dword_1073F44C = 0;
    dword_1073F450 = (int)"operator time scale max";
    dword_1073F454 = (int)"1";
    dword_1073F458 = 3;
    dword_1073F45C = 56;
    dword_1073F460 = 4;
    dword_1073F464 = -1;
    dword_1073F468 = 0;
    dword_1073F46C = 0;
    dword_1073F470 = 0;
    dword_1073F474 = 0;
    dword_1073F478 = 0;
    dword_1073F47C = (int)"operator time strength random scale max";
    dword_1073F480 = (int)"1";
    dword_1073F484 = 3;
    dword_1073F488 = 44;
    dword_1073F48C = 4;
    dword_1073F490 = -1;
    dword_1073F494 = 0;
    dword_1073F498 = 0;
    dword_1073F49C = 0;
    dword_1073F4A0 = 0;
    dword_1073F4A4 = 0;
    dword_1073F4A8 = (int)"operator strength scale seed";
    dword_1073F4AC = (int)"0";
    dword_1073F4B0 = 2;
    dword_1073F4B4 = 36;
    dword_1073F4B8 = 4;
    dword_1073F4BC = -1;
    dword_1073F4C0 = 0;
    dword_1073F4C4 = 0;
    dword_1073F4C8 = 0;
    dword_1073F4CC = 0;
    dword_1073F4D0 = 0;
    dword_1073F4D4 = (int)"operator strength random scale min";
    dword_1073F4D8 = (int)"1";
    dword_1073F4DC = 3;
    dword_1073F4E0 = 40;
    dword_1073F4E4 = 4;
    dword_1073F4E8 = -1;
    dword_1073F4EC = 0;
    dword_1073F4F0 = 0;
    dword_1073F4F4 = 0;
    dword_1073F4F8 = 0;
    dword_1073F4FC = 0;
    dword_1073F508 = 3;
    dword_1073F560 = 3;
    dword_1073F58C = 3;
    dword_1073F500 = (int)"operator strength random scale max";
    dword_1073F504 = (int)"1";
    dword_1073F50C = 44;
    dword_1073F510 = 4;
    dword_1073F514 = -1;
    dword_1073F518 = 0;
    dword_1073F51C = 0;
    dword_1073F520 = 0;
    dword_1073F524 = 0;
    dword_1073F528 = 0;
    dword_1073F52C = (int)"operator end cap state";
    dword_1073F530 = (int)"-1";
    dword_1073F534 = 2;
    dword_1073F538 = 64;
    dword_1073F53C = 4;
    dword_1073F540 = -1;
    dword_1073F544 = 0;
    dword_1073F548 = 0;
    dword_1073F54C = 0;
    dword_1073F550 = 0;
    dword_1073F554 = 0;
    dword_1073F558 = (int)"emission_start_time";
    dword_1073F55C = (int)"0";
    dword_1073F564 = 96;
    dword_1073F568 = 4;
    dword_1073F56C = -1;
    dword_1073F570 = 0;
    dword_1073F574 = 0;
    dword_1073F578 = 0;
    dword_1073F57C = 0;
    dword_1073F580 = 0;
    dword_1073F584 = (int)"emission_start_time max";
    dword_1073F588 = (int)"-1";
    dword_1073F590 = 100;
    dword_1073F594 = 4;
    dword_1073F598 = -1;
    dword_1073F59C = 0;
    dword_1073F5A0 = 0;
    dword_1073F5A4 = 0;
    dword_1073F5A8 = 0;
    dword_1073F5AC = 0;
    dword_1073F5B0 = (int)"num_to_emit_minimum";
    dword_1073F5B4 = (int)"-1";
    dword_1073F5B8 = 2;
    dword_1073F5BC = 92;
    dword_1073F5C0 = 4;
    dword_1073F5C4 = -1;
    dword_1073F5C8 = 0;
    dword_1073F5CC = 0;
    dword_1073F5D0 = 0;
    dword_1073F5D4 = 0;
    dword_1073F5D8 = 0;
    dword_1073F5DC = (int)"num_to_emit";
    dword_1073F5E0 = (int)"100";
    dword_1073F5E4 = 2;
    dword_1073F5E8 = 88;
    dword_1073F5EC = 4;
    dword_1073F5F0 = -1;
    dword_1073F5F4 = 0;
    dword_1073F5F8 = 0;
    dword_1073F5FC = 0;
    dword_1073F600 = 0;
    dword_1073F604 = 0;
    dword_1073F608 = (int)"maximum emission per frame";
    dword_1073F60C = (int)"-1";
    dword_1073F610 = 2;
    dword_1073F614 = 104;
    dword_1073F618 = 4;
    dword_1073F61C = -1;
    dword_1073F620 = 0;
    dword_1073F624 = 0;
    dword_1073F628 = 0;
    dword_1073F62C = 0;
    dword_1073F630 = 0;
    dword_1073F634 = (int)"emission count scale control point";
    dword_1073F638 = (int)"-1";
    dword_1073F63C = 2;
    dword_1073F664 = (int)"0";
    dword_1073F690 = (int)"-1";
    dword_1073F668 = 2;
    dword_1073F694 = 2;
    dword_1073F640 = 108;
    dword_1073F644 = 4;
    dword_1073F648 = -1;
    dword_1073F64C = 0;
    dword_1073F650 = 0;
    dword_1073F654 = 0;
    dword_1073F658 = 0;
    dword_1073F65C = 0;
    dword_1073F660 = (int)"emission count scale control point field";
    dword_1073F66C = 112;
    dword_1073F670 = 4;
    dword_1073F674 = -1;
    dword_1073F678 = 0;
    dword_1073F67C = 0;
    dword_1073F680 = 0;
    dword_1073F684 = 0;
    dword_1073F688 = 0;
    dword_1073F68C = (int)"control point with snapshot data";
    dword_1073F698 = 116;
    dword_1073F69C = 4;
    dword_1073F6A0 = -1;
    dword_1073F6A4 = 0;
    dword_1073F6A8 = 0;
    dword_1073F6AC = 0;
    dword_1073F6B0 = 0;
    dword_1073F6B4 = 0;
    dword_1073F6B8 = 0;
    dword_1073F6BC = 0;
    dword_1073F6C0 = 0;
    dword_1073F6C4 = 0;
    dword_1073F6C8 = 0;
    dword_1073F6CC = -1;
    dword_1073F6D0 = 0;
    dword_1073F6D4 = 0;
    dword_1073F6D8 = 0;
    dword_1073F6DC = 0;
    dword_1073F6E0 = 0;
  }
  return unpack_14;
}

//------------------------------------------------------------------------------
// Address: 0x1022A950
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ContinuousEmitter>(class C_OP_ContinuousEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ContinuousEmitter>()
{
  if ( (_S3_6 & 1) == 0 )
  {
    _S3_6 |= 1u;
    dword_1073F6F0 = 3;
    dword_1073F6F4 = 4;
    dword_1073F6F8 = 4;
    dword_1073F6FC = -1;
    dword_1073F700 = 0;
    dword_1073F704 = 0;
    dword_1073F708 = 0;
    dword_1073F70C = 0;
    dword_1073F710 = 0;
    dword_1073F714 = (int)"operator end fadein";
    dword_1073F718 = (int)"0";
    dword_1073F71C = 3;
    dword_1073F720 = 8;
    dword_1073F724 = 4;
    dword_1073F728 = -1;
    dword_1073F72C = 0;
    dword_1073F730 = 0;
    dword_1073F734 = 0;
    dword_1073F738 = 0;
    dword_1073F73C = 0;
    dword_1073F740 = (int)"operator start fadeout";
    dword_1073F744 = (int)"0";
    dword_1073F748 = 3;
    dword_1073F74C = 12;
    dword_1073F750 = 4;
    dword_1073F754 = -1;
    dword_1073F758 = 0;
    dword_1073F75C = 0;
    dword_1073F760 = 0;
    dword_1073F764 = 0;
    dword_1073F768 = 0;
    dword_1073F76C = (int)"operator end fadeout";
    dword_1073F770 = (int)"0";
    dword_1073F774 = 3;
    dword_1073F778 = 16;
    dword_1073F77C = 4;
    dword_1073F780 = -1;
    dword_1073F784 = 0;
    dword_1073F788 = 0;
    dword_1073F78C = 0;
    dword_1073F790 = 0;
    dword_1073F794 = 0;
    dword_1073F798 = (int)"operator fade oscillate";
    dword_1073F79C = (int)"0";
    dword_1073F7A0 = 3;
    dword_1073F7A4 = 20;
    dword_1073F7A8 = 4;
    dword_1073F7AC = -1;
    dword_1073F7B0 = 0;
    dword_1073F7B4 = 0;
    dword_1073F7B8 = 0;
    dword_1073F7BC = 0;
    dword_1073F7C0 = 0;
    dword_1073F7C4 = (int)"operator time offset seed";
    dword_1073F7C8 = (int)"0";
    dword_1073F7CC = 2;
    dword_1073F7D0 = 32;
    dword_1073F7D4 = 4;
    dword_1073F7D8 = -1;
    dword_1073F7DC = 0;
    dword_1073F7E0 = 0;
    dword_1073F7E4 = 0;
    dword_1073F7E8 = 0;
    dword_1073F7EC = 0;
    dword_1073F7F0 = (int)"operator time offset min";
    dword_1073F7F4 = (int)"0";
    dword_1073F7F8 = 3;
    dword_1073F7FC = 24;
    dword_1073F800 = 4;
    dword_1073F804 = -1;
    dword_1073F808 = 0;
    dword_1073F80C = 0;
    dword_1073F810 = 0;
    dword_1073F814 = 0;
    dword_1073F818 = 0;
    dword_1073F81C = (int)"operator time offset max";
    dword_1073F820 = (int)"0";
    dword_1073F824 = 3;
    dword_1073F828 = 28;
    dword_1073F82C = 4;
    dword_1073F830 = -1;
    dword_1073F834 = 0;
    dword_1073F838 = 0;
    dword_1073F83C = 0;
    dword_1073F840 = 0;
    dword_1073F844 = 0;
    dword_1073F848 = (int)"operator time scale seed";
    dword_1073F84C = (int)"0";
    dword_1073F850 = 2;
    dword_1073F854 = 48;
    dword_1073F858 = 4;
    dword_1073F85C = -1;
    dword_1073F860 = 0;
    dword_1073F864 = 0;
    dword_1073F868 = 0;
    dword_1073F86C = 0;
    dword_1073F870 = 0;
    dword_1073F874 = (int)"operator time scale min";
    dword_1073F878 = (int)"1";
    dword_1073F87C = 3;
    dword_1073F880 = 52;
    dword_1073F884 = 4;
    dword_1073F888 = -1;
    dword_1073F88C = 0;
    dword_1073F890 = 0;
    dword_1073F894 = 0;
    dword_1073F898 = 0;
    dword_1073F89C = 0;
    dword_1073F8A0 = (int)"operator time scale max";
    dword_1073F8A4 = (int)"1";
    dword_1073F8A8 = 3;
    dword_1073F8AC = 56;
    dword_1073F8B0 = 4;
    dword_1073F8B4 = -1;
    dword_1073F8B8 = 0;
    dword_1073F8BC = 0;
    dword_1073F8C0 = 0;
    dword_1073F8C4 = 0;
    dword_1073F8C8 = 0;
    dword_1073F8CC = (int)"operator time strength random scale max";
    dword_1073F8D0 = (int)"1";
    dword_1073F8D4 = 3;
    dword_1073F8D8 = 44;
    dword_1073F8DC = 4;
    dword_1073F8E0 = -1;
    dword_1073F8E4 = 0;
    dword_1073F8E8 = 0;
    dword_1073F8EC = 0;
    dword_1073F8F0 = 0;
    dword_1073F8F4 = 0;
    dword_1073F8F8 = (int)"operator strength scale seed";
    dword_1073F8FC = (int)"0";
    dword_1073F900 = 2;
    dword_1073F904 = 36;
    dword_1073F908 = 4;
    dword_1073F90C = -1;
    dword_1073F910 = 0;
    dword_1073F914 = 0;
    dword_1073F918 = 0;
    dword_1073F91C = 0;
    dword_1073F920 = 0;
    dword_1073F924 = (int)"operator strength random scale min";
    dword_1073F928 = (int)"1";
    dword_1073F92C = 3;
    dword_1073F930 = 40;
    dword_1073F934 = 4;
    dword_1073F938 = -1;
    dword_1073F93C = 0;
    dword_1073F940 = 0;
    dword_1073F944 = 0;
    dword_1073F948 = 0;
    dword_1073F94C = 0;
    dword_1073F958 = 3;
    dword_1073F9B0 = 3;
    dword_1073F9DC = 3;
    dword_1073FA08 = 3;
    dword_1073FA34 = 3;
    dword_1073F950 = (int)"operator strength random scale max";
    dword_1073F954 = (int)"1";
    dword_1073F95C = 44;
    dword_1073F960 = 4;
    dword_1073F964 = -1;
    dword_1073F968 = 0;
    dword_1073F96C = 0;
    dword_1073F970 = 0;
    dword_1073F974 = 0;
    dword_1073F978 = 0;
    dword_1073F97C = (int)"operator end cap state";
    dword_1073F980 = (int)"-1";
    dword_1073F984 = 2;
    dword_1073F988 = 64;
    dword_1073F98C = 4;
    dword_1073F990 = -1;
    dword_1073F994 = 0;
    dword_1073F998 = 0;
    dword_1073F99C = 0;
    dword_1073F9A0 = 0;
    dword_1073F9A4 = 0;
    dword_1073F9A8 = (int)"emission_start_time";
    dword_1073F9AC = (int)"0";
    dword_1073F9B4 = 92;
    dword_1073F9B8 = 4;
    dword_1073F9BC = -1;
    dword_1073F9C0 = 0;
    dword_1073F9C4 = 0;
    dword_1073F9C8 = 0;
    dword_1073F9CC = 0;
    dword_1073F9D0 = 0;
    dword_1073F9D4 = (int)"emission_rate";
    dword_1073F9D8 = (int)"100";
    dword_1073F9E0 = 96;
    dword_1073F9E4 = 4;
    dword_1073F9E8 = -1;
    dword_1073F9EC = 0;
    dword_1073F9F0 = 0;
    dword_1073F9F4 = 0;
    dword_1073F9F8 = 0;
    dword_1073F9FC = 0;
    dword_1073FA00 = (int)"emission_duration";
    dword_1073FA04 = (int)"0";
    dword_1073FA0C = 88;
    dword_1073FA10 = 4;
    dword_1073FA14 = -1;
    dword_1073FA18 = 0;
    dword_1073FA1C = 0;
    dword_1073FA20 = 0;
    dword_1073FA24 = 0;
    dword_1073FA28 = 0;
    dword_1073FA2C = (int)"scale emission to used control points";
    dword_1073FA30 = (int)"0.0";
    dword_1073FA38 = 104;
    dword_1073FA3C = 4;
    dword_1073FA40 = -1;
    dword_1073FA44 = 0;
    dword_1073FA48 = 0;
    dword_1073FA4C = 0;
    dword_1073FA50 = 0;
    dword_1073FA54 = 0;
    dword_1073FA58 = (int)"use parent particles for emission scaling";
    dword_1073FA5C = (int)"0";
    dword_1073FA60 = 4;
    dword_1073FA64 = 116;
    dword_1073FA68 = 1;
    dword_1073FA6C = -1;
    dword_1073FA70 = 0;
    dword_1073FA74 = 0;
    dword_1073FA78 = 0;
    dword_1073FA7C = 0;
    dword_1073FA80 = 0;
    dword_1073FA84 = (int)"emission count scale control point";
    dword_1073FA88 = (int)"-1";
    dword_1073FA8C = 2;
    dword_1073FAB4 = (int)"0";
    dword_1073FAE0 = (int)"0";
    dword_1073FAEC = 1;
    dword_1073FAB8 = 2;
    dword_1073FA90 = 108;
    dword_1073FA94 = 4;
    dword_1073FA98 = -1;
    dword_1073FA9C = 0;
    dword_1073FAA0 = 0;
    dword_1073FAA4 = 0;
    dword_1073FAA8 = 0;
    dword_1073FAAC = 0;
    dword_1073FAB0 = (int)"emission count scale control point field";
    dword_1073FABC = 112;
    dword_1073FAC0 = 4;
    dword_1073FAC4 = -1;
    dword_1073FAC8 = 0;
    dword_1073FACC = 0;
    dword_1073FAD0 = 0;
    dword_1073FAD4 = 0;
    dword_1073FAD8 = 0;
    dword_1073FADC = (int)"emit particles for killed parent particles";
    dword_1073FAE4 = 4;
    dword_1073FAE8 = 117;
    dword_1073FAF0 = -1;
    dword_1073FAF4 = 0;
    dword_1073FAF8 = 0;
    dword_1073FAFC = 0;
    dword_1073FB00 = 0;
    dword_1073FB04 = 0;
    dword_1073FB08 = 0;
    dword_1073FB0C = 0;
    dword_1073FB10 = 0;
    dword_1073FB14 = 0;
    dword_1073FB18 = 0;
    dword_1073FB1C = -1;
    dword_1073FB20 = 0;
    dword_1073FB24 = 0;
    dword_1073FB28 = 0;
    dword_1073FB2C = 0;
    dword_1073FB30 = 0;
  }
  return unpack_15;
}

//------------------------------------------------------------------------------
// Address: 0x1022B0A0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_NoiseEmitter>(class C_OP_NoiseEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_NoiseEmitter>()
{
  if ( (_S4_3 & 1) == 0 )
  {
    _S4_3 |= 1u;
    dword_1073FB40 = 3;
    dword_1073FB44 = 4;
    dword_1073FB48 = 4;
    dword_1073FB4C = -1;
    dword_1073FB50 = 0;
    dword_1073FB54 = 0;
    dword_1073FB58 = 0;
    dword_1073FB5C = 0;
    dword_1073FB60 = 0;
    dword_1073FB64 = (int)"operator end fadein";
    dword_1073FB68 = (int)"0";
    dword_1073FB6C = 3;
    dword_1073FB70 = 8;
    dword_1073FB74 = 4;
    dword_1073FB78 = -1;
    dword_1073FB7C = 0;
    dword_1073FB80 = 0;
    dword_1073FB84 = 0;
    dword_1073FB88 = 0;
    dword_1073FB8C = 0;
    dword_1073FB90 = (int)"operator start fadeout";
    dword_1073FB94 = (int)"0";
    dword_1073FB98 = 3;
    dword_1073FB9C = 12;
    dword_1073FBA0 = 4;
    dword_1073FBA4 = -1;
    dword_1073FBA8 = 0;
    dword_1073FBAC = 0;
    dword_1073FBB0 = 0;
    dword_1073FBB4 = 0;
    dword_1073FBB8 = 0;
    dword_1073FBBC = (int)"operator end fadeout";
    dword_1073FBC0 = (int)"0";
    dword_1073FBC4 = 3;
    dword_1073FBC8 = 16;
    dword_1073FBCC = 4;
    dword_1073FBD0 = -1;
    dword_1073FBD4 = 0;
    dword_1073FBD8 = 0;
    dword_1073FBDC = 0;
    dword_1073FBE0 = 0;
    dword_1073FBE4 = 0;
    dword_1073FBE8 = (int)"operator fade oscillate";
    dword_1073FBEC = (int)"0";
    dword_1073FBF0 = 3;
    dword_1073FBF4 = 20;
    dword_1073FBF8 = 4;
    dword_1073FBFC = -1;
    dword_1073FC00 = 0;
    dword_1073FC04 = 0;
    dword_1073FC08 = 0;
    dword_1073FC0C = 0;
    dword_1073FC10 = 0;
    dword_1073FC14 = (int)"operator time offset seed";
    dword_1073FC18 = (int)"0";
    dword_1073FC1C = 2;
    dword_1073FC20 = 32;
    dword_1073FC24 = 4;
    dword_1073FC28 = -1;
    dword_1073FC2C = 0;
    dword_1073FC30 = 0;
    dword_1073FC34 = 0;
    dword_1073FC38 = 0;
    dword_1073FC3C = 0;
    dword_1073FC40 = (int)"operator time offset min";
    dword_1073FC44 = (int)"0";
    dword_1073FC48 = 3;
    dword_1073FC4C = 24;
    dword_1073FC50 = 4;
    dword_1073FC54 = -1;
    dword_1073FC58 = 0;
    dword_1073FCA0 = 2;
    dword_1073FC5C = 0;
    dword_1073FC60 = 0;
    dword_1073FC64 = 0;
    dword_1073FC68 = 0;
    dword_1073FC6C = (int)"operator time offset max";
    dword_1073FC70 = (int)"0";
    dword_1073FC74 = 3;
    dword_1073FC78 = 28;
    dword_1073FC7C = 4;
    dword_1073FC80 = -1;
    dword_1073FC84 = 0;
    dword_1073FC88 = 0;
    dword_1073FC8C = 0;
    dword_1073FC90 = 0;
    dword_1073FC94 = 0;
    dword_1073FC98 = (int)"operator time scale seed";
    dword_1073FC9C = (int)"0";
    dword_1073FCA4 = 48;
    dword_1073FCA8 = 4;
    dword_1073FCAC = -1;
    dword_1073FCB0 = 0;
    dword_1073FCB4 = 0;
    dword_1073FCB8 = 0;
    dword_1073FCBC = 0;
    dword_1073FCC0 = 0;
    dword_1073FCC4 = (int)"operator time scale min";
    dword_1073FCC8 = (int)"1";
    dword_1073FCCC = 3;
    dword_1073FCD0 = 52;
    dword_1073FCD4 = 4;
    dword_1073FCD8 = -1;
    dword_1073FCDC = 0;
    dword_1073FCE0 = 0;
    dword_1073FCE4 = 0;
    dword_1073FCE8 = 0;
    dword_1073FCEC = 0;
    dword_1073FCF0 = (int)"operator time scale max";
    dword_1073FCF4 = (int)"1";
    dword_1073FCF8 = 3;
    dword_1073FCFC = 56;
    dword_1073FD00 = 4;
    dword_1073FD04 = -1;
    dword_1073FD08 = 0;
    dword_1073FD0C = 0;
    dword_1073FD10 = 0;
    dword_1073FD14 = 0;
    dword_1073FD18 = 0;
    dword_1073FD1C = (int)"operator time strength random scale max";
    dword_1073FD20 = (int)"1";
    dword_1073FD24 = 3;
    dword_1073FD28 = 44;
    dword_1073FD2C = 4;
    dword_1073FD30 = -1;
    dword_1073FD34 = 0;
    dword_1073FD38 = 0;
    dword_1073FD3C = 0;
    dword_1073FD40 = 0;
    dword_1073FD44 = 0;
    dword_1073FD48 = (int)"operator strength scale seed";
    dword_1073FD4C = (int)"0";
    dword_1073FD50 = 2;
    dword_1073FD54 = 36;
    dword_1073FD58 = 4;
    dword_1073FD5C = -1;
    dword_1073FD60 = 0;
    dword_1073FD64 = 0;
    dword_1073FD68 = 0;
    dword_1073FD6C = 0;
    dword_1073FD70 = 0;
    dword_1073FD74 = (int)"operator strength random scale min";
    dword_1073FD78 = (int)"1";
    dword_1073FD7C = 3;
    dword_1073FD80 = 40;
    dword_1073FD84 = 4;
    dword_1073FD88 = -1;
    dword_1073FD8C = 0;
    dword_1073FD90 = 0;
    dword_1073FD94 = 0;
    dword_1073FD98 = 0;
    dword_1073FD9C = 0;
    dword_1073FDA0 = (int)"operator strength random scale max";
    dword_1073FDA4 = (int)"1";
    dword_1073FDA8 = 3;
    dword_1073FDAC = 44;
    dword_1073FDB0 = 4;
    dword_1073FDB4 = -1;
    dword_1073FDB8 = 0;
    dword_1073FDBC = 0;
    dword_1073FDC0 = 0;
    dword_1073FDC4 = 0;
    dword_1073FDC8 = 0;
    dword_1073FDCC = (int)"operator end cap state";
    dword_1073FDD0 = (int)"-1";
    dword_1073FDD4 = 2;
    dword_1073FDD8 = 64;
    dword_1073FDDC = 4;
    dword_1073FDE0 = -1;
    dword_1073FDE4 = 0;
    dword_1073FDE8 = 0;
    dword_1073FDEC = 0;
    dword_1073FDF0 = 0;
    dword_1073FDF4 = 0;
    dword_1073FDF8 = (int)"emission_start_time";
    dword_1073FDFC = (int)"0";
    dword_1073FE00 = 3;
    dword_1073FE04 = 92;
    dword_1073FE08 = 4;
    dword_1073FE0C = -1;
    dword_1073FE10 = 0;
    dword_1073FE14 = 0;
    dword_1073FE18 = 0;
    dword_1073FE1C = 0;
    dword_1073FE20 = 0;
    dword_1073FE24 = (int)"emission_duration";
    dword_1073FE28 = (int)"0";
    dword_1073FE2C = 3;
    dword_1073FE30 = 88;
    dword_1073FE34 = 4;
    dword_1073FE38 = -1;
    dword_1073FE3C = 0;
    dword_1073FE40 = 0;
    dword_1073FE44 = 0;
    dword_1073FE48 = 0;
    dword_1073FE4C = 0;
    dword_1073FE50 = (int)"scale emission to used control points";
    dword_1073FE54 = (int)"0.0";
    dword_1073FE58 = 3;
    dword_1073FE5C = 100;
    dword_1073FE60 = 4;
    dword_1073FE64 = -1;
    dword_1073FE68 = 0;
    dword_1073FE6C = 0;
    dword_1073FE70 = 0;
    dword_1073FE74 = 0;
    dword_1073FE78 = 0;
    dword_1073FE7C = (int)"time noise coordinate scale";
    dword_1073FE80 = (int)"0.1";
    dword_1073FE84 = 3;
    dword_1073FE88 = 120;
    dword_1073FE8C = 4;
    dword_1073FE90 = -1;
    dword_1073FE94 = 0;
    dword_1073FE98 = 0;
    dword_1073FE9C = 0;
    dword_1073FEA0 = 0;
    dword_1073FEA4 = 0;
    dword_1073FEA8 = (int)"time coordinate offset";
    dword_1073FEAC = (int)"0";
    dword_1073FEB0 = 3;
    dword_1073FEB4 = 108;
    dword_1073FEB8 = 4;
    dword_1073FEBC = -1;
    dword_1073FEC0 = 0;
    dword_1073FEC4 = 0;
    dword_1073FEC8 = 0;
    dword_1073FECC = 0;
    dword_1073FED0 = 0;
    dword_1073FED4 = (int)"absolute value";
    dword_1073FED8 = (int)"0";
    dword_1073FEDC = 4;
    dword_1073FF04 = (int)"0";
    dword_1073FF30 = (int)"0";
    dword_1073FF88 = (int)"0";
    dword_1073FF34 = 3;
    dword_1073FF60 = 3;
    dword_1073FF8C = 3;
    dword_1073FEE4 = 1;
    dword_1073FF10 = 1;
    dword_1073FEE0 = 104;
    dword_1073FEE8 = -1;
    dword_1073FEEC = 0;
    dword_1073FEF0 = 0;
    dword_1073FEF4 = 0;
    dword_1073FEF8 = 0;
    dword_1073FEFC = 0;
    dword_1073FF00 = (int)"invert absolute value";
    dword_1073FF08 = 4;
    dword_1073FF0C = 105;
    dword_1073FF14 = -1;
    dword_1073FF18 = 0;
    dword_1073FF1C = 0;
    dword_1073FF20 = 0;
    dword_1073FF24 = 0;
    dword_1073FF28 = 0;
    dword_1073FF2C = (int)"emission minimum";
    dword_1073FF38 = 112;
    dword_1073FF3C = 4;
    dword_1073FF40 = -1;
    dword_1073FF44 = 0;
    dword_1073FF48 = 0;
    dword_1073FF4C = 0;
    dword_1073FF50 = 0;
    dword_1073FF54 = 0;
    dword_1073FF58 = (int)"emission maximum";
    dword_1073FF5C = (int)"100";
    dword_1073FF64 = 116;
    dword_1073FF68 = 4;
    dword_1073FF6C = -1;
    dword_1073FF70 = 0;
    dword_1073FF74 = 0;
    dword_1073FF78 = 0;
    dword_1073FF7C = 0;
    dword_1073FF80 = 0;
    dword_1073FF84 = (int)"world time noise coordinate scale";
    dword_1073FF90 = 140;
    dword_1073FF94 = 4;
    dword_1073FF98 = -1;
    dword_1073FF9C = 0;
    dword_1073FFA0 = 0;
    dword_1073FFA4 = 0;
    dword_1073FFA8 = 0;
    dword_1073FFAC = 0;
    dword_1073FFB0 = 0;
    dword_1073FFB4 = 0;
    dword_1073FFB8 = 0;
    dword_1073FFBC = 0;
    dword_1073FFC0 = 0;
    dword_1073FFC4 = -1;
    dword_1073FFC8 = 0;
    dword_1073FFCC = 0;
    dword_1073FFD0 = 0;
    dword_1073FFD4 = 0;
    dword_1073FFD8 = 0;
  }
  return unpack_16;
}

//------------------------------------------------------------------------------
// Address: 0x1022B8F0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_MaintainEmitter>(class C_OP_MaintainEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_MaintainEmitter>()
{
  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    dword_1073FFE8 = 3;
    dword_1073FFEC = 4;
    dword_1073FFF0 = 4;
    dword_1073FFF4 = -1;
    dword_1073FFF8 = 0;
    dword_1073FFFC = 0;
    dword_10740000 = 0;
    dword_10740004 = 0;
    dword_10740008 = 0;
    dword_1074000C = (int)"operator end fadein";
    dword_10740010 = (int)"0";
    dword_10740014 = 3;
    dword_10740018 = 8;
    dword_1074001C = 4;
    dword_10740020 = -1;
    dword_10740024 = 0;
    dword_10740028 = 0;
    dword_1074002C = 0;
    dword_10740030 = 0;
    dword_10740034 = 0;
    dword_10740038 = (int)"operator start fadeout";
    dword_1074003C = (int)"0";
    dword_10740040 = 3;
    dword_10740044 = 12;
    dword_10740048 = 4;
    dword_1074004C = -1;
    dword_10740050 = 0;
    dword_10740054 = 0;
    dword_10740058 = 0;
    dword_1074005C = 0;
    dword_10740060 = 0;
    dword_10740064 = (int)"operator end fadeout";
    dword_10740068 = (int)"0";
    dword_1074006C = 3;
    dword_10740070 = 16;
    dword_10740074 = 4;
    dword_10740078 = -1;
    dword_1074007C = 0;
    dword_10740080 = 0;
    dword_10740084 = 0;
    dword_10740088 = 0;
    dword_1074008C = 0;
    dword_10740090 = (int)"operator fade oscillate";
    dword_10740094 = (int)"0";
    dword_10740098 = 3;
    dword_1074009C = 20;
    dword_107400A0 = 4;
    dword_107400A4 = -1;
    dword_107400A8 = 0;
    dword_107400AC = 0;
    dword_107400B0 = 0;
    dword_107400B4 = 0;
    dword_107400B8 = 0;
    dword_107400BC = (int)"operator time offset seed";
    dword_107400C0 = (int)"0";
    dword_107400C4 = 2;
    dword_107400C8 = 32;
    dword_107400CC = 4;
    dword_107400D0 = -1;
    dword_107400D4 = 0;
    dword_107400D8 = 0;
    dword_107400DC = 0;
    dword_107400E0 = 0;
    dword_107400E4 = 0;
    dword_107400E8 = (int)"operator time offset min";
    dword_107400EC = (int)"0";
    dword_107400F0 = 3;
    dword_107400F4 = 24;
    dword_107400F8 = 4;
    dword_107400FC = -1;
    dword_10740100 = 0;
    dword_10740104 = 0;
    dword_10740108 = 0;
    dword_1074010C = 0;
    dword_10740110 = 0;
    dword_10740114 = (int)"operator time offset max";
    dword_10740118 = (int)"0";
    dword_1074011C = 3;
    dword_10740120 = 28;
    dword_10740124 = 4;
    dword_10740128 = -1;
    dword_1074012C = 0;
    dword_10740130 = 0;
    dword_10740134 = 0;
    dword_10740138 = 0;
    dword_1074013C = 0;
    dword_10740140 = (int)"operator time scale seed";
    dword_10740144 = (int)"0";
    dword_10740148 = 2;
    dword_1074014C = 48;
    dword_10740150 = 4;
    dword_10740154 = -1;
    dword_10740158 = 0;
    dword_1074015C = 0;
    dword_10740160 = 0;
    dword_10740164 = 0;
    dword_10740168 = 0;
    dword_1074016C = (int)"operator time scale min";
    dword_10740170 = (int)"1";
    dword_10740174 = 3;
    dword_10740178 = 52;
    dword_1074017C = 4;
    dword_10740180 = -1;
    dword_10740184 = 0;
    dword_10740188 = 0;
    dword_1074018C = 0;
    dword_10740190 = 0;
    dword_10740194 = 0;
    dword_10740198 = (int)"operator time scale max";
    dword_1074019C = (int)"1";
    dword_107401A0 = 3;
    dword_107401A4 = 56;
    dword_107401A8 = 4;
    dword_107401AC = -1;
    dword_107401B0 = 0;
    dword_107401B4 = 0;
    dword_107401B8 = 0;
    dword_107401BC = 0;
    dword_107401C0 = 0;
    dword_107401C4 = (int)"operator time strength random scale max";
    dword_107401C8 = (int)"1";
    dword_107401CC = 3;
    dword_107401D0 = 44;
    dword_107401D4 = 4;
    dword_107401D8 = -1;
    dword_107401DC = 0;
    dword_107401E0 = 0;
    dword_107401E4 = 0;
    dword_107401E8 = 0;
    dword_107401EC = 0;
    dword_107401F0 = (int)"operator strength scale seed";
    dword_107401F4 = (int)"0";
    dword_107401F8 = 2;
    dword_107401FC = 36;
    dword_10740200 = 4;
    dword_10740204 = -1;
    dword_10740208 = 0;
    dword_1074020C = 0;
    dword_10740210 = 0;
    dword_10740214 = 0;
    dword_10740218 = 0;
    dword_1074021C = (int)"operator strength random scale min";
    dword_10740220 = (int)"1";
    dword_10740224 = 3;
    dword_10740228 = 40;
    dword_1074022C = 4;
    dword_10740230 = -1;
    dword_10740234 = 0;
    dword_10740238 = 0;
    dword_1074023C = 0;
    dword_10740240 = 0;
    dword_10740244 = 0;
    dword_10740250 = 3;
    dword_107402A8 = 3;
    dword_10740248 = (int)"operator strength random scale max";
    dword_1074024C = (int)"1";
    dword_10740254 = 44;
    dword_10740258 = 4;
    dword_1074025C = -1;
    dword_10740260 = 0;
    dword_10740264 = 0;
    dword_10740268 = 0;
    dword_1074026C = 0;
    dword_10740270 = 0;
    dword_10740274 = (int)"operator end cap state";
    dword_10740278 = (int)"-1";
    dword_1074027C = 2;
    dword_10740280 = 64;
    dword_10740284 = 4;
    dword_10740288 = -1;
    dword_1074028C = 0;
    dword_10740290 = 0;
    dword_10740294 = 0;
    dword_10740298 = 0;
    dword_1074029C = 0;
    dword_107402A0 = (int)"emission start time";
    dword_107402A4 = (int)"0";
    dword_107402AC = 92;
    dword_107402B0 = 4;
    dword_107402B4 = -1;
    dword_107402B8 = 0;
    dword_107402BC = 0;
    dword_107402C0 = 0;
    dword_107402C4 = 0;
    dword_107402C8 = 0;
    dword_107402CC = (int)"count to maintain";
    dword_107402D0 = (int)"100";
    dword_107402D4 = 2;
    dword_107402D8 = 88;
    dword_107402DC = 4;
    dword_107402E0 = -1;
    dword_107402E4 = 0;
    dword_107402E8 = 0;
    dword_107402EC = 0;
    dword_107402F0 = 0;
    dword_107402F4 = 0;
    dword_107402F8 = (int)"maintain count scale control point";
    dword_107402FC = (int)"-1";
    dword_10740300 = 2;
    dword_10740304 = 96;
    dword_10740308 = 4;
    dword_1074030C = -1;
    dword_10740310 = 0;
    dword_10740314 = 0;
    dword_10740318 = 0;
    dword_1074031C = 0;
    dword_10740320 = 0;
    dword_10740324 = (int)"maintain count scale control point field";
    dword_10740328 = (int)"0";
    dword_1074032C = 2;
    dword_10740330 = 100;
    dword_10740334 = 4;
    dword_10740338 = -1;
    dword_1074033C = 0;
    dword_10740340 = 0;
    dword_10740344 = 0;
    dword_10740348 = 0;
    dword_1074034C = 0;
    dword_10740350 = (int)"control point with snapshot data";
    dword_10740354 = (int)"-1";
    dword_10740358 = 2;
    dword_1074035C = 104;
    dword_10740360 = 4;
    dword_10740364 = -1;
    dword_10740368 = 0;
    dword_1074036C = 0;
    dword_10740370 = 0;
    dword_10740374 = 0;
    dword_10740378 = 0;
    dword_1074037C = 0;
    dword_10740380 = 0;
    dword_10740384 = 0;
    dword_10740388 = 0;
    dword_1074038C = 0;
    dword_10740390 = -1;
    dword_10740394 = 0;
    dword_10740398 = 0;
    dword_1074039C = 0;
    dword_107403A0 = 0;
    dword_107403A4 = 0;
  }
  return unpack_17;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10231B70
// Name: private: virtual unsigned int C_OP_MaintainEmitter::GetRequiredContextBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_OP_MaintainEmitter::GetRequiredContextBytes(C_OP_SpinYaw *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x102329B0
// Name: private: virtual unsigned int C_OP_InstantaneousEmitter::GetRequiredContextBytes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_InstantaneousEmitter::GetRequiredContextBytes(C_OP_InstantaneousEmitter *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x102E3E10
// Name: private: void C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(class CParticleCollection __near *,struct InstantaneousEmitterContext_t __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pCtx,
        bool bForceUpdate)
{
  int m_nSnapshotControlPoint; // eax
  int m_StartingParticlesToEmit; // edx
  CParticleSnapshot *m_pSnapshot; // eax
  int m_nScaleControlPoint; // eax
  float flTime; // xmm0_4
  float m_flCurTime; // xmm1_4
  Vector vecScale; // [esp+10h] [ebp-Ch] BYREF

  if ( bForceUpdate || !pCtx->m_bComputedActualParticlesToEmit )
  {
    m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
    m_StartingParticlesToEmit = pCtx->m_StartingParticlesToEmit;
    if ( m_nSnapshotControlPoint < 0 )
    {
      m_nScaleControlPoint = this->m_nScaleControlPoint;
      if ( m_nScaleControlPoint >= 0 )
      {
        flTime = this->m_flStartTime + pCtx->m_flTimeOffset;
        m_flCurTime = pParticles->m_flCurTime;
        if ( m_flCurTime < flTime || flTime < (float)(m_flCurTime - pParticles->m_flPreviousDt) )
          CParticleCollection::GetControlPointAtPrevTime(
            this: pParticles,
            nControlPoint: m_nScaleControlPoint,
            pControlPoint: &vecScale);
        else
          CParticleCollection::GetControlPointAtTime(
            this: pParticles,
            nControlPoint: m_nScaleControlPoint,
            flTime,
            pControlPoint: &vecScale);
        m_StartingParticlesToEmit = (int)(float)((float)pCtx->m_StartingParticlesToEmit
                                               * *(&vecScale.x + this->m_nScaleControlPointField));
      }
    }
    else
    {
      if ( m_nSnapshotControlPoint >= pParticles->m_nNumControlPointsAllocated - 1 )
        m_nSnapshotControlPoint = pParticles->m_nNumControlPointsAllocated - 1;
      m_pSnapshot = pParticles->m_pCPInfo[m_nSnapshotControlPoint].m_ControlPoint.m_pSnapshot;
      if ( m_pSnapshot != nullptr )
        m_StartingParticlesToEmit = m_pSnapshot->m_pContainer->m_nColumns;
    }
    pCtx->m_bComputedActualParticlesToEmit = true;
    pCtx->m_nRemainingParticles = m_StartingParticlesToEmit < 0 ? 0 : m_StartingParticlesToEmit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E45E0
// Name: private: virtual unsigned int C_OP_InstantaneousEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_InstantaneousEmitter::Emit(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        float flCurStrength,
        float *pContext)
{
  int v7; // eax
  int m_nMaxEmittedPerFrame; // edx
  int m_nActiveParticles; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  unsigned int v13; // eax
  float flStartTime; // [esp+18h] [ebp+10h]

  if ( *((_BYTE *)pContext + 20) == 0 )
    return 0;
  flStartTime = pContext[4] + pContext[3];
  if ( flStartTime > pParticles->m_flCurTime )
    return 0;
  C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(
    this,
    pParticles,
    pCtx: (InstantaneousEmitterContext_t *)pContext,
    bForceUpdate: false);
  v7 = *(_DWORD *)pContext;
  if ( *(int *)pContext <= 0 )
    return 0;
  m_nMaxEmittedPerFrame = this->m_nMaxEmittedPerFrame;
  if ( m_nMaxEmittedPerFrame >= v7 )
    m_nMaxEmittedPerFrame = *(_DWORD *)pContext;
  *(_DWORD *)pContext = v7 - m_nMaxEmittedPerFrame;
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v10 = pParticles->m_nMaxAllowedParticles - m_nActiveParticles;
  if ( v10 >= m_nMaxEmittedPerFrame )
    v10 = m_nMaxEmittedPerFrame;
  if ( v10 == 0 )
    return 0;
  v11 = m_nActiveParticles + v10;
  pParticles->m_nActiveParticles = m_nActiveParticles + v10;
  pParticles->m_nPaddedActiveParticles = (m_nActiveParticles + v10 + 3) / 4;
  if ( m_nActiveParticles < m_nActiveParticles + v10 )
  {
    if ( v10 >= 4 )
    {
      v12 = m_nActiveParticles + 1;
      do
      {
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v12 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v12
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v12 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v12 + 1)
                                                         / 4)] = flStartTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v12 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v12 + 2)
                                                         / 4)] = flStartTime;
        m_nActiveParticles += 4;
        v12 += 4;
      }
      while ( m_nActiveParticles < v11 - 3 );
    }
    for ( ; m_nActiveParticles < v11; pParticles->m_ParticleAttributes.m_pAttributes[8][v13] = flStartTime )
    {
      v13 = (m_nActiveParticles & 3) + pParticles->m_ParticleAttributes.m_nFloatStrides[8] * (m_nActiveParticles / 4);
      ++m_nActiveParticles;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x102E4770
// Name: private: virtual bool C_OP_ContinuousEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_ContinuousEmitter::MayCreateMoreParticles(
        C_OP_ContinuousEmitter *this,
        const CParticleCollection *pParticles,
        float *pContext)
{
  bool result; // al
  float m_flEmissionDuration; // xmm0_4

  result = false;
  if ( *((_BYTE *)pContext + 16) != 0 && !this->m_bInitFromKilledParentParticles && this->m_flEmitRate > 0.0 )
  {
    m_flEmissionDuration = this->m_flEmissionDuration;
    if ( m_flEmissionDuration == 0.0
      || (float)(pParticles->m_flCurTime - pParticles->m_flDt) <= (float)((float)(this->m_flStartTime + pContext[3])
                                                                        + m_flEmissionDuration) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E4ED0
// Name: private: virtual bool C_OP_NoiseEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_NoiseEmitter::MayCreateMoreParticles(
        C_OP_NoiseEmitter *this,
        const CParticleCollection *pParticles,
        float *pContext)
{
  bool result; // al
  float m_flEmissionDuration; // xmm0_4

  result = false;
  if ( *((_BYTE *)pContext + 16) != 0 )
  {
    m_flEmissionDuration = this->m_flEmissionDuration;
    if ( m_flEmissionDuration == 0.0
      || (float)(pParticles->m_flCurTime - pParticles->m_flDt) <= (float)((float)(this->m_flStartTime + pContext[3])
                                                                        + m_flEmissionDuration) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102E56E0
// Name: private: void C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(class CParticleCollection __near *,struct MaintainEmitterContext_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        MaintainEmitterContext_t *pCtx)
{
  int m_nSnapshotControlPoint; // eax
  CParticleSnapshot *m_pSnapshot; // eax
  int m_nColumns; // ecx
  int m_nScaleControlPoint; // eax
  float flTime; // xmm0_4
  float m_flCurTime; // xmm1_4
  Vector vecScale; // [esp+14h] [ebp-Ch] BYREF

  pCtx->m_ActualParticlesToMaintain = this->m_nParticlesToMaintain;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
  {
    m_nScaleControlPoint = this->m_nScaleControlPoint;
    if ( m_nScaleControlPoint >= 0 )
    {
      flTime = this->m_flStartTime + pCtx->m_flTimeOffset;
      m_flCurTime = pParticles->m_flCurTime;
      if ( m_flCurTime < flTime || flTime < (float)(m_flCurTime - pParticles->m_flPreviousDt) )
        CParticleCollection::GetControlPointAtPrevTime(
          this: pParticles,
          nControlPoint: m_nScaleControlPoint,
          pControlPoint: &vecScale);
      else
        CParticleCollection::GetControlPointAtTime(
          this: pParticles,
          nControlPoint: m_nScaleControlPoint,
          flTime,
          pControlPoint: &vecScale);
      m_nColumns = (int)(float)((float)this->m_nParticlesToMaintain * *(&vecScale.x + this->m_nScaleControlPointField));
      goto LABEL_12;
    }
  }
  else
  {
    if ( m_nSnapshotControlPoint >= pParticles->m_nNumControlPointsAllocated - 1 )
      m_nSnapshotControlPoint = pParticles->m_nNumControlPointsAllocated - 1;
    m_pSnapshot = pParticles->m_pCPInfo[m_nSnapshotControlPoint].m_ControlPoint.m_pSnapshot;
    if ( m_pSnapshot != nullptr )
    {
      m_nColumns = m_pSnapshot->m_pContainer->m_nColumns;
LABEL_12:
      pCtx->m_ActualParticlesToMaintain = m_nColumns;
    }
  }
  pCtx->m_ActualParticlesToMaintain &= (pCtx->m_ActualParticlesToMaintain < 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E5DD0
// Name: private: virtual unsigned int C_OP_MaintainEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_MaintainEmitter::Emit(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        float flCurStrength,
        float *pContext)
{
  int m_nActiveParticles; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  float m_flPrevSimTime; // xmm0_4
  int v11; // ebx
  float v12; // xmm1_4
  int v13; // ecx
  float m_flCurTime; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float *v17; // eax
  float flStartTime; // [esp+14h] [ebp+10h]

  if ( *((_BYTE *)pContext + 8) == 0 )
    return 0;
  flStartTime = this->m_flStartTime + pContext[1];
  if ( flStartTime > pParticles->m_flCurTime )
    return 0;
  C_OP_MaintainEmitter::UpdateActualParticlesToMaintain(this, pParticles, pCtx: (MaintainEmitterContext_t *)pContext);
  m_nActiveParticles = pParticles->m_nActiveParticles;
  v7 = *(_DWORD *)pContext;
  if ( m_nActiveParticles >= *(_DWORD *)pContext || v7 <= 0 )
    return 0;
  v8 = pParticles->m_nMaxAllowedParticles - m_nActiveParticles;
  v9 = v7 - m_nActiveParticles;
  if ( v8 >= v9 )
    v8 = v9;
  if ( v8 < 0 )
    return 0;
  m_flPrevSimTime = pParticles->m_flPrevSimTime;
  v11 = m_nActiveParticles + v8;
  pParticles->m_nActiveParticles = m_nActiveParticles + v8;
  pParticles->m_nPaddedActiveParticles = (m_nActiveParticles + v8 + 3) / 4;
  if ( m_flPrevSimTime <= flStartTime )
    m_flPrevSimTime = flStartTime;
  v12 = (float)(pParticles->m_flCurTime - m_flPrevSimTime) / (float)v8;
  if ( m_nActiveParticles < v11 )
  {
    if ( v8 >= 4 )
    {
      v13 = m_nActiveParticles + 1;
      do
      {
        if ( pParticles->m_flCurTime <= m_flPrevSimTime )
          m_flPrevSimTime = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = m_flPrevSimTime;
        m_flCurTime = m_flPrevSimTime + v12;
        if ( pParticles->m_flCurTime <= m_flCurTime )
          m_flCurTime = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v13 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v13
                                                         / 4)] = m_flCurTime;
        v15 = m_flCurTime + v12;
        if ( pParticles->m_flCurTime <= v15 )
          v15 = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v13 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v13 + 1)
                                                         / 4)] = v15;
        v16 = v15 + v12;
        if ( pParticles->m_flCurTime <= v16 )
          v16 = pParticles->m_flCurTime;
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v13 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v13 + 2)
                                                         / 4)] = v16;
        m_nActiveParticles += 4;
        v13 += 4;
        m_flPrevSimTime = v16 + v12;
      }
      while ( m_nActiveParticles < v11 - 3 );
    }
    for ( ; m_nActiveParticles < v11; m_flPrevSimTime = m_flPrevSimTime + v12 )
    {
      v17 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                             + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                             * (m_nActiveParticles
                                                              / 4)];
      if ( pParticles->m_flCurTime <= m_flPrevSimTime )
        m_flPrevSimTime = pParticles->m_flCurTime;
      ++m_nActiveParticles;
      *v17 = m_flPrevSimTime;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x102E5FE0
// Name: void AddBuiltInParticleEmitters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBuiltInParticleEmitters()
{
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: &s_C_OP_ContinuousEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: &s_C_OP_InstantaneousEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: &s_C_OP_NoiseEmitterFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_EMITTER,
    pOpFactory: &s_C_OP_MaintainEmitterFactory);
}

//------------------------------------------------------------------------------
// Address: 0x102E6030
// Name: private: virtual unsigned int C_OP_ContinuousEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_OP_ContinuousEmitter::Emit(
        C_OP_ContinuousEmitter *this,
        float pParticles,
        float flCurStrength,
        float pContext)
{
  float v4; // ebx
  CParticleCollection *v5; // esi
  bool v7; // cc
  float m_flEmissionDuration; // xmm0_4
  float v10; // xmm6_4
  float m_flCurTime; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float HighestControlPoint; // xmm0_4
  int m_nScaleControlPoint; // eax
  float m_flEmissionScale; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  CParticleCollection *m_pParent; // eax
  float v22; // xmm1_4
  float v23; // xmm1_4
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  int v26; // eax
  float v27; // xmm2_4
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  int v30; // ecx
  int m_nActiveParticles; // edi
  int v32; // ebx
  float v33; // xmm6_4
  float v34; // xmm0_4
  int v35; // ecx
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float *v39; // eax
  Vector vecScale; // [esp+14h] [ebp-10h] BYREF
  float flControlPointScale; // [esp+20h] [ebp-4h]

  v4 = pContext;
  v5 = (CParticleCollection *)LODWORD(pParticles);
  v7 = (float)(*(float *)(LODWORD(pContext) + 12) + this->m_flStartTime) <= *(float *)(LODWORD(pParticles) + 36);
  pContext = *(float *)(LODWORD(pContext) + 12) + this->m_flStartTime;
  if ( !v7 )
    return 0;
  if ( this->m_bInitFromKilledParentParticles )
  {
    CParticleOperatorInstance::GetParentKillList(
      this,
      pParticles: (CParticleCollection *)LODWORD(pParticles),
      nNumParticlesToKill: (int *)&pParticles);
    m_flEmissionDuration = this->m_flEmissionDuration;
    v10 = 0.0;
    m_flCurTime = v5->m_flCurTime;
    v12 = (float)SLODWORD(pParticles);
    if ( m_flEmissionDuration != 0.0 )
    {
      v13 = pContext;
      v14 = m_flEmissionDuration + pContext;
      if ( pContext <= m_flCurTime )
      {
        if ( m_flCurTime > v14 )
        {
          m_flCurTime = v14;
          v15 = v14;
          goto LABEL_34;
        }
        v13 = v5->m_flCurTime;
      }
      m_flCurTime = v13;
    }
    v15 = m_flCurTime;
    goto LABEL_34;
  }
  HighestControlPoint = (float)CParticleCollection::GetHighestControlPoint(this: (CParticleCollection *)LODWORD(pParticles));
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  m_flEmissionScale = this->m_flEmissionScale * HighestControlPoint;
  v19 = this->m_flEmitRate * flCurStrength;
  flControlPointScale = m_flEmissionScale;
  pParticles = v19;
  if ( m_nScaleControlPoint >= 0 )
  {
    CParticleCollection::GetControlPointAtTime(
      this: v5,
      nControlPoint: m_nScaleControlPoint,
      flTime: v5->m_flCurTime,
      pControlPoint: &vecScale);
    v20 = *(&vecScale.x + this->m_nScaleControlPointField);
    if ( v20 < 0.0 )
      v20 = 0.0;
    v19 = v20 * pParticles;
    m_flEmissionScale = flControlPointScale;
  }
  if ( m_flEmissionScale != 0.0 || this->m_bScalePerParticle )
  {
    if ( this->m_bScalePerParticle )
    {
      m_pParent = v5->m_pParent;
      if ( m_pParent != nullptr )
        m_flEmissionScale = (float)m_pParent->m_nActiveParticles * this->m_flEmissionScale;
      else
        m_flEmissionScale = this->m_flEmissionScale;
    }
    v19 = v19 * m_flEmissionScale;
  }
  if ( v19 == 0.0 )
    return 0;
  if ( *(_BYTE *)(LODWORD(v4) + 16) == 0 )
    return 0;
  if ( this->m_bInitFromKilledParentParticles )
    return 0;
  if ( this->m_flEmitRate <= 0.0 )
    return 0;
  v22 = this->m_flEmissionDuration;
  if ( v22 != 0.0
    && (float)(v5->m_flCurTime - v5->m_flDt) > (float)((float)(*(float *)(LODWORD(v4) + 12) + this->m_flStartTime) + v22) )
  {
    return 0;
  }
  m_flCurTime = v5->m_flCurTime;
  v15 = m_flCurTime - v5->m_flDt;
  if ( v22 != 0.0 )
  {
    if ( v15 <= pContext )
      v15 = pContext;
    v23 = v22 + pContext;
    if ( v23 <= m_flCurTime )
      m_flCurTime = v23;
  }
  v10 = m_flCurTime - v15;
  v12 = v19 * (float)(m_flCurTime - v15);
LABEL_34:
  v24 = (__m128)(unsigned int)*(_DWORD *)LODWORD(v4);
  v24.m128_f32[0] = v24.m128_f32[0] + v12;
  v25.m128_i32[0] = 1258291200;
  v26 = *(_DWORD *)(LODWORD(v4) + 4);
  v27 = v24.m128_f32[0];
  *(_DWORD *)LODWORD(v4) = v24.m128_i32[0];
  v28 = _mm_and_ps((__m128)0x80000000, v24);
  v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v24, v28), v25).m128_f32[0]) & 0x4B000000
                  | v28.m128_i32[0];
  v24.m128_f32[0] = (float)(v24.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
  v29 = v24;
  v29.m128_f32[0] = v24.m128_f32[0] - v27;
  v30 = (int)(float)((float)(v24.m128_f32[0]
                           - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v29, v28).m128_f32[0]) & 0x3F800000))
                   - (float)v26);
  *(_DWORD *)(LODWORD(v4) + 4) = v30 + v26;
  if ( v30 == 0 )
    return 0;
  m_nActiveParticles = v5->m_nActiveParticles;
  if ( v5->m_nMaxAllowedParticles - m_nActiveParticles < v30 )
    v30 = v5->m_nMaxAllowedParticles - m_nActiveParticles;
  if ( v30 == 0 )
    return 0;
  v32 = m_nActiveParticles + v30;
  v33 = v10 / (float)v30;
  v5->m_nActiveParticles = m_nActiveParticles + v30;
  v5->m_nPaddedActiveParticles = (m_nActiveParticles + v30 + 3) / 4;
  v34 = v33 + v15;
  if ( m_nActiveParticles < m_nActiveParticles + v30 )
  {
    if ( v30 >= 4 )
    {
      v35 = m_nActiveParticles + 1;
      do
      {
        if ( m_flCurTime <= v34 )
          v34 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * (m_nActiveParticles / 4)] = v34;
        v36 = v34 + v33;
        if ( m_flCurTime <= v36 )
          v36 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(v35 & 3) + v5->m_ParticleAttributes.m_nFloatStrides[8] * (v35 / 4)] = v36;
        v37 = v36 + v33;
        if ( m_flCurTime <= v37 )
          v37 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v35 + 1) & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * ((v35 + 1) / 4)] = v37;
        v38 = v37 + v33;
        if ( m_flCurTime <= v38 )
          v38 = m_flCurTime;
        v5->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v35 - 2) & 3)
                                                + v5->m_ParticleAttributes.m_nFloatStrides[8] * ((v35 + 2) / 4)] = v38;
        m_nActiveParticles += 4;
        v35 += 4;
        v34 = v38 + v33;
      }
      while ( m_nActiveParticles < v32 - 3 );
    }
    for ( ; m_nActiveParticles < v32; v34 = v34 + v33 )
    {
      v39 = &v5->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                     + v5->m_ParticleAttributes.m_nFloatStrides[8]
                                                     * (m_nActiveParticles
                                                      / 4)];
      if ( m_flCurTime <= v34 )
        v34 = m_flCurTime;
      ++m_nActiveParticles;
      *v39 = v34;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x102E6400
// Name: private: virtual unsigned int C_OP_NoiseEmitter::Emit(class CParticleCollection __near *,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
unsigned int __userpurge C_OP_NoiseEmitter::Emit@<eax>(
        C_OP_NoiseEmitter *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CParticleCollection *pParticles,
        float flCurStrength,
        _BYTE *pContext)
{
  int HighestControlPoint; // eax
  bool v9; // zf
  float m_flNoiseScale; // xmm1_4
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  __m128 v14; // xmm0
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  __m128 m_flEmissionDuration_low; // xmm0
  float v20; // xmm3_4
  __m128 m_flCurTime_low; // xmm5
  float v22; // xmm7_4
  __m128 v23; // xmm2
  int v24; // eax
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  int v30; // ecx
  int m_nActiveParticles; // edi
  float v32; // eax
  float v33; // ecx
  float v34; // xmm3_4
  float v35; // xmm0_4
  int v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float *v40; // eax
  _BYTE v42[64]; // [esp-Ch] [ebp-7Ch] OVERLAPPED BYREF
  float v43; // [esp+40h] [ebp-30h]
  float v44; // [esp+44h] [ebp-2Ch]
  float v45; // [esp+48h] [ebp-28h]
  float v46; // [esp+4Ch] [ebp-24h]
  float m_flOutputMin; // [esp+50h] [ebp-20h]
  float m_flOutputMax; // [esp+54h] [ebp-1Ch]
  float flControlPointScale; // [esp+58h] [ebp-18h]
  float fMin; // [esp+5Ch] [ebp-14h]
  float fMax; // [esp+60h] [ebp-10h]
  int flAbsScale; // [esp+64h] [ebp-Ch]
  int nAbsVal; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  flAbsScale = a2;
  nAbsVal = retaddr;
  HighestControlPoint = CParticleCollection::GetHighestControlPoint(this: pParticles);
  v9 = !this->m_bAbsVal;
  v46 = this->m_flEmissionScale * (float)HighestControlPoint;
  fMin = NAN;
  flControlPointScale = 0.5;
  if ( !v9 )
  {
    fMin = NAN;
    flControlPointScale = 1.0;
  }
  m_flNoiseScale = this->m_flNoiseScale;
  m_flOutputMin = this->m_flOutputMin;
  m_flOutputMax = this->m_flOutputMax;
  *(float *)&v42[52] = (float)(pParticles->m_flCurTime + this->m_flOffset) * m_flNoiseScale;
  *(float *)&v42[56] = *(float *)&v42[52];
  *(float *)&v42[60] = *(float *)&v42[52];
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: a3, a2: a4));
  v43 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: LODWORD(fMax), a2: flAbsScale));
  v44 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  fMax = COERCE_FLOAT(_Plat_MSTime(a1: LODWORD(fMax), a2: flAbsScale));
  v45 = (double)LODWORD(fMax) * this->m_flWorldTimeScale;
  v11 = 0;
  v11.m128_f32[0] = v43 + *(float *)&v42[52];
  *(__m128 *)v42 = _mm_shuffle_ps(v11, v11, 0);
  v12 = 0;
  v12.m128_f32[0] = v44 + *(float *)&v42[52];
  *(__m128 *)&v42[16] = _mm_shuffle_ps(v12, v12, 0);
  v13 = 0;
  v13.m128_f32[0] = v45 + *(float *)&v42[52];
  v14 = _mm_shuffle_ps(v13, v13, 0);
  *(__m128 *)&v42[32] = v14;
  NoiseSIMD(result: (FourVectors *)v42);
  *(__m128 *)&v42[48] = v14;
  LODWORD(fMax) = LODWORD(fMin) & v14.m128_i32[0];
  if ( this->m_bAbsValInv )
    v15 = 1.0 - fMax;
  else
    v15 = fMax;
  v16 = (float)((float)((float)(m_flOutputMax - m_flOutputMin) * flControlPointScale) * v15)
      + (float)((float)((float)(1.0 - flControlPointScale) * (float)(m_flOutputMax - m_flOutputMin)) + m_flOutputMin);
  if ( v16 >= 0.0 )
  {
    if ( v16 > 2147483600.0 )
      v16 = 2147483600.0;
  }
  else
  {
    v16 = 0.0;
  }
  v17 = v16 * flCurStrength;
  if ( v46 != 0.0 )
    v17 = v17 * v46;
  if ( v17 == 0.0 )
    return 0;
  if ( pContext[16] == 0 )
    return 0;
  m_flEmissionDuration_low = (__m128)LODWORD(this->m_flEmissionDuration);
  if ( m_flEmissionDuration_low.m128_f32[0] != 0.0
    && (float)(pParticles->m_flCurTime - pParticles->m_flDt) > (float)((float)(this->m_flStartTime
                                                                             + *((float *)pContext + 3))
                                                                     + m_flEmissionDuration_low.m128_f32[0]) )
  {
    return 0;
  }
  v20 = this->m_flStartTime + *((float *)pContext + 3);
  m_flCurTime_low = (__m128)LODWORD(pParticles->m_flCurTime);
  if ( v20 > m_flCurTime_low.m128_f32[0] )
    return 0;
  v22 = m_flCurTime_low.m128_f32[0] - pParticles->m_flDt;
  if ( m_flEmissionDuration_low.m128_f32[0] != 0.0 )
  {
    if ( v20 > v22 )
      v22 = this->m_flStartTime + *((float *)pContext + 3);
    m_flEmissionDuration_low.m128_f32[0] = m_flEmissionDuration_low.m128_f32[0] + v20;
    if ( m_flCurTime_low.m128_f32[0] > m_flEmissionDuration_low.m128_f32[0] )
      m_flCurTime_low = m_flEmissionDuration_low;
  }
  v23.m128_i32[0] = 1258291200;
  v24 = *((_DWORD *)pContext + 1);
  v25 = m_flCurTime_low;
  v25.m128_f32[0] = m_flCurTime_low.m128_f32[0] - v22;
  v26 = v25;
  v26.m128_f32[0] = (float)((float)(m_flCurTime_low.m128_f32[0] - v22) * v17) + *(float *)pContext;
  v27 = _mm_and_ps((__m128)0x80000000, v26);
  v23.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v26, v27), v23).m128_f32[0]) & 0x4B000000
                  | v27.m128_i32[0];
  v28 = v26;
  v28.m128_f32[0] = (float)(v26.m128_f32[0] + v23.m128_f32[0]) - v23.m128_f32[0];
  v29 = v28;
  v29.m128_f32[0] = v28.m128_f32[0] - v26.m128_f32[0];
  *(_DWORD *)pContext = v26.m128_i32[0];
  v30 = (int)(float)((float)(v28.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v29, v27).m128_u32[0] & 0x3F800000))
                   - (float)v24);
  *((_DWORD *)pContext + 1) = v30 + v24;
  if ( *(float *)&v30 == 0.0 )
    return 0;
  m_nActiveParticles = pParticles->m_nActiveParticles;
  LODWORD(v32) = pParticles->m_nMaxAllowedParticles - m_nActiveParticles;
  fMax = *(float *)&v30;
  if ( SLODWORD(v32) < v30 )
  {
    fMax = v32;
    *(float *)&v30 = v32;
  }
  if ( v30 <= 0 )
    return 0;
  LODWORD(v33) = m_nActiveParticles + v30;
  v34 = v25.m128_f32[0] / (float)SLODWORD(fMax);
  flControlPointScale = v33;
  *(float *)&pParticles->m_nActiveParticles = v33;
  pParticles->m_nPaddedActiveParticles = (LODWORD(v33) + 3) / 4;
  v35 = v34 + v22;
  if ( m_nActiveParticles < SLODWORD(v33) )
  {
    if ( LODWORD(v33) - m_nActiveParticles >= 4 )
    {
      v36 = m_nActiveParticles + 1;
      do
      {
        if ( m_flCurTime_low.m128_f32[0] <= v35 )
          v35 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (m_nActiveParticles
                                                         / 4)] = v35;
        v37 = v35 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v37 )
          v37 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(v36 & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * (v36
                                                         / 4)] = v37;
        v38 = v37 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v38 )
          v38 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v36 + 1) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v36 + 1)
                                                         / 4)] = v38;
        v39 = v38 + v34;
        if ( m_flCurTime_low.m128_f32[0] <= v39 )
          v39 = m_flCurTime_low.m128_f32[0];
        pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v36 - 2) & 3)
                                                        + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                        * ((v36 + 2)
                                                         / 4)] = v39;
        m_nActiveParticles += 4;
        v36 += 4;
        v35 = v39 + v34;
      }
      while ( m_nActiveParticles < LODWORD(flControlPointScale) - 3 );
      v33 = flControlPointScale;
    }
    for ( ; m_nActiveParticles < SLODWORD(v33); v35 = v35 + v34 )
    {
      v40 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                             + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                             * (m_nActiveParticles
                                                              / 4)];
      if ( m_flCurTime_low.m128_f32[0] <= v35 )
        v35 = m_flCurTime_low.m128_f32[0];
      ++m_nActiveParticles;
      *v40 = v35;
    }
  }
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x102E68D0
// Name: private: virtual unsigned __int64 C_OP_InstantaneousEmitter::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_OP_InstantaneousEmitter::GetReadControlPointMask(C_OP_InstantaneousEmitter *this)
{
  int m_nScaleControlPoint; // ecx
  int v3; // esi
  int m_nSnapshotControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    v3 = 0;
  else
    v3 = 1LL << m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
    return v3;
  else
    return v3 | (1LL << m_nSnapshotControlPoint);
}

//------------------------------------------------------------------------------
// Address: 0x102E6930
// Name: private: virtual unsigned __int64 C_OP_ContinuousEmitter::GetNonPositionalControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_ContinuousEmitter::GetNonPositionalControlPointMask(C_OP_ContinuousEmitter *this)
{
  int m_nScaleControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    return 0;
  else
    return 1LL << m_nScaleControlPoint;
}

//------------------------------------------------------------------------------
// Address: 0x102E6950
// Name: private: virtual void C_OP_InstantaneousEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::StopEmission(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly )
    pContext[20] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E6970
// Name: private: virtual void C_OP_InstantaneousEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::SkipToTime(
        C_OP_InstantaneousEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  if ( flTime > (float)((float)(this->m_flStartTime + pContext[3]) + 2.0) )
    *((_BYTE *)pContext + 20) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E69A0
// Name: private: virtual void C_OP_InstantaneousEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::InitializeContextData(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        int *pContext)
{
  int m_nParticlesToEmit; // eax
  int m_nRandomQueryCount; // edi
  __int16 v5; // bx
  float m_flStartTimeMax; // xmm0_4
  float m_flStartTime; // xmm1_4
  int v8; // eax
  int m_nMinParticlesToEmit; // [esp+4h] [ebp-4h]

  m_nMinParticlesToEmit = this->m_nMinParticlesToEmit;
  m_nParticlesToEmit = this->m_nParticlesToEmit;
  if ( m_nMinParticlesToEmit >= 0 )
  {
    m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
    v5 = m_nRandomQueryCount + pParticles->m_nRandomSeed;
    pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
    m_nParticlesToEmit = m_nMinParticlesToEmit
                       + (int)(float)((float)(m_nParticlesToEmit - m_nMinParticlesToEmit + 1)
                                    * s_pRandomFloats[v5 & 0xFFF]);
  }
  pContext[1] = m_nParticlesToEmit;
  *pContext = m_nParticlesToEmit;
  *((_BYTE *)pContext + 8) = 0;
  pContext[3] = 0;
  *((_BYTE *)pContext + 20) = 1;
  m_flStartTimeMax = this->m_flStartTimeMax;
  if ( m_flStartTimeMax <= 0.0 )
  {
    pContext[4] = SLODWORD(this->m_flStartTime);
  }
  else
  {
    m_flStartTime = this->m_flStartTime;
    v8 = pParticles->m_nRandomQueryCount;
    pParticles->m_nRandomQueryCount = v8 + 1;
    *((float *)pContext + 4) = (float)((float)(m_flStartTimeMax - m_flStartTime)
                                     * s_pRandomFloats[((_WORD)v8 + (unsigned __int16)pParticles->m_nRandomSeed) & 0xFFF])
                             + m_flStartTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6A60
// Name: private: virtual bool C_OP_InstantaneousEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_OP_InstantaneousEmitter::MayCreateMoreParticles(
        C_OP_InstantaneousEmitter *this,
        const CParticleCollection *pParticles,
        int *pContext)
{
  return *((_BYTE *)pContext + 20) != 0 && *pContext > 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E6A80
// Name: private: virtual void C_OP_InstantaneousEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::InitParams(C_OP_InstantaneousEmitter *this, CParticleSystemDefinition *pDef)
{
  int m_nMinParticlesToEmit; // eax
  int m_nParticlesToEmit; // eax
  int m_nMaxParticles; // eax
  int m_nScaleControlPointField; // eax
  int m_nScaleControlPoint; // eax
  int m_nSnapshotControlPoint; // eax

  m_nMinParticlesToEmit = this->m_nMinParticlesToEmit;
  if ( m_nMinParticlesToEmit >= 0 && m_nMinParticlesToEmit > this->m_nParticlesToEmit )
  {
    m_nParticlesToEmit = this->m_nParticlesToEmit;
    this->m_nParticlesToEmit = this->m_nMinParticlesToEmit;
    this->m_nMinParticlesToEmit = m_nParticlesToEmit;
  }
  if ( this->m_nMaxEmittedPerFrame < 0 )
  {
    m_nMaxParticles = pDef->m_nMaxParticles;
    if ( m_nMaxParticles >= 5000 )
      m_nMaxParticles = 5000;
    this->m_nMaxEmittedPerFrame = m_nMaxParticles;
  }
  m_nScaleControlPointField = this->m_nScaleControlPointField;
  if ( m_nScaleControlPointField >= 0 )
  {
    if ( m_nScaleControlPointField > 2 )
      m_nScaleControlPointField = 2;
  }
  else
  {
    m_nScaleControlPointField = 0;
  }
  this->m_nScaleControlPointField = m_nScaleControlPointField;
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint >= -1 )
  {
    if ( m_nScaleControlPoint > 64 )
      m_nScaleControlPoint = 64;
  }
  else
  {
    m_nScaleControlPoint = -1;
  }
  this->m_nScaleControlPoint = m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint >= -1 )
  {
    if ( m_nSnapshotControlPoint > 64 )
      m_nSnapshotControlPoint = 64;
    this->m_nSnapshotControlPoint = m_nSnapshotControlPoint;
  }
  else
  {
    this->m_nSnapshotControlPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6B10
// Name: private: virtual void C_OP_InstantaneousEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::StartEmission(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly )
  {
    C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(this, pParticles, pCtx: pContext, bForceUpdate: true);
    ((void (__thiscall *)(C_OP_InstantaneousEmitter *, _DWORD, CParticleCollection *, InstantaneousEmitterContext_t *))this->SkipToTime)(
      a1: this,
      a2: LODWORD(pParticles->m_flCurTime),
      a3: pParticles,
      a4: pContext);
    pContext->m_bOn = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6B60
// Name: private: virtual void C_OP_InstantaneousEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_InstantaneousEmitter::Restart(
        C_OP_InstantaneousEmitter *this,
        CParticleCollection *pParticles,
        InstantaneousEmitterContext_t *pContext)
{
  float m_flStartTimeMax; // xmm0_4
  int m_nRandomQueryCount; // eax
  float m_flStartTime; // xmm1_4
  __int16 v7; // dx

  C_OP_InstantaneousEmitter::UpdateActualParticlesToEmit(this, pParticles, pCtx: pContext, bForceUpdate: true);
  pContext->m_flTimeOffset = pParticles->m_flCurTime;
  pContext->m_bOn = true;
  m_flStartTimeMax = this->m_flStartTimeMax;
  if ( m_flStartTimeMax <= 0.0 )
  {
    pContext->m_flRandomStartTime = this->m_flStartTime;
  }
  else
  {
    m_nRandomQueryCount = pParticles->m_nRandomQueryCount;
    m_flStartTime = this->m_flStartTime;
    v7 = m_nRandomQueryCount + pParticles->m_nRandomSeed;
    pParticles->m_nRandomQueryCount = m_nRandomQueryCount + 1;
    pContext->m_flRandomStartTime = (float)((float)(m_flStartTimeMax - m_flStartTime) * s_pRandomFloats[v7 & 0xFFF])
                                  + m_flStartTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6BE0
// Name: private: virtual void C_OP_ContinuousEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::InitParams(C_OP_ContinuousEmitter *this, CParticleSystemDefinition *pDef)
{
  if ( this->m_flEmitRate < 0.0 )
    this->m_flEmitRate = 0.0;
  if ( this->m_flEmissionDuration < 0.0 )
    this->m_flEmissionDuration = 0.0;
  this->m_flEmitRate = (float)g_nParticle_Multiplier * this->m_flEmitRate;
}

//------------------------------------------------------------------------------
// Address: 0x102E6C20
// Name: private: virtual void C_OP_NoiseEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::StopEmission(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly || this->m_flEmissionDuration == 0.0 )
    pContext[16] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E6C50
// Name: private: virtual void C_OP_ContinuousEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::InitializeContextData(
        C_OP_ContinuousEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[2] = this->m_flStartTime;
  *(_QWORD *)pContext = 0;
  pContext[3] = 0.0;
  *((_BYTE *)pContext + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E6C80
// Name: private: virtual void C_OP_ContinuousEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::Restart(
        C_OP_ContinuousEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  if ( this->m_flEmissionDuration != 0.0 )
  {
    pContext[2] = this->m_flStartTime + pParticles->m_flCurTime;
    *pContext = 0.0;
    pContext[1] = 0.0;
    pContext[3] = pParticles->m_flCurTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E6CC0
// Name: private: virtual bool C_OP_ContinuousEmitter::ShouldRun(bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_ContinuousEmitter::ShouldRun(C_OP_ContinuousEmitter *this, bool bApplyingParentKillList)
{
  if ( this->m_bInitFromKilledParentParticles )
    return bApplyingParentKillList;
  else
    return !bApplyingParentKillList;
}

//------------------------------------------------------------------------------
// Address: 0x102E6CE0
// Name: private: virtual void C_OP_ContinuousEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_ContinuousEmitter::SkipToTime(
        C_OP_ContinuousEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  int HighestControlPoint; // eax
  float m_flEmitRate; // xmm0_4
  float v8; // xmm1_4
  int m_nScaleControlPoint; // eax
  float v10; // xmm1_4
  float m_flCurTime; // xmm5_4
  float v12; // xmm0_4
  __m128 m_flCurTime_low; // xmm2
  __m128d v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  float v18; // xmm2_4
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  int m_nActiveParticles; // edi
  int m_nMaxAllowedParticles; // eax
  int v23; // ecx
  float v24; // xmm6_4
  int v25; // ecx
  float v26; // xmm4_4
  float v27; // xmm0_4
  int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float *v32; // eax
  __m128 v33; // xmm0
  float v34; // xmm0_4
  Vector vecScale; // [esp+10h] [ebp-18h] BYREF
  float flStartTime; // [esp+1Ch] [ebp-Ch]
  float flControlPointScale; // [esp+20h] [ebp-8h]
  float flEmitStrength; // [esp+24h] [ebp-4h] BYREF
  int i; // [esp+30h] [ebp+8h]
  float ia; // [esp+30h] [ebp+8h]
  float flCurrDrawTime; // [esp+34h] [ebp+Ch]
  void *pContexta; // [esp+38h] [ebp+10h]

  flStartTime = this->m_flStartTime + pContext[3];
  if ( flStartTime < flTime && !this->m_bInitFromKilledParentParticles )
  {
    HighestControlPoint = CParticleCollection::GetHighestControlPoint(this: pParticles);
    m_flEmitRate = this->m_flEmitRate;
    flControlPointScale = this->m_flEmissionScale * (float)HighestControlPoint;
    flCurrDrawTime = m_flEmitRate;
    if ( CParticleCollection::CheckIfOperatorShouldRun(
           this: pParticles,
           pOp: this,
           pflCurStrength: &flEmitStrength,
           bApplyingParentKillList: false) )
    {
      v8 = flEmitStrength * m_flEmitRate;
      flCurrDrawTime = flEmitStrength * m_flEmitRate;
    }
    else
    {
      v8 = m_flEmitRate;
    }
    m_nScaleControlPoint = this->m_nScaleControlPoint;
    if ( m_nScaleControlPoint >= 0 )
    {
      CParticleCollection::GetControlPointAtTime(
        this: pParticles,
        nControlPoint: m_nScaleControlPoint,
        flTime: pParticles->m_flCurTime,
        pControlPoint: &vecScale);
      v10 = *(&vecScale.x + this->m_nScaleControlPointField);
      if ( v10 < 0.0 )
        v10 = 0.0;
      v8 = v10 * flCurrDrawTime;
    }
    if ( flControlPointScale != 0.0 )
      v8 = v8 * flControlPointScale;
    m_flCurTime = pParticles->m_flCurTime;
    v12 = m_flCurTime - flTime;
    if ( this->m_flEmissionDuration != 0.0 && flStartTime > v12 )
      v12 = flStartTime;
    m_flCurTime_low = (__m128)LODWORD(pParticles->m_flCurTime);
    m_flCurTime_low.m128_f32[0] = m_flCurTime - v12;
    v14 = _mm_cvtps_pd(m_flCurTime_low);
    if ( v14.m128d_f64[0] > 4.0 )
      v14 = (__m128d)0x4010000000000000uLL;
    v15 = _mm_cvtpd_ps(v14);
    v16 = v15;
    v16.m128_f32[0] = v15.m128_f32[0] * v8;
    v17.m128_i32[0] = 1258291200;
    *pContext = v16.m128_f32[0];
    v18 = v16.m128_f32[0];
    v19 = _mm_and_ps((__m128)0x80000000, v16);
    v17.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v19), v17).m128_f32[0]) & 0x4B000000
                    | v19.m128_i32[0];
    v16.m128_f32[0] = (float)(v16.m128_f32[0] + v17.m128_f32[0]) - v17.m128_f32[0];
    v20 = v16;
    v20.m128_f32[0] = v16.m128_f32[0] - v18;
    pContext[1] = 0.0;
    m_nActiveParticles = pParticles->m_nActiveParticles;
    m_nMaxAllowedParticles = pParticles->m_nMaxAllowedParticles;
    v23 = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v20, v19).m128_u32[0] & 0x3F800000));
    v24 = m_flCurTime - v15.m128_f32[0];
    i = v23;
    if ( m_nMaxAllowedParticles < m_nActiveParticles + v23 )
    {
      i = m_nMaxAllowedParticles - m_nActiveParticles;
      v23 = m_nMaxAllowedParticles - m_nActiveParticles;
    }
    v25 = m_nActiveParticles + v23;
    v26 = v15.m128_f32[0] / (float)i;
    pContexta = (void *)v25;
    pParticles->m_nActiveParticles = v25;
    pParticles->m_nPaddedActiveParticles = (v25 + 3) / 4;
    v27 = v26 + v24;
    if ( m_nActiveParticles < v25 )
    {
      if ( v25 - m_nActiveParticles >= 4 )
      {
        v28 = m_nActiveParticles + 1;
        do
        {
          if ( m_flCurTime <= v27 )
            v27 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * (m_nActiveParticles
                                                           / 4)] = v27;
          v29 = v27 + v26;
          if ( m_flCurTime <= v29 )
            v29 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(v28 & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * (v28
                                                           / 4)] = v29;
          v30 = v29 + v26;
          if ( m_flCurTime <= v30 )
            v30 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v28 + 1) & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * ((v28 + 1)
                                                           / 4)] = v30;
          v31 = v30 + v26;
          if ( m_flCurTime <= v31 )
            v31 = m_flCurTime;
          pParticles->m_ParticleAttributes.m_pAttributes[8][(((_BYTE)v28 - 2) & 3)
                                                          + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                          * ((v28 + 2)
                                                           / 4)] = v31;
          m_nActiveParticles += 4;
          v28 += 4;
          v27 = v31 + v26;
        }
        while ( m_nActiveParticles < (int)pContexta - 3 );
        v25 = (int)pContexta;
      }
      for ( ; m_nActiveParticles < v25; v27 = v27 + v26 )
      {
        v32 = &pParticles->m_ParticleAttributes.m_pAttributes[8][(m_nActiveParticles & 3)
                                                               + pParticles->m_ParticleAttributes.m_nFloatStrides[8]
                                                               * (m_nActiveParticles
                                                                / 4)];
        if ( m_flCurTime <= v27 )
          v27 = m_flCurTime;
        ++m_nActiveParticles;
        *v32 = v27;
      }
    }
    if ( !g_bDontMakeSkipToTimeTakeForever )
    {
      if ( v24 <= (float)(m_flCurTime - pParticles->m_pDef.m_pObject->m_flNoDrawTimeToGoToSleep) )
        v24 = m_flCurTime - pParticles->m_pDef.m_pObject->m_flNoDrawTimeToGoToSleep;
      v33 = 0;
      v33.m128_f32[0] = v24;
      pParticles->m_flCurTime = v24;
      pParticles->m_fl4CurTime = _mm_shuffle_ps(v33, v33, 0);
      pParticles->m_flTargetDrawTime = v24;
      ia = v24;
      if ( m_flCurTime > v24 )
      {
        do
        {
          CParticleCollection::Simulate(this: pParticles, a2: m_nActiveParticles, dt: 0.1);
          v34 = ia + 0.1;
          ia = v34;
        }
        while ( m_flCurTime > v34 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E7070
// Name: private: virtual void C_OP_NoiseEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::InitParams(C_OP_NoiseEmitter *this, CParticleSystemDefinition *pDef)
{
  if ( this->m_flEmissionDuration < 0.0 )
    this->m_flEmissionDuration = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102E7090
// Name: private: virtual void C_OP_NoiseEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::StartEmission(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  if ( !bInfiniteOnly || this->m_flEmissionDuration == 0.0 )
  {
    pContext[16] = 1;
    ((void (__stdcall *)(_DWORD, CParticleCollection *, _BYTE *))this->SkipToTime)(
      a1: LODWORD(pParticles->m_flCurTime),
      a2: pParticles,
      a3: pContext);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E70D0
// Name: private: virtual void C_OP_NoiseEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::InitializeContextData(
        C_OP_NoiseEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[2] = this->m_flStartTime;
  *pContext = 1.0;
  pContext[1] = 0.0;
  pContext[3] = 0.0;
  *((_BYTE *)pContext + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E7100
// Name: private: virtual void C_OP_NoiseEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::Restart(C_OP_NoiseEmitter *this, CParticleCollection *pParticles, float *pContext)
{
  if ( this->m_flEmissionDuration != 0.0 )
  {
    pContext[2] = this->m_flStartTime + pParticles->m_flCurTime;
    *(_QWORD *)pContext = 1065353216;
    pContext[3] = pParticles->m_flCurTime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E7150
// Name: private: virtual void C_OP_NoiseEmitter::SkipToTime(float,class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_NoiseEmitter::SkipToTime(
        C_OP_NoiseEmitter *this,
        float flTime,
        CParticleCollection *pParticles,
        float *pContext)
{
  float *v4; // esi

  v4 = pContext;
  if ( (float)(this->m_flStartTime + pContext[3]) < flTime )
  {
    CParticleCollection::GetHighestControlPoint(this: pParticles);
    CParticleCollection::CheckIfOperatorShouldRun(
      this: pParticles,
      pOp: this,
      pflCurStrength: (float *)&pContext,
      bApplyingParentKillList: false);
    *(_QWORD *)v4 = 1065353216;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E71B0
// Name: private: virtual unsigned __int64 C_OP_MaintainEmitter::GetNonPositionalControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_OP_MaintainEmitter::GetNonPositionalControlPointMask(C_OP_MaintainEmitter *this)
{
  int m_nScaleControlPoint; // ecx
  int v3; // esi
  int m_nSnapshotControlPoint; // ecx

  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint < 0 )
    v3 = 0;
  else
    v3 = 1LL << m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint < 0 )
    return v3;
  else
    return v3 | (1LL << m_nSnapshotControlPoint);
}

//------------------------------------------------------------------------------
// Address: 0x102E7210
// Name: private: virtual void C_OP_MaintainEmitter::InitializeContextData(class CParticleCollection __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::InitializeContextData(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        int *pContext)
{
  pContext[1] = 0;
  *((_BYTE *)pContext + 8) = 1;
  *pContext = this->m_nParticlesToMaintain;
}

//------------------------------------------------------------------------------
// Address: 0x102E7230
// Name: private: virtual void C_OP_MaintainEmitter::StartEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::StartEmission(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  pContext[8] = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E7240
// Name: private: virtual void C_OP_MaintainEmitter::StopEmission(class CParticleCollection __near *,void __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::StopEmission(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        _BYTE *pContext,
        bool bInfiniteOnly)
{
  pContext[8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102E7250
// Name: private: virtual void C_OP_MaintainEmitter::Restart(class CParticleCollection __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::Restart(
        C_OP_MaintainEmitter *this,
        CParticleCollection *pParticles,
        float *pContext)
{
  pContext[1] = pParticles->m_flCurTime;
  *((_BYTE *)pContext + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E7270
// Name: private: virtual bool C_OP_MaintainEmitter::MayCreateMoreParticles(class CParticleCollection const __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_OP_MaintainEmitter::MayCreateMoreParticles(
        C_OP_MaintainEmitter *this,
        const CParticleCollection *pParticles,
        _BYTE *pContext)
{
  return pContext[8];
}

//------------------------------------------------------------------------------
// Address: 0x102E7280
// Name: private: virtual void C_OP_MaintainEmitter::InitParams(class CParticleSystemDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_MaintainEmitter::InitParams(C_OP_MaintainEmitter *this, CParticleSystemDefinition *pDef)
{
  int m_nScaleControlPointField; // eax
  int m_nScaleControlPoint; // eax
  int m_nSnapshotControlPoint; // eax

  m_nScaleControlPointField = this->m_nScaleControlPointField;
  if ( m_nScaleControlPointField >= 0 )
  {
    if ( m_nScaleControlPointField > 2 )
      m_nScaleControlPointField = 2;
  }
  else
  {
    m_nScaleControlPointField = 0;
  }
  this->m_nScaleControlPointField = m_nScaleControlPointField;
  m_nScaleControlPoint = this->m_nScaleControlPoint;
  if ( m_nScaleControlPoint >= -1 )
  {
    if ( m_nScaleControlPoint > 64 )
      m_nScaleControlPoint = 64;
  }
  else
  {
    m_nScaleControlPoint = -1;
  }
  this->m_nScaleControlPoint = m_nScaleControlPoint;
  m_nSnapshotControlPoint = this->m_nSnapshotControlPoint;
  if ( m_nSnapshotControlPoint >= -1 )
  {
    if ( m_nSnapshotControlPoint > 64 )
      m_nSnapshotControlPoint = 64;
    this->m_nSnapshotControlPoint = m_nSnapshotControlPoint;
  }
  else
  {
    this->m_nSnapshotControlPoint = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042DA10
// Name: C_OP_InstantaneousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_InstantaneousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_InstantaneousEmitter>();
  s_pUnpack_18 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042DA30
// Name: C_OP_ContinuousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ContinuousEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ContinuousEmitter>();
  s_pUnpack_16 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042DA50
// Name: C_OP_NoiseEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_NoiseEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_NoiseEmitter>();
  s_pUnpack_15 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042DA70
// Name: C_OP_MaintainEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_MaintainEmitter_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_MaintainEmitter>();
  s_pUnpack_17 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102329F0
// Name: _C_WeaponMP7_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_WeaponMP7_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBaseGun *)C_BaseEntity::operator new(stAllocateBlock: 0xDB0u);
  v3 = &v2->C_WeaponCSBase::C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBaseGun::C_WeaponCSBaseGun(this: v2);
  *v3 = &C_WeaponMP7::`vftable'{for `IClientUnknown'};
  v3[1] = &C_WeaponMP7::`vftable'{for `IClientRenderable'};
  v3[2] = &C_WeaponMP7::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_WeaponMP7::`vftable'{for `IClientThinkable'};
  v3[4] = &C_WeaponMP7::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x102E3EE0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_InstantaneousEmitter>(class C_OP_InstantaneousEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_InstantaneousEmitter>()
{
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    dword_105C28D0 = 3;
    dword_105C28D4 = 4;
    dword_105C28D8 = 4;
    dword_105C28DC = -1;
    dword_105C28E0 = 0;
    dword_105C28E4 = 0;
    dword_105C28E8 = 0;
    dword_105C28EC = 0;
    dword_105C28F0 = 0;
    dword_105C28F4 = (int)"operator end fadein";
    dword_105C28F8 = (int)"0";
    dword_105C28FC = 3;
    dword_105C2900 = 8;
    dword_105C2904 = 4;
    dword_105C2908 = -1;
    dword_105C290C = 0;
    dword_105C2910 = 0;
    dword_105C2914 = 0;
    dword_105C2918 = 0;
    dword_105C291C = 0;
    dword_105C2920 = (int)"operator start fadeout";
    dword_105C2924 = (int)"0";
    dword_105C2928 = 3;
    dword_105C292C = 12;
    dword_105C2930 = 4;
    dword_105C2934 = -1;
    dword_105C2938 = 0;
    dword_105C293C = 0;
    dword_105C2940 = 0;
    dword_105C2944 = 0;
    dword_105C2948 = 0;
    dword_105C294C = (int)"operator end fadeout";
    dword_105C2950 = (int)"0";
    dword_105C2954 = 3;
    dword_105C2958 = 16;
    dword_105C295C = 4;
    dword_105C2960 = -1;
    dword_105C2964 = 0;
    dword_105C2968 = 0;
    dword_105C296C = 0;
    dword_105C2970 = 0;
    dword_105C2974 = 0;
    dword_105C2978 = (int)"operator fade oscillate";
    dword_105C297C = (int)"0";
    dword_105C2980 = 3;
    dword_105C2984 = 20;
    dword_105C2988 = 4;
    dword_105C298C = -1;
    dword_105C2990 = 0;
    dword_105C2994 = 0;
    dword_105C2998 = 0;
    dword_105C299C = 0;
    dword_105C29A0 = 0;
    dword_105C29A4 = (int)"operator time offset seed";
    dword_105C29A8 = (int)"0";
    dword_105C29AC = 2;
    dword_105C29B0 = 32;
    dword_105C29B4 = 4;
    dword_105C29B8 = -1;
    dword_105C29BC = 0;
    dword_105C29C0 = 0;
    dword_105C29C4 = 0;
    dword_105C29C8 = 0;
    dword_105C29CC = 0;
    dword_105C29D0 = (int)"operator time offset min";
    dword_105C29D4 = (int)"0";
    dword_105C29D8 = 3;
    dword_105C29DC = 24;
    dword_105C29E0 = 4;
    dword_105C29E4 = -1;
    dword_105C29E8 = 0;
    dword_105C29EC = 0;
    dword_105C29F0 = 0;
    dword_105C29F4 = 0;
    dword_105C29F8 = 0;
    dword_105C29FC = (int)"operator time offset max";
    dword_105C2A00 = (int)"0";
    dword_105C2A04 = 3;
    dword_105C2A08 = 28;
    dword_105C2A0C = 4;
    dword_105C2A10 = -1;
    dword_105C2A14 = 0;
    dword_105C2A18 = 0;
    dword_105C2A1C = 0;
    dword_105C2A20 = 0;
    dword_105C2A24 = 0;
    dword_105C2A28 = (int)"operator time scale seed";
    dword_105C2A2C = (int)"0";
    dword_105C2A30 = 2;
    dword_105C2A34 = 48;
    dword_105C2A38 = 4;
    dword_105C2A3C = -1;
    dword_105C2A40 = 0;
    dword_105C2A44 = 0;
    dword_105C2A48 = 0;
    dword_105C2A4C = 0;
    dword_105C2A50 = 0;
    dword_105C2A54 = (int)"operator time scale min";
    dword_105C2A58 = (int)"1";
    dword_105C2A5C = 3;
    dword_105C2A60 = 52;
    dword_105C2A64 = 4;
    dword_105C2A68 = -1;
    dword_105C2A6C = 0;
    dword_105C2A70 = 0;
    dword_105C2A74 = 0;
    dword_105C2A78 = 0;
    dword_105C2A7C = 0;
    dword_105C2A80 = (int)"operator time scale max";
    dword_105C2A84 = (int)"1";
    dword_105C2A88 = 3;
    dword_105C2A8C = 56;
    dword_105C2A90 = 4;
    dword_105C2A94 = -1;
    dword_105C2A98 = 0;
    dword_105C2A9C = 0;
    dword_105C2AA0 = 0;
    dword_105C2AA4 = 0;
    dword_105C2AA8 = 0;
    dword_105C2AAC = (int)"operator time strength random scale max";
    dword_105C2AB0 = (int)"1";
    dword_105C2AB4 = 3;
    dword_105C2AB8 = 44;
    dword_105C2ABC = 4;
    dword_105C2AC0 = -1;
    dword_105C2AC4 = 0;
    dword_105C2AC8 = 0;
    dword_105C2ACC = 0;
    dword_105C2AD0 = 0;
    dword_105C2AD4 = 0;
    dword_105C2AD8 = (int)"operator strength scale seed";
    dword_105C2ADC = (int)"0";
    dword_105C2AE0 = 2;
    dword_105C2AE4 = 36;
    dword_105C2AE8 = 4;
    dword_105C2AEC = -1;
    dword_105C2AF0 = 0;
    dword_105C2AF4 = 0;
    dword_105C2AF8 = 0;
    dword_105C2AFC = 0;
    dword_105C2B00 = 0;
    dword_105C2B04 = (int)"operator strength random scale min";
    dword_105C2B08 = (int)"1";
    dword_105C2B0C = 3;
    dword_105C2B10 = 40;
    dword_105C2B14 = 4;
    dword_105C2B18 = -1;
    dword_105C2B1C = 0;
    dword_105C2B20 = 0;
    dword_105C2B24 = 0;
    dword_105C2B28 = 0;
    dword_105C2B2C = 0;
    dword_105C2B38 = 3;
    dword_105C2B90 = 3;
    dword_105C2BBC = 3;
    dword_105C2B30 = (int)"operator strength random scale max";
    dword_105C2B34 = (int)"1";
    dword_105C2B3C = 44;
    dword_105C2B40 = 4;
    dword_105C2B44 = -1;
    dword_105C2B48 = 0;
    dword_105C2B4C = 0;
    dword_105C2B50 = 0;
    dword_105C2B54 = 0;
    dword_105C2B58 = 0;
    dword_105C2B5C = (int)"operator end cap state";
    dword_105C2B60 = (int)"-1";
    dword_105C2B64 = 2;
    dword_105C2B68 = 64;
    dword_105C2B6C = 4;
    dword_105C2B70 = -1;
    dword_105C2B74 = 0;
    dword_105C2B78 = 0;
    dword_105C2B7C = 0;
    dword_105C2B80 = 0;
    dword_105C2B84 = 0;
    dword_105C2B88 = (int)"emission_start_time";
    dword_105C2B8C = (int)"0";
    dword_105C2B94 = 96;
    dword_105C2B98 = 4;
    dword_105C2B9C = -1;
    dword_105C2BA0 = 0;
    dword_105C2BA4 = 0;
    dword_105C2BA8 = 0;
    dword_105C2BAC = 0;
    dword_105C2BB0 = 0;
    dword_105C2BB4 = (int)"emission_start_time max";
    dword_105C2BB8 = (int)"-1";
    dword_105C2BC0 = 100;
    dword_105C2BC4 = 4;
    dword_105C2BC8 = -1;
    dword_105C2BCC = 0;
    dword_105C2BD0 = 0;
    dword_105C2BD4 = 0;
    dword_105C2BD8 = 0;
    dword_105C2BDC = 0;
    dword_105C2BE0 = (int)"num_to_emit_minimum";
    dword_105C2BE4 = (int)"-1";
    dword_105C2BE8 = 2;
    dword_105C2BEC = 92;
    dword_105C2BF0 = 4;
    dword_105C2BF4 = -1;
    dword_105C2BF8 = 0;
    dword_105C2BFC = 0;
    dword_105C2C00 = 0;
    dword_105C2C04 = 0;
    dword_105C2C08 = 0;
    dword_105C2C0C = (int)"num_to_emit";
    dword_105C2C10 = (int)"100";
    dword_105C2C14 = 2;
    dword_105C2C18 = 88;
    dword_105C2C1C = 4;
    dword_105C2C20 = -1;
    dword_105C2C24 = 0;
    dword_105C2C28 = 0;
    dword_105C2C2C = 0;
    dword_105C2C30 = 0;
    dword_105C2C34 = 0;
    dword_105C2C38 = (int)"maximum emission per frame";
    dword_105C2C3C = (int)"-1";
    dword_105C2C40 = 2;
    dword_105C2C44 = 104;
    dword_105C2C48 = 4;
    dword_105C2C4C = -1;
    dword_105C2C50 = 0;
    dword_105C2C54 = 0;
    dword_105C2C58 = 0;
    dword_105C2C5C = 0;
    dword_105C2C60 = 0;
    dword_105C2C64 = (int)"emission count scale control point";
    dword_105C2C68 = (int)"-1";
    dword_105C2C6C = 2;
    dword_105C2C94 = (int)"0";
    dword_105C2CC0 = (int)"-1";
    dword_105C2C98 = 2;
    dword_105C2CC4 = 2;
    dword_105C2C70 = 108;
    dword_105C2C74 = 4;
    dword_105C2C78 = -1;
    dword_105C2C7C = 0;
    dword_105C2C80 = 0;
    dword_105C2C84 = 0;
    dword_105C2C88 = 0;
    dword_105C2C8C = 0;
    dword_105C2C90 = (int)"emission count scale control point field";
    dword_105C2C9C = 112;
    dword_105C2CA0 = 4;
    dword_105C2CA4 = -1;
    dword_105C2CA8 = 0;
    dword_105C2CAC = 0;
    dword_105C2CB0 = 0;
    dword_105C2CB4 = 0;
    dword_105C2CB8 = 0;
    dword_105C2CBC = (int)"control point with snapshot data";
    dword_105C2CC8 = 116;
    dword_105C2CCC = 4;
    dword_105C2CD0 = -1;
    dword_105C2CD4 = 0;
    dword_105C2CD8 = 0;
    dword_105C2CDC = 0;
    dword_105C2CE0 = 0;
    dword_105C2CE4 = 0;
    dword_105C2CE8 = 0;
    dword_105C2CEC = 0;
    dword_105C2CF0 = 0;
    dword_105C2CF4 = 0;
    dword_105C2CF8 = 0;
    dword_105C2CFC = -1;
    dword_105C2D00 = 0;
    dword_105C2D04 = 0;
    dword_105C2D08 = 0;
    dword_105C2D0C = 0;
    dword_105C2D10 = 0;
  }
  return unpack_15;
}

//------------------------------------------------------------------------------
// Address: 0x102E47D0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ContinuousEmitter>(class C_OP_ContinuousEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ContinuousEmitter>()
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    dword_105C2D20 = 3;
    dword_105C2D24 = 4;
    dword_105C2D28 = 4;
    dword_105C2D2C = -1;
    dword_105C2D30 = 0;
    dword_105C2D34 = 0;
    dword_105C2D38 = 0;
    dword_105C2D3C = 0;
    dword_105C2D40 = 0;
    dword_105C2D44 = (int)"operator end fadein";
    dword_105C2D48 = (int)"0";
    dword_105C2D4C = 3;
    dword_105C2D50 = 8;
    dword_105C2D54 = 4;
    dword_105C2D58 = -1;
    dword_105C2D5C = 0;
    dword_105C2D60 = 0;
    dword_105C2D64 = 0;
    dword_105C2D68 = 0;
    dword_105C2D6C = 0;
    dword_105C2D70 = (int)"operator start fadeout";
    dword_105C2D74 = (int)"0";
    dword_105C2D78 = 3;
    dword_105C2D7C = 12;
    dword_105C2D80 = 4;
    dword_105C2D84 = -1;
    dword_105C2D88 = 0;
    dword_105C2D8C = 0;
    dword_105C2D90 = 0;
    dword_105C2D94 = 0;
    dword_105C2D98 = 0;
    dword_105C2D9C = (int)"operator end fadeout";
    dword_105C2DA0 = (int)"0";
    dword_105C2DA4 = 3;
    dword_105C2DA8 = 16;
    dword_105C2DAC = 4;
    dword_105C2DB0 = -1;
    dword_105C2DB4 = 0;
    dword_105C2DB8 = 0;
    dword_105C2DBC = 0;
    dword_105C2DC0 = 0;
    dword_105C2DC4 = 0;
    dword_105C2DC8 = (int)"operator fade oscillate";
    dword_105C2DCC = (int)"0";
    dword_105C2DD0 = 3;
    dword_105C2DD4 = 20;
    dword_105C2DD8 = 4;
    dword_105C2DDC = -1;
    dword_105C2DE0 = 0;
    dword_105C2DE4 = 0;
    dword_105C2DE8 = 0;
    dword_105C2DEC = 0;
    dword_105C2DF0 = 0;
    dword_105C2DF4 = (int)"operator time offset seed";
    dword_105C2DF8 = (int)"0";
    dword_105C2DFC = 2;
    dword_105C2E00 = 32;
    dword_105C2E04 = 4;
    dword_105C2E08 = -1;
    dword_105C2E0C = 0;
    dword_105C2E10 = 0;
    dword_105C2E14 = 0;
    dword_105C2E18 = 0;
    dword_105C2E1C = 0;
    dword_105C2E20 = (int)"operator time offset min";
    dword_105C2E24 = (int)"0";
    dword_105C2E28 = 3;
    dword_105C2E2C = 24;
    dword_105C2E30 = 4;
    dword_105C2E34 = -1;
    dword_105C2E38 = 0;
    dword_105C2E3C = 0;
    dword_105C2E40 = 0;
    dword_105C2E44 = 0;
    dword_105C2E48 = 0;
    dword_105C2E4C = (int)"operator time offset max";
    dword_105C2E50 = (int)"0";
    dword_105C2E54 = 3;
    dword_105C2E58 = 28;
    dword_105C2E5C = 4;
    dword_105C2E60 = -1;
    dword_105C2E64 = 0;
    dword_105C2E68 = 0;
    dword_105C2E6C = 0;
    dword_105C2E70 = 0;
    dword_105C2E74 = 0;
    dword_105C2E78 = (int)"operator time scale seed";
    dword_105C2E7C = (int)"0";
    dword_105C2E80 = 2;
    dword_105C2E84 = 48;
    dword_105C2E88 = 4;
    dword_105C2E8C = -1;
    dword_105C2E90 = 0;
    dword_105C2E94 = 0;
    dword_105C2E98 = 0;
    dword_105C2E9C = 0;
    dword_105C2EA0 = 0;
    dword_105C2EA4 = (int)"operator time scale min";
    dword_105C2EA8 = (int)"1";
    dword_105C2EAC = 3;
    dword_105C2EB0 = 52;
    dword_105C2EB4 = 4;
    dword_105C2EB8 = -1;
    dword_105C2EBC = 0;
    dword_105C2EC0 = 0;
    dword_105C2EC4 = 0;
    dword_105C2EC8 = 0;
    dword_105C2ECC = 0;
    dword_105C2ED0 = (int)"operator time scale max";
    dword_105C2ED4 = (int)"1";
    dword_105C2ED8 = 3;
    dword_105C2EDC = 56;
    dword_105C2EE0 = 4;
    dword_105C2EE4 = -1;
    dword_105C2EE8 = 0;
    dword_105C2EEC = 0;
    dword_105C2EF0 = 0;
    dword_105C2EF4 = 0;
    dword_105C2EF8 = 0;
    dword_105C2EFC = (int)"operator time strength random scale max";
    dword_105C2F00 = (int)"1";
    dword_105C2F04 = 3;
    dword_105C2F08 = 44;
    dword_105C2F0C = 4;
    dword_105C2F10 = -1;
    dword_105C2F14 = 0;
    dword_105C2F18 = 0;
    dword_105C2F1C = 0;
    dword_105C2F20 = 0;
    dword_105C2F24 = 0;
    dword_105C2F28 = (int)"operator strength scale seed";
    dword_105C2F2C = (int)"0";
    dword_105C2F30 = 2;
    dword_105C2F34 = 36;
    dword_105C2F38 = 4;
    dword_105C2F3C = -1;
    dword_105C2F40 = 0;
    dword_105C2F44 = 0;
    dword_105C2F48 = 0;
    dword_105C2F4C = 0;
    dword_105C2F50 = 0;
    dword_105C2F54 = (int)"operator strength random scale min";
    dword_105C2F58 = (int)"1";
    dword_105C2F5C = 3;
    dword_105C2F60 = 40;
    dword_105C2F64 = 4;
    dword_105C2F68 = -1;
    dword_105C2F6C = 0;
    dword_105C2F70 = 0;
    dword_105C2F74 = 0;
    dword_105C2F78 = 0;
    dword_105C2F7C = 0;
    dword_105C2F88 = 3;
    dword_105C2FE0 = 3;
    dword_105C300C = 3;
    dword_105C3038 = 3;
    dword_105C3064 = 3;
    dword_105C2F80 = (int)"operator strength random scale max";
    dword_105C2F84 = (int)"1";
    dword_105C2F8C = 44;
    dword_105C2F90 = 4;
    dword_105C2F94 = -1;
    dword_105C2F98 = 0;
    dword_105C2F9C = 0;
    dword_105C2FA0 = 0;
    dword_105C2FA4 = 0;
    dword_105C2FA8 = 0;
    dword_105C2FAC = (int)"operator end cap state";
    dword_105C2FB0 = (int)"-1";
    dword_105C2FB4 = 2;
    dword_105C2FB8 = 64;
    dword_105C2FBC = 4;
    dword_105C2FC0 = -1;
    dword_105C2FC4 = 0;
    dword_105C2FC8 = 0;
    dword_105C2FCC = 0;
    dword_105C2FD0 = 0;
    dword_105C2FD4 = 0;
    dword_105C2FD8 = (int)"emission_start_time";
    dword_105C2FDC = (int)"0";
    dword_105C2FE4 = 92;
    dword_105C2FE8 = 4;
    dword_105C2FEC = -1;
    dword_105C2FF0 = 0;
    dword_105C2FF4 = 0;
    dword_105C2FF8 = 0;
    dword_105C2FFC = 0;
    dword_105C3000 = 0;
    dword_105C3004 = (int)"emission_rate";
    dword_105C3008 = (int)"100";
    dword_105C3010 = 96;
    dword_105C3014 = 4;
    dword_105C3018 = -1;
    dword_105C301C = 0;
    dword_105C3020 = 0;
    dword_105C3024 = 0;
    dword_105C3028 = 0;
    dword_105C302C = 0;
    dword_105C3030 = (int)"emission_duration";
    dword_105C3034 = (int)"0";
    dword_105C303C = 88;
    dword_105C3040 = 4;
    dword_105C3044 = -1;
    dword_105C3048 = 0;
    dword_105C304C = 0;
    dword_105C3050 = 0;
    dword_105C3054 = 0;
    dword_105C3058 = 0;
    dword_105C305C = (int)"scale emission to used control points";
    dword_105C3060 = (int)"0.0";
    dword_105C3068 = 104;
    dword_105C306C = 4;
    dword_105C3070 = -1;
    dword_105C3074 = 0;
    dword_105C3078 = 0;
    dword_105C307C = 0;
    dword_105C3080 = 0;
    dword_105C3084 = 0;
    dword_105C3088 = (int)"use parent particles for emission scaling";
    dword_105C308C = (int)"0";
    dword_105C3090 = 4;
    dword_105C3094 = 116;
    dword_105C3098 = 1;
    dword_105C309C = -1;
    dword_105C30A0 = 0;
    dword_105C30A4 = 0;
    dword_105C30A8 = 0;
    dword_105C30AC = 0;
    dword_105C30B0 = 0;
    dword_105C30B4 = (int)"emission count scale control point";
    dword_105C30B8 = (int)"-1";
    dword_105C30BC = 2;
    dword_105C30E4 = (int)"0";
    dword_105C3110 = (int)"0";
    dword_105C311C = 1;
    dword_105C30E8 = 2;
    dword_105C30C0 = 108;
    dword_105C30C4 = 4;
    dword_105C30C8 = -1;
    dword_105C30CC = 0;
    dword_105C30D0 = 0;
    dword_105C30D4 = 0;
    dword_105C30D8 = 0;
    dword_105C30DC = 0;
    dword_105C30E0 = (int)"emission count scale control point field";
    dword_105C30EC = 112;
    dword_105C30F0 = 4;
    dword_105C30F4 = -1;
    dword_105C30F8 = 0;
    dword_105C30FC = 0;
    dword_105C3100 = 0;
    dword_105C3104 = 0;
    dword_105C3108 = 0;
    dword_105C310C = (int)"emit particles for killed parent particles";
    dword_105C3114 = 4;
    dword_105C3118 = 117;
    dword_105C3120 = -1;
    dword_105C3124 = 0;
    dword_105C3128 = 0;
    dword_105C312C = 0;
    dword_105C3130 = 0;
    dword_105C3134 = 0;
    dword_105C3138 = 0;
    dword_105C313C = 0;
    dword_105C3140 = 0;
    dword_105C3144 = 0;
    dword_105C3148 = 0;
    dword_105C314C = -1;
    dword_105C3150 = 0;
    dword_105C3154 = 0;
    dword_105C3158 = 0;
    dword_105C315C = 0;
    dword_105C3160 = 0;
  }
  return unpack_16;
}

//------------------------------------------------------------------------------
// Address: 0x102E4F50
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_NoiseEmitter>(class C_OP_NoiseEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_NoiseEmitter>()
{
  if ( (_S4_1 & 1) == 0 )
  {
    _S4_1 |= 1u;
    dword_105C3170 = 3;
    dword_105C3174 = 4;
    dword_105C3178 = 4;
    dword_105C317C = -1;
    dword_105C3180 = 0;
    dword_105C3184 = 0;
    dword_105C3188 = 0;
    dword_105C318C = 0;
    dword_105C3190 = 0;
    dword_105C3194 = (int)"operator end fadein";
    dword_105C3198 = (int)"0";
    dword_105C319C = 3;
    dword_105C31A0 = 8;
    dword_105C31A4 = 4;
    dword_105C31A8 = -1;
    dword_105C31AC = 0;
    dword_105C31B0 = 0;
    dword_105C31B4 = 0;
    dword_105C31B8 = 0;
    dword_105C31BC = 0;
    dword_105C31C0 = (int)"operator start fadeout";
    dword_105C31C4 = (int)"0";
    dword_105C31C8 = 3;
    dword_105C31CC = 12;
    dword_105C31D0 = 4;
    dword_105C31D4 = -1;
    dword_105C31D8 = 0;
    dword_105C31DC = 0;
    dword_105C31E0 = 0;
    dword_105C31E4 = 0;
    dword_105C31E8 = 0;
    dword_105C31EC = (int)"operator end fadeout";
    dword_105C31F0 = (int)"0";
    dword_105C31F4 = 3;
    dword_105C31F8 = 16;
    dword_105C31FC = 4;
    dword_105C3200 = -1;
    dword_105C3204 = 0;
    dword_105C3208 = 0;
    dword_105C320C = 0;
    dword_105C3210 = 0;
    dword_105C3214 = 0;
    dword_105C3218 = (int)"operator fade oscillate";
    dword_105C321C = (int)"0";
    dword_105C3220 = 3;
    dword_105C3224 = 20;
    dword_105C3228 = 4;
    dword_105C322C = -1;
    dword_105C3230 = 0;
    dword_105C3234 = 0;
    dword_105C3238 = 0;
    dword_105C323C = 0;
    dword_105C3240 = 0;
    dword_105C3244 = (int)"operator time offset seed";
    dword_105C3248 = (int)"0";
    dword_105C324C = 2;
    dword_105C3250 = 32;
    dword_105C3254 = 4;
    dword_105C3258 = -1;
    dword_105C325C = 0;
    dword_105C3260 = 0;
    dword_105C3264 = 0;
    dword_105C3268 = 0;
    dword_105C326C = 0;
    dword_105C3270 = (int)"operator time offset min";
    dword_105C3274 = (int)"0";
    dword_105C3278 = 3;
    dword_105C327C = 24;
    dword_105C3280 = 4;
    dword_105C3284 = -1;
    dword_105C3288 = 0;
    dword_105C32D0 = 2;
    dword_105C328C = 0;
    dword_105C3290 = 0;
    dword_105C3294 = 0;
    dword_105C3298 = 0;
    dword_105C329C = (int)"operator time offset max";
    dword_105C32A0 = (int)"0";
    dword_105C32A4 = 3;
    dword_105C32A8 = 28;
    dword_105C32AC = 4;
    dword_105C32B0 = -1;
    dword_105C32B4 = 0;
    dword_105C32B8 = 0;
    dword_105C32BC = 0;
    dword_105C32C0 = 0;
    dword_105C32C4 = 0;
    dword_105C32C8 = (int)"operator time scale seed";
    dword_105C32CC = (int)"0";
    dword_105C32D4 = 48;
    dword_105C32D8 = 4;
    dword_105C32DC = -1;
    dword_105C32E0 = 0;
    dword_105C32E4 = 0;
    dword_105C32E8 = 0;
    dword_105C32EC = 0;
    dword_105C32F0 = 0;
    dword_105C32F4 = (int)"operator time scale min";
    dword_105C32F8 = (int)"1";
    dword_105C32FC = 3;
    dword_105C3300 = 52;
    dword_105C3304 = 4;
    dword_105C3308 = -1;
    dword_105C330C = 0;
    dword_105C3310 = 0;
    dword_105C3314 = 0;
    dword_105C3318 = 0;
    dword_105C331C = 0;
    dword_105C3320 = (int)"operator time scale max";
    dword_105C3324 = (int)"1";
    dword_105C3328 = 3;
    dword_105C332C = 56;
    dword_105C3330 = 4;
    dword_105C3334 = -1;
    dword_105C3338 = 0;
    dword_105C333C = 0;
    dword_105C3340 = 0;
    dword_105C3344 = 0;
    dword_105C3348 = 0;
    dword_105C334C = (int)"operator time strength random scale max";
    dword_105C3350 = (int)"1";
    dword_105C3354 = 3;
    dword_105C3358 = 44;
    dword_105C335C = 4;
    dword_105C3360 = -1;
    dword_105C3364 = 0;
    dword_105C3368 = 0;
    dword_105C336C = 0;
    dword_105C3370 = 0;
    dword_105C3374 = 0;
    dword_105C3378 = (int)"operator strength scale seed";
    dword_105C337C = (int)"0";
    dword_105C3380 = 2;
    dword_105C3384 = 36;
    dword_105C3388 = 4;
    dword_105C338C = -1;
    dword_105C3390 = 0;
    dword_105C3394 = 0;
    dword_105C3398 = 0;
    dword_105C339C = 0;
    dword_105C33A0 = 0;
    dword_105C33A4 = (int)"operator strength random scale min";
    dword_105C33A8 = (int)"1";
    dword_105C33AC = 3;
    dword_105C33B0 = 40;
    dword_105C33B4 = 4;
    dword_105C33B8 = -1;
    dword_105C33BC = 0;
    dword_105C33C0 = 0;
    dword_105C33C4 = 0;
    dword_105C33C8 = 0;
    dword_105C33CC = 0;
    dword_105C33D0 = (int)"operator strength random scale max";
    dword_105C33D4 = (int)"1";
    dword_105C33D8 = 3;
    dword_105C33DC = 44;
    dword_105C33E0 = 4;
    dword_105C33E4 = -1;
    dword_105C33E8 = 0;
    dword_105C33EC = 0;
    dword_105C33F0 = 0;
    dword_105C33F4 = 0;
    dword_105C33F8 = 0;
    dword_105C33FC = (int)"operator end cap state";
    dword_105C3400 = (int)"-1";
    dword_105C3404 = 2;
    dword_105C3408 = 64;
    dword_105C340C = 4;
    dword_105C3410 = -1;
    dword_105C3414 = 0;
    dword_105C3418 = 0;
    dword_105C341C = 0;
    dword_105C3420 = 0;
    dword_105C3424 = 0;
    dword_105C3428 = (int)"emission_start_time";
    dword_105C342C = (int)"0";
    dword_105C3430 = 3;
    dword_105C3434 = 92;
    dword_105C3438 = 4;
    dword_105C343C = -1;
    dword_105C3440 = 0;
    dword_105C3444 = 0;
    dword_105C3448 = 0;
    dword_105C344C = 0;
    dword_105C3450 = 0;
    dword_105C3454 = (int)"emission_duration";
    dword_105C3458 = (int)"0";
    dword_105C345C = 3;
    dword_105C3460 = 88;
    dword_105C3464 = 4;
    dword_105C3468 = -1;
    dword_105C346C = 0;
    dword_105C3470 = 0;
    dword_105C3474 = 0;
    dword_105C3478 = 0;
    dword_105C347C = 0;
    dword_105C3480 = (int)"scale emission to used control points";
    dword_105C3484 = (int)"0.0";
    dword_105C3488 = 3;
    dword_105C348C = 100;
    dword_105C3490 = 4;
    dword_105C3494 = -1;
    dword_105C3498 = 0;
    dword_105C349C = 0;
    dword_105C34A0 = 0;
    dword_105C34A4 = 0;
    dword_105C34A8 = 0;
    dword_105C34AC = (int)"time noise coordinate scale";
    dword_105C34B0 = (int)"0.1";
    dword_105C34B4 = 3;
    dword_105C34B8 = 120;
    dword_105C34BC = 4;
    dword_105C34C0 = -1;
    dword_105C34C4 = 0;
    dword_105C34C8 = 0;
    dword_105C34CC = 0;
    dword_105C34D0 = 0;
    dword_105C34D4 = 0;
    dword_105C34D8 = (int)"time coordinate offset";
    dword_105C34DC = (int)"0";
    dword_105C34E0 = 3;
    dword_105C34E4 = 108;
    dword_105C34E8 = 4;
    dword_105C34EC = -1;
    dword_105C34F0 = 0;
    dword_105C34F4 = 0;
    dword_105C34F8 = 0;
    dword_105C34FC = 0;
    dword_105C3500 = 0;
    dword_105C3504 = (int)"absolute value";
    dword_105C3508 = (int)"0";
    dword_105C350C = 4;
    dword_105C3534 = (int)"0";
    dword_105C3560 = (int)"0";
    dword_105C35B8 = (int)"0";
    dword_105C3564 = 3;
    dword_105C3590 = 3;
    dword_105C35BC = 3;
    dword_105C3514 = 1;
    dword_105C3540 = 1;
    dword_105C3510 = 104;
    dword_105C3518 = -1;
    dword_105C351C = 0;
    dword_105C3520 = 0;
    dword_105C3524 = 0;
    dword_105C3528 = 0;
    dword_105C352C = 0;
    dword_105C3530 = (int)"invert absolute value";
    dword_105C3538 = 4;
    dword_105C353C = 105;
    dword_105C3544 = -1;
    dword_105C3548 = 0;
    dword_105C354C = 0;
    dword_105C3550 = 0;
    dword_105C3554 = 0;
    dword_105C3558 = 0;
    dword_105C355C = (int)"emission minimum";
    dword_105C3568 = 112;
    dword_105C356C = 4;
    dword_105C3570 = -1;
    dword_105C3574 = 0;
    dword_105C3578 = 0;
    dword_105C357C = 0;
    dword_105C3580 = 0;
    dword_105C3584 = 0;
    dword_105C3588 = (int)"emission maximum";
    dword_105C358C = (int)"100";
    dword_105C3594 = 116;
    dword_105C3598 = 4;
    dword_105C359C = -1;
    dword_105C35A0 = 0;
    dword_105C35A4 = 0;
    dword_105C35A8 = 0;
    dword_105C35AC = 0;
    dword_105C35B0 = 0;
    dword_105C35B4 = (int)"world time noise coordinate scale";
    dword_105C35C0 = 140;
    dword_105C35C4 = 4;
    dword_105C35C8 = -1;
    dword_105C35CC = 0;
    dword_105C35D0 = 0;
    dword_105C35D4 = 0;
    dword_105C35D8 = 0;
    dword_105C35DC = 0;
    dword_105C35E0 = 0;
    dword_105C35E4 = 0;
    dword_105C35E8 = 0;
    dword_105C35EC = 0;
    dword_105C35F0 = 0;
    dword_105C35F4 = -1;
    dword_105C35F8 = 0;
    dword_105C35FC = 0;
    dword_105C3600 = 0;
    dword_105C3604 = 0;
    dword_105C3608 = 0;
  }
  return unpack_17;
}

//------------------------------------------------------------------------------
// Address: 0x102E57A0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_MaintainEmitter>(class C_OP_MaintainEmitter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_MaintainEmitter>()
{
  if ( (_S5_241 & 1) == 0 )
  {
    _S5_241 |= 1u;
    dword_105C3618 = 3;
    dword_105C361C = 4;
    dword_105C3620 = 4;
    dword_105C3624 = -1;
    dword_105C3628 = 0;
    dword_105C362C = 0;
    dword_105C3630 = 0;
    dword_105C3634 = 0;
    dword_105C3638 = 0;
    dword_105C363C = (int)"operator end fadein";
    dword_105C3640 = (int)"0";
    dword_105C3644 = 3;
    dword_105C3648 = 8;
    dword_105C364C = 4;
    dword_105C3650 = -1;
    dword_105C3654 = 0;
    dword_105C3658 = 0;
    dword_105C365C = 0;
    dword_105C3660 = 0;
    dword_105C3664 = 0;
    dword_105C3668 = (int)"operator start fadeout";
    dword_105C366C = (int)"0";
    dword_105C3670 = 3;
    dword_105C3674 = 12;
    dword_105C3678 = 4;
    dword_105C367C = -1;
    dword_105C3680 = 0;
    dword_105C3684 = 0;
    dword_105C3688 = 0;
    dword_105C368C = 0;
    dword_105C3690 = 0;
    dword_105C3694 = (int)"operator end fadeout";
    dword_105C3698 = (int)"0";
    dword_105C369C = 3;
    dword_105C36A0 = 16;
    dword_105C36A4 = 4;
    dword_105C36A8 = -1;
    dword_105C36AC = 0;
    dword_105C36B0 = 0;
    dword_105C36B4 = 0;
    dword_105C36B8 = 0;
    dword_105C36BC = 0;
    dword_105C36C0 = (int)"operator fade oscillate";
    dword_105C36C4 = (int)"0";
    dword_105C36C8 = 3;
    dword_105C36CC = 20;
    dword_105C36D0 = 4;
    dword_105C36D4 = -1;
    dword_105C36D8 = 0;
    dword_105C36DC = 0;
    dword_105C36E0 = 0;
    dword_105C36E4 = 0;
    dword_105C36E8 = 0;
    dword_105C36EC = (int)"operator time offset seed";
    dword_105C36F0 = (int)"0";
    dword_105C36F4 = 2;
    dword_105C36F8 = 32;
    dword_105C36FC = 4;
    dword_105C3700 = -1;
    dword_105C3704 = 0;
    dword_105C3708 = 0;
    dword_105C370C = 0;
    dword_105C3710 = 0;
    dword_105C3714 = 0;
    dword_105C3718 = (int)"operator time offset min";
    dword_105C371C = (int)"0";
    dword_105C3720 = 3;
    dword_105C3724 = 24;
    dword_105C3728 = 4;
    dword_105C372C = -1;
    dword_105C3730 = 0;
    dword_105C3734 = 0;
    dword_105C3738 = 0;
    dword_105C373C = 0;
    dword_105C3740 = 0;
    dword_105C3744 = (int)"operator time offset max";
    dword_105C3748 = (int)"0";
    dword_105C374C = 3;
    dword_105C3750 = 28;
    dword_105C3754 = 4;
    dword_105C3758 = -1;
    dword_105C375C = 0;
    dword_105C3760 = 0;
    dword_105C3764 = 0;
    dword_105C3768 = 0;
    dword_105C376C = 0;
    dword_105C3770 = (int)"operator time scale seed";
    dword_105C3774 = (int)"0";
    dword_105C3778 = 2;
    dword_105C377C = 48;
    dword_105C3780 = 4;
    dword_105C3784 = -1;
    dword_105C3788 = 0;
    dword_105C378C = 0;
    dword_105C3790 = 0;
    dword_105C3794 = 0;
    dword_105C3798 = 0;
    dword_105C379C = (int)"operator time scale min";
    dword_105C37A0 = (int)"1";
    dword_105C37A4 = 3;
    dword_105C37A8 = 52;
    dword_105C37AC = 4;
    dword_105C37B0 = -1;
    dword_105C37B4 = 0;
    dword_105C37B8 = 0;
    dword_105C37BC = 0;
    dword_105C37C0 = 0;
    dword_105C37C4 = 0;
    dword_105C37C8 = (int)"operator time scale max";
    dword_105C37CC = (int)"1";
    dword_105C37D0 = 3;
    dword_105C37D4 = 56;
    dword_105C37D8 = 4;
    dword_105C37DC = -1;
    dword_105C37E0 = 0;
    dword_105C37E4 = 0;
    dword_105C37E8 = 0;
    dword_105C37EC = 0;
    dword_105C37F0 = 0;
    dword_105C37F4 = (int)"operator time strength random scale max";
    dword_105C37F8 = (int)"1";
    dword_105C37FC = 3;
    dword_105C3800 = 44;
    dword_105C3804 = 4;
    dword_105C3808 = -1;
    dword_105C380C = 0;
    dword_105C3810 = 0;
    dword_105C3814 = 0;
    dword_105C3818 = 0;
    dword_105C381C = 0;
    dword_105C3820 = (int)"operator strength scale seed";
    dword_105C3824 = (int)"0";
    dword_105C3828 = 2;
    dword_105C382C = 36;
    dword_105C3830 = 4;
    dword_105C3834 = -1;
    dword_105C3838 = 0;
    dword_105C383C = 0;
    dword_105C3840 = 0;
    dword_105C3844 = 0;
    dword_105C3848 = 0;
    dword_105C384C = (int)"operator strength random scale min";
    dword_105C3850 = (int)"1";
    dword_105C3854 = 3;
    dword_105C3858 = 40;
    dword_105C385C = 4;
    dword_105C3860 = -1;
    dword_105C3864 = 0;
    dword_105C3868 = 0;
    dword_105C386C = 0;
    dword_105C3870 = 0;
    dword_105C3874 = 0;
    dword_105C3880 = 3;
    dword_105C38D8 = 3;
    dword_105C3878 = (int)"operator strength random scale max";
    dword_105C387C = (int)"1";
    dword_105C3884 = 44;
    dword_105C3888 = 4;
    dword_105C388C = -1;
    dword_105C3890 = 0;
    dword_105C3894 = 0;
    dword_105C3898 = 0;
    dword_105C389C = 0;
    dword_105C38A0 = 0;
    dword_105C38A4 = (int)"operator end cap state";
    dword_105C38A8 = (int)"-1";
    dword_105C38AC = 2;
    dword_105C38B0 = 64;
    dword_105C38B4 = 4;
    dword_105C38B8 = -1;
    dword_105C38BC = 0;
    dword_105C38C0 = 0;
    dword_105C38C4 = 0;
    dword_105C38C8 = 0;
    dword_105C38CC = 0;
    dword_105C38D0 = (int)"emission start time";
    dword_105C38D4 = (int)"0";
    dword_105C38DC = 92;
    dword_105C38E0 = 4;
    dword_105C38E4 = -1;
    dword_105C38E8 = 0;
    dword_105C38EC = 0;
    dword_105C38F0 = 0;
    dword_105C38F4 = 0;
    dword_105C38F8 = 0;
    dword_105C38FC = (int)"count to maintain";
    dword_105C3900 = (int)"100";
    dword_105C3904 = 2;
    dword_105C3908 = 88;
    dword_105C390C = 4;
    dword_105C3910 = -1;
    dword_105C3914 = 0;
    dword_105C3918 = 0;
    dword_105C391C = 0;
    dword_105C3920 = 0;
    dword_105C3924 = 0;
    dword_105C3928 = (int)"maintain count scale control point";
    dword_105C392C = (int)"-1";
    dword_105C3930 = 2;
    dword_105C3934 = 96;
    dword_105C3938 = 4;
    dword_105C393C = -1;
    dword_105C3940 = 0;
    dword_105C3944 = 0;
    dword_105C3948 = 0;
    dword_105C394C = 0;
    dword_105C3950 = 0;
    dword_105C3954 = (int)"maintain count scale control point field";
    dword_105C3958 = (int)"0";
    dword_105C395C = 2;
    dword_105C3960 = 100;
    dword_105C3964 = 4;
    dword_105C3968 = -1;
    dword_105C396C = 0;
    dword_105C3970 = 0;
    dword_105C3974 = 0;
    dword_105C3978 = 0;
    dword_105C397C = 0;
    dword_105C3980 = (int)"control point with snapshot data";
    dword_105C3984 = (int)"-1";
    dword_105C3988 = 2;
    dword_105C398C = 104;
    dword_105C3990 = 4;
    dword_105C3994 = -1;
    dword_105C3998 = 0;
    dword_105C399C = 0;
    dword_105C39A0 = 0;
    dword_105C39A4 = 0;
    dword_105C39A8 = 0;
    dword_105C39AC = 0;
    dword_105C39B0 = 0;
    dword_105C39B4 = 0;
    dword_105C39B8 = 0;
    dword_105C39BC = 0;
    dword_105C39C0 = -1;
    dword_105C39C4 = 0;
    dword_105C39C8 = 0;
    dword_105C39CC = 0;
    dword_105C39D0 = 0;
    dword_105C39D4 = 0;
  }
  return unpack_18;
}

} // namespace client
