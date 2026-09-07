// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_impact_effects.cpp
// Functions: 23
// ============================================================

#include "game\client\c_impact_effects.h"

//------------------------------------------------------------------------------
// Address: 0x10244370
// Name: public: virtual void PrecacheEffectImpactsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectImpactsPrecache::CResourcePrecacher::Cache(
        PrecacheEffectImpactsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_cement1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_cement2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_antlion1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_antlion2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_wood1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fleck_wood2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/blood2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/bloodspray",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/particle_noisesphere",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10244450
// Name: public: virtual void FX_CacheMaterialHandlesPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FX_CacheMaterialHandlesPrecache::CResourcePrecacher::Cache(
        FX_CacheMaterialHandlesPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_wood1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_Fleck_Wood);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_wood2",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)&g_Mat_Fleck_Wood[1]);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_cement1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_Fleck_Cement);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_cement2",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E3DC);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_antlion1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_Fleck_Antlion);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_antlion2",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E3E4);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_glass1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_Fleck_Glass);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_glass2",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E3EC);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_tile1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_Fleck_Tile);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/fleck_tile2",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)&g_Mat_Fleck_Tile[1]);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "particle/particle_smokegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_DustPuff);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "particle/particle_noisesphere",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)&dword_1066E3FC);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/blood",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_BloodPuff);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/blood2",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)&material);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/muzzleflash1",
    a4: bPrecache,
    a5: hResourceList,
    a6: (int *)g_Mat_SMG_Muzzleflash);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/muzzleflash2",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E40C);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/muzzleflash3",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E410);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_MATERIAL,
    a3: "effects/muzzleflash4",
    a4: bPrecache,
    a5: hResourceList,
    a6: &dword_1066E414);
}

//------------------------------------------------------------------------------
// Address: 0x10244600
// Name: public: virtual class ClientClass __near * C_TEGaussExplosion::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEGaussExplosion::GetClientClass(C_TEGaussExplosion *this)
{
  return &__g_C_TEGaussExplosionClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102446C0
// Name: void GetColorForSurface(class CGameTrace __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GetColorForSurface(int a1@<ebx>, CGameTrace *trace, Vector *color)
{
  float z; // ecx
  float v5; // eax
  float v6; // xmm3_4
  float v7; // xmm0_4
  int hitbox; // eax
  struct CBaseEntity *m_pEnt; // ecx
  int v10; // esi
  int v11; // eax
  const struct model_t *v12; // ebx
  int v13; // eax
  int v14; // eax
  double x; // xmm0_8
  double y; // xmm0_8
  double v17; // xmm0_8
  _BYTE end[24]; // [esp+0h] [ebp-24h] OVERLAPPED BYREF
  Vector diffuseColor; // [esp+18h] [ebp-Ch] BYREF
  CGameTrace *tracea; // [esp+2Ch] [ebp+8h]

  z = trace->endpos.z;
  v5 = trace->startpos.z;
  *(_QWORD *)&diffuseColor.x = *(_QWORD *)&trace->startpos.x;
  *(_QWORD *)&end[12] = *(_QWORD *)&trace->endpos.x;
  *(float *)&end[20] = z;
  diffuseColor.z = v5;
  v6 = trace->startpos.x + (float)((float)(*(float *)&end[12] - diffuseColor.x) * 1.1);
  *(float *)&end[4] = trace->startpos.y + (float)((float)(*(float *)&end[16] - diffuseColor.y) * 1.1);
  v7 = trace->startpos.z + (float)((float)(z - v5) * 1.1);
  *(float *)end = v6;
  *(float *)&end[8] = v7;
  if ( CGameTrace::DidHitWorld(this: trace) )
  {
    hitbox = trace->hitbox;
    if ( hitbox != 0 )
      staticpropmgr->GetStaticPropMaterialColorAndLighting(
        this: staticpropmgr,
        a2: trace,
        a3: hitbox - 1,
        a4: &diffuseColor,
        a5: (Vector *)&end[12]);
    else
      engine->TraceLineMaterialAndLighting(
        this: engine,
        a2: (const Vector *)trace,
        a3: (const Vector *)end,
        a4: &diffuseColor,
        a5: (Vector *)&end[12]);
  }
  else
  {
    m_pEnt = trace->m_pEnt;
    if ( m_pEnt == nullptr )
    {
      _Msg(a1: "Couldn't find surface in GetColorForSurface()\n");
      color->x = 255.0;
      color->y = 255.0;
      color->z = 255.0;
      return;
    }
    v10 = (*(int (__thiscall **)(struct CBaseEntity *, int))(*(_DWORD *)m_pEnt + 12))(a1: m_pEnt, a2: a1);
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 24))(a1: v10);
    v12 = modelinfo->GetModel(this: modelinfo, a2: v11);
    tracea = (CGameTrace *)modelinfo->__vftable;
    v13 = (*(int (__thiscall **)(int, CGameTrace *, Vector *, _BYTE *))(*(_DWORD *)v10 + 36))(
            a1: v10,
            a2: trace,
            a3: &diffuseColor,
            a4: &end[12]);
    v14 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v10 + 32))(a1: v10, a2: v13);
    ((void (__thiscall *)(IVModelInfoClient *, const struct model_t *, int))LODWORD(tracea[1].plane.normal.x))(
      a1: modelinfo,
      a2: v12,
      a3: v14);
  }
  x = diffuseColor.x;
  __libm_sse2_pow(x: *(long double *)end, y: *(long double *)&end[8]);
  *(float *)&x = x;
  color->x = *(float *)&x * *(float *)&end[12];
  y = diffuseColor.y;
  __libm_sse2_pow(x: *(long double *)end, y: *(long double *)&end[8]);
  *(float *)&y = y;
  color->y = *(float *)&y * *(float *)&end[16];
  v17 = diffuseColor.z;
  __libm_sse2_pow(x: *(long double *)end, y: *(long double *)&end[8]);
  *(float *)&v17 = v17;
  color->z = *(float *)&v17 * *(float *)&end[20];
}

