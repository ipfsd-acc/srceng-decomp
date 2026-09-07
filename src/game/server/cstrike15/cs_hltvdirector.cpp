// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_hltvdirector.cpp
// Functions: 7
// ============================================================

#include "game\server\cstrike15\cs_hltvdirector.h"

//------------------------------------------------------------------------------
// Address: 0x1027D0A0
// Name: public: virtual char const __near * __near * CCSHLTVDirector::GetModEvents(void)
// Source: json
//------------------------------------------------------------------------------
const char **__thiscall CCSHLTVDirector::GetModEvents(CCSHLTVDirector *this)
{
  return s_modevents_0;
}

//------------------------------------------------------------------------------
// Address: 0x1027D0F0
// Name: class CHLTVDirector __near * HLTVDirector(void)
// Source: json
//------------------------------------------------------------------------------
CCSHLTVDirector *__cdecl HLTVDirector()
{
  return &s_HLTVDirector;
}

//------------------------------------------------------------------------------
// Address: 0x1027D100
// Name: class IGameSystem __near * HLTVDirectorSystem(void)
// Source: json
//------------------------------------------------------------------------------
CBaseGameSystemPerFrame *__cdecl HLTVDirectorSystem()
{
  return &s_HLTVDirector.CBaseGameSystemPerFrame;
}

