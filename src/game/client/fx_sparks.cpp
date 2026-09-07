// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_sparks.cpp
// Functions: 17
// ============================================================

#include "game\client\fx_sparks.h"

//------------------------------------------------------------------------------
// Address: 0x1026B810
// Name: public: virtual void PrecacheEffectSparksPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectSparksPrecache::CResourcePrecacher::Cache(
        PrecacheEffectSparksPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/spark",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/energysplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/energyball",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/rico1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/rico1_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/blueflare1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/yellowflare",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/combinemuzzle1_nocull",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/combinemuzzle2_nocull",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/yellowflare_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1026B8F0
// Name: public: CTrailParticles::CTrailParticles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTrailParticles *__thiscall CTrailParticles::CTrailParticles(CTrailParticles *this, const char *pDebugName)
{
  CSimpleEmitter::CSimpleEmitter(this, pDebugName);
  this->__vftable = (CTrailParticles_vtbl *)&CTrailParticles::`vftable';
  CParticleCollision::CParticleCollision(this: &this->m_ParticleCollision);
  this->m_fFlags = 0;
  this->m_flVelocityDampen = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1026B930
// Name: public: virtual void CTrailParticles::Setup(class Vector const __near &,class Vector const __near *,float,float,float,float,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTrailParticles::Setup(
        CTrailParticles *this,
        const Vector *origin,
        const Vector *direction,
        float angularSpread,
        float minSpeed,
        float maxSpeed,
        float gravity,
        float dampen,
        int flags,
        bool bNotCollideable)
{
  if ( bNotCollideable )
    this->m_fFlags |= flags;
  else
    this->m_fFlags |= flags | 2;
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
// Address: 0x1026B9E0
// Name: public: virtual void CSimpleGlowEmitter::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleGlowEmitter::SimulateParticles(CSimpleGlowEmitter *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  CEffectMaterial *m_pNext; // eax
  bool i; // zf

  if ( *(float *)(gpGlobals.m_Index + 12) <= this->m_flDeathTime )
  {
    if ( (this->m_wasTested & 1) != 0 )
      CSimpleEmitter::SimulateParticles((CLocalSpaceEmitter *)this, pIterator);
  }
  else
  {
    m_pMaterial = pIterator->m_pMaterial;
    m_pNext = (CEffectMaterial *)m_pMaterial->m_Particles.m_pNext;
    for ( i = m_pNext == (CEffectMaterial *)&m_pMaterial->m_Particles;
          !i;
          i = m_pNext == (CEffectMaterial *)&pIterator->m_pMaterial->m_Particles )
    {
      pIterator->m_pNextParticle = m_pNext->m_Particles.m_pPrev;
      CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: (Particle *)m_pNext);
      m_pNext = (CEffectMaterial *)pIterator->m_pNextParticle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026BA40
// Name: public: virtual void CSimpleGlowEmitter::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleGlowEmitter::RenderParticles(CSimpleGlowEmitter *this, CParticleRenderIterator *pIterator)
{
  view_id_t v3; // eax
  unsigned __int8 v4; // bl
  view_id_t v5; // eax
  char v6; // di
  const Vector *(__thiscall *GetSortOrigin)(struct CSimpleGlowEmitter *); // eax
  char v8; // al
  pixelvis_queryparams_t params; // [esp+Ch] [ebp-1Ch] BYREF

  v3 = CurrentViewID();
  if ( v3 >= VIEW_MAIN )
  {
    if ( v3 > VIEW_SHADOW_DEPTH_TEXTURE )
      LOBYTE(v3) = 7;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  v4 = 1 << v3;
  v5 = CurrentViewID();
  if ( v5 >= VIEW_MAIN )
  {
    v6 = 7;
    if ( v5 <= VIEW_SHADOW_DEPTH_TEXTURE )
      v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( ((unsigned __int8)(1 << v6) & this->m_wasTested) == 0 )
  {
    GetSortOrigin = this->GetSortOrigin;
    params.bSetup = false;
    params.position = *GetSortOrigin(this);
    params.proxySize = 2.0;
    params.proxyAspect = 1.0;
    params.fadeTime = 0.0625;
    *(_WORD *)&params.bSetup = 1;
    if ( PixelVisibility_FractionVisible(&params, queryHandle: &this->m_queryHandle) == 0.0 )
    {
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_startTime) <= 0.1 )
        return;
      v8 = ~v4;
      this->m_isVisible &= ~v4;
    }
    else
    {
      v8 = ~v4;
      this->m_isVisible = v4 | this->m_isVisible & ~v4;
    }
    this->m_wasTested = v4 | this->m_wasTested & v8;
  }
  if ( (v4 & this->m_isVisible) != 0 )
    CSimpleEmitter::RenderParticles(this, pIterator);
}

//------------------------------------------------------------------------------
// Address: 0x1026BB80
// Name: bool EffectOccluded(class Vector const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EffectOccluded(const Vector *pos, int *queryHandle)
{
  const Vector *v2; // eax
  CGameTrace tr; // [esp+0h] [ebp-70h] BYREF
  pixelvis_queryparams_t params; // [esp+54h] [ebp-1Ch] BYREF

  if ( queryHandle != nullptr )
  {
    params.position = *pos;
    params.proxySize = 2.0;
    params.proxyAspect = 1.0;
    params.fadeTime = 0.0625;
    *(_WORD *)&params.bSetup = 1;
    if ( PixelVisibility_FractionVisible(&params, queryHandle) > 0.0 )
      return 0;
  }
  else
  {
    v2 = MainViewOrigin(nSlot: 0);
    UTIL_TraceLine(vecAbsStart: pos, vecAbsEnd: v2, mask: 0x4081u, ignore: nullptr, collisionGroup: 0, ptr: &tr);
    if ( tr.fraction >= 1.0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026BC30
// Name: public: virtual void CTrailParticles::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTrailParticles::RenderParticles(
        CTrailParticles *this@<ecx>,
        float a2@<ebp>,
        CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // edx
  Particle *m_pNext; // eax
  Particle *i; // esi
  CParticleMgr *v6; // eax
  CParticleMgr *v7; // eax
  float z; // xmm1_4
  float v9; // xmm0_4
  float width; // xmm0_4
  float v11; // [esp+20h] [ebp-5Ch]
  float v12[3]; // [esp+30h] [ebp-4Ch] BYREF
  float color[4]; // [esp+3Ch] [ebp-40h] BYREF
  Vector start; // [esp+4Ch] [ebp-30h] BYREF
  Vector v15; // [esp+58h] [ebp-24h] BYREF
  Vector delta; // [esp+64h] [ebp-18h]
  float sortKey; // [esp+70h] [ebp-Ch]
  float scale; // [esp+74h] [ebp-8h]
  float retaddr; // [esp+7Ch] [ebp+0h]

  sortKey = a2;
  scale = retaddr;
  LODWORD(delta.z) = this;
  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur;
          i != nullptr;
          i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: delta.x) )
    {
      delta.y = (float)(1.0 - (float)(i[1].m_Pos.z / i[1].m_Pos.y)) * *(float *)&i[2].m_pPrev;
      if ( delta.y < 0.0099999998 )
        delta.y = 0.0099999998;
      v6 = ParticleMgr();
      color[1] = (float)((float)((float)(v6->m_mModelView.m[0][1] * i->m_Pos.y)
                               + (float)(i->m_Pos.x * v6->m_mModelView.m[0][0]))
                       + (float)(v6->m_mModelView.m[0][2] * i->m_Pos.z))
               + v6->m_mModelView.m[0][3];
      color[2] = (float)((float)((float)(v6->m_mModelView.m[1][0] * i->m_Pos.x)
                               + (float)(v6->m_mModelView.m[1][1] * i->m_Pos.y))
                       + (float)(v6->m_mModelView.m[1][2] * i->m_Pos.z))
               + v6->m_mModelView.m[1][3];
      color[3] = (float)((float)((float)(v6->m_mModelView.m[2][0] * i->m_Pos.x)
                               + (float)(v6->m_mModelView.m[2][1] * i->m_Pos.y))
                       + (float)(v6->m_mModelView.m[2][2] * i->m_Pos.z))
               + v6->m_mModelView.m[2][3];
      delta.x = color[3];
      v7 = ParticleMgr();
      Vector3DMultiply(src1: &v7->m_mModelView, src2: (const Vector *)&i[1], dst: &v15);
      z = i[1].m_Pos.z;
      v9 = 1.0;
      if ( z <= 0.3 && (*(_BYTE *)(LODWORD(delta.z) + 380) & 8) != 0 )
      {
        v9 = i[1].m_Pos.z;
      }
      else if ( (*(_BYTE *)(LODWORD(delta.z) + 380) & 4) != 0 )
      {
        v9 = 1.0 - (float)(z / i[1].m_Pos.y);
      }
      v12[0] = (float)((float)LOBYTE(i[1].m_Pos.x) * v9) * 0.0039215689;
      v12[1] = (float)((float)BYTE1(i[1].m_Pos.x) * v9) * 0.0039215689;
      v12[2] = (float)((float)BYTE2(i[1].m_Pos.x) * v9) * 0.0039215689;
      color[0] = (float)((float)HIBYTE(i[1].m_Pos.x) * v9) * 0.0039215689;
      v11 = fsqrt(
              (float)((float)((float)(*(float *)&i[1].m_pNext * delta.y) * (float)(*(float *)&i[1].m_pNext * delta.y))
                    + (float)((float)(*(float *)&i[1].m_pSubTexture * delta.y)
                            * (float)(*(float *)&i[1].m_pSubTexture * delta.y)))
            + (float)((float)(*(float *)&i[1].m_pPrev * delta.y) * (float)(*(float *)&i[1].m_pPrev * delta.y)));
      width = *(float *)&i[2].m_pNext;
      if ( width > v11 )
        width = v11;
      start.x = v15.x * delta.y;
      start.y = v15.y * delta.y;
      start.z = v15.z * delta.y;
      Tracer_Draw(
        pDraw: pIterator->m_pParticleDraw,
        start: (const Vector *)&color[1],
        delta: &start,
        width,
        color: v12,
        startV: 0.0,
        endV: 1.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026BF00
// Name: public: virtual void CTrailParticles::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTrailParticles::SimulateParticles(CTrailParticles *this, CParticleSimulateIterator *pIterator)
{
  bool v2; // zf
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float v6; // xmm0_4
  float v7; // xmm0_4
  bool v8; // cf
  CGameTrace trace; // [esp+14h] [ebp-58h] BYREF
  CTrailParticles *v10; // [esp+68h] [ebp-4h]
  float timeDelta; // [esp+74h] [ebp+8h]

  v2 = (this->m_fFlags & 2) == 0;
  v10 = this;
  if ( v2 )
    CBaseSimpleCollision::ClearActivePlanes(this: &this->m_ParticleCollision);
  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      timeDelta = pIterator->m_flTimeDelta;
      ((void (__stdcall *)(Vector *, Particle *, _DWORD, float, CGameTrace *))v10->m_ParticleCollision.MoveParticle)(
        a1: &m_pNext->m_Pos,
        a2: &m_pNext[1],
        a3: 0,
        a4: COERCE_FLOAT(LODWORD(timeDelta)),
        a5: &trace);
      if ( (v10->m_fFlags & 1) != 0 )
      {
        v6 = 1.0 - (float)(v10->m_flVelocityDampen * timeDelta);
        if ( v6 < 0.0 )
          v6 = 0.0;
        *(float *)&m_pNext[1].m_pPrev = *(float *)&m_pNext[1].m_pPrev * v6;
        *(float *)&m_pNext[1].m_pNext = *(float *)&m_pNext[1].m_pNext * v6;
        *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture * v6;
      }
      v7 = m_pNext[1].m_Pos.z + timeDelta;
      v8 = v7 < m_pNext[1].m_Pos.y;
      m_pNext[1].m_Pos.z = v7;
      if ( !v8 )
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026C010
// Name: void FX_ElectricSpark(class Vector const __near &,int,int,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_ElectricSpark(const Vector *pos, int nMagnitude, int nTrailLength, const Vector *vecDir)
{
  int v4; // ebx
  CSimpleEmitter *v5; // eax
  CParticleEffect *v6; // esi
  double v7; // st7
  Particle *v8; // eax
  Particle *v9; // esi
  IUniformRandomStream *v10; // ecx
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  Particle *v15; // xmm1_4
  CParticleSubTexture *v16; // xmm2_4
  CSimpleEmitter *v17; // eax
  CSimpleEmitter *v18; // ebx
  CParticleEffect *v19; // esi
  Particle *v20; // eax
  IUniformRandomStream *v21; // ecx
  Particle *v22; // esi
  IUniformRandomStream *v23; // ecx
  IUniformRandomStream *v24; // ecx
  int v25; // eax
  Particle *v26; // xmm1_4
  CParticleSubTexture *v27; // xmm2_4
  CSimpleEmitter *v28; // eax
  CSimpleEmitter *v29; // ebx
  float v30; // xmm0_4
  double v31; // st7
  CParticleEffect *v32; // ebx
  CParticleSubTexture *PMaterial; // eax
  Particle *v34; // eax
  Particle *v35; // esi
  CParticleSubTexture *v36; // eax
  Particle *v37; // eax
  Particle *v38; // esi
  int v39; // eax
  double v40; // st7
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v42; // st7
  float z; // xmm0_4
  Particle *v44; // eax
  Particle *v45; // esi
  unsigned __int8 v46; // al
  CParticleEffect *v47; // ecx
  CParticleEffect *v48; // ecx
  int v49; // [esp+BCh] [ebp-4Ch]
  int v50; // [esp+C0h] [ebp-48h]
  Vector sOffs; // [esp+DCh] [ebp-2Ch] BYREF
  Vector dir; // [esp+E8h] [ebp-20h] BYREF
  float x; // [esp+F4h] [ebp-14h]
  int i; // [esp+F8h] [ebp-10h]
  int numSparks; // [esp+FCh] [ebp-Ch]
  CParticleEffect *v56; // [esp+100h] [ebp-8h]
  CParticleEffect *v57; // [esp+104h] [ebp-4h]

  v4 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_ElectricSpark",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x184u);
  v6 = v5;
  v57 = v5;
  if ( v5 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "FX_ElectricSpark 1");
    v6->__vftable = (CParticleEffect_vtbl *)&CTrailParticles::`vftable';
    CParticleCollision::CParticleCollision(this: (CParticleCollision *)&v6[1].m_ParticleEffect.IClientRenderable);
    v6[1].m_ParticleEffect.m_LastMax.y = 0.0;
    v6[1].m_ParticleEffect.m_LastMax.z = 0.0;
    CParticleEffect::AddRef(this: v6);
    if ( g_Material_Spark == nullptr )
      g_Material_Spark = CParticleEffect::GetPMaterial(this: v6, name: "effects/spark");
    v50 = 1145569280;
    v49 = 1133903872;
    ((void (__thiscall *)(CParticleEffect *, const Vector *, _DWORD, _DWORD, int))v6->__vftable[1].SimulateParticles)(
      a1: v6,
      a2: pos,
      a3: 0,
      a4: 0,
      a5: 1115684864);
    CParticleEffect::SetSortOrigin(this: v6, vSortOrigin: pos);
    v7 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 0x40000000,
           a3: 1082130432);
    i = nMagnitude * nMagnitude;
    numSparks = (int)(v7 * (double)(nMagnitude * nMagnitude));
    if ( numSparks <= 0 )
    {
LABEL_9:
      v17 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x184u);
      v18 = v17;
      v56 = v17;
      if ( v17 == nullptr )
      {
        v48 = v6;
        goto LABEL_29;
      }
      CSimpleEmitter::CSimpleEmitter(this: v17, pDebugName: "FX_ElectricSpark 2");
      v18->__vftable = (CSimpleEmitter_vtbl *)&CTrailParticles::`vftable';
      CParticleCollision::CParticleCollision(this: (CParticleCollision *)&v18[1]);
      v19 = nullptr;
      v18[1].m_ParticleEffect.m_LastMin.y = 0.0;
      v18[1].m_ParticleEffect.m_LastMin.z = 0.0;
      CParticleEffect::AddRef(this: v18);
      CParticleEffect::SetSortOrigin(this: v18, vSortOrigin: pos);
      v18[1].m_ParticleEffect.m_Max.y = 400.0;
      LODWORD(v18[1].m_ParticleEffect.m_LastMin.y) |= 1u;
      numSparks = nMagnitude * random->RandomInt(this: random, a2: 16, a3: 32);
      *(float *)&i = 0.0;
      if ( numSparks <= 0 )
      {
LABEL_16:
        x = *(float *)(gpGlobals.m_Index + 12) + 0.2;
        v28 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x118u);
        v29 = v28;
        if ( v28 != nullptr )
        {
          CSimpleEmitter::CSimpleEmitter(this: v28, pDebugName: "FX_ElectricSpark 3");
          v29->__vftable = (CSimpleEmitter_vtbl *)&CSimpleGlowEmitter::`vftable';
          CParticleEffect::SetSortOrigin(this: v29, vSortOrigin: pos);
          v30 = x;
          v29[1].m_ParticleEffect.CParticleEffect::__vftable = nullptr;
          LOWORD(v29[1].m_ParticleEffect.__vftable) = 0;
          v31 = *(float *)(gpGlobals.m_Index + 12);
          *(float *)&v29[1].__vftable = v30;
          *(float *)&v29[1].m_pDebugName = v31;
          v19 = v29;
        }
        v32 = nullptr;
        if ( v19 != nullptr )
        {
          CParticleEffect::AddRef(this: v19);
          v32 = v19;
        }
        PMaterial = CParticleEffect::GetPMaterial(this: v32, name: "effects/yellowflare_noz");
        v34 = CParticleEffect::AddParticle(this: v32, particleSize: 0x3Cu, material: PMaterial, origin: pos);
        v35 = v34;
        if ( v34 != nullptr )
        {
          *(_QWORD *)&v34[1].m_Pos.y = 1045220557;
          v34[1].m_pPrev = nullptr;
          v34[1].m_pNext = nullptr;
          v34[1].m_pSubTexture = nullptr;
          v34[2].m_pPrev = (Particle *)-1;
          LOBYTE(v34[2].m_pNext) = -1;
          BYTE1(v34[2].m_pNext) = nMagnitude * random->RandomInt(this: random, a2: 4, a3: 8);
          BYTE2(v35[2].m_pNext) = 0;
          v35[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          v35[2].m_pSubTexture = nullptr;
          v36 = CParticleEffect::GetPMaterial(this: v32, name: "effects/yellowflare_noz");
          v37 = CParticleEffect::AddParticle(this: v32, particleSize: 0x3Cu, material: v36, origin: pos);
          v38 = v37;
          if ( v37 != nullptr )
          {
            *(_QWORD *)&v37[1].m_Pos.y = 1045220557;
            v37[1].m_pPrev = nullptr;
            v37[1].m_pNext = nullptr;
            v37[1].m_pSubTexture = nullptr;
            v39 = (int)(float)random->RandomInt(this: random, a2: 32, a3: 64);
            LOBYTE(v38[2].m_pPrev) = v39;
            BYTE1(v38[2].m_pPrev) = v39;
            BYTE2(v38[2].m_pPrev) = v39;
            HIBYTE(v38[2].m_pPrev) = v39;
            LOBYTE(v38[2].m_pNext) = 0;
            BYTE1(v38[2].m_pNext) = nMagnitude * random->RandomInt(this: random, a2: 32, a3: 64);
            BYTE2(v38[2].m_pNext) = 0;
            v38[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
            *(float *)&v38[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                                a1: random,
                                                a2: -1082130432,
                                                a3: 1065353216);
            x = pos->x;
            v40 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1065353216,
                    a3: 1082130432);
            sOffs.x = v40 + x;
            RandomFloat = random->RandomFloat;
            x = pos->y;
            v42 = ((double (__stdcall *)(int, int))RandomFloat)(a1: -1065353216, a2: 1082130432);
            z = pos->z;
            sOffs.y = v42 + x;
            sOffs.z = z;
            v44 = CParticleEffect::AddParticle(this: v32, particleSize: 0x3Cu, material: dword_1066E3FC, origin: &sOffs);
            v45 = v44;
            if ( v44 != nullptr )
            {
              *(_QWORD *)&v44[1].m_Pos.y = 1065353216;
              v44[1].m_pPrev = nullptr;
              v44[1].m_pNext = nullptr;
              v44[1].m_pSubTexture = (CParticleSubTexture *)1098907648;
              *(float *)&v44[1].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1048576000,
                                            a3: 1098907648);
              *(float *)&v45[1].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1048576000,
                                            a3: 1098907648);
              LOWORD(v45[2].m_pPrev) = -1;
              BYTE2(v45[2].m_pPrev) = -56;
              HIBYTE(v45[2].m_pPrev) = random->RandomInt(this: random, a2: 16, a3: 32);
              LOBYTE(v45[2].m_pNext) = 0;
              v46 = random->RandomInt(this: random, a2: 4, a3: 8);
              BYTE1(v45[2].m_pNext) = v46;
              BYTE2(v45[2].m_pNext) = (int)(float)((float)v46 * 4.0);
              v45[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
              *(float *)&v45[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                                  a1: random,
                                                  a2: -1073741824,
                                                  a3: 0x40000000);
            }
          }
        }
        if ( v32 != nullptr )
          CParticleEffect::Release(this: v32);
        v47 = v56;
      }
      else
      {
        while ( 1 )
        {
          v20 = CParticleEffect::AddParticle(this: v18, particleSize: 0x38u, material: g_Material_Spark, origin: pos);
          v22 = v20;
          if ( v20 == nullptr )
            break;
          v20[1].m_Pos.z = 0.0;
          dir.x = _RandomFloat(this: v21, a2: -1.0, a3: 1.0);
          dir.y = _RandomFloat(this: v23, a2: -1.0, a3: 1.0);
          dir.z = _RandomFloat(this: v24, a2: -1.0, a3: 1.0);
          if ( vecDir != nullptr )
          {
            dir.x = vecDir->x + dir.x;
            dir.y = vecDir->y + dir.y;
            dir.z = vecDir->z + dir.z;
            VectorNormalize(vec: &dir);
          }
          *(float *)&v22[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                        a1: random,
                                        a2: 0x40000000,
                                        a3: 1082130432);
          *(float *)&v22[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                        a1: random,
                                        a2: 1017370378,
                                        a3: 1022739087)
                                    * (double)nTrailLength;
          v22[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1036831949,
                             a3: 1045220557)
                         * (double)nMagnitude;
          x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1124073472,
                a3: 1132462080);
          v25 = i + 1;
          *(float *)&v26 = dir.y * x;
          *(float *)&v27 = dir.z * x;
          *(float *)&v22[1].m_pPrev = x * dir.x;
          v22[1].m_pNext = v26;
          v22[1].m_pSubTexture = v27;
          v22[1].m_Pos.x = NAN;
          i = v25;
          if ( v25 >= numSparks )
          {
            v19 = nullptr;
            goto LABEL_16;
          }
        }
        v47 = v18;
      }
      CParticleEffect::Release(this: v47);
    }
    else
    {
      while ( 1 )
      {
        v8 = CParticleEffect::AddParticle(this: v6, particleSize: 0x38u, material: g_Material_Spark, origin: pos);
        v9 = v8;
        if ( v8 == nullptr )
          break;
        v8[1].m_Pos.z = 0.0;
        v8[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int, int, int))random->RandomFloat)(
                          a1: random,
                          a2: 1065353216,
                          a3: 0x40000000,
                          a4: v49,
                          a5: v50)
                      * (double)nMagnitude;
        dir.x = _RandomFloat(this: v10, a2: -1.0, a3: 1.0);
        dir.y = _RandomFloat(this: v11, a2: -1.0, a3: 1.0);
        dir.z = _RandomFloat(this: v12, a2: -1.0, a3: 1.0);
        dir.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1056964608,
                  a3: 1065353216);
        if ( vecDir != nullptr )
        {
          v13 = (float)(vecDir->y * 2.0) + dir.y;
          v14 = (float)(vecDir->z * 2.0) + dir.z;
          dir.x = (float)(vecDir->x * 2.0) + dir.x;
          dir.y = v13;
          dir.z = v14;
          VectorNormalize(vec: &dir);
        }
        *(float *)&v9[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 0x40000000,
                                     a3: 1084227584);
        v50 = 1133903872;
        v49 = 1115684864;
        *(float *)&v9[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1017370378,
                                     a3: 1028443341)
                                 * (double)nTrailLength;
        *(float *)&i = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
        *(float *)&v15 = dir.y * *(float *)&i;
        *(float *)&v16 = dir.z * *(float *)&i;
        *(float *)&v9[1].m_pPrev = dir.x * *(float *)&i;
        v9[1].m_pNext = v15;
        v9[1].m_pSubTexture = v16;
        ++v4;
        v9[1].m_Pos.x = NAN;
        v6 = v57;
        if ( v4 >= numSparks )
          goto LABEL_9;
      }
    }
    v48 = v57;
