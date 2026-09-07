// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispshore.cpp
// Functions: 28
// ============================================================

#include "hammer\dispshore.h"

//------------------------------------------------------------------------------
// Address: 0x10028790
// Name: public: virtual char const __near * CMapOverlayTransition::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapOverlayTransition::GetType(CMapOverlayTransition *this)
{
  return CMapOverlayTransition::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x100287A0
// Name: public: virtual int CMapOverlayTransition::IsMapClass(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapOverlayTransition::IsMapClass(CMapOverlayTransition *this, const char *Type)
{
  return Type == CMapOverlayTransition::__Type;
}

//------------------------------------------------------------------------------
// Address: 0x100287C0
// Name: class IDispShoreManager __near * GetShoreManager(void)
// Source: json
//------------------------------------------------------------------------------
CDispShoreManager *__cdecl GetShoreManager()
{
  return &s_DispShoreManager;
}

//------------------------------------------------------------------------------
// Address: 0x10028990
// Name: public: virtual struct Shoreline_t __near * CDispShoreManager::GetShoreline(int)
// Source: json
//------------------------------------------------------------------------------
Shoreline_t *__thiscall CDispShoreManager::GetShoreline(CDispShoreManager *this, int nShorelineId)
{
  int m_Size; // edx
  int v3; // eax
  Shoreline_t *m_pMemory; // esi
  Shoreline_t *i; // ecx

  m_Size = this->m_aShorelines.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = this->m_aShorelines.m_Memory.m_pMemory;
  for ( i = m_pMemory; i->m_nShorelineId != nShorelineId; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  return &m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x100289D0
// Name: private: void CDispShoreManager::BuildShorelineSegments(struct Shoreline_t __near *,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::BuildShorelineSegments(
        CDispShoreManager *this,
        Shoreline_t *pShoreline,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aFaces,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aWaterFaces)
{
  int m_Size; // ecx
  int v5; // ebx
  int v6; // edi
  CMapFace *v7; // esi
  CEditDispMgr *v8; // eax
  CMapDisp *v9; // eax
  int nWaterFaceCount; // [esp+4h] [ebp-8h]
  int nFaceCount; // [esp+8h] [ebp-4h]

  m_Size = aWaterFaces->m_Size;
  v5 = 0;
  for ( nWaterFaceCount = m_Size; v5 < m_Size; ++v5 )
  {
    v6 = 0;
    nFaceCount = aFaces->m_Size;
    if ( nFaceCount > 0 )
    {
      do
      {
        v7 = aFaces->m_Memory.m_pMemory[v6];
        if ( v7 != nullptr && v7->m_DispHandle != 0xFFFF )
        {
          v8 = EditDispMgr();
          v9 = v8->GetDisp(this: v8, a2: v7->m_DispHandle);
          if ( v9 != nullptr )
            CMapDisp::CreateShoreOverlays(this: v9, pFace: aWaterFaces->m_Memory.m_pMemory[v5], pShoreline);
        }
        ++v6;
      }
      while ( v6 < nFaceCount );
      m_Size = nWaterFaceCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028A60
// Name: private: void CDispShoreManager::AverageShorelineNormals(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::AverageShorelineNormals(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  Shoreline_t *v2; // edi
  int m_Size; // eax
  int v4; // ebx
  int v5; // ecx
  int v6; // esi
  ShoreSegment_t *m_pMemory; // eax
  int v8; // edx
  int v9; // ecx
  float v10; // xmm2_4
  ShoreSegment_t *v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  double v15; // st7
  int v16; // eax
  int v17; // edi
  ShoreSegment_t *v18; // eax
  bool v19; // zf
  Vector vecNormal; // [esp+4h] [ebp-24h] BYREF
  int nSegmentCount; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  int v24; // [esp+1Ch] [ebp-Ch]
  int v25; // [esp+20h] [ebp-8h]
  int iPoint2; // [esp+24h] [ebp-4h]

  v2 = pShoreline;
  m_Size = pShoreline->m_aSegments.m_Size;
  nSegmentCount = m_Size;
  if ( m_Size <= 0 )
    return;
  v4 = 0;
  v5 = 1;
  v23 = 0;
  v24 = 1;
  v22 = m_Size;
  do
  {
    if ( v5 >= m_Size )
      goto LABEL_26;
    v6 = v4 + 308;
    v25 = m_Size - v5;
    do
    {
      m_pMemory = v2->m_aSegments.m_Memory.m_pMemory;
      v8 = -1;
      v9 = -1;
      v10 = fabs(
              *(float *)((char *)&m_pMemory->m_vecPoints[0].x + v4)
            - *(float *)((char *)&m_pMemory->m_vecPoints[0].x + v6));
      iPoint2 = -1;
      if ( v10 <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[0].y + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[0].y + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[0].z + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[0].z + v6)) <= 0.1 )
      {
        v8 = 0;
        v9 = 0;
        iPoint2 = 0;
      }
      if ( fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[0].x + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].x + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[0].y + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].y + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[0].z + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].z + v6)) <= 0.1 )
      {
        v9 = 1;
        v8 = 0;
        iPoint2 = 1;
      }
      if ( fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].x + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[0].x + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].y + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[0].y + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].z + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[0].z + v6)) <= 0.1 )
      {
        v9 = 0;
        v8 = 1;
        iPoint2 = 0;
      }
      if ( fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].x + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].x + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].y + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].y + v6)) <= 0.1
        && fabs(
             *(float *)((char *)&m_pMemory->m_vecPoints[1].z + v4)
           - *(float *)((char *)&m_pMemory->m_vecPoints[1].z + v6)) <= 0.1 )
      {
        v8 = 1;
        v9 = 1;
        iPoint2 = 1;
LABEL_23:
        v11 = m_pMemory;
        v12 = v4 + 12 * v8;
        v13 = v6 + 12 * v9;
        *(float *)((char *)&v11->m_vecPoints[0].x + v13) = *(float *)((char *)&v11->m_vecPoints[0].x + v12);
        v14 = v4 + 4 * (3 * v8 + 6);
        *(float *)((char *)&v11->m_vecPoints[0].y + v13) = *(float *)((char *)&v11->m_vecPoints[0].y + v12);
        v15 = *(float *)((char *)&v11->m_vecPoints[0].z + v12);
        v16 = iPoint2;
        *(float *)((char *)&v11->m_vecPoints[0].z + v13) = v15;
        v17 = v6 + 4 * (3 * v16 + 6);
        v18 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        vecNormal.x = *(float *)((char *)&v18->m_vecPoints[0].x + v17)
                    + *(float *)((char *)&v18->m_vecPoints[0].x + v14);
        vecNormal.y = *(float *)((char *)&v18->m_vecPoints[0].y + v17)
                    + *(float *)((char *)&v18->m_vecPoints[0].y + v14);
        vecNormal.z = *(float *)((char *)&v18->m_vecPoints[0].z + v17)
                    + *(float *)((char *)&v18->m_vecPoints[0].z + v14);
        VectorNormalize(vec: &vecNormal);
        *(Vector *)((char *)pShoreline->m_aSegments.m_Memory.m_pMemory->m_vecPoints + v14) = vecNormal;
        v4 = v23;
        *(Vector *)((char *)pShoreline->m_aSegments.m_Memory.m_pMemory->m_vecPoints + v17) = vecNormal;
        v2 = pShoreline;
        goto LABEL_24;
      }
      if ( v8 != -1 && v9 != -1 )
        goto LABEL_23;
LABEL_24:
      v6 += 308;
      --v25;
    }
    while ( v25 != 0 );
    m_Size = nSegmentCount;
    v5 = v24;
LABEL_26:
    ++v5;
    v4 += 308;
    v19 = v22-- == 1;
    v24 = v5;
    v23 = v4;
  }
  while ( !v19 );
}

