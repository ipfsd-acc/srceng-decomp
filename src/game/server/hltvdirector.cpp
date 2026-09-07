// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/hltvdirector.cpp
// Functions: 34
// ============================================================

#include "game\server\hltvdirector.h"

//------------------------------------------------------------------------------
// Address: 0x1015D2F0
// Name: InitRandomOrder
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall InitRandomOrder(int nFields@<eax>, IUniformRandomStream *a2@<ecx>)
{
  int v2; // edi
  int i; // eax
  int v4; // eax
  int v5; // edi
  int v6; // esi
  IUniformRandomStream *v7; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // [esp+4h] [ebp-4h]

  v2 = nFields;
  if ( nFields > 256 )
    v2 = 256;
  for ( i = 0; i < v2; ++i )
    s_RndOrder[i] = i;
  v4 = v2 / 2;
  if ( v2 / 2 > 0 )
  {
    v5 = v2 - 1;
    v10 = v4;
    do
    {
      v6 = _RandomInt(this: a2, a2: 0, a3: v5);
      v8 = _RandomInt(this: v7, a2: 0, a3: v5);
      a2 = (IUniformRandomStream *)s_RndOrder[v6];
      v9 = v10-- == 1;
      s_RndOrder[v6] = s_RndOrder[v8];
      s_RndOrder[v8] = (int)a2;
    }
    while ( !v9 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D370
// Name: public: virtual bool CHLTVDirector::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLTVDirector::Init(CHLTVDirector *this)
{
  return gameeventmanager->LoadEventsFromFile(this: gameeventmanager, a2: "resource/hltvevents.res") > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015D3A0
// Name: public: virtual bool CHLTVDirector::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHLTVDirector::IsActive(CHLTVDirector *this)
{
  return this->m_nDebugID != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015D3B0
// Name: public: virtual class Vector CHLTVDirector::GetPVSOrigin(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CHLTVDirector::GetPVSOrigin(CHLTVDirector *this, Vector *result)
{
  __int64 v2; // xmm0_8
  int m_nBroadcastTick; // ecx

  v2 = *(_QWORD *)&this->m_pHLTVServer;
  m_nBroadcastTick = this->m_nBroadcastTick;
  *(_QWORD *)&result->x = v2;
  LODWORD(result->z) = m_nBroadcastTick;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D3D0
// Name: public: virtual char const __near * __near * CHLTVDirector::GetModEvents(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CHLTVDirector::GetModEvents(CHLTVDirector *this)
{
  return s_modevents;
}

//------------------------------------------------------------------------------
// Address: 0x1015D3E0
// Name: public: virtual void CHLTVDirector::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::FrameUpdatePostEntityThink(CHLTVDirector *this)
{
  int tickcount; // eax
  CBasePlayer *v3; // ecx
  void (__thiscall *v4)(char *); // eax
  IHLTVDirector_vtbl *v5; // eax

  if ( *(_DWORD *)&this->m_bRegisteredForEvents != 0 )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 44))(a1: (char *)this - 12);
    tickcount = gpGlobals->tickcount;
    if ( (int)this->m_pHLTVClient < tickcount
      && *(float *)&this->CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable >= 10.0 )
    {
      v3 = (CBasePlayer *)(tickcount + (int)(float)((float)(0.5 / gpGlobals->interval_per_tick) + 0.5));
      v4 = *(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 48);
      this->m_pHLTVClient = v3;
      v4(a1: (char *)this - 12);
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 52))(a1: (char *)this - 12);
    }
    v5 = this->IHLTVDirector::__vftable;
    if ( (int)v5 > 0 )
    {
      if ( SLODWORD(this->m_vPVSOrigin.z) <= (int)v5 )
        (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 16))(a1: (char *)this - 12);
    }
    else
    {
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 24))(a1: (char *)this - 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D470
// Name: protected: virtual void CHLTVDirector::StartDelayMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVDirector::StartDelayMessage(CHLTVDirector *this@<ecx>, int a2@<esi>)
{
  int tickcount; // eax
  int v4; // eax
  IGameEvent *v5; // esi

  tickcount = gpGlobals->tickcount;
  if ( this->m_nNextShotTick <= tickcount )
  {
    this->m_nNextShotTick = tickcount + (int)(float)((float)(6.0 / gpGlobals->interval_per_tick) + 0.5);
    v4 = ((int (__thiscall *)(IGameEventManager2 *, const char *, int, _DWORD, int))gameeventmanager->CreateEventA)(
           a1: gameeventmanager,
           a2: "hltv_message",
           a3: 1,
           a4: 0,
           a5: a2);
    v5 = (IGameEvent *)v4;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v4 + 56))(
        a1: v4,
        a2: "text",
        a3: "Please wait for broadcast to start ...");
      this->m_pHLTVServer->BroadcastEvent(this: this->m_pHLTVServer, a2: v5);
      gameeventmanager->FreeEvent(this: gameeventmanager, a2: v5);
    }
    this->StartBestFixedCameraShot(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D500
// Name: protected: virtual void CHLTVDirector::StartChaseCameraShot(int,int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::StartChaseCameraShot(
        CHLTVDirector *this,
        int iTarget1,
        int iTarget2,
        int distance,
        int phi,
        int theta,
        bool bInEye)
{
  IGameEvent *v8; // esi
  IHLTVServer *m_pHLTVServer; // ecx

  v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_chase", a3: 1, a4: 0);
  if ( v8 != nullptr )
  {
    v8->SetInt(this: v8, a2: "target1", a3: iTarget1);
    v8->SetInt(this: v8, a2: "target2", a3: iTarget2);
    v8->SetInt(this: v8, a2: "distance", a3: distance);
    v8->SetInt(this: v8, a2: "phi", a3: phi);
    v8->SetInt(this: v8, a2: "theta", a3: theta);
    v8->SetInt(this: v8, a2: "ineye", a3: bInEye);
    m_pHLTVServer = this->m_pHLTVServer;
    this->m_iPVSEntity = iTarget1;
    m_pHLTVServer->BroadcastEvent(this: m_pHLTVServer, a2: v8);
    gameeventmanager->FreeEvent(this: gameeventmanager, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D5C0
// Name: public: void CHLTVDirector::BuildCameraList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::BuildCameraList(CHLTVDirector *this)
{
  const char *v2; // eax
  CBaseEntity *i; // edi
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // ebx
  char *(__thiscall *GetFixedCameraEntityName)(CHLTVDirector *); // eax
  const char *v7; // eax
  QAngle angles; // [esp+8h] [ebp-18h] BYREF
  Vector forward; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  this->m_nNumFixedCameras = 0;
  memset(dst: (int)this->m_pFixedCameras, value: nullptr, count: sizeof(this->m_pFixedCameras));
  v2 = this->GetFixedCameraEntityName(this);
  for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: v2);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: v7) )
  {
    if ( this->m_nNumFixedCameras >= 64 )
      break;
    pszValue = i->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      forward.x = EntityByName->m_vecAbsOrigin.x - i->m_vecAbsOrigin.x;
      forward.y = EntityByName->m_vecAbsOrigin.y - i->m_vecAbsOrigin.y;
      forward.z = EntityByName->m_vecAbsOrigin.z - i->m_vecAbsOrigin.z;
      VectorAngles(&forward, &angles);
      CBaseEntity::SetAbsAngles(this: i, absAngles: &angles);
    }
    this->m_pFixedCameras[this->m_nNumFixedCameras] = i;
    GetFixedCameraEntityName = this->GetFixedCameraEntityName;
    ++this->m_nNumFixedCameras;
    v7 = GetFixedCameraEntityName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D700
// Name: protected: virtual void CHLTVDirector::StartFixedCameraShot(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::StartFixedCameraShot(CHLTVDirector *this, int iCamera, int iTarget)
{
  CBaseEntity *v4; // esi
  __int64 v5; // xmm0_8
  IGameEvent *v6; // esi
  IGameEvent_vtbl *v7; // ebx
  IUniformRandomStream *v8; // ecx
  float v9; // [esp+48h] [ebp-20h]
  __int64 vCamPos; // [esp+5Ch] [ebp-Ch]
  float vCamPos_8; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  v4 = this->m_pFixedCameras[iCamera];
  if ( (v4->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
  vCamPos = *(_QWORD *)&v4->m_vecAbsOrigin.x;
  vCamPos_8 = v4->m_vecAbsOrigin.z;
  if ( (v4->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
  v5 = *(_QWORD *)&v4->m_angAbsRotation.x;
  this->m_iPVSEntity = 0;
  *(_QWORD *)&this->m_vPVSOrigin.x = vCamPos;
  this->m_vPVSOrigin.z = vCamPos_8;
  v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_fixed", a3: 1, a4: 0);
  if ( v6 != nullptr )
  {
    v6->SetInt(this: v6, a2: "posx", a3: (int)*(float *)&vCamPos);
    v6->SetInt(this: v6, a2: "posy", a3: (int)*((float *)&vCamPos + 1));
    v6->SetInt(this: v6, a2: "posz", a3: (int)vCamPos_8);
    v6->SetInt(this: v6, a2: "theta", a3: (int)*(float *)&v5);
    v6->SetInt(this: v6, a2: "phi", a3: (int)*((float *)&v5 + 1));
    v6->SetInt(this: v6, a2: "target", a3: iTarget);
    v7 = v6->__vftable;
    v9 = _RandomFloat(this: v8, a2: 50.0, a3: 110.0);
    ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v7->SetFloat)(a1: v6, a2: "fov", a3: LODWORD(v9));
    this->m_pHLTVServer->BroadcastEvent(this: this->m_pHLTVServer, a2: v6);
    gameeventmanager->FreeEvent(this: gameeventmanager, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D880
// Name: protected: virtual void CHLTVDirector::CreateShotFromEvent(class CHLTVGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::CreateShotFromEvent(CHLTVDirector *this, CHLTVGameEvent *event)
{
  const char *v2; // esi
  bool v3; // bl
  bool v4; // al
  int v5; // eax
  CBasePlayer *v6; // esi
  int v7; // eax
  CBasePlayer *v8; // eax
  IUniformRandomStream *v9; // ecx
  CBasePlayer *v10; // edi
  float v11; // xmm0_4
  IUniformRandomStream *v12; // ecx
  CBasePlayer *v13; // eax
  int v14; // ebx
  edict_t *v15; // eax
  signed int v16; // eax
  signed int v17; // ecx
  CHLTVDirector *v18; // esi
  signed int m_pPev; // esi
  int m_nNextShotTick; // eax
  bool bRoundStart; // [esp+32h] [ebp-2h]
  bool bPlayerKilled; // [esp+33h] [ebp-1h]

  v2 = event->m_Event->GetName(this: event->m_Event);
  v3 = _V_strcmp(s1: "player_hurt", s2: v2) == 0;
  bPlayerKilled = _V_strcmp(s1: "player_death", s2: v2) == 0;
  bRoundStart = _V_strcmp(s1: "round_start", s2: v2) == 0;
  v4 = _V_strcmp(s1: "round_end", s2: v2) == 0;
  if ( v3 || bPlayerKilled )
  {
    v5 = event->m_Event->GetInt(this: event->m_Event, a2: "userid", a3: 0);
    v6 = UTIL_PlayerByUserId(userID: v5);
    v7 = event->m_Event->GetInt(this: event->m_Event, a2: "attacker", a3: 0);
    v8 = UTIL_PlayerByUserId(userID: v7);
    v10 = v8;
    if ( v6 != nullptr )
    {
      if ( v8 == v6 || v8 == nullptr )
      {
        m_pPev = (signed int)v6->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        this->StartChaseCameraShot(this, a2: m_pPev, a3: 0, a4: 96, a5: 20, a6: 0, a7: false);
        v18 = this;
      }
      else
      {
        if ( bPlayerKilled && _RandomFloat(this: v9, a2: 0.0, a3: 1.0) > 0.33
          || v3 && _RandomFloat(this: v9, a2: 0.0, a3: 1.0) > 0.66 )
        {
          v11 = 0.30000001;
        }
        else
        {
          v11 = 0.69999999;
        }
        if ( _RandomFloat(this: v9, a2: 0.0, a3: 1.0) > (double)v11 )
        {
          v13 = v10;
          v10 = v6;
          v6 = v13;
        }
        v14 = 30;
        if ( _RandomFloat(this: v12, a2: 0.0, a3: 1.0) <= 0.5 )
          v14 = -30;
        v15 = v10->m_Network.m_pPev;
        if ( v15 != nullptr )
          v16 = v15 - gpGlobals->pEdicts;
        else
          v16 = 0;
        v17 = (signed int)v6->m_Network.m_pPev;
        if ( v17 != 0 )
          v17 = (signed int)(v17 - (unsigned int)gpGlobals->pEdicts) >> 4;
        v18 = this;
        ((void (__thiscall *)(CHLTVDirector *, signed int, signed int, int, int, int))this->StartChaseCameraShot)(
          a1: this,
          a2: v17,
          a3: v16,
          a4: 96,
          a5: -20,
          a6: v14);
      }
      m_nNextShotTick = (int)(float)((float)(2.0 / gpGlobals->interval_per_tick) + 0.5) + event->m_Tick;
      if ( v18->m_nNextShotTick < m_nNextShotTick )
        m_nNextShotTick = v18->m_nNextShotTick;
      v18->m_nNextShotTick = m_nNextShotTick;
    }
  }
  else if ( bRoundStart || v4 )
  {
    this->StartBestFixedCameraShot(this, a2: false);
  }
  else
  {
    DevMsg(a1: "No known TV shot for event %s\n", v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015DCA0
// Name: protected: virtual void CHLTVDirector::StartRandomShot(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CHLTVDirector::StartRandomShot(CHLTVDirector *this)
{
  IUniformRandomStream *m_nNextShotTick; // ecx
  int v3; // eax

  m_nNextShotTick = (IUniformRandomStream *)this->m_nNextShotTick;
  v3 = this->m_nBroadcastTick + (int)(float)((float)(6.0 / gpGlobals->interval_per_tick) + 0.5);
  if ( (int)m_nNextShotTick < v3 )
    v3 = (int)m_nNextShotTick;
  this->m_nNextShotTick = v3;
  if ( _RandomFloat(this: m_nNextShotTick, a2: 0.0, a3: 1.0) < 0.25
    && tv_allow_static_shots.m_pParent != nullptr
    && tv_allow_static_shots.m_pParent->m_Value.m_nValue != 0 )
  {
    this->StartBestFixedCameraShot(this, a2: false);
  }
  else
  {
    this->StartBestPlayerCameraShot(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015DD30
// Name: public: bool CHLTVDirector::SetCameraMan(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVDirector::SetCameraMan(CHLTVDirector *this, CBasePlayer *iPlayerIndex)
{
  int m_iCameraManIndex; // eax
  CBasePlayer *v6; // eax
  IGameEvent *v7; // esi
  int i; // edi
  CBasePlayer *v9; // eax
  CBasePlayer *v10; // esi
  const char *v11; // eax
  char szText[200]; // [esp+4h] [ebp-E8h] BYREF
  CRecipientFilter filter; // [esp+CCh] [ebp-20h] BYREF
  CBasePlayer *pPlayer; // [esp+F4h] [ebp+8h]

  if ( tv_allow_camera_man.m_pParent == nullptr || tv_allow_camera_man.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  m_iCameraManIndex = this->m_iCameraManIndex;
  if ( (CBasePlayer *)m_iCameraManIndex != iPlayerIndex )
  {
    if ( m_iCameraManIndex != 0 && iPlayerIndex != nullptr )
      return 0;
    pPlayer = nullptr;
    if ( (int)iPlayerIndex > 0 )
    {
      v6 = UTIL_PlayerByIndex(playerIndex: (int)iPlayerIndex);
      pPlayer = v6;
      if ( v6 == nullptr || CBaseEntity::GetTeamNumber(this: v6) != 1 )
        return 0;
    }
    this->m_iCameraManIndex = (int)iPlayerIndex;
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_cameraman", a3: 0, a4: 0);
    if ( v7 != nullptr )
    {
      v7->SetInt(this: v7, a2: "index", a3: (int)iPlayerIndex);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
    }
    CRecipientFilter::CRecipientFilter(this: &filter);
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v9 = UTIL_PlayerByIndex(playerIndex: i);
      v10 = v9;
      if ( v9 != nullptr && CBaseEntity::GetTeamNumber(this: v9) == 1 && !v10->IsFakeClient(this: v10) )
        CRecipientFilter::AddRecipient(this: &filter, player: v10);
    }
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    if ( (int)iPlayerIndex > 0 )
    {
      v11 = pPlayer->GetPlayerName(this: pPlayer);
      V_snprintf(pDest: szText, maxLen: 200, pFormat: "SourceTV camera is now controlled by %s.", v11);
      UTIL_ClientPrintFilter(
        &filter,
        msg_dest: 3,
        msg_name: szText,
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      CRecipientFilter::~CRecipientFilter(this: &filter);
      return 1;
    }
    UTIL_ClientPrintFilter(
      &filter,
      msg_dest: 3,
      msg_name: "SourceTV camera switched to auto-director mode.",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015DED0
// Name: protected: virtual void CHLTVDirector::AnalyzeCameras(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CHLTVDirector::AnalyzeCameras(CHLTVDirector *this@<ecx>, IHandleEntity_vtbl *a2@<ebp>)
{
  float z; // edi
  int m_nNumFixedCameras; // eax
  bool v4; // cc
  int v5; // esi
  int v6; // ecx
  float v7; // edx
  CBaseEntity *v8; // esi
  int z_low; // edx
  __int128 v10; // xmm0
  float v11; // eax
  const QAngle *v12; // eax
  float v13; // xmm0_4
  __int128 v14; // xmm0
  IGameEvent *v15; // esi
  int v16; // [esp+20h] [ebp-ECh] BYREF
  _BYTE tr_32[56]; // [esp+4Ch] [ebp-C0h] OVERLAPPED BYREF
  Vector v1; // [esp+84h] [ebp-88h] BYREF
  __int128 v19; // [esp+90h] [ebp-7Ch]
  Vector v20; // [esp+A0h] [ebp-6Ch] BYREF
  int v21; // [esp+ACh] [ebp-60h]
  __int64 v22; // [esp+B0h] [ebp-5Ch]
  int iCameraIndex; // [esp+B8h] [ebp-54h]
  Vector vPlayerPos; // [esp+BCh] [ebp-50h] BYREF
  Vector v2; // [esp+C8h] [ebp-44h] BYREF
  Vector vCamPos; // [esp+D4h] [ebp-38h]
  int iClosestPlayer; // [esp+E0h] [ebp-2Ch]
  float flClosestPlayerDist; // [esp+E4h] [ebp-28h]
  int nCount; // [esp+E8h] [ebp-24h]
  Vector vDistribution; // [esp+ECh] [ebp-20h]
  int v31; // [esp+F8h] [ebp-14h]
  int i; // [esp+FCh] [ebp-10h]
  IHandleEntity v33; // [esp+100h] [ebp-Ch] BYREF
  int j; // [esp+104h] [ebp-8h]
  int retaddr; // [esp+10Ch] [ebp+0h]

  v33.__vftable = a2;
  j = retaddr;
  z = *(float *)&this;
  m_nNumFixedCameras = this->m_nNumFixedCameras;
  LODWORD(vDistribution.z) = this;
  InitRandomOrder(nFields: m_nNumFixedCameras, a2: (IUniformRandomStream *)this);
  v4 = *(_DWORD *)(LODWORD(z) + 68) <= 0;
  vDistribution.y = 0.0;
  if ( !v4 )
  {
    do
    {
      v5 = *(_DWORD *)(LODWORD(z) + 4 * s_RndOrder[LODWORD(vDistribution.y)] + 72);
      v6 = *(_DWORD *)(v5 + 196);
      v21 = s_RndOrder[LODWORD(vDistribution.y)];
      *(float *)&i = 0.0;
      vCamPos.x = 0.0;
      vCamPos.y = 100000.0;
      vCamPos.z = 0.0;
      *(float *)&iClosestPlayer = 0.0;
      flClosestPlayerDist = 0.0;
      *(float *)&nCount = 0.0;
      if ( (v6 & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v5, a2: (int)&v33);
      v4 = *(_DWORD *)(LODWORD(z) + 328) <= 0;
      v7 = *(float *)(v5 + 468);
      *(_QWORD *)&v2.x = *(_QWORD *)(v5 + 460);
      v2.z = v7;
      *(float *)&v31 = 0.0;
      if ( !v4 )
      {
        LODWORD(vDistribution.x) = LODWORD(z) + 332;
        do
        {
          v8 = *(CBaseEntity **)LODWORD(vDistribution.x);
          if ( (*(_DWORD *)(*(_DWORD *)LODWORD(vDistribution.x) + 196) & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)LODWORD(vDistribution.x), a2: (int)&v33);
          z_low = SLODWORD(v8->m_vecAbsOrigin.z);
          v22 = *(_QWORD *)&v8->m_vecAbsOrigin.x;
          iCameraIndex = z_low;
          v10 = 0;
          *(float *)&v10 = fsqrt(
                             (float)((float)((float)(*((float *)&v22 + 1) - v2.y) * (float)(*((float *)&v22 + 1) - v2.y))
                                   + (float)((float)(*(float *)&z_low - v2.z) * (float)(*(float *)&z_low - v2.z)))
                           + (float)((float)(*(float *)&v22 - v2.x) * (float)(*(float *)&v22 - v2.x)));
          v19 = v10;
          if ( *(float *)&v10 <= 1024.0 && *(float *)&v19 >= 4.0 )
          {
            if ( (v8->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v8, a2: (int)&v33);
            UTIL_TraceLine(
              a1: &v33,
              a2: (int)v8,
              vecAbsStart: &v2,
              vecAbsEnd: &v8->m_vecAbsOrigin,
              mask: 0x200400Bu,
              ignore: v8,
              collisionGroup: 0,
              ptr: (CGameTrace *)&v16);
            if ( *(float *)tr_32 >= 1.0 )
            {
              ++LODWORD(vCamPos.z);
              if ( vCamPos.y > *(float *)&v19 )
              {
                v11 = *(float *)&v8->m_Network.m_pPev;
                if ( v11 != 0.0 )
                  LODWORD(v11) = (signed int)(LODWORD(v11) - (unsigned int)gpGlobals->pEdicts) >> 4;
                vCamPos.x = v11;
                LODWORD(vCamPos.y) = v19;
              }
              v12 = v8->EyeAngles(this: v8);
              AngleVectors(angles: v12, forward: (Vector *)&tr_32[44]);
              vPlayerPos.x = v2.x - *(float *)&v22;
              vPlayerPos.y = v2.y - *((float *)&v22 + 1);
              vPlayerPos.z = v2.z - *(float *)&iCameraIndex;
              VectorNormalize(vec: &vPlayerPos);
              v20 = vPlayerPos;
              v1 = *(Vector *)&tr_32[44];
              VectorNormalize(vec: &v1);
              VectorNormalize(vec: &v20);
              v13 = (float)((float)((float)((float)(v1.y * v20.y) + (float)(v20.x * v1.x)) + (float)(v1.z * v20.z)) + 1.0)
                  * 0.5;
              *(float *)&iClosestPlayer = vPlayerPos.x + *(float *)&iClosestPlayer;
              flClosestPlayerDist = vPlayerPos.y + flClosestPlayerDist;
              *(float *)&i = (float)((float)(1.0 / fsqrt(*(float *)&v19)) * (float)(v13 * v13)) + *(float *)&i;
              *(float *)&nCount = vPlayerPos.z + *(float *)&nCount;
            }
          }
          LODWORD(vDistribution.x) += 4;
          ++v31;
        }
        while ( v31 < *(_DWORD *)(LODWORD(vDistribution.z) + 328) );
        z = vDistribution.z;
        if ( SLODWORD(vCamPos.z) > 0 )
        {
          *(float *)&v31 = flClosestPlayerDist * flClosestPlayerDist;
          v14 = 0;
          *(float *)&v14 = fsqrt(
                             (float)((float)(flClosestPlayerDist * flClosestPlayerDist)
                                   + (float)(*(float *)&nCount * *(float *)&nCount))
                           + (float)(*(float *)&iClosestPlayer * *(float *)&iClosestPlayer));
          v19 = v14;
          *(float *)&i = (float)(*(float *)&v14 / (float)SLODWORD(vCamPos.z)) * *(float *)&i;
        }
      }
      v15 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_rank_camera", a3: 0, a4: 0);
      if ( v15 != nullptr )
      {
        ((void (__thiscall *)(IGameEvent *, const char *, int))v15->SetFloat)(a1: v15, a2: "rank", a3: i);
        v15->SetInt(this: v15, a2: "index", a3: v21);
        v15->SetInt(this: v15, a2: "target", a3: LODWORD(vCamPos.x));
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v15, a3: false);
      }
      ++LODWORD(vDistribution.y);
    }
    while ( SLODWORD(vDistribution.y) < *(_DWORD *)(LODWORD(z) + 68) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015E2B0
// Name: protected: virtual void CHLTVDirector::BuildActivePlayerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::BuildActivePlayerList(CHLTVDirector *this)
{
  int i; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi

  this->m_nNumActivePlayers = 0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr
      && v3->IsAlive(this: v3)
      && (v4->m_afPhysicsFlags.m_Value & 8) == 0
      && CBaseEntity::GetTeamNumber(this: v4) > 1 )
    {
      this->m_pActivePlayers[this->m_nNumActivePlayers++] = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015E330
// Name: protected: virtual void CHLTVDirector::AnalyzePlayers(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CHLTVDirector::AnalyzePlayers(CHLTVDirector *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  IUniformRandomStream *v5; // ecx
  float x; // esi
  float v7; // edi
  int v8; // eax
  int v9; // eax
  __int64 v10; // xmm0_8
  int (__thiscall *v11)(_DWORD, __int64 *); // edx
  const QAngle *v12; // eax
  int v13; // eax
  CBaseEntity *v14; // esi
  float z; // edx
  __int128 v16; // xmm0
  CBaseEntity_vtbl *v17; // edx
  const QAngle *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  signed int m_pPev; // esi
  __int128 v22; // xmm0
  IGameEvent *(__thiscall *CreateEventA)(IGameEventManager2 *, const char *, bool, int *); // eax
  int v24; // eax
  IGameEvent *v25; // esi
  signed int v26; // edi
  _DWORD v28[3]; // [esp+20h] [ebp-F4h] BYREF
  _BYTE tr[92]; // [esp+2Ch] [ebp-E8h] OVERLAPPED
  int v30; // [esp+88h] [ebp-8Ch]
  __int64 v31; // [esp+8Ch] [ebp-88h]
  float v32; // [esp+94h] [ebp-80h]
  Vector vPlayerPos; // [esp+98h] [ebp-7Ch] BYREF
  Vector vCamPos; // [esp+A4h] [ebp-70h] BYREF
  Vector v35; // [esp+B0h] [ebp-64h] BYREF
  Vector v2; // [esp+BCh] [ebp-58h] BYREF
  signed int v37; // [esp+C8h] [ebp-4Ch]
  float v38; // [esp+CCh] [ebp-48h]
  int v39; // [esp+D0h] [ebp-44h]
  __int64 iBestFacingPlayer; // [esp+D4h] [ebp-40h] OVERLAPPED BYREF
  int j; // [esp+DCh] [ebp-38h]
  Vector v1; // [esp+E0h] [ebp-34h]
  int v43; // [esp+ECh] [ebp-28h]
  int nCount; // [esp+F0h] [ebp-24h]
  CBasePlayer *pPlayer; // [esp+F4h] [ebp-20h]
  int i; // [esp+F8h] [ebp-1Ch]
  Vector vDistribution; // [esp+FCh] [ebp-18h]
  int iPlayerIndex; // [esp+108h] [ebp-Ch] BYREF
  void *v49; // [esp+10Ch] [ebp-8h]
  void *retaddr; // [esp+114h] [ebp+0h]

  iPlayerIndex = a2;
  v49 = retaddr;
  ((void (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, int, CBasePlayer *, int, _DWORD, CHLTVDirector *))this->BuildActivePlayerList)(
    a1: a3,
    a2: a4,
    a3: v28[0],
    a4: v28[1],
    a5: v28[2],
    a6: *(_DWORD *)tr,
    a7: *(_DWORD *)&tr[4],
    a8: *(_DWORD *)&tr[8],
    a9: *(_DWORD *)&tr[12],
    a10: *(_DWORD *)&tr[16],
    a11: *(_DWORD *)&tr[20],
    a12: *(_DWORD *)&tr[24],
    a13: *(_DWORD *)&tr[28],
    a14: *(_DWORD *)&tr[32],
    a15: *(_DWORD *)&tr[36],
    a16: *(_DWORD *)&tr[40],
    a17: *(_DWORD *)&tr[44],
    a18: *(_DWORD *)&tr[48],
    a19: *(_DWORD *)&tr[52],
    a20: *(_DWORD *)&tr[56],
    a21: *(_DWORD *)&tr[60],
    a22: *(_DWORD *)&tr[64],
    a23: *(_DWORD *)&tr[68],
    a24: *(_DWORD *)&tr[72],
    a25: *(_DWORD *)&tr[76],
    a26: *(_DWORD *)&tr[80],
    a27: *(_DWORD *)&tr[84],
    a28: *(_DWORD *)&tr[88],
    a29: v30,
    a30: v31,
    a31: HIDWORD(v31),
    a32: LODWORD(v32),
    a33: LODWORD(vPlayerPos.x),
    a34: LODWORD(vPlayerPos.y),
    a35: LODWORD(vPlayerPos.z),
    a36: LODWORD(vCamPos.x),
    a37: LODWORD(vCamPos.y),
    a38: LODWORD(vCamPos.z),
    a39: LODWORD(v35.x),
    a40: LODWORD(v35.y),
    a41: LODWORD(v35.z),
    a42: LODWORD(v2.x),
    a43: LODWORD(v2.y),
    a44: LODWORD(v2.z),
    a45: v37,
    a46: LODWORD(v38),
    a47: v39,
    a48: iBestFacingPlayer,
    a49: HIDWORD(iBestFacingPlayer),
    a50: j,
    a51: LODWORD(v1.x),
    a52: LODWORD(v1.y),
    a53: LODWORD(v1.z),
    a54: v43,
    a55: nCount,
    a56: pPlayer,
    a57: i,
    a58: LODWORD(vDistribution.x),
    a59: this);
  InitRandomOrder(nFields: this->m_nNumActivePlayers, a2: v5);
  v43 = 0;
  if ( this->m_nNumActivePlayers > 0 )
  {
    do
    {
      x = *(float *)&s_RndOrder[v43];
      v7 = *(float *)(LODWORD(vDistribution.y) + 4 * LODWORD(x) + 332);
      v37 = 0;
      v1.y = 0.0;
      v8 = *(_DWORD *)(LODWORD(v7) + 196) >> 11;
      vDistribution.x = x;
      v1.z = v7;
      vDistribution.z = 0.0;
      v38 = 0.0;
      *(float *)&nCount = 0.0;
      *(float *)&pPlayer = 0.0;
      *(float *)&i = 0.0;
      if ( (v8 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(v7), a2: (int)&iPlayerIndex);
      v9 = *(_DWORD *)LODWORD(v7);
      v10 = *(_QWORD *)(LODWORD(v7) + 460);
      vPlayerPos.z = *(float *)(LODWORD(v7) + 468);
      LODWORD(vDistribution.y) = &iBestFacingPlayer;
      v11 = *(int (__thiscall **)(_DWORD, __int64 *))(v9 + 508);
      *(_QWORD *)&vPlayerPos.x = v10;
      v12 = (const QAngle *)v11(a1: LODWORD(v7), a2: &iBestFacingPlayer);
      AngleVectors(angles: v12, forward: (Vector *)LODWORD(vDistribution.z));
      *(float *)&iBestFacingPlayer = *(float *)&iBestFacingPlayer * -1.0;
      *((float *)&iBestFacingPlayer + 1) = *((float *)&iBestFacingPlayer + 1) * -1.0;
      v13 = 0;
      *(float *)&j = *(float *)&j * -1.0;
      v39 = 0;
      if ( *(int *)(LODWORD(vDistribution.y) + 328) > 0 )
      {
        LODWORD(v1.x) = LODWORD(vDistribution.y) + 332;
        while ( 1 )
        {
          if ( LODWORD(x) != v13 )
          {
            v14 = *(CBaseEntity **)LODWORD(v1.x);
            if ( (*(_DWORD *)(*(_DWORD *)LODWORD(v1.x) + 196) & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)LODWORD(v1.x), a2: (int)&iPlayerIndex);
            z = v14->m_vecAbsOrigin.z;
            v31 = *(_QWORD *)&v14->m_vecAbsOrigin.x;
            v32 = z;
            v16 = 0;
            *(float *)&v16 = fsqrt(
                               (float)((float)((float)(*((float *)&v31 + 1) - vPlayerPos.y)
                                             * (float)(*((float *)&v31 + 1) - vPlayerPos.y))
                                     + (float)((float)(z - vPlayerPos.z) * (float)(z - vPlayerPos.z)))
                             + (float)((float)(*(float *)&v31 - vPlayerPos.x) * (float)(*(float *)&v31 - vPlayerPos.x)));
            *(_OWORD *)&tr[76] = v16;
            if ( *(float *)&v16 <= 1024.0 && *(float *)&tr[76] >= 4.0 )
            {
              if ( (v14->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v14, a2: (int)&iPlayerIndex);
              UTIL_TraceLine(
                a1: (const IHandleEntity *)&iPlayerIndex,
                a2: (int)v14,
                vecAbsStart: &vPlayerPos,
                vecAbsEnd: &v14->m_vecAbsOrigin,
                mask: 0x200400Bu,
                ignore: v14,
                collisionGroup: 0,
                ptr: (CGameTrace *)v28);
              if ( *(float *)&tr[32] >= 1.0 )
              {
                v17 = v14->__vftable;
                ++LODWORD(v1.y);
                LODWORD(vDistribution.z) = &v35;
                v18 = v17->EyeAngles(this: v14);
                AngleVectors(angles: v18, forward: (Vector *)LODWORD(vDistribution.z));
                vCamPos = v35;
                *(_QWORD *)&v2.x = iBestFacingPlayer;
                LODWORD(v2.z) = j;
                VectorNormalize(vec: &v2);
                VectorNormalize(vec: &vCamPos);
                v19 = (float)((float)((float)((float)(v2.y * vCamPos.y) + (float)(vCamPos.x * v2.x))
                                    + (float)(v2.z * vCamPos.z))
                            + 1.0)
                    * 0.5;
                v20 = v19 * v19;
                if ( v20 > v38 )
                {
                  m_pPev = (signed int)v14->m_Network.m_pPev;
                  if ( m_pPev != 0 )
                    m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
                  v37 = m_pPev;
                  v38 = v20;
                }
                *(float *)&nCount = v35.x + *(float *)&nCount;
                *(float *)&pPlayer = v35.y + *(float *)&pPlayer;
                vDistribution.z = (float)((float)(1.0 / fsqrt(*(float *)&tr[76])) * v20) + vDistribution.z;
                *(float *)&i = v35.z + *(float *)&i;
              }
            }
            v7 = v1.z;
          }
          LODWORD(v1.x) += 4;
          v13 = v39 + 1;
          v39 = v13;
          if ( v13 >= *(_DWORD *)(LODWORD(vDistribution.y) + 328) )
            break;
          x = vDistribution.x;
        }
        if ( SLODWORD(v1.y) > 0 )
        {
          vDistribution.x = *(float *)&pPlayer * *(float *)&pPlayer;
          v22 = 0;
          *(float *)&v22 = fsqrt(
                             (float)((float)(*(float *)&pPlayer * *(float *)&pPlayer)
                                   + (float)(*(float *)&i * *(float *)&i))
                           + (float)(*(float *)&nCount * *(float *)&nCount));
          *(_OWORD *)&tr[76] = v22;
          vDistribution.z = (float)(*(float *)&v22 / (float)SLODWORD(v1.y)) * vDistribution.z;
        }
      }
      CreateEventA = gameeventmanager->CreateEventA;
      vDistribution.z = 0.0;
      v24 = ((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD))CreateEventA)(
              a1: gameeventmanager,
              a2: "hltv_rank_entity",
              a3: 0);
      v25 = (IGameEvent *)v24;
      if ( v24 != 0 )
      {
        v26 = *(_DWORD *)(LODWORD(v7) + 24);
        if ( v26 != 0 )
          v26 = (signed int)(v26 - (unsigned int)gpGlobals->pEdicts) >> 4;
        (*(void (__thiscall **)(int, const char *, signed int))(*(_DWORD *)v24 + 44))(a1: v24, a2: "index", a3: v26);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v25->SetFloat)(
          a1: v25,
          a2: "rank",
          a3: LODWORD(vDistribution.z));
        v25->SetInt(this: v25, a2: "target", a3: v37);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v25, a3: false);
      }
      ++v43;
    }
    while ( v43 < *(_DWORD *)(LODWORD(vDistribution.y) + 328) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015F240
// Name: protected: virtual void CHLTVDirector::UpdateSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::UpdateSettings(CHLTVDirector *this)
{
  float m_fValue; // xmm0_4
  int tickcount; // edi
  CBasePlayer *v4; // eax

  m_fValue = tv_delay.m_pParent->m_Value.m_fValue;
  this->m_fDelay = m_fValue;
  tickcount = gpGlobals->tickcount;
  if ( m_fValue >= 10.0 )
    tickcount -= (int)(float)((float)(m_fValue / gpGlobals->interval_per_tick) + 0.5);
  else
    this->m_fDelay = 0.0;
  if ( this->m_nBroadcastTick == 0 && tickcount > 0 )
    this->m_nNextShotTick = 0;
  if ( this->m_iCameraManIndex > 0 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: this->m_iCameraManIndex);
    if ( v4 == nullptr || CBaseEntity::GetTeamNumber(this: v4) != 1 )
      CHLTVDirector::SetCameraMan(this, iPlayerIndex: nullptr);
  }
  this->m_nBroadcastTick = tickcount < 0 ? 0 : tickcount;
}

//------------------------------------------------------------------------------
// Address: 0x10160170
// Name: protected: int CHLTVDirector::FindFirstEvent(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHLTVDirector::FindFirstEvent(CHLTVDirector *this, int tick)
{
  int result; // eax

  for ( result = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_EventHistory);
        (unsigned __int16)result != 0xFFFF
     && this->m_EventHistory.m_Elements.m_pMemory[(unsigned __int16)result].m_Data.m_Tick < tick;
        result = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                     this: &this->m_EventHistory,
                                     i: result) )
  {
    ;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101601E0
// Name: protected: virtual void CHLTVDirector::FinishCameraManShot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::FinishCameraManShot(CHLTVDirector *this)
{
  int FirstEvent; // ebx
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // edx
  int p_m_Data; // edi
  IGameEvent *m_Event; // ecx
  const char *v6; // eax
  IGameEvent *v7; // edi

  FirstEvent = CHLTVDirector::FindFirstEvent(this, tick: this->m_nBroadcastTick);
  if ( FirstEvent == 0xFFFF )
  {
    this->m_nNextShotTick = this->m_nBroadcastTick + 1;
  }
  else
  {
    this->m_nNextShotTick = this->m_nBroadcastTick + (int)(float)((float)(4.0 / gpGlobals->interval_per_tick) + 0.5);
    do
    {
      m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
      p_m_Data = (int)&m_pMemory[(unsigned __int16)FirstEvent].m_Data;
      if ( *(_DWORD *)p_m_Data >= this->m_nNextShotTick )
        break;
      m_Event = m_pMemory[(unsigned __int16)FirstEvent].m_Data.m_Event;
      v6 = m_Event->GetName(this: m_Event);
      if ( _V_strcmp(s1: v6, s2: "hltv_cameraman") == 0
        && (*(int (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(p_m_Data + 8) + 24))(
             a1: *(_DWORD *)(p_m_Data + 8),
             a2: "index",
             a3: 0) == 0 )
      {
        this->m_nNextShotTick = *(_DWORD *)p_m_Data + 1;
        this->m_iCameraMan = 0;
        return;
      }
      FirstEvent = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                       this: &this->m_EventHistory,
                                       i: FirstEvent);
    }
    while ( FirstEvent != 0xFFFF );
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_cameraman", a3: 1, a4: 0);
    if ( v7 != nullptr )
    {
      v7->SetInt(this: v7, a2: "index", a3: this->m_iCameraMan);
      this->m_pHLTVServer->BroadcastEvent(this: this->m_pHLTVServer, a2: v7);
      gameeventmanager->FreeEvent(this: gameeventmanager, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101602F0
// Name: protected: virtual bool CHLTVDirector::StartCameraManShot(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVDirector::StartCameraManShot(CHLTVDirector *this)
{
  int i; // ebx
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // edx
  int p_m_Data; // edi
  IGameEvent *m_Event; // ecx
  const char *v6; // eax
  int v8; // eax
  IHLTVServer *m_pHLTVServer; // ecx

  for ( i = CHLTVDirector::FindFirstEvent(this, tick: this->m_nNextShotTick);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_EventHistory,
                                i) )
  {
    m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
    p_m_Data = (int)&m_pMemory[(unsigned __int16)i].m_Data;
    if ( *(_DWORD *)p_m_Data > this->m_nBroadcastTick )
      break;
    m_Event = m_pMemory[(unsigned __int16)i].m_Data.m_Event;
    v6 = m_Event->GetName(this: m_Event);
    if ( _V_strcmp(s1: v6, s2: "hltv_cameraman") == 0
      && (*(int (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(p_m_Data + 8) + 24))(
           a1: *(_DWORD *)(p_m_Data + 8),
           a2: "index",
           a3: 0) > 0 )
    {
      v8 = (*(int (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(p_m_Data + 8) + 24))(
             a1: *(_DWORD *)(p_m_Data + 8),
             a2: "index",
             a3: 0);
      this->m_nNextShotTick = this->m_nBroadcastTick + 1;
      m_pHLTVServer = this->m_pHLTVServer;
      this->m_iCameraMan = v8;
      this->m_iPVSEntity = v8;
      m_pHLTVServer->BroadcastEvent(this: m_pHLTVServer, a2: *(IGameEvent **)(p_m_Data + 8));
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101603B0
// Name: protected: virtual class CHLTVGameEvent __near * CHLTVDirector::FindBestGameEvent(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVGameEvent *__thiscall CHLTVDirector::FindBestGameEvent(CHLTVDirector *this)
{
  int FirstEvent; // eax
  int i; // ebx
  CGlobalVars *v4; // ecx
  int v5; // edi
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // ecx
  bool v7; // cc
  int p_m_Data; // ecx
  int v9; // ecx
  int bestEvent[4]; // [esp+Ch] [ebp-20h] BYREF
  int bestEventPrio[4]; // [esp+1Ch] [ebp-10h] BYREF

  _V_memset(dest: bestEvent, fill: 0, count: 16);
  _V_memset(dest: bestEventPrio, fill: 0, count: 16);
  FirstEvent = CHLTVDirector::FindFirstEvent(this, tick: this->m_nBroadcastTick);
  for ( i = 0; i < 4; ++i )
  {
    v4 = gpGlobals;
    bestEventPrio[i] = 0;
    bestEvent[i] = 0;
    v5 = this->m_nBroadcastTick
       + (int)(float)((float)((float)((float)((float)i + 1.0) * 2.0) / v4->interval_per_tick) + 0.5);
    if ( v5 > this->m_nNextShotTick )
      break;
    if ( FirstEvent != 0xFFFF )
    {
      do
      {
        m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
        v7 = m_pMemory[(unsigned __int16)FirstEvent].m_Data.m_Tick <= v5;
        p_m_Data = (int)&m_pMemory[(unsigned __int16)FirstEvent].m_Data;
        if ( !v7 )
          break;
        v9 = *(_DWORD *)(p_m_Data + 4);
        if ( v9 > bestEventPrio[i] )
        {
          bestEvent[i] = FirstEvent;
          bestEventPrio[i] = v9;
        }
        FirstEvent = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                         this: &this->m_EventHistory,
                                         i: FirstEvent);
      }
      while ( (unsigned __int16)FirstEvent != 0xFFFF );
    }
  }
  if ( bestEventPrio[0] == 0 && bestEventPrio[1] == 0 )
  {
    if ( bestEventPrio[2] == 0 )
      return nullptr;
LABEL_14:
    if ( bestEventPrio[1] >= bestEventPrio[2] && bestEventPrio[1] >= bestEventPrio[3] )
      return &this->m_EventHistory.m_Elements.m_pMemory[LOWORD(bestEvent[1])].m_Data;
    if ( bestEventPrio[0] <= bestEventPrio[1] )
      goto LABEL_20;
    goto LABEL_18;
  }
  if ( bestEventPrio[1] >= bestEventPrio[0] )
    goto LABEL_14;
LABEL_18:
  if ( bestEventPrio[0] > bestEventPrio[2] )
    return &this->m_EventHistory.m_Elements.m_pMemory[LOWORD(bestEvent[0])].m_Data;
LABEL_20:
  if ( bestEventPrio[2] > bestEventPrio[3] )
    return &this->m_EventHistory.m_Elements.m_pMemory[LOWORD(bestEvent[2])].m_Data;
  if ( bestEvent[0] == 0 )
    return nullptr;
  return &this->m_EventHistory.m_Elements.m_pMemory[LOWORD(bestEvent[0])].m_Data;
}

//------------------------------------------------------------------------------
// Address: 0x101607B0
// Name: protected: virtual void CHLTVDirector::StartBestPlayerCameraShot(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVDirector::StartBestPlayerCameraShot(CHLTVDirector *this@<ecx>, int a2@<edi>)
{
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // eax
  IUniformRandomStream *m_Tick; // ecx
  int p_m_Data; // esi
  IGameEvent *m_Event; // ecx
  const char *v7; // eax
  int v8; // edi
  double v9; // st7
  int v10; // ecx
  int (__thiscall *v11)(int, const char *, _DWORD); // eax
  int v12; // esi
  double v13; // st6
  int v14; // eax
  int v15; // [esp+1Ch] [ebp-120h]
  float flPlayerRanking[64]; // [esp+28h] [ebp-114h] BYREF
  float v17; // [esp+128h] [ebp-14h]
  float flBestRank; // [esp+12Ch] [ebp-10h]
  int iBestTarget; // [esp+130h] [ebp-Ch]
  int iBestCamera; // [esp+134h] [ebp-8h]
  int index; // [esp+138h] [ebp-4h]

  memset(dst: (int)flPlayerRanking, value: nullptr, count: sizeof(flPlayerRanking));
  index = CHLTVDirector::FindFirstEvent(this, tick: this->m_nBroadcastTick);
  flBestRank = -1.0;
  iBestCamera = -1;
  iBestTarget = -1;
  if ( index == 0xFFFF )
    goto LABEL_13;
  v15 = a2;
  do
  {
    m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
    m_Tick = (IUniformRandomStream *)m_pMemory[(unsigned __int16)index].m_Data.m_Tick;
    p_m_Data = (int)&m_pMemory[(unsigned __int16)index].m_Data;
    if ( (int)m_Tick >= this->m_nNextShotTick )
      break;
    m_Event = m_pMemory[(unsigned __int16)index].m_Data.m_Event;
    v7 = m_Event->GetName(this: m_Event);
    if ( _V_strcmp(s1: v7, s2: "hltv_rank_entity") == 0 )
    {
      v8 = (*(int (__thiscall **)(_DWORD, const char *, _DWORD, int))(**(_DWORD **)(p_m_Data + 8) + 24))(
             a1: *(_DWORD *)(p_m_Data + 8),
             a2: "index",
             a3: 0,
             a4: v15);
      if ( v8 < 64 )
      {
        v9 = ((double (__cdecl *)(const char *, _DWORD))*(_DWORD *)(**(_DWORD **)(p_m_Data + 8) + 32))(
               a1: "rank",
               a2: 0)
           + flPlayerRanking[v8];
        v17 = v9;
        flPlayerRanking[v8] = v9;
        if ( v9 > flBestRank )
        {
          v10 = *(_DWORD *)(p_m_Data + 8);
          v11 = *(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v10 + 24);
          iBestCamera = v8;
          flBestRank = v17;
          iBestTarget = v11(a1: v10, a2: "target", a3: 0);
        }
      }
    }
    index = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                this: &this->m_EventHistory,
                                i: index);
  }
  while ( index != 0xFFFF );
  v12 = iBestCamera;
  if ( iBestCamera == -1 )
  {
LABEL_13:
    this->StartBestFixedCameraShot(this, a2: true);
  }
  else
  {
    v13 = _RandomFloat(this: m_Tick, a2: 0.0, a3: 1.0);
    v14 = 20;
    if ( v13 <= 0.5 )
      v14 = -20;
    this->StartChaseCameraShot(this, a2: v12, a3: iBestTarget, a4: 112, a5: 20, a6: v14, a7: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160940
// Name: protected: virtual void CHLTVDirector::StartBestFixedCameraShot(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::StartBestFixedCameraShot(CHLTVDirector *this, bool bForce)
{
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // eax
  int p_m_Data; // esi
  IGameEvent *m_Event; // ecx
  const char *v6; // eax
  int v7; // edi
  double v8; // st7
  int v9; // ecx
  int (__thiscall *v10)(int, const char *, _DWORD); // eax
  float flCameraRanking[64]; // [esp+18h] [ebp-114h] BYREF
  float v12; // [esp+118h] [ebp-14h]
  int iBestTarget; // [esp+11Ch] [ebp-10h]
  int iBestCamera; // [esp+120h] [ebp-Ch]
  float flBestRank; // [esp+124h] [ebp-8h]
  int index; // [esp+128h] [ebp-4h]

  if ( this->m_nNumFixedCameras > 0 )
  {
    memset(dst: (int)flCameraRanking, value: nullptr, count: sizeof(flCameraRanking));
    index = CHLTVDirector::FindFirstEvent(this, tick: this->m_nBroadcastTick);
    flBestRank = -1.0;
    iBestCamera = -1;
    for ( iBestTarget = -1;
          index != 0xFFFF;
          index = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                      this: &this->m_EventHistory,
                                      i: index) )
    {
      m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
      p_m_Data = (int)&m_pMemory[(unsigned __int16)index].m_Data;
      if ( *(_DWORD *)p_m_Data >= this->m_nNextShotTick )
        break;
      m_Event = m_pMemory[(unsigned __int16)index].m_Data.m_Event;
      v6 = m_Event->GetName(this: m_Event);
      if ( _V_strcmp(s1: v6, s2: "hltv_rank_camera") == 0 )
      {
        v7 = (*(int (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(p_m_Data + 8) + 24))(
               a1: *(_DWORD *)(p_m_Data + 8),
               a2: "index",
               a3: 0);
        v8 = ((double (__thiscall *)(_DWORD, const char *, _DWORD))*(_DWORD *)(**(_DWORD **)(p_m_Data + 8) + 32))(
               a1: *(_DWORD *)(p_m_Data + 8),
               a2: "rank",
               a3: 0)
           + flCameraRanking[v7];
        v12 = v8;
        flCameraRanking[v7] = v8;
        if ( v8 > flBestRank )
        {
          v9 = *(_DWORD *)(p_m_Data + 8);
          v10 = *(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v9 + 24);
          iBestCamera = v7;
          flBestRank = v12;
          iBestTarget = v10(a1: v9, a2: "target", a3: 0);
        }
      }
    }
    if ( bForce || flBestRank != 0.0 )
    {
      if ( iBestCamera != -1 )
        this->StartFixedCameraShot(this, a2: iBestCamera, a3: iBestTarget);
    }
    else
    {
      this->StartBestPlayerCameraShot(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160BA0
// Name: public: CHLTVDirector::CHLTVDirector(void)
// Source: json
//------------------------------------------------------------------------------
CHLTVDirector *__thiscall CHLTVDirector::CHLTVDirector(CHLTVDirector *this)
{
  CHLTVDirector *result; // eax

  result = this;
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CBaseGameSystemPerFrame_vtbl *)&CBaseGameSystemPerFrame::`vftable';
  this->IHLTVDirector::__vftable = (IHLTVDirector_vtbl *)&IHLTVDirector::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CHLTVDirector_vtbl *)&CHLTVDirector::`vftable'{for `CGameEventListener'};
  this->CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CBaseGameSystemPerFrame_vtbl *)&CHLTVDirector::`vftable'{for `CBaseGameSystemPerFrame'};
  this->IHLTVDirector::__vftable = (IHLTVDirector_vtbl *)&CHLTVDirector::`vftable'{for `IHLTVDirector'};
  this->m_EventHistory.m_LessFunc = nullptr;
  this->m_EventHistory.m_Elements.m_pMemory = nullptr;
  this->m_EventHistory.m_Elements.m_nAllocationCount = 0;
  this->m_EventHistory.m_Elements.m_nGrowSize = 0;
  this->m_EventHistory.m_Root = -1;
  this->m_EventHistory.m_NumElements = 0;
  this->m_EventHistory.m_FirstFree = -1;
  this->m_EventHistory.m_LastAlloc.index = -1;
  this->m_EventHistory.m_pElements = this->m_EventHistory.m_Elements.m_pMemory;
  this->m_iPVSEntity = 0;
  this->m_fDelay = 30.0;
  this->m_iLastPlayer = 1;
  this->m_pHLTVServer = nullptr;
  this->m_pHLTVClient = nullptr;
  this->m_iCameraMan = 0;
  this->m_nNumFixedCameras = 0;
  if ( this->m_EventHistory.m_LessFunc == nullptr )
    this->m_EventHistory.m_LessFunc = (bool (__cdecl *)(const CHLTVGameEvent *, const CHLTVGameEvent *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
  this->m_nNextAnalyzeTick = 0;
  this->m_iCameraManIndex = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10160C60
// Name: public: virtual char const __near * CHLTVDirector::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHLTVDirector::Name(CHLTVDirector *this)
{
  return "CHLTVDirector";
}

//------------------------------------------------------------------------------
// Address: 0x10160C70
// Name: public: virtual char __near * CHLTVDirector::GetFixedCameraEntityName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHLTVDirector::GetFixedCameraEntityName(CHLTVDirector *this)
{
  return "point_viewcontrol";
}

//------------------------------------------------------------------------------
// Address: 0x10160C90
// Name: public: virtual CHLTVDirector::~CHLTVDirector(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::~CHLTVDirector(CHLTVDirector *this)
{
  bool v2; // zf

  this->CGameEventListener::IGameEventListener2::__vftable = (CHLTVDirector_vtbl *)&CHLTVDirector::`vftable'{for `CGameEventListener'};
  this->CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CBaseGameSystemPerFrame_vtbl *)&CHLTVDirector::`vftable'{for `CBaseGameSystemPerFrame'};
  this->IHLTVDirector::__vftable = (IHLTVDirector_vtbl *)&CHLTVDirector::`vftable'{for `IHLTVDirector'};
  CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::~CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>(this: &this->m_EventHistory);
  this->IHLTVDirector::__vftable = (IHLTVDirector_vtbl *)&IHLTVDirector::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &this->CBaseGameSystemPerFrame);
  v2 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CHLTVDirector_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CHLTVDirector_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10160D00
// Name: public: virtual void CHLTVDirector::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::FireGameEvent(CHLTVDirector *this, IGameEvent *event)
{
  CHLTVGameEvent gameevent; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_pHLTVServer != nullptr )
  {
    gameevent.m_Event = gameeventmanager->DuplicateEvent(this: gameeventmanager, a2: event);
    gameevent.m_Priority = event->GetInt(this: event, a2: "priority", a3: -1);
    gameevent.m_Tick = gpGlobals->tickcount;
    CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::Insert(
      this: &this->m_EventHistory,
      a2: (const char *)this,
      insert: &gameevent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160D60
// Name: protected: void CHLTVDirector::RemoveEventsFromHistory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::RemoveEventsFromHistory(CHLTVDirector *this, int tick)
{
  CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl*)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short> > *p_m_EventHistory; // ebx
  int Inorder; // esi
  int v4; // edi
  unsigned __int16 v5; // ax
  CHLTVGameEvent *dc; // [esp+8h] [ebp-8h]

  p_m_EventHistory = &this->m_EventHistory;
  Inorder = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_EventHistory);
  if ( Inorder != 0xFFFF )
  {
    do
    {
      v4 = (unsigned __int16)Inorder;
      dc = &this->m_EventHistory.m_Elements.m_pMemory[v4].m_Data;
      if ( dc->m_Tick < tick || tick == -1 )
      {
        gameeventmanager->FreeEvent(
          this: gameeventmanager,
          a2: this->m_EventHistory.m_Elements.m_pMemory[v4].m_Data.m_Event);
        dc->m_Event = nullptr;
        if ( (_WORD)Inorder != 0xFFFF )
        {
          CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::Unlink(
            this: p_m_EventHistory,
            elem: Inorder);
          p_m_EventHistory->m_Elements.m_pMemory[v4].m_Left = Inorder;
          p_m_EventHistory->m_Elements.m_pMemory[v4].m_Right = p_m_EventHistory->m_FirstFree;
          --p_m_EventHistory->m_NumElements;
          p_m_EventHistory->m_FirstFree = Inorder;
        }
        v5 = CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::FirstInorder(this: p_m_EventHistory);
      }
      else
      {
        v5 = CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
               this: p_m_EventHistory,
               i: Inorder);
      }
      LOWORD(Inorder) = v5;
    }
    while ( v5 != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160E30
// Name: protected: virtual void CHLTVDirector::StartInstantBroadcastShot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::StartInstantBroadcastShot(CHLTVDirector *this)
{
  bool v2; // cc
  IGameEvent *v3; // edi

  v2 = this->m_iCameraManIndex <= 0;
  this->m_nNextShotTick = this->m_nBroadcastTick + (int)(float)((float)(8.0 / gpGlobals->interval_per_tick) + 0.5);
  if ( v2 )
  {
    CHLTVDirector::RemoveEventsFromHistory(this, tick: -1);
    this->AnalyzePlayers(this);
    this->AnalyzeCameras(this);
    this->StartRandomShot(this);
  }
  else
  {
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_cameraman", a3: 1, a4: 0);
    if ( v3 != nullptr )
    {
      v3->SetInt(this: v3, a2: "index", a3: this->m_iCameraManIndex);
      this->m_pHLTVServer->BroadcastEvent(this: this->m_pHLTVServer, a2: v3);
      gameeventmanager->FreeEvent(this: gameeventmanager, a2: v3);
      this->m_iPVSEntity = this->m_iCameraManIndex;
      this->m_nNextShotTick = this->m_nBroadcastTick + (int)(float)((float)(4.0 / gpGlobals->interval_per_tick) + 0.5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160F10
// Name: protected: virtual void CHLTVDirector::StartNewShot(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVDirector::StartNewShot(CHLTVDirector *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  CHLTVDirector_vtbl *v4; // eax
  int m_nBroadcastTick; // eax
  IGameEvent *v6; // edi
  int i; // ebx
  UtlRBTreeNode_t<CHLTVGameEvent,unsigned short> *m_pMemory; // ecx
  int p_m_Data; // edi
  IGameEvent *m_Event; // ecx
  const char *v11; // eax
  CHLTVGameEvent *v12; // eax
  CHLTVDirector_vtbl *v13; // edx

  v3 = gpGlobals->tickcount - (int)(float)((float)(120.0 / gpGlobals->interval_per_tick) + 0.5);
  CHLTVDirector::RemoveEventsFromHistory(this, tick: v3 < 0 ? 0 : v3);
  v4 = this->CGameEventListener::IGameEventListener2::__vftable;
  if ( this->m_fDelay >= 10.0 )
  {
    if ( this->m_iCameraMan <= 0 )
    {
      if ( ((unsigned __int8 (__fastcall *)(CHLTVDirector *))v4->StartCameraManShot)(a1: this) == 0 )
      {
        m_nBroadcastTick = this->m_nBroadcastTick;
        this->m_nNextShotTick = m_nBroadcastTick + (int)(float)((float)(8.0 / gpGlobals->interval_per_tick) + 0.5);
        if ( m_nBroadcastTick > 0 )
        {
          for ( i = CHLTVDirector::FindFirstEvent(this, tick: m_nBroadcastTick);
                i != 0xFFFF;
                i = (unsigned __int16)CUtlRBTree<CHLTVGameEvent,unsigned short,bool (__cdecl *)(CHLTVGameEvent const &,CHLTVGameEvent const &),CUtlMemory<UtlRBTreeNode_t<CHLTVGameEvent,unsigned short>,unsigned short>>::NextInorder(
                                        this: &this->m_EventHistory,
                                        i) )
          {
            m_pMemory = this->m_EventHistory.m_Elements.m_pMemory;
            p_m_Data = (int)&m_pMemory[(unsigned __int16)i].m_Data;
            if ( *(_DWORD *)p_m_Data >= this->m_nNextShotTick )
              break;
            m_Event = m_pMemory[(unsigned __int16)i].m_Data.m_Event;
            v11 = m_Event->GetName(this: m_Event);
            if ( _V_strcmp(s1: v11, s2: "hltv_cameraman") == 0
              && (*(int (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(p_m_Data + 8) + 24))(
                   a1: *(_DWORD *)(p_m_Data + 8),
                   a2: "index",
                   a3: 0) > 0 )
            {
              this->m_nNextShotTick = *(_DWORD *)p_m_Data;
              break;
            }
          }
          if ( (float)((float)(this->m_nNextShotTick - this->m_nBroadcastTick) * gpGlobals->interval_per_tick) >= 4.0 )
          {
            v12 = this->FindBestGameEvent(this);
            v13 = this->CGameEventListener::IGameEventListener2::__vftable;
            if ( v12 != nullptr )
              v13->CreateShotFromEvent(this, a2: v12);
            else
              v13->StartRandomShot(this);
          }
        }
        else
        {
          v6 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, int, _DWORD, int))gameeventmanager->CreateEventA)(
                               a1: gameeventmanager,
                               a2: "hltv_message",
                               a3: 1,
                               a4: 0,
                               a5: a2);
          if ( v6 != nullptr )
          {
            v6->SetString(this: v6, a2: "text", a3: "Please wait for broadcast to start ...");
            this->m_pHLTVServer->BroadcastEvent(this: this->m_pHLTVServer, a2: v6);
            gameeventmanager->FreeEvent(this: gameeventmanager, a2: v6);
          }
          this->StartBestFixedCameraShot(this, a2: true);
        }
      }
    }
    else
    {
      ((void (__fastcall *)(CHLTVDirector *))v4->FinishCameraManShot)(a1: this);
    }
  }
  else
  {
    v4->StartInstantBroadcastShot(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101610D0
// Name: public: virtual void CHLTVDirector::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::Shutdown(CHLTVDirector *this)
{
  CHLTVDirector::RemoveEventsFromHistory(this: (CHLTVDirector *)((char *)this - 12), tick: -1);
}

//------------------------------------------------------------------------------
// Address: 0x101610E0
// Name: public: virtual void CHLTVDirector::SetHLTVServer(class IHLTVServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHLTVDirector::SetHLTVServer(CHLTVDirector *this@<ecx>, int a2@<ebx>, IHLTVServer *hltv)
{
  IGameEventListener2 *v4; // esi
  int v5; // eax
  CBasePlayer *v6; // eax
  const char *v7; // [esp+0h] [ebp-8h]

  v4 = (CHLTVDirector *)((char *)this - 16);
  CHLTVDirector::RemoveEventsFromHistory(this: (CHLTVDirector *)((char *)this - 16), tick: -1);
  if ( hltv != nullptr )
  {
    v5 = ((int (__thiscall *)(IHLTVServer *, int))hltv->GetHLTVSlot)(a1: hltv, a2);
    v6 = UTIL_PlayerByIndex(playerIndex: v5 + 1);
    LODWORD(this->m_vPVSOrigin.x) = v6;
    if ( v6 != nullptr && v6->pl.hltv )
    {
      this->m_nDebugID = (int)hltv;
    }
    else
    {
      this->m_nDebugID = 0;
      _Error(this: (ISceneTokenProcessor *)&stru_104853C0, a2: v7);
    }
    LOBYTE(v4[2].__vftable) = 1;
    ((void (__thiscall *)(IGameEventManager2 *, IGameEventListener2 *, const char *))gameeventmanager->AddListener)(
      a1: gameeventmanager,
      a2: v4,
      a3: "player_hurt");
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "player_death", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "round_end", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "round_start", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hltv_cameraman", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hltv_rank_entity", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hltv_rank_camera", a4: true);
  }
  else
  {
    this->m_nDebugID = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161200
// Name: public: virtual void CHLTVDirector::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVDirector::LevelInitPostEntity(CHLTVDirector *this)
{
  CHLTVDirector::BuildCameraList(this: (CHLTVDirector *)((char *)this - 12));
  this->m_fDelay = 0.0;
  this->m_nBroadcastTick = 0;
  this->m_iPVSEntity = 0;
  this->m_pHLTVServer = nullptr;
  this->m_vPVSOrigin.z = 0.0;
  this->m_pHLTVClient = nullptr;
  this->m_pActivePlayers[61] = nullptr;
  CHLTVDirector::RemoveEventsFromHistory(this: (CHLTVDirector *)((char *)this - 12), tick: -1);
}
