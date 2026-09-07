// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/client.cpp
// Functions: 56
// ============================================================

#include "game\server\client.h"

//------------------------------------------------------------------------------
// Address: 0x100EA400
// Name: void ClientPrecache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientPrecache()
{
  int i; // esi
  int j; // esi
  int k; // esi
  int m; // esi
  char pBuf[260]; // [esp+0h] [ebp-104h] BYREF

  ClientGamePrecache();
  if ( engine->IsDedicatedServerForXbox(this: engine) )
  {
    engine->ForceExactFile(this: engine, a2: "cfg/mem_level_360.ekv");
    engine->ForceExactFile(this: engine, a2: "cfg/gpu_mem_level_360.ekv");
    engine->ForceExactFile(this: engine, a2: "cfg/gpu_level_360.ekv");
    engine->ForceExactFile(this: engine, a2: "cfg/cpu_level_360.ekv");
    engine->ForceExactFile(this: engine, a2: "cfg/cpu_level_360_ss.ekv");
  }
  else
  {
    for ( i = 0; i < 3; ++i )
    {
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "cfg/cpu_level_%d_pc.ekv", i);
      engine->ForceExactFile(this: engine, a2: pBuf);
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "cfg/cpu_level_%d_pc_ss.ekv", i);
      engine->ForceExactFile(this: engine, a2: pBuf);
    }
    for ( j = 0; j < 4; ++j )
    {
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "cfg/gpu_level_%d_pc.ekv", j);
      engine->ForceExactFile(this: engine, a2: pBuf);
    }
    for ( k = 0; k < 3; ++k )
    {
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "cfg/mem_level_%d_pc.ekv", k);
      engine->ForceExactFile(this: engine, a2: pBuf);
    }
    for ( m = 0; m < 3; ++m )
    {
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "cfg/gpu_mem_level_%d_pc.ekv", m);
      engine->ForceExactFile(this: engine, a2: pBuf);
    }
  }
  engine->ForceExactFile(this: engine, a2: "scripts/instructor_lessons.txt");
  engine->ForceExactFile(this: engine, a2: "scripts/mod_lessons.txt");
}

