// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_blood.cpp
// Functions: 16
// ============================================================

#include "game\client\fx_blood.h"

//------------------------------------------------------------------------------
// Address: 0x100D6070
// Name: public: virtual float CBloodSprayEmitter::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBloodSprayEmitter::UpdateRoll(CBloodSprayEmitter *this, SimpleParticle *pParticle, float timeDelta)
{
  float v3; // xmm0_4
  double result; // st7

  v3 = (float)((float)(timeDelta * -4.0) + 1.0) * pParticle->m_flRollDelta;
  pParticle->m_flRoll = (float)(pParticle->m_flRollDelta * timeDelta) + pParticle->m_flRoll;
  result = pParticle->m_flRoll;
  pParticle->m_flRollDelta = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D60B0
// Name: public: virtual void PrecacheEffectBloodSprayPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectBloodSprayPrecache::CResourcePrecacher::Cache(
        PrecacheEffectBloodSprayPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood_core",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood_gore",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood_drop",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood_puff",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D6120
// Name: public: virtual void BloodImpactPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BloodImpactPrecache::CResourcePrecacher::Cache(
        BloodImpactPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_red_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_green_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_yellow_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D6170
// Name: public: virtual void CBloodSprayEmitter::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBloodSprayEmitter::UpdateVelocity(
        CBloodSprayEmitter *this,
        SimpleParticle *pParticle,
        float timeDelta)
{
  float v4; // xmm1_4
  double v5; // xmm0_8
  __m128d v6; // xmm0
  double v7; // xmm0_8
  float v8; // xmm0_4
  float v9; // xmm2_4

  if ( (pParticle->m_iFlags & 2) == 0 )
  {
    v4 = timeDelta;
    if ( `CBloodSprayEmitter::UpdateVelocity'::`5'::dtime == timeDelta )
    {
      v8 = `CBloodSprayEmitter::UpdateVelocity'::`5'::decay;
    }
    else
    {
      __libm_sse2_log(a1: (__m128d)0x3FB99999A0000000uLL);
      *(float *)&v5 = v5;
      v6.m128d_f64[0] = (float)((float)(*(float *)&v5 * 2.5) * `CBloodSprayEmitter::UpdateVelocity'::`5'::dtime);
      __libm_sse2_exp(a1: v6);
      v4 = timeDelta;
      v8 = v7;
      `CBloodSprayEmitter::UpdateVelocity'::`5'::decay = v8;
      `CBloodSprayEmitter::UpdateVelocity'::`5'::dtime = timeDelta;
    }
    pParticle->m_vecVelocity.x = pParticle->m_vecVelocity.x * v8;
    pParticle->m_vecVelocity.y = pParticle->m_vecVelocity.y * v8;
    v9 = pParticle->m_vecVelocity.z * v8;
    pParticle->m_vecVelocity.z = v9;
    pParticle->m_vecVelocity.z = v9 - (float)(this->m_flGravity * v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6230
// Name: void HunterDamageCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall HunterDamageCallback(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CEffectData *data)
{
  IUniformRandomStream *v4; // ecx
  int v5; // ebx
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  CSimple3DEmitter *m_pObj; // esi
  int v9; // eax
  Particle *v10; // esi
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  IUniformRandomStream *v13; // ecx
  double v14; // st7
  float v15; // [esp+50h] [ebp-38h]
  float v16; // [esp+54h] [ebp-34h]
  float dir; // [esp+68h] [ebp-20h]
  float dir_4; // [esp+6Ch] [ebp-1Ch]
  float dir_8; // [esp+70h] [ebp-18h]
  float x; // [esp+80h] [ebp-8h]
  float y; // [esp+80h] [ebp-8h]
  float z; // [esp+80h] [ebp-8h]
  float v23; // [esp+80h] [ebp-8h]
  CSmartPtr<CSimple3DEmitter,CRefCountAccessor> pGlassEmitter; // [esp+84h] [ebp-4h] BYREF

  CSimple3DEmitter::Create(result: &pGlassEmitter, pDebugName: "HunterDamage");
  if ( pGlassEmitter.m_pObj != nullptr )
  {
    CParticleEffect::SetSortOrigin(this: pGlassEmitter.m_pObj, vSortOrigin: &data->m_vOrigin);
    ((void (__thiscall *)(CParticleCollision *, const CEffectData *, Vector *, int, int, int, int, int, int, int, int))pGlassEmitter.m_pObj->m_ParticleCollision.Setup_2)(
      a1: &pGlassEmitter.m_pObj->m_ParticleCollision,
      a2: data,
      a3: &data->m_vNormal,
      a4: 1065353216,
      a5: 1112014848,
      a6: 1137180672,
      a7: 1142292480,
      a8: 1045220557,
      a9: a2,
      a10: a3,
      a11: a1);
    v5 = 0;
    do
    {
      _RandomFloat(this: v4, a2: -32.0, a3: 32.0);
      _RandomFloat(this: v6, a2: -32.0, a3: 32.0);
      _RandomFloat(this: v7, a2: -32.0, a3: 32.0);
      m_pObj = pGlassEmitter.m_pObj;
      v9 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
      v10 = CParticleEffect::AddParticle(
              this: m_pObj,
              particleSize: 0x40u,
              material: g_Mat_Fleck_Antlion[v9],
              origin: nullptr);
      if ( v10 == nullptr )
        break;
      *(float *)&v10[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                    a1: random,
                                    a2: 0x40000000,
                                    a3: 1077936128);
      x = data->m_vNormal.x;
      dir = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: -1082130432,
              a3: 1065353216)
          + x;
      y = data->m_vNormal.y;
      dir_4 = ((double (__cdecl *)(int, int))random->RandomFloat)(a1: -1082130432, a2: 1065353216) + y;
      z = data->m_vNormal.z;
      dir_8 = ((double (__cdecl *)(int, int))random->RandomFloat)(a1: -1082130432, a2: 1065353216) + z;
      HIBYTE(v10[2].m_pSubTexture) = random->RandomInt(this: random, a2: 3, a3: 8);
      v23 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1112014848,
              a3: 1137180672);
      *(float *)&v10[1].m_pPrev = dir * v23;
      *(float *)&v10[1].m_pNext = dir_4 * v23;
      *(float *)&v10[1].m_pSubTexture = dir_8 * v23;
      v15 = _RandomFloat(this: v11, a2: 0.0, a3: 360.0);
      v16 = _RandomFloat(this: v12, a2: 0.0, a3: 360.0);
      v14 = _RandomFloat(this: v13, a2: 0.0, a3: 360.0);
      v10[1].m_Pos.x = v15;
      v10[1].m_Pos.y = v16;
      v10[1].m_Pos.z = v14;
      *(float *)&v10[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                    a1: random,
                                    a2: -1001914368,
                                    a3: 1145569280);
      ++v5;
      LOWORD(v10[2].m_pSubTexture) = -1;
      BYTE2(v10[2].m_pSubTexture) = -1;
      LOWORD(v10[2].m_Pos.x) = 16191;
      BYTE2(v10[2].m_Pos.x) = 63;
    }
    while ( v5 < 32 );
    if ( pGlassEmitter.m_pObj != nullptr )
      CParticleEffect::Release(this: pGlassEmitter.m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D65A0
// Name: void FX_BloodSpray(class Vector const __near &,class Vector const __near &,float,unsigned char,unsigned char,unsigned char,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_BloodSpray(
        const Vector *origin,
        const Vector *normal,
        float scale,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        char flags)
{
  float x; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float z; // xmm2_4
  float y; // xmm0_4
  float v12; // xmm2_4
  char v13; // cl
  CTrailParticles *v14; // eax
  CTrailParticles *v15; // eax
  CParticleEffect *v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  CParticleMgr *v20; // eax
  Particle *v21; // eax
  IUniformRandomStream *v22; // ecx
  Particle *v23; // esi
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  Particle *v27; // xmm1_4
  Particle *v28; // xmm2_4
  int v29; // ecx
  int v30; // edx
  float v31; // eax
  Particle *v32; // eax
  IUniformRandomStream *v33; // ecx
  Particle *v34; // esi
  IUniformRandomStream *v35; // ecx
  IUniformRandomStream *v36; // ecx
  double v37; // st7
  float v38; // xmm0_4
  float (__thiscall *v39)(IUniformRandomStream *, float, float); // edx
  double v40; // st7
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // eax
  int v46; // edx
  CSimpleEmitter *v47; // eax
  CParticleEffect *v48; // esi
  bool v49; // zf
  CParticleMgr *v50; // eax
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  Particle *v56; // eax
  IUniformRandomStream *v57; // ecx
  Particle *v58; // esi
  IUniformRandomStream *v59; // ecx
  IUniformRandomStream *v60; // ecx
  int v61; // eax
  Particle *v62; // xmm1_4
  Particle *v63; // xmm2_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  int v66; // ecx
  float v67; // xmm0_4
  bool v68; // cc
  int v69; // edx
  float v70; // xmm0_4
  char v71; // al
  CParticleMgr *v72; // eax
  float v73; // xmm3_4
  float v74; // xmm2_4
  float v75; // xmm1_4
  Particle *v76; // eax
  Particle *v77; // esi
  IUniformRandomStream *v78; // ecx
  IUniformRandomStream *v79; // ecx
  IUniformRandomStream *v80; // ecx
  int v81; // eax
  float v82; // xmm0_4
  float v83; // xmm2_4
  float v84; // xmm2_4
  float v85; // xmm0_4
  float v86; // xmm1_4
  int v87; // eax
  float v88; // xmm1_4
  int v89; // ecx
  float v90; // xmm1_4
  char v91; // al
  float offDir_8; // [esp+A8h] [ebp-70h]
  Vector worldLight; // [esp+ACh] [ebp-6Ch] BYREF
  Vector bbMax; // [esp+B8h] [ebp-60h] BYREF
  Vector bbMin; // [esp+C4h] [ebp-54h] BYREF
  Vector color; // [esp+D0h] [ebp-48h]
  Vector up; // [esp+DCh] [ebp-3Ch]
  Vector right; // [esp+E8h] [ebp-30h]
  Vector offset; // [esp+F4h] [ebp-24h] BYREF
  int v100; // [esp+100h] [ebp-18h]
  float v101; // [esp+104h] [ebp-14h]
  int v102; // [esp+108h] [ebp-10h]
  CParticleSubTexture *hMaterial; // [esp+10Ch] [ebp-Ch]
  CParticleEffect *v104; // [esp+110h] [ebp-8h]
  float colorRamp; // [esp+114h] [ebp-4h]

  if ( !UTIL_IsLowViolence() )
  {
    engine->GetLightForPoint(this: engine, result: &worldLight, a3: origin, a4: true);
    color.x = (float)((float)r * worldLight.x) * 0.0039215689;
    color.y = (float)((float)g * worldLight.y) * 0.0039215689;
    x = normal->x;
    color.z = (float)((float)b * worldLight.z) * 0.0039215689;
    if ( x == 0.0 && normal->y == 0.0 && normal->z == 1.0 )
    {
      z = normal->z;
      right.z = 1.0;
      y = normal->y;
      v12 = z * 0.0;
      right.x = 0.0;
      right.y = 0.0;
      up.x = v12 - y;
      up.y = x - v12;
      up.z = (float)(y * 0.0) - (float)(x * 0.0);
    }
    else
    {
      v8 = normal->y;
      v9 = normal->z;
      right.z = (float)(x * 0.0) - (float)(v8 * 0.0);
      right.y = (float)(v9 * 0.0) - x;
      right.x = v8 - (float)(v9 * 0.0);
      up.x = (float)(right.y * v9) - (float)(right.z * v8);
      up.y = (float)(right.z * x) - (float)(v9 * right.x);
      up.z = (float)(v8 * right.x) - (float)(right.y * x);
    }
    v13 = flags;
    if ( (flags & 1) != 0 )
    {
      v14 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
      if ( v14 == nullptr )
        return;
      v15 = CTrailParticles::CTrailParticles(this: v14, pDebugName: "blooddrops");
      v16 = v15;
      v104 = v15;
      if ( v15 == nullptr )
        return;
      CParticleEffect::AddRef(this: v15);
      CParticleEffect::SetSortOrigin(this: v16, vSortOrigin: origin);
      v16[1].m_ParticleEffect.m_LastMin.y = 600.0;
      v17 = origin->x;
      bbMax.x = origin->x + 32.0;
      v18 = origin->y;
      bbMax.y = v18 + 32.0;
      v19 = origin->z;
      bbMax.z = v19 + 32.0;
      bbMin.x = v17 - 32.0;
      bbMin.y = v18 - 32.0;
      bbMin.z = v19 - 32.0;
      CParticleEffectBinding::SetBBox(this: &v16->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
      LODWORD(v16[1].m_ParticleEffect.m_LastMax.y) |= 1u;
      v16[1].m_ParticleEffect.m_LastMax.z = 0.2;
      v20 = ParticleMgr();
      hMaterial = CParticleMgr::GetPMaterial(this: v20, pMaterialName: "effects/blood_drop");
      colorRamp = 0.0;
      while ( 1 )
      {
        offset = *origin;
        *(float *)&v102 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: -1090519040,
                            a3: 1056964608);
        offset.x = (float)((float)(*(float *)&v102 * right.x) * scale) + offset.x;
        offset.y = (float)((float)(right.y * *(float *)&v102) * scale) + offset.y;
        offset.z = (float)((float)(right.z * *(float *)&v102) * scale) + offset.z;
        *(float *)&v102 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: -1090519040,
                            a3: 1056964608);
        offset.x = (float)((float)(*(float *)&v102 * up.x) * scale) + offset.x;
        offset.y = (float)((float)(up.y * *(float *)&v102) * scale) + offset.y;
        offset.z = (float)((float)(up.z * *(float *)&v102) * scale) + offset.z;
        v21 = CParticleEffect::AddParticle(this: v16, particleSize: 0x38u, material: hMaterial, origin: &offset);
        v23 = v21;
        if ( v21 == nullptr )
          break;
        v21[1].m_Pos.z = 0.0;
        bbMin.x = _RandomFloat(this: v22, a2: -0.30000001, a3: 0.30000001);
        bbMin.y = _RandomFloat(this: v24, a2: -0.30000001, a3: 0.30000001);
        bbMin.z = _RandomFloat(this: v25, a2: -0.30000001, a3: 0.30000001);
        RandomFloat = random->RandomFloat;
        bbMax.x = normal->x + bbMin.x;
        bbMax.y = bbMin.y + normal->y;
        bbMax.z = bbMin.z + normal->z;
        *(float *)&v102 = ((double (__cdecl *)(_DWORD, _DWORD))RandomFloat)(a1: scale * 4.0, a2: scale * 40.0);
        *(float *)&v27 = bbMax.x * *(float *)&v102;
        *(float *)&v28 = bbMax.y * *(float *)&v102;
        *(float *)&v23[1].m_pSubTexture = bbMax.z * *(float *)&v102;
        v23[1].m_pPrev = v27;
        v23[1].m_pNext = v28;
        *(float *)&v23[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: 1082130432,
                                            a3: 1098907648)
                                        * scale
                                        + *(float *)&v23[1].m_pSubTexture;
        *(float *)&v23[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1040187392,
                                      a3: 1049414861)
                                  * scale;
        *(float *)&v23[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1017370378,
                                      a3: 1022739087)
                                  * scale;
        v23[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1056964608,
                           a3: 1065353216);
        v29 = (int)(float)(color.x * 255.0);
        v30 = (int)(float)(color.y * 255.0);
        BYTE2(v23[1].m_Pos.x) = (int)(float)(color.z * 255.0);
        LODWORD(v31) = LODWORD(colorRamp) + 1;
        LOBYTE(v23[1].m_Pos.x) = v29;
        BYTE1(v23[1].m_Pos.x) = v30;
        HIBYTE(v23[1].m_Pos.x) = -1;
        colorRamp = v31;
        if ( SLODWORD(v31) >= 14 )
          break;
        v16 = v104;
      }
      colorRamp = 0.0;
      do
      {
        offset = *origin;
        *(float *)&v102 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: -1090519040,
                            a3: 1056964608);
        offset.x = (float)((float)(*(float *)&v102 * right.x) * scale) + offset.x;
        offset.y = (float)((float)(right.y * *(float *)&v102) * scale) + offset.y;
        offset.z = (float)((float)(right.z * *(float *)&v102) * scale) + offset.z;
        *(float *)&v102 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: -1090519040,
                            a3: 1056964608);
        offset.x = (float)((float)(*(float *)&v102 * up.x) * scale) + offset.x;
        offset.y = (float)((float)(up.y * *(float *)&v102) * scale) + offset.y;
        offset.z = (float)((float)(up.z * *(float *)&v102) * scale) + offset.z;
        v32 = CParticleEffect::AddParticle(this: v104, particleSize: 0x38u, material: hMaterial, origin: &offset);
        v34 = v32;
        if ( v32 == nullptr )
          break;
        v32[1].m_Pos.z = 0.0;
        bbMin.x = _RandomFloat(this: v33, a2: -1.0, a3: 1.0);
        bbMin.y = _RandomFloat(this: v35, a2: -1.0, a3: 1.0);
        v37 = _RandomFloat(this: v36, a2: -1.0, a3: 1.0);
        v38 = normal->x + bbMin.x;
        bbMax.z = v37 + normal->z;
        v39 = random->RandomFloat;
        bbMax.x = v38;
        bbMax.y = bbMin.y + normal->y;
        v40 = ((double (__cdecl *)(_DWORD, int))v39)(a1: 0, a2: 1065353216);
        offDir_8 = v40 + bbMax.z;
        *(float *)&v102 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                            a1: random,
                            a2: scale * 2.0,
                            a3: scale * 25.0);
        v41 = *(float *)&v102;
        v42 = bbMax.x;
        v43 = bbMax.y;
        *(float *)&v34[1].m_pSubTexture = offDir_8 * *(float *)&v102;
        *(float *)&v34[1].m_pPrev = v42 * v41;
        *(float *)&v34[1].m_pNext = v43 * v41;
        *(float *)&v34[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: 1082130432,
                                            a3: 1098907648)
                                        * scale
                                        + *(float *)&v34[1].m_pSubTexture;
        *(float *)&v34[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1048576000,
                                      a3: 1052770304)
                                  * scale;
        *(float *)&v34[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 992204554,
                                      a3: 1000593162)
                                  * scale;
        v34[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1056964608,
                           a3: 1065353216);
        v44 = color.y;
        LOBYTE(v34[1].m_Pos.x) = (int)(float)(color.x * 255.0);
        LODWORD(v45) = LODWORD(colorRamp) + 1;
        v46 = (int)(float)(color.z * 255.0);
        BYTE1(v34[1].m_Pos.x) = (int)(float)(v44 * 255.0);
        BYTE2(v34[1].m_Pos.x) = v46;
        HIBYTE(v34[1].m_Pos.x) = -1;
        colorRamp = v45;
      }
      while ( SLODWORD(v45) < 24 );
      CParticleEffect::Release(this: v104);
      v13 = flags;
    }
    v102 = v13 & 2;
    if ( (v13 & 2) != 0 || (v13 & 4) != 0 )
    {
      v47 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x10Cu);
      v48 = v47;
      v104 = v47;
      if ( v47 != nullptr )
      {
        CSimpleEmitter::CSimpleEmitter(this: v47, pDebugName: "bloodgore");
        v48->__vftable = (CParticleEffect_vtbl *)&CBloodSprayEmitter::`vftable';
        CParticleEffect::AddRef(this: v48);
        CParticleEffect::SetSortOrigin(this: v48, vSortOrigin: origin);
        v49 = v102 == 0;
        v48[1].m_ParticleEffect.__vftable = nullptr;
        if ( !v49 )
        {
          v50 = ParticleMgr();
          v51 = scale * 0.5;
          hMaterial = CParticleMgr::GetPMaterial(this: v50, pMaterialName: "effects/blood_gore");
          v101 = scale * 0.5;
          v102 = 6;
          while ( 1 )
          {
            v52 = origin->x;
            v53 = normal->x * v51;
            v54 = (float)(v51 * normal->y) + origin->y;
            v55 = (float)(v51 * normal->z) + origin->z;
            offset.y = v54;
            offset.x = v52 + v53;
            offset.z = v55;
            colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                          a1: random,
                          a2: -1090519040,
                          a3: 1056964608);
            offset.x = (float)((float)(colorRamp * right.x) * scale) + offset.x;
            offset.y = (float)((float)(right.y * colorRamp) * scale) + offset.y;
            offset.z = (float)((float)(right.z * colorRamp) * scale) + offset.z;
            colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                          a1: random,
                          a2: -1090519040,
                          a3: 1056964608);
            offset.x = (float)((float)(colorRamp * up.x) * scale) + offset.x;
            offset.y = (float)((float)(up.y * colorRamp) * scale) + offset.y;
            offset.z = (float)((float)(up.z * colorRamp) * scale) + offset.z;
            v56 = CParticleEffect::AddParticle(this: v48, particleSize: 0x3Cu, material: hMaterial, origin: &offset);
            v58 = v56;
            if ( v56 != nullptr )
            {
              v56[1].m_Pos.z = 0.0;
              v56[1].m_Pos.y = 0.30000001;
              *(float *)&v56[1].m_pPrev = _RandomFloat(this: v57, a2: -0.2, a3: 0.2);
              *(float *)&v58[1].m_pNext = _RandomFloat(this: v59, a2: -0.2, a3: 0.2);
              *(float *)&v58[1].m_pSubTexture = _RandomFloat(this: v60, a2: -0.2, a3: 0.2);
              v61 = ((int (__thiscall *)(IUniformRandomStream *, int))random->RandomInt)(a1: random, a2: 10);
              *(float *)&v62 = (float)(normal->x * (float)v61) + *(float *)&v58[1].m_pPrev;
              *(float *)&v63 = (float)((float)v61 * normal->y) + *(float *)&v58[1].m_pNext;
              *(float *)&v58[1].m_pSubTexture = (float)((float)v61 * normal->z) + *(float *)&v58[1].m_pSubTexture;
              v58[1].m_pPrev = v62;
              v58[1].m_pNext = v63;
              colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: 1061158912,
                            a3: 1067450368);
              v64 = colorRamp;
              v65 = color.x * colorRamp;
              if ( (float)(color.x * colorRamp) > 1.0 )
                v65 = 1.0;
              v66 = (int)(float)(v65 * 255.0);
              v67 = color.y * colorRamp;
              v68 = (float)(color.y * colorRamp) <= 1.0;
              LOBYTE(v58[2].m_pPrev) = v66;
              if ( !v68 )
                v67 = 1.0;
              v69 = (int)(float)(v67 * 255.0);
              v70 = color.z * v64;
              v68 = (float)(color.z * v64) <= 1.0;
              BYTE1(v58[2].m_pPrev) = v69;
              if ( !v68 )
                v70 = 1.0;
              BYTE2(v58[2].m_pPrev) = (int)(float)(v70 * 255.0);
              v100 = (int)((double (__thiscall *)(IUniformRandomStream *, _DWORD))random->RandomFloat)(
                            a1: random,
                            a2: scale * 0.25);
              v71 = v100;
              BYTE1(v58[2].m_pNext) = v100;
              BYTE2(v58[2].m_pNext) = 2 * v71;
              HIBYTE(v58[2].m_pPrev) = random->RandomInt(this: random, a2: 200, a3: 255);
              LOBYTE(v58[2].m_pNext) = 0;
              v58[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
              v58[2].m_pSubTexture = nullptr;
            }
            v49 = v102-- == 1;
            v48 = v104;
            if ( v49 )
              break;
            v51 = v101;
          }
        }
        if ( (flags & 4) != 0 )
        {
          v72 = ParticleMgr();
          hMaterial = CParticleMgr::GetPMaterial(this: v72, pMaterialName: "effects/blood_puff");
          v102 = 6;
          do
          {
            v73 = origin->x;
            v74 = normal->x * scale;
            v75 = (float)(scale * normal->z) + origin->z;
            offset.y = (float)(scale * normal->y) + origin->y;
            offset.x = v73 + v74;
            offset.z = v75;
            *(float *)&v100 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: -1082130432,
                                a3: 1065353216);
            offset.x = (float)((float)(*(float *)&v100 * right.x) * scale) + offset.x;
            offset.y = (float)((float)(right.y * *(float *)&v100) * scale) + offset.y;
            offset.z = (float)((float)(right.z * *(float *)&v100) * scale) + offset.z;
            *(float *)&v100 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: -1082130432,
                                a3: 1065353216);
            offset.x = (float)((float)(*(float *)&v100 * up.x) * scale) + offset.x;
            offset.y = (float)((float)(up.y * *(float *)&v100) * scale) + offset.y;
            offset.z = (float)((float)(up.z * *(float *)&v100) * scale) + offset.z;
            v76 = CParticleEffect::AddParticle(this: v48, particleSize: 0x3Cu, material: hMaterial, origin: &offset);
            v77 = v76;
            if ( v76 != nullptr )
            {
              v76[1].m_Pos.z = 0.0;
              v76[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1056964608);
              *(float *)&v77[1].m_pPrev = _RandomFloat(this: v78, a2: -0.5, a3: 0.5);
              *(float *)&v77[1].m_pNext = _RandomFloat(this: v79, a2: -0.5, a3: 0.5);
              *(float *)&v77[1].m_pSubTexture = _RandomFloat(this: v80, a2: -0.5, a3: 0.5);
              v81 = random->RandomInt(this: random, a2: 100, a3: 200);
              v82 = (float)v81 * normal->z;
              v83 = (float)v81 * normal->y;
              *(float *)&v77[1].m_pPrev = (float)(normal->x * (float)v81) + *(float *)&v77[1].m_pPrev;
              *(float *)&v77[1].m_pNext = *(float *)&v77[1].m_pNext + v83;
              *(float *)&v77[1].m_pSubTexture = *(float *)&v77[1].m_pSubTexture + v82;
              colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: 1061158912,
                            a3: 1067450368);
              v84 = colorRamp;
              v85 = 1.0;
              v86 = color.x * colorRamp;
              if ( (float)(color.x * colorRamp) > 1.0 )
                v86 = 1.0;
              v87 = (int)(float)(v86 * 255.0);
              v88 = color.y * colorRamp;
              v68 = (float)(color.y * colorRamp) <= 1.0;
              LOBYTE(v77[2].m_pPrev) = v87;
              if ( !v68 )
                v88 = 1.0;
              v89 = (int)(float)(v88 * 255.0);
              v90 = color.z * v84;
              v68 = (float)(color.z * v84) <= 1.0;
              BYTE1(v77[2].m_pPrev) = v89;
              if ( v68 )
                v85 = v90;
              BYTE2(v77[2].m_pPrev) = (int)(float)(v85 * 255.0);
              v100 = (int)((double (__thiscall *)(IUniformRandomStream *, _DWORD))random->RandomFloat)(
                            a1: random,
                            a2: scale * 1.5);
              v91 = v100;
              BYTE1(v77[2].m_pNext) = v100;
              BYTE2(v77[2].m_pNext) = 4 * v91;
              HIBYTE(v77[2].m_pPrev) = random->RandomInt(this: random, a2: 80, a3: 128);
              LOBYTE(v77[2].m_pNext) = 0;
              v77[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
              v77[2].m_pSubTexture = nullptr;
            }
            v49 = v102-- == 1;
            v48 = v104;
          }
          while ( !v49 );
        }
        CParticleEffect::Release(this: v48);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7690
// Name: void FX_BloodBulletImpact(class Vector const __near &,class Vector const __near &,float,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_BloodBulletImpact(
        int a1@<edi>,
        const Vector *origin,
        const Vector *normal,
        float scale,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // al
  CSimpleEmitter *v10; // eax
  CParticleEffect *v11; // esi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  IUniformRandomStream *v15; // ecx
  CParticleMgr *v16; // eax
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  Particle *v25; // eax
  Particle *v26; // esi
  CParticleEffect *v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  int v32; // ecx
  float v33; // xmm0_4
  bool v34; // cc
  int v35; // edx
  float v36; // xmm0_4
  char v37; // al
  CParticleMgr *v38; // eax
  float v39; // xmm0_4
  float v40; // xmm1_4
  Particle *v41; // eax
  Particle *v42; // esi
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm3_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  double v47; // st7
  float v48; // xmm1_4
  float v49; // xmm0_4
  int v50; // eax
  float v51; // xmm0_4
  int v52; // ecx
  float v53; // xmm0_4
  char v54; // al
  CTrailParticles *v55; // eax
  CTrailParticles *v56; // eax
  CParticleEffect *v57; // esi
  void (__thiscall *SimulateParticles)(struct CParticleEffect *, CParticleSimulateIterator *); // edx
  CParticleMgr *v59; // eax
  int v60; // ebx
  Particle *v61; // eax
  IUniformRandomStream *v62; // ecx
  Particle *v63; // esi
  IUniformRandomStream *v64; // ecx
  IUniformRandomStream *v65; // ecx
  float v66; // xmm3_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  int v69; // edx
  float v70; // xmm1_4
  Vector bbMax; // [esp+8Ch] [ebp-50h] BYREF
  Vector worldLight; // [esp+98h] [ebp-44h] BYREF
  Vector dir; // [esp+A4h] [ebp-38h] BYREF
  Vector color; // [esp+B0h] [ebp-2Ch]
  Vector offset; // [esp+BCh] [ebp-20h] BYREF
  float v76; // [esp+C8h] [ebp-14h]
  CParticleEffect *v77; // [esp+CCh] [ebp-10h]
  CParticleEffect *v78; // [esp+D0h] [ebp-Ch]
  int v79; // [esp+D4h] [ebp-8h]
  float colorRamp; // [esp+D8h] [ebp-4h]

  if ( !UTIL_IsLowViolence() )
  {
    ((void (__thiscall *)(IVEngineClient *, Vector *, const Vector *, int, int))engine->GetLightForPoint)(
      a1: engine,
      a2: &worldLight,
      a3: origin,
      a4: 1,
      a5: a1);
    if ( *(int *)(gpGlobals.m_Index + 20) <= 1 )
    {
      v9 = b;
      v8 = g;
      v7 = r;
    }
    else
    {
      worldLight.x = 1.0;
      worldLight.y = 1.0;
      worldLight.z = 1.0;
      v7 = 96;
      v8 = 0;
      v9 = 10;
    }
    color.x = (float)((float)v7 * worldLight.x) * 0.0039215689;
    color.y = (float)((float)v8 * worldLight.y) * 0.0039215689;
    color.z = (float)((float)v9 * worldLight.z) * 0.0039215689;
    v10 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x10Cu);
    v11 = v10;
    v78 = v10;
    if ( v10 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v10, pDebugName: "bloodgore");
      v11->__vftable = (CParticleEffect_vtbl *)&CBloodSprayEmitter::`vftable';
      CParticleEffect::AddRef(this: v11);
      CParticleEffect::SetSortOrigin(this: v11, vSortOrigin: origin);
      v11[1].m_ParticleEffect.__vftable = (IClientRenderable_vtbl *)1128792064;
      x = origin->x;
      bbMax.x = origin->x + 16.0;
      y = origin->y;
      bbMax.y = y + 16.0;
      z = origin->z;
      bbMax.z = z + 16.0;
      dir.x = x - 16.0;
      dir.y = y - 16.0;
      dir.z = z - 16.0;
      CParticleEffectBinding::SetBBox(this: &v11->m_ParticleEffect, bbMin: &dir, &bbMax, bDisableAutoUpdate: true);
      if ( g_Blood_Core == nullptr )
      {
        v16 = ParticleMgr();
        g_Blood_Core = CParticleMgr::GetPMaterial(this: v16, pMaterialName: "effects/blood_core");
      }
      bbMax.x = _RandomFloat(this: v15, a2: -0.5, a3: 0.5);
      bbMax.y = _RandomFloat(this: v17, a2: -0.5, a3: 0.5);
      bbMax.z = _RandomFloat(this: v18, a2: -0.5, a3: 0.5);
      v19 = normal->x;
      dir.x = normal->x * bbMax.x;
      v20 = normal->y;
      dir.y = v20 * bbMax.y;
      v21 = normal->z;
      dir.z = v21 * bbMax.z;
      v22 = origin->x + (float)(v19 * 2.0);
      v23 = origin->y + (float)(v20 * 2.0);
      v24 = origin->z + (float)(v21 * 2.0);
      offset.x = v22;
      offset.y = v23;
      offset.z = v24;
      v25 = CParticleEffect::AddParticle(this: v11, particleSize: 0x3Cu, material: g_Blood_Core, origin: &offset);
      v26 = v25;
      if ( v25 != nullptr )
      {
        v25[1].m_Pos.z = 0.0;
        v25[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1048576000,
                           a3: 1056964608);
        *(float *)&v77 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1098907648,
                           a3: 1107296256);
        v27 = v77;
        v28 = dir.y;
        v29 = dir.z;
        *(float *)&v26[1].m_pPrev = dir.x * *(float *)&v77;
        *(float *)&v26[1].m_pNext = v28 * *(float *)&v27;
        *(float *)&v26[1].m_pSubTexture = v29 * *(float *)&v27;
        *(float *)&v26[1].m_pSubTexture = *(float *)&v26[1].m_pSubTexture
                                        - ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: 1090519040,
                                            a3: 1098907648);
        colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1061158912,
                      a3: 0x40000000);
        v30 = colorRamp;
        v31 = color.x * colorRamp;
        if ( (float)(color.x * colorRamp) > 1.0 )
          v31 = 1.0;
        v32 = (int)(float)(v31 * 255.0);
        v33 = color.y * colorRamp;
        v34 = (float)(color.y * colorRamp) <= 1.0;
        LOBYTE(v26[2].m_pPrev) = v32;
        if ( !v34 )
          v33 = 1.0;
        v35 = (int)(float)(v33 * 255.0);
        v36 = color.z * v30;
        v34 = (float)(color.z * v30) <= 1.0;
        BYTE1(v26[2].m_pPrev) = v35;
        if ( !v34 )
          v36 = 1.0;
        BYTE2(v26[2].m_pPrev) = (int)(float)(v36 * 255.0);
        v37 = random->RandomInt(this: random, a2: 2, a3: 4);
        BYTE1(v26[2].m_pNext) = v37;
        BYTE2(v26[2].m_pNext) = 8 * v37;
        *(_WORD *)((char *)&v26[2].m_pPrev + 3) = 255;
        v26[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        v26[2].m_pSubTexture = nullptr;
      }
      if ( g_Blood_Gore == nullptr )
      {
        v38 = ParticleMgr();
        g_Blood_Gore = CParticleMgr::GetPMaterial(this: v38, pMaterialName: "effects/blood_gore");
      }
      v79 = 1;
      v77 = (CParticleEffect *)4;
      do
      {
        v39 = origin->y + (float)(normal->y * 2.0);
        v40 = origin->z + (float)(normal->z * 2.0);
        offset.x = origin->x + (float)(normal->x * 2.0);
        offset.y = v39;
        offset.z = v40;
        v41 = CParticleEffect::AddParticle(this: v78, particleSize: 0x3Cu, material: g_Blood_Gore, origin: &offset);
        v42 = v41;
        if ( v41 != nullptr )
        {
          v41[1].m_Pos.z = 0.0;
          v41[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1056964608,
                             a3: 1061158912);
          colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1098907648,
                        a3: 1107296256);
          v43 = colorRamp * dir.x;
          v44 = dir.z * colorRamp;
          v45 = (float)v79;
          *(float *)&v42[1].m_pNext = (float)(dir.y * colorRamp) * (float)v79;
          *(float *)&v42[1].m_pPrev = v45 * v43;
          *(float *)&v42[1].m_pSubTexture = v44 * v45;
          RandomFloat = random->RandomFloat;
          v76 = v45;
          v47 = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                  a1: random,
                  a2: 1107296256,
                  a3: 1115684864);
          *(float *)&v42[1].m_pSubTexture = *(float *)&v42[1].m_pSubTexture - v47 * v76;
          colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1061158912,
                        a3: 0x40000000);
          v48 = colorRamp;
          v49 = color.x * colorRamp;
          if ( (float)(color.x * colorRamp) > 1.0 )
            v49 = 1.0;
          v50 = (int)(float)(v49 * 255.0);
          v51 = color.y * colorRamp;
          v34 = (float)(color.y * colorRamp) <= 1.0;
          LOBYTE(v42[2].m_pPrev) = v50;
          if ( !v34 )
            v51 = 1.0;
          v52 = (int)(float)(v51 * 255.0);
          v53 = color.z * v48;
          v34 = (float)(color.z * v48) <= 1.0;
          BYTE1(v42[2].m_pPrev) = v52;
          if ( !v34 )
            v53 = 1.0;
          BYTE2(v42[2].m_pPrev) = (int)(float)(v53 * 255.0);
          v54 = random->RandomInt(this: random, a2: 2, a3: 4);
          BYTE1(v42[2].m_pNext) = v54;
          BYTE2(v42[2].m_pNext) = 4 * v54;
          *(_WORD *)((char *)&v42[2].m_pPrev + 3) = 255;
          v42[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          v42[2].m_pSubTexture = nullptr;
        }
        ++v79;
        v77 = (CParticleEffect *)((char *)v77 - 1);
      }
      while ( *(float *)&v77 != 0.0 );
      v55 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
      if ( v55 != nullptr )
      {
        v56 = CTrailParticles::CTrailParticles(this: v55, pDebugName: "blooddrops");
        v57 = v56;
        v77 = v56;
        if ( v56 != nullptr )
        {
          CParticleEffect::AddRef(this: v56);
          CParticleEffect::SetSortOrigin(this: v57, vSortOrigin: origin);
          SimulateParticles = v57->__vftable[1].SimulateParticles;
          v57[1].m_ParticleEffect.m_LastMin.y = 400.0;
          ((void (__thiscall *)(CParticleEffect *))SimulateParticles)(a1: v57);
          if ( g_Blood_Drops == nullptr )
          {
            v59 = ParticleMgr();
            g_Blood_Drops = CParticleMgr::GetPMaterial(this: v59, pMaterialName: "effects/blood_drop");
          }
          v60 = 0;
          while ( 1 )
          {
            offset = *origin;
            v61 = CParticleEffect::AddParticle(this: v57, particleSize: 0x38u, material: g_Blood_Drops, origin: &offset);
            v63 = v61;
            if ( v61 == nullptr )
              break;
            v61[1].m_Pos.z = 0.0;
            bbMax.x = _RandomFloat(this: v62, a2: -1.0, a3: 1.0);
            bbMax.y = _RandomFloat(this: v64, a2: -1.0, a3: 1.0);
            bbMax.z = _RandomFloat(this: v65, a2: -1.0, a3: 1.0);
            v76 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 1115684864,
                    a3: 1124073472);
            v66 = v76;
            v67 = bbMax.y;
            v68 = bbMax.z;
            *(float *)&v63[1].m_pPrev = bbMax.x * v76;
            *(float *)&v63[1].m_pNext = v67 * v66;
            *(float *)&v63[1].m_pSubTexture = v68 * v66;
            *(float *)&v63[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: 1056964608,
                                          a3: 0x40000000);
            *(float *)&v63[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: 1028443341,
                                          a3: 1041865114);
            v63[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1048576000,
                               a3: 1056964608);
            v69 = (int)(float)(color.y * 255.0);
            v70 = color.z;
            LOBYTE(v63[1].m_Pos.x) = (int)(float)(color.x * 255.0);
            BYTE1(v63[1].m_Pos.x) = v69;
            ++v60;
            BYTE2(v63[1].m_Pos.x) = (int)(float)(v70 * 255.0);
            HIBYTE(v63[1].m_Pos.x) = -1;
            if ( v60 >= 8 )
              break;
            v57 = v77;
          }
          CParticleEffect::Release(this: v77);
        }
      }
      CParticleEffect::Release(this: v78);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7FF0
