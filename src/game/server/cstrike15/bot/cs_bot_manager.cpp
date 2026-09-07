// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_manager.cpp
// Functions: 158
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_manager.h"

//------------------------------------------------------------------------------
// Address: 0x102B2860
// Name: public: float ShortestPathCost::operator()(class CNavArea __near *,class CNavArea __near *,class CNavLadder const __near *,class CFuncElevator const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ShortestPathCost::operator()(
        ShortestPathCost *this,
        CNavArea *area,
        CNavArea *fromArea,
        const CNavLadder *ladder,
        const CFuncElevator *elevator,
        float length)
{
  float m_length; // xmm0_4
  float v8; // xmm0_4
  int m_attributeFlags; // ecx
  float v10; // xmm1_4
  float v11; // [esp-4h] [ebp-10h]

  if ( fromArea == nullptr )
    return 0.0;
  if ( ladder != nullptr )
  {
    m_length = ladder->m_length;
  }
  else
  {
    m_length = length;
    if ( length <= 0.0 )
    {
      v8 = area->m_center.x - fromArea->m_center.x;
      m_length = fsqrt(
                   (float)((float)((float)(area->m_center.y - fromArea->m_center.y)
                                 * (float)(area->m_center.y - fromArea->m_center.y))
                         + (float)((float)(area->m_center.z - fromArea->m_center.z)
                                 * (float)(area->m_center.z - fromArea->m_center.z)))
                 + (float)(v8 * v8));
    }
  }
  m_attributeFlags = area->m_attributeFlags;
  v10 = fromArea->m_costSoFar + m_length;
  v11 = v10;
  if ( (m_attributeFlags & 1) != 0 )
  {
    v10 = v10 + (float)(m_length * 20.0);
    v11 = v10;
  }
  if ( (m_attributeFlags & 2) != 0 )
  {
    v10 = v10 + (float)(m_length * 5.0);
    v11 = v10;
  }
  if ( gpGlobals->tickcount <= area->m_damagingTickCount )
    return (float)((float)(m_length * 100.0) + v10);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x102B2970
// Name: void RemoveBotControl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveBotControl()
{
  if ( TheBots != nullptr )
    ((void (__thiscall *)(CBotManager *, int))TheBots->dtr_CBotManager)(a1: TheBots, a2: 1);
  TheBots = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102B2990
// Name: class CBasePlayer __near * ClientPutInServerOverride_Bot(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__cdecl ClientPutInServerOverride_Bot(edict_t *pEdict, const char *playername)
{
  CBasePlayer *result; // eax
  CBasePlayer *v3; // esi

  CBasePlayer::s_PlayerEdict = pEdict;
  result = TheBots->AllocateBotEntity(this: TheBots);
  v3 = result;
  if ( result != nullptr )
  {
    CBasePlayer::SetPlayerName(this: result, name: playername);
    result = v3;
  }
  ++g_nClientPutInServerOverrides;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B29D0
// Name: void UTIL_DrawBox(struct Extent __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_DrawBox(Extent *extent, int lifetime, int red, int green, int blue)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float z; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  int *v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  float v17; // xmm0_4
  _DWORD *v18; // eax
  bool v19; // zf
  _DWORD v20[3]; // [esp+4h] [ebp-88h] BYREF
  Vector v[8]; // [esp+10h] [ebp-7Ch]
  Vector from; // [esp+70h] [ebp-1Ch] BYREF
  Vector to; // [esp+7Ch] [ebp-10h] BYREF
  int i; // [esp+88h] [ebp-4h]
  char restart_3; // [esp+97h] [ebp+Bh]

  x = extent->lo.x;
  y = extent->lo.y;
  v7 = extent->hi.x;
  v8 = extent->hi.y;
  v[0].z = extent->lo.z;
  v[1].z = v[0].z;
  v[2].z = v[0].z;
  v[3].z = v[0].z;
  z = extent->hi.z;
  v[0].x = x;
  v[0].y = y;
  v[1].x = v7;
  v[1].y = y;
  v[2].x = v7;
  v[2].y = v8;
  v[3].x = x;
  v[3].y = v8;
  v[4].x = x;
  v[4].y = y;
  v[4].z = z;
  v[5].x = v7;
  v[5].y = y;
  v[5].z = z;
  v[6].x = v7;
  v[6].y = v8;
  v[6].z = z;
  v[7].x = x;
  v[7].y = v8;
  v[7].z = z;
  restart_3 = 1;
  i = 0;
  if ( edge[0] != 0 )
  {
    v10 = to.z;
    v11 = to.y;
    v12 = to.x;
    v13 = edge;
    do
    {
      v14 = *v13;
      if ( restart_3 != 0 )
      {
        v15 = 3 * v14;
        v12 = *(float *)&v20[v15];
        v11 = *(float *)&v20[v15 + 1];
        v10 = *(float *)&v20[v15 + 2];
        restart_3 = 0;
      }
      else
      {
        from.x = v12;
        from.y = v11;
        from.z = v10;
        if ( v14 < 0 )
        {
          restart_3 = 1;
          v14 = -v14;
        }
        v16 = 3 * v14;
        v17 = *(float *)&v20[v16];
        v18 = &v20[v16];
        to.x = v17;
        to.y = (float)v18[1];
        to.z = (float)v18[2];
        NDebugOverlay::Line(
          origin: &from,
          target: &to,
          r: red / 2,
          g: green / 2,
          b: blue / 2,
          noDepthTest: 1,
          duration: 0.1);
        NDebugOverlay::Line(origin: &from, target: &to, r: red, g: green, b: blue, noDepthTest: 0, duration: 0.15000001);
        v10 = to.z;
        v11 = to.y;
        v12 = to.x;
      }
      v19 = edge[++i] == 0;
      v13 = &edge[i];
    }
    while ( !v19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2BC0
// Name: public: virtual void CCSBotManager::ServerDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::ServerDeactivate(CCSBotManager *this)
{
  this->m_serverActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x102B2BD0
// Name: bot_knives_only
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl bot_knives_only()
{
  unsigned int v0; // [esp-38h] [ebp-38h]
  CGameTrace *v1; // [esp-34h] [ebp-34h]
  unsigned int v2; // [esp-30h] [ebp-30h]
  CGameTrace *v3; // [esp-2Ch] [ebp-2Ch]
  unsigned int v4; // [esp-28h] [ebp-28h]
  CGameTrace *v5; // [esp-24h] [ebp-24h]
  unsigned int v6; // [esp-20h] [ebp-20h]
  CGameTrace *v7; // [esp-1Ch] [ebp-1Ch]
  unsigned int v8; // [esp-18h] [ebp-18h]
  CGameTrace *v9; // [esp-14h] [ebp-14h]
  unsigned int v10; // [esp-10h] [ebp-10h]
  CGameTrace *v11; // [esp-Ch] [ebp-Ch]
  unsigned int v12; // [esp-8h] [ebp-8h]
  CGameTrace *v13; // [esp-4h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_pistols.IConVar,
      value: 0,
      fContentsMask: v0,
      tr: v1);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_shotguns.IConVar,
      value: 0,
      fContentsMask: v2,
      tr: v3);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_sub_machine_guns.IConVar,
      value: 0,
      fContentsMask: v4,
      tr: v5);
    CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_allow_rifles.IConVar, value: 0, fContentsMask: v6, tr: v7);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_machine_guns.IConVar,
      value: 0,
      fContentsMask: v8,
      tr: v9);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_grenades.IConVar,
      value: 0,
      fContentsMask: v10,
      tr: v11);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_snipers.IConVar,
      value: 0,
      fContentsMask: v12,
      tr: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2C30
// Name: bot_pistols_only
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl bot_pistols_only()
{
  unsigned int v0; // [esp-38h] [ebp-38h]
  CGameTrace *v1; // [esp-34h] [ebp-34h]
  unsigned int v2; // [esp-30h] [ebp-30h]
  CGameTrace *v3; // [esp-2Ch] [ebp-2Ch]
  unsigned int v4; // [esp-28h] [ebp-28h]
  CGameTrace *v5; // [esp-24h] [ebp-24h]
  unsigned int v6; // [esp-20h] [ebp-20h]
  CGameTrace *v7; // [esp-1Ch] [ebp-1Ch]
  unsigned int v8; // [esp-18h] [ebp-18h]
  CGameTrace *v9; // [esp-14h] [ebp-14h]
  unsigned int v10; // [esp-10h] [ebp-10h]
  CGameTrace *v11; // [esp-Ch] [ebp-Ch]
  unsigned int v12; // [esp-8h] [ebp-8h]
  CGameTrace *v13; // [esp-4h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_pistols.IConVar,
      value: 1,
      fContentsMask: v0,
      tr: v1);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_shotguns.IConVar,
      value: 0,
      fContentsMask: v2,
      tr: v3);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_sub_machine_guns.IConVar,
      value: 0,
      fContentsMask: v4,
      tr: v5);
    CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_allow_rifles.IConVar, value: 0, fContentsMask: v6, tr: v7);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_machine_guns.IConVar,
      value: 0,
      fContentsMask: v8,
      tr: v9);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_grenades.IConVar,
      value: 0,
      fContentsMask: v10,
      tr: v11);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_snipers.IConVar,
      value: 0,
      fContentsMask: v12,
      tr: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2C90
// Name: bot_snipers_only
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl bot_snipers_only()
{
  unsigned int v0; // [esp-38h] [ebp-38h]
  CGameTrace *v1; // [esp-34h] [ebp-34h]
  unsigned int v2; // [esp-30h] [ebp-30h]
  CGameTrace *v3; // [esp-2Ch] [ebp-2Ch]
  unsigned int v4; // [esp-28h] [ebp-28h]
  CGameTrace *v5; // [esp-24h] [ebp-24h]
  unsigned int v6; // [esp-20h] [ebp-20h]
  CGameTrace *v7; // [esp-1Ch] [ebp-1Ch]
  unsigned int v8; // [esp-18h] [ebp-18h]
  CGameTrace *v9; // [esp-14h] [ebp-14h]
  unsigned int v10; // [esp-10h] [ebp-10h]
  CGameTrace *v11; // [esp-Ch] [ebp-Ch]
  unsigned int v12; // [esp-8h] [ebp-8h]
  CGameTrace *v13; // [esp-4h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_pistols.IConVar,
      value: 0,
      fContentsMask: v0,
      tr: v1);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_shotguns.IConVar,
      value: 0,
      fContentsMask: v2,
      tr: v3);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_sub_machine_guns.IConVar,
      value: 0,
      fContentsMask: v4,
      tr: v5);
    CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_allow_rifles.IConVar, value: 0, fContentsMask: v6, tr: v7);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_machine_guns.IConVar,
      value: 0,
      fContentsMask: v8,
      tr: v9);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_grenades.IConVar,
      value: 0,
      fContentsMask: v10,
      tr: v11);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_snipers.IConVar,
      value: 1,
      fContentsMask: v12,
      tr: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2CF0
// Name: bot_all_weapons
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl bot_all_weapons()
{
  unsigned int v0; // [esp-38h] [ebp-38h]
  CGameTrace *v1; // [esp-34h] [ebp-34h]
  unsigned int v2; // [esp-30h] [ebp-30h]
  CGameTrace *v3; // [esp-2Ch] [ebp-2Ch]
  unsigned int v4; // [esp-28h] [ebp-28h]
  CGameTrace *v5; // [esp-24h] [ebp-24h]
  unsigned int v6; // [esp-20h] [ebp-20h]
  CGameTrace *v7; // [esp-1Ch] [ebp-1Ch]
  unsigned int v8; // [esp-18h] [ebp-18h]
  CGameTrace *v9; // [esp-14h] [ebp-14h]
  unsigned int v10; // [esp-10h] [ebp-10h]
  CGameTrace *v11; // [esp-Ch] [ebp-Ch]
  unsigned int v12; // [esp-8h] [ebp-8h]
  CGameTrace *v13; // [esp-4h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_pistols.IConVar,
      value: 1,
      fContentsMask: v0,
      tr: v1);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_shotguns.IConVar,
      value: 1,
      fContentsMask: v2,
      tr: v3);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_sub_machine_guns.IConVar,
      value: 1,
      fContentsMask: v4,
      tr: v5);
    CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_allow_rifles.IConVar, value: 1, fContentsMask: v6, tr: v7);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_machine_guns.IConVar,
      value: 1,
      fContentsMask: v8,
      tr: v9);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_grenades.IConVar,
      value: 1,
      fContentsMask: v10,
      tr: v11);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&cv_bot_allow_snipers.IConVar,
      value: 1,
      fContentsMask: v12,
      tr: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2D50
