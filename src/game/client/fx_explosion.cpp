// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_explosion.cpp
// Functions: 40
// ============================================================

#include "game\client\fx_explosion.h"

//------------------------------------------------------------------------------
// Address: 0x100D8180
// Name: public: virtual void PrecacheEffectExplosionPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectExplosionPrecache::CResourcePrecacher::Cache(
        PrecacheEffectExplosionPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fire_cloud1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fire_cloud2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fire_embers1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fire_embers2",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/fire_embers3",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/splash3",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/splashwake1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/particle_smokegrenade",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/particle_smokegrenade1",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D8250
// Name: public: virtual float CExplosionParticle::UpdateAlpha(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CExplosionParticle::UpdateAlpha(CExplosionParticle *this, const SimpleParticle *pParticle)
{
  return Bias(x: 1.0 - (float)(pParticle->m_flLifetime / pParticle->m_flDieTime), biasAmt: 0x3E800000u);
}

//------------------------------------------------------------------------------
// Address: 0x100D8290
// Name: class C_BaseExplosionEffect __near & BaseExplosionEffect(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseExplosionEffect *__cdecl BaseExplosionEffect()
{
  return &C_BaseExplosionEffect::m_instance;
}

//------------------------------------------------------------------------------
// Address: 0x100D82A0
// Name: void ExplosionCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExplosionCallback(const CEffectData *data)
{
  ((void (__thiscall *)(C_BaseExplosionEffect *, const CEffectData *, _DWORD, _DWORD, int))C_BaseExplosionEffect::m_instance.Create)(
    a1: &C_BaseExplosionEffect::m_instance,
    a2: data,
    a3: LODWORD(data->m_flMagnitude),
    a4: LODWORD(data->m_flScale),
    a5: data->m_fFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100D82E0
// Name: public: virtual float CWaterExplosionParticle::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWaterExplosionParticle::UpdateRoll(
        CWaterExplosionParticle *this,
        SimpleParticle *pParticle,
        float timeDelta)
{
  float v3; // xmm1_4
  float v4; // xmm0_4

  v3 = 0.25;
  v4 = (float)((float)(timeDelta * -8.0) + 1.0) * pParticle->m_flRollDelta;
  pParticle->m_flRoll = (float)(pParticle->m_flRollDelta * timeDelta) + pParticle->m_flRoll;
  pParticle->m_flRollDelta = v4;
  if ( COERCE_FLOAT(LODWORD(v4) & _mask__AbsFloat_) < 0.25 )
  {
    if ( v4 <= 0.0 )
      v3 = -0.25;
    pParticle->m_flRollDelta = v3;
  }
  return pParticle->m_flRoll;
}

//------------------------------------------------------------------------------
// Address: 0x100D8350
// Name: public: virtual float CWaterExplosionParticle::UpdateAlpha(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CWaterExplosionParticle::UpdateAlpha(CWaterExplosionParticle *this, const SimpleParticle *pParticle)
{
  float ramp; // [esp+8h] [ebp+8h]

  ramp = 1.0 - (float)(pParticle->m_flLifetime / pParticle->m_flDieTime);
  if ( ramp < 0.75 )
    return (float)(ramp * ramp);
  return ramp;
}

//------------------------------------------------------------------------------
// Address: 0x100D8390
// Name: class C_WaterExplosionEffect __near & WaterExplosionEffect(void)
// Source: json
//------------------------------------------------------------------------------
C_WaterExplosionEffect *__cdecl WaterExplosionEffect()
{
  return &C_WaterExplosionEffect::m_waterinstance;
}

//------------------------------------------------------------------------------
// Address: 0x100D83A0
// Name: protected: virtual void C_WaterExplosionEffect::PlaySound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterExplosionEffect::PlaySound(C_WaterExplosionEffect *this)
{
  Vector *p_m_vecOrigin; // [esp-4h] [ebp-30h]
  CLocalPlayerFilter filter; // [esp+Ch] [ebp-20h] BYREF

  if ( (this->m_fFlags & 4) == 0 )
  {
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: 0,
      soundname: "Physics.WaterSplash",
      pOrigin: &this->m_vecWaterSurface,
      soundtime: 0.0,
      duration: nullptr);
    p_m_vecOrigin = &this->m_vecOrigin;
    if ( this->m_flDepth <= 128.0 )
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: 0,
        soundname: "BaseExplosionEffect.Sound",
        pOrigin: p_m_vecOrigin,
        soundtime: 0.0,
        duration: nullptr);
    else
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: 0,
        soundname: "WaterExplosionEffect.Sound",
        pOrigin: p_m_vecOrigin,
        soundtime: 0.0,
        duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8430
// Name: void WaterSurfaceExplosionCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WaterSurfaceExplosionCallback(const CEffectData *data)
{
  ((void (__thiscall *)(C_WaterExplosionEffect *, const CEffectData *, _DWORD, _DWORD, int))C_WaterExplosionEffect::m_waterinstance.Create)(
    a1: &C_WaterExplosionEffect::m_waterinstance,
    a2: data,
    a3: LODWORD(data->m_flMagnitude),
    a4: LODWORD(data->m_flScale),
    a5: data->m_fFlags);
}

//------------------------------------------------------------------------------
// Address: 0x100D8470
// Name: void FX_GetSplashLighting(class Vector,class Vector __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_GetSplashLighting(Vector position, Vector *color, float *luminosity)
{
  float *v3; // esi
  Vector *v4; // edi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  Vector totalColor; // [esp+8h] [ebp-Ch] BYREF

  engine->GetLightForPoint(this: engine, result: &totalColor, a3: &position, a4: true);
  v3 = luminosity;
  v4 = color;
  UTIL_GetNormalizedColorTintAndLuminosity(color: &totalColor, tint: color, luminosity);
  if ( v3 != nullptr )
  {
    v5 = *v3 * 4.0;
    if ( v5 > 1.0 )
      v5 = 1.0;
    *v3 = v5;
    if ( v5 < 0.25 )
      *v3 = 0.25;
  }
  if ( v4 != nullptr )
  {
    v6 = v4->y * 0.25;
    v7 = v4->z * 0.25;
    v4->x = (float)(v4->x * 0.25) + 0.75;
    v4->y = v6 + 0.75;
    v4->z = v7 + 0.75;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8520
// Name: public: virtual void CExplosionParticle::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExplosionParticle::UpdateVelocity(
        CExplosionParticle *this,
        SimpleParticle *pParticle,
        float timeDelta)
{
  float z; // eax
  double v4; // xmm0_8
  __m128d v5; // xmm0
  double v6; // xmm0_8
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector saveVelocity; // [esp+0h] [ebp-Ch] BYREF

  z = pParticle->m_vecVelocity.z;
  *(_QWORD *)&saveVelocity.x = *(_QWORD *)&pParticle->m_vecVelocity.x;
  saveVelocity.z = z;
  if ( `CExplosionParticle::UpdateVelocity'::`2'::dtime == timeDelta )
  {
    v7 = `CExplosionParticle::UpdateVelocity'::`2'::decay;
  }
  else
  {
    `CExplosionParticle::UpdateVelocity'::`2'::dtime = timeDelta;
    __libm_sse2_log(a1: (__m128d)0x3F1A36E2E0000000uLL);
    *(float *)&v4 = v4;
    v5.m128d_f64[0] = (float)((float)(*(float *)&v4 * timeDelta) * 2.0);
    __libm_sse2_exp(a1: v5);
    v7 = v6;
    `CExplosionParticle::UpdateVelocity'::`2'::decay = v7;
  }
  v8 = pParticle->m_vecVelocity.z;
  v9 = pParticle->m_vecVelocity.y * v7;
  pParticle->m_vecVelocity.x = v7 * pParticle->m_vecVelocity.x;
  v10 = v8 * v7;
  pParticle->m_vecVelocity.y = v9;
  pParticle->m_vecVelocity.z = v10;
  if ( (float)((float)((float)(v9 * v9) + (float)(pParticle->m_vecVelocity.x * pParticle->m_vecVelocity.x))
             + (float)(v10 * v10)) < 1024.0 )
  {
    VectorNormalize(vec: &saveVelocity);
    v11 = saveVelocity.y * 32.0;
    v12 = saveVelocity.z * 32.0;
    pParticle->m_vecVelocity.x = saveVelocity.x * 32.0;
    pParticle->m_vecVelocity.y = v11;
    pParticle->m_vecVelocity.z = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8640
// Name: public: virtual class Vector CExplosionParticle::UpdateColor(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CExplosionParticle::UpdateColor(
        CExplosionParticle *this,
        Vector *result,
        const SimpleParticle *pParticle)
{
  long double v4; // st7
  int v5; // edx
  const SimpleParticle *pParticlea; // [esp+18h] [ebp+Ch]

  v4 = Bias(x: 1.0 - (float)(pParticle->m_flLifetime / pParticle->m_flDieTime), biasAmt: 0x3E800000u);
  v5 = pParticle->m_uchColor[2];
  pParticlea = (const SimpleParticle *)pParticle->m_uchColor[1];
  result->x = (double)pParticle->m_uchColor[0] * v4 * 0.0039215689;
  result->y = (double)(int)pParticlea * v4 * 0.0039215689;
  result->z = v4 * (double)v5 * 0.0039215689;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D86C0
// Name: protected: float C_BaseExplosionEffect::ScaleForceByDeviation(class Vector __near &,class Vector __near &,float,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseExplosionEffect::ScaleForceByDeviation(
        C_BaseExplosionEffect *this,
        Vector *deviant,
        Vector *source,
        float spread,
        float *force)
{
  float v5; // xmm0_4

  if ( vec3_origin.x == deviant->x && vec3_origin.y == deviant->y && vec3_origin.z == deviant->z
    || vec3_origin.x == source->x && vec3_origin.y == source->y && vec3_origin.z == source->z )
  {
    return 1.0;
  }
  v5 = COERCE_FLOAT(
         COERCE_UNSIGNED_INT((float)((float)(deviant->y * source->y) + (float)(source->x * deviant->x)) + (float)(deviant->z * source->z))
       & _mask__AbsFloat_)
     * spread;
  if ( force != nullptr )
    *force = *force * v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D8780
// Name: protected: virtual void C_BaseExplosionEffect::CreateDynamicLight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseExplosionEffect::CreateDynamicLight(C_BaseExplosionEffect *this)
{
  dlight_t *v2; // eax

  if ( (this->m_fFlags & 2) != 0 )
  {
    v2 = effects->CL_AllocDlight(this: effects, a2: 0);
    v2->origin.x = this->m_vecOrigin.x;
    v2->origin.y = this->m_vecOrigin.y;
    v2->origin.z = this->m_vecOrigin.z;
    v2->decay = 200.0;
    v2->radius = this->m_flScale * 255.0;
    *(_WORD *)&v2->color.r = -8961;
    v2->color.b = 0x80;
    v2->die = *(float *)(gpGlobals.m_Index + 12) + 0.1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D87F0
// Name: protected: virtual void C_BaseExplosionEffect::PlaySound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseExplosionEffect::PlaySound(C_BaseExplosionEffect *this)
{
  CLocalPlayerFilter filter; // [esp+Ch] [ebp-20h] BYREF

  if ( (this->m_fFlags & 4) == 0 )
  {
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    if ( (this->m_fFlags & 0x100) != 0 )
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: 0,
        soundname: "explode_3",
        pOrigin: &this->m_vecOrigin,
        soundtime: 0.0,
        duration: nullptr);
    else
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: 0,
        soundname: "BaseExplosionEffect.Sound",
        pOrigin: &this->m_vecOrigin,
        soundtime: 0.0,
        duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8850
// Name: public: virtual void CWaterExplosionParticle::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWaterExplosionParticle::UpdateVelocity(
        CWaterExplosionParticle *this,
        SimpleParticle *pParticle,
        float timeDelta)
{
  float z; // eax
  double v4; // xmm0_8
  __m128d v5; // xmm0
  double v6; // xmm0_8
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector saveVelocity; // [esp+0h] [ebp-Ch] BYREF

  z = pParticle->m_vecVelocity.z;
  *(_QWORD *)&saveVelocity.x = *(_QWORD *)&pParticle->m_vecVelocity.x;
  saveVelocity.z = z;
  if ( `CWaterExplosionParticle::UpdateVelocity'::`2'::dtime == timeDelta )
  {
    v7 = `CWaterExplosionParticle::UpdateVelocity'::`2'::decay;
  }
  else
  {
    `CWaterExplosionParticle::UpdateVelocity'::`2'::dtime = timeDelta;
    __libm_sse2_log(a1: (__m128d)0x3F1A36E2E0000000uLL);
    *(float *)&v4 = v4;
    v5.m128d_f64[0] = (float)((float)(*(float *)&v4 * timeDelta) * 2.0);
    __libm_sse2_exp(a1: v5);
    v7 = v6;
    `CWaterExplosionParticle::UpdateVelocity'::`2'::decay = v7;
  }
  v8 = pParticle->m_vecVelocity.z;
  v9 = pParticle->m_vecVelocity.y * v7;
  pParticle->m_vecVelocity.x = v7 * pParticle->m_vecVelocity.x;
  v10 = v8 * v7;
  pParticle->m_vecVelocity.y = v9;
  pParticle->m_vecVelocity.z = v10;
  if ( (float)((float)((float)(v9 * v9) + (float)(pParticle->m_vecVelocity.x * pParticle->m_vecVelocity.x))
             + (float)(v10 * v10)) < 64.0 )
  {
    VectorNormalize(vec: &saveVelocity);
    v11 = saveVelocity.y * 8.0;
    v12 = saveVelocity.z * 8.0;
    pParticle->m_vecVelocity.x = saveVelocity.x * 8.0;
    pParticle->m_vecVelocity.y = v11;
    pParticle->m_vecVelocity.z = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8970
// Name: void HelicopterMegaBombCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HelicopterMegaBombCallback(const CEffectData *data)
{
  C_BaseExplosionEffect v1; // [esp+Ch] [ebp-38h] BYREF

  memset(&v1.m_Material_Smoke, 0, 16);
  v1.__vftable = (C_BaseExplosionEffect_vtbl *)&C_MegaBombExplosionEffect::`vftable';
  C_BaseExplosionEffect::Create(this: &v1, position: &data->m_vOrigin, force: 1.0, scale: 1.0, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100D89C0
// Name: protected: void C_BaseExplosionEffect::GetForceDirection(class Vector const __near &,float,class Vector __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseExplosionEffect::GetForceDirection(
        C_BaseExplosionEffect *this,
        const Vector *origin,
        float magnitude,
        Vector *resultDirection,
        float *resultForce)
{
  float *p_z; // esi
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float z; // xmm0_4
  bool v15; // zf
  CGameTrace ptr; // [esp+0h] [ebp-B0h] BYREF
  Vector d[6]; // [esp+54h] [ebp-5Ch] BYREF
  Vector vecAbsEnd; // [esp+9Ch] [ebp-14h] BYREF
  float v19; // [esp+A8h] [ebp-8h]
  float v20; // [esp+ACh] [ebp-4h]
  IHandleEntity savedregs; // [esp+B0h] [ebp+0h] BYREF
  float origina; // [esp+B8h] [ebp+8h]
  int resultDirectiona; // [esp+C0h] [ebp+10h]

  resultDirection->x = 0.0;
  resultDirection->y = 0.0;
  resultDirection->z = 0.0;
  d[0].x = 1.0;
  d[0].y = 0.0;
  d[0].z = 0.0;
  d[1].x = -1.0;
  d[1].y = 0.0;
  d[1].z = 0.0;
  d[2].x = 0.0;
  d[2].y = 1.0;
  d[2].z = 0.0;
  d[3].x = 0.0;
  d[3].y = -1.0;
  d[3].z = 0.0;
  d[4].x = 0.0;
  d[4].y = 0.0;
  d[4].z = 1.0;
  d[5].x = 0.0;
  d[5].y = 0.0;
  d[5].z = -1.0;
  *resultForce = 1.0;
  p_z = &d[0].z;
  resultDirectiona = 6;
  do
  {
    v8 = *p_z;
    origina = *(p_z - 2);
    v20 = *(p_z - 1);
    v19 = v8;
    v9 = origin->x + (float)(origina * magnitude);
    vecAbsEnd.y = origin->y + (float)(v20 * magnitude);
    v10 = origin->z + (float)(v8 * magnitude);
    vecAbsEnd.x = v9;
    vecAbsEnd.z = v10;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)p_z,
      vecAbsStart: origin,
      &vecAbsEnd,
      mask: 1u,
      ignore: nullptr,
      collisionGroup: 0,
      &ptr);
    v11 = (float)-origina * (float)(1.0 - ptr.fraction);
    v12 = (float)-v20 * (float)(1.0 - ptr.fraction);
    v13 = (float)-v19 * (float)(1.0 - ptr.fraction);
    *resultForce = (float)(1.0 - ptr.fraction) + *resultForce;
    resultDirection->x = v11 + resultDirection->x;
    resultDirection->y = v12 + resultDirection->y;
    z = resultDirection->z;
    *(p_z - 2) = v11;
    *(p_z - 1) = v12;
    *p_z = v13;
    p_z += 3;
    v15 = resultDirectiona-- == 1;
    resultDirection->z = z + v13;
  }
  while ( !v15 );
  if ( vec3_origin.x == resultDirection->x && vec3_origin.y == resultDirection->y && vec3_origin.z == resultDirection->z )
  {
    resultDirection->x = 0.0;
    resultDirection->y = 0.0;
    resultDirection->z = 1.0;
    *resultForce = 2.0;
  }
  VectorNormalize(vec: resultDirection);
}

//------------------------------------------------------------------------------
// Address: 0x100D8BE0
// Name: protected: virtual void C_WaterExplosionEffect::CreateCore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterExplosionEffect::CreateCore(C_WaterExplosionEffect *this)
{
  float v2; // xmm0_4
  float z; // xmm1_4
  int v4; // eax
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // edx
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  IMaterial *v7; // eax
  float (__thiscall *v8)(IUniformRandomStream *, float, float); // eax
  int (__thiscall *v9)(IUniformRandomStream *, int, int); // eax
  IMaterial *v10; // eax
  float lifeTime; // [esp+58h] [ebp-B4h]
  Vector vUp; // [esp+78h] [ebp-94h] BYREF
  Vector vRight; // [esp+84h] [ebp-88h] BYREF
  FXLineData_t lineData; // [esp+90h] [ebp-7Ch] BYREF
  Vector color; // [esp+DCh] [ebp-30h] BYREF
  float v16; // [esp+E8h] [ebp-24h]
  float lifetime; // [esp+ECh] [ebp-20h]
  float luminosity; // [esp+F0h] [ebp-1Ch] BYREF
  Vector start; // [esp+F4h] [ebp-18h] BYREF
  Vector normal; // [esp+100h] [ebp-Ch] BYREF

  if ( (this->m_fFlags & 0x40) == 0 )
  {
    *(_QWORD *)&normal.x = *(_QWORD *)&this->m_vecWaterSurface.x;
    normal.z = this->m_vecWaterSurface.z + 8.0;
    start = normal;
    engine->GetLightForPoint(this: engine, result: &normal, a3: &start, a4: true);
    UTIL_GetNormalizedColorTintAndLuminosity(color: &normal, tint: &color, &luminosity);
    v2 = luminosity * 4.0;
    if ( (float)(luminosity * 4.0) <= 1.0 )
    {
      luminosity = luminosity * 4.0;
      if ( v2 < 0.25 )
        luminosity = 0.25;
    }
    else
    {
      luminosity = 1.0;
    }
    color.x = (float)(color.x * 0.25) + 0.75;
    color.y = (float)(color.y * 0.25) + 0.75;
    color.z = (float)(color.z * 0.25) + 0.75;
    lifetime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1061997773,
                 a3: 1065353216);
    z = this->m_vecWaterSurface.z;
    normal.x = 0.0;
    normal.y = 0.0;
    normal.z = 1.0;
    start.x = this->m_vecWaterSurface.x;
    start.y = this->m_vecWaterSurface.y;
    start.z = z + 2.0;
    lifeTime = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
    v4 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
    FX_AddQuad(
      origin: &start,
      &normal,
      startSize: 64.0,
      endSize: 256.0,
      sizeBias: 0.85000002,
      startAlpha: luminosity,
      endAlpha: 0.0,
      alphaBias: 0.25,
      yaw: (float)v4,
      deltaYaw: 0.0,
      color: (const Vector *)0x168,
      lifeTime,
      shader: (const char *)0xC0800000,
      flags: 0x40800000u);
    normal.x = 0.0;
    normal.y = 0.0;
    normal.z = 1.0;
    VectorVectors(forward: &normal, right: &vRight, up: &vUp);
    RandomFloat = random->RandomFloat;
    start = this->m_vecWaterSurface;
    v16 = ((double (__thiscall *)(IUniformRandomStream *, int, int, Vector *, int, const char *, int))RandomFloat)(
            a1: random,
            a2: 1112014848,
            a3: 1117126656,
            a4: &color,
            a5: 0x40000000,
            a6: "effects/splashwake1",
            a7: 3);
    RandomInt = random->RandomInt;
    normal.x = (float)(v16 * 0.0) + start.x;
    normal.y = (float)(v16 * 0.0) + start.y;
    normal.z = v16 + start.z;
    RandomInt(this: random, a2: 0, a3: 1);
    lineData.m_flDieTime = lifetime * 0.5;
    v16 = lifetime * 0.5;
    lineData.m_flStartAlpha = luminosity;
    lineData.m_flEndAlpha = 0.0;
    lineData.m_flStartScale = 25.0;
    lineData.m_flEndScale = 100.0;
    v7 = materials->FindMaterial(this: materials, a2: "effects/splash3", a3: 0, a4: 0, a5: 0);
    lineData.m_vecStart = start;
    lineData.m_vecStartVelocity = vec3_origin;
    lineData.m_vecEnd = normal;
    lineData.m_pMaterial = v7;
    lineData.m_vecEndVelocity.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                    a1: random,
                                    a2: 1143111680,
                                    a3: 1144750080);
    lineData.m_vecEndVelocity.x = 0.0;
    lineData.m_vecEndVelocity.y = 0.0;
    FX_AddLine(data: &lineData);
    v8 = random->RandomFloat;
    start = this->m_vecWaterSurface;
    lifetime = ((double (__stdcall *)(int, int))v8)(a1: 1107296256, a2: 1115684864);
    v9 = random->RandomInt;
    normal.x = (float)(lifetime * 0.0) + start.x;
    normal.y = (float)(lifetime * 0.0) + start.y;
    normal.z = lifetime + start.z;
    v9(this: random, a2: 0, a3: 1);
    lineData.m_flDieTime = v16;
    lineData.m_flStartAlpha = luminosity;
    lineData.m_flEndAlpha = 0.0;
    lineData.m_flStartScale = 50.0;
    lineData.m_flEndScale = 100.0;
    v10 = materials->FindMaterial(this: materials, a2: "effects/splash3", a3: 0, a4: 0, a5: 0);
    lineData.m_vecStart = start;
    lineData.m_vecStartVelocity = vec3_origin;
    lineData.m_pMaterial = v10;
    lineData.m_vecEnd = normal;
    lifetime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1115684864,
                 a3: 1124073472);
    lineData.m_vecEndVelocity.x = lifetime * 0.0;
    lineData.m_vecEndVelocity.y = lifetime * 0.0;
    lineData.m_vecEndVelocity.z = lifetime;
    FX_AddLine(data: &lineData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9160
// Name: public: virtual void C_BaseExplosionEffect::Create(class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseExplosionEffect::Create(
        C_BaseExplosionEffect *this,
        const Vector *position,
        float force,
        float scale,
        int flags)
{
  float v6; // xmm0_4

  this->m_vecOrigin = *position;
  this->m_fFlags = flags;
  if ( (flags & 0x100) != 0 )
  {
    this->PlaySound(this);
  }
  else
  {
    if ( (flags & 0x200) != 0 )
      v6 = scale;
    else
      v6 = 1.0;
    this->m_flScale = v6;
    C_BaseExplosionEffect::GetForceDirection(
      this,
      origin: &this->m_vecOrigin,
      magnitude: force,
      resultDirection: &this->m_vecDirection,
      resultForce: &this->m_flForce);
    this->PlaySound(this);
    if ( scale != 0.0 )
      this->CreateCore(this);
    this->CreateDebris(this);
    this->CreateDynamicLight(this);
    this->CreateMisc(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9220
// Name: protected: virtual void C_BaseExplosionEffect::CreateCore(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseExplosionEffect::CreateCore(C_BaseExplosionEffect *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  int m_fFlags; // eax
  float v5; // xmm0_4
  CSimpleEmitter *v6; // eax
  CExplosionParticle *v7; // esi
  CSimpleEmitter *v8; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  IUniformRandomStream *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  bool v19; // zf
  Particle *v20; // eax
  IUniformRandomStream *v21; // ecx
  Particle *v22; // edi
  IUniformRandomStream *v23; // ecx
  IUniformRandomStream *v24; // ecx
  IUniformRandomStream *v25; // ecx
  Particle *v26; // xmm1_4
  CParticleSubTexture *v27; // xmm2_4
  double v28; // st7
  double v29; // st7
  float m_flScale; // xmm0_4
  Particle *v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  float v36; // xmm3_4
  CParticleSubTexture *m_Material_Smoke; // ecx
  float v38; // xmm1_4
  float v39; // xmm2_4
  Particle *v40; // eax
  Particle *v41; // edi
  float *v42; // esi
  IUniformRandomStream *v43; // ecx
  IUniformRandomStream *v44; // ecx
  IUniformRandomStream *v45; // ecx
  Particle *v46; // xmm1_4
  CParticleSubTexture *v47; // xmm2_4
  double v48; // st7
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  Particle *v52; // xmm1_4
  CParticleSubTexture *v53; // xmm0_4
  float v54; // xmm0_4
  Particle *v55; // xmm1_4
  float v56; // xmm0_4
  int v57; // eax
  double v58; // st7
  CExplosionParticle *m_pObj; // edi
  float v60; // xmm0_4
  long double v61; // st7
  float *v62; // eax
  float v63; // xmm0_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  IUniformRandomStream *v65; // ecx
  IUniformRandomStream *v66; // ecx
  IUniformRandomStream *v67; // ecx
  float v68; // xmm3_4
  CParticleSubTexture *v69; // edx
  float v70; // xmm1_4
  float v71; // xmm2_4
  Particle *v72; // eax
  Particle *v73; // esi
  double v74; // st7
  float v75; // xmm0_4
  float v76; // xmm0_4
  Particle *v77; // xmm1_4
  CParticleSubTexture *v78; // xmm0_4
  float v79; // xmm0_4
  Particle *v80; // xmm1_4
  int v81; // eax
  int v82; // eax
  double v83; // st7
  IUniformRandomStream *v84; // ecx
  IUniformRandomStream *v85; // ecx
  float v86; // xmm3_4
  float v87; // xmm1_4
  float v88; // xmm2_4
  int v89; // eax
  Particle *v90; // eax
  Particle *v91; // edi
  float *v92; // esi
  IUniformRandomStream *v93; // ecx
  IUniformRandomStream *v94; // ecx
  IUniformRandomStream *v95; // ecx
  float v96; // xmm0_4
  float v97; // xmm0_4
  float v98; // xmm0_4
  Particle *v99; // xmm1_4
  CParticleSubTexture *v100; // xmm0_4
  float v101; // xmm0_4
  Particle *v102; // xmm1_4
  CParticleSubTexture *v103; // xmm0_4
  char v104; // al
  int v105; // eax
  float v106; // xmm0_4
  int v107; // ecx
  float v108; // xmm0_4
  CExplosionParticle *v109; // esi
  IUniformRandomStream *v110; // ecx
  IUniformRandomStream *v111; // ecx
  float v112; // xmm3_4
  CParticleSubTexture *m_Material_FireCloud; // ecx
  float v114; // xmm1_4
  float v115; // xmm2_4
  Particle *v116; // eax
  Particle *v117; // edi
  float *v118; // esi
  IUniformRandomStream *v119; // ecx
  IUniformRandomStream *v120; // ecx
  IUniformRandomStream *v121; // ecx
  float v122; // xmm0_4
  float v123; // xmm0_4
  float v124; // xmm0_4
  Particle *v125; // xmm1_4
  CParticleSubTexture *v126; // xmm0_4
  float v127; // xmm0_4
  Particle *v128; // xmm1_4
  CParticleSubTexture *v129; // xmm0_4
  char v130; // al
  int v131; // eax
  float v132; // xmm0_4
  int v133; // ecx
  int v134; // eax
  Vector vRight; // [esp+78h] [ebp-94h] BYREF
  Vector vUp; // [esp+84h] [ebp-88h] BYREF
  float *p_y; // [esp+90h] [ebp-7Ch]
  float v140; // [esp+94h] [ebp-78h]
  float v141; // [esp+98h] [ebp-74h]
  float v142; // [esp+9Ch] [ebp-70h]
  Vector tint; // [esp+A0h] [ebp-6Ch] BYREF
  Vector bbMax; // [esp+ACh] [ebp-60h] BYREF
  Vector bbMin; // [esp+B8h] [ebp-54h] BYREF
  Vector forward; // [esp+C4h] [ebp-48h] BYREF
  Vector worldLight; // [esp+D0h] [ebp-3Ch] BYREF
  float v148; // [esp+DCh] [ebp-30h]
  float luminosity; // [esp+E0h] [ebp-2Ch] BYREF
  float fForce; // [esp+E4h] [ebp-28h] BYREF
  CSmartPtr<CExplosionParticle,CRefCountAccessor> pSimple; // [esp+E8h] [ebp-24h]
  float vDev; // [esp+ECh] [ebp-20h]
  Vector offset; // [esp+F0h] [ebp-1Ch] BYREF
  int flYaw; // [esp+FCh] [ebp-10h]
  float spread; // [esp+100h] [ebp-Ch]
  int i; // [esp+104h] [ebp-8h]
  int v157; // [esp+108h] [ebp-4h]

  m_fFlags = this->m_fFlags;
  if ( (m_fFlags & 0x40) == 0 && (m_fFlags & 0x100) == 0 )
  {
    vDev = this->m_flForce;
    v5 = vDev;
    if ( vDev < 2.0 || vDev > 2.0 )
    {
      v5 = 2.0;
      vDev = 2.0;
    }
    spread = 1.0 - (float)(v5 * 0.15000001);
    v6 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v7 = (CExplosionParticle *)v6;
    if ( v6 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v6, pDebugName: "exp_smoke");
      v7->__vftable = (CExplosionParticle_vtbl *)&CExplosionParticle::`vftable';
    }
    else
    {
      v7 = nullptr;
    }
    v8 = nullptr;
    pSimple.m_pObj = nullptr;
    if ( v7 != nullptr )
    {
      CParticleEffect::AddRef(this: v7);
      v8 = v7;
      pSimple.m_pObj = v7;
    }
    CParticleEffect::SetSortOrigin(this: v8, vSortOrigin: &this->m_vecOrigin);
    CSimpleEmitter::SetNearClip(this: v8, nearClipMin: 64.0, nearClipMax: 128.0);
    x = this->m_vecOrigin.x;
    bbMax.x = x + 128.0;
    y = this->m_vecOrigin.y;
    bbMax.y = y + 128.0;
    z = this->m_vecOrigin.z;
    bbMax.z = z + 128.0;
    bbMin.x = x - 128.0;
    bbMin.y = y - 128.0;
    bbMin.z = z - 128.0;
    CParticleEffectBinding::SetBBox(this: &v8->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
    if ( this->m_Material_Smoke == nullptr )
      this->m_Material_Smoke = dword_1066E3FC;
    v12 = (float)(this->m_vecDirection.y * 32.0) + this->m_vecOrigin.y;
    v13 = (float)(this->m_vecDirection.z * 32.0) + this->m_vecOrigin.z;
    offset.x = (float)(this->m_vecDirection.x * 32.0) + this->m_vecOrigin.x;
    offset.y = v12;
    offset.z = v13;
    ((void (__thiscall *)(IVEngineClient *, Vector *, Vector *, int, int, int))engine->GetLightForPoint)(
      a1: engine,
      a2: &worldLight,
      a3: &offset,
      a4: 1,
      a5: a2,
      a6: a3);
    v15 = vec3_origin.x;
    if ( vec3_origin.x == worldLight.x
      && (v16 = vec3_origin.y, vec3_origin.y == worldLight.y)
      && (v17 = vec3_origin.z, vec3_origin.z == worldLight.z) )
    {
      v18 = 0.0;
    }
    else
    {
      UTIL_GetNormalizedColorTintAndLuminosity(color: &worldLight, &tint, &luminosity);
      v17 = tint.z;
      v16 = tint.y;
      v15 = tint.x;
      v18 = luminosity;
    }
    v19 = SLOBYTE(this->m_fFlags) >= 0;
    tint.x = (float)(v15 * 0.25) + 0.75;
    tint.y = (float)(v16 * 0.25) + 0.75;
    tint.z = (float)(v17 * 0.25) + 0.75;
    luminosity = v18 * 255.0;
    if ( v19 )
    {
      v157 = 4;
      do
      {
        v20 = CParticleEffect::AddParticle(
                this: pSimple.m_pObj,
                particleSize: 0x3Cu,
                material: this->m_Material_Smoke,
                origin: &this->m_vecOrigin);
        v22 = v20;
        if ( v20 != nullptr )
        {
          v20[1].m_Pos.z = 0.0;
          v20[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 0x40000000,
                             a3: 1077936128);
          i = LODWORD(spread) ^ _mask__NegFloat_;
          *(float *)&v22[1].m_pPrev = _RandomFloat(
                                        this: v23,
                                        a2: COERCE_FLOAT(LODWORD(spread) ^ _mask__NegFloat_),
                                        a3: spread);
          *(float *)&v22[1].m_pNext = _RandomFloat(this: v24, a2: *(float *)&i, a3: spread);
          *(float *)&v22[1].m_pSubTexture = _RandomFloat(this: v25, a2: *(float *)&i, a3: spread);
          *(float *)&flYaw = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1065353216,
                               a3: 1086324736);
          *(float *)&v26 = (float)(*(float *)&flYaw * this->m_vecDirection.y) + *(float *)&v22[1].m_pNext;
          *(float *)&v27 = (float)(*(float *)&flYaw * this->m_vecDirection.z) + *(float *)&v22[1].m_pSubTexture;
          *(float *)&v22[1].m_pPrev = (float)(*(float *)&flYaw * this->m_vecDirection.x) + *(float *)&v22[1].m_pPrev;
          v22[1].m_pNext = v26;
          v22[1].m_pSubTexture = v27;
          VectorNormalize(vec: (Vector *)&v22[1]);
          v28 = ((double (__cdecl *)(int, int))random->RandomFloat)(a1: 1065353216, a2: 1144750080);
          fForce = v28 * vDev;
          C_BaseExplosionEffect::ScaleForceByDeviation(
            this,
            deviant: (Vector *)&v22[1],
            source: &this->m_vecDirection,
            spread,
            force: &fForce);
          v29 = fForce;
          *(float *)&v22[1].m_pPrev = fForce * *(float *)&v22[1].m_pPrev;
          *(float *)&v22[1].m_pNext = v29 * *(float *)&v22[1].m_pNext;
          *(float *)&v22[1].m_pSubTexture = v29 * *(float *)&v22[1].m_pSubTexture;
          m_flScale = this->m_flScale;
          *(float *)&v22[1].m_pPrev = m_flScale * *(float *)&v22[1].m_pPrev;
          *(float *)&v31 = m_flScale * *(float *)&v22[1].m_pNext;
          *(float *)&v22[1].m_pSubTexture = m_flScale * *(float *)&v22[1].m_pSubTexture;
          v22[1].m_pNext = v31;
          v32 = (float)random->RandomInt(this: random, a2: (int)(float)(luminosity * 0.5), a3: (int)luminosity);
          LOBYTE(v22[2].m_pPrev) = (int)(float)(v32 * worldLight.x);
          BYTE1(v22[2].m_pPrev) = (int)(float)(v32 * worldLight.y);
          BYTE2(v22[2].m_pPrev) = (int)(float)(v32 * worldLight.z);
          v33 = this->m_flScale * 72.0;
          BYTE1(v22[2].m_pNext) = (int)v33;
          BYTE2(v22[2].m_pNext) = 2 * (int)v33;
          *(_WORD *)((char *)&v22[2].m_pPrev + 3) = 255;
          v22[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v22[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1073741824,
                                              a3: 0x40000000);
        }
        --v157;
      }
      while ( *(float *)&v157 != 0.0 );
      flYaw = 8;
      do
      {
        offset.x = _RandomFloat(this: v21, a2: -16.0, a3: 16.0);
        offset.y = _RandomFloat(this: v34, a2: -16.0, a3: 16.0);
        offset.z = _RandomFloat(this: v35, a2: -16.0, a3: 16.0);
        v36 = this->m_flScale;
        m_Material_Smoke = this->m_Material_Smoke;
        v38 = (float)(offset.y * v36) + this->m_vecOrigin.y;
        v39 = (float)(offset.z * v36) + this->m_vecOrigin.z;
        offset.x = (float)(v36 * offset.x) + this->m_vecOrigin.x;
        offset.y = v38;
        offset.z = v39;
        v40 = CParticleEffect::AddParticle(
                this: pSimple.m_pObj,
                particleSize: 0x3Cu,
                material: m_Material_Smoke,
                origin: &offset);
        v41 = v40;
        if ( v40 != nullptr )
        {
          v40[1].m_Pos.z = 0.0;
          v40[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1056964608,
                             a3: 1065353216);
          v42 = (float *)&v41[1];
          i = LODWORD(spread) ^ _mask__NegFloat_;
          *(float *)&v41[1].m_pPrev = _RandomFloat(
                                        this: v43,
                                        a2: COERCE_FLOAT(LODWORD(spread) ^ _mask__NegFloat_),
                                        a3: spread);
          *(float *)&v41[1].m_pNext = _RandomFloat(this: v44, a2: *(float *)&i, a3: spread);
          *(float *)&v41[1].m_pSubTexture = _RandomFloat(this: v45, a2: *(float *)&i, a3: spread);
          *(float *)&v157 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                              a1: random,
                              a2: 1065353216,
                              a3: 1086324736);
          *(float *)&v46 = (float)(*(float *)&v157 * this->m_vecDirection.y) + *(float *)&v41[1].m_pNext;
          *(float *)&v47 = (float)(*(float *)&v157 * this->m_vecDirection.z) + *(float *)&v41[1].m_pSubTexture;
          *(float *)&v41[1].m_pPrev = (float)(*(float *)&v157 * this->m_vecDirection.x) + *(float *)&v41[1].m_pPrev;
          v41[1].m_pNext = v46;
          v41[1].m_pSubTexture = v47;
          VectorNormalize(vec: (Vector *)&v41[1]);
          v48 = ((double (__cdecl *)(int, int))random->RandomFloat)(a1: 1065353216, a2: 1157234688);
          v49 = *(float *)&v41[1].m_pPrev;
          *(float *)&v157 = v48 * vDev;
          if ( vec3_origin.x == v49
            && vec3_origin.y == *(float *)&v41[1].m_pNext
            && vec3_origin.z == *(float *)&v41[1].m_pSubTexture
            || (v50 = this->m_vecDirection.x, vec3_origin.x == v50)
            && vec3_origin.y == this->m_vecDirection.y
            && vec3_origin.z == this->m_vecDirection.z )
          {
            v51 = *(float *)&v157;
          }
          else
          {
            v51 = (float)(fabs(
                            (float)((float)(v50 * v49) + (float)(*(float *)&v41[1].m_pNext * this->m_vecDirection.y))
                          + (float)(*(float *)&v41[1].m_pSubTexture * this->m_vecDirection.z))
                        * spread)
                * *(float *)&v157;
          }
          *v42 = v51 * *v42;
          *(float *)&v52 = v51 * *(float *)&v41[1].m_pNext;
          *(float *)&v53 = v51 * *(float *)&v41[1].m_pSubTexture;
          v41[1].m_pNext = v52;
          v41[1].m_pSubTexture = v53;
          v54 = this->m_flScale;
          *v42 = v54 * *v42;
          *(float *)&v55 = v54 * *(float *)&v41[1].m_pNext;
          *(float *)&v41[1].m_pSubTexture = v54 * *(float *)&v41[1].m_pSubTexture;
          v41[1].m_pNext = v55;
          v56 = (float)random->RandomInt(this: random, a2: (int)(float)(luminosity * 0.5), a3: (int)luminosity);
          LOBYTE(v41[2].m_pPrev) = (int)(float)(v56 * worldLight.x);
          BYTE1(v41[2].m_pPrev) = (int)(float)(v56 * worldLight.y);
          BYTE2(v41[2].m_pPrev) = (int)(float)(v56 * worldLight.z);
          v57 = (int)(float)((float)random->RandomInt(this: random, a2: 32, a3: 64) * this->m_flScale);
          BYTE1(v41[2].m_pNext) = v57;
          BYTE2(v41[2].m_pNext) = 2 * v57;
          v58 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1124073472,
                  a3: 1132396544);
          LOBYTE(v41[2].m_pNext) = 0;
          v157 = (int)v58;
          HIBYTE(v41[2].m_pPrev) = (int)v58;
          v41[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v41[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1056964608,
                                              a3: 1090519040);
        }
        --flYaw;
      }
      while ( *(float *)&flYaw != 0.0 );
      VectorVectors(forward: &this->m_vecDirection, right: &vRight, up: &vUp);
      m_pObj = pSimple.m_pObj;
      v60 = 0.0;
      v148 = COERCE_FLOAT(&forward);
      p_y = &forward.y;
      i = 32;
      while ( 1 )
      {
        *(float *)&flYaw = v60 + 0.19634955;
        v61 = (float)(v60 + 0.19634955);
        v62 = p_y;
        *(float *)LODWORD(v148) = cos(v61);
        *v62 = sin(v61);
        v63 = this->m_flScale;
        v140 = forward.x * v63;
        v142 = v63 * 0.0;
        forward.z = 0.0;
        RandomFloat = random->RandomFloat;
        v141 = forward.y * v63;
        *(float *)&v157 = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                            a1: random,
                            a2: 1090519040,
                            a3: 1098907648);
        bbMax.x = v140 * *(float *)&v157;
        bbMax.y = v141 * *(float *)&v157;
        bbMax.z = v142 * *(float *)&v157;
        bbMin.x = _RandomFloat(this: v65, a2: -4.0, a3: 4.0);
        bbMin.y = _RandomFloat(this: v66, a2: -4.0, a3: 4.0);
        bbMin.z = _RandomFloat(this: v67, a2: -4.0, a3: 4.0);
        v68 = this->m_flScale;
        v69 = this->m_Material_Smoke;
        v70 = (float)((float)(bbMin.y * v68) + this->m_vecOrigin.y) + bbMax.y;
        v71 = (float)((float)(bbMin.z * v68) + this->m_vecOrigin.z) + bbMax.z;
        offset.x = (float)((float)(bbMin.x * v68) + this->m_vecOrigin.x) + bbMax.x;
        offset.y = v70;
        offset.z = v71;
        v72 = CParticleEffect::AddParticle(this: m_pObj, particleSize: 0x3Cu, material: v69, origin: &offset);
        v73 = v72;
        if ( v72 != nullptr )
        {
          v72[1].m_Pos.z = 0.0;
          v72[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1056964608,
                             a3: 1069547520);
          *(Vector *)&v73[1].m_pPrev = forward;
          v74 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1140457472,
                  a3: 1157234688);
          v75 = *(float *)&v73[1].m_pPrev;
          *(float *)&v157 = v74 * vDev;
          if ( vec3_origin.x == v75
            && vec3_origin.y == *(float *)&v73[1].m_pNext
            && vec3_origin.z == *(float *)&v73[1].m_pSubTexture
            || vec3_origin.x == v75
            && vec3_origin.y == *(float *)&v73[1].m_pNext
            && vec3_origin.z == *(float *)&v73[1].m_pSubTexture )
          {
            v76 = *(float *)&v157;
          }
          else
          {
            v76 = (float)(fabs(
                            (float)((float)(v75 * v75) + (float)(*(float *)&v73[1].m_pNext * *(float *)&v73[1].m_pNext))
                          + (float)(*(float *)&v73[1].m_pSubTexture * *(float *)&v73[1].m_pSubTexture))
                        * spread)
                * *(float *)&v157;
          }
          *(float *)&v73[1].m_pPrev = v76 * *(float *)&v73[1].m_pPrev;
          *(float *)&v77 = v76 * *(float *)&v73[1].m_pNext;
          *(float *)&v78 = v76 * *(float *)&v73[1].m_pSubTexture;
          v73[1].m_pNext = v77;
          v73[1].m_pSubTexture = v78;
          v79 = this->m_flScale;
          *(float *)&v73[1].m_pPrev = v79 * *(float *)&v73[1].m_pPrev;
          *(float *)&v80 = v79 * *(float *)&v73[1].m_pNext;
          *(float *)&v73[1].m_pSubTexture = v79 * *(float *)&v73[1].m_pSubTexture;
          v73[1].m_pNext = v80;
          v81 = random->RandomInt(this: random, a2: (int)(float)(luminosity * 0.5), a3: (int)luminosity);
          LOBYTE(v73[2].m_pPrev) = (int)(float)(worldLight.x * (float)v81);
          BYTE1(v73[2].m_pPrev) = (int)(float)(worldLight.y * (float)v81);
          BYTE2(v73[2].m_pPrev) = (int)(float)(worldLight.z * (float)v81);
          v82 = (int)(float)((float)random->RandomInt(this: random, a2: 16, a3: 32) * this->m_flScale);
          BYTE1(v73[2].m_pNext) = v82;
          BYTE2(v73[2].m_pNext) = 4 * v82;
          v83 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1098907648,
                  a3: 1107296256);
          LOBYTE(v73[2].m_pNext) = 0;
          v157 = (int)v83;
          HIBYTE(v73[2].m_pPrev) = (int)v83;
          v73[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v73[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1056964608,
                                              a3: 1090519040);
        }
        if ( --i == 0 )
          break;
        v60 = *(float *)&flYaw;
      }
    }
    if ( this->m_Material_Embers[0] == nullptr )
      this->m_Material_Embers[0] = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: "effects/fire_embers1");
    if ( this->m_Material_Embers[1] == nullptr )
      this->m_Material_Embers[1] = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: "effects/fire_embers2");
    for ( i = 16; i != 0; --i )
    {
      offset.x = _RandomFloat(this: v14, a2: -32.0, a3: 32.0);
      offset.y = _RandomFloat(this: v84, a2: -32.0, a3: 32.0);
      offset.z = _RandomFloat(this: v85, a2: -32.0, a3: 32.0);
      v86 = this->m_flScale;
      v87 = (float)(offset.y * v86) + this->m_vecOrigin.y;
      v88 = (float)(offset.z * v86) + this->m_vecOrigin.z;
      offset.x = (float)(v86 * offset.x) + this->m_vecOrigin.x;
      offset.y = v87;
      offset.z = v88;
      v89 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
      v90 = CParticleEffect::AddParticle(
              this: pSimple.m_pObj,
              particleSize: 0x3Cu,
              material: this->m_Material_Embers[v89],
              origin: nullptr);
      v91 = v90;
      if ( v90 != nullptr )
      {
        v90[1].m_Pos.z = 0.0;
        v90[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 0x40000000,
                           a3: 1077936128);
        v92 = (float *)&v91[1];
        *(float *)&v157 = spread * -2.0;
        *(float *)&flYaw = spread * 2.0;
        *(float *)&v91[1].m_pPrev = _RandomFloat(this: v93, a2: spread * -2.0, a3: spread * 2.0);
        *(float *)&v91[1].m_pNext = _RandomFloat(this: v94, a2: *(float *)&v157, a3: *(float *)&flYaw);
        *(float *)&v91[1].m_pSubTexture = _RandomFloat(this: v95, a2: *(float *)&v157, a3: *(float *)&flYaw);
        *(float *)&v91[1].m_pPrev = this->m_vecDirection.x + *(float *)&v91[1].m_pPrev;
        *(float *)&v91[1].m_pNext = this->m_vecDirection.y + *(float *)&v91[1].m_pNext;
        *(float *)&v91[1].m_pSubTexture = this->m_vecDirection.z + *(float *)&v91[1].m_pSubTexture;
        VectorNormalize(vec: (Vector *)&v91[1]);
        v148 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1065353216,
                 a3: 1137180672);
        if ( vec3_origin.x == *(float *)&v91[1].m_pPrev
          && vec3_origin.y == *(float *)&v91[1].m_pNext
          && vec3_origin.z == *(float *)&v91[1].m_pSubTexture
          || (v96 = this->m_vecDirection.x, vec3_origin.x == v96)
          && vec3_origin.y == this->m_vecDirection.y
          && vec3_origin.z == this->m_vecDirection.z )
        {
          v97 = 1.0;
        }
        else
        {
          v97 = fabs(
                  (float)((float)(v96 * *(float *)&v91[1].m_pPrev)
                        + (float)(*(float *)&v91[1].m_pNext * this->m_vecDirection.y))
                + (float)(*(float *)&v91[1].m_pSubTexture * this->m_vecDirection.z))
              * spread;
        }
        vDev = v97;
        v98 = (float)((float)((float)(v97 * v97) * 0.5) * 16.0) * v148;
        *v92 = v98 * *v92;
        *(float *)&v99 = v98 * *(float *)&v91[1].m_pNext;
        *(float *)&v100 = v98 * *(float *)&v91[1].m_pSubTexture;
        v91[1].m_pNext = v99;
        v91[1].m_pSubTexture = v100;
        v101 = this->m_flScale;
        *v92 = v101 * *v92;
        *(float *)&v102 = v101 * *(float *)&v91[1].m_pNext;
        *(float *)&v103 = v101 * *(float *)&v91[1].m_pSubTexture;
        v91[1].m_pNext = v102;
        v91[1].m_pSubTexture = v103;
        v104 = random->RandomInt(this: random, a2: 192, a3: 255);
        BYTE2(v91[2].m_pPrev) = v104;
        BYTE1(v91[2].m_pPrev) = v104;
        LOBYTE(v91[2].m_pPrev) = v104;
        v105 = random->RandomInt(this: random, a2: 8, a3: 16);
        v106 = (float)v105 * vDev;
        v107 = (int)v106;
        BYTE1(v91[2].m_pNext) = (int)v106;
        if ( (unsigned __int8)(int)v106 >= 4u )
        {
          if ( (unsigned __int8)(int)v106 > 0x20u )
            LOBYTE(v107) = 32;
        }
        else
        {
          LOBYTE(v107) = 4;
        }
        v108 = (float)(unsigned __int8)v107 * this->m_flScale;
        BYTE1(v91[2].m_pNext) = (int)v108;
        BYTE2(v91[2].m_pNext) = (int)v108;
        *(_WORD *)((char *)&v91[2].m_pPrev + 3) = 255;
        v91[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v91[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1056964608,
                                            a3: 1090519040);
      }
    }
    if ( this->m_Material_FireCloud == nullptr )
      this->m_Material_FireCloud = CParticleEffect::GetPMaterial(this: pSimple.m_pObj, name: "effects/fire_cloud2");
    v109 = pSimple.m_pObj;
    for ( i = 32; i != 0; --i )
    {
      offset.x = _RandomFloat(this: v14, a2: -48.0, a3: 48.0);
      offset.y = _RandomFloat(this: v110, a2: -48.0, a3: 48.0);
      offset.z = _RandomFloat(this: v111, a2: -48.0, a3: 48.0);
      v112 = this->m_flScale;
      m_Material_FireCloud = this->m_Material_FireCloud;
      v114 = (float)(offset.y * v112) + this->m_vecOrigin.y;
      v115 = (float)(offset.z * v112) + this->m_vecOrigin.z;
      offset.x = (float)(v112 * offset.x) + this->m_vecOrigin.x;
      offset.y = v114;
      offset.z = v115;
      v116 = CParticleEffect::AddParticle(
               this: v109,
               particleSize: 0x3Cu,
               material: m_Material_FireCloud,
               origin: &offset);
      v117 = v116;
      if ( v116 != nullptr )
      {
        v116[1].m_Pos.z = 0.0;
        v116[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                            a1: random,
                            a2: 1045220557,
                            a3: 1053609165);
        v118 = (float *)&v117[1];
        *(float *)&v157 = spread * -0.75;
        *(float *)&flYaw = spread * 0.75;
        *(float *)&v117[1].m_pPrev = _RandomFloat(this: v119, a2: spread * -0.75, a3: spread * 0.75);
        *(float *)&v117[1].m_pNext = _RandomFloat(this: v120, a2: *(float *)&v157, a3: *(float *)&flYaw);
        *(float *)&v117[1].m_pSubTexture = _RandomFloat(this: v121, a2: *(float *)&v157, a3: *(float *)&flYaw);
        *(float *)&v117[1].m_pPrev = this->m_vecDirection.x + *(float *)&v117[1].m_pPrev;
        *(float *)&v117[1].m_pNext = this->m_vecDirection.y + *(float *)&v117[1].m_pNext;
        *(float *)&v117[1].m_pSubTexture = this->m_vecDirection.z + *(float *)&v117[1].m_pSubTexture;
        VectorNormalize(vec: (Vector *)&v117[1]);
        v148 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1137180672,
                 a3: 1145569280);
        if ( vec3_origin.x == *(float *)&v117[1].m_pPrev
          && vec3_origin.y == *(float *)&v117[1].m_pNext
          && vec3_origin.z == *(float *)&v117[1].m_pSubTexture
          || (v122 = this->m_vecDirection.x, vec3_origin.x == v122)
          && vec3_origin.y == this->m_vecDirection.y
          && vec3_origin.z == this->m_vecDirection.z )
        {
          v123 = 1.0;
        }
        else
        {
          v123 = fabs(
                   (float)((float)(v122 * *(float *)&v117[1].m_pPrev)
                         + (float)(*(float *)&v117[1].m_pNext * this->m_vecDirection.y))
                 + (float)(*(float *)&v117[1].m_pSubTexture * this->m_vecDirection.z))
               * spread;
        }
        vDev = v123;
        v124 = (float)((float)((float)(v123 * v123) * 0.5) * 16.0) * v148;
        *v118 = v124 * *v118;
        *(float *)&v125 = v124 * *(float *)&v117[1].m_pNext;
        *(float *)&v126 = v124 * *(float *)&v117[1].m_pSubTexture;
        v117[1].m_pNext = v125;
        v117[1].m_pSubTexture = v126;
        v127 = this->m_flScale;
        *v118 = v127 * *v118;
        *(float *)&v128 = v127 * *(float *)&v117[1].m_pNext;
        *(float *)&v129 = v127 * *(float *)&v117[1].m_pSubTexture;
        v117[1].m_pNext = v128;
        v117[1].m_pSubTexture = v129;
        v130 = random->RandomInt(this: random, a2: 128, a3: 255);
        BYTE2(v117[2].m_pPrev) = v130;
        BYTE1(v117[2].m_pPrev) = v130;
        LOBYTE(v117[2].m_pPrev) = v130;
        v131 = random->RandomInt(this: random, a2: 32, a3: 85);
        v132 = (float)v131 * vDev;
        v133 = (int)v132;
        BYTE1(v117[2].m_pNext) = (int)v132;
        if ( (unsigned __int8)(int)v132 >= 0x20u )
        {
          if ( (unsigned __int8)(int)v132 > 0x55u )
            LOBYTE(v133) = 85;
        }
        else
        {
          LOBYTE(v133) = 32;
        }
        v134 = (int)(float)((float)(unsigned __int8)v133 * this->m_flScale);
        BYTE1(v117[2].m_pNext) = v134;
        BYTE2(v117[2].m_pNext) = (int)(float)((float)(unsigned __int8)v134 * 1.5);
        *(_WORD *)((char *)&v117[2].m_pPrev + 3) = 255;
        v117[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v117[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                             a1: random,
                                             a2: -1048576000,
                                             a3: 1098907648);
        v109 = pSimple.m_pObj;
      }
    }
    if ( v109 != nullptr )
      CParticleEffect::Release(this: v109);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DA720
// Name: protected: virtual void C_BaseExplosionEffect::CreateDebris(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_BaseExplosionEffect::CreateDebris(C_BaseExplosionEffect *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  CTrailParticles *v4; // eax
  CTrailParticles *v5; // eax
  CTrailParticles *v6; // ebx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm4_4
  Particle *v10; // eax
  Particle *v11; // esi
  IUniformRandomStream *v12; // ecx
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  double v15; // st7
  Particle *v16; // xmm0_4
  CParticleSubTexture *v17; // xmm2_4
  int v18; // eax
  float m_flScale; // xmm0_4
  Particle *v20; // xmm1_4
  CParticleSubTexture *v21; // xmm0_4
  Vector *p_m_vecDirection; // ebx
  float v23; // xmm1_4
  float v24; // xmm2_4
  double v25; // st7
  double v26; // st7
  double v27; // st7
  float v28; // xmm1_4
  CFleckParticles *m_pObj; // esi
  int v30; // eax
  Particle *v31; // eax
  Particle *v32; // esi
  double v33; // st7
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm2_4
  int v43; // [esp+94h] [ebp-50h]
  int v44; // [esp+98h] [ebp-4Ch]
  Vector bbMin; // [esp+A0h] [ebp-44h] BYREF
  Vector bbMax; // [esp+ACh] [ebp-38h] BYREF
  Vector offset; // [esp+B8h] [ebp-2Ch] BYREF
  Vector dir; // [esp+C4h] [ebp-20h] BYREF
  CParticleEffect *v49; // [esp+D0h] [ebp-14h]
  int colorRamp; // [esp+D4h] [ebp-10h]
  int numFlecks; // [esp+D8h] [ebp-Ch]
  CSmartPtr<CFleckParticles,CRefCountAccessor> fleckEmitter; // [esp+DCh] [ebp-8h] BYREF
  int i; // [esp+E0h] [ebp-4h]

  if ( (this->m_fFlags & 8) == 0 )
  {
    v4 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
    if ( v4 != nullptr )
    {
      v44 = a2;
      v5 = CTrailParticles::CTrailParticles(this: v4, pDebugName: "CreateDebris 1");
      v6 = v5;
      v49 = v5;
      if ( v5 != nullptr )
      {
        CParticleEffect::AddRef(this: v5);
        if ( this->m_Material_FireCloud == nullptr )
          this->m_Material_FireCloud = CParticleEffect::GetPMaterial(this: v6, name: "effects/fire_cloud2");
        v43 = a3;
        CParticleEffect::SetSortOrigin(this: v6, vSortOrigin: &this->m_vecOrigin);
        v6->m_ParticleCollision.m_flGravity = 200.0;
        v6->m_fFlags |= 1u;
        v6->m_flVelocityDampen = 8.0;
        x = this->m_vecOrigin.x;
        bbMax.x = x + 128.0;
        y = this->m_vecOrigin.y;
        bbMax.y = y + 128.0;
        z = this->m_vecOrigin.z;
        bbMax.z = z + 128.0;
        bbMin.x = x - 128.0;
        bbMin.y = y - 128.0;
        bbMin.z = z - 128.0;
        CParticleEffectBinding::SetBBox(this: &v6->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
        *(float *)&colorRamp = COERCE_FLOAT(random->RandomInt(this: random, a2: 8, a3: 16));
        i = 0;
        if ( colorRamp > 0 )
        {
          do
          {
            v10 = CParticleEffect::AddParticle(
                    this: v6,
                    particleSize: 0x38u,
                    material: this->m_Material_FireCloud,
                    origin: &this->m_vecOrigin);
            v11 = v10;
            if ( v10 == nullptr )
              break;
            v10[1].m_Pos.z = 0.0;
            v10[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1036831949,
                               a3: 1041865114);
            dir.x = _RandomFloat(this: v12, a2: -1.0, a3: 1.0);
            dir.y = _RandomFloat(this: v13, a2: -1.0, a3: 1.0);
            v15 = _RandomFloat(this: v14, a2: -1.0, a3: 1.0);
            dir.x = dir.x + this->m_vecDirection.x;
            dir.y = this->m_vecDirection.y + dir.y;
            dir.z = v15 + this->m_vecDirection.z;
            VectorNormalize(vec: &dir);
            *(float *)&v11[2].m_pNext = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: 0x40000000,
                                          a3: 1098907648)
                                      * this->m_flScale;
            *(float *)&v11[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                          a1: random,
                                          a2: 1028443341,
                                          a3: 1036831949)
                                      * this->m_flScale;
            *(float *)&numFlecks = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1153138688,
                                     a3: 1159479296);
            *(float *)&v16 = *(float *)&numFlecks * dir.x;
            *(float *)&v17 = dir.z * *(float *)&numFlecks;
            v18 = i;
            *(float *)&v11[1].m_pNext = dir.y * *(float *)&numFlecks;
            v11[1].m_pPrev = v16;
            v11[1].m_pSubTexture = v17;
            m_flScale = this->m_flScale;
            *(float *)&v11[1].m_pPrev = m_flScale * *(float *)&v11[1].m_pPrev;
            *(float *)&v20 = m_flScale * *(float *)&v11[1].m_pNext;
            *(float *)&v21 = m_flScale * *(float *)&v11[1].m_pSubTexture;
            v11[1].m_pNext = v20;
            v11[1].m_pSubTexture = v21;
            v11[1].m_Pos.x = NAN;
            i = v18 + 1;
          }
          while ( v18 + 1 < colorRamp );
        }
        bbMin.x = this->m_flScale * 128.0;
        bbMin.y = bbMin.x;
        bbMin.z = bbMin.x;
        CFleckParticles::Create(
          result: &fleckEmitter,
          pDebugName: "CreateDebris 2",
          vCenter: &this->m_vecOrigin,
          extents: &bbMin);
        if ( fleckEmitter.m_pObj != nullptr )
        {
          p_m_vecDirection = &this->m_vecDirection;
          ((void (__thiscall *)(CParticleCollision *, Vector *, Vector *, int, int, int, int, int))fleckEmitter.m_pObj->m_ParticleCollision.Setup_2)(
            a1: &fleckEmitter.m_pObj->m_ParticleCollision,
            a2: &this->m_vecOrigin,
            a3: &this->m_vecDirection,
            a4: 1063675494,
            a5: 1140850688,
            a6: 1149239296,
            a7: 1145569280,
            a8: 1056964608);
          *(float *)&numFlecks = COERCE_FLOAT(random->RandomInt(this: random, a2: 16, a3: 32));
          for ( i = 0; i < numFlecks; ++i )
          {
            v23 = this->m_vecDirection.y;
            v24 = this->m_vecDirection.z;
            offset.x = p_m_vecDirection->x * 16.0;
            offset.y = v23 * 16.0;
            offset.z = v24 * 16.0;
            v25 = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(a1: random, a2: -1056964608);
            offset.x = v25 + offset.x;
            v26 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1056964608,
                    a3: 1090519040);
            offset.y = v26 + offset.y;
            v27 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1056964608,
                    a3: 1090519040);
            v28 = this->m_flScale;
            offset.z = v27 + offset.z;
            m_pObj = fleckEmitter.m_pObj;
            offset.x = (float)(offset.x * v28) + this->m_vecOrigin.x;
            offset.y = this->m_vecOrigin.y + (float)(offset.y * v28);
            offset.z = this->m_vecOrigin.z + (float)(offset.z * v28);
            v30 = ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, Vector *))random->RandomInt)(
                    a1: random,
                    a2: 0,
                    a3: 1,
                    a4: &offset);
            v31 = CParticleEffect::AddParticle(
                    this: m_pObj,
                    particleSize: 0x38u,
                    material: g_Mat_Fleck_Cement[v30],
                    origin: (const Vector *)0x41000000);
            v32 = v31;
            if ( v31 == nullptr )
              break;
            v31[2].m_pPrev = nullptr;
            v31[1].m_Pos.z = 3.0;
            dir.x = ((double (__thiscall *)(IUniformRandomStream *, int, int, int, int))random->RandomFloat)(
                      a1: random,
                      a2: -1082130432,
                      a3: 1065353216,
                      a4: v43,
                      a5: v44)
                  + p_m_vecDirection->x;
            dir.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: -1082130432,
                      a3: 1065353216)
                  + this->m_vecDirection.y;
            dir.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: -1082130432,
                      a3: 1065353216)
                  + this->m_vecDirection.z;
            HIBYTE(v32[2].m_pNext) = (int)(float)((float)random->RandomInt(this: random, a2: 1, a3: 3) * this->m_flScale);
            VectorNormalize(vec: &dir);
            v33 = ((double (__stdcall *)(int, int))random->RandomFloat)(a1: 1115684864, a2: 1132462080);
            v34 = dir.z;
            v35 = dir.y;
            *(float *)&colorRamp = v33 * (double)(4 - HIBYTE(v32[2].m_pNext));
            if ( vec3_origin.x == dir.x && vec3_origin.y == dir.y && vec3_origin.z == dir.z )
              goto LABEL_20;
            if ( vec3_origin.x == p_m_vecDirection->x
              && vec3_origin.y == this->m_vecDirection.y
              && vec3_origin.z == this->m_vecDirection.z )
            {
LABEL_20:
              v36 = 1.0;
            }
            else
            {
              v36 = fabs(
                      (float)((float)(dir.x * p_m_vecDirection->x) + (float)(dir.y * this->m_vecDirection.y))
                    + (float)(dir.z * this->m_vecDirection.z))
                  * 0.80000001;
            }
            v37 = (float)((float)((float)(v36 * v36) * 0.5) * 16.0) * *(float *)&colorRamp;
            v38 = v37 * dir.x;
            *(float *)&v32[1].m_pPrev = v37 * dir.x;
            *(float *)&v32[1].m_pNext = v35 * v37;
            *(float *)&v32[1].m_pSubTexture = v34 * v37;
            v39 = this->m_flScale;
            *(float *)&v32[1].m_pPrev = v38 * v39;
            *(float *)&v32[1].m_pNext = *(float *)&v32[1].m_pNext * v39;
            *(float *)&v32[1].m_pSubTexture = *(float *)&v32[1].m_pSubTexture * v39;
            v44 = 1135869952;
            v43 = 0;
            v32[1].m_Pos.x = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
            v32[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                               a1: random,
                               a2: 0,
                               a3: 1135869952);
            *(float *)&colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                     a1: random,
                                     a2: 1056964608,
                                     a3: 1069547520);
            v40 = *(float *)&colorRamp * 0.25;
            if ( (float)(*(float *)&colorRamp * 0.25) <= 1.0 )
              v41 = *(float *)&colorRamp * 0.25;
            else
              v41 = 1.0;
            LOBYTE(v32[2].m_pNext) = (int)(float)(v41 * 255.0);
            if ( v40 <= 1.0 )
              v42 = v40;
            else
              v42 = 1.0;
            BYTE1(v32[2].m_pNext) = (int)(float)(v42 * 255.0);
            if ( v40 > 1.0 )
              v40 = 1.0;
            BYTE2(v32[2].m_pNext) = (int)(float)(v40 * 255.0);
          }
          if ( fleckEmitter.m_pObj != nullptr )
            CParticleEffect::Release(this: fleckEmitter.m_pObj);
          CParticleEffect::Release(this: v49);
        }
        else
        {
          CParticleEffect::Release(this: v6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DAF50
// Name: public: virtual void C_WaterExplosionEffect::Create(class Vector const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterExplosionEffect::Create(
        C_WaterExplosionEffect *this,
        const Vector *position,
        float force,
        float scale,
        int flags)
{
  Vector *p_m_vecOrigin; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float *p_m_flLuminosity; // esi
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  CGameTrace tr; // [esp+24h] [ebp-6Ch] BYREF
  Vector v16; // [esp+78h] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+84h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+90h] [ebp+0h] BYREF

  p_m_vecOrigin = &this->m_vecOrigin;
  this->m_vecOrigin = *position;
  vecAbsEnd.x = this->m_vecOrigin.x;
  vecAbsEnd.y = this->m_vecOrigin.y;
  vecAbsEnd.z = this->m_vecOrigin.z + 512.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)p_m_vecOrigin,
    vecAbsStart: p_m_vecOrigin,
    &vecAbsEnd,
    mask: 0x4030u,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid )
  {
    if ( tr.fractionleftsolid != 0.0 )
    {
      v8 = tr.fractionleftsolid * 512.0;
      v9 = (float)(tr.fractionleftsolid * 0.0) + p_m_vecOrigin->y;
      v10 = (float)(tr.fractionleftsolid * 512.0) + p_m_vecOrigin->z;
      this->m_vecWaterSurface.x = (float)(tr.fractionleftsolid * 0.0) + p_m_vecOrigin->x;
      this->m_vecWaterSurface.y = v9;
      this->m_vecWaterSurface.z = v10;
      this->m_flDepth = v8;
      goto LABEL_10;
    }
    v7 = 512.0;
    goto LABEL_8;
  }
  vecAbsEnd.x = p_m_vecOrigin->x;
  vecAbsEnd.y = p_m_vecOrigin->y;
  vecAbsEnd.z = p_m_vecOrigin->z - 512.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)p_m_vecOrigin,
    vecAbsStart: p_m_vecOrigin,
    &vecAbsEnd,
    mask: 0x4030u,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction >= 1.0 )
  {
    v7 = 0.0;
LABEL_8:
    this->m_vecWaterSurface.x = p_m_vecOrigin->x;
    this->m_vecWaterSurface.y = p_m_vecOrigin->y;
    this->m_vecWaterSurface.z = p_m_vecOrigin->z;
    goto LABEL_9;
  }
  this->m_vecWaterSurface = tr.endpos;
  v7 = 0.0;