// Name: void BloodSprayCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BloodSprayCallback(const CEffectData *data)
{
  int v1; // eax
  colorentry_t color; // [esp+18h] [ebp-8h]

  v1 = 0;
  while ( bloodcolors[v1].index != data->m_nColor )
  {
    if ( (unsigned int)++v1 >= 4 )
    {
      *(_WORD *)&color.r = 255;
      color.b = -1;
      goto LABEL_5;
    }
  }
  color = bloodcolors[v1];
LABEL_5:
  FX_BloodSpray(
    origin: &data->m_vOrigin,
    normal: &data->m_vNormal,
    scale: data->m_flScale,
    r: color.r,
    g: color.g,
    b: color.b,
    flags: data->m_fFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100D8060
// Name: void BloodImpactCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BloodImpactCallback(const CEffectData *data)
{
  int m_nColor; // ecx
  unsigned int i; // edi
  int v3; // eax
  Vector vecPosition; // [esp+18h] [ebp-18h] BYREF
  Vector forward; // [esp+24h] [ebp-Ch] BYREF

  m_nColor = data->m_nColor;
  for ( i = 0; i < 3; ++i )
  {
    if ( bloodCallbacks[i].nColor == m_nColor )
    {
      forward.x = -data->m_vNormal.x;
      forward.y = -data->m_vNormal.y;
      forward.z = -data->m_vNormal.z;
      VectorAngles(&forward, angles: (QAngle *)&vecPosition);
      DispatchParticleEffect(
        pszParticleName: (&off_105A3478)[2 * i],
        vecOrigin: data->m_vOrigin,
        vecAngles: (QAngle)vecPosition,
        pEntity: nullptr,
        nSplitScreenPlayerSlot: -1);
      return;
    }
  }
  vecPosition = data->m_vOrigin;
  v3 = 0;
  while ( bloodcolors[v3].index != m_nColor )
  {
    if ( (unsigned int)++v3 >= 4 )
    {
      *(_WORD *)((char *)&forward.y + 1) = 255;
      HIBYTE(forward.y) = -1;
      goto LABEL_8;
    }
  }
  LODWORD(forward.y) = bloodcolors[v3];
LABEL_8:
  FX_BloodBulletImpact(
    a1: i,
    origin: &vecPosition,
    normal: &data->m_vNormal,
    scale: data->m_flScale,
    r: BYTE1(forward.y),
    g: BYTE2(forward.y),
    b: HIBYTE(forward.y));
}

//------------------------------------------------------------------------------
// Address: 0x10415C30
// Name: PrecacheEffectBloodSprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectBloodSprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectBloodSprayPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectBloodSprayPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415C70
// Name: bloodsprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int bloodsprayPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  bloodsprayPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&bloodsprayPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415CB0
// Name: BloodImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int BloodImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  BloodImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&BloodImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415CF0
// Name: HunterDamagePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int HunterDamagePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  HunterDamagePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&HunterDamagePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415C50
// Name: _dynamic_initializer_for__ClientEffectReg_BloodSprayCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_BloodSprayCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_BloodSprayCallback,
           pEffectName: "bloodspray",
           fn: BloodSprayCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415C90
// Name: _dynamic_initializer_for__ClientEffectReg_BloodImpactCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_BloodImpactCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_BloodImpactCallback,
           pEffectName: "BloodImpact",
           fn: BloodImpactCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415CD0
// Name: _dynamic_initializer_for__ClientEffectReg_HunterDamageCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_HunterDamageCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_HunterDamageCallback,
           pEffectName: "HunterDamage",
           fn: (void (__cdecl *)(const CEffectData *))HunterDamageCallback);
}
