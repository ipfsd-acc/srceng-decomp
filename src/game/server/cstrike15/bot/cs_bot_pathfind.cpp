// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_pathfind.cpp
// Functions: 20
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_pathfind.h"

//------------------------------------------------------------------------------
// Address: 0x102BBEB0
// Name: public: bool CCSBot::IsNearJump(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::IsNearJump(CCSBot *this)
{
  int m_pathIndex; // edx
  int v2; // eax
  float *i; // ecx

  m_pathIndex = this->m_pathIndex;
  if ( m_pathIndex == 0 || m_pathIndex >= this->m_pathLength )
    return 0;
  v2 = m_pathIndex - 1;
  if ( m_pathIndex - 1 >= m_pathIndex )
    return 0;
  for ( i = &this->m_path[v2 + 1].pos.z;
        (*(_BYTE *)(*((_DWORD *)i - 10) + 84) & 2) == 0 || (float)(*i - *(i - 6)) <= 0.0;
        i += 6 )
  {
    if ( ++v2 >= m_pathIndex )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BBF10
// Name: public: float CCSBot::GetApproximateFallDamage(float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetApproximateFallDamage(CCSBot *this, float height)
{
  float damage; // [esp+8h] [ebp+8h]

  damage = (float)(height * 0.21780001) - 26.0;
  if ( damage >= 0.0 )
    return damage;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102BBF50
// Name: public: float CCSBot::GetPathDistanceRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetPathDistanceRemaining(CCSBot *this)
{
  int m_pathLength; // edx
  int m_pathIndex; // eax
  int v4; // esi
  float v5; // xmm4_4
  CNavArea *area; // eax
  __int64 v7; // xmm0_8
  int v8; // eax
  float v9; // xmm3_4
  float y; // xmm2_4
  float x; // xmm1_4
  CCSBot::ConnectInfo *v12; // ecx
  int v13; // edx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float z; // [esp-4h] [ebp-20h]
  float v20; // [esp+Ch] [ebp-10h]

  m_pathLength = this->m_pathLength;
  if ( m_pathLength == 0 )
    return -1.0;
  m_pathIndex = this->m_pathIndex;
  v4 = m_pathIndex;
  if ( m_pathIndex >= m_pathLength )
    v4 = m_pathLength - 1;
  v5 = 0.0;
  area = this->m_path[m_pathIndex].area;
  v7 = *(_QWORD *)&area->m_center.x;
  z = area->m_center.z;
  v8 = v4 + 1;
  v20 = 0.0;
  if ( v4 + 1 < m_pathLength )
  {
    v9 = z;
    y = *((float *)&v7 + 1);
    x = *(float *)&v7;
    v12 = &this->m_path[v8];
    v13 = m_pathLength - v8;
    do
    {
      v14 = v12->area->m_center.x - x;
      v15 = v12->area->m_center.y - y;
      v16 = v12->area->m_center.z - v9;
      v9 = v12->area->m_center.z;
      v17 = (float)(v15 * v15) + (float)(v16 * v16);
      y = v12->area->m_center.y;
      v18 = v17 + (float)(v14 * v14);
      x = v12->area->m_center.x;
      ++v12;
      --v13;
      v5 = v5 + fsqrt(v18);
    }
    while ( v13 != 0 );
    return v5;
  }
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x102BC040
// Name: private: void CCSBot::BuildTrivialPath(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::BuildTrivialPath(CCSBot *this, const Vector *goal)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  CCSNavArea *m_lastKnownArea; // edx
  double curtime; // st7
  Vector myOrigin; // [esp+14h] [ebp-Ch] BYREF

  GetCentroid(result: &myOrigin, player: this);
  x = myOrigin.x;
  y = myOrigin.y;
  z = myOrigin.z;
  this->m_path[0].area = this->m_lastKnownArea;
  this->m_pathIndex = 1;
  this->m_pathLength = 2;
  this->m_path[0].pos.x = x;
  this->m_path[0].pos.y = y;
  this->m_path[0].pos.z = z;
  this->m_path[0].pos.z = CNavArea::GetZ(this: this->m_lastKnownArea, x, y);
  m_lastKnownArea = this->m_lastKnownArea;
  this->m_path[0].how = NUM_TRAVERSE_TYPES;
  this->m_path[1].area = m_lastKnownArea;
  this->m_path[0].ladder = nullptr;
  this->m_path[1].pos = *goal;
  this->m_path[1].pos.z = CNavArea::GetZ(this: this->m_lastKnownArea, x: goal->x, y: goal->y);
  this->m_path[1].ladder = nullptr;
  this->m_path[1].how = NUM_TRAVERSE_TYPES;
  curtime = gpGlobals->curtime;
  this->m_spotEncounter = nullptr;
  this->m_pathLadder = nullptr;
  this->m_areaEnteredTimestamp = curtime;
  this->m_goalPosition = *goal;
}

//------------------------------------------------------------------------------
// Address: 0x102BC170
// Name: FindDescendingLadderApproachPoint
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall FindDescendingLadderApproachPoint@<eax>(
        const CNavLadder *ladder@<esi>,
        Vector *pos@<edi>,
        CNavArea *area)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  CGameTrace v8; // [esp+0h] [ebp-54h] BYREF
  IHandleEntity savedregs; // [esp+54h] [ebp+0h] BYREF

  v3 = ladder->m_top.y - (float)((float)(ladder->m_normal.y * 2.0) * 16.0);
  v4 = ladder->m_top.z - (float)((float)(ladder->m_normal.z * 2.0) * 16.0);
  pos->x = ladder->m_top.x - (float)((float)(ladder->m_normal.x * 2.0) * 16.0);
  pos->y = v3;
  pos->z = v4;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)ladder,
    vecAbsStart: &ladder->m_top,
    vecAbsEnd: pos,
    mask: 0x1400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &v8);
  if ( v8.fraction < 1.0 )
  {
    v5 = ladder->m_top.y + (float)((float)(ladder->m_normal.y * 2.0) * 16.0);
    v6 = ladder->m_top.z + (float)((float)(ladder->m_normal.z * 2.0) * 16.0);
    pos->x = ladder->m_top.x + (float)((float)(ladder->m_normal.x * 2.0) * 16.0);
    pos->y = v5;
    pos->z = v6;
    CNavArea::GetClosestPointOnArea(this: area, pPos: pos, close: pos);
  }
  return (float)((float)((float)(ladder->m_normal.y * (float)(pos->y - ladder->m_top.y))
                       + (float)((float)(pos->x - ladder->m_top.x) * ladder->m_normal.x))
               + (float)(ladder->m_normal.z * (float)(pos->z - ladder->m_top.z))) < 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102BC2C0
// Name: private: void CCSBot::ComputeLadderEndpoint(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ComputeLadderEndpoint(CCSBot *this, bool isAscending)
{
  const CNavLadder *m_pathLadder; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float y; // xmm0_4
  unsigned int v8; // eax
  const CNavLadder *v9; // eax
  float z; // xmm0_4
  float v11; // xmm2_4
  unsigned int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm0_4
  CGameTrace result; // [esp+4h] [ebp-6Ch] BYREF
  Vector to; // [esp+58h] [ebp-18h]
  Vector from; // [esp+64h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+70h] [ebp+0h] BYREF

  m_pathLadder = this->m_pathLadder;
  v4 = m_pathLadder->m_normal.x * 16.0;
  v5 = m_pathLadder->m_normal.y * 16.0;
  if ( isAscending )
  {
    v6 = m_pathLadder->m_bottom.x + v4;
    y = m_pathLadder->m_bottom.y;
    v8 = (unsigned int)this->m_iEFlags >> 11;
    from.x = v6;
    from.y = y + v5;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v9 = this->m_pathLadder;
    from.z = this->m_vecAbsOrigin.z + 35.5;
    z = v9->m_top.z;
  }
  else
  {
    v11 = m_pathLadder->m_top.x + v4;
    v12 = (unsigned int)this->m_iEFlags >> 11;
    v13 = m_pathLadder->m_top.y + v5;
    from.x = v11;
    from.y = v13;
    if ( (v12 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v9 = this->m_pathLadder;
    from.z = this->m_vecAbsOrigin.z + 35.5;
    z = v9->m_bottom.z;
  }
  to.z = z;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &from,
    vecAbsEnd: &v9->m_bottom,
    mask: 0x1400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &result);
  v14 = to.z;
  if ( result.fraction != 1.0 )
    v14 = (float)((float)(to.z - from.z) * result.fraction) + from.z;
  this->m_pathLadderEnd = v14;
}

//------------------------------------------------------------------------------
// Address: 0x102BC3F0
// Name: private: int CCSBot::FindOurPositionOnPath(class Vector __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBot::FindOurPositionOnPath(CCSBot *this, Vector *close, bool local)
{
  float z; // ecx
  int m_pathIndex; // ebx
  int v7; // eax
  int m_pathLength; // ebx
  int v9; // edi
  float *v10; // esi
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  Vector eyes; // [esp+4h] [ebp-48h] BYREF
  Vector probe; // [esp+10h] [ebp-3Ch] BYREF
  Vector along; // [esp+1Ch] [ebp-30h] BYREF
  Vector feet; // [esp+28h] [ebp-24h]
  Vector pos; // [esp+34h] [ebp-18h]
  float distSq; // [esp+40h] [ebp-Ch]
  int closeIndex; // [esp+44h] [ebp-8h]
  float closeDistSq; // [esp+48h] [ebp-4h]
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF
  float length; // [esp+58h] [ebp+Ch]

  if ( this->m_pathLength == 0 )
    return -1;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&feet.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  *(_QWORD *)&eyes.x = *(_QWORD *)&feet.x;
  feet.z = z;
  eyes.z = z + 35.5;
  closeDistSq = 1.0e10;
  closeIndex = -1;
  if ( local )
  {
    m_pathIndex = this->m_pathIndex;
    v7 = m_pathIndex - 3;
    if ( m_pathIndex - 3 < 1 )
      v7 = 1;
    m_pathLength = m_pathIndex + 3;
    if ( m_pathLength > this->m_pathLength )
      m_pathLength = this->m_pathLength;
  }
  else
  {
    m_pathLength = this->m_pathLength;
    v7 = 1;
  }
  v9 = v7;
  if ( v7 < m_pathLength )
  {
    v10 = (float *)(&this->m_isStopping + 24 * v7);
    do
    {
      v11 = v10[6] - *v10;
      v12 = v10[7] - v10[1];
      along.x = v10[5] - *(v10 - 1);
      along.y = v11;
      along.z = v12;
      length = VectorNormalize(vec: &along);
      v13 = *(v10 - 1);
      v14 = *v10;
      v15 = v10[1];
      v16 = (float)((float)((float)(feet.y - *v10) * along.y) + (float)((float)(feet.x - v13) * along.x))
          + (float)((float)(feet.z - v15) * along.z);
      if ( v16 > 0.0 )
      {
        if ( v16 < length )
        {
          v13 = v13 + (float)(along.x * v16);
          v14 = v14 + (float)(along.y * v16);
          v15 = v15 + (float)(along.z * v16);
        }
        else
        {
          v13 = v10[5];
          v14 = v10[6];
          v15 = v10[7];
        }
      }
      pos.x = v13;
      pos.y = v14;
      pos.z = v15;
      distSq = (float)((float)((float)(v14 - feet.y) * (float)(v14 - feet.y))
                     + (float)((float)(v13 - feet.x) * (float)(v13 - feet.x)))
             + (float)((float)(v15 - feet.z) * (float)(v15 - feet.z));
      if ( closeDistSq > distSq )
      {
        probe.x = v13;
        probe.y = v14;
        probe.z = v15 + 35.5;
        if ( IsWalkableTraceLineClear(from: &eyes, to: &probe, flags: 7u) )
        {
          closeDistSq = distSq;
          if ( close != nullptr )
            *close = pos;
          closeIndex = v9 - 1;
        }
      }
      ++v9;
      v10 += 6;
    }
    while ( v9 < m_pathLength );
  }
  return closeIndex;
}

//------------------------------------------------------------------------------
// Address: 0x102BC650
// Name: public: virtual bool CCSBot::IsRunning(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsRunning(CCSBot *this)
{
  CCSNavArea *m_lastKnownArea; // eax

  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_mustRunTimer) <= this->m_mustRunTimer.m_timestamp.m_Value )
    return this->m_isRunning;
  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea == nullptr )
    return this->m_isRunning;
  if ( (m_lastKnownArea->m_attributeFlags & 0x20) != 0 )
    return true;
  return (m_lastKnownArea->m_attributeFlags & 0x40) == 0 && this->m_isRunning;
}