//------------------------------------------------------------------------------
// Address: 0x100EA600
// Name: public: virtual struct datamap_t __near * CPointClientCommand::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointClientCommand::GetDataDescMap(CPointClientCommand *this)
{
  return &CPointClientCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA610
// Name: public: virtual struct datamap_t __near * CPointServerCommand::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointServerCommand::GetDataDescMap(CPointServerCommand *this)
{
  return &CPointServerCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA620
// Name: public: virtual struct datamap_t __near * CPointBroadcastClientCommand::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPointBroadcastClientCommand::GetDataDescMap(CPointBroadcastClientCommand *this)
{
  return &CPointBroadcastClientCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA630
// Name: char __near * CheckChatText(class CBasePlayer __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CheckChatText(CBasePlayer *pPlayer, char *text)
{
  char *v2; // edi
  int v3; // eax

  v2 = text;
  if ( text == nullptr || *text == 0 )
    return nullptr;
  v3 = _V_strlen(str: text);
  if ( *text == 34 )
  {
    v2 = text + 1;
    v3 -= 2;
    text[v3 + 1] = 0;
  }
  if ( v3 > 127 )
    text[127] = 0;
  g_pGameRules->CheckChatText(this: g_pGameRules, a2: pPlayer, a3: v2);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100EA690
// Name: public: virtual void ClientPrecachePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientPrecachePrecache::CResourcePrecacher::Cache(
        ClientPrecachePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  ConVar *m_pParent; // eax

  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "cable/cable.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "cable/cable_lit.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "cable/chain.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "cable/rope.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/blueglow1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/purpleglow1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/purplelaser1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  if ( !bIgnoreConditionals )
  {
    m_pParent = g_Language.m_pParent;
    if ( g_Language.m_pParent == nullptr )
      goto LABEL_7;
    if ( g_Language.m_pParent->m_Value.m_nValue == 1 )
    {
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: MODEL,
        a3: "models/germangibs.mdl",
        a4: bPrecache,
        a5: hResourceList,
        a6: nullptr);
      m_pParent = g_Language.m_pParent;
    }
    if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue != 1 )
LABEL_7:
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: MODEL,
        a3: "models/gibs/hgibs.mdl",
        a4: bPrecache,
        a5: hResourceList,
        a6: nullptr);
  }
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Error",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Hud.Hint",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.FallDamage",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.Swim",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.PickupWeapon",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.DenyWeaponSelection",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.WeaponSelected",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.WeaponSelectionClose",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Player.WeaponSelectionMoveSlot",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Glass",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Metal",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Flesh",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Wood",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Shrapnel",
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
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Shell",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Bounce.Concrete",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "BaseEntity.EnterWater",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "BaseEntity.ExitWater",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Instructor.LessonStart",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Instructor.ImportantLessonStart",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100EA910
// Name: void KillTargets(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KillTargets(const char *pKillTargetName)
{
  CBaseEntity *i; // esi
  const char *pszValue; // eax

  _DevMsg(a1: 2, a2: "KillTarget: %s\n", pKillTargetName);
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: pKillTargetName,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName: pKillTargetName,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr) )
  {
    UTIL_Remove(oldObj: i);
    pszValue = i->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(a1: 2, a2: "killing %s\n", pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA990
// Name: void ConsoleKillTarget(class CBasePlayer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConsoleKillTarget(CBasePlayer *pPlayer, const char *name)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi
  const char *DebugName; // eax

  if ( (name == locale || _V_stricmp(s1: name, s2: locale) == 0)
    && pPlayer != nullptr
    && (v2 = pPlayer->FindPickerEntity(this: pPlayer), v3 = v2, v2 != nullptr) )
  {
    UTIL_Remove(oldObj: v2);
    DebugName = CBaseEntity::GetDebugName(this: v3);
    _Msg(a1: "killing %s\n", DebugName);
  }
  else
  {
    KillTargets(pKillTargetName: name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAA00
// Name: public: void CPointServerCommand::InputCommand(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointServerCommand::InputCommand(CPointServerCommand *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  const char *v3; // eax
  IVEngineServer_vtbl *v4; // esi
  char *v5; // eax

  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      return;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( *pszValue != 0 )
  {
    if ( inputdata->value.fieldType == FIELD_STRING )
    {
      if ( inputdata->value.iVal != 0 )
        v3 = inputdata->value.iszVal.pszValue;
      else
        v3 = locale;
    }
    else
    {
      v3 = variant_t::ToString(this: &inputdata->value);
    }
    v4 = engine->__vftable;
    v5 = UTIL_VarArgs(format: "%s\n", v3);
    v4->ServerCommand(this: engine, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAA70
// Name: void CC_DrawLine(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DrawLine(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // esi
  Vector startPos; // [esp+4h] [ebp-18h] BYREF
  Vector endPos; // [esp+10h] [ebp-Ch] BYREF

  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  startPos.x = atof(nptr: v1);
  v2 = locale;
  if ( args->m_nArgc > 2 )
    v2 = args->m_ppArgv[2];
  startPos.y = atof(nptr: v2);
  v3 = locale;
  if ( args->m_nArgc > 3 )
    v3 = args->m_ppArgv[3];
  startPos.z = atof(nptr: v3);
  v4 = locale;
  if ( args->m_nArgc > 4 )
    v4 = args->m_ppArgv[4];
  endPos.x = atof(nptr: v4);
  v5 = locale;
  if ( args->m_nArgc > 5 )
    v5 = args->m_ppArgv[5];
  endPos.y = atof(nptr: v5);
  if ( args->m_nArgc > 6 )
    v6 = args->m_ppArgv[6];
  else
    v6 = locale;
  endPos.z = atof(nptr: v6);
  UTIL_AddDebugLine(&startPos, &endPos, noDepthTest: true, testLOS: true);
}

//------------------------------------------------------------------------------
// Address: 0x100EAB40
// Name: void CC_DrawCross(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_DrawCross(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  const char *v3; // esi
  long double v4; // st7
  float vPosition; // [esp+4h] [ebp-24h]
  float vPosition_4; // [esp+8h] [ebp-20h]
  Vector start; // [esp+10h] [ebp-18h] BYREF
  Vector end; // [esp+1Ch] [ebp-Ch] BYREF

  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  vPosition = atof(nptr: v1);
  v2 = locale;
  if ( args->m_nArgc > 2 )
    v2 = args->m_ppArgv[2];
  vPosition_4 = atof(nptr: v2);
  if ( args->m_nArgc > 3 )
    v3 = args->m_ppArgv[3];
  else
    v3 = locale;
  v4 = atof(nptr: v3);
  start.z = v4 - 5.0;
  start.x = vPosition - 5.0;
  end.z = v4 + 5.0;
  start.y = vPosition_4 - 5.0;
  end.x = vPosition + 5.0;
  end.y = vPosition_4 + 5.0;
  UTIL_AddDebugLine(startPos: &start, endPos: &end, noDepthTest: true, testLOS: true);
  start.x = start.x + 10.0;
  end.x = end.x - 10.0;
  UTIL_AddDebugLine(startPos: &start, endPos: &end, noDepthTest: true, testLOS: true);
  start.y = start.y + 10.0;
  end.y = end.y - 10.0;
  UTIL_AddDebugLine(startPos: &start, endPos: &end, noDepthTest: true, testLOS: true);
  start.x = start.x - 10.0;
  end.x = end.x + 10.0;
  UTIL_AddDebugLine(startPos: &start, endPos: &end, noDepthTest: true, testLOS: true);
}

//------------------------------------------------------------------------------
// Address: 0x100EACB0
// Name: buddha
// Source: json
//------------------------------------------------------------------------------
void __cdecl buddha()
{
  CBasePlayer *CommandClient; // esi
  int m_debugOverlays; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    m_debugOverlays = CommandClient->m_debugOverlays;
    if ( (m_debugOverlays & 0x2000000) != 0 )
    {
      CommandClient->m_debugOverlays = m_debugOverlays & 0xFDFFFFFF;
      _Msg(a1: "Buddha Mode off...\n");
    }
    else
    {
      CommandClient->m_debugOverlays = m_debugOverlays | 0x2000000;
      _Msg(a1: "Buddha Mode on...\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAD10
// Name: void CC_Player_SetModel(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Player_SetModel(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBaseEntity *v2; // esi
  const CViewVectors *v3; // eax
  Vector *p_m_vHullMax; // [esp-8h] [ebp-8h]

  if ( !gpGlobals->deathmatch )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) && args->m_nArgc == 2 )
    {
      V_snprintf(pDest: szName, maxLen: 256, pFormat: "models/%s.mdl", args->m_ppArgv[1]);
      v2->SetModel(this: v2, a2: szName);
      p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      UTIL_SetSize(pEnt: v2, vecMin: &v3->m_vHullMin, vecMax: p_m_vHullMax);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EADA0
// Name: void CC_Player_Use(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Player_Use(const CCommand *args)
{
  CBasePlayer *CommandClient; // esi

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( args->m_nArgc > 1 )
      CommandClient->SelectItem(this: CommandClient, a2: args->m_ppArgv[1], a3: 0);
    else
      CommandClient->SelectItem(this: CommandClient, a2: locale, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAE00
// Name: void EnableNoClip(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnableNoClip(CBasePlayer *pPlayer)
{
  void (__thiscall *NoClipStateChanged)(CBasePlayer *); // edx
  CEventLog *v2; // eax
  char *v3; // eax

  pPlayer->SetParent(this: pPlayer, a2: nullptr, a3: -1);
  CBaseEntity::SetMoveType(this: pPlayer, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
  ClientPrint(
    player: pPlayer,
    msg_dest: 2,
    msg_name: "noclip ON\n",
    param1: nullptr,
    param2: nullptr,
    param3: nullptr,
    param4: nullptr);
  NoClipStateChanged = pPlayer->NoClipStateChanged;
  pPlayer->m_iEFlags |= 4u;
  NoClipStateChanged(this: pPlayer);
  engine->SetNoClipEnabled(this: engine, a2: true);
  v2 = GameLogSystem();
  v3 = CEventLog::FormatPlayer(this: v2, ent: pPlayer);
  UTIL_LogPrintf(fmt: "%s entered NOCLIP mode\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x100EAE80
// Name: DescribeGroundList
// Source: json
//------------------------------------------------------------------------------
int __cdecl DescribeGroundList(CBaseEntity *ent)
{
  const char *pszValue; // eax
  const char *v5; // esi
  edict_t *m_pPev; // eax
  signed int v7; // edx
  const char *v8; // ecx
  edict_t *v9; // eax
  groundlink_t *DataObject; // eax
  groundlink_t *nextLink; // ecx
  unsigned int m_Index; // eax
  CBaseEntity **v13; // ecx
  CBaseEntity *v14; // esi
  const char *v15; // ecx
  signed int v16; // eax
  groundlink_t *root; // [esp+4h] [ebp-8h]
  groundlink_t *link; // [esp+8h] [ebp-4h]
  int c; // [esp+14h] [ebp+8h]

  if ( ent == nullptr )
    return 0;
  c = 1;
  if ( CBaseEntity::GetGroundEntity(this: ent) != nullptr )
  {
    pszValue = CBaseEntity::GetGroundEntity(this: ent)->m_iClassname.pszValue;
    if ( pszValue != nullptr )
      v5 = pszValue;
    else
      v5 = locale;
  }
  else
  {
    v5 = "NULL";
  }
  if ( CBaseEntity::GetGroundEntity(this: ent) != nullptr )
  {
    m_pPev = CBaseEntity::GetGroundEntity(this: ent)->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v7 = m_pPev - gpGlobals->pEdicts;
    else
      v7 = 0;
  }
  else
  {
    v7 = -1;
  }
  v8 = ent->m_iClassname.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  v9 = ent->m_Network.m_pPev;
  if ( v9 != nullptr )
    v9 -= (int)gpGlobals->pEdicts;
  _Msg(a1: "%i : %s (ground %i %s)\n", v9, v8, v7, v5);
  DataObject = (groundlink_t *)CBaseEntity::GetDataObject(this: ent, type: 0);
  root = DataObject;
  if ( DataObject != nullptr )
  {
    nextLink = DataObject->nextLink;
    link = nextLink;
    if ( nextLink != DataObject )
    {
      while ( 1 )
      {
        m_Index = nextLink->entity.m_Index;
        if ( nextLink->entity.m_Index != -1
          && (v13 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
              g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
          && (v14 = *v13, *v13 != nullptr) )
        {
          v15 = v14->m_iClassname.pszValue;
          if ( v15 == nullptr )
            v15 = locale;
          v16 = (signed int)v14->m_Network.m_pPev;
          if ( v16 != 0 )
            v16 = (signed int)(v16 - (unsigned int)gpGlobals->pEdicts) >> 4;
          _Msg(a1: "  %02i:  %i %s\n", c++, v16, v15);
          if ( CBaseEntity::GetGroundEntity(this: v14) != ent )
            _Msg(a1: "   mismatched!!!\n");
        }
        else
        {
          _Msg(a1: "  %02i:  NULL link\n", c++);
        }
        link = link->nextLink;
        if ( link == root )
          break;
        nextLink = link;
      }
    }
  }
  CBaseEntity::GetGroundEntity(this: ent);
  return c - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EB000
// Name: void CC_GroundList_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_GroundList_f(const CCommand *args)
{
  int v1; // eax
  CBaseEntity *v2; // eax
  CBaseEntity *i; // esi

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( args->m_nArgc == 2 )
    {
      v1 = atoi(nptr: args->m_ppArgv[1]);
      v2 = CBaseEntity::Instance(iEnt: v1);
      if ( v2 != nullptr )
        DescribeGroundList(ent: v2);
    }
    else
    {
      for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
            i != nullptr;
            i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
      {
        DescribeGroundList(ent: i);
      }
      _Msg(a1: "--- %i links\n", groundlinksallocated);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB090
// Name: void Host_Say(struct edict_t __near *,class CCommand const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Host_Say(int a1@<ebx>, edict_t *pEdict, const CCommand *args, BOOL teamonly)
{
  const char *v5; // edi
  int m_nArgv0Size; // eax
  bool v7; // zf
  const char *v8; // eax
  char *v9; // ebx
  int v10; // eax
  CBasePlayer *v11; // esi
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v13; // eax
  const char *v14; // ebx
  const char *v15; // edi
  signed int v16; // ecx
  char v17; // dl
  int i; // ebx
  CBasePlayer *v19; // edi
  edict_t *m_pPev; // eax
  CVoiceGameMgr *VoiceGameMgr; // eax
  const char *v22; // eax
  int v23; // edi
  char *NetworkIDString; // ebx
  CTeam *Team; // eax
  IGameEvent *v26; // esi
  edict_t *v27; // [esp-Ch] [ebp-244h]
  char szTemp[256]; // [esp+8h] [ebp-230h] BYREF
  char text[256]; // [esp+108h] [ebp-130h] BYREF
  CSingleUserRecipientFilter user; // [esp+208h] [ebp-30h] BYREF
  const char *pszPlayerName; // [esp+22Ch] [ebp-Ch]
  const char *pszFormat; // [esp+230h] [ebp-8h]
  const char *pszLocation; // [esp+234h] [ebp-4h]
  const char *p; // [esp+244h] [ebp+Ch]

  v5 = locale;
  if ( args->m_nArgc > 0 )
    v5 = args->m_ppArgv[0];
  if ( args->m_nArgc != 0 )
  {
    if ( _V_stricmp(s1: v5, s2: "say") != 0 && _V_stricmp(s1: v5, s2: "say_team") != 0 )
    {
      if ( args->m_nArgc < 2 )
      {
        V_snprintf(pDest: szTemp, maxLen: 256, pFormat: "%s", v5);
        v9 = szTemp;
        p = szTemp;
      }
      else
      {
        m_nArgv0Size = args->m_nArgv0Size;
        v7 = m_nArgv0Size == 0;
        v8 = &args->m_pArgSBuffer[m_nArgv0Size];
        if ( v7 )
          v8 = locale;
        V_snprintf(pDest: szTemp, maxLen: 256, pFormat: "%s %s", v5, v8);
        v9 = szTemp;
        p = szTemp;
      }
    }
    else
    {
      if ( args->m_nArgc < 2 )
        return;
      v10 = args->m_nArgv0Size;
      if ( v10 != 0 )
      {
        p = &args->m_pArgSBuffer[v10];
        v9 = &args->m_pArgSBuffer[v10];
      }
      else
      {
        p = locale;
        v9 = (char *)locale;
      }
    }
    v11 = nullptr;
    if ( pEdict != nullptr )
    {
      m_pUnk = pEdict->m_pUnk;
      if ( m_pUnk != nullptr )
        v13 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
      else
        v13 = nullptr;
      v11 = v13;
      p = CheckChatText(pPlayer: v13, text: v9);
      v9 = (char *)p;
    }
    if ( v9 != nullptr )
    {
      if ( pEdict == nullptr
        || v11->CanSpeak(this: v11)
        && (v11->CheckChatText(this: v11, a2: v9, a3: 127), (p = CheckChatText(pPlayer: v11, text: v9)) != nullptr) )
      {
        v14 = nullptr;
        v15 = nullptr;
        pszFormat = nullptr;
        pszLocation = nullptr;
        if ( g_pGameRules != nullptr )
        {
          pszFormat = g_pGameRules->GetChatFormat(this: g_pGameRules, a2: teamonly, a3: v11);
          v15 = g_pGameRules->GetChatPrefix(this: g_pGameRules, a2: teamonly, a3: v11);
          pszLocation = g_pGameRules->GetChatLocation(this: g_pGameRules, a2: teamonly, a3: v11);
          v14 = pszLocation;
        }
        if ( v11 != nullptr )
          pszPlayerName = v11->GetPlayerName(this: v11);
        else
          pszPlayerName = "Console";
        if ( v15 != nullptr && strlen(v15) != 0 )
        {
          if ( v14 != nullptr && strlen(v14) != 0 )
            V_snprintf(pDest: text, maxLen: 256, pFormat: "%s %s @ %s: ", v15, pszPlayerName, v14);
          else
            V_snprintf(pDest: text, maxLen: 256, pFormat: "%s %s: ", v15, pszPlayerName);
        }
        else
        {
          V_snprintf(pDest: text, maxLen: 256, pFormat: "%s: ", pszPlayerName);
        }
        v16 = 254 - strlen(text);
        if ( (int)strlen(p) > v16 )
          p[v16] = v17;
        V_strncat(pDest: text, pSrc: p, destBufferSize: 0x100u, max_chars_to_copy: -1);
        V_strncat(pDest: text, pSrc: "\n", destBufferSize: 0x100u, max_chars_to_copy: -1);
        for ( i = 1; i <= gpGlobals->maxClients; ++i )
        {
          v19 = UTIL_PlayerByIndex(playerIndex: i);
          if ( v19 != nullptr && v19->IsPlayer(this: v19) )
          {
            m_pPev = v19->m_Network.m_pPev;
            if ( m_pPev != nullptr
              && m_pPev != pEdict
              && v19->IsNetClient(this: v19)
              && (!teamonly || g_pGameRules->PlayerCanHearChat(this: g_pGameRules, a2: v19, a3: v11)) )
            {
              if ( v11 == nullptr
                || v19->CanHearAndReadChatFrom(this: v19, a2: v11)
                && (GetVoiceGameMgr() == nullptr
                 || (v27 = CBaseEntity::entindex(this: v11),
                     VoiceGameMgr = GetVoiceGameMgr(),
                     !CVoiceGameMgr::IsPlayerIgnoringPlayer(this: VoiceGameMgr, iTalker: (int)v27, iListener: i))) )
              {
                CSingleUserRecipientFilter::CSingleUserRecipientFilter(this: &user, player: v19);
                CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
                if ( pszFormat != nullptr )
                  UTIL_SayText2Filter(
                    filter: &user,
                    pEntity: v11,
                    bChat: true,
                    msg_name: pszFormat,
                    param1: pszPlayerName,
                    param2: p,
                    param3: pszLocation,
                    param4: nullptr);
                else
                  UTIL_SayTextFilter(filter: &user, pText: text, pPlayer: v11, bChat: true);
                CRecipientFilter::~CRecipientFilter(this: &user);
              }
            }
          }
        }
        if ( v11 != nullptr )
        {
          CRecipientFilter::CRecipientFilter(this: &user);
          user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
          CRecipientFilter::AddRecipient(this: &user, player: v11);
          CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
          if ( pszFormat != nullptr )
            UTIL_SayText2Filter(
              filter: &user,
              pEntity: v11,
              bChat: true,
              msg_name: pszFormat,
              param1: pszPlayerName,
              param2: p,
              param3: pszLocation,
              param4: nullptr);
          else
            UTIL_SayTextFilter(filter: &user, pText: text, pPlayer: v11, bChat: true);
          CRecipientFilter::~CRecipientFilter(this: &user);
        }
        if ( ((unsigned __int8 (__thiscall *)(IVEngineServer *, int))engine->IsDedicatedServer)(a1: engine, a2: a1) != 0 )
          _Msg(a1: "%s", text);
        v22 = "Console";
        v23 = 0;
        NetworkIDString = "Console";
        pszFormat = "Console";
        if ( v11 != nullptr )
        {
          v23 = engine->GetPlayerUserId(this: engine, a2: v11->m_Network.m_pPev);
          NetworkIDString = CBasePlayer::GetNetworkIDString(this: v11);
          pszLocation = v11->GetPlayerName(this: v11);
          Team = CBaseEntity::GetTeam(this: v11);
          if ( Team != nullptr )
            pszFormat = Team->GetName(this: Team);
          v22 = pszLocation;
        }
        if ( teamonly )
          UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" say_team \"%s\"\n", v22, v23, NetworkIDString, pszFormat, p);
        else
          UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" say \"%s\"\n", v22, v23, NetworkIDString, pszFormat, p);
        v26 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD))gameeventmanager->CreateEventA)(
                              a1: gameeventmanager,
                              a2: "player_say",
                              a3: 0);
        if ( v26 != nullptr )
        {
          v26->SetInt(this: v26, a2: "userid", a3: v23);
          v26->SetString(this: v26, a2: "text", a3: p);
          v26->SetInt(this: v26, a2: "priority", a3: 1);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v26, a3: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB5C0
// Name: cast_ray
// Source: json
//------------------------------------------------------------------------------
void __usercall cast_ray(int a1@<edi>)
{
  CBasePlayer *CommandClient; // esi
  CBaseEntity *m_pEnt; // ecx
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // eax
  CBaseEntity *v6; // ebx
  CBaseEntity *v7; // edi
  CBaseEntity *v8; // esi
  const char *pszValue; // eax
  int v10; // edi
  const char *v11; // eax
  int duration; // [esp+30h] [ebp-94h]
  CGameTrace tr; // [esp+40h] [ebp-84h] BYREF
  Vector forward; // [esp+94h] [ebp-30h] BYREF
  CBaseEntity *v16; // [esp+A0h] [ebp-24h]
  CBaseEntity *v17; // [esp+A4h] [ebp-20h]
  CBaseEntity *v18; // [esp+A8h] [ebp-1Ch]
  Vector start; // [esp+ACh] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+B8h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+C4h] [ebp+0h] BYREF

  CommandClient = UTIL_GetCommandClient();
  CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
  CommandClient->EyePosition(this: CommandClient, result: &start);
  vecAbsEnd.y = start.y + (float)(forward.y * 16384.0);
  vecAbsEnd.x = start.x + (float)(forward.x * 16384.0);
  vecAbsEnd.z = start.z + (float)(forward.z * 16384.0);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)CommandClient,
    vecAbsStart: &start,
    &vecAbsEnd,
    mask: 0x200400Bu,
    ignore: CommandClient,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction < 1.0 || tr.allsolid || tr.startsolid )
  {
    m_pEnt = tr.m_pEnt;
    v3 = (unsigned int)tr.m_pEnt->m_iEFlags >> 11;
    v18 = tr.m_pEnt;
    if ( (v3 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: tr.m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    v4 = (unsigned int)m_pEnt->m_iEFlags >> 11;
    v17 = m_pEnt;
    if ( (v4 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    v5 = (unsigned int)m_pEnt->m_iEFlags >> 11;
    v16 = m_pEnt;
    if ( (v5 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    v6 = m_pEnt;
    if ( (m_pEnt->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    v7 = m_pEnt;
    if ( (m_pEnt->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    v8 = m_pEnt;
    if ( (m_pEnt->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: m_pEnt, a2: (int)&savedregs);
      m_pEnt = tr.m_pEnt;
    }
    pszValue = m_pEnt->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(
      a1: 1,
      a2: "Hit %s\nposition %.2f, %.2f, %.2f\nangles %.2f, %.2f, %.2f\n",
      pszValue,
      v8->m_vecAbsOrigin.x,
      v7->m_vecAbsOrigin.y,
      v6->m_vecAbsOrigin.z,
      v16->m_angAbsRotation.x,
      v17->m_angAbsRotation.y,
      v18->m_angAbsRotation.z);
    v10 = ((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int))tr.m_pEnt->m_Collision.GetSolid)(
            a1: &tr.m_pEnt->m_Collision,
            a2: a1);
    v11 = (const char *)((int (__thiscall *)(IPhysicsSurfaceProps *, _DWORD, int))physprops->GetPropName)(
                          a1: physprops,
                          a2: tr.surface.surfaceProps,
                          a3: tr.contents);
    _DevMsg(
      a1: 1,
      a2: "Hit: hitbox %d, hitgroup %d, physics bone %d, solid %d, surface %s, surfaceprop %s, contents %08lx\n",
      tr.hitbox,
      tr.hitgroup,
      tr.physicsbone,
      v10,
      tr.surface.name,
      v11,
      duration);
    NDebugOverlay::Line(origin: &start, target: &tr.endpos, r: 0, g: 255, b: 0, noDepthTest: false, duration: 10.0);
    vecAbsEnd.y = tr.endpos.y + (float)(tr.plane.normal.y * 12.0);
    vecAbsEnd.x = tr.endpos.x + (float)(tr.plane.normal.x * 12.0);
    vecAbsEnd.z = tr.endpos.z + (float)(tr.plane.normal.z * 12.0);
    NDebugOverlay::Line(
      origin: &tr.endpos,
      target: &vecAbsEnd,
      r: 255,
      g: 255,
      b: 0,
      noDepthTest: false,
      duration: 10.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB8A0
// Name: cast_hull
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall cast_hull(float a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  CBasePlayer *CommandClient; // esi
  float v4; // xmm0_4
  float v5; // xmm1_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  CBaseEntity *v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // edx
  CBaseEntity *v12; // edi
  CBaseEntity *v13; // esi
  const char *pszValue; // eax
  int v15; // edi
  const char *v16; // eax
  float v18[4]; // [esp+54h] [ebp-10Ch] BYREF
  float v19; // [esp+64h] [ebp-FCh]
  float v20; // [esp+68h] [ebp-F8h]
  float v21; // [esp+6Ch] [ebp-F4h]
  float v22; // [esp+74h] [ebp-ECh]
  float v23; // [esp+78h] [ebp-E8h]
  float v24; // [esp+7Ch] [ebp-E4h]
  float v25; // [esp+84h] [ebp-DCh]
  float v26; // [esp+88h] [ebp-D8h]
  float v27; // [esp+8Ch] [ebp-D4h]
  int v28; // [esp+94h] [ebp-CCh]
  bool v29; // [esp+98h] [ebp-C8h]
  bool v30; // [esp+99h] [ebp-C7h]
  CTraceFilterSimple v31; // [esp+ACh] [ebp-B4h] BYREF
  Vector end; // [esp+BCh] [ebp-A4h] BYREF
  CGameTrace tr; // [esp+C8h] [ebp-98h] BYREF
  float v34; // [esp+11Ch] [ebp-44h]
  Vector forward; // [esp+120h] [ebp-40h]
  CBaseEntity *v36; // [esp+12Ch] [ebp-34h]
  Vector v37; // [esp+130h] [ebp-30h] BYREF
  Vector v38; // [esp+13Ch] [ebp-24h] BYREF
  Vector start; // [esp+148h] [ebp-18h] BYREF
  Vector extents; // [esp+154h] [ebp-Ch] BYREF
  float retaddr; // [esp+160h] [ebp+0h]

  extents.x = a1;
  extents.y = retaddr;
  CommandClient = UTIL_GetCommandClient();
  start.x = 16.0;
  start.y = 16.0;
  start.z = 16.0;
  CBasePlayer::EyeVectors(this: CommandClient, pForward: (Vector *)&tr.m_pEnt, pRight: nullptr, pUp: nullptr);
  ((void (__thiscall *)(CBasePlayer *, Vector *, int, int))CommandClient->EyePosition)(
    a1: CommandClient,
    a2: &v38,
    a3: a2,
    a4: a3);
  v20 = (float)(v38.y + (float)(*(float *)&tr.hitbox * 16384.0)) - v38.y;
  v19 = (float)(v38.x + (float)(*(float *)&tr.m_pEnt * 16384.0)) - v38.x;
  v21 = (float)(v38.z + (float)(v34 * 16384.0)) - v38.z;
  v28 = 0;
  v30 = (float)((float)((float)(v20 * v20) + (float)(v19 * v19)) + (float)(v21 * v21)) != 0.0;
  v25 = (float)(start.x - (float)-start.x) * 0.5;
  v26 = (float)(start.y - (float)-start.y) * 0.5;
  v27 = (float)(start.z - (float)-start.z) * 0.5;
  v29 = (float)((float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v27 * v27)) < 0.000001;
  v4 = (float)(start.x - start.x) * 0.5;
  v5 = (float)(start.z - start.z) * 0.5;
  v18[0] = v4 + v38.x;
  v18[1] = (float)((float)(start.y - start.y) * 0.5) + v38.y;
  v18[2] = v5 + v38.z;
  v22 = v4 * -1.0;
  v23 = (float)((float)(start.y - start.y) * 0.5) * -1.0;
  v24 = v5 * -1.0;
  CTraceFilterSimple::CTraceFilterSimple(
    this: &v31,
    passedict: CommandClient,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  TraceRay = enginetrace->TraceRay;
  LODWORD(start.z) = &end;
  ((void (__thiscall *)(IEngineTrace *, float *, int, CTraceFilterSimple *))TraceRay)(
    a1: enginetrace,
    a2: v18,
    a3: 33570827,
    a4: &v31);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &end, vecAbsEnd: &tr.startpos, r: 255, g: 255, b: 0, test: true, duration: -1.0);
  if ( tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
  {
    v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    v8 = *(_DWORD *)(*(_DWORD *)&tr.surface.surfaceProps + 196) >> 11;
    forward.z = *(float *)&tr.surface.surfaceProps;
    if ( (v8 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)&tr.surface.surfaceProps, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    v9 = (unsigned int)v7->m_iEFlags >> 11;
    v36 = v7;
    if ( (v9 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    v10 = (unsigned int)v7->m_iEFlags >> 11;
    LODWORD(forward.x) = v7;
    if ( (v10 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    v11 = (unsigned int)v7->m_iEFlags >> 11;
    LODWORD(forward.y) = v7;
    if ( (v11 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    v12 = v7;
    if ( (v7->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    v13 = v7;
    if ( (v7->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&extents);
      v7 = *(CBaseEntity **)&tr.surface.surfaceProps;
    }
    pszValue = v7->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(
      a1: 1,
      a2: "Hit %s\nposition %.2f, %.2f, %.2f\nangles %.2f, %.2f, %.2f\n",
      pszValue,
      v13->m_vecAbsOrigin.x,
      v12->m_vecAbsOrigin.y,
      *(float *)(LODWORD(forward.y) + 468),
      *(float *)(LODWORD(forward.x) + 472),
      v36->m_angAbsRotation.y,
      *(float *)(LODWORD(forward.z) + 480));
    v15 = (*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&tr.surface.surfaceProps + 228) + 44))(a1: *(_DWORD *)&tr.surface.surfaceProps + 228);
    v16 = physprops->GetPropName(this: physprops, a2: (__int16)tr.dispFlags);
    _DevMsg(
      a1: 1,
      a2: "Hit: hitbox %d, hitgroup %d, physics bone %d, solid %d, surface %s, surfaceprop %s\n",
      tr.hitgroup,
      tr.fractionleftsolid,
      SLOWORD(tr.surface.name),
      v15,
      (const char *)tr.contents,
      v16);
    NDebugOverlay::SweptBox(
      start: &v38,
      end: &tr.startpos,
      mins: &v37,
      maxs: &start,
      angles: COERCE_CONST_QANGLE_(-start.z),
      r: 0,
      g: 0,
      b: 255,
      a: 0,
      flDuration: 10.0);
    NDebugOverlay::Line(
      origin: (const Vector *)&v31.m_pPassEnt,
      target: &v37,
      r: 255,
      g: 255,
      b: 64,
      noDepthTest: false,
      duration: 10.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBDC0
// Name: class CBaseEntity __near * GetNextCommandEntity(class CBasePlayer __near *,char const __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl GetNextCommandEntity(CBasePlayer *pPlayer, const char *name, CBaseEntity *ent)
{
  int v4; // eax
  CBaseEntity *v5; // esi
  const char *pszValue; // eax
  const char *v7; // eax

  if ( pPlayer == nullptr )
    return nullptr;
  if ( name == locale || _V_stricmp(s1: name, s2: locale) == 0 )
  {
    if ( ent == nullptr )
      return pPlayer->FindPickerEntity(this: pPlayer);
    return nullptr;
  }
  v4 = atoi(nptr: name);
  if ( v4 != 0 )
  {
    if ( ent == nullptr )
      return CBaseEntity::Instance(iEnt: v4);
    return nullptr;
  }
  v5 = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: ent);
  if ( v5 == nullptr )
    return nullptr;
  while ( 1 )
  {
    pszValue = v5->m_iName.m_Value.pszValue;
    if ( pszValue != nullptr
      && (pszValue == name || CBaseEntity::NameMatchesComplex(this: v5, pszNameOrWildcard: name) != 0) )
    {
      break;
    }
    v7 = v5->m_iClassname.pszValue;
    if ( v7 != nullptr && (v7 == name || CBaseEntity::ClassMatchesComplex(this: v5, pszClassOrWildcard: name) != 0) )
      break;
    v5 = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: v5);
    if ( v5 == nullptr )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100EBE90
// Name: void SetDebugBits(class CBasePlayer __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetDebugBits(CBasePlayer *pPlayer, const char *name, int bit)
{
  CBaseEntity *Ent; // esi
  CBaseEntity *v4; // eax
  int m_debugOverlays; // eax
  int v6; // eax
  const char *pszValue; // eax
  const char *v8; // eax

  if ( pPlayer != nullptr )
  {
    Ent = nullptr;
    while ( name != locale && _V_stricmp(s1: name, s2: locale) != 0 )
    {
      v6 = atoi(nptr: name);
      if ( v6 != 0 )
      {
        if ( Ent != nullptr )
          return;
        v4 = CBaseEntity::Instance(iEnt: v6);
        goto LABEL_7;
      }
      Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
      if ( Ent == nullptr )
        return;
      while ( 1 )
      {
        pszValue = Ent->m_iName.m_Value.pszValue;
        if ( pszValue != nullptr
          && (pszValue == name || CBaseEntity::NameMatchesComplex(this: Ent, pszNameOrWildcard: name) != 0) )
        {
          break;
        }
        v8 = Ent->m_iClassname.pszValue;
        if ( v8 != nullptr && (v8 == name || CBaseEntity::ClassMatchesComplex(this: Ent, pszClassOrWildcard: name) != 0) )
          break;
        Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
        if ( Ent == nullptr )
          return;
      }
LABEL_8:
      if ( Ent == nullptr )
        return;
      m_debugOverlays = Ent->m_debugOverlays;
      if ( (m_debugOverlays & bit) != 0 )
        Ent->m_debugOverlays = m_debugOverlays & ~bit;
      else
        Ent->m_debugOverlays = bit | m_debugOverlays;
    }
    if ( Ent != nullptr )
      return;
    v4 = pPlayer->FindPickerEntity(this: pPlayer);
LABEL_7:
    Ent = v4;
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EBF90
// Name: public: void CPointClientCommand::InputCommand(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointClientCommand::InputCommand(CPointClientCommand *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  edict_t *v3; // esi
  edict_t *pEdicts; // eax
  void *v5; // eax
  const char *v6; // eax
  IVEngineServer_vtbl *v7; // edi
  char *v8; // eax

  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      return;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( *pszValue != 0 )
  {
    v3 = nullptr;
    if ( gpGlobals->maxClients == 1 )
    {
      if ( gpGlobals->pEdicts == nullptr )
        return;
      pEdicts = gpGlobals->pEdicts;
      if ( (pEdicts[1].m_fStateFlags & 2) != 0 )
        return;
      v3 = pEdicts + 1;
    }
    else
    {
      v5 = __RTDynamicCast(
             inptr: inputdata->pActivator,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CBasePlayer `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
        v3 = *((edict_t **)v5 + 6);
      if ( IsInCommentaryMode() )
      {
        if ( v3 != nullptr )
        {
LABEL_16:
          if ( v3->m_pUnk != nullptr )
          {
            if ( inputdata->value.fieldType == FIELD_STRING )
            {
              v6 = inputdata->value.iszVal.pszValue;
              if ( v6 == nullptr )
                v6 = locale;
            }
            else
            {
              v6 = variant_t::ToString(this: &inputdata->value);
            }
            v7 = engine->__vftable;
            v8 = UTIL_VarArgs(format: "%s\n", v6);
            v7->ClientCommand(this: engine, a2: v3, a3: v8);
          }
          return;
        }
        v3 = INDEXENT(iEdictNum: 1);
      }
    }
    if ( v3 == nullptr )
      return;
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC080
// Name: public: void CPointBroadcastClientCommand::InputCommand(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointBroadcastClientCommand::InputCommand(CPointBroadcastClientCommand *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  int v4; // esi
  CBasePlayer *v5; // eax
  edict_t *m_pPev; // edi
  const char *v7; // eax
  IVEngineServer_vtbl *v8; // esi
  char *v9; // eax
  int i; // [esp+Ch] [ebp+8h]

  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    pszValue = inputdata->value.iszVal.pszValue;
    if ( pszValue == nullptr )
      return;
  }
  else
  {
    pszValue = variant_t::ToString(this: &inputdata->value);
  }
  if ( *pszValue != 0 )
  {
    v4 = 1;
    for ( i = 1; v4 <= gpGlobals->maxClients; i = v4 )
    {
      v5 = UTIL_PlayerByIndex(playerIndex: v4);
      if ( v5 != nullptr )
      {
        m_pPev = v5->m_Network.m_pPev;
        if ( m_pPev != nullptr && m_pPev->m_pUnk != nullptr )
        {
          if ( inputdata->value.fieldType == FIELD_STRING )
          {
            v7 = inputdata->value.iszVal.pszValue;
            if ( v7 == nullptr )
              v7 = locale;
          }
          else
          {
            v7 = variant_t::ToString(this: &inputdata->value);
          }
          v8 = engine->__vftable;
          v9 = UTIL_VarArgs(format: "%s\n", v7);
          v8->ClientCommand(this: engine, a2: m_pPev, a3: v9);
          v4 = i;
        }
      }
      ++v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC140
// Name: void kill_helper(class CCommand const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl kill_helper(const CCommand *args, bool bVector, BOOL bExplode)
{
  int v4; // edi
  CBasePlayer *v5; // esi
  const char *v6; // eax
  CBasePlayer *CommandClient; // edi
  int v8; // ecx
  const char *v9; // eax
  int v10; // esi
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v14; // [esp-4h] [ebp-20h]
  Vector vecForce; // [esp+Ch] [ebp-10h] BYREF
  CBasePlayer *pPlayer; // [esp+18h] [ebp-4h]
  bool bKillOther_3; // [esp+27h] [ebp+Bh]

  v4 = 1;
  bKillOther_3 = args->m_nArgc > (bVector ? 4 : 1);
  if ( bKillOther_3 && sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    if ( gpGlobals->maxClients < 1 )
      return;
    while ( 1 )
    {
      v5 = UTIL_PlayerByIndex(playerIndex: v4);
      if ( v5 != nullptr && v5->IsPlayer(this: v5) )
      {
        pPlayer = v5;
        v14 = CCommand::operator[](this: args, nIndex: 1);
        v6 = v5->GetPlayerName(this: v5);
        if ( _V_strstr(s1: v6, search: v14) != nullptr )
          break;
      }
      if ( ++v4 > gpGlobals->maxClients )
        return;
    }
    CommandClient = pPlayer;
  }
  else
  {
    CommandClient = UTIL_GetCommandClient();
  }
  if ( CommandClient != nullptr )
  {
    if ( bVector )
    {
      v8 = bKillOther_3 + 1;
      if ( v8 >= args->m_nArgc )
        v9 = locale;
      else
        v9 = args->m_ppArgv[v8];
      vecForce.x = atof(nptr: v9);
      v10 = bKillOther_3 + 2;
      if ( v10 >= args->m_nArgc )
        v11 = locale;
      else
        v11 = args->m_ppArgv[v10];
      vecForce.y = atof(nptr: v11);
      v12 = bKillOther_3 + 3;
      if ( v12 >= args->m_nArgc )
        v13 = locale;
      else
        v13 = args->m_ppArgv[v12];
      vecForce.z = atof(nptr: v13);
      CommandClient->CommitSuicide(this: CommandClient, a2: &vecForce, a3: bExplode, a4: false);
    }
    else
    {
      CommandClient->CommitSuicide(this: CommandClient, a2: bExplode, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC2B0
// Name: kill
// Source: json
//------------------------------------------------------------------------------
void __cdecl kill(const CCommand *args)
{
  kill_helper(args, bVector: false, bExplode: false);
}

//------------------------------------------------------------------------------
// Address: 0x100EC2D0
// Name: explode
// Source: json
//------------------------------------------------------------------------------
void __cdecl explode(const CCommand *args)
{
  kill_helper(args, bVector: false, bExplode: true);
}

//------------------------------------------------------------------------------
// Address: 0x100EC2F0
// Name: killvector
// Source: json
//------------------------------------------------------------------------------
void __cdecl killvector(const CCommand *args)
{
  kill_helper(args, bVector: true, bExplode: false);
}

//------------------------------------------------------------------------------
// Address: 0x100EC310
// Name: explodevector
// Source: json
//------------------------------------------------------------------------------
void __cdecl explodevector(const CCommand *args)
{
  kill_helper(args, bVector: true, bExplode: true);
}

//------------------------------------------------------------------------------
// Address: 0x100EC330
// Name: say
// Source: json
//------------------------------------------------------------------------------
void __usercall say(int a1@<ebx>, const CCommand *args)
{
  CBasePlayer *CommandClient; // esi

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    if ( gpGlobals->curtime > CommandClient->m_fLastPlayerTalkTime + 0.66 )
    {
      Host_Say(a1, pEdict: CommandClient->m_Network.m_pPev, args, teamonly: false);
      CommandClient->m_fLastPlayerTalkTime = gpGlobals->curtime;
    }
  }
  else
  {
    Host_Say(a1, pEdict: nullptr, args, teamonly: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC3B0
// Name: say_team
// Source: json
//------------------------------------------------------------------------------
void __usercall say_team(int a1@<ebx>, const CCommand *args)
{
  CBasePlayer *CommandClient; // esi

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr
    && CommandClient->IsPlayer(this: CommandClient)
    && gpGlobals->curtime > CommandClient->m_fLastPlayerTalkTime + 0.66 )
  {
    Host_Say(a1, pEdict: CommandClient->m_Network.m_pPev, args, teamonly: true);
    CommandClient->m_fLastPlayerTalkTime = gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC420
// Name: give
// Source: json
//------------------------------------------------------------------------------
void __cdecl give(const CCommand *args)
{
  CBasePlayer *CommandClient; // esi
  const char *v2; // eax
  const char *pszValue; // eax
  char item_to_give[256]; // [esp+4h] [ebp-104h] BYREF
  string_t iszItem; // [esp+104h] [ebp-4h] BYREF

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr
    && CommandClient->IsPlayer(this: CommandClient)
    && (gpGlobals->maxClients == 1 || sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0)
    && args->m_nArgc >= 2 )
  {
    v2 = locale;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    V_strncpy(pDest: item_to_give, pSrc: v2, maxLen: 256);
    _V_strlower(start: item_to_give);
    if ( _V_stricmp(s1: item_to_give, s2: "item_suit") != 0 )
    {
      AllocPooledString(pszValue: (const char *)&iszItem);
      pszValue = iszItem.pszValue;
      if ( iszItem.pszValue == nullptr )
        pszValue = locale;
      CommandClient->GiveNamedItem(this: CommandClient, a2: pszValue, a3: 0, a4: true);
    }
    else
    {
      CommandClient->EquipSuit(this: CommandClient, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC510
// Name: void CC_Player_TestDispatchEffect(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Player_TestDispatchEffect(const CCommand *args)
{
  CBasePlayer *CommandClient; // edi
  int m_nArgc; // eax
  bool v3; // cc
  const char *v4; // eax
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  edict_t *m_pPev; // eax
  signed int v12; // eax
  const char *v13; // eax
  CGameTrace tr; // [esp+8h] [ebp-F8h] BYREF
  Vector vecForward; // [esp+5Ch] [ebp-A4h] BYREF
  CEffectData data; // [esp+68h] [ebp-98h] BYREF
  Vector vecSrc; // [esp+CCh] [ebp-34h] BYREF
  QAngle vecAngles; // [esp+D8h] [ebp-28h] BYREF
  Vector vecEnd; // [esp+E4h] [ebp-1Ch] BYREF
  float scale; // [esp+F0h] [ebp-10h]
  float flDistance; // [esp+F4h] [ebp-Ch]
  float magnitude; // [esp+F8h] [ebp-8h]
  float flags; // [esp+FCh] [ebp-4h]
  IHandleEntity savedregs; // [esp+100h] [ebp+0h] BYREF

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc >= 2 )
    {
      flDistance = 1024.0;
      if ( m_nArgc >= 3 )
      {
        v3 = m_nArgc <= 2;
        v4 = locale;
        if ( !v3 )
          v4 = args->m_ppArgv[2];
        flDistance = (float)atoi(nptr: v4);
      }
      v5 = args->m_nArgc;
      flags = 0.0;
      if ( v5 >= 4 )
      {
        v3 = v5 <= 3;
        v6 = locale;
        if ( !v3 )
          v6 = args->m_ppArgv[3];
        flags = (float)atoi(nptr: v6);
      }
      v7 = args->m_nArgc;
      magnitude = 0.0;
      if ( v7 >= 5 )
      {
        v3 = v7 <= 4;
        v8 = locale;
        if ( !v3 )
          v8 = args->m_ppArgv[4];
        magnitude = atof(nptr: v8);
      }
      v9 = args->m_nArgc;
      scale = 0.0;
      if ( v9 >= 6 )
      {
        v3 = v9 <= 5;
        v10 = locale;
        if ( !v3 )
          v10 = args->m_ppArgv[5];
        scale = atof(nptr: v10);
      }
      vecAngles = *CommandClient->EyeAngles(this: CommandClient);
      AngleVectors(angles: &vecAngles, forward: &vecForward);
      CommandClient->EyePosition(this: CommandClient, result: &vecSrc);
      vecEnd.y = vecSrc.y + (float)(vecForward.y * flDistance);
      vecEnd.x = vecSrc.x + (float)(vecForward.x * flDistance);
      vecEnd.z = vecSrc.z + (float)(vecForward.z * flDistance);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)args,
        vecAbsStart: &vecSrc,
        vecAbsEnd: &vecEnd,
        mask: 0xFFFFFFFF,
        ignore: CommandClient,
        collisionGroup: 0,
        ptr: &tr);
      memset((void *)&data.m_vStart, 0, 44);
      data.m_flScale = 1.0;
      memset(&data.m_flMagnitude, 0, 14);
      memset(&data.m_nMaterial, 0, 17);
      if ( tr.fraction >= 1.0 )
      {
        data.m_vOrigin = vecEnd;
        data.m_vAngles = vecAngles;
        AngleVectors(angles: &vecAngles, forward: &data.m_vNormal);
      }
      else
      {
        data.m_vOrigin = tr.endpos;
        VectorAngles(forward: &tr.plane.normal, angles: &data.m_vAngles);
        data.m_vNormal = tr.plane.normal;
      }
      m_pPev = CommandClient->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v12 = m_pPev - gpGlobals->pEdicts;
      else
        v12 = 0;
      v3 = args->m_nArgc <= 1;
      data.m_nEntIndex = v12;
      data.m_flMagnitude = magnitude;
      data.m_fFlags = (int)flags;
      data.m_flScale = scale;
      v13 = locale;
      if ( !v3 )
        v13 = args->m_ppArgv[1];
      PrecacheEffect(pEffectName: v13);
      if ( args->m_nArgc > 1 )
        DispatchEffect(pName: args->m_ppArgv[1], &data);
      else
        DispatchEffect(pName: locale, &data);
    }
    else
    {
      _Msg(a1: " Usage: test_dispatcheffect <effect name> <distance away> <flags> <magnitude> <scale>\n ");
      _Msg(a1: "\t\t defaults are: <distance 1024> <flags 0> <magnitude 0> <scale 0>\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC8A0
// Name: void CC_Player_BugBaitSwap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Player_BugBaitSwap()
{
  CBasePlayer *CommandClient; // edi
  CBaseCombatWeapon *ActiveWeapon; // esi
  CBasePlayer *v2; // eax
  const char *v3; // eax
  int v4; // eax
  CBasePlayer_vtbl *v5; // edx

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: CommandClient);
    if ( ActiveWeapon != nullptr )
    {
      v2 = UTIL_GetCommandClient();
      engine->ClientCommand(this: engine, a2: v2->m_Network.m_pPev, a3: "cancelselect");
      v3 = ActiveWeapon->GetName(this: ActiveWeapon);
      v4 = _V_stricmp(s1: v3, s2: "weapon_bugbait");
      v5 = CommandClient->__vftable;
      if ( v4 != 0 )
        v5->SelectItem(this: CommandClient, a2: "weapon_bugbait", a3: 0);
      else
        v5->SelectLastItem(this: CommandClient);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC930
// Name: bool TestEntityPosition(class CBaseEntity __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TestEntityPosition(CBaseEntity *pEntity, unsigned int mask)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  CGameTrace trace; // [esp+8h] [ebp-6Ch] BYREF
  Vector mins; // [esp+5Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+68h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  m_pPhysicsObject = pEntity->m_pPhysicsObject;
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( m_pPhysicsObject != nullptr )
  {
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
    pEntity->m_Collision.WorldSpaceSurroundingBounds(this: &pEntity->m_Collision, a2: &mins, a3: &maxs);
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)pEntity,
      vecAbsStart: &vec3_origin,
      vecAbsEnd: &vec3_origin,
      hullMin: &mins,
      hullMax: &maxs,
      mask,
      ignore: pEntity,
      collisionGroup: 0,
      ptr: &trace);
    return !trace.startsolid;
  }
  else
  {
    UTIL_TraceEntity(
      pEntity,
      vecAbsStart: &pEntity->m_vecAbsOrigin,
      vecAbsEnd: &pEntity->m_vecAbsOrigin,
      mask,
      ptr: &trace);
    return !trace.startsolid;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC9F0
// Name: FindPassableSpace
// Source: json
//------------------------------------------------------------------------------
int __usercall FindPassableSpace@<eax>(
        CBaseEntity *pEntity@<esi>,
        const Vector *direction@<edi>,
        unsigned int mask,
        float step,
        Vector *oldorigin)
{
  int v5; // ebx
  float v6; // xmm0_4
  float z; // ecx
  Vector origin; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v5 = 0;
  while ( 1 )
  {
    v6 = step;
    if ( (pEntity->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
      v6 = step;
    }
    z = pEntity->m_vecAbsOrigin.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&pEntity->m_vecAbsOrigin.x;
    origin.x = (float)(direction->x * v6) + origin.x;
    origin.y = (float)(direction->y * v6) + origin.y;
    origin.z = (float)(direction->z * v6) + z;
    CBaseEntity::SetAbsOrigin(this: pEntity, absOrigin: &origin);
    if ( TestEntityPosition(pEntity, mask) )
      break;
    if ( ++v5 >= 100 )
      return 0;
  }
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  *oldorigin = pEntity->m_vecAbsOrigin;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ECAE0
// Name: bool FindEmptySpace(class CBaseEntity __near *,unsigned int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindEmptySpace(
        CBaseEntity *pEntity,
        unsigned int mask,
        const Vector *forward,
        const Vector *right,
        const Vector *up,
        Vector *testOrigin)
{
  int result; // eax

  if ( FindPassableSpace(pEntity, direction: forward, mask, step: 1.0, oldorigin: testOrigin) != 0 )
    return 1;
  if ( FindPassableSpace(pEntity, direction: right, mask, step: 1.0, oldorigin: testOrigin) != 0 )
    return 1;
  if ( FindPassableSpace(pEntity, direction: right, mask, step: -1.0, oldorigin: testOrigin) != 0 )
    return 1;
  if ( FindPassableSpace(pEntity, direction: up, mask, step: 1.0, oldorigin: testOrigin) != 0 )
    return 1;
  if ( FindPassableSpace(pEntity, direction: up, mask, step: -1.0, oldorigin: testOrigin) != 0 )
    return 1;
  result = FindPassableSpace(pEntity, direction: forward, mask, step: -1.0, oldorigin: testOrigin);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ECBD0
// Name: void DisableNoClip(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableNoClip(CBasePlayer *pPlayer)
{
  float z; // ecx
  CEventLog *v2; // eax
  char *v3; // eax
  Vector forward; // [esp+4h] [ebp-30h] BYREF
  Vector right; // [esp+10h] [ebp-24h] BYREF
  Vector up; // [esp+1Ch] [ebp-18h] BYREF
  Vector oldorigin; // [esp+28h] [ebp-Ch] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  pPlayer->m_iEFlags &= ~4u;
  CBaseEntity::SetMoveType(this: pPlayer, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
  ClientPrint(
    player: pPlayer,
    msg_dest: 2,
    msg_name: "noclip OFF\n",
    param1: nullptr,
    param2: nullptr,
    param3: nullptr,
    param4: nullptr);
  if ( (pPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
  z = pPlayer->m_vecAbsOrigin.z;
  *(_QWORD *)&oldorigin.x = *(_QWORD *)&pPlayer->m_vecAbsOrigin.x;
  oldorigin.z = z;
  if ( noclip_fixup.m_pParent != nullptr
    && noclip_fixup.m_pParent->m_Value.m_nValue != 0
    && !TestEntityPosition(pEntity: pPlayer, mask: 0x201400Bu) )
  {
    AngleVectors(angles: &pPlayer->pl.v_angle, &forward, &right, &up);
    if ( (unsigned __int8)FindEmptySpace(
                            pEntity: pPlayer,
                            mask: 0x201400Bu,
                            &forward,
                            &right,
                            &up,
                            testOrigin: &oldorigin) == 0 )
      _Msg(a1: "Can't find the world\n");
    CBaseEntity::SetAbsOrigin(this: pPlayer, absOrigin: &oldorigin);
  }
  pPlayer->NoClipStateChanged(this: pPlayer);
  engine->SetNoClipEnabled(this: engine, a2: false);
  v2 = GameLogSystem();
  v3 = CEventLog::FormatPlayer(this: v2, ent: pPlayer);
  UTIL_LogPrintf(fmt: "%s left NOCLIP mode\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x100ECCE0
// Name: noclip
// Source: json
//------------------------------------------------------------------------------
void __cdecl noclip(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  const char *v3; // eax

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc < 2 )
      {
        if ( v2->m_MoveType.m_Value != 8 )
        {
LABEL_10:
          EnableNoClip(pPlayer: v2);
          return;
        }
        goto LABEL_14;
      }
      v3 = locale;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      if ( V_atoi(str: v3) != 0 )
      {
        if ( v2->m_MoveType.m_Value == 8 )
          return;
        goto LABEL_10;
      }
      if ( v2->m_MoveType.m_Value == 8 )
LABEL_14:
        DisableNoClip(pPlayer: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECD90
// Name: void CC_God_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_God_f()
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v1; // esi

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v1 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      CBaseEntity::ToggleFlag(this: v1, flagToToggle: 0x8000);
      if ( (v1->m_fFlags.m_Value & 0x8000) != 0 )
        ClientPrint(
          player: v1,
          msg_dest: 2,
          msg_name: "godmode ON\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      else
        ClientPrint(
          player: v1,
          msg_dest: 2,
          msg_name: "godmode OFF\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECE10
// Name: ent_setpos
// Source: json
//------------------------------------------------------------------------------
void __cdecl ent_setpos(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  const char *v3; // eax
  int v4; // esi
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // edi
  const char *v7; // eax
  bool v8; // cc
  const char *v9; // eax
  const char *v10; // eax
  double z; // xmm0_8
  Vector newpos; // [esp+0h] [ebp-18h] BYREF
  Vector oldorigin; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    LODWORD(oldorigin.z) = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 4 )
      {
        v3 = locale;
        if ( args->m_nArgc > 1 )
          v3 = args->m_ppArgv[1];
        v4 = V_atoi(str: v3);
        v5 = CBaseEntity::Instance(iEnt: v4);
        v6 = v5;
        if ( v5 != nullptr )
        {
          if ( (v5->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
          v8 = args->m_nArgc <= 2;
          oldorigin = v6->m_vecAbsOrigin;
          v9 = locale;
          if ( !v8 )
            v9 = args->m_ppArgv[2];
          newpos.x = atof(nptr: v9);
          v10 = locale;
          if ( args->m_nArgc > 3 )
            v10 = args->m_ppArgv[3];
          newpos.y = atof(nptr: v10);
          if ( args->m_nArgc == 5 )
          {
            *(double *)&oldorigin.y = atof(nptr: args->m_ppArgv[4]);
            z = *(double *)&oldorigin.y;
          }
          else
          {
            z = oldorigin.z;
          }
          newpos.z = z;
          CBaseEntity::SetAbsOrigin(this: v6, absOrigin: &newpos);
        }
        else
        {
          v7 = UTIL_VarArgs(format: "ent_setpos no entity %d\n", v4);
          ClientPrint(
            player: (CBasePlayer *)LODWORD(oldorigin.z),
            msg_dest: 2,
            msg_name: v7,
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        }
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  ent_setpos index x y <optional z>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECF80
// Name: ent_setang
// Source: json
//------------------------------------------------------------------------------
void __cdecl ent_setang(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  const char *v3; // eax
  int v4; // esi
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // edi
  const char *v7; // eax
  bool v8; // cc
  const char *v9; // eax
  const char *v10; // eax
  double z; // xmm0_8
  QAngle newAng; // [esp+0h] [ebp-18h] BYREF
  QAngle old; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    LODWORD(old.z) = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 4 )
      {
        v3 = locale;
        if ( args->m_nArgc > 1 )
          v3 = args->m_ppArgv[1];
        v4 = V_atoi(str: v3);
        v5 = CBaseEntity::Instance(iEnt: v4);
        v6 = v5;
        if ( v5 != nullptr )
        {
          if ( (v5->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v5, a2: (int)&savedregs);
          v8 = args->m_nArgc <= 2;
          old = v6->m_angAbsRotation;
          v9 = locale;
          if ( !v8 )
            v9 = args->m_ppArgv[2];
          newAng.x = atof(nptr: v9);
          v10 = locale;
          if ( args->m_nArgc > 3 )
            v10 = args->m_ppArgv[3];
          newAng.y = atof(nptr: v10);
          if ( args->m_nArgc == 5 )
          {
            *(double *)&old.y = atof(nptr: args->m_ppArgv[4]);
            z = *(double *)&old.y;
          }
          else
          {
            z = old.z;
          }
          newAng.z = z;
          CBaseEntity::SetAbsAngles(this: v6, absAngles: &newAng);
        }
        else
        {
          v7 = UTIL_VarArgs(format: "ent_setang no entity %d\n", v4);
          ClientPrint(
            player: (CBasePlayer *)LODWORD(old.z),
            msg_dest: 2,
            msg_name: v7,
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        }
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  ent_setang index pitch yaw <optional roll>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED0F0
// Name: setpos
// Source: json
//------------------------------------------------------------------------------
void __cdecl setpos(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  bool v3; // cc
  float z; // edx
  const char *v5; // eax
  const char *v6; // eax
  double v7; // xmm0_8
  Vector newpos; // [esp+0h] [ebp-18h] BYREF
  Vector oldorigin; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 3 )
      {
        if ( (v2->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
        v3 = args->m_nArgc <= 1;
        z = v2->m_vecAbsOrigin.z;
        *(_QWORD *)&oldorigin.x = *(_QWORD *)&v2->m_vecAbsOrigin.x;
        oldorigin.z = z;
        v5 = locale;
        if ( !v3 )
          v5 = args->m_ppArgv[1];
        newpos.x = atof(nptr: v5);
        v6 = locale;
        if ( args->m_nArgc > 2 )
          v6 = args->m_ppArgv[2];
        newpos.y = atof(nptr: v6);
        if ( args->m_nArgc == 4 )
        {
          *(double *)&oldorigin.y = atof(nptr: args->m_ppArgv[3]);
          v7 = *(double *)&oldorigin.y;
        }
        else
        {
          v7 = oldorigin.z;
        }
        newpos.z = v7;
        CBaseEntity::SetAbsOrigin(this: v2, absOrigin: &newpos);
        if ( !TestEntityPosition(pEntity: v2, mask: 0x201400Bu) )
          ClientPrint(
            player: v2,
            msg_dest: 2,
            msg_name: "setpos into world, use noclip to unstick yourself!\n",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  setpos x y <z optional>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED230
// Name: setpos_player
// Source: json
//------------------------------------------------------------------------------
void __cdecl setpos_player(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  const char *v3; // eax
  int v4; // eax
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  bool v7; // cc
  float z; // edx
  const char *v9; // eax
  const char *v10; // eax
  double v11; // xmm0_8
  Vector newpos; // [esp+0h] [ebp-18h] BYREF
  Vector oldorigin; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 4 )
      {
        v3 = locale;
        if ( args->m_nArgc > 1 )
          v3 = args->m_ppArgv[1];
        v4 = atoi(nptr: v3);
        v5 = UTIL_PlayerByIndex(playerIndex: v4);
        v6 = v5;
        if ( v5 != nullptr && v5->IsPlayer(this: v5) )
        {
          if ( (v6->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
          v7 = args->m_nArgc <= 2;
          z = v6->m_vecAbsOrigin.z;
          *(_QWORD *)&oldorigin.x = *(_QWORD *)&v6->m_vecAbsOrigin.x;
          oldorigin.z = z;
          v9 = locale;
          if ( !v7 )
            v9 = args->m_ppArgv[2];
          newpos.x = atof(nptr: v9);
          v10 = locale;
          if ( args->m_nArgc > 3 )
            v10 = args->m_ppArgv[3];
          newpos.y = atof(nptr: v10);
          if ( args->m_nArgc == 5 )
          {
            *(double *)&oldorigin.y = atof(nptr: args->m_ppArgv[4]);
            v11 = *(double *)&oldorigin.y;
          }
          else
          {
            v11 = oldorigin.z;
          }
          newpos.z = v11;
          CBaseEntity::SetAbsOrigin(this: v6, absOrigin: &newpos);
          if ( !TestEntityPosition(pEntity: v6, mask: 0x201400Bu) )
            ClientPrint(
              player: v6,
              msg_dest: 2,
              msg_name: "setpos into world, use noclip to unstick yourself!\n",
              param1: nullptr,
              param2: nullptr,
              param3: nullptr,
              param4: nullptr);
        }
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  setpos player_index x y <z optional>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED3B0
// Name: void CC_setang_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_setang_f(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  bool v3; // cc
  float z; // edx
  const char *v5; // eax
  const char *v6; // eax
  double v7; // xmm0_8
  QAngle newang; // [esp+0h] [ebp-18h] BYREF
  QAngle oldang; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 3 )
      {
        if ( (v2->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
        v3 = args->m_nArgc <= 1;
        z = v2->m_angAbsRotation.z;
        *(_QWORD *)&oldang.x = *(_QWORD *)&v2->m_angAbsRotation.x;
        oldang.z = z;
        v5 = locale;
        if ( !v3 )
          v5 = args->m_ppArgv[1];
        newang.x = atof(nptr: v5);
        v6 = locale;
        if ( args->m_nArgc > 2 )
          v6 = args->m_ppArgv[2];
        newang.y = atof(nptr: v6);
        if ( args->m_nArgc == 4 )
        {
          *(double *)&oldang.y = atof(nptr: args->m_ppArgv[3]);
          v7 = *(double *)&oldang.y;
        }
        else
        {
          v7 = oldang.z;
        }
        newang.z = v7;
        CBasePlayer::SnapEyeAngles(this: v2, viewAngles: &newang);
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  setang pitch yaw <roll optional>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED4C0
// Name: setpos_exact
// Source: json
//------------------------------------------------------------------------------
void __cdecl setpos_exact(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  bool v3; // cc
  float z; // edx
  const char *v5; // eax
  const char *v6; // eax
  double v7; // xmm0_8
  Vector newpos; // [esp+0h] [ebp-18h] BYREF
  Vector oldorigin; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 3 )
      {
        if ( (v2->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
        v3 = args->m_nArgc <= 1;
        z = v2->m_vecAbsOrigin.z;
        *(_QWORD *)&oldorigin.x = *(_QWORD *)&v2->m_vecAbsOrigin.x;
        oldorigin.z = z;
        v5 = locale;
        if ( !v3 )
          v5 = args->m_ppArgv[1];
        newpos.x = atof(nptr: v5);
        v6 = locale;
        if ( args->m_nArgc > 2 )
          v6 = args->m_ppArgv[2];
        newpos.y = atof(nptr: v6);
        if ( args->m_nArgc == 4 )
        {
          *(double *)&oldorigin.y = atof(nptr: args->m_ppArgv[3]);
          v7 = *(double *)&oldorigin.y;
        }
        else
        {
          v7 = oldorigin.z;
        }
        newpos.z = v7;
        v2->Teleport(this: v2, a2: &newpos, a3: nullptr, a4: nullptr, a5: true);
        if ( !TestEntityPosition(pEntity: v2, mask: 0x201400Bu) && v2->m_MoveType.m_Value != 8 )
          EnableNoClip(pPlayer: v2);
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  setpos_exact x y <z optional>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED600
// Name: setang_exact
// Source: json
//------------------------------------------------------------------------------
void __cdecl setang_exact(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v2; // esi
  bool v3; // cc
  float z; // edx
  const char *v5; // eax
  const char *v6; // eax
  double v7; // xmm0_8
  QAngle newang; // [esp+0h] [ebp-18h] BYREF
  QAngle oldang; // [esp+Ch] [ebp-Ch]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      if ( args->m_nArgc >= 3 )
      {
        if ( (v2->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
        v3 = args->m_nArgc <= 1;
        z = v2->m_angAbsRotation.z;
        *(_QWORD *)&oldang.x = *(_QWORD *)&v2->m_angAbsRotation.x;
        oldang.z = z;
        v5 = locale;
        if ( !v3 )
          v5 = args->m_ppArgv[1];
        newang.x = atof(nptr: v5);
        v6 = locale;
        if ( args->m_nArgc > 2 )
          v6 = args->m_ppArgv[2];
        newang.y = atof(nptr: v6);
        if ( args->m_nArgc == 4 )
        {
          *(double *)&oldang.y = atof(nptr: args->m_ppArgv[3]);
          v7 = *(double *)&oldang.y;
        }
        else
        {
          v7 = oldang.z;
        }
        newang.z = v7;
        v2->Teleport(this: v2, a2: nullptr, a3: &newang, a4: nullptr, a5: true);
        CBasePlayer::SnapEyeAngles(this: v2, viewAngles: &newang);
      }
      else
      {
        ClientPrint(
          player: v2,
          msg_dest: 2,
          msg_name: "Usage:  setang_exact pitch yaw <roll optional>\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED730
// Name: void CC_Notarget_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Notarget_f()
{
  CBasePlayer *CommandClient; // eax
  CBasePlayer *v1; // esi

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v1 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) && !gpGlobals->deathmatch )
    {
      CBaseEntity::ToggleFlag(this: v1, flagToToggle: 0x10000);
      if ( (v1->m_fFlags.m_Value & 0x10000) != 0 )
        ClientPrint(
          player: v1,
          msg_dest: 2,
          msg_name: "notarget ON\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      else
        ClientPrint(
          player: v1,
          msg_dest: 2,
          msg_name: "notarget OFF\n",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED7B0
// Name: void CC_HurtMe_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_HurtMe_f(const CCommand *args)
{
  CBasePlayer *CommandClient; // eax
  CBaseEntity *v2; // esi
  int v3; // eax
  const char *v4; // eax
  const CTakeDamageInfo *v5; // eax
  CTakeDamageInfo v6; // [esp+14h] [ebp-5Ch] BYREF

  if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
  {
    CommandClient = UTIL_GetCommandClient();
    v2 = CommandClient;
    if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
    {
      v3 = 10;
      if ( args->m_nArgc >= 2 )
      {
        v4 = locale;
        if ( args->m_nArgc > 1 )
          v4 = args->m_ppArgv[1];
        v3 = atoi(nptr: v4);
      }
      v5 = CTakeDamageInfo::CTakeDamageInfo(
             this: &v6,
             pInflictor: v2,
             pAttacker: v2,
             flDamage: (float)v3,
             bitsDamageType: 2048,
             iKillType: 0,
             iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this: v2, a2: (int)v2, inputInfo: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED840
// Name: void ClientCommand(class CBasePlayer __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientCommand(CBasePlayer *pPlayer, color32_s args)
{
  const CCommand *v2; // ebx
  const char *v3; // esi
  const char *v5; // eax
  const char *v6; // eax
  CBaseEntity *EntityByClassname; // esi
  CBaseEntity *v8; // edi
  const char *v9; // ecx
  const char *v10; // eax
  const Vector *v11; // eax
  const char *(__thiscall *GetPlayerName)(CBaseEntity *); // edx
  const char *v13; // eax
  char *v14; // eax
  const char *v15; // [esp-8h] [ebp-12Ch]
  const QAngle *fadeTime; // [esp+0h] [ebp-124h]
  const char *fadeHold; // [esp+4h] [ebp-120h]
  const char *v18; // [esp+8h] [ebp-11Ch]
  CFmtStrN<256> str; // [esp+18h] [ebp-10Ch] BYREF
  IMDLCache *cacheCriticalSection; // [esp+12Ch] [ebp+8h]

  v2 = (const CCommand *)args;
  v3 = locale;
  if ( **(int **)&args > 0 )
    v3 = *(const char **)(*(_DWORD *)&args + 1032);
  if ( pPlayer != nullptr )
  {
    cacheCriticalSection = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    if ( v3 == "killtarget" || _V_stricmp(s1: v3, s2: "killtarget") == 0 )
    {
      if ( g_pDeveloper->m_pParent != nullptr
        && g_pDeveloper->m_pParent->m_Value.m_nValue != 0
        && sv_cheats->m_pParent != nullptr
        && sv_cheats->m_pParent->m_Value.m_nValue != 0
        && UTIL_IsCommandIssuedByServerAdmin() )
      {
        v5 = locale;
        if ( v2->m_nArgc > 1 )
          v5 = v2->m_ppArgv[1];
        ConsoleKillTarget(pPlayer, name: v5);
        cacheCriticalSection->EndLock(this: cacheCriticalSection);
        return;
      }
      goto LABEL_44;
    }
    if ( v3 == "demorestart" || _V_stricmp(s1: v3, s2: "demorestart") == 0 )
    {
      pPlayer->ForceClientDllUpdate(this: pPlayer);
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
      return;
    }
    if ( v3 == "fade" || _V_stricmp(s1: v3, s2: "fade") == 0 )
    {
      args = (color32_s)-932954336;
      UTIL_ScreenFade(pEntity: pPlayer, color: &args, fadeTime: 3.0, fadeHold: 3.0, flags: 2);
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
      return;
    }
    if ( v3 != "te" && _V_stricmp(s1: v3, s2: "te") != 0 )
    {
      if ( FStrEq(sz1: v3, sz2: "bugpause") )
      {
        GetPlayerName = pPlayer->GetPlayerName;
        str.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
        *(_WORD *)&str.m_bQuietTruncation = 1;
        str.m_nLength = 0;
        v13 = GetPlayerName(this: pPlayer);
        v14 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
                this: &str,
                pszFormat: "BUG REPORTER ACTIVATED BY: %s\n",
                v13);
        UTIL_ClientPrintAll(
          msg_dest: 3,
          msg_name: v14,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        engine->Pause(this: engine, a2: true, a3: true);
        cacheCriticalSection->EndLock(this: cacheCriticalSection);
        return;
      }
      if ( FStrEq(sz1: v3, sz2: "bugunpause") )
      {
        engine->Pause(this: engine, a2: false, a3: true);
        cacheCriticalSection->EndLock(this: cacheCriticalSection);
        return;
      }
      if ( !g_pGameRules->ClientCommand(this: g_pGameRules, a2: pPlayer, a3: v2) )
      {
        if ( _V_strlen(str: v3) <= 128 )
        {
          v15 = UTIL_VarArgs(format: "Unknown command: %s\n", v3);
          ClientPrint(
            player: pPlayer,
            msg_dest: 2,
            msg_name: v15,
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        }
        else
        {
          ClientPrint(
            player: pPlayer,
            msg_dest: 2,
            msg_name: "Console command too long.\n",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        }
      }
      goto LABEL_44;
    }
    if ( sv_cheats->m_pParent == nullptr
      || sv_cheats->m_pParent->m_Value.m_nValue == 0
      || !UTIL_IsCommandIssuedByServerAdmin() )
    {
LABEL_44:
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
      return;
    }
    v6 = locale;
    if ( v2->m_nArgc > 1 )
      v6 = v2->m_ppArgv[1];
    if ( FStrEq(sz1: v6, sz2: "stop") )
    {
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: nullptr,
                            szName: "te_tester");
      if ( EntityByClassname != nullptr )
      {
        do
        {
          v8 = CGlobalEntityList::FindEntityByClassname(
                 this: &gEntList,
                 pStartEntity: EntityByClassname,
                 szName: "te_tester");
          UTIL_Remove(oldObj: EntityByClassname);
          EntityByClassname = v8;
        }
        while ( v8 != nullptr );
      }
      goto LABEL_44;
    }
    v9 = locale;
    if ( v2->m_nArgc > 2 )
      v9 = v2->m_ppArgv[2];
    v10 = locale;
    if ( v2->m_nArgc > 1 )
      v10 = v2->m_ppArgv[1];
    v18 = v9;
    fadeHold = v10;
    fadeTime = pPlayer->EyeAngles(this: pPlayer);
    v11 = pPlayer->WorldSpaceCenter(this: pPlayer);
    CTempEntTester::Create(vecOrigin: v11, vecAngles: fadeTime, lifetime: fadeHold, single_te: v18);
    cacheCriticalSection->EndLock(this: cacheCriticalSection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400CE0
// Name: ClientPrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ClientPrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  ClientPrecachePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&ClientPrecachePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400D60
// Name: CPointClientCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointClientCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointClientCommand>();
  CPointClientCommand_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400D90
// Name: CPointServerCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointServerCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointServerCommand>();
  CPointServerCommand_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400DC0
// Name: CPointBroadcastClientCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPointBroadcastClientCommand_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPointBroadcastClientCommand>();
  CPointBroadcastClientCommand_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400D00
// Name: _dynamic_initializer_for__cast_ray_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cast_ray_command__()
{
  ConCommand::ConCommand(
    this: &cast_ray_command,
    pName: "cast_ray",
    callback: (void (__cdecl *)())cast_ray,
    pHelpString: "Tests collision detection",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cast_ray_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400D30
// Name: _dynamic_initializer_for__cast_hull_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cast_hull_command__()
{
  ConCommand::ConCommand(
    this: &cast_hull_command,
    pName: "cast_hull",
    callback: (void (__cdecl *)())cast_hull,
    pHelpString: "Tests hull collision detection",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cast_hull_command__);
}
