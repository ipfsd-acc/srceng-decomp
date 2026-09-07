// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_eventlog.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\cs_eventlog.h"

//------------------------------------------------------------------------------
// Address: 0x1026A2C0
// Name: class CEventLog __near * GameLogSystem(void)
// Source: json
//------------------------------------------------------------------------------
CCSEventLog *__cdecl GameLogSystem()
{
  return &g_CSEventLog;
}

//------------------------------------------------------------------------------
// Address: 0x1026A2E0
// Name: public: virtual bool CCSEventLog::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSEventLog::Init(CCSEventLog *this)
{
  CCSEventLog *v1; // esi

  v1 = this;
  CEventLog::Init(this);
  v1 = (CCSEventLog *)((char *)v1 - 12);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "round_end", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "round_start", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "bomb_pickup", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "bomb_begindefuse", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "bomb_dropped", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "bomb_defused", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "bomb_planted", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "hostage_rescued", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "hostage_killed", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "hostage_follows", a4: true);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_hurt", a4: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026A400
// Name: protected: bool CCSEventLog::PrintCStrikeEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSEventLog::PrintCStrikeEvent(CCSEventLog *this, IGameEvent *event)
{
  const char *v3; // ebx
  int v4; // eax
  int v5; // edi
  const char *v6; // ebx
  CTeam *GlobalTeam; // esi
  CTeam *v8; // edi
  int (__thiscall *GetScore)(CTeam *); // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  CBasePlayer *v20; // edi
  CBasePlayer *v21; // eax
  int TeamNumber; // ebx
  bool v23; // cl
  int m_nValue; // eax
  CTeam *v25; // ebx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  char *v30; // eax
  int v31; // eax
  char *v32; // eax
  const char *v33; // eax
  int v34; // eax
  CBasePlayer *v35; // eax
  CBasePlayer *v36; // esi
  CTeam *Team; // eax
  char *NetworkIDString; // eax
  const char *v39; // eax
  bool v40; // zf
  CTeam *v41; // ebx
  char *v42; // eax
  int v43; // eax
  char *v44; // eax
  const char *v45; // eax
  CTeam *v46; // eax
  char *v47; // eax
  const char *v48; // eax
  int v49; // eax
  int v50; // eax
  char *v51; // eax
  const char *v52; // eax
  int v53; // eax
  CTeam *v54; // eax
  char *v55; // eax
  const char *v56; // eax
  int v57; // eax
  char *v58; // eax
  const char *v59; // eax
  int v60; // eax
  char *v61; // eax
  const char *v62; // eax
  int v63; // eax
  char *v64; // eax
  const char *v65; // eax
  int v66; // eax
  char *v67; // eax
  const char *v68; // eax
  int v69; // eax
  const char *v70; // eax
  char *v71; // eax
  const char *v72; // eax
  int v73; // eax
  char *v74; // eax
  const char *v75; // eax
  int v76; // [esp-34h] [ebp-54h]
  const char *v77; // [esp-30h] [ebp-50h]
  int v78; // [esp-2Ch] [ebp-4Ch]
  const char *v79; // [esp-2Ch] [ebp-4Ch]
  const char *v80; // [esp-28h] [ebp-48h]
  int v81; // [esp-24h] [ebp-44h]
  int v82; // [esp-24h] [ebp-44h]
  const char *v83; // [esp-20h] [ebp-40h]
  const char *v84; // [esp-20h] [ebp-40h]
  int v85; // [esp-1Ch] [ebp-3Ch]
  const char *v86; // [esp-1Ch] [ebp-3Ch]
  int v87; // [esp-1Ch] [ebp-3Ch]
  const char *v88; // [esp-1Ch] [ebp-3Ch]
  const char *v89; // [esp-18h] [ebp-38h]
  const char *v90; // [esp-18h] [ebp-38h]
  int v91; // [esp-14h] [ebp-34h]
  int v92; // [esp-14h] [ebp-34h]
  int v93; // [esp-10h] [ebp-30h]
  int v94; // [esp-10h] [ebp-30h]
  const char *v95; // [esp-10h] [ebp-30h]
  const char *v96; // [esp-Ch] [ebp-2Ch]
  int v97; // [esp-Ch] [ebp-2Ch]
  const char *v98; // [esp-Ch] [ebp-2Ch]
  int v99; // [esp-Ch] [ebp-2Ch]
  const char *v100; // [esp-Ch] [ebp-2Ch]
  int v101; // [esp-Ch] [ebp-2Ch]
  int v102; // [esp-Ch] [ebp-2Ch]
  int v103; // [esp-Ch] [ebp-2Ch]
  int v104; // [esp-8h] [ebp-28h]
  int v105; // [esp-8h] [ebp-28h]
  int v106; // [esp-8h] [ebp-28h]
  int v107; // [esp-8h] [ebp-28h]
  int v108; // [esp-8h] [ebp-28h]
  const char *v109; // [esp-8h] [ebp-28h]
  const char *v110; // [esp-8h] [ebp-28h]
  const char *v111; // [esp-8h] [ebp-28h]
  int v112; // [esp-8h] [ebp-28h]
  const char *v113; // [esp-8h] [ebp-28h]
  int v114; // [esp-8h] [ebp-28h]
  int v115; // [esp-8h] [ebp-28h]
  int v116; // [esp-8h] [ebp-28h]
  int v117; // [esp-8h] [ebp-28h]
  const char *v118; // [esp-8h] [ebp-28h]
  int v119; // [esp-8h] [ebp-28h]
  int v120; // [esp-4h] [ebp-24h]
  int v121; // [esp-4h] [ebp-24h]
  int v122; // [esp-4h] [ebp-24h]
  int v123; // [esp-4h] [ebp-24h]
  const char *v124; // [esp-4h] [ebp-24h]
  const char *v125; // [esp-4h] [ebp-24h]
  const char *v126; // [esp-4h] [ebp-24h]
  int v127; // [esp-4h] [ebp-24h]
  const char *v128; // [esp-4h] [ebp-24h]
  const char *v129; // [esp-4h] [ebp-24h]
  int v130; // [esp-4h] [ebp-24h]
  const char *v131; // [esp-4h] [ebp-24h]
  const char *v132; // [esp-4h] [ebp-24h]
  const char *v133; // [esp-4h] [ebp-24h]
  const char *v134; // [esp-4h] [ebp-24h]
  const char *v135; // [esp-4h] [ebp-24h]
  const char *v136; // [esp-4h] [ebp-24h]
  const char *v137; // [esp-4h] [ebp-24h]
  const char *v138; // [esp-4h] [ebp-24h]
  int attackerid; // [esp+Ch] [ebp-14h]
  CTeam *attackerida; // [esp+Ch] [ebp-14h]
  CTeam *v141; // [esp+10h] [ebp-10h]
  int v142; // [esp+10h] [ebp-10h]
  const char *weapon; // [esp+14h] [ebp-Ch]
  CBasePlayer *pAttacker; // [esp+18h] [ebp-8h]
  CBasePlayer *pAttackera; // [esp+18h] [ebp-8h]
  int userid; // [esp+1Ch] [ebp-4h]
  int headShot; // [esp+28h] [ebp+8h]
  const char *headShota; // [esp+28h] [ebp+8h]
  const char *headShotb; // [esp+28h] [ebp+8h]
  bool headShot_3; // [esp+2Bh] [ebp+Bh]

  v3 = event->GetName(this: event);
  v4 = _V_strlen(str: "round_end");
  if ( V_strncmp(s1: v3, s2: "round_end", count: v4) != 0 )
  {
    if ( V_strncmp(s1: v3, s2: "server_", count: 7) != 0 )
    {
      userid = event->GetInt(this: event, a2: "userid", a3: 0);
      v20 = UTIL_PlayerByUserId(userID: userid);
      if ( v20 != nullptr )
      {
        if ( v3 != "player_hurt" && _V_stricmp(s1: v3, s2: "player_hurt") != 0 )
        {
          v34 = _V_strlen(str: "player_death");
          if ( V_strncmp(s1: v3, s2: "player_death", count: v34) == 0 )
          {
            v142 = event->GetInt(this: event, a2: "attacker", a3: 0);
            pAttackera = (CBasePlayer *)event->GetString(this: event, a2: "weapon", a3: locale);
            headShot_3 = event->GetInt(this: event, a2: "headshot", a3: 0) == 1;
            v35 = UTIL_PlayerByUserId(userID: v142);
            v36 = v35;
            if ( v20 == v35 )
            {
              Team = CBaseEntity::GetTeam(this: v20);
              v108 = ((int (__thiscall *)(CTeam *, CBasePlayer *))Team->GetName)(a1: Team, a2: pAttackera);
              NetworkIDString = CBasePlayer::GetNetworkIDString(this: v20);
              v39 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, int))v20->GetPlayerName)(
                                    a1: v20,
                                    a2: userid,
                                    a3: NetworkIDString,
                                    a4: v108);
              UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" committed suicide with \"%s\"\n", v39, v94, v98, v109, v125);
              return 1;
            }
            else if ( v35 != nullptr )
            {
              v40 = !headShot_3;
              headShotb = " (headshot)";
              if ( v40 )
                headShotb = locale;
              v41 = CBaseEntity::GetTeam(this: v20);
              attackerida = CBaseEntity::GetTeam(this: v36);
              v99 = ((int (__thiscall *)(CTeam *, CBasePlayer *, const char *))v41->GetName)(
                      a1: v41,
                      a2: pAttackera,
                      a3: headShotb);
              v42 = CBasePlayer::GetNetworkIDString(this: v20);
              v43 = ((int (__thiscall *)(CBasePlayer *, int, char *, int))v20->GetPlayerName)(
                      a1: v20,
                      a2: userid,
                      a3: v42,
                      a4: v99);
              v87 = ((int (__thiscall *)(CTeam *, int))attackerida->GetName)(a1: attackerida, a2: v43);
              v44 = CBasePlayer::GetNetworkIDString(this: v36);
              v45 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, int))v36->GetPlayerName)(
                                    a1: v36,
                                    a2: v142,
                                    a3: v44,
                                    a4: v87);
              UTIL_LogPrintf(
                fmt: "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"%s\n",
                v45,
                v82,
                v84,
                v88,
                v90,
                v92,
                v95,
                v100,
                v110,
                v126);
              return 1;
            }
            else
            {
              v46 = CBaseEntity::GetTeam(this: v20);
              v127 = (int)v46->GetName(this: v46);
              v47 = CBasePlayer::GetNetworkIDString(this: v20);
              v48 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, int))v20->GetPlayerName)(
                                    a1: v20,
                                    a2: userid,
                                    a3: v47,
                                    a4: v127);
              UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" committed suicide with \"world\"\n", v48, v101, v111, v128);
              return 1;
            }
          }
          v49 = _V_strlen(str: "round_start");
          if ( V_strncmp(s1: v3, s2: "round_start", count: v49) == 0 )
          {
            UTIL_LogPrintf(fmt: "World triggered \"Round_Start\"\n");
            return 1;
          }
          v50 = _V_strlen(str: "hostage_follows");
          if ( V_strncmp(s1: v3, s2: "hostage_follows", count: v50) == 0 )
          {
            v51 = CBasePlayer::GetNetworkIDString(this: v20);
            v52 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v51);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><CT>\" triggered \"Touched_A_Hostage\"\n", v52, v112, v129);
            return 1;
          }
          v53 = _V_strlen(str: "hostage_killed");
          if ( V_strncmp(s1: v3, s2: "hostage_killed", count: v53) == 0 )
          {
            v54 = CBaseEntity::GetTeam(this: v20);
            v130 = (int)v54->GetName(this: v54);
            v55 = CBasePlayer::GetNetworkIDString(this: v20);
            v56 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, int))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v55,
                                  a4: v130);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" triggered \"Killed_A_Hostage\"\n", v56, v102, v113, v131);
            return 1;
          }
          v57 = _V_strlen(str: "hostage_rescued");
          if ( V_strncmp(s1: v3, s2: "hostage_rescued", count: v57) == 0 )
          {
            v58 = CBasePlayer::GetNetworkIDString(this: v20);
            v59 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v58);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><CT>\" triggered \"Rescued_A_Hostage\"\n", v59, v114, v132);
            return 1;
          }
          v60 = _V_strlen(str: "bomb_planted");
          if ( V_strncmp(s1: v3, s2: "bomb_planted", count: v60) == 0 )
          {
            v61 = CBasePlayer::GetNetworkIDString(this: v20);
            v62 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v61);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><TERRORIST>\" triggered \"Planted_The_Bomb\"\n", v62, v115, v133);
            return 1;
          }
          v63 = _V_strlen(str: "bomb_defused");
          if ( V_strncmp(s1: v3, s2: "bomb_defused", count: v63) == 0 )
          {
            v64 = CBasePlayer::GetNetworkIDString(this: v20);
            v65 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v64);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><CT>\" triggered \"Defused_The_Bomb\"\n", v65, v116, v134);
            return 1;
          }
          v66 = _V_strlen(str: "bomb_dropped");
          if ( V_strncmp(s1: v3, s2: "bomb_dropped", count: v66) == 0 )
          {
            v67 = CBasePlayer::GetNetworkIDString(this: v20);
            v68 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v67);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><TERRORIST>\" triggered \"Dropped_The_Bomb\"\n", v68, v117, v135);
            return 1;
          }
          v69 = _V_strlen(str: "bomb_begindefuse");
          if ( V_strncmp(s1: v3, s2: "bomb_begindefuse", count: v69) == 0 )
          {
            v40 = event->GetInt(this: event, a2: "haskit", a3: 0) == 1;
            v70 = "Begin_Bomb_Defuse_With_Kit";
            if ( !v40 )
              v70 = "Begin_Bomb_Defuse_Without_Kit";
            v136 = v70;
            v71 = CBasePlayer::GetNetworkIDString(this: v20);
            v72 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, const char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v71,
                                  a4: v136);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><CT>\" triggered \"%s\"\n", v72, v103, v118, v137);
            return 1;
          }
          v73 = _V_strlen(str: "bomb_pickup");
          if ( V_strncmp(s1: v3, s2: "bomb_pickup", count: v73) == 0 )
          {
            v74 = CBasePlayer::GetNetworkIDString(this: v20);
            v75 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *))v20->GetPlayerName)(
                                  a1: v20,
                                  a2: userid,
                                  a3: v74);
            UTIL_LogPrintf(fmt: "\"%s<%i><%s><TERRORIST>\" triggered \"Got_The_Bomb\"\n", v75, v119, v138);
            return 1;
          }
        }
        else
        {
          attackerid = event->GetInt(this: event, a2: "attacker", a3: 0);
          weapon = event->GetString(this: event, a2: "weapon", a3: locale);
          v21 = UTIL_PlayerByUserId(userID: attackerid);
          pAttacker = v21;
          if ( v21 != nullptr )
          {
            TeamNumber = CBaseEntity::GetTeamNumber(this: v21);
            v23 = CBaseEntity::GetTeamNumber(this: v20) == TeamNumber && v20 != pAttacker;
            if ( mp_logdetail.m_pParent != nullptr )
              m_nValue = mp_logdetail.m_pParent->m_Value.m_nValue;
            else
              LOBYTE(m_nValue) = 0;
            if ( v23 )
            {
              if ( (m_nValue & 2) == 0 )
                return 1;
            }
            else if ( (m_nValue & 1) == 0 )
            {
              return 1;
            }
            headShota = "GENERIC";
            switch ( event->GetInt(this: event, a2: "hitgroup", a3: 0) )
            {
              case 0:
                headShota = "generic";
                break;
              case 1:
                headShota = "head";
                break;
              case 2:
                headShota = "chest";
                break;
              case 3:
                headShota = "stomach";
                break;
              case 4:
                headShota = "left arm";
                break;
              case 5:
                headShota = "right arm";
                break;
              case 6:
                headShota = "left leg";
                break;
              case 7:
                headShota = "right leg";
                break;
              default:
                break;
            }
            v25 = CBaseEntity::GetTeam(this: v20);
            v141 = CBaseEntity::GetTeam(this: pAttacker);
            v26 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, const char *))event->GetInt)(
                    a1: event,
                    a2: "armor",
                    a3: 0,
                    a4: headShota);
            v27 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int))event->GetInt)(
                    a1: event,
                    a2: "health",
                    a3: 0,
                    a4: v26);
            v28 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int))event->GetInt)(
                    a1: event,
                    a2: "dmg_armor",
                    a3: 0,
                    a4: v27);
            v29 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int))event->GetInt)(
                    a1: event,
                    a2: "dmg_health",
                    a3: 0,
                    a4: v28);
            v85 = ((int (__thiscall *)(CTeam *, const char *, int))v25->GetName)(a1: v25, a2: weapon, a3: v29);
            v30 = CBasePlayer::GetNetworkIDString(this: v20);
            v31 = ((int (__thiscall *)(CBasePlayer *, int, char *, int))v20->GetPlayerName)(
                    a1: v20,
                    a2: userid,
                    a3: v30,
                    a4: v85);
            v78 = ((int (__thiscall *)(CTeam *, int))v141->GetName)(a1: v141, a2: v31);
            v32 = CBasePlayer::GetNetworkIDString(this: pAttacker);
            v33 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, int))pAttacker->GetPlayerName)(
                                  a1: pAttacker,
                                  a2: attackerid,
                                  a3: v32,
                                  a4: v78);
            UTIL_LogPrintf(
              fmt: "\"%s<%i><%s><%s>\" attacked \"%s<%i><%s><%s>\" with \"%s\" (damage \"%d\") (damage_armor \"%d\") (health \""
              "%d\") (armor \"%d\") (hitgroup \"%s\")\n",
              v33,
              v76,
              v77,
              v79,
              v80,
              v81,
              v83,
              v86,
              v89,
              v91,
              v93,
              v97,
              v107,
              v124);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  headShot = event->GetInt(this: event, a2: "winner", a3: 0);
  v5 = event->GetInt(this: event, a2: "reason", a3: 0);
  v6 = event->GetString(this: event, a2: "message", a3: locale) + 1;
  if ( v5 != 15 )
  {
    GlobalTeam = GetGlobalTeam(iIndex: 3);
    v8 = GetGlobalTeam(iIndex: 2);
    if ( headShot == 2 )
    {
      v14 = v8->GetScore(this: v8);
      v106 = ((int (__thiscall *)(CTeam *, int))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v14);
      v13 = (const char *)((int (__thiscall *)(CTeam *, const char *, int))v8->GetName)(a1: v8, a2: v6, a3: v106);
    }
    else
    {
      GetScore = v8->GetScore;
      if ( headShot != 3 )
      {
        v10 = ((int (__fastcall *)(CTeam *))GetScore)(a1: v8);
        v11 = ((int (__thiscall *)(CTeam *, int))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v10);
        UTIL_LogPrintf(fmt: "World triggered \"%s\" (CT \"%i\") (T \"%i\")\n", v6, v11, v120);
LABEL_9:
        v15 = GlobalTeam->GetNumPlayers(this: GlobalTeam);
        v16 = ((int (__thiscall *)(CTeam *, int))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v15);
        UTIL_LogPrintf(fmt: "Team \"CT\" scored \"%i\" with \"%i\" players\n", v16, v122);
        v17 = v8->GetNumPlayers(this: v8);
        v18 = ((int (__thiscall *)(CTeam *, int))v8->GetScore)(a1: v8, a2: v17);
        UTIL_LogPrintf(fmt: "Team \"TERRORIST\" scored \"%i\" with \"%i\" players\n", v18, v123);
        UTIL_LogPrintf(fmt: "World triggered \"Round_End\"\n");
        return 1;
      }
      v12 = ((int (__fastcall *)(CTeam *))GetScore)(a1: v8);
      v104 = ((int (__thiscall *)(CTeam *, int))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v12);
      v13 = (const char *)((int (__thiscall *)(CTeam *, const char *, int))GlobalTeam->GetName)(
                            a1: GlobalTeam,
                            a2: v6,
                            a3: v104);
    }
    UTIL_LogPrintf(fmt: "Team \"%s\" triggered \"%s\" (CT \"%i\") (T \"%i\")\n", v13, v96, v105, v121);
    goto LABEL_9;
  }
  UTIL_LogPrintf(fmt: "World triggered \"Game_Commencing\"\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026AC40
// Name: public: virtual bool CCSEventLog::PrintEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSEventLog::PrintEvent(CCSEventLog *this, IGameEvent *event)
{
  return CCSEventLog::PrintCStrikeEvent(this, event) != 0 || CEventLog::PrintEvent(this, event);
}

//------------------------------------------------------------------------------
// Address: 0x1026AC70
// Name: __CreateCServerGameTagsIServerGameTags_interface_9
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_9()
{
  return &_g_CServerGameTags_singleton_9;
}
