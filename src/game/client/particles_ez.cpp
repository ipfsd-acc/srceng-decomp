// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particles_ez.cpp
// Functions: 6
// ============================================================

#include "game\client\particles_ez.h"

//------------------------------------------------------------------------------
// Address: 0x10136870
// Name: void DrawParticleSingletons(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawParticleSingletons(bool bInSkybox)
{
  CSimpleEmitter *m_pObj; // eax
  CEmberEffect *v2; // eax
  CFireSmokeEffect *v3; // eax
  CFireParticle *v4; // esi
  RenderableInstance_t instance; // [esp+7h] [ebp-1h] BYREF

  m_pObj = g_pSimpleSingleton[bInSkybox].m_pObj;
  instance.m_nAlpha = -1;
  if ( m_pObj != nullptr )
    m_pObj->m_ParticleEffect.DrawModel(this: &m_pObj->m_ParticleEffect.IClientRenderable, a2: 1, a3: &instance);
  v2 = g_pEmberSingleton[bInSkybox].m_pObj;
  if ( v2 != nullptr )
    v2->m_ParticleEffect.DrawModel(this: &v2->m_ParticleEffect.IClientRenderable, a2: 1, a3: &instance);
  v3 = g_pFireSmokeSingleton[bInSkybox].m_pObj;
  if ( v3 != nullptr )
    v3->m_ParticleEffect.DrawModel(this: &v3->m_ParticleEffect.IClientRenderable, a2: 1, a3: &instance);
  v4 = g_pFireSingleton[bInSkybox].m_pObj;
  if ( v4 != nullptr )
    v4->m_ParticleEffect.DrawModel(this: &v4->m_ParticleEffect.IClientRenderable, a2: 1, a3: &instance);
}

