// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_client.cpp
// Functions: 18
// ============================================================

#include "game\server\cstrike15\cs_client.h"

//------------------------------------------------------------------------------
// Address: 0x10269D70
// Name: void ClientPutInServer(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientPutInServer(edict_t *pEdict, const char *playername)
{
  CBasePlayer *Player; // eax

  Player = CBasePlayer::CreatePlayer(className: "player", ed: pEdict);
  CBasePlayer::SetPlayerName(this: Player, name: playername);
}

//------------------------------------------------------------------------------
// Address: 0x10269DA0
// Name: char const __near * GetGameDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetGameDescription()
{
  if ( g_pGameRules != nullptr )
    return g_pGameRules->GetGameDescription(this: g_pGameRules);
  else
    return "Counter-Strike: Source";
}

//------------------------------------------------------------------------------
// Address: 0x10269DC0
// Name: public: virtual void ClientGamePrecachePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientGamePrecachePrecache::CResourcePrecacher::Cache(
        ClientGamePrecachePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/white.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/physbeam.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.PistolShell",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.RifleShell",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.ShotgunShell",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10269E40
// Name: void ClientGamePrecache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientGamePrecache()
{
  engine->ForceExactFile(this: engine, a2: "sprites/white.vmt");
  engine->ForceExactFile(this: engine, a2: "sprites/white.vtf");
  engine->ForceExactFile(this: engine, a2: "vgui/white.vmt");
  engine->ForceExactFile(this: engine, a2: "vgui/white.vtf");
  engine->ForceExactFile(this: engine, a2: "effects/flashbang.vmt");
  engine->ForceExactFile(this: engine, a2: "effects/flashbang_white.vmt");
  engine->ForceExactFile(this: engine, a2: "particle/particle_smokegrenade1.vmt");
  engine->ForceExactFile(this: engine, a2: "particle/particle_smokegrenade.vtf");
  engine->ForceExactFile(this: engine, a2: "sprites/scope_arc.vmt");
  engine->ForceExactFile(this: engine, a2: "sprites/scope_arc.vtf");
  engine->ForceExactFile(this: engine, a2: "scripts/dsp_presets.txt");
}