//------------------------------------------------------------------------------
// Address: 0x1027D120
// Name: public: virtual void CCSHLTVDirector::SetHLTVServer(class IHLTVServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSHLTVDirector::SetHLTVServer(CCSHLTVDirector *this@<ecx>, int a2@<ebx>, IHLTVServer *hltv)
{
  IGameEventListener2 *v4; // esi

  CHLTVDirector::SetHLTVServer(this, a2, hltv);
  if ( this->m_nDebugID != 0 )
  {
    v4 = (CCSHLTVDirector *)((char *)this - 16);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hostage_rescued", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hostage_killed", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hostage_hurt", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "hostage_follows", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "bomb_pickup", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "bomb_dropped", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "bomb_exploded", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "bomb_defused", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "bomb_planted", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "vip_escaped", a4: true);
    LOBYTE(v4[2].__vftable) = 1;
    gameeventmanager->AddListener(this: gameeventmanager, a2: v4, a3: "vip_killed", a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D250
// Name: public: virtual void CCSHLTVDirector::CreateShotFromEvent(class CHLTVGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSHLTVDirector::CreateShotFromEvent(CCSHLTVDirector *this, CBaseEntity *event)
{
  CCSHLTVDirector *v3; // ebx
  const char *v4; // esi
  int v5; // eax
  CBasePlayer *v6; // ebx
  IGameEvent *v7; // esi
  edict_t *v8; // eax
  int v9; // eax
  edict_t *v10; // eax
  int v11; // eax
  signed int m_pPev; // eax
  int v13; // eax
  int m_nNextShotTick; // eax
  IHLTVServer *m_pHLTVServer; // ecx
  const char *name; // [esp+3Ch] [ebp-Ch]
  CBaseEntity *v17; // [esp+40h] [ebp-8h]
  CBaseEntity *v18; // [esp+40h] [ebp-8h]
  CBasePlayer *player; // [esp+50h] [ebp+8h]

  v3 = this;
  v4 = (const char *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)event->m_pfnThink + 4))(a1: event->m_pfnThink);
  name = v4;
  if ( _V_strcmp(s1: "hostage_rescued", s2: v4) == 0
    || _V_strcmp(s1: "hostage_hurt", s2: v4) == 0
    || _V_strcmp(s1: "hostage_follows", s2: v4) == 0
    || _V_strcmp(s1: "hostage_killed", s2: v4) == 0 )
  {
    v11 = (*(int (__thiscall **)(void (__thiscall *)(CBaseEntity *), const char *, _DWORD))(*(_DWORD *)event->m_pfnThink
                                                                                          + 24))(
            a1: event->m_pfnThink,
            a2: "userid",
            a3: 0);
    player = UTIL_PlayerByUserId(userID: v11);
    if ( player == nullptr )
      return;
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_chase", a3: 1, a4: 0);
    m_pPev = (signed int)player->m_Network.m_pPev;
    if ( m_pPev != 0 )
      m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
    v7->SetInt(this: v7, a2: "target1", a3: m_pPev);
    v18 = (CBaseEntity *)v7->__vftable;
    v13 = (*(int (__thiscall **)(void (__thiscall *)(CBaseEntity *), const char *, _DWORD))(*(_DWORD *)event->m_pfnThink
                                                                                          + 24))(
            a1: event->m_pfnThink,
            a2: "hostage",
            a3: 0);
    ((void (__thiscall *)(IGameEvent *, const char *, int))LODWORD(v18->m_Network.m_PVSInfo.m_vCenter[1]))(
      a1: v7,
      a2: "target2",
      a3: v13);
    ((void (__thiscall *)(IGameEvent *, const char *, int))v7->SetFloat)(a1: v7, a2: "distance", a3: 1119879168);
    v7->SetInt(this: v7, a2: "theta", a3: 40);
    v7->SetInt(this: v7, a2: "phi", a3: 20);
    m_nNextShotTick = (int)event->__vftable + (int)(float)((float)(2.0 / gpGlobals->interval_per_tick) + 0.5);
    if ( v3->m_nNextShotTick < m_nNextShotTick )
      m_nNextShotTick = v3->m_nNextShotTick;
    v3->m_nNextShotTick = m_nNextShotTick;
    v10 = player->m_Network.m_pPev;
    if ( v10 != nullptr )
      v10 -= (int)gpGlobals->pEdicts;
    goto LABEL_21;
  }
  if ( _V_strcmp(s1: "bomb_pickup", s2: v4) != 0
    && _V_strcmp(s1: "bomb_dropped", s2: v4) != 0
    && _V_strcmp(s1: "bomb_planted", s2: v4) != 0
    && _V_strcmp(s1: "bomb_defused", s2: v4) != 0 )
  {
    CHLTVDirector::CreateShotFromEvent(this: v3, (CHLTVGameEvent *)event);
    return;
  }
  v5 = (*(int (__thiscall **)(void (__thiscall *)(CBaseEntity *), const char *, _DWORD))(*(_DWORD *)event->m_pfnThink
                                                                                       + 24))(
         a1: event->m_pfnThink,
         a2: "userid",
         a3: 0);
  v6 = UTIL_PlayerByUserId(userID: v5);
  v17 = v6;
  if ( v6 != nullptr )
  {
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hltv_chase", a3: 1, a4: 0);
    v8 = CBaseEntity::entindex(this: v6);
    v7->SetInt(this: v7, a2: "target1", a3: (int)v8);
    v7->SetInt(this: v7, a2: "target2", a3: 0);
    ((void (__thiscall *)(IGameEvent *, const char *, int))v7->SetFloat)(a1: v7, a2: "distance", a3: 1115684864);
    v7->SetInt(this: v7, a2: "theta", a3: 200);
    v7->SetInt(this: v7, a2: "phi", a3: 10);
    v3 = this;
    v9 = (int)event->__vftable + (int)(float)((float)(2.0 / gpGlobals->interval_per_tick) + 0.5);
    if ( this->m_nNextShotTick < v9 )
      v9 = this->m_nNextShotTick;
    this->m_nNextShotTick = v9;
    v10 = CBaseEntity::entindex(this: v17);
LABEL_21:
    m_pHLTVServer = v3->m_pHLTVServer;
    v3->m_iPVSEntity = (int)v10;
    m_pHLTVServer->BroadcastEvent(this: m_pHLTVServer, a2: v7);
    gameeventmanager->FreeEvent(this: gameeventmanager, a2: v7);
    DevMsg(a1: "DrcCmd: %s\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D0E0
// Name: __CreateCHLTVDirectorIHLTVDirector_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IHLTVDirector *__cdecl _CreateCHLTVDirectorIHLTVDirector_interface()
{
  return &s_HLTVDirector.IHLTVDirector;
}

//------------------------------------------------------------------------------
// Address: 0x1027D550
// Name: __CreateCServerGameTagsIServerGameTags_interface_11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_11()
{
  return &_g_CServerGameTags_singleton_11;
}
