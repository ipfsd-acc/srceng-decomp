// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_smokevolume.cpp
// Functions: 16
// ============================================================

#include "game\client\c_func_smokevolume.h"

//------------------------------------------------------------------------------
// Address: 0x100717A0
// Name: public: virtual class ClientClass __near * C_FuncSmokeVolume::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FuncSmokeVolume::GetClientClass(C_FuncSmokeVolume *this)
{
  return &__g_C_FuncSmokeVolumeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10071990
// Name: public: virtual C_FuncSmokeVolume::~C_FuncSmokeVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::~C_FuncSmokeVolume(C_FuncSmokeVolume *this)
{
  C_FuncSmokeVolume::SmokeParticleInfo *m_pSmokeParticleInfos; // [esp-4h] [ebp-8h]

  m_pSmokeParticleInfos = this->m_pSmokeParticleInfos;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FuncSmokeVolume_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_FuncSmokeVolume::`vftable';
  C_BaseEntity::operator delete(pMem: m_pSmokeParticleInfos);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100719F0
// Name: public: virtual void C_FuncSmokeVolume::NotifyRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::NotifyRemove(C_FuncSmokeVolume *this)
{
  *(_DWORD *)&this->m_iName[232] = 0;
  *(_DWORD *)&this->m_iName[228] = 0;
  *(_DWORD *)&this->m_iName[224] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071A30
// Name: public: C_FuncSmokeVolume::C_FuncSmokeVolume(void)
// Source: json
//------------------------------------------------------------------------------
C_FuncSmokeVolume *__thiscall C_FuncSmokeVolume::C_FuncSmokeVolume(C_FuncSmokeVolume *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FuncSmokeVolume_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FuncSmokeVolume::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_FuncSmokeVolume::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_FuncSmokeVolume::`vftable';
  this->m_bFirstUpdate = true;
  this->m_vLastOrigin.x = 0.0;
  this->m_vLastOrigin.y = 0.0;
  this->m_vLastOrigin.z = 0.0;
  this->m_vLastAngles.x = 0.0;
  this->m_vLastAngles.y = 0.0;
  this->m_vLastAngles.z = 0.0;
  this->m_SpacingRadius = 0.0;
  this->m_ParticleRadius = 0.0;
  this->m_pSmokeParticleInfos = nullptr;
  this->m_MinColor.x = 1.0;
  this->m_MinColor.y = 1.0;
  this->m_MinColor.z = 1.0;
  this->m_MaxColor.x = 1.0;
  this->m_MaxColor.y = 1.0;
  this->m_MaxColor.z = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10071B40
// Name: public: virtual void C_FuncSmokeVolume::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::OnDataChanged(C_FuncSmokeVolume *this, DataUpdateType_t updateType)
{
  float flMaxParticleRadius; // xmm0_4
  int v4; // xmm2_4
  float *v5; // ebx
  float *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  void *v11; // eax
  int v12; // ebx
  CParticleMgr *v13; // eax
  void *v14; // [esp-8h] [ebp-10h]

  *(float *)&this->m_zCount = (float)*((unsigned __int8 *)&this->m_bSimulate + 4) * 0.0039215689;
  this->m_SpacingRadius = (float)*((unsigned __int8 *)&this->m_bSimulate + 5) * 0.0039215689;
  this->m_MinColor.x = (float)*((unsigned __int8 *)&this->m_bSimulate + 6) * 0.0039215689;
  this->m_MinColor.y = (float)LOBYTE(this->IPrototypeAppEffect::__vftable) * 0.0039215689;
  this->m_MinColor.z = (float)BYTE1(this->IPrototypeAppEffect::__vftable) * 0.0039215689;
  this->m_MaxColor.x = (float)BYTE2(this->IPrototypeAppEffect::__vftable) * 0.0039215689;
  flMaxParticleRadius = *(float *)&this->m_MaterialName[248] * 0.5;
  *(float *)&v4 = *(float *)&this->m_MaterialName[252] * 0.5;
  *(float *)&this->m_spawnflags = flMaxParticleRadius;
  this->m_yCount = v4;
  CParticleEffectBinding::SetParticleCullRadius(
    this: (CParticleEffectBinding *)(&this->m_bIsBlurred + 4),
    flMaxParticleRadius);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v5 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 292))(a1: (char *)this - 8);
    v6 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 296))(a1: (char *)this - 8);
    v7 = *v6 - *v5;
    v8 = *(float *)&this->m_yCount * 2.0;
    v9 = v6[1] - v5[1];
    v10 = v6[2] - v5[2];
    this->m_maxDrawDistance = this->m_RotationSpeed;
    this->m_MaterialHandle = (CParticleSubTexture *)(int)(float)((float)((float)(1.0 / v8) * v7) + 0.5);
    v14 = *(void **)&this->m_bStarted;
    this->m_pSmokeParticleInfos = (C_FuncSmokeVolume::SmokeParticleInfo *)(int)(float)((float)((float)(1.0 / v8) * v9)
                                                                                     + 0.5);
    this->m_xCount = (int)(float)((float)((float)(1.0 / v8) * v10) + 0.5);
    C_BaseEntity::operator delete(pMem: v14);
    v11 = MemAlloc_Alloc(
            nSize: (24
           * (unsigned __int64)(unsigned int)((int)this->m_pSmokeParticleInfos
                                            * (int)this->m_MaterialHandle
                                            * this->m_xCount)) >> 32 != 0
          ? -1
          : 24 * (int)this->m_pSmokeParticleInfos * (int)this->m_MaterialHandle * this->m_xCount);
    v12 = *(_DWORD *)&this->m_bSimulate;
    *(_DWORD *)&this->m_bStarted = v11;
    v13 = ParticleMgr();
    (*(void (__thiscall **)(bool *, CParticleMgr *, _DWORD))(v12 + 4))(a1: &this->m_bSimulate, a2: v13, a3: 0);
  }
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10071D50
// Name: public: virtual void C_FuncSmokeVolume::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::SimulateParticles(C_FuncSmokeVolume *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // esi
  Particle *m_pNext; // edx

  if ( *(float *)&this->m_iName[204] != 0.0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    if ( m_pNext != &m_pMaterial->m_Particles )
    {
      do
      {
        pIterator->m_pNextParticle = m_pNext->m_pNext;
        *(float *)&m_pNext[1].m_pNext = *(float *)&m_pNext[1].m_pPrev
                                      * 0.0174532925199433
                                      * *(float *)&this->m_iName[184]
                                      * pIterator->m_flTimeDelta
                                      + *(float *)&m_pNext[1].m_pNext;
        m_pNext = pIterator->m_pNextParticle;
      }
      while ( m_pNext != &pIterator->m_pMaterial->m_Particles );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071DE0
// Name: void RenderParticle_ColorSizeAngle(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_ColorSizeAngle(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size,
        float angle)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  float *m_pCurrPosition; // eax
  float z; // xmm4_4
  float v10; // xmm0_4
  int v11; // ebx
  float *v12; // ecx
  float v13; // xmm0_4
  float *v14; // eax
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float *v18; // ecx
  float v19; // xmm4_4
  float *v20; // eax
  _DWORD *m_pCurrColor; // edx
  float v22; // xmm1_4
  float *v23; // ecx
  float v24; // xmm0_4
  float *v25; // eax
  float v26; // xmm4_4
  _DWORD *v27; // ecx
  float v28; // xmm1_4
  float *v29; // esi
  float v30; // xmm0_4
  int v31; // [esp+8h] [ebp-14h]
  int v32; // [esp+Ch] [ebp-10h]
  int v33; // [esp+10h] [ebp-Ch]
  CVertexBuilder *p_m_VertexBuilder; // [esp+14h] [ebp-8h]
  float ca; // [esp+18h] [ebp-4h]
  float sa; // [esp+30h] [ebp+14h]

  if ( alpha >= 0.001 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      v33 = (int)(float)(color->x * 254.89999);
      v32 = (int)(float)(color->y * 254.89999);
      v31 = (int)(float)(color->z * 254.89999);
      ca = cos(angle);
      sa = sin(angle);
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      z = pos->z;
      v10 = (float)((float)(COERCE_FLOAT(LODWORD(sa) ^ _mask__NegFloat_) - ca) * size) + pos->y;
      *m_pCurrPosition = (float)((float)(sa - ca) * size) + pos->x;
      m_pCurrPosition[1] = v10;
      m_pCurrPosition[2] = z;
      v11 = (unsigned __int8)v31
          | (((unsigned __int8)v32
            | (((unsigned __int8)v33 | ((unsigned __int8)(int)(float)(alpha * 254.89999) << 8)) << 8)) << 8);
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v11;
      v12 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v13 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v12 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v12[1] = v13;
      p_m_VertexBuilder = &m_pMeshBuilder->m_VertexBuilder;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v14 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v15 = pos->z;
      v16 = (float)((float)(ca - sa) * size) + pos->y;
      *v14 = (float)((float)(COERCE_FLOAT(LODWORD(ca) ^ _mask__NegFloat_) - sa) * size) + pos->x;
      v14[1] = v16;
      v14[2] = v15;
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = v11;
      v17 = pDraw->m_pSubTexture->m_tCoordMins[1];
      v18 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v18 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v18[1] = v17;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v19 = pos->z;
      v20 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      m_pCurrColor = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      v22 = (float)((float)(sa + ca) * size) + pos->y;
      *v20 = (float)((float)(ca - sa) * size) + pos->x;
      v20[1] = v22;
      v20[2] = v19;
      *m_pCurrColor = v11;
      v23 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v24 = pDraw->m_pSubTexture->m_tCoordMins[1];
      *v23 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v23[1] = v24;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v25 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v26 = pos->z;
      v27 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      v28 = (float)((float)(sa - ca) * size) + pos->y;
      *v25 = (float)((float)(sa + ca) * size) + pos->x;
      v25[1] = v28;
      v25[2] = v26;
      *v27 = v11;
      v29 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v30 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      *v29 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v29[1] = v30;
      CVertexBuilder::AdvanceVertex(this: p_m_VertexBuilder);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100720B0
// Name: public: virtual void C_FuncSmokeVolume::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::Update(C_FuncSmokeVolume *this, float fTimeDelta)
{
  C_FuncSmokeVolume *v2; // edi
  char *v3; // esi
  float *v4; // eax
  float *v5; // ecx
  float v6; // xmm0_4
  const Vector *v7; // eax
  double v8; // st7
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  bool v15; // cc
  float v16; // xmm1_4
  int v17; // ecx
  int v18; // eax
  unsigned int v19; // edi
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  IUniformRandomStream *v26; // ecx
  bool v27; // al
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // edx
  int v34; // eax
  bool v35; // zf
  int v36; // eax
  int v37; // edx
  IUniformRandomStream *v38; // ecx
  double v39; // st7
  unsigned int v40; // eax
  float v41; // xmm0_4
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  float v45; // xmm0_4
  C_FuncSmokeVolume::SmokeParticleInfo *v46; // edx
  int v47; // ecx
  float *v48; // eax
  int v49; // ecx
  float v50; // xmm0_4
  int v51; // eax
  float v52; // xmm0_4
  C_FuncSmokeVolume::SmokeParticleInfo *v53; // edx
  int v54; // ecx
  float *v55; // eax
  __m128 v56; // xmm0
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm4_4
  float **v61; // eax
  float v62; // xmm0_4
  float *v63; // ecx
  float *v64; // ecx
  float *v65; // ecx
  int v66; // eax
  double v67; // xmm0_8
  int v68; // edx
  int v69; // edx
  float v70; // xmm5_4
  float v71; // xmm6_4
  float v72; // xmm7_4
  float *v73; // edi
  float *v74; // eax
  float v75; // xmm6_4
  float v76; // xmm7_4
  int nTotal; // [esp+14h] [ebp-7Ch]
  float v78; // [esp+18h] [ebp-78h]
  float v79; // [esp+1Ch] [ebp-74h]
  float v80; // [esp+20h] [ebp-70h]
  int zCountOffset; // [esp+24h] [ebp-6Ch]
  float v82; // [esp+28h] [ebp-68h]
  float v83; // [esp+2Ch] [ebp-64h]
  float v84; // [esp+30h] [ebp-60h]
  int xCountOffset; // [esp+38h] [ebp-58h]
  int yCountOffset; // [esp+3Ch] [ebp-54h]
  int yCount; // [esp+40h] [ebp-50h]
  int zCount; // [esp+44h] [ebp-4Ch]
  int v90; // [esp+48h] [ebp-48h]
  Vector vWorldMins; // [esp+4Ch] [ebp-44h] BYREF
  int testX; // [esp+58h] [ebp-38h]
  float minViewOrigingDistance; // [esp+5Ch] [ebp-34h]
  int otherZ; // [esp+60h] [ebp-30h]
  C_FuncSmokeVolume::SmokeParticleInfo *pOther; // [esp+64h] [ebp-2Ch]
  int testY; // [esp+68h] [ebp-28h]
  int y; // [esp+6Ch] [ebp-24h]
  float d; // [esp+70h] [ebp-20h]
  Vector myPos; // [esp+74h] [ebp-1Ch] BYREF
  int x; // [esp+80h] [ebp-10h]
  int i; // [esp+84h] [ebp-Ch]
  bool bFound; // [esp+8Bh] [ebp-5h]
  int xCount; // [esp+8Ch] [ebp-4h]
  int savedregs; // [esp+90h] [ebp+0h] BYREF

  v2 = this;
  v3 = (char *)this - 2432;
  d = COERCE_FLOAT((*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432));
  v4 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 44))(a1: v3);
  v5 = (float *)LODWORD(d);
  if ( fabs(*(float *)LODWORD(d) - *(float *)&v2->m_MoveType) > 0.1
    || fabs(*(float *)(LODWORD(d) + 4) - v2->m_flAnimTime) > 0.1
    || fabs(*(float *)(LODWORD(d) + 8) - v2->m_flOldAnimTime) > 0.1
    || fabs(*v4 - v2->m_flSimulationTime) > 0.1
    || fabs(v4[1] - v2->m_flOldSimulationTime) > 0.1
    || fabs(v4[2] - *(float *)&v2->m_nOldRenderMode) > 0.1
    || LOBYTE(v2->m_VisibilityBits.m_Ints[0]) != 0 )
  {
    LOBYTE(v2->m_VisibilityBits.m_Ints[0]) = 0;
    v2->m_flSimulationTime = *v4;
    v2->m_flOldSimulationTime = v4[1];
    *(float *)&v2->m_nOldRenderMode = v4[2];
    *(float *)&v2->m_MoveType = *v5;
    v2->m_flAnimTime = v5[1];
    v2->m_flOldAnimTime = v5[2];
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: (CCollisionProperty *)&v2[-1].m_pIntermediateData[69],
      entityMins: (const Vector *)&v2[-1].m_pIntermediateData[71],
      entityMaxs: (const Vector *)&v2[-1].m_pIntermediateData[74],
      pWorldMins: &vWorldMins,
      pWorldMaxs: &myPos);
    v6 = *(float *)&v2->m_iName[208];
    vWorldMins.x = vWorldMins.x - v6;
    vWorldMins.z = vWorldMins.z - v6;
    vWorldMins.y = vWorldMins.y - v6;
    myPos.y = myPos.y + v6;
    myPos.x = myPos.x + v6;
    myPos.z = myPos.z + v6;
    CParticleEffectBinding::SetBBox(
      this: (CParticleEffectBinding *)&v2->IClientRenderable,
      bbMin: &vWorldMins,
      bbMax: &myPos,
      bDisableAutoUpdate: true);
  }
  minViewOrigingDistance = 3.4028235e38;
  v7 = MainViewOrigin(nSlot: 0);
  v8 = CCollisionProperty::CalcDistanceFromPoint(
         this: (CCollisionProperty *)&v2[-1].m_pIntermediateData[69],
         a2: COERCE_FLOAT(&savedregs),
         vecWorldPt: v7);
  d = v8;
  if ( v8 >= 3.4028235e38 )
    v9 = minViewOrigingDistance;
  else
    v9 = d;
  v10 = *(float *)&v2->m_iName[196];
  v11 = *(float *)&v2->m_iName[192];
  if ( v10 > 0.0 && v9 > v10 )
    v11 = 0.0;
  v12 = *(float *)&v2->m_iName[204];
  v13 = fTimeDelta;
  if ( v11 <= v12 )
  {
    if ( v12 <= v11 )
      goto LABEL_21;
    v16 = v12 - (float)(*(float *)&v2->m_iName[180] * fTimeDelta);
    *(float *)&v2->m_iName[204] = v16;
    v15 = v11 <= v16;
  }
  else
  {
    v14 = (float)(*(float *)&v2->m_iName[180] * fTimeDelta) + v12;
    *(float *)&v2->m_iName[204] = v14;
    v15 = v14 <= v11;
  }
  if ( !v15 )
    *(float *)&v2->m_iName[204] = v11;
