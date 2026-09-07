// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particle_simple3d.cpp
// Functions: 4
// ============================================================

#include "game\client\particle_simple3d.h"

//------------------------------------------------------------------------------
// Address: 0x1012F830
// Name: void RenderParticle_ColorSizeAngles(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_ColorSizeAngles(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size,
        const QAngle *angles)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  float z; // ecx
  float *m_pCurrPosition; // eax
  int v9; // edx
  float v10; // xmm0_4
  int v11; // ecx
  int v12; // edi
  float *v13; // ecx
  float v14; // xmm0_4
  CVertexBuilder *p_m_VertexBuilder; // ebx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float *v18; // eax
  float *v19; // ecx
  float v20; // xmm0_4
  float y; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  _DWORD *m_pCurrColor; // edx
  unsigned int v25; // xmm0_4
  unsigned int v26; // xmm1_4
  float v27; // xmm2_4
  float *v28; // ecx
  float v29; // xmm0_4
  float *v30; // eax
  _DWORD *v31; // ecx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *m_pCurrNormal; // eax
  float v35; // xmm0_4
  float v36; // xmm1_4
  float *v37; // esi
  float v38; // xmm0_4
  float v39; // [esp+0h] [ebp-4Ch]
  float v40; // [esp+4h] [ebp-48h]
  float v41; // [esp+8h] [ebp-44h]
  __int64 vVertex; // [esp+Ch] [ebp-40h]
  unsigned __int64 vVertexa; // [esp+Ch] [ebp-40h]
  float vVertex_8; // [esp+14h] [ebp-38h]
  float vVertex_8a; // [esp+14h] [ebp-38h]
  Vector vHeight; // [esp+18h] [ebp-34h] BYREF
  Vector vWidth; // [esp+24h] [ebp-28h] BYREF
  Vector vNorm; // [esp+30h] [ebp-1Ch] BYREF
  float v49; // [esp+3Ch] [ebp-10h]
  int v50; // [esp+40h] [ebp-Ch]
  int v51; // [esp+44h] [ebp-8h]
  int v52; // [esp+48h] [ebp-4h]

  if ( alpha >= 0.001 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      v52 = (int)(float)(color->x * 254.89999);
      v51 = (int)(float)(color->y * 254.89999);
      v50 = (int)(float)(color->z * 254.89999);
      v49 = alpha * 254.89999;
      AngleVectors(angles, forward: &vNorm, right: &vWidth, up: &vHeight);
      z = pos->z;
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v9 = (unsigned __int8)v52;
      vVertex = *(_QWORD *)&pos->x;
      *(_QWORD *)m_pCurrPosition = *(_QWORD *)&pos->x;
      vVertex_8 = z;
      v10 = z;
      v11 = (unsigned __int8)v50;
      m_pCurrPosition[2] = v10;
      v12 = v11 | (((unsigned __int8)v51 | ((v9 | ((unsigned __int8)(int)(float)(alpha * 254.89999) << 8)) << 8)) << 8);
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v12;
      v13 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *(Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal = vNorm;
      v14 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v13 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v13[1] = v14;
      p_m_VertexBuilder = &m_pMeshBuilder->m_VertexBuilder;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v16 = (float)(vWidth.y * size) + *((float *)&vVertex + 1);
      v17 = (float)(vWidth.z * size) + vVertex_8;
      v39 = (float)(vWidth.x * size) + *(float *)&vVertex;
      v40 = v16;
      v41 = v17;
      v18 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      *v18 = v39;
      v18[1] = v16;
      v18[2] = v17;
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v12;
      *(Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal = vNorm;
      v19 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v20 = pDraw->m_pSubTexture->m_tCoordMins[1];
      *v19 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v19[1] = v20;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      y = vHeight.y;
      v22 = vHeight.z;
      v23 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      m_pCurrColor = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *(float *)&v25 = (float)(vHeight.x * size) + v39;
      *(_DWORD *)v23 = v25;
      *(float *)&v26 = (float)(y * size) + v40;
      *((_DWORD *)v23 + 1) = v26;
      v27 = (float)(v22 * size) + v41;
      v23[2] = v27;
      *m_pCurrColor = v12;
      v28 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      vVertexa = __PAIR64__(v26, v25);
      vVertex_8a = v27;
      *(Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal = vNorm;
      v29 = pDraw->m_pSubTexture->m_tCoordMins[1];
      *v28 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v28[1] = v29;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v30 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v31 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      v32 = vWidth.y * size;
      v33 = vWidth.z * size;
      *v30 = *(float *)&vVertexa - (float)(vWidth.x * size);
      v30[1] = *((float *)&vVertexa + 1) - v32;
      v30[2] = vVertex_8a - v33;
      *v31 = v12;
      m_pCurrNormal = m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      v35 = vNorm.y;
      v36 = vNorm.z;
      *m_pCurrNormal = vNorm.x;
      v37 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      m_pCurrNormal[1] = v35;
      m_pCurrNormal[2] = v36;
      v38 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v37 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v37[1] = v38;
      CVertexBuilder::AdvanceVertex(this: p_m_VertexBuilder);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FB50
// Name: public: virtual void CSimple3DEmitter::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimple3DEmitter::SimulateParticles(CSimple3DEmitter *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float m_flTimeDelta; // xmm1_4
  float v5; // xmm0_4
  bool (__thiscall *MoveParticle)(CParticleCollision *, Vector *, Vector *, float *, float, CGameTrace *); // edx
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  CGameTrace trace; // [esp+14h] [ebp-58h] BYREF
  CSimple3DEmitter *v14; // [esp+68h] [ebp-4h]

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  v14 = this;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    while ( 1 )
    {
      m_flTimeDelta = pIterator->m_flTimeDelta;
      pIterator->m_pNextParticle = m_pNext->m_pNext;
      v5 = *(float *)&m_pNext[2].m_pNext - m_flTimeDelta;
      *(float *)&m_pNext[2].m_pNext = v5;
      if ( v5 >= 0.0 )
        break;
      CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
LABEL_14:
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        return;
    }
    MoveParticle = v14->m_ParticleCollision.MoveParticle;
    v7 = *(float *)&m_pNext[2].m_pPrev * m_flTimeDelta;
    m_pNext[1].m_Pos.x = v7 + m_pNext[1].m_Pos.x;
    v8 = v7 + m_pNext[1].m_Pos.y;
    v9 = v7 + m_pNext[1].m_Pos.z;
    m_pNext[1].m_Pos.y = v8;
    m_pNext[1].m_Pos.z = v9;
    ((void (__stdcall *)(Vector *, Particle *, Particle *, _DWORD, CGameTrace *))MoveParticle)(
      a1: &m_pNext->m_Pos,
      a2: &m_pNext[1],
      a3: &m_pNext[2],
      a4: LODWORD(m_flTimeDelta),
      a5: &trace);
    if ( *(float *)&m_pNext[2].m_pPrev != 0.0 && trace.fraction == 1.0 )
      goto LABEL_14;
    v10 = (float)(unsigned __int16)(int)(float)(m_pNext[1].m_Pos.x * 182.04445) * 0.0054931641;
    m_pNext[1].m_Pos.x = v10;
    if ( v10 >= 180.0 )
    {
      if ( fabs(v10 - 270.0) <= 0.5 )
        goto LABEL_12;
      v11 = (float)(v10 * 0.5) + 135.0;
    }
    else
    {
      if ( fabs(v10 - 90.0) <= 0.5 )
        goto LABEL_12;
      v11 = (float)(v10 * 0.5) + 46.0;
    }
    m_pNext[1].m_Pos.x = v11;
LABEL_12:
    v12 = (float)(unsigned __int16)(int)(float)(m_pNext[1].m_Pos.y * 182.04445) * 0.0054931641;
    m_pNext[1].m_Pos.y = v12;
    if ( fabs(v12) > 0.5 )
      m_pNext[1].m_Pos.y = m_pNext[1].m_Pos.z * 0.5;
    goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FD10
// Name: public: virtual void CSimple3DEmitter::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimple3DEmitter::RenderParticles(CSimple3DEmitter *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // edx
  Particle *m_pNext; // ecx
  Particle *i; // edi
  const Vector *v5; // eax
  const Vector *v6; // eax
  const Vector *v7; // eax
  int x_low; // eax
  int v9; // ecx
  int v10; // edx
  float v11; // xmm0_4
  float alpha; // xmm0_4
  Vector vFaceNorm; // [esp+18h] [ebp-34h] BYREF
  Vector vCameraToFace; // [esp+24h] [ebp-28h]
  float v15; // [esp+30h] [ebp-1Ch]
  float v16; // [esp+34h] [ebp-18h]
  float v17; // [esp+38h] [ebp-14h]
  Vector color; // [esp+3Ch] [ebp-10h] BYREF
  float sortKey; // [esp+48h] [ebp-4h]

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
      v5 = CurrentViewOrigin();
      v15 = v5->x - i->m_Pos.x;
      v16 = v5->y - i->m_Pos.y;
      v17 = v5->z - i->m_Pos.z;
      v6 = CurrentViewForward();
      sortKey = (float)((float)(v6->y * v16) + (float)(v6->x * v15)) + (float)(v6->z * v17);
      v7 = CurrentViewOrigin();
      vCameraToFace.x = i->m_Pos.x - v7->x;
      vCameraToFace.y = i->m_Pos.y - v7->y;
      vCameraToFace.z = i->m_Pos.z - v7->z;
      AngleVectors(angles: (const QAngle *)&i[1].m_Pos, forward: &vFaceNorm);
      if ( (float)((float)((float)(vFaceNorm.y * vCameraToFace.y) + (float)(vCameraToFace.x * vFaceNorm.x))
                 + (float)(vFaceNorm.z * vCameraToFace.z)) > 0.0 )
      {
        x_low = LOBYTE(i[2].m_Pos.x);
        v9 = BYTE1(i[2].m_Pos.x);
        v10 = BYTE2(i[2].m_Pos.x);
      }
      else
      {
        x_low = LOBYTE(i[2].m_pSubTexture);
        v9 = BYTE1(i[2].m_pSubTexture);
        v10 = BYTE2(i[2].m_pSubTexture);
      }
      color.x = (float)x_low * 0.0039215689;
      color.y = (float)v9 * 0.0039215689;
      v11 = *(float *)&i[2].m_pNext;
      color.z = (float)v10 * 0.0039215689;
      if ( v11 < 2.0 )
        alpha = v11 * 0.5;
      else
        alpha = 1.0;
      RenderParticle_ColorSizeAngles(
        pDraw: pIterator->m_pParticleDraw,
        pos: &i->m_Pos,
        &color,
        alpha,
        size: (float)HIBYTE(i[2].m_pSubTexture),
        angles: (const QAngle *)&i[1].m_Pos);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FEF0
// Name: public: static class CSmartPtr<class CSimple3DEmitter,class CRefCountAccessor> CSimple3DEmitter::Create(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CSimple3DEmitter,CRefCountAccessor> *__cdecl CSimple3DEmitter::Create(
        CSmartPtr<CSimple3DEmitter,CRefCountAccessor> *result,
        const char *pDebugName)
{
  CSimple3DEmitter *v2; // esi

  v2 = (CSimple3DEmitter *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v2 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v2, pDebugName);
    v2->__vftable = (CSimple3DEmitter_vtbl *)&CSimple3DEmitter::`vftable';
    CParticleCollision::CParticleCollision(this: &v2->m_ParticleCollision);
  }
  else
  {
    v2 = nullptr;
  }
  v2->m_ParticleEffect.m_Flags &= ~0x80u;
  result->m_pObj = nullptr;
  if ( v2 != nullptr )
  {
    CParticleEffect::AddRef(this: v2);
    if ( result->m_pObj != nullptr )
      CParticleEffect::Release(this: result->m_pObj);
    result->m_pObj = v2;
  }
  return result;
}