//------------------------------------------------------------------------------
// Address: 0x102448E0
// Name: void GlassImpactCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlassImpactCallback(const CEffectData *data)
{
  float z; // ecx
  float v2; // edx
  int v3; // eax
  int i; // edi
  CSimple3DEmitter *m_pObj; // esi
  int v6; // eax
  Particle *v7; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st7
  float v11; // xmm0_4
  float v12; // xmm1_4
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  double v16; // st7
  float x; // xmm0_4
  float y; // xmm1_4
  int v19; // esi
  float v20; // xmm2_4
  int v21; // edi
  double v22; // st7
  IUniformRandomStream_vtbl *v23; // eax
  double v24; // st7
  IUniformRandomStream_vtbl *v25; // eax
  double v26; // st7
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  double v28; // st7
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // st7
  IUniformRandomStream_vtbl *v33; // edx
  double v34; // st7
  IUniformRandomStream_vtbl *v35; // edx
  double v36; // st7
  int (__thiscall *v37)(IUniformRandomStream *, int, int); // eax
  unsigned __int8 v38; // al
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  SimpleParticle newParticle; // [esp+148h] [ebp-84h] BYREF
  float flShardSize; // [esp+184h] [ebp-48h]
  Vector pos; // [esp+188h] [ebp-44h] BYREF
  Vector dir; // [esp+194h] [ebp-38h]
  Vector offset; // [esp+1A0h] [ebp-2Ch]
  Vector vecColor; // [esp+1ACh] [ebp-20h] BYREF
  Vector normal; // [esp+1B8h] [ebp-14h] BYREF
  CSmartPtr<CSimple3DEmitter,CRefCountAccessor> pGlassEmitter; // [esp+1C4h] [ebp-8h] BYREF
  IUniformRandomStream *v50; // [esp+1C8h] [ebp-4h]
  float colorRampb; // [esp+1D4h] [ebp+8h]
  float colorRampc; // [esp+1D4h] [ebp+8h]
  float colorRampd; // [esp+1D4h] [ebp+8h]
  float colorRampe; // [esp+1D4h] [ebp+8h]
  float colorRamp; // [esp+1D4h] [ebp+8h]
  float colorRampf; // [esp+1D4h] [ebp+8h]
  float colorRampa; // [esp+1D4h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GlassImpactCallback",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  z = data->m_vOrigin.z;
  v2 = data->m_vNormal.z;
  *(_QWORD *)&pos.x = *(_QWORD *)&data->m_vOrigin.x;
  pos.z = z;
  *(_QWORD *)&normal.x = *(_QWORD *)&data->m_vNormal.x;
  normal.z = v2;
  CSimple3DEmitter::Create(result: &pGlassEmitter, pDebugName: "FX_GlassImpact");
  CParticleEffect::SetSortOrigin(this: pGlassEmitter.m_pObj, vSortOrigin: &pos);
  engine->ComputeLighting(this: engine, a2: &pos, a3: nullptr, a4: true, a5: &vecColor, a6: nullptr);
  vecColor.x = (float)((float)(1.0 - vecColor.x) * 0.30000001) + vecColor.x;
  vecColor.y = (float)((float)(1.0 - vecColor.y) * 0.30000001) + vecColor.y;
  vecColor.z = (float)((float)(1.0 - vecColor.z) * 0.30000001) + vecColor.z;
  flShardSize = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 0x40000000,
                  a3: 1086324736);
  v3 = random->RandomInt(this: random, a2: 2, a3: 4);
  if ( v3 > 0 )
  {
    for ( i = v3; i != 0; --i )
    {
      m_pObj = pGlassEmitter.m_pObj;
      v6 = random->RandomInt(this: random, a2: 0, a3: 1);
      v7 = CParticleEffect::AddParticle(
             this: m_pObj,
             particleSize: 0x40u,
             material: g_Mat_Fleck_Glass[v6],
             origin: &pos);
      if ( v7 != nullptr )
      {
        *(float *)&v7[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1075838976,
                                     a3: 1084227584);
        v8 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1085485875,
               a3: 1061997773);
        colorRampb = v8 + normal.x;
        *(float *)&v7[1].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1065353216,
                                     a3: 1133903872)
                                 * colorRampb;
        v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1085485875,
               a3: 1061997773);
        colorRampc = v9 + normal.y;
        *(float *)&v7[1].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1065353216,
                                     a3: 1133903872)
                                 * colorRampc;
        v10 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1085485875,
                a3: 1061997773);
        colorRampd = v10 + normal.z;
        v11 = flShardSize;
        v12 = flShardSize * 0.5;
        *(float *)&v7[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                           a1: random,
                                           a2: 1065353216,
                                           a3: 1133903872)
                                       * colorRampd;
        v50 = (IUniformRandomStream *)(int)(((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                                              a1: random,
                                              a2: v11 * -0.5,
                                              a3: LODWORD(v12))
                                          + flShardSize);
        LOBYTE(v13) = (_BYTE)v50;
        HIBYTE(v7[2].m_pSubTexture) = (_BYTE)v50;
        offset.x = _RandomFloat(this: v13, a2: 0.0, a3: 360.0);
        offset.y = _RandomFloat(this: v14, a2: 0.0, a3: 360.0);
        v16 = _RandomFloat(this: v15, a2: 0.0, a3: 360.0);
        v7[1].m_Pos.x = offset.x;
        v7[1].m_Pos.y = offset.y;
        v7[1].m_Pos.z = v16;
        *(float *)&v7[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: -1001914368,
                                     a3: 1145569280);
        LOBYTE(v7[2].m_pSubTexture) = (int)(float)(vecColor.x * 200.0);
        BYTE1(v7[2].m_pSubTexture) = (int)(float)(vecColor.y * 200.0);
        BYTE2(v7[2].m_pSubTexture) = (int)(float)(vecColor.z * 210.0);
        LOBYTE(v7[2].m_Pos.x) = (int)(float)(vecColor.x * 200.0);
        BYTE1(v7[2].m_Pos.x) = (int)(float)(vecColor.y * 200.0);
        BYTE2(v7[2].m_Pos.x) = (int)(float)(vecColor.z * 210.0);
      }
    }
  }
  ((void (__thiscall *)(CParticleCollision *, Vector *, Vector *, int, int, int, int, int))pGlassEmitter.m_pObj->m_ParticleCollision.Setup_2)(
    a1: &pGlassEmitter.m_pObj->m_ParticleCollision,
    a2: &pos,
    a3: &normal,
    a4: 1061997773,
    a5: 1065353216,
    a6: 1133903872,
    a7: 1145569280,
    a8: 1050253722);
  x = pos.x + (float)(normal.x * 2.0);
  y = pos.y + (float)(normal.y * 2.0);
  v19 = 1;
  v20 = pos.z + (float)(normal.z * 2.0);
  offset.x = x;
  offset.y = y;
  offset.z = v20;
  newParticle.m_iFlags = 0;
  v21 = 4;
  while ( 1 )
  {
    newParticle.m_Pos.x = x;
    newParticle.m_flLifetime = 0.0;
    newParticle.m_Pos.y = y;
    newParticle.m_Pos.z = v20;
    newParticle.m_flDieTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1036831949,
                                a3: 1048576000);
    v22 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1085485875,
            a3: 1061997773);
    v23 = random->__vftable;
    dir.x = v22 + normal.x;
    v24 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v23->RandomFloat)(
            a1: random,
            a2: -1085485875,
            a3: 1061997773);
    v25 = random->__vftable;
    dir.y = v24 + normal.y;
    v26 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v25->RandomFloat)(
            a1: random,
            a2: -1085485875,
            a3: 1061997773);
    RandomInt = random->RandomInt;
    dir.z = v26 + normal.z;
    newParticle.m_uchStartSize = RandomInt(this: random, a2: 1, a3: 4);
    newParticle.m_uchEndSize = 8 * newParticle.m_uchStartSize;
    colorRampe = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                   a1: random,
                   a2: 1090519040,
                   a3: 1098907648);
    *(float *)&v50 = (float)v19;
    newParticle.m_vecVelocity.x = (float)(dir.x * colorRampe) * (float)v19;
    newParticle.m_vecVelocity.y = (float)(dir.y * colorRampe) * (float)v19;
    newParticle.m_vecVelocity.z = (float)(dir.z * colorRampe) * (float)v19;
    v28 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: 1098907648,
            a3: 1107296256);
    newParticle.m_vecVelocity.z = newParticle.m_vecVelocity.z - v28 * *(float *)&v50;
    newParticle.m_uchStartAlpha = random->RandomInt(this: random, a2: 128, a3: 255);
    newParticle.m_uchEndAlpha = 0;
    newParticle.m_flRoll = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                             a1: random,
                             a2: 0,
                             a3: 1135869952);
    newParticle.m_flRollDelta = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                  a1: random,
                                  a2: -1082130432,
                                  a3: 1065353216);
    colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1056964608,
                  a3: 1067450368);
    v29 = colorRamp * 64.0;
    if ( (float)(colorRamp * 64.0) <= 1.0 )
      v30 = colorRamp * 64.0;
    else
      v30 = 1.0;
    newParticle.m_uchColor[0] = (int)(float)(v30 * 255.0);
    if ( v29 > 1.0 )
      v29 = 1.0;
    v31 = colorRamp * 92.0;
    newParticle.m_uchColor[1] = (int)(float)(v29 * 255.0);
    if ( (float)(colorRamp * 92.0) > 1.0 )
      v31 = 1.0;
    newParticle.m_uchColor[2] = (int)(float)(v31 * 255.0);
    AddSimpleParticle(pParticle: &newParticle, hMaterial: g_Mat_BloodPuff[0], bInSkybox: false);
    x = offset.x;
    ++v19;
    if ( --v21 == 0 )
      break;
    y = offset.y;
    v20 = offset.z;
  }
  newParticle.m_Pos = offset;
  newParticle.m_flLifetime = 0.0;
  newParticle.m_flDieTime = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(
                              a1: random,
                              a2: 1065353216);
  v32 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1085485875,
          a3: 1061997773);
  v33 = random->__vftable;
  dir.x = v32 + normal.x;
  v34 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v33->RandomFloat)(
          a1: random,
          a2: -1085485875,
          a3: 1061997773);
  v35 = random->__vftable;
  dir.y = v34 + normal.y;
  v36 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v35->RandomFloat)(
          a1: random,
          a2: -1085485875,
          a3: 1061997773);
  v37 = random->RandomInt;
  dir.z = v36 + normal.z;
  v38 = v37(this: random, a2: 4, a3: 8);
  newParticle.m_uchEndSize = (int)(float)((float)v38 * 4.0);
  newParticle.m_uchStartSize = v38;
  colorRampf = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 0x40000000,
                 a3: 1090519040);
  newParticle.m_vecVelocity.x = colorRampf * dir.x;
  newParticle.m_vecVelocity.y = dir.y * colorRampf;
  newParticle.m_vecVelocity.z = dir.z * colorRampf;
  newParticle.m_vecVelocity.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                  a1: random,
                                  a2: -1073741824,
                                  a3: 0x40000000);
  newParticle.m_uchStartAlpha = random->RandomInt(this: random, a2: 32, a3: 64);
  newParticle.m_uchEndAlpha = 0;
  newParticle.m_flRoll = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                           a1: random,
                           a2: 0,
                           a3: 1135869952);
  newParticle.m_flRollDelta = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: -1073741824,
                                a3: 0x40000000);
  colorRampa = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1056964608,
                 a3: 1067450368);
  v39 = colorRampa * 64.0;
  if ( (float)(colorRampa * 64.0) <= 1.0 )
    v40 = colorRampa * 64.0;
  else
    v40 = 1.0;
  newParticle.m_uchColor[0] = (int)(float)(v40 * 255.0);
  if ( v39 > 1.0 )
    v39 = 1.0;
  v41 = colorRampa * 92.0;
  newParticle.m_uchColor[1] = (int)(float)(v39 * 255.0);
  if ( (float)(colorRampa * 92.0) > 1.0 )
    v41 = 1.0;
  newParticle.m_uchColor[2] = (int)(float)(v41 * 255.0);
  AddSimpleParticle(pParticle: &newParticle, hMaterial: g_Mat_DustPuff[0], bInSkybox: false);
  if ( pGlassEmitter.m_pObj != nullptr )
    CParticleEffect::Release(this: pGlassEmitter.m_pObj);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10245360
