// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/movehelper_server.cpp
// Functions: 15
// ============================================================

#include "game\server\movehelper_server.h"

//------------------------------------------------------------------------------
// Address: 0x10173880
// Name: public: virtual void CMoveHelperServer::SetHost(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::SetHost(CMoveHelperServer *this, CBaseEntity *host)
{
  CMoveHelperServer_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pHost = host;
  ((void (*)(void))v2->ResetTouchList)();
}

//------------------------------------------------------------------------------
// Address: 0x101738A0
// Name: public: virtual void CMoveHelperServer::SetGroundNormal(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::SetGroundNormal(CMoveHelperServer *this, const Vector *groundNormal)
{
  this->m_groundNormal = *groundNormal;
}

//------------------------------------------------------------------------------
// Address: 0x101738C0
// Name: public: virtual void CMoveHelperServer::PlaybackEventFull(int,int,unsigned short,float,class Vector __near &,class Vector __near &,float,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::PlaybackEventFull(
        CMoveHelperServer *this,
        int flags,
        int clientindex,
        unsigned __int16 eventindex,
        float delay,
        Vector *origin,
        Vector *angles,
        float fparam1,
        float fparam2,
        int iparam1,
        int iparam2,
        int bparam1,
        int bparam2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101738D0
// Name: public: virtual class IPhysicsSurfaceProps __near * CMoveHelperServer::GetSurfaceProps(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsSurfaceProps *__thiscall CMoveHelperServer::GetSurfaceProps(CMoveHelperServer *this)
{
  return physprops;
}

//------------------------------------------------------------------------------
// Address: 0x101738E0
// Name: public: virtual void CMoveHelperServer::Con_NPrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMoveHelperServer::Con_NPrintf(CMoveHelperServer *this, int idx, char *pFormat, ...)
{
  char pDest[8192]; // [esp+0h] [ebp-2000h] BYREF
  va_list params; // [esp+2014h] [ebp+14h] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 0x2000, pFormat, params);
  engine->Con_NPrintf(this: engine, a2: idx, a3: pDest);
}

//------------------------------------------------------------------------------
// Address: 0x10173930
// Name: public: virtual void CMoveHelperServer::PlayerSetAnimation(enum PLAYER_ANIM)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::PlayerSetAnimation(CMoveHelperServer *this, PLAYER_ANIM eAnim)
{
  if ( this->m_pHost != nullptr && this->m_pHost->IsPlayer(this: this->m_pHost) )
    ((void (__thiscall *)(CBaseEntity *, PLAYER_ANIM))this->m_pHost->__vftable[2].GetNetworkable)(
      a1: this->m_pHost,
      a2: eAnim);
}

