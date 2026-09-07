// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_smokestack.cpp
// Functions: 19
// ============================================================

#include "game\client\c_smokestack.h"

//------------------------------------------------------------------------------
// Address: 0x1024FBA0
// Name: public: virtual class ClientClass __near * C_SmokeStack::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SmokeStack::GetClientClass(C_SmokeStack *this)
{
  return &__g_C_SmokeStackClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024FE30
// Name: public: virtual C_SmokeStack::~C_SmokeStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::~C_SmokeStack(C_SmokeStack *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SmokeStack_vtbl *)&C_SmokeStack::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SmokeStack::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SmokeStack::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SmokeStack::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SmokeStack::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SmokeStack::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SmokeStack::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024FEA0
// Name: public: virtual void C_SmokeStack::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::OnDataChanged(C_SmokeStack *this, DataUpdateType_t updateType)
{
  int v3; // ebx
  CParticleMgr *v4; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = *(_DWORD *)&this->m_bSimulate;
    v4 = ParticleMgr();
    (*(void (__thiscall **)(bool *, CParticleMgr *, _DWORD))(v3 + 4))(a1: &this->m_bSimulate, a2: v4, a3: 0);
  }
  *(float *)&this->m_bTwist = *(float *)&this->m_Renderer.m_bUsingPixelShaders / this->m_EndSize;
}

