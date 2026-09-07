// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vrad_dispcoll.cpp
// Functions: 16
// ============================================================

#include "utils\vrad\vrad_dispcoll.h"

//------------------------------------------------------------------------------
// Address: 0x10021D20
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: public: void CVRADDispColl::BaseFacePlaneToDispUV(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::BaseFacePlaneToDispUV(CVRADDispColl *this, const Vector *vecPlanePt, Vector2D *dispUV)
{
  PointInQuadToBarycentric(
    v1: this->m_vecSurfPoints,
    v2: &this->m_vecSurfPoints[3],
    v3: &this->m_vecSurfPoints[2],
    v4: &this->m_vecSurfPoints[1],
    point: vecPlanePt,
    uv: dispUV);
}

//------------------------------------------------------------------------------
// Address: 0x10021D70
// Name: int PlaneTypeForNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaneTypeForNormal(Vector *normal)
{
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  x = normal->x;
  if ( normal->x == 1.0 || x == -1.0 )
    return 0;
  y = normal->y;
  if ( y == 1.0 || y == -1.0 )
    return 1;
  z = normal->z;
  if ( z == 1.0 || z == -1.0 )
    return 2;
  v4 = fabs(x);
  v5 = fabs(y);
  v6 = fabs(z);
  if ( v4 >= v5 && v4 >= v6 )
    return 3;
  if ( v5 < v4 || v5 < v6 )
    return 5;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10021EC0
// Name: protected: void CVRADDispColl::DispUVToSurf_TriTLToBR(class Vector __near &,float,float,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::DispUVToSurf_TriTLToBR(
        CVRADDispColl *this,
        Vector *vecPoint,
        float flPushEps,
        float flU,
        float flV,
        int nSnapU,
        int nSnapV,
        int nWidth,
        int nHeight)
{
  int v10; // edi
  int v11; // eax
  int v12; // edx
  float v13; // xmm6_4
  int v14; // eax
  int v15; // ebx
  Vector *v16; // ecx
  float *v17; // eax
  float v18; // xmm2_4
  int v19; // edx
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  Vector *v23; // esi
  float v24; // xmm7_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm5_4
  float v31; // xmm1_4
  int v32; // ebx
  int v33; // esi
  Vector *m_pMemory; // ecx
  int v35; // edx
  float v36; // xmm5_4
  float *p_x; // eax
  float v38; // xmm7_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm6_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float v45; // xmm5_4
  float z; // xmm1_4
  float y; // xmm2_4
  float v48; // xmm0_4
  float edgeV; // [esp+Ch] [ebp-40h]
  float v50; // [esp+18h] [ebp-34h]
  float edgeU; // [esp+24h] [ebp-28h]
  Vector vecNormal; // [esp+3Ch] [ebp-10h] BYREF
  CVRADDispColl *v53; // [esp+48h] [ebp-4h]
  float flFracU; // [esp+64h] [ebp+18h]

  v53 = this;
  v10 = nSnapU + 1;
  v11 = nSnapV + 1;
  if ( nSnapU + 1 == nWidth )
    v10 = nSnapU;
  if ( v11 == nHeight )
    v11 = nSnapV;
  v12 = nWidth * nSnapV;
  v13 = flV - (float)nSnapV;
  flFracU = flU - (float)nSnapU;
  if ( (float)(v13 + flFracU) < 1.001 )
  {
    v32 = v12 + nSnapU;
    v33 = nSnapU + v11 * nWidth;
    m_pMemory = v53->m_aVerts.m_Memory.m_pMemory;
    v35 = v10 + v12;
    v36 = m_pMemory[v35].x - m_pMemory[v32].x;
    v18 = m_pMemory[v35].y - m_pMemory[v32].y;
    v22 = m_pMemory[v35].z - m_pMemory[v32].z;
    p_x = &m_pMemory[v32].x;
    v38 = m_pMemory[v33].x - *p_x;
    v39 = m_pMemory[v33].y - p_x[1];
    v40 = m_pMemory[v33].z - p_x[2];
    v23 = vecPoint;
    edgeV = v38;
    vecNormal.x = v38 * v13;
    vecNormal.y = v39 * v13;
    v50 = v36;
    vecNormal.z = v40 * v13;
    v41 = *p_x + (float)(v36 * flFracU);
    v42 = p_x[2];
    v43 = (float)(p_x[1] + (float)(v18 * flFracU)) + vecNormal.y;
    vecPoint->x = v41 + vecNormal.x;
    v44 = (float)(v42 + (float)(v22 * flFracU)) + vecNormal.z;
    vecPoint->y = v43;
    vecPoint->z = v44;
    if ( flPushEps == 0.0 )
      return;
    v45 = v39;
    v31 = v39 * v50;
    v28 = v40;
    v29 = v40 * v50;
    v30 = v45 * v22;
  }
  else
  {
    v14 = nWidth * v11;
    v15 = v14 + nSnapU;
    v16 = v53->m_aVerts.m_Memory.m_pMemory;
    v17 = &v16[v10 + v14].x;
    v18 = v16[v15].y - v17[1];
    v19 = v10 + v12;
    v20 = v16[v19].y - v17[1];
    v21 = v16[v19].z - v17[2];
    edgeU = v16[v15].x - *v17;
    v22 = v16[v15].z - v17[2];
    v23 = vecPoint;
    edgeV = v16[v19].x - *v17;
    v24 = edgeV * (float)(1.0 - v13);
    v25 = (float)(edgeU * (float)(1.0 - flFracU)) + *v17;
    vecNormal.y = v18 * (float)(1.0 - flFracU);
    v26 = (float)(v17[1] + vecNormal.y) + (float)(v20 * (float)(1.0 - v13));
    v27 = (float)(v17[2] + (float)(v22 * (float)(1.0 - flFracU))) + (float)(v21 * (float)(1.0 - v13));
    vecPoint->x = v25 + v24;
    vecPoint->y = v26;
    vecPoint->z = v27;
    if ( flPushEps == 0.0 )
      return;
    v28 = v21;
    v29 = v21 * edgeU;
    v30 = v22 * v20;
    v31 = v20 * edgeU;
  }
  vecNormal.x = (float)(v28 * v18) - v30;
  vecNormal.y = (float)(v22 * edgeV) - v29;
  vecNormal.z = v31 - (float)(v18 * edgeV);
  VectorNormalize(vec: &vecNormal);
  z = vecNormal.z;
  y = vecNormal.y;
  v23->x = (float)(vecNormal.x * flPushEps) + v23->x;
  v48 = v23->y + (float)(y * flPushEps);
  v23->z = (float)(z * flPushEps) + v23->z;
  v23->y = v48;
}

//------------------------------------------------------------------------------
// Address: 0x100221D0
// Name: protected: void CVRADDispColl::DispUVToSurf_TriBLToTR(class Vector __near &,float,float,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::DispUVToSurf_TriBLToTR(
        CVRADDispColl *this,
        Vector *vecPoint,
        float flPushEps,
        float flU,
        float flV,
        int nSnapU,
        int nSnapV,
        int nWidth,
        int nHeight)
{
  int v9; // edi
  int v10; // eax
  Vector *m_pMemory; // ecx
  float v12; // xmm5_4
  int v13; // edx
  float v14; // xmm6_4
  int v15; // eax
  int v16; // edi
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  Vector *v21; // esi
  int v22; // edx
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm1_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  int v37; // esi
  float *p_x; // eax
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm7_4
  float v44; // xmm4_4
  float v45; // xmm7_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float z; // xmm1_4
  float y; // xmm2_4
  float v52; // xmm0_4
  float v53; // [esp+Ch] [ebp-3Ch]
  float edgeU; // [esp+18h] [ebp-30h]
  float v55; // [esp+24h] [ebp-24h]
  float edgeV; // [esp+30h] [ebp-18h]
  float edgeV_4; // [esp+34h] [ebp-14h]
  Vector vecNormal; // [esp+3Ch] [ebp-Ch] BYREF

  v9 = nSnapU + 1;
  v10 = nSnapV + 1;
  if ( nSnapU + 1 == nWidth )
    v9 = nSnapU;
  if ( v10 == nHeight )
    v10 = nSnapV;
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  v12 = flU - (float)nSnapU;
  v13 = nWidth * nSnapV;
  v14 = flV - (float)nSnapV;
  if ( v14 <= v12 )
  {
    v37 = v10 * nWidth;
    p_x = &m_pMemory[v13 + v9].x;
    v39 = m_pMemory[v13 + nSnapU].z - p_x[2];
    v55 = m_pMemory[v13 + nSnapU].x - *p_x;
    v40 = m_pMemory[v13 + nSnapU].y - p_x[1];
    v41 = m_pMemory[v9 + v37].y - p_x[1];
    v42 = m_pMemory[v9 + v37].z - p_x[2];
    v43 = m_pMemory[v9 + v37].x - *p_x;
    v21 = vecPoint;
    edgeV_4 = v41 * v14;
    v44 = 1.0 - v12;
    v53 = v43;
    v45 = v43 * v14;
    v46 = (float)((float)(1.0 - v12) * v55) + *p_x;
    vecNormal.y = v40 * v44;
    v47 = (float)(p_x[2] + (float)(v39 * v44)) + (float)(v42 * v14);
    vecPoint->y = (float)(p_x[1] + (float)(v40 * v44)) + edgeV_4;
    vecPoint->x = v46 + v45;
    vecPoint->z = v47;
    if ( flPushEps == 0.0 )
      return;
    v48 = v41;
    v30 = v41 * v55;
    v49 = v42;
    v32 = v42 * v55;
    v33 = v48 * v39;
    v34 = v39 * v53;
    v35 = v49 * v40;
    v36 = v40 * v53;
  }
  else
  {
    v15 = nWidth * v10;
    v16 = v15 + v9;
    v17 = &m_pMemory[v15 + nSnapU].x;
    v18 = m_pMemory[v16].z - v17[2];
    v19 = m_pMemory[v16].x - *v17;
    v20 = m_pMemory[v16].y - v17[1];
    v21 = vecPoint;
    v22 = nSnapU + v13;
    v23 = m_pMemory[v22].y - v17[1];
    edgeV = m_pMemory[v22].x - *v17;
    v24 = m_pMemory[v22].z - v17[2];
    vecNormal.x = edgeV * (float)(1.0 - v14);
    vecNormal.y = v23 * (float)(1.0 - v14);
    vecNormal.z = v24 * (float)(1.0 - v14);
    v25 = (float)(*v17 + (float)(v19 * v12)) + vecNormal.x;
    v26 = (float)(v17[2] + (float)(v18 * v12)) + vecNormal.z;
    edgeU = v19;
    v27 = v20 * v12;
    v28 = v17[1];
    vecPoint->x = v25;
    vecPoint->y = (float)(v28 + v27) + vecNormal.y;
    vecPoint->z = v26;
    if ( flPushEps == 0.0 )
      return;
    v29 = v23;
    v30 = v23 * edgeU;
    v31 = v24;
    v32 = v24 * edgeU;
    v33 = v29 * v18;
    v34 = v18 * edgeV;
    v35 = v31 * v20;
    v36 = v20 * edgeV;
  }
  vecNormal.x = v33 - v35;
  vecNormal.y = v32 - v34;
  vecNormal.z = v36 - v30;
  VectorNormalize(vec: &vecNormal);
  z = vecNormal.z;
  y = vecNormal.y;
  v21->x = (float)(vecNormal.x * flPushEps) + v21->x;
  v52 = v21->y + (float)(y * flPushEps);
  v21->z = (float)(z * flPushEps) + v21->z;
  v21->y = v52;
}

