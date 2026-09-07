// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_waypoint.cpp
// Functions: 10
// ============================================================

#include "game\server\ai_waypoint.h"

//------------------------------------------------------------------------------
// Address: 0x10090890
// Name: public: void CAI_WaypointList::Set(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_WaypointList::Set(CChoreoChannel *this, CChoreoActor *actor)
{
  this->m_pActor = actor;
}

//------------------------------------------------------------------------------
// Address: 0x100908A0
// Name: public: struct AI_Waypoint_t __near * CAI_WaypointList::GetLast(void)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall CAI_WaypointList::GetLast(CAI_WaypointList *this)
{
  AI_Waypoint_t *result; // eax
  AI_Waypoint_t *i; // ecx

  result = this->m_pFirstWaypoint;
  if ( this->m_pFirstWaypoint != nullptr )
  {
    for ( i = result->pNext; i != nullptr; i = i->pNext )
      result = i;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100908C0
// Name: public: AI_Waypoint_t::AI_Waypoint_t(void)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall AI_Waypoint_t::AI_Waypoint_t(AI_Waypoint_t *this)
{
  this->hPathCorner.m_Index = -1;
  this->m_hData.m_Index = -1;
  memset(dst: (int)this, value: nullptr, count: sizeof(AI_Waypoint_t));
  this->vecLocation = vec3_invalid;
  this->iNodeID = -1;
  this->flPathDistGoal = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090920
// Name: public: AI_Waypoint_t::AI_Waypoint_t(class Vector const __near &,float,enum Navigation_t,int,int)
// Source: json
//------------------------------------------------------------------------------
AI_Waypoint_t *__thiscall AI_Waypoint_t::AI_Waypoint_t(
        AI_Waypoint_t *this,
        const Vector *initPosition,
        float initYaw,
        Navigation_t initNavType,
        int initWaypointFlags,
        int initNodeID)
{
  double z; // st7

  this->hPathCorner.m_Index = -1;
  this->m_hData.m_Index = -1;
  memset(dst: (int)this, value: nullptr, count: sizeof(AI_Waypoint_t));
  this->vecLocation.x = initPosition->x;
  this->vecLocation.y = initPosition->y;
  z = initPosition->z;
  this->flYaw = initYaw;
  this->vecLocation.z = z;
  this->m_iWPType = initNavType;
  this->m_fWaypointFlags = initWaypointFlags;
  this->iNodeID = initNodeID;
  this->flPathDistGoal = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090980
// Name: void AddWaypointLists(struct AI_Waypoint_t __near *,struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddWaypointLists(AI_Waypoint_t *oldRoute, AI_Waypoint_t *addRoute)
{
  AI_Waypoint_t *v2; // esi
  AI_Waypoint_t **p_pNext; // eax
  bool v4; // zf
  int iNodeID; // eax
  AI_Waypoint_t *v6; // edi
  AI_Waypoint_t *v7; // eax
  AI_Waypoint_t *v8; // ecx
  int v9; // eax
  AI_Waypoint_t *v10; // edi
  AI_Waypoint_t *pNext; // edx
  AI_Waypoint_t *pPrev; // ecx
  int v13; // ecx

  v2 = oldRoute;
  p_pNext = &oldRoute->pNext;
  if ( oldRoute->pNext != nullptr )
  {
    do
    {
      v2 = *p_pNext;
      v4 = (*p_pNext)->pNext == nullptr;
      p_pNext = &(*p_pNext)->pNext;
    }
    while ( !v4 );
  }
  iNodeID = v2->iNodeID;
  v2->m_fWaypointFlags &= ~8u;
  if ( iNodeID == -1 || iNodeID != addRoute->iNodeID )
  {
    pNext = v2->pNext;
    v9 = (int)&v2->pNext;
    if ( pNext != nullptr )
      pNext->pPrev = nullptr;
    *(_DWORD *)v9 = addRoute;
    if ( addRoute != nullptr )
    {
      pPrev = addRoute->pPrev;
      if ( pPrev != nullptr )
        pPrev->pNext = nullptr;
      *(_DWORD *)(*(_DWORD *)v9 + 44) = v2;
    }
  }
  else
  {
    v6 = addRoute->pNext;
    if ( v6 != nullptr )
      v6->pPrev = addRoute->pPrev;
    v7 = addRoute->pPrev;
    if ( v7 != nullptr )
      v7->pNext = addRoute->pNext;
    CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: addRoute);
    v8 = v2->pNext;
    v9 = (int)&v2->pNext;
    if ( v8 != nullptr )
      v8->pPrev = nullptr;
    *(_DWORD *)v9 = v6;
    if ( v6 != nullptr )
    {
      v10 = v6->pPrev;
      if ( v10 != nullptr )
        v10->pNext = nullptr;
      *(_DWORD *)(*(_DWORD *)v9 + 44) = v2;
    }
  }
  if ( *(_DWORD *)v9 != 0 )
  {
    do
    {
      v13 = *(_DWORD *)v9;
      v4 = *(_DWORD *)(*(_DWORD *)v9 + 40) == 0;
      v9 = *(_DWORD *)v9 + 40;
    }
    while ( !v4 );
    *(_DWORD *)(v13 + 32) |= 8u;
  }
  else
  {
    v2->m_fWaypointFlags |= 8u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090A40
// Name: public: void CAI_WaypointList::PrependWaypoints(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_WaypointList::PrependWaypoints(CAI_WaypointList *this, AI_Waypoint_t *pWaypoints)
{
  AddWaypointLists(oldRoute: pWaypoints, addRoute: this->m_pFirstWaypoint);
  this->m_pFirstWaypoint = pWaypoints;
}

//------------------------------------------------------------------------------
// Address: 0x10090A60
// Name: public: void CAI_WaypointList::PrependWaypoint(class Vector const __near &,enum Navigation_t,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_WaypointList::PrependWaypoint(
        CAI_WaypointList *this,
        const Vector *newPoint,
        Navigation_t navType,
        unsigned int waypointFlags,
        float flYaw)
{
  AI_Waypoint_t *v6; // eax
  AI_Waypoint_t *v7; // esi
  double z; // st7

  v6 = (AI_Waypoint_t *)CUtlMemoryPool::Alloc(this: &AI_Waypoint_t::s_Allocator, amount: 0x30u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->hPathCorner.m_Index = -1;
    v6->m_hData.m_Index = -1;
    memset(dst: (int)v6, value: nullptr, count: sizeof(AI_Waypoint_t));
    v7->vecLocation.x = newPoint->x;
    v7->vecLocation.y = newPoint->y;
    z = newPoint->z;
    v7->flYaw = flYaw;
    v7->vecLocation.z = z;
    v7->m_iWPType = navType;
    v7->m_fWaypointFlags = waypointFlags;
    v7->iNodeID = -1;
    v7->flPathDistGoal = -1.0;
    AddWaypointLists(oldRoute: v7, addRoute: this->m_pFirstWaypoint);
    this->m_pFirstWaypoint = v7;
  }
  else
  {
    AddWaypointLists(oldRoute: nullptr, addRoute: this->m_pFirstWaypoint);
    this->m_pFirstWaypoint = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090B00
// Name: void DeleteAll(struct AI_Waypoint_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteAll(AI_Waypoint_t *pWaypointList)
{
  AI_Waypoint_t *v1; // esi
  AI_Waypoint_t **p_pNext; // eax
  _DWORD *p_x; // ecx
  int v4; // edx

  v1 = pWaypointList;
  while ( v1 != nullptr )
  {
    p_pNext = &v1->pNext;
    p_x = (_DWORD *)&v1->vecLocation.x;
    v1 = v1->pNext;
    if ( v1 != nullptr )
      v1->pPrev = (AI_Waypoint_t *)p_x[11];
    v4 = p_x[11];
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 40) = *p_pNext;
    CUtlMemoryPool::Free(this: &AI_Waypoint_t::s_Allocator, memBlock: p_x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10090B50
// Name: public: void CAI_WaypointList::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_WaypointList::RemoveAll(CAI_WaypointList *this)
{
  DeleteAll(pWaypointList: this->m_pFirstWaypoint);
  this->m_pFirstWaypoint = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103FEFE0
// Name: AI_Waypoint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_Waypoint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_Waypoint_t>();
  AI_Waypoint_t_DataDescInit::g_DataMapHolder = result;
  return result;
}
