// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cmodel.cpp
// Functions: 74
// ============================================================

#include "engine\cmodel.h"

//------------------------------------------------------------------------------
// Address: 0x1014BC30
// Name: public: class Vector Ray_t::InvDelta(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Ray_t::InvDelta(Ray_t *this, Vector *result)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  Vector *v5; // eax

  x = this->m_Delta.x;
  if ( x == 0.0 )
    result->x = 3.4028235e38;
  else
    result->x = 1.0 / x;
  y = this->m_Delta.y;
  if ( y == 0.0 )
    result->y = 3.4028235e38;
  else
    result->y = 1.0 / y;
  z = this->m_Delta.z;
  v5 = result;
  if ( z == 0.0 )
    result->z = 3.4028235e38;
  else
    result->z = 1.0 / z;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014BCB0
// Name: void PopTraceVisits(struct TraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PopTraceVisits(TraceInfo_t *pTraceInfo)
{
  --pTraceInfo->m_nCheckDepth;
}

//------------------------------------------------------------------------------
// Address: 0x1014BCC0
// Name: int CM_NumClusters(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_NumClusters()
{
  return g_BSPData.numclusters;
}

//------------------------------------------------------------------------------
// Address: 0x1014BCD0
// Name: void CM_FreeMap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_FreeMap()
{
  CollisionBSPData_Destroy(pBSPData: &g_BSPData);
}

//------------------------------------------------------------------------------
// Address: 0x1014BCE0
// Name: int CM_PointLeafnumMinDistSqr_r(class CCollisionBSPData __near *,class Vector const __near &,int,float __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnumMinDistSqr_r(CCollisionBSPData *pBSPData, const Vector *p, int num, float *minDistSqr)
{
  int v4; // ecx
  cnode_t *map_rootnode; // edi
  int v6; // ecx
  cplane_t *plane; // eax
  cnode_t *v8; // edx
  unsigned __int8 type; // cl
  float v10; // xmm0_4
  float v11; // xmm0_4
  double v12; // st6
  double v13; // st7

  v4 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v6 = v4;
      plane = map_rootnode[v6].plane;
      v8 = &map_rootnode[v6];
      type = plane->type;
      if ( type >= 3u )
        v10 = (float)((float)(plane->normal.y * p->y) + (float)(plane->normal.x * p->x))
            + (float)(plane->normal.z * p->z);
      else
        v10 = *(&p->x + type);
      v11 = v10 - plane->dist;
      v12 = v11 * v11;
      v13 = *minDistSqr;
      if ( v12 <= v13 )
        v13 = v12;
      *minDistSqr = v13;
      if ( v11 >= 0.0 )
        v4 = v8->children[0];
      else
        v4 = v8->children[1];
    }
    while ( v4 >= 0 );
  }
  return -1 - v4;
}

//------------------------------------------------------------------------------
// Address: 0x1014BD80
// Name: int CM_PointLeafnum_r(class CCollisionBSPData __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnum_r(CCollisionBSPData *pBSPData, const Vector *p, int num)
{
  int v3; // ecx
  cnode_t *map_rootnode; // edi
  int v5; // ecx
  cplane_t *plane; // eax
  cnode_t *v7; // edx
  unsigned __int8 type; // cl
  float v9; // xmm0_4

  v3 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v5 = v3;
      plane = map_rootnode[v5].plane;
      v7 = &map_rootnode[v5];
      type = plane->type;
      if ( type >= 3u )
        v9 = (float)((float)(plane->normal.y * p->y) + (float)(plane->normal.x * p->x))
           + (float)(plane->normal.z * p->z);
      else
        v9 = *(&p->x + type);
      if ( (float)(v9 - plane->dist) >= 0.0 )
        v3 = v7->children[0];
      else
        v3 = v7->children[1];
    }
    while ( v3 >= 0 );
  }
  return -1 - v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE00