//------------------------------------------------------------------------------
// Address: 0x1024FEF0
// Name: public: virtual bool C_SmokeStack::GetPropEditInfo(class RecvTable __near * __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_SmokeStack::GetPropEditInfo(C_SmokeStack *this, RecvTable **ppTable, void **ppObj)
{
  *ppTable = &DT_SmokeStack::g_RecvTable;
  *ppObj = (char *)this - 2664;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1024FF10
// Name: public: virtual void C_SmokeStack::StartRender(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::StartRender(C_SmokeStack *this, VMatrix *effectMatrix)
{
  CParticleSphereRenderer::StartRender(this: (CParticleSphereRenderer *)&this->m_iTeamNum, effectMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1024FF70
// Name: void RenderParticle_Color255SizeNormalAngle(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RenderParticle_Color255SizeNormalAngle(
        ParticleDraw *pDraw,
        const Vector *pos,
        const Vector *color,
        float alpha,
        float size,
        const Vector *vNormal,
        unsigned int angle)
{
  CMeshBuilder *m_pMeshBuilder; // esi
  double v8; // xmm0_8
  float *m_pCurrPosition; // eax
  float v10; // xmm4_4
  double v11; // xmm0_8
  float v12; // xmm1_4
  float v13; // xmm1_4
  float *v14; // ecx
  Vector *m_pCurrNormal; // eax
  float *v16; // eax
  float v17; // xmm1_4
  _DWORD *m_pCurrColor; // ecx
  float *v19; // ecx
  Vector *v20; // eax
  float v21; // xmm1_4
  float *v22; // eax
  _DWORD *v23; // ecx
  float *v24; // ecx
  Vector *v25; // eax
  float v26; // xmm1_4
  float *v27; // eax
  _DWORD *v28; // ecx
  float *v29; // ecx
  Vector *v30; // esi
  float v31; // [esp+0h] [ebp-18h]
  float sa; // [esp+4h] [ebp-14h]
  int z; // [esp+8h] [ebp-10h]
  float v34; // [esp+8h] [ebp-10h]
  int y; // [esp+Ch] [ebp-Ch]
  CVertexBuilder *v36; // [esp+10h] [ebp-8h]
  CVertexBuilder *p_m_VertexBuilder; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]
  int v39; // [esp+14h] [ebp-4h]
  float ca; // [esp+2Ch] [ebp+14h]
  float caa; // [esp+2Ch] [ebp+14h]

  if ( alpha >= 0.5 )
  {
    m_pMeshBuilder = pDraw->m_pMeshBuilder;
    if ( m_pMeshBuilder != nullptr )
    {
      x = (int)color->x;
      y = (int)color->y;
      z = (int)color->z;
      v36 = (CVertexBuilder *)(int)alpha;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)angle));
      *(float *)&v8 = v8;
      ca = *(float *)&v8;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)angle));
      m_pCurrPosition = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v10 = pos->z;
      v12 = v11;
      *(float *)&v11 = (float)((float)(COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) - ca) * size) + pos->y;
      sa = v12;
      v13 = (float)(v12 - ca) * size;
      *m_pCurrPosition = pos->x + v13;
      m_pCurrPosition[1] = *(float *)&v11;
      m_pCurrPosition[2] = v10;
      *(_DWORD *)m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = (unsigned __int8)z
                                                              | (((unsigned __int8)y
                                                                | (((unsigned __int8)x | ((unsigned __int8)v36 << 8)) << 8)) << 8);
      v14 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v39 = (unsigned __int8)z | (((unsigned __int8)y | (((unsigned __int8)x | ((unsigned __int8)v36 << 8)) << 8)) << 8);
      *(float *)&v11 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      v31 = v13;
      m_pCurrNormal = (Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *v14 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v14[1] = *(float *)&v11;
      *m_pCurrNormal = *vNormal;
      p_m_VertexBuilder = &m_pMeshBuilder->m_VertexBuilder;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v16 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v34 = (float)(ca - sa) * size;
      v17 = pos->y + v34;
      *(float *)&v11 = pos->z;
      m_pCurrColor = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v16 = (float)((float)(COERCE_FLOAT(LODWORD(ca) ^ _mask__NegFloat_) - sa) * size) + pos->x;
      v16[1] = v17;
      v16[2] = *(float *)&v11;
      *m_pCurrColor = v39;
      *(float *)&v11 = pDraw->m_pSubTexture->m_tCoordMins[1];
      v19 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v20 = (Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *v19 = pDraw->m_pSubTexture->m_tCoordMins[0];
      v19[1] = *(float *)&v11;
      *v20 = *vNormal;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v21 = pos->z;
      v22 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      v23 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      caa = (float)(sa + ca) * size;
      *(float *)&v11 = caa + pos->y;
      *v22 = pos->x + v34;
      v22[1] = *(float *)&v11;
      v22[2] = v21;
      *v23 = v39;
      *(float *)&v11 = pDraw->m_pSubTexture->m_tCoordMins[1];
      v24 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v25 = (Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      *v24 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v24[1] = *(float *)&v11;
      *v25 = *vNormal;
      CVertexBuilder::AdvanceVertex(this: &m_pMeshBuilder->m_VertexBuilder);
      v26 = pos->z;
      v27 = m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
      *(float *)&v11 = pos->y + v31;
      v28 = m_pMeshBuilder->m_VertexBuilder.m_pCurrColor;
      *v27 = pos->x + caa;
      v27[1] = *(float *)&v11;
      v27[2] = v26;
      *v28 = v39;
      *(float *)&v11 = pDraw->m_pSubTexture->m_tCoordMaxs[1];
      v29 = m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v29 = pDraw->m_pSubTexture->m_tCoordMaxs[0];
      v30 = (Vector *)m_pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
      v29[1] = *(float *)&v11;
      *v30 = *vNormal;
      CVertexBuilder::AdvanceVertex(this: p_m_VertexBuilder);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250250
// Name: public: void CParticleSphereRenderer::RenderParticle(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSphereRenderer::RenderParticle(
        CParticleSphereRenderer *this,
        ParticleDraw *pDraw,
        const Vector *vOriginalPos,
        const Vector *vTransformedPos,
        float flAlpha,
        float flParticleSize,
        unsigned int flAngle)
{
  float m_flIntensity; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float x; // xmm5_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  Vector vColor; // [esp+10h] [ebp-Ch] BYREF

  m_flIntensity = this->m_AmbientLight.m_flIntensity;
  vColor = this->m_vBaseColor;
  if ( m_flIntensity == 0.0 )
  {
    z = vColor.z;
    y = vColor.y;
    x = vColor.x;
  }
  else
  {
    v8 = (float)((float)((float)(vOriginalPos->y - this->m_AmbientLight.m_vPos.y)
                       * (float)(vOriginalPos->y - this->m_AmbientLight.m_vPos.y))
               + (float)((float)(vOriginalPos->x - this->m_AmbientLight.m_vPos.x)
                       * (float)(vOriginalPos->x - this->m_AmbientLight.m_vPos.x)))
       + (float)((float)(vOriginalPos->z - this->m_AmbientLight.m_vPos.z)
               * (float)(vOriginalPos->z - this->m_AmbientLight.m_vPos.z));
    if ( v8 <= 0.000099999997 )
      v9 = 1000.0;
    else
      v9 = m_flIntensity / v8;
    x = (float)(this->m_AmbientLight.m_vColor.x * v9) + vColor.x;
    y = vColor.y + (float)(this->m_AmbientLight.m_vColor.y * v9);
    z = vColor.z + (float)(this->m_AmbientLight.m_vColor.z * v9);
  }
  if ( !this->m_bUsingPixelShaders )
  {
    v13 = this->m_DirectionalLight.m_flIntensity;
    if ( v13 != 0.0 )
    {
      v14 = (float)((float)((float)(vOriginalPos->y - this->m_DirectionalLight.m_vPos.y)
                          * (float)(vOriginalPos->y - this->m_DirectionalLight.m_vPos.y))
                  + (float)((float)(vOriginalPos->x - this->m_DirectionalLight.m_vPos.x)
                          * (float)(vOriginalPos->x - this->m_DirectionalLight.m_vPos.x)))
          + (float)((float)(vOriginalPos->z - this->m_DirectionalLight.m_vPos.z)
                  * (float)(vOriginalPos->z - this->m_DirectionalLight.m_vPos.z));
      if ( v14 <= 0.000099999997 )
        v15 = 1000.0;
      else
        v15 = v13 / v14;
      x = (float)(this->m_DirectionalLight.m_vColor.x * v15) + x;
      y = (float)(this->m_DirectionalLight.m_vColor.y * v15) + y;
      z = z + (float)(this->m_DirectionalLight.m_vColor.z * v15);
    }
  }
  if ( y <= z )
    v16 = z;
  else
    v16 = y;
  if ( x <= v16 )
  {
    if ( y <= z )
      v17 = z;
    else
      v17 = y;
  }
  else
  {
    v17 = x;
  }
  v18 = 255.0;
  if ( v17 <= 1.0 )
  {
    vColor.x = x * 255.0;
  }
  else
  {
    v18 = 255.0 / v17;
    vColor.x = (float)(255.0 / v17) * x;
  }
  vColor.y = y * v18;
  vColor.z = z * v18;
  RenderParticle_Color255SizeNormalAngle(
    pDraw,
    pos: vTransformedPos,
    color: &vColor,
    alpha: flAlpha,
    size: flParticleSize,
    vNormal: &vec3_origin,
    angle: flAngle);
}

//------------------------------------------------------------------------------
// Address: 0x10250440
// Name: public: virtual void C_SmokeStack::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::ClientThink(C_SmokeStack *this)
{
  *(_DWORD *)&this->m_ParticleEffect.m_ListIndex &= ~0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x10250450
// Name: private: void C_SmokeStack::QueueLightParametersInRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::QueueLightParametersInRenderer(C_SmokeStack *this)
{
  int b; // edx
  float g; // xmm1_4

  b = this->m_clrRender.m_Value.b;
  g = (float)this->m_clrRender.m_Value.g;
  this->m_Renderer.m_vBaseColor.x = (float)this->m_clrRender.m_Value.r * 0.0039215689;
  this->m_Renderer.m_vBaseColor.y = g * 0.0039215689;
  this->m_Renderer.m_vBaseColor.z = (float)b * 0.0039215689;
  this->m_Renderer.m_AmbientLight = this->m_AmbientLight;
  this->m_Renderer.m_DirectionalLight = this->m_DirLight;
  this->m_flAlphaScale = (float)C_BaseEntity::GetRenderAlpha(this);
}

//------------------------------------------------------------------------------
// Address: 0x10250570
// Name: public: virtual void C_SmokeStack::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::RenderParticles(C_SmokeStack *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  const Vector *i; // esi
  float *v7; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  Vector tPos; // [esp+18h] [ebp-Ch] BYREF
  float pIteratora; // [esp+2Ch] [ebp+8h]

  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = (const Vector *)pIterator->m_pCur;
          i != nullptr;
          i = (const Vector *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: i[5].x) )
    {
      v7 = *(float **)&this->m_iName[136];
      x = i[1].x;
      y = i[1].y;
      z = i[1].z;
      v11 = v7[30];
      tPos.x = (float)((float)((float)(v7[26] * y) + (float)(x * v7[25])) + (float)(v7[27] * z)) + v7[28];
      tPos.y = (float)((float)((float)(v7[29] * x) + (float)(v11 * y)) + (float)(v7[31] * z)) + v7[32];
      v12 = (float)((float)(v7[33] * x) + (float)(v7[34] * y)) + (float)(v7[35] * z);
      v13 = i[4].x * *(float *)&this->m_iName[132];
      pIteratora = (float)((float)((float)((float)(v13 * 3.1415927) * 2.0) * 40.743664) - 128.0) + 12582976.0;
      v14 = SinCosTable[LOBYTE(pIteratora)];
      tPos.z = v12 + v7[36];
      v15 = (float)(v14 + 1.0) * 0.5;
      if ( v13 > 0.5 )
        v15 = v15 * v15;
      CParticleSphereRenderer::RenderParticle(
        this: (CParticleSphereRenderer *)&this->m_iTeamNum,
        pDraw: pIterator->m_pParticleDraw,
        vOriginalPos: i + 1,
        vTransformedPos: &tPos,
        flAlpha: *(float *)&this->m_iName[128] * v15,
        flParticleSize: (float)((float)(*(float *)this->m_iName - *(float *)&this->m_hGroundEntity.m_Index) * v13)
      + *(float *)&this->m_hGroundEntity.m_Index,
        flAngle: i[4].y * 0.017453292);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250760
// Name: public: virtual void C_SmokeStack::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::SimulateParticles(C_SmokeStack *this, CParticleSimulateIterator *pIterator)
{
  float z; // eax
  CParticleSimulateIterator *v4; // edi
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  Particle *v7; // xmm0_4
  float m_flTimeDelta; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float vTwist; // [esp+4h] [ebp-18h]
  float vTwist_4; // [esp+8h] [ebp-14h]
  float y; // [esp+10h] [ebp-Ch]
  float x; // [esp+14h] [ebp-8h]
  char bDrawn; // [esp+1Bh] [ebp-1h]

  z = this->m_vecAbsVelocity.z;
  bDrawn = (LOBYTE(z) & 0x40) != 0;
  if ( *(_DWORD *)&this->m_iName[12] == 0 || (LOBYTE(z) & 0x50) != 0 )
  {
    v4 = pIterator;
    m_pMaterial = pIterator->m_pMaterial;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    if ( m_pNext != &m_pMaterial->m_Particles )
    {
      pIterator->m_pNextParticle = m_pNext->m_pNext;
      while ( 1 )
      {
        *(float *)&v7 = v4->m_flTimeDelta + *(float *)&m_pNext[2].m_pPrev;
        m_pNext[2].m_pPrev = v7;
        if ( (float)(*(float *)&v7 * *(float *)&this->m_iName[132]) < 1.0 )
        {
          if ( *(_DWORD *)&this->m_iName[124] != 0 )
          {
            x = m_pNext->m_Pos.x;
            vTwist = x
                   - *(float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
            y = m_pNext->m_Pos.y;
            vTwist_4 = y
                     - *(float *)((*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432)
                                + 4);
            m_pNext->m_Pos.x = (float)((float)(*(float *)&this->m_iName[112] * vTwist_4)
                                     + (float)(*(float *)&this->m_iName[108] * vTwist))
                             + *(float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
            v4 = pIterator;
            m_pNext->m_Pos.y = (float)((float)(*(float *)&this->m_iName[120] * vTwist_4)
                                     + (float)(*(float *)&this->m_iName[116] * vTwist))
                             + *(float *)((*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432)
                                        + 4);
          }
          m_flTimeDelta = v4->m_flTimeDelta;
          v9 = (float)(m_flTimeDelta * 0.5) * m_flTimeDelta;
          v10 = m_pNext[1].m_Pos.y * v9;
          v11 = m_pNext[1].m_Pos.z * v9;
          v12 = (float)((float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta) + m_pNext->m_Pos.x)
              + (float)(m_pNext[1].m_Pos.x * v9);
          v13 = *(float *)&m_pNext[1].m_pSubTexture * m_flTimeDelta;
          v14 = m_pNext->m_Pos.y + (float)(*(float *)&m_pNext[1].m_pNext * m_flTimeDelta);
          v15 = m_pNext->m_Pos.z;
          m_pNext->m_Pos.x = v12;
          m_pNext->m_Pos.y = v14 + v10;
          m_pNext->m_Pos.z = (float)(v15 + v13) + v11;
          v16 = v4->m_flTimeDelta;
          v17 = m_pNext[1].m_Pos.y * v16;
          v18 = m_pNext[1].m_Pos.z * v16;
          *(float *)&m_pNext[1].m_pPrev = *(float *)&m_pNext[1].m_pPrev + (float)(m_pNext[1].m_Pos.x * v16);
          *(float *)&m_pNext[1].m_pNext = *(float *)&m_pNext[1].m_pNext + v17;
          *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture + v18;
          *(float *)&m_pNext[2].m_pNext = (float)(*(float *)&m_pNext[2].m_pSubTexture * v4->m_flTimeDelta)
                                        + *(float *)&m_pNext[2].m_pNext;
          m_pNext[2].m_Pos.x = (float)((float)((float)(*(float *)(*(_DWORD *)&this->m_iName[136] + 136)
                                                     * m_pNext->m_Pos.y)
                                             + (float)(*(float *)(*(_DWORD *)&this->m_iName[136] + 132)
                                                     * m_pNext->m_Pos.x))
                                     + (float)(*(float *)(*(_DWORD *)&this->m_iName[136] + 140) * m_pNext->m_Pos.z))
                             + *(float *)(*(_DWORD *)&this->m_iName[136] + 144);
        }
        else
        {
          CParticleEffectBinding::RemoveParticle(this: v4->m_pEffectBinding, pParticle: m_pNext);
        }
        m_pNext = v4->m_pNextParticle;
        if ( m_pNext == &v4->m_pMaterial->m_Particles )
          break;
        v4->m_pNextParticle = m_pNext->m_pNext;
      }
    }
    this->m_iName[156] = bDrawn;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250A00
// Name: public: virtual void C_SmokeStack::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeStack::Start(C_SmokeStack *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  char *v5; // edi
  const struct model_t *v6; // eax
  char *v7; // eax
  const char *v8; // ecx
  char *v9; // eax
  CParticleSubTexture *v10; // eax
  int v11; // xmm0_4
  IMaterial *v12; // eax
  CParticleSubTexture *m_iTeamNum; // [esp+8h] [ebp-210h]
  char str[512]; // [esp+18h] [ebp-200h] BYREF

  if ( this == (C_SmokeStack *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  v5 = (char *)this - 228;
  CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4);
  strcpy(str, "unset_material");
  memset(dst: (int)&str[15], value: nullptr, count: 0x1F1u);
  v6 = modelinfo->GetModel(this: modelinfo, a2: LODWORD(this->m_angAbsRotation.z));
  if ( v6 != nullptr )
  {
    v7 = (char *)modelinfo->GetModelName(this: modelinfo, a2: v6);
    V_strncpy(pDest: str, pSrc: v7, maxLen: 512);
    v9 = V_stristr(a1: v8, a2: (const char *)pParticleMgr, pStr: str, pSearch: ".vmt");
    if ( v9 != nullptr )
      *v9 = 0;
  }
  v10 = CParticleEffectBinding::FindOrAddMaterial(
          this: (CParticleEffectBinding *)((char *)this - 228),
          pMaterialName: str);
  *(float *)&v11 = 1.0 / *(float *)&this->m_EntClientFlags;
  this->m_iTeamNum = (int)v10;
  this->m_nNextThinkTick = v11;
  this->m_iHealth = 0;
  m_iTeamNum = (CParticleSubTexture *)this->m_iTeamNum;
  *(float *)&this->m_nWaterType = *((float *)&this->m_pfnTouch + 2) / *(float *)&this->model;
  this->m_fEffects = (int)pParticleMgr;
  v12 = CParticleMgr::PMaterialToIMaterial(this: pParticleMgr, a2: (int)pParticleMgr, hMaterial: m_iTeamNum);
  if ( v12 != nullptr )
    CParticleSphereRenderer::Init(
      this: (CParticleSphereRenderer *)&this->IClientRenderable,
      pParticleMgr,
      pMaterial: v12);
  C_SmokeStack::QueueLightParametersInRenderer(this: (C_SmokeStack *)((char *)this - 2664));
  *((_DWORD *)v5 + 37) |= 0x10u;
  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 666) + 456))(
    a1: (char *)this - 2664,
    a2: *(float *)(gpGlobals.m_Index + 12) + 5.0);
}

//------------------------------------------------------------------------------
// Address: 0x10250B90
// Name: public: virtual void C_SmokeStack::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_SmokeStack::Update(C_SmokeStack *this@<ecx>, Particle *a2@<esi>, float fTimeDelta)
{
  const QAngle *v4; // eax
  float v6; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  IUniformRandomStream *v8; // ecx
  double v9; // xmm0_8
  int (__thiscall *v10)(char *); // eax
  double v11; // xmm0_8
  float *v12; // eax
  float v13; // xmm2_4
  IUniformRandomStream *v14; // ecx
  double v15; // st7
  float v16; // xmm1_4
  IUniformRandomStream *v17; // ecx
  float y; // xmm1_4
  float z; // xmm2_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v21; // st7
  double v22; // xmm0_8
  double v23; // xmm0_8
  int v24; // [esp+Ch] [ebp-68h]
  Vector up; // [esp+18h] [ebp-5Ch] BYREF
  float v26; // [esp+24h] [ebp-50h]
  float v27; // [esp+28h] [ebp-4Ch]
  float v28; // [esp+2Ch] [ebp-48h]
  float v29; // [esp+30h] [ebp-44h]
  float v30; // [esp+34h] [ebp-40h]
  float v31; // [esp+38h] [ebp-3Ch]
  float v32; // [esp+3Ch] [ebp-38h]
  float v33; // [esp+40h] [ebp-34h]
  float v34; // [esp+44h] [ebp-30h]
  float v35; // [esp+48h] [ebp-2Ch]
  float v36; // [esp+4Ch] [ebp-28h]
  float v37; // [esp+50h] [ebp-24h]
  Vector right; // [esp+54h] [ebp-20h] BYREF
  Vector forward; // [esp+60h] [ebp-14h] BYREF
  float tempDelta; // [esp+6Ch] [ebp-8h]
  float v41; // [esp+70h] [ebp-4h]
  float anglea; // [esp+7Ch] [ebp+8h]
  float angleb; // [esp+7Ch] [ebp+8h]
  float angle; // [esp+7Ch] [ebp+8h]

  if ( *(_DWORD *)&this->m_iName[136] != 0 )
  {
    if ( *(_DWORD *)&this->m_iName[12] != 0 && (LOBYTE(this->m_vecAbsVelocity.z) & 0x50) != 0 )
    {
      v4 = (const QAngle *)(*(int (**)(void))(*((_DWORD *)this - 608) + 44))();
      AngleVectors(angles: v4, &forward, &right, &up);
      while ( 1 )
      {
        v6 = *(float *)&this->m_iName[148];
        if ( fTimeDelta < v6 )
          break;
        *(float *)&this->m_iName[148] = *(float *)&this->m_iName[144];
        RandomInt = random->RandomInt;
        v24 = *(_DWORD *)&this->m_iName[152];
        tempDelta = fTimeDelta - v6;
        RandomInt(this: random, a2: 0, a3: v24);
        a2 = CParticleEffectBinding::AddParticle(
               this: (CParticleEffectBinding *)&this->IClientRenderable,
               (int)a2,
               sizeInBytes: 64,
               hMaterial: *(CParticleSubTexture **)&this->m_iName[140]);
        if ( a2 != nullptr )
        {
          anglea = _RandomFloat(this: v8, a2: 0.0, a3: 6.2831855);
          v41 = *(float *)&this->m_iName[16];
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(anglea)));
          *(float *)&v9 = v9;
          *(float *)&v9 = *(float *)&v9 * v41;
          v32 = forward.x * *(float *)&v9;
          v33 = forward.y * *(float *)&v9;
          v34 = forward.z * *(float *)&v9;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(anglea)));
          v10 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
          *(float *)&v11 = v11;
          *(float *)&v11 = *(float *)&v11 * v41;
          v35 = right.x * *(float *)&v11;
          v36 = right.y * *(float *)&v11;
          v37 = right.z * *(float *)&v11;
          v12 = (float *)v10(a1: (char *)this - 2432);
          *(float *)&v11 = (float)(*v12 + v35) + v32;
          v13 = (float)(v12[2] + v37) + v34;
          a2->m_Pos.y = (float)(v12[1] + v36) + v33;
          a2->m_Pos.x = *(float *)&v11;
          a2->m_Pos.z = v13;
          LODWORD(v11) = this->m_hOwnerEntity.m_Index;
          v26 = up.x * *(float *)&v11;
          v27 = up.y * *(float *)&v11;
          v28 = up.z * *(float *)&v11;
          v15 = _RandomFloat(
                  this: v14,
                  a2: COERCE_FLOAT(this->m_hNetworkMoveParent.m_Index ^ _mask__NegFloat_),
                  a3: *(float *)&this->m_hNetworkMoveParent.m_Index);
          v16 = *(float *)&this->m_hNetworkMoveParent.m_Index;
          v29 = forward.x * v15;
          v30 = forward.y * v15;
          v31 = v15 * forward.z;
          angleb = _RandomFloat(this: v17, a2: COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_), a3: v16);
          y = right.y;
          z = right.z;
          *(float *)&a2[1].m_pPrev = (float)((float)(angleb * right.x) + v29) + v26;
          *(float *)&a2[1].m_pNext = (float)((float)(y * angleb) + v30) + v27;
          *(float *)&a2[1].m_pSubTexture = (float)((float)(z * angleb) + v31) + v28;
          a2[1].m_Pos.x = *(float *)&this->m_iName[88];
          a2[1].m_Pos.y = *(float *)&this->m_iName[92];
          a2[1].m_Pos.z = *(float *)&this->m_iName[96];
          a2[2].m_pPrev = nullptr;
          a2[2].m_pNext = nullptr;
          RandomFloat = random->RandomFloat;
          up.y = *(float *)&this->m_iName[160];
          LODWORD(up.x) = LODWORD(up.y) ^ _mask__NegFloat_;
          *(float *)&a2[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *))RandomFloat)(a1: random);
          a2[2].m_Pos.x = a2->m_Pos.z;
        }
        fTimeDelta = tempDelta;
      }
      *(float *)&this->m_iName[148] = *(float *)&this->m_iName[148] - fTimeDelta;
    }
    v21 = Helper_GetFrameTime() * (*(float *)&this->m_iName[100] * 6.2831855 * 0.0027777778);
    angle = v21;
    *(_DWORD *)&this->m_iName[124] = v21 != 0.0;
    if ( v21 != 0.0 )
    {
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(angle)));
      *(float *)&v22 = v22;
      tempDelta = *(float *)&v22;
      *(_DWORD *)&this->m_iName[108] = LODWORD(v22);
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(angle)));
      *(float *)&v23 = v23;
      *(_DWORD *)&this->m_iName[112] = LODWORD(v23);
      *(_DWORD *)&this->m_iName[116] = LODWORD(v23) ^ _mask__NegFloat_;
      *(float *)&this->m_iName[120] = tempDelta;
    }
    C_SmokeStack::QueueLightParametersInRenderer(this: (C_SmokeStack *)((char *)this - 2432));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250F40
