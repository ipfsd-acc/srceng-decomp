// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/teamplay_gamerules.cpp
// Functions: 68
// ============================================================

#include "game\shared\teamplay_gamerules.h"

//------------------------------------------------------------------------------
// Address: 0x1002D8A0
// Name: public: virtual void CTeamplayRules::SetWinningTeam(int,int,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::SetWinningTeam(
        CBaseCombatCharacter *this,
        const Vector *origin,
        bool leftFoot,
        bool feetInWater,
        bool kneesInWater,
        bool jumping)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101D1120
// Name: public: virtual bool CTeamplayRules::PlayerMayCapturePoint(class CBasePlayer __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTeamplayRules::PlayerMayCapturePoint(
        CPluginHelpersCheck *this,
        const char *plugin,
        edict_t *pEntity,
        edict_t *type,
        KeyValues *data)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10230970
// Name: public: virtual void CTeamplayRules::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::Precache(CTeamplayRules *this)
{
  int i; // esi
  CTeam *GlobalTeam; // eax

  CGameRules::Precache(this);
  for ( i = 0; i < GetNumberOfTeams(); ++i )
  {
    GlobalTeam = GetGlobalTeam(iIndex: i);
    GlobalTeam->Precache(this: GlobalTeam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102309A0
// Name: public: virtual int CTeamplayRules::PlayerRelationship(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTeamplayRules::PlayerRelationship(CTeamplayRules *this, CBaseEntity *pPlayer, CBaseEntity *pTarget)
{
  const char *v4; // eax
  BOOL result; // eax

  result = false;
  if ( pPlayer != nullptr
    && pTarget != nullptr
    && pTarget->IsPlayer(this: pTarget)
    && *this->GetTeamID(this, a2: pPlayer) != 0
    && *this->GetTeamID(this, a2: pTarget) != 0 )
  {
    this->GetTeamID(this, a2: pTarget);
    v4 = (const char *)((int (__thiscall *)(CTeamplayRules *))this->GetTeamID)(a1: this);
    if ( _V_stricmp(s1: v4, s2: (const char *)pPlayer) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10230A30
// Name: public: virtual int CTeamplayRules::IPointsForKill(class CBasePlayer __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeamplayRules::IPointsForKill(CTeamplayRules *this, CBasePlayer *pAttacker, CBasePlayer *pKilled)
{
  if ( pKilled == nullptr )
    return 0;
  if ( pAttacker != nullptr && pAttacker != pKilled && this->PlayerRelationship(this, a2: pAttacker, a3: pKilled) == 1 )
    return -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10230A70
// Name: public: virtual int CTeamplayRules::GetTeamIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeamplayRules::GetTeamIndex(CTeamplayRules *this, const char *pTeamName)
{
  int v2; // esi
  const char *i; // edi

  if ( pTeamName == nullptr )
    return -1;
  if ( *pTeamName == 0 )
    return -1;
  v2 = 0;
  if ( num_teams <= 0 )
    return -1;
  for ( i = team_names[0]; _V_stricmp(s1: i, s2: pTeamName) != 0; i += 16 )
  {
    if ( ++v2 >= num_teams )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10230AC0
// Name: public: virtual char const __near * CTeamplayRules::GetIndexedTeamName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTeamplayRules::GetIndexedTeamName(CTeamplayRules *this, int teamIndex)
{
  if ( teamIndex < 0 || teamIndex >= num_teams )
    return (char *)locale;
  else
    return team_names[teamIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10230AF0
// Name: public: virtual bool CTeamplayRules::IsValidTeam(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::IsValidTeam(CTeamplayRules *this, const char *pTeamName)
{
  return !this->m_teamLimit || this->GetTeamIndex(this, a2: pTeamName) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10230B20
// Name: public: virtual void CTeamplayRules::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::Think(CTeamplayRules *this)
{
  float v2; // xmm0_4
  float m_fValue; // xmm0_4
  int v4; // eax

  CMultiplayRules::Think(this);
  if ( g_fGameOver )
  {
    CMultiplayRules::Think(this);
    return;
  }
  v2 = mp_timelimit.m_pParent->m_Value.m_fValue * 60.0;
  if ( v2 != 0.0 && gpGlobals->curtime >= v2 )
    goto LABEL_10;
  m_fValue = fraglimit.m_pParent->m_Value.m_fValue;
  if ( m_fValue != 0.0 )
  {
    v4 = 0;
    if ( num_teams > 0 )
    {
      while ( (float)team_scores[v4] < m_fValue )
      {
        if ( ++v4 >= num_teams )
          return;
      }
LABEL_10:
      this->ChangeLevel(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230BD0
// Name: public: virtual bool CTeamplayRules::ClientCommand(class CBaseEntity __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::ClientCommand(CTeamplayRules *this, CBaseEntity *pEdict, const CCommand *args)
{
  const char *v4; // eax

  if ( CMultiplayRules::ClientCommand(this, pEdict, args) )
    return true;
  v4 = locale;
  if ( args->m_nArgc > 0 )
    v4 = args->m_ppArgv[0];
  return v4 == "menuselect" || _V_stricmp(s1: v4, s2: "menuselect") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10230C20
// Name: public: virtual char const __near * CTeamplayRules::SetDefaultPlayerTeam(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTeamplayRules::SetDefaultPlayerTeam(CTeamplayRules *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax
  signed int v3; // esi

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v3 = m_pPev - gpGlobals->pEdicts;
  else
    v3 = 0;
  if ( ((unsigned __int8 (*)(void))pPlayer->IsNetClient)() != 0 )
    return engine->GetClientConVarValue(this: engine, a2: v3, a3: "cl_team");
  else
    return "default";
}

//------------------------------------------------------------------------------
// Address: 0x10230C80
// Name: public: virtual void CTeamplayRules::ClientDisconnected(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::ClientDisconnected(CTeamplayRules *this, edict_t *pClient)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v5; // eax
  int v6; // esi

  pEdicts = pClient;
  if ( pClient != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v5 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v6 = v5;
      if ( v5 != 0 )
      {
        *(_DWORD *)(v5 + 3656) = 1;
        if ( CBaseEntity::GetTeam(this: (CBaseEntity *)v5) != nullptr )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 372))(a1: v6, a2: 0);
      }
    }
  }
  CMultiplayRules::ClientDisconnected(this, pClient);
}

//------------------------------------------------------------------------------
// Address: 0x10230CF0
// Name: public: virtual bool CTeamplayRules::FPlayerCanTakeDamage(class CBasePlayer __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::FPlayerCanTakeDamage(
        CTeamplayRules *this,
        CBasePlayer *pPlayer,
        CBasePlayer *pAttacker)
{
  return (pAttacker == nullptr
       || this->PlayerRelationship(this, a2: pPlayer, a3: pAttacker) != 1
       || friendlyfire.m_pParent != nullptr && friendlyfire.m_pParent->m_Value.m_nValue != 0
       || pAttacker == pPlayer)
      && CGameRules::FPlayerCanTakeDamage(
           (CAI_BaseNPC *)this,
           vecSightDir: (const Vector *)pPlayer,
           sightDist: *(float *)&pAttacker);
}

//------------------------------------------------------------------------------
// Address: 0x10230D40
// Name: public: virtual bool CTeamplayRules::ShouldAutoAim(class CBasePlayer __near *,struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::ShouldAutoAim(CTeamplayRules *this, CBasePlayer *pPlayer, edict_t *target)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v6; // eax
  CBaseEntity *v7; // esi
  bool result; // al

  pEdicts = target;
  result = true;
  if ( target != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0 )
  {
    m_pUnk = pEdicts->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v6 = (int)m_pUnk->GetBaseEntity(this: m_pUnk);
      v7 = (CBaseEntity *)v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 336))(a1: v6) != 0
        && this->PlayerRelationship(this, a2: pPlayer, a3: v7) == 1 )
      {
        return false;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10230DB0
// Name: private: void CTeamplayRules::RecountTeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::RecountTeams(CTeamplayRules *this)
{
  char *j; // esi
  int v3; // eax
  CBasePlayer *v4; // eax
  const char *v5; // edi
  int v6; // esi
  char *v7; // [esp-Ch] [ebp-220h]
  char teamlist[512]; // [esp+Ch] [ebp-208h] BYREF
  CBasePlayer *plr; // [esp+20Ch] [ebp-8h]
  int i; // [esp+210h] [ebp-4h]

  num_teams = 0;
  V_strncpy(pDest: teamlist, pSrc: this->m_szTeamList, maxLen: 512);
  for ( j = strtok(string: teamlist, control: ";"); j != nullptr; j = strtok(string: nullptr, control: ";") )
  {
    if ( *j == 0 )
      break;
    if ( this->GetTeamIndex(this, a2: j) < 0 )
    {
      V_strncpy(pDest: team_names[num_teams], pSrc: j, maxLen: 16);
      ++num_teams;
    }
  }
  if ( num_teams < 2 )
  {
    num_teams = 0;
    this->m_teamLimit = false;
  }
  memset(dst: (unsigned __int8 *)team_scores, value: 0, count: sizeof(team_scores));
  v3 = 1;
  for ( i = 1; v3 <= gpGlobals->maxClients; i = v3 )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: v3);
    plr = v4;
    if ( v4 != nullptr )
    {
      v5 = CBaseEntity::TeamID(this: v4);
      v6 = this->GetTeamIndex(this, a2: v5);
      if ( v6 >= 0 )
        goto LABEL_14;
      if ( !this->m_teamLimit )
      {
        v6 = num_teams;
        v7 = team_names[num_teams++];
        team_scores[v6] = 0;
        V_strncpy(pDest: v7, pSrc: v5, maxLen: 16);
      }
      if ( v6 >= 0 )
LABEL_14:
        team_scores[v6] += plr->m_iFrags;
    }
    v3 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230F20
// Name: public: virtual void CTeamplayRules::InitHUD(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::InitHUD(CTeamplayRules *this, CBasePlayer *pPlayer)
{
  this->SetDefaultPlayerTeam(this, a2: pPlayer);
  CNavMesh::SaveCustomData((vgui::TreeView *)this, itemIndex: (int)pPlayer);
  CTeamplayRules::RecountTeams(this);
}

//------------------------------------------------------------------------------
// Address: 0x10230F60
// Name: public: virtual void CTeamplayRules::ClientSettingsChanged(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::ClientSettingsChanged(CTeamplayRules *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax
  const char *v4; // edi
  IGameEvent *v5; // esi
  int v6; // eax
  const char *pszName; // [esp+14h] [ebp+8h]

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  pszName = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "name");
  v4 = pPlayer->GetPlayerName(this: pPlayer);
  if ( _V_strcmp(s1: v4, s2: pszName) != 0 )
  {
    if ( *v4 != 0 )
    {
      v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_changename", a3: 0, a4: 0);
      if ( v5 != nullptr )
      {
        v6 = engine->GetPlayerUserId(this: engine, a2: pPlayer->m_Network.m_pPev);
        v5->SetInt(this: v5, a2: "userid", a3: v6);
        v5->SetString(this: v5, a2: "oldname", a3: v4);
        v5->SetString(this: v5, a2: "newname", a3: pszName);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
      }
    }
    CBasePlayer::SetPlayerName(this: pPlayer, name: pszName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231040
// Name: public: virtual void CTeamplayRules::DeathNotice(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::DeathNotice(CTeamplayRules *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // ecx
  CBasePlayer *m_pEntity; // edi
  IGameEvent *v6; // eax
  IGameEvent *v7; // esi
  IGameEvent_vtbl *v8; // ebx
  int UserID; // eax
  IGameEvent_vtbl *v10; // edi
  int v11; // eax

  if ( !this->m_DisableDeathMessages )
  {
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( pVictim != nullptr
      && m_pEntity != nullptr
      && m_pEntity->IsPlayer(this: m_pEntity)
      && m_pEntity != pVictim
      && this->PlayerRelationship(this, a2: pVictim, a3: m_pEntity) == 1 )
    {
      v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_death", a3: 0, a4: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v8 = v6->__vftable;
        UserID = CBasePlayer::GetUserID(this: m_pEntity);
        v8->SetInt(this: v7, a2: "killer", a3: UserID);
        v10 = v7->__vftable;
        v11 = CBasePlayer::GetUserID(this: pVictim);
        v10->SetInt(this: v7, a2: "victim", a3: v11);
        v7->SetInt(this: v7, a2: "priority", a3: 7);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
      }
    }
    else
    {
      CMultiplayRules::DeathNotice(this, pVictim, info);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231150
// Name: public: virtual void CTeamplayRules::PlayerKilled(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::PlayerKilled(CTeamplayRules *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  if ( !this->m_DisableDeathPenalty )
  {
    CMultiplayRules::PlayerKilled(this, pVictim, info);
    CTeamplayRules::RecountTeams(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231180
// Name: public: virtual bool CTeamplayRules::PlayerCanHearChat(class CBasePlayer __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::PlayerCanHearChat(CTeamplayRules *this, CBasePlayer *pListener, CBasePlayer *pSpeaker)
{
  if ( sv_allchat.m_pParent != nullptr
    && sv_allchat.m_pParent->m_Value.m_nValue != 0
    && !pSpeaker->IsAlive(this: pSpeaker) )
  {
    return !pListener->IsAlive(this: pListener);
  }
  else
  {
    return this->PlayerRelationship(this, a2: pListener, a3: pSpeaker) == 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102311E0
// Name: public: virtual char const __near * CTeamplayRules::GetTeamID(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTeamplayRules::GetTeamID(CTeamplayRules *this, CBaseEntity *pEntity)
{
  if ( pEntity != nullptr && pEntity->m_Network.m_pPev != nullptr )
    return CBaseEntity::TeamID(this: pEntity);
  else
    return locale;
}

//------------------------------------------------------------------------------
// Address: 0x10231210
// Name: public: CTeamplayRules::CTeamplayRules(void)
// Source: json
//------------------------------------------------------------------------------
CTeamplayRules *__thiscall CTeamplayRules::CTeamplayRules(CTeamplayRules *this)
{
  CMultiplayRules::CMultiplayRules(this);
  this->__vftable = (CTeamplayRules_vtbl *)&CTeamplayRules::`vftable';
  *(_WORD *)&this->m_DisableDeathMessages = 0;
  *(_WORD *)&this->m_bSwitchTeams = 0;
  memset(dst: (unsigned __int8 *)team_names, value: 0, count: sizeof(team_names));
  memset(dst: (unsigned __int8 *)team_scores, value: 0, count: sizeof(team_scores));
  num_teams = 0;
  this->m_szTeamList[0] = 0;
  CTeamplayRules::RecountTeams(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10231270
// Name: public: virtual int CTeamplayRules::GetCaptureValueForPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTeamplayRules::GetCaptureValueForPlayer(CBaseCombatCharacter *this, CBaseCombatWeapon *pWeapon)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10231280
// Name: public: virtual char const __near * CTeamplayRules::GetGameDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CTeamplayRules::GetGameDescription(CTeamplayRules *this)
{
  return "Teamplay";
}

//------------------------------------------------------------------------------
// Address: 0x10231290
// Name: public: virtual void CTeamplayRules::SetSwitchTeams(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::SetSwitchTeams(CTeamplayRules *this, bool bSwitch)
{
  this->m_bSwitchTeams = bSwitch;
}

//------------------------------------------------------------------------------
// Address: 0x102312A0
// Name: public: virtual bool CTeamplayRules::ShouldSwitchTeams(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::ShouldSwitchTeams(CTeamplayRules *this)
{
  return this->m_bSwitchTeams;
}

//------------------------------------------------------------------------------
// Address: 0x102312B0
// Name: public: virtual void CTeamplayRules::SetScrambleTeams(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRules::SetScrambleTeams(CTeamplayRules *this, bool bScramble)
{
  this->m_bScrambleTeams = bScramble;
}

//------------------------------------------------------------------------------
// Address: 0x102312C0
// Name: public: virtual bool CTeamplayRules::ShouldScrambleTeams(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTeamplayRules::ShouldScrambleTeams(CBaseAnimating *this)
{
  return this->m_bClientSideRagdoll.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10231310
// Name: void __CreateGameRules_CTeamplayRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CreateGameRules_CTeamplayRules()
{
  CTeamplayRules *v0; // esi

  v0 = (CTeamplayRules *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 556);
  _V_memset(dest: v0, fill: 0, count: 556);
  if ( v0 != nullptr )
    CTeamplayRules::CTeamplayRules(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10404380
// Name: _dynamic_initializer_for__teamplay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__teamplay__()
{
  ConVar::ConVar(this: &teamplay, pName: "mp_teamplay", pDefaultValue: "0", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__teamplay__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AC50
// Name: _dynamic_initializer_for__team_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__team_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CTeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &team_manager,
           a3: "team_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1041BA10
// Name: _dynamic_atexit_destructor_for__teamplay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__teamplay__()
{
  ConVar::~ConVar(this: &teamplay);
}

//------------------------------------------------------------------------------
// Address: 0x10231350
// Name: __CreateCServerGameTagsIServerGameTags_interface_6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_6()
{
  return &_g_CServerGameTags_singleton_6;
}

//------------------------------------------------------------------------------
// Address: 0x104043B0
// Name: _dynamic_initializer_for__falldamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__falldamage__()
{
  ConVar::ConVar(this: &falldamage, pName: "mp_falldamage", pDefaultValue: "0", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__falldamage__);
}

//------------------------------------------------------------------------------
// Address: 0x104043E0
// Name: _dynamic_initializer_for__weaponstay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__weaponstay__()
{
  ConVar::ConVar(this: &weaponstay, pName: "mp_weaponstay", pDefaultValue: "0", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__weaponstay__);
}

//------------------------------------------------------------------------------
// Address: 0x10404410
// Name: _dynamic_initializer_for__forcerespawn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__forcerespawn__()
{
  ConVar::ConVar(this: &forcerespawn, pName: "mp_forcerespawn", pDefaultValue: "1", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__forcerespawn__);
}

//------------------------------------------------------------------------------
// Address: 0x10404440
// Name: _dynamic_initializer_for__footsteps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__footsteps__()
{
  ConVar::ConVar(this: &footsteps, pName: "mp_footsteps", pDefaultValue: "1", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__footsteps__);
}

//------------------------------------------------------------------------------
// Address: 0x10404470
// Name: _dynamic_initializer_for__flashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__flashlight__()
{
  ConVar::ConVar(this: &flashlight, pName: "mp_flashlight", pDefaultValue: "0", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__flashlight__);
}

//------------------------------------------------------------------------------
// Address: 0x104044A0
// Name: _dynamic_initializer_for__aimcrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__aimcrosshair__()
{
  ConVar::ConVar(this: &aimcrosshair, pName: "mp_autocrosshair", pDefaultValue: "1", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__aimcrosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x104044D0
// Name: _dynamic_initializer_for__decalfrequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__decalfrequency__()
{
  ConVar::ConVar(this: &decalfrequency, pName: "decalfrequency", pDefaultValue: "10", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__decalfrequency__);
}

//------------------------------------------------------------------------------
// Address: 0x10404500
// Name: _dynamic_initializer_for__teamlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__teamlist__()
{
  ConVar::ConVar(this: &teamlist, pName: "mp_teamlist", pDefaultValue: "hgrunt;scientist", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__teamlist__);
}

//------------------------------------------------------------------------------
// Address: 0x10404530
// Name: _dynamic_initializer_for__teamoverride__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__teamoverride__()
{
  ConVar::ConVar(this: &teamoverride, pName: "mp_teamoverride", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__teamoverride__);
}

//------------------------------------------------------------------------------
// Address: 0x10404560
// Name: _dynamic_initializer_for__defaultteam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__defaultteam__()
{
  ConVar::ConVar(this: &defaultteam, pName: "mp_defaultteam", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__defaultteam__);
}

//------------------------------------------------------------------------------
// Address: 0x10404590
// Name: _dynamic_initializer_for__allowNPCs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__allowNPCs__()
{
  ConVar::ConVar(this: &allowNPCs, pName: "mp_allowNPCs", pDefaultValue: "1", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__allowNPCs__);
}

//------------------------------------------------------------------------------
// Address: 0x104045C0
// Name: _dynamic_initializer_for__suitvolume__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__suitvolume__()
{
  ConVar::ConVar(this: &suitvolume, pName: "suitvolume", pDefaultValue: "0.25", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__suitvolume__);
}

//------------------------------------------------------------------------------
// Address: 0x104045F0
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
// Address: 0x10404620
// Name: _dynamic_initializer_for__sv_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_timescale__()
{
  ConCommand::ConCommand(
    this: &sv_timescale,
    pName: "sv_timescale",
    callback: SV_TimeScale,
    pHelpString: "Change the speed of the game.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AC70
// Name: _dynamic_initializer_for__g_CBaseTeamObjectiveResource_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseTeamObjectiveResource_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseTeamObjectiveResource_ClassReg,
           pNetworkName: "CBaseTeamObjectiveResource",
           pTable: &DT_BaseTeamObjectiveResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA20
// Name: _dynamic_atexit_destructor_for__falldamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__falldamage__()
{
  ConVar::~ConVar(this: &falldamage);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA30
// Name: _dynamic_atexit_destructor_for__weaponstay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weaponstay__()
{
  ConVar::~ConVar(this: &weaponstay);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA40
// Name: _dynamic_atexit_destructor_for__forcerespawn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__forcerespawn__()
{
  ConVar::~ConVar(this: &forcerespawn);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA50
// Name: _dynamic_atexit_destructor_for__footsteps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__footsteps__()
{
  ConVar::~ConVar(this: &footsteps);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA60
// Name: _dynamic_atexit_destructor_for__flashlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flashlight__()
{
  ConVar::~ConVar(this: &flashlight);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA70
// Name: _dynamic_atexit_destructor_for__aimcrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__aimcrosshair__()
{
  ConVar::~ConVar(this: &aimcrosshair);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA80
// Name: _dynamic_atexit_destructor_for__decalfrequency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__decalfrequency__()
{
  ConVar::~ConVar(this: &decalfrequency);
}

//------------------------------------------------------------------------------
// Address: 0x1041BA90
// Name: _dynamic_atexit_destructor_for__teamlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__teamlist__()
{
  ConVar::~ConVar(this: &teamlist);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAA0
// Name: _dynamic_atexit_destructor_for__teamoverride__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__teamoverride__()
{
  ConVar::~ConVar(this: &teamoverride);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAB0
// Name: _dynamic_atexit_destructor_for__defaultteam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__defaultteam__()
{
  ConVar::~ConVar(this: &defaultteam);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAC0
// Name: _dynamic_atexit_destructor_for__allowNPCs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__allowNPCs__()
{
  ConVar::~ConVar(this: &allowNPCs);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAD0
// Name: _dynamic_atexit_destructor_for__suitvolume__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__suitvolume__()
{
  ConVar::~ConVar(this: &suitvolume);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAE0
// Name: _dynamic_atexit_destructor_for__sv_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_timescale__()
{
  ConCommand::~ConCommand(this: &sv_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x1041BAF0
// Name: _dynamic_atexit_destructor_for__g_GameTimescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameTimescale__()
{
  g_GameTimescale.__vftable = (CGameTimescale_vtbl *)&CGameTimescale::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_GameTimescale);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB10
// Name: _DataMapInit_CGameUI__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGameUI__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_224);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB20
// Name: _dynamic_atexit_destructor_for__sv_massreport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_massreport__()
{
  ConVar::~ConVar(this: &sv_massreport);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB30
// Name: _dynamic_atexit_destructor_for__sv_force_transmit_ents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_force_transmit_ents__()
{
  ConVar::~ConVar(this: &sv_force_transmit_ents);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB40
// Name: _dynamic_atexit_destructor_for__sv_autosave__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_autosave__()
{
  ConVar::~ConVar(this: &sv_autosave);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB50
// Name: _dynamic_atexit_destructor_for__ai_post_frame_navigation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_post_frame_navigation__()
{
  ConVar::~ConVar(this: &ai_post_frame_navigation);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB60
// Name: _dynamic_atexit_destructor_for__sv_threaded_init__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_threaded_init__()
{
  ConVar::~ConVar(this: &sv_threaded_init);
}
