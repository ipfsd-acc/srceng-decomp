// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particles_localspace.cpp
// Functions: 4
// ============================================================

#include "game\client\particles_localspace.h"

//------------------------------------------------------------------------------
// Address: 0x10136E20
// Name: public: virtual void CLocalSpaceEmitter::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalSpaceEmitter::Update(CLocalSpaceEmitter *this, float flTimeDelta)
{
  this->SetupTransformMatrix(this);
}

//------------------------------------------------------------------------------
// Address: 0x10136F10
// Name: public: virtual void CLocalSpaceEmitter::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalSpaceEmitter::RenderParticles(CLocalSpaceEmitter *this, CParticleRenderIterator *pIterator)
{
  CParticleMgr *v3; // eax
  CEffectMaterial *m_pMaterial; // edx
  float *v5; // ebx
  Particle *m_pNext; // eax
  Particle *i; // edi
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float m_flNearClipMin; // xmm2_4
  float v15; // xmm0_4
  float m_flNearClipMax; // xmm1_4
  float v17; // xmm0_4
  ParticleDraw *m_pParticleDraw; // eax
  CLocalSpaceEmitter_vtbl *v19; // edx
  float x; // xmm0_4
  double v21; // st7
  const Vector *v22; // eax
  float angle; // [esp+10h] [ebp-40h]
  float anglea; // [esp+10h] [ebp-40h]
  float alpha[3]; // [esp+20h] [ebp-30h] BYREF
  Vector screenPos; // [esp+2Ch] [ebp-24h] BYREF
  Vector worldPos; // [esp+38h] [ebp-18h] BYREF
  float sortKey; // [esp+44h] [ebp-Ch]
  ParticleDraw *pDraw; // [esp+48h] [ebp-8h]
  float v30; // [esp+4Ch] [ebp-4h]

  v3 = ParticleMgr();
  m_pMaterial = pIterator->m_pMaterial;
  v5 = (float *)v3;
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
      VectorTransform(
        in1: &i->m_Pos.x,
        in2: (const matrix3x4_t *)&this->m_ParticleEffect.m_LocalSpaceTransform,
        out: &worldPos.x);
      if ( (this->m_fFlags & 1) != 0 )
        FormatViewModelAttachment(pPlayer: nullptr, vOrigin: &worldPos, bInverse: false);
      v8 = v5[29] * worldPos.x;
      v9 = worldPos.x * v5[33];
      screenPos.x = (float)((float)((float)(v5[25] * worldPos.x) + (float)(v5[26] * worldPos.y))
                          + (float)(v5[27] * worldPos.z))
                  + v5[28];
      v10 = (float)((float)((float)(worldPos.y * v5[34]) + v9) + (float)(v5[35] * worldPos.z)) + v5[36];
      v11 = (float)(v5[30] * worldPos.y) + v8;
      v12 = (float)(int)v10;
      v13 = v5[31] * worldPos.z;
      m_flNearClipMin = this->m_flNearClipMin;
      screenPos.z = v10;
      LODWORD(v15) = LODWORD(v10) ^ _mask__NegFloat_;
      sortKey = v12;
      m_flNearClipMax = this->m_flNearClipMax;
      screenPos.y = (float)(v11 + v13) + v5[32];
      if ( v15 <= m_flNearClipMax )
      {
        if ( v15 <= m_flNearClipMin )
          v17 = 0.0;
        else
          v17 = (float)(v15 - m_flNearClipMin) / (float)(m_flNearClipMax - m_flNearClipMin);
      }
      else
      {
        v17 = 1.0;
      }
      m_pParticleDraw = pIterator->m_pParticleDraw;
      v19 = this->__vftable;
      v30 = v17;
      x = i[1].m_Pos.x;
      pDraw = m_pParticleDraw;
      angle = ((double (__thiscall *)(CLocalSpaceEmitter *, Particle *, _DWORD))v19->UpdateScale)(
                a1: this,
                a2: i,
                a3: LODWORD(x));
      v21 = ((double (__thiscall *)(CLocalSpaceEmitter *, Particle *, _DWORD))this->UpdateAlpha)(
              a1: this,
              a2: i,
              a3: LODWORD(angle));
      anglea = v21 * v30;
      v22 = (const Vector *)((int (__thiscall *)(CLocalSpaceEmitter *))this->UpdateColor)(a1: this);
      RenderParticle_ColorSizeAngle(
        pDraw,
        pos: &screenPos,
        color: v22,
        alpha: COERCE_FLOAT(alpha),
        size: *(float *)&i,
        angle: anglea);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137100
// Name: public: virtual void CLocalSpaceEmitter::SetupTransformMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocalSpaceEmitter::SetupTransformMatrix(CLocalSpaceEmitter *this)
{
  IClientRenderable *ClientRenderableFromHandle; // eax
  IClientRenderable *v3; // esi
  int v4; // eax
  int v5; // eax
  float v6; // xmm0_4
  matrix3x4_t mat; // [esp+Ch] [ebp-54h] BYREF
  Vector vWorldMins; // [esp+3Ch] [ebp-24h] BYREF
  Vector vWorldMaxs; // [esp+48h] [ebp-18h] BYREF
  Vector origin; // [esp+54h] [ebp-Ch] BYREF

  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: this->m_hEntity);
  v3 = ClientRenderableFromHandle;
  if ( ClientRenderableFromHandle != nullptr )
  {
    ClientRenderableFromHandle->GetAttachment(this: ClientRenderableFromHandle, a2: this->m_nAttachment, a3: &mat);
    MatrixGetColumn(in: &mat, column: 3, out: &origin);
    CParticleEffectBinding::SetLocalSpaceTransform(this: &this->m_ParticleEffect, transform: &mat);
    CParticleEffect::SetSortOrigin(this, vSortOrigin: &origin);
    v4 = v3->GetIClientUnknown(this: v3);
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
    if ( v5 != 0 )
    {
      v6 = *(float *)(v5 + 816);
      vWorldMins.x = origin.x - v6;
      vWorldMins.y = origin.y - v6;
      vWorldMins.z = origin.z - v6;
      vWorldMaxs.x = origin.x + v6;
      vWorldMaxs.y = origin.y + v6;
      vWorldMaxs.z = origin.z + v6;
      CParticleEffectBinding::SetBBox(
        this: &this->m_ParticleEffect,
        bbMin: &vWorldMins,
        bbMax: &vWorldMaxs,
        bDisableAutoUpdate: true);
    }
  }
  this->m_ParticleEffect.m_Flags &= ~0x400u;
}