//------------------------------------------------------------------------------
// Address: 0x10028CF0
// Name: private: void CDispShoreManager::ShorelineLength(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::ShorelineLength(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  float v2; // xmm3_4
  int m_Size; // edx
  ShoreSegment_t *m_pMemory; // ecx
  float *p_z; // eax

  v2 = 0.0;
  m_Size = pShoreline->m_aSegments.m_Size;
  if ( m_Size > 0 )
  {
    m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
    p_z = &m_pMemory->m_vecPoints[1].z;
    do
    {
      v2 = v2
         + fsqrt(
             (float)((float)((float)(*(p_z - 1) - *(p_z - 4)) * (float)(*(p_z - 1) - *(p_z - 4)))
                   + (float)((float)(*p_z - *(p_z - 3)) * (float)(*p_z - *(p_z - 3))))
           + (float)((float)(*(p_z - 2) - m_pMemory->m_vecPoints[0].x)
                   * (float)(*(p_z - 2) - m_pMemory->m_vecPoints[0].x)));
      ++m_pMemory;
      p_z += 77;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  pShoreline->m_flLength = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10028D90
// Name: private: void CDispShoreManager::GenerateTexCoord(struct Shoreline_t __near *,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::GenerateTexCoord(
        CDispShoreManager *this,
        Shoreline_t *pShoreline,
        int iSegment,
        float flLengthToSegment,
        bool bEnd)
{
  int v5; // ecx
  ShoreSegment_t *m_pMemory; // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  ShoreSegment_t *v9; // edx
  ShoreSegment_t *v10; // edx
  float v11; // xmm2_4
  float v12; // xmm1_4
  ShoreSegment_t *v13; // edx
  float v14; // xmm3_4
  ShoreSegment_t *v15; // edx

  v5 = iSegment;
  m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
  v7 = pShoreline->m_ShoreData.m_vecLengthTexcoord.y - pShoreline->m_ShoreData.m_vecLengthTexcoord.x;
  if ( m_pMemory[iSegment].m_iStartPoint != 0 )
  {
    if ( bEnd )
      goto LABEL_3;
  }
  else if ( !bEnd )
  {
LABEL_3:
    v8 = (float)(flLengthToSegment / pShoreline->m_flLength) * v7;
    m_pMemory[v5].m_WorldFace.m_vecTexCoords[0].x = v8;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[0].x = v8;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[0].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                   * 0.5;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[0].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.x;
    v9 = pShoreline->m_aSegments.m_Memory.m_pMemory;
    if ( v9[v5].m_WorldFace.m_bAdjWinding )
    {
      v9[v5].m_WorldFace.m_vecTexCoords[3].x = v8;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[3].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y;
    }
    else
    {
      v9[v5].m_WorldFace.m_vecTexCoords[1].x = v8;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[1].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y;
    }
    v15 = pShoreline->m_aSegments.m_Memory.m_pMemory;
    if ( v15[v5].m_WaterFace.m_bAdjWinding )
    {
      v15[v5].m_WaterFace.m_vecTexCoords[3].x = v8;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[3].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                     * 0.5;
    }
    else
    {
      v15[v5].m_WaterFace.m_vecTexCoords[1].x = v8;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[1].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                     * 0.5;
    }
    return;
  }
  v12 = (float)(flLengthToSegment / pShoreline->m_flLength) * v7;
  m_pMemory[v5].m_WorldFace.m_vecTexCoords[2].x = v12;
  pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[2].x = v12;
  pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[2].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y;
  pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[2].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                 * 0.5;
  v13 = pShoreline->m_aSegments.m_Memory.m_pMemory;
  v14 = (float)(flLengthToSegment / pShoreline->m_flLength) * v7;
  if ( v13[v5].m_WorldFace.m_bAdjWinding )
  {
    v13[v5].m_WorldFace.m_vecTexCoords[1].x = v14;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[1].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                   * 0.5;
  }
  else
  {
    v13[v5].m_WorldFace.m_vecTexCoords[3].x = v14;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WorldFace.m_vecTexCoords[3].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.y
                                                                                   * 0.5;
  }
  v10 = pShoreline->m_aSegments.m_Memory.m_pMemory;
  v11 = (float)(flLengthToSegment / pShoreline->m_flLength) * v7;
  if ( v10[v5].m_WaterFace.m_bAdjWinding )
  {
    v10[v5].m_WaterFace.m_vecTexCoords[1].x = v11;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[1].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.x;
  }
  else
  {
    v10[v5].m_WaterFace.m_vecTexCoords[3].x = v11;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v5].m_WaterFace.m_vecTexCoords[3].y = pShoreline->m_ShoreData.m_vecWidthTexcoord.x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028FB0
// Name: public: virtual void CDispShoreManager::Draw(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::Draw(CDispShoreManager *this, CRender3D *pRender)
{
  Shoreline_t *v2; // edi
  int v3; // esi
  int v4; // ebx
  CMapOverlay *v5; // ecx
  CDispShoreManager *v6; // [esp+0h] [ebp-Ch]
  int m_Size; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  v6 = this;
  if ( this->m_aShorelines.m_Size > 0 )
  {
    v8 = 0;
    m_Size = this->m_aShorelines.m_Size;
    do
    {
      v2 = &this->m_aShorelines.m_Memory.m_pMemory[v8];
      if ( v2 != nullptr && v2->m_aOverlays.m_Size > 0 )
      {
        v3 = 0;
        v4 = v2->m_aOverlays.m_Size;
        do
        {
          v5 = &v2->m_aOverlays.m_Memory.m_pMemory[v3];
          if ( v5 != nullptr )
            v5->Render3D(this: v5, a2: pRender);
          ++v3;
          --v4;
        }
        while ( v4 != 0 );
        this = v6;
      }
      ++v8;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029020
// Name: private: void CDispShoreManager::DrawShorelines(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDispShoreManager::DrawShorelines(
        CDispShoreManager *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        int iShoreline)
{
  Shoreline_t *v4; // edi
  int m_Size; // esi
  IMatRenderContext *v6; // ebx
  IMesh *v7; // ebx
  int v8; // esi
  int v9; // esi
  ShoreSegment_t *m_pMemory; // edx
  float y; // xmm2_4
  float v12; // xmm0_4
  float *m_pCurrPosition; // eax
  ShoreSegment_t *v14; // edx
  float v15; // xmm2_4
  float v16; // xmm0_4
  float *v17; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v19; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-214h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-2Ch]
  int v23; // [esp+1F0h] [ebp-28h]
  int v24; // [esp+1F4h] [ebp-24h]
  IMatRenderContext *v25; // [esp+1F8h] [ebp-20h]
  int v26; // [esp+1FCh] [ebp-1Ch]
  int v27; // [esp+200h] [ebp-18h]
  int v28; // [esp+204h] [ebp-14h]
  int v29; // [esp+208h] [ebp-10h]
  int v30; // [esp+214h] [ebp-4h]
  int nSegmentCount; // [esp+220h] [ebp+8h]

  v4 = &this->m_aShorelines.m_Memory.m_pMemory[iShoreline];
  if ( v4 != nullptr )
  {
    m_Size = v4->m_aSegments.m_Size;
    nSegmentCount = m_Size;
    if ( m_Size != 0 )
    {
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      v30 = 0;
      v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                  a1: materials,
                                  a2,
                                  a3);
      v25 = v6;
      pRenderContext.m_pObject = v6;
      LOBYTE(v30) = 1;
      if ( v6 != nullptr )
        v6->BeginRender(this: v6);
      LOBYTE(v30) = 2;
      v7 = v6->GetDynamicMesh(this: v6, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      meshBuilder.m_pMesh = v7;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v8 = 4 * m_Size;
      v7->SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v7,
        nMaxVertexCount: v8,
        desc: &meshBuilder);
      v9 = 0;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      if ( nSegmentCount > 0 )
      {
        do
        {
          v26 = 1258291200;
          v24 = 1258291200;
          v28 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          m_pMemory = v4->m_aSegments.m_Memory.m_pMemory;
          y = m_pMemory[v9].m_vecPoints[0].y;
          v12 = m_pMemory[v9].m_vecPoints[0].z + 50.0;
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v9].m_vecPoints[0].x;
          m_pCurrPosition[1] = y;
          m_pCurrPosition[2] = v12;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v27 = 1258291200;
          v29 = 1258291200;
          v23 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          v14 = v4->m_aSegments.m_Memory.m_pMemory;
          v15 = v14[v9].m_vecPoints[1].y;
          v16 = v14[v9].m_vecPoints[1].z + 50.0;
          v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v14[v9].m_vecPoints[1].x;
          v17[1] = v15;
          v17[2] = v16;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v9;
          --nSegmentCount;
        }
        while ( nSegmentCount != 0 );
      }
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
      ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v7->Draw_2(this: v7, a2: -1, a3: 0);
      LOBYTE(v30) = 3;
      v19 = v25;
      v25->EndRender(this: v25);
      LOBYTE(v30) = 0;
      v19->Release(this: v19);
      v30 = -1;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029380
// Name: private: void CDispShoreManager::DrawShorelineNormals(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDispShoreManager::DrawShorelineNormals(
        CDispShoreManager *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        int iShoreline)
{
  Shoreline_t *v4; // edi
  int m_Size; // esi
  IMatRenderContext *v6; // ebx
  IMesh *v7; // ebx
  int v8; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v10; // esi
  int i; // ebx
  ShoreSegment_t *m_pMemory; // edx
  float y; // xmm2_4
  float v14; // xmm0_4
  float *m_pCurrPosition; // eax
  ShoreSegment_t *v16; // edx
  float z; // xmm2_4
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm3_4
  ShoreSegment_t *v21; // edx
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm0_4
  ShoreSegment_t *v25; // edx
  float v26; // xmm2_4
  float v27; // xmm1_4
  float *v28; // eax
  float v29; // xmm3_4
  int m_nVertexCount; // eax
  IMatRenderContext *v31; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-22Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-44h]
  int v35; // [esp+1F0h] [ebp-40h]
  int v36; // [esp+1F4h] [ebp-3Ch]
  IMatRenderContext *v37; // [esp+1F8h] [ebp-38h]
  int v38; // [esp+1FCh] [ebp-34h]
  IMesh *pMesh; // [esp+200h] [ebp-30h]
  int v40; // [esp+204h] [ebp-2Ch]
  int v41; // [esp+208h] [ebp-28h]
  int v42; // [esp+20Ch] [ebp-24h]
  int v43; // [esp+210h] [ebp-20h]
  int v44; // [esp+214h] [ebp-1Ch]
  int v45; // [esp+218h] [ebp-18h]
  int v46; // [esp+21Ch] [ebp-14h]
  int v47; // [esp+220h] [ebp-10h]
  int v48; // [esp+22Ch] [ebp-4h]
  int nSegmentCount; // [esp+238h] [ebp+8h]

  v4 = &this->m_aShorelines.m_Memory.m_pMemory[iShoreline];
  if ( v4 != nullptr )
  {
    m_Size = v4->m_aSegments.m_Size;
    nSegmentCount = m_Size;
    if ( m_Size != 0 )
    {
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      v48 = 0;
      v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                  a1: materials,
                                  a2,
                                  a3);
      v37 = v6;
      pRenderContext.m_pObject = v6;
      LOBYTE(v48) = 1;
      if ( v6 != nullptr )
        v6->BeginRender(this: v6);
      LOBYTE(v48) = 2;
      v7 = v6->GetDynamicMesh(this: v6, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      meshBuilder.m_pMesh = v7;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v8 = 8 * m_Size;
      SetPrimitiveType = v7->SetPrimitiveType;
      pMesh = v7;
      SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v7,
        nMaxVertexCount: v8,
        desc: &meshBuilder);
      v10 = 0;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      if ( nSegmentCount > 0 )
      {
        for ( i = nSegmentCount; i != 0; --i )
        {
          v36 = 1258291200;
          v46 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
          m_pMemory = v4->m_aSegments.m_Memory.m_pMemory;
          y = m_pMemory[v10].m_vecPoints[0].y;
          v14 = m_pMemory[v10].m_vecPoints[0].z + 50.0;
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = m_pMemory[v10].m_vecPoints[0].x;
          m_pCurrPosition[1] = y;
          m_pCurrPosition[2] = v14;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v42 = 1258291200;
          v38 = 1258291455;
          v44 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
          v16 = v4->m_aSegments.m_Memory.m_pMemory;
          z = v16[v10].m_vecNormals[0].z;
          v18 = (float)(v16[v10].m_vecNormals[0].y * 25.0) + v16[v10].m_vecPoints[0].y;
          v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v20 = v16[v10].m_vecPoints[0].z + 50.0;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v16[v10].m_vecNormals[0].x * 25.0)
                                                       + v16[v10].m_vecPoints[0].x;
          v19[1] = v18;
          v19[2] = (float)(z * 25.0) + v20;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v47 = 1258291200;
          v40 = 1258291455;
          v35 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
          v21 = v4->m_aSegments.m_Memory.m_pMemory;
          v22 = v21[v10].m_vecPoints[1].y;
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v24 = v21[v10].m_vecPoints[1].z + 50.0;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v21[v10].m_vecPoints[1].x;
          v23[1] = v22;
          v23[2] = v24;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v41 = 1258291200;
          v43 = 1258291455;
          v45 = 1258291455;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
          v25 = v4->m_aSegments.m_Memory.m_pMemory;
          v26 = v25[v10].m_vecNormals[1].z;
          v27 = (float)(v25[v10].m_vecNormals[1].y * 25.0) + v25[v10].m_vecPoints[1].y;
          v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v29 = v25[v10].m_vecPoints[1].z + 50.0;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v25[v10].m_vecNormals[1].x * 25.0)
                                                       + v25[v10].m_vecPoints[1].x;
          v28[1] = v27;
          v28[2] = (float)(v26 * 25.0) + v29;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v10;
        }
        v7 = pMesh;
      }
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
      ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v7->Draw_2(this: v7, a2: -1, a3: 0);
      LOBYTE(v48) = 3;
      v31 = v37;
      v37->EndRender(this: v37);
      LOBYTE(v48) = 0;
      v31->Release(this: v31);
      v48 = -1;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029850
// Name: private: void CDispShoreManager::DrawShorelineOverlayPoints(class CRender3D __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::DrawShorelineOverlayPoints(
        CDispShoreManager *this,
        CRender3D *pRender,
        int iShoreline)
{
  Shoreline_t *v3; // ebx
  int v4; // edi
  int i; // esi
  ShoreSegment_t *m_pMemory; // ecx
  float v7; // xmm6_4
  int j; // esi
  Vector *v9; // eax
  float v10; // xmm6_4
  Vector vecWorldMax; // [esp+4h] [ebp-18h] BYREF
  Vector vecWorldMin; // [esp+10h] [ebp-Ch] BYREF
  int iShorelinea; // [esp+28h] [ebp+Ch]

  v3 = &this->m_aShorelines.m_Memory.m_pMemory[iShoreline];
  if ( v3 != nullptr && v3->m_aSegments.m_Size > 0 )
  {
    v4 = 0;
    iShorelinea = v3->m_aSegments.m_Size;
    do
    {
      for ( i = 0; i < 4; ++i )
      {
        m_pMemory = v3->m_aSegments.m_Memory.m_pMemory;
        vecWorldMin = m_pMemory[v4].m_WorldFace.m_vecPoints[i];
        vecWorldMax.x = m_pMemory[v4].m_WorldFace.m_vecPoints[i].x;
        vecWorldMax.y = m_pMemory[v4].m_WorldFace.m_vecPoints[i].y;
        v7 = m_pMemory[v4].m_WorldFace.m_vecPoints[i].z + 5.0;
        vecWorldMin.x = vecWorldMin.x - 5.0;
        vecWorldMax.x = vecWorldMax.x + 5.0;
        vecWorldMin.y = vecWorldMin.y - 5.0;
        vecWorldMax.y = vecWorldMax.y + 5.0;
        vecWorldMin.z = vecWorldMin.z - 5.0;
        vecWorldMax.z = v7;
        CRender3D::RenderBox(
          this: pRender,
          Mins: &vecWorldMin,
          Maxs: &vecWorldMax,
          chRed: 0xFFu,
          chGreen: 0,
          chBlue: 0,
          eBoxSelectionState: SELECT_NONE);
      }
      for ( j = 17; j < 21; ++j )
      {
        v9 = &v3->m_aSegments.m_Memory.m_pMemory[v4].m_vecPoints[j];
        vecWorldMin = *v9;
        vecWorldMax.x = v9->x;
        vecWorldMax.y = v9->y;
        v10 = v9->z + 5.0;
        vecWorldMin.x = vecWorldMin.x - 5.0;
        vecWorldMax.x = vecWorldMax.x + 5.0;
        vecWorldMin.y = vecWorldMin.y - 5.0;
        vecWorldMax.y = vecWorldMax.y + 5.0;
        vecWorldMin.z = vecWorldMin.z - 5.0;
        vecWorldMax.z = v10;
        CRender3D::RenderBox(
          this: pRender,
          Mins: &vecWorldMin,
          Maxs: &vecWorldMax,
          chRed: 0,
          chGreen: 0,
          chBlue: 0xFFu,
          eBoxSelectionState: SELECT_NONE);
      }
      ++v4;
      --iShorelinea;
    }
    while ( iShorelinea != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100299F0
// Name: public: virtual void CDispShoreManager::DebugDraw(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::DebugDraw(CDispShoreManager *this, CRender3D *pRender)
{
  int v4; // esi
  int nShorelineCount; // [esp+14h] [ebp+8h]

  pRender->SetRenderMode(this: pRender, a2: RENDER_MODE_WIREFRAME, a3: false);
  v4 = 0;
  nShorelineCount = this->GetShorelineCount(this);
  if ( nShorelineCount > 0 )
  {
    do
    {
      CDispShoreManager::DrawShorelines(this, a2: (int)pRender, a3: v4, iShoreline: v4);
      CDispShoreManager::DrawShorelineNormals(this, a2: (int)pRender, a3: v4, iShoreline: v4);
      CDispShoreManager::DrawShorelineOverlayPoints(this, pRender, iShoreline: v4++);
    }
    while ( v4 < nShorelineCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029C40
// Name: public: Shoreline_t::Shoreline_t(void)
// Source: json
//------------------------------------------------------------------------------
Shoreline_t *__thiscall Shoreline_t::Shoreline_t(Shoreline_t *this)
{
  CUtlVector<ShoreSegment_t,CUtlMemory<ShoreSegment_t,int> > *p_m_aSegments; // eax
  ShoreSegment_t *m_pMemory; // ecx
  int *v4; // ecx
  CMapOverlay *v5; // ecx

  p_m_aSegments = &this->m_aSegments;
  this->m_aSegments.m_Memory.m_pMemory = nullptr;
  this->m_aSegments.m_Memory.m_nAllocationCount = 0;
  this->m_aSegments.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aSegments.m_Memory.m_pMemory;
  p_m_aSegments->m_Size = 0;
  p_m_aSegments->m_pElements = m_pMemory;
  this->m_aSortedSegments.m_Memory.m_pMemory = nullptr;
  this->m_aSortedSegments.m_Memory.m_nAllocationCount = 0;
  this->m_aSortedSegments.m_Memory.m_nGrowSize = 0;
  v4 = this->m_aSortedSegments.m_Memory.m_pMemory;
  this->m_aSortedSegments.m_Size = 0;
  this->m_aSortedSegments.m_pElements = v4;
  this->m_aOverlays.m_Memory.m_pMemory = nullptr;
  this->m_aOverlays.m_Memory.m_nAllocationCount = 0;
  this->m_aOverlays.m_Memory.m_nGrowSize = 0;
  v5 = this->m_aOverlays.m_Memory.m_pMemory;
  this->m_aOverlays.m_Size = 0;
  this->m_aOverlays.m_pElements = v5;
  this->m_nShorelineId = -1;
  this->m_aSegments.m_Size = 0;
  if ( this->m_aSegments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aSegments.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aSegments.m_Memory.m_pMemory);
      this->m_aSegments.m_Memory.m_pMemory = nullptr;
    }
    this->m_aSegments.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aSegments.m_pElements = this->m_aSegments.m_Memory.m_pMemory;
  CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(this: &this->m_aOverlays);
  this->m_flLength = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029D20
// Name: public: Shoreline_t::~Shoreline_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Shoreline_t::~Shoreline_t(Shoreline_t *this)
{
  CUtlVector<ShoreSegment_t,CUtlMemory<ShoreSegment_t,int> > *p_m_aSegments; // esi
  CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int> > *p_m_aOverlays; // edi
  CUtlVector<int,CUtlMemory<int,int> > *p_m_aSortedSegments; // edi

  p_m_aSegments = &this->m_aSegments;
  this->m_aSegments.m_Size = 0;
  if ( this->m_aSegments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aSegments->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aSegments->m_Memory.m_pMemory);
      p_m_aSegments->m_Memory.m_pMemory = nullptr;
    }
    p_m_aSegments->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aOverlays = &this->m_aOverlays;
  p_m_aSegments->m_pElements = p_m_aSegments->m_Memory.m_pMemory;
  CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(this: p_m_aOverlays);
  CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(this: p_m_aOverlays);
  if ( p_m_aOverlays->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aOverlays->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aOverlays->m_Memory.m_pMemory);
      p_m_aOverlays->m_Memory.m_pMemory = nullptr;
    }
    p_m_aOverlays->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aSortedSegments = &this->m_aSortedSegments;
  this->m_aSortedSegments.m_Size = 0;
  if ( this->m_aSortedSegments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aSortedSegments->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aSortedSegments->m_Memory.m_pMemory);
      p_m_aSortedSegments->m_Memory.m_pMemory = nullptr;
    }
    this->m_aSortedSegments.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aSortedSegments.m_pElements = this->m_aSortedSegments.m_Memory.m_pMemory;
  if ( this->m_aSortedSegments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aSortedSegments->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aSortedSegments->m_Memory.m_pMemory);
      p_m_aSortedSegments->m_Memory.m_pMemory = nullptr;
    }
    this->m_aSortedSegments.m_Memory.m_nAllocationCount = 0;
  }
  p_m_aSegments->m_Size = 0;
  if ( p_m_aSegments->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aSegments->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aSegments->m_Memory.m_pMemory);
      p_m_aSegments->m_Memory.m_pMemory = nullptr;
    }
    p_m_aSegments->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aSegments->m_pElements = p_m_aSegments->m_Memory.m_pMemory;
  if ( p_m_aSegments->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aSegments->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aSegments->m_Memory.m_pMemory);
      p_m_aSegments->m_Memory.m_pMemory = nullptr;
    }
    p_m_aSegments->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029E60
// Name: public: void Shoreline_t::AddSegment(class Vector __near &,class Vector __near &,class Vector __near &,float,class CMapFace __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Shoreline_t::AddSegment(
        Shoreline_t *this,
        Vector *vecPoint0,
        Vector *vecPoint1,
        Vector *vecNormal,
        float flWaterZ,
        CMapFace *pWaterFace,
        unsigned __int16 hDisp)
{
  Vector *v7; // edx
  Shoreline_t *v8; // eax
  int m_Size; // esi
  int v10; // ecx
  float *m_pMemory; // edi
  float x; // xmm4_4
  float *v13; // eax
  float v14; // xmm3_4
  Vector *v15; // edi
  int v16; // edi
  CUtlMemory<ShoreSegment_t,int> *p_m_Memory; // esi
  int m_nAllocationCount; // eax
  ShoreSegment_t *v19; // ecx
  int v20; // eax
  int v21; // eax
  float v22; // xmm3_4
  float v23; // xmm4_4
  int v24; // edx
  double z; // st7
  Vector *v26; // edx
  ShoreSegment_t *v27; // ecx
  ShoreSegment_t *v28; // edx
  ShoreSegment_t *v29; // ecx
  int v30; // ecx
  ShoreSegment_t *v31; // edx
  ShoreSegment_t *v32; // edx
  ShoreSegment_t *v33; // edx
  ShoreSegment_t *v34; // edx
  _DWORD *p_x; // edx
  _DWORD *v36; // edx
  ShoreSegment_t *v37; // edx
  ShoreSegment_t *v38; // edx
  ShoreSegment_t *v39; // edx
  ShoreSegment_t *v40; // edx
  ShoreSegment_t *v41; // edx
  ShoreSegment_t *v42; // edx
  _DWORD *v43; // edx
  _DWORD *v44; // eax
  Shoreline_t *v45; // [esp+Ch] [ebp-14h]
  vgui::ToolWindow *v46; // [esp+10h] [ebp-10h]
  Vector *vecPoint0a; // [esp+28h] [ebp+8h]
  Vector *vecPoint1a; // [esp+2Ch] [ebp+Ch]

  v7 = vecPoint0;
  v8 = this;
  m_Size = this->m_aSegments.m_Size;
  v10 = 0;
  v45 = v8;
  if ( m_Size > 0 )
  {
    m_pMemory = (float *)v8->m_aSegments.m_Memory.m_pMemory;
    x = vecPoint0->x;
    v46 = (vgui::ToolWindow *)m_pMemory;
    v13 = m_pMemory + 5;
    while ( 1 )
    {
      v14 = *m_pMemory;
      if ( fabs(*m_pMemory - x) > 0.1 || fabs(*(v13 - 4) - vecPoint0->y) > 0.1 || fabs(*(v13 - 3) - vecPoint0->z) > 0.1 )
      {
        v15 = vecPoint1;
      }
      else
      {
        v15 = vecPoint1;
        if ( fabs(*(v13 - 2) - vecPoint1->x) <= 0.1
          && fabs(*(v13 - 1) - vecPoint1->y) <= 0.1
          && fabs(*v13 - vecPoint1->z) <= 0.1 )
        {
          return;
        }
      }
      if ( fabs(*(v13 - 2) - x) <= 0.1
        && fabs(*(v13 - 1) - vecPoint0->y) <= 0.1
        && fabs(*v13 - vecPoint0->z) <= 0.1
        && fabs(v14 - v15->x) <= 0.1
        && fabs(*(v13 - 4) - v15->y) <= 0.1
        && fabs(*(v13 - 3) - v15->z) <= 0.1 )
      {
        return;
      }
      v46 = (vgui::ToolWindow *)((char *)v46 + 308);
      ++v10;
      v13 += 77;
      if ( v10 >= m_Size )
        break;
      m_pMemory = (float *)v46;
    }
    v8 = v45;
  }
  v16 = v8->m_aSegments.m_Size;
  p_m_Memory = &v8->m_aSegments.m_Memory;
  m_nAllocationCount = v8->m_aSegments.m_Memory.m_nAllocationCount;
  if ( v16 + 1 > m_nAllocationCount )
  {
    CUtlMemory<ShoreSegment_t,int>::Grow(this: p_m_Memory, num: v16 - m_nAllocationCount + 1);
    v7 = vecPoint0;
  }
  ++p_m_Memory[1].m_pMemory;
  v19 = p_m_Memory->m_pMemory;
  v20 = (int)p_m_Memory[1].m_pMemory - v16 - 1;
  p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
  if ( v20 > 0 )
  {
    _V_memmove(dest: &v19[v16 + 1], src: &v19[v16], count: 308 * v20);
    v7 = vecPoint0;
  }
  v21 = v16;
  v22 = v7->x;
  v23 = (float)(vecNormal->x * (float)(vecPoint1->y - v7->y)) - (float)((float)(vecPoint1->x - v7->x) * vecNormal->y);
  v24 = (int)&p_m_Memory->m_pMemory[v16];
  if ( v23 < 0.0 )
  {
    *(float *)v24 = v22;
    *(float *)(v24 + 4) = vecPoint0->y;
    *(float *)(v24 + 8) = vecPoint0->z;
    vecPoint0a = &p_m_Memory->m_pMemory[v21].m_vecPoints[1];
    vecPoint0a->x = vecPoint1->x;
    vecPoint0a->y = vecPoint1->y;
    z = vecPoint1->z;
    v26 = vecPoint0a;
  }
  else
  {
    *(Vector *)v24 = *vecPoint1;
    vecPoint1a = &p_m_Memory->m_pMemory[v21].m_vecPoints[1];
    vecPoint1a->x = vecPoint0->x;
    vecPoint1a->y = vecPoint0->y;
    z = vecPoint0->z;
    v26 = vecPoint1a;
  }
  v26->z = z;
  p_m_Memory->m_pMemory[v21].m_vecNormals[0] = *vecNormal;
  p_m_Memory->m_pMemory[v21].m_vecNormals[1] = *vecNormal;
  p_m_Memory->m_pMemory[v21].m_hDisp = hDisp;
  p_m_Memory->m_pMemory[v21].m_flWaterZ = flWaterZ;
  p_m_Memory->m_pMemory[v21].m_iStartPoint = 0;
  p_m_Memory->m_pMemory[v21].m_bTouch = false;
  p_m_Memory->m_pMemory[v21].m_bCreated = false;
  v27 = p_m_Memory->m_pMemory;
  v27[v21].m_vecCenter.x = 0.0;
  v27[v21].m_vecCenter.y = 0.0;
  v27[v21].m_vecCenter.z = 0.0;
  p_m_Memory->m_pMemory[v21].m_WorldFace.m_bAdjWinding = false;
  p_m_Memory->m_pMemory[v21].m_WaterFace.m_bAdjWinding = false;
  v28 = p_m_Memory->m_pMemory;
  v28[v21].m_WorldFace.m_vecPoints[0].x = 0.0;
  v28[v21].m_WorldFace.m_vecPoints[0].y = 0.0;
  v28[v21].m_WorldFace.m_vecPoints[0].z = 0.0;
  v29 = p_m_Memory->m_pMemory;
  v29[v21].m_WorldFace.m_vecTexCoords[0].x = 0.0;
  v29[v21].m_WorldFace.m_vecTexCoords[0].y = 0.0;
  v30 = v16;
  p_m_Memory->m_pMemory[v30].m_WorldFace.m_pFaces[0] = nullptr;
  v31 = p_m_Memory->m_pMemory;
  v31[v21].m_WaterFace.m_vecPoints[0].x = 0.0;
  v31[v21].m_WaterFace.m_vecPoints[0].y = 0.0;
  v31[v21].m_WaterFace.m_vecPoints[0].z = 0.0;
  v32 = p_m_Memory->m_pMemory;
  v32[v21].m_WaterFace.m_vecTexCoords[0].x = 0.0;
  v32[v21].m_WaterFace.m_vecTexCoords[0].y = 0.0;
  p_m_Memory->m_pMemory[v30].m_WaterFace.m_pFaces[0] = nullptr;
  v33 = p_m_Memory->m_pMemory;
  v33[v21].m_WorldFace.m_vecPoints[1].x = 0.0;
  v33[v21].m_WorldFace.m_vecPoints[1].y = 0.0;
  v33[v21].m_WorldFace.m_vecPoints[1].z = 0.0;
  v34 = p_m_Memory->m_pMemory;
  v34[v21].m_WorldFace.m_vecTexCoords[1].x = 0.0;
  v34[v21].m_WorldFace.m_vecTexCoords[1].y = 0.0;
  p_m_Memory->m_pMemory[v30].m_WorldFace.m_pFaces[1] = nullptr;
  p_x = (_DWORD *)&p_m_Memory->m_pMemory[v21].m_WaterFace.m_vecPoints[1].x;
  *p_x = 0;
  p_x[1] = 0;
  p_x[2] = 0;
  v36 = (_DWORD *)&p_m_Memory->m_pMemory[v21].m_WaterFace.m_vecTexCoords[1].x;
  *v36 = 0;
  v36[1] = 0;
  p_m_Memory->m_pMemory[v30].m_WaterFace.m_pFaces[1] = nullptr;
  v37 = p_m_Memory->m_pMemory;
  v37[v21].m_WorldFace.m_vecPoints[2].x = 0.0;
  v37[v21].m_WorldFace.m_vecPoints[2].y = 0.0;
  v37[v21].m_WorldFace.m_vecPoints[2].z = 0.0;
  v38 = p_m_Memory->m_pMemory;
  v38[v21].m_WorldFace.m_vecTexCoords[2].x = 0.0;
  v38[v21].m_WorldFace.m_vecTexCoords[2].y = 0.0;
  p_m_Memory->m_pMemory[v30].m_WorldFace.m_pFaces[2] = nullptr;
  v39 = p_m_Memory->m_pMemory;
  v39[v21].m_WaterFace.m_vecPoints[2].x = 0.0;
  v39[v21].m_WaterFace.m_vecPoints[2].y = 0.0;
  v39[v21].m_WaterFace.m_vecPoints[2].z = 0.0;
  v40 = p_m_Memory->m_pMemory;
  v40[v21].m_WaterFace.m_vecTexCoords[2].x = 0.0;
  v40[v21].m_WaterFace.m_vecTexCoords[2].y = 0.0;
  p_m_Memory->m_pMemory[v30].m_WaterFace.m_pFaces[2] = nullptr;
  v41 = p_m_Memory->m_pMemory;
  v41[v21].m_WorldFace.m_vecPoints[3].x = 0.0;
  v41[v21].m_WorldFace.m_vecPoints[3].y = 0.0;
  v41[v21].m_WorldFace.m_vecPoints[3].z = 0.0;
  v42 = p_m_Memory->m_pMemory;
  v42[v21].m_WorldFace.m_vecTexCoords[3].x = 0.0;
  v42[v21].m_WorldFace.m_vecTexCoords[3].y = 0.0;
  p_m_Memory->m_pMemory[v30].m_WorldFace.m_pFaces[3] = nullptr;
  v43 = (_DWORD *)&p_m_Memory->m_pMemory[v21].m_WaterFace.m_vecPoints[3].x;
  *v43 = 0;
  v43[1] = 0;
  v43[2] = 0;
  v44 = (_DWORD *)&p_m_Memory->m_pMemory[v21].m_WaterFace.m_vecTexCoords[3].x;
  *v44 = 0;
  v44[1] = 0;
  p_m_Memory->m_pMemory[v30].m_WaterFace.m_pFaces[3] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1002A380
// Name: private: void CDispShoreManager::BuildShorelineOverlayPoint(struct Shoreline_t __near *,int,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::BuildShorelineOverlayPoint(
        CDispShoreManager *this,
        Shoreline_t *pShoreline,
        int iSegment,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aWaterFaces)
{
  CEditDispMgr *v4; // eax
  unsigned int v6; // edi
  ShoreSegment_t *m_pMemory; // eax
  float x; // xmm0_4
  float z; // xmm5_4
  float v10; // xmm3_4
  float y; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float *v16; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  CMapFace *m_Size; // ebx
  bool (__thiscall *IsSelected)(struct CMapFace *); // eax
  CMapDisp **v33; // eax
  CMapFace *v34; // ebx
  int v35; // eax
  ShoreSegment_t *v36; // eax
  float *v37; // eax
  ShoreSegment_t *v38; // edx
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  CMapFace *v44; // ecx
  ShoreSegment_t *v45; // edx
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  int v50; // ebx
  bool v51; // zf
  ShoreSegment_t *v52; // eax
  float v53; // xmm0_4
  float v54; // xmm3_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  ShoreSegment_t *v57; // eax
  double v58; // st7
  float *v59; // eax
  float *v60; // eax
  float *v61; // eax
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm3_4
  float v65; // xmm0_4
  float v66; // xmm2_4
  int i; // ebx
  float *v68; // eax
  float v69; // xmm3_4
  float v70; // xmm1_4
  ShoreSegment_t *v71; // ecx
  int v72; // ebx
  int v73; // eax
  int v74; // eax
  ShoreFaceData_t *p_m_WaterFace; // edx
  ShoreSegment_t *v76; // ecx
  ShoreSegment_t *v77; // eax
  int *v78; // eax
  ShoreSegment_t *v79; // ecx
  int *v80; // ebx
  ShoreSegment_t *v81; // edx
  float v82; // xmm1_4
  float v83; // xmm2_4
  float *v84; // eax
  ShoreSegment_t *v85; // ecx
  ShoreSegment_t *v86; // ecx
  __int64 v87; // xmm0_8
  float v88; // edx
  double v89; // st7
  float *v90; // eax
  CMapFace *v91; // ecx
  double v92; // st7
  Vector *v93; // eax
  ShoreSegment_t *v94; // edx
  ShoreSegment_t *v95; // edx
  __int64 v96; // xmm0_8
  CMapFace *v97; // ecx
  float v98; // eax
  double v99; // st7
  ShoreSegment_t *v100; // eax
  Vector *v101; // eax
  int m_nGrowSize; // esi
  CMapDisp **v103; // eax
  float vecPoints_36; // [esp+30h] [ebp-C4h]
  float vecPoints_40; // [esp+34h] [ebp-C0h]
  float vecPoints_44; // [esp+38h] [ebp-BCh]
  Vector vecDispMin; // [esp+3Ch] [ebp-B8h] BYREF
  Vector vecDispMax; // [esp+48h] [ebp-ACh] BYREF
  Vector vecHitNormal; // [esp+54h] [ebp-A0h] BYREF
  Vector vecTmp; // [esp+60h] [ebp-94h]
  CMapDisp *pCurDisp; // [esp+6Ch] [ebp-88h]
  int nWaterFaceCount; // [esp+70h] [ebp-84h]
  Vector vecEdge0; // [esp+74h] [ebp-80h] BYREF
  Vector vecEdge1; // [esp+80h] [ebp-74h] BYREF
  Vector vecHit; // [esp+8Ch] [ebp-68h] BYREF
  Vector vecWorldMax; // [esp+98h] [ebp-5Ch] BYREF
  Vector vecEnd; // [esp+A4h] [ebp-50h] BYREF
  Vector vecStart; // [esp+B0h] [ebp-44h] BYREF
  CMapFace *pWaterFace; // [esp+BCh] [ebp-38h]
  Vector vecWorldMin; // [esp+C0h] [ebp-34h] BYREF
  int iDisp; // [esp+CCh] [ebp-28h]
  CUtlVector<CMapDisp *,CUtlMemory<CMapDisp *,int> > m_aDispList; // [esp+D0h] [ebp-24h] BYREF
  CMapFace *pHitFace; // [esp+E4h] [ebp-10h]
  int v124; // [esp+F0h] [ebp-4h]
  CMapDisp *iWaterFace; // [esp+FCh] [ebp+8h]
  int iWaterFacea; // [esp+FCh] [ebp+8h]
  int iWaterPoint; // [esp+100h] [ebp+Ch]
  int iWaterPointa; // [esp+100h] [ebp+Ch]
  int iWaterPointb; // [esp+100h] [ebp+Ch]
  Vector vecPoints; // 0:^20.12

  v4 = EditDispMgr();
  v6 = iSegment;
  iWaterFace = v4->GetDisp(this: v4, a2: pShoreline->m_aSegments.m_Memory.m_pMemory[iSegment].m_hDisp);
  if ( iWaterFace != nullptr )
  {
    pWaterFace = (CMapFace *)GetActiveWorldEditDispManager();
    if ( pWaterFace != nullptr )
    {
      m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
      x = m_pMemory[v6].m_vecPoints[1].x;
      z = m_pMemory[v6].m_vecPoints[0].z;
      v10 = pShoreline->m_ShoreData.m_flWidths[0];
      y = m_pMemory[v6].m_vecPoints[0].y;
      v12 = m_pMemory[v6].m_vecNormals[0].z;
      v13 = m_pMemory[v6].m_vecNormals[0].y;
      v14 = m_pMemory[v6].m_vecNormals[1].z;
      v15 = m_pMemory[iSegment].m_vecPoints[0].x;
      v16 = (float *)&m_pMemory[v6];
      vecPoints_36 = x;
      vecPoints_40 = v16[4];
      *(_QWORD *)&vecPoints.y = __PAIR64__(LODWORD(z), LODWORD(y));
      vecPoints_44 = v16[5];
      v17 = (float)(v12 * v10) + z;
      v18 = (float)(v13 * v10) + y;
      v19 = v16[10] * v10;
      v20 = v14 * v10;
      v21 = v16[6] * v10;
      v22 = vecPoints_36 + (float)(v10 * v16[9]);
      v23 = vecPoints_40 + v19;
      vecPoints.x = v15;
      v24 = v21 + v15;
      v25 = vecPoints_44 + v20;
      vecWorldMin = vecPoints;
      vecWorldMax = vecPoints;
      if ( v15 > v24 )
        vecWorldMin.x = v24;
      if ( v24 > v15 )
        vecWorldMax.x = v24;
      if ( vecWorldMin.y > v18 )
        vecWorldMin.y = v18;
      v26 = vecWorldMax.y;
      if ( v18 > vecWorldMax.y )
        v26 = v18;
      v27 = vecWorldMin.z;
      if ( vecWorldMin.z > v17 )
        v27 = v17;
      v28 = vecWorldMax.z;
      if ( v17 > vecWorldMax.z )
        v28 = v17;
      if ( vecWorldMin.x > v22 )
        vecWorldMin.x = v22;
      v29 = vecWorldMax.x;
      if ( v22 > vecWorldMax.x )
      {
        vecWorldMax.x = v22;
        v29 = v22;
      }
      v30 = vecWorldMin.y;
      if ( vecWorldMin.y > v23 )
      {
        vecWorldMin.y = v23;
        v30 = v23;
      }
      if ( v23 > v26 )
        v26 = v23;
      if ( v27 > v25 )
        v27 = v25;
      if ( v25 > v28 )
        v28 = v25;
      if ( vecWorldMin.x > vecPoints_36 )
        vecWorldMin.x = vecPoints_36;
      if ( vecPoints_36 > v29 )
      {
        vecWorldMax.x = vecPoints_36;
        v29 = vecPoints_36;
      }
      if ( v30 > vecPoints_40 )
      {
        vecWorldMin.y = vecPoints_40;
        v30 = vecPoints_40;
      }
      if ( vecPoints_40 > v26 )
        v26 = vecPoints_40;
      if ( v27 > vecPoints_44 )
        v27 = vecPoints_44;
      if ( vecPoints_44 > v28 )
        v28 = vecPoints_44;
      m_Size = nullptr;
      vecWorldMin.x = vecWorldMin.x - 1.0;
      vecWorldMax.x = v29 + 1.0;
      vecWorldMin.y = v30 - 1.0;
      vecWorldMax.y = v26 + 1.0;
      vecWorldMin.z = v27 - 150.0;
      vecWorldMax.z = v28 + 150.0;
      memset(&m_aDispList, 0, sizeof(m_aDispList));
      v124 = 1;
      IsSelected = pWaterFace->IsSelected;
      m_aDispList.m_Memory.m_nAllocationCount = 0;
      m_aDispList.m_pElements = nullptr;
      nWaterFaceCount = ((int (__thiscall *)(CMapFace *))IsSelected)(a1: pWaterFace);
      for ( iDisp = 0; iDisp < nWaterFaceCount; ++iDisp )
      {
        pCurDisp = (CMapDisp *)pWaterFace->SetSelectionState(this: pWaterFace, a2: (SelectionState_t)iDisp);
        if ( pCurDisp != nullptr && pCurDisp != iWaterFace )
        {
          vecDispMin.x = pCurDisp->m_BBox[0].x;
          vecDispMin.y = pCurDisp->m_BBox[0].y;
          vecDispMin.z = pCurDisp->m_BBox[0].z;
          vecDispMax = pCurDisp->m_BBox[1];
          if ( IsBoxIntersectingBox(
                 boxMin1: &vecWorldMin,
                 boxMax1: &vecWorldMax,
                 boxMin2: &vecDispMin,
                 boxMax2: &vecDispMax) )
          {
            pHitFace = m_Size;
            if ( (int)&m_Size->__vftable + 1 > m_aDispList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CVisGroup *,int>::Grow(
                this: (CUtlMemory<CCullTreeNode *,int> *)&m_aDispList,
                num: (int)&m_Size->__vftable - m_aDispList.m_Memory.m_nAllocationCount + 1);
              m_Size = (CMapFace *)m_aDispList.m_Size;
            }
            m_Size = (CMapFace *)((char *)m_Size + 1);
            m_aDispList.m_Size = (int)m_Size;
            m_aDispList.m_pElements = m_aDispList.m_Memory.m_pMemory;
            if ( (char *)m_Size - (char *)pHitFace - 1 > 0 )
              _V_memmove(
                dest: &m_aDispList.m_Memory.m_pMemory[(_DWORD)pHitFace + 1],
                src: &m_aDispList.m_Memory.m_pMemory[(_DWORD)pHitFace],
                count: 4 * ((char *)m_Size - (char *)pHitFace - 1));
            v33 = &m_aDispList.m_Memory.m_pMemory[(_DWORD)pHitFace];
            if ( v33 != nullptr )
              *v33 = pCurDisp;
          }
        }
      }
      v34 = (CMapFace *)iWaterFace->GetParent(this: iWaterFace);
      v35 = iSegment;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v35].m_WorldFace.m_pFaces[0] = v34;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v35].m_WorldFace.m_pFaces[1] = v34;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v35].m_WorldFace.m_pFaces[2] = v34;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v35].m_WorldFace.m_pFaces[3] = v34;
      iDisp = 77 * iSegment;
      v36 = &pShoreline->m_aSegments.m_Memory.m_pMemory[v6];
      pHitFace = v34;
      v36->m_WorldFace.m_vecPoints[0].x = v36->m_vecPoints[0].x;
      v36->m_WorldFace.m_vecPoints[0].y = v36->m_vecPoints[0].y;
      v36->m_WorldFace.m_vecPoints[0].z = v36->m_vecPoints[0].z;
      v37 = (float *)&pShoreline->m_aSegments.m_Memory.m_pMemory[v6];
      v37[35] = v37[3];
      v37[36] = v37[4];
      v37[37] = v37[5];
      v38 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      v39 = pShoreline->m_ShoreData.m_flWidths[0];
      v40 = (float)(v38[v6].m_vecNormals[0].x * v39) + v38[v6].m_WorldFace.m_vecPoints[0].x;
      v41 = v38[v6].m_vecNormals[0].z * v39;
      v42 = v38[v6].m_WorldFace.m_vecPoints[0].y + (float)(v38[v6].m_vecNormals[0].y * v39);
      v43 = v38[v6].m_WorldFace.m_vecPoints[0].z + v41;
      vecStart.x = v40;
      vecStart.y = v42;
      vecStart.z = v43 + 150.0;
      vecEnd.x = v40;
      vecEnd.y = v42;
      vecEnd.z = v43 - 150.0;
      if ( !CMapDisp::TraceLine(
              this: iWaterFace,
              vecHitPos: &vecHit,
              &vecHitNormal,
              vecRayStart: &vecStart,
              vecRayEnd: &vecEnd) )
      {
        iWaterPoint = 0;
        if ( m_aDispList.m_Size > 0 )
        {
          while ( !CMapDisp::TraceLine(
                     this: m_aDispList.m_Memory.m_pMemory[iWaterPoint],
                     vecHitPos: &vecHit,
                     &vecHitNormal,
                     vecRayStart: &vecStart,
                     vecRayEnd: &vecEnd) )
          {
            if ( ++iWaterPoint >= m_aDispList.m_Size )
              goto LABEL_56;
          }
          pHitFace = (CMapFace *)m_aDispList.m_Memory.m_pMemory[iWaterPoint]->GetParent(this: m_aDispList.m_Memory.m_pMemory[iWaterPoint]);
        }
LABEL_56:
        if ( iWaterPoint == m_aDispList.m_Size )
          CMapDisp::TraceLineSnapTo(
            this: iWaterFace,
            HitPos: &vecHit,
            HitNormal: &vecHitNormal,
            RayStart: &vecStart,
            RayEnd: &vecEnd);
      }
      v44 = pHitFace;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_vecPoints[1] = vecHit;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_pFaces[1] = v44;
      v45 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      v46 = pShoreline->m_ShoreData.m_flWidths[0];
      v47 = v45[v6].m_vecNormals[1].z * v46;
      v48 = v45[v6].m_WorldFace.m_vecPoints[3].y + (float)(v45[v6].m_vecNormals[1].y * v46);
      v49 = v45[v6].m_WorldFace.m_vecPoints[3].z + v47;
      vecStart.x = (float)(pShoreline->m_ShoreData.m_flWidths[0] * v45[v6].m_vecNormals[1].x)
                 + v45[v6].m_WorldFace.m_vecPoints[3].x;
      vecStart.y = v48;
      vecStart.z = v49 + 150.0;
      vecEnd.x = vecStart.x;
      vecEnd.y = v48;
      vecEnd.z = v49 - 150.0;
      pHitFace = v34;
      if ( !CMapDisp::TraceLine(
              this: iWaterFace,
              vecHitPos: &vecHit,
              &vecHitNormal,
              vecRayStart: &vecStart,
              vecRayEnd: &vecEnd) )
      {
        v50 = 0;
        v51 = m_aDispList.m_Size == 0;
        if ( m_aDispList.m_Size > 0 )
        {
          while ( !CMapDisp::TraceLine(
                     this: m_aDispList.m_Memory.m_pMemory[v50],
                     vecHitPos: &vecHit,
                     &vecHitNormal,
                     vecRayStart: &vecStart,
                     vecRayEnd: &vecEnd) )
          {
            if ( ++v50 >= m_aDispList.m_Size )
              goto LABEL_64;
          }
          pHitFace = (CMapFace *)m_aDispList.m_Memory.m_pMemory[v50]->GetParent(this: m_aDispList.m_Memory.m_pMemory[v50]);
LABEL_64:
          v51 = v50 == m_aDispList.m_Size;
        }
        if ( v51 )
          CMapDisp::TraceLineSnapTo(
            this: iWaterFace,
            HitPos: &vecHit,
            HitNormal: &vecHitNormal,
            RayStart: &vecStart,
            RayEnd: &vecEnd);
      }
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_vecPoints[2] = vecHit;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_pFaces[2] = pHitFace;
      v52 = &pShoreline->m_aSegments.m_Memory.m_pMemory[v6];
      v53 = -pShoreline->m_ShoreData.m_flWidths[1];
      v54 = v52->m_vecNormals[0].z * v53;
      v55 = v52->m_vecPoints[0].y + (float)(v52->m_vecNormals[0].y * v53);
      v56 = v52->m_vecPoints[0].z;
      v52->m_WaterFace.m_vecPoints[0].x = v52->m_vecPoints[0].x + (float)(v53 * v52->m_vecNormals[0].x);
      v52->m_WaterFace.m_vecPoints[0].y = v55;
      v52->m_WaterFace.m_vecPoints[0].z = v56 + v54;
      v57 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      v58 = v57[v6].m_vecPoints[0].x;
      v59 = (float *)&v57[v6];
      v59[54] = v58;
      iWaterFacea = 0;
      v59[55] = v59[1];
      v59[56] = v59[2];
      v60 = (float *)&pShoreline->m_aSegments.m_Memory.m_pMemory[v6];
      v60[57] = v60[3];
      v60[58] = v60[4];
      v60[59] = v60[5];
      v61 = (float *)&pShoreline->m_aSegments.m_Memory.m_pMemory[v6];
      v62 = -pShoreline->m_ShoreData.m_flWidths[1];
      v63 = (float)(v61[9] * v62) + v61[3];
      v64 = v61[11] * v62;
      v65 = v61[4] + (float)(v61[10] * v62);
      v66 = v61[5] + v64;
      v61[60] = v63;
      v61[61] = v65;
      v61[62] = v66;
      nWaterFaceCount = aWaterFaces->m_Size;
      if ( nWaterFaceCount > 0 )
      {
        do
        {
          pWaterFace = aWaterFaces->m_Memory.m_pMemory[iWaterFacea];
          if ( pWaterFace != nullptr )
          {
            iWaterPointa = 0;
            for ( i = 204; i < 252; i += 12 )
            {
              v68 = (float *)((char *)pShoreline->m_aSegments.m_Memory.m_pMemory + i + v6 * 308);
              v69 = v68[1];
              v70 = v68[2];
              vecStart.x = *v68;
              vecStart.y = v69;
              vecStart.z = v70 + 150.0;
              vecEnd.x = vecStart.x;
              vecEnd.y = v69;
              vecEnd.z = v70 - 150.0;
              if ( CMapFace::TraceLineInside(
                     this: pWaterFace,
                     HitPos: &vecHit,
                     HitNormal: &vecHitNormal,
                     Start: &vecStart,
                     End: &vecEnd,
                     bNoDisp: false) )
              {
                *((_DWORD *)&pShoreline->m_aSegments.m_Memory.m_pMemory->m_WaterFace.m_pFaces[iWaterPointa] + iDisp) = pWaterFace;
              }
              ++iWaterPointa;
            }
          }
          ++iWaterFacea;
        }
        while ( iWaterFacea < nWaterFaceCount );
      }
      v71 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      v72 = iDisp;
      v73 = v71->m_WaterFace.m_pFaces[iDisp] == nullptr;
      if ( v71->m_WaterFace.m_pFaces[iDisp + 1] == nullptr )
        ++v73;
      if ( v71->m_WaterFace.m_pFaces[iDisp + 2] == nullptr )
        ++v73;
      if ( v71->m_WaterFace.m_pFaces[iDisp + 3] == nullptr )
        ++v73;
      if ( (unsigned int)(v73 - 1) <= 2 )
      {
        v74 = 0;
        iWaterPointb = 0;
        p_m_WaterFace = &v71[v6].m_WaterFace;
        while ( p_m_WaterFace->m_pFaces[0] == nullptr )
        {
          ++v74;
          p_m_WaterFace = (ShoreFaceData_t *)((char *)p_m_WaterFace + 4);
          if ( v74 >= 4 )
            goto LABEL_86;
        }
        iWaterPointb = *((_DWORD *)&v71->m_WaterFace.m_pFaces[iDisp] + v74);
LABEL_86:
        if ( v71->m_WaterFace.m_pFaces[iDisp] == nullptr )
          v71->m_WaterFace.m_pFaces[iDisp] = (CMapFace *)iWaterPointb;
        v76 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        if ( v76->m_WaterFace.m_pFaces[v72 + 1] == nullptr )
          v76->m_WaterFace.m_pFaces[v72 + 1] = (CMapFace *)iWaterPointb;
        v77 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        v51 = v77->m_WaterFace.m_pFaces[v72 + 2] == nullptr;
        v78 = (int *)&v77->m_WaterFace.m_pFaces[v72 + 2];
        if ( v51 )
          *v78 = iWaterPointb;
        v79 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        v51 = v79->m_WaterFace.m_pFaces[v72 + 3] == nullptr;
        v80 = (int *)&v79->m_WaterFace.m_pFaces[v72 + 3];
        if ( v51 )
          *v80 = iWaterPointb;
      }
      v81 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      v82 = v81[v6].m_vecPoints[1].y + v81[v6].m_vecPoints[0].y;
      v83 = v81[v6].m_vecPoints[1].z + v81[v6].m_vecPoints[0].z;
      v84 = (float *)&v81[v6];
      v84[72] = (float)(v81[v6].m_vecPoints[1].x + v81[v6].m_vecPoints[0].x) * 0.5;
      v84[73] = v82 * 0.5;
      v84[74] = v83 * 0.5;
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_bAdjWinding = false;
      v85 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      vecEdge0.x = v85[v6].m_WorldFace.m_vecPoints[1].x - v85[v6].m_WorldFace.m_vecPoints[0].x;
      vecEdge0.y = v85[v6].m_WorldFace.m_vecPoints[1].y - v85[v6].m_WorldFace.m_vecPoints[0].y;
      vecEdge0.z = v85[v6].m_WorldFace.m_vecPoints[1].z - v85[v6].m_WorldFace.m_vecPoints[0].z;
      vecEdge1.x = v85[v6].m_WorldFace.m_vecPoints[2].x - v85[v6].m_WorldFace.m_vecPoints[0].x;
      vecEdge1.y = v85[v6].m_WorldFace.m_vecPoints[2].y - v85[v6].m_WorldFace.m_vecPoints[0].y;
      vecEdge1.z = v85[v6].m_WorldFace.m_vecPoints[2].z - v85[v6].m_WorldFace.m_vecPoints[0].z;
      VectorNormalize(vec: &vecEdge0);
      VectorNormalize(vec: &vecEdge1);
      if ( (float)((float)(vecEdge0.y * vecEdge1.x) - (float)(vecEdge1.y * vecEdge0.x)) < 0.0 )
      {
        v86 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        v87 = *(_QWORD *)&v86[v6].m_WorldFace.m_vecPoints[1].x;
        v88 = v86[v6].m_WorldFace.m_vecPoints[1].z;
        v86[v6].m_WorldFace.m_vecPoints[1].x = v86[v6].m_WorldFace.m_vecPoints[3].x;
        v89 = v86[v6].m_WorldFace.m_vecPoints[3].y;
        v90 = (float *)&v86[v6];
        v91 = v86[v6].m_WorldFace.m_pFaces[1];
        v90[30] = v89;
        v92 = v90[37];
        vecTmp.z = v88;
        v90[31] = v92;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_pFaces[1] = pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_pFaces[3];
        v93 = &pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_vecPoints[3];
        *(_QWORD *)&vecTmp.x = v87;
        LODWORD(v93->x) = v87;
        v93->y = vecTmp.y;
        v93->z = vecTmp.z;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_pFaces[3] = v91;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WorldFace.m_bAdjWinding = true;
      }
      pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_bAdjWinding = false;
      v94 = pShoreline->m_aSegments.m_Memory.m_pMemory;
      vecEdge0.x = v94[v6].m_WaterFace.m_vecPoints[1].x - v94[v6].m_WaterFace.m_vecPoints[0].x;
      vecEdge0.y = v94[v6].m_WaterFace.m_vecPoints[1].y - v94[v6].m_WaterFace.m_vecPoints[0].y;
      vecEdge0.z = v94[v6].m_WaterFace.m_vecPoints[1].z - v94[v6].m_WaterFace.m_vecPoints[0].z;
      vecEdge1.x = v94[v6].m_WaterFace.m_vecPoints[2].x - v94[v6].m_WaterFace.m_vecPoints[0].x;
      vecEdge1.y = v94[v6].m_WaterFace.m_vecPoints[2].y - v94[v6].m_WaterFace.m_vecPoints[0].y;
      vecEdge1.z = v94[v6].m_WaterFace.m_vecPoints[2].z - v94[v6].m_WaterFace.m_vecPoints[0].z;
      VectorNormalize(vec: &vecEdge0);
      VectorNormalize(vec: &vecEdge1);
      if ( (float)((float)(vecEdge0.y * vecEdge1.x) - (float)(vecEdge1.y * vecEdge0.x)) < 0.0 )
      {
        v95 = pShoreline->m_aSegments.m_Memory.m_pMemory;
        v96 = *(_QWORD *)&v95[v6].m_WaterFace.m_vecPoints[1].x;
        v97 = v95[v6].m_WaterFace.m_pFaces[1];
        v98 = v95[v6].m_WaterFace.m_vecPoints[1].z;
        v95[v6].m_WaterFace.m_vecPoints[1].x = v95[v6].m_WaterFace.m_vecPoints[3].x;
        v99 = v95[v6].m_WaterFace.m_vecPoints[3].y;
        vecTmp.z = v98;
        v100 = &v95[v6];
        v100->m_WaterFace.m_vecPoints[1].y = v99;
        *(_QWORD *)&vecTmp.x = v96;
        v100->m_WaterFace.m_vecPoints[1].z = v95[v6].m_WaterFace.m_vecPoints[3].z;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_pFaces[1] = pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_pFaces[3];
        v101 = &pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_vecPoints[3];
        LODWORD(v101->x) = v96;
        v101->y = vecTmp.y;
        v101->z = vecTmp.z;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_pFaces[3] = v97;
        pShoreline->m_aSegments.m_Memory.m_pMemory[v6].m_WaterFace.m_bAdjWinding = true;
      }
      v124 = 2;
      m_nGrowSize = m_aDispList.m_Memory.m_nGrowSize;
      v103 = m_aDispList.m_Memory.m_pMemory;
      m_aDispList.m_Size = 0;
      if ( m_aDispList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_aDispList.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: m_aDispList.m_Memory.m_pMemory);
          v103 = nullptr;
          m_aDispList.m_Memory.m_pMemory = nullptr;
        }
        m_aDispList.m_Memory.m_nAllocationCount = 0;
      }
      m_aDispList.m_pElements = v103;
      v124 = -1;
      if ( m_nGrowSize >= 0 && v103 != nullptr )
        free(pMem: v103);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B060
