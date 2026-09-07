// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_water.cpp
// Functions: 46
// ============================================================

#include "game\client\fx_water.h"

//------------------------------------------------------------------------------
// Address: 0x100DF2F0
// Name: public: virtual void PrecacheEffectSplashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectSplashPrecache::CResourcePrecacher::Cache(
        PrecacheEffectSplashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/splash1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/splash2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/splash4",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/slime1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF360
// Name: public: virtual void FX_WaterRipplePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FX_WaterRipplePrecache::CResourcePrecacher::Cache(
        FX_WaterRipplePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "water_splash_02_surface2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF390
// Name: public: virtual void FX_GunshotSplashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FX_GunshotSplashPrecache::CResourcePrecacher::Cache(
        FX_GunshotSplashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "water_splash_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "water_splash_02",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "water_splash_03",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Physics.WaterSplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF400
// Name: public: virtual void FX_GunshotSlimeSplashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FX_GunshotSlimeSplashPrecache::CResourcePrecacher::Cache(
        FX_GunshotSlimeSplashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "slime_splash_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "slime_splash_02",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "slime_splash_03",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Physics.WaterSplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF470
// Name: public: virtual void gunshotsplashPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall gunshotsplashPrecache::CResourcePrecacher::Cache(
        gunshotsplashPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: SHARED,
    a3: "FX_GunshotSlimeSplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: SHARED,
    a3: "FX_GunshotSplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF4B0
// Name: public: virtual void waterripplePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall waterripplePrecache::CResourcePrecacher::Cache(
        waterripplePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: SHARED,
    a3: "FX_WaterRipple",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100DF4E0
// Name: public: void CSplashParticle::SetClipHeight(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashParticle::SetClipHeight(CSplashParticle *this, float flClipHeight)
{
  this->m_bUseClipHeight = true;
  this->m_flClipHeight = flClipHeight;
}