LABEL_9:
  this->m_flDepth = v7;
LABEL_10:
  *(_QWORD *)&vecAbsEnd.x = *(_QWORD *)&p_m_vecOrigin->x;
  vecAbsEnd.z = p_m_vecOrigin->z + 32.0;
  v16 = vecAbsEnd;
  p_m_flLuminosity = &this->m_flLuminosity;
  engine->GetLightForPoint(this: engine, result: &vecAbsEnd, a3: &v16, a4: true);
  UTIL_GetNormalizedColorTintAndLuminosity(
    color: &vecAbsEnd,
    tint: &this->m_vecColor,
    luminosity: &this->m_flLuminosity);
  if ( this != (C_WaterExplosionEffect *)-84 )
  {
    v12 = *p_m_flLuminosity * 4.0;
    if ( v12 > 1.0 )
      v12 = 1.0;
    *p_m_flLuminosity = v12;
    if ( v12 < 0.25 )
      *p_m_flLuminosity = 0.25;
  }
  if ( this != (C_WaterExplosionEffect *)-72 )
  {
    v13 = this->m_vecColor.y * 0.25;
    v14 = this->m_vecColor.z * 0.25;
    this->m_vecColor.x = (float)(this->m_vecColor.x * 0.25) + 0.75;
    this->m_vecColor.y = v13 + 0.75;
    this->m_vecColor.z = v14 + 0.75;
  }
  C_BaseExplosionEffect::Create(this, position, force, scale, flags);
}

