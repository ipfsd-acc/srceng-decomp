// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/eventlog.cpp
// Functions: 10
// ============================================================

#include "game\server\eventlog.h"

//------------------------------------------------------------------------------
// Address: 0x100D57D0
// Name: protected: virtual bool CEventLog::PrintGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEventLog::PrintGameEvent(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10121EC0
// Name: public: char const __near * CEventLog::FormatPlayer(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEventLog::FormatPlayer(CEventLog *this, CBaseEntity *ent)
{
  char *v2; // esi

  v2 = s_buffer[s_index++];
  if ( s_index >= 4 )
    s_index = 0;
  this->FormatPlayer(this, a2: ent, a3: v2, a4: 256);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10121F10
// Name: public: virtual void CEventLog::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventLog::FireGameEvent(CEventLog *this, IGameEvent *event)
{
  if ( g_bIsLogging )
    this->PrintEvent(this, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10121F30
// Name: protected: virtual bool CEventLog::PrintEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEventLog::PrintEvent(CEventLog *this, IGameEvent *event)
{
  const char *v3; // edi
  bool v5; // zf
  CEventLog_vtbl *v6; // eax

  v3 = event->GetName(this: event);
  if ( V_strncmp(s1: v3, s2: "server_", count: 7) == 0 )
    return true;
  if ( V_strncmp(s1: v3, s2: "player_", count: 7) == 0 )
    return this->PrintPlayerEvent(this, a2: event);
  if ( V_strncmp(s1: v3, s2: "team_", count: 5) == 0 )
    return this->PrintTeamEvent(this, a2: event);
  v5 = V_strncmp(s1: v3, s2: "game_", count: 5) == 0;
  v6 = this->CGameEventListener::IGameEventListener2::__vftable;
  if ( v5 )
    return v6->PrintGameEvent(this, a2: event);
  else
    return v6->PrintOtherEvent(this, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x10121FF0
// Name: public: virtual char const __near * CBaseGameSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseGameSystem::Name(CBaseGameSystemPerFrame *this)
{
  return "unnamed";
}

//------------------------------------------------------------------------------
// Address: 0x10122000
// Name: public: virtual bool CEventLog::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEventLog::Init(CEventLog *this)
{
  IGameEventListener2 *v1; // esi

  v1 = (IGameEventListener2 *)this - 3;
  *(&this->m_bRegisteredForEvents - 12) = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: (CEventLog *)((char *)this - 12),
    a3: "player_changename",
    a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_activate", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_death", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_team", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_disconnect", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_connect", a4: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101220A0
// Name: public: CEventLog::CEventLog(void)
// Source: json
//------------------------------------------------------------------------------
CEventLog *__thiscall CEventLog::CEventLog(CEventLog *this)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CBaseGameSystem::IGameSystem::__vftable = (CBaseGameSystem_vtbl *)&CBaseGameSystem::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CEventLog_vtbl *)&CEventLog::`vftable'{for `CGameEventListener'};
  this->CBaseGameSystem::IGameSystem::__vftable = (CBaseGameSystem_vtbl *)&CEventLog::`vftable'{for `CBaseGameSystem'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101220E0
// Name: public: virtual CEventLog::~CEventLog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventLog::~CEventLog(CEventLog *this)
{
  CBaseGameSystem *v2; // ecx
  bool v3; // zf

  v2 = &this->CBaseGameSystem;
  this->CGameEventListener::IGameEventListener2::__vftable = (CEventLog_vtbl *)&CEventLog::`vftable'{for `CGameEventListener'};
  v2->__vftable = (CBaseGameSystem_vtbl *)&CEventLog::`vftable'{for `CBaseGameSystem'};
  IGameSystem::~IGameSystem(this: v2);
  v3 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CEventLog_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CEventLog_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10122130
// Name: public: virtual void CEventLog::FormatPlayer(class CBaseEntity __near *,char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEventLog::FormatPlayer(CEventLog *this, CBasePlayer *ent, char *str, int len)
{
  CBasePlayer *v4; // esi
  int v5; // ebx
  const char *v6; // edi
  CTeam *Team; // eax
  CBaseCombatCharacter *v8; // eax
  int v9; // eax
  const char *networkIDString; // [esp+0h] [ebp-Ch]
  const char *teamName; // [esp+4h] [ebp-8h]
  int areaID; // [esp+8h] [ebp-4h]

  if ( str != nullptr && len > 0 )
  {
    v4 = ent;
    if ( ent == nullptr || !ent->IsPlayer(this: ent) )
      v4 = nullptr;
    v5 = 0;
    v6 = "Unknown";
    networkIDString = locale;
    teamName = locale;
    areaID = 0;
    if ( v4 != nullptr )
    {
      v6 = v4->GetPlayerName(this: v4);
      v5 = engine->GetPlayerUserId(this: engine, a2: v4->m_Network.m_pPev);
      networkIDString = CBasePlayer::GetNetworkIDString(this: v4);
      Team = CBaseEntity::GetTeam(this: v4);
      if ( Team != nullptr )
        teamName = Team->GetName(this: Team);
    }
    if ( ent != nullptr && ent->MyCombatCharacterPointer(this: ent) != nullptr )
    {
      v8 = ent->MyCombatCharacterPointer(this: ent);
      v9 = (int)v8->GetLastKnownArea(this: v8);
      if ( v9 != 0 )
        areaID = *(_DWORD *)(v9 + 136);
    }
    V_snprintf(
      pDest: str,
      maxLen: len,
      pFormat: "\"%s<%i><%s><%s><Area %d>\"",
      v6,
      v5,
      networkIDString,
      teamName,
      areaID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122230
// Name: protected: virtual bool CEventLog::PrintPlayerEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEventLog::PrintPlayerEvent(CEventLog *this, IGameEvent *event)
{
  const char *v3; // edi
  int v4; // ebx
  int v5; // eax
  const char *v6; // edi
  const char *v7; // eax
  int v9; // eax
  const char *v10; // edi
  const char *v11; // esi
  CBasePlayer *v12; // eax
  CTeam *Team; // eax
  const char *v14; // eax
  CBasePlayer *v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // esi
  CTeam *GlobalTeam; // esi
  int v20; // ebx
  const char *v21; // edi
  const char *v22; // esi
  const char *v23; // eax
  int v24; // eax
  CBasePlayer *v25; // esi
  CTeam *v26; // ebx
  const char *v27; // eax
  const char *pszValue; // ecx
  const char *v29; // eax
  const char *v30; // eax
  CTeam *v31; // eax
  const char *v32; // ebx
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  int v39; // eax
  const char *NetworkIDString; // eax
  const char *v41; // eax
  int v42; // eax
  const char *v43; // esi
  CTeam *v44; // eax
  const char *v45; // eax
  const char *v46; // eax
  int v47; // [esp-1Ch] [ebp-34h]
  const char *v48; // [esp-18h] [ebp-30h]
  const char *v49; // [esp-14h] [ebp-2Ch]
  int v50; // [esp-10h] [ebp-28h]
  int v51; // [esp-10h] [ebp-28h]
  const char *v52; // [esp-10h] [ebp-28h]
  const char *v53; // [esp-Ch] [ebp-24h]
  int v54; // [esp-Ch] [ebp-24h]
  int v55; // [esp-Ch] [ebp-24h]
  const char *v56; // [esp-8h] [ebp-20h]
  const char *v57; // [esp-8h] [ebp-20h]
  const char *v58; // [esp-8h] [ebp-20h]
  const char *v59; // [esp-8h] [ebp-20h]
  int v60; // [esp-8h] [ebp-20h]
  const char *v61; // [esp-8h] [ebp-20h]
  const char *v62; // [esp-4h] [ebp-1Ch]
  const char *v63; // [esp-4h] [ebp-1Ch]
  const char *v64; // [esp-4h] [ebp-1Ch]
  const char *v65; // [esp-4h] [ebp-1Ch]
  const char *v66; // [esp-4h] [ebp-1Ch]
  const char *v67; // [esp-4h] [ebp-1Ch]
  int attackerid; // [esp+Ch] [ebp-Ch]
  CTeam *attackerTeam; // [esp+10h] [ebp-8h]
  const char *playerName; // [esp+14h] [ebp-4h]
  const char *playerNamea; // [esp+14h] [ebp-4h]
  const char *newName; // [esp+20h] [ebp+8h]
  const char *newNamee; // [esp+20h] [ebp+8h]
  const char *newNamea; // [esp+20h] [ebp+8h]
  const char *newNameb; // [esp+20h] [ebp+8h]
  const char *newNamec; // [esp+20h] [ebp+8h]
  const char *newNamed; // [esp+20h] [ebp+8h]

  v3 = event->GetName(this: event);
  newName = v3;
  v4 = event->GetInt(this: event, a2: "userid", a3: 0);
  playerName = (const char *)v4;
  v5 = _V_strlen(str: "player_connect");
  if ( V_strncmp(s1: v3, s2: "player_connect", count: v5) == 0 )
  {
    v6 = event->GetString(this: event, a2: "name", a3: locale);
    newNamee = event->GetString(this: event, a2: "address", a3: locale);
    v7 = event->GetString(this: event, a2: "networkid", a3: locale);
    UTIL_LogPrintf(fmt: "\"%s<%i><%s><>\" connected, address \"%s\"\n", v6, v4, v7, newNamee);
    return 1;
  }
  v9 = _V_strlen(str: "player_disconnect");
  if ( V_strncmp(s1: v3, s2: "player_disconnect", count: v9) == 0 )
  {
    v10 = event->GetString(this: event, a2: "reason", a3: locale);
    newNamea = event->GetString(this: event, a2: "name", a3: locale);
    v11 = event->GetString(this: event, a2: "networkid", a3: locale);
    v12 = UTIL_PlayerByUserId(userID: v4);
    if ( v12 != nullptr && (Team = CBaseEntity::GetTeam(this: v12)) != nullptr )
      v14 = Team->GetName(this: Team);
    else
      v14 = locale;
    UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" disconnected (reason \"%s\")\n", newNamea, v4, v11, v14, v10);
    return 1;
  }
  v15 = UTIL_PlayerByUserId(userID: v4);
  if ( v15 == nullptr )
  {
    DevMsg(a1: "CEventLog::PrintPlayerEvent: Failed to find player (userid: %i, event: %s)\n", v4, newName);
    return 0;
  }
  v16 = _V_strlen(str: "player_team");
  if ( V_strncmp(s1: newName, s2: "player_team", count: v16) != 0 )
  {
    v24 = _V_strlen(str: "player_death");
    if ( V_strncmp(s1: newName, s2: "player_death", count: v24) != 0 )
    {
      v39 = _V_strlen(str: "player_activate");
      if ( V_strncmp(s1: newName, s2: "player_activate", count: v39) == 0 )
      {
        NetworkIDString = CBasePlayer::GetNetworkIDString(this: v15);
        v41 = (const char *)((int (__thiscall *)(CBasePlayer *, int, const char *))v15->GetPlayerName)(
                              a1: v15,
                              a2: v4,
                              a3: NetworkIDString);
        UTIL_LogPrintf(fmt: "\"%s<%i><%s><>\" entered the game\n", v41, v60, v67);
        return 1;
      }
      v42 = _V_strlen(str: "player_changename");
      if ( V_strncmp(s1: newName, s2: "player_changename", count: v42) == 0 )
      {
        newNamed = event->GetString(this: event, a2: "newname", a3: locale);
        v43 = event->GetString(this: event, a2: "oldname", a3: locale);
        v44 = CBaseEntity::GetTeam(this: v15);
        if ( v44 != nullptr )
          v45 = v44->GetName(this: v44);
        else
          v45 = locale;
        v61 = v45;
        v46 = CBasePlayer::GetNetworkIDString(this: v15);
        UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" changed name to \"%s\"\n", v43, v4, v46, v61, newNamed);
        return 1;
      }
      return 0;
    }
    attackerid = event->GetInt(this: event, a2: "attacker", a3: 0);
    v25 = UTIL_PlayerByUserId(userID: attackerid);
    v26 = CBaseEntity::GetTeam(this: v15);
    if ( v25 != nullptr )
      CBaseEntity::GetTeam(this: v25);
    if ( v15 == v25 )
    {
      if ( v26 != nullptr )
        v27 = v26->GetName(this: v26);
      else
        v27 = locale;
      pszValue = v25->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v62 = pszValue;
      v56 = v27;
      v29 = CBasePlayer::GetNetworkIDString(this: v15);
      v30 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *, const char *, const char *, const char *))v15->GetPlayerName)(
                            a1: v15,
                            a2: playerName,
                            a3: v29,
                            a4: v56,
                            a5: v62);
      UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" committed suicide with \"%s\"\n", v30, v50, v53, v57, v63);
      return 1;
    }
    else if ( v25 != nullptr )
    {
      v31 = CBaseEntity::GetTeam(this: v25);
      attackerTeam = v31;
      if ( v26 != nullptr )
      {
        newNamec = v26->GetName(this: v26);
        v31 = attackerTeam;
      }
      else
      {
        newNamec = locale;
      }
      if ( v31 != nullptr )
        v32 = v31->GetName(this: v31);
      else
        v32 = locale;
      v33 = CBasePlayer::GetNetworkIDString(this: v15);
      v51 = ((int (__thiscall *)(CBasePlayer *, const char *, const char *, const char *))v15->GetPlayerName)(
              a1: v15,
              a2: playerName,
              a3: v33,
              a4: newNamec);
      v34 = CBasePlayer::GetNetworkIDString(this: v25);
      v35 = (const char *)((int (__thiscall *)(CBasePlayer *, int, const char *, const char *, int))v25->GetPlayerName)(
                            a1: v25,
                            a2: attackerid,
                            a3: v34,
                            a4: v32,
                            a5: v51);
      UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\"\n", v35, v47, v48, v49, v52, v54, v58, v64);
      return 1;
    }
    else
    {
      if ( v26 != nullptr )
        v36 = v26->GetName(this: v26);
      else
        v36 = locale;
      v65 = v36;
      v37 = CBasePlayer::GetNetworkIDString(this: v15);
      v38 = (const char *)((int (__thiscall *)(CBasePlayer *, const char *, const char *, const char *))v15->GetPlayerName)(
                            a1: v15,
                            a2: playerName,
                            a3: v37,
                            a4: v65);
      UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" committed suicide with \"world\"\n", v38, v55, v59, v66);
      return 1;
    }
  }
  else
  {
    if ( !event->GetBool(this: event, a2: "disconnect", a3: false) )
    {
      v17 = event->GetInt(this: event, a2: "team", a3: 0);
      v18 = event->GetInt(this: event, a2: "oldteam", a3: 0);
      newNameb = (const char *)GetGlobalTeam(iIndex: v17);
      GlobalTeam = GetGlobalTeam(iIndex: v18);
      playerNamea = v15->GetPlayerName(this: v15);
      v20 = engine->GetPlayerUserId(this: engine, a2: v15->m_Network.m_pPev);
      if ( v20 > 0 )
      {
        v21 = CBasePlayer::GetNetworkIDString(this: v15);
        if ( GlobalTeam != nullptr )
          v22 = GlobalTeam->GetName(this: GlobalTeam);
        else
          v22 = "Unassigned";
        if ( newNameb != nullptr )
          v23 = (const char *)(*(int (__thiscall **)(const char *))(*(_DWORD *)newNameb + 784))(a1: newNameb);
        else
          v23 = "Unassigned";
        UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" joined team \"%s\"\n", playerNamea, v20, v21, v22, v23);
      }
    }
    return 1;
  }
}