LABEL_21:
  if ( *(float *)&v2->m_iName[204] != 0.0 )
  {
    minViewOrigingDistance = *(float *)&v2->m_iName[176] / (float)(*(float *)&v2->m_iName[188] + 0.1);
    vWorldMins.x = NAN;
    vWorldMins.y = 0.0;
    LODWORD(vWorldMins.z) = 1;
    d = minViewOrigingDistance * 0.5;
    if ( (LODWORD(minViewOrigingDistance) & 0x7F800000) != 0x7F800000 && (LODWORD(d) & 0x7F800000) != 0x7F800000 )
    {
      nTotal = *(_DWORD *)&v2->m_iName[224] * *(_DWORD *)&v2->m_iName[228] * *(_DWORD *)&v2->m_iName[232];
      i = 0;
      if ( nTotal > 0 )
      {
        v90 = 0;
        while ( 1 )
        {
          v17 = *(_DWORD *)&v2->m_iName[220];
          v18 = *(_DWORD *)(v90 + v17);
          v19 = v17 + v90;
          if ( v18 == 0 )
            goto LABEL_56;
          v20 = *(_DWORD *)(v19 + 4);
          if ( v20 == -1 )
            break;
          v40 = v17 + 24 * v20;
          x = v40;
          if ( v19 < v40 )
          {
            v41 = *(float *)(v40 + 8) + v13;
            *(float *)(v40 + 8) = v41;
            v42 = i;
            *(float *)(v19 + 8) = v41;
            v43 = *((_DWORD *)v3 + 746) * *((_DWORD *)v3 + 747);
            v44 = v42 / v43;
            v45 = *((float *)v3 + 749);
            v46 = (C_FuncSmokeVolume::SmokeParticleInfo *)(v43 * v44);
            v47 = *((_DWORD *)v3 + 746);
            otherZ = v44;
            pOther = v46;
            v82 = (float)((float)((float)(i - v47 * ((i - (int)v46) / v47) - (int)v46) * v45) * 2.0) + v45;
            v83 = (float)((float)((float)((i - (int)v46) / v47) * v45) * 2.0) + v45;
            v84 = (float)((float)((float)v44 * v45) * 2.0) + v45;
            v48 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 292))(a1: v3);
            v49 = *((_DWORD *)v3 + 746) * *((_DWORD *)v3 + 747);
            myPos.x = *v48 + v82;
            myPos.y = v48[1] + v83;
            v50 = v48[2];
            y = *(_DWORD *)(v19 + 4);
            v51 = y / v49;
            myPos.z = v50 + v84;
            v52 = *((float *)v3 + 749);
            v53 = (C_FuncSmokeVolume::SmokeParticleInfo *)(v49 * (y / v49));
            v54 = *((_DWORD *)v3 + 746);
            otherZ = v51;
            pOther = v53;
            v78 = (float)((float)((float)(y - v54 * ((y - (int)v53) / v54) - (int)v53) * v52) * 2.0) + v52;
            v79 = (float)((float)((float)((y - (int)v53) / v54) * v52) * 2.0) + v52;
            v80 = (float)((float)((float)v51 * v52) * 2.0) + v52;
            v55 = (float *)(*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 292))(a1: v3);
            v56 = (__m128)*(unsigned int *)(v19 + 8);
            v57 = *(float *)(v19 + 12);
            v58 = *v55 + v78;
            v59 = v55[1] + v79;
            v60 = v55[2] + v80;
            if ( v56.m128_f32[0] < v57 )
            {
              v56.m128_f32[0] = (float)((float)(v56.m128_f32[0] * 2.0) * 1.5707964) / v57;
              __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v56));
              v66 = x;
              *(float *)&v67 = v67;
              *(float *)&v67 = (float)(*(float *)&v67 + 1.0) * 0.5;
              *(float *)(*(_DWORD *)v19 + 32) = (float)((float)(*(float *)(x + 16) - *(float *)(v19 + 16))
                                                      * (float)(1.0 - *(float *)&v67))
                                              + *(float *)(v19 + 16);
              *(float *)(*(_DWORD *)v66 + 32) = (float)((float)(*(float *)(v66 + 16) - *(float *)(v19 + 16))
                                                      * *(float *)&v67)
                                              + *(float *)(v19 + 16);
              v68 = *(unsigned __int8 *)(v66 + 20);
              xCount = *(_DWORD *)v19 + 37;
              *(_BYTE *)xCount = (int)(float)((float)((float)(v68 - *(unsigned __int8 *)(v19 + 20))
                                                    * (float)(1.0 - *(float *)&v67))
                                            + (float)*(unsigned __int8 *)(v19 + 20));
              *(_BYTE *)(xCount + 1) = (int)(float)((float)((float)(*(unsigned __int8 *)(v66 + 21)
                                                                  - *(unsigned __int8 *)(v19 + 21))
                                                          * (float)(1.0 - *(float *)&v67))
                                                  + (float)*(unsigned __int8 *)(v19 + 21));
              *(_BYTE *)(xCount + 2) = (int)(float)((float)((float)(*(unsigned __int8 *)(v66 + 22)
                                                                  - *(unsigned __int8 *)(v19 + 22))
                                                          * (float)(1.0 - *(float *)&v67))
                                                  + (float)*(unsigned __int8 *)(v19 + 22));
              v69 = *(unsigned __int8 *)(v66 + 20);
              xCount = *(_DWORD *)v66 + 37;
              *(_BYTE *)xCount = (int)(float)((float)((float)(v69 - *(unsigned __int8 *)(v19 + 20)) * *(float *)&v67)
                                            + (float)*(unsigned __int8 *)(v19 + 20));
              v70 = v58 - myPos.x;
              v71 = v59 - myPos.y;
              v72 = v60 - myPos.z;
              *(_BYTE *)(xCount + 1) = (int)(float)((float)((float)(*(unsigned __int8 *)(v66 + 21)
                                                                  - *(unsigned __int8 *)(v19 + 21))
                                                          * *(float *)&v67)
                                                  + (float)*(unsigned __int8 *)(v19 + 21));
              *(_BYTE *)(xCount + 2) = (int)(float)((float)((float)(*(unsigned __int8 *)(v66 + 22)
                                                                  - *(unsigned __int8 *)(v19 + 22))
                                                          * *(float *)&v67)
                                                  + (float)*(unsigned __int8 *)(v19 + 22));
              v73 = *(float **)v19;
              v73[3] = (float)(v70 * (float)(1.0 - *(float *)&v67)) + myPos.x;
              v73[4] = (float)(v71 * (float)(1.0 - *(float *)&v67)) + myPos.y;
              v73[5] = (float)(v72 * (float)(1.0 - *(float *)&v67)) + myPos.z;
              v74 = *(float **)v66;
              v75 = (float)(v71 * *(float *)&v67) + myPos.y;
              v76 = (float)(v72 * *(float *)&v67) + myPos.z;
              v74[3] = (float)(v70 * *(float *)&v67) + myPos.x;
              v74[4] = v75;
              v74[5] = v76;
            }
            else
            {
              v61 = (float **)x;
              v62 = myPos.x;
              *(_DWORD *)(x + 4) = -1;
              *(_DWORD *)(v19 + 4) = -1;
              v63 = *(float **)v19;
              v63[3] = v58;
              v63[4] = v59;
              v63[5] = v60;
              v64 = *v61;
              v64[3] = v62;
              v64[4] = myPos.y;
              v64[5] = myPos.z;
              v65 = *(float **)v19;
              *(_DWORD *)v19 = *v61;
              *v61 = v65;
            }
          }