//------------------------------------------------------------------------------
// Address: 0x100DB1A0
// Name: protected: virtual void C_WaterExplosionEffect::CreateDebris(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall C_WaterExplosionEffect::CreateDebris(C_WaterExplosionEffect *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float v4; // xmm0_4
  CSimpleEmitter *v5; // eax
  CWaterExplosionParticle *v6; // edi
  CWaterExplosionParticle *m_pObj; // esi
  float x; // xmm2_4
  float v9; // xmm0_4
  IUniformRandomStream *v10; // ecx
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  double v13; // st7
  int v14; // eax
  Particle *v15; // eax
  Particle *v16; // edi
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  IUniformRandomStream *v19; // ecx
  Particle *v20; // xmm0_4
  CParticleSubTexture *v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  Particle *v25; // xmm1_4
  CParticleSubTexture *v26; // xmm0_4
  char v27; // al
  Vector color; // [esp+20h] [ebp-48h] BYREF
  Vector worldLight; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector offset; // [esp+38h] [ebp-30h]
  Vector v33; // [esp+44h] [ebp-24h] OVERLAPPED BYREF
  float v34; // [esp+50h] [ebp-18h]
  int i; // [esp+54h] [ebp-14h]
  float v36; // [esp+58h] [ebp-10h]
  CSmartPtr<CWaterExplosionParticle,CRefCountAccessor> pSimple; // [esp+5Ch] [ebp-Ch]
  float force; // [esp+60h] [ebp-8h]
  float spread; // [esp+64h] [ebp-4h]

  if ( (this->m_fFlags & 8) == 0 && this->m_flDepth > 128.0 )
  {
    force = this->m_flForce;
    v4 = force;
    if ( force < 2.0 || force > 2.0 )
    {
      v4 = 2.0;
      force = 2.0;
    }
    spread = 1.0 - (float)(v4 * 0.15000001);
    v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v6 = (CWaterExplosionParticle *)v5;
    if ( v5 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "waterexp_bubbles");
      v6->__vftable = (CWaterExplosionParticle_vtbl *)&CWaterExplosionParticle::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    m_pObj = nullptr;
    pSimple.m_pObj = nullptr;
    if ( v6 != nullptr )
    {
      CParticleEffect::AddRef(this: v6);
      pSimple.m_pObj = v6;
      m_pObj = v6;
    }
    CParticleEffect::SetSortOrigin(this: m_pObj, vSortOrigin: &this->m_vecOrigin);
    CSimpleEmitter::SetNearClip(this: m_pObj, nearClipMin: 64.0, nearClipMax: 128.0);
    x = this->m_vecDirection.x;
    v9 = (float)(this->m_vecDirection.y * 64.0) + this->m_vecOrigin.y;
    offset.z = (float)(this->m_vecDirection.z * 64.0) + this->m_vecOrigin.z;
    offset.x = this->m_vecOrigin.x + (float)(x * 64.0);
    offset.y = v9;
    v33 = offset;
    ((void (__thiscall *)(IVEngineClient *, Vector *, Vector *, int, int, int))engine->GetLightForPoint)(
      a1: engine,
      a2: &color,
      a3: &v33,
      a4: 1,
      a5: a2,
      a6: a3);
    UTIL_GetNormalizedColorTintAndLuminosity(&color, tint: &worldLight, luminosity: nullptr);
    worldLight.x = (float)(worldLight.x * 0.25) + 0.75;
    worldLight.y = (float)(worldLight.y * 0.25) + 0.75;
    worldLight.z = (float)(worldLight.z * 0.25) + 0.75;
    LODWORD(v33.y) = CParticleEffect::GetPMaterial(this: m_pObj, name: "effects/splash1");
    LODWORD(v33.z) = CParticleEffect::GetPMaterial(this: m_pObj, name: "effects/splash2");
    for ( i = 16; i != 0; --i )
    {
      offset.x = _RandomFloat(this: v10, a2: -32.0, a3: 32.0);
      offset.y = _RandomFloat(this: v11, a2: -32.0, a3: 32.0);
      v13 = _RandomFloat(this: v12, a2: -32.0, a3: 32.0);
      offset.x = this->m_vecOrigin.x + offset.x;
      offset.y = offset.y + this->m_vecOrigin.y;
      offset.z = v13 + this->m_vecOrigin.z;
      v14 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
      v15 = CParticleEffect::AddParticle(
              this: m_pObj,
              particleSize: 0x3Cu,
              material: *((CParticleSubTexture **)&v33.y + v14),
              origin: nullptr);
      v16 = v15;
      if ( v15 != nullptr )
      {
        v15[1].m_Pos.z = 0.0;
        v15[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 0x40000000,
                           a3: 1077936128);
        LODWORD(v36) = LODWORD(spread) ^ _mask__NegFloat_;
        *(float *)&v16[1].m_pPrev = _RandomFloat(
                                      this: v17,
                                      a2: COERCE_FLOAT(LODWORD(spread) ^ _mask__NegFloat_),
                                      a3: spread);
        *(float *)&v16[1].m_pNext = _RandomFloat(this: v18, a2: v36, a3: spread);
        *(float *)&v16[1].m_pSubTexture = _RandomFloat(this: v19, a2: v36, a3: spread);
        v34 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1065353216,
                a3: 1086324736);
        *(float *)&v20 = (float)(v34 * this->m_vecDirection.y) + *(float *)&v16[1].m_pNext;
        *(float *)&v21 = (float)(v34 * this->m_vecDirection.z) + *(float *)&v16[1].m_pSubTexture;
        *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev + (float)(this->m_vecDirection.x * v34);
        v16[1].m_pNext = v20;
        v16[1].m_pSubTexture = v21;
        VectorNormalize(vec: (Vector *)&v16[1]);
        v22 = *(float *)&v16[1].m_pPrev;
        v23 = force * 1500.0;
        if ( vec3_origin.x != v22
          || vec3_origin.y != *(float *)&v16[1].m_pNext
          || vec3_origin.z != *(float *)&v16[1].m_pSubTexture )
        {
          v24 = this->m_vecDirection.x;
          if ( vec3_origin.x != v24
            || vec3_origin.y != this->m_vecDirection.y
            || vec3_origin.z != this->m_vecDirection.z )
          {
            v23 = (float)(fabs(
                            (float)((float)(v24 * v22) + (float)(*(float *)&v16[1].m_pNext * this->m_vecDirection.y))
                          + (float)(*(float *)&v16[1].m_pSubTexture * this->m_vecDirection.z))
                        * spread)
                * v23;
          }
        }
        *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev * v23;
        *(float *)&v25 = v23 * *(float *)&v16[1].m_pNext;
        *(float *)&v26 = v23 * *(float *)&v16[1].m_pSubTexture;
        v16[1].m_pNext = v25;
        v16[1].m_pSubTexture = v26;
        LOBYTE(v16[2].m_pPrev) = (int)(float)(this->m_vecColor.x * 255.0);
        BYTE1(v16[2].m_pPrev) = (int)(float)(this->m_vecColor.y * 255.0);
        BYTE2(v16[2].m_pPrev) = (int)(float)(this->m_vecColor.z * 255.0);
        v27 = random->RandomInt(this: random, a2: 32, a3: 64);
        BYTE1(v16[2].m_pNext) = v27;
        BYTE2(v16[2].m_pNext) = 2 * v27;
        *(_WORD *)((char *)&v16[2].m_pPrev + 3) = (unsigned __int8)(int)this->m_flLuminosity;
        v16[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v16[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1056964608,
                                            a3: 1090519040);
        m_pObj = pSimple.m_pObj;
      }
    }
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DB6B0
// Name: protected: virtual void C_WaterExplosionEffect::CreateMisc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_WaterExplosionEffect::CreateMisc(C_WaterExplosionEffect *this)
{
  CParticleMgr *v2; // eax
  CTrailParticles *v3; // eax
  CTrailParticles *v4; // eax
  CTrailParticles *v5; // edi
  Vector *p_m_vecWaterSurface; // ebx
  float z; // xmm0_4
  double y; // st7
  double v9; // st7
  double v10; // st7
  Particle *v11; // eax
  Particle *v12; // esi
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  Particle *v17; // xmm1_4
  Particle *v18; // xmm2_4
  double v19; // st7
  double v20; // st7
  double v21; // st7
  int v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float m_flLuminosity; // xmm1_4
  int v27; // eax
  float v28; // xmm0_4
  double v29; // st7
  double v30; // st7
  double v31; // st7
  Particle *v32; // eax
  Particle *v33; // esi
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  IUniformRandomStream *v36; // ecx
  float (__thiscall *v37)(IUniformRandomStream *, float, float); // edx
  Particle *v38; // xmm1_4
  Particle *v39; // xmm2_4
  double v40; // st7
  double v41; // st7
  double v42; // st7
  int v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm4_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  int v48; // eax
  CSimpleEmitter *v49; // eax
  CSplashParticle *v50; // esi
  CSplashParticle *v51; // edi
  CSplashParticle *m_pObj; // esi
  float x; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm3_4
  Particle *v56; // eax
  IUniformRandomStream *v57; // ecx
  Particle *v58; // edi
  float *v59; // esi
  IUniformRandomStream *v60; // ecx
  IUniformRandomStream *v61; // ecx
  double v62; // st7
  float v63; // xmm0_4
  Particle *v64; // xmm1_4
  float *v65; // ecx
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  int v70; // edx
  float v71; // xmm0_4
  float v72; // xmm3_4
  float v73; // xmm1_4
  unsigned int v74; // eax
  float v75; // xmm1_4
  Vector bbMax; // [esp+64h] [ebp-40h] BYREF
  Vector bbMin; // [esp+70h] [ebp-34h] BYREF
  Vector offset; // [esp+7Ch] [ebp-28h] BYREF
  CParticleEffect *v79; // [esp+88h] [ebp-1Ch]
  int j; // [esp+8Ch] [ebp-18h]
  CParticleSubTexture *hMaterial; // [esp+90h] [ebp-14h]
  CSmartPtr<CSplashParticle,CRefCountAccessor> pSimple; // [esp+94h] [ebp-10h]
  C_WaterExplosionEffect *v83; // [esp+98h] [ebp-Ch]
  float colorRamp; // [esp+9Ch] [ebp-8h]
  int i; // [esp+A0h] [ebp-4h]

  v83 = this;
  v2 = ParticleMgr();
  hMaterial = CParticleMgr::GetPMaterial(this: v2, pMaterialName: "effects/splash2");
  v3 = (CTrailParticles *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v3 != nullptr )
  {
    v4 = CTrailParticles::CTrailParticles(this: v3, pDebugName: "splash");
    v5 = v4;
    v79 = v4;
    if ( v4 != nullptr )
    {
      CParticleEffect::AddRef(this: v4);
      p_m_vecWaterSurface = &this->m_vecWaterSurface;
      CParticleEffect::SetSortOrigin(this: v5, vSortOrigin: p_m_vecWaterSurface);
      v5->m_ParticleCollision.m_flGravity = 800.0;
      v5->m_fFlags |= 1u;
      v5->m_flVelocityDampen = 2.0;
      i = 0;
      do
      {
        z = p_m_vecWaterSurface->z;
        offset.x = p_m_vecWaterSurface->x;
        y = p_m_vecWaterSurface->y;
        offset.z = z;
        offset.y = y;
        v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1048576000,
               a3: 1098907648);
        offset.x = v9 + v9 + offset.x;
        v10 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1048576000,
                a3: 1098907648);
        offset.y = v10 + v10 + offset.y;
        v11 = CParticleEffect::AddParticle(this: v5, particleSize: 0x38u, material: hMaterial, origin: &offset);
        v12 = v11;
        if ( v11 == nullptr )
          break;
        v11[1].m_Pos.z = 0.0;
        v11[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1056964608,
                           a3: 1065353216);
        bbMin.x = _RandomFloat(this: v13, a2: -1.0, a3: 1.0);
        bbMin.y = _RandomFloat(this: v14, a2: -1.0, a3: 1.0);
        bbMin.z = _RandomFloat(this: v15, a2: -1.0, a3: 1.0);
        RandomFloat = random->RandomFloat;
        bbMax.y = bbMin.y;
        bbMax.z = bbMin.z + 1.0;
        bbMax.x = 400.0;
        *(float *)&j = ((double (__thiscall *)(IUniformRandomStream *, int))RandomFloat)(a1: random, a2: 1128792064);
        *(float *)&v17 = 400.0 * *(float *)&j;
        *(float *)&v18 = bbMin.y * *(float *)&j;
        *(float *)&v12[1].m_pSubTexture = (float)(bbMin.z + 1.0) * *(float *)&j;
        v12[1].m_pPrev = v17;
        v12[1].m_pNext = v18;
        v19 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1107296256,
                a3: 1124073472);
        *(float *)&v12[1].m_pSubTexture = v19 + v19 + *(float *)&v12[1].m_pSubTexture;
        v20 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1065353216,
                a3: 1077936128);
        v21 = v20 + v20;
        *(float *)&j = v21;
        if ( v21 >= 0.1 )
        {
          v22 = 1082130432;
          if ( *(float *)&j <= 4.0 )
            v22 = j;
        }
        else
        {
          v22 = 1036831949;
        }
        v12[2].m_pNext = (Particle *)v22;
        *(float *)&v12[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1020054733,
                                      a3: 1036831949);
        colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1069547520,
                      a3: 0x40000000);
        v23 = v83->m_vecColor.z * colorRamp;
        if ( v23 > 1.0 )
          v23 = 1.0;
        v24 = v83->m_vecColor.y * colorRamp;
        if ( v24 > 1.0 )
          v24 = 1.0;
        v25 = v83->m_vecColor.x * colorRamp;
        if ( v25 > 1.0 )
          v25 = 1.0;
        m_flLuminosity = v83->m_flLuminosity;
        BYTE2(v12[1].m_Pos.x) = (int)(float)(v23 * 255.0);
        v27 = i + 1;
        LOBYTE(v12[1].m_Pos.x) = (int)(float)(v25 * 255.0);
        BYTE1(v12[1].m_Pos.x) = (int)(float)(v24 * 255.0);
        HIBYTE(v12[1].m_Pos.x) = (int)(float)(m_flLuminosity * 255.0);
        i = v27;
      }
      while ( v27 < 32 );
      i = 0;
      do
      {
        v28 = p_m_vecWaterSurface->z;
        offset.x = p_m_vecWaterSurface->x;
        v29 = p_m_vecWaterSurface->y;
        offset.z = v28;
        offset.y = v29;
        v30 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1048576000,
                a3: 1098907648);
        offset.x = v30 + v30 + offset.x;
        v31 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1048576000,
                a3: 1098907648);
        offset.y = v31 + v31 + offset.y;
        v32 = CParticleEffect::AddParticle(this: v5, particleSize: 0x38u, material: hMaterial, origin: &offset);
        v33 = v32;
        if ( v32 == nullptr )
          break;
        v32[1].m_Pos.z = 0.0;
        v32[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1056964608,
                           a3: 1065353216);
        bbMax.x = _RandomFloat(this: v34, a2: -0.2, a3: 0.2);
        bbMax.y = _RandomFloat(this: v35, a2: -0.2, a3: 0.2);
        bbMax.z = _RandomFloat(this: v36, a2: -0.2, a3: 0.2);
        v37 = random->RandomFloat;
        bbMin.x = bbMax.x;
        bbMin.y = bbMax.y;
        bbMin.z = bbMax.z + 1.0;
        *(float *)&j = ((double (__thiscall *)(IUniformRandomStream *, int, int))v37)(
                         a1: random,
                         a2: 1133903872,
                         a3: 1142292480);
        *(float *)&v38 = bbMin.x * *(float *)&j;
        *(float *)&v39 = bbMax.y * *(float *)&j;
        *(float *)&v33[1].m_pSubTexture = (float)(bbMax.z + 1.0) * *(float *)&j;
        v33[1].m_pPrev = v38;
        v33[1].m_pNext = v39;
        v40 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1107296256,
                a3: 1124073472);
        *(float *)&v33[1].m_pSubTexture = v40 + v40 + *(float *)&v33[1].m_pSubTexture;
        v41 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 0x40000000,
                a3: 1077936128);
        v42 = v41 + v41;
        *(float *)&j = v42;
        if ( v42 >= 0.1 )
        {
          v43 = 1082130432;
          if ( *(float *)&j <= 4.0 )
            v43 = j;
        }
        else
        {
          v43 = 1036831949;
        }
        v33[2].m_pNext = (Particle *)v43;
        *(float *)&v33[2].m_pPrev = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                      a1: random,
                                      a2: 1020054733,
                                      a3: 1036831949);
        colorRamp = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1069547520,
                      a3: 0x40000000);
        v44 = v83->m_vecColor.z * colorRamp;
        if ( v44 > 1.0 )
          v44 = 1.0;
        v45 = v83->m_vecColor.y * colorRamp;
        if ( v45 > 1.0 )
          v45 = 1.0;
        v46 = v83->m_vecColor.x * colorRamp;
        if ( v46 > 1.0 )
          v46 = 1.0;
        v47 = v83->m_flLuminosity;
        LOBYTE(v33[1].m_Pos.x) = (int)(float)(v46 * 255.0);
        HIBYTE(v33[1].m_Pos.x) = (int)(float)(v47 * 255.0);
        v48 = i + 1;
        BYTE1(v33[1].m_Pos.x) = (int)(float)(v45 * 255.0);
        BYTE2(v33[1].m_Pos.x) = (int)(float)(v44 * 255.0);
        i = v48;
      }
      while ( v48 < 4 );
      v49 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x110u);
      v50 = (CSplashParticle *)v49;
      if ( v49 != nullptr )
      {
        CSimpleEmitter::CSimpleEmitter(this: v49, pDebugName: "splish");
        v50->__vftable = (CSplashParticle_vtbl *)&CSplashParticle::`vftable';
        v50->m_bUseClipHeight = false;
        v51 = v50;
      }
      else
      {
        v51 = nullptr;
      }
      m_pObj = nullptr;
      pSimple.m_pObj = nullptr;
      if ( v51 != nullptr )
      {
        CParticleEffect::AddRef(this: v51);
        pSimple.m_pObj = v51;
        m_pObj = v51;
      }
      CParticleEffect::SetSortOrigin(this: m_pObj, vSortOrigin: p_m_vecWaterSurface);
      CSplashParticle::SetClipHeight(this: m_pObj, flClipHeight: v83->m_vecWaterSurface.z);
      x = p_m_vecWaterSurface->x;
      bbMax.x = p_m_vecWaterSurface->x + 64.0;
      v54 = p_m_vecWaterSurface->y;
      bbMax.y = v54 + 64.0;
      v55 = p_m_vecWaterSurface->z - 64.0;
      bbMax.z = p_m_vecWaterSurface->z + 64.0;
      bbMin.x = x - 64.0;
      bbMin.y = v54 - 64.0;
      bbMin.z = v55;
      CParticleEffectBinding::SetBBox(this: &m_pObj->m_ParticleEffect, &bbMin, &bbMax, bDisableAutoUpdate: true);
      i = 0;
      for ( j = 8; j > -8; --j )
      {
        v56 = CParticleEffect::AddParticle(
                this: m_pObj,
                particleSize: 0x3Cu,
                material: hMaterial,
                origin: p_m_vecWaterSurface);
        v58 = v56;
        if ( v56 == nullptr )
          break;
        v56[1].m_Pos.z = 0.0;
        v56[1].m_Pos.y = 2.0;
        v59 = (float *)&v56[1];
        *(float *)&v56[1].m_pPrev = _RandomFloat(this: v57, a2: -0.2, a3: 0.2);
        *(float *)&v58[1].m_pNext = _RandomFloat(this: v60, a2: -0.2, a3: 0.2);
        *(float *)&v58[1].m_pSubTexture = _RandomFloat(this: v61, a2: -0.2, a3: 0.2);
        v62 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1082130432,
                a3: 1086324736);
        *v59 = *v59;
        LODWORD(bbMax.x) = &v58[1];
        v58[1].m_pNext = v58[1].m_pNext;
        *(float *)&v58[1].m_pSubTexture = v62 + *(float *)&v58[1].m_pSubTexture;
        VectorNormalize(vec: (Vector *)LODWORD(bbMax.x));
        v63 = (float)j * 100.0;
        *v59 = *v59 * v63;
        *(float *)&v64 = v63 * *(float *)&v58[1].m_pNext;
        *(float *)&v58[1].m_pSubTexture = v63 * *(float *)&v58[1].m_pSubTexture;
        v58[1].m_pNext = v64;
        colorRamp = ((double (__cdecl *)(int, int))random->RandomFloat)(a1: 1061158912, a2: 1067450368);
        v65 = (float *)v83;
        v66 = colorRamp;
        v67 = v83->m_vecColor.x * colorRamp;
        if ( v67 > 1.0 )
          v67 = 1.0;
        LOBYTE(v58[2].m_pPrev) = (int)(float)(v67 * 255.0);
        v68 = v65[19] * v66;
        if ( v68 > 1.0 )
          v68 = 1.0;
        BYTE1(v58[2].m_pPrev) = (int)(float)(v68 * 255.0);
        v69 = v65[20] * v66;
        if ( v69 > 1.0 )
          v69 = 1.0;
        v70 = (int)(float)(v69 * 255.0);
        v71 = (float)((float)i - 7.0) * -0.14285715;
        v72 = v71;
        BYTE2(v58[2].m_pPrev) = v70;
        if ( v71 >= 0.0 )
        {
          if ( v71 > 1.0 )
            v72 = 1.0;
        }
        else
        {
          v72 = 0.0;
        }
        v73 = (float)(1.0 - (float)(v72 * 0.5)) * 48.0;
        BYTE1(v58[2].m_pNext) = (int)v73;
        v74 = 2 * (unsigned __int8)(int)v73;
        if ( v74 > 0xFF )
          LOBYTE(v74) = -1;
        BYTE2(v58[2].m_pNext) = v74;
        if ( v71 >= 0.0 )
          v75 = v71 <= 1.0 ? v71 : 1.0;
        else
          v75 = 0.0;
        *(_WORD *)((char *)&v58[2].m_pPrev + 3) = (unsigned __int8)(int)(float)(v65[21]
                                                                              * (float)(255.0 - (float)(v75 * 223.0)));
        v58[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v58[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1065353216,
                                            a3: 1082130432);
        ++i;
        m_pObj = pSimple.m_pObj;
      }
      if ( m_pObj != nullptr )
        CParticleEffect::Release(this: m_pObj);
      CParticleEffect::Release(this: v79);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DC160
// Name: protected: virtual void C_MegaBombExplosionEffect::CreateCore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MegaBombExplosionEffect::CreateCore(C_MegaBombExplosionEffect *this)
{
  float m_flForce; // xmm0_4
  CSimpleEmitter *v3; // eax
  CExplosionParticle *v4; // edi
  CExplosionParticle *m_pObj; // esi
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  double v9; // st7
  CParticleSubTexture *m_Material_FireCloud; // ecx
  double v11; // st6
  Particle *v12; // eax
  Particle *v13; // edi
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  IUniformRandomStream *v16; // ecx
  CParticleSubTexture *v17; // xmm0_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float x; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  char v23; // al
  int v24; // eax
  float v25; // xmm0_4
  int v26; // ecx
  Vector offset; // [esp+14h] [ebp-28h] BYREF
  float fForce; // [esp+20h] [ebp-1Ch]
  int i; // [esp+24h] [ebp-18h]
  float vDev; // [esp+28h] [ebp-14h]
  float spread; // [esp+2Ch] [ebp-10h]
  float v32; // [esp+30h] [ebp-Ch]
  float v33; // [esp+34h] [ebp-8h]
  CSmartPtr<CExplosionParticle,CRefCountAccessor> pSimple; // [esp+38h] [ebp-4h]

  if ( (this->m_fFlags & 0x40) == 0 )
  {
    m_flForce = this->m_flForce;
    if ( m_flForce < 2.0 || m_flForce > 2.0 )
      m_flForce = 2.0;
    spread = 1.0 - (float)(m_flForce * 0.15000001);
    v3 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v4 = (CExplosionParticle *)v3;
    if ( v3 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v3, pDebugName: "exp_smoke");
      v4->__vftable = (CExplosionParticle_vtbl *)&CExplosionParticle::`vftable';
    }
    else
    {
      v4 = nullptr;
    }
    m_pObj = nullptr;
    pSimple.m_pObj = nullptr;
    if ( v4 != nullptr )
    {
      CParticleEffect::AddRef(this: v4);
      pSimple.m_pObj = v4;
      m_pObj = v4;
    }
    CParticleEffect::SetSortOrigin(this: m_pObj, vSortOrigin: &this->m_vecOrigin);
    CSimpleEmitter::SetNearClip(this: m_pObj, nearClipMin: 32.0, nearClipMax: 64.0);
    if ( this->m_Material_FireCloud == nullptr )
      this->m_Material_FireCloud = CParticleEffect::GetPMaterial(this: m_pObj, name: "effects/fire_cloud2");
    for ( i = 32; i != 0; --i )
    {
      offset.x = _RandomFloat(this: v6, a2: -48.0, a3: 48.0);
      offset.y = _RandomFloat(this: v7, a2: -48.0, a3: 48.0);
      v9 = _RandomFloat(this: v8, a2: -48.0, a3: 48.0);
      m_Material_FireCloud = this->m_Material_FireCloud;
      offset.x = this->m_vecOrigin.x + offset.x;
      LODWORD(offset.z) = &offset;
      v11 = this->m_vecOrigin.y + *(float *)&m_Material_FireCloud;
      LODWORD(offset.x) = 60;
      offset.y = v11;
      offset.z = v9 + this->m_vecOrigin.z;
      v12 = CParticleEffect::AddParticle(
              this: m_pObj,
              particleSize: 0x3Cu,
              material: (CParticleSubTexture *)LODWORD(offset.y),
              origin: (const Vector *)LODWORD(offset.z));
      v13 = v12;
      if ( v12 != nullptr )
      {
        v12[1].m_Pos.z = 0.0;
        v12[1].m_Pos.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1045220557,
                           a3: 1053609165);
        v32 = spread * -0.75;
        v33 = spread * 0.75;
        *(float *)&v13[1].m_pPrev = _RandomFloat(this: v14, a2: spread * -0.75, a3: spread * 0.75);
        *(float *)&v13[1].m_pNext = _RandomFloat(this: v15, a2: v32, a3: v33);
        *(float *)&v13[1].m_pSubTexture = _RandomFloat(this: v16, a2: v32, a3: v33);
        *(float *)&v13[1].m_pPrev = *(float *)&v13[1].m_pPrev + this->m_vecDirection.x;
        *(float *)&v13[1].m_pNext = this->m_vecDirection.y + *(float *)&v13[1].m_pNext;
        *(float *)&v17 = this->m_vecDirection.z + *(float *)&v13[1].m_pSubTexture;
        i = (int)&v13[1];
        v13[1].m_pSubTexture = v17;
        VectorNormalize(vec: (Vector *)i);
        RandomFloat = random->RandomFloat;
        spread = 800.0;
        fForce = ((double (__thiscall *)(IUniformRandomStream *, int))RandomFloat)(a1: random, a2: 1137180672);
        if ( vec3_origin.x == *(float *)&v13[1].m_pPrev
          && vec3_origin.y == *(float *)&v13[1].m_pNext
          && vec3_origin.z == *(float *)&v13[1].m_pSubTexture
          || (x = this->m_vecDirection.x, vec3_origin.x == x)
          && vec3_origin.y == this->m_vecDirection.y
          && vec3_origin.z == this->m_vecDirection.z )
        {
          v20 = 1.0;
        }
        else
        {
          v20 = COERCE_FLOAT(
                  COERCE_UNSIGNED_INT(
                    (float)((float)(*(float *)&v13[1].m_pNext * this->m_vecDirection.y)
                          + (float)(*(float *)&v13[1].m_pPrev * x))
                  + (float)(*(float *)&v13[1].m_pSubTexture * this->m_vecDirection.z))
                & _mask__AbsFloat_)
              * spread;
        }
        v21 = (float)((float)((float)(v20 * v20) * 0.5) * 16.0) * fForce;
        vDev = v20;
        *(float *)&v13[1].m_pPrev = *(float *)&v13[1].m_pPrev * v21;
        *(float *)&v13[1].m_pNext = *(float *)&v13[1].m_pNext * v21;
        *(float *)&v13[1].m_pSubTexture = *(float *)&v13[1].m_pSubTexture * v21;
        RandomInt = random->RandomInt;
        i = 255;
        v23 = ((int (__thiscall *)(IUniformRandomStream *, int))RandomInt)(a1: random, a2: 128);
        BYTE2(v13[2].m_pPrev) = v23;
        BYTE1(v13[2].m_pPrev) = v23;
        LOBYTE(v13[2].m_pPrev) = v23;
        v24 = random->RandomInt(this: random, a2: 32, a3: 85);
        v25 = (float)v24 * vDev;
        v26 = (int)v25;
        BYTE1(v13[2].m_pNext) = (int)v25;
        if ( (unsigned __int8)(int)v25 >= 0x20u )
        {
          if ( (unsigned __int8)(int)v25 > 0x55u )
            LOBYTE(v26) = 85;
        }
        else
        {
          LOBYTE(v26) = 32;
        }
        BYTE2(v13[2].m_pNext) = (int)(float)((float)(unsigned __int8)v26 * 1.5);
        BYTE1(v13[2].m_pNext) = v26;
        *(_WORD *)((char *)&v13[2].m_pPrev + 3) = 255;
        v13[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v13[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1048576000,
                                            a3: 1098907648);
        m_pObj = pSimple.m_pObj;
      }
    }
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AEC0
// Name: public: virtual float CExplosionParticle::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CExplosionParticle::UpdateRoll(CExplosionParticle *this, SimpleParticle *pParticle, float timeDelta)
{
  float v3; // xmm1_4
  float v4; // xmm0_4

  v3 = 0.5;
  v4 = (float)((float)(timeDelta * -8.0) + 1.0) * pParticle->m_flRollDelta;
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
// Address: 0x10415D10
// Name: PrecacheEffectExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectExplosionPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectExplosionPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415D60
// Name: ExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ExplosionPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ExplosionPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415DB0
// Name: WaterSurfaceExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int WaterSurfaceExplosionPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  WaterSurfaceExplosionPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&WaterSurfaceExplosionPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415E00
// Name: HelicopterMegaBombPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int HelicopterMegaBombPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  HelicopterMegaBombPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&HelicopterMegaBombPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415D30
// Name: _dynamic_initializer_for__C_BaseExplosionEffect::m_instance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__C_BaseExplosionEffect::m_instance__()
{
  return atexit(func: dynamic_atexit_destructor_for__C_BaseExplosionEffect::m_instance__);
}

//------------------------------------------------------------------------------
// Address: 0x10415D40
// Name: _dynamic_initializer_for__ClientEffectReg_ExplosionCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ExplosionCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ExplosionCallback,
           pEffectName: "Explosion",
           fn: ExplosionCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415D80
// Name: _dynamic_initializer_for__C_WaterExplosionEffect::m_waterinstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__C_WaterExplosionEffect::m_waterinstance__()
{
  return atexit(func: dynamic_atexit_destructor_for__C_WaterExplosionEffect::m_waterinstance__);
}

//------------------------------------------------------------------------------
// Address: 0x10415D90
// Name: _dynamic_initializer_for__ClientEffectReg_WaterSurfaceExplosionCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_WaterSurfaceExplosionCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_WaterSurfaceExplosionCallback,
           pEffectName: "WaterSurfaceExplosion",
           fn: WaterSurfaceExplosionCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415DD0
// Name: _dynamic_initializer_for__C_MegaBombExplosionEffect::m_megainstance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__C_MegaBombExplosionEffect::m_megainstance__()
{
  return atexit(func: dynamic_atexit_destructor_for__C_MegaBombExplosionEffect::m_megainstance__);
}

//------------------------------------------------------------------------------
// Address: 0x10415DE0
// Name: _dynamic_initializer_for__ClientEffectReg_HelicopterMegaBombCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_HelicopterMegaBombCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_HelicopterMegaBombCallback,
           pEffectName: "HelicopterMegaBomb",
           fn: HelicopterMegaBombCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415E20
// Name: _dynamic_initializer_for__r_drawflecks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawflecks__()
{
  ConVar::ConVar(this: &r_drawflecks, pName: "r_drawflecks", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_drawflecks__);
}

//------------------------------------------------------------------------------
// Address: 0x10415E50
// Name: _dynamic_initializer_for__r_impacts_alt_orientation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_impacts_alt_orientation__()
{
  ConVar::ConVar(this: &r_impacts_alt_orientation, pName: "r_impacts_alt_orientation", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_impacts_alt_orientation__);
}

//------------------------------------------------------------------------------
// Address: 0x10415E80
// Name: _dynamic_initializer_for__ClientEffectReg_RagdollImpactCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_RagdollImpactCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_RagdollImpactCallback,
           pEffectName: "RagdollImpact",
           fn: RagdollImpactCallback);
}
