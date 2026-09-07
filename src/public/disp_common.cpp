// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/disp_common.cpp
// Functions: 13
// ============================================================

#include "public\disp_common.h"

//------------------------------------------------------------------------------
// Address: 0x1015CA70
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015CAC0
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x1015CB50
// Name: public: int CDispUtilsHelper::GetPower(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispUtilsHelper::GetPower(CDispUtilsHelper *this)
{
  return *(_DWORD *)(this->GetPowerInfo(this) + 28);
}

//------------------------------------------------------------------------------
// Address: 0x1015CB60
// Name: public: class CVertIndex CDispUtilsHelper::GetEdgeMidPoint(int)const
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__thiscall CDispUtilsHelper::GetEdgeMidPoint(CDispUtilsHelper *this, CVertIndex *result, int iEdge)
{
  int v4; // edi
  int v5; // ecx
  CVertIndex *v6; // eax

  v4 = *(_DWORD *)(this->GetPowerInfo(this) + 36) - 1;
  v5 = *(_DWORD *)(this->GetPowerInfo(this) + 44);
  if ( iEdge != 0 )
  {
    if ( iEdge == 1 )
    {
      result->y = v4;
      result->x = v5;
      return result;
    }
    else if ( iEdge == 2 )
    {
      result->x = v4;
      result->y = v5;
      return result;
    }
    else
    {
      v6 = result;
      if ( iEdge == 3 )
      {
        result->x = v5;
        result->y = 0;
      }
      else
      {
        *result = 0;
      }
    }
  }
  else
  {
    result->x = 0;
    result->y = v5;
    return result;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015CBE0
// Name: FindNeighborCornerVert
// Source: json
//------------------------------------------------------------------------------
int __usercall FindNeighborCornerVert@<eax>(CCoreDispInfo *pDisp@<esi>, const Vector *vecPoint@<edi>)
{
  CPowerInfo *v2; // eax
  int v3; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v9; // [esp-1Ch] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-1Ch]
  float v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  int iClosest; // [esp+0h] [ebp-10h]

  v10 = 0;
  v11 = 1.0e24;
  for ( iClosest = 0; iClosest < 4; ++iClosest )
  {
    v2 = (CPowerInfo *)pDisp->GetPowerInfo(this: pDisp);
    v12 = (int)*CPowerInfo::GetCornerPointIndex(this: v2, iCorner: iClosest);
    v3 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * SHIWORD(v12);
    m_pVerts = pDisp->m_pVerts;
    v5 = (__int16)v12 + v3;
    v6 = m_pVerts[v5].m_Vert.x - vecPoint->x;
    v9 = fsqrt(
           (float)((float)((float)(m_pVerts[v5].m_Vert.y - vecPoint->y) * (float)(m_pVerts[v5].m_Vert.y - vecPoint->y))
                 + (float)(v6 * v6))
         + (float)((float)(m_pVerts[v5].m_Vert.z - vecPoint->z) * (float)(m_pVerts[v5].m_Vert.z - vecPoint->z)));
    v7 = v11;
    if ( v11 > v9 )
    {
      v7 = v9;
      v10 = iClosest;
      v11 = v9;
    }
  }
  if ( v7 > 0.1 )
    return -1;
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1015CCE0
// Name: UpdateTangentSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateTangentSpace(
        const Vector *vNormal@<esi>,
        const Vector *vTanS@<edi>,
        CCoreDispInfo *pDisp,
        const CVertIndex *index)
{
  int v4; // ecx
  CoreDispVert_t *m_pVerts; // eax
  char *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  v4 = index->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * index->y;
  m_pVerts = pDisp->m_pVerts;
  v4 *= 224;
  *(Vector *)((char *)&m_pVerts->m_Normal + v4) = *vNormal;
  v6 = (char *)m_pVerts + v4;
  v7 = vTanS->z * vNormal->x;
  v8 = vTanS->y * vNormal->x;
  v9 = (float)(vTanS->y * vNormal->z) - (float)(vTanS->z * vNormal->y);
  v10 = vTanS->x * vNormal->z;
  v11 = vTanS->x * vNormal->y;
  *(Vector *)(v6 + 76) = *vTanS;
  *((float *)v6 + 22) = v9;
  *((float *)v6 + 23) = v7 - v10;
  *((float *)v6 + 24) = v11 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x1015CD90
// Name: GetAllNeighbors
// Source: json
//------------------------------------------------------------------------------
int __usercall GetAllNeighbors@<eax>(int *iNeighbors@<esi>, CCoreDispInfo *pDisp)
{
  unsigned __int16 *v2; // ebx
  int result; // eax
  unsigned __int8 *p_m_nNeighbors; // ecx
  int i; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = (unsigned __int16 *)pDisp;
  result = 0;
  p_m_nNeighbors = &pDisp->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
  for ( i = 4; i != 0; --i )
  {
    v6 = 0;
    if ( *p_m_nNeighbors != 0 )
    {
      do
      {
        if ( result == 0 )
        {
          *iNeighbors = *(unsigned __int16 *)&p_m_nNeighbors[2 * v6 - 8];
          result = 1;
        }
        ++v6;
      }
      while ( v6 < *p_m_nNeighbors );
      v2 = (unsigned __int16 *)pDisp;
    }
    p_m_nNeighbors += 10;
  }
  v7 = v2[312];
  if ( (_WORD)v7 != 0xFFFF )
    iNeighbors[result++] = v7;
  v8 = v2[315];
  if ( (_WORD)v8 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v8;
  v9 = v2[318];
  if ( (_WORD)v9 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v9;
  v10 = v2[321];
  if ( (_WORD)v10 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v10;
  v11 = v2[324];
  if ( (_WORD)v11 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v11;
  v12 = v2[327];
  if ( (_WORD)v12 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v12;
  v13 = v2[330];
  if ( (_WORD)v13 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v13;
  v14 = v2[333];
  if ( (_WORD)v14 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015CE90
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x1015CFA0
// Name: BlendSubNeighbors
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendSubNeighbors(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // edi
  CDispNeighbor *v5; // eax
  CDispNeighbor *v6; // ebx
  int v7; // eax
  const Vector *p_m_Vert; // edi
  CCoreDispInfo *v9; // ebx
  int NeighborCornerVert; // esi
  CPowerInfo *v11; // eax
  CVertIndex v12; // ecx
  CDispNeighbor *v13; // esi
  int (__thiscall *v14)(CDispNeighbor *); // eax
  CPowerInfo *v15; // eax
  CVertIndex v16; // ecx
  int v17; // edi
  float *v18; // eax
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int v22; // eax
  float v23; // xmm0_4
  int p_m_Normal; // eax
  float v25; // xmm0_4
  int (__thiscall **v26)(CDispNeighbor *); // edx
  float v27; // xmm0_4
  int (__thiscall *v28)(CDispNeighbor *); // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  float v32; // xmm0_4
  int v33; // eax
  float v34; // xmm0_4
  float *v35; // eax
  float v36; // edx
  CCoreDispInfo_vtbl *v37; // eax
  int v38; // eax
  CoreDispVert_t *v39; // edx
  int v40; // ecx
  float v41; // xmm0_4
  int (__thiscall *v42)(CDispNeighbor *); // edx
  int v43; // eax
  int v44; // edx
  int v45; // ecx
  CoreDispVert_t *v46; // edx
  float z; // xmm4_4
  float y; // xmm1_4
  char *v49; // eax
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm5_4
  int v54; // [esp-10h] [ebp-54h]
  int v55; // [esp-10h] [ebp-54h]
  Vector vAvgTanS; // [esp+0h] [ebp-44h] BYREF
  Vector vecAverage; // [esp+Ch] [ebp-38h] BYREF
  int iCorners[2]; // [esp+18h] [ebp-2Ch]
  CVertIndex viCorners[2]; // [esp+20h] [ebp-24h] BYREF
  int v60; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h]
  int iDisp; // [esp+30h] [ebp-14h]
  CVertIndex viMidPoint; // [esp+34h] [ebp-10h] BYREF
  int iEdge; // [esp+38h] [ebp-Ch]
  CDispNeighbor *pEdge; // [esp+3Ch] [ebp-8h]
  CCoreDispInfo *pDisp; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( iDisp = 0; v2 < nListSize; iDisp = v2 )
  {
    v3 = ppListBase[v2];
    pDisp = v3;
    if ( v3 != nullptr )
    {
      v4 = 0;
      iEdge = 0;
      do
      {
        v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
        v6 = v5;
        pEdge = v5;
        if ( v5 != nullptr && v5->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v5->m_SubNeighbors[1].m_iNeighbor != 0xFFFF )
        {
          CDispUtilsHelper::GetEdgeMidPoint(this: v3, result: &viMidPoint, iEdge: v4);
          v7 = v3->GetPowerInfo(this: v3);
          p_m_Vert = &v3->m_pVerts[viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y].m_Vert;
          x = 224 * (viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y);
          v9 = ppListBase[v6->m_SubNeighbors[0].m_iNeighbor];
          pEdge = (CDispNeighbor *)ppListBase[pEdge->m_SubNeighbors[1].m_iNeighbor];
          iCorners[0] = FindNeighborCornerVert(pDisp: v9, vecPoint: p_m_Vert);
          NeighborCornerVert = FindNeighborCornerVert(pDisp: (CCoreDispInfo *)pEdge, vecPoint: p_m_Vert);
          if ( iCorners[0] != -1 && NeighborCornerVert != -1 )
          {
            v54 = iCorners[0];
            v11 = (CPowerInfo *)v9->GetPowerInfo(this: v9);
            v12 = *CPowerInfo::GetCornerPointIndex(this: v11, iCorner: v54);
            v55 = NeighborCornerVert;
            v13 = pEdge;
            v14 = **(int (__thiscall ***)(CDispNeighbor *))&pEdge->m_SubNeighbors[0].m_iNeighbor;
            viCorners[0] = v12;
            v15 = (CPowerInfo *)v14(a1: pEdge);
            v16 = *CPowerInfo::GetCornerPointIndex(this: v15, iCorner: v55);
            v17 = x;
            v18 = (float *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            viCorners[1] = v16;
            vecAverage.x = *v18;
            vecAverage.y = v18[1];
            v19 = v9->__vftable;
            vecAverage.z = v18[2];
            v20 = (int)v19->GetPowerInfo(this: v9);
            m_pVerts = v9->m_pVerts;
            v22 = viCorners[0].x + viCorners[0].y * *(_DWORD *)(v20 + 36);
            v23 = m_pVerts[v22].m_Normal.x + vecAverage.x;
            p_m_Normal = (int)&m_pVerts[v22].m_Normal;
            vecAverage.x = v23;
            v25 = *(float *)(p_m_Normal + 4) + vecAverage.y;
            x = viCorners[0].x;
            v26 = *(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            vecAverage.y = v25;
            v27 = *(float *)(p_m_Normal + 8) + vecAverage.z;
            v28 = *v26;
            vecAverage.z = v27;
            v29 = v28(a1: v13);
            v30 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v31 = 224 * (viCorners[1].x + viCorners[1].y * *(_DWORD *)(v29 + 36));
            v32 = *(float *)(v31 + v30 + 64) + vecAverage.x;
            v33 = v31 + v30 + 64;
            vecAverage.x = v32;
            v34 = *(float *)(v33 + 4) + vecAverage.y;
            v60 = viCorners[1].x;
            vecAverage.y = v34;
            vecAverage.z = *(float *)(v33 + 8) + vecAverage.z;
            VectorNormalize(vec: &vecAverage);
            v35 = (float *)((char *)&pDisp->m_pVerts->m_TangentS.x + v17);
            vAvgTanS.x = *v35;
            vAvgTanS.y = v35[1];
            v36 = v35[2];
            v37 = v9->__vftable;
            vAvgTanS.z = v36;
            v38 = (int)v37->GetPowerInfo(this: v9);
            v39 = v9->m_pVerts;
            v40 = x + viCorners[0].y * *(_DWORD *)(v38 + 36);
            vAvgTanS.x = v39[v40].m_TangentS.x + vAvgTanS.x;
            vAvgTanS.y = v39[v40].m_TangentS.y + vAvgTanS.y;
            v41 = v39[v40].m_TangentS.z + vAvgTanS.z;
            v42 = **(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            vAvgTanS.z = v41;
            v43 = v42(a1: v13);
            v44 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v45 = 224 * (v60 + viCorners[1].y * *(_DWORD *)(v43 + 36));
            vAvgTanS.x = vAvgTanS.x + *(float *)(v45 + v44 + 76);
            vAvgTanS.y = *(float *)(v45 + v44 + 80) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v45 + v44 + 84) + vAvgTanS.z;
            VectorNormalize(vec: &vAvgTanS);
            v46 = pDisp->m_pVerts;
            *(Vector *)((char *)&v46->m_Normal + v17) = vecAverage;
            z = vecAverage.z;
            y = vecAverage.y;
            v49 = (char *)v46 + v17;
            v50 = vAvgTanS.y * vecAverage.x;
            v51 = vAvgTanS.z * vecAverage.x;
            v52 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
            v53 = vAvgTanS.x;
            *(Vector *)(v49 + 76) = vAvgTanS;
            *((float *)v49 + 22) = v52;
            *((float *)v49 + 23) = v51 - (float)(z * v53);
            *((float *)v49 + 24) = (float)(y * v53) - v50;
            UpdateTangentSpace(vNormal: &vecAverage, vTanS: &vAvgTanS, pDisp: v9, index: viCorners);
            UpdateTangentSpace(
              vNormal: &vecAverage,
              vTanS: &vAvgTanS,
              pDisp: (CCoreDispInfo *)pEdge,
              index: &viCorners[1]);
          }
          v3 = pDisp;
          v4 = iEdge;
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      v2 = iDisp;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D340
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D500
// Name: BlendEdges
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendEdges(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // ebx
  CDispNeighbor *v5; // eax
  int v6; // ecx
  int m_iNeighbor; // eax
  CCoreDispInfo *v8; // ebx
  __int16 x; // ax
  CVertIndex m_Index; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int y; // edi
  int p_m_Normal; // edx
  CCoreDispInfo_vtbl *v16; // eax
  int v17; // eax
  CoreDispVert_t *m_pVerts; // ecx
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v24; // eax
  CCoreDispInfo_vtbl *v25; // edx
  int v26; // eax
  CoreDispVert_t *v27; // edx
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  int v31; // eax
  CCoreDispInfo_vtbl *v32; // edx
  int v33; // eax
  float z; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  int v40; // eax
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // ecx
  int v50; // edx
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  int v55; // eax
  float *p_x; // edi
  int v57; // eax
  CoreDispVert_t *v58; // edx
  int v59; // ecx
  int v60; // eax
  float *v61; // edi
  int v62; // eax
  CoreDispVert_t *v63; // edx
  int v64; // ecx
  int v65; // eax
  int v66; // edi
  CCoreDispInfo_vtbl *v67; // edx
  int v68; // eax
  int v69; // ecx
  CoreDispVert_t *v70; // eax
  int v71; // ecx
  CoreDispVert_t *v72; // eax
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  CVertIndex v79; // ecx
  int iCurPos; // [esp+4h] [ebp-94h]
  CVertIndex *v81; // [esp+8h] [ebp-90h]
  _WORD *v82; // [esp+Ch] [ebp-8Ch]
  float v83; // [esp+10h] [ebp-88h]
  __int16 v84; // [esp+14h] [ebp-84h]
  float v85; // [esp+18h] [ebp-80h]
  CVertIndex *v86; // [esp+1Ch] [ebp-7Ch]
  Vector vec; // [esp+20h] [ebp-78h] BYREF
  int iSubEdge; // [esp+2Ch] [ebp-6Ch]
  int iDisp; // [esp+30h] [ebp-68h]
  int iEdgeDim; // [esp+34h] [ebp-64h]
  CDispNeighbor *v91; // [esp+38h] [ebp-60h]
  int v92; // [esp+3Ch] [ebp-5Ch]
  Vector vecNormal; // [esp+40h] [ebp-58h] BYREF
  int iTween; // [esp+4Ch] [ebp-4Ch]
  CVertIndex viTween; // [esp+50h] [ebp-48h] BYREF
  int iEdge; // [esp+54h] [ebp-44h]
  Vector vAvgTanS; // [esp+58h] [ebp-40h] BYREF
  float flPercent; // [esp+64h] [ebp-34h]
  Vector vecAverage; // [esp+68h] [ebp-30h] BYREF
  CVertIndex viPrevPos; // [esp+74h] [ebp-24h]
  Vector *p_m_TangentS; // [esp+78h] [ebp-20h]
  CDispSubEdgeIterator it; // [esp+7Ch] [ebp-1Ch] BYREF

  v2 = 0;
  iDisp = 0;
  if ( nListSize <= 0 )
    return;
  do
  {
    v3 = ppListBase[v2];
    if ( v3 == nullptr )
      goto LABEL_30;
    v4 = 0;
    iEdge = 0;
    do
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
      if ( v5 == nullptr )
        goto LABEL_28;
      v6 = 0;
      iSubEdge = 0;
      v91 = v5;
      do
      {
        m_iNeighbor = v5->m_SubNeighbors[0].m_iNeighbor;
        if ( (_WORD)m_iNeighbor != 0xFFFF )
        {
          v8 = ppListBase[m_iNeighbor];
          if ( v8 != nullptr )
          {
            iEdgeDim = g_EdgeDims[iEdge];
            it.m_Inc.x = 0;
            it.m_Index.x = 0;
            it.m_pNeighbor = nullptr;
            it.m_End = 0;
            it.m_FreeDim = 0;
            it.m_pNeighbor = SetupEdgeIncrements(
                               pDisp: v3,
                               iEdge,
                               iSub: v6,
                               myIndex: &it.m_Index,
                               myInc: &it.m_Inc,
                               nbIndex: &it.m_NBIndex,
                               nbInc: &it.m_NBInc,
                               myEnd: &it.m_End,
                               iFreeDim: &it.m_FreeDim);
            if ( it.m_pNeighbor != nullptr )
            {
              it.m_Index.y -= it.m_Inc.y;
              it.m_NBIndex.x -= it.m_NBInc.x;
              x = it.m_Inc.x;
              it.m_Index.x -= it.m_Inc.x;
              it.m_NBIndex.y -= it.m_NBInc.y;
              it.m_End += *(&it.m_Inc.x + SLOWORD(it.m_FreeDim));
            }
            else
            {
              it.m_Index.x = 0;
              it.m_End = 0;
              it.m_Inc.x = 0;
              it.m_FreeDim = 0;
              x = 0;
            }
            it.m_Index.y += it.m_Inc.y;
            it.m_Index.x += x;
            it.m_NBIndex.x += it.m_NBInc.x;
            m_Index = it.m_Index;
            it.m_Index.x += x;
            it.m_Index.y += it.m_Inc.y;
            it.m_NBIndex.y += it.m_NBInc.y + it.m_NBInc.y;
            viPrevPos = m_Index;
            it.m_NBIndex.x += it.m_NBInc.x;
            v11 = 2 * SLOWORD(it.m_FreeDim);
            v81 = (CVertIndex *)((char *)&it.m_Index + v11);
            v12 = *(__int16 *)((char *)&it.m_Index.x + v11);
            if ( v12 < it.m_End )
            {
              v86 = (CVertIndex *)((char *)&it.m_Inc + v11);
              v92 = 2 * (iEdgeDim == 0);
              while ( 1 )
              {
                if ( v12 + v86->x < it.m_End )
                {
                  v13 = v8->GetPowerInfo(this: v8);
                  y = it.m_NBIndex.y;
                  p_m_Normal = (int)&v8->m_pVerts[it.m_NBIndex.x + it.m_NBIndex.y * *(_DWORD *)(v13 + 36)].m_Normal;
                  v16 = v3->__vftable;
                  p_m_TangentS = (Vector *)p_m_Normal;
                  v17 = (int)v16->GetPowerInfo(this: v3);
                  m_pVerts = v3->m_pVerts;
                  v19 = v8->__vftable;
                  v20 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v17 + 36);
                  v21 = m_pVerts[v20].m_Normal.x;
                  v22 = (int)&m_pVerts[v20].m_Normal;
                  vecAverage.x = v21 + p_m_TangentS->x;
                  vecAverage.y = *(float *)(v22 + 4) + p_m_TangentS->y;
                  GetPowerInfo = v19->GetPowerInfo;
                  vecAverage.z = *(float *)(v22 + 8) + p_m_TangentS->z;
                  v24 = (int)GetPowerInfo(this: v8);
                  v25 = v3->__vftable;
                  p_m_TangentS = &v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v24 + 36)].m_TangentS;
                  v26 = (int)v25->GetPowerInfo(this: v3);
                  v27 = v3->m_pVerts;
                  v28 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v26 + 36);
                  v29 = p_m_TangentS->x + v27[v28].m_TangentS.x;
                  v30 = (int)&v27[v28].m_TangentS;
                  vAvgTanS.x = v29;
                  vAvgTanS.y = *(float *)(v30 + 4) + p_m_TangentS->y;
                  vAvgTanS.z = *(float *)(v30 + 8) + p_m_TangentS->z;
                  VectorNormalize(vec: &vecAverage);
                  VectorNormalize(vec: &vAvgTanS);
                  v31 = v3->GetPowerInfo(this: v3);
                  v32 = v8->__vftable;
                  v33 = (int)&v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v31 + 36)];
                  *(Vector *)(v33 + 64) = vecAverage;
                  z = vecAverage.z;
                  v35 = vecAverage.y;
                  v36 = vAvgTanS.y * vecAverage.x;
                  v37 = vAvgTanS.z * vecAverage.x;
                  v38 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v39 = vAvgTanS.x;
                  *(Vector *)(v33 + 76) = vAvgTanS;
                  *(float *)(v33 + 88) = v38;
                  *(float *)(v33 + 92) = v37 - (float)(z * v39);
                  *(float *)(v33 + 96) = (float)(v35 * v39) - v36;
                  v40 = (int)v32->GetPowerInfo(this: v8);
                  v41 = (int)&v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v40 + 36)];
                  *(Vector *)(v41 + 64) = vecAverage;
                  v42 = vecAverage.z;
                  v43 = vecAverage.y;
                  v44 = vAvgTanS.y * vecAverage.x;
                  v45 = vAvgTanS.z * vecAverage.x;
                  v46 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v47 = vAvgTanS.x;
                  *(Vector *)(v41 + 76) = vAvgTanS;
                  *(float *)(v41 + 88) = v46;
                  *(float *)(v41 + 92) = v45 - (float)(v42 * v47);
                  *(float *)(v41 + 96) = (float)(v43 * v47) - v44;
                }
                v48 = *(__int16 *)((char *)&viPrevPos.x + v92);
                v49 = *(__int16 *)((char *)&it.m_Index.x + v92);
                v50 = v48 + 1;
                iCurPos = v49;
                iTween = v48 + 1;
                if ( v48 + 1 < v49 )
                  break;
LABEL_25:
                v79 = it.m_Index;
                it.m_Index.x += it.m_Inc.x;
                it.m_Index.y += it.m_Inc.y;
                it.m_NBIndex.y += it.m_NBInc.y;
                viPrevPos = v79;
                it.m_NBIndex.x += it.m_NBInc.x;
                v12 = v81->x;
                if ( v12 >= it.m_End )
                  goto LABEL_26;
              }
              v51 = (float)v48;
              p_m_TangentS = (Vector *)viPrevPos.x;
              v52 = (float)v49;
              v85 = (float)v48;
              v83 = (float)v49;
              v82 = (_WORD *)&viTween + (__int16)iEdgeDim;
              v84 = *(&it.m_Index.x + (__int16)iEdgeDim);
              while ( 1 )
              {
                v53 = (float)v50;
                if ( v51 == v52 )
                {
                  if ( (float)(v53 - v52) < 0.0 )
                  {
                    flPercent = 0.0;
                    goto LABEL_24;
                  }
                  v54 = 1.0;
                }
                else
                {
                  v54 = (float)(v53 - v51) / (float)(v52 - v51);
                }
                flPercent = v54;
LABEL_24:
                v55 = v3->GetPowerInfo(this: v3);
                p_x = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v55 + 36)].m_Normal.x;
                v57 = v3->GetPowerInfo(this: v3);
                v58 = v3->m_pVerts;
                v59 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v57 + 36);
                vecNormal.x = (float)((float)(*p_x - v58[v59].m_Normal.x) * flPercent) + v58[v59].m_Normal.x;
                vecNormal.y = (float)((float)(p_x[1] - v58[v59].m_Normal.y) * flPercent) + v58[v59].m_Normal.y;
                vecNormal.z = (float)((float)(p_x[2] - v58[v59].m_Normal.z) * flPercent) + v58[v59].m_Normal.z;
                VectorNormalize(vec: &vecNormal);
                v60 = v3->GetPowerInfo(this: v3);
                v61 = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v60 + 36)].m_TangentS.x;
                v62 = v3->GetPowerInfo(this: v3);
                v63 = v3->m_pVerts;
                v64 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v62 + 36);
                vec.x = (float)((float)(*v61 - v63[v64].m_TangentS.x) * flPercent) + v63[v64].m_TangentS.x;
                vec.y = (float)((float)(v61[1] - v63[v64].m_TangentS.y) * flPercent) + v63[v64].m_TangentS.y;
                vec.z = (float)((float)(v61[2] - v63[v64].m_TangentS.z) * flPercent) + v63[v64].m_TangentS.z;
                VectorNormalize(&vec);
                v65 = v92;
                v66 = iTween;
                *v82 = v84;
                v67 = v3->__vftable;
                *(__int16 *)((char *)&viTween.x + v65) = v66;
                v68 = (int)v67->GetPowerInfo(this: v3);
                v69 = *(_DWORD *)(v68 + 36) * viTween.y;
                v70 = v3->m_pVerts;
                v71 = viTween.x + v69;
                v70[v71].m_Normal.x = vecNormal.x;
                v70[v71].m_Normal.y = vecNormal.y;
                v72 = &v70[v71];
                v72->m_Normal.z = vecNormal.z;
                v73 = vecNormal.z;
                v74 = vecNormal.y;
                v75 = vec.y * vecNormal.x;
                v76 = vec.z * vecNormal.x;
                v77 = (float)(vec.y * vecNormal.z) - (float)(vec.z * vecNormal.y);
                v78 = vec.x;
                v72->m_TangentS = vec;
                v72->m_TangentT.x = v77;
                v72->m_TangentT.y = v76 - (float)(v73 * v78);
                v72->m_TangentT.z = (float)(v74 * v78) - v75;
                iTween = v66 + 1;
                if ( v66 + 1 >= iCurPos )
                  goto LABEL_25;
                v52 = v83;
                v51 = v85;
                v50 = iTween;
              }
            }
          }
        }
LABEL_26:
        v6 = iSubEdge + 1;
        v5 = (CDispNeighbor *)&v91->m_SubNeighbors[1];
        iSubEdge = v6;
        v91 = (CDispNeighbor *)((char *)v91 + 6);
      }
      while ( v6 < 2 );
      v4 = iEdge;
LABEL_28:
      iEdge = ++v4;
    }
    while ( v4 < 4 );
    v2 = iDisp;
LABEL_30:
    iDisp = ++v2;
  }
  while ( v2 < nListSize );
}

//------------------------------------------------------------------------------
// Address: 0x1015DC60
// Name: BlendCorners
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendCorners(CCoreDispInfo **ppListBase, int nListSize)
{
  int *m_pMemory; // ebx
  CCoreDispInfo *v3; // edi
  int AllNeighbors; // esi
  int m_Size; // eax
  int *v6; // eax
  CPowerInfo *v7; // eax
  CVertIndex v8; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v10; // eax
  int v11; // ebx
  CoreDispVert_t *v12; // eax
  float z; // edx
  Vector *p_m_TangentS; // eax
  CVertIndex v15; // eax
  CCoreDispInfo *v16; // esi
  int NeighborCornerVert; // eax
  CPowerInfo *v18; // eax
  CVertIndex v19; // edi
  const CPowerInfo *(__thiscall *v20)(struct CCoreDispInfo *); // eax
  int v21; // eax
  int v22; // ecx
  CoreDispVert_t *m_pVerts; // edx
  CoreDispVert_t *v24; // eax
  float v25; // xmm0_4
  int v26; // eax
  float v27; // xmm3_4
  float y; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  float x; // xmm5_4
  float *p_x; // ebx
  int v34; // edx
  int *v35; // ecx
  int v36; // eax
  int v37; // eax
  CoreDispVert_t *v38; // esi
  float v39; // xmm3_4
  float v40; // xmm0_4
  CoreDispVert_t *v41; // eax
  float v42; // xmm1_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm5_4
  int v46; // eax
  int v47; // eax
  CoreDispVert_t *v48; // esi
  float v49; // xmm3_4
  float v50; // xmm0_4
  CoreDispVert_t *v51; // eax
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm2_4
  float v55; // xmm5_4
  int v56; // eax
  CoreDispVert_t *v57; // esi
  float v58; // xmm3_4
  float v59; // xmm0_4
  CoreDispVert_t *v60; // eax
  float v61; // xmm1_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm5_4
  int v65; // eax
  CoreDispVert_t *v66; // eax
  float v67; // xmm3_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  float v72; // xmm5_4
  CVertIndex v73; // ebx
  int *v74; // ecx
  int v75; // eax
  CoreDispVert_t *v76; // edx
  float v77; // xmm3_4
  float v78; // xmm0_4
  CoreDispVert_t *v79; // eax
  float v80; // xmm1_4
  float v81; // xmm4_4
  float v82; // xmm2_4
  float v83; // xmm5_4
  int v84; // [esp-Ch] [ebp-860h]
  int v85; // [esp-Ch] [ebp-860h]
  int iNeighbors[512]; // [esp+4h] [ebp-850h] BYREF
  CCoreDispInfo *pDisp; // [esp+804h] [ebp-50h]
  const Vector *vCornerVert; // [esp+808h] [ebp-4Ch]
  CVertIndex viNBCornerVert; // [esp+80Ch] [ebp-48h]
  int iCorner; // [esp+810h] [ebp-44h]
  int iDisp; // [esp+814h] [ebp-40h]
  CUtlVector<int,CUtlMemory<int,int> > nbCornerVerts; // [esp+818h] [ebp-3Ch] BYREF
  int *v93; // [esp+82Ch] [ebp-28h]
  int nNeighbors; // [esp+830h] [ebp-24h]
  int v95; // [esp+834h] [ebp-20h]
  CVertIndex cornerVert; // [esp+838h] [ebp-1Ch]
  Vector vAvgTanS; // [esp+83Ch] [ebp-18h] BYREF
  Vector vAverage; // [esp+848h] [ebp-Ch] BYREF

  m_pMemory = nullptr;
  memset(&nbCornerVerts, 0, sizeof(nbCornerVerts));
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    pDisp = ppListBase[iDisp];
    v3 = pDisp;
    AllNeighbors = GetAllNeighbors(iNeighbors, pDisp);
    m_Size = 0;
    nNeighbors = AllNeighbors;
    nbCornerVerts.m_Size = 0;
    if ( nbCornerVerts.m_Memory.m_nAllocationCount < AllNeighbors && nbCornerVerts.m_Memory.m_nGrowSize >= 0 )
    {
      nbCornerVerts.m_Memory.m_nAllocationCount = AllNeighbors;
      if ( m_pMemory != nullptr )
        v6 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 4 * AllNeighbors);
      else
        v6 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * AllNeighbors);
      nbCornerVerts.m_Memory.m_pMemory = v6;
      m_Size = nbCornerVerts.m_Size;
      m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
    }
    nbCornerVerts.m_pElements = m_pMemory;
    if ( AllNeighbors != 0 )
    {
      if ( AllNeighbors > nbCornerVerts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&nbCornerVerts,
          num: AllNeighbors - nbCornerVerts.m_Memory.m_nAllocationCount);
        m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
        m_Size = nbCornerVerts.m_Size;
      }
      nbCornerVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && AllNeighbors > 0 )
        _V_memmove(dest: &m_pMemory[AllNeighbors], src: m_pMemory, count: 4 * m_Size);
    }
    for ( iCorner = 0; iCorner < 4; ++iCorner )
    {
      v84 = iCorner;
      v7 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
      v8 = *CPowerInfo::GetCornerPointIndex(this: v7, iCorner: v84);
      GetPowerInfo = v3->GetPowerInfo;
      cornerVert = v8;
      v10 = (int)GetPowerInfo(this: v3);
      v11 = cornerVert.x + *(_DWORD *)(v10 + 36) * cornerVert.y;
      v12 = &v3->m_pVerts[v11];
      vAverage.x = v12->m_Normal.x;
      vCornerVert = &v12->m_Vert;
      vAverage.y = v12->m_Normal.y;
      z = v12->m_Normal.z;
      p_m_TangentS = &v3->m_pVerts[v11].m_TangentS;
      vAverage.z = z;
      vAvgTanS = *p_m_TangentS;
      if ( AllNeighbors > 0 )
      {
        v15 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v93 = nbCornerVerts.m_Memory.m_pMemory;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = AllNeighbors;
        while ( 1 )
        {
          v16 = ppListBase[*(int *)((char *)v93 + *(_DWORD *)&v15)];
          NeighborCornerVert = FindNeighborCornerVert(pDisp: v16, vecPoint: vCornerVert);
          if ( NeighborCornerVert == -1 )
          {
            *v93 = -1;
          }
          else
          {
            v85 = NeighborCornerVert;
            v18 = (CPowerInfo *)v16->GetPowerInfo(this: v16);
            v19 = *CPowerInfo::GetCornerPointIndex(this: v18, iCorner: v85);
            v20 = v16->GetPowerInfo;
            viNBCornerVert = v19;
            v21 = (int)v20(this: v16);
            v22 = v19.x + *(_DWORD *)(v21 + 36) * viNBCornerVert.y;
            *v93 = v22;
            v22 *= 224;
            m_pVerts = v16->m_pVerts;
            vAverage.x = *(float *)((char *)&m_pVerts->m_Normal.x + v22) + vAverage.x;
            vAverage.y = *(float *)((char *)&m_pVerts->m_Normal.y + v22) + vAverage.y;
            vAverage.z = *(float *)((char *)&m_pVerts->m_Normal.z + v22) + vAverage.z;
            v24 = v16->m_pVerts;
            v25 = *(float *)((char *)&v24->m_TangentS.x + v22) + vAvgTanS.x;
            v26 = (int)&v24->m_TangentS + v22;
            vAvgTanS.x = v25;
            vAvgTanS.y = *(float *)(v26 + 4) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v26 + 8) + vAvgTanS.z;
          }
          ++v93;
          if ( --v95 == 0 )
            break;
          v15 = cornerVert;
        }
        AllNeighbors = nNeighbors;
        v3 = pDisp;
      }
      VectorNormalize(vec: &vAverage);
      VectorNormalize(vec: &vAvgTanS);
      v3->m_pVerts[v11].m_Normal = vAverage;
      v27 = vAverage.z;
      y = vAverage.y;
      v29 = vAvgTanS.z * vAverage.x;
      v30 = vAvgTanS.y * vAverage.x;
      v31 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
      x = vAvgTanS.x;
      v3->m_pVerts[v11].m_TangentS = vAvgTanS;
      p_x = &v3->m_pVerts[v11].m_TangentT.x;
      v34 = 0;
      *p_x = v31;
      p_x[1] = v29 - (float)(v27 * x);
      p_x[2] = (float)(y * x) - v30;
      if ( AllNeighbors >= 4 )
      {
        v35 = nbCornerVerts.m_Memory.m_pMemory + 2;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        viNBCornerVert = (CVertIndex)((char *)&iNeighbors[1] - (char *)nbCornerVerts.m_Memory.m_pMemory);
        do
        {
          v36 = *(v35 - 2);
          if ( v36 != -1 )
          {
            v37 = v36;
            v38 = ppListBase[iNeighbors[v34]]->m_pVerts;
            v38[v37].m_Normal = vAverage;
            v39 = vAverage.z;
            v40 = vAverage.y;
            v41 = &v38[v37];
            AllNeighbors = nNeighbors;
            v42 = vAvgTanS.z * vAverage.x;
            v43 = vAvgTanS.y * vAverage.x;
            v44 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v45 = vAvgTanS.x;
            v41->m_TangentS = vAvgTanS;
            v41->m_TangentT.x = v44;
            v41->m_TangentT.y = v42 - (float)(v39 * v45);
            v41->m_TangentT.z = (float)(v40 * v45) - v43;
          }
          v46 = *(v35 - 1);
          if ( v46 != -1 )
          {
            v47 = v46;
            v48 = ppListBase[iNeighbors[v34 + 1]]->m_pVerts;
            v48[v47].m_Normal = vAverage;
            v49 = vAverage.z;
            v50 = vAverage.y;
            v51 = &v48[v47];
            AllNeighbors = nNeighbors;
            v52 = vAvgTanS.z * vAverage.x;
            v53 = vAvgTanS.y * vAverage.x;
            v54 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v55 = vAvgTanS.x;
            v51->m_TangentS = vAvgTanS;
            v51->m_TangentT.x = v54;
            v51->m_TangentT.y = v52 - (float)(v49 * v55);
            v51->m_TangentT.z = (float)(v50 * v55) - v53;
          }
          if ( *v35 != -1 )
          {
            v56 = *v35;
            v57 = ppListBase[*(int *)((char *)v35 + *(_DWORD *)&cornerVert)]->m_pVerts;
            v57[v56].m_Normal = vAverage;
            v58 = vAverage.z;
            v59 = vAverage.y;
            v60 = &v57[v56];
            AllNeighbors = nNeighbors;
            v61 = vAvgTanS.z * vAverage.x;
            v62 = vAvgTanS.y * vAverage.x;
            v63 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v64 = vAvgTanS.x;
            v60->m_TangentS = vAvgTanS;
            v60->m_TangentT.x = v63;
            v60->m_TangentT.y = v61 - (float)(v58 * v64);
            v60->m_TangentT.z = (float)(v59 * v64) - v62;
          }
          v65 = v35[1];
          if ( v65 != -1 )
          {
            v66 = &ppListBase[*(int *)((char *)v35 + *(_DWORD *)&viNBCornerVert)]->m_pVerts[v65];
            AllNeighbors = nNeighbors;
            v66->m_Normal = vAverage;
            v67 = vAverage.z;
            v68 = vAverage.y;
            v69 = vAvgTanS.z * vAverage.x;
            v70 = vAvgTanS.y * vAverage.x;
            v71 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v72 = vAvgTanS.x;
            v66->m_TangentS = vAvgTanS;
            v66->m_TangentT.x = v71;
            v66->m_TangentT.y = v69 - (float)(v67 * v72);
            v66->m_TangentT.z = (float)(v68 * v72) - v70;
          }
          v34 += 4;
          v35 += 4;
        }
        while ( v34 < AllNeighbors - 3 );
      }
      if ( v34 < AllNeighbors )
      {
        v73 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v74 = &nbCornerVerts.m_Memory.m_pMemory[v34];
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = AllNeighbors - v34;
        do
        {
          if ( *v74 != -1 )
          {
            v75 = *v74;
            v76 = ppListBase[*(int *)((char *)v74 + *(_DWORD *)&v73)]->m_pVerts;
            v76[v75].m_Normal.x = vAverage.x;
            v73 = cornerVert;
            v76[v75].m_Normal.y = vAverage.y;
            v76[v75].m_Normal.z = vAverage.z;
            v77 = vAverage.z;
            v78 = vAverage.y;
            v79 = &v76[v75];
            v80 = vAvgTanS.z * vAverage.x;
            v81 = vAvgTanS.y * vAverage.x;
            v82 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v83 = vAvgTanS.x;
            v79->m_TangentS = vAvgTanS;
            v79->m_TangentT.x = v82;
            v79->m_TangentT.y = v80 - (float)(v77 * v83);
            v79->m_TangentT.z = (float)(v78 * v83) - v81;
          }
          ++v74;
          --v95;
        }
        while ( v95 != 0 );
      }
    }
    m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
  }
  if ( nbCornerVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015E3D0
// Name: void SmoothDispSurfNormals(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmoothDispSurfNormals(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // esi

  for ( i = 0; i < nListSize; ++i )
    CCoreDispInfo::SetDispUtilsHelperInfo(this: ppListBase[i], ppListBase, listSize: nListSize);
  BlendSubNeighbors(ppListBase, nListSize);
  BlendCorners(ppListBase, nListSize);
  BlendEdges(ppListBase, nListSize);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1015CD10
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015CD60
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x1015CDF0
// Name: public: int CDispUtilsHelper::GetPower(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispUtilsHelper::GetPower(CDispUtilsHelper *this)
{
  return *(_DWORD *)(this->GetPowerInfo(this) + 28);
}

//------------------------------------------------------------------------------
// Address: 0x1015CE00
// Name: public: class CVertIndex CDispUtilsHelper::GetEdgeMidPoint(int)const
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__thiscall CDispUtilsHelper::GetEdgeMidPoint(CDispUtilsHelper *this, CVertIndex *result, int iEdge)
{
  int v4; // edi
  int v5; // ecx
  CVertIndex *v6; // eax

  v4 = *(_DWORD *)(this->GetPowerInfo(this) + 36) - 1;
  v5 = *(_DWORD *)(this->GetPowerInfo(this) + 44);
  if ( iEdge != 0 )
  {
    if ( iEdge == 1 )
    {
      result->y = v4;
      result->x = v5;
      return result;
    }
    else if ( iEdge == 2 )
    {
      result->x = v4;
      result->y = v5;
      return result;
    }
    else
    {
      v6 = result;
      if ( iEdge == 3 )
      {
        result->x = v5;
        result->y = 0;
      }
      else
      {
        *result = 0;
      }
    }
  }
  else
  {
    result->x = 0;
    result->y = v5;
    return result;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1015CE80
// Name: FindNeighborCornerVert
// Source: json
//------------------------------------------------------------------------------
int __usercall FindNeighborCornerVert@<eax>(CCoreDispInfo *pDisp@<esi>, const Vector *vecPoint@<edi>)
{
  CPowerInfo *v2; // eax
  int v3; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v9; // [esp-1Ch] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-1Ch]
  float v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  int iClosest; // [esp+0h] [ebp-10h]

  v10 = 0;
  v11 = 1.0e24;
  for ( iClosest = 0; iClosest < 4; ++iClosest )
  {
    v2 = (CPowerInfo *)pDisp->GetPowerInfo(this: pDisp);
    v12 = (int)*CPowerInfo::GetCornerPointIndex(this: v2, iCorner: iClosest);
    v3 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * SHIWORD(v12);
    m_pVerts = pDisp->m_pVerts;
    v5 = (__int16)v12 + v3;
    v6 = m_pVerts[v5].m_Vert.x - vecPoint->x;
    v9 = fsqrt(
           (float)((float)((float)(m_pVerts[v5].m_Vert.y - vecPoint->y) * (float)(m_pVerts[v5].m_Vert.y - vecPoint->y))
                 + (float)(v6 * v6))
         + (float)((float)(m_pVerts[v5].m_Vert.z - vecPoint->z) * (float)(m_pVerts[v5].m_Vert.z - vecPoint->z)));
    v7 = v11;
    if ( v11 > v9 )
    {
      v7 = v9;
      v10 = iClosest;
      v11 = v9;
    }
  }
  if ( v7 > 0.1 )
    return -1;
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1015CF80
// Name: UpdateTangentSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateTangentSpace(
        const Vector *vNormal@<esi>,
        const Vector *vTanS@<edi>,
        CCoreDispInfo *pDisp,
        const CVertIndex *index)
{
  int v4; // ecx
  CoreDispVert_t *m_pVerts; // eax
  char *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  v4 = index->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * index->y;
  m_pVerts = pDisp->m_pVerts;
  v4 *= 224;
  *(Vector *)((char *)&m_pVerts->m_Normal + v4) = *vNormal;
  v6 = (char *)m_pVerts + v4;
  v7 = vTanS->z * vNormal->x;
  v8 = vTanS->y * vNormal->x;
  v9 = (float)(vTanS->y * vNormal->z) - (float)(vTanS->z * vNormal->y);
  v10 = vTanS->x * vNormal->z;
  v11 = vTanS->x * vNormal->y;
  *(Vector *)(v6 + 76) = *vTanS;
  *((float *)v6 + 22) = v9;
  *((float *)v6 + 23) = v7 - v10;
  *((float *)v6 + 24) = v11 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x1015D030
// Name: GetAllNeighbors
// Source: json
//------------------------------------------------------------------------------
int __usercall GetAllNeighbors@<eax>(int *iNeighbors@<esi>, CCoreDispInfo *pDisp)
{
  unsigned __int16 *v2; // ebx
  int result; // eax
  unsigned __int8 *p_m_nNeighbors; // ecx
  int i; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = (unsigned __int16 *)pDisp;
  result = 0;
  p_m_nNeighbors = &pDisp->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
  for ( i = 4; i != 0; --i )
  {
    v6 = 0;
    if ( *p_m_nNeighbors != 0 )
    {
      do
      {
        if ( result == 0 )
        {
          *iNeighbors = *(unsigned __int16 *)&p_m_nNeighbors[2 * v6 - 8];
          result = 1;
        }
        ++v6;
      }
      while ( v6 < *p_m_nNeighbors );
      v2 = (unsigned __int16 *)pDisp;
    }
    p_m_nNeighbors += 10;
  }
  v7 = v2[312];
  if ( (_WORD)v7 != 0xFFFF )
    iNeighbors[result++] = v7;
  v8 = v2[315];
  if ( (_WORD)v8 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v8;
  v9 = v2[318];
  if ( (_WORD)v9 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v9;
  v10 = v2[321];
  if ( (_WORD)v10 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v10;
  v11 = v2[324];
  if ( (_WORD)v11 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v11;
  v12 = v2[327];
  if ( (_WORD)v12 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v12;
  v13 = v2[330];
  if ( (_WORD)v13 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v13;
  v14 = v2[333];
  if ( (_WORD)v14 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D130
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x1015D240
// Name: BlendSubNeighbors
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendSubNeighbors(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // edi
  CDispNeighbor *v5; // eax
  CDispNeighbor *v6; // ebx
  int v7; // eax
  const Vector *p_m_Vert; // edi
  CCoreDispInfo *v9; // ebx
  int NeighborCornerVert; // esi
  CPowerInfo *v11; // eax
  CVertIndex v12; // ecx
  CDispNeighbor *v13; // esi
  int (__thiscall *v14)(CDispNeighbor *); // eax
  CPowerInfo *v15; // eax
  CVertIndex v16; // ecx
  int v17; // edi
  float *v18; // eax
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int v22; // eax
  float v23; // xmm0_4
  int p_m_Normal; // eax
  float v25; // xmm0_4
  int (__thiscall **v26)(CDispNeighbor *); // edx
  float v27; // xmm0_4
  int (__thiscall *v28)(CDispNeighbor *); // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  float v32; // xmm0_4
  int v33; // eax
  float v34; // xmm0_4
  float *v35; // eax
  float v36; // edx
  CCoreDispInfo_vtbl *v37; // eax
  int v38; // eax
  CoreDispVert_t *v39; // edx
  int v40; // ecx
  float v41; // xmm0_4
  int (__thiscall *v42)(CDispNeighbor *); // edx
  int v43; // eax
  int v44; // edx
  int v45; // ecx
  CoreDispVert_t *v46; // edx
  float z; // xmm4_4
  float y; // xmm1_4
  char *v49; // eax
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm2_4
  float v53; // xmm5_4
  int v54; // [esp-10h] [ebp-54h]
  int v55; // [esp-10h] [ebp-54h]
  Vector vAvgTanS; // [esp+0h] [ebp-44h] BYREF
  Vector vecAverage; // [esp+Ch] [ebp-38h] BYREF
  int iCorners[2]; // [esp+18h] [ebp-2Ch]
  CVertIndex viCorners[2]; // [esp+20h] [ebp-24h] BYREF
  int v60; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h]
  int iDisp; // [esp+30h] [ebp-14h]
  CVertIndex viMidPoint; // [esp+34h] [ebp-10h] BYREF
  int iEdge; // [esp+38h] [ebp-Ch]
  CDispNeighbor *pEdge; // [esp+3Ch] [ebp-8h]
  CCoreDispInfo *pDisp; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( iDisp = 0; v2 < nListSize; iDisp = v2 )
  {
    v3 = ppListBase[v2];
    pDisp = v3;
    if ( v3 != nullptr )
    {
      v4 = 0;
      iEdge = 0;
      do
      {
        v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
        v6 = v5;
        pEdge = v5;
        if ( v5 != nullptr && v5->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v5->m_SubNeighbors[1].m_iNeighbor != 0xFFFF )
        {
          CDispUtilsHelper::GetEdgeMidPoint(this: v3, result: &viMidPoint, iEdge: v4);
          v7 = v3->GetPowerInfo(this: v3);
          p_m_Vert = &v3->m_pVerts[viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y].m_Vert;
          x = 224 * (viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y);
          v9 = ppListBase[v6->m_SubNeighbors[0].m_iNeighbor];
          pEdge = (CDispNeighbor *)ppListBase[pEdge->m_SubNeighbors[1].m_iNeighbor];
          iCorners[0] = FindNeighborCornerVert(pDisp: v9, vecPoint: p_m_Vert);
          NeighborCornerVert = FindNeighborCornerVert(pDisp: (CCoreDispInfo *)pEdge, vecPoint: p_m_Vert);
          if ( iCorners[0] != -1 && NeighborCornerVert != -1 )
          {
            v54 = iCorners[0];
            v11 = (CPowerInfo *)v9->GetPowerInfo(this: v9);
            v12 = *CPowerInfo::GetCornerPointIndex(this: v11, iCorner: v54);
            v55 = NeighborCornerVert;
            v13 = pEdge;
            v14 = **(int (__thiscall ***)(CDispNeighbor *))&pEdge->m_SubNeighbors[0].m_iNeighbor;
            viCorners[0] = v12;
            v15 = (CPowerInfo *)v14(a1: pEdge);
            v16 = *CPowerInfo::GetCornerPointIndex(this: v15, iCorner: v55);
            v17 = x;
            v18 = (float *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            viCorners[1] = v16;
            vecAverage.x = *v18;
            vecAverage.y = v18[1];
            v19 = v9->__vftable;
            vecAverage.z = v18[2];
            v20 = (int)v19->GetPowerInfo(this: v9);
            m_pVerts = v9->m_pVerts;
            v22 = viCorners[0].x + viCorners[0].y * *(_DWORD *)(v20 + 36);
            v23 = m_pVerts[v22].m_Normal.x + vecAverage.x;
            p_m_Normal = (int)&m_pVerts[v22].m_Normal;
            vecAverage.x = v23;
            v25 = *(float *)(p_m_Normal + 4) + vecAverage.y;
            x = viCorners[0].x;
            v26 = *(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            vecAverage.y = v25;
            v27 = *(float *)(p_m_Normal + 8) + vecAverage.z;
            v28 = *v26;
            vecAverage.z = v27;
            v29 = v28(a1: v13);
            v30 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v31 = 224 * (viCorners[1].x + viCorners[1].y * *(_DWORD *)(v29 + 36));
            v32 = *(float *)(v31 + v30 + 64) + vecAverage.x;
            v33 = v31 + v30 + 64;
            vecAverage.x = v32;
            v34 = *(float *)(v33 + 4) + vecAverage.y;
            v60 = viCorners[1].x;
            vecAverage.y = v34;
            vecAverage.z = *(float *)(v33 + 8) + vecAverage.z;
            VectorNormalize(vec: &vecAverage);
            v35 = (float *)((char *)&pDisp->m_pVerts->m_TangentS.x + v17);
            vAvgTanS.x = *v35;
            vAvgTanS.y = v35[1];
            v36 = v35[2];
            v37 = v9->__vftable;
            vAvgTanS.z = v36;
            v38 = (int)v37->GetPowerInfo(this: v9);
            v39 = v9->m_pVerts;
            v40 = x + viCorners[0].y * *(_DWORD *)(v38 + 36);
            vAvgTanS.x = v39[v40].m_TangentS.x + vAvgTanS.x;
            vAvgTanS.y = v39[v40].m_TangentS.y + vAvgTanS.y;
            v41 = v39[v40].m_TangentS.z + vAvgTanS.z;
            v42 = **(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            vAvgTanS.z = v41;
            v43 = v42(a1: v13);
            v44 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v45 = 224 * (v60 + viCorners[1].y * *(_DWORD *)(v43 + 36));
            vAvgTanS.x = vAvgTanS.x + *(float *)(v45 + v44 + 76);
            vAvgTanS.y = *(float *)(v45 + v44 + 80) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v45 + v44 + 84) + vAvgTanS.z;
            VectorNormalize(vec: &vAvgTanS);
            v46 = pDisp->m_pVerts;
            *(Vector *)((char *)&v46->m_Normal + v17) = vecAverage;
            z = vecAverage.z;
            y = vecAverage.y;
            v49 = (char *)v46 + v17;
            v50 = vAvgTanS.y * vecAverage.x;
            v51 = vAvgTanS.z * vecAverage.x;
            v52 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
            v53 = vAvgTanS.x;
            *(Vector *)(v49 + 76) = vAvgTanS;
            *((float *)v49 + 22) = v52;
            *((float *)v49 + 23) = v51 - (float)(z * v53);
            *((float *)v49 + 24) = (float)(y * v53) - v50;
            UpdateTangentSpace(vNormal: &vecAverage, vTanS: &vAvgTanS, pDisp: v9, index: viCorners);
            UpdateTangentSpace(
              vNormal: &vecAverage,
              vTanS: &vAvgTanS,
              pDisp: (CCoreDispInfo *)pEdge,
              index: &viCorners[1]);
          }
          v3 = pDisp;
          v4 = iEdge;
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      v2 = iDisp;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D5E0
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D7A0
// Name: BlendEdges
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendEdges(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // ebx
  CDispNeighbor *v5; // eax
  int v6; // ecx
  int m_iNeighbor; // eax
  CCoreDispInfo *v8; // ebx
  __int16 x; // ax
  CVertIndex m_Index; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int y; // edi
  int p_m_Normal; // edx
  CCoreDispInfo_vtbl *v16; // eax
  int v17; // eax
  CoreDispVert_t *m_pVerts; // ecx
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v24; // eax
  CCoreDispInfo_vtbl *v25; // edx
  int v26; // eax
  CoreDispVert_t *v27; // edx
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  int v31; // eax
  CCoreDispInfo_vtbl *v32; // edx
  int v33; // eax
  float z; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  int v40; // eax
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // ecx
  int v50; // edx
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  int v55; // eax
  float *p_x; // edi
  int v57; // eax
  CoreDispVert_t *v58; // edx
  int v59; // ecx
  int v60; // eax
  float *v61; // edi
  int v62; // eax
  CoreDispVert_t *v63; // edx
  int v64; // ecx
  int v65; // eax
  int v66; // edi
  CCoreDispInfo_vtbl *v67; // edx
  int v68; // eax
  int v69; // ecx
  CoreDispVert_t *v70; // eax
  int v71; // ecx
  CoreDispVert_t *v72; // eax
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  CVertIndex v79; // ecx
  int iCurPos; // [esp+4h] [ebp-94h]
  CVertIndex *v81; // [esp+8h] [ebp-90h]
  _WORD *v82; // [esp+Ch] [ebp-8Ch]
  float v83; // [esp+10h] [ebp-88h]
  __int16 v84; // [esp+14h] [ebp-84h]
  float v85; // [esp+18h] [ebp-80h]
  CVertIndex *v86; // [esp+1Ch] [ebp-7Ch]
  Vector vec; // [esp+20h] [ebp-78h] BYREF
  int iSubEdge; // [esp+2Ch] [ebp-6Ch]
  int iDisp; // [esp+30h] [ebp-68h]
  int iEdgeDim; // [esp+34h] [ebp-64h]
  CDispNeighbor *v91; // [esp+38h] [ebp-60h]
  int v92; // [esp+3Ch] [ebp-5Ch]
  Vector vecNormal; // [esp+40h] [ebp-58h] BYREF
  int iTween; // [esp+4Ch] [ebp-4Ch]
  CVertIndex viTween; // [esp+50h] [ebp-48h] BYREF
  int iEdge; // [esp+54h] [ebp-44h]
  Vector vAvgTanS; // [esp+58h] [ebp-40h] BYREF
  float flPercent; // [esp+64h] [ebp-34h]
  Vector vecAverage; // [esp+68h] [ebp-30h] BYREF
  CVertIndex viPrevPos; // [esp+74h] [ebp-24h]
  Vector *p_m_TangentS; // [esp+78h] [ebp-20h]
  CDispSubEdgeIterator it; // [esp+7Ch] [ebp-1Ch] BYREF

  v2 = 0;
  iDisp = 0;
  if ( nListSize <= 0 )
    return;
  do
  {
    v3 = ppListBase[v2];
    if ( v3 == nullptr )
      goto LABEL_30;
    v4 = 0;
    iEdge = 0;
    do
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
      if ( v5 == nullptr )
        goto LABEL_28;
      v6 = 0;
      iSubEdge = 0;
      v91 = v5;
      do
      {
        m_iNeighbor = v5->m_SubNeighbors[0].m_iNeighbor;
        if ( (_WORD)m_iNeighbor != 0xFFFF )
        {
          v8 = ppListBase[m_iNeighbor];
          if ( v8 != nullptr )
          {
            iEdgeDim = g_EdgeDims[iEdge];
            it.m_Inc.x = 0;
            it.m_Index.x = 0;
            it.m_pNeighbor = nullptr;
            it.m_End = 0;
            it.m_FreeDim = 0;
            it.m_pNeighbor = SetupEdgeIncrements(
                               pDisp: v3,
                               iEdge,
                               iSub: v6,
                               myIndex: &it.m_Index,
                               myInc: &it.m_Inc,
                               nbIndex: &it.m_NBIndex,
                               nbInc: &it.m_NBInc,
                               myEnd: &it.m_End,
                               iFreeDim: &it.m_FreeDim);
            if ( it.m_pNeighbor != nullptr )
            {
              it.m_Index.y -= it.m_Inc.y;
              it.m_NBIndex.x -= it.m_NBInc.x;
              x = it.m_Inc.x;
              it.m_Index.x -= it.m_Inc.x;
              it.m_NBIndex.y -= it.m_NBInc.y;
              it.m_End += *(&it.m_Inc.x + SLOWORD(it.m_FreeDim));
            }
            else
            {
              it.m_Index.x = 0;
              it.m_End = 0;
              it.m_Inc.x = 0;
              it.m_FreeDim = 0;
              x = 0;
            }
            it.m_Index.y += it.m_Inc.y;
            it.m_Index.x += x;
            it.m_NBIndex.x += it.m_NBInc.x;
            m_Index = it.m_Index;
            it.m_Index.x += x;
            it.m_Index.y += it.m_Inc.y;
            it.m_NBIndex.y += it.m_NBInc.y + it.m_NBInc.y;
            viPrevPos = m_Index;
            it.m_NBIndex.x += it.m_NBInc.x;
            v11 = 2 * SLOWORD(it.m_FreeDim);
            v81 = (CVertIndex *)((char *)&it.m_Index + v11);
            v12 = *(__int16 *)((char *)&it.m_Index.x + v11);
            if ( v12 < it.m_End )
            {
              v86 = (CVertIndex *)((char *)&it.m_Inc + v11);
              v92 = 2 * (iEdgeDim == 0);
              while ( 1 )
              {
                if ( v12 + v86->x < it.m_End )
                {
                  v13 = v8->GetPowerInfo(this: v8);
                  y = it.m_NBIndex.y;
                  p_m_Normal = (int)&v8->m_pVerts[it.m_NBIndex.x + it.m_NBIndex.y * *(_DWORD *)(v13 + 36)].m_Normal;
                  v16 = v3->__vftable;
                  p_m_TangentS = (Vector *)p_m_Normal;
                  v17 = (int)v16->GetPowerInfo(this: v3);
                  m_pVerts = v3->m_pVerts;
                  v19 = v8->__vftable;
                  v20 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v17 + 36);
                  v21 = m_pVerts[v20].m_Normal.x;
                  v22 = (int)&m_pVerts[v20].m_Normal;
                  vecAverage.x = v21 + p_m_TangentS->x;
                  vecAverage.y = *(float *)(v22 + 4) + p_m_TangentS->y;
                  GetPowerInfo = v19->GetPowerInfo;
                  vecAverage.z = *(float *)(v22 + 8) + p_m_TangentS->z;
                  v24 = (int)GetPowerInfo(this: v8);
                  v25 = v3->__vftable;
                  p_m_TangentS = &v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v24 + 36)].m_TangentS;
                  v26 = (int)v25->GetPowerInfo(this: v3);
                  v27 = v3->m_pVerts;
                  v28 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v26 + 36);
                  v29 = p_m_TangentS->x + v27[v28].m_TangentS.x;
                  v30 = (int)&v27[v28].m_TangentS;
                  vAvgTanS.x = v29;
                  vAvgTanS.y = *(float *)(v30 + 4) + p_m_TangentS->y;
                  vAvgTanS.z = *(float *)(v30 + 8) + p_m_TangentS->z;
                  VectorNormalize(vec: &vecAverage);
                  VectorNormalize(vec: &vAvgTanS);
                  v31 = v3->GetPowerInfo(this: v3);
                  v32 = v8->__vftable;
                  v33 = (int)&v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v31 + 36)];
                  *(Vector *)(v33 + 64) = vecAverage;
                  z = vecAverage.z;
                  v35 = vecAverage.y;
                  v36 = vAvgTanS.y * vecAverage.x;
                  v37 = vAvgTanS.z * vecAverage.x;
                  v38 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v39 = vAvgTanS.x;
                  *(Vector *)(v33 + 76) = vAvgTanS;
                  *(float *)(v33 + 88) = v38;
                  *(float *)(v33 + 92) = v37 - (float)(z * v39);
                  *(float *)(v33 + 96) = (float)(v35 * v39) - v36;
                  v40 = (int)v32->GetPowerInfo(this: v8);
                  v41 = (int)&v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v40 + 36)];
                  *(Vector *)(v41 + 64) = vecAverage;
                  v42 = vecAverage.z;
                  v43 = vecAverage.y;
                  v44 = vAvgTanS.y * vecAverage.x;
                  v45 = vAvgTanS.z * vecAverage.x;
                  v46 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v47 = vAvgTanS.x;
                  *(Vector *)(v41 + 76) = vAvgTanS;
                  *(float *)(v41 + 88) = v46;
                  *(float *)(v41 + 92) = v45 - (float)(v42 * v47);
                  *(float *)(v41 + 96) = (float)(v43 * v47) - v44;
                }
                v48 = *(__int16 *)((char *)&viPrevPos.x + v92);
                v49 = *(__int16 *)((char *)&it.m_Index.x + v92);
                v50 = v48 + 1;
                iCurPos = v49;
                iTween = v48 + 1;
                if ( v48 + 1 < v49 )
                  break;
LABEL_25:
                v79 = it.m_Index;
                it.m_Index.x += it.m_Inc.x;
                it.m_Index.y += it.m_Inc.y;
                it.m_NBIndex.y += it.m_NBInc.y;
                viPrevPos = v79;
                it.m_NBIndex.x += it.m_NBInc.x;
                v12 = v81->x;
                if ( v12 >= it.m_End )
                  goto LABEL_26;
              }
              v51 = (float)v48;
              p_m_TangentS = (Vector *)viPrevPos.x;
              v52 = (float)v49;
              v85 = (float)v48;
              v83 = (float)v49;
              v82 = (_WORD *)&viTween + (__int16)iEdgeDim;
              v84 = *(&it.m_Index.x + (__int16)iEdgeDim);
              while ( 1 )
              {
                v53 = (float)v50;
                if ( v51 == v52 )
                {
                  if ( (float)(v53 - v52) < 0.0 )
                  {
                    flPercent = 0.0;
                    goto LABEL_24;
                  }
                  v54 = 1.0;
                }
                else
                {
                  v54 = (float)(v53 - v51) / (float)(v52 - v51);
                }
                flPercent = v54;
LABEL_24:
                v55 = v3->GetPowerInfo(this: v3);
                p_x = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v55 + 36)].m_Normal.x;
                v57 = v3->GetPowerInfo(this: v3);
                v58 = v3->m_pVerts;
                v59 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v57 + 36);
                vecNormal.x = (float)((float)(*p_x - v58[v59].m_Normal.x) * flPercent) + v58[v59].m_Normal.x;
                vecNormal.y = (float)((float)(p_x[1] - v58[v59].m_Normal.y) * flPercent) + v58[v59].m_Normal.y;
                vecNormal.z = (float)((float)(p_x[2] - v58[v59].m_Normal.z) * flPercent) + v58[v59].m_Normal.z;
                VectorNormalize(vec: &vecNormal);
                v60 = v3->GetPowerInfo(this: v3);
                v61 = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v60 + 36)].m_TangentS.x;
                v62 = v3->GetPowerInfo(this: v3);
                v63 = v3->m_pVerts;
                v64 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v62 + 36);
                vec.x = (float)((float)(*v61 - v63[v64].m_TangentS.x) * flPercent) + v63[v64].m_TangentS.x;
                vec.y = (float)((float)(v61[1] - v63[v64].m_TangentS.y) * flPercent) + v63[v64].m_TangentS.y;
                vec.z = (float)((float)(v61[2] - v63[v64].m_TangentS.z) * flPercent) + v63[v64].m_TangentS.z;
                VectorNormalize(&vec);
                v65 = v92;
                v66 = iTween;
                *v82 = v84;
                v67 = v3->__vftable;
                *(__int16 *)((char *)&viTween.x + v65) = v66;
                v68 = (int)v67->GetPowerInfo(this: v3);
                v69 = *(_DWORD *)(v68 + 36) * viTween.y;
                v70 = v3->m_pVerts;
                v71 = viTween.x + v69;
                v70[v71].m_Normal.x = vecNormal.x;
                v70[v71].m_Normal.y = vecNormal.y;
                v72 = &v70[v71];
                v72->m_Normal.z = vecNormal.z;
                v73 = vecNormal.z;
                v74 = vecNormal.y;
                v75 = vec.y * vecNormal.x;
                v76 = vec.z * vecNormal.x;
                v77 = (float)(vec.y * vecNormal.z) - (float)(vec.z * vecNormal.y);
                v78 = vec.x;
                v72->m_TangentS = vec;
                v72->m_TangentT.x = v77;
                v72->m_TangentT.y = v76 - (float)(v73 * v78);
                v72->m_TangentT.z = (float)(v74 * v78) - v75;
                iTween = v66 + 1;
                if ( v66 + 1 >= iCurPos )
                  goto LABEL_25;
                v52 = v83;
                v51 = v85;
                v50 = iTween;
              }
            }
          }
        }
LABEL_26:
        v6 = iSubEdge + 1;
        v5 = (CDispNeighbor *)&v91->m_SubNeighbors[1];
        iSubEdge = v6;
        v91 = (CDispNeighbor *)((char *)v91 + 6);
      }
      while ( v6 < 2 );
      v4 = iEdge;
LABEL_28:
      iEdge = ++v4;
    }
    while ( v4 < 4 );
    v2 = iDisp;
LABEL_30:
    iDisp = ++v2;
  }
  while ( v2 < nListSize );
}

//------------------------------------------------------------------------------
// Address: 0x1015DF00
// Name: BlendCorners
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendCorners(CCoreDispInfo **ppListBase, int nListSize)
{
  int *m_pMemory; // ebx
  CCoreDispInfo *v3; // edi
  int AllNeighbors; // esi
  int m_Size; // eax
  int *v6; // eax
  CPowerInfo *v7; // eax
  CVertIndex v8; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v10; // eax
  int v11; // ebx
  CoreDispVert_t *v12; // eax
  float z; // edx
  Vector *p_m_TangentS; // eax
  CVertIndex v15; // eax
  CCoreDispInfo *v16; // esi
  int NeighborCornerVert; // eax
  CPowerInfo *v18; // eax
  CVertIndex v19; // edi
  const CPowerInfo *(__thiscall *v20)(struct CCoreDispInfo *); // eax
  int v21; // eax
  int v22; // ecx
  CoreDispVert_t *m_pVerts; // edx
  CoreDispVert_t *v24; // eax
  float v25; // xmm0_4
  int v26; // eax
  float v27; // xmm3_4
  float y; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  float x; // xmm5_4
  float *p_x; // ebx
  int v34; // edx
  int *v35; // ecx
  int v36; // eax
  int v37; // eax
  CoreDispVert_t *v38; // esi
  float v39; // xmm3_4
  float v40; // xmm0_4
  CoreDispVert_t *v41; // eax
  float v42; // xmm1_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm5_4
  int v46; // eax
  int v47; // eax
  CoreDispVert_t *v48; // esi
  float v49; // xmm3_4
  float v50; // xmm0_4
  CoreDispVert_t *v51; // eax
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm2_4
  float v55; // xmm5_4
  int v56; // eax
  CoreDispVert_t *v57; // esi
  float v58; // xmm3_4
  float v59; // xmm0_4
  CoreDispVert_t *v60; // eax
  float v61; // xmm1_4
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm5_4
  int v65; // eax
  CoreDispVert_t *v66; // eax
  float v67; // xmm3_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  float v72; // xmm5_4
  CVertIndex v73; // ebx
  int *v74; // ecx
  int v75; // eax
  CoreDispVert_t *v76; // edx
  float v77; // xmm3_4
  float v78; // xmm0_4
  CoreDispVert_t *v79; // eax
  float v80; // xmm1_4
  float v81; // xmm4_4
  float v82; // xmm2_4
  float v83; // xmm5_4
  int v84; // [esp-Ch] [ebp-860h]
  int v85; // [esp-Ch] [ebp-860h]
  int iNeighbors[512]; // [esp+4h] [ebp-850h] BYREF
  CCoreDispInfo *pDisp; // [esp+804h] [ebp-50h]
  const Vector *vCornerVert; // [esp+808h] [ebp-4Ch]
  CVertIndex viNBCornerVert; // [esp+80Ch] [ebp-48h]
  int iCorner; // [esp+810h] [ebp-44h]
  int iDisp; // [esp+814h] [ebp-40h]
  CUtlVector<int,CUtlMemory<int,int> > nbCornerVerts; // [esp+818h] [ebp-3Ch] BYREF
  int *v93; // [esp+82Ch] [ebp-28h]
  int nNeighbors; // [esp+830h] [ebp-24h]
  int v95; // [esp+834h] [ebp-20h]
  CVertIndex cornerVert; // [esp+838h] [ebp-1Ch]
  Vector vAvgTanS; // [esp+83Ch] [ebp-18h] BYREF
  Vector vAverage; // [esp+848h] [ebp-Ch] BYREF

  m_pMemory = nullptr;
  memset(&nbCornerVerts, 0, sizeof(nbCornerVerts));
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    pDisp = ppListBase[iDisp];
    v3 = pDisp;
    AllNeighbors = GetAllNeighbors(iNeighbors, pDisp);
    m_Size = 0;
    nNeighbors = AllNeighbors;
    nbCornerVerts.m_Size = 0;
    if ( nbCornerVerts.m_Memory.m_nAllocationCount < AllNeighbors && nbCornerVerts.m_Memory.m_nGrowSize >= 0 )
    {
      nbCornerVerts.m_Memory.m_nAllocationCount = AllNeighbors;
      if ( m_pMemory != nullptr )
        v6 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 4 * AllNeighbors);
      else
        v6 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * AllNeighbors);
      nbCornerVerts.m_Memory.m_pMemory = v6;
      m_Size = nbCornerVerts.m_Size;
      m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
    }
    nbCornerVerts.m_pElements = m_pMemory;
    if ( AllNeighbors != 0 )
    {
      if ( AllNeighbors > nbCornerVerts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&nbCornerVerts,
          num: AllNeighbors - nbCornerVerts.m_Memory.m_nAllocationCount);
        m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
        m_Size = nbCornerVerts.m_Size;
      }
      nbCornerVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && AllNeighbors > 0 )
        _V_memmove(dest: &m_pMemory[AllNeighbors], src: m_pMemory, count: 4 * m_Size);
    }
    for ( iCorner = 0; iCorner < 4; ++iCorner )
    {
      v84 = iCorner;
      v7 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
      v8 = *CPowerInfo::GetCornerPointIndex(this: v7, iCorner: v84);
      GetPowerInfo = v3->GetPowerInfo;
      cornerVert = v8;
      v10 = (int)GetPowerInfo(this: v3);
      v11 = cornerVert.x + *(_DWORD *)(v10 + 36) * cornerVert.y;
      v12 = &v3->m_pVerts[v11];
      vAverage.x = v12->m_Normal.x;
      vCornerVert = &v12->m_Vert;
      vAverage.y = v12->m_Normal.y;
      z = v12->m_Normal.z;
      p_m_TangentS = &v3->m_pVerts[v11].m_TangentS;
      vAverage.z = z;
      vAvgTanS = *p_m_TangentS;
      if ( AllNeighbors > 0 )
      {
        v15 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v93 = nbCornerVerts.m_Memory.m_pMemory;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = AllNeighbors;
        while ( 1 )
        {
          v16 = ppListBase[*(int *)((char *)v93 + *(_DWORD *)&v15)];
          NeighborCornerVert = FindNeighborCornerVert(pDisp: v16, vecPoint: vCornerVert);
          if ( NeighborCornerVert == -1 )
          {
            *v93 = -1;
          }
          else
          {
            v85 = NeighborCornerVert;
            v18 = (CPowerInfo *)v16->GetPowerInfo(this: v16);
            v19 = *CPowerInfo::GetCornerPointIndex(this: v18, iCorner: v85);
            v20 = v16->GetPowerInfo;
            viNBCornerVert = v19;
            v21 = (int)v20(this: v16);
            v22 = v19.x + *(_DWORD *)(v21 + 36) * viNBCornerVert.y;
            *v93 = v22;
            v22 *= 224;
            m_pVerts = v16->m_pVerts;
            vAverage.x = *(float *)((char *)&m_pVerts->m_Normal.x + v22) + vAverage.x;
            vAverage.y = *(float *)((char *)&m_pVerts->m_Normal.y + v22) + vAverage.y;
            vAverage.z = *(float *)((char *)&m_pVerts->m_Normal.z + v22) + vAverage.z;
            v24 = v16->m_pVerts;
            v25 = *(float *)((char *)&v24->m_TangentS.x + v22) + vAvgTanS.x;
            v26 = (int)&v24->m_TangentS + v22;
            vAvgTanS.x = v25;
            vAvgTanS.y = *(float *)(v26 + 4) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v26 + 8) + vAvgTanS.z;
          }
          ++v93;
          if ( --v95 == 0 )
            break;
          v15 = cornerVert;
        }
        AllNeighbors = nNeighbors;
        v3 = pDisp;
      }
      VectorNormalize(vec: &vAverage);
      VectorNormalize(vec: &vAvgTanS);
      v3->m_pVerts[v11].m_Normal = vAverage;
      v27 = vAverage.z;
      y = vAverage.y;
      v29 = vAvgTanS.z * vAverage.x;
      v30 = vAvgTanS.y * vAverage.x;
      v31 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
      x = vAvgTanS.x;
      v3->m_pVerts[v11].m_TangentS = vAvgTanS;
      p_x = &v3->m_pVerts[v11].m_TangentT.x;
      v34 = 0;
      *p_x = v31;
      p_x[1] = v29 - (float)(v27 * x);
      p_x[2] = (float)(y * x) - v30;
      if ( AllNeighbors >= 4 )
      {
        v35 = nbCornerVerts.m_Memory.m_pMemory + 2;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        viNBCornerVert = (CVertIndex)((char *)&iNeighbors[1] - (char *)nbCornerVerts.m_Memory.m_pMemory);
        do
        {
          v36 = *(v35 - 2);
          if ( v36 != -1 )
          {
            v37 = v36;
            v38 = ppListBase[iNeighbors[v34]]->m_pVerts;
            v38[v37].m_Normal = vAverage;
            v39 = vAverage.z;
            v40 = vAverage.y;
            v41 = &v38[v37];
            AllNeighbors = nNeighbors;
            v42 = vAvgTanS.z * vAverage.x;
            v43 = vAvgTanS.y * vAverage.x;
            v44 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v45 = vAvgTanS.x;
            v41->m_TangentS = vAvgTanS;
            v41->m_TangentT.x = v44;
            v41->m_TangentT.y = v42 - (float)(v39 * v45);
            v41->m_TangentT.z = (float)(v40 * v45) - v43;
          }
          v46 = *(v35 - 1);
          if ( v46 != -1 )
          {
            v47 = v46;
            v48 = ppListBase[iNeighbors[v34 + 1]]->m_pVerts;
            v48[v47].m_Normal = vAverage;
            v49 = vAverage.z;
            v50 = vAverage.y;
            v51 = &v48[v47];
            AllNeighbors = nNeighbors;
            v52 = vAvgTanS.z * vAverage.x;
            v53 = vAvgTanS.y * vAverage.x;
            v54 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v55 = vAvgTanS.x;
            v51->m_TangentS = vAvgTanS;
            v51->m_TangentT.x = v54;
            v51->m_TangentT.y = v52 - (float)(v49 * v55);
            v51->m_TangentT.z = (float)(v50 * v55) - v53;
          }
          if ( *v35 != -1 )
          {
            v56 = *v35;
            v57 = ppListBase[*(int *)((char *)v35 + *(_DWORD *)&cornerVert)]->m_pVerts;
            v57[v56].m_Normal = vAverage;
            v58 = vAverage.z;
            v59 = vAverage.y;
            v60 = &v57[v56];
            AllNeighbors = nNeighbors;
            v61 = vAvgTanS.z * vAverage.x;
            v62 = vAvgTanS.y * vAverage.x;
            v63 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v64 = vAvgTanS.x;
            v60->m_TangentS = vAvgTanS;
            v60->m_TangentT.x = v63;
            v60->m_TangentT.y = v61 - (float)(v58 * v64);
            v60->m_TangentT.z = (float)(v59 * v64) - v62;
          }
          v65 = v35[1];
          if ( v65 != -1 )
          {
            v66 = &ppListBase[*(int *)((char *)v35 + *(_DWORD *)&viNBCornerVert)]->m_pVerts[v65];
            AllNeighbors = nNeighbors;
            v66->m_Normal = vAverage;
            v67 = vAverage.z;
            v68 = vAverage.y;
            v69 = vAvgTanS.z * vAverage.x;
            v70 = vAvgTanS.y * vAverage.x;
            v71 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v72 = vAvgTanS.x;
            v66->m_TangentS = vAvgTanS;
            v66->m_TangentT.x = v71;
            v66->m_TangentT.y = v69 - (float)(v67 * v72);
            v66->m_TangentT.z = (float)(v68 * v72) - v70;
          }
          v34 += 4;
          v35 += 4;
        }
        while ( v34 < AllNeighbors - 3 );
      }
      if ( v34 < AllNeighbors )
      {
        v73 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v74 = &nbCornerVerts.m_Memory.m_pMemory[v34];
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = AllNeighbors - v34;
        do
        {
          if ( *v74 != -1 )
          {
            v75 = *v74;
            v76 = ppListBase[*(int *)((char *)v74 + *(_DWORD *)&v73)]->m_pVerts;
            v76[v75].m_Normal.x = vAverage.x;
            v73 = cornerVert;
            v76[v75].m_Normal.y = vAverage.y;
            v76[v75].m_Normal.z = vAverage.z;
            v77 = vAverage.z;
            v78 = vAverage.y;
            v79 = &v76[v75];
            v80 = vAvgTanS.z * vAverage.x;
            v81 = vAvgTanS.y * vAverage.x;
            v82 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v83 = vAvgTanS.x;
            v79->m_TangentS = vAvgTanS;
            v79->m_TangentT.x = v82;
            v79->m_TangentT.y = v80 - (float)(v77 * v83);
            v79->m_TangentT.z = (float)(v78 * v83) - v81;
          }
          ++v74;
          --v95;
        }
        while ( v95 != 0 );
      }
    }
    m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
  }
  if ( nbCornerVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015E670
// Name: void SmoothDispSurfNormals(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmoothDispSurfNormals(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // esi

  for ( i = 0; i < nListSize; ++i )
    CCoreDispInfo::SetDispUtilsHelperInfo(this: ppListBase[i], ppListBase, listSize: nListSize);
  BlendSubNeighbors(ppListBase, nListSize);
  BlendCorners(ppListBase, nListSize);
  BlendEdges(ppListBase, nListSize);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1001ACF0
// Name: public: bool CVertIndex::operator!=(class CVertIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVertIndex::operator!=(CVertIndex *this, const CVertIndex *other)
{
  return this->x != other->x || this->y != other->y;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD20
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x1001AD90
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001ADE0
// Name: int GetSubNeighborIndex(class CDispUtilsHelper __near *,int,class CVertIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSubNeighborIndex(CDispUtilsHelper *pDisp, int iEdge, const CVertIndex *nodeIndex)
{
  int v3; // edi
  CDispNeighbor *v4; // eax
  int v5; // edx
  CDispNeighbor *v6; // esi
  int v7; // ecx
  int result; // eax

  v3 = pDisp->GetPowerInfo(this: pDisp);
  v4 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  v5 = *(_DWORD *)(v3 + 44);
  v6 = v4;
  v7 = *(&nodeIndex->x + (g_EdgeDims[iEdge] == 0));
  result = 0;
  if ( v7 == v5 )
  {
    if ( v6->m_SubNeighbors[0].m_Span != 0 )
      return -1;
  }
  else
  {
    result = v7 > v5;
  }
  if ( v6->m_SubNeighbors[result].m_iNeighbor == 0xFFFF )
  {
    if ( result == 1 && v6->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v6->m_SubNeighbors[0].m_Span == 0 )
      return 0;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE60
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  const CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x1001AEF0
// Name: void GetDispBox(class CCoreDispInfo __near *,class CDispBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDispBox(CCoreDispInfo *pDisp, CDispBox *box)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *p_z; // eax
  int i; // ecx
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  double v14; // xmm0_8
  float v15; // xmm0_4
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float vMax; // [esp+0h] [ebp-Ch]

  v2 = (__m128)0x6753C21Cu;
  v3 = (__m128)0xE753C21C;
  v4 = 1.0e24;
  v5 = 1.0e24;
  vMax = -1.0e24;
  v6 = -1.0e24;
  p_z = &pDisp->m_Surf.m_Points[0].z;
  for ( i = 4; i != 0; --i )
  {
    v9 = *(p_z - 2);
    if ( v9 > v4 )
      v9 = v4;
    v4 = v9;
    v10 = *(p_z - 1);
    if ( v10 > v5 )
      v10 = v5;
    v11 = (__m128)*(unsigned int *)p_z;
    v5 = v10;
    v12 = _mm_cvtps_pd(v11);
    v13 = _mm_cvtps_pd(v2);
    if ( v12.m128d_f64[0] > v13.m128d_f64[0] )
      v12 = v13;
    v2 = _mm_cvtpd_ps(v12);
    v14 = *(p_z - 2);
    if ( v14 < vMax )
      v14 = vMax;
    v15 = v14;
    vMax = v15;
    v16 = _mm_cvtps_pd((__m128)*((unsigned int *)p_z - 1));
    v17 = _mm_cvtps_pd(v3);
    if ( v16.m128d_f64[0] < v17.m128d_f64[0] )
      v16 = v17;
    v3 = _mm_cvtpd_ps(v16);
    v18 = v11.m128_f32[0];
    if ( v11.m128_f32[0] < (double)v6 )
      v18 = v6;
    p_z += 3;
    v6 = v18;
  }
  v19 = flPuff;
  v20 = v5 - flPuff;
  v21 = v2.m128_f32[0] - flPuff;
  v22 = flPuff + vMax;
  v23 = v3.m128_f32[0] + flPuff;
  box->m_Min.x = v4 - flPuff;
  box->m_Min.y = v20;
  box->m_Min.z = v21;
  box->m_Max.x = v22;
  box->m_Max.y = v23;
  box->m_Max.z = v19 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x1001B040
// Name: void AddNeighbor(class CCoreDispInfo __near *,int,int,enum NeighborSpan,class CCoreDispInfo __near *,int,enum NeighborSpan)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddNeighbor(
        int a1@<edi>,
        CCoreDispInfo *pMain,
        int iEdge,
        int iSub,
        NeighborSpan span,
        CCoreDispInfo *pOther,
        int iNeighborEdge,
        NeighborSpan nbSpan)
{
  NeighborSpan v8; // ebx
  int v9; // esi
  CDispNeighbor *v10; // eax
  unsigned __int8 v11; // dl

  if ( g_bEdgeNeighborFlip[iEdge] )
    span = g_SpanFlip[span];
  if ( g_bEdgeNeighborFlip[iNeighborEdge] )
    v8 = g_SpanFlip[nbSpan];
  else
    v8 = nbSpan;
  v9 = ((int (__thiscall *)(CCoreDispInfo *, int, int))pMain->GetEdgeNeighbor)(a1: pMain, a2: iEdge, a3: a1) + 6 * iSub;
  if ( v8 == MIDPOINT_TO_CORNER )
    v10 = (CDispNeighbor *)&pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge)->m_SubNeighbors[1];
  else
    v10 = pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge);
  if ( *(_WORD *)v9 == 0xFFFF && v10->m_SubNeighbors[0].m_iNeighbor == 0xFFFF )
  {
    *(_WORD *)v9 = pOther->m_nListIndex;
    *(_BYTE *)(v9 + 2) = g_CoreDispNeighborOrientationMap[iEdge][iNeighborEdge];
    *(_BYTE *)(v9 + 4) = v8;
    *(_BYTE *)(v9 + 3) = span;
    v10->m_SubNeighbors[0].m_iNeighbor = pMain->m_nListIndex;
    v11 = g_CoreDispNeighborOrientationMap[iNeighborEdge][iEdge];
    v10->m_SubNeighbors[0].m_Span = v8;
    v10->m_SubNeighbors[0].m_NeighborOrientation = v11;
    v10->m_SubNeighbors[0].m_NeighborSpan = span;
  }
  else if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "Found a displacement edge abutting multiple other edges.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B140
// Name: bool HasEdgeNeighbor(class CCoreDispInfo const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasEdgeNeighbor(const CCoreDispInfo *pMain, int iNeighbor)
{
  int v2; // ebx
  int v3; // esi
  CDispNeighbor *m_EdgeNeighbors; // edi
  CDispCornerNeighbors *i; // ecx
  int v6; // eax

  v2 = iNeighbor;
  v3 = 0;
  m_EdgeNeighbors = pMain->m_Surf.m_EdgeNeighbors;
  for ( i = pMain->m_Surf.m_CornerNeighbors; ; ++i )
  {
    v6 = 0;
    if ( i->m_nNeighbors != 0 )
      break;
LABEL_6:
    if ( m_EdgeNeighbors->m_SubNeighbors[0].m_iNeighbor == v2 || m_EdgeNeighbors->m_SubNeighbors[1].m_iNeighbor == v2 )
      return 1;
    ++v3;
    ++m_EdgeNeighbors;
    if ( v3 >= 4 )
      return 0;
  }
  while ( i->m_Neighbors[v6] != iNeighbor )
  {
    if ( ++v6 >= i->m_nNeighbors )
    {
      v2 = iNeighbor;
      goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1B0
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2C0
// Name: class CDispUtilsHelper __near * TransformIntoNeighbor(class CDispUtilsHelper __near *,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v4; // esi
  int v5; // edx
  __int16 y; // cx
  CVertIndex SubNeighborIndex; // eax

  v4 = iEdge;
  if ( iEdge == -1 )
  {
    v5 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
    if ( nodeIndex->x != 0 )
    {
      y = nodeIndex->y;
      if ( y == v5 )
      {
        v4 = 1;
      }
      else if ( nodeIndex->x == v5 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 4 * (y == 0) - 1;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  SubNeighborIndex = (CVertIndex)GetSubNeighborIndex(pDisp, iEdge: v4, nodeIndex);
  if ( SubNeighborIndex == -1 )
    return nullptr;
  else
    return TransformIntoSubNeighbor(pDisp, iEdge: v4, iSub: SubNeighborIndex, nodeIndex, out);
}

//------------------------------------------------------------------------------
// Address: 0x1001B350
// Name: bool FindEdge(class CCoreDispInfo __near *,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEdge(CCoreDispInfo *pInfo, const Vector *vPoint1, const Vector *vPoint2, int *iEdge)
{
  int v4; // ecx
  int v5; // ecx

  *iEdge = 0;
  while ( 1 )
  {
    v4 = *iEdge;
    if ( fabs(vPoint1->x - pInfo->m_Surf.m_Points[*iEdge].x) <= 0.0099999998
      && fabs(vPoint1->y - pInfo->m_Surf.m_Points[*iEdge].y) <= 0.0099999998
      && fabs(vPoint1->z - pInfo->m_Surf.m_Points[*iEdge].z) <= 0.0099999998
      && fabs(vPoint2->x - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].x) <= 0.0099999998
      && fabs(vPoint2->y - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].y) <= 0.0099999998
      && fabs(vPoint2->z - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].z) <= 0.0099999998 )
    {
      break;
    }
    v5 = v4 + 1;
    *iEdge = v5;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B420
// Name: void SetupEdgeNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupEdgeNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther)
{
  int v2; // edi
  float *p_z; // eax
  int v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  unsigned int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm6_4
  int v11; // ecx
  float *v12; // edx
  int v13; // ecx
  float *v14; // edx
  Vector pt[2]; // [esp+0h] [ebp-48h] BYREF
  Vector vPoint1; // [esp+18h] [ebp-30h] BYREF
  float v17; // [esp+28h] [ebp-20h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  Vector mid; // [esp+30h] [ebp-18h] BYREF
  int v20; // [esp+3Ch] [ebp-Ch]
  float *v21; // [esp+40h] [ebp-8h]
  int iNBEdge; // [esp+44h] [ebp-4h] BYREF

  v2 = 0;
  p_z = &pMain->m_Surf.m_Points[0].z;
  v4 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  v21 = &pMain->m_Surf.m_Points[0].z;
  v20 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  while ( 2 )
  {
    v5 = *(p_z - 2);
    v6 = *(p_z - 1);
    v7 = *p_z;
    v8 = 3 * ((unsigned int)&g_bEdgeNeighborFlip[v2 + v4] & 3) + 6;
    v9 = *((float *)&pMain->__vftable + v8);
    v10 = *((float *)&pMain->m_Nodes + v8);
    pt[1].z = *(&pMain->m_Elevation + v8);
    pt[0].x = v5;
    pt[0].y = v6;
    pt[0].z = v7;
    mid.x = (float)(v9 + v5) * 0.5;
    mid.y = (float)(v10 + v6) * 0.5;
    mid.z = (float)(pt[1].z + v7) * 0.5;
    pt[1].x = v9;
    pt[1].y = v10;
    v11 = 0;
    v12 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v12 - 2)) <= 0.0099999998
        && fabs(v10 - *(v12 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v12) <= 0.0099999998
        && fabs(pt[0].x - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].x) <= 0.0099999998
        && fabs(pt[0].y - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].y) <= 0.0099999998
        && fabs(pt[0].z - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].z) <= 0.0099999998 )
      {
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v11,
          nbSpan: CORNER_TO_CORNER);
        goto LABEL_27;
      }
      ++v11;
      v12 += 3;
    }
    while ( v11 < 4 );
    v17 = (float)(v6 * 2.0) - v10;
    v18 = (float)(v7 * 2.0) - pt[1].z;
    v13 = 0;
    v14 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v14 - 2)) <= 0.0099999998
        && fabs(v10 - *(v14 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v14) <= 0.0099999998
        && fabs((float)((float)(v5 * 2.0) - v9) - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].x) <= 0.0099999998
        && fabs(v17 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].y) <= 0.0099999998
        && fabs(v18 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].z) <= 0.0099999998 )
      {
        iNBEdge = v13;
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v13,
          nbSpan: CORNER_TO_MIDPOINT);
        goto LABEL_27;
      }
      ++v13;
      v14 += 3;
    }
    while ( v13 < 4 );
    iNBEdge = v13;
    vPoint1.x = (float)(v9 * 2.0) - pt[0].x;
    vPoint1.y = (float)(v10 * 2.0) - pt[0].y;
    vPoint1.z = (float)(pt[1].z * 2.0) - pt[0].z;
    if ( FindEdge(pInfo: pOther, &vPoint1, vPoint2: pt, iEdge: &iNBEdge) != 0 )
    {
      AddNeighbor(
        a1: v2,
        pMain,
        iEdge: v2,
        iSub: 0,
        span: CORNER_TO_CORNER,
        pOther,
        iNeighborEdge: iNBEdge,
        nbSpan: MIDPOINT_TO_CORNER);
    }
    else
    {
      if ( FindEdge(pInfo: pOther, vPoint1: &mid, vPoint2: pt, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: g_bEdgeNeighborFlip[v2],
          span: CORNER_TO_MIDPOINT,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
      if ( FindEdge(pInfo: pOther, vPoint1: &pt[1], vPoint2: &mid, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: !g_bEdgeNeighborFlip[v2],
          span: MIDPOINT_TO_CORNER,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
    }
LABEL_27:
    v21 += 3;
    if ( ++v2 < 4 )
    {
      v4 = v20;
      p_z = v21;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B740
// Name: void SetupCornerNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCornerNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther, int *nOverflows)
{
  CCoreDispInfo *v4; // edi
  CPowerInfo *v5; // eax
  const CVertIndex *CornerPointIndex; // ebx
  int i; // edi
  CPowerInfo *v8; // eax
  const CVertIndex *v9; // ebx
  Vector *p_m_Vert; // eax
  CDispCornerNeighbors *v11; // edi
  CDispCornerNeighbors *v12; // eax
  unsigned __int8 m_nNeighbors; // cl
  const Vector *vMainCorner; // [esp+8h] [ebp-10h]
  int iOtherSharedCorner; // [esp+Ch] [ebp-Ch]
  int iMainSharedCorner; // [esp+10h] [ebp-8h]
  int nShared; // [esp+14h] [ebp-4h]
  int iMainCorner; // [esp+24h] [ebp+Ch]

  v4 = pMain;
  if ( HasEdgeNeighbor(pMain, iNeighbor: pOther->m_nListIndex) == 0 )
  {
    nShared = 0;
    iMainSharedCorner = -1;
    iOtherSharedCorner = -1;
    iMainCorner = 0;
    while ( 1 )
    {
      v5 = (CPowerInfo *)v4->GetPowerInfo(this: v4);
      CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v5, iCorner: iMainCorner);
      vMainCorner = &v4->m_pVerts[CornerPointIndex->x
                                + *(_DWORD *)(v4->GetPowerInfo(this: v4) + 36) * CornerPointIndex->y].m_Vert;
      for ( i = 0; i < 4; ++i )
      {
        v8 = (CPowerInfo *)pOther->GetPowerInfo(this: pOther);
        v9 = CPowerInfo::GetCornerPointIndex(this: v8, iCorner: i);
        p_m_Vert = &pOther->m_pVerts[v9->x + *(_DWORD *)(pOther->GetPowerInfo(this: pOther) + 36) * v9->y].m_Vert;
        if ( fabs(vMainCorner->x - p_m_Vert->x) <= 0.001
          && fabs(vMainCorner->y - p_m_Vert->y) <= 0.001
          && fabs(vMainCorner->z - p_m_Vert->z) <= 0.001 )
        {
          ++nShared;
          iMainSharedCorner = iMainCorner;
          iOtherSharedCorner = i;
        }
      }
      if ( ++iMainCorner >= 4 )
        break;
      v4 = pMain;
    }
    if ( nShared == 1 )
    {
      v11 = pMain->GetCornerNeighbors(this: pMain, a2: iMainSharedCorner);
      v12 = pOther->GetCornerNeighbors(this: pOther, a2: iOtherSharedCorner);
      m_nNeighbors = v11->m_nNeighbors;
      if ( m_nNeighbors >= 4u || v12->m_nNeighbors >= 4u )
      {
        ++*nOverflows;
      }
      else
      {
        v11->m_Neighbors[m_nNeighbors] = pOther->m_nListIndex;
        ++v11->m_nNeighbors;
        v12->m_Neighbors[v12->m_nNeighbors++] = pMain->m_nListIndex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B8D0
// Name: bool VerifyNeighborVertConnection(class CDispUtilsHelper __near *,class CVertIndex const __near &,class CDispUtilsHelper const __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VerifyNeighborVertConnection(
        CDispUtilsHelper *pDisp,
        CVertIndex *nodeIndex,
        const CDispUtilsHelper *pTestNeighbor,
        const CVertIndex *testNeighborIndex,
        int mySide)
{
  const CDispUtilsHelper *v5; // eax
  CDispUtilsHelper *v6; // esi
  CDispUtilsHelper_vtbl *v7; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(CDispUtilsHelper *); // eax
  int v9; // eax
  int EdgeIndexFromPoint; // eax
  bool result; // al
  CVertIndex testIndex; // [esp+Ch] [ebp-8h] BYREF
  CVertIndex nbIndex; // [esp+10h] [ebp-4h] BYREF

  nbIndex.x = -1;
  nbIndex.y = -1;
  v5 = TransformIntoNeighbor(pDisp, iEdge: mySide, nodeIndex, out: &nbIndex);
  v6 = (CDispUtilsHelper *)v5;
  result = true;
  if ( v5 != nullptr )
  {
    if ( pTestNeighbor != v5 )
      return false;
    if ( nbIndex.x != testNeighborIndex->x )
      return false;
    if ( nbIndex.y != testNeighborIndex->y )
      return false;
    v7 = v5->__vftable;
    testIndex.x = -1;
    GetPowerInfo = v7->GetPowerInfo;
    testIndex.y = -1;
    v9 = (int)GetPowerInfo(this: v6);
    EdgeIndexFromPoint = GetEdgeIndexFromPoint(index: &nbIndex, iMaxPower: *(_DWORD *)(v9 + 28));
    if ( EdgeIndexFromPoint == -1
      || TransformIntoNeighbor(pDisp: v6, iEdge: EdgeIndexFromPoint, nodeIndex: &nbIndex, out: &testIndex) != pDisp
      || CVertIndex::operator!=(this: nodeIndex, other: &testIndex) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B980
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BB40
// Name: public: bool CDispEdgeIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispEdgeIterator::Next(CDispEdgeIterator *this)
{
  CVertIndex *p_m_Index; // edi
  CVertIndex *p_m_NBIndex; // ebx
  int m_iCurSub; // eax
  int m_iEdge; // ecx
  CDispUtilsHelper *v6; // eax

  this->m_It.m_Index.x += this->m_It.m_Inc.x;
  this->m_It.m_Index.y += this->m_It.m_Inc.y;
  this->m_It.m_NBIndex.x += this->m_It.m_NBInc.x;
  this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
  p_m_Index = &this->m_It.m_Index;
  p_m_NBIndex = &this->m_It.m_NBIndex;
  if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
    return 1;
  while ( 1 )
  {
    m_iCurSub = this->m_iCurSub;
    if ( m_iCurSub == 1 )
      break;
    m_iEdge = this->m_iEdge;
    this->m_iCurSub = m_iCurSub + 1;
    v6 = SetupEdgeIncrements(
           pDisp: this->m_pDisp,
           iEdge: m_iEdge,
           iSub: m_iCurSub + 1,
           myIndex: &this->m_It.m_Index,
           myInc: &this->m_It.m_Inc,
           nbIndex: &this->m_It.m_NBIndex,
           nbInc: &this->m_It.m_NBInc,
           myEnd: &this->m_It.m_End,
           iFreeDim: &this->m_It.m_FreeDim);
    this->m_It.m_pNeighbor = v6;
    if ( v6 == nullptr )
    {
      this->m_It.m_End = 0;
      this->m_It.m_Inc.x = 0;
      p_m_Index->x = 0;
      this->m_It.m_FreeDim = 0;
    }
    p_m_Index->x += this->m_It.m_Inc.x;
    this->m_It.m_Index.y += this->m_It.m_Inc.y;
    p_m_NBIndex->x += this->m_It.m_NBInc.x;
    this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
    if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC00
// Name: void VerifyNeighborConnections(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyNeighborConnections(CCoreDispInfo **ppListBase, int nDisps)
{
  char v2; // bl
  CCoreDispInfo *v3; // esi
  int v4; // edi
  _WORD *v5; // eax
  CPowerInfo *v6; // eax
  const CVertIndex *CornerPointIndex; // edi
  int p_m_Vert; // ebx
  CPowerInfo *v9; // eax
  const CVertIndex *v10; // edi
  int v11; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  CPowerInfo *v13; // eax
  const CVertIndex *v14; // edi
  int v15; // eax
  int v16; // [esp+14h] [ebp-44h]
  CDispEdgeIterator v17; // [esp+20h] [ebp-38h] BYREF
  int v18; // [esp+48h] [ebp-10h]
  int v19; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+50h] [ebp-8h]
  int v21; // [esp+54h] [ebp-4h]

  do
  {
    v2 = 1;
    v21 = 0;
    if ( nDisps <= 0 )
      break;
    v3 = *ppListBase;
    v4 = 0;
    for ( i = 0; ; i = 0 )
    {
      do
      {
        v17.m_It.m_NBIndex.x = 0;
        v17.m_It.m_Index = 0;
        v17.m_It.m_FreeDim = 0;
        v17.m_It.m_Inc.x = 0;
        v18 = 0;
        v17.m_iEdge = (int)v3;
        v17.m_iCurSub = v4;
        v17.m_It.m_pNeighbor = (CDispUtilsHelper *)-1;
        while ( CDispEdgeIterator::Next(this: (CDispEdgeIterator *)&v17.m_iEdge) != 0 )
        {
          if ( !VerifyNeighborVertConnection(
                  pDisp: v3,
                  nodeIndex: &v17.m_It.m_Inc,
                  pTestNeighbor: *(const CDispUtilsHelper **)&v17.m_It.m_Index,
                  testNeighborIndex: &v17.m_It.m_NBInc,
                  mySide: v4) )
          {
            v16 = v4;
            v5 = (_WORD *)((int (__thiscall *)(CCoreDispInfo *))v3->GetEdgeNeighbor)(a1: v3);
            *v5 = -1;
            v5[3] = -1;
            v6 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v6, iCorner: 0);
            p_m_Vert = (int)&v3->m_pVerts[CornerPointIndex->x
                                        + *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * CornerPointIndex->y].m_Vert;
            v9 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            v10 = CPowerInfo::GetCornerPointIndex(this: v9, iCorner: 0);
            v11 = *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * v10->y;
            GetPowerInfo = v3->GetPowerInfo;
            v19 = (int)&v3->m_pVerts[v10->x + v11].m_Vert;
            v13 = (CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, _DWORD))GetPowerInfo)(a1: v3, a2: 0);
            v14 = CPowerInfo::GetCornerPointIndex(this: v13, iCorner: v16);
            v15 = v3->GetPowerInfo(this: v3);
            _Warning(
              a1: "Warning: invalid neighbor connection on displacement near (%.2f %.2f %.2f)\n",
              v3->m_pVerts[v14->x + *(_DWORD *)(v15 + 36) * v14->y].m_Vert.x,
              *(float *)(v19 + 4),
              *(float *)(p_m_Vert + 8));
            v2 = 0;
            v4 = i;
          }
        }
        i = ++v4;
      }
      while ( v4 < 4 );
      if ( ++v21 >= nDisps )
        break;
      v3 = ppListBase[v21];
      v4 = 0;
    }
  }
  while ( v2 == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1001BDE0
// Name: bool IsVertAllowed(class CDispUtilsHelper __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsVertAllowed(CDispUtilsHelper *pDisp, CVertIndex sideVert, int iLevel)
{
  int v4; // eax
  const CVertIndex *v5; // edi
  int v6; // ecx
  __int16 v7; // ax
  int v8; // edx
  int v9; // ecx
  __int16 v10; // ax
  __int16 y; // cx
  int SubNeighborIndex; // edi
  CDispSubNeighbor *v14; // ebx
  CDispUtilsHelper *v15; // edi
  CShiftInfo *v16; // ebx
  int v17; // eax
  int v18; // eax
  int iSub; // [esp+8h] [ebp-4h]
  int iSide; // [esp+14h] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = (const CVertIndex *)sideVert;
  v6 = *(_DWORD *)(v4 + 36);
  if ( *(_WORD *)sideVert.x == 0 )
  {
    v7 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v7 != 0 && v7 != v6 - 1 )
      goto LABEL_4;
    return true;
  }
  v9 = v6 - 1;
  if ( *(__int16 *)sideVert.x == v9 )
  {
    v10 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v10 == 0 || v10 == v9 )
      return true;
  }
LABEL_4:
  v8 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  if ( v5->x != 0 )
  {
    y = v5->y;
    if ( y == v8 )
    {
      iSide = 1;
    }
    else if ( v5->x == v8 )
    {
      iSide = 2;
    }
    else
    {
      if ( y != 0 )
        return true;
      iSide = 3;
    }
  }
  else
  {
    iSide = 0;
  }
  SubNeighborIndex = GetSubNeighborIndex(pDisp, iEdge: iSide, nodeIndex: v5);
  iSub = SubNeighborIndex;
  if ( SubNeighborIndex == -1 )
    return true;
  v14 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iSide)->m_SubNeighbors[SubNeighborIndex];
  v15 = pDisp->GetDispUtilsByIndex(this: pDisp, a2: v14->m_iNeighbor);
  v16 = &g_ShiftInfos[v14->m_Span][v14->m_NeighborSpan];
  v17 = v15->GetPowerInfo(this: v15);
  if ( v16->m_PowerShiftAdd + *(_DWORD *)(v17 + 28) < iLevel + 1 )
    return false;
  TransformIntoSubNeighbor(
    pDisp,
    iEdge: iSide,
    (CVertIndex)iSub,
    nodeIndex: *(const CVertIndex **)&sideVert,
    out: &sideVert);
  v18 = v15->GetPowerInfo(this: v15);
  return ((int)v15[((unsigned int)(sideVert.x + *(_DWORD *)(v18 + 36) * sideVert.y) >> 5) + 200].__vftable
        & (1 << ((LOBYTE(sideVert.x) + *(_BYTE *)(v18 + 36) * LOBYTE(sideVert.y)) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF50
// Name: void UnallowVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnallowVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int *nUnallowed)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  const CVertIndex *v8; // eax
  int pDispa; // [esp+Ch] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = nodeIndex->x + *(_DWORD *)(v4 + 36) * nodeIndex->y;
  v6 = 1 << ((nodeIndex->x + *(_BYTE *)(v4 + 36) * nodeIndex->y) & 0x1F);
  if ( (v6 & (int)pDisp[((unsigned int)v5 >> 5) + 200].__vftable) != 0 )
  {
    ++*nUnallowed;
    pDisp[(v5 >> 5) + 200].__vftable = (CDispUtilsHelper_vtbl *)((int)pDisp[(v5 >> 5) + 200].__vftable & ~v6);
    v7 = 42 * v5 + 12;
    for ( pDispa = 4; pDispa != 0; --pDispa )
    {
      v8 = (const CVertIndex *)(v7 + *(_DWORD *)pDisp->GetPowerInfo(this: pDisp));
      if ( v8->x != -1 && v8[1].x == -1 )
        UnallowVerts_R(pDisp, nodeIndex: v8, nUnallowed);
      v7 += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BFF0
// Name: void DisableUnallowedVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableUnallowedVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int iLevel, int *nUnallowed)
{
  const CVertIndex *v5; // ebx
  const CVertIndex *v6; // edi
  int v7; // ebx
  const CVertIndex *v8; // edi
  int v9; // eax
  int pDispa; // [esp+14h] [ebp+8h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+Ch]
  int iLevela; // [esp+1Ch] [ebp+10h]

  nodeIndexa = (const CVertIndex *)(16
                                  * (nodeIndex->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * nodeIndex->y));
  v5 = nodeIndexa;
  for ( pDispa = 4; pDispa != 0; --pDispa )
  {
    v6 = (const CVertIndex *)((char *)v5 + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 4));
    if ( !IsVertAllowed(pDisp, sideVert: (CVertIndex)v6, iLevel) )
      UnallowVerts_R(pDisp, nodeIndex: v6, nUnallowed);
    ++v5;
  }
  v7 = iLevel + 1;
  if ( iLevel + 1 < *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28) )
  {
    v8 = nodeIndexa;
    for ( iLevela = 4; iLevela != 0; --iLevela )
    {
      v9 = pDisp->GetPowerInfo(this: pDisp);
      DisableUnallowedVerts_R(
        pDisp,
        nodeIndex: (const CVertIndex *)((char *)v8++ + *(_DWORD *)(v9 + 8)),
        iLevel: v7,
        nUnallowed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C0A0
// Name: void SetupAllowedVerts(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupAllowedVerts(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // edx
  CBitVec<289> *p_m_AllowedVerts; // eax
  int v5; // edi
  CCoreDispInfo *v6; // esi
  const CVertIndex *v7; // eax
  int nUnallowed; // [esp+Ch] [ebp-4h] BYREF
  char bContinue_3; // [esp+1Fh] [ebp+Fh]

  for ( i = 0; i < nListSize; ++i )
  {
    p_m_AllowedVerts = &ppListBase[i]->m_AllowedVerts;
    if ( ppListBase[i] != (CCoreDispInfo *)-800 )
    {
      p_m_AllowedVerts->m_Ints[0] = -1;
      p_m_AllowedVerts->m_Ints[1] = -1;
      p_m_AllowedVerts->m_Ints[2] = -1;
      p_m_AllowedVerts->m_Ints[3] = -1;
      p_m_AllowedVerts->m_Ints[4] = -1;
      p_m_AllowedVerts->m_Ints[5] = -1;
      p_m_AllowedVerts->m_Ints[6] = -1;
      p_m_AllowedVerts->m_Ints[7] = -1;
      p_m_AllowedVerts->m_Ints[8] = -1;
      p_m_AllowedVerts->m_Ints[9] = -1;
    }
  }
  do
  {
    v5 = 0;
    bContinue_3 = 0;
    if ( nListSize <= 0 )
      break;
    do
    {
      v6 = ppListBase[v5];
      nUnallowed = 0;
      v7 = (const CVertIndex *)v6->GetPowerInfo(this: v6);
      DisableUnallowedVerts_R(pDisp: v6, nodeIndex: v7 + 8, iLevel: 0, &nUnallowed);
      if ( nUnallowed != 0 )
        bContinue_3 = 1;
      ++v5;
    }
    while ( v5 < nListSize );
  }
  while ( bContinue_3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1001C320
// Name: void FindNeighboringDispSurfs(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindNeighboringDispSurfs(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  CCoreDispInfo *v5; // edi
  CDispNeighbor *v6; // eax
  int v7; // eax
  CDispBox *m_pMemory; // ebx
  int v9; // edx
  CDispBox *v10; // esi
  int v11; // edx
  int v12; // eax
  int v13; // edi
  CDispBox *v14; // esi
  int v15; // eax
  float *p_x; // ecx
  CCoreDispInfo *v17; // ebx
  bool v18; // zf
  int m_nGrowSize; // edi
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > boxes; // [esp+Ch] [ebp-3Ch] BYREF
  CCoreDispInfo *pOther; // [esp+20h] [ebp-28h]
  int nCornerOverflows; // [esp+24h] [ebp-24h] BYREF
  int v23; // [esp+28h] [ebp-20h]
  CDispBox *v24; // [esp+2Ch] [ebp-1Ch]
  int v25; // [esp+30h] [ebp-18h]
  CCoreDispInfo *pMain; // [esp+34h] [ebp-14h]
  CCoreDispInfo **v27; // [esp+38h] [ebp-10h]
  int v28; // [esp+44h] [ebp-4h]

  v2 = nListSize;
  v3 = 0;
  v4 = 0;
  if ( nListSize > 0 )
  {
    do
    {
      v5 = ppListBase[v4];
      do
      {
        v6 = v5->GetEdgeNeighbor(this: v5, a2: v3);
        v6->m_SubNeighbors[0].m_iNeighbor = -1;
        v6->m_SubNeighbors[1].m_iNeighbor = -1;
        v7 = (int)v5->GetCornerNeighbors(this: v5, a2: v3++);
        *(_BYTE *)(v7 + 8) = 0;
      }
      while ( v3 < 4 );
      ++v4;
      v3 = 0;
    }
    while ( v4 < nListSize );
    v2 = nListSize;
  }
  memset(&boxes, 0, sizeof(boxes));
  v28 = 1;
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int>>::InsertMultipleBefore(this: &boxes, elem: 0, num: v2);
  m_pMemory = boxes.m_Memory.m_pMemory;
  v9 = 0;
  if ( v2 > 0 )
  {
    v10 = boxes.m_Memory.m_pMemory;
    do
    {
      GetDispBox(pDisp: ppListBase[v9], box: v10);
      v9 = v11 + 1;
      ++v10;
    }
    while ( v9 < v2 );
  }
  nCornerOverflows = 0;
  if ( v2 > 0 )
  {
    v12 = 1;
    v25 = 1;
    v24 = m_pMemory;
    v27 = ppListBase;
    v23 = v2;
    do
    {
      pMain = *v27;
      v13 = v12;
      if ( v12 < nListSize )
      {
        v14 = m_pMemory + 1;
        do
        {
          pOther = ppListBase[v13];
          v15 = 0;
          p_x = &v14->m_Max.x;
          while ( *(p_x - 3) <= *(float *)((char *)p_x + (char *)m_pMemory - (char *)v14)
               && *(&m_pMemory->m_Min.x + v15) <= *p_x )
          {
            ++v15;
            ++p_x;
            if ( v15 >= 3 )
            {
              v17 = pOther;
              SetupEdgeNeighbors(pMain, pOther);
              SetupCornerNeighbors(pMain, pOther: v17, nOverflows: &nCornerOverflows);
              m_pMemory = v24;
              break;
            }
          }
          ++v13;
          ++v14;
        }
        while ( v13 < nListSize );
        v12 = v25;
      }
      ++v27;
      ++v12;
      ++m_pMemory;
      v18 = v23-- == 1;
      v25 = v12;
      v24 = m_pMemory;
    }
    while ( !v18 );
    if ( nCornerOverflows != 0 )
      _Warning(a1: "Warning: overflowed %d displacement corner-neighbor lists.", nCornerOverflows);
    m_pMemory = boxes.m_Memory.m_pMemory;
    v2 = nListSize;
  }
  VerifyNeighborConnections(ppListBase, nDisps: v2);
  v28 = 2;
  m_nGrowSize = boxes.m_Memory.m_nGrowSize;
  boxes.m_Size = 0;
  if ( boxes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      boxes.m_Memory.m_pMemory = nullptr;
      m_pMemory = nullptr;
    }
    boxes.m_Memory.m_nAllocationCount = 0;
  }
  boxes.m_pElements = m_pMemory;
  v28 = -1;
  if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10070610
// Name: public: bool CVertIndex::operator!=(class CVertIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVertIndex::operator!=(CVertIndex *this, const CVertIndex *other)
{
  return this->x != other->x || this->y != other->y;
}

//------------------------------------------------------------------------------
// Address: 0x10070640
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10070650
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070660
// Name: public: void CCoreDispSurface::GetPoint(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetPoint(CCoreDispSurface *this, int index, Vector *pt)
{
  *pt = this->m_Points[index];
}

//------------------------------------------------------------------------------
// Address: 0x10070690
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x100706E0
// Name: int GetSubNeighborIndex(class CDispUtilsHelper __near *,int,class CVertIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSubNeighborIndex(CDispUtilsHelper *pDisp, int iEdge, const CVertIndex *nodeIndex)
{
  int v3; // edi
  CDispNeighbor *v4; // eax
  int v5; // edx
  CDispNeighbor *v6; // esi
  int v7; // ecx
  int result; // eax

  v3 = pDisp->GetPowerInfo(this: pDisp);
  v4 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  v5 = *(_DWORD *)(v3 + 44);
  v6 = v4;
  v7 = *(&nodeIndex->x + (g_EdgeDims[iEdge] == 0));
  result = 0;
  if ( v7 == v5 )
  {
    if ( v6->m_SubNeighbors[0].m_Span != 0 )
      return -1;
  }
  else
  {
    result = v7 > v5;
  }
  if ( v6->m_SubNeighbors[result].m_iNeighbor == 0xFFFF )
  {
    if ( result == 1 && v6->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v6->m_SubNeighbors[0].m_Span == 0 )
      return 0;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070760
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x100707F0
// Name: void GetDispBox(class CCoreDispInfo __near *,class CDispBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDispBox(CCoreDispInfo *pDisp, CDispBox *box)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *p_z; // eax
  int i; // ecx
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  double v14; // xmm0_8
  float v15; // xmm0_4
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float vMax; // [esp+0h] [ebp-Ch]

  v2 = (__m128)0x6753C21Cu;
  v3 = (__m128)0xE753C21C;
  v4 = 1.0e24;
  v5 = 1.0e24;
  vMax = -1.0e24;
  v6 = -1.0e24;
  p_z = &pDisp->m_Surf.m_Points[0].z;
  for ( i = 4; i != 0; --i )
  {
    v9 = *(p_z - 2);
    if ( v9 > v4 )
      v9 = v4;
    v4 = v9;
    v10 = *(p_z - 1);
    if ( v10 > v5 )
      v10 = v5;
    v11 = (__m128)*(unsigned int *)p_z;
    v5 = v10;
    v12 = _mm_cvtps_pd(v11);
    v13 = _mm_cvtps_pd(v2);
    if ( v12.m128d_f64[0] > v13.m128d_f64[0] )
      v12 = v13;
    v2 = _mm_cvtpd_ps(v12);
    v14 = *(p_z - 2);
    if ( v14 < vMax )
      v14 = vMax;
    v15 = v14;
    vMax = v15;
    v16 = _mm_cvtps_pd((__m128)*((unsigned int *)p_z - 1));
    v17 = _mm_cvtps_pd(v3);
    if ( v16.m128d_f64[0] < v17.m128d_f64[0] )
      v16 = v17;
    v3 = _mm_cvtpd_ps(v16);
    v18 = v11.m128_f32[0];
    if ( v11.m128_f32[0] < (double)v6 )
      v18 = v6;
    p_z += 3;
    v6 = v18;
  }
  v19 = flPuff;
  v20 = v5 - flPuff;
  v21 = v2.m128_f32[0] - flPuff;
  v22 = flPuff + vMax;
  v23 = v3.m128_f32[0] + flPuff;
  box->m_Min.x = v4 - flPuff;
  box->m_Min.y = v20;
  box->m_Min.z = v21;
  box->m_Max.x = v22;
  box->m_Max.y = v23;
  box->m_Max.z = v19 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x10070940
// Name: void AddNeighbor(class CCoreDispInfo __near *,int,int,enum NeighborSpan,class CCoreDispInfo __near *,int,enum NeighborSpan)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddNeighbor(
        int a1@<edi>,
        CCoreDispInfo *pMain,
        int iEdge,
        int iSub,
        NeighborSpan span,
        CCoreDispInfo *pOther,
        int iNeighborEdge,
        NeighborSpan nbSpan)
{
  NeighborSpan v8; // ebx
  int v9; // esi
  CDispNeighbor *v10; // eax
  unsigned __int8 v11; // dl

  if ( g_bEdgeNeighborFlip[iEdge] )
    span = g_SpanFlip[span];
  if ( g_bEdgeNeighborFlip[iNeighborEdge] )
    v8 = g_SpanFlip[nbSpan];
  else
    v8 = nbSpan;
  v9 = ((int (__thiscall *)(CCoreDispInfo *, int, int))pMain->GetEdgeNeighbor)(a1: pMain, a2: iEdge, a3: a1) + 6 * iSub;
  if ( v8 == MIDPOINT_TO_CORNER )
    v10 = (CDispNeighbor *)&pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge)->m_SubNeighbors[1];
  else
    v10 = pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge);
  if ( *(_WORD *)v9 == 0xFFFF && v10->m_SubNeighbors[0].m_iNeighbor == 0xFFFF )
  {
    *(_WORD *)v9 = pOther->m_nListIndex;
    *(_BYTE *)(v9 + 2) = g_CoreDispNeighborOrientationMap[iEdge][iNeighborEdge];
    *(_BYTE *)(v9 + 4) = v8;
    *(_BYTE *)(v9 + 3) = span;
    v10->m_SubNeighbors[0].m_iNeighbor = pMain->m_nListIndex;
    v11 = g_CoreDispNeighborOrientationMap[iNeighborEdge][iEdge];
    v10->m_SubNeighbors[0].m_Span = v8;
    v10->m_SubNeighbors[0].m_NeighborOrientation = v11;
    v10->m_SubNeighbors[0].m_NeighborSpan = span;
  }
  else if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "Found a displacement edge abutting multiple other edges.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070A40
// Name: bool HasEdgeNeighbor(class CCoreDispInfo const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasEdgeNeighbor(const CCoreDispInfo *pMain, int iNeighbor)
{
  int v2; // ebx
  int v3; // esi
  CDispNeighbor *m_EdgeNeighbors; // edi
  CDispCornerNeighbors *i; // ecx
  int v6; // eax

  v2 = iNeighbor;
  v3 = 0;
  m_EdgeNeighbors = pMain->m_Surf.m_EdgeNeighbors;
  for ( i = pMain->m_Surf.m_CornerNeighbors; ; ++i )
  {
    v6 = 0;
    if ( i->m_nNeighbors != 0 )
      break;
LABEL_6:
    if ( m_EdgeNeighbors->m_SubNeighbors[0].m_iNeighbor == v2 || m_EdgeNeighbors->m_SubNeighbors[1].m_iNeighbor == v2 )
      return 1;
    ++v3;
    ++m_EdgeNeighbors;
    if ( v3 >= 4 )
      return 0;
  }
  while ( i->m_Neighbors[v6] != iNeighbor )
  {
    if ( ++v6 >= i->m_nNeighbors )
    {
      v2 = iNeighbor;
      goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070AB0
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x10070BC0
// Name: class CDispUtilsHelper __near * TransformIntoNeighbor(class CDispUtilsHelper __near *,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v4; // esi
  int v5; // edx
  __int16 y; // cx
  CVertIndex SubNeighborIndex; // eax

  v4 = iEdge;
  if ( iEdge == -1 )
  {
    v5 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
    if ( nodeIndex->x != 0 )
    {
      y = nodeIndex->y;
      if ( y == v5 )
      {
        v4 = 1;
      }
      else if ( nodeIndex->x == v5 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 4 * (y == 0) - 1;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  SubNeighborIndex = (CVertIndex)GetSubNeighborIndex(pDisp, iEdge: v4, nodeIndex);
  if ( SubNeighborIndex == -1 )
    return nullptr;
  else
    return TransformIntoSubNeighbor(pDisp, iEdge: v4, iSub: SubNeighborIndex, nodeIndex, out);
}

//------------------------------------------------------------------------------
// Address: 0x10070C50
// Name: bool FindEdge(class CCoreDispInfo __near *,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEdge(CCoreDispInfo *pInfo, const Vector *vPoint1, const Vector *vPoint2, int *iEdge)
{
  int v4; // ecx
  int v5; // ecx

  *iEdge = 0;
  while ( 1 )
  {
    v4 = *iEdge;
    if ( fabs(vPoint1->x - pInfo->m_Surf.m_Points[*iEdge].x) <= 0.0099999998
      && fabs(vPoint1->y - pInfo->m_Surf.m_Points[*iEdge].y) <= 0.0099999998
      && fabs(vPoint1->z - pInfo->m_Surf.m_Points[*iEdge].z) <= 0.0099999998
      && fabs(vPoint2->x - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].x) <= 0.0099999998
      && fabs(vPoint2->y - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].y) <= 0.0099999998
      && fabs(vPoint2->z - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].z) <= 0.0099999998 )
    {
      break;
    }
    v5 = v4 + 1;
    *iEdge = v5;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070D30
// Name: void SetupEdgeNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupEdgeNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther)
{
  int v2; // edi
  float *p_z; // eax
  int v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  unsigned int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm6_4
  int v11; // ecx
  float *v12; // edx
  int v13; // ecx
  float *v14; // edx
  Vector pt[2]; // [esp+0h] [ebp-48h] BYREF
  Vector vPoint1; // [esp+18h] [ebp-30h] BYREF
  float v17; // [esp+28h] [ebp-20h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  Vector mid; // [esp+30h] [ebp-18h] BYREF
  int v20; // [esp+3Ch] [ebp-Ch]
  float *v21; // [esp+40h] [ebp-8h]
  int iNBEdge; // [esp+44h] [ebp-4h] BYREF

  v2 = 0;
  p_z = &pMain->m_Surf.m_Points[0].z;
  v4 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  v21 = &pMain->m_Surf.m_Points[0].z;
  v20 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  while ( 2 )
  {
    v5 = *(p_z - 2);
    v6 = *(p_z - 1);
    v7 = *p_z;
    v8 = 3 * ((unsigned int)&g_bEdgeNeighborFlip[v2 + v4] & 3) + 6;
    v9 = *((float *)&pMain->__vftable + v8);
    v10 = *((float *)&pMain->m_Nodes + v8);
    pt[1].z = *(&pMain->m_Elevation + v8);
    pt[0].x = v5;
    pt[0].y = v6;
    pt[0].z = v7;
    mid.x = (float)(v9 + v5) * 0.5;
    mid.y = (float)(v10 + v6) * 0.5;
    mid.z = (float)(pt[1].z + v7) * 0.5;
    pt[1].x = v9;
    pt[1].y = v10;
    v11 = 0;
    v12 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v12 - 2)) <= 0.0099999998
        && fabs(v10 - *(v12 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v12) <= 0.0099999998
        && fabs(pt[0].x - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].x) <= 0.0099999998
        && fabs(pt[0].y - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].y) <= 0.0099999998
        && fabs(pt[0].z - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].z) <= 0.0099999998 )
      {
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v11,
          nbSpan: CORNER_TO_CORNER);
        goto LABEL_27;
      }
      ++v11;
      v12 += 3;
    }
    while ( v11 < 4 );
    v17 = (float)(v6 * 2.0) - v10;
    v18 = (float)(v7 * 2.0) - pt[1].z;
    v13 = 0;
    v14 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v14 - 2)) <= 0.0099999998
        && fabs(v10 - *(v14 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v14) <= 0.0099999998
        && fabs((float)((float)(v5 * 2.0) - v9) - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].x) <= 0.0099999998
        && fabs(v17 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].y) <= 0.0099999998
        && fabs(v18 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].z) <= 0.0099999998 )
      {
        iNBEdge = v13;
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v13,
          nbSpan: CORNER_TO_MIDPOINT);
        goto LABEL_27;
      }
      ++v13;
      v14 += 3;
    }
    while ( v13 < 4 );
    iNBEdge = v13;
    vPoint1.x = (float)(v9 * 2.0) - pt[0].x;
    vPoint1.y = (float)(v10 * 2.0) - pt[0].y;
    vPoint1.z = (float)(pt[1].z * 2.0) - pt[0].z;
    if ( FindEdge(pInfo: pOther, &vPoint1, vPoint2: pt, iEdge: &iNBEdge) != 0 )
    {
      AddNeighbor(
        a1: v2,
        pMain,
        iEdge: v2,
        iSub: 0,
        span: CORNER_TO_CORNER,
        pOther,
        iNeighborEdge: iNBEdge,
        nbSpan: MIDPOINT_TO_CORNER);
    }
    else
    {
      if ( FindEdge(pInfo: pOther, vPoint1: &mid, vPoint2: pt, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: g_bEdgeNeighborFlip[v2],
          span: CORNER_TO_MIDPOINT,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
      if ( FindEdge(pInfo: pOther, vPoint1: &pt[1], vPoint2: &mid, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: !g_bEdgeNeighborFlip[v2],
          span: MIDPOINT_TO_CORNER,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
    }
LABEL_27:
    v21 += 3;
    if ( ++v2 < 4 )
    {
      v4 = v20;
      p_z = v21;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071050
// Name: void SetupCornerNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCornerNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther, int *nOverflows)
{
  CCoreDispInfo *v4; // edi
  CPowerInfo *v5; // eax
  const CVertIndex *CornerPointIndex; // ebx
  int i; // edi
  CPowerInfo *v8; // eax
  const CVertIndex *v9; // ebx
  Vector *p_m_Vert; // eax
  CDispCornerNeighbors *v11; // edi
  CDispCornerNeighbors *v12; // eax
  unsigned __int8 m_nNeighbors; // cl
  const Vector *vMainCorner; // [esp+8h] [ebp-10h]
  int iOtherSharedCorner; // [esp+Ch] [ebp-Ch]
  int iMainSharedCorner; // [esp+10h] [ebp-8h]
  int nShared; // [esp+14h] [ebp-4h]
  int iMainCorner; // [esp+24h] [ebp+Ch]

  v4 = pMain;
  if ( HasEdgeNeighbor(pMain, iNeighbor: pOther->m_nListIndex) == 0 )
  {
    nShared = 0;
    iMainSharedCorner = -1;
    iOtherSharedCorner = -1;
    iMainCorner = 0;
    while ( 1 )
    {
      v5 = (CPowerInfo *)v4->GetPowerInfo(this: v4);
      CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v5, iCorner: iMainCorner);
      vMainCorner = &v4->m_pVerts[CornerPointIndex->x
                                + *(_DWORD *)(v4->GetPowerInfo(this: v4) + 36) * CornerPointIndex->y].m_Vert;
      for ( i = 0; i < 4; ++i )
      {
        v8 = (CPowerInfo *)pOther->GetPowerInfo(this: pOther);
        v9 = CPowerInfo::GetCornerPointIndex(this: v8, iCorner: i);
        p_m_Vert = &pOther->m_pVerts[v9->x + *(_DWORD *)(pOther->GetPowerInfo(this: pOther) + 36) * v9->y].m_Vert;
        if ( fabs(vMainCorner->x - p_m_Vert->x) <= 0.001
          && fabs(vMainCorner->y - p_m_Vert->y) <= 0.001
          && fabs(vMainCorner->z - p_m_Vert->z) <= 0.001 )
        {
          ++nShared;
          iMainSharedCorner = iMainCorner;
          iOtherSharedCorner = i;
        }
      }
      if ( ++iMainCorner >= 4 )
        break;
      v4 = pMain;
    }
    if ( nShared == 1 )
    {
      v11 = pMain->GetCornerNeighbors(this: pMain, a2: iMainSharedCorner);
      v12 = pOther->GetCornerNeighbors(this: pOther, a2: iOtherSharedCorner);
      m_nNeighbors = v11->m_nNeighbors;
      if ( m_nNeighbors >= 4u || v12->m_nNeighbors >= 4u )
      {
        ++*nOverflows;
      }
      else
      {
        v11->m_Neighbors[m_nNeighbors] = pOther->m_nListIndex;
        ++v11->m_nNeighbors;
        v12->m_Neighbors[v12->m_nNeighbors++] = pMain->m_nListIndex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100711E0
// Name: bool VerifyNeighborVertConnection(class CDispUtilsHelper __near *,class CVertIndex const __near &,class CDispUtilsHelper const __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VerifyNeighborVertConnection(
        CDispUtilsHelper *pDisp,
        CVertIndex *nodeIndex,
        const CDispUtilsHelper *pTestNeighbor,
        const CVertIndex *testNeighborIndex,
        int mySide)
{
  const CDispUtilsHelper *v5; // eax
  CDispUtilsHelper *v6; // esi
  CDispUtilsHelper_vtbl *v7; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(CDispUtilsHelper *); // eax
  int v9; // eax
  int EdgeIndexFromPoint; // eax
  bool result; // al
  CVertIndex testIndex; // [esp+Ch] [ebp-8h] BYREF
  CVertIndex nbIndex; // [esp+10h] [ebp-4h] BYREF

  nbIndex.x = -1;
  nbIndex.y = -1;
  v5 = TransformIntoNeighbor(pDisp, iEdge: mySide, nodeIndex, out: &nbIndex);
  v6 = (CDispUtilsHelper *)v5;
  result = true;
  if ( v5 != nullptr )
  {
    if ( pTestNeighbor != v5 )
      return false;
    if ( nbIndex.x != testNeighborIndex->x )
      return false;
    if ( nbIndex.y != testNeighborIndex->y )
      return false;
    v7 = v5->__vftable;
    testIndex.x = -1;
    GetPowerInfo = v7->GetPowerInfo;
    testIndex.y = -1;
    v9 = (int)GetPowerInfo(this: v6);
    EdgeIndexFromPoint = GetEdgeIndexFromPoint(index: &nbIndex, iMaxPower: *(_DWORD *)(v9 + 28));
    if ( EdgeIndexFromPoint == -1
      || TransformIntoNeighbor(pDisp: v6, iEdge: EdgeIndexFromPoint, nodeIndex: &nbIndex, out: &testIndex) != pDisp
      || CVertIndex::operator!=(this: nodeIndex, other: &testIndex) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10071290
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071450
// Name: public: bool CDispEdgeIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispEdgeIterator::Next(CDispEdgeIterator *this)
{
  CVertIndex *p_m_Index; // edi
  CVertIndex *p_m_NBIndex; // ebx
  int m_iCurSub; // eax
  int m_iEdge; // ecx
  CDispUtilsHelper *v6; // eax

  this->m_It.m_Index.x += this->m_It.m_Inc.x;
  this->m_It.m_Index.y += this->m_It.m_Inc.y;
  this->m_It.m_NBIndex.x += this->m_It.m_NBInc.x;
  this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
  p_m_Index = &this->m_It.m_Index;
  p_m_NBIndex = &this->m_It.m_NBIndex;
  if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
    return 1;
  while ( 1 )
  {
    m_iCurSub = this->m_iCurSub;
    if ( m_iCurSub == 1 )
      break;
    m_iEdge = this->m_iEdge;
    this->m_iCurSub = m_iCurSub + 1;
    v6 = SetupEdgeIncrements(
           pDisp: this->m_pDisp,
           iEdge: m_iEdge,
           iSub: m_iCurSub + 1,
           myIndex: &this->m_It.m_Index,
           myInc: &this->m_It.m_Inc,
           nbIndex: &this->m_It.m_NBIndex,
           nbInc: &this->m_It.m_NBInc,
           myEnd: &this->m_It.m_End,
           iFreeDim: &this->m_It.m_FreeDim);
    this->m_It.m_pNeighbor = v6;
    if ( v6 == nullptr )
    {
      this->m_It.m_End = 0;
      this->m_It.m_Inc.x = 0;
      p_m_Index->x = 0;
      this->m_It.m_FreeDim = 0;
    }
    p_m_Index->x += this->m_It.m_Inc.x;
    this->m_It.m_Index.y += this->m_It.m_Inc.y;
    p_m_NBIndex->x += this->m_It.m_NBInc.x;
    this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
    if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071510
// Name: void VerifyNeighborConnections(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyNeighborConnections(CCoreDispInfo **ppListBase, int nDisps)
{
  char v2; // bl
  CCoreDispInfo *v3; // esi
  int v4; // edi
  _WORD *v5; // eax
  CPowerInfo *v6; // eax
  const CVertIndex *CornerPointIndex; // edi
  int p_m_Vert; // ebx
  CPowerInfo *v9; // eax
  const CVertIndex *v10; // edi
  int v11; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  CPowerInfo *v13; // eax
  const CVertIndex *v14; // edi
  int v15; // eax
  int v16; // [esp+14h] [ebp-44h]
  CDispEdgeIterator v17; // [esp+20h] [ebp-38h] BYREF
  int v18; // [esp+48h] [ebp-10h]
  int v19; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+50h] [ebp-8h]
  int v21; // [esp+54h] [ebp-4h]

  do
  {
    v2 = 1;
    v21 = 0;
    if ( nDisps <= 0 )
      break;
    v3 = *ppListBase;
    v4 = 0;
    for ( i = 0; ; i = 0 )
    {
      do
      {
        v17.m_It.m_NBIndex.x = 0;
        v17.m_It.m_Index = 0;
        v17.m_It.m_FreeDim = 0;
        v17.m_It.m_Inc.x = 0;
        v18 = 0;
        v17.m_iEdge = (int)v3;
        v17.m_iCurSub = v4;
        v17.m_It.m_pNeighbor = (CDispUtilsHelper *)-1;
        while ( CDispEdgeIterator::Next(this: (CDispEdgeIterator *)&v17.m_iEdge) != 0 )
        {
          if ( !VerifyNeighborVertConnection(
                  pDisp: v3,
                  nodeIndex: &v17.m_It.m_Inc,
                  pTestNeighbor: *(const CDispUtilsHelper **)&v17.m_It.m_Index,
                  testNeighborIndex: &v17.m_It.m_NBInc,
                  mySide: v4) )
          {
            v16 = v4;
            v5 = (_WORD *)((int (__thiscall *)(CCoreDispInfo *))v3->GetEdgeNeighbor)(a1: v3);
            *v5 = -1;
            v5[3] = -1;
            v6 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v6, iCorner: 0);
            p_m_Vert = (int)&v3->m_pVerts[CornerPointIndex->x
                                        + *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * CornerPointIndex->y].m_Vert;
            v9 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            v10 = CPowerInfo::GetCornerPointIndex(this: v9, iCorner: 0);
            v11 = *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * v10->y;
            GetPowerInfo = v3->GetPowerInfo;
            v19 = (int)&v3->m_pVerts[v10->x + v11].m_Vert;
            v13 = (CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, _DWORD))GetPowerInfo)(a1: v3, a2: 0);
            v14 = CPowerInfo::GetCornerPointIndex(this: v13, iCorner: v16);
            v15 = v3->GetPowerInfo(this: v3);
            _Warning(
              a1: "Warning: invalid neighbor connection on displacement near (%.2f %.2f %.2f)\n",
              v3->m_pVerts[v14->x + *(_DWORD *)(v15 + 36) * v14->y].m_Vert.x,
              *(float *)(v19 + 4),
              *(float *)(p_m_Vert + 8));
            v2 = 0;
            v4 = i;
          }
        }
        i = ++v4;
      }
      while ( v4 < 4 );
      if ( ++v21 >= nDisps )
        break;
      v3 = ppListBase[v21];
      v4 = 0;
    }
  }
  while ( v2 == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x100716F0
// Name: bool IsVertAllowed(class CDispUtilsHelper __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsVertAllowed(CDispUtilsHelper *pDisp, CVertIndex sideVert, int iLevel)
{
  int v4; // eax
  const CVertIndex *v5; // edi
  int v6; // ecx
  __int16 v7; // ax
  int v8; // edx
  int v9; // ecx
  __int16 v10; // ax
  __int16 y; // cx
  int SubNeighborIndex; // edi
  CDispSubNeighbor *v14; // ebx
  CDispUtilsHelper *v15; // edi
  CShiftInfo *v16; // ebx
  int v17; // eax
  int v18; // eax
  int iSub; // [esp+8h] [ebp-4h]
  int iSide; // [esp+14h] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = (const CVertIndex *)sideVert;
  v6 = *(_DWORD *)(v4 + 36);
  if ( *(_WORD *)sideVert.x == 0 )
  {
    v7 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v7 != 0 && v7 != v6 - 1 )
      goto LABEL_4;
    return true;
  }
  v9 = v6 - 1;
  if ( *(__int16 *)sideVert.x == v9 )
  {
    v10 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v10 == 0 || v10 == v9 )
      return true;
  }
LABEL_4:
  v8 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  if ( v5->x != 0 )
  {
    y = v5->y;
    if ( y == v8 )
    {
      iSide = 1;
    }
    else if ( v5->x == v8 )
    {
      iSide = 2;
    }
    else
    {
      if ( y != 0 )
        return true;
      iSide = 3;
    }
  }
  else
  {
    iSide = 0;
  }
  SubNeighborIndex = GetSubNeighborIndex(pDisp, iEdge: iSide, nodeIndex: v5);
  iSub = SubNeighborIndex;
  if ( SubNeighborIndex == -1 )
    return true;
  v14 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iSide)->m_SubNeighbors[SubNeighborIndex];
  v15 = pDisp->GetDispUtilsByIndex(this: pDisp, a2: v14->m_iNeighbor);
  v16 = &g_ShiftInfos[v14->m_Span][v14->m_NeighborSpan];
  v17 = v15->GetPowerInfo(this: v15);
  if ( v16->m_PowerShiftAdd + *(_DWORD *)(v17 + 28) < iLevel + 1 )
    return false;
  TransformIntoSubNeighbor(
    pDisp,
    iEdge: iSide,
    (CVertIndex)iSub,
    nodeIndex: *(const CVertIndex **)&sideVert,
    out: &sideVert);
  v18 = v15->GetPowerInfo(this: v15);
  return ((int)v15[((unsigned int)(sideVert.x + *(_DWORD *)(v18 + 36) * sideVert.y) >> 5) + 200].__vftable
        & (1 << ((LOBYTE(sideVert.x) + *(_BYTE *)(v18 + 36) * LOBYTE(sideVert.y)) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10071860
// Name: void UnallowVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnallowVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int *nUnallowed)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  const CVertIndex *v8; // eax
  int pDispa; // [esp+Ch] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = nodeIndex->x + *(_DWORD *)(v4 + 36) * nodeIndex->y;
  v6 = 1 << ((nodeIndex->x + *(_BYTE *)(v4 + 36) * nodeIndex->y) & 0x1F);
  if ( (v6 & (int)pDisp[((unsigned int)v5 >> 5) + 200].__vftable) != 0 )
  {
    ++*nUnallowed;
    pDisp[(v5 >> 5) + 200].__vftable = (CDispUtilsHelper_vtbl *)((int)pDisp[(v5 >> 5) + 200].__vftable & ~v6);
    v7 = 42 * v5 + 12;
    for ( pDispa = 4; pDispa != 0; --pDispa )
    {
      v8 = (const CVertIndex *)(v7 + *(_DWORD *)pDisp->GetPowerInfo(this: pDisp));
      if ( v8->x != -1 && v8[1].x == -1 )
        UnallowVerts_R(pDisp, nodeIndex: v8, nUnallowed);
      v7 += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071900
// Name: void DisableUnallowedVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableUnallowedVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int iLevel, int *nUnallowed)
{
  const CVertIndex *v5; // ebx
  const CVertIndex *v6; // edi
  int v7; // ebx
  const CVertIndex *v8; // edi
  int v9; // eax
  int pDispa; // [esp+14h] [ebp+8h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+Ch]
  int iLevela; // [esp+1Ch] [ebp+10h]

  nodeIndexa = (const CVertIndex *)(16
                                  * (nodeIndex->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * nodeIndex->y));
  v5 = nodeIndexa;
  for ( pDispa = 4; pDispa != 0; --pDispa )
  {
    v6 = (const CVertIndex *)((char *)v5 + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 4));
    if ( !IsVertAllowed(pDisp, sideVert: (CVertIndex)v6, iLevel) )
      UnallowVerts_R(pDisp, nodeIndex: v6, nUnallowed);
    ++v5;
  }
  v7 = iLevel + 1;
  if ( iLevel + 1 < *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28) )
  {
    v8 = nodeIndexa;
    for ( iLevela = 4; iLevela != 0; --iLevela )
    {
      v9 = pDisp->GetPowerInfo(this: pDisp);
      DisableUnallowedVerts_R(
        pDisp,
        nodeIndex: (const CVertIndex *)((char *)v8++ + *(_DWORD *)(v9 + 8)),
        iLevel: v7,
        nUnallowed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100719B0
// Name: void SetupAllowedVerts(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupAllowedVerts(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // edx
  CBitVec<289> *p_m_AllowedVerts; // eax
  int v5; // edi
  CCoreDispInfo *v6; // esi
  const CVertIndex *v7; // eax
  int nUnallowed; // [esp+Ch] [ebp-4h] BYREF
  char bContinue_3; // [esp+1Fh] [ebp+Fh]

  for ( i = 0; i < nListSize; ++i )
  {
    p_m_AllowedVerts = &ppListBase[i]->m_AllowedVerts;
    if ( ppListBase[i] != (CCoreDispInfo *)-800 )
    {
      p_m_AllowedVerts->m_Ints[0] = -1;
      p_m_AllowedVerts->m_Ints[1] = -1;
      p_m_AllowedVerts->m_Ints[2] = -1;
      p_m_AllowedVerts->m_Ints[3] = -1;
      p_m_AllowedVerts->m_Ints[4] = -1;
      p_m_AllowedVerts->m_Ints[5] = -1;
      p_m_AllowedVerts->m_Ints[6] = -1;
      p_m_AllowedVerts->m_Ints[7] = -1;
      p_m_AllowedVerts->m_Ints[8] = -1;
      p_m_AllowedVerts->m_Ints[9] = -1;
    }
  }
  do
  {
    v5 = 0;
    bContinue_3 = 0;
    if ( nListSize <= 0 )
      break;
    do
    {
      v6 = ppListBase[v5];
      nUnallowed = 0;
      v7 = (const CVertIndex *)v6->GetPowerInfo(this: v6);
      DisableUnallowedVerts_R(pDisp: v6, nodeIndex: v7 + 8, iLevel: 0, &nUnallowed);
      if ( nUnallowed != 0 )
        bContinue_3 = 1;
      ++v5;
    }
    while ( v5 < nListSize );
  }
  while ( bContinue_3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10071A50
// Name: void FindNeighboringDispSurfs(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindNeighboringDispSurfs(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // ebx
  CCoreDispInfo *v3; // edi
  int i; // esi
  CDispNeighbor *v5; // eax
  int v6; // eax
  int m_Size; // eax
  unsigned __int8 *m_pMemory; // esi
  int v9; // edx
  CDispBox *v10; // edi
  int v11; // edx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  float *v15; // ecx
  CCoreDispInfo *v16; // ebx
  bool v17; // zf
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > boxes; // [esp+Ch] [ebp-30h] BYREF
  CCoreDispInfo *pOther; // [esp+20h] [ebp-1Ch]
  int nCornerOverflows; // [esp+24h] [ebp-18h] BYREF
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  CCoreDispInfo *pMain; // [esp+30h] [ebp-Ch]
  CCoreDispInfo **v24; // [esp+34h] [ebp-8h]
  int iDisp; // [esp+38h] [ebp-4h]

  v2 = nListSize;
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    v3 = ppListBase[iDisp];
    for ( i = 0; i < 4; ++i )
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: i);
      v5->m_SubNeighbors[0].m_iNeighbor = -1;
      v5->m_SubNeighbors[1].m_iNeighbor = -1;
      v6 = (int)v3->GetCornerNeighbors(this: v3, a2: i);
      *(_BYTE *)(v6 + 8) = 0;
    }
  }
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&boxes, 0, sizeof(boxes));
  if ( nListSize != 0 )
  {
    if ( nListSize > 0 )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&boxes,
        num: nListSize);
      m_Size = boxes.m_Size;
      m_pMemory = (unsigned __int8 *)boxes.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 && nListSize > 0 )
      _V_memmove(dest: &m_pMemory[24 * nListSize], src: m_pMemory, count: 24 * m_Size);
  }
  v9 = 0;
  if ( nListSize > 0 )
  {
    v10 = (CDispBox *)m_pMemory;
    do
    {
      GetDispBox(pDisp: ppListBase[v9], box: v10);
      v9 = v11 + 1;
      ++v10;
    }
    while ( v9 < nListSize );
  }
  nCornerOverflows = 0;
  if ( nListSize > 0 )
  {
    v12 = 1;
    v22 = 1;
    iDisp = (int)m_pMemory;
    v24 = ppListBase;
    v21 = nListSize;
    do
    {
      pMain = *v24;
      if ( v12 < v2 )
      {
        v13 = iDisp + 24;
        do
        {
          pOther = ppListBase[v12];
          v14 = 0;
          v15 = (float *)(v13 + 12);
          while ( *(v15 - 3) <= *(float *)((char *)v15 + iDisp - v13) )
          {
            if ( *(float *)(iDisp + 4 * v14) > *v15 )
              goto LABEL_24;
            ++v14;
            ++v15;
            if ( v14 >= 3 )
            {
              v16 = pOther;
              SetupEdgeNeighbors(pMain, pOther);
              SetupCornerNeighbors(pMain, pOther: v16, nOverflows: &nCornerOverflows);
LABEL_24:
              v2 = nListSize;
              break;
            }
            v2 = nListSize;
          }
          ++v12;
          v13 += 24;
        }
        while ( v12 < v2 );
        v12 = v22;
        m_pMemory = (unsigned __int8 *)boxes.m_Memory.m_pMemory;
      }
      ++v24;
      iDisp += 24;
      ++v12;
      v17 = v21-- == 1;
      v22 = v12;
    }
    while ( !v17 );
    if ( nCornerOverflows != 0 )
      _Warning(a1: "Warning: overflowed %d displacement corner-neighbor lists.", nCornerOverflows);
  }
  VerifyNeighborConnections(ppListBase, nDisps: v2);
  if ( boxes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0040A850
// Name: public: bool CVertIndex::operator!=(class CVertIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVertIndex::operator!=(CVertIndex *this, const CVertIndex *other)
{
  return this->x != other->x || this->y != other->y;
}

//------------------------------------------------------------------------------
// Address: 0x0040A880
// Name: void VectorMin(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMin(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x > b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y > b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z > b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x0040A900
// Name: void VectorMax(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorMax(const Vector *a, const Vector *b, Vector *result)
{
  double x; // xmm0_8
  float v4; // xmm0_4
  double y; // xmm0_8
  float v6; // xmm0_4
  double z; // xmm0_8

  x = a->x;
  if ( x < b->x )
    x = b->x;
  v4 = x;
  result->x = v4;
  y = a->y;
  if ( y < b->y )
    y = b->y;
  v6 = y;
  result->y = v6;
  z = a->z;
  if ( z < b->z )
    z = b->z;
  result->z = z;
}

//------------------------------------------------------------------------------
// Address: 0x0040A980
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040A990
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A9A0
// Name: public: void CCoreDispSurface::GetPoint(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetPoint(CCoreDispSurface *this, int index, Vector *pt)
{
  *pt = this->m_Points[index];
}

//------------------------------------------------------------------------------
// Address: 0x0040A9D0
// Name: public: class CCoreDispSurface __near * CCoreDispInfo::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CCoreDispInfo::GetSurface(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x0040A9E0
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040AA30
// Name: int GetSubNeighborIndex(class CDispUtilsHelper __near *,int,class CVertIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSubNeighborIndex(CDispUtilsHelper *pDisp, int iEdge, const CVertIndex *nodeIndex)
{
  int v3; // edi
  CDispNeighbor *v4; // eax
  int v5; // edx
  CDispNeighbor *v6; // esi
  int v7; // ecx
  int result; // eax

  v3 = pDisp->GetPowerInfo(this: pDisp);
  v4 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  v5 = *(_DWORD *)(v3 + 44);
  v6 = v4;
  v7 = *(&nodeIndex->x + (g_EdgeDims[iEdge] == 0));
  result = 0;
  if ( v7 == v5 )
  {
    if ( v6->m_SubNeighbors[0].m_Span != 0 )
      return -1;
  }
  else
  {
    result = v7 > v5;
  }
  if ( v6->m_SubNeighbors[result].m_iNeighbor == 0xFFFF )
  {
    if ( result == 1 && v6->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v6->m_SubNeighbors[0].m_Span == 0 )
      return 0;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040AAB0
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x0040AB40
// Name: void GetDispBox(class CCoreDispInfo __near *,class CDispBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDispBox(CCoreDispInfo *pDisp, CDispBox *box)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *p_z; // eax
  int i; // ecx
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  double v14; // xmm0_8
  float v15; // xmm0_4
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float vMax; // [esp+0h] [ebp-Ch]

  v2 = (__m128)0x6753C21Cu;
  v3 = (__m128)0xE753C21C;
  v4 = 1.0e24;
  v5 = 1.0e24;
  vMax = -1.0e24;
  v6 = -1.0e24;
  p_z = &pDisp->m_Surf.m_Points[0].z;
  for ( i = 4; i != 0; --i )
  {
    v9 = *(p_z - 2);
    if ( v9 > v4 )
      v9 = v4;
    v4 = v9;
    v10 = *(p_z - 1);
    if ( v10 > v5 )
      v10 = v5;
    v11 = (__m128)*(unsigned int *)p_z;
    v5 = v10;
    v12 = _mm_cvtps_pd(v11);
    v13 = _mm_cvtps_pd(v2);
    if ( v12.m128d_f64[0] > v13.m128d_f64[0] )
      v12 = v13;
    v2 = _mm_cvtpd_ps(v12);
    v14 = *(p_z - 2);
    if ( v14 < vMax )
      v14 = vMax;
    v15 = v14;
    vMax = v15;
    v16 = _mm_cvtps_pd((__m128)*((unsigned int *)p_z - 1));
    v17 = _mm_cvtps_pd(v3);
    if ( v16.m128d_f64[0] < v17.m128d_f64[0] )
      v16 = v17;
    v3 = _mm_cvtpd_ps(v16);
    v18 = v11.m128_f32[0];
    if ( v11.m128_f32[0] < (double)v6 )
      v18 = v6;
    p_z += 3;
    v6 = v18;
  }
  v19 = flPuff;
  v20 = v5 - flPuff;
  v21 = v2.m128_f32[0] - flPuff;
  v22 = flPuff + vMax;
  v23 = v3.m128_f32[0] + flPuff;
  box->m_Min.x = v4 - flPuff;
  box->m_Min.y = v20;
  box->m_Min.z = v21;
  box->m_Max.x = v22;
  box->m_Max.y = v23;
  box->m_Max.z = v19 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x0040AC90
// Name: void AddNeighbor(class CCoreDispInfo __near *,int,int,enum NeighborSpan,class CCoreDispInfo __near *,int,enum NeighborSpan)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddNeighbor(
        int a1@<edi>,
        CCoreDispInfo *pMain,
        int iEdge,
        int iSub,
        NeighborSpan span,
        CCoreDispInfo *pOther,
        int iNeighborEdge,
        NeighborSpan nbSpan)
{
  NeighborSpan v8; // ebx
  int v9; // esi
  CDispNeighbor *v10; // eax
  unsigned __int8 v11; // dl

  if ( g_bEdgeNeighborFlip[iEdge] )
    span = g_SpanFlip[span];
  if ( g_bEdgeNeighborFlip[iNeighborEdge] )
    v8 = g_SpanFlip[nbSpan];
  else
    v8 = nbSpan;
  v9 = ((int (__thiscall *)(CCoreDispInfo *, int, int))pMain->GetEdgeNeighbor)(a1: pMain, a2: iEdge, a3: a1) + 6 * iSub;
  if ( v8 == MIDPOINT_TO_CORNER )
    v10 = (CDispNeighbor *)&pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge)->m_SubNeighbors[1];
  else
    v10 = pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge);
  if ( *(_WORD *)v9 == 0xFFFF && v10->m_SubNeighbors[0].m_iNeighbor == 0xFFFF )
  {
    *(_WORD *)v9 = pOther->m_nListIndex;
    *(_BYTE *)(v9 + 2) = g_CoreDispNeighborOrientationMap[iEdge][iNeighborEdge];
    *(_BYTE *)(v9 + 4) = v8;
    *(_BYTE *)(v9 + 3) = span;
    v10->m_SubNeighbors[0].m_iNeighbor = pMain->m_nListIndex;
    v11 = g_CoreDispNeighborOrientationMap[iNeighborEdge][iEdge];
    v10->m_SubNeighbors[0].m_Span = v8;
    v10->m_SubNeighbors[0].m_NeighborOrientation = v11;
    v10->m_SubNeighbors[0].m_NeighborSpan = span;
  }
  else if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "Found a displacement edge abutting multiple other edges.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AD90
// Name: bool HasEdgeNeighbor(class CCoreDispInfo const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasEdgeNeighbor(const CCoreDispInfo *pMain, int iNeighbor)
{
  int v2; // ebx
  int v3; // esi
  CDispNeighbor *m_EdgeNeighbors; // edi
  CDispCornerNeighbors *i; // ecx
  int v6; // eax

  v2 = iNeighbor;
  v3 = 0;
  m_EdgeNeighbors = pMain->m_Surf.m_EdgeNeighbors;
  for ( i = pMain->m_Surf.m_CornerNeighbors; ; ++i )
  {
    v6 = 0;
    if ( i->m_nNeighbors != 0 )
      break;
LABEL_6:
    if ( m_EdgeNeighbors->m_SubNeighbors[0].m_iNeighbor == v2 || m_EdgeNeighbors->m_SubNeighbors[1].m_iNeighbor == v2 )
      return 1;
    ++v3;
    ++m_EdgeNeighbors;
    if ( v3 >= 4 )
      return 0;
  }
  while ( i->m_Neighbors[v6] != iNeighbor )
  {
    if ( ++v6 >= i->m_nNeighbors )
    {
      v2 = iNeighbor;
      goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040AE00
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x0040AF10
// Name: class CDispUtilsHelper __near * TransformIntoNeighbor(class CDispUtilsHelper __near *,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v4; // esi
  int v5; // edx
  __int16 y; // cx
  CVertIndex SubNeighborIndex; // eax

  v4 = iEdge;
  if ( iEdge == -1 )
  {
    v5 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
    if ( nodeIndex->x != 0 )
    {
      y = nodeIndex->y;
      if ( y == v5 )
      {
        v4 = 1;
      }
      else if ( nodeIndex->x == v5 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 4 * (y == 0) - 1;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  SubNeighborIndex = (CVertIndex)GetSubNeighborIndex(pDisp, iEdge: v4, nodeIndex);
  if ( SubNeighborIndex == -1 )
    return nullptr;
  else
    return TransformIntoSubNeighbor(pDisp, iEdge: v4, iSub: SubNeighborIndex, nodeIndex, out);
}

//------------------------------------------------------------------------------
// Address: 0x0040AFA0
// Name: bool FindEdge(class CCoreDispInfo __near *,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEdge(CCoreDispInfo *pInfo, const Vector *vPoint1, const Vector *vPoint2, int *iEdge)
{
  int v4; // ecx
  int v5; // ecx

  *iEdge = 0;
  while ( 1 )
  {
    v4 = *iEdge;
    if ( fabs(vPoint1->x - pInfo->m_Surf.m_Points[*iEdge].x) <= 0.0099999998
      && fabs(vPoint1->y - pInfo->m_Surf.m_Points[*iEdge].y) <= 0.0099999998
      && fabs(vPoint1->z - pInfo->m_Surf.m_Points[*iEdge].z) <= 0.0099999998
      && fabs(vPoint2->x - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].x) <= 0.0099999998
      && fabs(vPoint2->y - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].y) <= 0.0099999998
      && fabs(vPoint2->z - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].z) <= 0.0099999998 )
    {
      break;
    }
    v5 = v4 + 1;
    *iEdge = v5;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B070
// Name: void SetupEdgeNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupEdgeNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther)
{
  int v2; // edi
  float *p_z; // eax
  int v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  unsigned int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm6_4
  int v11; // ecx
  float *v12; // edx
  int v13; // ecx
  float *v14; // edx
  Vector pt[2]; // [esp+0h] [ebp-48h] BYREF
  Vector vPoint1; // [esp+18h] [ebp-30h] BYREF
  float v17; // [esp+28h] [ebp-20h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  Vector mid; // [esp+30h] [ebp-18h] BYREF
  int v20; // [esp+3Ch] [ebp-Ch]
  float *v21; // [esp+40h] [ebp-8h]
  int iNBEdge; // [esp+44h] [ebp-4h] BYREF

  v2 = 0;
  p_z = &pMain->m_Surf.m_Points[0].z;
  v4 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  v21 = &pMain->m_Surf.m_Points[0].z;
  v20 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  while ( 2 )
  {
    v5 = *(p_z - 2);
    v6 = *(p_z - 1);
    v7 = *p_z;
    v8 = 3 * ((unsigned int)&g_bEdgeNeighborFlip[v2 + v4] & 3) + 6;
    v9 = *((float *)&pMain->__vftable + v8);
    v10 = *((float *)&pMain->m_Nodes + v8);
    pt[1].z = *(&pMain->m_Elevation + v8);
    pt[0].x = v5;
    pt[0].y = v6;
    pt[0].z = v7;
    mid.x = (float)(v9 + v5) * 0.5;
    mid.y = (float)(v10 + v6) * 0.5;
    mid.z = (float)(pt[1].z + v7) * 0.5;
    pt[1].x = v9;
    pt[1].y = v10;
    v11 = 0;
    v12 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v12 - 2)) <= 0.0099999998
        && fabs(v10 - *(v12 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v12) <= 0.0099999998
        && fabs(pt[0].x - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].x) <= 0.0099999998
        && fabs(pt[0].y - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].y) <= 0.0099999998
        && fabs(pt[0].z - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].z) <= 0.0099999998 )
      {
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v11,
          nbSpan: CORNER_TO_CORNER);
        goto LABEL_27;
      }
      ++v11;
      v12 += 3;
    }
    while ( v11 < 4 );
    v17 = (float)(v6 * 2.0) - v10;
    v18 = (float)(v7 * 2.0) - pt[1].z;
    v13 = 0;
    v14 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v14 - 2)) <= 0.0099999998
        && fabs(v10 - *(v14 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v14) <= 0.0099999998
        && fabs((float)((float)(v5 * 2.0) - v9) - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].x) <= 0.0099999998
        && fabs(v17 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].y) <= 0.0099999998
        && fabs(v18 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].z) <= 0.0099999998 )
      {
        iNBEdge = v13;
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v13,
          nbSpan: CORNER_TO_MIDPOINT);
        goto LABEL_27;
      }
      ++v13;
      v14 += 3;
    }
    while ( v13 < 4 );
    iNBEdge = v13;
    vPoint1.x = (float)(v9 * 2.0) - pt[0].x;
    vPoint1.y = (float)(v10 * 2.0) - pt[0].y;
    vPoint1.z = (float)(pt[1].z * 2.0) - pt[0].z;
    if ( FindEdge(pInfo: pOther, &vPoint1, vPoint2: pt, iEdge: &iNBEdge) != 0 )
    {
      AddNeighbor(
        a1: v2,
        pMain,
        iEdge: v2,
        iSub: 0,
        span: CORNER_TO_CORNER,
        pOther,
        iNeighborEdge: iNBEdge,
        nbSpan: MIDPOINT_TO_CORNER);
    }
    else
    {
      if ( FindEdge(pInfo: pOther, vPoint1: &mid, vPoint2: pt, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: g_bEdgeNeighborFlip[v2],
          span: CORNER_TO_MIDPOINT,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
      if ( FindEdge(pInfo: pOther, vPoint1: &pt[1], vPoint2: &mid, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: !g_bEdgeNeighborFlip[v2],
          span: MIDPOINT_TO_CORNER,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
    }
LABEL_27:
    v21 += 3;
    if ( ++v2 < 4 )
    {
      v4 = v20;
      p_z = v21;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B390
// Name: void SetupCornerNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCornerNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther, int *nOverflows)
{
  CCoreDispInfo *v4; // edi
  CPowerInfo *v5; // eax
  const CVertIndex *CornerPointIndex; // ebx
  int i; // edi
  CPowerInfo *v8; // eax
  const CVertIndex *v9; // ebx
  Vector *p_m_Vert; // eax
  CDispCornerNeighbors *v11; // edi
  CDispCornerNeighbors *v12; // eax
  unsigned __int8 m_nNeighbors; // cl
  const Vector *vMainCorner; // [esp+8h] [ebp-10h]
  int iOtherSharedCorner; // [esp+Ch] [ebp-Ch]
  int iMainSharedCorner; // [esp+10h] [ebp-8h]
  int nShared; // [esp+14h] [ebp-4h]
  int iMainCorner; // [esp+24h] [ebp+Ch]

  v4 = pMain;
  if ( HasEdgeNeighbor(pMain, iNeighbor: pOther->m_nListIndex) == 0 )
  {
    nShared = 0;
    iMainSharedCorner = -1;
    iOtherSharedCorner = -1;
    iMainCorner = 0;
    while ( 1 )
    {
      v5 = (CPowerInfo *)v4->GetPowerInfo(this: v4);
      CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v5, iCorner: iMainCorner);
      vMainCorner = &v4->m_pVerts[CornerPointIndex->x
                                + *(_DWORD *)(v4->GetPowerInfo(this: v4) + 36) * CornerPointIndex->y].m_Vert;
      for ( i = 0; i < 4; ++i )
      {
        v8 = (CPowerInfo *)pOther->GetPowerInfo(this: pOther);
        v9 = CPowerInfo::GetCornerPointIndex(this: v8, iCorner: i);
        p_m_Vert = &pOther->m_pVerts[v9->x + *(_DWORD *)(pOther->GetPowerInfo(this: pOther) + 36) * v9->y].m_Vert;
        if ( fabs(vMainCorner->x - p_m_Vert->x) <= 0.001
          && fabs(vMainCorner->y - p_m_Vert->y) <= 0.001
          && fabs(vMainCorner->z - p_m_Vert->z) <= 0.001 )
        {
          ++nShared;
          iMainSharedCorner = iMainCorner;
          iOtherSharedCorner = i;
        }
      }
      if ( ++iMainCorner >= 4 )
        break;
      v4 = pMain;
    }
    if ( nShared == 1 )
    {
      v11 = pMain->GetCornerNeighbors(this: pMain, a2: iMainSharedCorner);
      v12 = pOther->GetCornerNeighbors(this: pOther, a2: iOtherSharedCorner);
      m_nNeighbors = v11->m_nNeighbors;
      if ( m_nNeighbors >= 4u || v12->m_nNeighbors >= 4u )
      {
        ++*nOverflows;
      }
      else
      {
        v11->m_Neighbors[m_nNeighbors] = pOther->m_nListIndex;
        ++v11->m_nNeighbors;
        v12->m_Neighbors[v12->m_nNeighbors++] = pMain->m_nListIndex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B520
// Name: bool VerifyNeighborVertConnection(class CDispUtilsHelper __near *,class CVertIndex const __near &,class CDispUtilsHelper const __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VerifyNeighborVertConnection(
        CDispUtilsHelper *pDisp,
        CVertIndex *nodeIndex,
        const CDispUtilsHelper *pTestNeighbor,
        const CVertIndex *testNeighborIndex,
        int mySide)
{
  const CDispUtilsHelper *v5; // eax
  CDispUtilsHelper *v6; // esi
  CDispUtilsHelper_vtbl *v7; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(CDispUtilsHelper *); // eax
  int v9; // eax
  int EdgeIndexFromPoint; // eax
  bool result; // al
  CVertIndex testIndex; // [esp+Ch] [ebp-8h] BYREF
  CVertIndex nbIndex; // [esp+10h] [ebp-4h] BYREF

  nbIndex.x = -1;
  nbIndex.y = -1;
  v5 = TransformIntoNeighbor(pDisp, iEdge: mySide, nodeIndex, out: &nbIndex);
  v6 = (CDispUtilsHelper *)v5;
  result = true;
  if ( v5 != nullptr )
  {
    if ( pTestNeighbor != v5 )
      return false;
    if ( nbIndex.x != testNeighborIndex->x )
      return false;
    if ( nbIndex.y != testNeighborIndex->y )
      return false;
    v7 = v5->__vftable;
    testIndex.x = -1;
    GetPowerInfo = v7->GetPowerInfo;
    testIndex.y = -1;
    v9 = (int)GetPowerInfo(this: v6);
    EdgeIndexFromPoint = GetEdgeIndexFromPoint(index: &nbIndex, iMaxPower: *(_DWORD *)(v9 + 28));
    if ( EdgeIndexFromPoint == -1
      || TransformIntoNeighbor(pDisp: v6, iEdge: EdgeIndexFromPoint, nodeIndex: &nbIndex, out: &testIndex) != pDisp
      || CVertIndex::operator!=(this: nodeIndex, other: &testIndex) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B5D0
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B790
// Name: public: bool CDispEdgeIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispEdgeIterator::Next(CDispEdgeIterator *this)
{
  CVertIndex *p_m_Index; // edi
  CVertIndex *p_m_NBIndex; // ebx
  int m_iCurSub; // eax
  int m_iEdge; // ecx
  CDispUtilsHelper *v6; // eax

  this->m_It.m_Index.x += this->m_It.m_Inc.x;
  this->m_It.m_Index.y += this->m_It.m_Inc.y;
  this->m_It.m_NBIndex.x += this->m_It.m_NBInc.x;
  this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
  p_m_Index = &this->m_It.m_Index;
  p_m_NBIndex = &this->m_It.m_NBIndex;
  if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
    return 1;
  while ( 1 )
  {
    m_iCurSub = this->m_iCurSub;
    if ( m_iCurSub == 1 )
      break;
    m_iEdge = this->m_iEdge;
    this->m_iCurSub = m_iCurSub + 1;
    v6 = SetupEdgeIncrements(
           pDisp: this->m_pDisp,
           iEdge: m_iEdge,
           iSub: m_iCurSub + 1,
           myIndex: &this->m_It.m_Index,
           myInc: &this->m_It.m_Inc,
           nbIndex: &this->m_It.m_NBIndex,
           nbInc: &this->m_It.m_NBInc,
           myEnd: &this->m_It.m_End,
           iFreeDim: &this->m_It.m_FreeDim);
    this->m_It.m_pNeighbor = v6;
    if ( v6 == nullptr )
    {
      this->m_It.m_End = 0;
      this->m_It.m_Inc.x = 0;
      p_m_Index->x = 0;
      this->m_It.m_FreeDim = 0;
    }
    p_m_Index->x += this->m_It.m_Inc.x;
    this->m_It.m_Index.y += this->m_It.m_Inc.y;
    p_m_NBIndex->x += this->m_It.m_NBInc.x;
    this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
    if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B850
// Name: void VerifyNeighborConnections(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyNeighborConnections(CCoreDispInfo **ppListBase, int nDisps)
{
  char v2; // bl
  CCoreDispInfo *v3; // esi
  int v4; // edi
  _WORD *v5; // eax
  CPowerInfo *v6; // eax
  const CVertIndex *CornerPointIndex; // edi
  int p_m_Vert; // ebx
  CPowerInfo *v9; // eax
  const CVertIndex *v10; // edi
  int v11; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  CPowerInfo *v13; // eax
  const CVertIndex *v14; // edi
  int v15; // eax
  int v16; // [esp+18h] [ebp-44h]
  CDispEdgeIterator it; // [esp+28h] [ebp-34h] BYREF
  int v18; // [esp+50h] [ebp-Ch]
  int iEdge; // [esp+54h] [ebp-8h]
  int iDisp; // [esp+58h] [ebp-4h]

  do
  {
    v2 = 1;
    iDisp = 0;
    if ( nDisps <= 0 )
      break;
    v3 = *ppListBase;
    v4 = 0;
    for ( iEdge = 0; ; iEdge = 0 )
    {
      do
      {
        it.m_It.m_Inc.x = 0;
        it.m_It.m_pNeighbor = nullptr;
        it.m_It.m_End = 0;
        it.m_It.m_Index.x = 0;
        it.m_It.m_FreeDim = 0;
        it.m_pDisp = v3;
        it.m_iEdge = v4;
        it.m_iCurSub = -1;
        while ( CDispEdgeIterator::Next(this: &it) != 0 )
        {
          if ( !VerifyNeighborVertConnection(
                  pDisp: v3,
                  nodeIndex: &it.m_It.m_Index,
                  pTestNeighbor: it.m_It.m_pNeighbor,
                  testNeighborIndex: &it.m_It.m_NBIndex,
                  mySide: v4) )
          {
            v16 = v4;
            v5 = (_WORD *)((int (__thiscall *)(CCoreDispInfo *))v3->GetEdgeNeighbor)(a1: v3);
            *v5 = -1;
            v5[3] = -1;
            v6 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v6, iCorner: 0);
            p_m_Vert = (int)&v3->m_pVerts[CornerPointIndex->x
                                        + *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * CornerPointIndex->y].m_Vert;
            v9 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            v10 = CPowerInfo::GetCornerPointIndex(this: v9, iCorner: 0);
            v11 = *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * v10->y;
            GetPowerInfo = v3->GetPowerInfo;
            v18 = (int)&v3->m_pVerts[v10->x + v11].m_Vert;
            v13 = (CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, _DWORD))GetPowerInfo)(a1: v3, a2: 0);
            v14 = CPowerInfo::GetCornerPointIndex(this: v13, iCorner: v16);
            v15 = v3->GetPowerInfo(this: v3);
            _Warning(
              a1: "Warning: invalid neighbor connection on displacement near (%.2f %.2f %.2f)\n",
              v3->m_pVerts[v14->x + *(_DWORD *)(v15 + 36) * v14->y].m_Vert.x,
              *(float *)(v18 + 4),
              *(float *)(p_m_Vert + 8));
            v2 = 0;
            v4 = iEdge;
          }
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      if ( ++iDisp >= nDisps )
        break;
      v3 = ppListBase[iDisp];
      v4 = 0;
    }
  }
  while ( v2 == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0040BA30
// Name: bool IsVertAllowed(class CDispUtilsHelper __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsVertAllowed(CDispUtilsHelper *pDisp, CVertIndex sideVert, int iLevel)
{
  int v4; // eax
  const CVertIndex *v5; // edi
  int v6; // ecx
  __int16 v7; // ax
  int v8; // edx
  int v9; // ecx
  __int16 v10; // ax
  __int16 y; // cx
  int SubNeighborIndex; // edi
  CDispSubNeighbor *v14; // ebx
  CDispUtilsHelper *v15; // edi
  CShiftInfo *v16; // ebx
  int v17; // eax
  int v18; // eax
  int iSub; // [esp+8h] [ebp-4h]
  int iSide; // [esp+14h] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = (const CVertIndex *)sideVert;
  v6 = *(_DWORD *)(v4 + 36);
  if ( *(_WORD *)sideVert.x == 0 )
  {
    v7 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v7 != 0 && v7 != v6 - 1 )
      goto LABEL_4;
    return true;
  }
  v9 = v6 - 1;
  if ( *(__int16 *)sideVert.x == v9 )
  {
    v10 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v10 == 0 || v10 == v9 )
      return true;
  }
LABEL_4:
  v8 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  if ( v5->x != 0 )
  {
    y = v5->y;
    if ( y == v8 )
    {
      iSide = 1;
    }
    else if ( v5->x == v8 )
    {
      iSide = 2;
    }
    else
    {
      if ( y != 0 )
        return true;
      iSide = 3;
    }
  }
  else
  {
    iSide = 0;
  }
  SubNeighborIndex = GetSubNeighborIndex(pDisp, iEdge: iSide, nodeIndex: v5);
  iSub = SubNeighborIndex;
  if ( SubNeighborIndex == -1 )
    return true;
  v14 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iSide)->m_SubNeighbors[SubNeighborIndex];
  v15 = pDisp->GetDispUtilsByIndex(this: pDisp, a2: v14->m_iNeighbor);
  v16 = &g_ShiftInfos[v14->m_Span][v14->m_NeighborSpan];
  v17 = v15->GetPowerInfo(this: v15);
  if ( v16->m_PowerShiftAdd + *(_DWORD *)(v17 + 28) < iLevel + 1 )
    return false;
  TransformIntoSubNeighbor(
    pDisp,
    iEdge: iSide,
    (CVertIndex)iSub,
    nodeIndex: *(const CVertIndex **)&sideVert,
    out: &sideVert);
  v18 = v15->GetPowerInfo(this: v15);
  return ((int)v15[((unsigned int)(sideVert.x + *(_DWORD *)(v18 + 36) * sideVert.y) >> 5) + 200].__vftable
        & (1 << ((LOBYTE(sideVert.x) + *(_BYTE *)(v18 + 36) * LOBYTE(sideVert.y)) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040BBA0
// Name: void UnallowVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnallowVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int *nUnallowed)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  const CVertIndex *v8; // eax
  int pDispa; // [esp+Ch] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = nodeIndex->x + *(_DWORD *)(v4 + 36) * nodeIndex->y;
  v6 = 1 << ((nodeIndex->x + *(_BYTE *)(v4 + 36) * nodeIndex->y) & 0x1F);
  if ( (v6 & (int)pDisp[((unsigned int)v5 >> 5) + 200].__vftable) != 0 )
  {
    ++*nUnallowed;
    pDisp[(v5 >> 5) + 200].__vftable = (CDispUtilsHelper_vtbl *)((int)pDisp[(v5 >> 5) + 200].__vftable & ~v6);
    v7 = 42 * v5 + 12;
    for ( pDispa = 4; pDispa != 0; --pDispa )
    {
      v8 = (const CVertIndex *)(v7 + *(_DWORD *)pDisp->GetPowerInfo(this: pDisp));
      if ( v8->x != -1 && v8[1].x == -1 )
        UnallowVerts_R(pDisp, nodeIndex: v8, nUnallowed);
      v7 += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BC40
// Name: void DisableUnallowedVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableUnallowedVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int iLevel, int *nUnallowed)
{
  const CVertIndex *v5; // ebx
  const CVertIndex *v6; // edi
  int v7; // ebx
  const CVertIndex *v8; // edi
  int v9; // eax
  int pDispa; // [esp+14h] [ebp+8h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+Ch]
  int iLevela; // [esp+1Ch] [ebp+10h]

  nodeIndexa = (const CVertIndex *)(16
                                  * (nodeIndex->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * nodeIndex->y));
  v5 = nodeIndexa;
  for ( pDispa = 4; pDispa != 0; --pDispa )
  {
    v6 = (const CVertIndex *)((char *)v5 + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 4));
    if ( !IsVertAllowed(pDisp, sideVert: (CVertIndex)v6, iLevel) )
      UnallowVerts_R(pDisp, nodeIndex: v6, nUnallowed);
    ++v5;
  }
  v7 = iLevel + 1;
  if ( iLevel + 1 < *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28) )
  {
    v8 = nodeIndexa;
    for ( iLevela = 4; iLevela != 0; --iLevela )
    {
      v9 = pDisp->GetPowerInfo(this: pDisp);
      DisableUnallowedVerts_R(
        pDisp,
        nodeIndex: (const CVertIndex *)((char *)v8++ + *(_DWORD *)(v9 + 8)),
        iLevel: v7,
        nUnallowed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BCF0
// Name: void SetupAllowedVerts(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupAllowedVerts(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // edx
  CBitVec<289> *p_m_AllowedVerts; // eax
  int v5; // edi
  CCoreDispInfo *v6; // esi
  const CVertIndex *v7; // eax
  int nUnallowed; // [esp+Ch] [ebp-4h] BYREF
  char bContinue_3; // [esp+1Fh] [ebp+Fh]

  for ( i = 0; i < nListSize; ++i )
  {
    p_m_AllowedVerts = &ppListBase[i]->m_AllowedVerts;
    if ( ppListBase[i] != (CCoreDispInfo *)-800 )
    {
      p_m_AllowedVerts->m_Ints[0] = -1;
      p_m_AllowedVerts->m_Ints[1] = -1;
      p_m_AllowedVerts->m_Ints[2] = -1;
      p_m_AllowedVerts->m_Ints[3] = -1;
      p_m_AllowedVerts->m_Ints[4] = -1;
      p_m_AllowedVerts->m_Ints[5] = -1;
      p_m_AllowedVerts->m_Ints[6] = -1;
      p_m_AllowedVerts->m_Ints[7] = -1;
      p_m_AllowedVerts->m_Ints[8] = -1;
      p_m_AllowedVerts->m_Ints[9] = -1;
    }
  }
  do
  {
    v5 = 0;
    bContinue_3 = 0;
    if ( nListSize <= 0 )
      break;
    do
    {
      v6 = ppListBase[v5];
      nUnallowed = 0;
      v7 = (const CVertIndex *)v6->GetPowerInfo(this: v6);
      DisableUnallowedVerts_R(pDisp: v6, nodeIndex: v7 + 8, iLevel: 0, &nUnallowed);
      if ( nUnallowed != 0 )
        bContinue_3 = 1;
      ++v5;
    }
    while ( v5 < nListSize );
  }
  while ( bContinue_3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0040BD90
// Name: void FindNeighboringDispSurfs(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindNeighboringDispSurfs(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // ebx
  CCoreDispInfo *v3; // edi
  int i; // esi
  CDispNeighbor *v5; // eax
  int v6; // eax
  int m_Size; // eax
  CDispBox *m_pMemory; // esi
  int v9; // edx
  CDispBox *v10; // edi
  int v11; // edx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  float *v15; // ecx
  CCoreDispInfo *v16; // ebx
  bool v17; // zf
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > boxes; // [esp+Ch] [ebp-30h] BYREF
  CCoreDispInfo *pOther; // [esp+20h] [ebp-1Ch]
  int nCornerOverflows; // [esp+24h] [ebp-18h] BYREF
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  CCoreDispInfo *pMain; // [esp+30h] [ebp-Ch]
  CCoreDispInfo **v24; // [esp+34h] [ebp-8h]
  int iDisp; // [esp+38h] [ebp-4h]

  v2 = nListSize;
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    v3 = ppListBase[iDisp];
    for ( i = 0; i < 4; ++i )
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: i);
      v5->m_SubNeighbors[0].m_iNeighbor = -1;
      v5->m_SubNeighbors[1].m_iNeighbor = -1;
      v6 = (int)v3->GetCornerNeighbors(this: v3, a2: i);
      *(_BYTE *)(v6 + 8) = 0;
    }
  }
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&boxes, 0, sizeof(boxes));
  if ( nListSize != 0 )
  {
    if ( nListSize > 0 )
    {
      CUtlMemory<DetailObjectGroup_t,int>::Grow(this: (CUtlMemory<DetailObjectGroup_t,int> *)&boxes, num: nListSize);
      m_Size = boxes.m_Size;
      m_pMemory = boxes.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 && nListSize > 0 )
      _V_memmove(dest: &m_pMemory[nListSize], src: m_pMemory, count: 24 * m_Size);
  }
  v9 = 0;
  if ( nListSize > 0 )
  {
    v10 = m_pMemory;
    do
    {
      GetDispBox(pDisp: ppListBase[v9], box: v10);
      v9 = v11 + 1;
      ++v10;
    }
    while ( v9 < nListSize );
  }
  nCornerOverflows = 0;
  if ( nListSize > 0 )
  {
    v12 = 1;
    v22 = 1;
    iDisp = (int)m_pMemory;
    v24 = ppListBase;
    v21 = nListSize;
    do
    {
      pMain = *v24;
      if ( v12 < v2 )
      {
        v13 = iDisp + 24;
        do
        {
          pOther = ppListBase[v12];
          v14 = 0;
          v15 = (float *)(v13 + 12);
          while ( *(v15 - 3) <= *(float *)((char *)v15 + iDisp - v13) )
          {
            if ( *(float *)(iDisp + 4 * v14) > *v15 )
              goto LABEL_24;
            ++v14;
            ++v15;
            if ( v14 >= 3 )
            {
              v16 = pOther;
              SetupEdgeNeighbors(pMain, pOther);
              SetupCornerNeighbors(pMain, pOther: v16, nOverflows: &nCornerOverflows);
LABEL_24:
              v2 = nListSize;
              break;
            }
            v2 = nListSize;
          }
          ++v12;
          v13 += 24;
        }
        while ( v12 < v2 );
        v12 = v22;
        m_pMemory = boxes.m_Memory.m_pMemory;
      }
      ++v24;
      iDisp += 24;
      ++v12;
      v17 = v21-- == 1;
      v22 = v12;
    }
    while ( !v17 );
    if ( nCornerOverflows != 0 )
      _Warning(a1: "Warning: overflowed %d displacement corner-neighbor lists.", nCornerOverflows);
  }
  VerifyNeighborConnections(ppListBase, nDisps: v2);
  if ( boxes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00423C10
// Name: public: bool CVertIndex::operator!=(class CVertIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVertIndex::operator!=(CVertIndex *this, const CVertIndex *other)
{
  return this->x != other->x || this->y != other->y;
}

//------------------------------------------------------------------------------
// Address: 0x00423C40
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00423C50
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423C60
// Name: public: void CCoreDispSurface::GetPoint(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetPoint(CCoreDispSurface *this, int index, Vector *pt)
{
  *pt = this->m_Points[index];
}

//------------------------------------------------------------------------------
// Address: 0x00423C90
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423CE0
// Name: int GetSubNeighborIndex(class CDispUtilsHelper __near *,int,class CVertIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSubNeighborIndex(CDispUtilsHelper *pDisp, int iEdge, const CVertIndex *nodeIndex)
{
  int v3; // edi
  CDispNeighbor *v4; // eax
  int v5; // edx
  CDispNeighbor *v6; // esi
  int v7; // ecx
  int result; // eax

  v3 = pDisp->GetPowerInfo(this: pDisp);
  v4 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  v5 = *(_DWORD *)(v3 + 44);
  v6 = v4;
  v7 = *(&nodeIndex->x + (g_EdgeDims[iEdge] == 0));
  result = 0;
  if ( v7 == v5 )
  {
    if ( v6->m_SubNeighbors[0].m_Span != 0 )
      return -1;
  }
  else
  {
    result = v7 > v5;
  }
  if ( v6->m_SubNeighbors[result].m_iNeighbor == 0xFFFF )
  {
    if ( result == 1 && v6->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v6->m_SubNeighbors[0].m_Span == 0 )
      return 0;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423D60
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x00423DF0
// Name: void GetDispBox(class CCoreDispInfo __near *,class CDispBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDispBox(CCoreDispInfo *pDisp, CDispBox *box)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *p_z; // eax
  int i; // ecx
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  double v14; // xmm0_8
  float v15; // xmm0_4
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float vMax; // [esp+0h] [ebp-Ch]

  v2 = (__m128)0x6753C21Cu;
  v3 = (__m128)0xE753C21C;
  v4 = 1.0e24;
  v5 = 1.0e24;
  vMax = -1.0e24;
  v6 = -1.0e24;
  p_z = &pDisp->m_Surf.m_Points[0].z;
  for ( i = 4; i != 0; --i )
  {
    v9 = *(p_z - 2);
    if ( v9 > v4 )
      v9 = v4;
    v4 = v9;
    v10 = *(p_z - 1);
    if ( v10 > v5 )
      v10 = v5;
    v11 = (__m128)*(unsigned int *)p_z;
    v5 = v10;
    v12 = _mm_cvtps_pd(v11);
    v13 = _mm_cvtps_pd(v2);
    if ( v12.m128d_f64[0] > v13.m128d_f64[0] )
      v12 = v13;
    v2 = _mm_cvtpd_ps(v12);
    v14 = *(p_z - 2);
    if ( v14 < vMax )
      v14 = vMax;
    v15 = v14;
    vMax = v15;
    v16 = _mm_cvtps_pd((__m128)*((unsigned int *)p_z - 1));
    v17 = _mm_cvtps_pd(v3);
    if ( v16.m128d_f64[0] < v17.m128d_f64[0] )
      v16 = v17;
    v3 = _mm_cvtpd_ps(v16);
    v18 = v11.m128_f32[0];
    if ( v11.m128_f32[0] < (double)v6 )
      v18 = v6;
    p_z += 3;
    v6 = v18;
  }
  v19 = flPuff;
  v20 = v5 - flPuff;
  v21 = v2.m128_f32[0] - flPuff;
  v22 = flPuff + vMax;
  v23 = v3.m128_f32[0] + flPuff;
  box->m_Min.x = v4 - flPuff;
  box->m_Min.y = v20;
  box->m_Min.z = v21;
  box->m_Max.x = v22;
  box->m_Max.y = v23;
  box->m_Max.z = v19 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x00423F40
// Name: void AddNeighbor(class CCoreDispInfo __near *,int,int,enum NeighborSpan,class CCoreDispInfo __near *,int,enum NeighborSpan)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddNeighbor(
        int a1@<edi>,
        CCoreDispInfo *pMain,
        int iEdge,
        int iSub,
        NeighborSpan span,
        CCoreDispInfo *pOther,
        int iNeighborEdge,
        NeighborSpan nbSpan)
{
  NeighborSpan v8; // ebx
  int v9; // esi
  CDispNeighbor *v10; // eax
  unsigned __int8 v11; // dl

  if ( g_bEdgeNeighborFlip[iEdge] )
    span = g_SpanFlip[span];
  if ( g_bEdgeNeighborFlip[iNeighborEdge] )
    v8 = g_SpanFlip[nbSpan];
  else
    v8 = nbSpan;
  v9 = ((int (__thiscall *)(CCoreDispInfo *, int, int))pMain->GetEdgeNeighbor)(a1: pMain, a2: iEdge, a3: a1) + 6 * iSub;
  if ( v8 == MIDPOINT_TO_CORNER )
    v10 = (CDispNeighbor *)&pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge)->m_SubNeighbors[1];
  else
    v10 = pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge);
  if ( *(_WORD *)v9 == 0xFFFF && v10->m_SubNeighbors[0].m_iNeighbor == 0xFFFF )
  {
    *(_WORD *)v9 = pOther->m_nListIndex;
    *(_BYTE *)(v9 + 2) = g_CoreDispNeighborOrientationMap[iEdge][iNeighborEdge];
    *(_BYTE *)(v9 + 4) = v8;
    *(_BYTE *)(v9 + 3) = span;
    v10->m_SubNeighbors[0].m_iNeighbor = pMain->m_nListIndex;
    v11 = g_CoreDispNeighborOrientationMap[iNeighborEdge][iEdge];
    v10->m_SubNeighbors[0].m_Span = v8;
    v10->m_SubNeighbors[0].m_NeighborOrientation = v11;
    v10->m_SubNeighbors[0].m_NeighborSpan = span;
  }
  else if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "Found a displacement edge abutting multiple other edges.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424040
// Name: bool HasEdgeNeighbor(class CCoreDispInfo const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasEdgeNeighbor(const CCoreDispInfo *pMain, int iNeighbor)
{
  int v2; // ebx
  int v3; // esi
  CDispNeighbor *m_EdgeNeighbors; // edi
  CDispCornerNeighbors *i; // ecx
  int v6; // eax

  v2 = iNeighbor;
  v3 = 0;
  m_EdgeNeighbors = pMain->m_Surf.m_EdgeNeighbors;
  for ( i = pMain->m_Surf.m_CornerNeighbors; ; ++i )
  {
    v6 = 0;
    if ( i->m_nNeighbors != 0 )
      break;
LABEL_6:
    if ( m_EdgeNeighbors->m_SubNeighbors[0].m_iNeighbor == v2 || m_EdgeNeighbors->m_SubNeighbors[1].m_iNeighbor == v2 )
      return 1;
    ++v3;
    ++m_EdgeNeighbors;
    if ( v3 >= 4 )
      return 0;
  }
  while ( i->m_Neighbors[v6] != iNeighbor )
  {
    if ( ++v6 >= i->m_nNeighbors )
    {
      v2 = iNeighbor;
      goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004240B0
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x004241C0
// Name: class CDispUtilsHelper __near * TransformIntoNeighbor(class CDispUtilsHelper __near *,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v4; // esi
  int v5; // edx
  __int16 y; // cx
  CVertIndex SubNeighborIndex; // eax

  v4 = iEdge;
  if ( iEdge == -1 )
  {
    v5 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
    if ( nodeIndex->x != 0 )
    {
      y = nodeIndex->y;
      if ( y == v5 )
      {
        v4 = 1;
      }
      else if ( nodeIndex->x == v5 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 4 * (y == 0) - 1;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  SubNeighborIndex = (CVertIndex)GetSubNeighborIndex(pDisp, iEdge: v4, nodeIndex);
  if ( SubNeighborIndex == -1 )
    return nullptr;
  else
    return TransformIntoSubNeighbor(pDisp, iEdge: v4, iSub: SubNeighborIndex, nodeIndex, out);
}

//------------------------------------------------------------------------------
// Address: 0x00424250
// Name: bool FindEdge(class CCoreDispInfo __near *,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEdge(CCoreDispInfo *pInfo, const Vector *vPoint1, const Vector *vPoint2, int *iEdge)
{
  int v4; // ecx
  int v5; // ecx

  *iEdge = 0;
  while ( 1 )
  {
    v4 = *iEdge;
    if ( fabs(vPoint1->x - pInfo->m_Surf.m_Points[*iEdge].x) <= 0.0099999998
      && fabs(vPoint1->y - pInfo->m_Surf.m_Points[*iEdge].y) <= 0.0099999998
      && fabs(vPoint1->z - pInfo->m_Surf.m_Points[*iEdge].z) <= 0.0099999998
      && fabs(vPoint2->x - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].x) <= 0.0099999998
      && fabs(vPoint2->y - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].y) <= 0.0099999998
      && fabs(vPoint2->z - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].z) <= 0.0099999998 )
    {
      break;
    }
    v5 = v4 + 1;
    *iEdge = v5;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00424320
// Name: void SetupEdgeNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupEdgeNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther)
{
  int v2; // edi
  float *p_z; // eax
  int v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  unsigned int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm6_4
  int v11; // ecx
  float *v12; // edx
  int v13; // ecx
  float *v14; // edx
  Vector pt[2]; // [esp+0h] [ebp-48h] BYREF
  Vector vPoint1; // [esp+18h] [ebp-30h] BYREF
  float v17; // [esp+28h] [ebp-20h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  Vector mid; // [esp+30h] [ebp-18h] BYREF
  int v20; // [esp+3Ch] [ebp-Ch]
  float *v21; // [esp+40h] [ebp-8h]
  int iNBEdge; // [esp+44h] [ebp-4h] BYREF

  v2 = 0;
  p_z = &pMain->m_Surf.m_Points[0].z;
  v4 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  v21 = &pMain->m_Surf.m_Points[0].z;
  v20 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  while ( 2 )
  {
    v5 = *(p_z - 2);
    v6 = *(p_z - 1);
    v7 = *p_z;
    v8 = 3 * ((unsigned int)&g_bEdgeNeighborFlip[v2 + v4] & 3) + 6;
    v9 = *((float *)&pMain->__vftable + v8);
    v10 = *((float *)&pMain->m_Nodes + v8);
    pt[1].z = *(&pMain->m_Elevation + v8);
    pt[0].x = v5;
    pt[0].y = v6;
    pt[0].z = v7;
    mid.x = (float)(v9 + v5) * 0.5;
    mid.y = (float)(v10 + v6) * 0.5;
    mid.z = (float)(pt[1].z + v7) * 0.5;
    pt[1].x = v9;
    pt[1].y = v10;
    v11 = 0;
    v12 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v12 - 2)) <= 0.0099999998
        && fabs(v10 - *(v12 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v12) <= 0.0099999998
        && fabs(pt[0].x - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].x) <= 0.0099999998
        && fabs(pt[0].y - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].y) <= 0.0099999998
        && fabs(pt[0].z - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].z) <= 0.0099999998 )
      {
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v11,
          nbSpan: CORNER_TO_CORNER);
        goto LABEL_27;
      }
      ++v11;
      v12 += 3;
    }
    while ( v11 < 4 );
    v17 = (float)(v6 * 2.0) - v10;
    v18 = (float)(v7 * 2.0) - pt[1].z;
    v13 = 0;
    v14 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v14 - 2)) <= 0.0099999998
        && fabs(v10 - *(v14 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v14) <= 0.0099999998
        && fabs((float)((float)(v5 * 2.0) - v9) - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].x) <= 0.0099999998
        && fabs(v17 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].y) <= 0.0099999998
        && fabs(v18 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].z) <= 0.0099999998 )
      {
        iNBEdge = v13;
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v13,
          nbSpan: CORNER_TO_MIDPOINT);
        goto LABEL_27;
      }
      ++v13;
      v14 += 3;
    }
    while ( v13 < 4 );
    iNBEdge = v13;
    vPoint1.x = (float)(v9 * 2.0) - pt[0].x;
    vPoint1.y = (float)(v10 * 2.0) - pt[0].y;
    vPoint1.z = (float)(pt[1].z * 2.0) - pt[0].z;
    if ( FindEdge(pInfo: pOther, &vPoint1, vPoint2: pt, iEdge: &iNBEdge) != 0 )
    {
      AddNeighbor(
        a1: v2,
        pMain,
        iEdge: v2,
        iSub: 0,
        span: CORNER_TO_CORNER,
        pOther,
        iNeighborEdge: iNBEdge,
        nbSpan: MIDPOINT_TO_CORNER);
    }
    else
    {
      if ( FindEdge(pInfo: pOther, vPoint1: &mid, vPoint2: pt, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: g_bEdgeNeighborFlip[v2],
          span: CORNER_TO_MIDPOINT,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
      if ( FindEdge(pInfo: pOther, vPoint1: &pt[1], vPoint2: &mid, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: !g_bEdgeNeighborFlip[v2],
          span: MIDPOINT_TO_CORNER,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
    }
LABEL_27:
    v21 += 3;
    if ( ++v2 < 4 )
    {
      v4 = v20;
      p_z = v21;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424640
// Name: void SetupCornerNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCornerNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther, int *nOverflows)
{
  CCoreDispInfo *v4; // edi
  CPowerInfo *v5; // eax
  const CVertIndex *CornerPointIndex; // ebx
  int i; // edi
  CPowerInfo *v8; // eax
  const CVertIndex *v9; // ebx
  Vector *p_m_Vert; // eax
  CDispCornerNeighbors *v11; // edi
  CDispCornerNeighbors *v12; // eax
  unsigned __int8 m_nNeighbors; // cl
  const Vector *vMainCorner; // [esp+8h] [ebp-10h]
  int iOtherSharedCorner; // [esp+Ch] [ebp-Ch]
  int iMainSharedCorner; // [esp+10h] [ebp-8h]
  int nShared; // [esp+14h] [ebp-4h]
  int iMainCorner; // [esp+24h] [ebp+Ch]

  v4 = pMain;
  if ( HasEdgeNeighbor(pMain, iNeighbor: pOther->m_nListIndex) == 0 )
  {
    nShared = 0;
    iMainSharedCorner = -1;
    iOtherSharedCorner = -1;
    iMainCorner = 0;
    while ( 1 )
    {
      v5 = (CPowerInfo *)v4->GetPowerInfo(this: v4);
      CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v5, iCorner: iMainCorner);
      vMainCorner = &v4->m_pVerts[CornerPointIndex->x
                                + *(_DWORD *)(v4->GetPowerInfo(this: v4) + 36) * CornerPointIndex->y].m_Vert;
      for ( i = 0; i < 4; ++i )
      {
        v8 = (CPowerInfo *)pOther->GetPowerInfo(this: pOther);
        v9 = CPowerInfo::GetCornerPointIndex(this: v8, iCorner: i);
        p_m_Vert = &pOther->m_pVerts[v9->x + *(_DWORD *)(pOther->GetPowerInfo(this: pOther) + 36) * v9->y].m_Vert;
        if ( fabs(vMainCorner->x - p_m_Vert->x) <= 0.001
          && fabs(vMainCorner->y - p_m_Vert->y) <= 0.001
          && fabs(vMainCorner->z - p_m_Vert->z) <= 0.001 )
        {
          ++nShared;
          iMainSharedCorner = iMainCorner;
          iOtherSharedCorner = i;
        }
      }
      if ( ++iMainCorner >= 4 )
        break;
      v4 = pMain;
    }
    if ( nShared == 1 )
    {
      v11 = pMain->GetCornerNeighbors(this: pMain, a2: iMainSharedCorner);
      v12 = pOther->GetCornerNeighbors(this: pOther, a2: iOtherSharedCorner);
      m_nNeighbors = v11->m_nNeighbors;
      if ( m_nNeighbors >= 4u || v12->m_nNeighbors >= 4u )
      {
        ++*nOverflows;
      }
      else
      {
        v11->m_Neighbors[m_nNeighbors] = pOther->m_nListIndex;
        ++v11->m_nNeighbors;
        v12->m_Neighbors[v12->m_nNeighbors++] = pMain->m_nListIndex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004247D0
// Name: bool VerifyNeighborVertConnection(class CDispUtilsHelper __near *,class CVertIndex const __near &,class CDispUtilsHelper const __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VerifyNeighborVertConnection(
        CDispUtilsHelper *pDisp,
        CVertIndex *nodeIndex,
        const CDispUtilsHelper *pTestNeighbor,
        const CVertIndex *testNeighborIndex,
        int mySide)
{
  const CDispUtilsHelper *v5; // eax
  CDispUtilsHelper *v6; // esi
  CDispUtilsHelper_vtbl *v7; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(CDispUtilsHelper *); // eax
  int v9; // eax
  int EdgeIndexFromPoint; // eax
  bool result; // al
  CVertIndex testIndex; // [esp+Ch] [ebp-8h] BYREF
  CVertIndex nbIndex; // [esp+10h] [ebp-4h] BYREF

  nbIndex.x = -1;
  nbIndex.y = -1;
  v5 = TransformIntoNeighbor(pDisp, iEdge: mySide, nodeIndex, out: &nbIndex);
  v6 = (CDispUtilsHelper *)v5;
  result = true;
  if ( v5 != nullptr )
  {
    if ( pTestNeighbor != v5 )
      return false;
    if ( nbIndex.x != testNeighborIndex->x )
      return false;
    if ( nbIndex.y != testNeighborIndex->y )
      return false;
    v7 = v5->__vftable;
    testIndex.x = -1;
    GetPowerInfo = v7->GetPowerInfo;
    testIndex.y = -1;
    v9 = (int)GetPowerInfo(this: v6);
    EdgeIndexFromPoint = GetEdgeIndexFromPoint(index: &nbIndex, iMaxPower: *(_DWORD *)(v9 + 28));
    if ( EdgeIndexFromPoint == -1
      || TransformIntoNeighbor(pDisp: v6, iEdge: EdgeIndexFromPoint, nodeIndex: &nbIndex, out: &testIndex) != pDisp
      || CVertIndex::operator!=(this: nodeIndex, other: &testIndex) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424880
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424A40
// Name: public: bool CDispEdgeIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispEdgeIterator::Next(CDispEdgeIterator *this)
{
  CVertIndex *p_m_Index; // edi
  CVertIndex *p_m_NBIndex; // ebx
  int m_iCurSub; // eax
  int m_iEdge; // ecx
  CDispUtilsHelper *v6; // eax

  this->m_It.m_Index.x += this->m_It.m_Inc.x;
  this->m_It.m_Index.y += this->m_It.m_Inc.y;
  this->m_It.m_NBIndex.x += this->m_It.m_NBInc.x;
  this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
  p_m_Index = &this->m_It.m_Index;
  p_m_NBIndex = &this->m_It.m_NBIndex;
  if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
    return 1;
  while ( 1 )
  {
    m_iCurSub = this->m_iCurSub;
    if ( m_iCurSub == 1 )
      break;
    m_iEdge = this->m_iEdge;
    this->m_iCurSub = m_iCurSub + 1;
    v6 = SetupEdgeIncrements(
           pDisp: this->m_pDisp,
           iEdge: m_iEdge,
           iSub: m_iCurSub + 1,
           myIndex: &this->m_It.m_Index,
           myInc: &this->m_It.m_Inc,
           nbIndex: &this->m_It.m_NBIndex,
           nbInc: &this->m_It.m_NBInc,
           myEnd: &this->m_It.m_End,
           iFreeDim: &this->m_It.m_FreeDim);
    this->m_It.m_pNeighbor = v6;
    if ( v6 == nullptr )
    {
      this->m_It.m_End = 0;
      this->m_It.m_Inc.x = 0;
      p_m_Index->x = 0;
      this->m_It.m_FreeDim = 0;
    }
    p_m_Index->x += this->m_It.m_Inc.x;
    this->m_It.m_Index.y += this->m_It.m_Inc.y;
    p_m_NBIndex->x += this->m_It.m_NBInc.x;
    this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
    if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424B00
// Name: void VerifyNeighborConnections(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyNeighborConnections(CCoreDispInfo **ppListBase, int nDisps)
{
  char v2; // bl
  CCoreDispInfo *v3; // esi
  int v4; // edi
  _WORD *v5; // eax
  CPowerInfo *v6; // eax
  const CVertIndex *CornerPointIndex; // edi
  int p_m_Vert; // ebx
  CPowerInfo *v9; // eax
  const CVertIndex *v10; // edi
  int v11; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  CPowerInfo *v13; // eax
  const CVertIndex *v14; // edi
  int v15; // eax
  int v16; // [esp+18h] [ebp-44h]
  CDispEdgeIterator it; // [esp+28h] [ebp-34h] BYREF
  int v18; // [esp+50h] [ebp-Ch]
  int iEdge; // [esp+54h] [ebp-8h]
  int iDisp; // [esp+58h] [ebp-4h]

  do
  {
    v2 = 1;
    iDisp = 0;
    if ( nDisps <= 0 )
      break;
    v3 = *ppListBase;
    v4 = 0;
    for ( iEdge = 0; ; iEdge = 0 )
    {
      do
      {
        it.m_It.m_Inc.x = 0;
        it.m_It.m_pNeighbor = nullptr;
        it.m_It.m_End = 0;
        it.m_It.m_Index.x = 0;
        it.m_It.m_FreeDim = 0;
        it.m_pDisp = v3;
        it.m_iEdge = v4;
        it.m_iCurSub = -1;
        while ( CDispEdgeIterator::Next(this: &it) != 0 )
        {
          if ( !VerifyNeighborVertConnection(
                  pDisp: v3,
                  nodeIndex: &it.m_It.m_Index,
                  pTestNeighbor: it.m_It.m_pNeighbor,
                  testNeighborIndex: &it.m_It.m_NBIndex,
                  mySide: v4) )
          {
            v16 = v4;
            v5 = (_WORD *)((int (__thiscall *)(CCoreDispInfo *))v3->GetEdgeNeighbor)(a1: v3);
            *v5 = -1;
            v5[3] = -1;
            v6 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v6, iCorner: 0);
            p_m_Vert = (int)&v3->m_pVerts[CornerPointIndex->x
                                        + *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * CornerPointIndex->y].m_Vert;
            v9 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            v10 = CPowerInfo::GetCornerPointIndex(this: v9, iCorner: 0);
            v11 = *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * v10->y;
            GetPowerInfo = v3->GetPowerInfo;
            v18 = (int)&v3->m_pVerts[v10->x + v11].m_Vert;
            v13 = (CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, _DWORD))GetPowerInfo)(a1: v3, a2: 0);
            v14 = CPowerInfo::GetCornerPointIndex(this: v13, iCorner: v16);
            v15 = v3->GetPowerInfo(this: v3);
            _Warning(
              a1: "Warning: invalid neighbor connection on displacement near (%.2f %.2f %.2f)\n",
              v3->m_pVerts[v14->x + *(_DWORD *)(v15 + 36) * v14->y].m_Vert.x,
              *(float *)(v18 + 4),
              *(float *)(p_m_Vert + 8));
            v2 = 0;
            v4 = iEdge;
          }
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      if ( ++iDisp >= nDisps )
        break;
      v3 = ppListBase[iDisp];
      v4 = 0;
    }
  }
  while ( v2 == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00424CE0
// Name: bool IsVertAllowed(class CDispUtilsHelper __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsVertAllowed(CDispUtilsHelper *pDisp, CVertIndex sideVert, int iLevel)
{
  int v4; // eax
  const CVertIndex *v5; // edi
  int v6; // ecx
  __int16 v7; // ax
  int v8; // edx
  int v9; // ecx
  __int16 v10; // ax
  __int16 y; // cx
  int SubNeighborIndex; // edi
  CDispSubNeighbor *v14; // ebx
  CDispUtilsHelper *v15; // edi
  CShiftInfo *v16; // ebx
  int v17; // eax
  int v18; // eax
  int iSub; // [esp+8h] [ebp-4h]
  int iSide; // [esp+14h] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = (const CVertIndex *)sideVert;
  v6 = *(_DWORD *)(v4 + 36);
  if ( *(_WORD *)sideVert.x == 0 )
  {
    v7 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v7 != 0 && v7 != v6 - 1 )
      goto LABEL_4;
    return true;
  }
  v9 = v6 - 1;
  if ( *(__int16 *)sideVert.x == v9 )
  {
    v10 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v10 == 0 || v10 == v9 )
      return true;
  }
LABEL_4:
  v8 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  if ( v5->x != 0 )
  {
    y = v5->y;
    if ( y == v8 )
    {
      iSide = 1;
    }
    else if ( v5->x == v8 )
    {
      iSide = 2;
    }
    else
    {
      if ( y != 0 )
        return true;
      iSide = 3;
    }
  }
  else
  {
    iSide = 0;
  }
  SubNeighborIndex = GetSubNeighborIndex(pDisp, iEdge: iSide, nodeIndex: v5);
  iSub = SubNeighborIndex;
  if ( SubNeighborIndex == -1 )
    return true;
  v14 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iSide)->m_SubNeighbors[SubNeighborIndex];
  v15 = pDisp->GetDispUtilsByIndex(this: pDisp, a2: v14->m_iNeighbor);
  v16 = &g_ShiftInfos[v14->m_Span][v14->m_NeighborSpan];
  v17 = v15->GetPowerInfo(this: v15);
  if ( v16->m_PowerShiftAdd + *(_DWORD *)(v17 + 28) < iLevel + 1 )
    return false;
  TransformIntoSubNeighbor(
    pDisp,
    iEdge: iSide,
    (CVertIndex)iSub,
    nodeIndex: *(const CVertIndex **)&sideVert,
    out: &sideVert);
  v18 = v15->GetPowerInfo(this: v15);
  return ((int)v15[((unsigned int)(sideVert.x + *(_DWORD *)(v18 + 36) * sideVert.y) >> 5) + 200].__vftable
        & (1 << ((LOBYTE(sideVert.x) + *(_BYTE *)(v18 + 36) * LOBYTE(sideVert.y)) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424E50
// Name: void UnallowVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnallowVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int *nUnallowed)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  const CVertIndex *v8; // eax
  int pDispa; // [esp+Ch] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = nodeIndex->x + *(_DWORD *)(v4 + 36) * nodeIndex->y;
  v6 = 1 << ((nodeIndex->x + *(_BYTE *)(v4 + 36) * nodeIndex->y) & 0x1F);
  if ( (v6 & (int)pDisp[((unsigned int)v5 >> 5) + 200].__vftable) != 0 )
  {
    ++*nUnallowed;
    pDisp[(v5 >> 5) + 200].__vftable = (CDispUtilsHelper_vtbl *)((int)pDisp[(v5 >> 5) + 200].__vftable & ~v6);
    v7 = 42 * v5 + 12;
    for ( pDispa = 4; pDispa != 0; --pDispa )
    {
      v8 = (const CVertIndex *)(v7 + *(_DWORD *)pDisp->GetPowerInfo(this: pDisp));
      if ( v8->x != -1 && v8[1].x == -1 )
        UnallowVerts_R(pDisp, nodeIndex: v8, nUnallowed);
      v7 += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424EF0
// Name: void DisableUnallowedVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableUnallowedVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int iLevel, int *nUnallowed)
{
  const CVertIndex *v5; // ebx
  const CVertIndex *v6; // edi
  int v7; // ebx
  const CVertIndex *v8; // edi
  int v9; // eax
  int pDispa; // [esp+14h] [ebp+8h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+Ch]
  int iLevela; // [esp+1Ch] [ebp+10h]

  nodeIndexa = (const CVertIndex *)(16
                                  * (nodeIndex->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * nodeIndex->y));
  v5 = nodeIndexa;
  for ( pDispa = 4; pDispa != 0; --pDispa )
  {
    v6 = (const CVertIndex *)((char *)v5 + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 4));
    if ( !IsVertAllowed(pDisp, sideVert: (CVertIndex)v6, iLevel) )
      UnallowVerts_R(pDisp, nodeIndex: v6, nUnallowed);
    ++v5;
  }
  v7 = iLevel + 1;
  if ( iLevel + 1 < *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28) )
  {
    v8 = nodeIndexa;
    for ( iLevela = 4; iLevela != 0; --iLevela )
    {
      v9 = pDisp->GetPowerInfo(this: pDisp);
      DisableUnallowedVerts_R(
        pDisp,
        nodeIndex: (const CVertIndex *)((char *)v8++ + *(_DWORD *)(v9 + 8)),
        iLevel: v7,
        nUnallowed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424FA0
// Name: void SetupAllowedVerts(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupAllowedVerts(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // edx
  CBitVec<289> *p_m_AllowedVerts; // eax
  int v5; // edi
  CCoreDispInfo *v6; // esi
  const CVertIndex *v7; // eax
  int nUnallowed; // [esp+Ch] [ebp-4h] BYREF
  char bContinue_3; // [esp+1Fh] [ebp+Fh]

  for ( i = 0; i < nListSize; ++i )
  {
    p_m_AllowedVerts = &ppListBase[i]->m_AllowedVerts;
    if ( ppListBase[i] != (CCoreDispInfo *)-800 )
    {
      p_m_AllowedVerts->m_Ints[0] = -1;
      p_m_AllowedVerts->m_Ints[1] = -1;
      p_m_AllowedVerts->m_Ints[2] = -1;
      p_m_AllowedVerts->m_Ints[3] = -1;
      p_m_AllowedVerts->m_Ints[4] = -1;
      p_m_AllowedVerts->m_Ints[5] = -1;
      p_m_AllowedVerts->m_Ints[6] = -1;
      p_m_AllowedVerts->m_Ints[7] = -1;
      p_m_AllowedVerts->m_Ints[8] = -1;
      p_m_AllowedVerts->m_Ints[9] = -1;
    }
  }
  do
  {
    v5 = 0;
    bContinue_3 = 0;
    if ( nListSize <= 0 )
      break;
    do
    {
      v6 = ppListBase[v5];
      nUnallowed = 0;
      v7 = (const CVertIndex *)v6->GetPowerInfo(this: v6);
      DisableUnallowedVerts_R(pDisp: v6, nodeIndex: v7 + 8, iLevel: 0, &nUnallowed);
      if ( nUnallowed != 0 )
        bContinue_3 = 1;
      ++v5;
    }
    while ( v5 < nListSize );
  }
  while ( bContinue_3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00425040
// Name: void FindNeighboringDispSurfs(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindNeighboringDispSurfs(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // ebx
  CCoreDispInfo *v3; // edi
  int i; // esi
  CDispNeighbor *v5; // eax
  int v6; // eax
  int m_Size; // eax
  CDispBox *m_pMemory; // esi
  int v9; // edx
  CDispBox *v10; // edi
  int v11; // edx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  float *v15; // ecx
  CCoreDispInfo *v16; // ebx
  bool v17; // zf
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > boxes; // [esp+Ch] [ebp-30h] BYREF
  CCoreDispInfo *pOther; // [esp+20h] [ebp-1Ch]
  int nCornerOverflows; // [esp+24h] [ebp-18h] BYREF
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  CCoreDispInfo *pMain; // [esp+30h] [ebp-Ch]
  CCoreDispInfo **v24; // [esp+34h] [ebp-8h]
  int iDisp; // [esp+38h] [ebp-4h]

  v2 = nListSize;
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    v3 = ppListBase[iDisp];
    for ( i = 0; i < 4; ++i )
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: i);
      v5->m_SubNeighbors[0].m_iNeighbor = -1;
      v5->m_SubNeighbors[1].m_iNeighbor = -1;
      v6 = (int)v3->GetCornerNeighbors(this: v3, a2: i);
      *(_BYTE *)(v6 + 8) = 0;
    }
  }
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&boxes, 0, sizeof(boxes));
  if ( nListSize != 0 )
  {
    if ( nListSize > 0 )
    {
      CUtlMemory<HashedPlane_t,int>::Grow(this: &boxes.m_Memory, num: nListSize);
      m_Size = boxes.m_Size;
      m_pMemory = boxes.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 && nListSize > 0 )
      _V_memmove(dest: &m_pMemory[nListSize], src: m_pMemory, count: 24 * m_Size);
  }
  v9 = 0;
  if ( nListSize > 0 )
  {
    v10 = m_pMemory;
    do
    {
      GetDispBox(pDisp: ppListBase[v9], box: v10);
      v9 = v11 + 1;
      ++v10;
    }
    while ( v9 < nListSize );
  }
  nCornerOverflows = 0;
  if ( nListSize > 0 )
  {
    v12 = 1;
    v22 = 1;
    iDisp = (int)m_pMemory;
    v24 = ppListBase;
    v21 = nListSize;
    do
    {
      pMain = *v24;
      if ( v12 < v2 )
      {
        v13 = iDisp + 24;
        do
        {
          pOther = ppListBase[v12];
          v14 = 0;
          v15 = (float *)(v13 + 12);
          while ( *(v15 - 3) <= *(float *)((char *)v15 + iDisp - v13) )
          {
            if ( *(float *)(iDisp + 4 * v14) > *v15 )
              goto LABEL_24;
            ++v14;
            ++v15;
            if ( v14 >= 3 )
            {
              v16 = pOther;
              SetupEdgeNeighbors(pMain, pOther);
              SetupCornerNeighbors(pMain, pOther: v16, nOverflows: &nCornerOverflows);
LABEL_24:
              v2 = nListSize;
              break;
            }
            v2 = nListSize;
          }
          ++v12;
          v13 += 24;
        }
        while ( v12 < v2 );
        v12 = v22;
        m_pMemory = boxes.m_Memory.m_pMemory;
      }
      ++v24;
      iDisp += 24;
      ++v12;
      v17 = v21-- == 1;
      v22 = v12;
    }
    while ( !v17 );
    if ( nCornerOverflows != 0 )
      _Warning(a1: "Warning: overflowed %d displacement corner-neighbor lists.", nCornerOverflows);
  }
  VerifyNeighborConnections(ppListBase, nDisps: v2);
  if ( boxes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace vbsp2

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0041ADB0
// Name: public: bool CVertIndex::operator!=(class CVertIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVertIndex::operator!=(CVertIndex *this, const CVertIndex *other)
{
  return this->x != other->x || this->y != other->y;
}

//------------------------------------------------------------------------------
// Address: 0x0041ADE0
// Name: float RemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapVal(float val, float A, float B, float C, float D)
{
  if ( A != B )
    return C + (D - C) * (val - A) / (B - A);
  if ( (float)(val - B) < 0.0 )
    return C;
  return D;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE50
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE60
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE70
// Name: public: void CCoreDispSurface::GetPoint(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetPoint(CCoreDispSurface *this, int index, Vector *pt)
{
  *pt = this->m_Points[index];
}

//------------------------------------------------------------------------------
// Address: 0x0041AEA0
// Name: public: class CCoreDispSurface __near * CCoreDispInfo::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CCoreDispInfo::GetSurface(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x0041AEB0
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF00
// Name: int GetSubNeighborIndex(class CDispUtilsHelper __near *,int,class CVertIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetSubNeighborIndex(CDispUtilsHelper *pDisp, int iEdge, const CVertIndex *nodeIndex)
{
  int v3; // edi
  CDispNeighbor *v4; // eax
  int v5; // edx
  CDispNeighbor *v6; // esi
  int v7; // ecx
  int result; // eax

  v3 = pDisp->GetPowerInfo(this: pDisp);
  v4 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  v5 = *(_DWORD *)(v3 + 44);
  v6 = v4;
  v7 = *(&nodeIndex->x + (g_EdgeDims[iEdge] == 0));
  result = 0;
  if ( v7 == v5 )
  {
    if ( v6->m_SubNeighbors[0].m_Span != 0 )
      return -1;
  }
  else
  {
    result = v7 > v5;
  }
  if ( v6->m_SubNeighbors[result].m_iNeighbor == 0xFFFF )
  {
    if ( result == 1 && v6->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v6->m_SubNeighbors[0].m_Span == 0 )
      return 0;
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF80
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x0041B010
// Name: public: class CVertIndex CDispUtilsHelper::GetEdgeMidPoint(int)const
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__thiscall CDispUtilsHelper::GetEdgeMidPoint(CDispUtilsHelper *this, CVertIndex *result, int iEdge)
{
  int v4; // edi
  int v5; // ecx
  CVertIndex *v6; // eax

  v4 = *(_DWORD *)(this->GetPowerInfo(this) + 36) - 1;
  v5 = *(_DWORD *)(this->GetPowerInfo(this) + 44);
  if ( iEdge != 0 )
  {
    if ( iEdge == 1 )
    {
      result->y = v4;
      result->x = v5;
      return result;
    }
    else if ( iEdge == 2 )
    {
      result->x = v4;
      result->y = v5;
      return result;
    }
    else
    {
      v6 = result;
      if ( iEdge == 3 )
      {
        result->x = v5;
        result->y = 0;
      }
      else
      {
        *result = 0;
      }
    }
  }
  else
  {
    result->x = 0;
    result->y = v5;
    return result;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041B090
// Name: void GetDispBox(class CCoreDispInfo __near *,class CDispBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetDispBox(CCoreDispInfo *pDisp, CDispBox *box)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float *p_z; // eax
  int i; // ecx
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 v11; // xmm7
  __m128d v12; // xmm0
  __m128d v13; // xmm1
  double v14; // xmm0_8
  float v15; // xmm0_4
  __m128d v16; // xmm0
  __m128d v17; // xmm1
  double v18; // xmm0_8
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float vMax; // [esp+0h] [ebp-Ch]

  v2 = (__m128)0x6753C21Cu;
  v3 = (__m128)0xE753C21C;
  v4 = 1.0e24;
  v5 = 1.0e24;
  vMax = -1.0e24;
  v6 = -1.0e24;
  p_z = &pDisp->m_Surf.m_Points[0].z;
  for ( i = 4; i != 0; --i )
  {
    v9 = *(p_z - 2);
    if ( v9 > v4 )
      v9 = v4;
    v4 = v9;
    v10 = *(p_z - 1);
    if ( v10 > v5 )
      v10 = v5;
    v11 = (__m128)*(unsigned int *)p_z;
    v5 = v10;
    v12 = _mm_cvtps_pd(v11);
    v13 = _mm_cvtps_pd(v2);
    if ( v12.m128d_f64[0] > v13.m128d_f64[0] )
      v12 = v13;
    v2 = _mm_cvtpd_ps(v12);
    v14 = *(p_z - 2);
    if ( v14 < vMax )
      v14 = vMax;
    v15 = v14;
    vMax = v15;
    v16 = _mm_cvtps_pd((__m128)*((unsigned int *)p_z - 1));
    v17 = _mm_cvtps_pd(v3);
    if ( v16.m128d_f64[0] < v17.m128d_f64[0] )
      v16 = v17;
    v3 = _mm_cvtpd_ps(v16);
    v18 = v11.m128_f32[0];
    if ( v11.m128_f32[0] < (double)v6 )
      v18 = v6;
    p_z += 3;
    v6 = v18;
  }
  v19 = flPuff;
  v20 = v5 - flPuff;
  v21 = v2.m128_f32[0] - flPuff;
  v22 = flPuff + vMax;
  v23 = v3.m128_f32[0] + flPuff;
  box->m_Min.x = v4 - flPuff;
  box->m_Min.y = v20;
  box->m_Min.z = v21;
  box->m_Max.x = v22;
  box->m_Max.y = v23;
  box->m_Max.z = v19 + v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041B1E0
// Name: void AddNeighbor(class CCoreDispInfo __near *,int,int,enum NeighborSpan,class CCoreDispInfo __near *,int,enum NeighborSpan)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddNeighbor(
        int a1@<edi>,
        CCoreDispInfo *pMain,
        int iEdge,
        int iSub,
        NeighborSpan span,
        CCoreDispInfo *pOther,
        int iNeighborEdge,
        NeighborSpan nbSpan)
{
  NeighborSpan v8; // ebx
  int v9; // esi
  CDispNeighbor *v10; // eax
  unsigned __int8 v11; // dl

  if ( g_bEdgeNeighborFlip[iEdge] )
    span = g_SpanFlip[span];
  if ( g_bEdgeNeighborFlip[iNeighborEdge] )
    v8 = g_SpanFlip[nbSpan];
  else
    v8 = nbSpan;
  v9 = ((int (__thiscall *)(CCoreDispInfo *, int, int))pMain->GetEdgeNeighbor)(a1: pMain, a2: iEdge, a3: a1) + 6 * iSub;
  if ( v8 == MIDPOINT_TO_CORNER )
    v10 = (CDispNeighbor *)&pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge)->m_SubNeighbors[1];
  else
    v10 = pOther->GetEdgeNeighbor(this: pOther, a2: iNeighborEdge);
  if ( *(_WORD *)v9 == 0xFFFF && v10->m_SubNeighbors[0].m_iNeighbor == 0xFFFF )
  {
    *(_WORD *)v9 = pOther->m_nListIndex;
    *(_BYTE *)(v9 + 2) = g_CoreDispNeighborOrientationMap[iEdge][iNeighborEdge];
    *(_BYTE *)(v9 + 4) = v8;
    *(_BYTE *)(v9 + 3) = span;
    v10->m_SubNeighbors[0].m_iNeighbor = pMain->m_nListIndex;
    v11 = g_CoreDispNeighborOrientationMap[iNeighborEdge][iEdge];
    v10->m_SubNeighbors[0].m_Span = v8;
    v10->m_SubNeighbors[0].m_NeighborOrientation = v11;
    v10->m_SubNeighbors[0].m_NeighborSpan = span;
  }
  else if ( _executeCount < 1 )
  {
    ++_executeCount;
    _Warning(a1: "Found a displacement edge abutting multiple other edges.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B2E0
// Name: bool HasEdgeNeighbor(class CCoreDispInfo const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasEdgeNeighbor(const CCoreDispInfo *pMain, int iNeighbor)
{
  int v2; // ebx
  int v3; // esi
  CDispNeighbor *m_EdgeNeighbors; // edi
  CDispCornerNeighbors *i; // ecx
  int v6; // eax

  v2 = iNeighbor;
  v3 = 0;
  m_EdgeNeighbors = pMain->m_Surf.m_EdgeNeighbors;
  for ( i = pMain->m_Surf.m_CornerNeighbors; ; ++i )
  {
    v6 = 0;
    if ( i->m_nNeighbors != 0 )
      break;
LABEL_6:
    if ( m_EdgeNeighbors->m_SubNeighbors[0].m_iNeighbor == v2 || m_EdgeNeighbors->m_SubNeighbors[1].m_iNeighbor == v2 )
      return 1;
    ++v3;
    ++m_EdgeNeighbors;
    if ( v3 >= 4 )
      return 0;
  }
  while ( i->m_Neighbors[v6] != iNeighbor )
  {
    if ( ++v6 >= i->m_nNeighbors )
    {
      v2 = iNeighbor;
      goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B350
// Name: FindNeighborCornerVert
// Source: json
//------------------------------------------------------------------------------
int __usercall FindNeighborCornerVert@<eax>(CCoreDispInfo *pDisp@<esi>, const Vector *vecPoint@<edi>)
{
  CPowerInfo *v2; // eax
  int v3; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v9; // [esp-1Ch] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-1Ch]
  float v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  int iClosest; // [esp+0h] [ebp-10h]

  v10 = 0;
  v11 = 1.0e24;
  for ( iClosest = 0; iClosest < 4; ++iClosest )
  {
    v2 = (CPowerInfo *)pDisp->GetPowerInfo(this: pDisp);
    v12 = (int)*CPowerInfo::GetCornerPointIndex(this: v2, iCorner: iClosest);
    v3 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * SHIWORD(v12);
    m_pVerts = pDisp->m_pVerts;
    v5 = (__int16)v12 + v3;
    v6 = m_pVerts[v5].m_Vert.x - vecPoint->x;
    v9 = fsqrt(
           (float)((float)((float)(m_pVerts[v5].m_Vert.y - vecPoint->y) * (float)(m_pVerts[v5].m_Vert.y - vecPoint->y))
                 + (float)(v6 * v6))
         + (float)((float)(m_pVerts[v5].m_Vert.z - vecPoint->z) * (float)(m_pVerts[v5].m_Vert.z - vecPoint->z)));
    v7 = v11;
    if ( v11 > v9 )
    {
      v7 = v9;
      v10 = iClosest;
      v11 = v9;
    }
  }
  if ( v7 > 0.1 )
    return -1;
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0041B450
// Name: UpdateTangentSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateTangentSpace(
        const Vector *vNormal@<esi>,
        const Vector *vTanS@<edi>,
        CCoreDispInfo *pDisp,
        const CVertIndex *index)
{
  int v4; // ecx
  CoreDispVert_t *m_pVerts; // eax
  char *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  v4 = index->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * index->y;
  m_pVerts = pDisp->m_pVerts;
  v4 *= 224;
  *(Vector *)((char *)&m_pVerts->m_Normal + v4) = *vNormal;
  v6 = (char *)m_pVerts + v4;
  v7 = vTanS->z * vNormal->x;
  v8 = vTanS->y * vNormal->x;
  v9 = (float)(vTanS->y * vNormal->z) - (float)(vTanS->z * vNormal->y);
  v10 = vTanS->x * vNormal->z;
  v11 = vTanS->x * vNormal->y;
  *(Vector *)(v6 + 76) = *vTanS;
  *((float *)v6 + 22) = v9;
  *((float *)v6 + 23) = v7 - v10;
  *((float *)v6 + 24) = v11 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x0041B500
// Name: GetAllNeighbors
// Source: json
//------------------------------------------------------------------------------
int __usercall GetAllNeighbors@<eax>(int *iNeighbors@<esi>, CCoreDispInfo *pDisp)
{
  unsigned __int16 *v2; // ebx
  int result; // eax
  unsigned __int8 *p_m_nNeighbors; // ecx
  int i; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = (unsigned __int16 *)pDisp;
  result = 0;
  p_m_nNeighbors = &pDisp->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
  for ( i = 4; i != 0; --i )
  {
    v6 = 0;
    if ( *p_m_nNeighbors != 0 )
    {
      do
      {
        if ( result == 0 )
        {
          *iNeighbors = *(unsigned __int16 *)&p_m_nNeighbors[2 * v6 - 8];
          result = 1;
        }
        ++v6;
      }
      while ( v6 < *p_m_nNeighbors );
      v2 = (unsigned __int16 *)pDisp;
    }
    p_m_nNeighbors += 10;
  }
  v7 = v2[312];
  if ( (_WORD)v7 != 0xFFFF )
    iNeighbors[result++] = v7;
  v8 = v2[315];
  if ( (_WORD)v8 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v8;
  v9 = v2[318];
  if ( (_WORD)v9 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v9;
  v10 = v2[321];
  if ( (_WORD)v10 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v10;
  v11 = v2[324];
  if ( (_WORD)v11 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v11;
  v12 = v2[327];
  if ( (_WORD)v12 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v12;
  v13 = v2[330];
  if ( (_WORD)v13 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v13;
  v14 = v2[333];
  if ( (_WORD)v14 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B600
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x0041B710
// Name: class CDispUtilsHelper __near * TransformIntoNeighbor(class CDispUtilsHelper __near *,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v4; // esi
  int v5; // edx
  __int16 y; // cx
  CVertIndex SubNeighborIndex; // eax

  v4 = iEdge;
  if ( iEdge == -1 )
  {
    v5 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
    if ( nodeIndex->x != 0 )
    {
      y = nodeIndex->y;
      if ( y == v5 )
      {
        v4 = 1;
      }
      else if ( nodeIndex->x == v5 )
      {
        v4 = 2;
      }
      else
      {
        v4 = 4 * (y == 0) - 1;
      }
    }
    else
    {
      v4 = 0;
    }
  }
  SubNeighborIndex = (CVertIndex)GetSubNeighborIndex(pDisp, iEdge: v4, nodeIndex);
  if ( SubNeighborIndex == -1 )
    return nullptr;
  else
    return TransformIntoSubNeighbor(pDisp, iEdge: v4, iSub: SubNeighborIndex, nodeIndex, out);
}

//------------------------------------------------------------------------------
// Address: 0x0041B7A0
// Name: bool FindEdge(class CCoreDispInfo __near *,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEdge(CCoreDispInfo *pInfo, const Vector *vPoint1, const Vector *vPoint2, int *iEdge)
{
  int v4; // ecx
  int v5; // ecx

  *iEdge = 0;
  while ( 1 )
  {
    v4 = *iEdge;
    if ( fabs(vPoint1->x - pInfo->m_Surf.m_Points[*iEdge].x) <= 0.0099999998
      && fabs(vPoint1->y - pInfo->m_Surf.m_Points[*iEdge].y) <= 0.0099999998
      && fabs(vPoint1->z - pInfo->m_Surf.m_Points[*iEdge].z) <= 0.0099999998
      && fabs(vPoint2->x - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].x) <= 0.0099999998
      && fabs(vPoint2->y - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].y) <= 0.0099999998
      && fabs(vPoint2->z - pInfo->m_Surf.m_Points[((_BYTE)v4 + 1) & 3].z) <= 0.0099999998 )
    {
      break;
    }
    v5 = v4 + 1;
    *iEdge = v5;
    if ( v5 >= 4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B870
// Name: void SetupEdgeNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupEdgeNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther)
{
  int v2; // edi
  float *p_z; // eax
  int v4; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  unsigned int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm6_4
  int v11; // ecx
  float *v12; // edx
  int v13; // ecx
  float *v14; // edx
  Vector pt[2]; // [esp+0h] [ebp-48h] BYREF
  Vector vPoint1; // [esp+18h] [ebp-30h] BYREF
  float v17; // [esp+28h] [ebp-20h]
  float v18; // [esp+2Ch] [ebp-1Ch]
  Vector mid; // [esp+30h] [ebp-18h] BYREF
  int v20; // [esp+3Ch] [ebp-Ch]
  float *v21; // [esp+40h] [ebp-8h]
  int iNBEdge; // [esp+44h] [ebp-4h] BYREF

  v2 = 0;
  p_z = &pMain->m_Surf.m_Points[0].z;
  v4 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  v21 = &pMain->m_Surf.m_Points[0].z;
  v20 = 1 - (_DWORD)g_bEdgeNeighborFlip;
  while ( 2 )
  {
    v5 = *(p_z - 2);
    v6 = *(p_z - 1);
    v7 = *p_z;
    v8 = 3 * ((unsigned int)&g_bEdgeNeighborFlip[v2 + v4] & 3) + 6;
    v9 = *((float *)&pMain->__vftable + v8);
    v10 = *((float *)&pMain->m_Nodes + v8);
    pt[1].z = *(&pMain->m_Elevation + v8);
    pt[0].x = v5;
    pt[0].y = v6;
    pt[0].z = v7;
    mid.x = (float)(v9 + v5) * 0.5;
    mid.y = (float)(v10 + v6) * 0.5;
    mid.z = (float)(pt[1].z + v7) * 0.5;
    pt[1].x = v9;
    pt[1].y = v10;
    v11 = 0;
    v12 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v12 - 2)) <= 0.0099999998
        && fabs(v10 - *(v12 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v12) <= 0.0099999998
        && fabs(pt[0].x - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].x) <= 0.0099999998
        && fabs(pt[0].y - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].y) <= 0.0099999998
        && fabs(pt[0].z - pOther->m_Surf.m_Points[((_BYTE)v11 + 1) & 3].z) <= 0.0099999998 )
      {
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v11,
          nbSpan: CORNER_TO_CORNER);
        goto LABEL_27;
      }
      ++v11;
      v12 += 3;
    }
    while ( v11 < 4 );
    v17 = (float)(v6 * 2.0) - v10;
    v18 = (float)(v7 * 2.0) - pt[1].z;
    v13 = 0;
    v14 = &pOther->m_Surf.m_Points[0].z;
    do
    {
      if ( fabs(v9 - *(v14 - 2)) <= 0.0099999998
        && fabs(v10 - *(v14 - 1)) <= 0.0099999998
        && fabs(pt[1].z - *v14) <= 0.0099999998
        && fabs((float)((float)(v5 * 2.0) - v9) - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].x) <= 0.0099999998
        && fabs(v17 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].y) <= 0.0099999998
        && fabs(v18 - pOther->m_Surf.m_Points[((_BYTE)v13 + 1) & 3].z) <= 0.0099999998 )
      {
        iNBEdge = v13;
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: 0,
          span: CORNER_TO_CORNER,
          pOther,
          iNeighborEdge: v13,
          nbSpan: CORNER_TO_MIDPOINT);
        goto LABEL_27;
      }
      ++v13;
      v14 += 3;
    }
    while ( v13 < 4 );
    iNBEdge = v13;
    vPoint1.x = (float)(v9 * 2.0) - pt[0].x;
    vPoint1.y = (float)(v10 * 2.0) - pt[0].y;
    vPoint1.z = (float)(pt[1].z * 2.0) - pt[0].z;
    if ( FindEdge(pInfo: pOther, &vPoint1, vPoint2: pt, iEdge: &iNBEdge) != 0 )
    {
      AddNeighbor(
        a1: v2,
        pMain,
        iEdge: v2,
        iSub: 0,
        span: CORNER_TO_CORNER,
        pOther,
        iNeighborEdge: iNBEdge,
        nbSpan: MIDPOINT_TO_CORNER);
    }
    else
    {
      if ( FindEdge(pInfo: pOther, vPoint1: &mid, vPoint2: pt, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: g_bEdgeNeighborFlip[v2],
          span: CORNER_TO_MIDPOINT,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
      if ( FindEdge(pInfo: pOther, vPoint1: &pt[1], vPoint2: &mid, iEdge: &iNBEdge) != 0 )
        AddNeighbor(
          a1: v2,
          pMain,
          iEdge: v2,
          iSub: !g_bEdgeNeighborFlip[v2],
          span: MIDPOINT_TO_CORNER,
          pOther,
          iNeighborEdge: iNBEdge,
          nbSpan: CORNER_TO_CORNER);
    }
LABEL_27:
    v21 += 3;
    if ( ++v2 < 4 )
    {
      v4 = v20;
      p_z = v21;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BB90
// Name: void SetupCornerNeighbors(class CCoreDispInfo __near *,class CCoreDispInfo __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupCornerNeighbors(CCoreDispInfo *pMain, CCoreDispInfo *pOther, int *nOverflows)
{
  CCoreDispInfo *v4; // edi
  CPowerInfo *v5; // eax
  const CVertIndex *CornerPointIndex; // ebx
  int i; // edi
  CPowerInfo *v8; // eax
  const CVertIndex *v9; // ebx
  Vector *p_m_Vert; // eax
  CDispCornerNeighbors *v11; // edi
  CDispCornerNeighbors *v12; // eax
  unsigned __int8 m_nNeighbors; // cl
  const Vector *vMainCorner; // [esp+8h] [ebp-10h]
  int iOtherSharedCorner; // [esp+Ch] [ebp-Ch]
  int iMainSharedCorner; // [esp+10h] [ebp-8h]
  int nShared; // [esp+14h] [ebp-4h]
  int iMainCorner; // [esp+24h] [ebp+Ch]

  v4 = pMain;
  if ( HasEdgeNeighbor(pMain, iNeighbor: pOther->m_nListIndex) == 0 )
  {
    nShared = 0;
    iMainSharedCorner = -1;
    iOtherSharedCorner = -1;
    iMainCorner = 0;
    while ( 1 )
    {
      v5 = (CPowerInfo *)v4->GetPowerInfo(this: v4);
      CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v5, iCorner: iMainCorner);
      vMainCorner = &v4->m_pVerts[CornerPointIndex->x
                                + *(_DWORD *)(v4->GetPowerInfo(this: v4) + 36) * CornerPointIndex->y].m_Vert;
      for ( i = 0; i < 4; ++i )
      {
        v8 = (CPowerInfo *)pOther->GetPowerInfo(this: pOther);
        v9 = CPowerInfo::GetCornerPointIndex(this: v8, iCorner: i);
        p_m_Vert = &pOther->m_pVerts[v9->x + *(_DWORD *)(pOther->GetPowerInfo(this: pOther) + 36) * v9->y].m_Vert;
        if ( fabs(vMainCorner->x - p_m_Vert->x) <= 0.001
          && fabs(vMainCorner->y - p_m_Vert->y) <= 0.001
          && fabs(vMainCorner->z - p_m_Vert->z) <= 0.001 )
        {
          ++nShared;
          iMainSharedCorner = iMainCorner;
          iOtherSharedCorner = i;
        }
      }
      if ( ++iMainCorner >= 4 )
        break;
      v4 = pMain;
    }
    if ( nShared == 1 )
    {
      v11 = pMain->GetCornerNeighbors(this: pMain, a2: iMainSharedCorner);
      v12 = pOther->GetCornerNeighbors(this: pOther, a2: iOtherSharedCorner);
      m_nNeighbors = v11->m_nNeighbors;
      if ( m_nNeighbors >= 4u || v12->m_nNeighbors >= 4u )
      {
        ++*nOverflows;
      }
      else
      {
        v11->m_Neighbors[m_nNeighbors] = pOther->m_nListIndex;
        ++v11->m_nNeighbors;
        v12->m_Neighbors[v12->m_nNeighbors++] = pMain->m_nListIndex;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BD20
// Name: bool VerifyNeighborVertConnection(class CDispUtilsHelper __near *,class CVertIndex const __near &,class CDispUtilsHelper const __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl VerifyNeighborVertConnection(
        CDispUtilsHelper *pDisp,
        CVertIndex *nodeIndex,
        const CDispUtilsHelper *pTestNeighbor,
        const CVertIndex *testNeighborIndex,
        int mySide)
{
  const CDispUtilsHelper *v5; // eax
  CDispUtilsHelper *v6; // esi
  CDispUtilsHelper_vtbl *v7; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(CDispUtilsHelper *); // eax
  int v9; // eax
  int EdgeIndexFromPoint; // eax
  bool result; // al
  CVertIndex testIndex; // [esp+Ch] [ebp-8h] BYREF
  CVertIndex nbIndex; // [esp+10h] [ebp-4h] BYREF

  nbIndex.x = -1;
  nbIndex.y = -1;
  v5 = TransformIntoNeighbor(pDisp, iEdge: mySide, nodeIndex, out: &nbIndex);
  v6 = (CDispUtilsHelper *)v5;
  result = true;
  if ( v5 != nullptr )
  {
    if ( pTestNeighbor != v5 )
      return false;
    if ( nbIndex.x != testNeighborIndex->x )
      return false;
    if ( nbIndex.y != testNeighborIndex->y )
      return false;
    v7 = v5->__vftable;
    testIndex.x = -1;
    GetPowerInfo = v7->GetPowerInfo;
    testIndex.y = -1;
    v9 = (int)GetPowerInfo(this: v6);
    EdgeIndexFromPoint = GetEdgeIndexFromPoint(index: &nbIndex, iMaxPower: *(_DWORD *)(v9 + 28));
    if ( EdgeIndexFromPoint == -1
      || TransformIntoNeighbor(pDisp: v6, iEdge: EdgeIndexFromPoint, nodeIndex: &nbIndex, out: &testIndex) != pDisp
      || CVertIndex::operator!=(this: nodeIndex, other: &testIndex) )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BDD0
// Name: BlendSubNeighbors
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendSubNeighbors(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // edi
  CDispNeighbor *v5; // eax
  CDispNeighbor *v6; // ebx
  int v7; // eax
  const Vector *p_m_Vert; // edi
  CCoreDispInfo *v9; // ebx
  int NeighborCornerVert; // esi
  CPowerInfo *v11; // eax
  CVertIndex v12; // ecx
  CDispNeighbor *v13; // esi
  int (__thiscall *v14)(CDispNeighbor *); // eax
  CPowerInfo *v15; // eax
  CVertIndex v16; // ecx
  int v17; // edi
  __int64 v18; // xmm0_8
  CCoreDispInfo_vtbl *v19; // edx
  float *v20; // eax
  float v21; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v23; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int v25; // eax
  int p_m_Normal; // eax
  int (__thiscall **v27)(CDispNeighbor *); // edx
  int (__thiscall *v28)(CDispNeighbor *); // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  float *v33; // eax
  float v34; // edx
  CCoreDispInfo_vtbl *v35; // eax
  int v36; // eax
  CoreDispVert_t *v37; // edx
  int v38; // ecx
  int (__thiscall *v39)(CDispNeighbor *); // edx
  int v40; // eax
  int v41; // edx
  int v42; // ecx
  CoreDispVert_t *v43; // edx
  float z; // xmm4_4
  float y; // xmm1_4
  char *v46; // eax
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  int v50; // [esp-10h] [ebp-54h]
  int v51; // [esp-10h] [ebp-54h]
  Vector vAvgTanS; // [esp+0h] [ebp-44h] BYREF
  Vector vecAverage; // [esp+Ch] [ebp-38h] BYREF
  int iCorners[2]; // [esp+18h] [ebp-2Ch]
  CVertIndex viCorners[2]; // [esp+20h] [ebp-24h] BYREF
  int v56; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h]
  int iDisp; // [esp+30h] [ebp-14h]
  CVertIndex viMidPoint; // [esp+34h] [ebp-10h] BYREF
  int iEdge; // [esp+38h] [ebp-Ch]
  CDispNeighbor *pEdge; // [esp+3Ch] [ebp-8h]
  CCoreDispInfo *pDisp; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( iDisp = 0; v2 < nListSize; iDisp = v2 )
  {
    v3 = ppListBase[v2];
    pDisp = v3;
    if ( v3 != nullptr )
    {
      v4 = 0;
      iEdge = 0;
      do
      {
        v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
        v6 = v5;
        pEdge = v5;
        if ( v5 != nullptr && v5->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v5->m_SubNeighbors[1].m_iNeighbor != 0xFFFF )
        {
          CDispUtilsHelper::GetEdgeMidPoint(this: v3, result: &viMidPoint, iEdge: v4);
          v7 = v3->GetPowerInfo(this: v3);
          p_m_Vert = &v3->m_pVerts[viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y].m_Vert;
          x = 224 * (viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y);
          v9 = ppListBase[v6->m_SubNeighbors[0].m_iNeighbor];
          pEdge = (CDispNeighbor *)ppListBase[pEdge->m_SubNeighbors[1].m_iNeighbor];
          iCorners[0] = FindNeighborCornerVert(pDisp: v9, vecPoint: p_m_Vert);
          NeighborCornerVert = FindNeighborCornerVert(pDisp: (CCoreDispInfo *)pEdge, vecPoint: p_m_Vert);
          if ( iCorners[0] != -1 && NeighborCornerVert != -1 )
          {
            v50 = iCorners[0];
            v11 = (CPowerInfo *)v9->GetPowerInfo(this: v9);
            v12 = *CPowerInfo::GetCornerPointIndex(this: v11, iCorner: v50);
            v51 = NeighborCornerVert;
            v13 = pEdge;
            v14 = **(int (__thiscall ***)(CDispNeighbor *))&pEdge->m_SubNeighbors[0].m_iNeighbor;
            viCorners[0] = v12;
            v15 = (CPowerInfo *)v14(a1: pEdge);
            v16 = *CPowerInfo::GetCornerPointIndex(this: v15, iCorner: v51);
            v17 = x;
            v18 = *(_QWORD *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            v19 = v9->__vftable;
            v20 = (float *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            viCorners[1] = v16;
            *(_QWORD *)&vecAverage.x = v18;
            v21 = v20[2];
            GetPowerInfo = v19->GetPowerInfo;
            vecAverage.z = v21;
            v23 = (int)GetPowerInfo(this: v9);
            m_pVerts = v9->m_pVerts;
            v25 = viCorners[0].x + viCorners[0].y * *(_DWORD *)(v23 + 36);
            *(float *)&v18 = m_pVerts[v25].m_Normal.x + vecAverage.x;
            p_m_Normal = (int)&m_pVerts[v25].m_Normal;
            LODWORD(vecAverage.x) = v18;
            *(float *)&v18 = *(float *)(p_m_Normal + 4) + vecAverage.y;
            x = viCorners[0].x;
            v27 = *(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            LODWORD(vecAverage.y) = v18;
            *(float *)&v18 = *(float *)(p_m_Normal + 8) + vecAverage.z;
            v28 = *v27;
            LODWORD(vecAverage.z) = v18;
            v29 = v28(a1: v13);
            v30 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v31 = 224 * (viCorners[1].x + viCorners[1].y * *(_DWORD *)(v29 + 36));
            *(float *)&v18 = *(float *)(v31 + v30 + 64) + vecAverage.x;
            v32 = v31 + v30 + 64;
            LODWORD(vecAverage.x) = v18;
            *(float *)&v18 = *(float *)(v32 + 4) + vecAverage.y;
            v56 = viCorners[1].x;
            LODWORD(vecAverage.y) = v18;
            vecAverage.z = *(float *)(v32 + 8) + vecAverage.z;
            VectorNormalize(vec: &vecAverage);
            v33 = (float *)((char *)&pDisp->m_pVerts->m_TangentS.x + v17);
            *(_QWORD *)&vAvgTanS.x = *(_QWORD *)v33;
            v34 = v33[2];
            v35 = v9->__vftable;
            vAvgTanS.z = v34;
            v36 = (int)v35->GetPowerInfo(this: v9);
            v37 = v9->m_pVerts;
            v38 = x + viCorners[0].y * *(_DWORD *)(v36 + 36);
            vAvgTanS.x = v37[v38].m_TangentS.x + vAvgTanS.x;
            vAvgTanS.y = v37[v38].m_TangentS.y + vAvgTanS.y;
            *(float *)&v18 = v37[v38].m_TangentS.z + vAvgTanS.z;
            v39 = **(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            LODWORD(vAvgTanS.z) = v18;
            v40 = v39(a1: v13);
            v41 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v42 = 224 * (v56 + viCorners[1].y * *(_DWORD *)(v40 + 36));
            vAvgTanS.x = vAvgTanS.x + *(float *)(v42 + v41 + 76);
            vAvgTanS.y = *(float *)(v42 + v41 + 80) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v42 + v41 + 84) + vAvgTanS.z;
            VectorNormalize(vec: &vAvgTanS);
            v43 = pDisp->m_pVerts;
            *(Vector *)((char *)&v43->m_Normal + v17) = vecAverage;
            z = vecAverage.z;
            y = vecAverage.y;
            v46 = (char *)v43 + v17;
            v47 = vAvgTanS.y * vecAverage.x;
            *(float *)&v18 = vAvgTanS.z * vecAverage.x;
            v48 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
            v49 = vAvgTanS.x;
            *(Vector *)(v46 + 76) = vAvgTanS;
            *((float *)v46 + 22) = v48;
            *((float *)v46 + 23) = *(float *)&v18 - (float)(z * v49);
            *((float *)v46 + 24) = (float)(y * v49) - v47;
            UpdateTangentSpace(vNormal: &vecAverage, vTanS: &vAvgTanS, pDisp: v9, index: viCorners);
            UpdateTangentSpace(
              vNormal: &vecAverage,
              vTanS: &vAvgTanS,
              pDisp: (CCoreDispInfo *)pEdge,
              index: &viCorners[1]);
          }
          v3 = pDisp;
          v4 = iEdge;
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      v2 = iDisp;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C170
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C330
// Name: public: bool CDispEdgeIterator::Next(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispEdgeIterator::Next(CDispEdgeIterator *this)
{
  CVertIndex *p_m_Index; // edi
  CVertIndex *p_m_NBIndex; // ebx
  int m_iCurSub; // eax
  int m_iEdge; // ecx
  CDispUtilsHelper *v6; // eax

  this->m_It.m_Index.x += this->m_It.m_Inc.x;
  this->m_It.m_Index.y += this->m_It.m_Inc.y;
  this->m_It.m_NBIndex.x += this->m_It.m_NBInc.x;
  this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
  p_m_Index = &this->m_It.m_Index;
  p_m_NBIndex = &this->m_It.m_NBIndex;
  if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
    return 1;
  while ( 1 )
  {
    m_iCurSub = this->m_iCurSub;
    if ( m_iCurSub == 1 )
      break;
    m_iEdge = this->m_iEdge;
    this->m_iCurSub = m_iCurSub + 1;
    v6 = SetupEdgeIncrements(
           pDisp: this->m_pDisp,
           iEdge: m_iEdge,
           iSub: m_iCurSub + 1,
           myIndex: &this->m_It.m_Index,
           myInc: &this->m_It.m_Inc,
           nbIndex: &this->m_It.m_NBIndex,
           nbInc: &this->m_It.m_NBInc,
           myEnd: &this->m_It.m_End,
           iFreeDim: &this->m_It.m_FreeDim);
    this->m_It.m_pNeighbor = v6;
    if ( v6 == nullptr )
    {
      this->m_It.m_End = 0;
      this->m_It.m_Inc.x = 0;
      p_m_Index->x = 0;
      this->m_It.m_FreeDim = 0;
    }
    p_m_Index->x += this->m_It.m_Inc.x;
    this->m_It.m_Index.y += this->m_It.m_Inc.y;
    p_m_NBIndex->x += this->m_It.m_NBInc.x;
    this->m_It.m_NBIndex.y += this->m_It.m_NBInc.y;
    if ( *(&this->m_It.m_Index.x + SLOWORD(this->m_It.m_FreeDim)) < this->m_It.m_End )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C3F0
// Name: void VerifyNeighborConnections(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VerifyNeighborConnections(CCoreDispInfo **ppListBase, int nDisps)
{
  char v2; // bl
  CCoreDispInfo *v3; // esi
  int v4; // edi
  _WORD *v5; // eax
  CPowerInfo *v6; // eax
  const CVertIndex *CornerPointIndex; // edi
  int p_m_Vert; // ebx
  CPowerInfo *v9; // eax
  const CVertIndex *v10; // edi
  int v11; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  CPowerInfo *v13; // eax
  const CVertIndex *v14; // edi
  int v15; // eax
  int v16; // [esp+18h] [ebp-44h]
  CDispEdgeIterator it; // [esp+28h] [ebp-34h] BYREF
  int v18; // [esp+50h] [ebp-Ch]
  int iEdge; // [esp+54h] [ebp-8h]
  int iDisp; // [esp+58h] [ebp-4h]

  do
  {
    v2 = 1;
    iDisp = 0;
    if ( nDisps <= 0 )
      break;
    v3 = *ppListBase;
    v4 = 0;
    for ( iEdge = 0; ; iEdge = 0 )
    {
      do
      {
        it.m_It.m_Inc.x = 0;
        it.m_It.m_pNeighbor = nullptr;
        it.m_It.m_End = 0;
        it.m_It.m_Index.x = 0;
        it.m_It.m_FreeDim = 0;
        it.m_pDisp = v3;
        it.m_iEdge = v4;
        it.m_iCurSub = -1;
        while ( CDispEdgeIterator::Next(this: &it) != 0 )
        {
          if ( !VerifyNeighborVertConnection(
                  pDisp: v3,
                  nodeIndex: &it.m_It.m_Index,
                  pTestNeighbor: it.m_It.m_pNeighbor,
                  testNeighborIndex: &it.m_It.m_NBIndex,
                  mySide: v4) )
          {
            v16 = v4;
            v5 = (_WORD *)((int (__thiscall *)(CCoreDispInfo *))v3->GetEdgeNeighbor)(a1: v3);
            *v5 = -1;
            v5[3] = -1;
            v6 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            CornerPointIndex = CPowerInfo::GetCornerPointIndex(this: v6, iCorner: 0);
            p_m_Vert = (int)&v3->m_pVerts[CornerPointIndex->x
                                        + *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * CornerPointIndex->y].m_Vert;
            v9 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
            v10 = CPowerInfo::GetCornerPointIndex(this: v9, iCorner: 0);
            v11 = *(_DWORD *)(v3->GetPowerInfo(this: v3) + 36) * v10->y;
            GetPowerInfo = v3->GetPowerInfo;
            v18 = (int)&v3->m_pVerts[v10->x + v11].m_Vert;
            v13 = (CPowerInfo *)((int (__thiscall *)(CCoreDispInfo *, _DWORD))GetPowerInfo)(a1: v3, a2: 0);
            v14 = CPowerInfo::GetCornerPointIndex(this: v13, iCorner: v16);
            v15 = v3->GetPowerInfo(this: v3);
            _Warning(
              a1: "Warning: invalid neighbor connection on displacement near (%.2f %.2f %.2f)\n",
              v3->m_pVerts[v14->x + *(_DWORD *)(v15 + 36) * v14->y].m_Vert.x,
              *(float *)(v18 + 4),
              *(float *)(p_m_Vert + 8));
            v2 = 0;
            v4 = iEdge;
          }
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      if ( ++iDisp >= nDisps )
        break;
      v3 = ppListBase[iDisp];
      v4 = 0;
    }
  }
  while ( v2 == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0041C5D0
// Name: bool IsVertAllowed(class CDispUtilsHelper __near *,class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsVertAllowed(CDispUtilsHelper *pDisp, CVertIndex sideVert, int iLevel)
{
  int v4; // eax
  const CVertIndex *v5; // edi
  int v6; // ecx
  __int16 v7; // ax
  int v8; // edx
  int v9; // ecx
  __int16 v10; // ax
  __int16 y; // cx
  int SubNeighborIndex; // edi
  CDispSubNeighbor *v14; // ebx
  CDispUtilsHelper *v15; // edi
  CShiftInfo *v16; // ebx
  int v17; // eax
  int v18; // eax
  int iSub; // [esp+8h] [ebp-4h]
  int iSide; // [esp+14h] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = (const CVertIndex *)sideVert;
  v6 = *(_DWORD *)(v4 + 36);
  if ( *(_WORD *)sideVert.x == 0 )
  {
    v7 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v7 != 0 && v7 != v6 - 1 )
      goto LABEL_4;
    return true;
  }
  v9 = v6 - 1;
  if ( *(__int16 *)sideVert.x == v9 )
  {
    v10 = *(_WORD *)(*(_DWORD *)&sideVert + 2);
    if ( v10 == 0 || v10 == v9 )
      return true;
  }
LABEL_4:
  v8 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  if ( v5->x != 0 )
  {
    y = v5->y;
    if ( y == v8 )
    {
      iSide = 1;
    }
    else if ( v5->x == v8 )
    {
      iSide = 2;
    }
    else
    {
      if ( y != 0 )
        return true;
      iSide = 3;
    }
  }
  else
  {
    iSide = 0;
  }
  SubNeighborIndex = GetSubNeighborIndex(pDisp, iEdge: iSide, nodeIndex: v5);
  iSub = SubNeighborIndex;
  if ( SubNeighborIndex == -1 )
    return true;
  v14 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iSide)->m_SubNeighbors[SubNeighborIndex];
  v15 = pDisp->GetDispUtilsByIndex(this: pDisp, a2: v14->m_iNeighbor);
  v16 = &g_ShiftInfos[v14->m_Span][v14->m_NeighborSpan];
  v17 = v15->GetPowerInfo(this: v15);
  if ( v16->m_PowerShiftAdd + *(_DWORD *)(v17 + 28) < iLevel + 1 )
    return false;
  TransformIntoSubNeighbor(
    pDisp,
    iEdge: iSide,
    (CVertIndex)iSub,
    nodeIndex: *(const CVertIndex **)&sideVert,
    out: &sideVert);
  v18 = v15->GetPowerInfo(this: v15);
  return ((int)v15[((unsigned int)(sideVert.x + *(_DWORD *)(v18 + 36) * sideVert.y) >> 5) + 200].__vftable
        & (1 << ((LOBYTE(sideVert.x) + *(_BYTE *)(v18 + 36) * LOBYTE(sideVert.y)) & 0x1F))) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C740
// Name: void UnallowVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnallowVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int *nUnallowed)
{
  int v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edi
  const CVertIndex *v8; // eax
  int pDispa; // [esp+Ch] [ebp+8h]

  v4 = pDisp->GetPowerInfo(this: pDisp);
  v5 = nodeIndex->x + *(_DWORD *)(v4 + 36) * nodeIndex->y;
  v6 = 1 << ((nodeIndex->x + *(_BYTE *)(v4 + 36) * nodeIndex->y) & 0x1F);
  if ( (v6 & (int)pDisp[((unsigned int)v5 >> 5) + 200].__vftable) != 0 )
  {
    ++*nUnallowed;
    pDisp[(v5 >> 5) + 200].__vftable = (CDispUtilsHelper_vtbl *)((int)pDisp[(v5 >> 5) + 200].__vftable & ~v6);
    v7 = 42 * v5 + 12;
    for ( pDispa = 4; pDispa != 0; --pDispa )
    {
      v8 = (const CVertIndex *)(v7 + *(_DWORD *)pDisp->GetPowerInfo(this: pDisp));
      if ( v8->x != -1 && v8[1].x == -1 )
        UnallowVerts_R(pDisp, nodeIndex: v8, nUnallowed);
      v7 += 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C7E0
// Name: void DisableUnallowedVerts_R(class CDispUtilsHelper __near *,class CVertIndex const __near &,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisableUnallowedVerts_R(CDispUtilsHelper *pDisp, const CVertIndex *nodeIndex, int iLevel, int *nUnallowed)
{
  const CVertIndex *v5; // ebx
  const CVertIndex *v6; // edi
  int v7; // ebx
  const CVertIndex *v8; // edi
  int v9; // eax
  int pDispa; // [esp+14h] [ebp+8h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+Ch]
  int iLevela; // [esp+1Ch] [ebp+10h]

  nodeIndexa = (const CVertIndex *)(16
                                  * (nodeIndex->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * nodeIndex->y));
  v5 = nodeIndexa;
  for ( pDispa = 4; pDispa != 0; --pDispa )
  {
    v6 = (const CVertIndex *)((char *)v5 + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 4));
    if ( !IsVertAllowed(pDisp, sideVert: (CVertIndex)v6, iLevel) )
      UnallowVerts_R(pDisp, nodeIndex: v6, nUnallowed);
    ++v5;
  }
  v7 = iLevel + 1;
  if ( iLevel + 1 < *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28) )
  {
    v8 = nodeIndexa;
    for ( iLevela = 4; iLevela != 0; --iLevela )
    {
      v9 = pDisp->GetPowerInfo(this: pDisp);
      DisableUnallowedVerts_R(
        pDisp,
        nodeIndex: (const CVertIndex *)((char *)v8++ + *(_DWORD *)(v9 + 8)),
        iLevel: v7,
        nUnallowed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C890
// Name: void SetupAllowedVerts(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupAllowedVerts(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // edx
  CBitVec<289> *p_m_AllowedVerts; // eax
  int v5; // edi
  CCoreDispInfo *v6; // esi
  const CVertIndex *v7; // eax
  int nUnallowed; // [esp+Ch] [ebp-4h] BYREF
  char bContinue_3; // [esp+1Fh] [ebp+Fh]

  for ( i = 0; i < nListSize; ++i )
  {
    p_m_AllowedVerts = &ppListBase[i]->m_AllowedVerts;
    if ( ppListBase[i] != (CCoreDispInfo *)-800 )
    {
      p_m_AllowedVerts->m_Ints[0] = -1;
      p_m_AllowedVerts->m_Ints[1] = -1;
      p_m_AllowedVerts->m_Ints[2] = -1;
      p_m_AllowedVerts->m_Ints[3] = -1;
      p_m_AllowedVerts->m_Ints[4] = -1;
      p_m_AllowedVerts->m_Ints[5] = -1;
      p_m_AllowedVerts->m_Ints[6] = -1;
      p_m_AllowedVerts->m_Ints[7] = -1;
      p_m_AllowedVerts->m_Ints[8] = -1;
      p_m_AllowedVerts->m_Ints[9] = -1;
    }
  }
  do
  {
    v5 = 0;
    bContinue_3 = 0;
    if ( nListSize <= 0 )
      break;
    do
    {
      v6 = ppListBase[v5];
      nUnallowed = 0;
      v7 = (const CVertIndex *)v6->GetPowerInfo(this: v6);
      DisableUnallowedVerts_R(pDisp: v6, nodeIndex: v7 + 8, iLevel: 0, &nUnallowed);
      if ( nUnallowed != 0 )
        bContinue_3 = 1;
      ++v5;
    }
    while ( v5 < nListSize );
  }
  while ( bContinue_3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0041C930
// Name: BlendEdges
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendEdges(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // ebx
  CDispNeighbor *v5; // eax
  int v6; // ecx
  int m_iNeighbor; // eax
  CCoreDispInfo *v8; // ebx
  __int16 x; // ax
  CVertIndex m_Index; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int y; // edi
  int p_m_Normal; // edx
  CCoreDispInfo_vtbl *v16; // eax
  int v17; // eax
  CoreDispVert_t *m_pVerts; // ecx
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v24; // eax
  CCoreDispInfo_vtbl *v25; // edx
  int v26; // eax
  CoreDispVert_t *v27; // edx
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  int v31; // eax
  CCoreDispInfo_vtbl *v32; // edx
  int v33; // eax
  float z; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  int v40; // eax
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // ecx
  int v50; // edx
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  int v55; // eax
  float *p_x; // edi
  int v57; // eax
  CoreDispVert_t *v58; // edx
  int v59; // ecx
  int v60; // eax
  float *v61; // edi
  int v62; // eax
  CoreDispVert_t *v63; // edx
  int v64; // ecx
  int v65; // eax
  int v66; // edi
  CCoreDispInfo_vtbl *v67; // edx
  int v68; // eax
  int v69; // ecx
  CoreDispVert_t *v70; // eax
  int v71; // ecx
  CoreDispVert_t *v72; // eax
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  CVertIndex v79; // ecx
  int iCurPos; // [esp+4h] [ebp-94h]
  CVertIndex *v81; // [esp+8h] [ebp-90h]
  _WORD *v82; // [esp+Ch] [ebp-8Ch]
  float v83; // [esp+10h] [ebp-88h]
  __int16 v84; // [esp+14h] [ebp-84h]
  float v85; // [esp+18h] [ebp-80h]
  CVertIndex *v86; // [esp+1Ch] [ebp-7Ch]
  Vector vec; // [esp+20h] [ebp-78h] BYREF
  int iSubEdge; // [esp+2Ch] [ebp-6Ch]
  int iDisp; // [esp+30h] [ebp-68h]
  int iEdgeDim; // [esp+34h] [ebp-64h]
  CDispNeighbor *v91; // [esp+38h] [ebp-60h]
  int v92; // [esp+3Ch] [ebp-5Ch]
  Vector vecNormal; // [esp+40h] [ebp-58h] BYREF
  int iTween; // [esp+4Ch] [ebp-4Ch]
  CVertIndex viTween; // [esp+50h] [ebp-48h] BYREF
  int iEdge; // [esp+54h] [ebp-44h]
  Vector vAvgTanS; // [esp+58h] [ebp-40h] BYREF
  float flPercent; // [esp+64h] [ebp-34h]
  Vector vecAverage; // [esp+68h] [ebp-30h] BYREF
  CVertIndex viPrevPos; // [esp+74h] [ebp-24h]
  Vector *p_m_TangentS; // [esp+78h] [ebp-20h]
  CDispSubEdgeIterator it; // [esp+7Ch] [ebp-1Ch] BYREF

  v2 = 0;
  iDisp = 0;
  if ( nListSize <= 0 )
    return;
  do
  {
    v3 = ppListBase[v2];
    if ( v3 == nullptr )
      goto LABEL_30;
    v4 = 0;
    iEdge = 0;
    do
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
      if ( v5 == nullptr )
        goto LABEL_28;
      v6 = 0;
      iSubEdge = 0;
      v91 = v5;
      do
      {
        m_iNeighbor = v5->m_SubNeighbors[0].m_iNeighbor;
        if ( (_WORD)m_iNeighbor != 0xFFFF )
        {
          v8 = ppListBase[m_iNeighbor];
          if ( v8 != nullptr )
          {
            iEdgeDim = g_EdgeDims[iEdge];
            it.m_Inc.x = 0;
            it.m_Index.x = 0;
            it.m_pNeighbor = nullptr;
            it.m_End = 0;
            it.m_FreeDim = 0;
            it.m_pNeighbor = SetupEdgeIncrements(
                               pDisp: v3,
                               iEdge,
                               iSub: v6,
                               myIndex: &it.m_Index,
                               myInc: &it.m_Inc,
                               nbIndex: &it.m_NBIndex,
                               nbInc: &it.m_NBInc,
                               myEnd: &it.m_End,
                               iFreeDim: &it.m_FreeDim);
            if ( it.m_pNeighbor != nullptr )
            {
              it.m_Index.y -= it.m_Inc.y;
              it.m_NBIndex.x -= it.m_NBInc.x;
              x = it.m_Inc.x;
              it.m_Index.x -= it.m_Inc.x;
              it.m_NBIndex.y -= it.m_NBInc.y;
              it.m_End += *(&it.m_Inc.x + SLOWORD(it.m_FreeDim));
            }
            else
            {
              it.m_Index.x = 0;
              it.m_End = 0;
              it.m_Inc.x = 0;
              it.m_FreeDim = 0;
              x = 0;
            }
            it.m_Index.y += it.m_Inc.y;
            it.m_Index.x += x;
            it.m_NBIndex.x += it.m_NBInc.x;
            m_Index = it.m_Index;
            it.m_Index.x += x;
            it.m_Index.y += it.m_Inc.y;
            it.m_NBIndex.y += it.m_NBInc.y + it.m_NBInc.y;
            viPrevPos = m_Index;
            it.m_NBIndex.x += it.m_NBInc.x;
            v11 = 2 * SLOWORD(it.m_FreeDim);
            v81 = (CVertIndex *)((char *)&it.m_Index + v11);
            v12 = *(__int16 *)((char *)&it.m_Index.x + v11);
            if ( v12 < it.m_End )
            {
              v86 = (CVertIndex *)((char *)&it.m_Inc + v11);
              v92 = 2 * (iEdgeDim == 0);
              while ( 1 )
              {
                if ( v12 + v86->x < it.m_End )
                {
                  v13 = v8->GetPowerInfo(this: v8);
                  y = it.m_NBIndex.y;
                  p_m_Normal = (int)&v8->m_pVerts[it.m_NBIndex.x + it.m_NBIndex.y * *(_DWORD *)(v13 + 36)].m_Normal;
                  v16 = v3->__vftable;
                  p_m_TangentS = (Vector *)p_m_Normal;
                  v17 = (int)v16->GetPowerInfo(this: v3);
                  m_pVerts = v3->m_pVerts;
                  v19 = v8->__vftable;
                  v20 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v17 + 36);
                  v21 = m_pVerts[v20].m_Normal.x;
                  v22 = (int)&m_pVerts[v20].m_Normal;
                  vecAverage.x = v21 + p_m_TangentS->x;
                  vecAverage.y = *(float *)(v22 + 4) + p_m_TangentS->y;
                  GetPowerInfo = v19->GetPowerInfo;
                  vecAverage.z = *(float *)(v22 + 8) + p_m_TangentS->z;
                  v24 = (int)GetPowerInfo(this: v8);
                  v25 = v3->__vftable;
                  p_m_TangentS = &v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v24 + 36)].m_TangentS;
                  v26 = (int)v25->GetPowerInfo(this: v3);
                  v27 = v3->m_pVerts;
                  v28 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v26 + 36);
                  v29 = p_m_TangentS->x + v27[v28].m_TangentS.x;
                  v30 = (int)&v27[v28].m_TangentS;
                  vAvgTanS.x = v29;
                  vAvgTanS.y = *(float *)(v30 + 4) + p_m_TangentS->y;
                  vAvgTanS.z = *(float *)(v30 + 8) + p_m_TangentS->z;
                  VectorNormalize(vec: &vecAverage);
                  VectorNormalize(vec: &vAvgTanS);
                  v31 = v3->GetPowerInfo(this: v3);
                  v32 = v8->__vftable;
                  v33 = (int)&v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v31 + 36)];
                  *(Vector *)(v33 + 64) = vecAverage;
                  z = vecAverage.z;
                  v35 = vecAverage.y;
                  v36 = vAvgTanS.y * vecAverage.x;
                  v37 = vAvgTanS.z * vecAverage.x;
                  v38 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v39 = vAvgTanS.x;
                  *(Vector *)(v33 + 76) = vAvgTanS;
                  *(float *)(v33 + 88) = v38;
                  *(float *)(v33 + 92) = v37 - (float)(z * v39);
                  *(float *)(v33 + 96) = (float)(v35 * v39) - v36;
                  v40 = (int)v32->GetPowerInfo(this: v8);
                  v41 = (int)&v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v40 + 36)];
                  *(Vector *)(v41 + 64) = vecAverage;
                  v42 = vecAverage.z;
                  v43 = vecAverage.y;
                  v44 = vAvgTanS.y * vecAverage.x;
                  v45 = vAvgTanS.z * vecAverage.x;
                  v46 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v47 = vAvgTanS.x;
                  *(Vector *)(v41 + 76) = vAvgTanS;
                  *(float *)(v41 + 88) = v46;
                  *(float *)(v41 + 92) = v45 - (float)(v42 * v47);
                  *(float *)(v41 + 96) = (float)(v43 * v47) - v44;
                }
                v48 = *(__int16 *)((char *)&viPrevPos.x + v92);
                v49 = *(__int16 *)((char *)&it.m_Index.x + v92);
                v50 = v48 + 1;
                iCurPos = v49;
                iTween = v48 + 1;
                if ( v48 + 1 < v49 )
                  break;
LABEL_25:
                v79 = it.m_Index;
                it.m_Index.x += it.m_Inc.x;
                it.m_Index.y += it.m_Inc.y;
                it.m_NBIndex.y += it.m_NBInc.y;
                viPrevPos = v79;
                it.m_NBIndex.x += it.m_NBInc.x;
                v12 = v81->x;
                if ( v12 >= it.m_End )
                  goto LABEL_26;
              }
              v51 = (float)v48;
              p_m_TangentS = (Vector *)viPrevPos.x;
              v52 = (float)v49;
              v85 = (float)v48;
              v83 = (float)v49;
              v82 = (_WORD *)&viTween + (__int16)iEdgeDim;
              v84 = *(&it.m_Index.x + (__int16)iEdgeDim);
              while ( 1 )
              {
                v53 = (float)v50;
                if ( v51 == v52 )
                {
                  if ( (float)(v53 - v52) < 0.0 )
                  {
                    flPercent = 0.0;
                    goto LABEL_24;
                  }
                  v54 = 1.0;
                }
                else
                {
                  v54 = (float)(v53 - v51) / (float)(v52 - v51);
                }
                flPercent = v54;
LABEL_24:
                v55 = v3->GetPowerInfo(this: v3);
                p_x = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v55 + 36)].m_Normal.x;
                v57 = v3->GetPowerInfo(this: v3);
                v58 = v3->m_pVerts;
                v59 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v57 + 36);
                vecNormal.x = (float)((float)(*p_x - v58[v59].m_Normal.x) * flPercent) + v58[v59].m_Normal.x;
                vecNormal.y = (float)((float)(p_x[1] - v58[v59].m_Normal.y) * flPercent) + v58[v59].m_Normal.y;
                vecNormal.z = (float)((float)(p_x[2] - v58[v59].m_Normal.z) * flPercent) + v58[v59].m_Normal.z;
                VectorNormalize(vec: &vecNormal);
                v60 = v3->GetPowerInfo(this: v3);
                v61 = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v60 + 36)].m_TangentS.x;
                v62 = v3->GetPowerInfo(this: v3);
                v63 = v3->m_pVerts;
                v64 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v62 + 36);
                vec.x = (float)((float)(*v61 - v63[v64].m_TangentS.x) * flPercent) + v63[v64].m_TangentS.x;
                vec.y = (float)((float)(v61[1] - v63[v64].m_TangentS.y) * flPercent) + v63[v64].m_TangentS.y;
                vec.z = (float)((float)(v61[2] - v63[v64].m_TangentS.z) * flPercent) + v63[v64].m_TangentS.z;
                VectorNormalize(&vec);
                v65 = v92;
                v66 = iTween;
                *v82 = v84;
                v67 = v3->__vftable;
                *(__int16 *)((char *)&viTween.x + v65) = v66;
                v68 = (int)v67->GetPowerInfo(this: v3);
                v69 = *(_DWORD *)(v68 + 36) * viTween.y;
                v70 = v3->m_pVerts;
                v71 = viTween.x + v69;
                v70[v71].m_Normal.x = vecNormal.x;
                v70[v71].m_Normal.y = vecNormal.y;
                v72 = &v70[v71];
                v72->m_Normal.z = vecNormal.z;
                v73 = vecNormal.z;
                v74 = vecNormal.y;
                v75 = vec.y * vecNormal.x;
                v76 = vec.z * vecNormal.x;
                v77 = (float)(vec.y * vecNormal.z) - (float)(vec.z * vecNormal.y);
                v78 = vec.x;
                v72->m_TangentS = vec;
                v72->m_TangentT.x = v77;
                v72->m_TangentT.y = v76 - (float)(v73 * v78);
                v72->m_TangentT.z = (float)(v74 * v78) - v75;
                iTween = v66 + 1;
                if ( v66 + 1 >= iCurPos )
                  goto LABEL_25;
                v52 = v83;
                v51 = v85;
                v50 = iTween;
              }
            }
          }
        }
LABEL_26:
        v6 = iSubEdge + 1;
        v5 = (CDispNeighbor *)&v91->m_SubNeighbors[1];
        iSubEdge = v6;
        v91 = (CDispNeighbor *)((char *)v91 + 6);
      }
      while ( v6 < 2 );
      v4 = iEdge;
LABEL_28:
      iEdge = ++v4;
    }
    while ( v4 < 4 );
    v2 = iDisp;
LABEL_30:
    iDisp = ++v2;
  }
  while ( v2 < nListSize );
}

//------------------------------------------------------------------------------
// Address: 0x0041D090
// Name: BlendCorners
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendCorners(CCoreDispInfo **ppListBase, int nListSize)
{
  int *m_pMemory; // ebx
  CCoreDispInfo *v3; // edi
  int AllNeighbors; // esi
  int m_Size; // eax
  int *v6; // eax
  CPowerInfo *v7; // eax
  CVertIndex v8; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v10; // eax
  int v11; // ebx
  CoreDispVert_t *v12; // eax
  float z; // edx
  const Vector *p_m_Vert; // ecx
  int p_m_TangentS; // eax
  float v16; // xmm0_4
  CVertIndex v17; // eax
  CCoreDispInfo *v18; // esi
  int NeighborCornerVert; // eax
  CPowerInfo *v20; // eax
  CVertIndex v21; // edi
  const CPowerInfo *(__thiscall *v22)(struct CCoreDispInfo *); // eax
  int v23; // eax
  int v24; // ecx
  CoreDispVert_t *m_pVerts; // edx
  CoreDispVert_t *v26; // eax
  float v27; // xmm0_4
  int v28; // eax
  float v29; // xmm3_4
  float y; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float x; // xmm5_4
  float *p_x; // ebx
  int v36; // edx
  int *v37; // ecx
  int v38; // eax
  int v39; // eax
  CoreDispVert_t *v40; // esi
  float v41; // xmm3_4
  float v42; // xmm0_4
  CoreDispVert_t *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // eax
  CoreDispVert_t *v50; // esi
  float v51; // xmm3_4
  float v52; // xmm0_4
  CoreDispVert_t *v53; // eax
  float v54; // xmm1_4
  float v55; // xmm4_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  int v58; // eax
  CoreDispVert_t *v59; // esi
  float v60; // xmm3_4
  float v61; // xmm0_4
  CoreDispVert_t *v62; // eax
  float v63; // xmm1_4
  float v64; // xmm4_4
  float v65; // xmm2_4
  float v66; // xmm5_4
  int v67; // eax
  CoreDispVert_t *v68; // eax
  float v69; // xmm3_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm4_4
  float v73; // xmm2_4
  float v74; // xmm5_4
  CVertIndex v75; // ebx
  int *v76; // ecx
  int v77; // eax
  CoreDispVert_t *v78; // edx
  float v79; // xmm3_4
  float v80; // xmm0_4
  CoreDispVert_t *v81; // eax
  float v82; // xmm1_4
  float v83; // xmm4_4
  float v84; // xmm2_4
  float v85; // xmm5_4
  int v86; // [esp-Ch] [ebp-860h]
  int v87; // [esp-Ch] [ebp-860h]
  int iNeighbors[512]; // [esp+4h] [ebp-850h] BYREF
  CCoreDispInfo *pDisp; // [esp+804h] [ebp-50h]
  const Vector *vCornerVert; // [esp+808h] [ebp-4Ch]
  CVertIndex viNBCornerVert; // [esp+80Ch] [ebp-48h]
  int iCorner; // [esp+810h] [ebp-44h]
  int iDisp; // [esp+814h] [ebp-40h]
  CUtlVector<int,CUtlMemory<int,int> > nbCornerVerts; // [esp+818h] [ebp-3Ch] BYREF
  int *v95; // [esp+82Ch] [ebp-28h]
  int nNeighbors; // [esp+830h] [ebp-24h]
  int v97; // [esp+834h] [ebp-20h]
  CVertIndex cornerVert; // [esp+838h] [ebp-1Ch]
  Vector vAvgTanS; // [esp+83Ch] [ebp-18h] BYREF
  Vector vAverage; // [esp+848h] [ebp-Ch] BYREF

  m_pMemory = nullptr;
  memset(&nbCornerVerts, 0, sizeof(nbCornerVerts));
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    pDisp = ppListBase[iDisp];
    v3 = pDisp;
    AllNeighbors = GetAllNeighbors(iNeighbors, pDisp);
    m_Size = 0;
    nNeighbors = AllNeighbors;
    nbCornerVerts.m_Size = 0;
    if ( nbCornerVerts.m_Memory.m_nAllocationCount < AllNeighbors && nbCornerVerts.m_Memory.m_nGrowSize >= 0 )
    {
      nbCornerVerts.m_Memory.m_nAllocationCount = AllNeighbors;
      if ( m_pMemory != nullptr )
        v6 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 4 * AllNeighbors);
      else
        v6 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * AllNeighbors);
      nbCornerVerts.m_Memory.m_pMemory = v6;
      m_Size = nbCornerVerts.m_Size;
      m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
    }
    nbCornerVerts.m_pElements = m_pMemory;
    if ( AllNeighbors != 0 )
    {
      if ( AllNeighbors > nbCornerVerts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&nbCornerVerts,
          num: AllNeighbors - nbCornerVerts.m_Memory.m_nAllocationCount);
        m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
        m_Size = nbCornerVerts.m_Size;
      }
      nbCornerVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && AllNeighbors > 0 )
        _V_memmove(dest: &m_pMemory[AllNeighbors], src: m_pMemory, count: 4 * m_Size);
    }
    for ( iCorner = 0; iCorner < 4; ++iCorner )
    {
      v86 = iCorner;
      v7 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
      v8 = *CPowerInfo::GetCornerPointIndex(this: v7, iCorner: v86);
      GetPowerInfo = v3->GetPowerInfo;
      cornerVert = v8;
      v10 = (int)GetPowerInfo(this: v3);
      v11 = cornerVert.x + *(_DWORD *)(v10 + 36) * cornerVert.y;
      v12 = &v3->m_pVerts[v11];
      *(_QWORD *)&vAverage.x = *(_QWORD *)&v12->m_Normal.x;
      z = v12->m_Normal.z;
      p_m_Vert = &v12->m_Vert;
      p_m_TangentS = (int)&v3->m_pVerts[v11].m_TangentS;
      vAverage.z = z;
      vAvgTanS.x = *(float *)p_m_TangentS;
      vAvgTanS.y = *(float *)(p_m_TangentS + 4);
      v16 = *(float *)(p_m_TangentS + 8);
      vCornerVert = p_m_Vert;
      vAvgTanS.z = v16;
      if ( AllNeighbors > 0 )
      {
        v17 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = nbCornerVerts.m_Memory.m_pMemory;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v97 = AllNeighbors;
        while ( 1 )
        {
          v18 = ppListBase[*(int *)((char *)v95 + *(_DWORD *)&v17)];
          NeighborCornerVert = FindNeighborCornerVert(pDisp: v18, vecPoint: vCornerVert);
          if ( NeighborCornerVert == -1 )
          {
            *v95 = -1;
          }
          else
          {
            v87 = NeighborCornerVert;
            v20 = (CPowerInfo *)v18->GetPowerInfo(this: v18);
            v21 = *CPowerInfo::GetCornerPointIndex(this: v20, iCorner: v87);
            v22 = v18->GetPowerInfo;
            viNBCornerVert = v21;
            v23 = (int)v22(this: v18);
            v24 = v21.x + *(_DWORD *)(v23 + 36) * viNBCornerVert.y;
            *v95 = v24;
            v24 *= 224;
            m_pVerts = v18->m_pVerts;
            vAverage.x = *(float *)((char *)&m_pVerts->m_Normal.x + v24) + vAverage.x;
            vAverage.y = *(float *)((char *)&m_pVerts->m_Normal.y + v24) + vAverage.y;
            vAverage.z = *(float *)((char *)&m_pVerts->m_Normal.z + v24) + vAverage.z;
            v26 = v18->m_pVerts;
            v27 = *(float *)((char *)&v26->m_TangentS.x + v24) + vAvgTanS.x;
            v28 = (int)&v26->m_TangentS + v24;
            vAvgTanS.x = v27;
            vAvgTanS.y = *(float *)(v28 + 4) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v28 + 8) + vAvgTanS.z;
          }
          ++v95;
          if ( --v97 == 0 )
            break;
          v17 = cornerVert;
        }
        AllNeighbors = nNeighbors;
        v3 = pDisp;
      }
      VectorNormalize(vec: &vAverage);
      VectorNormalize(vec: &vAvgTanS);
      v3->m_pVerts[v11].m_Normal = vAverage;
      v29 = vAverage.z;
      y = vAverage.y;
      v31 = vAvgTanS.z * vAverage.x;
      v32 = vAvgTanS.y * vAverage.x;
      v33 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
      x = vAvgTanS.x;
      v3->m_pVerts[v11].m_TangentS = vAvgTanS;
      p_x = &v3->m_pVerts[v11].m_TangentT.x;
      v36 = 0;
      *p_x = v33;
      p_x[1] = v31 - (float)(v29 * x);
      p_x[2] = (float)(y * x) - v32;
      if ( AllNeighbors >= 4 )
      {
        v37 = nbCornerVerts.m_Memory.m_pMemory + 2;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        viNBCornerVert = (CVertIndex)((char *)&iNeighbors[1] - (char *)nbCornerVerts.m_Memory.m_pMemory);
        do
        {
          v38 = *(v37 - 2);
          if ( v38 != -1 )
          {
            v39 = v38;
            v40 = ppListBase[iNeighbors[v36]]->m_pVerts;
            v40[v39].m_Normal = vAverage;
            v41 = vAverage.z;
            v42 = vAverage.y;
            v43 = &v40[v39];
            AllNeighbors = nNeighbors;
            v44 = vAvgTanS.z * vAverage.x;
            v45 = vAvgTanS.y * vAverage.x;
            v46 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v47 = vAvgTanS.x;
            v43->m_TangentS = vAvgTanS;
            v43->m_TangentT.x = v46;
            v43->m_TangentT.y = v44 - (float)(v41 * v47);
            v43->m_TangentT.z = (float)(v42 * v47) - v45;
          }
          v48 = *(v37 - 1);
          if ( v48 != -1 )
          {
            v49 = v48;
            v50 = ppListBase[iNeighbors[v36 + 1]]->m_pVerts;
            v50[v49].m_Normal = vAverage;
            v51 = vAverage.z;
            v52 = vAverage.y;
            v53 = &v50[v49];
            AllNeighbors = nNeighbors;
            v54 = vAvgTanS.z * vAverage.x;
            v55 = vAvgTanS.y * vAverage.x;
            v56 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v57 = vAvgTanS.x;
            v53->m_TangentS = vAvgTanS;
            v53->m_TangentT.x = v56;
            v53->m_TangentT.y = v54 - (float)(v51 * v57);
            v53->m_TangentT.z = (float)(v52 * v57) - v55;
          }
          if ( *v37 != -1 )
          {
            v58 = *v37;
            v59 = ppListBase[*(int *)((char *)v37 + *(_DWORD *)&cornerVert)]->m_pVerts;
            v59[v58].m_Normal = vAverage;
            v60 = vAverage.z;
            v61 = vAverage.y;
            v62 = &v59[v58];
            AllNeighbors = nNeighbors;
            v63 = vAvgTanS.z * vAverage.x;
            v64 = vAvgTanS.y * vAverage.x;
            v65 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v66 = vAvgTanS.x;
            v62->m_TangentS = vAvgTanS;
            v62->m_TangentT.x = v65;
            v62->m_TangentT.y = v63 - (float)(v60 * v66);
            v62->m_TangentT.z = (float)(v61 * v66) - v64;
          }
          v67 = v37[1];
          if ( v67 != -1 )
          {
            v68 = &ppListBase[*(int *)((char *)v37 + *(_DWORD *)&viNBCornerVert)]->m_pVerts[v67];
            AllNeighbors = nNeighbors;
            v68->m_Normal = vAverage;
            v69 = vAverage.z;
            v70 = vAverage.y;
            v71 = vAvgTanS.z * vAverage.x;
            v72 = vAvgTanS.y * vAverage.x;
            v73 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v74 = vAvgTanS.x;
            v68->m_TangentS = vAvgTanS;
            v68->m_TangentT.x = v73;
            v68->m_TangentT.y = v71 - (float)(v69 * v74);
            v68->m_TangentT.z = (float)(v70 * v74) - v72;
          }
          v36 += 4;
          v37 += 4;
        }
        while ( v36 < AllNeighbors - 3 );
      }
      if ( v36 < AllNeighbors )
      {
        v75 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v76 = &nbCornerVerts.m_Memory.m_pMemory[v36];
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v97 = AllNeighbors - v36;
        do
        {
          if ( *v76 != -1 )
          {
            v77 = *v76;
            v78 = ppListBase[*(int *)((char *)v76 + *(_DWORD *)&v75)]->m_pVerts;
            v78[v77].m_Normal.x = vAverage.x;
            v75 = cornerVert;
            v78[v77].m_Normal.y = vAverage.y;
            v78[v77].m_Normal.z = vAverage.z;
            v79 = vAverage.z;
            v80 = vAverage.y;
            v81 = &v78[v77];
            v82 = vAvgTanS.z * vAverage.x;
            v83 = vAvgTanS.y * vAverage.x;
            v84 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v85 = vAvgTanS.x;
            v81->m_TangentS = vAvgTanS;
            v81->m_TangentT.x = v84;
            v81->m_TangentT.y = v82 - (float)(v79 * v85);
            v81->m_TangentT.z = (float)(v80 * v85) - v83;
          }
          ++v76;
          --v97;
        }
        while ( v97 != 0 );
      }
    }
    m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
  }
  if ( nbCornerVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041D800
// Name: void SmoothDispSurfNormals(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmoothDispSurfNormals(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // esi

  for ( i = 0; i < nListSize; ++i )
    CCoreDispInfo::SetDispUtilsHelperInfo(this: ppListBase[i], ppListBase, listSize: nListSize);
  BlendSubNeighbors(ppListBase, nListSize);
  BlendCorners(ppListBase, nListSize);
  BlendEdges(ppListBase, nListSize);
}

//------------------------------------------------------------------------------
// Address: 0x0041D840
// Name: void FindNeighboringDispSurfs(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindNeighboringDispSurfs(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // ebx
  CCoreDispInfo *v3; // edi
  int i; // esi
  CDispNeighbor *v5; // eax
  int v6; // eax
  int m_Size; // eax
  CDispBox *m_pMemory; // esi
  int v9; // edx
  CDispBox *v10; // edi
  int v11; // edx
  int v12; // edi
  int v13; // esi
  int v14; // eax
  float *v15; // ecx
  CCoreDispInfo *v16; // ebx
  bool v17; // zf
  CUtlVector<CDispBox,CUtlMemory<CDispBox,int> > boxes; // [esp+Ch] [ebp-30h] BYREF
  CCoreDispInfo *pOther; // [esp+20h] [ebp-1Ch]
  int nCornerOverflows; // [esp+24h] [ebp-18h] BYREF
  int v21; // [esp+28h] [ebp-14h]
  int v22; // [esp+2Ch] [ebp-10h]
  CCoreDispInfo *pMain; // [esp+30h] [ebp-Ch]
  CCoreDispInfo **v24; // [esp+34h] [ebp-8h]
  int iDisp; // [esp+38h] [ebp-4h]

  v2 = nListSize;
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    v3 = ppListBase[iDisp];
    for ( i = 0; i < 4; ++i )
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: i);
      v5->m_SubNeighbors[0].m_iNeighbor = -1;
      v5->m_SubNeighbors[1].m_iNeighbor = -1;
      v6 = (int)v3->GetCornerNeighbors(this: v3, a2: i);
      *(_BYTE *)(v6 + 8) = 0;
    }
  }
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&boxes, 0, sizeof(boxes));
  if ( nListSize != 0 )
  {
    if ( nListSize > 0 )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)&boxes,
        num: nListSize);
      m_Size = boxes.m_Size;
      m_pMemory = boxes.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 && nListSize > 0 )
      _V_memmove(dest: &m_pMemory[nListSize], src: m_pMemory, count: 24 * m_Size);
  }
  v9 = 0;
  if ( nListSize > 0 )
  {
    v10 = m_pMemory;
    do
    {
      GetDispBox(pDisp: ppListBase[v9], box: v10);
      v9 = v11 + 1;
      ++v10;
    }
    while ( v9 < nListSize );
  }
  nCornerOverflows = 0;
  if ( nListSize > 0 )
  {
    v12 = 1;
    v22 = 1;
    iDisp = (int)m_pMemory;
    v24 = ppListBase;
    v21 = nListSize;
    do
    {
      pMain = *v24;
      if ( v12 < v2 )
      {
        v13 = iDisp + 24;
        do
        {
          pOther = ppListBase[v12];
          v14 = 0;
          v15 = (float *)(v13 + 12);
          while ( *(v15 - 3) <= *(float *)((char *)v15 + iDisp - v13) )
          {
            if ( *(float *)(iDisp + 4 * v14) > *v15 )
              goto LABEL_24;
            ++v14;
            ++v15;
            if ( v14 >= 3 )
            {
              v16 = pOther;
              SetupEdgeNeighbors(pMain, pOther);
              SetupCornerNeighbors(pMain, pOther: v16, nOverflows: &nCornerOverflows);
LABEL_24:
              v2 = nListSize;
              break;
            }
            v2 = nListSize;
          }
          ++v12;
          v13 += 24;
        }
        while ( v12 < v2 );
        v12 = v22;
        m_pMemory = boxes.m_Memory.m_pMemory;
      }
      ++v24;
      iDisp += 24;
      ++v12;
      v17 = v21-- == 1;
      v22 = v12;
    }
    while ( !v17 );
    if ( nCornerOverflows != 0 )
      _Warning(a1: "Warning: overflowed %d displacement corner-neighbor lists.", nCornerOverflows);
  }
  VerifyNeighborConnections(ppListBase, nDisps: v2);
  if ( boxes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x100022E0
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002310
// Name: float VectorLength(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VectorLength(const Vector *v)
{
  return fsqrt((float)((float)(v->x * v->x) + (float)(v->y * v->y)) + (float)(v->z * v->z));
}

//------------------------------------------------------------------------------
// Address: 0x10002370
// Name: public: float Vector::Length(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Length(Vector *this)
{
  return fsqrt((float)((float)(this->x * this->x) + (float)(this->y * this->y)) + (float)(this->z * this->z));
}

//------------------------------------------------------------------------------
// Address: 0x100023D0
// Name: public: class Vector Vector::operator+(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator+(Vector *this, Vector *result, const Vector *v)
{
  result->x = v->x + this->x;
  result->y = v->y + this->y;
  result->z = v->z + this->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002410
// Name: public: class Vector Vector::operator-(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator-(Vector *this, Vector *result, const Vector *v)
{
  result->x = this->x - v->x;
  result->y = this->y - v->y;
  result->z = this->z - v->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002450
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002490
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100024B0
// Name: public: void CCoreDispSurface::GetPoint(int,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetPoint(CCoreDispSurface *this, int index, Vector *pt)
{
  *pt = this->m_Points[index];
}

//------------------------------------------------------------------------------
// Address: 0x100024E0
// Name: public: class CCoreDispSurface __near * CCoreDispInfo::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CCoreDispInfo::GetSurface(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x100024F0
// Name: int GetEdgeIndexFromPoint(class CVertIndex const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdgeIndexFromPoint(const CVertIndex *index, char iMaxPower)
{
  int v2; // eax
  __int16 y; // dx

  v2 = 1 << iMaxPower;
  if ( index->x == 0 )
    return 0;
  y = index->y;
  if ( y == v2 )
    return 1;
  if ( index->x == v2 )
    return 2;
  return 4 * (y == 0) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002540
// Name: void SetupSpan(int,int,enum NeighborSpan,class CVertIndex __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupSpan(int iPower, int iEdge, NeighborSpan span, CVertIndex *viStart, CVertIndex *viEnd)
{
  _BOOL2 v5; // bx
  CPowerInfo *PowerInfo; // edi

  v5 = g_EdgeDims[iEdge] == 0;
  PowerInfo = (CPowerInfo *)GetPowerInfo(iPower);
  *viStart = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: iEdge);
  *viEnd = *CPowerInfo::GetCornerPointIndex(this: PowerInfo, iCorner: ((_BYTE)iEdge + 1) & 3);
  if ( iEdge != 2 && iEdge != 3 )
  {
    if ( span != CORNER_TO_MIDPOINT )
    {
      if ( span != MIDPOINT_TO_CORNER )
        return;
      goto LABEL_5;
    }
LABEL_8:
    *(&viEnd->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == CORNER_TO_MIDPOINT )
  {
LABEL_5:
    *(&viStart->x + v5) = PowerInfo->m_MidPoint;
    return;
  }
  if ( span == MIDPOINT_TO_CORNER )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: public: class CVertIndex CDispUtilsHelper::GetEdgeMidPoint(int)const
// Source: json
//------------------------------------------------------------------------------
CVertIndex *__thiscall CDispUtilsHelper::GetEdgeMidPoint(CDispUtilsHelper *this, CVertIndex *result, int iEdge)
{
  int v4; // edi
  int v5; // ecx
  CVertIndex *v6; // eax

  v4 = *(_DWORD *)(this->GetPowerInfo(this) + 36) - 1;
  v5 = *(_DWORD *)(this->GetPowerInfo(this) + 44);
  if ( iEdge != 0 )
  {
    if ( iEdge == 1 )
    {
      result->y = v4;
      result->x = v5;
      return result;
    }
    else if ( iEdge == 2 )
    {
      result->x = v4;
      result->y = v5;
      return result;
    }
    else
    {
      v6 = result;
      if ( iEdge == 3 )
      {
        result->x = v5;
        result->y = 0;
      }
      else
      {
        *result = 0;
      }
    }
  }
  else
  {
    result->x = 0;
    result->y = v5;
    return result;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10002650
// Name: FindNeighborCornerVert
// Source: json
//------------------------------------------------------------------------------
int __usercall FindNeighborCornerVert@<eax>(CCoreDispInfo *pDisp@<esi>, const Vector *vecPoint@<edi>)
{
  CPowerInfo *v2; // eax
  int v3; // ecx
  CoreDispVert_t *m_pVerts; // eax
  int v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v9; // [esp-1Ch] [ebp-2Ch]
  int v10; // [esp-Ch] [ebp-1Ch]
  float v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  int iClosest; // [esp+0h] [ebp-10h]

  v10 = 0;
  v11 = 1.0e24;
  for ( iClosest = 0; iClosest < 4; ++iClosest )
  {
    v2 = (CPowerInfo *)pDisp->GetPowerInfo(this: pDisp);
    v12 = (int)*CPowerInfo::GetCornerPointIndex(this: v2, iCorner: iClosest);
    v3 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * SHIWORD(v12);
    m_pVerts = pDisp->m_pVerts;
    v5 = (__int16)v12 + v3;
    v6 = m_pVerts[v5].m_Vert.x - vecPoint->x;
    v9 = fsqrt(
           (float)((float)((float)(m_pVerts[v5].m_Vert.y - vecPoint->y) * (float)(m_pVerts[v5].m_Vert.y - vecPoint->y))
                 + (float)(v6 * v6))
         + (float)((float)(m_pVerts[v5].m_Vert.z - vecPoint->z) * (float)(m_pVerts[v5].m_Vert.z - vecPoint->z)));
    v7 = v11;
    if ( v11 > v9 )
    {
      v7 = v9;
      v10 = iClosest;
      v11 = v9;
    }
  }
  if ( v7 > 0.1 )
    return -1;
  else
    return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10002750
// Name: UpdateTangentSpace
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateTangentSpace(
        const Vector *vNormal@<esi>,
        const Vector *vTanS@<edi>,
        CCoreDispInfo *pDisp,
        const CVertIndex *index)
{
  int v4; // ecx
  CoreDispVert_t *m_pVerts; // eax
  char *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm3_4

  v4 = index->x + *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36) * index->y;
  m_pVerts = pDisp->m_pVerts;
  v4 *= 224;
  *(Vector *)((char *)&m_pVerts->m_Normal + v4) = *vNormal;
  v6 = (char *)m_pVerts + v4;
  v7 = vTanS->z * vNormal->x;
  v8 = vTanS->y * vNormal->x;
  v9 = (float)(vTanS->y * vNormal->z) - (float)(vTanS->z * vNormal->y);
  v10 = vTanS->x * vNormal->z;
  v11 = vTanS->x * vNormal->y;
  *(Vector *)(v6 + 76) = *vTanS;
  *((float *)v6 + 22) = v9;
  *((float *)v6 + 23) = v7 - v10;
  *((float *)v6 + 24) = v11 - v8;
}

//------------------------------------------------------------------------------
// Address: 0x10002800
// Name: GetAllNeighbors
// Source: json
//------------------------------------------------------------------------------
int __usercall GetAllNeighbors@<eax>(int *iNeighbors@<esi>, CCoreDispInfo *pDisp)
{
  unsigned __int16 *v2; // ebx
  int result; // eax
  unsigned __int8 *p_m_nNeighbors; // ecx
  int i; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v2 = (unsigned __int16 *)pDisp;
  result = 0;
  p_m_nNeighbors = &pDisp->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
  for ( i = 4; i != 0; --i )
  {
    v6 = 0;
    if ( *p_m_nNeighbors != 0 )
    {
      do
      {
        if ( result == 0 )
        {
          *iNeighbors = *(unsigned __int16 *)&p_m_nNeighbors[2 * v6 - 8];
          result = 1;
        }
        ++v6;
      }
      while ( v6 < *p_m_nNeighbors );
      v2 = (unsigned __int16 *)pDisp;
    }
    p_m_nNeighbors += 10;
  }
  v7 = v2[312];
  if ( (_WORD)v7 != 0xFFFF )
    iNeighbors[result++] = v7;
  v8 = v2[315];
  if ( (_WORD)v8 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v8;
  v9 = v2[318];
  if ( (_WORD)v9 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v9;
  v10 = v2[321];
  if ( (_WORD)v10 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v10;
  v11 = v2[324];
  if ( (_WORD)v11 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v11;
  v12 = v2[327];
  if ( (_WORD)v12 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v12;
  v13 = v2[330];
  if ( (_WORD)v13 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v13;
  v14 = v2[333];
  if ( (_WORD)v14 != 0xFFFF && result < 512 )
    iNeighbors[result++] = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002900
// Name: class CDispUtilsHelper __near * TransformIntoSubNeighbor(class CDispUtilsHelper __near *,int,int,class CVertIndex const __near &,class CVertIndex __near &)
// Source: json
//------------------------------------------------------------------------------
CDispUtilsHelper *__cdecl TransformIntoSubNeighbor(
        CDispUtilsHelper *pDisp,
        int iEdge,
        CVertIndex iSub,
        const CVertIndex *nodeIndex,
        CVertIndex *out)
{
  int v5; // ebx
  CDispUtilsHelper *v6; // esi
  CDispNeighbor *v7; // eax
  CDispUtilsHelper *m_Span; // edx
  CDispSubNeighbor *v9; // edi
  CDispUtilsHelper_vtbl *v10; // eax
  int v11; // eax
  CDispUtilsHelper *v12; // eax
  unsigned __int8 m_NeighborOrientation; // cl
  NeighborSpan m_NeighborSpan; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  CVertIndex *v18; // edi
  int v19; // edx
  int v20; // edx
  int v21; // ecx
  CDispUtilsHelper *pNeighbor; // [esp+Ch] [ebp-8h]
  CVertIndex viDestEnd; // [esp+10h] [ebp-4h] BYREF

  v5 = iEdge;
  v6 = pDisp;
  v7 = pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge);
  m_Span = (CDispUtilsHelper *)v7->m_SubNeighbors[*(_DWORD *)&iSub].m_Span;
  v9 = &v7->m_SubNeighbors[*(_DWORD *)&iSub];
  v10 = v6->__vftable;
  pDisp = m_Span;
  v11 = (int)v10->GetPowerInfo(this: v6);
  SetupSpan(
    iPower: *(_DWORD *)(v11 + 28),
    iEdge: v5,
    span: (NeighborSpan)pDisp,
    viStart: (CVertIndex *)&iEdge,
    viEnd: &iSub);
  v12 = v6->GetDispUtilsByIndex(this: v6, a2: v9->m_iNeighbor);
  m_NeighborOrientation = v9->m_NeighborOrientation;
  m_NeighborSpan = v9->m_NeighborSpan;
  pNeighbor = v12;
  v15 = (m_NeighborOrientation + (_BYTE)v5 - 2) & 3;
  v16 = v12->GetPowerInfo(this: v12);
  SetupSpan(
    iPower: *(_DWORD *)(v16 + 28),
    iEdge: v15,
    span: m_NeighborSpan,
    viStart: &viDestEnd,
    viEnd: (CVertIndex *)&pDisp);
  v17 = g_EdgeDims[v15];
  v18 = out;
  v19 = *((__int16 *)&iEdge + (g_EdgeDims[v5] == 0));
  v20 = ((*(&nodeIndex->x + (g_EdgeDims[v5] == 0)) - v19) << 16) / (*(&iSub.x + (g_EdgeDims[v5] == 0)) - v19);
  *(&out->x + (__int16)v17) = *((_WORD *)&pDisp + (__int16)v17);
  v21 = 2 * (v17 == 0);
  *(__int16 *)((char *)&v18->x + v21) = *(_WORD *)((char *)&pDisp + v21)
                                      + v20
                                      * (*(__int16 *)((char *)&viDestEnd.x + v21) - *(__int16 *)((char *)&pDisp + v21))
                                      / 0x10000;
  return pNeighbor;
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
// Name: BlendSubNeighbors
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendSubNeighbors(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // edi
  CDispNeighbor *v5; // eax
  CDispNeighbor *v6; // ebx
  int v7; // eax
  const Vector *p_m_Vert; // edi
  CCoreDispInfo *v9; // ebx
  int NeighborCornerVert; // esi
  CPowerInfo *v11; // eax
  CVertIndex v12; // ecx
  CDispNeighbor *v13; // esi
  int (__thiscall *v14)(CDispNeighbor *); // eax
  CPowerInfo *v15; // eax
  CVertIndex v16; // ecx
  int v17; // edi
  __int64 v18; // xmm0_8
  CCoreDispInfo_vtbl *v19; // edx
  float *v20; // eax
  float v21; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v23; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int v25; // eax
  int p_m_Normal; // eax
  int (__thiscall **v27)(CDispNeighbor *); // edx
  int (__thiscall *v28)(CDispNeighbor *); // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  float *v33; // eax
  float v34; // edx
  CCoreDispInfo_vtbl *v35; // eax
  int v36; // eax
  CoreDispVert_t *v37; // edx
  int v38; // ecx
  int (__thiscall *v39)(CDispNeighbor *); // edx
  int v40; // eax
  int v41; // edx
  int v42; // ecx
  CoreDispVert_t *v43; // edx
  float z; // xmm4_4
  float y; // xmm1_4
  char *v46; // eax
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  int v50; // [esp-10h] [ebp-54h]
  int v51; // [esp-10h] [ebp-54h]
  Vector vAvgTanS; // [esp+0h] [ebp-44h] BYREF
  Vector vecAverage; // [esp+Ch] [ebp-38h] BYREF
  int iCorners[2]; // [esp+18h] [ebp-2Ch]
  CVertIndex viCorners[2]; // [esp+20h] [ebp-24h] BYREF
  int v56; // [esp+28h] [ebp-1Ch]
  int x; // [esp+2Ch] [ebp-18h]
  int iDisp; // [esp+30h] [ebp-14h]
  CVertIndex viMidPoint; // [esp+34h] [ebp-10h] BYREF
  int iEdge; // [esp+38h] [ebp-Ch]
  CDispNeighbor *pEdge; // [esp+3Ch] [ebp-8h]
  CCoreDispInfo *pDisp; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( iDisp = 0; v2 < nListSize; iDisp = v2 )
  {
    v3 = ppListBase[v2];
    pDisp = v3;
    if ( v3 != nullptr )
    {
      v4 = 0;
      iEdge = 0;
      do
      {
        v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
        v6 = v5;
        pEdge = v5;
        if ( v5 != nullptr && v5->m_SubNeighbors[0].m_iNeighbor != 0xFFFF && v5->m_SubNeighbors[1].m_iNeighbor != 0xFFFF )
        {
          CDispUtilsHelper::GetEdgeMidPoint(this: v3, result: &viMidPoint, iEdge: v4);
          v7 = v3->GetPowerInfo(this: v3);
          p_m_Vert = &v3->m_pVerts[viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y].m_Vert;
          x = 224 * (viMidPoint.x + *(_DWORD *)(v7 + 36) * viMidPoint.y);
          v9 = ppListBase[v6->m_SubNeighbors[0].m_iNeighbor];
          pEdge = (CDispNeighbor *)ppListBase[pEdge->m_SubNeighbors[1].m_iNeighbor];
          iCorners[0] = FindNeighborCornerVert(pDisp: v9, vecPoint: p_m_Vert);
          NeighborCornerVert = FindNeighborCornerVert(pDisp: (CCoreDispInfo *)pEdge, vecPoint: p_m_Vert);
          if ( iCorners[0] != -1 && NeighborCornerVert != -1 )
          {
            v50 = iCorners[0];
            v11 = (CPowerInfo *)v9->GetPowerInfo(this: v9);
            v12 = *CPowerInfo::GetCornerPointIndex(this: v11, iCorner: v50);
            v51 = NeighborCornerVert;
            v13 = pEdge;
            v14 = **(int (__thiscall ***)(CDispNeighbor *))&pEdge->m_SubNeighbors[0].m_iNeighbor;
            viCorners[0] = v12;
            v15 = (CPowerInfo *)v14(a1: pEdge);
            v16 = *CPowerInfo::GetCornerPointIndex(this: v15, iCorner: v51);
            v17 = x;
            v18 = *(_QWORD *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            v19 = v9->__vftable;
            v20 = (float *)((char *)&pDisp->m_pVerts->m_Normal.x + x);
            viCorners[1] = v16;
            *(_QWORD *)&vecAverage.x = v18;
            v21 = v20[2];
            GetPowerInfo = v19->GetPowerInfo;
            vecAverage.z = v21;
            v23 = (int)GetPowerInfo(this: v9);
            m_pVerts = v9->m_pVerts;
            v25 = viCorners[0].x + viCorners[0].y * *(_DWORD *)(v23 + 36);
            *(float *)&v18 = m_pVerts[v25].m_Normal.x + vecAverage.x;
            p_m_Normal = (int)&m_pVerts[v25].m_Normal;
            LODWORD(vecAverage.x) = v18;
            *(float *)&v18 = *(float *)(p_m_Normal + 4) + vecAverage.y;
            x = viCorners[0].x;
            v27 = *(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            LODWORD(vecAverage.y) = v18;
            *(float *)&v18 = *(float *)(p_m_Normal + 8) + vecAverage.z;
            v28 = *v27;
            LODWORD(vecAverage.z) = v18;
            v29 = v28(a1: v13);
            v30 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v31 = 224 * (viCorners[1].x + viCorners[1].y * *(_DWORD *)(v29 + 36));
            *(float *)&v18 = *(float *)(v31 + v30 + 64) + vecAverage.x;
            v32 = v31 + v30 + 64;
            LODWORD(vecAverage.x) = v18;
            *(float *)&v18 = *(float *)(v32 + 4) + vecAverage.y;
            v56 = viCorners[1].x;
            LODWORD(vecAverage.y) = v18;
            vecAverage.z = *(float *)(v32 + 8) + vecAverage.z;
            VectorNormalize(vec: &vecAverage);
            v33 = (float *)((char *)&pDisp->m_pVerts->m_TangentS.x + v17);
            *(_QWORD *)&vAvgTanS.x = *(_QWORD *)v33;
            v34 = v33[2];
            v35 = v9->__vftable;
            vAvgTanS.z = v34;
            v36 = (int)v35->GetPowerInfo(this: v9);
            v37 = v9->m_pVerts;
            v38 = x + viCorners[0].y * *(_DWORD *)(v36 + 36);
            vAvgTanS.x = v37[v38].m_TangentS.x + vAvgTanS.x;
            vAvgTanS.y = v37[v38].m_TangentS.y + vAvgTanS.y;
            *(float *)&v18 = v37[v38].m_TangentS.z + vAvgTanS.z;
            v39 = **(int (__thiscall ***)(CDispNeighbor *))&v13->m_SubNeighbors[0].m_iNeighbor;
            LODWORD(vAvgTanS.z) = v18;
            v40 = v39(a1: v13);
            v41 = *(_DWORD *)&v13[63].m_SubNeighbors[0].m_NeighborSpan;
            v42 = 224 * (v56 + viCorners[1].y * *(_DWORD *)(v40 + 36));
            vAvgTanS.x = vAvgTanS.x + *(float *)(v42 + v41 + 76);
            vAvgTanS.y = *(float *)(v42 + v41 + 80) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v42 + v41 + 84) + vAvgTanS.z;
            VectorNormalize(vec: &vAvgTanS);
            v43 = pDisp->m_pVerts;
            *(Vector *)((char *)&v43->m_Normal + v17) = vecAverage;
            z = vecAverage.z;
            y = vecAverage.y;
            v46 = (char *)v43 + v17;
            v47 = vAvgTanS.y * vecAverage.x;
            *(float *)&v18 = vAvgTanS.z * vecAverage.x;
            v48 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
            v49 = vAvgTanS.x;
            *(Vector *)(v46 + 76) = vAvgTanS;
            *((float *)v46 + 22) = v48;
            *((float *)v46 + 23) = *(float *)&v18 - (float)(z * v49);
            *((float *)v46 + 24) = (float)(y * v49) - v47;
            UpdateTangentSpace(vNormal: &vecAverage, vTanS: &vAvgTanS, pDisp: v9, index: viCorners);
            UpdateTangentSpace(
              vNormal: &vecAverage,
              vTanS: &vAvgTanS,
              pDisp: (CCoreDispInfo *)pEdge,
              index: &viCorners[1]);
          }
          v3 = pDisp;
          v4 = iEdge;
        }
        iEdge = ++v4;
      }
      while ( v4 < 4 );
      v2 = iDisp;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002DB0
// Name: class CDispUtilsHelper __near * SetupEdgeIncrements(class CDispUtilsHelper __near *,int,int,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,class CVertIndex __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CDispUtilsHelper *__cdecl SetupEdgeIncrements(
        CDispUtilsHelper *pDisp,
        int iEdge,
        int iSub,
        CVertIndex *myIndex,
        CVertIndex *myInc,
        CVertIndex *nbIndex,
        CVertIndex *nbInc,
        int *myEnd,
        int *iFreeDim)
{
  CDispSubNeighbor *v11; // edi
  int m_iNeighbor; // eax
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int m_NeighborOrientation; // eax
  CVertIndex *v19; // eax
  int v20; // edx
  bool v21; // zf
  int v22; // ecx
  CDispSubNeighbor *pSub; // [esp+Ch] [ebp-Ch]
  _BYTE iEdgeDim[6]; // [esp+10h] [ebp-8h] OVERLAPPED
  CShiftInfo *pShiftInfo; // [esp+20h] [ebp+8h]
  CDispUtilsHelper *pNeighbor; // [esp+24h] [ebp+Ch]

  *(_DWORD *)iEdgeDim = g_EdgeDims[iEdge];
  *iFreeDim = *(_DWORD *)iEdgeDim == 0;
  v11 = &pDisp->GetEdgeNeighbor(this: pDisp, a2: iEdge)->m_SubNeighbors[iSub];
  m_iNeighbor = v11->m_iNeighbor;
  pSub = v11;
  if ( (_WORD)m_iNeighbor == 0xFFFF )
    return nullptr;
  pNeighbor = pDisp->GetDispUtilsByIndex(this: pDisp, a2: m_iNeighbor);
  pShiftInfo = &g_ShiftInfos[v11->m_Span][v11->m_NeighborSpan];
  v14 = pDisp->GetPowerInfo(this: pDisp);
  v15 = 2 * *(__int16 *)iEdgeDim;
  *(__int16 *)((char *)&myIndex->x + v15) = *(_WORD *)(v14 + 40) * LOWORD(g_EdgeSideLenMul[iEdge]);
  *(&myIndex->x + *(__int16 *)iFreeDim) = iSub * *(_WORD *)(v14 + 44);
  TransformIntoSubNeighbor(pDisp, iEdge, (CVertIndex)iSub, nodeIndex: myIndex, out: nbIndex);
  v16 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 28);
  v17 = pShiftInfo->m_PowerShiftAdd + *(_DWORD *)(pNeighbor->GetPowerInfo(this: pNeighbor) + 28);
  *(_WORD *)&iEdgeDim[v15] = 0;
  *(__int16 *)((char *)&myInc->x + v15) = 0;
  if ( v17 <= v16 )
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1 << (v16 - v17);
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1;
  }
  else
  {
    *(&myInc->x + *(__int16 *)iFreeDim) = 1;
    *(_WORD *)&iEdgeDim[2 * *(__int16 *)iFreeDim] = 1 << (v17 - v16);
  }
  m_NeighborOrientation = pSub->m_NeighborOrientation;
  if ( pSub->m_NeighborOrientation != 0 )
  {
    if ( m_NeighborOrientation == 1 )
    {
      v19 = nbInc;
      nbInc->x = *(_WORD *)&iEdgeDim[2];
      v20 = -*(_DWORD *)iEdgeDim;
    }
    else
    {
      v21 = m_NeighborOrientation == 2;
      v19 = nbInc;
      if ( v21 )
      {
        nbInc->x = -*(_WORD *)iEdgeDim;
        v20 = -*(_DWORD *)&iEdgeDim[2];
      }
      else
      {
        nbInc->x = -*(_WORD *)&iEdgeDim[2];
        LOWORD(v20) = *(_WORD *)iEdgeDim;
      }
    }
    v19->y = v20;
  }
  else
  {
    *nbInc = *(CVertIndex *)iEdgeDim;
  }
  if ( pSub->m_Span == 1 )
  {
    *myEnd = *(int *)(pDisp->GetPowerInfo(this: pDisp) + 36) >> 1;
    return pNeighbor;
  }
  else
  {
    v22 = *(_DWORD *)(pDisp->GetPowerInfo(this: pDisp) + 36);
    *myEnd = v22 - 1;
    return pNeighbor;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F70
// Name: BlendEdges
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendEdges(CCoreDispInfo **ppListBase, int nListSize)
{
  int v2; // eax
  CCoreDispInfo *v3; // esi
  int v4; // ebx
  CDispNeighbor *v5; // eax
  int v6; // ecx
  int m_iNeighbor; // eax
  CCoreDispInfo *v8; // ebx
  __int16 x; // ax
  CVertIndex m_Index; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int y; // edi
  int p_m_Normal; // edx
  CCoreDispInfo_vtbl *v16; // eax
  int v17; // eax
  CoreDispVert_t *m_pVerts; // ecx
  CCoreDispInfo_vtbl *v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v24; // eax
  CCoreDispInfo_vtbl *v25; // edx
  int v26; // eax
  CoreDispVert_t *v27; // edx
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  int v31; // eax
  CCoreDispInfo_vtbl *v32; // edx
  int v33; // eax
  float z; // xmm4_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  int v40; // eax
  int v41; // eax
  float v42; // xmm4_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // ecx
  int v50; // edx
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  int v55; // eax
  float *p_x; // edi
  int v57; // eax
  CoreDispVert_t *v58; // edx
  int v59; // ecx
  int v60; // eax
  float *v61; // edi
  int v62; // eax
  CoreDispVert_t *v63; // edx
  int v64; // ecx
  int v65; // eax
  int v66; // edi
  CCoreDispInfo_vtbl *v67; // edx
  int v68; // eax
  int v69; // ecx
  CoreDispVert_t *v70; // eax
  int v71; // ecx
  CoreDispVert_t *v72; // eax
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  CVertIndex v79; // ecx
  int iCurPos; // [esp+4h] [ebp-94h]
  CVertIndex *v81; // [esp+8h] [ebp-90h]
  _WORD *v82; // [esp+Ch] [ebp-8Ch]
  float v83; // [esp+10h] [ebp-88h]
  __int16 v84; // [esp+14h] [ebp-84h]
  float v85; // [esp+18h] [ebp-80h]
  CVertIndex *v86; // [esp+1Ch] [ebp-7Ch]
  Vector vec; // [esp+20h] [ebp-78h] BYREF
  int iSubEdge; // [esp+2Ch] [ebp-6Ch]
  int iDisp; // [esp+30h] [ebp-68h]
  int iEdgeDim; // [esp+34h] [ebp-64h]
  CDispNeighbor *v91; // [esp+38h] [ebp-60h]
  int v92; // [esp+3Ch] [ebp-5Ch]
  Vector vecNormal; // [esp+40h] [ebp-58h] BYREF
  int iTween; // [esp+4Ch] [ebp-4Ch]
  CVertIndex viTween; // [esp+50h] [ebp-48h] BYREF
  int iEdge; // [esp+54h] [ebp-44h]
  Vector vAvgTanS; // [esp+58h] [ebp-40h] BYREF
  float flPercent; // [esp+64h] [ebp-34h]
  Vector vecAverage; // [esp+68h] [ebp-30h] BYREF
  CVertIndex viPrevPos; // [esp+74h] [ebp-24h]
  Vector *p_m_TangentS; // [esp+78h] [ebp-20h]
  CDispSubEdgeIterator it; // [esp+7Ch] [ebp-1Ch] BYREF

  v2 = 0;
  iDisp = 0;
  if ( nListSize <= 0 )
    return;
  do
  {
    v3 = ppListBase[v2];
    if ( v3 == nullptr )
      goto LABEL_30;
    v4 = 0;
    iEdge = 0;
    do
    {
      v5 = v3->GetEdgeNeighbor(this: v3, a2: v4);
      if ( v5 == nullptr )
        goto LABEL_28;
      v6 = 0;
      iSubEdge = 0;
      v91 = v5;
      do
      {
        m_iNeighbor = v5->m_SubNeighbors[0].m_iNeighbor;
        if ( (_WORD)m_iNeighbor != 0xFFFF )
        {
          v8 = ppListBase[m_iNeighbor];
          if ( v8 != nullptr )
          {
            iEdgeDim = g_EdgeDims[iEdge];
            it.m_Inc.x = 0;
            it.m_Index.x = 0;
            it.m_pNeighbor = nullptr;
            it.m_End = 0;
            it.m_FreeDim = 0;
            it.m_pNeighbor = SetupEdgeIncrements(
                               pDisp: v3,
                               iEdge,
                               iSub: v6,
                               myIndex: &it.m_Index,
                               myInc: &it.m_Inc,
                               nbIndex: &it.m_NBIndex,
                               nbInc: &it.m_NBInc,
                               myEnd: &it.m_End,
                               iFreeDim: &it.m_FreeDim);
            if ( it.m_pNeighbor != nullptr )
            {
              it.m_Index.y -= it.m_Inc.y;
              it.m_NBIndex.x -= it.m_NBInc.x;
              x = it.m_Inc.x;
              it.m_Index.x -= it.m_Inc.x;
              it.m_NBIndex.y -= it.m_NBInc.y;
              it.m_End += *(&it.m_Inc.x + SLOWORD(it.m_FreeDim));
            }
            else
            {
              it.m_Index.x = 0;
              it.m_End = 0;
              it.m_Inc.x = 0;
              it.m_FreeDim = 0;
              x = 0;
            }
            it.m_Index.y += it.m_Inc.y;
            it.m_Index.x += x;
            it.m_NBIndex.x += it.m_NBInc.x;
            m_Index = it.m_Index;
            it.m_Index.x += x;
            it.m_Index.y += it.m_Inc.y;
            it.m_NBIndex.y += it.m_NBInc.y + it.m_NBInc.y;
            viPrevPos = m_Index;
            it.m_NBIndex.x += it.m_NBInc.x;
            v11 = 2 * SLOWORD(it.m_FreeDim);
            v81 = (CVertIndex *)((char *)&it.m_Index + v11);
            v12 = *(__int16 *)((char *)&it.m_Index.x + v11);
            if ( v12 < it.m_End )
            {
              v86 = (CVertIndex *)((char *)&it.m_Inc + v11);
              v92 = 2 * (iEdgeDim == 0);
              while ( 1 )
              {
                if ( v12 + v86->x < it.m_End )
                {
                  v13 = v8->GetPowerInfo(this: v8);
                  y = it.m_NBIndex.y;
                  p_m_Normal = (int)&v8->m_pVerts[it.m_NBIndex.x + it.m_NBIndex.y * *(_DWORD *)(v13 + 36)].m_Normal;
                  v16 = v3->__vftable;
                  p_m_TangentS = (Vector *)p_m_Normal;
                  v17 = (int)v16->GetPowerInfo(this: v3);
                  m_pVerts = v3->m_pVerts;
                  v19 = v8->__vftable;
                  v20 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v17 + 36);
                  v21 = m_pVerts[v20].m_Normal.x;
                  v22 = (int)&m_pVerts[v20].m_Normal;
                  vecAverage.x = v21 + p_m_TangentS->x;
                  vecAverage.y = *(float *)(v22 + 4) + p_m_TangentS->y;
                  GetPowerInfo = v19->GetPowerInfo;
                  vecAverage.z = *(float *)(v22 + 8) + p_m_TangentS->z;
                  v24 = (int)GetPowerInfo(this: v8);
                  v25 = v3->__vftable;
                  p_m_TangentS = &v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v24 + 36)].m_TangentS;
                  v26 = (int)v25->GetPowerInfo(this: v3);
                  v27 = v3->m_pVerts;
                  v28 = it.m_Index.x + it.m_Index.y * *(_DWORD *)(v26 + 36);
                  v29 = p_m_TangentS->x + v27[v28].m_TangentS.x;
                  v30 = (int)&v27[v28].m_TangentS;
                  vAvgTanS.x = v29;
                  vAvgTanS.y = *(float *)(v30 + 4) + p_m_TangentS->y;
                  vAvgTanS.z = *(float *)(v30 + 8) + p_m_TangentS->z;
                  VectorNormalize(vec: &vecAverage);
                  VectorNormalize(vec: &vAvgTanS);
                  v31 = v3->GetPowerInfo(this: v3);
                  v32 = v8->__vftable;
                  v33 = (int)&v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v31 + 36)];
                  *(Vector *)(v33 + 64) = vecAverage;
                  z = vecAverage.z;
                  v35 = vecAverage.y;
                  v36 = vAvgTanS.y * vecAverage.x;
                  v37 = vAvgTanS.z * vecAverage.x;
                  v38 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v39 = vAvgTanS.x;
                  *(Vector *)(v33 + 76) = vAvgTanS;
                  *(float *)(v33 + 88) = v38;
                  *(float *)(v33 + 92) = v37 - (float)(z * v39);
                  *(float *)(v33 + 96) = (float)(v35 * v39) - v36;
                  v40 = (int)v32->GetPowerInfo(this: v8);
                  v41 = (int)&v8->m_pVerts[it.m_NBIndex.x + y * *(_DWORD *)(v40 + 36)];
                  *(Vector *)(v41 + 64) = vecAverage;
                  v42 = vecAverage.z;
                  v43 = vecAverage.y;
                  v44 = vAvgTanS.y * vecAverage.x;
                  v45 = vAvgTanS.z * vecAverage.x;
                  v46 = (float)(vAvgTanS.y * vecAverage.z) - (float)(vAvgTanS.z * vecAverage.y);
                  v47 = vAvgTanS.x;
                  *(Vector *)(v41 + 76) = vAvgTanS;
                  *(float *)(v41 + 88) = v46;
                  *(float *)(v41 + 92) = v45 - (float)(v42 * v47);
                  *(float *)(v41 + 96) = (float)(v43 * v47) - v44;
                }
                v48 = *(__int16 *)((char *)&viPrevPos.x + v92);
                v49 = *(__int16 *)((char *)&it.m_Index.x + v92);
                v50 = v48 + 1;
                iCurPos = v49;
                iTween = v48 + 1;
                if ( v48 + 1 < v49 )
                  break;
LABEL_25:
                v79 = it.m_Index;
                it.m_Index.x += it.m_Inc.x;
                it.m_Index.y += it.m_Inc.y;
                it.m_NBIndex.y += it.m_NBInc.y;
                viPrevPos = v79;
                it.m_NBIndex.x += it.m_NBInc.x;
                v12 = v81->x;
                if ( v12 >= it.m_End )
                  goto LABEL_26;
              }
              v51 = (float)v48;
              p_m_TangentS = (Vector *)viPrevPos.x;
              v52 = (float)v49;
              v85 = (float)v48;
              v83 = (float)v49;
              v82 = (_WORD *)&viTween + (__int16)iEdgeDim;
              v84 = *(&it.m_Index.x + (__int16)iEdgeDim);
              while ( 1 )
              {
                v53 = (float)v50;
                if ( v51 == v52 )
                {
                  if ( (float)(v53 - v52) < 0.0 )
                  {
                    flPercent = 0.0;
                    goto LABEL_24;
                  }
                  v54 = 1.0;
                }
                else
                {
                  v54 = (float)(v53 - v51) / (float)(v52 - v51);
                }
                flPercent = v54;
LABEL_24:
                v55 = v3->GetPowerInfo(this: v3);
                p_x = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v55 + 36)].m_Normal.x;
                v57 = v3->GetPowerInfo(this: v3);
                v58 = v3->m_pVerts;
                v59 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v57 + 36);
                vecNormal.x = (float)((float)(*p_x - v58[v59].m_Normal.x) * flPercent) + v58[v59].m_Normal.x;
                vecNormal.y = (float)((float)(p_x[1] - v58[v59].m_Normal.y) * flPercent) + v58[v59].m_Normal.y;
                vecNormal.z = (float)((float)(p_x[2] - v58[v59].m_Normal.z) * flPercent) + v58[v59].m_Normal.z;
                VectorNormalize(vec: &vecNormal);
                v60 = v3->GetPowerInfo(this: v3);
                v61 = &v3->m_pVerts[it.m_Index.x + it.m_Index.y * *(_DWORD *)(v60 + 36)].m_TangentS.x;
                v62 = v3->GetPowerInfo(this: v3);
                v63 = v3->m_pVerts;
                v64 = (int)p_m_TangentS + viPrevPos.y * *(_DWORD *)(v62 + 36);
                vec.x = (float)((float)(*v61 - v63[v64].m_TangentS.x) * flPercent) + v63[v64].m_TangentS.x;
                vec.y = (float)((float)(v61[1] - v63[v64].m_TangentS.y) * flPercent) + v63[v64].m_TangentS.y;
                vec.z = (float)((float)(v61[2] - v63[v64].m_TangentS.z) * flPercent) + v63[v64].m_TangentS.z;
                VectorNormalize(&vec);
                v65 = v92;
                v66 = iTween;
                *v82 = v84;
                v67 = v3->__vftable;
                *(__int16 *)((char *)&viTween.x + v65) = v66;
                v68 = (int)v67->GetPowerInfo(this: v3);
                v69 = *(_DWORD *)(v68 + 36) * viTween.y;
                v70 = v3->m_pVerts;
                v71 = viTween.x + v69;
                v70[v71].m_Normal.x = vecNormal.x;
                v70[v71].m_Normal.y = vecNormal.y;
                v72 = &v70[v71];
                v72->m_Normal.z = vecNormal.z;
                v73 = vecNormal.z;
                v74 = vecNormal.y;
                v75 = vec.y * vecNormal.x;
                v76 = vec.z * vecNormal.x;
                v77 = (float)(vec.y * vecNormal.z) - (float)(vec.z * vecNormal.y);
                v78 = vec.x;
                v72->m_TangentS = vec;
                v72->m_TangentT.x = v77;
                v72->m_TangentT.y = v76 - (float)(v73 * v78);
                v72->m_TangentT.z = (float)(v74 * v78) - v75;
                iTween = v66 + 1;
                if ( v66 + 1 >= iCurPos )
                  goto LABEL_25;
                v52 = v83;
                v51 = v85;
                v50 = iTween;
              }
            }
          }
        }
LABEL_26:
        v6 = iSubEdge + 1;
        v5 = (CDispNeighbor *)&v91->m_SubNeighbors[1];
        iSubEdge = v6;
        v91 = (CDispNeighbor *)((char *)v91 + 6);
      }
      while ( v6 < 2 );
      v4 = iEdge;
LABEL_28:
      iEdge = ++v4;
    }
    while ( v4 < 4 );
    v2 = iDisp;
LABEL_30:
    iDisp = ++v2;
  }
  while ( v2 < nListSize );
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: BlendCorners
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendCorners(CCoreDispInfo **ppListBase, int nListSize)
{
  int *m_pMemory; // ebx
  CCoreDispInfo *v3; // edi
  int AllNeighbors; // esi
  int m_Size; // eax
  int *v6; // eax
  CPowerInfo *v7; // eax
  CVertIndex v8; // ecx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int v10; // eax
  int v11; // ebx
  CoreDispVert_t *v12; // eax
  float z; // edx
  const Vector *p_m_Vert; // ecx
  int p_m_TangentS; // eax
  float v16; // xmm0_4
  CVertIndex v17; // eax
  CCoreDispInfo *v18; // esi
  int NeighborCornerVert; // eax
  CPowerInfo *v20; // eax
  CVertIndex v21; // edi
  const CPowerInfo *(__thiscall *v22)(struct CCoreDispInfo *); // eax
  int v23; // eax
  int v24; // ecx
  CoreDispVert_t *m_pVerts; // edx
  CoreDispVert_t *v26; // eax
  float v27; // xmm0_4
  int v28; // eax
  float v29; // xmm3_4
  float y; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float x; // xmm5_4
  float *p_x; // ebx
  int v36; // edx
  int *v37; // ecx
  int v38; // eax
  int v39; // eax
  CoreDispVert_t *v40; // esi
  float v41; // xmm3_4
  float v42; // xmm0_4
  CoreDispVert_t *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  int v48; // eax
  int v49; // eax
  CoreDispVert_t *v50; // esi
  float v51; // xmm3_4
  float v52; // xmm0_4
  CoreDispVert_t *v53; // eax
  float v54; // xmm1_4
  float v55; // xmm4_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  int v58; // eax
  CoreDispVert_t *v59; // esi
  float v60; // xmm3_4
  float v61; // xmm0_4
  CoreDispVert_t *v62; // eax
  float v63; // xmm1_4
  float v64; // xmm4_4
  float v65; // xmm2_4
  float v66; // xmm5_4
  int v67; // eax
  CoreDispVert_t *v68; // eax
  float v69; // xmm3_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm4_4
  float v73; // xmm2_4
  float v74; // xmm5_4
  CVertIndex v75; // ebx
  int *v76; // ecx
  int v77; // eax
  CoreDispVert_t *v78; // edx
  float v79; // xmm3_4
  float v80; // xmm0_4
  CoreDispVert_t *v81; // eax
  float v82; // xmm1_4
  float v83; // xmm4_4
  float v84; // xmm2_4
  float v85; // xmm5_4
  int v86; // [esp-Ch] [ebp-860h]
  int v87; // [esp-Ch] [ebp-860h]
  int iNeighbors[512]; // [esp+4h] [ebp-850h] BYREF
  CCoreDispInfo *pDisp; // [esp+804h] [ebp-50h]
  const Vector *vCornerVert; // [esp+808h] [ebp-4Ch]
  CVertIndex viNBCornerVert; // [esp+80Ch] [ebp-48h]
  int iCorner; // [esp+810h] [ebp-44h]
  int iDisp; // [esp+814h] [ebp-40h]
  CUtlVector<int,CUtlMemory<int,int> > nbCornerVerts; // [esp+818h] [ebp-3Ch] BYREF
  int *v95; // [esp+82Ch] [ebp-28h]
  int nNeighbors; // [esp+830h] [ebp-24h]
  int v97; // [esp+834h] [ebp-20h]
  CVertIndex cornerVert; // [esp+838h] [ebp-1Ch]
  Vector vAvgTanS; // [esp+83Ch] [ebp-18h] BYREF
  Vector vAverage; // [esp+848h] [ebp-Ch] BYREF

  m_pMemory = nullptr;
  memset(&nbCornerVerts, 0, sizeof(nbCornerVerts));
  for ( iDisp = 0; iDisp < nListSize; ++iDisp )
  {
    pDisp = ppListBase[iDisp];
    v3 = pDisp;
    AllNeighbors = GetAllNeighbors(iNeighbors, pDisp);
    m_Size = 0;
    nNeighbors = AllNeighbors;
    nbCornerVerts.m_Size = 0;
    if ( nbCornerVerts.m_Memory.m_nAllocationCount < AllNeighbors && nbCornerVerts.m_Memory.m_nGrowSize >= 0 )
    {
      nbCornerVerts.m_Memory.m_nAllocationCount = AllNeighbors;
      if ( m_pMemory != nullptr )
        v6 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 4 * AllNeighbors);
      else
        v6 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * AllNeighbors);
      nbCornerVerts.m_Memory.m_pMemory = v6;
      m_Size = nbCornerVerts.m_Size;
      m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
    }
    nbCornerVerts.m_pElements = m_pMemory;
    if ( AllNeighbors != 0 )
    {
      if ( AllNeighbors > nbCornerVerts.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&nbCornerVerts,
          num: AllNeighbors - nbCornerVerts.m_Memory.m_nAllocationCount);
        m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
        m_Size = nbCornerVerts.m_Size;
      }
      nbCornerVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && AllNeighbors > 0 )
        _V_memmove(dest: &m_pMemory[AllNeighbors], src: m_pMemory, count: 4 * m_Size);
    }
    for ( iCorner = 0; iCorner < 4; ++iCorner )
    {
      v86 = iCorner;
      v7 = (CPowerInfo *)v3->GetPowerInfo(this: v3);
      v8 = *CPowerInfo::GetCornerPointIndex(this: v7, iCorner: v86);
      GetPowerInfo = v3->GetPowerInfo;
      cornerVert = v8;
      v10 = (int)GetPowerInfo(this: v3);
      v11 = cornerVert.x + *(_DWORD *)(v10 + 36) * cornerVert.y;
      v12 = &v3->m_pVerts[v11];
      *(_QWORD *)&vAverage.x = *(_QWORD *)&v12->m_Normal.x;
      z = v12->m_Normal.z;
      p_m_Vert = &v12->m_Vert;
      p_m_TangentS = (int)&v3->m_pVerts[v11].m_TangentS;
      vAverage.z = z;
      vAvgTanS.x = *(float *)p_m_TangentS;
      vAvgTanS.y = *(float *)(p_m_TangentS + 4);
      v16 = *(float *)(p_m_TangentS + 8);
      vCornerVert = p_m_Vert;
      vAvgTanS.z = v16;
      if ( AllNeighbors > 0 )
      {
        v17 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v95 = nbCornerVerts.m_Memory.m_pMemory;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v97 = AllNeighbors;
        while ( 1 )
        {
          v18 = ppListBase[*(int *)((char *)v95 + *(_DWORD *)&v17)];
          NeighborCornerVert = FindNeighborCornerVert(pDisp: v18, vecPoint: vCornerVert);
          if ( NeighborCornerVert == -1 )
          {
            *v95 = -1;
          }
          else
          {
            v87 = NeighborCornerVert;
            v20 = (CPowerInfo *)v18->GetPowerInfo(this: v18);
            v21 = *CPowerInfo::GetCornerPointIndex(this: v20, iCorner: v87);
            v22 = v18->GetPowerInfo;
            viNBCornerVert = v21;
            v23 = (int)v22(this: v18);
            v24 = v21.x + *(_DWORD *)(v23 + 36) * viNBCornerVert.y;
            *v95 = v24;
            v24 *= 224;
            m_pVerts = v18->m_pVerts;
            vAverage.x = *(float *)((char *)&m_pVerts->m_Normal.x + v24) + vAverage.x;
            vAverage.y = *(float *)((char *)&m_pVerts->m_Normal.y + v24) + vAverage.y;
            vAverage.z = *(float *)((char *)&m_pVerts->m_Normal.z + v24) + vAverage.z;
            v26 = v18->m_pVerts;
            v27 = *(float *)((char *)&v26->m_TangentS.x + v24) + vAvgTanS.x;
            v28 = (int)&v26->m_TangentS + v24;
            vAvgTanS.x = v27;
            vAvgTanS.y = *(float *)(v28 + 4) + vAvgTanS.y;
            vAvgTanS.z = *(float *)(v28 + 8) + vAvgTanS.z;
          }
          ++v95;
          if ( --v97 == 0 )
            break;
          v17 = cornerVert;
        }
        AllNeighbors = nNeighbors;
        v3 = pDisp;
      }
      VectorNormalize(vec: &vAverage);
      VectorNormalize(vec: &vAvgTanS);
      v3->m_pVerts[v11].m_Normal = vAverage;
      v29 = vAverage.z;
      y = vAverage.y;
      v31 = vAvgTanS.z * vAverage.x;
      v32 = vAvgTanS.y * vAverage.x;
      v33 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
      x = vAvgTanS.x;
      v3->m_pVerts[v11].m_TangentS = vAvgTanS;
      p_x = &v3->m_pVerts[v11].m_TangentT.x;
      v36 = 0;
      *p_x = v33;
      p_x[1] = v31 - (float)(v29 * x);
      p_x[2] = (float)(y * x) - v32;
      if ( AllNeighbors >= 4 )
      {
        v37 = nbCornerVerts.m_Memory.m_pMemory + 2;
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        viNBCornerVert = (CVertIndex)((char *)&iNeighbors[1] - (char *)nbCornerVerts.m_Memory.m_pMemory);
        do
        {
          v38 = *(v37 - 2);
          if ( v38 != -1 )
          {
            v39 = v38;
            v40 = ppListBase[iNeighbors[v36]]->m_pVerts;
            v40[v39].m_Normal = vAverage;
            v41 = vAverage.z;
            v42 = vAverage.y;
            v43 = &v40[v39];
            AllNeighbors = nNeighbors;
            v44 = vAvgTanS.z * vAverage.x;
            v45 = vAvgTanS.y * vAverage.x;
            v46 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v47 = vAvgTanS.x;
            v43->m_TangentS = vAvgTanS;
            v43->m_TangentT.x = v46;
            v43->m_TangentT.y = v44 - (float)(v41 * v47);
            v43->m_TangentT.z = (float)(v42 * v47) - v45;
          }
          v48 = *(v37 - 1);
          if ( v48 != -1 )
          {
            v49 = v48;
            v50 = ppListBase[iNeighbors[v36 + 1]]->m_pVerts;
            v50[v49].m_Normal = vAverage;
            v51 = vAverage.z;
            v52 = vAverage.y;
            v53 = &v50[v49];
            AllNeighbors = nNeighbors;
            v54 = vAvgTanS.z * vAverage.x;
            v55 = vAvgTanS.y * vAverage.x;
            v56 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v57 = vAvgTanS.x;
            v53->m_TangentS = vAvgTanS;
            v53->m_TangentT.x = v56;
            v53->m_TangentT.y = v54 - (float)(v51 * v57);
            v53->m_TangentT.z = (float)(v52 * v57) - v55;
          }
          if ( *v37 != -1 )
          {
            v58 = *v37;
            v59 = ppListBase[*(int *)((char *)v37 + *(_DWORD *)&cornerVert)]->m_pVerts;
            v59[v58].m_Normal = vAverage;
            v60 = vAverage.z;
            v61 = vAverage.y;
            v62 = &v59[v58];
            AllNeighbors = nNeighbors;
            v63 = vAvgTanS.z * vAverage.x;
            v64 = vAvgTanS.y * vAverage.x;
            v65 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v66 = vAvgTanS.x;
            v62->m_TangentS = vAvgTanS;
            v62->m_TangentT.x = v65;
            v62->m_TangentT.y = v63 - (float)(v60 * v66);
            v62->m_TangentT.z = (float)(v61 * v66) - v64;
          }
          v67 = v37[1];
          if ( v67 != -1 )
          {
            v68 = &ppListBase[*(int *)((char *)v37 + *(_DWORD *)&viNBCornerVert)]->m_pVerts[v67];
            AllNeighbors = nNeighbors;
            v68->m_Normal = vAverage;
            v69 = vAverage.z;
            v70 = vAverage.y;
            v71 = vAvgTanS.z * vAverage.x;
            v72 = vAvgTanS.y * vAverage.x;
            v73 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v74 = vAvgTanS.x;
            v68->m_TangentS = vAvgTanS;
            v68->m_TangentT.x = v73;
            v68->m_TangentT.y = v71 - (float)(v69 * v74);
            v68->m_TangentT.z = (float)(v70 * v74) - v72;
          }
          v36 += 4;
          v37 += 4;
        }
        while ( v36 < AllNeighbors - 3 );
      }
      if ( v36 < AllNeighbors )
      {
        v75 = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v76 = &nbCornerVerts.m_Memory.m_pMemory[v36];
        cornerVert = (CVertIndex)((char *)iNeighbors - (char *)nbCornerVerts.m_Memory.m_pMemory);
        v97 = AllNeighbors - v36;
        do
        {
          if ( *v76 != -1 )
          {
            v77 = *v76;
            v78 = ppListBase[*(int *)((char *)v76 + *(_DWORD *)&v75)]->m_pVerts;
            v78[v77].m_Normal.x = vAverage.x;
            v75 = cornerVert;
            v78[v77].m_Normal.y = vAverage.y;
            v78[v77].m_Normal.z = vAverage.z;
            v79 = vAverage.z;
            v80 = vAverage.y;
            v81 = &v78[v77];
            v82 = vAvgTanS.z * vAverage.x;
            v83 = vAvgTanS.y * vAverage.x;
            v84 = (float)(vAverage.z * vAvgTanS.y) - (float)(vAverage.y * vAvgTanS.z);
            v85 = vAvgTanS.x;
            v81->m_TangentS = vAvgTanS;
            v81->m_TangentT.x = v84;
            v81->m_TangentT.y = v82 - (float)(v79 * v85);
            v81->m_TangentT.z = (float)(v80 * v85) - v83;
          }
          ++v76;
          --v97;
        }
        while ( v97 != 0 );
      }
    }
    m_pMemory = nbCornerVerts.m_Memory.m_pMemory;
  }
  if ( nbCornerVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10003E40
// Name: void SmoothDispSurfNormals(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmoothDispSurfNormals(CCoreDispInfo **ppListBase, int nListSize)
{
  int i; // esi

  for ( i = 0; i < nListSize; ++i )
    CCoreDispInfo::SetDispUtilsHelperInfo(this: ppListBase[i], ppListBase, listSize: nListSize);
  BlendSubNeighbors(ppListBase, nListSize);
  BlendCorners(ppListBase, nListSize);
  BlendEdges(ppListBase, nListSize);
}

//------------------------------------------------------------------------------
// Address: 0x1002B580
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10077160
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const float *v1, const float *v2, float *cross)
{
  *cross = (float)(v2[2] * v1[1]) - (float)(v1[2] * v2[1]);
  cross[1] = (float)(v1[2] * *v2) - (float)(*v1 * v2[2]);
  cross[2] = (float)(*v1 * v2[1]) - (float)(*v2 * v1[1]);
}

} // namespace vrad_dll