LABEL_56:
          v90 += 24;
          if ( ++i >= nTotal )
            return;
          v13 = fTimeDelta;
          v2 = this;
        }
        *(float *)(v18 + 32) = *(float *)(v19 + 16);
        *(_BYTE *)(*(_DWORD *)v19 + 37) = *(_BYTE *)(v19 + 20);
        *(_BYTE *)(*(_DWORD *)v19 + 38) = *(_BYTE *)(v19 + 21);
        *(_BYTE *)(*(_DWORD *)v19 + 39) = *(_BYTE *)(v19 + 22);
        v21 = *((_DWORD *)v3 + 746) * *((_DWORD *)v3 + 747);
        v22 = i / v21;
        v23 = v21 * (i / v21);
        v24 = *((IUniformRandomStream **)v3 + 746);
        otherZ = v22;
        y = (i - v23) / (int)v24;
        x = i - (_DWORD)v24 * y - v23;
        xCountOffset = _RandomInt(this: v24, a2: 0, a3: 0x7FFF);
        yCountOffset = _RandomInt(this: v25, a2: 0, a3: 0x7FFF);
        zCountOffset = _RandomInt(this: v26, a2: 0, a3: 0x7FFF);
        v27 = false;
        bFound = false;
        xCount = 0;
LABEL_30:
        if ( v27 )
          goto LABEL_56;
        yCount = 0;