// Name: private: int CDispShoreManager::FindShorelineStart(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispShoreManager::FindShorelineStart(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  int v2; // ecx
  int v3; // esi
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // eax
  ShoreSegment_t *m_pMemory; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // edi
  int nSegmentCount; // [esp+Ch] [ebp-Ch]
  int iSegment2; // [esp+10h] [ebp-8h]
  int iSegment; // [esp+14h] [ebp-4h]

  v2 = 0;
  nSegmentCount = pShoreline->m_aSegments.m_Size;
  iSegment = 0;
  if ( nSegmentCount <= 0 )
    return -1;
  while ( 1 )
  {
    v3 = 0;
    v4 = 0;
    v5 = -1;
    iSegment2 = 0;
    v6 = 0;
    do
    {
      if ( iSegment != v3 )
      {
        m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
        if ( fabs(m_pMemory[v2].m_vecPoints[0].x - m_pMemory[v6].m_vecPoints[0].x) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[0].y - m_pMemory[v6].m_vecPoints[0].y) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[0].z - m_pMemory[v6].m_vecPoints[0].z) <= 0.1 )
        {
          ++v4;
          v5 = 1;
        }
        if ( fabs(m_pMemory[v2].m_vecPoints[0].x - m_pMemory[v6].m_vecPoints[1].x) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[0].y - m_pMemory[v6].m_vecPoints[1].y) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[0].z - m_pMemory[v6].m_vecPoints[1].z) <= 0.1 )
        {
          ++v4;
          v5 = 1;
        }
        if ( fabs(m_pMemory[v2].m_vecPoints[1].x - m_pMemory[v6].m_vecPoints[0].x) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[1].y - m_pMemory[v6].m_vecPoints[0].y) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[1].z - m_pMemory[v6].m_vecPoints[0].z) <= 0.1 )
        {
          ++v4;
          v5 = 0;
        }
        if ( fabs(m_pMemory[v2].m_vecPoints[1].x - m_pMemory[v6].m_vecPoints[1].x) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[1].y - m_pMemory[v6].m_vecPoints[1].y) <= 0.1
          && fabs(m_pMemory[v2].m_vecPoints[1].z - m_pMemory[v6].m_vecPoints[1].z) <= 0.1 )
        {
          ++v4;
          v5 = 0;
        }
      }
      v3 = iSegment2 + 1;
      ++v6;
      iSegment2 = v3;
    }
    while ( v3 < nSegmentCount );
    if ( v4 == 1 )
      break;
    ++v2;
    if ( ++iSegment >= nSegmentCount )
      return -1;
  }
  pShoreline->m_aSegments.m_Memory.m_pMemory[iSegment].m_iStartPoint = v5;
  m_Size = pShoreline->m_aSortedSegments.m_Size;
  m_nAllocationCount = pShoreline->m_aSortedSegments.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&pShoreline->m_aSortedSegments,
      num: m_Size - m_nAllocationCount + 1);
  ++pShoreline->m_aSortedSegments.m_Size;
  v11 = pShoreline->m_aSortedSegments.m_Memory.m_pMemory;
  v12 = pShoreline->m_aSortedSegments.m_Size - m_Size - 1;
  pShoreline->m_aSortedSegments.m_pElements = v11;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
  v13 = &pShoreline->m_aSortedSegments.m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = iSegment;
  pShoreline->m_aSegments.m_Memory.m_pMemory[iSegment].m_bTouch = true;
  return iSegment;
}