// Name: void FX_Blood(class Vector __near &,class Vector __near &,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_Blood(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        Vector *pos,
        Vector *dir,
        float r,
        float g,
        float b,
        float a)
{
  int v9; // edi
  Particle *v10; // eax
  Particle *v11; // esi
  double v12; // st7
  float z; // xmm2_4
  int v14; // xmm3_4
  Particle *v15; // xmm1_4
  int v16; // edi
  Particle *v17; // eax
  Particle *v18; // esi
  double v19; // st7
  float x; // xmm0_4
  float v21; // xmm2_4
  char v22; // cl
  char v23; // dl
  int v24; // xmm3_4
  Vector vDir; // [esp+78h] [ebp-18h] BYREF
  int i; // [esp+84h] [ebp-Ch]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+88h] [ebp-8h] BYREF
  char v28; // [esp+8Eh] [ebp-2h]
  char v29; // [esp+8Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Blood",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  CSimpleEmitter::Create(result: &pSimple, pDebugName: "FX_Blood");
  if ( pSimple.m_pObj != nullptr )
  {
    CParticleEffect::SetSortOrigin(this: pSimple.m_pObj, vSortOrigin: pos);
    vDir.x = ((double (__thiscall *)(IUniformRandomStream *, int, int, int, int, int))random->RandomFloat)(
               a1: random,
               a2: -1082130432,
               a3: 1065353216,
               a4: a2,
               a5: a3,
               a6: a1)
           + dir->x;
    vDir.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1082130432,
               a3: 1065353216)
           + dir->y;
    vDir.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1082130432,
               a3: 1065353216)
           + dir->z;
    VectorNormalize(vec: &vDir);
    v9 = 0;
    *(float *)&i = 0.0;
    while ( 1 )
    {
      v10 = CParticleEffect::AddParticle(
              this: pSimple.m_pObj,
              particleSize: 0x3Cu,
              material: g_Mat_BloodPuff[0],
              origin: pos);
      v11 = v10;
      if ( v10 == nullptr )
        break;
      v10[1].m_Pos.z = 0.0;
      v10[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1048576000,
                         a3: 1056964608);
      v12 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 0x40000000,
              a3: 1090519040);
      z = vDir.z;
      *(float *)&i = v12 * (double)i;
      v14 = i;
      *(float *)&v15 = *(float *)&i * vDir.y;
      *(float *)&v11[1].m_pPrev = vDir.x * *(float *)&i;
      v11[1].m_pNext = v15;
      *(float *)&v11[1].m_pSubTexture = z * *(float *)&v14;
      *(float *)&v11[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: -1040187392,
                                          a3: -1048576000)
                                      + *(float *)&v11[1].m_pSubTexture;
      LOBYTE(v11[2].m_pPrev) = (int)r;
      HIBYTE(v11[2].m_pPrev) = (int)a;
      BYTE1(v11[2].m_pPrev) = (int)g;
      BYTE2(v11[2].m_pPrev) = (int)b;
      LOWORD(v11[2].m_pNext) = 512;
      BYTE2(v11[2].m_pNext) = 8;
      v11[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
      *(float *)&v11[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: -1073741824,
                                          a3: 0x40000000);
      i = ++v9;
      if ( v9 >= 2 )
      {
        v16 = 0;
        *(float *)&i = 0.0;
        v29 = (int)g;
        v28 = (int)b;
        do
        {
          v17 = CParticleEffect::AddParticle(this: pSimple.m_pObj, particleSize: 0x3Cu, material: material, origin: pos);
          v18 = v17;
          if ( v17 == nullptr )
            break;
          v17[1].m_Pos.z = 0.0;
          v17[1].m_Pos.y = 0.5;
          v19 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1082130432,
                  a3: 1098907648);
          x = vDir.x;
          v21 = vDir.z;
          v22 = v29;
          v23 = v28;
          *(float *)&i = v19 * (double)i;
          v24 = i;
          *(float *)&v18[1].m_pNext = *(float *)&i * vDir.y;
          *(float *)&v18[1].m_pPrev = x * *(float *)&v24;
          *(float *)&v18[1].m_pSubTexture = v21 * *(float *)&v24;
          BYTE2(v18[2].m_pPrev) = v23;
          LOBYTE(v18[2].m_pPrev) = (int)r;
          BYTE1(v18[2].m_pPrev) = v22;
          *(Particle **)((char *)&v18[2].m_pPrev + 3) = (Particle *)134348928;
          v18[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v18[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1065353216,
                                              a3: 1082130432);
          i = ++v16;
        }
        while ( v16 < 2 );
        break;
      }
    }
    if ( pSimple.m_pObj != nullptr )
      CParticleEffect::Release(this: pSimple.m_pObj);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245710