// Name: int CM_PointLeafnum(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnum(const Vector *p)
{
  if ( g_BSPData.numplanes != 0 )
    return CM_PointLeafnum_r(pBSPData: &g_BSPData, p, num: 0);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE30
// Name: void CM_SnapPointToReferenceLeaf_r(class CCollisionBSPData __near *,class Vector const __near &,int,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SnapPointToReferenceLeaf_r(
        CCollisionBSPData *pBSPData,
        const Vector *p,
        int num,
        float tolerance,
        Vector *pSnapPoint)
{
  int v5; // edx
  cnode_t *map_rootnode; // ebx
  int v7; // edx
  cplane_t *plane; // eax
  cnode_t *v9; // esi
  int v10; // edx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4

  v5 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v7 = v5;
      plane = map_rootnode[v7].plane;
      v9 = &map_rootnode[v7];
      if ( plane->type >= 3u )
      {
        v11 = (float)((float)(p->y * plane->normal.y) + (float)(p->x * plane->normal.x))
            + (float)(p->z * plane->normal.z);
        v12 = (float)((float)(pSnapPoint->y * plane->normal.y) + (float)(plane->normal.x * pSnapPoint->x))
            + (float)(pSnapPoint->z * plane->normal.z);
      }
      else
      {
        v10 = 4 * plane->type;
        v11 = *(float *)((char *)&p->x + v10);
        v12 = *(float *)((char *)&pSnapPoint->x + v10);
      }
      v13 = v12 - plane->dist;
      if ( (float)(v11 - plane->dist) >= 0.0 )
      {
        v5 = v9->children[0];
        if ( v13 < 0.0 )
        {
          v17 = tolerance - v13;
          v18 = (float)(plane->normal.y * (float)(tolerance - v13)) + pSnapPoint->y;
          v19 = (float)(plane->normal.z * v17) + pSnapPoint->z;
          pSnapPoint->x = pSnapPoint->x + (float)(plane->normal.x * v17);
          pSnapPoint->y = v18;
          pSnapPoint->z = v19;
        }
      }
      else
      {
        v5 = v9->children[1];
        if ( v13 > 0.0 )
        {
          v14 = v13 + tolerance;
          v15 = plane->normal.y * v14;
          v16 = plane->normal.z * v14;
          pSnapPoint->x = pSnapPoint->x - (float)(plane->normal.x * v14);
          pSnapPoint->y = pSnapPoint->y - v15;
          pSnapPoint->z = pSnapPoint->z - v16;
        }
      }
    }
    while ( v5 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BF80
// Name: void CM_SnapPointToReferenceLeaf(class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SnapPointToReferenceLeaf(const Vector *referenceLeafPoint, float tolerance, Vector *pSnapPoint)
{
  if ( g_BSPData.numplanes != 0 )
    CM_SnapPointToReferenceLeaf_r(pBSPData: &g_BSPData, p: referenceLeafPoint, num: 0, tolerance, pSnapPoint);
}

//------------------------------------------------------------------------------
// Address: 0x1014BFB0
// Name: int CM_BoxLeafnums(struct leafnums_t __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxLeafnums(leafnums_t *context, const Vector *center, const Vector *extents, int nodenum)
{
  int v6; // edx
  double y; // st7
  float v8; // xmm0_4
  cnode_t *v9; // esi
  cplane_t *plane; // edx
  float v11; // xmm0_4
  long double v12; // st7
  double v13; // st6
  __int16 v14; // cx
  _DWORD v16[1024]; // [esp+0h] [ebp-1018h]
  float v17; // [esp+1000h] [ebp-18h]
  float z; // [esp+1004h] [ebp-14h]
  int v19; // [esp+1008h] [ebp-10h]
  int v20; // [esp+100Ch] [ebp-Ch]
  int v21; // [esp+1010h] [ebp-8h]
  int v22; // [esp+1014h] [ebp-4h]
  float v23; // [esp+1020h] [ebp+8h]
  float x; // [esp+102Ch] [ebp+14h]

  v19 = 0;
  v20 = 0;
  v22 = 0;
  v21 = -1;
  while ( 1 )
  {
    while ( nodenum >= 0 )
    {
      y = extents->y;
      v8 = center->y;
      v9 = &context->pBSPData->map_rootnode[nodenum];
      plane = v9->plane;
      v23 = v9->plane->normal.y;
      x = v9->plane->normal.x;
      z = v9->plane->normal.z;
      v11 = (float)((float)((float)(v8 * v23) + (float)(center->x * x)) + (float)(center->z * z)) - plane->dist;
      v12 = fabs(y * v23) + fabs(x * extents->x);
      v13 = extents->z;
      v21 = nodenum;
      v17 = v12 + fabs(v13 * z);
      if ( v11 < v17 )
      {
        if ( (float)-v17 <= v11 )
        {
          if ( context->leafTopNode == -1 )
            context->leafTopNode = nodenum;
          v14 = v22;
          v16[v22] = v9->children[0];
          v22 = (v14 + 1) & 0x3FF;
          nodenum = v9->children[1];
        }
        else
        {
          nodenum = v9->children[1];
        }
      }
      else
      {
        nodenum = v9->children[0];
      }
    }
    if ( context->leafTopNode == -1 )
      context->leafTopNode = v21;
    v6 = v19;
    if ( v19 < context->leafMaxCount )
    {
      context->pLeafList[v19] = -1 - nodenum;
      v19 = ++v6;
    }
    if ( v20 == v22 )
      break;
    nodenum = v16[v20];
    v20 = ((_WORD)v20 + 1) & 0x3FF;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1014C560
// Name: CM_ComputeTraceEndpoints
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_ComputeTraceEndpoints(CGameTrace *tr, const Ray_t *ray)
{
  float fraction; // xmm3_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float fractionleftsolid; // xmm3_4
  float v7; // xmm3_4

  fraction = tr->fraction;
  v3 = ray->m_StartOffset.x + ray->m_Start.x;
  v4 = ray->m_StartOffset.y + ray->m_Start.y;
  v5 = ray->m_StartOffset.z + ray->m_Start.z;
  if ( fraction == 1.0 )
  {
    tr->endpos.x = ray->m_Delta.x + v3;
    tr->endpos.y = ray->m_Delta.y + v4;
    tr->endpos.z = ray->m_Delta.z + v5;
  }
  else
  {
    tr->endpos.x = (float)(ray->m_Delta.x * fraction) + v3;
    tr->endpos.y = (float)(ray->m_Delta.y * fraction) + v4;
    tr->endpos.z = (float)(ray->m_Delta.z * fraction) + v5;
  }
  fractionleftsolid = tr->fractionleftsolid;
  if ( fractionleftsolid == 0.0 )
  {
    tr->startpos.x = v3;
    tr->startpos.y = v4;
    tr->startpos.z = v5;
  }
  else
  {
    if ( fractionleftsolid == 1.0 )
    {
      *(_WORD *)&tr->allsolid = 257;
      tr->fraction = 0.0;
      tr->endpos.x = v3;
      tr->endpos.y = v4;
      tr->endpos.z = v5;
    }
    v7 = tr->fractionleftsolid;
    tr->startpos.x = (float)(ray->m_Delta.x * v7) + v3;
    tr->startpos.y = (float)(ray->m_Delta.y * v7) + v4;
    tr->startpos.z = (float)(ray->m_Delta.z * v7) + v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C680
// Name: void CM_ClearTrace(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_ClearTrace(CGameTrace *trace)
{
  memset(dst: (unsigned __int8 *)trace, value: 0, count: sizeof(CGameTrace));
  trace->fraction = 1.0;
  trace->fractionleftsolid = 0.0;
  trace->surface = CCollisionBSPData::nullsurface;
}

//------------------------------------------------------------------------------
// Address: 0x1014C6C0
// Name: void CM_NullVis(class CCollisionBSPData __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_NullVis(CCollisionBSPData *pBSPData, unsigned __int8 *out)
{
  if ( (pBSPData->numclusters + 7) >> 3 != 0 )
    memset(dst: out, value: 0xFFu, count: (pBSPData->numclusters + 7) >> 3);
}

//------------------------------------------------------------------------------
// Address: 0x1014C6F0
// Name: void CM_DecompressVis(class CCollisionBSPData __near *,int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DecompressVis(CCollisionBSPData *pBSPData, int cluster, int visType, unsigned __int8 *out)
{
  int numclusters; // eax
  dvis_t *map_vis; // ecx
  unsigned __int8 *v7; // ebx
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // eax
  int numClusterBytes; // [esp+Ch] [ebp+8h]

  numclusters = pBSPData->numclusters;
  if ( cluster > numclusters || cluster < 0 )
  {
    v13 = (numclusters + 7) >> 3;
    if ( v13 == 0 )
      return;
LABEL_19:
    memset(dst: out, value: 0xFFu, count: v13);
    return;
  }
  if ( pBSPData->numvisibility == 0 || pBSPData->map_vis == nullptr )
  {
    v13 = (numclusters + 7) >> 3;
    if ( v13 == 0 )
      return;
    goto LABEL_19;
  }
  map_vis = pBSPData->map_vis;
  v7 = out;
  v8 = map_vis->bitofs[cluster][visType];
  v9 = (numclusters + 7) >> 3;
  v10 = (dvis_t *)((char *)map_vis + v8) == nullptr;
  v11 = (unsigned __int8 *)map_vis + v8;
  numClusterBytes = v9;
  if ( v10 )
  {
    CM_NullVis(pBSPData, out);
  }
  else
  {
    do
    {
      if ( *v11 != 0 )
      {
        *v7++ = *v11++;
      }
      else
      {
        v12 = v11[1];
        v11 += 2;
        if ( (int)&v7[v12 - (_DWORD)out] > v9 )
        {
          v12 = (unsigned int)&out[v9 - (_DWORD)v7];
          ConMsg(a1: "warning: Vis decompression overrun\n");
          v9 = numClusterBytes;
        }
        if ( v12 != 0 )
        {
          memset(dst: v7, value: 0, count: v12);
          v9 = numClusterBytes;
          v7 += v12;
        }
      }
    }
    while ( v7 - out < v9 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C800
// Name: unsigned char const __near * CM_Vis(unsigned char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CM_Vis(unsigned __int8 *dest, int destlen, int cluster, unsigned int visType)
{
  if ( dest != nullptr && visType <= 2 )
  {
    if ( cluster == -1 )
    {
      if ( (g_BSPData.numclusters + 7) >> 3 > destlen )
        Sys_Error(error: "CM_Vis:  buffer not big enough (%i but need %i)\n", destlen, (g_BSPData.numclusters + 7) >> 3);
      memset(dst: dest, value: 0, count: (g_BSPData.numclusters + 7) >> 3);
      return dest;
    }
    else
    {
      CM_DecompressVis(pBSPData: &g_BSPData, cluster, visType, out: dest);
      return dest;
    }
  }
  else
  {
    Sys_Error(error: "CM_Vis: error");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C880
// Name: int CM_ClusterPVSSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_ClusterPVSSize()
{
  return 0x2000;
}

//------------------------------------------------------------------------------
// Address: 0x1014C890
// Name: unsigned char const __near * CM_ClusterPVS(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CM_ClusterPVS(int cluster)
{
  if ( cluster == -1 )
  {
    if ( (g_BSPData.numclusters + 7) >> 3 > 0x2000 )
      Sys_Error(error: "CM_Vis:  buffer not big enough (%i but need %i)\n", 0x2000, (g_BSPData.numclusters + 7) >> 3);
    memset(dst: pvsrow, value: 0, count: (g_BSPData.numclusters + 7) >> 3);
    return pvsrow;
  }
  else
  {
    CM_DecompressVis(pBSPData: &g_BSPData, cluster, visType: 0, out: pvsrow);
    return pvsrow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C900
// Name: void CM_WorldSpaceCenter(class ICollideable __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_WorldSpaceCenter(ICollideable *pCollideable, Vector *pCenter)
{
  const Vector *v2; // edi
  const Vector *v3; // eax
  const QAngle *(__thiscall *GetCollisionAngles)(ICollideable *); // edx
  float v5; // xmm2_4
  float *v6; // ecx
  const matrix3x4_t *v7; // eax
  const Vector *v8; // eax
  Vector vecLocalCenter; // [esp+8h] [ebp-Ch] BYREF

  v2 = pCollideable->OBBMaxs(this: pCollideable);
  v3 = pCollideable->OBBMins(this: pCollideable);
  vecLocalCenter.x = v3->x + v2->x;
  vecLocalCenter.y = v3->y + v2->y;
  GetCollisionAngles = pCollideable->GetCollisionAngles;
  v5 = (float)(v3->z + v2->z) * 0.5;
  vecLocalCenter.x = vecLocalCenter.x * 0.5;
  vecLocalCenter.y = vecLocalCenter.y * 0.5;
  vecLocalCenter.z = v5;
  v6 = (float *)GetCollisionAngles(this: pCollideable);
  if ( vec3_angle.x == *v6 && vec3_angle.y == v6[1] && vec3_angle.z == v6[2]
    || vec3_origin.x == vecLocalCenter.x && vec3_origin.y == vecLocalCenter.y && vec3_origin.z == vecLocalCenter.z )
  {
    v8 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pCenter->x = v8->x + vecLocalCenter.x;
    pCenter->y = v8->y + vecLocalCenter.y;
    pCenter->z = v8->z + vecLocalCenter.z;
  }
  else
  {
    v7 = pCollideable->CollisionToWorldTransform(this: pCollideable);
    VectorTransform(in1: &vecLocalCenter.x, in2: v7, out: &pCenter->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CA40
// Name: void CM_WorldSpaceBounds(class ICollideable __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_WorldSpaceBounds(ICollideable *pCollideable, Vector *pMins, Vector *pMaxs)
{
  const QAngle *v3; // eax
  const Vector *v4; // edi
  const Vector *v5; // eax
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // edx
  float *v7; // edi
  const Vector *v8; // eax
  const matrix3x4_t *v9; // eax
  const Vector *v10; // [esp-10h] [ebp-14h]
  const Vector *v11; // [esp-Ch] [ebp-10h]

  v3 = pCollideable->GetCollisionAngles(this: pCollideable);
  if ( vec3_angle.x == v3->x && vec3_angle.y == v3->y && vec3_angle.z == v3->z )
  {
    v4 = pCollideable->OBBMins(this: pCollideable);
    v5 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pMins->x = v5->x + v4->x;
    pMins->y = v5->y + v4->y;
    OBBMaxs = pCollideable->OBBMaxs;
    pMins->z = v5->z + v4->z;
    v7 = (float *)OBBMaxs(this: pCollideable);
    v8 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pMaxs->x = v8->x + *v7;
    pMaxs->y = v8->y + v7[1];
    pMaxs->z = v8->z + v7[2];
  }
  else
  {
    v11 = pCollideable->OBBMaxs(this: pCollideable);
    v10 = pCollideable->OBBMins(this: pCollideable);
    v9 = pCollideable->CollisionToWorldTransform(this: pCollideable);
    TransformAABB(transform: v9, vecMinsIn: v10, vecMaxsIn: v11, vecMinsOut: pMins, vecMaxsOut: pMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CB50
// Name: public: void CFastPointLeafNum::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFastPointLeafNum::Reset(CFastPointLeafNum *this)
{
  this->m_flDistToExitLeafSqr = -1.0;
  this->m_iCachedLeaf = -1;
  this->m_vCachedPos.x = 0.0;
  this->m_vCachedPos.y = 0.0;
  this->m_vCachedPos.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CB80
// Name: public: struct csurface_t __near * CCollisionBSPData::GetSurfaceAtIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
csurface_t *__thiscall CCollisionBSPData::GetSurfaceAtIndex(CCollisionBSPData *this, unsigned __int16 surfaceIndex)
{
  if ( surfaceIndex == 0xFFFF )
    return &CCollisionBSPData::nullsurface;
  else
    return &this->map_surfaces.m_pArray[surfaceIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1014CBB0
// Name: void EndTrace(struct TraceInfo_t __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndTrace(TraceInfo_t **pTraceInfo)
{
  --(*pTraceInfo)->m_nCheckDepth;
  CTSListBase::Push(this: &g_TraceInfoPool, pNode: (TSLNodeBase_t *)&(*pTraceInfo)[-1].m_DispCounters[1].m_pElements);
  *pTraceInfo = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014CBE0
// Name: struct cmodel_t __near * CM_InlineModelNumber(int)
// Source: json
//------------------------------------------------------------------------------
cmodel_t *__cdecl CM_InlineModelNumber(int index)
{
  if ( index < 0 || index > g_BSPData.numcmodels )
    return nullptr;
  else
    return &g_BSPData.map_cmodels.m_pArray[index];
}

//------------------------------------------------------------------------------
// Address: 0x1014CC10
// Name: int CM_BrushContents_r(class CCollisionBSPData __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BrushContents_r(CCollisionBSPData *pBSPData, int nodenum)
{
  int v2; // eax
  int i; // edi
  cnode_t *v4; // ebx
  cleaf_t *v5; // eax
  int numleafbrushes; // ecx
  unsigned __int16 *v7; // eax

  v2 = nodenum;
  for ( i = 0; v2 >= 0; v2 = v4->children[1] )
  {
    v4 = &pBSPData->map_rootnode[v2];
    i |= CM_BrushContents_r(pBSPData, nodenum: v4->children[0]);
  }
  v5 = &pBSPData->map_leafs.m_pArray[-v2 - 1];
  numleafbrushes = v5->numleafbrushes;
  if ( v5->numleafbrushes != 0 )
  {
    v7 = &pBSPData->map_leafbrushes.m_pArray[v5->firstleafbrush];
    do
    {
      i |= pBSPData->map_brushes.m_pArray[*v7++].contents;
      --numleafbrushes;
    }
    while ( numleafbrushes != 0 );
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1014CC90
// Name: int CM_InlineModelContents(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_InlineModelContents(int index)
{
  cmodel_t *v1; // eax

  if ( index >= 0 && index <= g_BSPData.numcmodels && (v1 = &g_BSPData.map_cmodels.m_pArray[index]) != nullptr )
    return CM_BrushContents_r(pBSPData: &g_BSPData, nodenum: v1->headnode);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CCD0
// Name: int CM_LeafContents(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafContents(int leafnum)
{
  return g_BSPData.map_leafs.m_pArray[leafnum].contents;
}

//------------------------------------------------------------------------------
// Address: 0x1014CCF0
// Name: int CM_LeafCluster(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafCluster(int leafnum)
{
  return g_BSPData.map_leafs.m_pArray[leafnum].cluster;
}

//------------------------------------------------------------------------------
// Address: 0x1014CD10
// Name: int CM_LeafFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafFlags(int leafnum)
{
  return *((__int16 *)&g_BSPData.map_leafs.m_pArray[leafnum] + 3) >> 9;
}

//------------------------------------------------------------------------------
// Address: 0x1014CD30
// Name: int CM_LeafArea(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafArea(int leafnum)
{
  return (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[leafnum] + 3) << 7) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x1014CD50
// Name: int CM_BoxLeafnums(class Vector const __near &,class Vector const __near &,int __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxLeafnums(
        const Vector *mins,
        const Vector *maxs,
        int *list,
        int listsize,
        int *topnode,
        int cmodelIndex)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int result; // eax
  leafnums_t context; // [esp+0h] [ebp-28h] BYREF
  Vector center; // [esp+10h] [ebp-18h] BYREF
  Vector extents; // [esp+1Ch] [ebp-Ch] BYREF

  context.pLeafList = list;
  x = maxs->x;
  y = maxs->y;
  z = maxs->z;
  context.leafMaxCount = listsize;
  v9 = (float)(mins->x + x) * 0.5;
  v10 = (float)(mins->y + y) * 0.5;
  v11 = (float)(mins->z + z) * 0.5;
  result = 0;
  context.leafTopNode = -1;
  context.pBSPData = &g_BSPData;
  center.x = v9;
  center.y = v10;
  center.z = v11;
  extents.x = x - v9;
  extents.y = y - v10;
  extents.z = z - v11;
  if ( cmodelIndex >= 0 && cmodelIndex < g_BSPData.numcmodels )
    result = CM_BoxLeafnums(&context, &center, &extents, nodenum: g_BSPData.map_cmodels.m_pArray[cmodelIndex].headnode);
  if ( topnode != nullptr )
    *topnode = context.leafTopNode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014CE30
// Name: int CM_PointContents(class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointContents(const Vector *p, int headnode, int contentsMask)
{
  if ( g_BSPData.numnodes != 0 && (g_BSPData.allcontents & contentsMask) != 0 )
    return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum_r(pBSPData: &g_BSPData, p, num: headnode)].contents;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CE70
// Name: int CM_TransformedPointContents(class Vector const __near &,int,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_TransformedPointContents(const Vector *p, int headnode, const Vector *origin, const QAngle *angles)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float y; // xmm1_4
  Vector up; // [esp+0h] [ebp-30h] BYREF
  Vector right; // [esp+Ch] [ebp-24h] BYREF
  Vector forward; // [esp+18h] [ebp-18h] BYREF
  Vector p_l; // [esp+24h] [ebp-Ch] BYREF

  p_l.x = p->x - origin->x;
  p_l.y = p->y - origin->y;
  x = angles->x;
  p_l.z = p->z - origin->z;
  if ( x != 0.0 || angles->y != 0.0 || angles->z != 0.0 )
  {
    AngleVectors(angles, &forward, &right, &up);
    v5 = p_l.x;
    y = p_l.y;
    p_l.x = (float)((float)(forward.y * p_l.y) + (float)(forward.x * p_l.x)) + (float)(forward.z * p_l.z);
    LODWORD(p_l.y) = COERCE_UNSIGNED_INT((float)((float)(right.x * v5) + (float)(right.y * p_l.y)) + (float)(right.z * p_l.z))
                   ^ _mask__NegFloat_;
    p_l.z = (float)((float)(up.y * y) + (float)(up.x * v5)) + (float)(up.z * p_l.z);
  }
  return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum_r(pBSPData: &g_BSPData, p: &p_l, num: headnode)].contents;
}

//------------------------------------------------------------------------------
// Address: 0x1014CFB0
// Name: bool IntersectRayWithBoxBrush(struct TraceInfo_t __near *,struct cbrush_t const __near *,struct cboxbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBoxBrush(TraceInfo_t *pTraceInfo, const cbrush_t *pBrush, cboxbrush_t *pBox)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  int v20; // eax
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  float v32; // xmm6_4
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  bool v35; // al
  int contents; // edx
  bool v38; // cf
  int v39; // ecx
  unsigned __int16 v40; // ax
  CCollisionBSPData *m_pBSPData; // ecx
  csurface_t *SurfaceAtIndex; // eax
  const char *name; // edx
  unsigned __int8 v44; // cl
  __m128 v45; // [esp-Ch] [ebp-7Ch]
  unsigned int v46; // [esp-Ch] [ebp-7Ch]
  __m128 faceId_4; // [esp+4h] [ebp-6Ch]
  __m128 v48; // [esp+14h] [ebp-5Ch]
  __m128 invDelta_4; // [esp+24h] [ebp-4Ch]
  __m128 startOutMins_4; // [esp+34h] [ebp-3Ch]
  __m128 startOutMins_4a; // [esp+34h] [ebp-3Ch]
  __m128 lastIn_4a; // [esp+44h] [ebp-2Ch]
  __m128 lastIn_4; // [esp+44h] [ebp-2Ch]

  v3 = *(__m128 *)&pTraceInfo->m_extents.x;
  v4 = _mm_sub_ps(_mm_sub_ps((__m128)pBox->mins, *(__m128 *)&pTraceInfo->m_start.x), v3);
  v5 = *(__m128 *)&pTraceInfo->m_delta.x;
  startOutMins_4 = _mm_add_ps(_mm_sub_ps((__m128)pBox->maxs, *(__m128 *)&pTraceInfo->m_start.x), v3);
  v6 = _mm_cmplt_ps(startOutMins_4, v5);
  v7 = _mm_cmplt_ps(Four_Zeros, v4);
  v8 = _mm_cmplt_ps(v5, v4);
  v9 = _mm_cmplt_ps(startOutMins_4, Four_Zeros);
  invDelta_4 = v7;
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v6, v9), _mm_and_ps(v8, v7)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return 0;
  v48 = *(__m128 *)&pTraceInfo->m_invDelta.x;
  lastIn_4a = _mm_mul_ps(v48, startOutMins_4);
  v10 = _mm_or_ps(_mm_xor_ps(v6, v9), _mm_xor_ps(v8, v7));
  v11 = _mm_mul_ps(v48, v4);
  v12 = _mm_max_ps(v11, lastIn_4a);
  faceId_4 = _mm_andnot_ps(v10, Four_Negative_FLT_MAX);
  v13 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v11, lastIn_4a), v10), faceId_4);
  v14 = _mm_andnot_ps(v10, Four_FLT_MAX);
  v15 = _mm_or_ps(_mm_and_ps(v12, v10), v14);
  v45 = v14;
  v16 = _mm_min_ps(_mm_min_ps(v15, _mm_shuffle_ps(v15, v15, 57)), _mm_shuffle_ps(v15, v15, 78));
  v17 = _mm_max_ps(_mm_max_ps(v13, _mm_shuffle_ps(v13, v13, 57)), _mm_shuffle_ps(v13, v13, 78));
  if ( _mm_movemask_ps(
         _mm_cmpeq_ps(
           _mm_cmplt_ps(
             _mm_min_ps(_mm_shuffle_ps(v16, v16, 0), Four_Ones),
             _mm_max_ps(_mm_shuffle_ps(v17, v17, 0), Four_Zeros)),
           Four_Zeros)) != 15 )
    return 0;
  v18 = _mm_mul_ps(_mm_sub_ps(v4, Four_DistEpsilons), v48);
  v19 = _mm_mul_ps(_mm_add_ps(Four_DistEpsilons, startOutMins_4), v48);
  v20 = _mm_movemask_ps(_mm_and_ps(_mm_or_ps(v9, invDelta_4), *(__m128 *)g_SIMD_clear_wmask));
  v21 = _mm_cmple_ps(v18, v19);
  v22 = _mm_andnot_ps(v21, *(__m128 *)g_CubeFaceIndex1);
  v23 = _mm_and_ps(*(__m128 *)g_CubeFaceIndex0, v21);
  v24 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v18, v19), v10), faceId_4);
  v25 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v18, v19), v10), v45);
  v26 = _mm_or_ps(v22, v23);
  v27 = _mm_shuffle_ps(v24, v24, 57);
  v28 = _mm_min_ps(_mm_min_ps(v25, _mm_shuffle_ps(v25, v25, 57)), _mm_shuffle_ps(v25, v25, 78));
  v29 = _mm_max_ps(v24, v27);
  v30 = _mm_cmplt_ps(v27, v24);
  v31 = _mm_shuffle_ps(v24, v24, 78);
  v32 = _mm_andnot_ps(v30, _mm_shuffle_ps(v26, v26, 57)).m128_f32[0];
  v27.m128_i32[0] = v26.m128_i32[0] & v30.m128_i32[0];
  v33 = _mm_cmplt_ps(v31, v29);
  v34 = _mm_max_ps(v29, v31);
  v46 = _mm_andnot_ps(v33, _mm_shuffle_ps(v26, v26, 78)).m128_u32[0]
      | (v27.m128_i32[0] | LODWORD(v32)) & v33.m128_i32[0];
  lastIn_4 = _mm_min_ps(_mm_shuffle_ps(v28, v28, 0), Four_Ones);
  v35 = v20 != 0;
  startOutMins_4a = _mm_max_ps(_mm_shuffle_ps(v34, v34, 0), Four_Zeros);
  if ( _mm_movemask_ps(_mm_cmpeq_ps(_mm_cmplt_ps(lastIn_4, startOutMins_4a), Four_Zeros)) != 15 )
    return 0;
  if ( v35 && (!pTraceInfo->m_ispoint || pTraceInfo->m_trace.fractionleftsolid <= startOutMins_4a.m128_f32[0]) )
  {
    if ( pTraceInfo->m_trace.fraction <= startOutMins_4a.m128_f32[0] )
      return 0;
    LODWORD(pTraceInfo->m_trace.fraction) = startOutMins_4a.m128_i32[0];
    pTraceInfo->m_bDispHit = 0;
    v40 = pBox->surfaceIndex[v46];
    m_pBSPData = pTraceInfo->m_pBSPData;
    pTraceInfo->m_trace.plane.normal = vec3_origin;
    SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: m_pBSPData, surfaceIndex: v40);
    name = SurfaceAtIndex->name;
    *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
    LOWORD(SurfaceAtIndex) = pBox->surfaceIndex[v46];
    pTraceInfo->m_trace.surface.name = name;
    pTraceInfo->m_trace.worldSurfaceIndex = (unsigned __int16)SurfaceAtIndex;
    if ( v46 < 3 )
    {
      v44 = signbits[v46];
      LODWORD(pTraceInfo->m_trace.plane.dist) = *((_DWORD *)&pBox->mins.x + v46) ^ _mask__NegFloat_;
      *((_DWORD *)&pTraceInfo->m_trace.plane.normal.x + v46) = -1082130432;
      pTraceInfo->m_trace.plane.type = v46;
      pTraceInfo->m_trace.contents = pBrush->contents;
      pTraceInfo->m_trace.plane.signbits = v44;
    }
    else
    {
      pTraceInfo->m_trace.plane.dist = *(&pBox->mins.y + v46);
      *((_DWORD *)&pTraceInfo->m_trace.endpos.x + v46) = 1065353216;
      pTraceInfo->m_trace.plane.type = v46 - 3;
      pTraceInfo->m_trace.contents = pBrush->contents;
      pTraceInfo->m_trace.plane.signbits = 0;
    }
    return 1;
  }
  else
  {
    contents = pBrush->contents;
    pTraceInfo->m_trace.startsolid = true;
    pTraceInfo->m_trace.contents = contents;
    if ( lastIn_4.m128_f32[0] >= 1.0 )
    {
      pTraceInfo->m_trace.allsolid = true;
      pTraceInfo->m_trace.fraction = 0.0;
      return 0;
    }
    if ( lastIn_4.m128_f32[0] <= pTraceInfo->m_trace.fractionleftsolid )
      return 0;
    v38 = lastIn_4.m128_f32[0] < pTraceInfo->m_trace.fraction;
    LODWORD(pTraceInfo->m_trace.fractionleftsolid) = lastIn_4.m128_i32[0];
    if ( v38 )
      return 0;
    v39 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
    pTraceInfo->m_trace.surface.name = CCollisionBSPData::nullsurface.name;
    pTraceInfo->m_trace.fraction = 1.0;
    *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v39;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D390
// Name: void CM_TestBoxInBrush(struct TraceInfo_t __near *,struct cbrush_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TestBoxInBrush(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // eax
  __m128 *v3; // eax
  Vector *p_m_maxs; // esi
  int firstbrushside; // edx
  float z; // xmm0_4
  float y; // xmm4_4
  float x; // xmm5_4
  cbrushside_t *v9; // eax
  cplane_t *plane; // edi
  Vector *v11; // eax
  int v12; // edi
  double v13; // st7
  Vector ofs; // [esp+0h] [ebp-2Ch] BYREF
  const cbrush_t *v15; // [esp+Ch] [ebp-20h]
  int v16; // [esp+10h] [ebp-1Ch]
  float v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+18h] [ebp-14h]
  cbrushside_t *v19; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  char *v22; // [esp+28h] [ebp-4h]

  numsides = brush->numsides;
  v15 = brush;
  if ( (_WORD)numsides == 0xFFFF )
  {
    v3 = (__m128 *)&pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside];
    if ( _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_and_ps(
               _mm_cmplt_ps(
                 _mm_min_ps(v3[1], _mm_add_ps(*(__m128 *)&pTraceInfo->m_maxs.x, *(__m128 *)&pTraceInfo->m_start.x)),
                 _mm_max_ps(*v3, _mm_add_ps(*(__m128 *)&pTraceInfo->m_mins.x, *(__m128 *)&pTraceInfo->m_start.x))),
               *(__m128 *)g_SIMD_clear_wmask),
             Four_Zeros)) == 15 )
    {
LABEL_15:
      *(_WORD *)&pTraceInfo->m_trace.allsolid = 257;
      pTraceInfo->m_trace.fraction = 0.0;
      pTraceInfo->m_trace.fractionleftsolid = 1.0;
      pTraceInfo->m_trace.contents = brush->contents;
    }
  }
  else if ( (_WORD)numsides != 0 )
  {
    p_m_maxs = &pTraceInfo->m_maxs;
    memset(&ofs, 0, sizeof(ofs));
    i = 0;
    v16 = numsides;
    firstbrushside = brush->firstbrushside;
    z = pTraceInfo->m_start.z;
    y = pTraceInfo->m_start.y;
    x = pTraceInfo->m_start.x;
    v18 = -12;
    v22 = (char *)((char *)&ofs - (char *)p_m_maxs);
    v9 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[firstbrushside];
    v17 = z;
    v19 = v9;
    while ( 1 )
    {
      plane = v9->plane;
      v11 = &pTraceInfo->m_maxs;
      v12 = (char *)plane - (char *)p_m_maxs;
      for ( j = 3; j != 0; --j )
      {
        if ( *(float *)((char *)&v11->x + v12) >= 0.0 )
          v13 = v11[v18 / 0xCu].x;
        else
          v13 = v11->x;
        *(float *)((char *)&v11->x + (_DWORD)v22) = v13;
        v11 = (Vector *)((char *)v11 + 4);
      }
      if ( (float)((float)((float)((float)(x * v19->plane->normal.x) + (float)(y * v19->plane->normal.y))
                         + (float)(v17 * v19->plane->normal.z))
                 - (float)(v19->plane->dist
                         - (float)((float)((float)(v19->plane->normal.x * ofs.x) + (float)(v19->plane->normal.y * ofs.y))
                                 + (float)(v19->plane->normal.z * ofs.z)))) > 0.0 )
        break;
      v9 = v19 + 1;
      ++i;
      ++v19;
      if ( i >= v16 )
      {
        brush = v15;
        goto LABEL_15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D540
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014D5D0
// Name: void FloodArea_r(class CCollisionBSPData __near *,struct carea_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodArea_r(CCollisionBSPData *pBSPData, carea_t *area, int floodnum)
{
  bool v4; // cc
  dareaportal_t *v5; // edi
  int i; // [esp+10h] [ebp+8h]

  if ( area->floodvalid == pBSPData->floodvalid )
  {
    if ( area->floodnum == floodnum )
      return;
    Sys_Error(error: "FloodArea_r: reflooded");
  }
  v4 = area->numareaportals <= 0;
  area->floodnum = floodnum;
  area->floodvalid = pBSPData->floodvalid;
  v5 = &pBSPData->map_areaportals.m_pArray[area->firstareaportal];
  i = 0;
  if ( !v4 )
  {
    do
    {
      if ( pBSPData->portalopen.m_pArray[v5->m_PortalKey] )
        FloodArea_r(pBSPData, area: &pBSPData->map_areas.m_pArray[v5->otherarea], floodnum);
      ++v5;
      ++i;
    }
    while ( i < area->numareaportals );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D670
// Name: void FloodAreaConnections(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodAreaConnections(CCollisionBSPData *pBSPData)
{
  int v2; // eax
  carea_t *v3; // esi
  int firstareaportal; // ecx
  bool v5; // zf
  bool v6; // sf
  dareaportal_t *v7; // ebx
  int floodnum; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]
  int pBSPDataa; // [esp+18h] [ebp+8h]

  ++pBSPData->floodvalid;
  v2 = 0;
  i = 1;
  if ( pBSPData->numareas > 1 )
  {
    pBSPDataa = 1;
    do
    {
      v3 = &pBSPData->map_areas.m_pArray[pBSPDataa];
      if ( v3->floodvalid != pBSPData->floodvalid )
      {
        firstareaportal = v3->firstareaportal;
        ++v2;
        v5 = v3->numareaportals == 0;
        v6 = v3->numareaportals < 0;
        v3->floodnum = v2;
        v3->floodvalid = pBSPData->floodvalid;
        floodnum = v2;
        v7 = &pBSPData->map_areaportals.m_pArray[firstareaportal];
        v10 = 0;
        if ( !v6 && !v5 )
        {
          do
          {
            if ( pBSPData->portalopen.m_pArray[v7->m_PortalKey] )
            {
              FloodArea_r(pBSPData, area: &pBSPData->map_areas.m_pArray[v7->otherarea], floodnum: v2);
              v2 = floodnum;
            }
            ++v7;
            ++v10;
          }
          while ( v10 < v3->numareaportals );
        }
      }
      ++pBSPDataa;
      ++i;
    }
    while ( i < pBSPData->numareas );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D740
// Name: void CM_SetAreaPortalState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetAreaPortalState(int portalnum, int isOpen)
{
  if ( portalnum > g_BSPData.numareaportals )
    Sys_Error(error: "portalnum > numareaportals");
  g_BSPData.portalopen.m_pArray[portalnum] = isOpen != 0;
  FloodAreaConnections(pBSPData: &g_BSPData);
}

//------------------------------------------------------------------------------
// Address: 0x1014D780
// Name: void CM_SetAreaPortalStates(int const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetAreaPortalStates(char *portalnums, char *isOpen, int nPortals)
{
  int v3; // ebx
  char *v4; // esi
  int v5; // edx
  bool v6; // cl
  int v7; // edi
  int v8; // esi
  int v9; // ebx

  v3 = nPortals;
  if ( nPortals != 0 )
  {
    if ( nPortals > 0 )
    {
      v4 = portalnums;
      do
      {
        if ( *(_DWORD *)v4 > g_BSPData.numareaportals )
          Sys_Error(error: "portalnum > numareaportals");
        v5 = *(_DWORD *)v4;
        v6 = *(_DWORD *)&v4[isOpen - portalnums] != 0;
        v4 += 4;
        --v3;
        g_BSPData.portalopen.m_pArray[v5] = v6;
      }
      while ( v3 != 0 );
    }
    ++g_BSPData.floodvalid;
    v7 = 1;
    v8 = 0;
    if ( g_BSPData.numareas > 1 )
    {
      v9 = 1;
      do
      {
        if ( g_BSPData.map_areas.m_pArray[v9].floodvalid != g_BSPData.floodvalid )
          FloodArea_r(pBSPData: &g_BSPData, area: &g_BSPData.map_areas.m_pArray[v9], floodnum: ++v8);
        ++v7;
        ++v9;
      }
      while ( v7 < g_BSPData.numareas );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D830
// Name: bool CM_AreasConnected(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CM_AreasConnected(int area1, int area2)
{
  if ( map_noareas.m_pParent != nullptr && map_noareas.m_pParent->m_Value.m_nValue != 0 )
    return true;
  if ( area1 >= g_BSPData.numareas || area2 >= g_BSPData.numareas )
    Sys_Error(
      error: "area(1==%i, 2==%i) >= numareas (%i):  Check if engine->ResetPVS() was called from ClientSetupVisibility",
      area1,
      area2,
      g_BSPData.numareas);
  return g_BSPData.map_areas.m_pArray[area1].floodnum == g_BSPData.map_areas.m_pArray[area2].floodnum;
}

//------------------------------------------------------------------------------
// Address: 0x1014D890
// Name: void CM_LeavesConnected(class Vector const __near &,int,int const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_LeavesConnected(const Vector *vecOrigin, int nCount, const int *pLeaves, bool *pIsConnected)
{
  int v4; // eax
  int v5; // ecx
  int i; // eax

  if ( map_noareas.m_pParent != nullptr && map_noareas.m_pParent->m_Value.m_nValue != 0 )
  {
    memset(dst: (unsigned __int8 *)pIsConnected, value: 1u, count: nCount);
  }
  else
  {
    if ( g_BSPData.numplanes != 0 )
      v4 = CM_PointLeafnum_r(pBSPData: &g_BSPData, p: vecOrigin, num: 0);
    else
      v4 = 0;
    v5 = (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[v4] + 3) << 7) >> 7;
    for ( i = 0; i < nCount; ++i )
      pIsConnected[i] = g_BSPData.map_areas.m_pArray[v5].floodnum == g_BSPData.map_areas.m_pArray[(__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[pLeaves[i]] + 3) << 7) >> 7].floodnum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D940
// Name: int CM_WriteAreaBits(unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_WriteAreaBits(unsigned __int8 *buffer, int buflen, int area)
{
  int v3; // ebx
  int m_nValue; // eax
  int v6; // eax
  int v7; // edx
  int bytes; // [esp+8h] [ebp-4h]
  int floodnum; // [esp+18h] [ebp+Ch]

  if ( buflen < 32 )
    Sys_Error(error: "CM_WriteAreaBits with buffer size %d < 32\n", buflen);
  v3 = (g_BSPData.numareas + 7) >> 3;
  bytes = v3;
  if ( map_noareas.m_pParent != nullptr && (m_nValue = map_noareas.m_pParent->m_Value.m_nValue) != 0 )
  {
    _V_memset(dest: buffer, fill: (unsigned __int8)-(m_nValue != 2), count: buflen);
    return v3;
  }
  else
  {
    _V_memset(dest: buffer, fill: 0, count: buflen);
    floodnum = g_BSPData.map_areas.m_pArray[area].floodnum;
    v6 = 0;
    if ( g_BSPData.numareas > 0 )
    {
      v7 = 0;
      do
      {
        if ( g_BSPData.map_areas.m_pArray[v7].floodnum == floodnum || area == 0 )
        {
          buffer[v6 >> 3] |= 1 << (v6 & 7);
          v3 = bytes;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < g_BSPData.numareas );
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DA10
// Name: bool CM_GetAreaPortalPlane(class Vector const __near &,int,class VPlane __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CM_GetAreaPortalPlane(const Vector *vViewOrigin, int portalKey, VPlane *pPlane)
{
  int v3; // eax
  int v4; // eax
  carea_t *v5; // eax
  int numareaportals; // edx
  int v7; // ecx
  dareaportal_t *i; // eax
  double x; // st7
  cplane_t *v11; // eax

  if ( g_BSPData.numplanes != 0 )
  {
    v3 = CM_PointLeafnum_r(pBSPData: &g_BSPData, p: vViewOrigin, num: 0);
    if ( v3 < 0 )
      return 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v3 >= g_BSPData.numleafs )
    return 0;
  v4 = (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[v3] + 3) << 7) >> 7;
  if ( v4 < 0 || v4 >= g_BSPData.numareas )
    return 0;
  v5 = &g_BSPData.map_areas.m_pArray[v4];
  numareaportals = v5->numareaportals;
  v7 = 0;
  if ( v5->numareaportals <= 0 )
    return 0;
  for ( i = &g_BSPData.map_areaportals.m_pArray[v5->firstareaportal]; i->m_PortalKey != portalKey; ++i )
  {
    if ( ++v7 >= numareaportals )
      return 0;
  }
  x = g_BSPData.map_planes.m_pArray[i->planenum].normal.x;
  v11 = &g_BSPData.map_planes.m_pArray[i->planenum];
  pPlane->m_Normal.x = x;
  pPlane->m_Normal.y = v11->normal.y;
  pPlane->m_Normal.z = v11->normal.z;
  pPlane->m_Dist = v11->dist;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DAE0
// Name: bool CM_HeadnodeVisible(int,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CM_HeadnodeVisible(int nodenum, const unsigned __int8 *visbits, int vissize)
{
  int v3; // eax
  cnode_t *map_rootnode; // ebx
  cnode_t *v5; // esi
  int cluster; // eax

  v3 = nodenum;
  if ( nodenum < 0 )
  {
LABEL_5:
    cluster = g_BSPData.map_leafs.m_pArray[-v3 - 1].cluster;
    return cluster != -1 && ((unsigned __int8)(1 << (cluster & 7)) & visbits[cluster >> 3]) != 0;
  }
  else
  {
    map_rootnode = g_BSPData.map_rootnode;
    while ( 1 )
    {
      v5 = &map_rootnode[v3];
      if ( CM_HeadnodeVisible(nodenum: v5->children[0], visbits, vissize) )
        return true;
      v3 = v5->children[1];
      if ( v3 < 0 )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DB60
// Name: int CM_BoxVisible(class Vector const __near &,class Vector const __near &,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxVisible(const Vector *mins, const Vector *maxs, const unsigned __int8 *visbits, int vissize)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  int v10; // ebx
  int cluster; // edi
  int v12; // esi
  int leafList[256]; // [esp+0h] [ebp-428h] BYREF
  leafnums_t context; // [esp+400h] [ebp-28h] BYREF
  Vector extents; // [esp+410h] [ebp-18h] BYREF
  Vector center; // [esp+41Ch] [ebp-Ch] BYREF
  const Vector *maxsa; // [esp+434h] [ebp+Ch]

  x = mins->x;
  y = mins->y;
  z = mins->z;
  context.pLeafList = leafList;
  v7 = maxs->x;
  v8 = maxs->y;
  v9 = maxs->z;
  v10 = 0;
  context.leafTopNode = -1;
  context.leafMaxCount = 256;
  context.pBSPData = &g_BSPData;
  center.x = (float)(x + v7) * 0.5;
  center.y = (float)(y + v8) * 0.5;
  center.z = (float)(z + v9) * 0.5;
  extents.x = v7 - center.x;
  extents.y = v8 - center.y;
  extents.z = v9 - center.z;
  maxsa = nullptr;
  if ( g_BSPData.numcmodels > 0 )
    maxsa = (const Vector *)CM_BoxLeafnums(
                              &context,
                              &center,
                              &extents,
                              nodenum: g_BSPData.map_cmodels.m_pArray->headnode);
  if ( (int)maxsa <= 0 )
    return 0;
  while ( 1 )
  {
    cluster = g_BSPData.map_leafs.m_pArray[leafList[v10]].cluster;
    v12 = cluster >> 3;
    if ( cluster >> 3 > vissize )
      Sys_Error(error: "CM_BoxVisible:  cluster %i, offset %i out of bounds %i\n", cluster, v12, vissize);
    if ( ((unsigned __int8)(1 << (cluster & 7)) & visbits[v12]) != 0 )
      break;
    if ( ++v10 >= (int)maxsa )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DC90
// Name: void CM_SetupAreaFloodNums(unsigned char __near * const,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetupAreaFloodNums(unsigned __int8 *areaFloodNums, int *pNumAreas)
{
  int v2; // eax
  int v3; // ecx

  *pNumAreas = g_BSPData.numareas;
  if ( g_BSPData.numareas > 256 )
    _Error(a1: "pBSPData->numareas > MAX_MAP_AREAS");
  v2 = 0;
  if ( g_BSPData.numareas > 0 )
  {
    v3 = 0;
    do
      areaFloodNums[v2++] = g_BSPData.map_areas.m_pArray[v3++].floodnum;
    while ( v2 < g_BSPData.numareas );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DCF0
// Name: public: CFastPointLeafNum::CFastPointLeafNum(void)
// Source: json
//------------------------------------------------------------------------------
CFastPointLeafNum *__thiscall CFastPointLeafNum::CFastPointLeafNum(CFastPointLeafNum *this)
{
  this->m_flDistToExitLeafSqr = -1.0;
  this->m_iCachedLeaf = -1;
  this->m_vCachedPos.x = 0.0;
  this->m_vCachedPos.y = 0.0;
  this->m_vCachedPos.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014DD20
// Name: public: int CFastPointLeafNum::GetLeaf(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFastPointLeafNum::GetLeaf(CFastPointLeafNum *this, const Vector *vPos)
{
  int m_iCachedLeaf; // ecx
  int result; // eax

  m_iCachedLeaf = this->m_iCachedLeaf;
  if ( m_iCachedLeaf >= 0
    && m_iCachedLeaf < g_BSPData.numleafs
    && (float)((float)((float)((float)(vPos->y - this->m_vCachedPos.y) * (float)(vPos->y - this->m_vCachedPos.y))
                     + (float)((float)(vPos->x - this->m_vCachedPos.x) * (float)(vPos->x - this->m_vCachedPos.x)))
             + (float)((float)(vPos->z - this->m_vCachedPos.z) * (float)(vPos->z - this->m_vCachedPos.z))) <= this->m_flDistToExitLeafSqr )
  {
    return m_iCachedLeaf;
  }
  this->m_vCachedPos = *vPos;
  this->m_flDistToExitLeafSqr = 1.0e24;
  result = CM_PointLeafnumMinDistSqr_r(pBSPData: &g_BSPData, p: vPos, num: 0, minDistSqr: &this->m_flDistToExitLeafSqr);
  this->m_iCachedLeaf = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014DDB0
// Name: void CM_ClipBoxToBrush<1>(struct TraceInfo_t restrict __near *,struct cbrush_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_ClipBoxToBrush<1>(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // ecx
  float v4; // xmm7_4
  cbrushside_t *v5; // eax
  char v6; // bl
  cbrushside_t *v7; // edx
  cbrushside_t *v8; // edi
  float v9; // xmm0_4
  float *p_x; // ecx
  float dist; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  bool v16; // cf
  const char *name; // eax
  int v18; // ecx
  unsigned __int16 surfaceIndex; // di
  csurface_t *SurfaceAtIndex; // eax
  int v21; // edx
  const cplane_t *plane; // [esp-Ch] [ebp-1Ch]
  int brushContents; // [esp+4h] [ebp-Ch]
  float leavefrac; // [esp+8h] [ebp-8h]
  bool startout; // [esp+Fh] [ebp-1h]

  numsides = brush->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    IntersectRayWithBoxBrush(
      pTraceInfo,
      pBrush: brush,
      pBox: &pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside]);
    return;
  }
  if ( (_WORD)numsides != 0 )
  {
    v4 = -99999.0;
    brushContents = brush->contents;
    v5 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[brush->firstbrushside];
    v6 = 0;
    v7 = &v5[numsides];
    v8 = nullptr;
    v9 = 1.0;
    leavefrac = 1.0;
    startout = false;
    if ( v5 >= v7 )
    {
LABEL_22:
      pTraceInfo->m_trace.startsolid = true;
      pTraceInfo->m_trace.contents = brushContents;
      if ( v6 != 0 )
      {
        if ( v9 != 1.0 && v9 > pTraceInfo->m_trace.fractionleftsolid )
        {
          v16 = v9 < pTraceInfo->m_trace.fraction;
          pTraceInfo->m_trace.fractionleftsolid = v9;
          if ( !v16 )
          {
            name = CCollisionBSPData::nullsurface.name;
            v18 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
            pTraceInfo->m_trace.fraction = 1.0;
            pTraceInfo->m_trace.surface.name = name;
            *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v18;
          }
        }
      }
      else
      {
        pTraceInfo->m_trace.allsolid = true;
        pTraceInfo->m_trace.fraction = 0.0;
        pTraceInfo->m_trace.fractionleftsolid = 1.0;
      }
      return;
    }
    while ( 1 )
    {
      p_x = &v5->plane->normal.x;
      dist = v5->plane->dist;
      if ( v5->bBevel == 0 )
      {
        v12 = (float)((float)((float)(pTraceInfo->m_start.y * p_x[1]) + (float)(*p_x * pTraceInfo->m_start.x))
                    + (float)(pTraceInfo->m_start.z * p_x[2]))
            - dist;
        v13 = (float)((float)((float)(pTraceInfo->m_end.y * p_x[1]) + (float)(pTraceInfo->m_end.x * *p_x))
                    + (float)(pTraceInfo->m_end.z * p_x[2]))
            - dist;
        if ( v12 > 0.0 )
        {
          startout = true;
          if ( v13 > 0.0 )
            return;
          goto LABEL_11;
        }
        if ( v13 > 0.0 )
        {
          v6 = 1;
LABEL_11:
          if ( v12 <= v13 )
          {
            if ( leavefrac > (float)((float)(v12 + 0.03125) / (float)(v12 - v13)) )
              leavefrac = (float)(v12 + 0.03125) / (float)(v12 - v13);
          }
          else
          {
            v14 = v12 - 0.03125;
            if ( (float)(v12 - 0.03125) < 0.0 )
              v14 = 0.0;
            v15 = v14 / (float)(v12 - v13);
            if ( v15 > v4 )
            {
              v4 = v15;
              v8 = v5;
            }
          }
        }
      }
      if ( ++v5 >= v7 )
      {
        if ( !startout || (float)(pTraceInfo->m_trace.fractionleftsolid - v4) > 0.0 )
        {
          v9 = leavefrac;
          goto LABEL_22;
        }
        if ( leavefrac > v4 && v4 > -99999.0 && pTraceInfo->m_trace.fraction > v4 )
        {
          if ( v4 < 0.0 )
            v4 = 0.0;
          plane = v8->plane;
          pTraceInfo->m_trace.fraction = v4;
          pTraceInfo->m_bDispHit = 0;
          cplane_t::operator=(this: &pTraceInfo->m_trace.plane, __that: plane);
          surfaceIndex = v8->surfaceIndex;
          SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: pTraceInfo->m_pBSPData, surfaceIndex);
          v21 = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
          pTraceInfo->m_trace.surface.name = SurfaceAtIndex->name;
          *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v21;
          pTraceInfo->m_trace.worldSurfaceIndex = surfaceIndex;
          pTraceInfo->m_trace.contents = brushContents;
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E040
// Name: void CM_ClipBoxToBrush<0>(struct TraceInfo_t restrict __near *,struct cbrush_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_ClipBoxToBrush<0>(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // ecx
  cbrushside_t *v4; // eax
  char v5; // bl
  cbrushside_t *v6; // edx
  cbrushside_t *v7; // edi
  float v8; // xmm1_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  bool v15; // cf
  const char *name; // eax
  int v17; // ecx
  float v18; // xmm0_4
  unsigned __int16 surfaceIndex; // di
  csurface_t *SurfaceAtIndex; // eax
  const char *v21; // ecx
  int v22; // edx
  const cplane_t *plane; // [esp-Ch] [ebp-40h]
  float x; // [esp+18h] [ebp-1Ch]
  float dist; // [esp+1Ch] [ebp-18h]
  int brushContents; // [esp+24h] [ebp-10h]
  float enterfrac; // [esp+28h] [ebp-Ch]
  float leavefrac; // [esp+2Ch] [ebp-8h]
  bool startout; // [esp+33h] [ebp-1h]

  numsides = brush->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    IntersectRayWithBoxBrush(
      pTraceInfo,
      pBrush: brush,
      pBox: &pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside]);
    return;
  }
  if ( (_WORD)numsides != 0 )
  {
    brushContents = brush->contents;
    v4 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[brush->firstbrushside];
    enterfrac = -99999.0;
    v5 = 0;
    v6 = &v4[numsides];
    v7 = nullptr;
    v8 = 1.0;
    leavefrac = 1.0;
    startout = false;
    if ( v4 >= v6 )
    {
LABEL_19:
      pTraceInfo->m_trace.startsolid = true;
      pTraceInfo->m_trace.contents = brushContents;
      if ( v5 != 0 )
      {
        if ( v8 != 1.0 && v8 > pTraceInfo->m_trace.fractionleftsolid )
        {
          v15 = v8 < pTraceInfo->m_trace.fraction;
          pTraceInfo->m_trace.fractionleftsolid = v8;
          if ( !v15 )
          {
            name = CCollisionBSPData::nullsurface.name;
            v17 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
            pTraceInfo->m_trace.fraction = 1.0;
            pTraceInfo->m_trace.surface.name = name;
            *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v17;
          }
        }
      }
      else
      {
        pTraceInfo->m_trace.allsolid = true;
        pTraceInfo->m_trace.fraction = 0.0;
        pTraceInfo->m_trace.fractionleftsolid = 1.0;
      }
      return;
    }
    while ( 1 )
    {
      y = v4->plane->normal.y;
      z = v4->plane->normal.z;
      x = v4->plane->normal.x;
      dist = fabs(y * pTraceInfo->m_extents.y)
           + fabs(x * pTraceInfo->m_extents.x)
           + fabs(z * pTraceInfo->m_extents.z)
           + v4->plane->dist;
      v11 = (float)((float)((float)(pTraceInfo->m_start.y * y) + (float)(pTraceInfo->m_start.x * x))
                  + (float)(pTraceInfo->m_start.z * z))
          - dist;
      v12 = (float)((float)((float)(y * pTraceInfo->m_end.y) + (float)(x * pTraceInfo->m_end.x))
                  + (float)(z * pTraceInfo->m_end.z))
          - dist;
      if ( v11 > 0.0 )
        break;
      if ( v12 > 0.0 )
      {
        v5 = 1;
LABEL_10:
        if ( v11 <= v12 )
        {
          if ( leavefrac > (float)((float)(v11 + 0.03125) / (float)(v11 - v12)) )
            leavefrac = (float)(v11 + 0.03125) / (float)(v11 - v12);
        }
        else
        {
          v13 = v11 - 0.03125;
          if ( (float)(v11 - 0.03125) < 0.0 )
            v13 = 0.0;
          v14 = v13 / (float)(v11 - v12);
          if ( v14 > enterfrac )
          {
            enterfrac = v14;
            v7 = v4;
          }
        }
      }
      if ( ++v4 >= v6 )
      {
        v8 = leavefrac;
        if ( !startout )
          goto LABEL_19;
        v18 = enterfrac;
        if ( leavefrac > enterfrac && enterfrac > -99999.0 && pTraceInfo->m_trace.fraction > enterfrac )
        {
          if ( enterfrac < 0.0 )
            v18 = 0.0;
          plane = v7->plane;
          pTraceInfo->m_trace.fraction = v18;
          pTraceInfo->m_bDispHit = 0;
          cplane_t::operator=(this: &pTraceInfo->m_trace.plane, __that: plane);
          surfaceIndex = v7->surfaceIndex;
          SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: pTraceInfo->m_pBSPData, surfaceIndex);
          v21 = SurfaceAtIndex->name;
          v22 = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
          pTraceInfo->m_trace.worldSurfaceIndex = surfaceIndex;
          pTraceInfo->m_trace.surface.name = v21;
          *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v22;
          pTraceInfo->m_trace.contents = brushContents;
        }
        return;
      }
    }
    startout = true;
    if ( v12 > 0.0 )
      return;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E350
// Name: void PushTraceVisits(struct TraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PushTraceVisits(TraceInfo_t *pTraceInfo)
{
  int v1; // ecx
  unsigned __int8 **v3; // esi

  v1 = ++pTraceInfo->m_nCheckDepth;
  if ( pTraceInfo->m_Count[v1]++ == -1 )
  {
    pTraceInfo->m_Count[v1] = 1;
    v3 = (unsigned __int8 **)((char *)pTraceInfo + 20 * v1);
    memset(dst: v3[74], value: 0, count: 4 * (_DWORD)v3[77]);
    memset(dst: v3[84], value: 0, count: 4 * (_DWORD)v3[87]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E3C0
// Name: struct vcollide_t __near * CM_GetVCollide(int)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__cdecl CM_GetVCollide(int modelIndex)
{
  cmodel_t *v1; // eax

  if ( modelIndex >= 0
    && modelIndex <= g_BSPData.numcmodels
    && (v1 = &g_BSPData.map_cmodels.m_pArray[modelIndex]) != nullptr )
  {
    return &v1->vcollisionData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E400
// Name: char __near * CM_EntityString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CM_EntityString()
{
  if ( g_BSPData.map_entitystring.m_buf.m_Put != 0
    || g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: g_BSPData.map_entitystring.m_pFilename,
         a3: nullptr,
         a4: &g_BSPData.map_entitystring.m_buf,
         a5: g_BSPData.map_entitystring.m_nCount,
         a6: g_BSPData.map_entitystring.m_nOffset,
         a7: nullptr) )
  {
    return (char *)&g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory[g_BSPData.map_entitystring.m_buf.m_Get
                                                                      - g_BSPData.map_entitystring.m_buf.m_nOffset];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E450
// Name: void CM_RegisterPaintMap(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_RegisterPaintMap(CCollisionBSPData *pBSPData)
{
  char *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *FirstValue; // eax
  bool v5; // bl

  if ( pBSPData->map_entitystring.m_buf.m_Put != 0
    || g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: pBSPData->map_entitystring.m_pFilename,
         a3: nullptr,
         a4: &pBSPData->map_entitystring.m_buf,
         a5: pBSPData->map_entitystring.m_nCount,
         a6: pBSPData->map_entitystring.m_nOffset,
         a7: nullptr) )
  {
    v1 = (char *)&pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory[pBSPData->map_entitystring.m_buf.m_Get
                                                                    - pBSPData->map_entitystring.m_buf.m_nOffset];
  }
  else
  {
    v1 = nullptr;
  }
  v2 = (KeyValues *)V_stristr(pStr: v1, pSearch: "paintinmap");
  if ( v2 != nullptr )
  {
    v3 = KeyValues::FromString(szName: defaultValue, szStringVal: v2, ppEndOfParse: nullptr);
    FirstValue = KeyValues::GetFirstValue(this: v3);
    v5 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue)[1] == 49;
    KeyValues::deleteThis(this: v3);
    g_PaintManager.m_bShouldRegister = v5;
  }
  else
  {
    g_PaintManager.m_bShouldRegister = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E510
// Name: struct cmodel_t __near * CM_LoadMap(char const __near *,bool,struct texinfo_s __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
cmodel_t *__usercall CM_LoadMap@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        lumpfileheader_t *pPathName,
        bool allowReusePrevious,
        texinfo_s *pTexinfo,
        int texinfoCount,
        unsigned int *checksum)
{
  int i; // eax

  if ( strcmp(g_BSPData.mapPathName, (const char *)pPathName) == 0 && allowReusePrevious )
  {
    *checksum = last_checksum;
    return g_BSPData.map_cmodels.m_pArray;
  }
  else
  {
    CollisionBSPData_PreLoad(pBSPData: &g_BSPData);
    if ( pPathName != nullptr && LOBYTE(pPathName->lumpOffset) != 0 )
    {
      CMapLoadHelper::Init(a1, a2, p_lumpHeader: pPathName, pMapModel: nullptr, (char *)pPathName);
      CollisionBSPData_Load((const char *)pPathName, pBSPData: &g_BSPData, pTexinfo, texinfoCount);
      CMapLoadHelper::Shutdown();
      CM_DispTreeLeafnum(pBSPData: &g_BSPData);
      for ( i = 0; i < g_BSPData.numportalopen; ++i )
        g_BSPData.portalopen.m_pArray[i] = false;
      FloodAreaConnections(pBSPData: &g_BSPData);
      CM_RegisterPaintMap(pBSPData: &g_BSPData);
      return g_BSPData.map_cmodels.m_pArray;
    }
    else
    {
      *checksum = 0;
      return g_BSPData.map_cmodels.m_pArray;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E600
// Name: struct vcollide_t __near * CM_VCollideForModel(int,struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__cdecl CM_VCollideForModel(int modelindex, const model_t *pModel)
{
  int v3; // eax
  cmodel_t *v4; // eax

  if ( pModel->type == mod_brush )
  {
    v3 = modelindex - 1;
    if ( modelindex - 1 < 0 )
      return nullptr;
    if ( v3 > g_BSPData.numcmodels )
      return nullptr;
    v4 = &g_BSPData.map_cmodels.m_pArray[v3];
    if ( v4 == nullptr )
      return nullptr;
    return &v4->vcollisionData;
  }
  else
  {
    if ( pModel->type != mod_studio )
      return nullptr;
    return ((vcollide_t *(__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: pModel->studio);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E660
// Name: CM_TestInLeaf
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_TestInLeaf(TraceInfo_t *pTraceInfo@<ecx>, int ndxLeaf@<eax>)
{
  cleaf_t *v2; // esi
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  int v5; // eax
  CCollisionBSPData *m_pBSPData; // edx
  int v7; // eax
  const cbrush_t *v8; // edx
  int dispCount; // eax
  unsigned int count; // [esp+Ch] [ebp-8h]
  int ndxLeafBrush; // [esp+10h] [ebp-4h]

  v2 = &pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  count = pTraceInfo->m_Count[m_nCheckDepth];
  v5 = 0;
  ndxLeafBrush = 0;
  if ( v2->numleafbrushes != 0 )
  {
    while ( 1 )
    {
      m_pBSPData = pTraceInfo->m_pBSPData;
      v7 = m_pBSPData->map_leafbrushes.m_pArray[v5 + v2->firstleafbrush];
      v8 = &m_pBSPData->map_brushes.m_pArray[v7];
      if ( m_pMemory[v7] != count )
      {
        m_pMemory[v7] = count;
        if ( (pTraceInfo->m_contents & v8->contents) != 0 )
        {
          CM_TestBoxInBrush(pTraceInfo, brush: v8);
          if ( pTraceInfo->m_trace.fraction == 0.0 )
            break;
        }
      }
      v5 = ndxLeafBrush + 1;
      ndxLeafBrush = v5;
      if ( v5 >= v2->numleafbrushes )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( !pTraceInfo->m_trace.startsolid )
    {
      dispCount = v2->dispCount;
      if ( (_WORD)dispCount != 0 )
        CM_TestInDispTree(
          pTraceInfo,
          pDispList: &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v2->dispListStart],
          dispListCount: dispCount,
          traceStart: &pTraceInfo->m_start,
          boxMin: &pTraceInfo->m_mins,
          boxMax: &pTraceInfo->m_maxs,
          collisionMask: pTraceInfo->m_contents,
          pTrace: &pTraceInfo->m_trace);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E750
// Name: CM_UnsweptBoxTrace
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_UnsweptBoxTrace(TraceInfo_t *pTraceInfo@<esi>, const Ray_t *ray, int headnode)
{
  CCollisionBSPData *m_pBSPData; // edx
  float x; // xmm0_4
  float y; // xmm0_4
  float v6; // xmm0_4
  int v7; // ebx
  int v8; // edi
  int ndxLeaf[1024]; // [esp+0h] [ebp-101Ch] BYREF
  leafnums_t context; // [esp+1000h] [ebp-1Ch] BYREF
  Vector extents; // [esp+1010h] [ebp-Ch] BYREF
  char center_3; // [esp+1027h] [ebp+Bh]

  m_pBSPData = pTraceInfo->m_pBSPData;
  x = ray->m_Extents.x;
  context.pLeafList = ndxLeaf;
  extents.x = x + 1.0;
  y = ray->m_Extents.y;
  context.pBSPData = m_pBSPData;
  extents.y = y + 1.0;
  v6 = ray->m_Extents.z + 1.0;
  context.leafTopNode = -1;
  context.leafMaxCount = 1024;
  center_3 = 0;
  extents.z = v6;
  v7 = CM_BoxLeafnums(&context, center: &ray->m_Start, &extents, nodenum: headnode);
  v8 = 0;
  if ( v7 <= 0 )
    goto LABEL_7;
  do
  {
    if ( (pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf[v8]].contents & 1) == 0 )
      center_3 = 1;
    CM_TestInLeaf(pTraceInfo, ndxLeaf: ndxLeaf[v8]);
    if ( pTraceInfo->m_trace.allsolid )
      break;
    ++v8;
  }
  while ( v8 < v7 );
  if ( center_3 == 0 )
  {
LABEL_7:
    *(_WORD *)&pTraceInfo->m_trace.allsolid = 257;
    pTraceInfo->m_trace.fraction = 0.0;
    pTraceInfo->m_trace.fractionleftsolid = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E850
// Name: public: class CGameTrace __near & CGameTrace::operator=(class CGameTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CGameTrace *__thiscall CGameTrace::operator=(CGameTrace *this, const CGameTrace *__that)
{
  CBaseTrace::operator=(this, __that);
  this->fractionleftsolid = __that->fractionleftsolid;
  this->surface = __that->surface;
  this->hitgroup = __that->hitgroup;
  this->physicsbone = __that->physicsbone;
  this->worldSurfaceIndex = __that->worldSurfaceIndex;
  this->m_pEnt = __that->m_pEnt;
  this->hitbox = __that->hitbox;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014E8A0
// Name: public: void CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(
        CUtlMemoryFixedGrowable<unsigned short,32,int> *this,
        int nCount)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = this->m_nMallocGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 2 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (unsigned __int16 *)v5;
      CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x1014E910
// Name: void CM_DiscardEntityString(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DiscardEntityString()
{
  g_BSPData.map_entitystring.m_buf.m_Get = 0;
  g_BSPData.map_entitystring.m_buf.m_Put = 0;
  g_BSPData.map_entitystring.m_buf.m_nOffset = 0;
  g_BSPData.map_entitystring.m_buf.m_nMaxPut = 0;
  g_BSPData.map_entitystring.m_buf.m_Error = 0;
  if ( g_BSPData.map_entitystring.m_buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory);
      g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory = nullptr;
    }
    g_BSPData.map_entitystring.m_buf.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E960
// Name: void CM_TraceToLeaf<1>(struct TraceInfo_t restrict __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TraceToLeaf<1>(TraceInfo_t *pTraceInfo, int ndxLeaf, float startFrac, float endFrac)
{
  CCollisionBSPData *m_pBSPData; // eax
  unsigned __int16 *v6; // edx
  int v7; // ecx
  int v8; // edx
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  const cbrush_t *v13; // edx
  int m_contents; // ecx
  int numsides; // edi
  int v16; // ecx
  unsigned __int16 *surfaceIndex; // edx
  int v18; // eax
  csurface_t *v19; // eax
  int v20; // ecx
  int v21; // eax
  csurface_t *v22; // eax
  unsigned __int16 *v23; // ecx
  int v24; // eax
  unsigned int *v25; // edx
  int v26; // eax
  int v27; // edi
  alignedbbox_t *v28; // ecx
  const unsigned __int16 **v29; // eax
  unsigned __int16 *v30; // [esp+8h] [ebp-24h]
  unsigned __int16 *v31; // [esp+8h] [ebp-24h]
  int v32; // [esp+Ch] [ebp-20h]
  unsigned int *v33; // [esp+Ch] [ebp-20h]
  unsigned __int16 *pDispList; // [esp+10h] [ebp-1Ch]
  unsigned int v35; // [esp+14h] [ebp-18h]
  CRangeValidatedArray<cbrush_t> *p_map_brushes; // [esp+18h] [ebp-14h]
  int v37; // [esp+1Ch] [ebp-10h]
  unsigned int *v38; // [esp+20h] [ebp-Ch]
  const unsigned __int16 *pBrushList; // [esp+24h] [ebp-8h]
  const unsigned __int16 *pBrushLista; // [esp+24h] [ebp-8h]
  const cbrush_t *v41; // [esp+28h] [ebp-4h]
  unsigned __int16 *p_surfaceIndex; // [esp+28h] [ebp-4h]
  int v43; // [esp+28h] [ebp-4h]

  m_pBSPData = pTraceInfo->m_pBSPData;
  v6 = (unsigned __int16 *)&m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v7 = v6[5];
  v30 = v6;
  if ( (_WORD)v7 == 0 )
    goto LABEL_28;
  v8 = (int)&m_pBSPData->map_leafbrushes.m_pArray[v6[4]];
  p_map_brushes = &m_pBSPData->map_brushes;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v37 = v8;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v35 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = nullptr;
  v32 = v7;
  v38 = m_pMemory;
  pBrushList = nullptr;
  while ( 1 )
  {
    v12 = *(unsigned __int16 *)(v37 + 2 * (_DWORD)v11);
    v13 = &p_map_brushes->m_pArray[v12];
    v41 = v13;
    if ( m_pMemory[v12] == v35 )
      goto LABEL_25;
    m_pMemory[v12] = v35;
    m_contents = pTraceInfo->m_contents;
    if ( (v13->contents & m_contents) == 0 )
      goto LABEL_25;
    if ( (v13->contents & pTraceInfo->m_contents) != 128 || (m_contents & 0x2000) == 0 )
      goto LABEL_24;
    numsides = v13->numsides;
    if ( (_WORD)numsides == 0xFFFF )
    {
      v16 = 0;
      surfaceIndex = pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v18 = *surfaceIndex;
        v19 = (_WORD)v18 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v18];
        if ( SLOBYTE(v19->flags) < 0 )
          goto LABEL_25;
        ++v16;
        ++surfaceIndex;
        if ( v16 >= 6 )
        {
          v13 = v41;
          goto LABEL_24;
        }
      }
    }
    v20 = 0;
    if ( v13->numsides != 0 )
    {
      p_surfaceIndex = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v21 = *p_surfaceIndex;
        v22 = (_WORD)v21 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v21];
        if ( SLOBYTE(v22->flags) < 0 )
          break;
        p_surfaceIndex += 4;
        if ( ++v20 >= numsides )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      CM_ClipBoxToBrush<1>(pTraceInfo, brush: v13);
      if ( pTraceInfo->m_trace.fraction == 0.0 )
        break;
    }
LABEL_25:
    v11 = (const unsigned __int16 *)((char *)pBrushList + 1);
    pBrushList = v11;
    if ( (int)v11 >= v32 )
      break;
    m_pMemory = v38;
  }
  if ( pTraceInfo->m_trace.startsolid )
    return;
  v6 = v30;
LABEL_28:
  if ( v6[7] == 0 )
    return;
  v31 = &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v6[6]];
  v23 = (unsigned __int16 *)v6[7];
  v24 = pTraceInfo->m_nCheckDepth;
  v25 = pTraceInfo->m_DispCounters[v24].m_Memory.m_pMemory;
  pBrushLista = (const unsigned __int16 *)pTraceInfo->m_Count[v24];
  v26 = 0;
  pDispList = v23;
  v33 = v25;
  v43 = 0;
  while ( 2 )
  {
    v27 = v31[v26];
    v28 = &g_pDispBounds[v27];
    if ( (v28->dispContents & pTraceInfo->m_contents) == 0 )
      goto LABEL_36;
    if ( pTraceInfo->m_isswept )
    {
      v29 = (const unsigned __int16 **)&v33[v28->dispCounter];
      if ( *v29 != pBrushLista )
      {
        *v29 = pBrushLista;
        break;
      }
LABEL_36:
      v26 = v43 + 1;
      v43 = v26;
      if ( v26 >= (int)pDispList )
        goto LABEL_37;
      continue;
    }
    break;
  }
  if ( !IsBoxIntersectingRay(
          boxMin: &v28->mins,
          boxMax: &v28->maxs,
          origin: &pTraceInfo->m_start,
          vecDelta: &pTraceInfo->m_delta,
          vecInvDelta: &pTraceInfo->m_invDelta,
          flTolerance: 0.03125) )
    goto LABEL_36;
  CM_TraceToDispTree<1>(pTraceInfo, pDispTree: &g_pDispCollTrees[v27], startFrac, endFrac);
  if ( pTraceInfo->m_trace.fraction != 0.0 )
    goto LABEL_36;
LABEL_37:
  CM_PostTraceToDispTree(pTraceInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1014EC30
// Name: void CM_TraceToLeaf<0>(struct TraceInfo_t restrict __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TraceToLeaf<0>(TraceInfo_t *pTraceInfo, int ndxLeaf, float startFrac, float endFrac)
{
  CCollisionBSPData *m_pBSPData; // eax
  unsigned __int16 *v6; // edx
  unsigned int *v7; // ecx
  int v8; // edx
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  const cbrush_t *v13; // edx
  int m_contents; // ecx
  unsigned __int16 *numsides; // edi
  int v16; // ecx
  unsigned __int16 *surfaceIndex; // edx
  int v18; // eax
  csurface_t *v19; // eax
  int v20; // ecx
  int plane_low; // eax
  csurface_t *v22; // eax
  unsigned __int16 *v23; // eax
  unsigned __int16 *v24; // ecx
  int v25; // eax
  unsigned int *v26; // edx
  int v27; // eax
  int v28; // edi
  alignedbbox_t *v29; // eax
  const unsigned __int16 **v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  Vector boxMin; // [esp+8h] [ebp-3Ch] BYREF
  Vector boxMax; // [esp+14h] [ebp-30h] BYREF
  unsigned __int16 *v38; // [esp+20h] [ebp-24h]
  unsigned int *v39; // [esp+24h] [ebp-20h]
  unsigned __int16 *pDispList; // [esp+28h] [ebp-1Ch]
  unsigned int v41; // [esp+2Ch] [ebp-18h]
  CRangeValidatedArray<cbrush_t> *p_map_brushes; // [esp+30h] [ebp-14h]
  int v43; // [esp+34h] [ebp-10h]
  unsigned int *v44; // [esp+38h] [ebp-Ch]
  const unsigned __int16 *pBrushList; // [esp+3Ch] [ebp-8h]
  cbrushside_t *v46; // [esp+40h] [ebp-4h]

  m_pBSPData = pTraceInfo->m_pBSPData;
  v6 = (unsigned __int16 *)&m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v7 = (unsigned int *)v6[5];
  v38 = v6;
  if ( (_WORD)v7 == 0 )
    goto LABEL_28;
  v8 = (int)&m_pBSPData->map_leafbrushes.m_pArray[v6[4]];
  p_map_brushes = &m_pBSPData->map_brushes;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v43 = v8;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v41 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = nullptr;
  v39 = v7;
  v44 = m_pMemory;
  pBrushList = nullptr;
  while ( 1 )
  {
    v12 = *(unsigned __int16 *)(v43 + 2 * (_DWORD)v11);
    v13 = &p_map_brushes->m_pArray[v12];
    v46 = (cbrushside_t *)v13;
    if ( m_pMemory[v12] == v41 )
      goto LABEL_25;
    m_pMemory[v12] = v41;
    m_contents = pTraceInfo->m_contents;
    if ( (v13->contents & m_contents) == 0 )
      goto LABEL_25;
    if ( (v13->contents & pTraceInfo->m_contents) != 128 || (m_contents & 0x2000) == 0 )
      goto LABEL_24;
    numsides = (unsigned __int16 *)v13->numsides;
    if ( (_WORD)numsides == 0xFFFF )
    {
      v16 = 0;
      surfaceIndex = pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v18 = *surfaceIndex;
        v19 = (_WORD)v18 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v18];
        if ( SLOBYTE(v19->flags) < 0 )
          goto LABEL_25;
        ++v16;
        ++surfaceIndex;
        if ( v16 >= 6 )
        {
          v13 = (const cbrush_t *)v46;
          goto LABEL_24;
        }
      }
    }
    v46 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[v13->firstbrushside];
    v20 = 0;
    pDispList = numsides;
    if ( (int)numsides > 0 )
    {
      v46 = (cbrushside_t *)((char *)v46 + 4);
      while ( 1 )
      {
        plane_low = LOWORD(v46->plane);
        v22 = (_WORD)plane_low == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[plane_low];
        if ( SLOBYTE(v22->flags) < 0 )
          break;
        ++v46;
        if ( ++v20 >= (int)pDispList )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      CM_ClipBoxToBrush<0>(pTraceInfo, brush: v13);
      if ( pTraceInfo->m_trace.fraction == 0.0 )
        break;
    }
LABEL_25:
    v11 = (const unsigned __int16 *)((char *)pBrushList + 1);
    pBrushList = v11;
    if ( (int)v11 >= (int)v39 )
      break;
    m_pMemory = v44;
  }
  if ( pTraceInfo->m_trace.startsolid )
    return;
  v6 = v38;
LABEL_28:
  v23 = (unsigned __int16 *)v6[7];
  if ( (_WORD)v23 == 0 )
    return;
  v38 = &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v6[6]];
  v24 = v23;
  v25 = pTraceInfo->m_nCheckDepth;
  v26 = pTraceInfo->m_DispCounters[v25].m_Memory.m_pMemory;
  pBrushList = (const unsigned __int16 *)pTraceInfo->m_Count[v25];
  v27 = 0;
  pDispList = v24;
  v39 = v26;
  v46 = nullptr;
  while ( 2 )
  {
    v28 = v38[v27];
    v29 = &g_pDispBounds[v28];
    if ( (v29->dispContents & pTraceInfo->m_contents) == 0 )
      goto LABEL_36;
    if ( pTraceInfo->m_isswept )
    {
      v30 = (const unsigned __int16 **)&v39[v29->dispCounter];
      if ( *v30 != pBrushList )
      {
        *v30 = pBrushList;
        break;
      }
LABEL_36:
      v27 = (int)&v46->plane + 1;
      v46 = (cbrushside_t *)v27;
      if ( v27 >= (int)pDispList )
        goto LABEL_37;
      continue;
    }
    break;
  }
  v31 = v29->mins.y - pTraceInfo->m_extents.y;
  v32 = pTraceInfo->m_extents.x + v29->maxs.x;
  v33 = v29->maxs.y + pTraceInfo->m_extents.y;
  boxMax.z = v29->maxs.z + pTraceInfo->m_extents.z;
  v34 = v29->mins.x - pTraceInfo->m_extents.x;
  boxMin.y = v31;
  v35 = v29->mins.z - pTraceInfo->m_extents.z;
  boxMax.x = v32;
  boxMax.y = v33;
  boxMin.x = v34;
  boxMin.z = v35;
  if ( !IsBoxIntersectingRay(
          &boxMin,
          &boxMax,
          origin: &pTraceInfo->m_start,
          vecDelta: &pTraceInfo->m_delta,
          vecInvDelta: &pTraceInfo->m_invDelta,
          flTolerance: 0.03125) )
    goto LABEL_36;
  CM_TraceToDispTree<0>(pTraceInfo, pDispTree: &g_pDispCollTrees[v28], startFrac, endFrac);
  if ( pTraceInfo->m_trace.fraction != 0.0 )
    goto LABEL_36;
LABEL_37:
  CM_PostTraceToDispTree(pTraceInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1014EF60
// Name: public: TraceInfo_t::~TraceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TraceInfo_t::~TraceInfo_t(TraceInfo_t *this)
{
  TraceInfo_t *v2; // esi
  float x; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_DispCounters; // esi
  int j; // ebx
  unsigned int *m_pMemory; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = this + 1;
  for ( i = 1; i >= 0; --i )
  {
    v2 = (TraceInfo_t *)((char *)v2 - 20);
    v2->m_end.x = 0.0;
    if ( v2->m_start.z >= 0.0 )
    {
      if ( LODWORD(v2->m_start.x) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v2->m_start.x));
        v2->m_start.x = 0.0;
      }
      v2->m_start.y = 0.0;
    }
    x = v2->m_start.x;
    v2->m_end.y = v2->m_start.x;
    if ( v2->m_start.z >= 0.0 )
    {
      if ( x != 0.0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(x));
        v2->m_start.x = 0.0;
      }
      v2->m_start.y = 0.0;
    }
  }
  m_DispCounters = this->m_DispCounters;
  for ( j = 1; j >= 0; --j )
  {
    --m_DispCounters;
    m_DispCounters->m_Size = 0;
    if ( m_DispCounters->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_DispCounters->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_DispCounters->m_Memory.m_pMemory);
        m_DispCounters->m_Memory.m_pMemory = nullptr;
      }
      m_DispCounters->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = m_DispCounters->m_Memory.m_pMemory;
    m_DispCounters->m_pElements = m_DispCounters->m_Memory.m_pMemory;
    if ( m_DispCounters->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_DispCounters->m_Memory.m_pMemory = nullptr;
      }
      m_DispCounters->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F040
// Name: CM_RecursiveHullCheckImpl_1_
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_RecursiveHullCheckImpl_1_(
        TraceInfo_t *pTraceInfo,
        int num,
        float p1f,
        float p2f,
        const Vector *p1,
        const Vector *p2)
{
  bool v6; // cf
  int v7; // ebx
  cnode_t *v10; // edx
  float *p_x; // eax
  unsigned __int8 type; // cl
  float dist; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int v20; // ebx
  double v21; // st6
  double v22; // st7
  float v23; // xmm0_4
  float v24; // xmm0_4
  Vector p2a; // [esp+0h] [ebp-1Ch] BYREF
  cnode_t *endFrac; // [esp+Ch] [ebp-10h]
  cnode_t *map_rootnode; // [esp+10h] [ebp-Ch]
  float v28; // [esp+14h] [ebp-8h]
  TraceInfo_t *v29; // [esp+18h] [ebp-4h]
  float p1a; // [esp+2Ch] [ebp+10h]
  float offset; // [esp+30h] [ebp+14h]

  v6 = p1f < pTraceInfo->m_trace.fraction;
  v7 = num;
  v29 = pTraceInfo;
  if ( !v6 )
    return;
  if ( num < 0 )
  {
LABEL_17:
    CM_TraceToLeaf<1>(pTraceInfo, ndxLeaf: -1 - v7, startFrac: p1f, endFrac: p2f);
    return;
  }
  map_rootnode = pTraceInfo->m_pBSPData->map_rootnode;
  while ( 1 )
  {
    v10 = &map_rootnode[v7];
    p_x = &v10->plane->normal.x;
    type = v10->plane->type;
    dist = v10->plane->dist;
    endFrac = v10;
    if ( type >= 3u )
    {
      v14 = (float)((float)(p1->y * p_x[1]) + (float)(*p_x * p1->x)) + (float)(p1->z * p_x[2]);
      v15 = (float)((float)(p2->y * p_x[1]) + (float)(*p_x * p2->x)) + (float)(p2->z * p_x[2]);
      v16 = 0.0;
    }
    else
    {
      v14 = *(&p1->x + type);
      v15 = *(&p2->x + type);
      v16 = *(&v29->m_extents.x + type);
    }
    v17 = v14 - dist;
    v18 = v15 - dist;
    v28 = v16;
    if ( v17 <= v16 || v18 <= v16 )
      break;
    v7 = v10->children[0];
LABEL_13:
    if ( v7 < 0 )
      goto LABEL_16;
  }
  v19 = -v16;
  if ( v19 > v17 && v19 > v18 )
  {
    v7 = v10->children[1];
    goto LABEL_13;
  }
  if ( v7 < 0 )
  {
LABEL_16:
    pTraceInfo = v29;
    goto LABEL_17;
  }
  if ( v18 > v17 )
  {
    v20 = 1;
    v21 = 1.0 / (v17 - v18);
    offset = (v28 + v17 + 0.03125) * v21;
    v22 = v17 - v28 - 0.03125;
    goto LABEL_20;
  }
  v20 = 0;
  if ( v17 <= v18 )
  {
    offset = 0.0;
    goto LABEL_26;
  }
  v21 = 1.0 / (v17 - v18);
  offset = (v17 - v28 - 0.03125) * v21;
  v22 = v17 + v28 + 0.03125;
LABEL_20:
  p1a = v22 * v21;
  v23 = p1a;
  if ( p1a < 0.0 )
  {
    v23 = 0.0;
    goto LABEL_27;
  }
  if ( p1a > 1.0 )
LABEL_26:
    v23 = 1.0;
LABEL_27:
  p2a.x = (float)((float)(p2->x - p1->x) * v23) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v23) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v23) + p1->z;
  CM_RecursiveHullCheckImpl_1_(
    pTraceInfo: v29,
    num: v10->children[v20],
    p1f,
    p2f: (float)((float)(p2f - p1f) * v23) + p1f,
    p1,
    p2: &p2a);
  v24 = 0.0;
  if ( offset >= 0.0 )
  {
    v24 = 1.0;
    if ( offset <= 1.0 )
      v24 = offset;
  }
  p2a.x = (float)((float)(p2->x - p1->x) * v24) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v24) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v24) + p1->z;
  CM_RecursiveHullCheckImpl_1_(
    pTraceInfo: v29,
    num: endFrac->children[v20 ^ 1],
    p1f: (float)((float)(p2f - p1f) * v24) + p1f,
    p2f,
    p1: &p2a,
    p2);
}

//------------------------------------------------------------------------------
// Address: 0x1014F320
// Name: CM_RecursiveHullCheckImpl_0_
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __fastcall CM_RecursiveHullCheckImpl_0_(
        TraceInfo_t *pTraceInfo,
        int num,
        float p1f,
        float p2f,
        const Vector *p1,
        const Vector *p2)
{
  bool v7; // cf
  cnode_t *v10; // edx
  float *p_x; // eax
  unsigned __int8 type; // cl
  float dist; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  long double v17; // st7
  double x; // st7
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  long double v23; // st5
  long double v24; // rt2
  long double v25; // st5
  long double v26; // st7
  long double v27; // st6
  float v28; // xmm0_4
  long double v29; // st5
  float v30; // xmm2_4
  float v31; // xmm0_4
  Vector p2a; // [esp+0h] [ebp-20h] BYREF
  cnode_t *endFrac; // [esp+Ch] [ebp-14h]
  float v34; // [esp+10h] [ebp-10h]
  cnode_t *map_rootnode; // [esp+14h] [ebp-Ch]
  float v36; // [esp+18h] [ebp-8h]
  int mid; // [esp+1Ch] [ebp-4h] OVERLAPPED
  float p1a; // [esp+30h] [ebp+10h]
  float t2a; // [esp+34h] [ebp+14h]
  int t2; // [esp+34h] [ebp+14h]

  v7 = p1f < pTraceInfo->m_trace.fraction;
  mid = num;
  if ( !v7 )
    return;
  if ( num < 0 )
    goto LABEL_16;
  map_rootnode = pTraceInfo->m_pBSPData->map_rootnode;
  while ( 1 )
  {
    v10 = &map_rootnode[mid];
    p_x = &v10->plane->normal.x;
    type = v10->plane->type;
    dist = v10->plane->dist;
    endFrac = v10;
    if ( type >= 3u )
    {
      x = pTraceInfo->m_extents.x;
      v19 = p1->y * p_x[1];
      v34 = *p_x;
      v15 = (float)(v19 + (float)(v34 * p1->x)) + (float)(p1->z * p_x[2]);
      v16 = (float)((float)(p2->y * p_x[1]) + (float)(v34 * p2->x)) + (float)(p2->z * p_x[2]);
      v17 = fabs(x * v34) + fabs(pTraceInfo->m_extents.y * p_x[1]) + fabs(pTraceInfo->m_extents.z * p_x[2]);
      t2a = v17;
      v14 = t2a;
    }
    else
    {
      v14 = *(&pTraceInfo->m_extents.x + type);
      v15 = *(&p1->x + type);
      v16 = *(&p2->x + type);
      v17 = v14;
    }
    v20 = v15 - dist;
    v21 = v16 - dist;
    v36 = v21;
    if ( v20 <= v14 || v21 <= v14 )
      break;
    mid = v10->children[0];
LABEL_13:
    if ( mid < 0 )
      goto LABEL_16;
  }
  v22 = -v14;
  if ( v22 > v20 && v22 > v21 )
  {
    mid = v10->children[1];
    goto LABEL_13;
  }
  if ( mid < 0 )
  {
LABEL_16:
    CM_TraceToLeaf<0>(pTraceInfo, ndxLeaf: -1 - mid, startFrac: p1f, endFrac: p2f);
    return;
  }
  if ( v21 > v20 )
  {
    t2 = 1;
    v23 = 1.0 / (v20 - v36);
    p1a = (v17 + v20 + 0.03125) * v23;
    v24 = v23;
    v25 = v20 - v17;
    v26 = v24;
    v27 = v25 - 0.03125;
    goto LABEL_19;
  }
  t2 = 0;
  if ( v20 <= v21 )
  {
    p1a = 0.0;
    goto LABEL_25;
  }
  v29 = 1.0 / (v20 - v36);
  p1a = (v20 - v17 - 0.03125) * v29;
  v27 = v29;
  v26 = v20 + v17 + 0.03125;
LABEL_19:
  v36 = v26 * v27;
  v28 = v36;
  if ( v36 < 0.0 )
  {
    v28 = 0.0;
    goto LABEL_26;
  }
  if ( v36 > 1.0 )
LABEL_25:
    v28 = 1.0;
LABEL_26:
  p2a.x = (float)((float)(p2->x - p1->x) * v28) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v28) + p1->y;
  v30 = (float)((float)(p2->z - p1->z) * v28) + p1->z;
  v34 = p2f - p1f;
  p2a.z = v30;
  CM_RecursiveHullCheckImpl_0_(
    pTraceInfo,
    num: v10->children[t2],
    p1f,
    p2f: (float)((float)(p2f - p1f) * v28) + p1f,
    p1,
    p2: &p2a);
  v31 = 0.0;
  if ( p1a >= 0.0 )
  {
    v31 = 1.0;
    if ( p1a <= 1.0 )
      v31 = p1a;
  }
  p2a.x = (float)((float)(p2->x - p1->x) * v31) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v31) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v31) + p1->z;
  CM_RecursiveHullCheckImpl_0_(
    pTraceInfo,
    num: endFrac->children[t2 ^ 1],
    p1f: (float)(v34 * v31) + p1f,
    p2f,
    p1: &p2a,
    p2);
}

//------------------------------------------------------------------------------
// Address: 0x1014F6B0
// Name: public: TraceInfo_t::TraceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
TraceInfo_t *__thiscall TraceInfo_t::TraceInfo_t(TraceInfo_t *this)
{
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_BrushCounters; // eax
  int i; // edx
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_DispCounters; // eax
  int j; // edx

  m_BrushCounters = this->m_BrushCounters;
  for ( i = 1; i >= 0; --i )
  {
    m_BrushCounters->m_Memory.m_pMemory = nullptr;
    m_BrushCounters->m_Memory.m_nAllocationCount = 0;
    m_BrushCounters->m_Memory.m_nGrowSize = 0;
    m_BrushCounters->m_Size = 0;
    m_BrushCounters->m_pElements = nullptr;
    ++m_BrushCounters;
  }
  m_DispCounters = this->m_DispCounters;
  for ( j = 1; j >= 0; --j )
  {
    m_DispCounters->m_Memory.m_pMemory = nullptr;
    m_DispCounters->m_Memory.m_nAllocationCount = 0;
    m_DispCounters->m_Memory.m_nGrowSize = 0;
    m_DispCounters->m_Size = 0;
    m_DispCounters->m_pElements = nullptr;
    ++m_DispCounters;
  }
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x128u);
  this->m_nCheckDepth = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014F720
// Name: void CM_RecursiveHullCheck(struct TraceInfo_t __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_RecursiveHullCheck(TraceInfo_t *pTraceInfo, int num, float p1f, float p2f)
{
  Vector *p_m_end; // [esp-4h] [ebp-4h]

  p_m_end = &pTraceInfo->m_end;
  if ( pTraceInfo->m_ispoint )
    CM_RecursiveHullCheckImpl_1_(pTraceInfo, num, p1f, p2f, p1: &pTraceInfo->m_start, p2: p_m_end);
  else
    CM_RecursiveHullCheckImpl_0_(pTraceInfo, num, p1f, p2f, p1: &pTraceInfo->m_start, p2: p_m_end);
}

//------------------------------------------------------------------------------
// Address: 0x1014F760
// Name: void CM_GetTraceDataForLeaf(struct TraceInfo_t restrict __near *,int,class CTraceListData __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_GetTraceDataForLeaf(TraceInfo_t *pTraceInfo, int ndxLeaf, CTraceListData *traceData)
{
  TraceInfo_t *v3; // ebx
  cleaf_t *v4; // edx
  bool v5; // zf
  unsigned int firstleafbrush; // esi
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // ecx
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  cleaf_t *v12; // esi
  int v13; // ecx
  CCollisionBSPData *dispCount; // eax
  unsigned int v15; // ecx
  int v16; // ebx
  alignedbbox_t *v17; // eax
  int dispCounter; // ecx
  unsigned int *v19; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *v22; // ecx
  int v23; // eax
  unsigned __int16 *v24; // edi
  cleaf_t *pLeaf; // [esp+10h] [ebp-14h]
  cleaf_t *pLeafa; // [esp+10h] [ebp-14h]
  unsigned int *pCounters; // [esp+14h] [ebp-10h]
  unsigned int *pCountersa; // [esp+14h] [ebp-10h]
  unsigned __int16 src[2]; // [esp+18h] [ebp-Ch] BYREF
  CCollisionBSPData *m_pBSPData; // [esp+1Ch] [ebp-8h]
  unsigned int count; // [esp+20h] [ebp-4h]

  v3 = pTraceInfo;
  v4 = &pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v5 = (v4->contents & 1) == 0;
  m_pBSPData = pTraceInfo->m_pBSPData;
  pLeaf = v4;
  if ( v5 )
    traceData->m_bFoundNonSolidLeaf = true;
  firstleafbrush = v4->firstleafbrush;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v9 = firstleafbrush + v4->numleafbrushes;
  pCounters = m_pMemory;
  count = v3->m_Count[m_nCheckDepth];
  if ( firstleafbrush < v9 )
  {
    do
    {
      v10 = m_pBSPData->map_leafbrushes.m_pArray[firstleafbrush];
      if ( m_pMemory[v10] != count )
      {
        m_pMemory[v10] = count;
        *(_DWORD *)src = v10;
        CUtlVector<unsigned short,CUtlMemoryFixedGrowable<unsigned short,64,int>>::InsertBefore(
          this: &traceData->m_brushList,
          elem: traceData->m_brushList.m_Size,
          src);
        m_pMemory = pCounters;
      }
      ++firstleafbrush;
    }
    while ( (int)firstleafbrush < (int)v9 );
    v4 = pLeaf;
  }
  v11 = v3->m_nCheckDepth;
  v12 = (cleaf_t *)v3->m_Count[v11];
  v13 = v11;
  dispCount = (CCollisionBSPData *)v4->dispCount;
  pCountersa = v3->m_DispCounters[v13].m_Memory.m_pMemory;
  pLeafa = v12;
  if ( v4->dispCount != 0 )
  {
    v15 = 2 * v4->dispListStart;
    count = v15;
    m_pBSPData = dispCount;
    while ( 1 )
    {
      v16 = *(unsigned __int16 *)((char *)v3->m_pBSPData->map_dispList.m_pArray + v15);
      v17 = &g_pDispBounds[v16];
      dispCounter = v17->dispCounter;
      v5 = pCountersa[dispCounter] == (_DWORD)v12;
      v19 = &pCountersa[dispCounter];
      if ( !v5 )
      {
        *v19 = (unsigned int)v12;
        if ( IsBoxIntersectingBox(
               boxMin1: &v17->mins,
               boxMax1: &v17->maxs,
               boxMin2: &traceData->m_mins,
               boxMax2: &traceData->m_maxs) )
        {
          m_Size = traceData->m_dispList.m_Size;
          m_nAllocationCount = traceData->m_dispList.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(
              this: &traceData->m_dispList.m_Memory,
              nCount: m_Size - m_nAllocationCount + 1);
          ++traceData->m_dispList.m_Size;
          v22 = traceData->m_dispList.m_Memory.m_pMemory;
          v23 = traceData->m_dispList.m_Size - m_Size - 1;
          traceData->m_dispList.m_pElements = v22;
          if ( v23 > 0 )
            _V_memmove(dest: &v22[m_Size + 1], src: &v22[m_Size], count: 2 * v23);
          v24 = &traceData->m_dispList.m_Memory.m_pMemory[m_Size];
          if ( v24 != nullptr )
            *v24 = v16;
        }
      }
      v15 = count + 2;
      v5 = m_pBSPData == (CCollisionBSPData *)1;
      m_pBSPData = (CCollisionBSPData *)((char *)m_pBSPData - 1);
      count += 2;
      if ( v5 )
        break;
      v3 = pTraceInfo;
      v12 = pLeafa;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F920
// Name: struct TraceInfo_t __near * BeginTrace(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t **__cdecl BeginTrace()
{
  TSLNodeBase_t *v0; // eax
  char *v1; // eax
  TSLNodeBase_t *v2; // esi
  TSLNodeBase_t **v3; // ebx
  TSLNodeBase_t *v4; // esi
  bool v5; // zf
  int v6; // edi
  TSLNodeBase_t *Next; // eax
  char *v8; // ecx
  int v9; // eax
  int v10; // edi
  TSLNodeBase_t *v11; // eax
  char *v12; // ecx
  int v13; // eax
  TSLNodeBase_t *v14; // eax
  TSLNodeBase_t **v15; // esi
  int i; // [esp+8h] [ebp-4h]

  v0 = CTSListBase::Pop(this: &g_TraceInfoPool);
  if ( v0 == nullptr )
  {
    v1 = (char *)MemAlloc_Alloc(nSize: 0x180u);
    v2 = (TSLNodeBase_t *)v1;
    if ( v1 != nullptr )
    {
      TraceInfo_t::TraceInfo_t(this: (TraceInfo_t *)(v1 + 4));
      v0 = v2;
    }
    else
    {
      v0 = nullptr;
    }
  }
  v3 = &v0->Next + 1;
  v4 = v0 + 39;
  if ( v0[39].Next != (TSLNodeBase_t *)(g_BSPData.numbrushes + 1) )
  {
    *((_DWORD *)&v0[36].Next + 1) = 0;
    v0[37].Next = nullptr;
    v0[36].Next = (TSLNodeBase_t *)-1;
    for ( i = 2; i != 0; --i )
    {
      v6 = g_BSPData.numbrushes + 1;
      v5 = g_BSPData.numbrushes == -1;
      v4->Next = nullptr;
      if ( !v5 )
      {
        Next = v4[-1].Next;
        if ( v6 > (int)Next )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)(&v4[-2].Next + 1),
            num: v6 - (_DWORD)Next);
        v4->Next = (TSLNodeBase_t *)((char *)v4->Next + v6);
        v8 = *((char **)&v4[-2].Next + 1);
        v9 = (int)v4->Next - v6;
        *((_DWORD *)&v4->Next + 1) = v8;
        if ( v9 > 0 && v6 > 0 )
          _V_memmove(dest: &v8[4 * v6], src: v8, count: 4 * v9);
      }
      v10 = g_DispCollTreeCount;
      v4[5].Next = nullptr;
      if ( v10 != 0 )
      {
        v11 = v4[4].Next;
        if ( v10 > (int)v11 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(&v4[3].Next + 1), num: v10 - (_DWORD)v11);
        v4[5].Next = (TSLNodeBase_t *)((char *)v4[5].Next + v10);
        v12 = *((char **)&v4[3].Next + 1);
        v13 = (int)v4[5].Next - v10;
        *((_DWORD *)&v4[5].Next + 1) = v12;
        if ( v13 > 0 && v10 > 0 )
          _V_memmove(dest: &v12[4 * v10], src: v12, count: 4 * v13);
      }
      memset(dst: *((unsigned __int8 **)&v4[-2].Next + 1), value: 0, count: 4 * (int)v4->Next);
      memset(dst: *((unsigned __int8 **)&v4[3].Next + 1), value: 0, count: 4 * (int)v4[5].Next);
      v4 = (TSLNodeBase_t *)((char *)v4 + 20);
    }
  }
  v3[71] = (TSLNodeBase_t *)((char *)v3[71] + 1);
  v14 = v3[71];
  v5 = (TSLNodeBase_t **)((char *)&v3[(_DWORD)v14 + 72]->Next + 1) == nullptr;
  v3[(_DWORD)v14 + 72] = (TSLNodeBase_t *)((char *)v3[(_DWORD)v14 + 72] + 1);
  if ( v5 )
  {
    v3[(_DWORD)v14 + 72] = (TSLNodeBase_t *)1;
    v15 = &v3[5 * (_DWORD)v14];
    memset(dst: (unsigned __int8 *)v15[74], value: 0, count: 4 * (_DWORD)v15[77]);
    memset(dst: (unsigned __int8 *)v15[84], value: 0, count: 4 * (_DWORD)v15[87]);
  }
  v3[65] = (TSLNodeBase_t *)&g_BSPData;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014FAE0
// Name: void CM_GetTraceDataForBSP(class Vector const __near &,class Vector const __near &,class CTraceListData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_GetTraceDataForBSP(const Vector *mins, TraceInfo_t *maxs, CTraceListData *traceData)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // esi
  int v9; // ebx
  int v10; // edi
  cnode_t *v11; // eax
  cplane_t *plane; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  _DWORD v15[1024]; // [esp+0h] [ebp-1024h]
  float v16; // [esp+1000h] [ebp-24h]
  float v17; // [esp+1004h] [ebp-20h]
  float v18; // [esp+1008h] [ebp-1Ch]
  float v19; // [esp+100Ch] [ebp-18h]
  float v20; // [esp+1010h] [ebp-14h]
  float v21; // [esp+1014h] [ebp-10h]
  float v22; // [esp+1018h] [ebp-Ch]
  float v23; // [esp+101Ch] [ebp-8h]
  float v24; // [esp+1020h] [ebp-4h]
  float v25; // [esp+102Ch] [ebp+8h]
  TraceInfo_t *pTraceInfo; // [esp+1030h] [ebp+Ch]

  x = maxs->m_start.x;
  y = maxs->m_start.y;
  z = maxs->m_start.z;
  v6 = (float)(mins->y + y) * 0.5;
  v7 = (float)(mins->z + z) * 0.5;
  v21 = (float)(mins->x + maxs->m_start.x) * 0.5;
  v22 = v6;
  v23 = v7;
  v17 = x - v21;
  v18 = y - v6;
  v19 = z - v7;
  v8 = 0;
  v9 = 0;
  pTraceInfo = (TraceInfo_t *)BeginTrace();
  v10 = 0;
  while ( 1 )
  {
    while ( v8 >= 0 )
    {
      v11 = &g_BSPData.map_rootnode[v8];
      plane = v11->plane;
      v13 = v11->plane->normal.z;
      v25 = v11->plane->normal.y;
      v16 = v11->plane->normal.x;
      v20 = v13;
      v14 = (float)((float)((float)(v25 * v22) + (float)(v16 * v21)) + (float)(v13 * v23)) - plane->dist;
      v24 = fabs(v25 * v18) + fabs(v16 * v17) + fabs(v13 * v19);
      if ( v14 < v24 )
      {
        v8 = v11->children[1];
        if ( COERCE_FLOAT(LODWORD(v24) ^ _mask__NegFloat_) <= v14 )
        {
          v15[v10] = v11->children[0];
          v10 = ((_WORD)v10 + 1) & 0x3FF;
        }
      }
      else
      {
        v8 = v11->children[0];
      }
    }
    CM_GetTraceDataForLeaf(pTraceInfo, ndxLeaf: -1 - v8, traceData);
    if ( v9 == v10 )
      break;
    v8 = v15[v9];
    v9 = ((_WORD)v9 + 1) & 0x3FF;
  }
  --pTraceInfo->m_nCheckDepth;
  CTSListBase::Push(this: &g_TraceInfoPool, pNode: (TSLNodeBase_t *)&pTraceInfo[-1].m_DispCounters[1].m_pElements);
}

//------------------------------------------------------------------------------
// Address: 0x1014FC60
// Name: void CM_BoxTraceAgainstLeafList(struct Ray_t const __near &,class CTraceListData const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_BoxTraceAgainstLeafList(
        const Ray_t *ray,
        const CTraceListData *traceData,
        const Ray_t *nBrushMask,
        CGameTrace *trace)
{
  TSLNodeBase_t **v4; // esi
  float v5; // xmm0_4
  float x; // xmm1_4
  float v7; // xmm3_4
  const Ray_t *v8; // edi
  float y; // xmm2_4
  float v10; // xmm1_4
  float z; // xmm2_4
  const cbrush_t *v12; // edx
  int m_Size; // ecx
  unsigned __int16 *m_pMemory; // edx
  TSLNodeBase_t *v15; // eax
  bool v16; // zf
  int v17; // ecx
  TSLNodeBase_t *Next; // edx
  TSLNodeBase_t *v19; // eax
  const cbrush_t *v20; // edx
  unsigned int v21; // ecx
  int v22; // eax
  int numsides; // edi
  int v24; // ecx
  TSLNodeBase_t *v25; // edx
  int Next_low; // eax
  csurface_t *v27; // eax
  int v28; // ecx
  int x_low; // eax
  csurface_t *v30; // eax
  int v31; // edx
  int v32; // eax
  const cbrush_t *v33; // edx
  unsigned int v34; // ecx
  int v35; // eax
  int v36; // edi
  int v37; // ecx
  TSLNodeBase_t *v38; // edx
  int v39; // eax
  csurface_t *v40; // eax
  int v41; // ecx
  int v42; // eax
  csurface_t *v43; // eax
  int v44; // eax
  int v45; // edi
  alignedbbox_t *v46; // ecx
  int v47; // edi
  alignedbbox_t *v48; // eax
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  float *v53; // ecx
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  TSLNodeBase_t **v57; // esi
  int v58; // [esp-Ch] [ebp-40h]
  int v59; // [esp-Ch] [ebp-40h]
  TSLHead_t m_Head; // [esp-8h] [ebp-3Ch]
  TSLHead_t v61; // [esp-8h] [ebp-3Ch]
  Vector boxMin; // [esp+8h] [ebp-2Ch] BYREF
  Vector boxMax; // [esp+14h] [ebp-20h] BYREF
  unsigned __int16 *v64; // [esp+20h] [ebp-14h]
  int v65; // [esp+24h] [ebp-10h]
  unsigned __int16 *v66; // [esp+28h] [ebp-Ch]
  TSLNodeBase_t *v67; // [esp+2Ch] [ebp-8h]
  int v68; // [esp+30h] [ebp-4h]
  int raya; // [esp+44h] [ebp+10h]
  const Ray_t *rayb; // [esp+44h] [ebp+10h]
  const Ray_t *rayc; // [esp+44h] [ebp+10h]
  const Ray_t *rayd; // [esp+44h] [ebp+10h]
  const Ray_t *raye; // [esp+44h] [ebp+10h]
  const Ray_t *rayf; // [esp+44h] [ebp+10h]
  const Ray_t *rayg; // [esp+44h] [ebp+10h]
  const Ray_t *rayh; // [esp+44h] [ebp+10h]

  v4 = BeginTrace();
  memset(dst: (unsigned __int8 *)v4 + 84, value: 0, count: 0x54u);
  v4[35] = nullptr;
  v4[32] = (TSLNodeBase_t *)1065353216;
  *((csurface_t *)v4 + 18) = CCollisionBSPData::nullsurface;
  v4[69] = nullptr;
  v4[66] = nullptr;
  v4[67] = nullptr;
  v4[68] = nullptr;
  v4[63] = (TSLNodeBase_t *)nBrushMask;
  *(Vector *)v4 = ray->m_Start.Vector;
  *((float *)v4 + 3) = ray->m_Delta.x + ray->m_Start.x;
  *((float *)v4 + 4) = ray->m_Delta.y + ray->m_Start.y;
  *((float *)v4 + 5) = ray->m_Delta.z + ray->m_Start.z;
  *((float *)v4 + 6) = ray->m_Extents.x * -1.0;
  *((float *)v4 + 7) = ray->m_Extents.y * -1.0;
  *((float *)v4 + 8) = ray->m_Extents.z * -1.0;
  *((Vector *)v4 + 3) = ray->m_Extents.Vector;
  v5 = 3.4028235e38;
  *((Vector *)v4 + 4) = ray->m_Extents.Vector;
  *((Vector *)v4 + 5) = ray->m_Delta.Vector;
  x = ray->m_Delta.x;
  if ( x == 0.0 )
    v7 = 3.4028235e38;
  else
    v7 = 1.0 / x;
  v8 = ray;
  y = ray->m_Delta.y;
  if ( y == 0.0 )
    v10 = 3.4028235e38;
  else
    v10 = 1.0 / y;
  z = ray->m_Delta.z;
  if ( z != 0.0 )
    v5 = 1.0 / z;
  *((float *)v4 + 18) = v7;
  *((float *)v4 + 19) = v10;
  *((float *)v4 + 20) = v5;
  *((_BYTE *)v4 + 256) = ray->m_IsRay;
  *((_BYTE *)v4 + 257) = ray->m_IsSwept;
  if ( ray->m_IsSwept )
  {
    m_Size = traceData->m_brushList.m_Size;
    m_pMemory = traceData->m_brushList.m_Memory.m_pMemory;
    v15 = v4[65] + 21;
    v16 = !ray->m_IsRay;
    v68 = 0;
    if ( !v16 )
    {
      v64 = (unsigned __int16 *)m_Size;
      v66 = m_pMemory;
      v67 = v15;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v17 = v66[v68];
          Next = v15->Next;
          v19 = v15->Next[v17].Next;
          v20 = (const cbrush_t *)&Next[v17];
          v21 = (unsigned int)v4[63];
          v22 = v21 & (unsigned int)v19;
          rayb = (const Ray_t *)v20;
          if ( v22 == 0 )
            goto LABEL_41;
          if ( v22 != 128 || (v21 & 0x2000) == 0 )
            goto LABEL_40;
          numsides = v20->numsides;
          if ( (_WORD)numsides == 0xFFFF )
          {
            v24 = 0;
            v25 = &v4[65][14].Next[6 * v20->firstbrushside + 4];
            while ( 1 )
            {
              Next_low = LOWORD(v25->Next);
              v27 = (_WORD)Next_low == 0xFFFF
                  ? &CCollisionBSPData::nullsurface
                  : (csurface_t *)&v4[65][67].Next[Next_low];
              if ( SLOBYTE(v27->flags) < 0 )
                goto LABEL_41;
              ++v24;
              v25 = (TSLNodeBase_t *)((char *)v25 + 2);
              if ( v24 >= 6 )
              {
                v20 = (const cbrush_t *)rayb;
                goto LABEL_40;
              }
            }
          }
          rayc = (const Ray_t *)&v4[65][13].Next[v20->firstbrushside];
          v28 = 0;
          v65 = v20->numsides;
          if ( numsides > 0 )
          {
            rayd = (const Ray_t *)&rayc->m_Start.y;
            while ( 1 )
            {
              x_low = LOWORD(rayd->m_Start.x);
              v30 = (_WORD)x_low == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[x_low];
              if ( SLOBYTE(v30->flags) < 0 )
                break;
              rayd = (const Ray_t *)((char *)rayd + 8);
              if ( ++v28 >= v65 )
                goto LABEL_40;
            }
          }
          else
          {
LABEL_40:
            CM_ClipBoxToBrush<1>(pTraceInfo: (TraceInfo_t *)v4, brush: v20);
            if ( *((float *)v4 + 32) == 0.0 )
              break;
          }
LABEL_41:
          if ( ++v68 >= (int)v64 )
            break;
          v15 = v67;
        }
      }
LABEL_64:
      if ( *((float *)v4 + 32) > 0.0 && *((_BYTE *)v4 + 139) == 0 )
      {
        v16 = !ray->m_IsRay;
        v44 = traceData->m_dispList.m_Size;
        rayh = nullptr;
        v65 = v44;
        if ( v16 )
        {
          v64 = traceData->m_dispList.m_Memory.m_pMemory;
          if ( v44 > 0 )
          {
            do
            {
              v47 = v64[(_DWORD)rayh];
              v48 = &g_pDispBounds[v47];
              if ( (v48->dispContents & (unsigned int)v4[63]) != 0 )
              {
                boxMax.x = *((float *)v4 + 12) + v48->maxs.x;
                boxMax.y = *((float *)v4 + 13) + v48->maxs.y;
                boxMax.z = *((float *)v4 + 14) + v48->maxs.z;
                boxMin.x = v48->mins.x - *((float *)v4 + 12);
                boxMin.y = v48->mins.y - *((float *)v4 + 13);
                boxMin.z = v48->mins.z - *((float *)v4 + 14);
                if ( IsBoxIntersectingRay(
                       &boxMin,
                       &boxMax,
                       origin: (const Vector *)v4,
                       vecDelta: (const Vector *)v4 + 5,
                       vecInvDelta: (const Vector *)v4 + 6,
                       flTolerance: 0.03125) )
                {
                  CM_TraceToDispTree<0>(
                    pTraceInfo: (TraceInfo_t *)v4,
                    pDispTree: &g_pDispCollTrees[v47],
                    startFrac: 0.0,
                    endFrac: 1.0);
                  if ( *((float *)v4 + 32) == 0.0 )
                    break;
                }
              }
              rayh = (const Ray_t *)((char *)rayh + 1);
            }
            while ( (int)rayh < v65 );
          }
        }
        else
        {
          v64 = traceData->m_dispList.m_Memory.m_pMemory;
          if ( v44 > 0 )
          {
            do
            {
              v45 = v64[(_DWORD)rayh];
              v46 = &g_pDispBounds[v45];
              if ( (v46->dispContents & (unsigned int)v4[63]) != 0
                && IsBoxIntersectingRay(
                     boxMin: &v46->mins,
                     boxMax: &v46->maxs,
                     origin: (const Vector *)v4,
                     vecDelta: (const Vector *)v4 + 5,
                     vecInvDelta: (const Vector *)v4 + 6,
                     flTolerance: 0.03125) )
              {
                CM_TraceToDispTree<1>(
                  pTraceInfo: (TraceInfo_t *)v4,
                  pDispTree: &g_pDispCollTrees[v45],
                  startFrac: 0.0,
                  endFrac: 1.0);
                if ( *((float *)v4 + 32) == 0.0 )
                  break;
              }
              rayh = (const Ray_t *)((char *)rayh + 1);
            }
            while ( (int)rayh < v65 );
          }
        }
        CM_PostTraceToDispTree(pTraceInfo: (TraceInfo_t *)v4);
      }
      goto LABEL_79;
    }
    v67 = (TSLNodeBase_t *)m_Size;
    v64 = m_pMemory;
    v65 = (int)v15;
    if ( m_Size <= 0 )
      goto LABEL_64;
    while ( 1 )
    {
      v31 = v64[v68];
      v32 = *(_DWORD *)(*(_DWORD *)v65 + 8 * v31);
      v33 = (const cbrush_t *)(*(_DWORD *)v65 + 8 * v31);
      v34 = (unsigned int)v4[63];
      v35 = v34 & v32;
      raye = (const Ray_t *)v33;
      if ( v35 != 0 )
      {
        if ( v35 != 128 || (v34 & 0x2000) == 0 )
        {
LABEL_62:
          CM_ClipBoxToBrush<0>(pTraceInfo: (TraceInfo_t *)v4, brush: v33);
          if ( *((float *)v4 + 32) == 0.0 )
            goto LABEL_64;
          goto LABEL_63;
        }
        v36 = v33->numsides;
        if ( (_WORD)v36 == 0xFFFF )
        {
          v37 = 0;
          v38 = &v4[65][14].Next[6 * v33->firstbrushside + 4];
          while ( 1 )
          {
            v39 = LOWORD(v38->Next);
            v40 = (_WORD)v39 == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[v39];
            if ( SLOBYTE(v40->flags) < 0 )
              break;
            ++v37;
            v38 = (TSLNodeBase_t *)((char *)v38 + 2);
            if ( v37 >= 6 )
            {
              v33 = (const cbrush_t *)raye;
              goto LABEL_62;
            }
          }
        }
        else
        {
          rayf = (const Ray_t *)&v4[65][13].Next[v33->firstbrushside];
          v41 = 0;
          v66 = (unsigned __int16 *)v33->numsides;
          if ( v36 <= 0 )
            goto LABEL_62;
          rayg = (const Ray_t *)&rayf->m_Start.y;
          while ( 1 )
          {
            v42 = LOWORD(rayg->m_Start.x);
            v43 = (_WORD)v42 == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[v42];
            if ( SLOBYTE(v43->flags) < 0 )
              break;
            rayg = (const Ray_t *)((char *)rayg + 8);
            if ( ++v41 >= (int)v66 )
              goto LABEL_62;
          }
        }
      }
LABEL_63:
      if ( ++v68 >= (int)v67 )
        goto LABEL_64;
    }
  }
  for ( raya = 0; raya < traceData->m_brushList.m_Size; ++raya )
  {
    v12 = (const cbrush_t *)&v4[65][21].Next[traceData->m_brushList.m_Memory.m_pMemory[raya]];
    if ( ((unsigned int)v4[63] & v12->contents) != 0 )
    {
      CM_TestBoxInBrush(pTraceInfo: (TraceInfo_t *)v4, brush: v12);
      if ( *((_BYTE *)v4 + 138) != 0 )
        break;
    }
  }
  if ( *((_BYTE *)v4 + 139) == 0 )
    CM_TestInDispTree(
      pTraceInfo: (TraceInfo_t *)v4,
      pDispList: traceData->m_dispList.m_Memory.m_pMemory,
      dispListCount: traceData->m_dispList.m_Size,
      traceStart: (const Vector *)v4,
      boxMin: (const Vector *)v4 + 2,
      boxMax: (const Vector *)v4 + 3,
      collisionMask: (int)v4[63],
      pTrace: (CGameTrace *)v4 + 1);
  if ( !traceData->m_bFoundNonSolidLeaf )
  {
    *((_WORD *)v4 + 69) = 257;
    v4[32] = nullptr;
    v4[35] = (TSLNodeBase_t *)1065353216;
    goto LABEL_80;
  }
LABEL_79:
  v8 = ray;
LABEL_80:
  v49 = *((float *)v4 + 32);
  v50 = v8->m_StartOffset.x + v8->m_Start.x;
  v51 = v8->m_StartOffset.y + v8->m_Start.y;
  v52 = v8->m_StartOffset.z + v8->m_Start.z;
  v53 = (float *)(v4 + 21);
  if ( v49 == 1.0 )
  {
    *((float *)v4 + 24) = v8->m_Delta.x + v50;
    *((float *)v4 + 25) = v51 + v8->m_Delta.y;
    v54 = v52 + v8->m_Delta.z;
  }
  else
  {
    *((float *)v4 + 24) = (float)(v8->m_Delta.x * v49) + v50;
    *((float *)v4 + 25) = (float)(v49 * v8->m_Delta.y) + v51;
    v54 = (float)(v49 * v8->m_Delta.z) + v52;
  }
  *((float *)v4 + 26) = v54;
  v55 = *((float *)v4 + 35);
  if ( v55 == 0.0 )
  {
    *v53 = v50;
    *((float *)v4 + 22) = v51;
    *((float *)v4 + 23) = v52;
  }
  else
  {
    if ( v55 == 1.0 )
    {
      *((_WORD *)v4 + 69) = 257;
      v4[32] = nullptr;
      *((float *)v4 + 24) = v50;
      *((float *)v4 + 25) = v51;
      *((float *)v4 + 26) = v52;
    }
    v56 = *((float *)v4 + 35);
    *v53 = (float)(v8->m_Delta.x * v56) + v50;
    *((float *)v4 + 22) = (float)(v56 * v8->m_Delta.y) + v51;
    *((float *)v4 + 23) = (float)(v56 * v8->m_Delta.z) + v52;
  }
  CBaseTrace::operator=(this: trace, __that: (const CBaseTrace *)(v4 + 21));
  trace->fractionleftsolid = *((float *)v4 + 35);
  trace->surface = *((csurface_t *)v4 + 18);
  trace->hitgroup = (int)v4[38];
  trace->physicsbone = *((_WORD *)v4 + 78);
  trace->worldSurfaceIndex = *((_WORD *)v4 + 79);
  trace->m_pEnt = (struct CBaseEntity *)v4[40];
  trace->hitbox = (int)v4[41];
  v4[71] = (TSLNodeBase_t *)((char *)v4[71] - 1);
  m_Head = g_TraceInfoPool.m_Head;
  v58 = g_TraceInfoPool.m_Head.value32.DepthAndSequence + 65537;
  v57 = v4 - 1;
  *v57 = g_TraceInfoPool.m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &g_TraceInfoPool,
                          a2: v57,
                          a3: v58,
                          a4: m_Head.value.Next,
                          a5: m_Head.value32.DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      v61 = g_TraceInfoPool.m_Head;
      v59 = g_TraceInfoPool.m_Head.value32.DepthAndSequence + 65537;
      *v57 = g_TraceInfoPool.m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_TraceInfoPool,
                               a2: v57,
                               a3: v59,
                               a4: v61.value.Next,
                               a5: v61.value32.DepthAndSequence) == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150530
// Name: void CM_BoxTrace(struct Ray_t const __near &,int,int,bool,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_BoxTrace(const Ray_t *ray, int headnode, TSLNodeBase_t *brushmask, bool computeEndpt, CGameTrace *tr)
{
  TSLNodeBase_t **v5; // esi
  CGameTrace *v6; // ebx
  float x; // xmm1_4
  float v8; // xmm4_4
  float y; // xmm3_4
  float v10; // xmm1_4
  float z; // xmm3_4
  float v12; // xmm2_4
  bool m_IsRay; // dl
  float v14; // [esp-10h] [ebp-1Ch]
  float v15; // [esp-Ch] [ebp-18h]
  const Vector *v16; // [esp-4h] [ebp-10h]

  v5 = BeginTrace();
  v6 = (CGameTrace *)(v5 + 21);
  memset(dst: (unsigned __int8 *)v5 + 84, value: 0, count: 0x54u);
  v5[32] = (TSLNodeBase_t *)1065353216;
  v5[35] = nullptr;
  *((csurface_t *)v5 + 18) = CCollisionBSPData::nullsurface;
  if ( *((_DWORD *)&v5[65][15].Next + 1) != 0 )
  {
    v5[69] = nullptr;
    v5[66] = nullptr;
    v5[67] = nullptr;
    v5[68] = nullptr;
    v5[63] = brushmask;
    *(Vector *)v5 = ray->m_Start.Vector;
    *((float *)v5 + 3) = ray->m_Start.x + ray->m_Delta.x;
    *((float *)v5 + 4) = ray->m_Delta.y + ray->m_Start.y;
    *((float *)v5 + 5) = ray->m_Delta.z + ray->m_Start.z;
    *((float *)v5 + 6) = ray->m_Extents.x * -1.0;
    *((float *)v5 + 7) = ray->m_Extents.y * -1.0;
    *((float *)v5 + 8) = ray->m_Extents.z * -1.0;
    *((Vector *)v5 + 3) = ray->m_Extents.Vector;
    *((Vector *)v5 + 4) = ray->m_Extents.Vector;
    *((Vector *)v5 + 5) = ray->m_Delta.Vector;
    x = ray->m_Delta.x;
    if ( x == 0.0 )
      v8 = 3.4028235e38;
    else
      v8 = 1.0 / x;
    y = ray->m_Delta.y;
    if ( y == 0.0 )
      v10 = 3.4028235e38;
    else
      v10 = 1.0 / y;
    z = ray->m_Delta.z;
    if ( z == 0.0 )
      v12 = 3.4028235e38;
    else
      v12 = 1.0 / z;
    *((float *)v5 + 18) = v8;
    *((float *)v5 + 19) = v10;
    *((float *)v5 + 20) = v12;
    m_IsRay = ray->m_IsRay;
    *((_BYTE *)v5 + 256) = m_IsRay;
    *((_BYTE *)v5 + 257) = ray->m_IsSwept;
    if ( ray->m_IsSwept )
    {
      v16 = (const Vector *)(v5 + 3);
      v15 = 1.0;
      v14 = 0.0;
      if ( m_IsRay )
        CM_RecursiveHullCheckImpl_1_(
          pTraceInfo: (TraceInfo_t *)v5,
          num: headnode,
          p1f: v14,
          p2f: v15,
          p1: (const Vector *)v5,
          p2: v16);
      else
        CM_RecursiveHullCheckImpl_0_(
          pTraceInfo: (TraceInfo_t *)v5,
          num: headnode,
          p1f: v14,
          p2f: v15,
          p1: (const Vector *)v5,
          p2: v16);
    }
    else
    {
      CM_UnsweptBoxTrace(pTraceInfo: (TraceInfo_t *)v5, ray, headnode);
    }
    if ( computeEndpt )
      CM_ComputeTraceEndpoints(tr: v6, ray);
  }
  CBaseTrace::operator=(this: tr, __that: v6);
  tr->fractionleftsolid = *((float *)v5 + 35);
  tr->surface = *((csurface_t *)v5 + 18);
  tr->hitgroup = (int)v5[38];
  tr->physicsbone = *((_WORD *)v5 + 78);
  tr->worldSurfaceIndex = *((_WORD *)v5 + 79);
  tr->m_pEnt = (struct CBaseEntity *)v5[40];
  tr->hitbox = (int)v5[41];
  v5[71] = (TSLNodeBase_t *)((char *)v5[71] - 1);
  CTSListBase::Push(this: &g_TraceInfoPool, pNode: (TSLNodeBase_t *)(v5 - 1));
}

//------------------------------------------------------------------------------
// Address: 0x101507B0
// Name: void CM_TransformedBoxTrace(struct Ray_t const __near &,int,int,class Vector const __near &,class QAngle const __near &,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_TransformedBoxTrace(
        float a1@<ebp>,
        const Ray_t *ray,
        int headnode,
        TSLNodeBase_t *brushmask,
        const Vector *origin,
        const QAngle *angles,
        CGameTrace *tr)
{
  float x; // xmm4_4
  float v8; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float v11; // xmm0_4
  bool m_IsSwept; // cl
  float fraction; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // eax
  float fractionleftsolid; // xmm3_4
  float v23; // xmm3_4
  _BYTE v24[12]; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t localToWorld; // [esp+0h] [ebp-A0h] BYREF
  Ray_t ray_l; // [esp+30h] [ebp-70h] BYREF
  Vector normal; // [esp+80h] [ebp-20h] BYREF
  Vector temp; // [esp+8Ch] [ebp-14h]
  void *v29; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  temp.z = a1;
  v29 = retaddr;
  x = angles->x;
  v8 = ray->m_StartOffset.x;
  y = ray->m_StartOffset.y;
  z = ray->m_StartOffset.z;
  *(Vector *)&ray_l.m_StartOffset.y = ray->m_Extents.Vector;
  ray_l.m_Extents.y = 0.0;
  ray_l.m_Delta.y = v8;
  ray_l.m_Delta.z = y;
  ray_l.m_Delta.w = z;
  if ( x == 0.0 && angles->y == 0.0 && angles->z == 0.0 )
  {
    localToWorld.m_flMatVal[2][1] = ray->m_Start.x - origin->x;
    localToWorld.m_flMatVal[2][2] = ray->m_Start.y - origin->y;
    localToWorld.m_flMatVal[2][3] = ray->m_Start.z - origin->z;
    ray_l.m_Start.y = ray->m_Delta.x;
    ray_l.m_Start.z = ray->m_Delta.y;
    v11 = ray->m_Delta.z;
    HIBYTE(temp.y) = 0;
    LODWORD(temp.x) = &ray->m_Delta;
    ray_l.m_Start.w = v11;
  }
  else
  {
    v18 = z + ray->m_Start.z;
    v19 = ray->m_Start.x + v8;
    v20 = ray->m_Start.y + y;
    HIBYTE(temp.y) = 1;
    normal.x = v19;
    normal.y = v20;
    normal.z = v18;
    AngleMatrix(angles, position: origin, matrix: (matrix3x4_t *)v24);
    LODWORD(temp.x) = &ray->m_Delta;
    VectorIRotate(in1: &ray->m_Delta.x, in2: (const matrix3x4_t *)v24, out: &ray_l.m_Start.y);
    VectorITransform(in1: &normal.x, in2: (const matrix3x4_t *)v24, out: &localToWorld.m_flMatVal[2][1]);
    localToWorld.m_flMatVal[2][1] = localToWorld.m_flMatVal[2][1] - ray->m_StartOffset.x;
    localToWorld.m_flMatVal[2][2] = localToWorld.m_flMatVal[2][2] - ray->m_StartOffset.y;
    localToWorld.m_flMatVal[2][3] = localToWorld.m_flMatVal[2][3] - ray->m_StartOffset.z;
  }
  m_IsSwept = ray->m_IsSwept;
  LOBYTE(ray_l.m_Extents.z) = ray->m_IsRay;
  BYTE1(ray_l.m_Extents.z) = m_IsSwept;
  CM_BoxTrace(ray: (const Ray_t *)&localToWorld.m_flMatVal[2][1], headnode, brushmask, computeEndpt: false, tr);
  if ( tr->fraction != 1.0 && HIBYTE(temp.y) != 0 )
  {
    normal = tr->plane.normal;
    VectorRotate(in1: &normal.x, in2: (const matrix3x4_t *)v24, out: &tr->plane.normal.x);
  }
  fraction = tr->fraction;
  v14 = ray->m_Start.x + ray->m_StartOffset.x;
  v15 = ray->m_StartOffset.y + ray->m_Start.y;
  v16 = ray->m_Start.z + ray->m_StartOffset.z;
  v17 = temp.x;
  if ( fraction == 1.0 )
  {
    tr->endpos.x = v14 + *(float *)LODWORD(temp.x);
    tr->endpos.y = *(float *)(LODWORD(v17) + 4) + v15;
    tr->endpos.z = *(float *)(LODWORD(v17) + 8) + v16;
  }
  else
  {
    v21 = temp.x;
    tr->endpos.x = (float)(fraction * *(float *)LODWORD(temp.x)) + v14;
    tr->endpos.y = (float)(*(float *)(LODWORD(v21) + 4) * fraction) + v15;
    tr->endpos.z = (float)(*(float *)(LODWORD(v21) + 8) * fraction) + v16;
  }
  fractionleftsolid = tr->fractionleftsolid;
  if ( fractionleftsolid == 0.0 )
  {
    tr->startpos.x = v14;
    tr->startpos.y = v15;
    tr->startpos.z = v16;
  }
  else
  {
    if ( fractionleftsolid == 1.0 )
    {
      *(_WORD *)&tr->allsolid = 257;
      tr->fraction = 0.0;
      tr->endpos.x = v14;
      tr->endpos.y = v15;
      tr->endpos.z = v16;
    }
    v23 = tr->fractionleftsolid;
    tr->startpos.x = (float)(v23 * *(float *)LODWORD(v17)) + v14;
    tr->startpos.y = (float)(*(float *)(LODWORD(v17) + 4) * v23) + v15;
    tr->startpos.z = (float)(*(float *)(LODWORD(v17) + 8) * v23) + v16;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1014BD90
// Name: public: class Vector Ray_t::InvDelta(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Ray_t::InvDelta(Ray_t *this, Vector *result)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  Vector *v5; // eax

  x = this->m_Delta.x;
  if ( x == 0.0 )
    result->x = 3.4028235e38;
  else
    result->x = 1.0 / x;
  y = this->m_Delta.y;
  if ( y == 0.0 )
    result->y = 3.4028235e38;
  else
    result->y = 1.0 / y;
  z = this->m_Delta.z;
  v5 = result;
  if ( z == 0.0 )
    result->z = 3.4028235e38;
  else
    result->z = 1.0 / z;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE10
// Name: void PopTraceVisits(struct TraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PopTraceVisits(TraceInfo_t *pTraceInfo)
{
  --pTraceInfo->m_nCheckDepth;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE20
// Name: int CM_NumClusters(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_NumClusters()
{
  return g_BSPData.numclusters;
}

//------------------------------------------------------------------------------
// Address: 0x1014BE40
// Name: int CM_PointLeafnumMinDistSqr_r(class CCollisionBSPData __near *,class Vector const __near &,int,float __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnumMinDistSqr_r(CCollisionBSPData *pBSPData, const Vector *p, int num, float *minDistSqr)
{
  int v4; // ecx
  cnode_t *map_rootnode; // edi
  int v6; // ecx
  cplane_t *plane; // eax
  cnode_t *v8; // edx
  unsigned __int8 type; // cl
  float v10; // xmm0_4
  float v11; // xmm0_4
  double v12; // st6
  double v13; // st7

  v4 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v6 = v4;
      plane = map_rootnode[v6].plane;
      v8 = &map_rootnode[v6];
      type = plane->type;
      if ( type >= 3u )
        v10 = (float)((float)(plane->normal.y * p->y) + (float)(plane->normal.x * p->x))
            + (float)(plane->normal.z * p->z);
      else
        v10 = *(&p->x + type);
      v11 = v10 - plane->dist;
      v12 = v11 * v11;
      v13 = *minDistSqr;
      if ( v12 <= v13 )
        v13 = v12;
      *minDistSqr = v13;
      if ( v11 >= 0.0 )
        v4 = v8->children[0];
      else
        v4 = v8->children[1];
    }
    while ( v4 >= 0 );
  }
  return -1 - v4;
}

//------------------------------------------------------------------------------
// Address: 0x1014BEE0
// Name: int CM_PointLeafnum_r(class CCollisionBSPData __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnum_r(CCollisionBSPData *pBSPData, const Vector *p, int num)
{
  int v3; // ecx
  cnode_t *map_rootnode; // edi
  int v5; // ecx
  cplane_t *plane; // eax
  cnode_t *v7; // edx
  unsigned __int8 type; // cl
  float v9; // xmm0_4

  v3 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v5 = v3;
      plane = map_rootnode[v5].plane;
      v7 = &map_rootnode[v5];
      type = plane->type;
      if ( type >= 3u )
        v9 = (float)((float)(plane->normal.y * p->y) + (float)(plane->normal.x * p->x))
           + (float)(plane->normal.z * p->z);
      else
        v9 = *(&p->x + type);
      if ( (float)(v9 - plane->dist) >= 0.0 )
        v3 = v7->children[0];
      else
        v3 = v7->children[1];
    }
    while ( v3 >= 0 );
  }
  return -1 - v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014BF60
// Name: int CM_PointLeafnum(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointLeafnum(const Vector *p)
{
  if ( g_BSPData.numplanes != 0 )
    return CM_PointLeafnum_r(pBSPData: &g_BSPData, p, num: 0);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014BF90
// Name: void CM_SnapPointToReferenceLeaf_r(class CCollisionBSPData __near *,class Vector const __near &,int,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SnapPointToReferenceLeaf_r(
        CCollisionBSPData *pBSPData,
        const Vector *p,
        int num,
        float tolerance,
        Vector *pSnapPoint)
{
  int v5; // edx
  cnode_t *map_rootnode; // ebx
  int v7; // edx
  cplane_t *plane; // eax
  cnode_t *v9; // esi
  int v10; // edx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4

  v5 = num;
  if ( num >= 0 )
  {
    map_rootnode = pBSPData->map_rootnode;
    do
    {
      v7 = v5;
      plane = map_rootnode[v7].plane;
      v9 = &map_rootnode[v7];
      if ( plane->type >= 3u )
      {
        v11 = (float)((float)(p->y * plane->normal.y) + (float)(p->x * plane->normal.x))
            + (float)(p->z * plane->normal.z);
        v12 = (float)((float)(pSnapPoint->y * plane->normal.y) + (float)(plane->normal.x * pSnapPoint->x))
            + (float)(pSnapPoint->z * plane->normal.z);
      }
      else
      {
        v10 = 4 * plane->type;
        v11 = *(float *)((char *)&p->x + v10);
        v12 = *(float *)((char *)&pSnapPoint->x + v10);
      }
      v13 = v12 - plane->dist;
      if ( (float)(v11 - plane->dist) >= 0.0 )
      {
        v5 = v9->children[0];
        if ( v13 < 0.0 )
        {
          v17 = tolerance - v13;
          v18 = (float)(plane->normal.y * (float)(tolerance - v13)) + pSnapPoint->y;
          v19 = (float)(plane->normal.z * v17) + pSnapPoint->z;
          pSnapPoint->x = pSnapPoint->x + (float)(plane->normal.x * v17);
          pSnapPoint->y = v18;
          pSnapPoint->z = v19;
        }
      }
      else
      {
        v5 = v9->children[1];
        if ( v13 > 0.0 )
        {
          v14 = v13 + tolerance;
          v15 = plane->normal.y * v14;
          v16 = plane->normal.z * v14;
          pSnapPoint->x = pSnapPoint->x - (float)(plane->normal.x * v14);
          pSnapPoint->y = pSnapPoint->y - v15;
          pSnapPoint->z = pSnapPoint->z - v16;
        }
      }
    }
    while ( v5 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C0E0
// Name: void CM_SnapPointToReferenceLeaf(class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SnapPointToReferenceLeaf(const Vector *referenceLeafPoint, float tolerance, Vector *pSnapPoint)
{
  if ( g_BSPData.numplanes != 0 )
    CM_SnapPointToReferenceLeaf_r(pBSPData: &g_BSPData, p: referenceLeafPoint, num: 0, tolerance, pSnapPoint);
}

//------------------------------------------------------------------------------
// Address: 0x1014C110
// Name: int CM_BoxLeafnums(struct leafnums_t __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxLeafnums(leafnums_t *context, const Vector *center, const Vector *extents, int nodenum)
{
  int v6; // edx
  double y; // st7
  float v8; // xmm0_4
  cnode_t *v9; // esi
  cplane_t *plane; // edx
  float v11; // xmm0_4
  long double v12; // st7
  double v13; // st6
  __int16 v14; // cx
  _DWORD v16[1024]; // [esp+0h] [ebp-1018h]
  float v17; // [esp+1000h] [ebp-18h]
  float z; // [esp+1004h] [ebp-14h]
  int v19; // [esp+1008h] [ebp-10h]
  int v20; // [esp+100Ch] [ebp-Ch]
  int v21; // [esp+1010h] [ebp-8h]
  int v22; // [esp+1014h] [ebp-4h]
  float v23; // [esp+1020h] [ebp+8h]
  float x; // [esp+102Ch] [ebp+14h]

  v19 = 0;
  v20 = 0;
  v22 = 0;
  v21 = -1;
  while ( 1 )
  {
    while ( nodenum >= 0 )
    {
      y = extents->y;
      v8 = center->y;
      v9 = &context->pBSPData->map_rootnode[nodenum];
      plane = v9->plane;
      v23 = v9->plane->normal.y;
      x = v9->plane->normal.x;
      z = v9->plane->normal.z;
      v11 = (float)((float)((float)(v8 * v23) + (float)(center->x * x)) + (float)(center->z * z)) - plane->dist;
      v12 = fabs(y * v23) + fabs(x * extents->x);
      v13 = extents->z;
      v21 = nodenum;
      v17 = v12 + fabs(v13 * z);
      if ( v11 < v17 )
      {
        if ( (float)-v17 <= v11 )
        {
          if ( context->leafTopNode == -1 )
            context->leafTopNode = nodenum;
          v14 = v22;
          v16[v22] = v9->children[0];
          v22 = (v14 + 1) & 0x3FF;
          nodenum = v9->children[1];
        }
        else
        {
          nodenum = v9->children[1];
        }
      }
      else
      {
        nodenum = v9->children[0];
      }
    }
    if ( context->leafTopNode == -1 )
      context->leafTopNode = v21;
    v6 = v19;
    if ( v19 < context->leafMaxCount )
    {
      context->pLeafList[v19] = -1 - nodenum;
      v19 = ++v6;
    }
    if ( v20 == v22 )
      break;
    nodenum = v16[v20];
    v20 = ((_WORD)v20 + 1) & 0x3FF;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1014C7E0
// Name: void CM_ClearTrace(class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_ClearTrace(CGameTrace *trace)
{
  memset(dst: (unsigned __int8 *)trace, value: 0, count: sizeof(CGameTrace));
  trace->fraction = 1.0;
  trace->fractionleftsolid = 0.0;
  trace->surface = CCollisionBSPData::nullsurface;
}

//------------------------------------------------------------------------------
// Address: 0x1014C820
// Name: void CM_NullVis(class CCollisionBSPData __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_NullVis(CCollisionBSPData *pBSPData, unsigned __int8 *out)
{
  if ( (pBSPData->numclusters + 7) >> 3 != 0 )
    memset(dst: out, value: 0xFFu, count: (pBSPData->numclusters + 7) >> 3);
}

//------------------------------------------------------------------------------
// Address: 0x1014C850
// Name: void CM_DecompressVis(class CCollisionBSPData __near *,int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DecompressVis(CCollisionBSPData *pBSPData, int cluster, int visType, unsigned __int8 *out)
{
  int numclusters; // eax
  dvis_t *map_vis; // ecx
  unsigned __int8 *v7; // ebx
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // eax
  int numClusterBytes; // [esp+Ch] [ebp+8h]

  numclusters = pBSPData->numclusters;
  if ( cluster > numclusters || cluster < 0 )
  {
    v13 = (numclusters + 7) >> 3;
    if ( v13 == 0 )
      return;
LABEL_19:
    memset(dst: out, value: 0xFFu, count: v13);
    return;
  }
  if ( pBSPData->numvisibility == 0 || pBSPData->map_vis == nullptr )
  {
    v13 = (numclusters + 7) >> 3;
    if ( v13 == 0 )
      return;
    goto LABEL_19;
  }
  map_vis = pBSPData->map_vis;
  v7 = out;
  v8 = map_vis->bitofs[cluster][visType];
  v9 = (numclusters + 7) >> 3;
  v10 = (dvis_t *)((char *)map_vis + v8) == nullptr;
  v11 = (unsigned __int8 *)map_vis + v8;
  numClusterBytes = v9;
  if ( v10 )
  {
    CM_NullVis(pBSPData, out);
  }
  else
  {
    do
    {
      if ( *v11 != 0 )
      {
        *v7++ = *v11++;
      }
      else
      {
        v12 = v11[1];
        v11 += 2;
        if ( (int)&v7[v12 - (_DWORD)out] > v9 )
        {
          v12 = (unsigned int)&out[v9 - (_DWORD)v7];
          ConMsg(a1: "warning: Vis decompression overrun\n");
          v9 = numClusterBytes;
        }
        if ( v12 != 0 )
        {
          memset(dst: v7, value: 0, count: v12);
          v9 = numClusterBytes;
          v7 += v12;
        }
      }
    }
    while ( v7 - out < v9 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C960
// Name: unsigned char const __near * CM_Vis(unsigned char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CM_Vis(unsigned __int8 *dest, int destlen, int cluster, unsigned int visType)
{
  if ( dest != nullptr && visType <= 2 )
  {
    if ( cluster == -1 )
    {
      if ( (g_BSPData.numclusters + 7) >> 3 > destlen )
        Sys_Error(error: "CM_Vis:  buffer not big enough (%i but need %i)\n", destlen, (g_BSPData.numclusters + 7) >> 3);
      memset(dst: dest, value: 0, count: (g_BSPData.numclusters + 7) >> 3);
      return dest;
    }
    else
    {
      CM_DecompressVis(pBSPData: &g_BSPData, cluster, visType, out: dest);
      return dest;
    }
  }
  else
  {
    Sys_Error(error: "CM_Vis: error");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014C9E0
// Name: int CM_ClusterPVSSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_ClusterPVSSize()
{
  return 0x2000;
}

//------------------------------------------------------------------------------
// Address: 0x1014C9F0
// Name: unsigned char const __near * CM_ClusterPVS(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl CM_ClusterPVS(int cluster)
{
  if ( cluster == -1 )
  {
    if ( (g_BSPData.numclusters + 7) >> 3 > 0x2000 )
      Sys_Error(error: "CM_Vis:  buffer not big enough (%i but need %i)\n", 0x2000, (g_BSPData.numclusters + 7) >> 3);
    memset(dst: pvsrow, value: 0, count: (g_BSPData.numclusters + 7) >> 3);
    return pvsrow;
  }
  else
  {
    CM_DecompressVis(pBSPData: &g_BSPData, cluster, visType: 0, out: pvsrow);
    return pvsrow;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CA60
// Name: void CM_WorldSpaceCenter(class ICollideable __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_WorldSpaceCenter(ICollideable *pCollideable, Vector *pCenter)
{
  const Vector *v2; // edi
  const Vector *v3; // eax
  const QAngle *(__thiscall *GetCollisionAngles)(ICollideable *); // edx
  float v5; // xmm2_4
  float *v6; // ecx
  const matrix3x4_t *v7; // eax
  const Vector *v8; // eax
  Vector vecLocalCenter; // [esp+8h] [ebp-Ch] BYREF

  v2 = pCollideable->OBBMaxs(this: pCollideable);
  v3 = pCollideable->OBBMins(this: pCollideable);
  vecLocalCenter.x = v3->x + v2->x;
  vecLocalCenter.y = v3->y + v2->y;
  GetCollisionAngles = pCollideable->GetCollisionAngles;
  v5 = (float)(v3->z + v2->z) * 0.5;
  vecLocalCenter.x = vecLocalCenter.x * 0.5;
  vecLocalCenter.y = vecLocalCenter.y * 0.5;
  vecLocalCenter.z = v5;
  v6 = (float *)GetCollisionAngles(this: pCollideable);
  if ( vec3_angle.x == *v6 && vec3_angle.y == v6[1] && vec3_angle.z == v6[2]
    || vec3_origin.x == vecLocalCenter.x && vec3_origin.y == vecLocalCenter.y && vec3_origin.z == vecLocalCenter.z )
  {
    v8 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pCenter->x = v8->x + vecLocalCenter.x;
    pCenter->y = v8->y + vecLocalCenter.y;
    pCenter->z = v8->z + vecLocalCenter.z;
  }
  else
  {
    v7 = pCollideable->CollisionToWorldTransform(this: pCollideable);
    VectorTransform(in1: &vecLocalCenter.x, in2: v7, out: &pCenter->x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CBA0
// Name: void CM_WorldSpaceBounds(class ICollideable __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_WorldSpaceBounds(ICollideable *pCollideable, Vector *pMins, Vector *pMaxs)
{
  const QAngle *v3; // eax
  const Vector *v4; // edi
  const Vector *v5; // eax
  const Vector *(__thiscall *OBBMaxs)(ICollideable *); // edx
  float *v7; // edi
  const Vector *v8; // eax
  const matrix3x4_t *v9; // eax
  const Vector *v10; // [esp-10h] [ebp-14h]
  const Vector *v11; // [esp-Ch] [ebp-10h]

  v3 = pCollideable->GetCollisionAngles(this: pCollideable);
  if ( vec3_angle.x == v3->x && vec3_angle.y == v3->y && vec3_angle.z == v3->z )
  {
    v4 = pCollideable->OBBMins(this: pCollideable);
    v5 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pMins->x = v5->x + v4->x;
    pMins->y = v5->y + v4->y;
    OBBMaxs = pCollideable->OBBMaxs;
    pMins->z = v5->z + v4->z;
    v7 = (float *)OBBMaxs(this: pCollideable);
    v8 = pCollideable->GetCollisionOrigin(this: pCollideable);
    pMaxs->x = v8->x + *v7;
    pMaxs->y = v8->y + v7[1];
    pMaxs->z = v8->z + v7[2];
  }
  else
  {
    v11 = pCollideable->OBBMaxs(this: pCollideable);
    v10 = pCollideable->OBBMins(this: pCollideable);
    v9 = pCollideable->CollisionToWorldTransform(this: pCollideable);
    TransformAABB(transform: v9, vecMinsIn: v10, vecMaxsIn: v11, vecMinsOut: pMins, vecMaxsOut: pMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014CCB0
// Name: public: void CFastPointLeafNum::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFastPointLeafNum::Reset(CFastPointLeafNum *this)
{
  this->m_flDistToExitLeafSqr = -1.0;
  this->m_iCachedLeaf = -1;
  this->m_vCachedPos.x = 0.0;
  this->m_vCachedPos.y = 0.0;
  this->m_vCachedPos.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CCE0
// Name: public: struct csurface_t __near * CCollisionBSPData::GetSurfaceAtIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
csurface_t *__thiscall CCollisionBSPData::GetSurfaceAtIndex(CCollisionBSPData *this, unsigned __int16 surfaceIndex)
{
  if ( surfaceIndex == 0xFFFF )
    return &CCollisionBSPData::nullsurface;
  else
    return &this->map_surfaces.m_pArray[surfaceIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1014CD40
// Name: struct cmodel_t __near * CM_InlineModelNumber(int)
// Source: json
//------------------------------------------------------------------------------
cmodel_t *__cdecl CM_InlineModelNumber(int index)
{
  if ( index < 0 || index > g_BSPData.numcmodels )
    return nullptr;
  else
    return &g_BSPData.map_cmodels.m_pArray[index];
}

//------------------------------------------------------------------------------
// Address: 0x1014CD70
// Name: int CM_BrushContents_r(class CCollisionBSPData __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BrushContents_r(CCollisionBSPData *pBSPData, int nodenum)
{
  int v2; // eax
  int i; // edi
  cnode_t *v4; // ebx
  cleaf_t *v5; // eax
  int numleafbrushes; // ecx
  unsigned __int16 *v7; // eax

  v2 = nodenum;
  for ( i = 0; v2 >= 0; v2 = v4->children[1] )
  {
    v4 = &pBSPData->map_rootnode[v2];
    i |= CM_BrushContents_r(pBSPData, nodenum: v4->children[0]);
  }
  v5 = &pBSPData->map_leafs.m_pArray[-v2 - 1];
  numleafbrushes = v5->numleafbrushes;
  if ( v5->numleafbrushes != 0 )
  {
    v7 = &pBSPData->map_leafbrushes.m_pArray[v5->firstleafbrush];
    do
    {
      i |= pBSPData->map_brushes.m_pArray[*v7++].contents;
      --numleafbrushes;
    }
    while ( numleafbrushes != 0 );
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1014CDF0
// Name: int CM_InlineModelContents(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_InlineModelContents(int index)
{
  cmodel_t *v1; // eax

  if ( index >= 0 && index <= g_BSPData.numcmodels && (v1 = &g_BSPData.map_cmodels.m_pArray[index]) != nullptr )
    return CM_BrushContents_r(pBSPData: &g_BSPData, nodenum: v1->headnode);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CE50
// Name: int CM_LeafCluster(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafCluster(int leafnum)
{
  return g_BSPData.map_leafs.m_pArray[leafnum].cluster;
}

//------------------------------------------------------------------------------
// Address: 0x1014CE90
// Name: int CM_LeafArea(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_LeafArea(int leafnum)
{
  return (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[leafnum] + 3) << 7) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x1014CEB0
// Name: int CM_BoxLeafnums(class Vector const __near &,class Vector const __near &,int __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxLeafnums(
        const Vector *mins,
        const Vector *maxs,
        int *list,
        int listsize,
        int *topnode,
        int cmodelIndex)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int result; // eax
  leafnums_t context; // [esp+0h] [ebp-28h] BYREF
  Vector center; // [esp+10h] [ebp-18h] BYREF
  Vector extents; // [esp+1Ch] [ebp-Ch] BYREF

  context.pLeafList = list;
  x = maxs->x;
  y = maxs->y;
  z = maxs->z;
  context.leafMaxCount = listsize;
  v9 = (float)(mins->x + x) * 0.5;
  v10 = (float)(mins->y + y) * 0.5;
  v11 = (float)(mins->z + z) * 0.5;
  result = 0;
  context.leafTopNode = -1;
  context.pBSPData = &g_BSPData;
  center.x = v9;
  center.y = v10;
  center.z = v11;
  extents.x = x - v9;
  extents.y = y - v10;
  extents.z = z - v11;
  if ( cmodelIndex >= 0 && cmodelIndex < g_BSPData.numcmodels )
    result = CM_BoxLeafnums(&context, &center, &extents, nodenum: g_BSPData.map_cmodels.m_pArray[cmodelIndex].headnode);
  if ( topnode != nullptr )
    *topnode = context.leafTopNode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014CF90
// Name: int CM_PointContents(class Vector const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_PointContents(const Vector *p, int headnode, int contentsMask)
{
  if ( g_BSPData.numnodes != 0 && (g_BSPData.allcontents & contentsMask) != 0 )
    return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum_r(pBSPData: &g_BSPData, p, num: headnode)].contents;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CFD0
// Name: int CM_TransformedPointContents(class Vector const __near &,int,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_TransformedPointContents(const Vector *p, int headnode, const Vector *origin, const QAngle *angles)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float y; // xmm1_4
  Vector up; // [esp+0h] [ebp-30h] BYREF
  Vector right; // [esp+Ch] [ebp-24h] BYREF
  Vector forward; // [esp+18h] [ebp-18h] BYREF
  Vector p_l; // [esp+24h] [ebp-Ch] BYREF

  p_l.x = p->x - origin->x;
  p_l.y = p->y - origin->y;
  x = angles->x;
  p_l.z = p->z - origin->z;
  if ( x != 0.0 || angles->y != 0.0 || angles->z != 0.0 )
  {
    AngleVectors(angles, &forward, &right, &up);
    v5 = p_l.x;
    y = p_l.y;
    p_l.x = (float)((float)(forward.y * p_l.y) + (float)(forward.x * p_l.x)) + (float)(forward.z * p_l.z);
    LODWORD(p_l.y) = COERCE_UNSIGNED_INT((float)((float)(right.x * v5) + (float)(right.y * p_l.y)) + (float)(right.z * p_l.z))
                   ^ _mask__NegFloat_;
    p_l.z = (float)((float)(up.y * y) + (float)(up.x * v5)) + (float)(up.z * p_l.z);
  }
  return g_BSPData.map_leafs.m_pArray[CM_PointLeafnum_r(pBSPData: &g_BSPData, p: &p_l, num: headnode)].contents;
}

//------------------------------------------------------------------------------
// Address: 0x1014D110
// Name: bool IntersectRayWithBoxBrush(struct TraceInfo_t __near *,struct cbrush_t const __near *,struct cboxbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBoxBrush(TraceInfo_t *pTraceInfo, const cbrush_t *pBrush, cboxbrush_t *pBox)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm0
  __m128 v6; // xmm4
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  int v20; // eax
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  float v32; // xmm6_4
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  bool v35; // al
  int contents; // edx
  bool v38; // cf
  int v39; // ecx
  unsigned __int16 v40; // ax
  CCollisionBSPData *m_pBSPData; // ecx
  csurface_t *SurfaceAtIndex; // eax
  const char *name; // edx
  unsigned __int8 v44; // cl
  __m128 v45; // [esp-Ch] [ebp-7Ch]
  unsigned int v46; // [esp-Ch] [ebp-7Ch]
  __m128 faceId_4; // [esp+4h] [ebp-6Ch]
  __m128 v48; // [esp+14h] [ebp-5Ch]
  __m128 invDelta_4; // [esp+24h] [ebp-4Ch]
  __m128 startOutMins_4; // [esp+34h] [ebp-3Ch]
  __m128 startOutMins_4a; // [esp+34h] [ebp-3Ch]
  __m128 lastIn_4a; // [esp+44h] [ebp-2Ch]
  __m128 lastIn_4; // [esp+44h] [ebp-2Ch]

  v3 = *(__m128 *)&pTraceInfo->m_extents.x;
  v4 = _mm_sub_ps(_mm_sub_ps((__m128)pBox->mins, *(__m128 *)&pTraceInfo->m_start.x), v3);
  v5 = *(__m128 *)&pTraceInfo->m_delta.x;
  startOutMins_4 = _mm_add_ps(_mm_sub_ps((__m128)pBox->maxs, *(__m128 *)&pTraceInfo->m_start.x), v3);
  v6 = _mm_cmplt_ps(startOutMins_4, v5);
  v7 = _mm_cmplt_ps(Four_Zeros, v4);
  v8 = _mm_cmplt_ps(v5, v4);
  v9 = _mm_cmplt_ps(startOutMins_4, Four_Zeros);
  invDelta_4 = v7;
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v6, v9), _mm_and_ps(v8, v7)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return 0;
  v48 = *(__m128 *)&pTraceInfo->m_invDelta.x;
  lastIn_4a = _mm_mul_ps(v48, startOutMins_4);
  v10 = _mm_or_ps(_mm_xor_ps(v6, v9), _mm_xor_ps(v8, v7));
  v11 = _mm_mul_ps(v48, v4);
  v12 = _mm_max_ps(v11, lastIn_4a);
  faceId_4 = _mm_andnot_ps(v10, Four_Negative_FLT_MAX);
  v13 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v11, lastIn_4a), v10), faceId_4);
  v14 = _mm_andnot_ps(v10, Four_FLT_MAX);
  v15 = _mm_or_ps(_mm_and_ps(v12, v10), v14);
  v45 = v14;
  v16 = _mm_min_ps(_mm_min_ps(v15, _mm_shuffle_ps(v15, v15, 57)), _mm_shuffle_ps(v15, v15, 78));
  v17 = _mm_max_ps(_mm_max_ps(v13, _mm_shuffle_ps(v13, v13, 57)), _mm_shuffle_ps(v13, v13, 78));
  if ( _mm_movemask_ps(
         _mm_cmpeq_ps(
           _mm_cmplt_ps(
             _mm_min_ps(_mm_shuffle_ps(v16, v16, 0), Four_Ones),
             _mm_max_ps(_mm_shuffle_ps(v17, v17, 0), Four_Zeros)),
           Four_Zeros)) != 15 )
    return 0;
  v18 = _mm_mul_ps(_mm_sub_ps(v4, Four_DistEpsilons), v48);
  v19 = _mm_mul_ps(_mm_add_ps(Four_DistEpsilons, startOutMins_4), v48);
  v20 = _mm_movemask_ps(_mm_and_ps(_mm_or_ps(v9, invDelta_4), *(__m128 *)g_SIMD_clear_wmask));
  v21 = _mm_cmple_ps(v18, v19);
  v22 = _mm_andnot_ps(v21, *(__m128 *)g_CubeFaceIndex1);
  v23 = _mm_and_ps(*(__m128 *)g_CubeFaceIndex0, v21);
  v24 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v18, v19), v10), faceId_4);
  v25 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v18, v19), v10), v45);
  v26 = _mm_or_ps(v22, v23);
  v27 = _mm_shuffle_ps(v24, v24, 57);
  v28 = _mm_min_ps(_mm_min_ps(v25, _mm_shuffle_ps(v25, v25, 57)), _mm_shuffle_ps(v25, v25, 78));
  v29 = _mm_max_ps(v24, v27);
  v30 = _mm_cmplt_ps(v27, v24);
  v31 = _mm_shuffle_ps(v24, v24, 78);
  v32 = _mm_andnot_ps(v30, _mm_shuffle_ps(v26, v26, 57)).m128_f32[0];
  v27.m128_i32[0] = v26.m128_i32[0] & v30.m128_i32[0];
  v33 = _mm_cmplt_ps(v31, v29);
  v34 = _mm_max_ps(v29, v31);
  v46 = _mm_andnot_ps(v33, _mm_shuffle_ps(v26, v26, 78)).m128_u32[0]
      | (v27.m128_i32[0] | LODWORD(v32)) & v33.m128_i32[0];
  lastIn_4 = _mm_min_ps(_mm_shuffle_ps(v28, v28, 0), Four_Ones);
  v35 = v20 != 0;
  startOutMins_4a = _mm_max_ps(_mm_shuffle_ps(v34, v34, 0), Four_Zeros);
  if ( _mm_movemask_ps(_mm_cmpeq_ps(_mm_cmplt_ps(lastIn_4, startOutMins_4a), Four_Zeros)) != 15 )
    return 0;
  if ( v35 && (!pTraceInfo->m_ispoint || pTraceInfo->m_trace.fractionleftsolid <= startOutMins_4a.m128_f32[0]) )
  {
    if ( pTraceInfo->m_trace.fraction <= startOutMins_4a.m128_f32[0] )
      return 0;
    LODWORD(pTraceInfo->m_trace.fraction) = startOutMins_4a.m128_i32[0];
    pTraceInfo->m_bDispHit = 0;
    v40 = pBox->surfaceIndex[v46];
    m_pBSPData = pTraceInfo->m_pBSPData;
    pTraceInfo->m_trace.plane.normal = vec3_origin;
    SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: m_pBSPData, surfaceIndex: v40);
    name = SurfaceAtIndex->name;
    *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
    LOWORD(SurfaceAtIndex) = pBox->surfaceIndex[v46];
    pTraceInfo->m_trace.surface.name = name;
    pTraceInfo->m_trace.worldSurfaceIndex = (unsigned __int16)SurfaceAtIndex;
    if ( v46 < 3 )
    {
      v44 = signbits[v46];
      LODWORD(pTraceInfo->m_trace.plane.dist) = *((_DWORD *)&pBox->mins.x + v46) ^ _mask__NegFloat_;
      *((_DWORD *)&pTraceInfo->m_trace.plane.normal.x + v46) = -1082130432;
      pTraceInfo->m_trace.plane.type = v46;
      pTraceInfo->m_trace.contents = pBrush->contents;
      pTraceInfo->m_trace.plane.signbits = v44;
    }
    else
    {
      pTraceInfo->m_trace.plane.dist = *(&pBox->mins.y + v46);
      *((_DWORD *)&pTraceInfo->m_trace.endpos.x + v46) = 1065353216;
      pTraceInfo->m_trace.plane.type = v46 - 3;
      pTraceInfo->m_trace.contents = pBrush->contents;
      pTraceInfo->m_trace.plane.signbits = 0;
    }
    return 1;
  }
  else
  {
    contents = pBrush->contents;
    pTraceInfo->m_trace.startsolid = true;
    pTraceInfo->m_trace.contents = contents;
    if ( lastIn_4.m128_f32[0] >= 1.0 )
    {
      pTraceInfo->m_trace.allsolid = true;
      pTraceInfo->m_trace.fraction = 0.0;
      return 0;
    }
    if ( lastIn_4.m128_f32[0] <= pTraceInfo->m_trace.fractionleftsolid )
      return 0;
    v38 = lastIn_4.m128_f32[0] < pTraceInfo->m_trace.fraction;
    LODWORD(pTraceInfo->m_trace.fractionleftsolid) = lastIn_4.m128_i32[0];
    if ( v38 )
      return 0;
    v39 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
    pTraceInfo->m_trace.surface.name = CCollisionBSPData::nullsurface.name;
    pTraceInfo->m_trace.fraction = 1.0;
    *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v39;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D4F0
// Name: void CM_TestBoxInBrush(struct TraceInfo_t __near *,struct cbrush_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TestBoxInBrush(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // eax
  __m128 *v3; // eax
  Vector *p_m_maxs; // esi
  int firstbrushside; // edx
  float z; // xmm0_4
  float y; // xmm4_4
  float x; // xmm5_4
  cbrushside_t *v9; // eax
  cplane_t *plane; // edi
  Vector *v11; // eax
  int v12; // edi
  double v13; // st7
  Vector ofs; // [esp+0h] [ebp-2Ch] BYREF
  const cbrush_t *v15; // [esp+Ch] [ebp-20h]
  int v16; // [esp+10h] [ebp-1Ch]
  float v17; // [esp+14h] [ebp-18h]
  int v18; // [esp+18h] [ebp-14h]
  cbrushside_t *v19; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int j; // [esp+24h] [ebp-8h]
  char *v22; // [esp+28h] [ebp-4h]

  numsides = brush->numsides;
  v15 = brush;
  if ( (_WORD)numsides == 0xFFFF )
  {
    v3 = (__m128 *)&pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside];
    if ( _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_and_ps(
               _mm_cmplt_ps(
                 _mm_min_ps(v3[1], _mm_add_ps(*(__m128 *)&pTraceInfo->m_maxs.x, *(__m128 *)&pTraceInfo->m_start.x)),
                 _mm_max_ps(*v3, _mm_add_ps(*(__m128 *)&pTraceInfo->m_mins.x, *(__m128 *)&pTraceInfo->m_start.x))),
               *(__m128 *)g_SIMD_clear_wmask),
             Four_Zeros)) == 15 )
    {
LABEL_15:
      *(_WORD *)&pTraceInfo->m_trace.allsolid = 257;
      pTraceInfo->m_trace.fraction = 0.0;
      pTraceInfo->m_trace.fractionleftsolid = 1.0;
      pTraceInfo->m_trace.contents = brush->contents;
    }
  }
  else if ( (_WORD)numsides != 0 )
  {
    p_m_maxs = &pTraceInfo->m_maxs;
    memset(&ofs, 0, sizeof(ofs));
    i = 0;
    v16 = numsides;
    firstbrushside = brush->firstbrushside;
    z = pTraceInfo->m_start.z;
    y = pTraceInfo->m_start.y;
    x = pTraceInfo->m_start.x;
    v18 = -12;
    v22 = (char *)((char *)&ofs - (char *)p_m_maxs);
    v9 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[firstbrushside];
    v17 = z;
    v19 = v9;
    while ( 1 )
    {
      plane = v9->plane;
      v11 = &pTraceInfo->m_maxs;
      v12 = (char *)plane - (char *)p_m_maxs;
      for ( j = 3; j != 0; --j )
      {
        if ( *(float *)((char *)&v11->x + v12) >= 0.0 )
          v13 = v11[v18 / 0xCu].x;
        else
          v13 = v11->x;
        *(float *)((char *)&v11->x + (_DWORD)v22) = v13;
        v11 = (Vector *)((char *)v11 + 4);
      }
      if ( (float)((float)((float)((float)(x * v19->plane->normal.x) + (float)(y * v19->plane->normal.y))
                         + (float)(v17 * v19->plane->normal.z))
                 - (float)(v19->plane->dist
                         - (float)((float)((float)(v19->plane->normal.x * ofs.x) + (float)(v19->plane->normal.y * ofs.y))
                                 + (float)(v19->plane->normal.z * ofs.z)))) > 0.0 )
        break;
      v9 = v19 + 1;
      ++i;
      ++v19;
      if ( i >= v16 )
      {
        brush = v15;
        goto LABEL_15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D6A0
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014D730
// Name: void FloodArea_r(class CCollisionBSPData __near *,struct carea_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodArea_r(CCollisionBSPData *pBSPData, carea_t *area, int floodnum)
{
  bool v4; // cc
  dareaportal_t *v5; // edi
  int i; // [esp+10h] [ebp+8h]

  if ( area->floodvalid == pBSPData->floodvalid )
  {
    if ( area->floodnum == floodnum )
      return;
    Sys_Error(error: "FloodArea_r: reflooded");
  }
  v4 = area->numareaportals <= 0;
  area->floodnum = floodnum;
  area->floodvalid = pBSPData->floodvalid;
  v5 = &pBSPData->map_areaportals.m_pArray[area->firstareaportal];
  i = 0;
  if ( !v4 )
  {
    do
    {
      if ( pBSPData->portalopen.m_pArray[v5->m_PortalKey] )
        FloodArea_r(pBSPData, area: &pBSPData->map_areas.m_pArray[v5->otherarea], floodnum);
      ++v5;
      ++i;
    }
    while ( i < area->numareaportals );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D7D0
// Name: void FloodAreaConnections(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodAreaConnections(CCollisionBSPData *pBSPData)
{
  int v2; // eax
  carea_t *v3; // esi
  int firstareaportal; // ecx
  bool v5; // zf
  bool v6; // sf
  dareaportal_t *v7; // ebx
  int floodnum; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]
  int pBSPDataa; // [esp+18h] [ebp+8h]

  ++pBSPData->floodvalid;
  v2 = 0;
  i = 1;
  if ( pBSPData->numareas > 1 )
  {
    pBSPDataa = 1;
    do
    {
      v3 = &pBSPData->map_areas.m_pArray[pBSPDataa];
      if ( v3->floodvalid != pBSPData->floodvalid )
      {
        firstareaportal = v3->firstareaportal;
        ++v2;
        v5 = v3->numareaportals == 0;
        v6 = v3->numareaportals < 0;
        v3->floodnum = v2;
        v3->floodvalid = pBSPData->floodvalid;
        floodnum = v2;
        v7 = &pBSPData->map_areaportals.m_pArray[firstareaportal];
        v10 = 0;
        if ( !v6 && !v5 )
        {
          do
          {
            if ( pBSPData->portalopen.m_pArray[v7->m_PortalKey] )
            {
              FloodArea_r(pBSPData, area: &pBSPData->map_areas.m_pArray[v7->otherarea], floodnum: v2);
              v2 = floodnum;
            }
            ++v7;
            ++v10;
          }
          while ( v10 < v3->numareaportals );
        }
      }
      ++pBSPDataa;
      ++i;
    }
    while ( i < pBSPData->numareas );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D8A0
// Name: void CM_SetAreaPortalState(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetAreaPortalState(int portalnum, int isOpen)
{
  if ( portalnum > g_BSPData.numareaportals )
    Sys_Error(error: "portalnum > numareaportals");
  g_BSPData.portalopen.m_pArray[portalnum] = isOpen != 0;
  FloodAreaConnections(pBSPData: &g_BSPData);
}

//------------------------------------------------------------------------------
// Address: 0x1014D8E0
// Name: void CM_SetAreaPortalStates(int const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetAreaPortalStates(char *portalnums, char *isOpen, int nPortals)
{
  int v3; // ebx
  char *v4; // esi
  int v5; // edx
  bool v6; // cl
  int v7; // edi
  int v8; // esi
  int v9; // ebx

  v3 = nPortals;
  if ( nPortals != 0 )
  {
    if ( nPortals > 0 )
    {
      v4 = portalnums;
      do
      {
        if ( *(_DWORD *)v4 > g_BSPData.numareaportals )
          Sys_Error(error: "portalnum > numareaportals");
        v5 = *(_DWORD *)v4;
        v6 = *(_DWORD *)&v4[isOpen - portalnums] != 0;
        v4 += 4;
        --v3;
        g_BSPData.portalopen.m_pArray[v5] = v6;
      }
      while ( v3 != 0 );
    }
    ++g_BSPData.floodvalid;
    v7 = 1;
    v8 = 0;
    if ( g_BSPData.numareas > 1 )
    {
      v9 = 1;
      do
      {
        if ( g_BSPData.map_areas.m_pArray[v9].floodvalid != g_BSPData.floodvalid )
          FloodArea_r(pBSPData: &g_BSPData, area: &g_BSPData.map_areas.m_pArray[v9], floodnum: ++v8);
        ++v7;
        ++v9;
      }
      while ( v7 < g_BSPData.numareas );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D990
// Name: bool CM_AreasConnected(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CM_AreasConnected(int area1, int area2)
{
  if ( map_noareas.m_pParent != nullptr && map_noareas.m_pParent->m_Value.m_nValue != 0 )
    return true;
  if ( area1 >= g_BSPData.numareas || area2 >= g_BSPData.numareas )
    Sys_Error(
      error: "area(1==%i, 2==%i) >= numareas (%i):  Check if engine->ResetPVS() was called from ClientSetupVisibility",
      area1,
      area2,
      g_BSPData.numareas);
  return g_BSPData.map_areas.m_pArray[area1].floodnum == g_BSPData.map_areas.m_pArray[area2].floodnum;
}

//------------------------------------------------------------------------------
// Address: 0x1014D9F0
// Name: void CM_LeavesConnected(class Vector const __near &,int,int const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_LeavesConnected(const Vector *vecOrigin, int nCount, const int *pLeaves, bool *pIsConnected)
{
  int v4; // eax
  int v5; // ecx
  int i; // eax

  if ( map_noareas.m_pParent != nullptr && map_noareas.m_pParent->m_Value.m_nValue != 0 )
  {
    memset(dst: (unsigned __int8 *)pIsConnected, value: 1u, count: nCount);
  }
  else
  {
    if ( g_BSPData.numplanes != 0 )
      v4 = CM_PointLeafnum_r(pBSPData: &g_BSPData, p: vecOrigin, num: 0);
    else
      v4 = 0;
    v5 = (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[v4] + 3) << 7) >> 7;
    for ( i = 0; i < nCount; ++i )
      pIsConnected[i] = g_BSPData.map_areas.m_pArray[v5].floodnum == g_BSPData.map_areas.m_pArray[(__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[pLeaves[i]] + 3) << 7) >> 7].floodnum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DAA0
// Name: int CM_WriteAreaBits(unsigned char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_WriteAreaBits(unsigned __int8 *buffer, int buflen, int area)
{
  int v3; // ebx
  int m_nValue; // eax
  int v6; // eax
  int v7; // edx
  int bytes; // [esp+8h] [ebp-4h]
  int floodnum; // [esp+18h] [ebp+Ch]

  if ( buflen < 32 )
    Sys_Error(error: "CM_WriteAreaBits with buffer size %d < 32\n", buflen);
  v3 = (g_BSPData.numareas + 7) >> 3;
  bytes = v3;
  if ( map_noareas.m_pParent != nullptr && (m_nValue = map_noareas.m_pParent->m_Value.m_nValue) != 0 )
  {
    _V_memset(dest: buffer, fill: (unsigned __int8)-(m_nValue != 2), count: buflen);
    return v3;
  }
  else
  {
    _V_memset(dest: buffer, fill: 0, count: buflen);
    floodnum = g_BSPData.map_areas.m_pArray[area].floodnum;
    v6 = 0;
    if ( g_BSPData.numareas > 0 )
    {
      v7 = 0;
      do
      {
        if ( g_BSPData.map_areas.m_pArray[v7].floodnum == floodnum || area == 0 )
        {
          buffer[v6 >> 3] |= 1 << (v6 & 7);
          v3 = bytes;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < g_BSPData.numareas );
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DB70
// Name: bool CM_GetAreaPortalPlane(class Vector const __near &,int,class VPlane __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CM_GetAreaPortalPlane(const Vector *vViewOrigin, int portalKey, VPlane *pPlane)
{
  int v3; // eax
  int v4; // eax
  carea_t *v5; // eax
  int numareaportals; // edx
  int v7; // ecx
  dareaportal_t *i; // eax
  double x; // st7
  cplane_t *v11; // eax

  if ( g_BSPData.numplanes != 0 )
  {
    v3 = CM_PointLeafnum_r(pBSPData: &g_BSPData, p: vViewOrigin, num: 0);
    if ( v3 < 0 )
      return 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v3 >= g_BSPData.numleafs )
    return 0;
  v4 = (__int16)(*((_WORD *)&g_BSPData.map_leafs.m_pArray[v3] + 3) << 7) >> 7;
  if ( v4 < 0 || v4 >= g_BSPData.numareas )
    return 0;
  v5 = &g_BSPData.map_areas.m_pArray[v4];
  numareaportals = v5->numareaportals;
  v7 = 0;
  if ( v5->numareaportals <= 0 )
    return 0;
  for ( i = &g_BSPData.map_areaportals.m_pArray[v5->firstareaportal]; i->m_PortalKey != portalKey; ++i )
  {
    if ( ++v7 >= numareaportals )
      return 0;
  }
  x = g_BSPData.map_planes.m_pArray[i->planenum].normal.x;
  v11 = &g_BSPData.map_planes.m_pArray[i->planenum];
  pPlane->m_Normal.x = x;
  pPlane->m_Normal.y = v11->normal.y;
  pPlane->m_Normal.z = v11->normal.z;
  pPlane->m_Dist = v11->dist;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DC40
// Name: bool CM_HeadnodeVisible(int,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CM_HeadnodeVisible(int nodenum, const unsigned __int8 *visbits, int vissize)
{
  int v3; // eax
  cnode_t *map_rootnode; // ebx
  cnode_t *v5; // esi
  int cluster; // eax

  v3 = nodenum;
  if ( nodenum < 0 )
  {
LABEL_5:
    cluster = g_BSPData.map_leafs.m_pArray[-v3 - 1].cluster;
    return cluster != -1 && ((unsigned __int8)(1 << (cluster & 7)) & visbits[cluster >> 3]) != 0;
  }
  else
  {
    map_rootnode = g_BSPData.map_rootnode;
    while ( 1 )
    {
      v5 = &map_rootnode[v3];
      if ( CM_HeadnodeVisible(nodenum: v5->children[0], visbits, vissize) )
        return true;
      v3 = v5->children[1];
      if ( v3 < 0 )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DCC0
// Name: int CM_BoxVisible(class Vector const __near &,class Vector const __near &,unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CM_BoxVisible(const Vector *mins, const Vector *maxs, const unsigned __int8 *visbits, int vissize)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  int v10; // ebx
  int cluster; // edi
  int v12; // esi
  int leafList[256]; // [esp+0h] [ebp-428h] BYREF
  leafnums_t context; // [esp+400h] [ebp-28h] BYREF
  Vector extents; // [esp+410h] [ebp-18h] BYREF
  Vector center; // [esp+41Ch] [ebp-Ch] BYREF
  const Vector *maxsa; // [esp+434h] [ebp+Ch]

  x = mins->x;
  y = mins->y;
  z = mins->z;
  context.pLeafList = leafList;
  v7 = maxs->x;
  v8 = maxs->y;
  v9 = maxs->z;
  v10 = 0;
  context.leafTopNode = -1;
  context.leafMaxCount = 256;
  context.pBSPData = &g_BSPData;
  center.x = (float)(x + v7) * 0.5;
  center.y = (float)(y + v8) * 0.5;
  center.z = (float)(z + v9) * 0.5;
  extents.x = v7 - center.x;
  extents.y = v8 - center.y;
  extents.z = v9 - center.z;
  maxsa = nullptr;
  if ( g_BSPData.numcmodels > 0 )
    maxsa = (const Vector *)CM_BoxLeafnums(
                              &context,
                              &center,
                              &extents,
                              nodenum: g_BSPData.map_cmodels.m_pArray->headnode);
  if ( (int)maxsa <= 0 )
    return 0;
  while ( 1 )
  {
    cluster = g_BSPData.map_leafs.m_pArray[leafList[v10]].cluster;
    v12 = cluster >> 3;
    if ( cluster >> 3 > vissize )
      Sys_Error(error: "CM_BoxVisible:  cluster %i, offset %i out of bounds %i\n", cluster, v12, vissize);
    if ( ((unsigned __int8)(1 << (cluster & 7)) & visbits[v12]) != 0 )
      break;
    if ( ++v10 >= (int)maxsa )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014DDF0
// Name: void CM_SetupAreaFloodNums(unsigned char __near * const,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_SetupAreaFloodNums(unsigned __int8 *areaFloodNums, int *pNumAreas)
{
  int v2; // eax
  int v3; // ecx

  *pNumAreas = g_BSPData.numareas;
  if ( g_BSPData.numareas > 256 )
    _Error(a1: "pBSPData->numareas > MAX_MAP_AREAS");
  v2 = 0;
  if ( g_BSPData.numareas > 0 )
  {
    v3 = 0;
    do
      areaFloodNums[v2++] = g_BSPData.map_areas.m_pArray[v3++].floodnum;
    while ( v2 < g_BSPData.numareas );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014DE50
// Name: public: CFastPointLeafNum::CFastPointLeafNum(void)
// Source: json
//------------------------------------------------------------------------------
CFastPointLeafNum *__thiscall CFastPointLeafNum::CFastPointLeafNum(CFastPointLeafNum *this)
{
  this->m_flDistToExitLeafSqr = -1.0;
  this->m_iCachedLeaf = -1;
  this->m_vCachedPos.x = 0.0;
  this->m_vCachedPos.y = 0.0;
  this->m_vCachedPos.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014DE80
// Name: public: int CFastPointLeafNum::GetLeaf(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFastPointLeafNum::GetLeaf(CFastPointLeafNum *this, const Vector *vPos)
{
  int m_iCachedLeaf; // ecx
  int result; // eax

  m_iCachedLeaf = this->m_iCachedLeaf;
  if ( m_iCachedLeaf >= 0
    && m_iCachedLeaf < g_BSPData.numleafs
    && (float)((float)((float)((float)(vPos->y - this->m_vCachedPos.y) * (float)(vPos->y - this->m_vCachedPos.y))
                     + (float)((float)(vPos->x - this->m_vCachedPos.x) * (float)(vPos->x - this->m_vCachedPos.x)))
             + (float)((float)(vPos->z - this->m_vCachedPos.z) * (float)(vPos->z - this->m_vCachedPos.z))) <= this->m_flDistToExitLeafSqr )
  {
    return m_iCachedLeaf;
  }
  this->m_vCachedPos = *vPos;
  this->m_flDistToExitLeafSqr = 1.0e24;
  result = CM_PointLeafnumMinDistSqr_r(pBSPData: &g_BSPData, p: vPos, num: 0, minDistSqr: &this->m_flDistToExitLeafSqr);
  this->m_iCachedLeaf = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014DF10
// Name: void CM_ClipBoxToBrush<1>(struct TraceInfo_t restrict __near *,struct cbrush_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_ClipBoxToBrush<1>(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // ecx
  float v4; // xmm7_4
  cbrushside_t *v5; // eax
  char v6; // bl
  cbrushside_t *v7; // edx
  cbrushside_t *v8; // edi
  float v9; // xmm0_4
  float *p_x; // ecx
  float dist; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  bool v16; // cf
  const char *name; // eax
  int v18; // ecx
  unsigned __int16 surfaceIndex; // di
  csurface_t *SurfaceAtIndex; // eax
  int v21; // edx
  const cplane_t *plane; // [esp-Ch] [ebp-1Ch]
  int brushContents; // [esp+4h] [ebp-Ch]
  float leavefrac; // [esp+8h] [ebp-8h]
  bool startout; // [esp+Fh] [ebp-1h]

  numsides = brush->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    IntersectRayWithBoxBrush(
      pTraceInfo,
      pBrush: brush,
      pBox: &pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside]);
    return;
  }
  if ( (_WORD)numsides != 0 )
  {
    v4 = -99999.0;
    brushContents = brush->contents;
    v5 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[brush->firstbrushside];
    v6 = 0;
    v7 = &v5[numsides];
    v8 = nullptr;
    v9 = 1.0;
    leavefrac = 1.0;
    startout = false;
    if ( v5 >= v7 )
    {
LABEL_22:
      pTraceInfo->m_trace.startsolid = true;
      pTraceInfo->m_trace.contents = brushContents;
      if ( v6 != 0 )
      {
        if ( v9 != 1.0 && v9 > pTraceInfo->m_trace.fractionleftsolid )
        {
          v16 = v9 < pTraceInfo->m_trace.fraction;
          pTraceInfo->m_trace.fractionleftsolid = v9;
          if ( !v16 )
          {
            name = CCollisionBSPData::nullsurface.name;
            v18 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
            pTraceInfo->m_trace.fraction = 1.0;
            pTraceInfo->m_trace.surface.name = name;
            *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v18;
          }
        }
      }
      else
      {
        pTraceInfo->m_trace.allsolid = true;
        pTraceInfo->m_trace.fraction = 0.0;
        pTraceInfo->m_trace.fractionleftsolid = 1.0;
      }
      return;
    }
    while ( 1 )
    {
      p_x = &v5->plane->normal.x;
      dist = v5->plane->dist;
      if ( v5->bBevel == 0 )
      {
        v12 = (float)((float)((float)(pTraceInfo->m_start.y * p_x[1]) + (float)(*p_x * pTraceInfo->m_start.x))
                    + (float)(pTraceInfo->m_start.z * p_x[2]))
            - dist;
        v13 = (float)((float)((float)(pTraceInfo->m_end.y * p_x[1]) + (float)(pTraceInfo->m_end.x * *p_x))
                    + (float)(pTraceInfo->m_end.z * p_x[2]))
            - dist;
        if ( v12 > 0.0 )
        {
          startout = true;
          if ( v13 > 0.0 )
            return;
          goto LABEL_11;
        }
        if ( v13 > 0.0 )
        {
          v6 = 1;
LABEL_11:
          if ( v12 <= v13 )
          {
            if ( leavefrac > (float)((float)(v12 + 0.03125) / (float)(v12 - v13)) )
              leavefrac = (float)(v12 + 0.03125) / (float)(v12 - v13);
          }
          else
          {
            v14 = v12 - 0.03125;
            if ( (float)(v12 - 0.03125) < 0.0 )
              v14 = 0.0;
            v15 = v14 / (float)(v12 - v13);
            if ( v15 > v4 )
            {
              v4 = v15;
              v8 = v5;
            }
          }
        }
      }
      if ( ++v5 >= v7 )
      {
        if ( !startout || (float)(pTraceInfo->m_trace.fractionleftsolid - v4) > 0.0 )
        {
          v9 = leavefrac;
          goto LABEL_22;
        }
        if ( leavefrac > v4 && v4 > -99999.0 && pTraceInfo->m_trace.fraction > v4 )
        {
          if ( v4 < 0.0 )
            v4 = 0.0;
          plane = v8->plane;
          pTraceInfo->m_trace.fraction = v4;
          pTraceInfo->m_bDispHit = 0;
          cplane_t::operator=(this: &pTraceInfo->m_trace.plane, __that: plane);
          surfaceIndex = v8->surfaceIndex;
          SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: pTraceInfo->m_pBSPData, surfaceIndex);
          v21 = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
          pTraceInfo->m_trace.surface.name = SurfaceAtIndex->name;
          *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v21;
          pTraceInfo->m_trace.worldSurfaceIndex = surfaceIndex;
          pTraceInfo->m_trace.contents = brushContents;
        }
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E1A0
// Name: void CM_ClipBoxToBrush<0>(struct TraceInfo_t restrict __near *,struct cbrush_t const restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_ClipBoxToBrush<0>(TraceInfo_t *pTraceInfo, const cbrush_t *brush)
{
  int numsides; // ecx
  cbrushside_t *v4; // eax
  char v5; // bl
  cbrushside_t *v6; // edx
  cbrushside_t *v7; // edi
  float v8; // xmm1_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  bool v15; // cf
  const char *name; // eax
  int v17; // ecx
  float v18; // xmm0_4
  unsigned __int16 surfaceIndex; // di
  csurface_t *SurfaceAtIndex; // eax
  const char *v21; // ecx
  int v22; // edx
  const cplane_t *plane; // [esp-Ch] [ebp-40h]
  float x; // [esp+18h] [ebp-1Ch]
  float dist; // [esp+1Ch] [ebp-18h]
  int brushContents; // [esp+24h] [ebp-10h]
  float enterfrac; // [esp+28h] [ebp-Ch]
  float leavefrac; // [esp+2Ch] [ebp-8h]
  bool startout; // [esp+33h] [ebp-1h]

  numsides = brush->numsides;
  if ( (_WORD)numsides == 0xFFFF )
  {
    IntersectRayWithBoxBrush(
      pTraceInfo,
      pBrush: brush,
      pBox: &pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[brush->firstbrushside]);
    return;
  }
  if ( (_WORD)numsides != 0 )
  {
    brushContents = brush->contents;
    v4 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[brush->firstbrushside];
    enterfrac = -99999.0;
    v5 = 0;
    v6 = &v4[numsides];
    v7 = nullptr;
    v8 = 1.0;
    leavefrac = 1.0;
    startout = false;
    if ( v4 >= v6 )
    {
LABEL_19:
      pTraceInfo->m_trace.startsolid = true;
      pTraceInfo->m_trace.contents = brushContents;
      if ( v5 != 0 )
      {
        if ( v8 != 1.0 && v8 > pTraceInfo->m_trace.fractionleftsolid )
        {
          v15 = v8 < pTraceInfo->m_trace.fraction;
          pTraceInfo->m_trace.fractionleftsolid = v8;
          if ( !v15 )
          {
            name = CCollisionBSPData::nullsurface.name;
            v17 = *(_DWORD *)&CCollisionBSPData::nullsurface.surfaceProps;
            pTraceInfo->m_trace.fraction = 1.0;
            pTraceInfo->m_trace.surface.name = name;
            *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v17;
          }
        }
      }
      else
      {
        pTraceInfo->m_trace.allsolid = true;
        pTraceInfo->m_trace.fraction = 0.0;
        pTraceInfo->m_trace.fractionleftsolid = 1.0;
      }
      return;
    }
    while ( 1 )
    {
      y = v4->plane->normal.y;
      z = v4->plane->normal.z;
      x = v4->plane->normal.x;
      dist = fabs(y * pTraceInfo->m_extents.y)
           + fabs(x * pTraceInfo->m_extents.x)
           + fabs(z * pTraceInfo->m_extents.z)
           + v4->plane->dist;
      v11 = (float)((float)((float)(pTraceInfo->m_start.y * y) + (float)(pTraceInfo->m_start.x * x))
                  + (float)(pTraceInfo->m_start.z * z))
          - dist;
      v12 = (float)((float)((float)(y * pTraceInfo->m_end.y) + (float)(x * pTraceInfo->m_end.x))
                  + (float)(z * pTraceInfo->m_end.z))
          - dist;
      if ( v11 > 0.0 )
        break;
      if ( v12 > 0.0 )
      {
        v5 = 1;
LABEL_10:
        if ( v11 <= v12 )
        {
          if ( leavefrac > (float)((float)(v11 + 0.03125) / (float)(v11 - v12)) )
            leavefrac = (float)(v11 + 0.03125) / (float)(v11 - v12);
        }
        else
        {
          v13 = v11 - 0.03125;
          if ( (float)(v11 - 0.03125) < 0.0 )
            v13 = 0.0;
          v14 = v13 / (float)(v11 - v12);
          if ( v14 > enterfrac )
          {
            enterfrac = v14;
            v7 = v4;
          }
        }
      }
      if ( ++v4 >= v6 )
      {
        v8 = leavefrac;
        if ( !startout )
          goto LABEL_19;
        v18 = enterfrac;
        if ( leavefrac > enterfrac && enterfrac > -99999.0 && pTraceInfo->m_trace.fraction > enterfrac )
        {
          if ( enterfrac < 0.0 )
            v18 = 0.0;
          plane = v7->plane;
          pTraceInfo->m_trace.fraction = v18;
          pTraceInfo->m_bDispHit = 0;
          cplane_t::operator=(this: &pTraceInfo->m_trace.plane, __that: plane);
          surfaceIndex = v7->surfaceIndex;
          SurfaceAtIndex = CCollisionBSPData::GetSurfaceAtIndex(this: pTraceInfo->m_pBSPData, surfaceIndex);
          v21 = SurfaceAtIndex->name;
          v22 = *(_DWORD *)&SurfaceAtIndex->surfaceProps;
          pTraceInfo->m_trace.worldSurfaceIndex = surfaceIndex;
          pTraceInfo->m_trace.surface.name = v21;
          *(_DWORD *)&pTraceInfo->m_trace.surface.surfaceProps = v22;
          pTraceInfo->m_trace.contents = brushContents;
        }
        return;
      }
    }
    startout = true;
    if ( v12 > 0.0 )
      return;
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E4B0
// Name: void PushTraceVisits(struct TraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PushTraceVisits(TraceInfo_t *pTraceInfo)
{
  int v1; // ecx
  unsigned __int8 **v3; // esi

  v1 = ++pTraceInfo->m_nCheckDepth;
  if ( pTraceInfo->m_Count[v1]++ == -1 )
  {
    pTraceInfo->m_Count[v1] = 1;
    v3 = (unsigned __int8 **)((char *)pTraceInfo + 20 * v1);
    memset(dst: v3[74], value: 0, count: 4 * (_DWORD)v3[77]);
    memset(dst: v3[84], value: 0, count: 4 * (_DWORD)v3[87]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E520
// Name: struct vcollide_t __near * CM_GetVCollide(int)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__cdecl CM_GetVCollide(int modelIndex)
{
  cmodel_t *v1; // eax

  if ( modelIndex >= 0
    && modelIndex <= g_BSPData.numcmodels
    && (v1 = &g_BSPData.map_cmodels.m_pArray[modelIndex]) != nullptr )
  {
    return &v1->vcollisionData;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E560
// Name: char __near * CM_EntityString(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CM_EntityString()
{
  if ( g_BSPData.map_entitystring.m_buf.m_Put != 0
    || g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: g_BSPData.map_entitystring.m_pFilename,
         a3: nullptr,
         a4: &g_BSPData.map_entitystring.m_buf,
         a5: g_BSPData.map_entitystring.m_nCount,
         a6: g_BSPData.map_entitystring.m_nOffset,
         a7: nullptr) )
  {
    return (char *)&g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory[g_BSPData.map_entitystring.m_buf.m_Get
                                                                      - g_BSPData.map_entitystring.m_buf.m_nOffset];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E5B0
// Name: void CM_RegisterPaintMap(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_RegisterPaintMap(CCollisionBSPData *pBSPData)
{
  char *v1; // eax
  const char *v2; // eax
  KeyValues *v3; // esi
  KeyValues *FirstValue; // eax
  bool v5; // bl

  if ( pBSPData->map_entitystring.m_buf.m_Put != 0
    || g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: pBSPData->map_entitystring.m_pFilename,
         a3: nullptr,
         a4: &pBSPData->map_entitystring.m_buf,
         a5: pBSPData->map_entitystring.m_nCount,
         a6: pBSPData->map_entitystring.m_nOffset,
         a7: nullptr) )
  {
    v1 = (char *)&pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory[pBSPData->map_entitystring.m_buf.m_Get
                                                                    - pBSPData->map_entitystring.m_buf.m_nOffset];
  }
  else
  {
    v1 = nullptr;
  }
  v2 = V_stristr(pStr: v1, pSearch: "paintinmap");
  if ( v2 != nullptr )
  {
    v3 = KeyValues::FromString(szName: defaultValue, szStringVal: v2, ppEndOfParse: nullptr);
    FirstValue = KeyValues::GetFirstValue(this: v3);
    v5 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue)[1] == 49;
    KeyValues::deleteThis(this: v3);
    g_PaintManager.m_bShouldRegister = v5;
  }
  else
  {
    g_PaintManager.m_bShouldRegister = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E670
// Name: struct cmodel_t __near * CM_LoadMap(char const __near *,bool,struct texinfo_s __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
cmodel_t *__cdecl CM_LoadMap(
        const char *pPathName,
        bool allowReusePrevious,
        texinfo_s *pTexinfo,
        int texinfoCount,
        unsigned int *checksum)
{
  int i; // eax

  if ( strcmp(g_BSPData.mapPathName, pPathName) == 0 && allowReusePrevious )
  {
    *checksum = last_checksum;
    return g_BSPData.map_cmodels.m_pArray;
  }
  else
  {
    CollisionBSPData_PreLoad(pBSPData: &g_BSPData);
    if ( pPathName != nullptr && *pPathName != 0 )
    {
      CMapLoadHelper::Init(pMapModel: nullptr, pPathName);
      CollisionBSPData_Load(pPathName, pBSPData: &g_BSPData, pTexinfo, texinfoCount);
      CMapLoadHelper::Shutdown();
      CM_DispTreeLeafnum(pBSPData: &g_BSPData);
      for ( i = 0; i < g_BSPData.numportalopen; ++i )
        g_BSPData.portalopen.m_pArray[i] = false;
      FloodAreaConnections(pBSPData: &g_BSPData);
      CM_RegisterPaintMap(pBSPData: &g_BSPData);
      return g_BSPData.map_cmodels.m_pArray;
    }
    else
    {
      *checksum = 0;
      return g_BSPData.map_cmodels.m_pArray;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E760
// Name: struct vcollide_t __near * CM_VCollideForModel(int,struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
vcollide_t *__cdecl CM_VCollideForModel(int modelindex, const model_t *pModel)
{
  int v3; // eax
  cmodel_t *v4; // eax

  if ( pModel->type == mod_brush )
  {
    v3 = modelindex - 1;
    if ( modelindex - 1 < 0 )
      return nullptr;
    if ( v3 > g_BSPData.numcmodels )
      return nullptr;
    v4 = &g_BSPData.map_cmodels.m_pArray[v3];
    if ( v4 == nullptr )
      return nullptr;
    return &v4->vcollisionData;
  }
  else
  {
    if ( pModel->type != mod_studio )
      return nullptr;
    return ((vcollide_t *(__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: pModel->studio);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E7C0
// Name: CM_TestInLeaf
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_TestInLeaf(TraceInfo_t *pTraceInfo@<ecx>, int ndxLeaf@<eax>)
{
  cleaf_t *v2; // esi
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  int v5; // eax
  CCollisionBSPData *m_pBSPData; // edx
  int v7; // eax
  const cbrush_t *v8; // edx
  int dispCount; // eax
  unsigned int count; // [esp+Ch] [ebp-8h]
  int ndxLeafBrush; // [esp+10h] [ebp-4h]

  v2 = &pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  count = pTraceInfo->m_Count[m_nCheckDepth];
  v5 = 0;
  ndxLeafBrush = 0;
  if ( v2->numleafbrushes != 0 )
  {
    while ( 1 )
    {
      m_pBSPData = pTraceInfo->m_pBSPData;
      v7 = m_pBSPData->map_leafbrushes.m_pArray[v5 + v2->firstleafbrush];
      v8 = &m_pBSPData->map_brushes.m_pArray[v7];
      if ( m_pMemory[v7] != count )
      {
        m_pMemory[v7] = count;
        if ( (pTraceInfo->m_contents & v8->contents) != 0 )
        {
          CM_TestBoxInBrush(pTraceInfo, brush: v8);
          if ( pTraceInfo->m_trace.fraction == 0.0 )
            break;
        }
      }
      v5 = ndxLeafBrush + 1;
      ndxLeafBrush = v5;
      if ( v5 >= v2->numleafbrushes )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( !pTraceInfo->m_trace.startsolid )
    {
      dispCount = v2->dispCount;
      if ( (_WORD)dispCount != 0 )
        CM_TestInDispTree(
          pTraceInfo,
          pDispList: &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v2->dispListStart],
          dispListCount: dispCount,
          traceStart: &pTraceInfo->m_start,
          boxMin: &pTraceInfo->m_mins,
          boxMax: &pTraceInfo->m_maxs,
          collisionMask: pTraceInfo->m_contents,
          pTrace: &pTraceInfo->m_trace);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E8B0
// Name: CM_UnsweptBoxTrace
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_UnsweptBoxTrace(TraceInfo_t *pTraceInfo@<esi>, const Ray_t *ray, int headnode)
{
  CCollisionBSPData *m_pBSPData; // edx
  float x; // xmm0_4
  float y; // xmm0_4
  float v6; // xmm0_4
  int v7; // ebx
  int v8; // edi
  int ndxLeaf[1024]; // [esp+0h] [ebp-101Ch] BYREF
  leafnums_t context; // [esp+1000h] [ebp-1Ch] BYREF
  Vector extents; // [esp+1010h] [ebp-Ch] BYREF
  char center_3; // [esp+1027h] [ebp+Bh]

  m_pBSPData = pTraceInfo->m_pBSPData;
  x = ray->m_Extents.x;
  context.pLeafList = ndxLeaf;
  extents.x = x + 1.0;
  y = ray->m_Extents.y;
  context.pBSPData = m_pBSPData;
  extents.y = y + 1.0;
  v6 = ray->m_Extents.z + 1.0;
  context.leafTopNode = -1;
  context.leafMaxCount = 1024;
  center_3 = 0;
  extents.z = v6;
  v7 = CM_BoxLeafnums(&context, center: &ray->m_Start, &extents, nodenum: headnode);
  v8 = 0;
  if ( v7 <= 0 )
    goto LABEL_7;
  do
  {
    if ( (pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf[v8]].contents & 1) == 0 )
      center_3 = 1;
    CM_TestInLeaf(pTraceInfo, ndxLeaf: ndxLeaf[v8]);
    if ( pTraceInfo->m_trace.allsolid )
      break;
    ++v8;
  }
  while ( v8 < v7 );
  if ( center_3 == 0 )
  {
LABEL_7:
    *(_WORD *)&pTraceInfo->m_trace.allsolid = 257;
    pTraceInfo->m_trace.fraction = 0.0;
    pTraceInfo->m_trace.fractionleftsolid = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E9B0
// Name: public: class CGameTrace __near & CGameTrace::operator=(class CGameTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CGameTrace *__thiscall CGameTrace::operator=(CGameTrace *this, const CGameTrace *__that)
{
  CBaseTrace::operator=(this, __that);
  this->fractionleftsolid = __that->fractionleftsolid;
  this->surface = __that->surface;
  this->hitgroup = __that->hitgroup;
  this->physicsbone = __that->physicsbone;
  this->worldSurfaceIndex = __that->worldSurfaceIndex;
  this->m_pEnt = __that->m_pEnt;
  this->hitbox = __that->hitbox;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014EA00
// Name: public: void CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(
        CUtlMemoryFixedGrowable<unsigned short,32,int> *this,
        int nCount)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = this->m_nMallocGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 2 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 2 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (unsigned __int16 *)v5;
      CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x1014EA70
// Name: void CM_DiscardEntityString(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_DiscardEntityString()
{
  g_BSPData.map_entitystring.m_buf.m_Get = 0;
  g_BSPData.map_entitystring.m_buf.m_Put = 0;
  g_BSPData.map_entitystring.m_buf.m_nOffset = 0;
  g_BSPData.map_entitystring.m_buf.m_nMaxPut = 0;
  g_BSPData.map_entitystring.m_buf.m_Error = 0;
  if ( g_BSPData.map_entitystring.m_buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory);
      g_BSPData.map_entitystring.m_buf.m_Memory.m_pMemory = nullptr;
    }
    g_BSPData.map_entitystring.m_buf.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EAC0
// Name: void CM_TraceToLeaf<1>(struct TraceInfo_t restrict __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TraceToLeaf<1>(TraceInfo_t *pTraceInfo, int ndxLeaf, float startFrac, float endFrac)
{
  CCollisionBSPData *m_pBSPData; // eax
  unsigned __int16 *v6; // edx
  int v7; // ecx
  int v8; // edx
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  const cbrush_t *v13; // edx
  int m_contents; // ecx
  int numsides; // edi
  int v16; // ecx
  unsigned __int16 *surfaceIndex; // edx
  int v18; // eax
  csurface_t *v19; // eax
  int v20; // ecx
  int v21; // eax
  csurface_t *v22; // eax
  unsigned __int16 *v23; // ecx
  int v24; // eax
  unsigned int *v25; // edx
  int v26; // eax
  int v27; // edi
  alignedbbox_t *v28; // ecx
  const unsigned __int16 **v29; // eax
  unsigned __int16 *v30; // [esp+8h] [ebp-24h]
  unsigned __int16 *v31; // [esp+8h] [ebp-24h]
  int v32; // [esp+Ch] [ebp-20h]
  unsigned int *v33; // [esp+Ch] [ebp-20h]
  unsigned __int16 *pDispList; // [esp+10h] [ebp-1Ch]
  unsigned int v35; // [esp+14h] [ebp-18h]
  CRangeValidatedArray<cbrush_t> *p_map_brushes; // [esp+18h] [ebp-14h]
  int v37; // [esp+1Ch] [ebp-10h]
  unsigned int *v38; // [esp+20h] [ebp-Ch]
  const unsigned __int16 *pBrushList; // [esp+24h] [ebp-8h]
  const unsigned __int16 *pBrushLista; // [esp+24h] [ebp-8h]
  const cbrush_t *v41; // [esp+28h] [ebp-4h]
  unsigned __int16 *p_surfaceIndex; // [esp+28h] [ebp-4h]
  int v43; // [esp+28h] [ebp-4h]

  m_pBSPData = pTraceInfo->m_pBSPData;
  v6 = (unsigned __int16 *)&m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v7 = v6[5];
  v30 = v6;
  if ( (_WORD)v7 == 0 )
    goto LABEL_28;
  v8 = (int)&m_pBSPData->map_leafbrushes.m_pArray[v6[4]];
  p_map_brushes = &m_pBSPData->map_brushes;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v37 = v8;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v35 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = nullptr;
  v32 = v7;
  v38 = m_pMemory;
  pBrushList = nullptr;
  while ( 1 )
  {
    v12 = *(unsigned __int16 *)(v37 + 2 * (_DWORD)v11);
    v13 = &p_map_brushes->m_pArray[v12];
    v41 = v13;
    if ( m_pMemory[v12] == v35 )
      goto LABEL_25;
    m_pMemory[v12] = v35;
    m_contents = pTraceInfo->m_contents;
    if ( (v13->contents & m_contents) == 0 )
      goto LABEL_25;
    if ( (v13->contents & pTraceInfo->m_contents) != 128 || (m_contents & 0x2000) == 0 )
      goto LABEL_24;
    numsides = v13->numsides;
    if ( (_WORD)numsides == 0xFFFF )
    {
      v16 = 0;
      surfaceIndex = pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v18 = *surfaceIndex;
        v19 = (_WORD)v18 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v18];
        if ( SLOBYTE(v19->flags) < 0 )
          goto LABEL_25;
        ++v16;
        ++surfaceIndex;
        if ( v16 >= 6 )
        {
          v13 = v41;
          goto LABEL_24;
        }
      }
    }
    v20 = 0;
    if ( v13->numsides != 0 )
    {
      p_surfaceIndex = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v21 = *p_surfaceIndex;
        v22 = (_WORD)v21 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v21];
        if ( SLOBYTE(v22->flags) < 0 )
          break;
        p_surfaceIndex += 4;
        if ( ++v20 >= numsides )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      CM_ClipBoxToBrush<1>(pTraceInfo, brush: v13);
      if ( pTraceInfo->m_trace.fraction == 0.0 )
        break;
    }
LABEL_25:
    v11 = (const unsigned __int16 *)((char *)pBrushList + 1);
    pBrushList = v11;
    if ( (int)v11 >= v32 )
      break;
    m_pMemory = v38;
  }
  if ( pTraceInfo->m_trace.startsolid )
    return;
  v6 = v30;
LABEL_28:
  if ( v6[7] == 0 )
    return;
  v31 = &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v6[6]];
  v23 = (unsigned __int16 *)v6[7];
  v24 = pTraceInfo->m_nCheckDepth;
  v25 = pTraceInfo->m_DispCounters[v24].m_Memory.m_pMemory;
  pBrushLista = (const unsigned __int16 *)pTraceInfo->m_Count[v24];
  v26 = 0;
  pDispList = v23;
  v33 = v25;
  v43 = 0;
  while ( 2 )
  {
    v27 = v31[v26];
    v28 = &g_pDispBounds[v27];
    if ( (v28->dispContents & pTraceInfo->m_contents) == 0 )
      goto LABEL_36;
    if ( pTraceInfo->m_isswept )
    {
      v29 = (const unsigned __int16 **)&v33[v28->dispCounter];
      if ( *v29 != pBrushLista )
      {
        *v29 = pBrushLista;
        break;
      }
LABEL_36:
      v26 = v43 + 1;
      v43 = v26;
      if ( v26 >= (int)pDispList )
        goto LABEL_37;
      continue;
    }
    break;
  }
  if ( !IsBoxIntersectingRay(
          boxMin: &v28->mins,
          boxMax: &v28->maxs,
          origin: &pTraceInfo->m_start,
          vecDelta: &pTraceInfo->m_delta,
          vecInvDelta: &pTraceInfo->m_invDelta,
          flTolerance: 0.03125) )
    goto LABEL_36;
  CM_TraceToDispTree<1>(pTraceInfo, pDispTree: &g_pDispCollTrees[v27], startFrac, endFrac);
  if ( pTraceInfo->m_trace.fraction != 0.0 )
    goto LABEL_36;
LABEL_37:
  CM_PostTraceToDispTree(pTraceInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1014ED90
// Name: void CM_TraceToLeaf<0>(struct TraceInfo_t restrict __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_TraceToLeaf<0>(TraceInfo_t *pTraceInfo, int ndxLeaf, float startFrac, float endFrac)
{
  CCollisionBSPData *m_pBSPData; // eax
  unsigned __int16 *v6; // edx
  unsigned int *v7; // ecx
  int v8; // edx
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // edi
  const unsigned __int16 *v11; // eax
  int v12; // eax
  const cbrush_t *v13; // edx
  int m_contents; // ecx
  unsigned __int16 *numsides; // edi
  int v16; // ecx
  unsigned __int16 *surfaceIndex; // edx
  int v18; // eax
  csurface_t *v19; // eax
  int v20; // ecx
  int plane_low; // eax
  csurface_t *v22; // eax
  unsigned __int16 *v23; // eax
  unsigned __int16 *v24; // ecx
  int v25; // eax
  unsigned int *v26; // edx
  int v27; // eax
  int v28; // edi
  alignedbbox_t *v29; // eax
  const unsigned __int16 **v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  Vector boxMin; // [esp+8h] [ebp-3Ch] BYREF
  Vector boxMax; // [esp+14h] [ebp-30h] BYREF
  unsigned __int16 *v38; // [esp+20h] [ebp-24h]
  unsigned int *v39; // [esp+24h] [ebp-20h]
  unsigned __int16 *pDispList; // [esp+28h] [ebp-1Ch]
  unsigned int v41; // [esp+2Ch] [ebp-18h]
  CRangeValidatedArray<cbrush_t> *p_map_brushes; // [esp+30h] [ebp-14h]
  int v43; // [esp+34h] [ebp-10h]
  unsigned int *v44; // [esp+38h] [ebp-Ch]
  const unsigned __int16 *pBrushList; // [esp+3Ch] [ebp-8h]
  cbrushside_t *v46; // [esp+40h] [ebp-4h]

  m_pBSPData = pTraceInfo->m_pBSPData;
  v6 = (unsigned __int16 *)&m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v7 = (unsigned int *)v6[5];
  v38 = v6;
  if ( (_WORD)v7 == 0 )
    goto LABEL_28;
  v8 = (int)&m_pBSPData->map_leafbrushes.m_pArray[v6[4]];
  p_map_brushes = &m_pBSPData->map_brushes;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  v43 = v8;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v41 = pTraceInfo->m_Count[m_nCheckDepth];
  v11 = nullptr;
  v39 = v7;
  v44 = m_pMemory;
  pBrushList = nullptr;
  while ( 1 )
  {
    v12 = *(unsigned __int16 *)(v43 + 2 * (_DWORD)v11);
    v13 = &p_map_brushes->m_pArray[v12];
    v46 = (cbrushside_t *)v13;
    if ( m_pMemory[v12] == v41 )
      goto LABEL_25;
    m_pMemory[v12] = v41;
    m_contents = pTraceInfo->m_contents;
    if ( (v13->contents & m_contents) == 0 )
      goto LABEL_25;
    if ( (v13->contents & pTraceInfo->m_contents) != 128 || (m_contents & 0x2000) == 0 )
      goto LABEL_24;
    numsides = (unsigned __int16 *)v13->numsides;
    if ( (_WORD)numsides == 0xFFFF )
    {
      v16 = 0;
      surfaceIndex = pTraceInfo->m_pBSPData->map_boxbrushes.m_pArray[v13->firstbrushside].surfaceIndex;
      while ( 1 )
      {
        v18 = *surfaceIndex;
        v19 = (_WORD)v18 == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[v18];
        if ( SLOBYTE(v19->flags) < 0 )
          goto LABEL_25;
        ++v16;
        ++surfaceIndex;
        if ( v16 >= 6 )
        {
          v13 = (const cbrush_t *)v46;
          goto LABEL_24;
        }
      }
    }
    v46 = &pTraceInfo->m_pBSPData->map_brushsides.m_pArray[v13->firstbrushside];
    v20 = 0;
    pDispList = numsides;
    if ( (int)numsides > 0 )
    {
      v46 = (cbrushside_t *)((char *)v46 + 4);
      while ( 1 )
      {
        plane_low = LOWORD(v46->plane);
        v22 = (_WORD)plane_low == 0xFFFF
            ? &CCollisionBSPData::nullsurface
            : &pTraceInfo->m_pBSPData->map_surfaces.m_pArray[plane_low];
        if ( SLOBYTE(v22->flags) < 0 )
          break;
        ++v46;
        if ( ++v20 >= (int)pDispList )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      CM_ClipBoxToBrush<0>(pTraceInfo, brush: v13);
      if ( pTraceInfo->m_trace.fraction == 0.0 )
        break;
    }
LABEL_25:
    v11 = (const unsigned __int16 *)((char *)pBrushList + 1);
    pBrushList = v11;
    if ( (int)v11 >= (int)v39 )
      break;
    m_pMemory = v44;
  }
  if ( pTraceInfo->m_trace.startsolid )
    return;
  v6 = v38;
LABEL_28:
  v23 = (unsigned __int16 *)v6[7];
  if ( (_WORD)v23 == 0 )
    return;
  v38 = &pTraceInfo->m_pBSPData->map_dispList.m_pArray[v6[6]];
  v24 = v23;
  v25 = pTraceInfo->m_nCheckDepth;
  v26 = pTraceInfo->m_DispCounters[v25].m_Memory.m_pMemory;
  pBrushList = (const unsigned __int16 *)pTraceInfo->m_Count[v25];
  v27 = 0;
  pDispList = v24;
  v39 = v26;
  v46 = nullptr;
  while ( 2 )
  {
    v28 = v38[v27];
    v29 = &g_pDispBounds[v28];
    if ( (v29->dispContents & pTraceInfo->m_contents) == 0 )
      goto LABEL_36;
    if ( pTraceInfo->m_isswept )
    {
      v30 = (const unsigned __int16 **)&v39[v29->dispCounter];
      if ( *v30 != pBrushList )
      {
        *v30 = pBrushList;
        break;
      }
LABEL_36:
      v27 = (int)&v46->plane + 1;
      v46 = (cbrushside_t *)v27;
      if ( v27 >= (int)pDispList )
        goto LABEL_37;
      continue;
    }
    break;
  }
  v31 = v29->mins.y - pTraceInfo->m_extents.y;
  v32 = pTraceInfo->m_extents.x + v29->maxs.x;
  v33 = v29->maxs.y + pTraceInfo->m_extents.y;
  boxMax.z = v29->maxs.z + pTraceInfo->m_extents.z;
  v34 = v29->mins.x - pTraceInfo->m_extents.x;
  boxMin.y = v31;
  v35 = v29->mins.z - pTraceInfo->m_extents.z;
  boxMax.x = v32;
  boxMax.y = v33;
  boxMin.x = v34;
  boxMin.z = v35;
  if ( !IsBoxIntersectingRay(
          &boxMin,
          &boxMax,
          origin: &pTraceInfo->m_start,
          vecDelta: &pTraceInfo->m_delta,
          vecInvDelta: &pTraceInfo->m_invDelta,
          flTolerance: 0.03125) )
    goto LABEL_36;
  CM_TraceToDispTree<0>(pTraceInfo, pDispTree: &g_pDispCollTrees[v28], startFrac, endFrac);
  if ( pTraceInfo->m_trace.fraction != 0.0 )
    goto LABEL_36;
LABEL_37:
  CM_PostTraceToDispTree(pTraceInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1014F0C0
// Name: public: TraceInfo_t::~TraceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TraceInfo_t::~TraceInfo_t(TraceInfo_t *this)
{
  TraceInfo_t *v2; // esi
  float x; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_DispCounters; // esi
  int j; // ebx
  unsigned int *m_pMemory; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = this + 1;
  for ( i = 1; i >= 0; --i )
  {
    v2 = (TraceInfo_t *)((char *)v2 - 20);
    v2->m_end.x = 0.0;
    if ( v2->m_start.z >= 0.0 )
    {
      if ( LODWORD(v2->m_start.x) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v2->m_start.x));
        v2->m_start.x = 0.0;
      }
      v2->m_start.y = 0.0;
    }
    x = v2->m_start.x;
    v2->m_end.y = v2->m_start.x;
    if ( v2->m_start.z >= 0.0 )
    {
      if ( x != 0.0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(x));
        v2->m_start.x = 0.0;
      }
      v2->m_start.y = 0.0;
    }
  }
  m_DispCounters = this->m_DispCounters;
  for ( j = 1; j >= 0; --j )
  {
    --m_DispCounters;
    m_DispCounters->m_Size = 0;
    if ( m_DispCounters->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_DispCounters->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_DispCounters->m_Memory.m_pMemory);
        m_DispCounters->m_Memory.m_pMemory = nullptr;
      }
      m_DispCounters->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = m_DispCounters->m_Memory.m_pMemory;
    m_DispCounters->m_pElements = m_DispCounters->m_Memory.m_pMemory;
    if ( m_DispCounters->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_DispCounters->m_Memory.m_pMemory = nullptr;
      }
      m_DispCounters->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014F1A0
// Name: CM_RecursiveHullCheckImpl_1_
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_RecursiveHullCheckImpl_1_(
        TraceInfo_t *pTraceInfo,
        int num,
        float p1f,
        float p2f,
        const Vector *p1,
        const Vector *p2)
{
  bool v6; // cf
  int v7; // ebx
  cnode_t *v10; // edx
  float *p_x; // eax
  unsigned __int8 type; // cl
  float dist; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int v20; // ebx
  double v21; // st6
  double v22; // st7
  float v23; // xmm0_4
  float v24; // xmm0_4
  Vector p2a; // [esp+0h] [ebp-1Ch] BYREF
  cnode_t *endFrac; // [esp+Ch] [ebp-10h]
  cnode_t *map_rootnode; // [esp+10h] [ebp-Ch]
  float v28; // [esp+14h] [ebp-8h]
  TraceInfo_t *v29; // [esp+18h] [ebp-4h]
  float p1a; // [esp+2Ch] [ebp+10h]
  float offset; // [esp+30h] [ebp+14h]

  v6 = p1f < pTraceInfo->m_trace.fraction;
  v7 = num;
  v29 = pTraceInfo;
  if ( !v6 )
    return;
  if ( num < 0 )
  {
LABEL_17:
    CM_TraceToLeaf<1>(pTraceInfo, ndxLeaf: -1 - v7, startFrac: p1f, endFrac: p2f);
    return;
  }
  map_rootnode = pTraceInfo->m_pBSPData->map_rootnode;
  while ( 1 )
  {
    v10 = &map_rootnode[v7];
    p_x = &v10->plane->normal.x;
    type = v10->plane->type;
    dist = v10->plane->dist;
    endFrac = v10;
    if ( type >= 3u )
    {
      v14 = (float)((float)(p1->y * p_x[1]) + (float)(*p_x * p1->x)) + (float)(p1->z * p_x[2]);
      v15 = (float)((float)(p2->y * p_x[1]) + (float)(*p_x * p2->x)) + (float)(p2->z * p_x[2]);
      v16 = 0.0;
    }
    else
    {
      v14 = *(&p1->x + type);
      v15 = *(&p2->x + type);
      v16 = *(&v29->m_extents.x + type);
    }
    v17 = v14 - dist;
    v18 = v15 - dist;
    v28 = v16;
    if ( v17 <= v16 || v18 <= v16 )
      break;
    v7 = v10->children[0];
LABEL_13:
    if ( v7 < 0 )
      goto LABEL_16;
  }
  v19 = -v16;
  if ( v19 > v17 && v19 > v18 )
  {
    v7 = v10->children[1];
    goto LABEL_13;
  }
  if ( v7 < 0 )
  {
LABEL_16:
    pTraceInfo = v29;
    goto LABEL_17;
  }
  if ( v18 > v17 )
  {
    v20 = 1;
    v21 = 1.0 / (v17 - v18);
    offset = (v28 + v17 + 0.03125) * v21;
    v22 = v17 - v28 - 0.03125;
    goto LABEL_20;
  }
  v20 = 0;
  if ( v17 <= v18 )
  {
    offset = 0.0;
    goto LABEL_26;
  }
  v21 = 1.0 / (v17 - v18);
  offset = (v17 - v28 - 0.03125) * v21;
  v22 = v17 + v28 + 0.03125;
LABEL_20:
  p1a = v22 * v21;
  v23 = p1a;
  if ( p1a < 0.0 )
  {
    v23 = 0.0;
    goto LABEL_27;
  }
  if ( p1a > 1.0 )
LABEL_26:
    v23 = 1.0;
LABEL_27:
  p2a.x = (float)((float)(p2->x - p1->x) * v23) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v23) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v23) + p1->z;
  CM_RecursiveHullCheckImpl_1_(
    pTraceInfo: v29,
    num: v10->children[v20],
    p1f,
    p2f: (float)((float)(p2f - p1f) * v23) + p1f,
    p1,
    p2: &p2a);
  v24 = 0.0;
  if ( offset >= 0.0 )
  {
    v24 = 1.0;
    if ( offset <= 1.0 )
      v24 = offset;
  }
  p2a.x = (float)((float)(p2->x - p1->x) * v24) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v24) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v24) + p1->z;
  CM_RecursiveHullCheckImpl_1_(
    pTraceInfo: v29,
    num: endFrac->children[v20 ^ 1],
    p1f: (float)((float)(p2f - p1f) * v24) + p1f,
    p2f,
    p1: &p2a,
    p2);
}

//------------------------------------------------------------------------------
// Address: 0x1014F480
// Name: CM_RecursiveHullCheckImpl_0_
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __fastcall CM_RecursiveHullCheckImpl_0_(
        TraceInfo_t *pTraceInfo,
        int num,
        float p1f,
        float p2f,
        const Vector *p1,
        const Vector *p2)
{
  bool v7; // cf
  cnode_t *v10; // edx
  float *p_x; // eax
  unsigned __int8 type; // cl
  float dist; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  long double v17; // st7
  double x; // st7
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  long double v23; // st5
  long double v24; // rt2
  long double v25; // st5
  long double v26; // st7
  long double v27; // st6
  float v28; // xmm0_4
  long double v29; // st5
  float v30; // xmm2_4
  float v31; // xmm0_4
  Vector p2a; // [esp+0h] [ebp-20h] BYREF
  cnode_t *endFrac; // [esp+Ch] [ebp-14h]
  float v34; // [esp+10h] [ebp-10h]
  cnode_t *map_rootnode; // [esp+14h] [ebp-Ch]
  float v36; // [esp+18h] [ebp-8h]
  int mid; // [esp+1Ch] [ebp-4h] OVERLAPPED
  float p1a; // [esp+30h] [ebp+10h]
  float t2a; // [esp+34h] [ebp+14h]
  int t2; // [esp+34h] [ebp+14h]

  v7 = p1f < pTraceInfo->m_trace.fraction;
  mid = num;
  if ( !v7 )
    return;
  if ( num < 0 )
    goto LABEL_16;
  map_rootnode = pTraceInfo->m_pBSPData->map_rootnode;
  while ( 1 )
  {
    v10 = &map_rootnode[mid];
    p_x = &v10->plane->normal.x;
    type = v10->plane->type;
    dist = v10->plane->dist;
    endFrac = v10;
    if ( type >= 3u )
    {
      x = pTraceInfo->m_extents.x;
      v19 = p1->y * p_x[1];
      v34 = *p_x;
      v15 = (float)(v19 + (float)(v34 * p1->x)) + (float)(p1->z * p_x[2]);
      v16 = (float)((float)(p2->y * p_x[1]) + (float)(v34 * p2->x)) + (float)(p2->z * p_x[2]);
      v17 = fabs(x * v34) + fabs(pTraceInfo->m_extents.y * p_x[1]) + fabs(pTraceInfo->m_extents.z * p_x[2]);
      t2a = v17;
      v14 = t2a;
    }
    else
    {
      v14 = *(&pTraceInfo->m_extents.x + type);
      v15 = *(&p1->x + type);
      v16 = *(&p2->x + type);
      v17 = v14;
    }
    v20 = v15 - dist;
    v21 = v16 - dist;
    v36 = v21;
    if ( v20 <= v14 || v21 <= v14 )
      break;
    mid = v10->children[0];
LABEL_13:
    if ( mid < 0 )
      goto LABEL_16;
  }
  v22 = -v14;
  if ( v22 > v20 && v22 > v21 )
  {
    mid = v10->children[1];
    goto LABEL_13;
  }
  if ( mid < 0 )
  {
LABEL_16:
    CM_TraceToLeaf<0>(pTraceInfo, ndxLeaf: -1 - mid, startFrac: p1f, endFrac: p2f);
    return;
  }
  if ( v21 > v20 )
  {
    t2 = 1;
    v23 = 1.0 / (v20 - v36);
    p1a = (v17 + v20 + 0.03125) * v23;
    v24 = v23;
    v25 = v20 - v17;
    v26 = v24;
    v27 = v25 - 0.03125;
    goto LABEL_19;
  }
  t2 = 0;
  if ( v20 <= v21 )
  {
    p1a = 0.0;
    goto LABEL_25;
  }
  v29 = 1.0 / (v20 - v36);
  p1a = (v20 - v17 - 0.03125) * v29;
  v27 = v29;
  v26 = v20 + v17 + 0.03125;
LABEL_19:
  v36 = v26 * v27;
  v28 = v36;
  if ( v36 < 0.0 )
  {
    v28 = 0.0;
    goto LABEL_26;
  }
  if ( v36 > 1.0 )
LABEL_25:
    v28 = 1.0;
LABEL_26:
  p2a.x = (float)((float)(p2->x - p1->x) * v28) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v28) + p1->y;
  v30 = (float)((float)(p2->z - p1->z) * v28) + p1->z;
  v34 = p2f - p1f;
  p2a.z = v30;
  CM_RecursiveHullCheckImpl_0_(
    pTraceInfo,
    num: v10->children[t2],
    p1f,
    p2f: (float)((float)(p2f - p1f) * v28) + p1f,
    p1,
    p2: &p2a);
  v31 = 0.0;
  if ( p1a >= 0.0 )
  {
    v31 = 1.0;
    if ( p1a <= 1.0 )
      v31 = p1a;
  }
  p2a.x = (float)((float)(p2->x - p1->x) * v31) + p1->x;
  p2a.y = (float)((float)(p2->y - p1->y) * v31) + p1->y;
  p2a.z = (float)((float)(p2->z - p1->z) * v31) + p1->z;
  CM_RecursiveHullCheckImpl_0_(
    pTraceInfo,
    num: endFrac->children[t2 ^ 1],
    p1f: (float)(v34 * v31) + p1f,
    p2f,
    p1: &p2a,
    p2);
}

//------------------------------------------------------------------------------
// Address: 0x1014F810
// Name: public: TraceInfo_t::TraceInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
TraceInfo_t *__thiscall TraceInfo_t::TraceInfo_t(TraceInfo_t *this)
{
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_BrushCounters; // eax
  int i; // edx
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *m_DispCounters; // eax
  int j; // edx

  m_BrushCounters = this->m_BrushCounters;
  for ( i = 1; i >= 0; --i )
  {
    m_BrushCounters->m_Memory.m_pMemory = nullptr;
    m_BrushCounters->m_Memory.m_nAllocationCount = 0;
    m_BrushCounters->m_Memory.m_nGrowSize = 0;
    m_BrushCounters->m_Size = 0;
    m_BrushCounters->m_pElements = nullptr;
    ++m_BrushCounters;
  }
  m_DispCounters = this->m_DispCounters;
  for ( j = 1; j >= 0; --j )
  {
    m_DispCounters->m_Memory.m_pMemory = nullptr;
    m_DispCounters->m_Memory.m_nAllocationCount = 0;
    m_DispCounters->m_Memory.m_nGrowSize = 0;
    m_DispCounters->m_Size = 0;
    m_DispCounters->m_pElements = nullptr;
    ++m_DispCounters;
  }
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x128u);
  this->m_nCheckDepth = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014F880
// Name: void CM_RecursiveHullCheck(struct TraceInfo_t __near *,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_RecursiveHullCheck(TraceInfo_t *pTraceInfo, int num, float p1f, float p2f)
{
  Vector *p_m_end; // [esp-4h] [ebp-4h]

  p_m_end = &pTraceInfo->m_end;
  if ( pTraceInfo->m_ispoint )
    CM_RecursiveHullCheckImpl_1_(pTraceInfo, num, p1f, p2f, p1: &pTraceInfo->m_start, p2: p_m_end);
  else
    CM_RecursiveHullCheckImpl_0_(pTraceInfo, num, p1f, p2f, p1: &pTraceInfo->m_start, p2: p_m_end);
}

//------------------------------------------------------------------------------
// Address: 0x1014F8C0
// Name: void CM_GetTraceDataForLeaf(struct TraceInfo_t restrict __near *,int,class CTraceListData __near &)
// Source: json
//------------------------------------------------------------------------------
void __fastcall CM_GetTraceDataForLeaf(TraceInfo_t *pTraceInfo, int ndxLeaf, CTraceListData *traceData)
{
  TraceInfo_t *v3; // ebx
  cleaf_t *v4; // edx
  bool v5; // zf
  unsigned int firstleafbrush; // esi
  int m_nCheckDepth; // eax
  unsigned int *m_pMemory; // ecx
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  cleaf_t *v12; // esi
  int v13; // ecx
  CCollisionBSPData *dispCount; // eax
  unsigned int v15; // ecx
  int v16; // ebx
  alignedbbox_t *v17; // eax
  int dispCounter; // ecx
  unsigned int *v19; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *v22; // ecx
  int v23; // eax
  unsigned __int16 *v24; // edi
  cleaf_t *pLeaf; // [esp+10h] [ebp-14h]
  cleaf_t *pLeafa; // [esp+10h] [ebp-14h]
  unsigned int *pCounters; // [esp+14h] [ebp-10h]
  unsigned int *pCountersa; // [esp+14h] [ebp-10h]
  unsigned __int16 src[2]; // [esp+18h] [ebp-Ch] BYREF
  CCollisionBSPData *m_pBSPData; // [esp+1Ch] [ebp-8h]
  unsigned int count; // [esp+20h] [ebp-4h]

  v3 = pTraceInfo;
  v4 = &pTraceInfo->m_pBSPData->map_leafs.m_pArray[ndxLeaf];
  v5 = (v4->contents & 1) == 0;
  m_pBSPData = pTraceInfo->m_pBSPData;
  pLeaf = v4;
  if ( v5 )
    traceData->m_bFoundNonSolidLeaf = true;
  firstleafbrush = v4->firstleafbrush;
  m_nCheckDepth = pTraceInfo->m_nCheckDepth;
  m_pMemory = pTraceInfo->m_BrushCounters[m_nCheckDepth].m_Memory.m_pMemory;
  v9 = firstleafbrush + v4->numleafbrushes;
  pCounters = m_pMemory;
  count = v3->m_Count[m_nCheckDepth];
  if ( firstleafbrush < v9 )
  {
    do
    {
      v10 = m_pBSPData->map_leafbrushes.m_pArray[firstleafbrush];
      if ( m_pMemory[v10] != count )
      {
        m_pMemory[v10] = count;
        *(_DWORD *)src = v10;
        CUtlVector<unsigned short,CUtlMemoryFixedGrowable<unsigned short,64,int>>::InsertBefore(
          this: &traceData->m_brushList,
          elem: traceData->m_brushList.m_Size,
          src);
        m_pMemory = pCounters;
      }
      ++firstleafbrush;
    }
    while ( (int)firstleafbrush < (int)v9 );
    v4 = pLeaf;
  }
  v11 = v3->m_nCheckDepth;
  v12 = (cleaf_t *)v3->m_Count[v11];
  v13 = v11;
  dispCount = (CCollisionBSPData *)v4->dispCount;
  pCountersa = v3->m_DispCounters[v13].m_Memory.m_pMemory;
  pLeafa = v12;
  if ( v4->dispCount != 0 )
  {
    v15 = 2 * v4->dispListStart;
    count = v15;
    m_pBSPData = dispCount;
    while ( 1 )
    {
      v16 = *(unsigned __int16 *)((char *)v3->m_pBSPData->map_dispList.m_pArray + v15);
      v17 = &g_pDispBounds[v16];
      dispCounter = v17->dispCounter;
      v5 = pCountersa[dispCounter] == (_DWORD)v12;
      v19 = &pCountersa[dispCounter];
      if ( !v5 )
      {
        *v19 = (unsigned int)v12;
        if ( IsBoxIntersectingBox(
               boxMin1: &v17->mins,
               boxMax1: &v17->maxs,
               boxMin2: &traceData->m_mins,
               boxMax2: &traceData->m_maxs) )
        {
          m_Size = traceData->m_dispList.m_Size;
          m_nAllocationCount = traceData->m_dispList.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemoryFixedGrowable<unsigned short,64,int>::Grow(
              this: &traceData->m_dispList.m_Memory,
              nCount: m_Size - m_nAllocationCount + 1);
          ++traceData->m_dispList.m_Size;
          v22 = traceData->m_dispList.m_Memory.m_pMemory;
          v23 = traceData->m_dispList.m_Size - m_Size - 1;
          traceData->m_dispList.m_pElements = v22;
          if ( v23 > 0 )
            _V_memmove(dest: &v22[m_Size + 1], src: &v22[m_Size], count: 2 * v23);
          v24 = &traceData->m_dispList.m_Memory.m_pMemory[m_Size];
          if ( v24 != nullptr )
            *v24 = v16;
        }
      }
      v15 = count + 2;
      v5 = m_pBSPData == (CCollisionBSPData *)1;
      m_pBSPData = (CCollisionBSPData *)((char *)m_pBSPData - 1);
      count += 2;
      if ( v5 )
        break;
      v3 = pTraceInfo;
      v12 = pLeafa;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014FA80
// Name: struct TraceInfo_t __near * BeginTrace(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t **__cdecl BeginTrace()
{
  TSLNodeBase_t *v0; // eax
  char *v1; // eax
  TSLNodeBase_t *v2; // esi
  TSLNodeBase_t **v3; // ebx
  TSLNodeBase_t *v4; // esi
  bool v5; // zf
  int v6; // edi
  TSLNodeBase_t *Next; // eax
  char *v8; // ecx
  int v9; // eax
  int v10; // edi
  TSLNodeBase_t *v11; // eax
  char *v12; // ecx
  int v13; // eax
  TSLNodeBase_t *v14; // eax
  TSLNodeBase_t **v15; // esi
  int i; // [esp+8h] [ebp-4h]

  v0 = CTSListBase::Pop(this: &g_TraceInfoPool);
  if ( v0 == nullptr )
  {
    v1 = (char *)MemAlloc_Alloc(nSize: 0x180u);
    v2 = (TSLNodeBase_t *)v1;
    if ( v1 != nullptr )
    {
      TraceInfo_t::TraceInfo_t(this: (TraceInfo_t *)(v1 + 4));
      v0 = v2;
    }
    else
    {
      v0 = nullptr;
    }
  }
  v3 = &v0->Next + 1;
  v4 = v0 + 39;
  if ( v0[39].Next != (TSLNodeBase_t *)(g_BSPData.numbrushes + 1) )
  {
    *((_DWORD *)&v0[36].Next + 1) = 0;
    v0[37].Next = nullptr;
    v0[36].Next = (TSLNodeBase_t *)-1;
    for ( i = 2; i != 0; --i )
    {
      v6 = g_BSPData.numbrushes + 1;
      v5 = g_BSPData.numbrushes == -1;
      v4->Next = nullptr;
      if ( !v5 )
      {
        Next = v4[-1].Next;
        if ( v6 > (int)Next )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)(&v4[-2].Next + 1),
            num: v6 - (_DWORD)Next);
        v4->Next = (TSLNodeBase_t *)((char *)v4->Next + v6);
        v8 = *((char **)&v4[-2].Next + 1);
        v9 = (int)v4->Next - v6;
        *((_DWORD *)&v4->Next + 1) = v8;
        if ( v9 > 0 && v6 > 0 )
          _V_memmove(dest: &v8[4 * v6], src: v8, count: 4 * v9);
      }
      v10 = g_DispCollTreeCount;
      v4[5].Next = nullptr;
      if ( v10 != 0 )
      {
        v11 = v4[4].Next;
        if ( v10 > (int)v11 )
          CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)(&v4[3].Next + 1), num: v10 - (_DWORD)v11);
        v4[5].Next = (TSLNodeBase_t *)((char *)v4[5].Next + v10);
        v12 = *((char **)&v4[3].Next + 1);
        v13 = (int)v4[5].Next - v10;
        *((_DWORD *)&v4[5].Next + 1) = v12;
        if ( v13 > 0 && v10 > 0 )
          _V_memmove(dest: &v12[4 * v10], src: v12, count: 4 * v13);
      }
      memset(dst: *((unsigned __int8 **)&v4[-2].Next + 1), value: 0, count: 4 * (int)v4->Next);
      memset(dst: *((unsigned __int8 **)&v4[3].Next + 1), value: 0, count: 4 * (int)v4[5].Next);
      v4 = (TSLNodeBase_t *)((char *)v4 + 20);
    }
  }
  v3[71] = (TSLNodeBase_t *)((char *)v3[71] + 1);
  v14 = v3[71];
  v5 = (TSLNodeBase_t **)((char *)&v3[(_DWORD)v14 + 72]->Next + 1) == nullptr;
  v3[(_DWORD)v14 + 72] = (TSLNodeBase_t *)((char *)v3[(_DWORD)v14 + 72] + 1);
  if ( v5 )
  {
    v3[(_DWORD)v14 + 72] = (TSLNodeBase_t *)1;
    v15 = &v3[5 * (_DWORD)v14];
    memset(dst: (unsigned __int8 *)v15[74], value: 0, count: 4 * (_DWORD)v15[77]);
    memset(dst: (unsigned __int8 *)v15[84], value: 0, count: 4 * (_DWORD)v15[87]);
  }
  v3[65] = (TSLNodeBase_t *)&g_BSPData;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1014FC40
// Name: void CM_GetTraceDataForBSP(class Vector const __near &,class Vector const __near &,class CTraceListData __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_GetTraceDataForBSP(const Vector *mins, TraceInfo_t *maxs, CTraceListData *traceData)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int v8; // esi
  int v9; // ebx
  int v10; // edi
  cnode_t *v11; // eax
  cplane_t *plane; // ecx
  float v13; // xmm2_4
  float v14; // xmm0_4
  _DWORD v15[1024]; // [esp+0h] [ebp-1024h]
  float v16; // [esp+1000h] [ebp-24h]
  float v17; // [esp+1004h] [ebp-20h]
  float v18; // [esp+1008h] [ebp-1Ch]
  float v19; // [esp+100Ch] [ebp-18h]
  float v20; // [esp+1010h] [ebp-14h]
  float v21; // [esp+1014h] [ebp-10h]
  float v22; // [esp+1018h] [ebp-Ch]
  float v23; // [esp+101Ch] [ebp-8h]
  float v24; // [esp+1020h] [ebp-4h]
  float v25; // [esp+102Ch] [ebp+8h]
  TraceInfo_t *pTraceInfo; // [esp+1030h] [ebp+Ch]

  x = maxs->m_start.x;
  y = maxs->m_start.y;
  z = maxs->m_start.z;
  v6 = (float)(mins->y + y) * 0.5;
  v7 = (float)(mins->z + z) * 0.5;
  v21 = (float)(mins->x + maxs->m_start.x) * 0.5;
  v22 = v6;
  v23 = v7;
  v17 = x - v21;
  v18 = y - v6;
  v19 = z - v7;
  v8 = 0;
  v9 = 0;
  pTraceInfo = (TraceInfo_t *)BeginTrace();
  v10 = 0;
  while ( 1 )
  {
    while ( v8 >= 0 )
    {
      v11 = &g_BSPData.map_rootnode[v8];
      plane = v11->plane;
      v13 = v11->plane->normal.z;
      v25 = v11->plane->normal.y;
      v16 = v11->plane->normal.x;
      v20 = v13;
      v14 = (float)((float)((float)(v25 * v22) + (float)(v16 * v21)) + (float)(v13 * v23)) - plane->dist;
      v24 = fabs(v25 * v18) + fabs(v16 * v17) + fabs(v13 * v19);
      if ( v14 < v24 )
      {
        v8 = v11->children[1];
        if ( COERCE_FLOAT(LODWORD(v24) ^ _mask__NegFloat_) <= v14 )
        {
          v15[v10] = v11->children[0];
          v10 = ((_WORD)v10 + 1) & 0x3FF;
        }
      }
      else
      {
        v8 = v11->children[0];
      }
    }
    CM_GetTraceDataForLeaf(pTraceInfo, ndxLeaf: -1 - v8, traceData);
    if ( v9 == v10 )
      break;
    v8 = v15[v9];
    v9 = ((_WORD)v9 + 1) & 0x3FF;
  }
  --pTraceInfo->m_nCheckDepth;
  CTSListBase::Push(this: &g_TraceInfoPool, pNode: (TSLNodeBase_t *)&pTraceInfo[-1].m_DispCounters[1].m_pElements);
}

//------------------------------------------------------------------------------
// Address: 0x1014FDC0
// Name: void CM_BoxTraceAgainstLeafList(struct Ray_t const __near &,class CTraceListData const __near &,int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_BoxTraceAgainstLeafList(
        const Ray_t *ray,
        const CTraceListData *traceData,
        const Ray_t *nBrushMask,
        CGameTrace *trace)
{
  TSLNodeBase_t **v4; // esi
  float v5; // xmm0_4
  float x; // xmm1_4
  float v7; // xmm3_4
  const Ray_t *v8; // edi
  float y; // xmm2_4
  float v10; // xmm1_4
  float z; // xmm2_4
  const cbrush_t *v12; // edx
  int m_Size; // ecx
  unsigned __int16 *m_pMemory; // edx
  TSLNodeBase_t *v15; // eax
  bool v16; // zf
  int v17; // ecx
  TSLNodeBase_t *Next; // edx
  TSLNodeBase_t *v19; // eax
  const cbrush_t *v20; // edx
  unsigned int v21; // ecx
  int v22; // eax
  int numsides; // edi
  int v24; // ecx
  TSLNodeBase_t *v25; // edx
  int Next_low; // eax
  csurface_t *v27; // eax
  int v28; // ecx
  int x_low; // eax
  csurface_t *v30; // eax
  int v31; // edx
  int v32; // eax
  const cbrush_t *v33; // edx
  unsigned int v34; // ecx
  int v35; // eax
  int v36; // edi
  int v37; // ecx
  TSLNodeBase_t *v38; // edx
  int v39; // eax
  csurface_t *v40; // eax
  int v41; // ecx
  int v42; // eax
  csurface_t *v43; // eax
  int v44; // eax
  int v45; // edi
  alignedbbox_t *v46; // ecx
  int v47; // edi
  alignedbbox_t *v48; // eax
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  float *v53; // ecx
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  TSLNodeBase_t **v57; // esi
  int v58; // [esp-Ch] [ebp-40h]
  int v59; // [esp-Ch] [ebp-40h]
  TSLHead_t m_Head; // [esp-8h] [ebp-3Ch]
  TSLHead_t v61; // [esp-8h] [ebp-3Ch]
  Vector boxMin; // [esp+8h] [ebp-2Ch] BYREF
  Vector boxMax; // [esp+14h] [ebp-20h] BYREF
  unsigned __int16 *v64; // [esp+20h] [ebp-14h]
  int v65; // [esp+24h] [ebp-10h]
  unsigned __int16 *v66; // [esp+28h] [ebp-Ch]
  TSLNodeBase_t *v67; // [esp+2Ch] [ebp-8h]
  int v68; // [esp+30h] [ebp-4h]
  int raya; // [esp+44h] [ebp+10h]
  const Ray_t *rayb; // [esp+44h] [ebp+10h]
  const Ray_t *rayc; // [esp+44h] [ebp+10h]
  const Ray_t *rayd; // [esp+44h] [ebp+10h]
  const Ray_t *raye; // [esp+44h] [ebp+10h]
  const Ray_t *rayf; // [esp+44h] [ebp+10h]
  const Ray_t *rayg; // [esp+44h] [ebp+10h]
  const Ray_t *rayh; // [esp+44h] [ebp+10h]

  v4 = BeginTrace();
  memset(dst: (unsigned __int8 *)v4 + 84, value: 0, count: 0x54u);
  v4[35] = nullptr;
  v4[32] = (TSLNodeBase_t *)1065353216;
  *((csurface_t *)v4 + 18) = CCollisionBSPData::nullsurface;
  v4[69] = nullptr;
  v4[66] = nullptr;
  v4[67] = nullptr;
  v4[68] = nullptr;
  v4[63] = (TSLNodeBase_t *)nBrushMask;
  *(Vector *)v4 = ray->m_Start.Vector;
  *((float *)v4 + 3) = ray->m_Delta.x + ray->m_Start.x;
  *((float *)v4 + 4) = ray->m_Delta.y + ray->m_Start.y;
  *((float *)v4 + 5) = ray->m_Delta.z + ray->m_Start.z;
  *((float *)v4 + 6) = ray->m_Extents.x * -1.0;
  *((float *)v4 + 7) = ray->m_Extents.y * -1.0;
  *((float *)v4 + 8) = ray->m_Extents.z * -1.0;
  *((Vector *)v4 + 3) = ray->m_Extents.Vector;
  v5 = 3.4028235e38;
  *((Vector *)v4 + 4) = ray->m_Extents.Vector;
  *((Vector *)v4 + 5) = ray->m_Delta.Vector;
  x = ray->m_Delta.x;
  if ( x == 0.0 )
    v7 = 3.4028235e38;
  else
    v7 = 1.0 / x;
  v8 = ray;
  y = ray->m_Delta.y;
  if ( y == 0.0 )
    v10 = 3.4028235e38;
  else
    v10 = 1.0 / y;
  z = ray->m_Delta.z;
  if ( z != 0.0 )
    v5 = 1.0 / z;
  *((float *)v4 + 18) = v7;
  *((float *)v4 + 19) = v10;
  *((float *)v4 + 20) = v5;
  *((_BYTE *)v4 + 256) = ray->m_IsRay;
  *((_BYTE *)v4 + 257) = ray->m_IsSwept;
  if ( ray->m_IsSwept )
  {
    m_Size = traceData->m_brushList.m_Size;
    m_pMemory = traceData->m_brushList.m_Memory.m_pMemory;
    v15 = v4[65] + 21;
    v16 = !ray->m_IsRay;
    v68 = 0;
    if ( !v16 )
    {
      v64 = (unsigned __int16 *)m_Size;
      v66 = m_pMemory;
      v67 = v15;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v17 = v66[v68];
          Next = v15->Next;
          v19 = v15->Next[v17].Next;
          v20 = (const cbrush_t *)&Next[v17];
          v21 = (unsigned int)v4[63];
          v22 = v21 & (unsigned int)v19;
          rayb = (const Ray_t *)v20;
          if ( v22 == 0 )
            goto LABEL_41;
          if ( v22 != 128 || (v21 & 0x2000) == 0 )
            goto LABEL_40;
          numsides = v20->numsides;
          if ( (_WORD)numsides == 0xFFFF )
          {
            v24 = 0;
            v25 = &v4[65][14].Next[6 * v20->firstbrushside + 4];
            while ( 1 )
            {
              Next_low = LOWORD(v25->Next);
              v27 = (_WORD)Next_low == 0xFFFF
                  ? &CCollisionBSPData::nullsurface
                  : (csurface_t *)&v4[65][67].Next[Next_low];
              if ( SLOBYTE(v27->flags) < 0 )
                goto LABEL_41;
              ++v24;
              v25 = (TSLNodeBase_t *)((char *)v25 + 2);
              if ( v24 >= 6 )
              {
                v20 = (const cbrush_t *)rayb;
                goto LABEL_40;
              }
            }
          }
          rayc = (const Ray_t *)&v4[65][13].Next[v20->firstbrushside];
          v28 = 0;
          v65 = v20->numsides;
          if ( numsides > 0 )
          {
            rayd = (const Ray_t *)&rayc->m_Start.y;
            while ( 1 )
            {
              x_low = LOWORD(rayd->m_Start.x);
              v30 = (_WORD)x_low == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[x_low];
              if ( SLOBYTE(v30->flags) < 0 )
                break;
              rayd = (const Ray_t *)((char *)rayd + 8);
              if ( ++v28 >= v65 )
                goto LABEL_40;
            }
          }
          else
          {
LABEL_40:
            CM_ClipBoxToBrush<1>(pTraceInfo: (TraceInfo_t *)v4, brush: v20);
            if ( *((float *)v4 + 32) == 0.0 )
              break;
          }
LABEL_41:
          if ( ++v68 >= (int)v64 )
            break;
          v15 = v67;
        }
      }
LABEL_64:
      if ( *((float *)v4 + 32) > 0.0 && *((_BYTE *)v4 + 139) == 0 )
      {
        v16 = !ray->m_IsRay;
        v44 = traceData->m_dispList.m_Size;
        rayh = nullptr;
        v65 = v44;
        if ( v16 )
        {
          v64 = traceData->m_dispList.m_Memory.m_pMemory;
          if ( v44 > 0 )
          {
            do
            {
              v47 = v64[(_DWORD)rayh];
              v48 = &g_pDispBounds[v47];
              if ( (v48->dispContents & (unsigned int)v4[63]) != 0 )
              {
                boxMax.x = *((float *)v4 + 12) + v48->maxs.x;
                boxMax.y = *((float *)v4 + 13) + v48->maxs.y;
                boxMax.z = *((float *)v4 + 14) + v48->maxs.z;
                boxMin.x = v48->mins.x - *((float *)v4 + 12);
                boxMin.y = v48->mins.y - *((float *)v4 + 13);
                boxMin.z = v48->mins.z - *((float *)v4 + 14);
                if ( IsBoxIntersectingRay(
                       &boxMin,
                       &boxMax,
                       origin: (const Vector *)v4,
                       vecDelta: (const Vector *)v4 + 5,
                       vecInvDelta: (const Vector *)v4 + 6,
                       flTolerance: 0.03125) )
                {
                  CM_TraceToDispTree<0>(
                    pTraceInfo: (TraceInfo_t *)v4,
                    pDispTree: &g_pDispCollTrees[v47],
                    startFrac: 0.0,
                    endFrac: 1.0);
                  if ( *((float *)v4 + 32) == 0.0 )
                    break;
                }
              }
              rayh = (const Ray_t *)((char *)rayh + 1);
            }
            while ( (int)rayh < v65 );
          }
        }
        else
        {
          v64 = traceData->m_dispList.m_Memory.m_pMemory;
          if ( v44 > 0 )
          {
            do
            {
              v45 = v64[(_DWORD)rayh];
              v46 = &g_pDispBounds[v45];
              if ( (v46->dispContents & (unsigned int)v4[63]) != 0
                && IsBoxIntersectingRay(
                     boxMin: &v46->mins,
                     boxMax: &v46->maxs,
                     origin: (const Vector *)v4,
                     vecDelta: (const Vector *)v4 + 5,
                     vecInvDelta: (const Vector *)v4 + 6,
                     flTolerance: 0.03125) )
              {
                CM_TraceToDispTree<1>(
                  pTraceInfo: (TraceInfo_t *)v4,
                  pDispTree: &g_pDispCollTrees[v45],
                  startFrac: 0.0,
                  endFrac: 1.0);
                if ( *((float *)v4 + 32) == 0.0 )
                  break;
              }
              rayh = (const Ray_t *)((char *)rayh + 1);
            }
            while ( (int)rayh < v65 );
          }
        }
        CM_PostTraceToDispTree(pTraceInfo: (TraceInfo_t *)v4);
      }
      goto LABEL_79;
    }
    v67 = (TSLNodeBase_t *)m_Size;
    v64 = m_pMemory;
    v65 = (int)v15;
    if ( m_Size <= 0 )
      goto LABEL_64;
    while ( 1 )
    {
      v31 = v64[v68];
      v32 = *(_DWORD *)(*(_DWORD *)v65 + 8 * v31);
      v33 = (const cbrush_t *)(*(_DWORD *)v65 + 8 * v31);
      v34 = (unsigned int)v4[63];
      v35 = v34 & v32;
      raye = (const Ray_t *)v33;
      if ( v35 != 0 )
      {
        if ( v35 != 128 || (v34 & 0x2000) == 0 )
        {
LABEL_62:
          CM_ClipBoxToBrush<0>(pTraceInfo: (TraceInfo_t *)v4, brush: v33);
          if ( *((float *)v4 + 32) == 0.0 )
            goto LABEL_64;
          goto LABEL_63;
        }
        v36 = v33->numsides;
        if ( (_WORD)v36 == 0xFFFF )
        {
          v37 = 0;
          v38 = &v4[65][14].Next[6 * v33->firstbrushside + 4];
          while ( 1 )
          {
            v39 = LOWORD(v38->Next);
            v40 = (_WORD)v39 == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[v39];
            if ( SLOBYTE(v40->flags) < 0 )
              break;
            ++v37;
            v38 = (TSLNodeBase_t *)((char *)v38 + 2);
            if ( v37 >= 6 )
            {
              v33 = (const cbrush_t *)raye;
              goto LABEL_62;
            }
          }
        }
        else
        {
          rayf = (const Ray_t *)&v4[65][13].Next[v33->firstbrushside];
          v41 = 0;
          v66 = (unsigned __int16 *)v33->numsides;
          if ( v36 <= 0 )
            goto LABEL_62;
          rayg = (const Ray_t *)&rayf->m_Start.y;
          while ( 1 )
          {
            v42 = LOWORD(rayg->m_Start.x);
            v43 = (_WORD)v42 == 0xFFFF ? &CCollisionBSPData::nullsurface : (csurface_t *)&v4[65][67].Next[v42];
            if ( SLOBYTE(v43->flags) < 0 )
              break;
            rayg = (const Ray_t *)((char *)rayg + 8);
            if ( ++v41 >= (int)v66 )
              goto LABEL_62;
          }
        }
      }
LABEL_63:
      if ( ++v68 >= (int)v67 )
        goto LABEL_64;
    }
  }
  for ( raya = 0; raya < traceData->m_brushList.m_Size; ++raya )
  {
    v12 = (const cbrush_t *)&v4[65][21].Next[traceData->m_brushList.m_Memory.m_pMemory[raya]];
    if ( ((unsigned int)v4[63] & v12->contents) != 0 )
    {
      CM_TestBoxInBrush(pTraceInfo: (TraceInfo_t *)v4, brush: v12);
      if ( *((_BYTE *)v4 + 138) != 0 )
        break;
    }
  }
  if ( *((_BYTE *)v4 + 139) == 0 )
    CM_TestInDispTree(
      pTraceInfo: (TraceInfo_t *)v4,
      pDispList: traceData->m_dispList.m_Memory.m_pMemory,
      dispListCount: traceData->m_dispList.m_Size,
      traceStart: (const Vector *)v4,
      boxMin: (const Vector *)v4 + 2,
      boxMax: (const Vector *)v4 + 3,
      collisionMask: (int)v4[63],
      pTrace: (CGameTrace *)v4 + 1);
  if ( !traceData->m_bFoundNonSolidLeaf )
  {
    *((_WORD *)v4 + 69) = 257;
    v4[32] = nullptr;
    v4[35] = (TSLNodeBase_t *)1065353216;
    goto LABEL_80;
  }
LABEL_79:
  v8 = ray;
LABEL_80:
  v49 = *((float *)v4 + 32);
  v50 = v8->m_StartOffset.x + v8->m_Start.x;
  v51 = v8->m_StartOffset.y + v8->m_Start.y;
  v52 = v8->m_StartOffset.z + v8->m_Start.z;
  v53 = (float *)(v4 + 21);
  if ( v49 == 1.0 )
  {
    *((float *)v4 + 24) = v8->m_Delta.x + v50;
    *((float *)v4 + 25) = v51 + v8->m_Delta.y;
    v54 = v52 + v8->m_Delta.z;
  }
  else
  {
    *((float *)v4 + 24) = (float)(v8->m_Delta.x * v49) + v50;
    *((float *)v4 + 25) = (float)(v49 * v8->m_Delta.y) + v51;
    v54 = (float)(v49 * v8->m_Delta.z) + v52;
  }
  *((float *)v4 + 26) = v54;
  v55 = *((float *)v4 + 35);
  if ( v55 == 0.0 )
  {
    *v53 = v50;
    *((float *)v4 + 22) = v51;
    *((float *)v4 + 23) = v52;
  }
  else
  {
    if ( v55 == 1.0 )
    {
      *((_WORD *)v4 + 69) = 257;
      v4[32] = nullptr;
      *((float *)v4 + 24) = v50;
      *((float *)v4 + 25) = v51;
      *((float *)v4 + 26) = v52;
    }
    v56 = *((float *)v4 + 35);
    *v53 = (float)(v8->m_Delta.x * v56) + v50;
    *((float *)v4 + 22) = (float)(v56 * v8->m_Delta.y) + v51;
    *((float *)v4 + 23) = (float)(v56 * v8->m_Delta.z) + v52;
  }
  CBaseTrace::operator=(this: trace, __that: (const CBaseTrace *)(v4 + 21));
  trace->fractionleftsolid = *((float *)v4 + 35);
  trace->surface = *((csurface_t *)v4 + 18);
  trace->hitgroup = (int)v4[38];
  trace->physicsbone = *((_WORD *)v4 + 78);
  trace->worldSurfaceIndex = *((_WORD *)v4 + 79);
  trace->m_pEnt = (struct CBaseEntity *)v4[40];
  trace->hitbox = (int)v4[41];
  v4[71] = (TSLNodeBase_t *)((char *)v4[71] - 1);
  m_Head = g_TraceInfoPool.m_Head;
  v58 = g_TraceInfoPool.m_Head.value32.DepthAndSequence + 65537;
  v57 = v4 - 1;
  *v57 = g_TraceInfoPool.m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &g_TraceInfoPool,
                          a2: v57,
                          a3: v58,
                          a4: m_Head.value.Next,
                          a5: m_Head.value32.DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      v61 = g_TraceInfoPool.m_Head;
      v59 = g_TraceInfoPool.m_Head.value32.DepthAndSequence + 65537;
      *v57 = g_TraceInfoPool.m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &g_TraceInfoPool,
                               a2: v57,
                               a3: v59,
                               a4: v61.value.Next,
                               a5: v61.value32.DepthAndSequence) == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150690
// Name: void CM_BoxTrace(struct Ray_t const __near &,int,int,bool,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CM_BoxTrace(const Ray_t *ray, int headnode, TSLNodeBase_t *brushmask, bool computeEndpt, CGameTrace *tr)
{
  TSLNodeBase_t **v5; // esi
  CGameTrace *v6; // ebx
  float x; // xmm1_4
  float v8; // xmm4_4
  float y; // xmm3_4
  float v10; // xmm1_4
  float z; // xmm3_4
  float v12; // xmm2_4
  bool m_IsRay; // dl
  float v14; // [esp-10h] [ebp-1Ch]
  float v15; // [esp-Ch] [ebp-18h]
  const Vector *v16; // [esp-4h] [ebp-10h]

  v5 = BeginTrace();
  v6 = (CGameTrace *)(v5 + 21);
  memset(dst: (unsigned __int8 *)v5 + 84, value: 0, count: 0x54u);
  v5[32] = (TSLNodeBase_t *)1065353216;
  v5[35] = nullptr;
  *((csurface_t *)v5 + 18) = CCollisionBSPData::nullsurface;
  if ( *((_DWORD *)&v5[65][15].Next + 1) != 0 )
  {
    v5[69] = nullptr;
    v5[66] = nullptr;
    v5[67] = nullptr;
    v5[68] = nullptr;
    v5[63] = brushmask;
    *(Vector *)v5 = ray->m_Start.Vector;
    *((float *)v5 + 3) = ray->m_Start.x + ray->m_Delta.x;
    *((float *)v5 + 4) = ray->m_Delta.y + ray->m_Start.y;
    *((float *)v5 + 5) = ray->m_Delta.z + ray->m_Start.z;
    *((float *)v5 + 6) = ray->m_Extents.x * -1.0;
    *((float *)v5 + 7) = ray->m_Extents.y * -1.0;
    *((float *)v5 + 8) = ray->m_Extents.z * -1.0;
    *((Vector *)v5 + 3) = ray->m_Extents.Vector;
    *((Vector *)v5 + 4) = ray->m_Extents.Vector;
    *((Vector *)v5 + 5) = ray->m_Delta.Vector;
    x = ray->m_Delta.x;
    if ( x == 0.0 )
      v8 = 3.4028235e38;
    else
      v8 = 1.0 / x;
    y = ray->m_Delta.y;
    if ( y == 0.0 )
      v10 = 3.4028235e38;
    else
      v10 = 1.0 / y;
    z = ray->m_Delta.z;
    if ( z == 0.0 )
      v12 = 3.4028235e38;
    else
      v12 = 1.0 / z;
    *((float *)v5 + 18) = v8;
    *((float *)v5 + 19) = v10;
    *((float *)v5 + 20) = v12;
    m_IsRay = ray->m_IsRay;
    *((_BYTE *)v5 + 256) = m_IsRay;
    *((_BYTE *)v5 + 257) = ray->m_IsSwept;
    if ( ray->m_IsSwept )
    {
      v16 = (const Vector *)(v5 + 3);
      v15 = 1.0;
      v14 = 0.0;
      if ( m_IsRay )
        CM_RecursiveHullCheckImpl_1_(
          pTraceInfo: (TraceInfo_t *)v5,
          num: headnode,
          p1f: v14,
          p2f: v15,
          p1: (const Vector *)v5,
          p2: v16);
      else
        CM_RecursiveHullCheckImpl_0_(
          pTraceInfo: (TraceInfo_t *)v5,
          num: headnode,
          p1f: v14,
          p2f: v15,
          p1: (const Vector *)v5,
          p2: v16);
    }
    else
    {
      CM_UnsweptBoxTrace(pTraceInfo: (TraceInfo_t *)v5, ray, headnode);
    }
    if ( computeEndpt )
      CM_ComputeTraceEndpoints(ray, tr: v6);
  }
  CBaseTrace::operator=(this: tr, __that: v6);
  tr->fractionleftsolid = *((float *)v5 + 35);
  tr->surface = *((csurface_t *)v5 + 18);
  tr->hitgroup = (int)v5[38];
  tr->physicsbone = *((_WORD *)v5 + 78);
  tr->worldSurfaceIndex = *((_WORD *)v5 + 79);
  tr->m_pEnt = (struct CBaseEntity *)v5[40];
  tr->hitbox = (int)v5[41];
  v5[71] = (TSLNodeBase_t *)((char *)v5[71] - 1);
  CTSListBase::Push(this: &g_TraceInfoPool, pNode: (TSLNodeBase_t *)(v5 - 1));
}

//------------------------------------------------------------------------------
// Address: 0x10150910
// Name: void CM_TransformedBoxTrace(struct Ray_t const __near &,int,int,class Vector const __near &,class QAngle const __near &,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CM_TransformedBoxTrace(
        float a1@<ebp>,
        const Ray_t *ray,
        int headnode,
        TSLNodeBase_t *brushmask,
        const Vector *origin,
        const QAngle *angles,
        CGameTrace *tr)
{
  float x; // xmm4_4
  float v8; // xmm1_4
  float y; // xmm2_4
  float z; // xmm0_4
  float v11; // xmm0_4
  bool m_IsSwept; // cl
  float fraction; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // eax
  float fractionleftsolid; // xmm3_4
  float v23; // xmm3_4
  _BYTE v24[12]; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t localToWorld; // [esp+0h] [ebp-A0h] BYREF
  Ray_t ray_l; // [esp+30h] [ebp-70h] BYREF
  Vector normal; // [esp+80h] [ebp-20h] BYREF
  Vector temp; // [esp+8Ch] [ebp-14h]
  void *v29; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  temp.z = a1;
  v29 = retaddr;
  x = angles->x;
  v8 = ray->m_StartOffset.x;
  y = ray->m_StartOffset.y;
  z = ray->m_StartOffset.z;
  *(Vector *)&ray_l.m_StartOffset.y = ray->m_Extents.Vector;
  ray_l.m_Extents.y = 0.0;
  ray_l.m_Delta.y = v8;
  ray_l.m_Delta.z = y;
  ray_l.m_Delta.w = z;
  if ( x == 0.0 && angles->y == 0.0 && angles->z == 0.0 )
  {
    localToWorld.m_flMatVal[2][1] = ray->m_Start.x - origin->x;
    localToWorld.m_flMatVal[2][2] = ray->m_Start.y - origin->y;
    localToWorld.m_flMatVal[2][3] = ray->m_Start.z - origin->z;
    ray_l.m_Start.y = ray->m_Delta.x;
    ray_l.m_Start.z = ray->m_Delta.y;
    v11 = ray->m_Delta.z;
    HIBYTE(temp.y) = 0;
    LODWORD(temp.x) = &ray->m_Delta;
    ray_l.m_Start.w = v11;
  }
  else
  {
    v18 = z + ray->m_Start.z;
    v19 = ray->m_Start.x + v8;
    v20 = ray->m_Start.y + y;
    HIBYTE(temp.y) = 1;
    normal.x = v19;
    normal.y = v20;
    normal.z = v18;
    AngleMatrix(angles, position: origin, matrix: (matrix3x4_t *)v24);
    LODWORD(temp.x) = &ray->m_Delta;
    VectorIRotate(in1: &ray->m_Delta.x, in2: (const matrix3x4_t *)v24, out: &ray_l.m_Start.y);
    VectorITransform(in1: &normal.x, in2: (const matrix3x4_t *)v24, out: &localToWorld.m_flMatVal[2][1]);
    localToWorld.m_flMatVal[2][1] = localToWorld.m_flMatVal[2][1] - ray->m_StartOffset.x;
    localToWorld.m_flMatVal[2][2] = localToWorld.m_flMatVal[2][2] - ray->m_StartOffset.y;
    localToWorld.m_flMatVal[2][3] = localToWorld.m_flMatVal[2][3] - ray->m_StartOffset.z;
  }
  m_IsSwept = ray->m_IsSwept;
  LOBYTE(ray_l.m_Extents.z) = ray->m_IsRay;
  BYTE1(ray_l.m_Extents.z) = m_IsSwept;
  CM_BoxTrace(ray: (const Ray_t *)&localToWorld.m_flMatVal[2][1], headnode, brushmask, computeEndpt: false, tr);
  if ( tr->fraction != 1.0 && HIBYTE(temp.y) != 0 )
  {
    normal = tr->plane.normal;
    VectorRotate(in1: &normal.x, in2: (const matrix3x4_t *)v24, out: &tr->plane.normal.x);
  }
  fraction = tr->fraction;
  v14 = ray->m_Start.x + ray->m_StartOffset.x;
  v15 = ray->m_StartOffset.y + ray->m_Start.y;
  v16 = ray->m_Start.z + ray->m_StartOffset.z;
  v17 = temp.x;
  if ( fraction == 1.0 )
  {
    tr->endpos.x = v14 + *(float *)LODWORD(temp.x);
    tr->endpos.y = *(float *)(LODWORD(v17) + 4) + v15;
    tr->endpos.z = *(float *)(LODWORD(v17) + 8) + v16;
  }
  else
  {
    v21 = temp.x;
    tr->endpos.x = (float)(fraction * *(float *)LODWORD(temp.x)) + v14;
    tr->endpos.y = (float)(*(float *)(LODWORD(v21) + 4) * fraction) + v15;
    tr->endpos.z = (float)(*(float *)(LODWORD(v21) + 8) * fraction) + v16;
  }
  fractionleftsolid = tr->fractionleftsolid;
  if ( fractionleftsolid == 0.0 )
  {
    tr->startpos.x = v14;
    tr->startpos.y = v15;
    tr->startpos.z = v16;
  }
  else
  {
    if ( fractionleftsolid == 1.0 )
    {
      *(_WORD *)&tr->allsolid = 257;
      tr->fraction = 0.0;
      tr->endpos.x = v14;
      tr->endpos.y = v15;
      tr->endpos.z = v16;
    }
    v23 = tr->fractionleftsolid;
    tr->startpos.x = (float)(v23 * *(float *)LODWORD(v17)) + v14;
    tr->startpos.y = (float)(*(float *)(LODWORD(v17) + 4) * v23) + v15;
    tr->startpos.z = (float)(*(float *)(LODWORD(v17) + 8) * v23) + v16;
  }
}

} // namespace engine_xlsp