// Name: public: C_SmokeStack::C_SmokeStack(void)
// Source: json
//------------------------------------------------------------------------------
C_SmokeStack *__thiscall C_SmokeStack::C_SmokeStack(C_SmokeStack *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SmokeStack_vtbl *)&C_SmokeStack::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SmokeStack::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SmokeStack::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SmokeStack::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SmokeStack::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SmokeStack::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SmokeStack::`vftable';
  CParticleSphereRenderer::CParticleSphereRenderer(this: &this->m_Renderer);
  this->m_ParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  this->m_SpreadSpeed = 15.0;
  this->m_EndSize = 15.0;
  this->m_Rate = 80.0;
  this->m_Speed = 30.0;
  this->m_JetLength = 180.0;
  this->m_pParticleMgr = nullptr;
  this->m_MaterialHandle[0] = nullptr;
  this->m_iMaterialModel = -1;
  this->m_StartSize = 10.0;
  this->m_bEmit = 1;
  this->m_flBaseSpread = 20.0;
  this->m_bInView = false;
  if ( this->m_clrRender.m_Value.r != 0 )
    this->m_clrRender.m_Value.r = 0;
  if ( this->m_clrRender.m_Value.g != 0 )
    this->m_clrRender.m_Value.g = 0;
  if ( this->m_clrRender.m_Value.b != 0 )
    this->m_clrRender.m_Value.b = 0;
  C_BaseEntity::SetRenderAlpha(this, a: 255);
  this->m_AmbientLight.m_vPos.z = -100.0;
  this->m_AmbientLight.m_vPos.x = 0.0;
  this->m_AmbientLight.m_vPos.y = 0.0;
  this->m_AmbientLight.m_vColor.x = 40.0;
  this->m_AmbientLight.m_vColor.y = 40.0;
  this->m_AmbientLight.m_vColor.z = 40.0;
  this->m_AmbientLight.m_flIntensity = 8000.0;
  this->m_DirLight.m_vColor.x = 255.0;
  this->m_DirLight.m_vColor.y = 128.0;
  this->m_DirLight.m_vColor.z = 0.0;
  this->m_vWind.x = 0.0;
  this->m_vWind.y = 0.0;
  this->m_vWind.z = 0.0;
  this->m_flTwist = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042AE70
// Name: DT_SmokeStack::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeStack::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SmokeStack::g_RecvTable);
  return atexit(func: DT_SmokeStack::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AE90
// Name: DT_SmokeStack::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeStack::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SmokeStack::ignored>();
  DT_SmokeStack::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104366D0
// Name: DT_SmokeStack::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeStack::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SmokeStack::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10251110
// Name: _C_SmokeStack_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SmokeStack_CreateObject(int entnum, int serialNum)
{
  C_SmokeStack *v2; // eax
  C_SmokeStack *v3; // eax
  C_SmokeStack *v4; // esi

  v2 = (C_SmokeStack *)C_BaseEntity::operator new(stAllocateBlock: 0xB70u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SmokeStack::C_SmokeStack(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AEA0
// Name: _dynamic_initializer_for____g_C_SteamJetClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SteamJetClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SteamJetClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SteamJetClientClass;
  return result;
}