//------------------------------------------------------------------------------
// Address: 0x10269F30
// Name: void respawn(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl respawn(CBaseEntity *pEdict, bool fCopyCorpse)
{
  void *v2; // eax

  if ( gpGlobals->coop || gpGlobals->deathmatch )
  {
    if ( fCopyCorpse )
    {
      v2 = __RTDynamicCast(
             inptr: pEdict,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CBasePlayer `RTTI Type Descriptor',
             isReference: 0);
      (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 1680))(a1: v2);
    }
    pEdict->Spawn(this: pEdict);
  }
  else
  {
    engine->ServerCommand(this: engine, a2: "reload\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269FA0
// Name: void InstallGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall InstallGameRules(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  CreateGameRulesObject(a1, a2, a3, pClassName: "CCSGameRules");
}

//------------------------------------------------------------------------------
// Address: 0x10269FB0
// Name: void GameStartFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GameStartFrame()
{
  if ( !g_fGameOver )
    gpGlobals->teamplay = teamplay.m_pParent != nullptr && teamplay.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10269FF0
// Name: void FinishClientPutInServer(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall FinishClientPutInServer(int a1@<edi>, CCSPlayer *pPlayer)
{
  int StartMoney; // eax
  const char *v4; // eax
  char *v5; // ecx
  char *v6; // eax
  char sName[128]; // [esp+20h] [ebp-80h] BYREF

  pPlayer->InitialSpawn(this: pPlayer);
  pPlayer->Spawn(this: pPlayer);
  if ( !pPlayer->IsBot(this: pPlayer) )
  {
    pPlayer->m_iNumSpawns = 0;
    if ( pPlayer->m_takedamage.m_Value != 0 )
    {
      ((void (__thiscall *)(CCSPlayer *, CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *, int))pPlayer->NetworkStateChanged_m_takedamage)(
        a1: pPlayer,
        a2: &pPlayer->m_takedamage,
        a3: a1);
      pPlayer->m_takedamage.m_Value = 0;
    }
    if ( !pPlayer->pl.deadflag.m_Value )
    {
      pPlayer->pl.NetworkStateChanged(this: &pPlayer->pl, a2: &pPlayer->pl.deadflag);
      pPlayer->pl.deadflag.m_Value = true;
    }
    if ( pPlayer->m_lifeState.m_Value != 2 )
    {
      pPlayer->NetworkStateChanged_m_lifeState(this: pPlayer, a2: &pPlayer->m_lifeState);
      pPlayer->m_lifeState.m_Value = 2;
    }
    CBaseEntity::AddEffects(this: pPlayer, nEffects: 32);
    pPlayer->ChangeTeam(this: pPlayer, a2: 0);
    CBaseEntity::ThinkSet(
      this: pPlayer,
      func:  __thiscall CBasePlayer::`vcall'{1396,{flat}},
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this: pPlayer, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
    StartMoney = CCSGameRules::GetStartMoney(this: (CCSGameRules *)g_pGameRules);
    CCSPlayer::AddAccount(this: pPlayer, amount: StartMoney, bTrackChange: true, bItemBought: false);
    CCSPlayer::MoveToNextIntroCamera(this: pPlayer);
    CBaseEntity::SetMoveType(this: pPlayer, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  }
  v4 = pPlayer->GetPlayerName(this: pPlayer);
  V_strncpy(pDest: sName, pSrc: v4, maxLen: 128);
  v5 = sName;
  do
  {
    if ( *v5 == 0 )
      break;
    if ( *v5 == 37 )
      *v5 = 32;
    ++v5;
  }
  while ( v5 != nullptr );
  v6 = sName;
  if ( sName[0] == 0 )
    v6 = "<unconnected>";
  UTIL_ClientPrintAll(
    msg_dest: 1u,
    msg_name: "#Game_connected",
    param1: v6,
    param2: nullptr,
    param3: nullptr,
    param4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1026A170
// Name: void ClientActive(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall ClientActive(int a1@<edi>, edict_t *pEdict)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v4; // eax
  void *v5; // esi
  CCSPlayer *v6; // esi
  int m_nValue; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  pEdicts = pEdict;
  if ( (pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr
    && (v4 = (int)m_pUnk->GetBaseEntity(this: m_pUnk), v5 = (void *)v4, v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 336))(a1: v4) != 0 )
  {
    v6 = (CCSPlayer *)__RTDynamicCast(
                        inptr: v5,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  }
  else
  {
    v6 = nullptr;
  }
  FinishClientPutInServer(a1, pPlayer: v6);
  CRecipientFilter::CRecipientFilter(this: &user);
  user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &user, player: v6);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
  UserMessageBegin(filter: &user, messagename: "MatchEndConditions");
  if ( fraglimit.m_pParent != nullptr )
    m_nValue = fraglimit.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  MessageWriteLong(iValue: m_nValue);
  if ( mp_maxrounds.m_pParent != nullptr )
    v8 = mp_maxrounds.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  MessageWriteLong(iValue: v8);
  if ( mp_winlimit.m_pParent != nullptr )
    v9 = mp_winlimit.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  MessageWriteLong(iValue: v9);
  if ( mp_timelimit.m_pParent != nullptr )
    v10 = mp_timelimit.m_pParent->m_Value.m_nValue;
  else
    v10 = 0;
  MessageWriteLong(iValue: v10);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &user);
}

//------------------------------------------------------------------------------
// Address: 0x1040D240
// Name: ClientGamePrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ClientGamePrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  ClientGamePrecachePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&ClientGamePrecachePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D260
// Name: _dynamic_initializer_for__mp_logdetail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_logdetail__()
{
  ConVar::ConVar(
    this: &mp_logdetail,
    pName: "mp_logdetail",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Logs attacks.  Values are: 0=off, 1=enemy, 2=teammate, 3=both)",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 3.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_logdetail__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D2B0
// Name: _dynamic_initializer_for__g_CSEventLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CSEventLog__()
{
  CEventLog::CEventLog(this: &g_CSEventLog);
  g_CSEventLog.CEventLog::CGameEventListener::IGameEventListener2::__vftable = (CCSEventLog_vtbl *)&CCSEventLog::`vftable'{for `CGameEventListener'};
  g_CSEventLog.CEventLog::CBaseGameSystem::IGameSystem::__vftable = (CBaseGameSystem_vtbl *)&CCSEventLog::`vftable'{for `CBaseGameSystem'};
  return atexit(func: dynamic_atexit_destructor_for__g_CSEventLog__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D2E0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___9()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_9,
           fn: _CreateCServerGameTagsIServerGameTags_interface_9,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040D300
// Name: _dynamic_initializer_for__sv_timebetweenducks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_timebetweenducks__()
{
  ConVar::ConVar(
    this: &sv_timebetweenducks,
    pName: "sv_timebetweenducks",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Minimum time before recognizing consecutive duck key",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 2.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_timebetweenducks__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D350
// Name: _dynamic_initializer_for__g_GameMovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GameMovement__()
{
  CGameMovement::CGameMovement(this: &g_GameMovement);
  g_GameMovement.__vftable = (CCSGameMovement_vtbl *)&CCSGameMovement::`vftable';
  g_GameMovement.m_fTimeLastUnducked = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_GameMovement__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D380
// Name: _dynamic_initializer_for____g_CreateCGameMovementIGameMovement_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameMovementIGameMovement_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameMovementIGameMovement_reg,
           fn: _CreateCGameMovementIGameMovement_interface,
           pName: "GameMovement001");
}

//------------------------------------------------------------------------------
// Address: 0x1040D3A0
// Name: _dynamic_initializer_for__sv_enablebunnyhopping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_enablebunnyhopping__()
{
  ConVar::ConVar(this: &sv_enablebunnyhopping, pName: "sv_enablebunnyhopping", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__sv_enablebunnyhopping__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D3D0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___10()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_10,
           fn: _CreateCServerGameTagsIServerGameTags_interface_10,
           pName: "ServerGameTags001");
}
