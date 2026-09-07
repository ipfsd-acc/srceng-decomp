// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envbeam.cpp
// Functions: 27
// ============================================================

#include "game\server\envbeam.h"

//------------------------------------------------------------------------------
// Address: 0x1011AEC0
// Name: public: virtual struct datamap_t __near * CEnvBeam::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvBeam::GetDataDescMap(CEnvBeam *this)
{
  return &CEnvBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011AED0
// Name: public: void CBaseEntity::EntityToWorldSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::EntityToWorldSpace(CBaseEntity *this, const Vector *in, Vector *pOut)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( vec3_angle.x == this->m_angAbsRotation.x
    && vec3_angle.y == this->m_angAbsRotation.y
    && vec3_angle.z == this->m_angAbsRotation.z )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    pOut->x = this->m_vecAbsOrigin.x + in->x;
    pOut->y = this->m_vecAbsOrigin.y + in->y;
    pOut->z = this->m_vecAbsOrigin.z + in->z;
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    VectorTransform(in1: &in->x, in2: &this->m_rgflCoordinateFrame, out: &pOut->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011AFB0
// Name: public: void CBaseEntity::WorldToEntitySpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::WorldToEntitySpace(CBaseEntity *this, const Vector *in, Vector *pOut)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( vec3_angle.x == this->m_angAbsRotation.x
    && vec3_angle.y == this->m_angAbsRotation.y
    && vec3_angle.z == this->m_angAbsRotation.z )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    pOut->x = in->x - this->m_vecAbsOrigin.x;
    pOut->y = in->y - this->m_vecAbsOrigin.y;
    pOut->z = in->z - this->m_vecAbsOrigin.z;
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    VectorITransform(in1: &in->x, in2: &this->m_rgflCoordinateFrame, out: &pOut->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011B090
// Name: public: virtual void CEnvBeam::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvBeam::Precache(CEnvBeam *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  char fixedname[512]; // [esp+4h] [ebp-204h] BYREF
  char pszValue[4]; // [esp+204h] [ebp-4h] BYREF

  v3 = this->m_iszSpriteName.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  if ( V_stristr(pStr: v3, pSearch: ".vmt") == nullptr )
  {
    v4 = this->m_iszSpriteName.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    V_strncpy(pDest: fixedname, pSrc: v4, maxLen: 512);
    V_SetExtension(path: fixedname, extension: ".vmt", pathStringLength: 512);
    this->m_iszSpriteName.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  }
  g_iszPhysicsPropClassname.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  v5 = this->m_iszSpriteName.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  this->m_spriteTexture = CBaseEntity::PrecacheModel(a1: a2, name: v5, bPreload: true);
  CBeam::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011B160
// Name: public: bool CEnvBeam::PassesTouchFilters(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvBeam::PassesTouchFilters(CEnvBeam *this, CBaseEntity *pOther)
{
  bool v3; // bl
  unsigned int m_Index; // ecx
  CBaseFilter *m_pEntity; // eax

  v3 = false;
  if ( this->m_TouchType != touch_npc_only )
    v3 = pOther->IsPlayer(this: pOther);
  if ( this->m_TouchType != touch_player_only && pOther->IsNPC(this: pOther) )
    v3 = true;
  if ( (this->m_TouchType != touch_player_or_npc_or_physicsprop
     || pOther->m_iClassname.pszValue != g_iszPhysicsPropClassname.pszValue)
    && !v3 )
  {
    return false;
  }
  m_Index = this->m_hFilter.m_Index;
  return m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = (CBaseFilter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
      || CBaseFilter::PassesFilter(this: m_pEntity, pCaller: this, pEntity: pOther);
}

//------------------------------------------------------------------------------
// Address: 0x1011B210
// Name: public: virtual bool CTraceFilterPlayersNPCsPhysicsProps::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterPlayersNPCsPhysicsProps::ShouldHitEntity(
        CTraceFilterPlayersNPCsPhysicsProps *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  const char **v3; // esi
  bool result; // al

  result = false;
  if ( !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity) )
  {
    v3 = (const char **)pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity);
    if ( v3 != nullptr
      && ((*((unsigned __int8 (__thiscall **)(const char **))*v3 + 84))(a1: v3) != 0
       || (*((int (__thiscall **)(const char **))*v3 + 74))(a1: v3) != 0
       || v3[23] == g_iszPhysicsPropClassname.pszValue) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011B280
// Name: public: virtual bool CTraceFilterPlayersNPCs::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterPlayersNPCs::ShouldHitEntity(
        CTraceFilterPlayersNPCs *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  const CBaseHandle *v3; // esi
  bool result; // al

  result = false;
  if ( !staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity) )
  {
    v3 = pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity);
    if ( v3 != nullptr
      && ((*(unsigned __int8 (__thiscall **)(const CBaseHandle *))(v3->m_Index + 336))(a1: v3) != 0
       || (*(int (__thiscall **)(const CBaseHandle *))(v3->m_Index + 296))(a1: v3) != 0) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011B2E0
// Name: public: void CEnvBeam::Zap(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::Zap(CEnvBeam *this, const Vector *vecSrc, const Vector *vecDest)
{
  CBroadcastRecipientFilter filter; // [esp+50h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, const Vector *, const Vector *, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))te->BeamPoints)(
    a1: &filter,
    a2: 0,
    a3: vecSrc,
    a4: vecDest,
    a5: this->m_spriteTexture,
    a6: 0,
    a7: this->m_frameStart,
    a8: (int)this->m_flFrameRate.m_Value,
    a9: LODWORD(this->m_life),
    a10: LODWORD(this->m_boltWidth),
    a11: LODWORD(this->m_boltWidth),
    a12: 0,
    a13: LODWORD(this->m_noiseAmplitude),
    a14: this->m_clrRender.m_Value.r,
    a15: this->m_clrRender.m_Value.g,
    a16: this->m_clrRender.m_Value.b,
    a17: this->m_clrRender.m_Value.a,
    a18: this->m_speed);
  CBeam::DoSparks(this, start: vecSrc, end: vecDest);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1011B3D0
// Name: public: void CEnvBeam::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::TurnOff(CEnvBeam *this)
{
  float m_life; // xmm0_4

  m_life = this->m_life;
  this->m_active = 0;
  if ( m_life == 0.0 && (this->m_spawnflags.m_Value & 8) == 0 )
    CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011B440
// Name: public: void CEnvBeam::Strike(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::Strike(CEnvBeam *this)
{
  const char *pszValue; // eax
  const char *v3; // eax
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // edi
  bool v6; // bl
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  int m_speed; // eax
  bool v11; // bl
  signed int v12; // eax
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  signed int m_pPev; // eax
  CBaseEntity *v16; // edi
  edict_t *v17; // eax
  CBaseEntity *v18; // ebx
  const Vector *v19; // edi
  const Vector *v20; // ebx
  CBaseEntity *v21; // [esp+48h] [ebp-A4h]
  CGameTrace tr; // [esp+58h] [ebp-94h] BYREF
  CBroadcastRecipientFilter filter; // [esp+ACh] [ebp-40h] BYREF
  Vector vEndPointLocation; // [esp+CCh] [ebp-20h] BYREF
  Vector *p_m_vecAbsOrigin; // [esp+D8h] [ebp-14h]
  CBaseEntity *pEnd; // [esp+DCh] [ebp-10h]
  signed int v27; // [esp+E0h] [ebp-Ch]
  bool pointStart; // [esp+E7h] [ebp-5h]
  CBaseEntity *pStart; // [esp+E8h] [ebp-4h]
  IHandleEntity savedregs; // [esp+ECh] [ebp+0h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  pszValue = this->m_iszStartEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  pStart = CBeam::RandomTargetname(this, szName: pszValue);
  v3 = this->m_iszEndEntity.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  v4 = CBeam::RandomTargetname(this, szName: v3);
  v5 = v4;
  v6 = v4 != nullptr;
  pEnd = v4;
  if ( pStart != nullptr )
  {
    if ( v4 != nullptr )
    {
      if ( (v4->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
      vEndPointLocation = v5->m_vecAbsOrigin;
    }
    else
    {
      x = this->m_vEndPointRelative.x;
      if ( x > -0.0099999998 && x < 0.0099999998 )
      {
        y = this->m_vEndPointRelative.y;
        if ( y > -0.0099999998 && y < 0.0099999998 )
        {
          z = this->m_vEndPointRelative.z;
          if ( z > -0.0099999998 && z < 0.0099999998 )
            goto LABEL_63;
        }
      }
      CBaseEntity::EntityToWorldSpace(this, in: &this->m_vEndPointRelative, pOut: &vEndPointLocation);
    }
    m_speed = this->m_speed;
    if ( m_speed >= 0 )
    {
      if ( (float)m_speed > 100.0 )
        m_speed = 100;
    }
    else
    {
      m_speed = 0;
    }
    v21 = pStart;
    this->m_speed = m_speed;
    pointStart = IsStaticPointEntity(pEnt: v21);
    v11 = !v6 || IsStaticPointEntity(pEnt: v5);
    if ( pointStart || v11 )
    {
      if ( (this->m_spawnflags.m_Value & 8) != 0 )
        goto LABEL_63;
      if ( v11 )
      {
        v27 = 0;
      }
      else
      {
        m_pPev = (signed int)v5->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        v27 = m_pPev;
      }
      if ( pointStart )
      {
        v16 = pStart;
        if ( (pStart->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pStart, a2: (int)&savedregs);
        p_m_vecAbsOrigin = &v16->m_vecAbsOrigin;
        v17 = nullptr;
      }
      else
      {
        v17 = pStart->m_Network.m_pPev;
        p_m_vecAbsOrigin = nullptr;
        if ( v17 != nullptr )
          v17 -= (int)gpGlobals->pEdicts;
      }
      ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, edict_t *, Vector *, signed int, Vector *, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))te->BeamEntPoint)(
        a1: &filter,
        a2: 0,
        a3: v17,
        a4: p_m_vecAbsOrigin,
        a5: v27,
        a6: v11 ? &vEndPointLocation : nullptr,
        a7: this->m_spriteTexture,
        a8: 0,
        a9: this->m_frameStart,
        a10: (int)this->m_flFrameRate.m_Value,
        a11: LODWORD(this->m_life),
        a12: LODWORD(this->m_boltWidth),
        a13: LODWORD(this->m_boltWidth),
        a14: 0,
        a15: LODWORD(this->m_noiseAmplitude),
        a16: this->m_clrRender.m_Value.r,
        a17: this->m_clrRender.m_Value.g,
        a18: this->m_clrRender.m_Value.b,
        a19: this->m_clrRender.m_Value.a,
        a20: this->m_speed);
    }
    else
    {
      v12 = (signed int)v5->m_Network.m_pPev;
      if ( (this->m_spawnflags.m_Value & 8) != 0 )
      {
        if ( v12 != 0 )
          v27 = (signed int)(v12 - (unsigned int)gpGlobals->pEdicts) >> 4;
        else
          v27 = 0;
        v13 = pStart->m_Network.m_pPev;
        if ( v13 != nullptr )
          v13 -= (int)gpGlobals->pEdicts;
        ((void (__thiscall *)(ITempEntsSystem *, CBroadcastRecipientFilter *, _DWORD, edict_t *, signed int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD))te->BeamRing)(
          a1: te,
          a2: &filter,
          a3: 0,
          a4: v13,
          a5: v27,
          a6: this->m_spriteTexture,
          a7: 0,
          a8: this->m_frameStart,
          a9: (int)this->m_flFrameRate.m_Value,
          a10: LODWORD(this->m_life),
          a11: LODWORD(this->m_boltWidth),
          a12: 0,
          a13: LODWORD(this->m_noiseAmplitude),
          a14: this->m_clrRender.m_Value.r,
          a15: this->m_clrRender.m_Value.g,
          a16: this->m_clrRender.m_Value.b,
          a17: this->m_clrRender.m_Value.a,
          a18: this->m_speed,
          a19: 0);
        goto LABEL_53;
      }
      if ( v12 != 0 )
        v12 = (signed int)(v12 - (unsigned int)gpGlobals->pEdicts) >> 4;
      v14 = pStart->m_Network.m_pPev;
      if ( v14 != nullptr )
        v14 -= (int)gpGlobals->pEdicts;
      ((void (__thiscall *)(ITempEntsSystem *, CBroadcastRecipientFilter *, _DWORD, edict_t *, signed int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))te->BeamEnts)(
        a1: te,
        a2: &filter,
        a3: 0,
        a4: v14,
        a5: v12,
        a6: this->m_spriteTexture,
        a7: 0,
        a8: this->m_frameStart,
        a9: (int)this->m_flFrameRate.m_Value,
        a10: LODWORD(this->m_life),
        a11: LODWORD(this->m_boltWidth),
        a12: LODWORD(this->m_boltWidth),
        a13: 0,
        a14: LODWORD(this->m_noiseAmplitude),
        a15: this->m_clrRender.m_Value.r,
        a16: this->m_clrRender.m_Value.g,
        a17: this->m_clrRender.m_Value.b,
        a18: this->m_clrRender.m_Value.a,
        a19: this->m_speed);
    }
    v5 = pEnd;
LABEL_53:
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
    v18 = pStart;
    if ( (pStart->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pStart, a2: (int)&savedregs);
    v19 = &v5->m_vecAbsOrigin;
    v20 = &v18->m_vecAbsOrigin;
    CBeam::DoSparks(this, start: v20, end: v19);
    if ( this->m_flDamage > 0.0 )
    {
      if ( (pEnd->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pEnd, a2: (int)&savedregs);
      if ( (pStart->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pStart, a2: (int)&savedregs);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: v20,
        vecAbsEnd: v19,
        mask: 0x200400Bu,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &tr);
      this->m_flFireTime = gpGlobals->curtime - 1.0;
      CBeam::BeamDamage(this, ptr: &tr);
    }
  }
LABEL_63:
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1011B910
// Name: public: void CEnvBeam::UpdateThink(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CEnvBeam::UpdateThink(CEnvBeam *this@<ecx>, IHandleEntity_vtbl *a2@<ebp>)
{
  const Vector *AbsStartPos; // eax
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *v4; // edi
  const Vector *v5; // ecx
  bool v6; // zf
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *AbsEndPos; // [esp+0h] [ebp-E0h]
  _BYTE v8[12]; // [esp+1Ch] [ebp-C4h] BYREF
  _BYTE tr_32[56]; // [esp+48h] [ebp-98h] OVERLAPPED BYREF
  Ray_t ray; // [esp+80h] [ebp-60h] BYREF
  void **v11; // [esp+D0h] [ebp-10h] BYREF
  IHandleEntity v12[2]; // [esp+D4h] [ebp-Ch] BYREF
  IHandleEntity_vtbl *retaddr; // [esp+E0h] [ebp+0h]

  v12[0].__vftable = a2;
  v12[1].__vftable = retaddr;
  if ( this->m_flDamage <= 0.0 || gpGlobals->curtime < this->m_flFireTime + 0.1 )
  {
    CBeam::RelinkBeam(this);
  }
  else
  {
    AbsEndPos = CBeam::GetAbsEndPos(this, a2: (int)v12);
    AbsStartPos = CBeam::GetAbsStartPos(this, a2: (int)v12);
    UTIL_TraceLine(
      a1: v12,
      a2: (int)this,
      vecAbsStart: AbsStartPos,
      vecAbsEnd: &AbsEndPos->m_Value,
      mask: 0x200400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: (CGameTrace *)v8);
    CBeam::BeamDamage(this, ptr: (CGameTrace *)v8);
  }
  if ( this->m_TouchType == touch_none )
    goto LABEL_12;
  ray.m_Extents.y = 0.0;
  v4 = CBeam::GetAbsEndPos(this, a2: (int)v12);
  v5 = CBeam::GetAbsStartPos(this, a2: (int)v12);
  ray.m_Start.y = v4->m_Value.x - v5->x;
  ray.m_Start.z = v4->m_Value.y - v5->y;
  ray.m_Start.w = v4->m_Value.z - v5->z;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  v6 = this->m_TouchType == touch_player_or_npc_or_physicsprop;
  memset(&ray.m_StartOffset.y, 0, 12);
  ray.m_Extents.y = 0.0;
  LOBYTE(ray.m_Extents.z) = 1;
  memset(&ray.m_Delta.y, 0, 12);
  *(Vector *)&tr_32[44] = *v5;
  v11 = v6 ? &CTraceFilterPlayersNPCsPhysicsProps::`vftable' : &CTraceFilterPlayersNPCs::`vftable';
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&tr_32[44],
    a3: 1174421507u,
    a4: (ITraceFilter *)&v11,
    a5: (CGameTrace *)v8);
  if ( *(float *)tr_32 != 1.0 && CEnvBeam::PassesTouchFilters(this, pOther: *(CBaseEntity **)&tr_32[32]) )
    COutputEvent::FireOutput(
      this: &this->m_OnTouchedByEntity,
      pActivator: *(CBaseEntity **)&tr_32[32],
      pCaller: this,
      fDelay: 0.0);
  else
LABEL_12:
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1011BB30
// Name: public: void CEnvBeam::RandomArea(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CEnvBeam::RandomArea(CEnvBeam *this@<ecx>, float a2@<ebp>)
{
  int v3; // edi
  __int64 v4; // xmm0_8
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v6; // st7
  float m_radius; // xmm3_4
  __int128 v8; // xmm0
  float v9; // xmm1_4
  int v10; // [esp+40h] [ebp-11Ch] BYREF
  CGameTrace tr1; // [esp+4Ch] [ebp-110h] BYREF
  _BYTE tr2[92]; // [esp+A4h] [ebp-B8h] OVERLAPPED BYREF
  Vector v13; // [esp+108h] [ebp-54h] BYREF
  Vector v14; // [esp+114h] [ebp-48h] BYREF
  float v15; // [esp+120h] [ebp-3Ch]
  Vector v16; // [esp+124h] [ebp-38h] BYREF
  Vector vecDir2; // [esp+130h] [ebp-2Ch] BYREF
  Vector vecDir1; // [esp+13Ch] [ebp-20h] BYREF
  Vector vecSrc; // [esp+148h] [ebp-14h] BYREF
  void *v20; // [esp+154h] [ebp-8h]
  void *retaddr; // [esp+15Ch] [ebp+0h]

  vecSrc.z = a2;
  v20 = retaddr;
  v3 = 0;
  while ( 1 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vecSrc.z);
    v4 = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vecDir1.z = this->m_vecAbsOrigin.z;
    RandomFloat = random->RandomFloat;
    *(_QWORD *)&vecDir1.x = v4;
    v15 = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
            a1: random,
            a2: -1082130432,
            a3: 1065353216);
    vecSrc.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: -1082130432,
                 a3: 1065353216);
    vecSrc.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: -1082130432,
                 a3: 1065353216);
    vecDir2.x = v15;
    vecDir2.y = vecSrc.y;
    vecDir2.z = vecSrc.x;
    VectorNormalize(vec: &vecDir2);
    *(float *)&v4 = this->m_radius;
    v13.x = vecDir1.x + (float)(*(float *)&v4 * vecDir2.x);
    v13.y = vecDir1.y + (float)(vecDir2.y * *(float *)&v4);
    v13.z = vecDir1.z + (float)(vecDir2.z * *(float *)&v4);
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&vecSrc.z,
      a2: (int)this,
      vecAbsStart: &vecDir1,
      vecAbsEnd: &v13,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: (CGameTrace *)&v10);
    if ( tr1.plane.normal.z != 1.0 )
    {
      do
      {
        vecSrc.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: -1082130432,
                     a3: 1065353216);
        vecSrc.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: -1082130432,
                     a3: 1065353216);
        v6 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: -1082130432,
               a3: 1065353216);
        v16.x = vecSrc.x;
        v16.y = vecSrc.y;
        v16.z = v6;
      }
      while ( vecSrc.y * vecDir2.y + vecSrc.x * vecDir2.x + v6 * vecDir2.z > 0.0 );
      VectorNormalize(vec: &v16);
      m_radius = this->m_radius;
      v14.x = (float)(v16.x * m_radius) + vecDir1.x;
      v14.y = (float)(v16.y * m_radius) + vecDir1.y;
      v14.z = (float)(v16.z * m_radius) + vecDir1.z;
      UTIL_TraceLine(
        a1: (const IHandleEntity *)&vecSrc.z,
        a2: (int)this,
        vecAbsStart: &vecDir1,
        vecAbsEnd: &v14,
        mask: 0x400Bu,
        ignore: this,
        collisionGroup: 0,
        ptr: (CGameTrace *)&tr1.m_pEnt);
      if ( *(float *)&tr2[32] != 1.0 )
      {
        v8 = 0;
        v9 = this->m_radius;
        *(float *)&v8 = fsqrt(
                          (float)((float)((float)(tr1.startpos.y - *(float *)&tr2[4])
                                        * (float)(tr1.startpos.y - *(float *)&tr2[4]))
                                + (float)((float)(tr1.startpos.z - *(float *)&tr2[8])
                                        * (float)(tr1.startpos.z - *(float *)&tr2[8])))
                        + (float)((float)(tr1.startpos.x - *(float *)tr2) * (float)(tr1.startpos.x - *(float *)tr2)));
        *(_OWORD *)&tr2[76] = v8;
        if ( v9 * 0.1 <= *(float *)&v8 )
        {
          UTIL_TraceLine(
            a1: (const IHandleEntity *)&vecSrc.z,
            a2: (int)this,
            vecAbsStart: &tr1.startpos,
            vecAbsEnd: (const Vector *)tr2,
            mask: 0x400Bu,
            ignore: this,
            collisionGroup: 0,
            ptr: (CGameTrace *)&tr1.m_pEnt);
          if ( *(float *)&tr2[32] == 1.0 )
            break;
        }
      }
    }
    if ( ++v3 >= 10 )
      return;
  }
  CEnvBeam::Zap(this, vecSrc: &tr1.startpos, vecDest: (const Vector *)tr2);
}

