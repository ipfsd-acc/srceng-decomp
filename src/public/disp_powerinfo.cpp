// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/disp_powerinfo.cpp
// Functions: 8
// ============================================================

#include "public\disp_powerinfo.h"

//------------------------------------------------------------------------------
// Address: 0x1015E440
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x1015E4A0
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015E5B0
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015E8A0
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x1015E8B0
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x1015E8D0
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015E990
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EAD0
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1015E6E0
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x1015E740
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015E850
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015EB40
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x1015EB50
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x1015EB70
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015EC30
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015ED80
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1001C520
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x1001C580
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C690
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C980
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x1001C990
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x1001C9B0
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA70
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CBB0
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100788B0
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x10078910
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078A20
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078D10
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x10078D20
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x10078D40
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078E00
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10078F40
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0040D3B0
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x0040D410
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D520
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D810
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x0040D820
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x0040D840
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D900
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040DA40
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x0042BEF0
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x0042BF50
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (int)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C060
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C350
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x0042C360
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x0042C380
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042C440
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C580
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace vbsp2

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0041DA10
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x0041DA70
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DB80
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DE70
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x0041DE80
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x0041DEA0
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041DF60
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E0A0
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10003E80
// Name: WrapVertIndex
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__usercall WrapVertIndex@<eax>(const CVertIndex *in@<edi>, int sideLength@<esi>, _WORD *a3)
{
  int i; // ecx
  int v4; // eax
  __int16 v5; // dx
  int out[2]; // [esp+4h] [ebp-8h]

  for ( i = 0; i < 2; ++i )
  {
    v4 = *(&in->x + (__int16)i);
    if ( (v4 & 0x8000u) != 0 )
    {
      v4 = sideLength - -(__int16)v4 % sideLength - 1;
LABEL_4:
      out[i] = v4;
      continue;
    }
    if ( (__int16)v4 < sideLength )
      goto LABEL_4;
    out[i] = (__int16)v4 % sideLength;
  }
  v5 = out[1];
  *a3 = out[0];
  a3[1] = v5;
  return (CVertIndex *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x10003EE0
// Name: AddDependency
// Source: json
//------------------------------------------------------------------------------
void __usercall AddDependency(
        const CVertIndex *nodeIndex@<eax>,
        CVertInfo *dependencies,
        const CVertIndex *sideLength,
        const CVertIndex *dependency,
        int iMaxPower,
        int bCheckNeighborDependency)
{
  const CVertIndex *v7; // esi
  int v8; // ecx
  CVertInfo *v9; // ebx
  int v10; // eax
  CVertInfo *v11; // edx
  CVertIndex *p_m_iVert; // eax
  bool v13; // zf
  CVertInfo *v14; // eax
  int v15; // edx
  CVertDependency *m_ReverseDependencies; // ecx
  __int16 y; // cx
  CVertIndex *v18; // eax
  __int16 v19; // dx
  __int16 delta_2; // [esp+Eh] [ebp-Ah]
  int sideLengtha; // [esp+14h] [ebp-4h]

  v7 = sideLength;
  v8 = (1 << (char)dependency) + 1;
  v9 = &dependencies[nodeIndex->x + v8 * nodeIndex->y];
  sideLengtha = v8;
  v10 = 0;
  v11 = v9;
  while ( v11->m_Dependencies[0].m_iVert.x != -1 )
  {
    ++v10;
    v11 = (CVertInfo *)((char *)v11 + 6);
    if ( v10 >= 2 )
    {
      v10 = 0;
      break;
    }
  }
  p_m_iVert = &v9->m_Dependencies[v10].m_iVert;
  *p_m_iVert = *sideLength;
  v13 = (_BYTE)bCheckNeighborDependency == 0;
  p_m_iVert[1].x = -1;
  if ( !v13 )
  {
    v14 = &dependencies[v7->x + v8 * v7->y];
    v15 = 0;
    m_ReverseDependencies = v14->m_ReverseDependencies;
    while ( m_ReverseDependencies->m_iVert.x != -1 )
    {
      ++v15;
      ++m_ReverseDependencies;
      if ( v15 >= 4 )
      {
        v15 = 0;
        break;
      }
    }
    v14->m_ReverseDependencies[v15].m_iVert = *nodeIndex;
    v7 = sideLength;
    v14->m_ReverseDependencies[v15].m_iNeighbor = -1;
  }
  if ( (_BYTE)iMaxPower != 0 )
  {
    iMaxPower = GetEdgeIndexFromPoint(index: nodeIndex, iMaxPower: (char)dependency);
    if ( iMaxPower != -1 )
    {
      y = nodeIndex->y;
      delta_2 = y - v7->y;
      LOWORD(bCheckNeighborDependency) = nodeIndex->x - v7->x + nodeIndex->x;
      HIWORD(bCheckNeighborDependency) = delta_2 + y;
      v18 = WrapVertIndex(in: (const CVertIndex *)&bCheckNeighborDependency, sideLength: sideLengtha, a3: &dependencies);
      v19 = iMaxPower;
      v9->m_Dependencies[1].m_iVert = *v18;
      v9->m_Dependencies[1].m_iNeighbor = v19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FF0
// Name: InitPowerInfo_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo_R(
        CPowerInfo *pPowerInfo,
        int iMaxPower,
        const CVertIndex *nodeIndex,
        const CVertIndex *dependency1,
        const CVertIndex *dependency2,
        const CVertIndex *nodeEdge1,
        const CVertIndex *nodeEdge2,
        const CVertIndex *iParent,
        __int16 *iLevel)
{
  CPowerInfo *v9; // ebx
  const CVertIndex *v10; // edi
  int v11; // eax
  int v12; // ecx
  const CVertIndex *v13; // esi
  __int16 v14; // dx
  int v15; // esi
  __int16 *v16; // ecx
  __int16 v17; // ax
  int v18; // ecx
  CFourVerts *m_pSideVerts; // eax
  int v20; // eax
  int v21; // eax
  const CVertIndex *p_y; // ecx
  __int16 y; // dx
  __int16 v24; // cx
  CFourVerts *m_pChildVerts; // edx
  __int16 x; // ax
  __int16 v27; // cx
  const CVertIndex *v28; // [esp-Ch] [ebp-34h]
  __int16 sideVertCorner1; // [esp+Ch] [ebp-1Ch]
  __int16 sideVertCorner1_2; // [esp+Eh] [ebp-1Ah]
  CVertIndex sideVertCorner0a; // [esp+14h] [ebp-14h]
  int sideVertCorner0; // [esp+14h] [ebp-14h]
  const CVertIndex *v33; // [esp+1Ch] [ebp-Ch]
  int nodeInc; // [esp+20h] [ebp-8h]
  int iSideVert; // [esp+24h] [ebp-4h] BYREF

  v9 = pPowerInfo;
  v10 = nodeIndex;
  nodeInc = (1 << iMaxPower) + 1;
  v11 = nodeIndex->x + nodeInc * nodeIndex->y;
  v12 = v11;
  pPowerInfo->m_pVertInfo[v12].m_iParent = *iParent;
  v9->m_pVertInfo[v12].m_iNodeLevel = (_WORD)iLevel + 1;
  v13 = (const CVertIndex *)iMaxPower;
  iSideVert = v11;
  v28 = (const CVertIndex *)iMaxPower;
  v14 = ((1 << iMaxPower) + 1) * nodeEdge1->y;
  LOWORD(nodeIndex) = (1 << iMaxPower) + 1;
  v9->m_pErrorEdges[v11].m_Values[0] = nodeEdge1->x + v14;
  v9->m_pErrorEdges[v11].m_Values[1] = nodeEdge2->x + (_WORD)nodeIndex * nodeEdge2->y;
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency1,
    dependency: v28,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  AddDependency(
    nodeIndex: v10,
    dependencies: v9->m_pVertInfo,
    sideLength: dependency2,
    dependency: v13,
    iMaxPower: 0,
    bCheckNeighborDependency: 1);
  v15 = 1 << ((_BYTE)v13 - (_BYTE)iLevel - 1);
  v16 = &g_SideVertMul[0][1];
  v33 = (const CVertIndex *)(16 * iSideVert);
  nodeEdge1 = (const CVertIndex *)(16 * iSideVert);
  iParent = (const CVertIndex *)&g_SideVertCorners[0].m_Corner1[1];
  for ( pPowerInfo = (CPowerInfo *)&g_SideVertMul[0][1]; ; v16 = (__int16 *)pPowerInfo )
  {
    v17 = v10->x + v15 * *(v16 - 1);
    HIWORD(nodeEdge2) = v10->y + v15 * *v16;
    v18 = v17 + nodeInc * SHIWORD(nodeEdge2);
    LOWORD(nodeEdge2) = v17;
    m_pSideVerts = v9->m_pSideVerts;
    iSideVert = v18;
    *(CVertIndex *)((char *)m_pSideVerts->m_Verts + (_DWORD)nodeEdge1) = (CVertIndex)nodeEdge2;
    sideVertCorner0a.x = v10->x + v15 * iParent[-1].y;
    sideVertCorner0a.y = v10->y + v15 * iParent->x;
    sideVertCorner1 = v10->x + v15 * iParent->y;
    sideVertCorner1_2 = v10->y + v15 * iParent[1].x;
    *(const CVertIndex *)((char *)nodeEdge1 + (unsigned int)v9->m_pSideVertCorners) = sideVertCorner0a;
    v20 = iSideVert;
    v9->m_pErrorEdges[iSideVert].m_Values[0] = sideVertCorner0a.x + sideVertCorner0a.y * (_WORD)nodeIndex;
    v9->m_pErrorEdges[v20].m_Values[1] = sideVertCorner1 + sideVertCorner1_2 * (_WORD)nodeIndex;
    AddDependency(
      nodeIndex: (const CVertIndex *)&nodeEdge2,
      dependencies: v9->m_pVertInfo,
      sideLength: v10,
      dependency: (const CVertIndex *)iMaxPower,
      iMaxPower: 1,
      bCheckNeighborDependency: 1);
    ++nodeEdge1;
    iParent += 2;
    pPowerInfo = (CPowerInfo *)((char *)pPowerInfo + 4);
    if ( (int)pPowerInfo >= (int)&g_SideVertCorners[0].m_Corner1[1] )
      break;
  }
  v21 = v15 >> 1;
  if ( v15 >> 1 != 0 )
  {
    sideVertCorner0 = (int)iLevel + 1;
    p_y = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    iLevel = &g_ChildNodeDependencies[0][1].y;
    nodeEdge1 = (const CVertIndex *)&g_ChildNodeIndexMul[0].y;
    nodeIndex = v33;
    while ( 1 )
    {
      y = p_y[-1].y;
      v24 = v10->y + v21 * p_y->x;
      LOWORD(nodeEdge2) = v10->x + v21 * y;
      m_pChildVerts = v9->m_pChildVerts;
      HIWORD(nodeEdge2) = v24;
      *(CVertIndex *)((char *)m_pChildVerts->m_Verts + (_DWORD)nodeIndex) = (CVertIndex)nodeEdge2;
      x = v10->x;
      LOWORD(m_pChildVerts) = v15 * nodeEdge1->x;
      LOWORD(pPowerInfo) = v10->x + v15 * nodeEdge1[-1].y;
      v27 = v10->y;
      HIWORD(pPowerInfo) = v27 + (_WORD)m_pChildVerts;
      LOWORD(iParent) = x + v15 * *(iLevel - 1);
      HIWORD(iParent) = v27 + v15 * *iLevel;
      LOWORD(iSideVert) = x + v15 * *(iLevel - 3);
      HIWORD(iSideVert) = v27 + v15 * *(iLevel - 2);
      InitPowerInfo_R(
        pPowerInfo: v9,
        iMaxPower,
        nodeIndex: (const CVertIndex *)&nodeEdge2,
        dependency1: (const CVertIndex *)&iSideVert,
        dependency2: (const CVertIndex *)&iParent,
        nodeEdge1: v10,
        nodeEdge2: (const CVertIndex *)&pPowerInfo,
        iParent: v10,
        iLevel: sideVertCorner0);
      ++nodeIndex;
      iLevel += 4;
      if ( (int)++nodeEdge1 >= (int)&g_ChildNodeDependencies[0][0].y )
        break;
      v21 = v15 >> 1;
      p_y = nodeEdge1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100042E0
// Name: class CPowerInfo const __near * GetPowerInfo(int)
// Source: json
//------------------------------------------------------------------------------
const CPowerInfo *__cdecl GetPowerInfo(int iPower)
{
  return g_PowerInfos[iPower];
}

//------------------------------------------------------------------------------
// Address: 0x100042F0
// Name: public: class CVertIndex const __near & CPowerInfo::GetCornerPointIndex(int)const
// Source: json
//------------------------------------------------------------------------------
const CVertIndex *__thiscall CPowerInfo::GetCornerPointIndex(CPowerInfo *this, int iCorner)
{
  return &this->m_CornerPointIndices[iCorner];
}

//------------------------------------------------------------------------------
// Address: 0x10004310
// Name: public: CVertInfo::CVertInfo(void)
// Source: json
//------------------------------------------------------------------------------
CVertInfo *__thiscall CVertInfo::CVertInfo(CVertInfo *this)
{
  this->m_Dependencies[0].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[0].m_iNeighbor = -1;
  this->m_Dependencies[1].m_iVert = (CVertIndex)-1;
  this->m_Dependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[0].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[0].m_iNeighbor = -1;
  this->m_ReverseDependencies[1].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[1].m_iNeighbor = -1;
  this->m_ReverseDependencies[2].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[2].m_iNeighbor = -1;
  this->m_ReverseDependencies[3].m_iVert = (CVertIndex)-1;
  this->m_ReverseDependencies[3].m_iNeighbor = -1;
  this->m_iParent.y = -1;
  this->m_iParent.x = -1;
  this->m_iNodeLevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100043D0
// Name: InitPowerInfoTriInfos_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfoTriInfos_R(
        CPowerInfo *pInfo,
        const CVertIndex *nodeIndex,
        CTriInfo **pTriInfo,
        int iMaxPower,
        int iLevel)
{
  char v5; // di
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  unsigned __int16 indices; // [esp+Ch] [ebp-14h]
  __int16 sideVert; // [esp+14h] [ebp-Ch]
  __int16 sideVert_2; // [esp+16h] [ebp-Ah]
  int iVert; // [esp+1Ch] [ebp-4h]
  int nodeIndexa; // [esp+2Ch] [ebp+Ch]
  __int16 vertInc; // [esp+34h] [ebp+14h]
  __int16 iLevela; // [esp+38h] [ebp+18h]

  v5 = iMaxPower;
  v6 = nodeIndex->x + nodeIndex->y * ((1 << iMaxPower) + 1);
  v7 = iLevel + 1;
  if ( iLevel + 1 >= iMaxPower )
  {
    v9 = 1 << (iMaxPower - iLevel - 1);
    v10 = 0;
    iVert = 0;
    vertInc = v9;
    if ( g_TWinding.m_nVerts > 0 )
    {
      iLevela = (1 << v5) + 1;
      v11 = 0;
      while ( 1 )
      {
        sideVert = nodeIndex->x + v9 * g_TWinding.m_Verts[v11].m_Index.x;
        sideVert_2 = nodeIndex->y + vertInc * g_TWinding.m_Verts[v11].m_Index.y;
        if ( v10 == 1 )
        {
          (*pTriInfo)->m_Indices[0] = indices;
          (*pTriInfo)->m_Indices[1] = sideVert + sideVert_2 * iLevela;
          (*pTriInfo)->m_Indices[2] = v6;
          ++*pTriInfo;
        }
        ++v11;
        indices = sideVert + sideVert_2 * iLevela;
        v10 = 1;
        if ( ++iVert >= g_TWinding.m_nVerts )
          break;
        LOWORD(v9) = vertInc;
      }
    }
  }
  else
  {
    v8 = 4 * v6;
    nodeIndexa = 4;
    while ( 1 )
    {
      InitPowerInfoTriInfos_R(pInfo, nodeIndex: &pInfo->m_pChildVerts->m_Verts[v8++], pTriInfo, iMaxPower, iLevel: v7);
      if ( --nodeIndexa == 0 )
        break;
      v7 = iLevel + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004510
// Name: void InitPowerInfo(class CPowerInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitPowerInfo(int pInfo, int iMaxPower)
{
  CPowerInfo *v2; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  CTriInfo *m_pTriInfos; // ecx
  int v7; // eax
  __int16 v8; // cx
  __int16 v9; // dx
  __int16 v10; // dx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int *v15; // edx
  int v16; // [esp-2Ch] [ebp-80h]
  int v17; // [esp-20h] [ebp-74h]
  CVertIndex nbStartVert; // [esp+14h] [ebp-40h]
  CVertIndex nbNextVert; // [esp+1Ch] [ebp-38h]
  __int16 v20; // [esp+24h] [ebp-30h]
  int v21; // [esp+2Eh] [ebp-26h]
  int v22; // [esp+34h] [ebp-20h]
  __int16 v23; // [esp+38h] [ebp-1Ch]
  CTriInfo *pTriInfo; // [esp+3Ch] [ebp-18h] BYREF
  CVertIndex nodeEdge2; // [esp+40h] [ebp-14h] BYREF
  CVertIndex nodeEdge1; // [esp+44h] [ebp-10h] BYREF
  CVertIndex nodeDependency2; // [esp+48h] [ebp-Ch] BYREF
  int iEdge; // [esp+4Ch] [ebp-8h] BYREF
  CVertIndex v29; // [esp+50h] [ebp-4h]

  v2 = (CPowerInfo *)pInfo;
  v3 = (1 << iMaxPower) + 1;
  v22 = 1 << iMaxPower;
  nodeDependency2 = 0;
  v4 = 1 << iMaxPower;
  *(_DWORD *)(pInfo + 36) = v3;
  v5 = v3 / 2;
  nodeEdge2.x = v3 / 2;
  nodeEdge2.y = nodeEdge2.x;
  v2->m_RootNode = nodeEdge2;
  v2->m_MaxVerts = v3 * v3;
  v2->m_SideLengthM1 = v3 - 1;
  v2->m_MidPoint = v3 / 2;
  v2->m_CornerPointIndices[0] = 0;
  v2->m_CornerPointIndices[1].x = 0;
  v2->m_CornerPointIndices[1].y = v4;
  v2->m_CornerPointIndices[2].x = v4;
  v2->m_CornerPointIndices[2].y = v4;
  v2->m_CornerPointIndices[3].y = 0;
  pInfo = -1;
  nodeEdge1 = 0;
  v17 = iMaxPower;
  v23 = v4;
  LOWORD(iEdge) = v4;
  HIWORD(iEdge) = v4;
  v2->m_CornerPointIndices[3].x = v4;
  nodeEdge2.x = v4;
  nodeEdge2.y = v4;
  InitPowerInfo_R(
    pPowerInfo: v2,
    iMaxPower: v17,
    nodeIndex: &v2->m_RootNode,
    dependency1: (const CVertIndex *)&iEdge,
    dependency2: &nodeDependency2,
    &nodeEdge1,
    &nodeEdge2,
    iParent: (const CVertIndex *)&pInfo,
    iLevel: nullptr);
  m_pTriInfos = v2->m_pTriInfos;
  v16 = iMaxPower;
  v2->m_Power = iMaxPower;
  pTriInfo = m_pTriInfos;
  InitPowerInfoTriInfos_R(pInfo: v2, nodeIndex: &v2->m_RootNode, &pTriInfo, iMaxPower: v16, iLevel: 0);
  v7 = 0;
  iEdge = 0;
  while ( 1 )
  {
    if ( v7 == 2 )
    {
      v2->m_EdgeStartVerts[2].y = 0;
      v2->m_EdgeStartVerts[2].x = v4;
      v8 = v4;
      v9 = 1;
      goto LABEL_10;
    }
    if ( v7 == 1 )
    {
      v2->m_EdgeStartVerts[1].x = 0;
      v2->m_EdgeStartVerts[1].y = v4;
      v9 = v4;
LABEL_9:
      v8 = 1;
      goto LABEL_10;
    }
    v2->m_EdgeStartVerts[v7] = 0;
    if ( v7 != 0 )
    {
      v9 = 0;
      goto LABEL_9;
    }
    v8 = 0;
    v9 = 1;
LABEL_10:
    v10 = v9 - v2->m_EdgeStartVerts[v7].y;
    LOWORD(pTriInfo) = v8 - v2->m_EdgeStartVerts[v7].x;
    HIWORD(pTriInfo) = v10;
    v2->m_EdgeIncrements[v7] = (CVertIndex)pTriInfo;
    v11 = ((_BYTE)v7 - 2) & 3;
    if ( v11 == 2 )
    {
      nbStartVert.x = v4;
LABEL_12:
      nbStartVert.y = 0;
      goto LABEL_13;
    }
    nbStartVert.x = 0;
    if ( v11 != 1 )
      goto LABEL_12;
    nbStartVert.y = v4;
LABEL_13:
    if ( v11 == 2 )
    {
      nbNextVert.x = v4;
      nbNextVert.y = 1;
    }
    else if ( v11 == 1 )
    {
      nbNextVert.x = 1;
      nbNextVert.y = v4;
    }
    else
    {
      nbNextVert = (CVertIndex)0x10000;
      if ( (((_BYTE)v7 - 2) & 3) != 0 )
        nbNextVert = (CVertIndex)1;
    }
    nodeEdge2.x = nbStartVert.y - v5;
    nodeEdge1 = (CVertIndex)(*(_DWORD *)&nbStartVert - v5);
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][1][1]) * (nbStartVert.y - v5)
                  + LOWORD(g_OrientationRotations[0][1][0]) * (nbStartVert.x - v5);
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[0][0][0]) * (nbStartVert.x - v5)
                  + LOWORD(g_OrientationRotations[0][0][1]) * (nbStartVert.y - v5);
    v2->m_NeighborStartVerts[v7][0] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[0][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[0][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[0][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][0] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[1][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[1][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[1][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][1] = (CVertIndex)pInfo;
    v29.y = LOWORD(g_OrientationRotations[1][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = LOWORD(g_OrientationRotations[1][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[1][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][1] = v29;
    LOWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][0][0]) * nodeEdge1.x
                  + LOWORD(g_OrientationRotations[2][0][1]) * nodeEdge2.x;
    HIWORD(pInfo) = v5
                  + LOWORD(g_OrientationRotations[2][1][1]) * nodeEdge2.x
                  + LOWORD(g_OrientationRotations[2][1][0]) * nodeEdge1.x;
    v2->m_NeighborStartVerts[iEdge][2] = (CVertIndex)pInfo;
    nodeDependency2.x = LOWORD(g_OrientationRotations[2][0][0]) * (nbNextVert.x - nbStartVert.x)
                      + LOWORD(g_OrientationRotations[2][0][1]) * (nbNextVert.y - nbStartVert.y);
    v29.y = LOWORD(g_OrientationRotations[2][1][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[2][1][1]) * (nbNextVert.y - nbStartVert.y);
    v29.x = nodeDependency2.x;
    v2->m_NeighborIncrements[iEdge][2] = v29;
    LOWORD(v21) = nodeEdge2.x;
    v20 = LOWORD(g_OrientationRotations[3][0][0]) * nodeEdge1.x + LOWORD(g_OrientationRotations[3][0][1]) * nodeEdge2.x;
    nodeEdge2 = (CVertIndex)(g_OrientationRotations[3][1][1] * v21);
    LOWORD(pInfo) = v5 + v20;
    HIWORD(pInfo) = v5
                  + nodeEdge1.x * LOWORD(g_OrientationRotations[3][1][0])
                  + LOWORD(g_OrientationRotations[3][1][1]) * v21;
    v2->m_NeighborStartVerts[iEdge][3] = (CVertIndex)pInfo;
    v29.y = (nbNextVert.x - nbStartVert.x) * LOWORD(g_OrientationRotations[3][1][0])
          + LOWORD(g_OrientationRotations[3][1][1]) * (nbNextVert.y - nbStartVert.y);
    v7 = iEdge + 1;
    v29.x = LOWORD(g_OrientationRotations[3][0][0]) * (nbNextVert.x - nbStartVert.x)
          + LOWORD(g_OrientationRotations[3][0][1]) * (nbNextVert.y - nbStartVert.y);
    v2->m_NeighborIncrements[iEdge][3] = v29;
    iEdge = v7;
    if ( v7 >= 4 )
      break;
    LOWORD(v4) = v23;
  }
  v12 = iMaxPower - 1;
  v13 = 0;
  v14 = 1;
  if ( iMaxPower - 1 > 0 )
  {
    v15 = &v2->m_MaxVerts + iMaxPower;
    do
    {
      v13 += v14;
      *v15 = v13;
      v14 *= 4;
      --v15;
      --v12;
    }
    while ( v12 != 0 );
  }
  v2->m_NodeCount = v14 + v13;
  v2->m_nTriInfos = 2 * v22 * v22;
}

} // namespace vrad_dll
