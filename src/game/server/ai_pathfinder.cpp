// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_pathfinder.cpp
// Functions: 110
// ============================================================

#include "game\server\ai_pathfinder.h"

//------------------------------------------------------------------------------
// Address: 0x10073C80
// Name: public: void CAI_Pathfinder::Init(class CAI_Network __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::Init(CAI_Pathfinder *this, CAI_Network *pNetwork)
{
  this->m_pNetwork = pNetwork;
}

//------------------------------------------------------------------------------
// Address: 0x10073C90
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::CreateNodeWaypoint(enum Hull_t,int,int)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::CreateNodeWaypoint(
        CAI_Pathfinder *this,
        Hull_t hullType,
        int nodeID,
        int nodeFlags)
{
  CAI_Network *m_pNetwork; // ecx
  CAI_Node *v5; // esi
  Navigation_t v6; // ebx
  AI_Waypoint_t *v7; // edi
  const Vector *Position; // eax
  float initYaw; // [esp+0h] [ebp-28h]
  Vector v11; // [esp+1Ch] [ebp-Ch] BYREF

  m_pNetwork = this->m_pNetwork;
  if ( nodeID < 0 || nodeID >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v5 = nullptr;
  }
  else
  {
    v5 = m_pNetwork->m_pAInode[nodeID];
  }
  if ( v5->m_eNodeType == NODE_AIR )
  {
    v6 = NAV_FLY;
  }
  else if ( v5->m_eNodeType == NODE_CLIMB )
  {
    v6 = NAV_CLIMB;
  }
  else
  {
    v6 = NAV_GROUND;
  }
  v7 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
  if ( v7 == nullptr )
    return nullptr;
  initYaw = v5->m_flYaw;
  Position = CAI_Node::GetPosition(this: v5, result: &v11, hull: hullType);
  return AI_Waypoint_t::AI_Waypoint_t(
           this: v7,
           initPosition: Position,
           initYaw,
           initNavType: v6,
           initWaypointFlags: nodeFlags | 4,
           initNodeID: nodeID);
}

