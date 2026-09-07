// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/overlay.cpp
// Functions: 35
// ============================================================

#include "engine\overlay.h"

//------------------------------------------------------------------------------
// Address: 0x100F5290
// Name: class IOverlayMgr __near * OverlayMgr(void)
// Source: json
//------------------------------------------------------------------------------
COverlayMgr *__cdecl OverlayMgr()
{
  return &g_OverlayMgr;
}

//------------------------------------------------------------------------------
// Address: 0x100F52A0
// Name: public: virtual void COverlayMgr::UpdateOverlayRenderLevels(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::UpdateOverlayRenderLevels(COverlayMgr *this, int nCPULevel, int nGPULevel)
{
  this->m_nCPULevel = nCPULevel;
  this->m_nGPULevel = nGPULevel;
}

//------------------------------------------------------------------------------
// Address: 0x100F52C0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: m_pMemory,
                                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5410
// Name: public: void CIndexBuilder::FastPolygonList(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastPolygonList(CIndexBuilder *this, int startVert, int *pVertexCount, int polygonCount)
{
  unsigned __int16 *v4; // eax
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // esi
  int m_nCurrentIndex; // eax
  CIndexBuilder *v11; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]
  int indexOut; // [esp+1Ch] [ebp+8h]
  int polygonCounta; // [esp+24h] [ebp+10h]

  v4 = &this->m_pIndices[this->m_nCurrentIndex];
  v5 = this->m_nIndexOffset + startVert;
  v6 = 0;
  v11 = this;
  indexOut = 0;
  polygonCounta = polygonCount * this->m_nIndexSize;
  i = 0;
  if ( polygonCounta > 0 )
  {
    do
    {
      v7 = pVertexCount[v6];
      v8 = v7 - 2;
      v9 = 0;
      if ( v7 - 2 > 0 )
      {
        do
        {
          *v4 = v5;
          v4[1] = v9 + v5 + 1;
          v4[2] = v9++ + v5 + 2;
          v4 += 3;
        }
        while ( v9 < v8 );
        v6 = i;
      }
      LOWORD(v5) = v7 + v5;
      ++v6;
      indexOut += v8 + 2 * v8;
      i = v6;
    }
    while ( v6 < polygonCounta );
    this = v11;
  }
  this->m_nCurrentIndex += indexOut * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100F54B0
// Name: void Overlay_TriTLToBR(class CDispInfo __near *,class CMeshReader __near *,class Vector __near &,class Vector __near &,float,float,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Overlay_TriTLToBR(
        int a1@<ebp>,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        float flU,
        float flV,
        int nWidth,
        const Vector *vecIntersectPoint)
{
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  float v13; // xmm2_4
  int v14; // eax
  int v15; // ecx
  float *v16; // edx
  int v17; // eax
  unsigned int k; // esi
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  int v24; // xmm3_4
  int v25; // xmm1_4
  Vector *v26; // eax
  _DWORD *v27; // edx
  double v28; // st7
  double v29; // st7
  int v30; // ecx
  float v31; // xmm3_4
  __int128 v32; // xmm0
  float v33; // xmm2_4
  __int128 v34; // xmm0
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm3_4
  __int128 v40; // xmm0
  float v41; // xmm2_4
  __int128 v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // eax
  float *v52; // edx
  unsigned int m; // esi
  int v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float *v58; // eax
  int v59; // xmm3_4
  int v60; // xmm1_4
  Vector *v61; // eax
  _DWORD *v62; // edx
  double v63; // st7
  double v64; // st7
  int v65; // ecx
  float v66; // xmm7_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float *m_pNormal; // edx
  int m_VertexSize_Normal; // eax
  unsigned int i; // esi
  int v79; // eax
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float *v83; // eax
  int v84; // xmm3_4
  int v85; // xmm1_4
  Vector *FlatVert; // eax
  _DWORD *v87; // edx
  double y; // st7
  double z; // st7
  int v90; // ecx
  float v91; // xmm3_4
  float x; // xmm4_4
  __int128 v93; // xmm1
  __int128 v94; // xmm1
  float v95; // xmm0_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  float v100; // xmm3_4
  float v101; // xmm4_4
  __int128 v102; // xmm0
  __int128 v103; // xmm0
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm5_4
  float v108; // xmm4_4
  float v109; // xmm3_4
  Vector *v110; // eax
  float v111; // xmm2_4
  float v112; // xmm5_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm4_4
  float v117; // xmm5_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm3_4
  float v121; // xmm4_4
  float v122; // xmm4_4
  float v123; // xmm5_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  float v126; // xmm0_4
  int v127; // eax
  float *v128; // edx
  unsigned int j; // esi
  int v130; // eax
  float v131; // xmm0_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float *v134; // eax
  int v135; // xmm3_4
  int v136; // xmm0_4
  int v137; // xmm1_4
  Vector *v138; // eax
  _DWORD *v139; // edx
  double v140; // st7
  double v141; // st7
  int v142; // ecx
  float v143; // xmm0_4
  float v144; // xmm1_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  float v147; // xmm4_4
  float v148; // xmm6_4
  float v149; // xmm0_4
  float v150; // xmm6_4
  float v151; // xmm4_4
  float v152; // xmm3_4
  int v153; // [esp-18h] [ebp-E0h]
  int v154; // [esp-18h] [ebp-E0h]
  int v155; // [esp-18h] [ebp-E0h]
  int v156; // [esp-18h] [ebp-E0h]
  int v157; // [esp-Ch] [ebp-D4h]
  int v158; // [esp-8h] [ebp-D0h]
  int v159; // [esp-8h] [ebp-D0h]
  int v160; // [esp-4h] [ebp-CCh]
  int v161; // [esp-4h] [ebp-CCh]
  int nSnapU; // [esp+0h] [ebp-C8h]
  int nSnapUa; // [esp+0h] [ebp-C8h]
  int v164; // [esp+4h] [ebp-C4h]
  float v165[2]; // [esp+8h] [ebp-C0h] BYREF
  int nNextU; // [esp+10h] [ebp-B8h]
  Vector vecFlatVerts[3]; // [esp+14h] [ebp-B4h] BYREF
  _BYTE flCfs[20]; // [esp+38h] [ebp-90h] OVERLAPPED BYREF
  int nIndices_4[3]; // [esp+50h] [ebp-78h] OVERLAPPED
  Vector vecVerts[3]; // [esp+5Ch] [ebp-6Ch]
  _BYTE vecNormals[44]; // [esp+80h] [ebp-48h] OVERLAPPED BYREF
  _BYTE *v172; // [esp+B8h] [ebp-10h]
  _DWORD v173[3]; // [esp+BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v173[0] = a1;
  v173[1] = retaddr;
  v9 = (int)flU;
  v10 = (int)flV;
  v11 = (int)flU + 1;
  v12 = (int)flV + 1;
  v157 = (int)flU;
  *(_DWORD *)&vecNormals[24] = (int)flV;
  v164 = v11;
  *(_DWORD *)flCfs = v12;
  if ( v11 == nWidth )
  {
    v11 = (int)flU;
    v164 = (int)flU;
  }
  if ( v12 == nWidth )
  {
    v12 = (int)flV;
    *(_DWORD *)flCfs = (int)flV;
  }
  v13 = (float)v10;
  v14 = nWidth * v10;
  if ( (float)((float)(flV - v13) + (float)(flU - (float)v9)) < 1.000001 )
  {
    *(_DWORD *)&vecNormals[32] = v14 + v9;
    v159 = nWidth * *(_DWORD *)flCfs;
    m_pNormal = pReader->m_pNormal;
    v161 = v9 + nWidth * *(_DWORD *)flCfs;
    *(_DWORD *)&vecNormals[36] = v161;
    nSnapUa = v11 + v14;
    *(_DWORD *)&vecNormals[40] = v11 + v14;
    m_VertexSize_Normal = pReader->m_VertexSize_Normal;
    v172 = &vecNormals[32];
    for ( i = 0; (int)i < 36; vecVerts[i / 0xC + 1].z = *(float *)((char *)m_pNormal + v90 + 8) )
    {
      v79 = *(_DWORD *)v172 * m_VertexSize_Normal;
      v80 = *(float *)((char *)m_pNormal + v79);
      v81 = *(float *)((char *)m_pNormal + v79 + 4);
      v82 = *(float *)((char *)m_pNormal + v79 + 8);
      v83 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
      *(float *)&v84 = v83[1] + (float)(v81 * 0.1);
      v155 = *(_DWORD *)v172;
      *(float *)&v85 = v83[2] + (float)(v82 * 0.1);
      *(float *)&nIndices_4[i / 4] = (float)(v80 * 0.1) + *v83;
      nIndices_4[i / 4 + 1] = v84;
      nIndices_4[i / 4 + 2] = v85;
      FlatVert = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&flCfs[8], iVertex: v155);
      v87 = v172;
      v165[i / 4] = FlatVert->x;
      y = FlatVert->y;
      v172 += 4;
      v165[i / 4 + 1] = y;
      i += 12;
      z = FlatVert->z;
      m_VertexSize_Normal = pReader->m_VertexSize_Normal;
      *(float *)&v173[i / 4 - 46] = z;
      v90 = *v87 * m_VertexSize_Normal;
      m_pNormal = pReader->m_pNormal;
      vecVerts[i / 0xC + 1].x = *(float *)((char *)m_pNormal + v90);
      vecVerts[i / 0xC + 1].y = *(float *)((char *)m_pNormal + v90 + 4);
    }
    if ( v157 == v164 )
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
        goto LABEL_10;
      v91 = vecVerts[0].z - *(float *)&nIndices_4[2];
      x = vecVerts[2].x;
      v93 = 0;
      *(float *)&v93 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->x - v165[0])
                                       * (float)(vecIntersectPoint->x - v165[0]))
                               + (float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1])))
                       + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                               * (float)(vecIntersectPoint->z - *(float *)&nNextU)));
      *(_OWORD *)&vecNormals[28] = v93;
      v94 = 0;
      *(float *)&v94 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[0].x - v165[0]) * (float)(vecFlatVerts[0].x - v165[0]))
                               + (float)((float)(vecFlatVerts[0].y - v165[1]) * (float)(vecFlatVerts[0].y - v165[1])))
                       + (float)((float)(vecFlatVerts[0].z - *(float *)&nNextU)
                               * (float)(vecFlatVerts[0].z - *(float *)&nNextU)));
      *(_OWORD *)&flCfs[4] = v94;
      v95 = *(float *)&vecNormals[28] / *(float *)&v94;
      *(float *)&v94 = vecVerts[0].x - *(float *)nIndices_4;
      vecWorld->y = (float)((float)(vecVerts[0].y - *(float *)&nIndices_4[1]) * v95) + *(float *)&nIndices_4[1];
      v96 = *(float *)&vecNormals[4] - vecVerts[2].y;
      vecWorld->z = (float)(v91 * v95) + *(float *)&nIndices_4[2];
      v97 = *(float *)&vecNormals[8] - vecVerts[2].z;
      vecWorld->x = (float)(*(float *)&v94 * v95) + *(float *)nIndices_4;
      v98 = (float)(v96 * v95) + vecVerts[2].y;
      v99 = (float)(v97 * v95) + vecVerts[2].z;
      vecWorldNormal->x = x + (float)((float)(*(float *)vecNormals - x) * v95);
      vecWorldNormal->y = v98;
      vecWorldNormal->z = v99;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
      {
        v100 = *(float *)nIndices_4;
        v101 = vecVerts[1].x;
        v102 = 0;
        *(float *)&v102 = fsqrt(
                            (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                          * (float)(vecIntersectPoint->y - v165[1]))
                                  + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                          * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                          + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
        *(_OWORD *)&vecNormals[28] = v102;
        v103 = 0;
        *(float *)&v103 = fsqrt(
                            (float)((float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1]))
                                  + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                                          * (float)(vecFlatVerts[1].z - *(float *)&nNextU)))
                          + (float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0])));
        *(_OWORD *)&flCfs[4] = v103;
        *(float *)&v103 = *(float *)&vecNormals[28] / *(float *)&v103;
        v104 = (float)((float)(vecVerts[1].z - *(float *)&nIndices_4[2])
                     * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
             + *(float *)&nIndices_4[2];
        vecWorld->y = (float)((float)(vecVerts[1].y - *(float *)&nIndices_4[1])
                            * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
                    + *(float *)&nIndices_4[1];
        v105 = *(float *)&vecNormals[16] - vecVerts[2].y;
        vecWorld->z = v104;
        v106 = *(float *)&vecNormals[20] - vecVerts[2].z;
        v107 = *(float *)&v103 * (float)(v101 - v100);
        v108 = *(float *)&vecNormals[12];
        vecWorld->x = v100 + v107;
        v109 = vecVerts[2].x;
        v110 = vecWorldNormal;
        v111 = (float)(v106 * *(float *)&v103) + vecVerts[2].z;
        v112 = *(float *)&v103 * (float)(v108 - vecVerts[2].x);
        vecWorldNormal->y = (float)(v105 * *(float *)&v103) + vecVerts[2].y;
      }
      else
      {
        if ( CalcBarycentricCooefs(
               v0: (const Vector *)v165,
               v1: vecFlatVerts,
               v2: &vecFlatVerts[1],
               pt: vecIntersectPoint,
               c0: (float *)&flCfs[8],
               c1: (float *)&flCfs[12],
               c2: (float *)&flCfs[16]) )
        {
          v113 = *(float *)&flCfs[16];
          v114 = *(float *)&flCfs[12];
          vecFlatVerts[2].y = vecVerts[1].y * *(float *)&flCfs[16];
          vecFlatVerts[2].z = vecVerts[1].z * *(float *)&flCfs[16];
          *(float *)&vecNormals[36] = vecVerts[0].y * *(float *)&flCfs[12];
          v115 = *(float *)&flCfs[8];
          v116 = (float)((float)(*(float *)&flCfs[8] * *(float *)&nIndices_4[1])
                       + (float)(vecVerts[0].y * *(float *)&flCfs[12]))
               + (float)(vecVerts[1].y * *(float *)&flCfs[16]);
          v117 = (float)((float)(*(float *)&flCfs[8] * *(float *)&nIndices_4[2])
                       + (float)(vecVerts[0].z * *(float *)&flCfs[12]))
               + (float)(vecVerts[1].z * *(float *)&flCfs[16]);
          v118 = *(float *)&vecNormals[4];
          v119 = *(float *)vecNormals;
          vecWorld->x = (float)((float)(*(float *)nIndices_4 * *(float *)&flCfs[8])
                              + (float)(vecVerts[0].x * *(float *)&flCfs[12]))
                      + (float)(vecVerts[1].x * *(float *)&flCfs[16]);
          v120 = *(float *)&vecNormals[12];
          vecWorld->y = v116;
          v121 = *(float *)&vecNormals[16];
          vecWorld->z = v117;
          v122 = v121 * v113;
          v123 = *(float *)&vecNormals[20] * v113;
          *(float *)&vecNormals[40] = *(float *)&vecNormals[8] * v114;
          v124 = (float)((float)(vecVerts[2].x * v115) + (float)(v119 * v114)) + (float)(v120 * v113);
          v125 = (float)((float)(v115 * vecVerts[2].y) + (float)(v118 * v114)) + v122;
          v126 = (float)((float)(v115 * vecVerts[2].z) + *(float *)&vecNormals[40]) + v123;
          vecWorldNormal->x = v124;
          vecWorldNormal->y = v125;
          vecWorldNormal->z = v126;
          VectorNormalize(vec: vecWorldNormal);
          return;
        }
        *(_DWORD *)&vecNormals[36] = v164 + v159;
        *(_DWORD *)&vecNormals[32] = v161;
        v127 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecNormals[40] = nSnapUa;
        v128 = pReader->m_pNormal;
        *(_DWORD *)&vecNormals[24] = &vecNormals[32];
        for ( j = 0; (int)j < 36; vecVerts[j / 0xC + 1].z = *(float *)((char *)v128 + v142 + 8) )
        {
          v130 = **(_DWORD **)&vecNormals[24] * v127;
          v131 = *(float *)((char *)v128 + v130);
          v132 = *(float *)((char *)v128 + v130 + 4);
          v133 = *(float *)((char *)v128 + v130 + 8);
          v134 = (float *)((char *)pReader->m_pPosition + **(_DWORD **)&vecNormals[24] * pReader->m_VertexSize_Position);
          *(float *)&v135 = *v134 + (float)(v131 * 0.1);
          *(float *)&v136 = v134[1] + (float)(v132 * 0.1);
          v156 = **(_DWORD **)&vecNormals[24];
          *(float *)&v137 = v134[2] + (float)(v133 * 0.1);
          nIndices_4[j / 4] = v135;
          nIndices_4[j / 4 + 1] = v136;
          nIndices_4[j / 4 + 2] = v137;
          v138 = CDispInfo::GetFlatVert(this: pDisp, result: &vecFlatVerts[2], iVertex: v156);
          v139 = *(_DWORD **)&vecNormals[24];
          v165[j / 4] = v138->x;
          v140 = v138->y;
          *(_DWORD *)&vecNormals[24] += 4;
          v165[j / 4 + 1] = v140;
          j += 12;
          v141 = v138->z;
          v127 = pReader->m_VertexSize_Normal;
          *(float *)&v173[j / 4 - 46] = v141;
          v142 = *v139 * v127;
          v128 = pReader->m_pNormal;
          vecVerts[j / 0xC + 1].x = *(float *)((char *)v128 + v142);
          vecVerts[j / 0xC + 1].y = *(float *)((char *)v128 + v142 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)v165,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: &vecFlatVerts[2].x,
          c1: &vecFlatVerts[2].y,
          c2: &vecFlatVerts[2].z);
        v143 = vecFlatVerts[2].z;
        *(float *)&flCfs[12] = vecFlatVerts[2].z * vecVerts[1].y;
        *(float *)&flCfs[16] = vecFlatVerts[2].z * vecVerts[1].z;
        v144 = vecFlatVerts[2].y;
        *(float *)&vecNormals[36] = vecFlatVerts[2].y * vecVerts[0].y;
        v145 = vecFlatVerts[2].x;
        v146 = (float)((float)(*(float *)nIndices_4 * vecFlatVerts[2].x) + (float)(vecFlatVerts[2].y * vecVerts[0].x))
             + (float)(vecFlatVerts[2].z * vecVerts[1].x);
        v147 = (float)((float)(vecFlatVerts[2].x * *(float *)&nIndices_4[1]) + (float)(vecFlatVerts[2].y * vecVerts[0].y))
             + (float)(vecFlatVerts[2].z * vecVerts[1].y);
        vecWorld->z = (float)((float)(vecFlatVerts[2].x * *(float *)&nIndices_4[2])
                            + (float)(vecFlatVerts[2].y * vecVerts[0].z))
                    + (float)(vecFlatVerts[2].z * vecVerts[1].z);
        vecWorld->y = v147;
        v112 = v143 * *(float *)&vecNormals[12];
        v148 = v143;
        v149 = v143 * *(float *)&vecNormals[20];
        v150 = v148 * *(float *)&vecNormals[16];
        vecWorld->x = v146;
        v110 = vecWorldNormal;
        *(float *)&vecNormals[40] = v149;
        v151 = v145 * vecVerts[2].y;
        v152 = vecVerts[2].x * v145;
        v111 = (float)((float)(v145 * vecVerts[2].z) + (float)(v144 * *(float *)&vecNormals[8])) + v149;
        v109 = v152 + (float)(v144 * *(float *)vecNormals);
        vecWorldNormal->y = (float)(v151 + (float)(v144 * *(float *)&vecNormals[4])) + v150;
      }
      v110->z = v111;
      v110->x = v109 + v112;
      VectorNormalize(vec: v110);
    }
  }
  else
  {
    v15 = nWidth * v12;
    v158 = v14;
    v160 = v15 + v9;
    *(_DWORD *)&flCfs[8] = v15 + v9;
    v16 = pReader->m_pNormal;
    *(_DWORD *)&flCfs[12] = v11 + v15;
    nSnapU = v11 + v14;
    *(_DWORD *)&flCfs[16] = v11 + v14;
    v17 = pReader->m_VertexSize_Normal;
    v172 = &flCfs[8];
    for ( k = 0; (int)k < 36; vecVerts[k / 0xC + 1].z = *(float *)((char *)v16 + v30 + 8) )
    {
      v19 = *(_DWORD *)v172 * v17;
      v20 = *(float *)((char *)v16 + v19);
      v21 = *(float *)((char *)v16 + v19 + 4);
      v22 = *(float *)((char *)v16 + v19 + 8);
      v23 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
      *(float *)&v24 = v23[1] + (float)(v21 * 0.1);
      v153 = *(_DWORD *)v172;
      *(float *)&v25 = v23[2] + (float)(v22 * 0.1);
      *(float *)&nIndices_4[k / 4] = (float)(v20 * 0.1) + *v23;
      nIndices_4[k / 4 + 1] = v24;
      nIndices_4[k / 4 + 2] = v25;
      v26 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecNormals[32], iVertex: v153);
      v27 = v172;
      v165[k / 4] = v26->x;
      v28 = v26->y;
      v172 += 4;
      v165[k / 4 + 1] = v28;
      k += 12;
      v29 = v26->z;
      v17 = pReader->m_VertexSize_Normal;
      *(float *)&v173[k / 4 - 46] = v29;
      v30 = *v27 * v17;
      v16 = pReader->m_pNormal;
      vecVerts[k / 0xC + 1].x = *(float *)((char *)v16 + v30);
      vecVerts[k / 0xC + 1].y = *(float *)((char *)v16 + v30 + 4);
    }
    if ( v157 == v164 )
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
      {
LABEL_10:
        *vecWorld = *(Vector *)nIndices_4;
        *vecWorldNormal = vecVerts[2];
        VectorNormalize(vec: vecWorldNormal);
        return;
      }
      v31 = vecVerts[1].z - *(float *)&nIndices_4[2];
      v32 = 0;
      *(float *)&v32 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1]))
                               + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                       * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                       + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
      *(_OWORD *)&vecNormals[28] = v32;
      v33 = vecVerts[1].y - *(float *)&nIndices_4[1];
      v34 = 0;
      *(float *)&v34 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1]))
                               + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                                       * (float)(vecFlatVerts[1].z - *(float *)&nNextU)))
                       + (float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0])));
      *(_OWORD *)&flCfs[4] = v34;
      *(float *)&v34 = *(float *)&vecNormals[28] / *(float *)&v34;
      vecWorld->x = (float)((float)(vecVerts[1].x - *(float *)nIndices_4)
                          * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
                  + *(float *)nIndices_4;
      v35 = *(float *)&vecNormals[12] - vecVerts[2].x;
      vecWorld->y = (float)(v33 * *(float *)&v34) + *(float *)&nIndices_4[1];
      v36 = *(float *)&vecNormals[16] - vecVerts[2].y;
      vecWorld->z = (float)(v31 * *(float *)&v34) + *(float *)&nIndices_4[2];
      v37 = (float)(v36 * *(float *)&v34) + vecVerts[2].y;
      v38 = (float)((float)(*(float *)&vecNormals[20] - vecVerts[2].z) * *(float *)&v34) + vecVerts[2].z;
      vecWorldNormal->x = (float)(v35 * *(float *)&v34) + vecVerts[2].x;
      vecWorldNormal->y = v37;
      vecWorldNormal->z = v38;
      VectorNormalize(vec: vecWorldNormal);
    }
    else if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
    {
      v39 = vecVerts[1].z - *(float *)&nIndices_4[2];
      v40 = 0;
      *(float *)&v40 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1]))
                               + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                       * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                       + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
      *(_OWORD *)&vecNormals[28] = v40;
      v41 = vecVerts[1].y - *(float *)&nIndices_4[1];
      v42 = 0;
      *(float *)&v42 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0]))
                               + (float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1])))
                       + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                               * (float)(vecFlatVerts[1].z - *(float *)&nNextU)));
      *(_OWORD *)&flCfs[4] = v42;
      *(float *)&v40 = *(float *)&v40 / *(float *)&v42;
      vecWorld->x = (float)((float)(vecVerts[1].x - *(float *)nIndices_4) * *(float *)&v40) + *(float *)nIndices_4;
      *(float *)&v42 = *(float *)&vecNormals[12] - vecVerts[2].x;
      vecWorld->y = (float)(v41 * *(float *)&v40) + *(float *)&nIndices_4[1];
      v43 = *(float *)&vecNormals[16] - vecVerts[2].y;
      vecWorld->z = (float)(v39 * *(float *)&v40) + *(float *)&nIndices_4[2];
      v44 = (float)(v43 * *(float *)&v40) + vecVerts[2].y;
      v45 = (float)((float)(*(float *)&vecNormals[20] - vecVerts[2].z) * *(float *)&v40) + vecVerts[2].z;
      vecWorldNormal->x = (float)(*(float *)&v42 * *(float *)&v40) + vecVerts[2].x;
      vecWorldNormal->y = v44;
      vecWorldNormal->z = v45;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( CalcBarycentricCooefs(
             v0: (const Vector *)v165,
             v1: vecFlatVerts,
             v2: &vecFlatVerts[1],
             pt: vecIntersectPoint,
             c0: &vecFlatVerts[2].x,
             c1: &vecFlatVerts[2].y,
             c2: &vecFlatVerts[2].z) )
      {
        v46 = vecFlatVerts[2].z;
        *(float *)&vecNormals[36] = vecVerts[1].y * vecFlatVerts[2].z;
        *(float *)&vecNormals[40] = vecVerts[1].z * vecFlatVerts[2].z;
        v47 = vecFlatVerts[2].y;
        *(float *)&flCfs[12] = vecVerts[0].y * vecFlatVerts[2].y;
        *(float *)&flCfs[16] = vecVerts[0].z * vecFlatVerts[2].y;
        v48 = vecFlatVerts[2].x;
        v49 = (float)((float)(*(float *)&nIndices_4[1] * vecFlatVerts[2].x) + (float)(vecVerts[0].y * vecFlatVerts[2].y))
            + (float)(vecVerts[1].y * vecFlatVerts[2].z);
        v50 = (float)((float)(*(float *)&nIndices_4[2] * vecFlatVerts[2].x) + (float)(vecVerts[0].z * vecFlatVerts[2].y))
            + (float)(vecVerts[1].z * vecFlatVerts[2].z);
      }
      else
      {
        *(_DWORD *)&vecNormals[36] = v160;
        *(_DWORD *)&vecNormals[32] = v157 + v158;
        v51 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecNormals[40] = nSnapU;
        v52 = pReader->m_pNormal;
        v172 = &vecNormals[32];
        for ( m = 0; (int)m < 36; vecVerts[m / 0xC + 1].z = *(float *)((char *)v52 + v65 + 8) )
        {
          v54 = *(_DWORD *)v172 * v51;
          v55 = *(float *)((char *)v52 + v54);
          v56 = *(float *)((char *)v52 + v54 + 4);
          v57 = *(float *)((char *)v52 + v54 + 8);
          v58 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
          *(float *)&v59 = v58[1] + (float)(v56 * 0.1);
          v154 = *(_DWORD *)v172;
          *(float *)&v60 = v58[2] + (float)(v57 * 0.1);
          *(float *)&nIndices_4[m / 4] = (float)(v55 * 0.1) + *v58;
          nIndices_4[m / 4 + 1] = v59;
          nIndices_4[m / 4 + 2] = v60;
          v61 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&flCfs[8], iVertex: v154);
          v62 = v172;
          v165[m / 4] = v61->x;
          v63 = v61->y;
          v172 += 4;
          v165[m / 4 + 1] = v63;
          m += 12;
          v64 = v61->z;
          v51 = pReader->m_VertexSize_Normal;
          *(float *)&v173[m / 4 - 46] = v64;
          v65 = *v62 * v51;
          v52 = pReader->m_pNormal;
          vecVerts[m / 0xC + 1].x = *(float *)((char *)v52 + v65);
          vecVerts[m / 0xC + 1].y = *(float *)((char *)v52 + v65 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)v165,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: (float *)&flCfs[8],
          c1: (float *)&flCfs[12],
          c2: (float *)&flCfs[16]);
        v46 = *(float *)&flCfs[16];
        vecFlatVerts[2].y = vecVerts[1].y * *(float *)&flCfs[16];
        vecFlatVerts[2].z = vecVerts[1].z * *(float *)&flCfs[16];
        v47 = *(float *)&flCfs[12];
        *(float *)&vecNormals[36] = vecVerts[0].y * *(float *)&flCfs[12];
        *(float *)&vecNormals[40] = vecVerts[0].z * *(float *)&flCfs[12];
        v48 = *(float *)&flCfs[8];
        v49 = (float)((float)(*(float *)&nIndices_4[1] * *(float *)&flCfs[8])
                    + (float)(vecVerts[0].y * *(float *)&flCfs[12]))
            + (float)(vecVerts[1].y * *(float *)&flCfs[16]);
        v50 = (float)((float)(*(float *)&nIndices_4[2] * *(float *)&flCfs[8])
                    + (float)(vecVerts[0].z * *(float *)&flCfs[12]))
            + (float)(vecVerts[1].z * *(float *)&flCfs[16]);
      }
      v66 = *(float *)vecNormals;
      v67 = (float)((float)(*(float *)nIndices_4 * v48) + (float)(vecVerts[0].x * v47)) + (float)(vecVerts[1].x * v46);
      v68 = *(float *)&vecNormals[20] * v46;
      vecWorld->y = v49;
      v69 = *(float *)&vecNormals[12];
      vecWorld->z = v50;
      v70 = *(float *)&vecNormals[16] * v46;
      v71 = v69 * v46;
      *(float *)&vecNormals[36] = *(float *)&vecNormals[4] * v47;
      v72 = *(float *)&vecNormals[8] * v47;
      vecWorld->x = v67;
      *(float *)&vecNormals[40] = v72;
      v73 = (float)((float)(vecVerts[2].x * v48) + (float)(v66 * v47)) + v71;
      v74 = (float)((float)(vecVerts[2].y * v48) + *(float *)&vecNormals[36]) + v70;
      v75 = (float)((float)(vecVerts[2].z * v48) + *(float *)&vecNormals[40]) + v68;
      vecWorldNormal->x = v73;
      vecWorldNormal->y = v74;
      vecWorldNormal->z = v75;
      VectorNormalize(vec: vecWorldNormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F63F0
// Name: void Overlay_TriBLToTR(class CDispInfo __near *,class CMeshReader __near *,class Vector __near &,class Vector __near &,float,float,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Overlay_TriBLToTR(
        int a1@<ebp>,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        float flU,
        float flV,
        int nWidth,
        const Vector *vecIntersectPoint)
{
  int v9; // esi
  int v10; // eax
  int v11; // edi
  int v12; // edx
  int v13; // edx
  float v14; // xmm2_4
  int v15; // eax
  int v16; // eax
  float *v17; // edx
  unsigned int k; // esi
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm3_4
  float v25; // xmm1_4
  Vector *v26; // eax
  _DWORD *v27; // edx
  double v28; // st7
  double v29; // st7
  int v30; // ecx
  float v31; // xmm3_4
  __int128 v32; // xmm0
  float v33; // xmm2_4
  __int128 v34; // xmm0
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm3_4
  __int128 v40; // xmm0
  float v41; // xmm2_4
  __int128 v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  int v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // eax
  float *v52; // edx
  unsigned int m; // esi
  int v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float *v58; // eax
  float v59; // xmm3_4
  float v60; // xmm1_4
  Vector *v61; // eax
  _DWORD *v62; // edx
  double v63; // st7
  double v64; // st7
  int v65; // ecx
  float v66; // xmm7_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float *m_pNormal; // edx
  int m_VertexSize_Normal; // eax
  unsigned int i; // esi
  int v79; // eax
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float *v83; // eax
  float v84; // xmm3_4
  float v85; // xmm1_4
  Vector *FlatVert; // eax
  _DWORD *v87; // edx
  double y; // st7
  double z; // st7
  int v90; // ecx
  float v91; // xmm3_4
  float v92; // xmm4_4
  __int128 v93; // xmm1
  __int128 v94; // xmm1
  float v95; // xmm0_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  float x; // xmm3_4
  float v101; // xmm4_4
  __int128 v102; // xmm0
  __int128 v103; // xmm0
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm5_4
  float v108; // xmm4_4
  float v109; // xmm3_4
  Vector *v110; // eax
  float v111; // xmm2_4
  float v112; // xmm5_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm4_4
  float v117; // xmm5_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm3_4
  float v121; // xmm4_4
  float v122; // xmm4_4
  float v123; // xmm5_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  float v126; // xmm0_4
  int v127; // eax
  float *v128; // edx
  unsigned int j; // esi
  int v130; // eax
  float v131; // xmm0_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float *v134; // eax
  float v135; // xmm3_4
  float v136; // xmm0_4
  float v137; // xmm1_4
  Vector *v138; // eax
  _DWORD *v139; // edx
  double v140; // st7
  double v141; // st7
  int v142; // ecx
  int v143; // xmm0_4
  float v144; // xmm1_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  float v147; // xmm4_4
  float v148; // xmm6_4
  float v149; // xmm0_4
  float v150; // xmm6_4
  float v151; // xmm4_4
  float v152; // xmm3_4
  int v153; // [esp-18h] [ebp-E0h]
  int v154; // [esp-18h] [ebp-E0h]
  int v155; // [esp-18h] [ebp-E0h]
  int v156; // [esp-18h] [ebp-E0h]
  int v157; // [esp-Ch] [ebp-D4h]
  int v158; // [esp-8h] [ebp-D0h]
  int v159; // [esp-8h] [ebp-D0h]
  int v160; // [esp-4h] [ebp-CCh]
  int nSnapU; // [esp+0h] [ebp-C8h]
  int nSnapUa; // [esp+0h] [ebp-C8h]
  int v163; // [esp+4h] [ebp-C4h]
  int v164; // [esp+4h] [ebp-C4h]
  int nNextU[3]; // [esp+8h] [ebp-C0h] BYREF
  float v166; // [esp+Ch] [ebp-BCh]
  float v167; // [esp+10h] [ebp-B8h]
  Vector vecFlatVerts[3]; // [esp+14h] [ebp-B4h] BYREF
  int nNextV; // [esp+38h] [ebp-90h] BYREF
  __int128 flCfs; // [esp+3Ch] [ebp-8Ch] OVERLAPPED BYREF
  __int128 nIndices; // [esp+4Ch] [ebp-7Ch] OVERLAPPED
  Vector vecNormals[3]; // [esp+5Ch] [ebp-6Ch]
  _BYTE vecVerts[44]; // [esp+80h] [ebp-48h] OVERLAPPED BYREF
  char *v174; // [esp+B8h] [ebp-10h]
  _DWORD v175[3]; // [esp+BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v175[0] = a1;
  v175[1] = retaddr;
  v9 = (int)flU;
  v10 = (int)flV;
  v11 = (int)flU + 1;
  v12 = (int)flV + 1;
  v157 = (int)flU;
  *(_DWORD *)&vecVerts[24] = (int)flV;
  v160 = v11;
  LODWORD(vecFlatVerts[2].x) = v12;
  if ( v11 == nWidth )
  {
    v11 = (int)flU;
    v160 = (int)flU;
  }
  if ( v12 == nWidth )
  {
    v12 = (int)flV;
    LODWORD(vecFlatVerts[2].x) = (int)flV;
  }
  v13 = nWidth * v12;
  v14 = (float)v10;
  v15 = nWidth * v10;
  if ( (float)(flV - v14) <= (float)(flU - (float)v9) )
  {
    v164 = v13 + v11;
    *(_DWORD *)&vecVerts[36] = v13 + v11;
    nSnapUa = v15 + v9;
    *(_DWORD *)&vecVerts[32] = v15 + v9;
    v159 = v13;
    m_pNormal = pReader->m_pNormal;
    *(_DWORD *)&vecVerts[40] = v11 + v15;
    m_VertexSize_Normal = pReader->m_VertexSize_Normal;
    v174 = &vecVerts[32];
    for ( i = 0; (int)i < 9; *(float *)((char *)&nIndices + i * 4) = *(float *)((char *)m_pNormal + v90 + 8) )
    {
      v79 = *(_DWORD *)v174 * m_VertexSize_Normal;
      v80 = *(float *)((char *)m_pNormal + v79);
      v81 = *(float *)((char *)m_pNormal + v79 + 4);
      v82 = *(float *)((char *)m_pNormal + v79 + 8);
      v83 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
      v84 = v83[1] + (float)(v81 * 0.1);
      v155 = *(_DWORD *)v174;
      v85 = v83[2] + (float)(v82 * 0.1);
      vecNormals[i / 3 + 2].x = (float)(v80 * 0.1) + *v83;
      vecNormals[i / 3 + 2].y = v84;
      vecNormals[i / 3 + 2].z = v85;
      FlatVert = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)((char *)&flCfs + 4), iVertex: v155);
      v87 = v174;
      nNextU[i] = SLODWORD(FlatVert->x);
      y = FlatVert->y;
      v174 += 4;
      *(float *)((char *)&v166 + i * 4) = y;
      i += 3;
      z = FlatVert->z;
      m_VertexSize_Normal = pReader->m_VertexSize_Normal;
      *(float *)&v175[i - 46] = z;
      v90 = *v87 * m_VertexSize_Normal;
      m_pNormal = pReader->m_pNormal;
      *(float *)((char *)&flCfs + i * 4 + 8) = *(float *)((char *)m_pNormal + v90);
      *(float *)((char *)&flCfs + i * 4 + 12) = *(float *)((char *)m_pNormal + v90 + 4);
    }
    if ( v157 == v160 )
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
        goto LABEL_10;
      v91 = *(float *)&vecVerts[8] - vecNormals[2].z;
      v92 = *((float *)&nIndices + 1);
      v93 = 0;
      *(float *)&v93 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                                       * (float)(vecIntersectPoint->x - *(float *)nNextU))
                               + (float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166)))
                       + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)));
      *(_OWORD *)&vecVerts[28] = v93;
      v94 = 0;
      *(float *)&v94 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[0].x - *(float *)nNextU)
                                       * (float)(vecFlatVerts[0].x - *(float *)nNextU))
                               + (float)((float)(vecFlatVerts[0].y - v166) * (float)(vecFlatVerts[0].y - v166)))
                       + (float)((float)(vecFlatVerts[0].z - v167) * (float)(vecFlatVerts[0].z - v167)));
      flCfs = v94;
      v95 = *(float *)&vecVerts[28] / *(float *)&v94;
      *(float *)&v94 = *(float *)vecVerts - vecNormals[2].x;
      vecWorld->y = (float)((float)(*(float *)&vecVerts[4] - vecNormals[2].y) * v95) + vecNormals[2].y;
      v96 = vecNormals[0].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v91 * v95) + vecNormals[2].z;
      v97 = vecNormals[0].z - *((float *)&nIndices + 3);
      vecWorld->x = (float)(*(float *)&v94 * v95) + vecNormals[2].x;
      v98 = (float)(v96 * v95) + *((float *)&nIndices + 2);
      v99 = (float)(v97 * v95) + *((float *)&nIndices + 3);
      vecWorldNormal->x = v92 + (float)((float)(vecNormals[0].x - v92) * v95);
      vecWorldNormal->y = v98;
      vecWorldNormal->z = v99;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
      {
        x = vecNormals[2].x;
        v101 = *(float *)&vecVerts[12];
        v102 = 0;
        *(float *)&v102 = fsqrt(
                            (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                                  + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                          + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                                  * (float)(vecIntersectPoint->x - *(float *)nNextU)));
        *(_OWORD *)&vecVerts[28] = v102;
        v103 = 0;
        *(float *)&v103 = fsqrt(
                            (float)((float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166))
                                  + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)))
                          + (float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                                  * (float)(vecFlatVerts[1].x - *(float *)nNextU)));
        flCfs = v103;
        *(float *)&v103 = *(float *)&vecVerts[28] / *(float *)&v103;
        v104 = (float)((float)(*(float *)&vecVerts[20] - vecNormals[2].z)
                     * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
             + vecNormals[2].z;
        vecWorld->y = (float)((float)(*(float *)&vecVerts[16] - vecNormals[2].y)
                            * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
                    + vecNormals[2].y;
        v105 = vecNormals[1].y - *((float *)&nIndices + 2);
        vecWorld->z = v104;
        v106 = vecNormals[1].z - *((float *)&nIndices + 3);
        v107 = *(float *)&v103 * (float)(v101 - x);
        v108 = vecNormals[1].x;
        vecWorld->x = x + v107;
        v109 = *((float *)&nIndices + 1);
        v110 = vecWorldNormal;
        v111 = (float)(v106 * *(float *)&v103) + *((float *)&nIndices + 3);
        v112 = *(float *)&v103 * (float)(v108 - *((float *)&nIndices + 1));
        vecWorldNormal->y = (float)(v105 * *(float *)&v103) + *((float *)&nIndices + 2);
      }
      else
      {
        if ( CalcBarycentricCooefs(
               v0: (const Vector *)nNextU,
               v1: vecFlatVerts,
               v2: &vecFlatVerts[1],
               pt: vecIntersectPoint,
               c0: (float *)&flCfs + 1,
               c1: (float *)&flCfs + 2,
               c2: (float *)&flCfs + 3) )
        {
          v113 = *((float *)&flCfs + 3);
          v114 = *((float *)&flCfs + 2);
          vecFlatVerts[2].z = *(float *)&vecVerts[16] * *((float *)&flCfs + 3);
          *(float *)&nNextV = *(float *)&vecVerts[20] * *((float *)&flCfs + 3);
          *(float *)&vecVerts[36] = *(float *)&vecVerts[4] * *((float *)&flCfs + 2);
          v115 = *((float *)&flCfs + 1);
          v116 = (float)((float)(*((float *)&flCfs + 1) * vecNormals[2].y)
                       + (float)(*(float *)&vecVerts[4] * *((float *)&flCfs + 2)))
               + (float)(*(float *)&vecVerts[16] * *((float *)&flCfs + 3));
          v117 = (float)((float)(*((float *)&flCfs + 1) * vecNormals[2].z)
                       + (float)(*(float *)&vecVerts[8] * *((float *)&flCfs + 2)))
               + (float)(*(float *)&vecVerts[20] * *((float *)&flCfs + 3));
          v118 = vecNormals[0].y;
          v119 = vecNormals[0].x;
          vecWorld->x = (float)((float)(vecNormals[2].x * *((float *)&flCfs + 1))
                              + (float)(*(float *)vecVerts * *((float *)&flCfs + 2)))
                      + (float)(*(float *)&vecVerts[12] * *((float *)&flCfs + 3));
          v120 = vecNormals[1].x;
          vecWorld->y = v116;
          v121 = vecNormals[1].y;
          vecWorld->z = v117;
          v122 = v121 * v113;
          v123 = vecNormals[1].z * v113;
          *(float *)&vecVerts[40] = vecNormals[0].z * v114;
          v124 = (float)((float)(*((float *)&nIndices + 1) * v115) + (float)(v119 * v114)) + (float)(v120 * v113);
          v125 = (float)((float)(v115 * *((float *)&nIndices + 2)) + (float)(v118 * v114)) + v122;
          v126 = (float)((float)(v115 * *((float *)&nIndices + 3)) + *(float *)&vecVerts[40]) + v123;
          vecWorldNormal->x = v124;
          vecWorldNormal->y = v125;
          vecWorldNormal->z = v126;
          VectorNormalize(vec: vecWorldNormal);
          return;
        }
        *(_DWORD *)&vecVerts[36] = v157 + v159;
        *(_DWORD *)&vecVerts[32] = nSnapUa;
        v127 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecVerts[40] = v164;
        v128 = pReader->m_pNormal;
        *(_DWORD *)&vecVerts[24] = &vecVerts[32];
        for ( j = 0; (int)j < 9; *(float *)((char *)&nIndices + j * 4) = *(float *)((char *)v128 + v142 + 8) )
        {
          v130 = **(_DWORD **)&vecVerts[24] * v127;
          v131 = *(float *)((char *)v128 + v130);
          v132 = *(float *)((char *)v128 + v130 + 4);
          v133 = *(float *)((char *)v128 + v130 + 8);
          v134 = (float *)((char *)pReader->m_pPosition + **(_DWORD **)&vecVerts[24] * pReader->m_VertexSize_Position);
          v135 = *v134 + (float)(v131 * 0.1);
          v136 = v134[1] + (float)(v132 * 0.1);
          v156 = **(_DWORD **)&vecVerts[24];
          v137 = v134[2] + (float)(v133 * 0.1);
          vecNormals[j / 3 + 2].x = v135;
          vecNormals[j / 3 + 2].y = v136;
          vecNormals[j / 3 + 2].z = v137;
          v138 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecFlatVerts[2].y, iVertex: v156);
          v139 = *(_DWORD **)&vecVerts[24];
          nNextU[j] = SLODWORD(v138->x);
          v140 = v138->y;
          *(_DWORD *)&vecVerts[24] += 4;
          *(float *)((char *)&v166 + j * 4) = v140;
          j += 3;
          v141 = v138->z;
          v127 = pReader->m_VertexSize_Normal;
          *(float *)&v175[j - 46] = v141;
          v142 = *v139 * v127;
          v128 = pReader->m_pNormal;
          *(float *)((char *)&flCfs + j * 4 + 8) = *(float *)((char *)v128 + v142);
          *(float *)((char *)&flCfs + j * 4 + 12) = *(float *)((char *)v128 + v142 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)nNextU,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: &vecFlatVerts[2].y,
          c1: &vecFlatVerts[2].z,
          c2: (float *)&nNextV);
        v143 = nNextV;
        *((float *)&flCfs + 2) = *(float *)&nNextV * *(float *)&vecVerts[16];
        *((float *)&flCfs + 3) = *(float *)&nNextV * *(float *)&vecVerts[20];
        v144 = vecFlatVerts[2].z;
        *(float *)&vecVerts[36] = vecFlatVerts[2].z * *(float *)&vecVerts[4];
        v145 = vecFlatVerts[2].y;
        v146 = (float)((float)(vecNormals[2].x * vecFlatVerts[2].y) + (float)(vecFlatVerts[2].z * *(float *)vecVerts))
             + (float)(*(float *)&nNextV * *(float *)&vecVerts[12]);
        v147 = (float)((float)(vecFlatVerts[2].y * vecNormals[2].y) + (float)(vecFlatVerts[2].z * *(float *)&vecVerts[4]))
             + (float)(*(float *)&nNextV * *(float *)&vecVerts[16]);
        vecWorld->z = (float)((float)(vecFlatVerts[2].y * vecNormals[2].z)
                            + (float)(vecFlatVerts[2].z * *(float *)&vecVerts[8]))
                    + (float)(*(float *)&nNextV * *(float *)&vecVerts[20]);
        vecWorld->y = v147;
        v112 = *(float *)&v143 * vecNormals[1].x;
        v148 = *(float *)&v143;
        v149 = *(float *)&v143 * vecNormals[1].z;
        v150 = v148 * vecNormals[1].y;
        vecWorld->x = v146;
        v110 = vecWorldNormal;
        *(float *)&vecVerts[40] = v149;
        v151 = v145 * *((float *)&nIndices + 2);
        v152 = *((float *)&nIndices + 1) * v145;
        v111 = (float)((float)(v145 * *((float *)&nIndices + 3)) + (float)(v144 * vecNormals[0].z)) + v149;
        v109 = v152 + (float)(v144 * vecNormals[0].x);
        vecWorldNormal->y = (float)(v151 + (float)(v144 * vecNormals[0].y)) + v150;
      }
      v110->z = v111;
      v110->x = v109 + v112;
      VectorNormalize(vec: v110);
    }
  }
  else
  {
    v158 = v15;
    DWORD2(flCfs) = v13 + v9;
    nSnapU = v9 + v15;
    DWORD1(flCfs) = v9 + v15;
    v16 = pReader->m_VertexSize_Normal;
    v163 = v11 + v13;
    HIDWORD(flCfs) = v11 + v13;
    v17 = pReader->m_pNormal;
    v174 = (char *)&flCfs + 4;
    for ( k = 0; (int)k < 9; *(float *)((char *)&nIndices + k * 4) = *(float *)((char *)v17 + v30 + 8) )
    {
      v19 = *(_DWORD *)v174 * v16;
      v20 = *(float *)((char *)v17 + v19);
      v21 = *(float *)((char *)v17 + v19 + 4);
      v22 = *(float *)((char *)v17 + v19 + 8);
      v23 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
      v24 = v23[1] + (float)(v21 * 0.1);
      v153 = *(_DWORD *)v174;
      v25 = v23[2] + (float)(v22 * 0.1);
      vecNormals[k / 3 + 2].x = (float)(v20 * 0.1) + *v23;
      vecNormals[k / 3 + 2].y = v24;
      vecNormals[k / 3 + 2].z = v25;
      v26 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecVerts[32], iVertex: v153);
      v27 = v174;
      nNextU[k] = SLODWORD(v26->x);
      v28 = v26->y;
      v174 += 4;
      *(float *)((char *)&v166 + k * 4) = v28;
      k += 3;
      v29 = v26->z;
      v16 = pReader->m_VertexSize_Normal;
      *(float *)&v175[k - 46] = v29;
      v30 = *v27 * v16;
      v17 = pReader->m_pNormal;
      *(float *)((char *)&flCfs + k * 4 + 8) = *(float *)((char *)v17 + v30);
      *(float *)((char *)&flCfs + k * 4 + 12) = *(float *)((char *)v17 + v30 + 4);
    }
    if ( v157 == v160 )
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
      {
LABEL_10:
        *vecWorld = vecNormals[2];
        *vecWorldNormal = *(Vector *)((char *)&nIndices + 4);
        VectorNormalize(vec: vecWorldNormal);
        return;
      }
      v31 = *(float *)&vecVerts[20] - vecNormals[2].z;
      v32 = 0;
      *(float *)&v32 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                               + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                       + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                               * (float)(vecIntersectPoint->x - *(float *)nNextU)));
      *(_OWORD *)&vecVerts[28] = v32;
      v33 = *(float *)&vecVerts[16] - vecNormals[2].y;
      v34 = 0;
      *(float *)&v34 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166))
                               + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)))
                       + (float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                               * (float)(vecFlatVerts[1].x - *(float *)nNextU)));
      flCfs = v34;
      *(float *)&v34 = *(float *)&vecVerts[28] / *(float *)&v34;
      vecWorld->x = (float)((float)(*(float *)&vecVerts[12] - vecNormals[2].x)
                          * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
                  + vecNormals[2].x;
      v35 = vecNormals[1].x - *((float *)&nIndices + 1);
      vecWorld->y = (float)(v33 * *(float *)&v34) + vecNormals[2].y;
      v36 = vecNormals[1].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v31 * *(float *)&v34) + vecNormals[2].z;
      v37 = (float)(v36 * *(float *)&v34) + *((float *)&nIndices + 2);
      v38 = (float)((float)(vecNormals[1].z - *((float *)&nIndices + 3)) * *(float *)&v34) + *((float *)&nIndices + 3);
      vecWorldNormal->x = (float)(v35 * *(float *)&v34) + *((float *)&nIndices + 1);
      vecWorldNormal->y = v37;
      vecWorldNormal->z = v38;
      VectorNormalize(vec: vecWorldNormal);
    }
    else if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
    {
      v39 = *(float *)&vecVerts[20] - vecNormals[2].z;
      v40 = 0;
      *(float *)&v40 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                               + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                       + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                               * (float)(vecIntersectPoint->x - *(float *)nNextU)));
      *(_OWORD *)&vecVerts[28] = v40;
      v41 = *(float *)&vecVerts[16] - vecNormals[2].y;
      v42 = 0;
      *(float *)&v42 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                                       * (float)(vecFlatVerts[1].x - *(float *)nNextU))
                               + (float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166)))
                       + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)));
      flCfs = v42;
      *(float *)&v40 = *(float *)&v40 / *(float *)&v42;
      vecWorld->x = (float)((float)(*(float *)&vecVerts[12] - vecNormals[2].x) * *(float *)&v40) + vecNormals[2].x;
      *(float *)&v42 = vecNormals[1].x - *((float *)&nIndices + 1);
      vecWorld->y = (float)(v41 * *(float *)&v40) + vecNormals[2].y;
      v43 = vecNormals[1].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v39 * *(float *)&v40) + vecNormals[2].z;
      v44 = (float)(v43 * *(float *)&v40) + *((float *)&nIndices + 2);
      v45 = (float)((float)(vecNormals[1].z - *((float *)&nIndices + 3)) * *(float *)&v40) + *((float *)&nIndices + 3);
      vecWorldNormal->x = (float)(*(float *)&v42 * *(float *)&v40) + *((float *)&nIndices + 1);
      vecWorldNormal->y = v44;
      vecWorldNormal->z = v45;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( CalcBarycentricCooefs(
             v0: (const Vector *)nNextU,
             v1: vecFlatVerts,
             v2: &vecFlatVerts[1],
             pt: vecIntersectPoint,
             c0: &vecFlatVerts[2].y,
             c1: &vecFlatVerts[2].z,
             c2: (float *)&nNextV) )
      {
        v46 = nNextV;
        *(float *)&vecVerts[36] = *(float *)&vecVerts[16] * *(float *)&nNextV;
        *(float *)&vecVerts[40] = *(float *)&vecVerts[20] * *(float *)&nNextV;
        v47 = vecFlatVerts[2].z;
        *((float *)&flCfs + 2) = *(float *)&vecVerts[4] * vecFlatVerts[2].z;
        *((float *)&flCfs + 3) = *(float *)&vecVerts[8] * vecFlatVerts[2].z;
        v48 = vecFlatVerts[2].y;
        v49 = (float)((float)(vecNormals[2].y * vecFlatVerts[2].y) + (float)(*(float *)&vecVerts[4] * vecFlatVerts[2].z))
            + (float)(*(float *)&vecVerts[16] * *(float *)&nNextV);
        v50 = (float)((float)(vecNormals[2].z * vecFlatVerts[2].y) + (float)(*(float *)&vecVerts[8] * vecFlatVerts[2].z))
            + (float)(*(float *)&vecVerts[20] * *(float *)&nNextV);
      }
      else
      {
        *(_DWORD *)&vecVerts[36] = v163;
        *(_DWORD *)&vecVerts[32] = nSnapU;
        v51 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecVerts[40] = v160 + v158;
        v52 = pReader->m_pNormal;
        v174 = &vecVerts[32];
        for ( m = 0; (int)m < 9; *(float *)((char *)&nIndices + m * 4) = *(float *)((char *)v52 + v65 + 8) )
        {
          v54 = *(_DWORD *)v174 * v51;
          v55 = *(float *)((char *)v52 + v54);
          v56 = *(float *)((char *)v52 + v54 + 4);
          v57 = *(float *)((char *)v52 + v54 + 8);
          v58 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
          v59 = v58[1] + (float)(v56 * 0.1);
          v154 = *(_DWORD *)v174;
          v60 = v58[2] + (float)(v57 * 0.1);
          vecNormals[m / 3 + 2].x = (float)(v55 * 0.1) + *v58;
          vecNormals[m / 3 + 2].y = v59;
          vecNormals[m / 3 + 2].z = v60;
          v61 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)((char *)&flCfs + 4), iVertex: v154);
          v62 = v174;
          nNextU[m] = SLODWORD(v61->x);
          v63 = v61->y;
          v174 += 4;
          *(float *)((char *)&v166 + m * 4) = v63;
          m += 3;
          v64 = v61->z;
          v51 = pReader->m_VertexSize_Normal;
          *(float *)&v175[m - 46] = v64;
          v65 = *v62 * v51;
          v52 = pReader->m_pNormal;
          *(float *)((char *)&flCfs + m * 4 + 8) = *(float *)((char *)v52 + v65);
          *(float *)((char *)&flCfs + m * 4 + 12) = *(float *)((char *)v52 + v65 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)nNextU,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: (float *)&flCfs + 1,
          c1: (float *)&flCfs + 2,
          c2: (float *)&flCfs + 3);
        v46 = SHIDWORD(flCfs);
        vecFlatVerts[2].z = *(float *)&vecVerts[16] * *((float *)&flCfs + 3);
        *(float *)&nNextV = *(float *)&vecVerts[20] * *((float *)&flCfs + 3);
        v47 = *((float *)&flCfs + 2);
        *(float *)&vecVerts[36] = *(float *)&vecVerts[4] * *((float *)&flCfs + 2);
        *(float *)&vecVerts[40] = *(float *)&vecVerts[8] * *((float *)&flCfs + 2);
        v48 = *((float *)&flCfs + 1);
        v49 = (float)((float)(vecNormals[2].y * *((float *)&flCfs + 1))
                    + (float)(*(float *)&vecVerts[4] * *((float *)&flCfs + 2)))
            + (float)(*(float *)&vecVerts[16] * *((float *)&flCfs + 3));
        v50 = (float)((float)(vecNormals[2].z * *((float *)&flCfs + 1))
                    + (float)(*(float *)&vecVerts[8] * *((float *)&flCfs + 2)))
            + (float)(*(float *)&vecVerts[20] * *((float *)&flCfs + 3));
      }
      v66 = vecNormals[0].x;
      v67 = (float)((float)(vecNormals[2].x * v48) + (float)(*(float *)vecVerts * v47))
          + (float)(*(float *)&vecVerts[12] * *(float *)&v46);
      v68 = vecNormals[1].z * *(float *)&v46;
      vecWorld->y = v49;
      v69 = vecNormals[1].x;
      vecWorld->z = v50;
      v70 = vecNormals[1].y * *(float *)&v46;
      v71 = v69 * *(float *)&v46;
      *(float *)&vecVerts[36] = vecNormals[0].y * v47;
      v72 = vecNormals[0].z * v47;
      vecWorld->x = v67;
      *(float *)&vecVerts[40] = v72;
      v73 = (float)((float)(*((float *)&nIndices + 1) * v48) + (float)(v66 * v47)) + v71;
      v74 = (float)((float)(*((float *)&nIndices + 2) * v48) + *(float *)&vecVerts[36]) + v70;
      v75 = (float)((float)(*((float *)&nIndices + 3) * v48) + *(float *)&vecVerts[40]) + v68;
      vecWorldNormal->x = v73;
      vecWorldNormal->y = v74;
      vecWorldNormal->z = v75;
      VectorNormalize(vec: vecWorldNormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7480
// Name: public: virtual void COverlayMgr::ClearRenderLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ClearRenderLists(COverlayMgr *this)
{
  int i; // esi
  float v3; // xmm1_4
  float v4; // xmm0_4

  for ( i = 0; i < 4; ++i )
    this->ClearRenderLists(this, a2: i);
  if ( r_overlayfadeenable.m_pParent != nullptr && r_overlayfadeenable.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = r_overlayfademin.m_pParent->m_Value.m_fValue * r_overlayfademin.m_pParent->m_Value.m_fValue;
    v4 = r_overlayfademax.m_pParent->m_Value.m_fValue * r_overlayfademax.m_pParent->m_Value.m_fValue;
    this->m_flFadeMin2 = v3;
    this->m_flFadeMax2 = v4;
    this->m_flFadeDelta2 = 1.0 / (float)(v4 - v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F74F0
// Name: private: bool COverlayMgr::FadeOverlayFragmentGlobal(struct moverlayfragment_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COverlayMgr::FadeOverlayFragmentGlobal(COverlayMgr *this, moverlayfragment_t *pFragment)
{
  bool result; // al
  int v4; // esi
  int m_Size; // ebx
  overlayvert_t *m_pMemory; // edx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  overlayvert_t *v10; // edx
  float v11; // xmm0_4
  float m_flFadeMin2; // xmm1_4
  float v13; // xmm0_4
  float pFragmenta; // [esp+Ch] [ebp+8h]

  result = false;
  if ( pFragment->m_aPrimVerts.m_Size > 0 )
  {
    v4 = 0;
    m_Size = pFragment->m_aPrimVerts.m_Size;
    while ( 1 )
    {
      m_pMemory = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
      v7 = g_CurrentViewOrigin.x - m_pMemory[v4].pos.x;
      v8 = g_CurrentViewOrigin.y - m_pMemory[v4].pos.y;
      v9 = g_CurrentViewOrigin.z - m_pMemory[v4].pos.z;
      v10 = &m_pMemory[v4];
      v11 = (float)(v8 * v8) + (float)(v7 * v7);
      m_flFadeMin2 = this->m_flFadeMin2;
      v13 = v11 + (float)(v9 * v9);
      if ( m_flFadeMin2 > v13 )
        break;
      if ( v13 <= this->m_flFadeMax2 )
      {
        pFragmenta = (float)((float)(1.0 - (float)((float)(v13 - m_flFadeMin2) * this->m_flFadeDelta2)) * 255.0)
                   + 8388608.0;
        pFragment->m_aPrimVerts.m_Memory.m_pMemory[v4].packedColor = (LOBYTE(pFragmenta) << 24) | 0xFFFFFF;
        goto LABEL_8;
      }
      v10->packedColor = 0xFFFFFF;
LABEL_9:
      ++v4;
      if ( --m_Size == 0 )
        return result;
    }
    v10->packedColor = -1;
LABEL_8:
    result = true;
    goto LABEL_9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F75E0
// Name: private: bool COverlayMgr::FadeOverlayFragment(struct moverlay_t __near *,struct moverlayfragment_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::FadeOverlayFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *pFragment)
{
  float m_flFadeDistMaxSq; // xmm3_4
  float m_flFadeDistMinSq; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  int v9; // esi
  float v10; // xmm3_4
  int m_Size; // ecx
  int v12; // eax
  float v13; // [esp-4h] [ebp-10h]

  m_flFadeDistMaxSq = pOverlay->m_flFadeDistMaxSq;
  m_flFadeDistMinSq = pOverlay->m_flFadeDistMinSq;
  v6 = fsqrt(
         (float)((float)((float)(pOverlay->m_vecOrigin.z - g_CurrentViewOrigin.z)
                       * (float)(pOverlay->m_vecOrigin.z - g_CurrentViewOrigin.z))
               + (float)((float)(pOverlay->m_vecOrigin.y - g_CurrentViewOrigin.y)
                       * (float)(pOverlay->m_vecOrigin.y - g_CurrentViewOrigin.y)))
       + (float)((float)(pOverlay->m_vecOrigin.x - g_CurrentViewOrigin.x)
               * (float)(pOverlay->m_vecOrigin.x - g_CurrentViewOrigin.x)));
  v7 = (float)(v6 - pOverlay->m_flRadius) * (float)(v6 - pOverlay->m_flRadius);
  if ( v7 >= m_flFadeDistMaxSq )
    return 0;
  v9 = -1;
  if ( m_flFadeDistMinSq >= 0.0 && v7 > m_flFadeDistMinSq )
  {
    v10 = (float)(m_flFadeDistMaxSq - v7) * pOverlay->m_flInvFadeRangeSq;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    v13 = (float)(v10 * 255.0) + 8388608.0;
    v9 = (LOBYTE(v13) << 24) | 0xFFFFFF;
  }
  m_Size = pFragment->m_aPrimVerts.m_Size;
  if ( m_Size > 0 )
  {
    v12 = 0;
    do
    {
      pFragment->m_aPrimVerts.m_Memory.m_pMemory[v12++].packedColor = v9;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7700
// Name: public: virtual void COverlayMgr::ClearRenderLists(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ClearRenderLists(COverlayMgr *this, int nSortGroup)
{
  COverlayMgr::RenderQueueInfo_t *v2; // eax
  int m_nNextRenderQueue; // edx

  ++g_OverlayRenderFrameID;
  v2 = (COverlayMgr::RenderQueueInfo_t *)this->m_nFirstRenderQueue[nSortGroup];
  if ( v2 == (COverlayMgr::RenderQueueInfo_t *)0xFFFF )
  {
    this->m_nFirstRenderQueue[nSortGroup] = -1;
  }
  else
  {
    do
    {
      v2 = &this->m_RenderQueue.m_Memory.m_pMemory[(unsigned __int16)v2].m_Element.m_Queue[nSortGroup];
      m_nNextRenderQueue = v2->m_nNextRenderQueue;
      v2->m_nVertexCount = 0;
      v2->m_nIndexCount = 0;
      v2->m_hFirstFragment = -1;
      v2->m_nNextRenderQueue = -1;
      LOWORD(v2) = m_nNextRenderQueue;
    }
    while ( m_nNextRenderQueue != 0xFFFF );
    this->m_nFirstRenderQueue[nSortGroup] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7770
// Name: public: virtual void COverlayMgr::SetOverlayBindProxy(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::SetOverlayBindProxy(COverlayMgr *this, int iOverlayID, void *pBindProxy)
{
  moverlay_t *v3; // eax

  v3 = &this->m_aOverlays.m_Memory.m_pMemory[iOverlayID];
  if ( v3 != nullptr )
    v3->m_pBindProxy = pBindProxy;
}

//------------------------------------------------------------------------------
// Address: 0x100F7790
// Name: void Overlay_DispUVToWorld(class CDispInfo __near *,class CMeshReader __near *,class Vector2D const __near &,class Vector __near &,class Vector __near &,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_DispUVToWorld(
        CDispInfo *pDisp,
        CMeshReader *pReader,
        const Vector2D *vecUV,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        CMeshReader *surfaceFrag)
{
  int v7; // esi
  float v8; // xmm0_4
  Vector point; // [esp+1Ch] [ebp-Ch] BYREF
  int _28; // [esp+28h] [ebp+0h] BYREF
  float vecIntersectPoint_4; // [esp+30h] [ebp+8h]
  float pReadera; // [esp+44h] [ebp+1Ch]

  v7 = (1 << *(_DWORD *)(pDisp->GetPowerInfo(this: &pDisp->CDispUtilsHelper) + 28)) + 1;
  PointInQuadFromBarycentric(
    v1: (const Vector *)(surfaceFrag->m_VertexSize_Color + 52 * (pDisp->m_iPointStart % 4)),
    v2: (const Vector *)(surfaceFrag->m_VertexSize_Color + 52 * ((pDisp->m_iPointStart + 3) % 4)),
    v3: (const Vector *)(surfaceFrag->m_VertexSize_Color + 52 * ((pDisp->m_iPointStart + 2) % 4)),
    v4: (const Vector *)(surfaceFrag->m_VertexSize_Color + 52 * ((pDisp->m_iPointStart + 1) % 4)),
    uv: vecUV,
    &point);
  v8 = (float)v7 - 1.000001;
  pReadera = vecUV->x * v8;
  vecIntersectPoint_4 = vecUV->y * v8;
  if ( ((int)pReadera + v7 * (int)vecIntersectPoint_4) % 2 == 1 )
    Overlay_TriTLToBR(
      a1: (int)&_28,
      pDisp,
      pReader,
      vecWorld,
      vecWorldNormal,
      flU: pReadera,
      flV: vecIntersectPoint_4,
      nWidth: v7,
      vecIntersectPoint: &point);
  else
    Overlay_TriBLToTR(
      a1: (int)&_28,
      pDisp,
      pReader,
      vecWorld,
      vecWorldNormal,
      flU: pReadera,
      flV: vecIntersectPoint_4,
      nWidth: v7,
      vecIntersectPoint: &point);
}

//------------------------------------------------------------------------------
// Address: 0x100F7CF0
// Name: struct overlayvert_t __near * CopyConstruct<struct overlayvert_t>(struct overlayvert_t __near *,struct overlayvert_t const __near &)
// Source: json
//------------------------------------------------------------------------------
overlayvert_t *__cdecl CopyConstruct<overlayvert_t>(overlayvert_t *pMemory, const overlayvert_t *src)
{
  overlayvert_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  *pMemory = *src;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F7ED0
// Name: public: virtual void COverlayMgr::AddFragmentListToRenderList(int,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::AddFragmentListToRenderList(
        COverlayMgr *this,
        int nSortGroup,
        unsigned __int16 iFragment,
        bool bDisp)
{
  int v5; // eax
  moverlayfragment_t *v6; // esi
  moverlay_t *v7; // edx
  unsigned __int8 m_nMinCPULevel; // cl
  int m_nCPULevel; // ebx
  bool v10; // al
  unsigned __int8 m_nMaxCPULevel; // cl
  unsigned __int8 m_nMinGPULevel; // cl
  unsigned __int8 m_nMaxGPULevel; // cl
  bool v14; // al
  int m_nMaterialSortID; // ecx
  COverlayMgr::RenderQueueInfo_t *v16; // eax
  int nVertexCount; // [esp+4h] [ebp-8h]
  unsigned __int16 i; // [esp+8h] [ebp-4h]
  int iFragmenta; // [esp+18h] [ebp+Ch]

  for ( i = iFragment; i != 0xFFFF; i = *(unsigned __int16 *)((char *)&this->m_aFragments.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 44 * i;
    v6 = (moverlayfragment_t *)((char *)&this->m_aFragments.m_Memory.m_pMemory->m_Element + v5);
    iFragmenta = v5;
    if ( !bDisp && v6->m_nRenderFrameID == g_OverlayRenderFrameID )
      continue;
    v7 = &this->m_aOverlays.m_Memory.m_pMemory[v6->m_iOverlay];
    if ( v7 == nullptr )
      continue;
    m_nMinCPULevel = v7->m_nMinCPULevel;
    m_nCPULevel = this->m_nCPULevel;
    v10 = true;
    if ( m_nMinCPULevel == 0 || (v10 = m_nCPULevel >= m_nMinCPULevel - 1) )
    {
      m_nMaxCPULevel = v7->m_nMaxCPULevel;
      if ( m_nMaxCPULevel != 0 )
        v10 = m_nCPULevel <= m_nMaxCPULevel - 1;
      if ( v10 )
      {
        m_nMinGPULevel = v7->m_nMinGPULevel;
        if ( m_nMinGPULevel != 0 )
          v10 = this->m_nGPULevel >= m_nMinGPULevel - 1;
        if ( v10 )
        {
          m_nMaxGPULevel = v7->m_nMaxGPULevel;
          if ( m_nMaxGPULevel != 0 )
            v10 = this->m_nGPULevel <= m_nMaxGPULevel - 1;
          if ( v10 )
          {
            nVertexCount = v6->m_aPrimVerts.m_Size;
            if ( nVertexCount >= 3 )
            {
              if ( r_overlayfadeenable.m_pParent != nullptr && r_overlayfadeenable.m_pParent->m_Value.m_nValue != 0 )
              {
                v14 = COverlayMgr::FadeOverlayFragmentGlobal(this, pFragment: v6);
              }
              else
              {
                if ( v7->m_flFadeDistMaxSq <= 0.0 )
                  goto LABEL_23;
                v14 = COverlayMgr::FadeOverlayFragment(this, pOverlay: v7, pFragment: v6);
              }
              if ( v14 )
              {
LABEL_23:
                m_nMaterialSortID = v6->m_nMaterialSortID;
                v6->m_nRenderFrameID = g_OverlayRenderFrameID;
                v16 = &this->m_RenderQueue.m_Memory.m_pMemory[m_nMaterialSortID].m_Element.m_Queue[nSortGroup];
                if ( v16->m_hFirstFragment == 0xFFFF )
                {
                  this->m_RenderQueue.m_Memory.m_pMemory[m_nMaterialSortID].m_Element.m_Queue[nSortGroup].m_nNextRenderQueue = this->m_nFirstRenderQueue[nSortGroup];
                  this->m_nFirstRenderQueue[nSortGroup] = m_nMaterialSortID;
                }
                v6->m_hNextRender = v16->m_hFirstFragment;
                v16->m_nVertexCount += nVertexCount;
                v16->m_nIndexCount += 3 * nVertexCount - 6;
                v16->m_hFirstFragment = i;
              }
            }
          }
        }
      }
    }
    v5 = iFragmenta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8070
// Name: public: virtual void COverlayMgr::RenderAllUnlitOverlays(class IMatRenderContext __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::RenderAllUnlitOverlays(
        COverlayMgr *this,
        IMatRenderContext *pRenderContext,
        int nSortGroup)
{
  moverlay_t *m_pMemory; // eax
  int m_hFirstFragment; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v7; // ecx
  int v8; // esi
  int i; // [esp+8h] [ebp-4h]
  int nSortGroupa; // [esp+18h] [ebp+Ch]

  i = 0;
  if ( this->m_aOverlays.m_Size > 0 )
  {
    nSortGroupa = 0;
    do
    {
      m_pMemory = this->m_aOverlays.m_Memory.m_pMemory;
      if ( (m_pMemory[nSortGroupa].m_nFlags & 1) != 0 )
      {
        m_hFirstFragment = m_pMemory[nSortGroupa].m_hFirstFragment;
        if ( m_hFirstFragment != 0xFFFF )
        {
          v7 = this->m_OverlayFragments.m_Memory.m_pMemory;
          do
          {
            v8 = (unsigned __int16)m_hFirstFragment;
            this->AddFragmentListToRenderList(this, a2: nSortGroup, a3: v7[v8].m_Element, a4: false);
            v7 = this->m_OverlayFragments.m_Memory.m_pMemory;
            m_hFirstFragment = v7[v8].m_Next;
          }
          while ( m_hFirstFragment != 0xFFFF );
        }
      }
      ++nSortGroupa;
      ++i;
    }
    while ( i < this->m_aOverlays.m_Size );
  }
  this->RenderOverlays(this, a2: pRenderContext, a3: nSortGroup);
  this->ClearRenderLists(this, a2: nSortGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100F8410
// Name: private: void COverlayMgr::BuildClipPlanes(struct msurface2_t __near *,struct moverlayfragment_t __near &,class Vector const __near &,class CUtlVector<struct cplane_t,class CUtlMemory<struct cplane_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::BuildClipPlanes(
        COverlayMgr *this,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag,
        const Vector *vecBasisNormal,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *m_ClipPlanes)
{
  int m_Size; // edi
  int v7; // ebx
  overlayvert_t *m_pMemory; // ecx
  int v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  int m_nAllocationCount; // eax
  cplane_t *v14; // ecx
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  cplane_t *v20; // ecx
  float v21; // xmm1_4
  int v22; // edx
  float v23; // xmm3_4
  Vector vecEdge; // [esp+4h] [ebp-14h] BYREF
  int v25; // [esp+10h] [ebp-8h]
  int nVertCount; // [esp+14h] [ebp-4h]
  int m_ClipPlanesa; // [esp+2Ch] [ebp+14h]

  m_Size = surfaceFrag->m_aPrimVerts.m_Size;
  nVertCount = m_Size;
  if ( m_Size > 0 )
  {
    m_ClipPlanesa = 2;
    v7 = 0;
    v25 = m_Size;
    while ( 1 )
    {
      m_pMemory = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v9 = (m_ClipPlanesa - 1) % m_Size;
      v10 = m_pMemory[v9].pos.y - m_pMemory[v7].pos.y;
      v11 = m_pMemory[v9].pos.z - m_pMemory[v7].pos.z;
      vecEdge.x = m_pMemory[v9].pos.x - m_pMemory[v7].pos.x;
      vecEdge.y = v10;
      vecEdge.z = v11;
      VectorNormalize(vec: &vecEdge);
      v12 = (int)m_ClipPlanes[1].m_pMemory;
      m_nAllocationCount = m_ClipPlanes->m_nAllocationCount;
      if ( v12 + 1 > m_nAllocationCount )
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: m_ClipPlanes, num: v12 - m_nAllocationCount + 1);
      ++m_ClipPlanes[1].m_pMemory;
      v14 = (cplane_t *)m_ClipPlanes->m_pMemory;
      v15 = (int)m_ClipPlanes[1].m_pMemory - v12 - 1;
      m_ClipPlanes[1].m_nAllocationCount = (int)m_ClipPlanes->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 20 * v15);
      v16 = vecBasisNormal->z * vecEdge.x;
      v17 = (float)(vecBasisNormal->y * vecEdge.z) - (float)(vecBasisNormal->z * vecEdge.y);
      v18 = vecBasisNormal->x * vecEdge.z;
      v19 = (float)(vecBasisNormal->x * vecEdge.y) - (float)(vecBasisNormal->y * vecEdge.x);
      v20 = (cplane_t *)&m_ClipPlanes->m_pMemory[v12];
      v20->normal.x = v17;
      v20->normal.z = v19;
      v21 = v16 - v18;
      v20->normal.y = v21;
      v22 = m_ClipPlanesa % nVertCount;
      v23 = (float)((float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.y * v21)
                  + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.x * v17))
          + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.z * v19);
      v20->dist = v23;
      v20->type = 3;
      if ( (float)((float)((float)((float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.y * v21)
                                 + (float)(v17 * surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.x))
                         + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.z * v19))
                 - v23) > 0.0 )
      {
        v20->normal.x = -v17;
        v20->normal.y = -v21;
        v20->normal.z = -v19;
        v20->dist = -v23;
      }
      ++m_ClipPlanesa;
      ++v7;
      if ( --v25 == 0 )
        break;
      m_Size = nVertCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F8770
// Name: public: virtual void COverlayMgr::RenderOverlays(class IMatRenderContext __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::RenderOverlays(COverlayMgr *this, IMatRenderContext *pRenderContext, int nSortGroup)
{
  COverlayMgr *v3; // edi
  int m_nValue; // eax
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v6; // eax
  COverlayMgr::RenderQueueHead_t *p_m_Element; // esi
  int m_nNextRenderQueue; // edx
  IMaterial *m_pMaterial; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // edi
  void *m_pBindProxy; // edx
  unsigned __int16 m_hNextRender; // ax
  int m_Size; // edx
  float *m_pCurrPosition; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int m_nVertexCount; // eax
  void *v19; // eax
  IMatRenderContext *v20; // ebx
  COverlayMgr::RenderQueueHead_t *v21; // esi
  bool v22; // al
  IMesh *v23; // ebx
  int m_nIndexCount; // eax
  int v25; // ecx
  const overlayvert_t *v26; // esi
  const overlayvert_t *v27; // ebx
  float decalOffset; // xmm0_4
  int v29; // edi
  unsigned int v30; // edx
  float *p_z; // eax
  float *m_pCurrNormal; // ecx
  float *v33; // ecx
  float *v34; // ecx
  float *v35; // ecx
  int v36; // ecx
  float *v37; // ecx
  float *v38; // ecx
  float *v39; // ecx
  float *v40; // ecx
  float *v41; // ecx
  int v42; // ecx
  float *v43; // ecx
  float *v44; // ecx
  float *v45; // ecx
  float *v46; // ecx
  float *v47; // ecx
  int v48; // ecx
  float *v49; // ecx
  float *v50; // ecx
  float *v51; // ecx
  float *v52; // ecx
  float *v53; // ecx
  int v54; // ecx
  float *v55; // eax
  int v56; // edx
  float *v57; // ecx
  float *v58; // ecx
  float *v59; // ecx
  float *v60; // ecx
  int v61; // ecx
  int v62; // edi
  unsigned int v63; // edx
  float *v64; // eax
  float *v65; // ecx
  float *v66; // ecx
  float *v67; // ecx
  float *v68; // ecx
  int v69; // ecx
  float *v70; // ecx
  float *v71; // ecx
  float *v72; // ecx
  float *v73; // ecx
  float *v74; // ecx
  int v75; // ecx
  float *v76; // ecx
  float *v77; // ecx
  float *v78; // ecx
  float *v79; // ecx
  float *v80; // ecx
  int v81; // ecx
  float *v82; // ecx
  float *v83; // ecx
  float *v84; // ecx
  float *v85; // ecx
  float *v86; // ecx
  int v87; // ecx
  float *v88; // eax
  int v89; // edx
  float *v90; // ecx
  float *v91; // ecx
  float *v92; // ecx
  float *v93; // ecx
  int v94; // ecx
  int v95; // ebx
  unsigned int v96; // esi
  unsigned __int8 *v97; // edi
  int *v98; // eax
  IMesh *v99; // edi
  int v100; // eax
  int *v101; // eax
  CUtlVectorFixedGrowable<int,256> polyList; // [esp+8h] [ebp-644h] BYREF
  int nNextRenderQueue; // [esp+420h] [ebp-22Ch]
  void *pCurrentBindProxy; // [esp+424h] [ebp-228h]
  CMeshBuilder meshBuilder; // [esp+428h] [ebp-224h] BYREF
  COverlayMgr::RenderQueueHead_t *renderQueueHead; // [esp+610h] [ebp-3Ch]
  int nMaxVertices; // [esp+614h] [ebp-38h]
  int nMaxIndices; // [esp+618h] [ebp-34h]
  int iHighestRenderOrder; // [esp+61Ch] [ebp-30h]
  int iCurrentRenderOrder; // [esp+620h] [ebp-2Ch]
  int nCurrVertexCount; // [esp+624h] [ebp-28h]
  int nCurrIndexCount; // [esp+628h] [ebp-24h]
  int v113; // [esp+62Ch] [ebp-20h]
  COverlayMgr *v114; // [esp+630h] [ebp-1Ch]
  int hStartFragment; // [esp+634h] [ebp-18h]
  int nVertCount; // [esp+638h] [ebp-14h]
  IMesh *pMesh; // [esp+63Ch] [ebp-10h]
  bool bWireframeFragments; // [esp+642h] [ebp-Ah]
  bool bBoundMaterial; // [esp+643h] [ebp-9h]
  const overlayvert_t *pVert; // [esp+644h] [ebp-8h]
  bool bLightmappedMaterial; // [esp+64Bh] [ebp-1h]

  v3 = this;
  v114 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "COverlayMgr::RenderOverlays",
    a3: 0,
    a4: "Overlays",
    a5: false,
    a6: 4);
  if ( r_renderoverlayfragment.m_pParent == nullptr || r_renderoverlayfragment.m_pParent->m_Value.m_nValue == 0 )
  {
    v3->ClearRenderLists(this: v3, a2: nSortGroup);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( r_overlaywireframe.m_pParent != nullptr )
    m_nValue = r_overlaywireframe.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bWireframeFragments = m_nValue != 0;
  if ( m_nValue != 0 )
    pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  iCurrentRenderOrder = 0;
  iHighestRenderOrder = 0;
  bLightmappedMaterial = false;
  nMaxIndices = GetMaxIndicesToRender(this: pRenderContext);
  while ( 2 )
  {
    v6 = v3->m_nFirstRenderQueue[nSortGroup];
    if ( v6 == 0xFFFF )
      goto LABEL_125;
    do
    {
      p_m_Element = &v114->m_RenderQueue.m_Memory.m_pMemory[(unsigned __int16)v6].m_Element;
      m_nNextRenderQueue = p_m_Element->m_Queue[nSortGroup].m_nNextRenderQueue;
      renderQueueHead = p_m_Element;
      nNextRenderQueue = m_nNextRenderQueue;
      if ( bWireframeFragments )
        m_pMaterial = g_materialWorldWireframe;
      else
        m_pMaterial = p_m_Element->m_pMaterial;
      nMaxVertices = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: m_pMaterial);
      hStartFragment = p_m_Element->m_Queue[nSortGroup].m_hFirstFragment;
      if ( (_WORD)hStartFragment == 0xFFFF )
        goto LABEL_124;
      do
      {
        m_pMemory = v114->m_aFragments.m_Memory.m_pMemory;
        m_pBindProxy = v114->m_aOverlays.m_Memory.m_pMemory[m_pMemory[(unsigned __int16)hStartFragment].m_Element.m_iOverlay].m_pBindProxy;
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        polyList.m_Memory.m_nGrowSize = -1;
        m_hNextRender = hStartFragment;
        polyList.m_pElements = polyList.m_Memory.m_pFixedMemory;
        pCurrentBindProxy = m_pBindProxy;
        m_Size = 0;
        pMesh = nullptr;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        polyList.m_Memory.m_pMemory = polyList.m_Memory.m_pFixedMemory;
        polyList.m_Memory.m_nAllocationCount = 256;
        polyList.m_Memory.m_nMallocGrowSize = 0;
        polyList.m_Size = 0;
        nCurrVertexCount = 0;
        nCurrIndexCount = 0;
        bBoundMaterial = false;
        hStartFragment = 0xFFFF;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        do
        {
          v113 = 44 * m_hNextRender;
          v15 = (int)&v114->m_aOverlays.m_Memory.m_pMemory[m_pMemory[v113 / 0x2Cu].m_Element.m_iOverlay];
          if ( *(void **)(v15 + 144) != pCurrentBindProxy )
          {
            if ( (_WORD)hStartFragment == 0xFFFF )
              hStartFragment = m_hNextRender;
            goto LABEL_97;
          }
          v16 = *(__int16 *)(v15 + 6);
          if ( v16 > iHighestRenderOrder )
            iHighestRenderOrder = *(__int16 *)(v15 + 6);
          if ( v16 == iCurrentRenderOrder )
          {
            nVertCount = m_pMemory[v113 / 0x2Cu].m_Element.m_aPrimVerts.m_Size;
            v17 = nVertCount;
            pVert = (const overlayvert_t *)(3 * nVertCount - 6);
            if ( pMesh != nullptr )
            {
              if ( nCurrVertexCount + nVertCount > nMaxVertices || nCurrIndexCount + 3 * nVertCount - 6 > nMaxIndices )
              {
                CIndexBuilder::FastPolygonList(
                  this: &meshBuilder.m_IndexBuilder,
                  startVert: 0,
                  pVertexCount: polyList.m_Memory.m_pMemory,
                  polygonCount: m_Size);
                if ( meshBuilder.m_bGenerateIndices )
                {
                  switch ( meshBuilder.m_Type )
                  {
                    case MATERIAL_LINE_STRIP:
                      m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                      break;
                    case MATERIAL_LINE_LOOP:
                      m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                      break;
                    case MATERIAL_POLYGON:
                      m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                      break;
                    case MATERIAL_QUADS:
                      m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                      break;
                    case MATERIAL_INSTANCED_QUADS:
                      m_nVertexCount = 0;
                      break;
                    default:
                      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                      break;
                  }
                  CIndexBuilder::GenerateIndices(
                    this: &meshBuilder.m_IndexBuilder,
                    primitiveType: meshBuilder.m_Type,
                    nIndexCount: m_nVertexCount);
                }
                meshBuilder.m_pMesh->UnlockMesh(
                  this: meshBuilder.m_pMesh,
                  a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
                  a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
                  a4: &meshBuilder);
                meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
                meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
                meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
                meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                meshBuilder.m_pMesh = nullptr;
                pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                m_Size = 0;
                pMesh = nullptr;
                polyList.m_Size = 0;
                nCurrVertexCount = 0;
                nCurrIndexCount = 0;
              }
              v17 = nVertCount;
            }
            nCurrVertexCount += v17;
            nCurrIndexCount += (int)pVert;
            pVert = m_pMemory[v113 / 0x2Cu].m_Element.m_aPrimVerts.m_Memory.m_pMemory;
            if ( pMesh == nullptr )
            {
              if ( bWireframeFragments || bBoundMaterial )
              {
                v21 = renderQueueHead;
                v20 = pRenderContext;
              }
              else
              {
                v19 = *(void **)(v15 + 144);
                v20 = pRenderContext;
                v21 = renderQueueHead;
                pRenderContext->Bind(this: pRenderContext, a2: renderQueueHead->m_pMaterial, a3: v19);
                v20->BindLightmapPage(this: v20, a2: v21->m_nLightmapPage);
                if ( v21->m_pMaterial->GetPropertyFlag(this: v21->m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP)
                  || (v22 = v21->m_pMaterial->GetPropertyFlag(
                              this: v21->m_pMaterial,
                              a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS),
                      bLightmappedMaterial = false,
                      v22) )
                {
                  bLightmappedMaterial = true;
                }
                bBoundMaterial = true;
              }
              v23 = v20->GetDynamicMesh(this: v20, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
              m_nIndexCount = v21->m_Queue[nSortGroup].m_nIndexCount;
              pMesh = v23;
              if ( m_nIndexCount >= nMaxIndices )
                m_nIndexCount = nMaxIndices;
              v25 = v21->m_Queue[nSortGroup].m_nVertexCount;
              if ( v25 >= nMaxVertices )
                v25 = nMaxVertices;
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: v23,
                type: MATERIAL_TRIANGLES,
                nVertexCount: v25,
                nIndexCount: m_nIndexCount,
                pMeshSettings: nullptr);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            v26 = pVert;
            v27 = nullptr;
            if ( bLightmappedMaterial )
            {
              decalOffset = m_pMemory[v113 / 0x2Cu].m_Element.decalOffset;
              v29 = nVertCount;
              if ( nVertCount >= 4 )
              {
                v30 = ((unsigned int)(nVertCount - 4) >> 2) + 1;
                p_z = &pVert[1].pos.z;
                pVert = (const overlayvert_t *)(4 * v30);
                do
                {
                  *m_pCurrPosition = v26->pos.x;
                  m_pCurrPosition[1] = *(p_z - 14);
                  m_pCurrPosition[2] = *(p_z - 13);
                  m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(p_z - 12);
                  m_pCurrNormal[1] = *(p_z - 11);
                  m_pCurrNormal[2] = *(p_z - 10);
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z - 3);
                  v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(p_z - 9);
                  v33[1] = *(p_z - 8);
                  v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(p_z - 5);
                  v34[1] = *(p_z - 4);
                  v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v35[1] = 0.0;
                  v36 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v36;
                  if ( v36 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v36;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v37 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v37;
                  *v37 = *(p_z - 2);
                  v37[1] = *(p_z - 1);
                  v37[2] = *p_z;
                  v38 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[1];
                  v38[1] = p_z[2];
                  v38[2] = p_z[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 10);
                  v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[4];
                  v39[1] = p_z[5];
                  v40 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[8];
                  v40[1] = p_z[9];
                  v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v41[1] = 0.0;
                  v42 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v42;
                  if ( v42 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v42;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v43 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v43;
                  *v43 = p_z[11];
                  v43[1] = p_z[12];
                  v43[2] = p_z[13];
                  v44 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[14];
                  v44[1] = p_z[15];
                  v44[2] = p_z[16];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 23);
                  v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[17];
                  v45[1] = p_z[18];
                  v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[21];
                  v46[1] = p_z[22];
                  v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v47[1] = 0.0;
                  v48 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v48;
                  if ( v48 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v48;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v49 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v49;
                  *v49 = p_z[24];
                  v49[1] = p_z[25];
                  v49[2] = p_z[26];
                  v50 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[27];
                  v50[1] = p_z[28];
                  v50[2] = p_z[29];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 36);
                  v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[30];
                  v51[1] = p_z[31];
                  v52 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[34];
                  v52[1] = p_z[35];
                  v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v53[1] = 0.0;
                  v54 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v54;
                  if ( v54 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v54;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v26 += 4;
                  p_z += 52;
                  --v30;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v30 != 0 );
                m_Size = polyList.m_Size;
                v27 = pVert;
              }
              if ( (int)v27 < v29 )
              {
                v55 = &v26->pos.z;
                v56 = v29 - (_DWORD)v27;
                do
                {
                  *m_pCurrPosition = *(v55 - 2);
                  m_pCurrPosition[1] = *(v55 - 1);
                  m_pCurrPosition[2] = *v55;
                  v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v55[1];
                  v57[1] = v55[2];
                  v57[2] = v55[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v55 + 10);
                  v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v55[4];
                  v58[1] = v55[5];
                  v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v55[8];
                  v59[1] = v55[9];
                  v60 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v60[1] = 0.0;
                  v61 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v61;
                  if ( v61 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v61;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v55 += 13;
                  --v56;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v56 != 0 );
                goto LABEL_86;
              }
            }
            else
            {
              v62 = nVertCount;
              if ( nVertCount >= 4 )
              {
                v63 = ((unsigned int)(nVertCount - 4) >> 2) + 1;
                v64 = &pVert[1].pos.z;
                pVert = (const overlayvert_t *)(4 * v63);
                do
                {
                  *m_pCurrPosition = v26->pos.x;
                  m_pCurrPosition[1] = *(v64 - 14);
                  m_pCurrPosition[2] = *(v64 - 13);
                  v65 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(v64 - 12);
                  v65[1] = *(v64 - 11);
                  v65[2] = *(v64 - 10);
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 - 3);
                  v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(v64 - 9);
                  v66[1] = *(v64 - 8);
                  v67 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(v64 - 5);
                  v67[1] = *(v64 - 4);
                  v68 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = *(v64 - 7);
                  v68[1] = *(v64 - 6);
                  v69 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v69;
                  if ( v69 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v69;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v70 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v70;
                  *v70 = *(v64 - 2);
                  v70[1] = *(v64 - 1);
                  v70[2] = *v64;
                  v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[1];
                  v71[1] = v64[2];
                  v71[2] = v64[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 10);
                  v72 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[4];
                  v72[1] = v64[5];
                  v73 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[8];
                  v73[1] = v64[9];
                  v74 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[6];
                  v74[1] = v64[7];
                  v75 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v75;
                  if ( v75 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v75;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v76 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v76;
                  *v76 = v64[11];
                  v76[1] = v64[12];
                  v76[2] = v64[13];
                  v77 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[14];
                  v77[1] = v64[15];
                  v77[2] = v64[16];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 23);
                  v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[17];
                  v78[1] = v64[18];
                  v79 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[21];
                  v79[1] = v64[22];
                  v80 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[19];
                  v80[1] = v64[20];
                  v81 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v81;
                  if ( v81 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v81;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v82 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v82;
                  *v82 = v64[24];
                  v82[1] = v64[25];
                  v82[2] = v64[26];
                  v83 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[27];
                  v83[1] = v64[28];
                  v83[2] = v64[29];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 36);
                  v84 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[30];
                  v84[1] = v64[31];
                  v85 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[34];
                  v85[1] = v64[35];
                  v86 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[32];
                  v86[1] = v64[33];
                  v87 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v87;
                  if ( v87 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v87;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v26 += 4;
                  v64 += 52;
                  --v63;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v63 != 0 );
                m_Size = polyList.m_Size;
                v27 = pVert;
              }
              if ( (int)v27 < v62 )
              {
                v88 = &v26->pos.z;
                v89 = v62 - (_DWORD)v27;
                do
                {
                  *m_pCurrPosition = *(v88 - 2);
                  m_pCurrPosition[1] = *(v88 - 1);
                  m_pCurrPosition[2] = *v88;
                  v90 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v88[1];
                  v90[1] = v88[2];
                  v90[2] = v88[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v88 + 10);
                  v91 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v88[4];
                  v91[1] = v88[5];
                  v92 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v88[8];
                  v92[1] = v88[9];
                  v93 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v88[6];
                  v93[1] = v88[7];
                  v94 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v94;
                  if ( v94 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v94;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v88 += 13;
                  --v89;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v89 != 0 );
LABEL_86:
                m_Size = polyList.m_Size;
              }
            }
            v95 = m_Size;
            if ( m_Size + 1 > polyList.m_Memory.m_nAllocationCount )
            {
              pVert = (const overlayvert_t *)(m_Size - polyList.m_Memory.m_nAllocationCount + 1);
              if ( polyList.m_Memory.m_nGrowSize < 0 )
              {
                polyList.m_Memory.m_nGrowSize = polyList.m_Memory.m_nMallocGrowSize;
                if ( polyList.m_Memory.m_nAllocationCount != 0 )
                {
                  v96 = 4 * polyList.m_Memory.m_nAllocationCount;
                  v97 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                             this: _g_pMemAlloc,
                                             a2: 4 * polyList.m_Memory.m_nAllocationCount);
                  memcpy(dst: v97, src: (unsigned __int8 *)polyList.m_Memory.m_pMemory, count: v96);
                  polyList.m_Memory.m_pMemory = (int *)v97;
                }
                else
                {
                  polyList.m_Memory.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&polyList, num: (int)pVert);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            polyList.m_Size = ++m_Size;
            polyList.m_pElements = polyList.m_Memory.m_pMemory;
            if ( m_Size - v95 - 1 > 0 )
            {
              _V_memmove(
                dest: &polyList.m_Memory.m_pMemory[v95 + 1],
                src: &polyList.m_Memory.m_pMemory[v95],
                count: 4 * (m_Size - v95 - 1));
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            v98 = &polyList.m_Memory.m_pMemory[v95];
            if ( v98 != nullptr )
            {
              *v98 = nVertCount;
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
          }
LABEL_97:
          m_pMemory = v114->m_aFragments.m_Memory.m_pMemory;
          m_hNextRender = m_pMemory[v113 / 0x2Cu].m_Element.m_hNextRender;
        }
        while ( m_hNextRender != 0xFFFF );
        v99 = pMesh;
        if ( pMesh != nullptr )
        {
          CIndexBuilder::FastPolygonList(
            this: &meshBuilder.m_IndexBuilder,
            startVert: 0,
            pVertexCount: polyList.m_Memory.m_pMemory,
            polygonCount: m_Size);
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v100 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v100 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v100 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v100 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v100 = 0;
                break;
              default:
                v100 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: v100);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          v99->Draw_2(this: v99, a2: -1, a3: 0);
        }
        v101 = polyList.m_Memory.m_pMemory;
        polyList.m_Size = 0;
        if ( polyList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( polyList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: polyList.m_Memory.m_pMemory);
            v101 = nullptr;
            polyList.m_Memory.m_pMemory = nullptr;
          }
          polyList.m_Memory.m_nAllocationCount = 0;
        }
        polyList.m_pElements = v101;
        if ( polyList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v101 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v101);
            polyList.m_Memory.m_pMemory = nullptr;
          }
          polyList.m_Memory.m_nAllocationCount = 0;
        }
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
      }
      while ( (_WORD)hStartFragment != 0xFFFF );
LABEL_124:
      LOWORD(v6) = nNextRenderQueue;
    }
    while ( nNextRenderQueue != 0xFFFF );
LABEL_125:
    if ( ++iCurrentRenderOrder <= iHighestRenderOrder )
    {
      v3 = v114;
      continue;
    }
    break;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100F95C0
// Name: private: bool COverlayMgr::Surf_PreClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::Surf_PreClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag)
{
  float y; // xmm0_4
  float x; // xmm1_4
  overlayvert_t *m_pMemory; // ecx
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  int m_Size; // ebx
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // edi
  overlayvert_t *v45; // ecx
  float z; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float *p_x; // ecx
  float v52; // xmm0_4
  overlayvert_t *v53; // ecx
  float v54; // xmm3_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  float v58; // xmm4_4
  float *v59; // ecx
  float v60; // xmm0_4
  overlayvert_t *v61; // ecx
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  float *v66; // ecx
  float v67; // xmm5_4
  float v68; // xmm0_4
  overlayvert_t *v69; // ecx
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm5_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  float *v75; // ecx
  float v76; // xmm0_4
  int v77; // edx
  int v78; // ebx
  overlayvert_t *v79; // ecx
  float v80; // xmm3_4
  float v81; // xmm2_4
  float v82; // xmm4_4
  float v83; // xmm1_4
  float *v84; // ecx
  float v85; // xmm7_4
  float v86; // xmm0_4
  int iVert; // [esp+1Ch] [ebp+8h]
  float overlayFraga; // [esp+20h] [ebp+Ch]
  float overlayFragb; // [esp+20h] [ebp+Ch]
  float overlayFragc; // [esp+20h] [ebp+Ch]
  float overlayFragd; // [esp+20h] [ebp+Ch]
  float overlayFrage; // [esp+20h] [ebp+Ch]

  overlayFrag->m_aPrimVerts.m_Size = 0;
  CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
    this: &overlayFrag->m_aPrimVerts,
    elem: 0,
    num: 4);
  y = pOverlay->m_vecUVPoints[0].y;
  x = pOverlay->m_vecUVPoints[0].x;
  m_pMemory = overlayFrag->m_aPrimVerts.m_Memory.m_pMemory;
  v9 = pOverlay->m_vecBasis[1].x * y;
  v10 = y * pOverlay->m_vecBasis[1].z;
  v11 = pOverlay->m_vecUVPoints[0].y * pOverlay->m_vecBasis[1].y;
  v12 = (float)(pOverlay->m_vecBasis[0].x * x) + v9;
  v13 = x * pOverlay->m_vecBasis[0].y;
  v14 = x * pOverlay->m_vecBasis[0].z;
  m_pMemory->pos.x = v12;
  v15 = v14 + v10;
  m_pMemory->pos.z = v15;
  v16 = v13 + v11;
  m_pMemory->pos.y = v16;
  m_pMemory->pos.x = v12 + pOverlay->m_vecOrigin.x;
  m_pMemory->pos.y = v16 + pOverlay->m_vecOrigin.y;
  m_pMemory->pos.z = pOverlay->m_vecOrigin.z + v15;
  v17 = pOverlay->m_vecUVPoints[1].y;
  v18 = pOverlay->m_vecUVPoints[1].x;
  v19 = pOverlay->m_vecUVPoints[1].y * pOverlay->m_vecBasis[1].y;
  v20 = pOverlay->m_vecBasis[0].x * v18;
  v21 = pOverlay->m_vecUVPoints[1].x * pOverlay->m_vecBasis[0].y;
  v22 = (float)(v18 * pOverlay->m_vecBasis[0].z) + (float)(v17 * pOverlay->m_vecBasis[1].z);
  m_pMemory[1].pos.x = v20 + (float)(pOverlay->m_vecBasis[1].x * v17);
  m_pMemory[1].pos.y = v21 + v19;
  m_pMemory[1].pos.z = v22;
  m_pMemory[1].pos.x = m_pMemory[1].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[1].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[1].pos.y;
  m_pMemory[1].pos.z = m_pMemory[1].pos.z + pOverlay->m_vecOrigin.z;
  v23 = pOverlay->m_vecUVPoints[2].y;
  v24 = pOverlay->m_vecUVPoints[2].x;
  v25 = pOverlay->m_vecBasis[0].x * v24;
  v26 = pOverlay->m_vecUVPoints[2].x * pOverlay->m_vecBasis[0].y;
  v27 = v24 * pOverlay->m_vecBasis[0].z;
  v28 = pOverlay->m_vecBasis[1].x * v23;
  v29 = pOverlay->m_vecUVPoints[2].y * pOverlay->m_vecBasis[1].y;
  v30 = v23 * pOverlay->m_vecBasis[1].z;
  m_pMemory[2].pos.x = v25 + v28;
  m_pMemory[2].pos.y = v26 + v29;
  m_pMemory[2].pos.z = v27 + v30;
  m_pMemory[2].pos.x = m_pMemory[2].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[2].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[2].pos.y;
  m_pMemory[2].pos.z = m_pMemory[2].pos.z + pOverlay->m_vecOrigin.z;
  v31 = pOverlay->m_vecUVPoints[3].y;
  v32 = pOverlay->m_vecUVPoints[3].x;
  v33 = v31 * pOverlay->m_vecBasis[1].y;
  v34 = pOverlay->m_vecBasis[0].x * v32;
  v35 = v32 * pOverlay->m_vecBasis[0].y;
  v36 = (float)(v32 * pOverlay->m_vecBasis[0].z) + (float)(v31 * pOverlay->m_vecBasis[1].z);
  m_pMemory[3].pos.x = v34 + (float)(pOverlay->m_vecBasis[1].x * v31);
  m_pMemory[3].pos.y = v35 + v33;
  m_pMemory[3].pos.z = v36;
  m_pMemory[3].pos.x = m_pMemory[3].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[3].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[3].pos.y;
  m_pMemory[3].pos.z = m_pMemory[3].pos.z + pOverlay->m_vecOrigin.z;
  v37 = pOverlay->m_flV[0];
  m_pMemory->texCoord[0].x = pOverlay->m_flU[0];
  m_pMemory->texCoord[0].y = v37;
  v38 = pOverlay->m_flV[1];
  m_pMemory[1].texCoord[0].x = pOverlay->m_flU[0];
  m_pMemory[1].texCoord[0].y = v38;
  v39 = pOverlay->m_flV[1];
  m_pMemory[2].texCoord[0].x = pOverlay->m_flU[1];
  m_pMemory[2].texCoord[0].y = v39;
  v40 = pOverlay->m_flV[0];
  m_pMemory[3].texCoord[0].x = pOverlay->m_flU[1];
  m_pMemory[3].texCoord[0].y = v40;
  m_pMemory->texCoord[1].x = 0.0;
  m_pMemory->texCoord[1].y = 0.0;
  m_pMemory[1].texCoord[1].x = 0.0;
  m_pMemory[1].texCoord[1].y = 1.0;
  m_pMemory[2].texCoord[1].x = 1.0;
  m_pMemory[2].texCoord[1].y = 1.0;
  m_pMemory[3].texCoord[1].x = 1.0;
  m_pMemory[3].texCoord[1].y = 0.0;
  m_Size = surfaceFrag->m_aPrimVerts.m_Size;
  v42 = 0;
  if ( m_Size >= 4 )
  {
    v43 = 0;
    v44 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    iVert = 4 * v44;
    do
    {
      v45 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      z = v45[v43].pos.z;
      v47 = v45[v43].pos.x;
      v48 = v45[v43].pos.y;
      v49 = pOverlay->m_vecBasis[2].x;
      v50 = pOverlay->m_vecBasis[2].y;
      p_x = &v45[v43].pos.x;
      overlayFraga = pOverlay->m_vecBasis[2].z;
      v52 = (float)((float)(v49 * (float)(v47 - pOverlay->m_vecOrigin.x))
                  + (float)(v50 * (float)(v48 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFraga * (float)(z - pOverlay->m_vecOrigin.z));
      *p_x = v47 - (float)(v49 * v52);
      p_x[1] = v48 - (float)(v50 * v52);
      p_x[2] = z - (float)(overlayFraga * v52);
      v53 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v54 = v53[v43 + 1].pos.z;
      v55 = v53[v43 + 1].pos.x;
      v56 = v53[v43 + 1].pos.y;
      v57 = pOverlay->m_vecBasis[2].x;
      v58 = pOverlay->m_vecBasis[2].y;
      v59 = &v53[v43 + 1].pos.x;
      overlayFragb = pOverlay->m_vecBasis[2].z;
      v60 = (float)((float)(v57 * (float)(v55 - pOverlay->m_vecOrigin.x))
                  + (float)(v58 * (float)(v56 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragb * (float)(v54 - pOverlay->m_vecOrigin.z));
      *v59 = v55 - (float)(v57 * v60);
      v59[1] = v56 - (float)(v58 * v60);
      v59[2] = v54 - (float)(overlayFragb * v60);
      v61 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v62 = v61[v43 + 2].pos.z;
      v63 = v61[v43 + 2].pos.x;
      v64 = v61[v43 + 2].pos.y;
      v65 = pOverlay->m_vecBasis[2].y;
      v66 = &v61[v43 + 2].pos.x;
      v67 = pOverlay->m_vecBasis[2].x;
      overlayFragc = pOverlay->m_vecBasis[2].z;
      v68 = (float)((float)(v67 * (float)(v63 - pOverlay->m_vecOrigin.x))
                  + (float)(v65 * (float)(v64 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragc * (float)(v62 - pOverlay->m_vecOrigin.z));
      *v66 = v63 - (float)(v67 * v68);
      v66[1] = v64 - (float)(v65 * v68);
      v66[2] = v62 - (float)(overlayFragc * v68);
      v69 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v70 = v69[v43 + 3].pos.z;
      v71 = v69[v43 + 3].pos.x;
      v72 = pOverlay->m_vecBasis[2].x;
      v73 = v69[v43 + 3].pos.y;
      v74 = pOverlay->m_vecBasis[2].y;
      v75 = &v69[v43 + 3].pos.x;
      overlayFragd = pOverlay->m_vecBasis[2].z;
      v76 = (float)((float)(v72 * (float)(v71 - pOverlay->m_vecOrigin.x))
                  + (float)(v74 * (float)(v73 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragd * (float)(v70 - pOverlay->m_vecOrigin.z));
      *v75 = v71 - (float)(v72 * v76);
      v43 += 4;
      --v44;
      v75[1] = v73 - (float)(v74 * v76);
      v75[2] = v70 - (float)(overlayFragd * v76);
    }
    while ( v44 != 0 );
    v42 = iVert;
  }
  if ( v42 < m_Size )
  {
    v77 = v42;
    v78 = m_Size - v42;
    do
    {
      v79 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v80 = v79[v77].pos.z;
      v81 = v79[v77].pos.y;
      v82 = pOverlay->m_vecBasis[2].y;
      v83 = v79[v77].pos.x;
      v84 = &v79[v77].pos.x;
      overlayFrage = pOverlay->m_vecBasis[2].z;
      v85 = pOverlay->m_vecBasis[2].x;
      v86 = (float)((float)(v82 * (float)(v81 - pOverlay->m_vecOrigin.y))
                  + (float)(v85 * (float)(v83 - pOverlay->m_vecOrigin.x)))
          + (float)(overlayFrage * (float)(v80 - pOverlay->m_vecOrigin.z));
      ++v77;
      --v78;
      *v84 = v83 - (float)(v85 * v86);
      v84[1] = v81 - (float)(v82 * v86);
      v84[2] = v80 - (float)(overlayFrage * v86);
    }
    while ( v78 != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F9EF0
// Name: private: int COverlayMgr::GetMaterialSortID(class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COverlayMgr::GetMaterialSortID(COverlayMgr *this, IMaterial *pMaterial, int nLightmapPage)
{
  int result; // eax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // esi
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *p_m_RenderQueue; // ebx
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // si
  unsigned __int16 v8; // ax
  int v9; // esi
  int v10; // eax

  LOWORD(result) = this->m_RenderQueue.m_Head;
  if ( (_WORD)result == 0xFFFF )
  {
LABEL_6:
    p_m_RenderQueue = &this->m_RenderQueue;
    v6 = CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_RenderQueue,
           multilist: false);
    v7 = v6;
    if ( v6 == 0xFFFF )
    {
      v8 = -1;
    }
    else
    {
      CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_RenderQueue,
        before: 0xFFFFu,
        elem: v6);
      v8 = v7;
    }
    v9 = v8;
    v10 = (int)&p_m_RenderQueue->m_Memory.m_pMemory[v8];
    *(_DWORD *)(v10 + 4) = nLightmapPage;
    *(_WORD *)(v10 + 40) = 1;
    *(_DWORD *)v10 = pMaterial;
    *(_DWORD *)(v10 + 8) = -1;
    *(_DWORD *)(v10 + 16) = -1;
    *(_DWORD *)(v10 + 12) = 0;
    *(_DWORD *)(v10 + 20) = 0;
    *(_DWORD *)(v10 + 24) = -1;
    *(_DWORD *)(v10 + 28) = 0;
    *(_DWORD *)(v10 + 32) = -1;
    *(_DWORD *)(v10 + 36) = 0;
    pMaterial->IncrementReferenceCount(this: pMaterial);
    return v9;
  }
  else
  {
    m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
    while ( m_pMemory[(unsigned __int16)result].m_Element.m_pMaterial != pMaterial
         || m_pMemory[(unsigned __int16)result].m_Element.m_nLightmapPage != nLightmapPage )
    {
      LOWORD(result) = m_pMemory[(unsigned __int16)result].m_Next;
      if ( (_WORD)result == 0xFFFF )
        goto LABEL_6;
    }
    result = (unsigned __int16)result;
    ++m_pMemory[(unsigned __int16)result].m_Element.m_nRefCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F9FE0
// Name: public: virtual void COverlayMgr::ReSortMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ReSortMaterials(COverlayMgr *this)
{
  int m_Size; // eax
  moverlay_t *v3; // eax
  int m_nTexInfo; // ecx
  bool v5; // zf
  mtexinfo_t *v6; // ecx
  int j; // eax
  int v8; // edi
  int v9; // esi
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v10; // esi
  unsigned __int16 MaterialSortID; // ax
  msurface2_t *m_SurfId; // edx
  int v13; // edi
  SurfaceCtx_t ctx; // [esp+Ch] [ebp-40h] BYREF
  Vector2D uv; // [esp+30h] [ebp-1Ch] BYREF
  int v16; // [esp+38h] [ebp-14h]
  int i; // [esp+3Ch] [ebp-10h]
  mtexinfo_t *pTexInfo; // [esp+40h] [ebp-Ch]
  int v19; // [esp+44h] [ebp-8h]
  unsigned int v20; // [esp+48h] [ebp-4h]

  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderQueue);
  if ( this->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderQueue.m_Memory.m_pMemory);
      this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RenderQueue.m_FirstFree = -1;
  this->m_RenderQueue.m_pElements = this->m_RenderQueue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_RenderQueue.m_NumAlloced = -65536;
  *(_DWORD *)this->m_nFirstRenderQueue = -1;
  *(_DWORD *)&this->m_nFirstRenderQueue[2] = -1;
  m_Size = this->m_aOverlays.m_Size;
  if ( m_Size > 0 )
  {
    v20 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v3 = &this->m_aOverlays.m_Memory.m_pMemory[v20 / 0xA8];
      if ( v3 != nullptr )
      {
        m_nTexInfo = v3->m_nTexInfo;
        v5 = &host_state.worldbrush->texinfo[m_nTexInfo] == nullptr;
        v6 = &host_state.worldbrush->texinfo[m_nTexInfo];
        pTexInfo = v6;
        if ( !v5 )
        {
          for ( j = v3->m_hFirstFragment;
                j != 0xFFFF;
                j = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Next + v8) )
          {
            v8 = 6 * (unsigned __int16)j;
            v9 = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Element + v8);
            v5 = &this->m_aFragments.m_Memory.m_pMemory[v9] == nullptr;
            v10 = &this->m_aFragments.m_Memory.m_pMemory[v9];
            v16 = v8;
            if ( !v5 )
            {
              MaterialSortID = COverlayMgr::GetMaterialSortID(
                                 this,
                                 pMaterial: v6->material,
                                 nLightmapPage: materialSortInfoArray[v10->m_Element.m_SurfId->materialSortID].lightmapPageID);
              m_SurfId = v10->m_Element.m_SurfId;
              v10->m_Element.m_nMaterialSortID = MaterialSortID;
              SurfSetupSurfaceContext(&ctx, surfID: m_SurfId);
              if ( v10->m_Element.m_aPrimVerts.m_Size > 0 )
              {
                v13 = 0;
                v19 = v10->m_Element.m_aPrimVerts.m_Size;
                do
                {
                  SurfComputeLightmapCoordinate(
                    &ctx,
                    surfID: v10->m_Element.m_SurfId,
                    vec: &v10->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v13].pos,
                    &uv);
                  *(Vector2D *)v10->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v13++].lightCoord = uv;
                  --v19;
                }
                while ( v19 != 0 );
                v8 = v16;
              }
              v6 = pTexInfo;
            }
          }
        }
      }
      v20 += 168;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA160
// Name: private: unsigned short COverlayMgr::AddFragmentToFragmentList(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall COverlayMgr::AddFragmentToFragmentList(COverlayMgr *this, int nSize)
{
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *p_m_aFragments; // edi
  int v3; // ecx
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v5; // eax
  unsigned __int16 v6; // si
  int v7; // eax

  p_m_aFragments = &this->m_aFragments;
  v3 = CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_aFragments,
         multilist: true);
  v4 = -1;
  if ( (_WORD)v3 != 0xFFFF )
  {
    v5 = &p_m_aFragments->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v5->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v5->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v5->m_Element.m_aPrimVerts.m_Size = 0;
      v5->m_Element.m_aPrimVerts.m_pElements = nullptr;
    }
    v4 = v3;
  }
  v6 = v4;
  v7 = (int)&p_m_aFragments->m_Memory.m_pMemory[v4];
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = -1;
  *(_DWORD *)v7 = -1;
  *(_DWORD *)(v7 + 12) = -1;
  if ( nSize > 0 )
  {
    *(_DWORD *)(v7 + 28) = 0;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)(v7 + 16),
      elem: 0,
      num: nSize);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100FA1E0
// Name: public: virtual void COverlayMgr::UnloadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::UnloadOverlays(COverlayMgr *this)
{
  COverlayMgr *v1; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // ecx
  int v4; // edi
  int i; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v6; // edx
  unsigned int v7; // edi
  int m_Element; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v9; // esi
  bool v10; // sf
  overlayvert_t *v11; // eax
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]

  v1 = this;
  m_Head = this->m_RenderQueue.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Head;
      m_pMemory[(unsigned __int16)m_Head].m_Element.m_pMaterial->DecrementReferenceCount(this: m_pMemory[(unsigned __int16)m_Head].m_Element.m_pMaterial);
      m_pMemory = v1->m_RenderQueue.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  if ( v1->m_aOverlays.m_Size > 0 )
  {
    v13 = 0;
    m_Size = v1->m_aOverlays.m_Size;
    do
    {
      for ( i = v1->m_aOverlays.m_Memory.m_pMemory[v13].m_hFirstFragment; i != 0xFFFF; v1 = this )
      {
        v6 = v1->m_OverlayFragments.m_Memory.m_pMemory;
        v7 = (unsigned __int16)i;
        m_Element = v6[v7].m_Element;
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
          this: &v1->m_aFragments,
          elem: v6[v7].m_Element);
        v9 = &this->m_aFragments.m_Memory.m_pMemory[m_Element];
        v10 = v9->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
        v9->m_Element.m_aPrimVerts.m_Size = 0;
        if ( !v10 )
        {
          if ( v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory);
            v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
          }
          v9->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
        }
        v10 = v9->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
        v11 = v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
        v9->m_Element.m_aPrimVerts.m_pElements = v11;
        if ( !v10 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
          }
          v9->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
        }
        v9->m_Next = this->m_aFragments.m_FirstFree;
        this->m_aFragments.m_FirstFree = m_Element;
        i = this->m_OverlayFragments.m_Memory.m_pMemory[v7].m_Next;
      }
      ++v13;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::RemoveAll(this: &v1->m_aOverlays);
  if ( v1->m_aOverlays.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_aOverlays.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_aOverlays.m_Memory.m_pMemory);
      v1->m_aOverlays.m_Memory.m_pMemory = nullptr;
    }
    v1->m_aOverlays.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_aOverlays.m_pElements = v1->m_aOverlays.m_Memory.m_pMemory;
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_aFragments);
  if ( v1->m_aFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_aFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_aFragments.m_Memory.m_pMemory);
      v1->m_aFragments.m_Memory.m_pMemory = nullptr;
    }
    v1->m_aFragments.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_aFragments.m_FirstFree = -1;
  v1->m_aFragments.m_pElements = v1->m_aFragments.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_aFragments.m_NumAlloced = -65536;
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_OverlayFragments);
  if ( v1->m_OverlayFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_OverlayFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_OverlayFragments.m_Memory.m_pMemory);
      v1->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
    }
    v1->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_OverlayFragments.m_FirstFree = -1;
  v1->m_OverlayFragments.m_pElements = v1->m_OverlayFragments.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_OverlayFragments.m_NumAlloced = -65536;
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_RenderQueue);
  if ( v1->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_RenderQueue.m_Memory.m_pMemory);
      v1->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    v1->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_RenderQueue.m_FirstFree = -1;
  v1->m_RenderQueue.m_pElements = v1->m_RenderQueue.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_RenderQueue.m_NumAlloced = -65536;
  *(_DWORD *)v1->m_nFirstRenderQueue = -1;
  *(_DWORD *)&v1->m_nFirstRenderQueue[2] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA420
// Name: private: void COverlayMgr::Surf_PostClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_PostClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID)
{
  int m_Size; // eax
  unsigned __int16 v6; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v8; // ebx
  overlayvert_t *v10; // edi
  _DWORD *p_z; // eax
  int j; // ecx
  float y; // xmm0_4
  float x; // xmm7_4
  float v15; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm7_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float v35; // xmm7_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  int v44; // edi
  cplane_t *plane; // eax
  float v46; // xmm2_4
  float v47; // xmm4_4
  float v48; // xmm7_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  int v51; // eax
  float v52; // xmm5_4
  float v53; // xmm4_4
  char *texCoord; // eax
  overlayvert_t *v55; // ecx
  bool v56; // zf
  const Vector *v57; // eax
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float *p_x; // eax
  float v62; // xmm0_4
  COverlayMgr *v63; // ebx
  unsigned __int16 v64; // ax
  int v65; // eax
  unsigned __int16 v66; // cx
  unsigned __int16 m_Tail; // dx
  unsigned __int16 v68; // ax
  unsigned __int16 v69; // cx
  int v70; // edx
  unsigned __int16 v71; // cx
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *v72; // esi
  int m_nFirstOverlayFragment; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v74; // eax
  unsigned __int16 v75; // cx
  unsigned __int16 v76; // ax
  unsigned __int16 v77; // dx
  int v78; // ecx
  bool v79; // sf
  SurfaceCtx_t ctx; // [esp+4h] [ebp-9Ch] BYREF
  Vector2D vecUV; // [esp+28h] [ebp-78h] BYREF
  moverlayfragment_t origOverlay; // [esp+30h] [ebp-70h] BYREF
  Vector2D vecTexCoord; // [esp+58h] [ebp-48h] BYREF
  Vector2D uv; // [esp+60h] [ebp-40h] BYREF
  int v85; // [esp+68h] [ebp-38h]
  Vector vec; // [esp+6Ch] [ebp-34h] BYREF
  float dist; // [esp+78h] [ebp-28h]
  int v88; // [esp+7Ch] [ebp-24h]
  int v89; // [esp+80h] [ebp-20h]
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *p_m_aFragments; // [esp+84h] [ebp-1Ch]
  int v91; // [esp+88h] [ebp-18h]
  COverlayMgr *v92; // [esp+8Ch] [ebp-14h]
  const Vector *vNormal; // [esp+90h] [ebp-10h]
  int m_hFirstFragment; // [esp+94h] [ebp-Ch]
  int hFragment; // [esp+98h] [ebp-8h]
  int nVertCount; // [esp+9Ch] [ebp-4h]
  overlayvert_t *pOverlaya; // [esp+A8h] [ebp+8h]
  moverlay_t *pOverlayb; // [esp+A8h] [ebp+8h]
  unsigned __int16 i; // [esp+ACh] [ebp+Ch]

  m_Size = overlayFrag->m_aPrimVerts.m_Size;
  v92 = this;
  nVertCount = m_Size;
  if ( m_Size != 0 )
  {
    v6 = COverlayMgr::AddFragmentToFragmentList(this, nSize: m_Size);
    m_pMemory = this->m_aFragments.m_Memory.m_pMemory;
    hFragment = v6;
    p_m_aFragments = &this->m_aFragments;
    v89 = 44 * v6;
    v8 = &m_pMemory[v89 / 0x2Cu];
    SurfSetupSurfaceContext(&ctx, surfID);
    v8->m_Element.m_iOverlay = pOverlay->m_nId;
    v8->m_Element.m_SurfId = surfID;
    v8->m_Element.decalOffset = ComputeDecalLightmapOffset(surfID);
    vNormal = &surfID->plane->normal;
    memset(&origOverlay.m_aPrimVerts, 0, sizeof(origOverlay.m_aPrimVerts));
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
      this: (CUtlMemory<SndInfo_t,int> *)&origOverlay.m_aPrimVerts,
      num: 4);
    v10 = origOverlay.m_aPrimVerts.m_Memory.m_pMemory;
    if ( origOverlay.m_aPrimVerts.m_Size > 0 )
      _V_memmove(
        dest: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[4],
        src: origOverlay.m_aPrimVerts.m_Memory.m_pMemory,
        count: 52 * origOverlay.m_aPrimVerts.m_Size);
    p_z = (_DWORD *)&v10->normal.z;
    for ( j = 4; j != 0; --j )
    {
      if ( p_z != (_DWORD *)20 )
      {
        *(p_z - 5) = 0;
        *(p_z - 4) = 0;
        *(p_z - 3) = 0;
        *(p_z - 2) = 0;
        *(p_z - 1) = 0;
        *p_z = 0;
        p_z[1] = 0;
        p_z[2] = 0;
        p_z[3] = 0;
        p_z[4] = 0;
        p_z[6] = 0;
        p_z[5] = 0;
        p_z[7] = -1;
      }
      p_z += 13;
    }
    y = pOverlay->m_vecUVPoints[0].y;
    x = pOverlay->m_vecUVPoints[0].x;
    v15 = pOverlay->m_vecBasis[0].y;
    z = pOverlay->m_vecBasis[0].z;
    v17 = pOverlay->m_vecBasis[1].y * y;
    v18 = pOverlay->m_vecBasis[1].z * y;
    v19 = (float)(pOverlay->m_vecBasis[0].x * x) + (float)(pOverlay->m_vecBasis[1].x * y);
    v10->pos.x = v19;
    v20 = (float)(v15 * x) + v17;
    v10->pos.y = v20;
    v21 = (float)(z * x) + v18;
    v10->pos.z = v21;
    v10->pos.x = pOverlay->m_vecOrigin.x + v19;
    v10->pos.y = v20 + pOverlay->m_vecOrigin.y;
    v10->pos.z = pOverlay->m_vecOrigin.z + v21;
    v22 = pOverlay->m_vecUVPoints[1].y;
    v23 = pOverlay->m_vecUVPoints[1].x;
    v24 = pOverlay->m_vecBasis[0].y;
    v25 = pOverlay->m_vecBasis[0].z;
    v26 = pOverlay->m_vecBasis[1].y * v22;
    v27 = pOverlay->m_vecBasis[1].z * v22;
    v10[1].pos.x = (float)(pOverlay->m_vecBasis[0].x * v23) + (float)(pOverlay->m_vecBasis[1].x * v22);
    v10[1].pos.y = (float)(v24 * v23) + v26;
    v10[1].pos.z = (float)(v25 * v23) + v27;
    v10[1].pos.x = pOverlay->m_vecOrigin.x + v10[1].pos.x;
    v10[1].pos.y = v10[1].pos.y + pOverlay->m_vecOrigin.y;
    v10[1].pos.z = pOverlay->m_vecOrigin.z + v10[1].pos.z;
    v28 = pOverlay->m_vecUVPoints[2].y;
    v29 = pOverlay->m_vecUVPoints[2].x;
    v30 = pOverlay->m_vecBasis[0].y;
    v31 = pOverlay->m_vecBasis[0].z;
    v32 = pOverlay->m_vecBasis[1].y * v28;
    v33 = pOverlay->m_vecBasis[1].z * v28;
    v10[2].pos.x = (float)(pOverlay->m_vecBasis[0].x * v29) + (float)(pOverlay->m_vecBasis[1].x * v28);
    v10[2].pos.y = (float)(v30 * v29) + v32;
    v10[2].pos.z = (float)(v31 * v29) + v33;
    v10[2].pos.x = pOverlay->m_vecOrigin.x + v10[2].pos.x;
    v10[2].pos.y = v10[2].pos.y + pOverlay->m_vecOrigin.y;
    v10[2].pos.z = pOverlay->m_vecOrigin.z + v10[2].pos.z;
    v34 = pOverlay->m_vecUVPoints[3].y;
    v35 = pOverlay->m_vecUVPoints[3].x;
    v36 = pOverlay->m_vecBasis[0].y;
    v37 = pOverlay->m_vecBasis[0].z;
    v38 = pOverlay->m_vecBasis[1].y * v34;
    v39 = pOverlay->m_vecBasis[1].z * v34;
    v10[3].pos.x = (float)(pOverlay->m_vecBasis[0].x * v35) + (float)(pOverlay->m_vecBasis[1].x * v34);
    v10[3].pos.y = (float)(v36 * v35) + v38;
    v10[3].pos.z = (float)(v37 * v35) + v39;
    v10[3].pos.x = pOverlay->m_vecOrigin.x + v10[3].pos.x;
    v10[3].pos.y = v10[3].pos.y + pOverlay->m_vecOrigin.y;
    v10[3].pos.z = pOverlay->m_vecOrigin.z + v10[3].pos.z;
    v40 = pOverlay->m_flV[0];
    v10->texCoord[0].x = pOverlay->m_flU[0];
    v10->texCoord[0].y = v40;
    v41 = pOverlay->m_flV[1];
    v10[1].texCoord[0].x = pOverlay->m_flU[0];
    v10[1].texCoord[0].y = v41;
    v42 = pOverlay->m_flV[1];
    v10[2].texCoord[0].x = pOverlay->m_flU[1];
    v10[2].texCoord[0].y = v42;
    v43 = pOverlay->m_flV[0];
    v10[3].texCoord[0].x = pOverlay->m_flU[1];
    v10[3].texCoord[0].y = v43;
    v10->texCoord[1].x = 0.0;
    v10->texCoord[1].y = 0.0;
    v10[1].texCoord[1].x = 0.0;
    v10[1].texCoord[1].y = 1.0;
    v10[2].texCoord[1].x = 1.0;
    v10[2].texCoord[1].y = 1.0;
    v10[3].texCoord[1].x = 1.0;
    v10[3].texCoord[1].y = 0.0;
    if ( nVertCount > 0 )
    {
      v85 = -104 - (_DWORD)v10;
      m_hFirstFragment = -128 - (_DWORD)v10;
      v44 = 0;
      v91 = nVertCount;
      do
      {
        PointInQuadToBarycentric(
          v1: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory->pos,
          v2: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[3].pos,
          v3: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].pos,
          v4: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[1].pos,
          point: &overlayFrag->m_aPrimVerts.m_Memory.m_pMemory[v44].pos,
          uv: &vecUV);
        nVertCount = (int)&v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44];
        pOverlaya = &overlayFrag->m_aPrimVerts.m_Memory.m_pMemory[v44];
        plane = surfID->plane;
        vec = plane->normal;
        dist = plane->dist;
        v88 = *(_DWORD *)&plane->type;
        VectorNormalize(&vec);
        v46 = pOverlaya->pos.y;
        v47 = pOverlaya->pos.z;
        v48 = pOverlay->m_vecBasis[2].x;
        v49 = (float)((float)(vec.y * pOverlay->m_vecBasis[2].y) + (float)(vec.x * v48))
            + (float)(vec.z * pOverlay->m_vecBasis[2].z);
        if ( v49 == 0.0 )
          v50 = (float)((float)((float)(vec.y * v46) + (float)(vec.x * pOverlaya->pos.x)) + (float)(vec.z * v47)) - dist;
        else
          v50 = (float)(1.0 / v49)
              * (float)((float)((float)((float)(vec.y * v46) + (float)(vec.x * pOverlaya->pos.x)) + (float)(vec.z * v47))
                      - dist);
        v51 = nVertCount;
        v52 = v50 * pOverlay->m_vecBasis[2].y;
        v53 = v47 - (float)(v50 * pOverlay->m_vecBasis[2].z);
        *(float *)nVertCount = pOverlaya->pos.x - (float)(v50 * v48);
        *(float *)(v51 + 4) = v46 - v52;
        *(float *)(v51 + 8) = v53;
        texCoord = (char *)origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].texCoord;
        pOverlayb = (moverlay_t *)origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].texCoord;
        nVertCount = 2;
        while ( 1 )
        {
          TexCoordInQuadFromBarycentric(
            v1: (const Vector2D *)texCoord - 13,
            v2: (const Vector2D *)(texCoord + 52),
            v3: (const Vector2D *)texCoord,
            v4: (const Vector2D *)(texCoord - 52),
            uv: &vecUV,
            texCoord: &vecTexCoord);
          *(int *)((char *)&pOverlayb->m_nId
                 + v44 * 52
                 + v85
                 + (unsigned int)v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory) = LODWORD(vecTexCoord.x);
          v55 = v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
          v56 = nVertCount-- == 1;
          *(float *)((char *)&v55->texCoord[0].y + (_DWORD)pOverlayb + v44 * 52 + m_hFirstFragment) = vecTexCoord.y;
          pOverlayb = (moverlay_t *)((char *)pOverlayb + 8);
          if ( v56 )
            break;
          texCoord = (char *)pOverlayb;
        }
        v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].normal = *vNormal;
        SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].pos, &uv);
        v57 = vNormal;
        *(Vector2D *)v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].lightCoord = uv;
        v58 = v57->x;
        v59 = v57->y;
        v60 = v57->z;
        p_x = &v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].pos.x;
        *p_x = (float)(v58 * 0.1) + *p_x;
        p_x[1] = p_x[1] + (float)(v59 * 0.1);
        v62 = p_x[2];
        ++v44;
        v56 = v91-- == 1;
        p_x[2] = v62 + (float)(v60 * 0.1);
      }
      while ( !v56 );
      v10 = origOverlay.m_aPrimVerts.m_Memory.m_pMemory;
    }
    v8->m_Element.m_nMaterialSortID = COverlayMgr::GetMaterialSortID(
                                        this: v92,
                                        pMaterial: host_state.worldbrush->texinfo[pOverlay->m_nTexInfo].material,
                                        nLightmapPage: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
    v63 = v92;
    v64 = CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
            this: &v92->m_OverlayFragments,
            multilist: true);
    if ( v64 == 0xFFFF )
      i = -1;
    else
      i = v64;
    v63->m_OverlayFragments.m_Memory.m_pMemory[i].m_Element = hFragment;
    m_hFirstFragment = pOverlay->m_hFirstFragment;
    CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
      this: &v63->m_OverlayFragments,
      elem: i);
    v65 = (int)&v63->m_OverlayFragments.m_Memory.m_pMemory[i];
    v66 = m_hFirstFragment;
    *(_WORD *)(v65 + 4) = m_hFirstFragment;
    if ( v66 == 0xFFFF )
    {
      m_Tail = v63->m_OverlayFragments.m_Tail;
      *(_WORD *)(v65 + 2) = m_Tail;
      v68 = i;
      v69 = m_Tail;
      v63->m_OverlayFragments.m_Tail = i;
    }
    else
    {
      v70 = (int)&v63->m_OverlayFragments.m_Memory.m_pMemory[v66];
      v69 = *(_WORD *)(v70 + 2);
      *(_WORD *)(v65 + 2) = v69;
      *(_WORD *)(v70 + 2) = i;
      v68 = i;
    }
    if ( v69 == 0xFFFF )
      v63->m_OverlayFragments.m_Head = v68;
    else
      v63->m_OverlayFragments.m_Memory.m_pMemory[v69].m_Next = v68;
    ++v63->m_OverlayFragments.m_ElementCount;
    v71 = hFragment;
    pOverlay->m_hFirstFragment = v68;
    v72 = p_m_aFragments;
    m_nFirstOverlayFragment = surfID->m_nFirstOverlayFragment;
    CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_aFragments,
      elem: v71);
    v74 = &v72->m_Memory.m_pMemory[v89 / 0x2Cu];
    v74->m_Next = m_nFirstOverlayFragment;
    if ( (_WORD)m_nFirstOverlayFragment == 0xFFFF )
    {
      v75 = v72->m_Tail;
      v74->m_Previous = v75;
      v76 = hFragment;
      v77 = v75;
      v72->m_Tail = hFragment;
    }
    else
    {
      v78 = (int)&v72->m_Memory.m_pMemory[m_nFirstOverlayFragment];
      v77 = *(_WORD *)(v78 + 40);
      v74->m_Previous = v77;
      *(_WORD *)(v78 + 40) = hFragment;
      v76 = hFragment;
    }
    if ( v77 == 0xFFFF )
      v72->m_Head = v76;
    else
      v72->m_Memory.m_pMemory[v77].m_Next = v76;
    ++v72->m_ElementCount;
    v79 = origOverlay.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
    surfID->m_nFirstOverlayFragment = v76;
    if ( !v79 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FABF0
// Name: private: void COverlayMgr::Disp_PostClipFragment(class CDispInfo __near *,class CMeshReader __near *,struct moverlay_t __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_PostClipFragment(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        moverlay_t *pOverlay,
        CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragments,
        msurface2_t *surfID)
{
  int firstvertindex; // esi
  overlayvert_t *m_pMemory; // ebx
  _DWORD *p_z; // eax
  int i; // ecx
  mvertex_t *v10; // eax
  mvertex_t *v11; // eax
  mvertex_t *v12; // eax
  mvertex_t *v13; // eax
  double z; // st7
  const CPowerInfo *m_pPowerInfo; // eax
  int m_SideLength; // edi
  Vector2D *v17; // edx
  int v18; // esi
  int v19; // ecx
  float v20; // xmm0_4
  int v21; // ecx
  int m_Size; // eax
  int v23; // ecx
  moverlayfragment_t *v24; // edx
  int v25; // edx
  COverlayMgr *v26; // esi
  unsigned __int16 v27; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v28; // edi
  int v29; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v30; // edi
  double v31; // st7
  bool v32; // cc
  int v33; // esi
  float x; // xmm0_4
  float v35; // xmm1_4
  float y; // xmm2_4
  moverlayfragment_t *v37; // edx
  overlayvert_t *v38; // eax
  overlayvert_t *v39; // ecx
  overlayvert_t *v40; // edx
  overlayvert_t *v41; // ecx
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_OverlayFragments; // edi
  unsigned __int16 v43; // ax
  unsigned __int16 v44; // si
  char *v45; // eax
  unsigned __int16 v46; // cx
  unsigned __int16 m_Tail; // dx
  unsigned __int16 v48; // cx
  int v49; // edx
  unsigned __int16 v50; // dx
  COverlayMgr *v51; // edi
  int m_nFirstOverlayFragment; // esi
  char *v53; // eax
  unsigned __int16 v54; // cx
  unsigned __int16 v55; // ax
  unsigned __int16 v56; // dx
  int v57; // ecx
  SurfaceCtx_t ctx; // [esp+4h] [ebp-98h] BYREF
  moverlayfragment_t surfaceFrag; // [esp+28h] [ebp-74h] BYREF
  Vector2D uv; // [esp+50h] [ebp-4Ch] BYREF
  Vector2D lightCoords[4]; // [esp+58h] [ebp-44h] BYREF
  int nFragCount; // [esp+78h] [ebp-24h]
  int v63; // [esp+7Ch] [ebp-20h]
  Vector2D vecTmpUV; // [esp+80h] [ebp-1Ch] BYREF
  int iFrag; // [esp+88h] [ebp-14h]
  COverlayMgr *v66; // [esp+8Ch] [ebp-10h]
  moverlayfragment_t *pDispFragment; // [esp+90h] [ebp-Ch]
  int hFragment; // [esp+94h] [ebp-8h]
  int nVertCount; // [esp+98h] [ebp-4h]

  v66 = this;
  if ( aDispFragments->m_Size != 0 )
  {
    SurfSetupSurfaceContext(&ctx, surfID);
    firstvertindex = surfID->firstvertindex;
    memset(&surfaceFrag.m_aPrimVerts, 0, sizeof(surfaceFrag.m_aPrimVerts));
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
      this: (CUtlMemory<SndInfo_t,int> *)&surfaceFrag.m_aPrimVerts,
      num: 4);
    m_pMemory = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
    surfaceFrag.m_aPrimVerts.m_Size += 4;
    surfaceFrag.m_aPrimVerts.m_pElements = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
    if ( surfaceFrag.m_aPrimVerts.m_Size - 4 > 0 )
      _V_memmove(
        dest: &surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory[4],
        src: surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory,
        count: 52 * (surfaceFrag.m_aPrimVerts.m_Size - 4));
    p_z = (_DWORD *)&m_pMemory->normal.z;
    for ( i = 4; i != 0; --i )
    {
      if ( p_z != (_DWORD *)20 )
      {
        *(p_z - 5) = 0;
        *(p_z - 4) = 0;
        *(p_z - 3) = 0;
        *(p_z - 2) = 0;
        *(p_z - 1) = 0;
        *p_z = 0;
        p_z[1] = 0;
        p_z[2] = 0;
        p_z[3] = 0;
        p_z[4] = 0;
        p_z[6] = 0;
        p_z[5] = 0;
        p_z[7] = -1;
      }
      p_z += 13;
    }
    v10 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
    m_pMemory->pos.x = v10->position.x;
    m_pMemory->pos.y = v10->position.y;
    m_pMemory->pos.z = v10->position.z;
    v11 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 1]];
    m_pMemory[1].pos.x = v11->position.x;
    m_pMemory[1].pos.y = v11->position.y;
    m_pMemory[1].pos.z = v11->position.z;
    v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 2]];
    m_pMemory[2].pos.x = v12->position.x;
    m_pMemory[2].pos.y = v12->position.y;
    m_pMemory[2].pos.z = v12->position.z;
    v13 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 3]];
    m_pMemory[3].pos.x = v13->position.x;
    m_pMemory[3].pos.y = v13->position.y;
    z = v13->position.z;
    m_pPowerInfo = pDisp->m_pPowerInfo;
    m_pMemory[3].pos.z = z;
    m_SideLength = m_pPowerInfo->m_SideLength;
    v17 = (Vector2D *)pReader->m_pTexCoord[1];
    v18 = pReader->m_VertexSize_TexCoord[1];
    v19 = v18 * (m_SideLength - 1);
    lightCoords[0] = *v17;
    lightCoords[1].x = *(float *)((char *)&v17->x + v19);
    v20 = *(float *)((char *)&v17->y + v19);
    v21 = m_SideLength * v19;
    lightCoords[1].y = v20;
    lightCoords[2] = *(Vector2D *)((char *)v17 + v18 * (m_SideLength * m_SideLength - 1));
    lightCoords[3].x = *(float *)((char *)&v17->x + v21);
    m_Size = aDispFragments->m_Size;
    lightCoords[3].y = *(float *)((char *)&v17->y + v21);
    nFragCount = m_Size;
    v23 = 0;
    for ( iFrag = 0; v23 < m_Size; iFrag = v23 )
    {
      v24 = aDispFragments->m_Memory.m_pMemory[v23];
      pDispFragment = v24;
      if ( v24 != nullptr )
      {
        v25 = v24->m_aPrimVerts.m_Size;
        nVertCount = v25;
        if ( v25 >= 3 )
        {
          v26 = v66;
          v27 = COverlayMgr::AddFragmentToFragmentList(this: v66, nSize: v25);
          v28 = v26->m_aFragments.m_Memory.m_pMemory;
          hFragment = v27;
          v29 = v27;
          v30 = &v28[v29];
          v63 = v29 * 44;
          v30->m_Element.m_iOverlay = pOverlay->m_nId;
          v30->m_Element.m_SurfId = surfID;
          v31 = ComputeDecalLightmapOffset(surfID);
          v32 = nVertCount <= 0;
          v30->m_Element.decalOffset = v31;
          if ( !v32 )
          {
            v33 = 0;
            do
            {
              x = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory[v33].pos.x;
              v35 = 0.0;
              vecTmpUV.x = x;
              y = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory[v33].pos.y;
              if ( x >= 0.0 )
              {
                if ( x > 1.0 )
                  x = 1.0;
              }
              else
              {
                x = 0.0;
              }
              vecTmpUV.x = x;
              if ( y >= 0.0 )
              {
                if ( y <= 1.0 )
                  v35 = y;
                else
                  v35 = 1.0;
              }
              vecTmpUV.y = v35;
              Overlay_DispUVToWorld(
                pDisp,
                pReader,
                vecUV: &vecTmpUV,
                vecWorld: &v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33].pos,
                vecWorldNormal: &v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33].normal,
                &surfaceFrag);
              v37 = pDispFragment;
              v38 = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory;
              v39 = v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v39[v33].texCoord[0].x = v38[v33].texCoord[0].x;
              v39[v33].texCoord[0].y = v38[v33].texCoord[0].y;
              v40 = v37->m_aPrimVerts.m_Memory.m_pMemory;
              v41 = v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v41[v33].texCoord[1].x = v40[v33].texCoord[1].x;
              v41[v33].texCoord[1].y = v40[v33].texCoord[1].y;
              TexCoordInQuadFromBarycentric(
                v1: lightCoords,
                v2: &lightCoords[1],
                v3: &lightCoords[2],
                v4: &lightCoords[3],
                uv: &vecTmpUV,
                texCoord: &uv);
              *(Vector2D *)v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33++].lightCoord = uv;
              --nVertCount;
            }
            while ( nVertCount != 0 );
            v26 = v66;
          }
          v30->m_Element.m_nMaterialSortID = COverlayMgr::GetMaterialSortID(
                                               this: v26,
                                               pMaterial: host_state.worldbrush->texinfo[pOverlay->m_nTexInfo].material,
                                               nLightmapPage: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
          p_m_OverlayFragments = &v26->m_OverlayFragments;
          v43 = CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
                  this: &v26->m_OverlayFragments,
                  multilist: true);
          v44 = -1;
          if ( v43 != 0xFFFF )
            v44 = v43;
          p_m_OverlayFragments->m_Memory.m_pMemory[v44].m_Element = hFragment;
          pDispFragment = (moverlayfragment_t *)(6 * v44);
          nVertCount = pOverlay->m_hFirstFragment;
          CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
            this: p_m_OverlayFragments,
            elem: v44);
          v45 = (char *)pDispFragment + (unsigned int)p_m_OverlayFragments->m_Memory.m_pMemory;
          v46 = nVertCount;
          *((_WORD *)v45 + 2) = nVertCount;
          if ( v46 == 0xFFFF )
          {
            m_Tail = p_m_OverlayFragments->m_Tail;
            *((_WORD *)v45 + 1) = m_Tail;
            v48 = m_Tail;
            p_m_OverlayFragments->m_Tail = v44;
          }
          else
          {
            v49 = (int)&p_m_OverlayFragments->m_Memory.m_pMemory[v46];
            v48 = *(_WORD *)(v49 + 2);
            *((_WORD *)v45 + 1) = v48;
            *(_WORD *)(v49 + 2) = v44;
          }
          if ( v48 == 0xFFFF )
            p_m_OverlayFragments->m_Head = v44;
          else
            p_m_OverlayFragments->m_Memory.m_pMemory[v48].m_Next = v44;
          ++p_m_OverlayFragments->m_ElementCount;
          v50 = hFragment;
          v51 = v66;
          pOverlay->m_hFirstFragment = v44;
          m_nFirstOverlayFragment = surfID->m_nFirstOverlayFragment;
          CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
            this: &v51->m_aFragments,
            elem: v50);
          v53 = (char *)v51->m_aFragments.m_Memory.m_pMemory + v63;
          *((_WORD *)v53 + 21) = m_nFirstOverlayFragment;
          if ( (_WORD)m_nFirstOverlayFragment == 0xFFFF )
          {
            v54 = v51->m_aFragments.m_Tail;
            *((_WORD *)v53 + 20) = v54;
            v55 = hFragment;
            v56 = v54;
            v51->m_aFragments.m_Tail = hFragment;
          }
          else
          {
            v57 = (int)&v51->m_aFragments.m_Memory.m_pMemory[m_nFirstOverlayFragment];
            v56 = *(_WORD *)(v57 + 40);
            *((_WORD *)v53 + 20) = v56;
            *(_WORD *)(v57 + 40) = hFragment;
            v55 = hFragment;
          }
          if ( v56 == 0xFFFF )
            v51->m_aFragments.m_Head = v55;
          else
            v51->m_aFragments.m_Memory.m_pMemory[v56].m_Next = v55;
          ++v51->m_aFragments.m_ElementCount;
          v23 = iFrag;
          surfID->m_nFirstOverlayFragment = v55;
          m_Size = nFragCount;
        }
      }
      ++v23;
    }
    if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB100
// Name: private: void COverlayMgr::DoClipFragment(struct moverlayfragment_t __near *,struct cplane_t __near *,struct moverlayfragment_t __near * __near *,struct moverlayfragment_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::DoClipFragment(
        COverlayMgr *this,
        moverlayfragment_t *pFragment,
        cplane_t *pClipPlane,
        moverlayfragment_t **ppFront,
        moverlayfragment_t **ppBack)
{
  int v6; // edi
  int m_Size; // esi
  int v8; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float dist; // xmm4_4
  overlayvert_t *m_pMemory; // edx
  float v14; // xmm0_4
  float v15; // xmm0_4
  moverlayfragment_t *v16; // eax
  cplane_t *v17; // eax
  cplane_t *v18; // esi
  moverlayfragment_t *v19; // eax
  int v20; // esi
  int v21; // eax
  overlayvert_t *p_vert; // edx
  int v23; // eax
  overlayvert_t *v24; // eax
  float v25; // xmm0_4
  int v26; // edx
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  int v31; // [esp-Ch] [ebp-458h]
  float flDists[128]; // [esp+8h] [ebp-444h]
  int nSides[128]; // [esp+208h] [ebp-244h]
  overlayvert_t vert; // [esp+408h] [ebp-44h] BYREF
  int nSideCounts[3]; // [esp+43Ch] [ebp-10h] BYREF
  int nVertCount; // [esp+448h] [ebp-4h]
  moverlayfragment_t *pFragmenta; // [esp+454h] [ebp+8h]
  cplane_t *pClipPlanea; // [esp+458h] [ebp+Ch]

  v6 = 0;
  if ( pFragment == nullptr )
    return;
  m_Size = pFragment->m_aPrimVerts.m_Size;
  v8 = 0;
  memset(nSideCounts, 0, sizeof(nSideCounts));
  if ( m_Size > 0 )
  {
    y = pClipPlane->normal.y;
    x = pClipPlane->normal.x;
    z = pClipPlane->normal.z;
    dist = pClipPlane->dist;
    m_pMemory = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
    do
    {
      v14 = (float)((float)((float)(m_pMemory->pos.y * y) + (float)(x * m_pMemory->pos.x))
                  + (float)(m_pMemory->pos.z * z))
          - dist;
      flDists[v8] = v14;
      if ( v14 <= 0.000099999997 )
      {
        if ( v14 >= -0.000099999997 )
          nSides[v8] = 2;
        else
          nSides[v8] = 1;
      }
      else
      {
        nSides[v8] = 0;
      }
      ++nSideCounts[nSides[v8++]];
      ++m_pMemory;
    }
    while ( v8 < m_Size );
  }
  v15 = flDists[0];
  nSides[v8] = nSides[0];
  flDists[v8] = v15;
  v16 = (moverlayfragment_t *)MemAlloc_Alloc(nSize: 0x28u);
  if ( nSideCounts[0] == 0 )
  {
    if ( v16 != nullptr )
    {
      v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v16->m_aPrimVerts.m_Size = 0;
      v16->m_aPrimVerts.m_pElements = nullptr;
      v16->m_SurfId = pFragment->m_SurfId;
      v16->m_iOverlay = pFragment->m_iOverlay;
      v6 = (int)v16;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
        this: &v16->m_aPrimVerts,
        pArray: pFragment->m_aPrimVerts.m_Memory.m_pMemory,
        size: pFragment->m_aPrimVerts.m_Size);
    }
    *ppBack = (moverlayfragment_t *)v6;
    return;
  }
  if ( nSideCounts[1] == 0 )
  {
    if ( v16 != nullptr )
    {
      v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v16->m_aPrimVerts.m_Size = 0;
      v16->m_aPrimVerts.m_pElements = nullptr;
      v16->m_SurfId = pFragment->m_SurfId;
      v16->m_iOverlay = pFragment->m_iOverlay;
      v6 = (int)v16;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
        this: &v16->m_aPrimVerts,
        pArray: pFragment->m_aPrimVerts.m_Memory.m_pMemory,
        size: pFragment->m_aPrimVerts.m_Size);
    }
    *ppFront = (moverlayfragment_t *)v6;
    return;
  }
  if ( v16 != nullptr )
  {
    v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
    v16->m_aPrimVerts.m_Size = 0;
    v16->m_aPrimVerts.m_pElements = nullptr;
    pFragmenta = v16;
    v16->m_SurfId = nullptr;
    v16->m_iOverlay = -1;
  }
  else
  {
    pFragmenta = nullptr;
  }
  v17 = (cplane_t *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v17 != nullptr )
  {
    *(_DWORD *)&v17->type = 0;
    v17[1].normal.x = 0.0;
    v17[1].normal.y = 0.0;
    v17[1].normal.z = 0.0;
    v17[1].dist = 0.0;
    v18 = v17;
    pClipPlanea = v17;
    v17->normal.y = 0.0;
    v17->normal.z = NAN;
  }
  else
  {
    pClipPlanea = nullptr;
    v18 = nullptr;
  }
  v19 = pFragmenta;
  if ( pFragmenta == nullptr )
  {
    if ( v18 != nullptr )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v18->type);
      free(pMem: v18);
    }
    return;
  }
  if ( v18 == nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&pFragmenta->m_aPrimVerts);
    free(pMem: pFragmenta);
    return;
  }
  nVertCount = pFragment->m_aPrimVerts.m_Size;
  if ( nVertCount <= 0 )
    goto LABEL_40;
  v20 = 0;
  do
  {
    v21 = nSides[v6];
    if ( v21 == 2 )
    {
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: pFragmenta->m_aPrimVerts.m_Size,
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
      p_vert = &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20];
LABEL_37:
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)&pClipPlanea->type,
        elem: LODWORD(pClipPlanea[1].normal.z),
        src: p_vert);
      goto LABEL_38;
    }
    if ( v21 == 1 )
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)&pClipPlanea->type,
        elem: LODWORD(pClipPlanea[1].normal.z),
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
    if ( nSides[v6] == 0 )
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: pFragmenta->m_aPrimVerts.m_Size,
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
    v23 = nSides[v6 + 1];
    if ( v23 != 2 && v23 != nSides[v6] )
    {
      v24 = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
      v25 = flDists[v6] / (float)(flDists[v6] - flDists[v6 + 1]);
      memset(&vert.normal, 0, sizeof(vert.normal));
      vert.lightCoord[1] = 0.0;
      vert.lightCoord[0] = 0.0;
      vert.packedColor = -1;
      v26 = (v6 + 1) % nVertCount;
      v27 = v24[v26].pos.x - v24[v20].pos.x;
      v28 = v24[v26].pos.z - v24[v20].pos.z;
      vert.pos.y = (float)((float)(v24[v26].pos.y - v24[v20].pos.y) * v25) + v24[v20].pos.y;
      vert.texCoord[0].x = (float)((float)(v24[v26].texCoord[0].x - v24[v20].texCoord[0].x) * v25)
                         + v24[v20].texCoord[0].x;
      vert.texCoord[0].y = (float)((float)(v24[v26].texCoord[0].y - v24[v20].texCoord[0].y) * v25)
                         + v24[v20].texCoord[0].y;
      vert.texCoord[1].x = (float)((float)(v24[v26].texCoord[1].x - v24[v20].texCoord[1].x) * v25)
                         + v24[v20].texCoord[1].x;
      v29 = (float)(v28 * v25) + v24[v20].pos.z;
      v30 = (float)((float)(v24[v26].texCoord[1].y - v24[v20].texCoord[1].y) * v25) + v24[v20].texCoord[1].y;
      v31 = pFragmenta->m_aPrimVerts.m_Size;
      vert.pos.x = (float)(v27 * v25) + v24[v20].pos.x;
      vert.pos.z = v29;
      vert.texCoord[1].y = v30;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: v31,
        src: &vert);
      p_vert = &vert;
      goto LABEL_37;
    }
LABEL_38:
    ++v6;
    ++v20;
  }
  while ( v6 < nVertCount );
  v18 = pClipPlanea;
  v19 = pFragmenta;
LABEL_40:
  *ppFront = v19;
  *ppBack = (moverlayfragment_t *)v18;
}

//------------------------------------------------------------------------------
// Address: 0x100FB580
// Name: public: COverlayMgr::COverlayMgr(void)
// Source: json
//------------------------------------------------------------------------------
COverlayMgr *__thiscall COverlayMgr::COverlayMgr(COverlayMgr *this)
{
  this->__vftable = (COverlayMgr_vtbl *)&COverlayMgr::`vftable';
  this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
  this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  this->m_RenderQueue.m_Memory.m_nGrowSize = 0;
  this->m_RenderQueue.m_LastAlloc.index = -1;
  this->m_RenderQueue.m_Head = -1;
  this->m_RenderQueue.m_Tail = -1;
  this->m_RenderQueue.m_FirstFree = -1;
  this->m_RenderQueue.m_ElementCount = 0;
  this->m_RenderQueue.m_NumAlloced = 0;
  this->m_RenderQueue.m_pElements = this->m_RenderQueue.m_Memory.m_pMemory;
  this->m_aOverlays.m_Memory.m_pMemory = nullptr;
  this->m_aOverlays.m_Memory.m_nAllocationCount = 0;
  this->m_aOverlays.m_Memory.m_nGrowSize = 0;
  this->m_aOverlays.m_Size = 0;
  this->m_aOverlays.m_pElements = nullptr;
  this->m_aFragments.m_Memory.m_pMemory = nullptr;
  this->m_aFragments.m_Memory.m_nAllocationCount = 0;
  this->m_aFragments.m_Memory.m_nGrowSize = 0;
  this->m_aFragments.m_LastAlloc.index = -1;
  this->m_aFragments.m_Head = -1;
  this->m_aFragments.m_Tail = -1;
  this->m_aFragments.m_FirstFree = -1;
  this->m_aFragments.m_ElementCount = 0;
  this->m_aFragments.m_NumAlloced = 0;
  this->m_aFragments.m_pElements = this->m_aFragments.m_Memory.m_pMemory;
  this->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
  this->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  this->m_OverlayFragments.m_Memory.m_nGrowSize = 0;
  this->m_OverlayFragments.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_OverlayFragments.m_FirstFree = 0xFFFF;
  this->m_OverlayFragments.m_pElements = this->m_OverlayFragments.m_Memory.m_pMemory;
  this->m_OverlayFragments.m_NumAlloced = 0;
  *(_DWORD *)&this->m_OverlayFragments.m_Head = -1;
  *(_DWORD *)this->m_nFirstRenderQueue = -1;
  *(_DWORD *)&this->m_nFirstRenderQueue[2] = -1;
  this->m_flFadeMin2 = 0.0;
  this->m_flFadeMax2 = 0.0;
  this->m_flFadeDelta2 = 0.0;
  this->m_nCPULevel = -1;
  this->m_nGPULevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB660
// Name: public: COverlayMgr::~COverlayMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::~COverlayMgr(COverlayMgr *this)
{
  this->__vftable = (COverlayMgr_vtbl *)&COverlayMgr::`vftable';
  COverlayMgr::UnloadOverlays(this);
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_OverlayFragments);
  if ( this->m_OverlayFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OverlayFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OverlayFragments.m_Memory.m_pMemory);
      this->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
    }
    this->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_aFragments);
  if ( this->m_aFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aFragments.m_Memory.m_pMemory);
      this->m_aFragments.m_Memory.m_pMemory = nullptr;
    }
    this->m_aFragments.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::~CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>(this: &this->m_aOverlays);
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderQueue);
  if ( this->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderQueue.m_Memory.m_pMemory);
      this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB720
// Name: private: void COverlayMgr::Surf_ClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_ClipFragment(
        COverlayMgr *this,
        moverlayfragment_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag)
{
  moverlayfragment_t *v5; // eax
  moverlayfragment_t *v6; // edi
  moverlayfragment_t *v7; // esi
  cplane_t *m_pMemory; // edi
  int v9; // edx
  overlayvert_t *v10; // eax
  overlayvert_t *v11; // ecx
  overlayvert_t *v12; // ecx
  float x; // ebx
  float *p_x; // eax
  float *v15; // ecx
  overlayvert_t *v16; // eax
  int m_Size; // [esp-4h] [ebp-28h]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > m_ClipPlanes; // [esp+Ch] [ebp-18h] BYREF
  COverlayMgr *v19; // [esp+20h] [ebp-4h]

  v19 = this;
  memset(&m_ClipPlanes, 0, sizeof(m_ClipPlanes));
  COverlayMgr::BuildClipPlanes(
    this,
    surfID,
    surfaceFrag,
    vecBasisNormal: (const Vector *)&pOverlay[3].m_hNextRender,
    (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&m_ClipPlanes);
  v5 = (moverlayfragment_t *)MemAlloc_Alloc(nSize: 0x28u);
  v6 = overlayFrag;
  if ( v5 != nullptr )
  {
    v5->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    v5->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    v5->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
    v5->m_aPrimVerts.m_Size = 0;
    v5->m_aPrimVerts.m_pElements = nullptr;
    v5->m_SurfId = v6->m_SurfId;
    v5->m_iOverlay = v6->m_iOverlay;
    v7 = v5;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
      this: &v5->m_aPrimVerts,
      pArray: v6->m_aPrimVerts.m_Memory.m_pMemory,
      size: v6->m_aPrimVerts.m_Size);
  }
  else
  {
    v7 = nullptr;
  }
  if ( m_ClipPlanes.m_Size > 0 )
  {
    m_pMemory = m_ClipPlanes.m_Memory.m_pMemory;
    for ( surfID = (msurface2_t *)m_ClipPlanes.m_Size; surfID != nullptr; surfID = (msurface2_t *)((char *)surfID - 1) )
    {
      pOverlay = nullptr;
      surfaceFrag = nullptr;
      COverlayMgr::DoClipFragment(
        this: v19,
        pFragment: v7,
        pClipPlane: m_pMemory,
        ppFront: &pOverlay,
        ppBack: &surfaceFrag);
      if ( v7 != nullptr )
      {
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7->m_aPrimVerts);
        free(pMem: v7);
      }
      v7 = nullptr;
      if ( surfaceFrag != nullptr )
        v7 = surfaceFrag;
      if ( pOverlay != nullptr )
      {
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&pOverlay->m_aPrimVerts);
        free(pMem: pOverlay);
      }
      ++m_pMemory;
    }
    v6 = overlayFrag;
  }
  if ( m_ClipPlanes.m_Memory.m_nGrowSize >= 0 && m_ClipPlanes.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ClipPlanes.m_Memory.m_pMemory);
    m_ClipPlanes.m_Memory.m_pMemory = nullptr;
  }
  v6->m_aPrimVerts.m_Size = 0;
  if ( v7 != nullptr )
  {
    m_Size = v7->m_aPrimVerts.m_Size;
    v6->m_aPrimVerts.m_Size = 0;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
      this: &v6->m_aPrimVerts,
      elem: 0,
      num: m_Size);
    overlayFrag = nullptr;
    if ( v7->m_aPrimVerts.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = v7->m_aPrimVerts.m_Memory.m_pMemory;
        v11 = v6->m_aPrimVerts.m_Memory.m_pMemory;
        v11[v9].pos.x = v10[v9].pos.x;
        v11[v9].pos.y = v10[v9].pos.y;
        v11[v9].pos.z = v10[v9].pos.z;
        v12 = v7->m_aPrimVerts.m_Memory.m_pMemory;
        x = v12[v9].texCoord[0].x;
        p_x = &v12[v9].texCoord[0].x;
        v15 = &v6->m_aPrimVerts.m_Memory.m_pMemory[v9].texCoord[0].x;
        *v15 = x;
        v15[1] = p_x[1];
        v15[2] = p_x[2];
        v15[3] = p_x[3];
        ++v9;
        overlayFrag = (moverlayfragment_t *)((char *)overlayFrag + 1);
      }
      while ( (int)overlayFrag < v7->m_aPrimVerts.m_Size );
    }
    v7->m_aPrimVerts.m_Size = 0;
    if ( v7->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v7->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_aPrimVerts.m_Memory.m_pMemory);
        v7->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      }
      v7->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    }
    v16 = v7->m_aPrimVerts.m_Memory.m_pMemory;
    v7->m_aPrimVerts.m_pElements = v16;
    if ( v7->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        v7->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      }
      v7->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v7);
  }
  if ( m_ClipPlanes.m_Memory.m_nGrowSize >= 0 && m_ClipPlanes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ClipPlanes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100FB920
// Name: private: void COverlayMgr::Surf_CreateFragments(struct moverlay_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_CreateFragments(COverlayMgr *this, moverlayfragment_t *pOverlay, msurface2_t *surfID)
{
  int firstvertindex; // ebx
  int flags_high; // eax
  int m_nAllocationCount; // ecx
  overlayvert_t *v6; // edi
  overlayvert_t *m_pMemory; // esi
  int v8; // eax
  int v9; // edi
  _DWORD *p_z; // eax
  int i; // ecx
  mvertex_t *v12; // eax
  mvertex_t *v13; // ecx
  mvertex_t *v14; // edx
  bool v15; // zf
  moverlayfragment_t overlayFrag; // [esp+Ch] [ebp-58h] BYREF
  moverlayfragment_t surfaceFrag; // [esp+34h] [ebp-30h] BYREF
  int v18; // [esp+5Ch] [ebp-8h]
  COverlayMgr *v19; // [esp+60h] [ebp-4h]

  firstvertindex = surfID->firstvertindex;
  flags_high = HIBYTE(surfID->flags);
  v19 = this;
  m_nAllocationCount = 0;
  v6 = nullptr;
  m_pMemory = nullptr;
  v8 = flags_high - 2;
  memset(&overlayFrag.m_aPrimVerts, 0, sizeof(overlayFrag.m_aPrimVerts));
  memset(&surfaceFrag.m_aPrimVerts, 0, sizeof(surfaceFrag.m_aPrimVerts));
  if ( v8 > 0 )
  {
    v9 = 2 * firstvertindex + 4;
    v18 = v8;
    while ( 1 )
    {
      surfaceFrag.m_aPrimVerts.m_Size = 0;
      if ( m_nAllocationCount < 3 )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
          this: (CUtlMemory<SndInfo_t,int> *)&surfaceFrag.m_aPrimVerts,
          num: 3 - m_nAllocationCount);
        m_pMemory = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
      }
      surfaceFrag.m_aPrimVerts.m_Size += 3;
      surfaceFrag.m_aPrimVerts.m_pElements = m_pMemory;
      if ( surfaceFrag.m_aPrimVerts.m_Size - 3 > 0 )
        _V_memmove(dest: &m_pMemory[3], src: m_pMemory, count: 52 * (surfaceFrag.m_aPrimVerts.m_Size - 3));
      p_z = (_DWORD *)&m_pMemory->normal.z;
      for ( i = 3; i != 0; --i )
      {
        if ( p_z != (_DWORD *)20 )
        {
          *(p_z - 5) = 0;
          *(p_z - 4) = 0;
          *(p_z - 3) = 0;
          *(p_z - 2) = 0;
          *(p_z - 1) = 0;
          *p_z = 0;
          p_z[1] = 0;
          p_z[2] = 0;
          p_z[3] = 0;
          p_z[4] = 0;
          p_z[6] = 0;
          p_z[5] = 0;
          p_z[7] = -1;
        }
        p_z += 13;
      }
      v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
      m_pMemory->pos.x = v12->position.x;
      m_pMemory->pos.y = v12->position.y;
      m_pMemory->pos.z = v12->position.z;
      v13 = &host_state.worldbrush->vertexes[*(unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v9 - 2)];
      m_pMemory[1].pos.x = v13->position.x;
      m_pMemory[1].pos.y = v13->position.y;
      m_pMemory[1].pos.z = v13->position.z;
      v14 = &host_state.worldbrush->vertexes[*(unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v9)];
      m_pMemory[2].pos.x = v14->position.x;
      m_pMemory[2].pos.y = v14->position.y;
      m_pMemory[2].pos.z = v14->position.z;
      if ( TriangleArea(v0: &m_pMemory->pos, v1: &m_pMemory[1].pos, v2: &m_pMemory[2].pos) > 1.0
        && COverlayMgr::Surf_PreClipFragment(this: v19, (moverlay_t *)pOverlay, &overlayFrag, surfID, &surfaceFrag) != 0 )
      {
        COverlayMgr::Surf_ClipFragment(this: v19, pOverlay, &overlayFrag, surfID, &surfaceFrag);
        COverlayMgr::Surf_PostClipFragment(this: v19, (moverlay_t *)pOverlay, &overlayFrag, surfID);
      }
      v9 += 2;
      v15 = v18-- == 1;
      surfaceFrag.m_aPrimVerts.m_Size = 0;
      overlayFrag.m_aPrimVerts.m_Size = 0;
      if ( v15 )
        break;
      m_nAllocationCount = surfaceFrag.m_aPrimVerts.m_Memory.m_nAllocationCount;
    }
    v6 = overlayFrag.m_aPrimVerts.m_Memory.m_pMemory;
  }
  if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100FBB80
// Name: public: virtual bool COverlayMgr::LoadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::LoadOverlays(COverlayMgr *this)
{
  signed __int32 v3; // ebx
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int> > *p_m_aOverlays; // esi
  signed __int32 v5; // edi
  char *v6; // eax
  float *v7; // edi
  char *v8; // esi
  unsigned __int16 v9; // dx
  float *v10; // eax
  float *v11; // eax
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v16; // ebx
  int v17; // eax
  float *v18; // edi
  int v19; // eax
  char *v20; // esi
  unsigned __int16 v21; // dx
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  int v25; // eax
  int v26; // ecx
  char *v27; // edx
  int v28; // ecx
  __int16 v29; // ax
  worldbrushdata_t *Map; // eax
  int v31; // ecx
  int v32; // edx
  doverlay_t *v33; // eax
  int v34; // [esp+14h] [ebp-4D4h]
  CMapLoadHelper v35; // [esp+20h] [ebp-4C8h] BYREF
  CMapLoadHelper v36; // [esp+14Ch] [ebp-39Ch] BYREF
  CMapLoadHelper v37; // [esp+274h] [ebp-274h] BYREF
  CMapLoadHelper v38; // [esp+39Ch] [ebp-14Ch] BYREF
  int SamplePosition; // [esp+4C4h] [ebp-24h]
  int v40; // [esp+4C8h] [ebp-20h]
  signed __int32 v41; // [esp+4CCh] [ebp-1Ch]
  int v42; // [esp+4D0h] [ebp-18h]
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int> > *v43; // [esp+4D4h] [ebp-14h]
  int v44; // [esp+4D8h] [ebp-10h]
  int v45; // [esp+4DCh] [ebp-Ch]
  int v46; // [esp+4E0h] [ebp-8h]
  doverlay_t *pOverlayIn; // [esp+4E4h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &v38, lumpToLoad: 0x2Du, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v37, lumpToLoad: 0x32u, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v35.m_nLumpOffset, lumpToLoad: 0x3Cu, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v36, lumpToLoad: 0x3Du, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v38);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v38) % 0x160u != 0
    || (v42 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v37),
        CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v37) % 0x460u != 0)
    || (v45 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v35.m_nLumpOffset),
        (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v35.m_nLumpOffset) & 7) != 0)
    || (v44 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v36),
        (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v36) & 3) != 0) )
  {
    CMapLoadHelper::~CMapLoadHelper(this: &v36);
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v35.m_nLumpOffset);
    CMapLoadHelper::~CMapLoadHelper(this: &v37);
    CMapLoadHelper::~CMapLoadHelper(this: &v38);
    return 0;
  }
  else
  {
    v3 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v38) / 0x160u;
    v41 = v3;
    p_m_aOverlays = &this->m_aOverlays;
    v5 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v37) / 0x460u;
    v40 = v5;
    v43 = p_m_aOverlays;
    CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::RemoveAll(this: p_m_aOverlays);
    CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::InsertMultipleBefore(
      this: p_m_aOverlays,
      elem: p_m_aOverlays->m_Size,
      num: v5 + v3);
    v46 = 0;
    if ( v3 > 0 )
    {
      v6 = (char *)(v44 + 2);
      v44 += 2;
      pOverlayIn = nullptr;
      v7 = (float *)(SamplePosition + 336);
      while ( 1 )
      {
        v8 = (char *)pOverlayIn + (unsigned int)p_m_aOverlays->m_Memory.m_pMemory;
        if ( v6 != (char *)2 )
        {
          v8[164] = *(v6 - 2);
          v8[165] = *(v6 - 1);
          v8[166] = *v6;
          v8[167] = v6[1];
          v44 = (int)(v6 + 4);
        }
        *(_DWORD *)v8 = v46;
        *((_WORD *)v8 + 2) = *((_WORD *)v7 - 166);
        v9 = *((_WORD *)v7 - 165) >> 14;
        *((_WORD *)v8 + 5) = 0;
        *((_WORD *)v8 + 3) = v9;
        if ( v9 >= 4u )
          _Error(a1: "COverlayMgr::LoadOverlays: invalid render order (%d) for an overlay.", (__int16)v9);
        v10 = (float *)v45;
        *((float *)v8 + 8) = *(v7 - 18);
        *((float *)v8 + 9) = *(v7 - 17);
        *((float *)v8 + 10) = *(v7 - 16);
        *((float *)v8 + 11) = *(v7 - 15);
        if ( v10 != nullptr )
        {
          *((float *)v8 + 37) = *v10;
          v11 = v10 + 2;
          v12 = *(v11 - 1);
          v45 = (int)v11;
          *((float *)v8 + 38) = v12;
          *((float *)v8 + 39) = 1.0 / (float)(*(v11 - 1) - *(v11 - 2));
        }
        else
        {
          *((_DWORD *)v8 + 37) = -1082130432;
          *((_DWORD *)v8 + 38) = 0;
          *((_DWORD *)v8 + 39) = 1065353216;
        }
        *((float *)v8 + 24) = *(v7 - 2);
        *((float *)v8 + 25) = *(v7 - 1);
        *((float *)v8 + 26) = *v7;
        *((float *)v8 + 12) = *(v7 - 14);
        *((float *)v8 + 13) = *(v7 - 13);
        *((float *)v8 + 14) = *(v7 - 12);
        *((float *)v8 + 15) = *(v7 - 11);
        *((float *)v8 + 16) = *(v7 - 10);
        *((float *)v8 + 17) = *(v7 - 9);
        *((float *)v8 + 18) = *(v7 - 8);
        *((float *)v8 + 19) = *(v7 - 7);
        *((float *)v8 + 20) = *(v7 - 6);
        *((float *)v8 + 21) = *(v7 - 5);
        *((float *)v8 + 22) = *(v7 - 4);
        *((float *)v8 + 23) = *(v7 - 3);
        *((float *)v8 + 33) = v7[1];
        *((float *)v8 + 34) = v7[2];
        *((float *)v8 + 35) = v7[3];
        v13 = *((float *)v8 + 14);
        v14 = *((float *)v8 + 17);
        v15 = *((float *)v8 + 20);
        *((float *)v8 + 27) = v13;
        *((float *)v8 + 28) = v14;
        *((float *)v8 + 29) = v15;
        if ( v13 == 0.0 && v14 == 0.0 && v15 == 0.0 )
          _Warning(
            a1: "Bad overlay basis at (%f %f %f)!\n",
            *((float *)v8 + 24),
            *((float *)v8 + 25),
            *((float *)v8 + 26));
        *((float *)v8 + 30) = (float)(*((float *)v8 + 29) * *((float *)v8 + 34))
                            - (float)(*((float *)v8 + 35) * *((float *)v8 + 28));
        *((float *)v8 + 31) = (float)(*((float *)v8 + 35) * *((float *)v8 + 27))
                            - (float)(*((float *)v8 + 29) * *((float *)v8 + 33));
        *((float *)v8 + 32) = (float)(*((float *)v8 + 28) * *((float *)v8 + 33))
                            - (float)(*((float *)v8 + 34) * *((float *)v8 + 27));
        VectorNormalize(vec: (Vector *)v8 + 10);
        *((_DWORD *)v8 + 14) = 0;
        *((_DWORD *)v8 + 17) = 0;
        *((_DWORD *)v8 + 20) = 0;
        v16 = 0;
        v34 = *((_WORD *)v7 - 165) & 0x3FFF;
        *((_DWORD *)v8 + 6) = 0;
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)(v8 + 12),
          elem: 0,
          num: v34);
        if ( (*((_WORD *)v7 - 165) & 0x3FFF) != 0 )
        {
          do
          {
            *(_DWORD *)(*((_DWORD *)v8 + 3) + 4 * v16) = &CMapLoadHelper::GetMap(this: &v38)->surfaces2[LODWORD(v7[v16 - 82])];
            ++v16;
          }
          while ( v16 < (*((_WORD *)v7 - 165) & 0x3FFF) );
        }
        pOverlayIn = (doverlay_t *)((char *)pOverlayIn + 168);
        v17 = v46 + 1;
        v7 += 88;
        *((_WORD *)v8 + 4) = -1;
        *((_DWORD *)v8 + 36) = 0;
        p_m_aOverlays = v43;
        v46 = v17;
        if ( v17 >= v41 )
          break;
        v6 = (char *)v44;
      }
      v5 = v40;
      v3 = v41;
    }
    pOverlayIn = nullptr;
    if ( v5 > 0 )
    {
      v18 = (float *)(v42 + 1104);
      v19 = 168 * v3;
      v46 = 168 * v3;
      while ( 1 )
      {
        v20 = (char *)p_m_aOverlays->m_Memory.m_pMemory + v19;
        *(_DWORD *)v20 = (char *)pOverlayIn + v3;
        *((_WORD *)v20 + 2) = *((_WORD *)v18 - 550);
        v21 = *((_WORD *)v18 - 549) >> 14;
        *((_WORD *)v20 + 5) = 0;
        *((_WORD *)v20 + 3) = v21;
        if ( v21 >= 4u )
          _Error(a1: "COverlayMgr::LoadOverlays: invalid render order (%d) for an overlay.", (__int16)v21);
        *((float *)v20 + 8) = *(v18 - 18);
        *((float *)v20 + 9) = *(v18 - 17);
        *((float *)v20 + 10) = *(v18 - 16);
        *((float *)v20 + 11) = *(v18 - 15);
        *((float *)v20 + 24) = *(v18 - 2);
        *((float *)v20 + 25) = *(v18 - 1);
        *((float *)v20 + 26) = *v18;
        *((float *)v20 + 12) = *(v18 - 14);
        *((float *)v20 + 13) = *(v18 - 13);
        *((float *)v20 + 14) = *(v18 - 12);
        *((float *)v20 + 15) = *(v18 - 11);
        *((float *)v20 + 16) = *(v18 - 10);
        *((float *)v20 + 17) = *(v18 - 9);
        *((float *)v20 + 18) = *(v18 - 8);
        *((float *)v20 + 19) = *(v18 - 7);
        *((float *)v20 + 20) = *(v18 - 6);
        *((float *)v20 + 21) = *(v18 - 5);
        *((float *)v20 + 22) = *(v18 - 4);
        *((float *)v20 + 23) = *(v18 - 3);
        *((float *)v20 + 33) = v18[1];
        *((float *)v20 + 34) = v18[2];
        *((float *)v20 + 35) = v18[3];
        v22 = *((float *)v20 + 14);
        v23 = *((float *)v20 + 17);
        v24 = *((float *)v20 + 20);
        *((float *)v20 + 27) = v22;
        *((float *)v20 + 28) = v23;
        *((float *)v20 + 29) = v24;
        if ( v22 == 0.0 && v23 == 0.0 && v24 == 0.0 )
          _Warning(
            a1: "Bad overlay basis at (%f %f %f)!\n",
            *((float *)v20 + 24),
            *((float *)v20 + 25),
            *((float *)v20 + 26));
        *((float *)v20 + 30) = (float)(*((float *)v20 + 29) * *((float *)v20 + 34))
                             - (float)(*((float *)v20 + 35) * *((float *)v20 + 28));
        *((float *)v20 + 31) = (float)(*((float *)v20 + 35) * *((float *)v20 + 27))
                             - (float)(*((float *)v20 + 29) * *((float *)v20 + 33));
        *((float *)v20 + 32) = (float)(*((float *)v20 + 28) * *((float *)v20 + 33))
                             - (float)(*((float *)v20 + 34) * *((float *)v20 + 27));
        VectorNormalize(vec: (Vector *)v20 + 10);
        *((_DWORD *)v20 + 14) = 0;
        *((_DWORD *)v20 + 17) = 0;
        *((_DWORD *)v20 + 20) = 0;
        v25 = *((_WORD *)v18 - 549) & 0x3FFF;
        v42 = v25;
        *((_DWORD *)v20 + 6) = 0;
        if ( v25 != 0 )
        {
          v26 = *((_DWORD *)v20 + 4);
          if ( v25 > v26 )
          {
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)v20 + 1, num: v25 - v26);
            v25 = v42;
          }
          *((_DWORD *)v20 + 6) += v25;
          v27 = *((char **)v20 + 3);
          v28 = *((_DWORD *)v20 + 6) - v25;
          *((_DWORD *)v20 + 7) = v27;
          if ( v28 > 0 && v25 > 0 )
            _V_memmove(dest: &v27[4 * v25], src: v27, count: 4 * v28);
        }
        v29 = *((_WORD *)v18 - 549) & 0x3FFF;
        v45 = 0;
        if ( v29 != 0 )
        {
          do
          {
            Map = CMapLoadHelper::GetMap(this: &v37);
            v31 = v45;
            *(_DWORD *)(*((_DWORD *)v20 + 3) + 4 * v45) = &Map->surfaces2[LODWORD(v18[v45 - 274])];
            v32 = *((_WORD *)v18 - 549) & 0x3FFF;
            v45 = v31 + 1;
          }
          while ( v31 + 1 < v32 );
        }
        v46 += 168;
        *((_WORD *)v20 + 4) = -1;
        v33 = (doverlay_t *)((char *)&pOverlayIn->nId + 1);
        v18 += 280;
        *((_DWORD *)v20 + 36) = 0;
        pOverlayIn = v33;
        if ( (int)v33 >= v40 )
          break;
        v19 = v46;
        v3 = v41;
        p_m_aOverlays = v43;
      }
    }
    CMapLoadHelper::~CMapLoadHelper(this: &v36);
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v35.m_nLumpOffset);
    CMapLoadHelper::~CMapLoadHelper(this: &v37);
    CMapLoadHelper::~CMapLoadHelper(this: &v38);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC300
// Name: private: bool COverlayMgr::Disp_PreClipFragment(struct moverlay_t __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::Disp_PreClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        CUtlMemory<S3RGBA,int> *aDispFragments,
        msurface2_t *surfID)
{
  int firstvertindex; // edi
  float *v5; // esi
  _DWORD *v6; // eax
  int i; // ecx
  mvertex_t *v8; // eax
  double y; // st7
  mvertex_t *v10; // eax
  mvertex_t *v11; // eax
  mvertex_t *v12; // eax
  int m_Size; // edi
  char *v15; // eax
  msurface2_t *m_SurfId; // edx
  int v18; // ecx
  int m_nAllocationCount; // eax
  moverlayfragment_t **v20; // edx
  int v21; // eax
  moverlayfragment_t **v22; // eax
  IDispInfo_vtbl *v23; // eax
  unsigned int v24; // edi
  COverlayMgr *v25; // eax
  mtexinfo_t *v26; // eax
  CFmtStrN<256> *v27; // eax
  CFmtStrN<256> v28; // [esp+20h] [ebp-180h] BYREF
  _BYTE v29[16]; // [esp+130h] [ebp-70h] BYREF
  const void *v30[2]; // [esp+140h] [ebp-60h] BYREF
  moverlayfragment_t surfaceFrag; // [esp+148h] [ebp-58h] BYREF
  Vector *v3; // [esp+170h] [ebp-30h]
  moverlayfragment_t overlayFrag; // [esp+174h] [ebp-2Ch] BYREF
  COverlayMgr *v34; // [esp+19Ch] [ebp-4h]
  int m_pMemory; // [esp+1ACh] [ebp+Ch]
  const Vector *v36; // [esp+1ACh] [ebp+Ch]
  int v37; // [esp+1B0h] [ebp+10h]
  const char *v38; // [esp+1B0h] [ebp+10h]

  firstvertindex = surfID->firstvertindex;
  v34 = this;
  v30[0] = nullptr;
  v30[1] = nullptr;
  memset(&surfaceFrag, 0, 12);
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
    this: (CUtlMemory<SndInfo_t,int> *)v30,
    num: 4);
  v5 = (float *)v30[0];
  surfaceFrag.m_SurfId = (msurface2_t *)((char *)surfaceFrag.m_SurfId + 4);
  surfaceFrag.m_iOverlay = (int)v30[0];
  if ( (int)&surfaceFrag.m_SurfId[-1].visframe > 0 )
    _V_memmove(dest: (char *)v30[0] + 208, src: v30[0], count: 52 * (int)&surfaceFrag.m_SurfId[-1].visframe);
  v6 = v5 + 5;
  for ( i = 4; i != 0; --i )
  {
    if ( v6 != (_DWORD *)20 )
    {
      *(v6 - 5) = 0;
      *(v6 - 4) = 0;
      *(v6 - 3) = 0;
      *(v6 - 2) = 0;
      *(v6 - 1) = 0;
      *v6 = 0;
      v6[1] = 0;
      v6[2] = 0;
      v6[3] = 0;
      v6[4] = 0;
      v6[6] = 0;
      v6[5] = 0;
      v6[7] = -1;
    }
    v6 += 13;
  }
  v8 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
  memset(&overlayFrag.m_aPrimVerts, 0, 12);
  *v5 = v8->position.x;
  overlayFrag.m_aPrimVerts.m_Size = 0;
  y = v8->position.y;
  overlayFrag.m_aPrimVerts.m_pElements = nullptr;
  v5[1] = y;
  v5[2] = v8->position.z;
  v10 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 1]];
  v5[13] = v10->position.x;
  v5[14] = v10->position.y;
  v5[15] = v10->position.z;
  v11 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 2]];
  v5[26] = v11->position.x;
  v5[27] = v11->position.y;
  v5[28] = v11->position.z;
  v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 3]];
  v5[39] = v12->position.x;
  v5[40] = v12->position.y;
  v5[41] = v12->position.z;
  if ( COverlayMgr::Surf_PreClipFragment(
         this: v34,
         pOverlay,
         &overlayFrag,
         surfID,
         surfaceFrag: (moverlayfragment_t *)v29) == 0 )
  {
    if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
LABEL_11:
    if ( surfaceFrag.m_nRenderFrameID >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    return 0;
  }
  COverlayMgr::Surf_ClipFragment(
    this: v34,
    (moverlayfragment_t *)pOverlay,
    &overlayFrag,
    surfID,
    surfaceFrag: (moverlayfragment_t *)v29);
  m_Size = overlayFrag.m_aPrimVerts.m_Size;
  if ( overlayFrag.m_aPrimVerts.m_Size == 0 )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&overlayFrag.m_aPrimVerts);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v30);
    return 0;
  }
  v15 = (char *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v15 != nullptr )
  {
    m_SurfId = overlayFrag.m_SurfId;
    *((_DWORD *)v15 + 4) = 0;
    *((_DWORD *)v15 + 5) = 0;
    *((_DWORD *)v15 + 6) = 0;
    *((_DWORD *)v15 + 7) = 0;
    *((_DWORD *)v15 + 8) = 0;
    *((_DWORD *)v15 + 1) = m_SurfId;
    v34 = (COverlayMgr *)v15;
    *((_DWORD *)v15 + 2) = overlayFrag.m_iOverlay;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
      this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)(v15 + 16),
      pArray: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory,
      size: m_Size);
  }
  else
  {
    v34 = nullptr;
  }
  m_nAllocationCount = aDispFragments->m_nAllocationCount;
  m_pMemory = (int)aDispFragments[1].m_pMemory;
  v18 = m_pMemory;
  if ( m_pMemory + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(this: aDispFragments, num: m_pMemory - m_nAllocationCount + 1);
    v18 = m_pMemory;
  }
  ++aDispFragments[1].m_pMemory;
  v20 = (moverlayfragment_t **)aDispFragments->m_pMemory;
  v21 = (int)aDispFragments[1].m_pMemory - v18 - 1;
  aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
  if ( v21 > 0 )
  {
    _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 4 * v21);
    v18 = m_pMemory;
  }
  v22 = (moverlayfragment_t **)&aDispFragments->m_pMemory[v18];
  if ( v22 != nullptr )
    *v22 = (moverlayfragment_t *)v34;
  v23 = surfID->pDispInfo[92].__vftable;
  v37 = 0;
  if ( overlayFrag.m_aPrimVerts.m_Size > 0 )
  {
    v36 = (const Vector *)&v5[13 * (((int)&v23->dtr_IDispInfo + 1) % 4)];
    surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory = (overlayvert_t *)&v5[13 * (((int)&v23->dtr_IDispInfo + 2) % 4)];
    surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize = (int)&v5[13 * (((int)&v23->dtr_IDispInfo + 3) % 4)];
    surfaceFrag.m_aPrimVerts.m_Size = (int)&v5[13 * (_DWORD)v23];
    v24 = 0;
    while ( 1 )
    {
      PointInQuadToBarycentric(
        v1: (const Vector *)surfaceFrag.m_aPrimVerts.m_Size,
        v2: (const Vector *)surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize,
        v3: &surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory->pos,
        v4: v36,
        point: &overlayFrag.m_aPrimVerts.m_Memory.m_pMemory[v24 / 0x34].pos,
        uv: (Vector2D *)&surfaceFrag.m_aPrimVerts.m_pElements);
      v3 = &surfaceFrag.m_aPrimVerts.m_pElements->pos;
      if ( ((int)surfaceFrag.m_aPrimVerts.m_pElements & 0x7F800000) == 0x7F800000 )
        break;
      surfaceFrag.m_aPrimVerts.m_Memory.m_nAllocationCount = LODWORD(surfaceFrag.decalOffset);
      if ( (LODWORD(surfaceFrag.decalOffset) & 0x7F800000) == 0x7F800000 )
        break;
      v25 = v34;
      *(_DWORD *)(v24 + v34->m_RenderQueue.m_Memory.m_nAllocationCount) = surfaceFrag.m_aPrimVerts.m_pElements;
      *(float *)(v24 + v25->m_RenderQueue.m_Memory.m_nAllocationCount + 4) = surfaceFrag.decalOffset;
      *(_DWORD *)(v24 + v25->m_RenderQueue.m_Memory.m_nAllocationCount + 8) = 0;
      v24 += 52;
      if ( ++v37 >= overlayFrag.m_aPrimVerts.m_Size )
        goto LABEL_29;
    }
    v26 = &host_state.worldbrush->texinfo[pOverlay->m_nTexInfo];
    if ( v26 != nullptr && v26->material != nullptr )
      v38 = v26->material->GetName(this: v26->material);
    else
      v38 = defaultValue;
    v27 = CFmtStrN<256>::CFmtStrN<256>(
            this: (CFmtStrN<256> *)&v28.m_bQuietTruncation,
            pszFormat: "(%f, %f, %f)",
            pOverlay->m_vecOrigin.x,
            pOverlay->m_vecOrigin.y,
            pOverlay->m_vecOrigin.z);
    _DevWarning(a1: 1, a2: "Bad overlay geometry at %s with material '%s'\n", v27->m_szBuf, v38);
    if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
      overlayFrag.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    }
    goto LABEL_11;
  }
LABEL_29:
  if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
    overlayFrag.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
  }
  if ( surfaceFrag.m_nRenderFrameID >= 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FC7C0
// Name: private: void COverlayMgr::Disp_DoClip(class CDispInfo __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct cplane_t __near &,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_DoClip(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CUtlMemory<S3RGBA,int> *aDispFragments,
        cplane_t *clipPlane,
        float clipDistStart,
        moverlayfragment_t *nInterval,
        moverlayfragment_t *nLoopStart,
        int nLoopEnd,
        int nLoopInc)
{
  int v9; // ecx
  moverlayfragment_t **v10; // edx
  int m_pMemory; // edi
  moverlayfragment_t **v13; // ebx
  moverlayfragment_t **v14; // eax
  bool v15; // sf
  int v16; // eax
  moverlayfragment_t *v17; // edi
  COverlayMgr *v18; // ecx
  overlayvert_t *v19; // eax
  int v20; // edi
  int m_nAllocationCount; // eax
  moverlayfragment_t **v22; // ecx
  int v23; // eax
  moverlayfragment_t **v24; // eax
  int v25; // edi
  int v26; // eax
  moverlayfragment_t **v27; // ecx
  int v28; // eax
  moverlayfragment_t **v29; // eax
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > aClippedFragments; // [esp+0h] [ebp-20h] BYREF
  COverlayMgr *v31; // [esp+14h] [ebp-Ch]
  float flOOInterval; // [esp+18h] [ebp-8h]
  int iInterval; // [esp+1Ch] [ebp-4h]
  int iFrag; // [esp+2Ch] [ebp+Ch]

  v31 = this;
  v9 = 0;
  v10 = nullptr;
  flOOInterval = 1.0 / (float)(int)nInterval;
  memset(&aClippedFragments, 0, sizeof(aClippedFragments));
  iInterval = (int)nLoopStart;
  if ( (int)nLoopStart < nLoopEnd )
  {
    while ( 1 )
    {
      m_pMemory = (int)aDispFragments[1].m_pMemory;
      v13 = (moverlayfragment_t **)aDispFragments->m_pMemory;
      aClippedFragments.m_Size = 0;
      if ( m_pMemory == 0 )
        goto LABEL_13;
      if ( m_pMemory > v9 )
      {
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&aClippedFragments, num: m_pMemory - v9);
        v10 = aClippedFragments.m_Memory.m_pMemory;
      }
      aClippedFragments.m_Size += m_pMemory;
      aClippedFragments.m_pElements = v10;
      if ( aClippedFragments.m_Size - m_pMemory > 0 )
      {
        if ( m_pMemory <= 0 )
          goto LABEL_13;
        _V_memmove(dest: &v10[m_pMemory], src: v10, count: 4 * (aClippedFragments.m_Size - m_pMemory));
        v10 = aClippedFragments.m_Memory.m_pMemory;
      }
      if ( m_pMemory > 0 )
      {
        v14 = v10;
        do
        {
          *v14 = *(moverlayfragment_t **)((char *)v14 + (char *)v13 - (char *)v10);
          ++v14;
          --m_pMemory;
        }
        while ( m_pMemory != 0 );
      }
LABEL_13:
      v15 = aDispFragments->m_nGrowSize < 0;
      aDispFragments[1].m_pMemory = nullptr;
      if ( !v15 )
      {
        if ( aDispFragments->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: aDispFragments->m_pMemory);
          v10 = aClippedFragments.m_Memory.m_pMemory;
          aDispFragments->m_pMemory = nullptr;
        }
        aDispFragments->m_nAllocationCount = 0;
      }
      aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
      v16 = 0;
      for ( iFrag = 0; v16 < aClippedFragments.m_Size; iFrag = v16 )
      {
        v17 = v10[v16];
        if ( v17 != nullptr )
        {
          nInterval = nullptr;
          nLoopStart = nullptr;
          v18 = v31;
          clipPlane->dist = (float)((float)iInterval * flOOInterval) * clipDistStart;
          COverlayMgr::DoClipFragment(
            this: v18,
            pFragment: v17,
            pClipPlane: clipPlane,
            ppFront: &nInterval,
            ppBack: &nLoopStart);
          v17->m_aPrimVerts.m_Size = 0;
          if ( v17->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v17->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17->m_aPrimVerts.m_Memory.m_pMemory);
              v17->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
            }
            v17->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
          }
          v19 = v17->m_aPrimVerts.m_Memory.m_pMemory;
          v17->m_aPrimVerts.m_pElements = v19;
          if ( v17->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v19 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
              v17->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
            }
            v17->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: v17);
          if ( nInterval != nullptr )
          {
            v20 = (int)aDispFragments[1].m_pMemory;
            m_nAllocationCount = aDispFragments->m_nAllocationCount;
            if ( v20 + 1 > m_nAllocationCount )
              CUtlMemory<INetMessage *,int>::Grow(this: aDispFragments, num: v20 - m_nAllocationCount + 1);
            ++aDispFragments[1].m_pMemory;
            v22 = (moverlayfragment_t **)aDispFragments->m_pMemory;
            v23 = (int)aDispFragments[1].m_pMemory - v20 - 1;
            aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
            v24 = (moverlayfragment_t **)&aDispFragments->m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = nInterval;
          }
          if ( nLoopStart != nullptr )
          {
            v25 = (int)aDispFragments[1].m_pMemory;
            v26 = aDispFragments->m_nAllocationCount;
            if ( v25 + 1 > v26 )
              CUtlMemory<INetMessage *,int>::Grow(this: aDispFragments, num: v25 - v26 + 1);
            ++aDispFragments[1].m_pMemory;
            v27 = (moverlayfragment_t **)aDispFragments->m_pMemory;
            v28 = (int)aDispFragments[1].m_pMemory - v25 - 1;
            aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
            if ( v28 > 0 )
              _V_memmove(dest: &v27[v25 + 1], src: &v27[v25], count: 4 * v28);
            v29 = (moverlayfragment_t **)&aDispFragments->m_pMemory[v25];
            if ( v29 != nullptr )
              *v29 = nLoopStart;
          }
          v10 = aClippedFragments.m_Memory.m_pMemory;
        }
        v16 = iFrag + 1;
      }
      iInterval += nLoopInc;
      if ( iInterval >= nLoopEnd )
        break;
      v9 = aClippedFragments.m_Memory.m_nAllocationCount;
    }
  }
  if ( aClippedFragments.m_Memory.m_nGrowSize >= 0 && v10 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100FCA50
// Name: private: void COverlayMgr::Disp_ClipFragment(class CDispInfo __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_ClipFragment(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CUtlMemory<S3RGBA,int> *aDispFragments)
{
  int v4; // esi
  cplane_t v5; // [esp+Ch] [ebp-14h] BYREF

  v4 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: &pDisp->CDispUtilsHelper) + 28);
  v5.normal.x = 1.0;
  v5.normal.y = 0.0;
  v5.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &v5,
    clipDistStart: 1.0,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  v5.normal.x = 0.0;
  v5.normal.y = 1.0;
  v5.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &v5,
    clipDistStart: 1.0,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  v5.normal.x = 0.70700002;
  v5.normal.y = 0.70700002;
  v5.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &v5,
    clipDistStart: 0.70700002,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)2,
    nLoopEnd: 2 * v4 - 1,
    nLoopInc: 2);
  v5.normal.x = -0.70700002;
  v5.normal.y = 0.70700002;
  v5.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    aDispFragments,
    clipPlane: &v5,
    clipDistStart: 0.70700002,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)(2 - v4),
    nLoopEnd: v4 - 1,
    nLoopInc: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100FCB70
// Name: private: void COverlayMgr::Disp_CreateFragments(struct moverlay_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_CreateFragments(COverlayMgr *this, moverlay_t *pOverlay, msurface2_t *surfID)
{
  CDispInfo *pDispInfo; // esi
  int i; // ebx
  moverlayfragment_t *v6; // esi
  overlayvert_t *m_pMemory; // eax
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > aDispFragments; // [esp+Ch] [ebp-14h] BYREF

  memset(&aDispFragments, 0, sizeof(aDispFragments));
  if ( COverlayMgr::Disp_PreClipFragment(this, pOverlay, (CUtlMemory<S3RGBA,int> *)&aDispFragments, surfID) != 0 )
  {
    pDispInfo = (CDispInfo *)surfID->pDispInfo;
    if ( pDispInfo != nullptr )
    {
      COverlayMgr::Disp_ClipFragment(this, pDisp: pDispInfo, (CUtlMemory<S3RGBA,int> *)&aDispFragments);
      COverlayMgr::Disp_PostClipFragment(
        this,
        pDisp: pDispInfo,
        pReader: &pDispInfo->m_MeshReader,
        pOverlay,
        &aDispFragments,
        surfID);
    }
  }
  for ( i = aDispFragments.m_Size - 1; i >= 0; --i )
  {
    v6 = aDispFragments.m_Memory.m_pMemory[i];
    if ( v6 != nullptr )
    {
      v6->m_aPrimVerts.m_Size = 0;
      if ( v6->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v6->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_aPrimVerts.m_Memory.m_pMemory);
          v6->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
        }
        v6->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v6->m_aPrimVerts.m_Memory.m_pMemory;
      v6->m_aPrimVerts.m_pElements = m_pMemory;
      if ( v6->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v6->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
        }
        v6->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v6);
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&aDispFragments);
}

//------------------------------------------------------------------------------
// Address: 0x100FCC50
// Name: public: virtual void COverlayMgr::CreateFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::CreateFragments(COverlayMgr *this)
{
  int m_Size; // edx
  moverlay_t *v3; // esi
  int v4; // ecx
  bool v5; // al
  float x; // xmm7_4
  float z; // xmm3_4
  float y; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  moverlay_t *v13; // esi
  float v14; // xmm1_4
  int m_hFirstFragment; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v16; // edx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v17; // eax
  int v18; // ebx
  int v19; // edi
  overlayvert_t *m_pMemory; // edx
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float *p_z; // esi
  float *v25; // edx
  unsigned int v26; // ecx
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float *p_x; // ecx
  int v31; // edi
  bool v32; // zf
  moverlay_t *v33; // esi
  mtexinfo_t *v34; // ebx
  const char *v35; // edi
  int i; // eax
  int v37; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v38; // edi
  const char *v39; // eax
  _DWORD *v40; // edi
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  msurface2_t *v44; // [esp-4h] [ebp-5Ch]
  int v45; // [esp+Ch] [ebp-4Ch]
  int v46; // [esp+38h] [ebp-20h]
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v47; // [esp+38h] [ebp-20h]
  UtlLinkedListElem_t<unsigned short,unsigned short> *v48; // [esp+40h] [ebp-18h]
  int v49; // [esp+40h] [ebp-18h]
  int v50; // [esp+44h] [ebp-14h]
  float v51; // [esp+44h] [ebp-14h]
  int v52; // [esp+44h] [ebp-14h]
  int v53; // [esp+48h] [ebp-10h]
  int v54; // [esp+48h] [ebp-10h]
  int v55; // [esp+4Ch] [ebp-Ch]
  moverlayfragment_t *pFrag; // [esp+54h] [ebp-4h]
  moverlayfragment_t *pFraga; // [esp+54h] [ebp-4h]
  moverlayfragment_t *pFragb; // [esp+54h] [ebp-4h]

  m_Size = this->m_aOverlays.m_Size;
  v55 = m_Size;
  if ( m_Size > 0 )
  {
    pFrag = nullptr;
    v50 = this->m_aOverlays.m_Size;
    do
    {
      v3 = (moverlay_t *)((char *)pFrag + (unsigned int)this->m_aOverlays.m_Memory.m_pMemory);
      v4 = v3->m_aFaces.m_Size;
      v46 = v4;
      if ( v4 != 0 )
      {
        v5 = v3->m_vecUVPoints[3].z == 1.0;
        v3->m_vecUVPoints[3].z = 0.0;
        x = v3->m_vecBasis[2].x;
        if ( (LODWORD(x) & 0x7F800000) != 0x7F800000
          && (LODWORD(v3->m_vecBasis[2].y) & 0x7F800000) != 0x7F800000
          && (LODWORD(v3->m_vecBasis[2].z) & 0x7F800000) != 0x7F800000 )
        {
          z = v3->m_vecBasis[0].z;
          y = v3->m_vecBasis[0].y;
          v9 = (float)(v3->m_vecBasis[2].y * z) - (float)(v3->m_vecBasis[2].z * y);
          v10 = (float)(v3->m_vecBasis[0].x * v3->m_vecBasis[2].z) - (float)(z * x);
          v11 = (float)(y * x) - (float)(v3->m_vecBasis[0].x * v3->m_vecBasis[2].y);
          v3->m_vecBasis[1].x = v9;
          v3->m_vecBasis[1].y = v10;
          v3->m_vecBasis[1].z = v11;
          if ( v5 )
          {
            v3->m_vecBasis[1].x = -v9;
            v3->m_vecBasis[1].y = -v10;
            v3->m_vecBasis[1].z = -v11;
          }
        }
        v12 = 0;
        if ( v4 > 0 )
        {
          do
          {
            v44 = v3->m_aFaces.m_Memory.m_pMemory[v12];
            if ( (v44->flags & 0x800) != 0 )
              COverlayMgr::Disp_CreateFragments(this, pOverlay: v3, surfID: v44);
            else
              COverlayMgr::Surf_CreateFragments(this, pOverlay: v3, surfID: v44);
            ++v12;
          }
          while ( v12 < v46 );
          m_Size = v55;
        }
      }
      pFrag = (moverlayfragment_t *)((char *)pFrag + 168);
      --v50;
    }
    while ( v50 != 0 );
    if ( m_Size > 0 )
    {
      pFraga = nullptr;
      v53 = v55;
      do
      {
        v13 = (moverlay_t *)((char *)pFraga + (unsigned int)this->m_aOverlays.m_Memory.m_pMemory);
        v14 = 0.0;
        m_hFirstFragment = v13->m_hFirstFragment;
        v51 = 0.0;
        if ( m_hFirstFragment != 0xFFFF )
        {
          do
          {
            v16 = &this->m_OverlayFragments.m_Memory.m_pMemory[(unsigned __int16)m_hFirstFragment];
            v17 = &this->m_aFragments.m_Memory.m_pMemory[v16->m_Element];
            v18 = 0;
            v19 = v17->m_Element.m_aPrimVerts.m_Size;
            v48 = v16;
            if ( v19 >= 4 )
            {
              m_pMemory = v17->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v21 = v13->m_vecOrigin.x;
              v22 = v13->m_vecOrigin.y;
              v23 = v13->m_vecOrigin.z;
              p_z = &m_pMemory->pos.z;
              v25 = &m_pMemory[1].pos.z;
              v26 = ((unsigned int)(v19 - 4) >> 2) + 1;
              v18 = 4 * v26;
              do
              {
                if ( v14 <= (float)((float)((float)((float)(*(p_z - 1) - v22) * (float)(*(p_z - 1) - v22))
                                          + (float)((float)(*(p_z - 2) - v21) * (float)(*(p_z - 2) - v21)))
                                  + (float)((float)(*p_z - v23) * (float)(*p_z - v23))) )
                  v14 = (float)((float)((float)(*(p_z - 1) - v22) * (float)(*(p_z - 1) - v22))
                              + (float)((float)(*(p_z - 2) - v21) * (float)(*(p_z - 2) - v21)))
                      + (float)((float)(*p_z - v23) * (float)(*p_z - v23));
                if ( v14 <= (float)((float)((float)((float)(*(v25 - 1) - v22) * (float)(*(v25 - 1) - v22))
                                          + (float)((float)(p_z[11] - v21) * (float)(p_z[11] - v21)))
                                  + (float)((float)(*v25 - v23) * (float)(*v25 - v23))) )
                  v14 = (float)((float)((float)(*(v25 - 1) - v22) * (float)(*(v25 - 1) - v22))
                              + (float)((float)(p_z[11] - v21) * (float)(p_z[11] - v21)))
                      + (float)((float)(*v25 - v23) * (float)(*v25 - v23));
                if ( v14 <= (float)((float)((float)((float)(v25[12] - v22) * (float)(v25[12] - v22))
                                          + (float)((float)(p_z[24] - v21) * (float)(p_z[24] - v21)))
                                  + (float)((float)(v25[13] - v23) * (float)(v25[13] - v23))) )
                  v14 = (float)((float)((float)(v25[12] - v22) * (float)(v25[12] - v22))
                              + (float)((float)(p_z[24] - v21) * (float)(p_z[24] - v21)))
                      + (float)((float)(v25[13] - v23) * (float)(v25[13] - v23));
                if ( v14 <= (float)((float)((float)((float)(v25[25] - v22) * (float)(v25[25] - v22))
                                          + (float)((float)(p_z[37] - v21) * (float)(p_z[37] - v21)))
                                  + (float)((float)(v25[26] - v23) * (float)(v25[26] - v23))) )
                  v14 = (float)((float)((float)(v25[25] - v22) * (float)(v25[25] - v22))
                              + (float)((float)(p_z[37] - v21) * (float)(p_z[37] - v21)))
                      + (float)((float)(v25[26] - v23) * (float)(v25[26] - v23));
                p_z += 52;
                v25 += 52;
                --v26;
              }
              while ( v26 != 0 );
              v16 = v48;
              v13 = (moverlay_t *)((char *)pFraga + (unsigned int)this->m_aOverlays.m_Memory.m_pMemory);
            }
            if ( v18 < v19 )
            {
              p_x = &v17->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v18].pos.x;
              v31 = v19 - v18;
              do
              {
                v27 = v13->m_vecOrigin.x;
                v28 = v13->m_vecOrigin.y;
                v29 = v13->m_vecOrigin.z;
                if ( v14 <= (float)((float)((float)((float)(p_x[1] - v28) * (float)(p_x[1] - v28))
                                          + (float)((float)(*p_x - v27) * (float)(*p_x - v27)))
                                  + (float)((float)(p_x[2] - v29) * (float)(p_x[2] - v29))) )
                  v14 = (float)((float)((float)(p_x[1] - v28) * (float)(p_x[1] - v28))
                              + (float)((float)(*p_x - v27) * (float)(*p_x - v27)))
                      + (float)((float)(p_x[2] - v29) * (float)(p_x[2] - v29));
                p_x += 13;
                --v31;
              }
              while ( v31 != 0 );
            }
            m_hFirstFragment = v16->m_Next;
          }
          while ( m_hFirstFragment != 0xFFFF );
          v51 = v14;
        }
        pFraga = (moverlayfragment_t *)((char *)pFraga + 168);
        v32 = v53-- == 1;
        v13->m_flRadius = sqrt(v51);
      }
      while ( !v32 );
    }
  }
  pFragb = nullptr;
  if ( v55 > 0 )
  {
    v52 = 0;
    do
    {
      v33 = &this->m_aOverlays.m_Memory.m_pMemory[v52];
      v34 = &host_state.worldbrush->texinfo[v33->m_nTexInfo];
      v35 = v34->material->GetShaderName(this: v34->material);
      v33->m_nFlags = _V_stricmp(s1: v35, s2: "UnlitGeneric") == 0 || _V_stricmp(s1: v35, s2: "DecalModulate") == 0;
      for ( i = v33->m_hFirstFragment;
            i != 0xFFFF;
            i = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Next + v45) )
      {
        v37 = (unsigned __int16)i;
        v38 = &this->m_aFragments.m_Memory.m_pMemory[this->m_OverlayFragments.m_Memory.m_pMemory[v37].m_Element];
        v45 = v37 * 6;
        v47 = v38;
        if ( (LODWORD(v38->m_Element.decalOffset) & 0x7F800000) == 0x7F800000 )
        {
          if ( v34->material != nullptr )
            v39 = v34->material->GetName(this: v34->material);
          else
            v39 = defaultValue;
          _DevMsg(a1: 1, a2: "Bad overlay decal offset - %d with material '%s'\n", pFragb, v39);
        }
        if ( v38->m_Element.m_aPrimVerts.m_Size > 0 )
        {
          v54 = 0;
          v49 = v38->m_Element.m_aPrimVerts.m_Size;
          do
          {
            v40 = (_DWORD *)&v47->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v54].pos.x;
            if ( (*v40 & 0x7F800000) == 0x7F800000
              || (v40[1] & 0x7F800000) == 0x7F800000
              || (v40[2] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v41 = v34->material->GetName(this: v34->material);
              else
                v41 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay vert - %d at (%f, %f, %f) with material '%s'\n",
                pFragb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v41);
            }
            if ( (v40[3] & 0x7F800000) == 0x7F800000
              || (v40[4] & 0x7F800000) == 0x7F800000
              || (v40[5] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v42 = v34->material->GetName(this: v34->material);
              else
                v42 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay normal - %d at (%f, %f, %f) with material '%s'\n",
                pFragb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v42);
            }
            if ( (v40[6] & 0x7F800000) == 0x7F800000
              || (v40[7] & 0x7F800000) == 0x7F800000
              || (v40[8] & 0x7F800000) == 0x7F800000
              || (v40[9] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v43 = v34->material->GetName(this: v34->material);
              else
                v43 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay texture coords - %d at (%f, %f, %f) with material '%s'\n",
                pFragb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v43);
            }
            ++v54;
            --v49;
          }
          while ( v49 != 0 );
        }
      }
      ++v52;
      pFragb = (moverlayfragment_t *)((char *)pFragb + 1);
    }
    while ( (int)pFragb < v55 );
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100F52B0
// Name: public: virtual void COverlayMgr::UpdateOverlayRenderLevels(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::UpdateOverlayRenderLevels(COverlayMgr *this, int nCPULevel, int nGPULevel)
{
  this->m_nCPULevel = nCPULevel;
  this->m_nGPULevel = nGPULevel;
}

//------------------------------------------------------------------------------
// Address: 0x100F52D0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: m_pMemory,
                                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5420
// Name: public: void CIndexBuilder::FastPolygonList(int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastPolygonList(CIndexBuilder *this, int startVert, int *pVertexCount, int polygonCount)
{
  unsigned __int16 *v4; // eax
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // esi
  int m_nCurrentIndex; // eax
  CIndexBuilder *v11; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]
  int indexOut; // [esp+1Ch] [ebp+8h]
  int polygonCounta; // [esp+24h] [ebp+10h]

  v4 = &this->m_pIndices[this->m_nCurrentIndex];
  v5 = this->m_nIndexOffset + startVert;
  v6 = 0;
  v11 = this;
  indexOut = 0;
  polygonCounta = polygonCount * this->m_nIndexSize;
  i = 0;
  if ( polygonCounta > 0 )
  {
    do
    {
      v7 = pVertexCount[v6];
      v8 = v7 - 2;
      v9 = 0;
      if ( v7 - 2 > 0 )
      {
        do
        {
          *v4 = v5;
          v4[1] = v9 + v5 + 1;
          v4[2] = v9++ + v5 + 2;
          v4 += 3;
        }
        while ( v9 < v8 );
        v6 = i;
      }
      LOWORD(v5) = v7 + v5;
      ++v6;
      indexOut += v8 + 2 * v8;
      i = v6;
    }
    while ( v6 < polygonCounta );
    this = v11;
  }
  this->m_nCurrentIndex += indexOut * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100F54C0
// Name: void Overlay_TriTLToBR(class CDispInfo __near *,class CMeshReader __near *,class Vector __near &,class Vector __near &,float,float,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Overlay_TriTLToBR(
        int a1@<ebp>,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        float flU,
        float flV,
        int nWidth,
        const Vector *vecIntersectPoint)
{
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  float v13; // xmm2_4
  int v14; // eax
  int v15; // ecx
  float *v16; // edx
  int v17; // eax
  unsigned int k; // esi
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  int v24; // xmm3_4
  int v25; // xmm1_4
  Vector *v26; // eax
  _DWORD *v27; // edx
  double v28; // st7
  double v29; // st7
  int v30; // ecx
  float v31; // xmm3_4
  __int128 v32; // xmm0
  float v33; // xmm2_4
  __int128 v34; // xmm0
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm3_4
  __int128 v40; // xmm0
  float v41; // xmm2_4
  __int128 v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // eax
  float *v52; // edx
  unsigned int m; // esi
  int v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float *v58; // eax
  int v59; // xmm3_4
  int v60; // xmm1_4
  Vector *v61; // eax
  _DWORD *v62; // edx
  double v63; // st7
  double v64; // st7
  int v65; // ecx
  float v66; // xmm7_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float *m_pNormal; // edx
  int m_VertexSize_Normal; // eax
  unsigned int i; // esi
  int v79; // eax
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float *v83; // eax
  int v84; // xmm3_4
  int v85; // xmm1_4
  Vector *FlatVert; // eax
  _DWORD *v87; // edx
  double y; // st7
  double z; // st7
  int v90; // ecx
  float v91; // xmm3_4
  float x; // xmm4_4
  __int128 v93; // xmm1
  __int128 v94; // xmm1
  float v95; // xmm0_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  float v100; // xmm3_4
  float v101; // xmm4_4
  __int128 v102; // xmm0
  __int128 v103; // xmm0
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm5_4
  float v108; // xmm4_4
  float v109; // xmm3_4
  Vector *v110; // eax
  float v111; // xmm2_4
  float v112; // xmm5_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm4_4
  float v117; // xmm5_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm3_4
  float v121; // xmm4_4
  float v122; // xmm4_4
  float v123; // xmm5_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  float v126; // xmm0_4
  int v127; // eax
  float *v128; // edx
  unsigned int j; // esi
  int v130; // eax
  float v131; // xmm0_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float *v134; // eax
  int v135; // xmm3_4
  int v136; // xmm0_4
  int v137; // xmm1_4
  Vector *v138; // eax
  _DWORD *v139; // edx
  double v140; // st7
  double v141; // st7
  int v142; // ecx
  float v143; // xmm0_4
  float v144; // xmm1_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  float v147; // xmm4_4
  float v148; // xmm6_4
  float v149; // xmm0_4
  float v150; // xmm6_4
  float v151; // xmm4_4
  float v152; // xmm3_4
  int v153; // [esp-18h] [ebp-E0h]
  int v154; // [esp-18h] [ebp-E0h]
  int v155; // [esp-18h] [ebp-E0h]
  int v156; // [esp-18h] [ebp-E0h]
  int v157; // [esp-Ch] [ebp-D4h]
  int v158; // [esp-8h] [ebp-D0h]
  int v159; // [esp-8h] [ebp-D0h]
  int v160; // [esp-4h] [ebp-CCh]
  int v161; // [esp-4h] [ebp-CCh]
  int nSnapU; // [esp+0h] [ebp-C8h]
  int nSnapUa; // [esp+0h] [ebp-C8h]
  int v164; // [esp+4h] [ebp-C4h]
  float v165[2]; // [esp+8h] [ebp-C0h] BYREF
  int nNextU; // [esp+10h] [ebp-B8h]
  Vector vecFlatVerts[3]; // [esp+14h] [ebp-B4h] BYREF
  _BYTE flCfs[20]; // [esp+38h] [ebp-90h] OVERLAPPED BYREF
  int nIndices_4[3]; // [esp+50h] [ebp-78h] OVERLAPPED
  Vector vecVerts[3]; // [esp+5Ch] [ebp-6Ch]
  _BYTE vecNormals[44]; // [esp+80h] [ebp-48h] OVERLAPPED BYREF
  _BYTE *v172; // [esp+B8h] [ebp-10h]
  _DWORD v173[3]; // [esp+BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v173[0] = a1;
  v173[1] = retaddr;
  v9 = (int)flU;
  v10 = (int)flV;
  v11 = (int)flU + 1;
  v12 = (int)flV + 1;
  v157 = (int)flU;
  *(_DWORD *)&vecNormals[24] = (int)flV;
  v164 = v11;
  *(_DWORD *)flCfs = v12;
  if ( v11 == nWidth )
  {
    v11 = (int)flU;
    v164 = (int)flU;
  }
  if ( v12 == nWidth )
  {
    v12 = (int)flV;
    *(_DWORD *)flCfs = (int)flV;
  }
  v13 = (float)v10;
  v14 = nWidth * v10;
  if ( (float)((float)(flV - v13) + (float)(flU - (float)v9)) < 1.000001 )
  {
    *(_DWORD *)&vecNormals[32] = v14 + v9;
    v159 = nWidth * *(_DWORD *)flCfs;
    m_pNormal = pReader->m_pNormal;
    v161 = v9 + nWidth * *(_DWORD *)flCfs;
    *(_DWORD *)&vecNormals[36] = v161;
    nSnapUa = v11 + v14;
    *(_DWORD *)&vecNormals[40] = v11 + v14;
    m_VertexSize_Normal = pReader->m_VertexSize_Normal;
    v172 = &vecNormals[32];
    for ( i = 0; (int)i < 36; vecVerts[i / 0xC + 1].z = *(float *)((char *)m_pNormal + v90 + 8) )
    {
      v79 = *(_DWORD *)v172 * m_VertexSize_Normal;
      v80 = *(float *)((char *)m_pNormal + v79);
      v81 = *(float *)((char *)m_pNormal + v79 + 4);
      v82 = *(float *)((char *)m_pNormal + v79 + 8);
      v83 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
      *(float *)&v84 = v83[1] + (float)(v81 * 0.1);
      v155 = *(_DWORD *)v172;
      *(float *)&v85 = v83[2] + (float)(v82 * 0.1);
      *(float *)&nIndices_4[i / 4] = (float)(v80 * 0.1) + *v83;
      nIndices_4[i / 4 + 1] = v84;
      nIndices_4[i / 4 + 2] = v85;
      FlatVert = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&flCfs[8], iVertex: v155);
      v87 = v172;
      v165[i / 4] = FlatVert->x;
      y = FlatVert->y;
      v172 += 4;
      v165[i / 4 + 1] = y;
      i += 12;
      z = FlatVert->z;
      m_VertexSize_Normal = pReader->m_VertexSize_Normal;
      *(float *)&v173[i / 4 - 46] = z;
      v90 = *v87 * m_VertexSize_Normal;
      m_pNormal = pReader->m_pNormal;
      vecVerts[i / 0xC + 1].x = *(float *)((char *)m_pNormal + v90);
      vecVerts[i / 0xC + 1].y = *(float *)((char *)m_pNormal + v90 + 4);
    }
    if ( v157 == v164 )
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
        goto LABEL_10;
      v91 = vecVerts[0].z - *(float *)&nIndices_4[2];
      x = vecVerts[2].x;
      v93 = 0;
      *(float *)&v93 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->x - v165[0])
                                       * (float)(vecIntersectPoint->x - v165[0]))
                               + (float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1])))
                       + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                               * (float)(vecIntersectPoint->z - *(float *)&nNextU)));
      *(_OWORD *)&vecNormals[28] = v93;
      v94 = 0;
      *(float *)&v94 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[0].x - v165[0]) * (float)(vecFlatVerts[0].x - v165[0]))
                               + (float)((float)(vecFlatVerts[0].y - v165[1]) * (float)(vecFlatVerts[0].y - v165[1])))
                       + (float)((float)(vecFlatVerts[0].z - *(float *)&nNextU)
                               * (float)(vecFlatVerts[0].z - *(float *)&nNextU)));
      *(_OWORD *)&flCfs[4] = v94;
      v95 = *(float *)&vecNormals[28] / *(float *)&v94;
      *(float *)&v94 = vecVerts[0].x - *(float *)nIndices_4;
      vecWorld->y = (float)((float)(vecVerts[0].y - *(float *)&nIndices_4[1]) * v95) + *(float *)&nIndices_4[1];
      v96 = *(float *)&vecNormals[4] - vecVerts[2].y;
      vecWorld->z = (float)(v91 * v95) + *(float *)&nIndices_4[2];
      v97 = *(float *)&vecNormals[8] - vecVerts[2].z;
      vecWorld->x = (float)(*(float *)&v94 * v95) + *(float *)nIndices_4;
      v98 = (float)(v96 * v95) + vecVerts[2].y;
      v99 = (float)(v97 * v95) + vecVerts[2].z;
      vecWorldNormal->x = x + (float)((float)(*(float *)vecNormals - x) * v95);
      vecWorldNormal->y = v98;
      vecWorldNormal->z = v99;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
      {
        v100 = *(float *)nIndices_4;
        v101 = vecVerts[1].x;
        v102 = 0;
        *(float *)&v102 = fsqrt(
                            (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                          * (float)(vecIntersectPoint->y - v165[1]))
                                  + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                          * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                          + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
        *(_OWORD *)&vecNormals[28] = v102;
        v103 = 0;
        *(float *)&v103 = fsqrt(
                            (float)((float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1]))
                                  + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                                          * (float)(vecFlatVerts[1].z - *(float *)&nNextU)))
                          + (float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0])));
        *(_OWORD *)&flCfs[4] = v103;
        *(float *)&v103 = *(float *)&vecNormals[28] / *(float *)&v103;
        v104 = (float)((float)(vecVerts[1].z - *(float *)&nIndices_4[2])
                     * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
             + *(float *)&nIndices_4[2];
        vecWorld->y = (float)((float)(vecVerts[1].y - *(float *)&nIndices_4[1])
                            * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
                    + *(float *)&nIndices_4[1];
        v105 = *(float *)&vecNormals[16] - vecVerts[2].y;
        vecWorld->z = v104;
        v106 = *(float *)&vecNormals[20] - vecVerts[2].z;
        v107 = *(float *)&v103 * (float)(v101 - v100);
        v108 = *(float *)&vecNormals[12];
        vecWorld->x = v100 + v107;
        v109 = vecVerts[2].x;
        v110 = vecWorldNormal;
        v111 = (float)(v106 * *(float *)&v103) + vecVerts[2].z;
        v112 = *(float *)&v103 * (float)(v108 - vecVerts[2].x);
        vecWorldNormal->y = (float)(v105 * *(float *)&v103) + vecVerts[2].y;
      }
      else
      {
        if ( CalcBarycentricCooefs(
               v0: (const Vector *)v165,
               v1: vecFlatVerts,
               v2: &vecFlatVerts[1],
               pt: vecIntersectPoint,
               c0: (float *)&flCfs[8],
               c1: (float *)&flCfs[12],
               c2: (float *)&flCfs[16]) )
        {
          v113 = *(float *)&flCfs[16];
          v114 = *(float *)&flCfs[12];
          vecFlatVerts[2].y = vecVerts[1].y * *(float *)&flCfs[16];
          vecFlatVerts[2].z = vecVerts[1].z * *(float *)&flCfs[16];
          *(float *)&vecNormals[36] = vecVerts[0].y * *(float *)&flCfs[12];
          v115 = *(float *)&flCfs[8];
          v116 = (float)((float)(*(float *)&flCfs[8] * *(float *)&nIndices_4[1])
                       + (float)(vecVerts[0].y * *(float *)&flCfs[12]))
               + (float)(vecVerts[1].y * *(float *)&flCfs[16]);
          v117 = (float)((float)(*(float *)&flCfs[8] * *(float *)&nIndices_4[2])
                       + (float)(vecVerts[0].z * *(float *)&flCfs[12]))
               + (float)(vecVerts[1].z * *(float *)&flCfs[16]);
          v118 = *(float *)&vecNormals[4];
          v119 = *(float *)vecNormals;
          vecWorld->x = (float)((float)(*(float *)nIndices_4 * *(float *)&flCfs[8])
                              + (float)(vecVerts[0].x * *(float *)&flCfs[12]))
                      + (float)(vecVerts[1].x * *(float *)&flCfs[16]);
          v120 = *(float *)&vecNormals[12];
          vecWorld->y = v116;
          v121 = *(float *)&vecNormals[16];
          vecWorld->z = v117;
          v122 = v121 * v113;
          v123 = *(float *)&vecNormals[20] * v113;
          *(float *)&vecNormals[40] = *(float *)&vecNormals[8] * v114;
          v124 = (float)((float)(vecVerts[2].x * v115) + (float)(v119 * v114)) + (float)(v120 * v113);
          v125 = (float)((float)(v115 * vecVerts[2].y) + (float)(v118 * v114)) + v122;
          v126 = (float)((float)(v115 * vecVerts[2].z) + *(float *)&vecNormals[40]) + v123;
          vecWorldNormal->x = v124;
          vecWorldNormal->y = v125;
          vecWorldNormal->z = v126;
          VectorNormalize(vec: vecWorldNormal);
          return;
        }
        *(_DWORD *)&vecNormals[36] = v164 + v159;
        *(_DWORD *)&vecNormals[32] = v161;
        v127 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecNormals[40] = nSnapUa;
        v128 = pReader->m_pNormal;
        *(_DWORD *)&vecNormals[24] = &vecNormals[32];
        for ( j = 0; (int)j < 36; vecVerts[j / 0xC + 1].z = *(float *)((char *)v128 + v142 + 8) )
        {
          v130 = **(_DWORD **)&vecNormals[24] * v127;
          v131 = *(float *)((char *)v128 + v130);
          v132 = *(float *)((char *)v128 + v130 + 4);
          v133 = *(float *)((char *)v128 + v130 + 8);
          v134 = (float *)((char *)pReader->m_pPosition + **(_DWORD **)&vecNormals[24] * pReader->m_VertexSize_Position);
          *(float *)&v135 = *v134 + (float)(v131 * 0.1);
          *(float *)&v136 = v134[1] + (float)(v132 * 0.1);
          v156 = **(_DWORD **)&vecNormals[24];
          *(float *)&v137 = v134[2] + (float)(v133 * 0.1);
          nIndices_4[j / 4] = v135;
          nIndices_4[j / 4 + 1] = v136;
          nIndices_4[j / 4 + 2] = v137;
          v138 = CDispInfo::GetFlatVert(this: pDisp, result: &vecFlatVerts[2], iVertex: v156);
          v139 = *(_DWORD **)&vecNormals[24];
          v165[j / 4] = v138->x;
          v140 = v138->y;
          *(_DWORD *)&vecNormals[24] += 4;
          v165[j / 4 + 1] = v140;
          j += 12;
          v141 = v138->z;
          v127 = pReader->m_VertexSize_Normal;
          *(float *)&v173[j / 4 - 46] = v141;
          v142 = *v139 * v127;
          v128 = pReader->m_pNormal;
          vecVerts[j / 0xC + 1].x = *(float *)((char *)v128 + v142);
          vecVerts[j / 0xC + 1].y = *(float *)((char *)v128 + v142 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)v165,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: &vecFlatVerts[2].x,
          c1: &vecFlatVerts[2].y,
          c2: &vecFlatVerts[2].z);
        v143 = vecFlatVerts[2].z;
        *(float *)&flCfs[12] = vecFlatVerts[2].z * vecVerts[1].y;
        *(float *)&flCfs[16] = vecFlatVerts[2].z * vecVerts[1].z;
        v144 = vecFlatVerts[2].y;
        *(float *)&vecNormals[36] = vecFlatVerts[2].y * vecVerts[0].y;
        v145 = vecFlatVerts[2].x;
        v146 = (float)((float)(*(float *)nIndices_4 * vecFlatVerts[2].x) + (float)(vecFlatVerts[2].y * vecVerts[0].x))
             + (float)(vecFlatVerts[2].z * vecVerts[1].x);
        v147 = (float)((float)(vecFlatVerts[2].x * *(float *)&nIndices_4[1]) + (float)(vecFlatVerts[2].y * vecVerts[0].y))
             + (float)(vecFlatVerts[2].z * vecVerts[1].y);
        vecWorld->z = (float)((float)(vecFlatVerts[2].x * *(float *)&nIndices_4[2])
                            + (float)(vecFlatVerts[2].y * vecVerts[0].z))
                    + (float)(vecFlatVerts[2].z * vecVerts[1].z);
        vecWorld->y = v147;
        v112 = v143 * *(float *)&vecNormals[12];
        v148 = v143;
        v149 = v143 * *(float *)&vecNormals[20];
        v150 = v148 * *(float *)&vecNormals[16];
        vecWorld->x = v146;
        v110 = vecWorldNormal;
        *(float *)&vecNormals[40] = v149;
        v151 = v145 * vecVerts[2].y;
        v152 = vecVerts[2].x * v145;
        v111 = (float)((float)(v145 * vecVerts[2].z) + (float)(v144 * *(float *)&vecNormals[8])) + v149;
        v109 = v152 + (float)(v144 * *(float *)vecNormals);
        vecWorldNormal->y = (float)(v151 + (float)(v144 * *(float *)&vecNormals[4])) + v150;
      }
      v110->z = v111;
      v110->x = v109 + v112;
      VectorNormalize(vec: v110);
    }
  }
  else
  {
    v15 = nWidth * v12;
    v158 = v14;
    v160 = v15 + v9;
    *(_DWORD *)&flCfs[8] = v15 + v9;
    v16 = pReader->m_pNormal;
    *(_DWORD *)&flCfs[12] = v11 + v15;
    nSnapU = v11 + v14;
    *(_DWORD *)&flCfs[16] = v11 + v14;
    v17 = pReader->m_VertexSize_Normal;
    v172 = &flCfs[8];
    for ( k = 0; (int)k < 36; vecVerts[k / 0xC + 1].z = *(float *)((char *)v16 + v30 + 8) )
    {
      v19 = *(_DWORD *)v172 * v17;
      v20 = *(float *)((char *)v16 + v19);
      v21 = *(float *)((char *)v16 + v19 + 4);
      v22 = *(float *)((char *)v16 + v19 + 8);
      v23 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
      *(float *)&v24 = v23[1] + (float)(v21 * 0.1);
      v153 = *(_DWORD *)v172;
      *(float *)&v25 = v23[2] + (float)(v22 * 0.1);
      *(float *)&nIndices_4[k / 4] = (float)(v20 * 0.1) + *v23;
      nIndices_4[k / 4 + 1] = v24;
      nIndices_4[k / 4 + 2] = v25;
      v26 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecNormals[32], iVertex: v153);
      v27 = v172;
      v165[k / 4] = v26->x;
      v28 = v26->y;
      v172 += 4;
      v165[k / 4 + 1] = v28;
      k += 12;
      v29 = v26->z;
      v17 = pReader->m_VertexSize_Normal;
      *(float *)&v173[k / 4 - 46] = v29;
      v30 = *v27 * v17;
      v16 = pReader->m_pNormal;
      vecVerts[k / 0xC + 1].x = *(float *)((char *)v16 + v30);
      vecVerts[k / 0xC + 1].y = *(float *)((char *)v16 + v30 + 4);
    }
    if ( v157 == v164 )
    {
      if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
      {
LABEL_10:
        *vecWorld = *(Vector *)nIndices_4;
        *vecWorldNormal = vecVerts[2];
        VectorNormalize(vec: vecWorldNormal);
        return;
      }
      v31 = vecVerts[1].z - *(float *)&nIndices_4[2];
      v32 = 0;
      *(float *)&v32 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1]))
                               + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                       * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                       + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
      *(_OWORD *)&vecNormals[28] = v32;
      v33 = vecVerts[1].y - *(float *)&nIndices_4[1];
      v34 = 0;
      *(float *)&v34 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1]))
                               + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                                       * (float)(vecFlatVerts[1].z - *(float *)&nNextU)))
                       + (float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0])));
      *(_OWORD *)&flCfs[4] = v34;
      *(float *)&v34 = *(float *)&vecNormals[28] / *(float *)&v34;
      vecWorld->x = (float)((float)(vecVerts[1].x - *(float *)nIndices_4)
                          * (float)(*(float *)&vecNormals[28] / *(float *)&flCfs[4]))
                  + *(float *)nIndices_4;
      v35 = *(float *)&vecNormals[12] - vecVerts[2].x;
      vecWorld->y = (float)(v33 * *(float *)&v34) + *(float *)&nIndices_4[1];
      v36 = *(float *)&vecNormals[16] - vecVerts[2].y;
      vecWorld->z = (float)(v31 * *(float *)&v34) + *(float *)&nIndices_4[2];
      v37 = (float)(v36 * *(float *)&v34) + vecVerts[2].y;
      v38 = (float)((float)(*(float *)&vecNormals[20] - vecVerts[2].z) * *(float *)&v34) + vecVerts[2].z;
      vecWorldNormal->x = (float)(v35 * *(float *)&v34) + vecVerts[2].x;
      vecWorldNormal->y = v37;
      vecWorldNormal->z = v38;
      VectorNormalize(vec: vecWorldNormal);
    }
    else if ( *(_DWORD *)&vecNormals[24] == *(_DWORD *)flCfs )
    {
      v39 = vecVerts[1].z - *(float *)&nIndices_4[2];
      v40 = 0;
      *(float *)&v40 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v165[1])
                                       * (float)(vecIntersectPoint->y - v165[1]))
                               + (float)((float)(vecIntersectPoint->z - *(float *)&nNextU)
                                       * (float)(vecIntersectPoint->z - *(float *)&nNextU)))
                       + (float)((float)(vecIntersectPoint->x - v165[0]) * (float)(vecIntersectPoint->x - v165[0])));
      *(_OWORD *)&vecNormals[28] = v40;
      v41 = vecVerts[1].y - *(float *)&nIndices_4[1];
      v42 = 0;
      *(float *)&v42 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].x - v165[0]) * (float)(vecFlatVerts[1].x - v165[0]))
                               + (float)((float)(vecFlatVerts[1].y - v165[1]) * (float)(vecFlatVerts[1].y - v165[1])))
                       + (float)((float)(vecFlatVerts[1].z - *(float *)&nNextU)
                               * (float)(vecFlatVerts[1].z - *(float *)&nNextU)));
      *(_OWORD *)&flCfs[4] = v42;
      *(float *)&v40 = *(float *)&v40 / *(float *)&v42;
      vecWorld->x = (float)((float)(vecVerts[1].x - *(float *)nIndices_4) * *(float *)&v40) + *(float *)nIndices_4;
      *(float *)&v42 = *(float *)&vecNormals[12] - vecVerts[2].x;
      vecWorld->y = (float)(v41 * *(float *)&v40) + *(float *)&nIndices_4[1];
      v43 = *(float *)&vecNormals[16] - vecVerts[2].y;
      vecWorld->z = (float)(v39 * *(float *)&v40) + *(float *)&nIndices_4[2];
      v44 = (float)(v43 * *(float *)&v40) + vecVerts[2].y;
      v45 = (float)((float)(*(float *)&vecNormals[20] - vecVerts[2].z) * *(float *)&v40) + vecVerts[2].z;
      vecWorldNormal->x = (float)(*(float *)&v42 * *(float *)&v40) + vecVerts[2].x;
      vecWorldNormal->y = v44;
      vecWorldNormal->z = v45;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( CalcBarycentricCooefs(
             v0: (const Vector *)v165,
             v1: vecFlatVerts,
             v2: &vecFlatVerts[1],
             pt: vecIntersectPoint,
             c0: &vecFlatVerts[2].x,
             c1: &vecFlatVerts[2].y,
             c2: &vecFlatVerts[2].z) )
      {
        v46 = vecFlatVerts[2].z;
        *(float *)&vecNormals[36] = vecVerts[1].y * vecFlatVerts[2].z;
        *(float *)&vecNormals[40] = vecVerts[1].z * vecFlatVerts[2].z;
        v47 = vecFlatVerts[2].y;
        *(float *)&flCfs[12] = vecVerts[0].y * vecFlatVerts[2].y;
        *(float *)&flCfs[16] = vecVerts[0].z * vecFlatVerts[2].y;
        v48 = vecFlatVerts[2].x;
        v49 = (float)((float)(*(float *)&nIndices_4[1] * vecFlatVerts[2].x) + (float)(vecVerts[0].y * vecFlatVerts[2].y))
            + (float)(vecVerts[1].y * vecFlatVerts[2].z);
        v50 = (float)((float)(*(float *)&nIndices_4[2] * vecFlatVerts[2].x) + (float)(vecVerts[0].z * vecFlatVerts[2].y))
            + (float)(vecVerts[1].z * vecFlatVerts[2].z);
      }
      else
      {
        *(_DWORD *)&vecNormals[36] = v160;
        *(_DWORD *)&vecNormals[32] = v157 + v158;
        v51 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecNormals[40] = nSnapU;
        v52 = pReader->m_pNormal;
        v172 = &vecNormals[32];
        for ( m = 0; (int)m < 36; vecVerts[m / 0xC + 1].z = *(float *)((char *)v52 + v65 + 8) )
        {
          v54 = *(_DWORD *)v172 * v51;
          v55 = *(float *)((char *)v52 + v54);
          v56 = *(float *)((char *)v52 + v54 + 4);
          v57 = *(float *)((char *)v52 + v54 + 8);
          v58 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v172 * pReader->m_VertexSize_Position);
          *(float *)&v59 = v58[1] + (float)(v56 * 0.1);
          v154 = *(_DWORD *)v172;
          *(float *)&v60 = v58[2] + (float)(v57 * 0.1);
          *(float *)&nIndices_4[m / 4] = (float)(v55 * 0.1) + *v58;
          nIndices_4[m / 4 + 1] = v59;
          nIndices_4[m / 4 + 2] = v60;
          v61 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&flCfs[8], iVertex: v154);
          v62 = v172;
          v165[m / 4] = v61->x;
          v63 = v61->y;
          v172 += 4;
          v165[m / 4 + 1] = v63;
          m += 12;
          v64 = v61->z;
          v51 = pReader->m_VertexSize_Normal;
          *(float *)&v173[m / 4 - 46] = v64;
          v65 = *v62 * v51;
          v52 = pReader->m_pNormal;
          vecVerts[m / 0xC + 1].x = *(float *)((char *)v52 + v65);
          vecVerts[m / 0xC + 1].y = *(float *)((char *)v52 + v65 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)v165,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: (float *)&flCfs[8],
          c1: (float *)&flCfs[12],
          c2: (float *)&flCfs[16]);
        v46 = *(float *)&flCfs[16];
        vecFlatVerts[2].y = vecVerts[1].y * *(float *)&flCfs[16];
        vecFlatVerts[2].z = vecVerts[1].z * *(float *)&flCfs[16];
        v47 = *(float *)&flCfs[12];
        *(float *)&vecNormals[36] = vecVerts[0].y * *(float *)&flCfs[12];
        *(float *)&vecNormals[40] = vecVerts[0].z * *(float *)&flCfs[12];
        v48 = *(float *)&flCfs[8];
        v49 = (float)((float)(*(float *)&nIndices_4[1] * *(float *)&flCfs[8])
                    + (float)(vecVerts[0].y * *(float *)&flCfs[12]))
            + (float)(vecVerts[1].y * *(float *)&flCfs[16]);
        v50 = (float)((float)(*(float *)&nIndices_4[2] * *(float *)&flCfs[8])
                    + (float)(vecVerts[0].z * *(float *)&flCfs[12]))
            + (float)(vecVerts[1].z * *(float *)&flCfs[16]);
      }
      v66 = *(float *)vecNormals;
      v67 = (float)((float)(*(float *)nIndices_4 * v48) + (float)(vecVerts[0].x * v47)) + (float)(vecVerts[1].x * v46);
      v68 = *(float *)&vecNormals[20] * v46;
      vecWorld->y = v49;
      v69 = *(float *)&vecNormals[12];
      vecWorld->z = v50;
      v70 = *(float *)&vecNormals[16] * v46;
      v71 = v69 * v46;
      *(float *)&vecNormals[36] = *(float *)&vecNormals[4] * v47;
      v72 = *(float *)&vecNormals[8] * v47;
      vecWorld->x = v67;
      *(float *)&vecNormals[40] = v72;
      v73 = (float)((float)(vecVerts[2].x * v48) + (float)(v66 * v47)) + v71;
      v74 = (float)((float)(vecVerts[2].y * v48) + *(float *)&vecNormals[36]) + v70;
      v75 = (float)((float)(vecVerts[2].z * v48) + *(float *)&vecNormals[40]) + v68;
      vecWorldNormal->x = v73;
      vecWorldNormal->y = v74;
      vecWorldNormal->z = v75;
      VectorNormalize(vec: vecWorldNormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6400
// Name: void Overlay_TriBLToTR(class CDispInfo __near *,class CMeshReader __near *,class Vector __near &,class Vector __near &,float,float,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Overlay_TriBLToTR(
        int a1@<ebp>,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        float flU,
        float flV,
        int nWidth,
        const Vector *vecIntersectPoint)
{
  int v9; // esi
  int v10; // eax
  int v11; // edi
  int v12; // edx
  int v13; // edx
  float v14; // xmm2_4
  int v15; // eax
  int v16; // eax
  float *v17; // edx
  unsigned int k; // esi
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm3_4
  float v25; // xmm1_4
  Vector *v26; // eax
  _DWORD *v27; // edx
  double v28; // st7
  double v29; // st7
  int v30; // ecx
  float v31; // xmm3_4
  __int128 v32; // xmm0
  float v33; // xmm2_4
  __int128 v34; // xmm0
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm3_4
  __int128 v40; // xmm0
  float v41; // xmm2_4
  __int128 v42; // xmm1
  float v43; // xmm2_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  int v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm4_4
  float v50; // xmm5_4
  int v51; // eax
  float *v52; // edx
  unsigned int m; // esi
  int v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float *v58; // eax
  float v59; // xmm3_4
  float v60; // xmm1_4
  Vector *v61; // eax
  _DWORD *v62; // edx
  double v63; // st7
  double v64; // st7
  int v65; // ecx
  float v66; // xmm7_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm4_4
  float v70; // xmm5_4
  float v71; // xmm4_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm3_4
  float *m_pNormal; // edx
  int m_VertexSize_Normal; // eax
  unsigned int i; // esi
  int v79; // eax
  float v80; // xmm0_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float *v83; // eax
  float v84; // xmm3_4
  float v85; // xmm1_4
  Vector *FlatVert; // eax
  _DWORD *v87; // edx
  double y; // st7
  double z; // st7
  int v90; // ecx
  float v91; // xmm3_4
  float v92; // xmm4_4
  __int128 v93; // xmm1
  __int128 v94; // xmm1
  float v95; // xmm0_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm3_4
  float x; // xmm3_4
  float v101; // xmm4_4
  __int128 v102; // xmm0
  __int128 v103; // xmm0
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm5_4
  float v108; // xmm4_4
  float v109; // xmm3_4
  Vector *v110; // eax
  float v111; // xmm2_4
  float v112; // xmm5_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm4_4
  float v117; // xmm5_4
  float v118; // xmm7_4
  float v119; // xmm6_4
  float v120; // xmm3_4
  float v121; // xmm4_4
  float v122; // xmm4_4
  float v123; // xmm5_4
  float v124; // xmm1_4
  float v125; // xmm2_4
  float v126; // xmm0_4
  int v127; // eax
  float *v128; // edx
  unsigned int j; // esi
  int v130; // eax
  float v131; // xmm0_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float *v134; // eax
  float v135; // xmm3_4
  float v136; // xmm0_4
  float v137; // xmm1_4
  Vector *v138; // eax
  _DWORD *v139; // edx
  double v140; // st7
  double v141; // st7
  int v142; // ecx
  int v143; // xmm0_4
  float v144; // xmm1_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  float v147; // xmm4_4
  float v148; // xmm6_4
  float v149; // xmm0_4
  float v150; // xmm6_4
  float v151; // xmm4_4
  float v152; // xmm3_4
  int v153; // [esp-18h] [ebp-E0h]
  int v154; // [esp-18h] [ebp-E0h]
  int v155; // [esp-18h] [ebp-E0h]
  int v156; // [esp-18h] [ebp-E0h]
  int v157; // [esp-Ch] [ebp-D4h]
  int v158; // [esp-8h] [ebp-D0h]
  int v159; // [esp-8h] [ebp-D0h]
  int v160; // [esp-4h] [ebp-CCh]
  int nSnapU; // [esp+0h] [ebp-C8h]
  int nSnapUa; // [esp+0h] [ebp-C8h]
  int v163; // [esp+4h] [ebp-C4h]
  int v164; // [esp+4h] [ebp-C4h]
  int nNextU[3]; // [esp+8h] [ebp-C0h] BYREF
  float v166; // [esp+Ch] [ebp-BCh]
  float v167; // [esp+10h] [ebp-B8h]
  Vector vecFlatVerts[3]; // [esp+14h] [ebp-B4h] BYREF
  int nNextV; // [esp+38h] [ebp-90h] BYREF
  __int128 flCfs; // [esp+3Ch] [ebp-8Ch] OVERLAPPED BYREF
  __int128 nIndices; // [esp+4Ch] [ebp-7Ch] OVERLAPPED
  Vector vecNormals[3]; // [esp+5Ch] [ebp-6Ch]
  _BYTE vecVerts[44]; // [esp+80h] [ebp-48h] OVERLAPPED BYREF
  char *v174; // [esp+B8h] [ebp-10h]
  _DWORD v175[3]; // [esp+BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v175[0] = a1;
  v175[1] = retaddr;
  v9 = (int)flU;
  v10 = (int)flV;
  v11 = (int)flU + 1;
  v12 = (int)flV + 1;
  v157 = (int)flU;
  *(_DWORD *)&vecVerts[24] = (int)flV;
  v160 = v11;
  LODWORD(vecFlatVerts[2].x) = v12;
  if ( v11 == nWidth )
  {
    v11 = (int)flU;
    v160 = (int)flU;
  }
  if ( v12 == nWidth )
  {
    v12 = (int)flV;
    LODWORD(vecFlatVerts[2].x) = (int)flV;
  }
  v13 = nWidth * v12;
  v14 = (float)v10;
  v15 = nWidth * v10;
  if ( (float)(flV - v14) <= (float)(flU - (float)v9) )
  {
    v164 = v13 + v11;
    *(_DWORD *)&vecVerts[36] = v13 + v11;
    nSnapUa = v15 + v9;
    *(_DWORD *)&vecVerts[32] = v15 + v9;
    v159 = v13;
    m_pNormal = pReader->m_pNormal;
    *(_DWORD *)&vecVerts[40] = v11 + v15;
    m_VertexSize_Normal = pReader->m_VertexSize_Normal;
    v174 = &vecVerts[32];
    for ( i = 0; (int)i < 9; *(float *)((char *)&nIndices + i * 4) = *(float *)((char *)m_pNormal + v90 + 8) )
    {
      v79 = *(_DWORD *)v174 * m_VertexSize_Normal;
      v80 = *(float *)((char *)m_pNormal + v79);
      v81 = *(float *)((char *)m_pNormal + v79 + 4);
      v82 = *(float *)((char *)m_pNormal + v79 + 8);
      v83 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
      v84 = v83[1] + (float)(v81 * 0.1);
      v155 = *(_DWORD *)v174;
      v85 = v83[2] + (float)(v82 * 0.1);
      vecNormals[i / 3 + 2].x = (float)(v80 * 0.1) + *v83;
      vecNormals[i / 3 + 2].y = v84;
      vecNormals[i / 3 + 2].z = v85;
      FlatVert = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)((char *)&flCfs + 4), iVertex: v155);
      v87 = v174;
      nNextU[i] = SLODWORD(FlatVert->x);
      y = FlatVert->y;
      v174 += 4;
      *(float *)((char *)&v166 + i * 4) = y;
      i += 3;
      z = FlatVert->z;
      m_VertexSize_Normal = pReader->m_VertexSize_Normal;
      *(float *)&v175[i - 46] = z;
      v90 = *v87 * m_VertexSize_Normal;
      m_pNormal = pReader->m_pNormal;
      *(float *)((char *)&flCfs + i * 4 + 8) = *(float *)((char *)m_pNormal + v90);
      *(float *)((char *)&flCfs + i * 4 + 12) = *(float *)((char *)m_pNormal + v90 + 4);
    }
    if ( v157 == v160 )
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
        goto LABEL_10;
      v91 = *(float *)&vecVerts[8] - vecNormals[2].z;
      v92 = *((float *)&nIndices + 1);
      v93 = 0;
      *(float *)&v93 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                                       * (float)(vecIntersectPoint->x - *(float *)nNextU))
                               + (float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166)))
                       + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)));
      *(_OWORD *)&vecVerts[28] = v93;
      v94 = 0;
      *(float *)&v94 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[0].x - *(float *)nNextU)
                                       * (float)(vecFlatVerts[0].x - *(float *)nNextU))
                               + (float)((float)(vecFlatVerts[0].y - v166) * (float)(vecFlatVerts[0].y - v166)))
                       + (float)((float)(vecFlatVerts[0].z - v167) * (float)(vecFlatVerts[0].z - v167)));
      flCfs = v94;
      v95 = *(float *)&vecVerts[28] / *(float *)&v94;
      *(float *)&v94 = *(float *)vecVerts - vecNormals[2].x;
      vecWorld->y = (float)((float)(*(float *)&vecVerts[4] - vecNormals[2].y) * v95) + vecNormals[2].y;
      v96 = vecNormals[0].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v91 * v95) + vecNormals[2].z;
      v97 = vecNormals[0].z - *((float *)&nIndices + 3);
      vecWorld->x = (float)(*(float *)&v94 * v95) + vecNormals[2].x;
      v98 = (float)(v96 * v95) + *((float *)&nIndices + 2);
      v99 = (float)(v97 * v95) + *((float *)&nIndices + 3);
      vecWorldNormal->x = v92 + (float)((float)(vecNormals[0].x - v92) * v95);
      vecWorldNormal->y = v98;
      vecWorldNormal->z = v99;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
      {
        x = vecNormals[2].x;
        v101 = *(float *)&vecVerts[12];
        v102 = 0;
        *(float *)&v102 = fsqrt(
                            (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                                  + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                          + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                                  * (float)(vecIntersectPoint->x - *(float *)nNextU)));
        *(_OWORD *)&vecVerts[28] = v102;
        v103 = 0;
        *(float *)&v103 = fsqrt(
                            (float)((float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166))
                                  + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)))
                          + (float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                                  * (float)(vecFlatVerts[1].x - *(float *)nNextU)));
        flCfs = v103;
        *(float *)&v103 = *(float *)&vecVerts[28] / *(float *)&v103;
        v104 = (float)((float)(*(float *)&vecVerts[20] - vecNormals[2].z)
                     * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
             + vecNormals[2].z;
        vecWorld->y = (float)((float)(*(float *)&vecVerts[16] - vecNormals[2].y)
                            * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
                    + vecNormals[2].y;
        v105 = vecNormals[1].y - *((float *)&nIndices + 2);
        vecWorld->z = v104;
        v106 = vecNormals[1].z - *((float *)&nIndices + 3);
        v107 = *(float *)&v103 * (float)(v101 - x);
        v108 = vecNormals[1].x;
        vecWorld->x = x + v107;
        v109 = *((float *)&nIndices + 1);
        v110 = vecWorldNormal;
        v111 = (float)(v106 * *(float *)&v103) + *((float *)&nIndices + 3);
        v112 = *(float *)&v103 * (float)(v108 - *((float *)&nIndices + 1));
        vecWorldNormal->y = (float)(v105 * *(float *)&v103) + *((float *)&nIndices + 2);
      }
      else
      {
        if ( CalcBarycentricCooefs(
               v0: (const Vector *)nNextU,
               v1: vecFlatVerts,
               v2: &vecFlatVerts[1],
               pt: vecIntersectPoint,
               c0: (float *)&flCfs + 1,
               c1: (float *)&flCfs + 2,
               c2: (float *)&flCfs + 3) )
        {
          v113 = *((float *)&flCfs + 3);
          v114 = *((float *)&flCfs + 2);
          vecFlatVerts[2].z = *(float *)&vecVerts[16] * *((float *)&flCfs + 3);
          *(float *)&nNextV = *(float *)&vecVerts[20] * *((float *)&flCfs + 3);
          *(float *)&vecVerts[36] = *(float *)&vecVerts[4] * *((float *)&flCfs + 2);
          v115 = *((float *)&flCfs + 1);
          v116 = (float)((float)(*((float *)&flCfs + 1) * vecNormals[2].y)
                       + (float)(*(float *)&vecVerts[4] * *((float *)&flCfs + 2)))
               + (float)(*(float *)&vecVerts[16] * *((float *)&flCfs + 3));
          v117 = (float)((float)(*((float *)&flCfs + 1) * vecNormals[2].z)
                       + (float)(*(float *)&vecVerts[8] * *((float *)&flCfs + 2)))
               + (float)(*(float *)&vecVerts[20] * *((float *)&flCfs + 3));
          v118 = vecNormals[0].y;
          v119 = vecNormals[0].x;
          vecWorld->x = (float)((float)(vecNormals[2].x * *((float *)&flCfs + 1))
                              + (float)(*(float *)vecVerts * *((float *)&flCfs + 2)))
                      + (float)(*(float *)&vecVerts[12] * *((float *)&flCfs + 3));
          v120 = vecNormals[1].x;
          vecWorld->y = v116;
          v121 = vecNormals[1].y;
          vecWorld->z = v117;
          v122 = v121 * v113;
          v123 = vecNormals[1].z * v113;
          *(float *)&vecVerts[40] = vecNormals[0].z * v114;
          v124 = (float)((float)(*((float *)&nIndices + 1) * v115) + (float)(v119 * v114)) + (float)(v120 * v113);
          v125 = (float)((float)(v115 * *((float *)&nIndices + 2)) + (float)(v118 * v114)) + v122;
          v126 = (float)((float)(v115 * *((float *)&nIndices + 3)) + *(float *)&vecVerts[40]) + v123;
          vecWorldNormal->x = v124;
          vecWorldNormal->y = v125;
          vecWorldNormal->z = v126;
          VectorNormalize(vec: vecWorldNormal);
          return;
        }
        *(_DWORD *)&vecVerts[36] = v157 + v159;
        *(_DWORD *)&vecVerts[32] = nSnapUa;
        v127 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecVerts[40] = v164;
        v128 = pReader->m_pNormal;
        *(_DWORD *)&vecVerts[24] = &vecVerts[32];
        for ( j = 0; (int)j < 9; *(float *)((char *)&nIndices + j * 4) = *(float *)((char *)v128 + v142 + 8) )
        {
          v130 = **(_DWORD **)&vecVerts[24] * v127;
          v131 = *(float *)((char *)v128 + v130);
          v132 = *(float *)((char *)v128 + v130 + 4);
          v133 = *(float *)((char *)v128 + v130 + 8);
          v134 = (float *)((char *)pReader->m_pPosition + **(_DWORD **)&vecVerts[24] * pReader->m_VertexSize_Position);
          v135 = *v134 + (float)(v131 * 0.1);
          v136 = v134[1] + (float)(v132 * 0.1);
          v156 = **(_DWORD **)&vecVerts[24];
          v137 = v134[2] + (float)(v133 * 0.1);
          vecNormals[j / 3 + 2].x = v135;
          vecNormals[j / 3 + 2].y = v136;
          vecNormals[j / 3 + 2].z = v137;
          v138 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecFlatVerts[2].y, iVertex: v156);
          v139 = *(_DWORD **)&vecVerts[24];
          nNextU[j] = SLODWORD(v138->x);
          v140 = v138->y;
          *(_DWORD *)&vecVerts[24] += 4;
          *(float *)((char *)&v166 + j * 4) = v140;
          j += 3;
          v141 = v138->z;
          v127 = pReader->m_VertexSize_Normal;
          *(float *)&v175[j - 46] = v141;
          v142 = *v139 * v127;
          v128 = pReader->m_pNormal;
          *(float *)((char *)&flCfs + j * 4 + 8) = *(float *)((char *)v128 + v142);
          *(float *)((char *)&flCfs + j * 4 + 12) = *(float *)((char *)v128 + v142 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)nNextU,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: &vecFlatVerts[2].y,
          c1: &vecFlatVerts[2].z,
          c2: (float *)&nNextV);
        v143 = nNextV;
        *((float *)&flCfs + 2) = *(float *)&nNextV * *(float *)&vecVerts[16];
        *((float *)&flCfs + 3) = *(float *)&nNextV * *(float *)&vecVerts[20];
        v144 = vecFlatVerts[2].z;
        *(float *)&vecVerts[36] = vecFlatVerts[2].z * *(float *)&vecVerts[4];
        v145 = vecFlatVerts[2].y;
        v146 = (float)((float)(vecNormals[2].x * vecFlatVerts[2].y) + (float)(vecFlatVerts[2].z * *(float *)vecVerts))
             + (float)(*(float *)&nNextV * *(float *)&vecVerts[12]);
        v147 = (float)((float)(vecFlatVerts[2].y * vecNormals[2].y) + (float)(vecFlatVerts[2].z * *(float *)&vecVerts[4]))
             + (float)(*(float *)&nNextV * *(float *)&vecVerts[16]);
        vecWorld->z = (float)((float)(vecFlatVerts[2].y * vecNormals[2].z)
                            + (float)(vecFlatVerts[2].z * *(float *)&vecVerts[8]))
                    + (float)(*(float *)&nNextV * *(float *)&vecVerts[20]);
        vecWorld->y = v147;
        v112 = *(float *)&v143 * vecNormals[1].x;
        v148 = *(float *)&v143;
        v149 = *(float *)&v143 * vecNormals[1].z;
        v150 = v148 * vecNormals[1].y;
        vecWorld->x = v146;
        v110 = vecWorldNormal;
        *(float *)&vecVerts[40] = v149;
        v151 = v145 * *((float *)&nIndices + 2);
        v152 = *((float *)&nIndices + 1) * v145;
        v111 = (float)((float)(v145 * *((float *)&nIndices + 3)) + (float)(v144 * vecNormals[0].z)) + v149;
        v109 = v152 + (float)(v144 * vecNormals[0].x);
        vecWorldNormal->y = (float)(v151 + (float)(v144 * vecNormals[0].y)) + v150;
      }
      v110->z = v111;
      v110->x = v109 + v112;
      VectorNormalize(vec: v110);
    }
  }
  else
  {
    v158 = v15;
    DWORD2(flCfs) = v13 + v9;
    nSnapU = v9 + v15;
    DWORD1(flCfs) = v9 + v15;
    v16 = pReader->m_VertexSize_Normal;
    v163 = v11 + v13;
    HIDWORD(flCfs) = v11 + v13;
    v17 = pReader->m_pNormal;
    v174 = (char *)&flCfs + 4;
    for ( k = 0; (int)k < 9; *(float *)((char *)&nIndices + k * 4) = *(float *)((char *)v17 + v30 + 8) )
    {
      v19 = *(_DWORD *)v174 * v16;
      v20 = *(float *)((char *)v17 + v19);
      v21 = *(float *)((char *)v17 + v19 + 4);
      v22 = *(float *)((char *)v17 + v19 + 8);
      v23 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
      v24 = v23[1] + (float)(v21 * 0.1);
      v153 = *(_DWORD *)v174;
      v25 = v23[2] + (float)(v22 * 0.1);
      vecNormals[k / 3 + 2].x = (float)(v20 * 0.1) + *v23;
      vecNormals[k / 3 + 2].y = v24;
      vecNormals[k / 3 + 2].z = v25;
      v26 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)&vecVerts[32], iVertex: v153);
      v27 = v174;
      nNextU[k] = SLODWORD(v26->x);
      v28 = v26->y;
      v174 += 4;
      *(float *)((char *)&v166 + k * 4) = v28;
      k += 3;
      v29 = v26->z;
      v16 = pReader->m_VertexSize_Normal;
      *(float *)&v175[k - 46] = v29;
      v30 = *v27 * v16;
      v17 = pReader->m_pNormal;
      *(float *)((char *)&flCfs + k * 4 + 8) = *(float *)((char *)v17 + v30);
      *(float *)((char *)&flCfs + k * 4 + 12) = *(float *)((char *)v17 + v30 + 4);
    }
    if ( v157 == v160 )
    {
      if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
      {
LABEL_10:
        *vecWorld = vecNormals[2];
        *vecWorldNormal = *(Vector *)((char *)&nIndices + 4);
        VectorNormalize(vec: vecWorldNormal);
        return;
      }
      v31 = *(float *)&vecVerts[20] - vecNormals[2].z;
      v32 = 0;
      *(float *)&v32 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                               + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                       + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                               * (float)(vecIntersectPoint->x - *(float *)nNextU)));
      *(_OWORD *)&vecVerts[28] = v32;
      v33 = *(float *)&vecVerts[16] - vecNormals[2].y;
      v34 = 0;
      *(float *)&v34 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166))
                               + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)))
                       + (float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                               * (float)(vecFlatVerts[1].x - *(float *)nNextU)));
      flCfs = v34;
      *(float *)&v34 = *(float *)&vecVerts[28] / *(float *)&v34;
      vecWorld->x = (float)((float)(*(float *)&vecVerts[12] - vecNormals[2].x)
                          * (float)(*(float *)&vecVerts[28] / *(float *)&flCfs))
                  + vecNormals[2].x;
      v35 = vecNormals[1].x - *((float *)&nIndices + 1);
      vecWorld->y = (float)(v33 * *(float *)&v34) + vecNormals[2].y;
      v36 = vecNormals[1].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v31 * *(float *)&v34) + vecNormals[2].z;
      v37 = (float)(v36 * *(float *)&v34) + *((float *)&nIndices + 2);
      v38 = (float)((float)(vecNormals[1].z - *((float *)&nIndices + 3)) * *(float *)&v34) + *((float *)&nIndices + 3);
      vecWorldNormal->x = (float)(v35 * *(float *)&v34) + *((float *)&nIndices + 1);
      vecWorldNormal->y = v37;
      vecWorldNormal->z = v38;
      VectorNormalize(vec: vecWorldNormal);
    }
    else if ( *(_DWORD *)&vecVerts[24] == LODWORD(vecFlatVerts[2].x) )
    {
      v39 = *(float *)&vecVerts[20] - vecNormals[2].z;
      v40 = 0;
      *(float *)&v40 = fsqrt(
                         (float)((float)((float)(vecIntersectPoint->y - v166) * (float)(vecIntersectPoint->y - v166))
                               + (float)((float)(vecIntersectPoint->z - v167) * (float)(vecIntersectPoint->z - v167)))
                       + (float)((float)(vecIntersectPoint->x - *(float *)nNextU)
                               * (float)(vecIntersectPoint->x - *(float *)nNextU)));
      *(_OWORD *)&vecVerts[28] = v40;
      v41 = *(float *)&vecVerts[16] - vecNormals[2].y;
      v42 = 0;
      *(float *)&v42 = fsqrt(
                         (float)((float)((float)(vecFlatVerts[1].x - *(float *)nNextU)
                                       * (float)(vecFlatVerts[1].x - *(float *)nNextU))
                               + (float)((float)(vecFlatVerts[1].y - v166) * (float)(vecFlatVerts[1].y - v166)))
                       + (float)((float)(vecFlatVerts[1].z - v167) * (float)(vecFlatVerts[1].z - v167)));
      flCfs = v42;
      *(float *)&v40 = *(float *)&v40 / *(float *)&v42;
      vecWorld->x = (float)((float)(*(float *)&vecVerts[12] - vecNormals[2].x) * *(float *)&v40) + vecNormals[2].x;
      *(float *)&v42 = vecNormals[1].x - *((float *)&nIndices + 1);
      vecWorld->y = (float)(v41 * *(float *)&v40) + vecNormals[2].y;
      v43 = vecNormals[1].y - *((float *)&nIndices + 2);
      vecWorld->z = (float)(v39 * *(float *)&v40) + vecNormals[2].z;
      v44 = (float)(v43 * *(float *)&v40) + *((float *)&nIndices + 2);
      v45 = (float)((float)(vecNormals[1].z - *((float *)&nIndices + 3)) * *(float *)&v40) + *((float *)&nIndices + 3);
      vecWorldNormal->x = (float)(*(float *)&v42 * *(float *)&v40) + *((float *)&nIndices + 1);
      vecWorldNormal->y = v44;
      vecWorldNormal->z = v45;
      VectorNormalize(vec: vecWorldNormal);
    }
    else
    {
      if ( CalcBarycentricCooefs(
             v0: (const Vector *)nNextU,
             v1: vecFlatVerts,
             v2: &vecFlatVerts[1],
             pt: vecIntersectPoint,
             c0: &vecFlatVerts[2].y,
             c1: &vecFlatVerts[2].z,
             c2: (float *)&nNextV) )
      {
        v46 = nNextV;
        *(float *)&vecVerts[36] = *(float *)&vecVerts[16] * *(float *)&nNextV;
        *(float *)&vecVerts[40] = *(float *)&vecVerts[20] * *(float *)&nNextV;
        v47 = vecFlatVerts[2].z;
        *((float *)&flCfs + 2) = *(float *)&vecVerts[4] * vecFlatVerts[2].z;
        *((float *)&flCfs + 3) = *(float *)&vecVerts[8] * vecFlatVerts[2].z;
        v48 = vecFlatVerts[2].y;
        v49 = (float)((float)(vecNormals[2].y * vecFlatVerts[2].y) + (float)(*(float *)&vecVerts[4] * vecFlatVerts[2].z))
            + (float)(*(float *)&vecVerts[16] * *(float *)&nNextV);
        v50 = (float)((float)(vecNormals[2].z * vecFlatVerts[2].y) + (float)(*(float *)&vecVerts[8] * vecFlatVerts[2].z))
            + (float)(*(float *)&vecVerts[20] * *(float *)&nNextV);
      }
      else
      {
        *(_DWORD *)&vecVerts[36] = v163;
        *(_DWORD *)&vecVerts[32] = nSnapU;
        v51 = pReader->m_VertexSize_Normal;
        *(_DWORD *)&vecVerts[40] = v160 + v158;
        v52 = pReader->m_pNormal;
        v174 = &vecVerts[32];
        for ( m = 0; (int)m < 9; *(float *)((char *)&nIndices + m * 4) = *(float *)((char *)v52 + v65 + 8) )
        {
          v54 = *(_DWORD *)v174 * v51;
          v55 = *(float *)((char *)v52 + v54);
          v56 = *(float *)((char *)v52 + v54 + 4);
          v57 = *(float *)((char *)v52 + v54 + 8);
          v58 = (float *)((char *)pReader->m_pPosition + *(_DWORD *)v174 * pReader->m_VertexSize_Position);
          v59 = v58[1] + (float)(v56 * 0.1);
          v154 = *(_DWORD *)v174;
          v60 = v58[2] + (float)(v57 * 0.1);
          vecNormals[m / 3 + 2].x = (float)(v55 * 0.1) + *v58;
          vecNormals[m / 3 + 2].y = v59;
          vecNormals[m / 3 + 2].z = v60;
          v61 = CDispInfo::GetFlatVert(this: pDisp, result: (Vector *)((char *)&flCfs + 4), iVertex: v154);
          v62 = v174;
          nNextU[m] = SLODWORD(v61->x);
          v63 = v61->y;
          v174 += 4;
          *(float *)((char *)&v166 + m * 4) = v63;
          m += 3;
          v64 = v61->z;
          v51 = pReader->m_VertexSize_Normal;
          *(float *)&v175[m - 46] = v64;
          v65 = *v62 * v51;
          v52 = pReader->m_pNormal;
          *(float *)((char *)&flCfs + m * 4 + 8) = *(float *)((char *)v52 + v65);
          *(float *)((char *)&flCfs + m * 4 + 12) = *(float *)((char *)v52 + v65 + 4);
        }
        CalcBarycentricCooefs(
          v0: (const Vector *)nNextU,
          v1: vecFlatVerts,
          v2: &vecFlatVerts[1],
          pt: vecIntersectPoint,
          c0: (float *)&flCfs + 1,
          c1: (float *)&flCfs + 2,
          c2: (float *)&flCfs + 3);
        v46 = SHIDWORD(flCfs);
        vecFlatVerts[2].z = *(float *)&vecVerts[16] * *((float *)&flCfs + 3);
        *(float *)&nNextV = *(float *)&vecVerts[20] * *((float *)&flCfs + 3);
        v47 = *((float *)&flCfs + 2);
        *(float *)&vecVerts[36] = *(float *)&vecVerts[4] * *((float *)&flCfs + 2);
        *(float *)&vecVerts[40] = *(float *)&vecVerts[8] * *((float *)&flCfs + 2);
        v48 = *((float *)&flCfs + 1);
        v49 = (float)((float)(vecNormals[2].y * *((float *)&flCfs + 1))
                    + (float)(*(float *)&vecVerts[4] * *((float *)&flCfs + 2)))
            + (float)(*(float *)&vecVerts[16] * *((float *)&flCfs + 3));
        v50 = (float)((float)(vecNormals[2].z * *((float *)&flCfs + 1))
                    + (float)(*(float *)&vecVerts[8] * *((float *)&flCfs + 2)))
            + (float)(*(float *)&vecVerts[20] * *((float *)&flCfs + 3));
      }
      v66 = vecNormals[0].x;
      v67 = (float)((float)(vecNormals[2].x * v48) + (float)(*(float *)vecVerts * v47))
          + (float)(*(float *)&vecVerts[12] * *(float *)&v46);
      v68 = vecNormals[1].z * *(float *)&v46;
      vecWorld->y = v49;
      v69 = vecNormals[1].x;
      vecWorld->z = v50;
      v70 = vecNormals[1].y * *(float *)&v46;
      v71 = v69 * *(float *)&v46;
      *(float *)&vecVerts[36] = vecNormals[0].y * v47;
      v72 = vecNormals[0].z * v47;
      vecWorld->x = v67;
      *(float *)&vecVerts[40] = v72;
      v73 = (float)((float)(*((float *)&nIndices + 1) * v48) + (float)(v66 * v47)) + v71;
      v74 = (float)((float)(*((float *)&nIndices + 2) * v48) + *(float *)&vecVerts[36]) + v70;
      v75 = (float)((float)(*((float *)&nIndices + 3) * v48) + *(float *)&vecVerts[40]) + v68;
      vecWorldNormal->x = v73;
      vecWorldNormal->y = v74;
      vecWorldNormal->z = v75;
      VectorNormalize(vec: vecWorldNormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F73E0
// Name: public: virtual void COverlayMgr::ClearRenderLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ClearRenderLists(COverlayMgr *this)
{
  int i; // esi
  float v3; // xmm1_4
  float v4; // xmm0_4

  for ( i = 0; i < 4; ++i )
    this->ClearRenderLists(this, a2: i);
  if ( r_overlayfadeenable.m_pParent != nullptr && r_overlayfadeenable.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = r_overlayfademin.m_pParent->m_Value.m_fValue * r_overlayfademin.m_pParent->m_Value.m_fValue;
    v4 = r_overlayfademax.m_pParent->m_Value.m_fValue * r_overlayfademax.m_pParent->m_Value.m_fValue;
    this->m_flFadeMin2 = v3;
    this->m_flFadeMax2 = v4;
    this->m_flFadeDelta2 = 1.0 / (float)(v4 - v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7450
// Name: private: bool COverlayMgr::FadeOverlayFragmentGlobal(struct moverlayfragment_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COverlayMgr::FadeOverlayFragmentGlobal(COverlayMgr *this, moverlayfragment_t *pFragment)
{
  bool result; // al
  int v4; // esi
  int m_Size; // ebx
  overlayvert_t *m_pMemory; // edx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  overlayvert_t *v10; // edx
  float v11; // xmm0_4
  float m_flFadeMin2; // xmm1_4
  float v13; // xmm0_4
  float pFragmenta; // [esp+Ch] [ebp+8h]

  result = false;
  if ( pFragment->m_aPrimVerts.m_Size > 0 )
  {
    v4 = 0;
    m_Size = pFragment->m_aPrimVerts.m_Size;
    while ( 1 )
    {
      m_pMemory = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
      v7 = g_CurrentViewOrigin.x - m_pMemory[v4].pos.x;
      v8 = g_CurrentViewOrigin.y - m_pMemory[v4].pos.y;
      v9 = g_CurrentViewOrigin.z - m_pMemory[v4].pos.z;
      v10 = &m_pMemory[v4];
      v11 = (float)(v8 * v8) + (float)(v7 * v7);
      m_flFadeMin2 = this->m_flFadeMin2;
      v13 = v11 + (float)(v9 * v9);
      if ( m_flFadeMin2 > v13 )
        break;
      if ( v13 <= this->m_flFadeMax2 )
      {
        pFragmenta = (float)((float)(1.0 - (float)((float)(v13 - m_flFadeMin2) * this->m_flFadeDelta2)) * 255.0)
                   + 8388608.0;
        pFragment->m_aPrimVerts.m_Memory.m_pMemory[v4].packedColor = (LOBYTE(pFragmenta) << 24) | 0xFFFFFF;
        goto LABEL_8;
      }
      v10->packedColor = 0xFFFFFF;
LABEL_9:
      ++v4;
      if ( --m_Size == 0 )
        return result;
    }
    v10->packedColor = -1;
LABEL_8:
    result = true;
    goto LABEL_9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F7540
// Name: private: bool COverlayMgr::FadeOverlayFragment(struct moverlay_t __near *,struct moverlayfragment_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::FadeOverlayFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *pFragment)
{
  float m_flFadeDistMaxSq; // xmm3_4
  float m_flFadeDistMinSq; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  int v9; // esi
  float v10; // xmm3_4
  int m_Size; // ecx
  int v12; // eax
  float v13; // [esp-4h] [ebp-10h]

  m_flFadeDistMaxSq = pOverlay->m_flFadeDistMaxSq;
  m_flFadeDistMinSq = pOverlay->m_flFadeDistMinSq;
  v6 = fsqrt(
         (float)((float)((float)(pOverlay->m_vecOrigin.z - g_CurrentViewOrigin.z)
                       * (float)(pOverlay->m_vecOrigin.z - g_CurrentViewOrigin.z))
               + (float)((float)(pOverlay->m_vecOrigin.y - g_CurrentViewOrigin.y)
                       * (float)(pOverlay->m_vecOrigin.y - g_CurrentViewOrigin.y)))
       + (float)((float)(pOverlay->m_vecOrigin.x - g_CurrentViewOrigin.x)
               * (float)(pOverlay->m_vecOrigin.x - g_CurrentViewOrigin.x)));
  v7 = (float)(v6 - pOverlay->m_flRadius) * (float)(v6 - pOverlay->m_flRadius);
  if ( v7 >= m_flFadeDistMaxSq )
    return 0;
  v9 = -1;
  if ( m_flFadeDistMinSq >= 0.0 && v7 > m_flFadeDistMinSq )
  {
    v10 = (float)(m_flFadeDistMaxSq - v7) * pOverlay->m_flInvFadeRangeSq;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    v13 = (float)(v10 * 255.0) + 8388608.0;
    v9 = (LOBYTE(v13) << 24) | 0xFFFFFF;
  }
  m_Size = pFragment->m_aPrimVerts.m_Size;
  if ( m_Size > 0 )
  {
    v12 = 0;
    do
    {
      pFragment->m_aPrimVerts.m_Memory.m_pMemory[v12++].packedColor = v9;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F7660
// Name: public: virtual void COverlayMgr::ClearRenderLists(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ClearRenderLists(COverlayMgr *this, int nSortGroup)
{
  COverlayMgr::RenderQueueInfo_t *v2; // eax
  int m_nNextRenderQueue; // edx

  ++g_OverlayRenderFrameID;
  v2 = (COverlayMgr::RenderQueueInfo_t *)this->m_nFirstRenderQueue[nSortGroup];
  if ( v2 == (COverlayMgr::RenderQueueInfo_t *)0xFFFF )
  {
    this->m_nFirstRenderQueue[nSortGroup] = -1;
  }
  else
  {
    do
    {
      v2 = &this->m_RenderQueue.m_Memory.m_pMemory[(unsigned __int16)v2].m_Element.m_Queue[nSortGroup];
      m_nNextRenderQueue = v2->m_nNextRenderQueue;
      v2->m_nVertexCount = 0;
      v2->m_nIndexCount = 0;
      v2->m_hFirstFragment = -1;
      v2->m_nNextRenderQueue = -1;
      LOWORD(v2) = m_nNextRenderQueue;
    }
    while ( m_nNextRenderQueue != 0xFFFF );
    this->m_nFirstRenderQueue[nSortGroup] = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F76D0
// Name: public: virtual void COverlayMgr::SetOverlayBindProxy(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::SetOverlayBindProxy(COverlayMgr *this, int iOverlayID, void *pBindProxy)
{
  moverlay_t *v3; // eax

  v3 = &this->m_aOverlays.m_Memory.m_pMemory[iOverlayID];
  if ( v3 != nullptr )
    v3->m_pBindProxy = pBindProxy;
}

//------------------------------------------------------------------------------
// Address: 0x100F76F0
// Name: void Overlay_DispUVToWorld(class CDispInfo __near *,class CMeshReader __near *,class Vector2D const __near &,class Vector __near &,class Vector __near &,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_DispUVToWorld(
        CDispInfo *pDisp,
        CMeshReader *pReader,
        const Vector2D *vecUV,
        Vector *vecWorld,
        Vector *vecWorldNormal,
        moverlayfragment_t *surfaceFrag)
{
  int v7; // esi
  float v8; // xmm0_4
  Vector vecIntersectPoint; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF
  float flV; // [esp+30h] [ebp+8h]
  float flU; // [esp+44h] [ebp+1Ch]

  v7 = (1 << *(_DWORD *)(pDisp->GetPowerInfo(this: &pDisp->CDispUtilsHelper) + 28)) + 1;
  PointInQuadFromBarycentric(
    v1: &surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[pDisp->m_iPointStart % 4].pos,
    v2: &surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[(pDisp->m_iPointStart + 3) % 4].pos,
    v3: &surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[(pDisp->m_iPointStart + 2) % 4].pos,
    v4: &surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[(pDisp->m_iPointStart + 1) % 4].pos,
    uv: vecUV,
    point: &vecIntersectPoint);
  v8 = (float)v7 - 1.000001;
  flU = vecUV->x * v8;
  flV = vecUV->y * v8;
  if ( ((int)flU + v7 * (int)flV) % 2 == 1 )
    Overlay_TriTLToBR(
      a1: (int)&savedregs,
      pDisp,
      pReader,
      vecWorld,
      vecWorldNormal,
      flU,
      flV,
      nWidth: v7,
      &vecIntersectPoint);
  else
    Overlay_TriBLToTR(
      a1: (int)&savedregs,
      pDisp,
      pReader,
      vecWorld,
      vecWorldNormal,
      flU,
      flV,
      nWidth: v7,
      &vecIntersectPoint);
}

//------------------------------------------------------------------------------
// Address: 0x100F7C50
// Name: struct overlayvert_t __near * CopyConstruct<struct overlayvert_t>(struct overlayvert_t __near *,struct overlayvert_t const __near &)
// Source: json
//------------------------------------------------------------------------------
overlayvert_t *__cdecl CopyConstruct<overlayvert_t>(overlayvert_t *pMemory, const overlayvert_t *src)
{
  overlayvert_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  *pMemory = *src;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F7E30
// Name: public: virtual void COverlayMgr::AddFragmentListToRenderList(int,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::AddFragmentListToRenderList(
        COverlayMgr *this,
        int nSortGroup,
        unsigned __int16 iFragment,
        bool bDisp)
{
  int v5; // eax
  moverlayfragment_t *v6; // esi
  moverlay_t *v7; // edx
  unsigned __int8 m_nMinCPULevel; // cl
  int m_nCPULevel; // ebx
  bool v10; // al
  unsigned __int8 m_nMaxCPULevel; // cl
  unsigned __int8 m_nMinGPULevel; // cl
  unsigned __int8 m_nMaxGPULevel; // cl
  char v14; // al
  int m_nMaterialSortID; // ecx
  COverlayMgr::RenderQueueInfo_t *v16; // eax
  int nVertexCount; // [esp+4h] [ebp-8h]
  unsigned __int16 i; // [esp+8h] [ebp-4h]
  int iFragmenta; // [esp+18h] [ebp+Ch]

  for ( i = iFragment; i != 0xFFFF; i = *(unsigned __int16 *)((char *)&this->m_aFragments.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 44 * i;
    v6 = (moverlayfragment_t *)((char *)&this->m_aFragments.m_Memory.m_pMemory->m_Element + v5);
    iFragmenta = v5;
    if ( !bDisp && v6->m_nRenderFrameID == g_OverlayRenderFrameID )
      continue;
    v7 = &this->m_aOverlays.m_Memory.m_pMemory[v6->m_iOverlay];
    if ( v7 == nullptr )
      continue;
    m_nMinCPULevel = v7->m_nMinCPULevel;
    m_nCPULevel = this->m_nCPULevel;
    v10 = true;
    if ( m_nMinCPULevel == 0 || (v10 = m_nCPULevel >= m_nMinCPULevel - 1) )
    {
      m_nMaxCPULevel = v7->m_nMaxCPULevel;
      if ( m_nMaxCPULevel != 0 )
        v10 = m_nCPULevel <= m_nMaxCPULevel - 1;
      if ( v10 )
      {
        m_nMinGPULevel = v7->m_nMinGPULevel;
        if ( m_nMinGPULevel != 0 )
          v10 = this->m_nGPULevel >= m_nMinGPULevel - 1;
        if ( v10 )
        {
          m_nMaxGPULevel = v7->m_nMaxGPULevel;
          if ( m_nMaxGPULevel != 0 )
            v10 = this->m_nGPULevel <= m_nMaxGPULevel - 1;
          if ( v10 )
          {
            nVertexCount = v6->m_aPrimVerts.m_Size;
            if ( nVertexCount >= 3 )
            {
              if ( r_overlayfadeenable.m_pParent != nullptr && r_overlayfadeenable.m_pParent->m_Value.m_nValue != 0 )
              {
                v14 = COverlayMgr::FadeOverlayFragmentGlobal(this, pFragment: v6);
              }
              else
              {
                if ( v7->m_flFadeDistMaxSq <= 0.0 )
                  goto LABEL_23;
                v14 = COverlayMgr::FadeOverlayFragment(this, pOverlay: v7, pFragment: v6);
              }
              if ( v14 != 0 )
              {
LABEL_23:
                m_nMaterialSortID = v6->m_nMaterialSortID;
                v6->m_nRenderFrameID = g_OverlayRenderFrameID;
                v16 = &this->m_RenderQueue.m_Memory.m_pMemory[m_nMaterialSortID].m_Element.m_Queue[nSortGroup];
                if ( v16->m_hFirstFragment == 0xFFFF )
                {
                  this->m_RenderQueue.m_Memory.m_pMemory[m_nMaterialSortID].m_Element.m_Queue[nSortGroup].m_nNextRenderQueue = this->m_nFirstRenderQueue[nSortGroup];
                  this->m_nFirstRenderQueue[nSortGroup] = m_nMaterialSortID;
                }
                v6->m_hNextRender = v16->m_hFirstFragment;
                v16->m_nVertexCount += nVertexCount;
                v16->m_nIndexCount += 3 * nVertexCount - 6;
                v16->m_hFirstFragment = i;
              }
            }
          }
        }
      }
    }
    v5 = iFragmenta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7FD0
// Name: public: virtual void COverlayMgr::RenderAllUnlitOverlays(class IMatRenderContext __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::RenderAllUnlitOverlays(
        COverlayMgr *this,
        IMatRenderContext *pRenderContext,
        int nSortGroup)
{
  moverlay_t *m_pMemory; // eax
  int m_hFirstFragment; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v7; // ecx
  int v8; // esi
  int i; // [esp+8h] [ebp-4h]
  int nSortGroupa; // [esp+18h] [ebp+Ch]

  i = 0;
  if ( this->m_aOverlays.m_Size > 0 )
  {
    nSortGroupa = 0;
    do
    {
      m_pMemory = this->m_aOverlays.m_Memory.m_pMemory;
      if ( (m_pMemory[nSortGroupa].m_nFlags & 1) != 0 )
      {
        m_hFirstFragment = m_pMemory[nSortGroupa].m_hFirstFragment;
        if ( m_hFirstFragment != 0xFFFF )
        {
          v7 = this->m_OverlayFragments.m_Memory.m_pMemory;
          do
          {
            v8 = (unsigned __int16)m_hFirstFragment;
            this->AddFragmentListToRenderList(this, a2: nSortGroup, a3: v7[v8].m_Element, a4: false);
            v7 = this->m_OverlayFragments.m_Memory.m_pMemory;
            m_hFirstFragment = v7[v8].m_Next;
          }
          while ( m_hFirstFragment != 0xFFFF );
        }
      }
      ++nSortGroupa;
      ++i;
    }
    while ( i < this->m_aOverlays.m_Size );
  }
  this->RenderOverlays(this, a2: pRenderContext, a3: nSortGroup);
  this->ClearRenderLists(this, a2: nSortGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100F8470
// Name: private: void COverlayMgr::BuildClipPlanes(struct msurface2_t __near *,struct moverlayfragment_t __near &,class Vector const __near &,class CUtlVector<struct cplane_t,class CUtlMemory<struct cplane_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::BuildClipPlanes(
        COverlayMgr *this,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag,
        const Vector *vecBasisNormal,
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *m_ClipPlanes)
{
  int m_Size; // edi
  int v7; // ebx
  overlayvert_t *m_pMemory; // ecx
  int v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  int m_nAllocationCount; // eax
  cplane_t *v14; // ecx
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm7_4
  float v19; // xmm2_4
  cplane_t *v20; // ecx
  float v21; // xmm1_4
  int v22; // edx
  float v23; // xmm3_4
  Vector vecEdge; // [esp+4h] [ebp-14h] BYREF
  int v25; // [esp+10h] [ebp-8h]
  int nVertCount; // [esp+14h] [ebp-4h]
  int m_ClipPlanesa; // [esp+2Ch] [ebp+14h]

  m_Size = surfaceFrag->m_aPrimVerts.m_Size;
  nVertCount = m_Size;
  if ( m_Size > 0 )
  {
    m_ClipPlanesa = 2;
    v7 = 0;
    v25 = m_Size;
    while ( 1 )
    {
      m_pMemory = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v9 = (m_ClipPlanesa - 1) % m_Size;
      v10 = m_pMemory[v9].pos.y - m_pMemory[v7].pos.y;
      v11 = m_pMemory[v9].pos.z - m_pMemory[v7].pos.z;
      vecEdge.x = m_pMemory[v9].pos.x - m_pMemory[v7].pos.x;
      vecEdge.y = v10;
      vecEdge.z = v11;
      VectorNormalize(vec: &vecEdge);
      v12 = (int)m_ClipPlanes[1].m_pMemory;
      m_nAllocationCount = m_ClipPlanes->m_nAllocationCount;
      if ( v12 + 1 > m_nAllocationCount )
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: m_ClipPlanes, num: v12 - m_nAllocationCount + 1);
      ++m_ClipPlanes[1].m_pMemory;
      v14 = (cplane_t *)m_ClipPlanes->m_pMemory;
      v15 = (int)m_ClipPlanes[1].m_pMemory - v12 - 1;
      m_ClipPlanes[1].m_nAllocationCount = (int)m_ClipPlanes->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 20 * v15);
      v16 = vecBasisNormal->z * vecEdge.x;
      v17 = (float)(vecBasisNormal->y * vecEdge.z) - (float)(vecBasisNormal->z * vecEdge.y);
      v18 = vecBasisNormal->x * vecEdge.z;
      v19 = (float)(vecBasisNormal->x * vecEdge.y) - (float)(vecBasisNormal->y * vecEdge.x);
      v20 = (cplane_t *)&m_ClipPlanes->m_pMemory[v12];
      v20->normal.x = v17;
      v20->normal.z = v19;
      v21 = v16 - v18;
      v20->normal.y = v21;
      v22 = m_ClipPlanesa % nVertCount;
      v23 = (float)((float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.y * v21)
                  + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.x * v17))
          + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v7].pos.z * v19);
      v20->dist = v23;
      v20->type = 3;
      if ( (float)((float)((float)((float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.y * v21)
                                 + (float)(v17 * surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.x))
                         + (float)(surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory[v22].pos.z * v19))
                 - v23) > 0.0 )
      {
        v20->normal.x = -v17;
        v20->normal.y = -v21;
        v20->normal.z = -v19;
        v20->dist = -v23;
      }
      ++m_ClipPlanesa;
      ++v7;
      if ( --v25 == 0 )
        break;
      m_Size = nVertCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F87D0
// Name: public: virtual void COverlayMgr::RenderOverlays(class IMatRenderContext __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::RenderOverlays(COverlayMgr *this, IMatRenderContext *pRenderContext, int nSortGroup)
{
  COverlayMgr *v3; // edi
  int m_nValue; // eax
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v6; // eax
  COverlayMgr::RenderQueueHead_t *p_m_Element; // esi
  int m_nNextRenderQueue; // edx
  IMaterial *m_pMaterial; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // edi
  void *m_pBindProxy; // edx
  unsigned __int16 m_hNextRender; // ax
  int m_Size; // edx
  float *m_pCurrPosition; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int m_nVertexCount; // eax
  void *v19; // eax
  IMatRenderContext *v20; // ebx
  COverlayMgr::RenderQueueHead_t *v21; // esi
  bool v22; // al
  IMesh *v23; // ebx
  int m_nIndexCount; // eax
  int v25; // ecx
  const overlayvert_t *v26; // esi
  const overlayvert_t *v27; // ebx
  float decalOffset; // xmm0_4
  int v29; // edi
  unsigned int v30; // edx
  float *p_z; // eax
  float *m_pCurrNormal; // ecx
  float *v33; // ecx
  float *v34; // ecx
  float *v35; // ecx
  int v36; // ecx
  float *v37; // ecx
  float *v38; // ecx
  float *v39; // ecx
  float *v40; // ecx
  float *v41; // ecx
  int v42; // ecx
  float *v43; // ecx
  float *v44; // ecx
  float *v45; // ecx
  float *v46; // ecx
  float *v47; // ecx
  int v48; // ecx
  float *v49; // ecx
  float *v50; // ecx
  float *v51; // ecx
  float *v52; // ecx
  float *v53; // ecx
  int v54; // ecx
  float *v55; // eax
  int v56; // edx
  float *v57; // ecx
  float *v58; // ecx
  float *v59; // ecx
  float *v60; // ecx
  int v61; // ecx
  int v62; // edi
  unsigned int v63; // edx
  float *v64; // eax
  float *v65; // ecx
  float *v66; // ecx
  float *v67; // ecx
  float *v68; // ecx
  int v69; // ecx
  float *v70; // ecx
  float *v71; // ecx
  float *v72; // ecx
  float *v73; // ecx
  float *v74; // ecx
  int v75; // ecx
  float *v76; // ecx
  float *v77; // ecx
  float *v78; // ecx
  float *v79; // ecx
  float *v80; // ecx
  int v81; // ecx
  float *v82; // ecx
  float *v83; // ecx
  float *v84; // ecx
  float *v85; // ecx
  float *v86; // ecx
  int v87; // ecx
  float *v88; // eax
  int v89; // edx
  float *v90; // ecx
  float *v91; // ecx
  float *v92; // ecx
  float *v93; // ecx
  int v94; // ecx
  int v95; // ebx
  unsigned int v96; // esi
  unsigned __int8 *v97; // edi
  int *v98; // eax
  IMesh *v99; // edi
  int v100; // eax
  int *v101; // eax
  CUtlVectorFixedGrowable<int,256> polyList; // [esp+8h] [ebp-644h] BYREF
  int nNextRenderQueue; // [esp+420h] [ebp-22Ch]
  void *pCurrentBindProxy; // [esp+424h] [ebp-228h]
  CMeshBuilder meshBuilder; // [esp+428h] [ebp-224h] BYREF
  COverlayMgr::RenderQueueHead_t *renderQueueHead; // [esp+610h] [ebp-3Ch]
  int nMaxVertices; // [esp+614h] [ebp-38h]
  int nMaxIndices; // [esp+618h] [ebp-34h]
  int iHighestRenderOrder; // [esp+61Ch] [ebp-30h]
  int iCurrentRenderOrder; // [esp+620h] [ebp-2Ch]
  int nCurrVertexCount; // [esp+624h] [ebp-28h]
  int nCurrIndexCount; // [esp+628h] [ebp-24h]
  int v113; // [esp+62Ch] [ebp-20h]
  COverlayMgr *v114; // [esp+630h] [ebp-1Ch]
  int hStartFragment; // [esp+634h] [ebp-18h]
  int nVertCount; // [esp+638h] [ebp-14h]
  IMesh *pMesh; // [esp+63Ch] [ebp-10h]
  bool bWireframeFragments; // [esp+642h] [ebp-Ah]
  bool bBoundMaterial; // [esp+643h] [ebp-9h]
  const overlayvert_t *pVert; // [esp+644h] [ebp-8h]
  bool bLightmappedMaterial; // [esp+64Bh] [ebp-1h]

  v3 = this;
  v114 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "COverlayMgr::RenderOverlays",
    a3: 0,
    a4: "Overlays",
    a5: false,
    a6: 4);
  if ( r_renderoverlayfragment.m_pParent == nullptr || r_renderoverlayfragment.m_pParent->m_Value.m_nValue == 0 )
  {
    v3->ClearRenderLists(this: v3, a2: nSortGroup);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( r_overlaywireframe.m_pParent != nullptr )
    m_nValue = r_overlaywireframe.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bWireframeFragments = m_nValue != 0;
  if ( m_nValue != 0 )
    pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  iCurrentRenderOrder = 0;
  iHighestRenderOrder = 0;
  bLightmappedMaterial = false;
  nMaxIndices = GetMaxIndicesToRender(this: pRenderContext);
  while ( 2 )
  {
    v6 = v3->m_nFirstRenderQueue[nSortGroup];
    if ( v6 == 0xFFFF )
      goto LABEL_125;
    do
    {
      p_m_Element = &v114->m_RenderQueue.m_Memory.m_pMemory[(unsigned __int16)v6].m_Element;
      m_nNextRenderQueue = p_m_Element->m_Queue[nSortGroup].m_nNextRenderQueue;
      renderQueueHead = p_m_Element;
      nNextRenderQueue = m_nNextRenderQueue;
      if ( bWireframeFragments )
        m_pMaterial = g_materialWorldWireframe;
      else
        m_pMaterial = p_m_Element->m_pMaterial;
      nMaxVertices = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: m_pMaterial);
      hStartFragment = p_m_Element->m_Queue[nSortGroup].m_hFirstFragment;
      if ( (_WORD)hStartFragment == 0xFFFF )
        goto LABEL_124;
      do
      {
        m_pMemory = v114->m_aFragments.m_Memory.m_pMemory;
        m_pBindProxy = v114->m_aOverlays.m_Memory.m_pMemory[m_pMemory[(unsigned __int16)hStartFragment].m_Element.m_iOverlay].m_pBindProxy;
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        polyList.m_Memory.m_nGrowSize = -1;
        m_hNextRender = hStartFragment;
        polyList.m_pElements = polyList.m_Memory.m_pFixedMemory;
        pCurrentBindProxy = m_pBindProxy;
        m_Size = 0;
        pMesh = nullptr;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        polyList.m_Memory.m_pMemory = polyList.m_Memory.m_pFixedMemory;
        polyList.m_Memory.m_nAllocationCount = 256;
        polyList.m_Memory.m_nMallocGrowSize = 0;
        polyList.m_Size = 0;
        nCurrVertexCount = 0;
        nCurrIndexCount = 0;
        bBoundMaterial = false;
        hStartFragment = 0xFFFF;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        do
        {
          v113 = 44 * m_hNextRender;
          v15 = (int)&v114->m_aOverlays.m_Memory.m_pMemory[m_pMemory[v113 / 0x2Cu].m_Element.m_iOverlay];
          if ( *(void **)(v15 + 144) != pCurrentBindProxy )
          {
            if ( (_WORD)hStartFragment == 0xFFFF )
              hStartFragment = m_hNextRender;
            goto LABEL_97;
          }
          v16 = *(__int16 *)(v15 + 6);
          if ( v16 > iHighestRenderOrder )
            iHighestRenderOrder = *(__int16 *)(v15 + 6);
          if ( v16 == iCurrentRenderOrder )
          {
            nVertCount = m_pMemory[v113 / 0x2Cu].m_Element.m_aPrimVerts.m_Size;
            v17 = nVertCount;
            pVert = (const overlayvert_t *)(3 * nVertCount - 6);
            if ( pMesh != nullptr )
            {
              if ( nCurrVertexCount + nVertCount > nMaxVertices || nCurrIndexCount + 3 * nVertCount - 6 > nMaxIndices )
              {
                CIndexBuilder::FastPolygonList(
                  this: &meshBuilder.m_IndexBuilder,
                  startVert: 0,
                  pVertexCount: polyList.m_Memory.m_pMemory,
                  polygonCount: m_Size);
                if ( meshBuilder.m_bGenerateIndices )
                {
                  switch ( meshBuilder.m_Type )
                  {
                    case MATERIAL_LINE_STRIP:
                      m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                      break;
                    case MATERIAL_LINE_LOOP:
                      m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                      break;
                    case MATERIAL_POLYGON:
                      m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                      break;
                    case MATERIAL_QUADS:
                      m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                      break;
                    case MATERIAL_INSTANCED_QUADS:
                      m_nVertexCount = 0;
                      break;
                    default:
                      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                      break;
                  }
                  CIndexBuilder::GenerateIndices(
                    this: &meshBuilder.m_IndexBuilder,
                    primitiveType: meshBuilder.m_Type,
                    nIndexCount: m_nVertexCount);
                }
                meshBuilder.m_pMesh->UnlockMesh(
                  this: meshBuilder.m_pMesh,
                  a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
                  a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
                  a4: &meshBuilder);
                meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
                meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
                meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
                meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                meshBuilder.m_pMesh = nullptr;
                pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                m_Size = 0;
                pMesh = nullptr;
                polyList.m_Size = 0;
                nCurrVertexCount = 0;
                nCurrIndexCount = 0;
              }
              v17 = nVertCount;
            }
            nCurrVertexCount += v17;
            nCurrIndexCount += (int)pVert;
            pVert = m_pMemory[v113 / 0x2Cu].m_Element.m_aPrimVerts.m_Memory.m_pMemory;
            if ( pMesh == nullptr )
            {
              if ( bWireframeFragments || bBoundMaterial )
              {
                v21 = renderQueueHead;
                v20 = pRenderContext;
              }
              else
              {
                v19 = *(void **)(v15 + 144);
                v20 = pRenderContext;
                v21 = renderQueueHead;
                pRenderContext->Bind(this: pRenderContext, a2: renderQueueHead->m_pMaterial, a3: v19);
                v20->BindLightmapPage(this: v20, a2: v21->m_nLightmapPage);
                if ( v21->m_pMaterial->GetPropertyFlag(this: v21->m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP)
                  || (v22 = v21->m_pMaterial->GetPropertyFlag(
                              this: v21->m_pMaterial,
                              a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS),
                      bLightmappedMaterial = false,
                      v22) )
                {
                  bLightmappedMaterial = true;
                }
                bBoundMaterial = true;
              }
              v23 = v20->GetDynamicMesh(this: v20, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
              m_nIndexCount = v21->m_Queue[nSortGroup].m_nIndexCount;
              pMesh = v23;
              if ( m_nIndexCount >= nMaxIndices )
                m_nIndexCount = nMaxIndices;
              v25 = v21->m_Queue[nSortGroup].m_nVertexCount;
              if ( v25 >= nMaxVertices )
                v25 = nMaxVertices;
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: v23,
                type: MATERIAL_TRIANGLES,
                nVertexCount: v25,
                nIndexCount: m_nIndexCount,
                pMeshSettings: nullptr);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            v26 = pVert;
            v27 = nullptr;
            if ( bLightmappedMaterial )
            {
              decalOffset = m_pMemory[v113 / 0x2Cu].m_Element.decalOffset;
              v29 = nVertCount;
              if ( nVertCount >= 4 )
              {
                v30 = ((unsigned int)(nVertCount - 4) >> 2) + 1;
                p_z = &pVert[1].pos.z;
                pVert = (const overlayvert_t *)(4 * v30);
                do
                {
                  *m_pCurrPosition = v26->pos.x;
                  m_pCurrPosition[1] = *(p_z - 14);
                  m_pCurrPosition[2] = *(p_z - 13);
                  m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(p_z - 12);
                  m_pCurrNormal[1] = *(p_z - 11);
                  m_pCurrNormal[2] = *(p_z - 10);
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z - 3);
                  v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(p_z - 9);
                  v33[1] = *(p_z - 8);
                  v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(p_z - 5);
                  v34[1] = *(p_z - 4);
                  v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v35[1] = 0.0;
                  v36 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v36;
                  if ( v36 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v36;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v37 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v37;
                  *v37 = *(p_z - 2);
                  v37[1] = *(p_z - 1);
                  v37[2] = *p_z;
                  v38 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[1];
                  v38[1] = p_z[2];
                  v38[2] = p_z[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 10);
                  v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[4];
                  v39[1] = p_z[5];
                  v40 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[8];
                  v40[1] = p_z[9];
                  v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v41[1] = 0.0;
                  v42 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v42;
                  if ( v42 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v42;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v43 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v43;
                  *v43 = p_z[11];
                  v43[1] = p_z[12];
                  v43[2] = p_z[13];
                  v44 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[14];
                  v44[1] = p_z[15];
                  v44[2] = p_z[16];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 23);
                  v45 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[17];
                  v45[1] = p_z[18];
                  v46 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[21];
                  v46[1] = p_z[22];
                  v47 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v47[1] = 0.0;
                  v48 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v48;
                  if ( v48 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v48;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v49 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v49;
                  *v49 = p_z[24];
                  v49[1] = p_z[25];
                  v49[2] = p_z[26];
                  v50 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_z[27];
                  v50[1] = p_z[28];
                  v50[2] = p_z[29];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)p_z + 36);
                  v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[30];
                  v51[1] = p_z[31];
                  v52 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[34];
                  v52[1] = p_z[35];
                  v53 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v53[1] = 0.0;
                  v54 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v54;
                  if ( v54 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v54;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v26 += 4;
                  p_z += 52;
                  --v30;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v30 != 0 );
                m_Size = polyList.m_Size;
                v27 = pVert;
              }
              if ( (int)v27 < v29 )
              {
                v55 = &v26->pos.z;
                v56 = v29 - (_DWORD)v27;
                do
                {
                  *m_pCurrPosition = *(v55 - 2);
                  m_pCurrPosition[1] = *(v55 - 1);
                  m_pCurrPosition[2] = *v55;
                  v57 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v55[1];
                  v57[1] = v55[2];
                  v57[2] = v55[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v55 + 10);
                  v58 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v55[4];
                  v58[1] = v55[5];
                  v59 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v55[8];
                  v59[1] = v55[9];
                  v60 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = decalOffset;
                  v60[1] = 0.0;
                  v61 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v61;
                  if ( v61 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v61;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v55 += 13;
                  --v56;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v56 != 0 );
                goto LABEL_86;
              }
            }
            else
            {
              v62 = nVertCount;
              if ( nVertCount >= 4 )
              {
                v63 = ((unsigned int)(nVertCount - 4) >> 2) + 1;
                v64 = &pVert[1].pos.z;
                pVert = (const overlayvert_t *)(4 * v63);
                do
                {
                  *m_pCurrPosition = v26->pos.x;
                  m_pCurrPosition[1] = *(v64 - 14);
                  m_pCurrPosition[2] = *(v64 - 13);
                  v65 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(v64 - 12);
                  v65[1] = *(v64 - 11);
                  v65[2] = *(v64 - 10);
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 - 3);
                  v66 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(v64 - 9);
                  v66[1] = *(v64 - 8);
                  v67 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(v64 - 5);
                  v67[1] = *(v64 - 4);
                  v68 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = *(v64 - 7);
                  v68[1] = *(v64 - 6);
                  v69 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v69;
                  if ( v69 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v69;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v70 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v70;
                  *v70 = *(v64 - 2);
                  v70[1] = *(v64 - 1);
                  v70[2] = *v64;
                  v71 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[1];
                  v71[1] = v64[2];
                  v71[2] = v64[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 10);
                  v72 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[4];
                  v72[1] = v64[5];
                  v73 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[8];
                  v73[1] = v64[9];
                  v74 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[6];
                  v74[1] = v64[7];
                  v75 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v75;
                  if ( v75 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v75;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v76 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v76;
                  *v76 = v64[11];
                  v76[1] = v64[12];
                  v76[2] = v64[13];
                  v77 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[14];
                  v77[1] = v64[15];
                  v77[2] = v64[16];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 23);
                  v78 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[17];
                  v78[1] = v64[18];
                  v79 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[21];
                  v79[1] = v64[22];
                  v80 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[19];
                  v80[1] = v64[20];
                  v81 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v81;
                  if ( v81 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v81;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  v82 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = v82;
                  *v82 = v64[24];
                  v82[1] = v64[25];
                  v82[2] = v64[26];
                  v83 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v64[27];
                  v83[1] = v64[28];
                  v83[2] = v64[29];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v64 + 36);
                  v84 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v64[30];
                  v84[1] = v64[31];
                  v85 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v64[34];
                  v85[1] = v64[35];
                  v86 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v64[32];
                  v86[1] = v64[33];
                  v87 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v87;
                  if ( v87 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v87;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v26 += 4;
                  v64 += 52;
                  --v63;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v63 != 0 );
                m_Size = polyList.m_Size;
                v27 = pVert;
              }
              if ( (int)v27 < v62 )
              {
                v88 = &v26->pos.z;
                v89 = v62 - (_DWORD)v27;
                do
                {
                  *m_pCurrPosition = *(v88 - 2);
                  m_pCurrPosition[1] = *(v88 - 1);
                  m_pCurrPosition[2] = *v88;
                  v90 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v88[1];
                  v90[1] = v88[2];
                  v90[2] = v88[3];
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((_DWORD *)v88 + 10);
                  v91 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v88[4];
                  v91[1] = v88[5];
                  v92 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v88[8];
                  v92[1] = v88[9];
                  v93 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
                  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v88[6];
                  v93[1] = v88[7];
                  v94 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v94;
                  if ( v94 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                    meshBuilder.m_VertexBuilder.m_nVertexCount = v94;
                  meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                  m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                  v88 += 13;
                  --v89;
                  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                }
                while ( v89 != 0 );
LABEL_86:
                m_Size = polyList.m_Size;
              }
            }
            v95 = m_Size;
            if ( m_Size + 1 > polyList.m_Memory.m_nAllocationCount )
            {
              pVert = (const overlayvert_t *)(m_Size - polyList.m_Memory.m_nAllocationCount + 1);
              if ( polyList.m_Memory.m_nGrowSize < 0 )
              {
                polyList.m_Memory.m_nGrowSize = polyList.m_Memory.m_nMallocGrowSize;
                if ( polyList.m_Memory.m_nAllocationCount != 0 )
                {
                  v96 = 4 * polyList.m_Memory.m_nAllocationCount;
                  v97 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                             this: _g_pMemAlloc,
                                             a2: 4 * polyList.m_Memory.m_nAllocationCount);
                  memcpy(dst: v97, src: (unsigned __int8 *)polyList.m_Memory.m_pMemory, count: v96);
                  polyList.m_Memory.m_pMemory = (int *)v97;
                }
                else
                {
                  polyList.m_Memory.m_pMemory = nullptr;
                }
              }
              CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&polyList, num: (int)pVert);
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            polyList.m_Size = ++m_Size;
            polyList.m_pElements = polyList.m_Memory.m_pMemory;
            if ( m_Size - v95 - 1 > 0 )
            {
              _V_memmove(
                dest: &polyList.m_Memory.m_pMemory[v95 + 1],
                src: &polyList.m_Memory.m_pMemory[v95],
                count: 4 * (m_Size - v95 - 1));
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
            v98 = &polyList.m_Memory.m_pMemory[v95];
            if ( v98 != nullptr )
            {
              *v98 = nVertCount;
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              m_Size = polyList.m_Size;
            }
          }
LABEL_97:
          m_pMemory = v114->m_aFragments.m_Memory.m_pMemory;
          m_hNextRender = m_pMemory[v113 / 0x2Cu].m_Element.m_hNextRender;
        }
        while ( m_hNextRender != 0xFFFF );
        v99 = pMesh;
        if ( pMesh != nullptr )
        {
          CIndexBuilder::FastPolygonList(
            this: &meshBuilder.m_IndexBuilder,
            startVert: 0,
            pVertexCount: polyList.m_Memory.m_pMemory,
            polygonCount: m_Size);
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v100 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v100 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v100 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v100 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v100 = 0;
                break;
              default:
                v100 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: v100);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          v99->Draw_2(this: v99, a2: -1, a3: 0);
        }
        v101 = polyList.m_Memory.m_pMemory;
        polyList.m_Size = 0;
        if ( polyList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( polyList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: polyList.m_Memory.m_pMemory);
            v101 = nullptr;
            polyList.m_Memory.m_pMemory = nullptr;
          }
          polyList.m_Memory.m_nAllocationCount = 0;
        }
        polyList.m_pElements = v101;
        if ( polyList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v101 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v101);
            polyList.m_Memory.m_pMemory = nullptr;
          }
          polyList.m_Memory.m_nAllocationCount = 0;
        }
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
      }
      while ( (_WORD)hStartFragment != 0xFFFF );
LABEL_124:
      LOWORD(v6) = nNextRenderQueue;
    }
    while ( nNextRenderQueue != 0xFFFF );
LABEL_125:
    if ( ++iCurrentRenderOrder <= iHighestRenderOrder )
    {
      v3 = v114;
      continue;
    }
    break;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100F9620
// Name: private: bool COverlayMgr::Surf_PreClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::Surf_PreClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag)
{
  float y; // xmm0_4
  float x; // xmm1_4
  overlayvert_t *m_pMemory; // ecx
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  int m_Size; // ebx
  int v42; // ecx
  int v43; // edx
  unsigned int v44; // edi
  overlayvert_t *v45; // ecx
  float z; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float *p_x; // ecx
  float v52; // xmm0_4
  overlayvert_t *v53; // ecx
  float v54; // xmm3_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  float v58; // xmm4_4
  float *v59; // ecx
  float v60; // xmm0_4
  overlayvert_t *v61; // ecx
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm4_4
  float *v66; // ecx
  float v67; // xmm5_4
  float v68; // xmm0_4
  overlayvert_t *v69; // ecx
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm5_4
  float v73; // xmm2_4
  float v74; // xmm4_4
  float *v75; // ecx
  float v76; // xmm0_4
  int v77; // edx
  int v78; // ebx
  overlayvert_t *v79; // ecx
  float v80; // xmm3_4
  float v81; // xmm2_4
  float v82; // xmm4_4
  float v83; // xmm1_4
  float *v84; // ecx
  float v85; // xmm7_4
  float v86; // xmm0_4
  int iVert; // [esp+1Ch] [ebp+8h]
  float overlayFraga; // [esp+20h] [ebp+Ch]
  float overlayFragb; // [esp+20h] [ebp+Ch]
  float overlayFragc; // [esp+20h] [ebp+Ch]
  float overlayFragd; // [esp+20h] [ebp+Ch]
  float overlayFrage; // [esp+20h] [ebp+Ch]

  overlayFrag->m_aPrimVerts.m_Size = 0;
  CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
    this: &overlayFrag->m_aPrimVerts,
    elem: 0,
    num: 4);
  y = pOverlay->m_vecUVPoints[0].y;
  x = pOverlay->m_vecUVPoints[0].x;
  m_pMemory = overlayFrag->m_aPrimVerts.m_Memory.m_pMemory;
  v9 = pOverlay->m_vecBasis[1].x * y;
  v10 = y * pOverlay->m_vecBasis[1].z;
  v11 = pOverlay->m_vecUVPoints[0].y * pOverlay->m_vecBasis[1].y;
  v12 = (float)(pOverlay->m_vecBasis[0].x * x) + v9;
  v13 = x * pOverlay->m_vecBasis[0].y;
  v14 = x * pOverlay->m_vecBasis[0].z;
  m_pMemory->pos.x = v12;
  v15 = v14 + v10;
  m_pMemory->pos.z = v15;
  v16 = v13 + v11;
  m_pMemory->pos.y = v16;
  m_pMemory->pos.x = v12 + pOverlay->m_vecOrigin.x;
  m_pMemory->pos.y = v16 + pOverlay->m_vecOrigin.y;
  m_pMemory->pos.z = pOverlay->m_vecOrigin.z + v15;
  v17 = pOverlay->m_vecUVPoints[1].y;
  v18 = pOverlay->m_vecUVPoints[1].x;
  v19 = pOverlay->m_vecUVPoints[1].y * pOverlay->m_vecBasis[1].y;
  v20 = pOverlay->m_vecBasis[0].x * v18;
  v21 = pOverlay->m_vecUVPoints[1].x * pOverlay->m_vecBasis[0].y;
  v22 = (float)(v18 * pOverlay->m_vecBasis[0].z) + (float)(v17 * pOverlay->m_vecBasis[1].z);
  m_pMemory[1].pos.x = v20 + (float)(pOverlay->m_vecBasis[1].x * v17);
  m_pMemory[1].pos.y = v21 + v19;
  m_pMemory[1].pos.z = v22;
  m_pMemory[1].pos.x = m_pMemory[1].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[1].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[1].pos.y;
  m_pMemory[1].pos.z = m_pMemory[1].pos.z + pOverlay->m_vecOrigin.z;
  v23 = pOverlay->m_vecUVPoints[2].y;
  v24 = pOverlay->m_vecUVPoints[2].x;
  v25 = pOverlay->m_vecBasis[0].x * v24;
  v26 = pOverlay->m_vecUVPoints[2].x * pOverlay->m_vecBasis[0].y;
  v27 = v24 * pOverlay->m_vecBasis[0].z;
  v28 = pOverlay->m_vecBasis[1].x * v23;
  v29 = pOverlay->m_vecUVPoints[2].y * pOverlay->m_vecBasis[1].y;
  v30 = v23 * pOverlay->m_vecBasis[1].z;
  m_pMemory[2].pos.x = v25 + v28;
  m_pMemory[2].pos.y = v26 + v29;
  m_pMemory[2].pos.z = v27 + v30;
  m_pMemory[2].pos.x = m_pMemory[2].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[2].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[2].pos.y;
  m_pMemory[2].pos.z = m_pMemory[2].pos.z + pOverlay->m_vecOrigin.z;
  v31 = pOverlay->m_vecUVPoints[3].y;
  v32 = pOverlay->m_vecUVPoints[3].x;
  v33 = v31 * pOverlay->m_vecBasis[1].y;
  v34 = pOverlay->m_vecBasis[0].x * v32;
  v35 = v32 * pOverlay->m_vecBasis[0].y;
  v36 = (float)(v32 * pOverlay->m_vecBasis[0].z) + (float)(v31 * pOverlay->m_vecBasis[1].z);
  m_pMemory[3].pos.x = v34 + (float)(pOverlay->m_vecBasis[1].x * v31);
  m_pMemory[3].pos.y = v35 + v33;
  m_pMemory[3].pos.z = v36;
  m_pMemory[3].pos.x = m_pMemory[3].pos.x + pOverlay->m_vecOrigin.x;
  m_pMemory[3].pos.y = pOverlay->m_vecOrigin.y + m_pMemory[3].pos.y;
  m_pMemory[3].pos.z = m_pMemory[3].pos.z + pOverlay->m_vecOrigin.z;
  v37 = pOverlay->m_flV[0];
  m_pMemory->texCoord[0].x = pOverlay->m_flU[0];
  m_pMemory->texCoord[0].y = v37;
  v38 = pOverlay->m_flV[1];
  m_pMemory[1].texCoord[0].x = pOverlay->m_flU[0];
  m_pMemory[1].texCoord[0].y = v38;
  v39 = pOverlay->m_flV[1];
  m_pMemory[2].texCoord[0].x = pOverlay->m_flU[1];
  m_pMemory[2].texCoord[0].y = v39;
  v40 = pOverlay->m_flV[0];
  m_pMemory[3].texCoord[0].x = pOverlay->m_flU[1];
  m_pMemory[3].texCoord[0].y = v40;
  m_pMemory->texCoord[1].x = 0.0;
  m_pMemory->texCoord[1].y = 0.0;
  m_pMemory[1].texCoord[1].x = 0.0;
  m_pMemory[1].texCoord[1].y = 1.0;
  m_pMemory[2].texCoord[1].x = 1.0;
  m_pMemory[2].texCoord[1].y = 1.0;
  m_pMemory[3].texCoord[1].x = 1.0;
  m_pMemory[3].texCoord[1].y = 0.0;
  m_Size = surfaceFrag->m_aPrimVerts.m_Size;
  v42 = 0;
  if ( m_Size >= 4 )
  {
    v43 = 0;
    v44 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    iVert = 4 * v44;
    do
    {
      v45 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      z = v45[v43].pos.z;
      v47 = v45[v43].pos.x;
      v48 = v45[v43].pos.y;
      v49 = pOverlay->m_vecBasis[2].x;
      v50 = pOverlay->m_vecBasis[2].y;
      p_x = &v45[v43].pos.x;
      overlayFraga = pOverlay->m_vecBasis[2].z;
      v52 = (float)((float)(v49 * (float)(v47 - pOverlay->m_vecOrigin.x))
                  + (float)(v50 * (float)(v48 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFraga * (float)(z - pOverlay->m_vecOrigin.z));
      *p_x = v47 - (float)(v49 * v52);
      p_x[1] = v48 - (float)(v50 * v52);
      p_x[2] = z - (float)(overlayFraga * v52);
      v53 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v54 = v53[v43 + 1].pos.z;
      v55 = v53[v43 + 1].pos.x;
      v56 = v53[v43 + 1].pos.y;
      v57 = pOverlay->m_vecBasis[2].x;
      v58 = pOverlay->m_vecBasis[2].y;
      v59 = &v53[v43 + 1].pos.x;
      overlayFragb = pOverlay->m_vecBasis[2].z;
      v60 = (float)((float)(v57 * (float)(v55 - pOverlay->m_vecOrigin.x))
                  + (float)(v58 * (float)(v56 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragb * (float)(v54 - pOverlay->m_vecOrigin.z));
      *v59 = v55 - (float)(v57 * v60);
      v59[1] = v56 - (float)(v58 * v60);
      v59[2] = v54 - (float)(overlayFragb * v60);
      v61 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v62 = v61[v43 + 2].pos.z;
      v63 = v61[v43 + 2].pos.x;
      v64 = v61[v43 + 2].pos.y;
      v65 = pOverlay->m_vecBasis[2].y;
      v66 = &v61[v43 + 2].pos.x;
      v67 = pOverlay->m_vecBasis[2].x;
      overlayFragc = pOverlay->m_vecBasis[2].z;
      v68 = (float)((float)(v67 * (float)(v63 - pOverlay->m_vecOrigin.x))
                  + (float)(v65 * (float)(v64 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragc * (float)(v62 - pOverlay->m_vecOrigin.z));
      *v66 = v63 - (float)(v67 * v68);
      v66[1] = v64 - (float)(v65 * v68);
      v66[2] = v62 - (float)(overlayFragc * v68);
      v69 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v70 = v69[v43 + 3].pos.z;
      v71 = v69[v43 + 3].pos.x;
      v72 = pOverlay->m_vecBasis[2].x;
      v73 = v69[v43 + 3].pos.y;
      v74 = pOverlay->m_vecBasis[2].y;
      v75 = &v69[v43 + 3].pos.x;
      overlayFragd = pOverlay->m_vecBasis[2].z;
      v76 = (float)((float)(v72 * (float)(v71 - pOverlay->m_vecOrigin.x))
                  + (float)(v74 * (float)(v73 - pOverlay->m_vecOrigin.y)))
          + (float)(overlayFragd * (float)(v70 - pOverlay->m_vecOrigin.z));
      *v75 = v71 - (float)(v72 * v76);
      v43 += 4;
      --v44;
      v75[1] = v73 - (float)(v74 * v76);
      v75[2] = v70 - (float)(overlayFragd * v76);
    }
    while ( v44 != 0 );
    v42 = iVert;
  }
  if ( v42 < m_Size )
  {
    v77 = v42;
    v78 = m_Size - v42;
    do
    {
      v79 = surfaceFrag->m_aPrimVerts.m_Memory.m_pMemory;
      v80 = v79[v77].pos.z;
      v81 = v79[v77].pos.y;
      v82 = pOverlay->m_vecBasis[2].y;
      v83 = v79[v77].pos.x;
      v84 = &v79[v77].pos.x;
      overlayFrage = pOverlay->m_vecBasis[2].z;
      v85 = pOverlay->m_vecBasis[2].x;
      v86 = (float)((float)(v82 * (float)(v81 - pOverlay->m_vecOrigin.y))
                  + (float)(v85 * (float)(v83 - pOverlay->m_vecOrigin.x)))
          + (float)(overlayFrage * (float)(v80 - pOverlay->m_vecOrigin.z));
      ++v77;
      --v78;
      *v84 = v83 - (float)(v85 * v86);
      v84[1] = v81 - (float)(v82 * v86);
      v84[2] = v80 - (float)(overlayFrage * v86);
    }
    while ( v78 != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F9F50
// Name: private: int COverlayMgr::GetMaterialSortID(class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COverlayMgr::GetMaterialSortID(COverlayMgr *this, IMaterial *pMaterial, int nLightmapPage)
{
  int result; // eax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // esi
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short> > *p_m_RenderQueue; // ebx
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // si
  unsigned __int16 v8; // ax
  int v9; // esi
  int v10; // eax

  LOWORD(result) = this->m_RenderQueue.m_Head;
  if ( (_WORD)result == 0xFFFF )
  {
LABEL_6:
    p_m_RenderQueue = &this->m_RenderQueue;
    v6 = CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_RenderQueue,
           multilist: false);
    v7 = v6;
    if ( v6 == 0xFFFF )
    {
      v8 = -1;
    }
    else
    {
      CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_RenderQueue,
        before: 0xFFFFu,
        elem: v6);
      v8 = v7;
    }
    v9 = v8;
    v10 = (int)&p_m_RenderQueue->m_Memory.m_pMemory[v8];
    *(_DWORD *)(v10 + 4) = nLightmapPage;
    *(_WORD *)(v10 + 40) = 1;
    *(_DWORD *)v10 = pMaterial;
    *(_DWORD *)(v10 + 8) = -1;
    *(_DWORD *)(v10 + 16) = -1;
    *(_DWORD *)(v10 + 12) = 0;
    *(_DWORD *)(v10 + 20) = 0;
    *(_DWORD *)(v10 + 24) = -1;
    *(_DWORD *)(v10 + 28) = 0;
    *(_DWORD *)(v10 + 32) = -1;
    *(_DWORD *)(v10 + 36) = 0;
    pMaterial->IncrementReferenceCount(this: pMaterial);
    return v9;
  }
  else
  {
    m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
    while ( m_pMemory[(unsigned __int16)result].m_Element.m_pMaterial != pMaterial
         || m_pMemory[(unsigned __int16)result].m_Element.m_nLightmapPage != nLightmapPage )
    {
      LOWORD(result) = m_pMemory[(unsigned __int16)result].m_Next;
      if ( (_WORD)result == 0xFFFF )
        goto LABEL_6;
    }
    result = (unsigned __int16)result;
    ++m_pMemory[(unsigned __int16)result].m_Element.m_nRefCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FA040
// Name: public: virtual void COverlayMgr::ReSortMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::ReSortMaterials(COverlayMgr *this)
{
  int m_Size; // eax
  moverlay_t *v3; // eax
  int m_nTexInfo; // ecx
  bool v5; // zf
  mtexinfo_t *v6; // ecx
  int j; // eax
  int v8; // edi
  int v9; // esi
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v10; // esi
  unsigned __int16 MaterialSortID; // ax
  msurface2_t *m_SurfId; // edx
  int v13; // edi
  SurfaceCtx_t ctx; // [esp+Ch] [ebp-40h] BYREF
  Vector2D uv; // [esp+30h] [ebp-1Ch] BYREF
  int v16; // [esp+38h] [ebp-14h]
  int i; // [esp+3Ch] [ebp-10h]
  mtexinfo_t *pTexInfo; // [esp+40h] [ebp-Ch]
  int v19; // [esp+44h] [ebp-8h]
  unsigned int v20; // [esp+48h] [ebp-4h]

  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderQueue);
  if ( this->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderQueue.m_Memory.m_pMemory);
      this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
  this->m_RenderQueue.m_FirstFree = -1;
  this->m_RenderQueue.m_pElements = this->m_RenderQueue.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_RenderQueue.m_NumAlloced = -65536;
  *(_DWORD *)this->m_nFirstRenderQueue = -1;
  *(_DWORD *)&this->m_nFirstRenderQueue[2] = -1;
  m_Size = this->m_aOverlays.m_Size;
  if ( m_Size > 0 )
  {
    v20 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v3 = &this->m_aOverlays.m_Memory.m_pMemory[v20 / 0xA8];
      if ( v3 != nullptr )
      {
        m_nTexInfo = v3->m_nTexInfo;
        v5 = &host_state.worldbrush->texinfo[m_nTexInfo] == nullptr;
        v6 = &host_state.worldbrush->texinfo[m_nTexInfo];
        pTexInfo = v6;
        if ( !v5 )
        {
          for ( j = v3->m_hFirstFragment;
                j != 0xFFFF;
                j = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Next + v8) )
          {
            v8 = 6 * (unsigned __int16)j;
            v9 = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Element + v8);
            v5 = &this->m_aFragments.m_Memory.m_pMemory[v9] == nullptr;
            v10 = &this->m_aFragments.m_Memory.m_pMemory[v9];
            v16 = v8;
            if ( !v5 )
            {
              MaterialSortID = COverlayMgr::GetMaterialSortID(
                                 this,
                                 pMaterial: v6->material,
                                 nLightmapPage: materialSortInfoArray[v10->m_Element.m_SurfId->materialSortID].lightmapPageID);
              m_SurfId = v10->m_Element.m_SurfId;
              v10->m_Element.m_nMaterialSortID = MaterialSortID;
              SurfSetupSurfaceContext(&ctx, surfID: m_SurfId);
              if ( v10->m_Element.m_aPrimVerts.m_Size > 0 )
              {
                v13 = 0;
                v19 = v10->m_Element.m_aPrimVerts.m_Size;
                do
                {
                  SurfComputeLightmapCoordinate(
                    &ctx,
                    surfID: v10->m_Element.m_SurfId,
                    vec: &v10->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v13].pos,
                    &uv);
                  *(Vector2D *)v10->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v13++].lightCoord = uv;
                  --v19;
                }
                while ( v19 != 0 );
                v8 = v16;
              }
              v6 = pTexInfo;
            }
          }
        }
      }
      v20 += 168;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA1C0
// Name: private: unsigned short COverlayMgr::AddFragmentToFragmentList(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall COverlayMgr::AddFragmentToFragmentList(COverlayMgr *this, int nSize)
{
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *p_m_aFragments; // edi
  int v3; // ecx
  unsigned __int16 v4; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v5; // eax
  unsigned __int16 v6; // si
  int v7; // eax

  p_m_aFragments = &this->m_aFragments;
  v3 = (unsigned __int16)CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_aFragments,
                           multilist: true);
  v4 = -1;
  if ( (_WORD)v3 != 0xFFFF )
  {
    v5 = &p_m_aFragments->m_Memory.m_pMemory[v3];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v5->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v5->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v5->m_Element.m_aPrimVerts.m_Size = 0;
      v5->m_Element.m_aPrimVerts.m_pElements = nullptr;
    }
    v4 = v3;
  }
  v6 = v4;
  v7 = (int)&p_m_aFragments->m_Memory.m_pMemory[v4];
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = -1;
  *(_DWORD *)v7 = -1;
  *(_DWORD *)(v7 + 12) = -1;
  if ( nSize > 0 )
  {
    *(_DWORD *)(v7 + 28) = 0;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)(v7 + 16),
      elem: 0,
      num: nSize);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100FA240
// Name: public: virtual void COverlayMgr::UnloadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::UnloadOverlays(COverlayMgr *this)
{
  COverlayMgr *v1; // esi
  int m_Head; // eax
  UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short> *m_pMemory; // ecx
  int v4; // edi
  int i; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v6; // edx
  unsigned int v7; // edi
  int m_Element; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v9; // esi
  bool v10; // sf
  overlayvert_t *v11; // eax
  int m_Size; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]

  v1 = this;
  m_Head = this->m_RenderQueue.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Head;
      m_pMemory[(unsigned __int16)m_Head].m_Element.m_pMaterial->DecrementReferenceCount(this: m_pMemory[(unsigned __int16)m_Head].m_Element.m_pMaterial);
      m_pMemory = v1->m_RenderQueue.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  if ( v1->m_aOverlays.m_Size > 0 )
  {
    v13 = 0;
    m_Size = v1->m_aOverlays.m_Size;
    do
    {
      for ( i = v1->m_aOverlays.m_Memory.m_pMemory[v13].m_hFirstFragment; i != 0xFFFF; v1 = this )
      {
        v6 = v1->m_OverlayFragments.m_Memory.m_pMemory;
        v7 = (unsigned __int16)i;
        m_Element = v6[v7].m_Element;
        CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
          this: &v1->m_aFragments,
          elem: v6[v7].m_Element);
        v9 = &this->m_aFragments.m_Memory.m_pMemory[m_Element];
        v10 = v9->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
        v9->m_Element.m_aPrimVerts.m_Size = 0;
        if ( !v10 )
        {
          if ( v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory);
            v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
          }
          v9->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
        }
        v10 = v9->m_Element.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
        v11 = v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
        v9->m_Element.m_aPrimVerts.m_pElements = v11;
        if ( !v10 )
        {
          if ( v11 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
            v9->m_Element.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
          }
          v9->m_Element.m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
        }
        v9->m_Next = this->m_aFragments.m_FirstFree;
        this->m_aFragments.m_FirstFree = m_Element;
        i = this->m_OverlayFragments.m_Memory.m_pMemory[v7].m_Next;
      }
      ++v13;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::RemoveAll(this: &v1->m_aOverlays);
  if ( v1->m_aOverlays.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_aOverlays.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_aOverlays.m_Memory.m_pMemory);
      v1->m_aOverlays.m_Memory.m_pMemory = nullptr;
    }
    v1->m_aOverlays.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_aOverlays.m_pElements = v1->m_aOverlays.m_Memory.m_pMemory;
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_aFragments);
  if ( v1->m_aFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_aFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_aFragments.m_Memory.m_pMemory);
      v1->m_aFragments.m_Memory.m_pMemory = nullptr;
    }
    v1->m_aFragments.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_aFragments.m_FirstFree = -1;
  v1->m_aFragments.m_pElements = v1->m_aFragments.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_aFragments.m_NumAlloced = -65536;
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_OverlayFragments);
  if ( v1->m_OverlayFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_OverlayFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_OverlayFragments.m_Memory.m_pMemory);
      v1->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
    }
    v1->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_OverlayFragments.m_FirstFree = -1;
  v1->m_OverlayFragments.m_pElements = v1->m_OverlayFragments.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_OverlayFragments.m_NumAlloced = -65536;
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_RenderQueue);
  if ( v1->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_RenderQueue.m_Memory.m_pMemory);
      v1->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    v1->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_RenderQueue.m_FirstFree = -1;
  v1->m_RenderQueue.m_pElements = v1->m_RenderQueue.m_Memory.m_pMemory;
  *(_DWORD *)&v1->m_RenderQueue.m_NumAlloced = -65536;
  *(_DWORD *)v1->m_nFirstRenderQueue = -1;
  *(_DWORD *)&v1->m_nFirstRenderQueue[2] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA480
// Name: private: void COverlayMgr::Surf_PostClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_PostClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID)
{
  int m_Size; // eax
  unsigned __int16 v6; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *m_pMemory; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v8; // ebx
  overlayvert_t *v10; // edi
  _DWORD *p_z; // eax
  int j; // ecx
  float y; // xmm0_4
  float x; // xmm7_4
  float v15; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm7_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm0_4
  float v35; // xmm7_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  int v44; // edi
  cplane_t *plane; // eax
  float v46; // xmm2_4
  float v47; // xmm4_4
  float v48; // xmm7_4
  float v49; // xmm5_4
  float v50; // xmm0_4
  int v51; // eax
  float v52; // xmm5_4
  float v53; // xmm4_4
  char *texCoord; // eax
  overlayvert_t *v55; // ecx
  bool v56; // zf
  const Vector *v57; // eax
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float *p_x; // eax
  float v62; // xmm0_4
  COverlayMgr *v63; // ebx
  unsigned __int16 v64; // ax
  int v65; // eax
  unsigned __int16 v66; // cx
  unsigned __int16 m_Tail; // dx
  unsigned __int16 v68; // ax
  unsigned __int16 v69; // cx
  int v70; // edx
  unsigned __int16 v71; // cx
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *v72; // esi
  int m_nFirstOverlayFragment; // ebx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v74; // eax
  unsigned __int16 v75; // cx
  unsigned __int16 v76; // ax
  unsigned __int16 v77; // dx
  int v78; // ecx
  bool v79; // sf
  SurfaceCtx_t ctx; // [esp+4h] [ebp-9Ch] BYREF
  Vector2D vecUV; // [esp+28h] [ebp-78h] BYREF
  moverlayfragment_t origOverlay; // [esp+30h] [ebp-70h] BYREF
  Vector2D vecTexCoord; // [esp+58h] [ebp-48h] BYREF
  Vector2D uv; // [esp+60h] [ebp-40h] BYREF
  int v85; // [esp+68h] [ebp-38h]
  Vector vec; // [esp+6Ch] [ebp-34h] BYREF
  float dist; // [esp+78h] [ebp-28h]
  int v88; // [esp+7Ch] [ebp-24h]
  int v89; // [esp+80h] [ebp-20h]
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short> > *p_m_aFragments; // [esp+84h] [ebp-1Ch]
  int v91; // [esp+88h] [ebp-18h]
  COverlayMgr *v92; // [esp+8Ch] [ebp-14h]
  const Vector *vNormal; // [esp+90h] [ebp-10h]
  int m_hFirstFragment; // [esp+94h] [ebp-Ch]
  int hFragment; // [esp+98h] [ebp-8h]
  int nVertCount; // [esp+9Ch] [ebp-4h]
  overlayvert_t *pOverlaya; // [esp+A8h] [ebp+8h]
  moverlay_t *pOverlayb; // [esp+A8h] [ebp+8h]
  unsigned __int16 i; // [esp+ACh] [ebp+Ch]

  m_Size = overlayFrag->m_aPrimVerts.m_Size;
  v92 = this;
  nVertCount = m_Size;
  if ( m_Size != 0 )
  {
    v6 = COverlayMgr::AddFragmentToFragmentList(this, nSize: m_Size);
    m_pMemory = this->m_aFragments.m_Memory.m_pMemory;
    hFragment = v6;
    p_m_aFragments = &this->m_aFragments;
    v89 = 44 * v6;
    v8 = &m_pMemory[v89 / 0x2Cu];
    SurfSetupSurfaceContext(&ctx, surfID);
    v8->m_Element.m_iOverlay = pOverlay->m_nId;
    v8->m_Element.m_SurfId = surfID;
    v8->m_Element.decalOffset = ComputeDecalLightmapOffset(surfID);
    vNormal = &surfID->plane->normal;
    memset(&origOverlay.m_aPrimVerts, 0, sizeof(origOverlay.m_aPrimVerts));
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
      this: (CUtlMemory<SndInfo_t,int> *)&origOverlay.m_aPrimVerts,
      num: 4);
    v10 = origOverlay.m_aPrimVerts.m_Memory.m_pMemory;
    if ( origOverlay.m_aPrimVerts.m_Size > 0 )
      _V_memmove(
        dest: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[4],
        src: origOverlay.m_aPrimVerts.m_Memory.m_pMemory,
        count: 52 * origOverlay.m_aPrimVerts.m_Size);
    p_z = (_DWORD *)&v10->normal.z;
    for ( j = 4; j != 0; --j )
    {
      if ( p_z != (_DWORD *)20 )
      {
        *(p_z - 5) = 0;
        *(p_z - 4) = 0;
        *(p_z - 3) = 0;
        *(p_z - 2) = 0;
        *(p_z - 1) = 0;
        *p_z = 0;
        p_z[1] = 0;
        p_z[2] = 0;
        p_z[3] = 0;
        p_z[4] = 0;
        p_z[6] = 0;
        p_z[5] = 0;
        p_z[7] = -1;
      }
      p_z += 13;
    }
    y = pOverlay->m_vecUVPoints[0].y;
    x = pOverlay->m_vecUVPoints[0].x;
    v15 = pOverlay->m_vecBasis[0].y;
    z = pOverlay->m_vecBasis[0].z;
    v17 = pOverlay->m_vecBasis[1].y * y;
    v18 = pOverlay->m_vecBasis[1].z * y;
    v19 = (float)(pOverlay->m_vecBasis[0].x * x) + (float)(pOverlay->m_vecBasis[1].x * y);
    v10->pos.x = v19;
    v20 = (float)(v15 * x) + v17;
    v10->pos.y = v20;
    v21 = (float)(z * x) + v18;
    v10->pos.z = v21;
    v10->pos.x = pOverlay->m_vecOrigin.x + v19;
    v10->pos.y = v20 + pOverlay->m_vecOrigin.y;
    v10->pos.z = pOverlay->m_vecOrigin.z + v21;
    v22 = pOverlay->m_vecUVPoints[1].y;
    v23 = pOverlay->m_vecUVPoints[1].x;
    v24 = pOverlay->m_vecBasis[0].y;
    v25 = pOverlay->m_vecBasis[0].z;
    v26 = pOverlay->m_vecBasis[1].y * v22;
    v27 = pOverlay->m_vecBasis[1].z * v22;
    v10[1].pos.x = (float)(pOverlay->m_vecBasis[0].x * v23) + (float)(pOverlay->m_vecBasis[1].x * v22);
    v10[1].pos.y = (float)(v24 * v23) + v26;
    v10[1].pos.z = (float)(v25 * v23) + v27;
    v10[1].pos.x = pOverlay->m_vecOrigin.x + v10[1].pos.x;
    v10[1].pos.y = v10[1].pos.y + pOverlay->m_vecOrigin.y;
    v10[1].pos.z = pOverlay->m_vecOrigin.z + v10[1].pos.z;
    v28 = pOverlay->m_vecUVPoints[2].y;
    v29 = pOverlay->m_vecUVPoints[2].x;
    v30 = pOverlay->m_vecBasis[0].y;
    v31 = pOverlay->m_vecBasis[0].z;
    v32 = pOverlay->m_vecBasis[1].y * v28;
    v33 = pOverlay->m_vecBasis[1].z * v28;
    v10[2].pos.x = (float)(pOverlay->m_vecBasis[0].x * v29) + (float)(pOverlay->m_vecBasis[1].x * v28);
    v10[2].pos.y = (float)(v30 * v29) + v32;
    v10[2].pos.z = (float)(v31 * v29) + v33;
    v10[2].pos.x = pOverlay->m_vecOrigin.x + v10[2].pos.x;
    v10[2].pos.y = v10[2].pos.y + pOverlay->m_vecOrigin.y;
    v10[2].pos.z = pOverlay->m_vecOrigin.z + v10[2].pos.z;
    v34 = pOverlay->m_vecUVPoints[3].y;
    v35 = pOverlay->m_vecUVPoints[3].x;
    v36 = pOverlay->m_vecBasis[0].y;
    v37 = pOverlay->m_vecBasis[0].z;
    v38 = pOverlay->m_vecBasis[1].y * v34;
    v39 = pOverlay->m_vecBasis[1].z * v34;
    v10[3].pos.x = (float)(pOverlay->m_vecBasis[0].x * v35) + (float)(pOverlay->m_vecBasis[1].x * v34);
    v10[3].pos.y = (float)(v36 * v35) + v38;
    v10[3].pos.z = (float)(v37 * v35) + v39;
    v10[3].pos.x = pOverlay->m_vecOrigin.x + v10[3].pos.x;
    v10[3].pos.y = v10[3].pos.y + pOverlay->m_vecOrigin.y;
    v10[3].pos.z = pOverlay->m_vecOrigin.z + v10[3].pos.z;
    v40 = pOverlay->m_flV[0];
    v10->texCoord[0].x = pOverlay->m_flU[0];
    v10->texCoord[0].y = v40;
    v41 = pOverlay->m_flV[1];
    v10[1].texCoord[0].x = pOverlay->m_flU[0];
    v10[1].texCoord[0].y = v41;
    v42 = pOverlay->m_flV[1];
    v10[2].texCoord[0].x = pOverlay->m_flU[1];
    v10[2].texCoord[0].y = v42;
    v43 = pOverlay->m_flV[0];
    v10[3].texCoord[0].x = pOverlay->m_flU[1];
    v10[3].texCoord[0].y = v43;
    v10->texCoord[1].x = 0.0;
    v10->texCoord[1].y = 0.0;
    v10[1].texCoord[1].x = 0.0;
    v10[1].texCoord[1].y = 1.0;
    v10[2].texCoord[1].x = 1.0;
    v10[2].texCoord[1].y = 1.0;
    v10[3].texCoord[1].x = 1.0;
    v10[3].texCoord[1].y = 0.0;
    if ( nVertCount > 0 )
    {
      v85 = -104 - (_DWORD)v10;
      m_hFirstFragment = -128 - (_DWORD)v10;
      v44 = 0;
      v91 = nVertCount;
      do
      {
        PointInQuadToBarycentric(
          v1: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory->pos,
          v2: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[3].pos,
          v3: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].pos,
          v4: &origOverlay.m_aPrimVerts.m_Memory.m_pMemory[1].pos,
          point: &overlayFrag->m_aPrimVerts.m_Memory.m_pMemory[v44].pos,
          uv: &vecUV);
        nVertCount = (int)&v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44];
        pOverlaya = &overlayFrag->m_aPrimVerts.m_Memory.m_pMemory[v44];
        plane = surfID->plane;
        vec = plane->normal;
        dist = plane->dist;
        v88 = *(_DWORD *)&plane->type;
        VectorNormalize(&vec);
        v46 = pOverlaya->pos.y;
        v47 = pOverlaya->pos.z;
        v48 = pOverlay->m_vecBasis[2].x;
        v49 = (float)((float)(vec.y * pOverlay->m_vecBasis[2].y) + (float)(vec.x * v48))
            + (float)(vec.z * pOverlay->m_vecBasis[2].z);
        if ( v49 == 0.0 )
          v50 = (float)((float)((float)(vec.y * v46) + (float)(vec.x * pOverlaya->pos.x)) + (float)(vec.z * v47)) - dist;
        else
          v50 = (float)(1.0 / v49)
              * (float)((float)((float)((float)(vec.y * v46) + (float)(vec.x * pOverlaya->pos.x)) + (float)(vec.z * v47))
                      - dist);
        v51 = nVertCount;
        v52 = v50 * pOverlay->m_vecBasis[2].y;
        v53 = v47 - (float)(v50 * pOverlay->m_vecBasis[2].z);
        *(float *)nVertCount = pOverlaya->pos.x - (float)(v50 * v48);
        *(float *)(v51 + 4) = v46 - v52;
        *(float *)(v51 + 8) = v53;
        texCoord = (char *)origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].texCoord;
        pOverlayb = (moverlay_t *)origOverlay.m_aPrimVerts.m_Memory.m_pMemory[2].texCoord;
        nVertCount = 2;
        while ( 1 )
        {
          TexCoordInQuadFromBarycentric(
            v1: (const Vector2D *)texCoord - 13,
            v2: (const Vector2D *)(texCoord + 52),
            v3: (const Vector2D *)texCoord,
            v4: (const Vector2D *)(texCoord - 52),
            uv: &vecUV,
            texCoord: &vecTexCoord);
          *(int *)((char *)&pOverlayb->m_nId
                 + v44 * 52
                 + v85
                 + (unsigned int)v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory) = LODWORD(vecTexCoord.x);
          v55 = v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
          v56 = nVertCount-- == 1;
          *(float *)((char *)&v55->texCoord[0].y + (_DWORD)pOverlayb + v44 * 52 + m_hFirstFragment) = vecTexCoord.y;
          pOverlayb = (moverlay_t *)((char *)pOverlayb + 8);
          if ( v56 )
            break;
          texCoord = (char *)pOverlayb;
        }
        v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].normal = *vNormal;
        SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].pos, &uv);
        v57 = vNormal;
        *(Vector2D *)v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].lightCoord = uv;
        v58 = v57->x;
        v59 = v57->y;
        v60 = v57->z;
        p_x = &v8->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v44].pos.x;
        *p_x = (float)(v58 * 0.1) + *p_x;
        p_x[1] = p_x[1] + (float)(v59 * 0.1);
        v62 = p_x[2];
        ++v44;
        v56 = v91-- == 1;
        p_x[2] = v62 + (float)(v60 * 0.1);
      }
      while ( !v56 );
      v10 = origOverlay.m_aPrimVerts.m_Memory.m_pMemory;
    }
    v8->m_Element.m_nMaterialSortID = COverlayMgr::GetMaterialSortID(
                                        this: v92,
                                        pMaterial: host_state.worldbrush->texinfo[pOverlay->m_nTexInfo].material,
                                        nLightmapPage: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
    v63 = v92;
    v64 = CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
            this: &v92->m_OverlayFragments,
            multilist: true);
    if ( v64 == 0xFFFF )
      i = -1;
    else
      i = v64;
    v63->m_OverlayFragments.m_Memory.m_pMemory[i].m_Element = hFragment;
    m_hFirstFragment = pOverlay->m_hFirstFragment;
    CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
      this: &v63->m_OverlayFragments,
      elem: i);
    v65 = (int)&v63->m_OverlayFragments.m_Memory.m_pMemory[i];
    v66 = m_hFirstFragment;
    *(_WORD *)(v65 + 4) = m_hFirstFragment;
    if ( v66 == 0xFFFF )
    {
      m_Tail = v63->m_OverlayFragments.m_Tail;
      *(_WORD *)(v65 + 2) = m_Tail;
      v68 = i;
      v69 = m_Tail;
      v63->m_OverlayFragments.m_Tail = i;
    }
    else
    {
      v70 = (int)&v63->m_OverlayFragments.m_Memory.m_pMemory[v66];
      v69 = *(_WORD *)(v70 + 2);
      *(_WORD *)(v65 + 2) = v69;
      *(_WORD *)(v70 + 2) = i;
      v68 = i;
    }
    if ( v69 == 0xFFFF )
      v63->m_OverlayFragments.m_Head = v68;
    else
      v63->m_OverlayFragments.m_Memory.m_pMemory[v69].m_Next = v68;
    ++v63->m_OverlayFragments.m_ElementCount;
    v71 = hFragment;
    pOverlay->m_hFirstFragment = v68;
    v72 = p_m_aFragments;
    m_nFirstOverlayFragment = surfID->m_nFirstOverlayFragment;
    CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_aFragments,
      elem: v71);
    v74 = &v72->m_Memory.m_pMemory[v89 / 0x2Cu];
    v74->m_Next = m_nFirstOverlayFragment;
    if ( (_WORD)m_nFirstOverlayFragment == 0xFFFF )
    {
      v75 = v72->m_Tail;
      v74->m_Previous = v75;
      v76 = hFragment;
      v77 = v75;
      v72->m_Tail = hFragment;
    }
    else
    {
      v78 = (int)&v72->m_Memory.m_pMemory[m_nFirstOverlayFragment];
      v77 = *(_WORD *)(v78 + 40);
      v74->m_Previous = v77;
      *(_WORD *)(v78 + 40) = hFragment;
      v76 = hFragment;
    }
    if ( v77 == 0xFFFF )
      v72->m_Head = v76;
    else
      v72->m_Memory.m_pMemory[v77].m_Next = v76;
    ++v72->m_ElementCount;
    v79 = origOverlay.m_aPrimVerts.m_Memory.m_nGrowSize < 0;
    surfID->m_nFirstOverlayFragment = v76;
    if ( !v79 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FAC50
// Name: private: void COverlayMgr::Disp_PostClipFragment(class CDispInfo __near *,class CMeshReader __near *,struct moverlay_t __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_PostClipFragment(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CMeshReader *pReader,
        moverlay_t *pOverlay,
        CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragments,
        msurface2_t *surfID)
{
  int firstvertindex; // esi
  overlayvert_t *m_pMemory; // ebx
  _DWORD *p_z; // eax
  int i; // ecx
  mvertex_t *v10; // eax
  mvertex_t *v11; // eax
  mvertex_t *v12; // eax
  mvertex_t *v13; // eax
  double z; // st7
  const CPowerInfo *m_pPowerInfo; // eax
  int m_SideLength; // edi
  Vector2D *v17; // edx
  int v18; // esi
  int v19; // ecx
  float v20; // xmm0_4
  int v21; // ecx
  int m_Size; // eax
  int v23; // ecx
  moverlayfragment_t *v24; // edx
  int v25; // edx
  COverlayMgr *v26; // esi
  unsigned __int16 v27; // ax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v28; // edi
  int v29; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v30; // edi
  double v31; // st7
  bool v32; // cc
  int v33; // esi
  float x; // xmm0_4
  float v35; // xmm1_4
  float y; // xmm2_4
  moverlayfragment_t *v37; // edx
  overlayvert_t *v38; // eax
  overlayvert_t *v39; // ecx
  overlayvert_t *v40; // edx
  overlayvert_t *v41; // ecx
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_OverlayFragments; // edi
  unsigned __int16 v43; // ax
  unsigned __int16 v44; // si
  char *v45; // eax
  unsigned __int16 v46; // cx
  unsigned __int16 m_Tail; // dx
  unsigned __int16 v48; // cx
  int v49; // edx
  unsigned __int16 v50; // dx
  COverlayMgr *v51; // edi
  int m_nFirstOverlayFragment; // esi
  char *v53; // eax
  unsigned __int16 v54; // cx
  unsigned __int16 v55; // ax
  unsigned __int16 v56; // dx
  int v57; // ecx
  SurfaceCtx_t ctx; // [esp+4h] [ebp-98h] BYREF
  moverlayfragment_t surfaceFrag; // [esp+28h] [ebp-74h] BYREF
  Vector2D uv; // [esp+50h] [ebp-4Ch] BYREF
  Vector2D lightCoords[4]; // [esp+58h] [ebp-44h] BYREF
  int nFragCount; // [esp+78h] [ebp-24h]
  int v63; // [esp+7Ch] [ebp-20h]
  Vector2D vecTmpUV; // [esp+80h] [ebp-1Ch] BYREF
  int iFrag; // [esp+88h] [ebp-14h]
  COverlayMgr *v66; // [esp+8Ch] [ebp-10h]
  moverlayfragment_t *pDispFragment; // [esp+90h] [ebp-Ch]
  int hFragment; // [esp+94h] [ebp-8h]
  int nVertCount; // [esp+98h] [ebp-4h]

  v66 = this;
  if ( aDispFragments->m_Size != 0 )
  {
    SurfSetupSurfaceContext(&ctx, surfID);
    firstvertindex = surfID->firstvertindex;
    memset(&surfaceFrag.m_aPrimVerts, 0, sizeof(surfaceFrag.m_aPrimVerts));
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
      this: (CUtlMemory<SndInfo_t,int> *)&surfaceFrag.m_aPrimVerts,
      num: 4);
    m_pMemory = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
    surfaceFrag.m_aPrimVerts.m_Size += 4;
    surfaceFrag.m_aPrimVerts.m_pElements = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
    if ( surfaceFrag.m_aPrimVerts.m_Size - 4 > 0 )
      _V_memmove(
        dest: &surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory[4],
        src: surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory,
        count: 52 * (surfaceFrag.m_aPrimVerts.m_Size - 4));
    p_z = (_DWORD *)&m_pMemory->normal.z;
    for ( i = 4; i != 0; --i )
    {
      if ( p_z != (_DWORD *)20 )
      {
        *(p_z - 5) = 0;
        *(p_z - 4) = 0;
        *(p_z - 3) = 0;
        *(p_z - 2) = 0;
        *(p_z - 1) = 0;
        *p_z = 0;
        p_z[1] = 0;
        p_z[2] = 0;
        p_z[3] = 0;
        p_z[4] = 0;
        p_z[6] = 0;
        p_z[5] = 0;
        p_z[7] = -1;
      }
      p_z += 13;
    }
    v10 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
    m_pMemory->pos.x = v10->position.x;
    m_pMemory->pos.y = v10->position.y;
    m_pMemory->pos.z = v10->position.z;
    v11 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 1]];
    m_pMemory[1].pos.x = v11->position.x;
    m_pMemory[1].pos.y = v11->position.y;
    m_pMemory[1].pos.z = v11->position.z;
    v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 2]];
    m_pMemory[2].pos.x = v12->position.x;
    m_pMemory[2].pos.y = v12->position.y;
    m_pMemory[2].pos.z = v12->position.z;
    v13 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 3]];
    m_pMemory[3].pos.x = v13->position.x;
    m_pMemory[3].pos.y = v13->position.y;
    z = v13->position.z;
    m_pPowerInfo = pDisp->m_pPowerInfo;
    m_pMemory[3].pos.z = z;
    m_SideLength = m_pPowerInfo->m_SideLength;
    v17 = (Vector2D *)pReader->m_pTexCoord[1];
    v18 = pReader->m_VertexSize_TexCoord[1];
    v19 = v18 * (m_SideLength - 1);
    lightCoords[0] = *v17;
    lightCoords[1].x = *(float *)((char *)&v17->x + v19);
    v20 = *(float *)((char *)&v17->y + v19);
    v21 = m_SideLength * v19;
    lightCoords[1].y = v20;
    lightCoords[2] = *(Vector2D *)((char *)v17 + v18 * (m_SideLength * m_SideLength - 1));
    lightCoords[3].x = *(float *)((char *)&v17->x + v21);
    m_Size = aDispFragments->m_Size;
    lightCoords[3].y = *(float *)((char *)&v17->y + v21);
    nFragCount = m_Size;
    v23 = 0;
    for ( iFrag = 0; v23 < m_Size; iFrag = v23 )
    {
      v24 = aDispFragments->m_Memory.m_pMemory[v23];
      pDispFragment = v24;
      if ( v24 != nullptr )
      {
        v25 = v24->m_aPrimVerts.m_Size;
        nVertCount = v25;
        if ( v25 >= 3 )
        {
          v26 = v66;
          v27 = COverlayMgr::AddFragmentToFragmentList(this: v66, nSize: v25);
          v28 = v26->m_aFragments.m_Memory.m_pMemory;
          hFragment = v27;
          v29 = v27;
          v30 = &v28[v29];
          v63 = v29 * 44;
          v30->m_Element.m_iOverlay = pOverlay->m_nId;
          v30->m_Element.m_SurfId = surfID;
          v31 = ComputeDecalLightmapOffset(surfID);
          v32 = nVertCount <= 0;
          v30->m_Element.decalOffset = v31;
          if ( !v32 )
          {
            v33 = 0;
            do
            {
              x = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory[v33].pos.x;
              v35 = 0.0;
              vecTmpUV.x = x;
              y = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory[v33].pos.y;
              if ( x >= 0.0 )
              {
                if ( x > 1.0 )
                  x = 1.0;
              }
              else
              {
                x = 0.0;
              }
              vecTmpUV.x = x;
              if ( y >= 0.0 )
              {
                if ( y <= 1.0 )
                  v35 = y;
                else
                  v35 = 1.0;
              }
              vecTmpUV.y = v35;
              Overlay_DispUVToWorld(
                pDisp,
                pReader,
                vecUV: &vecTmpUV,
                vecWorld: &v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33].pos,
                vecWorldNormal: &v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33].normal,
                &surfaceFrag);
              v37 = pDispFragment;
              v38 = pDispFragment->m_aPrimVerts.m_Memory.m_pMemory;
              v39 = v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v39[v33].texCoord[0].x = v38[v33].texCoord[0].x;
              v39[v33].texCoord[0].y = v38[v33].texCoord[0].y;
              v40 = v37->m_aPrimVerts.m_Memory.m_pMemory;
              v41 = v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v41[v33].texCoord[1].x = v40[v33].texCoord[1].x;
              v41[v33].texCoord[1].y = v40[v33].texCoord[1].y;
              TexCoordInQuadFromBarycentric(
                v1: lightCoords,
                v2: &lightCoords[1],
                v3: &lightCoords[2],
                v4: &lightCoords[3],
                uv: &vecTmpUV,
                texCoord: &uv);
              *(Vector2D *)v30->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v33++].lightCoord = uv;
              --nVertCount;
            }
            while ( nVertCount != 0 );
            v26 = v66;
          }
          v30->m_Element.m_nMaterialSortID = COverlayMgr::GetMaterialSortID(
                                               this: v26,
                                               pMaterial: host_state.worldbrush->texinfo[pOverlay->m_nTexInfo].material,
                                               nLightmapPage: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
          p_m_OverlayFragments = &v26->m_OverlayFragments;
          v43 = CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
                  this: &v26->m_OverlayFragments,
                  multilist: true);
          v44 = -1;
          if ( v43 != 0xFFFF )
            v44 = v43;
          p_m_OverlayFragments->m_Memory.m_pMemory[v44].m_Element = hFragment;
          pDispFragment = (moverlayfragment_t *)(6 * v44);
          nVertCount = pOverlay->m_hFirstFragment;
          CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
            this: p_m_OverlayFragments,
            elem: v44);
          v45 = (char *)pDispFragment + (unsigned int)p_m_OverlayFragments->m_Memory.m_pMemory;
          v46 = nVertCount;
          *((_WORD *)v45 + 2) = nVertCount;
          if ( v46 == 0xFFFF )
          {
            m_Tail = p_m_OverlayFragments->m_Tail;
            *((_WORD *)v45 + 1) = m_Tail;
            v48 = m_Tail;
            p_m_OverlayFragments->m_Tail = v44;
          }
          else
          {
            v49 = (int)&p_m_OverlayFragments->m_Memory.m_pMemory[v46];
            v48 = *(_WORD *)(v49 + 2);
            *((_WORD *)v45 + 1) = v48;
            *(_WORD *)(v49 + 2) = v44;
          }
          if ( v48 == 0xFFFF )
            p_m_OverlayFragments->m_Head = v44;
          else
            p_m_OverlayFragments->m_Memory.m_pMemory[v48].m_Next = v44;
          ++p_m_OverlayFragments->m_ElementCount;
          v50 = hFragment;
          v51 = v66;
          pOverlay->m_hFirstFragment = v44;
          m_nFirstOverlayFragment = surfID->m_nFirstOverlayFragment;
          CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::Unlink(
            this: &v51->m_aFragments,
            elem: v50);
          v53 = (char *)v51->m_aFragments.m_Memory.m_pMemory + v63;
          *((_WORD *)v53 + 21) = m_nFirstOverlayFragment;
          if ( (_WORD)m_nFirstOverlayFragment == 0xFFFF )
          {
            v54 = v51->m_aFragments.m_Tail;
            *((_WORD *)v53 + 20) = v54;
            v55 = hFragment;
            v56 = v54;
            v51->m_aFragments.m_Tail = hFragment;
          }
          else
          {
            v57 = (int)&v51->m_aFragments.m_Memory.m_pMemory[m_nFirstOverlayFragment];
            v56 = *(_WORD *)(v57 + 40);
            *((_WORD *)v53 + 20) = v56;
            *(_WORD *)(v57 + 40) = hFragment;
            v55 = hFragment;
          }
          if ( v56 == 0xFFFF )
            v51->m_aFragments.m_Head = v55;
          else
            v51->m_aFragments.m_Memory.m_pMemory[v56].m_Next = v55;
          ++v51->m_aFragments.m_ElementCount;
          v23 = iFrag;
          surfID->m_nFirstOverlayFragment = v55;
          m_Size = nFragCount;
        }
      }
      ++v23;
    }
    if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB160
// Name: private: void COverlayMgr::DoClipFragment(struct moverlayfragment_t __near *,struct cplane_t __near *,struct moverlayfragment_t __near * __near *,struct moverlayfragment_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::DoClipFragment(
        COverlayMgr *this,
        moverlayfragment_t *pFragment,
        cplane_t *pClipPlane,
        moverlayfragment_t **ppFront,
        moverlayfragment_t **ppBack)
{
  int v6; // edi
  int m_Size; // esi
  int v8; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float dist; // xmm4_4
  overlayvert_t *m_pMemory; // edx
  float v14; // xmm0_4
  float v15; // xmm0_4
  moverlayfragment_t *v16; // eax
  cplane_t *v17; // eax
  cplane_t *v18; // esi
  moverlayfragment_t *v19; // eax
  int v20; // esi
  int v21; // eax
  overlayvert_t *p_vert; // edx
  int v23; // eax
  overlayvert_t *v24; // eax
  float v25; // xmm0_4
  int v26; // edx
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  int v31; // [esp-Ch] [ebp-458h]
  float flDists[128]; // [esp+8h] [ebp-444h]
  int nSides[128]; // [esp+208h] [ebp-244h]
  overlayvert_t vert; // [esp+408h] [ebp-44h] BYREF
  int nSideCounts[3]; // [esp+43Ch] [ebp-10h] BYREF
  int nVertCount; // [esp+448h] [ebp-4h]
  moverlayfragment_t *pFragmenta; // [esp+454h] [ebp+8h]
  cplane_t *pClipPlanea; // [esp+458h] [ebp+Ch]

  v6 = 0;
  if ( pFragment == nullptr )
    return;
  m_Size = pFragment->m_aPrimVerts.m_Size;
  v8 = 0;
  memset(nSideCounts, 0, sizeof(nSideCounts));
  if ( m_Size > 0 )
  {
    y = pClipPlane->normal.y;
    x = pClipPlane->normal.x;
    z = pClipPlane->normal.z;
    dist = pClipPlane->dist;
    m_pMemory = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
    do
    {
      v14 = (float)((float)((float)(m_pMemory->pos.y * y) + (float)(x * m_pMemory->pos.x))
                  + (float)(m_pMemory->pos.z * z))
          - dist;
      flDists[v8] = v14;
      if ( v14 <= 0.000099999997 )
      {
        if ( v14 >= -0.000099999997 )
          nSides[v8] = 2;
        else
          nSides[v8] = 1;
      }
      else
      {
        nSides[v8] = 0;
      }
      ++nSideCounts[nSides[v8++]];
      ++m_pMemory;
    }
    while ( v8 < m_Size );
  }
  v15 = flDists[0];
  nSides[v8] = nSides[0];
  flDists[v8] = v15;
  v16 = (moverlayfragment_t *)MemAlloc_Alloc(nSize: 0x28u);
  if ( nSideCounts[0] == 0 )
  {
    if ( v16 != nullptr )
    {
      v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v16->m_aPrimVerts.m_Size = 0;
      v16->m_aPrimVerts.m_pElements = nullptr;
      v16->m_SurfId = pFragment->m_SurfId;
      v16->m_iOverlay = pFragment->m_iOverlay;
      v6 = (int)v16;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
        this: &v16->m_aPrimVerts,
        pArray: pFragment->m_aPrimVerts.m_Memory.m_pMemory,
        size: pFragment->m_aPrimVerts.m_Size);
    }
    *ppBack = (moverlayfragment_t *)v6;
    return;
  }
  if ( nSideCounts[1] == 0 )
  {
    if ( v16 != nullptr )
    {
      v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
      v16->m_aPrimVerts.m_Size = 0;
      v16->m_aPrimVerts.m_pElements = nullptr;
      v16->m_SurfId = pFragment->m_SurfId;
      v16->m_iOverlay = pFragment->m_iOverlay;
      v6 = (int)v16;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
        this: &v16->m_aPrimVerts,
        pArray: pFragment->m_aPrimVerts.m_Memory.m_pMemory,
        size: pFragment->m_aPrimVerts.m_Size);
    }
    *ppFront = (moverlayfragment_t *)v6;
    return;
  }
  if ( v16 != nullptr )
  {
    v16->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    v16->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    v16->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
    v16->m_aPrimVerts.m_Size = 0;
    v16->m_aPrimVerts.m_pElements = nullptr;
    pFragmenta = v16;
    v16->m_SurfId = nullptr;
    v16->m_iOverlay = -1;
  }
  else
  {
    pFragmenta = nullptr;
  }
  v17 = (cplane_t *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v17 != nullptr )
  {
    *(_DWORD *)&v17->type = 0;
    v17[1].normal.x = 0.0;
    v17[1].normal.y = 0.0;
    v17[1].normal.z = 0.0;
    v17[1].dist = 0.0;
    v18 = v17;
    pClipPlanea = v17;
    v17->normal.y = 0.0;
    v17->normal.z = NAN;
  }
  else
  {
    pClipPlanea = nullptr;
    v18 = nullptr;
  }
  v19 = pFragmenta;
  if ( pFragmenta == nullptr )
  {
    if ( v18 != nullptr )
    {
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v18->type);
      free(pMem: v18);
    }
    return;
  }
  if ( v18 == nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&pFragmenta->m_aPrimVerts);
    free(pMem: pFragmenta);
    return;
  }
  nVertCount = pFragment->m_aPrimVerts.m_Size;
  if ( nVertCount <= 0 )
    goto LABEL_40;
  v20 = 0;
  do
  {
    v21 = nSides[v6];
    if ( v21 == 2 )
    {
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: pFragmenta->m_aPrimVerts.m_Size,
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
      p_vert = &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20];
LABEL_37:
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)&pClipPlanea->type,
        elem: LODWORD(pClipPlanea[1].normal.z),
        src: p_vert);
      goto LABEL_38;
    }
    if ( v21 == 1 )
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)&pClipPlanea->type,
        elem: LODWORD(pClipPlanea[1].normal.z),
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
    if ( nSides[v6] == 0 )
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: pFragmenta->m_aPrimVerts.m_Size,
        src: &pFragment->m_aPrimVerts.m_Memory.m_pMemory[v20]);
    v23 = nSides[v6 + 1];
    if ( v23 != 2 && v23 != nSides[v6] )
    {
      v24 = pFragment->m_aPrimVerts.m_Memory.m_pMemory;
      v25 = flDists[v6] / (float)(flDists[v6] - flDists[v6 + 1]);
      memset(&vert.normal, 0, sizeof(vert.normal));
      vert.lightCoord[1] = 0.0;
      vert.lightCoord[0] = 0.0;
      vert.packedColor = -1;
      v26 = (v6 + 1) % nVertCount;
      v27 = v24[v26].pos.x - v24[v20].pos.x;
      v28 = v24[v26].pos.z - v24[v20].pos.z;
      vert.pos.y = (float)((float)(v24[v26].pos.y - v24[v20].pos.y) * v25) + v24[v20].pos.y;
      vert.texCoord[0].x = (float)((float)(v24[v26].texCoord[0].x - v24[v20].texCoord[0].x) * v25)
                         + v24[v20].texCoord[0].x;
      vert.texCoord[0].y = (float)((float)(v24[v26].texCoord[0].y - v24[v20].texCoord[0].y) * v25)
                         + v24[v20].texCoord[0].y;
      vert.texCoord[1].x = (float)((float)(v24[v26].texCoord[1].x - v24[v20].texCoord[1].x) * v25)
                         + v24[v20].texCoord[1].x;
      v29 = (float)(v28 * v25) + v24[v20].pos.z;
      v30 = (float)((float)(v24[v26].texCoord[1].y - v24[v20].texCoord[1].y) * v25) + v24[v20].texCoord[1].y;
      v31 = pFragmenta->m_aPrimVerts.m_Size;
      vert.pos.x = (float)(v27 * v25) + v24[v20].pos.x;
      vert.pos.z = v29;
      vert.texCoord[1].y = v30;
      CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertBefore(
        this: &pFragmenta->m_aPrimVerts,
        elem: v31,
        src: &vert);
      p_vert = &vert;
      goto LABEL_37;
    }
LABEL_38:
    ++v6;
    ++v20;
  }
  while ( v6 < nVertCount );
  v18 = pClipPlanea;
  v19 = pFragmenta;
LABEL_40:
  *ppFront = v19;
  *ppBack = (moverlayfragment_t *)v18;
}

//------------------------------------------------------------------------------
// Address: 0x100FB5E0
// Name: public: COverlayMgr::COverlayMgr(void)
// Source: json
//------------------------------------------------------------------------------
COverlayMgr *__thiscall COverlayMgr::COverlayMgr(COverlayMgr *this)
{
  this->__vftable = (COverlayMgr_vtbl *)&COverlayMgr::`vftable';
  this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
  this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  this->m_RenderQueue.m_Memory.m_nGrowSize = 0;
  this->m_RenderQueue.m_LastAlloc.index = -1;
  this->m_RenderQueue.m_Head = -1;
  this->m_RenderQueue.m_Tail = -1;
  this->m_RenderQueue.m_FirstFree = -1;
  this->m_RenderQueue.m_ElementCount = 0;
  this->m_RenderQueue.m_NumAlloced = 0;
  this->m_RenderQueue.m_pElements = this->m_RenderQueue.m_Memory.m_pMemory;
  this->m_aOverlays.m_Memory.m_pMemory = nullptr;
  this->m_aOverlays.m_Memory.m_nAllocationCount = 0;
  this->m_aOverlays.m_Memory.m_nGrowSize = 0;
  this->m_aOverlays.m_Size = 0;
  this->m_aOverlays.m_pElements = nullptr;
  this->m_aFragments.m_Memory.m_pMemory = nullptr;
  this->m_aFragments.m_Memory.m_nAllocationCount = 0;
  this->m_aFragments.m_Memory.m_nGrowSize = 0;
  this->m_aFragments.m_LastAlloc.index = -1;
  this->m_aFragments.m_Head = -1;
  this->m_aFragments.m_Tail = -1;
  this->m_aFragments.m_FirstFree = -1;
  this->m_aFragments.m_ElementCount = 0;
  this->m_aFragments.m_NumAlloced = 0;
  this->m_aFragments.m_pElements = this->m_aFragments.m_Memory.m_pMemory;
  this->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
  this->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  this->m_OverlayFragments.m_Memory.m_nGrowSize = 0;
  this->m_OverlayFragments.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_OverlayFragments.m_FirstFree = 0xFFFF;
  this->m_OverlayFragments.m_pElements = this->m_OverlayFragments.m_Memory.m_pMemory;
  this->m_OverlayFragments.m_NumAlloced = 0;
  *(_DWORD *)&this->m_OverlayFragments.m_Head = -1;
  *(_DWORD *)this->m_nFirstRenderQueue = -1;
  *(_DWORD *)&this->m_nFirstRenderQueue[2] = -1;
  this->m_flFadeMin2 = 0.0;
  this->m_flFadeMax2 = 0.0;
  this->m_flFadeDelta2 = 0.0;
  this->m_nCPULevel = -1;
  this->m_nGPULevel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FB6C0
// Name: public: COverlayMgr::~COverlayMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::~COverlayMgr(COverlayMgr *this)
{
  this->__vftable = (COverlayMgr_vtbl *)&COverlayMgr::`vftable';
  COverlayMgr::UnloadOverlays(this);
  CUtlLinkedList<unsigned short,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_OverlayFragments);
  if ( this->m_OverlayFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OverlayFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OverlayFragments.m_Memory.m_pMemory);
      this->m_OverlayFragments.m_Memory.m_pMemory = nullptr;
    }
    this->m_OverlayFragments.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<moverlayfragment_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<moverlayfragment_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_aFragments);
  if ( this->m_aFragments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aFragments.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aFragments.m_Memory.m_pMemory);
      this->m_aFragments.m_Memory.m_pMemory = nullptr;
    }
    this->m_aFragments.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::~CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>(this: &this->m_aOverlays);
  CUtlLinkedList<COverlayMgr::RenderQueueHead_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<COverlayMgr::RenderQueueHead_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RenderQueue);
  if ( this->m_RenderQueue.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderQueue.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderQueue.m_Memory.m_pMemory);
      this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FB780
// Name: private: void COverlayMgr::Surf_ClipFragment(struct moverlay_t __near *,struct moverlayfragment_t __near &,struct msurface2_t __near *,struct moverlayfragment_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_ClipFragment(
        COverlayMgr *this,
        moverlayfragment_t *pOverlay,
        moverlayfragment_t *overlayFrag,
        msurface2_t *surfID,
        moverlayfragment_t *surfaceFrag)
{
  moverlayfragment_t *v5; // eax
  moverlayfragment_t *v6; // edi
  moverlayfragment_t *v7; // esi
  cplane_t *m_pMemory; // edi
  int v9; // edx
  overlayvert_t *v10; // eax
  overlayvert_t *v11; // ecx
  overlayvert_t *v12; // ecx
  float x; // ebx
  float *p_x; // eax
  float *v15; // ecx
  overlayvert_t *v16; // eax
  int m_Size; // [esp-4h] [ebp-28h]
  CUtlVector<cplane_t,CUtlMemory<cplane_t,int> > m_ClipPlanes; // [esp+Ch] [ebp-18h] BYREF
  COverlayMgr *v19; // [esp+20h] [ebp-4h]

  v19 = this;
  memset(&m_ClipPlanes, 0, sizeof(m_ClipPlanes));
  COverlayMgr::BuildClipPlanes(
    this,
    surfID,
    surfaceFrag,
    vecBasisNormal: (const Vector *)&pOverlay[3].m_hNextRender,
    (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&m_ClipPlanes);
  v5 = (moverlayfragment_t *)MemAlloc_Alloc(nSize: 0x28u);
  v6 = overlayFrag;
  if ( v5 != nullptr )
  {
    v5->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    v5->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    v5->m_aPrimVerts.m_Memory.m_nGrowSize = 0;
    v5->m_aPrimVerts.m_Size = 0;
    v5->m_aPrimVerts.m_pElements = nullptr;
    v5->m_SurfId = v6->m_SurfId;
    v5->m_iOverlay = v6->m_iOverlay;
    v7 = v5;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
      this: &v5->m_aPrimVerts,
      pArray: v6->m_aPrimVerts.m_Memory.m_pMemory,
      size: v6->m_aPrimVerts.m_Size);
  }
  else
  {
    v7 = nullptr;
  }
  if ( m_ClipPlanes.m_Size > 0 )
  {
    m_pMemory = m_ClipPlanes.m_Memory.m_pMemory;
    for ( surfID = (msurface2_t *)m_ClipPlanes.m_Size; surfID != nullptr; surfID = (msurface2_t *)((char *)surfID - 1) )
    {
      pOverlay = nullptr;
      surfaceFrag = nullptr;
      COverlayMgr::DoClipFragment(
        this: v19,
        pFragment: v7,
        pClipPlane: m_pMemory,
        ppFront: &pOverlay,
        ppBack: &surfaceFrag);
      if ( v7 != nullptr )
      {
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v7->m_aPrimVerts);
        free(pMem: v7);
      }
      v7 = nullptr;
      if ( surfaceFrag != nullptr )
        v7 = surfaceFrag;
      if ( pOverlay != nullptr )
      {
        CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&pOverlay->m_aPrimVerts);
        free(pMem: pOverlay);
      }
      ++m_pMemory;
    }
    v6 = overlayFrag;
  }
  if ( m_ClipPlanes.m_Memory.m_nGrowSize >= 0 && m_ClipPlanes.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ClipPlanes.m_Memory.m_pMemory);
    m_ClipPlanes.m_Memory.m_pMemory = nullptr;
  }
  v6->m_aPrimVerts.m_Size = 0;
  if ( v7 != nullptr )
  {
    m_Size = v7->m_aPrimVerts.m_Size;
    v6->m_aPrimVerts.m_Size = 0;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::InsertMultipleBefore(
      this: &v6->m_aPrimVerts,
      elem: 0,
      num: m_Size);
    overlayFrag = nullptr;
    if ( v7->m_aPrimVerts.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = v7->m_aPrimVerts.m_Memory.m_pMemory;
        v11 = v6->m_aPrimVerts.m_Memory.m_pMemory;
        v11[v9].pos.x = v10[v9].pos.x;
        v11[v9].pos.y = v10[v9].pos.y;
        v11[v9].pos.z = v10[v9].pos.z;
        v12 = v7->m_aPrimVerts.m_Memory.m_pMemory;
        x = v12[v9].texCoord[0].x;
        p_x = &v12[v9].texCoord[0].x;
        v15 = &v6->m_aPrimVerts.m_Memory.m_pMemory[v9].texCoord[0].x;
        *v15 = x;
        v15[1] = p_x[1];
        v15[2] = p_x[2];
        v15[3] = p_x[3];
        ++v9;
        overlayFrag = (moverlayfragment_t *)((char *)overlayFrag + 1);
      }
      while ( (int)overlayFrag < v7->m_aPrimVerts.m_Size );
    }
    v7->m_aPrimVerts.m_Size = 0;
    if ( v7->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v7->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_aPrimVerts.m_Memory.m_pMemory);
        v7->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      }
      v7->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    }
    v16 = v7->m_aPrimVerts.m_Memory.m_pMemory;
    v7->m_aPrimVerts.m_pElements = v16;
    if ( v7->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        v7->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
      }
      v7->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v7);
  }
  if ( m_ClipPlanes.m_Memory.m_nGrowSize >= 0 && m_ClipPlanes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_ClipPlanes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100FB980
// Name: private: void COverlayMgr::Surf_CreateFragments(struct moverlay_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Surf_CreateFragments(COverlayMgr *this, moverlayfragment_t *pOverlay, msurface2_t *surfID)
{
  int firstvertindex; // ebx
  int flags_high; // eax
  int m_nAllocationCount; // ecx
  overlayvert_t *v6; // edi
  overlayvert_t *m_pMemory; // esi
  int v8; // eax
  int v9; // edi
  _DWORD *p_z; // eax
  int i; // ecx
  mvertex_t *v12; // eax
  mvertex_t *v13; // ecx
  mvertex_t *v14; // edx
  bool v15; // zf
  moverlayfragment_t overlayFrag; // [esp+Ch] [ebp-58h] BYREF
  moverlayfragment_t surfaceFrag; // [esp+34h] [ebp-30h] BYREF
  int v18; // [esp+5Ch] [ebp-8h]
  COverlayMgr *v19; // [esp+60h] [ebp-4h]

  firstvertindex = surfID->firstvertindex;
  flags_high = HIBYTE(surfID->flags);
  v19 = this;
  m_nAllocationCount = 0;
  v6 = nullptr;
  m_pMemory = nullptr;
  v8 = flags_high - 2;
  memset(&overlayFrag.m_aPrimVerts, 0, sizeof(overlayFrag.m_aPrimVerts));
  memset(&surfaceFrag.m_aPrimVerts, 0, sizeof(surfaceFrag.m_aPrimVerts));
  if ( v8 > 0 )
  {
    v9 = 2 * firstvertindex + 4;
    v18 = v8;
    while ( 1 )
    {
      surfaceFrag.m_aPrimVerts.m_Size = 0;
      if ( m_nAllocationCount < 3 )
      {
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
          this: (CUtlMemory<SndInfo_t,int> *)&surfaceFrag.m_aPrimVerts,
          num: 3 - m_nAllocationCount);
        m_pMemory = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
      }
      surfaceFrag.m_aPrimVerts.m_Size += 3;
      surfaceFrag.m_aPrimVerts.m_pElements = m_pMemory;
      if ( surfaceFrag.m_aPrimVerts.m_Size - 3 > 0 )
        _V_memmove(dest: &m_pMemory[3], src: m_pMemory, count: 52 * (surfaceFrag.m_aPrimVerts.m_Size - 3));
      p_z = (_DWORD *)&m_pMemory->normal.z;
      for ( i = 3; i != 0; --i )
      {
        if ( p_z != (_DWORD *)20 )
        {
          *(p_z - 5) = 0;
          *(p_z - 4) = 0;
          *(p_z - 3) = 0;
          *(p_z - 2) = 0;
          *(p_z - 1) = 0;
          *p_z = 0;
          p_z[1] = 0;
          p_z[2] = 0;
          p_z[3] = 0;
          p_z[4] = 0;
          p_z[6] = 0;
          p_z[5] = 0;
          p_z[7] = -1;
        }
        p_z += 13;
      }
      v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
      m_pMemory->pos.x = v12->position.x;
      m_pMemory->pos.y = v12->position.y;
      m_pMemory->pos.z = v12->position.z;
      v13 = &host_state.worldbrush->vertexes[*(unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v9 - 2)];
      m_pMemory[1].pos.x = v13->position.x;
      m_pMemory[1].pos.y = v13->position.y;
      m_pMemory[1].pos.z = v13->position.z;
      v14 = &host_state.worldbrush->vertexes[*(unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v9)];
      m_pMemory[2].pos.x = v14->position.x;
      m_pMemory[2].pos.y = v14->position.y;
      m_pMemory[2].pos.z = v14->position.z;
      if ( TriangleArea(v0: &m_pMemory->pos, v1: &m_pMemory[1].pos, v2: &m_pMemory[2].pos) > 1.0
        && COverlayMgr::Surf_PreClipFragment(this: v19, (moverlay_t *)pOverlay, &overlayFrag, surfID, &surfaceFrag) != 0 )
      {
        COverlayMgr::Surf_ClipFragment(this: v19, pOverlay, &overlayFrag, surfID, &surfaceFrag);
        COverlayMgr::Surf_PostClipFragment(this: v19, (moverlay_t *)pOverlay, &overlayFrag, surfID);
      }
      v9 += 2;
      v15 = v18-- == 1;
      surfaceFrag.m_aPrimVerts.m_Size = 0;
      overlayFrag.m_aPrimVerts.m_Size = 0;
      if ( v15 )
        break;
      m_nAllocationCount = surfaceFrag.m_aPrimVerts.m_Memory.m_nAllocationCount;
    }
    v6 = overlayFrag.m_aPrimVerts.m_Memory.m_pMemory;
  }
  if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && v6 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100FBBE0
// Name: public: virtual bool COverlayMgr::LoadOverlays(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::LoadOverlays(COverlayMgr *this)
{
  int v3; // ebx
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int> > *p_m_aOverlays; // esi
  int v5; // edi
  doverlaysystemlevel_t *p_nMinGPULevel; // eax
  float *p_z; // edi
  int v8; // esi
  unsigned __int16 v9; // dx
  float *v10; // eax
  int v11; // eax
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v16; // ebx
  int v17; // eax
  float *v18; // edi
  int v19; // eax
  char *v20; // esi
  unsigned __int16 v21; // dx
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  dwateroverlay_t *v25; // eax
  int v26; // ecx
  char *v27; // edx
  int v28; // ecx
  __int16 v29; // ax
  worldbrushdata_t *Map; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // eax
  int v34; // [esp+14h] [ebp-4D4h]
  CMapLoadHelper lhOverlayFades; // [esp+24h] [ebp-4C4h] BYREF
  CMapLoadHelper lhOverlaySystemLevel; // [esp+14Ch] [ebp-39Ch] BYREF
  CMapLoadHelper lh2; // [esp+274h] [ebp-274h] BYREF
  CMapLoadHelper lh; // [esp+39Ch] [ebp-14Ch] BYREF
  doverlay_t *pOverlayIn; // [esp+4C4h] [ebp-24h]
  int nWaterOverlayCount; // [esp+4C8h] [ebp-20h]
  int nOverlayCount; // [esp+4CCh] [ebp-1Ch]
  dwateroverlay_t *pWaterOverlayIn; // [esp+4D0h] [ebp-18h]
  CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int> > *v43; // [esp+4D4h] [ebp-14h]
  doverlaysystemlevel_t *pOverlaySystemLevelIn; // [esp+4D8h] [ebp-10h]
  int iFace; // [esp+4DCh] [ebp-Ch]
  int iOverlay; // [esp+4E0h] [ebp-8h]
  int iWaterOverlay; // [esp+4E4h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x2Du, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &lh2, lumpToLoad: 0x32u, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &lhOverlayFades, lumpToLoad: 0x3Cu, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &lhOverlaySystemLevel, lumpToLoad: 0x3Du, bUncompress: true);
  pOverlayIn = (doverlay_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0x160u != 0
    || (pWaterOverlayIn = (dwateroverlay_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh2),
        CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh2) % 0x460u != 0)
    || (iFace = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhOverlayFades),
        (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhOverlayFades) & 7) != 0)
    || (pOverlaySystemLevelIn = (doverlaysystemlevel_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhOverlaySystemLevel),
        (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhOverlaySystemLevel) & 3) != 0) )
  {
    CMapLoadHelper::~CMapLoadHelper(this: &lhOverlaySystemLevel);
    CMapLoadHelper::~CMapLoadHelper(this: &lhOverlayFades);
    CMapLoadHelper::~CMapLoadHelper(this: &lh2);
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
    return 0;
  }
  else
  {
    v3 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0x160u;
    nOverlayCount = v3;
    p_m_aOverlays = &this->m_aOverlays;
    v5 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh2) / 0x460u;
    nWaterOverlayCount = v5;
    v43 = p_m_aOverlays;
    CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::RemoveAll(this: p_m_aOverlays);
    CUtlVector<moverlay_t,CUtlMemory<moverlay_t,int>>::InsertMultipleBefore(
      this: p_m_aOverlays,
      elem: p_m_aOverlays->m_Size,
      num: v5 + v3);
    iOverlay = 0;
    if ( v3 > 0 )
    {
      p_nMinGPULevel = (doverlaysystemlevel_t *)&pOverlaySystemLevelIn->nMinGPULevel;
      pOverlaySystemLevelIn = (doverlaysystemlevel_t *)((char *)pOverlaySystemLevelIn + 2);
      iWaterOverlay = 0;
      p_z = &pOverlayIn->vecOrigin.z;
      while ( 1 )
      {
        v8 = (int)p_m_aOverlays->m_Memory.m_pMemory + iWaterOverlay;
        if ( p_nMinGPULevel != (doverlaysystemlevel_t *)2 )
        {
          *(_BYTE *)(v8 + 164) = p_nMinGPULevel[-1].nMinGPULevel;
          *(_BYTE *)(v8 + 165) = p_nMinGPULevel[-1].nMaxGPULevel;
          *(_BYTE *)(v8 + 166) = p_nMinGPULevel->nMinCPULevel;
          *(_BYTE *)(v8 + 167) = p_nMinGPULevel->nMaxCPULevel;
          pOverlaySystemLevelIn = p_nMinGPULevel + 1;
        }
        *(_DWORD *)v8 = iOverlay;
        *(_WORD *)(v8 + 4) = *((_WORD *)p_z - 166);
        v9 = *((_WORD *)p_z - 165) >> 14;
        *(_WORD *)(v8 + 10) = 0;
        *(_WORD *)(v8 + 6) = v9;
        if ( v9 >= 4u )
          _Error(a1: "COverlayMgr::LoadOverlays: invalid render order (%d) for an overlay.", (__int16)v9);
        v10 = (float *)iFace;
        *(float *)(v8 + 32) = *(p_z - 18);
        *(float *)(v8 + 36) = *(p_z - 17);
        *(float *)(v8 + 40) = *(p_z - 16);
        *(float *)(v8 + 44) = *(p_z - 15);
        if ( v10 != nullptr )
        {
          *(float *)(v8 + 148) = *v10;
          v11 = (int)(v10 + 2);
          v12 = *(float *)(v11 - 4);
          iFace = v11;
          *(float *)(v8 + 152) = v12;
          *(float *)(v8 + 156) = 1.0 / (float)(*(float *)(v11 - 4) - *(float *)(v11 - 8));
        }
        else
        {
          *(_DWORD *)(v8 + 148) = -1082130432;
          *(_DWORD *)(v8 + 152) = 0;
          *(_DWORD *)(v8 + 156) = 1065353216;
        }
        *(float *)(v8 + 96) = *(p_z - 2);
        *(float *)(v8 + 100) = *(p_z - 1);
        *(float *)(v8 + 104) = *p_z;
        *(float *)(v8 + 48) = *(p_z - 14);
        *(float *)(v8 + 52) = *(p_z - 13);
        *(float *)(v8 + 56) = *(p_z - 12);
        *(float *)(v8 + 60) = *(p_z - 11);
        *(float *)(v8 + 64) = *(p_z - 10);
        *(float *)(v8 + 68) = *(p_z - 9);
        *(float *)(v8 + 72) = *(p_z - 8);
        *(float *)(v8 + 76) = *(p_z - 7);
        *(float *)(v8 + 80) = *(p_z - 6);
        *(float *)(v8 + 84) = *(p_z - 5);
        *(float *)(v8 + 88) = *(p_z - 4);
        *(float *)(v8 + 92) = *(p_z - 3);
        *(float *)(v8 + 132) = p_z[1];
        *(float *)(v8 + 136) = p_z[2];
        *(float *)(v8 + 140) = p_z[3];
        v13 = *(float *)(v8 + 56);
        v14 = *(float *)(v8 + 68);
        v15 = *(float *)(v8 + 80);
        *(float *)(v8 + 108) = v13;
        *(float *)(v8 + 112) = v14;
        *(float *)(v8 + 116) = v15;
        if ( v13 == 0.0 && v14 == 0.0 && v15 == 0.0 )
          _Warning(
            a1: "Bad overlay basis at (%f %f %f)!\n",
            *(float *)(v8 + 96),
            *(float *)(v8 + 100),
            *(float *)(v8 + 104));
        *(float *)(v8 + 120) = (float)(*(float *)(v8 + 116) * *(float *)(v8 + 136))
                             - (float)(*(float *)(v8 + 140) * *(float *)(v8 + 112));
        *(float *)(v8 + 124) = (float)(*(float *)(v8 + 140) * *(float *)(v8 + 108))
                             - (float)(*(float *)(v8 + 116) * *(float *)(v8 + 132));
        *(float *)(v8 + 128) = (float)(*(float *)(v8 + 112) * *(float *)(v8 + 132))
                             - (float)(*(float *)(v8 + 136) * *(float *)(v8 + 108));
        VectorNormalize(vec: (Vector *)(v8 + 120));
        *(_DWORD *)(v8 + 56) = 0;
        *(_DWORD *)(v8 + 68) = 0;
        *(_DWORD *)(v8 + 80) = 0;
        v16 = 0;
        v34 = *((_WORD *)p_z - 165) & 0x3FFF;
        *(_DWORD *)(v8 + 24) = 0;
        CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
          this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)(v8 + 12),
          elem: 0,
          num: v34);
        if ( (*((_WORD *)p_z - 165) & 0x3FFF) != 0 )
        {
          do
          {
            *(_DWORD *)(*(_DWORD *)(v8 + 12) + 4 * v16) = &CMapLoadHelper::GetMap(this: &lh)->surfaces2[LODWORD(p_z[v16 - 82])];
            ++v16;
          }
          while ( v16 < (*((_WORD *)p_z - 165) & 0x3FFF) );
        }
        iWaterOverlay += 168;
        v17 = iOverlay + 1;
        p_z += 88;
        *(_WORD *)(v8 + 8) = -1;
        *(_DWORD *)(v8 + 144) = 0;
        p_m_aOverlays = v43;
        iOverlay = v17;
        if ( v17 >= nOverlayCount )
          break;
        p_nMinGPULevel = pOverlaySystemLevelIn;
      }
      v5 = nWaterOverlayCount;
      v3 = nOverlayCount;
    }
    iWaterOverlay = 0;
    if ( v5 > 0 )
    {
      v18 = &pWaterOverlayIn->vecOrigin.z;
      v19 = 168 * v3;
      iOverlay = 168 * v3;
      while ( 1 )
      {
        v20 = (char *)p_m_aOverlays->m_Memory.m_pMemory + v19;
        *(_DWORD *)v20 = v3 + iWaterOverlay;
        *((_WORD *)v20 + 2) = *((_WORD *)v18 - 550);
        v21 = *((_WORD *)v18 - 549) >> 14;
        *((_WORD *)v20 + 5) = 0;
        *((_WORD *)v20 + 3) = v21;
        if ( v21 >= 4u )
          _Error(a1: "COverlayMgr::LoadOverlays: invalid render order (%d) for an overlay.", (__int16)v21);
        *((float *)v20 + 8) = *(v18 - 18);
        *((float *)v20 + 9) = *(v18 - 17);
        *((float *)v20 + 10) = *(v18 - 16);
        *((float *)v20 + 11) = *(v18 - 15);
        *((float *)v20 + 24) = *(v18 - 2);
        *((float *)v20 + 25) = *(v18 - 1);
        *((float *)v20 + 26) = *v18;
        *((float *)v20 + 12) = *(v18 - 14);
        *((float *)v20 + 13) = *(v18 - 13);
        *((float *)v20 + 14) = *(v18 - 12);
        *((float *)v20 + 15) = *(v18 - 11);
        *((float *)v20 + 16) = *(v18 - 10);
        *((float *)v20 + 17) = *(v18 - 9);
        *((float *)v20 + 18) = *(v18 - 8);
        *((float *)v20 + 19) = *(v18 - 7);
        *((float *)v20 + 20) = *(v18 - 6);
        *((float *)v20 + 21) = *(v18 - 5);
        *((float *)v20 + 22) = *(v18 - 4);
        *((float *)v20 + 23) = *(v18 - 3);
        *((float *)v20 + 33) = v18[1];
        *((float *)v20 + 34) = v18[2];
        *((float *)v20 + 35) = v18[3];
        v22 = *((float *)v20 + 14);
        v23 = *((float *)v20 + 17);
        v24 = *((float *)v20 + 20);
        *((float *)v20 + 27) = v22;
        *((float *)v20 + 28) = v23;
        *((float *)v20 + 29) = v24;
        if ( v22 == 0.0 && v23 == 0.0 && v24 == 0.0 )
          _Warning(
            a1: "Bad overlay basis at (%f %f %f)!\n",
            *((float *)v20 + 24),
            *((float *)v20 + 25),
            *((float *)v20 + 26));
        *((float *)v20 + 30) = (float)(*((float *)v20 + 29) * *((float *)v20 + 34))
                             - (float)(*((float *)v20 + 35) * *((float *)v20 + 28));
        *((float *)v20 + 31) = (float)(*((float *)v20 + 35) * *((float *)v20 + 27))
                             - (float)(*((float *)v20 + 29) * *((float *)v20 + 33));
        *((float *)v20 + 32) = (float)(*((float *)v20 + 28) * *((float *)v20 + 33))
                             - (float)(*((float *)v20 + 34) * *((float *)v20 + 27));
        VectorNormalize(vec: (Vector *)v20 + 10);
        *((_DWORD *)v20 + 14) = 0;
        *((_DWORD *)v20 + 17) = 0;
        *((_DWORD *)v20 + 20) = 0;
        v25 = (dwateroverlay_t *)(*((_WORD *)v18 - 549) & 0x3FFF);
        pWaterOverlayIn = v25;
        *((_DWORD *)v20 + 6) = 0;
        if ( v25 != nullptr )
        {
          v26 = *((_DWORD *)v20 + 4);
          if ( (int)v25 > v26 )
          {
            CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)v20 + 1, num: (int)v25 - v26);
            v25 = pWaterOverlayIn;
          }
          *((_DWORD *)v20 + 6) += v25;
          v27 = *((char **)v20 + 3);
          v28 = *((_DWORD *)v20 + 6) - (_DWORD)v25;
          *((_DWORD *)v20 + 7) = v27;
          if ( v28 > 0 && (int)v25 > 0 )
            _V_memmove(dest: &v27[4 * (_DWORD)v25], src: v27, count: 4 * v28);
        }
        v29 = *((_WORD *)v18 - 549) & 0x3FFF;
        iFace = 0;
        if ( v29 != 0 )
        {
          do
          {
            Map = CMapLoadHelper::GetMap(this: &lh2);
            v31 = iFace;
            *(_DWORD *)(*((_DWORD *)v20 + 3) + 4 * iFace) = &Map->surfaces2[LODWORD(v18[iFace - 274])];
            v32 = *((_WORD *)v18 - 549) & 0x3FFF;
            iFace = v31 + 1;
          }
          while ( v31 + 1 < v32 );
        }
        iOverlay += 168;
        *((_WORD *)v20 + 4) = -1;
        v33 = iWaterOverlay + 1;
        v18 += 280;
        *((_DWORD *)v20 + 36) = 0;
        iWaterOverlay = v33;
        if ( v33 >= nWaterOverlayCount )
          break;
        v19 = iOverlay;
        v3 = nOverlayCount;
        p_m_aOverlays = v43;
      }
    }
    CMapLoadHelper::~CMapLoadHelper(this: &lhOverlaySystemLevel);
    CMapLoadHelper::~CMapLoadHelper(this: &lhOverlayFades);
    CMapLoadHelper::~CMapLoadHelper(this: &lh2);
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FC360
// Name: private: bool COverlayMgr::Disp_PreClipFragment(struct moverlay_t __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall COverlayMgr::Disp_PreClipFragment(
        COverlayMgr *this,
        moverlay_t *pOverlay,
        CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragments,
        msurface2_t *surfID)
{
  int firstvertindex; // edi
  overlayvert_t *m_pMemory; // esi
  _DWORD *p_z; // eax
  int i; // ecx
  mvertex_t *v8; // eax
  double y; // st7
  mvertex_t *v10; // eax
  mvertex_t *v11; // eax
  mvertex_t *v12; // eax
  int m_Size; // edi
  char *v15; // eax
  msurface2_t *m_SurfId; // edx
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *v18; // ecx
  int m_nAllocationCount; // eax
  moverlayfragment_t **v20; // edx
  int v21; // eax
  moverlayfragment_t **v22; // eax
  IDispInfo_vtbl *v23; // eax
  int v24; // edi
  COverlayMgr *v25; // eax
  mtexinfo_t *v26; // eax
  CFmtStrN<256> *v27; // eax
  CFmtStrN<256> v28; // [esp+24h] [ebp-17Ch] BYREF
  moverlayfragment_t surfaceFrag; // [esp+130h] [ebp-70h] BYREF
  Vector *v3; // [esp+158h] [ebp-48h]
  float v31; // [esp+15Ch] [ebp-44h]
  Vector *v2; // [esp+160h] [ebp-40h]
  Vector *v1; // [esp+164h] [ebp-3Ch]
  Vector2D vecTmpUV; // [esp+168h] [ebp-38h] BYREF
  float x; // [esp+170h] [ebp-30h]
  moverlayfragment_t overlayFrag; // [esp+174h] [ebp-2Ch] BYREF
  COverlayMgr *v37; // [esp+19Ch] [ebp-4h]
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragmentsa; // [esp+1ACh] [ebp+Ch]
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragmentsb; // [esp+1ACh] [ebp+Ch]
  int iVert; // [esp+1B0h] [ebp+10h]
  const char *iVerta; // [esp+1B0h] [ebp+10h]

  firstvertindex = surfID->firstvertindex;
  v37 = this;
  memset(&surfaceFrag.m_aPrimVerts, 0, sizeof(surfaceFrag.m_aPrimVerts));
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
    this: (CUtlMemory<SndInfo_t,int> *)&surfaceFrag.m_aPrimVerts,
    num: 4);
  m_pMemory = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
  surfaceFrag.m_aPrimVerts.m_Size += 4;
  surfaceFrag.m_aPrimVerts.m_pElements = surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory;
  if ( surfaceFrag.m_aPrimVerts.m_Size - 4 > 0 )
    _V_memmove(
      dest: &surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory[4],
      src: surfaceFrag.m_aPrimVerts.m_Memory.m_pMemory,
      count: 52 * (surfaceFrag.m_aPrimVerts.m_Size - 4));
  p_z = (_DWORD *)&m_pMemory->normal.z;
  for ( i = 4; i != 0; --i )
  {
    if ( p_z != (_DWORD *)20 )
    {
      *(p_z - 5) = 0;
      *(p_z - 4) = 0;
      *(p_z - 3) = 0;
      *(p_z - 2) = 0;
      *(p_z - 1) = 0;
      *p_z = 0;
      p_z[1] = 0;
      p_z[2] = 0;
      p_z[3] = 0;
      p_z[4] = 0;
      p_z[6] = 0;
      p_z[5] = 0;
      p_z[7] = -1;
    }
    p_z += 13;
  }
  v8 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
  memset(&overlayFrag.m_aPrimVerts, 0, 12);
  m_pMemory->pos.x = v8->position.x;
  overlayFrag.m_aPrimVerts.m_Size = 0;
  y = v8->position.y;
  overlayFrag.m_aPrimVerts.m_pElements = nullptr;
  m_pMemory->pos.y = y;
  m_pMemory->pos.z = v8->position.z;
  v10 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 1]];
  m_pMemory[1].pos.x = v10->position.x;
  m_pMemory[1].pos.y = v10->position.y;
  m_pMemory[1].pos.z = v10->position.z;
  v11 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 2]];
  m_pMemory[2].pos.x = v11->position.x;
  m_pMemory[2].pos.y = v11->position.y;
  m_pMemory[2].pos.z = v11->position.z;
  v12 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex + 3]];
  m_pMemory[3].pos.x = v12->position.x;
  m_pMemory[3].pos.y = v12->position.y;
  m_pMemory[3].pos.z = v12->position.z;
  if ( COverlayMgr::Surf_PreClipFragment(this: v37, pOverlay, &overlayFrag, surfID, &surfaceFrag) == 0 )
  {
    if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
LABEL_11:
    if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 0;
  }
  COverlayMgr::Surf_ClipFragment(this: v37, (moverlayfragment_t *)pOverlay, &overlayFrag, surfID, &surfaceFrag);
  m_Size = overlayFrag.m_aPrimVerts.m_Size;
  if ( overlayFrag.m_aPrimVerts.m_Size == 0 )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&overlayFrag.m_aPrimVerts);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&surfaceFrag.m_aPrimVerts);
    return 0;
  }
  v15 = (char *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v15 != nullptr )
  {
    m_SurfId = overlayFrag.m_SurfId;
    *((_DWORD *)v15 + 4) = 0;
    *((_DWORD *)v15 + 5) = 0;
    *((_DWORD *)v15 + 6) = 0;
    *((_DWORD *)v15 + 7) = 0;
    *((_DWORD *)v15 + 8) = 0;
    *((_DWORD *)v15 + 1) = m_SurfId;
    v37 = (COverlayMgr *)v15;
    *((_DWORD *)v15 + 2) = overlayFrag.m_iOverlay;
    CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int>>::CopyArray(
      this: (CUtlVector<overlayvert_t,CUtlMemory<overlayvert_t,int> > *)(v15 + 16),
      pArray: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory,
      size: m_Size);
  }
  else
  {
    v37 = nullptr;
  }
  m_nAllocationCount = aDispFragments->m_Memory.m_nAllocationCount;
  aDispFragmentsa = (CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *)aDispFragments->m_Size;
  v18 = aDispFragmentsa;
  if ( (int)&aDispFragmentsa->m_Memory.m_pMemory + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)aDispFragments,
      num: (int)&aDispFragmentsa->m_Memory.m_pMemory - m_nAllocationCount + 1);
    v18 = aDispFragmentsa;
  }
  ++aDispFragments->m_Size;
  v20 = aDispFragments->m_Memory.m_pMemory;
  v21 = aDispFragments->m_Size - (_DWORD)v18 - 1;
  aDispFragments->m_pElements = aDispFragments->m_Memory.m_pMemory;
  if ( v21 > 0 )
  {
    _V_memmove(dest: &v20[(_DWORD)v18 + 1], src: &v20[(_DWORD)v18], count: 4 * v21);
    v18 = aDispFragmentsa;
  }
  v22 = &aDispFragments->m_Memory.m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (moverlayfragment_t *)v37;
  v23 = surfID->pDispInfo[92].__vftable;
  iVert = 0;
  if ( overlayFrag.m_aPrimVerts.m_Size > 0 )
  {
    aDispFragmentsb = (CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *)&m_pMemory[((int)&v23->dtr_IDispInfo + 1) % 4];
    v3 = &m_pMemory[((int)&v23->dtr_IDispInfo + 2) % 4].pos;
    v2 = &m_pMemory[((int)&v23->dtr_IDispInfo + 3) % 4].pos;
    v1 = &m_pMemory[(_DWORD)v23].pos;
    v24 = 0;
    while ( 1 )
    {
      PointInQuadToBarycentric(
        v1,
        v2,
        v3,
        v4: (const Vector *)aDispFragmentsb,
        point: &overlayFrag.m_aPrimVerts.m_Memory.m_pMemory[v24].pos,
        uv: &vecTmpUV);
      x = vecTmpUV.x;
      if ( (LODWORD(vecTmpUV.x) & 0x7F800000) == 0x7F800000 )
        break;
      v31 = vecTmpUV.y;
      if ( (LODWORD(vecTmpUV.y) & 0x7F800000) == 0x7F800000 )
        break;
      v25 = v37;
      *(Vector2D *)(v24 * 52 + v37->m_RenderQueue.m_Memory.m_nAllocationCount) = vecTmpUV;
      *(_DWORD *)(v24 * 52 + v25->m_RenderQueue.m_Memory.m_nAllocationCount + 8) = 0;
      ++v24;
      if ( ++iVert >= overlayFrag.m_aPrimVerts.m_Size )
        goto LABEL_29;
    }
    v26 = &host_state.worldbrush->texinfo[pOverlay->m_nTexInfo];
    if ( v26 != nullptr && v26->material != nullptr )
      iVerta = v26->material->GetName(this: v26->material);
    else
      iVerta = defaultValue;
    v27 = CFmtStrN<256>::CFmtStrN<256>(
            this: &v28,
            pszFormat: "(%f, %f, %f)",
            pOverlay->m_vecOrigin.x,
            pOverlay->m_vecOrigin.y,
            pOverlay->m_vecOrigin.z);
    _DevWarning(a1: 1, a2: "Bad overlay geometry at %s with material '%s'\n", v27->m_szBuf, iVerta);
    if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
      overlayFrag.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
    }
    goto LABEL_11;
  }
LABEL_29:
  if ( overlayFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 && overlayFrag.m_aPrimVerts.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlayFrag.m_aPrimVerts.m_Memory.m_pMemory);
    overlayFrag.m_aPrimVerts.m_Memory.m_pMemory = nullptr;
  }
  if ( surfaceFrag.m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FC820
// Name: private: void COverlayMgr::Disp_DoClip(class CDispInfo __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &,struct cplane_t __near &,float,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_DoClip(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CUtlMemory<S3RGBA,int> *aDispFragments,
        cplane_t *clipPlane,
        float clipDistStart,
        moverlayfragment_t *nInterval,
        moverlayfragment_t *nLoopStart,
        int nLoopEnd,
        int nLoopInc)
{
  int v9; // ecx
  moverlayfragment_t **v10; // edx
  int m_pMemory; // edi
  moverlayfragment_t **v13; // ebx
  moverlayfragment_t **v14; // eax
  bool v15; // sf
  int v16; // eax
  moverlayfragment_t *v17; // edi
  COverlayMgr *v18; // ecx
  overlayvert_t *v19; // eax
  int v20; // edi
  int m_nAllocationCount; // eax
  moverlayfragment_t **v22; // ecx
  int v23; // eax
  moverlayfragment_t **v24; // eax
  int v25; // edi
  int v26; // eax
  moverlayfragment_t **v27; // ecx
  int v28; // eax
  moverlayfragment_t **v29; // eax
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > aClippedFragments; // [esp+0h] [ebp-20h] BYREF
  COverlayMgr *v31; // [esp+14h] [ebp-Ch]
  float flOOInterval; // [esp+18h] [ebp-8h]
  int iInterval; // [esp+1Ch] [ebp-4h]
  int iFrag; // [esp+2Ch] [ebp+Ch]

  v31 = this;
  v9 = 0;
  v10 = nullptr;
  flOOInterval = 1.0 / (float)(int)nInterval;
  memset(&aClippedFragments, 0, sizeof(aClippedFragments));
  iInterval = (int)nLoopStart;
  if ( (int)nLoopStart < nLoopEnd )
  {
    while ( 1 )
    {
      m_pMemory = (int)aDispFragments[1].m_pMemory;
      v13 = (moverlayfragment_t **)aDispFragments->m_pMemory;
      aClippedFragments.m_Size = 0;
      if ( m_pMemory == 0 )
        goto LABEL_13;
      if ( m_pMemory > v9 )
      {
        CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&aClippedFragments, num: m_pMemory - v9);
        v10 = aClippedFragments.m_Memory.m_pMemory;
      }
      aClippedFragments.m_Size += m_pMemory;
      aClippedFragments.m_pElements = v10;
      if ( aClippedFragments.m_Size - m_pMemory > 0 )
      {
        if ( m_pMemory <= 0 )
          goto LABEL_13;
        _V_memmove(dest: &v10[m_pMemory], src: v10, count: 4 * (aClippedFragments.m_Size - m_pMemory));
        v10 = aClippedFragments.m_Memory.m_pMemory;
      }
      if ( m_pMemory > 0 )
      {
        v14 = v10;
        do
        {
          *v14 = *(moverlayfragment_t **)((char *)v14 + (char *)v13 - (char *)v10);
          ++v14;
          --m_pMemory;
        }
        while ( m_pMemory != 0 );
      }
LABEL_13:
      v15 = aDispFragments->m_nGrowSize < 0;
      aDispFragments[1].m_pMemory = nullptr;
      if ( !v15 )
      {
        if ( aDispFragments->m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: aDispFragments->m_pMemory);
          v10 = aClippedFragments.m_Memory.m_pMemory;
          aDispFragments->m_pMemory = nullptr;
        }
        aDispFragments->m_nAllocationCount = 0;
      }
      aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
      v16 = 0;
      for ( iFrag = 0; v16 < aClippedFragments.m_Size; iFrag = v16 )
      {
        v17 = v10[v16];
        if ( v17 != nullptr )
        {
          nInterval = nullptr;
          nLoopStart = nullptr;
          v18 = v31;
          clipPlane->dist = (float)((float)iInterval * flOOInterval) * clipDistStart;
          COverlayMgr::DoClipFragment(
            this: v18,
            pFragment: v17,
            pClipPlane: clipPlane,
            ppFront: &nInterval,
            ppBack: &nLoopStart);
          v17->m_aPrimVerts.m_Size = 0;
          if ( v17->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v17->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17->m_aPrimVerts.m_Memory.m_pMemory);
              v17->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
            }
            v17->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
          }
          v19 = v17->m_aPrimVerts.m_Memory.m_pMemory;
          v17->m_aPrimVerts.m_pElements = v19;
          if ( v17->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v19 != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
              v17->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
            }
            v17->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
          }
          free(pMem: v17);
          if ( nInterval != nullptr )
          {
            v20 = (int)aDispFragments[1].m_pMemory;
            m_nAllocationCount = aDispFragments->m_nAllocationCount;
            if ( v20 + 1 > m_nAllocationCount )
              CUtlMemory<INetMessage *,int>::Grow(this: aDispFragments, num: v20 - m_nAllocationCount + 1);
            ++aDispFragments[1].m_pMemory;
            v22 = (moverlayfragment_t **)aDispFragments->m_pMemory;
            v23 = (int)aDispFragments[1].m_pMemory - v20 - 1;
            aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 4 * v23);
            v24 = (moverlayfragment_t **)&aDispFragments->m_pMemory[v20];
            if ( v24 != nullptr )
              *v24 = nInterval;
          }
          if ( nLoopStart != nullptr )
          {
            v25 = (int)aDispFragments[1].m_pMemory;
            v26 = aDispFragments->m_nAllocationCount;
            if ( v25 + 1 > v26 )
              CUtlMemory<INetMessage *,int>::Grow(this: aDispFragments, num: v25 - v26 + 1);
            ++aDispFragments[1].m_pMemory;
            v27 = (moverlayfragment_t **)aDispFragments->m_pMemory;
            v28 = (int)aDispFragments[1].m_pMemory - v25 - 1;
            aDispFragments[1].m_nAllocationCount = (int)aDispFragments->m_pMemory;
            if ( v28 > 0 )
              _V_memmove(dest: &v27[v25 + 1], src: &v27[v25], count: 4 * v28);
            v29 = (moverlayfragment_t **)&aDispFragments->m_pMemory[v25];
            if ( v29 != nullptr )
              *v29 = nLoopStart;
          }
          v10 = aClippedFragments.m_Memory.m_pMemory;
        }
        v16 = iFrag + 1;
      }
      iInterval += nLoopInc;
      if ( iInterval >= nLoopEnd )
        break;
      v9 = aClippedFragments.m_Memory.m_nAllocationCount;
    }
  }
  if ( aClippedFragments.m_Memory.m_nGrowSize >= 0 && v10 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x100FCAB0
// Name: private: void COverlayMgr::Disp_ClipFragment(class CDispInfo __near *,class CUtlVector<struct moverlayfragment_t __near *,class CUtlMemory<struct moverlayfragment_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_ClipFragment(
        COverlayMgr *this,
        CDispInfo *pDisp,
        CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > *aDispFragments)
{
  int v4; // esi
  cplane_t clipPlane; // [esp+20h] [ebp-14h] BYREF

  v4 = 1 << *(_DWORD *)(pDisp->GetPowerInfo(this: &pDisp->CDispUtilsHelper) + 28);
  clipPlane.normal.x = 1.0;
  clipPlane.normal.y = 0.0;
  clipPlane.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    (CUtlMemory<S3RGBA,int> *)aDispFragments,
    &clipPlane,
    clipDistStart: 1.0,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  clipPlane.normal.x = 0.0;
  clipPlane.normal.y = 1.0;
  clipPlane.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    (CUtlMemory<S3RGBA,int> *)aDispFragments,
    &clipPlane,
    clipDistStart: 1.0,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)1,
    nLoopEnd: v4,
    nLoopInc: 1);
  clipPlane.normal.x = 0.70700002;
  clipPlane.normal.y = 0.70700002;
  clipPlane.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    (CUtlMemory<S3RGBA,int> *)aDispFragments,
    &clipPlane,
    clipDistStart: 0.70700002,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)2,
    nLoopEnd: 2 * v4 - 1,
    nLoopInc: 2);
  clipPlane.normal.x = -0.70700002;
  clipPlane.normal.y = 0.70700002;
  clipPlane.normal.z = 0.0;
  COverlayMgr::Disp_DoClip(
    this,
    pDisp,
    (CUtlMemory<S3RGBA,int> *)aDispFragments,
    &clipPlane,
    clipDistStart: 0.70700002,
    nInterval: (moverlayfragment_t *)v4,
    nLoopStart: (moverlayfragment_t *)(2 - v4),
    nLoopEnd: v4 - 1,
    nLoopInc: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100FCBD0
// Name: private: void COverlayMgr::Disp_CreateFragments(struct moverlay_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::Disp_CreateFragments(COverlayMgr *this, moverlay_t *pOverlay, msurface2_t *surfID)
{
  CDispInfo *pDispInfo; // esi
  int i; // ebx
  moverlayfragment_t *v6; // esi
  overlayvert_t *m_pMemory; // eax
  CUtlVector<moverlayfragment_t *,CUtlMemory<moverlayfragment_t *,int> > aDispFragments; // [esp+Ch] [ebp-14h] BYREF

  memset(&aDispFragments, 0, sizeof(aDispFragments));
  if ( COverlayMgr::Disp_PreClipFragment(this, pOverlay, &aDispFragments, surfID) != 0 )
  {
    pDispInfo = (CDispInfo *)surfID->pDispInfo;
    if ( pDispInfo != nullptr )
    {
      COverlayMgr::Disp_ClipFragment(this, pDisp: pDispInfo, &aDispFragments);
      COverlayMgr::Disp_PostClipFragment(
        this,
        pDisp: pDispInfo,
        pReader: &pDispInfo->m_MeshReader,
        pOverlay,
        &aDispFragments,
        surfID);
    }
  }
  for ( i = aDispFragments.m_Size - 1; i >= 0; --i )
  {
    v6 = aDispFragments.m_Memory.m_pMemory[i];
    if ( v6 != nullptr )
    {
      v6->m_aPrimVerts.m_Size = 0;
      if ( v6->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v6->m_aPrimVerts.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_aPrimVerts.m_Memory.m_pMemory);
          v6->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
        }
        v6->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v6->m_aPrimVerts.m_Memory.m_pMemory;
      v6->m_aPrimVerts.m_pElements = m_pMemory;
      if ( v6->m_aPrimVerts.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v6->m_aPrimVerts.m_Memory.m_pMemory = nullptr;
        }
        v6->m_aPrimVerts.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v6);
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&aDispFragments);
}

//------------------------------------------------------------------------------
// Address: 0x100FCCB0
// Name: public: virtual void COverlayMgr::CreateFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COverlayMgr::CreateFragments(COverlayMgr *this)
{
  int m_Size; // edx
  moverlay_t *v3; // esi
  int v4; // ecx
  bool v5; // al
  float x; // xmm7_4
  float z; // xmm3_4
  float y; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  int v12; // edi
  moverlay_t *v13; // esi
  float v14; // xmm1_4
  int m_hFirstFragment; // eax
  UtlLinkedListElem_t<unsigned short,unsigned short> *v16; // edx
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v17; // eax
  int v18; // ebx
  int v19; // edi
  overlayvert_t *m_pMemory; // edx
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float *p_z; // esi
  float *v25; // edx
  unsigned int v26; // ecx
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float *p_x; // ecx
  int v31; // edi
  bool v32; // zf
  moverlay_t *v33; // esi
  mtexinfo_t *v34; // ebx
  const char *v35; // edi
  int i; // eax
  int v37; // eax
  UtlLinkedListElem_t<moverlayfragment_t,unsigned short> *v38; // edi
  const char *v39; // eax
  _DWORD *v40; // edi
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  msurface2_t *v44; // [esp+18h] [ebp-5Ch]
  int v45; // [esp+28h] [ebp-4Ch]
  moverlayfragment_t *pFrag; // [esp+54h] [ebp-20h]
  moverlayfragment_t *pFraga; // [esp+54h] [ebp-20h]
  UtlLinkedListElem_t<unsigned short,unsigned short> *v48; // [esp+5Ch] [ebp-18h]
  int v49; // [esp+5Ch] [ebp-18h]
  int flRadiusSq; // [esp+60h] [ebp-14h]
  float flRadiusSqa; // [esp+60h] [ebp-14h]
  int flRadiusSqb; // [esp+60h] [ebp-14h]
  int v53; // [esp+64h] [ebp-10h]
  int v54; // [esp+64h] [ebp-10h]
  int nOverlayCount; // [esp+68h] [ebp-Ch]
  int iOverlay; // [esp+70h] [ebp-4h]
  int iOverlaya; // [esp+70h] [ebp-4h]
  int iOverlayb; // [esp+70h] [ebp-4h]

  m_Size = this->m_aOverlays.m_Size;
  nOverlayCount = m_Size;
  if ( m_Size > 0 )
  {
    iOverlay = 0;
    flRadiusSq = this->m_aOverlays.m_Size;
    do
    {
      v3 = &this->m_aOverlays.m_Memory.m_pMemory[iOverlay];
      v4 = v3->m_aFaces.m_Size;
      pFrag = (moverlayfragment_t *)v4;
      if ( v4 != 0 )
      {
        v5 = v3->m_vecUVPoints[3].z == 1.0;
        v3->m_vecUVPoints[3].z = 0.0;
        x = v3->m_vecBasis[2].x;
        if ( (LODWORD(x) & 0x7F800000) != 0x7F800000
          && (LODWORD(v3->m_vecBasis[2].y) & 0x7F800000) != 0x7F800000
          && (LODWORD(v3->m_vecBasis[2].z) & 0x7F800000) != 0x7F800000 )
        {
          z = v3->m_vecBasis[0].z;
          y = v3->m_vecBasis[0].y;
          v9 = (float)(v3->m_vecBasis[2].y * z) - (float)(v3->m_vecBasis[2].z * y);
          v10 = (float)(v3->m_vecBasis[0].x * v3->m_vecBasis[2].z) - (float)(z * x);
          v11 = (float)(y * x) - (float)(v3->m_vecBasis[0].x * v3->m_vecBasis[2].y);
          v3->m_vecBasis[1].x = v9;
          v3->m_vecBasis[1].y = v10;
          v3->m_vecBasis[1].z = v11;
          if ( v5 )
          {
            v3->m_vecBasis[1].x = -v9;
            v3->m_vecBasis[1].y = -v10;
            v3->m_vecBasis[1].z = -v11;
          }
        }
        v12 = 0;
        if ( v4 > 0 )
        {
          do
          {
            v44 = v3->m_aFaces.m_Memory.m_pMemory[v12];
            if ( (v44->flags & 0x800) != 0 )
              COverlayMgr::Disp_CreateFragments(this, pOverlay: v3, surfID: v44);
            else
              COverlayMgr::Surf_CreateFragments(this, pOverlay: (moverlayfragment_t *)v3, surfID: v44);
            ++v12;
          }
          while ( v12 < (int)pFrag );
          m_Size = nOverlayCount;
        }
      }
      ++iOverlay;
      --flRadiusSq;
    }
    while ( flRadiusSq != 0 );
    if ( m_Size > 0 )
    {
      iOverlaya = 0;
      v53 = nOverlayCount;
      do
      {
        v13 = &this->m_aOverlays.m_Memory.m_pMemory[iOverlaya];
        v14 = 0.0;
        m_hFirstFragment = v13->m_hFirstFragment;
        flRadiusSqa = 0.0;
        if ( m_hFirstFragment != 0xFFFF )
        {
          do
          {
            v16 = &this->m_OverlayFragments.m_Memory.m_pMemory[(unsigned __int16)m_hFirstFragment];
            v17 = &this->m_aFragments.m_Memory.m_pMemory[v16->m_Element];
            v18 = 0;
            v19 = v17->m_Element.m_aPrimVerts.m_Size;
            v48 = v16;
            if ( v19 >= 4 )
            {
              m_pMemory = v17->m_Element.m_aPrimVerts.m_Memory.m_pMemory;
              v21 = v13->m_vecOrigin.x;
              v22 = v13->m_vecOrigin.y;
              v23 = v13->m_vecOrigin.z;
              p_z = &m_pMemory->pos.z;
              v25 = &m_pMemory[1].pos.z;
              v26 = ((unsigned int)(v19 - 4) >> 2) + 1;
              v18 = 4 * v26;
              do
              {
                if ( v14 <= (float)((float)((float)((float)(*(p_z - 1) - v22) * (float)(*(p_z - 1) - v22))
                                          + (float)((float)(*(p_z - 2) - v21) * (float)(*(p_z - 2) - v21)))
                                  + (float)((float)(*p_z - v23) * (float)(*p_z - v23))) )
                  v14 = (float)((float)((float)(*(p_z - 1) - v22) * (float)(*(p_z - 1) - v22))
                              + (float)((float)(*(p_z - 2) - v21) * (float)(*(p_z - 2) - v21)))
                      + (float)((float)(*p_z - v23) * (float)(*p_z - v23));
                if ( v14 <= (float)((float)((float)((float)(*(v25 - 1) - v22) * (float)(*(v25 - 1) - v22))
                                          + (float)((float)(p_z[11] - v21) * (float)(p_z[11] - v21)))
                                  + (float)((float)(*v25 - v23) * (float)(*v25 - v23))) )
                  v14 = (float)((float)((float)(*(v25 - 1) - v22) * (float)(*(v25 - 1) - v22))
                              + (float)((float)(p_z[11] - v21) * (float)(p_z[11] - v21)))
                      + (float)((float)(*v25 - v23) * (float)(*v25 - v23));
                if ( v14 <= (float)((float)((float)((float)(v25[12] - v22) * (float)(v25[12] - v22))
                                          + (float)((float)(p_z[24] - v21) * (float)(p_z[24] - v21)))
                                  + (float)((float)(v25[13] - v23) * (float)(v25[13] - v23))) )
                  v14 = (float)((float)((float)(v25[12] - v22) * (float)(v25[12] - v22))
                              + (float)((float)(p_z[24] - v21) * (float)(p_z[24] - v21)))
                      + (float)((float)(v25[13] - v23) * (float)(v25[13] - v23));
                if ( v14 <= (float)((float)((float)((float)(v25[25] - v22) * (float)(v25[25] - v22))
                                          + (float)((float)(p_z[37] - v21) * (float)(p_z[37] - v21)))
                                  + (float)((float)(v25[26] - v23) * (float)(v25[26] - v23))) )
                  v14 = (float)((float)((float)(v25[25] - v22) * (float)(v25[25] - v22))
                              + (float)((float)(p_z[37] - v21) * (float)(p_z[37] - v21)))
                      + (float)((float)(v25[26] - v23) * (float)(v25[26] - v23));
                p_z += 52;
                v25 += 52;
                --v26;
              }
              while ( v26 != 0 );
              v16 = v48;
              v13 = &this->m_aOverlays.m_Memory.m_pMemory[iOverlaya];
            }
            if ( v18 < v19 )
            {
              p_x = &v17->m_Element.m_aPrimVerts.m_Memory.m_pMemory[v18].pos.x;
              v31 = v19 - v18;
              do
              {
                v27 = v13->m_vecOrigin.x;
                v28 = v13->m_vecOrigin.y;
                v29 = v13->m_vecOrigin.z;
                if ( v14 <= (float)((float)((float)((float)(p_x[1] - v28) * (float)(p_x[1] - v28))
                                          + (float)((float)(*p_x - v27) * (float)(*p_x - v27)))
                                  + (float)((float)(p_x[2] - v29) * (float)(p_x[2] - v29))) )
                  v14 = (float)((float)((float)(p_x[1] - v28) * (float)(p_x[1] - v28))
                              + (float)((float)(*p_x - v27) * (float)(*p_x - v27)))
                      + (float)((float)(p_x[2] - v29) * (float)(p_x[2] - v29));
                p_x += 13;
                --v31;
              }
              while ( v31 != 0 );
            }
            m_hFirstFragment = v16->m_Next;
          }
          while ( m_hFirstFragment != 0xFFFF );
          flRadiusSqa = v14;
        }
        ++iOverlaya;
        v32 = v53-- == 1;
        v13->m_flRadius = sqrt(flRadiusSqa);
      }
      while ( !v32 );
    }
  }
  iOverlayb = 0;
  if ( nOverlayCount > 0 )
  {
    flRadiusSqb = 0;
    do
    {
      v33 = &this->m_aOverlays.m_Memory.m_pMemory[flRadiusSqb];
      v34 = &host_state.worldbrush->texinfo[v33->m_nTexInfo];
      v35 = v34->material->GetShaderName(this: v34->material);
      v33->m_nFlags = _V_stricmp(s1: v35, s2: "UnlitGeneric") == 0 || _V_stricmp(s1: v35, s2: "DecalModulate") == 0;
      for ( i = v33->m_hFirstFragment;
            i != 0xFFFF;
            i = *(unsigned __int16 *)((char *)&this->m_OverlayFragments.m_Memory.m_pMemory->m_Next + v45) )
      {
        v37 = (unsigned __int16)i;
        v38 = &this->m_aFragments.m_Memory.m_pMemory[this->m_OverlayFragments.m_Memory.m_pMemory[v37].m_Element];
        v45 = v37 * 6;
        pFraga = &v38->m_Element;
        if ( (LODWORD(v38->m_Element.decalOffset) & 0x7F800000) == 0x7F800000 )
        {
          if ( v34->material != nullptr )
            v39 = v34->material->GetName(this: v34->material);
          else
            v39 = defaultValue;
          _DevMsg(a1: 1, a2: "Bad overlay decal offset - %d with material '%s'\n", iOverlayb, v39);
        }
        if ( v38->m_Element.m_aPrimVerts.m_Size > 0 )
        {
          v54 = 0;
          v49 = v38->m_Element.m_aPrimVerts.m_Size;
          do
          {
            v40 = (_DWORD *)&pFraga->m_aPrimVerts.m_Memory.m_pMemory[v54].pos.x;
            if ( (*v40 & 0x7F800000) == 0x7F800000
              || (v40[1] & 0x7F800000) == 0x7F800000
              || (v40[2] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v41 = v34->material->GetName(this: v34->material);
              else
                v41 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay vert - %d at (%f, %f, %f) with material '%s'\n",
                iOverlayb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v41);
            }
            if ( (v40[3] & 0x7F800000) == 0x7F800000
              || (v40[4] & 0x7F800000) == 0x7F800000
              || (v40[5] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v42 = v34->material->GetName(this: v34->material);
              else
                v42 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay normal - %d at (%f, %f, %f) with material '%s'\n",
                iOverlayb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v42);
            }
            if ( (v40[6] & 0x7F800000) == 0x7F800000
              || (v40[7] & 0x7F800000) == 0x7F800000
              || (v40[8] & 0x7F800000) == 0x7F800000
              || (v40[9] & 0x7F800000) == 0x7F800000 )
            {
              if ( v34->material != nullptr )
                v43 = v34->material->GetName(this: v34->material);
              else
                v43 = defaultValue;
              _DevMsg(
                a1: 1,
                a2: "Bad overlay texture coords - %d at (%f, %f, %f) with material '%s'\n",
                iOverlayb,
                v33->m_vecOrigin.x,
                v33->m_vecOrigin.y,
                v33->m_vecOrigin.z,
                v43);
            }
            ++v54;
            --v49;
          }
          while ( v49 != 0 );
        }
      }
      ++flRadiusSqb;
      ++iOverlayb;
    }
    while ( iOverlayb < nOverlayCount );
  }
}

} // namespace engine_xlsp
