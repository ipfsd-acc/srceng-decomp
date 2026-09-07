// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/bot/bot_hide.cpp
// Functions: 8
// ============================================================

#include "game\shared\cstrike15\bot\bot_hide.h"

//------------------------------------------------------------------------------
// Address: 0x102CBC40
// Name: bool IsSpotOccupied(class CBaseEntity __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSpotOccupied(CBasePlayer *me, const Vector *pos)
{
  CBasePlayer *ClosestPlayer; // eax
  float range; // [esp+0h] [ebp-4h] BYREF

  ClosestPlayer = UTIL_GetClosestPlayer(pos, distance: &range);
  return ClosestPlayer != me && ClosestPlayer != nullptr && range < 75.0;
}

//------------------------------------------------------------------------------
// Address: 0x102CBC80
// Name: public: int CollectHidingSpotsFunctor::GetRandomHidingSpot(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CollectHidingSpotsFunctor::GetRandomHidingSpot(CollectHidingSpotsFunctor *this)
{
  int v2; // edi
  int result; // eax
  int v4; // ecx
  int *i; // edx

  v2 = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: this->m_totalWeight - 1);
  result = this->m_count - 1;
  v4 = 0;
  if ( result > 0 )
  {
    for ( i = &this->m_hidingSpotWeight[1]; *i < v2; ++i )
    {
      if ( ++v4 >= result )
        return result;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CBCD0
// Name: public: bool CollectHidingSpotsFunctor::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CollectHidingSpotsFunctor::operator()(CollectHidingSpotsFunctor *this, CNavArea *area)
{
  unsigned int m_place; // eax
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v6; // ecx
  HidingSpot *v7; // edi
  float m_range; // xmm3_4
  const Vector *m_origin; // eax
  CBasePlayer *ClosestPlayer; // eax
  CNavArea *m_area; // eax
  CNavArea *v12; // edi
  float distance; // [esp+4h] [ebp-Ch] BYREF
  CBaseEntity *m_me; // [esp+8h] [ebp-8h]
  int it; // [esp+Ch] [ebp-4h]

  m_place = this->m_place;
  if ( m_place != 0 && area->m_place != m_place )
    return 1;
  m_pData = area->m_hidingSpots.m_pData;
  v6 = 0;
  it = 0;
  if ( m_pData->m_Size <= 0 )
    return this->m_count < 256;
  while ( 1 )
  {
    v7 = m_pData->m_Elements[v6];
    if ( this->m_count == 256 )
      break;
    m_range = this->m_range;
    if ( m_range <= 0.0
      || (m_origin = this->m_origin,
          (float)((float)((float)((float)(v7->m_pos.y - m_origin->y) * (float)(v7->m_pos.y - m_origin->y))
                        + (float)((float)(v7->m_pos.x - m_origin->x) * (float)(v7->m_pos.x - m_origin->x)))
                + (float)((float)(v7->m_pos.z - m_origin->z) * (float)(v7->m_pos.z - m_origin->z))) <= (float)(m_range * m_range)) )
    {
      m_me = this->m_me;
      ClosestPlayer = UTIL_GetClosestPlayer(pos: &v7->m_pos, &distance);
      if ( ClosestPlayer == m_me || ClosestPlayer == nullptr || distance >= 75.0 )
      {
        m_area = v7->m_area;
        if ( (m_area == nullptr || (m_area->m_attributeFlags & 0x200) == 0) && (this->m_flags & v7->m_flags) != 0 )
        {
          this->m_hidingSpot[this->m_count] = &v7->m_pos;
          this->m_hidingSpotWeight[this->m_count] = this->m_totalWeight;
          v12 = v7->m_area;
          if ( v12 != nullptr && SLOBYTE(v12->m_attributeFlags) < 0 )
            ++this->m_totalWeight;
          else
            this->m_totalWeight += 2;
          ++this->m_count;
        }
      }
    }
    m_pData = area->m_hidingSpots.m_pData;
    v6 = it + 1;
    it = v6;
    if ( v6 >= m_pData->m_Size )
      return this->m_count < 256;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CBE40
// Name: public: bool CollectArriveFirstSpotsFunctor::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CollectArriveFirstSpotsFunctor::operator()(CollectArriveFirstSpotsFunctor *this, CNavArea *area)
{
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v4; // ecx
  float m_range; // xmm3_4
  const HidingSpot *v6; // edi
  const Vector *m_searchOrigin; // eax
  CBaseEntity *m_me; // ebx
  CBasePlayer *ClosestPlayer; // eax
  CNavArea *m_area; // ebx
  float distance; // [esp+4h] [ebp-8h] BYREF
  int it; // [esp+8h] [ebp-4h]

  m_pData = area->m_hidingSpots.m_pData;
  v4 = 0;
  for ( it = 0; v4 < m_pData->m_Size; it = v4 )
  {
    m_range = this->m_range;
    v6 = m_pData->m_Elements[v4];
    if ( m_range <= 0.0
      || (m_searchOrigin = this->m_searchOrigin,
          (float)((float)((float)((float)(v6->m_pos.y - m_searchOrigin->y) * (float)(v6->m_pos.y - m_searchOrigin->y))
                        + (float)((float)(v6->m_pos.x - m_searchOrigin->x) * (float)(v6->m_pos.x - m_searchOrigin->x)))
                + (float)((float)(v6->m_pos.z - m_searchOrigin->z) * (float)(v6->m_pos.z - m_searchOrigin->z))) <= (float)(m_range * m_range)) )
    {
      m_me = this->m_me;
      ClosestPlayer = UTIL_GetClosestPlayer(pos: &v6->m_pos, &distance);
      if ( (ClosestPlayer == m_me || ClosestPlayer == nullptr || distance >= 75.0) && (v6->m_flags & this->m_flags) != 0 )
      {
        m_area = v6->m_area;
        if ( this->m_enemyArriveTime > (float)(m_area->m_earliestOccupyTime[CBaseEntity::GetTeamNumber(this: this->m_me)
                                                                          % 2]
                                             + 1.0) )
          this->m_hidingSpot[this->m_count++] = v6;
      }
    }
    m_pData = area->m_hidingSpots.m_pData;
    v4 = it + 1;
  }
  return this->m_count != 256;
}

//------------------------------------------------------------------------------
// Address: 0x102CD120
// Name: class Vector const __near * FindNearbyHidingSpot(class CBaseEntity __near *,class Vector const __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl FindNearbyHidingSpot(
        CBaseEntity *me,
        const Vector *pos,
        float maxRange,
        char isSniper,
        bool useNearest)
{
  CNavArea *NearestNavArea; // edi
  float v6; // xmm0_4
  const Vector *result; // eax
  float v8; // xmm3_4
  int i; // edi
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  const Vector *v13; // ecx
  CollectHidingSpotsFunctor v14; // [esp+18h] [ebp-1038h] BYREF
  CollectHidingSpotsFunctor func; // [esp+834h] [ebp-81Ch] BYREF
  int savedregs; // [esp+1050h] [ebp+0h] BYREF

  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea == nullptr )
    return nullptr;
  while ( 1 )
  {
    v6 = maxRange;
    if ( isSniper != 0 )
    {
      func.m_origin = pos;
      func.m_me = me;
      func.m_count = 0;
      func.m_range = maxRange;
      func.m_flags = 4;
      func.m_place = 0;
      func.m_totalWeight = 0;
      SearchSurroundingAreas<CollectHidingSpotsFunctor>(
        a1: (const CNavLadder *)&savedregs,
        startArea: NearestNavArea,
        startPos: pos,
        &func,
        maxRange,
        options: 0,
        teamID: -1);
      if ( func.m_count != 0 )
        return func.m_hidingSpot[CollectHidingSpotsFunctor::GetRandomHidingSpot(this: &func)];
      func.m_origin = pos;
      func.m_me = me;
      func.m_count = 0;
      func.m_range = maxRange;
      func.m_flags = 2;
      func.m_place = 0;
      func.m_totalWeight = 0;
      SearchSurroundingAreas<CollectHidingSpotsFunctor>(
        a1: (const CNavLadder *)&savedregs,
        startArea: NearestNavArea,
        startPos: pos,
        &func,
        maxRange,
        options: 0,
        teamID: -1);
      if ( func.m_count != 0 )
        return func.m_hidingSpot[CollectHidingSpotsFunctor::GetRandomHidingSpot(this: &func)];
      v6 = maxRange;
    }
    v14.m_origin = pos;
    v14.m_me = me;
    v14.m_count = 0;
    v14.m_range = v6;
    v14.m_flags = 1;
    v14.m_place = 0;
    v14.m_totalWeight = 0;
    SearchSurroundingAreas<CollectHidingSpotsFunctor>(
      a1: (const CNavLadder *)&savedregs,
      startArea: NearestNavArea,
      startPos: pos,
      func: &v14,
      maxRange: v6,
      options: 0,
      teamID: -1);
    if ( v14.m_count != 0 )
      break;
    if ( isSniper == 0 )
    {
      isSniper = 1;
      NearestNavArea = CNavMesh::GetNearestNavArea(
                         this: TheNavMesh,
                         pos,
                         anyZ: false,
                         maxDist: 10000.0,
                         checkLOS: false,
                         checkGround: true);
      if ( NearestNavArea != nullptr )
        continue;
    }
    return nullptr;
  }
  if ( !useNearest )
    return v14.m_hidingSpot[CollectHidingSpotsFunctor::GetRandomHidingSpot(this: &v14)];
  v8 = 1.0e10;
  result = nullptr;
  for ( i = 0; i < v14.m_count; ++i )
  {
    v13 = v14.m_hidingSpot[i];
    x = pos->x;
    y = pos->y;
    z = pos->z;
    if ( v8 > (float)((float)((float)((float)(v13->y - y) * (float)(v13->y - y))
                            + (float)((float)(v13->x - x) * (float)(v13->x - x)))
                    + (float)((float)(v13->z - z) * (float)(v13->z - z))) )
    {
      v8 = (float)((float)((float)(v13->y - y) * (float)(v13->y - y))
                 + (float)((float)(v13->x - x) * (float)(v13->x - x)))
         + (float)((float)(v13->z - z) * (float)(v13->z - z));
      result = v14.m_hidingSpot[i];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CD360
// Name: class HidingSpot const __near * FindInitialEncounterSpot(class CBaseEntity __near *,class Vector const __near &,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
HidingSpot *__cdecl FindInitialEncounterSpot(
        CBaseEntity *me,
        const Vector *searchOrigin,
        float enemyArriveTime,
        float maxRange,
        bool isSniper)
{
  HidingSpot *result; // eax
  CNavArea *v6; // edi
  float v7; // xmm0_4
  IUniformRandomStream *v8; // ecx
  CollectArriveFirstSpotsFunctor collector; // [esp+18h] [ebp-418h] BYREF
  int savedregs; // [esp+430h] [ebp+0h] BYREF

  result = (HidingSpot *)CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: searchOrigin,
                           anyZ: false,
                           maxDist: 10000.0,
                           checkLOS: false,
                           checkGround: true);
  v6 = (CNavArea *)result;
  if ( result != nullptr )
  {
    v7 = maxRange;
    if ( isSniper )
    {
      collector.m_searchOrigin = searchOrigin;
      collector.m_me = me;
      collector.m_count = 0;
      collector.m_range = maxRange;
      collector.m_flags = 4;
      collector.m_enemyArriveTime = enemyArriveTime;
      SearchSurroundingAreas<CollectArriveFirstSpotsFunctor>(
        a1: (const CNavLadder *)&savedregs,
        startArea: (CNavArea *)result,
        startPos: searchOrigin,
        func: &collector,
        maxRange,
        options: 0,
        teamID: -1);
      if ( collector.m_count != 0 )
        return (HidingSpot *)collector.m_hidingSpot[_RandomInt(this: v8, a2: 0, a3: collector.m_count - 1)];
      collector.m_searchOrigin = searchOrigin;
      collector.m_me = me;
      collector.m_count = 0;
      collector.m_range = maxRange;
      collector.m_flags = 2;
      collector.m_enemyArriveTime = enemyArriveTime;
      SearchSurroundingAreas<CollectArriveFirstSpotsFunctor>(
        a1: (const CNavLadder *)&savedregs,
        startArea: v6,
        startPos: searchOrigin,
        func: &collector,
        maxRange,
        options: 0,
        teamID: -1);
      if ( collector.m_count != 0 )
        return (HidingSpot *)collector.m_hidingSpot[_RandomInt(this: v8, a2: 0, a3: collector.m_count - 1)];
      v7 = maxRange;
    }
    collector.m_searchOrigin = searchOrigin;
    collector.m_me = me;
    collector.m_count = 0;
    collector.m_range = v7;
    collector.m_flags = 9;
    collector.m_enemyArriveTime = enemyArriveTime;
    SearchSurroundingAreas<CollectArriveFirstSpotsFunctor>(
      a1: (const CNavLadder *)&savedregs,
      startArea: v6,
      startPos: searchOrigin,
      func: &collector,
      maxRange: v7,
      options: 0,
      teamID: -1);
    result = (HidingSpot *)collector.m_count;
    if ( collector.m_count == 0 )
      return result;
    return (HidingSpot *)collector.m_hidingSpot[_RandomInt(this: v8, a2: 0, a3: collector.m_count - 1)];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CD6B0
// Name: class Vector const __near * FindRandomHidingSpot(class CBaseEntity __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl FindRandomHidingSpot(CBaseEntity *me, unsigned int place, bool isSniper)
{
  IUniformRandomStream *v3; // ecx
  CollectHidingSpotsFunctor collector; // [esp+Ch] [ebp-81Ch] BYREF
  int savedregs; // [esp+828h] [ebp+0h] BYREF

  if ( isSniper )
  {
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
    collector.m_origin = &me->m_vecAbsOrigin;
    collector.m_me = me;
    collector.m_count = 0;
    collector.m_range = -1.0;
    collector.m_flags = 4;
    collector.m_place = place;
    collector.m_totalWeight = 0;
    CNavMesh::ForAllAreas<CollectHidingSpotsFunctor>(this: TheNavMesh, func: &collector);
    if ( collector.m_count != 0 )
      return collector.m_hidingSpot[_RandomInt(this: v3, a2: 0, a3: collector.m_count - 1)];
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
    collector.m_count = 0;
    collector.m_totalWeight = 0;
    collector.m_origin = &me->m_vecAbsOrigin;
    collector.m_me = me;
    collector.m_range = -1.0;
    collector.m_flags = 2;
    collector.m_place = place;
    CNavMesh::ForAllAreas<CollectHidingSpotsFunctor>(this: TheNavMesh, func: &collector);
    if ( collector.m_count != 0 )
      return collector.m_hidingSpot[_RandomInt(this: v3, a2: 0, a3: collector.m_count - 1)];
  }
  if ( (me->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
  collector.m_me = me;
  collector.m_origin = &me->m_vecAbsOrigin;
  collector.m_count = 0;
  collector.m_range = -1.0;
  collector.m_flags = 1;
  collector.m_place = place;
  collector.m_totalWeight = 0;
  CNavMesh::ForAllAreas<CollectHidingSpotsFunctor>(this: TheNavMesh, func: &collector);
  if ( collector.m_count != 0 )
    return collector.m_hidingSpot[_RandomInt(this: v3, a2: 0, a3: collector.m_count - 1)];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CD840
// Name: __CreateCServerGameTagsIServerGameTags_interface_33
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_33()
{
  return &_g_CServerGameTags_singleton_33;
}