//------------------------------------------------------------------------------
// Address: 0x10073D30
// Name: int ClosestPointToPosition(class Vector const __near &,class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClosestPointToPosition(const Vector *vecPosition, Vector *vecPoints, int nNumPoints)
{
  float v3; // xmm1_4
  int result; // eax
  int v5; // ecx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float *p_z; // edx
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float *v13; // edx

  v3 = 3.4028235e38;
  result = -1;
  v5 = 0;
  if ( nNumPoints >= 4 )
  {
    x = vecPosition->x;
    y = vecPosition->y;
    z = vecPosition->z;
    p_z = &vecPoints[1].z;
    do
    {
      if ( v3 > (float)((float)((float)((float)(*(p_z - 5) - x) * (float)(*(p_z - 5) - x))
                              + (float)((float)(*(p_z - 4) - y) * (float)(*(p_z - 4) - y)))
                      + (float)((float)(*(p_z - 3) - z) * (float)(*(p_z - 3) - z))) )
      {
        v3 = (float)((float)((float)(*(p_z - 5) - x) * (float)(*(p_z - 5) - x))
                   + (float)((float)(*(p_z - 4) - y) * (float)(*(p_z - 4) - y)))
           + (float)((float)(*(p_z - 3) - z) * (float)(*(p_z - 3) - z));
        result = v5;
      }
      if ( v3 > (float)((float)((float)((float)(*(p_z - 2) - x) * (float)(*(p_z - 2) - x))
                              + (float)((float)(*(p_z - 1) - y) * (float)(*(p_z - 1) - y)))
                      + (float)((float)(*p_z - z) * (float)(*p_z - z))) )
      {
        v3 = (float)((float)((float)(*(p_z - 2) - x) * (float)(*(p_z - 2) - x))
                   + (float)((float)(*(p_z - 1) - y) * (float)(*(p_z - 1) - y)))
           + (float)((float)(*p_z - z) * (float)(*p_z - z));
        result = v5 + 1;
      }
      if ( v3 > (float)((float)((float)((float)(p_z[1] - x) * (float)(p_z[1] - x))
                              + (float)((float)(p_z[2] - y) * (float)(p_z[2] - y)))
                      + (float)((float)(p_z[3] - z) * (float)(p_z[3] - z))) )
      {
        v3 = (float)((float)((float)(p_z[1] - x) * (float)(p_z[1] - x))
                   + (float)((float)(p_z[2] - y) * (float)(p_z[2] - y)))
           + (float)((float)(p_z[3] - z) * (float)(p_z[3] - z));
        result = v5 + 2;
      }
      if ( v3 > (float)((float)((float)((float)(p_z[4] - x) * (float)(p_z[4] - x))
                              + (float)((float)(p_z[5] - y) * (float)(p_z[5] - y)))
                      + (float)((float)(p_z[6] - z) * (float)(p_z[6] - z))) )
      {
        v3 = (float)((float)((float)(p_z[4] - x) * (float)(p_z[4] - x))
                   + (float)((float)(p_z[5] - y) * (float)(p_z[5] - y)))
           + (float)((float)(p_z[6] - z) * (float)(p_z[6] - z));
        result = v5 + 3;
      }
      v5 += 4;
      p_z += 12;
    }
    while ( v5 < nNumPoints - 3 );
  }
  if ( v5 < nNumPoints )
  {
    v13 = &vecPoints[v5].z;
    do
    {
      v10 = vecPosition->x;
      v11 = vecPosition->y;
      v12 = vecPosition->z;
      if ( v3 > (float)((float)((float)((float)(*(v13 - 2) - v10) * (float)(*(v13 - 2) - v10))
                              + (float)((float)(*(v13 - 1) - v11) * (float)(*(v13 - 1) - v11)))
                      + (float)((float)(*v13 - v12) * (float)(*v13 - v12))) )
      {
        v3 = (float)((float)((float)(*(v13 - 2) - v10) * (float)(*(v13 - 2) - v10))
                   + (float)((float)(*(v13 - 1) - v11) * (float)(*(v13 - 1) - v11)))
           + (float)((float)(*v13 - v12) * (float)(*v13 - v12));
        result = v5;
      }
      ++v5;
      v13 += 3;
    }
    while ( v5 < nNumPoints );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10073ED0
// Name: int ShortestDirectionThroughPoints(class Vector const __near &,int,int,class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ShortestDirectionThroughPoints(
        const Vector *vecStart,
        int nStartPoint,
        int nEndPoint,
        Vector *vecPoints,
        int nNumPoints)
{
  int v5; // eax
  int v6; // esi
  Vector *v7; // ebx
  float v8; // xmm4_4
  int v9; // edx
  float v10; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  Vector *v14; // ecx
  int v15; // eax
  Vector *v16; // ecx
  int v17; // eax
  Vector *v18; // ecx
  int v19; // eax
  Vector *v20; // ecx
  float v21; // xmm3_4
  int v22; // eax
  int i; // edx
  Vector *v24; // ecx

  v5 = nStartPoint + 1;
  v6 = nNumPoints - 1;
  if ( nStartPoint + 1 <= nNumPoints - 1 )
  {
    if ( v5 < 0 )
      v5 = nNumPoints - 1;
  }
  else
  {
    v5 = 0;
  }
  v7 = &vecPoints[nStartPoint];
  v8 = (float)((float)((float)(vecStart->y - v7->y) * (float)(vecStart->y - v7->y))
             + (float)((float)(vecStart->x - v7->x) * (float)(vecStart->x - v7->x)))
     + (float)((float)(vecStart->z - v7->z) * (float)(vecStart->z - v7->z));
  v9 = 0;
  v10 = v8;
  if ( nNumPoints < 4 )
  {
LABEL_29:
    while ( v9 < nNumPoints )
    {
      v21 = v7->z - vecPoints[v5].z;
      v10 = v10
          + (float)((float)((float)((float)(v7->y - vecPoints[v5].y) * (float)(v7->y - vecPoints[v5].y))
                          + (float)((float)(v7->x - vecPoints[v5].x) * (float)(v7->x - vecPoints[v5].x)))
                  + (float)(v21 * v21));
      if ( v5 == nEndPoint )
        break;
      if ( ++v5 <= v6 )
      {
        if ( v5 < 0 )
          v5 = nNumPoints - 1;
      }
      else
      {
        v5 = 0;
      }
      ++v9;
    }
  }
  else
  {
    x = v7->x;
    y = v7->y;
    z = v7->z;
    while ( 1 )
    {
      v14 = &vecPoints[v5];
      v10 = v10
          + (float)((float)((float)((float)(y - v14->y) * (float)(y - v14->y))
                          + (float)((float)(x - v14->x) * (float)(x - v14->x)))
                  + (float)((float)(z - v14->z) * (float)(z - v14->z)));
      if ( v5 == nEndPoint )
        break;
      v15 = v5 + 1;
      if ( v15 <= v6 )
      {
        if ( v15 < 0 )
          v15 = nNumPoints - 1;
      }
      else
      {
        v15 = 0;
      }
      v16 = &vecPoints[v15];
      v10 = v10
          + (float)((float)((float)((float)(y - v16->y) * (float)(y - v16->y))
                          + (float)((float)(x - v16->x) * (float)(x - v16->x)))
                  + (float)((float)(z - v16->z) * (float)(z - v16->z)));
      if ( v15 == nEndPoint )
        break;
      v17 = v15 + 1;
      if ( v17 <= v6 )
      {
        if ( v17 < 0 )
          v17 = nNumPoints - 1;
      }
      else
      {
        v17 = 0;
      }
      v18 = &vecPoints[v17];
      v10 = v10
          + (float)((float)((float)((float)(y - v18->y) * (float)(y - v18->y))
                          + (float)((float)(x - v18->x) * (float)(x - v18->x)))
                  + (float)((float)(z - v18->z) * (float)(z - v18->z)));
      if ( v17 == nEndPoint )
        break;
      v19 = v17 + 1;
      if ( v19 <= v6 )
      {
        if ( v19 < 0 )
          v19 = nNumPoints - 1;
      }
      else
      {
        v19 = 0;
      }
      v20 = &vecPoints[v19];
      v10 = v10
          + (float)((float)((float)((float)(y - v20->y) * (float)(y - v20->y))
                          + (float)((float)(x - v20->x) * (float)(x - v20->x)))
                  + (float)((float)(z - v20->z) * (float)(z - v20->z)));
      if ( v19 == nEndPoint )
        break;
      v5 = v19 + 1;
      if ( v5 <= v6 )
      {
        if ( v5 < 0 )
          v5 = nNumPoints - 1;
      }
      else
      {
        v5 = 0;
      }
      v9 += 4;
      if ( v9 >= nNumPoints - 3 )
      {
        v8 = (float)((float)((float)(vecStart->y - v7->y) * (float)(vecStart->y - v7->y))
                   + (float)((float)(vecStart->x - v7->x) * (float)(vecStart->x - v7->x)))
           + (float)((float)(vecStart->z - v7->z) * (float)(vecStart->z - v7->z));
        goto LABEL_29;
      }
    }
    v8 = (float)((float)((float)(vecStart->y - v7->y) * (float)(vecStart->y - v7->y))
               + (float)((float)(vecStart->x - v7->x) * (float)(vecStart->x - v7->x)))
       + (float)((float)(vecStart->z - v7->z) * (float)(vecStart->z - v7->z));
  }
  v22 = nStartPoint - 1;
  if ( nStartPoint - 1 <= v6 )
  {
    if ( v22 < 0 )
      v22 = nNumPoints - 1;
  }
  else
  {
    v22 = 0;
  }
  for ( i = 0; i < nNumPoints; ++i )
  {
    v24 = &vecPoints[v22];
    v8 = v8
       + (float)((float)((float)((float)(v7->y - v24->y) * (float)(v7->y - v24->y))
                       + (float)((float)(v7->x - v24->x) * (float)(v7->x - v24->x)))
               + (float)((float)(v7->z - v24->z) * (float)(v7->z - v24->z)));
    if ( v8 > v10 )
      break;
    if ( v22 == nEndPoint )
      return -1;
    if ( --v22 <= v6 )
    {
      if ( v22 < 0 )
        v22 = nNumPoints - 1;
    }
    else
    {
      v22 = 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100741A0
// Name: public: void CAI_Pathfinder::UnlockRouteNodes(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::UnlockRouteNodes(CAI_Pathfinder *this, AI_Waypoint_t *pPath)
{
  AI_Waypoint_t *i; // esi
  int iNodeID; // eax
  CAI_Network *m_pNetwork; // edx
  CAI_Node *v5; // eax
  float curtime; // xmm0_4

  for ( i = pPath; i != nullptr; i = i->pNext )
  {
    iNodeID = i->iNodeID;
    if ( iNodeID != -1 )
    {
      m_pNetwork = this->m_pNetwork;
      if ( iNodeID < 0 || iNodeID >= m_pNetwork->m_iNumNodes )
      {
        ++`CAI_Network::GetNode'::`8'::warningCount;
      }
      else
      {
        v5 = m_pNetwork->m_pAInode[iNodeID];
        if ( v5 != nullptr )
        {
          curtime = gpGlobals->curtime;
          if ( v5->m_flNextUseTime > curtime )
            v5->m_flNextUseTime = curtime;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074200
// Name: public: void CAI_Pathfinder::CTriDebugOverlay::ClearTriOverlayLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::CTriDebugOverlay::ClearTriOverlayLines(CAI_Pathfinder::CTriDebugOverlay *this)
{
  int i; // eax
  OverlayLine_t *v2; // esi

  if ( this->m_debugTriOverlayLine != nullptr )
  {
    for ( i = 3; i < 53; i += 5 )
    {
      this->m_debugTriOverlayLine[i - 3]->draw = false;
      this->m_debugTriOverlayLine[i - 2]->draw = false;
      this->m_debugTriOverlayLine[i - 1]->draw = false;
      this->m_debugTriOverlayLine[i]->draw = false;
      v2 = this->m_debugTriOverlayLine[i + 1];
      v2->draw = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074250
// Name: public: void CAI_Pathfinder::CTriDebugOverlay::FadeTriOverlayLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::CTriDebugOverlay::FadeTriOverlayLines(CAI_Pathfinder::CTriDebugOverlay *this)
{
  int i; // eax
  OverlayLine_t *v2; // edx

  if ( this->m_debugTriOverlayLine != nullptr )
  {
    for ( i = 0; i < 50; ++i )
    {
      this->m_debugTriOverlayLine[i]->r = (int)((double)this->m_debugTriOverlayLine[i]->r * 0.5);
      this->m_debugTriOverlayLine[i]->g = (int)((double)this->m_debugTriOverlayLine[i]->g * 0.5);
      v2 = this->m_debugTriOverlayLine[i];
      v2->b = (int)((double)v2->b * 0.5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100742C0
// Name: public: int CAI_Pathfinder::NearestNodeToNPC(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CAI_Pathfinder::NearestNodeToNPC@<eax>(CAI_Pathfinder *this@<ecx>, int a2@<ebp>)
{
  CAI_BaseNPC *m_pOuter; // edi

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  return CAI_Network::NearestNodeToPoint(
           this: this->m_pNetwork,
           pNPC: this->m_pOuter,
           vecOrigin: &m_pOuter->m_vecAbsOrigin,
           bCheckVisibility: true,
           pFilter: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10074300
// Name: public: int CAI_Pathfinder::NearestNodeToPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Pathfinder::NearestNodeToPoint(CAI_Pathfinder *this, const Vector *vecOrigin)
{
  return CAI_Network::NearestNodeToPoint(
           this: this->m_pNetwork,
           pNPC: this->m_pOuter,
           vecOrigin,
           bCheckVisibility: true,
           pFilter: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10074320
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildSimpleRoute(enum Navigation_t,class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildSimpleRoute(
        CAI_Pathfinder *this,
        Navigation_t navType,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pTarget,
        int endFlags,
        int nodeID,
        int nodeTargetType,
        float flYaw)
{
  CAI_Network *m_pNetwork; // eax
  CAI_Node *v11; // eax
  AI_Waypoint_t *v12; // eax
  AIMoveTrace_t moveTrace; // [esp+1Ch] [ebp-38h] BYREF
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  if ( (nodeID == -1
     || ((m_pNetwork = this->m_pNetwork, nodeID < 0) || nodeID >= m_pNetwork->m_iNumNodes
       ? (++`CAI_Network::GetNode'::`8'::warningCount, v11 = nullptr)
       : (v11 = m_pNetwork->m_pAInode[nodeID]),
         v11->m_eNodeType == nodeTargetType))
    && (memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace)),
        CAI_MoveProbe::MoveLimit(
          this: this->m_pOuter->m_pMoveProbe,
          a2: (int)&savedregs,
          navType,
          vecStart: vStart,
          vecEnd: vEnd,
          collisionMask: this->m_pOuter->m_nAITraceMask,
          pTarget,
          pctToCheckStandPositions: 100.0,
          flags: 0,
          pTrace: &moveTrace),
        moveTrace.fStatus >= AIMR_OK)
    && (v12 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u)) != nullptr )
  {
    return AI_Waypoint_t::AI_Waypoint_t(
             this: v12,
             initPosition: vEnd,
             initYaw: flYaw,
             initNavType: navType,
             initWaypointFlags: endFlags,
             initNodeID: nodeID);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100743F0
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildRouteThroughPoints(class Vector __near *,int,int,int,int,enum Navigation_t,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildRouteThroughPoints(
        CAI_Pathfinder *this,
        Vector *vecPoints,
        int nNumPoints,
        int nDirection,
        int nStartIndex,
        int nEndIndex,
        Navigation_t navType,
        CBaseEntity *pTarget)
{
  AI_Waypoint_t *v8; // ebx
  CAI_BaseNPC *m_pOuter; // edi
  unsigned int m_nAITraceMask; // edx
  unsigned int v13; // eax
  int v14; // edi
  const Vector *v15; // esi
  AI_Waypoint_t *v16; // eax
  AI_Waypoint_t *v17; // eax
  AI_Waypoint_t *pNext; // ecx
  AI_Waypoint_t *pPrev; // ecx
  AI_Waypoint_t *v21; // eax
  AI_Waypoint_t *v22; // eax
  AI_Waypoint_t *v23; // ecx
  AI_Waypoint_t *v24; // eax
  AIMoveTrace_t endTrace; // [esp+1Ch] [ebp-48h] BYREF
  CAI_Pathfinder *v26; // [esp+54h] [ebp-10h]
  AI_Waypoint_t *pFirstRoute; // [esp+5Ch] [ebp-8h]
  CAI_MoveProbe *pMoveProbe; // [esp+60h] [ebp-4h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  unsigned int nRunAwayCount; // [esp+78h] [ebp+14h]
  int nRunAwayCounta; // [esp+78h] [ebp+14h]

  v8 = nullptr;
  v26 = this;
  memset(dst: (int)&endTrace, value: nullptr, count: sizeof(endTrace));
  m_pOuter = this->m_pOuter;
  endTrace.fStatus = AIMR_OK;
  m_nAITraceMask = m_pOuter->m_nAITraceMask;
  v13 = (unsigned int)m_pOuter->m_iEFlags >> 11;
  pMoveProbe = m_pOuter->m_pMoveProbe;
  pFirstRoute = nullptr;
  nRunAwayCount = m_nAITraceMask;
  if ( (v13 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
  CAI_MoveProbe::MoveLimit(
    this: pMoveProbe,
    a2: (int)&savedregs,
    navType,
    vecStart: &m_pOuter->m_vecAbsOrigin,
    vecEnd: &vecPoints[nStartIndex],
    collisionMask: nRunAwayCount,
    pTarget,
    pctToCheckStandPositions: 100.0,
    flags: 0,
    pTrace: &endTrace);
  if ( endTrace.fStatus < AIMR_OK )
    return nullptr;
  nRunAwayCounta = 0;
  if ( nNumPoints > 0 )
  {
    while ( 1 )
    {
      ++nRunAwayCounta;
      v14 = nStartIndex + nDirection;
      if ( nStartIndex + nDirection <= nNumPoints - 1 )
      {
        if ( v14 < 0 )
          v14 = nNumPoints - 1;
      }
      else
      {
        v14 = 0;
      }
      v15 = &vecPoints[nStartIndex];
      CAI_MoveProbe::MoveLimit(
        this: pMoveProbe,
        a2: (int)&savedregs,
        navType,
        vecStart: v15,
        vecEnd: &vecPoints[v14],
        collisionMask: v26->m_pOuter->m_nAITraceMask,
        pTarget,
        pctToCheckStandPositions: 100.0,
        flags: 0,
        pTrace: &endTrace);
      if ( endTrace.fStatus < AIMR_OK )
        break;
      v16 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
      if ( v8 != nullptr )
      {
        if ( v16 != nullptr )
          v17 = AI_Waypoint_t::AI_Waypoint_t(
                  this: v16,
                  initPosition: v15,
                  initYaw: 0.0,
                  initNavType: navType,
                  initWaypointFlags: 33,
                  initNodeID: -1);
        else
          v17 = nullptr;
        pNext = v8->pNext;
        if ( pNext != nullptr )
          pNext->pPrev = nullptr;
        v8->pNext = v17;
        if ( v17 != nullptr )
        {
          pPrev = v17->pPrev;
          if ( pPrev != nullptr )
            pPrev->pNext = nullptr;
          v8->pNext->pPrev = v8;
        }
        v8 = v17;
      }
      else if ( v16 != nullptr )
      {
        v8 = AI_Waypoint_t::AI_Waypoint_t(
               this: v16,
               initPosition: v15,
               initYaw: 0.0,
               initNavType: navType,
               initWaypointFlags: 1,
               initNodeID: -1);
        pFirstRoute = v8;
      }
      else
      {
        v8 = nullptr;
        pFirstRoute = nullptr;
      }
      if ( v14 == nEndIndex )
      {
        v21 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
        if ( v21 != nullptr )
          v22 = AI_Waypoint_t::AI_Waypoint_t(
                  this: v21,
                  initPosition: &vecPoints[nEndIndex],
                  initYaw: 0.0,
                  initNavType: navType,
                  initWaypointFlags: 1,
                  initNodeID: -1);
        else
          v22 = nullptr;
        v23 = v8->pNext;
        if ( v23 != nullptr )
          v23->pPrev = nullptr;
        v8->pNext = v22;
        if ( v22 != nullptr )
        {
          v24 = v22->pPrev;
          if ( v24 != nullptr )
            v24->pNext = nullptr;
          v8->pNext->pPrev = v8;
        }
        return pFirstRoute;
      }
      nStartIndex = v14;
      if ( nRunAwayCounta >= nNumPoints )
        return pFirstRoute;
    }
    if ( v8 != nullptr )
      DeleteAll(pWaypointList: v8);
    return nullptr;
  }
  return pFirstRoute;
}

//------------------------------------------------------------------------------
// Address: 0x10074620
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::BuildRadialRoute(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildRadialRoute(
        CAI_Pathfinder *this,
        const Vector *vStartPos,
        const Vector *vCenterPos,
        const Vector *vGoalPos,
        float flRadius,
        float flArc,
        float flStepDist,
        bool bClockwise,
        float goalTolerance,
        bool bAirRoute)
{
  CAI_BaseNPC *m_pOuter; // eax
  float v12; // xmm0_4
  double v14; // st7
  float z; // edx
  int v16; // edi
  __m128 v17; // xmm0
  double v19; // xmm0_8
  AI_Waypoint_t *(__thiscall *BuildLocalRoute)(CAI_Pathfinder *, const Vector *, const Vector *, const CBaseEntity *, int, int, int, float); // eax
  double v21; // xmm0_8
  AI_Waypoint_t *v22; // eax
  AI_Waypoint_t *v23; // eax
  Vector vStartDir; // [esp+10h] [ebp-24h] BYREF
  Vector vLastPos; // [esp+1Ch] [ebp-18h] BYREF
  Vector vNextPos; // [esp+28h] [ebp-Ch] BYREF
  float flEndAngle; // [esp+3Ch] [ebp+8h]
  AI_Waypoint_t *pHeadRoute; // [esp+4Ch] [ebp+18h]
  float flAngleStep; // [esp+50h] [ebp+1Ch]
  float flCurAngle; // [esp+5Ch] [ebp+28h]

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  __libm_sse2_atan();
  v12 = (float)((float)(flStepDist * 0.5) / flRadius) * 2.0;
  flAngleStep = v12;
  if ( bClockwise )
  {
    flArc = flArc * -1.0;
    flAngleStep = v12 * -1.0;
  }
  vStartDir.x = vStartPos->x - vCenterPos->x;
  vStartDir.y = vStartPos->y - vCenterPos->y;
  vStartDir.z = vStartPos->z - vCenterPos->z;
  VectorNormalize(vec: &vStartDir);
  v14 = UTIL_VecToYaw(vec: &vStartDir) * 0.017453292;
  z = vStartPos->z;
  flEndAngle = 0.017453292 * flArc + v14;
  *(_QWORD *)&vLastPos.x = *(_QWORD *)&vStartPos->x;
  pHeadRoute = nullptr;
  vLastPos.z = z;
  v16 = bAirRoute ? 4 : 1;
  flCurAngle = v14 + flAngleStep;
  v17 = (__m128)LODWORD(flCurAngle);
  while ( bClockwise ? flEndAngle < v17.m128_f32[0] : v17.m128_f32[0] < flEndAngle )
  {
    vNextPos = *vCenterPos;
    __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v17));
    *(float *)&v19 = v19;
    vNextPos.x = (float)(*(float *)&v19 * flRadius) + vNextPos.x;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(flCurAngle)));
    BuildLocalRoute = this->BuildLocalRoute;
    *(float *)&v21 = v21;
    vNextPos.y = (float)(*(float *)&v21 * flRadius) + vNextPos.y;
    v22 = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, Vector *, Vector *, _DWORD, _DWORD, int, int, _DWORD))BuildLocalRoute)(
                             a1: this,
                             a2: &vLastPos,
                             a3: &vNextPos,
                             a4: 0,
                             a5: 0,
                             a6: -1,
                             a7: v16,
                             a8: LODWORD(goalTolerance));
    if ( v22 == nullptr )
      return nullptr;
    v22->m_fWaypointFlags |= 0x20u;
    if ( pHeadRoute != nullptr )
      AddWaypointLists(oldRoute: pHeadRoute, addRoute: v22);
    else
      pHeadRoute = v22;
    vLastPos = vNextPos;
    v17 = (__m128)LODWORD(flCurAngle);
    v17.m128_f32[0] = flCurAngle + flAngleStep;
    flCurAngle = flCurAngle + flAngleStep;
  }
  if ( pHeadRoute != nullptr )
  {
    v23 = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, Vector *, const Vector *, _DWORD, _DWORD, int, int, _DWORD))this->BuildLocalRoute)(
                             a1: this,
                             a2: &vLastPos,
                             a3: vGoalPos,
                             a4: 0,
                             a5: 0,
                             a6: -1,
                             a7: v16,
                             a8: LODWORD(goalTolerance));
    if ( v23 != nullptr )
    {
      v23->m_fWaypointFlags = v23->m_fWaypointFlags & 0xFFFFFFD7 | 8;
      AddWaypointLists(oldRoute: pHeadRoute, addRoute: v23);
      return pHeadRoute;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10074860
// Name: public: virtual bool CPathfindNearestNodeFilter::ShouldContinue(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPathfindNearestNodeFilter::ShouldContinue(CPathfindNearestNodeFilter *this)
{
  return this->m_pRoute == nullptr && this->m_nTries < 4;
}

//------------------------------------------------------------------------------
// Address: 0x10074880
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildNearestNodeRoute(class Vector const __near &,bool,int,float,int __near *)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildNearestNodeRoute(
        CAI_Pathfinder *this,
        const Vector *vGoal,
        bool bToNode,
        char buildFlags,
        float goalTolerance,
        int *pNearestNode)
{
  __int64 v6; // xmm0_8
  CAI_BaseNPC *m_pOuter; // edx
  CAI_Network *m_pNetwork; // ecx
  CPathfindNearestNodeFilter filter; // [esp+0h] [ebp-2Ch] BYREF

  v6 = *(_QWORD *)&vGoal->x;
  filter.m_vGoal.z = vGoal->z;
  filter.m_bToNode = bToNode;
  filter.m_nTries = 0;
  filter.m_pRoute = nullptr;
  filter.m_moveTypes = buildFlags & 0x1F;
  m_pOuter = this->m_pOuter;
  filter.m_pPathfinder = this;
  m_pNetwork = this->m_pNetwork;
  *(_QWORD *)&filter.m_vGoal.x = v6;
  filter.__vftable = (CPathfindNearestNodeFilter_vtbl *)&CPathfindNearestNodeFilter::`vftable';
  filter.m_goalTolerance = goalTolerance;
  filter.m_bAvoidObstacles = true;
  *pNearestNode = CAI_Network::NearestNodeToPoint(
                    this: m_pNetwork,
                    pNPC: m_pOuter,
                    vecOrigin: vGoal,
                    bCheckVisibility: true,
                    pFilter: &filter);
  return filter.m_pRoute;
}

//------------------------------------------------------------------------------
// Address: 0x100748F0
// Name: public: void CAI_Pathfinder::CTriDebugOverlay::Draw(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::CTriDebugOverlay::Draw(
        CAI_Pathfinder::CTriDebugOverlay *this,
        __int16 npcDebugOverlays)
{
  int i; // esi
  OverlayLine_t *v4; // ecx

  if ( this->m_debugTriOverlayLine != nullptr )
  {
    if ( npcDebugOverlays < 0 )
    {
      for ( i = 0; i < 50; ++i )
      {
        v4 = this->m_debugTriOverlayLine[i];
        if ( v4->draw )
          NDebugOverlay::Line(
            origin: &this->m_debugTriOverlayLine[i]->origin,
            target: &this->m_debugTriOverlayLine[i]->dest,
            r: this->m_debugTriOverlayLine[i]->r,
            g: this->m_debugTriOverlayLine[i]->g,
            b: v4->b,
            noDepthTest: v4->noDepthTest,
            duration: 0.0);
      }
    }
    else
    {
      CAI_Pathfinder::CTriDebugOverlay::ClearTriOverlayLines(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10074960
// Name: private: void CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(class Vector const __near &,class Vector const __near &,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
        CAI_Pathfinder::CTriDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        int r,
        int g,
        int b,
        bool noDepthTest)
{
  int i; // edi
  int v9; // eax
  OverlayLine_t *v10; // ecx
  int v11; // eax

  if ( this->m_debugTriOverlayLine == nullptr )
  {
    this->m_debugTriOverlayLine = (OverlayLine_t **)operator new(nSize: 0xC8u);
    for ( i = 0; i < 50; ++i )
      this->m_debugTriOverlayLine[i] = (OverlayLine_t *)operator new(nSize: 0x28u);
  }
  v9 = overCounter;
  if ( overCounter >= 50 )
    v9 = 0;
  v10 = this->m_debugTriOverlayLine[v9];
  v11 = v9 + 1;
  v10->origin.x = origin->x;
  overCounter = v11;
  v10->origin.y = origin->y;
  v10->origin.z = origin->z;
  this->m_debugTriOverlayLine[v11 - 1]->dest = *dest;
  this->m_debugTriOverlayLine[v11 - 1]->r = r;
  this->m_debugTriOverlayLine[v11 - 1]->g = g;
  this->m_debugTriOverlayLine[v11 - 1]->b = b;
  this->m_debugTriOverlayLine[v11 - 1]->noDepthTest = noDepthTest;
  this->m_debugTriOverlayLine[v11 - 1]->draw = true;
}

//------------------------------------------------------------------------------
// Address: 0x10074A20
// Name: private: enum Navigation_t CAI_Pathfinder::ComputeWaypointType(bool __near *,class CAI_Node __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
Navigation_t __thiscall CAI_Pathfinder::ComputeWaypointType(
        CAI_Pathfinder *this,
        bool *pWantsPreciseMovement,
        CAI_Node **ppNodes,
        int parentID,
        int destID)
{
  CAI_Node *v5; // ecx
  int m_Size; // edx
  int v7; // esi
  CAI_Link **m_pMemory; // eax
  CAI_Link *v9; // edi
  __int16 m_iSrcID; // cx
  CAI_BaseNPC *m_pOuter; // ecx
  int v12; // ebx
  int v13; // esi
  unsigned int v14; // esi
  Navigation_t result; // eax
  CAI_Node *v16; // eax
  int v17; // ebx
  int v18; // esi
  CAI_Link **i; // edi
  __int16 v20; // ax
  int v21; // esi
  Navigation_t navType; // [esp+Ch] [ebp-8h]
  CAI_Node *pNode; // [esp+20h] [ebp+Ch]

  *pWantsPreciseMovement = false;
  v5 = ppNodes[parentID];
  m_Size = v5->m_Links.m_Size;
  v7 = 0;
  navType = NAV_NONE;
  if ( m_Size <= 0 )
    goto LABEL_24;
  m_pMemory = v5->m_Links.m_Memory.m_pMemory;
  while ( 1 )
  {
    v9 = *m_pMemory;
    m_iSrcID = (*m_pMemory)->m_iSrcID;
    if ( parentID == m_iSrcID )
      m_iSrcID = v9->m_iDestID;
    if ( m_iSrcID == destID )
      break;
    ++v7;
    ++m_pMemory;
    if ( v7 >= m_Size )
      goto LABEL_24;
  }
  m_pOuter = this->m_pOuter;
  v12 = v9->m_iAcceptedMoveTypes[m_pOuter->m_eHull];
  v13 = v12 & m_pOuter->CapabilitiesGet(this: m_pOuter);
  if ( v13 == 0 && v12 == 2 )
  {
    ppNodes[destID]->m_flNextUseTime = gpGlobals->curtime + 0.30000001;
    v13 = 2;
  }
  *pWantsPreciseMovement = (v9->m_LinkInfo & 4) != 0;
  if ( (((v13 & 0x3F) - 1) & v13 & 0x3F) == 0 )
  {
    switch ( v13 )
    {
      case 1:
        goto $LN66;
      case 2:
        goto $LN63;
      case 4:
        goto $LN65_1;
      case 8:
        goto $LN64_1;
      case 16:
        goto $LN62;
      default:
        goto LABEL_22;
    }
  }
  v14 = (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x10) != 0 ? v13 & 0xFFFFFFC0 | 0x10 : v13 & 0xFFFFFFEF;
  switch ( v14 )
  {
    case 1u:
$LN66:
      result = NAV_GROUND;
      break;
    case 2u:
$LN63:
      result = NAV_JUMP;
      break;
    case 4u:
$LN65_1:
      result = NAV_FLY;
      break;
    case 8u:
$LN64_1:
      result = NAV_CLIMB;
      break;
    case 0x10u:
$LN62:
      result = NAV_CRAWL;
      break;
    default:
LABEL_22:
      result = NAV_NONE;
      break;
  }
  navType = result;
  if ( result == NAV_NONE )
  {
LABEL_24:
    v16 = ppNodes[destID];
    v17 = v16->m_Links.m_Size;
    v18 = 0;
    pNode = v16;
    if ( v17 <= 0 )
    {
      return navType;
    }
    else
    {
      for ( i = v16->m_Links.m_Memory.m_pMemory; ; ++i )
      {
        v20 = parentID == (*i)->m_iSrcID ? (*i)->m_iDestID : (*i)->m_iSrcID;
        if ( v20 == destID )
          break;
        if ( ++v18 >= v17 )
          return navType;
      }
      switch ( pNode->m_Links.m_Memory.m_pMemory[v18]->m_iAcceptedMoveTypes[this->m_pOuter->m_eHull]
             & (unsigned __int8)this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) )
      {
        case 1:
          v21 = 0;
          break;
        case 2:
          v21 = 1;
          break;
        case 4:
          v21 = 2;
          break;
        case 8:
          v21 = 3;
          break;
        case 16:
          v21 = 4;
          break;
        default:
          v21 = -1;
          break;
      }
      DevMsg(a1: "Note: Strange link found between nodes in AI node graph\n");
      return v21;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10074CA0
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::MakeRouteFromParents(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::MakeRouteFromParents(CAI_Pathfinder *this, int *parentArray, int endID)
{
  CAI_Node **m_pAInode; // eax
  int v4; // esi
  AI_Waypoint_t *v5; // edx
  int v6; // edi
  AI_Waypoint_t *result; // eax
  int iNodeID; // eax
  int v9; // edi
  AI_Waypoint_t *v10; // ebx
  CAI_Node *v11; // ecx
  const Vector *Position; // eax
  AI_Waypoint_t *pNext; // ecx
  AI_Waypoint_t *v14; // ecx
  AI_Waypoint_t *pPrev; // ecx
  float initYaw; // [esp+0h] [ebp-40h]
  Navigation_t v17; // [esp+4h] [ebp-3Ch]
  Vector v18; // [esp+1Ch] [ebp-24h] BYREF
  int prevID; // [esp+28h] [ebp-18h]
  Navigation_t waypointType; // [esp+2Ch] [ebp-14h]
  CAI_Pathfinder *v21; // [esp+30h] [ebp-10h]
  CAI_Node **pAInode; // [esp+34h] [ebp-Ch]
  int nNextWaypointFlags; // [esp+38h] [ebp-8h]
  AI_Waypoint_t *pOldWaypoint; // [esp+3Ch] [ebp-4h]

  m_pAInode = this->m_pNetwork->m_pAInode;
  v4 = endID;
  v5 = nullptr;
  v6 = 0;
  v21 = this;
  pOldWaypoint = nullptr;
  pAInode = m_pAInode;
  if ( endID == -1 )
    return nullptr;
  while ( 1 )
  {
    iNodeID = parentArray[v4];
    prevID = iNodeID;
    if ( iNodeID == -1 )
    {
      if ( v5 == nullptr )
        break;
      iNodeID = v5->iNodeID;
    }
    v9 = v6 | 4;
    waypointType = CAI_Pathfinder::ComputeWaypointType(
                     this,
                     pWantsPreciseMovement: (bool *)&endID + 3,
                     ppNodes: pAInode,
                     parentID: v4,
                     destID: iNodeID);
    if ( HIBYTE(endID) != 0 )
    {
      v9 |= 0x60u;
      nNextWaypointFlags = 96;
    }
    else
    {
      nNextWaypointFlags = 0;
    }
    v10 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
    if ( v10 != nullptr )
    {
      v11 = pAInode[v4];
      v17 = waypointType;
      initYaw = v11->m_flYaw;
      Position = CAI_Node::GetPosition(this: v11, result: &v18, hull: v21->m_pOuter->m_eHull);
      result = AI_Waypoint_t::AI_Waypoint_t(
                 this: v10,
                 initPosition: Position,
                 initYaw,
                 initNavType: v17,
                 initWaypointFlags: v9,
                 initNodeID: v4);
    }
    else
    {
      result = nullptr;
    }
    pNext = result->pNext;
    if ( pNext != nullptr )
      pNext->pPrev = nullptr;
    v14 = pOldWaypoint;
    result->pNext = pOldWaypoint;
    if ( v14 != nullptr )
    {
      pPrev = v14->pPrev;
      if ( pPrev != nullptr )
        pPrev->pNext = nullptr;
      result->pNext->pPrev = result;
    }
    v4 = prevID;
    pOldWaypoint = result;
    v5 = result;
    if ( prevID == -1 )
      return result;
    this = v21;
    v6 = nNextWaypointFlags;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10074DC0
// Name: NPCBuildFlags
// Source: json
//------------------------------------------------------------------------------
int __usercall NPCBuildFlags@<eax>(CAI_BaseNPC *pNPC@<esi>, const Vector *vecOrigin@<ecx>)
{
  int v3; // edi

  if ( vecOrigin->x == pNPC->m_vecOrigin.m_Value.x
    && vecOrigin->y == pNPC->m_vecOrigin.m_Value.y
    && vecOrigin->z == pNPC->m_vecOrigin.m_Value.z
    && CAI_BaseNPC::GetNavType(this: pNPC) == NAV_CLIMB )
  {
    return 8;
  }
  if ( (pNPC->CapabilitiesGet(this: pNPC) & 4) != 0 )
    return 36;
  if ( (pNPC->CapabilitiesGet(this: pNPC) & 1) == 0 )
    return 0;
  v3 = 33;
  if ( (pNPC->CapabilitiesGet(this: pNPC) & 2) != 0 )
    v3 = 35;
  if ( (pNPC->CapabilitiesGet(this: pNPC) & 0x10) != 0 )
    return v3 | 0x10;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10074E70
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::RouteToNode(class Vector const __near &,int,int,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::RouteToNode(
        CAI_Pathfinder *this,
        const Vector *vecOrigin,
        int buildFlags,
        int nodeID,
        float goalTolerance)
{
  int v6; // esi
  Hull_t m_eHull; // edx
  CAI_Network *m_pNetwork; // eax
  unsigned int v9; // esi
  CAI_Node *v10; // ecx
  AI_Waypoint_t *result; // eax
  Vector v12; // [esp+10h] [ebp-Ch] BYREF

  v6 = buildFlags | NPCBuildFlags(pNPC: this->m_pOuter, vecOrigin);
  m_eHull = this->m_pOuter->m_eHull;
  m_pNetwork = this->m_pNetwork;
  v9 = v6 & 0xFFFFFDFF;
  if ( nodeID < 0 || nodeID >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    v10 = nullptr;
  }
  else
  {
    v10 = m_pNetwork->m_pAInode[nodeID];
  }
  CAI_Node::GetPosition(this: v10, result: &v12, hull: m_eHull);
  if ( v12.x == vecOrigin->x && v12.y == vecOrigin->y && v12.z == vecOrigin->z )
    return CAI_Pathfinder::CreateNodeWaypoint(this, hullType: this->m_pOuter->m_eHull, nodeID, nodeFlags: 8);
  result = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, const Vector *, Vector *, _DWORD, int, int, unsigned int, _DWORD))this->BuildLocalRoute)(
                              a1: this,
                              a2: vecOrigin,
                              a3: &v12,
                              a4: 0,
                              a5: 4,
                              a6: nodeID,
                              a7: v9,
                              a8: LODWORD(goalTolerance));
  if ( result != nullptr )
    result->iNodeID = nodeID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10074F40
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::RouteFromNode(class Vector const __near &,int,int,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::RouteFromNode(
        CAI_Pathfinder *this,
        CAI_Node *vecOrigin,
        int buildFlags,
        int nodeID,
        float goalTolerance)
{
  CAI_Network *m_pNetwork; // eax
  int v9; // esi
  AI_Waypoint_t *v10; // eax
  Vector v11; // [esp+38h] [ebp-Ch] BYREF
  CAI_Node *pNode; // [esp+4Ch] [ebp+8h]
  int buildFlagsa; // [esp+50h] [ebp+Ch]

  buildFlagsa = NPCBuildFlags(pNPC: this->m_pOuter, (const Vector *)vecOrigin) | 0x200 | buildFlags;
  m_pNetwork = this->m_pNetwork;
  if ( nodeID < 0 || nodeID >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    pNode = nullptr;
  }
  else
  {
    pNode = m_pNetwork->m_pAInode[nodeID];
  }
  CAI_Node::GetPosition(this: pNode, result: &v11, hull: this->m_pOuter->m_eHull);
  if ( v11.x == *(float *)&vecOrigin->m_iID && v11.y == vecOrigin->m_vOrigin.x && v11.z == vecOrigin->m_vOrigin.y )
    return CAI_Pathfinder::CreateNodeWaypoint(this, hullType: this->m_pOuter->m_eHull, nodeID, nodeFlags: 8);
  v9 = ((int (__thiscall *)(CAI_Pathfinder *, Vector *, CAI_Node *, _DWORD, int, int, int, _DWORD))this->BuildLocalRoute)(
         a1: this,
         a2: &v11,
         a3: vecOrigin,
         a4: 0,
         a5: 8,
         a6: -1,
         a7: buildFlagsa,
         a8: LODWORD(goalTolerance));
  if ( v9 == 0
    && pNode->m_eNodeType == NODE_CLIMB
    && (float)((float)((float)(*(float *)&vecOrigin->m_iID - v11.x) * (float)(*(float *)&vecOrigin->m_iID - v11.x))
             + (float)((float)(vecOrigin->m_vOrigin.x - v11.y) * (float)(vecOrigin->m_vOrigin.x - v11.y))) < 1024.0
    && CAI_MoveProbe::CheckStandPosition(
         this: this->m_pOuter->m_pMoveProbe,
         vecStart: &v11,
         collisionMask: this->m_pOuter->m_nAITraceMask & 0xFDFFFFFF) )
  {
    v10 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
    if ( v10 != nullptr )
      return AI_Waypoint_t::AI_Waypoint_t(
               this: v10,
               initPosition: (const Vector *)vecOrigin,
               initYaw: 0.0,
               initNavType: NAV_GROUND,
               initWaypointFlags: 8,
               initNodeID: nodeID);
    return nullptr;
  }
  return (AI_Waypoint_t *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x100750B0
// Name: private: bool CAI_Pathfinder::CanGiveWay(class Vector const __near &,class Vector const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Pathfinder::CanGiveWay(
        CAI_Pathfinder *this,
        const Vector *vStart,
        const Vector *vEnd,
        CBaseEntity *pBlocker)
{
  CAI_BaseNPC *v5; // eax
  int v6; // eax
  bool result; // al

  v5 = pBlocker->MyNPCPointer(this: pBlocker);
  result = false;
  if ( v5 != nullptr && v5->m_Network.m_pPev != nullptr )
  {
    v6 = v5->IRelationType(this: v5, a2: this->m_pOuter);
    if ( v6 == 3 || v6 == 4 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075100
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::BuildOBBAvoidanceRoute(class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,class CBaseEntity const __near *,enum Navigation_t)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildOBBAvoidanceRoute(
        CAI_Pathfinder *this,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pObstruction,
        CBaseEntity *pTarget,
        Navigation_t navType)
{
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // esi
  Vector *v8; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  float v10; // xmm1_4
  int v11; // edi
  int v12; // ebx
  int v13; // esi
  AI_Waypoint_t *result; // eax
  int m_eHull; // [esp-4h] [ebp-58h]
  Vector vecPoints[4]; // [esp+Ch] [ebp-48h] BYREF
  Vector vecSize; // [esp+3Ch] [ebp-18h] BYREF
  float v18; // [esp+48h] [ebp-Ch]
  float flWidthPercY; // [esp+4Ch] [ebp-8h]
  CAI_Pathfinder *v20; // [esp+50h] [ebp-4h]
  float flWidthPercX; // [esp+64h] [ebp+10h]
  float flWidthPercXa; // [esp+64h] [ebp+10h]
  float flWidthPercXb; // [esp+64h] [ebp+10h]
  float flWidthPercXc; // [esp+64h] [ebp+10h]

  p_m_Collision = &pObstruction->m_Collision;
  v20 = this;
  if ( CCollisionProperty::IsPointInBounds(this: &pObstruction->m_Collision, vecWorldPt: vEnd) )
    return nullptr;
  v8 = AllocTempVector();
  v8->x = pObstruction->m_Collision.m_vecMaxs.m_Value.x - pObstruction->m_Collision.m_vecMins.m_Value.x;
  v8->y = pObstruction->m_Collision.m_vecMaxs.m_Value.y - pObstruction->m_Collision.m_vecMins.m_Value.y;
  v8->z = pObstruction->m_Collision.m_vecMaxs.m_Value.z - pObstruction->m_Collision.m_vecMins.m_Value.z;
  m_pOuter = this->m_pOuter;
  vecSize.z = v8->z;
  m_eHull = m_pOuter->m_eHull;
  *(_QWORD *)&vecSize.x = *(_QWORD *)&v8->x;
  flWidthPercX = NAI_Hull::Width(id: m_eHull) * 0.5;
  v10 = flWidthPercX / vecSize.y;
  flWidthPercXa = flWidthPercX / vecSize.x;
  LODWORD(v18) = LODWORD(flWidthPercXa) ^ _mask__NegFloat_;
  LODWORD(vecSize.x) = LODWORD(flWidthPercXa) ^ _mask__NegFloat_;
  vecSize.y = v10 + 1.0;
  flWidthPercY = v10;
  vecSize.z = 0.25;
  CCollisionProperty::NormalizedToWorldSpace(this: p_m_Collision, in: &vecSize, pResult: vecPoints);
  flWidthPercXb = flWidthPercXa + 1.0;
  vecSize.x = flWidthPercXb;
  vecSize.y = v10 + 1.0;
  vecSize.z = 0.25;
  CCollisionProperty::NormalizedToWorldSpace(this: p_m_Collision, in: &vecSize, pResult: &vecPoints[1]);
  vecSize.x = flWidthPercXb;
  LODWORD(flWidthPercXc) = LODWORD(flWidthPercY) ^ _mask__NegFloat_;
  LODWORD(vecSize.y) = LODWORD(flWidthPercY) ^ _mask__NegFloat_;
  vecSize.z = 0.25;
  CCollisionProperty::NormalizedToWorldSpace(this: p_m_Collision, in: &vecSize, pResult: &vecPoints[2]);
  vecSize.x = v18;
  vecSize.y = flWidthPercXc;
  vecSize.z = 0.25;
  CCollisionProperty::NormalizedToWorldSpace(this: p_m_Collision, in: &vecSize, pResult: &vecPoints[3]);
  v11 = ClosestPointToPosition(vecPosition: vStart, vecPoints, nNumPoints: 4);
  v12 = ClosestPointToPosition(vecPosition: vEnd, vecPoints, nNumPoints: 4);
  if ( v11 == v12 )
    return nullptr;
  v13 = ShortestDirectionThroughPoints(vecStart: vStart, nStartPoint: v11, nEndPoint: v12, vecPoints, nNumPoints: 4);
  result = CAI_Pathfinder::BuildRouteThroughPoints(
             this: v20,
             vecPoints,
             nNumPoints: 4,
             nDirection: v13,
             nStartIndex: v11,
             nEndIndex: v12,
             navType,
             pTarget);
  if ( result == nullptr )
  {
    result = CAI_Pathfinder::BuildRouteThroughPoints(
               this: v20,
               vecPoints,
               nNumPoints: 4,
               nDirection: -v13,
               nStartIndex: v11,
               nEndIndex: v12,
               navType,
               pTarget);
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075310
// Name: public: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildRoute(class Vector const __near &,class Vector const __near &,class CBaseEntity __near *,float,enum Navigation_t,int)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__userpurge CAI_Pathfinder::BuildRoute@<eax>(
        CAI_Pathfinder *this@<ecx>,
        int a2@<edi>,
        const Vector *vStart,
        const Vector *vEnd,
        CBaseEntity *pTarget,
        float goalTolerance,
        Navigation_t curNavType,
        int nBuildFlags)
{
  unsigned int v8; // ebx
  unsigned int v10; // edi
  AI_Waypoint_t *result; // eax
  char bTryLocal_3; // [esp+47h] [ebp+1Fh]

  v8 = nBuildFlags & 0xFFFFFE00;
  if ( ai_no_local_paths.m_pParent != nullptr && ai_no_local_paths.m_pParent->m_Value.m_nValue != 0
    || (bTryLocal_3 = 1, (v8 & 0x400) != 0) )
  {
    bTryLocal_3 = 0;
  }
  if ( curNavType == NAV_CLIMB )
  {
    v8 |= 8u;
LABEL_20:
    result = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, const Vector *, const Vector *, unsigned int, _DWORD))this->BuildNodeRoute)(
                                a1: this,
                                a2: vStart,
                                a3: vEnd,
                                a4: v8,
                                a5: LODWORD(goalTolerance));
    goto LABEL_21;
  }
  if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 4) != 0
    || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x20) != 0 )
  {
    v8 |= 0x64u;
  }
  else if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 1) != 0 )
  {
    v8 |= 0x61u;
    if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 2) != 0 )
      v8 |= 2u;
    if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x10) != 0 )
      v8 |= 0x10u;
  }
  if ( bTryLocal_3 == 0 || !this->CanUseLocalNavigation(this) )
    goto LABEL_20;
  v10 = v8;
  if ( (((int (__thiscall *)(CAI_BaseNPC *, int))this->m_pOuter->CapabilitiesGet)(a1: this->m_pOuter, a2) & 0x200) != 0 )
    v10 = v8 & 0xFFFFFFEF;
  result = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, const Vector *, const Vector *, CBaseEntity *, int, int, unsigned int))this->BuildLocalRoute)(
                              a1: this,
                              a2: vStart,
                              a3: vEnd,
                              a4: pTarget,
                              a5: 8,
                              a6: -1,
                              a7: v10);
  if ( result == nullptr )
    goto LABEL_20;
LABEL_21:
  this->m_bIgnoreStaleLinks = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075430
// Name: public: virtual bool CPathfindNearestNodeFilter::IsValid(class CAI_Node __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPathfindNearestNodeFilter::IsValid(CPathfindNearestNodeFilter *this, CAI_Node *pNode)
{
  CAI_Node *v2; // ebx
  CAI_Pathfinder *m_pPathfinder; // eax
  int v5; // edx
  int m_Size; // edi
  CAI_Link **m_pMemory; // ecx
  AI_Waypoint_t *v9; // eax
  int v10; // [esp-8h] [ebp-1Ch]
  int m_iID; // [esp-4h] [ebp-18h]
  float goalTolerance; // [esp+0h] [ebp-14h]

  v2 = pNode;
  m_pPathfinder = this->m_pPathfinder;
  v5 = 0;
  if ( !m_pPathfinder->m_bIgnoreStaleLinks )
  {
    m_Size = pNode->m_Links.m_Size;
    if ( m_Size > 0 )
    {
      m_pMemory = pNode->m_Links.m_Memory.m_pMemory;
      do
      {
        if ( ((*m_pMemory)->m_LinkInfo & 0x13) != 0
          || (v2 = pNode, ((*m_pMemory)->m_iAcceptedMoveTypes[m_pPathfinder->m_pOuter->m_eHull] & this->m_moveTypes) == 0) )
        {
          ++v5;
        }
        ++m_pMemory;
        --m_Size;
      }
      while ( m_Size != 0 );
      if ( v5 != 0 && v5 == v2->m_Links.m_Size )
        return false;
    }
  }
  if ( this->m_bAvoidObstacles
    && CAI_LocalNavigator::IsSegmentBlockedByGlobalObstacles(vecStart: &v2->m_vOrigin, vecEnd: &this->m_vGoal) )
  {
    return false;
  }
  goalTolerance = this->m_goalTolerance;
  m_iID = v2->m_iID;
  v10 = this->m_nTries >= 2 ? 128 : 192;
  if ( this->m_bToNode )
    v9 = CAI_Pathfinder::RouteToNode(
           this: this->m_pPathfinder,
           vecOrigin: &this->m_vGoal,
           buildFlags: v10,
           nodeID: m_iID,
           goalTolerance);
  else
    v9 = CAI_Pathfinder::RouteFromNode(
           this: this->m_pPathfinder,
           vecOrigin: (CAI_Node *)&this->m_vGoal,
           buildFlags: v10,
           nodeID: m_iID,
           goalTolerance);
  ++this->m_nTries;
  this->m_pRoute = v9;
  return this->m_pRoute != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10075510
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::BuildNodeRoute(class Vector const __near &,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildNodeRoute(
        CAI_Pathfinder *this,
        AI_Waypoint_t *vStart,
        const Vector *vEnd,
        char buildFlags,
        float goalTolerance)
{
  CAI_Network *m_pNetwork; // ecx
  __int64 v8; // xmm0_8
  CAI_BaseNPC *m_pOuter; // edx
  int v10; // eax
  AI_Waypoint_t *v11; // edi
  int v12; // ebx
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  AI_Waypoint_t *v15; // eax
  CFmtStrN<256> *v16; // eax
  CFmtStrN<256> *v17; // eax
  CFmtStrN<256> *v18; // eax
  AI_Waypoint_t *v19; // eax
  CFmtStrN<256> *v20; // eax
  CFmtStrN<256> *v21; // eax
  CFmtStrN<256> *v22; // eax
  CFmtStrN<256> v23; // [esp+14h] [ebp-244h] BYREF
  CFmtStrN<256> v24; // [esp+120h] [ebp-138h] BYREF
  INearestNodeFilter pFilter; // [esp+22Ch] [ebp-2Ch] BYREF
  CAI_Pathfinder *v26; // [esp+230h] [ebp-28h]
  int v27; // [esp+234h] [ebp-24h]
  __int64 v28; // [esp+238h] [ebp-20h]
  float z; // [esp+240h] [ebp-18h]
  char v30; // [esp+244h] [ebp-14h]
  float v31; // [esp+248h] [ebp-10h]
  int v32; // [esp+24Ch] [ebp-Ch]
  char v33; // [esp+250h] [ebp-8h]
  AI_Waypoint_t *pWaypointList; // [esp+254h] [ebp-4h]
  AI_Waypoint_t *destRoute; // [esp+268h] [ebp+10h]

  m_pNetwork = this->m_pNetwork;
  if ( m_pNetwork->m_iNumNodes == 0 )
    return nullptr;
  v8 = *(_QWORD *)&vStart->vecLocation.x;
  z = vStart->vecLocation.z;
  v32 = buildFlags & 0x1F;
  v27 = 0;
  pWaypointList = nullptr;
  m_pOuter = this->m_pOuter;
  v28 = v8;
  pFilter.__vftable = (INearestNodeFilter_vtbl *)&CPathfindNearestNodeFilter::`vftable';
  v26 = this;
  v30 = 1;
  v31 = goalTolerance;
  v33 = 1;
  v10 = CAI_Network::NearestNodeToPoint(
          this: m_pNetwork,
          pNPC: m_pOuter,
          vecOrigin: &vStart->vecLocation,
          bCheckVisibility: true,
          &pFilter);
  v11 = pWaypointList;
  v12 = v10;
  if ( pWaypointList == nullptr )
  {
    if ( ai_debug_nav.m_pParent != nullptr && (AI_Waypoint_t *)ai_debug_nav.m_pParent->m_Value.m_nValue != pWaypointList )
    {
      v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "Node pathfind failed, no route to source %d\n", v10);
      v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "[Nav] %s", v13->m_szBuf);
      DevMsg(pAI: this->m_pOuter, pszFormat: v14->m_szBuf);
      return nullptr;
    }
    return nullptr;
  }
  v15 = CAI_Pathfinder::BuildNearestNodeRoute(
          this,
          vGoal: vEnd,
          bToNode: false,
          buildFlags,
          goalTolerance,
          pNearestNode: (int *)&goalTolerance);
  destRoute = v15;
  if ( v15 == nullptr )
  {
    DeleteAll(pWaypointList: v11);
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v16 = CFmtStrN<256>::CFmtStrN<256>(
              this: &v24,
              pszFormat: "Node pathfind failed, no route to dest %d\n",
              goalTolerance);
      v17 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "[Nav] %s", v16->m_szBuf);
      DevMsg(pAI: this->m_pOuter, pszFormat: v17->m_szBuf);
    }
    return nullptr;
  }
  if ( LODWORD(goalTolerance) == v12 )
  {
    AddWaypointLists(oldRoute: v11, addRoute: v15);
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v18 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "[Nav] %s", "Node pathfind succeeded: dest == source\n");
      DevMsg(pAI: this->m_pOuter, pszFormat: v18->m_szBuf);
      return v11;
    }
    return v11;
  }
  if ( !CAI_Network::IsConnected(this: this->m_pNetwork, srcID: v12, destID: SLODWORD(goalTolerance)) )
    return nullptr;
  v19 = this->FindBestPath(this, a2: v12, a3: LODWORD(goalTolerance));
  if ( v19 == nullptr )
  {
    DeleteAll(pWaypointList: v11);
    DeleteAll(pWaypointList: destRoute);
    if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
    {
      v20 = CFmtStrN<256>::CFmtStrN<256>(
              this: &v24,
              pszFormat: "Node pathfind failed, no route between %d and %d\n",
              v12,
              goalTolerance);
      v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "[Nav] %s", v20->m_szBuf);
      DevMsg(pAI: this->m_pOuter, pszFormat: v21->m_szBuf);
    }
    return nullptr;
  }
  AddWaypointLists(oldRoute: v11, addRoute: v19);
  AddWaypointLists(oldRoute: v11, addRoute: destRoute);
  if ( ai_debug_nav.m_pParent != nullptr && ai_debug_nav.m_pParent->m_Value.m_nValue != 0 )
  {
    v22 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "[Nav] %s", "Node pathfind succeeded\n");
    DevMsg(pAI: this->m_pOuter, pszFormat: v22->m_szBuf);
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100757A0
// Name: public: void CAI_Pathfinder::DrawDebugGeometryOverlays(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::DrawDebugGeometryOverlays(CAI_Pathfinder *this, __int16 npcDebugOverlays)
{
  CAI_Pathfinder::CTriDebugOverlay::Draw(this: &this->m_TriDebugOverlay, npcDebugOverlays);
}

//------------------------------------------------------------------------------
// Address: 0x100757B0
// Name: public: void CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLines(class Vector const __near &,class Vector const __near &,class Vector const __near &,struct AIMoveTrace_t const __near &,struct AIMoveTrace_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLines(
        CAI_Pathfinder::CTriDebugOverlay *this,
        const Vector *vecStart,
        const Vector *vecApex,
        const Vector *vecEnd,
        const AIMoveTrace_t *startTrace,
        const AIMoveTrace_t *endTrace,
        bool bPathClear)
{
  float x; // xmm1_4
  float y; // xmm2_4
  int v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edx
  int v14; // [esp-10h] [ebp-34h]
  int v15; // [esp-10h] [ebp-34h]
  int v16; // [esp-Ch] [ebp-30h]
  int v17; // [esp-Ch] [ebp-30h]
  int v18; // [esp-Ch] [ebp-30h]
  int v19; // [esp-Ch] [ebp-30h]
  int v20; // [esp-8h] [ebp-2Ch]
  int v21; // [esp-8h] [ebp-2Ch]
  int v22; // [esp-8h] [ebp-2Ch]
  int v23; // [esp-8h] [ebp-2Ch]
  Vector pt1; // [esp+Ch] [ebp-18h] BYREF
  Vector pt2; // [esp+18h] [ebp-Ch] BYREF

  CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
    this,
    origin: vecStart,
    dest: vecApex,
    r: s_TriangulationColor[bPathClear][0],
    g: (unsigned __int8)byte_1056B1B1[3 * bPathClear],
    b: (unsigned __int8)byte_1056B1B2[3 * bPathClear],
    noDepthTest: false);
  CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
    this,
    origin: vecApex,
    dest: vecEnd,
    r: s_TriangulationColor[bPathClear][0],
    g: (unsigned __int8)byte_1056B1B1[3 * bPathClear],
    b: (unsigned __int8)byte_1056B1B2[3 * bPathClear],
    noDepthTest: false);
  if ( startTrace->fStatus < AIMR_OK )
  {
    x = startTrace->vEndPosition.x;
    y = startTrace->vEndPosition.y;
    v10 = s_TriangulationColor[bPathClear][0];
    v20 = (unsigned __int8)byte_1056B1B2[3 * bPathClear];
    v16 = (unsigned __int8)byte_1056B1B1[3 * bPathClear];
    pt2.z = startTrace->vEndPosition.z;
    pt1.z = pt2.z;
    pt1.x = x - 10.0;
    pt1.y = y - 10.0;
    pt2.x = x + 10.0;
    pt2.y = y + 10.0;
    CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
      this,
      origin: &pt1,
      dest: &pt2,
      r: v10,
      g: v16,
      b: v20,
      noDepthTest: false);
    v21 = (unsigned __int8)byte_1056B1B2[3 * bPathClear];
    v17 = (unsigned __int8)byte_1056B1B1[3 * bPathClear];
    v14 = s_TriangulationColor[bPathClear][0];
    pt1.x = pt1.x + 20.0;
    pt2.x = pt2.x - 20.0;
    CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
      this,
      origin: &pt1,
      dest: &pt2,
      r: v14,
      g: v17,
      b: v21,
      noDepthTest: false);
  }
  if ( endTrace->fStatus < AIMR_OK )
  {
    v11 = endTrace->vEndPosition.x;
    v12 = endTrace->vEndPosition.y;
    v13 = s_TriangulationColor[bPathClear][0];
    v22 = (unsigned __int8)byte_1056B1B2[3 * bPathClear];
    v18 = (unsigned __int8)byte_1056B1B1[3 * bPathClear];
    pt1.z = endTrace->vEndPosition.z;
    pt2.z = pt1.z;
    pt2.x = v11 - 10.0;
    pt2.y = v12 - 10.0;
    pt1.x = v11 + 10.0;
    pt1.y = v12 + 10.0;
    CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
      this,
      origin: &pt2,
      dest: &pt1,
      r: v13,
      g: v18,
      b: v22,
      noDepthTest: false);
    v23 = (unsigned __int8)byte_1056B1B2[3 * bPathClear];
    v19 = (unsigned __int8)byte_1056B1B1[3 * bPathClear];
    v15 = s_TriangulationColor[bPathClear][0];
    pt2.x = pt2.x + 20.0;
    pt1.x = pt1.x - 20.0;
    CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLine(
      this,
      origin: &pt2,
      dest: &pt1,
      r: v15,
      g: v19,
      b: v23,
      noDepthTest: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10075A40
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildComplexRoute(enum Navigation_t,class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,int,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
AI_Waypoint_t *__userpurge CAI_Pathfinder::BuildComplexRoute@<eax>(
        CAI_Pathfinder *this@<ecx>,
        int a2@<ebp>,
        Navigation_t navType,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pTarget,
        int endFlags,
        int nodeID,
        __int16 buildFlags,
        float flYaw,
        float goalTolerance,
        float maxLocalNavDistance)
{
  float v12; // xmm1_4
  float v14; // xmm1_4
  __int128 v15; // xmm0
  CAI_BaseNPC *m_pOuter; // ecx
  CAI_MoveProbe *m_pMoveProbe; // ecx
  AI_Waypoint_t *v18; // eax
  char v19; // al
  CAI_BaseNPC *v20; // ecx
  float v21; // xmm1_4
  AI_Waypoint_t *(__thiscall *BuildTriangulationRoute)(CAI_Pathfinder *, const Vector *, const Vector *, const CBaseEntity *, int, int, float, float, Navigation_t); // edx
  __int128 v23; // xmm0
  AI_Waypoint_t *result; // eax
  Navigation_t pctToCheckStandPositions; // [esp+24h] [ebp-B8h]
  int v26; // [esp+28h] [ebp-B4h]
  int v27; // [esp+2Ch] [ebp-B0h]
  _BYTE v28[128]; // [esp+40h] [ebp-9Ch] OVERLAPPED BYREF
  unsigned int m_nAITraceMask; // [esp+C4h] [ebp-18h]
  float v30; // [esp+C8h] [ebp-14h]
  bool v31; // [esp+CFh] [ebp-Dh]
  int v32; // [esp+D0h] [ebp-Ch] BYREF
  float flTotalDist; // [esp+D4h] [ebp-8h]
  float retaddr; // [esp+DCh] [ebp+0h]

  v32 = a2;
  flTotalDist = retaddr;
  v12 = vEnd->y - vStart->y;
  v14 = v12 * v12;
  if ( navType != NAV_GROUND )
    v14 = v14 + (float)((float)(vEnd->z - vStart->z) * (float)(vEnd->z - vStart->z));
  v15 = 0;
  *(float *)&v15 = fsqrt(v14 + (float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)));
  *(_OWORD *)&v28[112] = v15;
  v30 = *(float *)&v15;
  if ( *(float *)&v15 < 0.0625 )
    goto LABEL_27;
  m_pOuter = this->m_pOuter;
  if ( (buildFlags & 0x80u) == 0 )
    m_nAITraceMask = m_pOuter->m_nAITraceMask;
  else
    m_nAITraceMask = m_pOuter->m_nAITraceMask & 0xFDFFFFFF;
  v31 = (m_pOuter->CapabilitiesGet(this: m_pOuter) & 0x80) == 0;
  if ( maxLocalNavDistance < v30 && (buildFlags & 0x800) == 0 )
    return nullptr;
  memset(dst: (int)&v28[56], value: nullptr, count: 0x38u);
  m_pMoveProbe = this->m_pOuter->m_pMoveProbe;
  v30 = (float)(v31 ? 0x64 : 0);
  CAI_MoveProbe::MoveLimit(
    this: m_pMoveProbe,
    a2: (int)&v32,
    navType,
    vecStart: vStart,
    vecEnd: vEnd,
    collisionMask: m_nAITraceMask,
    pTarget,
    pctToCheckStandPositions: v30,
    flags: 0,
    pTrace: (AIMoveTrace_t *)&v28[56]);
  if ( *(int *)&v28[56] >= 0 )
  {
    v18 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
    if ( v18 != nullptr )
    {
      v27 = nodeID;
      v26 = endFlags;
      pctToCheckStandPositions = navType;
      return AI_Waypoint_t::AI_Waypoint_t(
               this: v18,
               initPosition: vEnd,
               initYaw: flYaw,
               initNavType: pctToCheckStandPositions,
               initWaypointFlags: v26,
               initNodeID: v27);
    }
    return nullptr;
  }
  v19 = buildFlags;
  if ( (buildFlags & 0x200) != 0 && (endFlags & 8) != 0 && goalTolerance >= *(float *)&v28[92] )
  {
LABEL_27:
    v18 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
    if ( v18 != nullptr )
    {
      v27 = nodeID;
      v26 = endFlags;
      pctToCheckStandPositions = navType;
      return AI_Waypoint_t::AI_Waypoint_t(
               this: v18,
               initPosition: vEnd,
               initYaw: flYaw,
               initNavType: pctToCheckStandPositions,
               initWaypointFlags: v26,
               initNodeID: v27);
    }
    return nullptr;
  }
  if ( (buildFlags & 0x40) == 0 )
  {
LABEL_23:
    if ( *(_DWORD *)&v28[56] == -3 && (v19 & 0x20) != 0 )
    {
      memset(dst: (int)v28, value: nullptr, count: 0x38u);
      CAI_MoveProbe::MoveLimit(
        this: this->m_pOuter->m_pMoveProbe,
        a2: (int)&v32,
        navType,
        vecStart: vStart,
        vecEnd: vEnd,
        collisionMask: this->m_pOuter->m_nAITraceMask & 0xFDFFFFFF,
        pTarget,
        pctToCheckStandPositions: v30,
        flags: 0,
        pTrace: (AIMoveTrace_t *)v28);
      if ( *(int *)v28 >= 0 && CAI_Pathfinder::CanGiveWay(this, vStart, vEnd, pBlocker: *(CBaseEntity **)&v28[84]) )
        goto LABEL_27;
    }
    return nullptr;
  }
  if ( !AIStrongOpt()
    || (v20 = this->m_pOuter)->m_NPCState == NPC_STATE_SCRIPT
    || CAI_BaseNPC::IsCurSchedule(this: v20, schedId: 63, fIdeal: false) )
  {
    v21 = (float)(vEnd->y - vStart->y) * (float)(vEnd->y - vStart->y);
    if ( navType != NAV_GROUND )
      v21 = v21 + (float)((float)(vEnd->z - vStart->z) * (float)(vEnd->z - vStart->z));
    BuildTriangulationRoute = this->BuildTriangulationRoute;
    v23 = 0;
    *(float *)&v23 = fsqrt(v21 + (float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)));
    *(_OWORD *)&v28[112] = v23;
    result = (AI_Waypoint_t *)((int (__thiscall *)(CAI_Pathfinder *, const Vector *, const Vector *, const CBaseEntity *, int, int, _DWORD, _DWORD, Navigation_t))BuildTriangulationRoute)(
                                a1: this,
                                a2: vStart,
                                a3: vEnd,
                                a4: pTarget,
                                a5: endFlags,
                                a6: nodeID,
                                a7: LODWORD(flYaw),
                                a8: *(float *)&v23 - *(float *)&v28[92],
                                a9: navType);
    if ( result != nullptr )
      return result;
  }
  v19 = buildFlags;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x10075D30
// Name: private: struct AI_Waypoint_t __near * CAI_Pathfinder::BuildCrawlRoute(class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildCrawlRoute(
        CAI_Pathfinder *this,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pTarget,
        int endFlags,
        int nodeID,
        __int16 buildFlags,
        float flYaw,
        float goalTolerance)
{
  bool v10; // al
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v10 = AIStrongOpt();
  return CAI_Pathfinder::BuildComplexRoute(
           this,
           a2: (int)&savedregs,
           navType: NAV_CRAWL,
           vStart,
           vEnd,
           pTarget,
           endFlags,
           nodeID,
           buildFlags,
           flYaw,
           goalTolerance,
           maxLocalNavDistance: MAX_LOCAL_NAV_DIST_GROUND[v10]);
}

//------------------------------------------------------------------------------
// Address: 0x10075D90
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::BuildLocalRoute(class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__userpurge CAI_Pathfinder::BuildLocalRoute@<eax>(
        CAI_Pathfinder *this@<ecx>,
        int a2@<ebp>,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pTarget,
        int endFlags,
        int nodeID,
        __int16 buildFlags,
        float goalTolerance)
{
  CAI_Network *m_pNetwork; // eax
  float m_flYaw; // xmm0_4
  bool v12; // al
  AI_Waypoint_t *result; // eax
  bool v14; // al
  float v15; // xmm1_4
  _DWORD v16[2]; // [esp+3Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h]

  v16[0] = a2;
  v16[1] = retaddr;
  if ( nodeID == -1 )
  {
    m_flYaw = 0.0;
  }
  else
  {
    m_pNetwork = this->m_pNetwork;
    if ( nodeID < 0 || nodeID >= m_pNetwork->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      m_flYaw = MEMORY[0x40];
    }
    else
    {
      m_flYaw = m_pNetwork->m_pAInode[nodeID]->m_flYaw;
    }
  }
  if ( (buildFlags & 1) == 0
    || (v12 = AIStrongOpt(),
        (result = CAI_Pathfinder::BuildComplexRoute(
                    this,
                    a2: (int)v16,
                    navType: NAV_GROUND,
                    vStart,
                    vEnd,
                    pTarget,
                    endFlags,
                    nodeID,
                    buildFlags,
                    flYaw: m_flYaw,
                    goalTolerance,
                    maxLocalNavDistance: MAX_LOCAL_NAV_DIST_GROUND[v12])) == nullptr) )
  {
    if ( (buildFlags & 4) == 0
      || (v14 = AIStrongOpt(),
          (result = CAI_Pathfinder::BuildComplexRoute(
                      this,
                      a2: (int)v16,
                      navType: NAV_FLY,
                      vStart,
                      vEnd,
                      pTarget,
                      endFlags,
                      nodeID,
                      buildFlags,
                      flYaw: m_flYaw,
                      goalTolerance,
                      maxLocalNavDistance: MAX_LOCAL_NAV_DIST_FLY[v14])) == nullptr) )
    {
      if ( (buildFlags & 0x10) == 0
        || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x10) == 0
        || (result = CAI_Pathfinder::BuildCrawlRoute(
                       this,
                       vStart,
                       vEnd,
                       pTarget,
                       endFlags,
                       nodeID,
                       buildFlags,
                       flYaw: m_flYaw,
                       goalTolerance)) == nullptr )
      {
        if ( (buildFlags & 2) == 0
          || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 2) == 0
          || COERCE_FLOAT(COERCE_UNSIGNED_INT(vStart->z - vEnd->z) & _mask__AbsFloat_) <= 24.0
          && (v15 = vStart->y - vEnd->y,
              fsqrt((float)((float)(vStart->x - vEnd->x) * (float)(vStart->x - vEnd->x)) + (float)(v15 * v15)) <= 360000.0)
          || (result = CAI_Pathfinder::BuildSimpleRoute(
                         this,
                         navType: NAV_JUMP,
                         vStart,
                         vEnd,
                         pTarget,
                         endFlags,
                         nodeID,
                         nodeTargetType: 2,
                         flYaw: m_flYaw)) == nullptr )
        {
          if ( (buildFlags & 8) == 0 )
            return nullptr;
          if ( (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 8) == 0 )
            return nullptr;
          result = CAI_Pathfinder::BuildSimpleRoute(
                     this,
                     navType: NAV_CLIMB,
                     vStart,
                     vEnd,
                     pTarget,
                     endFlags,
                     nodeID,
                     nodeTargetType: 4,
                     flYaw: m_flYaw);
          if ( result == nullptr )
            return nullptr;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10075FF0
// Name: private: bool CAI_Pathfinder::TestTriangulationRoute(enum Navigation_t,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,struct AIMoveTrace_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Pathfinder::TestTriangulationRoute(
        CAI_Pathfinder *this,
        Navigation_t navType,
        const Vector *vecStart,
        const Vector *vecApex,
        const Vector *vecEnd,
        const CBaseEntity *pTargetEnt,
        AIMoveTrace_t *pStartTrace)
{
  CAI_BaseNPC *m_pOuter; // eax
  CAI_MoveProbe *m_pMoveProbe; // edi
  unsigned int m_nAITraceMask; // [esp-8h] [ebp-5Ch]
  AIMoveTrace_t endTrace; // [esp+18h] [ebp-3Ch] BYREF
  BOOL bPathClear; // [esp+50h] [ebp-4h]
  int savedregs; // [esp+54h] [ebp+0h] BYREF

  memset(dst: (int)&endTrace, value: nullptr, count: sizeof(endTrace));
  m_pOuter = this->m_pOuter;
  endTrace.fStatus = AIMR_OK;
  m_pMoveProbe = m_pOuter->m_pMoveProbe;
  m_nAITraceMask = m_pOuter->m_nAITraceMask;
  LOBYTE(bPathClear) = 0;
  if ( CAI_MoveProbe::MoveLimit(
         this: m_pMoveProbe,
         a2: (int)&savedregs,
         navType,
         vecStart,
         vecEnd: vecApex,
         collisionMask: m_nAITraceMask,
         pTarget: pTargetEnt,
         pctToCheckStandPositions: 100.0,
         flags: 0,
         pTrace: pStartTrace)
    && CAI_MoveProbe::MoveLimit(
         this: m_pMoveProbe,
         a2: (int)&savedregs,
         navType,
         vecStart: vecApex,
         vecEnd,
         collisionMask: this->m_pOuter->m_nAITraceMask,
         pTarget: pTargetEnt,
         pctToCheckStandPositions: 100.0,
         flags: 0,
         pTrace: &endTrace) )
  {
    LOBYTE(bPathClear) = 1;
  }
  if ( (this->m_pOuter->m_debugOverlays & 0x8000) != 0 )
    CAI_Pathfinder::CTriDebugOverlay::AddTriOverlayLines(
      this: &this->m_TriDebugOverlay,
      vecStart,
      vecApex,
      vecEnd,
      startTrace: pStartTrace,
      &endTrace,
      bPathClear);
  return bPathClear;
}

//------------------------------------------------------------------------------
// Address: 0x100760D0
// Name: public: bool CAI_Pathfinder::Triangulate(enum Navigation_t,class Vector const __near &,class Vector const __near &,float,class CBaseEntity const __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Pathfinder::Triangulate(
        CAI_Pathfinder *this,
        Navigation_t navType,
        const Vector *vecStart,
        const Vector *vecEndIn,
        float flDistToBlocker,
        const CBaseEntity *pTargetEnt,
        Vector *pApex)
{
  unsigned int v8; // ecx
  bool result; // al
  CAI_BaseNPC *m_pOuter; // eax
  float v12; // xmm0_4
  double v13; // st7
  double v14; // st7
  bool v15; // zf
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  int v20; // esi
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  int v24; // ebx
  float *p_z; // esi
  float *v26; // edi
  float y; // xmm3_4
  float z; // xmm5_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  Vector *v32; // eax
  float v33; // xmm0_4
  Vector *v34; // eax
  Hull_t v35; // [esp+4h] [ebp-D4h]
  Hull_t m_eHull; // [esp+8h] [ebp-D0h]
  AIMoveTrace_t moveTrace; // [esp+18h] [ebp-C0h] BYREF
  Vector vecApex[4]; // [esp+50h] [ebp-88h] BYREF
  Vector vecDelta[2]; // [esp+80h] [ebp-58h] BYREF
  float sizeX; // [esp+98h] [ebp-40h]
  CAI_Pathfinder *v41; // [esp+9Ch] [ebp-3Ch]
  float sizeZ; // [esp+A0h] [ebp-38h]
  Vector vecUp; // [esp+A4h] [ebp-34h]
  Vector vecEnd; // [esp+B0h] [ebp-28h] BYREF
  float v45; // [esp+BCh] [ebp-1Ch]
  Vector vecPerpendicular; // [esp+C0h] [ebp-18h]
  Vector vecForward; // [esp+CCh] [ebp-Ch] BYREF
  int savedregs; // [esp+D8h] [ebp+0h] BYREF
  float i; // [esp+E8h] [ebp+10h]
  int ia; // [esp+E8h] [ebp+10h]
  int flDistToBlockera; // [esp+ECh] [ebp+14h]

  v8 = (unsigned int)this->m_pOuter->m_spawnflags.m_Value >> 4;
  v41 = this;
  if ( (v8 & 1) != 0 )
    return false;
  vecForward.x = vecEndIn->x - vecStart->x;
  vecForward.y = vecEndIn->y - vecStart->y;
  vecForward.z = vecEndIn->z - vecStart->z;
  i = VectorNormalize(vec: &vecForward);
  if ( navType == NAV_FLY || i <= 384.0 )
  {
    vecEnd = *vecEndIn;
  }
  else
  {
    m_pOuter = this->m_pOuter;
    i = 384.0;
    vecEnd.x = vecForward.x * 384.0;
    vecEnd.y = vecForward.y * 384.0;
    vecEnd.z = vecForward.z * 384.0;
    result = CAI_MoveProbe::MoveLimit(
               this: m_pOuter->m_pMoveProbe,
               a2: (int)&savedregs,
               navType,
               vecStart: &vecEnd,
               vecEnd: vecEndIn,
               collisionMask: m_pOuter->m_nAITraceMask,
               pTarget: pTargetEnt,
               pctToCheckStandPositions: 100.0,
               flags: 0,
               pTrace: nullptr);
    if ( !result )
      return result;
  }
  if ( (float)(1.0 - COERCE_FLOAT(LODWORD(vecForward.z) & _mask__AbsFloat_)) <= 0.001 )
  {
    v12 = 0.0;
    vecUp.y = 1.0;
    vecUp.z = 0.0;
    vecPerpendicular.x = 1.0;
    vecPerpendicular.z = 0.0;
  }
  else
  {
    vecUp.z = 1.0;
    vecPerpendicular.x = vecForward.y - (float)(vecForward.z * 0.0);
    v12 = (float)(vecForward.z * 0.0) - vecForward.x;
    vecUp.y = 0.0;
    vecPerpendicular.z = (float)(vecForward.x * 0.0) - (float)(vecForward.y * 0.0);
  }
  m_eHull = this->m_pOuter->m_eHull;
  vecPerpendicular.y = v12;
  v13 = NAI_Hull::Length(id: m_eHull);
  v35 = this->m_pOuter->m_eHull;
  sizeX = v13 * 0.5;
  v14 = NAI_Hull::Height(id: v35);
  v15 = (this->m_pOuter->m_debugOverlays & 0x8000) == 0;
  sizeZ = v14 * 0.5;
  if ( !v15 )
    CAI_Pathfinder::CTriDebugOverlay::FadeTriOverlayLines(this: &this->m_TriDebugOverlay);
  v16 = sizeX + flDistToBlocker;
  if ( (float)(sizeX + flDistToBlocker) > i )
    v16 = i;
  v17 = (float)(vecForward.x * v16) + vecStart->x;
  vecApex[0].x = v17 - (float)(vecPerpendicular.x * sizeX);
  v18 = (float)(vecForward.y * v16) + vecStart->y;
  v19 = (float)(v16 * vecForward.z) + vecStart->z;
  vecApex[0].y = v18 - (float)(vecPerpendicular.y * sizeX);
  vecApex[0].z = v19 - (float)(vecPerpendicular.z * sizeX);
  vecApex[1].x = v17 + (float)(vecPerpendicular.x * sizeX);
  vecApex[1].y = v18 + (float)(vecPerpendicular.y * sizeX);
  v20 = 2;
  vecApex[1].z = v19 + (float)(vecPerpendicular.z * sizeX);
  vecDelta[0].x = (float)(vecPerpendicular.x * sizeX) * 2.0;
  vecDelta[0].y = (float)(vecPerpendicular.y * sizeX) * 2.0;
  vecDelta[0].z = (float)(vecPerpendicular.z * sizeX) * 2.0;
  vecPerpendicular.x = v16;
  v45 = v16;
  if ( navType == NAV_FLY )
  {
    v21 = (float)(sizeZ * 3.0) * 0.0;
    v22 = vecUp.y * (float)(sizeZ * 3.0);
    v23 = (float)(sizeZ * 3.0) * vecUp.z;
    vecApex[2].x = v17 - v21;
    vecApex[2].y = v18 - v22;
    vecDelta[1].x = v21;
    vecDelta[1].y = v22;
    vecDelta[1].z = v23;
    vecApex[2].z = v19 - v23;
    vecApex[3].x = v21 + v17;
    vecApex[3].y = v22 + v18;
    vecApex[3].z = v23 + v19;
    vecPerpendicular.z = v16;
    vecPerpendicular.y = v16;
    v20 = 4;
  }
  memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
  ia = 0;
  flDistToBlockera = v20 - 1;
  while ( 1 )
  {
    v24 = flDistToBlockera;
    if ( flDistToBlockera >= 0 )
      break;
LABEL_29:
    if ( ++ia >= 2 )
      return false;
  }
  p_z = &vecApex[flDistToBlockera].z;
  while ( 1 )
  {
    v26 = p_z - 2;
    if ( CAI_Pathfinder::TestTriangulationRoute(
           this: v41,
           navType,
           vecStart,
           vecApex: (const Vector *)(p_z - 2),
           &vecEnd,
           pTargetEnt,
           pStartTrace: &moveTrace) )
    {
      break;
    }
    if ( moveTrace.fStatus < AIMR_OK )
    {
      y = vecForward.y;
      z = vecForward.z;
      v29 = *(&v45 + v24);
      v30 = v29;
      if ( v29 > (float)((float)((float)((float)(moveTrace.vEndPosition.y - vecStart->y) * vecForward.y)
                               + (float)((float)(moveTrace.vEndPosition.x - vecStart->x) * vecForward.x))
                       + (float)((float)(moveTrace.vEndPosition.z - vecStart->z) * vecForward.z)) )
        v30 = (float)((float)((float)(moveTrace.vEndPosition.y - vecStart->y) * vecForward.y)
                    + (float)((float)(moveTrace.vEndPosition.x - vecStart->x) * vecForward.x))
            + (float)((float)(moveTrace.vEndPosition.z - vecStart->z) * vecForward.z);
      *v26 = (float)((float)(v30 - v29) * vecForward.x) + *v26;
      *(p_z - 1) = (float)(y * (float)(v30 - v29)) + *(p_z - 1);
      *p_z = (float)((float)(v30 - v29) * z) + *p_z;
      *(&v45 + v24) = v30;
    }
    v31 = *v26;
    v32 = &vecDelta[v24 >> 1];
    if ( (v24 & 1) != 0 )
    {
      *v26 = v31 + v32->x;
      *(p_z - 1) = v32->y + *(p_z - 1);
      v33 = v32->z + *p_z;
    }
    else
    {
      *v26 = v31 - v32->x;
      *(p_z - 1) = *(p_z - 1) - v32->y;
      v33 = *p_z - v32->z;
    }
    *p_z = v33;
    p_z -= 3;
    if ( --v24 < 0 )
      goto LABEL_29;
  }
  v34 = &vecApex[v24];
  *pApex = *v34;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100765D0
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::BuildTriangulationRoute(class Vector const __near &,class Vector const __near &,class CBaseEntity const __near *,int,int,float,float,enum Navigation_t)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_Pathfinder::BuildTriangulationRoute(
        CAI_Pathfinder *this,
        const Vector *vStart,
        const Vector *vEnd,
        const CBaseEntity *pTarget,
        int endFlags,
        int nodeID,
        float flYaw,
        float flDistToBlocker,
        Navigation_t navType)
{
  AI_Waypoint_t *result; // eax
  AI_Waypoint_t *v10; // eax
  AI_Waypoint_t *v11; // esi
  AI_Waypoint_t *v12; // eax
  AI_Waypoint_t *pNext; // ecx
  AI_Waypoint_t *pPrev; // ecx
  Vector vApex; // [esp+18h] [ebp-Ch] BYREF

  if ( !CAI_Pathfinder::Triangulate(
          this,
          navType,
          vecStart: vStart,
          vecEndIn: vEnd,
          flDistToBlocker,
          pTargetEnt: pTarget,
          pApex: &vApex) )
    return nullptr;
  v10 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
  if ( v10 != nullptr )
    v11 = AI_Waypoint_t::AI_Waypoint_t(
            this: v10,
            initPosition: vEnd,
            initYaw: flYaw,
            initNavType: navType,
            initWaypointFlags: endFlags,
            initNodeID: nodeID);
  else
    v11 = nullptr;
  v12 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
  if ( v12 != nullptr )
    result = AI_Waypoint_t::AI_Waypoint_t(
               this: v12,
               initPosition: &vApex,
               initYaw: 0.0,
               initNavType: navType,
               initWaypointFlags: 1,
               initNodeID: -1);
  else
    result = nullptr;
  pNext = result->pNext;
  if ( pNext != nullptr )
    pNext->pPrev = nullptr;
  result->pNext = v11;
  if ( v11 != nullptr )
  {
    pPrev = v11->pPrev;
    if ( pPrev != nullptr )
      pPrev->pNext = nullptr;
    result->pNext->pPrev = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100766A0
// Name: private: bool CAI_Pathfinder::CheckStaleNavTypeRoute(enum Navigation_t,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CAI_Pathfinder::CheckStaleNavTypeRoute@<al>(
        CAI_Pathfinder *this@<ecx>,
        int a2@<ebp>,
        Navigation_t navType,
        const Vector *vStart,
        const Vector *vEnd)
{
  bool result; // al
  __int128 v7; // xmm0
  _BYTE v8[72]; // [esp+14h] [ebp-64h] OVERLAPPED BYREF
  CAI_Pathfinder *v9; // [esp+68h] [ebp-10h]
  _DWORD v10[3]; // [esp+6Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+78h] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  v9 = this;
  memset(dst: (int)v8, value: nullptr, count: 0x38u);
  CAI_MoveProbe::MoveLimit(
    this: this->m_pOuter->m_pMoveProbe,
    a2: (int)v10,
    navType,
    vecStart: vStart,
    vecEnd: vEnd,
    collisionMask: this->m_pOuter->m_nAITraceMask,
    pTarget: nullptr,
    pctToCheckStandPositions: 100.0,
    flags: 4,
    pTrace: (AIMoveTrace_t *)v8);
  result = true;
  if ( *(int *)v8 < 0 )
  {
    v7 = 0;
    *(float *)&v7 = fsqrt(
                      (float)((float)((float)(vEnd->y - vStart->y) * (float)(vEnd->y - vStart->y))
                            + (float)((float)(vEnd->z - vStart->z) * (float)(vEnd->z - vStart->z)))
                    + (float)((float)(vEnd->x - vStart->x) * (float)(vEnd->x - vStart->x)));
    *(_OWORD *)&v8[56] = v7;
    if ( !CAI_Pathfinder::Triangulate(
            this: v9,
            navType,
            vecStart: vStart,
            vecEndIn: vEnd,
            flDistToBlocker: *(float *)&v7 - *(float *)&v8[36],
            pTargetEnt: nullptr,
            pApex: (Vector *)&v8[60]) )
    {
      if ( *(_DWORD *)&v8[28] == 0 )
        return false;
      if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v8[28] + 296))(a1: *(_DWORD *)&v8[28]) == 0 )
        return false;
      CAI_MoveProbe::MoveLimit(
        this: v9->m_pOuter->m_pMoveProbe,
        a2: (int)v10,
        navType,
        vecStart: vStart,
        vecEnd: vEnd,
        collisionMask: v9->m_pOuter->m_nAITraceMask & 0xFDFFFFFF,
        pTarget: nullptr,
        pctToCheckStandPositions: 100.0,
        flags: 0,
        pTrace: (AIMoveTrace_t *)v8);
      if ( *(int *)v8 < 0 )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100767F0
// Name: private: bool CAI_Pathfinder::CheckStaleRoute(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Pathfinder::CheckStaleRoute(
        CAI_Pathfinder *this,
        const Vector *vStart,
        const Vector *vEnd,
        char moveTypes)
{
  bool result; // al
  AIMoveTrace_t moveTrace; // [esp+18h] [ebp-38h] BYREF
  int savedregs; // [esp+50h] [ebp+0h] BYREF

  result = true;
  if ( ((moveTypes & 1) == 0
     || !CAI_Pathfinder::CheckStaleNavTypeRoute(this, a2: (int)&savedregs, navType: NAV_GROUND, vStart, vEnd))
    && ((moveTypes & 4) == 0
     || !CAI_Pathfinder::CheckStaleNavTypeRoute(this, a2: (int)&savedregs, navType: NAV_FLY, vStart, vEnd)) )
  {
    if ( (moveTypes & 2) == 0
      || (memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace)),
          CAI_MoveProbe::MoveLimit(
            this: this->m_pOuter->m_pMoveProbe,
            a2: (int)&savedregs,
            navType: NAV_JUMP,
            vecStart: vStart,
            vecEnd: vEnd,
            collisionMask: this->m_pOuter->m_nAITraceMask,
            pTarget: nullptr,
            pctToCheckStandPositions: 100.0,
            flags: 0,
            pTrace: &moveTrace),
          moveTrace.fStatus < AIMR_OK)
      && (CAI_MoveProbe::MoveLimit(
            this: this->m_pOuter->m_pMoveProbe,
            a2: (int)&savedregs,
            navType: NAV_JUMP,
            vecStart: vEnd,
            vecEnd: vStart,
            collisionMask: this->m_pOuter->m_nAITraceMask,
            pTarget: nullptr,
            pctToCheckStandPositions: 100.0,
            flags: 0,
            pTrace: &moveTrace),
          moveTrace.fStatus < AIMR_OK) )
    {
      if ( (moveTypes & 8) == 0 )
        return false;
      memset(dst: (int)&moveTrace, value: nullptr, count: sizeof(moveTrace));
      CAI_MoveProbe::MoveLimit(
        this: this->m_pOuter->m_pMoveProbe,
        a2: (int)&savedregs,
        navType: NAV_CLIMB,
        vecStart: vStart,
        vecEnd: vEnd,
        collisionMask: this->m_pOuter->m_nAITraceMask,
        pTarget: nullptr,
        pctToCheckStandPositions: 100.0,
        flags: 0,
        pTrace: &moveTrace);
      if ( moveTrace.fStatus < AIMR_OK )
        return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076920
// Name: private: bool CAI_Pathfinder::IsLinkStillStale(int,class CAI_Link __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Pathfinder::IsLinkStillStale(CAI_Pathfinder *this, char moveType, CAI_Link *nodeLink)
{
  float curtime; // xmm0_4
  CAI_BaseNPC *m_pOuter; // ecx
  int m_eHull; // eax
  CAI_Network *m_pNetwork; // ecx
  int m_iDestID; // eax
  CAI_Node *v9; // eax
  int m_iSrcID; // edx
  Hull_t v11; // ebx
  CAI_Network *v12; // edi
  CAI_Node *v13; // edi
  const Vector *v14; // eax
  const Vector *Position; // [esp-10h] [ebp-30h]
  Vector v17; // [esp+4h] [ebp-1Ch] BYREF
  Vector v18; // [esp+10h] [ebp-10h] BYREF
  int hull; // [esp+1Ch] [ebp-4h]

  if ( this->m_bIgnoreStaleLinks || (nodeLink->m_LinkInfo & 1) == 0 )
    return 0;
  curtime = gpGlobals->curtime;
  if ( nodeLink->m_timeStaleExpires <= curtime && curtime != this->m_flLastStaleLinkCheckTime )
  {
    m_pOuter = this->m_pOuter;
    this->m_flLastStaleLinkCheckTime = curtime;
    m_eHull = m_pOuter->m_eHull;
    m_pNetwork = this->m_pNetwork;
    hull = m_eHull;
    m_iDestID = nodeLink->m_iDestID;
    if ( m_iDestID < 0 || m_iDestID >= m_pNetwork->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v9 = nullptr;
    }
    else
    {
      v9 = m_pNetwork->m_pAInode[m_iDestID];
    }
    m_iSrcID = nodeLink->m_iSrcID;
    v11 = this->m_pOuter->m_eHull;
    v12 = this->m_pNetwork;
    if ( m_iSrcID < 0 || m_iSrcID >= v12->m_iNumNodes )
    {
      ++`CAI_Network::GetNode'::`8'::warningCount;
      v13 = nullptr;
    }
    else
    {
      v13 = v12->m_pAInode[m_iSrcID];
    }
    Position = CAI_Node::GetPosition(this: v9, result: &v18, hull);
    v14 = CAI_Node::GetPosition(this: v13, result: &v17, hull: v11);
    if ( CAI_Pathfinder::CheckStaleRoute(this, vStart: v14, vEnd: Position, moveTypes: moveType) )
    {
      nodeLink->m_LinkInfo &= ~1u;
      return 0;
    }
    nodeLink->m_timeStaleExpires = gpGlobals->curtime + 1.0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10076A30
// Name: public: bool CAI_Pathfinder::IsLinkUsable(class CAI_Link __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Pathfinder::IsLinkUsable(CAI_Pathfinder *this, CAI_Link *pLink, int startID)
{
  CAI_Link *v3; // edx
  bool v4; // zf
  CAI_Pathfinder *v5; // ebx
  CAI_DynamicLink *m_pDynamicLink; // eax
  const char *pszValue; // esi
  CAI_BaseNPC *m_pOuter; // ecx
  __int16 m_iSrcID; // ax
  _DWORD *v12; // ecx
  int v13; // eax
  char v14; // cl
  int v15; // esi
  CAI_Network *m_pNetwork; // eax
  int v17; // esi
  int v18; // edx
  CAI_Network *v19; // eax
  CAI_Hint *m_pHint; // esi
  CAI_Hint *v21; // edi
  int m_nTargetNodeID; // esi
  _DWORD *v23; // edi
  int v24; // ebx
  Vector *v25; // eax
  Vector *v26; // [esp-Ch] [ebp-48h]
  Vector *Position; // [esp-8h] [ebp-44h]
  Vector v28; // [esp+8h] [ebp-34h] BYREF
  Vector v29; // [esp+14h] [ebp-28h] BYREF
  Vector v30; // [esp+20h] [ebp-1Ch] BYREF
  CAI_Pathfinder *v31; // [esp+2Ch] [ebp-10h]
  float *p_z; // [esp+30h] [ebp-Ch]
  int endID; // [esp+34h] [ebp-8h]
  CAI_Node *pStartNode; // [esp+38h] [ebp-4h]
  int linkMoveTypesa; // [esp+48h] [ebp+Ch]
  CAI_Node *linkMoveTypes; // [esp+48h] [ebp+Ch]

  v3 = pLink;
  v4 = (pLink->m_LinkInfo & 0x12) == 0;
  v5 = this;
  v31 = this;
  if ( !v4 )
  {
    m_pDynamicLink = pLink->m_pDynamicLink;
    if ( m_pDynamicLink == nullptr )
      return false;
    pszValue = m_pDynamicLink->m_strAllowUse.pszValue;
    if ( pszValue == nullptr )
      return false;
    m_pOuter = this->m_pOuter;
    if ( m_pDynamicLink->m_bInvertAllow )
    {
      if ( m_pOuter->m_iName.m_Value.pszValue == pszValue
        || CBaseEntity::NameMatchesComplex(this: m_pOuter, pszNameOrWildcard: m_pDynamicLink->m_strAllowUse.pszValue) != 0
        || CBaseEntity::ClassMatches(this: v5->m_pOuter, pszClassOrWildcard: pszValue) )
      {
        return false;
      }
    }
    else
    {
      if ( m_pOuter->m_iName.m_Value.pszValue == pszValue )
        goto LABEL_13;
      if ( CBaseEntity::NameMatchesComplex(this: m_pOuter, pszNameOrWildcard: m_pDynamicLink->m_strAllowUse.pszValue) == 0
        && !CBaseEntity::ClassMatches(this: v5->m_pOuter, pszClassOrWildcard: pszValue) )
      {
        return false;
      }
    }
    v3 = pLink;
  }
LABEL_13:
  m_iSrcID = v3->m_iSrcID;
  if ( startID == v3->m_iSrcID )
    m_iSrcID = v3->m_iDestID;
  v12 = &v5->m_pOuter->CAI_Component::__vftable;
  endID = m_iSrcID;
  linkMoveTypesa = v3->m_iAcceptedMoveTypes[v12[418]];
  v13 = (*(int (__thiscall **)(_DWORD *))(*v12 + 1916))(a1: v12);
  v14 = linkMoveTypesa;
  v15 = v13;
  m_pNetwork = v5->m_pNetwork;
  v17 = linkMoveTypesa & v15;
  if ( startID < 0 || startID >= m_pNetwork->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    pStartNode = nullptr;
  }
  else
  {
    pStartNode = m_pNetwork->m_pAInode[startID];
  }
  v18 = endID;
  v19 = v5->m_pNetwork;
  if ( endID < 0 || endID >= v19->m_iNumNodes )
  {
    ++`CAI_Network::GetNode'::`8'::warningCount;
    linkMoveTypes = nullptr;
  }
  else
  {
    linkMoveTypes = v19->m_pAInode[endID];
  }
  if ( (v14 & 2) != 0 )
  {
    if ( v17 == 0 )
    {
      m_pHint = pStartNode->m_pHint;
      v21 = linkMoveTypes->m_pHint;
      if ( m_pHint == nullptr
        || v21 == nullptr
        || m_pHint->m_NodeData.nHintType != 901
        || v21->m_NodeData.nHintType != 901 )
      {
        return false;
      }
      if ( ((m_pHint->m_spawnflags.m_Value | v21->m_spawnflags.m_Value) & 0x10000) == 0 )
      {
        p_z = &CBaseEntity::GetAbsOrigin(this: pStartNode->m_pHint)->z;
        if ( *p_z <= CBaseEntity::GetAbsOrigin(this: v21)->z )
          return false;
        v18 = endID;
      }
      if ( pStartNode->m_flNextUseTime > gpGlobals->curtime )
        return false;
      m_nTargetNodeID = m_pHint->m_nTargetNodeID;
      if ( m_nTargetNodeID != -1 && m_nTargetNodeID != v18 )
        return false;
      v17 = 2;
    }
  }
  else if ( v17 == 0 )
  {
    return false;
  }
  if ( v5->m_pOuter->IsUnusableNode(this: v5->m_pOuter, a2: v18, a3: linkMoveTypes->m_pHint) )
    return false;
  if ( v17 == 2 )
  {
    v23 = &v5->m_pOuter->CAI_Component::__vftable;
    v24 = v23[418];
    p_z = (float *)(*v23 + 1968);
    Position = CAI_Node::GetPosition(this: linkMoveTypes, result: &v30, hull: v24);
    v26 = CAI_Node::GetPosition(this: linkMoveTypes, result: &v29, hull: v24);
    v25 = CAI_Node::GetPosition(this: pStartNode, result: &v28, hull: v24);
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, Vector *, Vector *, Vector *))p_z)(
           a1: v23,
           a2: v25,
           a3: v26,
           a4: Position) != 0 )
    {
      v5 = v31;
      return (pLink->m_LinkInfo & 1) == 0
          || CAI_Pathfinder::IsLinkStillStale(this: v5, moveType: v17, nodeLink: pLink) == 0;
    }
    return false;
  }
  return (pLink->m_LinkInfo & 1) == 0 || CAI_Pathfinder::IsLinkStillStale(this: v5, moveType: v17, nodeLink: pLink) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10076D10
// Name: public: virtual struct AI_Waypoint_t __near * CAI_Pathfinder::FindBestPath(int,int)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__userpurge CAI_Pathfinder::FindBestPath@<eax>(
        CAI_Pathfinder *this@<ecx>,
        CAI_Node **a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int startID,
        int endID)
{
  CAI_Network *m_pNetwork; // eax
  bool v7; // zf
  int m_iNumNodes; // esi
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  unsigned int v13; // ecx
  CAI_Node **v14; // ecx
  Vector *Position; // esi
  Vector *v16; // eax
  float v17; // xmm1_4
  int *v18; // edx
  float v19; // xmm0_4
  __int128 v20; // xmm1
  int v21; // xmm0_4
  unsigned int *m_pInt; // esi
  int v23; // edx
  int v24; // eax
  int v25; // eax
  unsigned int *v26; // edx
  int BSSmallest; // esi
  CAI_Pathfinder *v29; // ecx
  CAI_Node *v30; // edi
  CAI_BaseNPC *m_pOuter; // ecx
  bool (__thiscall *IsUnusableNode)(CAI_BaseNPC *, int, CAI_Hint *); // eax
  bool v33; // cc
  CAI_Link *v34; // edi
  CAI_BaseNPC *v35; // ecx
  CAI_BaseNPC_vtbl *v36; // eax
  char v37; // al
  float *v38; // ecx
  __int16 m_iSrcID; // ax
  int v40; // edi
  double v41; // st7
  float v42; // xmm1_4
  int v43; // eax
  float v44; // xmm0_4
  int v45; // esi
  float v46; // xmm0_4
  float *v47; // edx
  Hull_t v48; // eax
  Vector *v49; // eax
  CAI_Node *v50; // ecx
  Vector *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm1_4
  float z; // xmm2_4
  float *v55; // eax
  float v56; // xmm0_4
  __int128 v57; // xmm1
  int v58; // eax
  AI_Waypoint_t *RouteFromParents; // esi
  float *m_eHull; // [esp-A4h] [ebp-B0h]
  CAI_Hint *m_pHint; // [esp-A4h] [ebp-B0h]
  int v62; // [esp-A0h] [ebp-ACh] BYREF
  int v63; // [esp-9Ch] [ebp-A8h]
  Vector v64; // [esp-90h] [ebp-9Ch] BYREF
  Vector v65; // [esp-84h] [ebp-90h] BYREF
  Vector v66; // [esp-78h] [ebp-84h] BYREF
  Vector v67; // [esp-6Ch] [ebp-78h] BYREF
  __int128 v68; // [esp-60h] [ebp-6Ch]
  float v69; // [esp-50h] [ebp-5Ch]
  int v70; // [esp-4Ch] [ebp-58h]
  int v71; // [esp-48h] [ebp-54h]
  int *v72; // [esp-44h] [ebp-50h]
  int *v73; // [esp-40h] [ebp-4Ch]
  CBitVecT<CVarBitVecBase<unsigned short> > v74; // [esp-3Ch] [ebp-48h] BYREF
  int v75; // [esp-30h] [ebp-3Ch]
  int v76; // [esp-2Ch] [ebp-38h]
  int v77; // [esp-28h] [ebp-34h]
  float *v78; // [esp-24h] [ebp-30h]
  CAI_Node *v79; // [esp-20h] [ebp-2Ch]
  CBitVecT<CVarBitVecBase<unsigned short> > v80; // [esp-1Ch] [ebp-28h] BYREF
  int *v81; // [esp-10h] [ebp-1Ch]
  CAI_Node **m_pAInode; // [esp-Ch] [ebp-18h]
  CAI_Pathfinder *v83; // [esp-8h] [ebp-14h]
  float *v84; // [esp-4h] [ebp-10h]
  CAI_Node **pAInode; // [esp+0h] [ebp-Ch] BYREF
  void *v86; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  pAInode = a2;
  v86 = retaddr;
  m_pNetwork = this->m_pNetwork;
  v7 = m_pNetwork->m_iNumNodes == 0;
  v63 = a4;
  v62 = a3;
  v83 = this;
  if ( v7 )
    return nullptr;
  m_iNumNodes = m_pNetwork->m_iNumNodes;
  m_pAInode = m_pNetwork->m_pAInode;
  v71 = m_iNumNodes;
  CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(this: &v80, numBits: m_iNumNodes);
  CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(this: &v74, numBits: m_iNumNodes);
  v9 = alloca(4 * m_iNumNodes);
  v81 = &v62;
  v10 = alloca(4 * m_iNumNodes);
  v72 = &v62;
  v11 = alloca(4 * m_iNumNodes);
  v78 = (float *)&v62;
  v12 = alloca(4 * m_iNumNodes);
  v73 = &v62;
  if ( m_iNumNodes > 0 )
  {
    v13 = (unsigned int)(4 * m_iNumNodes) >> 2;
    memset(&v62, 0xFFu, 4 * v13);
    memset32(v81, 2139095039, v13);
  }
  v14 = m_pAInode;
  m_eHull = (float *)v83->m_pOuter->m_eHull;
  v81[startID] = 0;
  v84 = m_eHull;
  Position = CAI_Node::GetPosition(this: v14[endID], result: &v67, hull: (int)m_eHull);
  v16 = CAI_Node::GetPosition(this: m_pAInode[startID], result: &v66, hull: (int)v84);
  v17 = v16->y - Position->y;
  v18 = v72;
  v19 = (float)((float)((float)(v16->x - Position->x) * (float)(v16->x - Position->x)) + (float)(v17 * v17))
      + (float)((float)(v16->z - Position->z) * (float)(v16->z - Position->z));
  v20 = 0;
  *(float *)&v20 = fsqrt(v19);
  v68 = v20;
  *(float *)&v21 = *(float *)&v20 * 0.1;
  v78[startID] = *(float *)&v21;
  m_pInt = v80.m_pInt;
  v18[startID] = v21;
  v23 = 1 << (startID & 0x1F);
  v24 = startID >> 5;
  m_pInt[v24] |= v23;
  v74.m_pInt[v24] |= v23;
  while ( 1 )
  {
    do
    {
LABEL_5:
      v80.m_pInt[v80.m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[v80.m_numBits & 0x1F];
      v25 = v80.m_numInts - 1;
      v26 = v80.m_pInt;
      if ( v80.m_numInts == 0 )
      {
LABEL_8:
        if ( v74.m_numInts > 1u )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v74.m_pInt);
          v26 = v80.m_pInt;
        }
        v74.m_pInt = nullptr;
        if ( v80.m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
        return nullptr;
      }
      while ( v80.m_pInt[v25] == 0 )
      {
        if ( --v25 < 0 )
          goto LABEL_8;
      }
      BSSmallest = CAI_Network::FindBSSmallest(bitString: (CVarBitVec *)&v80, float_array: v78, array_size: v71);
      v29 = v83;
      v75 = BSSmallest;
      v80.m_pInt[BSSmallest >> 5] &= ~(1 << (BSSmallest & 0x1F));
      v30 = m_pAInode[BSSmallest];
      m_pOuter = v29->m_pOuter;
      m_pHint = v30->m_pHint;
      IsUnusableNode = m_pOuter->IsUnusableNode;
      v79 = v30;
    }
    while ( IsUnusableNode(this: m_pOuter, a2: BSSmallest, a3: m_pHint) );
    if ( BSSmallest == endID )
      break;
    v33 = v30->m_Links.m_Size <= 0;
    v77 = 0;
    if ( !v33 )
    {
      while ( 1 )
      {
        v34 = v30->m_Links.m_Memory.m_pMemory[v77];
        v76 = (int)v34;
        if ( CAI_Pathfinder::IsLinkUsable(this: v83, pLink: v34, startID: BSSmallest) )
        {
          v35 = v83->m_pOuter;
          v36 = v35->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v84 = (float *)v35->m_eHull;
          v37 = ((int (__thiscall *)(CAI_BaseNPC *, int, int))v36->CapabilitiesGet)(a1: v35, a2: v62, a3: v63);
          v38 = (float *)(unsigned __int8)(v37 & v34->m_iAcceptedMoveTypes[(_DWORD)v84]);
          m_iSrcID = v34->m_iSrcID;
          v84 = v38;
          if ( BSSmallest == m_iSrcID )
            m_iSrcID = v34->m_iDestID;
          v40 = m_iSrcID;
          CAI_Node::GetPosition(this: v79, result: &v67, hull: v83->m_pOuter->m_eHull);
          CAI_Node::GetPosition(this: m_pAInode[v40], result: &v66, hull: v83->m_pOuter->m_eHull);
          v41 = CAI_Navigator::MovementCost(
                  this: v83->m_pOuter->m_pNavigator,
                  a2: COERCE_FLOAT(&pAInode),
                  a3: v40,
                  a4: BSSmallest,
                  moveType: (int)v84,
                  vecStart: &v67,
                  vecEnd: &v66);
          *(float *)&v84 = v41;
          if ( v41 != 3.4028235e38 )
          {
            v42 = *(float *)&v84;
            if ( (*(_BYTE *)(v76 + 16) & 8) != 0 )
              v42 = *(float *)&v84 + 512.0;
            v43 = *(_DWORD *)(v76 + 24);
            if ( v43 > 0 )
            {
              if ( v43 > 3 )
                goto LABEL_31;
              v42 = *((float *)&CAI_Pathfinder::m_DataMap.m_pOptimizedDataMap + v43) + v42;
            }
            v44 = *(float *)&v81[BSSmallest];
            v45 = v40 >> 5;
            v46 = v44 + v42;
            v69 = v46;
            v70 = 1 << (v40 & 0x1F);
            if ( (v70 & v74.m_pInt[v45]) == 0 || *(float *)&v81[v40] > v46 )
            {
              v47 = (float *)v81;
              v73[v40] = v75;
              v48 = v83->m_pOuter->m_eHull;
              v47[v40] = v46;
              v76 = v48;
              v49 = CAI_Node::GetPosition(this: m_pAInode[endID], result: &v64, hull: v48);
              v50 = m_pAInode[v40];
              v84 = (float *)v49;
              v51 = CAI_Node::GetPosition(this: v50, result: &v65, hull: v76);
              v52 = v51->x - *v84;
              v53 = v51->y - v84[1];
              z = v51->z;
              v55 = v78;
              v56 = (float)((float)(v52 * v52) + (float)(v53 * v53))
                  + (float)((float)(z - v84[2]) * (float)(z - v84[2]));
              v57 = 0;
              *(float *)&v57 = fsqrt(v56);
              v68 = v57;
              v72[v40] = v57;
              v55[v40] = *(float *)&v57 + v69;
              v58 = v70;
              v74.m_pInt[v45] |= v70;
              v80.m_pInt[v45] |= v58;
            }
            BSSmallest = v75;
          }
        }
LABEL_31:
        if ( ++v77 >= v79->m_Links.m_Size )
          goto LABEL_5;
        v30 = v79;
      }
    }
  }
  RouteFromParents = CAI_Pathfinder::MakeRouteFromParents(this: v83, parentArray: v73, endID);
  if ( v74.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v74.m_pInt);
  v74.m_pInt = nullptr;
  if ( v80.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v80.m_pInt);
  return RouteFromParents;
}

//------------------------------------------------------------------------------
// Address: 0x100771F0
// Name: public: struct AI_Waypoint_t __near * CAI_Pathfinder::FindShortRandomPath(int,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
AI_Waypoint_t *__userpurge CAI_Pathfinder::FindShortRandomPath@<eax>(
        CAI_Pathfinder *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int startID,
        float minPathLength,
        const Vector *directionIn)
{
  CAI_Network *m_pNetwork; // eax
  float v8; // edx
  CAI_Node **m_pAInode; // edi
  int v10; // esi
  CAI_BaseNPC *m_pOuter; // ecx
  void *v12; // esp
  float z; // ecx
  CAI_BaseNPC *v14; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v17; // xmm2_4
  float *p_m_iID; // eax
  int v19; // edi
  float *v20; // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  IUniformRandomStream_vtbl *v24; // eax
  int v25; // ecx
  float *v26; // ecx
  float *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  __int128 v30; // xmm0
  CAI_Node *v31; // ecx
  CAI_Node *v32; // ecx
  bool v33; // cc
  CAI_Link *ShuffeledLink; // eax
  __int16 m_iSrcID; // cx
  __int16 m_iDestID; // ax
  int v37; // edi
  int v38; // eax
  int v39; // eax
  AI_Waypoint_t *RouteFromParents; // esi
  AI_Waypoint_t *v42; // esi
  IMemAlloc *v43; // ecx
  AI_Waypoint_t *v44; // esi
  int v45; // [esp-170h] [ebp-17Ch] BYREF
  int v46; // [esp-16Ch] [ebp-178h]
  _DWORD v47[30]; // [esp-160h] [ebp-16Ch]
  _DWORD v48[30]; // [esp-E8h] [ebp-F4h]
  __int128 v49; // [esp-70h] [ebp-7Ch]
  CAI_Link *v50; // [esp-5Ch] [ebp-68h]
  Vector v51; // [esp-58h] [ebp-64h] BYREF
  int v52; // [esp-4Ch] [ebp-58h]
  int v53; // [esp-48h] [ebp-54h]
  Vector v54; // [esp-44h] [ebp-50h] BYREF
  int v55; // [esp-38h] [ebp-44h]
  float v56; // [esp-34h] [ebp-40h]
  float v57; // [esp-30h] [ebp-3Ch]
  float v58; // [esp-2Ch] [ebp-38h]
  float v59; // [esp-28h] [ebp-34h]
  float v60; // [esp-24h] [ebp-30h]
  int *v61; // [esp-20h] [ebp-2Ch]
  CAI_Node **v62; // [esp-1Ch] [ebp-28h]
  CAI_Pathfinder *v63; // [esp-18h] [ebp-24h]
  CBitVecT<CVarBitVecBase<unsigned short> > v64; // [esp-14h] [ebp-20h] BYREF
  int v65; // [esp-8h] [ebp-14h]
  int v66; // [esp-4h] [ebp-10h]
  int v67; // [esp+0h] [ebp-Ch]
  int numNeighbors; // [esp+4h] [ebp-8h]
  int retaddr; // [esp+Ch] [ebp+0h]

  v67 = a2;
  numNeighbors = retaddr;
  m_pNetwork = this->m_pNetwork;
  v8 = *(float *)&m_pNetwork->m_iNumNodes;
  v46 = a4;
  v45 = a3;
  m_pAInode = m_pNetwork->m_pAInode;
  v10 = -1;
  v63 = this;
  v65 = 1;
  v66 = 0;
  v57 = v8;
  v62 = m_pAInode;
  if ( v8 == 0.0 )
    return nullptr;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    m_pOuter->m_afMemory |= 8u;
  v12 = alloca(4 * LODWORD(v8));
  v61 = &v45;
  CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(this: &v64, numBits: SLODWORD(v57));
  z = directionIn->z;
  *(_QWORD *)&v54.x = *(_QWORD *)&directionIn->x;
  v54.z = z;
  if ( m_pAInode[startID]->m_Links.m_Size != 0 )
  {
    v61[startID] = -1;
    v48[0] = startID;
    v56 = 0.0;
    v53 = 0;
    while ( 1 )
    {
LABEL_6:
      if ( minPathLength <= v56 && (v10 == -1 || m_pAInode[v10]->m_eNodeType != NODE_CLIMB) )
      {
        RouteFromParents = CAI_Pathfinder::MakeRouteFromParents(this: v63, parentArray: v61, endID: v10);
        if ( v64.m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64.m_pInt);
        return RouteFromParents;
      }
      ++v53;
      if ( v10 != -1 && v65 == 0 && v66 == 0 )
      {
        if ( m_pAInode[v10]->m_eNodeType == NODE_CLIMB )
        {
          if ( v64.m_numInts <= 1u )
            return nullptr;
          ((void (__thiscall *)(IMemAlloc *, unsigned int *, int, int))_g_pMemAlloc->Free_2)(
            a1: _g_pMemAlloc,
            a2: v64.m_pInt,
            a3: v45,
            a4: v46);
          return nullptr;
        }
        else
        {
          v42 = CAI_Pathfinder::MakeRouteFromParents(this: v63, parentArray: v61, endID: v10);
          if ( v64.m_numInts > 1u )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64.m_pInt);
          return v42;
        }
      }
      v52 = v10;
      if ( vec3_origin.x == v54.x && vec3_origin.y == v54.y && vec3_origin.z == v54.z )
      {
        v24 = random->__vftable;
        if ( v65 != 0 )
          v10 = v48[((int (__stdcall *)(_DWORD, int))v24->RandomInt)(a1: 0, a2: v65 - 1)];
        else
          v10 = v47[((int (__stdcall *)(_DWORD, int))v24->RandomInt)(a1: 0, a2: v66 - 1)];
        goto LABEL_33;
      }
      v57 = -1.0;
      if ( v10 == -1 )
      {
        v14 = v63->m_pOuter;
        x = v14->m_vecOrigin.m_Value.x;
        y = v14->m_vecOrigin.m_Value.y;
        v17 = v14->m_vecOrigin.m_Value.z;
      }
      else
      {
        p_m_iID = (float *)&m_pAInode[v10]->m_iID;
        x = p_m_iID[1];
        y = p_m_iID[2];
        v17 = p_m_iID[3];
      }
      v60 = v17;
      v59 = y;
      v58 = x;
      if ( v65 != 0 )
      {
        v66 = 0;
        if ( v65 <= 0 )
          goto LABEL_28;
        while ( 1 )
        {
          v19 = v48[v66];
          v20 = (float *)&v62[v19]->m_iID;
          v51.x = x - v20[1];
          v51.y = y - v20[2];
          v51.z = v17 - v20[3];
          VectorNormalize(vec: &v51);
          if ( (float)((float)((float)(v51.y * v54.y) + (float)(v51.x * v54.x)) + (float)(v51.z * v54.z)) > v57 )
          {
            v57 = (float)((float)(v51.y * v54.y) + (float)(v51.x * v54.x)) + (float)(v51.z * v54.z);
            v10 = v19;
          }
          if ( ++v66 >= v65 )
            break;
          v17 = v60;
          y = v59;
          x = v58;
        }
        m_pAInode = v62;
      }
      else
      {
        v10 = v47[random->RandomInt(this: random, a2: 0, a3: v66 - 1)];
      }
      x = v58;
      y = v59;
      v17 = v60;
LABEL_28:
      if ( v10 != -1 )
      {
        v21 = (float *)&m_pAInode[v10]->m_iID;
        v22 = y - v21[2];
        v23 = v17 - v21[3];
        v54.x = x - v21[1];
        v54.y = v22;
        v54.z = v23;
        VectorNormalize(vec: &v54);
      }
LABEL_33:
      if ( v10 < 0 )
      {
        if ( v64.m_numInts <= 1u )
          return nullptr;
        v43 = _g_pMemAlloc;
LABEL_69:
        v43->Free_2(this: v43, a2: v64.m_pInt);
        return nullptr;
      }
      v61[v10] = v52;
      v25 = v52;
      v64.m_pInt[v10 >> 5] |= 1 << (v10 & 0x1F);
      if ( v25 != -1 )
      {
        v26 = (float *)&m_pAInode[v25]->m_iID;
        v27 = (float *)&m_pAInode[v10]->m_iID;
        v28 = v26[1] - v27[1];
        v29 = (float)((float)((float)(v26[2] - v27[2]) * (float)(v26[2] - v27[2]))
                    + (float)((float)(v26[3] - v27[3]) * (float)(v26[3] - v27[3])))
            + (float)(v28 * v28);
        v30 = 0;
        *(float *)&v30 = fsqrt(v29);
        v49 = v30;
        v56 = *(float *)&v30 + v56;
      }
      if ( (v56 >= minPathLength || v53 > 20) && m_pAInode[v10]->m_eNodeType != NODE_CLIMB )
      {
        v44 = CAI_Pathfinder::MakeRouteFromParents(this: v63, parentArray: v61, endID: v10);
        if ( v64.m_numInts > 1u )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64.m_pInt);
        return v44;
      }
      v31 = m_pAInode[v10];
      v65 = 0;
      v66 = 0;
      CAI_Node::ShuffleLinks(this: v31);
      v32 = m_pAInode[v10];
      v33 = v32->m_Links.m_Size <= 0;
      v55 = 0;
      if ( !v33 )
      {
        while ( v66 != 30 && v65 != 30 )
        {
          ShuffeledLink = CAI_Node::GetShuffeledLink(this: v32, nNum: v55);
          m_iSrcID = ShuffeledLink->m_iSrcID;
          v50 = ShuffeledLink;
          if ( v10 == m_iSrcID )
            m_iDestID = ShuffeledLink->m_iDestID;
          else
            m_iDestID = m_iSrcID;
          v37 = m_iDestID;
          if ( ((1 << (m_iDestID & 0x1F)) & v64.m_pInt[m_iDestID >> 5]) == 0
            && m_iDestID != v52
            && CAI_Pathfinder::IsLinkUsable(this: v63, pLink: v50, startID: v10) )
          {
            if ( v62[v37]->m_flNextUseTime <= gpGlobals->curtime )
            {
              v39 = v65;
              v48[v65] = v37;
              v65 = v39 + 1;
            }
            else
            {
              v38 = v66;
              v47[v66] = v37;
              v66 = v38 + 1;
            }
          }
          v32 = v62[v10];
          if ( ++v55 >= v32->m_Links.m_Size )
          {
            m_pAInode = v62;
            goto LABEL_6;
          }
        }
        break;
      }
    }
  }
  if ( v64.m_numInts > 1u )
  {
    v43 = _g_pMemAlloc;
    goto LABEL_69;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103FCB80
// Name: CAI_Pathfinder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Pathfinder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Pathfinder>(__formal: nullptr);
  CAI_Pathfinder_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FFD30
// Name: _dynamic_initializer_for__find_ent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__find_ent__()
{
  ConCommand::ConCommand(
    this: &find_ent,
    pName: "find_ent",
    callback: CC_Find_Ent,
    pHelpString: "Find and list all entities with classnames or targetnames that contain the specified substring.\n"
    "Format: find_ent <substring>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__find_ent__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFD60
// Name: _dynamic_initializer_for__find_ent_index__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__find_ent_index__()
{
  ConCommand::ConCommand(
    this: &find_ent_index,
    pName: "find_ent_index",
    callback: CC_Find_Ent_Index,
    pHelpString: "Display data for entity matching specified index.\nFormat: find_ent_index <index>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__find_ent_index__);
}

//------------------------------------------------------------------------------
// Address: 0x10419B80
// Name: _dynamic_atexit_destructor_for__find_ent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__find_ent__()
{
  ConCommand::~ConCommand(this: &find_ent);
}

//------------------------------------------------------------------------------
// Address: 0x10419B90
// Name: _dynamic_atexit_destructor_for__find_ent_index__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__find_ent_index__()
{
  ConCommand::~ConCommand(this: &find_ent_index);
}

//------------------------------------------------------------------------------
// Address: 0x10076C90
// Name: struct datamap_t __near * DataMapInit<class CAI_Pathfinder>(class CAI_Pathfinder __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Pathfinder>()
{
  if ( (_S2_27 & 1) == 0 )
  {
    _S2_27 |= 1u;
    nameHolder_56.m_pszBase = "CAI_Pathfinder";
    nameHolder_56.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_56.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_56.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_56.m_Names.m_Size = 0;
    nameHolder_56.m_Names.m_pElements = nullptr;
    nameHolder_56.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_Pathfinder__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Pathfinder::m_DataMap.baseMap = nullptr;
  CAI_Pathfinder::m_DataMap.dataNumFields = 1;
  CAI_Pathfinder::m_DataMap.dataDesc = &dataDesc_54[1];
  return &CAI_Pathfinder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FCB90
// Name: _dynamic_initializer_for__ai_no_local_paths__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_no_local_paths__()
{
  ConVar::ConVar(this: &ai_no_local_paths, pName: "ai_no_local_paths", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_no_local_paths__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCBC0
// Name: _dynamic_initializer_for__CAI_PlaneSolver::s_GlobalObstacles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_PlaneSolver::s_GlobalObstacles__()
{
  return atexit(func: dynamic_atexit_destructor_for__CAI_PlaneSolver::s_GlobalObstacles__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCBD0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg,
           fn: _CreateCServerGameTagsIServerGameTags_interface,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x103FCBF0
// Name: _dynamic_initializer_for__sk_ally_regen_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_ally_regen_time__()
{
  ConVar::ConVar(
    this: &sk_ally_regen_time,
    pName: "sk_ally_regen_time",
    pDefaultValue: "0.3003",
    flags: 0,
    pHelpString: "Time taken for an ally to regenerate a point of health.");
  return atexit(func: dynamic_atexit_destructor_for__sk_ally_regen_time__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCC20
// Name: _dynamic_initializer_for__sv_npc_talker_maxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_npc_talker_maxdist__()
{
  ConVar::ConVar(
    this: &sv_npc_talker_maxdist,
    pName: "sv_npc_talker_maxdist",
    pDefaultValue: "1024",
    flags: 0,
    pHelpString: "NPCs over this distance from the player won't attempt to speak.");
  return atexit(func: dynamic_atexit_destructor_for__sv_npc_talker_maxdist__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCC50
// Name: _dynamic_initializer_for__ai_no_talk_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_no_talk_delay__()
{
  ConVar::ConVar(this: &ai_no_talk_delay, pName: "ai_no_talk_delay", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_no_talk_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCC80
// Name: _dynamic_initializer_for__rr_debug_qa__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_debug_qa__()
{
  ConVar::ConVar(
    this: &rr_debug_qa,
    pName: "rr_debug_qa",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to see debug related to the Question & Answer system used to create conversations between allied NPCs.");
  return atexit(func: dynamic_atexit_destructor_for__rr_debug_qa__);
}

//------------------------------------------------------------------------------
// Address: 0x103FCCD0
// Name: _dynamic_initializer_for__g_ConceptInfos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ResponseRules::CRR_Concept *dynamic_initializer_for__g_ConceptInfos__()
{
  ResponseRules::CRR_Concept *result; // eax

  ResponseRules::CRR_Concept::CRR_Concept(this: &g_ConceptInfos, fromString: "TLK_ANSWER");
  unk_105DF64C = -1;
  unk_105DF650 = 1;
  unk_105DF654 = -1082130432;
  unk_105DF658 = -1082130432;
  unk_105DF65C = -1082130432;
  unk_105DF660 = -1082130432;
  unk_105DF664 = -1082130432;
  unk_105DF668 = -1082130432;
  unk_105DF66C = 16;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF670, fromString: "TLK_ANSWER_HELLO");
  unk_105DF674 = -1;
  unk_105DF678 = 1;
  unk_105DF67C = -1082130432;
  unk_105DF680 = -1082130432;
  unk_105DF684 = -1082130432;
  unk_105DF688 = -1082130432;
  unk_105DF68C = -1082130432;
  unk_105DF690 = -1082130432;
  unk_105DF694 = 16;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF698, fromString: "TLK_QUESTION");
  unk_105DF69C = -1;
  unk_105DF6A0 = 1;
  unk_105DF6A4 = -1082130432;
  unk_105DF6A8 = -1082130432;
  unk_105DF6AC = -1082130432;
  unk_105DF6B0 = -1082130432;
  unk_105DF6B4 = -1082130432;
  unk_105DF6B8 = -1082130432;
  unk_105DF6BC = 8;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF6C0, fromString: "TLK_IDLE");
  unk_105DF6C4 = -1;
  unk_105DF6C8 = 0;
  unk_105DF6CC = -1082130432;
  unk_105DF6D0 = -1082130432;
  unk_105DF6D4 = -1082130432;
  unk_105DF6D8 = -1082130432;
  unk_105DF6DC = -1082130432;
  unk_105DF6E0 = -1082130432;
  unk_105DF6E4 = 4;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF6E8, fromString: "TLK_STARE");
  unk_105DF6F4 = -1082130432;
  unk_105DF6F8 = -1082130432;
  unk_105DF6FC = -1082130432;
  unk_105DF700 = -1082130432;
  unk_105DF704 = 1127481344;
  unk_105DF6EC = -1;
  unk_105DF6F0 = 0;
  unk_105DF708 = 0;
  unk_105DF70C = 4;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF710, fromString: "TLK_LOOK");
  unk_105DF714 = -1;
  unk_105DF718 = 2;
  unk_105DF71C = -1082130432;
  unk_105DF720 = -1082130432;
  unk_105DF724 = -1082130432;
  unk_105DF728 = -1082130432;
  unk_105DF72C = -1082130432;
  unk_105DF730 = -1082130432;
  unk_105DF734 = 4;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF738, fromString: "TLK_HELLO");
  unk_105DF744 = 1084227584;
  unk_105DF748 = 1092616192;
  unk_105DF73C = -1;
  unk_105DF740 = 0;
  unk_105DF74C = -1082130432;
  unk_105DF750 = -1082130432;
  unk_105DF754 = -1082130432;
  unk_105DF758 = -1082130432;
  unk_105DF75C = 7;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF760, fromString: "TLK_PHELLO");
  unk_105DF764 = -1;
  unk_105DF768 = 0;
  unk_105DF76C = -1082130432;
  unk_105DF770 = -1082130432;
  unk_105DF774 = -1082130432;
  unk_105DF778 = -1082130432;
  unk_105DF77C = -1082130432;
  unk_105DF780 = -1082130432;
  unk_105DF784 = 7;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF788, fromString: "TLK_HELLO_NPC");
  unk_105DF794 = 1084227584;
  unk_105DF798 = 1092616192;
  unk_105DF78C = -1;
  unk_105DF790 = 0;
  unk_105DF79C = -1082130432;
  unk_105DF7A0 = -1082130432;
  unk_105DF7A4 = -1082130432;
  unk_105DF7A8 = -1082130432;
  unk_105DF7AC = 9;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF7B0, fromString: "TLK_PIDLE");
  unk_105DF7B4 = -1;
  unk_105DF7B8 = 0;
  unk_105DF7BC = -1082130432;
  unk_105DF7C0 = -1082130432;
  unk_105DF7C4 = -1082130432;
  unk_105DF7C8 = -1082130432;
  unk_105DF7CC = -1082130432;
  unk_105DF7D0 = -1082130432;
  unk_105DF7D4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF7D8, fromString: "TLK_PQUESTION");
  unk_105DF7DC = -1;
  unk_105DF7E0 = 0;
  unk_105DF7E4 = -1082130432;
  unk_105DF7E8 = -1082130432;
  unk_105DF7EC = -1082130432;
  unk_105DF7F0 = -1082130432;
  unk_105DF7F4 = -1082130432;
  unk_105DF7F8 = -1082130432;
  unk_105DF7FC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF800, fromString: "TLK_SMELL");
  unk_105DF804 = -1;
  unk_105DF808 = 0;
  unk_105DF80C = -1082130432;
  unk_105DF810 = -1082130432;
  unk_105DF814 = -1082130432;
  unk_105DF818 = -1082130432;
  unk_105DF81C = -1082130432;
  unk_105DF820 = -1082130432;
  unk_105DF824 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF828, fromString: "TLK_USE");
  unk_105DF82C = -1;
  unk_105DF830 = 1;
  unk_105DF834 = -1082130432;
  unk_105DF838 = -1082130432;
  unk_105DF83C = -1082130432;
  unk_105DF840 = -1082130432;
  unk_105DF844 = -1082130432;
  unk_105DF848 = -1082130432;
  unk_105DF84C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF850, fromString: "TLK_STARTFOLLOW");
  unk_105DF854 = -1;
  unk_105DF858 = 1;
  unk_105DF85C = -1082130432;
  unk_105DF860 = -1082130432;
  unk_105DF864 = -1082130432;
  unk_105DF868 = -1082130432;
  unk_105DF86C = -1082130432;
  unk_105DF870 = -1082130432;
  unk_105DF874 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF878, fromString: "TLK_STOPFOLLOW");
  unk_105DF87C = -1;
  unk_105DF880 = 1;
  unk_105DF884 = -1082130432;
  unk_105DF888 = -1082130432;
  unk_105DF88C = -1082130432;
  unk_105DF890 = -1082130432;
  unk_105DF894 = -1082130432;
  unk_105DF898 = -1082130432;
  unk_105DF89C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF8A0, fromString: "TLK_JOINPLAYER");
  unk_105DF8A4 = -1;
  unk_105DF8A8 = 1;
  unk_105DF8AC = -1082130432;
  unk_105DF8B0 = -1082130432;
  unk_105DF8B4 = -1082130432;
  unk_105DF8B8 = -1082130432;
  unk_105DF8BC = -1082130432;
  unk_105DF8C0 = -1082130432;
  unk_105DF8C4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF8C8, fromString: "TLK_STOP");
  unk_105DF8CC = -1;
  unk_105DF8D0 = 1;
  unk_105DF8D4 = -1082130432;
  unk_105DF8D8 = -1082130432;
  unk_105DF8DC = -1082130432;
  unk_105DF8E0 = -1082130432;
  unk_105DF8E4 = -1082130432;
  unk_105DF8E8 = -1082130432;
  unk_105DF8EC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF8F0, fromString: "TLK_NOSHOOT");
  unk_105DF8F4 = -1;
  unk_105DF8F8 = 1;
  unk_105DF8FC = -1082130432;
  unk_105DF900 = -1082130432;
  unk_105DF904 = -1082130432;
  unk_105DF908 = -1082130432;
  unk_105DF90C = -1082130432;
  unk_105DF910 = -1082130432;
  unk_105DF914 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF918, fromString: "TLK_PLHURT1");
  unk_105DF91C = -1;
  unk_105DF920 = 1;
  unk_105DF924 = -1082130432;
  unk_105DF928 = -1082130432;
  unk_105DF92C = -1082130432;
  unk_105DF930 = -1082130432;
  unk_105DF934 = -1082130432;
  unk_105DF938 = -1082130432;
  unk_105DF93C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF940, fromString: "TLK_PLHURT2");
  unk_105DF944 = -1;
  unk_105DF948 = 1;
  unk_105DF94C = -1082130432;
  unk_105DF950 = -1082130432;
  unk_105DF954 = -1082130432;
  unk_105DF958 = -1082130432;
  unk_105DF95C = -1082130432;
  unk_105DF960 = -1082130432;
  unk_105DF964 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF968, fromString: "TLK_PLHURT3");
  unk_105DF96C = -1;
  unk_105DF970 = 1;
  unk_105DF974 = -1082130432;
  unk_105DF978 = -1082130432;
  unk_105DF97C = -1082130432;
  unk_105DF980 = -1082130432;
  unk_105DF984 = -1082130432;
  unk_105DF988 = -1082130432;
  unk_105DF98C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF990, fromString: "TLK_PLHURT");
  unk_105DF994 = -1;
  unk_105DF998 = 1;
  unk_105DF99C = -1082130432;
  unk_105DF9A0 = -1082130432;
  unk_105DF9A4 = -1082130432;
  unk_105DF9A8 = -1082130432;
  unk_105DF9AC = -1082130432;
  unk_105DF9B0 = -1082130432;
  unk_105DF9B4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF9B8, fromString: "TLK_PLPUSH");
  unk_105DF9C4 = -1082130432;
  unk_105DF9C8 = -1082130432;
  unk_105DF9CC = -1082130432;
  unk_105DF9D0 = -1082130432;
  unk_105DF9D4 = 1097859072;
  unk_105DF9BC = -1;
  unk_105DF9C0 = 1;
  unk_105DF9D8 = 1106247680;
  unk_105DF9DC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DF9E0, fromString: "TLK_PLRELOAD");
  unk_105DF9E4 = -1;
  unk_105DF9E8 = 1;
  unk_105DF9EC = -1082130432;
  unk_105DF9F0 = -1082130432;
  unk_105DF9F4 = -1082130432;
  unk_105DF9F8 = -1082130432;
  unk_105DF9FC = 1114636288;
  unk_105DFA00 = 0;
  unk_105DFA04 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFA08, fromString: "TLK_SHOT");
  unk_105DFA0C = -1;
  unk_105DFA10 = 1;
  unk_105DFA14 = -1082130432;
  unk_105DFA18 = -1082130432;
  unk_105DFA1C = -1082130432;
  unk_105DFA20 = -1082130432;
  unk_105DFA24 = -1082130432;
  unk_105DFA28 = -1082130432;
  unk_105DFA2C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFA30, fromString: "TLK_WOUND");
  unk_105DFA34 = -1;
  unk_105DFA38 = 1;
  unk_105DFA3C = -1082130432;
  unk_105DFA40 = -1082130432;
  unk_105DFA44 = -1082130432;
  unk_105DFA48 = -1082130432;
  unk_105DFA4C = -1082130432;
  unk_105DFA50 = -1082130432;
  unk_105DFA54 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFA58, fromString: "TLK_MORTAL");
  unk_105DFA5C = -1;
  unk_105DFA60 = 1;
  unk_105DFA64 = -1082130432;
  unk_105DFA68 = -1082130432;
  unk_105DFA6C = -1082130432;
  unk_105DFA70 = -1082130432;
  unk_105DFA74 = -1082130432;
  unk_105DFA78 = -1082130432;
  unk_105DFA7C = 1;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFA80, fromString: "TLK_SEE_COMBINE");
  unk_105DFA84 = -1;
  unk_105DFA88 = 1;
  unk_105DFA8C = -1082130432;
  unk_105DFA90 = -1082130432;
  unk_105DFA94 = -1082130432;
  unk_105DFA98 = -1082130432;
  unk_105DFA9C = -1082130432;
  unk_105DFAA0 = -1082130432;
  unk_105DFAA4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFAA8, fromString: "TLK_ENEMY_DEAD");
  unk_105DFAAC = -1;
  unk_105DFAB0 = 1;
  unk_105DFAB4 = -1082130432;
  unk_105DFAB8 = -1082130432;
  unk_105DFABC = -1082130432;
  unk_105DFAC0 = -1082130432;
  unk_105DFAC4 = -1082130432;
  unk_105DFAC8 = -1082130432;
  unk_105DFACC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFAD0, fromString: "TLK_ALYX_ENEMY_DEAD");
  unk_105DFAD4 = -1;
  unk_105DFAD8 = 1;
  unk_105DFADC = -1082130432;
  unk_105DFAE0 = -1082130432;
  unk_105DFAE4 = -1082130432;
  unk_105DFAE8 = -1082130432;
  unk_105DFAEC = -1082130432;
  unk_105DFAF0 = -1082130432;
  unk_105DFAF4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFAF8, fromString: "TLK_SELECTED");
  unk_105DFAFC = -1;
  unk_105DFB00 = 1;
  unk_105DFB04 = -1082130432;
  unk_105DFB08 = -1082130432;
  unk_105DFB0C = -1082130432;
  unk_105DFB10 = -1082130432;
  unk_105DFB14 = -1082130432;
  unk_105DFB18 = -1082130432;
  unk_105DFB1C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFB20, fromString: "TLK_COMMANDED");
  unk_105DFB24 = -1;
  unk_105DFB28 = 1;
  unk_105DFB2C = -1082130432;
  unk_105DFB30 = -1082130432;
  unk_105DFB34 = -1082130432;
  unk_105DFB38 = -1082130432;
  unk_105DFB3C = -1082130432;
  unk_105DFB40 = -1082130432;
  unk_105DFB44 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFB48, fromString: "TLK_COMMAND_FAILED");
  unk_105DFB4C = -1;
  unk_105DFB50 = 1;
  unk_105DFB54 = -1082130432;
  unk_105DFB58 = -1082130432;
  unk_105DFB5C = -1082130432;
  unk_105DFB60 = -1082130432;
  unk_105DFB64 = -1082130432;
  unk_105DFB68 = -1082130432;
  unk_105DFB6C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFB70, fromString: "TLK_DENY_COMMAND");
  unk_105DFB74 = -1;
  unk_105DFB78 = 1;
  unk_105DFB7C = -1082130432;
  unk_105DFB80 = -1082130432;
  unk_105DFB84 = -1082130432;
  unk_105DFB88 = -1082130432;
  unk_105DFB8C = -1082130432;
  unk_105DFB90 = -1082130432;
  unk_105DFB94 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFB98, fromString: "TLK_BETRAYED");
  unk_105DFB9C = -1;
  unk_105DFBA0 = 1;
  unk_105DFBA4 = -1082130432;
  unk_105DFBA8 = -1082130432;
  unk_105DFBAC = -1082130432;
  unk_105DFBB0 = -1082130432;
  unk_105DFBB4 = -1082130432;
  unk_105DFBB8 = -1082130432;
  unk_105DFBBC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFBC0, fromString: "TLK_ALLY_KILLED");
  unk_105DFBCC = -1082130432;
  unk_105DFBD0 = -1082130432;
  unk_105DFBD4 = -1082130432;
  unk_105DFBD8 = -1082130432;
  unk_105DFBDC = 1097859072;
  unk_105DFBC4 = -1;
  unk_105DFBC8 = 1;
  unk_105DFBE0 = 1106247680;
  unk_105DFBE4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFBE8, fromString: "TLK_ATTACKING");
  unk_105DFBEC = -1;
  unk_105DFBF0 = 1;
  unk_105DFBF4 = -1082130432;
  unk_105DFBF8 = -1082130432;
  unk_105DFBFC = -1082130432;
  unk_105DFC00 = -1082130432;
  unk_105DFC04 = -1082130432;
  unk_105DFC08 = -1082130432;
  unk_105DFC0C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFC10, fromString: "TLK_HEAL");
  unk_105DFC14 = -1;
  unk_105DFC18 = 1;
  unk_105DFC1C = -1082130432;
  unk_105DFC20 = -1082130432;
  unk_105DFC24 = -1082130432;
  unk_105DFC28 = -1082130432;
  unk_105DFC2C = -1082130432;
  unk_105DFC30 = -1082130432;
  unk_105DFC34 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFC38, fromString: "TLK_GIVEAMMO");
  unk_105DFC3C = -1;
  unk_105DFC40 = 1;
  unk_105DFC44 = -1082130432;
  unk_105DFC48 = -1082130432;
  unk_105DFC4C = -1082130432;
  unk_105DFC50 = -1082130432;
  unk_105DFC54 = -1082130432;
  unk_105DFC58 = -1082130432;
  unk_105DFC5C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFC60, fromString: "TLK_HELP_ME");
  unk_105DFC6C = -1082130432;
  unk_105DFC70 = -1082130432;
  unk_105DFC74 = -1082130432;
  unk_105DFC78 = -1082130432;
  unk_105DFC7C = 1088421888;
  unk_105DFC64 = -1;
  unk_105DFC68 = 1;
  unk_105DFC80 = 1092616192;
  unk_105DFC84 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFC88, fromString: "TLK_PLYR_PHYSATK");
  unk_105DFC8C = -1;
  unk_105DFC90 = 1;
  unk_105DFC94 = -1082130432;
  unk_105DFC98 = -1082130432;
  unk_105DFC9C = -1082130432;
  unk_105DFCA0 = -1082130432;
  unk_105DFCA4 = -1082130432;
  unk_105DFCA8 = -1082130432;
  unk_105DFCAC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFCB0, fromString: "TLK_NEWWEAPON");
  unk_105DFCB4 = -1;
  unk_105DFCB8 = 1;
  unk_105DFCBC = -1082130432;
  unk_105DFCC0 = -1082130432;
  unk_105DFCC4 = -1082130432;
  unk_105DFCC8 = -1082130432;
  unk_105DFCCC = -1082130432;
  unk_105DFCD0 = -1082130432;
  unk_105DFCD4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFCD8, fromString: "TLK_STARTCOMBAT");
  unk_105DFCE4 = -1082130432;
  unk_105DFCE8 = -1082130432;
  unk_105DFCEC = -1082130432;
  unk_105DFCF0 = -1082130432;
  unk_105DFCF4 = 1106247680;
  unk_105DFCDC = -1;
  unk_105DFCE0 = 1;
  unk_105DFCF8 = 0;
  unk_105DFCFC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFD00, fromString: "TLK_WATCHOUT");
  unk_105DFD0C = -1082130432;
  unk_105DFD10 = -1082130432;
  unk_105DFD14 = -1082130432;
  unk_105DFD18 = -1082130432;
  unk_105DFD1C = 1106247680;
  unk_105DFD04 = -1;
  unk_105DFD08 = 1;
  unk_105DFD20 = 1110704128;
  unk_105DFD24 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFD28, fromString: "TLK_MOBBED");
  unk_105DFD34 = -1082130432;
  unk_105DFD38 = -1082130432;
  unk_105DFD3C = -1082130432;
  unk_105DFD40 = -1082130432;
  unk_105DFD44 = 1092616192;
  unk_105DFD2C = -1;
  unk_105DFD30 = 1;
  unk_105DFD48 = 1094713344;
  unk_105DFD4C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFD50, fromString: "TLK_MANY_ENEMIES");
  unk_105DFD5C = -1082130432;
  unk_105DFD60 = -1082130432;
  unk_105DFD64 = -1082130432;
  unk_105DFD68 = -1082130432;
  unk_105DFD6C = 1110704128;
  unk_105DFD54 = -1;
  unk_105DFD58 = 1;
  unk_105DFD70 = 1114636288;
  unk_105DFD74 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFD78, fromString: "TLK_DANGER");
  unk_105DFD84 = -1082130432;
  unk_105DFD88 = -1082130432;
  unk_105DFD8C = -1082130432;
  unk_105DFD90 = -1082130432;
  unk_105DFD94 = 1084227584;
  unk_105DFD7C = -1;
  unk_105DFD80 = 2;
  unk_105DFD98 = 1088421888;
  unk_105DFD9C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFDA0, fromString: "TLK_PLDEAD");
  unk_105DFDA4 = -1;
  unk_105DFDA8 = 2;
  unk_105DFDAC = -1082130432;
  unk_105DFDB0 = -1082130432;
  unk_105DFDB4 = -1082130432;
  unk_105DFDB8 = -1082130432;
  unk_105DFDBC = 1120403456;
  unk_105DFDC0 = 0;
  unk_105DFDC4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFDC8, fromString: "TLK_HIDEANDRELOAD");
  unk_105DFDD4 = -1082130432;
  unk_105DFDD8 = -1082130432;
  unk_105DFDDC = -1082130432;
  unk_105DFDE0 = -1082130432;
  unk_105DFDE4 = 1110704128;
  unk_105DFDCC = -1;
  unk_105DFDD0 = 2;
  unk_105DFDE8 = 1114636288;
  unk_105DFDEC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFDF0, fromString: "TLK_FLASHLIGHT_ILLUM");
  unk_105DFDF4 = -1;
  unk_105DFDF8 = 2;
  unk_105DFDFC = -1082130432;
  unk_105DFE00 = -1082130432;
  unk_105DFE04 = -1082130432;
  unk_105DFE08 = -1082130432;
  unk_105DFE0C = -1082130432;
  unk_105DFE10 = -1082130432;
  unk_105DFE14 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFE18, fromString: "TLK_FLASHLIGHT_ON");
  unk_105DFE1C = -1;
  unk_105DFE20 = 2;
  unk_105DFE24 = -1082130432;
  unk_105DFE28 = -1082130432;
  unk_105DFE2C = -1082130432;
  unk_105DFE30 = -1082130432;
  unk_105DFE34 = -1082130432;
  unk_105DFE38 = -1082130432;
  unk_105DFE3C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFE40, fromString: "TLK_FLASHLIGHT_OFF");
  unk_105DFE44 = -1;
  unk_105DFE48 = 2;
  unk_105DFE4C = -1082130432;
  unk_105DFE50 = -1082130432;
  unk_105DFE54 = -1082130432;
  unk_105DFE58 = -1082130432;
  unk_105DFE5C = -1082130432;
  unk_105DFE60 = -1082130432;
  unk_105DFE64 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFE68, fromString: "TLK_FOUNDPLAYER");
  unk_105DFE6C = -1;
  unk_105DFE70 = 1;
  unk_105DFE74 = -1082130432;
  unk_105DFE78 = -1082130432;
  unk_105DFE7C = -1082130432;
  unk_105DFE80 = -1082130432;
  unk_105DFE84 = -1082130432;
  unk_105DFE88 = -1082130432;
  unk_105DFE8C = 4;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFE90, fromString: "TLK_PLAYER_KILLED_NPC");
  unk_105DFE94 = -1;
  unk_105DFE98 = 1;
  unk_105DFE9C = -1082130432;
  unk_105DFEA0 = -1082130432;
  unk_105DFEA4 = -1082130432;
  unk_105DFEA8 = -1082130432;
  unk_105DFEAC = -1082130432;
  unk_105DFEB0 = -1082130432;
  unk_105DFEB4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFEB8, fromString: "TLK_ENEMY_BURNING");
  unk_105DFEBC = -1;
  unk_105DFEC0 = 1;
  unk_105DFEC4 = -1082130432;
  unk_105DFEC8 = -1082130432;
  unk_105DFECC = -1082130432;
  unk_105DFED0 = -1082130432;
  unk_105DFED4 = -1082130432;
  unk_105DFED8 = -1082130432;
  unk_105DFEDC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFEE0, fromString: "TLK_SPOTTED_ZOMBIE_WAKEUP");
  unk_105DFEE4 = -1;
  unk_105DFEE8 = 1;
  unk_105DFEEC = -1082130432;
  unk_105DFEF0 = -1082130432;
  unk_105DFEF4 = -1082130432;
  unk_105DFEF8 = -1082130432;
  unk_105DFEFC = -1082130432;
  unk_105DFF00 = -1082130432;
  unk_105DFF04 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFF08, fromString: "TLK_SPOTTED_HEADCRAB_LEAVING_ZOMBIE");
  unk_105DFF0C = -1;
  unk_105DFF10 = 1;
  unk_105DFF14 = -1082130432;
  unk_105DFF18 = -1082130432;
  unk_105DFF1C = -1082130432;
  unk_105DFF20 = -1082130432;
  unk_105DFF24 = -1082130432;
  unk_105DFF28 = -1082130432;
  unk_105DFF2C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFF30, fromString: "TLK_DANGER_ZOMBINE_GRENADE");
  unk_105DFF34 = -1;
  unk_105DFF38 = 1;
  unk_105DFF3C = -1082130432;
  unk_105DFF40 = -1082130432;
  unk_105DFF44 = -1082130432;
  unk_105DFF48 = -1082130432;
  unk_105DFF4C = -1082130432;
  unk_105DFF50 = -1082130432;
  unk_105DFF54 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFF58, fromString: "TLK_BALLSOCKETED");
  unk_105DFF5C = -1;
  unk_105DFF60 = 1;
  unk_105DFF64 = -1082130432;
  unk_105DFF68 = -1082130432;
  unk_105DFF6C = -1082130432;
  unk_105DFF70 = -1082130432;
  unk_105DFF74 = -1082130432;
  unk_105DFF78 = -1082130432;
  unk_105DFF7C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFF80, fromString: "TLK_DARKNESS_LOSTPLAYER");
  unk_105DFF84 = -1;
  unk_105DFF88 = 1;
  unk_105DFF8C = -1082130432;
  unk_105DFF90 = -1082130432;
  unk_105DFF94 = -1082130432;
  unk_105DFF98 = -1082130432;
  unk_105DFF9C = -1082130432;
  unk_105DFFA0 = -1082130432;
  unk_105DFFA4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFFA8, fromString: "TLK_DARKNESS_FOUNDPLAYER");
  unk_105DFFAC = -1;
  unk_105DFFB0 = 1;
  unk_105DFFB4 = -1082130432;
  unk_105DFFB8 = -1082130432;
  unk_105DFFBC = -1082130432;
  unk_105DFFC0 = -1082130432;
  unk_105DFFC4 = -1082130432;
  unk_105DFFC8 = -1082130432;
  unk_105DFFCC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFFD0, fromString: "TLK_DARKNESS_UNKNOWN_WOUND");
  unk_105DFFD4 = -1;
  unk_105DFFD8 = 1;
  unk_105DFFDC = -1082130432;
  unk_105DFFE0 = -1082130432;
  unk_105DFFE4 = -1082130432;
  unk_105DFFE8 = -1082130432;
  unk_105DFFEC = -1082130432;
  unk_105DFFF0 = -1082130432;
  unk_105DFFF4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105DFFF8, fromString: "TLK_DARKNESS_HEARDSOUND");
  unk_105E0004 = -1082130432;
  unk_105E0008 = -1082130432;
  unk_105E000C = -1082130432;
  unk_105E0010 = -1082130432;
  unk_105E0014 = 1101004800;
  unk_105DFFFC = -1;
  unk_105E0000 = 1;
  unk_105E0018 = 1106247680;
  unk_105E001C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0020, fromString: "TLK_DARKNESS_LOSTENEMY_BY_FLASHLIGHT");
  unk_105E0024 = -1;
  unk_105E0028 = 1;
  unk_105E002C = -1082130432;
  unk_105E0030 = -1082130432;
  unk_105E0034 = -1082130432;
  unk_105E0038 = -1082130432;
  unk_105E003C = -1082130432;
  unk_105E0040 = -1082130432;
  unk_105E0044 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(
    this: &stru_105E0048,
    fromString: "TLK_DARKNESS_LOSTENEMY_BY_FLASHLIGHT_EXPIRED");
  unk_105E004C = -1;
  unk_105E0050 = 1;
  unk_105E0054 = -1082130432;
  unk_105E0058 = -1082130432;
  unk_105E005C = -1082130432;
  unk_105E0060 = -1082130432;
  unk_105E0064 = -1082130432;
  unk_105E0068 = -1082130432;
  unk_105E006C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0070, fromString: "TLK_DARKNESS_FOUNDENEMY_BY_FLASHLIGHT");
  unk_105E0074 = -1;
  unk_105E0078 = 1;
  unk_105E007C = -1082130432;
  unk_105E0080 = -1082130432;
  unk_105E0084 = -1082130432;
  unk_105E0088 = -1082130432;
  unk_105E008C = -1082130432;
  unk_105E0090 = -1082130432;
  unk_105E0094 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0098, fromString: "TLK_DARKNESS_FLASHLIGHT_EXPIRED");
  unk_105E009C = -1;
  unk_105E00A0 = 1;
  unk_105E00A4 = -1082130432;
  unk_105E00A8 = -1082130432;
  unk_105E00AC = -1082130432;
  unk_105E00B0 = -1082130432;
  unk_105E00B4 = -1082130432;
  unk_105E00B8 = -1082130432;
  unk_105E00BC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E00C0, fromString: "TLK_SPOTTED_INCOMING_HEADCRAB");
  unk_105E00C4 = -1;
  unk_105E00C8 = 1;
  unk_105E00CC = -1082130432;
  unk_105E00D0 = -1082130432;
  unk_105E00D4 = -1082130432;
  unk_105E00D8 = -1082130432;
  unk_105E00DC = -1082130432;
  unk_105E00E0 = -1082130432;
  unk_105E00E4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E00E8, fromString: "TLK_LEAD_START");
  unk_105E00EC = -1;
  unk_105E00F0 = 1;
  unk_105E00F4 = -1082130432;
  unk_105E00F8 = -1082130432;
  unk_105E00FC = -1082130432;
  unk_105E0100 = -1082130432;
  unk_105E0104 = -1082130432;
  unk_105E0108 = -1082130432;
  unk_105E010C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0110, fromString: "TLK_LEAD_ARRIVAL");
  unk_105E0114 = -1;
  unk_105E0118 = 1;
  unk_105E011C = -1082130432;
  unk_105E0120 = -1082130432;
  unk_105E0124 = -1082130432;
  unk_105E0128 = -1082130432;
  unk_105E012C = -1082130432;
  unk_105E0130 = -1082130432;
  unk_105E0134 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0138, fromString: "TLK_LEAD_SUCCESS");
  unk_105E013C = -1;
  unk_105E0140 = 1;
  unk_105E0144 = -1082130432;
  unk_105E0148 = -1082130432;
  unk_105E014C = -1082130432;
  unk_105E0150 = -1082130432;
  unk_105E0154 = -1082130432;
  unk_105E0158 = -1082130432;
  unk_105E015C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0160, fromString: "lead_fail");
  unk_105E0164 = -1;
  unk_105E0168 = 1;
  unk_105E016C = -1082130432;
  unk_105E0170 = -1082130432;
  unk_105E0174 = -1082130432;
  unk_105E0178 = -1082130432;
  unk_105E017C = -1082130432;
  unk_105E0180 = -1082130432;
  unk_105E0184 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0188, fromString: "TLK_LEAD_COMINGBACK");
  unk_105E018C = -1;
  unk_105E0190 = 1;
  unk_105E0194 = -1082130432;
  unk_105E0198 = -1082130432;
  unk_105E019C = -1082130432;
  unk_105E01A0 = -1082130432;
  unk_105E01A4 = -1082130432;
  unk_105E01A8 = -1082130432;
  unk_105E01AC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E01B0, fromString: "TLK_LEAD_CATCHUP");
  unk_105E01B4 = -1;
  unk_105E01B8 = 1;
  unk_105E01BC = -1082130432;
  unk_105E01C0 = -1082130432;
  unk_105E01C4 = -1082130432;
  unk_105E01C8 = -1082130432;
  unk_105E01CC = -1082130432;
  unk_105E01D0 = -1082130432;
  unk_105E01D4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E01D8, fromString: "TLK_LEAD_RETRIEVE");
  unk_105E01DC = -1;
  unk_105E01E0 = 1;
  unk_105E01E4 = -1082130432;
  unk_105E01E8 = -1082130432;
  unk_105E01EC = -1082130432;
  unk_105E01F0 = -1082130432;
  unk_105E01F4 = -1082130432;
  unk_105E01F8 = -1082130432;
  unk_105E01FC = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0200, fromString: "TLK_LEAD_ATTRACTPLAYER");
  unk_105E0204 = -1;
  unk_105E0208 = 1;
  unk_105E020C = -1082130432;
  unk_105E0210 = -1082130432;
  unk_105E0214 = -1082130432;
  unk_105E0218 = -1082130432;
  unk_105E021C = -1082130432;
  unk_105E0220 = -1082130432;
  unk_105E0224 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0228, fromString: "TLK_LEAD_WAITOVER");
  unk_105E022C = -1;
  unk_105E0230 = 1;
  unk_105E0234 = -1082130432;
  unk_105E0238 = -1082130432;
  unk_105E023C = -1082130432;
  unk_105E0240 = -1082130432;
  unk_105E0244 = -1082130432;
  unk_105E0248 = -1082130432;
  unk_105E024C = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0250, fromString: "TLK_LEAD_MISSING_WEAPON");
  unk_105E0254 = -1;
  unk_105E0258 = 1;
  unk_105E025C = -1082130432;
  unk_105E0260 = -1082130432;
  unk_105E0264 = -1082130432;
  unk_105E0268 = -1082130432;
  unk_105E026C = -1082130432;
  unk_105E0270 = -1082130432;
  unk_105E0274 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E0278, fromString: "TLK_LEAD_IDLE");
  unk_105E027C = -1;
  unk_105E0280 = 1;
  unk_105E0284 = -1082130432;
  unk_105E0288 = -1082130432;
  unk_105E028C = -1082130432;
  unk_105E0290 = -1082130432;
  unk_105E0294 = -1082130432;
  unk_105E0298 = -1082130432;
  unk_105E029C = 0;
  result = ResponseRules::CRR_Concept::CRR_Concept(this: &stru_105E02A0, fromString: "TLK_PASSENGER_NEW_RADAR_CONTACT");
  unk_105E02C4 = 0;
  unk_105E02A4 = -1;
  unk_105E02A8 = 1;
  unk_105E02AC = -1082130432;
  unk_105E02B0 = -1082130432;
  unk_105E02B4 = -1082130432;
  unk_105E02B8 = -1082130432;
  unk_105E02BC = -1082130432;
  unk_105E02C0 = -1082130432;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FE9D0
