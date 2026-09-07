// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/enginetrace.cpp
// Functions: 64
// ============================================================

#include "engine\enginetrace.h"

//------------------------------------------------------------------------------
// Address: 0x100359E0
// Name: public: virtual enum TraceType_t CTraceFilter::GetTraceType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceFilter::GetTraceType(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012B700
// Name: public: virtual bool CTraceFilterHitAll::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterHitAll::ShouldHitEntity(CRConServer *this, int hSocket, const netadr_s *netAdr)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174B00
// Name: public: virtual class ICollideable __near * CEngineTraceClient::GetCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::GetCollideable(CEngineTraceClient *this, IHandleEntity *pEntity)
{
  IStaticPropMgrEngine *v2; // eax
  ICollideable *result; // eax
  const CBaseHandle *v4; // eax
  int v5; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pEntity);
  if ( result == nullptr )
  {
    v4 = pEntity->GetRefEHandle(this: pEntity);
    v5 = ((int (__thiscall *)(IClientEntityList *, unsigned int))entitylist->GetClientUnknownFromHandle)(
           a1: entitylist,
           a2: v4->m_Index);
    return (*(ICollideable *(__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174B50
// Name: public: virtual class ICollideable __near * CEngineTraceServer::GetCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceServer::GetCollideable(CEngineTraceServer *this, IHandleEntity *pEntity)
{
  IStaticPropMgrEngine *v2; // eax
  ICollideable *result; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pEntity);
  if ( result == nullptr )
    return ((ICollideable *(__thiscall *)(IHandleEntity *))pEntity->__vftable[1].dtr_IHandleEntity)(a1: pEntity);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174B80
// Name: private: virtual int CEngineTraceClient::SpatialPartitionTriggerMask(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTraceClient::SpatialPartitionTriggerMask(CEngineTraceClient *this)
{
  return 256;
}

//------------------------------------------------------------------------------
// Address: 0x10174B90
// Name: private: static int CPointContentsEnum::GetModelHeadNode(class ICollideable __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CPointContentsEnum::GetModelHeadNode(ICollideable *pCollide)
{
  unsigned int v1; // edi
  cmodel_t *v2; // eax

  v1 = pCollide->GetCollisionModelIndex(this: pCollide);
  if ( v1 <= 0x3FF
    && pCollide->GetCollisionModel(this: pCollide) != nullptr
    && (v2 = CM_InlineModelNumber(index: v1 - 1)) != nullptr )
  {
    return v2->headnode;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174BE0
// Name: public: virtual int CEngineTrace::GetPointContents_WorldOnly(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetPointContents_WorldOnly(
        CEngineTrace *this,
        const Vector *vecAbsPosition,
        int contentsMask)
{
  return CM_PointContents(p: vecAbsPosition, headnode: 0, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x10174C00
// Name: public: virtual int CEngineTrace::GetPointContents(class Vector const __near &,int,class IHandleEntity __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetPointContents(
        CEngineTrace *this,
        const Vector *vecAbsPosition,
        int contentsMask,
        IHandleEntity **ppEntity)
{
  int v6; // ebx
  float z; // xmm0_4
  ISpatialPartitionInternal *v8; // eax
  ISpatialPartitionInternal_vtbl *v9; // ebx
  int v10; // eax
  int m_Contents; // edi
  ICollideable *v13; // eax
  CPointContentsEnum contentsEnum; // [esp+Ch] [ebp-20h] BYREF
  int nContents; // [esp+34h] [ebp+8h]
  int contentsMaska; // [esp+38h] [ebp+Ch]

  ++this->m_traceStatCounters[1];
  v6 = contentsMask & CM_PointContents(p: vecAbsPosition, headnode: 0, contentsMask);
  nContents = v6;
  if ( v6 != 1 )
  {
    contentsEnum.m_Pos.x = vecAbsPosition->x;
    contentsEnum.m_Pos.y = vecAbsPosition->y;
    z = vecAbsPosition->z;
    contentsEnum.__vftable = (CPointContentsEnum_vtbl *)&CPointContentsEnum::`vftable';
    contentsEnum.m_Contents = 0;
    contentsEnum.m_validMask = contentsMask;
    contentsEnum.m_pEngineTrace = this;
    contentsEnum.m_Pos.z = z;
    contentsEnum.m_pCollide = nullptr;
    v8 = SpatialPartition();
    v9 = v8->__vftable;
    contentsMaska = (int)v8;
    v10 = ((int (__thiscall *)(CEngineTrace *, const Vector *, _DWORD, CPointContentsEnum *))this->SpatialPartitionMask)(
            a1: this,
            a2: vecAbsPosition,
            a3: 0,
            a4: &contentsEnum);
    ((void (__thiscall *)(int, int))v9->EnumerateElementsAtPoint)(a1: contentsMaska, a2: v10);
    m_Contents = contentsEnum.m_Contents;
    if ( contentsEnum.m_Contents != 0 )
    {
      if ( ppEntity != nullptr )
        *ppEntity = contentsEnum.m_pCollide->GetEntityHandle(this: contentsEnum.m_pCollide);
      return m_Contents;
    }
    v6 = nContents;
  }
  if ( ppEntity != nullptr )
  {
    v13 = this->GetWorldCollideable(this);
    *ppEntity = (IHandleEntity *)v13->GetEntityHandle(this: v13);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10174CE0
// Name: public: virtual int CEngineTrace::GetStatByIndex(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetStatByIndex(CEngineTrace *this, int index, bool bClear)
{
  int result; // eax

  if ( index >= 3 )
    return 0;
  result = this->m_traceStatCounters[index];
  if ( bClear )
    this->m_traceStatCounters[index] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174D10
// Name: public: static void CSetupBrushQuery::BrushQueryReleaseFunc(class CBrushQuery __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSetupBrushQuery::BrushQueryReleaseFunc(TraceInfo_t *pBrushQuery)
{
  pBrushQuery = (TraceInfo_t *)LODWORD(pBrushQuery->m_end.y);
  EndTrace(pTraceInfo: &pBrushQuery);
}

//------------------------------------------------------------------------------
// Address: 0x10174D30
// Name: disp_list_all_collideable
// Source: json
//------------------------------------------------------------------------------
void __cdecl disp_list_all_collideable()
{
  int v0; // esi
  int v1; // eax
  int v2; // edi
  unsigned __int16 m_nFlags; // bx
  const char *v4; // edx
  const char *v5; // ecx
  const char *v6; // eax
  __int64 v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+18h] [ebp-4h]

  v0 = 0;
  v7 = 0;
  v8 = 0;
  ConMsg(a1: "Displacement list:\n");
  v1 = g_DispCollTreeCount;
  if ( g_DispCollTreeCount > 0 )
  {
    v2 = 0;
    do
    {
      m_nFlags = g_pDispCollTrees[v2].m_nFlags;
      v4 = "   Ray";
      if ( (m_nFlags & 8) == 0 )
        v4 = "NO Ray";
      v5 = "   Hull";
      if ( (m_nFlags & 4) == 0 )
        v5 = "NO Hull";
      v6 = "   Physics";
      if ( (m_nFlags & 2) == 0 )
        v6 = "NO Physics";
      ConMsg(
        a1: "Displacement %3d, location ( % 10.2f % 10.2f % 10.2f ), collision flags: %s %s %s\n",
        v0,
        (float)((float)(g_pDispCollTrees[v2].m_maxs.x + g_pDispCollTrees[v2].m_mins.x) * 0.5),
        (float)((float)(g_pDispCollTrees[v2].m_maxs.y + g_pDispCollTrees[v2].m_mins.y) * 0.5),
        (float)((float)(g_pDispCollTrees[v2].m_maxs.z + g_pDispCollTrees[v2].m_mins.z) * 0.5),
        v6,
        v5,
        v4);
      LODWORD(v7) = ((m_nFlags & 2) != 0) + (_DWORD)v7;
      v1 = g_DispCollTreeCount;
      HIDWORD(v7) += (m_nFlags & 4) != 0;
      v8 += (m_nFlags & 8) != 0;
      ++v0;
      ++v2;
    }
    while ( v0 < g_DispCollTreeCount );
  }
  ConMsg(
    a1: "Total displacements: %d\nCollision stats: %d with physics, %d with hull, %d with ray.\n",
    v1,
    (_DWORD)v7,
    HIDWORD(v7),
    v8);
}

//------------------------------------------------------------------------------
// Address: 0x10174E80
// Name: public: virtual int CEngineTrace::GetNumDisplacements(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetNumDisplacements(CEngineTrace *this)
{
  return g_DispCollTreeCount;
}

//------------------------------------------------------------------------------
// Address: 0x10174E90
// Name: public: virtual void CEngineTrace::GetDisplacementMesh(int,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetDisplacementMesh(CEngineTrace *this, int nIndex, virtualmeshlist_t *pMeshTriList)
{
  CDispCollTree::GetVirtualMeshList(this: &g_pDispCollTrees[nIndex], pList: pMeshTriList);
}

//------------------------------------------------------------------------------
// Address: 0x10174EB0
// Name: public: virtual int CEngineTrace::GetLeafContainingPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetLeafContainingPoint(CEngineTrace *this, const Vector *vPos)
{
  return CM_PointLeafnum(p: vPos);
}

//------------------------------------------------------------------------------
// Address: 0x10174ED0
// Name: public: virtual unsigned int CStudioConvexInfo::GetContents(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioConvexInfo::GetContents(CStudioConvexInfo *this, int convexGameData)
{
  if ( convexGameData != 0 )
    return *(_DWORD *)((char *)this->m_pStudioHdr + 216 * convexGameData + this->m_pStudioHdr->boneindex - 36);
  else
    return this->m_pStudioHdr->contents;
}

//------------------------------------------------------------------------------
// Address: 0x10174F00
// Name: private: bool CEngineTrace::ClipRayToBSP(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToBSP(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  int v6; // eax
  int headnode; // edi
  const Vector *v8; // eax
  const QAngle *v10; // [esp-8h] [ebp-10h]

  v6 = pEntity->GetCollisionModelIndex(this: pEntity);
  headnode = CM_InlineModelNumber(index: v6 - 1)->headnode;
  v10 = pEntity->GetCollisionAngles(this: pEntity);
  v8 = pEntity->GetCollisionOrigin(this: pEntity);
  CM_TransformedBoxTrace(ray, headnode, brushmask: fMask, origin: v8, angles: v10, tr: pTrace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174F50
// Name: private: bool CEngineTrace::ClipRayToOBB(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToOBB(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const Vector *v6; // eax
  const QAngle *v7; // [esp-14h] [ebp-18h]
  const Vector *v8; // [esp-10h] [ebp-14h]
  const Vector *v9; // [esp-Ch] [ebp-10h]

  if ( pEntity->GetSolid(this: pEntity) != SOLID_OBB )
    return 0;
  v9 = pEntity->OBBMaxs(this: pEntity);
  v8 = pEntity->OBBMins(this: pEntity);
  v7 = pEntity->GetCollisionAngles(this: pEntity);
  v6 = pEntity->GetCollisionOrigin(this: pEntity);
  IntersectRayWithOBB(
    ray,
    vecBoxOrigin: v6,
    angBoxRotation: v7,
    vecOBBMins: v8,
    vecOBBMaxs: v9,
    flTolerance: 0.03125,
    pTrace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174FC0
// Name: private: virtual void CEngineTraceClient::SetTraceEntity(class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTraceClient::SetTraceEntity(
        CEngineTraceClient *this,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  int v3; // edi
  IStaticPropMgrEngine *v4; // eax
  IStaticPropMgrEngine *v5; // eax

  if ( pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid )
  {
    if ( pCollideable != nullptr )
    {
      v3 = pCollideable->GetEntityHandle(this: pCollideable);
      v4 = StaticPropMgr();
      if ( v4->IsStaticProp_2(this: v4, a2: (IHandleEntity *)v3) )
      {
        pTrace->m_pEnt = (struct CBaseEntity *)entitylist->GetClientEntity(this: entitylist, a2: 0);
        v5 = StaticPropMgr();
        pTrace->hitbox = v5->GetStaticPropIndex(this: v5, a2: (IHandleEntity *)v3) + 1;
      }
      else
      {
        pTrace->m_pEnt = (struct CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(a1: v3);
      }
    }
    else
    {
      pTrace->m_pEnt = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175050
// Name: private: virtual void CEngineTraceServer::SetTraceEntity(class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTraceServer::SetTraceEntity(
        CEngineTraceServer *this,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  struct CBaseEntity *v3; // edi
  IStaticPropMgrEngine *v4; // eax
  struct CBaseEntity *m_pUnk; // eax
  IStaticPropMgrEngine *v6; // eax

  if ( pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid )
  {
    v3 = (struct CBaseEntity *)pCollideable->GetEntityHandle(this: pCollideable);
    v4 = StaticPropMgr();
    if ( v4->IsStaticProp_2(this: v4, a2: (IHandleEntity *)v3) )
    {
      if ( (sv.edicts->m_fStateFlags & 4) != 0 )
        m_pUnk = (struct CBaseEntity *)sv.edicts->m_pUnk;
      else
        m_pUnk = nullptr;
      pTrace->m_pEnt = m_pUnk;
      v6 = StaticPropMgr();
      pTrace->hitbox = v6->GetStaticPropIndex(this: v6, a2: (IHandleEntity *)v3) + 1;
    }
    else
    {
      pTrace->m_pEnt = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101750D0
// Name: public: virtual void CEngineTrace::ClipRayToEntity(struct Ray_t const __near &,unsigned int,class IHandleEntity __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::ClipRayToEntity(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        IHandleEntity *pEntity,
        CGameTrace *pTrace)
{
  CEngineTrace_vtbl *v6; // edi
  int v7; // eax

  v6 = this->__vftable;
  v7 = ((int (__thiscall *)(CEngineTrace *, IHandleEntity *, CGameTrace *))this->GetCollideable)(
         a1: this,
         a2: pEntity,
         a3: pTrace);
  ((void (__thiscall *)(CEngineTrace *, const Ray_t *, unsigned int, int))v6->ClipRayToCollideable)(
    a1: this,
    a2: ray,
    a3: fMask,
    a4: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10175100
// Name: public: virtual enum IterationRetval_t CEntityListAlongRay::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CEntityListAlongRay::EnumElement(CEntityListAlongRay *this, IHandleEntity *pHandleEntity)
{
  int m_nCount; // eax

  m_nCount = this->m_nCount;
  if ( m_nCount >= 1024 )
  {
    _DevMsg(a1: 1, a2: "Max entity count along ray exceeded!\n");
  }
  else
  {
    this->m_EntityHandles[m_nCount] = pHandleEntity;
    ++this->m_nCount;
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x10175140
// Name: private: virtual class ICollideable __near * CEngineTraceClient::HandleEntityToCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::HandleEntityToCollideable(
        CEngineTraceClient *this,
        IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v2; // eax
  ICollideable *result; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pHandleEntity);
  if ( result == nullptr && pHandleEntity != nullptr )
    return ((ICollideable *(__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].dtr_IHandleEntity)(a1: pHandleEntity);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175170
// Name: private: virtual char const __near * CEngineTraceServer::GetDebugName(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTraceServer::GetDebugName(CEngineTraceServer *this, IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v2; // eax
  int v4; // eax

  v2 = StaticPropMgr();
  if ( v2->IsStaticProp_2(this: v2, a2: pHandleEntity) )
    return "static prop";
  if ( pHandleEntity == nullptr
    || ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity) == 0 )
  {
    return "<null>";
  }
  v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
  return (*(const char *(__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101751D0
// Name: private: virtual char const __near * CEngineTraceClient::GetDebugName(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTraceClient::GetDebugName(CEngineTraceClient *this, IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v2; // eax
  int v4; // eax
  int v5; // esi

  v2 = StaticPropMgr();
  if ( v2->IsStaticProp_2(this: v2, a2: pHandleEntity) )
    return "static prop";
  if ( pHandleEntity == nullptr )
    return "<null>";
  v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
  v5 = v4;
  if ( v4 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4) != 0 )
    return *(const char **)((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5) + 8);
  else
    return "client entity";
}

//------------------------------------------------------------------------------
// Address: 0x10175240
// Name: private: virtual class ICollideable __near * CEngineTraceClient::GetWorldCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::GetWorldCollideable(CEngineTraceClient *this)
{
  IClientEntity *v1; // eax

  v1 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v1 != nullptr )
    return v1->GetCollideable(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10175260
// Name: private: virtual class ICollideable __near * CEngineTraceServer::GetWorldCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceServer::GetWorldCollideable(CEngineTraceServer *this)
{
  IServerUnknown *m_pUnk; // ecx

  if ( sv.edicts != nullptr && (sv.edicts->m_fStateFlags & 4) != 0 && (m_pUnk = sv.edicts->m_pUnk) != nullptr )
    return m_pUnk->GetCollideable(this: m_pUnk);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10175280
// Name: ComputeRayBounds
// Source: json
//------------------------------------------------------------------------------
void __fastcall ComputeRayBounds(Vector *maxs, Vector *mins, const Ray_t *ray)
{
  float x; // xmm0_4
  float v4; // xmm1_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector start; // 0:^4.12

  x = ray->m_Delta.x;
  start = ray->m_Start.Vector;
  if ( ray->m_IsRay )
  {
    if ( x <= 0.0 )
    {
      maxs->x = start.x;
      v4 = ray->m_Delta.x + start.x;
    }
    else
    {
      v4 = ray->m_Start.x;
      maxs->x = x + start.x;
    }
    mins->x = v4;
    y = ray->m_Delta.y;
    if ( y <= 0.0 )
    {
      maxs->y = start.y;
      mins->y = start.y + ray->m_Delta.y;
    }
    else
    {
      maxs->y = y + start.y;
      mins->y = start.y;
    }
    z = ray->m_Delta.z;
    if ( z <= 0.0 )
    {
      maxs->z = start.z;
      v7 = ray->m_Delta.z + start.z;
    }
    else
    {
      v7 = start.z;
      maxs->z = z + start.z;
    }
    mins->z = v7;
  }
  else
  {
    if ( x <= 0.0 )
    {
      maxs->x = ray->m_Extents.x + start.x;
      v8 = ray->m_Delta.x + start.x;
    }
    else
    {
      v8 = ray->m_Start.x;
      maxs->x = (float)(x + start.x) + ray->m_Extents.x;
    }
    mins->x = v8 - ray->m_Extents.x;
    v9 = ray->m_Delta.y;
    if ( v9 <= 0.0 )
    {
      maxs->y = ray->m_Extents.y + start.y;
      mins->y = (float)(start.y + ray->m_Delta.y) - ray->m_Extents.y;
    }
    else
    {
      maxs->y = (float)(v9 + start.y) + ray->m_Extents.y;
      mins->y = start.y - ray->m_Extents.y;
    }
    v10 = ray->m_Delta.z;
    if ( v10 <= 0.0 )
    {
      maxs->z = ray->m_Extents.z + start.z;
      v11 = (float)(ray->m_Delta.z + start.z) - ray->m_Extents.z;
    }
    else
    {
      maxs->z = (float)(v10 + start.z) + ray->m_Extents.z;
      v11 = start.z - ray->m_Extents.z;
    }
    mins->z = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175430
// Name: public: virtual bool CTraceListData::CanTraceRay(struct Ray_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceListData::CanTraceRay(CTraceListData *this, const Ray_t *ray)
{
  Vector rayMins; // [esp+4h] [ebp-18h] BYREF
  Vector rayMaxs; // [esp+10h] [ebp-Ch] BYREF

  ComputeRayBounds(ray, mins: &rayMins, maxs: &rayMaxs);
  return this->m_mins.z >= rayMaxs.x
      && rayMins.x >= *(float *)&this->m_staticPropList.m_pElements
      && this->m_maxs.x >= rayMaxs.y
      && rayMins.y >= this->m_mins.x
      && this->m_maxs.y >= rayMaxs.z
      && rayMins.z >= this->m_mins.y;
}

//------------------------------------------------------------------------------
// Address: 0x101754C0
// Name: public: virtual void CEngineTrace::SetupLeafAndEntityListRay(struct Ray_t const __near &,class ITraceListData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::SetupLeafAndEntityListRay(
        CEngineTrace *this,
        const Ray_t *ray,
        ITraceListData *pTraceData)
{
  const Vector *v4; // ecx
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  ComputeRayBounds(ray, &mins, &maxs);
  this->SetupLeafAndEntityListBox(this, a2: &mins, a3: v4, a4: pTraceData);
}

//------------------------------------------------------------------------------
// Address: 0x10175500
// Name: public: virtual void CEngineTrace::SetupLeafAndEntityListBox(class Vector const __near &,class Vector const __near &,class ITraceListData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::SetupLeafAndEntityListBox(
        CEngineTrace *this,
        const Vector *vecBoxMin,
        const Vector *vecBoxMax,
        ITraceListData *pTraceData)
{
  CTraceListData *v5; // esi
  float y; // xmm1_4
  int v7; // eax
  const Vector *vecBoxMina; // [esp+18h] [ebp+8h]
  ITraceListData *pTraceDataa; // [esp+20h] [ebp+10h]

  if ( pTraceData != nullptr )
    v5 = (CTraceListData *)&pTraceData[-1];
  else
    v5 = nullptr;
  v5->Reset(this: &v5->ITraceListData);
  v5->m_mins.x = vecBoxMin->x - 1.0;
  v5->m_maxs.x = vecBoxMax->x + 1.0;
  y = vecBoxMin->y;
  v5->m_pEngineTrace = this;
  v5->m_mins.y = y - 1.0;
  v5->m_maxs.y = vecBoxMax->y + 1.0;
  v5->m_mins.z = vecBoxMin->z - 1.0;
  v5->m_maxs.z = vecBoxMax->z + 1.0;
  CM_GetTraceDataForBSP(mins: &v5->m_mins, maxs: &v5->m_maxs, traceData: v5);
  pTraceDataa = (ITraceListData *)SpatialPartition();
  vecBoxMina = (const Vector *)pTraceDataa->__vftable;
  v7 = ((int (__thiscall *)(CEngineTrace *, Vector *, Vector *, _DWORD, CTraceListData *))this->SpatialPartitionMask)(
         a1: this,
         a2: &v5->m_mins,
         a3: &v5->m_maxs,
         a4: 0,
         a5: v5);
  ((void (__thiscall *)(ITraceListData *, int))LODWORD(vecBoxMina[4].x))(a1: pTraceDataa, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101755F0
// Name: public: virtual enum IterationRetval_t CEnumerationFilter::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEnumerationFilter::EnumElement(CEnumerationFilter *this, IHandleEntity *pHandleEntity)
{
  IStaticPropMgrEngine *v3; // eax

  v3 = StaticPropMgr();
  return !v3->IsStaticProp_2(this: v3, a2: pHandleEntity)
      && ((int (__thiscall *)(IEntityEnumerator *, IHandleEntity *))this->m_pEnumerator->EnumEntity)(
           a1: this->m_pEnumerator,
           a2: pHandleEntity) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175630
// Name: public: virtual void CEngineTrace::EnumerateEntities(struct Ray_t const __near &,bool,class IEntityEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::EnumerateEntities(
        CEngineTrace *this,
        const Ray_t *ray,
        bool bTriggers,
        IEntityEnumerator *pEnumerator)
{
  CEngineTrace_vtbl *v4; // edx
  int (*SpatialPartitionTriggerMask)(void); // eax
  int v6; // esi
  ISpatialPartitionInternal *v7; // eax
  CEnumerationFilter enumerator; // [esp+4h] [ebp-Ch] BYREF

  ++this->m_traceStatCounters[2];
  v4 = this->__vftable;
  enumerator.__vftable = (CEnumerationFilter_vtbl *)&CEnumerationFilter::`vftable';
  enumerator.m_pEnumerator = pEnumerator;
  enumerator.m_pEngineTrace = this;
  if ( bTriggers )
    SpatialPartitionTriggerMask = (int (*)(void))v4->SpatialPartitionTriggerMask;
  else
    SpatialPartitionTriggerMask = (int (*)(void))v4->SpatialPartitionMask;
  v6 = SpatialPartitionTriggerMask();
  if ( v6 != 0 )
  {
    v7 = SpatialPartition();
    v7->EnumerateElementsAlongRay(this: v7, a2: v6, a3: ray, a4: false, a5: &enumerator);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175690
// Name: public: virtual void CEngineTrace::EnumerateEntities(class Vector const __near &,class Vector const __near &,class IEntityEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::EnumerateEntities(
        CEngineTrace *this,
        const Vector *vecAbsMins,
        const Vector *vecAbsMaxs,
        IEntityEnumerator *pEnumerator)
{
  ISpatialPartitionInternal *v5; // ebx
  ISpatialPartitionInternal_vtbl *v6; // edi
  int v7; // eax
  CEnumerationFilter enumerator; // [esp+Ch] [ebp-Ch] BYREF

  ++this->m_traceStatCounters[2];
  enumerator.__vftable = (CEnumerationFilter_vtbl *)&CEnumerationFilter::`vftable';
  enumerator.m_pEnumerator = pEnumerator;
  enumerator.m_pEngineTrace = this;
  v5 = SpatialPartition();
  v6 = v5->__vftable;
  v7 = ((int (__thiscall *)(CEngineTrace *, const Vector *, const Vector *, _DWORD, CEnumerationFilter *))this->SpatialPartitionMask)(
         a1: this,
         a2: vecAbsMins,
         a3: vecAbsMaxs,
         a4: 0,
         a5: &enumerator);
  ((void (__thiscall *)(ISpatialPartitionInternal *, int))v6->EnumerateElementsInBox)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10175710
// Name: public: virtual void CEngineTrace::FreeTraceListData(class ITraceListData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::FreeTraceListData(CEngineTrace *this, ITraceListData *pTraceListData)
{
  if ( pTraceListData != nullptr )
    ((void (__thiscall *)(ITraceListData *, int))pTraceListData->dtr_ITraceListData)(a1: pTraceListData, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10175730
// Name: public: static bool CPointContentsEnum::TestEntity(class CEngineTrace __near *,class ICollideable __near *,class Vector const __near &,int,int __near *,class ICollideable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPointContentsEnum::TestEntity@<al>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CEngineTrace *pEngineTrace,
        ICollideable *pCollide,
        const Vector *vPos,
        int validMask,
        int *pContents,
        ICollideable **pWorldCollideable)
{
  IStaticPropMgrEngine *v9; // eax
  IStaticPropMgrEngine_vtbl *v10; // edi
  int v11; // eax
  const model_t *v13; // eax
  int ModelHeadNode; // edi
  const QAngle *v15; // eax
  ICollideable_vtbl *v16; // edx
  const Vector *v17; // eax
  int v18; // eax
  int v19; // [esp-14h] [ebp-CCh]
  int v20; // [esp-10h] [ebp-C8h]
  _DWORD v21[3]; // [esp-Ch] [ebp-C4h] BYREF
  CGameTrace trace; // [esp+0h] [ebp-B8h] BYREF
  int v23; // [esp+54h] [ebp-64h]
  Ray_t ray; // [esp+58h] [ebp-60h]
  IStaticPropMgrEngine *v25; // [esp+A8h] [ebp-10h]
  int v26; // [esp+ACh] [ebp-Ch]
  void *v27; // [esp+B0h] [ebp-8h]
  void *retaddr; // [esp+B8h] [ebp+0h]

  v26 = a1;
  v27 = retaddr;
  v20 = a3;
  v19 = a2;
  if ( (validMask & 1) != 0
    && (v9 = StaticPropMgr(),
        v10 = v9->__vftable,
        v25 = v9,
        v11 = ((int (__thiscall *)(ICollideable *, int, int))pCollide->GetEntityHandle)(a1: pCollide, a2: v19, a3),
        v10->IsStaticProp_2(this: v25, a2: (IHandleEntity *)v11)) )
  {
    ray.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)&trace.m_pEnt, start: vPos, end: vPos);
    ((void (__thiscall *)(CEngineTrace *, struct CBaseEntity **, int, ICollideable *, _DWORD *, int, int))pEngineTrace->ClipRayToCollideable)(
      a1: pEngineTrace,
      a2: &trace.m_pEnt,
      a3: -1,
      a4: pCollide,
      a5: v21,
      a6: v19,
      a7: v20);
    if ( trace.plane.pad[1] != 0 )
    {
      *pContents = 1;
      *pWorldCollideable = pEngineTrace->GetWorldCollideable(this: pEngineTrace);
      return 1;
    }
  }
  else if ( (((int (__thiscall *)(ICollideable *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD))pCollide->GetSolidFlags)(
               a1: pCollide,
               a2: v19,
               a3: v20,
               a4: v21[0],
               a5: v21[1],
               a6: v21[2],
               a7: LODWORD(trace.startpos.x),
               a8: LODWORD(trace.startpos.y),
               a9: LODWORD(trace.startpos.z),
               a10: LODWORD(trace.endpos.x),
               a11: LODWORD(trace.endpos.y),
               a12: LODWORD(trace.endpos.z),
               a13: LODWORD(trace.plane.normal.x),
               a14: LODWORD(trace.plane.normal.y),
               a15: LODWORD(trace.plane.normal.z),
               a16: LODWORD(trace.plane.dist),
               a17: *(_DWORD *)&trace.plane.type,
               a18: LODWORD(trace.fraction),
               a19: trace.contents,
               a20: *(_DWORD *)&trace.dispFlags,
               a21: LODWORD(trace.fractionleftsolid),
               a22: trace.surface.name,
               a23: *(_DWORD *)&trace.surface.surfaceProps,
               a24: trace.hitgroup,
               a25: *(_DWORD *)&trace.physicsbone,
               a26: trace.m_pEnt,
               a27: trace.hitbox,
               a28: v23,
               a29: LODWORD(ray.m_Start.x),
               a30: LODWORD(ray.m_Start.y),
               a31: LODWORD(ray.m_Start.z),
               a32: LODWORD(ray.m_Start.w),
               a33: LODWORD(ray.m_Delta.x),
               a34: LODWORD(ray.m_Delta.y),
               a35: LODWORD(ray.m_Delta.z),
               a36: LODWORD(ray.m_Delta.w),
               a37: LODWORD(ray.m_StartOffset.x),
               a38: LODWORD(ray.m_StartOffset.y),
               a39: LODWORD(ray.m_StartOffset.z),
               a40: LODWORD(ray.m_StartOffset.w),
               a41: LODWORD(ray.m_Extents.x),
               a42: LODWORD(ray.m_Extents.y),
               a43: LODWORD(ray.m_Extents.z),
               a44: LODWORD(ray.m_Extents.w),
               a45: ray.m_pWorldAxisTransform,
               a46: *(_DWORD *)&ray.m_IsRay,
               a47: *(_DWORD *)(&ray.m_IsSwept + 3),
               a48: *(_DWORD *)(&ray.m_IsSwept + 7))
           & 0x20) != 0 )
  {
    v13 = pCollide->GetCollisionModel(this: pCollide);
    if ( v13 != nullptr && v13->type == mod_brush )
    {
      ModelHeadNode = CPointContentsEnum::GetModelHeadNode(pCollide);
      v15 = pCollide->GetCollisionAngles(this: pCollide);
      v16 = pCollide->__vftable;
      *(_DWORD *)(&ray.m_IsSwept + 7) = v15;
      v17 = v16->GetCollisionOrigin(this: pCollide);
      v18 = CM_TransformedPointContents(
              p: vPos,
              headnode: ModelHeadNode,
              origin: v17,
              angles: *(const QAngle **)(&ray.m_IsSwept + 7));
      if ( (v18 & validMask) != 0 )
      {
        *pContents = v18;
        *pWorldCollideable = pCollide;
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175850
// Name: public: virtual enum IterationRetval_t CPointContentsEnum::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CPointContentsEnum::EnumElement(CPointContentsEnum *this, IHandleEntity *pHandleEntity)
{
  ICollideable *result; // eax

  result = this->m_pEngineTrace->HandleEntityToCollideable(this: this->m_pEngineTrace, a2: pHandleEntity);
  if ( result != nullptr )
    return (ICollideable *)CPointContentsEnum::TestEntity(
                             pEngineTrace: this->m_pEngineTrace,
                             pCollide: result,
                             vPos: &this->m_Pos,
                             validMask: this->m_validMask,
                             pContents: &this->m_Contents,
                             pWorldCollideable: &this->m_pCollide);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101758A0
// Name: public: virtual int CEngineTrace::GetPointContents_Collideable(class ICollideable __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CEngineTrace::GetPointContents_Collideable@<eax>(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        ICollideable *pCollide,
        const Vector *vecAbsPosition)
{
  IStaticPropMgrEngine *v6; // eax
  IStaticPropMgrEngine_vtbl *v7; // edi
  int v8; // eax
  CEngineTrace *v9; // edi
  int result; // eax
  const model_t *v11; // eax
  int ModelHeadNode; // edi
  const Vector *v13; // eax
  _DWORD v15[22]; // [esp-B8h] [ebp-C4h] BYREF
  Ray_t v16; // [esp-60h] [ebp-6Ch] BYREF
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-Ch] [ebp-18h]
  const QAngle *v19; // [esp-8h] [ebp-14h]
  CEngineTrace *v20; // [esp-4h] [ebp-10h]
  int v21; // [esp+0h] [ebp-Ch]
  void *v22; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  v20 = this;
  v6 = StaticPropMgr();
  v7 = v6->__vftable;
  v8 = ((int (__thiscall *)(ICollideable *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, int, int, IStaticPropMgrEngine *))pCollide->GetEntityHandle)(
         a1: pCollide,
         a2: a3,
         a3: a4,
         a4: v15[0],
         a5: v15[1],
         a6: v15[2],
         a7: v15[3],
         a8: v15[4],
         a9: v15[5],
         a10: v15[6],
         a11: v15[7],
         a12: v15[8],
         a13: v15[9],
         a14: v15[10],
         a15: v15[11],
         a16: v15[12],
         a17: v15[13],
         a18: v15[14],
         a19: v15[15],
         a20: v15[16],
         a21: v15[17],
         a22: v15[18],
         a23: v15[19],
         a24: v15[20],
         a25: v15[21],
         a26: LODWORD(v16.m_Start.x),
         a27: LODWORD(v16.m_Start.y),
         a28: LODWORD(v16.m_Start.z),
         a29: LODWORD(v16.m_Start.w),
         a30: LODWORD(v16.m_Delta.x),
         a31: LODWORD(v16.m_Delta.y),
         a32: LODWORD(v16.m_Delta.z),
         a33: LODWORD(v16.m_Delta.w),
         a34: LODWORD(v16.m_StartOffset.x),
         a35: LODWORD(v16.m_StartOffset.y),
         a36: LODWORD(v16.m_StartOffset.z),
         a37: LODWORD(v16.m_StartOffset.w),
         a38: LODWORD(v16.m_Extents.x),
         a39: LODWORD(v16.m_Extents.y),
         a40: LODWORD(v16.m_Extents.z),
         a41: LODWORD(v16.m_Extents.w),
         a42: v16.m_pWorldAxisTransform,
         a43: *(_DWORD *)&v16.m_IsRay,
         a44: *(_DWORD *)(&v16.m_IsSwept + 3),
         a45: *(_DWORD *)(&v16.m_IsSwept + 7),
         a46: v17,
         a47: v18,
         a48: v6);
  if ( v7->IsStaticProp_2(this: (IStaticPropMgrEngine *)v19, a2: (IHandleEntity *)v8) )
  {
    v16.m_pWorldAxisTransform = nullptr;
    Ray_t::Init(this: &v16, start: vecAbsPosition, end: vecAbsPosition);
    v9 = v20;
    v20->ClipRayToCollideable(this: v20, a2: &v16, a3: -1u, a4: pCollide, a5: (CGameTrace *)v15);
    if ( HIBYTE(v15[13]) != 0 )
    {
      v9->GetWorldCollideable(this: v9);
      return 1;
    }
  }
  else if ( (pCollide->GetSolidFlags(this: pCollide) & 0x20) != 0 )
  {
    v11 = pCollide->GetCollisionModel(this: pCollide);
    if ( v11 != nullptr && v11->type == mod_brush )
    {
      ModelHeadNode = CPointContentsEnum::GetModelHeadNode(pCollide);
      v19 = pCollide->GetCollisionAngles(this: pCollide);
      v13 = pCollide->GetCollisionOrigin(this: pCollide);
      result = CM_TransformedPointContents(p: vecAbsPosition, headnode: ModelHeadNode, origin: v13, angles: v19);
      if ( result != 0 )
        return result;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101759A0
// Name: GetBrushesInCollideable_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBrushesInCollideable_r(
        CCollisionBSPData *pBSPData,
        unsigned int *pVisitedBrushes,
        unsigned int **pKeepBrushes,
        int node)
{
  int i; // eax
  cnode_t *v5; // edi
  unsigned int v6; // ecx
  cleaf_t *v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  cleaf_t *m_pArray; // eax
  int numleafbrushes; // edi

  for ( i = node; i >= 0; i = v5->children[1] )
  {
    v5 = &pBSPData->map_nodes.m_pArray[i];
    GetBrushesInCollideable_r(pBSPData, pVisitedBrushes, pKeepBrushes, node: v5->children[0]);
  }
  v6 = -1 - i;
  v7 = &pBSPData->map_leafs.m_pArray[v6];
  v8 = 0;
  if ( v7->numleafbrushes != 0 )
  {
    do
    {
      v9 = pBSPData->map_leafbrushes.m_pArray[v8 + v7->firstleafbrush];
      if ( pVisitedBrushes[v9] == 0 )
      {
        pVisitedBrushes[v9] = 1;
        *(*pKeepBrushes)++ = v9;
      }
      m_pArray = pBSPData->map_leafs.m_pArray;
      numleafbrushes = m_pArray[v6].numleafbrushes;
      v7 = &m_pArray[v6];
      ++v8;
    }
    while ( v8 < numleafbrushes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175A40
// Name: public: virtual int CEngineTrace::GetBrushInfo(int,int __near &,struct BrushSideInfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetBrushInfo(
        CEngineTrace *this,
        int iBrush,
        int *ContentsOut,
        BrushSideInfo_t *pBrushSideInfoOut,
        int iBrushSideInfoArraySize)
{
  cbrush_t *v5; // edx
  int numsides; // eax
  int v7; // ebx
  float *p_dist; // esi
  int v9; // edi
  __int16 v10; // ax
  int firstbrushside; // eax
  cbrushside_t *v13; // edi
  cbrushside_t *v14; // esi
  float *p_z; // eax
  float *p_x; // ecx
  double x; // st7
  cboxbrush_t *pBox; // [esp+8h] [ebp+8h]
  BrushSideInfo_t *pBrushSideInfoOuta; // [esp+10h] [ebp+10h]
  BrushSideInfo_t *iBrushSideInfoArraySizea; // [esp+14h] [ebp+14h]

  if ( iBrush < 0 || iBrush >= g_BSPData.numbrushes )
    return 0;
  v5 = &g_BSPData.map_brushes.m_pArray[iBrush];
  *ContentsOut = v5->contents;
  numsides = v5->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    if ( pBrushSideInfoOut != nullptr && iBrushSideInfoArraySize >= 6 )
    {
      v7 = 0;
      iBrushSideInfoArraySizea = pBrushSideInfoOut;
      pBox = &g_BSPData.map_boxbrushes.m_pArray[v5->firstbrushside];
      p_dist = &pBrushSideInfoOut->plane.dist;
      v9 = 1;
      pBrushSideInfoOuta = (BrushSideInfo_t *)&pBox[-1].surfaceIndex[2];
      do
      {
        _V_memset(dest: p_dist - 3, fill: 0, count: 20);
        v10 = v9;
        if ( v7 >= 3 )
        {
          iBrushSideInfoArraySizea[-1].plane.dist = -1.0;
          *(_DWORD *)p_dist = LODWORD(pBrushSideInfoOuta->plane.normal.x) ^ _mask__NegFloat_;
        }
        else
        {
          iBrushSideInfoArraySizea->plane.normal.x = 1.0;
          *p_dist = pBrushSideInfoOuta[1].plane.normal.y;
          v10 = __ROL4__(v9, 3);
        }
        *((_WORD *)p_dist + 4) = 0;
        pBrushSideInfoOuta = (BrushSideInfo_t *)((char *)pBrushSideInfoOuta + 4);
        iBrushSideInfoArraySizea = (BrushSideInfo_t *)((char *)iBrushSideInfoArraySizea + 28);
        *((_WORD *)p_dist + 5) = (unsigned __int16)(v10 & pBox->thinMask) != 0;
        ++v7;
        p_dist += 6;
        v9 = __ROL4__(v9, 1);
      }
      while ( v7 < 6 );
      return 6;
    }
    else
    {
      return -6;
    }
  }
  else if ( pBrushSideInfoOut != nullptr && iBrushSideInfoArraySize >= numsides )
  {
    firstbrushside = v5->firstbrushside;
    v13 = &g_BSPData.map_brushsides.m_pArray[firstbrushside + v5->numsides];
    v14 = &g_BSPData.map_brushsides.m_pArray[firstbrushside];
    if ( v14 != v13 )
    {
      p_z = &pBrushSideInfoOut->plane.normal.z;
      do
      {
        p_x = &v14->plane->normal.x;
        x = v14->plane->normal.x;
        ++v14;
        *(p_z - 2) = x;
        p_z += 6;
        *(p_z - 7) = p_x[1];
        *(p_z - 6) = p_x[2];
        *(p_z - 5) = p_x[3];
        *((_BYTE *)p_z - 16) = *((_BYTE *)p_x + 16);
        *((_BYTE *)p_z - 15) = *((_BYTE *)p_x + 17);
        *((_BYTE *)p_z - 14) = *((_BYTE *)p_x + 18);
        *((_BYTE *)p_z - 13) = *((_BYTE *)p_x + 19);
        *((_WORD *)p_z - 6) = v14[-1].bBevel;
        *((_WORD *)p_z - 5) = v14[-1].bThin;
      }
      while ( v14 != v13 );
    }
    return v5->numsides;
  }
  else
  {
    return -numsides;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175BE0
// Name: public: virtual bool CEngineTrace::PointOutsideWorld(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTrace::PointOutsideWorld(CEngineTrace *this, const Vector *ptTest)
{
  return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum(p: ptTest)].cluster == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10175C10
// Name: public: virtual unsigned int CBrushConvexInfo::GetContents(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushConvexInfo::GetContents(CBrushConvexInfo *this, int convexGameData)
{
  return this->m_pBSPData->map_brushes.m_pArray[convexGameData].contents;
}

//------------------------------------------------------------------------------
// Address: 0x10175C30
// Name: private: bool CEngineTrace::ClipRayToVPhysics(struct Ray_t const __near &,unsigned int,class ICollideable __near *,struct studiohdr_t __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToVPhysics(
        CEngineTrace *this,
        const Ray_t *ray,
        __int64 fMask,
        studiohdr_t *pStudioHdr,
        CGameTrace *pTrace)
{
  int v5; // esi
  int v7; // edi
  int v8; // eax
  int v9; // edi
  IPhysicsCollision_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  float *v13; // eax
  int v14; // eax
  float v15; // ecx
  float v16; // edx
  int v17; // eax
  vcollide_t *v18; // edi
  IPhysicsCollision_vtbl *v19; // ebx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  vcollide_t *v23; // eax
  vcollide_t *v24; // ebx
  char *v25; // edi
  int v26; // eax
  int v27; // eax
  float v28; // [esp+3Ch] [ebp-18h]
  float v29; // [esp+40h] [ebp-14h]
  float v30; // [esp+44h] [ebp-10h]
  double v31; // [esp+48h] [ebp-Ch] BYREF
  double var3C; // [esp+50h] [ebp-4h]
  char v33; // [esp+67h] [ebp+13h]

  v5 = HIDWORD(fMask);
  if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(fMask) + 44))(a1: HIDWORD(fMask)) != 6 )
    return 0;
  v33 = 0;
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(a1: v5);
  if ( v7 != 0 )
  {
    if ( pStudioHdr != nullptr )
    {
      LODWORD(var3C) = pStudioHdr;
      v17 = *(unsigned __int16 *)(v7 + 312);
      HIDWORD(v31) = &CStudioConvexInfo::`vftable';
      v18 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: v17);
      if ( v18 != nullptr && (*(_WORD *)v18 & 0x7FFF) != 0 )
      {
        v19 = physcollision->__vftable;
        v20 = (*(int (__thiscall **)(int, CGameTrace *))(*(_DWORD *)v5 + 36))(a1: v5, a2: pTrace);
        v21 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 32))(a1: v5, a2: v20);
        ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, _DWORD, char *, struct CPhysCollide *, int))v19->TraceBox)(
          a1: physcollision,
          a2: ray,
          a3: fMask,
          a4: (char *)&v31 + 4,
          a5: *v18->solids,
          a6: v21);
        return 1;
      }
    }
    else if ( !ray->m_IsRay || *(_DWORD *)(v7 + 272) != 1 )
    {
      v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 24))(a1: v5);
      v23 = CM_VCollideForModel(modelindex: v22, pModel: (const model_t *)v7);
      v24 = v23;
      if ( v23 != nullptr && (*(_WORD *)v23 & 0x7FFF) != 0 )
      {
        v25 = *(_DWORD *)(v7 + 272) == 1 ? (char *)((unsigned int)&v31 + 4) : nullptr;
        HIDWORD(v31) = &CBrushConvexInfo::`vftable';
        LODWORD(var3C) = &g_BSPData;
        HIDWORD(fMask) = (IPhysicsCollision)physcollision->__vftable;
        v26 = (*(int (__thiscall **)(int, CGameTrace *))(*(_DWORD *)v5 + 36))(a1: v5, a2: pTrace);
        v27 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 32))(a1: v5, a2: v26);
        (*(void (__thiscall **)(IPhysicsCollision *, const Ray_t *, _DWORD, char *, struct CPhysCollide *, int))(HIDWORD(fMask) + 124))(
          a1: physcollision,
          a2: ray,
          a3: fMask,
          a4: v25,
          a5: *v24->solids,
          a6: v27);
        return 1;
      }
    }
    return v33;
  }
  else
  {
    v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 72))(a1: v5);
    if ( v8 != 0 && (v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 296))(a1: v8)) != 0 )
    {
      v10 = physcollision->__vftable;
      v11 = (*(int (__thiscall **)(int, CGameTrace *))(*(_DWORD *)v5 + 36))(a1: v5, a2: pTrace);
      v12 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 32))(a1: v5, a2: v11);
      ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, _DWORD, _DWORD, int, int))v10->TraceBox)(
        a1: physcollision,
        a2: ray,
        a3: fMask,
        a4: 0,
        a5: v9,
        a6: v12);
      return 1;
    }
    else
    {
      v13 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
      v29 = v13[1];
      v28 = *v13;
      v30 = v13[2];
      v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
      v15 = *(float *)v14;
      v16 = *(float *)(v14 + 4);
      LODWORD(var3C) = *(_DWORD *)(v14 + 8);
      *((float *)&v31 + 1) = v16;
      _Warning(
        a1: "CEngineTrace::ClipRayToVPhysics : no model; bbox {%g,%g,%g}-{%g,%g,%g}\n",
        v28,
        v29,
        v30,
        v15,
        v16,
        *(float *)&var3C);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175E80
// Name: private: bool CEngineTrace::ClipRayToBBox(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CEngineTrace::ClipRayToBBox@<al>(
        CEngineTrace *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const matrix3x4_t *v9; // ecx
  const matrix3x4_t *m_pWorldAxisTransform; // ecx
  Vector *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  ICollideable_vtbl *v15; // edx
  const Vector *(__thiscall *GetCollisionOrigin)(ICollideable *); // eax
  const float *v17; // eax
  bool m_IsSwept; // cl
  ICollideable_vtbl *v19; // edx
  const Vector *(__thiscall *v20)(ICollideable *); // eax
  float *v21; // eax
  ICollideable_vtbl *v22; // edx
  float v23; // xmm0_4
  const Vector *(__thiscall *v24)(ICollideable *); // eax
  float *v25; // eax
  float v26; // xmm0_4
  const matrix3x4_t *v27; // edx
  float v28; // xmm0_4
  float fraction; // xmm0_4
  float v30; // eax
  float v31; // xmm0_4
  float fractionleftsolid; // xmm0_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float x; // xmm0_4
  float v39; // xmm3_4
  float y; // xmm2_4
  float v41; // xmm0_4
  float z; // xmm2_4
  float v43; // xmm1_4
  const Vector *(__thiscall *OBBMins)(ICollideable *); // eax
  float v45; // eax
  ICollideable_vtbl *v46; // edx
  float *v47; // eax
  ICollideable_vtbl *v48; // edx
  float v49; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // eax
  float v51; // eax
  ICollideable_vtbl *v52; // edx
  float *v53; // eax
  float v54[3]; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t ray_l; // [esp+0h] [ebp-B0h] BYREF
  float v56; // [esp+50h] [ebp-60h]
  Vector temp; // [esp+54h] [ebp-5Ch] BYREF
  VectorAligned vecAbsMins; // [esp+60h] [ebp-50h] BYREF
  VectorAligned vecInvDelta; // [esp+70h] [ebp-40h] BYREF
  float v60[2]; // [esp+90h] [ebp-20h] BYREF
  const matrix3x4_t *v61; // [esp+98h] [ebp-18h]
  Vector localEntityOrigin; // [esp+9Ch] [ebp-14h]
  void *v63; // [esp+A8h] [ebp-8h]
  void *retaddr; // [esp+B0h] [ebp+0h]

  localEntityOrigin.z = a2;
  v63 = retaddr;
  if ( ((int (__thiscall *)(ICollideable *, int, int))pEntity->GetSolid)(a1: pEntity, a2: a3, a3: a4) != 2 )
    return 0;
  if ( ray->m_IsRay || (v9 = ray->m_pWorldAxisTransform, *(float *)&v9 == 0.0) )
  {
    x = ray->m_Delta.x;
    if ( x == 0.0 )
      v39 = 3.4028235e38;
    else
      v39 = 1.0 / x;
    y = ray->m_Delta.y;
    if ( y == 0.0 )
      v41 = 3.4028235e38;
    else
      v41 = 1.0 / y;
    z = ray->m_Delta.z;
    if ( z == 0.0 )
      v43 = 3.4028235e38;
    else
      v43 = 1.0 / z;
    OBBMins = pEntity->OBBMins;
    vecAbsMins.y = v39;
    vecAbsMins.z = v41;
    vecAbsMins.w = v43;
    v45 = COERCE_FLOAT((int)OBBMins(this: pEntity));
    v46 = pEntity->__vftable;
    localEntityOrigin.y = v45;
    v47 = (float *)v46->GetCollisionOrigin(this: pEntity);
    v48 = pEntity->__vftable;
    temp.x = *(float *)LODWORD(localEntityOrigin.y) + *v47;
    temp.y = v47[1] + *(float *)(LODWORD(localEntityOrigin.y) + 4);
    v49 = v47[2] + *(float *)(LODWORD(localEntityOrigin.y) + 8);
    OBBMaxs = v48->OBBMaxs;
    temp.z = v49;
    v51 = COERCE_FLOAT((int)OBBMaxs(this: pEntity));
    v52 = pEntity->__vftable;
    localEntityOrigin.y = v51;
    v53 = (float *)v52->GetCollisionOrigin(this: pEntity);
    vecInvDelta.y = *v53 + *(float *)LODWORD(localEntityOrigin.y);
    vecInvDelta.z = v53[1] + *(float *)(LODWORD(localEntityOrigin.y) + 4);
    vecInvDelta.w = v53[2] + *(float *)(LODWORD(localEntityOrigin.y) + 8);
    IntersectRayWithBox(
      ray,
      inInvDelta: (VectorAligned *)&vecAbsMins.y,
      inBoxMins: (const VectorAligned *)&temp,
      inBoxMaxs: (VectorAligned *)&vecInvDelta.y,
      pTrace);
  }
  else
  {
    LODWORD(localEntityOrigin.x) = &ray_l.m_Start.y;
    v61 = v9;
    ray_l.m_Extents.y = 0.0;
    *(VectorAligned *)((char *)&ray_l.m_StartOffset + 4) = ray->m_Extents;
    VectorIRotate(in1: &ray->m_Delta.x, in2: v9, out: &ray->m_Delta.x);
    m_pWorldAxisTransform = ray->m_pWorldAxisTransform;
    memset(&ray_l.m_Delta.y, 0, 12);
    VectorITransform(in1: &ray->m_Start.x, in2: m_pWorldAxisTransform, out: v54);
    v11 = Ray_t::InvDelta(this: (Ray_t *)v54, result: (Vector *)(&ray_l.m_IsSwept + 3));
    v12 = v11->y;
    v13 = v11->z;
    v14 = v11->x;
    v15 = pEntity->__vftable;
    LODWORD(localEntityOrigin.y) = ray->m_pWorldAxisTransform;
    GetCollisionOrigin = v15->GetCollisionOrigin;
    vecAbsMins.y = v14;
    vecAbsMins.z = v12;
    vecAbsMins.w = v13;
    v17 = (const float *)GetCollisionOrigin(this: pEntity);
    VectorITransform(in1: v17, in2: (const matrix3x4_t *)LODWORD(localEntityOrigin.y), out: v60);
    m_IsSwept = ray->m_IsSwept;
    v19 = pEntity->__vftable;
    LOBYTE(ray_l.m_Extents.z) = ray->m_IsRay;
    v20 = v19->OBBMins;
    BYTE1(ray_l.m_Extents.z) = m_IsSwept;
    v21 = (float *)v20(this: pEntity);
    v22 = pEntity->__vftable;
    temp.x = *v21 + v60[0];
    temp.y = v21[1] + v60[1];
    v23 = v21[2] + *(float *)&v61;
    v24 = v22->OBBMaxs;
    temp.z = v23;
    v25 = (float *)v24(this: pEntity);
    vecInvDelta.y = *v25 + v60[0];
    v26 = v25[1] + v60[1];
    LODWORD(localEntityOrigin.x) = pTrace;
    vecInvDelta.z = v26;
    vecInvDelta.w = v25[2] + *(float *)&v61;
    IntersectRayWithBox(
      ray: (const Ray_t *)v54,
      inInvDelta: (VectorAligned *)&vecAbsMins.y,
      inBoxMins: (const VectorAligned *)&temp,
      inBoxMaxs: (VectorAligned *)&vecInvDelta.y,
      pTrace);
    if ( pTrace->fraction >= 1.0 && !pTrace->allsolid && !pTrace->startsolid )
    {
      pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
      pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
      pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
      return 1;
    }
    v27 = ray->m_pWorldAxisTransform;
    *(float *)(&ray_l.m_IsSwept + 3) = pTrace->plane.normal.x;
    v28 = pTrace->plane.normal.y;
    LODWORD(localEntityOrigin.x) = &pTrace->plane;
    *(float *)(&ray_l.m_IsSwept + 7) = v28;
    v56 = pTrace->plane.normal.z;
    VectorRotate(in1: (const float *)(&ray_l.m_IsSwept + 3), in2: v27, out: &pTrace->plane.normal.x);
    pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    fraction = pTrace->fraction;
    v30 = localEntityOrigin.x;
    if ( fraction == 1.0 )
    {
      pTrace->endpos.x = *(float *)LODWORD(localEntityOrigin.x) + pTrace->startpos.x;
      pTrace->endpos.y = *(float *)(LODWORD(v30) + 4) + pTrace->startpos.y;
      v31 = pTrace->startpos.z + *(float *)(LODWORD(v30) + 8);
    }
    else
    {
      pTrace->endpos.x = (float)(*(float *)LODWORD(localEntityOrigin.x) * fraction) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(*(float *)(LODWORD(v30) + 4) * fraction) + pTrace->startpos.y;
      v31 = (float)(fraction * *(float *)(LODWORD(v30) + 8)) + pTrace->startpos.z;
    }
    pTrace->endpos.z = v31;
    pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                               + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                       + (float)(pTrace->endpos.z * pTrace->plane.normal.z);
    fractionleftsolid = pTrace->fractionleftsolid;
    if ( fractionleftsolid < 1.0 )
    {
      v33 = pTrace->startpos.x;
      v34 = (float)(*(float *)(LODWORD(v30) + 4) * fractionleftsolid) + pTrace->startpos.y;
      v35 = *(float *)LODWORD(v30) * fractionleftsolid;
      v36 = fractionleftsolid * *(float *)(LODWORD(v30) + 8);
      pTrace->startpos.y = v34;
      v37 = pTrace->startpos.z + v36;
      pTrace->startpos.x = v33 + v35;
      pTrace->startpos.z = v37;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101762D0
// Name: public: virtual void CEngineTrace::SweepCollideable(class ICollideable __near *,class Vector const __near &,class Vector const __near &,class QAngle const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::SweepCollideable(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        ICollideable *pCollide,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const QAngle *vecAngles,
        float fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  int v13; // eax
  const Vector *v14; // eax
  void (__thiscall *TraceRay)(struct CEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  _BYTE v18[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  v13 = ((int (__thiscall *)(ICollideable *, int, int))pCollide->OBBMaxs)(a1: pCollide, a2: a3, a3: a4);
  v14 = (const Vector *)((int (__thiscall *)(ICollideable *, int))pCollide->OBBMins)(a1: pCollide, a2: v13);
  Ray_t::Init(
    this: (Ray_t *)v18,
    start: vecAbsStart,
    end: vecAbsEnd,
    mins: v14,
    maxs: (const Vector *)ray.m_pWorldAxisTransform);
  if ( (pCollide->GetSolidFlags(this: pCollide) & 0x100) != 0 )
    LODWORD(ray.m_Extents.y) = pCollide->GetRootParentToWorldTransform(this: pCollide);
  TraceRay = this->TraceRay;
  ray.m_pWorldAxisTransform = (const matrix3x4_t *)pTrace;
  LODWORD(ray.m_Extents.w) = pTraceFilter;
  ray.m_Extents.z = fMask;
  ((void (__thiscall *)(CEngineTrace *, _BYTE *))TraceRay)(a1: this, a2: v18);
}

//------------------------------------------------------------------------------
// Address: 0x101763C0
// Name: public: virtual void CEngineTrace::GetBrushesInAABB(class Vector const __near &,class Vector const __near &,class CBrushQuery __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetBrushesInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs,
        CBrushQuery *BrushQuery,
        int nContentsMask,
        cleaf_t *nCModelIndex)
{
  void (__cdecl *m_pReleaseFunc)(CBrushQuery *); // eax
  TraceInfo_t *v7; // esi
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  CCollisionBSPData *m_pBSPData; // eax
  void *v19; // esp
  int v20; // eax
  unsigned int *m_pMemory; // ebx
  int v22; // edi
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edi
  cbrush_t *m_pArray; // ecx
  cbrush_t *v28; // ebx
  int numsides; // eax
  int v30; // edx
  unsigned int *v31; // edx
  unsigned int v32; // [esp-1Ch] [ebp-58h]
  int v33[3]; // [esp+0h] [ebp-3Ch] BYREF
  Vector vExtents; // [esp+Ch] [ebp-30h]
  Vector vCenter; // [esp+18h] [ebp-24h]
  int iNumLeafs; // [esp+24h] [ebp-18h]
  int *pLeafList; // [esp+28h] [ebp-14h]
  unsigned int *pKeepBrushes; // [esp+2Ch] [ebp-10h]
  int iLeaf; // [esp+30h] [ebp-Ch]
  unsigned int *pVisitedBrushes; // [esp+34h] [ebp-8h]
  int iBrushCounter; // [esp+38h] [ebp-4h]
  int iMaxBrushSides; // [esp+44h] [ebp+8h]
  int iKeepBrushCounta; // [esp+48h] [ebp+Ch]
  int iKeepBrushCount; // [esp+48h] [ebp+Ch]
  cleaf_t *pLeaf; // [esp+54h] [ebp+18h]

  m_pReleaseFunc = BrushQuery->m_pReleaseFunc;
  if ( m_pReleaseFunc != nullptr )
    m_pReleaseFunc(a1: BrushQuery);
  BrushQuery->m_iCount = 0;
  BrushQuery->m_pBrushes = nullptr;
  BrushQuery->m_iMaxBrushSides = 0;
  BrushQuery->m_pReleaseFunc = nullptr;
  BrushQuery->m_pData = nullptr;
  v7 = BeginTrace();
  if ( nContentsMask == 0x40000 && host_state.worldbrush->m_pSurfaceBrushList == nullptr )
    nContentsMask = -1;
  x = vMaxs->x;
  y = vMaxs->y;
  z = vMaxs->z;
  v12 = (float)(vMins->y + y) * 0.5;
  v13 = (float)(vMins->z + z) * 0.5;
  vCenter.x = (float)(vMins->x + vMaxs->x) * 0.5;
  vCenter.y = v12;
  vCenter.z = v13;
  vExtents.x = x - vCenter.x;
  vExtents.y = y - v12;
  vExtents.z = z - v13;
  CM_ClearTrace(trace: &v7->m_trace);
  v7->m_bDispHit = 0;
  v7->m_DispStabDir.x = 0.0;
  v7->m_DispStabDir.y = 0.0;
  v7->m_DispStabDir.z = 0.0;
  v14 = vCenter.x;
  v7->m_start.y = v12;
  v7->m_start.z = v13;
  v7->m_start.x = v14;
  v7->m_contents = nContentsMask;
  v7->m_end.y = v12;
  v7->m_end.x = v14;
  v15 = vExtents.x;
  v7->m_end.z = v13;
  v7->m_mins.x = v15 * -1.0;
  v16 = vExtents.y;
  v7->m_mins.y = vExtents.y * -1.0;
  v17 = vExtents.z;
  v7->m_mins.z = vExtents.z * -1.0;
  v7->m_maxs.x = v15;
  v7->m_maxs.y = v16;
  v7->m_maxs.z = v17;
  v7->m_extents.x = v15;
  v7->m_extents.y = v16;
  v7->m_extents.z = v17;
  v7->m_delta = vec3_origin;
  v7->m_invDelta = vec3_origin;
  m_pBSPData = v7->m_pBSPData;
  *(_WORD *)&v7->m_ispoint = 0;
  iKeepBrushCounta = m_pBSPData->numleafs;
  v19 = alloca(4 * iKeepBrushCounta);
  pLeafList = v33;
  v20 = CM_BoxLeafnums(
          mins: vMins,
          maxs: vMaxs,
          list: v33,
          listsize: iKeepBrushCounta,
          topnode: nullptr,
          cmodelIndex: (int)nCModelIndex);
  m_pMemory = v7->m_BrushCounters[0].m_Memory.m_pMemory;
  v22 = v20;
  v32 = 4 * v7->m_BrushCounters[0].m_Size;
  iNumLeafs = v20;
  pVisitedBrushes = m_pMemory;
  memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: v32);
  v23 = 0;
  pKeepBrushes = v7->m_BrushCounters[1].m_Memory.m_pMemory;
  iKeepBrushCount = 0;
  iMaxBrushSides = 0;
  iLeaf = 0;
  if ( v22 != 0 )
  {
    do
    {
      v24 = (int)&v7->m_pBSPData->map_leafs.m_pArray[pLeafList[v23]];
      v25 = 0;
      pLeaf = (cleaf_t *)v24;
      iBrushCounter = 0;
      if ( *(_WORD *)(v24 + 10) != 0 )
      {
        do
        {
          v26 = v7->m_pBSPData->map_leafbrushes.m_pArray[v25 + *(unsigned __int16 *)(v24 + 8)];
          if ( m_pMemory[v26] == 0 )
          {
            m_pMemory[v26] = 1;
            m_pArray = v7->m_pBSPData->map_brushes.m_pArray;
            v28 = &m_pArray[v26];
            if ( (nContentsMask & v28->contents) != 0 )
            {
              CM_TestBoxInBrush(pTraceInfo: v7, brush: &m_pArray[v26]);
              if ( v7->m_trace.allsolid )
              {
                pKeepBrushes[iKeepBrushCount++] = v26;
                numsides = v28->numsides;
                if ( (_WORD)numsides == 0xFFFF )
                  numsides = 6;
                if ( numsides > iMaxBrushSides )
                  iMaxBrushSides = numsides;
                v7->m_trace.allsolid = false;
              }
              v24 = (int)pLeaf;
            }
          }
          v30 = *(unsigned __int16 *)(v24 + 10);
          m_pMemory = pVisitedBrushes;
          v25 = iBrushCounter + 1;
          iBrushCounter = v25;
        }
        while ( v25 != v30 );
        v23 = iLeaf;
      }
      iLeaf = ++v23;
    }
    while ( v23 != iNumLeafs );
  }
  v31 = pKeepBrushes;
  BrushQuery->m_iCount = iKeepBrushCount;
  BrushQuery->m_pBrushes = v31;
  BrushQuery->m_iMaxBrushSides = iMaxBrushSides;
  BrushQuery->m_pData = v7;
  BrushQuery->m_pReleaseFunc = CSetupBrushQuery::BrushQueryReleaseFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10176700
// Name: public: virtual void CEngineTrace::GetBrushesInCollideable(class ICollideable __near *,class CBrushQuery __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetBrushesInCollideable(
        CEngineTrace *this,
        ICollideable *pCollideable,
        CBrushQuery *BrushQuery)
{
  CBrushQuery *v3; // ebx
  void (__cdecl *m_pReleaseFunc)(CBrushQuery *); // eax
  int v5; // eax
  cmodel_t *v6; // eax
  TraceInfo_t *v7; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_BrushCounters; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  CBrushQuery *v13; // edx
  int nHeadNode; // [esp+8h] [ebp-4h]
  int nHeadNodea; // [esp+8h] [ebp-4h]
  int iMaxBrushSides; // [esp+14h] [ebp+8h]
  int iMaxBrushSidesa; // [esp+14h] [ebp+8h]

  v3 = BrushQuery;
  m_pReleaseFunc = BrushQuery->m_pReleaseFunc;
  if ( m_pReleaseFunc != nullptr )
    m_pReleaseFunc(a1: BrushQuery);
  v3->m_iCount = 0;
  v3->m_pBrushes = nullptr;
  v3->m_iMaxBrushSides = 0;
  v3->m_pReleaseFunc = nullptr;
  v3->m_pData = nullptr;
  v5 = pCollideable->GetCollisionModelIndex(this: pCollideable);
  v6 = CM_InlineModelNumber(index: v5 - 1);
  if ( v6 != nullptr )
  {
    nHeadNode = v6->headnode;
    v7 = BeginTrace();
    CM_ClearTrace(trace: &v7->m_trace);
    v7->m_bDispHit = 0;
    v7->m_DispStabDir.x = 0.0;
    v7->m_DispStabDir.y = 0.0;
    v7->m_DispStabDir.z = 0.0;
    v7->m_contents = 0;
    v7->m_start = vec3_origin;
    v7->m_end = vec3_origin;
    v7->m_mins = vec3_origin;
    v7->m_maxs = vec3_origin;
    v7->m_extents = vec3_origin;
    v7->m_delta = vec3_origin;
    v7->m_invDelta = vec3_origin;
    *(_WORD *)&v7->m_ispoint = 0;
    m_BrushCounters = v7->m_BrushCounters;
    for ( iMaxBrushSides = 2; iMaxBrushSides != 0; --iMaxBrushSides )
    {
      memset(dst: (unsigned __int8 *)m_BrushCounters->m_Memory.m_pMemory, value: 0, count: 4 * m_BrushCounters->m_Size);
      ++m_BrushCounters;
    }
    BrushQuery = (CBrushQuery *)v7->m_BrushCounters[1].m_Memory.m_pMemory;
    GetBrushesInCollideable_r(
      pBSPData: v7->m_pBSPData,
      pVisitedBrushes: v7->m_BrushCounters[0].m_Memory.m_pMemory,
      pKeepBrushes: (unsigned int **)&BrushQuery,
      node: nHeadNode);
    v9 = ((char *)BrushQuery - (char *)v7->m_BrushCounters[1].m_Memory.m_pMemory) >> 2;
    BrushQuery = (CBrushQuery *)v7->m_BrushCounters[1].m_Memory.m_pMemory;
    v10 = 0;
    v11 = 0;
    iMaxBrushSidesa = 0;
    if ( v9 != 0 )
    {
      nHeadNodea = (int)v7->m_pBSPData->map_brushes.m_pArray;
      do
      {
        v12 = 6;
        if ( *(_WORD *)(nHeadNodea + 8 * *(&BrushQuery->m_iCount + v11) + 4) != 0xFFFF )
          v12 = *(unsigned __int16 *)(nHeadNodea + 8 * *(&BrushQuery->m_iCount + v11) + 4);
        v10 = iMaxBrushSidesa;
        if ( v12 > iMaxBrushSidesa )
        {
          v10 = v12;
          iMaxBrushSidesa = v12;
        }
        ++v11;
      }
      while ( v11 != v9 );
    }
    v13 = BrushQuery;
    v3->m_pData = v7;
    v3->m_iCount = v9;
    v3->m_pBrushes = (unsigned int *)v13;
    v3->m_iMaxBrushSides = v10;
    v3->m_pReleaseFunc = CSetupBrushQuery::BrushQueryReleaseFunc;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176970
// Name: public: virtual class CPhysCollide __near * CEngineTrace::GetCollidableFromDisplacementsInAABB(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__thiscall CEngineTrace::GetCollidableFromDisplacementsInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs)
{
  void *v3; // esp
  int *v4; // edi
  int v5; // ebx
  struct CPhysPolysoup *(__thiscall *PolysoupCreate)(IPhysicsCollision *); // eax
  int m_nCheckDepth; // ecx
  unsigned int v8; // esi
  int v9; // eax
  cleaf_t *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ebx
  CDispCollTree *v15; // edi
  int m_iCounter; // eax
  bool v17; // zf
  unsigned int *v18; // eax
  int indexCount; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ebx
  int v23; // eax
  int v24; // ecx
  const Vector *v25; // ebx
  const Vector *v26; // esi
  struct CPhysPolysoup *v27; // edi
  struct CPhysCollide *v28; // esi
  int v30[3]; // [esp+0h] [ebp-1864h] BYREF
  virtualmeshlist_t pList; // [esp+Ch] [ebp-1858h] BYREF
  int contents; // [esp+1824h] [ebp-40h]
  int v33; // [esp+1828h] [ebp-3Ch]
  int v34; // [esp+182Ch] [ebp-38h]
  int v35; // [esp+1830h] [ebp-34h]
  int v36; // [esp+1834h] [ebp-30h]
  unsigned int v37; // [esp+1838h] [ebp-2Ch]
  int *v38; // [esp+183Ch] [ebp-28h]
  unsigned int *m_pMemory; // [esp+1840h] [ebp-24h]
  int v40; // [esp+1844h] [ebp-20h]
  Vector *pt; // [esp+1848h] [ebp-1Ch]
  int v42; // [esp+184Ch] [ebp-18h]
  int v43; // [esp+1850h] [ebp-14h]
  int v44; // [esp+1854h] [ebp-10h]
  int v45; // [esp+1858h] [ebp-Ch]
  TraceInfo_t *pTraceInfo; // [esp+185Ch] [ebp-8h] BYREF
  struct CPhysPolysoup *v47; // [esp+1860h] [ebp-4h]

  v3 = alloca(4 * g_BSPData.numleafs);
  v4 = v30;
  v38 = v30;
  v5 = CM_BoxLeafnums(
         mins: vMins,
         maxs: vMaxs,
         list: v30,
         listsize: g_BSPData.numleafs,
         topnode: nullptr,
         cmodelIndex: 0);
  PolysoupCreate = physcollision->PolysoupCreate;
  v36 = v5;
  v47 = PolysoupCreate(this: physcollision);
  v42 = 0;
  pTraceInfo = BeginTrace();
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v8 = pTraceInfo->m_Count[m_nCheckDepth];
  v9 = 0;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v37 = v8;
  v40 = 0;
  if ( v5 <= 0 )
  {
LABEL_23:
    EndTrace(&pTraceInfo);
    v27 = v47;
    v28 = physcollision->ConvertPolysoupToCollide(this: physcollision, a2: v47, a3: 0);
    physcollision->PolysoupDestroy(this: physcollision, a2: v27);
    return v28;
  }
  else
  {
    while ( 1 )
    {
      v10 = &g_BSPData.map_leafs.m_pArray[v4[v9]];
      v43 = 0;
      v11 = *(_DWORD *)&v10->cluster;
      contents = v10->contents;
      v12 = *(_DWORD *)&v10->firstleafbrush;
      v13 = *(_DWORD *)&v10->dispListStart;
      v33 = v11;
      v34 = v12;
      v35 = v13;
      if ( HIWORD(v13) != 0 )
        break;
LABEL_22:
      v9 = v40 + 1;
      v40 = v9;
      if ( v9 >= v5 )
        goto LABEL_23;
    }
    v14 = 2 * (unsigned __int16)v13;
    v44 = v14;
    while ( 1 )
    {
      v15 = &g_pDispCollTrees[*(unsigned __int16 *)((char *)g_BSPData.map_dispList.m_pArray + v14)];
      m_iCounter = v15->m_iCounter;
      v17 = m_pMemory[m_iCounter] == v8;
      v18 = &m_pMemory[m_iCounter];
      if ( !v17 )
      {
        *v18 = v8;
        if ( IsBoxIntersectingBox(boxMin1: vMins, boxMax1: vMaxs, boxMin2: &v15->m_mins, boxMax2: &v15->m_maxs) )
        {
          CDispCollTree::GetVirtualMeshList(this: v15, &pList);
          v42 += pList.triangleCount;
          if ( v42 > 0xFFFF )
          {
            EndTrace(&pTraceInfo);
            return nullptr;
          }
          indexCount = pList.indexCount;
          v20 = 0;
          v45 = 0;
          if ( pList.indexCount > 0 )
            break;
        }
      }
LABEL_20:
      v14 += 2;
      ++v43;
      v44 = v14;
      if ( v43 >= HIWORD(v35) )
      {
        v5 = v36;
        v4 = v38;
        goto LABEL_22;
      }
    }
    while ( v20 + 2 < indexCount )
    {
      v21 = pList.indices[v20 + 1];
      v22 = pList.indices[v20 + 2];
      v23 = pList.indices[v20];
      if ( v23 >= pList.vertexCount )
        break;
      if ( v21 >= pList.vertexCount )
        break;
      v24 = v22;
      if ( v22 >= pList.vertexCount )
        break;
      v25 = &pList.pVerts[v21];
      v26 = &pList.pVerts[v23];
      pt = &pList.pVerts[v24];
      if ( IsPointInBox(pt: v26, boxMin: vMins, boxMax: vMaxs)
        || IsPointInBox(pt: v25, boxMin: vMins, boxMax: vMaxs)
        || IsPointInBox(pt, boxMin: vMins, boxMax: vMaxs) )
      {
        ((void (__stdcall *)(struct CPhysPolysoup *, const Vector *, const Vector *, Vector *, _DWORD))physcollision->PolysoupAddTriangle)(
          a1: v47,
          a2: v26,
          a3: v25,
          a4: pt,
          a5: v15->m_nSurfaceProps[0]);
      }
      indexCount = pList.indexCount;
      v45 += 3;
      if ( v45 >= pList.indexCount )
      {
        v8 = v37;
        v14 = v44;
        goto LABEL_20;
      }
      v20 = v45;
    }
    EndTrace(&pTraceInfo);
    physcollision->PolysoupDestroy(this: physcollision, a2: v47);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176C60
// Name: public: virtual int CEngineTrace::GetMeshesFromDisplacementsInAABB(class Vector const __near &,class Vector const __near &,struct virtualmeshlist_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetMeshesFromDisplacementsInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs,
        virtualmeshlist_t *pOutputMeshes,
        int iMaxOutputMeshes)
{
  void *v5; // esp
  int *v6; // esi
  int v7; // ebx
  int m_nCheckDepth; // ecx
  unsigned int *m_pMemory; // edx
  unsigned int v10; // ecx
  int v11; // eax
  int *p_contents; // eax
  int v13; // edx
  int v14; // eax
  virtualmeshlist_t *v15; // edi
  int v16; // ebx
  CDispCollTree *v17; // esi
  int m_iCounter; // edx
  int v19; // esi
  int v21[3]; // [esp+0h] [ebp-3Ch] BYREF
  cleaf_t curLeaf; // [esp+Ch] [ebp-30h]
  int iLeafCount; // [esp+1Ch] [ebp-20h]
  int *pLeafList; // [esp+20h] [ebp-1Ch]
  int count; // [esp+24h] [ebp-18h]
  unsigned int *pCounters; // [esp+28h] [ebp-14h]
  TraceInfo_t *pTraceInfo; // [esp+2Ch] [ebp-10h] BYREF
  int i; // [esp+30h] [ebp-Ch]
  int v29; // [esp+34h] [ebp-8h]
  int iMeshesWritten; // [esp+38h] [ebp-4h]

  iMeshesWritten = 0;
  v5 = alloca(4 * g_BSPData.numleafs);
  v6 = v21;
  pLeafList = v21;
  v7 = CM_BoxLeafnums(
         mins: vMins,
         maxs: vMaxs,
         list: v21,
         listsize: g_BSPData.numleafs,
         topnode: nullptr,
         cmodelIndex: 0);
  iLeafCount = v7;
  pTraceInfo = BeginTrace();
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v10 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = 0;
  pCounters = m_pMemory;
  count = v10;
  i = 0;
  if ( v7 <= 0 )
  {
LABEL_11:
    EndTrace(&pTraceInfo);
    return iMeshesWritten;
  }
  while ( 1 )
  {
    p_contents = &g_BSPData.map_leafs.m_pArray[v6[v11]].contents;
    curLeaf.contents = *p_contents;
    *(_DWORD *)&curLeaf.cluster = p_contents[1];
    v13 = p_contents[2];
    v14 = p_contents[3];
    *(_DWORD *)&curLeaf.firstleafbrush = v13;
    *(_DWORD *)&curLeaf.dispListStart = v14;
    v29 = 0;
    if ( HIWORD(v14) != 0 )
      break;
LABEL_10:
    v11 = i + 1;
    i = v11;
    if ( v11 >= v7 )
      goto LABEL_11;
  }
  v15 = &pOutputMeshes[iMeshesWritten];
  v16 = (unsigned __int16)v14;
  while ( 1 )
  {
    v17 = &g_pDispCollTrees[g_BSPData.map_dispList.m_pArray[v16]];
    m_iCounter = v17->m_iCounter;
    if ( pCounters[m_iCounter] != v10 )
      break;
LABEL_8:
    ++v16;
    if ( ++v29 >= curLeaf.dispCount )
    {
      v6 = pLeafList;
      v7 = iLeafCount;
      goto LABEL_10;
    }
  }
  pCounters[m_iCounter] = v10;
  if ( !IsBoxIntersectingBox(boxMin1: vMins, boxMax1: vMaxs, boxMin2: &v17->m_mins, boxMax2: &v17->m_maxs)
    || (CDispCollTree::GetVirtualMeshList(this: v17, pList: v15),
        v19 = iMeshesWritten + 1,
        ++v15,
        iMeshesWritten = v19,
        v19 != iMaxOutputMeshes) )
  {
    v10 = count;
    goto LABEL_8;
  }
  EndTrace(&pTraceInfo);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x10176DE0
// Name: private: bool CEngineTrace::ClipTraceToTrace(class CGameTrace __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipTraceToTrace(CEngineTrace *this, CGameTrace *clipTrace, CGameTrace *pFinalTrace)
{
  float flFractionLeftSolid; // [esp+1Ch] [ebp+8h]
  Vector vecStartPos; // 0:^C.12

  if ( !clipTrace->allsolid && !clipTrace->startsolid && pFinalTrace->fraction <= clipTrace->fraction )
    return 0;
  if ( pFinalTrace->startsolid )
  {
    vecStartPos = pFinalTrace->startpos;
    flFractionLeftSolid = pFinalTrace->fractionleftsolid;
    CBaseTrace::operator=(this: pFinalTrace, __that: clipTrace);
    pFinalTrace->fractionleftsolid = clipTrace->fractionleftsolid;
    pFinalTrace->surface = clipTrace->surface;
    pFinalTrace->hitgroup = clipTrace->hitgroup;
    pFinalTrace->physicsbone = clipTrace->physicsbone;
    pFinalTrace->worldSurfaceIndex = clipTrace->worldSurfaceIndex;
    pFinalTrace->m_pEnt = clipTrace->m_pEnt;
    pFinalTrace->hitbox = clipTrace->hitbox;
    pFinalTrace->startsolid = true;
    if ( flFractionLeftSolid > clipTrace->fractionleftsolid )
    {
      pFinalTrace->fractionleftsolid = flFractionLeftSolid;
      pFinalTrace->startpos = vecStartPos;
      return 1;
    }
  }
  else
  {
    CBaseTrace::operator=(this: pFinalTrace, __that: clipTrace);
    pFinalTrace->fractionleftsolid = clipTrace->fractionleftsolid;
    pFinalTrace->surface = clipTrace->surface;
    pFinalTrace->hitgroup = clipTrace->hitgroup;
    pFinalTrace->physicsbone = clipTrace->physicsbone;
    pFinalTrace->worldSurfaceIndex = clipTrace->worldSurfaceIndex;
    pFinalTrace->m_pEnt = clipTrace->m_pEnt;
    pFinalTrace->hitbox = clipTrace->hitbox;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10176EF0
// Name: public: virtual void CEngineTrace::TraceRay(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::TraceRay(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        int fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  void *v8; // esp
  char v10; // al
  float fraction; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  ISpatialPartitionInternal *v14; // eax
  ISpatialPartitionInternal_vtbl *v15; // edi
  CEngineTrace *v16; // esi
  CEngineTrace_vtbl *v17; // edx
  int v18; // eax
  TraceType_t v19; // eax
  TraceType_t (__thiscall *GetTraceType)(ITraceFilter *); // edx
  IHandleEntity *v21; // edi
  IStaticPropMgrEngine *v22; // eax
  CGameTrace *v23; // edi
  void **v25; // [esp-10D0h] [ebp-10DCh] BYREF
  int v26; // [esp-10CCh] [ebp-10D8h]
  _DWORD v27[1024]; // [esp-10C8h] [ebp-10D4h]
  CGameTrace v28; // [esp-C8h] [ebp-D4h] BYREF
  Ray_t v29; // [esp-70h] [ebp-7Ch] BYREF
  void **v30; // [esp-1Ch] [ebp-28h] BYREF
  int v31; // [esp-18h] [ebp-24h]
  float v32; // [esp-14h] [ebp-20h]
  int v33; // [esp-10h] [ebp-1Ch]
  float fractionleftsolid; // [esp-Ch] [ebp-18h]
  CEngineTrace *i; // [esp-8h] [ebp-14h]
  bool v36; // [esp-2h] [ebp-Eh]
  bool v37; // [esp-1h] [ebp-Dh]
  int v38; // [esp+0h] [ebp-Ch]
  void *v39; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v38 = a2;
  v39 = retaddr;
  v8 = alloca(4312);
  i = this;
  if ( (_S2_11 & 1) == 0 )
  {
    _S2_11 |= 1u;
    counter_2.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "TraceRay",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_2.m_pCounter;
  ++this->m_traceStatCounters[0];
  v30 = &CTraceFilterHitAll::`vftable';
  if ( pTraceFilter == nullptr )
    pTraceFilter = (ITraceFilter *)&v30;
  CM_ClearTrace(trace: pTrace);
  if ( ((int (__thiscall *)(ITraceFilter *, int, int))pTraceFilter->GetTraceType)(a1: pTraceFilter, a2: a3, a3: a4) == 2 )
  {
    pTrace->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
    pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
    pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  }
  else
  {
    v10 = (char)this->GetWorldCollideable(this);
    CM_BoxTrace(ray, headnode: 0, brushmask: fMask, computeEndpt: v10, tr: pTrace);
    this->SetTraceEntity(this, a2: (ICollideable *)LODWORD(fractionleftsolid), a3: pTrace);
    if ( pTrace->startsolid || pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_WORLD_ONLY )
      return;
  }
  fraction = pTrace->fraction;
  v32 = fraction;
  fractionleftsolid = fraction;
  v29 = *ray;
  if ( fraction == 0.0 )
  {
    memset(&v29.m_Delta, 0, 12);
    fractionleftsolid = pTrace->fractionleftsolid;
    pTrace->fractionleftsolid = 1.0;
  }
  else
  {
    v29.m_Delta.y = (float)((float)(fraction * v29.m_Delta.y) + v29.m_Start.y) - v29.m_Start.y;
    v12 = (float)((float)(v29.m_Delta.x * fraction) + v29.m_Start.x) - v29.m_Start.x;
    v13 = (float)((float)(v29.m_Delta.z * fraction) + v29.m_Start.z) - v29.m_Start.z;
    pTrace->fractionleftsolid = pTrace->fractionleftsolid / fraction;
    v29.m_Delta.x = v12;
    v29.m_Delta.z = v13;
  }
  pTrace->fraction = 1.0;
  v25 = &CEntityListAlongRay::`vftable';
  v26 = 0;
  v14 = SpatialPartition();
  v15 = v14->__vftable;
  v16 = i;
  v17 = i->__vftable;
  v33 = (int)v14;
  v18 = ((int (__thiscall *)(CEngineTrace *, Ray_t *, _DWORD, void ***))v17->SpatialPartitionMask)(
          a1: i,
          a2: &v29,
          a3: 0,
          a4: &v25);
  ((void (__thiscall *)(int, int))v15->EnumerateElementsAlongRay)(a1: v33, a2: v18);
  v19 = pTraceFilter->GetTraceType(this: pTraceFilter);
  GetTraceType = pTraceFilter->GetTraceType;
  v36 = v19 == TRACE_ENTITIES_ONLY;
  v37 = GetTraceType(this: pTraceFilter) == TRACE_EVERYTHING_FILTER_PROPS;
  v31 = v26;
  for ( i = nullptr; (int)i < v31; i = (CEngineTrace *)((char *)i + 1) )
  {
    v21 = (IHandleEntity *)v27[(_DWORD)i];
    v33 = (int)v16->HandleEntityToCollideable(this: v16, a2: v21);
    v22 = StaticPropMgr();
    if ( v22->IsStaticProp_2(this: v22, a2: v21) )
    {
      if ( v36 )
        continue;
      if ( !v37 )
        goto LABEL_18;
    }
    if ( pTraceFilter->ShouldHitEntity(this: pTraceFilter, a2: v21, a3: fMask) != 0 )
    {
LABEL_18:
      v16->ClipRayToCollideable(this: v16, a2: &v29, a3: fMask, a4: (ICollideable *)v33, a5: &v28);
      v23 = pTrace;
      CEngineTrace::ClipTraceToTrace(this: v16, clipTrace: &v28, pFinalTrace: pTrace);
      if ( pTrace->allsolid )
        goto LABEL_21;
    }
  }
  v23 = pTrace;
LABEL_21:
  v23->fraction = v32 * v23->fraction;
  v23->fractionleftsolid = v23->fractionleftsolid * fractionleftsolid;
  if ( !ray->m_IsRay )
  {
    v23->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    v23->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    v23->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    v23->fractionleftsolid = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10177270
// Name: public: virtual int CEngineTrace::GetSetDebugTraceCounter(int,enum DebugTraceCounterBehavior_t)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEngineTrace::GetSetDebugTraceCounter(
        CEngineTrace *this,
        char *value,
        DebugTraceCounterBehavior_t behavior)
{
  void *v3; // edi
  char *v4; // eax

  if ( DEBUG_THINK_TRACE_COUNTER_ALLOWED() )
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap);
    if ( behavior != kTRACE_COUNTER_SET )
    {
      if ( behavior != kTRACE_COUNTER_INC )
        return v3;
      v4 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) + (_DWORD)value;
    }
    else
    {
      v4 = value;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: v4);
    return v3;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101772D0
// Name: private: bool CEngineTrace::ClipRayToHitboxes(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTrace::ClipRayToHitboxes(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  int contents; // ecx
  float v8; // xmm3_4
  bool v9; // zf
  float v10; // xmm0_4
  bool result; // al
  float y; // ecx
  float z; // edx
  float fractionleftsolid; // xmm0_4
  int hitgroup; // edx
  int hitbox; // eax
  __int16 physicsbone; // cx
  const char *name; // edx
  int v19; // eax
  CGameTrace hitboxTrace; // [esp+4h] [ebp-60h] BYREF
  Vector vecStartPos; // [esp+58h] [ebp-Ch]

  CM_ClearTrace(trace: &hitboxTrace);
  v5 = ray->m_StartOffset.y + ray->m_Start.y;
  v6 = ray->m_StartOffset.z + ray->m_Start.z;
  contents = pTrace->contents;
  v8 = ray->m_Delta.x + (float)(ray->m_Start.x + ray->m_StartOffset.x);
  hitboxTrace.startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
  hitboxTrace.endpos.y = ray->m_Delta.y + v5;
  v9 = !ray->m_IsRay;
  v10 = ray->m_Delta.z + v6;
  hitboxTrace.contents = contents;
  hitboxTrace.startpos.y = v5;
  hitboxTrace.startpos.z = v6;
  hitboxTrace.endpos.x = v8;
  hitboxTrace.endpos.z = v10;
  if ( v9 )
    return false;
  result = pCollideable->TestHitboxes(this: pCollideable, a2: ray, a3: fMask, a4: &hitboxTrace);
  if ( result )
  {
    if ( hitboxTrace.fraction >= 1.0 && !hitboxTrace.allsolid && !hitboxTrace.startsolid )
    {
      CM_ClearTrace(trace: pTrace);
      pTrace->startpos = hitboxTrace.startpos;
      pTrace->endpos = hitboxTrace.endpos;
      return true;
    }
    if ( pCollideable->GetSolid(this: pCollideable) == SOLID_VPHYSICS )
    {
      hitgroup = hitboxTrace.hitgroup;
      hitbox = hitboxTrace.hitbox;
      pTrace->contents = hitboxTrace.contents;
      physicsbone = hitboxTrace.physicsbone;
      pTrace->hitgroup = hitgroup;
      name = hitboxTrace.surface.name;
      pTrace->hitbox = hitbox;
      v19 = *(_DWORD *)&hitboxTrace.surface.surfaceProps;
      pTrace->physicsbone = physicsbone;
      pTrace->surface.name = name;
      *(_DWORD *)&pTrace->surface.surfaceProps = v19;
    }
    else
    {
      y = pTrace->startpos.y;
      z = pTrace->startpos.z;
      fractionleftsolid = pTrace->fractionleftsolid;
      vecStartPos.x = pTrace->startpos.x;
      vecStartPos.y = y;
      vecStartPos.z = z;
      CGameTrace::operator=(this: pTrace, __that: &hitboxTrace);
      if ( hitboxTrace.startsolid )
      {
        pTrace->startpos = vecStartPos;
        pTrace->fractionleftsolid = fractionleftsolid;
        return true;
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10177480
// Name: public: virtual void CEngineTrace::ClipRayToCollideable(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::ClipRayToCollideable(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const model_t *(__thiscall *GetCollisionModel)(ICollideable *); // edx
  int v9; // eax
  char v10; // al
  const matrix3x4_t *pOldTransform; // [esp+Ch] [ebp-Ch]
  studiohdr_t *pStudioHdr; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  char bCustomPerformed_3; // [esp+23h] [ebp+Bh]
  const model_t *pModel; // [esp+28h] [ebp+10h]
  char pModel_3; // [esp+2Bh] [ebp+13h]
  char bIsStudioModel_3; // [esp+2Fh] [ebp+17h]

  CM_ClearTrace(trace: pTrace);
  pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
  pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
  pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
  GetCollisionModel = pEntity->GetCollisionModel;
  pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  v9 = (int)GetCollisionModel(this: pEntity);
  pModel = (const model_t *)v9;
  bIsStudioModel_3 = 0;
  pStudioHdr = nullptr;
  if ( v9 != 0 && *(_DWORD *)(v9 + 272) == 3 )
  {
    bIsStudioModel_3 = 1;
    pStudioHdr = (studiohdr_t *)modelloader->GetExtraData(this: modelloader, a2: v9);
    if ( (fMask & 0x40000000) == 0 && (fMask & pStudioHdr->contents) == 0 )
      return;
  }
  pOldTransform = ray->m_pWorldAxisTransform;
  if ( (pEntity->GetSolidFlags(this: pEntity) & 0x100) != 0 )
    ray->m_pWorldAxisTransform = pEntity->GetRootParentToWorldTransform(this: pEntity);
  bCustomPerformed_3 = 0;
  if ( pEntity->GetSolid(this: pEntity) == SOLID_CUSTOM )
    goto LABEL_12;
  if ( !ray->m_IsRay )
    goto LABEL_11;
  if ( (pEntity->GetSolidFlags(this: pEntity) & 1) != 0 )
  {
LABEL_12:
    pEntity->TestCollision(this: pEntity, a2: ray, a3: fMask, a4: pTrace);
    v10 = 1;
    bCustomPerformed_3 = 1;
    goto LABEL_18;
  }
  if ( !ray->m_IsRay )
  {
LABEL_11:
    if ( (pEntity->GetSolidFlags(this: pEntity) & 2) != 0 )
      goto LABEL_12;
  }
  v10 = CEngineTrace::ClipRayToVPhysics(this, ray, fMask: __SPAIR64__((unsigned int)pEntity, fMask), pStudioHdr, pTrace);
  if ( v10 == 0
    && (pModel == nullptr
     || pModel->type != mod_brush
     || (v10 = CEngineTrace::ClipRayToBSP(this, ray, fMask, pEntity, pTrace)) == 0) )
  {
    v10 = CEngineTrace::ClipRayToOBB(this, ray, fMask, pEntity, pTrace);
  }
LABEL_18:
  pModel_3 = 0;
  if ( bIsStudioModel_3 != 0 && (fMask & 0x40000000) != 0 && bCustomPerformed_3 == 0 )
  {
    v10 = CEngineTrace::ClipRayToHitboxes(this, ray, fMask, pCollideable: pEntity, pTrace);
    if ( v10 == 0 )
    {
LABEL_24:
      CEngineTrace::ClipRayToBBox(
        this,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)ray,
        a4: (int)pTrace,
        ray,
        fMask,
        pEntity,
        pTrace);
      goto LABEL_25;
    }
    pModel_3 = 1;
  }
  if ( v10 == 0 )
    goto LABEL_24;
LABEL_25:
  if ( bIsStudioModel_3 != 0
    && pModel_3 == 0
    && (pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid)
    && (bCustomPerformed_3 == 0 || pTrace->surface.surfaceProps == 0) )
  {
    pTrace->contents = pStudioHdr->contents;
    pTrace->surface.name = "**studio**";
    pTrace->surface.flags = 0;
    pTrace->surface.surfaceProps = pStudioHdr->surfacepropLookup;
  }
  if ( pTrace->m_pEnt == nullptr && (pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid) )
    this->SetTraceEntity(this, a2: pEntity, a3: pTrace);
  ray->m_pWorldAxisTransform = pOldTransform;
}

//------------------------------------------------------------------------------
// Address: 0x101776D0
// Name: public: virtual void CEngineTrace::TraceRayAgainstLeafAndEntityList(struct Ray_t const __near &,class ITraceListData __near *,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::TraceRayAgainstLeafAndEntityList(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        ITraceListData *pTraceData,
        int fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  ITraceFilter *v10; // ecx
  CGameTrace *v11; // edi
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool v14; // zf
  TraceType_t (__thiscall *GetTraceType)(ITraceFilter *); // eax
  int v16; // esi
  int v17; // eax
  int v18; // edi
  CEngineTrace *v19; // esi
  int v20; // ecx
  int v21; // edx
  int v22; // esi
  CEngineTrace *v23; // edi
  CGameTrace v25; // [esp-Ch] [ebp-F4h] BYREF
  CGameTrace trace; // [esp+48h] [ebp-A0h] BYREF
  int v27; // [esp+9Ch] [ebp-4Ch]
  _BYTE entityRay[68]; // [esp+A0h] [ebp-48h] OVERLAPPED BYREF
  int entityRay_72; // [esp+E8h] [ebp+0h]

  *(_DWORD *)&entityRay[60] = a2;
  *(_DWORD *)&entityRay[64] = entityRay_72;
  *(_DWORD *)&entityRay[40] = this;
  if ( pTraceData != nullptr )
    *(_DWORD *)&entityRay[52] = pTraceData - 1;
  else
    *(_DWORD *)&entityRay[52] = 0;
  ComputeRayBounds(ray, mins: (Vector *)&entityRay[28], maxs: (Vector *)&entityRay[16]);
  if ( *(float *)(*(_DWORD *)&entityRay[52] + 1332) < *(float *)&entityRay[16]
    || *(float *)&entityRay[28] < *(float *)(*(_DWORD *)&entityRay[52] + 1320)
    || *(float *)(*(_DWORD *)&entityRay[52] + 1336) < *(float *)&entityRay[20]
    || *(float *)&entityRay[32] < *(float *)(*(_DWORD *)&entityRay[52] + 1324)
    || *(float *)(*(_DWORD *)&entityRay[52] + 1340) < *(float *)&entityRay[24]
    || *(float *)&entityRay[36] < *(float *)(*(_DWORD *)&entityRay[52] + 1328) )
  {
    ((void (__thiscall *)(CEngineTrace *, const Ray_t *, int, ITraceFilter *, CGameTrace *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->TraceRay)(
      a1: this,
      a2: ray,
      a3: fMask,
      a4: pTraceFilter,
      a5: pTrace,
      a6: a3,
      a7: a4,
      a8: LODWORD(v25.startpos.x),
      a9: LODWORD(v25.startpos.y),
      a10: LODWORD(v25.startpos.z),
      a11: LODWORD(v25.endpos.x),
      a12: LODWORD(v25.endpos.y),
      a13: LODWORD(v25.endpos.z),
      a14: LODWORD(v25.plane.normal.x),
      a15: LODWORD(v25.plane.normal.y),
      a16: LODWORD(v25.plane.normal.z),
      a17: LODWORD(v25.plane.dist),
      a18: *(_DWORD *)&v25.plane.type,
      a19: LODWORD(v25.fraction),
      a20: v25.contents,
      a21: *(_DWORD *)&v25.dispFlags,
      a22: LODWORD(v25.fractionleftsolid),
      a23: v25.surface.name,
      a24: *(_DWORD *)&v25.surface.surfaceProps,
      a25: v25.hitgroup,
      a26: *(_DWORD *)&v25.physicsbone,
      a27: v25.m_pEnt,
      a28: v25.hitbox,
      a29: LODWORD(trace.startpos.x),
      a30: LODWORD(trace.startpos.y),
      a31: LODWORD(trace.startpos.z),
      a32: LODWORD(trace.endpos.x),
      a33: LODWORD(trace.endpos.y),
      a34: LODWORD(trace.endpos.z),
      a35: LODWORD(trace.plane.normal.x),
      a36: LODWORD(trace.plane.normal.y),
      a37: LODWORD(trace.plane.normal.z),
      a38: LODWORD(trace.plane.dist),
      a39: *(_DWORD *)&trace.plane.type,
      a40: LODWORD(trace.fraction),
      a41: trace.contents,
      a42: *(_DWORD *)&trace.dispFlags,
      a43: LODWORD(trace.fractionleftsolid),
      a44: trace.surface.name,
      a45: *(_DWORD *)&trace.surface.surfaceProps,
      a46: trace.hitgroup,
      a47: *(_DWORD *)&trace.physicsbone,
      a48: trace.m_pEnt,
      a49: trace.hitbox,
      a50: v27,
      a51: *(_DWORD *)entityRay,
      a52: *(_DWORD *)&entityRay[4],
      a53: *(_DWORD *)&entityRay[8],
      a54: *(_DWORD *)&entityRay[12],
      a55: *(_DWORD *)&entityRay[16],
      a56: *(_DWORD *)&entityRay[20],
      a57: *(_DWORD *)&entityRay[24],
      a58: *(_DWORD *)&entityRay[28],
      a59: *(_DWORD *)&entityRay[32],
      a60: *(_DWORD *)&entityRay[36],
      a61: *(_DWORD *)&entityRay[40],
      a62: *(_DWORD *)&entityRay[44]);
    return;
  }
  v10 = pTraceFilter;
  *(_DWORD *)&entityRay[12] = &CTraceFilterHitAll::`vftable';
  if ( pTraceFilter == nullptr )
  {
    pTraceFilter = (ITraceFilter *)&entityRay[12];
    v10 = (ITraceFilter *)&entityRay[12];
  }
  if ( ((int (__thiscall *)(ITraceFilter *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v10->GetTraceType)(
         a1: v10,
         a2: a3,
         a3: a4,
         a4: LODWORD(v25.startpos.x),
         a5: LODWORD(v25.startpos.y),
         a6: LODWORD(v25.startpos.z),
         a7: LODWORD(v25.endpos.x),
         a8: LODWORD(v25.endpos.y),
         a9: LODWORD(v25.endpos.z),
         a10: LODWORD(v25.plane.normal.x),
         a11: LODWORD(v25.plane.normal.y),
         a12: LODWORD(v25.plane.normal.z),
         a13: LODWORD(v25.plane.dist),
         a14: *(_DWORD *)&v25.plane.type,
         a15: LODWORD(v25.fraction),
         a16: v25.contents,
         a17: *(_DWORD *)&v25.dispFlags,
         a18: LODWORD(v25.fractionleftsolid),
         a19: v25.surface.name,
         a20: *(_DWORD *)&v25.surface.surfaceProps,
         a21: v25.hitgroup,
         a22: *(_DWORD *)&v25.physicsbone,
         a23: v25.m_pEnt,
         a24: v25.hitbox,
         a25: LODWORD(trace.startpos.x),
         a26: LODWORD(trace.startpos.y),
         a27: LODWORD(trace.startpos.z),
         a28: LODWORD(trace.endpos.x),
         a29: LODWORD(trace.endpos.y),
         a30: LODWORD(trace.endpos.z),
         a31: LODWORD(trace.plane.normal.x),
         a32: LODWORD(trace.plane.normal.y),
         a33: LODWORD(trace.plane.normal.z),
         a34: LODWORD(trace.plane.dist),
         a35: *(_DWORD *)&trace.plane.type,
         a36: LODWORD(trace.fraction),
         a37: trace.contents,
         a38: *(_DWORD *)&trace.dispFlags,
         a39: LODWORD(trace.fractionleftsolid),
         a40: trace.surface.name,
         a41: *(_DWORD *)&trace.surface.surfaceProps,
         a42: trace.hitgroup,
         a43: *(_DWORD *)&trace.physicsbone,
         a44: trace.m_pEnt,
         a45: trace.hitbox,
         a46: v27,
         a47: *(_DWORD *)entityRay,
         a48: *(_DWORD *)&entityRay[4],
         a49: *(_DWORD *)&entityRay[8],
         a50: *(_DWORD *)&entityRay[12],
         a51: *(_DWORD *)&entityRay[16],
         a52: *(_DWORD *)&entityRay[20],
         a53: *(_DWORD *)&entityRay[24],
         a54: *(_DWORD *)&entityRay[28],
         a55: *(_DWORD *)&entityRay[32],
         a56: *(_DWORD *)&entityRay[36],
         a57: *(_DWORD *)&entityRay[40],
         a58: *(_DWORD *)&entityRay[44],
         a59: *(_DWORD *)&entityRay[48],
         a60: *(_DWORD *)&entityRay[52]) == 2 )
  {
    CM_ClearTrace(trace: pTrace);
    pTrace->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
    pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
    pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  }
  else
  {
    *(_DWORD *)&entityRay[56] = this->GetWorldCollideable(this);
    CM_BoxTraceAgainstLeafList(ray, traceData: (const CTraceListData *)pTrace, nBrushMask: fMask, trace: pTrace);
    this->SetTraceEntity(this, a2: *(ICollideable **)&entityRay[56], a3: pTrace);
    if ( pTrace->fraction == 0.0 || pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_WORLD_ONLY )
      return;
  }
  *(float *)&entityRay[8] = pTrace->fraction;
  *(Ray_t *)&trace.startpos.y = *ray;
  if ( *(float *)&entityRay[8] == 0.0 )
  {
    v11 = pTrace;
    memset(&trace.endpos.z, 0, 12);
    pTrace->fractionleftsolid = 1.0;
    pTrace->fraction = 1.0;
  }
  else
  {
    trace.endpos.z = (float)((float)(trace.endpos.z * *(float *)&entityRay[8]) + trace.startpos.y) - trace.startpos.y;
    v12 = (float)((float)(trace.plane.normal.x * *(float *)&entityRay[8]) + trace.startpos.z) - trace.startpos.z;
    v13 = (float)((float)(trace.plane.normal.y * *(float *)&entityRay[8]) + trace.endpos.x) - trace.endpos.x;
    pTrace->fractionleftsolid = pTrace->fractionleftsolid / *(float *)&entityRay[8];
    trace.plane.normal.x = v12;
    trace.plane.normal.y = v13;
    pTrace->fraction = 1.0;
    v11 = pTrace;
  }
  v14 = pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_ENTITIES_ONLY;
  GetTraceType = pTraceFilter->GetTraceType;
  entityRay[50] = v14;
  entityRay[51] = GetTraceType(this: pTraceFilter) == TRACE_EVERYTHING_FILTER_PROPS;
  if ( entityRay[50] == 0 )
  {
    v16 = 0;
    *(_DWORD *)&entityRay[44] = *(_DWORD *)(*(_DWORD *)&entityRay[52] + 1312);
    for ( *(_DWORD *)&entityRay[56] = 0; v16 < *(int *)&entityRay[44]; *(_DWORD *)&entityRay[56] = ++v16 )
    {
      if ( v11->allsolid )
        break;
      v17 = *(_DWORD *)(*(_DWORD *)&entityRay[52] + 784);
      v18 = *(_DWORD *)(v17 + 8 * v16 + 4);
      if ( entityRay[51] == 0
        || pTraceFilter->ShouldHitEntity(this: pTraceFilter, a2: *(IHandleEntity **)(v17 + 8 * v16), a3: fMask) != 0 )
      {
        (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)v18 + 60))(
          a1: v18,
          a2: &entityRay[16],
          a3: &entityRay[28]);
        if ( IsBoxIntersectingRay(
               vecBoxMin: (const Vector *)&entityRay[16],
               vecBoxMax: (const Vector *)&entityRay[28],
               ray: (const Ray_t *)&trace.startpos.y,
               flTolerance: 0.03125) )
        {
          v19 = *(CEngineTrace **)&entityRay[40];
          (*(void (__thiscall **)(_DWORD, float *, int, int, CGameTrace *))(**(_DWORD **)&entityRay[40] + 16))(
            a1: *(_DWORD *)&entityRay[40],
            a2: &trace.startpos.y,
            a3: fMask,
            a4: v18,
            a5: &v25);
          CEngineTrace::ClipTraceToTrace(this: v19, clipTrace: &v25, pFinalTrace: pTrace);
          v16 = *(_DWORD *)&entityRay[56];
        }
      }
      v11 = pTrace;
    }
  }
  v20 = 0;
  *(_DWORD *)&entityRay[44] = *(_DWORD *)(*(_DWORD *)&entityRay[52] + 776);
  for ( *(_DWORD *)&entityRay[56] = 0; v20 < *(int *)&entityRay[44]; *(_DWORD *)&entityRay[56] = v20 )
  {
    if ( v11->allsolid )
      break;
    v21 = *(_DWORD *)(*(_DWORD *)&entityRay[52] + 248);
    v22 = *(_DWORD *)(v21 + 8 * v20 + 4);
    if ( pTraceFilter->ShouldHitEntity(this: pTraceFilter, a2: *(IHandleEntity **)(v21 + 8 * v20), a3: fMask) != 0 )
    {
      (*(void (__thiscall **)(int, _BYTE *, _BYTE *))(*(_DWORD *)v22 + 60))(
        a1: v22,
        a2: &entityRay[16],
        a3: &entityRay[28]);
      if ( IsBoxIntersectingRay(
             vecBoxMin: (const Vector *)&entityRay[16],
             vecBoxMax: (const Vector *)&entityRay[28],
             ray: (const Ray_t *)&trace.startpos.y,
             flTolerance: 0.03125) )
      {
        v23 = *(CEngineTrace **)&entityRay[40];
        (*(void (__thiscall **)(_DWORD, float *, int, int, CGameTrace *))(**(_DWORD **)&entityRay[40] + 16))(
          a1: *(_DWORD *)&entityRay[40],
          a2: &trace.startpos.y,
          a3: fMask,
          a4: v22,
          a5: &v25);
        CEngineTrace::ClipTraceToTrace(this: v23, clipTrace: &v25, pFinalTrace: pTrace);
      }
    }
    v11 = pTrace;
    v20 = *(_DWORD *)&entityRay[56] + 1;
  }
  v11->fraction = v11->fraction * *(float *)&entityRay[8];
  v11->fractionleftsolid = v11->fractionleftsolid * *(float *)&entityRay[8];
  if ( !ray->m_IsRay )
  {
    v11->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    v11->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    v11->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    v11->fractionleftsolid = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10177D30
// Name: public: CTraceListData::CTraceListData(void)
// Source: json
//------------------------------------------------------------------------------
CTraceListData *__thiscall CTraceListData::CTraceListData(CTraceListData *this)
{
  this->ITraceListData::__vftable = (ITraceListData_vtbl *)&ITraceListData::`vftable';
  this->IPartitionEnumerator::__vftable = (CTraceListData_vtbl *)&CTraceListData::`vftable'{for `IPartitionEnumerator'};
  this->ITraceListData::__vftable = (ITraceListData_vtbl *)&CTraceListData::`vftable'{for `ITraceListData'};
  this->m_brushList.m_Memory.m_nAllocationCount = 64;
  this->m_brushList.m_Memory.m_nMallocGrowSize = 0;
  this->m_brushList.m_Size = 0;
  this->m_brushList.m_Memory.m_pMemory = this->m_brushList.m_Memory.m_pFixedMemory;
  this->m_brushList.m_pElements = this->m_brushList.m_Memory.m_pFixedMemory;
  this->m_brushList.m_Memory.m_nGrowSize = -1;
  this->m_dispList.m_Memory.m_nGrowSize = -1;
  this->m_dispList.m_Memory.m_nAllocationCount = 32;
  this->m_dispList.m_Memory.m_nMallocGrowSize = 0;
  this->m_dispList.m_Size = 0;
  this->m_dispList.m_Memory.m_pMemory = this->m_dispList.m_Memory.m_pFixedMemory;
  this->m_dispList.m_pElements = this->m_dispList.m_Memory.m_pFixedMemory;
  this->m_entityList.m_Memory.m_nGrowSize = -1;
  this->m_entityList.m_Memory.m_nAllocationCount = 64;
  this->m_entityList.m_Memory.m_nMallocGrowSize = 0;
  this->m_entityList.m_Size = 0;
  this->m_entityList.m_Memory.m_pMemory = this->m_entityList.m_Memory.m_pFixedMemory;
  this->m_entityList.m_pElements = this->m_entityList.m_Memory.m_pFixedMemory;
  this->m_staticPropList.m_Memory.m_nGrowSize = -1;
  this->m_staticPropList.m_Memory.m_nAllocationCount = 64;
  this->m_staticPropList.m_Memory.m_nMallocGrowSize = 0;
  this->m_staticPropList.m_Size = 0;
  this->m_staticPropList.m_Memory.m_pMemory = this->m_staticPropList.m_Memory.m_pFixedMemory;
  this->m_staticPropList.m_pElements = this->m_staticPropList.m_Memory.m_pFixedMemory;
  this->m_pEngineTrace = nullptr;
  this->m_bFoundNonSolidLeaf = false;
  this->m_mins.x = 0.0;
  this->m_mins.y = 0.0;
  this->m_mins.z = 0.0;
  this->m_maxs.x = 0.0;
  this->m_maxs.y = 0.0;
  this->m_maxs.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10177E40
// Name: public: virtual bool CTraceListData::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceListData::IsEmpty(CTraceListData *this)
{
  return LODWORD(this->m_maxs.z) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10177E60
// Name: public: virtual void CTraceListData::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceListData::Reset(CTraceListData *this)
{
  *(_DWORD *)&this->m_brushList.m_Memory.m_pFixedMemory[62] = 0;
  *(_DWORD *)&this->m_dispList.m_Memory.m_pFixedMemory[30] = 0;
  this->m_entityList.m_Memory.m_pFixedMemory[63].pCollideable = nullptr;
  this->m_staticPropList.m_Memory.m_pFixedMemory[63].pCollideable = nullptr;
  this->m_staticPropList.m_pElements = nullptr;
  this->m_mins.x = 0.0;
  this->m_mins.y = 0.0;
  this->m_mins.z = 0.0;
  this->m_maxs.x = 0.0;
  this->m_maxs.y = 0.0;
  this->m_maxs.z = 0.0;
  LOBYTE(this->m_pEngineTrace) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10177F20
// Name: public: virtual class ITraceListData __near * CEngineTrace::AllocTraceListData(void)
// Source: json
//------------------------------------------------------------------------------
ITraceListData *__thiscall CEngineTrace::AllocTraceListData(CEngineTrace *this)
{
  CTraceListData *v1; // eax
  CTraceListData *v2; // eax

  v1 = (CTraceListData *)MemAlloc_Alloc(nSize: 0x548u);
  if ( v1 != nullptr && (v2 = CTraceListData::CTraceListData(this: v1)) != nullptr )
    return &v2->ITraceListData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10177F50
// Name: public: virtual enum IterationRetval_t CTraceListData::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CTraceListData::EnumElement(CTraceListData *this, IHandleEntity *pHandleEntity)
{
  ICollideable *v4; // esi
  const char *v5; // eax
  IStaticPropMgrEngine *v7; // eax
  int v8; // eax
  int v9; // eax
  char pHandleEntitya; // [esp+14h] [ebp+8h]

  v4 = this->m_pEngineTrace->HandleEntityToCollideable(this: this->m_pEngineTrace, a2: pHandleEntity);
  pHandleEntitya = v4->GetSolidFlags(this: v4);
  if ( v4->GetSolid(this: v4) != SOLID_NONE && (pHandleEntitya & 4) == 0 )
  {
    v7 = StaticPropMgr();
    if ( v7->IsStaticProp_2(this: v7, a2: pHandleEntity) )
    {
      v8 = CUtlVector<collideable_handleentity_t,CUtlMemoryFixedGrowable<collideable_handleentity_t,64,int>>::InsertBefore(
             this: &this->m_staticPropList,
             elem: this->m_staticPropList.m_Size);
      this->m_staticPropList.m_Memory.m_pMemory[v8].pCollideable = v4;
      this->m_staticPropList.m_Memory.m_pMemory[v8].pEntity = pHandleEntity;
    }
    else
    {
      v9 = CUtlVector<collideable_handleentity_t,CUtlMemoryFixedGrowable<collideable_handleentity_t,64,int>>::InsertBefore(
             this: &this->m_entityList,
             elem: this->m_entityList.m_Size);
      this->m_entityList.m_Memory.m_pMemory[v9].pCollideable = v4;
      this->m_entityList.m_Memory.m_pMemory[v9].pEntity = pHandleEntity;
    }
    return ITERATION_CONTINUE;
  }
  else
  {
    v5 = this->m_pEngineTrace->GetDebugName(this: this->m_pEngineTrace, a2: pHandleEntity);
    _Msg(a1: "%s in solid list (not solid)\n", v5);
    return ITERATION_CONTINUE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325130
// Name: _CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10325140
// Name: _dynamic_atexit_destructor_for__path_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__path_command__()
{
  ConCommand::~ConCommand(this: &path_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325150
// Name: _dynamic_atexit_destructor_for__fs_printopenfiles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_printopenfiles_command__()
{
  ConCommand::~ConCommand(this: &fs_printopenfiles_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325160
// Name: _dynamic_atexit_destructor_for__fs_warning_level_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_warning_level_command__()
{
  ConCommand::~ConCommand(this: &fs_warning_level_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325170
// Name: _dynamic_atexit_destructor_for__fs_syncdvddevcache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_syncdvddevcache_command__()
{
  ConCommand::~ConCommand(this: &fs_syncdvddevcache_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1012B870
// Name: public: virtual bool CTraceFilterHitAll::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterHitAll::ShouldHitEntity(CRConServer *this, int hSocket, const netadr_s *netAdr)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10174E50
// Name: public: virtual class ICollideable __near * CEngineTraceClient::GetCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::GetCollideable(CEngineTraceClient *this, IHandleEntity *pEntity)
{
  CStaticPropMgr *v2; // eax
  ICollideable *result; // eax
  const CBaseHandle *v4; // eax
  int v5; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pEntity);
  if ( result == nullptr )
  {
    v4 = pEntity->GetRefEHandle(this: pEntity);
    v5 = ((int (__thiscall *)(IClientEntityList *, unsigned int))entitylist->GetClientUnknownFromHandle)(
           a1: entitylist,
           a2: v4->m_Index);
    return (*(ICollideable *(__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174EA0
// Name: public: virtual class ICollideable __near * CEngineTraceServer::GetCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceServer::GetCollideable(CEngineTraceServer *this, IHandleEntity *pEntity)
{
  CStaticPropMgr *v2; // eax
  ICollideable *result; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pEntity);
  if ( result == nullptr )
    return ((ICollideable *(__thiscall *)(IHandleEntity *))pEntity->__vftable[1].dtr_IHandleEntity)(a1: pEntity);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174EE0
// Name: private: static int CPointContentsEnum::GetModelHeadNode(class ICollideable __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CPointContentsEnum::GetModelHeadNode(ICollideable *pCollide)
{
  unsigned int v1; // edi
  cmodel_t *v2; // eax

  v1 = pCollide->GetCollisionModelIndex(this: pCollide);
  if ( v1 <= 0x3FF
    && pCollide->GetCollisionModel(this: pCollide) != nullptr
    && (v2 = CM_InlineModelNumber(index: v1 - 1)) != nullptr )
  {
    return v2->headnode;
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10174F30
// Name: public: virtual int CEngineTrace::GetPointContents_WorldOnly(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetPointContents_WorldOnly(
        CEngineTrace *this,
        const Vector *vecAbsPosition,
        int contentsMask)
{
  return CM_PointContents(p: vecAbsPosition, headnode: 0, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x10175030
// Name: public: virtual int CEngineTrace::GetStatByIndex(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetStatByIndex(CEngineTrace *this, int index, bool bClear)
{
  int result; // eax

  if ( index >= 3 )
    return 0;
  result = this->m_traceStatCounters[index];
  if ( bClear )
    this->m_traceStatCounters[index] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175060
// Name: public: static void CSetupBrushQuery::BrushQueryReleaseFunc(class CBrushQuery __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSetupBrushQuery::BrushQueryReleaseFunc(TraceInfo_t *pBrushQuery)
{
  pBrushQuery = (TraceInfo_t *)LODWORD(pBrushQuery->m_end.y);
  EndTrace(pTraceInfo: &pBrushQuery);
}

//------------------------------------------------------------------------------
// Address: 0x10175080
// Name: disp_list_all_collideable
// Source: json
//------------------------------------------------------------------------------
void __cdecl disp_list_all_collideable()
{
  int v0; // esi
  int v1; // eax
  int v2; // edi
  unsigned __int16 m_nFlags; // bx
  const char *v4; // edx
  const char *v5; // ecx
  const char *v6; // eax
  int nPhysicsCollide; // [esp+3Ch] [ebp-Ch]
  int nHullCollide; // [esp+40h] [ebp-8h]
  int nRayCollide; // [esp+44h] [ebp-4h]

  v0 = 0;
  nPhysicsCollide = 0;
  nHullCollide = 0;
  nRayCollide = 0;
  ConMsg(a1: "Displacement list:\n");
  v1 = g_DispCollTreeCount;
  if ( g_DispCollTreeCount > 0 )
  {
    v2 = 0;
    do
    {
      m_nFlags = g_pDispCollTrees[v2].m_nFlags;
      v4 = "   Ray";
      if ( (m_nFlags & 8) == 0 )
        v4 = "NO Ray";
      v5 = "   Hull";
      if ( (m_nFlags & 4) == 0 )
        v5 = "NO Hull";
      v6 = "   Physics";
      if ( (m_nFlags & 2) == 0 )
        v6 = "NO Physics";
      ConMsg(
        a1: "Displacement %3d, location ( % 10.2f % 10.2f % 10.2f ), collision flags: %s %s %s\n",
        v0,
        (float)((float)(g_pDispCollTrees[v2].m_maxs.x + g_pDispCollTrees[v2].m_mins.x) * 0.5),
        (float)((float)(g_pDispCollTrees[v2].m_maxs.y + g_pDispCollTrees[v2].m_mins.y) * 0.5),
        (float)((float)(g_pDispCollTrees[v2].m_maxs.z + g_pDispCollTrees[v2].m_mins.z) * 0.5),
        v6,
        v5,
        v4);
      nPhysicsCollide += (m_nFlags & 2) != 0;
      v1 = g_DispCollTreeCount;
      nHullCollide += (m_nFlags & 4) != 0;
      nRayCollide += (m_nFlags & 8) != 0;
      ++v0;
      ++v2;
    }
    while ( v0 < g_DispCollTreeCount );
  }
  ConMsg(
    a1: "Total displacements: %d\nCollision stats: %d with physics, %d with hull, %d with ray.\n",
    v1,
    nPhysicsCollide,
    nHullCollide,
    nRayCollide);
}

//------------------------------------------------------------------------------
// Address: 0x101751E0
// Name: public: virtual void CEngineTrace::GetDisplacementMesh(int,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetDisplacementMesh(CEngineTrace *this, int nIndex, virtualmeshlist_t *pMeshTriList)
{
  CDispCollTree::GetVirtualMeshList(this: &g_pDispCollTrees[nIndex], pList: pMeshTriList);
}

//------------------------------------------------------------------------------
// Address: 0x10175200
// Name: public: virtual int CEngineTrace::GetLeafContainingPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetLeafContainingPoint(CEngineTrace *this, const Vector *vPos)
{
  return CM_PointLeafnum(p: vPos);
}

//------------------------------------------------------------------------------
// Address: 0x10175220
// Name: public: virtual unsigned int CStudioConvexInfo::GetContents(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioConvexInfo::GetContents(CStudioConvexInfo *this, int convexGameData)
{
  if ( convexGameData != 0 )
    return *(_DWORD *)((char *)this->m_pStudioHdr + 216 * convexGameData + this->m_pStudioHdr->boneindex - 36);
  else
    return this->m_pStudioHdr->contents;
}

//------------------------------------------------------------------------------
// Address: 0x10175250
// Name: private: bool CEngineTrace::ClipRayToBSP(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToBSP(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  int v6; // eax
  int headnode; // edi
  const Vector *v8; // eax
  const QAngle *v10; // [esp-8h] [ebp-10h]

  v6 = pEntity->GetCollisionModelIndex(this: pEntity);
  headnode = CM_InlineModelNumber(index: v6 - 1)->headnode;
  v10 = pEntity->GetCollisionAngles(this: pEntity);
  v8 = pEntity->GetCollisionOrigin(this: pEntity);
  CM_TransformedBoxTrace(ray, headnode, brushmask: fMask, origin: v8, angles: v10, tr: pTrace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101752A0
// Name: private: bool CEngineTrace::ClipRayToOBB(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToOBB(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const Vector *v6; // eax
  const QAngle *v7; // [esp-Ch] [ebp-18h]
  const Vector *v8; // [esp-8h] [ebp-14h]
  const Vector *v9; // [esp-4h] [ebp-10h]

  if ( pEntity->GetSolid(this: pEntity) != SOLID_OBB )
    return 0;
  v9 = pEntity->OBBMaxs(this: pEntity);
  v8 = pEntity->OBBMins(this: pEntity);
  v7 = pEntity->GetCollisionAngles(this: pEntity);
  v6 = pEntity->GetCollisionOrigin(this: pEntity);
  IntersectRayWithOBB(
    ray,
    vecBoxOrigin: v6,
    angBoxRotation: v7,
    vecOBBMins: v8,
    vecOBBMaxs: v9,
    flTolerance: 0.03125,
    pTrace);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10175310
// Name: private: virtual void CEngineTraceClient::SetTraceEntity(class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTraceClient::SetTraceEntity(
        CEngineTraceClient *this,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  int v3; // edi
  CStaticPropMgr *v4; // eax
  CStaticPropMgr *v5; // eax

  if ( pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid )
  {
    if ( pCollideable != nullptr )
    {
      v3 = pCollideable->GetEntityHandle(this: pCollideable);
      v4 = StaticPropMgr();
      if ( v4->IsStaticProp_2(this: v4, a2: (IHandleEntity *)v3) )
      {
        pTrace->m_pEnt = (struct CBaseEntity *)entitylist->GetClientEntity(this: entitylist, a2: 0);
        v5 = StaticPropMgr();
        pTrace->hitbox = v5->GetStaticPropIndex(this: v5, a2: (IHandleEntity *)v3) + 1;
      }
      else
      {
        pTrace->m_pEnt = (struct CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(a1: v3);
      }
    }
    else
    {
      pTrace->m_pEnt = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101753A0
// Name: private: virtual void CEngineTraceServer::SetTraceEntity(class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTraceServer::SetTraceEntity(
        CEngineTraceServer *this,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  struct CBaseEntity *v3; // edi
  CStaticPropMgr *v4; // eax
  struct CBaseEntity *m_pUnk; // eax
  CStaticPropMgr *v6; // eax

  if ( pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid )
  {
    v3 = (struct CBaseEntity *)pCollideable->GetEntityHandle(this: pCollideable);
    v4 = StaticPropMgr();
    if ( v4->IsStaticProp_2(this: v4, a2: (IHandleEntity *)v3) )
    {
      if ( (sv.edicts->m_fStateFlags & 4) != 0 )
        m_pUnk = (struct CBaseEntity *)sv.edicts->m_pUnk;
      else
        m_pUnk = nullptr;
      pTrace->m_pEnt = m_pUnk;
      v6 = StaticPropMgr();
      pTrace->hitbox = v6->GetStaticPropIndex(this: v6, a2: (IHandleEntity *)v3) + 1;
    }
    else
    {
      pTrace->m_pEnt = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175420
// Name: public: virtual void CEngineTrace::ClipRayToEntity(struct Ray_t const __near &,unsigned int,class IHandleEntity __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::ClipRayToEntity(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        IHandleEntity *pEntity,
        CGameTrace *pTrace)
{
  CEngineTrace_vtbl *v6; // edi
  int v7; // eax

  v6 = this->__vftable;
  v7 = ((int (__thiscall *)(CEngineTrace *, IHandleEntity *, CGameTrace *))this->GetCollideable)(
         a1: this,
         a2: pEntity,
         a3: pTrace);
  ((void (__thiscall *)(CEngineTrace *, const Ray_t *, unsigned int, int))v6->ClipRayToCollideable)(
    a1: this,
    a2: ray,
    a3: fMask,
    a4: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10175450
// Name: public: virtual enum IterationRetval_t CEntityListAlongRay::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CEntityListAlongRay::EnumElement(CEntityListAlongRay *this, IHandleEntity *pHandleEntity)
{
  int m_nCount; // eax

  m_nCount = this->m_nCount;
  if ( m_nCount >= 1024 )
  {
    _DevMsg(a1: 1, a2: "Max entity count along ray exceeded!\n");
  }
  else
  {
    this->m_EntityHandles[m_nCount] = pHandleEntity;
    ++this->m_nCount;
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x10175490
// Name: private: virtual char const __near * CEngineTraceServer::GetDebugName(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTraceServer::GetDebugName(CEngineTraceServer *this, IHandleEntity *pHandleEntity)
{
  CStaticPropMgr *v2; // eax
  int v4; // eax

  v2 = StaticPropMgr();
  if ( v2->IsStaticProp_2(this: v2, a2: pHandleEntity) )
    return "static prop";
  if ( pHandleEntity == nullptr
    || ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity) == 0 )
  {
    return "<null>";
  }
  v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
  return (*(const char *(__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101754F0
// Name: private: virtual class ICollideable __near * CEngineTraceClient::HandleEntityToCollideable(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::HandleEntityToCollideable(
        CEngineTraceClient *this,
        IHandleEntity *pHandleEntity)
{
  CStaticPropMgr *v2; // eax
  ICollideable *result; // eax

  v2 = StaticPropMgr();
  result = v2->GetStaticProp(this: v2, a2: pHandleEntity);
  if ( result == nullptr && pHandleEntity != nullptr )
    return ((ICollideable *(__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].dtr_IHandleEntity)(a1: pHandleEntity);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175520
// Name: private: virtual char const __near * CEngineTraceClient::GetDebugName(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineTraceClient::GetDebugName(CEngineTraceClient *this, IHandleEntity *pHandleEntity)
{
  CStaticPropMgr *v2; // eax
  int v4; // eax
  int v5; // esi

  v2 = StaticPropMgr();
  if ( v2->IsStaticProp_2(this: v2, a2: pHandleEntity) )
    return "static prop";
  if ( pHandleEntity == nullptr )
    return "<null>";
  v4 = ((int (__thiscall *)(IHandleEntity *))pHandleEntity->__vftable[1].SetRefEHandle)(a1: pHandleEntity);
  v5 = v4;
  if ( v4 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4) != 0 )
    return *(const char **)((*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5) + 8);
  else
    return "client entity";
}

//------------------------------------------------------------------------------
// Address: 0x10175590
// Name: private: virtual class ICollideable __near * CEngineTraceClient::GetWorldCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceClient::GetWorldCollideable(CEngineTraceClient *this)
{
  IClientEntity *v1; // eax

  v1 = entitylist->GetClientEntity(this: entitylist, a2: 0);
  if ( v1 != nullptr )
    return v1->GetCollideable(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101755B0
// Name: private: virtual class ICollideable __near * CEngineTraceServer::GetWorldCollideable(void)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__thiscall CEngineTraceServer::GetWorldCollideable(CEngineTraceServer *this)
{
  IServerUnknown *m_pUnk; // ecx

  if ( sv.edicts != nullptr && (sv.edicts->m_fStateFlags & 4) != 0 && (m_pUnk = sv.edicts->m_pUnk) != nullptr )
    return m_pUnk->GetCollideable(this: m_pUnk);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101755D0
// Name: ComputeRayBounds
// Source: json
//------------------------------------------------------------------------------
void __fastcall ComputeRayBounds(Vector *maxs, Vector *mins, const Ray_t *ray)
{
  float x; // xmm0_4
  float v4; // xmm1_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector start; // 0:^4.12

  x = ray->m_Delta.x;
  start = ray->m_Start.Vector;
  if ( ray->m_IsRay )
  {
    if ( x <= 0.0 )
    {
      maxs->x = start.x;
      v4 = ray->m_Delta.x + start.x;
    }
    else
    {
      v4 = ray->m_Start.x;
      maxs->x = x + start.x;
    }
    mins->x = v4;
    y = ray->m_Delta.y;
    if ( y <= 0.0 )
    {
      maxs->y = start.y;
      mins->y = start.y + ray->m_Delta.y;
    }
    else
    {
      maxs->y = y + start.y;
      mins->y = start.y;
    }
    z = ray->m_Delta.z;
    if ( z <= 0.0 )
    {
      maxs->z = start.z;
      v7 = ray->m_Delta.z + start.z;
    }
    else
    {
      v7 = start.z;
      maxs->z = z + start.z;
    }
    mins->z = v7;
  }
  else
  {
    if ( x <= 0.0 )
    {
      maxs->x = ray->m_Extents.x + start.x;
      v8 = ray->m_Delta.x + start.x;
    }
    else
    {
      v8 = ray->m_Start.x;
      maxs->x = (float)(x + start.x) + ray->m_Extents.x;
    }
    mins->x = v8 - ray->m_Extents.x;
    v9 = ray->m_Delta.y;
    if ( v9 <= 0.0 )
    {
      maxs->y = ray->m_Extents.y + start.y;
      mins->y = (float)(start.y + ray->m_Delta.y) - ray->m_Extents.y;
    }
    else
    {
      maxs->y = (float)(v9 + start.y) + ray->m_Extents.y;
      mins->y = start.y - ray->m_Extents.y;
    }
    v10 = ray->m_Delta.z;
    if ( v10 <= 0.0 )
    {
      maxs->z = ray->m_Extents.z + start.z;
      v11 = (float)(ray->m_Delta.z + start.z) - ray->m_Extents.z;
    }
    else
    {
      maxs->z = (float)(v10 + start.z) + ray->m_Extents.z;
      v11 = start.z - ray->m_Extents.z;
    }
    mins->z = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175780
// Name: public: virtual bool CTraceListData::CanTraceRay(struct Ray_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceListData::CanTraceRay(CTraceListData *this, const Ray_t *ray)
{
  Vector rayMins; // [esp+4h] [ebp-18h] BYREF
  Vector rayMaxs; // [esp+10h] [ebp-Ch] BYREF

  ComputeRayBounds(maxs: &rayMaxs, mins: &rayMins, ray);
  return this->m_mins.z >= rayMaxs.x
      && rayMins.x >= *(float *)&this->m_staticPropList.m_pElements
      && this->m_maxs.x >= rayMaxs.y
      && rayMins.y >= this->m_mins.x
      && this->m_maxs.y >= rayMaxs.z
      && rayMins.z >= this->m_mins.y;
}

//------------------------------------------------------------------------------
// Address: 0x10175810
// Name: public: virtual void CEngineTrace::SetupLeafAndEntityListRay(struct Ray_t const __near &,class ITraceListData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::SetupLeafAndEntityListRay(
        CEngineTrace *this,
        const Ray_t *ray,
        ITraceListData *pTraceData)
{
  const Vector *v4; // ecx
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF

  ComputeRayBounds(&maxs, &mins, ray);
  this->SetupLeafAndEntityListBox(this, a2: &mins, a3: v4, a4: pTraceData);
}

//------------------------------------------------------------------------------
// Address: 0x10175940
// Name: public: virtual enum IterationRetval_t CEnumerationFilter::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEnumerationFilter::EnumElement(CEnumerationFilter *this, IHandleEntity *pHandleEntity)
{
  CStaticPropMgr *v3; // eax

  v3 = StaticPropMgr();
  return !v3->IsStaticProp_2(this: v3, a2: pHandleEntity)
      && ((int (__thiscall *)(IEntityEnumerator *, IHandleEntity *))this->m_pEnumerator->EnumEntity)(
           a1: this->m_pEnumerator,
           a2: pHandleEntity) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175980
// Name: public: virtual void CEngineTrace::EnumerateEntities(struct Ray_t const __near &,bool,class IEntityEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::EnumerateEntities(
        CEngineTrace *this,
        const Ray_t *ray,
        bool bTriggers,
        IEntityEnumerator *pEnumerator)
{
  CEngineTrace_vtbl *v4; // edx
  int (*SpatialPartitionTriggerMask)(void); // eax
  int v6; // esi
  CSpatialPartition *v7; // eax
  CEnumerationFilter enumerator; // [esp+4h] [ebp-Ch] BYREF

  ++this->m_traceStatCounters[2];
  v4 = this->__vftable;
  enumerator.__vftable = (CEnumerationFilter_vtbl *)&CEnumerationFilter::`vftable';
  enumerator.m_pEnumerator = pEnumerator;
  enumerator.m_pEngineTrace = this;
  if ( bTriggers )
    SpatialPartitionTriggerMask = (int (*)(void))v4->SpatialPartitionTriggerMask;
  else
    SpatialPartitionTriggerMask = (int (*)(void))v4->SpatialPartitionMask;
  v6 = SpatialPartitionTriggerMask();
  if ( v6 != 0 )
  {
    v7 = SpatialPartition();
    v7->EnumerateElementsAlongRay(this: v7, a2: v6, a3: ray, a4: false, a5: &enumerator);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101759E0
// Name: public: virtual void CEngineTrace::EnumerateEntities(class Vector const __near &,class Vector const __near &,class IEntityEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::EnumerateEntities(
        CEngineTrace *this,
        const Vector *vecAbsMins,
        const Vector *vecAbsMaxs,
        IEntityEnumerator *pEnumerator)
{
  CSpatialPartition *v5; // ebx
  CSpatialPartition_vtbl *v6; // edi
  int v7; // eax
  CEnumerationFilter enumerator; // [esp+Ch] [ebp-Ch] BYREF

  ++this->m_traceStatCounters[2];
  enumerator.__vftable = (CEnumerationFilter_vtbl *)&CEnumerationFilter::`vftable';
  enumerator.m_pEnumerator = pEnumerator;
  enumerator.m_pEngineTrace = this;
  v5 = SpatialPartition();
  v6 = v5->__vftable;
  v7 = ((int (__thiscall *)(CEngineTrace *, const Vector *, const Vector *, _DWORD, CEnumerationFilter *))this->SpatialPartitionMask)(
         a1: this,
         a2: vecAbsMins,
         a3: vecAbsMaxs,
         a4: 0,
         a5: &enumerator);
  ((void (__thiscall *)(CSpatialPartition *, int))v6->EnumerateElementsInBox)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10175A60
// Name: public: virtual void CEngineTrace::FreeTraceListData(class ITraceListData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::FreeTraceListData(CEngineTrace *this, ITraceListData *pTraceListData)
{
  if ( pTraceListData != nullptr )
    ((void (__thiscall *)(ITraceListData *, int))pTraceListData->dtr_ITraceListData)(a1: pTraceListData, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10175A80
// Name: public: static bool CPointContentsEnum::TestEntity(class CEngineTrace __near *,class ICollideable __near *,class Vector const __near &,int,int __near *,class ICollideable __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPointContentsEnum::TestEntity@<al>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CEngineTrace *pEngineTrace,
        ICollideable *pCollide,
        const Vector *vPos,
        int validMask,
        int *pContents,
        ICollideable **pWorldCollideable)
{
  CStaticPropMgr *v9; // eax
  CStaticPropMgr_vtbl *v10; // edi
  int v11; // eax
  const model_t *v13; // eax
  int ModelHeadNode; // edi
  const QAngle *v15; // eax
  ICollideable_vtbl *v16; // edx
  const Vector *v17; // eax
  int v18; // eax
  int v19; // [esp-14h] [ebp-CCh]
  int v20; // [esp-10h] [ebp-C8h]
  _DWORD v21[3]; // [esp-Ch] [ebp-C4h] BYREF
  CGameTrace trace; // [esp+0h] [ebp-B8h] BYREF
  int v23; // [esp+54h] [ebp-64h]
  Ray_t ray; // [esp+58h] [ebp-60h]
  CStaticPropMgr *v25; // [esp+A8h] [ebp-10h]
  int v26; // [esp+ACh] [ebp-Ch]
  void *v27; // [esp+B0h] [ebp-8h]
  void *retaddr; // [esp+B8h] [ebp+0h]

  v26 = a1;
  v27 = retaddr;
  v20 = a3;
  v19 = a2;
  if ( (validMask & 1) != 0
    && (v9 = StaticPropMgr(),
        v10 = v9->IStaticPropMgrEngine::__vftable,
        v25 = v9,
        v11 = ((int (__thiscall *)(ICollideable *, int, int))pCollide->GetEntityHandle)(a1: pCollide, a2: v19, a3),
        v10->IsStaticProp_2(this: v25, a2: (IHandleEntity *)v11)) )
  {
    ray.m_Extents.y = 0.0;
    Ray_t::Init(this: (Ray_t *)&trace.m_pEnt, start: vPos, end: vPos);
    ((void (__thiscall *)(CEngineTrace *, struct CBaseEntity **, int, ICollideable *, _DWORD *, int, int))pEngineTrace->ClipRayToCollideable)(
      a1: pEngineTrace,
      a2: &trace.m_pEnt,
      a3: -1,
      a4: pCollide,
      a5: v21,
      a6: v19,
      a7: v20);
    if ( trace.plane.pad[1] != 0 )
    {
      *pContents = 1;
      *pWorldCollideable = pEngineTrace->GetWorldCollideable(this: pEngineTrace);
      return 1;
    }
  }
  else if ( (((int (__thiscall *)(ICollideable *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD))pCollide->GetSolidFlags)(
               a1: pCollide,
               a2: v19,
               a3: v20,
               a4: v21[0],
               a5: v21[1],
               a6: v21[2],
               a7: LODWORD(trace.startpos.x),
               a8: LODWORD(trace.startpos.y),
               a9: LODWORD(trace.startpos.z),
               a10: LODWORD(trace.endpos.x),
               a11: LODWORD(trace.endpos.y),
               a12: LODWORD(trace.endpos.z),
               a13: LODWORD(trace.plane.normal.x),
               a14: LODWORD(trace.plane.normal.y),
               a15: LODWORD(trace.plane.normal.z),
               a16: LODWORD(trace.plane.dist),
               a17: *(_DWORD *)&trace.plane.type,
               a18: LODWORD(trace.fraction),
               a19: trace.contents,
               a20: *(_DWORD *)&trace.dispFlags,
               a21: LODWORD(trace.fractionleftsolid),
               a22: trace.surface.name,
               a23: *(_DWORD *)&trace.surface.surfaceProps,
               a24: trace.hitgroup,
               a25: *(_DWORD *)&trace.physicsbone,
               a26: trace.m_pEnt,
               a27: trace.hitbox,
               a28: v23,
               a29: LODWORD(ray.m_Start.x),
               a30: LODWORD(ray.m_Start.y),
               a31: LODWORD(ray.m_Start.z),
               a32: LODWORD(ray.m_Start.w),
               a33: LODWORD(ray.m_Delta.x),
               a34: LODWORD(ray.m_Delta.y),
               a35: LODWORD(ray.m_Delta.z),
               a36: LODWORD(ray.m_Delta.w),
               a37: LODWORD(ray.m_StartOffset.x),
               a38: LODWORD(ray.m_StartOffset.y),
               a39: LODWORD(ray.m_StartOffset.z),
               a40: LODWORD(ray.m_StartOffset.w),
               a41: LODWORD(ray.m_Extents.x),
               a42: LODWORD(ray.m_Extents.y),
               a43: LODWORD(ray.m_Extents.z),
               a44: LODWORD(ray.m_Extents.w),
               a45: ray.m_pWorldAxisTransform,
               a46: *(_DWORD *)&ray.m_IsRay,
               a47: *(_DWORD *)(&ray.m_IsSwept + 3),
               a48: *(_DWORD *)(&ray.m_IsSwept + 7))
           & 0x20) != 0 )
  {
    v13 = pCollide->GetCollisionModel(this: pCollide);
    if ( v13 != nullptr && v13->type == mod_brush )
    {
      ModelHeadNode = CPointContentsEnum::GetModelHeadNode(pCollide);
      v15 = pCollide->GetCollisionAngles(this: pCollide);
      v16 = pCollide->__vftable;
      *(_DWORD *)(&ray.m_IsSwept + 7) = v15;
      v17 = v16->GetCollisionOrigin(this: pCollide);
      v18 = CM_TransformedPointContents(
              p: vPos,
              headnode: ModelHeadNode,
              origin: v17,
              angles: *(const QAngle **)(&ray.m_IsSwept + 7));
      if ( (v18 & validMask) != 0 )
      {
        *pContents = v18;
        *pWorldCollideable = pCollide;
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175BA0
// Name: public: virtual enum IterationRetval_t CPointContentsEnum::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ICollideable *__userpurge CPointContentsEnum::EnumElement@<eax>(
        CPointContentsEnum *this@<ecx>,
        int a2@<edi>,
        IHandleEntity *pHandleEntity)
{
  ICollideable *result; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  result = this->m_pEngineTrace->HandleEntityToCollideable(this: this->m_pEngineTrace, a2: pHandleEntity);
  if ( result != nullptr )
    return (ICollideable *)(CPointContentsEnum::TestEntity(
                              a1: (int)&savedregs,
                              a2,
                              a3: (int)this,
                              pEngineTrace: this->m_pEngineTrace,
                              pCollide: result,
                              vPos: &this->m_Pos,
                              validMask: this->m_validMask,
                              pContents: &this->m_Contents,
                              pWorldCollideable: &this->m_pCollide) != 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175BF0
// Name: public: virtual int CEngineTrace::GetPointContents_Collideable(class ICollideable __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CEngineTrace::GetPointContents_Collideable@<eax>(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        ICollideable *pCollide,
        const Vector *vecAbsPosition)
{
  CStaticPropMgr *v6; // eax
  CStaticPropMgr_vtbl *v7; // edi
  int v8; // eax
  CEngineTrace *v9; // edi
  int result; // eax
  const model_t *v11; // eax
  int ModelHeadNode; // edi
  const Vector *v13; // eax
  _DWORD v15[22]; // [esp-B8h] [ebp-C4h] BYREF
  Ray_t v16; // [esp-60h] [ebp-6Ch] BYREF
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-Ch] [ebp-18h]
  const QAngle *v19; // [esp-8h] [ebp-14h]
  CEngineTrace *v20; // [esp-4h] [ebp-10h]
  int v21; // [esp+0h] [ebp-Ch]
  void *v22; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v21 = a2;
  v22 = retaddr;
  v20 = this;
  v6 = StaticPropMgr();
  v7 = v6->IStaticPropMgrEngine::__vftable;
  v8 = ((int (__thiscall *)(ICollideable *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, int, int, CStaticPropMgr *))pCollide->GetEntityHandle)(
         a1: pCollide,
         a2: a3,
         a3: a4,
         a4: v15[0],
         a5: v15[1],
         a6: v15[2],
         a7: v15[3],
         a8: v15[4],
         a9: v15[5],
         a10: v15[6],
         a11: v15[7],
         a12: v15[8],
         a13: v15[9],
         a14: v15[10],
         a15: v15[11],
         a16: v15[12],
         a17: v15[13],
         a18: v15[14],
         a19: v15[15],
         a20: v15[16],
         a21: v15[17],
         a22: v15[18],
         a23: v15[19],
         a24: v15[20],
         a25: v15[21],
         a26: LODWORD(v16.m_Start.x),
         a27: LODWORD(v16.m_Start.y),
         a28: LODWORD(v16.m_Start.z),
         a29: LODWORD(v16.m_Start.w),
         a30: LODWORD(v16.m_Delta.x),
         a31: LODWORD(v16.m_Delta.y),
         a32: LODWORD(v16.m_Delta.z),
         a33: LODWORD(v16.m_Delta.w),
         a34: LODWORD(v16.m_StartOffset.x),
         a35: LODWORD(v16.m_StartOffset.y),
         a36: LODWORD(v16.m_StartOffset.z),
         a37: LODWORD(v16.m_StartOffset.w),
         a38: LODWORD(v16.m_Extents.x),
         a39: LODWORD(v16.m_Extents.y),
         a40: LODWORD(v16.m_Extents.z),
         a41: LODWORD(v16.m_Extents.w),
         a42: v16.m_pWorldAxisTransform,
         a43: *(_DWORD *)&v16.m_IsRay,
         a44: *(_DWORD *)(&v16.m_IsSwept + 3),
         a45: *(_DWORD *)(&v16.m_IsSwept + 7),
         a46: v17,
         a47: v18,
         a48: v6);
  if ( v7->IsStaticProp_2(this: (struct CStaticPropMgr *)v19, a2: (IHandleEntity *)v8) )
  {
    v16.m_pWorldAxisTransform = nullptr;
    Ray_t::Init(this: &v16, start: vecAbsPosition, end: vecAbsPosition);
    v9 = v20;
    v20->ClipRayToCollideable(this: v20, a2: &v16, a3: -1u, a4: pCollide, a5: (CGameTrace *)v15);
    if ( HIBYTE(v15[13]) != 0 )
    {
      v9->GetWorldCollideable(this: v9);
      return 1;
    }
  }
  else if ( (pCollide->GetSolidFlags(this: pCollide) & 0x20) != 0 )
  {
    v11 = pCollide->GetCollisionModel(this: pCollide);
    if ( v11 != nullptr && v11->type == mod_brush )
    {
      ModelHeadNode = CPointContentsEnum::GetModelHeadNode(pCollide);
      v19 = pCollide->GetCollisionAngles(this: pCollide);
      v13 = pCollide->GetCollisionOrigin(this: pCollide);
      result = CM_TransformedPointContents(p: vecAbsPosition, headnode: ModelHeadNode, origin: v13, angles: v19);
      if ( result != 0 )
        return result;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175CF0
// Name: GetBrushesInCollideable_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBrushesInCollideable_r(
        CCollisionBSPData *pBSPData,
        unsigned int *pVisitedBrushes,
        unsigned int **pKeepBrushes,
        int node)
{
  int i; // eax
  cnode_t *v5; // edi
  unsigned int v6; // ecx
  cleaf_t *v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  cleaf_t *m_pArray; // eax
  int numleafbrushes; // edi

  for ( i = node; i >= 0; i = v5->children[1] )
  {
    v5 = &pBSPData->map_nodes.m_pArray[i];
    GetBrushesInCollideable_r(pBSPData, pVisitedBrushes, pKeepBrushes, node: v5->children[0]);
  }
  v6 = -1 - i;
  v7 = &pBSPData->map_leafs.m_pArray[v6];
  v8 = 0;
  if ( v7->numleafbrushes != 0 )
  {
    do
    {
      v9 = pBSPData->map_leafbrushes.m_pArray[v8 + v7->firstleafbrush];
      if ( pVisitedBrushes[v9] == 0 )
      {
        pVisitedBrushes[v9] = 1;
        *(*pKeepBrushes)++ = v9;
      }
      m_pArray = pBSPData->map_leafs.m_pArray;
      numleafbrushes = m_pArray[v6].numleafbrushes;
      v7 = &m_pArray[v6];
      ++v8;
    }
    while ( v8 < numleafbrushes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175D90
// Name: public: virtual int CEngineTrace::GetBrushInfo(int,int __near &,struct BrushSideInfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetBrushInfo(
        CEngineTrace *this,
        int iBrush,
        int *ContentsOut,
        BrushSideInfo_t *pBrushSideInfoOut,
        int iBrushSideInfoArraySize)
{
  cbrush_t *v5; // edx
  int numsides; // eax
  int v7; // ebx
  float *p_dist; // esi
  int v9; // edi
  __int16 v10; // ax
  int firstbrushside; // eax
  cbrushside_t *v13; // edi
  cbrushside_t *v14; // esi
  float *p_z; // eax
  float *p_x; // ecx
  double x; // st7
  cboxbrush_t *pBox; // [esp+8h] [ebp+8h]
  BrushSideInfo_t *pBrushSideInfoOuta; // [esp+10h] [ebp+10h]
  BrushSideInfo_t *iBrushSideInfoArraySizea; // [esp+14h] [ebp+14h]

  if ( iBrush < 0 || iBrush >= g_BSPData.numbrushes )
    return 0;
  v5 = &g_BSPData.map_brushes.m_pArray[iBrush];
  *ContentsOut = v5->contents;
  numsides = v5->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    if ( pBrushSideInfoOut != nullptr && iBrushSideInfoArraySize >= 6 )
    {
      v7 = 0;
      iBrushSideInfoArraySizea = pBrushSideInfoOut;
      pBox = &g_BSPData.map_boxbrushes.m_pArray[v5->firstbrushside];
      p_dist = &pBrushSideInfoOut->plane.dist;
      v9 = 1;
      pBrushSideInfoOuta = (BrushSideInfo_t *)&pBox[-1].surfaceIndex[2];
      do
      {
        _V_memset(dest: p_dist - 3, fill: 0, count: 20);
        v10 = v9;
        if ( v7 >= 3 )
        {
          iBrushSideInfoArraySizea[-1].plane.dist = -1.0;
          *(_DWORD *)p_dist = LODWORD(pBrushSideInfoOuta->plane.normal.x) ^ _mask__NegFloat_;
        }
        else
        {
          iBrushSideInfoArraySizea->plane.normal.x = 1.0;
          *p_dist = pBrushSideInfoOuta[1].plane.normal.y;
          v10 = __ROL4__(v9, 3);
        }
        *((_WORD *)p_dist + 4) = 0;
        pBrushSideInfoOuta = (BrushSideInfo_t *)((char *)pBrushSideInfoOuta + 4);
        iBrushSideInfoArraySizea = (BrushSideInfo_t *)((char *)iBrushSideInfoArraySizea + 28);
        *((_WORD *)p_dist + 5) = (unsigned __int16)(v10 & pBox->thinMask) != 0;
        ++v7;
        p_dist += 6;
        v9 = __ROL4__(v9, 1);
      }
      while ( v7 < 6 );
      return 6;
    }
    else
    {
      return -6;
    }
  }
  else if ( pBrushSideInfoOut != nullptr && iBrushSideInfoArraySize >= numsides )
  {
    firstbrushside = v5->firstbrushside;
    v13 = &g_BSPData.map_brushsides.m_pArray[firstbrushside + v5->numsides];
    v14 = &g_BSPData.map_brushsides.m_pArray[firstbrushside];
    if ( v14 != v13 )
    {
      p_z = &pBrushSideInfoOut->plane.normal.z;
      do
      {
        p_x = &v14->plane->normal.x;
        x = v14->plane->normal.x;
        ++v14;
        *(p_z - 2) = x;
        p_z += 6;
        *(p_z - 7) = p_x[1];
        *(p_z - 6) = p_x[2];
        *(p_z - 5) = p_x[3];
        *((_BYTE *)p_z - 16) = *((_BYTE *)p_x + 16);
        *((_BYTE *)p_z - 15) = *((_BYTE *)p_x + 17);
        *((_BYTE *)p_z - 14) = *((_BYTE *)p_x + 18);
        *((_BYTE *)p_z - 13) = *((_BYTE *)p_x + 19);
        *((_WORD *)p_z - 6) = v14[-1].bBevel;
        *((_WORD *)p_z - 5) = v14[-1].bThin;
      }
      while ( v14 != v13 );
    }
    return v5->numsides;
  }
  else
  {
    return -numsides;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175F30
// Name: public: virtual bool CEngineTrace::PointOutsideWorld(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTrace::PointOutsideWorld(CEngineTrace *this, const Vector *ptTest)
{
  return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum(p: ptTest)].cluster == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10175F60
// Name: public: virtual unsigned int CBrushConvexInfo::GetContents(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushConvexInfo::GetContents(CBrushConvexInfo *this, int convexGameData)
{
  return this->m_pBSPData->map_brushes.m_pArray[convexGameData].contents;
}

//------------------------------------------------------------------------------
// Address: 0x10175F80
// Name: private: bool CEngineTrace::ClipRayToVPhysics(struct Ray_t const __near &,unsigned int,class ICollideable __near *,struct studiohdr_t __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipRayToVPhysics(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        studiohdr_t *pStudioHdr,
        CGameTrace *pTrace)
{
  const model_t *v8; // edi
  IPhysicsObject *v9; // eax
  int v10; // edi
  IPhysicsCollision_vtbl *v11; // ebx
  int v12; // eax
  int v13; // eax
  const Vector *v14; // eax
  const Vector *v15; // eax
  float x; // ecx
  float y; // edx
  int studio; // eax
  vcollide_t *v19; // edi
  IPhysicsCollision_vtbl *v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  vcollide_t *v24; // eax
  vcollide_t *v25; // ebx
  CCollisionBSPData **v26; // edi
  int v27; // eax
  int v28; // eax
  float vecMins; // [esp+3Ch] [ebp-18h]
  float vecMins_4; // [esp+40h] [ebp-14h]
  float vecMins_8; // [esp+44h] [ebp-10h]
  CBrushConvexInfo brushConvex; // [esp+48h] [ebp-Ch] BYREF
  float z; // [esp+50h] [ebp-4h]
  IPhysicsCollision_vtbl *bTraced; // [esp+64h] [ebp+10h]
  char bTraced_3; // [esp+67h] [ebp+13h]

  if ( pEntity->GetSolid(this: pEntity) != SOLID_VPHYSICS )
    return 0;
  bTraced_3 = 0;
  v8 = pEntity->GetCollisionModel(this: pEntity);
  if ( v8 != nullptr )
  {
    if ( pStudioHdr != nullptr )
    {
      z = *(float *)&pStudioHdr;
      studio = v8->studio;
      brushConvex.m_pBSPData = (CCollisionBSPData *)&CStudioConvexInfo::`vftable';
      v19 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: studio);
      if ( v19 != nullptr && (*(_WORD *)v19 & 0x7FFF) != 0 )
      {
        v20 = physcollision->__vftable;
        v21 = ((int (__thiscall *)(ICollideable *, CGameTrace *))pEntity->GetCollisionAngles)(a1: pEntity, a2: pTrace);
        v22 = ((int (__thiscall *)(ICollideable *, int))pEntity->GetCollisionOrigin)(a1: pEntity, a2: v21);
        ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, unsigned int, CCollisionBSPData **, struct CPhysCollide *, int))v20->TraceBox)(
          a1: physcollision,
          a2: ray,
          a3: fMask,
          a4: &brushConvex.m_pBSPData,
          a5: *v19->solids,
          a6: v22);
        return 1;
      }
    }
    else if ( !ray->m_IsRay || v8->type != mod_brush )
    {
      v23 = pEntity->GetCollisionModelIndex(this: pEntity);
      v24 = CM_VCollideForModel(modelindex: v23, pModel: v8);
      v25 = v24;
      if ( v24 != nullptr && (*(_WORD *)v24 & 0x7FFF) != 0 )
      {
        v26 = v8->type == mod_brush ? &brushConvex.m_pBSPData : nullptr;
        brushConvex.m_pBSPData = (CCollisionBSPData *)&CBrushConvexInfo::`vftable';
        z = COERCE_FLOAT(&g_BSPData);
        bTraced = physcollision->__vftable;
        v27 = ((int (__thiscall *)(ICollideable *, CGameTrace *))pEntity->GetCollisionAngles)(a1: pEntity, a2: pTrace);
        v28 = ((int (__thiscall *)(ICollideable *, int))pEntity->GetCollisionOrigin)(a1: pEntity, a2: v27);
        ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, unsigned int, CCollisionBSPData **, struct CPhysCollide *, int))bTraced->TraceBox)(
          a1: physcollision,
          a2: ray,
          a3: fMask,
          a4: v26,
          a5: *v25->solids,
          a6: v28);
        return 1;
      }
    }
    return bTraced_3;
  }
  else
  {
    v9 = pEntity->GetVPhysicsObject(this: pEntity);
    if ( v9 != nullptr && (v10 = (int)v9->GetCollide(this: v9)) != 0 )
    {
      v11 = physcollision->__vftable;
      v12 = ((int (__thiscall *)(ICollideable *, CGameTrace *))pEntity->GetCollisionAngles)(a1: pEntity, a2: pTrace);
      v13 = ((int (__thiscall *)(ICollideable *, int))pEntity->GetCollisionOrigin)(a1: pEntity, a2: v12);
      ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, unsigned int, _DWORD, int, int))v11->TraceBox)(
        a1: physcollision,
        a2: ray,
        a3: fMask,
        a4: 0,
        a5: v10,
        a6: v13);
      return 1;
    }
    else
    {
      v14 = pEntity->OBBMins(this: pEntity);
      vecMins_4 = v14->y;
      vecMins = v14->x;
      vecMins_8 = v14->z;
      v15 = pEntity->OBBMaxs(this: pEntity);
      x = v15->x;
      y = v15->y;
      z = v15->z;
      *(float *)&brushConvex.m_pBSPData = y;
      _Warning(
        a1: "CEngineTrace::ClipRayToVPhysics : no model; bbox {%g,%g,%g}-{%g,%g,%g}\n",
        vecMins,
        vecMins_4,
        vecMins_8,
        x,
        y,
        z);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101761D0
// Name: private: bool CEngineTrace::ClipRayToBBox(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CEngineTrace::ClipRayToBBox@<al>(
        CEngineTrace *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const matrix3x4_t *v9; // ecx
  const matrix3x4_t *m_pWorldAxisTransform; // ecx
  Vector *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  ICollideable_vtbl *v15; // edx
  const Vector *(__thiscall *GetCollisionOrigin)(ICollideable *); // eax
  const float *v17; // eax
  bool m_IsSwept; // cl
  ICollideable_vtbl *v19; // edx
  const Vector *(__thiscall *v20)(ICollideable *); // eax
  float *v21; // eax
  ICollideable_vtbl *v22; // edx
  float v23; // xmm0_4
  const Vector *(__thiscall *v24)(ICollideable *); // eax
  float *v25; // eax
  float v26; // xmm0_4
  const matrix3x4_t *v27; // edx
  float v28; // xmm0_4
  float fraction; // xmm0_4
  float v30; // eax
  float v31; // xmm0_4
  float fractionleftsolid; // xmm0_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float x; // xmm0_4
  float v39; // xmm3_4
  float y; // xmm2_4
  float v41; // xmm0_4
  float z; // xmm2_4
  float v43; // xmm1_4
  const Vector *(__thiscall *OBBMins)(ICollideable *); // eax
  float v45; // eax
  ICollideable_vtbl *v46; // edx
  float *v47; // eax
  ICollideable_vtbl *v48; // edx
  float v49; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // eax
  float v51; // eax
  ICollideable_vtbl *v52; // edx
  float *v53; // eax
  float v54[3]; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t ray_l; // [esp+0h] [ebp-B0h] BYREF
  float v56; // [esp+50h] [ebp-60h]
  Vector temp; // [esp+54h] [ebp-5Ch] BYREF
  VectorAligned vecAbsMins; // [esp+60h] [ebp-50h] BYREF
  VectorAligned vecInvDelta; // [esp+70h] [ebp-40h] BYREF
  float v60[2]; // [esp+90h] [ebp-20h] BYREF
  const matrix3x4_t *v61; // [esp+98h] [ebp-18h]
  Vector localEntityOrigin; // [esp+9Ch] [ebp-14h]
  void *v63; // [esp+A8h] [ebp-8h]
  void *retaddr; // [esp+B0h] [ebp+0h]

  localEntityOrigin.z = a2;
  v63 = retaddr;
  if ( ((int (__thiscall *)(ICollideable *, int, int))pEntity->GetSolid)(a1: pEntity, a2: a3, a3: a4) != 2 )
    return 0;
  if ( ray->m_IsRay || (v9 = ray->m_pWorldAxisTransform, *(float *)&v9 == 0.0) )
  {
    x = ray->m_Delta.x;
    if ( x == 0.0 )
      v39 = 3.4028235e38;
    else
      v39 = 1.0 / x;
    y = ray->m_Delta.y;
    if ( y == 0.0 )
      v41 = 3.4028235e38;
    else
      v41 = 1.0 / y;
    z = ray->m_Delta.z;
    if ( z == 0.0 )
      v43 = 3.4028235e38;
    else
      v43 = 1.0 / z;
    OBBMins = pEntity->OBBMins;
    vecAbsMins.y = v39;
    vecAbsMins.z = v41;
    vecAbsMins.w = v43;
    v45 = COERCE_FLOAT((int)OBBMins(this: pEntity));
    v46 = pEntity->__vftable;
    localEntityOrigin.y = v45;
    v47 = (float *)v46->GetCollisionOrigin(this: pEntity);
    v48 = pEntity->__vftable;
    temp.x = *(float *)LODWORD(localEntityOrigin.y) + *v47;
    temp.y = v47[1] + *(float *)(LODWORD(localEntityOrigin.y) + 4);
    v49 = v47[2] + *(float *)(LODWORD(localEntityOrigin.y) + 8);
    OBBMaxs = v48->OBBMaxs;
    temp.z = v49;
    v51 = COERCE_FLOAT((int)OBBMaxs(this: pEntity));
    v52 = pEntity->__vftable;
    localEntityOrigin.y = v51;
    v53 = (float *)v52->GetCollisionOrigin(this: pEntity);
    vecInvDelta.y = *v53 + *(float *)LODWORD(localEntityOrigin.y);
    vecInvDelta.z = v53[1] + *(float *)(LODWORD(localEntityOrigin.y) + 4);
    vecInvDelta.w = v53[2] + *(float *)(LODWORD(localEntityOrigin.y) + 8);
    IntersectRayWithBox(
      ray,
      inInvDelta: (VectorAligned *)&vecAbsMins.y,
      inBoxMins: (const VectorAligned *)&temp,
      inBoxMaxs: (VectorAligned *)&vecInvDelta.y,
      pTrace);
  }
  else
  {
    LODWORD(localEntityOrigin.x) = &ray_l.m_Start.y;
    v61 = v9;
    ray_l.m_Extents.y = 0.0;
    *(VectorAligned *)((char *)&ray_l.m_StartOffset + 4) = ray->m_Extents;
    VectorIRotate(in1: &ray->m_Delta.x, in2: v9, out: &ray->m_Delta.x);
    m_pWorldAxisTransform = ray->m_pWorldAxisTransform;
    memset(&ray_l.m_Delta.y, 0, 12);
    VectorITransform(in1: &ray->m_Start.x, in2: m_pWorldAxisTransform, out: v54);
    v11 = Ray_t::InvDelta(this: (Ray_t *)v54, result: (Vector *)(&ray_l.m_IsSwept + 3));
    v12 = v11->y;
    v13 = v11->z;
    v14 = v11->x;
    v15 = pEntity->__vftable;
    LODWORD(localEntityOrigin.y) = ray->m_pWorldAxisTransform;
    GetCollisionOrigin = v15->GetCollisionOrigin;
    vecAbsMins.y = v14;
    vecAbsMins.z = v12;
    vecAbsMins.w = v13;
    v17 = (const float *)GetCollisionOrigin(this: pEntity);
    VectorITransform(in1: v17, in2: (const matrix3x4_t *)LODWORD(localEntityOrigin.y), out: v60);
    m_IsSwept = ray->m_IsSwept;
    v19 = pEntity->__vftable;
    LOBYTE(ray_l.m_Extents.z) = ray->m_IsRay;
    v20 = v19->OBBMins;
    BYTE1(ray_l.m_Extents.z) = m_IsSwept;
    v21 = (float *)v20(this: pEntity);
    v22 = pEntity->__vftable;
    temp.x = *v21 + v60[0];
    temp.y = v21[1] + v60[1];
    v23 = v21[2] + *(float *)&v61;
    v24 = v22->OBBMaxs;
    temp.z = v23;
    v25 = (float *)v24(this: pEntity);
    vecInvDelta.y = *v25 + v60[0];
    v26 = v25[1] + v60[1];
    LODWORD(localEntityOrigin.x) = pTrace;
    vecInvDelta.z = v26;
    vecInvDelta.w = v25[2] + *(float *)&v61;
    IntersectRayWithBox(
      ray: (const Ray_t *)v54,
      inInvDelta: (VectorAligned *)&vecAbsMins.y,
      inBoxMins: (const VectorAligned *)&temp,
      inBoxMaxs: (VectorAligned *)&vecInvDelta.y,
      pTrace);
    if ( pTrace->fraction >= 1.0 && !pTrace->allsolid && !pTrace->startsolid )
    {
      pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
      pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
      pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
      return 1;
    }
    v27 = ray->m_pWorldAxisTransform;
    *(float *)(&ray_l.m_IsSwept + 3) = pTrace->plane.normal.x;
    v28 = pTrace->plane.normal.y;
    LODWORD(localEntityOrigin.x) = &pTrace->plane;
    *(float *)(&ray_l.m_IsSwept + 7) = v28;
    v56 = pTrace->plane.normal.z;
    VectorRotate(in1: (const float *)(&ray_l.m_IsSwept + 3), in2: v27, out: &pTrace->plane.normal.x);
    pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    fraction = pTrace->fraction;
    v30 = localEntityOrigin.x;
    if ( fraction == 1.0 )
    {
      pTrace->endpos.x = *(float *)LODWORD(localEntityOrigin.x) + pTrace->startpos.x;
      pTrace->endpos.y = *(float *)(LODWORD(v30) + 4) + pTrace->startpos.y;
      v31 = pTrace->startpos.z + *(float *)(LODWORD(v30) + 8);
    }
    else
    {
      pTrace->endpos.x = (float)(*(float *)LODWORD(localEntityOrigin.x) * fraction) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(*(float *)(LODWORD(v30) + 4) * fraction) + pTrace->startpos.y;
      v31 = (float)(fraction * *(float *)(LODWORD(v30) + 8)) + pTrace->startpos.z;
    }
    pTrace->endpos.z = v31;
    pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                               + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                       + (float)(pTrace->endpos.z * pTrace->plane.normal.z);
    fractionleftsolid = pTrace->fractionleftsolid;
    if ( fractionleftsolid < 1.0 )
    {
      v33 = pTrace->startpos.x;
      v34 = (float)(*(float *)(LODWORD(v30) + 4) * fractionleftsolid) + pTrace->startpos.y;
      v35 = *(float *)LODWORD(v30) * fractionleftsolid;
      v36 = fractionleftsolid * *(float *)(LODWORD(v30) + 8);
      pTrace->startpos.y = v34;
      v37 = pTrace->startpos.z + v36;
      pTrace->startpos.x = v33 + v35;
      pTrace->startpos.z = v37;
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10176620
// Name: public: virtual void CEngineTrace::SweepCollideable(class ICollideable __near *,class Vector const __near &,class Vector const __near &,class QAngle const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::SweepCollideable(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        ICollideable *pCollide,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        const QAngle *vecAngles,
        float fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  int v13; // eax
  const Vector *v14; // eax
  void (__thiscall *TraceRay)(struct CEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  _BYTE v18[12]; // [esp-Ch] [ebp-5Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-50h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&ray.m_IsRay = a2;
  *(_DWORD *)(&ray.m_IsSwept + 3) = retaddr;
  v13 = ((int (__thiscall *)(ICollideable *, int, int))pCollide->OBBMaxs)(a1: pCollide, a2: a3, a3: a4);
  v14 = (const Vector *)((int (__thiscall *)(ICollideable *, int))pCollide->OBBMins)(a1: pCollide, a2: v13);
  Ray_t::Init(
    this: (Ray_t *)v18,
    start: vecAbsStart,
    end: vecAbsEnd,
    mins: v14,
    maxs: (const Vector *)ray.m_pWorldAxisTransform);
  if ( (pCollide->GetSolidFlags(this: pCollide) & 0x100) != 0 )
    LODWORD(ray.m_Extents.y) = pCollide->GetRootParentToWorldTransform(this: pCollide);
  TraceRay = this->TraceRay;
  ray.m_pWorldAxisTransform = (const matrix3x4_t *)pTrace;
  LODWORD(ray.m_Extents.w) = pTraceFilter;
  ray.m_Extents.z = fMask;
  ((void (__thiscall *)(CEngineTrace *, _BYTE *))TraceRay)(a1: this, a2: v18);
}

//------------------------------------------------------------------------------
// Address: 0x10176710
// Name: public: virtual void CEngineTrace::GetBrushesInAABB(class Vector const __near &,class Vector const __near &,class CBrushQuery __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetBrushesInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs,
        CBrushQuery *BrushQuery,
        int nContentsMask,
        cleaf_t *nCModelIndex)
{
  void (__cdecl *m_pReleaseFunc)(CBrushQuery *); // eax
  TraceInfo_t *v7; // esi
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  CCollisionBSPData *m_pBSPData; // eax
  void *v19; // esp
  int v20; // eax
  unsigned int *m_pMemory; // ebx
  int v22; // edi
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // edi
  cbrush_t *m_pArray; // ecx
  cbrush_t *v28; // ebx
  int numsides; // eax
  int v30; // edx
  unsigned int *v31; // edx
  unsigned int v32; // [esp-1Ch] [ebp-58h]
  int v33[3]; // [esp+0h] [ebp-3Ch] BYREF
  Vector vExtents; // [esp+Ch] [ebp-30h]
  Vector vCenter; // [esp+18h] [ebp-24h]
  int iNumLeafs; // [esp+24h] [ebp-18h]
  int *pLeafList; // [esp+28h] [ebp-14h]
  unsigned int *pKeepBrushes; // [esp+2Ch] [ebp-10h]
  int iLeaf; // [esp+30h] [ebp-Ch]
  unsigned int *pVisitedBrushes; // [esp+34h] [ebp-8h]
  int iBrushCounter; // [esp+38h] [ebp-4h]
  int iMaxBrushSides; // [esp+44h] [ebp+8h]
  int iKeepBrushCounta; // [esp+48h] [ebp+Ch]
  int iKeepBrushCount; // [esp+48h] [ebp+Ch]
  cleaf_t *pLeaf; // [esp+54h] [ebp+18h]

  m_pReleaseFunc = BrushQuery->m_pReleaseFunc;
  if ( m_pReleaseFunc != nullptr )
    m_pReleaseFunc(a1: BrushQuery);
  BrushQuery->m_iCount = 0;
  BrushQuery->m_pBrushes = nullptr;
  BrushQuery->m_iMaxBrushSides = 0;
  BrushQuery->m_pReleaseFunc = nullptr;
  BrushQuery->m_pData = nullptr;
  v7 = BeginTrace();
  if ( nContentsMask == 0x40000 && host_state.worldbrush->m_pSurfaceBrushList == nullptr )
    nContentsMask = -1;
  x = vMaxs->x;
  y = vMaxs->y;
  z = vMaxs->z;
  v12 = (float)(vMins->y + y) * 0.5;
  v13 = (float)(vMins->z + z) * 0.5;
  vCenter.x = (float)(vMins->x + vMaxs->x) * 0.5;
  vCenter.y = v12;
  vCenter.z = v13;
  vExtents.x = x - vCenter.x;
  vExtents.y = y - v12;
  vExtents.z = z - v13;
  CM_ClearTrace(trace: &v7->m_trace);
  v7->m_bDispHit = 0;
  v7->m_DispStabDir.x = 0.0;
  v7->m_DispStabDir.y = 0.0;
  v7->m_DispStabDir.z = 0.0;
  v14 = vCenter.x;
  v7->m_start.y = v12;
  v7->m_start.z = v13;
  v7->m_start.x = v14;
  v7->m_contents = nContentsMask;
  v7->m_end.y = v12;
  v7->m_end.x = v14;
  v15 = vExtents.x;
  v7->m_end.z = v13;
  v7->m_mins.x = v15 * -1.0;
  v16 = vExtents.y;
  v7->m_mins.y = vExtents.y * -1.0;
  v17 = vExtents.z;
  v7->m_mins.z = vExtents.z * -1.0;
  v7->m_maxs.x = v15;
  v7->m_maxs.y = v16;
  v7->m_maxs.z = v17;
  v7->m_extents.x = v15;
  v7->m_extents.y = v16;
  v7->m_extents.z = v17;
  v7->m_delta = vec3_origin;
  v7->m_invDelta = vec3_origin;
  m_pBSPData = v7->m_pBSPData;
  *(_WORD *)&v7->m_ispoint = 0;
  iKeepBrushCounta = m_pBSPData->numleafs;
  v19 = alloca(4 * iKeepBrushCounta);
  pLeafList = v33;
  v20 = CM_BoxLeafnums(
          mins: vMins,
          maxs: vMaxs,
          list: v33,
          listsize: iKeepBrushCounta,
          topnode: nullptr,
          cmodelIndex: (int)nCModelIndex);
  m_pMemory = v7->m_BrushCounters[0].m_Memory.m_pMemory;
  v22 = v20;
  v32 = 4 * v7->m_BrushCounters[0].m_Size;
  iNumLeafs = v20;
  pVisitedBrushes = m_pMemory;
  memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count: v32);
  v23 = 0;
  pKeepBrushes = v7->m_BrushCounters[1].m_Memory.m_pMemory;
  iKeepBrushCount = 0;
  iMaxBrushSides = 0;
  iLeaf = 0;
  if ( v22 != 0 )
  {
    do
    {
      v24 = (int)&v7->m_pBSPData->map_leafs.m_pArray[pLeafList[v23]];
      v25 = 0;
      pLeaf = (cleaf_t *)v24;
      iBrushCounter = 0;
      if ( *(_WORD *)(v24 + 10) != 0 )
      {
        do
        {
          v26 = v7->m_pBSPData->map_leafbrushes.m_pArray[v25 + *(unsigned __int16 *)(v24 + 8)];
          if ( m_pMemory[v26] == 0 )
          {
            m_pMemory[v26] = 1;
            m_pArray = v7->m_pBSPData->map_brushes.m_pArray;
            v28 = &m_pArray[v26];
            if ( (nContentsMask & v28->contents) != 0 )
            {
              CM_TestBoxInBrush(pTraceInfo: v7, brush: &m_pArray[v26]);
              if ( v7->m_trace.allsolid )
              {
                pKeepBrushes[iKeepBrushCount++] = v26;
                numsides = v28->numsides;
                if ( (_WORD)numsides == 0xFFFF )
                  numsides = 6;
                if ( numsides > iMaxBrushSides )
                  iMaxBrushSides = numsides;
                v7->m_trace.allsolid = false;
              }
              v24 = (int)pLeaf;
            }
          }
          v30 = *(unsigned __int16 *)(v24 + 10);
          m_pMemory = pVisitedBrushes;
          v25 = iBrushCounter + 1;
          iBrushCounter = v25;
        }
        while ( v25 != v30 );
        v23 = iLeaf;
      }
      iLeaf = ++v23;
    }
    while ( v23 != iNumLeafs );
  }
  v31 = pKeepBrushes;
  BrushQuery->m_iCount = iKeepBrushCount;
  BrushQuery->m_pBrushes = v31;
  BrushQuery->m_iMaxBrushSides = iMaxBrushSides;
  BrushQuery->m_pData = v7;
  BrushQuery->m_pReleaseFunc = (void (__cdecl *)(CBrushQuery *))CSetupBrushQuery::BrushQueryReleaseFunc;
}

//------------------------------------------------------------------------------
// Address: 0x10176A50
// Name: public: virtual void CEngineTrace::GetBrushesInCollideable(class ICollideable __near *,class CBrushQuery __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::GetBrushesInCollideable(
        CEngineTrace *this,
        ICollideable *pCollideable,
        CBrushQuery *BrushQuery)
{
  CBrushQuery *v3; // ebx
  void (__cdecl *m_pReleaseFunc)(CBrushQuery *); // eax
  int v5; // eax
  cmodel_t *v6; // eax
  TraceInfo_t *v7; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_BrushCounters; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  CBrushQuery *v13; // edx
  int nHeadNode; // [esp+8h] [ebp-4h]
  int nHeadNodea; // [esp+8h] [ebp-4h]
  int iMaxBrushSides; // [esp+14h] [ebp+8h]
  int iMaxBrushSidesa; // [esp+14h] [ebp+8h]

  v3 = BrushQuery;
  m_pReleaseFunc = BrushQuery->m_pReleaseFunc;
  if ( m_pReleaseFunc != nullptr )
    m_pReleaseFunc(a1: BrushQuery);
  v3->m_iCount = 0;
  v3->m_pBrushes = nullptr;
  v3->m_iMaxBrushSides = 0;
  v3->m_pReleaseFunc = nullptr;
  v3->m_pData = nullptr;
  v5 = pCollideable->GetCollisionModelIndex(this: pCollideable);
  v6 = CM_InlineModelNumber(index: v5 - 1);
  if ( v6 != nullptr )
  {
    nHeadNode = v6->headnode;
    v7 = BeginTrace();
    CM_ClearTrace(trace: &v7->m_trace);
    v7->m_bDispHit = 0;
    v7->m_DispStabDir.x = 0.0;
    v7->m_DispStabDir.y = 0.0;
    v7->m_DispStabDir.z = 0.0;
    v7->m_contents = 0;
    v7->m_start = vec3_origin;
    v7->m_end = vec3_origin;
    v7->m_mins = vec3_origin;
    v7->m_maxs = vec3_origin;
    v7->m_extents = vec3_origin;
    v7->m_delta = vec3_origin;
    v7->m_invDelta = vec3_origin;
    *(_WORD *)&v7->m_ispoint = 0;
    m_BrushCounters = v7->m_BrushCounters;
    for ( iMaxBrushSides = 2; iMaxBrushSides != 0; --iMaxBrushSides )
    {
      memset(dst: (unsigned __int8 *)m_BrushCounters->m_Memory.m_pMemory, value: 0, count: 4 * m_BrushCounters->m_Size);
      ++m_BrushCounters;
    }
    BrushQuery = (CBrushQuery *)v7->m_BrushCounters[1].m_Memory.m_pMemory;
    GetBrushesInCollideable_r(
      pBSPData: v7->m_pBSPData,
      pVisitedBrushes: v7->m_BrushCounters[0].m_Memory.m_pMemory,
      pKeepBrushes: (unsigned int **)&BrushQuery,
      node: nHeadNode);
    v9 = ((char *)BrushQuery - (char *)v7->m_BrushCounters[1].m_Memory.m_pMemory) >> 2;
    BrushQuery = (CBrushQuery *)v7->m_BrushCounters[1].m_Memory.m_pMemory;
    v10 = 0;
    v11 = 0;
    iMaxBrushSidesa = 0;
    if ( v9 != 0 )
    {
      nHeadNodea = (int)v7->m_pBSPData->map_brushes.m_pArray;
      do
      {
        v12 = 6;
        if ( *(_WORD *)(nHeadNodea + 8 * *(&BrushQuery->m_iCount + v11) + 4) != 0xFFFF )
          v12 = *(unsigned __int16 *)(nHeadNodea + 8 * *(&BrushQuery->m_iCount + v11) + 4);
        v10 = iMaxBrushSidesa;
        if ( v12 > iMaxBrushSidesa )
        {
          v10 = v12;
          iMaxBrushSidesa = v12;
        }
        ++v11;
      }
      while ( v11 != v9 );
    }
    v13 = BrushQuery;
    v3->m_pData = v7;
    v3->m_iCount = v9;
    v3->m_pBrushes = (unsigned int *)v13;
    v3->m_iMaxBrushSides = v10;
    v3->m_pReleaseFunc = (void (__cdecl *)(CBrushQuery *))CSetupBrushQuery::BrushQueryReleaseFunc;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176CC0
// Name: public: virtual class CPhysCollide __near * CEngineTrace::GetCollidableFromDisplacementsInAABB(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__thiscall CEngineTrace::GetCollidableFromDisplacementsInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs)
{
  void *v3; // esp
  int *v4; // edi
  int v5; // ebx
  struct CPhysPolysoup *(__thiscall *PolysoupCreate)(IPhysicsCollision *); // eax
  int m_nCheckDepth; // ecx
  unsigned int v8; // esi
  int v9; // eax
  cleaf_t *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ebx
  CDispCollTree *v15; // edi
  int m_iCounter; // eax
  bool v17; // zf
  unsigned int *v18; // eax
  int indexCount; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ebx
  int v23; // eax
  int v24; // ecx
  const Vector *v25; // ebx
  const Vector *v26; // esi
  struct CPhysPolysoup *v27; // edi
  struct CPhysCollide *v28; // esi
  int v30[3]; // [esp+0h] [ebp-1864h] BYREF
  virtualmeshlist_t pList; // [esp+Ch] [ebp-1858h] BYREF
  int contents; // [esp+1824h] [ebp-40h]
  int v33; // [esp+1828h] [ebp-3Ch]
  int v34; // [esp+182Ch] [ebp-38h]
  int v35; // [esp+1830h] [ebp-34h]
  int v36; // [esp+1834h] [ebp-30h]
  unsigned int v37; // [esp+1838h] [ebp-2Ch]
  int *v38; // [esp+183Ch] [ebp-28h]
  unsigned int *m_pMemory; // [esp+1840h] [ebp-24h]
  int v40; // [esp+1844h] [ebp-20h]
  Vector *pt; // [esp+1848h] [ebp-1Ch]
  int v42; // [esp+184Ch] [ebp-18h]
  int v43; // [esp+1850h] [ebp-14h]
  int v44; // [esp+1854h] [ebp-10h]
  int v45; // [esp+1858h] [ebp-Ch]
  TraceInfo_t *pTraceInfo; // [esp+185Ch] [ebp-8h] BYREF
  struct CPhysPolysoup *v47; // [esp+1860h] [ebp-4h]

  v3 = alloca(4 * g_BSPData.numleafs);
  v4 = v30;
  v38 = v30;
  v5 = CM_BoxLeafnums(
         mins: vMins,
         maxs: vMaxs,
         list: v30,
         listsize: g_BSPData.numleafs,
         topnode: nullptr,
         cmodelIndex: 0);
  PolysoupCreate = physcollision->PolysoupCreate;
  v36 = v5;
  v47 = PolysoupCreate(this: physcollision);
  v42 = 0;
  pTraceInfo = BeginTrace();
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v8 = pTraceInfo->m_Count[m_nCheckDepth];
  v9 = 0;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v37 = v8;
  v40 = 0;
  if ( v5 <= 0 )
  {
LABEL_23:
    EndTrace(&pTraceInfo);
    v27 = v47;
    v28 = physcollision->ConvertPolysoupToCollide(this: physcollision, a2: v47, a3: 0);
    physcollision->PolysoupDestroy(this: physcollision, a2: v27);
    return v28;
  }
  else
  {
    while ( 1 )
    {
      v10 = &g_BSPData.map_leafs.m_pArray[v4[v9]];
      v43 = 0;
      v11 = *(_DWORD *)&v10->cluster;
      contents = v10->contents;
      v12 = *(_DWORD *)&v10->firstleafbrush;
      v13 = *(_DWORD *)&v10->dispListStart;
      v33 = v11;
      v34 = v12;
      v35 = v13;
      if ( HIWORD(v13) != 0 )
        break;
LABEL_22:
      v9 = v40 + 1;
      v40 = v9;
      if ( v9 >= v5 )
        goto LABEL_23;
    }
    v14 = 2 * (unsigned __int16)v13;
    v44 = v14;
    while ( 1 )
    {
      v15 = &g_pDispCollTrees[*(unsigned __int16 *)((char *)g_BSPData.map_dispList.m_pArray + v14)];
      m_iCounter = v15->m_iCounter;
      v17 = m_pMemory[m_iCounter] == v8;
      v18 = &m_pMemory[m_iCounter];
      if ( !v17 )
      {
        *v18 = v8;
        if ( IsBoxIntersectingBox(boxMin1: vMins, boxMax1: vMaxs, boxMin2: &v15->m_mins, boxMax2: &v15->m_maxs) )
        {
          CDispCollTree::GetVirtualMeshList(this: v15, &pList);
          v42 += pList.triangleCount;
          if ( v42 > 0xFFFF )
          {
            EndTrace(&pTraceInfo);
            return nullptr;
          }
          indexCount = pList.indexCount;
          v20 = 0;
          v45 = 0;
          if ( pList.indexCount > 0 )
            break;
        }
      }
LABEL_20:
      v14 += 2;
      ++v43;
      v44 = v14;
      if ( v43 >= HIWORD(v35) )
      {
        v5 = v36;
        v4 = v38;
        goto LABEL_22;
      }
    }
    while ( v20 + 2 < indexCount )
    {
      v21 = pList.indices[v20 + 1];
      v22 = pList.indices[v20 + 2];
      v23 = pList.indices[v20];
      if ( v23 >= pList.vertexCount )
        break;
      if ( v21 >= pList.vertexCount )
        break;
      v24 = v22;
      if ( v22 >= pList.vertexCount )
        break;
      v25 = &pList.pVerts[v21];
      v26 = &pList.pVerts[v23];
      pt = &pList.pVerts[v24];
      if ( IsPointInBox(pt: v26, boxMin: vMins, boxMax: vMaxs)
        || IsPointInBox(pt: v25, boxMin: vMins, boxMax: vMaxs)
        || IsPointInBox(pt, boxMin: vMins, boxMax: vMaxs) )
      {
        ((void (__stdcall *)(struct CPhysPolysoup *, const Vector *, const Vector *, Vector *, _DWORD))physcollision->PolysoupAddTriangle)(
          a1: v47,
          a2: v26,
          a3: v25,
          a4: pt,
          a5: v15->m_nSurfaceProps[0]);
      }
      indexCount = pList.indexCount;
      v45 += 3;
      if ( v45 >= pList.indexCount )
      {
        v8 = v37;
        v14 = v44;
        goto LABEL_20;
      }
      v20 = v45;
    }
    EndTrace(&pTraceInfo);
    physcollision->PolysoupDestroy(this: physcollision, a2: v47);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176FB0
// Name: public: virtual int CEngineTrace::GetMeshesFromDisplacementsInAABB(class Vector const __near &,class Vector const __near &,struct virtualmeshlist_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineTrace::GetMeshesFromDisplacementsInAABB(
        CEngineTrace *this,
        const Vector *vMins,
        const Vector *vMaxs,
        virtualmeshlist_t *pOutputMeshes,
        int iMaxOutputMeshes)
{
  void *v5; // esp
  int *v6; // esi
  int v7; // ebx
  int m_nCheckDepth; // ecx
  unsigned int *m_pMemory; // edx
  unsigned int v10; // ecx
  int v11; // eax
  int *p_contents; // eax
  int v13; // edx
  int v14; // eax
  virtualmeshlist_t *v15; // edi
  int v16; // ebx
  CDispCollTree *v17; // esi
  int m_iCounter; // edx
  int v19; // esi
  int v21[3]; // [esp+0h] [ebp-3Ch] BYREF
  cleaf_t curLeaf; // [esp+Ch] [ebp-30h]
  int iLeafCount; // [esp+1Ch] [ebp-20h]
  int *pLeafList; // [esp+20h] [ebp-1Ch]
  int count; // [esp+24h] [ebp-18h]
  unsigned int *pCounters; // [esp+28h] [ebp-14h]
  TraceInfo_t *pTraceInfo; // [esp+2Ch] [ebp-10h] BYREF
  int i; // [esp+30h] [ebp-Ch]
  int v29; // [esp+34h] [ebp-8h]
  int iMeshesWritten; // [esp+38h] [ebp-4h]

  iMeshesWritten = 0;
  v5 = alloca(4 * g_BSPData.numleafs);
  v6 = v21;
  pLeafList = v21;
  v7 = CM_BoxLeafnums(
         mins: vMins,
         maxs: vMaxs,
         list: v21,
         listsize: g_BSPData.numleafs,
         topnode: nullptr,
         cmodelIndex: 0);
  iLeafCount = v7;
  pTraceInfo = BeginTrace();
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v10 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = 0;
  pCounters = m_pMemory;
  count = v10;
  i = 0;
  if ( v7 <= 0 )
  {
LABEL_11:
    EndTrace(&pTraceInfo);
    return iMeshesWritten;
  }
  while ( 1 )
  {
    p_contents = &g_BSPData.map_leafs.m_pArray[v6[v11]].contents;
    curLeaf.contents = *p_contents;
    *(_DWORD *)&curLeaf.cluster = p_contents[1];
    v13 = p_contents[2];
    v14 = p_contents[3];
    *(_DWORD *)&curLeaf.firstleafbrush = v13;
    *(_DWORD *)&curLeaf.dispListStart = v14;
    v29 = 0;
    if ( HIWORD(v14) != 0 )
      break;
LABEL_10:
    v11 = i + 1;
    i = v11;
    if ( v11 >= v7 )
      goto LABEL_11;
  }
  v15 = &pOutputMeshes[iMeshesWritten];
  v16 = (unsigned __int16)v14;
  while ( 1 )
  {
    v17 = &g_pDispCollTrees[g_BSPData.map_dispList.m_pArray[v16]];
    m_iCounter = v17->m_iCounter;
    if ( pCounters[m_iCounter] != v10 )
      break;
LABEL_8:
    ++v16;
    if ( ++v29 >= curLeaf.dispCount )
    {
      v6 = pLeafList;
      v7 = iLeafCount;
      goto LABEL_10;
    }
  }
  pCounters[m_iCounter] = v10;
  if ( !IsBoxIntersectingBox(boxMin1: vMins, boxMax1: vMaxs, boxMin2: &v17->m_mins, boxMax2: &v17->m_maxs)
    || (CDispCollTree::GetVirtualMeshList(this: v17, pList: v15),
        v19 = iMeshesWritten + 1,
        ++v15,
        iMeshesWritten = v19,
        v19 != iMaxOutputMeshes) )
  {
    v10 = count;
    goto LABEL_8;
  }
  EndTrace(&pTraceInfo);
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x10177130
// Name: private: bool CEngineTrace::ClipTraceToTrace(class CGameTrace __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEngineTrace::ClipTraceToTrace(CEngineTrace *this, CGameTrace *clipTrace, CGameTrace *pFinalTrace)
{
  float flFractionLeftSolid; // [esp+1Ch] [ebp+8h]
  Vector vecStartPos; // 0:^C.12

  if ( !clipTrace->allsolid && !clipTrace->startsolid && pFinalTrace->fraction <= clipTrace->fraction )
    return 0;
  if ( pFinalTrace->startsolid )
  {
    vecStartPos = pFinalTrace->startpos;
    flFractionLeftSolid = pFinalTrace->fractionleftsolid;
    CBaseTrace::operator=(this: pFinalTrace, __that: clipTrace);
    pFinalTrace->fractionleftsolid = clipTrace->fractionleftsolid;
    pFinalTrace->surface = clipTrace->surface;
    pFinalTrace->hitgroup = clipTrace->hitgroup;
    pFinalTrace->physicsbone = clipTrace->physicsbone;
    pFinalTrace->worldSurfaceIndex = clipTrace->worldSurfaceIndex;
    pFinalTrace->m_pEnt = clipTrace->m_pEnt;
    pFinalTrace->hitbox = clipTrace->hitbox;
    pFinalTrace->startsolid = true;
    if ( flFractionLeftSolid > clipTrace->fractionleftsolid )
    {
      pFinalTrace->fractionleftsolid = flFractionLeftSolid;
      pFinalTrace->startpos = vecStartPos;
      return 1;
    }
  }
  else
  {
    CBaseTrace::operator=(this: pFinalTrace, __that: clipTrace);
    pFinalTrace->fractionleftsolid = clipTrace->fractionleftsolid;
    pFinalTrace->surface = clipTrace->surface;
    pFinalTrace->hitgroup = clipTrace->hitgroup;
    pFinalTrace->physicsbone = clipTrace->physicsbone;
    pFinalTrace->worldSurfaceIndex = clipTrace->worldSurfaceIndex;
    pFinalTrace->m_pEnt = clipTrace->m_pEnt;
    pFinalTrace->hitbox = clipTrace->hitbox;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10177240
// Name: public: virtual void CEngineTrace::TraceRay(struct Ray_t const __near &,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::TraceRay(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        int fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  void *v8; // esp
  char v10; // al
  float fraction; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  CSpatialPartition *v14; // eax
  CSpatialPartition_vtbl *v15; // edi
  CEngineTrace *v16; // esi
  CEngineTrace_vtbl *v17; // edx
  int v18; // eax
  TraceType_t v19; // eax
  TraceType_t (__thiscall *GetTraceType)(ITraceFilter *); // edx
  IHandleEntity *v21; // edi
  CStaticPropMgr *v22; // eax
  CGameTrace *v23; // edi
  void **v25; // [esp-10D0h] [ebp-10DCh] BYREF
  int v26; // [esp-10CCh] [ebp-10D8h]
  _DWORD v27[1024]; // [esp-10C8h] [ebp-10D4h]
  CGameTrace v28; // [esp-C8h] [ebp-D4h] BYREF
  Ray_t v29; // [esp-70h] [ebp-7Ch] BYREF
  void **v30; // [esp-1Ch] [ebp-28h] BYREF
  int v31; // [esp-18h] [ebp-24h]
  float v32; // [esp-14h] [ebp-20h]
  int v33; // [esp-10h] [ebp-1Ch]
  float fractionleftsolid; // [esp-Ch] [ebp-18h]
  CEngineTrace *i; // [esp-8h] [ebp-14h]
  bool v36; // [esp-2h] [ebp-Eh]
  bool v37; // [esp-1h] [ebp-Dh]
  int v38; // [esp+0h] [ebp-Ch]
  void *v39; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v38 = a2;
  v39 = retaddr;
  v8 = alloca(4312);
  i = this;
  if ( (_S2_11 & 1) == 0 )
  {
    _S2_11 |= 1u;
    counter_2.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "TraceRay",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_2.m_pCounter;
  ++this->m_traceStatCounters[0];
  v30 = &CTraceFilterHitAll::`vftable';
  if ( pTraceFilter == nullptr )
    pTraceFilter = (ITraceFilter *)&v30;
  CM_ClearTrace(trace: pTrace);
  if ( ((int (__thiscall *)(ITraceFilter *, int, int))pTraceFilter->GetTraceType)(a1: pTraceFilter, a2: a3, a3: a4) == 2 )
  {
    pTrace->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
    pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
    pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  }
  else
  {
    v10 = (char)this->GetWorldCollideable(this);
    CM_BoxTrace(ray, headnode: 0, brushmask: fMask, computeEndpt: v10, tr: pTrace);
    this->SetTraceEntity(this, a2: (ICollideable *)LODWORD(fractionleftsolid), a3: pTrace);
    if ( pTrace->startsolid || pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_WORLD_ONLY )
      return;
  }
  fraction = pTrace->fraction;
  v32 = fraction;
  fractionleftsolid = fraction;
  v29 = *ray;
  if ( fraction == 0.0 )
  {
    memset(&v29.m_Delta, 0, 12);
    fractionleftsolid = pTrace->fractionleftsolid;
    pTrace->fractionleftsolid = 1.0;
  }
  else
  {
    v29.m_Delta.y = (float)((float)(fraction * v29.m_Delta.y) + v29.m_Start.y) - v29.m_Start.y;
    v12 = (float)((float)(v29.m_Delta.x * fraction) + v29.m_Start.x) - v29.m_Start.x;
    v13 = (float)((float)(v29.m_Delta.z * fraction) + v29.m_Start.z) - v29.m_Start.z;
    pTrace->fractionleftsolid = pTrace->fractionleftsolid / fraction;
    v29.m_Delta.x = v12;
    v29.m_Delta.z = v13;
  }
  pTrace->fraction = 1.0;
  v25 = &CEntityListAlongRay::`vftable';
  v26 = 0;
  v14 = SpatialPartition();
  v15 = v14->__vftable;
  v16 = i;
  v17 = i->__vftable;
  v33 = (int)v14;
  v18 = ((int (__thiscall *)(CEngineTrace *, Ray_t *, _DWORD, void ***))v17->SpatialPartitionMask)(
          a1: i,
          a2: &v29,
          a3: 0,
          a4: &v25);
  ((void (__thiscall *)(int, int))v15->EnumerateElementsAlongRay)(a1: v33, a2: v18);
  v19 = pTraceFilter->GetTraceType(this: pTraceFilter);
  GetTraceType = pTraceFilter->GetTraceType;
  v36 = v19 == TRACE_ENTITIES_ONLY;
  v37 = GetTraceType(this: pTraceFilter) == TRACE_EVERYTHING_FILTER_PROPS;
  v31 = v26;
  for ( i = nullptr; (int)i < v31; i = (CEngineTrace *)((char *)i + 1) )
  {
    v21 = (IHandleEntity *)v27[(_DWORD)i];
    v33 = (int)v16->HandleEntityToCollideable(this: v16, a2: v21);
    v22 = StaticPropMgr();
    if ( v22->IsStaticProp_2(this: v22, a2: v21) )
    {
      if ( v36 )
        continue;
      if ( !v37 )
        goto LABEL_18;
    }
    if ( pTraceFilter->ShouldHitEntity(this: pTraceFilter, a2: v21, a3: fMask) != 0 )
    {
LABEL_18:
      v16->ClipRayToCollideable(this: v16, a2: &v29, a3: fMask, a4: (ICollideable *)v33, a5: &v28);
      v23 = pTrace;
      CEngineTrace::ClipTraceToTrace(this: v16, clipTrace: &v28, pFinalTrace: pTrace);
      if ( pTrace->allsolid )
        goto LABEL_21;
    }
  }
  v23 = pTrace;
LABEL_21:
  v23->fraction = v32 * v23->fraction;
  v23->fractionleftsolid = v23->fractionleftsolid * fractionleftsolid;
  if ( !ray->m_IsRay )
  {
    v23->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    v23->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    v23->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    v23->fractionleftsolid = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101775C0
// Name: public: virtual int CEngineTrace::GetSetDebugTraceCounter(int,enum DebugTraceCounterBehavior_t)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEngineTrace::GetSetDebugTraceCounter(
        CEngineTrace *this,
        char *value,
        DebugTraceCounterBehavior_t behavior)
{
  void *v3; // edi
  char *v4; // eax

  if ( DEBUG_THINK_TRACE_COUNTER_ALLOWED() )
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap);
    if ( behavior != kTRACE_COUNTER_SET )
    {
      if ( behavior != kTRACE_COUNTER_INC )
        return v3;
      v4 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) + (_DWORD)value;
    }
    else
    {
      v4 = value;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: v4);
    return v3;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10177620
// Name: private: bool CEngineTrace::ClipRayToHitboxes(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineTrace::ClipRayToHitboxes(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pCollideable,
        CGameTrace *pTrace)
{
  float v5; // xmm1_4
  float v6; // xmm2_4
  int contents; // ecx
  float v8; // xmm3_4
  bool v9; // zf
  float v10; // xmm0_4
  bool result; // al
  float y; // ecx
  float z; // edx
  float fractionleftsolid; // xmm0_4
  int hitgroup; // edx
  int hitbox; // eax
  __int16 physicsbone; // cx
  const char *name; // edx
  int v19; // eax
  CGameTrace hitboxTrace; // [esp+4h] [ebp-60h] BYREF
  Vector vecStartPos; // [esp+58h] [ebp-Ch]

  CM_ClearTrace(trace: &hitboxTrace);
  v5 = ray->m_StartOffset.y + ray->m_Start.y;
  v6 = ray->m_StartOffset.z + ray->m_Start.z;
  contents = pTrace->contents;
  v8 = ray->m_Delta.x + (float)(ray->m_Start.x + ray->m_StartOffset.x);
  hitboxTrace.startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
  hitboxTrace.endpos.y = ray->m_Delta.y + v5;
  v9 = !ray->m_IsRay;
  v10 = ray->m_Delta.z + v6;
  hitboxTrace.contents = contents;
  hitboxTrace.startpos.y = v5;
  hitboxTrace.startpos.z = v6;
  hitboxTrace.endpos.x = v8;
  hitboxTrace.endpos.z = v10;
  if ( v9 )
    return false;
  result = pCollideable->TestHitboxes(this: pCollideable, a2: ray, a3: fMask, a4: &hitboxTrace);
  if ( result )
  {
    if ( hitboxTrace.fraction >= 1.0 && !hitboxTrace.allsolid && !hitboxTrace.startsolid )
    {
      CM_ClearTrace(trace: pTrace);
      pTrace->startpos = hitboxTrace.startpos;
      pTrace->endpos = hitboxTrace.endpos;
      return true;
    }
    if ( pCollideable->GetSolid(this: pCollideable) == SOLID_VPHYSICS )
    {
      hitgroup = hitboxTrace.hitgroup;
      hitbox = hitboxTrace.hitbox;
      pTrace->contents = hitboxTrace.contents;
      physicsbone = hitboxTrace.physicsbone;
      pTrace->hitgroup = hitgroup;
      name = hitboxTrace.surface.name;
      pTrace->hitbox = hitbox;
      v19 = *(_DWORD *)&hitboxTrace.surface.surfaceProps;
      pTrace->physicsbone = physicsbone;
      pTrace->surface.name = name;
      *(_DWORD *)&pTrace->surface.surfaceProps = v19;
    }
    else
    {
      y = pTrace->startpos.y;
      z = pTrace->startpos.z;
      fractionleftsolid = pTrace->fractionleftsolid;
      vecStartPos.x = pTrace->startpos.x;
      vecStartPos.y = y;
      vecStartPos.z = z;
      CGameTrace::operator=(this: pTrace, __that: &hitboxTrace);
      if ( hitboxTrace.startsolid )
      {
        pTrace->startpos = vecStartPos;
        pTrace->fractionleftsolid = fractionleftsolid;
        return true;
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101777D0
// Name: public: virtual void CEngineTrace::ClipRayToCollideable(struct Ray_t const __near &,unsigned int,class ICollideable __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineTrace::ClipRayToCollideable(
        CEngineTrace *this,
        const Ray_t *ray,
        unsigned int fMask,
        ICollideable *pEntity,
        CGameTrace *pTrace)
{
  const model_t *(__thiscall *GetCollisionModel)(ICollideable *); // edx
  int v9; // eax
  char v10; // al
  const matrix3x4_t *pOldTransform; // [esp+Ch] [ebp-Ch]
  studiohdr_t *pStudioHdr; // [esp+10h] [ebp-8h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  char bCustomPerformed_3; // [esp+23h] [ebp+Bh]
  const model_t *pModel; // [esp+28h] [ebp+10h]
  char pModel_3; // [esp+2Bh] [ebp+13h]
  char bIsStudioModel_3; // [esp+2Fh] [ebp+17h]

  CM_ClearTrace(trace: pTrace);
  pTrace->startpos.x = ray->m_StartOffset.x + ray->m_Start.x;
  pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
  pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
  GetCollisionModel = pEntity->GetCollisionModel;
  pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  v9 = (int)GetCollisionModel(this: pEntity);
  pModel = (const model_t *)v9;
  bIsStudioModel_3 = 0;
  pStudioHdr = nullptr;
  if ( v9 != 0 && *(_DWORD *)(v9 + 272) == 3 )
  {
    bIsStudioModel_3 = 1;
    pStudioHdr = (studiohdr_t *)modelloader->GetExtraData(this: modelloader, a2: v9);
    if ( (fMask & 0x40000000) == 0 && (fMask & pStudioHdr->contents) == 0 )
      return;
  }
  pOldTransform = ray->m_pWorldAxisTransform;
  if ( (pEntity->GetSolidFlags(this: pEntity) & 0x100) != 0 )
    ray->m_pWorldAxisTransform = pEntity->GetRootParentToWorldTransform(this: pEntity);
  bCustomPerformed_3 = 0;
  if ( pEntity->GetSolid(this: pEntity) == SOLID_CUSTOM )
    goto LABEL_12;
  if ( !ray->m_IsRay )
    goto LABEL_11;
  if ( (pEntity->GetSolidFlags(this: pEntity) & 1) != 0 )
  {
LABEL_12:
    pEntity->TestCollision(this: pEntity, a2: ray, a3: fMask, a4: pTrace);
    v10 = 1;
    bCustomPerformed_3 = 1;
    goto LABEL_18;
  }
  if ( !ray->m_IsRay )
  {
LABEL_11:
    if ( (pEntity->GetSolidFlags(this: pEntity) & 2) != 0 )
      goto LABEL_12;
  }
  v10 = CEngineTrace::ClipRayToVPhysics(this, ray, fMask, pEntity, pStudioHdr, pTrace);
  if ( v10 == 0
    && (pModel == nullptr
     || pModel->type != mod_brush
     || (v10 = CEngineTrace::ClipRayToBSP(this, ray, fMask, pEntity, pTrace)) == 0) )
  {
    v10 = CEngineTrace::ClipRayToOBB(this, ray, fMask, pEntity, pTrace);
  }
LABEL_18:
  pModel_3 = 0;
  if ( bIsStudioModel_3 != 0 && (fMask & 0x40000000) != 0 && bCustomPerformed_3 == 0 )
  {
    v10 = CEngineTrace::ClipRayToHitboxes(this, ray, fMask, pCollideable: pEntity, pTrace);
    if ( v10 == 0 )
    {
LABEL_24:
      CEngineTrace::ClipRayToBBox(
        this,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)ray,
        a4: (int)pTrace,
        ray,
        fMask,
        pEntity,
        pTrace);
      goto LABEL_25;
    }
    pModel_3 = 1;
  }
  if ( v10 == 0 )
    goto LABEL_24;
LABEL_25:
  if ( bIsStudioModel_3 != 0
    && pModel_3 == 0
    && (pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid)
    && (bCustomPerformed_3 == 0 || pTrace->surface.surfaceProps == 0) )
  {
    pTrace->contents = pStudioHdr->contents;
    pTrace->surface.name = "**studio**";
    pTrace->surface.flags = 0;
    pTrace->surface.surfaceProps = pStudioHdr->surfacepropLookup;
  }
  if ( pTrace->m_pEnt == nullptr && (pTrace->fraction < 1.0 || pTrace->allsolid || pTrace->startsolid) )
    this->SetTraceEntity(this, a2: pEntity, a3: pTrace);
  ray->m_pWorldAxisTransform = pOldTransform;
}

//------------------------------------------------------------------------------
// Address: 0x10177A20
// Name: public: virtual void CEngineTrace::TraceRayAgainstLeafAndEntityList(struct Ray_t const __near &,class ITraceListData __near *,unsigned int,class ITraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CEngineTrace::TraceRayAgainstLeafAndEntityList(
        CEngineTrace *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Ray_t *ray,
        ITraceListData *pTraceData,
        unsigned int fMask,
        ITraceFilter *pTraceFilter,
        CGameTrace *pTrace)
{
  ITraceFilter *v10; // ecx
  CGameTrace *v11; // edi
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool v14; // zf
  TraceType_t (__thiscall *GetTraceType)(ITraceFilter *); // eax
  int v16; // esi
  ITraceListData_vtbl *v17; // eax
  int v18; // edi
  float x; // esi
  int v20; // ecx
  ITraceListData_vtbl *v21; // edx
  int v22; // esi
  float v23; // edi
  _DWORD v25[3]; // [esp+3Ch] [ebp-F4h] BYREF
  _BYTE trace[168]; // [esp+48h] [ebp-E8h] OVERLAPPED BYREF
  float fraction; // [esp+F0h] [ebp-40h]
  void **v28; // [esp+F4h] [ebp-3Ch] BYREF
  float v29; // [esp+F8h] [ebp-38h] BYREF
  float flWorldFraction; // [esp+FCh] [ebp-34h]
  CTraceFilterHitAll traceFilter; // [esp+100h] [ebp-30h]
  Vector rayMaxs; // [esp+104h] [ebp-2Ch] BYREF
  Vector rayMins; // [esp+110h] [ebp-20h]
  ITraceListData *flTolerance; // [esp+11Ch] [ebp-14h]
  int propCount; // [esp+120h] [ebp-10h]
  int v36; // [esp+124h] [ebp-Ch] OVERLAPPED
  CTraceListData *traceData; // [esp+128h] [ebp-8h]
  CTraceListData *retaddr; // [esp+130h] [ebp+0h]

  v36 = a2;
  traceData = retaddr;
  LODWORD(rayMins.x) = this;
  if ( pTraceData != nullptr )
    flTolerance = pTraceData - 1;
  else
    flTolerance = nullptr;
  ComputeRayBounds(maxs: (Vector *)&v29, mins: &rayMaxs, ray);
  if ( *(float *)&flTolerance[333].__vftable < v29
    || rayMaxs.x < *(float *)&flTolerance[330].__vftable
    || *(float *)&flTolerance[334].__vftable < flWorldFraction
    || rayMaxs.y < *(float *)&flTolerance[331].__vftable
    || *(float *)&flTolerance[335].__vftable < *(float *)&traceFilter.__vftable
    || rayMaxs.z < *(float *)&flTolerance[332].__vftable )
  {
    ((void (__thiscall *)(CEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, void **, _DWORD, _DWORD, CTraceFilterHitAll_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->TraceRay)(
      a1: this,
      a2: ray,
      a3: fMask,
      a4: pTraceFilter,
      a5: pTrace,
      a6: a3,
      a7: a4,
      a8: v25[0],
      a9: v25[1],
      a10: v25[2],
      a11: *(_DWORD *)trace,
      a12: *(_DWORD *)&trace[4],
      a13: *(_DWORD *)&trace[8],
      a14: *(_DWORD *)&trace[12],
      a15: *(_DWORD *)&trace[16],
      a16: *(_DWORD *)&trace[20],
      a17: *(_DWORD *)&trace[24],
      a18: *(_DWORD *)&trace[28],
      a19: *(_DWORD *)&trace[32],
      a20: *(_DWORD *)&trace[36],
      a21: *(_DWORD *)&trace[40],
      a22: *(_DWORD *)&trace[44],
      a23: *(_DWORD *)&trace[48],
      a24: *(_DWORD *)&trace[52],
      a25: *(_DWORD *)&trace[56],
      a26: *(_DWORD *)&trace[60],
      a27: *(_DWORD *)&trace[64],
      a28: *(_DWORD *)&trace[68],
      a29: *(_DWORD *)&trace[72],
      a30: *(_DWORD *)&trace[76],
      a31: *(_DWORD *)&trace[80],
      a32: *(_DWORD *)&trace[84],
      a33: *(_DWORD *)&trace[88],
      a34: *(_DWORD *)&trace[92],
      a35: *(_DWORD *)&trace[96],
      a36: *(_DWORD *)&trace[100],
      a37: *(_DWORD *)&trace[104],
      a38: *(_DWORD *)&trace[108],
      a39: *(_DWORD *)&trace[112],
      a40: *(_DWORD *)&trace[116],
      a41: *(_DWORD *)&trace[120],
      a42: *(_DWORD *)&trace[124],
      a43: *(_DWORD *)&trace[128],
      a44: *(_DWORD *)&trace[132],
      a45: *(_DWORD *)&trace[136],
      a46: *(_DWORD *)&trace[140],
      a47: *(_DWORD *)&trace[144],
      a48: *(_DWORD *)&trace[148],
      a49: *(_DWORD *)&trace[152],
      a50: *(_DWORD *)&trace[156],
      a51: *(_DWORD *)&trace[160],
      a52: *(_DWORD *)&trace[164],
      a53: LODWORD(fraction),
      a54: v28,
      a55: LODWORD(v29),
      a56: LODWORD(flWorldFraction),
      a57: traceFilter.__vftable,
      a58: LODWORD(rayMaxs.x),
      a59: LODWORD(rayMaxs.y),
      a60: LODWORD(rayMaxs.z),
      a61: LODWORD(rayMins.x),
      a62: LODWORD(rayMins.y));
    return;
  }
  v10 = pTraceFilter;
  v28 = &CTraceFilterHitAll::`vftable';
  if ( pTraceFilter == nullptr )
  {
    pTraceFilter = (ITraceFilter *)&v28;
    v10 = (ITraceFilter *)&v28;
  }
  if ( ((int (__thiscall *)(ITraceFilter *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, float, void **, float, float, CTraceFilterHitAll_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, ITraceListData *))v10->GetTraceType)(
         a1: v10,
         a2: a3,
         a3: a4,
         a4: v25[0],
         a5: v25[1],
         a6: v25[2],
         a7: *(_DWORD *)trace,
         a8: *(_DWORD *)&trace[4],
         a9: *(_DWORD *)&trace[8],
         a10: *(_DWORD *)&trace[12],
         a11: *(_DWORD *)&trace[16],
         a12: *(_DWORD *)&trace[20],
         a13: *(_DWORD *)&trace[24],
         a14: *(_DWORD *)&trace[28],
         a15: *(_DWORD *)&trace[32],
         a16: *(_DWORD *)&trace[36],
         a17: *(_DWORD *)&trace[40],
         a18: *(_DWORD *)&trace[44],
         a19: *(_DWORD *)&trace[48],
         a20: *(_DWORD *)&trace[52],
         a21: *(_DWORD *)&trace[56],
         a22: *(_DWORD *)&trace[60],
         a23: *(_DWORD *)&trace[64],
         a24: *(_DWORD *)&trace[68],
         a25: *(_DWORD *)&trace[72],
         a26: *(_DWORD *)&trace[76],
         a27: *(_DWORD *)&trace[80],
         a28: *(_DWORD *)&trace[84],
         a29: *(_DWORD *)&trace[88],
         a30: *(_DWORD *)&trace[92],
         a31: *(_DWORD *)&trace[96],
         a32: *(_DWORD *)&trace[100],
         a33: *(_DWORD *)&trace[104],
         a34: *(_DWORD *)&trace[108],
         a35: *(_DWORD *)&trace[112],
         a36: *(_DWORD *)&trace[116],
         a37: *(_DWORD *)&trace[120],
         a38: *(_DWORD *)&trace[124],
         a39: *(_DWORD *)&trace[128],
         a40: *(_DWORD *)&trace[132],
         a41: *(_DWORD *)&trace[136],
         a42: *(_DWORD *)&trace[140],
         a43: *(_DWORD *)&trace[144],
         a44: *(_DWORD *)&trace[148],
         a45: *(_DWORD *)&trace[152],
         a46: *(_DWORD *)&trace[156],
         a47: *(_DWORD *)&trace[160],
         a48: *(_DWORD *)&trace[164],
         a49: COERCE_FLOAT(LODWORD(fraction)),
         a50: v28,
         a51: COERCE_FLOAT(LODWORD(v29)),
         a52: COERCE_FLOAT(LODWORD(flWorldFraction)),
         a53: traceFilter.__vftable,
         a54: LODWORD(rayMaxs.x),
         a55: LODWORD(rayMaxs.y),
         a56: LODWORD(rayMaxs.z),
         a57: LODWORD(rayMins.x),
         a58: LODWORD(rayMins.y),
         a59: LODWORD(rayMins.z),
         a60: flTolerance) == 2 )
  {
    CM_ClearTrace(trace: pTrace);
    pTrace->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    pTrace->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    pTrace->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    pTrace->endpos.x = ray->m_Delta.x + pTrace->startpos.x;
    pTrace->endpos.y = ray->m_Delta.y + pTrace->startpos.y;
    pTrace->endpos.z = ray->m_Delta.z + pTrace->startpos.z;
  }
  else
  {
    propCount = (int)this->GetWorldCollideable(this);
    CM_BoxTraceAgainstLeafList(ray, traceData: (const CTraceListData *)pTrace, nBrushMask: fMask, trace: pTrace);
    this->SetTraceEntity(this, a2: (ICollideable *)propCount, a3: pTrace);
    if ( pTrace->fraction == 0.0 || pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_WORLD_ONLY )
      return;
  }
  fraction = pTrace->fraction;
  *(Ray_t *)&trace[76] = *ray;
  if ( fraction == 0.0 )
  {
    v11 = pTrace;
    memset(&trace[92], 0, 12);
    pTrace->fractionleftsolid = 1.0;
    pTrace->fraction = 1.0;
  }
  else
  {
    *(float *)&trace[92] = (float)((float)(*(float *)&trace[92] * fraction) + *(float *)&trace[76])
                         - *(float *)&trace[76];
    v12 = (float)((float)(*(float *)&trace[96] * fraction) + *(float *)&trace[80]) - *(float *)&trace[80];
    v13 = (float)((float)(*(float *)&trace[100] * fraction) + *(float *)&trace[84]) - *(float *)&trace[84];
    pTrace->fractionleftsolid = pTrace->fractionleftsolid / fraction;
    *(float *)&trace[96] = v12;
    *(float *)&trace[100] = v13;
    pTrace->fraction = 1.0;
    v11 = pTrace;
  }
  v14 = pTraceFilter->GetTraceType(this: pTraceFilter) == TRACE_ENTITIES_ONLY;
  GetTraceType = pTraceFilter->GetTraceType;
  BYTE2(rayMins.z) = v14;
  HIBYTE(rayMins.z) = GetTraceType(this: pTraceFilter) == TRACE_EVERYTHING_FILTER_PROPS;
  if ( BYTE2(rayMins.z) == 0 )
  {
    v16 = 0;
    LODWORD(rayMins.y) = (ITraceListData)flTolerance[328].__vftable;
    for ( propCount = 0; v16 < SLODWORD(rayMins.y); propCount = ++v16 )
    {
      if ( v11->allsolid )
        break;
      v17 = flTolerance[196].__vftable;
      v18 = *((_DWORD *)&v17->Reset + 2 * v16);
      if ( HIBYTE(rayMins.z) == 0
        || pTraceFilter->ShouldHitEntity(
             this: pTraceFilter,
             a2: *((IHandleEntity **)&v17->dtr_ITraceListData + 2 * v16),
             a3: fMask) != 0 )
      {
        (*(void (__thiscall **)(int, float *, Vector *))(*(_DWORD *)v18 + 60))(a1: v18, a2: &v29, a3: &rayMaxs);
        if ( IsBoxIntersectingRay(
               vecBoxMin: (const Vector *)&v29,
               vecBoxMax: &rayMaxs,
               ray: (const Ray_t *)&trace[76],
               flTolerance: 0.03125) )
        {
          x = rayMins.x;
          (*(void (__thiscall **)(_DWORD, _BYTE *, unsigned int, int, _DWORD *))(*(_DWORD *)LODWORD(rayMins.x) + 16))(
            a1: LODWORD(rayMins.x),
            a2: &trace[76],
            a3: fMask,
            a4: v18,
            a5: v25);
          CEngineTrace::ClipTraceToTrace(
            this: (CEngineTrace *)LODWORD(x),
            clipTrace: (CGameTrace *)v25,
            pFinalTrace: pTrace);
          v16 = propCount;
        }
      }
      v11 = pTrace;
    }
  }
  v20 = 0;
  LODWORD(rayMins.y) = (ITraceListData)flTolerance[194].__vftable;
  for ( propCount = 0; v20 < SLODWORD(rayMins.y); propCount = v20 )
  {
    if ( v11->allsolid )
      break;
    v21 = flTolerance[62].__vftable;
    v22 = *((_DWORD *)&v21->Reset + 2 * v20);
    if ( pTraceFilter->ShouldHitEntity(
           this: pTraceFilter,
           a2: *((IHandleEntity **)&v21->dtr_ITraceListData + 2 * v20),
           a3: fMask) != 0 )
    {
      (*(void (__thiscall **)(int, float *, Vector *))(*(_DWORD *)v22 + 60))(a1: v22, a2: &v29, a3: &rayMaxs);
      if ( IsBoxIntersectingRay(
             vecBoxMin: (const Vector *)&v29,
             vecBoxMax: &rayMaxs,
             ray: (const Ray_t *)&trace[76],
             flTolerance: 0.03125) )
      {
        v23 = rayMins.x;
        (*(void (__thiscall **)(_DWORD, _BYTE *, unsigned int, int, _DWORD *))(*(_DWORD *)LODWORD(rayMins.x) + 16))(
          a1: LODWORD(rayMins.x),
          a2: &trace[76],
          a3: fMask,
          a4: v22,
          a5: v25);
        CEngineTrace::ClipTraceToTrace(
          this: (CEngineTrace *)LODWORD(v23),
          clipTrace: (CGameTrace *)v25,
          pFinalTrace: pTrace);
      }
    }
    v11 = pTrace;
    v20 = propCount + 1;
  }
  v11->fraction = v11->fraction * fraction;
  v11->fractionleftsolid = v11->fractionleftsolid * fraction;
  if ( !ray->m_IsRay )
  {
    v11->startpos.x = ray->m_Start.x + ray->m_StartOffset.x;
    v11->startpos.y = ray->m_StartOffset.y + ray->m_Start.y;
    v11->startpos.z = ray->m_StartOffset.z + ray->m_Start.z;
    v11->fractionleftsolid = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10178080
// Name: public: CTraceListData::CTraceListData(void)
// Source: json
//------------------------------------------------------------------------------
CTraceListData *__thiscall CTraceListData::CTraceListData(CTraceListData *this)
{
  this->ITraceListData::__vftable = (ITraceListData_vtbl *)&ITraceListData::`vftable';
  this->IPartitionEnumerator::__vftable = (CTraceListData_vtbl *)&CTraceListData::`vftable'{for `IPartitionEnumerator'};
  this->ITraceListData::__vftable = (ITraceListData_vtbl *)&CTraceListData::`vftable'{for `ITraceListData'};
  this->m_brushList.m_Memory.m_nAllocationCount = 64;
  this->m_brushList.m_Memory.m_nMallocGrowSize = 0;
  this->m_brushList.m_Size = 0;
  this->m_brushList.m_Memory.m_pMemory = this->m_brushList.m_Memory.m_pFixedMemory;
  this->m_brushList.m_pElements = this->m_brushList.m_Memory.m_pFixedMemory;
  this->m_brushList.m_Memory.m_nGrowSize = -1;
  this->m_dispList.m_Memory.m_nGrowSize = -1;
  this->m_dispList.m_Memory.m_nAllocationCount = 32;
  this->m_dispList.m_Memory.m_nMallocGrowSize = 0;
  this->m_dispList.m_Size = 0;
  this->m_dispList.m_Memory.m_pMemory = this->m_dispList.m_Memory.m_pFixedMemory;
  this->m_dispList.m_pElements = this->m_dispList.m_Memory.m_pFixedMemory;
  this->m_entityList.m_Memory.m_nGrowSize = -1;
  this->m_entityList.m_Memory.m_nAllocationCount = 64;
  this->m_entityList.m_Memory.m_nMallocGrowSize = 0;
  this->m_entityList.m_Size = 0;
  this->m_entityList.m_Memory.m_pMemory = this->m_entityList.m_Memory.m_pFixedMemory;
  this->m_entityList.m_pElements = this->m_entityList.m_Memory.m_pFixedMemory;
  this->m_staticPropList.m_Memory.m_nGrowSize = -1;
  this->m_staticPropList.m_Memory.m_nAllocationCount = 64;
  this->m_staticPropList.m_Memory.m_nMallocGrowSize = 0;
  this->m_staticPropList.m_Size = 0;
  this->m_staticPropList.m_Memory.m_pMemory = this->m_staticPropList.m_Memory.m_pFixedMemory;
  this->m_staticPropList.m_pElements = this->m_staticPropList.m_Memory.m_pFixedMemory;
  this->m_pEngineTrace = nullptr;
  this->m_bFoundNonSolidLeaf = false;
  this->m_mins.x = 0.0;
  this->m_mins.y = 0.0;
  this->m_mins.z = 0.0;
  this->m_maxs.x = 0.0;
  this->m_maxs.y = 0.0;
  this->m_maxs.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10178190
// Name: public: virtual bool CTraceListData::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceListData::IsEmpty(CTraceListData *this)
{
  return LODWORD(this->m_maxs.z) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101781B0
// Name: public: virtual void CTraceListData::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceListData::Reset(CTraceListData *this)
{
  *(_DWORD *)&this->m_brushList.m_Memory.m_pFixedMemory[62] = 0;
  *(_DWORD *)&this->m_dispList.m_Memory.m_pFixedMemory[30] = 0;
  this->m_entityList.m_Memory.m_pFixedMemory[63].pCollideable = nullptr;
  this->m_staticPropList.m_Memory.m_pFixedMemory[63].pCollideable = nullptr;
  this->m_staticPropList.m_pElements = nullptr;
  this->m_mins.x = 0.0;
  this->m_mins.y = 0.0;
  this->m_mins.z = 0.0;
  this->m_maxs.x = 0.0;
  this->m_maxs.y = 0.0;
  this->m_maxs.z = 0.0;
  LOBYTE(this->m_pEngineTrace) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10178270
// Name: public: virtual class ITraceListData __near * CEngineTrace::AllocTraceListData(void)
// Source: json
//------------------------------------------------------------------------------
ITraceListData *__thiscall CEngineTrace::AllocTraceListData(CEngineTrace *this)
{
  CTraceListData *v1; // eax
  CTraceListData *v2; // eax

  v1 = (CTraceListData *)MemAlloc_Alloc(nSize: 0x548u);
  if ( v1 != nullptr && (v2 = CTraceListData::CTraceListData(this: v1)) != nullptr )
    return &v2->ITraceListData;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101782A0
// Name: public: virtual enum IterationRetval_t CTraceListData::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CTraceListData::EnumElement(CTraceListData *this, IHandleEntity *pHandleEntity)
{
  ICollideable *v4; // esi
  const char *v5; // eax
  CStaticPropMgr *v7; // eax
  int v8; // eax
  int v9; // eax
  char pHandleEntitya; // [esp+14h] [ebp+8h]

  v4 = this->m_pEngineTrace->HandleEntityToCollideable(this: this->m_pEngineTrace, a2: pHandleEntity);
  pHandleEntitya = v4->GetSolidFlags(this: v4);
  if ( v4->GetSolid(this: v4) != SOLID_NONE && (pHandleEntitya & 4) == 0 )
  {
    v7 = StaticPropMgr();
    if ( v7->IsStaticProp_2(this: v7, a2: pHandleEntity) )
    {
      v8 = CUtlVector<collideable_handleentity_t,CUtlMemoryFixedGrowable<collideable_handleentity_t,64,int>>::InsertBefore(
             this: &this->m_staticPropList,
             elem: this->m_staticPropList.m_Size);
      this->m_staticPropList.m_Memory.m_pMemory[v8].pCollideable = v4;
      this->m_staticPropList.m_Memory.m_pMemory[v8].pEntity = pHandleEntity;
    }
    else
    {
      v9 = CUtlVector<collideable_handleentity_t,CUtlMemoryFixedGrowable<collideable_handleentity_t,64,int>>::InsertBefore(
             this: &this->m_entityList,
             elem: this->m_entityList.m_Size);
      this->m_entityList.m_Memory.m_pMemory[v9].pCollideable = v4;
      this->m_entityList.m_Memory.m_pMemory[v9].pEntity = pHandleEntity;
    }
    return ITERATION_CONTINUE;
  }
  else
  {
    v5 = this->m_pEngineTrace->GetDebugName(this: this->m_pEngineTrace, a2: pHandleEntity);
    _Msg(a1: "%s in solid list (not solid)\n", v5);
    return ITERATION_CONTINUE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DF4F0
// Name: public: virtual enum TraceType_t CTraceFilter::GetTraceType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTraceFilter::GetTraceType(vgui::CTreeViewListControl *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10325320
// Name: _CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEngineTrace::TraceRay_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10325330
// Name: _dynamic_atexit_destructor_for__path_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__path_command__()
{
  ConCommand::~ConCommand(this: &path_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325340
// Name: _dynamic_atexit_destructor_for__fs_printopenfiles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_printopenfiles_command__()
{
  ConCommand::~ConCommand(this: &fs_printopenfiles_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325350
// Name: _dynamic_atexit_destructor_for__fs_warning_level_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_warning_level_command__()
{
  ConCommand::~ConCommand(this: &fs_warning_level_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325360
// Name: _dynamic_atexit_destructor_for__fs_syncdvddevcache_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_syncdvddevcache_command__()
{
  ConCommand::~ConCommand(this: &fs_syncdvddevcache_command);
}

} // namespace engine_xlsp
