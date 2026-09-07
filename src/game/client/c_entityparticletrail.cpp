// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_entityparticletrail.cpp
// Functions: 20
// ============================================================

#include "game\client\c_entityparticletrail.h"

//------------------------------------------------------------------------------
// Address: 0x10065FB0
// Name: public: virtual class ClientClass __near * C_EntityParticleTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EntityParticleTrail::GetClientClass(C_EntityParticleTrail *this)
{
  return &__g_C_EntityParticleTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10066090
// Name: public: class VMatrix __near & CParticleMgr::GetModelView(void)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall CParticleMgr::GetModelView(CParticleMgr *this)
{
  return &this->m_mModelView;
}

//------------------------------------------------------------------------------
// Address: 0x100660A0
// Name: public: C_EntityParticleTrail::C_EntityParticleTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_EntityParticleTrail *__thiscall C_EntityParticleTrail::C_EntityParticleTrail(C_EntityParticleTrail *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EntityParticleTrail_vtbl *)&C_EntityParticleTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EntityParticleTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EntityParticleTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EntityParticleTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EntityParticleTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_EntityParticleTrail::`vftable'{for `IParticleEffect'};
  EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(this: &this->m_Info);
  this->m_hConstraintEntity.m_Index = -1;
  this->m_teParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_teParticleSpawn.m_fNextEvent = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066180
// Name: private: void C_EntityParticleTrail::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityParticleTrail::Start(C_EntityParticleTrail *this)
{
  IParticleEffect *v2; // eax
  CParticleMgr *v3; // eax
  const char *MaterialNameFromIndex; // eax
  CParticleMgr *v5; // eax
  CParticleEffectBinding *p_m_ParticleEffect; // [esp-8h] [ebp-Ch]
  IParticleEffect *v7; // [esp-4h] [ebp-8h]
  const char *v8; // [esp-4h] [ebp-8h]

  if ( this != nullptr )
    v2 = &this->IParticleEffect;
  else
    v2 = nullptr;
  v7 = v2;
  p_m_ParticleEffect = &this->m_ParticleEffect;
  v3 = ParticleMgr();
  if ( CParticleMgr::AddEffect(this: v3, pEffect: p_m_ParticleEffect, pSim: v7) )
  {
    MaterialNameFromIndex = GetMaterialNameFromIndex(nIndex: this->m_iMaterialName);
    if ( MaterialNameFromIndex != nullptr )
    {
      v8 = MaterialNameFromIndex;
      v5 = ParticleMgr();
      this->m_hMaterial = CParticleMgr::GetPMaterial(this: v5, pMaterialName: v8);
      this->m_teParticleSpawn.m_TimeBetweenEvents = 0.0066666668;
      this->m_teParticleSpawn.m_fNextEvent = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100661F0
// Name: public: virtual void C_EntityParticleTrail::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityParticleTrail::SimulateParticles(
        C_EntityParticleTrail *this,
        CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  bool i; // zf
  float m_flTimeDelta; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  bool v9; // cf

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  for ( i = m_pNext == &m_pMaterial->m_Particles; !i; i = m_pNext == &pIterator->m_pMaterial->m_Particles )
  {
    m_flTimeDelta = pIterator->m_flTimeDelta;
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    v6 = *(float *)&m_pNext[1].m_pNext;
    v7 = *(float *)&m_pNext[1].m_pSubTexture;
    m_pNext->m_Pos.x = (float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta) + m_pNext->m_Pos.x;
    m_pNext->m_Pos.y = m_pNext->m_Pos.y + (float)(v6 * m_flTimeDelta);
    m_pNext->m_Pos.z = m_pNext->m_Pos.z + (float)(v7 * m_flTimeDelta);
    v8 = m_pNext[1].m_Pos.z + m_flTimeDelta;
    v9 = v8 < m_pNext[1].m_Pos.y;
    m_pNext[1].m_Pos.z = v8;
    if ( !v9 )
      CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
    m_pNext = pIterator->m_pNextParticle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066280
// Name: private: void CParticleRenderIterator::TestFlushBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleRenderIterator::TestFlushBatch(CParticleRenderIterator *this)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  int v3; // eax
  IMesh *m_pMesh; // edi
  CMeshBuilder *v5; // esi

  if ( ++this->m_nParticlesInCurrentBatch >= 200 )
  {
    m_pMeshBuilder = this->m_pMeshBuilder;
    if ( m_pMeshBuilder->m_bGenerateIndices )
    {
      v3 = CMeshBuilder::IndicesFromVertices(
             this: m_pMeshBuilder,
             type: m_pMeshBuilder->m_Type,
             nVertexCount: m_pMeshBuilder->m_VertexBuilder.m_nVertexCount);
      CIndexBuilder::GenerateIndices(
        this: &m_pMeshBuilder->m_IndexBuilder,
        primitiveType: m_pMeshBuilder->m_Type,
        nIndexCount: v3);
    }
    m_pMeshBuilder->m_pMesh->UnlockMesh(
      this: m_pMeshBuilder->m_pMesh,
      a2: m_pMeshBuilder->m_VertexBuilder.m_nVertexCount,
      a3: m_pMeshBuilder->m_IndexBuilder.m_nIndexCount,
      a4: m_pMeshBuilder);
    m_pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
    m_pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
    m_pMeshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
    m_pMeshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
    m_pMeshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    m_pMeshBuilder->m_pMesh->Draw_2(this: m_pMeshBuilder->m_pMesh, a2: -1, a3: 0);
    m_pMeshBuilder->m_pMesh = nullptr;
    m_pMesh = this->m_pMesh;
    v5 = this->m_pMeshBuilder;
    v5->m_pMesh = m_pMesh;
    v5->m_bGenerateIndices = true;
    v5->m_Type = MATERIAL_QUADS;
    m_pMesh->SetPrimitiveType(this: m_pMesh, a2: MATERIAL_TRIANGLES);
    v5->m_pMesh->LockMesh(this: v5->m_pMesh, a2: 3200, a3: 4800, a4: v5, a5: nullptr);
    v5->m_IndexBuilder.m_pIndexBuffer = &m_pMesh->IIndexBuffer;
    v5->m_IndexBuilder.m_nIndexCount = 0;
    v5->m_IndexBuilder.m_nMaxIndexCount = 4800;
    v5->m_IndexBuilder.m_bModify = false;
    v5->m_IndexBuilder.m_nIndexOffset = v5->m_nFirstVertex;
    v5->m_IndexBuilder.m_pIndices = v5->m_pIndices;
    v5->m_IndexBuilder.m_nIndexSize = v5->m_nIndexSize;
    v5->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &v5->m_VertexBuilder, pMesh: m_pMesh, nMaxVertexCount: 3200, desc: v5);
    v5->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &v5->m_VertexBuilder);
    this->m_nParticlesInCurrentBatch = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100663F0
// Name: public: struct Particle const __near * CParticleRenderIterator::GetNext(float)
// Source: json
//------------------------------------------------------------------------------
const Particle *__thiscall CParticleRenderIterator::GetNext(CParticleRenderIterator *this, float sortKey)
{
  Particle *m_pCur; // eax
  Particle *m_pNext; // edx
  float m_MinZ; // xmm1_4
  float m_MaxZ; // xmm1_4
  int m_nZCoords; // ecx
  Particle *m_pPrev; // ecx
  Particle *v9; // ecx
  Particle *p_m_Particles; // eax

  CParticleRenderIterator::TestFlushBatch(this);
  m_pCur = this->m_pCur;
  m_pNext = m_pCur->m_pNext;
  if ( this->m_bBucketSort )
  {
    m_MinZ = this->m_MinZ;
    if ( m_MinZ > sortKey )
      m_MinZ = sortKey;
    this->m_MinZ = m_MinZ;
    m_MaxZ = this->m_MaxZ;
    if ( sortKey > m_MaxZ )
      m_MaxZ = sortKey;
    m_nZCoords = this->m_nZCoords;
    this->m_MaxZ = m_MaxZ;
    this->m_zCoords[m_nZCoords] = sortKey;
    ++this->m_nZCoords;
  }
  else if ( m_pCur == this->m_pMaterial->m_Particles.m_pNext || this->m_flPrevZ <= sortKey )
  {
    this->m_flPrevZ = sortKey;
  }
  else
  {
    m_pPrev = m_pCur->m_pPrev;
    m_pPrev->m_pNext = m_pCur->m_pNext;
    m_pCur->m_pNext->m_pPrev = m_pCur->m_pPrev;
    m_pCur->m_pNext = m_pPrev;
    v9 = m_pPrev->m_pPrev;
    m_pCur->m_pPrev = v9;
    v9->m_pNext = m_pCur;
    m_pCur->m_pNext->m_pPrev = m_pCur;
  }
  p_m_Particles = &this->m_pMaterial->m_Particles;
  this->m_pCur = m_pNext;
  if ( m_pNext == p_m_Particles )
    return nullptr;
  this->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
  return this->m_pCur;
}

//------------------------------------------------------------------------------
// Address: 0x100664C0
// Name: void RenderParticle_ColorSize(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_ColorSize(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  float *m_pCurrPosition; // eax
  float z; // xmm2_4
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
  int v29; // [esp+4h] [ebp-Ch]
  int v30; // [esp+8h] [ebp-8h]
  int v31; // [esp+Ch] [ebp-4h]
  CVertexBuilder *alphaa; // [esp+24h] [ebp+14h]

  if ( alpha >= 0.001 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      v31 = (int)(float)(color->x * 254.89999);
      v30 = (int)(float)(color->y * 254.89999);
      v29 = (int)(float)(color->z * 254.89999);
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      z = pos->z;
      v8 = pos->y - size;
      *m_pCurrPosition = pos->x - size;
      m_pCurrPosition[1] = v8;
      m_pCurrPosition[2] = z;
      v9 = (unsigned __int8)v29
         | (((unsigned __int8)v30
           | (((unsigned __int8)v31 | ((unsigned __int8)(int)(float)(alpha * 254.89999) << 8)) << 8)) << 8);
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
// Address: 0x10066720
// Name: public: virtual void C_EntityParticleTrail::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityParticleTrail::OnDataChanged(C_EntityParticleTrail *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    C_EntityParticleTrail::Start(this: (C_EntityParticleTrail *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10066750
// Name: private: void C_EntityParticleTrail::AddParticle(float,class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_EntityParticleTrail::AddParticle(
        C_EntityParticleTrail *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        float flInitialDeltaTime,
        const Vector *vecMins,
        const Vector *vecMaxs,
        const matrix3x4_t *boxToWorld)
{
  float x; // edi
  unsigned int v10; // ecx
  int v11; // eax
  CEntInfo *v12; // esi
  unsigned int v13; // ecx
  CEntInfo *v14; // eax
  IHandleEntity *v15; // eax
  Particle *v16; // eax
  Particle *v17; // esi
  int v18; // xmm0_4
  double v19; // st7
  _DWORD v20[3]; // [esp+38h] [ebp-D4h] BYREF
  CGameTrace tr; // [esp+44h] [ebp-C8h] BYREF
  int v22; // [esp+98h] [ebp-74h]
  Ray_t ray; // [esp+9Ch] [ebp-70h] BYREF
  Vector vecLocalPosition; // [esp+ECh] [ebp-20h] BYREF
  int maxVal; // [esp+F8h] [ebp-14h]
  Vector vecWorldPosition; // [esp+FCh] [ebp-10h]
  float retaddr; // [esp+10Ch] [ebp+0h]

  vecWorldPosition.y = a2;
  vecWorldPosition.z = retaddr;
  vecWorldPosition.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, C_EntityParticleTrail *, _DWORD, _DWORD, int))random->RandomFloat)(
                         a1: random,
                         a2: 0,
                         a3: 1065353216,
                         a4: a3,
                         a5: a4,
                         a6: v20[0],
                         a7: v20[1],
                         a8: v20[2],
                         a9: LODWORD(tr.startpos.x),
                         a10: LODWORD(tr.startpos.y),
                         a11: LODWORD(tr.startpos.z),
                         a12: LODWORD(tr.endpos.x),
                         a13: LODWORD(tr.endpos.y),
                         a14: LODWORD(tr.endpos.z),
                         a15: LODWORD(tr.plane.normal.x),
                         a16: LODWORD(tr.plane.normal.y),
                         a17: LODWORD(tr.plane.normal.z),
                         a18: LODWORD(tr.plane.dist),
                         a19: *(_DWORD *)&tr.plane.type,
                         a20: LODWORD(tr.fraction),
                         a21: tr.contents,
                         a22: *(_DWORD *)&tr.dispFlags,
                         a23: LODWORD(tr.fractionleftsolid),
                         a24: tr.surface.name,
                         a25: *(_DWORD *)&tr.surface.surfaceProps,
                         a26: tr.hitgroup,
                         a27: *(_DWORD *)&tr.physicsbone,
                         a28: tr.m_pEnt,
                         a29: tr.hitbox,
                         a30: v22,
                         a31: LODWORD(ray.m_Start.x),
                         a32: LODWORD(ray.m_Start.y),
                         a33: LODWORD(ray.m_Start.z),
                         a34: LODWORD(ray.m_Start.w),
                         a35: LODWORD(ray.m_Delta.x),
                         a36: LODWORD(ray.m_Delta.y),
                         a37: LODWORD(ray.m_Delta.z),
                         a38: LODWORD(ray.m_Delta.w),
                         a39: LODWORD(ray.m_StartOffset.x),
                         a40: LODWORD(ray.m_StartOffset.y),
                         a41: LODWORD(ray.m_StartOffset.z),
                         a42: LODWORD(ray.m_StartOffset.w),
                         a43: LODWORD(ray.m_Extents.x),
                         a44: LODWORD(ray.m_Extents.y),
                         a45: LODWORD(ray.m_Extents.z),
                         a46: LODWORD(ray.m_Extents.w),
                         a47: ray.m_pWorldAxisTransform,
                         a48: *(_DWORD *)&ray.m_IsRay,
                         a49: *(_DWORD *)(&ray.m_IsSwept + 3),
                         a50: *(_DWORD *)(&ray.m_IsSwept + 7),
                         a51: this,
                         a52: LODWORD(vecLocalPosition.y),
                         a53: LODWORD(vecLocalPosition.z),
                         a54: maxVal);
  *(float *)&ray.m_IsRay = (float)((float)(vecMaxs->x - vecMins->x) * vecWorldPosition.x) + vecMins->x;
  vecWorldPosition.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                         a1: random,
                         a2: 0,
                         a3: 1065353216);
  *(float *)(&ray.m_IsSwept + 3) = (float)((float)(vecMaxs->y - vecMins->y) * vecWorldPosition.x) + vecMins->y;
  vecWorldPosition.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                         a1: random,
                         a2: 0,
                         a3: 1065353216);
  *(float *)(&ray.m_IsSwept + 7) = (float)((float)(vecMaxs->z - vecMins->z) * vecWorldPosition.x) + vecMins->z;
  VectorTransform(in1: (float *)&ray.m_IsRay, in2: boxToWorld, out: &vecLocalPosition.y);
  x = vecLocalPosition.x;
  v10 = *(_DWORD *)(LODWORD(vecLocalPosition.x) + 2688);
  if ( v10 == -1 )
    goto LABEL_8;
  v11 = (unsigned __int16)v10;
  v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10];
  v13 = HIWORD(v10);
  if ( v12->m_SerialNumber != v13 || v12->m_pEntity == nullptr )
    goto LABEL_8;
  memset(&ray.m_Start.y, 0, 12);
  memset(&ray.m_StartOffset.y, 0, 12);
  memset(&ray.m_Delta.y, 0, 12);
  tr.m_pEnt = (struct CBaseEntity *)LODWORD(vecLocalPosition.y);
  tr.hitbox = LODWORD(vecLocalPosition.z);
  v14 = &g_pEntityList->m_EntPtrArray[v11];
  ray.m_Extents.y = 0.0;
  LOWORD(ray.m_Extents.z) = 1;
  v22 = maxVal;
  v15 = v14->m_SerialNumber == v13 ? v14->m_pEntity : nullptr;
  enginetrace->ClipRayToEntity(
    this: enginetrace,
    a2: (const Ray_t *)&tr.m_pEnt,
    a3: -1u,
    a4: v15,
    a5: (CGameTrace *)v20);
  if ( tr.plane.pad[1] != 0 )
  {
LABEL_8:
    v16 = CParticleEffectBinding::AddParticle(
            this: (CParticleEffectBinding *)(LODWORD(x) + 2436),
            sizeInBytes: 60,
            hMaterial: *(CParticleSubTexture **)(LODWORD(x) + 2692));
    v17 = v16;
    if ( v16 != nullptr )
    {
      v16->m_Pos.x = vecLocalPosition.y;
      v16->m_Pos.y = vecLocalPosition.z;
      v18 = maxVal;
      maxVal = 360;
      vecLocalPosition.z = 0.0;
      LODWORD(v16->m_Pos.z) = v18;
      v16[1].m_Pos.x = (float)Helper_RandomInt(minVal: SLODWORD(vecLocalPosition.z), maxVal);
      *(float *)&v17[2].m_pSubTexture = Helper_RandomFloat(minVal: -2.0, maxVal: 2.0);
      v17[1].m_Pos.z = flInitialDeltaTime;
      v19 = *(float *)(LODWORD(x) + 2676);
      LODWORD(vecLocalPosition.y) = 64;
      v17[1].m_Pos.y = v19;
      LODWORD(vecLocalPosition.x) = 64;
      LOWORD(v17[2].m_pPrev) = -29632;
      BYTE2(v17[2].m_pPrev) = -31;
      *(_WORD *)((char *)&v17[2].m_pPrev + 3) = (unsigned __int8)Helper_RandomInt(
                                                                   minVal: SLODWORD(vecLocalPosition.x),
                                                                   maxVal: SLODWORD(vecLocalPosition.y));
      BYTE1(v17[2].m_pNext) = (int)*(float *)(LODWORD(x) + 2680);
      BYTE2(v17[2].m_pNext) = (int)*(float *)(LODWORD(x) + 2684);
      *(Vector *)&v17[1].m_pPrev = vec3_origin;
      v17->m_Pos.x = (float)(flInitialDeltaTime * *(float *)&v17[1].m_pPrev) + v17->m_Pos.x;
      v17->m_Pos.y = (float)(*(float *)&v17[1].m_pNext * flInitialDeltaTime) + v17->m_Pos.y;
      v17->m_Pos.z = (float)(*(float *)&v17[1].m_pSubTexture * flInitialDeltaTime) + v17->m_Pos.z;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066A50
// Name: public: virtual void C_EntityParticleTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_EntityParticleTrail::Update(
        C_EntityParticleTrail *this@<ecx>,
        studiohdr_t *a2@<edi>,
        float fTimeDelta)
{
  unsigned int v4; // ecx
  C_BaseEntity **v5; // eax
  C_BaseEntity *v6; // ebx
  C_BaseAnimating *v7; // eax
  IVModelInfoClient_vtbl *v8; // edi
  const struct model_t *v9; // eax
  int HitboxSet; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  const Vector *v13; // eax
  float y; // xmm0_4
  int v15; // eax
  const Vector *v16; // [esp+14h] [ebp-41Ch]
  matrix3x4_t *hitboxbones[256]; // [esp+28h] [ebp-408h] BYREF
  studiohdr_t *pStudioHdr; // [esp+428h] [ebp-8h]
  C_BaseAnimating *pAnimating; // [esp+42Ch] [ebp-4h]
  int savedregs; // [esp+430h] [ebp+0h] BYREF

  v4 = *((_DWORD *)this - 419);
  if ( v4 != -1 )
  {
    v5 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v4];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4) )
    {
      v6 = *v5;
      if ( *v5 != nullptr )
      {
        v7 = v6->GetBaseAnimating(this: v6);
        pAnimating = v7;
        if ( v7 != nullptr
          && C_BaseAnimating::HitboxToWorldTransforms(this: v7, pHitboxToWorld: hitboxbones) != 0
          && (v8 = modelinfo->__vftable,
              v9 = pAnimating->GetModel(this: &pAnimating->IClientRenderable),
              a2 = v8->GetStudiomodel(this: modelinfo, a2: v9),
              pStudioHdr = a2,
              a2 != nullptr)
          && (HitboxSet = C_BaseAnimating::GetHitboxSet(this: pAnimating),
              (a2 = (studiohdr_t *)((char *)pStudioHdr + 12 * HitboxSet + a2->hitboxsetindex)) != nullptr) )
        {
          while ( 1 )
          {
            y = this->m_vecVelocity.y;
            v12 = fTimeDelta;
            if ( fTimeDelta < y )
              break;
            this->m_vecVelocity.y = this->m_vecVelocity.x;
            fTimeDelta = fTimeDelta - y;
            v15 = random->RandomInt(this: random, a2: 0, a3: a2->version - 1);
            C_EntityParticleTrail::AddParticle(
              this: (C_EntityParticleTrail *)((char *)this - 2432),
              a2: COERCE_FLOAT(&savedregs),
              a3: (int)a2,
              a4: (int)this,
              flInitialDeltaTime: fTimeDelta,
              vecMins: (const Vector *)((char *)&a2->checksum + 68 * v15 + a2->checksum),
              vecMaxs: (const Vector *)&a2->name[68 * v15 + 8 + a2->checksum],
              boxToWorld: hitboxbones[*(int *)((char *)&a2->id + 68 * v15 + a2->checksum)]);
          }
        }
        else
        {
          while ( 1 )
          {
            v11 = this->m_vecVelocity.y;
            v12 = fTimeDelta;
            if ( fTimeDelta < v11 )
              break;
            this->m_vecVelocity.y = this->m_vecVelocity.x;
            fTimeDelta = fTimeDelta - v11;
            C_BaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
            v16 = v6->m_Collision.OBBMaxs(this: &v6->m_Collision);
            v13 = v6->m_Collision.OBBMins(this: &v6->m_Collision);
            C_EntityParticleTrail::AddParticle(
              this: (C_EntityParticleTrail *)((char *)this - 2432),
              a2: COERCE_FLOAT(&savedregs),
              a3: (int)a2,
              a4: (int)this,
              flInitialDeltaTime: fTimeDelta,
              vecMins: v13,
              vecMaxs: v16,
              boxToWorld: &v6->m_rgflCoordinateFrame);
          }
        }
        this->m_vecVelocity.y = this->m_vecVelocity.y - v12;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066C30
// Name: public: virtual void C_EntityParticleTrail::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityParticleTrail::RenderParticles(C_EntityParticleTrail *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  CParticleMgr *v6; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  int v10; // ecx
  float v11; // xmm4_4
  int v12; // edx
  float v13; // xmm0_4
  float m_pPrev_low; // xmm1_4
  int m_pPrev_high; // eax
  float v16; // xmm1_4
  int v17; // ecx
  Vector color; // [esp+10h] [ebp-18h] BYREF
  Vector tPos; // [esp+1Ch] [ebp-Ch] BYREF
  float t; // [esp+30h] [ebp+8h]

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
      t = i[1].m_Pos.z / i[1].m_Pos.y;
      v6 = ParticleMgr();
      y = i->m_Pos.y;
      x = i->m_Pos.x;
      z = i->m_Pos.z;
      v10 = BYTE1(i[2].m_pPrev);
      v11 = v6->m_mModelView.m[1][1] * y;
      tPos.x = (float)((float)((float)(v6->m_mModelView.m[0][1] * y) + (float)(x * v6->m_mModelView.m[0][0]))
                     + (float)(v6->m_mModelView.m[0][2] * z))
             + v6->m_mModelView.m[0][3];
      v12 = BYTE2(i[2].m_pPrev);
      tPos.y = (float)((float)((float)(v6->m_mModelView.m[1][0] * x) + v11) + (float)(v6->m_mModelView.m[1][2] * z))
             + v6->m_mModelView.m[1][3];
      v13 = (float)((float)((float)(v6->m_mModelView.m[2][0] * x) + (float)(v6->m_mModelView.m[2][1] * y))
                  + (float)(v6->m_mModelView.m[2][2] * z))
          + v6->m_mModelView.m[2][3];
      m_pPrev_low = (float)LOBYTE(i[2].m_pPrev);
      m_pPrev_high = HIBYTE(i[2].m_pPrev);
      tPos.z = v13;
      color.x = m_pPrev_low * 0.0039215689;
      v16 = (float)v10;
      v17 = BYTE2(i[2].m_pNext);
      color.y = v16 * 0.0039215689;
      color.z = (float)v12 * 0.0039215689;
      RenderParticle_ColorSize(
        pDraw: pIterator->m_pParticleDraw,
        pos: &tPos,
        &color,
        alpha: (float)((float)((float)((float)LOBYTE(i[2].m_pNext) * 0.0039215689) - (float)((float)m_pPrev_high * 0.0039215689))
              * t)
      + (float)((float)m_pPrev_high * 0.0039215689),
        size: (float)(unsigned __int8)(int)(float)((float)((float)(v17 - BYTE1(i[2].m_pNext)) * t) + (float)BYTE1(i[2].m_pNext)));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411AF0
// Name: DT_EntityParticleTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EntityParticleTrail::g_RecvTable);
  return atexit(func: DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411B10
// Name: DT_EntityParticleTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EntityParticleTrail::ignored>();
  DT_EntityParticleTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104301A0
// Name: DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EntityParticleTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x100666D0
// Name: _C_EntityParticleTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EntityParticleTrail_CreateObject(int entnum, int serialNum)
{
  C_EntityParticleTrail *v2; // eax
  C_EntityParticleTrail *v3; // eax
  C_EntityParticleTrail *v4; // esi

  v2 = (C_EntityParticleTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xA90u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EntityParticleTrail::C_EntityParticleTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411B20
// Name: _dynamic_initializer_for__cl_ambient_light_disableentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ambient_light_disableentities__()
{
  ConVar::ConVar(
    this: &cl_ambient_light_disableentities,
    pName: "cl_ambient_light_disableentities",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable map ambient light entities.");
  return atexit(func: dynamic_atexit_destructor_for__cl_ambient_light_disableentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10411B50
// Name: _dynamic_initializer_for__s_EnvAmbientLightMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EnvAmbientLightMgr__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &s_EnvAmbientLightMgr, name: nullptr);
  s_EnvAmbientLightMgr.__vftable = (CSpatialEntityMgr_vtbl *)&CSpatialEntityMgr::`vftable';
  s_EnvAmbientLightMgr.m_SpatialEntities.m_Memory.m_pMemory = nullptr;
  s_EnvAmbientLightMgr.m_SpatialEntities.m_Memory.m_nAllocationCount = 0;
  s_EnvAmbientLightMgr.m_SpatialEntities.m_Memory.m_nGrowSize = 0;
  s_EnvAmbientLightMgr.m_SpatialEntities.m_Size = 0;
  s_EnvAmbientLightMgr.m_SpatialEntities.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__s_EnvAmbientLightMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10411BA0
// Name: _dynamic_initializer_for____g_C_EnvAmbientLightClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvAmbientLightClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvAmbientLightClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvAmbientLightClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104301B0
// Name: _dynamic_atexit_destructor_for__cl_ambient_light_disableentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ambient_light_disableentities__()
{
  ConVar::~ConVar(this: &cl_ambient_light_disableentities);
}