// Name: void FX_GaussExplosion(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall FX_GaussExplosion(int a1@<ebx>, const Vector *pos, const Vector *dir)
{
  CTrailParticles *v4; // eax
  CTrailParticles *v5; // eax
  CTrailParticles *v6; // edi
  const Vector *v7; // esi
  Particle *v8; // eax
  IUniformRandomStream *v9; // ecx
  Particle *v10; // esi
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  double v13; // st7
  double v14; // st6
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float (__thiscall *v16)(IUniformRandomStream *, float, float); // eax
  Particle *v17; // xmm1_4
  CParticleSubTexture *v18; // xmm2_4
  Vector vDir; // [esp+50h] [ebp-18h] BYREF
  int numSparks; // [esp+5Ch] [ebp-Ch]
  float v22; // [esp+60h] [ebp-8h]
  CParticleSubTexture *hMaterial; // [esp+64h] [ebp-4h]
  float ia; // [esp+74h] [ebp+Ch]
  float ib; // [esp+74h] [ebp+Ch]
  float ic; // [esp+74h] [ebp+Ch]
  int i; // [esp+74h] [ebp+Ch]

  ia = dir->x;
  vDir.x = ((double (__stdcall *)(int, int, int))random->RandomFloat)(a1: -1082130432, a2: 1065353216, a3: a1) + ia;
  ib = dir->y;
  vDir.y = ((double (__stdcall *)(int, int))random->RandomFloat)(a1: -1082130432, a2: 1065353216) + ib;
  ic = dir->z;
  vDir.z = ((double (__stdcall *)(int, int))random->RandomFloat)(a1: -1082130432, a2: 1065353216) + ic;
  VectorNormalize(vec: &vDir);
  v4 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v4 != nullptr )
  {
    v5 = CTrailParticles::CTrailParticles(this: v4, pDebugName: "FX_ElectricSpark");
    v6 = v5;
    if ( v5 != nullptr )
    {
      CParticleEffect::AddRef(this: v5);
      v7 = pos;
      hMaterial = CParticleEffect::GetPMaterial(this: v6, name: "effects/spark");
      CParticleEffect::SetSortOrigin(this: v6, vSortOrigin: pos);
      v6->m_ParticleCollision.m_flGravity = 800.0;
      v6->m_fFlags |= 3u;
      ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, int, int, int, int, int))v6->m_ParticleCollision.Setup_2)(
        a1: &v6->m_ParticleCollision,
        a2: pos,
        a3: &vDir,
        a4: 1061997773,
        a5: 1124073472,
        a6: 1140850688,
        a7: 1145569280,
        a8: 1050253722);
      numSparks = random->RandomInt(this: random, a2: 16, a3: 32);
      i = 0;
      if ( numSparks <= 0 )
      {
LABEL_6:
        FX_ElectricSpark(pos: v7, nMagnitude: 1, nTrailLength: 1, vecDir: &vDir);
      }
      else
      {
        while ( 1 )
        {
          v8 = CParticleEffect::AddParticle(this: v6, particleSize: 0x38u, material: hMaterial, origin: v7);
          v10 = v8;
          if ( v8 == nullptr )
            break;
          v8[1].m_Pos.z = 0.0;
          vDir.x = _RandomFloat(this: v9, a2: -0.60000002, a3: 0.60000002);
          _RandomFloat(this: v11, a2: -0.60000002, a3: 0.60000002);
          v13 = _RandomFloat(this: v12, a2: -0.60000002, a3: 0.60000002);
          v14 = dir->x + vDir.x;
          LODWORD(vDir.y) = &vDir;
          vDir.x = v14;
          vDir.y = COERCE_FLOAT(&vDir) + dir->y;
          vDir.z = v13 + dir->z;
          VectorNormalize(vec: (Vector *)LODWORD(vDir.y));
          RandomFloat = random->RandomFloat;
          numSparks = 1082130432;
          vDir.z = 1.0;
          *(float *)&v10[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *))RandomFloat)(a1: random);
          v16 = random->RandomFloat;
          vDir.y = 0.1;
          vDir.x = 0.0099999998;
          *(float *)&v10[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *))v16)(a1: random);
          v10[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1048576000,
                             a3: 1065353216);
          v22 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1124073472,
                  a3: 1140850688);
          *(float *)&v17 = vDir.y * v22;
          *(float *)&v18 = vDir.z * v22;
          *(float *)&v10[1].m_pPrev = vDir.x * v22;
          v10[1].m_pNext = v17;
          v10[1].m_pSubTexture = v18;
          v10[1].m_Pos.x = NAN;
          v7 = pos;
          if ( ++i >= numSparks )
            goto LABEL_6;
        }
      }
      CParticleEffect::Release(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245A80
// Name: public: virtual void C_TEGaussExplosion::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_TEGaussExplosion::PostDataUpdate(
        C_TEGaussExplosion *this@<ecx>,
        int a2@<ebx>,
        DataUpdateType_t updateType)
{
  FX_GaussExplosion(a1: a2, pos: (const Vector *)&this->m_pNextDynamic, dir: (const Vector *)&this->m_nType);
}