//------------------------------------------------------------------------------
// Address: 0x100DF500
// Name: void UTIL_GetNormalizedColorTintAndLuminosity(class Vector const __near &,class Vector __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_GetNormalizedColorTintAndLuminosity(const Vector *color, Vector *tint, float *luminosity)
{
  float x; // xmm3_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm4_4

  if ( luminosity != nullptr )
    *luminosity = (float)((float)(color->y * 0.58999997) + (float)(color->x * 0.30000001)) + (float)(color->z * 0.11);
  if ( tint != nullptr )
  {
    x = color->x;
    if ( vec3_origin.x == color->x && vec3_origin.y == color->y && vec3_origin.z == color->z )
    {
      *tint = vec3_origin;
    }
    else
    {
      y = color->y;
      z = color->z;
      if ( y <= z )
        v6 = color->z;
      else
        v6 = color->y;
      if ( x <= v6 )
      {
        if ( y <= z )
          v7 = color->z;
        else
          v7 = color->y;
      }
      else
      {
        v7 = color->x;
      }
      tint->x = x * (float)(1.0 / v7);
      tint->y = y * (float)(1.0 / v7);
      tint->z = z * (float)(1.0 / v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF600
// Name: public: virtual float CSplashParticle::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSplashParticle::UpdateRoll(CSplashParticle *this, SimpleParticle *pParticle, float timeDelta)
{
  float v3; // xmm1_4
  float v4; // xmm0_4

  v3 = 0.5;
  v4 = (float)((float)(timeDelta * -4.0) + 1.0) * pParticle->m_flRollDelta;
  pParticle->m_flRoll = (float)(pParticle->m_flRollDelta * timeDelta) + pParticle->m_flRoll;
  pParticle->m_flRollDelta = v4;
  if ( COERCE_FLOAT(LODWORD(v4) & _mask__AbsFloat_) < 0.5 )
  {
    if ( v4 <= 0.0 )
      v3 = -0.5;
    pParticle->m_flRollDelta = v3;
  }
  return pParticle->m_flRoll;
}

//------------------------------------------------------------------------------
// Address: 0x100DF670
// Name: public: virtual void CSplashParticle::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashParticle::UpdateVelocity(CSplashParticle *this, SimpleParticle *pParticle, float timeDelta)
{
  float v3; // xmm0_4
  double v4; // xmm0_8
  __m128d v5; // xmm0
  double v6; // xmm0_8
  float v7; // xmm1_4

  v3 = timeDelta;
  if ( dtime == timeDelta )
  {
    v7 = decay;
  }
  else
  {
    dtime = timeDelta;
    __libm_sse2_log(a1: (__m128d)0x3F1A36E2E0000000uLL);
    *(float *)&v4 = v4;
    v5.m128d_f64[0] = (float)((float)(*(float *)&v4 * timeDelta) * 0.33333334);
    __libm_sse2_exp(a1: v5);
    v7 = v6;
    v3 = timeDelta;
    decay = v7;
  }
  pParticle->m_vecVelocity.x = pParticle->m_vecVelocity.x * v7;
  pParticle->m_vecVelocity.y = pParticle->m_vecVelocity.y * v7;
  pParticle->m_vecVelocity.z = (float)(pParticle->m_vecVelocity.z * v7) - (float)(v3 * 800.0);
}

//------------------------------------------------------------------------------
// Address: 0x100DF720
// Name: public: virtual void CSplashParticle::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplashParticle::SimulateParticles(CSplashParticle *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float timeDelta; // [esp+24h] [ebp+8h]

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  timeDelta = pIterator->m_flTimeDelta;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    do
    {
      ((void (__thiscall *)(CSplashParticle *, Particle *, _DWORD))this->UpdateVelocity)(
        a1: this,
        a2: m_pNext,
        a3: LODWORD(timeDelta));
      v6 = timeDelta;
      v7 = *(float *)&m_pNext[1].m_pNext;
      v8 = *(float *)&m_pNext[1].m_pSubTexture;
      m_pNext->m_Pos.x = (float)(*(float *)&m_pNext[1].m_pPrev * timeDelta) + m_pNext->m_Pos.x;
      m_pNext->m_Pos.y = m_pNext->m_Pos.y + (float)(v7 * timeDelta);
      m_pNext->m_Pos.z = m_pNext->m_Pos.z + (float)(v8 * timeDelta);
      if ( this->m_bUseClipHeight )
      {
        if ( this->m_flClipHeight > ((double (__thiscall *)(CSplashParticle *, Particle *))this->UpdateScale)(
                                      a1: this,
                                      a2: m_pNext)
                                  + m_pNext->m_Pos.z )
        {
          CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
          m_pNext = pIterator->m_pNextParticle;
          if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
            return;
          pIterator->m_pNextParticle = m_pNext->m_pNext;
          continue;
        }
        v6 = timeDelta;
      }
      m_pNext[1].m_Pos.z = v6 + m_pNext[1].m_Pos.z;
      ((void (__thiscall *)(CSplashParticle *, Particle *, _DWORD))this->UpdateRoll)(
        a1: this,
        a2: m_pNext,
        a3: LODWORD(v6));
      if ( m_pNext[1].m_Pos.z >= m_pNext[1].m_Pos.y )
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        return;
      pIterator->m_pNextParticle = m_pNext->m_pNext;
    }
    while ( m_pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DF850
// Name: void FX_WaterRipple(class Vector const __near &,float,class Vector __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_WaterRipple(const Vector *origin)
{
  float y; // xmm2_4
  float z; // xmm3_4
  CGameTrace tr; // [esp+0h] [ebp-6Ch] BYREF
  Vector startPos; // [esp+54h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+60h] [ebp-Ch] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_WaterRipple",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  y = origin->y;
  z = origin->z;
  startPos.x = origin->x;
  startPos.y = y;
  startPos.z = z + 8.0;
  vecAngles.x = startPos.x;
  vecAngles.y = y;
  vecAngles.z = z - 64.0;
  UTIL_TraceLine(
    vecAbsStart: &startPos,
    vecAbsEnd: (const Vector *)&vecAngles,
    mask: 0x4030u,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction < 1.0 )
  {
    startPos.x = tr.plane.normal.z;
    startPos.y = tr.plane.normal.y;
    startPos.z = tr.plane.normal.x;
    VectorAngles(forward: &startPos, angles: &vecAngles);
    DispatchParticleEffect(
      pszParticleName: "water_splash_02_surface2",
      vecOrigin: tr.endpos,
      vecAngles,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100DF960
// Name: void FX_GunshotSplashVisuals(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshotSplashVisuals(const Vector *origin, const Vector *normal, float scale)
{
  const char *v3; // [esp-28h] [ebp-40h]
  Vector forward; // [esp+0h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+Ch] [ebp-Ch] BYREF
  QAngle v6; // 0:^10.12

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_GunshotSplash",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( cl_show_splashes.m_pParent != nullptr && cl_show_splashes.m_pParent->m_Value.m_nValue != 0 )
  {
    forward.x = normal->z;
    forward.y = normal->y;
    forward.z = normal->x;
    VectorAngles(&forward, angles: &vecAngles);
    if ( scale >= 4.0 )
    {
      v6 = vecAngles;
      if ( scale >= 8.0 )
        v3 = "water_splash_03";
      else
        v3 = "water_splash_02";
    }
    else
    {
      v6 = vecAngles;
      v3 = "water_splash_01";
    }
    DispatchParticleEffect(
      pszParticleName: v3,
      vecOrigin: *origin,
      vecAngles: v6,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100DFA60
// Name: void RippleCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RippleCallback(const CEffectData *data)
{
  const CEffectData *v1; // esi
  Vector v2; // [esp+20h] [ebp-28h] BYREF
  Vector v3; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector color; // [esp+38h] [ebp-10h] BYREF
  float flScale; // [esp+44h] [ebp-4h]

  v1 = data;
  flScale = data->m_flScale * 0.125;
  *(_QWORD *)&color.x = *(_QWORD *)&data->m_vOrigin.x;
  color.z = data->m_vOrigin.z + 4.0;
  v3 = color;
  engine->GetLightForPoint(this: engine, result: &v2, a3: &v3, a4: true);
  UTIL_GetNormalizedColorTintAndLuminosity(color: &v2, tint: &color, luminosity: (float *)&data);
  color.x = (float)(color.x * 0.25) + 0.75;
  color.y = (float)(color.y * 0.25) + 0.75;
  color.z = (float)(color.z * 0.25) + 0.75;
  FX_WaterRipple(origin: &v1->m_vOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x100DFB80
// Name: public: virtual float CSplashParticle::UpdateAlpha(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSplashParticle::UpdateAlpha(CSplashParticle *this, const SimpleParticle *pParticle)
{
  bool v3; // zf
  int m_uchStartAlpha; // ecx
  float m_flClipHeight; // xmm2_4
  float z; // xmm0_4
  float v8; // xmm0_4
  float flAlpha; // [esp+4h] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-4h]

  v3 = !this->m_bUseClipHeight;
  m_uchStartAlpha = pParticle->m_uchStartAlpha;
  if ( v3 )
    return (double)m_uchStartAlpha * 0.0039215689
         + pParticle->m_flLifetime
         / pParticle->m_flDieTime
         * (0.0039215689 * (double)pParticle->m_uchEndAlpha - (double)m_uchStartAlpha * 0.0039215689);
  flAlpha = (float)m_uchStartAlpha * 0.0039215689;
  m_flClipHeight = this->m_flClipHeight;
  z = pParticle->m_Pos.z;
  v10 = m_flClipHeight
      - ((double (__thiscall *)(CSplashParticle *, const SimpleParticle *))this->UpdateScale)(a1: this, a2: pParticle)
      * 0.5;
  if ( m_flClipHeight == v10 )
  {
    if ( (float)(z - v10) < 0.0 )
      return 1.0 * flAlpha;
    else
      return 0.0 * flAlpha;
  }
  else
  {
    v8 = (float)(z - m_flClipHeight) / (float)(v10 - m_flClipHeight);
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
      return (float)(1.0 - v8) * flAlpha;
    }
    else
    {
      return (float)(1.0 - 0.0) * flAlpha;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFCC0
// Name: void FX_GunshotSplashSound(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshotSplashSound(const Vector *origin)
{
  EmitSound_t ep; // [esp+0h] [ebp-68h] BYREF
  CLocalPlayerFilter filter; // [esp+48h] [ebp-20h] BYREF

  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  ep.m_hSoundScriptHandle = -1;
  ep.m_nFlags = 0;
  ep.m_pflSoundDuration = nullptr;
  ep.m_bWarnOnDirectWaveReference = false;
  memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
  *(_WORD *)&ep.m_bEmitCloseCaption = 1;
  ep.m_nSoundEntryVersion = 1;
  ep.m_flSoundTime = 0.0;
  ep.m_nPitch = 100;
  ep.m_nSpeakerEntity = -1;
  ep.m_nChannel = 2;
  ep.m_pSoundName = "Physics.WaterSplash";
  ep.m_flVolume = 1.0;
  ep.m_SoundLevel = SNDLVL_NORM;
  ep.m_pOrigin = origin;
  C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100DFD60
// Name: void FX_GunshotSplash(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshotSplash(const Vector *origin, const Vector *normal, float scale)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_GunshotSplash",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( cl_show_splashes.m_pParent != nullptr && cl_show_splashes.m_pParent->m_Value.m_nValue != 0 )
  {
    FX_GunshotSplashVisuals(origin, normal, scale);
    FX_GunshotSplashSound(origin);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFDE0
// Name: void FX_GunshotSlimeSplash(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GunshotSlimeSplash(const Vector *origin, const Vector *normal, float scale)
{
  const char *v3; // [esp-28h] [ebp-B0h]
  EmitSound_t ep; // [esp+8h] [ebp-80h] BYREF
  CLocalPlayerFilter filter; // [esp+50h] [ebp-38h] BYREF
  Vector forward; // [esp+70h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+7Ch] [ebp-Ch] BYREF
  QAngle v8; // 0:^10.12

  if ( cl_show_splashes.m_pParent != nullptr && cl_show_splashes.m_pParent->m_Value.m_nValue != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "FX_GunshotSlimeSplash",
      a3: 0,
      a4: "Particle/Effect_Rendering",
      a5: false,
      a6: 4);
    forward.x = normal->z;
    forward.y = normal->y;
    forward.z = normal->x;
    VectorAngles(&forward, angles: &vecAngles);
    if ( scale >= 2.0 )
    {
      v8 = vecAngles;
      if ( scale >= 4.0 )
        v3 = "slime_splash_03";
      else
        v3 = "slime_splash_02";
    }
    else
    {
      v8 = vecAngles;
      v3 = "slime_splash_01";
    }
    DispatchParticleEffect(
      pszParticleName: v3,
      vecOrigin: *origin,
      vecAngles: v8,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_nSoundEntryVersion = 1;
    ep.m_flSoundTime = 0.0;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    ep.m_pflSoundDuration = nullptr;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_hSoundScriptHandle = -1;
    ep.m_nChannel = 2;
    ep.m_pSoundName = "Physics.WaterSplash";
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_NORM;
    ep.m_pOrigin = origin;
    C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DFF70
// Name: void SplashCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplashCallback(const CEffectData *data)
{
  bool v1; // zf
  float scale; // [esp+0h] [ebp-20h]
  Vector normal; // [esp+8h] [ebp-18h] BYREF
  Vector v4; // [esp+14h] [ebp-Ch] BYREF

  AngleVectors(angles: &data->m_vAngles, forward: &normal);
  v1 = (data->m_fFlags & 1) == 0;
  v4.x = 0.0;
  v4.y = 0.0;
  v4.z = 1.0;
  scale = data->m_flScale;
  if ( v1 )
    FX_GunshotSplash(origin: &data->m_vOrigin, normal: &v4, scale);
  else
    FX_GunshotSlimeSplash(origin: &data->m_vOrigin, normal: &v4, scale);
}

//------------------------------------------------------------------------------
// Address: 0x100DFFE0
// Name: void SplashQuietCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplashQuietCallback(const CEffectData *data)
{
  bool v1; // zf
  float scale; // [esp+0h] [ebp-20h]
  Vector normal; // [esp+8h] [ebp-18h] BYREF
  Vector v4; // [esp+14h] [ebp-Ch] BYREF

  AngleVectors(angles: &data->m_vAngles, forward: &normal);
  v1 = (data->m_fFlags & 1) == 0;
  v4.x = 0.0;
  v4.y = 0.0;
  v4.z = 1.0;
  scale = data->m_flScale;
  if ( v1 )
    FX_GunshotSplashVisuals(origin: &data->m_vOrigin, normal: &v4, scale);
  else
    FX_GunshotSlimeSplash(origin: &data->m_vOrigin, normal: &v4, scale);
}

//------------------------------------------------------------------------------
// Address: 0x100E0050
// Name: void GunshotSplashCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GunshotSplashCallback(const CEffectData *data)
{
  bool v1; // zf
  float scale; // [esp+0h] [ebp-10h]
  Vector normal; // [esp+4h] [ebp-Ch] BYREF

  v1 = (data->m_fFlags & 1) == 0;
  normal.x = 0.0;
  normal.y = 0.0;
  normal.z = 1.0;
  scale = data->m_flScale;
  if ( v1 )
    FX_GunshotSplash(origin: &data->m_vOrigin, &normal, scale);
  else
    FX_GunshotSlimeSplash(origin: &data->m_vOrigin, &normal, scale);
}

//------------------------------------------------------------------------------
// Address: 0x104160C0
// Name: PrecacheEffectSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectSplashPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectSplashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416110
// Name: FX_WaterRipplePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int FX_WaterRipplePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF258;
  FX_WaterRipplePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF258;
  dword_106EF258 = (int)&FX_WaterRipplePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416130
// Name: FX_GunshotSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int FX_GunshotSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF258;
  FX_GunshotSplashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF258;
  dword_106EF258 = (int)&FX_GunshotSplashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416150
// Name: FX_GunshotSlimeSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int FX_GunshotSlimeSplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF258;
  FX_GunshotSlimeSplashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF258;
  dword_106EF258 = (int)&FX_GunshotSlimeSplashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416190
// Name: watersplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int watersplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  watersplashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&watersplashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104161D0
// Name: watersplashquietPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int watersplashquietPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  watersplashquietPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&watersplashquietPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416210
// Name: gunshotsplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int gunshotsplashPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  gunshotsplashPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&gunshotsplashPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416250
// Name: waterripplePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int waterripplePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  waterripplePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&waterripplePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104160E0
// Name: _dynamic_initializer_for__cl_show_splashes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_show_splashes__()
{
  ConVar::ConVar(this: &cl_show_splashes, pName: "cl_show_splashes", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_show_splashes__);
}

//------------------------------------------------------------------------------
// Address: 0x10416170
// Name: _dynamic_initializer_for__ClientEffectReg_SplashCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_SplashCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_SplashCallback,
           pEffectName: "watersplash",
           fn: SplashCallback);
}

//------------------------------------------------------------------------------
// Address: 0x104161B0
// Name: _dynamic_initializer_for__ClientEffectReg_SplashQuietCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_SplashQuietCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_SplashQuietCallback,
           pEffectName: "watersplashquiet",
           fn: SplashQuietCallback);
}

//------------------------------------------------------------------------------
// Address: 0x104161F0
// Name: _dynamic_initializer_for__ClientEffectReg_GunshotSplashCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_GunshotSplashCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_GunshotSplashCallback,
           pEffectName: "gunshotsplash",
           fn: GunshotSplashCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10416230
// Name: _dynamic_initializer_for__ClientEffectReg_RippleCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_RippleCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_RippleCallback,
           pEffectName: "waterripple",
           fn: RippleCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10416270
// Name: _dynamic_initializer_for__g_GameTimescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameTimescale__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_GameTimescale, name: "CGameTimescale");
  g_GameTimescale.__vftable = (CGameTimescale_vtbl *)&CGameTimescale::`vftable';
  g_GameTimescale.m_flStartBlendRealtime = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_GameTimescale__);
}

//------------------------------------------------------------------------------
// Address: 0x104162A0
// Name: _dynamic_initializer_for__sv_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_timescale__()
{
  ConCommand::ConCommand(
    this: &sv_timescale,
    pName: "sv_timescale",
    callback: (void (__cdecl *)())SV_TimeScale,
    pHelpString: "Change the speed of the game.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x104162D0
// Name: _dynamic_initializer_for__userMessageRegister_CurrentTimescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserMessageRegister *dynamic_initializer_for__userMessageRegister_CurrentTimescale__()
{
  return CUserMessageRegister::CUserMessageRegister(
           this: &userMessageRegister_CurrentTimescale,
           pMessageName: "CurrentTimescale",
           pHookFn: __MsgFunc_CurrentTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x104162F0
// Name: _dynamic_initializer_for__userMessageRegister_DesiredTimescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserMessageRegister *dynamic_initializer_for__userMessageRegister_DesiredTimescale__()
{
  return CUserMessageRegister::CUserMessageRegister(
           this: &userMessageRegister_DesiredTimescale,
           pMessageName: "DesiredTimescale",
           pHookFn: __MsgFunc_DesiredTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x10416310
// Name: _dynamic_initializer_for__s_TraceFilter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTraceFilterSkipTwoEntities *dynamic_initializer_for__s_TraceFilter__()
{
  CTraceFilterSkipTwoEntities *v0; // esi
  int i; // edi
  CTraceFilterSkipTwoEntities *result; // eax

  v0 = &s_TraceFilter;
  for ( i = 7; i >= 0; --i )
  {
    result = CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
               this: v0,
               passentity: nullptr,
               passentity2: nullptr,
               collisionGroup: 0);
    v0->__vftable = (CTraceFilterSkipTwoEntities_vtbl *)&CTraceFilterSkipTwoEntitiesAndCheckTeamMask::`vftable';
    ++v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416340
// Name: _dynamic_initializer_for__sv_ladder_dampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_ladder_dampen__()
{
  ConVar::ConVar(
    this: &sv_ladder_dampen,
    pName: "sv_ladder_dampen",
    pDefaultValue: "0.2",
    flags: 0x2000,
    pHelpString: "Amount to dampen perpendicular movement on a ladder",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_ladder_dampen__);
}

//------------------------------------------------------------------------------
// Address: 0x10416390
// Name: _dynamic_initializer_for__sv_ladder_angle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_ladder_angle__()
{
  ConVar::ConVar(
    this: &sv_ladder_angle,
    pName: "sv_ladder_angle",
    pDefaultValue: "-0.707",
    flags: 0x2000,
    pHelpString: "Cos of angle of incidence to ladder perpendicular for applying ladder_dampen",
    bMin: true,
    fMin: -1.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_ladder_angle__);
}

//------------------------------------------------------------------------------
// Address: 0x104163E0
// Name: _dynamic_initializer_for__cl_pred_checkstuck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_pred_checkstuck__()
{
  ConVar::ConVar(
    this: &cl_pred_checkstuck,
    pName: "cl_pred_checkstuck",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Perform the additional 'stuck' traces on the client side during prediction.");
  return atexit(func: dynamic_atexit_destructor_for__cl_pred_checkstuck__);
}

//------------------------------------------------------------------------------
// Address: 0x10416410
// Name: _dynamic_initializer_for__sv_optimizedmovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_optimizedmovement__()
{
  ConVar::ConVar(this: &sv_optimizedmovement, pName: "sv_optimizedmovement", pDefaultValue: "1", flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__sv_optimizedmovement__);
}

//------------------------------------------------------------------------------
// Address: 0x10416440
// Name: _dynamic_initializer_for__g_Language__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Language__()
{
  ConVar::ConVar(this: &g_Language, pName: "g_Language", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_Language__);
}

//------------------------------------------------------------------------------
// Address: 0x10416470
// Name: _dynamic_initializer_for__sk_autoaim_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_autoaim_mode__()
{
  ConVar::ConVar(this: &sk_autoaim_mode, pName: "sk_autoaim_mode", pDefaultValue: "1", flags: 8320);
  return atexit(func: dynamic_atexit_destructor_for__sk_autoaim_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x104164A0
// Name: _dynamic_initializer_for____g_C_GameRulesProxyClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_GameRulesProxyClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_GameRulesProxyClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_GameRulesProxyClientClass;
  return result;
}
