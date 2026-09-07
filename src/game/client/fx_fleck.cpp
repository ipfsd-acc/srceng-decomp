// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_fleck.cpp
// Functions: 5
// ============================================================

#include "game\client\fx_fleck.h"

//------------------------------------------------------------------------------
// Address: 0x100DC5B0
// Name: public: virtual void CFleckParticles::Setup(class Vector const __near &,class Vector const __near *,float,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFleckParticles::Setup(
        CFleckParticles *this,
        const Vector *origin,
        const Vector *direction,
        float angularSpread,
        float minSpeed,
        float maxSpeed,
        float gravity,
        float dampen,
        int flags)
{
  ((void (__thiscall *)(CParticleCollision *, const Vector *, const Vector *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_ParticleCollision.Setup_2)(
    a1: &this->m_ParticleCollision,
    a2: origin,
    a3: direction,
    a4: LODWORD(angularSpread),
    a5: LODWORD(minSpeed),
    a6: LODWORD(maxSpeed),
    a7: LODWORD(gravity),
    a8: LODWORD(dampen));
}

//------------------------------------------------------------------------------
// Address: 0x100DC670
// Name: public: virtual void CFleckParticles::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFleckParticles::RenderParticles(CFleckParticles *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  CParticleMgr *v5; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  int v9; // ecx
  int v10; // edx
  float v11; // xmm4_4
  float v12; // xmm0_4
  float m_pNext_low; // xmm1_4
  int m_pNext_high; // eax
  float v15; // xmm0_4
  ParticleDraw *m_pParticleDraw; // eax
  float v17; // xmm0_4
  float size; // [esp+4h] [ebp-28h]
  float angle; // [esp+8h] [ebp-24h]
  Vector color; // [esp+14h] [ebp-18h] BYREF
  Vector tPos; // [esp+20h] [ebp-Ch] BYREF

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
      v5 = ParticleMgr();
      y = i->m_Pos.y;
      x = i->m_Pos.x;
      z = i->m_Pos.z;
      v9 = BYTE1(i[2].m_pNext);
      v10 = BYTE2(i[2].m_pNext);
      v11 = v5->m_mModelView.m[1][1];
      tPos.x = (float)((float)((float)(v5->m_mModelView.m[0][1] * y) + (float)(v5->m_mModelView.m[0][0] * x))
                     + (float)(v5->m_mModelView.m[0][2] * z))
             + v5->m_mModelView.m[0][3];
      tPos.y = (float)((float)((float)(v5->m_mModelView.m[1][0] * x) + (float)(v11 * y))
                     + (float)(v5->m_mModelView.m[1][2] * z))
             + v5->m_mModelView.m[1][3];
      v12 = (float)((float)((float)(v5->m_mModelView.m[2][0] * x) + (float)(v5->m_mModelView.m[2][1] * y))
                  + (float)(v5->m_mModelView.m[2][2] * z))
          + v5->m_mModelView.m[2][3];
      m_pNext_low = (float)LOBYTE(i[2].m_pNext);
      m_pNext_high = HIBYTE(i[2].m_pNext);
      tPos.z = v12;
      color.x = m_pNext_low * 0.0039215689;
      color.y = (float)v9 * 0.0039215689;
      angle = i[1].m_Pos.x;
      v15 = (float)m_pNext_high;
      m_pParticleDraw = pIterator->m_pParticleDraw;
      size = v15;
      v17 = *(float *)&i[2].m_pPrev / i[1].m_Pos.z;
      color.z = (float)v10 * 0.0039215689;
      RenderParticle_ColorSizeAngle(pDraw: m_pParticleDraw, pos: &tPos, &color, alpha: 1.0 - v17, size, angle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC820
// Name: public: virtual void CFleckParticles::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFleckParticles::SimulateParticles(CFleckParticles *this, CParticleSimulateIterator *pIterator)
{
  CParticleSimulateIterator *v2; // esi
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  float m_flTimeDelta; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cf
  CParticleCollision_vtbl *v8; // edx
  Particle *v9; // esi
  Vector *v10; // edi
  CGameTrace trace; // [esp+14h] [ebp-58h] BYREF
  CFleckParticles *v12; // [esp+68h] [ebp-4h]

  v2 = pIterator;
  v12 = this;
  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    while ( 1 )
    {
      m_flTimeDelta = v2->m_flTimeDelta;
      v6 = *(float *)&m_pNext[2].m_pPrev + m_flTimeDelta;
      v7 = v6 < m_pNext[1].m_Pos.z;
      *(float *)&m_pNext[2].m_pPrev = v6;
      if ( v7 )
      {
        v8 = v12->m_ParticleCollision.__vftable;
        v9 = (Particle *)((char *)m_pNext + 40);
        v10 = (Vector *)&m_pNext[1];
        m_pNext[1].m_Pos.x = (float)(m_pNext[1].m_Pos.y * m_flTimeDelta) + m_pNext[1].m_Pos.x;
        ((void (__stdcall *)(Vector *, Particle *, float *, float, CGameTrace *))v8->MoveParticle)(
          a1: &m_pNext->m_Pos,
          a2: &m_pNext[1],
          a3: &m_pNext[1].m_Pos.y,
          a4: COERCE_FLOAT(LODWORD(m_flTimeDelta)),
          a5: &trace);
        if ( trace.allsolid )
        {
          *v10 = vec3_origin;
          v9->m_pPrev = nullptr;
        }
        v2 = pIterator;
      }
      else
      {
        CParticleEffectBinding::RemoveParticle(this: v2->m_pEffectBinding, pParticle: m_pNext);
      }
      m_pNext = v2->m_pNextParticle;
      if ( m_pNext == &v2->m_pMaterial->m_Particles )
        break;
      v2->m_pNextParticle = m_pNext->m_pNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC910
// Name: public: class CFleckParticles __near * CParticleMergeList<class CFleckParticles,class CMergeSameNameBbox<class CFleckParticles>>::FindAndMergeParticleSystem(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CFleckParticles *__userpurge CParticleMergeList<CFleckParticles,CMergeSameNameBbox<CFleckParticles>>::FindAndMergeParticleSystem@<eax>(
        CParticleMergeList<CFleckParticles,CMergeSameNameBbox<CFleckParticles> > *this@<ecx>,
        int a2@<ebp>,
        const char *pEffectName,
        const Vector *center,
        const Vector *extents)
{
  CFleckParticles *m_pHead; // esi
  const char *v6; // eax
  __int128 v7; // xmm0
  __int128 v9; // [esp-40h] [ebp-4Ch] BYREF
  Vector v10; // [esp-30h] [ebp-3Ch] BYREF
  Vector v11; // [esp-24h] [ebp-30h] BYREF
  Vector v12; // [esp-18h] [ebp-24h] BYREF
  Vector v13; // [esp-Ch] [ebp-18h] BYREF
  int v14; // [esp+0h] [ebp-Ch]
  void *v15; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v14 = a2;
  v15 = retaddr;
  m_pHead = this->m_pHead;
  if ( this->m_pHead == nullptr )
    return nullptr;
  while ( 1 )
  {
    v6 = m_pHead->GetEffectName(this: m_pHead);
    if ( _V_stricmp(s1: v6, s2: pEffectName) == 0 )
    {
      CParticleEffectBinding::GetWorldspaceBounds(this: &m_pHead->m_ParticleEffect, pMins: &v13, pMaxs: &v12);
      v11.x = center->x - extents->x;
      v11.y = center->y - extents->y;
      v11.z = center->z - extents->z;
      AddPointToBounds(v: &v11, mins: &v13, maxs: &v12);
      v10.x = center->x + extents->x;
      v10.y = center->y + extents->y;
      v10.z = extents->z + center->z;
      AddPointToBounds(v: &v10, mins: &v13, maxs: &v12);
      v7 = 0;
      *(float *)&v7 = fsqrt(
                        (float)((float)((float)(v12.y - v13.y) * (float)(v12.y - v13.y))
                              + (float)((float)(v12.z - v13.z) * (float)(v12.z - v13.z)))
                      + (float)((float)(v12.x - v13.x) * (float)(v12.x - v13.x)));
      v9 = v7;
      if ( *(float *)&v7 < 120.0 )
        break;
    }
    m_pHead = m_pHead->m_pNextParticleSystem;
    if ( m_pHead == nullptr )
      return nullptr;
  }
  CParticleEffectBinding::SetBBox(this: &m_pHead->m_ParticleEffect, bbMin: &v13, bbMax: &v12, bDisableAutoUpdate: true);
  *((float *)&v9 + 1) = (float)(v13.x + v12.x) * 0.5;
  *((float *)&v9 + 2) = (float)(v13.y + v12.y) * 0.5;
  *((float *)&v9 + 3) = (float)(v13.z + v12.z) * 0.5;
  CParticleEffect::SetSortOrigin(this: m_pHead, vSortOrigin: (const Vector *)((char *)&v9 + 4));
  return m_pHead;
}

//------------------------------------------------------------------------------
// Address: 0x100DCAC0
// Name: public: static class CSmartPtr<class CFleckParticles,class CRefCountAccessor> CFleckParticles::Create(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CFleckParticles,CRefCountAccessor> *__cdecl CFleckParticles::Create(
        CSmartPtr<CFleckParticles,CRefCountAccessor> *result,
        const char *pDebugName,
        const Vector *vCenter,
        const Vector *extents)
{
  CFleckParticles *v4; // esi
  CSmartPtr<CFleckParticles,CRefCountAccessor> *v5; // edi
  CSimpleEmitter *v6; // eax
  float y; // xmm2_4
  float z; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  Vector bbMin; // [esp+Ch] [ebp-18h] BYREF
  Vector bbMax; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v4 = CParticleMergeList<CFleckParticles,CMergeSameNameBbox<CFleckParticles>>::FindAndMergeParticleSystem(
         this: &g_FleckMergeList,
         a2: (int)&savedregs,
         pEffectName: pDebugName,
         center: vCenter,
         extents);
  if ( v4 != nullptr )
  {
    v5 = result;
    result->m_pObj = nullptr;
  }
  else
  {
    v6 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x180u);
    v4 = (CFleckParticles *)v6;
    if ( v6 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v6, pDebugName);
      v4->__vftable = (CFleckParticles_vtbl *)&CFleckParticles::`vftable';
      CParticleCollision::CParticleCollision(this: &v4->m_ParticleCollision);
      v4->m_pNextParticleSystem = nullptr;
      v4->m_pNextParticleSystem = g_FleckMergeList.m_pHead;
      g_FleckMergeList.m_pHead = v4;
      y = extents->y;
      z = extents->z;
      v9 = vCenter->x - extents->x;
      bbMax.x = extents->x + vCenter->x;
      v10 = vCenter->y;
      v11 = y + v10;
      v12 = v10 - extents->y;
      bbMax.y = v11;
      v13 = vCenter->z;
      v14 = z + v13;
      v15 = v13 - extents->z;
      bbMax.z = v14;
      bbMin.x = v9;
      bbMin.y = v12;
      bbMin.z = v15;
      CParticleEffectBinding::SetBBox(this: &v4->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
      CParticleEffect::SetSortOrigin(this: v4, vSortOrigin: vCenter);
    }
    else
    {
      v4 = nullptr;
    }
    v5 = result;
    result->m_pObj = nullptr;
    if ( v4 == nullptr )
      return v5;
  }
  CParticleEffect::AddRef(this: v4);
  if ( v5->m_pObj != nullptr )
    CParticleEffect::Release(this: v5->m_pObj);
  v5->m_pObj = v4;
  return v5;
}
