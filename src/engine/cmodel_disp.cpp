// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cmodel_disp.cpp
// Functions: 19
// ============================================================

#include "engine\cmodel_disp.h"

//------------------------------------------------------------------------------
// Address: 0x10153290
// Name: int CM_SurfacepropsForDisp(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_SurfacepropsForDisp(int index)
{
  return g_pDispCollTrees[index].m_nSurfaceProps[0];
}

//------------------------------------------------------------------------------
// Address: 0x101532B0
// Name: void CM_PreStab(struct TraceInfo_t __near *,unsigned short const __near *,int,class Vector __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_PreStab(
        TraceInfo_t *pTraceInfo,
        const unsigned __int16 *pDispList,
        int dispListCount,
        Vector *vStabDir,
        int collisionMask,
        int *contents)
{
  int v6; // ecx
  int v7; // edi
  CDispCollTree *v8; // esi

  v6 = dispListCount;
  if ( dispListCount != 0 )
  {
    v7 = 0;
    *vStabDir = g_pDispCollTrees[*pDispList].m_vecStabDir;
    *contents = 1;
    if ( dispListCount > 0 )
    {
      do
      {
        v8 = &g_pDispCollTrees[pDispList[v7]];
        if ( (collisionMask & v8->m_nContents) != 0 )
        {
          if ( CDispCollTree::PointInBounds(
                 this: v8,
                 vecBoxCenter: &pTraceInfo->m_start,
                 vecBoxMin: &pTraceInfo->m_mins,
                 vecBoxMax: &pTraceInfo->m_maxs,
                 bPoint: pTraceInfo->m_ispoint) )
          {
            *vStabDir = v8->m_vecStabDir;
            *contents = v8->m_nContents;
            return;
          }
          v6 = dispListCount;
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153370
// Name: void CM_Stab(struct TraceInfo_t __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_Stab(TraceInfo_t *pTraceInfo, const Vector *start, const Vector *vStabDir)
{
  float z; // edx
  float v4; // xmm2_4
  float v5; // xmm3_4
  float y; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  Vector p1f; // 0:^C.12

  pTraceInfo->m_trace.fraction = 1.0;
  pTraceInfo->m_trace.fractionleftsolid = 0.0;
  pTraceInfo->m_trace.surface = CCollisionBSPData::nullsurface;
  *(_WORD *)&pTraceInfo->m_trace.allsolid = 0;
  pTraceInfo->m_bDispHit = 0;
  pTraceInfo->m_DispStabDir = *vStabDir;
  p1f.y = pTraceInfo->m_end.y;
  p1f.x = pTraceInfo->m_end.x;
  z = pTraceInfo->m_end.z;
  pTraceInfo->m_start = *start;
  p1f.z = z;
  v4 = vStabDir->y * 99999.898;
  v5 = start->x + (float)(vStabDir->x * 99999.898);
  y = start->y;
  pTraceInfo->m_end.z = (float)(vStabDir->z * 99999.898) + start->z;
  pTraceInfo->m_end.x = v5;
  v7 = y + v4;
  pTraceInfo->m_end.y = v7;
  v8 = v7 - pTraceInfo->m_start.y;
  v9 = pTraceInfo->m_end.z - pTraceInfo->m_start.z;
  v10 = v5 - pTraceInfo->m_start.x;
  pTraceInfo->m_delta.x = v10;
  pTraceInfo->m_delta.y = v8;
  pTraceInfo->m_delta.z = v9;
  if ( v10 == 0.0 )
    v11 = 3.4028235e38;
  else
    v11 = 1.0 / v10;
  v12 = pTraceInfo->m_delta.y;
  if ( v12 == 0.0 )
    v13 = 3.4028235e38;
  else
    v13 = 1.0 / v12;
  v14 = pTraceInfo->m_delta.z;
  if ( v14 == 0.0 )
    v15 = 3.4028235e38;
  else
    v15 = 1.0 / v14;
  pTraceInfo->m_invDelta.x = v11;
  pTraceInfo->m_invDelta.y = v13;
  pTraceInfo->m_invDelta.z = v15;
  PushTraceVisits(pTraceInfo);
  CM_RecursiveHullCheck(pTraceInfo, num: 0, p1f: 0.0, p2f: 1.0);
  PopTraceVisits(pTraceInfo);
  pTraceInfo->m_end = p1f;
}

//------------------------------------------------------------------------------
// Address: 0x10153510
// Name: void CM_PostTraceToDispTree(struct TraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_PostTraceToDispTree(TraceInfo_t *pTraceInfo)
{
  if ( pTraceInfo->m_bDispHit != 0
    && (float)((float)((float)(pTraceInfo->m_trace.plane.normal.y * pTraceInfo->m_delta.y)
                     + (float)(pTraceInfo->m_trace.plane.normal.x * pTraceInfo->m_delta.x))
             + (float)(pTraceInfo->m_trace.plane.normal.z * pTraceInfo->m_delta.z)) > 0.0 )
  {
    *(_WORD *)&pTraceInfo->m_trace.allsolid = 257;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153560
// Name: void DispCollTrees_FreeLeafList(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispCollTrees_FreeLeafList(CCollisionBSPData *pBSPData)
{
  if ( pBSPData->map_dispList.m_pArray != nullptr )
  {
    pBSPData->map_dispList.m_pArray = nullptr;
    pBSPData->numdisplist = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153580
// Name: void CM_TraceToDispTree<1>(struct TraceInfo_t __near *,class CDispCollTree __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CM_TraceToDispTree<1>(
        TraceInfo_t *pTraceInfo@<ecx>,
        CDispCollTree *pDispTree@<edx>,
        int a3@<ebp>,
        float startFrac,
        float endFrac)
{
  CGameTrace *p_m_trace; // edi
  CDispCollTree *v7; // eax
  char dispFlags; // dl
  Vector m_start; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h] BYREF
  CDispCollTree *v11; // [esp+50h] [ebp-10h]
  int v12; // [esp+54h] [ebp-Ch]
  void *v13; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v12 = a3;
  v13 = retaddr;
  m_start = pTraceInfo->m_start;
  *(Vector *)&ray.m_Start.y = pTraceInfo->m_delta;
  p_m_trace = &pTraceInfo->m_trace;
  v11 = pDispTree;
  ray.m_Extents.y = 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  LOWORD(ray.m_Extents.z) = 257;
  if ( CDispCollTree::AABBTree_Ray(
         this: pDispTree,
         ray: (const Ray_t *)&m_start,
         vecInvDelta: &pTraceInfo->m_invDelta,
         pTrace: &pTraceInfo->m_trace,
         bSide: true) != 0 )
  {
    v7 = v11;
    pTraceInfo->m_bDispHit = 1;
    p_m_trace->contents = v7->m_nContents;
    dispFlags = p_m_trace->dispFlags;
    p_m_trace->surface.name = "**displacement**";
    p_m_trace->surface.flags = v7->m_nTexinfoFlags;
    if ( (dispFlags & 0x10) != 0 )
      p_m_trace->surface.surfaceProps = v7->m_nSurfaceProps[1];
    else
      p_m_trace->surface.surfaceProps = v7->m_nSurfaceProps[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153670
// Name: void CM_TraceToDispTree<0>(struct TraceInfo_t __near *,class CDispCollTree __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CM_TraceToDispTree<0>(
        TraceInfo_t *pTraceInfo@<ecx>,
        CDispCollTree *pDispTree@<edx>,
        int a3@<ebp>,
        float startFrac,
        float endFrac)
{
  float x; // xmm0_4
  CGameTrace *p_m_trace; // edi
  float z; // xmm0_4
  CDispCollTree *v9; // eax
  char dispFlags; // dl
  Vector m_start; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h]
  CDispCollTree *v13; // [esp+50h] [ebp-10h]
  _DWORD v14[3]; // [esp+54h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  v14[0] = a3;
  v14[1] = retaddr;
  m_start = pTraceInfo->m_start;
  *(Vector *)&ray.m_Start.y = pTraceInfo->m_delta;
  x = pTraceInfo->m_extents.x;
  ray.m_Extents.y = 0.0;
  p_m_trace = &pTraceInfo->m_trace;
  ray.m_StartOffset.y = x;
  ray.m_StartOffset.z = pTraceInfo->m_extents.y;
  z = pTraceInfo->m_extents.z;
  v13 = pDispTree;
  ray.m_StartOffset.w = z;
  LOWORD(ray.m_Extents.z) = 256;
  if ( CDispCollTree::AABBTree_SweepAABB(
         this: pDispTree,
         a2: COERCE_FLOAT(v14),
         ray: (const Ray_t *)&m_start,
         vecInvDelta: &pTraceInfo->m_invDelta,
         pTrace: &pTraceInfo->m_trace) )
  {
    v9 = v13;
    pTraceInfo->m_bDispHit = 1;
    p_m_trace->contents = v9->m_nContents;
    dispFlags = p_m_trace->dispFlags;
    p_m_trace->surface.name = "**displacement**";
    p_m_trace->surface.flags = v9->m_nTexinfoFlags;
    if ( (dispFlags & 0x10) != 0 )
      p_m_trace->surface.surfaceProps = v9->m_nSurfaceProps[1];
    else
      p_m_trace->surface.surfaceProps = v9->m_nSurfaceProps[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153760
// Name: public: void CDispLeafBuilder::WriteLeafList(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispLeafBuilder::WriteLeafList(CDispLeafBuilder *this, unsigned __int16 *pLeafList)
{
  CCollisionBSPData *m_pBSPData; // eax
  int v3; // edi
  int v4; // edx
  int v5; // esi
  int i; // edx
  cleaf_t *v7; // eax
  CCollisionBSPData *v8; // eax
  int v9; // esi
  unsigned __int16 v10; // dx
  cleaf_t *m_pArray; // eax
  int j; // esi
  int v13; // edx
  cleaf_t *v14; // eax
  int count; // [esp+Ch] [ebp-4h]

  m_pBSPData = this->m_pBSPData;
  v3 = 0;
  v4 = 0;
  if ( this->m_pBSPData->numleafs > 0 )
  {
    v5 = 0;
    do
    {
      m_pBSPData->map_leafs.m_pArray[v5].dispCount = 0;
      m_pBSPData = this->m_pBSPData;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pBSPData->numleafs );
  }
  for ( i = 0; i < this->m_dispList.m_Size; ++v7->dispCount )
    v7 = &this->m_pBSPData->map_leafs.m_pArray[this->m_dispList.m_Memory.m_pMemory[i++]];
  v8 = this->m_pBSPData;
  v9 = 0;
  if ( this->m_pBSPData->numleafs > 0 )
  {
    v10 = 0;
    do
    {
      m_pArray = v8->map_leafs.m_pArray;
      m_pArray[v3].dispListStart = v10;
      v10 += m_pArray[v3].dispCount;
      m_pArray[v3].dispCount = 0;
      v8 = this->m_pBSPData;
      ++v9;
      ++v3;
    }
    while ( v9 < this->m_pBSPData->numleafs );
  }
  for ( j = 0; j < this->m_leafCount.m_Size; ++j )
  {
    v13 = 0;
    count = this->m_leafCount.m_Memory.m_pMemory[j];
    if ( this->m_leafCount.m_Memory.m_pMemory[j] != 0 )
    {
      do
      {
        v14 = &this->m_pBSPData->map_leafs.m_pArray[this->m_dispList.m_Memory.m_pMemory[v13
                                                                                      + this->m_firstIndex.m_Memory.m_pMemory[j]]];
        ++v13;
        pLeafList[v14->dispCount++ + v14->dispListStart] = j;
      }
      while ( v13 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153860
// Name: class CPhysCollide __near * CM_PhysCollideForDisp(int)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__cdecl CM_PhysCollideForDisp(int index)
{
  if ( index < 0 || index >= g_DispCollTreeCount )
    return nullptr;
  else
    return g_TerrainList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x10153890
// Name: void CM_TestInDispTree(struct TraceInfo_t __near *,unsigned short const __near *,int,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_TestInDispTree(
        TraceInfo_t *pTraceInfo,
        const unsigned __int16 *pDispList,
        int dispListCount,
        const Vector *traceStart,
        const Vector *boxMin,
        const Vector *boxMax,
        int collisionMask,
        CGameTrace *pTrace)
{
  const Vector *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm0_4
  int m_nCheckDepth; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  unsigned int *m_pMemory; // edx
  const Vector *v16; // eax
  int v17; // ebx
  int v18; // esi
  alignedbbox_t *v19; // eax
  unsigned int *v20; // ecx
  CDispCollTree *v21; // esi
  CGameTrace *v22; // eax
  Vector absMins; // [esp+0h] [ebp-1Ch] BYREF
  Vector absMaxs; // [esp+Ch] [ebp-10h] BYREF
  unsigned int *pCounters; // [esp+18h] [ebp-4h]

  if ( boxMin->x == 0.0
    && boxMin->y == 0.0
    && boxMin->z == 0.0
    && boxMax->x == 0.0
    && boxMax->y == 0.0
    && boxMax->z == 0.0 )
  {
LABEL_13:
    v8 = traceStart;
    goto LABEL_14;
  }
  v8 = traceStart;
  v9 = boxMin->z + traceStart->z;
  v10 = boxMax->y + traceStart->y;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  absMins.x = traceStart->x + boxMin->x;
  v12 = boxMin->y + traceStart->y;
  absMins.z = v9;
  v13 = boxMax->x + traceStart->x;
  absMaxs.y = v10;
  v14 = boxMax->z + traceStart->z;
  absMins.y = v12;
  absMaxs.x = v13;
  absMaxs.z = v14;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v16 = (const Vector *)pTraceInfo->m_Count[m_nCheckDepth];
  v17 = 0;
  pCounters = m_pMemory;
  boxMin = v16;
  if ( dispListCount <= 0 )
  {
LABEL_14:
    CM_PreStab(pTraceInfo, pDispList, dispListCount, vStabDir: &absMins, collisionMask, contents: (int *)&boxMin);
    CM_Stab(pTraceInfo, start: v8, vStabDir: &absMins);
    if ( pTraceInfo->m_bDispHit != 0 && pTraceInfo->m_trace.startsolid )
    {
      pTraceInfo->m_trace.allsolid = true;
      pTraceInfo->m_trace.fraction = 0.0;
      pTraceInfo->m_trace.fractionleftsolid = 0.0;
    }
    else
    {
      pTraceInfo->m_trace.fraction = 1.0;
      *(_WORD *)&pTraceInfo->m_trace.allsolid = 0;
      pTraceInfo->m_trace.contents = 0;
      pTraceInfo->m_trace.fractionleftsolid = 0.0;
    }
    return;
  }
  while ( 1 )
  {
    v18 = pDispList[v17];
    v19 = &g_pDispBounds[v18];
    if ( (collisionMask & v19->dispContents) != 0 )
    {
      v20 = &pCounters[v19->dispCounter];
      if ( (const Vector *)*v20 != boxMin )
      {
        *v20 = (unsigned int)boxMin;
        if ( IsBoxIntersectingBox(boxMin1: &absMins, boxMax1: &absMaxs, boxMin2: &v19->mins, boxMax2: &v19->maxs) )
        {
          v21 = &g_pDispCollTrees[v18];
          if ( CDispCollTree::AABBTree_IntersectAABB(this: v21, &absMins, &absMaxs) )
            break;
        }
      }
    }
    if ( ++v17 >= dispListCount )
      goto LABEL_13;
  }
  v22 = pTrace;
  *(_WORD *)&pTrace->allsolid = 257;
  v22->fraction = 0.0;
  v22->fractionleftsolid = 0.0;
  v22->contents = v21->m_nContents;
}

//------------------------------------------------------------------------------
// Address: 0x10153AB0
// Name: void CM_DestroyDispPhysCollide(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DestroyDispPhysCollide()
{
  int *m_pMemory; // eax
  int v1; // esi
  struct CPhysCollide **v2; // eax

  m_pMemory = g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory;
  g_VirtualTerrain.m_dispHullOffset.m_Size = 0;
  if ( g_VirtualTerrain.m_dispHullOffset.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory = nullptr;
    }
    g_VirtualTerrain.m_dispHullOffset.m_Memory.m_nAllocationCount = 0;
  }
  g_VirtualTerrain.m_dispHullOffset.m_pElements = m_pMemory;
  free(pMem: g_VirtualTerrain.m_pDispHullData);
  v1 = g_TerrainList.m_Size - 1;
  for ( g_VirtualTerrain.m_pDispHullData = nullptr; v1 >= 0; --v1 )
    physcollision->DestroyCollide(this: physcollision, a2: g_TerrainList.m_Memory.m_pMemory[v1]);
  g_TerrainList.m_Size = 0;
  if ( g_TerrainList.m_Memory.m_nGrowSize < 0 )
  {
    g_TerrainList.m_pElements = g_TerrainList.m_Memory.m_pMemory;
  }
  else
  {
    v2 = g_TerrainList.m_Memory.m_pMemory;
    if ( g_TerrainList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TerrainList.m_Memory.m_pMemory);
      v2 = nullptr;
      g_TerrainList.m_Memory.m_pMemory = nullptr;
    }
    g_TerrainList.m_Memory.m_nAllocationCount = 0;
    g_TerrainList.m_pElements = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153B80
// Name: public: void CDispLeafBuilder::BuildLeafListForDisplacement(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispLeafBuilder::BuildLeafListForDisplacement(CDispLeafBuilder *this, int index)
{
  CDispCollTree *v3; // eax
  int headnode; // edx
  float z; // xmm0_4
  int v6; // ecx
  int v7; // eax
  int m_Size; // edi
  unsigned __int16 v9; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v12; // eax
  unsigned __int16 *v13; // eax
  int v14; // edx
  cnode_t *map_rootnode; // ecx
  const cplane_t *plane; // eax
  cnode_t *v17; // esi
  unsigned __int8 type; // cl
  float dist; // xmm0_4
  int v20; // ecx
  char v21; // al
  int v22; // ecx
  int v23; // eax
  _DWORD v24[1024]; // [esp+4h] [ebp-1024h]
  float emaxs[3]; // [esp+1004h] [ebp-24h] BYREF
  float emins[3]; // [esp+1010h] [ebp-18h] BYREF
  int v27; // [esp+101Ch] [ebp-Ch]
  int v28; // [esp+1020h] [ebp-8h]
  int v29; // [esp+1024h] [ebp-4h]

  v3 = &g_pDispCollTrees[index];
  if ( v3 != nullptr && v3->m_nPower != 0 )
  {
    this->m_firstIndex.m_Memory.m_pMemory[index] = this->m_dispList.m_Size;
    this->m_leafCount.m_Memory.m_pMemory[index] = 0;
    headnode = this->m_pBSPData->map_cmodels.m_pArray->headnode;
    emins[0] = v3->m_mins.x;
    emins[1] = v3->m_mins.y;
    emins[2] = v3->m_mins.z;
    emaxs[0] = v3->m_maxs.x;
    emaxs[1] = v3->m_maxs.y;
    z = v3->m_maxs.z;
    v6 = 0;
    v29 = 1;
    v24[0] = headnode;
    emaxs[2] = z;
    while ( 1 )
    {
      v7 = v24[v6];
      v28 = (v6 + 1) % 1024;
      if ( v7 >= 0 )
      {
        v14 = v7;
        map_rootnode = this->m_pBSPData->map_rootnode;
        plane = map_rootnode[v7].plane;
        v17 = &map_rootnode[v14];
        type = plane->type;
        if ( type >= 3u )
        {
          v21 = BoxOnPlaneSide(emins, emaxs, p: plane);
        }
        else
        {
          dist = plane->dist;
          v20 = type;
          if ( emins[v20] < dist )
          {
            if ( dist < emaxs[v20] )
              v21 = 3;
            else
              v21 = 2;
          }
          else
          {
            v21 = 1;
          }
        }
        if ( (v21 & 1) != 0 )
        {
          v22 = v29;
          v24[v29] = v17->children[0];
          v29 = (v22 + 1) % 1024;
        }
        if ( (v21 & 2) != 0 )
        {
          v23 = v29;
          v24[v29] = v17->children[1];
          v29 = (v23 + 1) % 1024;
        }
      }
      else
      {
        m_Size = this->m_dispList.m_Size;
        v9 = -1 - v7;
        m_nAllocationCount = this->m_dispList.m_Memory.m_nAllocationCount;
        v27 = v9;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<wchar_t,int> *)&this->m_dispList,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_dispList.m_Size;
        m_pMemory = this->m_dispList.m_Memory.m_pMemory;
        v12 = this->m_dispList.m_Size - m_Size - 1;
        this->m_dispList.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v12);
        v13 = &this->m_dispList.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v27;
        ++this->m_leafCount.m_Memory.m_pMemory[index];
      }
      if ( v28 == v29 )
        break;
      v6 = v28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153D70
// Name: public: virtual void CVirtualTerrain::GetWorldspaceBounds(void __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetWorldspaceBounds(
        CVirtualTerrain *this,
        void *userData,
        Vector *pMins,
        Vector *pMaxs)
{
  alignedbbox_t *v4; // eax

  v4 = &g_pDispBounds[(_DWORD)userData];
  *pMins = v4->mins.Vector;
  *pMaxs = v4->maxs.Vector;
}

//------------------------------------------------------------------------------
// Address: 0x10153DB0
// Name: public: virtual void CVirtualTerrain::GetTrianglesInSphere(void __near *,class Vector const __near &,float,struct virtualmeshtrianglelist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetTrianglesInSphere(
        CVirtualTerrain *this,
        void *userData,
        const Vector *center,
        float radius,
        virtualmeshtrianglelist_t *pList)
{
  pList->triangleCount = CDispCollTree::AABBTree_GetTrisInSphere(
                           this: &g_pDispCollTrees[(_DWORD)userData],
                           center,
                           radius,
                           pIndexOut: pList->triangleIndices,
                           indexMax: 0xC00u);
}

//------------------------------------------------------------------------------
// Address: 0x10153DF0
// Name: public: virtual void CVirtualTerrain::GetVirtualMesh(void __near *,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetVirtualMesh(CVirtualTerrain *this, void *userData, virtualmeshlist_t *pList)
{
  unsigned __int8 *m_pDispHullData; // ecx
  int *m_pMemory; // eax
  bool v6; // sf
  int *v7; // eax

  CDispCollTree::GetVirtualMeshList(this: &g_pDispCollTrees[(_DWORD)userData], pList);
  pList->pHull = nullptr;
  m_pDispHullData = this->m_pDispHullData;
  if ( m_pDispHullData != nullptr )
  {
    m_pMemory = this->m_dispHullOffset.m_Memory.m_pMemory;
    v6 = m_pMemory[(_DWORD)userData] < 0;
    v7 = &m_pMemory[(_DWORD)userData];
    if ( !v6 )
      pList->pHull = &m_pDispHullData[*v7];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153E40
// Name: public: CDispLeafBuilder::CDispLeafBuilder(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
CDispLeafBuilder *__thiscall CDispLeafBuilder::CDispLeafBuilder(CDispLeafBuilder *this, CCollisionBSPData *pBSPData)
{
  unsigned __int16 *m_pMemory; // edx
  unsigned __int16 *v4; // eax
  int i; // eax
  int v7; // [esp-4h] [ebp-10h]
  int v8; // [esp-4h] [ebp-10h]

  this->m_dispList.m_Memory.m_pMemory = nullptr;
  this->m_dispList.m_Memory.m_nAllocationCount = 0;
  this->m_dispList.m_Memory.m_nGrowSize = 0;
  this->m_dispList.m_Size = 0;
  this->m_dispList.m_pElements = nullptr;
  this->m_firstIndex.m_Memory.m_pMemory = nullptr;
  this->m_firstIndex.m_Memory.m_nAllocationCount = 0;
  this->m_firstIndex.m_Memory.m_nGrowSize = 0;
  this->m_firstIndex.m_Size = 0;
  this->m_firstIndex.m_pElements = nullptr;
  this->m_leafCount.m_Memory.m_pMemory = nullptr;
  this->m_leafCount.m_Memory.m_nAllocationCount = 0;
  this->m_leafCount.m_Memory.m_nGrowSize = 0;
  this->m_leafCount.m_Size = 0;
  this->m_leafCount.m_pElements = nullptr;
  this->m_pBSPData = pBSPData;
  if ( this->m_dispList.m_Memory.m_nAllocationCount < 4096 && this->m_dispList.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_dispList.m_Memory.m_pMemory;
    this->m_dispList.m_Memory.m_nAllocationCount = 4096;
    if ( m_pMemory != nullptr )
      v4 = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 0x2000);
    else
      v4 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
    this->m_dispList.m_Memory.m_pMemory = v4;
  }
  this->m_dispList.m_pElements = this->m_dispList.m_Memory.m_pMemory;
  v7 = g_DispCollTreeCount;
  this->m_leafCount.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_leafCount,
    elem: 0,
    num: v7);
  v8 = g_DispCollTreeCount;
  this->m_firstIndex.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_firstIndex,
    elem: 0,
    num: v8);
  for ( i = 0; i < g_DispCollTreeCount; ++i )
  {
    this->m_leafCount.m_Memory.m_pMemory[i] = 0;
    this->m_firstIndex.m_Memory.m_pMemory[i] = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10153F20
// Name: void CM_DispTreeLeafnum(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DispTreeLeafnum(CCollisionBSPData *pBSPData)
{
  int v1; // eax
  int v2; // ecx
  int i; // edi
  int m_Size; // edi
  unsigned __int16 *v5; // eax
  CDispLeafBuilder leafBuilder; // [esp+0h] [ebp-40h] BYREF

  if ( g_DispCollTreeCount != 0 )
  {
    v1 = 0;
    if ( pBSPData->numleafs > 0 )
    {
      v2 = 0;
      do
      {
        pBSPData->map_leafs.m_pArray[v2].dispCount = 0;
        ++v1;
        ++v2;
      }
      while ( v1 < pBSPData->numleafs );
    }
    CDispLeafBuilder::CDispLeafBuilder(this: &leafBuilder, pBSPData);
    for ( i = 0; i < g_DispCollTreeCount; ++i )
      CDispLeafBuilder::BuildLeafListForDisplacement(this: &leafBuilder, index: i);
    m_Size = leafBuilder.m_dispList.m_Size;
    v5 = (unsigned __int16 *)Hunk_AllocName(
                               size: 2 * leafBuilder.m_dispList.m_Size,
                               name: "CM_DispTreeLeafnum",
                               bClear: false);
    pBSPData->map_dispList.m_pArray = v5;
    pBSPData->numdisplist = m_Size;
    CDispLeafBuilder::WriteLeafList(this: &leafBuilder, pLeafList: v5);
    if ( leafBuilder.m_leafCount.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_leafCount.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_leafCount.m_Memory.m_pMemory);
    if ( leafBuilder.m_firstIndex.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_firstIndex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_firstIndex.m_Memory.m_pMemory);
    if ( leafBuilder.m_dispList.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_dispList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_dispList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154060
// Name: public: void CVirtualTerrain::LevelInit(struct dphysdisp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::LevelInit(CVirtualTerrain *this, dphysdisp_t *pLump, int lumpSize)
{
  unsigned int v3; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *p_m_dispHullOffset; // edi
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // [esp-8h] [ebp-14h]

  v3 = 0;
  if ( pLump != nullptr )
  {
    p_m_dispHullOffset = &this->m_dispHullOffset;
    v7 = g_DispCollTreeCount;
    this->m_dispHullOffset.m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_dispHullOffset,
      elem: 0,
      num: v7);
    v5 = 0;
    if ( pLump->numDisplacements != 0 )
    {
      do
      {
        if ( pLump[v5 + 1].numDisplacements == 0xFFFF )
        {
          p_m_dispHullOffset->m_Memory.m_pMemory[v5] = -1;
        }
        else
        {
          p_m_dispHullOffset->m_Memory.m_pMemory[v5] = v3;
          v3 += pLump[v5 + 1].numDisplacements;
        }
        ++v5;
      }
      while ( v5 < pLump->numDisplacements );
    }
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v3);
    this->m_pDispHullData = v6;
    memcpy(dst: v6, src: (unsigned __int8 *)&pLump[pLump->numDisplacements + 1], count: v3);
  }
  else
  {
    this->m_pDispHullData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154100
// Name: void CM_CreateDispPhysCollide(struct dphysdisp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_CreateDispPhysCollide(dphysdisp_t *pDispLump, int dispLumpSize)
{
  int v2; // ebx
  int i; // esi
  struct CPhysCollide **v4; // edi
  virtualmeshparams_t params; // [esp+8h] [ebp-Ch] BYREF

  CVirtualTerrain::LevelInit(this: &g_VirtualTerrain, pLump: pDispLump, lumpSize: dispLumpSize);
  v2 = 0;
  g_TerrainList.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_TerrainList,
    elem: 0,
    num: g_DispCollTreeCount);
  for ( i = 0; i < g_DispCollTreeCount; ++v2 )
  {
    if ( &g_pDispCollTrees[v2] != nullptr && (g_pDispCollTrees[v2].m_nFlags & 2) != 0 )
    {
      g_TerrainList.m_Memory.m_pMemory[i] = nullptr;
    }
    else
    {
      v4 = &g_TerrainList.m_Memory.m_pMemory[i];
      params.buildOuterHull = dispLumpSize <= 0;
      params.pMeshEventHandler = &g_VirtualTerrain;
      params.userData = (void *)i;
      *v4 = physcollision->CreateVirtualMesh(this: physcollision, a2: &params);
    }
    ++i;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101533F0
// Name: int CM_SurfacepropsForDisp(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_SurfacepropsForDisp(int index)
{
  return g_pDispCollTrees[index].m_nSurfaceProps[0];
}

//------------------------------------------------------------------------------
// Address: 0x10153410
// Name: void CM_PreStab(struct TraceInfo_t __near *,unsigned short const __near *,int,class Vector __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_PreStab(
        TraceInfo_t *pTraceInfo,
        const unsigned __int16 *pDispList,
        int dispListCount,
        Vector *vStabDir,
        int collisionMask,
        int *contents)
{
  int v6; // ecx
  int v7; // edi
  CDispCollTree *v8; // esi

  v6 = dispListCount;
  if ( dispListCount != 0 )
  {
    v7 = 0;
    *vStabDir = g_pDispCollTrees[*pDispList].m_vecStabDir;
    *contents = 1;
    if ( dispListCount > 0 )
    {
      do
      {
        v8 = &g_pDispCollTrees[pDispList[v7]];
        if ( (collisionMask & v8->m_nContents) != 0 )
        {
          if ( CDispCollTree::PointInBounds(
                 this: v8,
                 vecBoxCenter: &pTraceInfo->m_start,
                 vecBoxMin: &pTraceInfo->m_mins,
                 vecBoxMax: &pTraceInfo->m_maxs,
                 bPoint: pTraceInfo->m_ispoint) )
          {
            *vStabDir = v8->m_vecStabDir;
            *contents = v8->m_nContents;
            return;
          }
          v6 = dispListCount;
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101534D0
// Name: void CM_Stab(struct TraceInfo_t __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_Stab(TraceInfo_t *pTraceInfo, const Vector *start, const Vector *vStabDir)
{
  float z; // edx
  float v4; // xmm2_4
  float v5; // xmm3_4
  float y; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  Vector p1f; // 0:^C.12

  pTraceInfo->m_trace.fraction = 1.0;
  pTraceInfo->m_trace.fractionleftsolid = 0.0;
  pTraceInfo->m_trace.surface = CCollisionBSPData::nullsurface;
  *(_WORD *)&pTraceInfo->m_trace.allsolid = 0;
  pTraceInfo->m_bDispHit = 0;
  pTraceInfo->m_DispStabDir = *vStabDir;
  p1f.y = pTraceInfo->m_end.y;
  p1f.x = pTraceInfo->m_end.x;
  z = pTraceInfo->m_end.z;
  pTraceInfo->m_start = *start;
  p1f.z = z;
  v4 = vStabDir->y * 99999.898;
  v5 = start->x + (float)(vStabDir->x * 99999.898);
  y = start->y;
  pTraceInfo->m_end.z = (float)(vStabDir->z * 99999.898) + start->z;
  pTraceInfo->m_end.x = v5;
  v7 = y + v4;
  pTraceInfo->m_end.y = v7;
  v8 = v7 - pTraceInfo->m_start.y;
  v9 = pTraceInfo->m_end.z - pTraceInfo->m_start.z;
  v10 = v5 - pTraceInfo->m_start.x;
  pTraceInfo->m_delta.x = v10;
  pTraceInfo->m_delta.y = v8;
  pTraceInfo->m_delta.z = v9;
  if ( v10 == 0.0 )
    v11 = 3.4028235e38;
  else
    v11 = 1.0 / v10;
  v12 = pTraceInfo->m_delta.y;
  if ( v12 == 0.0 )
    v13 = 3.4028235e38;
  else
    v13 = 1.0 / v12;
  v14 = pTraceInfo->m_delta.z;
  if ( v14 == 0.0 )
    v15 = 3.4028235e38;
  else
    v15 = 1.0 / v14;
  pTraceInfo->m_invDelta.x = v11;
  pTraceInfo->m_invDelta.y = v13;
  pTraceInfo->m_invDelta.z = v15;
  PushTraceVisits(pTraceInfo);
  CM_RecursiveHullCheck(pTraceInfo, num: 0, p1f: 0.0, p2f: 1.0);
  PopTraceVisits(pTraceInfo);
  pTraceInfo->m_end = p1f;
}

//------------------------------------------------------------------------------
// Address: 0x101536C0
// Name: void DispCollTrees_FreeLeafList(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispCollTrees_FreeLeafList(CCollisionBSPData *pBSPData)
{
  if ( pBSPData->map_dispList.m_pArray != nullptr )
  {
    pBSPData->map_dispList.m_pArray = nullptr;
    pBSPData->numdisplist = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101536E0
// Name: void CM_TraceToDispTree<1>(struct TraceInfo_t __near *,class CDispCollTree __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CM_TraceToDispTree<1>(
        TraceInfo_t *pTraceInfo@<ecx>,
        CDispCollTree *pDispTree@<edx>,
        int a3@<ebp>,
        float startFrac,
        float endFrac)
{
  CGameTrace *p_m_trace; // edi
  CDispCollTree *v7; // eax
  char dispFlags; // dl
  Vector m_start; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h] BYREF
  CDispCollTree *v11; // [esp+50h] [ebp-10h]
  int v12; // [esp+54h] [ebp-Ch]
  void *v13; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v12 = a3;
  v13 = retaddr;
  m_start = pTraceInfo->m_start;
  *(Vector *)&ray.m_Start.y = pTraceInfo->m_delta;
  p_m_trace = &pTraceInfo->m_trace;
  v11 = pDispTree;
  ray.m_Extents.y = 0.0;
  memset(&ray.m_StartOffset.y, 0, 12);
  LOWORD(ray.m_Extents.z) = 257;
  if ( CDispCollTree::AABBTree_Ray(
         this: pDispTree,
         ray: (const Ray_t *)&m_start,
         vecInvDelta: &pTraceInfo->m_invDelta,
         pTrace: &pTraceInfo->m_trace,
         bSide: true) )
  {
    v7 = v11;
    pTraceInfo->m_bDispHit = 1;
    p_m_trace->contents = v7->m_nContents;
    dispFlags = p_m_trace->dispFlags;
    p_m_trace->surface.name = "**displacement**";
    p_m_trace->surface.flags = v7->m_nTexinfoFlags;
    if ( (dispFlags & 0x10) != 0 )
      p_m_trace->surface.surfaceProps = v7->m_nSurfaceProps[1];
    else
      p_m_trace->surface.surfaceProps = v7->m_nSurfaceProps[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101537D0
// Name: void CM_TraceToDispTree<0>(struct TraceInfo_t __near *,class CDispCollTree __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CM_TraceToDispTree<0>(
        TraceInfo_t *pTraceInfo@<ecx>,
        CDispCollTree *pDispTree@<edx>,
        int a3@<ebp>,
        float startFrac,
        float endFrac)
{
  float x; // xmm0_4
  CGameTrace *p_m_trace; // edi
  float z; // xmm0_4
  CDispCollTree *v9; // eax
  char dispFlags; // dl
  Vector m_start; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-60h]
  CDispCollTree *v13; // [esp+50h] [ebp-10h]
  int v14; // [esp+54h] [ebp-Ch]
  void *v15; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v14 = a3;
  v15 = retaddr;
  m_start = pTraceInfo->m_start;
  *(Vector *)&ray.m_Start.y = pTraceInfo->m_delta;
  x = pTraceInfo->m_extents.x;
  ray.m_Extents.y = 0.0;
  p_m_trace = &pTraceInfo->m_trace;
  ray.m_StartOffset.y = x;
  ray.m_StartOffset.z = pTraceInfo->m_extents.y;
  z = pTraceInfo->m_extents.z;
  v13 = pDispTree;
  ray.m_StartOffset.w = z;
  LOWORD(ray.m_Extents.z) = 256;
  if ( CDispCollTree::AABBTree_SweepAABB(
         this: pDispTree,
         ray: (const Ray_t *)&m_start,
         vecInvDelta: &pTraceInfo->m_invDelta,
         pTrace: &pTraceInfo->m_trace) )
  {
    v9 = v13;
    pTraceInfo->m_bDispHit = 1;
    p_m_trace->contents = v9->m_nContents;
    dispFlags = p_m_trace->dispFlags;
    p_m_trace->surface.name = "**displacement**";
    p_m_trace->surface.flags = v9->m_nTexinfoFlags;
    if ( (dispFlags & 0x10) != 0 )
      p_m_trace->surface.surfaceProps = v9->m_nSurfaceProps[1];
    else
      p_m_trace->surface.surfaceProps = v9->m_nSurfaceProps[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101538C0
// Name: public: void CDispLeafBuilder::WriteLeafList(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispLeafBuilder::WriteLeafList(CDispLeafBuilder *this, unsigned __int16 *pLeafList)
{
  CCollisionBSPData *m_pBSPData; // eax
  int v3; // edi
  int v4; // edx
  int v5; // esi
  int i; // edx
  cleaf_t *v7; // eax
  CCollisionBSPData *v8; // eax
  int v9; // esi
  unsigned __int16 v10; // dx
  cleaf_t *m_pArray; // eax
  int j; // esi
  int v13; // edx
  cleaf_t *v14; // eax
  int count; // [esp+Ch] [ebp-4h]

  m_pBSPData = this->m_pBSPData;
  v3 = 0;
  v4 = 0;
  if ( this->m_pBSPData->numleafs > 0 )
  {
    v5 = 0;
    do
    {
      m_pBSPData->map_leafs.m_pArray[v5].dispCount = 0;
      m_pBSPData = this->m_pBSPData;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pBSPData->numleafs );
  }
  for ( i = 0; i < this->m_dispList.m_Size; ++v7->dispCount )
    v7 = &this->m_pBSPData->map_leafs.m_pArray[this->m_dispList.m_Memory.m_pMemory[i++]];
  v8 = this->m_pBSPData;
  v9 = 0;
  if ( this->m_pBSPData->numleafs > 0 )
  {
    v10 = 0;
    do
    {
      m_pArray = v8->map_leafs.m_pArray;
      m_pArray[v3].dispListStart = v10;
      v10 += m_pArray[v3].dispCount;
      m_pArray[v3].dispCount = 0;
      v8 = this->m_pBSPData;
      ++v9;
      ++v3;
    }
    while ( v9 < this->m_pBSPData->numleafs );
  }
  for ( j = 0; j < this->m_leafCount.m_Size; ++j )
  {
    v13 = 0;
    count = this->m_leafCount.m_Memory.m_pMemory[j];
    if ( this->m_leafCount.m_Memory.m_pMemory[j] != 0 )
    {
      do
      {
        v14 = &this->m_pBSPData->map_leafs.m_pArray[this->m_dispList.m_Memory.m_pMemory[v13
                                                                                      + this->m_firstIndex.m_Memory.m_pMemory[j]]];
        ++v13;
        pLeafList[v14->dispCount++ + v14->dispListStart] = j;
      }
      while ( v13 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101539C0
// Name: class CPhysCollide __near * CM_PhysCollideForDisp(int)
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__cdecl CM_PhysCollideForDisp(int index)
{
  if ( index < 0 || index >= g_DispCollTreeCount )
    return nullptr;
  else
    return g_TerrainList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x101539F0
// Name: void CM_TestInDispTree(struct TraceInfo_t __near *,unsigned short const __near *,int,class Vector const __near &,class Vector const __near &,class Vector const __near &,int,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_TestInDispTree(
        TraceInfo_t *pTraceInfo,
        const unsigned __int16 *pDispList,
        int dispListCount,
        const Vector *traceStart,
        const Vector *boxMin,
        const Vector *boxMax,
        int collisionMask,
        CGameTrace *pTrace)
{
  const Vector *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm0_4
  int m_nCheckDepth; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  unsigned int *m_pMemory; // edx
  const Vector *v16; // eax
  int v17; // ebx
  int v18; // esi
  alignedbbox_t *v19; // eax
  unsigned int *v20; // ecx
  CDispCollTree *v21; // esi
  CGameTrace *v22; // eax
  Vector absMins; // [esp+0h] [ebp-1Ch] BYREF
  Vector absMaxs; // [esp+Ch] [ebp-10h] BYREF
  unsigned int *pCounters; // [esp+18h] [ebp-4h]

  if ( boxMin->x == 0.0
    && boxMin->y == 0.0
    && boxMin->z == 0.0
    && boxMax->x == 0.0
    && boxMax->y == 0.0
    && boxMax->z == 0.0 )
  {
LABEL_13:
    v8 = traceStart;
    goto LABEL_14;
  }
  v8 = traceStart;
  v9 = boxMin->z + traceStart->z;
  v10 = boxMax->y + traceStart->y;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  absMins.x = traceStart->x + boxMin->x;
  v12 = boxMin->y + traceStart->y;
  absMins.z = v9;
  v13 = boxMax->x + traceStart->x;
  absMaxs.y = v10;
  v14 = boxMax->z + traceStart->z;
  absMins.y = v12;
  absMaxs.x = v13;
  absMaxs.z = v14;
  m_pMemory = pTraceInfo->m_DispCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v16 = (const Vector *)pTraceInfo->m_Count[m_nCheckDepth];
  v17 = 0;
  pCounters = m_pMemory;
  boxMin = v16;
  if ( dispListCount <= 0 )
  {
LABEL_14:
    CM_PreStab(pTraceInfo, pDispList, dispListCount, vStabDir: &absMins, collisionMask, contents: (int *)&boxMin);
    CM_Stab(pTraceInfo, start: v8, vStabDir: &absMins);
    if ( pTraceInfo->m_bDispHit != 0 && pTraceInfo->m_trace.startsolid )
    {
      pTraceInfo->m_trace.allsolid = true;
      pTraceInfo->m_trace.fraction = 0.0;
      pTraceInfo->m_trace.fractionleftsolid = 0.0;
    }
    else
    {
      pTraceInfo->m_trace.fraction = 1.0;
      *(_WORD *)&pTraceInfo->m_trace.allsolid = 0;
      pTraceInfo->m_trace.contents = 0;
      pTraceInfo->m_trace.fractionleftsolid = 0.0;
    }
    return;
  }
  while ( 1 )
  {
    v18 = pDispList[v17];
    v19 = &g_pDispBounds[v18];
    if ( (collisionMask & v19->dispContents) != 0 )
    {
      v20 = &pCounters[v19->dispCounter];
      if ( (const Vector *)*v20 != boxMin )
      {
        *v20 = (unsigned int)boxMin;
        if ( IsBoxIntersectingBox(boxMin1: &absMins, boxMax1: &absMaxs, boxMin2: &v19->mins, boxMax2: &v19->maxs) )
        {
          v21 = &g_pDispCollTrees[v18];
          if ( CDispCollTree::AABBTree_IntersectAABB(this: v21, &absMins, &absMaxs) )
            break;
        }
      }
    }
    if ( ++v17 >= dispListCount )
      goto LABEL_13;
  }
  v22 = pTrace;
  *(_WORD *)&pTrace->allsolid = 257;
  v22->fraction = 0.0;
  v22->fractionleftsolid = 0.0;
  v22->contents = v21->m_nContents;
}

//------------------------------------------------------------------------------
// Address: 0x10153C10
// Name: void CM_DestroyDispPhysCollide(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DestroyDispPhysCollide()
{
  int *m_pMemory; // eax
  int v1; // esi
  struct CPhysCollide **v2; // eax

  m_pMemory = g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory;
  g_VirtualTerrain.m_dispHullOffset.m_Size = 0;
  if ( g_VirtualTerrain.m_dispHullOffset.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_VirtualTerrain.m_dispHullOffset.m_Memory.m_pMemory = nullptr;
    }
    g_VirtualTerrain.m_dispHullOffset.m_Memory.m_nAllocationCount = 0;
  }
  g_VirtualTerrain.m_dispHullOffset.m_pElements = m_pMemory;
  free(pMem: g_VirtualTerrain.m_pDispHullData);
  v1 = g_TerrainList.m_Size - 1;
  for ( g_VirtualTerrain.m_pDispHullData = nullptr; v1 >= 0; --v1 )
    physcollision->DestroyCollide(this: physcollision, a2: g_TerrainList.m_Memory.m_pMemory[v1]);
  g_TerrainList.m_Size = 0;
  if ( g_TerrainList.m_Memory.m_nGrowSize < 0 )
  {
    g_TerrainList.m_pElements = g_TerrainList.m_Memory.m_pMemory;
  }
  else
  {
    v2 = g_TerrainList.m_Memory.m_pMemory;
    if ( g_TerrainList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TerrainList.m_Memory.m_pMemory);
      v2 = nullptr;
      g_TerrainList.m_Memory.m_pMemory = nullptr;
    }
    g_TerrainList.m_Memory.m_nAllocationCount = 0;
    g_TerrainList.m_pElements = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153CE0
// Name: public: void CDispLeafBuilder::BuildLeafListForDisplacement(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispLeafBuilder::BuildLeafListForDisplacement(CDispLeafBuilder *this, int index)
{
  CDispCollTree *v3; // eax
  int headnode; // edx
  float z; // xmm0_4
  int v6; // ecx
  int v7; // eax
  int m_Size; // edi
  unsigned __int16 v9; // cx
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v12; // eax
  unsigned __int16 *v13; // eax
  int v14; // edx
  cnode_t *map_rootnode; // ecx
  const cplane_t *plane; // eax
  cnode_t *v17; // esi
  unsigned __int8 type; // cl
  float dist; // xmm0_4
  int v20; // ecx
  char v21; // al
  int v22; // ecx
  int v23; // eax
  _DWORD v24[1024]; // [esp+4h] [ebp-1024h]
  float emaxs[3]; // [esp+1004h] [ebp-24h] BYREF
  float emins[3]; // [esp+1010h] [ebp-18h] BYREF
  int v27; // [esp+101Ch] [ebp-Ch]
  int v28; // [esp+1020h] [ebp-8h]
  int v29; // [esp+1024h] [ebp-4h]

  v3 = &g_pDispCollTrees[index];
  if ( v3 != nullptr && v3->m_nPower != 0 )
  {
    this->m_firstIndex.m_Memory.m_pMemory[index] = this->m_dispList.m_Size;
    this->m_leafCount.m_Memory.m_pMemory[index] = 0;
    headnode = this->m_pBSPData->map_cmodels.m_pArray->headnode;
    emins[0] = v3->m_mins.x;
    emins[1] = v3->m_mins.y;
    emins[2] = v3->m_mins.z;
    emaxs[0] = v3->m_maxs.x;
    emaxs[1] = v3->m_maxs.y;
    z = v3->m_maxs.z;
    v6 = 0;
    v29 = 1;
    v24[0] = headnode;
    emaxs[2] = z;
    while ( 1 )
    {
      v7 = v24[v6];
      v28 = (v6 + 1) % 1024;
      if ( v7 >= 0 )
      {
        v14 = v7;
        map_rootnode = this->m_pBSPData->map_rootnode;
        plane = map_rootnode[v7].plane;
        v17 = &map_rootnode[v14];
        type = plane->type;
        if ( type >= 3u )
        {
          v21 = BoxOnPlaneSide(emins, emaxs, p: plane);
        }
        else
        {
          dist = plane->dist;
          v20 = type;
          if ( emins[v20] < dist )
          {
            if ( dist < emaxs[v20] )
              v21 = 3;
            else
              v21 = 2;
          }
          else
          {
            v21 = 1;
          }
        }
        if ( (v21 & 1) != 0 )
        {
          v22 = v29;
          v24[v29] = v17->children[0];
          v29 = (v22 + 1) % 1024;
        }
        if ( (v21 & 2) != 0 )
        {
          v23 = v29;
          v24[v29] = v17->children[1];
          v29 = (v23 + 1) % 1024;
        }
      }
      else
      {
        m_Size = this->m_dispList.m_Size;
        v9 = -1 - v7;
        m_nAllocationCount = this->m_dispList.m_Memory.m_nAllocationCount;
        v27 = v9;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<wchar_t,int> *)&this->m_dispList,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_dispList.m_Size;
        m_pMemory = this->m_dispList.m_Memory.m_pMemory;
        v12 = this->m_dispList.m_Size - m_Size - 1;
        this->m_dispList.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v12);
        v13 = &this->m_dispList.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v27;
        ++this->m_leafCount.m_Memory.m_pMemory[index];
      }
      if ( v28 == v29 )
        break;
      v6 = v28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153ED0
// Name: public: virtual void CVirtualTerrain::GetWorldspaceBounds(void __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetWorldspaceBounds(
        CVirtualTerrain *this,
        void *userData,
        Vector *pMins,
        Vector *pMaxs)
{
  alignedbbox_t *v4; // eax

  v4 = &g_pDispBounds[(_DWORD)userData];
  *pMins = v4->mins.Vector;
  *pMaxs = v4->maxs.Vector;
}

//------------------------------------------------------------------------------
// Address: 0x10153F10
// Name: public: virtual void CVirtualTerrain::GetTrianglesInSphere(void __near *,class Vector const __near &,float,struct virtualmeshtrianglelist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetTrianglesInSphere(
        CVirtualTerrain *this,
        void *userData,
        const Vector *center,
        float radius,
        virtualmeshtrianglelist_t *pList)
{
  pList->triangleCount = CDispCollTree::AABBTree_GetTrisInSphere(
                           this: &g_pDispCollTrees[(_DWORD)userData],
                           center,
                           radius,
                           pIndexOut: pList->triangleIndices,
                           indexMax: 3072);
}

//------------------------------------------------------------------------------
// Address: 0x10153F50
// Name: public: virtual void CVirtualTerrain::GetVirtualMesh(void __near *,struct virtualmeshlist_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::GetVirtualMesh(CVirtualTerrain *this, void *userData, virtualmeshlist_t *pList)
{
  unsigned __int8 *m_pDispHullData; // ecx
  int *m_pMemory; // eax
  bool v6; // sf
  int *v7; // eax

  CDispCollTree::GetVirtualMeshList(this: &g_pDispCollTrees[(_DWORD)userData], pList);
  pList->pHull = nullptr;
  m_pDispHullData = this->m_pDispHullData;
  if ( m_pDispHullData != nullptr )
  {
    m_pMemory = this->m_dispHullOffset.m_Memory.m_pMemory;
    v6 = m_pMemory[(_DWORD)userData] < 0;
    v7 = &m_pMemory[(_DWORD)userData];
    if ( !v6 )
      pList->pHull = &m_pDispHullData[*v7];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153FA0
// Name: public: CDispLeafBuilder::CDispLeafBuilder(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
CDispLeafBuilder *__thiscall CDispLeafBuilder::CDispLeafBuilder(CDispLeafBuilder *this, CCollisionBSPData *pBSPData)
{
  unsigned __int16 *m_pMemory; // edx
  unsigned __int16 *v4; // eax
  int i; // eax
  int v7; // [esp-4h] [ebp-10h]
  int v8; // [esp-4h] [ebp-10h]

  this->m_dispList.m_Memory.m_pMemory = nullptr;
  this->m_dispList.m_Memory.m_nAllocationCount = 0;
  this->m_dispList.m_Memory.m_nGrowSize = 0;
  this->m_dispList.m_Size = 0;
  this->m_dispList.m_pElements = nullptr;
  this->m_firstIndex.m_Memory.m_pMemory = nullptr;
  this->m_firstIndex.m_Memory.m_nAllocationCount = 0;
  this->m_firstIndex.m_Memory.m_nGrowSize = 0;
  this->m_firstIndex.m_Size = 0;
  this->m_firstIndex.m_pElements = nullptr;
  this->m_leafCount.m_Memory.m_pMemory = nullptr;
  this->m_leafCount.m_Memory.m_nAllocationCount = 0;
  this->m_leafCount.m_Memory.m_nGrowSize = 0;
  this->m_leafCount.m_Size = 0;
  this->m_leafCount.m_pElements = nullptr;
  this->m_pBSPData = pBSPData;
  if ( this->m_dispList.m_Memory.m_nAllocationCount < 4096 && this->m_dispList.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_dispList.m_Memory.m_pMemory;
    this->m_dispList.m_Memory.m_nAllocationCount = 4096;
    if ( m_pMemory != nullptr )
      v4 = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 0x2000);
    else
      v4 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 0x2000);
    this->m_dispList.m_Memory.m_pMemory = v4;
  }
  this->m_dispList.m_pElements = this->m_dispList.m_Memory.m_pMemory;
  v7 = g_DispCollTreeCount;
  this->m_leafCount.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_leafCount,
    elem: 0,
    num: v7);
  v8 = g_DispCollTreeCount;
  this->m_firstIndex.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_firstIndex,
    elem: 0,
    num: v8);
  for ( i = 0; i < g_DispCollTreeCount; ++i )
  {
    this->m_leafCount.m_Memory.m_pMemory[i] = 0;
    this->m_firstIndex.m_Memory.m_pMemory[i] = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10154080
// Name: void CM_DispTreeLeafnum(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DispTreeLeafnum(CCollisionBSPData *pBSPData)
{
  int v1; // eax
  int v2; // ecx
  int i; // edi
  int m_Size; // edi
  unsigned __int16 *v5; // eax
  CDispLeafBuilder leafBuilder; // [esp+0h] [ebp-40h] BYREF

  if ( g_DispCollTreeCount != 0 )
  {
    v1 = 0;
    if ( pBSPData->numleafs > 0 )
    {
      v2 = 0;
      do
      {
        pBSPData->map_leafs.m_pArray[v2].dispCount = 0;
        ++v1;
        ++v2;
      }
      while ( v1 < pBSPData->numleafs );
    }
    CDispLeafBuilder::CDispLeafBuilder(this: &leafBuilder, pBSPData);
    for ( i = 0; i < g_DispCollTreeCount; ++i )
      CDispLeafBuilder::BuildLeafListForDisplacement(this: &leafBuilder, index: i);
    m_Size = leafBuilder.m_dispList.m_Size;
    v5 = (unsigned __int16 *)Hunk_AllocName(
                               size: 2 * leafBuilder.m_dispList.m_Size,
                               name: "CM_DispTreeLeafnum",
                               bClear: false);
    pBSPData->map_dispList.m_pArray = v5;
    pBSPData->numdisplist = m_Size;
    CDispLeafBuilder::WriteLeafList(this: &leafBuilder, pLeafList: v5);
    if ( leafBuilder.m_leafCount.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_leafCount.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_leafCount.m_Memory.m_pMemory);
    if ( leafBuilder.m_firstIndex.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_firstIndex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_firstIndex.m_Memory.m_pMemory);
    if ( leafBuilder.m_dispList.m_Memory.m_nGrowSize >= 0 && leafBuilder.m_dispList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafBuilder.m_dispList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101541C0
// Name: public: void CVirtualTerrain::LevelInit(struct dphysdisp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVirtualTerrain::LevelInit(CVirtualTerrain *this, dphysdisp_t *pLump, int lumpSize)
{
  unsigned int v3; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *p_m_dispHullOffset; // edi
  int v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // [esp-8h] [ebp-14h]

  v3 = 0;
  if ( pLump != nullptr )
  {
    p_m_dispHullOffset = &this->m_dispHullOffset;
    v7 = g_DispCollTreeCount;
    this->m_dispHullOffset.m_Size = 0;
    CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_dispHullOffset,
      elem: 0,
      num: v7);
    v5 = 0;
    if ( pLump->numDisplacements != 0 )
    {
      do
      {
        if ( pLump[v5 + 1].numDisplacements == 0xFFFF )
        {
          p_m_dispHullOffset->m_Memory.m_pMemory[v5] = -1;
        }
        else
        {
          p_m_dispHullOffset->m_Memory.m_pMemory[v5] = v3;
          v3 += pLump[v5 + 1].numDisplacements;
        }
        ++v5;
      }
      while ( v5 < pLump->numDisplacements );
    }
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v3);
    this->m_pDispHullData = v6;
    memcpy(dst: v6, src: (unsigned __int8 *)&pLump[pLump->numDisplacements + 1], count: v3);
  }
  else
  {
    this->m_pDispHullData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154260
// Name: void CM_CreateDispPhysCollide(struct dphysdisp_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_CreateDispPhysCollide(dphysdisp_t *pDispLump, int dispLumpSize)
{
  int v2; // ebx
  int i; // esi
  struct CPhysCollide **v4; // edi
  virtualmeshparams_t params; // [esp+8h] [ebp-Ch] BYREF

  CVirtualTerrain::LevelInit(this: &g_VirtualTerrain, pLump: pDispLump, lumpSize: dispLumpSize);
  v2 = 0;
  g_TerrainList.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&g_TerrainList,
    elem: 0,
    num: g_DispCollTreeCount);
  for ( i = 0; i < g_DispCollTreeCount; ++v2 )
  {
    if ( &g_pDispCollTrees[v2] != nullptr && (g_pDispCollTrees[v2].m_nFlags & 2) != 0 )
    {
      g_TerrainList.m_Memory.m_pMemory[i] = nullptr;
    }
    else
    {
      v4 = &g_TerrainList.m_Memory.m_pMemory[i];
      params.buildOuterHull = dispLumpSize <= 0;
      params.pMeshEventHandler = &g_VirtualTerrain;
      params.userData = (void *)i;
      *v4 = physcollision->CreateVirtualMesh(this: physcollision, a2: &params);
    }
    ++i;
  }
}

} // namespace engine_xlsp