// Name: _dynamic_initializer_for__g_ConceptInfoMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConceptInfoMap__()
{
  CConceptInfoMap::CConceptInfoMap(this: &g_ConceptInfoMap);
  return atexit(func: dynamic_atexit_destructor_for__g_ConceptInfoMap__);
}

//------------------------------------------------------------------------------
// Address: 0x103FE9F0
// Name: _dynamic_initializer_for__ai_ally_speech_manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_ally_speech_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_AllySpeechManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_ally_speech_manager,
           a3: "ai_ally_speech_manager");
}

//------------------------------------------------------------------------------
// Address: 0x103FFD90
// Name: _dynamic_initializer_for__ent_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_dump__()
{
  ConCommand::ConCommand(
    this: &ent_dump,
    pName: "ent_dump",
    callback: CC_Ent_Dump,
    pHelpString: "Usage:\n   ent_dump <entity name>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_dump__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFDC0
// Name: _dynamic_initializer_for__firetarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__firetarget__()
{
  ConCommand::ConCommand(
    this: &firetarget,
    pName: "firetarget",
    callback: CC_Ent_FireTarget,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__firetarget__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFDF0
// Name: _dynamic_initializer_for__ent_fire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_fire__()
{
  ConCommand::ConCommand(
    this: &ent_fire,
    pName: "ent_fire",
    pCallback: &g_EntFireAutoComplete,
    pHelpString: "Usage:\n   ent_fire <target> [action] [value] [delay]\n",
    flags: 0x4000,
    pCompletionCallback: &g_EntFireAutoComplete.ICommandCompletionCallback);
  return atexit(func: dynamic_atexit_destructor_for__ent_fire__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFE20
// Name: _dynamic_initializer_for__ent_cancelpendingentfires__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_cancelpendingentfires__()
{
  ConCommand::ConCommand(
    this: &ent_cancelpendingentfires,
    pName: "ent_cancelpendingentfires",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_CancelPendingEntFires,
    pHelpString: "Cancels all ent_fire created outputs that are currently waiting for their delay to expire.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_cancelpendingentfires__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFE50
// Name: _dynamic_initializer_for__ent_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_info__()
{
  ConCommand::ConCommand(
    this: &ent_info,
    pName: "ent_info",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_Info,
    pHelpString: "Usage:\n   ent_info <class name>\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_info__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFE80
// Name: _dynamic_initializer_for__ent_messages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_messages__()
{
  ConCommand::ConCommand(
    this: &ent_messages,
    pName: "ent_messages",
    callback: CC_Ent_Messages,
    pHelpString: "Toggles input/output message display for the selected entity(ies).  The name of the entity will be displayed as well"
    " as any messages that it sends or receives.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_messages__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFEB0
// Name: _dynamic_initializer_for__ent_pause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_pause__()
{
  ConCommand::ConCommand(
    this: &ent_pause,
    pName: "ent_pause",
    callback: CC_Ent_Pause,
    pHelpString: "Toggles pausing of input/output message processing for entities.  When turned on processing of all message will stop"
    ".  Any messages displayed with 'ent_messages' will stop fading and be displayed indefinitely. To step through the me"
    "ssages one by one use 'ent_step'.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_pause__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFEE0
// Name: _dynamic_initializer_for__picker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__picker__()
{
  ConCommand::ConCommand(
    this: &picker,
    pName: "picker",
    callback: CC_Ent_Picker,
    pHelpString: "Toggles 'picker' mode.  When picker is on, the bounding box, pivot and debugging text is displayed for whatever enti"
    "ty the player is looking at.\n"
    "\tArguments:\tfull - enables all debug information",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__picker__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFF10
// Name: _dynamic_initializer_for__ent_pivot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_pivot__()
{
  ConCommand::ConCommand(
    this: &ent_pivot,
    pName: "ent_pivot",
    callback: CC_Ent_Pivot,
    pHelpString: "Displays the pivot for the given entity(ies).\n"
    "\t(y=up=green, z=forward=blue, x=left=red). \n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_pivot__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFF40
// Name: _dynamic_initializer_for__ent_step__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_step__()
{
  ConCommand::ConCommand(
    this: &ent_step,
    pName: "ent_step",
    callback: CC_Ent_Step,
    pHelpString: "When 'ent_pause' is set this will step through one waiting input / output message at a time.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_step__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFF70
// Name: _dynamic_initializer_for__ent_show_response_criteria__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_show_response_criteria__()
{
  ConCommand::ConCommand(
    this: &ent_show_response_criteria,
    pName: "ent_show_response_criteria",
    callback: CC_Ent_Show_Response_Criteria,
    pHelpString: "Print, to the console, an entity's current criteria set used to select responses.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_show_response_criteria__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFFA0
// Name: _dynamic_initializer_for__ent_autoaim__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_autoaim__()
{
  ConCommand::ConCommand(
    this: &ent_autoaim,
    pName: "ent_autoaim",
    callback: CC_Ent_Autoaim,
    pHelpString: "Displays the entity's autoaim radius.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_autoaim__);
}

//------------------------------------------------------------------------------
// Address: 0x103FFFD0
// Name: _dynamic_initializer_for__step_spline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__step_spline__()
{
  ConVar::ConVar(this: &step_spline, pName: "step_spline", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__step_spline__);
}

//------------------------------------------------------------------------------
// Address: 0x10400000
// Name: _dynamic_initializer_for__ent_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_create__()
{
  ConCommand::ConCommand(
    this: &ent_create,
    pName: "ent_create",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_Create,
    pHelpString: "Creates an entity of the given type where the player is looking.",
    flags: 16388,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_create__);
}

//------------------------------------------------------------------------------
// Address: 0x10400030
// Name: _dynamic_initializer_for__ent_teleport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_teleport__()
{
  ConCommand::ConCommand(
    this: &ent_teleport,
    pName: "ent_teleport",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_Teleport,
    pHelpString: "Teleport the specified entity to where the player is looking.\n\tFormat: ent_teleport <entity name>",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_teleport__);
}

//------------------------------------------------------------------------------
// Address: 0x10400060
// Name: _dynamic_initializer_for__ent_orient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_orient__()
{
  ConCommand::ConCommand(
    this: &ent_orient,
    pName: "ent_orient",
    callback: (void (__cdecl *)(const CCommand *))CC_Ent_Orient,
    pHelpString: "Orient the specified entity to match the player's angles. By default, only orients target entity's YAW. Use the 'all"
    "angles' option to orient on all axis.\n"
    "\tFormat: ent_orient <entity name> <optional: allangles>",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ent_orient__);
}

//------------------------------------------------------------------------------
// Address: 0x10400090
// Name: _dynamic_initializer_for__hl2_episodic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hl2_episodic__()
{
  ConVar::ConVar(this: &hl2_episodic, pName: "hl2_episodic", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__hl2_episodic__);
}

//------------------------------------------------------------------------------
// Address: 0x104000C0
// Name: _dynamic_initializer_for__ent_debugkeys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ent_debugkeys__()
{
  ConVar::ConVar(this: &ent_debugkeys, pName: "ent_debugkeys", pDefaultValue: locale, flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ent_debugkeys__);
}

//------------------------------------------------------------------------------
// Address: 0x104000F0
// Name: _dynamic_initializer_for__ai_shot_bias_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_bias_min__()
{
  ConVar::ConVar(this: &ai_shot_bias_min, pName: "ai_shot_bias_min", pDefaultValue: "-1.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_bias_min__);
}

//------------------------------------------------------------------------------
// Address: 0x10400120
// Name: _dynamic_initializer_for__ai_shot_bias_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_bias_max__()
{
  ConVar::ConVar(this: &ai_shot_bias_max, pName: "ai_shot_bias_max", pDefaultValue: "1.0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_bias_max__);
}

//------------------------------------------------------------------------------
// Address: 0x10400150
// Name: _dynamic_initializer_for__ai_debug_shoot_positions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_shoot_positions__()
{
  ConVar::ConVar(this: &ai_debug_shoot_positions, pName: "ai_debug_shoot_positions", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_shoot_positions__);
}

//------------------------------------------------------------------------------
// Address: 0x10400180
// Name: _dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_DEVELOPER_VERBOSE__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "DeveloperVerbose",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR);
  LOG_DEVELOPER_VERBOSE = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104001A0
// Name: _dynamic_initializer_for__sv_alternateticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_alternateticks__()
{
  ConVar::ConVar(
    this: &sv_alternateticks,
    pName: "sv_alternateticks",
    pDefaultValue: "1",
    flags: 64,
    pHelpString: "If set, server only simulates entities on even numbered ticks.\n");
  return atexit(func: dynamic_atexit_destructor_for__sv_alternateticks__);
}

//------------------------------------------------------------------------------
// Address: 0x10419BA0
// Name: _dynamic_atexit_destructor_for__ent_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_dump__()
{
  ConCommand::~ConCommand(this: &ent_dump);
}

//------------------------------------------------------------------------------
// Address: 0x10419BB0
// Name: _dynamic_atexit_destructor_for__firetarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__firetarget__()
{
  ConCommand::~ConCommand(this: &firetarget);
}

//------------------------------------------------------------------------------
// Address: 0x10419BC0
// Name: _dynamic_atexit_destructor_for__ent_fire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_fire__()
{
  ConCommand::~ConCommand(this: &ent_fire);
}

//------------------------------------------------------------------------------
// Address: 0x10419BD0
// Name: _dynamic_atexit_destructor_for__ent_cancelpendingentfires__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_cancelpendingentfires__()
{
  ConCommand::~ConCommand(this: &ent_cancelpendingentfires);
}

//------------------------------------------------------------------------------
// Address: 0x10419BE0
// Name: _dynamic_atexit_destructor_for__ent_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_info__()
{
  ConCommand::~ConCommand(this: &ent_info);
}

//------------------------------------------------------------------------------
// Address: 0x10419BF0
// Name: _dynamic_atexit_destructor_for__ent_messages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_messages__()
{
  ConCommand::~ConCommand(this: &ent_messages);
}

//------------------------------------------------------------------------------
// Address: 0x10419C00
// Name: _dynamic_atexit_destructor_for__ent_pause__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_pause__()
{
  ConCommand::~ConCommand(this: &ent_pause);
}

//------------------------------------------------------------------------------
// Address: 0x10419C10
// Name: _dynamic_atexit_destructor_for__picker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__picker__()
{
  ConCommand::~ConCommand(this: &picker);
}

//------------------------------------------------------------------------------
// Address: 0x10419C20
// Name: _dynamic_atexit_destructor_for__ent_pivot__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_pivot__()
{
  ConCommand::~ConCommand(this: &ent_pivot);
}

//------------------------------------------------------------------------------
// Address: 0x10419C30
// Name: _dynamic_atexit_destructor_for__ent_step__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_step__()
{
  ConCommand::~ConCommand(this: &ent_step);
}

//------------------------------------------------------------------------------
// Address: 0x10419C40
// Name: _dynamic_atexit_destructor_for__ent_show_response_criteria__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_show_response_criteria__()
{
  ConCommand::~ConCommand(this: &ent_show_response_criteria);
}

//------------------------------------------------------------------------------
// Address: 0x10419C50
// Name: _dynamic_atexit_destructor_for__ent_autoaim__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_autoaim__()
{
  ConCommand::~ConCommand(this: &ent_autoaim);
}

//------------------------------------------------------------------------------
// Address: 0x10419C60
// Name: _dynamic_atexit_destructor_for__step_spline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__step_spline__()
{
  ConVar::~ConVar(this: &step_spline);
}

//------------------------------------------------------------------------------
// Address: 0x10419C70
// Name: _dynamic_atexit_destructor_for__ent_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_create__()
{
  ConCommand::~ConCommand(this: &ent_create);
}

//------------------------------------------------------------------------------
// Address: 0x10419C80
// Name: _dynamic_atexit_destructor_for__ent_teleport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_teleport__()
{
  ConCommand::~ConCommand(this: &ent_teleport);
}

//------------------------------------------------------------------------------
// Address: 0x10419C90
// Name: _dynamic_atexit_destructor_for__ent_orient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_orient__()
{
  ConCommand::~ConCommand(this: &ent_orient);
}

//------------------------------------------------------------------------------
// Address: 0x10419CA0
// Name: _ServerClassInit_DT_AnimTimeMustBeFirst::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_AnimTimeMustBeFirst::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_49;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419CC0
// Name: _dynamic_atexit_destructor_for__g_ModelSoundsCacheSaver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelSoundsCacheSaver__()
{
  IGameSystem::~IGameSystem(this: &g_ModelSoundsCacheSaver);
}

//------------------------------------------------------------------------------
// Address: 0x10419CD0
// Name: _DataMapInit_thinkfunc_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_thinkfunc_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_89);
}

//------------------------------------------------------------------------------
// Address: 0x10419CE0
// Name: _DataMapInit_ResponseContext_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ResponseContext_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_90);
}

//------------------------------------------------------------------------------
// Address: 0x10419CF0
// Name: _DataMapInit_CBaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_91);
}

//------------------------------------------------------------------------------
// Address: 0x10419D00
// Name: _dynamic_atexit_destructor_for__g_TeleportStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TeleportStack__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_TeleportStack);
}

//------------------------------------------------------------------------------
// Address: 0x10419D10
// Name: _dynamic_atexit_destructor_for__g_ModelPrecacheSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelPrecacheSystem__()
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_ModelPrecacheSystem.m_RepeatCounts.m_Tree);
  IGameSystem::~IGameSystem(this: &g_ModelPrecacheSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10419D30
// Name: _dynamic_atexit_destructor_for__g_ModelSoundsCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ModelSoundsCache__()
{
  CUtlCachedFileData<CModelSoundsCache>::~CUtlCachedFileData<CModelSoundsCache>(this: &g_ModelSoundsCache);
}

//------------------------------------------------------------------------------
// Address: 0x10419D40
// Name: _dynamic_atexit_destructor_for__g_CBaseEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CBaseEntity_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CBaseEntity_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x10419D50
// Name: _dynamic_atexit_destructor_for__hl2_episodic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hl2_episodic__()
{
  ConVar::~ConVar(this: &hl2_episodic);
}

//------------------------------------------------------------------------------
// Address: 0x10419D60
// Name: _dynamic_atexit_destructor_for__ent_debugkeys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ent_debugkeys__()
{
  ConVar::~ConVar(this: &ent_debugkeys);
}

//------------------------------------------------------------------------------
// Address: 0x10419D70
// Name: _dynamic_atexit_destructor_for__ai_shot_bias_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_bias_min__()
{
  ConVar::~ConVar(this: &ai_shot_bias_min);
}

//------------------------------------------------------------------------------
// Address: 0x10419D80
// Name: _dynamic_atexit_destructor_for__ai_shot_bias_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_bias_max__()
{
  ConVar::~ConVar(this: &ai_shot_bias_max);
}

//------------------------------------------------------------------------------
// Address: 0x10419D90
// Name: _dynamic_atexit_destructor_for__ai_debug_shoot_positions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_shoot_positions__()
{
  ConVar::~ConVar(this: &ai_debug_shoot_positions);
}

//------------------------------------------------------------------------------
// Address: 0x10419DA0
// Name: _dynamic_atexit_destructor_for__sv_alternateticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_alternateticks__()
{
  ConVar::~ConVar(this: &sv_alternateticks);
}