//------------------------------------------------------------------------------
// Address: 0x10136900
// Name: public: virtual void CEZParticleInit::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEZParticleInit::LevelShutdownPreEntity(CEZParticleInit *this)
{
  if ( g_pSimpleSingleton[1].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pSimpleSingleton[1].m_pObj);
    g_pSimpleSingleton[1].m_pObj = nullptr;
  }
  if ( g_pSimpleSingleton[0].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pSimpleSingleton[0].m_pObj);
    g_pSimpleSingleton[0].m_pObj = nullptr;
  }
  if ( g_pEmberSingleton[1].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pEmberSingleton[1].m_pObj);
    g_pEmberSingleton[1].m_pObj = nullptr;
  }
  if ( g_pEmberSingleton[0].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pEmberSingleton[0].m_pObj);
    g_pEmberSingleton[0].m_pObj = nullptr;
  }
  if ( g_pFireSmokeSingleton[1].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pFireSmokeSingleton[1].m_pObj);
    g_pFireSmokeSingleton[1].m_pObj = nullptr;
  }
  if ( g_pFireSmokeSingleton[0].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pFireSmokeSingleton[0].m_pObj);
    g_pFireSmokeSingleton[0].m_pObj = nullptr;
  }
  if ( g_pFireSingleton[1].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pFireSingleton[1].m_pObj);
    g_pFireSingleton[1].m_pObj = nullptr;
  }
  if ( g_pFireSingleton[0].m_pObj != nullptr )
  {
    CParticleEffect::Release(this: g_pFireSingleton[0].m_pObj);
    g_pFireSingleton[0].m_pObj = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101369B0
// Name: public: class SimpleParticle __near & SimpleParticle::operator=(class SimpleParticle const __near &)
// Source: json
//------------------------------------------------------------------------------
SimpleParticle *__thiscall SimpleParticle::operator=(SimpleParticle *this, const SimpleParticle *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10136A40
// Name: public: class CSmartPtr<class CFireParticle,class CRefCountAccessor> CEZParticleInit::InitSingleton<class CFireParticle>(class CSmartPtr<class CFireParticle,class CRefCountAccessor>)
// Source: json
//------------------------------------------------------------------------------
CSmartPtr<CSimpleEmitter,CRefCountAccessor> *__thiscall CEZParticleInit::InitSingleton<CFireParticle>(
        CEZParticleInit *this,
        CSmartPtr<CSimpleEmitter,CRefCountAccessor> *result,
        CSmartPtr<CFireParticle,CRefCountAccessor> pEmitter)
{
  Vector bbMin; // [esp+0h] [ebp-18h] BYREF
  Vector vSortOrigin; // [esp+Ch] [ebp-Ch] BYREF

  if ( pEmitter.m_pObj == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_10484C94, a2: (const char *)LODWORD(bbMin.x));
  CParticleEffectBinding::SetDrawThruLeafSystem(this: &pEmitter.m_pObj->m_ParticleEffect, bDraw: 0);
  memset((void *)&vSortOrigin, 0, sizeof(vSortOrigin));
  CParticleEffect::SetSortOrigin(this: pEmitter.m_pObj, &vSortOrigin);
  memset((void *)&vSortOrigin, 0, sizeof(vSortOrigin));
  memset((void *)&bbMin, 0, sizeof(bbMin));
  CParticleEffectBinding::SetBBox(
    this: &pEmitter.m_pObj->m_ParticleEffect,
    &bbMin,
    bbMax: &vSortOrigin,
    bDisableAutoUpdate: true);
  result->m_pObj = nullptr;
  if ( pEmitter.m_pObj != nullptr )
  {
    CParticleEffect::AddRef(this: pEmitter.m_pObj);
    if ( result->m_pObj != nullptr )
      CParticleEffect::Release(this: result->m_pObj);
    result->m_pObj = pEmitter.m_pObj;
    CParticleEffect::Release(this: pEmitter.m_pObj);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10136B00
// Name: public: virtual void CEZParticleInit::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEZParticleInit::LevelInitPreEntity(CEZParticleInit *this)
{
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *inited; // eax
  CSimpleEmitter *m_pObj; // esi
  CSimpleEmitter *v4; // ecx
  CFireParticle *v5; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v6; // eax
  CSimpleEmitter *v7; // esi
  CSimpleEmitter *v8; // ecx
  CFireParticle *v9; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v10; // eax
  CEmberEffect *v11; // esi
  CEmberEffect *v12; // ecx
  CFireParticle *v13; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v14; // eax
  CEmberEffect *v15; // esi
  CEmberEffect *v16; // ecx
  CFireParticle *v17; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v18; // eax
  CFireSmokeEffect *v19; // esi
  CFireSmokeEffect *v20; // ecx
  CFireParticle *v21; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v22; // eax
  CFireSmokeEffect *v23; // esi
  CFireSmokeEffect *v24; // ecx
  CFireParticle *v25; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v26; // eax
  CFireParticle *v27; // esi
  CFireParticle *v28; // ecx
  CFireParticle *v29; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v30; // eax
  CFireParticle *v31; // esi
  CFireParticle *v32; // ecx
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> v33[3]; // [esp-4h] [ebp-10h] BYREF
  CSmartPtr<CFireParticle,CRefCountAccessor> result; // [esp+8h] [ebp-4h] BYREF

  v33[0].m_pObj = (CSimpleEmitter *)this;
  CSimpleEmitter::Create(result: v33, pDebugName: "Simple Particle Singleton");
  inited = CEZParticleInit::InitSingleton<CFireParticle>(
             this,
             (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
             pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  m_pObj = inited->m_pObj;
  v4 = g_pSimpleSingleton[0].m_pObj;
  if ( inited->m_pObj != g_pSimpleSingleton[0].m_pObj )
  {
    if ( m_pObj != nullptr )
    {
      CParticleEffect::AddRef(this: inited->m_pObj);
      v4 = g_pSimpleSingleton[0].m_pObj;
    }
    if ( v4 != nullptr )
      CParticleEffect::Release(this: v4);
    g_pSimpleSingleton[0].m_pObj = m_pObj;
  }
  v5 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v5;
  CSimpleEmitter::Create(result: v33, pDebugName: "Simple Particle Singleton [sky]");
  v6 = CEZParticleInit::InitSingleton<CFireParticle>(
         this,
         (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
         pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v7 = v6->m_pObj;
  v8 = g_pSimpleSingleton[1].m_pObj;
  if ( v6->m_pObj != g_pSimpleSingleton[1].m_pObj )
  {
    if ( v7 != nullptr )
    {
      CParticleEffect::AddRef(this: v6->m_pObj);
      v8 = g_pSimpleSingleton[1].m_pObj;
    }
    if ( v8 != nullptr )
      CParticleEffect::Release(this: v8);
    g_pSimpleSingleton[1].m_pObj = v7;
  }
  v9 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v9;
  CEmberEffect::Create(result: (CSmartPtr<CEmberEffect,CRefCountAccessor> *)v33, pDebugName: "Ember Particle Singleton");
  v10 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v11 = (CEmberEffect *)v10->m_pObj;
  v12 = g_pEmberSingleton[0].m_pObj;
  if ( v10->m_pObj != g_pEmberSingleton[0].m_pObj )
  {
    if ( v11 != nullptr )
    {
      CParticleEffect::AddRef(this: v10->m_pObj);
      v12 = g_pEmberSingleton[0].m_pObj;
    }
    if ( v12 != nullptr )
      CParticleEffect::Release(this: v12);
    g_pEmberSingleton[0].m_pObj = v11;
  }
  v13 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v13;
  CEmberEffect::Create(
    result: (CSmartPtr<CEmberEffect,CRefCountAccessor> *)v33,
    pDebugName: "Ember Particle Singleton [sky]");
  v14 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v15 = (CEmberEffect *)v14->m_pObj;
  v16 = g_pEmberSingleton[1].m_pObj;
  if ( v14->m_pObj != g_pEmberSingleton[1].m_pObj )
  {
    if ( v15 != nullptr )
    {
      CParticleEffect::AddRef(this: v14->m_pObj);
      v16 = g_pEmberSingleton[1].m_pObj;
    }
    if ( v16 != nullptr )
      CParticleEffect::Release(this: v16);
    g_pEmberSingleton[1].m_pObj = v15;
  }
  v17 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v17;
  CFireSmokeEffect::Create(
    result: (CSmartPtr<CFireSmokeEffect,CRefCountAccessor> *)v33,
    pDebugName: "Fire Smoke Particle Singleton");
  v18 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v19 = (CFireSmokeEffect *)v18->m_pObj;
  v20 = g_pFireSmokeSingleton[0].m_pObj;
  if ( v18->m_pObj != g_pFireSmokeSingleton[0].m_pObj )
  {
    if ( v19 != nullptr )
    {
      CParticleEffect::AddRef(this: v18->m_pObj);
      v20 = g_pFireSmokeSingleton[0].m_pObj;
    }
    if ( v20 != nullptr )
      CParticleEffect::Release(this: v20);
    g_pFireSmokeSingleton[0].m_pObj = v19;
  }
  v21 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v21;
  CFireSmokeEffect::Create(
    result: (CSmartPtr<CFireSmokeEffect,CRefCountAccessor> *)v33,
    pDebugName: "Fire Smoke Particle Singleton [sky]");
  v22 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v23 = (CFireSmokeEffect *)v22->m_pObj;
  v24 = g_pFireSmokeSingleton[1].m_pObj;
  if ( v22->m_pObj != g_pFireSmokeSingleton[1].m_pObj )
  {
    if ( v23 != nullptr )
    {
      CParticleEffect::AddRef(this: v22->m_pObj);
      v24 = g_pFireSmokeSingleton[1].m_pObj;
    }
    if ( v24 != nullptr )
      CParticleEffect::Release(this: v24);
    g_pFireSmokeSingleton[1].m_pObj = v23;
  }
  v25 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v25;
  CFireParticle::Create(
    result: (CSmartPtr<CFireParticle,CRefCountAccessor> *)v33,
    pDebugName: "Fire Particle Singleton");
  v26 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v27 = (CFireParticle *)v26->m_pObj;
  v28 = g_pFireSingleton[0].m_pObj;
  if ( v26->m_pObj != g_pFireSingleton[0].m_pObj )
  {
    if ( v27 != nullptr )
    {
      CParticleEffect::AddRef(this: v26->m_pObj);
      v28 = g_pFireSingleton[0].m_pObj;
    }
    if ( v28 != nullptr )
      CParticleEffect::Release(this: v28);
    g_pFireSingleton[0].m_pObj = v27;
  }
  v29 = result.m_pObj;
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
  v33[0].m_pObj = v29;
  CFireParticle::Create(
    result: (CSmartPtr<CFireParticle,CRefCountAccessor> *)v33,
    pDebugName: "Fire Particle Singleton [sky]");
  v30 = CEZParticleInit::InitSingleton<CFireParticle>(
          this,
          (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&result,
          pEmitter: (CSmartPtr<CFireParticle,CRefCountAccessor>)v33[0].m_pObj);
  v31 = (CFireParticle *)v30->m_pObj;
  v32 = g_pFireSingleton[1].m_pObj;
  if ( v30->m_pObj != g_pFireSingleton[1].m_pObj )
  {
    if ( v31 != nullptr )
    {
      CParticleEffect::AddRef(this: v30->m_pObj);
      v32 = g_pFireSingleton[1].m_pObj;
    }
    if ( v32 != nullptr )
      CParticleEffect::Release(this: v32);
    g_pFireSingleton[1].m_pObj = v31;
  }
  if ( result.m_pObj != nullptr )
    CParticleEffect::Release(this: result.m_pObj);
}

//------------------------------------------------------------------------------
// Address: 0x10136DB0
// Name: void AddSimpleParticle(class SimpleParticle const __near *,class CParticleSubTexture __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSimpleParticle(const SimpleParticle *pParticle, CParticleSubTexture *hMaterial, bool bInSkybox)
{
  CSimpleEmitter *m_pObj; // ecx
  SimpleParticle *v4; // eax
  SimpleParticle *v5; // esi
  Particle *m_pNext; // ebx
  Particle *m_pPrev; // edi
  CParticleSubTexture *bInSkyboxa; // [esp+1Ch] [ebp+10h]

  m_pObj = g_pSimpleSingleton[bInSkybox].m_pObj;
  if ( m_pObj != nullptr )
  {
    v4 = CSimpleEmitter::AddSimpleParticle(
           this: m_pObj,
           hMaterial,
           vOrigin: &pParticle->m_Pos,
           flDieTime: 3.0,
           uchSize: 0xAu);
    v5 = v4;
    if ( v4 != nullptr )
    {
      m_pNext = v4->m_pNext;
      m_pPrev = v4->m_pPrev;
      bInSkyboxa = v4->m_pSubTexture;
      SimpleParticle::operator=(this: v4, __that: pParticle);
      v5->m_pPrev = m_pPrev;
      v5->m_pNext = m_pNext;
      v5->m_pSubTexture = bInSkyboxa;
    }
  }
}