//------------------------------------------------------------------------------
// Address: 0x100224E0
// Name: public: void CVRADDispColl::DispUVToSurfNormal(class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::DispUVToSurfNormal(CVRADDispColl *this, const Vector2D *dispUV, Vector *vecNormal)
{
  float x; // xmm4_4
  float y; // xmm3_4
  int v5; // edx
  float v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // esi
  int v9; // ebx
  float v10; // xmm2_4
  int v11; // eax
  int v12; // ecx
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm3_4
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // esi
  int v20; // ebx
  Vector *m_pMemory; // eax
  float v22; // xmm2_4
  float *v23; // edx
  float *p_x; // edx
  float *v25; // ecx
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float vecDispNormals_12; // [esp+Ch] [ebp-48h]
  float vecDispNormals_16; // [esp+10h] [ebp-44h]
  float vecDispNormals_20; // [esp+14h] [ebp-40h]
  float vecDispNormals_24; // [esp+18h] [ebp-3Ch]
  float vecDispNormals_28; // [esp+1Ch] [ebp-38h]
  float vecDispNormals_32; // [esp+20h] [ebp-34h]
  Vector vecBlendedNormals[2]; // [esp+30h] [ebp-24h] BYREF
  float flFracV; // [esp+48h] [ebp-Ch]
  float flFracU; // [esp+4Ch] [ebp-8h]
  CVRADDispColl *v40; // [esp+50h] [ebp-4h]

  x = dispUV->x;
  v40 = this;
  if ( x >= 0.0 && x <= 1.0 )
  {
    y = dispUV->y;
    if ( y >= 0.0 && y <= 1.0 )
    {
      v5 = (1 << this->m_nPower) + 1;
      v6 = (float)v5 - 1.000001;
      v7 = v6 * x;
      v8 = (int)(float)(v6 * x);
      v9 = v8 + 1;
      v10 = v6 * y;
      v11 = (int)v10;
      v12 = (int)v10 + 1;
      if ( v8 + 1 == v5 )
        v9 = v8;
      if ( v12 == v5 )
        v12 = (int)v10;
      v13 = v5 * v12;
      v14 = v7 - (float)v8;
      v15 = (float)v11;
      v16 = v5 * v11;
      v17 = v16 + v8;
      v18 = v13 + v8;
      v19 = v13 + v9;
      v20 = v16 + v9;
      m_pMemory = v40->m_aVertNormals.m_Memory.m_pMemory;
      flFracV = v10 - v15;
      v18 *= 3;
      v22 = *(&m_pMemory->x + v18);
      v23 = &m_pMemory->x + v18;
      vecDispNormals_12 = v22;
      vecDispNormals_16 = v23[1];
      vecDispNormals_20 = v23[2];
      p_x = &m_pMemory[v19].x;
      vecDispNormals_24 = *p_x;
      vecDispNormals_28 = p_x[1];
      v25 = &m_pMemory[v17].x;
      vecDispNormals_32 = p_x[2];
      v26 = (float)(m_pMemory[v20].x * v14) + (float)((float)(1.0 - v14) * *v25);
      v27 = (float)(m_pMemory[v20].y * v14) + (float)((float)(1.0 - v14) * v25[1]);
      v28 = (float)(m_pMemory[v20].z * v14) + (float)((float)(1.0 - v14) * v25[2]);
      flFracU = v14;
      vecBlendedNormals[0].x = v26;
      vecBlendedNormals[0].y = v27;
      vecBlendedNormals[0].z = v28;
      VectorNormalize(vec: vecBlendedNormals);
      vecBlendedNormals[1].x = (float)(vecDispNormals_24 * flFracU) + (float)((float)(1.0 - v14) * vecDispNormals_12);
      vecBlendedNormals[1].y = (float)(vecDispNormals_28 * flFracU) + (float)((float)(1.0 - v14) * vecDispNormals_16);
      vecBlendedNormals[1].z = (float)(vecDispNormals_32 * flFracU) + (float)((float)(1.0 - v14) * vecDispNormals_20);
      VectorNormalize(vec: &vecBlendedNormals[1]);
      v29 = (float)(vecBlendedNormals[1].y * flFracV) + (float)(vecBlendedNormals[0].y * (float)(1.0 - flFracV));
      v30 = (float)(vecBlendedNormals[1].z * flFracV) + (float)(vecBlendedNormals[0].z * (float)(1.0 - flFracV));
      vecNormal->x = (float)(vecBlendedNormals[1].x * flFracV)
                   + (float)((float)(1.0 - flFracV) * vecBlendedNormals[0].x);
      vecNormal->y = v29;
      vecNormal->z = v30;
      VectorNormalize(vec: vecNormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022730
// Name: public: bool CVRADDispColl::InitParentPatch(int,class Vector __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRADDispColl::InitParentPatch(CVRADDispColl *this, int iPatch, Vector *pPoints, float *flArea)
{
  CPatch *v4; // esi
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float *p_z; // ebx
  float v14; // xmm0_4
  winding_t *v15; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  Vector *v30; // eax
  int v31; // eax
  int v32; // edx
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  __int128 v36; // xmm5
  __int128 v37; // xmm4
  __int128 v38; // xmm6
  int i; // eax
  __int128 v40; // xmm0
  __int128 v41; // xmm0
  __int128 v42; // xmm0
  int faceNumber; // eax
  Vector vecNormal; // [esp+Ch] [ebp-Ch] BYREF

  v4 = &g_Patches.m_Memory.m_pMemory[iPatch];
  if ( v4 == nullptr )
    return 0;
  memset(
    dst: (unsigned __int8 *)&g_Patches.m_Memory.m_pMemory[iPatch],
    value: 0,
    count: sizeof(g_Patches.m_Memory.m_pMemory[iPatch]));
  v4->ndxNext = g_FacePatches.m_Memory.m_pMemory[this->m_iParent];
  g_FacePatches.m_Memory.m_pMemory[this->m_iParent] = iPatch;
  v4->faceNumber = this->m_iParent;
  v4->child1 = -1;
  v4->child2 = -1;
  v4->parent = -1;
  v4->ndxNextClusterChild = -1;
  v4->ndxNextParent = -1;
  v7 = pPoints[3].y - pPoints->y;
  v8 = pPoints[3].z - pPoints->z;
  v9 = pPoints[1].y - pPoints->y;
  v10 = pPoints[1].z - pPoints->z;
  v11 = pPoints[1].x - pPoints->x;
  v12 = pPoints[3].x - pPoints->x;
  p_z = &pPoints->z;
  vecNormal.x = (float)(v7 * v10) - (float)(v8 * v9);
  vecNormal.y = (float)(v8 * v11) - (float)(v10 * v12);
  vecNormal.z = (float)(v9 * v12) - (float)(v7 * v11);
  *flArea = VectorNormalize(vec: &vecNormal);
  v4->scale[1] = 1.0;
  v4->scale[0] = 1.0;
  v14 = dispchop;
  *((_DWORD *)v4 + 18) &= ~4u;
  v4->chop = v14;
  v15 = AllocWinding(points: 4);
  v4->winding = v15;
  v15->numpoints = 4;
  *v4->winding->p = *pPoints;
  x = pPoints->x;
  y = pPoints->y;
  z = pPoints->z;
  v4->winding->p[1] = pPoints[1];
  v19 = x + pPoints[1].x;
  v20 = pPoints[1].y + y;
  v21 = pPoints[1].z;
  v4->winding->p[2] = pPoints[2];
  v22 = v21 + z;
  v23 = v19 + pPoints[2].x;
  v24 = pPoints[2].y;
  v25 = pPoints[2].z;
  v4->winding->p[3] = pPoints[3];
  v26 = v24 + v20;
  v27 = v25 + v22;
  v28 = pPoints[3].z;
  v29 = v23 + pPoints[3].x;
  v4->origin.y = (float)(pPoints[3].y + v26) * 0.25;
  v4->origin.x = v29 * 0.25;
  v4->origin.z = (float)(v28 + v27) * 0.25;
  v4->normal = vecNormal;
  v30 = (Vector *)MemAlloc_Alloc(nSize: 0x14u);
  v4->plane = (dplane_t *)v30;
  if ( v30 == nullptr )
    return 0;
  *v30 = vecNormal;
  v4->plane->dist = (float)((float)(pPoints->x * vecNormal.x) + (float)(vecNormal.y * pPoints->y))
                  + (float)(*p_z * vecNormal.z);
  v31 = PlaneTypeForNormal(normal: &v4->plane->normal);
  *(_DWORD *)(v32 + 16) = v31;
  v4->planeDist = v4->plane->dist;
  v33 = 3.4028235e38;
  v34 = 3.4028235e38;
  v35 = 3.4028235e38;
  v4->area = *flArea;
  v36 = 0x800000u;
  v37 = 0x800000u;
  v38 = 0x800000u;
  for ( i = 4; i != 0; --i )
  {
    v40 = *((unsigned int *)p_z - 2);
    if ( *(float *)&v40 <= v33 )
      v33 = *(p_z - 2);
    if ( *(float *)&v36 > *(float *)&v40 )
      v40 = v36;
    v36 = v40;
    v41 = *((unsigned int *)p_z - 1);
    if ( *(float *)&v41 <= v34 )
      v34 = *(p_z - 1);
    if ( *(float *)&v37 > *(float *)&v41 )
      v41 = v37;
    v37 = v41;
    v42 = *(unsigned int *)p_z;
    if ( *(float *)&v42 <= v35 )
      v35 = *p_z;
    if ( *(float *)&v38 > *(float *)&v42 )
      v42 = v38;
    p_z += 3;
    v38 = v42;
  }
  v4->mins.x = v33;
  v4->mins.y = v34;
  v4->mins.z = v35;
  LODWORD(v4->maxs.x) = v36;
  LODWORD(v4->maxs.y) = v37;
  LODWORD(v4->maxs.z) = v42;
  v4->face_mins.x = v33;
  v4->face_mins.y = v34;
  v4->face_mins.z = v35;
  LODWORD(v4->face_maxs.x) = v36;
  LODWORD(v4->face_maxs.y) = v37;
  LODWORD(v4->face_maxs.z) = v42;
  faceNumber = v4->faceNumber;
  *((_DWORD *)v4 + 18) ^= (*((_DWORD *)v4 + 18)
                         ^ (8
                          * (unsigned __int8)((unsigned int)texinfo.m_Memory.m_pMemory[dfaces[faceNumber].texinfo].flags >> 11)))
                        & 8;
  v4->m_IterationKey = 0;
  BaseLightForFace(
    f: &g_pFaces[faceNumber],
    light: &v4->baselight,
    parea: &v4->basearea,
    reflectivity: &v4->reflectivity);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10022B10
// Name: public: bool CVRADDispColl::InitPatch(int,int,int,class Vector __near *,int __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRADDispColl::InitPatch(
        CVRADDispColl *this,
        int iPatch,
        int iParentPatch,
        int iChild,
        Vector *pPoints,
        int *pIndices,
        float *flArea)
{
  CPatch *v7; // esi
  CPatch *v9; // ecx
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float *p_z; // ebx
  float v18; // xmm0_4
  winding_t *v19; // eax
  float x; // xmm3_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  Vector *v31; // eax
  int v32; // eax
  int v33; // edx
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  __int128 v37; // xmm5
  __int128 v38; // xmm4
  __int128 v39; // xmm6
  int i; // eax
  __int128 v41; // xmm0
  __int128 v42; // xmm0
  __int128 v43; // xmm0
  CPatch *v44; // ecx
  int faceNumber; // eax
  Vector vecNormal; // [esp+Ch] [ebp-14h] BYREF
  CVRADDispColl *v47; // [esp+18h] [ebp-8h]
  CPatch *pParentPatch; // [esp+1Ch] [ebp-4h]

  v7 = &g_Patches.m_Memory.m_pMemory[iPatch];
  v47 = this;
  if ( v7 == nullptr )
    return 0;
  memset(
    dst: (unsigned __int8 *)&g_Patches.m_Memory.m_pMemory[iPatch],
    value: 0,
    count: sizeof(g_Patches.m_Memory.m_pMemory[iPatch]));
  pParentPatch = nullptr;
  if ( iParentPatch == -1 )
  {
    v7->ndxNext = g_FacePatches.m_Memory.m_pMemory[this->m_iParent];
    g_FacePatches.m_Memory.m_pMemory[this->m_iParent] = iPatch;
    v7->faceNumber = v47->m_iParent;
  }
  else
  {
    v9 = &g_Patches.m_Memory.m_pMemory[iParentPatch];
    pParentPatch = v9;
    if ( v9 == nullptr )
      return 0;
    v7->ndxNext = -1;
    v7->faceNumber = v9->faceNumber;
    if ( iChild != 0 )
      v9->child2 = iPatch;
    else
      v9->child1 = iPatch;
  }
  v7->parent = iParentPatch;
  v7->child1 = -1;
  v7->child2 = -1;
  v7->ndxNextClusterChild = -1;
  v7->ndxNextParent = -1;
  v11 = pPoints[2].y - pPoints->y;
  v12 = pPoints[2].z - pPoints->z;
  v13 = pPoints[1].y - pPoints->y;
  v14 = pPoints[1].z - pPoints->z;
  v15 = pPoints[1].x - pPoints->x;
  v16 = pPoints[2].x - pPoints->x;
  p_z = &pPoints->z;
  vecNormal.x = (float)(v11 * v14) - (float)(v12 * v13);
  vecNormal.y = (float)(v12 * v15) - (float)(v14 * v16);
  vecNormal.z = (float)(v13 * v16) - (float)(v11 * v15);
  *flArea = VectorNormalize(vec: &vecNormal) * 0.5;
  v7->scale[1] = 1.0;
  v7->scale[0] = 1.0;
  v18 = dispchop;
  *((_DWORD *)v7 + 18) &= ~4u;
  v7->chop = v18;
  v19 = AllocWinding(points: 3);
  v7->winding = v19;
  v19->numpoints = 3;
  *v7->winding->p = *pPoints;
  x = pPoints->x;
  y = pPoints->y;
  z = pPoints->z;
  v7->indices[0] = *(_WORD *)pIndices;
  v7->winding->p[1] = pPoints[1];
  v23 = pPoints[1].x;
  v24 = y + pPoints[1].y;
  v25 = z + pPoints[1].z;
  v7->indices[1] = *((_WORD *)pIndices + 2);
  v26 = v23 + x;
  v27 = v24;
  v7->winding->p[2] = pPoints[2];
  v28 = pPoints[2].x;
  v29 = v27 + pPoints[2].y;
  v30 = v25 + pPoints[2].z;
  v7->indices[2] = *((_WORD *)pIndices + 4);
  v7->origin.x = (float)(v28 + v26) * 0.33333334;
  v7->origin.y = v29 * 0.33333334;
  v7->origin.z = v30 * 0.33333334;
  v7->normal = vecNormal;
  v31 = (Vector *)MemAlloc_Alloc(nSize: 0x14u);
  v7->plane = (dplane_t *)v31;
  if ( v31 == nullptr )
    return 0;
  *v31 = vecNormal;
  v7->plane->dist = (float)((float)(pPoints->x * vecNormal.x) + (float)(vecNormal.y * pPoints->y))
                  + (float)(*p_z * vecNormal.z);
  v32 = PlaneTypeForNormal(normal: &v7->plane->normal);
  *(_DWORD *)(v33 + 16) = v32;
  v34 = 3.4028235e38;
  v7->planeDist = v7->plane->dist;
  v35 = 3.4028235e38;
  v36 = 3.4028235e38;
  v7->area = *flArea;
  v37 = 0x800000u;
  v38 = 0x800000u;
  v39 = 0x800000u;
  for ( i = 3; i != 0; --i )
  {
    v41 = *((unsigned int *)p_z - 2);
    if ( *(float *)&v41 <= v34 )
      v34 = *(p_z - 2);
    if ( *(float *)&v37 > *(float *)&v41 )
      v41 = v37;
    v37 = v41;
    v42 = *((unsigned int *)p_z - 1);
    if ( *(float *)&v42 <= v35 )
      v35 = *(p_z - 1);
    if ( *(float *)&v38 > *(float *)&v42 )
      v42 = v38;
    v38 = v42;
    v43 = *(unsigned int *)p_z;
    if ( *(float *)&v43 <= v36 )
      v36 = *p_z;
    if ( *(float *)&v39 > *(float *)&v43 )
      v43 = v39;
    p_z += 3;
    v39 = v43;
  }
  v44 = pParentPatch;
  v7->mins.x = v34;
  v7->mins.y = v35;
  v7->mins.z = v36;
  LODWORD(v7->maxs.x) = v37;
  LODWORD(v7->maxs.y) = v38;
  LODWORD(v7->maxs.z) = v43;
  if ( v44 != nullptr )
  {
    v7->face_mins.x = v44->face_mins.x;
    v7->face_mins.y = v44->face_mins.y;
    v7->face_mins.z = v44->face_mins.z;
    v7->face_maxs.x = v44->face_maxs.x;
    v7->face_maxs.y = v44->face_maxs.y;
    v7->face_maxs.z = v44->face_maxs.z;
  }
  else
  {
    v7->face_mins.x = v34;
    v7->face_mins.y = v35;
    v7->face_mins.z = v36;
    LODWORD(v7->face_maxs.x) = v37;
    LODWORD(v7->face_maxs.y) = v38;
    LODWORD(v7->face_maxs.z) = v43;
  }
  faceNumber = v7->faceNumber;
  *((_DWORD *)v7 + 18) ^= (*((_DWORD *)v7 + 18)
                         ^ (8
                          * (unsigned __int8)((unsigned int)texinfo.m_Memory.m_pMemory[dfaces[faceNumber].texinfo].flags >> 11)))
                        & 8;
  v7->m_IterationKey = 0;
  if ( v44 != nullptr )
  {
    v7->baselight.x = v44->baselight.x;
    v7->baselight.y = v44->baselight.y;
    v7->baselight.z = v44->baselight.z;
    v7->basearea = v44->basearea;
    v7->reflectivity.x = v44->reflectivity.x;
    v7->reflectivity.y = v44->reflectivity.y;
    v7->reflectivity.z = v44->reflectivity.z;
  }
  else
  {
    BaseLightForFace(
      f: &g_pFaces[faceNumber],
      light: &v7->baselight,
      parea: &v7->basearea,
      reflectivity: &v7->reflectivity);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10022FC0
// Name: public: void CVRADDispColl::AddPolysForRayTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::AddPolysForRayTrace(CVRADDispColl *this)
{
  CDispCollTri *v2; // eax
  Vector *m_pMemory; // esi
  const Vector *v4; // [esp-18h] [ebp-30h]
  const Vector *v5; // [esp-14h] [ebp-2Ch]
  const Vector *v6; // [esp-10h] [ebp-28h]
  Vector fullCoverage; // [esp+4h] [ebp-14h] BYREF
  int ndxTri; // [esp+10h] [ebp-8h]
  unsigned int v9; // [esp+14h] [ebp-4h]

  if ( (this->m_nContents & 0x4081) != 0 )
  {
    ndxTri = 0;
    if ( this->m_aTris.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v2 = &this->m_aTris.m_Memory.m_pMemory[v9 / 0x18];
        m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
        v6 = &m_pMemory[v2->m_TriData[2].m_IndexDummy & 0x1FF];
        v5 = &m_pMemory[v2->m_TriData[1].m_IndexDummy & 0x1FF];
        v4 = &m_pMemory[v2->m_TriData[0].m_IndexDummy & 0x1FF];
        fullCoverage.x = 1.0;
        RayTracingEnvironment::AddTriangle(this: &g_RtEnv, id: 0x2000000, v1: v4, v2: v5, v3: v6, color: &fullCoverage);
        v9 += 24;
        ++ndxTri;
      }
      while ( ndxTri < this->m_aTris.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023070
// Name: public: void CVRADDispColl::DispUVToSurfPoint(class Vector2D const __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRADDispColl::DispUVToSurfPoint(
        CVRADDispColl *this,
        const Vector2D *dispUV,
        Vector *vecPoint,
        float flPushEps)
{
  float x; // xmm3_4
  float y; // xmm2_4
  int v6; // eax
  float v7; // xmm1_4
  float flV; // xmm0_4
  float flU; // xmm1_4
  int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]

  x = dispUV->x;
  if ( dispUV->x >= 0.0 && x <= 1.0 )
  {
    y = dispUV->y;
    if ( y >= 0.0 && y <= 1.0 )
    {
      v6 = (1 << this->m_nPower) + 1;
      v7 = (float)v6 - 1.000001;
      flV = v7 * y;
      flU = v7 * x;
      v11 = (int)flV;
      v10 = (int)flU;
      if ( ((int)flU + v6 * (int)flV) % 2 == 1 )
        CVRADDispColl::DispUVToSurf_TriTLToBR(
          this,
          vecPoint,
          flPushEps,
          flU,
          flV,
          nSnapU: v10,
          nSnapV: v11,
          nWidth: v6,
          nHeight: v6);
      else
        CVRADDispColl::DispUVToSurf_TriBLToTR(
          this,
          vecPoint,
          flPushEps,
          flU,
          flV,
          nSnapU: v10,
          nSnapV: v11,
          nWidth: v6,
          nHeight: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100231C0
// Name: public: CVRADDispColl::CVRADDispColl(void)
// Source: json
//------------------------------------------------------------------------------
CVRADDispColl *__thiscall CVRADDispColl::CVRADDispColl(CVRADDispColl *this)
{
  CDispCollTree::CDispCollTree(this);
  this->__vftable = (CVRADDispColl_vtbl *)&CVRADDispColl::`vftable';
  this->m_aLuxelCoords.m_Memory.m_pMemory = nullptr;
  this->m_aLuxelCoords.m_Memory.m_nAllocationCount = 0;
  this->m_aLuxelCoords.m_Memory.m_nGrowSize = 0;
  this->m_aLuxelCoords.m_pElements = nullptr;
  this->m_aVertNormals.m_Memory.m_pMemory = nullptr;
  this->m_aVertNormals.m_Memory.m_nAllocationCount = 0;
  this->m_aVertNormals.m_Memory.m_nGrowSize = 0;
  this->m_aVertNormals.m_Size = 0;
  this->m_aVertNormals.m_pElements = nullptr;
  this->m_iParent = -1;
  this->m_flSampleRadius2 = 0.0;
  this->m_flPatchSampleRadius2 = 0.0;
  this->m_flSampleWidth = 0.0;
  this->m_flSampleHeight = 0.0;
  this->m_aLuxelCoords.m_Size = 0;
  if ( this->m_aLuxelCoords.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aLuxelCoords.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aLuxelCoords.m_Memory.m_pMemory);
      this->m_aLuxelCoords.m_Memory.m_pMemory = nullptr;
    }
    this->m_aLuxelCoords.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aLuxelCoords.m_pElements = this->m_aLuxelCoords.m_Memory.m_pMemory;
  this->m_aVertNormals.m_Size = 0;
  if ( this->m_aVertNormals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aVertNormals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aVertNormals.m_Memory.m_pMemory);
      this->m_aVertNormals.m_Memory.m_pMemory = nullptr;
    }
    this->m_aVertNormals.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aVertNormals.m_pElements = this->m_aVertNormals.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100232C0
// Name: public: float CVRADDispColl::CreateParentPatches(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVRADDispColl::CreateParentPatches(CVRADDispColl *this)
{
  int v2; // eax
  Vector *m_pMemory; // ecx
  Vector *v4; // edx
  Vector *v5; // edx
  Vector *v6; // eax
  float z; // xmm0_4
  int m_Size; // eax
  int v9; // esi
  int v10; // eax
  Vector vecPoints[4]; // [esp+8h] [ebp-34h] BYREF
  float flArea; // [esp+38h] [ebp-4h] BYREF

  v2 = 1 << this->m_nPower;
  m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
  vecPoints[0] = *m_pMemory;
  ++v2;
  v4 = &m_pMemory[v2 * (v2 - 1)];
  vecPoints[1] = *v4;
  v5 = &m_pMemory[v2 * v2];
  vecPoints[2] = v5[-1];
  v6 = &m_pMemory[v2];
  vecPoints[3].x = v6[-1].x;
  vecPoints[3].y = v6[-1].y;
  z = v6[-1].z;
  m_Size = g_Patches.m_Size;
  vecPoints[3].z = z;
  v9 = g_Patches.m_Size;
  if ( g_Patches.m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CPatch,int>::Grow(
      this: &g_Patches.m_Memory,
      num: g_Patches.m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Patches.m_Size;
  }
  g_Patches.m_Size = m_Size + 1;
  v10 = m_Size - v9;
  g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &g_Patches.m_Memory.m_pMemory[v9 + 1], src: &g_Patches.m_Memory.m_pMemory[v9], count: 264 * v10);
  if ( v9 == -1 )
    return 0.0;
  flArea = 0.0;
  if ( CVRADDispColl::InitParentPatch(this, iPatch: v9, pPoints: vecPoints, &flArea) == 0 )
  {
    if ( g_Patches.m_Size - v9 - 1 > 0 )
      _V_memmove(
        dest: &g_Patches.m_Memory.m_pMemory[v9],
        src: &g_Patches.m_Memory.m_pMemory[v9 + 1],
        count: 264 * (g_Patches.m_Size - v9 - 1));
    --g_Patches.m_Size;
    return 0.0;
  }
  return flArea;
}

//------------------------------------------------------------------------------
// Address: 0x10023440
// Name: public: void CVRADDispColl::CreateChildPatchesFromRoot(int,int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVRADDispColl::CreateChildPatchesFromRoot(
        CVRADDispColl *this@<ecx>,
        float a2@<ebp>,
        int iParentPatch,
        int *pChildPatch)
{
  int v5; // esi
  CPatch *v6; // eax
  float *p_x; // eax
  float v8; // xmm1_4
  float v9; // xmm3_4
  float m_flSampleHeight; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float m_flSampleWidth; // xmm5_4
  float *v21; // eax
  int i; // ecx
  float v23; // xmm6_4
  __int128 v24; // xmm5
  double v25; // st7
  Vector *m_pMemory; // eax
  Vector *v27; // edx
  float z; // xmm0_4
  _DWORD *v29; // eax
  int v30; // xmm0_4
  int m_Size; // eax
  int v32; // esi
  int v33; // eax
  int *v34; // esi
  Vector *v35; // eax
  float v36; // xmm0_4
  _DWORD *v37; // ecx
  int v38; // xmm0_4
  _DWORD *v39; // eax
  int v40; // xmm0_4
  int v41; // eax
  int v42; // esi
  int v43; // eax
  int v44; // eax
  int v45; // ecx
  float v46; // [esp-Ch] [ebp-6Ch]
  _DWORD v47[2]; // [esp-8h] [ebp-68h] BYREF
  Vector v48; // [esp+0h] [ebp-60h] BYREF
  _BYTE vecPoints[40]; // [esp+Ch] [ebp-54h] OVERLAPPED BYREF
  Vector vecNormal; // [esp+34h] [ebp-2Ch] BYREF
  int v51; // [esp+40h] [ebp-20h]
  int v52; // [esp+44h] [ebp-1Ch]
  int iPoints[3]; // [esp+48h] [ebp-18h] BYREF
  float flArea; // [esp+54h] [ebp-Ch]
  float flMinArea; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  flArea = a2;
  flMinArea = retaddr;
  *pChildPatch = -1;
  pChildPatch[1] = -1;
  v5 = (1 << this->m_nPower) + 1;
  v6 = &g_Patches.m_Memory.m_pMemory[iParentPatch];
  if ( v6 != nullptr )
  {
    p_x = &v6->winding->p->x;
    v8 = p_x[6] - p_x[3];
    v9 = p_x[7] - p_x[4];
    m_flSampleHeight = this->m_flSampleHeight;
    v11 = p_x[3] - *p_x;
    v12 = p_x[4] - p_x[1];
    v13 = p_x[5] - p_x[2];
    v48.z = p_x[8] - p_x[5];
    v14 = p_x[11] - p_x[8];
    v48.x = v8;
    v15 = p_x[9] - p_x[6];
    v48.y = v9;
    v16 = p_x[10] - p_x[7];
    *(float *)&vecPoints[8] = v14;
    v17 = p_x[9] - *p_x;
    *(float *)vecPoints = v15;
    v18 = p_x[11] - p_x[2];
    *(float *)&vecPoints[4] = v16;
    v19 = p_x[10] - p_x[1];
    vecNormal.z = v17;
    *(float *)&vecPoints[12] = v17;
    m_flSampleWidth = this->m_flSampleWidth;
    v46 = v11;
    *(float *)v47 = v12;
    *(float *)&v47[1] = v13;
    *(float *)&vecPoints[16] = v19;
    *(float *)&vecPoints[20] = v18;
    if ( m_flSampleWidth <= m_flSampleHeight )
      m_flSampleWidth = m_flSampleHeight;
    *(float *)&iPoints[1] = dispchop * m_flSampleWidth;
    iPoints[2] = 0;
    v21 = (float *)v47;
    for ( i = 4; i != 0; --i )
    {
      v24 = 0;
      v23 = *(float *)&iPoints[2];
      *(float *)&v24 = fsqrt((float)((float)(*(v21 - 1) * *(v21 - 1)) + (float)(v21[1] * v21[1])) + (float)(*v21 * *v21));
      *(_OWORD *)&vecPoints[24] = v24;
      if ( *(float *)&v24 > *(float *)&iPoints[2] )
      {
        *(_OWORD *)&vecPoints[24] = v24;
        v23 = *(float *)&v24;
        iPoints[2] = v24;
      }
      v21 += 3;
    }
    if ( *(float *)&iPoints[1] <= v23 )
    {
      *(float *)&iPoints[1] = *(float *)&iPoints[1] * *(float *)&iPoints[1];
      *(float *)&vecPoints[28] = (float)(v19 * v13) - (float)(v18 * v12);
      *(float *)&vecPoints[32] = (float)(v18 * v11) - (float)(v13 * vecNormal.z);
      *(float *)&vecPoints[36] = (float)(v12 * vecNormal.z) - (float)(v19 * v11);
      v25 = VectorNormalize(vec: (Vector *)&vecPoints[28]);
      if ( *(float *)&iPoints[1] <= v25 )
      {
        m_pMemory = this->m_aVerts.m_Memory.m_pMemory;
        iPoints[1] = v5 * v5 - 1;
        LODWORD(vecNormal.z) = iPoints[1];
        iPoints[2] = v5 - 1;
        v27 = &m_pMemory[iPoints[1]];
        v48 = *v27;
        *(float *)vecPoints = m_pMemory->x;
        *(float *)&vecPoints[4] = m_pMemory->y;
        z = m_pMemory->z;
        v52 = v5 * (v5 - 1);
        v29 = (_DWORD *)&m_pMemory[v52].x;
        *(float *)&vecPoints[8] = z;
        *(_DWORD *)&vecPoints[12] = *v29;
        *(_DWORD *)&vecPoints[16] = v29[1];
        v30 = v29[2];
        m_Size = g_Patches.m_Size;
        v51 = 0;
        *(_DWORD *)&vecPoints[20] = v30;
        v32 = g_Patches.m_Size;
        if ( g_Patches.m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPatch,int>::Grow(
            this: &g_Patches.m_Memory,
            num: g_Patches.m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
          m_Size = g_Patches.m_Size;
        }
        g_Patches.m_Size = m_Size + 1;
        v33 = m_Size - v32;
        g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
        if ( v33 > 0 )
          _V_memmove(
            dest: &g_Patches.m_Memory.m_pMemory[v32 + 1],
            src: &g_Patches.m_Memory.m_pMemory[v32],
            count: 264 * v33);
        *pChildPatch = v32;
        if ( v32 != -1 )
        {
          if ( CVRADDispColl::InitPatch(
                 this,
                 iPatch: v32,
                 iParentPatch,
                 iChild: 0,
                 pPoints: &v48,
                 pIndices: (int *)&vecNormal.z,
                 flArea: (float *)iPoints) == 0 )
          {
            v34 = pChildPatch;
LABEL_17:
            if ( g_Patches.m_Size - *v34 - 1 > 0 )
              _V_memmove(
                dest: &g_Patches.m_Memory.m_pMemory[*v34],
                src: &g_Patches.m_Memory.m_pMemory[*v34 + 1],
                count: 264 * (g_Patches.m_Size - *v34 - 1));
            --g_Patches.m_Size;
            *v34 = -1;
            return;
          }
          v35 = this->m_aVerts.m_Memory.m_pMemory;
          v48.x = v35->x;
          v48.y = v35->y;
          v36 = v35->z;
          v51 = iPoints[1];
          v48.z = v36;
          v37 = (_DWORD *)&v35[iPoints[1]].x;
          *(_DWORD *)vecPoints = *v37;
          v38 = v37[1];
          v52 = iPoints[2];
          *(_DWORD *)&vecPoints[4] = v38;
          v39 = (_DWORD *)&v35[iPoints[2]].x;
          *(_DWORD *)&vecPoints[8] = v37[2];
          *(_DWORD *)&vecPoints[12] = *v39;
          *(_DWORD *)&vecPoints[16] = v39[1];
          v40 = v39[2];
          v41 = g_Patches.m_Size;
          v42 = g_Patches.m_Size;
          vecNormal.z = 0.0;
          *(_DWORD *)&vecPoints[20] = v40;
          iPoints[1] = g_Patches.m_Size;
          if ( g_Patches.m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CPatch,int>::Grow(
              this: &g_Patches.m_Memory,
              num: g_Patches.m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
            v41 = g_Patches.m_Size;
          }
          g_Patches.m_Size = v41 + 1;
          v43 = v41 - v42;
          g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
          if ( v43 > 0 )
            _V_memmove(
              dest: &g_Patches.m_Memory.m_pMemory[v42 + 1],
              src: &g_Patches.m_Memory.m_pMemory[v42],
              count: 264 * v43);
          v44 = iPoints[1];
          v34 = pChildPatch;
          pChildPatch[1] = iPoints[1];
          if ( v44 == -1 )
            goto LABEL_17;
          if ( CVRADDispColl::InitPatch(
                 this,
                 iPatch: v44,
                 iParentPatch,
                 iChild: 1,
                 pPoints: &v48,
                 pIndices: (int *)&vecNormal.z,
                 flArea: (float *)iPoints) == 0 )
          {
            if ( g_Patches.m_Size - *pChildPatch - 1 > 0 )
              _V_memmove(
                dest: &g_Patches.m_Memory.m_pMemory[*pChildPatch],
                src: &g_Patches.m_Memory.m_pMemory[*pChildPatch + 1],
                count: 264 * (g_Patches.m_Size - *pChildPatch - 1));
            --g_Patches.m_Size;
            v45 = pChildPatch[1];
            *pChildPatch = -1;
            if ( g_Patches.m_Size - v45 - 1 > 0 )
              _V_memmove(
                dest: &g_Patches.m_Memory.m_pMemory[v45],
                src: &g_Patches.m_Memory.m_pMemory[v45 + 1],
                count: 264 * (g_Patches.m_Size - v45 - 1));
            --g_Patches.m_Size;
            pChildPatch[1] = -1;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023940
// Name: public: void CVRADDispColl::CreateChildPatchesSub(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVRADDispColl::CreateChildPatchesSub(CVRADDispColl *this@<ecx>, int a2@<ebp>, int iParentPatch)
{
  CPatch *v3; // edi
  float m_flSampleHeight; // xmm1_4
  float *p_x; // eax
  float v6; // xmm4_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  int v15; // esi
  int v16; // eax
  float *p_y; // ecx
  float v18; // xmm6_4
  __int128 v19; // xmm5
  double v20; // st7
  Vector *p; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  Vector *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float z; // xmm0_4
  int m_Size; // eax
  int v36; // edi
  int v37; // esi
  int v38; // eax
  CVRADDispColl *v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  CVRADDispColl *v43; // esi
  Vector *v44; // [esp-20h] [ebp-A8h]
  _DWORD v45[3]; // [esp-Ch] [ebp-94h] BYREF
  Vector vecEdges[3]; // [esp+0h] [ebp-88h] BYREF
  int x_low; // [esp+24h] [ebp-64h]
  float y; // [esp+28h] [ebp-60h]
  float v49; // [esp+2Ch] [ebp-5Ch]
  float x; // [esp+30h] [ebp-58h]
  float v51; // [esp+34h] [ebp-54h]
  float v52; // [esp+38h] [ebp-50h]
  int v53[3]; // [esp+40h] [ebp-48h] BYREF
  __int128 nChildIndices; // [esp+4Ch] [ebp-3Ch] OVERLAPPED BYREF
  Vector vecNormal; // [esp+5Ch] [ebp-2Ch]
  int v56; // [esp+68h] [ebp-20h]
  float v57; // [esp+6Ch] [ebp-1Ch] BYREF
  int iChildPatch[2]; // [esp+70h] [ebp-18h]
  float flArea; // [esp+78h] [ebp-10h]
  int v60; // [esp+7Ch] [ebp-Ch]
  CPatch *pParentPatch; // [esp+80h] [ebp-8h]
  CPatch *retaddr; // [esp+88h] [ebp+0h]

  v60 = a2;
  pParentPatch = retaddr;
  v3 = &g_Patches.m_Memory.m_pMemory[iParentPatch];
  iChildPatch[0] = (int)this;
  iChildPatch[1] = (int)v3;
  if ( v3 == nullptr || v3->winding->numpoints != 3 )
    return;
  m_flSampleHeight = this->m_flSampleHeight;
  if ( this->m_flSampleWidth > m_flSampleHeight )
    m_flSampleHeight = this->m_flSampleWidth;
  p_x = &v3->winding->p->x;
  v6 = p_x[3] - *p_x;
  v7 = p_x[5] - p_x[2];
  v8 = p_x[7] - p_x[1];
  v9 = p_x[7] - p_x[4];
  v10 = p_x[8] - p_x[5];
  v11 = dispchop * m_flSampleHeight;
  v12 = p_x[8] - p_x[2];
  *(float *)v53 = p_x[6] - *p_x;
  x_low = v53[0];
  v13 = p_x[6] - p_x[3];
  v57 = v11;
  v14 = p_x[4] - p_x[1];
  x = v13;
  v15 = -1;
  vecEdges[2].x = v6;
  vecEdges[2].y = v14;
  vecEdges[2].z = v7;
  y = v8;
  v49 = v12;
  v51 = v9;
  v52 = v10;
  flArea = 0.0;
  v16 = 0;
  p_y = &vecEdges[2].y;
  do
  {
    v19 = 0;
    v18 = flArea;
    *(float *)&v19 = fsqrt((float)((float)(*(p_y - 1) * *(p_y - 1)) + (float)(p_y[1] * p_y[1])) + (float)(*p_y * *p_y));
    nChildIndices = v19;
    if ( *(float *)&v19 > flArea )
    {
      nChildIndices = v19;
      v18 = *(float *)&v19;
      flArea = *(float *)&v19;
      v15 = v16;
    }
    ++v16;
    p_y += 3;
  }
  while ( v16 < 3 );
  if ( v57 > v18 )
    return;
  v57 = (float)(v57 * v57) * 0.5;
  *((float *)&nChildIndices + 1) = (float)(v8 * v7) - (float)(v12 * v14);
  *((float *)&nChildIndices + 2) = (float)(v12 * v6) - (float)(v7 * *(float *)v53);
  *((float *)&nChildIndices + 3) = (float)(v14 * *(float *)v53) - (float)(v8 * v6);
  v20 = VectorNormalize(vec: (Vector *)((char *)&nChildIndices + 4));
  if ( v57 > v20 * 0.5 )
    return;
  switch ( v15 )
  {
    case 0:
      p = v3->winding->p;
      v32 = p[1].y + p->y;
      v33 = p[1].z + p->z;
      v45[0] = LODWORD(p->x);
      v45[1] = LODWORD(p->y);
      v45[2] = LODWORD(p->z);
      vecEdges[0].x = (float)(p->x + p[1].x) * 0.5;
      vecEdges[1].x = p[2].x;
      vecEdges[1].y = p[2].y;
      z = p[2].z;
      vecEdges[0].y = v32 * 0.5;
      v25 = p[1].y + p->y;
      vecEdges[0].z = v33 * 0.5;
      v26 = p[1].z + p->z;
      vecEdges[1].z = z;
      v24 = p->x + p[1].x;
      goto LABEL_17;
    case 1:
      v27 = v3->winding->p;
      v45[0] = LODWORD(v27->x);
      v45[1] = LODWORD(v27->y);
      v45[2] = LODWORD(v27->z);
      v28 = v27[2].y + v27[1].y;
      v29 = v27[2].z + v27[1].z;
      vecEdges[0] = v27[1];
      vecEdges[1].x = (float)(v27[2].x + v27[1].x) * 0.5;
      vecEdges[2].x = (float)(v27[1].x + v27[2].x) * 0.5;
      x_low = LODWORD(v27[2].x);
      y = v27[2].y;
      v49 = v27[2].z;
      x = v27->x;
      v30 = v27->y;
      vecEdges[1].y = v28 * 0.5;
      v25 = v27[1].y + v27[2].y;
      vecEdges[1].z = v29 * 0.5;
      v26 = v27[1].z + v27[2].z;
      v51 = v30;
      v31 = v27->z;
LABEL_18:
      vecEdges[2].y = v25 * 0.5;
      vecEdges[2].z = v26 * 0.5;
      v52 = v31;
      break;
    case 2:
      p = v3->winding->p;
      v22 = p[2].y + p->y;
      v23 = p[2].z + p->z;
      v45[0] = LODWORD(p->x);
      v45[1] = LODWORD(p->y);
      v45[2] = LODWORD(p->z);
      vecEdges[0] = p[1];
      vecEdges[1].x = (float)(p[2].x + p->x) * 0.5;
      v24 = p[2].x + p->x;
      vecEdges[1].y = v22 * 0.5;
      v25 = p->y + p[2].y;
      vecEdges[1].z = v23 * 0.5;
      v26 = p->z + p[2].z;
LABEL_17:
      vecEdges[2].x = v24 * 0.5;
      x_low = LODWORD(p[1].x);
      y = p[1].y;
      v49 = p[1].z;
      x = p[2].x;
      v51 = p[2].y;
      v31 = p[2].z;
      goto LABEL_18;
    default:
      break;
  }
  memset(v53, 255, sizeof(v53));
  flArea = COERCE_FLOAT(v45);
  m_Size = g_Patches.m_Size;
  vecNormal.z = 0.0;
  v56 = 0;
  v36 = 0;
  while ( 1 )
  {
    v37 = m_Size;
    if ( m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPatch,int>::Grow(this: &g_Patches.m_Memory, num: m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Patches.m_Size;
    }
    g_Patches.m_Size = m_Size + 1;
    v38 = m_Size - v37;
    g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
    if ( v38 > 0 )
      _V_memmove(
        dest: &g_Patches.m_Memory.m_pMemory[v37 + 1],
        src: &g_Patches.m_Memory.m_pMemory[v37],
        count: 264 * v38);
    v39 = (CVRADDispColl *)iChildPatch[0];
    v44 = (Vector *)LODWORD(flArea);
    *((_DWORD *)&vecNormal.z + v36) = v37;
    v57 = 0.0;
    if ( CVRADDispColl::InitPatch(
           this: v39,
           iPatch: v37,
           iParentPatch,
           iChild: v36,
           pPoints: v44,
           pIndices: v53,
           flArea: &v57) == 0 )
      break;
    m_Size = g_Patches.m_Size;
LABEL_32:
    LODWORD(flArea) += 36;
    if ( ++v36 >= 2 )
      goto LABEL_37;
  }
  if ( v36 != 0 )
  {
    v40 = iChildPatch[1];
    *(_DWORD *)(iChildPatch[1] + 228) = -1;
    *(_DWORD *)(v40 + 232) = -1;
    v41 = g_Patches.m_Size;
    if ( g_Patches.m_Size - v37 - 1 > 0 )
    {
      _V_memmove(
        dest: &g_Patches.m_Memory.m_pMemory[v37],
        src: &g_Patches.m_Memory.m_pMemory[v37 + 1],
        count: 264 * (g_Patches.m_Size - v37 - 1));
      v41 = g_Patches.m_Size;
    }
    v42 = v41 - 1;
    g_Patches.m_Size = v42;
    if ( v42 - LODWORD(vecNormal.z) - 1 > 0 )
    {
      _V_memmove(
        dest: &g_Patches.m_Memory.m_pMemory[LODWORD(vecNormal.z)],
        src: &g_Patches.m_Memory.m_pMemory[LODWORD(vecNormal.z) + 1],
        count: 264 * (v42 - LODWORD(vecNormal.z) - 1));
      v42 = g_Patches.m_Size;
    }
    m_Size = v42 - 1;
    g_Patches.m_Size = m_Size;
    goto LABEL_32;
  }
  *(_DWORD *)(iChildPatch[1] + 228) = -1;
  if ( g_Patches.m_Size - v37 - 1 > 0 )
    _V_memmove(
      dest: &g_Patches.m_Memory.m_pMemory[v37],
      src: &g_Patches.m_Memory.m_pMemory[v37 + 1],
      count: 264 * (g_Patches.m_Size - v37 - 1));
  --g_Patches.m_Size;
LABEL_37:
  v43 = (CVRADDispColl *)iChildPatch[0];
  CVRADDispColl::CreateChildPatchesSub(this: (CVRADDispColl *)iChildPatch[0], iParentPatch: SLODWORD(vecNormal.z));
  CVRADDispColl::CreateChildPatchesSub(this: v43, iParentPatch: v56);
}

//------------------------------------------------------------------------------
// Address: 0x10023F90
// Name: public: virtual bool CVRADDispColl::Create(class CCoreDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRADDispColl::Create(CVRADDispColl *this, CCoreDispInfo *pDisp)
{
  char result; // al
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edx
  Vector *v8; // eax
  CoreDispVert_t *m_pVerts; // ecx
  int p_m_Normal; // ecx
  CoreDispVert_t *v11; // ecx
  Vector2D *m_pMemory; // eax
  Vector2D *v13; // eax
  dface_t *v14; // eax
  texinfo_s *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  int v19; // [esp-4h] [ebp-10h]
  float v20; // [esp-4h] [ebp-10h]

  result = CDispCollTree::Create(this, pDisp);
  if ( result != 0 )
  {
    v4 = 1 << this->m_nPower;
    this->m_aLuxelCoords.m_Size = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
      this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&this->m_aLuxelCoords,
      elem: 0,
      num: (v4 + 1) * (v4 + 1));
    v5 = 1 << this->m_nPower;
    this->m_aVertNormals.m_Size = 0;
    CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
      this: &this->m_aVertNormals,
      elem: 0,
      num: (v5 + 1) * (v5 + 1));
    v6 = 0;
    v7 = 0;
    this->m_iParent = pDisp->m_Surf.m_Index;
    if ( this->m_aVerts.m_Size > 0 )
    {
      v19 = 0;
      do
      {
        v8 = &this->m_aVertNormals.m_Memory.m_pMemory[v19];
        m_pVerts = pDisp->m_pVerts;
        ++v19;
        v8->x = m_pVerts[v6].m_Normal.x;
        p_m_Normal = (int)&m_pVerts[v6].m_Normal;
        v8->y = *(float *)(p_m_Normal + 4);
        v8->z = *(float *)(p_m_Normal + 8);
        v11 = pDisp->m_pVerts;
        m_pMemory = this->m_aLuxelCoords.m_Memory.m_pMemory;
        m_pMemory[v7].x = v11[v6].m_LuxelCoords[0].x;
        v13 = &m_pMemory[v7++];
        v13->y = v11[v6++].m_LuxelCoords[0].y;
      }
      while ( v7 < this->m_aVerts.m_Size );
    }
    v14 = &g_pFaces[this->m_iParent];
    if ( v14 != nullptr )
    {
      v15 = &texinfo.m_Memory.m_pMemory[v14->texinfo];
      if ( v15 != nullptr )
      {
        v16 = 1.0
            / fsqrt(
                (float)((float)(v15->lightmapVecsLuxelsPerWorldUnits[0][1] * v15->lightmapVecsLuxelsPerWorldUnits[0][1])
                      + (float)(v15->lightmapVecsLuxelsPerWorldUnits[0][0] * v15->lightmapVecsLuxelsPerWorldUnits[0][0]))
              + (float)(v15->lightmapVecsLuxelsPerWorldUnits[0][2] * v15->lightmapVecsLuxelsPerWorldUnits[0][2]));
        this->m_flSampleWidth = v16;
        this->m_flSampleHeight = v16;
        v17 = fsqrt((float)(v16 * v16) * 2.0) * 2.2;
        if ( v17 > g_flMaxDispSampleSize )
          v17 = g_flMaxDispSampleSize;
        this->m_flSampleRadius2 = v17 * v17;
        v18 = (float)(dispchop * v16) * 2.2;
        if ( v18 > g_MaxDispPatchRadius )
        {
          v20 = g_MaxDispPatchRadius;
          _Warning(a1: "Patch Sample Radius Clamped!\n");
          v18 = v20;
        }
        this->m_flPatchSampleRadius2 = v18 * v18;
      }
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024190
// Name: public: void CVRADDispColl::CreateChildPatches(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVRADDispColl::CreateChildPatches(
        CVRADDispColl *this@<ecx>,
        int a2@<ebp>,
        int iParentPatch,
        int nLevel)
{
  CPatch *v4; // edi
  int numpoints; // ecx
  CPatch *v7; // edi
  float m_flSampleHeight; // xmm1_4
  float *p_x; // eax
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  unsigned int v13; // xmm6_4
  int v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  unsigned int v17; // xmm5_4
  float v18; // xmm0_4
  float *v19; // eax
  int i; // ecx
  float v21; // xmm6_4
  __int128 v22; // xmm5
  double v23; // st7
  unsigned int v24; // esi
  int v25; // kr00_4
  unsigned int v26; // edx
  unsigned int v27; // edi
  Vector *m_pMemory; // ecx
  Vector *v29; // eax
  float z; // xmm0_4
  int m_Size; // eax
  int v32; // edi
  int v33; // esi
  int v34; // eax
  CVRADDispColl *v35; // ecx
  CPatch *v36; // eax
  int v37; // eax
  int v38; // eax
  CVRADDispColl *v39; // edi
  Vector *v40; // [esp-20h] [ebp-C8h]
  int *v41; // [esp-1Ch] [ebp-C4h]
  Vector v42; // [esp-Ch] [ebp-B4h] BYREF
  _BYTE vecChildPoints[76]; // [esp+0h] [ebp-A8h] OVERLAPPED BYREF
  float v44; // [esp+58h] [ebp-50h]
  _DWORD v45[2]; // [esp+5Ch] [ebp-4Ch] BYREF
  int nChildIndices[2][3]; // [esp+64h] [ebp-44h] BYREF
  float v47; // [esp+7Ch] [ebp-2Ch] BYREF
  CPatch *v48; // [esp+80h] [ebp-28h]
  unsigned int v49; // [esp+84h] [ebp-24h]
  int flArea; // [esp+88h] [ebp-20h] BYREF
  CPatch *pParentPatch; // [esp+8Ch] [ebp-1Ch]
  CVRADDispColl *v52; // [esp+90h] [ebp-18h]
  int iChildPatch[2]; // [esp+94h] [ebp-14h]
  _DWORD v54[2]; // [esp+9Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+A8h] [ebp+0h]

  v54[0] = a2;
  v54[1] = retaddr;
  v4 = &g_Patches.m_Memory.m_pMemory[iParentPatch];
  v52 = this;
  v48 = v4;
  if ( v4 == nullptr )
    return;
  numpoints = v4->winding->numpoints;
  if ( numpoints == 4 )
  {
    CVRADDispColl::CreateChildPatchesFromRoot(this, a2: COERCE_FLOAT(v54), iParentPatch, pChildPatch: &flArea);
    if ( flArea != -1 )
    {
      v7 = pParentPatch;
      if ( pParentPatch != (CPatch *)-1 )
      {
        CVRADDispColl::CreateChildPatches(this, iParentPatch: flArea, nLevel: 0);
        CVRADDispColl::CreateChildPatches(this, iParentPatch: (int)v7, nLevel: 0);
      }
    }
    return;
  }
  if ( numpoints == 3 )
  {
    m_flSampleHeight = this->m_flSampleHeight;
    if ( this->m_flSampleWidth > m_flSampleHeight )
      m_flSampleHeight = this->m_flSampleWidth;
    p_x = &v4->winding->p->x;
    v10 = p_x[3] - *p_x;
    v11 = p_x[5] - p_x[2];
    v12 = p_x[7] - p_x[1];
    *(float *)&v13 = p_x[7] - p_x[4];
    *(float *)&v14 = p_x[8] - p_x[5];
    v15 = dispchop * m_flSampleHeight;
    v16 = p_x[8] - p_x[2];
    *(float *)&v49 = p_x[6] - *p_x;
    *(_QWORD *)&nChildIndices[0][0] = __PAIR64__(LODWORD(v12), v49);
    *(float *)&v17 = p_x[6] - p_x[3];
    *(float *)iChildPatch = v15;
    v18 = p_x[4] - p_x[1];
    *(_QWORD *)&nChildIndices[1][0] = __PAIR64__(v13, v17);
    v44 = v10;
    *(float *)v45 = v18;
    *(float *)&v45[1] = v11;
    *(float *)&nChildIndices[0][2] = v16;
    nChildIndices[1][2] = v14;
    iChildPatch[1] = 0;
    v19 = (float *)v45;
    for ( i = 3; i != 0; --i )
    {
      v22 = 0;
      v21 = *(float *)&iChildPatch[1];
      *(float *)&v22 = fsqrt((float)((float)(*(v19 - 1) * *(v19 - 1)) + (float)(v19[1] * v19[1])) + (float)(*v19 * *v19));
      *(_OWORD *)&vecChildPoints[60] = v22;
      if ( *(float *)&v22 > *(float *)&iChildPatch[1] )
      {
        *(_OWORD *)&vecChildPoints[60] = v22;
        v21 = *(float *)&v22;
        iChildPatch[1] = v22;
      }
      v19 += 3;
    }
    if ( *(float *)iChildPatch <= v21 )
    {
      *(float *)&iChildPatch[1] = (float)(*(float *)iChildPatch * *(float *)iChildPatch) * 0.5;
      *(float *)&vecChildPoints[64] = (float)(v12 * v11) - (float)(v16 * v18);
      *(float *)&vecChildPoints[68] = (float)(v16 * v10) - (float)(v11 * *(float *)&v49);
      *(float *)&vecChildPoints[72] = (float)(v18 * *(float *)&v49) - (float)(v12 * v10);
      v23 = VectorNormalize(vec: (Vector *)&vecChildPoints[64]);
      if ( *(float *)&iChildPatch[1] <= v23 * 0.5 )
      {
        if ( nLevel >= 2 * this->m_nPower )
        {
          CVRADDispColl::CreateChildPatchesSub(this, a2: (int)v54, iParentPatch);
          return;
        }
        v24 = v4->indices[0];
        v25 = v24 + v4->indices[1];
        v26 = v4->indices[2];
        v27 = v4->indices[1];
        m_pMemory = v52->m_aVerts.m_Memory.m_pMemory;
        *(_QWORD *)&nChildIndices[0][0] = __PAIR64__(v24, v26);
        v42 = m_pMemory[v26];
        *(Vector *)vecChildPoints = m_pMemory[v24];
        nChildIndices[0][2] = v25 / 2;
        nChildIndices[1][2] = v25 / 2;
        v29 = &m_pMemory[v25 / 2];
        *(_QWORD *)&vecChildPoints[12] = *(_QWORD *)&v29->x;
        *(float *)&vecChildPoints[20] = v29->z;
        *(Vector *)&vecChildPoints[24] = m_pMemory[v27];
        *(Vector *)&vecChildPoints[36] = m_pMemory[v26];
        *(_QWORD *)&vecChildPoints[48] = *(_QWORD *)&v29->x;
        z = v29->z;
        flArea = -1;
        pParentPatch = (CPatch *)-1;
        *(_QWORD *)&nChildIndices[1][0] = __PAIR64__(v26, v27);
        iChildPatch[1] = (int)&v42;
        m_Size = g_Patches.m_Size;
        *(float *)&vecChildPoints[56] = z;
        v32 = 0;
        iChildPatch[0] = (int)nChildIndices;
        while ( 1 )
        {
          v33 = m_Size;
          if ( m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CPatch,int>::Grow(
              this: &g_Patches.m_Memory,
              num: m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
            m_Size = g_Patches.m_Size;
          }
          g_Patches.m_Size = m_Size + 1;
          v34 = m_Size - v33;
          g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
          if ( v34 > 0 )
            _V_memmove(
              dest: &g_Patches.m_Memory.m_pMemory[v33 + 1],
              src: &g_Patches.m_Memory.m_pMemory[v33],
              count: 264 * v34);
          v41 = (int *)iChildPatch[0];
          v35 = v52;
          v40 = (Vector *)iChildPatch[1];
          *(&flArea + v32) = v33;
          v47 = 0.0;
          if ( CVRADDispColl::InitPatch(
                 this: v35,
                 iPatch: v33,
                 iParentPatch,
                 iChild: v32,
                 pPoints: v40,
                 pIndices: v41,
                 flArea: &v47) != 0 )
          {
            m_Size = g_Patches.m_Size;
          }
          else
          {
            if ( v32 == 0 )
            {
              v48->child1 = -1;
              if ( g_Patches.m_Size - v33 - 1 > 0 )
                _V_memmove(
                  dest: &g_Patches.m_Memory.m_pMemory[v33],
                  src: &g_Patches.m_Memory.m_pMemory[v33 + 1],
                  count: 264 * (g_Patches.m_Size - v33 - 1));
              --g_Patches.m_Size;
LABEL_35:
              v39 = v52;
              CVRADDispColl::CreateChildPatches(this: v52, iParentPatch: flArea, nLevel: nLevel + 1);
              CVRADDispColl::CreateChildPatches(this: v39, iParentPatch: (int)pParentPatch, nLevel: nLevel + 1);
              return;
            }
            v36 = v48;
            v48->child1 = -1;
            v36->child2 = -1;
            v37 = g_Patches.m_Size;
            if ( g_Patches.m_Size - v33 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_Patches.m_Memory.m_pMemory[v33],
                src: &g_Patches.m_Memory.m_pMemory[v33 + 1],
                count: 264 * (g_Patches.m_Size - v33 - 1));
              v37 = g_Patches.m_Size;
            }
            v38 = v37 - 1;
            g_Patches.m_Size = v38;
            if ( v38 - flArea - 1 > 0 )
            {
              _V_memmove(
                dest: &g_Patches.m_Memory.m_pMemory[flArea],
                src: &g_Patches.m_Memory.m_pMemory[flArea + 1],
                count: 264 * (v38 - flArea - 1));
              v38 = g_Patches.m_Size;
            }
            m_Size = v38 - 1;
            g_Patches.m_Size = m_Size;
          }
          iChildPatch[0] += 12;
          iChildPatch[1] += 36;
          if ( ++v32 >= 2 )
            goto LABEL_35;
        }
      }
    }
  }
}