//------------------------------------------------------------------------------
// Address: 0x101739A0
// Name: public: virtual char const __near * CMoveHelperServer::GetName(class CBaseHandle)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMoveHelperServer::GetName(CMoveHelperServer *this, CBaseHandle handle)
{
  CEntInfo *v2; // eax
  int v3; // eax
  int v4; // edi
  CGlobalVars *v5; // edx
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v8; // eax
  _DWORD *v9; // esi
  const char *result; // eax
  bool v11; // zf
  const char *v12; // esi
  _BYTE v13[4]; // [esp+8h] [ebp-4h] BYREF

  if ( handle.m_Index != -1
    && (v2 = &gEntList.m_EntPtrArray[LOWORD(handle.m_Index)])->m_SerialNumber == HIWORD(handle.m_Index)
    && v2->m_pEntity != nullptr )
  {
    v3 = ((int (__thiscall *)(IHandleEntity *))v2->m_pEntity->__vftable[1].SetRefEHandle)(a1: v2->m_pEntity);
    v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
  }
  else
  {
    v4 = 0;
  }
  v5 = gpGlobals;
  pEdicts = (edict_t *)v4;
  if ( (v4 != 0 || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr )
  {
    v8 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
    v5 = gpGlobals;
    v9 = (_DWORD *)v8;
  }
  else
  {
    v9 = nullptr;
  }
  if ( v4 != 0 && (signed int)(v4 - (unsigned int)v5->pEdicts) >> 4 != 0 )
  {
    if ( v9 != nullptr && *(_DWORD *)(*(int (__thiscall **)(_DWORD *, _BYTE *))(*v9 + 28))(a1: v9, a2: v13) != 0 )
    {
      result = *(const char **)(*(int (__thiscall **)(_DWORD *, _BYTE *))(*v9 + 28))(a1: v9, a2: v13);
      v11 = result == nullptr;
    }
    else
    {
      v12 = (const char *)v9[23];
      v11 = v12 == nullptr;
      result = v12;
    }
  }
  else
  {
    result = v5->mapname.pszValue;
    v11 = result == nullptr;
  }
  if ( v11 )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10173A70
// Name: public: virtual void CMoveHelperServer::StartSound(class Vector const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::StartSound(CMoveHelperServer *this, const Vector *origin, const char *soundname)
{
  edict_t *m_pPev; // eax
  CRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
  m_pPev = this->m_pHost->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(
    &filter,
    iEntIndex: (int)m_pPev,
    soundname,
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10173AD0
// Name: public: virtual bool CMoveHelperServer::PlayerFallingDamage(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMoveHelperServer::PlayerFallingDamage(CMoveHelperServer *this)
{
  CBasePlayer *m_pHost; // esi
  double v3; // st7
  CGlobalVars *v4; // edx
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v7; // eax
  CBaseEntity *v8; // ebx
  edict_t *v9; // eax
  IServerUnknown *v10; // ecx
  CBaseEntity *v11; // eax
  const CTakeDamageInfo *v12; // eax
  CBaseEntity *v13; // edi
  CCSPlayer *v14; // eax
  CTakeDamageInfo v16; // [esp+24h] [ebp-60h] BYREF
  color32_s black; // [esp+80h] [ebp-4h] BYREF
  int savedregs; // [esp+84h] [ebp+0h] BYREF

  if ( !this->m_pHost->IsPlayer(this: this->m_pHost) )
    return 1;
  m_pHost = (CBasePlayer *)this->m_pHost;
  v3 = ((double (__thiscall *)(CGameRules *, CBasePlayer *))g_pGameRules->FlPlayerFallDamage)(
         a1: g_pGameRules,
         a2: m_pHost);
  *(float *)&black = v3;
  if ( v3 > 0.0 )
  {
    v4 = gpGlobals;
    if ( gpGlobals->pEdicts != nullptr
      && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0
      && (m_pUnk = pEdicts->m_pUnk) != nullptr )
    {
      v7 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v4 = gpGlobals;
      v8 = (CBaseEntity *)v7;
    }
    else
    {
      v8 = nullptr;
    }
    if ( v4->pEdicts != nullptr && ((v9 = v4->pEdicts)->m_fStateFlags & 2) == 0 && (v10 = v9->m_pUnk) != nullptr )
      v11 = v10->GetBaseEntity(this: v10);
    else
      v11 = nullptr;
    v12 = CTakeDamageInfo::CTakeDamageInfo(
            this: &v16,
            pInflictor: v11,
            pAttacker: v8,
            flDamage: *(float *)&black,
            bitsDamageType: 32,
            iKillType: 0,
            iObjectsPenetrated: 0);
    CBaseEntity::TakeDamage(this: m_pHost, a2: (int)m_pHost, inputInfo: v12);
    if ( (m_pHost->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pHost, a2: (int)&savedregs);
    this->StartSound(this, a2: &m_pHost->m_vecAbsOrigin, a3: "Player.FallDamage");
    v13 = this->m_pHost;
    if ( v13 != nullptr && v13->IsPlayer(this: v13) )
    {
      v14 = (CCSPlayer *)__RTDynamicCast(
                           inptr: v13,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      if ( v14 != nullptr )
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: v14,
          statId: CSSTAT_FALL_DAMAGE,
          iDelta: *(_DWORD *)&black,
          bPlayerOnly: false);
    }
  }
  if ( m_pHost->m_iHealth.m_Value > 0 )
    return 1;
  if ( g_pGameRules->FlPlayerFallDeathDoesScreenFade(this: g_pGameRules, a2: m_pHost) )
  {
    *(float *)&black = -1.7014118e38;
    UTIL_ScreenFade(pEntity: m_pHost, color: &black, fadeTime: 0.0, fadeHold: 9999.0, flags: 10);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10173C60
// Name: class IMoveHelper __near * MoveHelperServer(void)
// Source: json
//------------------------------------------------------------------------------
IMoveHelper *__cdecl MoveHelperServer()
{
  return IMoveHelper::sm_pSingleton;
}

//------------------------------------------------------------------------------
// Address: 0x10173C70
// Name: public: virtual void CMoveHelperServer::ProcessImpacts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::ProcessImpacts(CMoveHelperServer *this)
{
  int v2; // ebx
  CBaseEntity *m_pHost; // edi
  CBaseEntity *m_pEnt; // ecx
  unsigned int m_Index; // eax
  CEntInfo *v6; // ecx
  IHandleEntity *m_pEntity; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  CBaseEntity *v12; // eax
  int v13; // edi
  CBaseEntity *v14; // eax
  float x; // xmm0_4
  CBaseEntity *v16; // ebx
  float y; // xmm0_4
  float z; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  Vector vel; // [esp+Ch] [ebp-14h] BYREF
  CBaseEntity *entity; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v2 = 0;
  CBaseEntity::PhysicsTouchTriggers(this: this->m_pHost, pPrevAbsOrigin: nullptr);
  m_pHost = this->m_pHost;
  if ( (m_pHost->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
  {
    if ( (m_pHost->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: this->m_pHost, a2: (int)&savedregs);
    vel = m_pHost->m_vecAbsVelocity;
    for ( i = 0; i < this->m_TouchList.m_Size; ++i )
    {
      m_pEnt = this->m_TouchList.m_Memory.m_pMemory[v2].trace.m_pEnt;
      m_Index = m_pEnt->GetRefEHandle(this: m_pEnt)->m_Index;
      if ( m_Index != -1 )
      {
        v6 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
        if ( v6->m_SerialNumber == HIWORD(m_Index) )
        {
          m_pEntity = v6->m_pEntity;
          if ( m_pEntity != nullptr )
          {
            v8 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[1].SetRefEHandle)(a1: m_pEntity);
            v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
            v10 = v9;
            if ( v9 != 0 )
            {
              v11 = *(_DWORD *)(v9 + 12);
              if ( v11 != 0 )
              {
                v12 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 20))(a1: v11);
                entity = v12;
                if ( v12 != nullptr && v12 != this->m_pHost )
                {
                  v13 = *(_DWORD *)(v10 + 12);
                  if ( v13 != 0 )
                    v14 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v13 + 20))(a1: v13);
                  else
                    v14 = nullptr;
                  this->m_TouchList.m_Memory.m_pMemory[v2].trace.m_pEnt = v14;
                  CBaseEntity::SetAbsVelocity(
                    this: this->m_pHost,
                    vecAbsVelocity: &this->m_TouchList.m_Memory.m_pMemory[v2].deltavelocity);
                  CBaseEntity::PhysicsImpact(
                    this: entity,
                    other: this->m_pHost,
                    trace: &this->m_TouchList.m_Memory.m_pMemory[v2].trace);
                }
              }
            }
          }
        }
      }
      ++v2;
    }
    CBaseEntity::SetAbsVelocity(this: this->m_pHost, vecAbsVelocity: &vel);
    if ( this->m_pHost != nullptr && this->m_pHost->IsPlayer(this: this->m_pHost) )
    {
      x = this->m_collisionNormal.x;
      v16 = this->m_pHost;
      if ( x <= -0.0099999998
        || x >= 0.0099999998
        || (y = this->m_collisionNormal.y) <= -0.0099999998
        || y >= 0.0099999998
        || (z = this->m_collisionNormal.z) <= -0.0099999998
        || z >= 0.0099999998 )
      {
        VectorNormalize(vec: &this->m_collisionNormal);
        v16[5].m_vecAbsVelocity.y = this->m_collisionNormal.x;
        v16[5].m_vecAbsVelocity.z = this->m_collisionNormal.y;
        v16[5].m_vecAngVelocity.x = this->m_collisionNormal.z;
      }
      v19 = this->m_groundNormal.x;
      if ( v19 <= -0.0099999998
        || v19 >= 0.0099999998
        || (v20 = this->m_groundNormal.y) <= -0.0099999998
        || v20 >= 0.0099999998
        || (v21 = this->m_groundNormal.z) <= -0.0099999998
        || v21 >= 0.0099999998 )
      {
        v16[5].m_vecAngVelocity.y = v19;
        v16[5].m_vecAngVelocity.z = this->m_groundNormal.y;
        v16[5].m_rgflCoordinateFrame.m_flMatVal[0][0] = this->m_groundNormal.z;
      }
    }
    this->ResetTouchList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173E90
// Name: public: virtual bool CMoveHelperServer::IsWorldEntity(class CBaseHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMoveHelperServer::IsWorldEntity(CMoveHelperServer *this, const CBaseHandle *handle)
{
  edict_t *pEdicts; // esi
  edict_t *v3; // eax
  IServerUnknown *m_pUnk; // ecx
  IHandleEntity *v5; // eax
  unsigned int m_Index; // edx

  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v3 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
  else
    v3 = nullptr;
  if ( (v3 != nullptr || pEdicts != nullptr && (v3 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v3->m_pUnk) != nullptr )
  {
    v5 = m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v5 = nullptr;
  }
  m_Index = handle->m_Index;
  if ( handle->m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    return v5 == nullptr;
  }
  else
  {
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10173F20
// Name: public: virtual void CMoveHelperServer::ResetTouchList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::ResetTouchList(CMoveHelperServer *this)
{
  this->m_TouchList.m_Size = 0;
  this->m_collisionNormal.x = 0.0;
  this->m_collisionNormal.y = 0.0;
  this->m_collisionNormal.z = 0.0;
  this->m_groundNormal.x = 0.0;
  this->m_groundNormal.y = 0.0;
  this->m_groundNormal.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10173FF0
// Name: public: virtual bool CMoveHelperServer::AddToTouched(class CGameTrace const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMoveHelperServer::AddToTouched(
        CMoveHelperServer *this,
        const CGameTrace *tr,
        const Vector *impactvelocity)
{
  CBaseEntity *m_pEnt; // eax
  int v5; // eax
  CBaseEntity **p_m_pEnt; // edx
  CUtlVector<CMoveHelperServer::touchlist_t,CUtlMemory<CMoveHelperServer::touchlist_t,int> > *p_m_TouchList; // edi
  int v8; // esi

  m_pEnt = tr->m_pEnt;
  if ( m_pEnt == nullptr || m_pEnt == this->m_pHost )
    return 0;
  this->m_collisionNormal.x = tr->plane.normal.x + this->m_collisionNormal.x;
  this->m_collisionNormal.y = tr->plane.normal.y + this->m_collisionNormal.y;
  this->m_collisionNormal.z = tr->plane.normal.z + this->m_collisionNormal.z;
  v5 = this->m_TouchList.m_Size - 1;
  if ( v5 < 0 )
  {
LABEL_8:
    p_m_TouchList = &this->m_TouchList;
    v8 = CUtlVector<CMoveHelperServer::touchlist_t,CUtlMemory<CMoveHelperServer::touchlist_t,int>>::AddToTail(this: &this->m_TouchList);
    CGameTrace::operator=(this: &p_m_TouchList->m_Memory.m_pMemory[v8].trace, __that: tr);
    p_m_TouchList->m_Memory.m_pMemory[v8].deltavelocity = *impactvelocity;
    return 1;
  }
  else
  {
    p_m_pEnt = &this->m_TouchList.m_Memory.m_pMemory[v5].trace.m_pEnt;
    while ( *p_m_pEnt != tr->m_pEnt )
    {
      p_m_pEnt -= 24;
      if ( --v5 < 0 )
        goto LABEL_8;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101740A0
// Name: public: virtual void CMoveHelperServer::StartSound(class Vector const __near &,int,char const __near *,float,enum soundlevel_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMoveHelperServer::StartSound(
        CMoveHelperServer *this,
        const Vector *origin,
        int channel,
        const char *sample,
        unsigned int volume,
        soundlevel_t soundlevel,
        int fFlags,
        int pitch)
{
  signed int v9; // eax
  CBaseEntity *m_pHost; // ecx
  edict_t *m_pPev; // ecx
  CBaseEntity *v12; // ecx
  edict_t *v13; // ecx
  EmitSound_t ep; // [esp+Ch] [ebp-68h] BYREF
  CRecipientFilter filter; // [esp+54h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin);
  if ( gpGlobals->maxClients == 1 )
  {
    ep.m_hSoundScriptHandle = -1;
    ep.m_nChannel = channel;
    ep.m_pSoundName = sample;
    v9 = 0;
    ep.m_nFlags = fFlags;
    ep.m_flSoundTime = 0.0;
    ep.m_nPitch = pitch;
    m_pHost = this->m_pHost;
    ep.m_pflSoundDuration = nullptr;
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    *(_QWORD *)&ep.m_flVolume = __PAIR64__(soundlevel, volume);
    ep.m_pOrigin = origin;
    m_pPev = m_pHost->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v9 = m_pPev - gpGlobals->pEdicts;
  }
  else
  {
    CRecipientFilter::UsePredictionRules(this: &filter);
    ep.m_hSoundScriptHandle = -1;
    v9 = 0;
    ep.m_nChannel = channel;
    ep.m_pSoundName = sample;
    ep.m_flSoundTime = 0.0;
    ep.m_nFlags = fFlags;
    v12 = this->m_pHost;
    ep.m_pflSoundDuration = nullptr;
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    *(_QWORD *)&ep.m_flVolume = __PAIR64__(soundlevel, volume);
    ep.m_nPitch = pitch;
    ep.m_pOrigin = origin;
    v13 = v12->m_Network.m_pPev;
    if ( v13 != nullptr )
      v9 = v13 - gpGlobals->pEdicts;
  }
  CBaseEntity::EmitSound(&filter, iEntIndex: v9, params: &ep);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}