//------------------------------------------------------------------------------
// Address: 0x1002B270
// Name: private: void CDispShoreManager::CreateOverlays(struct Shoreline_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::CreateOverlays(CDispShoreManager *this, Shoreline_t *pShoreline, int iSegment)
{
  int m_Size; // ebx
  int v4; // edi
  vgui::ToolWindow *v5; // eax
  ShoreSegment_t *m_pMemory; // edx
  int v7; // eax
  int v8; // esi
  CMapFace **v9; // ecx
  CMapFace **v10; // eax
  int v11; // eax
  CMapFace **v12; // ebx
  int v13; // esi
  CMapFace **v14; // ecx
  CMapFace **v15; // eax
  int v16; // eax
  CMapFace **v17; // edi
  CMapOverlay *v18; // esi
  int i; // edi
  int v20; // edi
  IEditorTexture *m_pTexture; // eax
  int v22; // edi
  CMapFace **v23; // eax
  int v24; // edi
  CMapFace **v25; // eax
  int v26; // esi
  int m_nAllocationCount; // eax
  CMapOverlay *v28; // ecx
  int v29; // eax
  CMapOverlay *v30; // ecx
  unsigned int v31; // esi
  bool v32; // zf
  vgui::ToolWindow *v33; // ecx
  CMapOverlay *v34; // esi
  CMapFace **v35; // ebx
  int j; // ebx
  IEditorTexture *v38; // eax
  void (__thiscall *CalcBounds)(CMapClass *, int); // eax
  int m_nGrowSize; // esi
  int v41; // esi
  CMapFace **v42; // eax
  CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > aWaterFaces; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > aWorldFaces; // [esp+20h] [ebp-34h] BYREF
  int v45; // [esp+34h] [ebp-20h]
  vgui::ToolWindow *v46; // [esp+38h] [ebp-1Ch]
  ShoreSegment_t *v47; // [esp+3Ch] [ebp-18h]
  int iFace; // [esp+40h] [ebp-14h]
  int v49; // [esp+44h] [ebp-10h]
  int v50; // [esp+50h] [ebp-4h]

  memset(&aWorldFaces, 0, sizeof(aWorldFaces));
  m_Size = 0;
  v50 = 3;
  memset(&aWaterFaces, 0, sizeof(aWaterFaces));
  v4 = 0;
  v5 = (vgui::ToolWindow *)(77 * iSegment);
  iFace = 0;
  v46 = (vgui::ToolWindow *)(77 * iSegment);
  v49 = 308 * iSegment + 88;
  while ( 1 )
  {
    m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
    v47 = m_pMemory;
    if ( *(_DWORD *)((char *)&m_pMemory->m_vecPoints[0].x + v49) == 0 )
      break;
    v45 = 4 * ((_DWORD)v5 + iFace) + 188;
    if ( *(_DWORD *)((char *)&m_pMemory->m_vecPoints[0].x + v45) == 0 )
      break;
    v7 = 0;
    if ( m_Size <= 0 )
      goto LABEL_10;
    while ( aWorldFaces.m_Memory.m_pMemory[v7] != *(CMapFace **)((char *)&m_pMemory->m_vecPoints[0].x + v49) )
    {
      if ( ++v7 >= m_Size )
        goto LABEL_10;
    }
    if ( v7 == -1 )
    {
LABEL_10:
      v8 = m_Size;
      if ( m_Size + 1 > aWorldFaces.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&aWorldFaces,
          num: m_Size - aWorldFaces.m_Memory.m_nAllocationCount + 1);
        m_Size = aWorldFaces.m_Size;
        m_pMemory = v47;
      }
      aWorldFaces.m_Size = ++m_Size;
      v9 = aWorldFaces.m_Memory.m_pMemory;
      aWorldFaces.m_pElements = aWorldFaces.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &aWorldFaces.m_Memory.m_pMemory[v8 + 1],
          src: &aWorldFaces.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        v9 = aWorldFaces.m_Memory.m_pMemory;
        m_pMemory = v47;
      }
      v10 = &v9[v8];
      if ( v10 != nullptr )
        *v10 = *(CMapFace **)((char *)&m_pMemory->m_vecPoints[0].x + v49);
    }
    v11 = 0;
    if ( v4 <= 0 )
      goto LABEL_21;
    while ( aWaterFaces.m_Memory.m_pMemory[v11] != *(CMapFace **)((char *)&pShoreline->m_aSegments.m_Memory.m_pMemory->m_WorldFace.m_pFaces[3]
                                                                + v49) )
    {
      if ( ++v11 >= v4 )
        goto LABEL_21;
    }
    if ( v11 == -1 )
    {
LABEL_21:
      v12 = (CMapFace **)((char *)pShoreline->m_aSegments.m_Memory.m_pMemory + v45);
      v13 = v4;
      if ( v4 + 1 > aWaterFaces.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&aWaterFaces,
          num: v4 - aWaterFaces.m_Memory.m_nAllocationCount + 1);
        v4 = aWaterFaces.m_Size;
      }
      aWaterFaces.m_Size = ++v4;
      v14 = aWaterFaces.m_Memory.m_pMemory;
      aWaterFaces.m_pElements = aWaterFaces.m_Memory.m_pMemory;
      if ( v4 - v13 - 1 > 0 )
      {
        _V_memmove(
          dest: &aWaterFaces.m_Memory.m_pMemory[v13 + 1],
          src: &aWaterFaces.m_Memory.m_pMemory[v13],
          count: 4 * (v4 - v13 - 1));
        v14 = aWaterFaces.m_Memory.m_pMemory;
      }
      v15 = &v14[v13];
      if ( v15 != nullptr )
        *v15 = *v12;
      m_Size = aWorldFaces.m_Size;
    }
    v49 += 4;
    if ( ++iFace >= 4 )
    {
      v16 = CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::InsertBefore(
              this: &pShoreline->m_aOverlays,
              elem: pShoreline->m_aOverlays.m_Size);
      v17 = aWorldFaces.m_Memory.m_pMemory;
      v18 = &pShoreline->m_aOverlays.m_Memory.m_pMemory[v16];
      v18->m_uiFlags |= 2u;
      CMapOverlay::Basis_Init(this: v18, pFace: *v17);
      CMapOverlay::Handles_Init(this: v18, pFace: *v17);
      CMapOverlay::SideList_Init(this: v18, pFace: *v17);
      for ( i = 1; i < aWorldFaces.m_Size; ++i )
        CMapOverlay::SideList_AddFace(this: v18, pFace: aWorldFaces.m_Memory.m_pMemory[i]);
      v20 = iSegment;
      v18->m_bLoaded = true;
      CMapOverlay::HandleMoveTo(
        this: v18,
        iHandle: 0,
        vecPoint: pShoreline->m_aSegments.m_Memory.m_pMemory[iSegment].m_WorldFace.m_vecPoints,
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[iSegment].m_WorldFace.m_pFaces[0]);
      CMapOverlay::HandleMoveTo(
        this: v18,
        iHandle: 1,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_vecPoints[1],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_pFaces[1]);
      CMapOverlay::HandleMoveTo(
        this: v18,
        iHandle: 2,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_vecPoints[2],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_pFaces[2]);
      CMapOverlay::HandleMoveTo(
        this: v18,
        iHandle: 3,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_vecPoints[3],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_pFaces[3]);
      m_pTexture = pShoreline->m_ShoreData.m_pTexture;
      if ( m_pTexture != nullptr )
        v18->m_Material.m_pTexture = m_pTexture;
      else
        CMapOverlay::SetMaterial(this: v18, szMaterialName: "decals/decal_signroute004b");
      CMapOverlay::SetTexCoords(
        this: v18,
        vecTexCoords: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WorldFace.m_vecTexCoords);
      v18->CalcBounds(this: v18, a2: 1);
      CMapOverlay::DoClip(this: v18);
      v18->PostUpdate(this: v18, a2: Notify_Changed);
      v26 = pShoreline->m_aOverlays.m_Size;
      m_nAllocationCount = pShoreline->m_aOverlays.m_Memory.m_nAllocationCount;
      if ( v26 + 1 > m_nAllocationCount )
        CUtlMemory<CMapOverlay,int>::Grow(this: &pShoreline->m_aOverlays.m_Memory, num: v26 - m_nAllocationCount + 1);
      ++pShoreline->m_aOverlays.m_Size;
      v28 = pShoreline->m_aOverlays.m_Memory.m_pMemory;
      v29 = pShoreline->m_aOverlays.m_Size - v26 - 1;
      pShoreline->m_aOverlays.m_pElements = v28;
      if ( v29 > 0 )
        _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 532 * v29);
      v30 = pShoreline->m_aOverlays.m_Memory.m_pMemory;
      v31 = v26;
      v32 = &v30[v31] == nullptr;
      v33 = (vgui::ToolWindow *)&v30[v31];
      v45 = (int)v33;
      v46 = v33;
      LOBYTE(v50) = 6;
      if ( !v32 )
        CMapOverlay::CMapOverlay(this: (CMapOverlay *)v33);
      LOBYTE(v50) = 3;
      v34 = &pShoreline->m_aOverlays.m_Memory.m_pMemory[v31];
      v35 = aWaterFaces.m_Memory.m_pMemory;
      v34->m_uiFlags |= 2u;
      CMapOverlay::Basis_Init(this: v34, pFace: *v35);
      CMapOverlay::Handles_Init(this: v34, pFace: *v35);
      CMapOverlay::SideList_Init(this: v34, pFace: *v35);
      for ( j = 1; j < aWaterFaces.m_Size; ++j )
        CMapOverlay::SideList_AddFace(this: v34, pFace: aWaterFaces.m_Memory.m_pMemory[j]);
      v34->m_bLoaded = true;
      CMapOverlay::HandleMoveTo(
        this: v34,
        iHandle: 0,
        vecPoint: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_vecPoints,
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_pFaces[0]);
      CMapOverlay::HandleMoveTo(
        this: v34,
        iHandle: 1,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_vecPoints[1],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_pFaces[1]);
      CMapOverlay::HandleMoveTo(
        this: v34,
        iHandle: 2,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_vecPoints[2],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_pFaces[2]);
      CMapOverlay::HandleMoveTo(
        this: v34,
        iHandle: 3,
        vecPoint: &pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_vecPoints[3],
        pFace: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_pFaces[3]);
      v38 = pShoreline->m_ShoreData.m_pTexture;
      if ( v38 != nullptr )
        v34->m_Material.m_pTexture = v38;
      else
        CMapOverlay::SetMaterial(this: v34, szMaterialName: "decals/decal_signroute004b");
      CMapOverlay::SetTexCoords(
        this: v34,
        vecTexCoords: pShoreline->m_aSegments.m_Memory.m_pMemory[v20].m_WaterFace.m_vecTexCoords);
      CalcBounds = v34->CalcBounds;
      v34->m_uiFlags |= 2u;
      CalcBounds(this: v34, a2: 1);
      CMapOverlay::DoClip(this: v34);
      v34->PostUpdate(this: v34, a2: Notify_Changed);
      LOBYTE(v50) = 7;
      m_nGrowSize = aWaterFaces.m_Memory.m_nGrowSize;
      aWaterFaces.m_Size = 0;
      if ( aWaterFaces.m_Memory.m_nGrowSize >= 0 )
      {
        free(pMem: aWaterFaces.m_Memory.m_pMemory);
        aWaterFaces.m_Memory.m_pMemory = nullptr;
        aWaterFaces.m_Memory.m_nAllocationCount = 0;
      }
      aWaterFaces.m_pElements = aWaterFaces.m_Memory.m_pMemory;
      LOBYTE(v50) = 1;
      if ( m_nGrowSize >= 0 )
      {
        if ( aWaterFaces.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: aWaterFaces.m_Memory.m_pMemory);
          aWaterFaces.m_Memory.m_pMemory = nullptr;
        }
        aWaterFaces.m_Memory.m_nAllocationCount = 0;
      }
      v50 = 8;
      v41 = aWorldFaces.m_Memory.m_nGrowSize;
      aWorldFaces.m_Size = 0;
      if ( aWorldFaces.m_Memory.m_nGrowSize < 0 )
      {
        v42 = aWorldFaces.m_Memory.m_pMemory;
      }
      else
      {
        free(pMem: aWorldFaces.m_Memory.m_pMemory);
        v42 = nullptr;
        aWorldFaces.m_Memory.m_pMemory = nullptr;
        aWorldFaces.m_Memory.m_nAllocationCount = 0;
      }
      aWorldFaces.m_pElements = v42;
      v50 = -1;
      if ( v41 >= 0 && v42 != nullptr )
        free(pMem: v42);
      return;
    }
    v5 = v46;
  }
  LOBYTE(v50) = 4;
  v22 = aWaterFaces.m_Memory.m_nGrowSize;
  v23 = aWaterFaces.m_Memory.m_pMemory;
  aWaterFaces.m_Size = 0;
  if ( aWaterFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( aWaterFaces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: aWaterFaces.m_Memory.m_pMemory);
      aWaterFaces.m_Memory.m_pMemory = nullptr;
      v23 = nullptr;
    }
    aWaterFaces.m_Memory.m_nAllocationCount = 0;
  }
  aWaterFaces.m_pElements = v23;
  LOBYTE(v50) = 1;
  if ( v22 >= 0 )
  {
    if ( v23 != nullptr )
    {
      free(pMem: v23);
      aWaterFaces.m_Memory.m_pMemory = nullptr;
    }
    aWaterFaces.m_Memory.m_nAllocationCount = 0;
  }
  v50 = 5;
  v24 = aWorldFaces.m_Memory.m_nGrowSize;
  v25 = aWorldFaces.m_Memory.m_pMemory;
  aWorldFaces.m_Size = 0;
  if ( aWorldFaces.m_Memory.m_nGrowSize >= 0 )
  {
    if ( aWorldFaces.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: aWorldFaces.m_Memory.m_pMemory);
      aWorldFaces.m_Memory.m_pMemory = nullptr;
      v25 = nullptr;
    }
    aWorldFaces.m_Memory.m_nAllocationCount = 0;
  }
  aWorldFaces.m_pElements = v25;
  v50 = -1;
  if ( v24 >= 0 )
  {
    if ( v25 != nullptr )
    {
      free(pMem: v25);
      aWorldFaces.m_Memory.m_pMemory = nullptr;
    }
    aWorldFaces.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B840
// Name: private: void CDispShoreManager::BuildShorelineOverlayPoints(struct Shoreline_t __near *,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::BuildShorelineOverlayPoints(
        CDispShoreManager *this,
        Shoreline_t *pShoreline,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aWaterFaces)
{
  int m_Size; // edi
  int i; // esi

  m_Size = pShoreline->m_aSegments.m_Size;
  if ( m_Size != 0 )
  {
    for ( i = 0; i < m_Size; ++i )
      CDispShoreManager::BuildShorelineOverlayPoint(this, pShoreline, iSegment: i, aWaterFaces);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B880
// Name: private: bool CDispShoreManager::ConnectShorelineSegments(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispShoreManager::ConnectShorelineSegments(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  int ShorelineStart; // edi
  int m_Size; // ecx
  int v6; // eax
  int v7; // edx
  ShoreSegment_t *m_pMemory; // esi
  int v9; // ecx
  bool v10; // al
  int v11; // edi
  int v12; // esi
  int m_nAllocationCount; // eax
  int *v14; // ecx
  int v15; // eax
  int *v16; // eax
  int nSegmentCount; // [esp+Ch] [ebp-8h]
  int iSegment2; // [esp+10h] [ebp-4h]
  bool bIsTouching0_3; // [esp+1Fh] [ebp+Bh]

  pShoreline->m_aSortedSegments.m_Size = 0;
  if ( pShoreline->m_aSortedSegments.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pShoreline->m_aSortedSegments.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: pShoreline->m_aSortedSegments.m_Memory.m_pMemory);
      pShoreline->m_aSortedSegments.m_Memory.m_pMemory = nullptr;
    }
    pShoreline->m_aSortedSegments.m_Memory.m_nAllocationCount = 0;
  }
  pShoreline->m_aSortedSegments.m_pElements = pShoreline->m_aSortedSegments.m_Memory.m_pMemory;
  ShorelineStart = CDispShoreManager::FindShorelineStart(this, pShoreline);
  if ( ShorelineStart == -1 )
    ShorelineStart = 0;
  m_Size = pShoreline->m_aSegments.m_Size;
  nSegmentCount = m_Size;
  do
  {
    v6 = 0;
    iSegment2 = 0;
    if ( m_Size <= 0 )
      goto LABEL_40;
    v7 = 0;
    while ( v6 == ShorelineStart )
    {
LABEL_29:
      ++v6;
      ++v7;
      iSegment2 = v6;
      if ( v6 >= m_Size )
        goto LABEL_40;
    }
    m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
    v9 = ShorelineStart;
    bIsTouching0_3 = false;
    if ( fabs(m_pMemory[ShorelineStart].m_vecPoints[0].x - m_pMemory[v7].m_vecPoints[0].x) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[0].y - m_pMemory[v7].m_vecPoints[0].y) <= 0.1 )
    {
      bIsTouching0_3 = fabs(m_pMemory[v9].m_vecPoints[0].z - m_pMemory[v7].m_vecPoints[0].z) <= 0.1;
    }
    if ( fabs(m_pMemory[v9].m_vecPoints[1].x - m_pMemory[v7].m_vecPoints[0].x) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[1].y - m_pMemory[v7].m_vecPoints[0].y) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[1].z - m_pMemory[v7].m_vecPoints[0].z) <= 0.1 )
    {
      bIsTouching0_3 = true;
    }
    v10 = false;
    if ( fabs(m_pMemory[ShorelineStart].m_vecPoints[0].x - m_pMemory[v7].m_vecPoints[1].x) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[0].y - m_pMemory[v7].m_vecPoints[1].y) <= 0.1 )
    {
      v10 = fabs(m_pMemory[v9].m_vecPoints[0].z - m_pMemory[v7].m_vecPoints[1].z) <= 0.1;
    }
    if ( fabs(m_pMemory[v9].m_vecPoints[1].x - m_pMemory[v7].m_vecPoints[1].x) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[1].y - m_pMemory[v7].m_vecPoints[1].y) <= 0.1
      && fabs(m_pMemory[v9].m_vecPoints[1].z - m_pMemory[v7].m_vecPoints[1].z) <= 0.1 )
    {
      v10 = true;
    }
    if ( !bIsTouching0_3 && !v10 || m_pMemory[v7].m_bTouch )
    {
      v6 = iSegment2;
      m_Size = nSegmentCount;
      goto LABEL_29;
    }
    v11 = iSegment2;
    m_pMemory[iSegment2].m_iStartPoint = 0;
    if ( v10 )
      pShoreline->m_aSegments.m_Memory.m_pMemory[v11].m_iStartPoint = 1;
    v12 = pShoreline->m_aSortedSegments.m_Size;
    m_nAllocationCount = pShoreline->m_aSortedSegments.m_Memory.m_nAllocationCount;
    if ( v12 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&pShoreline->m_aSortedSegments,
        num: v12 - m_nAllocationCount + 1);
    ++pShoreline->m_aSortedSegments.m_Size;
    v14 = pShoreline->m_aSortedSegments.m_Memory.m_pMemory;
    v15 = pShoreline->m_aSortedSegments.m_Size - v12 - 1;
    pShoreline->m_aSortedSegments.m_pElements = v14;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
    v16 = &pShoreline->m_aSortedSegments.m_Memory.m_pMemory[v12];
    if ( v16 != nullptr )
      *v16 = iSegment2;
    m_Size = nSegmentCount;
    pShoreline->m_aSegments.m_Memory.m_pMemory[v11].m_bTouch = true;
    v6 = iSegment2;
