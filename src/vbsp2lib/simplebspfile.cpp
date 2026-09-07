// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/simplebspfile.cpp
// Functions: 41
// ============================================================

#include "vbsp2lib\simplebspfile.h"

//------------------------------------------------------------------------------
// Address: 0x1005C890
// Name: private: void CSimpleBSPFile::MakeUnreachableNodesSolid(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::MakeUnreachableNodesSolid(CSimpleBSPFile *this, CBSPNode *pNode)
{
  CBSPNode *i; // esi

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: i->m_pChildren[0]);
  if ( !i->m_bEntityCanReach )
    i->m_ContentsFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x1005C8D0
// Name: public: int CBSPPortal::GetNodeIndexForFace(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBSPPortal::GetNodeIndexForFace(CBSPPortal *this)
{
  int m_ContentsFlags; // eax
  int v2; // edx
  int v3; // ecx

  m_ContentsFlags = this->m_pNodes[0]->m_ContentsFlags;
  v2 = 1;
  v3 = m_ContentsFlags ^ this->m_pNodes[1]->m_ContentsFlags;
  while ( (v3 & v2) == 0 )
  {
    v2 *= 2;
    if ( v2 > 128 )
    {
      v2 = 0;
      return (v2 & m_ContentsFlags) != 0;
    }
  }
  return (v2 & m_ContentsFlags) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005C9A0
// Name: private: enum PlaneSide_t CSimpleBSPFile::GetPrimaryPlaneSide(class CBSPBrush __near *,struct Plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __thiscall CSimpleBSPFile::GetPrimaryPlaneSide(CSimpleBSPFile *this, CBSPBrush *pBrush, Plane_t *pPlane)
{
  int m_Size; // edx
  float v4; // xmm0_4
  PlaneSide_t result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v6; // ecx
  int v7; // ebx
  int v8; // edx
  Vector *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // esi
  float *v15; // edx
  unsigned int v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float *p_x; // ecx
  int v22; // ebx
  float v23; // xmm1_4
  bool v24; // zf
  int j; // [esp+0h] [ebp-8h]
  int v26; // [esp+4h] [ebp-4h]
  CBSPBrush *pBrusha; // [esp+10h] [ebp+8h]

  m_Size = pBrush->m_Sides.m_Size;
  v4 = 0.0;
  result = PLANE_SIDE_FRONT;
  if ( m_Size <= 0 )
    return result;
  v6 = &pBrush->m_Sides.m_Memory.m_pMemory->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  pBrusha = (CBSPBrush *)v6;
  v26 = m_Size;
  do
  {
    v7 = v6->m_Size;
    v8 = 0;
    if ( v7 < 4 )
      goto LABEL_27;
    m_pMemory = v6->m_Memory.m_pMemory;
    y = pPlane->m_vNormal.y;
    x = pPlane->m_vNormal.x;
    z = pPlane->m_vNormal.z;
    m_flDistance = pPlane->m_flDistance;
    p_z = &m_pMemory->z;
    v15 = &m_pMemory[1].z;
    v16 = ((unsigned int)(v7 - 4) >> 2) + 1;
    j = 4 * v16;
    do
    {
      v17 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(*p_z * z)) - m_flDistance;
      if ( v17 <= v4 )
      {
        v17 = -v17;
        if ( v17 <= v4 )
          goto LABEL_10;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v17;
LABEL_10:
      v18 = (float)((float)((float)(*(v15 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v15)) - m_flDistance;
      if ( v18 <= v4 )
      {
        v18 = -v18;
        if ( v18 <= v4 )
          goto LABEL_15;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v18;
LABEL_15:
      v19 = (float)((float)((float)(v15[2] * y) + (float)(p_z[4] * x)) + (float)(v15[3] * z)) - m_flDistance;
      if ( v19 <= v4 )
      {
        v19 = -v19;
        if ( v19 <= v4 )
          goto LABEL_20;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v19;
LABEL_20:
      v20 = (float)((float)((float)(v15[5] * y) + (float)(p_z[7] * x)) + (float)(v15[6] * z)) - m_flDistance;
      if ( v20 <= v4 )
      {
        v20 = -v20;
        if ( v20 <= v4 )
          goto LABEL_25;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v20;
LABEL_25:
      p_z += 12;
      v15 += 12;
      --v16;
    }
    while ( v16 != 0 );
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)pBrusha;
    v8 = j;
LABEL_27:
    if ( v8 >= v7 )
      goto LABEL_36;
    p_x = &v6->m_Memory.m_pMemory[v8].x;
    v22 = v7 - v8;
    while ( 2 )
    {
      v23 = (float)((float)((float)(p_x[1] * pPlane->m_vNormal.y) + (float)(pPlane->m_vNormal.x * *p_x))
                  + (float)(p_x[2] * pPlane->m_vNormal.z))
          - pPlane->m_flDistance;
      if ( v23 > v4 )
      {
        result = PLANE_SIDE_FRONT;
        goto LABEL_33;
      }
      v23 = -v23;
      if ( v23 > v4 )
      {
        result = PLANE_SIDE_BACK;
LABEL_33:
        v4 = v23;
      }
      p_x += 3;
      if ( --v22 != 0 )
        continue;
      break;
    }
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)pBrusha;
LABEL_36:
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)v6 + 36);
    v24 = v26-- == 1;
    pBrusha = (CBSPBrush *)v6;
  }
  while ( !v24 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005CBD0
// Name: private: enum PlaneSide_t CSimpleBSPFile::TestBrushAgainstPlaneIndex(class CBSPBrush __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __thiscall CSimpleBSPFile::TestBrushAgainstPlaneIndex(
        CSimpleBSPFile *this,
        CBSPBrush *pBrush,
        int nPlaneIndex,
        int *nNumSplits)
{
  CBSPBrush *v4; // esi
  int m_Size; // edi
  int v6; // edx
  CBSPBrushSide *v7; // ecx
  HashedPlane_t *v8; // ebx
  PlaneSide_t result; // eax
  CBSPBrushSide *v10; // eax
  int v11; // edi
  int v12; // edx
  Vector *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // esi
  float *v19; // edx
  unsigned int v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float *p_x; // ecx
  int v26; // edi
  float v27; // xmm0_4
  int j; // [esp+10h] [ebp-14h]
  int ia; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h]
  int nBackPoints; // [esp+20h] [ebp-4h]
  int nFrontPoints; // [esp+30h] [ebp+Ch]

  v4 = pBrush;
  *nNumSplits = 0;
  m_Size = pBrush->m_Sides.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    v8 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[nPlaneIndex];
    result = GetPlaneSide(vMin: &pBrush->m_vMinBounds, vMax: &pBrush->m_vMaxBounds, pPlane: v8);
    if ( result == PLANE_SIDE_BOTH )
    {
      ia = 0;
      if ( pBrush->m_Sides.m_Size > 0 )
      {
        v31 = 0;
        do
        {
          v10 = &v4->m_Sides.m_Memory.m_pMemory[v31];
          if ( v10->m_nTextureInfoIndex != -1 )
          {
            v11 = v10->m_Polygon.m_Points.m_Size;
            v12 = 0;
            nFrontPoints = 0;
            nBackPoints = 0;
            if ( v11 >= 4 )
            {
              m_pMemory = v10->m_Polygon.m_Points.m_Memory.m_pMemory;
              y = v8->m_vNormal.y;
              x = v8->m_vNormal.x;
              z = v8->m_vNormal.z;
              m_flDistance = v8->m_flDistance;
              p_z = &m_pMemory->z;
              v19 = &m_pMemory[1].z;
              v20 = ((unsigned int)(v11 - 4) >> 2) + 1;
              j = 4 * v20;
              do
              {
                v21 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(*p_z * z))
                    - m_flDistance;
                if ( v21 <= 0.1 )
                {
                  if ( v21 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v22 = (float)((float)((float)(*(v19 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v19)) - m_flDistance;
                if ( v22 <= 0.1 )
                {
                  if ( v22 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v23 = (float)((float)((float)(v19[2] * y) + (float)(p_z[4] * x)) + (float)(v19[3] * z)) - m_flDistance;
                if ( v23 <= 0.1 )
                {
                  if ( v23 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v24 = (float)((float)((float)(v19[5] * y) + (float)(p_z[7] * x)) + (float)(v19[6] * z)) - m_flDistance;
                if ( v24 <= 0.1 )
                {
                  if ( v24 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                p_z += 12;
                v19 += 12;
                --v20;
              }
              while ( v20 != 0 );
              v4 = pBrush;
              v12 = j;
            }
            if ( v12 < v11 )
            {
              p_x = &v10->m_Polygon.m_Points.m_Memory.m_pMemory[v12].x;
              v26 = v11 - v12;
              do
              {
                v27 = (float)((float)((float)(p_x[1] * v8->m_vNormal.y) + (float)(v8->m_vNormal.x * *p_x))
                            + (float)(p_x[2] * v8->m_vNormal.z))
                    - v8->m_flDistance;
                if ( v27 <= 0.1 )
                {
                  if ( v27 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                p_x += 3;
                --v26;
              }
              while ( v26 != 0 );
              v4 = pBrush;
            }
            if ( nFrontPoints > 0 && nBackPoints > 0 && (v10->m_SurfaceFlags & 0x200) == 0 )
              ++*nNumSplits;
          }
          ++v31;
          ++ia;
        }
        while ( ia < v4->m_Sides.m_Size );
        return PLANE_SIDE_BOTH;
      }
    }
  }
  else
  {
    v7 = pBrush->m_Sides.m_Memory.m_pMemory;
    while ( 1 )
    {
      if ( nPlaneIndex == v7->m_nPlaneIndex )
        return PLANE_SIDE_FACING|PLANE_SIDE_BACK;
      if ( nPlaneIndex == (v7->m_nPlaneIndex ^ 1) )
        return PLANE_SIDE_FACING|PLANE_SIDE_FRONT;
      ++v6;
      ++v7;
      if ( v6 >= m_Size )
        goto LABEL_6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005CE80
// Name: private: void CSimpleBSPFile::FloodFillThroughPortals(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FloodFillThroughPortals(CSimpleBSPFile *this, CBSPNode *pNode)
{
  int v2; // edi
  CBSPPortal *v4; // ecx
  CBSPNode *v5; // eax

  v2 = 0;
  for ( pNode->m_bEntityCanReach = true; v2 < pNode->m_Portals.m_Size; ++v2 )
  {
    v4 = pNode->m_Portals.m_Memory.m_pMemory[v2];
    v5 = v4->m_pNodes[0];
    if ( v4->m_pNodes[0] == pNode )
      v5 = v4->m_pNodes[1];
    if ( !v5->m_bEntityCanReach && (v5->m_ContentsFlags & 1) == 0 )
      CSimpleBSPFile::FloodFillThroughPortals(this, pNode: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CED0
// Name: private: void CSimpleBSPFile::NumberPortalFaces(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::NumberPortalFaces(CSimpleBSPFile *this, CBSPNode *pNode)
{
  int i; // eax

  while ( 1 )
  {
    for ( i = 0; i < pNode->m_Faces.m_Size; ++i )
      pNode->m_Faces.m_Memory.m_pMemory[i]->m_nSerializedFaceIndex = this->m_nNextFaceIndex++;
    if ( pNode->m_nSplitPlaneIndex == -1 )
      break;
    CSimpleBSPFile::NumberPortalFaces(this, pNode: pNode->m_pChildren[0]);
    pNode = pNode->m_pChildren[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D0D0
// Name: public: CBSPNode::CBSPNode(void)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CBSPNode::CBSPNode(CBSPNode *this)
{
  this->m_pParent = nullptr;
  this->m_ContentsFlags = 0;
  this->m_nSplitPlaneIndex = -1;
  this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
  this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  this->m_ClippedBrushes.m_Memory.m_nGrowSize = 0;
  this->m_ClippedBrushes.m_Size = 0;
  this->m_ClippedBrushes.m_pElements = nullptr;
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = nullptr;
  this->m_Portals.m_Memory.m_pMemory = nullptr;
  this->m_Portals.m_Memory.m_nAllocationCount = 0;
  this->m_Portals.m_Memory.m_nGrowSize = 0;
  this->m_Portals.m_Size = 0;
  this->m_Portals.m_pElements = nullptr;
  this->m_bEntityCanReach = false;
  this->m_pChildren[1] = nullptr;
  this->m_pChildren[0] = nullptr;
  this->m_nClusterIndex = -1;
  ClearBounds(mins: &this->m_vMinBounds, maxs: &this->m_vMaxBounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D130
// Name: private: class CBSPNode __near * CSimpleBSPFile::GenerateBSPGrid(int,int,int,int,int __near * const,int __near * const,class CBSPNode __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CSimpleBSPFile::GenerateBSPGrid(
        CSimpleBSPFile *this,
        int nMinX,
        int nMinY,
        int nMaxX,
        int nMaxY,
        int *nAbsoluteMins,
        int *nAbsoluteMaxs,
        CBSPNode **ppNodeList)
{
  int v10; // edx
  CBSPNode *v12; // eax
  CBSPNode *v13; // eax
  CBSPNode *v14; // esi
  CBSPNode *BSPGrid; // eax
  CBSPNode *v16; // edx
  Vector vNormal; // [esp+10h] [ebp-Ch] BYREF
  int nMinXa; // [esp+28h] [ebp+Ch]
  int nMinXb; // [esp+28h] [ebp+Ch]

  if ( nMinX == nMaxX && nMinY == nMaxY )
  {
    if ( nMinX < *nAbsoluteMins
      || nMaxX > *nAbsoluteMaxs
      || (v10 = nAbsoluteMins[1], nMinY < v10)
      || nMaxY > nAbsoluteMaxs[1] )
    {
      v12 = (CBSPNode *)operator new(nSize: 0x70u);
      if ( v12 != nullptr )
        return CBSPNode::CBSPNode(this: v12);
      else
        return nullptr;
    }
    else
    {
      return *(&ppNodeList[nMinX] + (nMinY - v10) * (*nAbsoluteMaxs - *nAbsoluteMins + 1) - *nAbsoluteMins);
    }
  }
  else
  {
    v13 = (CBSPNode *)operator new(nSize: 0x70u);
    if ( v13 != nullptr )
      v14 = CBSPNode::CBSPNode(this: v13);
    else
      v14 = nullptr;
    if ( nMaxX - nMinX <= nMaxY - nMinY )
    {
      nMinXb = (nMaxY - nMinY) / 2 + nMinY + 1;
      vNormal.x = 0.0;
      vNormal.z = 0.0;
      vNormal.y = 1.0;
      v14->m_nSplitPlaneIndex = CPlaneHash::FindPlaneIndex(
                                  this: &this->m_PlaneHash,
                                  &vNormal,
                                  flDistance: (float)(nMinXb << 10));
      v14->m_pChildren[0] = CSimpleBSPFile::GenerateBSPGrid(
                              this,
                              nMinX,
                              nMinY: nMinXb,
                              nMaxX,
                              nMaxY,
                              nAbsoluteMins,
                              nAbsoluteMaxs,
                              ppNodeList);
      BSPGrid = CSimpleBSPFile::GenerateBSPGrid(
                  this,
                  nMinX,
                  nMinY,
                  nMaxX,
                  nMaxY: (nMaxY - nMinY) / 2 + nMinY,
                  nAbsoluteMins,
                  nAbsoluteMaxs,
                  ppNodeList);
    }
    else
    {
      vNormal.x = 1.0;
      nMinXa = (nMaxX - nMinX) / 2 + nMinX + 1;
      vNormal.y = 0.0;
      vNormal.z = 0.0;
      v14->m_nSplitPlaneIndex = CPlaneHash::FindPlaneIndex(
                                  this: &this->m_PlaneHash,
                                  &vNormal,
                                  flDistance: (float)(nMinXa << 10));
      v14->m_pChildren[0] = CSimpleBSPFile::GenerateBSPGrid(
                              this,
                              nMinX: nMinXa,
                              nMinY,
                              nMaxX,
                              nMaxY,
                              nAbsoluteMins,
                              nAbsoluteMaxs,
                              ppNodeList);
      BSPGrid = CSimpleBSPFile::GenerateBSPGrid(
                  this,
                  nMinX,
                  nMinY,
                  nMaxX: (nMaxX - nMinX) / 2 + nMinX,
                  nMaxY,
                  nAbsoluteMins,
                  nAbsoluteMaxs,
                  ppNodeList);
    }
    v16 = v14->m_pChildren[0];
    v14->m_pChildren[1] = BSPGrid;
    v16->m_pParent = v14;
    v14->m_pChildren[1]->m_pParent = v14;
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D310
// Name: private: int CSimpleBSPFile::FindBestSplitPlane(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleBSPFile::FindBestSplitPlane(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList)
{
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v2; // ecx
  int m_Size; // esi
  int v4; // edi
  int v5; // eax
  CBSPBrush *v6; // edx
  CBSPBrushSide *v7; // eax
  bool v8; // zf
  int v9; // ebx
  int v10; // ecx
  unsigned int v11; // edi
  CBSPBrush *v12; // esi
  PlaneSide_t v13; // eax
  int v14; // edx
  CBSPBrushSide *m_pMemory; // ecx
  signed int v16; // eax
  int v17; // eax
  CBitVec<2048> testedFlags; // [esp+Ch] [ebp-140h] BYREF
  CBSPBrushSide *pBrushSide; // [esp+10Ch] [ebp-40h]
  CBSPBrush *pBrush; // [esp+110h] [ebp-3Ch]
  PlaneSide_t planeSide; // [esp+114h] [ebp-38h]
  int nBestValue; // [esp+118h] [ebp-34h]
  int nSide; // [esp+11Ch] [ebp-30h]
  int nBrush; // [esp+120h] [ebp-2Ch]
  int nBestPlane; // [esp+124h] [ebp-28h]
  CSimpleBSPFile *v27; // [esp+128h] [ebp-24h]
  int nFacing; // [esp+12Ch] [ebp-20h]
  int nBack; // [esp+130h] [ebp-1Ch]
  unsigned int v30; // [esp+134h] [ebp-18h]
  int nTestBrush; // [esp+138h] [ebp-14h]
  int nSplits; // [esp+13Ch] [ebp-10h]
  int nFront; // [esp+140h] [ebp-Ch]
  int nFlagIndex; // [esp+144h] [ebp-8h]
  int nBrushSplits; // [esp+148h] [ebp-4h] BYREF

  v27 = this;
  nBestPlane = -1;
  nBestValue = -99999;
  memset(dst: (unsigned __int8 *)&testedFlags, value: 0, count: sizeof(testedFlags));
  v2 = pBrushList;
  m_Size = pBrushList->m_Size;
  v4 = 0;
  v5 = 0;
  nFlagIndex = 0;
  nBrush = 0;
  if ( m_Size <= 0 )
    return -1;
  do
  {
    v6 = v2->m_Memory.m_pMemory[v5];
    pBrush = v6;
    nSide = 0;
    if ( v6->m_Sides.m_Size > 0 )
    {
      v30 = 0;
      do
      {
        v7 = &v6->m_Sides.m_Memory.m_pMemory[v30 / 0x24];
        v8 = v7->m_nTextureInfoIndex == -1;
        pBrushSide = v7;
        if ( v8 )
        {
          nFlagIndex = ++v4;
        }
        else if ( ((1 << (v4 & 0x1F)) & testedFlags.m_Ints[v4 >> 5]) != 0 )
        {
          nFlagIndex = ++v4;
        }
        else
        {
          v9 = 0;
          v10 = 0;
          v11 = v7->m_nPlaneIndex & 0xFFFFFFFE;
          nFront = 0;
          nBack = 0;
          nFacing = 0;
          nSplits = 0;
          nTestBrush = 0;
          if ( m_Size > 0 )
          {
            do
            {
              v12 = pBrushList->m_Memory.m_pMemory[nTestBrush];
              nBrushSplits = 0;
              v13 = CSimpleBSPFile::TestBrushAgainstPlaneIndex(
                      this: v27,
                      pBrush: v12,
                      nPlaneIndex: v11,
                      nNumSplits: &nBrushSplits);
              nSplits += nBrushSplits;
              planeSide = v13;
              v12->m_nTempSplitSide = v13;
              if ( (v13 & 4) != 0 )
              {
                ++nFacing;
                v14 = __ROL4__(1, v9);
                if ( v12->m_Sides.m_Size > 0 )
                {
                  m_pMemory = v12->m_Sides.m_Memory.m_pMemory;
                  nBrushSplits = v12->m_Sides.m_Size;
                  do
                  {
                    if ( (m_pMemory->m_nPlaneIndex & 0xFFFFFFFE) == v11 )
                    {
                      testedFlags.m_Ints[v9 >> 5] |= v14;
                      LOBYTE(v13) = planeSide;
                    }
                    ++v9;
                    v14 = __ROL4__(v14, 1);
                    ++m_pMemory;
                    --nBrushSplits;
                  }
                  while ( nBrushSplits != 0 );
                }
              }
              if ( (v13 & 1) != 0 )
                ++nFront;
              if ( (v13 & 2) != 0 )
                ++nBack;
              m_Size = pBrushList->m_Size;
              ++nTestBrush;
            }
            while ( nTestBrush < m_Size );
            v10 = nFacing;
          }
          v16 = 5 * (v10 - nSplits) - abs32(nFront - nBack);
          if ( v27->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v11].m_Type < 3 )
            v16 += 5;
          if ( (pBrushSide->m_SurfaceFlags & 0x10) != 0 )
            v16 -= 500;
          if ( v16 > nBestValue )
          {
            m_Size = pBrushList->m_Size;
            nBestValue = v16;
            v17 = 0;
            for ( nBestPlane = v11; v17 < m_Size; ++v17 )
            {
              pBrushList->m_Memory.m_pMemory[v17]->m_nSplitSide = pBrushList->m_Memory.m_pMemory[v17]->m_nTempSplitSide;
              m_Size = pBrushList->m_Size;
            }
          }
          v4 = ++nFlagIndex;
          v6 = pBrush;
        }
        v30 += 36;
        ++nSide;
      }
      while ( nSide < v6->m_Sides.m_Size );
      v2 = pBrushList;
      v5 = nBrush;
    }
    m_Size = v2->m_Size;
    nBrush = ++v5;
  }
  while ( v5 < m_Size );
  return nBestPlane;
}

//------------------------------------------------------------------------------
// Address: 0x1005D530
// Name: private: void CSimpleBSPFile::FloodEntities(class CBSPTree __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FloodEntities(CSimpleBSPFile *this, CBSPTree *pTree)
{
  const CSimpleMapFile *m_pMapFile; // eax
  int v4; // ebx
  int v5; // esi
  const MapEntityKeyValuePair_t *Pair; // eax
  const char *PairValue; // eax
  float v8; // xmm0_4
  CBSPNode *m_pRoot; // ecx
  int i; // eax
  CBSPNode *v11; // edx
  int v12; // edx
  Vector vOrigin; // [esp+Ch] [ebp-Ch] BYREF

  m_pMapFile = this->m_pMapFile;
  v4 = 1;
  if ( this->m_pMapFile->m_Entities.m_Size > 1 )
  {
    v5 = 1;
    do
    {
      Pair = FindPair(
               pKeyName: "origin",
               pPairs: &m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory[m_pMapFile->m_Entities.m_Memory.m_pMemory[v5].m_nFirstKVPairIndex],
               nNumPairs: m_pMapFile->m_Entities.m_Memory.m_pMemory[v5].m_nNumKVPairs);
      if ( Pair != nullptr )
      {
        PairValue = GetPairValue(pPair: Pair);
        sscanf(string: PairValue, format: "%f %f %f", &vOrigin, &vOrigin.y, &vOrigin.z);
        v8 = vOrigin.z + 1.0;
        m_pRoot = pTree->m_pRoot;
        vOrigin.z = vOrigin.z + 1.0;
        for ( i = m_pRoot->m_nSplitPlaneIndex; i != -1; i = m_pRoot->m_nSplitPlaneIndex )
        {
          if ( this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_flDistance <= (float)((float)((float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.y * vOrigin.y)
                                                                                              + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.x * vOrigin.x))
                                                                                      + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.z
                                                                                              * v8)) )
            m_pRoot = m_pRoot->m_pChildren[0];
          else
            m_pRoot = m_pRoot->m_pChildren[1];
        }
        if ( (m_pRoot->m_ContentsFlags & 1) == 0 )
          CSimpleBSPFile::FloodFillThroughPortals(this, pNode: m_pRoot);
      }
      m_pMapFile = this->m_pMapFile;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pMapFile->m_Entities.m_Size );
  }
  if ( pTree->m_OutsideNode.m_bEntityCanReach
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Entity can reach outside node; map is leaky.\n");
  }
  v11 = pTree->m_pRoot;
  if ( pTree->m_pRoot->m_nSplitPlaneIndex == -1 )
  {
    if ( !v11->m_bEntityCanReach )
      v11->m_ContentsFlags |= 1u;
  }
  else
  {
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: v11->m_pChildren[0]);
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: *(CBSPNode **)(v12 + 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D710
// Name: public: CBSPPortal::CBSPPortal(class CBSPPortal const __near &,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPPortal *__thiscall CBSPPortal::CBSPPortal(CBSPPortal *this, const CBSPPortal *other, Polygon_t *pPortalShape)
{
  CBSPPortal *result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v4; // ecx
  int m_nGrowSize; // edx
  Vector *m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  Vector *m_pElements; // edx

  result = this;
  this->m_pOnNode = other->m_pOnNode;
  v4 = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
  result->m_Polygon.m_Points.m_Size = 0;
  result->m_Polygon.m_Points.m_pElements = nullptr;
  result->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  result->m_Plane = other->m_Plane;
  result->m_PortalFaces.m_Memory.m_pMemory = nullptr;
  result->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  result->m_PortalFaces.m_Memory.m_nGrowSize = 0;
  result->m_PortalFaces.m_Size = 0;
  result->m_PortalFaces.m_pElements = nullptr;
  result->m_pNodes[0] = other->m_pNodes[0];
  result->m_pNodes[1] = other->m_pNodes[1];
  if ( pPortalShape != nullptr )
    v4 = &pPortalShape->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  m_nGrowSize = result->m_Polygon.m_Points.m_Memory.m_nGrowSize;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = v4->m_Memory.m_nGrowSize;
  v4->m_Memory.m_nGrowSize = m_nGrowSize;
  m_pMemory = result->m_Polygon.m_Points.m_Memory.m_pMemory;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = v4->m_Memory.m_pMemory;
  v4->m_Memory.m_pMemory = m_pMemory;
  m_nAllocationCount = result->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
  v4->m_Memory.m_nAllocationCount = m_nAllocationCount;
  m_Size = result->m_Polygon.m_Points.m_Size;
  result->m_Polygon.m_Points.m_Size = v4->m_Size;
  v4->m_Size = m_Size;
  m_pElements = result->m_Polygon.m_Points.m_pElements;
  result->m_Polygon.m_Points.m_pElements = v4->m_pElements;
  v4->m_pElements = m_pElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005D7C0
// Name: public: CBSPFace::CBSPFace(class CBSPFace const __near &,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPFace *__thiscall CBSPFace::CBSPFace(CBSPFace *this, const CBSPFace *other, Polygon_t *pPolygon)
{
  CBSPFace *result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v4; // ecx
  int m_nGrowSize; // edx
  Vector *m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  Vector *m_pElements; // edx

  result = this;
  this->m_nTextureInfoIndex = other->m_nTextureInfoIndex;
  this->m_nPlaneIndex = other->m_nPlaneIndex;
  v4 = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
  result->m_Polygon.m_Points.m_Size = 0;
  result->m_Polygon.m_Points.m_pElements = nullptr;
  result->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  result->m_nDisplacementIndex = -1;
  result->m_nSerializedFaceIndex = -1;
  if ( pPolygon != nullptr )
    v4 = &pPolygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  m_nGrowSize = result->m_Polygon.m_Points.m_Memory.m_nGrowSize;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = v4->m_Memory.m_nGrowSize;
  v4->m_Memory.m_nGrowSize = m_nGrowSize;
  m_pMemory = result->m_Polygon.m_Points.m_Memory.m_pMemory;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = v4->m_Memory.m_pMemory;
  v4->m_Memory.m_pMemory = m_pMemory;
  m_nAllocationCount = result->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
  v4->m_Memory.m_nAllocationCount = m_nAllocationCount;
  m_Size = result->m_Polygon.m_Points.m_Size;
  result->m_Polygon.m_Points.m_Size = v4->m_Size;
  v4->m_Size = m_Size;
  m_pElements = result->m_Polygon.m_Points.m_pElements;
  result->m_Polygon.m_Points.m_pElements = v4->m_pElements;
  v4->m_pElements = m_pElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005D840
// Name: private: void CSimpleBSPFile::AssignClusterIndicesToLeaves(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::AssignClusterIndicesToLeaves(CSimpleBSPFile *this, CBSPNode *pNode)
{
  CBSPNode *i; // esi
  int v4; // eax

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: i->m_pChildren[0]);
  if ( (i->m_ContentsFlags & 1) == 0 )
  {
    v4 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: (CUtlVector<int,CUtlMemory<int,int> > *)&this->m_Clusters);
    i->m_nClusterIndex = v4;
    this->m_Clusters.m_Memory.m_pMemory[v4].m_pLeafNode = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D890
// Name: private: void CSimpleBSPFile::FilterFaceIntoTree(class CBSPNode __near *,class CBSPFace __near *,class CBSPFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FilterFaceIntoTree(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CBSPFace *pClippedFace,
        CBSPFace *pOriginalFace)
{
  int m_nSplitPlaneIndex; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPFace **m_pMemory; // ecx
  int v9; // eax
  CBSPFace **v10; // eax
  CSimpleBSPFile *v11; // eax
  HashedPlane_t *v12; // esi
  int v13; // eax
  int m_nGrowSize; // edx
  Vector *v15; // edx
  int v16; // edx
  Vector *m_pElements; // eax
  Vector *v18; // edx
  int v19; // edx
  CBSPFace v20; // [esp+1Ch] [ebp-74h] BYREF
  Polygon_t pPolygon; // [esp+44h] [ebp-4Ch] BYREF
  Polygon_t v22; // [esp+5Ch] [ebp-34h] BYREF
  Polygon_t v23; // [esp+74h] [ebp-1Ch] BYREF
  CSimpleBSPFile *v24; // [esp+8Ch] [ebp-4h]

  m_nSplitPlaneIndex = pNode->m_nSplitPlaneIndex;
  v24 = this;
  if ( m_nSplitPlaneIndex == -1 )
  {
    if ( (pNode->m_ContentsFlags & 1) == 0 )
    {
      m_Size = pNode->m_Faces.m_Size;
      m_nAllocationCount = pNode->m_Faces.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&pNode->m_Faces,
          num: m_Size - m_nAllocationCount + 1);
      ++pNode->m_Faces.m_Size;
      m_pMemory = pNode->m_Faces.m_Memory.m_pMemory;
      v9 = pNode->m_Faces.m_Size - m_Size - 1;
      pNode->m_Faces.m_pElements = m_pMemory;
      if ( v9 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v9);
      v10 = &pNode->m_Faces.m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = pOriginalFace;
      if ( pOriginalFace->m_nSerializedFaceIndex == -1 )
      {
        v11 = v24;
        pOriginalFace->m_nSerializedFaceIndex = v24->m_nNextFaceIndex;
        ++v11->m_nNextFaceIndex;
      }
    }
  }
  else
  {
    v12 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[m_nSplitPlaneIndex];
    v23.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    pPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    v22.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    memset(
      &v23.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(v23.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    memset(
      &pPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(pPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    memset(
      &v22.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(v22.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    ChopPolygon(
      polygon: &pClippedFace->m_Polygon,
      vNormal: &v12->m_vNormal,
      flDistance: v12->m_flDistance,
      pOn: &v23,
      pFront: &pPolygon,
      pBack: &v22);
    v13 = v23.m_Points.m_Size;
    if ( v23.m_Points.m_Size > 0 )
    {
      m_nGrowSize = v23.m_Points.m_Memory.m_nGrowSize;
      if ( (float)((float)((float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.y
                                 * v12->m_vNormal.y)
                         + (float)(v12->m_vNormal.x
                                 * this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.x))
                 + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.z
                         * v12->m_vNormal.z)) <= 0.0 )
      {
        v23.m_Points.m_Memory.m_nGrowSize = v22.m_Points.m_Memory.m_nGrowSize;
        v22.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
        v18 = v23.m_Points.m_Memory.m_pMemory;
        v23.m_Points.m_Memory.m_pMemory = v22.m_Points.m_Memory.m_pMemory;
        v22.m_Points.m_Memory.m_pMemory = v18;
        v19 = v23.m_Points.m_Memory.m_nAllocationCount;
        v23.m_Points.m_Memory.m_nAllocationCount = v22.m_Points.m_Memory.m_nAllocationCount;
        v23.m_Points.m_Size = v22.m_Points.m_Size;
        v22.m_Points.m_Size = v13;
        m_pElements = v22.m_Points.m_pElements;
        v22.m_Points.m_Memory.m_nAllocationCount = v19;
        v22.m_Points.m_pElements = v23.m_Points.m_pElements;
      }
      else
      {
        v23.m_Points.m_Memory.m_nGrowSize = pPolygon.m_Points.m_Memory.m_nGrowSize;
        pPolygon.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
        v15 = v23.m_Points.m_Memory.m_pMemory;
        v23.m_Points.m_Memory.m_pMemory = pPolygon.m_Points.m_Memory.m_pMemory;
        pPolygon.m_Points.m_Memory.m_pMemory = v15;
        v16 = v23.m_Points.m_Memory.m_nAllocationCount;
        v23.m_Points.m_Memory.m_nAllocationCount = pPolygon.m_Points.m_Memory.m_nAllocationCount;
        v23.m_Points.m_Size = pPolygon.m_Points.m_Size;
        pPolygon.m_Points.m_Size = v13;
        m_pElements = pPolygon.m_Points.m_pElements;
        pPolygon.m_Points.m_Memory.m_nAllocationCount = v16;
        pPolygon.m_Points.m_pElements = v23.m_Points.m_pElements;
      }
      v23.m_Points.m_pElements = m_pElements;
    }
    if ( pPolygon.m_Points.m_Size > 0 )
    {
      CBSPFace::CBSPFace(this: &v20, other: pClippedFace, &pPolygon);
      CSimpleBSPFile::FilterFaceIntoTree(this, pNode: pNode->m_pChildren[0], pClippedFace: &v20, pOriginalFace);
      v20.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v20.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    }
    if ( v22.m_Points.m_Size > 0 )
    {
      CBSPFace::CBSPFace(this: &v20, other: pClippedFace, pPolygon: &v22);
      CSimpleBSPFile::FilterFaceIntoTree(this, pNode: pNode->m_pChildren[1], pClippedFace: &v20, pOriginalFace);
      v20.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v20.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    }
    v22.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v22.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    pPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    v23.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v23.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DB00
// Name: AttachPortalToNodes
// Source: json
//------------------------------------------------------------------------------
void __usercall AttachPortalToNodes(vgui::TreeNode_vtbl *pNode0@<eax>, vgui::TreeNode *pPortal, CBSPNode *pNode1)
{
  CUtlMemory<vgui::TreeNode *,int> *p_OnMessage; // esi
  int GetCurrentKeyFocus; // eax
  vgui::TreeNode **m_pMemory; // edi
  vgui::TreeNode **v6; // ecx
  int v7; // eax
  vgui::TreeNode **v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBSPPortal **v11; // ecx
  int v12; // eax
  CBSPPortal **v13; // eax

  p_OnMessage = (CUtlMemory<vgui::TreeNode *,int> *)&pNode0->OnMessage;
  pPortal->__vftable = pNode0;
  *(_DWORD *)&pPortal->vgui::Panel::m_RegisterClass = pNode1;
  GetCurrentKeyFocus = (int)pNode0->GetCurrentKeyFocus;
  m_pMemory = p_OnMessage[1].m_pMemory;
  if ( (int)m_pMemory + 1 > GetCurrentKeyFocus )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: p_OnMessage,
      num: (int)m_pMemory - GetCurrentKeyFocus + 1);
  ++p_OnMessage[1].m_pMemory;
  v6 = p_OnMessage->m_pMemory;
  v7 = (char *)p_OnMessage[1].m_pMemory - (char *)m_pMemory - 1;
  p_OnMessage[1].m_nAllocationCount = (int)p_OnMessage->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v6[(_DWORD)m_pMemory + 1],
      src: (unsigned __int8 *)&v6[(_DWORD)m_pMemory],
      count: 4 * v7);
  v8 = &p_OnMessage->m_pMemory[(_DWORD)m_pMemory];
  if ( v8 != nullptr )
    *v8 = pPortal;
  m_Size = pNode1->m_Portals.m_Size;
  m_nAllocationCount = pNode1->m_Portals.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&pNode1->m_Portals,
      num: m_Size - m_nAllocationCount + 1);
  ++pNode1->m_Portals.m_Size;
  v11 = pNode1->m_Portals.m_Memory.m_pMemory;
  v12 = pNode1->m_Portals.m_Size - m_Size - 1;
  pNode1->m_Portals.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v11[m_Size + 1], src: (unsigned __int8 *)&v11[m_Size], count: 4 * v12);
  v13 = &pNode1->m_Portals.m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = (CBSPPortal *)pPortal;
}

//------------------------------------------------------------------------------
// Address: 0x1005DBC0
// Name: SubdivideFaceForLightmaps
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl SubdivideFaceForLightmaps(
        const CSimpleMapFile *pMapFile,
        CUtlMemory<vgui::TreeNode *,int> *pFaceList,
        int nOriginalFaceIndex)
{
  CBSPFace *v4; // eax
  MapTextureInfo_t *v5; // ecx
  Vector *m_pElements; // ecx
  float z; // xmm1_4
  float x; // xmm3_4
  int y_low; // xmm4_4
  __m128 v10; // xmm2
  float v11; // xmm5_4
  int m_Size; // edi
  int v13; // ebx
  Vector *m_pMemory; // ecx
  float *p_z; // edx
  float *v16; // ecx
  unsigned int v17; // eax
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  __m128 v21; // xmm0
  int v22; // eax
  int v23; // edi
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  double v29; // st7
  double v30; // st7
  const CBSPFace *v31; // ebx
  CBSPFace *v32; // eax
  CBSPFace *v33; // eax
  int v34; // eax
  int m_nAllocationCount; // ecx
  int v36; // ebx
  CBSPFace **v37; // ecx
  int v38; // eax
  CBSPFace **v39; // eax
  int v40; // edi
  int v41; // eax
  CBSPFace **v42; // ecx
  int v43; // eax
  CBSPFace **v44; // eax
  Vector *v45; // eax
  Vector *v46; // eax
  int v47; // ecx
  Polygon_t pFront; // [esp+1Ch] [ebp-4Ch] BYREF
  Polygon_t frontPolygon; // [esp+34h] [ebp-34h] BYREF
  Polygon_t backPolygon; // [esp+4Ch] [ebp-1Ch] BYREF
  CBSPFace *vSplitPlaneNormal; // [esp+64h] [ebp-4h] OVERLAPPED
  float v52; // [esp+74h] [ebp+Ch]
  float v53; // [esp+74h] [ebp+Ch]
  CUtlMemory<vgui::TreeNode *,int> *v54; // [esp+74h] [ebp+Ch]
  char v55; // [esp+77h] [ebp+Fh]

  v4 = (CBSPFace *)pFaceList->m_pMemory[nOriginalFaceIndex];
  v5 = &pMapFile->m_TextureInfos.m_Memory.m_pMemory[v4->m_nTextureInfoIndex];
  vSplitPlaneNormal = v4;
  if ( (v5->m_SurfaceFlags & 0x400) == 0 )
  {
    m_pElements = (Vector *)&v5->m_flLightmapVectors[0][1];
    v55 = 0;
    backPolygon.m_Points.m_pElements = m_pElements;
    backPolygon.m_Points.m_Size = 2;
    while ( 1 )
    {
      z = m_pElements[-1].z;
      x = m_pElements->x;
      y_low = SLODWORD(m_pElements->y);
      v10 = (__m128)0x7F7FFFFFu;
      v11 = -3.4028235e38;
      *(float *)&backPolygon.m_Points.__vftable = z;
      *(float *)&backPolygon.m_Points.m_Memory.m_pMemory = x;
      backPolygon.m_Points.m_Memory.m_nAllocationCount = y_low;
      m_Size = v4->m_Polygon.m_Points.m_Size;
      v13 = 0;
      if ( m_Size >= 4 )
      {
        m_pMemory = v4->m_Polygon.m_Points.m_Memory.m_pMemory;
        p_z = &m_pMemory->z;
        v16 = &m_pMemory[1].z;
        v17 = ((unsigned int)(m_Size - 4) >> 2) + 1;
        v13 = 4 * v17;
        do
        {
          v18 = (__m128)*((unsigned int *)p_z - 2);
          v18.m128_f32[0] = (float)((float)(v18.m128_f32[0] * z) + (float)(*(p_z - 1) * x))
                          + (float)(*p_z * *(float *)&y_low);
          if ( v10.m128_f32[0] > v18.m128_f32[0] )
            v10 = v18;
          if ( v18.m128_f32[0] > v11 )
            v11 = v18.m128_f32[0];
          v19 = (__m128)*((unsigned int *)v16 - 1);
          v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * x) + (float)(p_z[1] * z))
                          + (float)(*(float *)&y_low * *v16);
          if ( v10.m128_f32[0] > v19.m128_f32[0] )
            v10 = v19;
          if ( v19.m128_f32[0] > v11 )
            v11 = v19.m128_f32[0];
          v20 = (__m128)*((unsigned int *)v16 + 2);
          v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * x) + (float)(p_z[4] * z))
                          + (float)(v16[3] * *(float *)&y_low);
          if ( v10.m128_f32[0] > v20.m128_f32[0] )
            v10 = v20;
          if ( v20.m128_f32[0] > v11 )
            v11 = v20.m128_f32[0];
          v21 = (__m128)*((unsigned int *)v16 + 5);
          v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * x) + (float)(p_z[7] * z))
                          + (float)(v16[6] * *(float *)&y_low);
          if ( v10.m128_f32[0] > v21.m128_f32[0] )
            v10 = v21;
          if ( v21.m128_f32[0] > v11 )
            v11 = v21.m128_f32[0];
          p_z += 12;
          v16 += 12;
          --v17;
        }
        while ( v17 != 0 );
        v4 = vSplitPlaneNormal;
      }
      if ( v13 < m_Size )
      {
        v22 = (int)&v4->m_Polygon.m_Points.m_Memory.m_pMemory[v13];
        v23 = m_Size - v13;
        do
        {
          v24 = (__m128)*(unsigned int *)(v22 + 4);
          v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * x) + (float)(*(float *)v22 * z))
                          + (float)(*(float *)(v22 + 8) * *(float *)&y_low);
          if ( v10.m128_f32[0] > v24.m128_f32[0] )
            v10 = v24;
          if ( v24.m128_f32[0] > v11 )
            v11 = v24.m128_f32[0];
          v22 += 12;
          --v23;
        }
        while ( v23 != 0 );
      }
      v25.m128_i32[0] = 1258291200;
      v26 = _mm_and_ps((__m128)0x80000000, v10);
      v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v26), v25).m128_f32[0]) & 0x4B000000
                      | v26.m128_i32[0];
      v27 = v10;
      v27.m128_f32[0] = (float)(v10.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
      v28 = v27;
      v28.m128_f32[0] = v27.m128_f32[0] - v10.m128_f32[0];
      *(float *)&backPolygon.m_Points.m_Memory.m_nGrowSize = v27.m128_f32[0]
                                                           - COERCE_FLOAT(_mm_cmpgt_ss(v28, v26).m128_u32[0] & 0x3F800000);
      v29 = ceil(X: v11);
      if ( (int)(v29 - *(float *)&backPolygon.m_Points.m_Memory.m_nGrowSize) > 32 )
      {
        v52 = *(float *)&backPolygon.m_Points.m_Memory.m_nGrowSize + 32.0 - 1.0;
        v30 = VectorNormalize(vec: (Vector *)&backPolygon);
        v31 = vSplitPlaneNormal;
        pFront.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        memset(
          &pFront.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(pFront.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        memset(
          &frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        v53 = v52 / v30;
        ChopPolygon(
          polygon: &vSplitPlaneNormal->m_Polygon,
          vNormal: (const Vector *)&backPolygon,
          flDistance: v53,
          pOn: nullptr,
          &pFront,
          pBack: &frontPolygon);
        if ( (pFront.m_Points.m_Size == 0 || frontPolygon.m_Points.m_Size == 0)
          && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        {
          _LoggingSystem_Log(
            a1: LOG_VBSP2,
            a2: 3,
            a3: "SubdivideFaceForLightmaps: face too big for lightmapping but split operation failed.");
        }
        v32 = (CBSPFace *)operator new(nSize: 0x28u);
        if ( v32 != nullptr )
          v54 = (CUtlMemory<vgui::TreeNode *,int> *)CBSPFace::CBSPFace(this: v32, other: v31, pPolygon: &pFront);
        else
          v54 = nullptr;
        v33 = (CBSPFace *)operator new(nSize: 0x28u);
        if ( v33 != nullptr )
          vSplitPlaneNormal = CBSPFace::CBSPFace(this: v33, other: v31, pPolygon: &frontPolygon);
        else
          vSplitPlaneNormal = nullptr;
        v34 = (int)pFaceList[1].m_pMemory;
        m_nAllocationCount = pFaceList->m_nAllocationCount;
        v36 = v34;
        if ( v34 + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: pFaceList,
            num: v34 - m_nAllocationCount + 1);
        ++pFaceList[1].m_pMemory;
        v37 = (CBSPFace **)pFaceList->m_pMemory;
        v38 = (int)pFaceList[1].m_pMemory - v36 - 1;
        pFaceList[1].m_nAllocationCount = (int)pFaceList->m_pMemory;
        if ( v38 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v37[v36 + 1], src: (unsigned __int8 *)&v37[v36], count: 4 * v38);
        v39 = (CBSPFace **)&pFaceList->m_pMemory[v36];
        if ( v39 != nullptr )
          *v39 = (CBSPFace *)v54;
        v40 = (int)pFaceList[1].m_pMemory;
        v41 = pFaceList->m_nAllocationCount;
        if ( v40 + 1 > v41 )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: pFaceList,
            num: v40 - v41 + 1);
        ++pFaceList[1].m_pMemory;
        v42 = (CBSPFace **)pFaceList->m_pMemory;
        v43 = (int)pFaceList[1].m_pMemory - v40 - 1;
        pFaceList[1].m_nAllocationCount = (int)pFaceList->m_pMemory;
        if ( v43 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v42[v40 + 1], src: (unsigned __int8 *)&v42[v40], count: 4 * v43);
        v44 = (CBSPFace **)&pFaceList->m_pMemory[v40];
        if ( v44 != nullptr )
          *v44 = vSplitPlaneNormal;
        SubdivideFaceForLightmaps(
          pMapFile,
          (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)pFaceList,
          nOriginalFaceIndex: v36);
        SubdivideFaceForLightmaps(
          pMapFile,
          (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)pFaceList,
          nOriginalFaceIndex: v40);
        v45 = frontPolygon.m_Points.m_Memory.m_pMemory;
        vSplitPlaneNormal = (CBSPFace *)pFaceList->m_pMemory[nOriginalFaceIndex];
        v55 = 1;
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        frontPolygon.m_Points.m_Size = 0;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( frontPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: frontPolygon.m_Points.m_Memory.m_pMemory);
            v45 = nullptr;
            frontPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          frontPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        frontPolygon.m_Points.m_pElements = v45;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v45 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v45);
            frontPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          frontPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        v46 = pFront.m_Points.m_Memory.m_pMemory;
        pFront.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        pFront.m_Points.m_Size = 0;
        if ( pFront.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pFront.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pFront.m_Points.m_Memory.m_pMemory);
            v46 = nullptr;
            pFront.m_Points.m_Memory.m_pMemory = nullptr;
          }
          pFront.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        pFront.m_Points.m_pElements = v46;
        if ( pFront.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v46 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46);
            pFront.m_Points.m_Memory.m_pMemory = nullptr;
          }
          pFront.m_Points.m_Memory.m_nAllocationCount = 0;
        }
      }
      backPolygon.m_Points.m_pElements = (Vector *)((char *)backPolygon.m_Points.m_pElements + 16);
      if ( --backPolygon.m_Points.m_Size == 0 )
        break;
      m_pElements = backPolygon.m_Points.m_pElements;
      v4 = vSplitPlaneNormal;
    }
    if ( v55 != 0 )
    {
      v47 = (int)pFaceList[1].m_pMemory;
      if ( v47 > 0 )
      {
        if ( nOriginalFaceIndex != v47 - 1 )
          pFaceList->m_pMemory[nOriginalFaceIndex] = pFaceList->m_pMemory[v47 - 1];
        --pFaceList[1].m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E160
// Name: private: void CSimpleBSPFile::BuildRadialVisibilityData(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildRadialVisibilityData(CSimpleBSPFile *this, CBSPNode *pRootNode)
{
  int v3; // eax
  int m_Size; // esi
  int v5; // eax
  int v6; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v9; // eax
  int v10; // ecx
  int v11; // edx
  const CBSPNode *m_pLeafNode; // eax
  float v13; // xmm2_4
  float x; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // esi
  float v19; // xmm6_4
  float v20; // xmm0_4
  const CBSPNode *v21; // eax
  float y; // xmm4_4
  float z; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  unsigned __int8 *v30; // eax
  Vector vTestMin; // [esp+Ch] [ebp-48h] BYREF
  Vector vTestMax; // [esp+18h] [ebp-3Ch] BYREF
  Vector vTestPoint; // [esp+24h] [ebp-30h] BYREF
  Vector vHalfExtent1; // [esp+30h] [ebp-24h]
  Vector vCenter1; // [esp+3Ch] [ebp-18h]
  int nRowLength; // [esp+48h] [ebp-Ch]
  float flDistanceSquared; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]
  CBSPNode *pRootNodea; // [esp+5Ch] [ebp+8h]

  if ( pRootNode->m_nSplitPlaneIndex == -1 )
  {
    if ( (pRootNode->m_ContentsFlags & 1) == 0 )
    {
      v3 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: (CUtlVector<int,CUtlMemory<int,int> > *)&this->m_Clusters);
      pRootNode->m_nClusterIndex = v3;
      this->m_Clusters.m_Memory.m_pMemory[v3].m_pLeafNode = pRootNode;
    }
  }
  else
  {
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: pRootNode->m_pChildren[0]);
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: pRootNode->m_pChildren[1]);
  }
  m_Size = this->m_Clusters.m_Size;
  v5 = (m_Size + 7) / 8;
  v6 = v5 * m_Size;
  nRowLength = v5;
  this->m_VisibilityData.m_Size = 0;
  if ( v6 != 0 )
  {
    m_nAllocationCount = this->m_VisibilityData.m_Memory.m_nAllocationCount;
    if ( v6 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_VisibilityData.m_Memory, num: v6 - m_nAllocationCount);
    this->m_VisibilityData.m_Size += v6;
    m_pMemory = this->m_VisibilityData.m_Memory.m_pMemory;
    v9 = this->m_VisibilityData.m_Size - v6;
    this->m_VisibilityData.m_pElements = m_pMemory;
    if ( v9 > 0 && v6 > 0 )
      _V_memmove(dest: &m_pMemory[v6], src: m_pMemory, count: v9);
  }
  memset(dst: this->m_VisibilityData.m_Memory.m_pMemory, value: 0, count: this->m_VisibilityData.m_Size);
  v10 = this->m_Clusters.m_Size;
  v11 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    pRootNodea = nullptr;
    do
    {
      m_pLeafNode = this->m_Clusters.m_Memory.m_pMemory[v11].m_pLeafNode;
      v13 = m_pLeafNode->m_vMinBounds.z + m_pLeafNode->m_vMaxBounds.z;
      x = m_pLeafNode->m_vMaxBounds.x;
      v15 = (float)(x + m_pLeafNode->m_vMinBounds.x) * 0.5;
      v16 = (float)(m_pLeafNode->m_vMinBounds.y + m_pLeafNode->m_vMaxBounds.y) * 0.5;
      vHalfExtent1.y = m_pLeafNode->m_vMaxBounds.y - v16;
      v17 = v13 * 0.5;
      v18 = 0;
      v19 = x - v15;
      v20 = m_pLeafNode->m_vMaxBounds.z - v17;
      vCenter1.x = v15;
      vCenter1.y = v16;
      vCenter1.z = v17;
      vHalfExtent1.x = v19;
      vHalfExtent1.z = v20;
      if ( v10 > 0 )
      {
        while ( 1 )
        {
          v21 = this->m_Clusters.m_Memory.m_pMemory[v18].m_pLeafNode;
          y = v21->m_vMaxBounds.y;
          z = v21->m_vMaxBounds.z;
          v24 = (float)(v21->m_vMinBounds.x + v21->m_vMaxBounds.x) * 0.5;
          v25 = (float)(v21->m_vMinBounds.y + y) * 0.5;
          v26 = (float)(v21->m_vMinBounds.z + z) * 0.5;
          v27 = v21->m_vMaxBounds.x;
          vTestPoint.y = vCenter1.y - v25;
          vTestPoint.z = vCenter1.z - v26;
          v28 = (float)(v27 - v24) + v19;
          vTestMin.x = vec3_origin.x - v28;
          v29 = (float)(y - v25) + vHalfExtent1.y;
          vTestMin.y = vec3_origin.y - v29;
          vTestPoint.x = v15 - v24;
          vTestMax.x = v28;
          vTestMax.y = v29;
          vTestMax.z = (float)(z - v26) + vHalfExtent1.z;
          vTestMin.z = vec3_origin.z - vTestMax.z;
          flDistanceSquared = CalcSqrDistanceToAABB(mins: &vTestMin, maxs: &vTestMax, point: &vTestPoint);
          if ( (float)(this->m_flVisibilityRadius * this->m_flVisibilityRadius) > flDistanceSquared )
          {
            v30 = &this->m_VisibilityData.m_Memory.m_pMemory[(unsigned int)pRootNodea + v18 / 8];
            *v30 |= 1 << (v18 % 8);
          }
          if ( ++v18 >= this->m_Clusters.m_Size )
            break;
          v19 = vHalfExtent1.x;
          v15 = vCenter1.x;
        }
        v11 = i;
      }
      v10 = this->m_Clusters.m_Size;
      pRootNodea = (CBSPNode *)((char *)pRootNodea + nRowLength);
      i = ++v11;
    }
    while ( v11 < v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E580
// Name: public: CBSPPortal::~CBSPPortal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPortal::~CBSPPortal(CBSPPortal *this)
{
  int v2; // eax
  CBSPFace *v3; // esi
  Vector *m_pMemory; // eax
  CBSPFace **v5; // eax
  Vector *v6; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_PortalFaces.m_Size; i = v2 )
  {
    v3 = this->m_PortalFaces.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v3->m_Polygon.m_Points.m_Size = 0;
      if ( v3->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Polygon.m_Points.m_Memory.m_pMemory);
          v3->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Polygon.m_Points.m_Memory.m_pMemory;
      v3->m_Polygon.m_Points.m_pElements = m_pMemory;
      if ( v3->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_PortalFaces.m_Size = 0;
  if ( this->m_PortalFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PortalFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PortalFaces.m_Memory.m_pMemory);
      this->m_PortalFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_PortalFaces.m_Memory.m_pMemory;
  this->m_PortalFaces.m_pElements = v5;
  if ( this->m_PortalFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_PortalFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  this->m_Polygon.m_Points.m_Size = 0;
  if ( this->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Polygon.m_Points.m_Memory.m_pMemory);
      this->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    }
    this->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Polygon.m_Points.m_Memory.m_pMemory;
  this->m_Polygon.m_Points.m_pElements = v6;
  if ( this->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    }
    this->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E6B0
// Name: private: void CSimpleBSPFile::BuildNodePortals(class CBSPNode __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildNodePortals(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlMemory<vgui::TreeNode *,int> *pPortalList)
{
  int v3; // ebx
  CBSPPortal **m_pMemory; // ecx
  CBSPPortal *v5; // eax
  int v6; // edi
  int v7; // esi
  CBSPPortal *v8; // eax
  CBSPPortal *v9; // ebx
  int v10; // eax
  CBSPNode *m_pParent; // esi
  CBSPNode *i; // ecx
  const Vector *v13; // eax
  int j; // esi
  CBSPPortal *v15; // eax
  float m_flDistance; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  int m_nAllocationCount; // eax
  CBSPPortal **v20; // ecx
  int v21; // eax
  CBSPPortal **v22; // eax
  bool v23; // cc
  CBSPPortal *v24; // esi
  CBSPNode *v25; // edi
  BOOL v26; // ecx
  int v27; // eax
  float v28; // edx
  int m_Size; // ecx
  CBSPPortal **v30; // edx
  int v31; // ecx
  CBSPNode *v32; // edi
  int v33; // ecx
  int v34; // eax
  CBSPPortal **v35; // edx
  int v36; // ecx
  int m_nGrowSize; // eax
  Vector *v38; // eax
  int v39; // eax
  int v40; // eax
  Vector *m_pElements; // eax
  CBSPPortal *v42; // eax
  vgui::TreeNode *v43; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v44; // edx
  int v45; // edi
  int v46; // eax
  vgui::TreeNode **v47; // ecx
  int v48; // eax
  vgui::TreeNode **v49; // eax
  float v50; // edi
  float z; // esi
  Vector *v52; // eax
  Vector *v53; // eax
  float v54; // [esp+0h] [ebp-74h]
  vgui::TreeNode *v55; // [esp+8h] [ebp-6Ch]
  Polygon_t pBack; // [esp+1Ch] [ebp-58h] BYREF
  Polygon_t pPolygon; // [esp+34h] [ebp-40h] BYREF
  Vector v58; // [esp+4Ch] [ebp-28h] BYREF
  float x; // [esp+58h] [ebp-1Ch] BYREF
  Vector vNormal; // [esp+5Ch] [ebp-18h]
  Vector v61; // [esp+68h] [ebp-Ch]

  LODWORD(v61.y) = this;
  while ( 1 )
  {
    v3 = 0;
    if ( pNode->m_Portals.m_Size > 0 )
    {
      m_pMemory = pNode->m_Portals.m_Memory.m_pMemory;
      do
      {
        v5 = m_pMemory[v3];
        v6 = 0;
        if ( v5->m_Polygon.m_Points.m_Size > 0 )
        {
          v7 = 0;
          do
          {
            AddPointToBounds(
              v: &v5->m_Polygon.m_Points.m_Memory.m_pMemory[v7],
              mins: &pNode->m_vMinBounds,
              maxs: &pNode->m_vMaxBounds);
            m_pMemory = pNode->m_Portals.m_Memory.m_pMemory;
            v5 = m_pMemory[v3];
            ++v6;
            ++v7;
          }
          while ( v6 < v5->m_Polygon.m_Points.m_Size );
        }
        ++v3;
      }
      while ( v3 < pNode->m_Portals.m_Size );
    }
    if ( pNode->m_nSplitPlaneIndex == -1 )
      break;
    v8 = (CBSPPortal *)operator new(nSize: 0x4Cu);
    v9 = nullptr;
    if ( v8 != nullptr )
    {
      v8->m_pOnNode = nullptr;
      v8->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
      v8->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      v8->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
      v8->m_Polygon.m_Points.m_Size = 0;
      v8->m_Polygon.m_Points.m_pElements = nullptr;
      v8->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v8->m_PortalFaces.m_Memory.m_pMemory = nullptr;
      v8->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
      v8->m_PortalFaces.m_Memory.m_nGrowSize = 0;
      v8->m_PortalFaces.m_Size = 0;
      v8->m_PortalFaces.m_pElements = nullptr;
      v8->m_pNodes[1] = nullptr;
      v8->m_pNodes[0] = nullptr;
      v9 = v8;
    }
    v10 = *(_DWORD *)(LODWORD(v61.y) + 8) + 24 * pNode->m_nSplitPlaneIndex;
    v9->m_Plane.m_vNormal.x = *(float *)v10;
    v9->m_Plane.m_vNormal.y = *(float *)(v10 + 4);
    v9->m_Plane.m_vNormal.z = *(float *)(v10 + 8);
    v9->m_Plane.m_flDistance = *(float *)(v10 + 12);
    v9->m_Plane.m_Type = *(_DWORD *)(v10 + 16);
    v9->m_pOnNode = pNode;
    CreatePolygonFromPlane(vNormal: (const Vector *)v10, flDistance: *(float *)(v10 + 12), pPolygon: &v9->m_Polygon);
    m_pParent = pNode->m_pParent;
    for ( i = pNode; m_pParent != nullptr; m_pParent = m_pParent->m_pParent )
    {
      v13 = (const Vector *)(*(_DWORD *)(LODWORD(v61.y) + 8) + 24 * m_pParent->m_nSplitPlaneIndex);
      if ( m_pParent->m_pChildren[0] == i )
      {
        ChopPolygonInPlace(pPolygon: &v9->m_Polygon, vNormal: v13, flDistance: v13[1].x);
      }
      else
      {
        v58.x = -v13->x;
        v58.y = -v13->y;
        v58.z = -v13->z;
        ChopPolygonInPlace(pPolygon: &v9->m_Polygon, vNormal: &v58, flDistance: -v13[1].x);
      }
      i = m_pParent;
    }
    for ( j = 0; j < pNode->m_Portals.m_Size; ++j )
    {
      v15 = pNode->m_Portals.m_Memory.m_pMemory[j];
      if ( v15->m_pNodes[0] == pNode )
      {
        x = v15->m_Plane.m_vNormal.x;
        vNormal.x = v15->m_Plane.m_vNormal.y;
        vNormal.y = v15->m_Plane.m_vNormal.z;
        m_flDistance = v15->m_Plane.m_flDistance;
      }
      else
      {
        v17 = -v15->m_Plane.m_vNormal.y;
        v18 = -v15->m_Plane.m_vNormal.z;
        x = -v15->m_Plane.m_vNormal.x;
        vNormal.x = v17;
        vNormal.y = v18;
        m_flDistance = -v15->m_Plane.m_flDistance;
      }
      ChopPolygonInPlace(pPolygon: &v9->m_Polygon, vNormal: (const Vector *)&x, flDistance: m_flDistance);
    }
    if ( v9->m_Polygon.m_Points.m_Size == 0 || IsPolygonTiny(pPolygon: &v9->m_Polygon) )
    {
      CBSPPortal::~CBSPPortal(this: v9);
      free(pMem: v9);
    }
    else
    {
      AttachPortalToNodes(
        pNode0: (vgui::TreeNode_vtbl *)pNode->m_pChildren[0],
        pPortal: (vgui::TreeNode *)v9,
        pNode1: pNode->m_pChildren[1]);
      m_nAllocationCount = pPortalList->m_nAllocationCount;
      LODWORD(v61.z) = pPortalList[1].m_pMemory;
      if ( LODWORD(v61.z) + 1 > m_nAllocationCount )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: pPortalList,
          num: LODWORD(v61.z) - m_nAllocationCount + 1);
      ++pPortalList[1].m_pMemory;
      v20 = (CBSPPortal **)pPortalList->m_pMemory;
      v21 = (int)pPortalList[1].m_pMemory - LODWORD(v61.z) - 1;
      pPortalList[1].m_nAllocationCount = (int)pPortalList->m_pMemory;
      if ( v21 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v20[LODWORD(v61.z) + 1],
          src: (unsigned __int8 *)&v20[LODWORD(v61.z)],
          count: 4 * v21);
      v22 = (CBSPPortal **)&pPortalList->m_pMemory[LODWORD(v61.z)];
      if ( v22 != nullptr )
        *v22 = v9;
    }
    v23 = pNode->m_Portals.m_Size <= 0;
    LODWORD(vNormal.z) = *(_DWORD *)(LODWORD(v61.y) + 8) + 24 * pNode->m_nSplitPlaneIndex;
    if ( !v23 )
    {
      do
      {
        v24 = *pNode->m_Portals.m_Memory.m_pMemory;
        v25 = v24->m_pNodes[0];
        v26 = v24->m_pNodes[0] == pNode;
        LODWORD(v61.x) = v24->m_pNodes[0] != pNode;
        v27 = 0;
        v28 = *(float *)&v24->m_pNodes[v26];
        m_Size = v25->m_Portals.m_Size;
        v61.z = v28;
        if ( m_Size > 0 )
        {
          v30 = v25->m_Portals.m_Memory.m_pMemory;
          while ( *v30 != v24 )
          {
            ++v27;
            ++v30;
            if ( v27 >= m_Size )
              goto LABEL_40;
          }
          if ( v27 != -1 )
          {
            v31 = m_Size - v27 - 1;
            if ( v31 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v25->m_Portals.m_Memory.m_pMemory[v27],
                src: (unsigned __int8 *)&v25->m_Portals.m_Memory.m_pMemory[v27 + 1],
                count: 4 * v31);
            --v25->m_Portals.m_Size;
          }
        }
LABEL_40:
        v32 = v24->m_pNodes[1];
        v33 = v32->m_Portals.m_Size;
        v34 = 0;
        if ( v33 > 0 )
        {
          v35 = v32->m_Portals.m_Memory.m_pMemory;
          while ( *v35 != v24 )
          {
            ++v34;
            ++v35;
            if ( v34 >= v33 )
              goto LABEL_49;
          }
          if ( v34 != -1 )
          {
            v36 = v33 - v34 - 1;
            if ( v36 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v32->m_Portals.m_Memory.m_pMemory[v34],
                src: (unsigned __int8 *)&v32->m_Portals.m_Memory.m_pMemory[v34 + 1],
                count: 4 * v36);
            --v32->m_Portals.m_Size;
          }
        }
LABEL_49:
        v24->m_pNodes[1] = nullptr;
        v24->m_pNodes[0] = nullptr;
        pPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        pBack.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        v54 = *(float *)(LODWORD(vNormal.z) + 12);
        memset(
          &pPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(pPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        memset(
          &pBack.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(pBack.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        ChopPolygon(
          polygon: &v24->m_Polygon,
          vNormal: (const Vector *)LODWORD(vNormal.z),
          flDistance: v54,
          pOn: nullptr,
          pFront: &pPolygon,
          &pBack);
        if ( IsPolygonTiny(&pPolygon) )
          pPolygon.m_Points.m_Size = 0;
        if ( IsPolygonTiny(pPolygon: &pBack) )
          pBack.m_Points.m_Size = 0;
        if ( pPolygon.m_Points.m_Size != 0 )
        {
          if ( pBack.m_Points.m_Size != 0 )
          {
            m_nGrowSize = v24->m_Polygon.m_Points.m_Memory.m_nGrowSize;
            v24->m_Polygon.m_Points.m_Memory.m_nGrowSize = pPolygon.m_Points.m_Memory.m_nGrowSize;
            pPolygon.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
            v38 = v24->m_Polygon.m_Points.m_Memory.m_pMemory;
            v24->m_Polygon.m_Points.m_Memory.m_pMemory = pPolygon.m_Points.m_Memory.m_pMemory;
            pPolygon.m_Points.m_Memory.m_pMemory = v38;
            v39 = v24->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
            v24->m_Polygon.m_Points.m_Memory.m_nAllocationCount = pPolygon.m_Points.m_Memory.m_nAllocationCount;
            pPolygon.m_Points.m_Memory.m_nAllocationCount = v39;
            v40 = v24->m_Polygon.m_Points.m_Size;
            v24->m_Polygon.m_Points.m_Size = pPolygon.m_Points.m_Size;
            pPolygon.m_Points.m_Size = v40;
            m_pElements = v24->m_Polygon.m_Points.m_pElements;
            v24->m_Polygon.m_Points.m_pElements = pPolygon.m_Points.m_pElements;
            pPolygon.m_Points.m_pElements = m_pElements;
            v42 = (CBSPPortal *)operator new(nSize: 0x4Cu);
            if ( v42 != nullptr )
              v43 = (vgui::TreeNode *)CBSPPortal::CBSPPortal(this: v42, other: v24, pPortalShape: &pBack);
            else
              v43 = nullptr;
            v44 = pPortalList;
            v45 = (int)pPortalList[1].m_pMemory;
            v46 = pPortalList->m_nAllocationCount;
            if ( v45 + 1 > v46 )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: pPortalList,
                num: v45 - v46 + 1);
              v44 = pPortalList;
            }
            ++v44[1].m_pMemory;
            v47 = v44->m_pMemory;
            v48 = (int)v44[1].m_pMemory - v45 - 1;
            v44[1].m_nAllocationCount = (int)v44->m_pMemory;
            if ( v48 > 0 )
            {
              _V_memmove(dest: (unsigned __int8 *)&v47[v45 + 1], src: (unsigned __int8 *)&v47[v45], count: 4 * v48);
              v44 = pPortalList;
            }
            v49 = &v44->m_pMemory[v45];
            if ( v49 != nullptr )
              *v49 = v43;
            if ( LODWORD(v61.x) != 0 )
            {
              v55 = (vgui::TreeNode *)v24;
              z = v61.z;
              AttachPortalToNodes(
                pNode0: (vgui::TreeNode_vtbl *)LODWORD(v61.z),
                pPortal: v55,
                pNode1: pNode->m_pChildren[0]);
              AttachPortalToNodes(
                pNode0: (vgui::TreeNode_vtbl *)LODWORD(z),
                pPortal: v43,
                pNode1: pNode->m_pChildren[1]);
            }
            else
            {
              v50 = v61.z;
              AttachPortalToNodes(
                pNode0: (vgui::TreeNode_vtbl *)pNode->m_pChildren[0],
                pPortal: (vgui::TreeNode *)v24,
                pNode1: (CBSPNode *)LODWORD(v61.z));
              AttachPortalToNodes(
                pNode0: (vgui::TreeNode_vtbl *)pNode->m_pChildren[1],
                pPortal: v43,
                pNode1: (CBSPNode *)LODWORD(v50));
            }
          }
          else if ( LODWORD(v61.x) != 0 )
          {
            AttachPortalToNodes(
              pNode0: (vgui::TreeNode_vtbl *)LODWORD(v61.z),
              pPortal: (vgui::TreeNode *)v24,
              pNode1: pNode->m_pChildren[0]);
          }
          else
          {
            AttachPortalToNodes(
              pNode0: (vgui::TreeNode_vtbl *)pNode->m_pChildren[0],
              pPortal: (vgui::TreeNode *)v24,
              pNode1: (CBSPNode *)LODWORD(v61.z));
          }
        }
        else if ( LODWORD(v61.x) != 0 )
        {
          AttachPortalToNodes(
            pNode0: (vgui::TreeNode_vtbl *)LODWORD(v61.z),
            pPortal: (vgui::TreeNode *)v24,
            pNode1: pNode->m_pChildren[1]);
        }
        else
        {
          AttachPortalToNodes(
            pNode0: (vgui::TreeNode_vtbl *)pNode->m_pChildren[1],
            pPortal: (vgui::TreeNode *)v24,
            pNode1: (CBSPNode *)LODWORD(v61.z));
        }
        v52 = pBack.m_Points.m_Memory.m_pMemory;
        pBack.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        pBack.m_Points.m_Size = 0;
        if ( pBack.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pBack.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBack.m_Points.m_Memory.m_pMemory);
            v52 = nullptr;
            pBack.m_Points.m_Memory.m_pMemory = nullptr;
          }
          pBack.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        pBack.m_Points.m_pElements = v52;
        if ( pBack.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v52 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v52);
            pBack.m_Points.m_Memory.m_pMemory = nullptr;
          }
          pBack.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        v53 = pPolygon.m_Points.m_Memory.m_pMemory;
        pPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        pPolygon.m_Points.m_Size = 0;
        if ( pPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( pPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pPolygon.m_Points.m_Memory.m_pMemory);
            v53 = nullptr;
            pPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          pPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        pPolygon.m_Points.m_pElements = v53;
        if ( pPolygon.m_Points.m_Memory.m_nGrowSize >= 0 && v53 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53);
      }
      while ( pNode->m_Portals.m_Size > 0 );
    }
    CSimpleBSPFile::BuildNodePortals(
      this: (CSimpleBSPFile *)LODWORD(v61.y),
      pNode: pNode->m_pChildren[0],
      (CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *)pPortalList);
    pNode = pNode->m_pChildren[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F190
// Name: private: void CSimpleBSPFile::BuildTreePortals(class CBSPTree __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSimpleBSPFile::BuildTreePortals(
        CSimpleBSPFile *this,
        CBSPTree *pTree,
        CUtlMemory<vgui::TreeNode *,int> *pPortalList)
{
  _DWORD *v3; // esi
  int i; // ebx
  char *v5; // edi
  _DWORD *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float *v9; // ecx
  const Vector *v10; // eax
  int j; // ebx
  int v12; // esi
  const Vector *v13; // edi
  int m_pMemory; // edi
  int m_nAllocationCount; // ecx
  CBSPPortal **v16; // ecx
  int v17; // eax
  int v18; // ecx
  float *v19; // eax
  CBSPPortal **v20; // edi
  _BYTE dst[128]; // [esp+Ch] [ebp-B0h] OVERLAPPED BYREF
  Vector vBounds[2]; // [esp+8Ch] [ebp-30h]
  CBSPPortal *pPortals[6]; // [esp+A4h] [ebp-18h]

  pPortals[4] = (CBSPPortal *)this;
  *(float *)&dst[120] = pTree->m_vMinBounds.x - 8.0;
  vBounds[0].y = pTree->m_vMaxBounds.x + 8.0;
  *(float *)&dst[124] = pTree->m_vMinBounds.y - 8.0;
  vBounds[0].z = pTree->m_vMaxBounds.y + 8.0;
  vBounds[0].x = pTree->m_vMinBounds.z - 8.0;
  v3 = nullptr;
  vBounds[1].x = pTree->m_vMaxBounds.z + 8.0;
  memset(dst, value: 0, count: 0x78u);
  pPortals[5] = nullptr;
  for ( i = 0; ; i = 0 )
  {
    while ( 1 )
    {
      v5 = (char *)pPortals[5] + 2 * i + i;
      v6 = operator new(nSize: 0x4Cu);
      if ( v6 != nullptr )
      {
        v6[2] = 0;
        v6[4] = 0;
        v6[5] = 0;
        v6[6] = 0;
        v6[7] = 0;
        v6[8] = 0;
        v6[3] = &CCopyableUtlVector<Vector>::`vftable';
        v6[14] = 0;
        v6[15] = 0;
        v6[16] = 0;
        v6[17] = 0;
        v6[18] = 0;
        v6[1] = 0;
        *v6 = 0;
        v3 = v6;
      }
      *((_DWORD *)&vBounds[1].y + (_DWORD)v5) = v3;
      v7 = i != 0 ? -1.0 : 1.0;
      v8 = *(float *)&dst[4 * (_DWORD)v5 + 120];
      *(float *)&dst[4 * (_DWORD)&v5[(unsigned int)&pPortals[5]->m_pNodes[(_DWORD)v5]]] = v7;
      v9 = (float *)&dst[20 * (_DWORD)v5 + 12];
      v10 = (const Vector *)&dst[20 * (_DWORD)v5];
      *v9 = v8 * v7;
      *((float *)v3 + 9) = v10->x;
      *((float *)v3 + 10) = v10->y;
      *((float *)v3 + 11) = v10->z;
      *((float *)v3 + 12) = v10[1].x;
      v3[13] = LODWORD(v10[1].y);
      CreatePolygonFromPlane(vNormal: v10, flDistance: *v9, pPolygon: (Polygon_t *)(v3 + 3));
      AttachPortalToNodes(
        pNode0: (vgui::TreeNode_vtbl *)pTree->m_pRoot,
        pPortal: (vgui::TreeNode *)v3,
        pNode1: &pTree->m_OutsideNode);
      if ( ++i >= 2 )
        break;
      v3 = nullptr;
    }
    if ( (int)++pPortals[5] >= 3 )
      break;
    v3 = nullptr;
  }
  for ( j = 0; j < 6; ++j )
  {
    v12 = 0;
    v13 = (const Vector *)dst;
    do
    {
      if ( j != v12 )
        ChopPolygonInPlace(
          pPolygon: (Polygon_t *)(*((_DWORD *)&vBounds[1].y + j) + 12),
          vNormal: v13,
          flDistance: v13[1].x);
      ++v12;
      v13 = (const Vector *)((char *)v13 + 20);
    }
    while ( v12 < 6 );
  }
  m_pMemory = (int)pPortalList[1].m_pMemory;
  m_nAllocationCount = pPortalList->m_nAllocationCount;
  if ( m_pMemory + 6 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: pPortalList,
      num: m_pMemory - m_nAllocationCount + 6);
  pPortalList[1].m_pMemory = (vgui::TreeNode **)((char *)pPortalList[1].m_pMemory + 6);
  v16 = (CBSPPortal **)pPortalList->m_pMemory;
  v17 = (int)pPortalList[1].m_pMemory - m_pMemory - 6;
  pPortalList[1].m_nAllocationCount = (int)pPortalList->m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v16[m_pMemory + 6], src: (unsigned __int8 *)&v16[m_pMemory], count: 4 * v17);
  v18 = m_pMemory;
  v19 = (float *)&pPortalList->m_pMemory[m_pMemory];
  if ( v19 != nullptr )
    *v19 = vBounds[1].y;
  if ( &pPortalList->m_pMemory[v18] != (vgui::TreeNode **)-4 )
    pPortalList->m_pMemory[v18 + 1] = (vgui::TreeNode *)LODWORD(vBounds[1].z);
  if ( &pPortalList->m_pMemory[m_pMemory] != (vgui::TreeNode **)-8 )
    pPortalList->m_pMemory[m_pMemory + 2] = (vgui::TreeNode *)pPortals[0];
  if ( &pPortalList->m_pMemory[m_pMemory] != (vgui::TreeNode **)-12 )
    pPortalList->m_pMemory[m_pMemory + 3] = (vgui::TreeNode *)pPortals[1];
  if ( &pPortalList->m_pMemory[m_pMemory] != (vgui::TreeNode **)-16 )
    pPortalList->m_pMemory[m_pMemory + 4] = (vgui::TreeNode *)pPortals[2];
  v20 = (CBSPPortal **)&pPortalList->m_pMemory[m_pMemory + 5];
  if ( v20 != nullptr )
    *v20 = pPortals[3];
  CSimpleBSPFile::BuildNodePortals(this: (CSimpleBSPFile *)pPortals[4], pNode: pTree->m_pRoot, pPortalList);
}

//------------------------------------------------------------------------------
// Address: 0x1005F420
// Name: public: CSimpleBSPFile::CSimpleBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
CSimpleBSPFile *__thiscall CSimpleBSPFile::CSimpleBSPFile(CSimpleBSPFile *this)
{
  this->m_pMapFile = nullptr;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_Models.m_Memory.m_pMemory = nullptr;
  this->m_Models.m_Memory.m_nAllocationCount = 0;
  this->m_Models.m_Memory.m_nGrowSize = 0;
  this->m_Models.m_Size = 0;
  this->m_Models.m_pElements = nullptr;
  this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementFaces.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementFaces.m_Size = 0;
  this->m_DisplacementFaces.m_pElements = nullptr;
  this->m_Clusters.m_Memory.m_pMemory = nullptr;
  this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  this->m_Clusters.m_Memory.m_nGrowSize = 0;
  this->m_Clusters.m_Size = 0;
  this->m_Clusters.m_pElements = nullptr;
  this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
  this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  this->m_VisibilityData.m_Memory.m_nGrowSize = 0;
  this->m_VisibilityData.m_Size = 0;
  this->m_VisibilityData.m_pElements = nullptr;
  this->m_nNextFaceIndex = 0;
  this->m_flVisibilityRadius = 2500.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005F4D0
// Name: private: void CSimpleBSPFile::MakeFacesFromPortals(class CBSPModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::MakeFacesFromPortals(CSimpleBSPFile *this, CBSPModel *pModel)
{
  CBSPModel *v2; // ecx
  int v3; // eax
  CBSPPortal *v4; // esi
  CBSPNode *m_pOnNode; // edi
  int v6; // edx
  int v7; // eax
  CBSPNode *v8; // eax
  CBSPBrush **m_pMemory; // edx
  const MapBrush_t *m_pOriginalBrush; // eax
  int m_nNumSides; // ecx
  MapBrushSide_t *v12; // eax
  int v13; // eax
  CBSPFace *v14; // eax
  CBSPFace *v15; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPFace **v18; // ecx
  int v19; // eax
  CBSPFace **v20; // ebx
  int m_ContentsFlags; // edx
  int v22; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // ebx
  int v27; // ecx
  int v28; // edx
  unsigned int v29; // ebx
  Vector *v30; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector *v34; // eax
  Vector *v35; // esi
  float v36; // xmm0_4
  int v37; // xmm1_4
  int v38; // xmm2_4
  Vector *v39; // esi
  Vector *v40; // esi
  float v41; // xmm0_4
  int v42; // xmm1_4
  int v43; // xmm2_4
  Vector *v44; // esi
  Vector *v45; // esi
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  Vector *v49; // esi
  int v50; // ecx
  int v51; // edx
  int v52; // esi
  Vector *v53; // eax
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float *p_x; // eax
  int nPortal; // [esp+0h] [ebp-18h]
  int nPortalSide; // [esp+4h] [ebp-14h]
  int nPortalSidea; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  int ia; // [esp+8h] [ebp-10h]
  CBSPPortal *pPortal; // [esp+10h] [ebp-8h]
  int nNumPoints; // [esp+14h] [ebp-4h]
  int nNumPointsa; // [esp+14h] [ebp-4h]

  v2 = pModel;
  v3 = 0;
  for ( nPortal = 0; v3 < pModel->m_Portals.m_Size; nPortal = v3 )
  {
    v4 = v2->m_Portals.m_Memory.m_pMemory[v3];
    m_pOnNode = v4->m_pOnNode;
    v6 = 0;
    pPortal = v4;
    if ( m_pOnNode != nullptr )
    {
      v7 = 1;
      while ( ((v4->m_pNodes[1]->m_ContentsFlags ^ v4->m_pNodes[0]->m_ContentsFlags) & v7) == 0 )
      {
        v7 *= 2;
        if ( v7 > 128 )
          goto LABEL_48;
      }
      if ( v7 != 0 )
      {
        nNumPoints = 0;
        nPortalSide = 0;
        do
        {
          v8 = v4->m_pNodes[v6];
          if ( v8->m_ClippedBrushes.m_Size > 0 )
          {
            m_pMemory = v8->m_ClippedBrushes.m_Memory.m_pMemory;
            i = v8->m_ClippedBrushes.m_Size;
            do
            {
              m_pOriginalBrush = (*m_pMemory)->m_pOriginalBrush;
              m_nNumSides = m_pOriginalBrush->m_nNumSides;
              if ( m_nNumSides > 0 )
              {
                v12 = &this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[m_pOriginalBrush->m_nFirstSideIndex];
                do
                {
                  if ( v12->m_nTextureInfoIndex != -1
                    && (v12->m_nPlaneIndex & 0xFFFFFFFE) == m_pOnNode->m_nSplitPlaneIndex )
                  {
                    nNumPoints = (int)v12;
                  }
                  ++v12;
                  --m_nNumSides;
                }
                while ( m_nNumSides != 0 );
              }
              ++m_pMemory;
              --i;
            }
            while ( i != 0 );
            v6 = nPortalSide;
          }
          nPortalSide = ++v6;
        }
        while ( v6 < 2 );
        if ( nNumPoints != 0 )
        {
          v13 = *(_DWORD *)(nNumPoints + 12);
          if ( v13 != -1 && SLOBYTE(this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[v13].m_SurfaceFlags) >= 0 )
          {
            v14 = (CBSPFace *)operator new(nSize: 0x28u);
            v15 = nullptr;
            if ( v14 != nullptr )
            {
              v14->m_nTextureInfoIndex = -1;
              v14->m_nPlaneIndex = -1;
              v14->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
              v14->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
              v14->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
              v14->m_Polygon.m_Points.m_Size = 0;
              v14->m_Polygon.m_Points.m_pElements = nullptr;
              v14->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
              v14->m_nDisplacementIndex = -1;
              v14->m_nSerializedFaceIndex = -1;
              v15 = v14;
            }
            v15->m_nTextureInfoIndex = *(_DWORD *)(nNumPoints + 12);
            v15->m_nPlaneIndex = v4->m_pOnNode->m_nSplitPlaneIndex;
            m_Size = v4->m_PortalFaces.m_Size;
            m_nAllocationCount = v4->m_PortalFaces.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v4->m_PortalFaces,
                num: m_Size - m_nAllocationCount + 1);
            ++v4->m_PortalFaces.m_Size;
            v18 = v4->m_PortalFaces.m_Memory.m_pMemory;
            v19 = v4->m_PortalFaces.m_Size - m_Size - 1;
            v4->m_PortalFaces.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v18[m_Size + 1],
                src: (unsigned __int8 *)&v18[m_Size],
                count: 4 * v19);
            v20 = &v4->m_PortalFaces.m_Memory.m_pMemory[m_Size];
            if ( v20 != nullptr )
              *v20 = v15;
            m_ContentsFlags = v4->m_pNodes[0]->m_ContentsFlags;
            v22 = 1;
            while ( ((m_ContentsFlags ^ v4->m_pNodes[1]->m_ContentsFlags) & v22) == 0 )
            {
              v22 *= 2;
              if ( v22 > 128 )
              {
                v22 = 0;
                break;
              }
            }
            if ( (m_ContentsFlags & v22) != 0 )
            {
              if ( v4 == (CBSPPortal *)-12 )
                v23 = nullptr;
              else
                v23 = &v4->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: v23);
              v24 = v15->m_Polygon.m_Points.m_Size;
              v15->m_nPlaneIndex |= 1u;
              v25 = v24 / 2;
              v26 = 0;
              nNumPointsa = v24;
              nPortalSidea = v24 / 2;
              if ( v24 / 2 >= 4 )
              {
                v27 = 0;
                v28 = 4 * (3 * v24 - 9);
                v29 = ((unsigned int)(v25 - 4) >> 2) + 1;
                ia = 4 * v29;
                do
                {
                  v30 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  x = v30[v27].x;
                  y = v30[v27].y;
                  z = v30[v27].z;
                  v30[v27].x = *(float *)((char *)&v30[2].x + v28);
                  v27 += 4;
                  *((float *)&v30[v27 - 3] - 2) = *(float *)((char *)&v30[2].y + v28);
                  *((float *)&v30[v27 - 3] - 1) = *(float *)((char *)&v30[2].z + v28);
                  v34 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v34[2].x + v28) = x;
                  *(float *)((char *)&v34[2].y + v28) = y;
                  *(float *)((char *)&v34[2].z + v28) = z;
                  v35 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v36 = v35[v27 - 3].x;
                  v37 = *((_DWORD *)&v35[v27 - 2] - 2);
                  v38 = *((_DWORD *)&v35[v27 - 2] - 1);
                  v35[v27 - 3].x = *(float *)((char *)&v35[1].x + v28);
                  *((float *)&v35[v27 - 2] - 2) = *(float *)((char *)&v35[1].y + v28);
                  v28 -= 48;
                  --v29;
                  *((float *)&v35[v27 - 2] - 1) = *(float *)((char *)&v35[5].z + v28);
                  v39 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v39[5].x + v28) = v36;
                  *(_DWORD *)((char *)&v39[5].y + v28) = v37;
                  *(_DWORD *)((char *)&v39[5].z + v28) = v38;
                  v40 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v41 = v40[v27 - 2].x;
                  v42 = *((_DWORD *)&v40[v27 - 1] - 2);
                  v43 = *((_DWORD *)&v40[v27 - 1] - 1);
                  v40[v27 - 2].x = *(float *)((char *)&v40[4].x + v28);
                  *((float *)&v40[v27 - 1] - 2) = *(float *)((char *)&v40[4].y + v28);
                  *((float *)&v40[v27 - 1] - 1) = *(float *)((char *)&v40[4].z + v28);
                  v44 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v44[4].x + v28) = v41;
                  *(_DWORD *)((char *)&v44[4].y + v28) = v42;
                  *(_DWORD *)((char *)&v44[4].z + v28) = v43;
                  v45 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v46 = v45[v27 - 1].x;
                  v47 = v45[v27 - 1].y;
                  v48 = v45[v27 - 1].z;
                  v45[v27 - 1].x = *(float *)((char *)&v45[3].x + v28);
                  v45[v27 - 1].y = *(float *)((char *)&v45[3].y + v28);
                  v45[v27 - 1].z = *(float *)((char *)&v45[3].z + v28);
                  v49 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v49[3].x + v28) = v46;
                  *(float *)((char *)&v49[3].y + v28) = v47;
                  *(float *)((char *)&v49[3].z + v28) = v48;
                }
                while ( v29 != 0 );
                v25 = nPortalSidea;
                v26 = ia;
                v24 = nNumPointsa;
              }
              if ( v26 < v25 )
              {
                v50 = v26;
                v51 = v24 - v26;
                v52 = v25 - v26;
                do
                {
                  v53 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v54 = v53[v50].x;
                  v55 = v53[v50].y;
                  v56 = v53[v50].z;
                  v53[v50++].x = v53[v51 - 1].x;
                  v53[v50 - 1].y = v53[v51 - 1].y;
                  v53[v50 - 1].z = v53[v51 - 1].z;
                  p_x = &v15->m_Polygon.m_Points.m_Memory.m_pMemory[--v51].x;
                  --v52;
                  *p_x = v54;
                  p_x[1] = v55;
                  p_x[2] = v56;
                }
                while ( v52 != 0 );
              }
              v4 = pPortal;
            }
            else if ( v4 == (CBSPPortal *)-12 )
            {
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: nullptr);
            }
            else
            {
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: &v4->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
            }
            SubdivideFaceForLightmaps(
              pMapFile: this->m_pMapFile,
              pFaceList: (CUtlMemory<vgui::TreeNode *,int> *)&v4->m_PortalFaces,
              nOriginalFaceIndex: 0);
            CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int>>::InsertMultipleBefore(
              this: &v4->m_pOnNode->m_Faces,
              elem: v4->m_pOnNode->m_Faces.m_Size,
              num: v4->m_PortalFaces.m_Size,
              pToInsert: v4->m_PortalFaces.m_Memory.m_pMemory);
          }
        }
      }
    }
LABEL_48:
    v2 = pModel;
    v3 = nPortal + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F8E0
// Name: private: void CSimpleBSPFile::CreateDisplacementFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateDisplacementFaces(CSimpleBSPFile *this)
{
  int m_Size; // esi
  int v3; // esi
  MapBrushSide_t *v4; // eax
  bool v5; // zf
  Polygon_t *p_m_Polygon; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v7; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  m_Size = this->m_pMapFile->m_Displacements.m_Size;
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(this: &this->m_DisplacementFaces);
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::InsertMultipleBefore(
    this: &this->m_DisplacementFaces,
    elem: this->m_DisplacementFaces.m_Size,
    num: m_Size);
  v3 = 0;
  i = 0;
  if ( this->m_DisplacementFaces.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v4 = &this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[this->m_pMapFile->m_Displacements.m_Memory.m_pMemory[v9].m_nOriginalBrushSide];
      v5 = &v4->m_Polygon == nullptr;
      p_m_Polygon = &v4->m_Polygon;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nTextureInfoIndex = (int)p_m_Polygon[-1].m_Points.m_pElements;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nPlaneIndex = p_m_Polygon[-1].m_Points.m_Size;
      if ( v5 )
        v7 = nullptr;
      else
        v7 = &p_m_Polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: &this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        other: v7);
      ++v9;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nDisplacementIndex = i;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3++].m_nSerializedFaceIndex = this->m_nNextFaceIndex++;
      ++i;
    }
    while ( i < this->m_DisplacementFaces.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005FB80
// Name: public: CBSPBrush::CBSPBrush(class CBSPBrush const __near &)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CBSPBrush::CBSPBrush(CBSPBrush *this, const CBSPBrush *__that)
{
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v3; // ecx

  this->m_vMinBounds = __that->m_vMinBounds;
  this->m_vMaxBounds = __that->m_vMaxBounds;
  v3 = &this->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
  v3->m_Memory.m_pMemory = nullptr;
  v3->m_Memory.m_nAllocationCount = 0;
  v3->m_Memory.m_nGrowSize = 0;
  v3->m_Size = 0;
  v3->m_pElements = nullptr;
  this->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
    this: v3,
    pArray: __that->m_Sides.m_Memory.m_pMemory,
    size: __that->m_Sides.m_Size);
  this->m_ContentsFlags = __that->m_ContentsFlags;
  this->m_pOriginalBrush = __that->m_pOriginalBrush;
  this->m_nTempSplitSide = __that->m_nTempSplitSide;
  this->m_nSplitSide = __that->m_nSplitSide;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005FBF0
// Name: public: CBSPNode::~CBSPNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPNode::~CBSPNode(CBSPNode *this)
{
  CBSPNode *v2; // edi
  CBSPNode *v3; // edi
  int v4; // eax
  CBSPBrush *v5; // edi
  CBSPBrushSide *m_pMemory; // eax
  CBSPPortal **v7; // eax
  CBSPFace **v8; // eax
  CBSPBrush **v9; // eax
  int i; // [esp+10h] [ebp-4h]

  v2 = this->m_pChildren[0];
  if ( v2 != nullptr )
  {
    CBSPNode::~CBSPNode(this: this->m_pChildren[0]);
    free(pMem: v2);
  }
  v3 = this->m_pChildren[1];
  if ( v3 != nullptr )
  {
    CBSPNode::~CBSPNode(this: this->m_pChildren[1]);
    free(pMem: v3);
  }
  v4 = 0;
  for ( i = 0; v4 < this->m_ClippedBrushes.m_Size; i = v4 )
  {
    v5 = this->m_ClippedBrushes.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v5->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
      if ( v5->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5->m_Sides.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Sides.m_Memory.m_pMemory);
          v5->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v5->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v5->m_Sides.m_Memory.m_pMemory;
      v5->m_Sides.m_pElements = m_pMemory;
      if ( v5->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v5->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v5->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v5);
      v4 = i;
    }
    ++v4;
  }
  this->m_Portals.m_Size = 0;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Portals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Portals.m_Memory.m_pMemory);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_Portals.m_Memory.m_pMemory;
  this->m_Portals.m_pElements = v7;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Faces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Faces.m_Memory.m_pMemory);
      this->m_Faces.m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_pElements = v8;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_Faces.m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ClippedBrushes.m_Size = 0;
  if ( this->m_ClippedBrushes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ClippedBrushes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ClippedBrushes.m_Memory.m_pMemory);
      this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
    }
    this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_ClippedBrushes.m_Memory.m_pMemory;
  this->m_ClippedBrushes.m_pElements = v9;
  if ( this->m_ClippedBrushes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
    }
    this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005FDA0
// Name: public: CBSPBrush::CBSPBrush(struct MapBrush_t const __near *,struct MapBrushSide_t const __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CBSPBrush::CBSPBrush(
        CBSPBrush *this,
        const MapBrush_t *pMapBrush,
        const MapBrushSide_t *pMapBrushSides)
{
  int v5; // eax
  const MapBrushSide_t *v6; // eax
  int m_nTextureInfoIndex; // edx
  __int16 m_SurfaceFlags; // cx
  int m_Size; // edx
  const Vector *m_pMemory; // eax
  CBSPBrushSide src; // [esp+4h] [ebp-24h] BYREF
  int i; // [esp+30h] [ebp+8h]

  this->m_vMinBounds = pMapBrush->m_vMinBounds;
  this->m_vMaxBounds = pMapBrush->m_vMaxBounds;
  this->m_Sides.m_Memory.m_pMemory = nullptr;
  this->m_Sides.m_Memory.m_nAllocationCount = 0;
  this->m_Sides.m_Memory.m_nGrowSize = 0;
  this->m_Sides.m_Size = 0;
  this->m_Sides.m_pElements = nullptr;
  this->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
  this->m_ContentsFlags = pMapBrush->m_ContentsFlags;
  this->m_pOriginalBrush = pMapBrush;
  this->m_nTempSplitSide = PLANE_SIDE_INVALID;
  this->m_nSplitSide = PLANE_SIDE_INVALID;
  for ( i = 0; i < pMapBrush->m_nNumSides; ++i )
  {
    v5 = i + pMapBrush->m_nFirstSideIndex;
    memset(
      &src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    v6 = &pMapBrushSides[v5];
    m_nTextureInfoIndex = v6->m_nTextureInfoIndex;
    src.m_nPlaneIndex = v6->m_nPlaneIndex;
    m_SurfaceFlags = v6->m_SurfaceFlags;
    src.m_nTextureInfoIndex = m_nTextureInfoIndex;
    m_Size = v6->m_Polygon.m_Points.m_Size;
    m_pMemory = v6->m_Polygon.m_Points.m_Memory.m_pMemory;
    src.m_SurfaceFlags = m_SurfaceFlags;
    src.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
      this: &src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      pArray: m_pMemory,
      size: m_Size);
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
      this: &this->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
      elem: this->m_Sides.m_Size,
      &src);
    if ( src.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 && src.m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Polygon.m_Points.m_Memory.m_pMemory);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005FEB0
// Name: private: void CSimpleBSPFile::SplitBrush(class CBSPBrush __near *,int,class CBSPBrush __near * __near *,class CBSPBrush __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::SplitBrush(
        CSimpleBSPFile *this,
        CSimpleBSPFile *pBrush,
        int nPlaneIndex,
        CCopyableUtlVector<Vector>_vtbl **ppFrontBrush,
        Vector **ppBackBrush)
{
  CBSPBrush *v5; // ebx
  HashedPlane_t *v6; // esi
  Vector *v7; // ecx
  float v8; // xmm6_4
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // eax
  int m_Size; // edi
  Vector *m_pMemory; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // edx
  float *v17; // ecx
  unsigned int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  int v27; // edi
  float *p_x; // ecx
  float v29; // xmm0_4
  CBSPBrush *v30; // eax
  CBSPBrush *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // edi
  float v36; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  const Vector *v39; // eax
  int v40; // edx
  Vector *v41; // xmm2_4
  CCopyableUtlVector<Vector>_vtbl *v42; // xmm1_4
  float v43; // xmm0_4
  int v44; // ecx
  Vector *v45; // eax
  void *v46; // eax
  CCopyableUtlVector<Vector>_vtbl *v47; // esi
  int v48; // eax
  void (__thiscall *m_ContentsFlags)(CCopyableUtlVector<Vector> *); // edx
  int v50; // ecx
  int *p_m_nGrowSize; // eax
  CCopyableUtlVector<Vector>_vtbl *v52; // edi
  int v53; // esi
  int v54; // eax
  int v55; // edx
  CBSPBrush *v56; // eax
  CBSPBrush *v57; // eax
  float v58; // ecx
  float v59; // ecx
  float v60; // ecx
  float v61; // ecx
  float v62; // ecx
  int v63; // ebx
  int v64; // ebx
  Polygon_t *v65; // esi
  CCopyableUtlVector<Vector>_vtbl *v66; // eax
  CCopyableUtlVector<Vector>_vtbl *v67; // edi
  int v68; // eax
  float *v69; // ecx
  void (__thiscall *v70)(CCopyableUtlVector<Vector> *); // eax
  CCopyableUtlVector<Vector>_vtbl *v71; // edi
  void (__thiscall *v72)(CCopyableUtlVector<Vector> *); // eax
  CCopyableUtlVector<Vector>_vtbl *v73; // edi
  int i; // edi
  CCopyableUtlVector<Vector>_vtbl *v75; // ebx
  int v76; // eax
  int v77; // ecx
  Vector *v78; // ecx
  int v79; // ecx
  int v80; // ecx
  Vector *v81; // ecx
  Vector *v82; // eax
  bool v83; // zf
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v84; // ecx
  void (__thiscall *v85)(CCopyableUtlVector<Vector> *); // eax
  char *v86; // eax
  Vector *v87; // esi
  Vector **v88; // ecx
  Vector *v89; // edi
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *p_y; // ecx
  float v91; // eax
  char *v92; // eax
  CBSPBrush *v93; // eax
  CBSPBrush *v94; // eax
  CBSPBrush *v95; // eax
  Polygon_t pFront; // [esp+1Ch] [ebp-70h] BYREF
  Polygon_t pBack; // [esp+34h] [ebp-58h] BYREF
  Polygon_t v98; // [esp+50h] [ebp-3Ch] BYREF
  float v99; // [esp+68h] [ebp-24h]
  Polygon_t splitPlanePolygon; // [esp+6Ch] [ebp-20h]
  int v101; // [esp+84h] [ebp-8h]
  CBSPBrush *pNewBrushes[2]; // [esp+88h] [ebp-4h]

  v5 = (CBSPBrush *)pBrush;
  splitPlanePolygon.m_Points.m_Memory.m_nGrowSize = (int)this;
  v6 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[nPlaneIndex];
  *ppBackBrush = nullptr;
  *ppFrontBrush = nullptr;
  v7 = (Vector *)pBrush->m_PlaneHash.m_HashTable[3];
  splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount = (int)v6;
  v8 = 0.0;
  pNewBrushes[0] = nullptr;
  if ( (int)v7 <= 0 )
    goto LABEL_42;
  v9 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)(pBrush->m_PlaneHash.m_HashTable[0] + 16);
  splitPlanePolygon.m_Points.m_Size = (int)v9;
  splitPlanePolygon.m_Points.m_pElements = v7;
  do
  {
    m_Size = v9->m_Size;
    v101 = 0;
    if ( m_Size >= 4 )
    {
      m_pMemory = v9->m_Memory.m_pMemory;
      y = v6->m_vNormal.y;
      x = v6->m_vNormal.x;
      z = v6->m_vNormal.z;
      m_flDistance = v6->m_flDistance;
      p_z = &m_pMemory->z;
      v17 = &m_pMemory[1].z;
      v18 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v101 = 4 * v18;
      do
      {
        v19 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - m_flDistance;
        if ( v19 <= 0.0 || v19 <= v8 )
        {
          if ( v19 < 0.0 && *(float *)pNewBrushes > v19 )
            *(float *)pNewBrushes = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y))
                                          + (float)(z * *p_z))
                                  - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - m_flDistance;
        }
        v20 = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17)) - m_flDistance;
        if ( v20 <= 0.0 || v20 <= v8 )
        {
          if ( v20 < 0.0 && *(float *)pNewBrushes > v20 )
            *(float *)pNewBrushes = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17))
                                  - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17)) - m_flDistance;
        }
        v21 = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z)) - m_flDistance;
        if ( v21 <= 0.0 || v21 <= v8 )
        {
          if ( v21 < 0.0 && *(float *)pNewBrushes > v21 )
            *(float *)pNewBrushes = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z))
                                  - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z)) - m_flDistance;
        }
        v22 = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z)) - m_flDistance;
        if ( v22 <= 0.0 || v22 <= v8 )
        {
          if ( v22 < 0.0 && *(float *)pNewBrushes > v22 )
            *(float *)pNewBrushes = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z))
                                  - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z)) - m_flDistance;
        }
        p_z += 12;
        v17 += 12;
        --v18;
      }
      while ( v18 != 0 );
      v5 = (CBSPBrush *)pBrush;
      v9 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)splitPlanePolygon.m_Points.m_Size;
    }
    if ( v101 < m_Size )
    {
      v23 = v6->m_vNormal.y;
      v24 = v6->m_vNormal.x;
      v25 = v6->m_vNormal.z;
      v26 = v6->m_flDistance;
      v27 = m_Size - v101;
      p_x = &v9->m_Memory.m_pMemory[v101].x;
      do
      {
        v29 = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) - v26;
        if ( v29 <= 0.0 || v29 <= v8 )
        {
          if ( v29 < 0.0 && *(float *)pNewBrushes > v29 )
            *(float *)pNewBrushes = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25))
                                  - v26;
        }
        else
        {
          v8 = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) - v26;
        }
        p_x += 3;
        --v27;
      }
      while ( v27 != 0 );
    }
    v9 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)v9 + 36);
    v83 = splitPlanePolygon.m_Points.m_pElements-- == (Vector *)1;
    splitPlanePolygon.m_Points.m_Size = (int)v9;
  }
  while ( !v83 );
  if ( v8 < 0.1 )
  {
LABEL_42:
    v30 = (CBSPBrush *)operator new(nSize: 0x40u);
    if ( v30 != nullptr )
      *ppBackBrush = (Vector *)CBSPBrush::CBSPBrush(this: v30, __that: v5);
    else
      *ppBackBrush = nullptr;
    return;
  }
  if ( *(float *)pNewBrushes > -0.1 )
  {
    v31 = (CBSPBrush *)operator new(nSize: 0x40u);
    if ( v31 != nullptr )
      *ppFrontBrush = (CCopyableUtlVector<Vector>_vtbl *)CBSPBrush::CBSPBrush(this: v31, __that: v5);
    else
      *ppFrontBrush = nullptr;
    return;
  }
  v32 = (float)(v5->m_vMaxBounds.x + v5->m_vMinBounds.x) * -0.5;
  v33 = (float)(v5->m_vMaxBounds.y + v5->m_vMinBounds.y) * -0.5;
  v34 = (float)(v5->m_vMaxBounds.z + v5->m_vMinBounds.z) * -0.5;
  v35 = 0;
  memset(
    &v98.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
    0,
    sizeof(v98.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
  v98.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  v36 = v6->m_vNormal.y * v33;
  *(float *)&splitPlanePolygon.m_Points.__vftable = v33;
  v37 = v6->m_vNormal.x * v32;
  v99 = v32;
  v38 = (float)((float)(v36 + v37) + (float)(v6->m_vNormal.z * v34)) + v6->m_flDistance;
  *(float *)&splitPlanePolygon.m_Points.m_Memory.m_pMemory = v34;
  CreatePolygonFromPlane(vNormal: &v6->m_vNormal, flDistance: v38, pPolygon: &v98);
  splitPlanePolygon.m_Points.m_Size = 0;
  if ( v5->m_Sides.m_Size > 0 )
  {
    while ( 1 )
    {
      v39 = (const Vector *)(*(_DWORD *)(splitPlanePolygon.m_Points.m_Memory.m_nGrowSize + 8)
                           + 24 * (v5->m_Sides.m_Memory.m_pMemory[v35].m_nPlaneIndex ^ 1));
      ChopPolygonInPlace(
        pPolygon: &v98,
        vNormal: v39,
        flDistance: (float)((float)((float)(v39->y * *(float *)&splitPlanePolygon.m_Points.__vftable) + (float)(v39->x * v99))
              + (float)(v39->z * *(float *)&splitPlanePolygon.m_Points.m_Memory.m_pMemory))
      + v39[1].x);
      if ( v98.m_Points.m_Size == 0 )
        break;
      ++v35;
      if ( ++splitPlanePolygon.m_Points.m_Size >= v5->m_Sides.m_Size )
        goto LABEL_52;
    }
LABEL_159:
    if ( CSimpleBSPFile::GetPrimaryPlaneSide(
           this: (CSimpleBSPFile *)splitPlanePolygon.m_Points.m_Memory.m_nGrowSize,
           pBrush: v5,
           pPlane: v6) == PLANE_SIDE_FRONT )
    {
      v93 = (CBSPBrush *)operator new(nSize: 0x40u);
      if ( v93 != nullptr )
        *ppFrontBrush = (CCopyableUtlVector<Vector>_vtbl *)CBSPBrush::CBSPBrush(this: v93, __that: v5);
      else
        *ppFrontBrush = nullptr;
    }
    else
    {
      v94 = (CBSPBrush *)operator new(nSize: 0x40u);
      if ( v94 != nullptr )
        v95 = CBSPBrush::CBSPBrush(this: v94, __that: v5);
      else
        v95 = nullptr;
      *ppBackBrush = &v95->m_vMinBounds;
    }
    v82 = v98.m_Points.m_Memory.m_pMemory;
    v98.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    v98.m_Points.m_Size = 0;
    if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v98.m_Points.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v98.m_Points.m_Memory.m_pMemory);
        v82 = nullptr;
        v98.m_Points.m_Memory.m_pMemory = nullptr;
      }
      v98.m_Points.m_Memory.m_nAllocationCount = 0;
    }
    v98.m_Points.m_pElements = v82;
    if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
    {
      v83 = v82 == nullptr;
LABEL_173:
      if ( !v83 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v82);
      return;
    }
    return;
  }
LABEL_52:
  if ( v98.m_Points.m_Size == 0 || IsPolygonTiny(pPolygon: &v98) )
    goto LABEL_159;
  v40 = 0;
  if ( v98.m_Points.m_Size > 0 )
  {
    v41 = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
    v42 = splitPlanePolygon.m_Points.__vftable;
    v43 = v99;
    v44 = 0;
    do
    {
      v45 = &v98.m_Points.m_Memory.m_pMemory[v44];
      v45->x = v98.m_Points.m_Memory.m_pMemory[v44].x - v43;
      v45->y = v45->y - *(float *)&v42;
      ++v40;
      v45->z = v45->z - *(float *)&v41;
      ++v44;
    }
    while ( v40 < v98.m_Points.m_Size );
  }
  splitPlanePolygon.m_Points.m_Size = 0;
  do
  {
    v46 = operator new(nSize: 0x40u);
    v47 = (CCopyableUtlVector<Vector>_vtbl *)v46;
    if ( v46 != nullptr )
    {
      *((_DWORD *)v46 + 7) = 0;
      *((_DWORD *)v46 + 8) = 0;
      *((_DWORD *)v46 + 9) = 0;
      *((_DWORD *)v46 + 10) = 0;
      *((_DWORD *)v46 + 11) = 0;
      *((_DWORD *)v46 + 6) = &CCopyableUtlVector<CBSPBrushSide>::`vftable';
      *((_DWORD *)v46 + 12) = 0;
      *((_DWORD *)v46 + 13) = 0;
      *((_DWORD *)v46 + 14) = 0;
      *((_DWORD *)v46 + 15) = 0;
      ClearBounds(mins: (Vector *)v46, maxs: (Vector *)v46 + 1);
    }
    else
    {
      v47 = nullptr;
    }
    v48 = splitPlanePolygon.m_Points.m_Size;
    m_ContentsFlags = (void (__thiscall *)(CCopyableUtlVector<Vector> *))v5->m_ContentsFlags;
    (&splitPlanePolygon.m_Points.__vftable)[splitPlanePolygon.m_Points.m_Size] = v47;
    v47[12].dtr_CCopyableUtlVector<Vector> = m_ContentsFlags;
    v47[13].dtr_CCopyableUtlVector<Vector> = (void (__thiscall *)(CCopyableUtlVector<Vector> *))v5->m_pOriginalBrush;
    splitPlanePolygon.m_Points.m_Size = v48 + 1;
  }
  while ( v48 + 1 < 2 );
  splitPlanePolygon.m_Points.m_Memory.m_nGrowSize = 0;
  if ( v5->m_Sides.m_Size > 0 )
  {
    v101 = 0;
    do
    {
      v50 = 1;
      p_m_nGrowSize = &pFront.m_Points.m_Memory.m_nGrowSize;
      do
      {
        *(p_m_nGrowSize - 2) = 0;
        *(p_m_nGrowSize - 1) = 0;
        *p_m_nGrowSize = 0;
        p_m_nGrowSize[1] = 0;
        p_m_nGrowSize[2] = 0;
        *(p_m_nGrowSize - 3) = (int)&CCopyableUtlVector<Vector>::`vftable';
        p_m_nGrowSize += 6;
        --v50;
      }
      while ( v50 >= 0 );
      ChopPolygon(
        polygon: (const Polygon_t *)(pBrush->m_PlaneHash.m_HashTable[0] + v101 + 12),
        vNormal: (const Vector *)splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount,
        flDistance: *(float *)(splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount + 12),
        pOn: nullptr,
        &pFront,
        &pBack);
      splitPlanePolygon.m_Points.m_Size = 0;
      pNewBrushes[0] = (CBSPBrush *)&pFront;
      do
      {
        if ( SLODWORD(pNewBrushes[0]->m_vMaxBounds.y) > 0 )
        {
          v52 = (&splitPlanePolygon.m_Points.__vftable)[splitPlanePolygon.m_Points.m_Size];
          CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
            this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v52[7],
            elem: (int)v52[10].dtr_CCopyableUtlVector<Vector>);
          v53 = (int)v52[7].dtr_CCopyableUtlVector<Vector> + 36 * (int)v52[10].dtr_CCopyableUtlVector<Vector> - 36;
          v54 = v101;
          *(_DWORD *)v53 = *(_DWORD *)(v101 + pBrush->m_PlaneHash.m_HashTable[0]);
          v55 = *(_DWORD *)(pBrush->m_PlaneHash.m_HashTable[0] + v54 + 4);
          *(_WORD *)(v53 + 8) = 0;
          v56 = pNewBrushes[0];
          *(_DWORD *)(v53 + 4) = v55;
          v57 = v56 != nullptr ? (CBSPBrush *)&v56->m_vMinBounds.y : nullptr;
          v58 = *(float *)(v53 + 24);
          *(float *)(v53 + 24) = v57->m_vMinBounds.z;
          v57->m_vMinBounds.z = v58;
          v59 = *(float *)(v53 + 16);
          *(float *)(v53 + 16) = v57->m_vMinBounds.x;
          v57->m_vMinBounds.x = v59;
          v60 = *(float *)(v53 + 20);
          *(float *)(v53 + 20) = v57->m_vMinBounds.y;
          v57->m_vMinBounds.y = v60;
          v61 = *(float *)(v53 + 28);
          *(float *)(v53 + 28) = v57->m_vMaxBounds.x;
          v57->m_vMaxBounds.x = v61;
          v62 = *(float *)(v53 + 32);
          *(float *)(v53 + 32) = v57->m_vMaxBounds.y;
          v63 = 0;
          v57->m_vMaxBounds.y = v62;
          if ( *(int *)(v53 + 28) > 0 )
          {
            splitPlanePolygon.m_Points.m_pElements = nullptr;
            do
            {
              AddPointToBounds(
                v: (const Vector *)((char *)splitPlanePolygon.m_Points.m_pElements++ + *(_DWORD *)(v53 + 16)),
                mins: (Vector *)v52,
                maxs: (Vector *)&v52[3]);
              ++v63;
            }
            while ( v63 < *(_DWORD *)(v53 + 28) );
          }
        }
        pNewBrushes[0] = (CBSPBrush *)((char *)pNewBrushes[0] + 24);
        ++splitPlanePolygon.m_Points.m_Size;
      }
      while ( splitPlanePolygon.m_Points.m_Size < 2 );
      v64 = 1;
      v65 = &v98;
      do
      {
        --v65;
        v65[-1].m_Points.m_pElements = (Vector *)&CCopyableUtlVector<Vector>::`vftable';
        v65->m_Points.m_Memory.m_nGrowSize = 0;
        if ( v65->m_Points.m_Memory.m_nAllocationCount >= 0 )
        {
          if ( v65->m_Points.__vftable != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v65->m_Points.__vftable);
            v65->m_Points.__vftable = nullptr;
          }
          v65->m_Points.m_Memory.m_pMemory = nullptr;
        }
        v66 = v65->m_Points.__vftable;
        v65->m_Points.m_Size = (int)v65->m_Points.__vftable;
        if ( v65->m_Points.m_Memory.m_nAllocationCount >= 0 )
        {
          if ( v66 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
            v65->m_Points.__vftable = nullptr;
          }
          v65->m_Points.m_Memory.m_pMemory = nullptr;
        }
        --v64;
      }
      while ( v64 >= 0 );
      v101 += 36;
      ++splitPlanePolygon.m_Points.m_Memory.m_nGrowSize;
    }
    while ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize < pBrush->m_PlaneHash.m_HashTable[3] );
  }
  pNewBrushes[0] = nullptr;
  do
  {
    v67 = (&splitPlanePolygon.m_Points.__vftable)[(int)pNewBrushes[0]];
    v68 = 0;
    v69 = (float *)v67;
    while ( *v69 >= -16384.0 && v69[3] <= 16384.0 )
    {
      ++v68;
      ++v69;
      if ( v68 >= 3 )
        goto LABEL_103;
    }
    if ( v67 != nullptr )
    {
      v67[6].dtr_CCopyableUtlVector<Vector> = (void (__thiscall *)(CCopyableUtlVector<Vector> *))&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v67[7]);
      if ( (int)v67[9].dtr_CCopyableUtlVector<Vector> >= 0 )
      {
        if ( v67[7].dtr_CCopyableUtlVector<Vector> != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v67[7].dtr_CCopyableUtlVector<Vector>);
          v67[7].dtr_CCopyableUtlVector<Vector> = nullptr;
        }
        v67[8].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      v70 = v67[7].dtr_CCopyableUtlVector<Vector>;
      v67[11].dtr_CCopyableUtlVector<Vector> = v70;
      if ( (int)v67[9].dtr_CCopyableUtlVector<Vector> >= 0 )
      {
        if ( v70 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v70);
          v67[7].dtr_CCopyableUtlVector<Vector> = nullptr;
        }
        v67[8].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      free(pMem: v67);
    }
    (&splitPlanePolygon.m_Points.__vftable)[(int)pNewBrushes[0]] = nullptr;
LABEL_103:
    v71 = (&splitPlanePolygon.m_Points.__vftable)[(int)pNewBrushes[0]];
    if ( v71 != nullptr && (int)v71[10].dtr_CCopyableUtlVector<Vector> < 3 )
    {
      v71[6].dtr_CCopyableUtlVector<Vector> = (void (__thiscall *)(CCopyableUtlVector<Vector> *))&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v71[7]);
      if ( (int)v71[9].dtr_CCopyableUtlVector<Vector> >= 0 )
      {
        if ( v71[7].dtr_CCopyableUtlVector<Vector> != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v71[7].dtr_CCopyableUtlVector<Vector>);
          v71[7].dtr_CCopyableUtlVector<Vector> = nullptr;
        }
        v71[8].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      v72 = v71[7].dtr_CCopyableUtlVector<Vector>;
      v71[11].dtr_CCopyableUtlVector<Vector> = v72;
      if ( (int)v71[9].dtr_CCopyableUtlVector<Vector> >= 0 )
      {
        if ( v72 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v72);
          v71[7].dtr_CCopyableUtlVector<Vector> = nullptr;
        }
        v71[8].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      free(pMem: v71);
      (&splitPlanePolygon.m_Points.__vftable)[(int)pNewBrushes[0]] = nullptr;
    }
    ++pNewBrushes[0];
  }
  while ( (int)pNewBrushes[0] < 2 );
  v73 = splitPlanePolygon.m_Points.__vftable;
  if ( splitPlanePolygon.m_Points.__vftable != nullptr )
  {
    if ( splitPlanePolygon.m_Points.m_Memory.m_pMemory != nullptr )
    {
      for ( i = 0; i < 2; ++i )
      {
        v75 = (&splitPlanePolygon.m_Points.__vftable)[i];
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
          this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v75[7],
          elem: (int)v75[10].dtr_CCopyableUtlVector<Vector>);
        v76 = (int)v75[7].dtr_CCopyableUtlVector<Vector> + 36 * (int)v75[10].dtr_CCopyableUtlVector<Vector> - 36;
        *(_DWORD *)v76 = nPlaneIndex ^ i ^ 1;
        *(_DWORD *)(v76 + 4) = -1;
        *(_WORD *)(v76 + 8) = 0;
        if ( i != 0 )
        {
          v77 = *(_DWORD *)(v76 + 24);
          *(_DWORD *)(v76 + 24) = v98.m_Points.m_Memory.m_nGrowSize;
          v98.m_Points.m_Memory.m_nGrowSize = v77;
          v78 = *(Vector **)(v76 + 16);
          *(_DWORD *)(v76 + 16) = v98.m_Points.m_Memory.m_pMemory;
          v98.m_Points.m_Memory.m_pMemory = v78;
          v79 = *(_DWORD *)(v76 + 20);
          *(_DWORD *)(v76 + 20) = v98.m_Points.m_Memory.m_nAllocationCount;
          v98.m_Points.m_Memory.m_nAllocationCount = v79;
          v80 = *(_DWORD *)(v76 + 28);
          *(_DWORD *)(v76 + 28) = v98.m_Points.m_Size;
          v98.m_Points.m_Size = v80;
          v81 = *(Vector **)(v76 + 32);
          *(_DWORD *)(v76 + 32) = v98.m_Points.m_pElements;
          v98.m_Points.m_pElements = v81;
        }
        else
        {
          CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
            this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)(v76 + 16),
            other: &v98.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
        }
      }
      *ppFrontBrush = splitPlanePolygon.m_Points.__vftable;
      *ppBackBrush = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
      v82 = v98.m_Points.m_Memory.m_pMemory;
      v98.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v98.m_Points.m_Size = 0;
      if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v98.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v98.m_Points.m_Memory.m_pMemory);
          v82 = nullptr;
          v98.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v98.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      v98.m_Points.m_pElements = v82;
      if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        v83 = v82 == nullptr;
        goto LABEL_173;
      }
      return;
    }
    v84 = (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&splitPlanePolygon.m_Points.__vftable[7];
    splitPlanePolygon.m_Points.__vftable[6].dtr_CCopyableUtlVector<Vector> = (void (__thiscall *)(CCopyableUtlVector<Vector> *))&CCopyableUtlVector<CBSPBrushSide>::`vftable';
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: v84);
    if ( (int)v73[9].dtr_CCopyableUtlVector<Vector> >= 0 )
    {
      if ( v73[7].dtr_CCopyableUtlVector<Vector> != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v73[7].dtr_CCopyableUtlVector<Vector>);
        v73[7].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      v73[8].dtr_CCopyableUtlVector<Vector> = nullptr;
    }
    v85 = v73[7].dtr_CCopyableUtlVector<Vector>;
    v73[11].dtr_CCopyableUtlVector<Vector> = v85;
    if ( (int)v73[9].dtr_CCopyableUtlVector<Vector> >= 0 )
    {
      if ( v85 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v85);
        v73[7].dtr_CCopyableUtlVector<Vector> = nullptr;
      }
      v73[8].dtr_CCopyableUtlVector<Vector> = nullptr;
    }
    free(pMem: v73);
    v86 = (char *)operator new(nSize: 0x40u);
    v87 = (Vector *)v86;
    if ( v86 != nullptr )
    {
      *(Vector *)v86 = *(Vector *)&pBrush->m_pMapFile;
      *((Vector *)v86 + 1) = *(Vector *)&pBrush->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount;
      *((_DWORD *)v86 + 7) = 0;
      *((_DWORD *)v86 + 8) = 0;
      *((_DWORD *)v86 + 9) = 0;
      *((_DWORD *)v86 + 10) = 0;
      *((_DWORD *)v86 + 11) = 0;
      *((_DWORD *)v86 + 6) = &CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)(v86 + 28),
        pArray: (const CBSPBrushSide *)pBrush->m_PlaneHash.m_HashTable[0],
        size: pBrush->m_PlaneHash.m_HashTable[3]);
      LODWORD(v87[4].x) = pBrush->m_PlaneHash.m_HashTable[5];
      LODWORD(v87[4].y) = pBrush->m_PlaneHash.m_HashTable[6];
      v88 = (Vector **)ppFrontBrush;
      LODWORD(v87[4].z) = pBrush->m_PlaneHash.m_HashTable[7];
      LODWORD(v87[5].x) = pBrush->m_PlaneHash.m_HashTable[8];
    }
    else
    {
      v88 = (Vector **)ppFrontBrush;
      v87 = nullptr;
    }
  }
  else
  {
    v89 = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
    if ( splitPlanePolygon.m_Points.m_Memory.m_pMemory == nullptr )
      goto LABEL_153;
    p_y = (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&splitPlanePolygon.m_Points.m_Memory.m_pMemory[2].y;
    LODWORD(splitPlanePolygon.m_Points.m_Memory.m_pMemory[2].x) = &CCopyableUtlVector<CBSPBrushSide>::`vftable';
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: p_y);
    if ( v89[3].x >= 0.0 )
    {
      if ( LODWORD(v89[2].y) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v89[2].y));
        v89[2].y = 0.0;
      }
      v89[2].z = 0.0;
    }
    v91 = v89[2].y;
    v89[3].z = v91;
    if ( v89[3].x >= 0.0 )
    {
      if ( v91 != 0.0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v91));
        v89[2].y = 0.0;
      }
      v89[2].z = 0.0;
    }
    free(pMem: v89);
    v92 = (char *)operator new(nSize: 0x40u);
    v87 = (Vector *)v92;
    if ( v92 != nullptr )
    {
      *(Vector *)v92 = *(Vector *)&pBrush->m_pMapFile;
      *((Vector *)v92 + 1) = *(Vector *)&pBrush->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount;
      *((_DWORD *)v92 + 7) = 0;
      *((_DWORD *)v92 + 8) = 0;
      *((_DWORD *)v92 + 9) = 0;
      *((_DWORD *)v92 + 10) = 0;
      *((_DWORD *)v92 + 11) = 0;
      *((_DWORD *)v92 + 6) = &CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)(v92 + 28),
        pArray: (const CBSPBrushSide *)pBrush->m_PlaneHash.m_HashTable[0],
        size: pBrush->m_PlaneHash.m_HashTable[3]);
      LODWORD(v87[4].x) = pBrush->m_PlaneHash.m_HashTable[5];
      LODWORD(v87[4].y) = pBrush->m_PlaneHash.m_HashTable[6];
      LODWORD(v87[4].z) = pBrush->m_PlaneHash.m_HashTable[7];
      LODWORD(v87[5].x) = pBrush->m_PlaneHash.m_HashTable[8];
    }
    else
    {
      v87 = nullptr;
    }
    v88 = ppBackBrush;
  }
  *v88 = v87;
LABEL_153:
  v82 = v98.m_Points.m_Memory.m_pMemory;
  v98.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  v98.m_Points.m_Size = 0;
  if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v98.m_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v98.m_Points.m_Memory.m_pMemory);
      v82 = nullptr;
      v98.m_Points.m_Memory.m_pMemory = nullptr;
    }
    v98.m_Points.m_Memory.m_nAllocationCount = 0;
  }
  v98.m_Points.m_pElements = v82;
  if ( v98.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    v83 = v82 == nullptr;
    goto LABEL_173;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060A00
// Name: private: void CSimpleBSPFile::SplitBrushList(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class CBSPNode __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::SplitBrushList(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList,
        CBSPNode *pNode,
        CBSPBrush *pFrontChildList,
        CBSPBrush *pBackChildList)
{
  bool v5; // cc
  CUtlMemory<vgui::TreeNode *,int> *v6; // esi
  CUtlMemory<vgui::TreeNode *,int> *v7; // edi
  CSimpleBSPFile *v8; // ebx
  vgui::TreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  CBSPBrush **v13; // ebx
  vgui::TreeNode **v14; // ebx
  int v15; // eax
  vgui::TreeNode **v16; // ecx
  int v17; // eax
  CBSPBrush **v18; // ebx
  CBSPBrush *v19; // eax
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v20; // edx
  int v21; // ecx
  _DWORD *v22; // eax
  vgui::TreeNode **v23; // ebx
  int v24; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  vgui::TreeNode **v27; // ecx
  int v28; // eax
  vgui::TreeNode **v29; // ecx
  int v30; // eax
  CBSPBrush **v31; // ebx
  PlaneSide_t whichSide; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  CBSPBrush *pBack; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+10h] [ebp-4h]

  v5 = pBrushList->m_Size <= 0;
  i = 0;
  if ( !v5 )
  {
    v6 = (CUtlMemory<vgui::TreeNode *,int> *)pBackChildList;
    v7 = (CUtlMemory<vgui::TreeNode *,int> *)pFrontChildList;
    do
    {
      v8 = (CSimpleBSPFile *)pBrushList->m_Memory.m_pMemory[i];
      whichSide = v8->m_PlaneHash.m_HashTable[8];
      if ( whichSide == PLANE_SIDE_BOTH )
      {
        CSimpleBSPFile::SplitBrush(
          this,
          pBrush: v8,
          nPlaneIndex: pNode->m_nSplitPlaneIndex,
          ppFrontBrush: (CCopyableUtlVector<Vector>_vtbl **)&pFrontChildList,
          ppBackBrush: (Vector **)&pBack);
        if ( pFrontChildList != nullptr )
        {
          m_pMemory = v7[1].m_pMemory;
          m_nAllocationCount = v7->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: v7,
              num: (int)m_pMemory - m_nAllocationCount + 1);
          ++v7[1].m_pMemory;
          v11 = v7->m_pMemory;
          v12 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
          v7[1].m_nAllocationCount = (int)v7->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v11[(_DWORD)m_pMemory + 1],
              src: (unsigned __int8 *)&v11[(_DWORD)m_pMemory],
              count: 4 * v12);
          v13 = (CBSPBrush **)&v7->m_pMemory[(_DWORD)m_pMemory];
          if ( v13 != nullptr )
            *v13 = pFrontChildList;
        }
        if ( pBack != nullptr )
        {
          v14 = v6[1].m_pMemory;
          v15 = v6->m_nAllocationCount;
          if ( (int)v14 + 1 > v15 )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: v6,
              num: (int)v14 - v15 + 1);
          ++v6[1].m_pMemory;
          v16 = v6->m_pMemory;
          v17 = (char *)v6[1].m_pMemory - (char *)v14 - 1;
          v6[1].m_nAllocationCount = (int)v6->m_pMemory;
          if ( v17 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v16[(_DWORD)v14 + 1],
              src: (unsigned __int8 *)&v16[(_DWORD)v14],
              count: 4 * v17);
          v18 = (CBSPBrush **)&v6->m_pMemory[(_DWORD)v14];
          if ( v18 != nullptr )
            *v18 = pBack;
        }
      }
      else
      {
        v19 = (CBSPBrush *)operator new(nSize: 0x40u);
        if ( v19 != nullptr )
          pBackChildList = CBSPBrush::CBSPBrush(this: v19, __that: (const CBSPBrush *)v8);
        else
          pBackChildList = nullptr;
        if ( (whichSide & 4) != 0 )
        {
          v20 = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)pBackChildList;
          v21 = 0;
          for ( j = 0; j < pBackChildList->m_Sides.m_Size; ++j )
          {
            v22 = (_DWORD *)(v21 + v20[1].m_Memory.m_nGrowSize);
            if ( (*v22 & 0xFFFFFFFE) == pNode->m_nSplitPlaneIndex )
              v22[1] = -1;
            v20 = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)pBackChildList;
            v21 += 36;
          }
        }
        if ( (whichSide & 1) != 0 )
        {
          v23 = v7[1].m_pMemory;
          v24 = v7->m_nAllocationCount;
          if ( (int)v23 + 1 > v24 )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: v7,
              num: (int)v23 - v24 + 1);
          ++v7[1].m_pMemory;
          v25 = v7->m_pMemory;
          v26 = (char *)v7[1].m_pMemory - (char *)v23 - 1;
          v7[1].m_nAllocationCount = (int)v7->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v25[(_DWORD)v23 + 1],
              src: (unsigned __int8 *)&v25[(_DWORD)v23],
              count: 4 * v26);
          v27 = v7->m_pMemory;
        }
        else
        {
          v23 = v6[1].m_pMemory;
          v28 = v6->m_nAllocationCount;
          if ( (int)v23 + 1 > v28 )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: v6,
              num: (int)v23 - v28 + 1);
          ++v6[1].m_pMemory;
          v29 = v6->m_pMemory;
          v30 = (char *)v6[1].m_pMemory - (char *)v23 - 1;
          v6[1].m_nAllocationCount = (int)v6->m_pMemory;
          if ( v30 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v29[(_DWORD)v23 + 1],
              src: (unsigned __int8 *)&v29[(_DWORD)v23],
              count: 4 * v30);
          v27 = v6->m_pMemory;
        }
        v31 = (CBSPBrush **)&v27[(_DWORD)v23];
        if ( v31 != nullptr )
          *v31 = pBackChildList;
      }
      ++i;
    }
    while ( i < pBrushList->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060C40
// Name: private: void CSimpleBSPFile::PruneNodes(class CBSPNode __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::PruneNodes(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *pPortalList)
{
  CBSPNode *v4; // eax
  int m_nGrowSize; // edx
  CBSPBrush **m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  CBSPBrush **m_pElements; // edx
  int i; // edx
  CBSPPortal *v11; // eax
  CBSPNode *m_pOnNode; // ecx
  CBSPNode *v13; // ecx
  CBSPNode *v14; // edi
  CBSPNode *v15; // edi

  if ( pNode->m_nSplitPlaneIndex != -1 )
  {
    CSimpleBSPFile::PruneNodes(this, pNode: pNode->m_pChildren[0], pPortalList);
    CSimpleBSPFile::PruneNodes(this, pNode: pNode->m_pChildren[1], pPortalList);
    if ( (pNode->m_pChildren[0]->m_ContentsFlags & 1) != 0 )
    {
      v4 = pNode->m_pChildren[1];
      if ( (v4->m_ContentsFlags & 1) != 0 )
      {
        pNode->m_ContentsFlags = 1;
        pNode->m_nSplitPlaneIndex = -1;
        m_nGrowSize = pNode->m_ClippedBrushes.m_Memory.m_nGrowSize;
        pNode->m_ClippedBrushes.m_Memory.m_nGrowSize = v4->m_ClippedBrushes.m_Memory.m_nGrowSize;
        v4->m_ClippedBrushes.m_Memory.m_nGrowSize = m_nGrowSize;
        m_pMemory = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
        pNode->m_ClippedBrushes.m_Memory.m_pMemory = v4->m_ClippedBrushes.m_Memory.m_pMemory;
        v4->m_ClippedBrushes.m_Memory.m_pMemory = m_pMemory;
        m_nAllocationCount = pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount;
        pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount = v4->m_ClippedBrushes.m_Memory.m_nAllocationCount;
        v4->m_ClippedBrushes.m_Memory.m_nAllocationCount = m_nAllocationCount;
        m_Size = pNode->m_ClippedBrushes.m_Size;
        pNode->m_ClippedBrushes.m_Size = v4->m_ClippedBrushes.m_Size;
        v4->m_ClippedBrushes.m_Size = m_Size;
        m_pElements = pNode->m_ClippedBrushes.m_pElements;
        pNode->m_ClippedBrushes.m_pElements = v4->m_ClippedBrushes.m_pElements;
        v4->m_ClippedBrushes.m_pElements = m_pElements;
        CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int>>::InsertMultipleBefore(
          this: (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)&pNode->m_ClippedBrushes,
          elem: pNode->m_ClippedBrushes.m_Size,
          num: pNode->m_pChildren[0]->m_ClippedBrushes.m_Size,
          pToInsert: (CBSPFace *const *)pNode->m_pChildren[0]->m_ClippedBrushes.m_Memory.m_pMemory);
        pNode->m_pChildren[0]->m_ClippedBrushes.m_Size = 0;
        for ( i = 0; i < pPortalList->m_Size; ++i )
        {
          v11 = pPortalList->m_Memory.m_pMemory[i];
          m_pOnNode = v11->m_pOnNode;
          if ( m_pOnNode == pNode->m_pChildren[0] || m_pOnNode == pNode->m_pChildren[1] )
            v11->m_pOnNode = nullptr;
          if ( v11->m_pNodes[0] == pNode->m_pChildren[0] || v11->m_pNodes[0] == pNode->m_pChildren[1] )
            v11->m_pNodes[0] = pNode;
          v13 = v11->m_pNodes[1];
          if ( v13 == pNode->m_pChildren[0] || v13 == pNode->m_pChildren[1] )
            v11->m_pNodes[1] = pNode;
        }
        v14 = pNode->m_pChildren[0];
        if ( v14 != nullptr )
        {
          CBSPNode::~CBSPNode(this: pNode->m_pChildren[0]);
          free(pMem: v14);
        }
        v15 = pNode->m_pChildren[1];
        if ( v15 != nullptr )
        {
          CBSPNode::~CBSPNode(this: pNode->m_pChildren[1]);
          free(pMem: v15);
        }
        pNode->m_pChildren[0] = nullptr;
        pNode->m_pChildren[1] = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060D70
// Name: private: void CSimpleBSPFile::FilterBrushIntoTree(class CBSPNode __near *,class CBSPBrush __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FilterBrushIntoTree(CSimpleBSPFile *this, CBSPBrush *pNode, CBSPNode *pBrush)
{
  CBSPNode *v3; // esi
  int x_low; // eax
  CBSPNode *v5; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPBrush **m_pMemory; // ecx
  int v10; // eax
  CBSPNode **v11; // ebx

  v3 = (CBSPNode *)pNode;
  x_low = LODWORD(pNode->m_vMaxBounds.x);
  v5 = pBrush;
  if ( x_low == -1 )
  {
LABEL_8:
    if ( (v3->m_ContentsFlags & 1) != 0 )
    {
      if ( v5 != nullptr )
      {
        v5->m_ClippedBrushes.m_Memory.m_nAllocationCount = (int)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v5->m_ClippedBrushes.m_Memory.m_nGrowSize);
        free(pMem: v5);
      }
    }
    else
    {
      m_Size = v3->m_ClippedBrushes.m_Size;
      m_nAllocationCount = v3->m_ClippedBrushes.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_ClippedBrushes,
          num: m_Size - m_nAllocationCount + 1);
      ++v3->m_ClippedBrushes.m_Size;
      m_pMemory = v3->m_ClippedBrushes.m_Memory.m_pMemory;
      v10 = v3->m_ClippedBrushes.m_Size - m_Size - 1;
      v3->m_ClippedBrushes.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v10);
      v11 = (CBSPNode **)&v3->m_ClippedBrushes.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = v5;
    }
  }
  else
  {
    while ( 1 )
    {
      CSimpleBSPFile::SplitBrush(
        this,
        pBrush: (CSimpleBSPFile *)v5,
        nPlaneIndex: x_low,
        ppFrontBrush: (CCopyableUtlVector<Vector>_vtbl **)&pBrush,
        ppBackBrush: (Vector **)&pNode);
      if ( v5 != nullptr )
      {
        v5->m_ClippedBrushes.m_Memory.m_nAllocationCount = (int)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)&v5->m_ClippedBrushes.m_Memory.m_nGrowSize);
        free(pMem: v5);
      }
      if ( pBrush != nullptr )
        CSimpleBSPFile::FilterBrushIntoTree(this, pNode: v3->m_pChildren[0], (CBSPBrush *)pBrush);
      v5 = (CBSPNode *)pNode;
      if ( pNode == nullptr )
        break;
      v3 = v3->m_pChildren[1];
      x_low = v3->m_nSplitPlaneIndex;
      if ( x_low == -1 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060E60
// Name: public: CBSPModel::~CBSPModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPModel::~CBSPModel(CBSPModel *this)
{
  CBSPTree *m_pTree; // esi
  int v3; // eax
  CBSPFace *v4; // esi
  Vector *m_pMemory; // eax
  int j; // esi
  CBSPPortal **v7; // ecx
  CBSPPortal *v8; // ebx
  CBSPPortal **v9; // eax
  CBSPFace **v10; // eax
  CBSPNode *i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  m_pTree = this->m_pTree;
  if ( this->m_pTree != nullptr )
  {
    i = m_pTree->m_pRoot;
    if ( m_pTree->m_pRoot != nullptr )
    {
      CBSPNode::~CBSPNode(this: m_pTree->m_pRoot);
      free(pMem: i);
    }
    CBSPNode::~CBSPNode(this: &m_pTree->m_OutsideNode);
    free(pMem: m_pTree);
  }
  v3 = 0;
  for ( ia = 0; v3 < this->m_DetailFaces.m_Size; ia = v3 )
  {
    v4 = this->m_DetailFaces.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      v4->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v4->m_Polygon.m_Points.m_Size = 0;
      if ( v4->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Polygon.m_Points.m_Memory.m_pMemory);
          v4->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v4->m_Polygon.m_Points.m_Memory.m_pMemory;
      v4->m_Polygon.m_Points.m_pElements = m_pMemory;
      if ( v4->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v4->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v4);
      v3 = ia;
    }
    ++v3;
  }
  for ( j = 0; j < this->m_Portals.m_Size; ++j )
  {
    v7 = this->m_Portals.m_Memory.m_pMemory;
    v8 = v7[j];
    if ( v8 != nullptr )
    {
      CBSPPortal::~CBSPPortal(this: v7[j]);
      free(pMem: v8);
    }
  }
  this->m_Portals.m_Size = 0;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Portals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Portals.m_Memory.m_pMemory);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_Portals.m_Memory.m_pMemory;
  this->m_Portals.m_pElements = v9;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailFaces.m_Size = 0;
  if ( this->m_DetailFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailFaces.m_Memory.m_pMemory);
      this->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_DetailFaces.m_Memory.m_pMemory;
  this->m_DetailFaces.m_pElements = v10;
  if ( this->m_DetailFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060FE0
// Name: private: class CBSPBrush __near * CSimpleBSPFile::CreateClippedBrush(struct MapBrush_t const __near *,class Vector const __near &,class Vector const __near &,int __near * const,int __near * const)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CSimpleBSPFile::CreateClippedBrush(
        CSimpleBSPFile *this,
        CBSPBrush *pMapBrush,
        CBSPBrush *vClipMin,
        const Vector *vClipMax,
        int *nClipMinPlanes,
        int *nClipMaxPlanes)
{
  const MapBrush_t *v6; // ebx
  const Vector *v7; // edi
  const Vector *p_m_vMinBounds; // ecx
  int v9; // edx
  Vector *p_m_Sides; // eax
  CBSPBrush *v11; // eax
  CBSPBrush *v12; // esi
  int v14; // ecx
  char *v15; // edx
  float *p_x; // eax
  CBSPBrushSide *m_pMemory; // eax
  const MapBrush_t *v18; // edi
  float *v19; // ecx
  int y_low; // eax
  CBSPBrushSide *v21; // eax
  Vector *v22; // edi
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v23; // ecx
  float y; // eax
  int v25; // edi
  int v26; // edx
  CBSPBrushSide *v27; // ecx
  unsigned int v28; // eax
  char *v29; // [esp+Ch] [ebp-18h]
  char *v30; // [esp+10h] [ebp-14h]
  char *v31; // [esp+14h] [ebp-10h]
  int v32; // [esp+18h] [ebp-Ch]
  Vector *v33; // [esp+1Ch] [ebp-8h]

  v6 = (const MapBrush_t *)pMapBrush;
  v7 = vClipMax;
  p_m_vMinBounds = &vClipMin->m_vMinBounds;
  v9 = 0;
  p_m_Sides = (Vector *)&pMapBrush->m_Sides;
  do
  {
    if ( p_m_Sides[-1].x >= *(float *)((char *)&p_m_vMinBounds->x + (char *)vClipMax - (char *)vClipMin)
      || p_m_vMinBounds->x >= p_m_Sides->x )
    {
      return nullptr;
    }
    ++v9;
    p_m_Sides = (Vector *)((char *)p_m_Sides + 4);
    p_m_vMinBounds = (const Vector *)((char *)p_m_vMinBounds + 4);
  }
  while ( v9 < 3 );
  v11 = (CBSPBrush *)operator new(nSize: 0x40u);
  if ( v11 != nullptr )
    v12 = CBSPBrush::CBSPBrush(
            this: v11,
            pMapBrush: v6,
            pMapBrushSides: this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory);
  else
    v12 = nullptr;
  v30 = (char *)((char *)vClipMin - (char *)v7);
  v14 = 12 - (_DWORD)v7;
  v15 = (char *)((char *)nClipMaxPlanes - (char *)v7);
  p_x = &v7->x;
  vClipMax = nullptr;
  v33 = (Vector *)v7;
  v32 = 12 - (_DWORD)v7;
  v31 = (char *)((char *)nClipMaxPlanes - (char *)v7);
  v29 = (char *)((char *)nClipMinPlanes - (char *)v7);
  while ( 1 )
  {
    if ( *(float *)((char *)&v12->m_vMinBounds.x + (_DWORD)p_x + v14) > *p_x )
    {
      CSimpleBSPFile::SplitBrush(
        this,
        pBrush: (CSimpleBSPFile *)v12,
        nPlaneIndex: *(_DWORD *)((char *)p_x + (_DWORD)v15),
        ppFrontBrush: (CCopyableUtlVector<Vector>_vtbl **)&pMapBrush,
        ppBackBrush: (Vector **)&vClipMin);
      if ( v12 != nullptr )
      {
        v12->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v12->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->m_Sides.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Sides.m_Memory.m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v12->m_Sides.m_Memory.m_pMemory;
        v12->m_Sides.m_pElements = m_pMemory;
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v12);
      }
      v18 = (const MapBrush_t *)pMapBrush;
      if ( pMapBrush != nullptr )
      {
        v19 = (float *)&pMapBrush->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
        pMapBrush->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)v19);
        if ( v18[1].m_ContentsFlags >= 0 )
        {
          if ( LODWORD(v18->m_vMaxBounds.y) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v18->m_vMaxBounds.y));
            v18->m_vMaxBounds.y = 0.0;
          }
          v18->m_vMaxBounds.z = 0.0;
        }
        y_low = LODWORD(v18->m_vMaxBounds.y);
        v18[1].m_nNumSides = y_low;
        if ( v18[1].m_ContentsFlags >= 0 )
        {
          if ( y_low != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)y_low);
            v18->m_vMaxBounds.y = 0.0;
          }
          v18->m_vMaxBounds.z = 0.0;
        }
        free(pMem: (void *)v18);
      }
      v12 = vClipMin;
      if ( vClipMin == nullptr )
        return nullptr;
      p_x = &v33->x;
    }
    if ( *(float *)((char *)p_x + (_DWORD)v30) > *(float *)((char *)&v12->m_vMinBounds.x + (_DWORD)vClipMax) )
    {
      CSimpleBSPFile::SplitBrush(
        this,
        pBrush: (CSimpleBSPFile *)v12,
        nPlaneIndex: *(_DWORD *)((char *)p_x + (_DWORD)v29),
        ppFrontBrush: (CCopyableUtlVector<Vector>_vtbl **)&pMapBrush,
        ppBackBrush: (Vector **)&vClipMin);
      if ( v12 != nullptr )
      {
        v12->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v12->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->m_Sides.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Sides.m_Memory.m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        v21 = v12->m_Sides.m_Memory.m_pMemory;
        v12->m_Sides.m_pElements = v21;
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v12);
      }
      v22 = &vClipMin->m_vMinBounds;
      if ( vClipMin != nullptr )
      {
        v23 = &vClipMin->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
        vClipMin->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: v23);
        if ( v22[3].x >= 0.0 )
        {
          if ( LODWORD(v22[2].y) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v22[2].y));
            v22[2].y = 0.0;
          }
          v22[2].z = 0.0;
        }
        y = v22[2].y;
        v22[3].z = y;
        if ( v22[3].x >= 0.0 )
        {
          if ( y != 0.0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(y));
            v22[2].y = 0.0;
          }
          v22[2].z = 0.0;
        }
        free(pMem: v22);
      }
      v12 = pMapBrush;
      if ( pMapBrush == nullptr )
        return nullptr;
      p_x = &v33->x;
    }
    ++p_x;
    vClipMax = (const Vector *)((char *)vClipMax + 4);
    v33 = (Vector *)p_x;
    if ( (int)vClipMax >= 8 )
      break;
    v14 = v32;
    v15 = v31;
  }
  v25 = 0;
  if ( v12->m_Sides.m_Size > 0 )
  {
    v26 = 0;
    do
    {
      v27 = v12->m_Sides.m_Memory.m_pMemory;
      v28 = v27[v26].m_nPlaneIndex & 0xFFFFFFFE;
      if ( v28 == *nClipMinPlanes || v28 == nClipMinPlanes[1] || v28 == *nClipMaxPlanes || v28 == nClipMaxPlanes[1] )
        v27[v26].m_nTextureInfoIndex = -1;
      ++v25;
      ++v26;
    }
    while ( v25 < v12->m_Sides.m_Size );
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x100612F0
// Name: private: void CSimpleBSPFile::BuildBSPChildren(class CBSPNode __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildBSPChildren(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList)
{
  int BestSplitPlane; // eax
  int m_nGrowSize; // ecx
  CBSPBrush **m_pMemory; // ecx
  int m_nAllocationCount; // ecx
  int m_Size; // ecx
  CBSPBrush **m_pElements; // ecx
  CBSPBrush *v12; // ecx
  int m_ContentsFlags; // edx
  int v14; // edi
  int v15; // esi
  int *p_m_nTextureInfoIndex; // ecx
  int v17; // ecx
  int *p_m_nGrowSize; // eax
  int i; // edi
  CBSPBrush *v20; // eax
  CBSPNode **m_pChildren; // edi
  CBSPNode *v22; // eax
  CBSPNode *v23; // esi
  bool v24; // zf
  CBSPNode **v25; // edi
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v26; // esi
  char *v27; // esi
  int j; // edi
  void *v29; // eax
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > childLists[2]; // [esp+Ch] [ebp-34h] BYREF
  char v31; // [esp+34h] [ebp-Ch] BYREF
  CBSPNode **v32; // [esp+38h] [ebp-8h]
  int unionFlags; // [esp+3Ch] [ebp-4h]
  int allContentsSolid; // [esp+48h] [ebp+8h]
  char allContentsSolid_3; // [esp+4Bh] [ebp+Bh]
  CBSPBrush **pBrushLista; // [esp+4Ch] [ebp+Ch]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushListb; // [esp+4Ch] [ebp+Ch]
  int pBrushListc; // [esp+4Ch] [ebp+Ch]

  unionFlags = (int)this;
  BestSplitPlane = CSimpleBSPFile::FindBestSplitPlane(this, pBrushList);
  if ( BestSplitPlane == -1 )
  {
    m_nGrowSize = pNode->m_ClippedBrushes.m_Memory.m_nGrowSize;
    pNode->m_ClippedBrushes.m_Memory.m_nGrowSize = pBrushList->m_Memory.m_nGrowSize;
    pBrushList->m_Memory.m_nGrowSize = m_nGrowSize;
    m_pMemory = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
    pNode->m_ClippedBrushes.m_Memory.m_pMemory = pBrushList->m_Memory.m_pMemory;
    pBrushList->m_Memory.m_pMemory = m_pMemory;
    m_nAllocationCount = pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount;
    pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount = pBrushList->m_Memory.m_nAllocationCount;
    pBrushList->m_Memory.m_nAllocationCount = m_nAllocationCount;
    m_Size = pNode->m_ClippedBrushes.m_Size;
    pNode->m_ClippedBrushes.m_Size = pBrushList->m_Size;
    pBrushList->m_Size = m_Size;
    m_pElements = pNode->m_ClippedBrushes.m_pElements;
    pNode->m_ClippedBrushes.m_pElements = pBrushList->m_pElements;
    pBrushList->m_pElements = m_pElements;
    unionFlags = 0;
    allContentsSolid_3 = 0;
    if ( pNode->m_ClippedBrushes.m_Size <= 0 )
      goto LABEL_14;
    pBrushLista = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
    v32 = (CBSPNode **)pNode->m_ClippedBrushes.m_Size;
    do
    {
      v12 = *pBrushLista;
      m_ContentsFlags = (*pBrushLista)->m_ContentsFlags;
      if ( (m_ContentsFlags & 1) != 0 )
      {
        v14 = v12->m_Sides.m_Size;
        v15 = 0;
        if ( v14 > 0 )
        {
          p_m_nTextureInfoIndex = &v12->m_Sides.m_Memory.m_pMemory->m_nTextureInfoIndex;
          do
          {
            if ( *p_m_nTextureInfoIndex != -1 )
              break;
            ++v15;
            p_m_nTextureInfoIndex += 9;
          }
          while ( v15 < v14 );
        }
        if ( v15 == v14 )
          allContentsSolid_3 = 1;
      }
      unionFlags |= m_ContentsFlags;
      ++pBrushLista;
      v32 = (CBSPNode **)((char *)v32 - 1);
    }
    while ( v32 != nullptr );
    if ( allContentsSolid_3 != 0 )
      pNode->m_ContentsFlags = 1;
    else
LABEL_14:
      pNode->m_ContentsFlags = unionFlags;
  }
  else
  {
    pNode->m_nSplitPlaneIndex = BestSplitPlane;
    v17 = 1;
    p_m_nGrowSize = &childLists[0].m_Memory.m_nGrowSize;
    do
    {
      *(p_m_nGrowSize - 2) = 0;
      *(p_m_nGrowSize - 1) = 0;
      *p_m_nGrowSize = 0;
      p_m_nGrowSize[1] = 0;
      p_m_nGrowSize[2] = 0;
      p_m_nGrowSize += 5;
      --v17;
    }
    while ( v17 >= 0 );
    CSimpleBSPFile::SplitBrushList(
      this,
      pBrushList,
      pNode,
      pFrontChildList: (CBSPBrush *)childLists,
      pBackChildList: (CBSPBrush *)&childLists[1]);
    for ( i = 0; i < pBrushList->m_Size; ++i )
    {
      v20 = pBrushList->m_Memory.m_pMemory[i];
      pBrushListb = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)v20;
      if ( v20 != nullptr )
      {
        v20->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: &v20->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        free(pMem: pBrushListb);
      }
      pBrushList->m_Memory.m_pMemory[i] = nullptr;
    }
    m_pChildren = pNode->m_pChildren;
    pBrushList->m_Size = 0;
    v32 = pNode->m_pChildren;
    pBrushListc = 2;
    do
    {
      v22 = (CBSPNode *)operator new(nSize: 0x70u);
      v23 = v22;
      if ( v22 != nullptr )
      {
        v22->m_pParent = nullptr;
        v22->m_ContentsFlags = 0;
        v22->m_nSplitPlaneIndex = -1;
        v22->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
        v22->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
        v22->m_ClippedBrushes.m_Memory.m_nGrowSize = 0;
        v22->m_ClippedBrushes.m_Size = 0;
        v22->m_ClippedBrushes.m_pElements = nullptr;
        v22->m_Faces.m_Memory.m_pMemory = nullptr;
        v22->m_Faces.m_Memory.m_nAllocationCount = 0;
        v22->m_Faces.m_Memory.m_nGrowSize = 0;
        v22->m_Faces.m_Size = 0;
        v22->m_Faces.m_pElements = nullptr;
        v22->m_Portals.m_Memory.m_pMemory = nullptr;
        v22->m_Portals.m_Memory.m_nAllocationCount = 0;
        v22->m_Portals.m_Memory.m_nGrowSize = 0;
        v22->m_Portals.m_Size = 0;
        v22->m_Portals.m_pElements = nullptr;
        v22->m_nClusterIndex = -1;
        v22->m_bEntityCanReach = false;
        v22->m_pChildren[1] = nullptr;
        v22->m_pChildren[0] = nullptr;
        ClearBounds(mins: &v22->m_vMinBounds, maxs: &v22->m_vMaxBounds);
      }
      else
      {
        v23 = nullptr;
      }
      *m_pChildren++ = v23;
      v24 = pBrushListc-- == 1;
      v23->m_pParent = pNode;
    }
    while ( !v24 );
    v25 = v32;
    v26 = childLists;
    for ( allContentsSolid = 2; allContentsSolid != 0; --allContentsSolid )
      CSimpleBSPFile::BuildBSPChildren(this: (CSimpleBSPFile *)unionFlags, pNode: *v25++, pBrushList: v26++);
    v27 = &v31;
    for ( j = 1; j >= 0; --j )
    {
      v27 -= 20;
      *((_DWORD *)v27 + 3) = 0;
      if ( *((int *)v27 + 2) >= 0 )
      {
        if ( *(_DWORD *)v27 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v27);
          *(_DWORD *)v27 = 0;
        }
        *((_DWORD *)v27 + 1) = 0;
      }
      v29 = *(void **)v27;
      *((_DWORD *)v27 + 4) = *(_DWORD *)v27;
      if ( *((int *)v27 + 2) >= 0 )
      {
        if ( v29 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
          *(_DWORD *)v27 = 0;
        }
        *((_DWORD *)v27 + 1) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061550
// Name: public: CSimpleBSPFile::~CSimpleBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::~CSimpleBSPFile(CSimpleBSPFile *this)
{
  int i; // edi
  CBSPModel *v3; // ecx
  unsigned __int8 *m_pMemory; // eax
  BSPCluster_t *v5; // eax
  CBSPFace *v6; // eax
  CBSPModel **v7; // eax
  HashedPlane_t *v8; // eax
  CBSPModel *pMem; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_Models.m_Size; ++i )
  {
    v3 = this->m_Models.m_Memory.m_pMemory[i];
    pMem = v3;
    if ( v3 != nullptr )
    {
      CBSPModel::~CBSPModel(this: v3);
      free(pMem);
    }
  }
  this->m_VisibilityData.m_Size = 0;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VisibilityData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VisibilityData.m_Memory.m_pMemory);
      this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_VisibilityData.m_Memory.m_pMemory;
  this->m_VisibilityData.m_pElements = m_pMemory;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Clusters.m_Size = 0;
  if ( this->m_Clusters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clusters.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clusters.m_Memory.m_pMemory);
      this->m_Clusters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Clusters.m_Memory.m_pMemory;
  this->m_Clusters.m_pElements = v5;
  if ( this->m_Clusters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_Clusters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(this: &this->m_DisplacementFaces);
  if ( this->m_DisplacementFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DisplacementFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DisplacementFaces.m_Memory.m_pMemory);
      this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_DisplacementFaces.m_Memory.m_pMemory;
  this->m_DisplacementFaces.m_pElements = v6;
  if ( this->m_DisplacementFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Models.m_Size = 0;
  if ( this->m_Models.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Models.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Models.m_Memory.m_pMemory);
      this->m_Models.m_Memory.m_pMemory = nullptr;
    }
    this->m_Models.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_Models.m_Memory.m_pMemory;
  this->m_Models.m_pElements = v7;
  if ( this->m_Models.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Models.m_Memory.m_pMemory = nullptr;
    }
    this->m_Models.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  this->m_PlaneHash.m_Planes.m_Size = 0;
  if ( this->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PlaneHash.m_Planes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PlaneHash.m_Planes.m_Memory.m_pMemory);
      this->m_PlaneHash.m_Planes.m_Memory.m_pMemory = nullptr;
    }
    this->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
  this->m_PlaneHash.m_Planes.m_pElements = v8;
  if ( this->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_PlaneHash.m_Planes.m_Memory.m_pMemory = nullptr;
    }
    this->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100617A0
// Name: private: void CSimpleBSPFile::CreateBSPBrushList(struct MapBrush_t const __near *,int,bool,bool,class Vector const __near &,class Vector const __near &,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateBSPBrushList(
        CSimpleBSPFile *this,
        CBSPBrush *pMapBrushes,
        const MapBrush_t *nBrushCount,
        bool bIncludeDetail,
        bool bIncludeStructural,
        Vector *vClipMin,
        const Vector *vClipMax,
        CUtlMemory<vgui::TreeNode *,int> *pBSPBrushList)
{
  const Vector *v8; // esi
  CPlaneHash *p_m_PlaneHash; // edi
  int PlaneIndex; // eax
  float v11; // xmm0_4
  const CSimpleMapFile *v12; // eax
  CBSPBrush *v14; // ecx
  CBSPBrush *v15; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CBSPBrush **v18; // ecx
  int v19; // eax
  CBSPBrush **v20; // edi
  bool v21; // zf
  Vector vNormal; // [esp+Ch] [ebp-30h] BYREF
  int nClipMinPlanes; // [esp+18h] [ebp-24h] BYREF
  int nMinPlanes[2]; // [esp+1Ch] [ebp-20h] BYREF
  int nMaxPlanes[2]; // [esp+24h] [ebp-18h]
  CSimpleBSPFile *v26; // [esp+2Ch] [ebp-10h]
  int v27; // [esp+30h] [ebp-Ch]
  int v28; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]
  const MapBrush_t *v30; // [esp+44h] [ebp+8h]
  const MapBrush_t *pMapBrushesa; // [esp+48h] [ebp+Ch]

  v8 = vClipMax;
  v28 = (char *)&nMinPlanes[1] - (char *)vClipMax;
  v27 = (char *)vClipMin - (char *)vClipMax;
  nMaxPlanes[1] = (int)this;
  p_m_PlaneHash = &this->m_PlaneHash;
  v26 = (CSimpleBSPFile *)((char *)&nClipMinPlanes - (char *)vClipMax);
  for ( i = 2; i != 0; --i )
  {
    memset(&vNormal, 0, sizeof(vNormal));
    *(float *)((char *)&v8->x + (char *)&vNormal - (char *)vClipMax) = 1.0;
    PlaneIndex = CPlaneHash::FindPlaneIndex(this: p_m_PlaneHash, &vNormal, flDistance: v8->x);
    v11 = *(float *)((char *)&v8->x + v27);
    *(_DWORD *)((char *)&v8->x + v28) = PlaneIndex;
    v12 = (const CSimpleMapFile *)CPlaneHash::FindPlaneIndex(this: p_m_PlaneHash, &vNormal, flDistance: v11);
    *(_DWORD *)((char *)&v8->x + (_DWORD)v26) = v12;
    v8 = (const Vector *)((char *)v8 + 4);
  }
  if ( (int)nBrushCount > 0 )
  {
    v14 = pMapBrushes;
    pMapBrushesa = (const MapBrush_t *)pMapBrushes;
    v30 = nBrushCount;
    do
    {
      if ( bIncludeDetail && (LODWORD(v14->m_vMinBounds.x) & 0x8000000) != 0
        || bIncludeStructural && (LODWORD(v14->m_vMinBounds.x) & 0x8000000) == 0 )
      {
        v15 = CSimpleBSPFile::CreateClippedBrush(
                this: (CSimpleBSPFile *)nMaxPlanes[1],
                pMapBrush: v14,
                (CBSPBrush *)vClipMin,
                vClipMax,
                &nClipMinPlanes,
                nClipMaxPlanes: &nMinPlanes[1]);
        if ( v15 != nullptr )
        {
          m_pMemory = (int)pBSPBrushList[1].m_pMemory;
          m_nAllocationCount = pBSPBrushList->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: pBSPBrushList,
              num: m_pMemory - m_nAllocationCount + 1);
          ++pBSPBrushList[1].m_pMemory;
          v18 = (CBSPBrush **)pBSPBrushList->m_pMemory;
          v19 = (int)pBSPBrushList[1].m_pMemory - m_pMemory - 1;
          pBSPBrushList[1].m_nAllocationCount = (int)pBSPBrushList->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v18[m_pMemory + 1],
              src: (unsigned __int8 *)&v18[m_pMemory],
              count: 4 * v19);
          v20 = (CBSPBrush **)&pBSPBrushList->m_pMemory[m_pMemory];
          if ( v20 != nullptr )
            *v20 = v15;
        }
      }
      v14 = (CBSPBrush *)&pMapBrushesa[1];
      v21 = v30 == (const MapBrush_t *)1;
      v30 = (const MapBrush_t *)((char *)v30 - 1);
      ++pMapBrushesa;
    }
    while ( !v21 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061900
// Name: private: class CBSPTree __near * CSimpleBSPFile::BuildBSPTree(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CSimpleBSPFile *__thiscall CSimpleBSPFile::BuildBSPTree(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList,
        const Vector *vMin,
        const Vector *vMax)
{
  char *v5; // eax
  char *v6; // esi
  CBSPNode *v7; // eax
  const CSimpleMapFile *v8; // eax
  int i; // esi
  int v10; // esi
  Vector *v11; // ebx
  CSimpleBSPFile *v12; // esi
  Vector vNormal; // [esp+Ch] [ebp-14h] BYREF
  CSimpleBSPFile *v15; // [esp+18h] [ebp-8h]
  CSimpleBSPFile *v16; // [esp+1Ch] [ebp-4h]

  v15 = this;
  v5 = (char *)operator new(nSize: 0x8Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    *(_DWORD *)v5 = 0;
    CBSPNode::CBSPNode(this: (CBSPNode *)(v5 + 4));
    ClearBounds(mins: (Vector *)(v6 + 116), maxs: (Vector *)(v6 + 128));
    v16 = (CSimpleBSPFile *)v6;
  }
  else
  {
    v16 = nullptr;
  }
  v7 = (CBSPNode *)operator new(nSize: 0x70u);
  if ( v7 != nullptr )
    v8 = (const CSimpleMapFile *)CBSPNode::CBSPNode(this: v7);
  else
    v8 = nullptr;
  v16->m_pMapFile = v8;
  for ( i = 0; i < 3; ++i )
  {
    vNormal = vec3_origin;
    *((_DWORD *)&vNormal.x + i) = 1065353216;
    CPlaneHash::FindPlaneIndex(
      this: &this->m_PlaneHash,
      &vNormal,
      flDistance: *(float *)((char *)&vNormal.x + 4 * i + (char *)vMax - (char *)&vNormal));
    *((_DWORD *)&vNormal.x + i) = -1082130432;
    CPlaneHash::FindPlaneIndex(
      this: &this->m_PlaneHash,
      &vNormal,
      flDistance: COERCE_FLOAT(*(_DWORD *)((char *)&vNormal.x + 4 * i + (char *)vMin - (char *)&vNormal) ^ _mask__NegFloat_));
  }
  v10 = 0;
  if ( pBrushList->m_Size > 0 )
  {
    v11 = (Vector *)&v16->m_PlaneHash.m_HashTable[25];
    do
    {
      AddPointToBounds(
        v: &pBrushList->m_Memory.m_pMemory[v10]->m_vMinBounds,
        mins: (Vector *)&v16->m_PlaneHash.m_HashTable[22],
        maxs: v11);
      AddPointToBounds(
        v: &pBrushList->m_Memory.m_pMemory[v10++]->m_vMaxBounds,
        mins: (Vector *)&v16->m_PlaneHash.m_HashTable[22],
        maxs: v11);
    }
    while ( v10 < pBrushList->m_Size );
  }
  v12 = v16;
  CSimpleBSPFile::BuildBSPChildren(this: v15, pNode: (CBSPNode *)v16->m_pMapFile, pBrushList);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10061A60
// Name: private: void CSimpleBSPFile::PopulateTreeWithDetail(class CBSPTree const __near *,int,int,class CUtlVector<class CBSPFace __near *,class CUtlMemory<class CBSPFace __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::PopulateTreeWithDetail(
        CSimpleBSPFile *this,
        const CBSPTree *pTree,
        int nFirstBrush,
        const MapBrush_t *nNumBrushes,
        CUtlMemory<vgui::TreeNode *,int> *pDetailFaceList)
{
  const CSimpleMapFile *m_pMapFile; // eax
  __int64 v6; // xmm0_8
  int v7; // esi
  __int64 v8; // xmm0_8
  CBSPBrush **m_pMemory; // ecx
  CBSPBrushSide *v11; // edi
  int v12; // eax
  char *v13; // edi
  CBSPFace *v14; // esi
  int v15; // edi
  int m_nAllocationCount; // eax
  CBSPFace **v17; // ecx
  int v18; // eax
  CBSPFace **v19; // eax
  bool v20; // zf
  CBSPFace *v21; // edi
  CBSPFace **v22; // ecx
  Vector *v23; // eax
  int i; // edi
  CBSPBrush *v25; // [esp-1Ch] [ebp-84h]
  CBSPFace clonedFace; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > detailBrushes; // [esp+34h] [ebp-34h] BYREF
  Vector vClipMin; // [esp+48h] [ebp-20h] BYREF
  Vector vClipMax; // [esp+54h] [ebp-14h] BYREF
  int m_Size; // [esp+60h] [ebp-8h]
  CSimpleBSPFile *v31; // [esp+64h] [ebp-4h]
  int nFirstBrusha; // [esp+74h] [ebp+Ch]
  int j; // [esp+78h] [ebp+10h]
  CBSPBrush **pDetailFaceLista; // [esp+7Ch] [ebp+14h]

  v31 = this;
  m_pMapFile = this->m_pMapFile;
  v6 = *(_QWORD *)&this->m_pMapFile->m_vMaxBounds.x;
  vClipMax.z = this->m_pMapFile->m_vMaxBounds.z;
  vClipMin.z = m_pMapFile->m_vMinBounds.z;
  v7 = 0;
  *(_QWORD *)&vClipMax.x = v6;
  v8 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
  v25 = (CBSPBrush *)&m_pMapFile->m_Brushes.m_Memory.m_pMemory[nFirstBrush];
  memset(&detailBrushes, 0, sizeof(detailBrushes));
  *(_QWORD *)&vClipMin.x = v8;
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: v25,
    nBrushCount: nNumBrushes,
    bIncludeDetail: true,
    bIncludeStructural: false,
    &vClipMin,
    &vClipMax,
    pBSPBrushList: (CUtlMemory<vgui::TreeNode *,int> *)&detailBrushes);
  if ( detailBrushes.m_Size > 0 )
  {
    m_pMemory = detailBrushes.m_Memory.m_pMemory;
    pDetailFaceLista = detailBrushes.m_Memory.m_pMemory;
    m_Size = detailBrushes.m_Size;
    do
    {
      if ( LOBYTE((*m_pMemory)->m_ContentsFlags) != 0 )
      {
        j = 0;
        if ( (*m_pMemory)->m_Sides.m_Size > 0 )
        {
          nFirstBrusha = 0;
          do
          {
            v11 = (*m_pMemory)->m_Sides.m_Memory.m_pMemory;
            v12 = *(int *)((char *)&v11->m_nTextureInfoIndex + v7);
            v13 = (char *)v11 + v7;
            if ( v12 != -1 && SLOBYTE(v31->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[v12].m_SurfaceFlags) >= 0 )
            {
              v14 = (CBSPFace *)operator new(nSize: 0x28u);
              if ( v14 != nullptr )
              {
                v14->m_nTextureInfoIndex = *((_DWORD *)v13 + 1);
                v14->m_nPlaneIndex = *(_DWORD *)v13;
                v14->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
                v14->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
                v14->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
                v14->m_Polygon.m_Points.m_Size = 0;
                v14->m_Polygon.m_Points.m_pElements = nullptr;
                v14->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
                CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
                  this: &v14->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                  pArray: *((const Vector **)v13 + 4),
                  size: *((_DWORD *)v13 + 7));
                v14->m_nDisplacementIndex = -1;
                v14->m_nSerializedFaceIndex = -1;
              }
              else
              {
                v14 = nullptr;
              }
              v15 = (int)pDetailFaceList[1].m_pMemory;
              m_nAllocationCount = pDetailFaceList->m_nAllocationCount;
              if ( v15 + 1 > m_nAllocationCount )
                CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                  this: pDetailFaceList,
                  num: v15 - m_nAllocationCount + 1);
              ++pDetailFaceList[1].m_pMemory;
              v17 = (CBSPFace **)pDetailFaceList->m_pMemory;
              v18 = (int)pDetailFaceList[1].m_pMemory - v15 - 1;
              pDetailFaceList[1].m_nAllocationCount = (int)pDetailFaceList->m_pMemory;
              if ( v18 > 0 )
                _V_memmove(dest: (unsigned __int8 *)&v17[v15 + 1], src: (unsigned __int8 *)&v17[v15], count: 4 * v18);
              v19 = (CBSPFace **)&pDetailFaceList->m_pMemory[v15];
              if ( v19 != nullptr )
                *v19 = v14;
              SubdivideFaceForLightmaps(pMapFile: v31->m_pMapFile, pFaceList: pDetailFaceList, nOriginalFaceIndex: v15);
              m_pMemory = pDetailFaceLista;
            }
            v7 = nFirstBrusha + 36;
            ++j;
            nFirstBrusha += 36;
          }
          while ( j < (*m_pMemory)->m_Sides.m_Size );
          v7 = 0;
        }
      }
      ++m_pMemory;
      v20 = m_Size-- == 1;
      pDetailFaceLista = m_pMemory;
    }
    while ( !v20 );
  }
  if ( (int)pDetailFaceList[1].m_pMemory > 0 )
  {
    do
    {
      v21 = (CBSPFace *)pDetailFaceList->m_pMemory[v7];
      clonedFace.m_nTextureInfoIndex = v21->m_nTextureInfoIndex;
      clonedFace.m_nPlaneIndex = v21->m_nPlaneIndex;
      memset(
        &clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        0,
        sizeof(clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
      clonedFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        this: &clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        pArray: v21->m_Polygon.m_Points.m_Memory.m_pMemory,
        size: v21->m_Polygon.m_Points.m_Size);
      v22 = (CBSPFace **)pDetailFaceList->m_pMemory;
      clonedFace.m_nDisplacementIndex = v21->m_nDisplacementIndex;
      clonedFace.m_nSerializedFaceIndex = v21->m_nSerializedFaceIndex;
      CSimpleBSPFile::FilterFaceIntoTree(
        this: v31,
        pNode: pTree->m_pRoot,
        pClippedFace: &clonedFace,
        pOriginalFace: v22[v7]);
      v23 = clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory;
      clonedFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      clonedFace.m_Polygon.m_Points.m_Size = 0;
      if ( clonedFace.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory);
          v23 = nullptr;
          clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        clonedFace.m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      clonedFace.m_Polygon.m_Points.m_pElements = v23;
      if ( clonedFace.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 && v23 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      ++v7;
    }
    while ( v7 < (int)pDetailFaceList[1].m_pMemory );
  }
  for ( i = 0; i < detailBrushes.m_Size; ++i )
    CSimpleBSPFile::FilterBrushIntoTree(
      this: v31,
      pNode: (CBSPBrush *)pTree->m_pRoot,
      pBrush: (CBSPNode *)detailBrushes.m_Memory.m_pMemory[i]);
  if ( detailBrushes.m_Memory.m_nGrowSize >= 0 && detailBrushes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: detailBrushes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10061D30
// Name: private: void CSimpleBSPFile::ProcessEntity(struct MapEntity_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::ProcessEntity(CSimpleBSPFile *this, const MapEntity_t *pEntity)
{
  CBSPBrush *v3; // edx
  char *v4; // eax
  char *v5; // esi
  int v6; // ecx
  int m_nAllocationCount; // eax
  CBSPModel **m_pMemory; // edx
  int v9; // eax
  CBSPModel **v10; // ecx
  CBSPTree *v11; // eax
  const MapBrush_t *m_nNumBrushes; // [esp-24h] [ebp-54h]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > brushList; // [esp+0h] [ebp-30h] BYREF
  Vector vMin; // [esp+14h] [ebp-1Ch] BYREF
  Vector vMax; // [esp+20h] [ebp-10h] BYREF
  int m_Size; // [esp+2Ch] [ebp-4h]

  m_nNumBrushes = (const MapBrush_t *)pEntity->m_nNumBrushes;
  v3 = (CBSPBrush *)&this->m_pMapFile->m_Brushes.m_Memory.m_pMemory[pEntity->m_nFirstBrushIndex];
  vMin.x = -16384.0;
  vMin.y = -16384.0;
  vMin.z = -16384.0;
  vMax.x = 16384.0;
  vMax.y = 16384.0;
  vMax.z = 16384.0;
  memset(&brushList, 0, sizeof(brushList));
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: v3,
    nBrushCount: m_nNumBrushes,
    bIncludeDetail: true,
    bIncludeStructural: true,
    vClipMin: &vMin,
    vClipMax: &vMax,
    pBSPBrushList: (CUtlMemory<vgui::TreeNode *,int> *)&brushList);
  v4 = (char *)operator new(nSize: 0x44u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
    *((_DWORD *)v4 + 5) = 0;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 8) = 0;
    *((_DWORD *)v4 + 9) = 0;
    *((_DWORD *)v4 + 10) = 0;
    ClearBounds(mins: (Vector *)(v4 + 44), maxs: (Vector *)(v4 + 56));
  }
  else
  {
    v5 = nullptr;
  }
  m_nAllocationCount = this->m_Models.m_Memory.m_nAllocationCount;
  m_Size = this->m_Models.m_Size;
  v6 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Models,
      num: m_Size - m_nAllocationCount + 1);
    v6 = m_Size;
  }
  ++this->m_Models.m_Size;
  m_pMemory = this->m_Models.m_Memory.m_pMemory;
  v9 = this->m_Models.m_Size - v6 - 1;
  this->m_Models.m_pElements = m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v6 + 1], src: (unsigned __int8 *)&m_pMemory[v6], count: 4 * v9);
    v6 = m_Size;
  }
  v10 = &this->m_Models.m_Memory.m_pMemory[v6];
  if ( v10 != nullptr )
    *v10 = (CBSPModel *)v5;
  v11 = (CBSPTree *)CSimpleBSPFile::BuildBSPTree(this, pBrushList: &brushList, &vMin, &vMax);
  *(_DWORD *)v5 = v11;
  CSimpleBSPFile::BuildTreePortals(this, pTree: v11, pPortalList: (CUtlMemory<vgui::TreeNode *,int> *)v5 + 2);
  CSimpleBSPFile::MakeFacesFromPortals(this, pModel: (CBSPModel *)v5);
  CSimpleBSPFile::PruneNodes(
    this,
    pNode: **(CBSPNode ***)v5,
    pPortalList: (CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *)(v5 + 24));
  CSimpleBSPFile::NumberPortalFaces(this, pNode: **(CBSPNode ***)v5);
  CSimpleBSPFile::PopulateTreeWithDetail(
    this,
    pTree: *(const CBSPTree **)v5,
    nFirstBrush: pEntity->m_nFirstBrushIndex,
    nNumBrushes: (const MapBrush_t *)pEntity->m_nNumBrushes,
    pDetailFaceList: (CUtlMemory<vgui::TreeNode *,int> *)(v5 + 4));
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&brushList);
}

//------------------------------------------------------------------------------
// Address: 0x10061ED0
// Name: private: class CBSPNode __near * CSimpleBSPFile::CreateGridNode(int,int)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CSimpleBSPFile::CreateGridNode(CSimpleBSPFile *this, CBSPNode *nX, int nY)
{
  const CSimpleMapFile *m_pMapFile; // eax
  MapEntity_t *m_pMemory; // ecx
  int m_nFirstBrushIndex; // ecx
  MapBrush_t *v7; // edx
  CBSPNode *v8; // eax
  CBSPNode *v9; // esi
  CSimpleBSPFile *v11; // esi
  const MapBrush_t *m_nNumBrushes; // [esp-1Ch] [ebp-50h]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > clippedBrushes; // [esp+8h] [ebp-2Ch] BYREF
  Vector vMin; // [esp+1Ch] [ebp-18h] BYREF
  Vector vMax; // [esp+28h] [ebp-Ch] BYREF
  CBSPNode *pNewNode; // [esp+3Ch] [ebp+8h]

  vMin.x = (float)(int)((_DWORD)nX << 10);
  vMin.y = (float)(nY << 10);
  vMin.z = -16384.0;
  m_pMapFile = this->m_pMapFile;
  vMax.x = (float)(((_DWORD)nX << 10) + 1024);
  m_pMemory = m_pMapFile->m_Entities.m_Memory.m_pMemory;
  m_nNumBrushes = (const MapBrush_t *)m_pMemory->m_nNumBrushes;
  m_nFirstBrushIndex = m_pMemory->m_nFirstBrushIndex;
  v7 = m_pMapFile->m_Brushes.m_Memory.m_pMemory;
  vMax.y = (float)((nY << 10) + 1024);
  vMax.z = 16384.0;
  memset(&clippedBrushes, 0, sizeof(clippedBrushes));
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: (CBSPBrush *)&v7[m_nFirstBrushIndex],
    nBrushCount: m_nNumBrushes,
    bIncludeDetail: false,
    bIncludeStructural: true,
    vClipMin: &vMin,
    vClipMax: &vMax,
    pBSPBrushList: (CUtlMemory<vgui::TreeNode *,int> *)&clippedBrushes);
  if ( clippedBrushes.m_Size != 0 )
  {
    v11 = CSimpleBSPFile::BuildBSPTree(this, pBrushList: &clippedBrushes, &vMin, &vMax);
    pNewNode = (CBSPNode *)v11->m_pMapFile;
    v11->m_pMapFile = nullptr;
    CBSPNode::~CBSPNode(this: (CBSPNode *)&v11->m_PlaneHash);
    free(pMem: v11);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&clippedBrushes);
    return pNewNode;
  }
  else
  {
    v8 = (CBSPNode *)operator new(nSize: 0x70u);
    if ( v8 != nullptr )
    {
      v9 = CBSPNode::CBSPNode(this: v8);
      v9->m_ContentsFlags = 1;
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&clippedBrushes);
      return v9;
    }
    else
    {
      MEMORY[0x10] = 1;
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&clippedBrushes);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062030
// Name: private: void CSimpleBSPFile::ProcessWorldEntity(struct MapEntity_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::ProcessWorldEntity(CSimpleBSPFile *this, const MapEntity_t *pEntity)
{
  char *v3; // eax
  char *v4; // esi
  char *v5; // ebx
  int v6; // ecx
  int m_nAllocationCount; // eax
  CBSPModel **m_pMemory; // edx
  int v9; // eax
  CBSPModel **v10; // ecx
  char *v11; // eax
  char *v12; // esi
  const CSimpleMapFile *m_pMapFile; // ecx
  int i; // eax
  __int64 v15; // xmm0_8
  int v16; // esi
  float v17; // esi
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __int64 v23; // xmm0_8
  int v24; // esi
  float v25; // esi
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  int v31; // ecx
  int v32; // eax
  int v33; // esi
  int v34; // esi
  CBSPNode *GridNode; // eax
  int v36; // ecx
  float v37; // eax
  int v38; // ecx
  CBSPNode *ppNodeList[1024]; // [esp+Ch] [ebp-1048h] BYREF
  __int64 v40; // [esp+100Ch] [ebp-48h]
  float v41; // [esp+1014h] [ebp-40h]
  __int64 v42; // [esp+1018h] [ebp-3Ch]
  float v43; // [esp+1020h] [ebp-34h]
  __int64 v44; // [esp+1024h] [ebp-30h]
  float z; // [esp+102Ch] [ebp-28h]
  __int64 v46; // [esp+1030h] [ebp-24h]
  float v47; // [esp+1038h] [ebp-1Ch]
  int nX; // [esp+103Ch] [ebp-18h]
  int m_Size; // [esp+1040h] [ebp-14h]
  int nAbsoluteMaxs; // [esp+1044h] [ebp-10h] BYREF
  int v51; // [esp+1048h] [ebp-Ch]
  int nAbsoluteMins; // [esp+104Ch] [ebp-8h] BYREF
  int nY; // [esp+1050h] [ebp-4h]

  v3 = (char *)operator new(nSize: 0x44u);
  v4 = v3;
  v5 = nullptr;
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    *((_DWORD *)v3 + 10) = 0;
    ClearBounds(mins: (Vector *)(v3 + 44), maxs: (Vector *)(v3 + 56));
    v5 = v4;
  }
  m_nAllocationCount = this->m_Models.m_Memory.m_nAllocationCount;
  m_Size = this->m_Models.m_Size;
  v6 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Models,
      num: m_Size - m_nAllocationCount + 1);
    v6 = m_Size;
  }
  ++this->m_Models.m_Size;
  m_pMemory = this->m_Models.m_Memory.m_pMemory;
  v9 = this->m_Models.m_Size - v6 - 1;
  this->m_Models.m_pElements = m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v6 + 1], src: (unsigned __int8 *)&m_pMemory[v6], count: 4 * v9);
    v6 = m_Size;
  }
  v10 = &this->m_Models.m_Memory.m_pMemory[v6];
  if ( v10 != nullptr )
    *v10 = (CBSPModel *)v5;
  v11 = (char *)operator new(nSize: 0x8Cu);
  v12 = v11;
  if ( v11 != nullptr )
  {
    *(_DWORD *)v11 = 0;
    CBSPNode::CBSPNode(this: (CBSPNode *)(v11 + 4));
    ClearBounds(mins: (Vector *)(v12 + 116), maxs: (Vector *)(v12 + 128));
  }
  else
  {
    v12 = nullptr;
  }
  *(_DWORD *)v5 = v12;
  m_pMapFile = this->m_pMapFile;
  nY = -16;
  nAbsoluteMins = -16;
  v51 = 15;
  nAbsoluteMaxs = 15;
  for ( i = 0; i < 8; i += 4 )
  {
    v15 = *(_QWORD *)&m_pMapFile->m_vMaxBounds.x;
    z = m_pMapFile->m_vMaxBounds.z;
    v16 = *(int *)((char *)&nAbsoluteMaxs + i);
    v44 = v15;
    if ( (float)(v16 << 10) > *(float *)((char *)&v44 + i) )
    {
      v17 = m_pMapFile->m_vMaxBounds.z;
      v42 = *(_QWORD *)&m_pMapFile->m_vMaxBounds.x;
      v43 = v17;
      v18 = (__m128)*(unsigned int *)((char *)&v42 + i);
      v18.m128_f32[0] = v18.m128_f32[0] * 0.0009765625;
      v19 = _mm_and_ps((__m128)0x80000000, v18);
      v20.m128_i32[0] = 1258291200;
      v20.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v18, v19), v20).m128_f32[0]) & 0x4B000000
                      | v19.m128_i32[0];
      v21 = v18;
      v21.m128_f32[0] = (float)(v18.m128_f32[0] + v20.m128_f32[0]) - v20.m128_f32[0];
      v22 = v21;
      v22.m128_f32[0] = v21.m128_f32[0] - v18.m128_f32[0];
      *(int *)((char *)&nAbsoluteMaxs + i) = (int)(float)(v21.m128_f32[0]
                                                        - COERCE_FLOAT(_mm_cmpgt_ss(v22, v19).m128_u32[0] & 0x3F800000));
    }
    v23 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
    v41 = m_pMapFile->m_vMinBounds.z;
    v24 = *(int *)((char *)&nAbsoluteMins + i) + 1;
    v40 = v23;
    if ( *(float *)((char *)&v40 + i) > (float)(v24 << 10) )
    {
      v25 = m_pMapFile->m_vMinBounds.z;
      v46 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
      v47 = v25;
      v26 = (__m128)*(unsigned int *)((char *)&v46 + i);
      v26.m128_f32[0] = v26.m128_f32[0] * 0.0009765625;
      v27 = _mm_and_ps((__m128)0x80000000, v26);
      v28.m128_i32[0] = 1258291200;
      v28.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v26, v27), v28).m128_f32[0]) & 0x4B000000
                      | v27.m128_i32[0];
      v29 = v26;
      v29.m128_f32[0] = (float)(v26.m128_f32[0] + v28.m128_f32[0]) - v28.m128_f32[0];
      v30 = v29;
      v30.m128_f32[0] = v29.m128_f32[0] - v26.m128_f32[0];
      *(int *)((char *)&nAbsoluteMins + i) = (int)(float)(v29.m128_f32[0]
                                                        - COERCE_FLOAT(_mm_cmpgt_ss(v30, v27).m128_u32[0] & 0x3F800000));
    }
    if ( *(int *)((char *)&nAbsoluteMins + i) < -16 )
      *(int *)((char *)&nAbsoluteMins + i) = -16;
    if ( *(int *)((char *)&nAbsoluteMaxs + i) > 15 )
      *(int *)((char *)&nAbsoluteMaxs + i) = 15;
  }
  memset(ppNodeList, 0, sizeof(ppNodeList));
  v31 = nY;
  v32 = nAbsoluteMins;
  v33 = nAbsoluteMaxs;
  m_Size = nY;
  if ( nY <= v51 )
  {
    do
    {
      nX = v32;
      if ( v32 <= v33 )
      {
        do
        {
          v34 = nX + (v31 - nY) * (v33 - v32 + 1) - v32;
          GridNode = CSimpleBSPFile::CreateGridNode(this, (CBSPNode *)nX, nY: v31);
          v31 = m_Size;
          ppNodeList[v34] = GridNode;
          v33 = nAbsoluteMaxs;
          ++nX;
          v32 = nAbsoluteMins;
        }
        while ( nX <= nAbsoluteMaxs );
      }
      m_Size = ++v31;
    }
    while ( v31 <= v51 );
    v31 = nY;
  }
  **(_DWORD **)v5 = CSimpleBSPFile::GenerateBSPGrid(
                      this,
                      nMinX: v32 - 1,
                      nMinY: v31 - 1,
                      nMaxX: v33 + 1,
                      nMaxY: v51 + 1,
                      &nAbsoluteMins,
                      &nAbsoluteMaxs,
                      ppNodeList);
  *(float *)(*(_DWORD *)v5 + 116) = (float)(nAbsoluteMins << 10);
  *(float *)(*(_DWORD *)v5 + 120) = (float)(nY << 10);
  v36 = *(_DWORD *)v5;
  v47 = this->m_pMapFile->m_vMinBounds.z;
  *(float *)(v36 + 124) = v47 - 8.0;
  *(float *)(*(_DWORD *)v5 + 128) = (float)((nAbsoluteMaxs + 1) << 10);
  *(float *)(*(_DWORD *)v5 + 132) = (float)((v51 + 1) << 10);
  v37 = this->m_pMapFile->m_vMaxBounds.z;
  v38 = *(_DWORD *)v5;
  v46 = *(_QWORD *)&this->m_pMapFile->m_vMaxBounds.x;
  v47 = v37;
  *(float *)(v38 + 136) = v37 + 8.0;
  CSimpleBSPFile::BuildTreePortals(
    this,
    pTree: *(CBSPTree **)v5,
    pPortalList: (CUtlMemory<vgui::TreeNode *,int> *)v5 + 2);
  CSimpleBSPFile::FloodEntities(this, pTree: *(CBSPTree **)v5);
  CSimpleBSPFile::MakeFacesFromPortals(this, pModel: (CBSPModel *)v5);
  CSimpleBSPFile::PruneNodes(
    this,
    pNode: **(CBSPNode ***)v5,
    pPortalList: (CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *)(v5 + 24));
  CSimpleBSPFile::NumberPortalFaces(this, pNode: **(CBSPNode ***)v5);
  CSimpleBSPFile::PopulateTreeWithDetail(
    this,
    pTree: *(const CBSPTree **)v5,
    nFirstBrush: this->m_pMapFile->m_Entities.m_Memory.m_pMemory->m_nFirstBrushIndex,
    nNumBrushes: (const MapBrush_t *)this->m_pMapFile->m_Entities.m_Memory.m_pMemory->m_nNumBrushes,
    pDetailFaceList: (CUtlMemory<vgui::TreeNode *,int> *)(v5 + 4));
  CSimpleBSPFile::BuildRadialVisibilityData(this, pRootNode: ***(CBSPNode ****)this->m_Models.m_Memory.m_pMemory);
  CSimpleBSPFile::CreateDisplacementFaces(this);
}

//------------------------------------------------------------------------------
// Address: 0x10062490
// Name: public: void CSimpleBSPFile::CreateFromMapFile(class CSimpleMapFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateFromMapFile(CSimpleBSPFile *this, const CSimpleMapFile *pMapFile)
{
  const CSimpleMapFile *v2; // esi
  CSimpleBSPFile *v3; // edi
  CPlaneHash *p_m_PlaneHash; // ebx
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *v5; // eax
  int *m_HashTable; // eax
  int j; // edx
  int v8; // eax
  MapEntity_t *m_pMemory; // edx
  MapEntity_t *v10; // ebx
  CBSPModel *v11; // eax
  int v12; // esi
  const Vector *v13; // edi
  const MapEntity_t *v14; // [esp-4h] [ebp-20h]
  Vector *mins; // [esp+10h] [ebp-Ch]
  Vector *maxs; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v2 = pMapFile;
  v3 = this;
  this->m_pMapFile = pMapFile;
  p_m_PlaneHash = &this->m_PlaneHash;
  if ( pMapFile == (const CSimpleMapFile *)-8 )
    v5 = nullptr;
  else
    v5 = &pMapFile->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
    this: &this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
    other: v5);
  m_HashTable = p_m_PlaneHash->m_HashTable;
  for ( j = 1024; j != 0; --j )
  {
    *m_HashTable = *(int *)((char *)m_HashTable + (char *)&pMapFile->m_PlaneHash - (char *)p_m_PlaneHash);
    ++m_HashTable;
  }
  v8 = 0;
  i = 0;
  if ( pMapFile->m_Entities.m_Size > 0 )
  {
    do
    {
      m_pMemory = v2->m_Entities.m_Memory.m_pMemory;
      v10 = &m_pMemory[v8];
      if ( v10->m_nNumBrushes > 0 )
      {
        v14 = &m_pMemory[v8];
        if ( v8 != 0 )
          CSimpleBSPFile::ProcessEntity(this: v3, pEntity: v14);
        else
          CSimpleBSPFile::ProcessWorldEntity(this: v3, pEntity: v14);
        v11 = v3->m_Models.m_Memory.m_pMemory[v3->m_Models.m_Size - 1];
        v12 = 0;
        if ( v10->m_nNumBrushes > 0 )
        {
          maxs = &v11->m_vMaxBounds;
          mins = &v11->m_vMinBounds;
          do
          {
            v13 = (const Vector *)&v3->m_pMapFile->m_Brushes.m_Memory.m_pMemory[v12 + v10->m_nFirstBrushIndex];
            AddPointToBounds(v: v13 + 1, mins, maxs);
            AddPointToBounds(v: v13 + 2, mins, maxs);
            v3 = this;
            ++v12;
          }
          while ( v12 < v10->m_nNumBrushes );
        }
        v8 = i;
        v2 = pMapFile;
      }
      i = ++v8;
    }
    while ( v8 < v2->m_Entities.m_Size );
  }
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x0040CC50
// Name: private: void CSimpleBSPFile::MakeUnreachableNodesSolid(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::MakeUnreachableNodesSolid(CSimpleBSPFile *this, CBSPNode *pNode)
{
  CBSPNode *i; // esi

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: i->m_pChildren[0]);
  if ( !i->m_bEntityCanReach )
    i->m_ContentsFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x0040CDD0
// Name: public: int CBSPPortal::GetNodeIndexForFace(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBSPPortal::GetNodeIndexForFace(CBSPPortal *this)
{
  int m_ContentsFlags; // eax
  int v2; // edx
  int v3; // ecx

  m_ContentsFlags = this->m_pNodes[0]->m_ContentsFlags;
  v2 = 1;
  v3 = m_ContentsFlags ^ this->m_pNodes[1]->m_ContentsFlags;
  while ( (v3 & v2) == 0 )
  {
    v2 *= 2;
    if ( v2 > 128 )
    {
      v2 = 0;
      return (v2 & m_ContentsFlags) != 0;
    }
  }
  return (v2 & m_ContentsFlags) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE90
// Name: private: enum PlaneSide_t CSimpleBSPFile::GetPrimaryPlaneSide(class CBSPBrush __near *,struct Plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __thiscall CSimpleBSPFile::GetPrimaryPlaneSide(CSimpleBSPFile *this, CBSPBrush *pBrush, Plane_t *pPlane)
{
  int m_Size; // edx
  float v4; // xmm0_4
  PlaneSide_t result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v6; // ecx
  int v7; // ebx
  int v8; // edx
  Vector *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // esi
  float *v15; // edx
  unsigned int v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float *p_x; // ecx
  int v22; // ebx
  float v23; // xmm1_4
  bool v24; // zf
  int j; // [esp+0h] [ebp-8h]
  int v26; // [esp+4h] [ebp-4h]
  CBSPBrush *pBrusha; // [esp+10h] [ebp+8h]

  m_Size = pBrush->m_Sides.m_Size;
  v4 = 0.0;
  result = PLANE_SIDE_FRONT;
  if ( m_Size <= 0 )
    return result;
  v6 = &pBrush->m_Sides.m_Memory.m_pMemory->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  pBrusha = (CBSPBrush *)v6;
  v26 = m_Size;
  do
  {
    v7 = v6->m_Size;
    v8 = 0;
    if ( v7 < 4 )
      goto LABEL_27;
    m_pMemory = v6->m_Memory.m_pMemory;
    y = pPlane->m_vNormal.y;
    x = pPlane->m_vNormal.x;
    z = pPlane->m_vNormal.z;
    m_flDistance = pPlane->m_flDistance;
    p_z = &m_pMemory->z;
    v15 = &m_pMemory[1].z;
    v16 = ((unsigned int)(v7 - 4) >> 2) + 1;
    j = 4 * v16;
    do
    {
      v17 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(*p_z * z)) - m_flDistance;
      if ( v17 <= v4 )
      {
        v17 = -v17;
        if ( v17 <= v4 )
          goto LABEL_10;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v17;
LABEL_10:
      v18 = (float)((float)((float)(*(v15 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v15)) - m_flDistance;
      if ( v18 <= v4 )
      {
        v18 = -v18;
        if ( v18 <= v4 )
          goto LABEL_15;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v18;
LABEL_15:
      v19 = (float)((float)((float)(v15[2] * y) + (float)(p_z[4] * x)) + (float)(v15[3] * z)) - m_flDistance;
      if ( v19 <= v4 )
      {
        v19 = -v19;
        if ( v19 <= v4 )
          goto LABEL_20;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v19;
LABEL_20:
      v20 = (float)((float)((float)(v15[5] * y) + (float)(p_z[7] * x)) + (float)(v15[6] * z)) - m_flDistance;
      if ( v20 <= v4 )
      {
        v20 = -v20;
        if ( v20 <= v4 )
          goto LABEL_25;
        result = PLANE_SIDE_BACK;
      }
      else
      {
        result = PLANE_SIDE_FRONT;
      }
      v4 = v20;
LABEL_25:
      p_z += 12;
      v15 += 12;
      --v16;
    }
    while ( v16 != 0 );
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)pBrusha;
    v8 = j;
LABEL_27:
    if ( v8 >= v7 )
      goto LABEL_36;
    p_x = &v6->m_Memory.m_pMemory[v8].x;
    v22 = v7 - v8;
    while ( 2 )
    {
      v23 = (float)((float)((float)(p_x[1] * pPlane->m_vNormal.y) + (float)(pPlane->m_vNormal.x * *p_x))
                  + (float)(p_x[2] * pPlane->m_vNormal.z))
          - pPlane->m_flDistance;
      if ( v23 > v4 )
      {
        result = PLANE_SIDE_FRONT;
        goto LABEL_33;
      }
      v23 = -v23;
      if ( v23 > v4 )
      {
        result = PLANE_SIDE_BACK;
LABEL_33:
        v4 = v23;
      }
      p_x += 3;
      if ( --v22 != 0 )
        continue;
      break;
    }
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)pBrusha;
LABEL_36:
    v6 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)v6 + 36);
    v24 = v26-- == 1;
    pBrusha = (CBSPBrush *)v6;
  }
  while ( !v24 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D0C0
// Name: private: enum PlaneSide_t CSimpleBSPFile::TestBrushAgainstPlaneIndex(class CBSPBrush __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __thiscall CSimpleBSPFile::TestBrushAgainstPlaneIndex(
        CSimpleBSPFile *this,
        CBSPBrush *pBrush,
        int nPlaneIndex,
        int *nNumSplits)
{
  CBSPBrush *v4; // esi
  int m_Size; // edi
  int v6; // edx
  CBSPBrushSide *v7; // ecx
  HashedPlane_t *v8; // ebx
  PlaneSide_t result; // eax
  CBSPBrushSide *v10; // eax
  int v11; // edi
  int v12; // edx
  Vector *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // esi
  float *v19; // edx
  unsigned int v20; // ecx
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float *p_x; // ecx
  int v26; // edi
  float v27; // xmm0_4
  int j; // [esp+10h] [ebp-14h]
  int ia; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h]
  int nBackPoints; // [esp+20h] [ebp-4h]
  int nFrontPoints; // [esp+30h] [ebp+Ch]

  v4 = pBrush;
  *nNumSplits = 0;
  m_Size = pBrush->m_Sides.m_Size;
  v6 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    v8 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[nPlaneIndex];
    result = GetPlaneSide(vMin: &pBrush->m_vMinBounds, vMax: &pBrush->m_vMaxBounds, pPlane: v8);
    if ( result == PLANE_SIDE_BOTH )
    {
      ia = 0;
      if ( pBrush->m_Sides.m_Size > 0 )
      {
        v31 = 0;
        do
        {
          v10 = &v4->m_Sides.m_Memory.m_pMemory[v31];
          if ( v10->m_nTextureInfoIndex != -1 )
          {
            v11 = v10->m_Polygon.m_Points.m_Size;
            v12 = 0;
            nFrontPoints = 0;
            nBackPoints = 0;
            if ( v11 >= 4 )
            {
              m_pMemory = v10->m_Polygon.m_Points.m_Memory.m_pMemory;
              y = v8->m_vNormal.y;
              x = v8->m_vNormal.x;
              z = v8->m_vNormal.z;
              m_flDistance = v8->m_flDistance;
              p_z = &m_pMemory->z;
              v19 = &m_pMemory[1].z;
              v20 = ((unsigned int)(v11 - 4) >> 2) + 1;
              j = 4 * v20;
              do
              {
                v21 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(*p_z * z))
                    - m_flDistance;
                if ( v21 <= 0.1 )
                {
                  if ( v21 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v22 = (float)((float)((float)(*(v19 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v19)) - m_flDistance;
                if ( v22 <= 0.1 )
                {
                  if ( v22 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v23 = (float)((float)((float)(v19[2] * y) + (float)(p_z[4] * x)) + (float)(v19[3] * z)) - m_flDistance;
                if ( v23 <= 0.1 )
                {
                  if ( v23 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                v24 = (float)((float)((float)(v19[5] * y) + (float)(p_z[7] * x)) + (float)(v19[6] * z)) - m_flDistance;
                if ( v24 <= 0.1 )
                {
                  if ( v24 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                p_z += 12;
                v19 += 12;
                --v20;
              }
              while ( v20 != 0 );
              v4 = pBrush;
              v12 = j;
            }
            if ( v12 < v11 )
            {
              p_x = &v10->m_Polygon.m_Points.m_Memory.m_pMemory[v12].x;
              v26 = v11 - v12;
              do
              {
                v27 = (float)((float)((float)(p_x[1] * v8->m_vNormal.y) + (float)(v8->m_vNormal.x * *p_x))
                            + (float)(p_x[2] * v8->m_vNormal.z))
                    - v8->m_flDistance;
                if ( v27 <= 0.1 )
                {
                  if ( v27 < -0.1 )
                    ++nBackPoints;
                }
                else
                {
                  ++nFrontPoints;
                }
                p_x += 3;
                --v26;
              }
              while ( v26 != 0 );
              v4 = pBrush;
            }
            if ( nFrontPoints > 0 && nBackPoints > 0 && (v10->m_SurfaceFlags & 0x200) == 0 )
              ++*nNumSplits;
          }
          ++v31;
          ++ia;
        }
        while ( ia < v4->m_Sides.m_Size );
        return PLANE_SIDE_BOTH;
      }
    }
  }
  else
  {
    v7 = pBrush->m_Sides.m_Memory.m_pMemory;
    while ( 1 )
    {
      if ( nPlaneIndex == v7->m_nPlaneIndex )
        return PLANE_SIDE_FACING|PLANE_SIDE_BACK;
      if ( nPlaneIndex == (v7->m_nPlaneIndex ^ 1) )
        return PLANE_SIDE_FACING|PLANE_SIDE_FRONT;
      ++v6;
      ++v7;
      if ( v6 >= m_Size )
        goto LABEL_6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040D370
// Name: private: void CSimpleBSPFile::FloodFillThroughPortals(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FloodFillThroughPortals(CSimpleBSPFile *this, CBSPNode *pNode)
{
  int v2; // edi
  CBSPPortal *v4; // ecx
  CBSPNode *v5; // eax

  v2 = 0;
  for ( pNode->m_bEntityCanReach = true; v2 < pNode->m_Portals.m_Size; ++v2 )
  {
    v4 = pNode->m_Portals.m_Memory.m_pMemory[v2];
    v5 = v4->m_pNodes[0];
    if ( v4->m_pNodes[0] == pNode )
      v5 = v4->m_pNodes[1];
    if ( !v5->m_bEntityCanReach && (v5->m_ContentsFlags & 1) == 0 )
      CSimpleBSPFile::FloodFillThroughPortals(this, pNode: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D3C0
// Name: private: void CSimpleBSPFile::NumberPortalFaces(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::NumberPortalFaces(CSimpleBSPFile *this, CBSPNode *pNode)
{
  int i; // eax

  while ( 1 )
  {
    for ( i = 0; i < pNode->m_Faces.m_Size; ++i )
      pNode->m_Faces.m_Memory.m_pMemory[i]->m_nSerializedFaceIndex = this->m_nNextFaceIndex++;
    if ( pNode->m_nSplitPlaneIndex == -1 )
      break;
    CSimpleBSPFile::NumberPortalFaces(this, pNode: pNode->m_pChildren[0]);
    pNode = pNode->m_pChildren[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D5C0
// Name: public: CBSPNode::CBSPNode(void)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CBSPNode::CBSPNode(CBSPNode *this)
{
  this->m_pParent = nullptr;
  this->m_ContentsFlags = 0;
  this->m_nSplitPlaneIndex = -1;
  this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
  this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  this->m_ClippedBrushes.m_Memory.m_nGrowSize = 0;
  this->m_ClippedBrushes.m_Size = 0;
  this->m_ClippedBrushes.m_pElements = nullptr;
  this->m_Faces.m_Memory.m_pMemory = nullptr;
  this->m_Faces.m_Memory.m_nAllocationCount = 0;
  this->m_Faces.m_Memory.m_nGrowSize = 0;
  this->m_Faces.m_Size = 0;
  this->m_Faces.m_pElements = nullptr;
  this->m_Portals.m_Memory.m_pMemory = nullptr;
  this->m_Portals.m_Memory.m_nAllocationCount = 0;
  this->m_Portals.m_Memory.m_nGrowSize = 0;
  this->m_Portals.m_Size = 0;
  this->m_Portals.m_pElements = nullptr;
  this->m_bEntityCanReach = false;
  this->m_pChildren[1] = nullptr;
  this->m_pChildren[0] = nullptr;
  this->m_nClusterIndex = -1;
  ClearBounds(mins: &this->m_vMinBounds, maxs: &this->m_vMaxBounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D620
// Name: private: class CBSPNode __near * CSimpleBSPFile::GenerateBSPGrid(int,int,int,int,int __near * const,int __near * const,class CBSPNode __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CSimpleBSPFile::GenerateBSPGrid(
        CSimpleBSPFile *this,
        int nMinX,
        int nMinY,
        int nMaxX,
        int nMaxY,
        int *nAbsoluteMins,
        int *nAbsoluteMaxs,
        CBSPNode **ppNodeList)
{
  int v10; // edx
  CBSPNode *v12; // eax
  CBSPNode *v13; // eax
  CBSPNode *v14; // esi
  CBSPNode *BSPGrid; // eax
  CBSPNode *v16; // edx
  Vector vNormal; // [esp+10h] [ebp-Ch] BYREF
  int nMidY; // [esp+28h] [ebp+Ch]
  int nMidYa; // [esp+28h] [ebp+Ch]

  if ( nMinX == nMaxX && nMinY == nMaxY )
  {
    if ( nMinX < *nAbsoluteMins
      || nMaxX > *nAbsoluteMaxs
      || (v10 = nAbsoluteMins[1], nMinY < v10)
      || nMaxY > nAbsoluteMaxs[1] )
    {
      v12 = (CBSPNode *)operator new(nSize: 0x70u);
      if ( v12 != nullptr )
        return CBSPNode::CBSPNode(this: v12);
      else
        return nullptr;
    }
    else
    {
      return *(&ppNodeList[nMinX] + (nMinY - v10) * (*nAbsoluteMaxs - *nAbsoluteMins + 1) - *nAbsoluteMins);
    }
  }
  else
  {
    v13 = (CBSPNode *)operator new(nSize: 0x70u);
    if ( v13 != nullptr )
      v14 = CBSPNode::CBSPNode(this: v13);
    else
      v14 = nullptr;
    if ( nMaxX - nMinX <= nMaxY - nMinY )
    {
      nMidYa = (nMaxY - nMinY) / 2 + nMinY + 1;
      vNormal.x = 0.0;
      vNormal.z = 0.0;
      vNormal.y = 1.0;
      v14->m_nSplitPlaneIndex = CPlaneHash::FindPlaneIndex(
                                  this: &this->m_PlaneHash,
                                  &vNormal,
                                  flDistance: (float)(nMidYa << 10));
      v14->m_pChildren[0] = CSimpleBSPFile::GenerateBSPGrid(
                              this,
                              nMinX,
                              nMinY: nMidYa,
                              nMaxX,
                              nMaxY,
                              nAbsoluteMins,
                              nAbsoluteMaxs,
                              ppNodeList);
      BSPGrid = CSimpleBSPFile::GenerateBSPGrid(
                  this,
                  nMinX,
                  nMinY,
                  nMaxX,
                  nMaxY: (nMaxY - nMinY) / 2 + nMinY,
                  nAbsoluteMins,
                  nAbsoluteMaxs,
                  ppNodeList);
    }
    else
    {
      vNormal.x = 1.0;
      nMidY = (nMaxX - nMinX) / 2 + nMinX + 1;
      vNormal.y = 0.0;
      vNormal.z = 0.0;
      v14->m_nSplitPlaneIndex = CPlaneHash::FindPlaneIndex(
                                  this: &this->m_PlaneHash,
                                  &vNormal,
                                  flDistance: (float)(nMidY << 10));
      v14->m_pChildren[0] = CSimpleBSPFile::GenerateBSPGrid(
                              this,
                              nMinX: nMidY,
                              nMinY,
                              nMaxX,
                              nMaxY,
                              nAbsoluteMins,
                              nAbsoluteMaxs,
                              ppNodeList);
      BSPGrid = CSimpleBSPFile::GenerateBSPGrid(
                  this,
                  nMinX,
                  nMinY,
                  nMaxX: (nMaxX - nMinX) / 2 + nMinX,
                  nMaxY,
                  nAbsoluteMins,
                  nAbsoluteMaxs,
                  ppNodeList);
    }
    v16 = v14->m_pChildren[0];
    v14->m_pChildren[1] = BSPGrid;
    v16->m_pParent = v14;
    v14->m_pChildren[1]->m_pParent = v14;
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D800
// Name: private: int CSimpleBSPFile::FindBestSplitPlane(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleBSPFile::FindBestSplitPlane(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList)
{
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v2; // ecx
  int m_Size; // esi
  int v4; // edi
  int v5; // eax
  CBSPBrush *v6; // edx
  CBSPBrushSide *v7; // eax
  bool v8; // zf
  int v9; // ebx
  int v10; // ecx
  unsigned int v11; // edi
  CBSPBrush *v12; // esi
  PlaneSide_t v13; // eax
  int v14; // edx
  CBSPBrushSide *m_pMemory; // ecx
  signed int v16; // eax
  int v17; // eax
  CBitVec<2048> testedFlags; // [esp+Ch] [ebp-140h] BYREF
  CBSPBrushSide *pBrushSide; // [esp+10Ch] [ebp-40h]
  CBSPBrush *pBrush; // [esp+110h] [ebp-3Ch]
  PlaneSide_t planeSide; // [esp+114h] [ebp-38h]
  int nBestValue; // [esp+118h] [ebp-34h]
  int nSide; // [esp+11Ch] [ebp-30h]
  int nBrush; // [esp+120h] [ebp-2Ch]
  int nBestPlane; // [esp+124h] [ebp-28h]
  CSimpleBSPFile *v27; // [esp+128h] [ebp-24h]
  int nFacing; // [esp+12Ch] [ebp-20h]
  int nBack; // [esp+130h] [ebp-1Ch]
  unsigned int v30; // [esp+134h] [ebp-18h]
  int nTestBrush; // [esp+138h] [ebp-14h]
  int nSplits; // [esp+13Ch] [ebp-10h]
  int nFront; // [esp+140h] [ebp-Ch]
  int nFlagIndex; // [esp+144h] [ebp-8h]
  int nBrushSplits; // [esp+148h] [ebp-4h] BYREF

  v27 = this;
  nBestPlane = -1;
  nBestValue = -99999;
  memset(dst: (unsigned __int8 *)&testedFlags, value: 0, count: sizeof(testedFlags));
  v2 = pBrushList;
  m_Size = pBrushList->m_Size;
  v4 = 0;
  v5 = 0;
  nFlagIndex = 0;
  nBrush = 0;
  if ( m_Size <= 0 )
    return -1;
  do
  {
    v6 = v2->m_Memory.m_pMemory[v5];
    pBrush = v6;
    nSide = 0;
    if ( v6->m_Sides.m_Size > 0 )
    {
      v30 = 0;
      do
      {
        v7 = &v6->m_Sides.m_Memory.m_pMemory[v30 / 0x24];
        v8 = v7->m_nTextureInfoIndex == -1;
        pBrushSide = v7;
        if ( v8 )
        {
          nFlagIndex = ++v4;
        }
        else if ( ((1 << (v4 & 0x1F)) & testedFlags.m_Ints[v4 >> 5]) != 0 )
        {
          nFlagIndex = ++v4;
        }
        else
        {
          v9 = 0;
          v10 = 0;
          v11 = v7->m_nPlaneIndex & 0xFFFFFFFE;
          nFront = 0;
          nBack = 0;
          nFacing = 0;
          nSplits = 0;
          nTestBrush = 0;
          if ( m_Size > 0 )
          {
            do
            {
              v12 = pBrushList->m_Memory.m_pMemory[nTestBrush];
              nBrushSplits = 0;
              v13 = CSimpleBSPFile::TestBrushAgainstPlaneIndex(
                      this: v27,
                      pBrush: v12,
                      nPlaneIndex: v11,
                      nNumSplits: &nBrushSplits);
              nSplits += nBrushSplits;
              planeSide = v13;
              v12->m_nTempSplitSide = v13;
              if ( (v13 & 4) != 0 )
              {
                ++nFacing;
                v14 = __ROL4__(1, v9);
                if ( v12->m_Sides.m_Size > 0 )
                {
                  m_pMemory = v12->m_Sides.m_Memory.m_pMemory;
                  nBrushSplits = v12->m_Sides.m_Size;
                  do
                  {
                    if ( (m_pMemory->m_nPlaneIndex & 0xFFFFFFFE) == v11 )
                    {
                      testedFlags.m_Ints[v9 >> 5] |= v14;
                      LOBYTE(v13) = planeSide;
                    }
                    ++v9;
                    v14 = __ROL4__(v14, 1);
                    ++m_pMemory;
                    --nBrushSplits;
                  }
                  while ( nBrushSplits != 0 );
                }
              }
              if ( (v13 & 1) != 0 )
                ++nFront;
              if ( (v13 & 2) != 0 )
                ++nBack;
              m_Size = pBrushList->m_Size;
              ++nTestBrush;
            }
            while ( nTestBrush < m_Size );
            v10 = nFacing;
          }
          v16 = 5 * (v10 - nSplits) - abs32(nFront - nBack);
          if ( v27->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v11].m_Type < 3 )
            v16 += 5;
          if ( (pBrushSide->m_SurfaceFlags & 0x10) != 0 )
            v16 -= 500;
          if ( v16 > nBestValue )
          {
            m_Size = pBrushList->m_Size;
            nBestValue = v16;
            v17 = 0;
            for ( nBestPlane = v11; v17 < m_Size; ++v17 )
            {
              pBrushList->m_Memory.m_pMemory[v17]->m_nSplitSide = pBrushList->m_Memory.m_pMemory[v17]->m_nTempSplitSide;
              m_Size = pBrushList->m_Size;
            }
          }
          v4 = ++nFlagIndex;
          v6 = pBrush;
        }
        v30 += 36;
        ++nSide;
      }
      while ( nSide < v6->m_Sides.m_Size );
      v2 = pBrushList;
      v5 = nBrush;
    }
    m_Size = v2->m_Size;
    nBrush = ++v5;
  }
  while ( v5 < m_Size );
  return nBestPlane;
}

//------------------------------------------------------------------------------
// Address: 0x0040DA20
// Name: private: void CSimpleBSPFile::FloodEntities(class CBSPTree __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FloodEntities(CSimpleBSPFile *this, CBSPTree *pTree)
{
  const CSimpleMapFile *m_pMapFile; // eax
  int v4; // ebx
  int v5; // esi
  const MapEntityKeyValuePair_t *Pair; // eax
  const char *PairValue; // eax
  float v8; // xmm0_4
  CBSPNode *m_pRoot; // ecx
  int i; // eax
  CBSPNode *v11; // edx
  int v12; // edx
  Vector vOrigin; // [esp+Ch] [ebp-Ch] BYREF

  m_pMapFile = this->m_pMapFile;
  v4 = 1;
  if ( this->m_pMapFile->m_Entities.m_Size > 1 )
  {
    v5 = 1;
    do
    {
      Pair = FindPair(
               pKeyName: "origin",
               pPairs: &m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory[m_pMapFile->m_Entities.m_Memory.m_pMemory[v5].m_nFirstKVPairIndex],
               nNumPairs: m_pMapFile->m_Entities.m_Memory.m_pMemory[v5].m_nNumKVPairs);
      if ( Pair != nullptr )
      {
        PairValue = GetPairValue(pPair: Pair);
        sscanf(string: PairValue, format: "%f %f %f", &vOrigin, &vOrigin.y, &vOrigin.z);
        v8 = vOrigin.z + 1.0;
        m_pRoot = pTree->m_pRoot;
        vOrigin.z = vOrigin.z + 1.0;
        for ( i = m_pRoot->m_nSplitPlaneIndex; i != -1; i = m_pRoot->m_nSplitPlaneIndex )
        {
          if ( this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_flDistance <= (float)((float)((float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.y * vOrigin.y)
                                                                                              + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.x * vOrigin.x))
                                                                                      + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[i].m_vNormal.z
                                                                                              * v8)) )
            m_pRoot = m_pRoot->m_pChildren[0];
          else
            m_pRoot = m_pRoot->m_pChildren[1];
        }
        if ( (m_pRoot->m_ContentsFlags & 1) == 0 )
          CSimpleBSPFile::FloodFillThroughPortals(this, pNode: m_pRoot);
      }
      m_pMapFile = this->m_pMapFile;
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_pMapFile->m_Entities.m_Size );
  }
  if ( pTree->m_OutsideNode.m_bEntityCanReach
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Entity can reach outside node; map is leaky.\n");
  }
  v11 = pTree->m_pRoot;
  if ( pTree->m_pRoot->m_nSplitPlaneIndex == -1 )
  {
    if ( !v11->m_bEntityCanReach )
      v11->m_ContentsFlags |= 1u;
  }
  else
  {
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: v11->m_pChildren[0]);
    CSimpleBSPFile::MakeUnreachableNodesSolid(this, pNode: *(CBSPNode **)(v12 + 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DC00
// Name: public: CBSPPortal::CBSPPortal(class CBSPPortal const __near &,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPPortal *__thiscall CBSPPortal::CBSPPortal(CBSPPortal *this, const CBSPPortal *other, Polygon_t *pPortalShape)
{
  CBSPPortal *result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v4; // ecx
  int m_nGrowSize; // edx
  Vector *m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  Vector *m_pElements; // edx

  result = this;
  this->m_pOnNode = other->m_pOnNode;
  v4 = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
  result->m_Polygon.m_Points.m_Size = 0;
  result->m_Polygon.m_Points.m_pElements = nullptr;
  result->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  result->m_Plane = other->m_Plane;
  result->m_PortalFaces.m_Memory.m_pMemory = nullptr;
  result->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  result->m_PortalFaces.m_Memory.m_nGrowSize = 0;
  result->m_PortalFaces.m_Size = 0;
  result->m_PortalFaces.m_pElements = nullptr;
  result->m_pNodes[0] = other->m_pNodes[0];
  result->m_pNodes[1] = other->m_pNodes[1];
  if ( pPortalShape != nullptr )
    v4 = &pPortalShape->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  m_nGrowSize = result->m_Polygon.m_Points.m_Memory.m_nGrowSize;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = v4->m_Memory.m_nGrowSize;
  v4->m_Memory.m_nGrowSize = m_nGrowSize;
  m_pMemory = result->m_Polygon.m_Points.m_Memory.m_pMemory;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = v4->m_Memory.m_pMemory;
  v4->m_Memory.m_pMemory = m_pMemory;
  m_nAllocationCount = result->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
  v4->m_Memory.m_nAllocationCount = m_nAllocationCount;
  m_Size = result->m_Polygon.m_Points.m_Size;
  result->m_Polygon.m_Points.m_Size = v4->m_Size;
  v4->m_Size = m_Size;
  m_pElements = result->m_Polygon.m_Points.m_pElements;
  result->m_Polygon.m_Points.m_pElements = v4->m_pElements;
  v4->m_pElements = m_pElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DCB0
// Name: public: CBSPFace::CBSPFace(class CBSPFace const __near &,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPFace *__thiscall CBSPFace::CBSPFace(CBSPFace *this, const CBSPFace *other, Polygon_t *pPolygon)
{
  CBSPFace *result; // eax
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v4; // ecx
  int m_nGrowSize; // edx
  Vector *m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  Vector *m_pElements; // edx

  result = this;
  this->m_nTextureInfoIndex = other->m_nTextureInfoIndex;
  this->m_nPlaneIndex = other->m_nPlaneIndex;
  v4 = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
  result->m_Polygon.m_Points.m_Size = 0;
  result->m_Polygon.m_Points.m_pElements = nullptr;
  result->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  result->m_nDisplacementIndex = -1;
  result->m_nSerializedFaceIndex = -1;
  if ( pPolygon != nullptr )
    v4 = &pPolygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  m_nGrowSize = result->m_Polygon.m_Points.m_Memory.m_nGrowSize;
  result->m_Polygon.m_Points.m_Memory.m_nGrowSize = v4->m_Memory.m_nGrowSize;
  v4->m_Memory.m_nGrowSize = m_nGrowSize;
  m_pMemory = result->m_Polygon.m_Points.m_Memory.m_pMemory;
  result->m_Polygon.m_Points.m_Memory.m_pMemory = v4->m_Memory.m_pMemory;
  v4->m_Memory.m_pMemory = m_pMemory;
  m_nAllocationCount = result->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
  result->m_Polygon.m_Points.m_Memory.m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
  v4->m_Memory.m_nAllocationCount = m_nAllocationCount;
  m_Size = result->m_Polygon.m_Points.m_Size;
  result->m_Polygon.m_Points.m_Size = v4->m_Size;
  v4->m_Size = m_Size;
  m_pElements = result->m_Polygon.m_Points.m_pElements;
  result->m_Polygon.m_Points.m_pElements = v4->m_pElements;
  v4->m_pElements = m_pElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040DD30
// Name: private: void CSimpleBSPFile::AssignClusterIndicesToLeaves(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::AssignClusterIndicesToLeaves(CSimpleBSPFile *this, CBSPNode *pNode)
{
  CBSPNode *i; // esi
  int v4; // eax

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: i->m_pChildren[0]);
  if ( (i->m_ContentsFlags & 1) == 0 )
  {
    v4 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: &this->m_Clusters);
    i->m_nClusterIndex = v4;
    this->m_Clusters.m_Memory.m_pMemory[v4].m_pLeafNode = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DD80
// Name: private: void CSimpleBSPFile::FilterFaceIntoTree(class CBSPNode __near *,class CBSPFace __near *,class CBSPFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FilterFaceIntoTree(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CBSPFace *pClippedFace,
        CBSPFace *pOriginalFace)
{
  int m_nSplitPlaneIndex; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPFace **m_pMemory; // ecx
  int v9; // eax
  CBSPFace **v10; // eax
  CSimpleBSPFile *v11; // eax
  HashedPlane_t *v12; // esi
  int v13; // eax
  int m_nGrowSize; // edx
  Vector *v15; // edx
  int v16; // edx
  Vector *m_pElements; // eax
  Vector *v18; // edx
  int v19; // edx
  CBSPFace newFace; // [esp+1Ch] [ebp-74h] BYREF
  Polygon_t frontPolygon; // [esp+44h] [ebp-4Ch] BYREF
  Polygon_t backPolygon; // [esp+5Ch] [ebp-34h] BYREF
  Polygon_t onPolygon; // [esp+74h] [ebp-1Ch] BYREF
  CSimpleBSPFile *v24; // [esp+8Ch] [ebp-4h]

  m_nSplitPlaneIndex = pNode->m_nSplitPlaneIndex;
  v24 = this;
  if ( m_nSplitPlaneIndex == -1 )
  {
    if ( (pNode->m_ContentsFlags & 1) == 0 )
    {
      m_Size = pNode->m_Faces.m_Size;
      m_nAllocationCount = pNode->m_Faces.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ColorRGBExp32,int>::Grow(
          this: (CUtlMemory<BSPCluster_t,int> *)&pNode->m_Faces,
          num: m_Size - m_nAllocationCount + 1);
      ++pNode->m_Faces.m_Size;
      m_pMemory = pNode->m_Faces.m_Memory.m_pMemory;
      v9 = pNode->m_Faces.m_Size - m_Size - 1;
      pNode->m_Faces.m_pElements = m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v10 = &pNode->m_Faces.m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        *v10 = pOriginalFace;
      if ( pOriginalFace->m_nSerializedFaceIndex == -1 )
      {
        v11 = v24;
        pOriginalFace->m_nSerializedFaceIndex = v24->m_nNextFaceIndex;
        ++v11->m_nNextFaceIndex;
      }
    }
  }
  else
  {
    v12 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[m_nSplitPlaneIndex];
    onPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    memset(
      &onPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(onPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    memset(
      &frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    memset(
      &backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    ChopPolygon(
      polygon: &pClippedFace->m_Polygon,
      vNormal: &v12->m_vNormal,
      flDistance: v12->m_flDistance,
      pOn: &onPolygon,
      pFront: &frontPolygon,
      pBack: &backPolygon);
    v13 = onPolygon.m_Points.m_Size;
    if ( onPolygon.m_Points.m_Size > 0 )
    {
      m_nGrowSize = onPolygon.m_Points.m_Memory.m_nGrowSize;
      if ( (float)((float)((float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.y
                                 * v12->m_vNormal.y)
                         + (float)(v12->m_vNormal.x
                                 * this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.x))
                 + (float)(this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pClippedFace->m_nPlaneIndex].m_vNormal.z
                         * v12->m_vNormal.z)) <= 0.0 )
      {
        onPolygon.m_Points.m_Memory.m_nGrowSize = backPolygon.m_Points.m_Memory.m_nGrowSize;
        backPolygon.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
        v18 = onPolygon.m_Points.m_Memory.m_pMemory;
        onPolygon.m_Points.m_Memory.m_pMemory = backPolygon.m_Points.m_Memory.m_pMemory;
        backPolygon.m_Points.m_Memory.m_pMemory = v18;
        v19 = onPolygon.m_Points.m_Memory.m_nAllocationCount;
        onPolygon.m_Points.m_Memory.m_nAllocationCount = backPolygon.m_Points.m_Memory.m_nAllocationCount;
        onPolygon.m_Points.m_Size = backPolygon.m_Points.m_Size;
        backPolygon.m_Points.m_Size = v13;
        m_pElements = backPolygon.m_Points.m_pElements;
        backPolygon.m_Points.m_Memory.m_nAllocationCount = v19;
        backPolygon.m_Points.m_pElements = onPolygon.m_Points.m_pElements;
      }
      else
      {
        onPolygon.m_Points.m_Memory.m_nGrowSize = frontPolygon.m_Points.m_Memory.m_nGrowSize;
        frontPolygon.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
        v15 = onPolygon.m_Points.m_Memory.m_pMemory;
        onPolygon.m_Points.m_Memory.m_pMemory = frontPolygon.m_Points.m_Memory.m_pMemory;
        frontPolygon.m_Points.m_Memory.m_pMemory = v15;
        v16 = onPolygon.m_Points.m_Memory.m_nAllocationCount;
        onPolygon.m_Points.m_Memory.m_nAllocationCount = frontPolygon.m_Points.m_Memory.m_nAllocationCount;
        onPolygon.m_Points.m_Size = frontPolygon.m_Points.m_Size;
        frontPolygon.m_Points.m_Size = v13;
        m_pElements = frontPolygon.m_Points.m_pElements;
        frontPolygon.m_Points.m_Memory.m_nAllocationCount = v16;
        frontPolygon.m_Points.m_pElements = onPolygon.m_Points.m_pElements;
      }
      onPolygon.m_Points.m_pElements = m_pElements;
    }
    if ( frontPolygon.m_Points.m_Size > 0 )
    {
      CBSPFace::CBSPFace(this: &newFace, other: pClippedFace, pPolygon: &frontPolygon);
      CSimpleBSPFile::FilterFaceIntoTree(this, pNode: pNode->m_pChildren[0], pClippedFace: &newFace, pOriginalFace);
      newFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&newFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    }
    if ( backPolygon.m_Points.m_Size > 0 )
    {
      CBSPFace::CBSPFace(this: &newFace, other: pClippedFace, pPolygon: &backPolygon);
      CSimpleBSPFile::FilterFaceIntoTree(this, pNode: pNode->m_pChildren[1], pClippedFace: &newFace, pOriginalFace);
      newFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&newFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    }
    backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    onPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&onPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DFF0
// Name: AttachPortalToNodes
// Source: json
//------------------------------------------------------------------------------
void __usercall AttachPortalToNodes(CBSPNode *pNode0@<eax>, CBSPPortal *pPortal, CBSPNode *pNode1)
{
  CUtlMemory<BSPCluster_t,int> *p_m_Portals; // esi
  int m_nAllocationCount; // eax
  BSPCluster_t *m_pMemory; // edi
  BSPCluster_t *v6; // ecx
  int v7; // eax
  BSPCluster_t *v8; // eax
  int m_Size; // edi
  int v10; // eax
  CBSPPortal **v11; // ecx
  int v12; // eax
  CBSPPortal **v13; // eax

  p_m_Portals = (CUtlMemory<BSPCluster_t,int> *)&pNode0->m_Portals;
  pPortal->m_pNodes[0] = pNode0;
  pPortal->m_pNodes[1] = pNode1;
  m_nAllocationCount = pNode0->m_Portals.m_Memory.m_nAllocationCount;
  m_pMemory = p_m_Portals[1].m_pMemory;
  if ( (int)&m_pMemory->m_pLeafNode + 1 > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Portals, num: (int)&m_pMemory->m_pLeafNode - m_nAllocationCount + 1);
  ++p_m_Portals[1].m_pMemory;
  v6 = p_m_Portals->m_pMemory;
  v7 = (char *)p_m_Portals[1].m_pMemory - (char *)m_pMemory - 1;
  p_m_Portals[1].m_nAllocationCount = (int)p_m_Portals->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &v6[(_DWORD)m_pMemory + 1], src: &v6[(_DWORD)m_pMemory], count: 4 * v7);
  v8 = &p_m_Portals->m_pMemory[(_DWORD)m_pMemory];
  if ( v8 != nullptr )
    v8->m_pLeafNode = (const CBSPNode *)pPortal;
  m_Size = pNode1->m_Portals.m_Size;
  v10 = pNode1->m_Portals.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > v10 )
    CUtlMemory<ColorRGBExp32,int>::Grow(this: (CUtlMemory<BSPCluster_t,int> *)&pNode1->m_Portals, num: m_Size - v10 + 1);
  ++pNode1->m_Portals.m_Size;
  v11 = pNode1->m_Portals.m_Memory.m_pMemory;
  v12 = pNode1->m_Portals.m_Size - m_Size - 1;
  pNode1->m_Portals.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
  v13 = &pNode1->m_Portals.m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = pPortal;
}

//------------------------------------------------------------------------------
// Address: 0x0040E0B0
// Name: SubdivideFaceForLightmaps
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubdivideFaceForLightmaps(const CSimpleMapFile *pMapFile, CBSPFace *pFaceList, int nOriginalFaceIndex)
{
  CBSPFace *v4; // eax
  MapTextureInfo_t *v5; // ecx
  float *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  __m128 v10; // xmm2
  float v11; // xmm5_4
  int m_Size; // edi
  int v13; // ebx
  Vector *m_pMemory; // ecx
  float *p_z; // edx
  float *v16; // ecx
  unsigned int v17; // eax
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  __m128 v20; // xmm0
  __m128 v21; // xmm0
  int v22; // eax
  int v23; // edi
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  double v29; // st7
  double v30; // st7
  CBSPFace *v31; // ebx
  CBSPFace *v32; // eax
  CBSPFace *v33; // eax
  int v34; // eax
  int m_nPlaneIndex; // ecx
  int v36; // ebx
  CBSPFace **m_nTextureInfoIndex; // ecx
  int v38; // eax
  CBSPFace **v39; // eax
  int v40; // edi
  int v41; // eax
  CBSPFace **v42; // ecx
  int v43; // eax
  CBSPFace **v44; // eax
  Vector *v45; // eax
  Vector *v46; // eax
  int v47; // ecx
  Polygon_t frontPolygon; // [esp+1Ch] [ebp-4Ch] BYREF
  Polygon_t backPolygon; // [esp+34h] [ebp-34h] BYREF
  Vector vSplitPlaneNormal; // [esp+4Ch] [ebp-1Ch] BYREF
  float flLightmapMin; // [esp+58h] [ebp-10h]
  int v52; // [esp+5Ch] [ebp-Ch]
  float *v53; // [esp+60h] [ebp-8h]
  CBSPFace *pNewFace2; // [esp+64h] [ebp-4h]
  float pNewFace1a; // [esp+74h] [ebp+Ch]
  float pNewFace1b; // [esp+74h] [ebp+Ch]
  CBSPFace *pNewFace1; // [esp+74h] [ebp+Ch]
  char pNewFace1_3; // [esp+77h] [ebp+Fh]

  v4 = *(CBSPFace **)(pFaceList->m_nTextureInfoIndex + 4 * nOriginalFaceIndex);
  v5 = &pMapFile->m_TextureInfos.m_Memory.m_pMemory[v4->m_nTextureInfoIndex];
  pNewFace2 = v4;
  if ( (v5->m_SurfaceFlags & 0x400) == 0 )
  {
    v6 = &v5->m_flLightmapVectors[0][1];
    pNewFace1_3 = 0;
    v53 = v6;
    v52 = 2;
    while ( 1 )
    {
      v7 = *(v6 - 1);
      v8 = *v6;
      v9 = v6[1];
      v10 = (__m128)0x7F7FFFFFu;
      v11 = -3.4028235e38;
      vSplitPlaneNormal.x = v7;
      vSplitPlaneNormal.y = v8;
      vSplitPlaneNormal.z = v9;
      m_Size = v4->m_Polygon.m_Points.m_Size;
      v13 = 0;
      if ( m_Size >= 4 )
      {
        m_pMemory = v4->m_Polygon.m_Points.m_Memory.m_pMemory;
        p_z = &m_pMemory->z;
        v16 = &m_pMemory[1].z;
        v17 = ((unsigned int)(m_Size - 4) >> 2) + 1;
        v13 = 4 * v17;
        do
        {
          v18 = (__m128)*((unsigned int *)p_z - 2);
          v18.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v7) + (float)(*(p_z - 1) * v8)) + (float)(*p_z * v9);
          if ( v10.m128_f32[0] > v18.m128_f32[0] )
            v10 = v18;
          if ( v18.m128_f32[0] > v11 )
            v11 = v18.m128_f32[0];
          v19 = (__m128)*((unsigned int *)v16 - 1);
          v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v8) + (float)(p_z[1] * v7)) + (float)(v9 * *v16);
          if ( v10.m128_f32[0] > v19.m128_f32[0] )
            v10 = v19;
          if ( v19.m128_f32[0] > v11 )
            v11 = v19.m128_f32[0];
          v20 = (__m128)*((unsigned int *)v16 + 2);
          v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v8) + (float)(p_z[4] * v7)) + (float)(v16[3] * v9);
          if ( v10.m128_f32[0] > v20.m128_f32[0] )
            v10 = v20;
          if ( v20.m128_f32[0] > v11 )
            v11 = v20.m128_f32[0];
          v21 = (__m128)*((unsigned int *)v16 + 5);
          v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v8) + (float)(p_z[7] * v7)) + (float)(v16[6] * v9);
          if ( v10.m128_f32[0] > v21.m128_f32[0] )
            v10 = v21;
          if ( v21.m128_f32[0] > v11 )
            v11 = v21.m128_f32[0];
          p_z += 12;
          v16 += 12;
          --v17;
        }
        while ( v17 != 0 );
        v4 = pNewFace2;
      }
      if ( v13 < m_Size )
      {
        v22 = (int)&v4->m_Polygon.m_Points.m_Memory.m_pMemory[v13];
        v23 = m_Size - v13;
        do
        {
          v24 = (__m128)*(unsigned int *)(v22 + 4);
          v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v8) + (float)(*(float *)v22 * v7))
                          + (float)(*(float *)(v22 + 8) * v9);
          if ( v10.m128_f32[0] > v24.m128_f32[0] )
            v10 = v24;
          if ( v24.m128_f32[0] > v11 )
            v11 = v24.m128_f32[0];
          v22 += 12;
          --v23;
        }
        while ( v23 != 0 );
      }
      v25.m128_i32[0] = 1258291200;
      v26 = _mm_and_ps((__m128)0x80000000, v10);
      v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v26), v25).m128_f32[0]) & 0x4B000000
                      | v26.m128_i32[0];
      v27 = v10;
      v27.m128_f32[0] = (float)(v10.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
      v28 = v27;
      v28.m128_f32[0] = v27.m128_f32[0] - v10.m128_f32[0];
      flLightmapMin = v27.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v28, v26).m128_u32[0] & 0x3F800000);
      v29 = ceil(X: v11);
      if ( (int)(v29 - flLightmapMin) > 32 )
      {
        pNewFace1a = flLightmapMin + 32.0 - 1.0;
        v30 = VectorNormalize(vec: &vSplitPlaneNormal);
        v31 = pNewFace2;
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        memset(
          &frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        memset(
          &backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        pNewFace1b = pNewFace1a / v30;
        ChopPolygon(
          polygon: &pNewFace2->m_Polygon,
          vNormal: &vSplitPlaneNormal,
          flDistance: pNewFace1b,
          pOn: nullptr,
          pFront: &frontPolygon,
          pBack: &backPolygon);
        if ( (frontPolygon.m_Points.m_Size == 0 || backPolygon.m_Points.m_Size == 0)
          && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        {
          _LoggingSystem_Log(
            a1: LOG_VBSP2,
            a2: 3,
            a3: "SubdivideFaceForLightmaps: face too big for lightmapping but split operation failed.");
        }
        v32 = (CBSPFace *)operator new(nSize: 0x28u);
        if ( v32 != nullptr )
          pNewFace1 = CBSPFace::CBSPFace(this: v32, other: v31, pPolygon: &frontPolygon);
        else
          pNewFace1 = nullptr;
        v33 = (CBSPFace *)operator new(nSize: 0x28u);
        if ( v33 != nullptr )
          pNewFace2 = CBSPFace::CBSPFace(this: v33, other: v31, pPolygon: &backPolygon);
        else
          pNewFace2 = nullptr;
        v34 = (int)pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
        m_nPlaneIndex = pFaceList->m_nPlaneIndex;
        v36 = v34;
        if ( v34 + 1 > m_nPlaneIndex )
          CUtlMemory<ColorRGBExp32,int>::Grow(
            this: (CUtlMemory<BSPCluster_t,int> *)pFaceList,
            num: v34 - m_nPlaneIndex + 1);
        ++pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
        m_nTextureInfoIndex = (CBSPFace **)pFaceList->m_nTextureInfoIndex;
        v38 = (int)pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory - v36 - 1;
        pFaceList->m_Polygon.m_Points.m_Memory.m_nAllocationCount = pFaceList->m_nTextureInfoIndex;
        if ( v38 > 0 )
          _V_memmove(dest: &m_nTextureInfoIndex[v36 + 1], src: &m_nTextureInfoIndex[v36], count: 4 * v38);
        v39 = (CBSPFace **)(pFaceList->m_nTextureInfoIndex + 4 * v36);
        if ( v39 != nullptr )
          *v39 = pNewFace1;
        v40 = (int)pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
        v41 = pFaceList->m_nPlaneIndex;
        if ( v40 + 1 > v41 )
          CUtlMemory<ColorRGBExp32,int>::Grow(this: (CUtlMemory<BSPCluster_t,int> *)pFaceList, num: v40 - v41 + 1);
        ++pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
        v42 = (CBSPFace **)pFaceList->m_nTextureInfoIndex;
        v43 = (int)pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory - v40 - 1;
        pFaceList->m_Polygon.m_Points.m_Memory.m_nAllocationCount = pFaceList->m_nTextureInfoIndex;
        if ( v43 > 0 )
          _V_memmove(dest: &v42[v40 + 1], src: &v42[v40], count: 4 * v43);
        v44 = (CBSPFace **)(pFaceList->m_nTextureInfoIndex + 4 * v40);
        if ( v44 != nullptr )
          *v44 = pNewFace2;
        SubdivideFaceForLightmaps(
          pMapFile,
          (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)pFaceList,
          nOriginalFaceIndex: v36);
        SubdivideFaceForLightmaps(
          pMapFile,
          (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)pFaceList,
          nOriginalFaceIndex: v40);
        v45 = backPolygon.m_Points.m_Memory.m_pMemory;
        pNewFace2 = *(CBSPFace **)(pFaceList->m_nTextureInfoIndex + 4 * nOriginalFaceIndex);
        pNewFace1_3 = 1;
        backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        backPolygon.m_Points.m_Size = 0;
        if ( backPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( backPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: backPolygon.m_Points.m_Memory.m_pMemory);
            v45 = nullptr;
            backPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          backPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        backPolygon.m_Points.m_pElements = v45;
        if ( backPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v45 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v45);
            backPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          backPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        v46 = frontPolygon.m_Points.m_Memory.m_pMemory;
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        frontPolygon.m_Points.m_Size = 0;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( frontPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: frontPolygon.m_Points.m_Memory.m_pMemory);
            v46 = nullptr;
            frontPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          frontPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        frontPolygon.m_Points.m_pElements = v46;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v46 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46);
            frontPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          frontPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
      }
      v53 += 4;
      if ( --v52 == 0 )
        break;
      v6 = v53;
      v4 = pNewFace2;
    }
    if ( pNewFace1_3 != 0 )
    {
      v47 = (int)pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
      if ( v47 > 0 )
      {
        if ( nOriginalFaceIndex != v47 - 1 )
          *(_DWORD *)(pFaceList->m_nTextureInfoIndex + 4 * nOriginalFaceIndex) = *(_DWORD *)(pFaceList->m_nTextureInfoIndex
                                                                                           + 4 * v47
                                                                                           - 4);
        --pFaceList->m_Polygon.m_Points.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E650
// Name: private: void CSimpleBSPFile::BuildRadialVisibilityData(class CBSPNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildRadialVisibilityData(CSimpleBSPFile *this, CBSPNode *pRootNode)
{
  int v3; // eax
  int m_Size; // esi
  int v5; // eax
  int v6; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  const CBSPNode *m_pLeafNode; // eax
  float v13; // xmm2_4
  float x; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // esi
  float v19; // xmm6_4
  float v20; // xmm0_4
  const CBSPNode *v21; // eax
  float y; // xmm4_4
  float z; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  unsigned __int8 *v30; // eax
  Vector vTestMin; // [esp+Ch] [ebp-48h] BYREF
  Vector vTestMax; // [esp+18h] [ebp-3Ch] BYREF
  Vector vTestPoint; // [esp+24h] [ebp-30h] BYREF
  Vector vHalfExtent1; // [esp+30h] [ebp-24h]
  Vector vCenter1; // [esp+3Ch] [ebp-18h]
  int nRowLength; // [esp+48h] [ebp-Ch]
  float flDistanceSquared; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]
  CBSPNode *pRootNodea; // [esp+5Ch] [ebp+8h]

  if ( pRootNode->m_nSplitPlaneIndex == -1 )
  {
    if ( (pRootNode->m_ContentsFlags & 1) == 0 )
    {
      v3 = CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(this: &this->m_Clusters);
      pRootNode->m_nClusterIndex = v3;
      this->m_Clusters.m_Memory.m_pMemory[v3].m_pLeafNode = pRootNode;
    }
  }
  else
  {
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: pRootNode->m_pChildren[0]);
    CSimpleBSPFile::AssignClusterIndicesToLeaves(this, pNode: pRootNode->m_pChildren[1]);
  }
  m_Size = this->m_Clusters.m_Size;
  v5 = (m_Size + 7) / 8;
  v6 = v5 * m_Size;
  nRowLength = v5;
  this->m_VisibilityData.m_Size = 0;
  if ( v6 != 0 )
  {
    m_nAllocationCount = this->m_VisibilityData.m_Memory.m_nAllocationCount;
    if ( v6 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_VisibilityData.m_Memory, num: v6 - m_nAllocationCount);
    this->m_VisibilityData.m_Size += v6;
    m_pMemory = this->m_VisibilityData.m_Memory.m_pMemory;
    v9 = this->m_VisibilityData.m_Size - v6;
    this->m_VisibilityData.m_pElements = m_pMemory;
    if ( v9 > 0 && v6 > 0 )
      _V_memmove(dest: &m_pMemory[v6], src: m_pMemory, count: v9);
  }
  memset(dst: this->m_VisibilityData.m_Memory.m_pMemory, value: 0, count: this->m_VisibilityData.m_Size);
  v10 = this->m_Clusters.m_Size;
  v11 = 0;
  i = 0;
  if ( v10 > 0 )
  {
    pRootNodea = nullptr;
    do
    {
      m_pLeafNode = this->m_Clusters.m_Memory.m_pMemory[v11].m_pLeafNode;
      v13 = m_pLeafNode->m_vMinBounds.z + m_pLeafNode->m_vMaxBounds.z;
      x = m_pLeafNode->m_vMaxBounds.x;
      v15 = (float)(x + m_pLeafNode->m_vMinBounds.x) * 0.5;
      v16 = (float)(m_pLeafNode->m_vMinBounds.y + m_pLeafNode->m_vMaxBounds.y) * 0.5;
      vHalfExtent1.y = m_pLeafNode->m_vMaxBounds.y - v16;
      v17 = v13 * 0.5;
      v18 = 0;
      v19 = x - v15;
      v20 = m_pLeafNode->m_vMaxBounds.z - v17;
      vCenter1.x = v15;
      vCenter1.y = v16;
      vCenter1.z = v17;
      vHalfExtent1.x = v19;
      vHalfExtent1.z = v20;
      if ( v10 > 0 )
      {
        while ( 1 )
        {
          v21 = this->m_Clusters.m_Memory.m_pMemory[v18].m_pLeafNode;
          y = v21->m_vMaxBounds.y;
          z = v21->m_vMaxBounds.z;
          v24 = (float)(v21->m_vMinBounds.x + v21->m_vMaxBounds.x) * 0.5;
          v25 = (float)(v21->m_vMinBounds.y + y) * 0.5;
          v26 = (float)(v21->m_vMinBounds.z + z) * 0.5;
          v27 = v21->m_vMaxBounds.x;
          vTestPoint.y = vCenter1.y - v25;
          vTestPoint.z = vCenter1.z - v26;
          v28 = (float)(v27 - v24) + v19;
          vTestMin.x = vec3_origin.x - v28;
          v29 = (float)(y - v25) + vHalfExtent1.y;
          vTestMin.y = vec3_origin.y - v29;
          vTestPoint.x = v15 - v24;
          vTestMax.x = v28;
          vTestMax.y = v29;
          vTestMax.z = (float)(z - v26) + vHalfExtent1.z;
          vTestMin.z = vec3_origin.z - vTestMax.z;
          flDistanceSquared = CalcSqrDistanceToAABB(mins: &vTestMin, maxs: &vTestMax, point: &vTestPoint);
          if ( (float)(this->m_flVisibilityRadius * this->m_flVisibilityRadius) > flDistanceSquared )
          {
            v30 = &this->m_VisibilityData.m_Memory.m_pMemory[(unsigned int)pRootNodea + v18 / 8];
            *v30 |= 1 << (v18 % 8);
          }
          if ( ++v18 >= this->m_Clusters.m_Size )
            break;
          v19 = vHalfExtent1.x;
          v15 = vCenter1.x;
        }
        v11 = i;
      }
      v10 = this->m_Clusters.m_Size;
      pRootNodea = (CBSPNode *)((char *)pRootNodea + nRowLength);
      i = ++v11;
    }
    while ( v11 < v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EA70
// Name: public: CBSPPortal::~CBSPPortal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPortal::~CBSPPortal(CBSPPortal *this)
{
  int v2; // eax
  CBSPFace *v3; // esi
  Vector *m_pMemory; // eax
  CBSPFace **v5; // eax
  Vector *v6; // eax
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_PortalFaces.m_Size; i = v2 )
  {
    v3 = this->m_PortalFaces.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      v3->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v3->m_Polygon.m_Points.m_Size = 0;
      if ( v3->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Polygon.m_Points.m_Memory.m_pMemory);
          v3->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_Polygon.m_Points.m_Memory.m_pMemory;
      v3->m_Polygon.m_Points.m_pElements = m_pMemory;
      if ( v3->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_PortalFaces.m_Size = 0;
  if ( this->m_PortalFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PortalFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PortalFaces.m_Memory.m_pMemory);
      this->m_PortalFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_PortalFaces.m_Memory.m_pMemory;
  this->m_PortalFaces.m_pElements = v5;
  if ( this->m_PortalFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_PortalFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  this->m_Polygon.m_Points.m_Size = 0;
  if ( this->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Polygon.m_Points.m_Memory.m_pMemory);
      this->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    }
    this->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Polygon.m_Points.m_Memory.m_pMemory;
  this->m_Polygon.m_Points.m_pElements = v6;
  if ( this->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    }
    this->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040EBA0
// Name: private: void CSimpleBSPFile::BuildNodePortals(class CBSPNode __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildNodePortals(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *pPortalList)
{
  int v3; // ebx
  CBSPPortal **m_pMemory; // ecx
  CBSPPortal *v5; // eax
  int v6; // edi
  int v7; // esi
  CBSPPortal *v8; // eax
  CBSPPortal *v9; // ebx
  HashedPlane_t *v10; // eax
  CBSPNode *m_pParent; // esi
  CBSPNode *i; // ecx
  HashedPlane_t *v13; // eax
  int j; // esi
  CBSPPortal *v15; // eax
  float m_flDistance; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  int m_nAllocationCount; // eax
  CBSPPortal **v20; // ecx
  int v21; // eax
  CBSPPortal **v22; // eax
  bool v23; // cc
  CBSPPortal *v24; // esi
  CBSPNode *v25; // edi
  BOOL v26; // ecx
  int v27; // eax
  CBSPNode *v28; // edx
  int m_Size; // ecx
  CBSPPortal **v30; // edx
  int v31; // ecx
  CBSPNode *v32; // edi
  int v33; // ecx
  int v34; // eax
  CBSPPortal **v35; // edx
  int v36; // ecx
  int m_nGrowSize; // eax
  Vector *v38; // eax
  int v39; // eax
  int v40; // eax
  Vector *m_pElements; // eax
  CBSPPortal *v42; // eax
  CBSPPortal *v43; // ebx
  CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *v44; // edx
  int v45; // edi
  int v46; // eax
  CBSPPortal **v47; // ecx
  int v48; // eax
  CBSPPortal **v49; // eax
  CBSPNode *v50; // edi
  CBSPNode *v51; // esi
  Vector *v52; // eax
  Vector *v53; // eax
  float v54; // [esp+0h] [ebp-74h]
  CBSPPortal *flDistance; // [esp+8h] [ebp-6Ch]
  Polygon_t backPolygon; // [esp+1Ch] [ebp-58h] BYREF
  Polygon_t frontPolygon; // [esp+34h] [ebp-40h] BYREF
  Vector vNormal; // [esp+4Ch] [ebp-28h] BYREF
  Vector m_vNormal; // [esp+58h] [ebp-1Ch] BYREF
  Plane_t *pPlane; // [esp+64h] [ebp-10h]
  int side; // [esp+68h] [ebp-Ch]
  CSimpleBSPFile *v62; // [esp+6Ch] [ebp-8h]
  CBSPNode *pOtherNode; // [esp+70h] [ebp-4h]

  v62 = this;
  while ( 1 )
  {
    v3 = 0;
    if ( pNode->m_Portals.m_Size > 0 )
    {
      m_pMemory = pNode->m_Portals.m_Memory.m_pMemory;
      do
      {
        v5 = m_pMemory[v3];
        v6 = 0;
        if ( v5->m_Polygon.m_Points.m_Size > 0 )
        {
          v7 = 0;
          do
          {
            AddPointToBounds(
              v: &v5->m_Polygon.m_Points.m_Memory.m_pMemory[v7],
              mins: &pNode->m_vMinBounds,
              maxs: &pNode->m_vMaxBounds);
            m_pMemory = pNode->m_Portals.m_Memory.m_pMemory;
            v5 = m_pMemory[v3];
            ++v6;
            ++v7;
          }
          while ( v6 < v5->m_Polygon.m_Points.m_Size );
        }
        ++v3;
      }
      while ( v3 < pNode->m_Portals.m_Size );
    }
    if ( pNode->m_nSplitPlaneIndex == -1 )
      break;
    v8 = (CBSPPortal *)operator new(nSize: 0x4Cu);
    v9 = nullptr;
    if ( v8 != nullptr )
    {
      v8->m_pOnNode = nullptr;
      v8->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
      v8->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      v8->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
      v8->m_Polygon.m_Points.m_Size = 0;
      v8->m_Polygon.m_Points.m_pElements = nullptr;
      v8->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v8->m_PortalFaces.m_Memory.m_pMemory = nullptr;
      v8->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
      v8->m_PortalFaces.m_Memory.m_nGrowSize = 0;
      v8->m_PortalFaces.m_Size = 0;
      v8->m_PortalFaces.m_pElements = nullptr;
      v8->m_pNodes[1] = nullptr;
      v8->m_pNodes[0] = nullptr;
      v9 = v8;
    }
    v10 = &v62->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pNode->m_nSplitPlaneIndex];
    v9->m_Plane.m_vNormal.x = v10->m_vNormal.x;
    v9->m_Plane.m_vNormal.y = v10->m_vNormal.y;
    v9->m_Plane.m_vNormal.z = v10->m_vNormal.z;
    v9->m_Plane.m_flDistance = v10->m_flDistance;
    v9->m_Plane.m_Type = v10->m_Type;
    v9->m_pOnNode = pNode;
    CreatePolygonFromPlane(vNormal: &v10->m_vNormal, flDistance: v10->m_flDistance, pPolygon: &v9->m_Polygon);
    m_pParent = pNode->m_pParent;
    for ( i = pNode; m_pParent != nullptr; m_pParent = m_pParent->m_pParent )
    {
      v13 = &v62->m_PlaneHash.m_Planes.m_Memory.m_pMemory[m_pParent->m_nSplitPlaneIndex];
      if ( m_pParent->m_pChildren[0] == i )
      {
        ChopPolygonInPlace(pPolygon: &v9->m_Polygon, vNormal: &v13->m_vNormal, flDistance: v13->m_flDistance);
      }
      else
      {
        vNormal.x = -v13->m_vNormal.x;
        vNormal.y = -v13->m_vNormal.y;
        vNormal.z = -v13->m_vNormal.z;
        ChopPolygonInPlace(pPolygon: &v9->m_Polygon, &vNormal, flDistance: -v13->m_flDistance);
      }
      i = m_pParent;
    }
    for ( j = 0; j < pNode->m_Portals.m_Size; ++j )
    {
      v15 = pNode->m_Portals.m_Memory.m_pMemory[j];
      if ( v15->m_pNodes[0] == pNode )
      {
        m_vNormal = v15->m_Plane.m_vNormal;
        m_flDistance = v15->m_Plane.m_flDistance;
      }
      else
      {
        v17 = -v15->m_Plane.m_vNormal.y;
        v18 = -v15->m_Plane.m_vNormal.z;
        m_vNormal.x = -v15->m_Plane.m_vNormal.x;
        m_vNormal.y = v17;
        m_vNormal.z = v18;
        m_flDistance = -v15->m_Plane.m_flDistance;
      }
      ChopPolygonInPlace(pPolygon: &v9->m_Polygon, vNormal: &m_vNormal, flDistance: m_flDistance);
    }
    if ( v9->m_Polygon.m_Points.m_Size == 0 || IsPolygonTiny(pPolygon: &v9->m_Polygon) )
    {
      CBSPPortal::~CBSPPortal(this: v9);
      free(pMem: v9);
    }
    else
    {
      AttachPortalToNodes(pNode0: pNode->m_pChildren[0], pPortal: v9, pNode1: pNode->m_pChildren[1]);
      m_nAllocationCount = pPortalList->m_Memory.m_nAllocationCount;
      pOtherNode = (CBSPNode *)pPortalList->m_Size;
      if ( (int)&pOtherNode->m_pParent + 1 > m_nAllocationCount )
        CUtlMemory<ColorRGBExp32,int>::Grow(
          this: (CUtlMemory<BSPCluster_t,int> *)pPortalList,
          num: (int)&pOtherNode->m_pParent - m_nAllocationCount + 1);
      ++pPortalList->m_Size;
      v20 = pPortalList->m_Memory.m_pMemory;
      v21 = pPortalList->m_Size - (_DWORD)pOtherNode - 1;
      pPortalList->m_pElements = pPortalList->m_Memory.m_pMemory;
      if ( v21 > 0 )
        _V_memmove(dest: &v20[(_DWORD)pOtherNode + 1], src: &v20[(_DWORD)pOtherNode], count: 4 * v21);
      v22 = &pPortalList->m_Memory.m_pMemory[(_DWORD)pOtherNode];
      if ( v22 != nullptr )
        *v22 = v9;
    }
    v23 = pNode->m_Portals.m_Size <= 0;
    pPlane = &v62->m_PlaneHash.m_Planes.m_Memory.m_pMemory[pNode->m_nSplitPlaneIndex];
    if ( !v23 )
    {
      do
      {
        v24 = *pNode->m_Portals.m_Memory.m_pMemory;
        v25 = v24->m_pNodes[0];
        v26 = v24->m_pNodes[0] == pNode;
        side = v24->m_pNodes[0] != pNode;
        v27 = 0;
        v28 = v24->m_pNodes[v26];
        m_Size = v25->m_Portals.m_Size;
        pOtherNode = v28;
        if ( m_Size > 0 )
        {
          v30 = v25->m_Portals.m_Memory.m_pMemory;
          while ( *v30 != v24 )
          {
            ++v27;
            ++v30;
            if ( v27 >= m_Size )
              goto LABEL_40;
          }
          if ( v27 != -1 )
          {
            v31 = m_Size - v27 - 1;
            if ( v31 > 0 )
              _V_memmove(
                dest: &v25->m_Portals.m_Memory.m_pMemory[v27],
                src: &v25->m_Portals.m_Memory.m_pMemory[v27 + 1],
                count: 4 * v31);
            --v25->m_Portals.m_Size;
          }
        }
LABEL_40:
        v32 = v24->m_pNodes[1];
        v33 = v32->m_Portals.m_Size;
        v34 = 0;
        if ( v33 > 0 )
        {
          v35 = v32->m_Portals.m_Memory.m_pMemory;
          while ( *v35 != v24 )
          {
            ++v34;
            ++v35;
            if ( v34 >= v33 )
              goto LABEL_49;
          }
          if ( v34 != -1 )
          {
            v36 = v33 - v34 - 1;
            if ( v36 > 0 )
              _V_memmove(
                dest: &v32->m_Portals.m_Memory.m_pMemory[v34],
                src: &v32->m_Portals.m_Memory.m_pMemory[v34 + 1],
                count: 4 * v36);
            --v32->m_Portals.m_Size;
          }
        }
LABEL_49:
        v24->m_pNodes[1] = nullptr;
        v24->m_pNodes[0] = nullptr;
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        v54 = pPlane->m_flDistance;
        memset(
          &frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(frontPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        memset(
          &backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          0,
          sizeof(backPolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
        ChopPolygon(
          polygon: &v24->m_Polygon,
          vNormal: &pPlane->m_vNormal,
          flDistance: v54,
          pOn: nullptr,
          pFront: &frontPolygon,
          pBack: &backPolygon);
        if ( IsPolygonTiny(pPolygon: &frontPolygon) )
          frontPolygon.m_Points.m_Size = 0;
        if ( IsPolygonTiny(pPolygon: &backPolygon) )
          backPolygon.m_Points.m_Size = 0;
        if ( frontPolygon.m_Points.m_Size != 0 )
        {
          if ( backPolygon.m_Points.m_Size != 0 )
          {
            m_nGrowSize = v24->m_Polygon.m_Points.m_Memory.m_nGrowSize;
            v24->m_Polygon.m_Points.m_Memory.m_nGrowSize = frontPolygon.m_Points.m_Memory.m_nGrowSize;
            frontPolygon.m_Points.m_Memory.m_nGrowSize = m_nGrowSize;
            v38 = v24->m_Polygon.m_Points.m_Memory.m_pMemory;
            v24->m_Polygon.m_Points.m_Memory.m_pMemory = frontPolygon.m_Points.m_Memory.m_pMemory;
            frontPolygon.m_Points.m_Memory.m_pMemory = v38;
            v39 = v24->m_Polygon.m_Points.m_Memory.m_nAllocationCount;
            v24->m_Polygon.m_Points.m_Memory.m_nAllocationCount = frontPolygon.m_Points.m_Memory.m_nAllocationCount;
            frontPolygon.m_Points.m_Memory.m_nAllocationCount = v39;
            v40 = v24->m_Polygon.m_Points.m_Size;
            v24->m_Polygon.m_Points.m_Size = frontPolygon.m_Points.m_Size;
            frontPolygon.m_Points.m_Size = v40;
            m_pElements = v24->m_Polygon.m_Points.m_pElements;
            v24->m_Polygon.m_Points.m_pElements = frontPolygon.m_Points.m_pElements;
            frontPolygon.m_Points.m_pElements = m_pElements;
            v42 = (CBSPPortal *)operator new(nSize: 0x4Cu);
            if ( v42 != nullptr )
              v43 = CBSPPortal::CBSPPortal(this: v42, other: v24, pPortalShape: &backPolygon);
            else
              v43 = nullptr;
            v44 = pPortalList;
            v45 = pPortalList->m_Size;
            v46 = pPortalList->m_Memory.m_nAllocationCount;
            if ( v45 + 1 > v46 )
            {
              CUtlMemory<ColorRGBExp32,int>::Grow(this: (CUtlMemory<BSPCluster_t,int> *)pPortalList, num: v45 - v46 + 1);
              v44 = pPortalList;
            }
            ++v44->m_Size;
            v47 = v44->m_Memory.m_pMemory;
            v48 = v44->m_Size - v45 - 1;
            v44->m_pElements = v44->m_Memory.m_pMemory;
            if ( v48 > 0 )
            {
              _V_memmove(dest: &v47[v45 + 1], src: &v47[v45], count: 4 * v48);
              v44 = pPortalList;
            }
            v49 = &v44->m_Memory.m_pMemory[v45];
            if ( v49 != nullptr )
              *v49 = v43;
            if ( side != 0 )
            {
              flDistance = v24;
              v51 = pOtherNode;
              AttachPortalToNodes(pNode0: pOtherNode, pPortal: flDistance, pNode1: pNode->m_pChildren[0]);
              AttachPortalToNodes(pNode0: v51, pPortal: v43, pNode1: pNode->m_pChildren[1]);
            }
            else
            {
              v50 = pOtherNode;
              AttachPortalToNodes(pNode0: pNode->m_pChildren[0], pPortal: v24, pNode1: pOtherNode);
              AttachPortalToNodes(pNode0: pNode->m_pChildren[1], pPortal: v43, pNode1: v50);
            }
          }
          else if ( side != 0 )
          {
            AttachPortalToNodes(pNode0: pOtherNode, pPortal: v24, pNode1: pNode->m_pChildren[0]);
          }
          else
          {
            AttachPortalToNodes(pNode0: pNode->m_pChildren[0], pPortal: v24, pNode1: pOtherNode);
          }
        }
        else if ( side != 0 )
        {
          AttachPortalToNodes(pNode0: pOtherNode, pPortal: v24, pNode1: pNode->m_pChildren[1]);
        }
        else
        {
          AttachPortalToNodes(pNode0: pNode->m_pChildren[1], pPortal: v24, pNode1: pOtherNode);
        }
        v52 = backPolygon.m_Points.m_Memory.m_pMemory;
        backPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        backPolygon.m_Points.m_Size = 0;
        if ( backPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( backPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: backPolygon.m_Points.m_Memory.m_pMemory);
            v52 = nullptr;
            backPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          backPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        backPolygon.m_Points.m_pElements = v52;
        if ( backPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v52 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v52);
            backPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          backPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        v53 = frontPolygon.m_Points.m_Memory.m_pMemory;
        frontPolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        frontPolygon.m_Points.m_Size = 0;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
        {
          if ( frontPolygon.m_Points.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: frontPolygon.m_Points.m_Memory.m_pMemory);
            v53 = nullptr;
            frontPolygon.m_Points.m_Memory.m_pMemory = nullptr;
          }
          frontPolygon.m_Points.m_Memory.m_nAllocationCount = 0;
        }
        frontPolygon.m_Points.m_pElements = v53;
        if ( frontPolygon.m_Points.m_Memory.m_nGrowSize >= 0 && v53 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53);
      }
      while ( pNode->m_Portals.m_Size > 0 );
    }
    CSimpleBSPFile::BuildNodePortals(this: v62, pNode: pNode->m_pChildren[0], pPortalList);
    pNode = pNode->m_pChildren[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F680
// Name: private: void CSimpleBSPFile::BuildTreePortals(class CBSPTree __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildTreePortals(
        CSimpleBSPFile *this,
        CBSPTree *pTree,
        CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *pPortalList)
{
  CBSPPortal *v3; // esi
  int j; // ebx
  int v5; // edi
  CBSPPortal *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float *p_m_flDistance; // ecx
  Plane_t *v10; // eax
  int k; // ebx
  int v12; // esi
  Plane_t *v13; // edi
  int m_Size; // edi
  int m_nAllocationCount; // ecx
  CBSPPortal **m_pMemory; // ecx
  int v17; // eax
  int v18; // ecx
  CBSPPortal **v19; // eax
  CBSPPortal **v20; // edi
  Plane_t planes[6]; // [esp+14h] [ebp-B0h] BYREF
  Vector vBounds[2]; // [esp+8Ch] [ebp-38h]
  CBSPPortal *pPortals[6]; // [esp+A4h] [ebp-20h]
  CSimpleBSPFile *v24; // [esp+BCh] [ebp-8h]
  int i; // [esp+C0h] [ebp-4h]

  v24 = this;
  vBounds[0].x = pTree->m_vMinBounds.x - 8.0;
  vBounds[1].x = pTree->m_vMaxBounds.x + 8.0;
  vBounds[0].y = pTree->m_vMinBounds.y - 8.0;
  vBounds[1].y = pTree->m_vMaxBounds.y + 8.0;
  vBounds[0].z = pTree->m_vMinBounds.z - 8.0;
  v3 = nullptr;
  vBounds[1].z = pTree->m_vMaxBounds.z + 8.0;
  memset(dst: (unsigned __int8 *)planes, value: 0, count: sizeof(planes));
  i = 0;
  for ( j = 0; ; j = 0 )
  {
    while ( 1 )
    {
      v5 = j + i + 2 * j;
      v6 = (CBSPPortal *)operator new(nSize: 0x4Cu);
      if ( v6 != nullptr )
      {
        v6->m_pOnNode = nullptr;
        v6->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        v6->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
        v6->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
        v6->m_Polygon.m_Points.m_Size = 0;
        v6->m_Polygon.m_Points.m_pElements = nullptr;
        v6->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        v6->m_PortalFaces.m_Memory.m_pMemory = nullptr;
        v6->m_PortalFaces.m_Memory.m_nAllocationCount = 0;
        v6->m_PortalFaces.m_Memory.m_nGrowSize = 0;
        v6->m_PortalFaces.m_Size = 0;
        v6->m_PortalFaces.m_pElements = nullptr;
        v6->m_pNodes[1] = nullptr;
        v6->m_pNodes[0] = nullptr;
        v3 = v6;
      }
      pPortals[v5] = v3;
      v7 = j != 0 ? -1.0 : 1.0;
      v8 = *(&vBounds[0].x + v5);
      *(&planes[0].m_vNormal.x + 4 * v5 + v5 + i) = v7;
      p_m_flDistance = &planes[v5].m_flDistance;
      v10 = &planes[v5];
      *p_m_flDistance = v8 * v7;
      v3->m_Plane.m_vNormal.x = v10->m_vNormal.x;
      v3->m_Plane.m_vNormal.y = v10->m_vNormal.y;
      v3->m_Plane.m_vNormal.z = v10->m_vNormal.z;
      v3->m_Plane.m_flDistance = v10->m_flDistance;
      v3->m_Plane.m_Type = v10->m_Type;
      CreatePolygonFromPlane(vNormal: &v10->m_vNormal, flDistance: *p_m_flDistance, pPolygon: &v3->m_Polygon);
      AttachPortalToNodes(pNode0: pTree->m_pRoot, pPortal: v3, pNode1: &pTree->m_OutsideNode);
      if ( ++j >= 2 )
        break;
      v3 = nullptr;
    }
    if ( ++i >= 3 )
      break;
    v3 = nullptr;
  }
  for ( k = 0; k < 6; ++k )
  {
    v12 = 0;
    v13 = planes;
    do
    {
      if ( k != v12 )
        ChopPolygonInPlace(pPolygon: &pPortals[k]->m_Polygon, vNormal: &v13->m_vNormal, flDistance: v13->m_flDistance);
      ++v12;
      ++v13;
    }
    while ( v12 < 6 );
  }
  m_Size = pPortalList->m_Size;
  m_nAllocationCount = pPortalList->m_Memory.m_nAllocationCount;
  if ( m_Size + 6 > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow(
      this: (CUtlMemory<BSPCluster_t,int> *)pPortalList,
      num: m_Size - m_nAllocationCount + 6);
  pPortalList->m_Size += 6;
  m_pMemory = pPortalList->m_Memory.m_pMemory;
  v17 = pPortalList->m_Size - m_Size - 6;
  pPortalList->m_pElements = pPortalList->m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 6], src: &m_pMemory[m_Size], count: 4 * v17);
  v18 = m_Size;
  v19 = &pPortalList->m_Memory.m_pMemory[m_Size];
  if ( v19 != nullptr )
    *v19 = pPortals[0];
  if ( &pPortalList->m_Memory.m_pMemory[v18] != (CBSPPortal **)-4 )
    pPortalList->m_Memory.m_pMemory[v18 + 1] = pPortals[1];
  if ( &pPortalList->m_Memory.m_pMemory[m_Size] != (CBSPPortal **)-8 )
    pPortalList->m_Memory.m_pMemory[m_Size + 2] = pPortals[2];
  if ( &pPortalList->m_Memory.m_pMemory[m_Size] != (CBSPPortal **)-12 )
    pPortalList->m_Memory.m_pMemory[m_Size + 3] = pPortals[3];
  if ( &pPortalList->m_Memory.m_pMemory[m_Size] != (CBSPPortal **)-16 )
    pPortalList->m_Memory.m_pMemory[m_Size + 4] = pPortals[4];
  v20 = &pPortalList->m_Memory.m_pMemory[m_Size + 5];
  if ( v20 != nullptr )
    *v20 = pPortals[5];
  CSimpleBSPFile::BuildNodePortals(this: v24, pNode: pTree->m_pRoot, pPortalList);
}

//------------------------------------------------------------------------------
// Address: 0x0040F910
// Name: public: CSimpleBSPFile::CSimpleBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
CSimpleBSPFile *__thiscall CSimpleBSPFile::CSimpleBSPFile(CSimpleBSPFile *this)
{
  this->m_pMapFile = nullptr;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_Models.m_Memory.m_pMemory = nullptr;
  this->m_Models.m_Memory.m_nAllocationCount = 0;
  this->m_Models.m_Memory.m_nGrowSize = 0;
  this->m_Models.m_Size = 0;
  this->m_Models.m_pElements = nullptr;
  this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementFaces.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementFaces.m_Size = 0;
  this->m_DisplacementFaces.m_pElements = nullptr;
  this->m_Clusters.m_Memory.m_pMemory = nullptr;
  this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  this->m_Clusters.m_Memory.m_nGrowSize = 0;
  this->m_Clusters.m_Size = 0;
  this->m_Clusters.m_pElements = nullptr;
  this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
  this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  this->m_VisibilityData.m_Memory.m_nGrowSize = 0;
  this->m_VisibilityData.m_Size = 0;
  this->m_VisibilityData.m_pElements = nullptr;
  this->m_nNextFaceIndex = 0;
  this->m_flVisibilityRadius = 2500.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F9C0
// Name: private: void CSimpleBSPFile::MakeFacesFromPortals(class CBSPModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::MakeFacesFromPortals(CSimpleBSPFile *this, CBSPModel *pModel)
{
  CBSPModel *v2; // ecx
  int v3; // eax
  CBSPPortal *v4; // esi
  CBSPNode *m_pOnNode; // edi
  int v6; // edx
  int v7; // eax
  CBSPNode *v8; // eax
  CBSPBrush **m_pMemory; // edx
  const MapBrush_t *m_pOriginalBrush; // eax
  int m_nNumSides; // ecx
  MapBrushSide_t *v12; // eax
  int v13; // eax
  CBSPFace *v14; // eax
  CBSPFace *v15; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPFace **v18; // ecx
  int v19; // eax
  CBSPFace **v20; // ebx
  int m_ContentsFlags; // edx
  int v22; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // ebx
  int v27; // ecx
  int v28; // edx
  unsigned int v29; // ebx
  Vector *v30; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector *v34; // eax
  Vector *v35; // esi
  float v36; // xmm0_4
  int v37; // xmm1_4
  int v38; // xmm2_4
  Vector *v39; // esi
  Vector *v40; // esi
  float v41; // xmm0_4
  int v42; // xmm1_4
  int v43; // xmm2_4
  Vector *v44; // esi
  Vector *v45; // esi
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  Vector *v49; // esi
  int v50; // ecx
  int v51; // edx
  int v52; // esi
  Vector *v53; // eax
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float *p_x; // eax
  int nPortal; // [esp+0h] [ebp-18h]
  int nPortalSide; // [esp+4h] [ebp-14h]
  int nPortalSidea; // [esp+4h] [ebp-14h]
  int i; // [esp+8h] [ebp-10h]
  int ia; // [esp+8h] [ebp-10h]
  CBSPPortal *pPortal; // [esp+10h] [ebp-8h]
  int nNumPoints; // [esp+14h] [ebp-4h]
  int nNumPointsa; // [esp+14h] [ebp-4h]

  v2 = pModel;
  v3 = 0;
  for ( nPortal = 0; v3 < pModel->m_Portals.m_Size; nPortal = v3 )
  {
    v4 = v2->m_Portals.m_Memory.m_pMemory[v3];
    m_pOnNode = v4->m_pOnNode;
    v6 = 0;
    pPortal = v4;
    if ( m_pOnNode != nullptr )
    {
      v7 = 1;
      while ( ((v4->m_pNodes[1]->m_ContentsFlags ^ v4->m_pNodes[0]->m_ContentsFlags) & v7) == 0 )
      {
        v7 *= 2;
        if ( v7 > 128 )
          goto LABEL_48;
      }
      if ( v7 != 0 )
      {
        nNumPoints = 0;
        nPortalSide = 0;
        do
        {
          v8 = v4->m_pNodes[v6];
          if ( v8->m_ClippedBrushes.m_Size > 0 )
          {
            m_pMemory = v8->m_ClippedBrushes.m_Memory.m_pMemory;
            i = v8->m_ClippedBrushes.m_Size;
            do
            {
              m_pOriginalBrush = (*m_pMemory)->m_pOriginalBrush;
              m_nNumSides = m_pOriginalBrush->m_nNumSides;
              if ( m_nNumSides > 0 )
              {
                v12 = &this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[m_pOriginalBrush->m_nFirstSideIndex];
                do
                {
                  if ( v12->m_nTextureInfoIndex != -1
                    && (v12->m_nPlaneIndex & 0xFFFFFFFE) == m_pOnNode->m_nSplitPlaneIndex )
                  {
                    nNumPoints = (int)v12;
                  }
                  ++v12;
                  --m_nNumSides;
                }
                while ( m_nNumSides != 0 );
              }
              ++m_pMemory;
              --i;
            }
            while ( i != 0 );
            v6 = nPortalSide;
          }
          nPortalSide = ++v6;
        }
        while ( v6 < 2 );
        if ( nNumPoints != 0 )
        {
          v13 = *(_DWORD *)(nNumPoints + 12);
          if ( v13 != -1 && SLOBYTE(this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[v13].m_SurfaceFlags) >= 0 )
          {
            v14 = (CBSPFace *)operator new(nSize: 0x28u);
            v15 = nullptr;
            if ( v14 != nullptr )
            {
              v14->m_nTextureInfoIndex = -1;
              v14->m_nPlaneIndex = -1;
              v14->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
              v14->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
              v14->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
              v14->m_Polygon.m_Points.m_Size = 0;
              v14->m_Polygon.m_Points.m_pElements = nullptr;
              v14->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
              v14->m_nDisplacementIndex = -1;
              v14->m_nSerializedFaceIndex = -1;
              v15 = v14;
            }
            v15->m_nTextureInfoIndex = *(_DWORD *)(nNumPoints + 12);
            v15->m_nPlaneIndex = v4->m_pOnNode->m_nSplitPlaneIndex;
            m_Size = v4->m_PortalFaces.m_Size;
            m_nAllocationCount = v4->m_PortalFaces.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<ColorRGBExp32,int>::Grow(
                this: (CUtlMemory<BSPCluster_t,int> *)&v4->m_PortalFaces,
                num: m_Size - m_nAllocationCount + 1);
            ++v4->m_PortalFaces.m_Size;
            v18 = v4->m_PortalFaces.m_Memory.m_pMemory;
            v19 = v4->m_PortalFaces.m_Size - m_Size - 1;
            v4->m_PortalFaces.m_pElements = v18;
            if ( v19 > 0 )
              _V_memmove(dest: &v18[m_Size + 1], src: &v18[m_Size], count: 4 * v19);
            v20 = &v4->m_PortalFaces.m_Memory.m_pMemory[m_Size];
            if ( v20 != nullptr )
              *v20 = v15;
            m_ContentsFlags = v4->m_pNodes[0]->m_ContentsFlags;
            v22 = 1;
            while ( ((m_ContentsFlags ^ v4->m_pNodes[1]->m_ContentsFlags) & v22) == 0 )
            {
              v22 *= 2;
              if ( v22 > 128 )
              {
                v22 = 0;
                break;
              }
            }
            if ( (m_ContentsFlags & v22) != 0 )
            {
              if ( v4 == (CBSPPortal *)-12 )
                v23 = nullptr;
              else
                v23 = &v4->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: v23);
              v24 = v15->m_Polygon.m_Points.m_Size;
              v15->m_nPlaneIndex |= 1u;
              v25 = v24 / 2;
              v26 = 0;
              nNumPointsa = v24;
              nPortalSidea = v24 / 2;
              if ( v24 / 2 >= 4 )
              {
                v27 = 0;
                v28 = 4 * (3 * v24 - 9);
                v29 = ((unsigned int)(v25 - 4) >> 2) + 1;
                ia = 4 * v29;
                do
                {
                  v30 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  x = v30[v27].x;
                  y = v30[v27].y;
                  z = v30[v27].z;
                  v30[v27].x = *(float *)((char *)&v30[2].x + v28);
                  v27 += 4;
                  *((float *)&v30[v27 - 3] - 2) = *(float *)((char *)&v30[2].y + v28);
                  *((float *)&v30[v27 - 3] - 1) = *(float *)((char *)&v30[2].z + v28);
                  v34 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v34[2].x + v28) = x;
                  *(float *)((char *)&v34[2].y + v28) = y;
                  *(float *)((char *)&v34[2].z + v28) = z;
                  v35 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v36 = v35[v27 - 3].x;
                  v37 = *((_DWORD *)&v35[v27 - 2] - 2);
                  v38 = *((_DWORD *)&v35[v27 - 2] - 1);
                  v35[v27 - 3].x = *(float *)((char *)&v35[1].x + v28);
                  *((float *)&v35[v27 - 2] - 2) = *(float *)((char *)&v35[1].y + v28);
                  v28 -= 48;
                  --v29;
                  *((float *)&v35[v27 - 2] - 1) = *(float *)((char *)&v35[5].z + v28);
                  v39 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v39[5].x + v28) = v36;
                  *(_DWORD *)((char *)&v39[5].y + v28) = v37;
                  *(_DWORD *)((char *)&v39[5].z + v28) = v38;
                  v40 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v41 = v40[v27 - 2].x;
                  v42 = *((_DWORD *)&v40[v27 - 1] - 2);
                  v43 = *((_DWORD *)&v40[v27 - 1] - 1);
                  v40[v27 - 2].x = *(float *)((char *)&v40[4].x + v28);
                  *((float *)&v40[v27 - 1] - 2) = *(float *)((char *)&v40[4].y + v28);
                  *((float *)&v40[v27 - 1] - 1) = *(float *)((char *)&v40[4].z + v28);
                  v44 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v44[4].x + v28) = v41;
                  *(_DWORD *)((char *)&v44[4].y + v28) = v42;
                  *(_DWORD *)((char *)&v44[4].z + v28) = v43;
                  v45 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v46 = v45[v27 - 1].x;
                  v47 = v45[v27 - 1].y;
                  v48 = v45[v27 - 1].z;
                  v45[v27 - 1].x = *(float *)((char *)&v45[3].x + v28);
                  v45[v27 - 1].y = *(float *)((char *)&v45[3].y + v28);
                  v45[v27 - 1].z = *(float *)((char *)&v45[3].z + v28);
                  v49 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  *(float *)((char *)&v49[3].x + v28) = v46;
                  *(float *)((char *)&v49[3].y + v28) = v47;
                  *(float *)((char *)&v49[3].z + v28) = v48;
                }
                while ( v29 != 0 );
                v25 = nPortalSidea;
                v26 = ia;
                v24 = nNumPointsa;
              }
              if ( v26 < v25 )
              {
                v50 = v26;
                v51 = v24 - v26;
                v52 = v25 - v26;
                do
                {
                  v53 = v15->m_Polygon.m_Points.m_Memory.m_pMemory;
                  v54 = v53[v50].x;
                  v55 = v53[v50].y;
                  v56 = v53[v50].z;
                  v53[v50++].x = v53[v51 - 1].x;
                  v53[v50 - 1].y = v53[v51 - 1].y;
                  v53[v50 - 1].z = v53[v51 - 1].z;
                  p_x = &v15->m_Polygon.m_Points.m_Memory.m_pMemory[--v51].x;
                  --v52;
                  *p_x = v54;
                  p_x[1] = v55;
                  p_x[2] = v56;
                }
                while ( v52 != 0 );
              }
              v4 = pPortal;
            }
            else if ( v4 == (CBSPPortal *)-12 )
            {
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: nullptr);
            }
            else
            {
              CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
                this: &v15->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                other: &v4->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
            }
            SubdivideFaceForLightmaps(
              pMapFile: this->m_pMapFile,
              pFaceList: (CBSPFace *)&v4->m_PortalFaces,
              nOriginalFaceIndex: 0);
            CUtlVector<ColorRGBExp32,CUtlMemory<ColorRGBExp32,int>>::InsertMultipleBefore(
              this: &v4->m_pOnNode->m_Faces,
              elem: v4->m_pOnNode->m_Faces.m_Size,
              num: v4->m_PortalFaces.m_Size,
              pToInsert: v4->m_PortalFaces.m_Memory.m_pMemory);
          }
        }
      }
    }
LABEL_48:
    v2 = pModel;
    v3 = nPortal + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FDD0
// Name: private: void CSimpleBSPFile::CreateDisplacementFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateDisplacementFaces(CSimpleBSPFile *this)
{
  int m_Size; // esi
  int v3; // esi
  MapBrushSide_t *v4; // eax
  bool v5; // zf
  Polygon_t *p_m_Polygon; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v7; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  m_Size = this->m_pMapFile->m_Displacements.m_Size;
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(this: &this->m_DisplacementFaces);
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::InsertMultipleBefore(
    this: &this->m_DisplacementFaces,
    elem: this->m_DisplacementFaces.m_Size,
    num: m_Size);
  v3 = 0;
  i = 0;
  if ( this->m_DisplacementFaces.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      v4 = &this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[this->m_pMapFile->m_Displacements.m_Memory.m_pMemory[v9].m_nOriginalBrushSide];
      v5 = &v4->m_Polygon == nullptr;
      p_m_Polygon = &v4->m_Polygon;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nTextureInfoIndex = (int)p_m_Polygon[-1].m_Points.m_pElements;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nPlaneIndex = p_m_Polygon[-1].m_Points.m_Size;
      if ( v5 )
        v7 = nullptr;
      else
        v7 = &p_m_Polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: &this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        other: v7);
      ++v9;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3].m_nDisplacementIndex = i;
      this->m_DisplacementFaces.m_Memory.m_pMemory[v3++].m_nSerializedFaceIndex = this->m_nNextFaceIndex++;
      ++i;
    }
    while ( i < this->m_DisplacementFaces.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410070
// Name: public: CBSPBrush::CBSPBrush(class CBSPBrush const __near &)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CBSPBrush::CBSPBrush(CBSPBrush *this, const CBSPBrush *__that)
{
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v3; // ecx

  this->m_vMinBounds = __that->m_vMinBounds;
  this->m_vMaxBounds = __that->m_vMaxBounds;
  v3 = &this->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
  v3->m_Memory.m_pMemory = nullptr;
  v3->m_Memory.m_nAllocationCount = 0;
  v3->m_Memory.m_nGrowSize = 0;
  v3->m_Size = 0;
  v3->m_pElements = nullptr;
  this->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
    this: v3,
    pArray: __that->m_Sides.m_Memory.m_pMemory,
    size: __that->m_Sides.m_Size);
  this->m_ContentsFlags = __that->m_ContentsFlags;
  this->m_pOriginalBrush = __that->m_pOriginalBrush;
  this->m_nTempSplitSide = __that->m_nTempSplitSide;
  this->m_nSplitSide = __that->m_nSplitSide;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004100E0
// Name: public: CBSPNode::~CBSPNode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPNode::~CBSPNode(CBSPNode *this)
{
  CBSPNode *v2; // edi
  CBSPNode *v3; // edi
  int v4; // eax
  CBSPBrush *v5; // edi
  CBSPBrushSide *m_pMemory; // eax
  CBSPPortal **v7; // eax
  CBSPFace **v8; // eax
  CBSPBrush **v9; // eax
  int i; // [esp+10h] [ebp-4h]

  v2 = this->m_pChildren[0];
  if ( v2 != nullptr )
  {
    CBSPNode::~CBSPNode(this: this->m_pChildren[0]);
    free(pMem: v2);
  }
  v3 = this->m_pChildren[1];
  if ( v3 != nullptr )
  {
    CBSPNode::~CBSPNode(this: this->m_pChildren[1]);
    free(pMem: v3);
  }
  v4 = 0;
  for ( i = 0; v4 < this->m_ClippedBrushes.m_Size; i = v4 )
  {
    v5 = this->m_ClippedBrushes.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v5->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
      if ( v5->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5->m_Sides.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Sides.m_Memory.m_pMemory);
          v5->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v5->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v5->m_Sides.m_Memory.m_pMemory;
      v5->m_Sides.m_pElements = m_pMemory;
      if ( v5->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v5->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v5->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v5);
      v4 = i;
    }
    ++v4;
  }
  this->m_Portals.m_Size = 0;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Portals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Portals.m_Memory.m_pMemory);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_Portals.m_Memory.m_pMemory;
  this->m_Portals.m_pElements = v7;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Faces.m_Size = 0;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Faces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Faces.m_Memory.m_pMemory);
      this->m_Faces.m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_Faces.m_Memory.m_pMemory;
  this->m_Faces.m_pElements = v8;
  if ( this->m_Faces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_Faces.m_Memory.m_pMemory = nullptr;
    }
    this->m_Faces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ClippedBrushes.m_Size = 0;
  if ( this->m_ClippedBrushes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ClippedBrushes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ClippedBrushes.m_Memory.m_pMemory);
      this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
    }
    this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_ClippedBrushes.m_Memory.m_pMemory;
  this->m_ClippedBrushes.m_pElements = v9;
  if ( this->m_ClippedBrushes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
    }
    this->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410290
// Name: public: CBSPBrush::CBSPBrush(struct MapBrush_t const __near *,struct MapBrushSide_t const __near *)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CBSPBrush::CBSPBrush(
        CBSPBrush *this,
        const MapBrush_t *pMapBrush,
        const MapBrushSide_t *pMapBrushSides)
{
  int v5; // eax
  const MapBrushSide_t *v6; // eax
  int m_nTextureInfoIndex; // edx
  __int16 m_SurfaceFlags; // cx
  int m_Size; // edx
  const Vector *m_pMemory; // eax
  CBSPBrushSide src; // [esp+4h] [ebp-24h] BYREF
  int i; // [esp+30h] [ebp+8h]

  this->m_vMinBounds = pMapBrush->m_vMinBounds;
  this->m_vMaxBounds = pMapBrush->m_vMaxBounds;
  this->m_Sides.m_Memory.m_pMemory = nullptr;
  this->m_Sides.m_Memory.m_nAllocationCount = 0;
  this->m_Sides.m_Memory.m_nGrowSize = 0;
  this->m_Sides.m_Size = 0;
  this->m_Sides.m_pElements = nullptr;
  this->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
  this->m_ContentsFlags = pMapBrush->m_ContentsFlags;
  this->m_pOriginalBrush = pMapBrush;
  this->m_nTempSplitSide = PLANE_SIDE_INVALID;
  this->m_nSplitSide = PLANE_SIDE_INVALID;
  for ( i = 0; i < pMapBrush->m_nNumSides; ++i )
  {
    v5 = i + pMapBrush->m_nFirstSideIndex;
    memset(
      &src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      0,
      sizeof(src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
    v6 = &pMapBrushSides[v5];
    m_nTextureInfoIndex = v6->m_nTextureInfoIndex;
    src.m_nPlaneIndex = v6->m_nPlaneIndex;
    m_SurfaceFlags = v6->m_SurfaceFlags;
    src.m_nTextureInfoIndex = m_nTextureInfoIndex;
    m_Size = v6->m_Polygon.m_Points.m_Size;
    m_pMemory = v6->m_Polygon.m_Points.m_Memory.m_pMemory;
    src.m_SurfaceFlags = m_SurfaceFlags;
    src.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
      this: &src.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      pArray: m_pMemory,
      size: m_Size);
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
      this: &this->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
      elem: this->m_Sides.m_Size,
      &src);
    if ( src.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 && src.m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Polygon.m_Points.m_Memory.m_pMemory);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004103A0
// Name: private: void CSimpleBSPFile::SplitBrush(class CBSPBrush __near *,int,class CBSPBrush __near * __near *,class CBSPBrush __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::SplitBrush(
        CSimpleBSPFile *this,
        CBSPBrush *pBrush,
        int nPlaneIndex,
        CBSPBrush **ppFrontBrush,
        CBSPBrush **ppBackBrush)
{
  CBSPBrush *v5; // ebx
  HashedPlane_t *v6; // esi
  int m_Size; // ecx
  float v8; // xmm6_4
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // eax
  int v10; // edi
  Vector *m_pMemory; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float m_flDistance; // xmm5_4
  float *p_z; // edx
  float *v17; // ecx
  unsigned int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  int v27; // edi
  float *p_x; // ecx
  float v29; // xmm0_4
  CBSPBrush *v30; // eax
  CBSPBrush *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // edi
  float v36; // xmm3_4
  float v37; // xmm1_4
  float flDistance; // xmm3_4
  HashedPlane_t *v39; // eax
  int v40; // edx
  CBSPBrush *v41; // xmm2_4
  CBSPBrush *v42; // xmm1_4
  float v43; // xmm0_4
  int v44; // ecx
  Vector *v45; // eax
  CBSPBrush *v46; // eax
  CBSPBrush *v47; // esi
  int v48; // eax
  int m_ContentsFlags; // edx
  int v50; // ecx
  int *p_m_nGrowSize; // eax
  CBSPBrush *v52; // edi
  int v53; // esi
  int v54; // eax
  int v55; // edx
  float v56; // eax
  _DWORD *v57; // eax
  int v58; // ecx
  int v59; // ecx
  int v60; // ecx
  int v61; // ecx
  int v62; // ecx
  int v63; // ebx
  int v64; // ebx
  Polygon_t *p_splitPlanePolygon; // esi
  CCopyableUtlVector<Vector>_vtbl *v66; // eax
  CBSPBrush *v67; // edi
  int v68; // eax
  float *v69; // ecx
  CBSPBrushSide *v70; // eax
  CBSPBrush *v71; // edi
  CBSPBrushSide *v72; // eax
  CBSPBrush *v73; // edi
  int k; // edi
  CBSPBrush *v75; // ebx
  int v76; // eax
  int v77; // ecx
  Vector *v78; // ecx
  int v79; // ecx
  int v80; // ecx
  Vector *v81; // ecx
  Vector *v82; // eax
  bool v83; // zf
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v84; // ecx
  CBSPBrushSide *v85; // eax
  CBSPBrush *v86; // eax
  CBSPBrush *v87; // esi
  CBSPBrush **v88; // ecx
  CBSPBrush *v89; // edi
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v90; // ecx
  CBSPBrushSide *v91; // eax
  CBSPBrush *v92; // eax
  CBSPBrush *v93; // eax
  CBSPBrush *v94; // eax
  CBSPBrush *v95; // eax
  Polygon_t choppedPolygons[2]; // [esp+1Ch] [ebp-70h] BYREF
  Polygon_t splitPlanePolygon; // [esp+50h] [ebp-3Ch] BYREF
  float v98; // [esp+68h] [ebp-24h]
  CBSPBrush *pNewBrushes[2]; // [esp+6Ch] [ebp-20h]
  Plane_t *pPlane; // [esp+74h] [ebp-18h]
  CSimpleBSPFile *v101; // [esp+78h] [ebp-14h]
  int i; // [esp+7Ch] [ebp-10h]
  int v103; // [esp+80h] [ebp-Ch]
  int j; // [esp+84h] [ebp-8h]
  float flBack; // [esp+88h] [ebp-4h]

  v5 = pBrush;
  v101 = this;
  v6 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[nPlaneIndex];
  *ppBackBrush = nullptr;
  *ppFrontBrush = nullptr;
  m_Size = pBrush->m_Sides.m_Size;
  pPlane = v6;
  v8 = 0.0;
  flBack = 0.0;
  if ( m_Size <= 0 )
    goto LABEL_42;
  v9 = &pBrush->m_Sides.m_Memory.m_pMemory->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  i = (int)v9;
  v103 = m_Size;
  do
  {
    v10 = v9->m_Size;
    j = 0;
    if ( v10 >= 4 )
    {
      m_pMemory = v9->m_Memory.m_pMemory;
      y = v6->m_vNormal.y;
      x = v6->m_vNormal.x;
      z = v6->m_vNormal.z;
      m_flDistance = v6->m_flDistance;
      p_z = &m_pMemory->z;
      v17 = &m_pMemory[1].z;
      v18 = ((unsigned int)(v10 - 4) >> 2) + 1;
      j = 4 * v18;
      do
      {
        v19 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - m_flDistance;
        if ( v19 <= 0.0 || v19 <= v8 )
        {
          if ( v19 < 0.0 && flBack > v19 )
            flBack = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z))
                   - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - m_flDistance;
        }
        v20 = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17)) - m_flDistance;
        if ( v20 <= 0.0 || v20 <= v8 )
        {
          if ( v20 < 0.0 && flBack > v20 )
            flBack = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17)) - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(*(v17 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v17)) - m_flDistance;
        }
        v21 = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z)) - m_flDistance;
        if ( v21 <= 0.0 || v21 <= v8 )
        {
          if ( v21 < 0.0 && flBack > v21 )
            flBack = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z)) - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(v17[2] * y) + (float)(p_z[4] * x)) + (float)(v17[3] * z)) - m_flDistance;
        }
        v22 = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z)) - m_flDistance;
        if ( v22 <= 0.0 || v22 <= v8 )
        {
          if ( v22 < 0.0 && flBack > v22 )
            flBack = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z)) - m_flDistance;
        }
        else
        {
          v8 = (float)((float)((float)(v17[5] * y) + (float)(p_z[7] * x)) + (float)(v17[6] * z)) - m_flDistance;
        }
        p_z += 12;
        v17 += 12;
        --v18;
      }
      while ( v18 != 0 );
      v5 = pBrush;
      v9 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)i;
    }
    if ( j < v10 )
    {
      v23 = v6->m_vNormal.y;
      v24 = v6->m_vNormal.x;
      v25 = v6->m_vNormal.z;
      v26 = v6->m_flDistance;
      v27 = v10 - j;
      p_x = &v9->m_Memory.m_pMemory[j].x;
      do
      {
        v29 = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) - v26;
        if ( v29 <= 0.0 || v29 <= v8 )
        {
          if ( v29 < 0.0 && flBack > v29 )
            flBack = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) - v26;
        }
        else
        {
          v8 = (float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) - v26;
        }
        p_x += 3;
        --v27;
      }
      while ( v27 != 0 );
    }
    v9 = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)v9 + 36);
    v83 = v103-- == 1;
    i = (int)v9;
  }
  while ( !v83 );
  if ( v8 < 0.1 )
  {
LABEL_42:
    v30 = (CBSPBrush *)operator new(nSize: 0x40u);
    if ( v30 != nullptr )
      *ppBackBrush = CBSPBrush::CBSPBrush(this: v30, __that: v5);
    else
      *ppBackBrush = nullptr;
    return;
  }
  if ( flBack > -0.1 )
  {
    v31 = (CBSPBrush *)operator new(nSize: 0x40u);
    if ( v31 != nullptr )
      *ppFrontBrush = CBSPBrush::CBSPBrush(this: v31, __that: v5);
    else
      *ppFrontBrush = nullptr;
    return;
  }
  v32 = (float)(v5->m_vMaxBounds.x + v5->m_vMinBounds.x) * -0.5;
  v33 = (float)(v5->m_vMaxBounds.y + v5->m_vMinBounds.y) * -0.5;
  v34 = (float)(v5->m_vMaxBounds.z + v5->m_vMinBounds.z) * -0.5;
  v35 = 0;
  memset(
    &splitPlanePolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
    0,
    sizeof(splitPlanePolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
  splitPlanePolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  v36 = v6->m_vNormal.y * v33;
  pNewBrushes[0] = (CBSPBrush *)LODWORD(v33);
  v37 = v6->m_vNormal.x * v32;
  v98 = v32;
  flDistance = (float)((float)(v36 + v37) + (float)(v6->m_vNormal.z * v34)) + v6->m_flDistance;
  pNewBrushes[1] = (CBSPBrush *)LODWORD(v34);
  CreatePolygonFromPlane(vNormal: &v6->m_vNormal, flDistance, pPolygon: &splitPlanePolygon);
  i = 0;
  if ( v5->m_Sides.m_Size > 0 )
  {
    while ( 1 )
    {
      v39 = &v101->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v5->m_Sides.m_Memory.m_pMemory[v35].m_nPlaneIndex ^ 1];
      ChopPolygonInPlace(
        pPolygon: &splitPlanePolygon,
        vNormal: &v39->m_vNormal,
        flDistance: (float)((float)((float)(v39->m_vNormal.y * *(float *)pNewBrushes) + (float)(v39->m_vNormal.x * v98))
              + (float)(v39->m_vNormal.z * *(float *)&pNewBrushes[1]))
      + v39->m_flDistance);
      if ( splitPlanePolygon.m_Points.m_Size == 0 )
        break;
      ++v35;
      if ( ++i >= v5->m_Sides.m_Size )
        goto LABEL_52;
    }
LABEL_159:
    if ( CSimpleBSPFile::GetPrimaryPlaneSide(this: v101, pBrush: v5, pPlane: v6) == PLANE_SIDE_FRONT )
    {
      v93 = (CBSPBrush *)operator new(nSize: 0x40u);
      if ( v93 != nullptr )
        *ppFrontBrush = CBSPBrush::CBSPBrush(this: v93, __that: v5);
      else
        *ppFrontBrush = nullptr;
    }
    else
    {
      v94 = (CBSPBrush *)operator new(nSize: 0x40u);
      if ( v94 != nullptr )
        v95 = CBSPBrush::CBSPBrush(this: v94, __that: v5);
      else
        v95 = nullptr;
      *ppBackBrush = v95;
    }
    v82 = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
    splitPlanePolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    splitPlanePolygon.m_Points.m_Size = 0;
    if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
    {
      if ( splitPlanePolygon.m_Points.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitPlanePolygon.m_Points.m_Memory.m_pMemory);
        v82 = nullptr;
        splitPlanePolygon.m_Points.m_Memory.m_pMemory = nullptr;
      }
      splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount = 0;
    }
    splitPlanePolygon.m_Points.m_pElements = v82;
    if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
    {
      v83 = v82 == nullptr;
LABEL_173:
      if ( !v83 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v82);
      return;
    }
    return;
  }
LABEL_52:
  if ( splitPlanePolygon.m_Points.m_Size == 0 || IsPolygonTiny(pPolygon: &splitPlanePolygon) )
    goto LABEL_159;
  v40 = 0;
  if ( splitPlanePolygon.m_Points.m_Size > 0 )
  {
    v41 = pNewBrushes[1];
    v42 = pNewBrushes[0];
    v43 = v98;
    v44 = 0;
    do
    {
      v45 = &splitPlanePolygon.m_Points.m_Memory.m_pMemory[v44];
      v45->x = splitPlanePolygon.m_Points.m_Memory.m_pMemory[v44].x - v43;
      v45->y = v45->y - *(float *)&v42;
      ++v40;
      v45->z = v45->z - *(float *)&v41;
      ++v44;
    }
    while ( v40 < splitPlanePolygon.m_Points.m_Size );
  }
  i = 0;
  do
  {
    v46 = (CBSPBrush *)operator new(nSize: 0x40u);
    v47 = v46;
    if ( v46 != nullptr )
    {
      v46->m_Sides.m_Memory.m_pMemory = nullptr;
      v46->m_Sides.m_Memory.m_nAllocationCount = 0;
      v46->m_Sides.m_Memory.m_nGrowSize = 0;
      v46->m_Sides.m_Size = 0;
      v46->m_Sides.m_pElements = nullptr;
      v46->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      v46->m_ContentsFlags = 0;
      v46->m_pOriginalBrush = nullptr;
      v46->m_nTempSplitSide = PLANE_SIDE_INVALID;
      v46->m_nSplitSide = PLANE_SIDE_INVALID;
      ClearBounds(mins: &v46->m_vMinBounds, maxs: &v46->m_vMaxBounds);
    }
    else
    {
      v47 = nullptr;
    }
    v48 = i;
    m_ContentsFlags = v5->m_ContentsFlags;
    pNewBrushes[i] = v47;
    v47->m_ContentsFlags = m_ContentsFlags;
    v47->m_pOriginalBrush = v5->m_pOriginalBrush;
    i = v48 + 1;
  }
  while ( v48 + 1 < 2 );
  v101 = nullptr;
  if ( v5->m_Sides.m_Size > 0 )
  {
    j = 0;
    do
    {
      v50 = 1;
      p_m_nGrowSize = &choppedPolygons[0].m_Points.m_Memory.m_nGrowSize;
      do
      {
        *(p_m_nGrowSize - 2) = 0;
        *(p_m_nGrowSize - 1) = 0;
        *p_m_nGrowSize = 0;
        p_m_nGrowSize[1] = 0;
        p_m_nGrowSize[2] = 0;
        *(p_m_nGrowSize - 3) = (int)&CCopyableUtlVector<Vector>::`vftable';
        p_m_nGrowSize += 6;
        --v50;
      }
      while ( v50 >= 0 );
      ChopPolygon(
        polygon: (const Polygon_t *)((char *)&pBrush->m_Sides.m_Memory.m_pMemory->m_Polygon + j),
        vNormal: &pPlane->m_vNormal,
        flDistance: pPlane->m_flDistance,
        pOn: nullptr,
        pFront: choppedPolygons,
        pBack: &choppedPolygons[1]);
      i = 0;
      flBack = COERCE_FLOAT(choppedPolygons);
      do
      {
        if ( *(int *)(LODWORD(flBack) + 16) > 0 )
        {
          v52 = pNewBrushes[i];
          CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
            this: &v52->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
            elem: v52->m_Sides.m_Size);
          v53 = (int)&v52->m_Sides.m_Memory.m_pMemory[v52->m_Sides.m_Size - 1];
          v54 = j;
          *(_DWORD *)v53 = *(int *)((char *)&pBrush->m_Sides.m_Memory.m_pMemory->m_nPlaneIndex + j);
          v55 = *(int *)((char *)&pBrush->m_Sides.m_Memory.m_pMemory->m_nTextureInfoIndex + v54);
          *(_WORD *)(v53 + 8) = 0;
          v56 = flBack;
          *(_DWORD *)(v53 + 4) = v55;
          v57 = v56 == 0.0 ? nullptr : (_DWORD *)(LODWORD(v56) + 4);
          v58 = *(_DWORD *)(v53 + 24);
          *(_DWORD *)(v53 + 24) = v57[2];
          v57[2] = v58;
          v59 = *(_DWORD *)(v53 + 16);
          *(_DWORD *)(v53 + 16) = *v57;
          *v57 = v59;
          v60 = *(_DWORD *)(v53 + 20);
          *(_DWORD *)(v53 + 20) = v57[1];
          v57[1] = v60;
          v61 = *(_DWORD *)(v53 + 28);
          *(_DWORD *)(v53 + 28) = v57[3];
          v57[3] = v61;
          v62 = *(_DWORD *)(v53 + 32);
          *(_DWORD *)(v53 + 32) = v57[4];
          v63 = 0;
          v57[4] = v62;
          if ( *(int *)(v53 + 28) > 0 )
          {
            v103 = 0;
            do
            {
              AddPointToBounds(
                v: (const Vector *)(v103 + *(_DWORD *)(v53 + 16)),
                mins: &v52->m_vMinBounds,
                maxs: &v52->m_vMaxBounds);
              v103 += 12;
              ++v63;
            }
            while ( v63 < *(_DWORD *)(v53 + 28) );
          }
        }
        LODWORD(flBack) += 24;
        ++i;
      }
      while ( i < 2 );
      v64 = 1;
      p_splitPlanePolygon = &splitPlanePolygon;
      do
      {
        --p_splitPlanePolygon;
        p_splitPlanePolygon[-1].m_Points.m_pElements = (Vector *)&CCopyableUtlVector<Vector>::`vftable';
        p_splitPlanePolygon->m_Points.m_Memory.m_nGrowSize = 0;
        if ( p_splitPlanePolygon->m_Points.m_Memory.m_nAllocationCount >= 0 )
        {
          if ( p_splitPlanePolygon->m_Points.__vftable != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_splitPlanePolygon->m_Points.__vftable);
            p_splitPlanePolygon->m_Points.__vftable = nullptr;
          }
          p_splitPlanePolygon->m_Points.m_Memory.m_pMemory = nullptr;
        }
        v66 = p_splitPlanePolygon->m_Points.__vftable;
        p_splitPlanePolygon->m_Points.m_Size = (int)p_splitPlanePolygon->m_Points.__vftable;
        if ( p_splitPlanePolygon->m_Points.m_Memory.m_nAllocationCount >= 0 )
        {
          if ( v66 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
            p_splitPlanePolygon->m_Points.__vftable = nullptr;
          }
          p_splitPlanePolygon->m_Points.m_Memory.m_pMemory = nullptr;
        }
        --v64;
      }
      while ( v64 >= 0 );
      j += 36;
      v101 = (CSimpleBSPFile *)((char *)v101 + 1);
    }
    while ( (int)v101 < pBrush->m_Sides.m_Size );
  }
  flBack = 0.0;
  do
  {
    v67 = pNewBrushes[LODWORD(flBack)];
    v68 = 0;
    v69 = &v67->m_vMinBounds.x;
    while ( *v69 >= -16384.0 && v69[3] <= 16384.0 )
    {
      ++v68;
      ++v69;
      if ( v68 >= 3 )
        goto LABEL_103;
    }
    if ( v67 != nullptr )
    {
      v67->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v67->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
      if ( v67->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v67->m_Sides.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v67->m_Sides.m_Memory.m_pMemory);
          v67->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v67->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      v70 = v67->m_Sides.m_Memory.m_pMemory;
      v67->m_Sides.m_pElements = v70;
      if ( v67->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v70 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v70);
          v67->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v67->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v67);
    }
    pNewBrushes[LODWORD(flBack)] = nullptr;
LABEL_103:
    v71 = pNewBrushes[LODWORD(flBack)];
    if ( v71 != nullptr && v71->m_Sides.m_Size < 3 )
    {
      v71->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v71->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
      if ( v71->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v71->m_Sides.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v71->m_Sides.m_Memory.m_pMemory);
          v71->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v71->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      v72 = v71->m_Sides.m_Memory.m_pMemory;
      v71->m_Sides.m_pElements = v72;
      if ( v71->m_Sides.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v72 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v72);
          v71->m_Sides.m_Memory.m_pMemory = nullptr;
        }
        v71->m_Sides.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v71);
      pNewBrushes[LODWORD(flBack)] = nullptr;
    }
    ++LODWORD(flBack);
  }
  while ( SLODWORD(flBack) < 2 );
  v73 = pNewBrushes[0];
  if ( pNewBrushes[0] != nullptr )
  {
    if ( pNewBrushes[1] != nullptr )
    {
      for ( k = 0; k < 2; ++k )
      {
        v75 = pNewBrushes[k];
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
          this: &v75->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
          elem: v75->m_Sides.m_Size);
        v76 = (int)&v75->m_Sides.m_Memory.m_pMemory[v75->m_Sides.m_Size - 1];
        *(_DWORD *)v76 = nPlaneIndex ^ k ^ 1;
        *(_DWORD *)(v76 + 4) = -1;
        *(_WORD *)(v76 + 8) = 0;
        if ( k != 0 )
        {
          v77 = *(_DWORD *)(v76 + 24);
          *(_DWORD *)(v76 + 24) = splitPlanePolygon.m_Points.m_Memory.m_nGrowSize;
          splitPlanePolygon.m_Points.m_Memory.m_nGrowSize = v77;
          v78 = *(Vector **)(v76 + 16);
          *(_DWORD *)(v76 + 16) = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
          splitPlanePolygon.m_Points.m_Memory.m_pMemory = v78;
          v79 = *(_DWORD *)(v76 + 20);
          *(_DWORD *)(v76 + 20) = splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount;
          splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount = v79;
          v80 = *(_DWORD *)(v76 + 28);
          *(_DWORD *)(v76 + 28) = splitPlanePolygon.m_Points.m_Size;
          splitPlanePolygon.m_Points.m_Size = v80;
          v81 = *(Vector **)(v76 + 32);
          *(_DWORD *)(v76 + 32) = splitPlanePolygon.m_Points.m_pElements;
          splitPlanePolygon.m_Points.m_pElements = v81;
        }
        else
        {
          CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
            this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)(v76 + 16),
            other: &splitPlanePolygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
        }
      }
      *(_QWORD *)ppFrontBrush = *(_QWORD *)pNewBrushes;
      v82 = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
      splitPlanePolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      splitPlanePolygon.m_Points.m_Size = 0;
      if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( splitPlanePolygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitPlanePolygon.m_Points.m_Memory.m_pMemory);
          v82 = nullptr;
          splitPlanePolygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      splitPlanePolygon.m_Points.m_pElements = v82;
      if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        v83 = v82 == nullptr;
        goto LABEL_173;
      }
      return;
    }
    v84 = &pNewBrushes[0]->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
    pNewBrushes[0]->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: v84);
    if ( v73->m_Sides.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v73->m_Sides.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v73->m_Sides.m_Memory.m_pMemory);
        v73->m_Sides.m_Memory.m_pMemory = nullptr;
      }
      v73->m_Sides.m_Memory.m_nAllocationCount = 0;
    }
    v85 = v73->m_Sides.m_Memory.m_pMemory;
    v73->m_Sides.m_pElements = v85;
    if ( v73->m_Sides.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v85 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v85);
        v73->m_Sides.m_Memory.m_pMemory = nullptr;
      }
      v73->m_Sides.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v73);
    v86 = (CBSPBrush *)operator new(nSize: 0x40u);
    v87 = v86;
    if ( v86 != nullptr )
    {
      v86->m_vMinBounds = pBrush->m_vMinBounds;
      v86->m_vMaxBounds = pBrush->m_vMaxBounds;
      v86->m_Sides.m_Memory.m_pMemory = nullptr;
      v86->m_Sides.m_Memory.m_nAllocationCount = 0;
      v86->m_Sides.m_Memory.m_nGrowSize = 0;
      v86->m_Sides.m_Size = 0;
      v86->m_Sides.m_pElements = nullptr;
      v86->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        this: &v86->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
        pArray: pBrush->m_Sides.m_Memory.m_pMemory,
        size: pBrush->m_Sides.m_Size);
      v87->m_ContentsFlags = pBrush->m_ContentsFlags;
      v87->m_pOriginalBrush = pBrush->m_pOriginalBrush;
      v88 = ppFrontBrush;
      v87->m_nTempSplitSide = pBrush->m_nTempSplitSide;
      v87->m_nSplitSide = pBrush->m_nSplitSide;
    }
    else
    {
      v88 = ppFrontBrush;
      v87 = nullptr;
    }
  }
  else
  {
    v89 = pNewBrushes[1];
    if ( pNewBrushes[1] == nullptr )
      goto LABEL_153;
    v90 = &pNewBrushes[1]->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
    pNewBrushes[1]->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
    CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: v90);
    if ( v89->m_Sides.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v89->m_Sides.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v89->m_Sides.m_Memory.m_pMemory);
        v89->m_Sides.m_Memory.m_pMemory = nullptr;
      }
      v89->m_Sides.m_Memory.m_nAllocationCount = 0;
    }
    v91 = v89->m_Sides.m_Memory.m_pMemory;
    v89->m_Sides.m_pElements = v91;
    if ( v89->m_Sides.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v91 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v91);
        v89->m_Sides.m_Memory.m_pMemory = nullptr;
      }
      v89->m_Sides.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v89);
    v92 = (CBSPBrush *)operator new(nSize: 0x40u);
    v87 = v92;
    if ( v92 != nullptr )
    {
      v92->m_vMinBounds = pBrush->m_vMinBounds;
      v92->m_vMaxBounds = pBrush->m_vMaxBounds;
      v92->m_Sides.m_Memory.m_pMemory = nullptr;
      v92->m_Sides.m_Memory.m_nAllocationCount = 0;
      v92->m_Sides.m_Memory.m_nGrowSize = 0;
      v92->m_Sides.m_Size = 0;
      v92->m_Sides.m_pElements = nullptr;
      v92->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
      CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        this: &v92->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >,
        pArray: pBrush->m_Sides.m_Memory.m_pMemory,
        size: pBrush->m_Sides.m_Size);
      v87->m_ContentsFlags = pBrush->m_ContentsFlags;
      v87->m_pOriginalBrush = pBrush->m_pOriginalBrush;
      v87->m_nTempSplitSide = pBrush->m_nTempSplitSide;
      v87->m_nSplitSide = pBrush->m_nSplitSide;
    }
    else
    {
      v87 = nullptr;
    }
    v88 = ppBackBrush;
  }
  *v88 = v87;
LABEL_153:
  v82 = splitPlanePolygon.m_Points.m_Memory.m_pMemory;
  splitPlanePolygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  splitPlanePolygon.m_Points.m_Size = 0;
  if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( splitPlanePolygon.m_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitPlanePolygon.m_Points.m_Memory.m_pMemory);
      v82 = nullptr;
      splitPlanePolygon.m_Points.m_Memory.m_pMemory = nullptr;
    }
    splitPlanePolygon.m_Points.m_Memory.m_nAllocationCount = 0;
  }
  splitPlanePolygon.m_Points.m_pElements = v82;
  if ( splitPlanePolygon.m_Points.m_Memory.m_nGrowSize >= 0 )
  {
    v83 = v82 == nullptr;
    goto LABEL_173;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410EF0
// Name: private: void CSimpleBSPFile::SplitBrushList(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class CBSPNode __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::SplitBrushList(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList,
        CBSPNode *pNode,
        CBSPBrush *pFrontChildList,
        CBSPBrush *pBackChildList)
{
  bool v5; // cc
  CUtlMemory<BSPCluster_t,int> *v6; // esi
  CUtlMemory<BSPCluster_t,int> *v7; // edi
  CBSPBrush *v8; // ebx
  BSPCluster_t *m_pMemory; // ebx
  int m_nAllocationCount; // eax
  BSPCluster_t *v11; // ecx
  int v12; // eax
  _DWORD *p_m_pLeafNode; // ebx
  BSPCluster_t *v14; // ebx
  int v15; // eax
  BSPCluster_t *v16; // ecx
  int v17; // eax
  _DWORD *v18; // ebx
  CBSPBrush *v19; // eax
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v20; // edx
  int v21; // ecx
  _DWORD *v22; // eax
  BSPCluster_t *v23; // ebx
  int v24; // eax
  BSPCluster_t *v25; // ecx
  int v26; // eax
  BSPCluster_t *v27; // ecx
  int v28; // eax
  BSPCluster_t *v29; // ecx
  int v30; // eax
  CBSPBrush **v31; // ebx
  PlaneSide_t whichSide; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  CBSPBrush *pBack; // [esp+Ch] [ebp-8h] BYREF
  int i; // [esp+10h] [ebp-4h]

  v5 = pBrushList->m_Size <= 0;
  i = 0;
  if ( !v5 )
  {
    v6 = (CUtlMemory<BSPCluster_t,int> *)pBackChildList;
    v7 = (CUtlMemory<BSPCluster_t,int> *)pFrontChildList;
    do
    {
      v8 = pBrushList->m_Memory.m_pMemory[i];
      whichSide = v8->m_nSplitSide;
      if ( whichSide == PLANE_SIDE_BOTH )
      {
        CSimpleBSPFile::SplitBrush(
          this,
          pBrush: v8,
          nPlaneIndex: pNode->m_nSplitPlaneIndex,
          ppFrontBrush: &pFrontChildList,
          ppBackBrush: &pBack);
        if ( pFrontChildList != nullptr )
        {
          m_pMemory = v7[1].m_pMemory;
          m_nAllocationCount = v7->m_nAllocationCount;
          if ( (int)&m_pMemory->m_pLeafNode + 1 > m_nAllocationCount )
            CUtlMemory<ColorRGBExp32,int>::Grow(this: v7, num: (int)&m_pMemory->m_pLeafNode - m_nAllocationCount + 1);
          ++v7[1].m_pMemory;
          v11 = v7->m_pMemory;
          v12 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
          v7[1].m_nAllocationCount = (int)v7->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
          p_m_pLeafNode = &v7->m_pMemory[(_DWORD)m_pMemory].m_pLeafNode;
          if ( p_m_pLeafNode != nullptr )
            *p_m_pLeafNode = pFrontChildList;
        }
        if ( pBack != nullptr )
        {
          v14 = v6[1].m_pMemory;
          v15 = v6->m_nAllocationCount;
          if ( (int)&v14->m_pLeafNode + 1 > v15 )
            CUtlMemory<ColorRGBExp32,int>::Grow(this: v6, num: (int)&v14->m_pLeafNode - v15 + 1);
          ++v6[1].m_pMemory;
          v16 = v6->m_pMemory;
          v17 = (char *)v6[1].m_pMemory - (char *)v14 - 1;
          v6[1].m_nAllocationCount = (int)v6->m_pMemory;
          if ( v17 > 0 )
            _V_memmove(dest: &v16[(_DWORD)v14 + 1], src: &v16[(_DWORD)v14], count: 4 * v17);
          v18 = &v6->m_pMemory[(_DWORD)v14].m_pLeafNode;
          if ( v18 != nullptr )
            *v18 = pBack;
        }
      }
      else
      {
        v19 = (CBSPBrush *)operator new(nSize: 0x40u);
        if ( v19 != nullptr )
          pBackChildList = CBSPBrush::CBSPBrush(this: v19, __that: v8);
        else
          pBackChildList = nullptr;
        if ( (whichSide & 4) != 0 )
        {
          v20 = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)pBackChildList;
          v21 = 0;
          for ( j = 0; j < pBackChildList->m_Sides.m_Size; ++j )
          {
            v22 = (_DWORD *)(v21 + v20[1].m_Memory.m_nGrowSize);
            if ( (*v22 & 0xFFFFFFFE) == pNode->m_nSplitPlaneIndex )
              v22[1] = -1;
            v20 = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)pBackChildList;
            v21 += 36;
          }
        }
        if ( (whichSide & 1) != 0 )
        {
          v23 = v7[1].m_pMemory;
          v24 = v7->m_nAllocationCount;
          if ( (int)&v23->m_pLeafNode + 1 > v24 )
            CUtlMemory<ColorRGBExp32,int>::Grow(this: v7, num: (int)&v23->m_pLeafNode - v24 + 1);
          ++v7[1].m_pMemory;
          v25 = v7->m_pMemory;
          v26 = (char *)v7[1].m_pMemory - (char *)v23 - 1;
          v7[1].m_nAllocationCount = (int)v7->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(dest: &v25[(_DWORD)v23 + 1], src: &v25[(_DWORD)v23], count: 4 * v26);
          v27 = v7->m_pMemory;
        }
        else
        {
          v23 = v6[1].m_pMemory;
          v28 = v6->m_nAllocationCount;
          if ( (int)&v23->m_pLeafNode + 1 > v28 )
            CUtlMemory<ColorRGBExp32,int>::Grow(this: v6, num: (int)&v23->m_pLeafNode - v28 + 1);
          ++v6[1].m_pMemory;
          v29 = v6->m_pMemory;
          v30 = (char *)v6[1].m_pMemory - (char *)v23 - 1;
          v6[1].m_nAllocationCount = (int)v6->m_pMemory;
          if ( v30 > 0 )
            _V_memmove(dest: &v29[(_DWORD)v23 + 1], src: &v29[(_DWORD)v23], count: 4 * v30);
          v27 = v6->m_pMemory;
        }
        v31 = (CBSPBrush **)&v27[(_DWORD)v23];
        if ( v31 != nullptr )
          *v31 = pBackChildList;
      }
      ++i;
    }
    while ( i < pBrushList->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411130
// Name: private: void CSimpleBSPFile::PruneNodes(class CBSPNode __near *,class CUtlVector<class CBSPPortal __near *,class CUtlMemory<class CBSPPortal __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::PruneNodes(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlVector<CBSPPortal *,CUtlMemory<CBSPPortal *,int> > *pPortalList)
{
  CBSPNode *v4; // eax
  int m_nGrowSize; // edx
  CBSPBrush **m_pMemory; // edx
  int m_nAllocationCount; // edx
  int m_Size; // edx
  CBSPBrush **m_pElements; // edx
  int i; // edx
  CBSPPortal *v11; // eax
  CBSPNode *m_pOnNode; // ecx
  CBSPNode *v13; // ecx
  CBSPNode *v14; // edi
  CBSPNode *v15; // edi

  if ( pNode->m_nSplitPlaneIndex != -1 )
  {
    CSimpleBSPFile::PruneNodes(this, pNode: pNode->m_pChildren[0], pPortalList);
    CSimpleBSPFile::PruneNodes(this, pNode: pNode->m_pChildren[1], pPortalList);
    if ( (pNode->m_pChildren[0]->m_ContentsFlags & 1) != 0 )
    {
      v4 = pNode->m_pChildren[1];
      if ( (v4->m_ContentsFlags & 1) != 0 )
      {
        pNode->m_ContentsFlags = 1;
        pNode->m_nSplitPlaneIndex = -1;
        m_nGrowSize = pNode->m_ClippedBrushes.m_Memory.m_nGrowSize;
        pNode->m_ClippedBrushes.m_Memory.m_nGrowSize = v4->m_ClippedBrushes.m_Memory.m_nGrowSize;
        v4->m_ClippedBrushes.m_Memory.m_nGrowSize = m_nGrowSize;
        m_pMemory = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
        pNode->m_ClippedBrushes.m_Memory.m_pMemory = v4->m_ClippedBrushes.m_Memory.m_pMemory;
        v4->m_ClippedBrushes.m_Memory.m_pMemory = m_pMemory;
        m_nAllocationCount = pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount;
        pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount = v4->m_ClippedBrushes.m_Memory.m_nAllocationCount;
        v4->m_ClippedBrushes.m_Memory.m_nAllocationCount = m_nAllocationCount;
        m_Size = pNode->m_ClippedBrushes.m_Size;
        pNode->m_ClippedBrushes.m_Size = v4->m_ClippedBrushes.m_Size;
        v4->m_ClippedBrushes.m_Size = m_Size;
        m_pElements = pNode->m_ClippedBrushes.m_pElements;
        pNode->m_ClippedBrushes.m_pElements = v4->m_ClippedBrushes.m_pElements;
        v4->m_ClippedBrushes.m_pElements = m_pElements;
        CUtlVector<ColorRGBExp32,CUtlMemory<ColorRGBExp32,int>>::InsertMultipleBefore(
          this: (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)&pNode->m_ClippedBrushes,
          elem: pNode->m_ClippedBrushes.m_Size,
          num: pNode->m_pChildren[0]->m_ClippedBrushes.m_Size,
          pToInsert: (CBSPFace *const *)pNode->m_pChildren[0]->m_ClippedBrushes.m_Memory.m_pMemory);
        pNode->m_pChildren[0]->m_ClippedBrushes.m_Size = 0;
        for ( i = 0; i < pPortalList->m_Size; ++i )
        {
          v11 = pPortalList->m_Memory.m_pMemory[i];
          m_pOnNode = v11->m_pOnNode;
          if ( m_pOnNode == pNode->m_pChildren[0] || m_pOnNode == pNode->m_pChildren[1] )
            v11->m_pOnNode = nullptr;
          if ( v11->m_pNodes[0] == pNode->m_pChildren[0] || v11->m_pNodes[0] == pNode->m_pChildren[1] )
            v11->m_pNodes[0] = pNode;
          v13 = v11->m_pNodes[1];
          if ( v13 == pNode->m_pChildren[0] || v13 == pNode->m_pChildren[1] )
            v11->m_pNodes[1] = pNode;
        }
        v14 = pNode->m_pChildren[0];
        if ( v14 != nullptr )
        {
          CBSPNode::~CBSPNode(this: pNode->m_pChildren[0]);
          free(pMem: v14);
        }
        v15 = pNode->m_pChildren[1];
        if ( v15 != nullptr )
        {
          CBSPNode::~CBSPNode(this: pNode->m_pChildren[1]);
          free(pMem: v15);
        }
        pNode->m_pChildren[0] = nullptr;
        pNode->m_pChildren[1] = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411260
// Name: private: void CSimpleBSPFile::FilterBrushIntoTree(class CBSPNode __near *,class CBSPBrush __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::FilterBrushIntoTree(CSimpleBSPFile *this, CBSPBrush *pNode, CBSPBrush *pBrush)
{
  CBSPNode *v3; // esi
  int x_low; // eax
  CBSPBrush *v5; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CBSPBrush **m_pMemory; // ecx
  int v10; // eax
  CBSPBrush **v11; // ebx

  v3 = (CBSPNode *)pNode;
  x_low = LODWORD(pNode->m_vMaxBounds.x);
  v5 = pBrush;
  if ( x_low == -1 )
  {
LABEL_8:
    if ( (v3->m_ContentsFlags & 1) != 0 )
    {
      if ( v5 != nullptr )
      {
        v5->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: &v5->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        free(pMem: v5);
      }
    }
    else
    {
      m_Size = v3->m_ClippedBrushes.m_Size;
      m_nAllocationCount = v3->m_ClippedBrushes.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ColorRGBExp32,int>::Grow(
          this: (CUtlMemory<BSPCluster_t,int> *)&v3->m_ClippedBrushes,
          num: m_Size - m_nAllocationCount + 1);
      ++v3->m_ClippedBrushes.m_Size;
      m_pMemory = v3->m_ClippedBrushes.m_Memory.m_pMemory;
      v10 = v3->m_ClippedBrushes.m_Size - m_Size - 1;
      v3->m_ClippedBrushes.m_pElements = m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
      v11 = &v3->m_ClippedBrushes.m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        *v11 = v5;
    }
  }
  else
  {
    while ( 1 )
    {
      CSimpleBSPFile::SplitBrush(this, pBrush: v5, nPlaneIndex: x_low, ppFrontBrush: &pBrush, ppBackBrush: &pNode);
      if ( v5 != nullptr )
      {
        v5->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: &v5->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        free(pMem: v5);
      }
      if ( pBrush != nullptr )
        CSimpleBSPFile::FilterBrushIntoTree(this, pNode: v3->m_pChildren[0], pBrush);
      v5 = pNode;
      if ( pNode == nullptr )
        break;
      v3 = v3->m_pChildren[1];
      x_low = v3->m_nSplitPlaneIndex;
      if ( x_low == -1 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411350
// Name: public: CBSPModel::~CBSPModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPModel::~CBSPModel(CBSPModel *this)
{
  CBSPTree *m_pTree; // esi
  int v3; // eax
  CBSPFace *v4; // esi
  Vector *m_pMemory; // eax
  int j; // esi
  CBSPPortal **v7; // ecx
  CBSPPortal *v8; // ebx
  CBSPPortal **v9; // eax
  CBSPFace **v10; // eax
  CBSPNode *i; // [esp+Ch] [ebp-4h]
  int ia; // [esp+Ch] [ebp-4h]

  m_pTree = this->m_pTree;
  if ( this->m_pTree != nullptr )
  {
    i = m_pTree->m_pRoot;
    if ( m_pTree->m_pRoot != nullptr )
    {
      CBSPNode::~CBSPNode(this: m_pTree->m_pRoot);
      free(pMem: i);
    }
    CBSPNode::~CBSPNode(this: &m_pTree->m_OutsideNode);
    free(pMem: m_pTree);
  }
  v3 = 0;
  for ( ia = 0; v3 < this->m_DetailFaces.m_Size; ia = v3 )
  {
    v4 = this->m_DetailFaces.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      v4->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      v4->m_Polygon.m_Points.m_Size = 0;
      if ( v4->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4->m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_Polygon.m_Points.m_Memory.m_pMemory);
          v4->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v4->m_Polygon.m_Points.m_Memory.m_pMemory;
      v4->m_Polygon.m_Points.m_pElements = m_pMemory;
      if ( v4->m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v4->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        v4->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v4);
      v3 = ia;
    }
    ++v3;
  }
  for ( j = 0; j < this->m_Portals.m_Size; ++j )
  {
    v7 = this->m_Portals.m_Memory.m_pMemory;
    v8 = v7[j];
    if ( v8 != nullptr )
    {
      CBSPPortal::~CBSPPortal(this: v7[j]);
      free(pMem: v8);
    }
  }
  this->m_Portals.m_Size = 0;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Portals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Portals.m_Memory.m_pMemory);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_Portals.m_Memory.m_pMemory;
  this->m_Portals.m_pElements = v9;
  if ( this->m_Portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_Portals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Portals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DetailFaces.m_Size = 0;
  if ( this->m_DetailFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DetailFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DetailFaces.m_Memory.m_pMemory);
      this->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_DetailFaces.m_Memory.m_pMemory;
  this->m_DetailFaces.m_pElements = v10;
  if ( this->m_DetailFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004114D0
// Name: private: class CBSPBrush __near * CSimpleBSPFile::CreateClippedBrush(struct MapBrush_t const __near *,class Vector const __near &,class Vector const __near &,int __near * const,int __near * const)
// Source: json
//------------------------------------------------------------------------------
CBSPBrush *__thiscall CSimpleBSPFile::CreateClippedBrush(
        CSimpleBSPFile *this,
        CBSPBrush *pMapBrush,
        CBSPBrush *vClipMin,
        const Vector *vClipMax,
        int *nClipMinPlanes,
        int *nClipMaxPlanes)
{
  const MapBrush_t *v6; // ebx
  const Vector *v7; // edi
  const Vector *p_m_vMinBounds; // ecx
  int v9; // edx
  Vector *p_m_Sides; // eax
  CBSPBrush *v11; // eax
  CBSPBrush *v12; // esi
  int v14; // ecx
  char *v15; // edx
  float *p_x; // eax
  CBSPBrushSide *m_pMemory; // eax
  const MapBrush_t *v18; // edi
  float *v19; // ecx
  int y_low; // eax
  CBSPBrushSide *v21; // eax
  Vector *v22; // edi
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v23; // ecx
  float y; // eax
  int v25; // edi
  int v26; // edx
  CBSPBrushSide *v27; // ecx
  unsigned int v28; // eax
  char *v29; // [esp+Ch] [ebp-18h]
  char *v30; // [esp+10h] [ebp-14h]
  char *v31; // [esp+14h] [ebp-10h]
  int v32; // [esp+18h] [ebp-Ch]
  Vector *v33; // [esp+1Ch] [ebp-8h]

  v6 = (const MapBrush_t *)pMapBrush;
  v7 = vClipMax;
  p_m_vMinBounds = &vClipMin->m_vMinBounds;
  v9 = 0;
  p_m_Sides = (Vector *)&pMapBrush->m_Sides;
  do
  {
    if ( p_m_Sides[-1].x >= *(float *)((char *)&p_m_vMinBounds->x + (char *)vClipMax - (char *)vClipMin)
      || p_m_vMinBounds->x >= p_m_Sides->x )
    {
      return nullptr;
    }
    ++v9;
    p_m_Sides = (Vector *)((char *)p_m_Sides + 4);
    p_m_vMinBounds = (const Vector *)((char *)p_m_vMinBounds + 4);
  }
  while ( v9 < 3 );
  v11 = (CBSPBrush *)operator new(nSize: 0x40u);
  if ( v11 != nullptr )
    v12 = CBSPBrush::CBSPBrush(
            this: v11,
            pMapBrush: v6,
            pMapBrushSides: this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory);
  else
    v12 = nullptr;
  v30 = (char *)((char *)vClipMin - (char *)v7);
  v14 = 12 - (_DWORD)v7;
  v15 = (char *)((char *)nClipMaxPlanes - (char *)v7);
  p_x = &v7->x;
  vClipMax = nullptr;
  v33 = (Vector *)v7;
  v32 = 12 - (_DWORD)v7;
  v31 = (char *)((char *)nClipMaxPlanes - (char *)v7);
  v29 = (char *)((char *)nClipMinPlanes - (char *)v7);
  while ( 1 )
  {
    if ( *(float *)((char *)&v12->m_vMinBounds.x + (_DWORD)p_x + v14) > *p_x )
    {
      CSimpleBSPFile::SplitBrush(
        this,
        pBrush: v12,
        nPlaneIndex: *(_DWORD *)((char *)p_x + (_DWORD)v15),
        ppFrontBrush: &pMapBrush,
        ppBackBrush: &vClipMin);
      if ( v12 != nullptr )
      {
        v12->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v12->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->m_Sides.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Sides.m_Memory.m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v12->m_Sides.m_Memory.m_pMemory;
        v12->m_Sides.m_pElements = m_pMemory;
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v12);
      }
      v18 = (const MapBrush_t *)pMapBrush;
      if ( pMapBrush != nullptr )
      {
        v19 = (float *)&pMapBrush->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
        pMapBrush->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: (CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *)v19);
        if ( v18[1].m_ContentsFlags >= 0 )
        {
          if ( LODWORD(v18->m_vMaxBounds.y) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v18->m_vMaxBounds.y));
            v18->m_vMaxBounds.y = 0.0;
          }
          v18->m_vMaxBounds.z = 0.0;
        }
        y_low = LODWORD(v18->m_vMaxBounds.y);
        v18[1].m_nNumSides = y_low;
        if ( v18[1].m_ContentsFlags >= 0 )
        {
          if ( y_low != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)y_low);
            v18->m_vMaxBounds.y = 0.0;
          }
          v18->m_vMaxBounds.z = 0.0;
        }
        free(pMem: (void *)v18);
      }
      v12 = vClipMin;
      if ( vClipMin == nullptr )
        return nullptr;
      p_x = &v33->x;
    }
    if ( *(float *)((char *)p_x + (_DWORD)v30) > *(float *)((char *)&v12->m_vMinBounds.x + (_DWORD)vClipMax) )
    {
      CSimpleBSPFile::SplitBrush(
        this,
        pBrush: v12,
        nPlaneIndex: *(_DWORD *)((char *)p_x + (_DWORD)v29),
        ppFrontBrush: &pMapBrush,
        ppBackBrush: &vClipMin);
      if ( v12 != nullptr )
      {
        v12->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: &v12->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->m_Sides.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_Sides.m_Memory.m_pMemory);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        v21 = v12->m_Sides.m_Memory.m_pMemory;
        v12->m_Sides.m_pElements = v21;
        if ( v12->m_Sides.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            v12->m_Sides.m_Memory.m_pMemory = nullptr;
          }
          v12->m_Sides.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v12);
      }
      v22 = &vClipMin->m_vMinBounds;
      if ( vClipMin != nullptr )
      {
        v23 = &vClipMin->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >;
        vClipMin->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this: v23);
        if ( v22[3].x >= 0.0 )
        {
          if ( LODWORD(v22[2].y) != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v22[2].y));
            v22[2].y = 0.0;
          }
          v22[2].z = 0.0;
        }
        y = v22[2].y;
        v22[3].z = y;
        if ( v22[3].x >= 0.0 )
        {
          if ( y != 0.0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(y));
            v22[2].y = 0.0;
          }
          v22[2].z = 0.0;
        }
        free(pMem: v22);
      }
      v12 = pMapBrush;
      if ( pMapBrush == nullptr )
        return nullptr;
      p_x = &v33->x;
    }
    ++p_x;
    vClipMax = (const Vector *)((char *)vClipMax + 4);
    v33 = (Vector *)p_x;
    if ( (int)vClipMax >= 8 )
      break;
    v14 = v32;
    v15 = v31;
  }
  v25 = 0;
  if ( v12->m_Sides.m_Size > 0 )
  {
    v26 = 0;
    do
    {
      v27 = v12->m_Sides.m_Memory.m_pMemory;
      v28 = v27[v26].m_nPlaneIndex & 0xFFFFFFFE;
      if ( v28 == *nClipMinPlanes || v28 == nClipMinPlanes[1] || v28 == *nClipMaxPlanes || v28 == nClipMaxPlanes[1] )
        v27[v26].m_nTextureInfoIndex = -1;
      ++v25;
      ++v26;
    }
    while ( v25 < v12->m_Sides.m_Size );
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x004117E0
// Name: private: void CSimpleBSPFile::BuildBSPChildren(class CBSPNode __near *,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::BuildBSPChildren(
        CSimpleBSPFile *this,
        CBSPNode *pNode,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList)
{
  int BestSplitPlane; // eax
  int m_nGrowSize; // ecx
  CBSPBrush **m_pMemory; // ecx
  int m_nAllocationCount; // ecx
  int m_Size; // ecx
  CBSPBrush **m_pElements; // ecx
  CBSPBrush *v12; // ecx
  int m_ContentsFlags; // edx
  int v14; // edi
  int v15; // esi
  int *p_m_nTextureInfoIndex; // ecx
  int v17; // ecx
  int *p_m_nGrowSize; // eax
  int i; // edi
  CBSPBrush *v20; // eax
  CBSPNode **m_pChildren; // edi
  CBSPNode *v22; // eax
  CBSPNode *v23; // esi
  bool v24; // zf
  CBSPNode **v25; // edi
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *v26; // esi
  char *v27; // esi
  int j; // edi
  void *v29; // eax
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > childLists[2]; // [esp+Ch] [ebp-34h] BYREF
  char v31; // [esp+34h] [ebp-Ch] BYREF
  CBSPNode **v32; // [esp+38h] [ebp-8h]
  int unionFlags; // [esp+3Ch] [ebp-4h]
  int allContentsSolid; // [esp+48h] [ebp+8h]
  char allContentsSolid_3; // [esp+4Bh] [ebp+Bh]
  CBSPBrush **pBrushLista; // [esp+4Ch] [ebp+Ch]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushListb; // [esp+4Ch] [ebp+Ch]
  int pBrushListc; // [esp+4Ch] [ebp+Ch]

  unionFlags = (int)this;
  BestSplitPlane = CSimpleBSPFile::FindBestSplitPlane(this, pBrushList);
  if ( BestSplitPlane == -1 )
  {
    m_nGrowSize = pNode->m_ClippedBrushes.m_Memory.m_nGrowSize;
    pNode->m_ClippedBrushes.m_Memory.m_nGrowSize = pBrushList->m_Memory.m_nGrowSize;
    pBrushList->m_Memory.m_nGrowSize = m_nGrowSize;
    m_pMemory = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
    pNode->m_ClippedBrushes.m_Memory.m_pMemory = pBrushList->m_Memory.m_pMemory;
    pBrushList->m_Memory.m_pMemory = m_pMemory;
    m_nAllocationCount = pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount;
    pNode->m_ClippedBrushes.m_Memory.m_nAllocationCount = pBrushList->m_Memory.m_nAllocationCount;
    pBrushList->m_Memory.m_nAllocationCount = m_nAllocationCount;
    m_Size = pNode->m_ClippedBrushes.m_Size;
    pNode->m_ClippedBrushes.m_Size = pBrushList->m_Size;
    pBrushList->m_Size = m_Size;
    m_pElements = pNode->m_ClippedBrushes.m_pElements;
    pNode->m_ClippedBrushes.m_pElements = pBrushList->m_pElements;
    pBrushList->m_pElements = m_pElements;
    unionFlags = 0;
    allContentsSolid_3 = 0;
    if ( pNode->m_ClippedBrushes.m_Size <= 0 )
      goto LABEL_14;
    pBrushLista = pNode->m_ClippedBrushes.m_Memory.m_pMemory;
    v32 = (CBSPNode **)pNode->m_ClippedBrushes.m_Size;
    do
    {
      v12 = *pBrushLista;
      m_ContentsFlags = (*pBrushLista)->m_ContentsFlags;
      if ( (m_ContentsFlags & 1) != 0 )
      {
        v14 = v12->m_Sides.m_Size;
        v15 = 0;
        if ( v14 > 0 )
        {
          p_m_nTextureInfoIndex = &v12->m_Sides.m_Memory.m_pMemory->m_nTextureInfoIndex;
          do
          {
            if ( *p_m_nTextureInfoIndex != -1 )
              break;
            ++v15;
            p_m_nTextureInfoIndex += 9;
          }
          while ( v15 < v14 );
        }
        if ( v15 == v14 )
          allContentsSolid_3 = 1;
      }
      unionFlags |= m_ContentsFlags;
      ++pBrushLista;
      v32 = (CBSPNode **)((char *)v32 - 1);
    }
    while ( v32 != nullptr );
    if ( allContentsSolid_3 != 0 )
      pNode->m_ContentsFlags = 1;
    else
LABEL_14:
      pNode->m_ContentsFlags = unionFlags;
  }
  else
  {
    pNode->m_nSplitPlaneIndex = BestSplitPlane;
    v17 = 1;
    p_m_nGrowSize = &childLists[0].m_Memory.m_nGrowSize;
    do
    {
      *(p_m_nGrowSize - 2) = 0;
      *(p_m_nGrowSize - 1) = 0;
      *p_m_nGrowSize = 0;
      p_m_nGrowSize[1] = 0;
      p_m_nGrowSize[2] = 0;
      p_m_nGrowSize += 5;
      --v17;
    }
    while ( v17 >= 0 );
    CSimpleBSPFile::SplitBrushList(
      this,
      pBrushList,
      pNode,
      pFrontChildList: (CBSPBrush *)childLists,
      pBackChildList: (CBSPBrush *)&childLists[1]);
    for ( i = 0; i < pBrushList->m_Size; ++i )
    {
      v20 = pBrushList->m_Memory.m_pMemory[i];
      pBrushListb = (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)v20;
      if ( v20 != nullptr )
      {
        v20->m_Sides.__vftable = (CCopyableUtlVector<CBSPBrushSide>_vtbl *)&CCopyableUtlVector<CBSPBrushSide>::`vftable';
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(this: &v20->m_Sides.CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> >);
        free(pMem: pBrushListb);
      }
      pBrushList->m_Memory.m_pMemory[i] = nullptr;
    }
    m_pChildren = pNode->m_pChildren;
    pBrushList->m_Size = 0;
    v32 = pNode->m_pChildren;
    pBrushListc = 2;
    do
    {
      v22 = (CBSPNode *)operator new(nSize: 0x70u);
      v23 = v22;
      if ( v22 != nullptr )
      {
        v22->m_pParent = nullptr;
        v22->m_ContentsFlags = 0;
        v22->m_nSplitPlaneIndex = -1;
        v22->m_ClippedBrushes.m_Memory.m_pMemory = nullptr;
        v22->m_ClippedBrushes.m_Memory.m_nAllocationCount = 0;
        v22->m_ClippedBrushes.m_Memory.m_nGrowSize = 0;
        v22->m_ClippedBrushes.m_Size = 0;
        v22->m_ClippedBrushes.m_pElements = nullptr;
        v22->m_Faces.m_Memory.m_pMemory = nullptr;
        v22->m_Faces.m_Memory.m_nAllocationCount = 0;
        v22->m_Faces.m_Memory.m_nGrowSize = 0;
        v22->m_Faces.m_Size = 0;
        v22->m_Faces.m_pElements = nullptr;
        v22->m_Portals.m_Memory.m_pMemory = nullptr;
        v22->m_Portals.m_Memory.m_nAllocationCount = 0;
        v22->m_Portals.m_Memory.m_nGrowSize = 0;
        v22->m_Portals.m_Size = 0;
        v22->m_Portals.m_pElements = nullptr;
        v22->m_nClusterIndex = -1;
        v22->m_bEntityCanReach = false;
        v22->m_pChildren[1] = nullptr;
        v22->m_pChildren[0] = nullptr;
        ClearBounds(mins: &v22->m_vMinBounds, maxs: &v22->m_vMaxBounds);
      }
      else
      {
        v23 = nullptr;
      }
      *m_pChildren++ = v23;
      v24 = pBrushListc-- == 1;
      v23->m_pParent = pNode;
    }
    while ( !v24 );
    v25 = v32;
    v26 = childLists;
    for ( allContentsSolid = 2; allContentsSolid != 0; --allContentsSolid )
      CSimpleBSPFile::BuildBSPChildren(this: (CSimpleBSPFile *)unionFlags, pNode: *v25++, pBrushList: v26++);
    v27 = &v31;
    for ( j = 1; j >= 0; --j )
    {
      v27 -= 20;
      *((_DWORD *)v27 + 3) = 0;
      if ( *((int *)v27 + 2) >= 0 )
      {
        if ( *(_DWORD *)v27 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v27);
          *(_DWORD *)v27 = 0;
        }
        *((_DWORD *)v27 + 1) = 0;
      }
      v29 = *(void **)v27;
      *((_DWORD *)v27 + 4) = *(_DWORD *)v27;
      if ( *((int *)v27 + 2) >= 0 )
      {
        if ( v29 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v29);
          *(_DWORD *)v27 = 0;
        }
        *((_DWORD *)v27 + 1) = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411A40
// Name: public: CSimpleBSPFile::~CSimpleBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::~CSimpleBSPFile(CSimpleBSPFile *this)
{
  int i; // edi
  CBSPModel *v3; // ecx
  unsigned __int8 *m_pMemory; // eax
  BSPCluster_t *v5; // eax
  CBSPFace *v6; // eax
  CBSPModel **v7; // eax
  HashedPlane_t *v8; // eax
  CBSPModel *pMem; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this->m_Models.m_Size; ++i )
  {
    v3 = this->m_Models.m_Memory.m_pMemory[i];
    pMem = v3;
    if ( v3 != nullptr )
    {
      CBSPModel::~CBSPModel(this: v3);
      free(pMem);
    }
  }
  this->m_VisibilityData.m_Size = 0;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VisibilityData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VisibilityData.m_Memory.m_pMemory);
      this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_VisibilityData.m_Memory.m_pMemory;
  this->m_VisibilityData.m_pElements = m_pMemory;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Clusters.m_Size = 0;
  if ( this->m_Clusters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Clusters.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Clusters.m_Memory.m_pMemory);
      this->m_Clusters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Clusters.m_Memory.m_pMemory;
  this->m_Clusters.m_pElements = v5;
  if ( this->m_Clusters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_Clusters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Clusters.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(this: &this->m_DisplacementFaces);
  if ( this->m_DisplacementFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DisplacementFaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DisplacementFaces.m_Memory.m_pMemory);
      this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_DisplacementFaces.m_Memory.m_pMemory;
  this->m_DisplacementFaces.m_pElements = v6;
  if ( this->m_DisplacementFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_DisplacementFaces.m_Memory.m_pMemory = nullptr;
    }
    this->m_DisplacementFaces.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Models.m_Size = 0;
  if ( this->m_Models.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Models.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Models.m_Memory.m_pMemory);
      this->m_Models.m_Memory.m_pMemory = nullptr;
    }
    this->m_Models.m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_Models.m_Memory.m_pMemory;
  this->m_Models.m_pElements = v7;
  if ( this->m_Models.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_Models.m_Memory.m_pMemory = nullptr;
    }
    this->m_Models.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  this->m_PlaneHash.m_Planes.m_Size = 0;
  if ( this->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PlaneHash.m_Planes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PlaneHash.m_Planes.m_Memory.m_pMemory);
      this->m_PlaneHash.m_Planes.m_Memory.m_pMemory = nullptr;
    }
    this->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
  this->m_PlaneHash.m_Planes.m_pElements = v8;
  if ( this->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_PlaneHash.m_Planes.m_Memory.m_pMemory = nullptr;
    }
    this->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411C90
// Name: private: void CSimpleBSPFile::CreateBSPBrushList(struct MapBrush_t const __near *,int,bool,bool,class Vector const __near &,class Vector const __near &,class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateBSPBrushList(
        CSimpleBSPFile *this,
        CBSPBrush *pMapBrushes,
        const MapBrush_t *nBrushCount,
        bool bIncludeDetail,
        bool bIncludeStructural,
        Vector *vClipMin,
        const Vector *vClipMax,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBSPBrushList)
{
  const Vector *v8; // esi
  CPlaneHash *p_m_PlaneHash; // edi
  int PlaneIndex; // eax
  float flDistance; // xmm0_4
  int v12; // eax
  CBSPBrush *v14; // ecx
  CBSPBrush *ClippedBrush; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBSPBrush **m_pMemory; // ecx
  int v19; // eax
  CBSPBrush **v20; // edi
  bool v21; // zf
  Vector vNormal; // [esp+10h] [ebp-30h] BYREF
  int nMinPlanes[2]; // [esp+1Ch] [ebp-24h] BYREF
  int nMaxPlanes[2]; // [esp+24h] [ebp-1Ch] BYREF
  CSimpleBSPFile *v25; // [esp+2Ch] [ebp-14h]
  int v26; // [esp+30h] [ebp-10h]
  int v27; // [esp+34h] [ebp-Ch]
  int v28; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]
  const MapBrush_t *pMapBrushesa; // [esp+48h] [ebp+8h]
  const MapBrush_t *nBrushCounta; // [esp+4Ch] [ebp+Ch]

  v8 = vClipMax;
  v28 = (char *)nMaxPlanes - (char *)vClipMax;
  v27 = (char *)vClipMin - (char *)vClipMax;
  v25 = this;
  p_m_PlaneHash = &this->m_PlaneHash;
  v26 = (char *)nMinPlanes - (char *)vClipMax;
  for ( i = 2; i != 0; --i )
  {
    memset(&vNormal, 0, sizeof(vNormal));
    *(float *)((char *)&v8->x + (char *)&vNormal - (char *)vClipMax) = 1.0;
    PlaneIndex = CPlaneHash::FindPlaneIndex(this: p_m_PlaneHash, &vNormal, flDistance: v8->x);
    flDistance = *(float *)((char *)&v8->x + v27);
    *(_DWORD *)((char *)&v8->x + v28) = PlaneIndex;
    v12 = CPlaneHash::FindPlaneIndex(this: p_m_PlaneHash, &vNormal, flDistance);
    *(_DWORD *)((char *)&v8->x + v26) = v12;
    v8 = (const Vector *)((char *)v8 + 4);
  }
  if ( (int)nBrushCount > 0 )
  {
    v14 = pMapBrushes;
    nBrushCounta = (const MapBrush_t *)pMapBrushes;
    pMapBrushesa = nBrushCount;
    do
    {
      if ( bIncludeDetail && (LODWORD(v14->m_vMinBounds.x) & 0x8000000) != 0
        || bIncludeStructural && (LODWORD(v14->m_vMinBounds.x) & 0x8000000) == 0 )
      {
        ClippedBrush = CSimpleBSPFile::CreateClippedBrush(
                         this: v25,
                         pMapBrush: v14,
                         (CBSPBrush *)vClipMin,
                         vClipMax,
                         nClipMinPlanes: nMinPlanes,
                         nClipMaxPlanes: nMaxPlanes);
        if ( ClippedBrush != nullptr )
        {
          m_Size = pBSPBrushList->m_Size;
          m_nAllocationCount = pBSPBrushList->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ColorRGBExp32,int>::Grow(
              this: (CUtlMemory<BSPCluster_t,int> *)pBSPBrushList,
              num: m_Size - m_nAllocationCount + 1);
          ++pBSPBrushList->m_Size;
          m_pMemory = pBSPBrushList->m_Memory.m_pMemory;
          v19 = pBSPBrushList->m_Size - m_Size - 1;
          pBSPBrushList->m_pElements = pBSPBrushList->m_Memory.m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v19);
          v20 = &pBSPBrushList->m_Memory.m_pMemory[m_Size];
          if ( v20 != nullptr )
            *v20 = ClippedBrush;
        }
      }
      v14 = (CBSPBrush *)&nBrushCounta[1];
      v21 = pMapBrushesa == (const MapBrush_t *)1;
      pMapBrushesa = (const MapBrush_t *)((char *)pMapBrushesa - 1);
      ++nBrushCounta;
    }
    while ( !v21 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411DF0
// Name: private: class CBSPTree __near * CSimpleBSPFile::BuildBSPTree(class CUtlVector<class CBSPBrush __near *,class CUtlMemory<class CBSPBrush __near *,int>> __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CBSPTree *__thiscall CSimpleBSPFile::BuildBSPTree(
        CSimpleBSPFile *this,
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *pBrushList,
        const Vector *vMin,
        const Vector *vMax)
{
  CBSPTree *v5; // eax
  CBSPTree *v6; // esi
  CBSPNode *v7; // eax
  CBSPNode *v8; // eax
  int i; // esi
  int v10; // esi
  Vector *p_m_vMaxBounds; // ebx
  CBSPTree *v12; // esi
  Vector vNormal; // [esp+10h] [ebp-14h] BYREF
  CSimpleBSPFile *v15; // [esp+1Ch] [ebp-8h]
  CBSPTree *pTree; // [esp+20h] [ebp-4h]

  v15 = this;
  v5 = (CBSPTree *)operator new(nSize: 0x8Cu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5->m_pRoot = nullptr;
    CBSPNode::CBSPNode(this: &v5->m_OutsideNode);
    ClearBounds(mins: &v6->m_vMinBounds, maxs: &v6->m_vMaxBounds);
    pTree = v6;
  }
  else
  {
    pTree = nullptr;
  }
  v7 = (CBSPNode *)operator new(nSize: 0x70u);
  if ( v7 != nullptr )
    v8 = CBSPNode::CBSPNode(this: v7);
  else
    v8 = nullptr;
  pTree->m_pRoot = v8;
  for ( i = 0; i < 3; ++i )
  {
    vNormal = vec3_origin;
    *((_DWORD *)&vNormal.x + i) = 1065353216;
    CPlaneHash::FindPlaneIndex(
      this: &this->m_PlaneHash,
      &vNormal,
      flDistance: *(float *)((char *)&vNormal.x + 4 * i + (char *)vMax - (char *)&vNormal));
    *((_DWORD *)&vNormal.x + i) = -1082130432;
    CPlaneHash::FindPlaneIndex(
      this: &this->m_PlaneHash,
      &vNormal,
      flDistance: COERCE_FLOAT(*(_DWORD *)((char *)&vNormal.x + 4 * i + (char *)vMin - (char *)&vNormal) ^ _mask__NegFloat_));
  }
  v10 = 0;
  if ( pBrushList->m_Size > 0 )
  {
    p_m_vMaxBounds = &pTree->m_vMaxBounds;
    do
    {
      AddPointToBounds(
        v: &pBrushList->m_Memory.m_pMemory[v10]->m_vMinBounds,
        mins: &pTree->m_vMinBounds,
        maxs: p_m_vMaxBounds);
      AddPointToBounds(
        v: &pBrushList->m_Memory.m_pMemory[v10++]->m_vMaxBounds,
        mins: &pTree->m_vMinBounds,
        maxs: p_m_vMaxBounds);
    }
    while ( v10 < pBrushList->m_Size );
  }
  v12 = pTree;
  CSimpleBSPFile::BuildBSPChildren(this: v15, pNode: pTree->m_pRoot, pBrushList);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00411F50
// Name: private: void CSimpleBSPFile::PopulateTreeWithDetail(class CBSPTree const __near *,int,int,class CUtlVector<class CBSPFace __near *,class CUtlMemory<class CBSPFace __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::PopulateTreeWithDetail(
        CSimpleBSPFile *this,
        const CBSPTree *pTree,
        int nFirstBrush,
        const MapBrush_t *nNumBrushes,
        CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *pDetailFaceList)
{
  const CSimpleMapFile *m_pMapFile; // eax
  __int64 v6; // xmm0_8
  int v7; // esi
  __int64 v8; // xmm0_8
  CBSPBrush **m_pMemory; // ecx
  CBSPBrushSide *v11; // edi
  int v12; // eax
  char *v13; // edi
  CBSPFace *v14; // esi
  int v15; // edi
  int m_nAllocationCount; // eax
  CBSPFace **v17; // ecx
  int v18; // eax
  CBSPFace **v19; // eax
  bool v20; // zf
  CBSPFace *v21; // edi
  CBSPFace **v22; // ecx
  Vector *v23; // eax
  int i; // edi
  CBSPBrush *v25; // [esp-1Ch] [ebp-84h]
  CBSPFace clonedFace; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > detailBrushes; // [esp+34h] [ebp-34h] BYREF
  Vector vClipMin; // [esp+48h] [ebp-20h] BYREF
  Vector vClipMax; // [esp+54h] [ebp-14h] BYREF
  int m_Size; // [esp+60h] [ebp-8h]
  CSimpleBSPFile *v31; // [esp+64h] [ebp-4h]
  int nFirstBrusha; // [esp+74h] [ebp+Ch]
  int j; // [esp+78h] [ebp+10h]
  CBSPBrush **pDetailFaceLista; // [esp+7Ch] [ebp+14h]

  v31 = this;
  m_pMapFile = this->m_pMapFile;
  v6 = *(_QWORD *)&this->m_pMapFile->m_vMaxBounds.x;
  vClipMax.z = this->m_pMapFile->m_vMaxBounds.z;
  vClipMin.z = m_pMapFile->m_vMinBounds.z;
  v7 = 0;
  *(_QWORD *)&vClipMax.x = v6;
  v8 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
  v25 = (CBSPBrush *)&m_pMapFile->m_Brushes.m_Memory.m_pMemory[nFirstBrush];
  memset(&detailBrushes, 0, sizeof(detailBrushes));
  *(_QWORD *)&vClipMin.x = v8;
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: v25,
    nBrushCount: nNumBrushes,
    bIncludeDetail: true,
    bIncludeStructural: false,
    &vClipMin,
    &vClipMax,
    pBSPBrushList: &detailBrushes);
  if ( detailBrushes.m_Size > 0 )
  {
    m_pMemory = detailBrushes.m_Memory.m_pMemory;
    pDetailFaceLista = detailBrushes.m_Memory.m_pMemory;
    m_Size = detailBrushes.m_Size;
    do
    {
      if ( LOBYTE((*m_pMemory)->m_ContentsFlags) != 0 )
      {
        j = 0;
        if ( (*m_pMemory)->m_Sides.m_Size > 0 )
        {
          nFirstBrusha = 0;
          do
          {
            v11 = (*m_pMemory)->m_Sides.m_Memory.m_pMemory;
            v12 = *(int *)((char *)&v11->m_nTextureInfoIndex + v7);
            v13 = (char *)v11 + v7;
            if ( v12 != -1 && SLOBYTE(v31->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[v12].m_SurfaceFlags) >= 0 )
            {
              v14 = (CBSPFace *)operator new(nSize: 0x28u);
              if ( v14 != nullptr )
              {
                v14->m_nTextureInfoIndex = *((_DWORD *)v13 + 1);
                v14->m_nPlaneIndex = *(_DWORD *)v13;
                v14->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
                v14->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
                v14->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
                v14->m_Polygon.m_Points.m_Size = 0;
                v14->m_Polygon.m_Points.m_pElements = nullptr;
                v14->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
                CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
                  this: &v14->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
                  pArray: *((const Vector **)v13 + 4),
                  size: *((_DWORD *)v13 + 7));
                v14->m_nDisplacementIndex = -1;
                v14->m_nSerializedFaceIndex = -1;
              }
              else
              {
                v14 = nullptr;
              }
              v15 = pDetailFaceList->m_Size;
              m_nAllocationCount = pDetailFaceList->m_Memory.m_nAllocationCount;
              if ( v15 + 1 > m_nAllocationCount )
                CUtlMemory<ColorRGBExp32,int>::Grow(
                  this: (CUtlMemory<BSPCluster_t,int> *)pDetailFaceList,
                  num: v15 - m_nAllocationCount + 1);
              ++pDetailFaceList->m_Size;
              v17 = pDetailFaceList->m_Memory.m_pMemory;
              v18 = pDetailFaceList->m_Size - v15 - 1;
              pDetailFaceList->m_pElements = pDetailFaceList->m_Memory.m_pMemory;
              if ( v18 > 0 )
                _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 4 * v18);
              v19 = &pDetailFaceList->m_Memory.m_pMemory[v15];
              if ( v19 != nullptr )
                *v19 = v14;
              SubdivideFaceForLightmaps(
                pMapFile: v31->m_pMapFile,
                pFaceList: (CBSPFace *)pDetailFaceList,
                nOriginalFaceIndex: v15);
              m_pMemory = pDetailFaceLista;
            }
            v7 = nFirstBrusha + 36;
            ++j;
            nFirstBrusha += 36;
          }
          while ( j < (*m_pMemory)->m_Sides.m_Size );
          v7 = 0;
        }
      }
      ++m_pMemory;
      v20 = m_Size-- == 1;
      pDetailFaceLista = m_pMemory;
    }
    while ( !v20 );
  }
  if ( pDetailFaceList->m_Size > 0 )
  {
    do
    {
      v21 = pDetailFaceList->m_Memory.m_pMemory[v7];
      clonedFace.m_nTextureInfoIndex = v21->m_nTextureInfoIndex;
      clonedFace.m_nPlaneIndex = v21->m_nPlaneIndex;
      memset(
        &clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        0,
        sizeof(clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >));
      clonedFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        this: &clonedFace.m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        pArray: v21->m_Polygon.m_Points.m_Memory.m_pMemory,
        size: v21->m_Polygon.m_Points.m_Size);
      v22 = pDetailFaceList->m_Memory.m_pMemory;
      clonedFace.m_nDisplacementIndex = v21->m_nDisplacementIndex;
      clonedFace.m_nSerializedFaceIndex = v21->m_nSerializedFaceIndex;
      CSimpleBSPFile::FilterFaceIntoTree(
        this: v31,
        pNode: pTree->m_pRoot,
        pClippedFace: &clonedFace,
        pOriginalFace: v22[v7]);
      v23 = clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory;
      clonedFace.m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      clonedFace.m_Polygon.m_Points.m_Size = 0;
      if ( clonedFace.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 )
      {
        if ( clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory);
          v23 = nullptr;
          clonedFace.m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        }
        clonedFace.m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
      }
      clonedFace.m_Polygon.m_Points.m_pElements = v23;
      if ( clonedFace.m_Polygon.m_Points.m_Memory.m_nGrowSize >= 0 && v23 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      ++v7;
    }
    while ( v7 < pDetailFaceList->m_Size );
  }
  for ( i = 0; i < detailBrushes.m_Size; ++i )
    CSimpleBSPFile::FilterBrushIntoTree(
      this: v31,
      pNode: (CBSPBrush *)pTree->m_pRoot,
      pBrush: detailBrushes.m_Memory.m_pMemory[i]);
  if ( detailBrushes.m_Memory.m_nGrowSize >= 0 && detailBrushes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: detailBrushes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00412220
// Name: private: void CSimpleBSPFile::ProcessEntity(struct MapEntity_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::ProcessEntity(CSimpleBSPFile *this, const MapEntity_t *pEntity)
{
  CBSPBrush *v3; // edx
  CBSPModel *v4; // eax
  CBSPModel *v5; // esi
  int v6; // ecx
  int m_nAllocationCount; // eax
  CBSPModel **m_pMemory; // edx
  int v9; // eax
  CBSPModel **v10; // ecx
  CBSPTree *v11; // eax
  const MapBrush_t *m_nNumBrushes; // [esp-24h] [ebp-54h]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > brushList; // [esp+0h] [ebp-30h] BYREF
  Vector vMin; // [esp+14h] [ebp-1Ch] BYREF
  Vector vMax; // [esp+20h] [ebp-10h] BYREF
  int m_Size; // [esp+2Ch] [ebp-4h]

  m_nNumBrushes = (const MapBrush_t *)pEntity->m_nNumBrushes;
  v3 = (CBSPBrush *)&this->m_pMapFile->m_Brushes.m_Memory.m_pMemory[pEntity->m_nFirstBrushIndex];
  vMin.x = -16384.0;
  vMin.y = -16384.0;
  vMin.z = -16384.0;
  vMax.x = 16384.0;
  vMax.y = 16384.0;
  vMax.z = 16384.0;
  memset(&brushList, 0, sizeof(brushList));
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: v3,
    nBrushCount: m_nNumBrushes,
    bIncludeDetail: true,
    bIncludeStructural: true,
    vClipMin: &vMin,
    vClipMax: &vMax,
    pBSPBrushList: &brushList);
  v4 = (CBSPModel *)operator new(nSize: 0x44u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_pTree = nullptr;
    v4->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    v4->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
    v4->m_DetailFaces.m_Memory.m_nGrowSize = 0;
    v4->m_DetailFaces.m_Size = 0;
    v4->m_DetailFaces.m_pElements = nullptr;
    v4->m_Portals.m_Memory.m_pMemory = nullptr;
    v4->m_Portals.m_Memory.m_nAllocationCount = 0;
    v4->m_Portals.m_Memory.m_nGrowSize = 0;
    v4->m_Portals.m_Size = 0;
    v4->m_Portals.m_pElements = nullptr;
    ClearBounds(mins: &v4->m_vMinBounds, maxs: &v4->m_vMaxBounds);
  }
  else
  {
    v5 = nullptr;
  }
  m_nAllocationCount = this->m_Models.m_Memory.m_nAllocationCount;
  m_Size = this->m_Models.m_Size;
  v6 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<ColorRGBExp32,int>::Grow(
      this: (CUtlMemory<BSPCluster_t,int> *)&this->m_Models,
      num: m_Size - m_nAllocationCount + 1);
    v6 = m_Size;
  }
  ++this->m_Models.m_Size;
  m_pMemory = this->m_Models.m_Memory.m_pMemory;
  v9 = this->m_Models.m_Size - v6 - 1;
  this->m_Models.m_pElements = m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
    v6 = m_Size;
  }
  v10 = &this->m_Models.m_Memory.m_pMemory[v6];
  if ( v10 != nullptr )
    *v10 = v5;
  v11 = CSimpleBSPFile::BuildBSPTree(this, pBrushList: &brushList, &vMin, &vMax);
  v5->m_pTree = v11;
  CSimpleBSPFile::BuildTreePortals(this, pTree: v11, pPortalList: &v5->m_Portals);
  CSimpleBSPFile::MakeFacesFromPortals(this, pModel: v5);
  CSimpleBSPFile::PruneNodes(this, pNode: v5->m_pTree->m_pRoot, pPortalList: &v5->m_Portals);
  CSimpleBSPFile::NumberPortalFaces(this, pNode: v5->m_pTree->m_pRoot);
  CSimpleBSPFile::PopulateTreeWithDetail(
    this,
    pTree: v5->m_pTree,
    nFirstBrush: pEntity->m_nFirstBrushIndex,
    nNumBrushes: (const MapBrush_t *)pEntity->m_nNumBrushes,
    pDetailFaceList: &v5->m_DetailFaces);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: &brushList);
}

//------------------------------------------------------------------------------
// Address: 0x004123C0
// Name: private: class CBSPNode __near * CSimpleBSPFile::CreateGridNode(int,int)
// Source: json
//------------------------------------------------------------------------------
CBSPNode *__thiscall CSimpleBSPFile::CreateGridNode(CSimpleBSPFile *this, CBSPNode *nX, int nY)
{
  const CSimpleMapFile *m_pMapFile; // eax
  MapEntity_t *m_pMemory; // ecx
  int m_nFirstBrushIndex; // ecx
  MapBrush_t *v7; // edx
  CBSPNode *v8; // eax
  CBSPNode *v9; // esi
  CBSPTree *v11; // esi
  const MapBrush_t *m_nNumBrushes; // [esp-1Ch] [ebp-50h]
  CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > clippedBrushes; // [esp+8h] [ebp-2Ch] BYREF
  Vector vMin; // [esp+1Ch] [ebp-18h] BYREF
  Vector vMax; // [esp+28h] [ebp-Ch] BYREF
  CBSPNode *pNewNode; // [esp+3Ch] [ebp+8h]

  vMin.x = (float)(int)((_DWORD)nX << 10);
  vMin.y = (float)(nY << 10);
  vMin.z = -16384.0;
  m_pMapFile = this->m_pMapFile;
  vMax.x = (float)(((_DWORD)nX << 10) + 1024);
  m_pMemory = m_pMapFile->m_Entities.m_Memory.m_pMemory;
  m_nNumBrushes = (const MapBrush_t *)m_pMemory->m_nNumBrushes;
  m_nFirstBrushIndex = m_pMemory->m_nFirstBrushIndex;
  v7 = m_pMapFile->m_Brushes.m_Memory.m_pMemory;
  vMax.y = (float)((nY << 10) + 1024);
  vMax.z = 16384.0;
  memset(&clippedBrushes, 0, sizeof(clippedBrushes));
  CSimpleBSPFile::CreateBSPBrushList(
    this,
    pMapBrushes: (CBSPBrush *)&v7[m_nFirstBrushIndex],
    nBrushCount: m_nNumBrushes,
    bIncludeDetail: false,
    bIncludeStructural: true,
    vClipMin: &vMin,
    vClipMax: &vMax,
    pBSPBrushList: &clippedBrushes);
  if ( clippedBrushes.m_Size != 0 )
  {
    v11 = CSimpleBSPFile::BuildBSPTree(this, pBrushList: &clippedBrushes, &vMin, &vMax);
    pNewNode = v11->m_pRoot;
    v11->m_pRoot = nullptr;
    CBSPNode::~CBSPNode(this: &v11->m_OutsideNode);
    free(pMem: v11);
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: &clippedBrushes);
    return pNewNode;
  }
  else
  {
    v8 = (CBSPNode *)operator new(nSize: 0x70u);
    if ( v8 != nullptr )
    {
      v9 = CBSPNode::CBSPNode(this: v8);
      v9->m_ContentsFlags = 1;
      CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: &clippedBrushes);
      return v9;
    }
    else
    {
      MEMORY[0x10] = 1;
      CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: &clippedBrushes);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412520
// Name: private: void CSimpleBSPFile::ProcessWorldEntity(struct MapEntity_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::ProcessWorldEntity(CSimpleBSPFile *this, const MapEntity_t *pEntity)
{
  CBSPModel *v3; // eax
  CBSPModel *v4; // esi
  CBSPModel *v5; // ebx
  int v6; // ecx
  int m_nAllocationCount; // eax
  CBSPModel **m_pMemory; // edx
  int v9; // eax
  CBSPModel **v10; // ecx
  CBSPTree *v11; // eax
  CBSPTree *v12; // esi
  const CSimpleMapFile *m_pMapFile; // ecx
  int i; // eax
  __int64 v15; // xmm0_8
  int v16; // esi
  float v17; // esi
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __int64 v23; // xmm0_8
  int v24; // esi
  float v25; // esi
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  int v31; // ecx
  int v32; // eax
  int v33; // esi
  int v34; // esi
  CBSPNode *GridNode; // eax
  CBSPTree *m_pTree; // ecx
  float v37; // eax
  CBSPTree *v38; // ecx
  CBSPNode *ppNodeList[1024]; // [esp+Ch] [ebp-1048h] BYREF
  __int64 v40; // [esp+100Ch] [ebp-48h]
  float v41; // [esp+1014h] [ebp-40h]
  __int64 v42; // [esp+1018h] [ebp-3Ch]
  float v43; // [esp+1020h] [ebp-34h]
  __int64 v44; // [esp+1024h] [ebp-30h]
  float z; // [esp+102Ch] [ebp-28h]
  __int64 v46; // [esp+1030h] [ebp-24h]
  float v47; // [esp+1038h] [ebp-1Ch]
  int nX; // [esp+103Ch] [ebp-18h]
  int m_Size; // [esp+1040h] [ebp-14h]
  int nAbsoluteMaxs; // [esp+1044h] [ebp-10h] BYREF
  int v51; // [esp+1048h] [ebp-Ch]
  int nAbsoluteMins; // [esp+104Ch] [ebp-8h] BYREF
  int nY; // [esp+1050h] [ebp-4h]

  v3 = (CBSPModel *)operator new(nSize: 0x44u);
  v4 = v3;
  v5 = nullptr;
  if ( v3 != nullptr )
  {
    v3->m_pTree = nullptr;
    v3->m_DetailFaces.m_Memory.m_pMemory = nullptr;
    v3->m_DetailFaces.m_Memory.m_nAllocationCount = 0;
    v3->m_DetailFaces.m_Memory.m_nGrowSize = 0;
    v3->m_DetailFaces.m_Size = 0;
    v3->m_DetailFaces.m_pElements = nullptr;
    v3->m_Portals.m_Memory.m_pMemory = nullptr;
    v3->m_Portals.m_Memory.m_nAllocationCount = 0;
    v3->m_Portals.m_Memory.m_nGrowSize = 0;
    v3->m_Portals.m_Size = 0;
    v3->m_Portals.m_pElements = nullptr;
    ClearBounds(mins: &v3->m_vMinBounds, maxs: &v3->m_vMaxBounds);
    v5 = v4;
  }
  m_nAllocationCount = this->m_Models.m_Memory.m_nAllocationCount;
  m_Size = this->m_Models.m_Size;
  v6 = m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
  {
    CUtlMemory<ColorRGBExp32,int>::Grow(
      this: (CUtlMemory<BSPCluster_t,int> *)&this->m_Models,
      num: m_Size - m_nAllocationCount + 1);
    v6 = m_Size;
  }
  ++this->m_Models.m_Size;
  m_pMemory = this->m_Models.m_Memory.m_pMemory;
  v9 = this->m_Models.m_Size - v6 - 1;
  this->m_Models.m_pElements = m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
    v6 = m_Size;
  }
  v10 = &this->m_Models.m_Memory.m_pMemory[v6];
  if ( v10 != nullptr )
    *v10 = v5;
  v11 = (CBSPTree *)operator new(nSize: 0x8Cu);
  v12 = v11;
  if ( v11 != nullptr )
  {
    v11->m_pRoot = nullptr;
    CBSPNode::CBSPNode(this: &v11->m_OutsideNode);
    ClearBounds(mins: &v12->m_vMinBounds, maxs: &v12->m_vMaxBounds);
  }
  else
  {
    v12 = nullptr;
  }
  v5->m_pTree = v12;
  m_pMapFile = this->m_pMapFile;
  nY = -16;
  nAbsoluteMins = -16;
  v51 = 15;
  nAbsoluteMaxs = 15;
  for ( i = 0; i < 8; i += 4 )
  {
    v15 = *(_QWORD *)&m_pMapFile->m_vMaxBounds.x;
    z = m_pMapFile->m_vMaxBounds.z;
    v16 = *(int *)((char *)&nAbsoluteMaxs + i);
    v44 = v15;
    if ( (float)(v16 << 10) > *(float *)((char *)&v44 + i) )
    {
      v17 = m_pMapFile->m_vMaxBounds.z;
      v42 = *(_QWORD *)&m_pMapFile->m_vMaxBounds.x;
      v43 = v17;
      v18 = (__m128)*(unsigned int *)((char *)&v42 + i);
      v18.m128_f32[0] = v18.m128_f32[0] * 0.0009765625;
      v19 = _mm_and_ps((__m128)0x80000000, v18);
      v20.m128_i32[0] = 1258291200;
      v20.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v18, v19), v20).m128_f32[0]) & 0x4B000000
                      | v19.m128_i32[0];
      v21 = v18;
      v21.m128_f32[0] = (float)(v18.m128_f32[0] + v20.m128_f32[0]) - v20.m128_f32[0];
      v22 = v21;
      v22.m128_f32[0] = v21.m128_f32[0] - v18.m128_f32[0];
      *(int *)((char *)&nAbsoluteMaxs + i) = (int)(float)(v21.m128_f32[0]
                                                        - COERCE_FLOAT(_mm_cmpgt_ss(v22, v19).m128_u32[0] & 0x3F800000));
    }
    v23 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
    v41 = m_pMapFile->m_vMinBounds.z;
    v24 = *(int *)((char *)&nAbsoluteMins + i) + 1;
    v40 = v23;
    if ( *(float *)((char *)&v40 + i) > (float)(v24 << 10) )
    {
      v25 = m_pMapFile->m_vMinBounds.z;
      v46 = *(_QWORD *)&m_pMapFile->m_vMinBounds.x;
      v47 = v25;
      v26 = (__m128)*(unsigned int *)((char *)&v46 + i);
      v26.m128_f32[0] = v26.m128_f32[0] * 0.0009765625;
      v27 = _mm_and_ps((__m128)0x80000000, v26);
      v28.m128_i32[0] = 1258291200;
      v28.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v26, v27), v28).m128_f32[0]) & 0x4B000000
                      | v27.m128_i32[0];
      v29 = v26;
      v29.m128_f32[0] = (float)(v26.m128_f32[0] + v28.m128_f32[0]) - v28.m128_f32[0];
      v30 = v29;
      v30.m128_f32[0] = v29.m128_f32[0] - v26.m128_f32[0];
      *(int *)((char *)&nAbsoluteMins + i) = (int)(float)(v29.m128_f32[0]
                                                        - COERCE_FLOAT(_mm_cmpgt_ss(v30, v27).m128_u32[0] & 0x3F800000));
    }
    if ( *(int *)((char *)&nAbsoluteMins + i) < -16 )
      *(int *)((char *)&nAbsoluteMins + i) = -16;
    if ( *(int *)((char *)&nAbsoluteMaxs + i) > 15 )
      *(int *)((char *)&nAbsoluteMaxs + i) = 15;
  }
  memset(ppNodeList, 0, sizeof(ppNodeList));
  v31 = nY;
  v32 = nAbsoluteMins;
  v33 = nAbsoluteMaxs;
  m_Size = nY;
  if ( nY <= v51 )
  {
    do
    {
      nX = v32;
      if ( v32 <= v33 )
      {
        do
        {
          v34 = nX + (v31 - nY) * (v33 - v32 + 1) - v32;
          GridNode = CSimpleBSPFile::CreateGridNode(this, (CBSPNode *)nX, nY: v31);
          v31 = m_Size;
          ppNodeList[v34] = GridNode;
          v33 = nAbsoluteMaxs;
          ++nX;
          v32 = nAbsoluteMins;
        }
        while ( nX <= nAbsoluteMaxs );
      }
      m_Size = ++v31;
    }
    while ( v31 <= v51 );
    v31 = nY;
  }
  v5->m_pTree->m_pRoot = CSimpleBSPFile::GenerateBSPGrid(
                           this,
                           nMinX: v32 - 1,
                           nMinY: v31 - 1,
                           nMaxX: v33 + 1,
                           nMaxY: v51 + 1,
                           &nAbsoluteMins,
                           &nAbsoluteMaxs,
                           ppNodeList);
  v5->m_pTree->m_vMinBounds.x = (float)(nAbsoluteMins << 10);
  v5->m_pTree->m_vMinBounds.y = (float)(nY << 10);
  m_pTree = v5->m_pTree;
  v47 = this->m_pMapFile->m_vMinBounds.z;
  m_pTree->m_vMinBounds.z = v47 - 8.0;
  v5->m_pTree->m_vMaxBounds.x = (float)((nAbsoluteMaxs + 1) << 10);
  v5->m_pTree->m_vMaxBounds.y = (float)((v51 + 1) << 10);
  v37 = this->m_pMapFile->m_vMaxBounds.z;
  v38 = v5->m_pTree;
  v46 = *(_QWORD *)&this->m_pMapFile->m_vMaxBounds.x;
  v47 = v37;
  v38->m_vMaxBounds.z = v37 + 8.0;
  CSimpleBSPFile::BuildTreePortals(this, pTree: v5->m_pTree, pPortalList: &v5->m_Portals);
  CSimpleBSPFile::FloodEntities(this, pTree: v5->m_pTree);
  CSimpleBSPFile::MakeFacesFromPortals(this, pModel: v5);
  CSimpleBSPFile::PruneNodes(this, pNode: v5->m_pTree->m_pRoot, pPortalList: &v5->m_Portals);
  CSimpleBSPFile::NumberPortalFaces(this, pNode: v5->m_pTree->m_pRoot);
  CSimpleBSPFile::PopulateTreeWithDetail(
    this,
    pTree: v5->m_pTree,
    nFirstBrush: this->m_pMapFile->m_Entities.m_Memory.m_pMemory->m_nFirstBrushIndex,
    nNumBrushes: (const MapBrush_t *)this->m_pMapFile->m_Entities.m_Memory.m_pMemory->m_nNumBrushes,
    pDetailFaceList: &v5->m_DetailFaces);
  CSimpleBSPFile::BuildRadialVisibilityData(this, pRootNode: ***(CBSPNode ****)this->m_Models.m_Memory.m_pMemory);
  CSimpleBSPFile::CreateDisplacementFaces(this);
}

//------------------------------------------------------------------------------
// Address: 0x00412980
// Name: public: void CSimpleBSPFile::CreateFromMapFile(class CSimpleMapFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleBSPFile::CreateFromMapFile(CSimpleBSPFile *this, const CSimpleMapFile *pMapFile)
{
  const CSimpleMapFile *v2; // esi
  CSimpleBSPFile *v3; // edi
  CPlaneHash *p_m_PlaneHash; // ebx
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *v5; // eax
  int *m_HashTable; // eax
  int j; // edx
  int v8; // eax
  MapEntity_t *m_pMemory; // edx
  MapEntity_t *v10; // ebx
  CBSPModel *v11; // eax
  int v12; // esi
  const Vector *v13; // edi
  const MapEntity_t *v14; // [esp-4h] [ebp-20h]
  Vector *mins; // [esp+10h] [ebp-Ch]
  Vector *maxs; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v2 = pMapFile;
  v3 = this;
  this->m_pMapFile = pMapFile;
  p_m_PlaneHash = &this->m_PlaneHash;
  if ( pMapFile == (const CSimpleMapFile *)-8 )
    v5 = nullptr;
  else
    v5 = &pMapFile->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
    this: &this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
    other: v5);
  m_HashTable = p_m_PlaneHash->m_HashTable;
  for ( j = 1024; j != 0; --j )
  {
    *m_HashTable = *(int *)((char *)m_HashTable + (char *)&pMapFile->m_PlaneHash - (char *)p_m_PlaneHash);
    ++m_HashTable;
  }
  v8 = 0;
  i = 0;
  if ( pMapFile->m_Entities.m_Size > 0 )
  {
    do
    {
      m_pMemory = v2->m_Entities.m_Memory.m_pMemory;
      v10 = &m_pMemory[v8];
      if ( v10->m_nNumBrushes > 0 )
      {
        v14 = &m_pMemory[v8];
        if ( v8 != 0 )
          CSimpleBSPFile::ProcessEntity(this: v3, pEntity: v14);
        else
          CSimpleBSPFile::ProcessWorldEntity(this: v3, pEntity: v14);
        v11 = v3->m_Models.m_Memory.m_pMemory[v3->m_Models.m_Size - 1];
        v12 = 0;
        if ( v10->m_nNumBrushes > 0 )
        {
          maxs = &v11->m_vMaxBounds;
          mins = &v11->m_vMinBounds;
          do
          {
            v13 = (const Vector *)&v3->m_pMapFile->m_Brushes.m_Memory.m_pMemory[v12 + v10->m_nFirstBrushIndex];
            AddPointToBounds(v: v13 + 1, mins, maxs);
            AddPointToBounds(v: v13 + 2, mins, maxs);
            v3 = this;
            ++v12;
          }
          while ( v12 < v10->m_nNumBrushes );
        }
        v8 = i;
        v2 = pMapFile;
      }
      i = ++v8;
    }
    while ( v8 < v2->m_Entities.m_Size );
  }
}

} // namespace vbsp2
