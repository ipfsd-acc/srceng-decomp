// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_collide.cpp
// Functions: 93
// ============================================================

#include "vphysics\physics_collide.h"

//------------------------------------------------------------------------------
// Address: 0x10006830
// Name: class IVP_SurfaceManager __near * CreateSurfaceManager(class CPhysCollide const __near *,short __near &)
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceManager *__cdecl CreateSurfaceManager(const CPhysCollide *pCollisionModel, __int16 *collideType)
{
  if ( pCollisionModel != nullptr )
    return pCollisionModel->CreateSurfaceManager(this: pCollisionModel, a2: collideType);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006850
// Name: void OutputCollideDebugInfo(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OutputCollideDebugInfo(const CPhysCollide *pCollisionModel)
{
  pCollisionModel->OutputDebugInfo(this: pCollisionModel);
}

//------------------------------------------------------------------------------
// Address: 0x10006860
// Name: private: void CPhysCollideCompactSurface::SetLedgeIndex(class IVP_Compact_Ledgetree_Node const __near *,class IVP_Compact_Ledge __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::SetLedgeIndex(
        CPhysCollideCompactSurface *this,
        const IVP_Compact_Ledgetree_Node *pNode,
        IVP_Compact_Ledge *pLedge,
        int nIndex)
{
  while ( pNode->offset_right_node != 0 )
  {
    CPhysCollideCompactSurface::SetLedgeIndex(this, pNode: pNode + 1, pLedge, nIndex);
    pNode = (const IVP_Compact_Ledgetree_Node *)((char *)pNode + pNode->offset_right_node);
  }
  if ( (IVP_Compact_Ledge *)((char *)pNode + pNode->offset_compact_ledge) == pLedge )
    pNode->nLedgeIndex = nIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100068A0
// Name: public: virtual int CPhysCollideCompactSurface::GetVCollideIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollideCompactSurface::GetVCollideIndex(CPhysCollideCompactSurface *this)
{
  return this->m_pCompactSurface->dummy[0];
}

//------------------------------------------------------------------------------
// Address: 0x100068D0
// Name: public: virtual class CPhysCollideAABBTree const __near * CPhysCollideCompactSurface::GetAABBTree(void)const
// Source: json
//------------------------------------------------------------------------------
const CPhysCollideAABBTree *__thiscall CPhysCollideCompactSurface::GetAABBTree(CPhysCollideCompactSurface *this)
{
  return this->m_pAABBTree;
}

//------------------------------------------------------------------------------
// Address: 0x100068E0
// Name: public: virtual void CPhysCollideCompactSurface::GetAllLedges(class IVP_U_BigVector<class IVP_Compact_Ledge> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::GetAllLedges(
        IVP_SurfaceManager_Polygon *this,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  IVP_Compact_Ledge_Solver::get_all_ledges(surface: this->compact_surface, all_ledges_out: resulting_ledges);
}

//------------------------------------------------------------------------------
// Address: 0x10006900
// Name: public: virtual unsigned int CPhysCollideCompactSurface::GetSerializationSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollideCompactSurface::GetSerializationSize(CPhysCollideCompactSurface *this)
{
  return (*((int *)this->m_pCompactSurface + 7) >> 8) + 28;
}

//------------------------------------------------------------------------------
// Address: 0x10006910
// Name: public: virtual class Vector CPhysCollideCompactSurface::GetOrthographicAreas(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysCollideCompactSurface::GetOrthographicAreas(CPhysCollideCompactSurface *this, Vector *result)
{
  __int64 v2; // xmm0_8
  float z; // ecx

  v2 = *(_QWORD *)&this->m_orthoAreas.x;
  z = this->m_orthoAreas.z;
  *(_QWORD *)&result->x = v2;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: private: void CPhysCollideCompactSurface::ComputeHullInfo_r(struct CPhysCollideCompactSurface::hullinfo_t __near *,class IVP_Compact_Ledgetree_Node const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::ComputeHullInfo_r(
        CPhysCollideCompactSurface *this,
        CPhysCollideCompactSurface::hullinfo_t *pOut,
        const IVP_Compact_Ledgetree_Node *node)
{
  int offset_compact_ledge; // eax

  while ( node->offset_right_node != 0 )
  {
    offset_compact_ledge = node->offset_compact_ledge;
    if ( offset_compact_ledge != 0
      && (const IVP_Compact_Ledgetree_Node *)((char *)node + offset_compact_ledge) != nullptr )
    {
      pOut->hasOuterHull = true;
    }
    CPhysCollideCompactSurface::ComputeHullInfo_r(this, pOut, node: node + 1);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + node->offset_right_node);
  }
  ++pOut->convexCount;
}

//------------------------------------------------------------------------------
// Address: 0x10006970
// Name: public: virtual void CPhysCollideCompactSurface::OutputDebugInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::OutputDebugInfo(CPhysCollideCompactSurface *this)
{
  IVP_Compact_Surface *m_pCompactSurface; // eax
  const IVP_Compact_Ledgetree_Node *v3; // edx
  int offset_compact_ledge; // eax
  _DWORD *v5; // edx
  const char *v6; // eax
  CPhysCollideCompactSurface::hullinfo_t info; // [esp+4h] [ebp-8h] BYREF

  m_pCompactSurface = this->m_pCompactSurface;
  info.hasOuterHull = false;
  info.convexCount = 0;
  v3 = (const IVP_Compact_Ledgetree_Node *)((char *)m_pCompactSurface + m_pCompactSurface->offset_ledgetree_root);
  if ( v3->offset_right_node == 0 )
  {
    info.convexCount = 1;
LABEL_5:
    v6 = "no";
    goto LABEL_6;
  }
  offset_compact_ledge = v3->offset_compact_ledge;
  if ( offset_compact_ledge != 0 )
    info.hasOuterHull = (const IVP_Compact_Ledgetree_Node *)((char *)v3 + offset_compact_ledge) != nullptr;
  CPhysCollideCompactSurface::ComputeHullInfo_r(this, pOut: &info, node: v3 + 1);
  CPhysCollideCompactSurface::ComputeHullInfo_r(
    this,
    pOut: &info,
    node: (const IVP_Compact_Ledgetree_Node *)((char *)v5 + *v5));
  v6 = "with";
  if ( !info.hasOuterHull )
    goto LABEL_5;
LABEL_6:
  _Msg(a1: "CollisionModel: Compact Surface: %d convex pieces %s outer hull\n", info.convexCount, v6);
}

//------------------------------------------------------------------------------
// Address: 0x100069F0
// Name: public: virtual void CPhysicsCollision::ConvexFree(class CPhysConvex __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::ConvexFree(CPhysicsCollision *this, void **pConvex)
{
  if ( pConvex != nullptr )
    ivp_free_aligned(data: pConvex);
}

//------------------------------------------------------------------------------
// Address: 0x10006A10
// Name: public: virtual int CPhysicsCollision::CollideSize(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysicsCollision::CollideSize(CPhysicsCollision *this, CPhysCollide *pCollide)
{
  return pCollide->GetSerializationSize(this: pCollide);
}

//------------------------------------------------------------------------------
// Address: 0x10006A30
// Name: public: virtual int CPhysicsCollision::CollideWrite(char __near *,class CPhysCollide __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysicsCollision::CollideWrite(
        CPhysicsCollision *this,
        char *pDest,
        CPhysCollide *pCollide,
        BOOL bSwap)
{
  return pCollide->SerializeToBuffer(this: pCollide, a2: pDest, a3: bSwap);
}

//------------------------------------------------------------------------------
// Address: 0x10006A50
// Name: public: virtual void CPhysicsCollision::DestroyDebugMesh(int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::DestroyDebugMesh(CPhysicsCollision *this, int vertCount, Vector *outVerts)
{
  free(data: outVerts);
}

//------------------------------------------------------------------------------
// Address: 0x10006A70
// Name: public: virtual void CPhysicsCollision::SetConvexGameData(class CPhysConvex __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::SetConvexGameData(
        CPhysicsCollision *this,
        CPhysConvex *pConvex,
        unsigned int gameData)
{
  if ( (*((_BYTE *)pConvex + 8) & 3) == 0 )
    *((_DWORD *)pConvex + 1) = gameData;
}

//------------------------------------------------------------------------------
// Address: 0x10006A90
// Name: public: virtual void CPhysicsCollision::TraceBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPhysicsCollision::TraceBox(
        CPhysicsCollision *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        CGameTrace *ptr)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CPhysicsTrace::SweepBoxIVP(
    this: &this->m_traceapi,
    a2: (int)&savedregs,
    start,
    end,
    mins,
    maxs,
    pCollide,
    surfaceOrigin: collideOrigin,
    surfaceAngles: collideAngles,
    ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006AA0
// Name: public: virtual void CPhysicsCollision::TraceBox(struct Ray_t const __near &,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::TraceBox(
        CPhysicsCollision *this,
        const Ray_t *ray,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        CGameTrace *ptr)
{
  this->TraceBox(this, a2: ray, a3: -1u, a4: nullptr, a5: pCollide, a6: collideOrigin, a7: collideAngles, a8: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006AD0
// Name: public: virtual bool CPhysicsCollision::TraceBoxAA(struct Ray_t const __near &,class CPhysCollide const __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsCollision::TraceBoxAA(
        CPhysicsCollision *this,
        const Ray_t *ray,
        const CPhysCollide *pCollide,
        CGameTrace *ptr)
{
  const CPhysCollideAABBTree *v5; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v5 = pCollide->GetAABBTree(this: pCollide);
  if ( v5 != nullptr )
    return CPhysicsTrace::SweepBoxAxisAlignedIVP(
             this: &this->m_traceapi,
             a2: (int)&savedregs,
             raySrc: ray,
             pSurface: pCollide,
             pTree: v5,
             ptr);
  CPhysicsTrace::SweepBoxIVP(
    this: &this->m_traceapi,
    a2: COERCE_FLOAT(&savedregs),
    raySrc: ray,
    contentsMask: 0xFFFFFFFF,
    pConvexInfo: nullptr,
    pCollide,
    surfaceOrigin: &vec3_origin,
    surfaceAngles: &vec3_angle,
    ptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006B30
// Name: public: virtual void CPhysicsCollision::TraceBox(struct Ray_t const __near &,unsigned int,class IConvexInfo __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPhysicsCollision::TraceBox(
        CPhysicsCollision *this,
        const Ray_t *ray,
        unsigned int contentsMask,
        IConvexInfo *pConvexInfo,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        CGameTrace *ptr)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CPhysicsTrace::SweepBoxIVP(
    this: &this->m_traceapi,
    a2: COERCE_FLOAT(&savedregs),
    raySrc: ray,
    contentsMask,
    pConvexInfo,
    pCollide,
    surfaceOrigin: collideOrigin,
    surfaceAngles: collideAngles,
    ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006B40
// Name: public: virtual void CPhysicsCollision::TraceCollide(class Vector const __near &,class Vector const __near &,class CPhysCollide const __near *,class QAngle const __near &,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsCollision::TraceCollide(
        CPhysicsCollision *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *start,
        const Vector *end,
        const CPhysCollide *pSweepCollide,
        const QAngle *sweepAngles,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        CGameTrace *ptr)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CPhysicsTrace::SweepIVP(
    this: &this->m_traceapi,
    a2: (int)&savedregs,
    a3: a2,
    a4: a3,
    start,
    end,
    pSweptSurface: pSweepCollide,
    sweptAngles: sweepAngles,
    pSurface: pCollide,
    surfaceOrigin: collideOrigin,
    surfaceAngles: collideAngles,
    ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006B50
// Name: public: virtual void CPhysicsCollision::CollideGetAABB(class Vector __near *,class Vector __near *,class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsCollision::CollideGetAABB(
        CPhysicsCollision *this@<ecx>,
        int a2@<edi>,
        Vector *pMins,
        Vector *pMaxs,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CPhysicsTrace::GetAABB(
    this: &this->m_traceapi,
    a2: COERCE_FLOAT(&savedregs),
    a3: a2,
    pMins,
    pMaxs,
    pCollide,
    collideOrigin,
    collideAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10006B60
// Name: public: virtual float CPhysicsCollision::CollideGetRadius(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CPhysicsCollision::CollideGetRadius(CPhysicsCollision *this, const CPhysCollide *pCollide)
{
  return pCollide->GetSphereRadius(this: pCollide);
}

//------------------------------------------------------------------------------
// Address: 0x10006B80
// Name: public: virtual class Vector CPhysicsCollision::CollideGetExtent(class CPhysCollide const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__userpurge CPhysicsCollision::CollideGetExtent@<eax>(
        CPhysicsCollision *this@<ecx>,
        int a2@<edi>,
        Vector *result,
        const CPhysCollide *pCollide,
        const Vector *collideOrigin,
        const QAngle *collideAngles,
        const Vector *direction)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( pCollide != nullptr )
    CPhysicsTrace::GetExtent(
      this: &this->m_traceapi,
      a2: COERCE_FLOAT(&savedregs),
      a3: a2,
      result,
      pCollide,
      collideOrigin,
      collideAngles,
      direction);
  else
    *result = *collideOrigin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006BD0
// Name: public: virtual bool CPhysicsCollision::IsBoxIntersectingCone(class Vector const __near &,class Vector const __near &,struct truncatedcone_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __thiscall CPhysicsCollision::IsBoxIntersectingCone(
        CPhysicsCollision *this,
        const Vector *boxAbsMins,
        const Vector *boxAbsMaxs,
        const truncatedcone_t *cone)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  return CPhysicsTrace::IsBoxIntersectingCone(
           this: &this->m_traceapi,
           a2: COERCE_FLOAT(&savedregs),
           boxAbsMins,
           boxAbsMaxs,
           cone);
}

//------------------------------------------------------------------------------
// Address: 0x10006BE0
// Name: public: virtual void CPhysicsCollision::VCollideUnload(struct vcollide_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::VCollideUnload(CPhysicsCollision *this, vcollide_t *pVCollide)
{
  int v2; // edi
  CPhysCollide *v3; // ecx

  this->VCollideFreeUserData(this, a2: pVCollide);
  v2 = 0;
  if ( (*(_WORD *)pVCollide & 0x7FFF) != 0 )
  {
    do
    {
      v3 = pVCollide->solids[v2];
      if ( v3 != nullptr )
        ((void (__thiscall *)(CPhysCollide *, int))v3->dtr_IPhysCollide)(a1: v3, a2: 1);
      ++v2;
    }
    while ( v2 < (*(_WORD *)pVCollide & 0x7FFF) );
  }
  free(data: pVCollide->solids);
  free(data: pVCollide->pKeyValues);
  *(_QWORD *)pVCollide = 0;
  *(_QWORD *)&pVCollide->pKeyValues = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006C50
// Name: public: virtual void __near * CPhysicsCollision::VCollideAllocUserData(struct vcollide_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CPhysicsCollision::VCollideAllocUserData(
        CPhysicsCollision *this,
        vcollide_t *pVCollide,
        unsigned int userDataSize)
{
  if ( pVCollide->pUserData != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pVCollide->pUserData);
    pVCollide->pUserData = nullptr;
  }
  if ( userDataSize != 0 )
    pVCollide->pUserData = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: userDataSize);
  return pVCollide->pUserData;
}