//------------------------------------------------------------------------------
// Address: 0x1011BED0
// Name: public: void CEnvBeam::RandomPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CEnvBeam::RandomPoint(CEnvBeam *this@<ecx>, float a2@<ebp>, const Vector *vecSrc)
{
  float m_radius; // xmm0_4
  __int128 v5; // xmm0
  int v6; // [esp+20h] [ebp-A4h] BYREF
  _BYTE tr1[92]; // [esp+2Ch] [ebp-98h] OVERLAPPED BYREF
  Vector v8; // [esp+90h] [ebp-34h] BYREF
  float v9; // [esp+9Ch] [ebp-28h]
  float v10; // [esp+A0h] [ebp-24h]
  float v11; // [esp+A4h] [ebp-20h]
  Vector v12; // [esp+A8h] [ebp-1Ch] BYREF
  Vector vecDir1; // [esp+B4h] [ebp-10h] BYREF
  float retaddr; // [esp+C4h] [ebp+0h]

  vecDir1.y = a2;
  vecDir1.z = retaddr;
  vecDir1.x = 0.0;
  while ( 1 )
  {
    v10 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1082130432,
            a3: 1065353216);
    v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1082130432,
           a3: 1065353216);
    v11 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1082130432,
            a3: 1065353216);
    v12.x = v10;
    v12.y = v9;
    v12.z = v11;
    VectorNormalize(vec: &v12);
    m_radius = this->m_radius;
    v8.x = vecSrc->x + (float)(m_radius * v12.x);
    v8.y = vecSrc->y + (float)(v12.y * m_radius);
    v8.z = vecSrc->z + (float)(v12.z * m_radius);
    UTIL_TraceLine(
      a1: (const IHandleEntity *)&vecDir1.y,
      a2: (int)vecSrc,
      vecAbsStart: vecSrc,
      vecAbsEnd: &v8,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: (CGameTrace *)&v6);
    v5 = 0;
    *(float *)&v5 = fsqrt(
                      (float)((float)((float)(*(float *)&tr1[4] - vecSrc->y) * (float)(*(float *)&tr1[4] - vecSrc->y))
                            + (float)((float)(*(float *)&tr1[8] - vecSrc->z) * (float)(*(float *)&tr1[8] - vecSrc->z)))
                    + (float)((float)(*(float *)tr1 - vecSrc->x) * (float)(*(float *)tr1 - vecSrc->x)));
    *(_OWORD *)&tr1[76] = v5;
    if ( this->m_radius * 0.1 <= *(float *)&v5 && *(float *)&tr1[32] != 1.0 )
      break;
    ++LODWORD(vecDir1.x);
    if ( SLODWORD(vecDir1.x) >= 10 )
      return;
  }
  CEnvBeam::Zap(this, vecSrc, vecDest: (const Vector *)tr1);
}