//------------------------------------------------------------------------------
// Address: 0x10137200
// Name: public: static class CSmartPtr<class CLocalSpaceEmitter,class CRefCountAccessor> CLocalSpaceEmitter::Create(char const __near *,class CBaseHandle,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> *__cdecl CLocalSpaceEmitter::Create(
        CSmartPtr<CLocalSpaceEmitter,CRefCountAccessor> *result,
        const char *pDebugName,
        CBaseHandle hEntity,
        int nAttachment,
        int fFlags)
{
  CLocalSpaceEmitter *v5; // esi
  CLocalSpaceEmitter_vtbl *v6; // edx

  v5 = (CLocalSpaceEmitter *)MemAlloc_Alloc(nSize: 0x114u);
  if ( v5 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName);
    v5->__vftable = (CLocalSpaceEmitter_vtbl *)&CLocalSpaceEmitter::`vftable';
    v5->m_hEntity.m_Index = -1;
  }
  else
  {
    v5 = nullptr;
  }
  CParticleEffect::SetDynamicallyAllocated(this: v5, bDynamic: true);
  v5->m_nAttachment = nAttachment;
  v6 = v5->__vftable;
  v5->m_hEntity = hEntity;
  v5->m_fFlags = fFlags;
  v6->SetupTransformMatrix(this: v5);
  result->m_pObj = nullptr;
  CParticleEffect::AddRef(this: v5);
  if ( result->m_pObj != nullptr )
    CParticleEffect::Release(this: result->m_pObj);
  result->m_pObj = v5;
  return result;
}