//------------------------------------------------------------------------------
// Address: 0x102BC6A0
// Name: private: void CCSBot::DrawPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::DrawPath(CCSBot *this)
{
  int m_pathLength; // eax
  int v3; // edi
  Vector *p_pos; // esi
  Vector v5; // [esp-28h] [ebp-60h]
  Vector v6; // [esp-1Ch] [ebp-54h]
  Vector v7; // [esp+Ch] [ebp-2Ch]
  Vector v8; // [esp+18h] [ebp-20h]
  Vector close; // [esp+24h] [ebp-14h] BYREF
  float x; // [esp+30h] [ebp-8h]
  float y; // [esp+34h] [ebp-4h]

  m_pathLength = this->m_pathLength;
  if ( m_pathLength != 0 )
  {
    v3 = 1;
    if ( m_pathLength > 1 )
    {
      p_pos = &this->m_path[0].pos;
      do
      {
        UTIL_DrawBeamPoints(vecStart: *p_pos, vecEnd: p_pos[2], iLifetime: 2, bRed: 0xFFu, bGreen: 0x4Bu, bBlue: 0);
        ++v3;
        p_pos += 2;
      }
      while ( v3 < this->m_pathLength );
    }
    if ( CCSBot::FindOurPositionOnPath(this, &close, local: true) >= 0 )
    {
      x = close.x;
      *(_QWORD *)&v8.x = *(_QWORD *)&close.x;
      y = close.y;
      v8.z = close.z + 25.0;
      *(_QWORD *)&v5.x = *(_QWORD *)&close.x;
      v5.z = close.z + 25.0;
      UTIL_DrawBeamPoints(vecStart: v5, vecEnd: close, iLifetime: 1, bRed: 0, bGreen: 0xFFu, bBlue: 0);
      v8.x = close.x - 25.0;
      v7.x = close.x + 25.0;
      v8.y = y;
      *(_QWORD *)&v6.x = *(_QWORD *)&v8.x;
      v8.z = close.z;
      v6.z = close.z;
      v7.y = y;
      v7.z = close.z;
      y = close.z;
      UTIL_DrawBeamPoints(vecStart: v7, vecEnd: v6, iLifetime: 1, bRed: 0, bGreen: 0xFFu, bBlue: 0);
      v7.y = close.y - 25.0;
      v7.x = x;
      v7.z = y;
      v8.y = close.y + 25.0;
      v8.x = x;
      v8.z = y;
      UTIL_DrawBeamPoints(vecStart: v8, vecEnd: v7, iLifetime: 1, bRed: 0, bGreen: 0xFFu, bBlue: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC8A0
// Name: public: void CCSBot::Wait(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Wait(CCSBot *this, float duration)
{
  CountdownTimer *p_m_waitTimer; // edi
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  p_m_waitTimer = &this->m_waitTimer;
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_waitTimer) + duration;
  if ( p_m_waitTimer->m_timestamp.m_Value != v3 )
  {
    p_m_waitTimer->NetworkStateChanged(this: p_m_waitTimer, a2: &p_m_waitTimer->m_timestamp);
    v4 = v3;
    p_m_waitTimer->m_timestamp.m_Value = v4;
  }
  if ( p_m_waitTimer->m_duration.m_Value != duration )
  {
    p_m_waitTimer->NetworkStateChanged(this: p_m_waitTimer, a2: &p_m_waitTimer->m_duration);
    p_m_waitTimer->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC910
// Name: private: bool CCSBot::ComputePathPositions(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::ComputePathPositions(CCSBot *this)
{
  CCSBot *v1; // edi
  CNavArea *area; // eax
  CCSBot::ConnectInfo *m_path; // esi
  Vector *p_pos; // ecx
  CCSBot::ConnectInfo *v6; // ebx
  int how; // eax
  CNavArea *v8; // eax
  float *p_x; // eax
  float v10; // xmm0_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  int m_pathLength; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // edx
  int v18; // eax
  float x; // xmm0_4
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // eax
  int v21; // ecx
  CNavArea *v22; // edx
  const CNavLadder *v23; // eax
  bool v24; // zf
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float z; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *v29; // ecx
  int v30; // eax
  const CNavLadder *v31; // ecx
  NavDirType v32; // [esp-4h] [ebp-54h]
  float y; // [esp+4h] [ebp-4Ch]
  float dir; // [esp+14h] [ebp-3Ch]
  float dir_4; // [esp+18h] [ebp-38h]
  int v37; // [esp+20h] [ebp-30h]
  int m_Size; // [esp+24h] [ebp-2Ch]
  float *v39; // [esp+28h] [ebp-28h]
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *v40; // [esp+28h] [ebp-28h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *pLadders; // [esp+2Ch] [ebp-24h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *pLaddersa; // [esp+2Ch] [ebp-24h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *pLaddersb; // [esp+2Ch] [ebp-24h]
  int it; // [esp+30h] [ebp-20h]
  int ita; // [esp+30h] [ebp-20h]
  int itb; // [esp+30h] [ebp-20h]
  int itc; // [esp+30h] [ebp-20h]
  Vector *v48; // [esp+34h] [ebp-1Ch]
  float *p_y; // [esp+38h] [ebp-18h]
  Vector *j; // [esp+3Ch] [ebp-14h]
  float *p_z; // [esp+40h] [ebp-10h]
  int v52; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  Vector *closePos; // [esp+4Ch] [ebp-4h]

  v1 = this;
  if ( this->m_pathLength == 0 )
    return 0;
  area = this->m_path[0].area;
  this->m_path[0].pos.x = area->m_center.x;
  m_path = this->m_path;
  p_pos = &this->m_path[0].pos;
  v1->m_path[0].pos.y = area->m_center.y;
  v1->m_path[0].pos.z = area->m_center.z;
  v1->m_path[0].ladder = nullptr;
  v1->m_path[0].how = NUM_TRAVERSE_TYPES;
  i = 1;
  if ( v1->m_pathLength <= 1 )
    return 1;
  p_z = &v1->m_path[1].pos.z;
  v52 = 4;
  v48 = &v1->m_path[1].pos;
  p_y = &v1->m_path[1].pos.y;
  v6 = &v1->m_path[1];
  pLadders = (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)v1->m_path;
  closePos = &v1->m_path[1].pos;
  for ( j = &v1->m_path[0].pos; ; j += 2 )
  {
    how = v6->how;
    it = (int)v6;
    if ( how <= 3 )
    {
      v32 = v6->how;
      v8 = v6->area;
      v6->ladder = nullptr;
      CNavArea::ComputeClosestPointInPortal(this: m_path->area, to: v8, dir: v32, fromPos: p_pos, closePos);
      switch ( v6->how )
      {
        case GO_NORTH:
          closePos->y = closePos->y - 5.0;
          break;
        case GO_EAST:
          p_x = &closePos->x;
          v10 = closePos->x + 5.0;
          goto LABEL_11;
        case GO_SOUTH:
          closePos->y = closePos->y + 5.0;
          break;
        case GO_WEST:
          p_x = &closePos->x;
          v10 = closePos->x - 5.0;
LABEL_11:
          *p_x = v10;
          break;
        default:
          break;
      }
      v6->pos.z = CNavArea::GetZ(this: m_path->area, x: closePos->x, y: closePos->y);
      if ( CNavArea::IsConnected(this: v6->area, area: m_path->area, dir: NUM_DIRECTIONS) == 0 )
      {
        switch ( v6->how )
        {
          case GO_NORTH:
            dir = 0.0;
            *(float *)&v11 = -1.0;
            goto LABEL_19;
          case GO_EAST:
            *(float *)&v12 = 1.0;
            goto LABEL_18;
          case GO_SOUTH:
            dir = 0.0;
            *(float *)&v11 = 1.0;
            goto LABEL_19;
          case GO_WEST:
            *(float *)&v12 = -1.0;
LABEL_18:
            dir = *(float *)&v12;
            *(float *)&v11 = 0.0;
LABEL_19:
            dir_4 = *(float *)&v11;
            break;
          default:
            break;
        }
        closePos->x = (float)(dir * 75.0) + closePos->x;
        v39 = &v6->pos.y;
        v6->pos.y = (float)(dir_4 * 75.0) + v6->pos.y;
        m_pathLength = v1->m_pathLength;
        if ( m_pathLength < 255 )
        {
          v14 = i;
          v15 = v1->m_pathLength;
          if ( m_pathLength > i )
          {
            if ( m_pathLength - i >= 4 )
            {
              v16 = (int)(&v1->m_isStopping + 24 * v15);
              v17 = ((unsigned int)(v15 - v52 - 1) >> 2) + 1;
              v15 -= 4 * v17;
              do
              {
                *(_DWORD *)(v16 + 12) = *(_DWORD *)(v16 - 12);
                *(_DWORD *)(v16 + 16) = *(_DWORD *)(v16 - 8);
                *(float *)(v16 + 20) = *(float *)(v16 - 4);
                v16 -= 96;
                --v17;
                *(float *)(v16 + 120) = *(float *)(v16 + 96);
                *(float *)(v16 + 124) = *(float *)(v16 + 100);
                *(_DWORD *)(v16 + 128) = *(_DWORD *)(v16 + 104);
                *(_DWORD *)(v16 + 84) = *(_DWORD *)(v16 + 60);
                *(_DWORD *)(v16 + 88) = *(_DWORD *)(v16 + 64);
                *(float *)(v16 + 92) = *(float *)(v16 + 68);
                *(float *)(v16 + 96) = *(float *)(v16 + 72);
                *(float *)(v16 + 100) = *(float *)(v16 + 76);
                *(_DWORD *)(v16 + 104) = *(_DWORD *)(v16 + 80);
                *(_DWORD *)(v16 + 60) = *(_DWORD *)(v16 + 36);
                *(_DWORD *)(v16 + 64) = *(_DWORD *)(v16 + 40);
                *(float *)(v16 + 68) = *(float *)(v16 + 44);
                *(float *)(v16 + 72) = *(float *)(v16 + 48);
                *(float *)(v16 + 76) = *(float *)(v16 + 52);
                *(_DWORD *)(v16 + 80) = *(_DWORD *)(v16 + 56);
                *(_DWORD *)(v16 + 36) = *(_DWORD *)(v16 + 12);
                *(_DWORD *)(v16 + 40) = *(_DWORD *)(v16 + 16);
                *(float *)(v16 + 44) = *(float *)(v16 + 20);
                *(float *)(v16 + 48) = *(float *)(v16 + 24);
                *(float *)(v16 + 52) = *(float *)(v16 + 28);
                *(_DWORD *)(v16 + 56) = *(_DWORD *)(v16 + 32);
              }
              while ( v17 != 0 );
              m_path = (CCSBot::ConnectInfo *)pLadders;
              v14 = i;
            }
            if ( v15 > v14 )
            {
              v18 = (int)&v1->m_path[v15].pos.y;
              pLaddersa = (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)(v15 - v14);
              do
              {
                *(_DWORD *)(v18 - 12) = *(_DWORD *)(v18 - 36);
                *(_DWORD *)(v18 - 8) = *(_DWORD *)(v18 - 32);
                *(float *)(v18 - 4) = *(float *)(v18 - 28);
                v18 -= 24;
                v24 = pLaddersa == (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)1;
                pLaddersa = (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)((char *)pLaddersa - 1);
                *(float *)(v18 + 24) = *(float *)v18;
                *(float *)(v18 + 28) = *(float *)(v18 + 4);
                *(_DWORD *)(v18 + 32) = *(_DWORD *)(v18 + 8);
              }
              while ( !v24 );
            }
          }
          ++v1->m_pathLength;
          ++v52;
          i = v14 + 1;
          j += 2;
          closePos += 2;
          p_z += 6;
          ++m_path;
          ++v6;
          v48[2].x = *(float *)(it + 8);
          p_y += 6;
          *p_y = *v39;
          y = v48[2].y;
          x = v48[2].x;
          v48 += 2;
          *p_z = CNavArea::GetZ(this: (CNavArea *)*(_DWORD *)it, x, y);
        }
      }
      goto LABEL_50;
    }
    if ( how == 4 )
    {
      m_ladder = m_path->area->m_ladder;
      v21 = 0;
      pLaddersb = m_ladder;
      m_Size = m_ladder->m_pData->m_Size;
      if ( m_Size > 0 )
      {
        v22 = v6->area;
        ita = (int)m_ladder->m_pData->m_Elements;
        while ( 1 )
        {
          v23 = *(const CNavLadder **)ita;
          if ( *(CNavArea **)(*(_DWORD *)ita + 32) == v22 || v23->m_topLeftArea == v22 || v23->m_topRightArea == v22 )
            break;
          ita += 4;
          if ( ++v21 >= m_Size )
          {
            v24 = v21 == pLaddersb->m_pData->m_Size;
            goto LABEL_49;
          }
        }
        v6->ladder = v23;
        v25 = v23->m_normal.z * 2.0;
        v26 = v23->m_bottom.x + (float)((float)(v23->m_normal.x * 2.0) * 16.0);
        v27 = v23->m_bottom.y + (float)((float)(v23->m_normal.y * 2.0) * 16.0);
        z = v23->m_bottom.z;
        m_ladder = pLaddersb;
        v6->pos.x = v26;
        v6->pos.y = v27;
        v6->pos.z = z + (float)(v25 * 16.0);
      }
      v24 = v21 == m_ladder->m_pData->m_Size;
      goto LABEL_49;
    }
    if ( how == 5 )
      break;
LABEL_50:
    ++v52;
    closePos += 2;
    p_y += 6;
    v48 += 2;
    p_z += 6;
    ++m_path;
    p_pos = j + 2;
    ++v6;
    ++i;
    pLadders = (const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)m_path;
    if ( i >= v1->m_pathLength )
      return 1;
  }
  v29 = &m_path->area->m_ladder[1];
  v30 = 0;
  v40 = v29;
  v37 = v29->m_pData->m_Size;
  if ( v37 > 0 )
  {
    itb = (int)v29->m_pData->m_Elements;
    while ( 1 )
    {
      v31 = *(const CNavLadder **)itb;
      if ( *(CNavArea **)(*(_DWORD *)itb + 48) == v6->area )
        break;
      itb += 4;
      if ( ++v30 >= v37 )
        goto LABEL_47;
    }
    v6->ladder = v31;
    itc = v30;
    FindDescendingLadderApproachPoint(ladder: v31, pos: &v6->pos, area: m_path->area);
    v1 = this;
    v30 = itc;
    m_path = (CCSBot::ConnectInfo *)pLadders;
LABEL_47:
    v29 = v40;
  }
  v24 = v30 == v29->m_pData->m_Size;
LABEL_49:
  if ( !v24 )
    goto LABEL_50;
  CBot<CCSPlayer>::PrintIfWatched(this: v1, format: "ERROR: Can't find ladder in path\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102BCE40
// Name: private: void CCSBot::SetupLadderMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetupLadderMovement(CCSBot *this)
{
  int m_pathIndex; // eax
  CCSBot::ConnectInfo *v3; // esi
  CNavArea **v4; // edi
  const CNavLadder *ladder; // ecx
  const CNavLadder *m_pathLadder; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float y; // xmm0_4
  QAngle ladderAngles; // [esp+10h] [ebp-Ch] BYREF

  m_pathIndex = this->m_pathIndex;
  if ( m_pathIndex >= 1 && this->m_pathLength != 0 )
  {
    v3 = &this->m_path[m_pathIndex];
    v4 = &this->m_lastKnownArea + 6 * m_pathIndex;
    if ( v3->ladder != nullptr )
    {
      this->m_spotEncounter = nullptr;
      this->m_areaEnteredTimestamp = gpGlobals->curtime;
      ladder = v3->ladder;
      this->m_pathLadder = ladder;
      this->m_pathLadderTimestamp = gpGlobals->curtime;
      VectorAngles(forward: &ladder->m_normal, angles: &ladderAngles);
      if ( v3->how == GO_LADDER_UP )
      {
        this->m_pathLadderState = APPROACH_ASCENDING_LADDER;
        this->m_pathLadderFaceIn = true;
        CBot<CCSPlayer>::PrintIfWatched(this, format: "APPROACH_ASCENDING_LADDER\n");
        m_pathLadder = this->m_pathLadder;
        v7 = m_pathLadder->m_bottom.y + (float)((float)(m_pathLadder->m_normal.y * 2.0) * 16.0);
        v8 = m_pathLadder->m_bottom.z + (float)((float)(m_pathLadder->m_normal.z * 2.0) * 16.0);
        this->m_goalPosition.x = m_pathLadder->m_bottom.x + (float)((float)(m_pathLadder->m_normal.x * 2.0) * 16.0);
        this->m_goalPosition.y = v7;
        this->m_goalPosition.z = v8;
      }
      else
      {
        if ( FindDescendingLadderApproachPoint(ladder: this->m_pathLadder, pos: &this->m_goalPosition, area: *v4) )
        {
          CBot<CCSPlayer>::PrintIfWatched(this, format: "APPROACH_DESCENDING_LADDER (face out)\n");
          y = ladderAngles.y;
          this->m_pathLadderState = APPROACH_DESCENDING_LADDER;
          this->m_pathLadderFaceIn = false;
          this->m_lookAheadAngle = y;
          return;
        }
        CBot<CCSPlayer>::PrintIfWatched(this, format: "APPROACH_DESCENDING_LADDER (face in)\n");
        this->m_pathLadderState = APPROACH_DESCENDING_LADDER;
        this->m_pathLadderFaceIn = true;
      }
      this->m_lookAheadAngle = AngleNormalizePositive(angle: ladderAngles.y + 180.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD000
// Name: private: int CCSBot::FindPathPoint(float,class Vector __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CCSBot::FindPathPoint@<eax>(
        CCSBot *this@<ecx>,
        int a2@<ebp>,
        float aheadRange,
        Vector *point,
        int *prevIndex)
{
  int OurPositionOnPath; // esi
  int result; // eax
  int m_pathLength; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float *p_z; // ecx
  double j; // st7
  float v13; // xmm0_4
  int v14; // ecx
  Vector *v15; // eax
  float v16; // edx
  float v17; // edx
  float v18; // edx
  float v19; // edx
  Vector *p_pos; // eax
  float z; // edx
  char *v22; // eax
  int v23; // eax
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // eax
  float v27; // xmm7_4
  float v28; // ecx
  IUniformRandomStream *tickcount; // ecx
  bool v30; // al
  int y_low; // ecx
  Vector *p_probe; // edx
  __int64 v33; // xmm0_8
  float v34; // edx
  int v35; // eax
  Vector *v36; // eax
  double v37; // st7
  float v38; // xmm5_4
  float v39; // xmm1_4
  float v40; // xmm6_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float *v43; // ecx
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm0_4
  float v48; // xmm7_4
  bool v49; // zf
  float v50; // xmm3_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  bool v53; // al
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm4_4
  float v57; // xmm0_4
  float v58; // xmm1_4
  int v59; // ecx
  float *v60; // ecx
  float duration; // [esp+Ch] [ebp-D8h]
  Vector v62; // [esp+30h] [ebp-B4h] BYREF
  Vector myOrigin; // [esp+3Ch] [ebp-A8h] BYREF
  Vector v64; // [esp+48h] [ebp-9Ch] BYREF
  Vector probe; // [esp+54h] [ebp-90h] BYREF
  Vector v66; // [esp+60h] [ebp-84h] BYREF
  Vector eyes; // [esp+6Ch] [ebp-78h]
  Vector to; // [esp+78h] [ebp-6Ch] BYREF
  Vector along; // [esp+84h] [ebp-60h]
  Vector feet; // [esp+90h] [ebp-54h]
  __int128 prevDir; // [esp+9Ch] [ebp-48h] OVERLAPPED BYREF
  Vector initDir; // [esp+ACh] [ebp-38h] BYREF
  __int128 dir; // [esp+B8h] [ebp-2Ch] OVERLAPPED
  float v74; // [esp+C8h] [ebp-1Ch]
  Vector pos; // [esp+CCh] [ebp-18h]
  int v76; // [esp+D8h] [ebp-Ch] OVERLAPPED BYREF
  int i; // [esp+DCh] [ebp-8h]
  int retaddr; // [esp+E4h] [ebp+0h]

  v76 = a2;
  i = retaddr;
  GetCentroid(result: &v62, player: this);
  OurPositionOnPath = CCSBot::FindOurPositionOnPath(this, close: &initDir, local: true);
  if ( prevIndex != nullptr )
    *prevIndex = OurPositionOnPath;
  if ( OurPositionOnPath <= 0 )
    return this->m_pathIndex;
  m_pathLength = this->m_pathLength;
  if ( this->m_isCrouching )
  {
    result = OurPositionOnPath + 1;
    if ( OurPositionOnPath + 1 >= m_pathLength )
      result = m_pathLength - 1;
    y = initDir.y;
    x = initDir.x;
    point->x = this->m_path[result].pos.x;
    p_z = &this->m_path[result].pos.z;
    point->y = this->m_path[result].pos.y;
    for ( j = *p_z; ; j = *p_z )
    {
      v13 = point->x;
      point->z = j;
      if ( (float)((float)((float)(v13 - x) * (float)(v13 - x)) + (float)((float)(point->y - y) * (float)(point->y - y))) >= 400.0 )
        break;
      ++result;
      p_z += 6;
      if ( result >= this->m_pathLength )
        return this->m_pathLength - 1;
      point->x = *(p_z - 2);
      point->y = *(p_z - 1);
    }
    return result;
  }
  v14 = m_pathLength - 1;
  if ( OurPositionOnPath < v14 )
  {
    if ( v14 - OurPositionOnPath < 4 )
    {
LABEL_21:
      if ( OurPositionOnPath < v14 )
      {
        p_pos = &this->m_path[OurPositionOnPath + 1].pos;
        do
        {
          z = p_pos->z;
          *((_QWORD *)&dir + 1) = *(_QWORD *)&p_pos->x;
          v74 = z;
          if ( (float)((float)((float)(*((float *)&dir + 2) - initDir.x) * (float)(*((float *)&dir + 2) - initDir.x))
                     + (float)((float)(*((float *)&dir + 3) - initDir.y) * (float)(*((float *)&dir + 3) - initDir.y))) >= 400.0 )
            break;
          ++OurPositionOnPath;
          p_pos += 2;
        }
        while ( OurPositionOnPath < v14 );
      }
    }
    else
    {
      v15 = &this->m_path[OurPositionOnPath + 2].pos;
      while ( 1 )
      {
        v16 = v15[-2].z;
        *((_QWORD *)&dir + 1) = *(_QWORD *)&v15[-2].x;
        v74 = v16;
        if ( (float)((float)((float)(*((float *)&dir + 2) - initDir.x) * (float)(*((float *)&dir + 2) - initDir.x))
                   + (float)((float)(*((float *)&dir + 3) - initDir.y) * (float)(*((float *)&dir + 3) - initDir.y))) >= 400.0 )
          break;
        v17 = v15->z;
        *((_QWORD *)&dir + 1) = *(_QWORD *)&v15->x;
        v74 = v17;
        if ( (float)((float)((float)(*((float *)&dir + 2) - initDir.x) * (float)(*((float *)&dir + 2) - initDir.x))
                   + (float)((float)(*((float *)&dir + 3) - initDir.y) * (float)(*((float *)&dir + 3) - initDir.y))) >= 400.0 )
        {
          ++OurPositionOnPath;
          break;
        }
        v18 = v15[2].z;
        *((_QWORD *)&dir + 1) = *(_QWORD *)&v15[2].x;
        v74 = v18;
        if ( (float)((float)((float)(*((float *)&dir + 2) - initDir.x) * (float)(*((float *)&dir + 2) - initDir.x))
                   + (float)((float)(*((float *)&dir + 3) - initDir.y) * (float)(*((float *)&dir + 3) - initDir.y))) >= 400.0 )
        {
          OurPositionOnPath += 2;
          break;
        }
        v19 = v15[4].z;
        *((_QWORD *)&dir + 1) = *(_QWORD *)&v15[4].x;
        v74 = v19;
        if ( (float)((float)((float)(*((float *)&dir + 2) - initDir.x) * (float)(*((float *)&dir + 2) - initDir.x))
                   + (float)((float)(*((float *)&dir + 3) - initDir.y) * (float)(*((float *)&dir + 3) - initDir.y))) >= 400.0 )
        {
          OurPositionOnPath += 3;
          break;
        }
        OurPositionOnPath += 4;
        v15 += 8;
        if ( OurPositionOnPath >= v14 - 3 )
          goto LABEL_21;
      }
    }
  }
  if ( OurPositionOnPath <= this->m_pathIndex
    || OurPositionOnPath >= this->m_pathLength
    || *((_DWORD *)(v22 = (char *)this + 24 * OurPositionOnPath) + 1979) == 0
    && (this->m_path[OurPositionOnPath].area->m_attributeFlags & 0x12) == 0 )
  {
    v23 = this->m_pathLength;
    if ( ++OurPositionOnPath >= v23 )
      OurPositionOnPath = v14;
    if ( OurPositionOnPath >= v23
      || *((_DWORD *)(v22 = (char *)this + 24 * OurPositionOnPath) + 1979) == 0
      && (this->m_path[OurPositionOnPath].area->m_attributeFlags & 0x12) == 0 )
    {
      v24 = (float *)((char *)this + 24 * OurPositionOnPath);
      *((float *)&prevDir + 1) = v24[1976] - v24[1970];
      *((float *)&prevDir + 2) = v24[1977] - v24[1971];
      v25 = v24[1978] - v24[1972];
      LODWORD(prevDir) = v24;
      *((float *)&prevDir + 3) = v25;
      VectorNormalize(vec: (Vector *)((char *)&prevDir + 4));
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&v76);
      v26 = this->m_vecAbsOrigin.z;
      v27 = 0.0;
      *(_QWORD *)&along.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      *(_QWORD *)&v66.x = *(_QWORD *)&along.x;
      along.z = v26;
      v66.z = v26 + 35.5;
      pos.z = 0.0;
      feet = *(Vector *)((char *)&prevDir + 4);
      HIWORD(pos.x) = 256;
      LODWORD(pos.y) = OurPositionOnPath;
      if ( OurPositionOnPath >= this->m_pathLength )
      {
        y_low = LODWORD(pos.y);
      }
      else
      {
        DWORD1(dir) = prevDir + 7888;
        while ( 1 )
        {
          v28 = *(float *)(DWORD1(dir) + 24);
          *((_QWORD *)&dir + 1) = *(_QWORD *)(DWORD1(dir) + 16);
          eyes.x = *((float *)&dir + 2) - *(float *)(DWORD1(dir) - 8);
          eyes.y = *((float *)&dir + 3) - *(float *)(DWORD1(dir) - 4);
          v74 = v28;
          eyes.z = v28 - *(float *)DWORD1(dir);
          initDir = eyes;
          VectorNormalize(vec: &initDir);
          if ( this->m_burnedByFlamesTimer.m_timestamp.m_Value <= 0.0
            || (*(float *)&dir = IntervalTimer::Now(this: (CEffectsServer *)&this->m_burnedByFlamesTimer)
                               - this->m_burnedByFlamesTimer.m_timestamp.m_Value,
                *(float *)&dir > 1.0) )
          {
            tickcount = (IUniformRandomStream *)gpGlobals->tickcount;
            if ( (int)tickcount <= *(_DWORD *)(*(_DWORD *)(DWORD1(dir) + 8) + 276) && pos.z < 100.0 )
            {
              duration = _RandomFloat(this: tickcount, a2: 0.5, a3: 1.5);
              CCSBot::Wait(this, duration);
LABEL_60:
              y_low = --LODWORD(pos.y);
              goto LABEL_63;
            }
          }
          if ( (float)((float)((float)(initDir.x * *((float *)&prevDir + 1))
                             + (float)(initDir.y * *((float *)&prevDir + 2)))
                     + (float)(initDir.z * *((float *)&prevDir + 3))) < 0.0 )
            goto LABEL_60;
          if ( (float)((float)((float)(feet.x * initDir.x) + (float)(feet.y * initDir.y)) + (float)(feet.z * initDir.z)) < 0.5 )
          {
            y_low = --LODWORD(pos.y);
            BYTE2(pos.x) = 1;
            goto LABEL_63;
          }
          *(_QWORD *)&v64.x = *((_QWORD *)&dir + 1);
          feet = initDir;
          v64.z = v74 + 35.5;
          v30 = IsWalkableTraceLineClear(from: &v66, to: &v64, flags: 4u);
          y_low = LODWORD(pos.y);
          if ( !v30 )
            break;
          if ( SLODWORD(pos.y) >= this->m_pathLength
            || *(_DWORD *)(DWORD1(dir) + 28) == 0 && (*(_BYTE *)(*(_DWORD *)(DWORD1(dir) + 8) + 84) & 2) == 0 )
          {
            if ( LODWORD(pos.y) == OurPositionOnPath )
            {
              probe.x = *((float *)&dir + 2) - along.x;
              probe.y = *((float *)&dir + 3) - along.y;
              probe.z = v74 - along.z;
              p_probe = &probe;
            }
            else
            {
              myOrigin.x = *((float *)&dir + 2) - *(float *)(DWORD1(dir) - 8);
              myOrigin.y = *((float *)&dir + 3) - *(float *)(DWORD1(dir) - 4);
              myOrigin.z = v74 - *(float *)DWORD1(dir);
              p_probe = &myOrigin;
            }
            v33 = *(_QWORD *)&p_probe->x;
            v34 = p_probe->z;
            *(_QWORD *)&to.x = v33;
            *(float *)&dir = *((float *)&v33 + 1) * *((float *)&v33 + 1);
            to.z = v34;
            pos.z = fsqrt((float)(*((float *)&v33 + 1) * *((float *)&v33 + 1)) + (float)(to.x * to.x)) + pos.z;
            if ( pos.z < aheadRange )
            {
              y_low = LODWORD(pos.y) + 1;
              LODWORD(pos.y) = y_low;
              DWORD1(dir) += 24;
              if ( y_low < this->m_pathLength )
                continue;
            }
          }
          goto LABEL_63;
        }
        HIBYTE(pos.x) = 0;
LABEL_63:
        v27 = pos.z;
        if ( y_low < OurPositionOnPath )
        {
          y_low = OurPositionOnPath;
          goto LABEL_68;
        }
      }
      v35 = this->m_pathLength;
      if ( y_low >= v35 )
        y_low = v35 - 1;
LABEL_68:
      if ( y_low != 0 )
      {
        v38 = *(&this->m_avoidTimestamp + 6 * y_low);
        v39 = this->m_path[y_low].pos.x;
        v40 = *((float *)&this->m_isStopping + 6 * y_low);
        v41 = this->m_path[y_low].pos.y;
        v42 = this->m_path[y_low].pos.z - *(float *)&(&this->m_stillTimer.__vftable)[6 * y_low];
        v43 = (float *)((char *)this + 24 * y_low);
        v44 = v39 - v38;
        v45 = v41 - v40;
        v46 = 1.0 / fsqrt((float)(v45 * v45) + (float)(v44 * v44));
        v47 = 1.0 - (float)((float)(v27 - aheadRange) * v46);
        v48 = 0.0;
        DWORD1(dir) = v43;
        initDir.x = v44;
        initDir.y = v45;
        initDir.z = v42;
        pos.z = v47;
        if ( v47 < 0.0 || (v48 = 1.0, v47 > 1.0) )
        {
          v47 = v48;
          pos.z = v48;
        }
        v49 = HIBYTE(pos.x) == 0;
        v36 = point;
        v50 = (float)(v42 * v47) + v43[1972];
        v51 = (float)(v44 * v47) + v38;
        v52 = (float)(v45 * v47) + v40;
        point->x = v51;
        point->y = v52;
        point->z = v50;
        if ( !v49 )
          goto LABEL_81;
        *(float *)&dir = v46 * 25.0;
        to.x = v51;
        to.y = v52;
        to.z = v50 + 35.5;
        if ( v47 > 0.0 )
        {
          do
          {
            v53 = IsWalkableTraceLineClear(from: &v66, &to, flags: 4u);
            v47 = pos.z;
            if ( v53 )
              break;
            v54 = (float)(initDir.x * (float)(pos.z - *(float *)&dir)) + *(float *)(DWORD1(dir) + 7880);
            v55 = (float)(initDir.z * (float)(pos.z - *(float *)&dir)) + *(float *)(DWORD1(dir) + 7888);
            v56 = *(float *)(DWORD1(dir) + 7884) + (float)(initDir.y * (float)(pos.z - *(float *)&dir));
            pos.z = pos.z - *(float *)&dir;
            v47 = pos.z;
            point->x = v54;
            point->y = v56;
            point->z = v55;
          }
          while ( v47 > 0.0 );
          v36 = point;
          v43 = (float *)DWORD1(dir);
        }
        if ( v47 > 0.0 )
          goto LABEL_81;
        v36->x = v43[1970];
        v36->y = v43[1971];
        v37 = v43[1972];
      }
      else
      {
        v36 = point;
        point->x = this->m_path[0].pos.x;
        point->y = this->m_path[0].pos.y;
        v37 = this->m_path[0].pos.z;
      }
      v36->z = v37;
LABEL_81:
      if ( BYTE2(pos.x) == 0 )
      {
        v57 = v36->x - v62.x;
        v58 = v36->y - v62.y;
        if ( (float)((float)(*((float *)&prevDir + 2) * v58) + (float)(*((float *)&prevDir + 1) * v57)) < 0.0
          || (float)((float)(v58 * v58) + (float)(v57 * v57)) < 2500.0 )
        {
          LODWORD(pos.z) = OurPositionOnPath;
          if ( OurPositionOnPath < this->m_pathLength )
          {
            v59 = prevDir + 7908;
            while ( *(_DWORD *)(v59 + 8) == 0
                 && (*(_BYTE *)(*(_DWORD *)(v59 - 12) + 84) & 2) == 0
                 && (float)((float)((float)(*(float *)v59 - v62.y) * (float)(*(float *)v59 - v62.y))
                          + (float)((float)(*(float *)(v59 - 4) - v62.x) * (float)(*(float *)(v59 - 4) - v62.x))) <= 2500.0 )
            {
              ++LODWORD(pos.z);
              v59 += 24;
              if ( SLODWORD(pos.z) >= this->m_pathLength )
                goto LABEL_92;
            }
            OurPositionOnPath = LODWORD(pos.z);
            v36->x = this->m_path[LODWORD(pos.z)].pos.x;
            v36->y = this->m_path[OurPositionOnPath].pos.y;
            v36->z = this->m_path[OurPositionOnPath].pos.z;
          }
LABEL_92:
          if ( LODWORD(pos.z) == this->m_pathLength )
          {
            v60 = &this->m_avoidTimestamp + 6 * this->m_pathLength;
            v36->x = *v60;
            v36->y = v60[1];
            v36->z = v60[2];
            return this->m_pathLength - 1;
          }
        }
      }
      return OurPositionOnPath;
    }
  }
  *point = *(Vector *)(v22 + 7904);
  return OurPositionOnPath;
}

//------------------------------------------------------------------------------
// Address: 0x102BDA00
// Name: private: void CCSBot::SetPathIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetPathIndex(CCSBot *this, int newIndex)
{
  int m_pathLength; // ecx
  int v4; // eax

  m_pathLength = this->m_pathLength;
  v4 = m_pathLength - 1;
  if ( newIndex < m_pathLength - 1 )
    v4 = newIndex;
  this->m_pathIndex = v4;
  this->m_areaEnteredTimestamp = gpGlobals->curtime;
  if ( this->m_path[v4].ladder != nullptr )
  {
    CCSBot::SetupLadderMovement(this);
  }
  else if ( v4 >= m_pathLength || v4 < 2 )
  {
    this->m_spotEncounter = nullptr;
    this->m_pathLadder = nullptr;
  }
  else
  {
    this->m_spotEncounter = CNavArea::GetSpotEncounter(
                              this: *((CNavArea **)&this->m_lastKnownArea + 6 * v4),
                              from: *((const CNavArea **)&this->m_taskEntity.m_Index + 6 * v4),
                              to: this->m_path[v4].area);
    this->m_pathLadder = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BDAB0
// Name: public: bool CCSBot::IsFriendInTheWay(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsFriendInTheWay(CCSBot *this, const Vector *goalPos)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  int v5; // eax
  CBasePlayer *v6; // esi
  edict_t *m_pPev; // eax
  edict_t *v8; // ebx
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float z; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  Vector *Centroid; // eax
  Vector v18; // [esp+Ch] [ebp-38h] BYREF
  Vector myOrigin; // [esp+18h] [ebp-2Ch] BYREF
  Vector moveDir; // [esp+24h] [ebp-20h] BYREF
  Vector pos; // [esp+30h] [ebp-14h]
  float length; // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  p_m_timestamp = &this->m_avoidFriendTimer.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_avoidFriendTimer) > this->m_avoidFriendTimer.m_timestamp.m_Value )
  {
    v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_avoidFriendTimer) + 0.5;
    *(float *)&i = v4;
    if ( p_m_timestamp->m_Value != v4 )
    {
      this->m_avoidFriendTimer.NetworkStateChanged(
        this: &this->m_avoidFriendTimer,
        a2: &this->m_avoidFriendTimer.m_timestamp);
      SLODWORD(p_m_timestamp->m_Value) = i;
    }
    if ( this->m_avoidFriendTimer.m_duration.m_Value != 0.5 )
    {
      this->m_avoidFriendTimer.NetworkStateChanged(
        this: &this->m_avoidFriendTimer,
        a2: &this->m_avoidFriendTimer.m_duration);
      this->m_avoidFriendTimer.m_duration.m_Value = 0.5;
    }
    GetCentroid(result: &myOrigin, player: this);
    moveDir.x = goalPos->x - myOrigin.x;
    moveDir.y = goalPos->y - myOrigin.y;
    moveDir.z = goalPos->z - myOrigin.z;
    length = VectorNormalize(vec: &moveDir);
    this->m_isFriendInTheWay = false;
    v5 = 1;
    i = 1;
    if ( gpGlobals->maxClients >= 1 )
    {
      while ( 1 )
      {
        v6 = UTIL_PlayerByIndex(playerIndex: v5);
        if ( v6 != nullptr && v6->IsAlive(this: v6) && CBaseEntity::InSameTeam(this: v6, pEntity: this) )
        {
          m_pPev = v6->m_Network.m_pPev;
          v8 = m_pPev != nullptr ? (edict_t *)(m_pPev - gpGlobals->pEdicts) : nullptr;
          if ( v8 != CBaseEntity::entindex(this) )
          {
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            if ( (v6->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
            v9 = v6->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x;
            v10 = v6->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
            v11 = v6->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z;
            if ( (float)((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11)) <= 10000.0 )
            {
              v12 = (float)((float)(v9 * moveDir.x) + (float)(v10 * moveDir.y)) + (float)(v11 * moveDir.z);
              if ( v12 > 0.0 )
              {
                if ( v12 < length )
                {
                  v14 = (float)(moveDir.x * v12) + myOrigin.x;
                  v15 = (float)(moveDir.y * v12) + myOrigin.y;
                  z = (float)(moveDir.z * v12) + myOrigin.z;
                  pos.x = v14;
                  pos.y = v15;
                }
                else
                {
                  pos.x = goalPos->x;
                  pos.y = goalPos->y;
                  z = goalPos->z;
                }
                pos.z = z;
                Centroid = GetCentroid(result: &v18, player: v6);
                if ( (float)((float)((float)((float)(pos.y - Centroid->y) * (float)(pos.y - Centroid->y))
                                   + (float)((float)(pos.x - Centroid->x) * (float)(pos.x - Centroid->x)))
                           + (float)((float)(pos.z - Centroid->z) * (float)(pos.z - Centroid->z))) < 900.0 )
                  break;
              }
            }
          }
        }
        v5 = i + 1;
        i = v5;
        if ( v5 > gpGlobals->maxClients )
          return this->m_isFriendInTheWay;
      }
      this->m_isFriendInTheWay = true;
    }
  }
  return this->m_isFriendInTheWay;
}

//------------------------------------------------------------------------------
// Address: 0x102BDD90
// Name: public: void CCSBot::FeelerReflexAdjustment(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::FeelerReflexAdjustment(CCSBot *this, Vector *goalPosition)
{
  CCSNavArea *m_lastKnownArea; // eax
  float v4; // xmm0_4
  bool (__thiscall *IsRunning)(CBasePlayer *); // edx
  float v6; // xmm0_4
  bool v7; // zf
  float v8; // xmm0_4
  float v9; // xmm1_4
  float z; // xmm2_4
  float x; // xmm4_4
  float y; // xmm5_4
  unsigned int v13; // eax
  float v14; // ecx
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  bool v19; // bl
  ConVar *m_pParent; // eax
  bool v21; // bl
  ConVar *v22; // eax
  float v23; // xmm0_4
  Vector *v24; // eax
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  unsigned __int8 v32; // [esp-8h] [ebp-7Ch]
  unsigned __int8 v33; // [esp-8h] [ebp-7Ch]
  unsigned __int8 v34; // [esp-4h] [ebp-78h]
  unsigned __int8 v35; // [esp-4h] [ebp-78h]
  Vector eye; // [esp+Ch] [ebp-68h] BYREF
  Vector normal; // [esp+18h] [ebp-5Ch] BYREF
  Vector feet; // [esp+24h] [ebp-50h]
  Vector lat; // [esp+30h] [ebp-44h]
  Vector from; // [esp+3Ch] [ebp-38h] BYREF
  Vector to; // [esp+48h] [ebp-2Ch] BYREF
  float ground; // [esp+54h] [ebp-20h] BYREF
  float v43; // [esp+58h] [ebp-1Ch]
  float v44; // [esp+5Ch] [ebp-18h]
  float v45; // [esp+60h] [ebp-14h]
  float v46; // [esp+64h] [ebp-10h]
  float feelerOffset; // [esp+68h] [ebp-Ch]
  float feelerLength; // [esp+6Ch] [ebp-8h]
  bool leftClear; // [esp+73h] [ebp-1h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea != nullptr && (m_lastKnownArea->m_attributeFlags & 4) != 0 )
    return;
  feet.x = BotCOS(angle: this->m_forwardAngle);
  lat.x = -BotSIN(angle: this->m_forwardAngle);
  if ( this->m_isCrouching )
    v4 = 15.0;
  else
    v4 = 20.0;
  IsRunning = this->IsRunning;
  feelerOffset = v4;
  if ( IsRunning(this) )
    v6 = 50.0;
  else
    v6 = 30.0;
  v7 = !this->m_isCrouching;
  feelerLength = v6;
  if ( !v7 )
    feelerLength = 20.0;
  this->EyePosition(this, result: &eye);
  if ( CCSBot::GetSimpleGroundHeightWithFloor(this, pos: &eye, height: &ground, &normal) == 0 )
    return;
  v8 = (float)(normal.z * feet.x) - (float)(normal.y * 0.0);
  v9 = (float)(normal.x * 0.0) - (float)(normal.z * lat.x);
  z = (float)(normal.y * lat.x) - (float)(normal.x * feet.x);
  x = (float)(v9 * normal.z) - (float)(z * normal.y);
  y = (float)(z * normal.x) - (float)(normal.z * v8);
  v13 = (unsigned int)this->m_iEFlags >> 11;
  feet.x = v8;
  feet.y = v9;
  feet.z = z;
  lat.x = x;
  lat.y = y;
  lat.z = (float)(normal.y * v8) - (float)(v9 * normal.x);
  if ( (v13 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    y = lat.y;
    x = lat.x;
    z = feet.z;
    v9 = feet.y;
    v8 = feet.x;
  }
  v14 = this->m_vecAbsOrigin.z;
  *(_QWORD *)&feet.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  v15 = y * feelerOffset;
  v45 = lat.z * feelerOffset;
  v16 = (float)(lat.z * feelerOffset) + (float)(v14 + 18.1);
  feet.z = v14 + 18.1;
  v17 = v9 * feelerLength;
  v18 = z * feelerLength;
  feelerOffset = x * feelerOffset;
  feelerLength = v8 * feelerLength;
  v44 = v17;
  v43 = v18;
  v46 = v15;
  from.x = feelerOffset + feet.x;
  from.y = feet.y + v15;
  from.z = v16;
  to.x = feelerLength + (float)(feelerOffset + feet.x);
  to.y = v17 + (float)(feet.y + v15);
  to.z = v18 + v16;
  v19 = IsWalkableTraceLineClear(&from, &to, flags: 7u);
  m_pParent = cv_bot_traceview.m_pParent;
  leftClear = v19;
  if ( cv_bot_traceview.m_pParent != nullptr )
  {
    if ( cv_bot_traceview.m_pParent->m_Value.m_nValue == 1 )
    {
      if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
      {
LABEL_20:
        if ( v19 )
        {
          v34 = -1;
          v32 = 0;
        }
        else
        {
          v34 = 0;
          v32 = -1;
        }
        UTIL_DrawBeamPoints(vecStart: from, vecEnd: to, iLifetime: 1, bRed: v32, bGreen: v34, bBlue: 0);
        goto LABEL_24;
      }
      m_pParent = cv_bot_traceview.m_pParent;
    }
    if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue != 10 )
      goto LABEL_24;
    goto LABEL_20;
  }
LABEL_24:
  from.x = feet.x - feelerOffset;
  from.y = feet.y - v46;
  from.z = feet.z - v45;
  to.x = feelerLength + (float)(feet.x - feelerOffset);
  to.y = v44 + (float)(feet.y - v46);
  to.z = v43 + (float)(feet.z - v45);
  v21 = IsWalkableTraceLineClear(&from, &to, flags: 7u);
  v22 = cv_bot_traceview.m_pParent;
  if ( cv_bot_traceview.m_pParent != nullptr )
  {
    if ( cv_bot_traceview.m_pParent->m_Value.m_nValue == 1 )
    {
      if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
        goto LABEL_30;
      v22 = cv_bot_traceview.m_pParent;
    }
    if ( v22 != nullptr && v22->m_Value.m_nValue == 10 )
    {
LABEL_30:
      if ( v21 )
      {
        v35 = -1;
        v33 = 0;
      }
      else
      {
        v35 = 0;
        v33 = -1;
      }
      UTIL_DrawBeamPoints(vecStart: from, vecEnd: to, iLifetime: 1, bRed: v33, bGreen: v35, bBlue: 0);
    }
  }
  if ( this->m_isCrouching )
    v23 = 150.0;
  else
    v23 = 300.0;
  if ( v21 )
  {
    if ( leftClear )
      return;
    v24 = goalPosition;
    v30 = lat.y * v23;
    v31 = lat.z * v23;
    v27 = goalPosition->x - (float)(lat.x * v23);
    v28 = goalPosition->y - v30;
    v29 = goalPosition->z - v31;
  }
  else
  {
    if ( !leftClear )
      return;
    v24 = goalPosition;
    v25 = lat.y * v23;
    v26 = lat.z * v23;
    v27 = goalPosition->x + (float)(lat.x * v23);
    v28 = goalPosition->y + v25;
    v29 = goalPosition->z + v26;
  }
  v24->z = v29;
  v24->y = v28;
  v24->x = v27;
}

//------------------------------------------------------------------------------
// Address: 0x102BE200
// Name: public: bool CCSBot::ComputePath(class Vector const __near &,enum RouteType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::ComputePath(CCSBot *this, const Vector *goal, RouteType route)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  IUniformRandomStream *v5; // ecx
  double v6; // st7
  CNavArea *NearestNavArea; // eax
  CCSNavArea *m_lastKnownArea; // edi
  CNavArea *v9; // ebx
  const Vector *v10; // eax
  CCSNavArea *v11; // eax
  float z; // edx
  int v13; // eax
  CNavArea *m_parent; // ecx
  CNavArea *v15; // ecx
  NavTraverseType *p_how; // edx
  double curtime; // st7
  int TeamNumber; // eax
  int v20; // ecx
  int v21; // edi
  int v22; // edx
  CCSBot::ConnectInfo *m_path; // eax
  Vector close; // [esp+30h] [ebp-28h] BYREF
  Vector pathEndPosition; // [esp+3Ch] [ebp-1Ch] BYREF
  _BYTE v26[4]; // [esp+48h] [ebp-10h] BYREF
  PathCost cost; // [esp+4Ch] [ebp-Ch] BYREF
  CNavArea *closestArea; // [esp+54h] [ebp-4h] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::ComputePath",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  p_m_timestamp = &this->m_repathTimer.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_repathTimer) <= this->m_repathTimer.m_timestamp.m_Value )
    goto LABEL_30;
  *(float *)&closestArea = _RandomFloat(this: v5, a2: 0.40000001, a3: 0.60000002);
  v6 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_repathTimer) + *(float *)&closestArea;
  *(float *)&cost.m_route = v6;
  if ( p_m_timestamp->m_Value != v6 )
  {
    this->m_repathTimer.NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
    SLODWORD(p_m_timestamp->m_Value) = cost.m_route;
  }
  if ( this->m_repathTimer.m_duration.m_Value != *(float *)&closestArea )
  {
    this->m_repathTimer.NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_duration);
    this->m_repathTimer.m_duration.m_Value = *(float *)&closestArea;
  }
  this->m_pathLength = 0;
  this->m_pathLadder = nullptr;
  this->m_isStopping = false;
  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos: goal,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  m_lastKnownArea = this->m_lastKnownArea;
  v9 = NearestNavArea;
  if ( m_lastKnownArea == nullptr )
    goto LABEL_30;
  v10 = this->EyePosition(this, result: v26);
  CNavArea::GetClosestPointOnArea(this: m_lastKnownArea, pPos: v10, &close);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (float)(close.z - this->m_vecAbsOrigin.z) > 58.0 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Last known area is above my head - resetting to nearest area.\n");
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v11 = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                          this: TheNavMesh,
                          pos: &this->m_vecAbsOrigin,
                          anyZ: false,
                          maxDist: 500.0,
                          checkLOS: true,
                          checkGround: true);
    this->m_lastKnownArea = v11;
    if ( v11 == nullptr )
      goto LABEL_30;
    m_lastKnownArea = v11;
  }
  z = goal->z;
  *(_QWORD *)&pathEndPosition.x = *(_QWORD *)&goal->x;
  pathEndPosition.z = z;
  if ( v9 != nullptr )
    pathEndPosition.z = CNavArea::GetZ(this: v9, x: pathEndPosition.x, y: pathEndPosition.y);
  else
    CNavMesh::GetGroundHeight(this: TheNavMesh, pos: &pathEndPosition, height: &pathEndPosition.z, normal: nullptr);
  if ( m_lastKnownArea == v9 )
    goto LABEL_18;
  cost.m_route = route;
  *(float *)&closestArea = 0.0;
  cost.m_bot = this;
  if ( NavAreaBuildPath<PathCost>(
         startArea: m_lastKnownArea,
         goalArea: v9,
         goalPos: goal,
         costFunc: &cost,
         &closestArea,
         maxPathLength: 0.0,
         teamID: -1,
         ignoreNavBlockers: false) == 0 )
    v9 = closestArea;
  v13 = 0;
  m_parent = v9;
  if ( v9 == nullptr )
  {
LABEL_30:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  do
  {
    m_parent = m_parent->m_parent;
    ++v13;
  }
  while ( m_parent != nullptr );
  if ( v13 > 255 )
  {
    v13 = 255;
LABEL_25:
    this->m_pathLength = v13;
    v15 = v9;
    p_how = &this->m_path[v13].how;
    do
    {
      if ( v15 == nullptr )
        break;
      p_how -= 6;
      *((_DWORD *)p_how - 1) = v15;
      *p_how = v15->m_parentHow;
      v15 = v15->m_parent;
      --v13;
    }
    while ( v13 != 0 );
    if ( CCSBot::ComputePathPositions(this) != 0 )
    {
      this->m_path[this->m_pathLength].area = v9;
      this->m_path[this->m_pathLength].pos = pathEndPosition;
      this->m_path[this->m_pathLength].ladder = nullptr;
      this->m_path[this->m_pathLength++].how = NUM_TRAVERSE_TYPES;
      this->m_pathIndex = 1;
      curtime = gpGlobals->curtime;
      this->m_spotEncounter = nullptr;
      this->m_areaEnteredTimestamp = curtime;
      this->m_goalPosition.x = this->m_path[1].pos.x;
      this->m_goalPosition.y = this->m_path[1].pos.y;
      this->m_goalPosition.z = this->m_path[1].pos.z;
      if ( this->m_path[1].ladder != nullptr )
        CCSBot::SetupLadderMovement(this);
      else
        this->m_pathLadder = nullptr;
      if ( CCSBot::IsSafe(this) )
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this);
        v20 = 0;
        if ( this->m_pathLength > 0 )
        {
          v21 = 4 * (TeamNumber % 2) + 212;
          v22 = ((TeamNumber == 2) + 2) % 2;
          m_path = this->m_path;
          do
          {
            if ( *(float *)((char *)&m_path->area->__vftable + v21) > m_path->area->m_earliestOccupyTime[v22] )
              break;
            ++v20;
            ++m_path;
          }
          while ( v20 < this->m_pathLength );
        }
        if ( v20 >= this->m_pathLength )
          this->m_initialEncounterArea = nullptr;
        else
          this->m_initialEncounterArea = this->m_path[v20].area;
      }
      goto LABEL_45;
    }
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Error building path\n");
    this->m_isStopping = false;
    this->m_pathLength = 0;
    this->m_pathLadder = nullptr;
    goto LABEL_30;
  }
  if ( v13 == 0 )
    goto LABEL_30;
  if ( v13 != 1 )
    goto LABEL_25;
LABEL_18:
  CCSBot::BuildTrivialPath(this, goal: &pathEndPosition);
LABEL_45:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BE690
// Name: private: bool CCSBot::UpdateLadderMovement(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CCSBot::UpdateLadderMovement@<al>(CCSBot *this@<ecx>, float a2@<ebp>)
{
  CCSBot::LadderNavState m_pathLadderState; // eax
  CCSBot_vtbl *v4; // edx
  bool result; // al
  CCSBot::LadderNavState v6; // eax
  float y; // xmm3_4
  float x; // xmm2_4
  int v9; // edi
  const CNavLadder *p_m_bottom; // ecx
  const CNavLadder *m_pathLadder; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  __int128 v15; // xmm1
  float v16; // xmm0_4
  const Vector *AbsOrigin; // eax
  const Vector *AbsVelocity; // eax
  const QAngle *v19; // eax
  const CNavLadder *v20; // ecx
  int v21; // edx
  const CNavLadder *v22; // eax
  float v23; // xmm1_4
  float z; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  __int128 v28; // xmm1
  void (__thiscall *Run)(CBot<CCSPlayer> *); // eax
  Vector *PosAtHeight; // eax
  const CNavLadder *v31; // ecx
  CNavArea *area; // eax
  float v33; // xmm0_4
  const QAngle *v34; // eax
  __int32 v35; // eax
  Vector *v36; // eax
  const QAngle *v37; // eax
  const CNavLadder *v38; // edi
  CCSBot_vtbl *v39; // eax
  const CNavLadder *v40; // ecx
  CNavArea *v41; // eax
  CCSBot_vtbl *v42; // edx
  CCSBot *v43; // ecx
  float m_pathLadderEnd; // xmm0_4
  bool v45; // zf
  double FeetZ; // st7
  int m_pathIndex; // eax
  const CNavLadder *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  int v51; // eax
  ConVar *m_pParent; // eax
  float b; // [esp+4h] [ebp-74h]
  float ba; // [esp+4h] [ebp-74h]
  float bb; // [esp+4h] [ebp-74h]
  Vector *bc; // [esp+4h] [ebp-74h]
  int tolerance; // [esp+8h] [ebp-70h]
  __int128 v58; // [esp+1Ch] [ebp-5Ch] BYREF
  Vector v59; // [esp+30h] [ebp-48h] BYREF
  __int128 v60; // [esp+3Ch] [ebp-3Ch] BYREF
  Vector to; // [esp+4Ch] [ebp-2Ch] BYREF
  QAngle idealAngle; // [esp+58h] [ebp-20h] BYREF
  Vector myOrigin; // [esp+64h] [ebp-14h] BYREF
  float destHeight; // [esp+70h] [ebp-8h]
  float retaddr; // [esp+78h] [ebp+0h]

  myOrigin.z = a2;
  destHeight = retaddr;
  if ( this->m_pathLadder == nullptr )
    return false;
  if ( (float)(gpGlobals->curtime - this->m_pathLadderTimestamp) > 10.0
    && (cv_bot_debug.m_pParent == nullptr || cv_bot_debug.m_pParent->m_Value.m_nValue == 0) )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Ladder timeout!\n");
LABEL_13:
    this->Jump(this, a2: true);
    CCSBot::Wiggle(this);
    CCSBot::ResetStuckMonitor(this);
    v4 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_isStopping = false;
    this->m_pathLength = 0;
    this->m_pathLadder = nullptr;
    v4->Run(this);
    return false;
  }
  m_pathLadderState = this->m_pathLadderState;
  if ( ((unsigned int)m_pathLadderState < FACE_ASCENDING_LADDER
     || m_pathLadderState == ASCEND_LADDER
     || m_pathLadderState == DESCEND_LADDER
     || m_pathLadderState == DISMOUNT_ASCENDING_LADDER
     || m_pathLadderState == MOVE_TO_DESTINATION)
    && this->m_isStuck )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Giving up ladder - stuck\n");
    goto LABEL_13;
  }
  CCSBot::ResetStuckMonitor(this);
  GetCentroid(result: (Vector *)&idealAngle, player: this);
  v6 = this->m_pathLadderState;
  y = idealAngle.y;
  x = idealAngle.x;
  v9 = 3;
  if ( (unsigned int)(v6 - 4) > 3
    || (v6 == MOUNT_ASCENDING_LADDER || v6 == ASCEND_LADDER
      ? (p_m_bottom = (const CNavLadder *)&this->m_pathLadder->m_bottom)
      : (p_m_bottom = this->m_pathLadder),
        (float)((float)((float)(p_m_bottom->m_top.y - idealAngle.y) * (float)(p_m_bottom->m_top.y - idealAngle.y))
              + (float)((float)(p_m_bottom->m_top.x - idealAngle.x) * (float)(p_m_bottom->m_top.x - idealAngle.x))) <= 40000.0) )
  {
    this->m_areaEnteredTimestamp = gpGlobals->curtime;
    switch ( v6 )
    {
      case APPROACH_ASCENDING_LADDER:
        m_pathLadder = this->m_pathLadder;
        v12 = x - this->m_goalPosition.x;
        v13 = y - this->m_goalPosition.y;
        v14 = (float)(v13 * m_pathLadder->m_normal.y) + (float)(v12 * m_pathLadder->m_normal.x);
        HIBYTE(myOrigin.y) = 0;
        if ( v14 < 0.0
          && COERCE_FLOAT(
               COERCE_UNSIGNED_INT(
                 (float)(m_pathLadder->m_normal.x * v13)
               + (float)(COERCE_FLOAT(LODWORD(m_pathLadder->m_normal.y) ^ _mask__NegFloat_) * v12))
             & _mask__AbsFloat_) < 10.0 )
        {
          v15 = 0;
          *(float *)&v15 = fsqrt((float)(v13 * v13) + (float)(v12 * v12));
          v58 = v15;
          HIBYTE(myOrigin.y) = *(float *)&v15 < 25.0;
        }
        v16 = (float)(v13 * v13) + (float)(v12 * v12);
        myOrigin.x = v16;
        if ( v16 < 2500.0 )
        {
          this->Walk(this);
          this->StandUp(this);
          v16 = myOrigin.x;
        }
        if ( v16 < 10000.0 && !CBasePlayer::IsOnLadder(this) )
        {
          LODWORD(myOrigin.x) = this->m_pathLadder;
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          if ( (float)(*(float *)(LODWORD(myOrigin.x) + 20) - AbsOrigin->z) > 58.0 )
          {
            AbsVelocity = CBaseEntity::GetAbsVelocity(this);
            VectorAngles(forward: AbsVelocity, angles: (QAngle *)((char *)&v60 + 4));
            b = *((float *)&v60 + 2);
            v19 = this->EyeAngles(this);
            if ( AnglesAreEqual(a: v19->y, b, tolerance: 15.0) )
              this->Jump(this, a2: false);
          }
        }
        if ( CBasePlayer::IsOnLadder(this) )
        {
          this->m_pathLadderState = ASCEND_LADDER;
          CBot<CCSPlayer>::PrintIfWatched(this, format: "ASCEND_LADDER\n");
          CCSBot::ComputeLadderEndpoint(this, isAscending: true);
        }
        else if ( HIBYTE(myOrigin.y) != 0 )
        {
          this->m_pathLadderState = FACE_ASCENDING_LADDER;
          CBot<CCSPlayer>::PrintIfWatched(this, format: "FACE_ASCENDING_LADDER\n");
        }
        else
        {
          CCSBot::MoveTowardsPosition(
            this,
            a2: COERCE_FLOAT((Vector *)&myOrigin.z),
            a3: (int)&this->m_goalPosition,
            a4: (int)this,
            pos: &this->m_goalPosition);
        }
        goto LABEL_109;
      case APPROACH_DESCENDING_LADDER:
        v9 = (int)this->m_pathLadder;
        if ( *(float *)(v9 + 20) + 35.5 >= CCSBot::GetFeetZ(this, a2: (int)&myOrigin.z) )
          goto LABEL_39;
        v25 = idealAngle.x - this->m_goalPosition.x;
        v26 = idealAngle.y - this->m_goalPosition.y;
        v27 = (float)(v26 * *(float *)(v9 + 64)) + (float)(v25 * *(float *)(v9 + 60));
        HIBYTE(myOrigin.y) = 0;
        if ( v27 > 0.0
          && COERCE_FLOAT(
               COERCE_UNSIGNED_INT(
                 (float)(*(float *)(v9 + 60) * v26)
               + (float)(COERCE_FLOAT(*(_DWORD *)(v9 + 64) ^ _mask__NegFloat_) * v25))
             & _mask__AbsFloat_) < 10.0 )
        {
          v28 = 0;
          *(float *)&v28 = fsqrt((float)(v26 * v26) + (float)(v25 * v25));
          v60 = v28;
          HIBYTE(myOrigin.y) = *(float *)&v28 < 25.0;
        }
        if ( *(CCSNavArea **)(v9 + 44) != this->m_lastKnownArea
          && !this->m_isCrouching
          && (float)((float)(v26 * v26) + (float)(v25 * v25)) < 22500.0 )
        {
          this->Walk(this);
        }
        if ( CBasePlayer::IsOnLadder(this) )
        {
          Run = this->Run;
          this->m_pathLadderState = DESCEND_LADDER;
          Run(this);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "DESCEND_LADDER\n");
          CCSBot::ComputeLadderEndpoint(this, isAscending: false);
        }
        else if ( HIBYTE(myOrigin.y) != 0 )
        {
          this->m_pathLadderState = FACE_DESCENDING_LADDER;
          CBot<CCSPlayer>::PrintIfWatched(this, format: "FACE_DESCENDING_LADDER\n");
        }
        else
        {
LABEL_108:
          CCSBot::MoveTowardsPosition(
            this,
            a2: COERCE_FLOAT((Vector *)&myOrigin.z),
            a3: v9,
            a4: (int)this,
            pos: &this->m_goalPosition);
        }
        goto LABEL_109;
      case FACE_ASCENDING_LADDER:
        PosAtHeight = CNavLadder::GetPosAtHeight(
                        this: (CNavLadder *)this->m_pathLadder,
                        result: &v59,
                        height: idealAngle.z);
        *((float *)&v60 + 1) = PosAtHeight->x - idealAngle.x;
        *((float *)&v60 + 2) = PosAtHeight->y - idealAngle.y;
        *((float *)&v60 + 3) = PosAtHeight->z - idealAngle.z;
        VectorAngles(forward: (const Vector *)((char *)&v60 + 4), angles: (QAngle *)&to);
        v31 = this->m_pathLadder;
        area = this->m_path[this->m_pathIndex].area;
        if ( area == v31->m_topForwardArea )
        {
          this->m_pathLadderDismountDir = FORWARD;
          goto LABEL_58;
        }
        if ( area == v31->m_topLeftArea )
        {
          v33 = to.y + 90.0;
          this->m_pathLadderDismountDir = 3;
        }
        else
        {
          if ( area != v31->m_topRightArea )
            goto LABEL_58;
          v33 = to.y - 90.0;
          this->m_pathLadderDismountDir = 1;
        }
        to.y = AngleNormalizePositive(angle: v33);
LABEL_58:
        ba = to.y;
        v34 = this->EyeAngles(this);
        if ( AnglesAreEqual(a: v34->y, b: ba, tolerance: 5.0) )
        {
          this->Run(this);
          CCSBot::ResetStuckMonitor(this);
          v35 = this->m_pathLadderDismountDir - 1;
          this->m_pathLadderState = MOUNT_ASCENDING_LADDER;
          if ( v35 != 0 )
          {
            if ( v35 == 2 )
              CBot<CCSPlayer>::PrintIfWatched(this, format: "MOUNT_ASCENDING_LADDER LEFT\n");
            else
              CBot<CCSPlayer>::PrintIfWatched(this, format: "MOUNT_ASCENDING_LADDER FORWARD\n");
          }
          else
          {
            CBot<CCSPlayer>::PrintIfWatched(this, format: "MOUNT_ASCENDING_LADDER RIGHT\n");
          }
        }
        goto LABEL_109;
      case FACE_DESCENDING_LADDER:
        v36 = CNavLadder::GetPosAtHeight(
                this: (CNavLadder *)this->m_pathLadder,
                result: (Vector *)((char *)&v58 + 4),
                height: idealAngle.z);
        *((float *)&v60 + 1) = v36->x - idealAngle.x;
        *((float *)&v60 + 2) = v36->y - idealAngle.y;
        *((float *)&v60 + 3) = v36->z - idealAngle.z;
        VectorAngles(forward: (const Vector *)((char *)&v60 + 4), angles: (QAngle *)&to);
        bb = to.y;
        v37 = this->EyeAngles(this);
        if ( AnglesAreEqual(a: v37->y, b: bb, tolerance: 5.0) )
        {
          this->m_pathLadderState = MOUNT_DESCENDING_LADDER;
          CCSBot::ResetStuckMonitor(this);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "MOUNT_DESCENDING_LADDER\n");
        }
        goto LABEL_109;
      case MOUNT_ASCENDING_LADDER:
        if ( CBasePlayer::IsOnLadder(this) )
        {
          this->m_pathLadderState = ASCEND_LADDER;
          CBot<CCSPlayer>::PrintIfWatched(this, format: "ASCEND_LADDER\n");
          CCSBot::ComputeLadderEndpoint(this, isAscending: true);
        }
        if ( !CBasePlayer::IsOnLadder(this) )
        {
          v38 = this->m_pathLadder;
          if ( (float)(v38->m_bottom.z - CBaseEntity::GetAbsOrigin(this)->z) > 58.0 )
            this->Jump(this, a2: false);
        }
        if ( this->m_pathLadderDismountDir == 1 )
        {
          this->StrafeLeft(this);
        }
        else
        {
          v39 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          if ( this->m_pathLadderDismountDir == 3 )
            ((void (__fastcall *)(CCSBot *))v39->StrafeRight)(a1: this);
          else
            ((void (__fastcall *)(CCSBot *))v39->MoveForward)(a1: this);
        }
        goto LABEL_109;
      case MOUNT_DESCENDING_LADDER:
        if ( this->m_pathLadder->m_bottom.z + 35.5 >= CCSBot::GetFeetZ(this, a2: (int)&myOrigin.z) )
        {
LABEL_39:
          CBot<CCSPlayer>::PrintIfWatched(this, format: "Fell from ladder.\n");
          v20 = this->m_pathLadder;
          v21 = 3 * this->m_pathIndex + 987;
          this->m_pathLadderState = MOVE_TO_DESTINATION;
          CNavArea::GetClosestPointOnArea(
            this: *((CNavArea **)&this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable
            + 2 * v21),
            pPos: &v20->m_bottom,
            close: &this->m_goalPosition);
          v22 = this->m_pathLadder;
          v23 = v22->m_normal.y;
          z = v22->m_normal.z;
          this->m_goalPosition.x = (float)(v22->m_normal.x * 16.0) + this->m_goalPosition.x;
          this->m_goalPosition.y = this->m_goalPosition.y + (float)(v23 * 16.0);
          this->m_goalPosition.z = this->m_goalPosition.z + (float)(z * 16.0);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "MOVE_TO_DESTINATION\n");
        }
        else
        {
          if ( CBasePlayer::IsOnLadder(this) )
          {
            this->m_pathLadderState = DESCEND_LADDER;
            CBot<CCSPlayer>::PrintIfWatched(this, format: "DESCEND_LADDER\n");
            CCSBot::ComputeLadderEndpoint(this, isAscending: false);
          }
          this->MoveForward(this);
        }
        goto LABEL_109;
      case ASCEND_LADDER:
        this->Run(this);
        if ( (this->m_path[this->m_pathIndex].area->m_attributeFlags & 1) != 0 )
          this->Crouch(this);
        if ( CCSBot::GetFeetZ(this, a2: (int)&myOrigin.z) < this->m_pathLadderEnd )
        {
          if ( !CBasePlayer::IsOnLadder(this) )
          {
            this->m_isStopping = false;
            this->m_pathLength = 0;
            this->m_pathLadder = nullptr;
            return false;
          }
        }
        else
        {
          this->m_pathLadderState = DISMOUNT_ASCENDING_LADDER;
          CBot<CCSPlayer>::PrintIfWatched(this, format: "DISMOUNT_ASCENDING_LADDER\n");
          v40 = this->m_pathLadder;
          v41 = this->m_path[this->m_pathIndex].area;
          if ( v41 == v40->m_topForwardArea )
          {
            this->m_pathLadderDismountDir = FORWARD;
          }
          else if ( v41 == v40->m_topLeftArea )
          {
            this->m_pathLadderDismountDir = 3;
          }
          else if ( v41 == v40->m_topRightArea )
          {
            this->m_pathLadderDismountDir = 1;
          }
          this->m_pathLadderDismountTimestamp = gpGlobals->curtime;
        }
        v42 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v43 = this;
        if ( this->m_pathLadderDismountDir == 1 )
        {
          v42->StrafeLeft(this);
        }
        else if ( this->m_pathLadderDismountDir == 3 )
        {
          ((void (__fastcall *)(CCSBot *))v42->StrafeRight)(a1: this);
        }
        else
        {
LABEL_103:
          ((void (__fastcall *)(CCSBot *))v42->MoveForward)(a1: v43);
        }
LABEL_109:
        m_pParent = cv_bot_traceview.m_pParent;
        if ( cv_bot_traceview.m_pParent == nullptr )
          goto LABEL_116;
        if ( cv_bot_traceview.m_pParent->m_Value.m_nValue == 1 )
        {
          if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
            goto LABEL_115;
          m_pParent = cv_bot_traceview.m_pParent;
        }
        if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue == 10 )
LABEL_115:
          CCSBot::DrawPath(this);
LABEL_116:
        result = true;
        break;
      case DESCEND_LADDER:
        this->Run(this);
        m_pathLadderEnd = this->m_pathLadderEnd;
        v45 = (this->m_path[this->m_pathIndex].area->m_attributeFlags & 8) == 0;
        myOrigin.x = m_pathLadderEnd;
        if ( v45 )
          myOrigin.x = m_pathLadderEnd + 35.5;
        if ( CBasePlayer::IsOnLadder(this) )
        {
          FeetZ = CCSBot::GetFeetZ(this, a2: (int)&myOrigin.z);
          if ( myOrigin.x < FeetZ )
            goto LABEL_102;
        }
        bc = &this->m_pathLadder->m_bottom;
        m_pathIndex = this->m_pathIndex;
        this->m_pathLadderState = MOVE_TO_DESTINATION;
        CNavArea::GetClosestPointOnArea(this: this->m_path[m_pathIndex].area, pPos: bc, close: &this->m_goalPosition);
        v48 = this->m_pathLadder;
        v49 = v48->m_normal.y;
        v50 = v48->m_normal.z;
        this->m_goalPosition.x = (float)(v48->m_normal.x * 16.0) + this->m_goalPosition.x;
        this->m_goalPosition.y = this->m_goalPosition.y + (float)(v49 * 16.0);
        this->m_goalPosition.z = this->m_goalPosition.z + (float)(v50 * 16.0);
        goto LABEL_101;
      case DISMOUNT_ASCENDING_LADDER:
        if ( (float)(gpGlobals->curtime - this->m_pathLadderDismountTimestamp) >= 0.40000001 )
        {
          v51 = 3 * this->m_pathIndex + 987;
          this->m_pathLadderState = MOVE_TO_DESTINATION;
          CNavArea::GetClosestPointOnArea(
            this: *((CNavArea **)&this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable
            + 2 * v51),
            pPos: (const Vector *)&idealAngle,
            close: &this->m_goalPosition);
LABEL_101:
          CBot<CCSPlayer>::PrintIfWatched(this, format: "MOVE_TO_DESTINATION\n");
        }
LABEL_102:
        v42 = this->CBot<CCSPlayer>::CCSPlayer::CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v43 = this;
        goto LABEL_103;
      case MOVE_TO_DESTINATION:
        if ( !CNavArea::Contains(this: this->m_path[this->m_pathIndex].area, pos: (const Vector *)&idealAngle) )
          goto LABEL_108;
        CBot<CCSPlayer>::PrintIfWatched(this, format: "Ladder traversed.\n");
        tolerance = this->m_pathIndex + 1;
        this->m_pathLadder = nullptr;
        CCSBot::SetPathIndex(this, newIndex: tolerance);
        this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
        this->m_lookAtDesc = nullptr;
        return false;
      default:
        goto LABEL_109;
    }
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Missed ladder\n");
    this->Jump(this, a2: true);
    this->m_isStopping = false;
    this->m_pathLength = 0;
    this->m_pathLadder = nullptr;
    this->Run(this);
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BF250
// Name: public: enum CCSBot::PathResult CCSBot::UpdatePathMovement(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CCSBot::UpdatePathMovement@<eax>(CCSBot *this@<ecx>, int a2@<ebp>, bool allowSpeedChange)
{
  const Vector *AbsVelocity; // eax
  int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  IntervalTimer_vtbl *v8; // xmm2_4
  float x; // xmm0_4
  int v11; // edi
  float v12; // xmm0_4
  bool v13; // zf
  int v14; // edi
  int m_pathLength; // eax
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  __int128 v21; // xmm0
  int v22; // edi
  float v23; // xmm5_4
  bool *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  __int128 v28; // xmm4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float y; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  CNavLadder *v38; // eax
  int v39; // eax
  int v40; // eax
  float v41; // xmm0_4
  float v42; // xmm1_4
  float *v43; // eax
  float v44; // xmm0_4
  float v45; // xmm1_4
  float z; // eax
  float v47; // xmm0_4
  ConVar *m_pParent; // eax
  int m_pathIndex; // eax
  int v50; // xmm0_4
  char *v51; // eax
  int *v52; // xmm0_4
  float v53; // xmm0_4
  float v54; // edx
  __int64 v55; // xmm0_8
  int v56; // eax
  int v57; // edx
  __int64 v58; // xmm0_8
  CountdownTimer *p_m_politeTimer; // ecx
  const BotProfile *m_profile; // eax
  float v61; // xmm0_4
  int v62; // edi
  float v63; // eax
  int v64; // edx
  CBasePlayer *ListenServerHost; // edi
  edict_t *v66; // eax
  int v67; // eax
  unsigned int v68; // eax
  CNavArea *NearestNavArea; // edi
  CNavArea *m_lastNavArea; // eax
  edict_t *m_pPev; // eax
  int TeamNumber; // eax
  int v73; // eax
  unsigned __int8 v74; // cl
  unsigned int m_place; // edi
  const char *v76; // eax
  CBasePlayer::NetworkVar_m_szLastPlaceName *v77; // eax
  CRecipientFilter v78; // [esp+34h] [ebp-5Ch] BYREF
  _BYTE close[36]; // [esp+54h] [ebp-3Ch] OVERLAPPED BYREF
  Vector myOrigin; // [esp+78h] [ebp-18h] BYREF
  int i; // [esp+84h] [ebp-Ch] BYREF
  int prevIndex; // [esp+88h] [ebp-8h]
  int retaddr; // [esp+90h] [ebp+0h]

  i = a2;
  prevIndex = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CCSBot::UpdatePathMovement",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  if ( this->m_pathLength == 0 )
    goto LABEL_150;
  if ( cv_bot_walk.m_pParent != nullptr && cv_bot_walk.m_pParent->m_Value.m_nValue != 0 )
    this->Walk(this);
  if ( CCSBot::UpdateLadderMovement(this, a2: COERCE_FLOAT(&i)) )
    goto LABEL_133;
  if ( this->m_pathLength == 0 )
  {
LABEL_150:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 2;
  }
  if ( CBasePlayer::IsOnLadder(this) )
    this->Jump(this, a2: true);
  if ( this->m_pathLadder == nullptr && this->m_lastKnownArea != nullptr && this->m_isStopping )
  {
    CCSBot::ResetStuckMonitor(this);
    this->ClearMovement(this);
    AbsVelocity = CBaseEntity::GetAbsVelocity(this);
    if ( (float)((float)((float)(AbsVelocity->x * AbsVelocity->x) + (float)(AbsVelocity->y * AbsVelocity->y))
               + (float)(AbsVelocity->z * AbsVelocity->z)) >= 0.1 )
    {
LABEL_133:
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
    this->m_isStopping = false;
  }
  v5 = this->m_pathLength - 1;
  HIBYTE(myOrigin.z) = 0;
  if ( this->m_pathIndex >= v5 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
    v6 = *(&this->m_avoidTimestamp + 6 * this->m_pathLength);
    v7 = *((float *)&this->m_isStopping + 6 * this->m_pathLength) - this->m_vecAbsOrigin.y;
    v8 = (&this->m_stillTimer.__vftable)[6 * this->m_pathLength];
    x = (float)((float)((float)(v6 - this->m_vecAbsOrigin.x) * (float)(v6 - this->m_vecAbsOrigin.x)) + (float)(v7 * v7))
      + (float)((float)(*(float *)&v8 - this->m_vecAbsOrigin.z) * (float)(*(float *)&v8 - this->m_vecAbsOrigin.z));
    myOrigin.x = x;
    if ( x < 40000.0 )
    {
      if ( allowSpeedChange && !this->m_isCrouching )
      {
        this->Walk(this);
        x = myOrigin.x;
      }
      if ( x < 2500.0 )
        HIBYTE(myOrigin.z) = 1;
      if ( x < 400.0 )
      {
        this->m_isStopping = false;
        this->m_pathLength = 0;
        this->m_pathLadder = nullptr;
        if ( allowSpeedChange )
          this->Run(this);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
    }
  }
  LODWORD(myOrigin.x) = CCSBot::FindPathPoint(
                          this,
                          a2: (int)&i,
                          aheadRange: 300.0,
                          point: &this->m_goalPosition,
                          prevIndex: (int *)&myOrigin.y);
  if ( myOrigin.y < 0.0 )
    myOrigin.y = 0.0;
  GetCentroid(result: (Vector *)&close[24], player: this);
  if ( this->m_pathIndex < this->m_pathLength - 1
    && (float)((float)((float)((float)(this->m_goalPosition.x - *(float *)&close[24])
                             * (float)(this->m_goalPosition.x - *(float *)&close[24]))
                     + (float)((float)(this->m_goalPosition.y - *(float *)&close[28])
                             * (float)(this->m_goalPosition.y - *(float *)&close[28])))
             + (float)((float)(this->m_goalPosition.z - *(float *)&close[32])
                     * (float)(this->m_goalPosition.z - *(float *)&close[32]))) < 10000.0
    && !CCSBot::IsLookingAtSpot(this, pri: PRIORITY_HIGH) )
  {
    this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
    this->m_lookAtDesc = nullptr;
    CCSBot::InhibitLookAround(this, duration: 0.5);
  }
  if ( SLODWORD(myOrigin.x) > this->m_pathIndex )
    CCSBot::SetPathIndex(this, newIndex: SLODWORD(myOrigin.x));
  if ( this->m_pathLadder == nullptr )
  {
    myOrigin.x = myOrigin.y;
    if ( SLODWORD(myOrigin.y) < this->m_pathLength )
    {
      LODWORD(myOrigin.y) = &this->m_path[LODWORD(myOrigin.y)];
      do
      {
        v11 = *(_DWORD *)LODWORD(myOrigin.y);
        if ( (*(_BYTE *)(*(_DWORD *)LODWORD(myOrigin.y) + 84) & 2) != 0 )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
          if ( *(float *)(v11 + 52) > this->m_vecAbsOrigin.z )
            break;
        }
        CNavArea::GetClosestPointOnArea(
          this: (CNavArea *)v11,
          pPos: (const Vector *)&close[24],
          close: (Vector *)&v78.m_Recipients.m_Size);
        if ( (float)((float)((float)(*(float *)&v78.m_Recipients.m_Size - *(float *)&close[24])
                           * (float)(*(float *)&v78.m_Recipients.m_Size - *(float *)&close[24]))
                   + (float)((float)(*(float *)&v78.m_Recipients.m_pElements - *(float *)&close[28])
                           * (float)(*(float *)&v78.m_Recipients.m_pElements - *(float *)&close[28]))) > 2500.0 )
          break;
        if ( (*(_BYTE *)(v11 + 84) & 1) != 0 )
        {
          this->Crouch(this);
          CCSBot::ResetStuckMonitor(this);
          goto LABEL_49;
        }
        LODWORD(myOrigin.y) += 24;
        ++LODWORD(myOrigin.x);
      }
      while ( SLODWORD(myOrigin.x) < this->m_pathLength );
    }
    v12 = gpGlobals->curtime - this->m_jumpTimestamp;
    if ( v12 > 3.0 || v12 >= 0.89999998 && (this->m_fFlags.m_Value & 1) != 0 )
      this->StandUp(this);
  }
LABEL_49:
  *(float *)&v78.m_Recipients.m_Size = this->m_goalPosition.x - *(float *)&close[24];
  *(float *)&v78.m_Recipients.m_pElements = this->m_goalPosition.y - *(float *)&close[28];
  *(float *)&v78.m_bUsingPredictionRules = this->m_goalPosition.z - *(float *)&close[32];
  myOrigin.x = UTIL_VecToYaw(vec: (const Vector *)&v78.m_Recipients.m_Size);
  this->m_forwardAngle = myOrigin.x;
  v13 = !this->m_isCrouching;
  BYTE2(myOrigin.z) = 0;
  if ( !v13 )
  {
    this->m_lookAheadAngle = myOrigin.x;
LABEL_81:
    z = this->m_goalPosition.z;
    *(_QWORD *)close = *(_QWORD *)&this->m_goalPosition.x;
    *(float *)&close[8] = z;
    if ( HIBYTE(myOrigin.z) == 0 && CCSBot::IsNearJump(this) == 0 )
    {
      v47 = gpGlobals->curtime - this->m_jumpTimestamp;
      if ( v47 > 3.0 || v47 >= 0.89999998 && (this->m_fFlags.m_Value & 1) != 0 )
        CCSBot::FeelerReflexAdjustment(this, goalPosition: (Vector *)close);
    }
    m_pParent = cv_bot_traceview.m_pParent;
    if ( cv_bot_traceview.m_pParent != nullptr )
    {
      if ( cv_bot_traceview.m_pParent->m_Value.m_nValue == 1 )
      {
        if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
        {
LABEL_93:
          CCSBot::DrawPath(this);
          m_pathIndex = this->m_pathIndex;
          myOrigin.y = 0.0;
          m_pathIndex *= 3;
          v50 = *((_DWORD *)&this->m_path[0].pos.x + 2 * m_pathIndex);
          v51 = (char *)&this->m_path[0].pos + 8 * m_pathIndex;
          LODWORD(myOrigin.x) = 255;
          v78.m_Recipients.m_Size = v50;
          v52 = *((int **)v51 + 1);
          *(_DWORD *)&close[32] = 255;
          v78.m_Recipients.m_pElements = v52;
          v53 = *((float *)v51 + 2) + 50.0;
          *(_DWORD *)&close[28] = 1;
          *(float *)&v78.m_bUsingPredictionRules = v53;
          v54 = v53;
          *(_QWORD *)&close[16] = *(_QWORD *)&v78.m_Recipients.m_Size;
          v55 = *(_QWORD *)v51;
          v56 = *((_DWORD *)v51 + 2);
          *(float *)&close[24] = v54;
          *(_QWORD *)&close[4] = v55;
          *(_DWORD *)&close[12] = v56;
          UTIL_DrawBeamPoints(
            vecStart: *(Vector *)&close[4],
            vecEnd: *(Vector *)&close[16],
            iLifetime: 1,
            bRed: 0xFFu,
            bGreen: 0xFFu,
            bBlue: 0);
          v57 = *(_DWORD *)&close[8];
          *(float *)&close[24] = *(float *)&close[8] + 50.0;
          *(_QWORD *)&close[4] = *(_QWORD *)close;
          *(_QWORD *)&close[16] = *(_QWORD *)&close[4];
          *(_DWORD *)&close[12] = v57;
          UTIL_DrawBeamPoints(
            vecStart: *(Vector *)&close[4],
            vecEnd: *(Vector *)&close[16],
            iLifetime: 1,
            bRed: 0xFFu,
            bGreen: 0,
            bBlue: 0xFFu);
          *(_QWORD *)&v78.m_Recipients.m_Size = *(_QWORD *)close;
          *(_DWORD *)&close[28] = 1;
          *(float *)&v78.m_bUsingPredictionRules = *(float *)&close[8] + 50.0;
          *(_QWORD *)&close[16] = *(_QWORD *)close;
          v58 = *(_QWORD *)&close[24];
          *(float *)&close[24] = *(float *)&close[8] + 50.0;
          *(_QWORD *)&close[4] = v58;
          *(_DWORD *)&close[12] = *(_DWORD *)&close[32];
          UTIL_DrawBeamPoints(
            vecStart: *(Vector *)&close[4],
            vecEnd: *(Vector *)&close[16],
            iLifetime: 1,
            bRed: 0xFFu,
            bGreen: 0,
            bBlue: 0xFFu);
          goto LABEL_94;
        }
        m_pParent = cv_bot_traceview.m_pParent;
      }
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue == 10 )
        goto LABEL_93;
    }
LABEL_94:
    if ( CCSBot::IsAttacking(this) || !CCSBot::IsFriendInTheWay(this, goalPos: &this->m_goalPosition) )
    {
      if ( this->m_isWaitingBehindFriend )
      {
        this->m_isWaitingBehindFriend = false;
        CCSBot::ResetStuckMonitor(this);
      }
    }
    else
    {
      p_m_politeTimer = &this->m_politeTimer;
      if ( this->m_isWaitingBehindFriend )
      {
        if ( IntervalTimer::Now(this: (CEffectsServer *)p_m_politeTimer) > this->m_politeTimer.m_timestamp.m_Value )
        {
          this->m_isWaitingBehindFriend = false;
          CCSBot::ResetStuckMonitor(this);
          this->m_isStopping = false;
          this->m_pathLength = 0;
          this->m_pathLadder = nullptr;
        }
      }
      else
      {
        m_profile = this->m_profile;
        this->m_isWaitingBehindFriend = true;
        CountdownTimer::Start(this: p_m_politeTimer, duration: 5.0 - (float)(m_profile->m_aggression * 3.0));
      }
    }
    if ( BYTE2(myOrigin.z) == 0
      && (!this->m_isWaitingBehindFriend
       || IntervalTimer::Now(this: (CEffectsServer *)&this->m_politeTimer) > this->m_politeTimer.m_timestamp.m_Value) )
    {
      CCSBot::MoveTowardsPosition(
        this,
        a2: COERCE_FLOAT(&i),
        a3: (int)&this->m_goalPosition,
        a4: (int)this,
        pos: (const Vector *)close);
      if ( this->m_isStuck )
      {
        v61 = gpGlobals->curtime - this->m_jumpTimestamp;
        if ( v61 > 3.0 || v61 >= 0.89999998 && (this->m_fFlags.m_Value & 1) != 0 )
          CCSBot::Wiggle(this);
      }
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
    if ( (float)(this->m_goalPosition.z - this->m_vecAbsOrigin.z) > 58.0
      && (float)((float)((float)(*(float *)&close[28] - this->m_goalPosition.y)
                       * (float)(*(float *)&close[28] - this->m_goalPosition.y))
               + (float)((float)(*(float *)&close[24] - this->m_goalPosition.x)
                       * (float)(*(float *)&close[24] - this->m_goalPosition.x))) < 5625.0 )
    {
      if ( this->m_pathIndex >= this->m_pathLength - 1 )
        goto LABEL_125;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
      v62 = this->m_pathIndex;
      if ( (float)(this->m_path[v62 + 1].pos.z - this->m_vecAbsOrigin.z) <= 58.0 )
        goto LABEL_132;
      if ( __OFSUB__(v62, v62 + 1) )
      {
LABEL_125:
        CBot<CCSPlayer>::PrintIfWatched(this, format: "I fell off!\n");
        if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this)
          && cv_bot_debug.m_pParent != nullptr
          && cv_bot_debug.m_pParent->m_Value.m_nValue != 0
          && UTIL_GetListenServerHost() != nullptr )
        {
          ListenServerHost = UTIL_GetListenServerHost();
          CSingleUserRecipientFilter::CSingleUserRecipientFilter(
            this: (CSingleUserRecipientFilter *)&v78,
            player: ListenServerHost);
          myOrigin.y = 0.0;
          myOrigin.x = 0.0;
          *(_DWORD *)&close[32] = 0;
          *(_DWORD *)&close[28] = "Bot.FellOff";
          v66 = CBaseEntity::entindex(this: ListenServerHost);
          CBaseEntity::EmitSound(
            filter: &v78,
            iEntIndex: (int)v66,
            soundname: *(const char **)&close[28],
            pOrigin: *(const Vector **)&close[32],
            soundtime: myOrigin.x,
            duration: (float *)LODWORD(myOrigin.y));
          CRecipientFilter::~CRecipientFilter(this: &v78);
        }
LABEL_130:
        v67 = this->m_pathIndex;
        if ( v67 >= this->m_pathLength - 1 )
          CBot<CCSPlayer>::PrintIfWatched(this, format: "Giving up trying to get to end of path\n");
        else
          CBot<CCSPlayer>::PrintIfWatched(
            this,
            format: "Giving up trying to get to area #%d\n",
            this->m_path[v67].area->m_id);
        this->Run(this);
        this->StandUp(this);
        v68 = (unsigned int)this->m_iEFlags >> 11;
        this->m_isStopping = false;
        this->m_pathLength = 0;
        this->m_pathLadder = nullptr;
        this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
        this->m_lookAtDesc = nullptr;
        if ( (v68 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
        NearestNavArea = CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: &this->m_vecAbsOrigin,
                           anyZ: false,
                           maxDist: 500.0,
                           checkLOS: true,
                           checkGround: true);
        if ( NearestNavArea != nullptr )
        {
          m_lastNavArea = this->CBot<CCSPlayer>::CCSPlayer::m_lastNavArea;
          if ( NearestNavArea != m_lastNavArea )
          {
            if ( m_lastNavArea != nullptr )
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                m_pPev -= (int)gpGlobals->pEdicts;
              LODWORD(myOrigin.y) = m_pPev;
              TeamNumber = CBaseEntity::GetTeamNumber(this);
              CNavArea::DecrementPlayerCount(
                this: this->CBot<CCSPlayer>::CCSPlayer::m_lastNavArea,
                teamID: TeamNumber,
                entIndex: SLODWORD(myOrigin.y));
            }
            v73 = CBaseEntity::GetTeamNumber(this) % 2;
            v74 = NearestNavArea->m_playerCount[v73];
            if ( v74 == 0xFF )
              DevMsg(a1: "CNavArea::IncrementPlayerCount: Overflow\n");
            else
              NearestNavArea->m_playerCount[v73] = v74 + 1;
            this->CBot<CCSPlayer>::CCSPlayer::m_lastNavArea = NearestNavArea;
            m_place = NearestNavArea->m_place;
            if ( m_place != 0 )
            {
              v76 = CNavMesh::PlaceToName(this: TheNavMesh, place: m_place);
              if ( v76 != nullptr && *v76 != 0 )
              {
                LODWORD(myOrigin.y) = 18;
                LODWORD(myOrigin.x) = v76;
                v77 = CBasePlayer::NetworkVar_m_szLastPlaceName::GetForModify(this: &this->m_szLastPlaceName);
                V_strncpy(pDest: v77->m_Value, pSrc: (const char *)LODWORD(myOrigin.x), maxLen: SLODWORD(myOrigin.y));
              }
            }
          }
        }
        goto LABEL_150;
      }
      LODWORD(v63) = &this->m_path[v62].pos.z;
      myOrigin.x = v63;
      while ( 1 )
      {
        if ( *(_DWORD *)(LODWORD(v63) - 12) == 4 )
        {
          if ( (this->m_iEFlags & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&i);
            v63 = myOrigin.x;
          }
          if ( (float)(*(float *)LODWORD(v63) - this->m_vecAbsOrigin.z) <= 58.0 )
            break;
        }
        ++v62;
        LODWORD(v63) += 24;
        v64 = this->m_pathIndex + 1;
        myOrigin.x = v63;
        if ( v62 > v64 )
          goto LABEL_125;
      }
    }
LABEL_132:
    if ( (float)(gpGlobals->curtime - this->m_areaEnteredTimestamp) <= 4.0 )
      goto LABEL_133;
    goto LABEL_130;
  }
  v14 = this->m_pathIndex;
  if ( v14 != 0 )
  {
    m_pathLength = this->m_pathLength;
    if ( v14 >= m_pathLength )
    {
      v44 = *(&this->m_avoidTimestamp + 6 * m_pathLength) - *(float *)&close[24];
      v45 = *((float *)&this->m_isStopping + 6 * m_pathLength) - *(float *)&close[28];
      v43 = &this->m_avoidTimestamp + 6 * m_pathLength;
    }
    else
    {
      v16 = *(float *)&close[24];
      v17 = *(float *)&close[28];
      v18 = this->m_path[v14].pos.z - *(float *)&close[32];
      v19 = this->m_path[v14].pos.x - *(float *)&close[24];
      v20 = this->m_path[v14].pos.y - *(float *)&close[28];
      *(float *)&close[12] = v19;
      *(float *)&close[16] = v20;
      *(float *)&close[20] = v18;
      if ( this->m_path[v14].ladder != nullptr
        || CCSBot::IsNearJump(this) != 0
        || (float)((float)(v19 * v19) + (float)(v20 * v20)) >= 250000.0 )
      {
        goto LABEL_80;
      }
      v21 = 0;
      v22 = v14 + 1;
      *(float *)&v21 = fsqrt((float)(v19 * v19) + (float)(v20 * v20));
      *(_OWORD *)&v78.m_Recipients.m_Memory.m_nGrowSize = v21;
      v23 = *(float *)&v21;
      if ( v22 < this->m_pathLength )
      {
        v24 = &this->m_isStopping + 24 * v22;
        while ( 1 )
        {
          v25 = *((float *)v24 + 5) - *((float *)v24 - 1);
          v26 = *((float *)v24 + 6) - *(float *)v24;
          v27 = *((float *)v24 + 7) - *((float *)v24 + 1);
          v28 = 0;
          *(float *)&v28 = fsqrt((float)(v25 * v25) + (float)(v26 * v26));
          *(_OWORD *)&v78.m_Recipients.m_Memory.m_nGrowSize = v28;
          v29 = *(float *)&v28 + v23;
          if ( v29 >= 500.0 )
          {
            v30 = (float)(500.0 - v23) / (float)(*(float *)&v78.m_Recipients.m_Memory.m_nGrowSize + v23);
            if ( v30 > 0.0 )
            {
              if ( v30 < 1.0 )
              {
                v31 = (float)(v25 * v30) + *(&this->m_avoidTimestamp + 6 * v22);
                v34 = v27 * v30;
                y = *((float *)&this->m_isStopping + 6 * v22) + (float)(v26 * v30);
                v33 = *(float *)&(&this->m_stillTimer.__vftable)[6 * v22] + v34;
              }
              else
              {
                v31 = this->m_path[v22].pos.x;
                y = this->m_path[v22].pos.y;
                v33 = this->m_path[v22].pos.z;
              }
            }
            else
            {
              v31 = *(&this->m_avoidTimestamp + 6 * v22);
              y = *((float *)&this->m_isStopping + 6 * v22);
              v33 = *(float *)&(&this->m_stillTimer.__vftable)[6 * v22];
            }
            *(float *)&close[12] = v31 - v16;
            *(float *)&close[16] = y - v17;
            *(float *)&close[20] = v33 - *(float *)&close[32];
            goto LABEL_76;
          }
          if ( *((_DWORD *)v24 + 8) != 0 || (*(_BYTE *)(*((_DWORD *)v24 + 3) + 84) & 0x16) != 0 )
            break;
          ++v22;
          v24 += 24;
          v23 = v29;
          if ( v22 >= this->m_pathLength )
            goto LABEL_76;
        }
        v35 = this->m_path[v22].pos.x;
        v36 = this->m_path[v22].pos.y;
        v37 = this->m_path[v22].pos.z - *(float *)&close[32];
        LODWORD(myOrigin.x) = (char *)this + 24 * v22;
        v38 = *(CNavLadder **)(LODWORD(myOrigin.x) + 7916);
        *(float *)&close[12] = v35 - v16;
        *(float *)&close[16] = v36 - v17;
        *(float *)&close[20] = v37;
        if ( v38 == nullptr )
          goto LABEL_76;
        if ( CNavLadder::IsInUse(this: v38, ignore: this) )
        {
          BYTE2(myOrigin.z) = 1;
          CCSBot::ResetStuckMonitor(this);
          v16 = *(float *)&close[24];
          v17 = *(float *)&close[28];
          if ( (float)((float)((float)(**(float **)(LODWORD(myOrigin.x) + 7916) - v16)
                             * (float)(**(float **)(LODWORD(myOrigin.x) + 7916) - v16))
                     + (float)((float)(*(float *)(*(_DWORD *)(LODWORD(myOrigin.x) + 7916) + 4) - v17)
                             * (float)(*(float *)(*(_DWORD *)(LODWORD(myOrigin.x) + 7916) + 4) - v17))) >= 10000.0 )
            goto LABEL_76;
          CCSBot::MoveAwayFromPosition(
            this,
            a2: COERCE_FLOAT(&i),
            a3: (int)this,
            pos: *(const Vector **)(LODWORD(myOrigin.x) + 7916));
        }
        v16 = *(float *)&close[24];
        v17 = *(float *)&close[28];
      }
LABEL_76:
      v39 = this->m_pathLength;
      if ( v22 != v39 )
        goto LABEL_80;
      v40 = 3 * v39;
      v41 = *(&this->m_avoidTimestamp + 2 * v40);
      v42 = *((float *)&this->m_isStopping + 2 * v40);
      v43 = &this->m_avoidTimestamp + 2 * v40;
      v44 = v41 - v16;
      v45 = v42 - v17;
    }
    *(float *)&close[20] = v43[2] - *(float *)&close[32];
    *(float *)&close[16] = v45;
    *(float *)&close[12] = v44;
  }
  else
  {
    *(float *)&close[12] = this->m_path[1].pos.x;
    *(float *)&close[16] = this->m_path[1].pos.y;
    *(float *)&close[20] = this->m_path[1].pos.z;
  }
LABEL_80:
  this->m_lookAheadAngle = UTIL_VecToYaw(vec: (const Vector *)&close[12]);
  goto LABEL_81;
}

//------------------------------------------------------------------------------
// Address: 0x102C0070
// Name: __CreateCServerGameTagsIServerGameTags_interface_24
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_24()
{
  return &_g_CServerGameTags_singleton_24;
}