LABEL_32:
        if ( v27 )
          goto LABEL_50;
        zCount = 0;
        testX = x + *((_DWORD *)&vWorldMins.x + (xCount + xCountOffset) % 3);
        testY = y + *((_DWORD *)&vWorldMins.x + (yCount + yCountOffset) % 3);
        v28 = 0;
        while ( 1 )
        {
          v29 = (zCountOffset + v28) % 3;
          v30 = testX;
          v31 = otherZ + *((_DWORD *)&vWorldMins.x + v29);
          if ( testX == x )
          {
            if ( testY == y && v31 == otherZ )
              goto LABEL_46;
            v30 = testX;
          }
          if ( v30 >= 0 && testY >= 0 && v31 >= 0 && v30 < *((_DWORD *)v3 + 746) )
          {
            v32 = *((_DWORD *)v3 + 747);
            if ( testY < v32 && v31 < *((_DWORD *)v3 + 748) )
            {
              v33 = 3 * (testX + *((_DWORD *)v3 + 746) * (testY + v32 * v31));
              v34 = *((_DWORD *)v3 + 745);
              v35 = *(_DWORD *)(v34 + 8 * v33) == 0;
              v36 = v34 + 8 * v33;
              pOther = (C_FuncSmokeVolume::SmokeParticleInfo *)v36;
              if ( !v35 && *(_DWORD *)(v36 + 4) == -1 )
              {
                v37 = testY + v31 * *((_DWORD *)v3 + 747);
                v38 = (IUniformRandomStream *)i;
                *(_DWORD *)(v19 + 4) = testX + *((_DWORD *)v3 + 746) * v37;
                *(_DWORD *)(v36 + 8) = 0;
                *(_DWORD *)(v36 + 4) = v38;
                *(_DWORD *)(v19 + 8) = 0;
                v39 = _RandomFloat(this: v38, a2: d, a3: minViewOrigingDistance);
                *(float *)(v19 + 12) = v39;
                v27 = true;
                pOther->m_TradeDuration = v39;
                bFound = true;
LABEL_49:
                if ( ++yCount >= 3 )
                {
LABEL_50:
                  if ( ++xCount >= 3 )
                    goto LABEL_56;
                  goto LABEL_30;
                }
                goto LABEL_32;
              }
            }
          }
LABEL_46:
          v28 = zCount + 1;
          zCount = v28;
          if ( v28 >= 3 )
          {
            v27 = bFound;
            goto LABEL_49;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072A30
// Name: public: virtual void C_FuncSmokeVolume::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::RenderParticles(C_FuncSmokeVolume *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  bool v7; // zf
  int x_low; // ecx
  float v9; // xmm4_4
  int v10; // edx
  float z; // eax
  float v12; // xmm5_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  int x_high; // ecx
  float v18; // xmm4_4
  int v19; // eax
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  CParticleMgr *v26; // eax
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  Vector tRenderPos; // [esp+18h] [ebp-24h] BYREF
  Vector renderPos; // [esp+24h] [ebp-18h]
  Vector color; // [esp+30h] [ebp-Ch] BYREF
  float alpha; // [esp+44h] [ebp+8h]

  if ( *(float *)&this->m_iName[204] != 0.0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    pIterator->m_bGotFirst = true;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    pIterator->m_pCur = m_pNext;
    if ( m_pNext != &m_pMaterial->m_Particles )
    {
      pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
      for ( i = pIterator->m_pCur;
            i != nullptr;
            i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: 1.0) )
      {
        v7 = (this->m_iName[200] & 1) == 0;
        x_low = LOBYTE(i[1].m_Pos.x);
        v9 = *(float *)&this->m_iName[240];
        v10 = BYTE1(i[1].m_Pos.x);
        z = i->m_Pos.z;
        v12 = *(float *)&this->m_iName[244];
        v13 = *(float *)&this->m_iName[248];
        v14 = *(float *)&this->m_iName[256];
        v15 = *(float *)&this->m_nModelIndex;
        *(_QWORD *)&renderPos.x = *(_QWORD *)&i->m_Pos.x;
        alpha = *(float *)&i[1].m_pSubTexture * *(float *)&this->m_iName[204];
        v16 = (float)x_low * 0.0039200312;
        x_high = HIBYTE(i[1].m_Pos.x);
        v18 = v9 + (float)((float)(*(float *)&this->m_iName[252] - v9) * v16);
        renderPos.z = z;
        v19 = BYTE2(i[1].m_Pos.x);
        v20 = v12 + (float)((float)(v14 - v12) * v16);
        v21 = v13 + (float)((float)(v15 - v13) * v16);
        v22 = (float)v10 * 0.0039215689;
        if ( v7 )
        {
          color.x = v22 * v18;
          color.y = (float)((float)v19 * 0.0039215689) * v20;
          color.z = (float)((float)x_high * 0.0039215689) * v21;
        }
        else
        {
          v23 = v22 + v18;
          v24 = (float)((float)v19 * 0.0039215689) + v20;
          v25 = (float)((float)x_high * 0.0039215689) + v21;
          if ( v23 >= 0.0 )
          {
            if ( v23 > 1.0 )
              v23 = 1.0;
          }
          else
          {
            v23 = 0.0;
          }
          color.x = v23;
          if ( v24 >= 0.0 )
          {
            if ( v24 > 1.0 )
              v24 = 1.0;
          }
          else
          {
            v24 = 0.0;
          }
          color.y = v24;
          if ( v25 >= 0.0 )
          {
            if ( v25 > 1.0 )
              v25 = 1.0;
            color.z = v25;
          }
          else
          {
            color.z = 0.0;
          }
        }
        v26 = ParticleMgr();
        v27 = v26->m_mModelView.m[1][0];
        tRenderPos.x = (float)((float)((float)(v26->m_mModelView.m[0][1] * renderPos.y)
                                     + (float)(v26->m_mModelView.m[0][0] * renderPos.x))
                             + (float)(v26->m_mModelView.m[0][2] * renderPos.z))
                     + v26->m_mModelView.m[0][3];
        tRenderPos.y = (float)((float)((float)(v26->m_mModelView.m[1][1] * renderPos.y) + (float)(v27 * renderPos.x))
                             + (float)(v26->m_mModelView.m[1][2] * renderPos.z))
                     + v26->m_mModelView.m[1][3];
        tRenderPos.z = (float)((float)((float)(v26->m_mModelView.m[2][1] * renderPos.y)
                                     + (float)(v26->m_mModelView.m[2][0] * renderPos.x))
                             + (float)(v26->m_mModelView.m[2][2] * renderPos.z))
                     + v26->m_mModelView.m[2][3];
        v28 = -tRenderPos.z;
        if ( (float)-tRenderPos.z <= 30.0 )
        {
          if ( v28 <= 10.0 )
            v29 = 0.0;
          else
            v29 = (float)(v28 - 10.0) * 0.050000001;
        }
        else
        {
          v29 = 1.0;
        }
        RenderParticle_ColorSizeAngle(
          pDraw: pIterator->m_pParticleDraw,
          pos: &tRenderPos,
          &color,
          alpha: v29 * alpha,
          size: *(float *)&this->m_iName[208],
          angle: *(float *)&i[1].m_pNext);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10072D40
// Name: private: void C_FuncSmokeVolume::FillVolume(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_FuncSmokeVolume::FillVolume(C_FuncSmokeVolume *this@<ecx>, float a2@<ebp>, int a3@<esi>)
{
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  float m_SpacingRadius; // xmm0_4
  const Vector *(__thiscall *WorldAlignMins)(C_BaseEntity *); // edx
  float *v9; // eax
  int v10; // xmm1_4
  int v11; // xmm2_4
  C_FuncSmokeVolume::SmokeParticleInfo *v12; // edi
  Particle *v13; // eax
  IUniformRandomStream *v14; // ecx
  int v15; // eax
  IUniformRandomStream *v16; // ecx
  double v17; // st7
  unsigned __int8 v18; // al
  float v19; // xmm0_4
  unsigned __int8 v20; // al
  float v21; // xmm0_4
  float *p_z; // eax
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float m_ParticleRadius; // xmm1_4
  int v27; // [esp+20h] [ebp-118h]
  Vector v28; // [esp+24h] [ebp-114h] BYREF
  CGameTrace trace; // [esp+30h] [ebp-108h] BYREF
  _DWORD v30[4]; // [esp+8Ch] [ebp-ACh] BYREF
  float v31; // [esp+9Ch] [ebp-9Ch]
  float v32; // [esp+A0h] [ebp-98h]
  float v33; // [esp+A4h] [ebp-94h]
  int v34; // [esp+ACh] [ebp-8Ch]
  int v35; // [esp+B0h] [ebp-88h]
  int v36; // [esp+B4h] [ebp-84h]
  int v37; // [esp+BCh] [ebp-7Ch]
  int v38; // [esp+C0h] [ebp-78h]
  int v39; // [esp+C4h] [ebp-74h]
  int v40; // [esp+CCh] [ebp-6Ch]
  char v41; // [esp+D0h] [ebp-68h]
  bool v42; // [esp+D1h] [ebp-67h]
  float f[3]; // [esp+E8h] [ebp-50h] BYREF
  Vector vColor; // [esp+F4h] [ebp-44h]
  float v45; // [esp+100h] [ebp-38h]
  float v46; // [esp+104h] [ebp-34h]
  int v47; // [esp+108h] [ebp-30h]
  float *v48; // [esp+10Ch] [ebp-2Ch]
  int v49; // [esp+110h] [ebp-28h]
  int i; // [esp+114h] [ebp-24h]
  int j; // [esp+118h] [ebp-20h]
  int z; // [esp+11Ch] [ebp-1Ch] BYREF
  int x; // [esp+120h] [ebp-18h]
  int y; // [esp+124h] [ebp-14h]
  Vector vPos; // [esp+128h] [ebp-10h]
  float retaddr; // [esp+138h] [ebp+0h]

  vPos.y = a2;
  vPos.z = retaddr;
  v27 = a3;
  v4 = 0;
  for ( i = 0; v4 < this->m_xCount; i = v4 )
  {
    v5 = 0;
    for ( j = 0; v5 < this->m_yCount; j = v5 )
    {
      v6 = 0;
      v49 = 0;
      if ( this->m_zCount > 0 )
      {
        v46 = (float)v4;
        v45 = (float)v5;
        while ( 1 )
        {
          m_SpacingRadius = this->m_SpacingRadius;
          WorldAlignMins = this->WorldAlignMins;
          vColor.x = (float)((float)(v46 * m_SpacingRadius) * 2.0) + m_SpacingRadius;
          vColor.y = (float)((float)(v45 * m_SpacingRadius) * 2.0) + m_SpacingRadius;
          vColor.z = (float)((float)((float)v6 * m_SpacingRadius) * 2.0) + m_SpacingRadius;
          v9 = (float *)WorldAlignMins(this);
          *(float *)&v10 = v9[1] + vColor.y;
          *(float *)&v11 = v9[2] + vColor.z;
          v12 = &this->m_pSmokeParticleInfos[i + this->m_xCount * (j + v6 * this->m_yCount)];
          *(float *)&z = *v9 + vColor.x;
          x = v10;
          y = v11;
          if ( v12 != nullptr )
          {
            if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)&z, a3: -1, a4: nullptr) & 1) != 0 )
            {
              v12->m_pParticle = nullptr;
            }
            else
            {
              v13 = CParticleEffectBinding::AddParticle(
                      this: &this->m_ParticleEffect,
                      sizeInBytes: 44,
                      hMaterial: this->m_MaterialHandle);
              LODWORD(vPos.x) = v13;
              if ( v13 != nullptr )
              {
                v13->m_Pos.x = *(float *)&z;
                v13->m_Pos.y = *(float *)&x;
                v13->m_Pos.z = *(float *)&y;
                v15 = rand(this: v14);
                *(_BYTE *)(LODWORD(vPos.x) + 36) = 255 * v15 / 0x7FFF;
                *(float *)(LODWORD(vPos.x) + 24) = _RandomFloat(
                                                     this: (IUniformRandomStream *)(255 * v15 / 0x7FFF),
                                                     a2: -1.0,
                                                     a3: 1.0);
                v17 = _RandomFloat(this: v16, a2: -this->m_RotationSpeed, a3: this->m_RotationSpeed);
                *(float *)(LODWORD(vPos.x) + 28) = v17;
              }
              ((void (__thiscall *)(IVEngineClient *, float *, int *, int, int))engine->GetLightForPoint)(
                a1: engine,
                a2: f,
                a3: &z,
                a4: 1,
                a5: v27);
              v18 = LinearToTexture(f: f[0]);
              v19 = f[1];
              v12->m_Color[0] = v18;
              v20 = LinearToTexture(f: v19);
              v21 = f[2];
              v12->m_Color[1] = v20;
              v12->m_Color[2] = LinearToTexture(f: v21);
              p_z = &s_FadePlaneDirections[0].z;
              v12->m_FadeAlpha = 1.0;
              v48 = &s_FadePlaneDirections[0].z;
              v47 = 6;
              while ( 1 )
              {
                v23 = *(p_z - 2);
                v24 = *p_z;
                v32 = (float)((float)(*(p_z - 1) * 100.0) + *(float *)&x) - *(float *)&x;
                v31 = (float)((float)(v23 * 100.0) + *(float *)&z) - *(float *)&z;
                v33 = (float)((float)(v24 * 100.0) + *(float *)&y) - *(float *)&y;
                v42 = (float)((float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33)) != 0.0;
                v39 = 0;
                v38 = 0;
                v37 = 0;
                v40 = 0;
                v41 = 1;
                v36 = 0;
                v35 = 0;
                v34 = 0;
                v30[0] = z;
                v30[1] = x;
                v30[2] = y;
                CTraceFilterSimple::CTraceFilterSimple(
                  this: (CTraceFilterSimple *)&trace.m_pEnt,
                  passedict: nullptr,
                  collisionGroup: 0,
                  pExtraShouldHitFunc: nullptr);
                enginetrace->TraceRay(
                  this: enginetrace,
                  a2: (const Ray_t *)v30,
                  a3: 16395u,
                  a4: (ITraceFilter *)&trace.m_pEnt,
                  a5: (CGameTrace *)&v28);
                if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                  DebugDrawLine(
                    vecAbsStart: &v28,
                    vecAbsEnd: &trace.startpos,
                    r: 255,
                    g: 0,
                    b: 0,
                    test: 1,
                    duration: -1.0);
                if ( trace.plane.normal.z < 1.0 )
                {
                  v25 = (float)((float)((float)(trace.endpos.y * *(float *)&x) + (float)(trace.endpos.x * *(float *)&z))
                              + (float)(trace.endpos.z * *(float *)&y))
                      - trace.plane.normal.x;
                  if ( v25 >= 0.0 )
                  {
                    m_ParticleRadius = this->m_ParticleRadius;
                    if ( m_ParticleRadius > v25 )
                      v12->m_FadeAlpha = (float)((float)((float)(v25 / m_ParticleRadius)
                                                       * (float)(v25 / m_ParticleRadius))
                                               * (float)(v25 / m_ParticleRadius))
                                       * v12->m_FadeAlpha;
                  }
                  else
                  {
                    v12->m_FadeAlpha = 0.0;
                  }
                }
                v48 += 3;
                if ( --v47 == 0 )
                  break;
                p_z = v48;
              }
              v12->m_pParticle = (C_FuncSmokeVolume::SmokeGrenadeParticle *)LODWORD(vPos.x);
              v12->m_TradeIndex = -1;
            }
          }
          if ( ++v49 >= this->m_zCount )
            break;
          v6 = v49;
        }
        v4 = i;
        v5 = j;
      }
      ++v5;
    }
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100731F0
// Name: public: virtual void C_FuncSmokeVolume::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FuncSmokeVolume::Start(
        C_FuncSmokeVolume *this,
        CParticleMgr *pParticleMgr,
        IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( this == (C_FuncSmokeVolume *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    LODWORD(this->m_flFriction) = CParticleEffectBinding::FindOrAddMaterial(
                                    this: (CParticleEffectBinding *)((char *)this - 228),
                                    pMaterialName: (const char *)&this->IClientThinkable);
    C_FuncSmokeVolume::FillVolume(
      this: (C_FuncSmokeVolume *)((char *)this - 2664),
      a2: COERCE_FLOAT(&savedregs),
      a3: (int)this);
    LOBYTE(this->m_vecNetworkOrigin.z) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104123F0
// Name: DT_FuncSmokeVolume::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncSmokeVolume::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FuncSmokeVolume::g_RecvTable);
  return atexit(func: DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412410
// Name: DT_FuncSmokeVolume::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncSmokeVolume::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FuncSmokeVolume::ignored>();
  DT_FuncSmokeVolume::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104303A0
// Name: DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncSmokeVolume::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FuncSmokeVolume::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10072060
// Name: _C_FuncSmokeVolume_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FuncSmokeVolume_CreateObject(int entnum, int serialNum)
{
  C_FuncSmokeVolume *v2; // eax
  C_FuncSmokeVolume *v3; // eax
  C_FuncSmokeVolume *v4; // esi

  v2 = (C_FuncSmokeVolume *)C_BaseEntity::operator new(stAllocateBlock: 0xBF0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FuncSmokeVolume::C_FuncSmokeVolume(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412420
// Name: _dynamic_initializer_for____g_C_FuncTrackTrainClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncTrackTrainClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncTrackTrainClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncTrackTrainClientClass;
  return result;
}