LABEL_29:
    CParticleEffect::Release(this: v48);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1026C9B0
// Name: void FX_MetalSpark(class Vector const __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_MetalSpark(
        int a1@<esi>,
        const Vector *position,
        const Vector *direction,
        const Vector *surfaceNormal,
        int iScale)
{
  const Vector *v5; // ebx
  float v6; // xmm3_4
  float v7; // xmm0_4
  CSimpleEmitter *v8; // eax
  CSimpleEmitter *v9; // edi
  int v10; // esi
  Particle *v11; // eax
  Particle *v12; // esi
  double v13; // st7
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  double v15; // st7
  float (__thiscall *v16)(IUniformRandomStream *, float, float); // edx
  double v17; // st7
  float (__thiscall *v18)(IUniformRandomStream *, float, float); // edx
  double v19; // st7
  int v20; // eax
  Particle *v21; // xmm1_4
  CParticleSubTexture *v22; // xmm2_4
  IMaterial *v23; // eax
  float x; // xmm1_4
  float y; // xmm1_4
  float z; // xmm1_4
  int v27; // [esp+60h] [ebp-A4h]
  int v28; // [esp+64h] [ebp-A0h]
  FXQuadData_t data; // [esp+68h] [ebp-9Ch] BYREF
  Vector bbMax; // [esp+BCh] [ebp-48h] BYREF
  Vector bbMin; // [esp+C8h] [ebp-3Ch] BYREF
  int numSparks; // [esp+D4h] [ebp-30h]
  Vector dir; // [esp+D8h] [ebp-2Ch] BYREF
  float v34; // [esp+E4h] [ebp-20h]
  int v35; // [esp+E8h] [ebp-1Ch]
  float spreadOfs; // [esp+ECh] [ebp-18h]
  Vector offset; // [esp+F0h] [ebp-14h] BYREF
  int i; // [esp+FCh] [ebp-8h]
  float v39; // [esp+100h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_MetalSpark",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( fx_drawmetalspark.m_pParent == nullptr )
    goto LABEL_3;
  if ( fx_drawmetalspark.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_3;
  v5 = surfaceNormal;
  v6 = position->x + surfaceNormal->x;
  offset.y = position->y + surfaceNormal->y;
  v7 = position->z + surfaceNormal->z;
  offset.x = v6;
  offset.z = v7;
  v8 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x184u);
  v9 = v8;
  if ( v8 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v8, pDebugName: "FX_MetalSpark 1");
    v9->__vftable = (CSimpleEmitter_vtbl *)&CTrailParticles::`vftable';
    CParticleCollision::CParticleCollision(this: (CParticleCollision *)&v9[1]);
    v9[1].m_ParticleEffect.m_LastMin.y = 0.0;
    v9[1].m_ParticleEffect.m_LastMin.z = 0.0;
    CParticleEffect::AddRef(this: v9);
    CParticleEffect::SetSortOrigin(this: v9, vSortOrigin: &offset);
    LODWORD(v9[1].m_ParticleEffect.m_LastMin.y) |= 1u;
    v9[1].m_ParticleEffect.m_LastMin.z = 8.0;
    v9[1].m_ParticleEffect.m_Max.y = 400.0;
    v9[1].m_ParticleEffect.m_Max.z = 0.25;
    bbMax.x = offset.x + 32.0;
    bbMax.y = offset.y + 32.0;
    bbMax.z = offset.z + 32.0;
    bbMin.x = offset.x - 32.0;
    bbMin.y = offset.y - 32.0;
    bbMin.z = offset.z - 32.0;
    CParticleEffectBinding::SetBBox(this: &v9->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
    v10 = 2
        * iScale
        * ((int (__thiscall *)(IUniformRandomStream *, int, int, int, int, int))random->RandomInt)(
            a1: random,
            a2: 4,
            a3: 8,
            a4: a1,
            a5: v27,
            a6: v28);
    numSparks = v10;
    if ( g_Material_Spark == nullptr )
      g_Material_Spark = CParticleEffect::GetPMaterial(this: v9, name: "effects/spark");
    i = 0;
    if ( v10 <= 0 )
    {
LABEL_16:
      data.m_flLifeTime = 0.0;
      data.m_flDieTime = 0.0;
      data.m_uiFlags = 0;
      v23 = materials->FindMaterial(
              this: materials,
              a2: "effects/yellowflare",
              a3: "ClientEffect textures",
              a4: 1,
              a5: 0);
      data.m_pMaterial = v23;
      if ( v23 != nullptr )
        v23->IncrementReferenceCount(this: v23);
      data.m_vecOrigin = offset;
      x = v5->x;
      data.m_Color.x = 1.0;
      data.m_Color.y = 1.0;
      data.m_Color.z = 1.0;
      data.m_vecNormal.x = x;
      y = v5->y;
      data.m_flStartAlpha = 1.0;
      data.m_vecNormal.y = y;
      z = v5->z;
      data.m_flEndAlpha = 0.0;
      data.m_vecNormal.z = z;
      data.m_flDieTime = 0.1;
      data.m_flYaw = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      data.m_flDeltaYaw = 0.0;
      data.m_flStartScale = (float)random->RandomInt(this: random, a2: 24, a3: 28);
      data.m_flEndScale = 0.0;
      FX_AddQuad(&data);
    }
    else
    {
      while ( 1 )
      {
        v11 = CParticleEffect::AddParticle(this: v9, particleSize: 0x38u, material: g_Material_Spark, origin: &offset);
        v12 = v11;
        if ( v11 == nullptr )
          break;
        v11[1].m_Pos.z = 0.0;
        if ( iScale <= 1 || i % 3 != 0 )
          v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1028443341,
                  a3: 1036831949);
        else
          v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1041865114,
                  a3: 1048576000);
        v12[1].m_Pos.y = v13;
        spreadOfs = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                      a1: random,
                      a2: 0,
                      a3: 0x40000000);
        v39 = direction->x;
        RandomFloat = random->RandomFloat;
        v34 = spreadOfs * 0.5;
        v35 = COERCE_UNSIGNED_INT(spreadOfs * 0.5) ^ _mask__NegFloat_;
        v15 = ((double (__thiscall *)(IUniformRandomStream *, int, _DWORD))RandomFloat)(
                a1: random,
                a2: v35,
                a3: spreadOfs * 0.5);
        dir.x = v15 + v39;
        v16 = random->RandomFloat;
        v39 = direction->y;
        v17 = ((double (__stdcall *)(int, _DWORD))v16)(a1: v35, a2: LODWORD(v34));
        dir.y = v17 + v39;
        v18 = random->RandomFloat;
        v39 = direction->z;
        v19 = ((double (__stdcall *)(int, _DWORD))v18)(a1: v35, a2: LODWORD(v34));
        dir.z = v19 + v39;
        VectorNormalize(vec: &dir);
        *(float *)&v12[2].m_pNext = ((double (__stdcall *)(int, int))random->RandomFloat)(
                                      a1: 1065353216,
                                      a2: 1082130432);
        *(float *)&v12[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1020054733,
                                      a3: 1036831949);
        v39 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                a1: random,
                a2: (float)(2.0 - spreadOfs) * 128.0,
                a3: (float)(2.0 - spreadOfs) * 512.0);
        v20 = i + 1;
        *(float *)&v21 = dir.y * v39;
        *(float *)&v22 = dir.z * v39;
        *(float *)&v12[1].m_pPrev = dir.x * v39;
        v12[1].m_pNext = v21;
        v12[1].m_pSubTexture = v22;
        v12[1].m_Pos.x = NAN;
        i = v20;
        if ( v20 >= numSparks )
        {
          v5 = surfaceNormal;
          goto LABEL_16;
        }
      }
    }
    CParticleEffect::Release(this: v9);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
LABEL_3:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026CF10
// Name: void FX_EnergySplash(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_EnergySplash(const Vector *pos, const Vector *normal)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  int v5; // eax
  int v6; // eax
  CParticleEffect *v7; // esi
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v8; // eax
  CParticleEffect *m_pObj; // ebx
  double v10; // st7
  Particle *v11; // esi
  double v12; // st7
  int v13; // eax
  __int64 shader; // [esp+60h] [ebp-24h] BYREF
  int v15; // [esp+68h] [ebp-1Ch]
  Vector offset; // [esp+6Ch] [ebp-18h] BYREF
  int v17; // [esp+78h] [ebp-Ch]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> result; // [esp+7Ch] [ebp-8h] BYREF
  int j; // [esp+80h] [ebp-4h]
  CParticleEffect *pEmitter; // [esp+8Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_EnergySplash",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v3 = normal->z * 2.0;
  v4 = pos->x + (float)(normal->x * 2.0);
  offset.y = pos->y + (float)(normal->y * 2.0);
  offset.z = pos->z + v3;
  shader = 0x3F8000003F800000LL;
  v15 = 1065353216;
  offset.x = v4;
  v5 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
  FX_AddQuad(
    origin: pos,
    normal,
    startSize: 64.0,
    endSize: 0.0,
    sizeBias: 0.75,
    startAlpha: 1.0,
    endAlpha: 0.0,
    alphaBias: 0.40000001,
    yaw: (float)v5,
    deltaYaw: 0.0,
    color: (const Vector *)0x168,
    lifeTime: 0.0,
    (const char *)&shader,
    flags: 0x3E800000u);
  shader = 0x3F8000003F800000LL;
  v15 = 1065353216;
  v6 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
  FX_AddQuad(
    origin: pos,
    normal,
    startSize: 16.0,
    endSize: 32.0,
    sizeBias: 0.75,
    startAlpha: 1.0,
    endAlpha: 0.0,
    alphaBias: 0.40000001,
    yaw: (float)v6,
    deltaYaw: 0.0,
    color: (const Vector *)0x168,
    lifeTime: 0.0,
    (const char *)&shader,
    flags: 0x3F000000u);
  v7 = nullptr;
  pEmitter = nullptr;
  v8 = CSimpleEmitter::Create(&result, pDebugName: "C_EntityDissolve");
  m_pObj = v8->m_pObj;
  if ( v8->m_pObj != nullptr )
  {
    CParticleEffect::AddRef(this: v8->m_pObj);
    pEmitter = m_pObj;
    v7 = m_pObj;
  }
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  CParticleEffect::SetSortOrigin(this: v7, vSortOrigin: pos);
  if ( g_Material_Spark == nullptr )
    g_Material_Spark = CParticleEffect::GetPMaterial(this: v7, name: "effects/spark");
  j = 0;
  while ( 1 )
  {
    offset.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: -1056964608,
                 a3: 1090519040);
    offset.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: -1056964608,
                 a3: 1090519040);
    v10 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
            a1: random,
            a2: 0,
            a3: 1082130432);
    offset.x = pos->x + offset.x;
    offset.y = pos->y + offset.y;
    offset.z = v10 + pos->z;
    v11 = CParticleEffect::AddParticle(this: v7, particleSize: 0x3Cu, material: g_Material_Spark, origin: &offset);
    if ( v11 == nullptr )
      break;
    *(float *)&shader = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
    *((float *)&shader + 1) = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
    v12 = Helper_RandomFloat(minVal: 16.0, maxVal: 64.0);
    *(_QWORD *)&v11[1].m_pPrev = shader;
    *(float *)&v11[1].m_pSubTexture = v12;
    v17 = (int)((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 0x40000000,
                 a3: 1082130432);
    BYTE1(v11[2].m_pNext) = v17;
    v11[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: 1053609165,
                       a3: 1058642330);
    v11[1].m_Pos.z = 0.0;
    v11[1].m_Pos.x = (float)Helper_RandomInt(minVal: 0, maxVal: 360);
    *(float *)&v11[2].m_pSubTexture = Helper_RandomFloat(minVal: -4.0, maxVal: 4.0);
    v13 = j + 1;
    LOBYTE(v11[2].m_pPrev) = -1;
    BYTE1(v11[2].m_pPrev) = -1;
    BYTE2(v11[2].m_pPrev) = -1;
    HIBYTE(v11[2].m_pPrev) = -1;
    LOBYTE(v11[2].m_pNext) = 0;
    BYTE2(v11[2].m_pNext) = 0;
    j = v13;
    if ( v13 >= 8 )
      break;
    v7 = pEmitter;
  }
  if ( pEmitter != nullptr )
    CParticleEffect::Release(this: pEmitter);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1026D380
// Name: void FX_SparkFan(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_SparkFan(Vector *position, Vector *normal)
{
  float v3; // xmm3_4
  float v4; // xmm0_4
  CSimpleEmitter *v5; // eax
  char *v6; // esi
  int v7; // ebx
  Particle *v8; // eax
  Particle *v9; // esi
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  Particle *v11; // xmm1_4
  CParticleSubTexture *v12; // xmm2_4
  float dir; // [esp+70h] [ebp-20h]
  float dir_4; // [esp+74h] [ebp-1Ch]
  float dir_8; // [esp+78h] [ebp-18h]
  Vector offset; // [esp+7Ch] [ebp-14h] BYREF
  float spreadOfs; // [esp+88h] [ebp-8h]
  int v18; // [esp+8Ch] [ebp-4h]
  float positiona; // [esp+98h] [ebp+8h]
  Vector *normala; // [esp+9Ch] [ebp+Ch]

  v3 = position->x + normal->x;
  offset.y = position->y + normal->y;
  v4 = position->z + normal->z;
  offset.x = v3;
  offset.z = v4;
  v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x184u);
  v6 = (char *)v5;
  v7 = 0;
  normala = (Vector *)v5;
  if ( v5 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "FX_MetalScrape 1");
    *(_DWORD *)v6 = &CTrailParticles::`vftable';
    CParticleCollision::CParticleCollision(this: (CParticleCollision *)(v6 + 264));
    *((_DWORD *)v6 + 95) = 0;
    *((_DWORD *)v6 + 96) = 0;
    CParticleEffect::AddRef(this: (CParticleEffect *)v6);
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)v6, vSortOrigin: &offset);
    (*(void (__thiscall **)(char *, Vector *, Vector *, int, int, int, int, int, int, _DWORD))(*(_DWORD *)v6 + 72))(
      a1: v6,
      a2: &offset,
      a3: normal,
      a4: 1050253722,
      a5: 1124073472,
      a6: 1140850688,
      a7: 1145569280,
      a8: 1053609165,
      a9: 1,
      a10: 0);
    if ( g_Material_Spark == nullptr )
      g_Material_Spark = CParticleEffect::GetPMaterial(this: (CParticleEffect *)v6, name: "effects/spark");
    while ( 1 )
    {
      v8 = CParticleEffect::AddParticle(
             this: (CParticleEffect *)v6,
             particleSize: 0x38u,
             material: g_Material_Spark,
             origin: &offset);
      v9 = v8;
      if ( v8 == nullptr )
        break;
      v8[1].m_Pos.z = 0.0;
      spreadOfs = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                    a1: random,
                    a2: 0,
                    a3: 0x40000000);
      RandomFloat = random->RandomFloat;
      positiona = spreadOfs * 0.30000001;
      v18 = COERCE_UNSIGNED_INT(spreadOfs * 0.30000001) ^ _mask__NegFloat_;
      dir = ((double (__thiscall *)(IUniformRandomStream *, int, _DWORD))RandomFloat)(
              a1: random,
              a2: v18,
              a3: spreadOfs * 0.30000001)
          + normal->x;
      dir_4 = ((double (__thiscall *)(IUniformRandomStream *, int, _DWORD))random->RandomFloat)(
                a1: random,
                a2: v18,
                a3: LODWORD(positiona))
            + normal->y;
      dir_8 = ((double (__thiscall *)(IUniformRandomStream *, int, _DWORD))random->RandomFloat)(
                a1: random,
                a2: v18,
                a3: LODWORD(positiona))
            + normal->z;
      *(float *)&v9[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 0x40000000,
                                   a3: 1084227584);
      *(float *)&v9[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 1014350479,
                                   a3: 1031127695);
      v9[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 0x40000000,
                        a3: 0x40000000);
      spreadOfs = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                    a1: random,
                    a2: (float)(2.0 - spreadOfs) * 128.0,
                    a3: (float)(2.0 - spreadOfs) * 512.0);
      ++v7;
      *(float *)&v11 = dir_4 * spreadOfs;
      *(float *)&v12 = dir_8 * spreadOfs;
      *(float *)&v9[1].m_pPrev = dir * spreadOfs;
      v9[1].m_pNext = v11;
      v9[1].m_pSubTexture = v12;
      v9[1].m_Pos.x = NAN;
      if ( v7 >= 35 )
        break;
      v6 = (char *)normala;
    }
    CParticleEffect::Release(this: (CParticleEffect *)normala);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D690
// Name: void ManhackSparkCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ManhackSparkCallback(const CEffectData *data)
{
  Vector vecPosition; // [esp+0h] [ebp-18h] BYREF
  Vector vecNormal; // [esp+Ch] [ebp-Ch] BYREF

  vecPosition = data->m_vOrigin;
  vecNormal = data->m_vNormal;
  FX_SparkFan(position: &vecPosition, normal: &vecNormal);
}

//------------------------------------------------------------------------------
// Address: 0x1042D110
// Name: PrecacheEffectSparksPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectSparksPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectSparksPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectSparksPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D180
// Name: ManhackSparksPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ManhackSparksPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ManhackSparksPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ManhackSparksPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D130
// Name: _dynamic_initializer_for__fx_drawmetalspark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fx_drawmetalspark__()
{
  ConVar::ConVar(
    this: &fx_drawmetalspark,
    pName: "fx_drawmetalspark",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Draw metal spark effects.");
  return atexit(func: dynamic_atexit_destructor_for__fx_drawmetalspark__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D160
// Name: _dynamic_initializer_for__ClientEffectReg_ManhackSparkCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ManhackSparkCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ManhackSparkCallback,
           pEffectName: "ManhackSparks",
           fn: ManhackSparkCallback);
}