//------------------------------------------------------------------------------
// Address: 0x10006CA0
// Name: public: virtual void CPhysicsCollision::VCollideFreeUserData(struct vcollide_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::VCollideFreeUserData(CPhysicsCollision *this, vcollide_t *pVCollide)
{
  if ( pVCollide->pUserData != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pVCollide->pUserData);
  pVCollide->pUserData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006CD0
// Name: public: virtual void CPhysicsCollision::VCollideCheck(struct vcollide_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::VCollideCheck(CPhysicsCollision *this, vcollide_t *pVCollide, const char *pName)
{
  int v3; // edi
  CPhysCollide *v4; // ecx
  const collidemap_t *v5; // eax
  int leafCount; // edx
  int v7; // esi
  unsigned __int8 *p_flags; // eax
  int v9; // ecx

  v3 = 0;
  if ( (*(_WORD *)pVCollide & 0x7FFF) != 0 )
  {
    do
    {
      v4 = pVCollide->solids[v3];
      v5 = v4->GetCollideMap(this: v4);
      if ( v5 == nullptr )
        goto LABEL_9;
      leafCount = v5->leafCount;
      v7 = 0;
      if ( v5->leafCount > 0 )
      {
        p_flags = &v5->leafmap[0].flags;
        v9 = leafCount;
        do
        {
          if ( (*p_flags & 6) != 0 )
            ++v7;
          p_flags += 24;
          --v9;
        }
        while ( v9 != 0 );
      }
      if ( v7 != leafCount )
LABEL_9:
        _Warning(a1: "PERFORMANCE (%s): Collision model will not support the fastest tracing code\n", pName);
      ++v3;
    }
    while ( v3 < (*(_WORD *)pVCollide & 0x7FFF) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D50
// Name: public: virtual class IVPhysicsKeyParser __near * CPhysicsCollision::VPhysicsKeyParserCreate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVPhysicsKeyParser *__thiscall CPhysicsCollision::VPhysicsKeyParserCreate(
        CPhysicsCollision *this,
        const char *pKeyData)
{
  return CreateVPhysicsKeyParser(pKeyData, bIsPacked: false);
}

//------------------------------------------------------------------------------
// Address: 0x10006D70
// Name: public: virtual class IVPhysicsKeyParser __near * CPhysicsCollision::VPhysicsKeyParserCreate(struct vcollide_t __near *)
// Source: json
//------------------------------------------------------------------------------
IVPhysicsKeyParser *__thiscall CPhysicsCollision::VPhysicsKeyParserCreate(
        CPhysicsCollision *this,
        vcollide_t *pVCollide)
{
  return CreateVPhysicsKeyParser(pKeyData: pVCollide->pKeyValues, bIsPacked: *(_WORD *)pVCollide < 0);
}

//------------------------------------------------------------------------------
// Address: 0x10006DA0
// Name: public: virtual void CPhysicsCollision::VPhysicsKeyParserDestroy(class IVPhysicsKeyParser __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::VPhysicsKeyParserDestroy(CPhysicsCollision *this, IPhysicsFrictionSnapshot *pParser)
{
  DestroyPlayerController(pSnapshot: pParser);
}

//------------------------------------------------------------------------------
// Address: 0x10006DC0
// Name: public: virtual class IPhysicsCollision __near * CPhysicsCollision::ThreadContextCreate(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsCollision *__thiscall CPhysicsCollision::ThreadContextCreate(CPhysicsCollision *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006DE0
// Name: public: virtual void CPhysicsCollision::CollideGetMassCenter(class CPhysCollide __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::CollideGetMassCenter(
        CPhysicsCollision *this,
        CPhysCollide *pCollide,
        Vector *pOutMassCenter)
{
  _BYTE v3[12]; // [esp+0h] [ebp-Ch] BYREF

  *pOutMassCenter = *pCollide->GetMassCenter(this: pCollide, result: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10006E10
// Name: public: virtual void CPhysicsCollision::CollideSetMassCenter(class CPhysCollide __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::CollideSetMassCenter(
        CPhysicsCollision *this,
        CPhysCollide *pCollide,
        const Vector *massCenter)
{
  pCollide->SetMassCenter(this: pCollide, a2: massCenter);
}

//------------------------------------------------------------------------------
// Address: 0x10006E30
// Name: public: virtual int CPhysicsCollision::CollideIndex(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsCollision::CollideIndex(CPhysicsCollision *this, const CPhysCollide *pCollide)
{
  if ( pCollide != nullptr )
    return pCollide->GetVCollideIndex(this: pCollide);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006E50
// Name: public: virtual class Vector CPhysicsCollision::CollideGetOrthographicAreas(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsCollision::CollideGetOrthographicAreas(
        CPhysicsCollision *this,
        Vector *result,
        const CPhysCollide *pCollide)
{
  if ( pCollide != nullptr )
    pCollide->GetOrthographicAreas(this: pCollide, result);
  else
    *result = vec3_origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006E90
// Name: public: virtual void CPhysicsCollision::CollideSetOrthographicAreas(class CPhysCollide __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::CollideSetOrthographicAreas(
        CPhysicsCollision *this,
        CPhysCollide *pCollide,
        const Vector *areas)
{
  if ( pCollide != nullptr )
    pCollide->SetOrthographicAreas(this: pCollide, a2: areas);
}

//------------------------------------------------------------------------------
// Address: 0x10006EB0
// Name: public: virtual void CPhysicsCollision::OutputDebugInfo(class CPhysCollide const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::OutputDebugInfo(CPhysicsCollision *this, const CPhysCollide *pCollide)
{
  pCollide->OutputDebugInfo(this: pCollide);
}

//------------------------------------------------------------------------------
// Address: 0x10006F60
// Name: public: virtual float CPhysCollideCompactSurface::GetSphereRadius(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysCollideCompactSurface::GetSphereRadius(CPhysCollideCompactSurface *this)
{
  return this->m_pCompactSurface->upper_limit_radius * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10006FD0
// Name: public: virtual class IVP_SurfaceManager __near * CPhysCollideCompactSurface::CreateSurfaceManager(short __near &)const
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceManager *__thiscall CPhysCollideCompactSurface::CreateSurfaceManager(
        CPhysCollideCompactSurface *this,
        __int16 *collideType)
{
  IVP_SurfaceManager *result; // eax
  IVP_SurfaceManager_vtbl *m_pCompactSurface; // ecx

  *collideType = 0;
  result = (IVP_SurfaceManager *)p_malloc(size: 8u);
  if ( result == nullptr )
    return nullptr;
  m_pCompactSurface = (IVP_SurfaceManager_vtbl *)this->m_pCompactSurface;
  result->__vftable = (IVP_SurfaceManager_vtbl *)&IVP_SurfaceManager_Polygon::`vftable';
  result[1].__vftable = m_pCompactSurface;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007010
// Name: public: virtual class Vector CPhysCollideCompactSurface::GetMassCenter(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysCollideCompactSurface::GetMassCenter(CPhysCollideCompactSurface *this, Vector *result)
{
  IVP_Compact_Surface *m_pCompactSurface; // ecx
  float unitScaleMetersInv; // xmm0_4

  m_pCompactSurface = this->m_pCompactSurface;
  unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(result->z) = COERCE_UNSIGNED_INT(m_pCompactSurface->mass_center.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                     ^ _mask__NegFloat_;
  result->y = m_pCompactSurface->mass_center.k[2] * unitScaleMetersInv;
  result->x = m_pCompactSurface->mass_center.k[0] * unitScaleMetersInv;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007060
// Name: public: virtual void CPhysCollideCompactSurface::SetMassCenter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::SetMassCenter(CPhysCollideCompactSurface *this, const Vector *massCenterHL)
{
  IVP_Compact_Surface *m_pCompactSurface; // eax
  float y; // xmm0_4

  m_pCompactSurface = this->m_pCompactSurface;
  y = massCenterHL->y;
  m_pCompactSurface->mass_center.k[0] = massCenterHL->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(m_pCompactSurface->mass_center.k[1]) = COERCE_UNSIGNED_INT(massCenterHL->z * g_PhysicsUnits.unitScaleMeters)
                                               ^ _mask__NegFloat_;
  m_pCompactSurface->mass_center.k[2] = g_PhysicsUnits.unitScaleMeters * y;
}

//------------------------------------------------------------------------------
// Address: 0x100070B0
// Name: public: virtual void CPhysCollideCompactSurface::SetOrthographicAreas(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::SetOrthographicAreas(CPhysCollideCompactSurface *this, const Vector *areas)
{
  this->m_orthoAreas = *areas;
}

//------------------------------------------------------------------------------
// Address: 0x100070D0
// Name: public: virtual class CPhysConvex __near * CPhysicsCollision::ConvexFromPlanes(float __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__userpurge CPhysicsCollision::ConvexFromPlanes@<eax>(
        CPhysicsCollision *this@<ecx>,
        int a2@<ebp>,
        float *pPlanes,
        int planeCount,
        float mergeDistance)
{
  int v5; // edi
  float pointmerge_threshold; // xmm0_4
  float *v7; // esi
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  IVP_Compact_Ledge *v11; // esi
  float v13[3]; // [esp+14h] [ebp-2Ch] BYREF
  IVP_U_Hesse plane; // [esp+20h] [ebp-20h] BYREF
  int v15; // [esp+34h] [ebp-Ch]
  IVP_Halfspacesoup halfspaces; // [esp+38h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h]
  float mergeDistancea; // [esp+4Ch] [ebp+Ch]

  v15 = a2;
  *(_DWORD *)&halfspaces.memsize = retaddr;
  IVP_Halfspacesoup::IVP_Halfspacesoup(this: (IVP_Halfspacesoup *)&plane.hesse_val);
  v5 = planeCount;
  pointmerge_threshold = g_PhysicsUnits.unitScaleMeters * mergeDistance;
  mergeDistancea = g_PhysicsUnits.unitScaleMeters * mergeDistance;
  if ( planeCount > 0 )
  {
    v7 = pPlanes + 2;
    do
    {
      v8 = *(v7 - 2);
      v9 = *(v7 - 1);
      v13[1] = -(float)-*v7;
      v10 = -v7[1];
      v13[0] = -v8;
      v13[2] = -v9;
      plane.k[0] = -(float)(v10 * g_PhysicsUnits.unitScaleMeters);
      IVP_Halfspacesoup::add_halfspace(this: (IVP_Halfspacesoup *)&plane.hesse_val, plane: (const IVP_U_Hesse *)v13);
      v7 += 4;
      --v5;
    }
    while ( v5 != 0 );
    pointmerge_threshold = mergeDistancea;
  }
  v11 = IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_compact_ledge(
          halfspaces: (IVP_Halfspacesoup *)&plane.hesse_val,
          pointmerge_threshold);
  IVP_Halfspacesoup::~IVP_Halfspacesoup(this: (IVP_Halfspacesoup *)&plane.hesse_val);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x100071A0
// Name: public: virtual class CPolyhedron __near * CPhysicsCollision::PolyhedronFromConvex(class CPhysConvex __near * const,bool)
// Source: json
//------------------------------------------------------------------------------
CPolyhedron *__thiscall CPhysicsCollision::PolyhedronFromConvex(
        CPhysicsCollision *this,
        CPhysConvex *const pConvex,
        bool bUseTempPolyhedron)
{
  int v3; // esi
  void *v4; // esp
  _DWORD *v5; // edi
  int *v6; // eax
  int i; // ebx
  int v8; // ecx
  int *v9; // edx
  int v10; // ecx
  int v11; // ecx
  int j; // esi
  int v13; // edi
  void *v14; // esp
  _DWORD *v15; // ebx
  PolyhedronMesh_Triangle *v16; // ecx
  int k; // edi
  int m; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  PolyhedronMesh_Triangle *v22; // eax
  int n; // edx
  int ii; // ecx
  void *v25; // esp
  int v26; // eax
  PolyhedronMesh_Triangle *v27; // ecx
  int jj; // edi
  PolyhedronMesh_Triangle *v29; // ebx
  BOOL v30; // edx
  int v31; // eax
  CPolyhedron_AllocByNew *TempPolyhedron; // eax
  _DWORD *v33; // edi
  int v34; // edx
  float *v35; // eax
  int v36; // ecx
  float v37; // xmm0_4
  float *p_x; // ecx
  int v39; // ebx
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  void *v43; // esp
  int v44; // esi
  int v45; // edx
  int v46; // eax
  unsigned __int16 *v47; // ecx
  char *p_y; // eax
  PolyhedronMesh_Triangle *v49; // esi
  int v50; // eax
  float *v51; // ecx
  float v52; // xmm3_4
  float v53; // xmm4_4
  float v54; // xmm5_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  PolyhedronMesh_Triangle *v58; // ecx
  int v59; // edx
  int v60; // ebx
  int v61; // eax
  unsigned __int16 *v62; // esi
  int v63; // esi
  bool v64; // zf
  unsigned __int16 v66; // [esp-8h] [ebp-34h]
  Vector *v67; // [esp-4h] [ebp-30h]
  _DWORD v68[2]; // [esp+0h] [ebp-2Ch] BYREF
  int v69; // [esp+8h] [ebp-24h] BYREF
  int iLow; // [esp+Ch] [ebp-20h]
  int v71; // [esp+10h] [ebp-1Ch]
  PolyhedronMesh_Triangle *pTriangles; // [esp+14h] [ebp-18h]
  int iNumPoints; // [esp+18h] [ebp-14h]
  int iTriangles; // [esp+1Ch] [ebp-10h]
  int iHighestPointIndex; // [esp+20h] [ebp-Ch]
  int iLinkCount; // [esp+24h] [ebp-8h]
  int iInsertIndex; // [esp+28h] [ebp-4h]
  Vector *pWriteVertices; // [esp+38h] [ebp+Ch]
  Vector *pWriteVerticesa; // [esp+38h] [ebp+Ch]
  Vector *pWriteVerticesb; // [esp+38h] [ebp+Ch]

  v3 = *((__int16 *)pConvex + 6);
  iTriangles = v3;
  v4 = alloca(24 * v3);
  pTriangles = (PolyhedronMesh_Triangle *)v68;
  iHighestPointIndex = 0;
  if ( v3 != 0 )
  {
    v5 = (_DWORD *)((char *)pConvex + 24);
    v6 = &v69;
    for ( i = v3; i != 0; --i )
    {
      v8 = (unsigned __int16)v5[1];
      *(v6 - 2) = v8;
      v6[3] = v8;
      v9 = v6 - 2;
      v10 = (unsigned __int16)*v5;
      *v6 = v10;
      *(v6 - 1) = v10;
      v11 = (unsigned __int16)*(v5 - 1);
      v6[2] = v11;
      v6[1] = v11;
      for ( j = 3; j != 0; --j )
      {
        if ( *v9 > iHighestPointIndex )
          iHighestPointIndex = *v9;
        v9 += 2;
      }
      v5 += 4;
      v6 += 6;
    }
    v3 = iTriangles;
  }
  v13 = 4 * ++iHighestPointIndex;
  v14 = alloca(v13);
  v15 = v68;
  iLow = (int)v68;
  memset(dst: (unsigned __int8 *)v68, value: 0, count: v13);
  if ( v3 != 0 )
  {
    v16 = pTriangles;
    for ( k = v3; k != 0; --k )
    {
      for ( m = 3; m != 0; --m )
      {
        ++v68[v16->Edges[0].iPointIndices[0]];
        v16 = (PolyhedronMesh_Triangle *)((char *)v16 + 8);
      }
    }
  }
  v19 = iHighestPointIndex;
  v20 = 0;
  v21 = 0;
  iInsertIndex = 0;
  if ( iHighestPointIndex != 0 )
  {
    do
    {
      if ( v68[v21] != 0 )
        v68[v21] = v20++;
      else
        v68[v21] = -1;
      ++v21;
    }
    while ( v21 != v19 );
    iInsertIndex = v20;
  }
  iNumPoints = v20;
  if ( v3 != 0 )
  {
    v22 = pTriangles;
    do
    {
      for ( n = 3; n != 0; --n )
      {
        for ( ii = 2; ii != 0; --ii )
        {
          v22->Edges[0].iPointIndices[0] = v68[v22->Edges[0].iPointIndices[0]];
          v22 = (PolyhedronMesh_Triangle *)((char *)v22 + 4);
        }
      }
      --v3;
    }
    while ( v3 != 0 );
  }
  v25 = alloca(iInsertIndex * iInsertIndex);
  memset(dst: (unsigned __int8 *)v68, value: 0, count: iInsertIndex * iInsertIndex);
  v26 = 0;
  if ( iTriangles != 0 )
  {
    v27 = pTriangles;
    v71 = iTriangles;
    iLinkCount = 3 * iTriangles;
    do
    {
      for ( jj = 3; jj != 0; --jj )
      {
        v29 = v27;
        v30 = v27->Edges[0].iPointIndices[0] > v27->Edges[0].iPointIndices[1];
        v27 = (PolyhedronMesh_Triangle *)((char *)v27 + 8);
        *((_BYTE *)v68 + v29->Edges[0].iPointIndices[-v30 + 1] + iInsertIndex * v27->Edges[-1].iPointIndices[v30]) = 1;
      }
      --v71;
    }
    while ( v71 != 0 );
    v26 = iLinkCount;
    v15 = (_DWORD *)iLow;
  }
  v31 = v26 / 2;
  v66 = 2 * v31;
  iLinkCount = v31;
  if ( bUseTempPolyhedron )
    TempPolyhedron = (CPolyhedron_AllocByNew *)GetTempPolyhedron(
                                                 iVertices: iInsertIndex,
                                                 iLines: v31,
                                                 iIndices: v66,
                                                 iPolygons: iTriangles);
  else
    TempPolyhedron = CPolyhedron_AllocByNew::Allocate(
                       iVertices: iInsertIndex,
                       iLines: v31,
                       iIndices: v66,
                       iPolygons: iTriangles);
  v33 = &TempPolyhedron->__vftable;
  v34 = 0;
  pWriteVertices = TempPolyhedron->pVertices;
  if ( iHighestPointIndex != 0 )
  {
    v35 = (float *)((char *)pConvex + *(_DWORD *)pConvex + 4);
    do
    {
      v36 = v15[v34];
      if ( v36 != -1 )
      {
        v37 = v35[1] * g_PhysicsUnits.unitScaleMetersInv;
        p_x = &pWriteVertices[v36].x;
        v15 = (_DWORD *)iLow;
        p_x[2] = -(float)(*v35 * g_PhysicsUnits.unitScaleMetersInv);
        p_x[1] = v37;
        *p_x = *(v35 - 1) * g_PhysicsUnits.unitScaleMetersInv;
      }
      ++v34;
      v35 += 4;
    }
    while ( v34 != iHighestPointIndex );
  }
  v39 = iNumPoints;
  v40 = 0;
  v41 = 0;
  if ( iNumPoints != 0 )
  {
    pWriteVerticesa = (Vector *)v68;
    do
    {
      v39 = iNumPoints;
      v42 = v41 + 1;
      if ( v41 + 1 != iNumPoints )
      {
        do
        {
          if ( *((_BYTE *)&pWriteVerticesa->x + v42) != 0 )
          {
            *(_WORD *)(v33[2] + 4 * v40) = v41;
            *(_WORD *)(v33[2] + 4 * v40++ + 2) = v42;
          }
          ++v42;
        }
        while ( v42 != v39 );
        v42 = v41 + 1;
      }
      pWriteVerticesa = (Vector *)((char *)pWriteVerticesa + v39);
      v41 = v42;
    }
    while ( v42 != v39 );
  }
  v43 = alloca(4 * v39);
  v44 = 1;
  v68[0] = 0;
  v45 = 1;
  if ( v39 != 1 )
  {
    do
    {
      v46 = v44;
      if ( v44 != iLinkCount )
      {
        v47 = (unsigned __int16 *)(v33[2] + 4 * v44);
        while ( *v47 != v45 )
        {
          ++v46;
          v47 += 2;
          if ( v46 == iLinkCount )
            goto LABEL_56;
        }
        v68[v45] = v46;
        v44 = v46 + 1;
      }
LABEL_56:
      ++v45;
    }
    while ( v45 != iNumPoints );
  }
  p_y = nullptr;
  iInsertIndex = 0;
  if ( iTriangles != 0 )
  {
    v49 = pTriangles;
    pWriteVerticesb = nullptr;
    pTriangles = (PolyhedronMesh_Triangle *)iTriangles;
    do
    {
      *(_WORD *)&p_y[v33[4]] = iInsertIndex;
      *(_WORD *)&p_y[v33[4] + 2] = 3;
      v50 = v33[1];
      v51 = (float *)(v50 + 12 * v49->Edges[0].iPointIndices[0]);
      v52 = *(float *)(v50 + 12 * v49->Edges[1].iPointIndices[0]) - *v51;
      v53 = *(float *)(v50 + 12 * v49->Edges[1].iPointIndices[0] + 4) - v51[1];
      v54 = *(float *)(v50 + 12 * v49->Edges[1].iPointIndices[0] + 8) - v51[2];
      v55 = *(float *)(v50 + 12 * v49->Edges[2].iPointIndices[0] + 8) - v51[2];
      v56 = *(float *)(v50 + 12 * v49->Edges[2].iPointIndices[0]) - *v51;
      v57 = *(float *)(v50 + 12 * v49->Edges[2].iPointIndices[0] + 4) - v51[1];
      v67 = (Vector *)((char *)&pWriteVerticesb->y + v33[4]);
      v67->x = (float)(v57 * v54) - (float)(v55 * v53);
      v67->y = (float)(v55 * v52) - (float)(v56 * v54);
      v67->z = (float)(v56 * v53) - (float)(v57 * v52);
      VectorNormalize(vec: v67);
      v58 = v49;
      v71 = 3;
      do
      {
        v59 = v58->Edges[0].iPointIndices[0] > v58->Edges[0].iPointIndices[1];
        v60 = v58->Edges[0].iPointIndices[v59];
        iNumPoints = 4 * v59;
        v61 = v68[v60];
        iLow = v59;
        iTriangles = v60;
        if ( v61 != iLinkCount )
        {
          v62 = (unsigned __int16 *)(v33[2] + 4 * v61);
          do
          {
            if ( *v62 == v60 )
            {
              if ( v62[1] == *(int *)((char *)&v58->Edges[0].iPointIndices[1] - iNumPoints) )
                break;
              v60 = iTriangles;
            }
            ++v61;
            v62 += 2;
          }
          while ( v61 != iLinkCount );
          LOBYTE(v59) = iLow;
        }
        v63 = iInsertIndex;
        *(_WORD *)(v33[3] + 4 * iInsertIndex) = v61;
        *(_BYTE *)(v33[3] + 4 * v63 + 2) = 1 - v59;
        v58 = (PolyhedronMesh_Triangle *)((char *)v58 + 8);
        v64 = v71-- == 1;
        iInsertIndex = v63 + 1;
      }
      while ( !v64 );
      p_y = (char *)&pWriteVerticesb[1].y;
      v64 = pTriangles == (PolyhedronMesh_Triangle *)1;
      pTriangles = (PolyhedronMesh_Triangle *)((char *)pTriangles - 1);
      pWriteVerticesb = (Vector *)((char *)pWriteVerticesb + 16);
      v49 = v58;
    }
    while ( !v64 );
  }
  return (CPolyhedron *)v33;
}

//------------------------------------------------------------------------------
// Address: 0x10007610
// Name: public: virtual void CPhysicsCollision::ConvexesFromConvexPolygon(class Vector const __near &,class Vector const __near *,int,class CPhysConvex __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::ConvexesFromConvexPolygon(
        CPhysicsCollision *this,
        const Vector *vPolyNormal,
        const Vector *pPoints,
        int iPointCount,
        CPhysConvex **pOutput)
{
  void *v5; // esp
  void *v6; // esp
  float *v7; // eax
  float *p_z; // ecx
  int i; // esi
  float v10; // xmm0_4
  float *v11; // ebx
  float *v12; // esi
  int v13; // edi
  float hesse_val; // ecx
  IVP_U_Point **v15; // eax
  IVP_U_Point *v16; // edx
  IVP_U_Point **v17; // ebx
  IVP_U_Point *v18; // edx
  IVP_U_Point **v19; // eax
  IVP_U_Point *v20; // edx
  IVP_U_Point *v21; // ecx
  IVP_U_Point *v22; // [esp-4h] [ebp-14h]
  IVP_U_Point v23; // [esp+0h] [ebp-10h] BYREF
  int v24; // [esp+1Ch] [ebp+Ch]
  CPhysConvex **v25; // [esp+20h] [ebp+10h]
  _DWORD *v26; // [esp+20h] [ebp+10h]
  int v27; // [esp+24h] [ebp+14h]

  v5 = alloca(16 * iPointCount);
  LODWORD(v23.hesse_val) = &v23;
  v6 = alloca(4 * iPointCount);
  if ( iPointCount != 0 )
  {
    v7 = &v23.k[2];
    p_z = &pPoints->z;
    for ( i = iPointCount; i != 0; --i )
    {
      v10 = *(p_z - 1);
      *(v7 - 2) = *(p_z - 2) * g_PhysicsUnits.unitScaleMeters;
      *(v7 - 1) = -(float)(*p_z * g_PhysicsUnits.unitScaleMeters);
      *v7 = g_PhysicsUnits.unitScaleMeters * v10;
      v7 += 4;
      p_z += 3;
    }
  }
  LODWORD(v23.k[0]) = &v23;
  v11 = &v23.k[1];
  LODWORD(v23.k[1]) = LODWORD(v23.hesse_val) + 16 * (iPointCount - 1);
  LODWORD(v23.k[2]) = LODWORD(v23.hesse_val) + 16;
  v12 = &v23.k[2];
  v13 = iPointCount - 2;
  v24 = 2;
  *pOutput = (CPhysConvex *)IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge(
                              p0: &v23,
                              p1: (IVP_U_Point *)LODWORD(v23.k[1]),
                              p2: (IVP_U_Point *)(LODWORD(v23.hesse_val) + 16));
  if ( iPointCount - 2 >= 2 )
  {
    v25 = pOutput + 1;
    v27 = LODWORD(v23.hesse_val) + 32;
    LODWORD(hesse_val) = LODWORD(v23.hesse_val) + 16 * v13;
    while ( 1 )
    {
      v12[1] = hesse_val;
      v15 = (IVP_U_Point **)v11;
      v16 = *((IVP_U_Point **)v11 + 2);
      v17 = (IVP_U_Point **)(v11 + 1);
      v22 = v16;
      v18 = *v15;
      LODWORD(v23.hesse_val) = LODWORD(hesse_val) - 16;
      --v13;
      *v25 = (CPhysConvex *)IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge(p0: v18, p1: *v17, p2: v22);
      v26 = v25 + 1;
      if ( v24 > v13 )
        break;
      ++v24;
      *((_DWORD *)v12 + 2) = v27;
      v12 += 2;
      v19 = v17;
      v20 = v17[1];
      v27 += 16;
      v21 = v17[2];
      v11 = (float *)(v17 + 1);
      *v26 = IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge(p0: *v19, p1: v20, p2: v21);
      v25 = (CPhysConvex **)(v26 + 1);
      if ( v24 > v13 )
        break;
      hesse_val = v23.hesse_val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007780
// Name: public: virtual float CPhysicsCollision::ConvexVolume(class CPhysConvex __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsCollision::ConvexVolume(CPhysicsCollision *this, CPhysConvex *pConvex)
{
  int v3; // ebx
  int v4; // eax
  float unitScaleMetersInv; // xmm0_4
  float v6; // xmm3_4
  _DWORD *v7; // edi
  int v8; // ecx
  int v9; // eax
  float v10; // xmm3_4
  float v11; // xmm1_4
  int v12; // eax
  int v13; // eax
  float v14; // xmm3_4
  float v15; // xmm1_4
  int v16; // eax
  float v17; // xmm3_4
  double result; // st7
  Vector points[3]; // [esp+0h] [ebp-30h] BYREF
  Vector vert; // [esp+24h] [ebp-Ch] BYREF
  float volume; // [esp+38h] [ebp+8h]

  v3 = *((__int16 *)pConvex + 6);
  v4 = *(_DWORD *)pConvex + 16 * (unsigned __int16)*((_DWORD *)pConvex + 5);
  volume = 0.0;
  unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
  v6 = *(float *)((char *)pConvex + v4 + 4);
  vert.y = *(float *)((char *)pConvex + v4 + 8) * g_PhysicsUnits.unitScaleMetersInv;
  vert.z = -(float)(v6 * g_PhysicsUnits.unitScaleMetersInv);
  vert.x = *(float *)((char *)pConvex + v4) * g_PhysicsUnits.unitScaleMetersInv;
  if ( v3 <= 0 )
    return 0.0;
  v7 = (_DWORD *)((char *)pConvex + 24);
  while ( 1 )
  {
    v8 = *(_DWORD *)pConvex;
    v9 = *(_DWORD *)pConvex + 16 * (unsigned __int16)*(v7 - 1);
    v10 = *(float *)((char *)pConvex + v9 + 4);
    points[0].y = *(float *)((char *)pConvex + v9 + 8) * unitScaleMetersInv;
    points[0].z = -(float)(v10 * unitScaleMetersInv);
    v11 = *(float *)((char *)pConvex + v9);
    v12 = (unsigned __int16)*v7;
    points[0].x = v11 * unitScaleMetersInv;
    v13 = v8 + 16 * v12;
    v14 = *(float *)((char *)pConvex + v13 + 4);
    points[1].y = *(float *)((char *)pConvex + v13 + 8) * unitScaleMetersInv;
    points[1].z = -(float)(v14 * unitScaleMetersInv);
    v15 = *(float *)((char *)pConvex + v13);
    v16 = v8 + 16 * (unsigned __int16)v7[1];
    points[1].x = v15 * unitScaleMetersInv;
    v17 = *(float *)((char *)pConvex + v16 + 4);
    points[2].y = *(float *)((char *)pConvex + v16 + 8) * unitScaleMetersInv;
    points[2].z = -(float)(v17 * unitScaleMetersInv);
    points[2].x = *(float *)((char *)pConvex + v16) * unitScaleMetersInv;
    result = TetrahedronVolume(p0: &vert, p1: points, p2: &points[1], p3: &points[2]) + volume;
    v7 += 4;
    --v3;
    volume = result;
    if ( v3 == 0 )
      break;
    unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007900
// Name: public: virtual float CPhysicsCollision::ConvexSurfaceArea(class CPhysConvex __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsCollision::ConvexSurfaceArea(CPhysicsCollision *this, CPhysConvex *pConvex)
{
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ecx
  int v6; // eax
  float v7; // xmm3_4
  float v8; // xmm1_4
  int v9; // eax
  int v10; // eax
  float v11; // xmm3_4
  float v12; // xmm1_4
  int v13; // eax
  int v14; // eax
  float v15; // xmm3_4
  double result; // st7
  Vector points[3]; // [esp+0h] [ebp-24h] BYREF
  float area; // [esp+2Ch] [ebp+8h]

  v3 = *((__int16 *)pConvex + 6);
  area = 0.0;
  if ( v3 <= 0 )
    return 0.0;
  v4 = (_DWORD *)((char *)pConvex + 24);
  do
  {
    v5 = *(_DWORD *)pConvex;
    v6 = *(_DWORD *)pConvex + 16 * (unsigned __int16)*(v4 - 1);
    v7 = *(float *)((char *)pConvex + v6 + 4);
    points[0].y = *(float *)((char *)pConvex + v6 + 8) * g_PhysicsUnits.unitScaleMetersInv;
    points[0].z = -(float)(v7 * g_PhysicsUnits.unitScaleMetersInv);
    v8 = *(float *)((char *)pConvex + v6);
    v9 = (unsigned __int16)*v4;
    points[0].x = v8 * g_PhysicsUnits.unitScaleMetersInv;
    v10 = v5 + 16 * v9;
    v11 = *(float *)((char *)pConvex + v10 + 4);
    points[1].y = *(float *)((char *)pConvex + v10 + 8) * g_PhysicsUnits.unitScaleMetersInv;
    points[1].z = -(float)(v11 * g_PhysicsUnits.unitScaleMetersInv);
    v12 = *(float *)((char *)pConvex + v10);
    v13 = (unsigned __int16)v4[1];
    points[1].x = v12 * g_PhysicsUnits.unitScaleMetersInv;
    v14 = v5 + 16 * v13;
    v15 = *(float *)((char *)pConvex + v14 + 4);
    points[2].y = *(float *)((char *)pConvex + v14 + 8) * g_PhysicsUnits.unitScaleMetersInv;
    points[2].z = -(float)(v15 * g_PhysicsUnits.unitScaleMetersInv);
    points[2].x = *(float *)((char *)pConvex + v14) * g_PhysicsUnits.unitScaleMetersInv;
    result = TriangleArea(v0: points, v1: &points[1], v2: &points[2]) + area;
    v4 += 4;
    --v3;
    area = result;
  }
  while ( v3 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007A30
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::ConvertConvexToCollide(class CPhysConvex __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__thiscall CPhysicsCollision::ConvertConvexToCollide(
        CPhysicsCollision *this,
        CPhysConvex **pConvex,
        int convexCount)
{
  CPhysCollide *(__thiscall *ConvertConvexToCollideParams)(struct CPhysicsCollision *, CPhysConvex **, int, const convertconvexparams_t *); // eax
  convertconvexparams_t convertParams; // [esp+0h] [ebp-10h] BYREF

  *(_DWORD *)&convertParams.buildOuterConvexHull = 0;
  *(_WORD *)&convertParams.bUseFastApproximateInertiaTensor = 0;
  convertParams.pForcedOuterHull = nullptr;
  ConvertConvexToCollideParams = this->ConvertConvexToCollideParams;
  convertParams.dragAreaEpsilon = 0.25;
  return ConvertConvexToCollideParams(this, a2: pConvex, a3: convexCount, a4: &convertParams);
}

//------------------------------------------------------------------------------
// Address: 0x10007A70
// Name: InitBoxVerts
// Source: json
//------------------------------------------------------------------------------
void __usercall InitBoxVerts(
        Vector **ppVerts@<esi>,
        const Vector *mins@<ecx>,
        const Vector *maxs@<edx>,
        Vector *boxVerts)
{
  *boxVerts = *mins;
  if ( ppVerts != nullptr )
    *ppVerts = boxVerts;
  boxVerts[1].x = maxs->x;
  boxVerts[1].y = mins->y;
  boxVerts[1].z = mins->z;
  if ( ppVerts != nullptr )
    ppVerts[1] = boxVerts + 1;
  boxVerts[2].x = mins->x;
  boxVerts[2].y = maxs->y;
  boxVerts[2].z = mins->z;
  if ( ppVerts != nullptr )
    ppVerts[2] = boxVerts + 2;
  boxVerts[3].x = maxs->x;
  boxVerts[3].y = maxs->y;
  boxVerts[3].z = mins->z;
  if ( ppVerts != nullptr )
    ppVerts[3] = boxVerts + 3;
  boxVerts[4].x = mins->x;
  boxVerts[4].y = mins->y;
  boxVerts[4].z = maxs->z;
  if ( ppVerts != nullptr )
    ppVerts[4] = boxVerts + 4;
  boxVerts[5].x = maxs->x;
  boxVerts[5].y = mins->y;
  boxVerts[5].z = maxs->z;
  if ( ppVerts != nullptr )
    ppVerts[5] = boxVerts + 5;
  boxVerts[6].x = mins->x;
  boxVerts[6].y = maxs->y;
  boxVerts[6].z = maxs->z;
  if ( ppVerts != nullptr )
    ppVerts[6] = boxVerts + 6;
  boxVerts[7] = *maxs;
  if ( ppVerts != nullptr )
    ppVerts[7] = boxVerts + 7;
}

//------------------------------------------------------------------------------
// Address: 0x10007BB0
// Name: public: virtual void CPhysicsCollision::PolysoupAddTriangle(class CPhysPolysoup __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::PolysoupAddTriangle(
        CPhysicsCollision *this,
        CPhysPolysoup *pSoup,
        const Vector *a,
        const Vector *b,
        const Vector *c,
        int materialIndex7bits)
{
  float y; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  IVP_Compact_Ledge *v9; // eax

  pSoup->m_isValid = true;
  y = a->y;
  pSoup->m_triangle[0].k[0] = a->x * g_PhysicsUnits.unitScaleMeters;
  pSoup->m_triangle[0].k[1] = -(float)(g_PhysicsUnits.unitScaleMeters * a->z);
  pSoup->m_triangle[0].k[2] = g_PhysicsUnits.unitScaleMeters * y;
  v7 = b->y;
  pSoup->m_triangle[1].k[0] = b->x * g_PhysicsUnits.unitScaleMeters;
  pSoup->m_triangle[1].k[1] = -(float)(b->z * g_PhysicsUnits.unitScaleMeters);
  pSoup->m_triangle[1].k[2] = g_PhysicsUnits.unitScaleMeters * v7;
  v8 = c->y;
  pSoup->m_triangle[2].k[0] = c->x * g_PhysicsUnits.unitScaleMeters;
  pSoup->m_triangle[2].k[1] = -(float)(c->z * g_PhysicsUnits.unitScaleMeters);
  pSoup->m_triangle[2].k[2] = g_PhysicsUnits.unitScaleMeters * v8;
  v9 = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(points: &pSoup->m_points);
  if ( v9 != nullptr )
  {
    v9[1].c_point_offset ^= (v9[1].c_point_offset ^ (materialIndex7bits << 24)) & 0x7F000000;
    IVP_SurfaceBuilder_Ledge_Soup::insert_ledge(this: &pSoup->m_builderSoup, c_ledge: v9);
  }
  else
  {
    _Warning(a1: "Degenerate Triangle\n");
    _Warning(a1: "(%.2f, %.2f, %.2f), ", a->x, a->y, a->z);
    _Warning(a1: "(%.2f, %.2f, %.2f), ", b->x, b->y, b->z);
    _Warning(a1: "(%.2f, %.2f, %.2f)\n", c->x, c->y, c->z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007DA0
// Name: public: virtual int CCollisionQuery::TriangleCount(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionQuery::TriangleCount(CCollisionQuery *this, int convexIndex)
{
  __int16 *v2; // eax

  v2 = (__int16 *)this->m_ledges.elems[convexIndex];
  if ( v2 != nullptr )
    return v2[6];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007DC0
// Name: public: virtual unsigned int CCollisionQuery::GetGameData(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCollisionQuery::GetGameData(CCollisionQuery *this, int convexIndex)
{
  _DWORD *v2; // eax

  v2 = this->m_ledges.elems[convexIndex];
  if ( v2 != nullptr )
    return v2[1];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007DE0
// Name: public: virtual void CCollisionQuery::GetTriangleVerts(int,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionQuery::GetTriangleVerts(
        CCollisionQuery *this,
        int convexIndex,
        int triangleIndex,
        Vector *verts)
{
  int *v4; // edx
  int *v5; // esi
  int v6; // edi
  int v7; // eax
  float v8; // xmm2_4
  int v9; // eax
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm0_4

  v4 = (int *)this->m_ledges.elems[convexIndex];
  if ( v4 != nullptr )
    v5 = &v4[4 * triangleIndex + 4];
  else
    v5 = nullptr;
  v6 = *v4;
  v7 = *v4 + 16 * (unsigned __int16)v5[3];
  v8 = *(float *)((char *)v4 + v7 + 4) * g_PhysicsUnits.unitScaleMetersInv;
  verts->y = *(float *)((char *)v4 + v7 + 8) * g_PhysicsUnits.unitScaleMetersInv;
  verts->z = -v8;
  verts->x = *(float *)((char *)v4 + v7) * g_PhysicsUnits.unitScaleMetersInv;
  v9 = v6 + 16 * (unsigned __int16)v5[2];
  v10 = *(float *)((char *)v4 + v9 + 8) * g_PhysicsUnits.unitScaleMetersInv;
  verts[1].z = -(float)(*(float *)((char *)v4 + v9 + 4) * g_PhysicsUnits.unitScaleMetersInv);
  verts[1].y = v10;
  verts[1].x = *(float *)((char *)v4 + v9) * g_PhysicsUnits.unitScaleMetersInv;
  v11 = v6 + 16 * (unsigned __int16)v5[1];
  v12 = *(float *)((char *)v4 + v11 + 8) * g_PhysicsUnits.unitScaleMetersInv;
  verts[2].z = -(float)(*(float *)((char *)v4 + v11 + 4) * g_PhysicsUnits.unitScaleMetersInv);
  verts[2].y = v12;
  verts[2].x = *(float *)((char *)v4 + v11) * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10007EF0
// Name: public: virtual int CCollisionQuery::GetTriangleMaterialIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionQuery::GetTriangleMaterialIndex(CCollisionQuery *this, int convexIndex, int triangleIndex)
{
  _BYTE *v3; // ecx

  v3 = this->m_ledges.elems[convexIndex];
  if ( v3 != nullptr )
    return v3[16 * triangleIndex + 19] & 0x7F;
  else
    return MEMORY[3] & 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x10007F30
// Name: public: virtual void CCollisionQuery::SetTriangleMaterialIndex(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionQuery::SetTriangleMaterialIndex(
        CCollisionQuery *this,
        int convexIndex,
        int triangleIndex,
        int index7bits)
{
  _DWORD *v4; // ecx

  v4 = this->m_ledges.elems[convexIndex];
  if ( v4 != nullptr )
    v4[4 * triangleIndex + 4] ^= (v4[4 * triangleIndex + 4] ^ (index7bits << 24)) & 0x7F000000;
  else
    MEMORY[0] ^= (MEMORY[0] ^ (index7bits << 24)) & 0x7F000000;
}

//------------------------------------------------------------------------------
// Address: 0x10008030
// Name: private: void CPhysCollideCompactSurface::InitCollideMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::InitCollideMap(CPhysCollideCompactSurface *this)
{
  int v2; // ebx
  void (__thiscall *GetAllLedges)(struct CPhysCollideCompactSurface *, IVP_U_BigVector<IVP_Compact_Ledge> *); // edx
  collidemap_t *v4; // eax
  int n_elems; // ecx
  IVP_Compact_Ledge *v6; // edi
  const IVP_Compact_Ledgetree_Node *v7; // edx
  _DWORD *v8; // edx
  void **elems; // eax
  bool v10; // zf
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+8h] [ebp-10h] BYREF
  int v12; // [esp+14h] [ebp-4h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v2 = 0;
  this->m_pCollideMap = nullptr;
  if ( this->m_pCompactSurface != nullptr )
  {
    GetAllLedges = this->GetAllLedges;
    memset(&ledges, 0, sizeof(ledges));
    GetAllLedges(this, a2: &ledges);
    if ( ledges.n_elems != 0 && ledges.n_elems <= 64 )
    {
      v4 = (collidemap_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * ledges.n_elems + 4);
      n_elems = ledges.n_elems;
      this->m_pCollideMap = v4;
      v4->leafCount = n_elems;
      if ( ledges.n_elems > 0 )
      {
        v12 = 0;
        do
        {
          InitLeafmap(
            a1: (int)&savedregs,
            pLedge: (IVP_Compact_Ledge *)ledges.elems[v2],
            pLeafmapOut: (leafmap_t *)((char *)this->m_pCollideMap->leafmap + v12));
          v6 = (IVP_Compact_Ledge *)ledges.elems[v2];
          v7 = (const IVP_Compact_Ledgetree_Node *)((char *)this->m_pCompactSurface
                                                  + this->m_pCompactSurface->offset_ledgetree_root);
          if ( v7->offset_right_node != 0 )
          {
            CPhysCollideCompactSurface::SetLedgeIndex(this, pNode: v7 + 1, pLedge: v6, nIndex: v2);
            CPhysCollideCompactSurface::SetLedgeIndex(
              this,
              pNode: (const IVP_Compact_Ledgetree_Node *)((char *)v8 + *v8),
              pLedge: v6,
              nIndex: v2);
          }
          else if ( (IVP_Compact_Ledge *)((char *)v7 + v7->offset_compact_ledge) == v6 )
          {
            v7->nLedgeIndex = v2;
          }
          v12 += 24;
          ++v2;
        }
        while ( v2 < ledges.n_elems );
      }
      elems = ledges.elems;
      v10 = ledges.elems == (void **)&v12;
    }
    else
    {
      elems = ledges.elems;
      v10 = ledges.elems == (void **)&v12;
    }
    if ( !v10 && elems != nullptr )
      free(data: elems);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008130
// Name: public: CPhysCollideCompactSurface::CPhysCollideCompactSurface(char const __near *,unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__thiscall CPhysCollideCompactSurface::CPhysCollideCompactSurface(
        CPhysCollideCompactSurface *this,
        char *pBuffer,
        unsigned int size,
        int index,
        bool swap)
{
  IVP_Compact_Surface *v6; // eax

  this->__vftable = (CPhysCollideCompactSurface_vtbl *)&CPhysCollideCompactSurface::`vftable';
  v6 = (IVP_Compact_Surface *)ivp_malloc_aligned(size, alignment: 16);
  this->m_pCompactSurface = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pBuffer, count: size);
  if ( swap )
    IVP_Compact_Surface::byte_swap_all(this: this->m_pCompactSurface, swap_points: IVP_TRUE, point_estimate: 100);
  this->m_pCompactSurface->dummy[0] = index;
  this->m_orthoAreas.x = 1.0;
  this->m_orthoAreas.y = 1.0;
  this->m_orthoAreas.z = 1.0;
  CPhysCollideCompactSurface::InitCollideMap(this);
  this->m_pAABBTree = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100081B0
// Name: public: CPhysCollideCompactSurface::CPhysCollideCompactSurface(struct compactsurfaceheader_t const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__thiscall CPhysCollideCompactSurface::CPhysCollideCompactSurface(
        CPhysCollideCompactSurface *this,
        const compactsurfaceheader_t *pHeader,
        int index,
        bool swap)
{
  int surfaceSize; // ebx
  IVP_Compact_Surface *v6; // eax

  this->__vftable = (CPhysCollideCompactSurface_vtbl *)&CPhysCollideCompactSurface::`vftable';
  surfaceSize = pHeader->surfaceSize;
  v6 = (IVP_Compact_Surface *)ivp_malloc_aligned(size: surfaceSize, alignment: 16);
  this->m_pCompactSurface = v6;
  memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)&pHeader[1], count: surfaceSize);
  if ( swap )
    IVP_Compact_Surface::byte_swap_all(this: this->m_pCompactSurface, swap_points: IVP_TRUE, point_estimate: 100);
  this->m_pCompactSurface->dummy[0] = index;
  this->m_orthoAreas.x = 1.0;
  this->m_orthoAreas.y = 1.0;
  this->m_orthoAreas.z = 1.0;
  CPhysCollideCompactSurface::InitCollideMap(this);
  this->m_orthoAreas.x = pHeader->dragAxisAreas.x;
  this->m_pAABBTree = nullptr;
  this->m_orthoAreas.y = pHeader->dragAxisAreas.y;
  this->m_orthoAreas.z = pHeader->dragAxisAreas.z;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008240
// Name: public: virtual unsigned int CPhysCollideCompactSurface::SerializeToBuffer(char __near *,bool)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysCollideCompactSurface::SerializeToBuffer(
        CPhysCollideCompactSurface *this,
        compactsurfaceheader_t *pDest,
        bool bSwap)
{
  IVP_Compact_Surface *m_pCompactSurface; // edx
  float x; // xmm0_4
  int v6; // eax
  float z; // xmm0_4
  unsigned __int8 *v8; // edi
  unsigned int v9; // ebx
  compactsurfaceheader_t header; // [esp+8h] [ebp-20h] BYREF
  CByteswap swap; // [esp+24h] [ebp-4h] BYREF
  int serializationSize; // [esp+30h] [ebp+8h]

  m_pCompactSurface = this->m_pCompactSurface;
  x = this->m_orthoAreas.x;
  header.vphysicsID = 1497911382;
  *(_DWORD *)&header.version = 256;
  v6 = *((_DWORD *)m_pCompactSurface + 7);
  header.dragAxisAreas.x = x;
  header.dragAxisAreas.y = this->m_orthoAreas.y;
  z = this->m_orthoAreas.z;
  header.surfaceSize = v6 >> 8;
  header.dragAxisAreas.z = z;
  header.axisMapSize = 0;
  if ( bSwap )
  {
    swap = (CByteswap)(*(_DWORD *)&swap | 3);
    CByteswap::SwapFieldsToTargetEndian(
      this: &swap,
      pOutputBuffer: &header,
      pBaseData: &header,
      pDataMap: &compactsurfaceheader_t::m_DataMap);
  }
  *pDest = header;
  v8 = (unsigned __int8 *)&pDest[1];
  v9 = *((int *)this->m_pCompactSurface + 7) >> 8;
  serializationSize = this->GetSerializationSize(this);
  if ( bSwap )
    IVP_Compact_Surface::byte_swap_all(this: this->m_pCompactSurface, swap_points: IVP_TRUE, point_estimate: 100);
  memcpy(dst: v8, src: (unsigned __int8 *)this->m_pCompactSurface, count: v9);
  return serializationSize;
}

//------------------------------------------------------------------------------
// Address: 0x10008320
// Name: public: virtual void CPhysCollideCompactSurface::ComputeOrthographicAreas(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysCollideCompactSurface::ComputeOrthographicAreas(CPhysCollideCompactSurface *this, float epsilon)
{
  void (__thiscall *CollideGetAABB)(IPhysicsCollision *, Vector *, Vector *, const CPhysCollide *, const Vector *, const QAngle *); // eax
  float v4; // xmm3_4
  float v5; // xmm4_4
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // ebx
  float v12; // xmm5_4
  float v13; // xmm0_4
  IPhysicsCollision *v14; // ecx
  bool v15; // cc
  float v16; // xmm0_4
  Vector *v17; // eax
  int v18; // ecx
  bool v19; // zf
  CPhysCollideCompactSurface *v20; // [esp-10h] [ebp-C4h]
  CGameTrace tr; // [esp+Ch] [ebp-A8h] BYREF
  Vector end; // [esp+60h] [ebp-54h] BYREF
  Vector start; // [esp+6Ch] [ebp-48h] BYREF
  Vector mins; // [esp+78h] [ebp-3Ch] BYREF
  Vector maxs; // [esp+84h] [ebp-30h] BYREF
  CPhysCollideCompactSurface *v26; // [esp+90h] [ebp-24h]
  float halfSide; // [esp+94h] [ebp-20h]
  float side; // [esp+98h] [ebp-1Ch]
  float v0; // [esp+9Ch] [ebp-18h]
  int v30; // [esp+A0h] [ebp-14h]
  Vector *p_m_orthoAreas; // [esp+A4h] [ebp-10h]
  int v32; // [esp+A8h] [ebp-Ch]
  int hits; // [esp+ACh] [ebp-8h]
  float u0; // [esp+B0h] [ebp-4h]
  int total; // [esp+BCh] [ebp+8h]

  CollideGetAABB = physcollision->CollideGetAABB;
  v26 = this;
  CollideGetAABB(this: physcollision, a2: &mins, a3: &maxs, a4: this, a5: &vec3_origin, a6: &vec3_angle);
  v4 = fsqrt(epsilon);
  side = v4;
  if ( v4 < 0.000099999997 )
  {
    v4 = 0.000099999997;
    side = 0.000099999997;
  }
  v5 = v4 * 0.5;
  v6 = 2;
  this->m_orthoAreas.x = 1.0;
  this->m_orthoAreas.y = 1.0;
  this->m_orthoAreas.z = 1.0;
  halfSide = v4 * 0.5;
  v30 = 2;
  p_m_orthoAreas = &this->m_orthoAreas;
  v7 = 0;
  v32 = 3;
  do
  {
    v8 = (v6 - 1) % 3;
    v9 = *(&maxs.x + v8);
    v10 = *(&mins.x + v8) + v5;
    hits = 0;
    total = 0;
    u0 = v10;
    v11 = v6 % 3;
    if ( v9 <= v10 )
      goto LABEL_14;
    do
    {
      v12 = *(&maxs.x + v11);
      v13 = *(&mins.x + v11) + v5;
      v0 = v13;
      if ( v12 > v13 )
      {
        do
        {
          v14 = physcollision;
          v20 = v26;
          *(float *)((char *)&start.x + v7) = *(float *)((char *)&mins.x + v7) - 1.0;
          *(float *)((char *)&end.x + v7) = *(float *)((char *)&maxs.x + v7) + 1.0;
          *(&start.x + v8) = v10;
          *(&end.x + v8) = v10;
          *(&start.x + v11) = v13;
          *(&end.x + v11) = v13;
          v14->TraceBox_3(
            this: v14,
            a2: &start,
            a3: &end,
            a4: &vec3_origin,
            a5: &vec3_origin,
            a6: v20,
            a7: &vec3_origin,
            a8: &vec3_angle,
            a9: &tr);
          if ( tr.fraction < 1.0 || tr.allsolid || tr.startsolid )
            ++hits;
          v4 = side;
          ++total;
          v13 = v0 + side;
          v15 = *(&maxs.x + v11) <= (float)(v0 + side);
          v10 = u0;
          v0 = v0 + side;
        }
        while ( !v15 );
        v5 = halfSide;
      }
      v16 = *(&maxs.x + v8);
      v10 = v10 + v4;
      u0 = v10;
    }
    while ( v16 > v10 );
    if ( total <= 0 )
LABEL_14:
      total = 1;
    v17 = p_m_orthoAreas;
    v18 = v30;
    p_m_orthoAreas->x = (float)hits / (float)total;
    v6 = v18 + 1;
    v7 += 4;
    v19 = v32-- == 1;
    p_m_orthoAreas = (Vector *)&v17->y;
    v30 = v6;
  }
  while ( !v19 );
}

//------------------------------------------------------------------------------
// Address: 0x10008530
// Name: public: class CPhysConvex __near * CPhysicsCollision::ConvexFromVertsFast(class Vector __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__thiscall CPhysicsCollision::ConvexFromVertsFast(
        CPhysicsCollision *this,
        Vector **pVerts,
        int vertCount)
{
  int v3; // edi
  float *v4; // esi
  Vector *v5; // eax
  float y; // xmm0_4
  int v7; // esi
  IVP_Compact_Ledge *v8; // edi
  void **elems; // eax
  IVP_U_Vector<IVP_U_Point> points; // [esp+Ch] [ebp-8h] BYREF
  char vars0; // [esp+14h] [ebp+0h] BYREF

  v3 = 0;
  *(_DWORD *)&points.memsize = 0;
  for ( points.elems = nullptr; v3 < vertCount; ++v3 )
  {
    v4 = (float *)p_malloc(size: 0x10u);
    v5 = pVerts[v3];
    y = v5->y;
    *v4 = v5->x * g_PhysicsUnits.unitScaleMeters;
    *((_DWORD *)v4 + 1) = COERCE_UNSIGNED_INT(v5->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    v4[2] = g_PhysicsUnits.unitScaleMeters * y;
    if ( points.n_elems >= points.memsize )
      IVP_U_Vector_Base::increment_mem(this: &points);
    points.elems[points.n_elems++] = v4;
  }
  v7 = 0;
  v8 = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(&points);
  if ( points.n_elems != 0 )
  {
    do
      free(data: points.elems[v7++]);
    while ( v7 < points.n_elems );
  }
  elems = points.elems;
  if ( (char *)points.elems != &vars0 )
  {
    if ( points.elems != nullptr )
      free(data: points.elems);
    elems = nullptr;
    points.elems = nullptr;
    points.memsize = 0;
  }
  points.n_elems = 0;
  if ( elems != (void **)&vars0 && elems != nullptr )
    free(data: elems);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10008640
// Name: public: class CPhysConvex __near * CPhysicsCollision::RebuildConvexFromPlanes(class CPhysConvex __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__userpurge CPhysicsCollision::RebuildConvexFromPlanes@<eax>(
        CPhysicsCollision *this@<ecx>,
        int a2@<ebp>,
        CPhysConvex *pConvex,
        float mergeTolerance)
{
  int v5; // esi
  _DWORD *v6; // esi
  IVP_Compact_Ledge *v7; // esi
  _BYTE v8[12]; // [esp+14h] [ebp-2Ch] BYREF
  IVP_U_Hesse plane; // [esp+20h] [ebp-20h] BYREF
  int v10; // [esp+30h] [ebp-10h]
  IVP_Halfspacesoup halfspaces; // [esp+34h] [ebp-Ch]
  void **retaddr; // [esp+40h] [ebp+0h]

  *(_DWORD *)&halfspaces.memsize = a2;
  halfspaces.elems = retaddr;
  if ( pConvex == nullptr )
    return nullptr;
  v5 = *((__int16 *)pConvex + 6);
  v10 = v5;
  IVP_Halfspacesoup::IVP_Halfspacesoup(this: (IVP_Halfspacesoup *)&plane.k[2]);
  if ( v5 > 0 )
  {
    v6 = (_DWORD *)((char *)pConvex + 20);
    do
    {
      IVP_U_Hesse::calc_hesse(
        this: (IVP_U_Hesse *)v8,
        tp0: (const IVP_U_Float_Point *)((char *)pConvex + 16 * (unsigned __int16)*v6 + *(_DWORD *)pConvex),
        tp1: (const IVP_U_Float_Point *)((char *)pConvex
                                  + 16
                                  * (unsigned __int16)*(_DWORD *)((char *)v6
                                                                + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                         + ((unsigned __int8)v6 & 0xC)))
                                  + *(_DWORD *)pConvex),
        tp2: (const IVP_U_Float_Point *)((char *)pConvex
                                  + 16
                                  * (unsigned __int16)*(_DWORD *)((char *)v6
                                                                + *(int *)((char *)IVP_Compact_Edge::prev_table
                                                                         + ((unsigned __int8)v6 & 0xC)))
                                  + *(_DWORD *)pConvex));
      if ( IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v8) > 0.000001 )
      {
        IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)v8);
        IVP_Halfspacesoup::add_halfspace(this: (IVP_Halfspacesoup *)&plane.k[2], plane: (const IVP_U_Hesse *)v8);
      }
      v6 += 4;
      --v10;
    }
    while ( v10 != 0 );
  }
  v7 = IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_compact_ledge(
         halfspaces: (IVP_Halfspacesoup *)&plane.k[2],
         pointmerge_threshold: mergeTolerance);
  IVP_Halfspacesoup::~IVP_Halfspacesoup(this: (IVP_Halfspacesoup *)&plane.k[2]);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10008740
// Name: public: virtual class CPhysConvex __near * CPhysicsCollision::ConvexFromVerts(class Vector __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysConvex *__thiscall CPhysicsCollision::ConvexFromVerts(CPhysicsCollision *this, Vector **pVerts, int vertCount)
{
  CPhysConvex *v4; // edi
  IVP_Compact_Ledge *v5; // ebx
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v4 = (CPhysConvex *)CPhysicsCollision::ConvexFromVertsFast(this, pVerts, vertCount);
  v5 = CPhysicsCollision::RebuildConvexFromPlanes(this, a2: (int)&savedregs, pConvex: v4, mergeTolerance: 0.0099999998);
  if ( v5 == nullptr )
    return v4;
  this->ConvexFree(this, a2: v4);
  return (CPhysConvex *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x100087A0
// Name: public: virtual class CPhysConvex __near * CPhysicsCollision::ConvexFromConvexPolyhedron(class CPolyhedron const __near &)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__thiscall CPhysicsCollision::ConvexFromConvexPolyhedron(
        CPhysicsCollision *this,
        IVP_Compact_Ledge *ConvexPolyhedron)
{
  int v2; // esi
  int v5; // ecx
  unsigned __int16 *v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edi
  IVP_Template_Point *v10; // ecx
  Vector *ledgetree_node_offset; // eax
  float y; // xmm0_4
  int j; // eax
  Polyhedron_IndexedLine_t *v14; // ecx
  unsigned __int16 v15; // si
  IVP_Template_Line *v16; // edx
  int v17; // esi
  int v18; // ecx
  Polyhedron_IndexedPolygon_t *c_point_offset; // eax
  int v20; // edi
  Polyhedron_IndexedPolygon_t *v21; // edx
  float v22; // xmm0_4
  IVP_Template_Surface *v23; // eax
  Polyhedron_IndexedPolygon_t *v24; // ecx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  Polyhedron_IndexedLineReference_t *v28; // edi
  int v29; // esi
  Polyhedron_IndexedPolygon_t *v30; // ecx
  IVP_Template_Surface *surfaces; // eax
  int v32; // edx
  float v33; // xmm0_4
  Polyhedron_IndexedLineReference_t *v34; // eax
  int iLineIndex; // edx
  int v36; // ecx
  Polyhedron_IndexedLineReference_t *v37; // edi
  int v38; // esi
  Polyhedron_IndexedPolygon_t *v39; // edx
  IVP_Template_Surface *v40; // eax
  int v41; // ecx
  float v42; // xmm0_4
  Polyhedron_IndexedLine_t *v43; // eax
  VPlane *v44; // edx
  int v45; // edx
  _WORD *v46; // eax
  Polyhedron_IndexedPolygon_t *v47; // ecx
  IVP_Template_Surface *v48; // eax
  int v49; // edx
  float v50; // xmm0_4
  Polyhedron_IndexedLine_t *v51; // eax
  int v52; // edx
  VPlane *v53; // eax
  Polyhedron_IndexedLineReference_t *v54; // eax
  int v55; // esi
  Polyhedron_IndexedPolygon_t *v56; // ecx
  IVP_Template_Surface *v57; // eax
  int v58; // edx
  float v59; // xmm0_4
  char *revert_line; // ecx
  int v61; // edx
  IVP_Compact_Ledge *v62; // eax
  int v63; // edi
  int v64; // esi
  Vector *v65; // eax
  int ledgetree_node_offset_low; // ecx
  float x; // xmm5_4
  float v68; // xmm4_4
  float z; // xmm3_4
  float v70; // xmm7_4
  float v71; // xmm6_4
  float *p_x; // eax
  int v73; // ecx
  float v74; // xmm2_4
  float v75; // xmm1_4
  float v76; // xmm0_4
  int v77; // edi
  void *v78; // esp
  VPlane *v79; // eax
  float *v80; // ecx
  char *v81; // eax
  double v82; // st7
  int v83; // edx
  Vector *v84; // edi
  float v85; // xmm0_4
  float *v86; // eax
  float v87; // xmm0_4
  float v88; // xmm1_4
  bool v89; // zf
  int v90; // esi
  _BYTE v91[8]; // [esp+30h] [ebp-58h] BYREF
  int v92; // [esp+38h] [ebp-50h] BYREF
  IVP_Template_Polygon polyTemplate; // [esp+3Ch] [ebp-4Ch] BYREF
  Vector vAABBMins; // [esp+54h] [ebp-34h]
  CPhysicsCollision *v95; // [esp+60h] [ebp-28h]
  VPlane *pPlanes; // [esp+64h] [ebp-24h]
  int iPlaneCount; // [esp+68h] [ebp-20h]
  int i; // [esp+6Ch] [ebp-1Ch]
  int iEnd; // [esp+70h] [ebp-18h]
  int k; // [esp+74h] [ebp-14h]
  int iTriangleCount; // [esp+78h] [ebp-10h]
  int v102; // [esp+7Ch] [ebp-Ch]
  Polyhedron_IndexedLineReference_t *pReverseLine; // [esp+80h] [ebp-8h]
  int iWritePolygon; // [esp+84h] [ebp-4h]
  IVP_Compact_Ledge *pLedge; // [esp+90h] [ebp+8h]
  IVP_Compact_Ledge *pLedgea; // [esp+90h] [ebp+8h]
  IVP_Compact_Ledge *pLedgeb; // [esp+90h] [ebp+8h]

  v2 = 0;
  v95 = this;
  if ( fast_poly_convert.m_pParent != nullptr && fast_poly_convert.m_pParent->m_Value.m_nValue != 0 )
    return CVPhysicsVirtualMeshWriter::ConvertPolyhedronToLedge(pPoly: (const CPolyhedron *)ConvexPolyhedron);
  v5 = *((unsigned __int16 *)&ConvexPolyhedron[1] + 5);
  iTriangleCount = 0;
  if ( v5 != 0 )
  {
    v6 = (unsigned __int16 *)(ConvexPolyhedron[1].c_point_offset + 2);
    do
    {
      v7 = iTriangleCount + *v6 - 2;
      v6 += 8;
      --v5;
      iTriangleCount = v7;
    }
    while ( v5 != 0 );
  }
  IVP_Template_Polygon::IVP_Template_Polygon(
    this: &polyTemplate,
    point_count: LOWORD(ConvexPolyhedron[1].ledgetree_node_offset),
    line_count: 3 * iTriangleCount / 2,
    surface_count: iTriangleCount);
  v8 = 0;
  if ( LOWORD(ConvexPolyhedron[1].ledgetree_node_offset) != 0 )
  {
    v9 = 0;
    do
    {
      v10 = &polyTemplate.points[v2];
      ledgetree_node_offset = (Vector *)ConvexPolyhedron->ledgetree_node_offset;
      y = ledgetree_node_offset[v9].y;
      v10->k[0] = ledgetree_node_offset[v9].x * g_PhysicsUnits.unitScaleMeters;
      v10->k[1] = -(float)(ledgetree_node_offset[v9].z * g_PhysicsUnits.unitScaleMeters);
      v10->k[2] = y * g_PhysicsUnits.unitScaleMeters;
      ++v8;
      ++v2;
      ++v9;
    }
    while ( v8 != LOWORD(ConvexPolyhedron[1].ledgetree_node_offset) );
  }
  for ( j = 0; j != HIWORD(ConvexPolyhedron[1].client_data); ++j )
  {
    v14 = *((Polyhedron_IndexedLine_t **)ConvexPolyhedron + 2);
    v15 = v14[j].iPointIndices[1];
    v16 = &polyTemplate.lines[j];
    v16->p[0] = v14[j].iPointIndices[0];
    v16->p[1] = v15;
  }
  v17 = 0;
  v18 = 0;
  pLedge = (IVP_Compact_Ledge *)HIWORD(ConvexPolyhedron[1].client_data);
  iWritePolygon = 0;
  i = 0;
  if ( *((_WORD *)&ConvexPolyhedron[1] + 5) != 0 )
  {
    v102 = 0;
    while ( 1 )
    {
      c_point_offset = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
      if ( *(unsigned __int16 *)((char *)&c_point_offset->iIndexCount + v17) == 3 )
      {
        v20 = v18;
        IVP_Template_Surface::init_surface(this: &polyTemplate.surfaces[v18], line_count: 3);
        polyTemplate.surfaces[v20].templ_poly = &polyTemplate;
        v21 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
        v22 = *(float *)((char *)&v21->polyNormal.y + v17);
        v23 = &polyTemplate.surfaces[v20];
        v23->normal.k[0] = *(float *)((char *)&v21->polyNormal.x + v17) * g_PhysicsUnits.unitScaleMeters;
        v23->normal.k[1] = -(float)(*(float *)((char *)&v21->polyNormal.z + v17) * g_PhysicsUnits.unitScaleMeters);
        v23->normal.k[2] = v22 * g_PhysicsUnits.unitScaleMeters;
        v24 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
        iEnd = *(_DWORD *)&ConvexPolyhedron->n_triangles + 4 * *(unsigned __int16 *)((char *)&v24->iFirstIndex + v17);
        v25 = 0;
        if ( *(unsigned __int16 *)((char *)&v24->iIndexCount + v17) != 0 )
        {
          do
          {
            polyTemplate.surfaces[v20].lines[v25] = *(_WORD *)(iEnd + 4 * v25);
            polyTemplate.surfaces[v20].revert_line[v25] = *(_BYTE *)(iEnd + 4 * v25 + 2);
            ++v25;
          }
          while ( v25 != *(unsigned __int16 *)(ConvexPolyhedron[1].c_point_offset + v17 + 2) );
        }
      }
      else
      {
        v26 = *(unsigned __int16 *)((char *)&c_point_offset->iFirstIndex + v17);
        v27 = *(unsigned __int16 *)((char *)&c_point_offset->iIndexCount + v17);
        v28 = (Polyhedron_IndexedLineReference_t *)(*(_DWORD *)&ConvexPolyhedron->n_triangles + 4 * v26);
        iEnd = v27 - 3;
        v29 = v18;
        pReverseLine = &v28[v27 - 1];
        IVP_Template_Surface::init_surface(this: &polyTemplate.surfaces[v18], line_count: 3);
        polyTemplate.surfaces[v29].templ_poly = &polyTemplate;
        v30 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
        surfaces = polyTemplate.surfaces;
        v32 = v102;
        v33 = *(float *)((char *)&v30->polyNormal.y + v102);
        polyTemplate.surfaces[v29].normal.k[0] = g_PhysicsUnits.unitScaleMeters
                                               * *(float *)((char *)&v30->polyNormal.x + v102);
        surfaces[v29].normal.k[1] = -(float)(*(float *)((char *)&v30->polyNormal.z + v32)
                                           * g_PhysicsUnits.unitScaleMeters);
        surfaces[v29].normal.k[2] = v33 * g_PhysicsUnits.unitScaleMeters;
        *polyTemplate.surfaces[v29].lines = v28->iLineIndex;
        v34 = pReverseLine;
        *polyTemplate.surfaces[v29].revert_line = v28->iEndPointIndex;
        iPlaneCount = *(unsigned __int16 *)(*((_DWORD *)ConvexPolyhedron + 2)
                                          + 2 * (2 * v34->iLineIndex - v34->iEndPointIndex)
                                          + 2);
        iLineIndex = v28->iLineIndex;
        k = (int)&polyTemplate.lines[(_DWORD)pLedge];
        v36 = k;
        *(_WORD *)k = *(_WORD *)(*((_DWORD *)ConvexPolyhedron + 2) + 2 * (v28->iEndPointIndex + 2 * iLineIndex));
        *(_WORD *)(v36 + 2) = iPlaneCount;
        polyTemplate.surfaces[v29].lines[1] = (unsigned __int16)pLedge;
        polyTemplate.surfaces[v29].revert_line[1] = 1;
        polyTemplate.surfaces[v29].lines[2] = v34->iLineIndex;
        polyTemplate.surfaces[v29].revert_line[2] = v34->iEndPointIndex;
        ++iWritePolygon;
        v37 = v28 + 1;
        k = 1;
        if ( iEnd != 1 )
        {
          v38 = iWritePolygon;
          iWritePolygon = iWritePolygon + iEnd - 1;
          do
          {
            if ( (k & 1) != 0 )
            {
              IVP_Template_Surface::init_surface(this: &polyTemplate.surfaces[v38], line_count: 3);
              polyTemplate.surfaces[v38].templ_poly = &polyTemplate;
              v39 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
              v40 = &polyTemplate.surfaces[v38];
              v41 = v102;
              v42 = *(float *)((char *)&v39->polyNormal.y + v102);
              v40->normal.k[0] = *(float *)((char *)&v39->polyNormal.x + v102) * g_PhysicsUnits.unitScaleMeters;
              v40->normal.k[1] = -(float)(*(float *)((char *)&v39->polyNormal.z + v41) * g_PhysicsUnits.unitScaleMeters);
              v40->normal.k[2] = v42 * g_PhysicsUnits.unitScaleMeters;
              *polyTemplate.surfaces[v38].lines = (unsigned __int16)pLedge;
              *polyTemplate.surfaces[v38].revert_line = 0;
              pLedge = (IVP_Compact_Ledge *)((char *)pLedge + 1);
              polyTemplate.surfaces[v38].lines[1] = v37->iLineIndex;
              polyTemplate.surfaces[v38].revert_line[1] = v37->iEndPointIndex;
              v43 = *((Polyhedron_IndexedLine_t **)ConvexPolyhedron + 2);
              v44 = (VPlane *)v43->iPointIndices[2 * pReverseLine->iLineIndex - pReverseLine->iEndPointIndex + 1];
              --pReverseLine;
              pPlanes = v44;
              v45 = v37->iLineIndex;
              iPlaneCount = (int)&polyTemplate.lines[(_DWORD)pLedge];
              LOWORD(v41) = v43[v45].iPointIndices[v37->iEndPointIndex];
              v46 = (_WORD *)iPlaneCount;
              *(_WORD *)(iPlaneCount + 2) = (_WORD)pPlanes;
              *v46 = v41;
              polyTemplate.surfaces[v38].lines[2] = (unsigned __int16)pLedge;
              polyTemplate.surfaces[v38].revert_line[2] = 1;
              ++v37;
            }
            else
            {
              IVP_Template_Surface::init_surface(this: &polyTemplate.surfaces[v38], line_count: 3);
              polyTemplate.surfaces[v38].templ_poly = &polyTemplate;
              v47 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
              v48 = &polyTemplate.surfaces[v38];
              v49 = v102;
              v50 = *(float *)((char *)&v47->polyNormal.y + v102);
              v48->normal.k[0] = *(float *)((char *)&v47->polyNormal.x + v102) * g_PhysicsUnits.unitScaleMeters;
              v48->normal.k[1] = -(float)(*(float *)((char *)&v47->polyNormal.z + v49) * g_PhysicsUnits.unitScaleMeters);
              v48->normal.k[2] = v50 * g_PhysicsUnits.unitScaleMeters;
              *polyTemplate.surfaces[v38].lines = (unsigned __int16)pLedge;
              *polyTemplate.surfaces[v38].revert_line = 0;
              pLedge = (IVP_Compact_Ledge *)((char *)pLedge + 1);
              v51 = *((Polyhedron_IndexedLine_t **)ConvexPolyhedron + 2);
              iPlaneCount = v51->iPointIndices[2 * pReverseLine->iLineIndex - pReverseLine->iEndPointIndex + 1];
              v52 = v37->iLineIndex;
              pPlanes = (VPlane *)&polyTemplate.lines[(_DWORD)pLedge];
              LOWORD(v52) = v51->iPointIndices[2 * v52 - v37->iEndPointIndex + 1];
              v53 = pPlanes;
              HIWORD(pPlanes->m_Normal.x) = iPlaneCount;
              LOWORD(v53->m_Normal.x) = v52;
              polyTemplate.surfaces[v38].lines[1] = (unsigned __int16)pLedge;
              polyTemplate.surfaces[v38].revert_line[1] = 1;
              v54 = pReverseLine;
              polyTemplate.surfaces[v38].lines[2] = pReverseLine->iLineIndex;
              polyTemplate.surfaces[v38].revert_line[2] = v54->iEndPointIndex;
            }
            ++v38;
            ++k;
          }
          while ( k != iEnd );
        }
        v55 = iWritePolygon;
        IVP_Template_Surface::init_surface(this: &polyTemplate.surfaces[iWritePolygon], line_count: 3);
        polyTemplate.surfaces[v55].templ_poly = &polyTemplate;
        v56 = (Polyhedron_IndexedPolygon_t *)ConvexPolyhedron[1].c_point_offset;
        v57 = polyTemplate.surfaces;
        v58 = v102;
        v59 = *(float *)((char *)&v56->polyNormal.y + v102);
        polyTemplate.surfaces[v55].normal.k[0] = *(float *)((char *)&v56->polyNormal.x + v102)
                                               * g_PhysicsUnits.unitScaleMeters;
        v57[v55].normal.k[1] = -(float)(*(float *)((char *)&v56->polyNormal.z + v58) * g_PhysicsUnits.unitScaleMeters);
        v57[v55].normal.k[2] = v59 * g_PhysicsUnits.unitScaleMeters;
        *polyTemplate.surfaces[v55].lines = v37->iLineIndex;
        *polyTemplate.surfaces[v55].revert_line = v37->iEndPointIndex;
        polyTemplate.surfaces[v55].lines[1] = v37[1].iLineIndex;
        polyTemplate.surfaces[v55].revert_line[1] = v37[1].iEndPointIndex;
        polyTemplate.surfaces[v55].lines[2] = (unsigned __int16)pLedge;
        revert_line = polyTemplate.surfaces[v55].revert_line;
        v17 = v102;
        revert_line[2] = 0;
        pLedge = (IVP_Compact_Ledge *)((char *)pLedge + 1);
      }
      v61 = *((unsigned __int16 *)&ConvexPolyhedron[1] + 5);
      ++iWritePolygon;
      v17 += 16;
      ++i;
      v102 = v17;
      if ( i == v61 )
        break;
      v18 = iWritePolygon;
    }
  }
  v62 = IVP_SurfaceBuilder_Polygon_Convex::convert_template_to_ledge(templat: &polyTemplate);
  v63 = iTriangleCount;
  pLedgea = v62;
  if ( iTriangleCount != 0 )
  {
    v64 = 0;
    do
    {
      IVP_Template_Surface::close_surface(this: &polyTemplate.surfaces[v64++]);
      --v63;
    }
    while ( v63 != 0 );
  }
  if ( pLedgea != nullptr )
  {
    IVP_Template_Polygon::~IVP_Template_Polygon(this: &polyTemplate);
    return pLedgea;
  }
  else
  {
    if ( (_S3 & 1) == 0 )
    {
      _S3 |= 1u;
      ConVarRef::ConVarRef(this: &developerRef, pName: "developer");
    }
    if ( developerRef.m_pConVarState->m_Value.m_nValue > 1 )
    {
      v65 = (Vector *)ConvexPolyhedron->ledgetree_node_offset;
      ledgetree_node_offset_low = LOWORD(ConvexPolyhedron[1].ledgetree_node_offset);
      x = v65->x;
      v68 = v65->y;
      z = v65->z;
      vAABBMins.x = v65->x;
      v70 = v68;
      v71 = z;
      if ( ledgetree_node_offset_low != 1 )
      {
        p_x = &v65[1].x;
        v73 = ledgetree_node_offset_low - 1;
        do
        {
          v74 = *p_x;
          if ( vAABBMins.x > *p_x )
            vAABBMins.x = *p_x;
          v75 = p_x[1];
          if ( v70 > v75 )
            v70 = p_x[1];
          v76 = p_x[2];
          if ( v71 > v76 )
            v71 = p_x[2];
          if ( v74 > x )
            x = v74;
          if ( v75 > v68 )
            v68 = p_x[1];
          if ( v76 > z )
            z = p_x[2];
          p_x += 3;
          --v73;
        }
        while ( v73 != 0 );
      }
      _Warning(
        a1: "CPhysicsCollision::ConvexFromConvexPolyhedron() conversion failure of polyhedron with AABB mins( %.2f, %.2f, %.2"
        "f ), maxs( %.2f, %.2f, %.2f )\n",
        vAABBMins.x,
        v70,
        v71,
        x,
        v68,
        z);
    }
    v77 = *((unsigned __int16 *)&ConvexPolyhedron[1] + 5);
    iPlaneCount = (unsigned __int16)v77;
    v78 = alloca((16 * v77 + 15) & 0x3FFFF0);
    v79 = (VPlane *)v91;
    pPlanes = (VPlane *)v91;
    if ( v77 != 0 )
    {
      v80 = (float *)&v92;
      pLedgeb = (IVP_Compact_Ledge *)v77;
      do
      {
        v81 = (char *)(-8 - (_DWORD)v91 + ConvexPolyhedron[1].c_point_offset);
        v82 = *(float *)((char *)v80 + (_DWORD)v81 + 4);
        v83 = *(unsigned __int16 *)(*((_DWORD *)ConvexPolyhedron + 2)
                                  + 4
                                  * *(unsigned __int16 *)(*(_DWORD *)&ConvexPolyhedron->n_triangles
                                                        + 4 * *(unsigned __int16 *)((char *)v80 + (_DWORD)v81)));
        v84 = (Vector *)ConvexPolyhedron->ledgetree_node_offset;
        v85 = *(float *)((char *)v80 + (_DWORD)v81 + 8);
        v86 = (float *)&v81[(_DWORD)v80];
        v83 *= 3;
        v87 = (float)(v85 * *(&v84->y + v83)) + (float)(*(&v84->x + v83) * v86[1]);
        v88 = v86[3] * *(&v84->z + v83);
        *(v80 - 2) = v82;
        *(v80 - 1) = v86[2];
        v80 += 4;
        v89 = pLedgeb == (IVP_Compact_Ledge *)1;
        pLedgeb = (IVP_Compact_Ledge *)((char *)pLedgeb - 1);
        *(v80 - 4) = v86[3];
        *(v80 - 3) = v87 + v88;
      }
      while ( !v89 );
      v79 = pPlanes;
      v77 = iPlaneCount;
    }
    v90 = ((int (__thiscall *)(CPhysicsCollision *, VPlane *, int, _DWORD))v95->ConvexFromPlanes)(
            a1: v95,
            a2: v79,
            a3: v77,
            a4: 0);
    IVP_Template_Polygon::~IVP_Template_Polygon(this: &polyTemplate);
    return (IVP_Compact_Ledge *)v90;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009020
// Name: public: virtual int CPhysicsCollision::GetConvexesUsedInCollideable(class CPhysCollide const __near *,class CPhysConvex __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsCollision::GetConvexesUsedInCollideable(
        CPhysicsCollision *this,
        const CPhysCollide *pCollideable,
        CPhysConvex **pOutputArray,
        int iOutputArrayLimit)
{
  void (__thiscall *GetAllLedges)(struct CPhysCollide *, IVP_U_BigVector<IVP_Compact_Ledge> *); // eax
  int n_elems; // esi
  void **elems; // edi
  CPhysConvex **v7; // eax
  int v8; // ecx
  int i; // edx
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+Ch] [ebp-Ch] BYREF
  char vars0; // [esp+18h] [ebp+0h] BYREF

  GetAllLedges = pCollideable->GetAllLedges;
  memset(&ledges, 0, sizeof(ledges));
  GetAllLedges(this: pCollideable, a2: &ledges);
  n_elems = ledges.n_elems;
  elems = ledges.elems;
  if ( ledges.n_elems > iOutputArrayLimit )
    n_elems = iOutputArrayLimit;
  if ( n_elems != 0 )
  {
    v7 = pOutputArray;
    v8 = (char *)ledges.elems - (char *)pOutputArray;
    for ( i = n_elems; i != 0; --i )
    {
      *v7 = *(CPhysConvex **)((char *)v7 + v8);
      ++v7;
    }
  }
  if ( elems != (void **)&vars0 && elems != nullptr )
    free(data: elems);
  return n_elems;
}

//------------------------------------------------------------------------------
// Address: 0x10009090
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::ConvertConvexToCollideParams(class CPhysConvex __near * __near *,int,struct convertconvexparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__userpurge CPhysicsCollision::ConvertConvexToCollideParams@<eax>(
        CPhysicsCollision *this@<ecx>,
        IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES a2@<ebp>,
        CPhysConvex **pConvex,
        int convexCount,
        const convertconvexparams_t *convertParams)
{
  int v5; // edi
  int v6; // esi
  CPhysCollide **pForcedOuterHull; // edx
  bool v8; // zf
  BOOL v9; // eax
  CPhysCollideCompactSurface *v10; // esi
  IVP_BOOL bUseFastApproximateInertiaTensor; // eax
  void (__thiscall *v12)(IVP_BOOL, IVP_U_Vector<IVV_Sphere> *, const char *); // eax
  _BYTE v14[12]; // [esp+14h] [ebp-DCh] BYREF
  IVP_SurfaceBuilder_Ledge_Soup builder; // [esp+20h] [ebp-D0h] BYREF
  vcollide_t tmp; // [esp+C0h] [ebp-30h] BYREF
  IVP_Template_Surbuild_LedgeSoup params; // [esp+D0h] [ebp-20h] BYREF
  void *v18; // [esp+E8h] [ebp-8h]
  void *retaddr; // [esp+F0h] [ebp+0h]

  params.merge_points = a2;
  v18 = retaddr;
  params.link_to_input_compact_ledges = (IVP_BOOL)this;
  if ( convexCount == 0 || pConvex == nullptr )
    return nullptr;
  v5 = 0;
  IVP_SurfaceBuilder_Ledge_Soup::IVP_SurfaceBuilder_Ledge_Soup(this: (IVP_SurfaceBuilder_Ledge_Soup *)v14);
  v6 = 0;
  if ( convexCount > 0 )
  {
    do
    {
      if ( pConvex[v6] != nullptr )
      {
        ++v5;
        IVP_SurfaceBuilder_Ledge_Soup::insert_ledge(
          this: (IVP_SurfaceBuilder_Ledge_Soup *)v14,
          c_ledge: (IVP_Compact_Ledge *)pConvex[v6]);
      }
      ++v6;
    }
    while ( v6 < convexCount );
    if ( v5 != 0 )
    {
      pForcedOuterHull = (CPhysCollide **)convertParams->pForcedOuterHull;
      tmp.pUserData = (void *)1;
      params.free_input_compact_ledges = IVP_TRUE;
      v8 = !convertParams->buildOuterConvexHull;
      tmp.solids = pForcedOuterHull;
      v9 = !v8;
      v8 = !convertParams->bUseFastApproximateInertiaTensor;
      params.force_convex_hull = nullptr;
      tmp.pKeyValues = (char *)v9;
      params.build_root_convex_hull = !v8;
      if ( fast_poly_convert.m_pParent == nullptr || fast_poly_convert.m_pParent->m_Value.m_nValue == 0 )
        params.build_root_convex_hull = IVP_FALSE;
      params.bUseFastApproximateInertiaTensor = (IVP_BOOL)IVP_SurfaceBuilder_Ledge_Soup::compile(
                                                            this: (IVP_SurfaceBuilder_Ledge_Soup *)v14,
                                                            templ: (IVP_Template_Surbuild_LedgeSoup *)&tmp.solids);
      v10 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
      if ( v10 != nullptr )
      {
        bUseFastApproximateInertiaTensor = params.bUseFastApproximateInertiaTensor;
        v10->m_pCompactSurface = (IVP_Compact_Surface *)params.bUseFastApproximateInertiaTensor;
        v10->__vftable = (CPhysCollideCompactSurface_vtbl *)&CPhysCollideCompactSurface::`vftable';
        *(_DWORD *)(bUseFastApproximateInertiaTensor + 44) = 1397773897;
        v10->m_pCompactSurface->dummy[0] = 0;
        v10->m_orthoAreas.x = 1.0;
        v10->m_orthoAreas.y = 1.0;
        v10->m_orthoAreas.z = 1.0;
        CPhysCollideCompactSurface::InitCollideMap(this: v10);
        v10->m_pAABBTree = nullptr;
      }
      else
      {
        v10 = nullptr;
      }
      if ( convertParams->buildDragAxisAreas )
        ((void (__thiscall *)(CPhysCollideCompactSurface *, _DWORD))v10->ComputeOrthographicAreas)(
          a1: v10,
          a2: LODWORD(convertParams->dragAreaEpsilon));
      if ( convertParams->bBuildAABBTree )
        v10->m_pAABBTree = Trace_CreateAABBTree(pSurface: v10);
      if ( convertParams->checkOptimalTracing )
      {
        *((_WORD *)&builder.all_spheres + 4) = *(_WORD *)(&builder.all_spheres + 1) & 0x8000 | 1;
        v12 = *(void (__thiscall **)(IVP_BOOL, IVP_U_Vector<IVV_Sphere> *, const char *))(*(_DWORD *)params.link_to_input_compact_ledges
                                                                                        + 224);
        *((_DWORD *)&builder.all_spheres + 3) = &params.bUseFastApproximateInertiaTensor;
        params.bUseFastApproximateInertiaTensor = (IVP_BOOL)v10;
        v12(a1: params.link_to_input_compact_ledges, a2: &builder.all_spheres + 1, a3: str);
      }
      IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(this: (IVP_SurfaceBuilder_Ledge_Soup *)v14);
      return v10;
    }
  }
  IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(this: (IVP_SurfaceBuilder_Ledge_Soup *)v14);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009240
// Name: private: class CPhysCollideCompactSurface __near * CPhysicsCollision::FastBboxCollide(class CPhysCollideCompactSurface const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__userpurge CPhysicsCollision::FastBboxCollide@<eax>(
        CPhysicsCollision *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CPhysCollideCompactSurface *pCollide,
        const Vector *mins,
        Vector *maxs)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float z; // xmm2_4
  const IVP_Compact_Surface *(__thiscall *GetCompactSurface)(struct CPhysCollideCompactSurface *); // edx
  int v13; // eax
  unsigned __int8 *v14; // edi
  float *v15; // eax
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float unitScaleMeters; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm5_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  CPhysCollide *(__thiscall *ConvertConvexToCollide)(struct CPhysicsCollision *, CPhysConvex **, int); // edx
  float v34; // xmm2_4
  float v35; // xmm4_4
  Vector *v36; // ecx
  float v37; // xmm2_4
  float v38; // xmm0_4
  Vector boxVerts[8]; // [esp+0h] [ebp-60h] BYREF

  x = mins->x;
  y = mins->y;
  v8 = maxs->x;
  v9 = maxs->y;
  boxVerts[0].z = mins->z;
  boxVerts[1].z = boxVerts[0].z;
  boxVerts[2].z = boxVerts[0].z;
  boxVerts[3].z = boxVerts[0].z;
  z = maxs->z;
  GetCompactSurface = pCollide->GetCompactSurface;
  boxVerts[0].x = x;
  boxVerts[0].y = y;
  boxVerts[1].x = v8;
  boxVerts[1].y = y;
  boxVerts[2].x = x;
  boxVerts[2].y = v9;
  boxVerts[3].x = v8;
  boxVerts[3].y = v9;
  boxVerts[4].x = x;
  boxVerts[4].y = y;
  boxVerts[4].z = z;
  boxVerts[5].x = v8;
  boxVerts[5].y = y;
  boxVerts[5].z = z;
  boxVerts[6].x = x;
  boxVerts[6].y = v9;
  boxVerts[6].z = z;
  boxVerts[7].x = v8;
  boxVerts[7].y = v9;
  boxVerts[7].z = z;
  v13 = ((int (__thiscall *)(const CPhysCollideCompactSurface *, int, int))GetCompactSurface)(a1: pCollide, a2, a3);
  maxs = (Vector *)(v13 + *(_DWORD *)(v13 + 32) + *(_DWORD *)(v13 + *(_DWORD *)(v13 + 32) + 4));
  mins = (const Vector *)(16 * (LODWORD(maxs->z) >> 8));
  v14 = (unsigned __int8 *)ivp_malloc_aligned(size: (int)mins, alignment: 16);
  memcpy(dst: v14, src: (unsigned __int8 *)maxs, count: (unsigned int)mins);
  if ( (v14[8] & 3) == 0 )
    *((_DWORD *)v14 + 1) = 0;
  v15 = (float *)&v14[*(_DWORD *)v14];
  v16 = boxVerts[this->m_bboxVertMap[0]].y * g_PhysicsUnits.unitScaleMeters;
  v17 = boxVerts[this->m_bboxVertMap[0]].z * g_PhysicsUnits.unitScaleMeters;
  *v15 = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[0]].x;
  v15[2] = v16;
  v15[1] = -v17;
  v15[3] = 0.0;
  v18 = -(float)(boxVerts[this->m_bboxVertMap[1]].z * g_PhysicsUnits.unitScaleMeters);
  v19 = boxVerts[this->m_bboxVertMap[1]].y * g_PhysicsUnits.unitScaleMeters;
  v15[4] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[1]].x;
  v15[5] = v18;
  v15[6] = v19;
  v15[7] = 0.0;
  v20 = -(float)(boxVerts[this->m_bboxVertMap[2]].z * g_PhysicsUnits.unitScaleMeters);
  v21 = boxVerts[this->m_bboxVertMap[2]].y * g_PhysicsUnits.unitScaleMeters;
  v15[8] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[2]].x;
  v15[9] = v20;
  v15[10] = v21;
  v15[11] = 0.0;
  unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
  v23 = boxVerts[this->m_bboxVertMap[3]].y;
  v24 = boxVerts[this->m_bboxVertMap[3]].z * g_PhysicsUnits.unitScaleMeters;
  v15[12] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[3]].x;
  v15[13] = -v24;
  v15[14] = v23 * unitScaleMeters;
  v15[15] = 0.0;
  v25 = g_PhysicsUnits.unitScaleMeters;
  v26 = boxVerts[this->m_bboxVertMap[4]].z;
  v27 = boxVerts[this->m_bboxVertMap[4]].y;
  v15[16] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[4]].x;
  v15[17] = -(float)(v26 * v25);
  v15[18] = v27 * v25;
  v15[19] = 0.0;
  v28 = boxVerts[this->m_bboxVertMap[5]].y;
  v29 = g_PhysicsUnits.unitScaleMeters;
  v30 = -(float)(boxVerts[this->m_bboxVertMap[5]].z * g_PhysicsUnits.unitScaleMeters);
  v15[20] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[5]].x;
  v15[21] = v30;
  v15[22] = v28 * v29;
  v15[23] = 0.0;
  v31 = g_PhysicsUnits.unitScaleMeters;
  v32 = boxVerts[this->m_bboxVertMap[6]].y;
  ConvertConvexToCollide = this->ConvertConvexToCollide;
  v34 = -(float)(boxVerts[this->m_bboxVertMap[6]].z * g_PhysicsUnits.unitScaleMeters);
  v15[24] = g_PhysicsUnits.unitScaleMeters * boxVerts[this->m_bboxVertMap[6]].x;
  v15[25] = v34;
  v15[26] = v32 * v31;
  v15[27] = 0.0;
  v35 = g_PhysicsUnits.unitScaleMeters;
  v36 = &boxVerts[this->m_bboxVertMap[7]];
  v37 = boxVerts[this->m_bboxVertMap[7]].z * g_PhysicsUnits.unitScaleMeters;
  v38 = v36->y;
  v15[28] = g_PhysicsUnits.unitScaleMeters * v36->x;
  v15[29] = -v37;
  v15[30] = v38 * v35;
  v15[31] = 0.0;
  pCollide = (const CPhysCollideCompactSurface *)v14;
  return (CPhysCollideCompactSurface *)ConvertConvexToCollide(this, a2: (CPhysConvex **)&pCollide, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10009580
// Name: public: virtual class CPhysConvex __near * CPhysicsCollision::BBoxToConvex(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__thiscall CPhysicsCollision::BBoxToConvex(
        CPhysicsCollision *this,
        const Vector *mins,
        const Vector *maxs)
{
  Vector boxVerts[8]; // [esp+8h] [ebp-80h] BYREF
  Vector *ppVerts[8]; // [esp+68h] [ebp-20h] BYREF

  InitBoxVerts(ppVerts, mins, maxs, boxVerts);
  return CPhysicsCollision::ConvexFromVertsFast(this, pVerts: ppVerts, vertCount: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100095C0
// Name: private: class CPhysCollideCompactSurface __near * CPhysicsCollision::GetBBoxCache(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__thiscall CPhysicsCollision::GetBBoxCache(
        CPhysicsCollision *this,
        const Vector *mins,
        const Vector *maxs)
{
  int v3; // edx
  bboxcache_t *m_pMemory; // ecx
  float x; // xmm0_4
  float *p_x; // esi
  float *i; // ecx
  const Vector *minsa; // [esp+14h] [ebp+8h]

  v3 = this->m_bboxCache.m_Size - 1;
  if ( v3 < 0 )
    return nullptr;
  m_pMemory = this->m_bboxCache.m_Memory.m_pMemory;
  x = mins->x;
  p_x = &m_pMemory[v3].mins.x;
  minsa = &m_pMemory->mins;
  for ( i = p_x + 5;
        x != *p_x
     || mins->y != *(i - 4)
     || mins->z != *(i - 3)
     || maxs->x != *(i - 2)
     || maxs->y != *(i - 1)
     || maxs->z != *i;
        i -= 7 )
  {
    p_x -= 7;
    if ( --v3 < 0 )
      return nullptr;
  }
  return *((CPhysCollideCompactSurface **)&minsa[2].x + 7 * v3);
}

//------------------------------------------------------------------------------
// Address: 0x10009670
// Name: public: CPhysPolysoup::CPhysPolysoup(void)
// Source: json
//------------------------------------------------------------------------------
CPhysPolysoup *__thiscall CPhysPolysoup::CPhysPolysoup(CPhysPolysoup *this)
{
  IVP_SurfaceBuilder_Ledge_Soup::IVP_SurfaceBuilder_Ledge_Soup(this: &this->m_builderSoup);
  *(_DWORD *)&this->m_points.memsize = 0;
  this->m_points.elems = nullptr;
  this->m_isValid = false;
  if ( this->m_points.n_elems >= this->m_points.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->m_points);
  this->m_points.elems[this->m_points.n_elems++] = this->m_triangle;
  if ( this->m_points.n_elems >= this->m_points.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->m_points);
  this->m_points.elems[this->m_points.n_elems++] = &this->m_triangle[1];
  if ( this->m_points.n_elems >= this->m_points.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->m_points);
  this->m_points.elems[this->m_points.n_elems++] = &this->m_triangle[2];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009740
// Name: public: virtual class CPhysPolysoup __near * CPhysicsCollision::PolysoupCreate(void)
// Source: json
//------------------------------------------------------------------------------
CPhysPolysoup *__thiscall CPhysicsCollision::PolysoupCreate(CPhysicsCollision *this)
{
  CPhysPolysoup *v1; // eax

  v1 = (CPhysPolysoup *)p_malloc(size: 0xF0u);
  if ( v1 != nullptr )
    return CPhysPolysoup::CPhysPolysoup(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009760
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::ConvertPolysoupToCollide(class CPhysPolysoup __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__userpurge CPhysicsCollision::ConvertPolysoupToCollide@<eax>(
        CPhysicsCollision *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CPhysCollide *pSoup,
        bool useMOPP)
{
  IVP_Compact_Surface *v7; // edi
  CPhysCollideCompactSurface *v8; // eax
  CPhysCollide *v9; // esi
  CPhysCollide *v10; // edi
  int v11; // esi
  void **elems; // ebx
  __int16 *v13; // eax
  int v14; // edx
  char v15; // cl
  char *v16; // eax
  int v17; // ecx
  int j; // esi
  int v19; // ecx
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+0h] [ebp-10h] BYREF
  int i; // [esp+Ch] [ebp-4h] BYREF
  CPhysCollide *pCollide; // [esp+18h] [ebp+8h]

  if ( LOBYTE(pSoup[56].__vftable) == 0 )
    return nullptr;
  v7 = IVP_SurfaceBuilder_Ledge_Soup::compile(this: (IVP_SurfaceBuilder_Ledge_Soup *)pSoup, templ: nullptr);
  v8 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
  v9 = v8;
  if ( v8 != nullptr )
  {
    v8->m_pCompactSurface = v7;
    v8->__vftable = (CPhysCollideCompactSurface_vtbl *)&CPhysCollideCompactSurface::`vftable';
    v7->dummy[2] = 1397773897;
    v8->m_pCompactSurface->dummy[0] = 0;
    v8->m_orthoAreas.x = 1.0;
    v8->m_orthoAreas.y = 1.0;
    v8->m_orthoAreas.z = 1.0;
    CPhysCollideCompactSurface::InitCollideMap(this: v8);
    v9[6].__vftable = nullptr;
    pCollide = v9;
  }
  else
  {
    pCollide = nullptr;
  }
  v10 = pCollide;
  memset(&ledges, 0, sizeof(ledges));
  ((void (__thiscall *)(CPhysCollide *, IVP_U_BigVector<IVP_Compact_Ledge> *, int, int, int))pCollide->GetAllLedges)(
    a1: pCollide,
    a2: &ledges,
    a3,
    a4,
    a5: a2);
  v11 = 0;
  elems = ledges.elems;
  i = 0;
  if ( ledges.n_elems <= 0 )
    goto LABEL_20;
  do
  {
    v13 = (__int16 *)elems[v11];
    v14 = v13[6];
    v15 = *((_BYTE *)v13 + 19);
    v16 = (char *)(v13 + 8);
    v17 = v15 & 0x7F;
    if ( v17 == 0 )
    {
      if ( v14 <= 0 )
        goto LABEL_18;
      for ( j = v14; j != 0; --j )
      {
        if ( (v16[3] & 0x7F) != 0 )
          LOBYTE(v17) = v16[3] & 0x7F;
        v16 += 16;
      }
      v11 = i;
    }
    if ( v14 > 0 )
    {
      v19 = (v17 & 0x7F) << 24;
      do
      {
        *(_DWORD *)v16 = v19 | *(_DWORD *)v16 & 0x80FFFFFF;
        v16 += 16;
        --v14;
      }
      while ( v14 != 0 );
      elems = ledges.elems;
    }
LABEL_18:
    i = ++v11;
  }
  while ( v11 < ledges.n_elems );
  v10 = pCollide;
LABEL_20:
  if ( elems != (void **)&i && elems != nullptr )
    free(data: elems);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10009880
// Name: public: virtual int CPhysicsCollision::CreateDebugMesh(class CPhysCollide const __near *,class Vector __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsCollision::CreateDebugMesh(
        CPhysicsCollision *this,
        const CPhysCollide *pCollisionModel,
        Vector **outVerts)
{
  void (__thiscall *GetAllLedges)(struct CPhysCollide *, IVP_U_BigVector<IVP_Compact_Ledge> *); // eax
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ecx
  Vector *v8; // eax
  int v9; // ecx
  void **elems; // eax
  _DWORD *v11; // esi
  int v12; // edx
  int p_y; // ecx
  _DWORD *v14; // edi
  int v15; // eax
  int v16; // edx
  float v17; // xmm3_4
  int v18; // edx
  float v19; // xmm0_4
  int v20; // edx
  float v21; // xmm0_4
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+Ch] [ebp-14h] BYREF
  Vector *v24; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]
  int vertCount; // [esp+28h] [ebp+8h]

  GetAllLedges = pCollisionModel->GetAllLedges;
  v4 = 0;
  memset(&ledges, 0, sizeof(ledges));
  GetAllLedges(this: pCollisionModel, a2: &ledges);
  v5 = 0;
  v6 = 0;
  vertCount = 0;
  if ( ledges.n_elems > 0 )
  {
    do
    {
      v7 = *((__int16 *)ledges.elems[v6++] + 6);
      v5 += v7 + 2 * v7;
    }
    while ( v6 < ledges.n_elems );
    vertCount = v5;
  }
  v8 = (Vector *)p_malloc(size: (12 * (unsigned __int64)(unsigned int)v5) >> 32 != 0 ? -1 : 12 * v5);
  v9 = 0;
  v24 = v8;
  elems = ledges.elems;
  for ( i = 0; v9 < ledges.n_elems; i = v9 )
  {
    v11 = elems[v9];
    v12 = *((__int16 *)v11 + 6);
    if ( v12 > 0 )
    {
      p_y = (int)&v24[v4 + 1].y;
      v14 = v11 + 6;
      v15 = *((__int16 *)v11 + 6);
      v4 += v12 + 2 * v12;
      do
      {
        v16 = *v11 + 16 * (unsigned __int16)v14[1];
        p_y += 36;
        v17 = *(float *)((char *)v11 + v16 + 4) * g_PhysicsUnits.unitScaleMetersInv;
        *(float *)(p_y - 48) = *(float *)((char *)v11 + v16 + 8) * g_PhysicsUnits.unitScaleMetersInv;
        *(float *)(p_y - 44) = -v17;
        *(float *)(p_y - 52) = *(float *)((char *)v11 + v16) * g_PhysicsUnits.unitScaleMetersInv;
        v18 = *v11 + 16 * (unsigned __int16)*v14;
        v14 += 4;
        v19 = *(float *)((char *)v11 + v18 + 8) * g_PhysicsUnits.unitScaleMetersInv;
        *(float *)(p_y - 32) = -(float)(*(float *)((char *)v11 + v18 + 4) * g_PhysicsUnits.unitScaleMetersInv);
        *(float *)(p_y - 36) = v19;
        *(float *)(p_y - 40) = *(float *)((char *)v11 + v18) * g_PhysicsUnits.unitScaleMetersInv;
        v20 = *v11 + 16 * (unsigned __int16)*(v14 - 5);
        --v15;
        v21 = *(float *)((char *)v11 + v20 + 8) * g_PhysicsUnits.unitScaleMetersInv;
        *(float *)(p_y - 20) = -(float)(*(float *)((char *)v11 + v20 + 4) * g_PhysicsUnits.unitScaleMetersInv);
        *(float *)(p_y - 24) = v21;
        *(float *)(p_y - 28) = *(float *)((char *)v11 + v20) * g_PhysicsUnits.unitScaleMetersInv;
      }
      while ( v15 != 0 );
      elems = ledges.elems;
      v5 = vertCount;
      v9 = i;
    }
    ++v9;
  }
  *outVerts = v24;
  if ( elems != (void **)&v24 && elems != nullptr )
    free(data: elems);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10009A50
// Name: public: virtual void CPhysicsCollision::DestroyCollide(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::DestroyCollide(CPhysicsCollision *this, CPhysCollideCompactSurface *pCollide)
{
  int v2; // eax
  CPhysCollideCompactSurface **p_pCollide; // edx

  v2 = this->m_bboxCache.m_Size - 1;
  if ( v2 < 0 )
  {
LABEL_5:
    if ( pCollide != nullptr )
      ((void (__thiscall *)(CPhysCollideCompactSurface *, int))pCollide->dtr_IPhysCollide)(a1: pCollide, a2: 1);
  }
  else
  {
    p_pCollide = &this->m_bboxCache.m_Memory.m_pMemory[v2].pCollide;
    while ( *p_pCollide != pCollide )
    {
      p_pCollide -= 7;
      if ( --v2 < 0 )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009A90
// Name: public: virtual float CPhysicsCollision::CollideVolume(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsCollision::CollideVolume(CPhysicsCollision *this, CPhysCollide *pCollide)
{
  void (__thiscall *GetAllLedges)(struct CPhysCollide *, IVP_U_BigVector<IVP_Compact_Ledge> *); // eax
  int v4; // esi
  double result; // st7
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+8h] [ebp-Ch] BYREF
  char vars0; // [esp+14h] [ebp+0h] BYREF
  float volume; // [esp+1Ch] [ebp+8h]

  GetAllLedges = pCollide->GetAllLedges;
  memset(&ledges, 0, sizeof(ledges));
  GetAllLedges(this: pCollide, a2: &ledges);
  v4 = 0;
  volume = 0.0;
  if ( ledges.n_elems > 0 )
  {
    do
    {
      result = ((double (__thiscall *)(CPhysicsCollision *, void *))this->ConvexVolume)(
                 a1: this,
                 a2: ledges.elems[v4++])
             + volume;
      volume = result;
    }
    while ( v4 < ledges.n_elems );
  }
  else
  {
    result = 0.0;
  }
  if ( (char *)ledges.elems != &vars0 && ledges.elems != nullptr )
  {
    free(data: ledges.elems);
    return volume;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009B20
// Name: public: virtual float CPhysicsCollision::CollideSurfaceArea(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsCollision::CollideSurfaceArea(CPhysicsCollision *this, CPhysCollide *pCollide)
{
  void (__thiscall *GetAllLedges)(struct CPhysCollide *, IVP_U_BigVector<IVP_Compact_Ledge> *); // eax
  int v4; // esi
  double result; // st7
  IVP_U_BigVector<IVP_Compact_Ledge> ledges; // [esp+8h] [ebp-Ch] BYREF
  char vars0; // [esp+14h] [ebp+0h] BYREF
  float area; // [esp+1Ch] [ebp+8h]

  GetAllLedges = pCollide->GetAllLedges;
  memset(&ledges, 0, sizeof(ledges));
  GetAllLedges(this: pCollide, a2: &ledges);
  v4 = 0;
  area = 0.0;
  if ( ledges.n_elems > 0 )
  {
    do
    {
      result = ((double (__thiscall *)(CPhysicsCollision *, void *))this->ConvexSurfaceArea)(
                 a1: this,
                 a2: ledges.elems[v4++])
             + area;
      area = result;
    }
    while ( v4 < ledges.n_elems );
  }
  else
  {
    result = 0.0;
  }
  if ( (char *)ledges.elems != &vars0 && ledges.elems != nullptr )
  {
    free(data: ledges.elems);
    return area;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009BB0
// Name: public: virtual bool CPhysicsCollision::GetBBoxCacheSize(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsCollision::GetBBoxCacheSize(CPhysicsCollision *this, int *pCachedSize, int *pCachedCount)
{
  int m_Size; // eax
  int v4; // esi
  int v5; // ebx
  CPhysCollideCompactSurface *pCollide; // ecx
  CPhysicsCollision *v8; // [esp+8h] [ebp-4h]

  *pCachedSize = 0;
  m_Size = this->m_bboxCache.m_Size;
  v4 = 0;
  v8 = this;
  *pCachedCount = m_Size;
  if ( m_Size > 0 )
  {
    v5 = 0;
    while ( 1 )
    {
      pCollide = this->m_bboxCache.m_Memory.m_pMemory[v5].pCollide;
      *pCachedSize += pCollide->GetSerializationSize(this: pCollide);
      ++v4;
      ++v5;
      if ( v4 >= *pCachedCount )
        break;
      this = v8;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009C60
// Name: public: static class CPhysCollide __near * CPhysCollide::UnserializeFromBuffer(char const __near *,unsigned int,int,bool)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__cdecl CPhysCollide::UnserializeFromBuffer(
        char *pBuffer,
        unsigned int size,
        int index,
        bool swap)
{
  CPhysCollideCompactSurface *v5; // eax
  int v6; // eax
  CPhysCollideCompactSurface *v7; // eax

  if ( *(_DWORD *)pBuffer == 1497911382 )
  {
    if ( *((_WORD *)pBuffer + 3) != 0 )
    {
      if ( *((_WORD *)pBuffer + 3) == 1 )
        _DevMsg(a1: 2, a2: "Null physics model\n");
      return nullptr;
    }
    v5 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
    if ( v5 != nullptr )
      return CPhysCollideCompactSurface::CPhysCollideCompactSurface(
               this: v5,
               pHeader: (const compactsurfaceheader_t *)pBuffer,
               index,
               swap);
    return nullptr;
  }
  v6 = *((_DWORD *)pBuffer + 11);
  if ( v6 == 1347440461 )
    return nullptr;
  if ( v6 != 1397773897 && v6 != 1230393427 )
  {
    if ( v6 != 0 )
      return nullptr;
    _DevMsg(a1: 1, a2: "Old format .PHY file loaded!!!\n");
  }
  v7 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
  if ( v7 == nullptr )
    return nullptr;
  return CPhysCollideCompactSurface::CPhysCollideCompactSurface(this: v7, pBuffer, size, index, swap);
}

//------------------------------------------------------------------------------
// Address: 0x10009D10
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::UnserializeCollide(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__thiscall CPhysicsCollision::UnserializeCollide(
        CPhysicsCollision *this,
        char *pBuffer,
        unsigned int size,
        int index)
{
  return CPhysCollide::UnserializeFromBuffer(pBuffer, size, index, swap: false);
}

//------------------------------------------------------------------------------
// Address: 0x10009D30
// Name: public: virtual void CPhysicsCollision::PolysoupDestroy(class CPhysPolysoup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::PolysoupDestroy(CPhysicsCollision *this, CPhysPolysoup *pSoup)
{
  CPhysPolysoup *elems; // eax

  if ( pSoup != nullptr )
  {
    elems = (CPhysPolysoup *)pSoup->m_points.elems;
    if ( elems != (CPhysPolysoup *)(&pSoup->m_points + 1) )
    {
      if ( elems != nullptr )
        free(data: pSoup->m_points.elems);
      pSoup->m_points.elems = nullptr;
      pSoup->m_points.memsize = 0;
    }
    pSoup->m_points.n_elems = 0;
    IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(this: &pSoup->m_builderSoup);
    free(data: pSoup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: public: virtual void CPhysicsCollision::VCollideLoad(struct vcollide_t __near *,int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::VCollideLoad(
        CPhysicsCollision *this,
        vcollide_t *pOutput,
        int solidCount,
        const char *pBuffer,
        int bufferSize,
        bool swap)
{
  int v7; // edi
  const char *i; // eax
  int v9; // ecx
  char *v10; // esi
  bool v11; // zf
  CPhysCollideCompactSurface *v12; // eax
  unsigned __int16 v13; // ax
  CPhysCollideCompactSurface *v14; // eax
  int v15; // eax
  CPhysCollideCompactSurface *v16; // eax
  int sizeOut; // [esp+4h] [ebp-8h] BYREF
  int size; // [esp+8h] [ebp-4h]
  int position; // [esp+14h] [ebp+8h]
  int positiona; // [esp+14h] [ebp+8h]

  *(_QWORD *)pOutput = 0;
  *(_QWORD *)&pOutput->pKeyValues = 0;
  *(_WORD *)pOutput ^= (solidCount ^ *(_WORD *)pOutput) & 0x7FFF;
  position = 0;
  v7 = 0;
  pOutput->solids = (CPhysCollide **)p_malloc(size: (unsigned __int64)(unsigned int)solidCount >> 30 != 0 ? -1 : 4 * solidCount);
  for ( i = pBuffer; v7 < solidCount; ++v7 )
  {
    v9 = *(_DWORD *)&i[position];
    positiona = position + 4;
    v10 = (char *)&i[positiona];
    v11 = *(_DWORD *)&i[positiona] == 1497911382;
    size = v9;
    if ( v11 )
    {
      if ( *((_WORD *)v10 + 3) != 0 )
      {
        if ( *((_WORD *)v10 + 3) == 1 )
          _DevMsg(a1: 2, a2: "Null physics model\n");
      }
      else
      {
        v14 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
        if ( v14 != nullptr )
        {
          v12 = CPhysCollideCompactSurface::CPhysCollideCompactSurface(
                  this: v14,
                  pHeader: (const compactsurfaceheader_t *)v10,
                  index: v7,
                  swap);
          goto LABEL_7;
        }
      }
    }
    else
    {
      v15 = *((_DWORD *)v10 + 11);
      if ( v15 != 1347440461 )
      {
        if ( v15 == 1397773897 || v15 == 1230393427 )
          goto LABEL_18;
        if ( v15 == 0 )
        {
          _DevMsg(a1: 1, a2: "Old format .PHY file loaded!!!\n");
LABEL_18:
          v16 = (CPhysCollideCompactSurface *)p_malloc(size: 0x1Cu);
          if ( v16 != nullptr )
          {
            v12 = CPhysCollideCompactSurface::CPhysCollideCompactSurface(this: v16, pBuffer: v10, size, index: v7, swap);
            goto LABEL_7;
          }
        }
      }
    }
    v12 = nullptr;
LABEL_7:
    position = size + positiona;
    pOutput->solids[v7] = v12;
    i = pBuffer;
  }
  *(_WORD *)pOutput |= 0x8000u;
  sizeOut = 0;
  pOutput->pKeyValues = (char *)PackVCollideText(
                                  pTextIn: &i[position],
                                  textSize: bufferSize - position,
                                  pSizeOut: &sizeOut);
  v13 = sizeOut;
  pOutput->pUserData = nullptr;
  pOutput->descSize = v13;
}

//------------------------------------------------------------------------------
// Address: 0x10009F00
// Name: public: virtual class ICollisionQuery __near * CPhysicsCollision::CreateQueryModel(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
ICollisionQuery *__thiscall CPhysicsCollision::CreateQueryModel(CPhysicsCollision *this, CPhysCollide *pCollide)
{
  char *v2; // eax
  char *v3; // esi

  v2 = (char *)p_malloc(size: 0x10u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  *(_DWORD *)v2 = &CCollisionQuery::`vftable';
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  pCollide->GetAllLedges(this: pCollide, a2: (IVP_U_BigVector<IVP_Compact_Ledge> *)(v2 + 4));
  return (ICollisionQuery *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10009FB0
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::CreateVirtualMesh(struct virtualmeshparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__thiscall CPhysicsCollision::CreateVirtualMesh(
        CPhysicsCollision *this,
        const virtualmeshparams_t *params)
{
  return CreateVirtualMesh(params);
}

//------------------------------------------------------------------------------
// Address: 0x10009FD0
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(data: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A090
// Name: private: void CPhysicsCollision::AddBBoxCache(class CPhysCollideCompactSurface __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollision::AddBBoxCache(
        CPhysicsCollision *this,
        CPhysCollideCompactSurface *pCollide,
        const Vector *mins,
        const Vector *maxs)
{
  bboxcache_t *v4; // eax

  v4 = &this->m_bboxCache.m_Memory.m_pMemory[CUtlVector<bboxcache_t,CUtlMemory<bboxcache_t,int>>::InsertBefore(
                                               this: &this->m_bboxCache,
                                               elem: this->m_bboxCache.m_Size)];
  v4->pCollide = pCollide;
  v4->mins = *mins;
  v4->maxs = *maxs;
}

//------------------------------------------------------------------------------
// Address: 0x1000A1F0
// Name: private: void CPhysicsCollision::InitBBoxCache(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CPhysicsCollision::InitBBoxCache(
        CPhysicsCollision *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  int v5; // ecx
  float *v6; // edi
  float v7; // xmm6_4
  char v8; // dl
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  int v12; // eax
  float *p_z; // esi
  __int128 v14; // xmm0
  CPhysicsCollision *v15; // eax
  CPhysicsCollision *v16; // esi
  int v17; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bboxcache_t *m_pMemory; // ecx
  int v21; // eax
  CPhysicsCollision *v22; // edx
  _DWORD *p_x; // eax
  Vector v26; // [esp-Ch] [ebp-BCh] BYREF
  Vector boxVerts[8]; // [esp+0h] [ebp-B0h] BYREF
  Vector *ppVerts[8]; // [esp+64h] [ebp-4Ch] BYREF
  __int128 maxs; // [esp+84h] [ebp-2Ch] OVERLAPPED BYREF
  Vector mins; // [esp+94h] [ebp-1Ch] BYREF
  CPhysicsCollision *v31; // [esp+A0h] [ebp-10h]
  int v32; // [esp+A4h] [ebp-Ch]
  CPhysConvex *pConvex; // [esp+A8h] [ebp-8h]
  CPhysConvex *retaddr; // [esp+B0h] [ebp+0h]

  v32 = a2;
  pConvex = retaddr;
  *(_QWORD *)((char *)&maxs + 4) = 0xC1800000C1800000uLL;
  HIDWORD(maxs) = 0;
  ppVerts[5] = (Vector *)1098907648;
  ppVerts[6] = (Vector *)1098907648;
  v31 = this;
  ppVerts[7] = (Vector *)1116733440;
  InitBoxVerts(
    ppVerts: (Vector **)&boxVerts[7].y,
    mins: (const Vector *)((char *)&maxs + 4),
    maxs: (const Vector *)&ppVerts[5],
    boxVerts: &v26);
  LODWORD(mins.z) = CPhysicsCollision::ConvexFromVertsFast(this, pVerts: (Vector **)&boxVerts[7].y, vertCount: 8);
  v5 = 0;
  v6 = (float *)(LODWORD(mins.z) + *(_DWORD *)LODWORD(mins.z) + 8);
  do
  {
    v7 = 0.1;
    v8 = -1;
    LODWORD(v9) = COERCE_UNSIGNED_INT(*(v6 - 1) * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
    v10 = *v6 * g_PhysicsUnits.unitScaleMetersInv;
    v11 = *(v6 - 2) * g_PhysicsUnits.unitScaleMetersInv;
    v12 = 0;
    p_z = &v26.z;
    do
    {
      v14 = 0;
      *(float *)&v14 = fsqrt(
                         (float)((float)((float)(*(p_z - 1) - v10) * (float)(*(p_z - 1) - v10))
                               + (float)((float)(*p_z - v9) * (float)(*p_z - v9)))
                       + (float)((float)(*(p_z - 2) - v11) * (float)(*(p_z - 2) - v11)));
      maxs = v14;
      if ( v7 > *(float *)&v14 )
      {
        v7 = *(float *)&maxs;
        v8 = v12;
      }
      ++v12;
      p_z += 3;
    }
    while ( v12 < 8 );
    v15 = v31;
    v31->m_bboxVertMap[v5++] = v8;
    v6 += 4;
  }
  while ( v5 < 8 );
  v16 = v15;
  v17 = ((int (__thiscall *)(CPhysicsCollision *, float *, int, int, int))v15->ConvertConvexToCollide)(
          a1: v15,
          a2: &mins.z,
          a3: 1,
          a4: a3,
          a5: a4);
  m_Size = v16->m_bboxCache.m_Size;
  v31 = (CPhysicsCollision *)v17;
  m_nAllocationCount = v16->m_bboxCache.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bboxcache_t,int>::Grow(this: &v16->m_bboxCache.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++v16->m_bboxCache.m_Size;
  m_pMemory = v16->m_bboxCache.m_Memory.m_pMemory;
  v21 = v16->m_bboxCache.m_Size - m_Size - 1;
  v16->m_bboxCache.m_pElements = m_pMemory;
  if ( v21 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 28 * v21);
  v22 = v31;
  p_x = (_DWORD *)&v16->m_bboxCache.m_Memory.m_pMemory[m_Size].mins.x;
  *p_x = -1048576000;
  p_x[1] = -1048576000;
  p_x[2] = 0;
  p_x[6] = v22;
  p_x[3] = 1098907648;
  p_x[4] = 1098907648;
  p_x[5] = 1116733440;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3F0
// Name: public: virtual class CPhysCollide __near * CPhysicsCollision::BBoxToCollide(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysCollideCompactSurface *__thiscall CPhysicsCollision::BBoxToCollide(
        CPhysicsCollision *this,
        const Vector *mins,
        Vector *maxs)
{
  CPhysCollideCompactSurface *result; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  CPhysCollideCompactSurface *pCollide; // [esp+18h] [ebp+Ch]

  if ( maxs->x == mins->x && maxs->y == mins->y && maxs->z == mins->z )
    return nullptr;
  result = CPhysicsCollision::GetBBoxCache(this, mins, maxs);
  if ( result == nullptr )
  {
    if ( this->m_bboxCache.m_Size == 0 )
      CPhysicsCollision::InitBBoxCache(this, a2: (int)&savedregs, a3: (int)maxs, a4: (int)this);
    pCollide = CPhysicsCollision::FastBboxCollide(
                 this,
                 a2: (int)maxs,
                 a3: (int)this,
                 pCollide: this->m_bboxCache.m_Memory.m_pMemory->pCollide,
                 mins,
                 maxs);
    CPhysicsCollision::AddBBoxCache(this, pCollide, mins, maxs);
    return pCollide;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6810
// Name: physcollideheader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *physcollideheader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<physcollideheader_t>(__formal: nullptr);
  physcollideheader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6820
// Name: compactsurfaceheader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *compactsurfaceheader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<compactsurfaceheader_t>(__formal: nullptr);
  compactsurfaceheader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0F0
// Name: struct datamap_t __near * DataMapInit<struct physcollideheader_t>(struct physcollideheader_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<physcollideheader_t>()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    nameHolder.m_pszBase = "physcollideheader_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 19;
    atexit(func: DataMapInit_physcollideheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  physcollideheader_t::m_DataMap.baseMap = nullptr;
  physcollideheader_t::m_DataMap.dataNumFields = 3;
  physcollideheader_t::m_DataMap.dataDesc = &dataDesc[1];
  return &physcollideheader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000A170
// Name: struct datamap_t __near * DataMapInit<struct compactsurfaceheader_t>(struct compactsurfaceheader_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<compactsurfaceheader_t>()
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    nameHolder_0.m_pszBase = "compactsurfaceheader_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 22;
    atexit(func: DataMapInit_compactsurfaceheader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  compactsurfaceheader_t::m_DataMap.baseMap = &physcollideheader_t::m_DataMap;
  compactsurfaceheader_t::m_DataMap.dataNumFields = 3;
  compactsurfaceheader_t::m_DataMap.dataDesc = &dataDesc_0[1];
  return &compactsurfaceheader_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C6830
// Name: _dynamic_initializer_for__fast_poly_convert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fast_poly_convert__()
{
  ConVar::ConVar(this: &fast_poly_convert, pName: "fast_poly_convert", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fast_poly_convert__);
}