//------------------------------------------------------------------------------
// Address: 0x10245AA0
// Name: void TE_GaussExplosion(class IRecipientFilter __near &,float,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall TE_GaussExplosion(
        int a1@<ebx>,
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir)
{
  FX_GaussExplosion(a1, pos, dir);
}

//------------------------------------------------------------------------------
// Address: 0x1042A8E0
// Name: PrecacheEffectImpactsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectImpactsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectImpactsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectImpactsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A960
// Name: FX_CacheMaterialHandlesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *FX_CacheMaterialHandlesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  FX_CacheMaterialHandlesPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &FX_CacheMaterialHandlesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A9A0
// Name: GlassImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int GlassImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  GlassImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&GlassImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AA10
// Name: DT_TEGaussExplosion::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGaussExplosion::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEGaussExplosion::g_RecvTable);
  return atexit(func: DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AA30
// Name: DT_TEGaussExplosion::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGaussExplosion::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEGaussExplosion::ignored>();
  DT_TEGaussExplosion::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104365C0
// Name: DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEGaussExplosion::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEGaussExplosion::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10244610
// Name: _C_TEGaussExplosion_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEGaussExplosion_CreateObject()
{
  return &_g_C_TEGaussExplosion.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042A900
// Name: _dynamic_initializer_for__fx_drawimpactdebris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fx_drawimpactdebris__()
{
  ConVar::ConVar(
    this: &fx_drawimpactdebris,
    pName: "fx_drawimpactdebris",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Draw impact debris effects.");
  return atexit(func: dynamic_atexit_destructor_for__fx_drawimpactdebris__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A930
// Name: _dynamic_initializer_for__fx_drawimpactdust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fx_drawimpactdust__()
{
  ConVar::ConVar(
    this: &fx_drawimpactdust,
    pName: "fx_drawimpactdust",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "Draw impact dust effects.");
  return atexit(func: dynamic_atexit_destructor_for__fx_drawimpactdust__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A980
// Name: _dynamic_initializer_for__ClientEffectReg_GlassImpactCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_GlassImpactCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_GlassImpactCallback,
           pEffectName: "GlassImpact",
           fn: GlassImpactCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042A9C0
// Name: _dynamic_initializer_for____g_C_TEGaussExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEGaussExplosion__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TEGaussExplosion);
  _g_C_TEGaussExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEGaussExplosion_vtbl *)&C_TEGaussExplosion::`vftable'{for `IClientUnknown'};
  _g_C_TEGaussExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEGaussExplosion::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEGaussExplosion__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A9F0
// Name: _dynamic_initializer_for____g_C_TEGaussExplosionClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEGaussExplosionClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEGaussExplosionClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEGaussExplosionClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AA40
// Name: _dynamic_initializer_for____g_C_MovieExplosionClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_MovieExplosionClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_MovieExplosionClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_MovieExplosionClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104365D0
// Name: _dynamic_atexit_destructor_for____g_C_TEGaussExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEGaussExplosion__()
{
  _g_C_TEGaussExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEGaussExplosion_vtbl *)&C_TEGaussExplosion::`vftable'{for `IClientUnknown'};
  _g_C_TEGaussExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEGaussExplosion::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEGaussExplosion);
}