// Name: BotGotoArea
// Source: json
//------------------------------------------------------------------------------
void __cdecl BotGotoArea(CNavArea *pArea)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  CCSBot *v4; // eax

  if ( pArea != nullptr )
  {
    v1 = 1;
    if ( gpGlobals->maxClients >= 1 )
    {
      while ( 1 )
      {
        v2 = UTIL_PlayerByIndex(playerIndex: v1);
        v3 = v2;
        if ( v2 != nullptr && v2->IsBot(this: v2) )
          break;
        if ( ++v1 > gpGlobals->maxClients )
          return;
      }
      v4 = (CCSBot *)__RTDynamicCast(
                       inptr: v3,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v4 != nullptr )
        CCSBot::MoveTo(this: v4, pos: &pArea->m_center, route: FASTEST_ROUTE);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2DD0
// Name: bot_goto_mark
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_goto_mark()
{
  CNavArea *MarkedArea; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    MarkedArea = CNavMesh::GetMarkedArea(this: TheNavMesh);
    BotGotoArea(pArea: MarkedArea);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2DF0
// Name: bot_goto_selected
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_goto_selected()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    BotGotoArea(pArea: TheNavMesh->m_selectedArea);
}

//------------------------------------------------------------------------------
// Address: 0x102B2E10
// Name: int UTIL_CSSBotsInGame(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_CSSBotsInGame()
{
  int v0; // esi
  int i; // edi
  CBasePlayer *v2; // eax

  v0 = 1;
  for ( i = 0; v0 <= gpGlobals->maxClients; ++v0 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v0);
    if ( __RTDynamicCast(
           inptr: v2,
           VfDelta: 0,
           SrcType: &CBasePlayer `RTTI Type Descriptor',
           TargetType: &CCSBot `RTTI Type Descriptor',
           isReference: 0) != nullptr )
      ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102B2E60
// Name: bool UTIL_CSSKickBotFromTeam(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl UTIL_CSSKickBotFromTeam(int kickTeam)
{
  CGlobalVars *v1; // eax
  int v2; // edi
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // esi
  int v5; // edi
  CBasePlayer *v6; // eax
  CBaseEntity *v7; // eax
  IVEngineServer_vtbl *v9; // edi
  const char *v10; // eax
  char *v11; // eax

  v1 = gpGlobals;
  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
  {
LABEL_6:
    v5 = 1;
    if ( v1->maxClients < 1 )
      return 0;
    while ( 1 )
    {
      v6 = UTIL_PlayerByIndex(playerIndex: v5);
      v7 = (CBaseEntity *)__RTDynamicCast(
                            inptr: v6,
                            VfDelta: 0,
                            SrcType: &CBasePlayer `RTTI Type Descriptor',
                            TargetType: &CCSBot `RTTI Type Descriptor',
                            isReference: 0);
      v4 = v7;
      if ( v7 != nullptr && CBaseEntity::GetTeamNumber(this: v7) == kickTeam )
        break;
      if ( ++v5 > gpGlobals->maxClients )
        return 0;
    }
    v9 = engine->__vftable;
  }
  else
  {
    while ( 1 )
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = (CBaseEntity *)__RTDynamicCast(
                            inptr: v3,
                            VfDelta: 0,
                            SrcType: &CBasePlayer `RTTI Type Descriptor',
                            TargetType: &CCSBot `RTTI Type Descriptor',
                            isReference: 0);
      if ( v4 != nullptr && !v4->IsAlive(this: v4) && CBaseEntity::GetTeamNumber(this: v4) == kickTeam )
        break;
      v1 = gpGlobals;
      if ( ++v2 > gpGlobals->maxClients )
        goto LABEL_6;
    }
    v9 = engine->__vftable;
  }
  v10 = v4->GetPlayerName(this: v4);
  v11 = UTIL_VarArgs(format: "kick \"%s\"\n", v10);
  v9->ServerCommand(this: engine, a2: v11);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B2F70
// Name: public: struct CCSBotManager::Zone const __near * CCSBotManager::GetZone(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CCSBotManager::Zone *__thiscall CCSBotManager::GetZone(CCSBotManager *this, const Vector *pos)
{
  int m_zoneCount; // esi
  int v3; // edx
  float x; // xmm1_4
  float *i; // eax
  float y; // xmm0_4
  float z; // xmm0_4

  m_zoneCount = this->m_zoneCount;
  v3 = 0;
  if ( m_zoneCount <= 0 )
    return nullptr;
  x = pos->x;
  for ( i = &this->m_zone[0].m_extent.lo.y; ; i += 30 )
  {
    if ( x >= *(i - 1) && i[2] >= x )
    {
      y = pos->y;
      if ( y >= *i && i[3] >= y )
      {
        z = pos->z;
        if ( z >= i[1] && i[4] >= z )
          break;
      }
    }
    if ( ++v3 >= m_zoneCount )
      return nullptr;
  }
  return &this->m_zone[v3];
}

//------------------------------------------------------------------------------
// Address: 0x102B31F0
// Name: public: class CNavArea __near * CCSBotManager::GetRandomAreaInZone(struct CCSBotManager::Zone const __near *)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CNavArea *__thiscall CCSBotManager::GetRandomAreaInZone(CCSBotManager *this, const CCSBotManager::Zone *zone)
{
  int m_areaCount; // ebx
  CNavArea *result; // eax
  int v4; // edx
  IUniformRandomStream *v5; // ecx
  int i; // esi
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  int v8; // eax
  CNavArea **v9; // edx
  int v10; // edi
  int v11; // esi
  int m_attributeFlags; // ecx
  CNavArea **zonea; // [esp+Ch] [ebp+8h]

  m_areaCount = zone->m_areaCount;
  if ( m_areaCount == 0 )
    return nullptr;
  v4 = 0;
  if ( m_areaCount <= 0 )
    return nullptr;
  zonea = zone->m_area;
  v5 = (IUniformRandomStream *)zonea;
  for ( i = m_areaCount; i != 0; --i )
  {
    RandomFloat = v5->__vftable[5].RandomFloat;
    if ( ((unsigned __int8)RandomFloat & 2) == 0 )
    {
      if ( (char)RandomFloat >= 0 )
        v4 += 20;
      else
        ++v4;
    }
    ++v5;
  }
  if ( v4 == 0 )
    return nullptr;
  v8 = _RandomInt(this: v5, a2: 1, a3: v4);
  v9 = zonea;
  v10 = v8;
  v11 = 0;
  while ( 1 )
  {
    result = *v9;
    m_attributeFlags = (*v9)->m_attributeFlags;
    if ( (m_attributeFlags & 2) == 0 )
    {
      if ( (m_attributeFlags & 0x80u) == 0 )
        v10 -= 20;
      else
        --v10;
    }
    if ( v10 <= 0 )
      break;
    ++v11;
    ++v9;
    if ( v11 >= m_areaCount )
      return *zonea;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B3280
// Name: public: virtual void CCSBotManager::OnServerShutdown(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnServerShutdown(CCSBotManager *this, IGameEvent *event)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  IBaseFileSystem *v4; // eax
  unsigned int i; // edi
  const char *v6; // esi
  ConVar *v7; // eax
  const char *m_pszString; // eax
  IBaseFileSystem *v9; // eax

  if ( !engine->IsDedicatedServer(this: engine) )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "ServerConfig");
      if ( v3 != nullptr )
      {
        if ( filesystem != nullptr )
          v4 = &filesystem->IBaseFileSystem;
        else
          v4 = nullptr;
        KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: "ServerConfig.vdf",
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr);
        for ( i = 0; i < 15; ++i )
        {
          v6 = botVars[i];
          if ( v6 != nullptr )
          {
            v7 = cvar->FindVar_2(this: cvar, a2: botVars[i]);
            if ( v7 != nullptr )
            {
              if ( (v7->m_nFlags & 0x1000) != 0 )
              {
                m_pszString = "FCVAR_NEVER_AS_STRING";
              }
              else
              {
                m_pszString = v7->m_pParent->m_Value.m_pszString;
                if ( m_pszString == nullptr )
                  m_pszString = locale;
              }
              KeyValues::SetString(this: v3, keyName: v6, value: m_pszString);
            }
          }
        }
        if ( filesystem != nullptr )
          v9 = &filesystem->IBaseFileSystem;
        else
          v9 = nullptr;
        KeyValues::SaveToFile(this: v3, filesystem: v9, resourceName: "ServerConfig.vdf", pathID: "GAME");
        KeyValues::deleteThis(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3370
// Name: public: virtual void CCSBotManager::OnPlayerFootstep(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnPlayerFootstep(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnPlayerFootstep(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B33E0
// Name: public: virtual void CCSBotManager::OnPlayerRadio(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnPlayerRadio(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  CCSBot *v6; // eax

  if ( event->GetInt(this: event, a2: "slot", a3: 0) == 17 )
    this->m_lastSeenEnemyTimestamp = gpGlobals->curtime;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: i);
    v5 = v4;
    if ( v4 != nullptr && v4->IsBot(this: v4) )
    {
      v6 = (CCSBot *)__RTDynamicCast(
                       inptr: v5,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v6 != nullptr )
        CCSBot::OnPlayerRadio(this: v6, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3480
// Name: public: virtual void CCSBotManager::OnPlayerDeath(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnPlayerDeath(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnPlayerDeath(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B34F0
// Name: public: virtual void CCSBotManager::OnBombPlanted(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombPlanted(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->m_isBombPlanted = true;
  this->m_bombPlantTimestamp = gpGlobals->curtime;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombPlanted(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3580
// Name: public: virtual void CCSBotManager::OnBombBeep(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombBeep(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombBeep(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B35F0
// Name: public: virtual void CCSBotManager::OnBombDefuseBegin(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombDefuseBegin(CCSBotManager *this, IGameEvent *event)
{
  int v3; // eax
  int i; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  vgui::TreeView *v7; // eax

  v3 = event->GetInt(this: event, a2: "userid", a3: 0);
  this->m_bombDefuser = (CCSPlayer *)UTIL_PlayerByUserId(userID: v3);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    v6 = v5;
    if ( v5 != nullptr && v5->IsBot(this: v5) )
    {
      v7 = (vgui::TreeView *)__RTDynamicCast(
                               inptr: v6,
                               VfDelta: 0,
                               SrcType: &CBasePlayer `RTTI Type Descriptor',
                               TargetType: &CCSBot `RTTI Type Descriptor',
                               isReference: 0);
      if ( v7 != nullptr )
        CNavMesh::SaveCustomData(this: v7, itemIndex: (int)event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3690
// Name: public: virtual void CCSBotManager::OnBombDefused(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombDefused(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->m_isBombPlanted = false;
  this->m_bombDefuser = nullptr;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombDefused(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3710
// Name: public: virtual void CCSBotManager::OnBombDefuseAbort(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombDefuseAbort(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->m_bombDefuser = nullptr;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombDefuseAbort(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3790
// Name: public: virtual void CCSBotManager::OnBombExploded(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombExploded(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombExploded(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3800
// Name: public: virtual void CCSBotManager::OnRoundEnd(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnRoundEnd(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->m_isRoundOver = true;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnRoundEnd(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3880
// Name: public: virtual void CCSBotManager::OnRoundStart(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnRoundStart(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->RestartRound(this);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnRoundStart(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3900
// Name: public: virtual void CCSBotManager::OnDoorMoving(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnDoorMoving(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnDoorMoving(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3970
// Name: public: virtual void CCSBotManager::OnHostageFollows(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnHostageFollows(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnHostageFollows(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B39E0
// Name: public: virtual void CCSBotManager::OnHostageRescuedAll(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnHostageRescuedAll(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnHostageRescuedAll(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3A50
// Name: public: virtual void CCSBotManager::OnWeaponFire(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnWeaponFire(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnWeaponFire(this: v5, a2: (int)event, a3: (int)v4, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3AC0
// Name: public: virtual void CCSBotManager::OnWeaponReload(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnWeaponReload(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnWeaponReload(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3B30
// Name: public: virtual void CCSBotManager::OnPlayerFallDamage(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnPlayerFallDamage(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnWeaponZoom(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3BA0
// Name: public: virtual void CCSBotManager::OnBulletImpact(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBulletImpact(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBulletImpact(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3C10
// Name: public: virtual void CCSBotManager::OnSmokeGrenadeDetonate(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnSmokeGrenadeDetonate(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnFlashbangDetonate(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3C80
// Name: public: virtual void CCSBotManager::OnHEGrenadeDetonate(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnHEGrenadeDetonate(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnMolotovDetonate(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3CF0
// Name: public: virtual void CCSBotManager::OnDecoyFiring(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnDecoyFiring(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnDecoyFiring(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3D60
// Name: public: virtual void CCSBotManager::OnGrenadeBounce(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnGrenadeBounce(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnGrenadeBounce(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3DD0
// Name: public: float CCSBotManager::GetBombTimeLeft(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBotManager::GetBombTimeLeft(CCSBotManager *this)
{
  return mp_c4timer.m_pParent->m_Value.m_fValue - (gpGlobals->curtime - this->m_bombPlantTimestamp);
}

//------------------------------------------------------------------------------
// Address: 0x102B3DF0
// Name: public: virtual bool CCSBotManager::IsImportantPlayer(class CCSPlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::IsImportantPlayer(CCSBotManager *this, CCSPlayer *player)
{
  if ( this->m_gameScenario == SCENARIO_DEFUSE_BOMB )
  {
    if ( CBaseEntity::GetTeamNumber(this: player) != 2 )
      return false;
    return CCSPlayer::HasC4(this: player);
  }
  else
  {
    if ( this->m_gameScenario != SCENARIO_ESCORT_VIP || CBaseEntity::GetTeamNumber(this: player) != 3 )
      return false;
    return CCSPlayer::IsVIP(this: player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B3E50
// Name: public: float CCSBotManager::GetRadioMessageInterval(enum RadioType,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBotManager::GetRadioMessageInterval(CCSBotManager *this, RadioType event, int teamID)
{
  if ( (unsigned int)(event - 2) > 0x16 )
    return 100000000.0;
  else
    return gpGlobals->curtime - *(&this->m_checkTransientAreasTimer.m_duration.m_Value + 2 * event + (teamID != 2));
}

//------------------------------------------------------------------------------
// Address: 0x102B3E90
// Name: public: void CCSBotManager::SetRadioMessageTimestamp(enum RadioType,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::SetRadioMessageTimestamp(CCSBotManager *this, RadioType event, int teamID)
{
  if ( (unsigned int)(event - 2) <= 0x16 )
    *(&this->m_checkTransientAreasTimer.m_duration.m_Value + 2 * event + (teamID != 2)) = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102B3EC0
// Name: public: class Vector CNavArea::GetCorner(enum NavCornerType)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CNavArea::GetCorner(CNavArea *this, Vector *result, NavCornerType corner)
{
  Vector *v3; // eax
  float m_neZ; // ecx
  float m_swZ; // edx
  __int64 v6; // xmm0_8
  float z; // ecx
  float v8; // edx
  __int64 pos; // [esp+0h] [ebp-Ch]
  __int64 posa; // [esp+0h] [ebp-Ch]

  switch ( corner )
  {
    case NORTH_EAST:
      *(float *)&pos = this->m_seCorner.x;
      HIDWORD(pos) = LODWORD(this->m_nwCorner.y);
      m_neZ = this->m_neZ;
      *(_QWORD *)&result->x = pos;
      result->z = m_neZ;
      v3 = result;
      break;
    case SOUTH_EAST:
      v6 = *(_QWORD *)&this->m_seCorner.x;
      z = this->m_seCorner.z;
      *(_QWORD *)&result->x = v6;
      result->z = z;
      v3 = result;
      break;
    case SOUTH_WEST:
      *(float *)&posa = this->m_nwCorner.x;
      HIDWORD(posa) = LODWORD(this->m_seCorner.y);
      m_swZ = this->m_swZ;
      *(_QWORD *)&result->x = posa;
      result->z = m_swZ;
      v3 = result;
      break;
    default:
      v8 = this->m_nwCorner.z;
      *(_QWORD *)&result->x = *(_QWORD *)&this->m_nwCorner.x;
      result->z = v8;
      v3 = result;
      break;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102B3F90
// Name: public: static enum BotDifficultyType CCSBotManager::GetDifficultyLevel(void)
// Source: json
//------------------------------------------------------------------------------
BotDifficultyType __cdecl CCSBotManager::GetDifficultyLevel()
{
  float m_fValue; // xmm0_4
  BotDifficultyType result; // eax

  m_fValue = cv_bot_difficulty.m_pParent->m_Value.m_fValue;
  if ( m_fValue < 0.89999998 )
    return BOT_EASY;
  if ( m_fValue < 1.9 )
    return BOT_NORMAL;
  result = BOT_HARD;
  if ( m_fValue >= 2.9000001 )
    return BOT_EXPERT;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B3FE0
// Name: void BotArgumentsFromArgv(class CCommand const __near &,char const __near * __near *,enum CSWeaponType __near *,enum BotDifficultyType __near *,int __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BotArgumentsFromArgv(
        const CCommand *args,
        const char **name,
        CSWeaponType *weaponType,
        BotDifficultyType *difficulty,
        int *team,
        bool *all)
{
  bool *v6; // esi
  int m_nArgc; // eax
  int v8; // ecx
  const char **v9; // edx
  char v10; // bl
  const char *v11; // edi
  BotDifficultyType v12; // esi
  CSWeaponType v13; // eax
  const char **v14; // [esp+0h] [ebp-4h]
  int arg; // [esp+10h] [ebp+Ch]

  s_name[0] = 0;
  *name = s_name;
  *difficulty = NUM_DIFFICULTY_LEVELS;
  if ( team != nullptr )
    *team = 0;
  v6 = all;
  if ( all != nullptr )
    *all = false;
  *weaponType = WEAPONTYPE_UNKNOWN;
  m_nArgc = args->m_nArgc;
  v8 = 1;
  arg = 1;
  if ( args->m_nArgc <= 1 )
    return;
  v9 = &args->m_ppArgv[1];
  v14 = &args->m_ppArgv[1];
  while ( 2 )
  {
    v10 = 0;
    if ( v8 < 0 || v8 >= m_nArgc )
      v11 = locale;
    else
      v11 = *v9;
    if ( v6 != nullptr && (v11 == "all" || _V_stricmp(s1: v11, s2: "all") == 0) )
    {
      *all = true;
LABEL_23:
      v10 = 1;
      goto LABEL_24;
    }
    if ( team != nullptr )
    {
      if ( v11 == "t" || _V_stricmp(s1: v11, s2: "t") == 0 )
      {
        *team = 2;
        goto LABEL_23;
      }
      if ( v11 == "ct" || _V_stricmp(s1: v11, s2: "ct") == 0 )
      {
        *team = 3;
        goto LABEL_23;
      }
    }
LABEL_24:
    v12 = BOT_EASY;
    while ( v10 == 0 )
    {
      if ( _V_stricmp(s1: BotDifficultyName[v12], s2: v11) == 0 )
      {
        *difficulty = v12;
        v10 = 1;
      }
      if ( ++v12 >= NUM_DIFFICULTY_LEVELS )
      {
        if ( v10 == 0 )
        {
          v13 = WeaponClassFromString(weaponType: v11);
          *weaponType = v13;
          if ( v13 == WEAPONTYPE_UNKNOWN )
            V_strncpy(pDest: s_name, pSrc: v11, maxLen: 32);
        }
        break;
      }
    }
    m_nArgc = args->m_nArgc;
    v8 = arg + 1;
    v9 = v14 + 1;
    arg = v8;
    ++v14;
    if ( v8 < args->m_nArgc )
    {
      v6 = all;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4150
// Name: public: class Vector const __near * CCSBotManager::GetRandomPositionInZone(struct CCSBotManager::Zone const __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCSBotManager::GetRandomPositionInZone(CCSBotManager *this, const CCSBotManager::Zone *zone)
{
  CNavArea *RandomAreaInZone; // edi
  float x; // xmm4_4
  float y; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  Extent areaExtent; // [esp+10h] [ebp-18h] BYREF

  if ( (_S2_262 & 1) == 0 )
    _S2_262 |= 1u;
  if ( zone == nullptr || zone->m_areaCount == 0 )
    return nullptr;
  RandomAreaInZone = CCSBotManager::GetRandomAreaInZone(this, zone);
  if ( zone->m_isLegacy )
  {
    CNavArea::GetClosestPointOnArea(this: RandomAreaInZone, pPos: &zone->m_center, close: &pos);
    return &pos;
  }
  else
  {
    CNavArea::GetExtent(this: RandomAreaInZone, extent: &areaExtent);
    if ( areaExtent.lo.x <= zone->m_extent.lo.x )
      x = zone->m_extent.lo.x;
    else
      x = areaExtent.lo.x;
    y = areaExtent.lo.y;
    if ( areaExtent.lo.y <= zone->m_extent.lo.y )
      y = zone->m_extent.lo.y;
    v6 = areaExtent.hi.x;
    if ( zone->m_extent.hi.x <= areaExtent.hi.x )
      v6 = zone->m_extent.hi.x;
    v7 = zone->m_extent.hi.y;
    if ( v7 > areaExtent.hi.y )
      v7 = areaExtent.hi.y;
    pos.x = (float)(v6 + x) * 0.5;
    pos.y = (float)(v7 + y) * 0.5;
    pos.z = CNavArea::GetZ(this: RandomAreaInZone, x: (float)(v6 + x) * 0.5, y: pos.y);
    return &pos;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4260
// Name: SelectSpawnSpot
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall SelectSpawnSpot@<eax>(const char *pEntClassName@<edi>, int a2@<ebp>)
{
  CBaseEntity *EntityByClassname; // esi
  CBaseEntity *v3; // ebx
  CBaseEntity *v4; // eax
  const char *v6; // [esp+0h] [ebp-Ch]

  EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: v6);
  if ( EntityByClassname == nullptr )
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: nullptr,
                          szName: pEntClassName);
  v3 = EntityByClassname;
  while ( 1 )
  {
    if ( EntityByClassname == nullptr )
    {
      v4 = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: pEntClassName);
      goto LABEL_12;
    }
    if ( (EntityByClassname->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: EntityByClassname, a2);
    if ( EntityByClassname->m_vecAbsOrigin.x != 0.0
      || EntityByClassname->m_vecAbsOrigin.y != 0.0
      || EntityByClassname->m_vecAbsOrigin.z != 0.0 )
    {
      return EntityByClassname;
    }
    v4 = CGlobalEntityList::FindEntityByClassname(
           this: &gEntList,
           pStartEntity: EntityByClassname,
           szName: pEntClassName);
LABEL_12:
    EntityByClassname = v4;
    if ( v4 == v3 )
      return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B42F0
// Name: public: void CCSBotManager::SetLooseBomb(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::SetLooseBomb(CCSBotManager *this, CBaseEntity *bomb)
{
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( bomb != nullptr )
  {
    this->m_looseBomb.m_Index = bomb->GetRefEHandle(this: bomb)->m_Index;
    if ( (bomb->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: bomb, a2: (int)&savedregs);
    this->m_looseBombArea = CNavMesh::GetNearestNavArea(
                              this: TheNavMesh,
                              pos: &bomb->m_vecAbsOrigin,
                              anyZ: false,
                              maxDist: 10000.0,
                              checkLOS: false,
                              checkGround: true);
  }
  else
  {
    this->m_looseBomb.m_Index = -1;
    this->m_looseBombArea = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4370
// Name: public: virtual unsigned int CCSBotManager::GetPlayerPriority(class CBasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBotManager::GetPlayerPriority(CCSBotManager *this, CBasePlayer *player)
{
  CCSPlayer *v4; // esi

  if ( !player->IsPlayer(this: player) )
    return -1;
  if ( !player->IsBot(this: player) )
    return 0;
  v4 = (CCSPlayer *)__RTDynamicCast(
                      inptr: player,
                      VfDelta: 0,
                      SrcType: &CBasePlayer `RTTI Type Descriptor',
                      TargetType: &CCSBot `RTTI Type Descriptor',
                      isReference: 0);
  if ( v4 == nullptr )
    return 0;
  if ( this->m_gameScenario == SCENARIO_DEFUSE_BOMB )
  {
    if ( CBaseEntity::GetTeamNumber(this: v4) == 2 && CCSPlayer::HasC4(this: v4) )
      return 1;
  }
  else if ( this->m_gameScenario == SCENARIO_RESCUE_HOSTAGES )
  {
    if ( CBaseEntity::GetTeamNumber(this: v4) == 3 && LOBYTE(v4[2].m_OnKilled.m_ActionList) != 0 )
      return 1;
  }
  else if ( this->m_gameScenario == SCENARIO_ESCORT_VIP && CBaseEntity::GetTeamNumber(this: v4) == 3 && v4->m_bIsVIP )
  {
    return 1;
  }
  return (int)&v4[1].m_Network.m_pPev->m_fStateFlags + 1;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C00
// Name: public: bool CCSBotManager::AllowPistols(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowPistols(CCSBotManager *this)
{
  return cv_bot_allow_pistols.m_pParent != nullptr && cv_bot_allow_pistols.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C20
// Name: public: bool CCSBotManager::AllowShotguns(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowShotguns(CCSBotManager *this)
{
  return cv_bot_allow_shotguns.m_pParent != nullptr && cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C40
// Name: public: bool CCSBotManager::AllowSubMachineGuns(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowSubMachineGuns(CCSBotManager *this)
{
  return cv_bot_allow_sub_machine_guns.m_pParent != nullptr
      && cv_bot_allow_sub_machine_guns.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C60
// Name: public: bool CCSBotManager::AllowRifles(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowRifles(CCSBotManager *this)
{
  return cv_bot_allow_rifles.m_pParent != nullptr && cv_bot_allow_rifles.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4C80
// Name: public: bool CCSBotManager::AllowMachineGuns(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowMachineGuns(CCSBotManager *this)
{
  return cv_bot_allow_machine_guns.m_pParent != nullptr && cv_bot_allow_machine_guns.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4CA0
// Name: public: bool CCSBotManager::AllowGrenades(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowGrenades(CCSBotManager *this)
{
  return cv_bot_allow_grenades.m_pParent != nullptr && cv_bot_allow_grenades.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4CC0
// Name: public: bool CCSBotManager::AllowSnipers(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::AllowSnipers(CCSBotManager *this)
{
  return cv_bot_allow_snipers.m_pParent != nullptr && cv_bot_allow_snipers.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4CE0
// Name: public: virtual char const __near * CCSBotManager::PlayerFootstepEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::PlayerFootstepEvent::GetEventName(CCSBotManager::PlayerFootstepEvent *this)
{
  return "player_footstep";
}

//------------------------------------------------------------------------------
// Address: 0x102B4CF0
// Name: public: virtual void CCSBotManager::PlayerFootstepEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::PlayerFootstepEvent::FireGameEvent(
        CCSBotManager::PlayerFootstepEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].AllocateBotEntity)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4D10
// Name: public: virtual char const __near * CCSBotManager::PlayerRadioEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::PlayerRadioEvent::GetEventName(CCSBotManager::PlayerRadioEvent *this)
{
  return "player_radio";
}

//------------------------------------------------------------------------------
// Address: 0x102B4D20
// Name: public: virtual void CCSBotManager::PlayerRadioEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::PlayerRadioEvent::FireGameEvent(
        CCSBotManager::PlayerRadioEvent *this,
        CBaseEntity *event)
{
  TheBots->__vftable[1].ClientDisconnect(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4D40
// Name: public: virtual char const __near * CCSBotManager::PlayerDeathEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::PlayerDeathEvent::GetEventName(CCSBotManager::PlayerDeathEvent *this)
{
  return "player_death";
}

//------------------------------------------------------------------------------
// Address: 0x102B4D50
// Name: public: virtual void CCSBotManager::PlayerDeathEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::PlayerDeathEvent::FireGameEvent(
        CCSBotManager::PlayerDeathEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].ClientCommand)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4D70
// Name: public: virtual char const __near * CCSBotManager::PlayerFallDamageEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::PlayerFallDamageEvent::GetEventName(CCSBotManager::PlayerFallDamageEvent *this)
{
  return "player_falldamage";
}

//------------------------------------------------------------------------------
// Address: 0x102B4D80
// Name: public: virtual void CCSBotManager::PlayerFallDamageEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::PlayerFallDamageEvent::FireGameEvent(
        CCSBotManager::PlayerFallDamageEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].ServerActivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4DA0
// Name: public: virtual char const __near * CCSBotManager::BombPickedUpEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombPickedUpEvent::GetEventName(CCSBotManager::BombPickedUpEvent *this)
{
  return "bomb_pickup";
}

//------------------------------------------------------------------------------
// Address: 0x102B4DB0
// Name: public: virtual void CCSBotManager::BombPickedUpEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombPickedUpEvent::FireGameEvent(
        CCSBotManager::BombPickedUpEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].ServerDeactivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4DD0
// Name: public: virtual char const __near * CCSBotManager::BombPlantedEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombPlantedEvent::GetEventName(CCSBotManager::BombPlantedEvent *this)
{
  return "bomb_planted";
}

//------------------------------------------------------------------------------
// Address: 0x102B4DE0
// Name: public: virtual void CCSBotManager::BombPlantedEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombPlantedEvent::FireGameEvent(
        CCSBotManager::BombPlantedEvent *this,
        IGameEvent *event)
{
  TheBots->__vftable[1].ServerCommand(this: TheBots, a2: (const char *)event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4E00
// Name: public: virtual char const __near * CCSBotManager::BombBeepEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombBeepEvent::GetEventName(CCSBotManager::BombBeepEvent *this)
{
  return "bomb_beep";
}

//------------------------------------------------------------------------------
// Address: 0x102B4E10
// Name: public: virtual void CCSBotManager::BombBeepEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombBeepEvent::FireGameEvent(CCSBotManager::BombBeepEvent *this, IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].RestartRound)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4E30
// Name: public: virtual char const __near * CCSBotManager::BombDefuseBeginEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombDefuseBeginEvent::GetEventName(CCSBotManager::BombDefuseBeginEvent *this)
{
  return "bomb_begindefuse";
}

//------------------------------------------------------------------------------
// Address: 0x102B4E40
// Name: public: virtual void CCSBotManager::BombDefuseBeginEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombDefuseBeginEvent::FireGameEvent(
        CCSBotManager::BombDefuseBeginEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[1].StartFrame)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4E60
// Name: public: virtual char const __near * CCSBotManager::BombDefusedEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombDefusedEvent::GetEventName(CCSBotManager::BombDefusedEvent *this)
{
  return "bomb_defused";
}

//------------------------------------------------------------------------------
// Address: 0x102B4E70
// Name: public: virtual void CCSBotManager::BombDefusedEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombDefusedEvent::FireGameEvent(
        CCSBotManager::BombDefusedEvent *this,
        CBasePlayer *event)
{
  TheBots->__vftable[1].GetPlayerPriority(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4E90
// Name: public: virtual char const __near * CCSBotManager::BombDefuseAbortEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombDefuseAbortEvent::GetEventName(CCSBotManager::BombDefuseAbortEvent *this)
{
  return "bomb_abortdefuse";
}

//------------------------------------------------------------------------------
// Address: 0x102B4EA0
// Name: public: virtual void CCSBotManager::BombDefuseAbortEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombDefuseAbortEvent::FireGameEvent(
        CCSBotManager::BombDefuseAbortEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].dtr_CBotManager)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4EC0
// Name: public: virtual char const __near * CCSBotManager::BombExplodedEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BombExplodedEvent::GetEventName(CCSBotManager::BombExplodedEvent *this)
{
  return "bomb_exploded";
}

//------------------------------------------------------------------------------
// Address: 0x102B4ED0
// Name: public: virtual void CCSBotManager::BombExplodedEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BombExplodedEvent::FireGameEvent(
        CCSBotManager::BombExplodedEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].AllocateBotEntity)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4EF0
// Name: public: virtual char const __near * CCSBotManager::RoundEndEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::RoundEndEvent::GetEventName(CCSBotManager::RoundEndEvent *this)
{
  return "round_end";
}

//------------------------------------------------------------------------------
// Address: 0x102B4F00
// Name: public: virtual void CCSBotManager::RoundEndEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::RoundEndEvent::FireGameEvent(CCSBotManager::RoundEndEvent *this, CBaseEntity *event)
{
  TheBots->__vftable[2].ClientDisconnect(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4F20
// Name: public: virtual char const __near * CCSBotManager::RoundStartEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::RoundStartEvent::GetEventName(CCSBotManager::RoundStartEvent *this)
{
  return "round_start";
}

//------------------------------------------------------------------------------
// Address: 0x102B4F30
// Name: public: virtual void CCSBotManager::RoundStartEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::RoundStartEvent::FireGameEvent(CCSBotManager::RoundStartEvent *this, IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].ClientCommand)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4F50
// Name: public: virtual char const __near * CCSBotManager::RoundFreezeEndEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::RoundFreezeEndEvent::GetEventName(CCSBotManager::RoundFreezeEndEvent *this)
{
  return "round_freeze_end";
}

//------------------------------------------------------------------------------
// Address: 0x102B4F60
// Name: public: virtual void CCSBotManager::RoundFreezeEndEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::RoundFreezeEndEvent::FireGameEvent(
        CCSBotManager::RoundFreezeEndEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].ServerActivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4F80
// Name: public: virtual char const __near * CCSBotManager::DoorMovingEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::DoorMovingEvent::GetEventName(CCSBotManager::DoorMovingEvent *this)
{
  return "door_moving";
}

//------------------------------------------------------------------------------
// Address: 0x102B4F90
// Name: public: virtual void CCSBotManager::DoorMovingEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::DoorMovingEvent::FireGameEvent(CCSBotManager::DoorMovingEvent *this, IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].ServerDeactivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4FB0
// Name: public: virtual char const __near * CCSBotManager::BreakPropEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BreakPropEvent::GetEventName(CCSBotManager::BreakPropEvent *this)
{
  return "break_prop";
}

//------------------------------------------------------------------------------
// Address: 0x102B4FC0
// Name: public: virtual void CCSBotManager::BreakPropEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BreakPropEvent::FireGameEvent(CCSBotManager::BreakPropEvent *this, IGameEvent *event)
{
  TheBots->__vftable[2].ServerCommand(this: TheBots, a2: (const char *)event);
}

//------------------------------------------------------------------------------
// Address: 0x102B4FE0
// Name: public: virtual char const __near * CCSBotManager::BreakBreakableEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BreakBreakableEvent::GetEventName(CCSBotManager::BreakBreakableEvent *this)
{
  return "break_breakable";
}

//------------------------------------------------------------------------------
// Address: 0x102B4FF0
// Name: public: virtual void CCSBotManager::BreakBreakableEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BreakBreakableEvent::FireGameEvent(
        CCSBotManager::BreakBreakableEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].RestartRound)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5010
// Name: public: virtual char const __near * CCSBotManager::HostageFollowsEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::HostageFollowsEvent::GetEventName(CCSBotManager::HostageFollowsEvent *this)
{
  return "hostage_follows";
}

//------------------------------------------------------------------------------
// Address: 0x102B5020
// Name: public: virtual void CCSBotManager::HostageFollowsEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::HostageFollowsEvent::FireGameEvent(
        CCSBotManager::HostageFollowsEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[2].StartFrame)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5040
// Name: public: virtual char const __near * CCSBotManager::HostageRescuedAllEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::HostageRescuedAllEvent::GetEventName(CCSBotManager::HostageRescuedAllEvent *this)
{
  return "hostage_rescued_all";
}

//------------------------------------------------------------------------------
// Address: 0x102B5050
// Name: public: virtual void CCSBotManager::HostageRescuedAllEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::HostageRescuedAllEvent::FireGameEvent(
        CCSBotManager::HostageRescuedAllEvent *this,
        CBasePlayer *event)
{
  TheBots->__vftable[2].GetPlayerPriority(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5070
// Name: public: virtual char const __near * CCSBotManager::WeaponFireEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::WeaponFireEvent::GetEventName(CCSBotManager::WeaponFireEvent *this)
{
  return "weapon_fire";
}

//------------------------------------------------------------------------------
// Address: 0x102B5080
// Name: public: virtual void CCSBotManager::WeaponFireEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::WeaponFireEvent::FireGameEvent(CCSBotManager::WeaponFireEvent *this, IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].dtr_CBotManager)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B50A0
// Name: public: virtual char const __near * CCSBotManager::WeaponFireOnEmptyEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::WeaponFireOnEmptyEvent::GetEventName(CCSBotManager::WeaponFireOnEmptyEvent *this)
{
  return "weapon_fire_on_empty";
}

//------------------------------------------------------------------------------
// Address: 0x102B50B0
// Name: public: virtual void CCSBotManager::WeaponFireOnEmptyEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::WeaponFireOnEmptyEvent::FireGameEvent(
        CCSBotManager::WeaponFireOnEmptyEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].AllocateBotEntity)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B50D0
// Name: public: virtual char const __near * CCSBotManager::WeaponReloadEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::WeaponReloadEvent::GetEventName(CCSBotManager::WeaponReloadEvent *this)
{
  return "weapon_reload";
}

//------------------------------------------------------------------------------
// Address: 0x102B50E0
// Name: public: virtual void CCSBotManager::WeaponReloadEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::WeaponReloadEvent::FireGameEvent(
        CCSBotManager::WeaponReloadEvent *this,
        CBaseEntity *event)
{
  TheBots->__vftable[3].ClientDisconnect(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5100
// Name: public: virtual char const __near * CCSBotManager::WeaponZoomEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::WeaponZoomEvent::GetEventName(CCSBotManager::WeaponZoomEvent *this)
{
  return "weapon_zoom";
}

//------------------------------------------------------------------------------
// Address: 0x102B5110
// Name: public: virtual void CCSBotManager::WeaponZoomEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::WeaponZoomEvent::FireGameEvent(CCSBotManager::WeaponZoomEvent *this, IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].ClientCommand)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5130
// Name: public: virtual char const __near * CCSBotManager::BulletImpactEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::BulletImpactEvent::GetEventName(CCSBotManager::BulletImpactEvent *this)
{
  return "bullet_impact";
}

//------------------------------------------------------------------------------
// Address: 0x102B5140
// Name: public: virtual void CCSBotManager::BulletImpactEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::BulletImpactEvent::FireGameEvent(
        CCSBotManager::BulletImpactEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].ServerActivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5160
// Name: public: virtual char const __near * CCSBotManager::HEGrenadeDetonateEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::HEGrenadeDetonateEvent::GetEventName(CCSBotManager::HEGrenadeDetonateEvent *this)
{
  return "hegrenade_detonate";
}

//------------------------------------------------------------------------------
// Address: 0x102B5170
// Name: public: virtual void CCSBotManager::HEGrenadeDetonateEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::HEGrenadeDetonateEvent::FireGameEvent(
        CCSBotManager::HEGrenadeDetonateEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].ServerDeactivate)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5190
// Name: public: virtual char const __near * CCSBotManager::FlashbangDetonateEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::FlashbangDetonateEvent::GetEventName(CCSBotManager::FlashbangDetonateEvent *this)
{
  return "flashbang_detonate";
}

//------------------------------------------------------------------------------
// Address: 0x102B51A0
// Name: public: virtual void CCSBotManager::FlashbangDetonateEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::FlashbangDetonateEvent::FireGameEvent(
        CCSBotManager::FlashbangDetonateEvent *this,
        IGameEvent *event)
{
  TheBots->__vftable[3].ServerCommand(this: TheBots, a2: (const char *)event);
}

//------------------------------------------------------------------------------
// Address: 0x102B51C0
// Name: public: virtual char const __near * CCSBotManager::SmokeGrenadeDetonateEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::SmokeGrenadeDetonateEvent::GetEventName(
        CCSBotManager::SmokeGrenadeDetonateEvent *this)
{
  return "smokegrenade_detonate";
}

//------------------------------------------------------------------------------
// Address: 0x102B51D0
// Name: public: virtual void CCSBotManager::SmokeGrenadeDetonateEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::SmokeGrenadeDetonateEvent::FireGameEvent(
        CCSBotManager::SmokeGrenadeDetonateEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].RestartRound)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B51F0
// Name: public: virtual char const __near * CCSBotManager::MolotovDetonateEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::MolotovDetonateEvent::GetEventName(CCSBotManager::MolotovDetonateEvent *this)
{
  return "molotov_detonate";
}

//------------------------------------------------------------------------------
// Address: 0x102B5200
// Name: public: virtual void CCSBotManager::MolotovDetonateEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::MolotovDetonateEvent::FireGameEvent(
        CCSBotManager::MolotovDetonateEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[3].StartFrame)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5220
// Name: public: virtual char const __near * CCSBotManager::DecoyDetonateEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::DecoyDetonateEvent::GetEventName(CCSBotManager::DecoyDetonateEvent *this)
{
  return "decoy_detonate";
}

//------------------------------------------------------------------------------
// Address: 0x102B5230
// Name: public: virtual void CCSBotManager::DecoyDetonateEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::DecoyDetonateEvent::FireGameEvent(
        CCSBotManager::DecoyDetonateEvent *this,
        CBasePlayer *event)
{
  TheBots->__vftable[3].GetPlayerPriority(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5250
// Name: public: virtual char const __near * CCSBotManager::DecoyFiringEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::DecoyFiringEvent::GetEventName(CCSBotManager::DecoyFiringEvent *this)
{
  return "decoy_firing";
}

//------------------------------------------------------------------------------
// Address: 0x102B5260
// Name: public: virtual void CCSBotManager::DecoyFiringEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::DecoyFiringEvent::FireGameEvent(
        CCSBotManager::DecoyFiringEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[4].dtr_CBotManager)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5280
// Name: public: virtual char const __near * CCSBotManager::GrenadeBounceEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::GrenadeBounceEvent::GetEventName(CCSBotManager::GrenadeBounceEvent *this)
{
  return "grenade_bounce";
}

//------------------------------------------------------------------------------
// Address: 0x102B5290
// Name: public: virtual void CCSBotManager::GrenadeBounceEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::GrenadeBounceEvent::FireGameEvent(
        CCSBotManager::GrenadeBounceEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[4].AllocateBotEntity)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B52B0
// Name: public: virtual int CCSBotManager::HostageFollowsEvent::GetEventDebugID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBotManager::HostageFollowsEvent::GetEventDebugID(CCSBotManager::ServerShutdownEvent *this)
{
  return 42;
}

//------------------------------------------------------------------------------
// Address: 0x102B52C0
// Name: public: virtual char const __near * CCSBotManager::NavBlockedEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::NavBlockedEvent::GetEventName(CCSBotManager::NavBlockedEvent *this)
{
  return "nav_blocked";
}

//------------------------------------------------------------------------------
// Address: 0x102B52D0
// Name: public: virtual void CCSBotManager::NavBlockedEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::NavBlockedEvent::FireGameEvent(CCSBotManager::NavBlockedEvent *this, CBaseEntity *event)
{
  TheBots->__vftable[4].ClientDisconnect(this: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B52F0
// Name: public: virtual char const __near * CCSBotManager::ServerShutdownEvent::GetEventName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBotManager::ServerShutdownEvent::GetEventName(CCSBotManager::ServerShutdownEvent *this)
{
  return "server_shutdown";
}

//------------------------------------------------------------------------------
// Address: 0x102B5300
// Name: public: virtual void CCSBotManager::ServerShutdownEvent::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::ServerShutdownEvent::FireGameEvent(
        CCSBotManager::ServerShutdownEvent *this,
        IGameEvent *event)
{
  ((void (__thiscall *)(CBotManager *, IGameEvent *))TheBots->__vftable[4].ClientCommand)(a1: TheBots, a2: event);
}

//------------------------------------------------------------------------------
// Address: 0x102B5B60
// Name: public: virtual void CCSBotManager::RestartRound(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CCSBotManager::RestartRound(CCSBotManager *this)
{
  IUniformRandomStream *v2; // ecx
  double v3; // st7
  float *v4; // edx
  int i; // edi
  float *v6; // eax
  int j; // ecx
  ConVar *m_pParent; // ecx

  CBotManager::RestartRound(this);
  this->m_looseBomb.m_Index = -1;
  this->m_looseBombArea = nullptr;
  this->m_isBombPlanted = false;
  v3 = _RandomFloat(this: v2, a2: 10.0, a3: 30.0) + gpGlobals->curtime;
  this->m_bombDefuser = nullptr;
  this->m_earliestBombPlantTimestamp = v3;
  v4 = this->m_radioMsgTimestamp[0];
  for ( i = 2; i != 0; --i )
  {
    v6 = v4;
    for ( j = 24; j != 0; --j )
    {
      *v6 = 0.0;
      v6 += 2;
    }
    ++v4;
  }
  this->m_lastSeenEnemyTimestamp = -9999.9004;
  m_pParent = mp_freezetime.m_pParent;
  this->m_roundStartTimestamp = mp_freezetime.m_pParent->m_Value.m_fValue + gpGlobals->curtime;
  this->m_isDefenseRushing = _RandomFloat(this: (IUniformRandomStream *)m_pParent, a2: 0.0, a3: 100.0) <= 33.299999;
  BotPhraseManager::OnRoundRestart(this: TheBotPhrases);
  this->m_isRoundOver = false;
}

//------------------------------------------------------------------------------
// Address: 0x102B5C70
// Name: private: void CCSBotManager::EnableEventListeners(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::EnableEventListeners(CCSBotManager *this, bool enable)
{
  bool v2; // al
  int v4; // esi
  BotEventInterface **m_pMemory; // eax
  BotEventInterface *v6; // ecx
  BotEventInterface **v7; // edi
  IGameEventManager2_vtbl *v8; // esi
  int v9; // eax
  int i; // [esp+4h] [ebp-4h]

  v2 = enable;
  if ( this->m_eventListenersEnabled != enable )
  {
    v4 = 0;
    this->m_eventListenersEnabled = enable;
    i = 0;
    if ( this->m_commonEventListeners.m_Size > 0 )
    {
      while ( 1 )
      {
        if ( v2 )
        {
          m_pMemory = this->m_commonEventListeners.m_Memory.m_pMemory;
          v6 = m_pMemory[v4];
          v7 = &m_pMemory[v4];
          v8 = gameeventmanager->__vftable;
          v9 = ((int (__thiscall *)(BotEventInterface *, int))v6->GetEventName)(a1: v6, a2: 1);
          ((void (__thiscall *)(IGameEventManager2 *, BotEventInterface *, int))v8->AddListener)(
            a1: gameeventmanager,
            a2: *v7,
            a3: v9);
          v4 = i;
        }
        else
        {
          gameeventmanager->RemoveListener(
            this: gameeventmanager,
            a2: this->m_commonEventListeners.m_Memory.m_pMemory[v4]);
        }
        i = ++v4;
        if ( v4 >= this->m_commonEventListeners.m_Size )
          break;
        v2 = enable;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B5D10
// Name: public: bool CCSBotManager::IsWeaponUseable(class CWeaponCSBase const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBotManager::IsWeaponUseable(CCSBotManager *this, CWeaponCSBase *weapon)
{
  return weapon != nullptr
      && (weapon->GetCSWeaponID(this: weapon) == WEAPON_C4
       || (cv_bot_allow_shotguns.m_pParent != nullptr && cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue != 0
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_SHOTGUN)
       && (cv_bot_allow_machine_guns.m_pParent != nullptr && cv_bot_allow_machine_guns.m_pParent->m_Value.m_nValue != 0
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_MACHINEGUN)
       && (cv_bot_allow_rifles.m_pParent != nullptr && cv_bot_allow_rifles.m_pParent->m_Value.m_nValue != 0
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_RIFLE)
       && (cv_bot_allow_shotguns.m_pParent != nullptr && cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue != 0
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_SHOTGUN)
       && (cv_bot_allow_snipers.m_pParent != nullptr && cv_bot_allow_snipers.m_pParent->m_Value.m_nValue != 0
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_SNIPER_RIFLE)
       && (CCSBotManager::AllowSubMachineGuns(this)
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_SUBMACHINEGUN)
       && (CCSBotManager::AllowPistols(this)
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_PISTOL)
       && (CCSBotManager::AllowGrenades(this)
        || CWeaponCSBase::GetCSWpnData(this: weapon)->m_WeaponType != WEAPONTYPE_GRENADE));
}

//------------------------------------------------------------------------------
// Address: 0x102B5E50
// Name: public: void CCSBotManager::ExtractScenarioData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::ExtractScenarioData(CCSBotManager *this)
{
  CGlobalVars *v2; // edi
  edict_t *pEdicts; // edx
  int v4; // eax
  int v5; // ecx
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // edi
  bool v8; // bl
  Vector *p_m_vecAbsOrigin; // ecx
  int m_zoneCount; // edx
  Vector *p_m_center; // eax
  CBaseEntity *i; // edi
  edict_t *m_pPev; // eax
  int v14; // eax
  int v15; // ecx
  Vector *v16; // eax
  int v17; // ebx
  float *p_z; // edi
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  Vector pWorldMins; // [esp+4h] [ebp-2Ch] BYREF
  Vector absmin; // [esp+10h] [ebp-20h] BYREF
  Vector absmax; // [esp+1Ch] [ebp-14h] BYREF
  CollectOverlappingAreas collector; // [esp+28h] [ebp-8h] BYREF
  int v26; // [esp+2Ch] [ebp-4h]
  int savedregs; // [esp+30h] [ebp+0h] BYREF

  if ( TheNavMesh->m_isLoaded )
  {
    this->m_zoneCount = 0;
    this->m_gameScenario = SCENARIO_DEATHMATCH;
    v2 = gpGlobals;
    collector.m_zone = (CCSBotManager::Zone *)1;
    if ( gpGlobals->maxEntities > 1 )
    {
      v26 = 16;
      do
      {
        pEdicts = v2->pEdicts;
        if ( pEdicts != nullptr )
          v4 = (pEdicts[v26 / 0x10u].m_fStateFlags & 2) == 0 ? (unsigned int)&pEdicts[v26 / 0x10u] : 0;
        else
          v4 = 0;
        if ( v4 != 0 || pEdicts != nullptr && (v4 = (int)v2->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
        {
          v5 = *(_DWORD *)(v4 + 12);
          if ( v5 != 0 )
          {
            v6 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
            v7 = v6;
            if ( v6 != nullptr )
            {
              if ( v6->m_iClassname.pszValue == "func_bomb_target"
                || CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "func_bomb_target") != 0 )
              {
                this->m_gameScenario = SCENARIO_DEFUSE_BOMB;
                goto LABEL_29;
              }
              if ( v7->m_iClassname.pszValue == "info_bomb_target"
                || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "info_bomb_target") != 0 )
              {
                this->m_gameScenario = SCENARIO_DEFUSE_BOMB;
                v8 = true;
                goto LABEL_30;
              }
              if ( v7->m_iClassname.pszValue == "func_hostage_rescue"
                || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "func_hostage_rescue") != 0 )
              {
                this->m_gameScenario = SCENARIO_RESCUE_HOSTAGES;
                goto LABEL_29;
              }
              if ( v7->m_iClassname.pszValue == "info_hostage_rescue"
                || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "info_hostage_rescue") != 0 )
              {
                this->m_gameScenario = SCENARIO_RESCUE_HOSTAGES;
                v8 = true;
                goto LABEL_30;
              }
              if ( v7->m_iClassname.pszValue == "hostage_entity"
                || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "hostage_entity") != 0 )
              {
                this->m_gameScenario = SCENARIO_RESCUE_HOSTAGES;
              }
              else if ( FClassnameIs(pEntity: v7, szClassname: "func_vip_safetyzone") )
              {
                this->m_gameScenario = SCENARIO_ESCORT_VIP;
LABEL_29:
                v8 = false;
LABEL_30:
                if ( this->m_zoneCount >= 4 )
                {
                  _Msg(a1: "Warning: Too many zones, some will be ignored.\n");
                }
                else
                {
                  CCollisionProperty::CollisionAABBToWorldAABB(
                    this: &v7->m_Collision,
                    entityMins: &v7->m_Collision.m_vecMins.m_Value,
                    entityMaxs: &v7->m_Collision.m_vecMaxs.m_Value,
                    pWorldMins: &absmin,
                    pWorldMaxs: &absmax);
                  this->m_zone[this->m_zoneCount].m_isBlocked = false;
                  if ( v8 )
                  {
                    if ( (v7->m_iEFlags & 0x800) != 0 )
                      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
                    p_m_vecAbsOrigin = &v7->m_vecAbsOrigin;
                  }
                  else
                  {
                    pWorldMins.x = (float)(absmax.x + absmin.x) * 0.5;
                    pWorldMins.y = (float)(absmin.y + absmax.y) * 0.5;
                    pWorldMins.z = (float)(absmax.z + absmin.z) * 0.5;
                    p_m_vecAbsOrigin = &pWorldMins;
                  }
                  m_zoneCount = this->m_zoneCount;
                  this->m_zone[m_zoneCount].m_center.x = p_m_vecAbsOrigin->x;
                  p_m_center = &this->m_zone[m_zoneCount].m_center;
                  p_m_center->y = p_m_vecAbsOrigin->y;
                  p_m_center->z = p_m_vecAbsOrigin->z;
                  this->m_zone[this->m_zoneCount].m_isLegacy = v8;
                  this->m_zone[this->m_zoneCount].m_index = this->m_zoneCount;
                  this->m_zone[this->m_zoneCount++].m_entity = v7;
                }
              }
            }
          }
        }
        v2 = gpGlobals;
        v26 += 16;
        ++collector.m_zone;
      }
      while ( (int)collector.m_zone < gpGlobals->maxEntities );
    }
    if ( this->m_zoneCount == 0 && this->m_gameScenario == SCENARIO_RESCUE_HOSTAGES )
    {
      for ( i = CGlobalEntityList::FindEntityByClassname(
                  this: &gEntList,
                  pStartEntity: nullptr,
                  szName: "info_player_start");
            i != nullptr;
            i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "info_player_start") )
      {
        m_pPev = i->m_Network.m_pPev;
        if ( m_pPev == nullptr || m_pPev - gpGlobals->pEdicts == 0 )
          break;
        v14 = this->m_zoneCount;
        if ( v14 >= 4 )
        {
          _Msg(a1: "Warning: Too many zones, some will be ignored.\n");
        }
        else
        {
          this->m_zone[v14].m_isBlocked = false;
          if ( (i->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
          v15 = this->m_zoneCount;
          this->m_zone[v15].m_center.x = i->m_vecAbsOrigin.x;
          v16 = &this->m_zone[v15].m_center;
          v16->y = i->m_vecAbsOrigin.y;
          v16->z = i->m_vecAbsOrigin.z;
          this->m_zone[this->m_zoneCount].m_isLegacy = true;
          this->m_zone[this->m_zoneCount].m_index = this->m_zoneCount;
          this->m_zone[this->m_zoneCount++].m_entity = i;
        }
      }
    }
    v17 = 0;
    if ( this->m_zoneCount > 0 )
    {
      p_z = &this->m_zone[0].m_extent.lo.z;
      do
      {
        if ( *((_BYTE *)p_z - 20) != 0 )
        {
          v19 = *(p_z - 8);
          *(p_z - 2) = v19 - 256.0;
          v20 = *(p_z - 7);
          *(p_z - 1) = v20 - 256.0;
          v21 = *(p_z - 6) + 256.0;
          *p_z = *(p_z - 6) - 256.0;
          p_z[1] = v19 + 256.0;
          p_z[2] = v20 + 256.0;
          p_z[3] = v21;
        }
        else
        {
          CCollisionProperty::CollisionAABBToWorldAABB(
            this: (CCollisionProperty *)(*((_DWORD *)p_z - 26) + 228),
            entityMins: (const Vector *)(*((_DWORD *)p_z - 26) + 236),
            entityMaxs: (const Vector *)(*((_DWORD *)p_z - 26) + 248),
            &pWorldMins,
            pWorldMaxs: &absmin);
          *(Vector *)(p_z - 2) = pWorldMins;
          *(Vector *)(p_z + 1) = absmin;
        }
        *p_z = *p_z - 50.0;
        p_z[3] = p_z[3] + 50.0;
        *(p_z - 9) = 0.0;
        collector.m_zone = (CCSBotManager::Zone *)(p_z - 26);
        CNavMesh::ForAllAreas<CollectOverlappingAreas>(this: TheNavMesh, func: &collector);
        ++v17;
        p_z += 30;
      }
      while ( v17 < this->m_zoneCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6360
// Name: public: virtual void CCSBotManager::OnBombPickedUp(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBombPickedUp(CCSBotManager *this, IGameEvent *event)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSBot *v5; // eax

  this->m_looseBomb.m_Index = -1;
  this->m_looseBombArea = nullptr;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) )
    {
      v5 = (CCSBot *)__RTDynamicCast(
                       inptr: v4,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v5 != nullptr )
        CCSBot::OnBombPickedUp(this: v5, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B63F0
// Name: public: virtual void CCSBotManager::OnBreakBreakable(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnBreakBreakable(CCSBotManager *this, IGameEvent *event)
{
  int v2; // eax
  ICollideable *v3; // eax
  int i; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  CCSBot *v7; // eax
  CheckAreasOverlappingBreakable collector; // [esp+8h] [ebp-1Ch] BYREF

  v2 = event->GetInt(this: event, a2: "entindex", a3: 0);
  collector.m_breakable = UTIL_EntityByIndex(entityIndex: v2);
  v3 = collector.m_breakable->GetCollideable(this: collector.m_breakable);
  v3->WorldSpaceSurroundingBounds(this: v3, a2: &collector.m_breakableExtent.lo, a3: &collector.m_breakableExtent.hi);
  collector.m_breakableExtent.lo.x = collector.m_breakableExtent.lo.x - 10.0;
  collector.m_breakableExtent.lo.y = collector.m_breakableExtent.lo.y - 10.0;
  collector.m_breakableExtent.lo.z = collector.m_breakableExtent.lo.z - 10.0;
  collector.m_breakableExtent.hi.x = collector.m_breakableExtent.hi.x + 10.0;
  collector.m_breakableExtent.hi.y = collector.m_breakableExtent.hi.y + 10.0;
  collector.m_breakableExtent.hi.z = collector.m_breakableExtent.hi.z + 10.0;
  CNavMesh::ForAllAreas<CheckAreasOverlappingBreakable>(this: TheNavMesh, func: &collector);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    v6 = v5;
    if ( v5 != nullptr && v5->IsBot(this: v5) )
    {
      v7 = (CCSBot *)__RTDynamicCast(
                       inptr: v6,
                       VfDelta: 0,
                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
      if ( v7 != nullptr )
        CCSBot::OnBreakProp(this: v7, event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6510
// Name: void DrawOccupyTime(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawOccupyTime()
{
  int v0; // ebx
  CNavArea *v1; // eax
  float v2; // xmm0_4
  int v3; // esi
  int v4; // edi
  Vector m_seCorner; // [esp+10h] [ebp-48h] BYREF
  Vector target; // [esp+1Ch] [ebp-3Ch] BYREF
  Vector v7; // [esp+28h] [ebp-30h] BYREF
  Vector origin; // [esp+34h] [ebp-24h] BYREF
  Vector v9; // [esp+40h] [ebp-18h]
  Vector v10; // [esp+4Ch] [ebp-Ch]

  v0 = 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = TheNavAreas.m_Memory.m_pMemory[v0];
      v2 = gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696];
      if ( v2 > v1->m_earliestOccupyTime[0] )
        break;
      if ( v2 > v1->m_earliestOccupyTime[1] )
      {
        v3 = 0;
        v4 = 255;
LABEL_8:
        origin = v1->m_nwCorner;
        v10.x = v1->m_seCorner.x;
        v10.y = v1->m_nwCorner.y;
        v10.z = v1->m_neZ;
        target = v10;
        v9.x = v1->m_nwCorner.x;
        v9.y = v1->m_seCorner.y;
        v9.z = v1->m_swZ;
        v7 = v9;
        m_seCorner = v1->m_seCorner;
        NDebugOverlay::Line(&origin, &target, r: v3, g: 0, b: v4, noDepthTest: 1, duration: 0.1);
        NDebugOverlay::Line(&origin, target: &v7, r: v3, g: 0, b: v4, noDepthTest: 1, duration: 0.1);
        NDebugOverlay::Line(origin: &m_seCorner, target: &v7, r: v3, g: 0, b: v4, noDepthTest: 1, duration: 0.1);
        NDebugOverlay::Line(origin: &m_seCorner, &target, r: v3, g: 0, b: v4, noDepthTest: 1, duration: 0.1);
      }
      if ( ++v0 >= TheNavAreas.m_Size )
        return;
    }
    v3 = 255;
    if ( v2 <= v1->m_earliestOccupyTime[1] )
      v4 = 0;
    else
      v4 = 255;
    goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B66B0
// Name: void DrawBattlefront(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawBattlefront()
{
  int i; // esi
  CNavArea *v1; // eax
  Vector m_seCorner; // [esp+8h] [ebp-48h] BYREF
  Vector target; // [esp+14h] [ebp-3Ch] BYREF
  Vector v4; // [esp+20h] [ebp-30h] BYREF
  Vector origin; // [esp+2Ch] [ebp-24h] BYREF
  Vector v6; // [esp+38h] [ebp-18h]
  Vector v7; // [esp+44h] [ebp-Ch]

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v1 = TheNavAreas.m_Memory.m_pMemory[i];
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v1->m_earliestOccupyTime[0] - v1->m_earliestOccupyTime[1]) & _mask__AbsFloat_) <= 1.0 )
    {
      origin = v1->m_nwCorner;
      v7.x = v1->m_seCorner.x;
      v7.y = v1->m_nwCorner.y;
      v7.z = v1->m_neZ;
      target = v7;
      v6.x = v1->m_nwCorner.x;
      v6.y = v1->m_seCorner.y;
      v6.z = v1->m_swZ;
      v4 = v6;
      m_seCorner = v1->m_seCorner;
      NDebugOverlay::Line(&origin, &target, r: 255, g: 50, b: 0, noDepthTest: 1, duration: 0.1);
      NDebugOverlay::Line(&origin, target: &v4, r: 255, g: 50, b: 0, noDepthTest: 1, duration: 0.1);
      NDebugOverlay::Line(origin: &m_seCorner, target: &v4, r: 255, g: 50, b: 0, noDepthTest: 1, duration: 0.1);
      NDebugOverlay::Line(origin: &m_seCorner, &target, r: 255, g: 50, b: 0, noDepthTest: 1, duration: 0.1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6D50
// Name: public: class BotProfile const __near * BotProfileManager::GetProfile(char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
const BotProfile *__thiscall BotProfileManager::GetProfile(BotProfileManager *this, const char *name, int team)
{
  int m_Head; // eax
  int v5; // esi
  BotProfile *m_Element; // edi

  m_Head = this->m_profileList.m_Head;
  if ( m_Head == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v5 = (unsigned __int16)m_Head;
    m_Element = this->m_profileList.m_Memory.m_pMemory[v5].m_Element;
    if ( _V_stricmp(s1: name, s2: m_Element->m_name) == 0 && BotProfile::IsValidForTeam(this: m_Element, team) )
      break;
    m_Head = this->m_profileList.m_Memory.m_pMemory[v5].m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x102B6DC0
// Name: public: class BotProfile const __near * BotProfileManager::GetProfileMatchingTemplate(char const __near *,int,enum BotDifficultyType)const
// Source: json
//------------------------------------------------------------------------------
const BotProfile *__thiscall BotProfileManager::GetProfileMatchingTemplate(
        BotProfileManager *this,
        const char *profileName,
        int team,
        BotDifficultyType difficulty)
{
  int m_Head; // eax
  int v6; // esi
  BotProfile *m_Element; // edi

  m_Head = this->m_profileList.m_Head;
  if ( m_Head == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v6 = (unsigned __int16)m_Head;
    m_Element = this->m_profileList.m_Memory.m_pMemory[v6].m_Element;
    if ( BotProfile::InheritsFrom(this: m_Element, name: profileName) != 0
      && BotProfile::IsValidForTeam(this: m_Element, team)
      && ((unsigned __int8)(1 << difficulty) & m_Element->m_difficultyFlags) != 0
      && !UTIL_IsNameTaken(name: m_Element->m_name, ignoreHumans: false) )
    {
      break;
    }
    m_Head = this->m_profileList.m_Memory.m_pMemory[v6].m_Next;
    if ( m_Head == 0xFFFF )
      return nullptr;
  }
  return m_Element;
}

//------------------------------------------------------------------------------
// Address: 0x102B6E40
// Name: public: virtual void CCSBotManager::ServerActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::ServerActivate(CCSBotManager *this)
{
  CCSBotManager *v1; // ebx
  void *v2; // esi
  unsigned int v3; // edi
  const char *i; // ebx
  const char *Token; // esi
  char *v6; // edi
  BotProfileManager *v7; // edi
  int j; // esi
  char *dataPointer; // [esp+10h] [ebp-4h]

  v1 = this;
  CCSBotManager::m_isMapDataLoaded = false;
  BotPhraseManager::Reset(this: TheBotPhrases);
  BotPhraseManager::Initialize(this: TheBotPhrases, filename: "BotChatter.db", bankIndex: 0);
  BotProfileManager::Reset(this: TheBotProfiles);
  BotProfileManager::FindVoiceBankIndex(this: TheBotProfiles, filename: "BotChatter.db");
  v2 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: "BotPackList.db", a3: "r", a4: 0);
  if ( v2 != nullptr )
  {
    v3 = filesystem->Size(this: &filesystem->IBaseFileSystem, a2: "BotPackList.db", a3: nullptr);
    dataPointer = (char *)operator new(nSize: v3);
    filesystem->Read(this: &filesystem->IBaseFileSystem, a2: dataPointer, a3: v3, a4: v2);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v2);
    for ( i = SharedParse(data: dataPointer); i != nullptr; i = SharedParse(data: i) )
    {
      Token = SharedGetToken();
      v6 = (char *)operator new(nSize: strlen(Token) + 1);
      strcpy(v6, Token);
      BotProfileManager::Init(this: TheBotProfiles, filename: v6, checksum: nullptr);
      free(pMem: v6);
    }
    free(pMem: dataPointer);
    v1 = this;
  }
  else
  {
    BotProfileManager::Init(this: TheBotProfiles, filename: "BotProfile.db", checksum: nullptr);
  }
  v7 = TheBotProfiles;
  for ( j = 1; j < v7->m_voiceBanks.m_Size; ++j )
    BotPhraseManager::Initialize(this: TheBotPhrases, filename: v7->m_voiceBanks.m_Memory.m_pMemory[j], bankIndex: j);
  CNavMesh::SetPlayerSpawnName(this: TheNavMesh, name: "info_player_terrorist");
  CCSBotManager::ExtractScenarioData(this: v1);
  v1->RestartRound(this: v1);
  BotPhraseManager::OnMapChange(this: TheBotPhrases);
  v1->m_serverActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x102B7000
// Name: public: bool CCSBotManager::BotAddCommand(int,bool,char const __near *,enum CSWeaponType,enum BotDifficultyType)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CCSBotManager::BotAddCommand(
        CCSBotManager *this,
        unsigned int team,
        bool isFromConsole,
        const char *profileName,
        CSWeaponType weaponType,
        BotDifficultyType difficulty)
{
  bool v7; // bl
  float m_fValue; // xmm0_4
  unsigned int v9; // esi
  char *m_pszString; // eax
  char *v11; // eax
  const BotProfile *Profile; // edi
  char *v13; // eax
  char *v14; // eax
  unsigned int v15; // [esp-14h] [ebp-14h]
  CGameTrace *v16; // [esp-10h] [ebp-10h]

  if ( !TheNavMesh->m_isLoaded )
  {
    if ( TheNavMesh->m_generationMode == GENERATE_NONE && !CCSBotManager::m_isMapDataLoaded )
    {
      CNavMesh::BeginGeneration(this: TheNavMesh, incremental: false);
      CCSBotManager::m_isMapDataLoaded = true;
    }
  }
  else if ( TheNavMesh->m_generationMode == GENERATE_NONE )
  {
    v7 = isFromConsole;
    if ( isFromConsole )
    {
      if ( difficulty == NUM_DIFFICULTY_LEVELS )
        difficulty = CCSBotManager::GetDifficultyLevel();
      v9 = team;
      if ( team == 0 )
      {
        if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = cv_bot_join_team.m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = (char *)locale;
        }
        if ( _V_stricmp(s1: m_pszString, s2: "T") != 0 )
        {
          if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
          {
            v11 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v11 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
            if ( v11 == nullptr )
              v11 = (char *)locale;
          }
          if ( _V_stricmp(s1: v11, s2: "CT") != 0 )
            v9 = CCSGameRules::SelectDefaultTeam(this: (CCSGameRules *)g_pGameRules, ignoreBots: false);
          else
            v9 = 3;
        }
        else
        {
          v9 = 2;
        }
      }
      if ( profileName != nullptr && *profileName != 0 )
      {
        if ( UTIL_IsNameTaken(name: profileName, ignoreHumans: false) )
        {
          _Msg(a1: "Error - %s is already in the game.\n", profileName);
          return 1;
        }
        Profile = BotProfileManager::GetProfile(this: TheBotProfiles, name: profileName, team: v9);
        if ( Profile == nullptr )
        {
          Profile = BotProfileManager::GetProfileMatchingTemplate(
                      this: TheBotProfiles,
                      profileName,
                      team: v9,
                      difficulty);
          if ( Profile == nullptr )
          {
            _Msg(a1: "Error - no profile for '%s' exists.\n", profileName);
            return 1;
          }
        }
        v7 = isFromConsole;
        goto LABEL_58;
      }
      v7 = isFromConsole;
    }
    else
    {
      m_fValue = cv_bot_difficulty.m_pParent->m_Value.m_fValue;
      v9 = team;
      if ( m_fValue >= 0.89999998 )
      {
        if ( m_fValue >= 1.9 )
        {
          if ( m_fValue >= 2.9000001 )
            difficulty = BOT_EXPERT;
          else
            difficulty = BOT_HARD;
        }
        else
        {
          difficulty = BOT_NORMAL;
        }
      }
      else
      {
        difficulty = BOT_EASY;
      }
    }
    if ( v9 == 0 )
    {
      if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
      {
        v13 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v13 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
        if ( v13 == nullptr )
          v13 = (char *)locale;
      }
      if ( _V_stricmp(s1: v13, s2: "T") != 0 )
      {
        if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
        {
          v14 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v14 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
          if ( v14 == nullptr )
            v14 = (char *)locale;
        }
        if ( _V_stricmp(s1: v14, s2: "CT") != 0 )
          v9 = CCSGameRules::SelectDefaultTeam(this: (CCSGameRules *)g_pGameRules, ignoreBots: false);
        else
          v9 = 3;
      }
      else
      {
        v9 = 2;
      }
    }
    Profile = BotProfileManager::GetRandomProfile(this: TheBotProfiles, difficulty, team: v9, weaponType);
    if ( Profile == nullptr )
    {
      if ( v7 )
        _Msg(a1: "All bot profiles at this difficulty level are in use.\n");
      return 1;
    }
LABEL_58:
    if ( v9 < 2 )
    {
      if ( v7 )
        _Msg(a1: "Could not add bot to the game: The game is full\n");
      return 0;
    }
    if ( CCSGameRules::TeamFull(this: (CCSGameRules *)g_pGameRules, team_id: v9) )
    {
      if ( v7 )
      {
        _Msg(a1: "Could not add bot to the game: Team is full\n");
        return 0;
      }
      return 0;
    }
    if ( CCSGameRules::TeamStacked(this: (CCSGameRules *)g_pGameRules, newTeam_id: v9, curTeam_id: 0) )
    {
      if ( v7 )
      {
        _Msg(
          a1: "Could not add bot to the game: Team is stacked (to disable this check, set mp_autoteambalance to zero, increas"
          "e mp_limitteams, and restart the round).\n");
        return 0;
      }
      return 0;
    }
    if ( CreateBot<CCSBot>(profile: Profile, team: v9) == nullptr )
    {
      if ( v7 )
      {
        _Msg(a1: "Error: CreateBot() failed.\n");
        return 0;
      }
      return 0;
    }
    if ( v7 )
    {
      if ( cv_bot_quota.m_pParent != nullptr )
      {
        CCollisionProperty::TestCollision(
          this: (ConVar *)&cv_bot_quota.IConVar,
          value: cv_bot_quota.m_pParent->m_Value.m_nValue + 1,
          fContentsMask: v15,
          tr: v16);
        return 1;
      }
      CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_quota.IConVar, value: 1, fContentsMask: v15, tr: v16);
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B7380
// Name: private: void CCSBotManager::MaintainBotQuota(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::MaintainBotQuota(CCSBotManager *this)
{
  ICommandLine *v1; // eax
  int v2; // esi
  int v3; // edi
  int m_nValue; // esi
  int v5; // eax
  bool v6; // zf
  bool v7; // bl
  char *m_pszString; // eax
  char *v9; // eax
  float v10; // xmm0_4
  int v11; // eax
  int v12; // ebx
  CCSGameRules *v13; // ecx
  char *v14; // eax
  char *v15; // eax
  bool v16; // al
  float m_fValue; // xmm0_4
  BotDifficultyType v18; // edi
  char *v19; // eax
  unsigned int v20; // esi
  char *v21; // eax
  const BotProfile *RandomProfile; // edi
  CAutoGameSystemPerFrame *m_pNext; // ecx
  const char *m_pszName; // edx
  int v25; // esi
  IUniformRandomStream *m_pszName_high; // ecx
  __int16 v27; // ax
  int numDeadTerrorist; // [esp+0h] [ebp-10h] BYREF
  int numDeadCT; // [esp+4h] [ebp-Ch] BYREF
  int numAliveTerrorist; // [esp+8h] [ebp-8h] BYREF
  int numAliveCT; // [esp+Ch] [ebp-4h] BYREF

  v1 = _CommandLine((CResponseRulesToEngineInterface *)this);
  if ( v1->CheckParm(this: v1, a2: "-nobots", a3: nullptr) != nullptr )
    return;
  if ( TheNavMesh->m_generationMode != GENERATE_NONE )
    return;
  v2 = UTIL_HumansInGame(ignoreSpectators: false);
  v3 = UTIL_HumansInGame(ignoreSpectators: true);
  if ( !engine->IsDedicatedServer(this: engine) && v2 == 0 )
    return;
  if ( g_pGameRules == nullptr || TheBots == nullptr )
    return;
  if ( cv_bot_quota.m_pParent != nullptr )
    m_nValue = cv_bot_quota.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v5 = UTIL_CSSBotsInGame();
  v6 = LOBYTE(g_pGameRules[133].m_pszName) == 0;
  numAliveCT = v5;
  v7 = !v6
    && TheBots[1].m_debugMessage[0].m_string[484] == 0
    && CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules) >= 20.0;
  if ( (cv_bot_quota_mode.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cv_bot_quota_mode.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  if ( FStrEq(sz1: m_pszString, sz2: "fill") )
  {
    if ( !v7 )
    {
      m_nValue = (m_nValue - v3) & ((m_nValue - v3 < 0) - 1);
      goto LABEL_32;
    }
  }
  else
  {
    if ( (cv_bot_quota_mode.m_nFlags & 0x1000) != 0 )
    {
      v9 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v9 = cv_bot_quota_mode.m_pParent->m_Value.m_pszString;
      if ( v9 == nullptr )
        v9 = (char *)locale;
    }
    if ( !FStrEq(sz1: v9, sz2: "match") )
      goto LABEL_32;
    if ( !v7 )
    {
      v10 = cv_bot_quota.m_pParent->m_Value.m_fValue * (float)v3;
      if ( v10 < 0.0 )
        v10 = 0.0;
      m_nValue = (int)v10;
      goto LABEL_32;
    }
  }
  m_nValue = numAliveCT;
LABEL_32:
  if ( cv_bot_join_after_player.m_pParent != nullptr
    && cv_bot_join_after_player.m_pParent->m_Value.m_nValue != 0
    && v3 == 0 )
  {
    m_nValue = 0;
  }
  if ( bot_join_delay.m_pParent != nullptr )
    numAliveTerrorist = bot_join_delay.m_pParent->m_Value.m_nValue;
  else
    *(float *)&numAliveTerrorist = 0.0;
  *(float *)&numAliveTerrorist = (float)numAliveTerrorist;
  if ( *(float *)&numAliveTerrorist > IntervalTimer::Now(this: (CEffectsServer *)g_pGameRules) )
    m_nValue = 0;
  if ( cv_bot_auto_vacate.m_pParent != nullptr && cv_bot_auto_vacate.m_pParent->m_Value.m_nValue != 0 )
    v11 = gpGlobals->maxClients - v3 - 1;
  else
    v11 = gpGlobals->maxClients - v3;
  if ( m_nValue >= v11 )
    m_nValue = v11;
  v12 = numAliveCT;
  if ( numAliveCT > 0 && m_nValue == numAliveCT )
  {
    v13 = (CCSGameRules *)g_pGameRules;
    if ( LOBYTE(g_pGameRules[133].m_pszName) == 0 )
      goto LABEL_69;
    if ( CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules) < 20.0
      && mp_autoteambalance.m_pParent != nullptr
      && mp_autoteambalance.m_pParent->m_Value.m_nValue != 0 )
    {
      CCSGameRules::InitializePlayerCounts(
        this: (CCSGameRules *)g_pGameRules,
        NumAliveTerrorist: &numAliveTerrorist,
        NumAliveCT: &numAliveCT,
        NumDeadTerrorist: &numDeadTerrorist,
        NumDeadCT: &numDeadCT);
      if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
      {
        v14 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v14 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
        if ( v14 == nullptr )
          v14 = (char *)locale;
      }
      if ( !FStrEq(sz1: v14, sz2: "T") )
      {
        if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
        {
          v15 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v15 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
          if ( v15 == nullptr )
            v15 = (char *)locale;
        }
        if ( !FStrEq(sz1: v15, sz2: "CT") )
        {
          v13 = (CCSGameRules *)g_pGameRules;
          if ( numAliveTerrorist <= (int)(g_pGameRules[132].m_pszName + 1) )
          {
            if ( numAliveCT <= (int)&g_pGameRules[132].m_pNext->CAutoGameSystemPerFrame::__vftable + 1 )
              goto LABEL_69;
            v16 = UTIL_KickBotFromTeam(kickTeam: 3);
          }
          else
          {
            v16 = UTIL_KickBotFromTeam(kickTeam: 2);
          }
          if ( v16 )
            return;
        }
      }
    }
  }
  v13 = (CCSGameRules *)g_pGameRules;
LABEL_69:
  if ( m_nValue <= v12 )
  {
    if ( m_nValue < v12 && UTIL_CSSKickBotFromTeam(kickTeam: 0) == 0 )
    {
      m_pNext = g_pGameRules[132].m_pNext;
      m_pszName = g_pGameRules[132].m_pszName;
      if ( (int)m_pNext <= (int)m_pszName )
      {
        if ( (int)m_pNext >= (int)m_pszName )
        {
          m_pszName_high = (IUniformRandomStream *)HIWORD(g_pGameRules[134].m_pszName);
          v27 = (__int16)g_pGameRules[134].m_pszName;
          if ( v27 >= (__int16)m_pszName_high )
            v25 = v27 <= (__int16)m_pszName_high ? 3 - (_RandomInt(this: m_pszName_high, a2: 0, a3: 1) != 0) : 3;
          else
            v25 = 2;
        }
        else
        {
          v25 = 3;
        }
      }
      else
      {
        v25 = 2;
      }
      if ( UTIL_CSSKickBotFromTeam(kickTeam: v25) == 0 )
      {
        if ( v25 == 2 )
          UTIL_CSSKickBotFromTeam(kickTeam: 3);
        else
          UTIL_CSSKickBotFromTeam(kickTeam: 2);
      }
    }
  }
  else if ( !CCSGameRules::TeamFull(this: v13, team_id: 2)
         || !CCSGameRules::TeamFull(this: (CCSGameRules *)g_pGameRules, team_id: 3) )
  {
    if ( TheNavMesh->m_isLoaded )
    {
      if ( TheNavMesh->m_generationMode == GENERATE_NONE )
      {
        m_fValue = cv_bot_difficulty.m_pParent->m_Value.m_fValue;
        if ( m_fValue >= 0.89999998 )
        {
          if ( m_fValue >= 1.9 )
          {
            v18 = BOT_HARD;
            if ( m_fValue >= 2.9000001 )
              v18 = BOT_EXPERT;
          }
          else
          {
            v18 = BOT_NORMAL;
          }
        }
        else
        {
          v18 = BOT_EASY;
        }
        if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
        {
          v19 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v19 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
          if ( v19 == nullptr )
            v19 = (char *)locale;
        }
        if ( _V_stricmp(s1: v19, s2: "T") != 0 )
        {
          if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
          {
            v21 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v21 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
            if ( v21 == nullptr )
              v21 = (char *)locale;
          }
          if ( _V_stricmp(s1: v21, s2: "CT") != 0 )
            v20 = CCSGameRules::SelectDefaultTeam(this: (CCSGameRules *)g_pGameRules, ignoreBots: false);
          else
            v20 = 3;
        }
        else
        {
          v20 = 2;
        }
        RandomProfile = BotProfileManager::GetRandomProfile(
                          this: TheBotProfiles,
                          difficulty: v18,
                          team: v20,
                          weaponType: WEAPONTYPE_UNKNOWN);
        if ( RandomProfile != nullptr
          && v20 >= 2
          && !CCSGameRules::TeamFull(this: (CCSGameRules *)g_pGameRules, team_id: v20)
          && !CCSGameRules::TeamStacked(this: (CCSGameRules *)g_pGameRules, newTeam_id: v20, curTeam_id: 0) )
        {
          CreateBot<CCSBot>(profile: RandomProfile, team: v20);
        }
      }
    }
    else if ( TheNavMesh->m_generationMode == GENERATE_NONE && !CCSBotManager::m_isMapDataLoaded )
    {
      CNavMesh::BeginGeneration(this: TheNavMesh, incremental: false);
      CCSBotManager::m_isMapDataLoaded = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B78D0
// Name: public: void CCSBotManager::CheckForBlockedZones(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::CheckForBlockedZones(CCSBotManager *this)
{
  CBaseEntity *v1; // esi
  CNavArea *NearestNavArea; // ebx
  int v3; // edi
  CNavArea **m_area; // esi
  bool v5; // al
  Vector spawnPos; // [esp+50h] [ebp-14h] BYREF
  CCSBotManager *v7; // [esp+5Ch] [ebp-8h]
  ShortestPathCost costFunc; // [esp+63h] [ebp-1h] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  v7 = this;
  v1 = SelectSpawnSpot(pEntClassName: "info_player_counterterrorist", a2: (int)&savedregs);
  if ( v1 != nullptr || (v1 = SelectSpawnSpot(pEntClassName: "info_player_terrorist", a2: (int)&savedregs)) != nullptr )
  {
    if ( (v1->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v1, a2: (int)&savedregs);
    spawnPos = v1->m_vecAbsOrigin;
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: &spawnPos,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    if ( NearestNavArea != nullptr )
    {
      v3 = 0;
      if ( v7->m_zoneCount > 0 )
      {
        m_area = v7->m_zone[0].m_area;
        do
        {
          if ( m_area[16] != nullptr )
          {
            v5 = NavAreaTravelDistance<ShortestPathCost>(
                   startArea: NearestNavArea,
                   endArea: *m_area,
                   &costFunc,
                   maxPathLength: 0.0) < 0.0;
            *((_BYTE *)m_area + 88) = v5;
            if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue == 5 && v5 )
              DevMsg(
                a1: "%.1f: Zone %d, area %d (%.0f %.0f %.0f) is blocked from spawn area %d (%.0f %.0f %.0f)\n",
                gpGlobals->curtime,
                v3,
                (*m_area)->m_id,
                (*m_area)->m_center.x,
                (*m_area)->m_center.y,
                (*m_area)->m_center.z,
                NearestNavArea->m_id,
                spawnPos.x,
                spawnPos.y,
                spawnPos.z);
          }
          ++v3;
          m_area += 30;
        }
        while ( v3 < v7->m_zoneCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7A70
// Name: public: virtual void CCSBotManager::OnRoundFreezeEnd(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnRoundFreezeEnd(CCSBotManager *this, IGameEvent *event)
{
  bool m_enabled; // al
  CCSBotManager::NavBlockedEvent *p_m_NavBlockedEvent; // ebx
  CNavMesh *v4; // esi
  int i; // edi
  CNavArea *v6; // ecx
  bool reenableEvents; // [esp+13h] [ebp-1h]

  m_enabled = this->m_NavBlockedEvent.m_enabled;
  p_m_NavBlockedEvent = &this->m_NavBlockedEvent;
  this->m_NavBlockedEvent.m_enabled = false;
  reenableEvents = m_enabled;
  gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_NavBlockedEvent);
  v4 = TheNavMesh;
  for ( i = 0; i < v4->m_transientAreas.m_Size; ++i )
  {
    v6 = v4->m_transientAreas.m_Memory.m_pMemory[i];
    if ( (v6->m_attributeFlags & 0x100) != 0 )
      v6->UpdateBlocked(this: v6, a2: false, a3: -1);
  }
  if ( reenableEvents )
  {
    p_m_NavBlockedEvent->m_enabled = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: p_m_NavBlockedEvent, a3: "nav_blocked", a4: true);
  }
  CCSBotManager::CheckForBlockedZones(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B7B10
// Name: public: virtual void CCSBotManager::OnNavBlocked(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::OnNavBlocked(CCSBotManager *this, IGameEvent *event)
{
  int v2; // edi
  IGameEvent *v3; // ebx
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  CCSBot *v6; // eax
  CBaseEntity *v7; // esi
  CNavArea *NearestNavArea; // ebx
  int v9; // edi
  CNavArea **m_area; // esi
  bool v11; // al
  Vector pos; // [esp+50h] [ebp-10h] BYREF
  CCSBotManager *v13; // [esp+5Ch] [ebp-4h]
  int savedregs; // [esp+60h] [ebp+0h] BYREF

  v2 = 1;
  v13 = this;
  if ( gpGlobals->maxClients >= 1 )
  {
    v3 = event;
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v2);
      v5 = v4;
      if ( v4 != nullptr && v4->IsBot(this: v4) )
      {
        v6 = (CCSBot *)__RTDynamicCast(
                         inptr: v5,
                         VfDelta: 0,
                         SrcType: &CBasePlayer `RTTI Type Descriptor',
                         TargetType: &CCSBot `RTTI Type Descriptor',
                         isReference: 0);
        if ( v6 != nullptr )
          CCSBot::OnNavBlocked(this: v6, event: v3);
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
  }
  v7 = SelectSpawnSpot(pEntClassName: "info_player_counterterrorist", a2: (int)&savedregs);
  if ( v7 != nullptr || (v7 = SelectSpawnSpot(pEntClassName: "info_player_terrorist", a2: (int)&savedregs)) != nullptr )
  {
    if ( (v7->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
    pos = v7->m_vecAbsOrigin;
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       &pos,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    if ( NearestNavArea != nullptr )
    {
      v9 = 0;
      if ( v13->m_zoneCount > 0 )
      {
        m_area = v13->m_zone[0].m_area;
        do
        {
          if ( m_area[16] != nullptr )
          {
            v11 = NavAreaTravelDistance<ShortestPathCost>(
                    startArea: NearestNavArea,
                    endArea: *m_area,
                    costFunc: (ShortestPathCost *)&event + 3,
                    maxPathLength: 0.0) < 0.0;
            *((_BYTE *)m_area + 88) = v11;
            if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue == 5 && v11 )
              DevMsg(
                a1: "%.1f: Zone %d, area %d (%.0f %.0f %.0f) is blocked from spawn area %d (%.0f %.0f %.0f)\n",
                gpGlobals->curtime,
                v9,
                (*m_area)->m_id,
                (*m_area)->m_center.x,
                (*m_area)->m_center.y,
                (*m_area)->m_center.z,
                NearestNavArea->m_id,
                pos.x,
                pos.y,
                pos.z);
          }
          ++v9;
          m_area += 30;
        }
        while ( v9 < v13->m_zoneCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7D10
// Name: CheckAreaAgainstAllZoneAreas
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckAreaAgainstAllZoneAreas(CNavArea *queryArea)
{
  CBotManager *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  CNavArea **v6; // edi
  CNavArea *zoneArea; // [esp+10h] [ebp-14h]
  int goalZoneCount; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int zoneIndex; // [esp+1Ch] [ebp-8h]
  ShortestPathCost cost; // [esp+23h] [ebp-1h] BYREF

  v1 = TheBots;
  v2 = *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[456];
  v3 = 0;
  goalZoneCount = v2;
  zoneIndex = 0;
  if ( v2 <= 0 )
    return 1;
  v10 = 0;
  while ( 1 )
  {
    v4 = *(_DWORD *)&v1[1].m_debugMessage[0].m_string[v3 + 44];
    v5 = 0;
    if ( v4 > 0 )
      break;
LABEL_8:
    v3 += 120;
    ++zoneIndex;
    v10 = v3;
    if ( zoneIndex >= v2 )
      return 1;
  }
  v6 = (CNavArea **)((char *)&v1[1].m_activeGrenadeList.m_Memory.m_nGrowSize + v3);
  while ( 1 )
  {
    zoneArea = *v6;
    if ( NavAreaTravelDistance<ShortestPathCost>(
           startArea: queryArea,
           endArea: *v6,
           costFunc: &cost,
           maxPathLength: 0.0) == -1.0 )
      break;
    ++v5;
    ++v6;
    if ( v5 >= v4 )
    {
      v1 = TheBots;
      v2 = goalZoneCount;
      v3 = v10;
      goto LABEL_8;
    }
  }
  _Msg(a1: "Area #%d is disconnected from goal area #%d.\n", queryArea->m_id, zoneArea->m_id);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B7DD0
// Name: nav_check_connectivity
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_check_connectivity()
{
  CNavArea *MarkedArea; // esi
  int v1; // eax
  CBotManager *v2; // ecx
  int v3; // edx
  int v4; // edi
  int v5; // esi
  CNavArea **v6; // edi
  CNavArea *v7; // ebx
  double v8; // st7
  float start; // [esp+10h] [ebp-20h]
  int v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h]
  int nit; // [esp+1Ch] [ebp-14h]
  CNavArea *startArea; // [esp+20h] [ebp-10h]
  int v14; // [esp+24h] [ebp-Ch]
  int v15; // [esp+28h] [ebp-8h]
  ShortestPathCost costFunc; // [esp+2Fh] [ebp-1h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( CNavMesh::GetMarkedArea(this: TheNavMesh) != nullptr )
    {
      MarkedArea = CNavMesh::GetMarkedArea(this: TheNavMesh);
      if ( CheckAreaAgainstAllZoneAreas(queryArea: MarkedArea) != 0 )
        _Msg(a1: "Area #%d is connected to all goal areas.\n", MarkedArea->m_id);
    }
    else
    {
      start = _Plat_FloatTime();
      v1 = 0;
      nit = 0;
      if ( TheNavAreas.m_Size > 0 )
      {
        v2 = TheBots;
        do
        {
          v3 = *(_DWORD *)&v2[1].m_debugMessage[0].m_string[456];
          v4 = 0;
          startArea = TheNavAreas.m_Memory.m_pMemory[v1];
          v10 = v3;
          v15 = 0;
          if ( v3 > 0 )
          {
            v14 = 0;
            while ( 1 )
            {
              v5 = 0;
              v11 = *(_DWORD *)&v2[1].m_debugMessage[0].m_string[v4 + 44];
              if ( v11 > 0 )
                break;
LABEL_14:
              v4 += 120;
              ++v15;
              v14 = v4;
              if ( v15 >= v3 )
                goto LABEL_17;
            }
            v6 = (CNavArea **)((char *)&v2[1].m_activeGrenadeList.m_Memory.m_nGrowSize + v4);
            while ( 1 )
            {
              v7 = *v6;
              if ( NavAreaTravelDistance<ShortestPathCost>(startArea, endArea: *v6, &costFunc, maxPathLength: 0.0) == -1.0 )
                break;
              ++v5;
              ++v6;
              if ( v5 >= v11 )
              {
                v2 = TheBots;
                v3 = v10;
                v4 = v14;
                goto LABEL_14;
              }
            }
            _Msg(a1: "Area #%d is disconnected from goal area #%d.\n", startArea->m_id, v7->m_id);
            v2 = TheBots;
          }
LABEL_17:
          v1 = nit + 1;
          nit = v1;
        }
        while ( v1 < TheNavAreas.m_Size );
      }
      v8 = _Plat_FloatTime();
      _Msg(a1: "nav_check_connectivity took %2.2f ms\n", (v8 - start) * 1000.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7F50
// Name: public: virtual void CCSBotManager::StartFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::StartFrame(CCSBotManager *this)
{
  ICommandLine *v2; // eax
  int v3; // eax
  int v4; // ebx
  Extent *p_m_extent; // esi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  CNavMesh *v7; // edi
  int i; // esi
  CNavArea *v9; // ecx
  CEffectsServer *v10; // esi
  double v11; // st7
  float v12; // xmm0_4
  IPredictionSystem **p_m_pNextSystem; // esi
  CEffectsServer *p_m_checkTransientAreasTimer; // [esp+4h] [ebp-4h]
  float v15; // [esp+4h] [ebp-4h]

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  if ( v2->CheckParm(this: v2, a2: "-nobots", a3: nullptr) != nullptr )
  {
    CCSBotManager::EnableEventListeners(this, enable: false);
  }
  else
  {
    CBotManager::StartFrame(this);
    CCSBotManager::MaintainBotQuota(this);
    v3 = UTIL_CSSBotsInGame();
    CCSBotManager::EnableEventListeners(this, enable: v3 > 0);
    if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue == 5 )
    {
      v4 = 0;
      if ( this->m_zoneCount > 0 )
      {
        p_m_extent = &this->m_zone[0].m_extent;
        do
        {
          if ( LOBYTE(p_m_extent[-1].hi.z) != 0 )
            UTIL_DrawBox(extent: p_m_extent, lifetime: 1, red: 255, green: 0, blue: 200);
          else
            UTIL_DrawBox(extent: p_m_extent, lifetime: 1, red: 255, green: 100, blue: 0);
          ++v4;
          p_m_extent += 5;
        }
        while ( v4 < this->m_zoneCount );
      }
    }
    if ( bot_show_occupy_time.m_pParent != nullptr && bot_show_occupy_time.m_pParent->m_Value.m_nValue != 0 )
      DrawOccupyTime();
    if ( bot_show_battlefront.m_pParent != nullptr && bot_show_battlefront.m_pParent->m_Value.m_nValue != 0 )
      DrawBattlefront();
    p_m_checkTransientAreasTimer = (CEffectsServer *)&this->m_checkTransientAreasTimer;
    p_m_timestamp = &this->m_checkTransientAreasTimer.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_checkTransientAreasTimer) > this->m_checkTransientAreasTimer.m_timestamp.m_Value
      && (nav_edit.m_pParent == nullptr || nav_edit.m_pParent->m_Value.m_nValue == 0) )
    {
      v7 = TheNavMesh;
      for ( i = 0; i < v7->m_transientAreas.m_Size; ++i )
      {
        v9 = v7->m_transientAreas.m_Memory.m_pMemory[i];
        if ( (v9->m_attributeFlags & 0x100) != 0 )
          v9->UpdateBlocked(this: v9, a2: false, a3: -1);
      }
      v10 = p_m_checkTransientAreasTimer;
      v11 = IntervalTimer::Now(this: p_m_checkTransientAreasTimer) + 2.0;
      if ( p_m_timestamp->m_Value != v11 )
      {
        (*(void (__thiscall **)(int, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))LODWORD(p_m_timestamp[-2].m_Value))(
          a1: (int)&p_m_timestamp[-2],
          a2: p_m_timestamp);
        v15 = v11;
        p_m_timestamp->m_Value = v15;
      }
      v12 = *(float *)&v10->m_pNextSystem;
      p_m_pNextSystem = &v10->m_pNextSystem;
      if ( v12 != 2.0 )
      {
        ((void (__thiscall *)(IPredictionSystem **, IPredictionSystem **))(*(p_m_pNextSystem - 1))->__vftable)(
          a1: p_m_pNextSystem - 1,
          a2: p_m_pNextSystem);
        *p_m_pNextSystem = (IPredictionSystem *)0x40000000;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B80F0
// Name: bot_add
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_add(const CCommand *args)
{
  int team; // [esp+0h] [ebp-10h] BYREF
  const char *name; // [esp+4h] [ebp-Ch] BYREF
  CSWeaponType weaponType; // [esp+8h] [ebp-8h] BYREF
  BotDifficultyType difficulty; // [esp+Ch] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    BotArgumentsFromArgv(args, &name, &weaponType, &difficulty, &team, all: nullptr);
    CCSBotManager::BotAddCommand(
      this: (CCSBotManager *)TheBots,
      team,
      isFromConsole: true,
      profileName: name,
      weaponType,
      difficulty);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8140
// Name: bot_add_t
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_add_t(const CCommand *args)
{
  const char *name; // [esp+0h] [ebp-Ch] BYREF
  CSWeaponType weaponType; // [esp+4h] [ebp-8h] BYREF
  BotDifficultyType difficulty; // [esp+8h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    BotArgumentsFromArgv(args, &name, &weaponType, &difficulty, team: nullptr, all: nullptr);
    CCSBotManager::BotAddCommand(
      this: (CCSBotManager *)TheBots,
      team: 2u,
      isFromConsole: true,
      profileName: name,
      weaponType,
      difficulty);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B8190
// Name: bot_add_ct
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_add_ct(const CCommand *args)
{
  const char *name; // [esp+0h] [ebp-Ch] BYREF
  CSWeaponType weaponType; // [esp+4h] [ebp-8h] BYREF
  BotDifficultyType difficulty; // [esp+8h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    BotArgumentsFromArgv(args, &name, &weaponType, &difficulty, team: nullptr, all: nullptr);
    CCSBotManager::BotAddCommand(
      this: (CCSBotManager *)TheBots,
      team: 3u,
      isFromConsole: true,
      profileName: name,
      weaponType,
      difficulty);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B81E0
// Name: public: CCSBotManager::CCSBotManager(void)
// Source: json
//------------------------------------------------------------------------------
CCSBotManager *__thiscall CCSBotManager::CCSBotManager(CCSBotManager *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  int v4; // eax
  int m_nAllocationCount; // ecx
  BotEventInterface **m_pMemory; // edx
  int v7; // ecx
  BotEventInterface **v8; // eax
  int v9; // ecx
  int v10; // eax
  BotEventInterface **v11; // edx
  int v12; // eax
  BotEventInterface **v13; // ecx
  int v14; // ecx
  int v15; // eax
  BotEventInterface **v16; // edx
  int v17; // eax
  BotEventInterface **v18; // ecx
  int v19; // ecx
  int v20; // eax
  BotEventInterface **v21; // edx
  int v22; // eax
  BotEventInterface **v23; // ecx
  int v24; // ecx
  int v25; // eax
  BotEventInterface **v26; // edx
  int v27; // eax
  BotEventInterface **v28; // ecx
  int v29; // ecx
  int v30; // eax
  BotEventInterface **v31; // edx
  int v32; // eax
  BotEventInterface **v33; // ecx
  int v34; // ecx
  int v35; // eax
  BotEventInterface **v36; // edx
  int v37; // eax
  BotEventInterface **v38; // ecx
  int v39; // ecx
  int v40; // eax
  BotEventInterface **v41; // edx
  int v42; // eax
  BotEventInterface **v43; // ecx
  int v44; // ecx
  int v45; // eax
  BotEventInterface **v46; // edx
  int v47; // eax
  BotEventInterface **v48; // ecx
  int v49; // ecx
  int v50; // eax
  BotEventInterface **v51; // edx
  int v52; // eax
  BotEventInterface **v53; // ecx
  int v54; // ecx
  int v55; // eax
  BotEventInterface **v56; // edx
  int v57; // eax
  BotEventInterface **v58; // ecx
  int v59; // ecx
  int v60; // eax
  BotEventInterface **v61; // edx
  int v62; // eax
  BotEventInterface **v63; // ecx
  int v64; // ecx
  int v65; // eax
  BotEventInterface **v66; // edx
  int v67; // eax
  BotEventInterface **v68; // ecx
  int v69; // ecx
  int v70; // eax
  BotEventInterface **v71; // edx
  int v72; // eax
  BotEventInterface **v73; // ecx
  BotPhraseManager *v74; // eax
  BotProfileManager *v75; // eax
  int m_Size; // [esp+Ch] [ebp-4h]
  int v78; // [esp+Ch] [ebp-4h]
  int v79; // [esp+Ch] [ebp-4h]
  int v80; // [esp+Ch] [ebp-4h]
  int v81; // [esp+Ch] [ebp-4h]
  int v82; // [esp+Ch] [ebp-4h]
  int v83; // [esp+Ch] [ebp-4h]
  int v84; // [esp+Ch] [ebp-4h]
  int v85; // [esp+Ch] [ebp-4h]
  int v86; // [esp+Ch] [ebp-4h]
  int v87; // [esp+Ch] [ebp-4h]
  int v88; // [esp+Ch] [ebp-4h]
  int v89; // [esp+Ch] [ebp-4h]
  int v90; // [esp+Ch] [ebp-4h]

  CBotManager::CBotManager(this);
  this->__vftable = (CCSBotManager_vtbl *)&CCSBotManager::`vftable';
  this->m_looseBomb.m_Index = -1;
  this->m_checkTransientAreasTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_checkTransientAreasTimer.__vftable;
  this->m_checkTransientAreasTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_checkTransientAreasTimer.m_duration);
  v3 = this->m_checkTransientAreasTimer.__vftable;
  this->m_checkTransientAreasTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_checkTransientAreasTimer, a2: &this->m_checkTransientAreasTimer.m_timestamp);
  this->m_PlayerFootstepEvent.__vftable = (CCSBotManager::PlayerFootstepEvent_vtbl *)&CCSBotManager::PlayerFootstepEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_PlayerFootstepEvent,
    a3: "player_footstep",
    a4: true);
  this->m_PlayerFootstepEvent.m_enabled = true;
  this->m_PlayerRadioEvent.__vftable = (CCSBotManager::PlayerRadioEvent_vtbl *)&CCSBotManager::PlayerRadioEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_PlayerRadioEvent, a3: "player_radio", a4: true);
  this->m_PlayerRadioEvent.m_enabled = true;
  this->m_PlayerDeathEvent.__vftable = (CCSBotManager::PlayerDeathEvent_vtbl *)&CCSBotManager::PlayerDeathEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_PlayerDeathEvent, a3: "player_death", a4: true);
  this->m_PlayerDeathEvent.m_enabled = true;
  this->m_PlayerFallDamageEvent.__vftable = (CCSBotManager::PlayerFallDamageEvent_vtbl *)&CCSBotManager::PlayerFallDamageEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_PlayerFallDamageEvent,
    a3: "player_falldamage",
    a4: true);
  this->m_PlayerFallDamageEvent.m_enabled = true;
  this->m_BombPickedUpEvent.__vftable = (CCSBotManager::BombPickedUpEvent_vtbl *)&CCSBotManager::BombPickedUpEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BombPickedUpEvent, a3: "bomb_pickup", a4: true);
  this->m_BombPickedUpEvent.m_enabled = true;
  this->m_BombPlantedEvent.__vftable = (CCSBotManager::BombPlantedEvent_vtbl *)&CCSBotManager::BombPlantedEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BombPlantedEvent, a3: "bomb_planted", a4: true);
  this->m_BombPlantedEvent.m_enabled = true;
  this->m_BombBeepEvent.__vftable = (CCSBotManager::BombBeepEvent_vtbl *)&CCSBotManager::BombBeepEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BombBeepEvent, a3: "bomb_beep", a4: true);
  this->m_BombBeepEvent.m_enabled = true;
  this->m_BombDefuseBeginEvent.__vftable = (CCSBotManager::BombDefuseBeginEvent_vtbl *)&CCSBotManager::BombDefuseBeginEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_BombDefuseBeginEvent,
    a3: "bomb_begindefuse",
    a4: true);
  this->m_BombDefuseBeginEvent.m_enabled = true;
  this->m_BombDefusedEvent.__vftable = (CCSBotManager::BombDefusedEvent_vtbl *)&CCSBotManager::BombDefusedEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BombDefusedEvent, a3: "bomb_defused", a4: true);
  this->m_BombDefusedEvent.m_enabled = true;
  this->m_BombDefuseAbortEvent.__vftable = (CCSBotManager::BombDefuseAbortEvent_vtbl *)&CCSBotManager::BombDefuseAbortEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_BombDefuseAbortEvent,
    a3: "bomb_abortdefuse",
    a4: true);
  this->m_BombDefuseAbortEvent.m_enabled = true;
  this->m_BombExplodedEvent.__vftable = (CCSBotManager::BombExplodedEvent_vtbl *)&CCSBotManager::BombExplodedEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BombExplodedEvent, a3: "bomb_exploded", a4: true);
  this->m_BombExplodedEvent.m_enabled = true;
  this->m_RoundEndEvent.__vftable = (CCSBotManager::RoundEndEvent_vtbl *)&CCSBotManager::RoundEndEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_RoundEndEvent, a3: "round_end", a4: true);
  this->m_RoundEndEvent.m_enabled = true;
  this->m_RoundStartEvent.__vftable = (CCSBotManager::RoundStartEvent_vtbl *)&CCSBotManager::RoundStartEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_RoundStartEvent, a3: "round_start", a4: true);
  this->m_RoundStartEvent.m_enabled = true;
  this->m_RoundFreezeEndEvent.__vftable = (CCSBotManager::RoundFreezeEndEvent_vtbl *)&CCSBotManager::RoundFreezeEndEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_RoundFreezeEndEvent,
    a3: "round_freeze_end",
    a4: true);
  this->m_RoundFreezeEndEvent.m_enabled = true;
  this->m_DoorMovingEvent.__vftable = (CCSBotManager::DoorMovingEvent_vtbl *)&CCSBotManager::DoorMovingEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_DoorMovingEvent, a3: "door_moving", a4: true);
  this->m_DoorMovingEvent.m_enabled = true;
  this->m_BreakPropEvent.__vftable = (CCSBotManager::BreakPropEvent_vtbl *)&CCSBotManager::BreakPropEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BreakPropEvent, a3: "break_prop", a4: true);
  this->m_BreakPropEvent.m_enabled = true;
  this->m_BreakBreakableEvent.__vftable = (CCSBotManager::BreakBreakableEvent_vtbl *)&CCSBotManager::BreakBreakableEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_BreakBreakableEvent,
    a3: "break_breakable",
    a4: true);
  this->m_BreakBreakableEvent.m_enabled = true;
  this->m_HostageFollowsEvent.__vftable = (CCSBotManager::HostageFollowsEvent_vtbl *)&CCSBotManager::HostageFollowsEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_HostageFollowsEvent,
    a3: "hostage_follows",
    a4: true);
  this->m_HostageFollowsEvent.m_enabled = true;
  this->m_HostageRescuedAllEvent.__vftable = (CCSBotManager::HostageRescuedAllEvent_vtbl *)&CCSBotManager::HostageRescuedAllEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_HostageRescuedAllEvent,
    a3: "hostage_rescued_all",
    a4: true);
  this->m_HostageRescuedAllEvent.m_enabled = true;
  this->m_WeaponFireEvent.__vftable = (CCSBotManager::WeaponFireEvent_vtbl *)&CCSBotManager::WeaponFireEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_WeaponFireEvent, a3: "weapon_fire", a4: true);
  this->m_WeaponFireEvent.m_enabled = true;
  this->m_WeaponFireOnEmptyEvent.__vftable = (CCSBotManager::WeaponFireOnEmptyEvent_vtbl *)&CCSBotManager::WeaponFireOnEmptyEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_WeaponFireOnEmptyEvent,
    a3: "weapon_fire_on_empty",
    a4: true);
  this->m_WeaponFireOnEmptyEvent.m_enabled = true;
  this->m_WeaponReloadEvent.__vftable = (CCSBotManager::WeaponReloadEvent_vtbl *)&CCSBotManager::WeaponReloadEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_WeaponReloadEvent, a3: "weapon_reload", a4: true);
  this->m_WeaponReloadEvent.m_enabled = true;
  this->m_WeaponZoomEvent.__vftable = (CCSBotManager::WeaponZoomEvent_vtbl *)&CCSBotManager::WeaponZoomEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_WeaponZoomEvent, a3: "weapon_zoom", a4: true);
  this->m_WeaponZoomEvent.m_enabled = true;
  this->m_BulletImpactEvent.__vftable = (CCSBotManager::BulletImpactEvent_vtbl *)&CCSBotManager::BulletImpactEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_BulletImpactEvent, a3: "bullet_impact", a4: true);
  this->m_BulletImpactEvent.m_enabled = true;
  this->m_HEGrenadeDetonateEvent.__vftable = (CCSBotManager::HEGrenadeDetonateEvent_vtbl *)&CCSBotManager::HEGrenadeDetonateEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_HEGrenadeDetonateEvent,
    a3: "hegrenade_detonate",
    a4: true);
  this->m_HEGrenadeDetonateEvent.m_enabled = true;
  this->m_FlashbangDetonateEvent.__vftable = (CCSBotManager::FlashbangDetonateEvent_vtbl *)&CCSBotManager::FlashbangDetonateEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_FlashbangDetonateEvent,
    a3: "flashbang_detonate",
    a4: true);
  this->m_FlashbangDetonateEvent.m_enabled = true;
  this->m_SmokeGrenadeDetonateEvent.__vftable = (CCSBotManager::SmokeGrenadeDetonateEvent_vtbl *)&CCSBotManager::SmokeGrenadeDetonateEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_SmokeGrenadeDetonateEvent,
    a3: "smokegrenade_detonate",
    a4: true);
  this->m_SmokeGrenadeDetonateEvent.m_enabled = true;
  this->m_MolotovDetonateEvent.__vftable = (CCSBotManager::MolotovDetonateEvent_vtbl *)&CCSBotManager::MolotovDetonateEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_MolotovDetonateEvent,
    a3: "molotov_detonate",
    a4: true);
  this->m_MolotovDetonateEvent.m_enabled = true;
  this->m_DecoyDetonateEvent.__vftable = (CCSBotManager::DecoyDetonateEvent_vtbl *)&CCSBotManager::DecoyDetonateEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_DecoyDetonateEvent, a3: "decoy_detonate", a4: true);
  this->m_DecoyDetonateEvent.m_enabled = true;
  this->m_DecoyFiringEvent.__vftable = (CCSBotManager::DecoyFiringEvent_vtbl *)&CCSBotManager::DecoyFiringEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_DecoyFiringEvent, a3: "decoy_firing", a4: true);
  this->m_DecoyFiringEvent.m_enabled = true;
  this->m_GrenadeBounceEvent.__vftable = (CCSBotManager::GrenadeBounceEvent_vtbl *)&CCSBotManager::GrenadeBounceEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_GrenadeBounceEvent, a3: "grenade_bounce", a4: true);
  this->m_GrenadeBounceEvent.m_enabled = true;
  this->m_NavBlockedEvent.__vftable = (CCSBotManager::NavBlockedEvent_vtbl *)&CCSBotManager::NavBlockedEvent::`vftable';
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->m_NavBlockedEvent, a3: "nav_blocked", a4: true);
  this->m_NavBlockedEvent.m_enabled = true;
  this->m_ServerShutdownEvent.__vftable = (CCSBotManager::ServerShutdownEvent_vtbl *)&CCSBotManager::ServerShutdownEvent::`vftable';
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->m_ServerShutdownEvent,
    a3: "server_shutdown",
    a4: true);
  this->m_ServerShutdownEvent.m_enabled = true;
  this->m_commonEventListeners.m_Memory.m_pMemory = nullptr;
  this->m_commonEventListeners.m_Memory.m_nAllocationCount = 0;
  this->m_commonEventListeners.m_Memory.m_nGrowSize = 0;
  this->m_commonEventListeners.m_Size = 0;
  this->m_commonEventListeners.m_pElements = nullptr;
  this->m_zoneCount = 0;
  this->m_looseBomb.m_Index = -1;
  this->m_looseBombArea = nullptr;
  this->m_serverActive = false;
  this->m_isBombPlanted = false;
  this->m_bombDefuser = nullptr;
  this->m_roundStartTimestamp = 0.0;
  this->m_eventListenersEnabled = true;
  m_nAllocationCount = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  m_Size = this->m_commonEventListeners.m_Size;
  v4 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: m_Size - m_nAllocationCount + 1);
    v4 = m_Size;
  }
  ++this->m_commonEventListeners.m_Size;
  m_pMemory = this->m_commonEventListeners.m_Memory.m_pMemory;
  v7 = this->m_commonEventListeners.m_Size - v4 - 1;
  this->m_commonEventListeners.m_pElements = m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 4 * v7);
    v4 = m_Size;
  }
  v8 = &this->m_commonEventListeners.m_Memory.m_pMemory[v4];
  if ( v8 != nullptr )
    *v8 = &this->m_PlayerFootstepEvent;
  v10 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v78 = this->m_commonEventListeners.m_Size;
  v9 = v78;
  if ( v78 + 1 > v10 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v78 - v10 + 1);
    v9 = v78;
  }
  ++this->m_commonEventListeners.m_Size;
  v11 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v12 = this->m_commonEventListeners.m_Size - v9 - 1;
  this->m_commonEventListeners.m_pElements = v11;
  if ( v12 > 0 )
  {
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
    v9 = v78;
  }
  v13 = &this->m_commonEventListeners.m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = &this->m_PlayerRadioEvent;
  v15 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v79 = this->m_commonEventListeners.m_Size;
  v14 = v79;
  if ( v79 + 1 > v15 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v79 - v15 + 1);
    v14 = v79;
  }
  ++this->m_commonEventListeners.m_Size;
  v16 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v17 = this->m_commonEventListeners.m_Size - v14 - 1;
  this->m_commonEventListeners.m_pElements = v16;
  if ( v17 > 0 )
  {
    _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 4 * v17);
    v14 = v79;
  }
  v18 = &this->m_commonEventListeners.m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = &this->m_PlayerFallDamageEvent;
  v20 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v80 = this->m_commonEventListeners.m_Size;
  v19 = v80;
  if ( v80 + 1 > v20 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v80 - v20 + 1);
    v19 = v80;
  }
  ++this->m_commonEventListeners.m_Size;
  v21 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v22 = this->m_commonEventListeners.m_Size - v19 - 1;
  this->m_commonEventListeners.m_pElements = v21;
  if ( v22 > 0 )
  {
    _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
    v19 = v80;
  }
  v23 = &this->m_commonEventListeners.m_Memory.m_pMemory[v19];
  if ( v23 != nullptr )
    *v23 = &this->m_BombBeepEvent;
  v25 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v81 = this->m_commonEventListeners.m_Size;
  v24 = v81;
  if ( v81 + 1 > v25 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v81 - v25 + 1);
    v24 = v81;
  }
  ++this->m_commonEventListeners.m_Size;
  v26 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v27 = this->m_commonEventListeners.m_Size - v24 - 1;
  this->m_commonEventListeners.m_pElements = v26;
  if ( v27 > 0 )
  {
    _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
    v24 = v81;
  }
  v28 = &this->m_commonEventListeners.m_Memory.m_pMemory[v24];
  if ( v28 != nullptr )
    *v28 = &this->m_DoorMovingEvent;
  v30 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v82 = this->m_commonEventListeners.m_Size;
  v29 = v82;
  if ( v82 + 1 > v30 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v82 - v30 + 1);
    v29 = v82;
  }
  ++this->m_commonEventListeners.m_Size;
  v31 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v32 = this->m_commonEventListeners.m_Size - v29 - 1;
  this->m_commonEventListeners.m_pElements = v31;
  if ( v32 > 0 )
  {
    _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: 4 * v32);
    v29 = v82;
  }
  v33 = &this->m_commonEventListeners.m_Memory.m_pMemory[v29];
  if ( v33 != nullptr )
    *v33 = &this->m_BreakPropEvent;
  v35 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v83 = this->m_commonEventListeners.m_Size;
  v34 = v83;
  if ( v83 + 1 > v35 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v83 - v35 + 1);
    v34 = v83;
  }
  ++this->m_commonEventListeners.m_Size;
  v36 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v37 = this->m_commonEventListeners.m_Size - v34 - 1;
  this->m_commonEventListeners.m_pElements = v36;
  if ( v37 > 0 )
  {
    _V_memmove(dest: &v36[v34 + 1], src: &v36[v34], count: 4 * v37);
    v34 = v83;
  }
  v38 = &this->m_commonEventListeners.m_Memory.m_pMemory[v34];
  if ( v38 != nullptr )
    *v38 = &this->m_BreakBreakableEvent;
  v40 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v84 = this->m_commonEventListeners.m_Size;
  v39 = v84;
  if ( v84 + 1 > v40 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v84 - v40 + 1);
    v39 = v84;
  }
  ++this->m_commonEventListeners.m_Size;
  v41 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v42 = this->m_commonEventListeners.m_Size - v39 - 1;
  this->m_commonEventListeners.m_pElements = v41;
  if ( v42 > 0 )
  {
    _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 4 * v42);
    v39 = v84;
  }
  v43 = &this->m_commonEventListeners.m_Memory.m_pMemory[v39];
  if ( v43 != nullptr )
    *v43 = &this->m_WeaponFireEvent;
  v45 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v85 = this->m_commonEventListeners.m_Size;
  v44 = v85;
  if ( v85 + 1 > v45 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v85 - v45 + 1);
    v44 = v85;
  }
  ++this->m_commonEventListeners.m_Size;
  v46 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v47 = this->m_commonEventListeners.m_Size - v44 - 1;
  this->m_commonEventListeners.m_pElements = v46;
  if ( v47 > 0 )
  {
    _V_memmove(dest: &v46[v44 + 1], src: &v46[v44], count: 4 * v47);
    v44 = v85;
  }
  v48 = &this->m_commonEventListeners.m_Memory.m_pMemory[v44];
  if ( v48 != nullptr )
    *v48 = &this->m_WeaponFireOnEmptyEvent;
  v50 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v86 = this->m_commonEventListeners.m_Size;
  v49 = v86;
  if ( v86 + 1 > v50 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v86 - v50 + 1);
    v49 = v86;
  }
  ++this->m_commonEventListeners.m_Size;
  v51 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v52 = this->m_commonEventListeners.m_Size - v49 - 1;
  this->m_commonEventListeners.m_pElements = v51;
  if ( v52 > 0 )
  {
    _V_memmove(dest: &v51[v49 + 1], src: &v51[v49], count: 4 * v52);
    v49 = v86;
  }
  v53 = &this->m_commonEventListeners.m_Memory.m_pMemory[v49];
  if ( v53 != nullptr )
    *v53 = &this->m_WeaponReloadEvent;
  v55 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v87 = this->m_commonEventListeners.m_Size;
  v54 = v87;
  if ( v87 + 1 > v55 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v87 - v55 + 1);
    v54 = v87;
  }
  ++this->m_commonEventListeners.m_Size;
  v56 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v57 = this->m_commonEventListeners.m_Size - v54 - 1;
  this->m_commonEventListeners.m_pElements = v56;
  if ( v57 > 0 )
  {
    _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 4 * v57);
    v54 = v87;
  }
  v58 = &this->m_commonEventListeners.m_Memory.m_pMemory[v54];
  if ( v58 != nullptr )
    *v58 = &this->m_WeaponZoomEvent;
  v60 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v88 = this->m_commonEventListeners.m_Size;
  v59 = v88;
  if ( v88 + 1 > v60 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v88 - v60 + 1);
    v59 = v88;
  }
  ++this->m_commonEventListeners.m_Size;
  v61 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v62 = this->m_commonEventListeners.m_Size - v59 - 1;
  this->m_commonEventListeners.m_pElements = v61;
  if ( v62 > 0 )
  {
    _V_memmove(dest: &v61[v59 + 1], src: &v61[v59], count: 4 * v62);
    v59 = v88;
  }
  v63 = &this->m_commonEventListeners.m_Memory.m_pMemory[v59];
  if ( v63 != nullptr )
    *v63 = &this->m_BulletImpactEvent;
  v65 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v89 = this->m_commonEventListeners.m_Size;
  v64 = v89;
  if ( v89 + 1 > v65 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v89 - v65 + 1);
    v64 = v89;
  }
  ++this->m_commonEventListeners.m_Size;
  v66 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v67 = this->m_commonEventListeners.m_Size - v64 - 1;
  this->m_commonEventListeners.m_pElements = v66;
  if ( v67 > 0 )
  {
    _V_memmove(dest: &v66[v64 + 1], src: &v66[v64], count: 4 * v67);
    v64 = v89;
  }
  v68 = &this->m_commonEventListeners.m_Memory.m_pMemory[v64];
  if ( v68 != nullptr )
    *v68 = &this->m_GrenadeBounceEvent;
  v70 = this->m_commonEventListeners.m_Memory.m_nAllocationCount;
  v90 = this->m_commonEventListeners.m_Size;
  v69 = v90;
  if ( v90 + 1 > v70 )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_commonEventListeners,
      num: v90 - v70 + 1);
    v69 = v90;
  }
  ++this->m_commonEventListeners.m_Size;
  v71 = this->m_commonEventListeners.m_Memory.m_pMemory;
  v72 = this->m_commonEventListeners.m_Size - v69 - 1;
  this->m_commonEventListeners.m_pElements = v71;
  if ( v72 > 0 )
  {
    _V_memmove(dest: &v71[v69 + 1], src: &v71[v69], count: 4 * v72);
    v69 = v90;
  }
  v73 = &this->m_commonEventListeners.m_Memory.m_pMemory[v69];
  if ( v73 != nullptr )
    *v73 = &this->m_NavBlockedEvent;
  v74 = (BotPhraseManager *)operator new(nSize: 0x348u);
  if ( v74 != nullptr )
    TheBotPhrases = BotPhraseManager::BotPhraseManager(this: v74);
  else
    TheBotPhrases = nullptr;
  v75 = (BotProfileManager *)operator new(nSize: 0x500u);
  if ( v75 != nullptr )
    TheBotProfiles = BotProfileManager::BotProfileManager(this: v75);
  else
    TheBotProfiles = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102B8DF0
// Name: public: virtual class CBasePlayer __near * CCSBotManager::AllocateBotEntity(void)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CCSBotManager::AllocateBotEntity(CCSBotManager *this)
{
  return CreateEntityByName(className: "cs_bot", iForceEdictIndex: -1, bNotify: true);
}

//------------------------------------------------------------------------------
// Address: 0x102B8E10
// Name: public: virtual CCSBotManager::~CCSBotManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBotManager::~CCSBotManager(CCSBotManager *this)
{
  bool v2; // zf

  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_commonEventListeners);
  v2 = !this->m_ServerShutdownEvent.m_enabled;
  this->m_ServerShutdownEvent.__vftable = (CCSBotManager::ServerShutdownEvent_vtbl *)&CCSBotManager::ServerShutdownEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_ServerShutdownEvent);
  this->m_ServerShutdownEvent.__vftable = (CCSBotManager::ServerShutdownEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_NavBlockedEvent.m_enabled;
  this->m_NavBlockedEvent.__vftable = (CCSBotManager::NavBlockedEvent_vtbl *)&CCSBotManager::NavBlockedEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_NavBlockedEvent);
  this->m_NavBlockedEvent.__vftable = (CCSBotManager::NavBlockedEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_GrenadeBounceEvent.m_enabled;
  this->m_GrenadeBounceEvent.__vftable = (CCSBotManager::GrenadeBounceEvent_vtbl *)&CCSBotManager::GrenadeBounceEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_GrenadeBounceEvent);
  this->m_GrenadeBounceEvent.__vftable = (CCSBotManager::GrenadeBounceEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_DecoyFiringEvent.m_enabled;
  this->m_DecoyFiringEvent.__vftable = (CCSBotManager::DecoyFiringEvent_vtbl *)&CCSBotManager::DecoyFiringEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_DecoyFiringEvent);
  this->m_DecoyFiringEvent.__vftable = (CCSBotManager::DecoyFiringEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_DecoyDetonateEvent.m_enabled;
  this->m_DecoyDetonateEvent.__vftable = (CCSBotManager::DecoyDetonateEvent_vtbl *)&CCSBotManager::DecoyDetonateEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_DecoyDetonateEvent);
  this->m_DecoyDetonateEvent.__vftable = (CCSBotManager::DecoyDetonateEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_MolotovDetonateEvent.m_enabled;
  this->m_MolotovDetonateEvent.__vftable = (CCSBotManager::MolotovDetonateEvent_vtbl *)&CCSBotManager::MolotovDetonateEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_MolotovDetonateEvent);
  this->m_MolotovDetonateEvent.__vftable = (CCSBotManager::MolotovDetonateEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_SmokeGrenadeDetonateEvent.m_enabled;
  this->m_SmokeGrenadeDetonateEvent.__vftable = (CCSBotManager::SmokeGrenadeDetonateEvent_vtbl *)&CCSBotManager::SmokeGrenadeDetonateEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_SmokeGrenadeDetonateEvent);
  this->m_SmokeGrenadeDetonateEvent.__vftable = (CCSBotManager::SmokeGrenadeDetonateEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_FlashbangDetonateEvent.m_enabled;
  this->m_FlashbangDetonateEvent.__vftable = (CCSBotManager::FlashbangDetonateEvent_vtbl *)&CCSBotManager::FlashbangDetonateEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_FlashbangDetonateEvent);
  this->m_FlashbangDetonateEvent.__vftable = (CCSBotManager::FlashbangDetonateEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_HEGrenadeDetonateEvent.m_enabled;
  this->m_HEGrenadeDetonateEvent.__vftable = (CCSBotManager::HEGrenadeDetonateEvent_vtbl *)&CCSBotManager::HEGrenadeDetonateEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_HEGrenadeDetonateEvent);
  this->m_HEGrenadeDetonateEvent.__vftable = (CCSBotManager::HEGrenadeDetonateEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BulletImpactEvent.m_enabled;
  this->m_BulletImpactEvent.__vftable = (CCSBotManager::BulletImpactEvent_vtbl *)&CCSBotManager::BulletImpactEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BulletImpactEvent);
  this->m_BulletImpactEvent.__vftable = (CCSBotManager::BulletImpactEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_WeaponZoomEvent.m_enabled;
  this->m_WeaponZoomEvent.__vftable = (CCSBotManager::WeaponZoomEvent_vtbl *)&CCSBotManager::WeaponZoomEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_WeaponZoomEvent);
  this->m_WeaponZoomEvent.__vftable = (CCSBotManager::WeaponZoomEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_WeaponReloadEvent.m_enabled;
  this->m_WeaponReloadEvent.__vftable = (CCSBotManager::WeaponReloadEvent_vtbl *)&CCSBotManager::WeaponReloadEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_WeaponReloadEvent);
  this->m_WeaponReloadEvent.__vftable = (CCSBotManager::WeaponReloadEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_WeaponFireOnEmptyEvent.m_enabled;
  this->m_WeaponFireOnEmptyEvent.__vftable = (CCSBotManager::WeaponFireOnEmptyEvent_vtbl *)&CCSBotManager::WeaponFireOnEmptyEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_WeaponFireOnEmptyEvent);
  this->m_WeaponFireOnEmptyEvent.__vftable = (CCSBotManager::WeaponFireOnEmptyEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_WeaponFireEvent.m_enabled;
  this->m_WeaponFireEvent.__vftable = (CCSBotManager::WeaponFireEvent_vtbl *)&CCSBotManager::WeaponFireEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_WeaponFireEvent);
  this->m_WeaponFireEvent.__vftable = (CCSBotManager::WeaponFireEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_HostageRescuedAllEvent.m_enabled;
  this->m_HostageRescuedAllEvent.__vftable = (CCSBotManager::HostageRescuedAllEvent_vtbl *)&CCSBotManager::HostageRescuedAllEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_HostageRescuedAllEvent);
  this->m_HostageRescuedAllEvent.__vftable = (CCSBotManager::HostageRescuedAllEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_HostageFollowsEvent.m_enabled;
  this->m_HostageFollowsEvent.__vftable = (CCSBotManager::HostageFollowsEvent_vtbl *)&CCSBotManager::HostageFollowsEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_HostageFollowsEvent);
  this->m_HostageFollowsEvent.__vftable = (CCSBotManager::HostageFollowsEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BreakBreakableEvent.m_enabled;
  this->m_BreakBreakableEvent.__vftable = (CCSBotManager::BreakBreakableEvent_vtbl *)&CCSBotManager::BreakBreakableEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BreakBreakableEvent);
  this->m_BreakBreakableEvent.__vftable = (CCSBotManager::BreakBreakableEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BreakPropEvent.m_enabled;
  this->m_BreakPropEvent.__vftable = (CCSBotManager::BreakPropEvent_vtbl *)&CCSBotManager::BreakPropEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BreakPropEvent);
  this->m_BreakPropEvent.__vftable = (CCSBotManager::BreakPropEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_DoorMovingEvent.m_enabled;
  this->m_DoorMovingEvent.__vftable = (CCSBotManager::DoorMovingEvent_vtbl *)&CCSBotManager::DoorMovingEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_DoorMovingEvent);
  this->m_DoorMovingEvent.__vftable = (CCSBotManager::DoorMovingEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_RoundFreezeEndEvent.m_enabled;
  this->m_RoundFreezeEndEvent.__vftable = (CCSBotManager::RoundFreezeEndEvent_vtbl *)&CCSBotManager::RoundFreezeEndEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_RoundFreezeEndEvent);
  this->m_RoundFreezeEndEvent.__vftable = (CCSBotManager::RoundFreezeEndEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_RoundStartEvent.m_enabled;
  this->m_RoundStartEvent.__vftable = (CCSBotManager::RoundStartEvent_vtbl *)&CCSBotManager::RoundStartEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_RoundStartEvent);
  this->m_RoundStartEvent.__vftable = (CCSBotManager::RoundStartEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_RoundEndEvent.m_enabled;
  this->m_RoundEndEvent.__vftable = (CCSBotManager::RoundEndEvent_vtbl *)&CCSBotManager::RoundEndEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_RoundEndEvent);
  this->m_RoundEndEvent.__vftable = (CCSBotManager::RoundEndEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombExplodedEvent.m_enabled;
  this->m_BombExplodedEvent.__vftable = (CCSBotManager::BombExplodedEvent_vtbl *)&CCSBotManager::BombExplodedEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombExplodedEvent);
  this->m_BombExplodedEvent.__vftable = (CCSBotManager::BombExplodedEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombDefuseAbortEvent.m_enabled;
  this->m_BombDefuseAbortEvent.__vftable = (CCSBotManager::BombDefuseAbortEvent_vtbl *)&CCSBotManager::BombDefuseAbortEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombDefuseAbortEvent);
  this->m_BombDefuseAbortEvent.__vftable = (CCSBotManager::BombDefuseAbortEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombDefusedEvent.m_enabled;
  this->m_BombDefusedEvent.__vftable = (CCSBotManager::BombDefusedEvent_vtbl *)&CCSBotManager::BombDefusedEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombDefusedEvent);
  this->m_BombDefusedEvent.__vftable = (CCSBotManager::BombDefusedEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombDefuseBeginEvent.m_enabled;
  this->m_BombDefuseBeginEvent.__vftable = (CCSBotManager::BombDefuseBeginEvent_vtbl *)&CCSBotManager::BombDefuseBeginEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombDefuseBeginEvent);
  this->m_BombDefuseBeginEvent.__vftable = (CCSBotManager::BombDefuseBeginEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombBeepEvent.m_enabled;
  this->m_BombBeepEvent.__vftable = (CCSBotManager::BombBeepEvent_vtbl *)&CCSBotManager::BombBeepEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombBeepEvent);
  this->m_BombBeepEvent.__vftable = (CCSBotManager::BombBeepEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombPlantedEvent.m_enabled;
  this->m_BombPlantedEvent.__vftable = (CCSBotManager::BombPlantedEvent_vtbl *)&CCSBotManager::BombPlantedEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombPlantedEvent);
  this->m_BombPlantedEvent.__vftable = (CCSBotManager::BombPlantedEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_BombPickedUpEvent.m_enabled;
  this->m_BombPickedUpEvent.__vftable = (CCSBotManager::BombPickedUpEvent_vtbl *)&CCSBotManager::BombPickedUpEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_BombPickedUpEvent);
  this->m_BombPickedUpEvent.__vftable = (CCSBotManager::BombPickedUpEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_PlayerFallDamageEvent.m_enabled;
  this->m_PlayerFallDamageEvent.__vftable = (CCSBotManager::PlayerFallDamageEvent_vtbl *)&CCSBotManager::PlayerFallDamageEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_PlayerFallDamageEvent);
  this->m_PlayerFallDamageEvent.__vftable = (CCSBotManager::PlayerFallDamageEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_PlayerDeathEvent.m_enabled;
  this->m_PlayerDeathEvent.__vftable = (CCSBotManager::PlayerDeathEvent_vtbl *)&CCSBotManager::PlayerDeathEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_PlayerDeathEvent);
  this->m_PlayerDeathEvent.__vftable = (CCSBotManager::PlayerDeathEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_PlayerRadioEvent.m_enabled;
  this->m_PlayerRadioEvent.__vftable = (CCSBotManager::PlayerRadioEvent_vtbl *)&CCSBotManager::PlayerRadioEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_PlayerRadioEvent);
  this->m_PlayerRadioEvent.__vftable = (CCSBotManager::PlayerRadioEvent_vtbl *)&IGameEventListener2::`vftable';
  v2 = !this->m_PlayerFootstepEvent.m_enabled;
  this->m_PlayerFootstepEvent.__vftable = (CCSBotManager::PlayerFootstepEvent_vtbl *)&CCSBotManager::PlayerFootstepEvent::`vftable';
  if ( !v2 )
    gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->m_PlayerFootstepEvent);
  this->m_PlayerFootstepEvent.__vftable = (CCSBotManager::PlayerFootstepEvent_vtbl *)&IGameEventListener2::`vftable';
  CBotManager::~CBotManager(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B93B0
// Name: public: bool CollectBots::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CollectBots::operator()(CollectBots *this, CBasePlayer *player)
{
  CCSBot *v4; // eax
  CCSBot *v5; // ebx
  const char **p_m_name; // ecx
  const char *m_name; // eax
  int v8; // eax
  CCSBot **v9; // eax
  int v10; // ecx
  CCSBot **v11; // esi
  BotDifficultyType m_difficulty; // ecx
  int m_team; // eax
  const BotProfile *m_profile; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCSBot **m_pMemory; // ecx
  int v18; // eax
  CCSBot **v19; // eax

  if ( !player->IsBot(this: player) )
    return 1;
  v4 = (CCSBot *)__RTDynamicCast(
                   inptr: player,
                   VfDelta: 0,
                   SrcType: &CBasePlayer `RTTI Type Descriptor',
                   TargetType: &CCSBot `RTTI Type Descriptor',
                   isReference: 0);
  v5 = v4;
  if ( v4 == nullptr )
    return 1;
  p_m_name = (const char **)&v4->m_profile->CBot<CCSPlayer>::m_name;
  if ( p_m_name == nullptr )
    return 1;
  m_name = this->m_name;
  if ( m_name == nullptr || *m_name == 0 )
    goto LABEL_16;
  if ( !FStrEq(sz1: m_name, sz2: *p_m_name) )
  {
    if ( BotProfile::InheritsFrom(this: v5->m_profile, name: this->m_name) == 0 )
      return 1;
LABEL_16:
    m_difficulty = this->m_difficulty;
    if ( (m_difficulty == NUM_DIFFICULTY_LEVELS
       || ((unsigned __int8)(1 << m_difficulty) & v5->m_profile->m_difficultyFlags) != 0)
      && ((m_team = this->m_team) != 3 && m_team != 2 || CBaseEntity::GetTeamNumber(this: v5) == this->m_team)
      && (this->m_weaponType == WEAPONTYPE_UNKNOWN
       || (m_profile = v5->m_profile)->m_weaponPreferenceCount != 0
       && this->m_weaponType == WeaponClassFromWeaponID(weaponID: m_profile->m_weaponPreference[0])) )
    {
      m_Size = this->m_bots.m_Size;
      m_nAllocationCount = this->m_bots.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          (CUtlMemory<vgui::TreeNode *,int> *)this,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_bots.m_Size;
      m_pMemory = this->m_bots.m_Memory.m_pMemory;
      v18 = this->m_bots.m_Size - m_Size - 1;
      this->m_bots.m_pElements = this->m_bots.m_Memory.m_pMemory;
      if ( v18 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
      v19 = &this->m_bots.m_Memory.m_pMemory[m_Size];
      if ( v19 != nullptr )
        *v19 = v5;
    }
    return 1;
  }
  v8 = this->m_bots.m_Memory.m_nAllocationCount;
  this->m_bots.m_Size = 0;
  if ( v8 < 1 )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: 1 - v8);
  ++this->m_bots.m_Size;
  v9 = this->m_bots.m_Memory.m_pMemory;
  v10 = this->m_bots.m_Size - 1;
  this->m_bots.m_pElements = this->m_bots.m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: v9 + 1, src: v9, count: 4 * v10);
  v11 = this->m_bots.m_Memory.m_pMemory;
  if ( v11 != nullptr )
    *v11 = v5;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B9540
// Name: public: class CBaseEntity __near * CCSBotManager::GetRandomSpawn(int)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSBotManager::GetRandomSpawn(CCSBotManager *this, int team)
{
  int v2; // ebx
  int m_Size; // esi
  CBaseEntity **m_pMemory; // edi
  int v5; // ebx
  CBaseEntity **v6; // ebx
  int v7; // ebx
  CBaseEntity **v8; // ebx
  CBaseEntity *v10; // esi
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > spawnSet; // [esp+Ch] [ebp-18h] BYREF
  CBaseEntity *spot; // [esp+20h] [ebp-4h]

  v2 = team;
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&spawnSet, 0, sizeof(spawnSet));
  if ( team == 2 || team == 4 )
  {
    spot = CGlobalEntityList::FindEntityByClassname(
             this: &gEntList,
             pStartEntity: nullptr,
             szName: "info_player_terrorist");
    if ( spot != nullptr )
    {
      do
      {
        v5 = m_Size;
        if ( m_Size + 1 > spawnSet.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&spawnSet,
            num: m_Size - spawnSet.m_Memory.m_nAllocationCount + 1);
          m_Size = spawnSet.m_Size;
          m_pMemory = spawnSet.m_Memory.m_pMemory;
        }
        spawnSet.m_Size = ++m_Size;
        spawnSet.m_pElements = m_pMemory;
        if ( m_Size - v5 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * (m_Size - v5 - 1));
        v6 = &m_pMemory[v5];
        if ( v6 != nullptr )
          *v6 = spot;
        spot = CGlobalEntityList::FindEntityByClassname(
                 this: &gEntList,
                 pStartEntity: spot,
                 szName: "info_player_terrorist");
      }
      while ( spot != nullptr );
      v2 = team;
    }
  }
  if ( v2 == 3 || v2 == 4 )
  {
    for ( spot = CGlobalEntityList::FindEntityByClassname(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: "info_player_counterterrorist");
          spot != nullptr;
          spot = CGlobalEntityList::FindEntityByClassname(
                   this: &gEntList,
                   pStartEntity: spot,
                   szName: "info_player_counterterrorist") )
    {
      v7 = m_Size;
      if ( m_Size + 1 > spawnSet.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&spawnSet,
          num: m_Size - spawnSet.m_Memory.m_nAllocationCount + 1);
        m_Size = spawnSet.m_Size;
        m_pMemory = spawnSet.m_Memory.m_pMemory;
      }
      spawnSet.m_Size = ++m_Size;
      spawnSet.m_pElements = m_pMemory;
      if ( m_Size - v7 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
      v8 = &m_pMemory[v7];
      if ( v8 != nullptr )
        *v8 = spot;
    }
  }
  if ( m_Size != 0 )
  {
    v10 = m_pMemory[_RandomInt((IUniformRandomStream *)this, a2: 0, a3: m_Size - 1)];
    if ( spawnSet.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v10;
  }
  else
  {
    if ( spawnSet.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9770
// Name: void InstallBotControl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallBotControl()
{
  CCSBotManager *v0; // eax

  if ( TheBots != nullptr )
    ((void (__thiscall *)(CBotManager *, int))TheBots->dtr_CBotManager)(a1: TheBots, a2: 1);
  v0 = (CCSBotManager *)operator new(nSize: 0x1C60u);
  if ( v0 != nullptr )
    TheBots = CCSBotManager::CCSBotManager(this: v0);
  else
    TheBots = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102B97B0
// Name: bot_kill
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_kill(const CCommand *args)
{
  int v1; // edi
  CCSBot *v2; // esi
  CollectBots collector; // [esp+0h] [ebp-38h] BYREF
  CSWeaponType weaponType; // [esp+24h] [ebp-14h] BYREF
  BotDifficultyType difficulty; // [esp+28h] [ebp-10h] BYREF
  int team; // [esp+2Ch] [ebp-Ch] BYREF
  const char *name; // [esp+30h] [ebp-8h] BYREF
  bool all; // [esp+37h] [ebp-1h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    BotArgumentsFromArgv(args, &name, &weaponType, &difficulty, &team, &all);
    if ( (name == nullptr || *name == 0) && team == 0 && difficulty == NUM_DIFFICULTY_LEVELS )
      all = true;
    collector.m_team = team;
    collector.m_name = name;
    memset(&collector, 0, 20);
    collector.m_difficulty = difficulty;
    collector.m_weaponType = weaponType;
    ForEachPlayer<CollectBots>(func: &collector);
    v1 = 0;
    if ( collector.m_bots.m_Size <= 0 )
    {
LABEL_11:
      if ( collector.m_bots.m_Memory.m_nGrowSize >= 0 && collector.m_bots.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: collector.m_bots.m_Memory.m_pMemory);
    }
    else
    {
      while ( 1 )
      {
        v2 = collector.m_bots.m_Memory.m_pMemory[v1];
        if ( v2->IsAlive(this: v2) )
        {
          v2->CommitSuicide(this: v2, a2: false, a3: false);
          if ( !all )
            break;
        }
        if ( ++v1 >= collector.m_bots.m_Size )
          goto LABEL_11;
      }
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&collector);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B98A0
// Name: bot_kick
// Source: json
//------------------------------------------------------------------------------
void __usercall bot_kick(unsigned int a1@<edi>, CGameTrace *a2@<esi>, const CCommand *args)
{
  const char *v3; // esi
  int v4; // edi
  bool v5; // bl
  IVEngineServer_vtbl *v6; // esi
  const char *v7; // eax
  char *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int m_nValue; // eax
  int v13; // eax
  int v14; // ecx
  CollectBots collector; // [esp+0h] [ebp-38h] BYREF
  CSWeaponType weaponType; // [esp+24h] [ebp-14h] BYREF
  const char *name; // [esp+28h] [ebp-10h] BYREF
  BotDifficultyType difficulty; // [esp+2Ch] [ebp-Ch] BYREF
  int team; // [esp+30h] [ebp-8h] BYREF
  bool all; // [esp+37h] [ebp-1h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    BotArgumentsFromArgv(args, &name, &weaponType, &difficulty, &team, &all);
    v3 = name;
    v4 = 0;
    if ( name != nullptr && *name != 0 || team != 0 || (v5 = true, difficulty != NUM_DIFFICULTY_LEVELS) )
      v5 = all;
    collector.m_difficulty = difficulty;
    memset(&collector, 0, 20);
    collector.m_name = name;
    collector.m_team = team;
    collector.m_weaponType = weaponType;
    ForEachPlayer<CollectBots>(func: &collector);
    if ( collector.m_bots.m_Size <= 0 )
    {
LABEL_11:
      if ( !v5 || v3 != nullptr && *v3 != 0 || team != 0 || difficulty != NUM_DIFFICULTY_LEVELS )
      {
        if ( cv_bot_quota.m_pParent != nullptr )
          m_nValue = cv_bot_quota.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v13 = m_nValue - collector.m_bots.m_Size;
        if ( cv_bot_quota.m_pParent != nullptr )
          v14 = cv_bot_quota.m_pParent->m_Value.m_nValue;
        else
          v14 = 0;
        if ( v13 >= 0 )
        {
          if ( v13 > v14 )
            v13 = v14;
        }
        else
        {
          v13 = 0;
        }
        CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_quota.IConVar, value: v13, fContentsMask: a1, tr: a2);
      }
      else
      {
        CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_quota.IConVar, value: 0, fContentsMask: a1, tr: a2);
      }
      if ( collector.m_bots.m_Memory.m_nGrowSize >= 0 && collector.m_bots.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: collector.m_bots.m_Memory.m_pMemory);
    }
    else
    {
      while ( 1 )
      {
        v6 = engine->__vftable;
        v7 = collector.m_bots.m_Memory.m_pMemory[v4]->GetPlayerName(this: collector.m_bots.m_Memory.m_pMemory[v4]);
        v8 = UTIL_VarArgs(format: "kick \"%s\"\n", v7);
        v6->ServerCommand(this: engine, a2: v8);
        if ( !v5 )
          break;
        if ( ++v4 >= collector.m_bots.m_Size )
        {
          v3 = name;
          goto LABEL_11;
        }
      }
      if ( cv_bot_quota.m_pParent != nullptr )
        v9 = cv_bot_quota.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      v10 = v9 - 1;
      if ( cv_bot_quota.m_pParent != nullptr )
        v11 = cv_bot_quota.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      if ( v10 >= 0 )
      {
        if ( v10 > v11 )
          v10 = v11;
      }
      else
      {
        v10 = 0;
      }
      CCollisionProperty::TestCollision(this: (ConVar *)&cv_bot_quota.IConVar, value: v10, fContentsMask: a1, tr: a2);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&collector);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B4450
// Name: class CCSBot __near * CreateBot<class CCSBot>(class BotProfile const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCSBot *__cdecl CreateBot<CCSBot>(const BotProfile *profile, int team)
{
  CResponseRulesToEngineInterface *v2; // ecx
  ICommandLine *v3; // eax
  int maxClients; // esi
  int v6; // eax
  edict_t *v7; // esi
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // eax
  CBaseEntity *v10; // esi
  int v11; // [esp-4h] [ebp-44h]
  char botName[64]; // [esp+0h] [ebp-40h] BYREF

  v3 = _CommandLine(this: v2);
  if ( v3->CheckParm(this: v3, a2: "-nobots", a3: nullptr) != nullptr )
    return nullptr;
  maxClients = gpGlobals->maxClients;
  if ( UTIL_ClientsInGame() < maxClients )
  {
    UTIL_ConstructBotNetName(name: botName, nameLength: 64, profile);
    g_nClientPutInServerOverrides = 0;
    ClientPutInServerOverride(fn: ClientPutInServerOverride_Bot);
    g_botInitTeam = team;
    g_botInitProfile = profile;
    v7 = (edict_t *)((int (__thiscall *)(IVEngineServer *, char *, int))engine->CreateFakeClient)(
                      a1: engine,
                      a2: botName,
                      a3: v11);
    ClientPutInServerOverride(fn: nullptr);
    if ( v7 != nullptr )
    {
      v8 = CBaseEntity::Instance(pent: v7);
      v9 = (CBaseEntity *)__RTDynamicCast(
                            inptr: v8,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSBot `RTTI Type Descriptor',
                            isReference: 0);
      v10 = v9;
      if ( v9 != nullptr )
      {
        CBaseEntity::ClearFlags(this: v9);
        CBaseEntity::AddFlag(this: v10, flags: 768);
        return (CCSBot *)v10;
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_104E93AC, a2: *(const char **)botName);
        return nullptr;
      }
    }
    else
    {
      CONSOLE_ECHO(pszMsg: "Unable to create bot: CreateFakeClient() returned null.\n");
      return nullptr;
    }
  }
  else
  {
    v6 = UTIL_ClientsInGame();
    CONSOLE_ECHO(pszMsg: "Unable to create bot: Server is full (%d/%d clients).\n", v6, maxClients);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6830
// Name: float NavAreaTravelDistance<class ShortestPathCost>(class CNavArea __near *,class CNavArea __near *,class ShortestPathCost __near &,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl NavAreaTravelDistance<ShortestPathCost>(
        CNavArea *startArea,
        CNavArea *endArea,
        ShortestPathCost *costFunc,
        float maxPathLength)
{
  CNavArea *v4; // edi
  int v6; // ecx
  CNavArea *v7; // esi
  int v8; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v10; // eax
  CNavArea *area; // esi
  float length; // xmm0_4
  const CNavLadder *ladder; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v14; // eax
  double v15; // st7
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  unsigned int m_openMarker; // eax
  float v20; // xmm0_4
  double v21; // xmm0_8
  CNavArea *m_parent; // eax
  float v23; // xmm3_4
  float *v24; // ecx
  float v25; // xmm0_4
  float v26; // xmm1_4
  const CFuncElevator *Elevator; // [esp+80h] [ebp-38h]
  float v29; // [esp+80h] [ebp-38h]
  float v30; // [esp+80h] [ebp-38h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // [esp+84h] [ebp-34h]
  const CNavLadder *v32; // [esp+88h] [ebp-30h]
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // [esp+90h] [ebp-28h]
  int v34; // [esp+94h] [ebp-24h]
  int v35; // [esp+98h] [ebp-20h]
  int v36; // [esp+9Ch] [ebp-1Ch]
  int v37; // [esp+A0h] [ebp-18h]
  CNavArea *v38; // [esp+A4h] [ebp-14h]
  bool v39; // [esp+AAh] [ebp-Eh]
  char v40; // [esp+ABh] [ebp-Dh]
  Vector m_center; // 0:^74.12

  if ( startArea == nullptr )
    return -1.0;
  v4 = endArea;
  if ( endArea == nullptr )
    return -1.0;
  if ( startArea == endArea )
    return 0.0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "NavAreaBuildPath",
    a3: 0,
    a4: "NextBotSpiky",
    a5: false,
    a6: 4);
  v6 = g_DebugPathfindCounter--;
  v39 = v6 > 0;
  if ( endArea->IsBlocked(this: endArea, a2: -1, a3: false) )
    goto LABEL_58;
  startArea->m_parent = nullptr;
  startArea->m_parentHow = NUM_TRAVERSE_TYPES;
  m_center = endArea->m_center;
  CNavArea::ClearSearchLists();
  startArea->m_totalCost = fsqrt(
                             (float)((float)((float)(startArea->m_center.x - m_center.x)
                                           * (float)(startArea->m_center.x - m_center.x))
                                   + (float)((float)(startArea->m_center.y - m_center.y)
                                           * (float)(startArea->m_center.y - m_center.y)))
                           + (float)((float)(startArea->m_center.z - m_center.z)
                                   * (float)(startArea->m_center.z - m_center.z)));
  startArea->m_costSoFar = 0.0;
  startArea->m_pathLengthSoFar = 0.0;
  CNavArea::AddToOpenList(this: startArea);
  v7 = CNavArea::m_openList;
  if ( CNavArea::m_openList == nullptr )
  {
LABEL_58:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return -1.0;
  }
  while ( 1 )
  {
    CNavArea::RemoveFromOpenList(this: v7);
    v7->m_prevOpen = nullptr;
    v7->m_nextOpen = nullptr;
    v38 = v7;
    if ( v39 )
      ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v7->DrawFilled)(
        a1: v7,
        a2: 0,
        a3: 255,
        a4: 0,
        a5: 128,
        a6: 1106247680,
        a7: 1,
        a8: 1084227584);
    if ( !v7->IsBlocked(this: v7, a2: -1, a3: false) )
      break;
LABEL_57:
    v7 = CNavArea::m_openList;
    if ( CNavArea::m_openList == nullptr )
      goto LABEL_58;
  }
  if ( v7 != v4 )
  {
    v8 = 0;
    v34 = 0;
    v35 = 0;
    m_connect = v7->m_connect;
    v40 = 1;
    m_ladder = nullptr;
    v37 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v32 = nullptr;
        Elevator = nullptr;
        if ( v34 != 0 )
          break;
        m_pData = m_connect->m_pData;
        if ( v8 < m_connect->m_pData->m_Size )
        {
          area = m_pData->m_Elements[v8].area;
          length = m_pData->m_Elements[v8].length;
          v36 = v35;
          ++v8;
LABEL_40:
          if ( area != v38 && !area->IsBlocked(this: area, a2: -1, a3: false) )
          {
            v15 = ShortestPathCost::operator()(
                    this: costFunc,
                    area,
                    fromArea: v38,
                    ladder: v32,
                    elevator: Elevator,
                    length);
            if ( v15 >= 0.0 )
            {
              if ( maxPathLength > 0.0 )
              {
                v16 = area->m_center.y - v38->m_center.y;
                v17 = area->m_center.x - v38->m_center.x;
                v18 = v38->m_pathLengthSoFar
                    + fsqrt(
                        (float)((float)(v17 * v17) + (float)(v16 * v16))
                      + (float)((float)(area->m_center.z - v38->m_center.z) * (float)(area->m_center.z - v38->m_center.z)));
                if ( v18 > maxPathLength )
                  goto LABEL_12;
                area->m_pathLengthSoFar = v18;
              }
              m_openMarker = area->m_openMarker;
              v29 = v15;
              if ( m_openMarker != CNavArea::m_masterMarker && area->m_marker != CNavArea::m_masterMarker
                || v29 < area->m_costSoFar )
              {
                v20 = (float)((float)((float)(area->m_center.y - m_center.y) * (float)(area->m_center.y - m_center.y))
                            + (float)((float)(area->m_center.x - m_center.x) * (float)(area->m_center.x - m_center.x)))
                    + (float)((float)(area->m_center.z - m_center.z) * (float)(area->m_center.z - m_center.z));
                if ( v20 <= 0.0 )
                  v21 = 0.0;
                else
                  v21 = fsqrt(v20);
                area->m_costSoFar = v29;
                area->m_totalCost = (float)v21 + v29;
                if ( m_openMarker == CNavArea::m_masterMarker )
                  CNavArea::UpdateOnOpenList(this: area);
                else
                  CNavArea::AddToOpenList(this: area);
                area->m_parent = v38;
                area->m_parentHow = v36;
              }
            }
          }
LABEL_12:
          v7 = v38;
        }
        else
        {
          v10 = v35 + 1;
          v8 = 0;
          v35 = v10;
          if ( v10 == 4 )
          {
            v34 = 1;
            m_ladder = v7->m_ladder;
            v37 = 0;
          }
          else
          {
            m_connect = &v7->m_connect[v10];
          }
        }
      }
      if ( v34 != 1 )
        break;
      if ( v8 < m_ladder->m_pData->m_Size )
      {
        ladder = m_ladder->m_pData->m_Elements[v8].ladder;
        v32 = ladder;
        if ( v40 == 0 )
        {
          area = ladder->m_bottomArea;
          v36 = 5;
          ++v8;
          goto LABEL_33;
        }
        switch ( v37 )
        {
          case 0:
            area = ladder->m_topForwardArea;
            v37 = 1;
            v36 = 4;
LABEL_33:
            if ( area == nullptr )
              goto LABEL_12;
LABEL_39:
            length = -1.0;
            goto LABEL_40;
          case 1:
            area = ladder->m_topLeftArea;
            v37 = 2;
            v36 = 4;
            goto LABEL_33;
          case 2:
            area = ladder->m_topRightArea;
            v37 = 3;
            v36 = 4;
            goto LABEL_33;
          default:
            break;
        }
        ++v8;
        v37 = 0;
      }
      else
      {
        v8 = 0;
        if ( v40 != 0 )
        {
          v40 = 0;
          m_ladder = &v7->m_ladder[1];
        }
        else
        {
          v34 = 2;
        }
      }
    }
    Elevator = CNavArea::GetElevator(this: v7);
    if ( Elevator == nullptr || (v14 = v7->m_elevatorAreas.m_pData, v8 >= v14->m_Size) )
    {
      v4 = endArea;
      v7->m_marker = CNavArea::m_masterMarker;
      goto LABEL_57;
    }
    area = v14->m_Elements[v8++].area;
    v36 = 7;
    if ( area->m_center.z <= v38->m_center.z )
      v36 = 8;
    goto LABEL_39;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  m_parent = v4->m_parent;
  v23 = 0.0;
  v30 = 0.0;
  v24 = (float *)v4;
  if ( m_parent != nullptr )
  {
    do
    {
      v25 = v24[11] - m_parent->m_center.x;
      v26 = (float)((float)((float)(v24[12] - m_parent->m_center.y) * (float)(v24[12] - m_parent->m_center.y))
                  + (float)((float)(v24[13] - m_parent->m_center.z) * (float)(v24[13] - m_parent->m_center.z)))
          + (float)(v25 * v25);
      v24 = (float *)m_parent;
      m_parent = m_parent->m_parent;
      v23 = v23 + fsqrt(v26);
    }
    while ( m_parent != nullptr );
    return v23;
  }
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x102B96F0
// Name: bool ForEachPlayer<class CollectBots>(class CollectBots __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<CollectBots>(CollectBots *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && CollectBots::operator()(this: func, player: v3) == 0 )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B9A30
// Name: __CreateCServerGameTagsIServerGameTags_interface_22
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_22()
{
  return &_g_CServerGameTags_singleton_22;
}
