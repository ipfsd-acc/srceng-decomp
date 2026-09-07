// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientsideeffects_test.cpp
// Functions: 13
// ============================================================

#include "game\client\clientsideeffects_test.h"

//------------------------------------------------------------------------------
// Address: 0x100BECC0
// Name: public: virtual void PrecacheEffectsTestPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectsTestPrecache::CResourcePrecacher::Cache(
        PrecacheEffectsTestPrecache::CResourcePrecacher *this,
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
    a3: "effects/gunshiptracer",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/bluespark",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100BED10
// Name: void FX_AddLine(struct FXLineData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_AddLine(const FXLineData_t *data)
{
  CFXLine *v1; // eax
  CFXLine *v2; // eax

  v1 = (CFXLine *)MemAlloc_Alloc(nSize: 0x58u);
  if ( v1 != nullptr )
  {
    v2 = CFXLine::CFXLine(this: v1, name: "Line", data);
    clienteffects->AddEffect(this: clienteffects, a2: v2);
  }
  else
  {
    clienteffects->AddEffect(this: clienteffects, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BED60
// Name: void FX_AddDiscreetLine(class Vector const __near &,class Vector const __near &,float,float,float,float,float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_AddDiscreetLine(
        const Vector *start,
        const Vector *direction,
        float velocity,
        float length,
        float clipLength,
        float scale,
        float life,
        const char *shader)
{
  CFXDiscreetLine *v8; // eax
  CFXDiscreetLine *v9; // eax

  v8 = (CFXDiscreetLine *)MemAlloc_Alloc(nSize: 0x40u);
  if ( v8 != nullptr )
  {
    v9 = CFXDiscreetLine::CFXDiscreetLine(
           this: v8,
           name: "Line",
           start,
           direction,
           velocity,
           length,
           clipLength,
           scale,
           life,
           shader);
    clienteffects->AddEffect(this: clienteffects, a2: v9);
  }
  else
  {
    clienteffects->AddEffect(this: clienteffects, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEDF0
// Name: void FX_AddQuad(struct FXQuadData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_AddQuad(const FXQuadData_t *data)
{
  CFXQuad *v1; // eax
  CFXQuad *v2; // eax

  v1 = (CFXQuad *)MemAlloc_Alloc(nSize: 0x60u);
  if ( v1 != nullptr )
  {
    v2 = CFXQuad::CFXQuad(this: v1, data);
    clienteffects->AddEffect(this: clienteffects, a2: v2);
  }
  else
  {
    clienteffects->AddEffect(this: clienteffects, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEE30
// Name: void FX_AddQuad(class Vector const __near &,class Vector const __near &,float,float,float,float,float,float,float,float,class Vector const __near &,float,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_AddQuad(
        const Vector *origin,
        const Vector *normal,
        float startSize,
        float endSize,
        float sizeBias,
        float startAlpha,
        float endAlpha,
        float alphaBias,
        float yaw,
        float deltaYaw,
        const Vector *color,
        float lifeTime,
        const char *shader,
        unsigned int flags)
{
  IMaterial *v14; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  CFXQuad *v17; // eax
  CFXQuad *v18; // eax
  FXQuadData_t data; // [esp+0h] [ebp-54h] BYREF

  data.m_flLifeTime = 0.0;
  data.m_flDieTime = 0.0;
  data.m_flStartAlpha = startAlpha;
  data.m_flEndAlpha = endAlpha;
  data.m_flStartScale = startSize;
  data.m_uiFlags = flags;
  data.m_flEndScale = endSize;
  v14 = materials->FindMaterial(this: materials, a2: shader, a3: "ClientEffect textures", a4: 1, a5: 0);
  data.m_pMaterial = v14;
  if ( v14 != nullptr )
    v14->IncrementReferenceCount(this: v14);
  data.m_vecNormal = *normal;
  data.m_vecOrigin.x = origin->x;
  data.m_vecOrigin.y = origin->y;
  y = color->y;
  z = color->z;
  data.m_vecOrigin.z = origin->z;
  data.m_flDieTime = lifeTime;
  data.m_Color.x = color->x;
  data.m_flScaleBias = sizeBias;
  data.m_flAlphaBias = alphaBias;
  data.m_flYaw = yaw;
  data.m_Color.y = y;
  data.m_Color.z = z;
  data.m_flDeltaYaw = deltaYaw;
  v17 = (CFXQuad *)MemAlloc_Alloc(nSize: 0x60u);
  if ( v17 != nullptr )
  {
    v18 = CFXQuad::CFXQuad(this: v17, &data);
    clienteffects->AddEffect(this: clienteffects, a2: v18);
  }
  else
  {
    clienteffects->AddEffect(this: clienteffects, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEF70
// Name: void FX_PlayerTracer(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_PlayerTracer(Vector *start, Vector *end)
{
  double v3; // st7
  float v4; // xmm1_4
  CFXStaticLine *v5; // esi
  CFXStaticLine *v6; // eax
  float scale; // [esp+2Ch] [ebp-38h]
  Vector dEnd; // [esp+40h] [ebp-24h] BYREF
  Vector dStart; // [esp+4Ch] [ebp-18h] BYREF
  Vector shotDir; // [esp+58h] [ebp-Ch] BYREF
  float length; // [esp+6Ch] [ebp+8h]
  float enda; // [esp+70h] [ebp+Ch]
  float endb; // [esp+70h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_PlayerTracer",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  shotDir.x = end->x - start->x;
  shotDir.y = end->y - start->y;
  shotDir.z = end->z - start->z;
  v3 = VectorNormalize(vec: &shotDir);
  length = v3;
  if ( v3 >= 256.0 )
  {
    enda = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
             a1: random,
             a2: -1044381696,
             a3: 1115684864)
         + 8.0;
    dStart.x = (float)(shotDir.x * enda) + start->x;
    v4 = (float)(enda * shotDir.y) + start->y;
    dStart.z = (float)(enda * shotDir.z) + start->z;
    dStart.y = v4;
    endb = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
             a1: random,
             a2: 1036831949,
             a3: 1058642330)
         * length;
    dEnd.x = (float)(endb * shotDir.x) + dStart.x;
    dEnd.y = (float)(endb * shotDir.y) + v4;
    dEnd.z = (float)(endb * shotDir.z) + dStart.z;
    v5 = (CFXStaticLine *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v5 != nullptr )
    {
      scale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1056964608,
                a3: 1061158912);
      v6 = CFXStaticLine::CFXStaticLine(
             this: v5,
             name: "Tracer",
             start: &dStart,
             end: &dEnd,
             scale,
             life: 0.0099999998,
             shader: "effects/spark",
             flags: 0);
    }
    else
    {
      v6 = nullptr;
    }
    clienteffects->AddEffect(this: clienteffects, a2: v6);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100BF150
// Name: public: virtual void CBulletWhizTimer::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBulletWhizTimer::LevelInitPreEntity(CBulletWhizTimer *this)
{
  this->m_nextWhizTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100BF190
// Name: void FX_TracerSound(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FX_TracerSound(float a1@<ebp>, const Vector *start, const Vector *end, int iTracerType)
{
  float m_fValue; // xmm0_4
  float v5; // xmm0_4
  double v6; // st7
  float v7; // xmm0_4
  _BYTE v8[12]; // [esp+5Ch] [ebp-1BCh] BYREF
  Ray_t bullet; // [esp+68h] [ebp-1B0h] BYREF
  Ray_t listener; // [esp+B8h] [ebp-160h] BYREF
  int v11; // [esp+108h] [ebp-110h]
  int v12; // [esp+10Ch] [ebp-10Ch]
  CSoundParameters params; // [esp+110h] [ebp-108h] BYREF
  CLocalPlayerFilter filter; // [esp+1C8h] [ebp-50h] BYREF
  Vector s; // [esp+1E8h] [ebp-30h] OVERLAPPED BYREF
  Vector vecListenOrigin; // [esp+1F4h] [ebp-24h] BYREF
  Vector shotDir; // [esp+200h] [ebp-18h]
  float flMinWhizTime; // [esp+20Ch] [ebp-Ch]
  float flWhizDist; // [esp+210h] [ebp-8h]
  float retaddr; // [esp+218h] [ebp+0h]

  flMinWhizTime = a1;
  flWhizDist = retaddr;
  shotDir.y = 72.0;
  shotDir.x = 0.1;
  *(_DWORD *)&filter.m_bUsingPredictionRules = 1036831949;
  s = *MainViewOrigin(nSlot: 0);
  switch ( iTracerType )
  {
    case 1:
      m_fValue = cl_tracer_whiz_distance.m_pParent->m_Value.m_fValue;
      LODWORD(shotDir.z) = "Bullets.DefaultNearmiss";
      shotDir.y = m_fValue;
      bullet.m_Extents.y = 0.0;
      listener.m_Extents.y = 0.0;
      Ray_t::Init(this: (Ray_t *)v8, start, end);
      *(_QWORD *)&vecListenOrigin.x = *(_QWORD *)&s.x;
      vecListenOrigin.z = s.z - 24.0;
      Ray_t::Init(this: (Ray_t *)&bullet.m_IsRay, start: &s, end: &vecListenOrigin);
      IntersectRayWithRay(
        ray0: (const Ray_t *)v8,
        ray1: (const Ray_t *)&bullet.m_IsRay,
        t: (float *)&filter.m_Recipients.m_Size,
        s: (float *)&filter.m_Recipients.m_pElements);
      v5 = *(float *)&filter.m_Recipients.m_pElements;
      if ( *(float *)&filter.m_Recipients.m_pElements >= 0.0 )
      {
        if ( *(float *)&filter.m_Recipients.m_pElements > 1.0 )
          v5 = 1.0;
      }
      else
      {
        v5 = 0.0;
      }
      s.z = s.z - (float)(v5 * 24.0);
      goto LABEL_10;
    case 2:
      LODWORD(shotDir.z) = "Bullets.GunshipNearmiss";
      goto LABEL_10;
    case 4:
      LODWORD(shotDir.z) = "Bullets.StriderNearmiss";
      goto LABEL_10;
    case 16:
      shotDir.y = 48.0;
      shotDir.x = 0.30000001;
      LODWORD(shotDir.z) = "Underwater.BulletImpact";
      *(_DWORD *)&filter.m_bUsingPredictionRules = 1058642330;
LABEL_10:
      if ( (float)(g_BulletWhiz.m_nextWhizTime - *(float *)(gpGlobals.m_Index + 12)) <= 0.0 )
      {
        v6 = CalcDistanceSqrToLineSegment(P: &s, vLineA: start, vLineB: end, outT: nullptr);
        if ( v6 < shotDir.y * shotDir.y )
        {
          CSoundParameters::CSoundParameters(this: (CSoundParameters *)(&listener.m_IsSwept + 7));
          if ( C_BaseEntity::GetParametersForSound(
                 soundname: (const char *)LODWORD(shotDir.z),
                 params: (CSoundParameters *)(&listener.m_IsSwept + 7),
                 actormodel: nullptr) )
          {
            vecListenOrigin.x = end->x - start->x;
            vecListenOrigin.y = end->y - start->y;
            vecListenOrigin.z = end->z - start->z;
            VectorNormalize(vec: &vecListenOrigin);
            CLocalPlayerFilter::CLocalPlayerFilter(this: (CLocalPlayerFilter *)&params.m_pOperatorsKV);
            if ( params.pitch <= 50 )
            {
              if ( params.pitch != 0 )
                v7 = 4.0;
              else
                v7 = 0.0;
            }
            else
            {
              v7 = 20.0 / (float)(params.pitch - 50);
            }
            ((void (__thiscall *)(IEngineSound *, KeyValues **, _DWORD, int, _DWORD, int, soundlevel_t *, int, _DWORD, _DWORD, _DWORD, int, const Vector *, Vector *, _DWORD, int, _DWORD, int))enginesound->EmitSound_2)(
              a1: enginesound,
              a2: &params.m_pOperatorsKV,
              a3: 0,
              a4: 6,
              a5: LODWORD(shotDir.z),
              a6: -1,
              a7: &params.soundlevel,
              a8: v11,
              a9: LODWORD(v7),
              a10: *(_DWORD *)&params.m_hSoundScriptHandle,
              a11: 0,
              a12: v12,
              a13: start,
              a14: &vecListenOrigin,
              a15: 0,
              a16: 1,
              a17: 0,
              a18: -1);
            C_RecipientFilter::~C_RecipientFilter(this: (C_RecipientFilter *)&params.m_pOperatorsKV);
          }
          g_BulletWhiz.m_nextWhizTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                                          a1: random,
                                          a2: LODWORD(shotDir.x),
                                          a3: *(_DWORD *)&filter.m_bUsingPredictionRules)
                                      + *(float *)(gpGlobals.m_Index + 12);
        }
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF4B0
// Name: void FX_Tracer(class Vector __near &,class Vector __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FX_Tracer(Vector *start, Vector *end, int velocity, bool makeWhiz)
{
  double v6; // st7
  CFXDiscreetLine *v7; // eax
  CFXDiscreetLine *v8; // eax
  Vector dir; // [esp+44h] [ebp-10h] BYREF
  float scale; // [esp+50h] [ebp-4h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF
  float dist; // [esp+5Ch] [ebp+8h]
  float length; // [esp+60h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "FX_Tracer",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  dir.x = end->x - start->x;
  dir.y = end->y - start->y;
  dir.z = end->z - start->z;
  v6 = VectorNormalize(vec: &dir);
  dist = v6;
  if ( v6 >= 256.0 )
  {
    length = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: 1115684864,
               a3: 1124073472);
    scale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1061158912,
              a3: 1063675494);
    v7 = (CFXDiscreetLine *)MemAlloc_Alloc(nSize: 0x40u);
    if ( v7 != nullptr )
      v8 = CFXDiscreetLine::CFXDiscreetLine(
             this: v7,
             name: "Line",
             start,
             direction: &dir,
             (float)velocity,
             length,
             clipLength: dist,
             scale,
             life: (float)(length + dist) / (float)velocity,
             shader: "effects/spark");
    else
      v8 = nullptr;
    clienteffects->AddEffect(this: clienteffects, a2: v8);
  }
  if ( makeWhiz )
    FX_TracerSound(a1: COERCE_FLOAT(&savedregs), start, end, iTracerType: 1);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10414FE0
// Name: PrecacheEffectsTestPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectsTestPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectsTestPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectsTestPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415000
// Name: _dynamic_initializer_for__g_BulletWhiz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BulletWhiz__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_BulletWhiz, name: "CBulletWhizTimer");
  g_BulletWhiz.__vftable = (CBulletWhizTimer_vtbl *)&CBulletWhizTimer::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_BulletWhiz__);
}

//------------------------------------------------------------------------------
// Address: 0x10415030
// Name: _dynamic_initializer_for__cl_tracer_whiz_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_tracer_whiz_distance__()
{
  ConVar::ConVar(this: &cl_tracer_whiz_distance, pName: "cl_tracer_whiz_distance", pDefaultValue: "72", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_tracer_whiz_distance__);
}

//------------------------------------------------------------------------------
// Address: 0x10415060
// Name: _dynamic_initializer_for__s_DirtyKDTree__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DirtyKDTree__()
{
  CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(
    this: &s_DirtyKDTree,
    name: "CDirtySpatialPartitionEntityList");
  return atexit(func: dynamic_atexit_destructor_for__s_DirtyKDTree__);
}