//------------------------------------------------------------------------------
// Address: 0x1011C0D0
// Name: public: void CEnvBeam::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::InputTurnOff(CEnvBeam *this, inputdata_t *inputdata)
{
  if ( this->m_active != 0 )
    CEnvBeam::TurnOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011C0F0
// Name: public: void CEnvBeam::InputStrikeOnce(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEnvBeam::InputStrikeOnce(CEnvBeam *this, inputdata_t *inputdata)
{
  CEnvBeam::Strike(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011C100
// Name: public: void CEnvBeam::StrikeThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvBeam::StrikeThink(CEnvBeam *this@<ecx>, int a2@<ebp>)
{
  float m_life; // xmm0_4
  bool v4; // zf
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  const char *pszValue; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *v10; // edi
  const char *v11; // esi
  float thinkTime; // [esp+8h] [ebp-Ch]

  m_life = this->m_life;
  if ( m_life != 0.0 )
  {
    if ( (this->m_spawnflags.m_Value & 4) != 0 )
    {
      thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                    a1: random,
                    a2: 0,
                    a3: LODWORD(this->m_restrike))
                + gpGlobals->curtime
                + this->m_life;
      CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
    }
    else
    {
      CBaseEntity::SetNextThink(
        this,
        thinkTime: (float)(gpGlobals->curtime + m_life) + this->m_restrike,
        szContext: nullptr);
    }
  }
  v4 = this->m_iszEndEntity.pszValue == nullptr;
  this->m_active = 1;
  if ( v4
    && (x = this->m_vEndPointRelative.x) > -0.0099999998
    && x < 0.0099999998
    && (y = this->m_vEndPointRelative.y) > -0.0099999998
    && y < 0.0099999998
    && (z = this->m_vEndPointRelative.z) > -0.0099999998
    && z < 0.0099999998 )
  {
    if ( this->m_iszStartEntity.pszValue != nullptr )
    {
      pszValue = this->m_iszStartEntity.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v9 = CBeam::RandomTargetname(this, szName: pszValue);
      v10 = v9;
      if ( v9 != nullptr )
      {
        if ( (v9->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v9, a2);
        CEnvBeam::RandomPoint(this, a2: *(float *)&a2, vecSrc: &v10->m_vecAbsOrigin);
      }
      else
      {
        v11 = this->m_iszStartEntity.pszValue;
        if ( v11 == nullptr )
          v11 = locale;
        _Msg(a1: "env_beam: unknown entity \"%s\"\n", v11);
      }
    }
    else
    {
      CEnvBeam::RandomArea(this, a2: *(float *)&a2);
    }
  }
  else
  {
    CEnvBeam::Strike(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C270
// Name: public: virtual char const __near * CEnvBeam::GetDecalName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEnvBeam::GetDecalName(CEnvBeam *this)
{
  const char *result; // eax

  result = this->m_iszDecal.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C280
// Name: public: virtual void CEnvBeam::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::Spawn(CEnvBeam *this)
{
  float m_noiseAmplitude; // xmm0_4
  unsigned int v3; // eax
  float m_Value; // xmm0_4
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  bool v8; // zf
  float width; // [esp+4h] [ebp-8h]

  if ( this->m_iszSpriteName.pszValue != nullptr )
  {
    CBeam::Spawn(this);
    m_noiseAmplitude = this->m_noiseAmplitude;
    if ( m_noiseAmplitude > 64.0 )
      m_noiseAmplitude = 64.0;
    v3 = (unsigned int)this->m_spawnflags.m_Value >> 9;
    this->m_noiseAmplitude = m_noiseAmplitude;
    width = this->m_boltWidth;
    if ( (v3 & 1) != 0 )
    {
      CBeam::SetWidth(this, width);
      m_Value = 0.0;
    }
    else
    {
      CBeam::SetWidth(this, width);
      m_Value = this->m_fWidth.m_Value;
    }
    CBeam::SetEndWidth(this, endWidth: m_Value);
    x = this->m_vEndPointWorld.x;
    if ( x > -0.0099999998
      && x < 0.0099999998
      && (y = this->m_vEndPointWorld.y) > -0.0099999998
      && y < 0.0099999998
      && (z = this->m_vEndPointWorld.z) > -0.0099999998
      && z < 0.0099999998 )
    {
      *(_QWORD *)&this->m_vEndPointRelative.y = 0;
      this->m_vEndPointRelative.x = 0.0;
    }
    else
    {
      CBaseEntity::WorldToEntitySpace(this, in: &this->m_vEndPointWorld, pOut: &this->m_vEndPointRelative);
    }
    if ( this->m_life != 0.0 || (this->m_spawnflags.m_Value & 8) != 0 )
    {
      v8 = this->m_iName.m_Value.pszValue == nullptr;
      this->m_active = 0;
      if ( v8 || (this->m_spawnflags.m_Value & 1) != 0 )
      {
        CBaseEntity::ThinkSet(
          this,
          func: (void (__thiscall *)(CBaseEntity *))CEnvBeam::StrikeThink,
          thinkTime: 0.0,
          szContext: nullptr);
        CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
      }
    }
    else
    {
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CEnvBeam::UpdateThink,
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      v8 = this->m_iName.m_Value.pszValue == nullptr;
      this->m_flFireTime = gpGlobals->curtime;
      if ( !v8 )
      {
        if ( (this->m_spawnflags.m_Value & 1) != 0 )
        {
          this->m_active = 1;
        }
        else
        {
          CBaseEntity::AddEffects(this, nEffects: 32);
          this->m_active = 0;
          CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
        }
      }
    }
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C490
// Name: public: void CEnvBeam::BeamUpdateVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::BeamUpdateVars(CEnvBeam *this)
{
  const char *pszValue; // eax
  CEnvBeam *EntityByName; // ebx
  const char *v4; // eax
  CBasePlayer *v5; // edi
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  edict_t *m_pPev; // ecx
  int m_speed; // eax
  CEnvBeam *v11; // edi
  float m_boltWidth; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v14; // ecx
  float m_noiseAmplitude; // xmm0_4
  float v16; // xmm1_4
  edict_t *v17; // ecx
  float v18; // xmm1_4
  float m_frameStart; // xmm0_4
  edict_t *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm0_4
  edict_t *v23; // ecx
  int v24; // eax
  Vector vEndPointPos; // [esp+Ch] [ebp-14h] BYREF
  CBaseEntity *pEnd; // [esp+18h] [ebp-8h]
  bool bEndPointFromEntity; // [esp+1Fh] [ebp-1h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  pszValue = this->m_iszStartEntity.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = (CEnvBeam *)CGlobalEntityList::FindEntityByName(
                               this: &gEntList,
                               pStartEntity: nullptr,
                               szName: pszValue,
                               pSearchingEntity: nullptr,
                               pActivator: nullptr,
                               pCaller: nullptr,
                               pFilter: nullptr);
  v4 = this->m_iszEndEntity.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  v5 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v4,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  pEnd = v5;
  bEndPointFromEntity = v5 != nullptr;
  if ( EntityByName != nullptr )
  {
    if ( v5 != nullptr )
    {
      if ( (v5->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
      vEndPointPos = v5->m_vecAbsOrigin;
    }
    else
    {
      x = this->m_vEndPointRelative.x;
      if ( x > -0.0099999998 && x < 0.0099999998 )
      {
        y = this->m_vEndPointRelative.y;
        if ( y > -0.0099999998 && y < 0.0099999998 )
        {
          z = this->m_vEndPointRelative.z;
          if ( z > -0.0099999998 && z < 0.0099999998 )
            return;
        }
      }
      CBaseEntity::EntityToWorldSpace(this, in: &this->m_vEndPointRelative, pOut: &vEndPointPos);
    }
    if ( this->m_nNumBeamEnts.m_Value != 2 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      }
      this->m_nNumBeamEnts.m_Value = 2;
    }
    m_speed = this->m_speed;
    if ( m_speed >= 0 )
    {
      if ( (float)m_speed > 100.0 )
        m_speed = 100;
    }
    else
    {
      m_speed = 0;
    }
    v11 = (CEnvBeam *)pEnd;
    this->m_speed = m_speed;
    if ( v11 == this && EntityByName != this )
      DevMsg(a1: "env_beams cannot have the end entity be the beam itself\nunless the start entity is also the beam itself!\n");
    this->m_ModelName.pszValue = this->m_iszSpriteName.pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this);
    this->SetModelIndex(this, a2: this->m_spriteTexture);
    CBeam::SetType(this, type: 1);
    if ( IsStaticPointEntity(pEnt: EntityByName) )
    {
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      CBeam::SetAbsStartPos(this, pos: &EntityByName->m_vecAbsOrigin);
    }
    else
    {
      CBeam::SetStartEntity(this, pEntity: EntityByName);
    }
    if ( !bEndPointFromEntity || IsStaticPointEntity(pEnt: v11) )
      CBeam::SetAbsEndPos(this, pos: &vEndPointPos);
    else
      CBeam::SetEndEntity(this, pEntity: v11);
    CBeam::RelinkBeam(this);
    m_boltWidth = this->m_boltWidth;
    if ( m_boltWidth > 102.3 )
      m_boltWidth = 102.3;
    m_Value = this->m_fWidth.m_Value;
    *(float *)&pEnd = m_boltWidth;
    if ( m_Value != m_boltWidth )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v14 = this->m_Network.m_pPev;
        if ( v14 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x3C4u);
          m_boltWidth = *(float *)&pEnd;
        }
      }
      this->m_fWidth.m_Value = m_boltWidth;
    }
    m_noiseAmplitude = this->m_noiseAmplitude;
    if ( m_noiseAmplitude > 64.0 )
      m_noiseAmplitude = 64.0;
    v16 = this->m_fAmplitude.m_Value;
    *(float *)&pEnd = m_noiseAmplitude;
    if ( v16 != m_noiseAmplitude )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v17 = this->m_Network.m_pPev;
        if ( v17 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x3D4u);
          m_noiseAmplitude = *(float *)&pEnd;
        }
      }
      this->m_fAmplitude.m_Value = m_noiseAmplitude;
    }
    v18 = this->m_fStartFrame.m_Value;
    m_frameStart = (float)this->m_frameStart;
    *(float *)&pEnd = m_frameStart;
    if ( v18 != m_frameStart )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v20 = this->m_Network.m_pPev;
        if ( v20 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x3D8u);
          m_frameStart = *(float *)&pEnd;
        }
      }
      this->m_fStartFrame.m_Value = m_frameStart;
    }
    v21 = this->m_fSpeed.m_Value;
    v22 = (float)this->m_speed;
    *(float *)&pEnd = v22;
    if ( v21 != v22 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v23 = this->m_Network.m_pPev;
        if ( v23 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v23->CBaseEdict, offset: 0x3DCu);
          v22 = *(float *)&pEnd;
        }
      }
      this->m_fSpeed.m_Value = v22;
    }
    v24 = this->m_spawnflags.m_Value;
    if ( (v24 & 0x80u) == 0 )
    {
      if ( (v24 & 0x100) != 0 )
        CBeam::SetBeamFlags(this, flags: 128);
    }
    else
    {
      CBeam::SetBeamFlags(this, flags: 64);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C8A0
// Name: public: virtual void CEnvBeam::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeam::Activate(CEnvBeam *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  void *v4; // eax

  pszValue = this->m_iFilterName.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    v4 = __RTDynamicCast(
           inptr: EntityByName,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBaseFilter `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
      this->m_hFilter.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
    else
      this->m_hFilter.m_Index = -1;
  }
  CBaseEntity::Activate(this);
  if ( this->m_life == 0.0 && (this->m_spawnflags.m_Value & 8) == 0 )
    CEnvBeam::BeamUpdateVars(this);
}

//------------------------------------------------------------------------------
// Address: 0x1011C930
// Name: public: void CEnvBeam::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvBeam::TurnOn(CEnvBeam *this@<ecx>, int a2@<ebp>)
{
  float m_life; // xmm1_4
  int m_Value; // eax
  unsigned int v5; // edi
  edict_t *m_pPev; // ecx
  const Vector *AbsStartPos; // eax
  CNetworkVectorBase<Vector,CBeam::NetworkVar_m_vecEndPos> *AbsEndPos; // [esp+4h] [ebp-8h]

  m_life = this->m_life;
  this->m_active = 1;
  if ( m_life != 0.0 || (this->m_spawnflags.m_Value & 8) != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvBeam::StrikeThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    m_Value = this->m_fEffects.m_Value;
    v5 = m_Value & 0xFFFFFFDF;
    if ( m_Value != (m_Value & 0xFFFFFFDF) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v5;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    AbsEndPos = CBeam::GetAbsEndPos(this, a2);
    AbsStartPos = CBeam::GetAbsStartPos(this, a2);
    CBeam::DoSparks(this, start: AbsStartPos, end: &AbsEndPos->m_Value);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvBeam::UpdateThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_flFireTime = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CA60
// Name: public: void CEnvBeam::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEnvBeam::InputTurnOn(CEnvBeam *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  if ( this->m_active == 0 )
    CEnvBeam::TurnOn(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1011CA80
// Name: public: void CEnvBeam::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEnvBeam::InputToggle(CEnvBeam *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  if ( this->m_active != 0 )
    CEnvBeam::TurnOff(this);
  else
    CEnvBeam::TurnOn(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10402C40
// Name: CEnvBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvBeam>(__formal: nullptr);
  CEnvBeam_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011C830
// Name: class CEnvBeam __near * _CreateEntityTemplate<class CEnvBeam>(class CEnvBeam __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvBeam *__cdecl _CreateEntityTemplate<CEnvBeam>(CEnvBeam *newEnt, const char *className)
{
  CBeam *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBeam *)CBaseEntity::operator new(stAllocateBlock: 0x46Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBeam::CBeam(this: v2);
    *v3 = &CEnvBeam::`vftable';
    v3[275] = -1;
    v3[277] = 0;
    v3[280] = -1;
    v3[281] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvBeam *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011CAA0
// Name: struct datamap_t __near * DataMapInit<class CEnvBeam>(class CEnvBeam __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvBeam>()
{
  if ( (_S2_93 & 1) == 0 )
  {
    _S2_93 |= 1u;
    nameHolder_173.m_pszBase = "CEnvBeam";
    nameHolder_173.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_173.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_173.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_173.m_Names.m_Size = 0;
    nameHolder_173.m_Names.m_pElements = nullptr;
    nameHolder_173.m_nLenBase = 8;
    atexit(func: DataMapInit_CEnvBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvBeam::m_DataMap.baseMap = &CBeam::m_DataMap;
  if ( (_S2_93 & 2) == 0 )
  {
    _S2_93 |= 2u;
    dataDesc_163[19].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_173,
                                   pszIdentifier: "StrikeThink");
    dataDesc_163[19].flags = 32;
    dataDesc_163[19].fieldOffset = 0;
    dataDesc_163[19].fieldSize = 1;
    dataDesc_163[19].externalName = nullptr;
    dataDesc_163[19].pSaveRestoreOps = nullptr;
    dataDesc_163[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::StrikeThink;
    *(_QWORD *)&dataDesc_163[19].td = 0;
    *(_QWORD *)&dataDesc_163[19].override_field = 0;
    *(_QWORD *)&dataDesc_163[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[19].flatOffset[1] = 0;
    dataDesc_163[20].fieldType = FIELD_VOID;
    dataDesc_163[20].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_173,
                                   pszIdentifier: "UpdateThink");
    dataDesc_163[20].fieldSize = 1;
    *(_QWORD *)&dataDesc_163[20].td = 0;
    *(_QWORD *)&dataDesc_163[20].override_field = 0;
    *(_QWORD *)&dataDesc_163[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[20].flatOffset[1] = 0;
    dataDesc_163[20].flags = 32;
    dataDesc_163[21].fieldSize = 1;
    *(_QWORD *)&dataDesc_163[21].td = 0;
    *(_QWORD *)&dataDesc_163[21].override_field = 0;
    *(_QWORD *)&dataDesc_163[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[21].flatOffset[1] = 0;
    dataDesc_163[21].flags = 8;
    dataDesc_163[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_163[22].td = 0;
    *(_QWORD *)&dataDesc_163[22].override_field = 0;
    *(_QWORD *)&dataDesc_163[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[22].flatOffset[1] = 0;
    dataDesc_163[20].fieldOffset = 0;
    dataDesc_163[20].externalName = nullptr;
    dataDesc_163[20].pSaveRestoreOps = nullptr;
    dataDesc_163[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::UpdateThink;
    dataDesc_163[21].fieldType = FIELD_VOID;
    dataDesc_163[21].fieldName = "InputTurnOn";
    dataDesc_163[21].fieldOffset = 0;
    dataDesc_163[21].externalName = "TurnOn";
    dataDesc_163[21].pSaveRestoreOps = nullptr;
    dataDesc_163[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::InputTurnOn;
    dataDesc_163[22].fieldType = FIELD_VOID;
    dataDesc_163[22].fieldName = "InputTurnOff";
    dataDesc_163[22].fieldOffset = 0;
    dataDesc_163[22].flags = 8;
    dataDesc_163[22].externalName = "TurnOff";
    dataDesc_163[22].pSaveRestoreOps = nullptr;
    dataDesc_163[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::InputTurnOff;
    dataDesc_163[23].fieldType = FIELD_VOID;
    dataDesc_163[23].fieldName = "InputToggle";
    dataDesc_163[23].fieldOffset = 0;
    dataDesc_163[23].fieldSize = 1;
    dataDesc_163[23].flags = 8;
    dataDesc_163[23].externalName = "Toggle";
    dataDesc_163[23].pSaveRestoreOps = nullptr;
    dataDesc_163[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::InputToggle;
    *(_QWORD *)&dataDesc_163[23].td = 0;
    *(_QWORD *)&dataDesc_163[23].override_field = 0;
    *(_QWORD *)&dataDesc_163[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[23].flatOffset[1] = 0;
    dataDesc_163[24].fieldSize = 1;
    *(_QWORD *)&dataDesc_163[24].td = 0;
    *(_QWORD *)&dataDesc_163[24].override_field = 0;
    *(_QWORD *)&dataDesc_163[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_163[24].flatOffset[1] = 0;
    dataDesc_163[24].fieldType = FIELD_VOID;
    dataDesc_163[24].fieldName = "InputStrikeOnce";
    dataDesc_163[24].fieldOffset = 0;
    dataDesc_163[24].flags = 8;
    dataDesc_163[24].externalName = "StrikeOnce";
    dataDesc_163[24].pSaveRestoreOps = nullptr;
    dataDesc_163[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvBeam::InputStrikeOnce;
    dataDesc_163[25].fieldType = FIELD_CUSTOM;
    dataDesc_163[25].fieldName = "m_OnTouchedByEntity";
    dataDesc_163[25].fieldOffset = 1108;
    *(_DWORD *)&dataDesc_163[25].fieldSize = 1441793;
    dataDesc_163[25].externalName = "OnTouchedByEntity";
    dataDesc_163[25].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_163[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_163[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_163[25].override_count = 0;
    *(_QWORD *)dataDesc_163[25].flatOffset = 0;
    *(_DWORD *)&dataDesc_163[25].flatGroup = 0;
  }
  CEnvBeam::m_DataMap.dataNumFields = 25;
  CEnvBeam::m_DataMap.dataDesc = &dataDesc_163[1];
  return &CEnvBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402C50
// Name: _dynamic_initializer_for__env_fade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_fade__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvFade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_fade,
           a3: "env_fade");
}