LABEL_40:
    if ( v6 == m_Size )
      break;
    ShorelineStart = v6;
  }
  while ( v6 != -1 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BB00
// Name: private: void CDispShoreManager::BuildShorelineOverlays(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::BuildShorelineOverlays(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  int m_Size; // eax
  int v3; // esi
  int v4; // edi
  CEditDispMgr *v5; // eax
  int v6; // eax
  int nSegmentCount; // [esp+4h] [ebp-8h]

  if ( pShoreline->m_aOverlays.m_Size != 0 )
    CUtlVector<CMapOverlay,CUtlMemory<CMapOverlay,int>>::Purge(this: &pShoreline->m_aOverlays);
  m_Size = pShoreline->m_aSegments.m_Size;
  nSegmentCount = m_Size;
  if ( m_Size != 0 && CMapDoc::m_pMapDoc != nullptr )
  {
    v3 = 0;
    if ( m_Size > 0 )
    {
      v4 = 0;
      do
      {
        v5 = EditDispMgr();
        v6 = (int)v5->GetDisp(this: v5, a2: pShoreline->m_aSegments.m_Memory.m_pMemory[v4].m_hDisp);
        if ( v6 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) != 0 )
          CDispShoreManager::CreateOverlays(this, pShoreline, iSegment: v3);
        ++v3;
        ++v4;
      }
      while ( v3 < nSegmentCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BC20
// Name: private: bool CDispShoreManager::TexcoordShoreline(struct Shoreline_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispShoreManager::TexcoordShoreline(CDispShoreManager *this, Shoreline_t *pShoreline)
{
  float v4; // xmm4_4
  int v5; // edi
  ShoreSegment_t *m_pMemory; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  int m_Size; // [esp+2Ch] [ebp-18h]
  int i; // [esp+34h] [ebp-10h]

  if ( pShoreline->m_aSegments.m_Size == 0 || CDispShoreManager::ConnectShorelineSegments(this, pShoreline) == 0 )
    return 0;
  CDispShoreManager::ShorelineLength(this, pShoreline);
  v4 = 0.0;
  m_Size = pShoreline->m_aSortedSegments.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = pShoreline->m_aSortedSegments.m_Memory.m_pMemory[i];
    CDispShoreManager::GenerateTexCoord(this, pShoreline, iSegment: v5, flLengthToSegment: v4, bEnd: false);
    m_pMemory = pShoreline->m_aSegments.m_Memory.m_pMemory;
    v7 = m_pMemory[v5].m_vecPoints[1].x - m_pMemory[v5].m_vecPoints[0].x;
    v8 = m_pMemory[v5].m_vecPoints[1].y - m_pMemory[v5].m_vecPoints[0].y;
    v9 = m_pMemory[v5].m_vecPoints[1].z - m_pMemory[v5].m_vecPoints[0].z;
    v4 = v4 + fsqrt((float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v7 * v7));
    CDispShoreManager::GenerateTexCoord(this, pShoreline, iSegment: v5, flLengthToSegment: v4, bEnd: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD30
// Name: public: virtual void CDispShoreManager::AddShoreline(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::AddShoreline(CDispShoreManager *this, int nShorelineId)
{
  this->RemoveShoreline(this, a2: nShorelineId);
  this->m_aShorelines.m_Memory.m_pMemory[CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::InsertBefore(
                                           this: &this->m_aShorelines,
                                           elem: this->m_aShorelines.m_Size)].m_nShorelineId = nShorelineId;
}

//------------------------------------------------------------------------------
// Address: 0x1002BD60
// Name: public: virtual void CDispShoreManager::RemoveShoreline(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::RemoveShoreline(CDispShoreManager *this, int nShorelineId)
{
  int v3; // ebx
  int v4; // edi
  Shoreline_t *m_pMemory; // eax

  v3 = this->m_aShorelines.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      m_pMemory = this->m_aShorelines.m_Memory.m_pMemory;
      if ( m_pMemory[v4].m_nShorelineId == nShorelineId )
      {
        Shoreline_t::~Shoreline_t(this: &m_pMemory[v4]);
        if ( this->m_aShorelines.m_Size - v3 - 1 > 0 )
          _V_memmove(
            dest: &this->m_aShorelines.m_Memory.m_pMemory[v4],
            src: &this->m_aShorelines.m_Memory.m_pMemory[v4 + 1],
            count: 96 * (this->m_aShorelines.m_Size - v3 - 1));
        --this->m_aShorelines.m_Size;
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BDC0
// Name: public: virtual void CDispShoreManager::BuildShoreline(int,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &,class CUtlVector<class CMapFace __near *,class CUtlMemory<class CMapFace __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::BuildShoreline(
        CDispShoreManager *this,
        int nShorelineId,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aFaces,
        CUtlVector<CMapFace *,CUtlMemory<CMapFace *,int> > *aWaterFaces)
{
  Shoreline_t *v5; // edi

  if ( aFaces->m_Size != 0 && aWaterFaces->m_Size != 0 )
  {
    v5 = this->GetShoreline(this, a2: nShorelineId);
    if ( v5 != nullptr )
    {
      CDispShoreManager::BuildShorelineSegments(this, pShoreline: v5, aFaces, aWaterFaces);
      CDispShoreManager::AverageShorelineNormals(this, pShoreline: v5);
      CDispShoreManager::BuildShorelineOverlayPoints(this, pShoreline: v5, aWaterFaces);
      CDispShoreManager::TexcoordShoreline(this, pShoreline: v5);
      CDispShoreManager::BuildShorelineOverlays(this, pShoreline: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BEE0
// Name: public: CDispShoreManager::CDispShoreManager(void)
// Source: json
//------------------------------------------------------------------------------
CDispShoreManager *__thiscall CDispShoreManager::CDispShoreManager(CDispShoreManager *this)
{
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int> > *p_m_aShorelines; // eax
  Shoreline_t *m_pMemory; // ecx
  CMapDisp **v4; // ecx

  p_m_aShorelines = &this->m_aShorelines;
  this->__vftable = (CDispShoreManager_vtbl *)&CDispShoreManager::`vftable';
  this->m_aShorelines.m_Memory.m_pMemory = nullptr;
  this->m_aShorelines.m_Memory.m_nAllocationCount = 0;
  this->m_aShorelines.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_aShorelines.m_Memory.m_pMemory;
  p_m_aShorelines->m_Size = 0;
  p_m_aShorelines->m_pElements = m_pMemory;
  this->m_aDispCache.m_Memory.m_pMemory = nullptr;
  this->m_aDispCache.m_Memory.m_nAllocationCount = 0;
  this->m_aDispCache.m_Memory.m_nGrowSize = 0;
  v4 = this->m_aDispCache.m_Memory.m_pMemory;
  this->m_aDispCache.m_Size = 0;
  this->m_aDispCache.m_pElements = v4;
  this->m_aDispCache.m_Size = 0;
  if ( this->m_aDispCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aDispCache.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aDispCache.m_Memory.m_pMemory);
      this->m_aDispCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_aDispCache.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aDispCache.m_pElements = this->m_aDispCache.m_Memory.m_pMemory;
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::Purge(this: &this->m_aShorelines);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002BF90
// Name: public: CDispShoreManager::~CDispShoreManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispShoreManager::~CDispShoreManager(CDispShoreManager *this)
{
  CUtlVector<CMapDisp *,CUtlMemory<CMapDisp *,int> > *p_m_aDispCache; // esi
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int> > *p_m_aShorelines; // esi

  this->__vftable = (CDispShoreManager_vtbl *)&CDispShoreManager::`vftable';
  p_m_aDispCache = &this->m_aDispCache;
  this->m_aDispCache.m_Size = 0;
  if ( this->m_aDispCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aDispCache->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aDispCache->m_Memory.m_pMemory);
      p_m_aDispCache->m_Memory.m_pMemory = nullptr;
    }
    p_m_aDispCache->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aDispCache->m_pElements = p_m_aDispCache->m_Memory.m_pMemory;
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::Purge(this: &this->m_aShorelines);
  p_m_aDispCache->m_Size = 0;
  if ( p_m_aDispCache->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aDispCache->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aDispCache->m_Memory.m_pMemory);
      p_m_aDispCache->m_Memory.m_pMemory = nullptr;
    }
    p_m_aDispCache->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aDispCache->m_pElements = p_m_aDispCache->m_Memory.m_pMemory;
  if ( p_m_aDispCache->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aDispCache->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aDispCache->m_Memory.m_pMemory);
      p_m_aDispCache->m_Memory.m_pMemory = nullptr;
    }
    p_m_aDispCache->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aShorelines = &this->m_aShorelines;
  CUtlVector<Shoreline_t,CUtlMemory<Shoreline_t,int>>::Purge(this: &this->m_aShorelines);
  if ( this->m_aShorelines.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aShorelines->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aShorelines->m_Memory.m_pMemory);
      p_m_aShorelines->m_Memory.m_pMemory = nullptr;
    }
    this->m_aShorelines.m_Memory.m_nAllocationCount = 0;
  }
}
