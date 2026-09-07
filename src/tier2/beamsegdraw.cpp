// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/beamsegdraw.cpp
// Functions: 6
// ============================================================

#include "tier2\beamsegdraw.h"

//------------------------------------------------------------------------------
// Address: 0x102B9D20
// Name: public: void CBeamSegDraw::End(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::End(CBeamSegDraw *this)
{
  CMeshBuilder *p_m_Mesh; // esi
  MaterialPrimitiveType_t m_Type; // edi
  int v3; // eax

  if ( this->m_pMeshBuilder != nullptr )
  {
    this->m_pMeshBuilder = nullptr;
  }
  else
  {
    p_m_Mesh = &this->m_Mesh;
    if ( this->m_Mesh.m_bGenerateIndices )
    {
      m_Type = this->m_Mesh.m_Type;
      v3 = CMeshBuilder::IndicesFromVertices(
             this: &this->m_Mesh,
             type: m_Type,
             nVertexCount: this->m_Mesh.m_VertexBuilder.m_nVertexCount);
      CIndexBuilder::GenerateIndices(this: &p_m_Mesh->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v3);
    }
    p_m_Mesh->m_pMesh->UnlockMesh(
      this: p_m_Mesh->m_pMesh,
      a2: p_m_Mesh->m_VertexBuilder.m_nVertexCount,
      a3: p_m_Mesh->m_IndexBuilder.m_nIndexCount,
      a4: p_m_Mesh);
    p_m_Mesh->m_IndexBuilder.m_pIndexBuffer = nullptr;
    p_m_Mesh->m_IndexBuilder.m_nMaxIndexCount = 0;
    p_m_Mesh->m_VertexBuilder.m_nMaxVertexCount = 0;
    p_m_Mesh->m_VertexBuilder.m_pVertexBuffer = nullptr;
    p_m_Mesh->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    p_m_Mesh->m_pMesh->Draw_2(this: p_m_Mesh->m_pMesh, a2: -1, a3: 0);
    p_m_Mesh->m_pMesh = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9DC0
// Name: public: void CBeamSegDraw::Start(class IMatRenderContext __near *,int,class IMaterial __near *,class CMeshBuilder __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::Start(
        CBeamSegDraw *this,
        IMatRenderContext *pRenderContext,
        int nSegs,
        IMaterial *pMaterial,
        CMeshBuilder *pMeshBuilder,
        int nMeshVertCount)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMesh *v8; // edi
  CMeshBuilder *p_m_Mesh; // esi

  this->m_pRenderContext = pRenderContext;
  this->m_nSegsDrawn = 0;
  this->m_nTotalSegs = nSegs;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &this->m_vecCameraPos);
  if ( pMeshBuilder != nullptr )
  {
    this->m_pMeshBuilder = pMeshBuilder;
    this->m_nMeshVertCount = nMeshVertCount;
  }
  else
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pMeshBuilder = nullptr;
    this->m_nMeshVertCount = 0;
    v8 = m_pRenderContext->GetDynamicMesh(this: m_pRenderContext, a2: true, a3: nullptr, a4: nullptr, a5: pMaterial);
    p_m_Mesh = &this->m_Mesh;
    p_m_Mesh->m_pMesh = v8;
    p_m_Mesh->m_bGenerateIndices = true;
    p_m_Mesh->m_Type = MATERIAL_TRIANGLE_STRIP;
    v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLE_STRIP);
    p_m_Mesh->m_pMesh->LockMesh(this: p_m_Mesh->m_pMesh, a2: 2 * nSegs, a3: 2 * nSegs, a4: p_m_Mesh, a5: nullptr);
    p_m_Mesh->m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
    p_m_Mesh->m_IndexBuilder.m_nIndexCount = 0;
    p_m_Mesh->m_IndexBuilder.m_nMaxIndexCount = 2 * nSegs;
    p_m_Mesh->m_IndexBuilder.m_bModify = false;
    p_m_Mesh->m_IndexBuilder.m_nIndexOffset = p_m_Mesh->m_nFirstVertex;
    p_m_Mesh->m_IndexBuilder.m_pIndices = p_m_Mesh->m_pIndices;
    p_m_Mesh->m_IndexBuilder.m_nIndexSize = p_m_Mesh->m_nIndexSize;
    p_m_Mesh->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &p_m_Mesh->m_VertexBuilder, pMesh: v8, nMaxVertexCount: 2 * nSegs, desc: p_m_Mesh);
    p_m_Mesh->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &p_m_Mesh->m_VertexBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9EE0
// Name: protected: void CBeamSegDraw::SpecifySeg(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::SpecifySeg(CBeamSegDraw *this, const Vector *vecCameraPos, const Vector *vNormal)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float y; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float m_flWidth; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float z; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float *m_pCurrPosition; // eax
  float m_flTexCoord; // xmm0_4
  float *v26; // eax
  float v27; // xmm0_4
  float *v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm0_4
  float *v34; // eax
  float *v35; // eax
  int m_nSegsDrawn; // eax
  int v37; // ecx
  CMeshBuilder *m_pMeshBuilder; // eax
  CMeshBuilder *v39; // eax
  CMeshBuilder *v40; // eax
  CMeshBuilder *v41; // eax
  CMeshBuilder *v42; // eax
  CMeshBuilder *v43; // esi
  float *v44; // eax
  float *v45; // eax
  float v46; // xmm0_4
  float *v47; // eax
  float v48; // xmm0_4
  float *v49; // eax
  float *v50; // eax
  float *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  float *v54; // esi
  float *v55; // eax
  float v56; // [esp-10h] [ebp-2Ch]
  float v57; // [esp-Ch] [ebp-28h]
  float vPoint2; // [esp+0h] [ebp-1Ch]
  float vPoint2_4; // [esp+4h] [ebp-18h]
  float vPoint2_8; // [esp+8h] [ebp-14h]
  CVertexBuilder *vTangentY; // [esp+Ch] [ebp-10h]

  v4 = this->m_Seg.m_vPos.x - vecCameraPos->x;
  v5 = this->m_Seg.m_vPos.y - vecCameraPos->y;
  v6 = this->m_Seg.m_vPos.z - vecCameraPos->z;
  y = vNormal->y;
  v8 = (float)(vNormal->z * v5) - (float)(y * v6);
  v9 = vNormal->z * v4;
  v10 = (float)(y * v4) - (float)(vNormal->x * v5);
  v11 = (float)(vNormal->x * v6) - v9;
  v12 = (float)((float)((float)(v8 * v8) + 0.00000011920929) + (float)(v11 * v11)) + (float)(v10 * v10);
  v56 = 1.0 / fsqrt(v12);
  v13 = (float)(3.0 - (float)((float)(v56 * v12) * v56)) * (float)(v56 * 0.5);
  vPoint2 = v8 * v13;
  vPoint2_4 = v11 * v13;
  vPoint2_8 = v10 * v13;
  m_flWidth = this->m_Seg.m_flWidth;
  v15 = m_flWidth * -0.5;
  v16 = m_flWidth * 0.5;
  v17 = vNormal->y;
  z = vNormal->z;
  v19 = (float)(v17 * v15) + this->m_Seg.m_vPos.y;
  v20 = (float)(z * v15) + this->m_Seg.m_vPos.z;
  v21 = (float)(vNormal->x * v16) + this->m_Seg.m_vPos.x;
  v22 = (float)(v17 * v16) + this->m_Seg.m_vPos.y;
  v23 = (float)(z * v16) + this->m_Seg.m_vPos.z;
  v57 = (float)(vNormal->x * v15) + this->m_Seg.m_vPos.x;
  if ( this->m_pMeshBuilder != nullptr )
  {
    m_pCurrPosition = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
    *m_pCurrPosition = v21;
    m_pCurrPosition[1] = v22;
    m_pCurrPosition[2] = v23;
    *(_DWORD *)this->m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                                  | ((this->m_Seg.m_color.g
                                                                    | ((this->m_Seg.m_color.r
                                                                      | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    m_flTexCoord = this->m_Seg.m_flTexCoord;
    v26 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v26 = 0.0;
    v26[1] = m_flTexCoord;
    v27 = this->m_Seg.m_flTexCoord;
    v28 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
    *v28 = 0.0;
    v28[1] = v27;
    *(Vector *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentS
              + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentS
              * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex) = *vNormal;
    v29 = (float *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentT
                  + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentT
                  * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex);
    *v29 = vPoint2;
    v29[1] = vPoint2_4;
    v29[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_pMeshBuilder->m_VertexBuilder);
    v30 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v30 = v57;
    v30[1] = v19;
    v30[2] = v20;
    *(_DWORD *)this->m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                                  | ((this->m_Seg.m_color.g
                                                                    | ((this->m_Seg.m_color.r
                                                                      | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v31 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    v32 = this->m_Seg.m_flTexCoord;
    *v31 = 1.0;
    v31[1] = v32;
    v33 = this->m_Seg.m_flTexCoord;
    v34 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
    *v34 = 1.0;
    v34[1] = v33;
    *(Vector *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentS
              + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentS
              * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex) = *vNormal;
    v35 = (float *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentT
                  + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentT
                  * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex);
    *v35 = vPoint2;
    v35[1] = vPoint2_4;
    v35[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_pMeshBuilder->m_VertexBuilder);
    m_nSegsDrawn = this->m_nSegsDrawn;
    if ( m_nSegsDrawn > 1 )
    {
      v37 = this->m_nMeshVertCount + 2 * m_nSegsDrawn - 4;
      m_pMeshBuilder = this->m_pMeshBuilder;
      m_pMeshBuilder->m_IndexBuilder.m_pIndices[m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                                                + LOWORD(m_pMeshBuilder->m_IndexBuilder.m_nIndexOffset);
      m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex += m_pMeshBuilder->m_IndexBuilder.m_nIndexSize;
      m_pMeshBuilder->m_IndexBuilder.m_nIndexCount = m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex;
      v39 = this->m_pMeshBuilder;
      v39->m_IndexBuilder.m_pIndices[v39->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v39->m_IndexBuilder.m_nIndexOffset)
                                                                          + 1;
      v39->m_IndexBuilder.m_nCurrentIndex += v39->m_IndexBuilder.m_nIndexSize;
      v39->m_IndexBuilder.m_nIndexCount = v39->m_IndexBuilder.m_nCurrentIndex;
      v40 = this->m_pMeshBuilder;
      v40->m_IndexBuilder.m_pIndices[v40->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v40->m_IndexBuilder.m_nIndexOffset)
                                                                          + 2;
      v40->m_IndexBuilder.m_nCurrentIndex += v40->m_IndexBuilder.m_nIndexSize;
      v40->m_IndexBuilder.m_nIndexCount = v40->m_IndexBuilder.m_nCurrentIndex;
      v41 = this->m_pMeshBuilder;
      v41->m_IndexBuilder.m_pIndices[v41->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v41->m_IndexBuilder.m_nIndexOffset)
                                                                          + 1;
      v41->m_IndexBuilder.m_nCurrentIndex += v41->m_IndexBuilder.m_nIndexSize;
      v41->m_IndexBuilder.m_nIndexCount = v41->m_IndexBuilder.m_nCurrentIndex;
      v42 = this->m_pMeshBuilder;
      v42->m_IndexBuilder.m_pIndices[v42->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v42->m_IndexBuilder.m_nIndexOffset)
                                                                          + 3;
      v42->m_IndexBuilder.m_nCurrentIndex += v42->m_IndexBuilder.m_nIndexSize;
      v42->m_IndexBuilder.m_nIndexCount = v42->m_IndexBuilder.m_nCurrentIndex;
      v43 = this->m_pMeshBuilder;
      v43->m_IndexBuilder.m_pIndices[v43->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v43->m_IndexBuilder.m_nIndexOffset)
                                                                          + 2;
      v43->m_IndexBuilder.m_nCurrentIndex += v43->m_IndexBuilder.m_nIndexSize;
      v43->m_IndexBuilder.m_nIndexCount = v43->m_IndexBuilder.m_nCurrentIndex;
    }
  }
  else
  {
    v44 = this->m_Mesh.m_VertexBuilder.m_pCurrPosition;
    *v44 = v21;
    v44[1] = v22;
    v44[2] = v23;
    *(_DWORD *)this->m_Mesh.m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                         | ((this->m_Seg.m_color.g
                                                           | ((this->m_Seg.m_color.r | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v45 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[0];
    v46 = this->m_Seg.m_flTexCoord;
    *v45 = 0.0;
    v45[1] = v46;
    v47 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[1];
    v48 = this->m_Seg.m_flTexCoord;
    *v47 = 0.0;
    v47[1] = v48;
    vTangentY = &this->m_Mesh.m_VertexBuilder;
    *(Vector *)((char *)this->m_Mesh.m_VertexBuilder.m_pTangentS
              + this->m_Mesh.m_VertexBuilder.m_nCurrentVertex * this->m_Mesh.m_VertexBuilder.m_VertexSize_TangentS) = *vNormal;
    v49 = (float *)((char *)this->m_Mesh.m_VertexBuilder.m_pTangentT
                  + this->m_Mesh.m_VertexBuilder.m_nCurrentVertex * this->m_Mesh.m_VertexBuilder.m_VertexSize_TangentT);
    *v49 = vPoint2;
    v49[1] = vPoint2_4;
    v49[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_Mesh.m_VertexBuilder);
    v50 = this->m_Mesh.m_VertexBuilder.m_pCurrPosition;
    *v50 = v57;
    v50[1] = v19;
    v50[2] = v20;
    *(_DWORD *)this->m_Mesh.m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                         | ((this->m_Seg.m_color.g
                                                           | ((this->m_Seg.m_color.r | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v51 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[0];
    v52 = this->m_Seg.m_flTexCoord;
    *v51 = 1.0;
    v51[1] = v52;
    v53 = this->m_Seg.m_flTexCoord;
    v54 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[1];
    *v54 = 1.0;
    v54[1] = v53;
    *(Vector *)((char *)vTangentY->m_pTangentS + vTangentY->m_nCurrentVertex * vTangentY->m_VertexSize_TangentS) = *vNormal;
    v55 = (float *)((char *)vTangentY->m_pTangentT + vTangentY->m_nCurrentVertex * vTangentY->m_VertexSize_TangentT);
    *v55 = vPoint2;
    v55[1] = vPoint2_4;
    v55[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: vTangentY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA5A0
// Name: public: virtual void CBeamSegDraw::NextSeg(struct BeamSeg_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBeamSegDraw::NextSeg(CBeamSegDraw *this@<ecx>, float a2@<ebp>, BeamSeg_t *pSeg)
{
  int m_nSegsDrawn; // ecx
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  Vector vNormal; // [esp+0h] [ebp-1Ch] BYREF
  float v27; // [esp+Ch] [ebp-10h]
  Vector vAveNormal; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  vAveNormal.x = a2;
  vAveNormal.y = retaddr;
  m_nSegsDrawn = this->m_nSegsDrawn;
  if ( m_nSegsDrawn > 0 )
  {
    v5 = this->m_Seg.m_vPos.x - pSeg->m_vPos.x;
    v6 = this->m_Seg.m_vPos.x - this->m_vecCameraPos.x;
    v7 = this->m_Seg.m_vPos.y - pSeg->m_vPos.y;
    v8 = this->m_Seg.m_vPos.y - this->m_vecCameraPos.y;
    v9 = this->m_Seg.m_vPos.z - pSeg->m_vPos.z;
    v10 = this->m_Seg.m_vPos.z - this->m_vecCameraPos.z;
    v11 = v9 * v8;
    v12 = (float)(v8 * v5) - (float)(v7 * v6);
    v13 = (float)(v10 * v7) - v11;
    v14 = (float)(v9 * v6) - (float)(v10 * v5);
    v15 = (float)((float)((float)(v13 * v13) + 0.00000011920929) + (float)(v14 * v14)) + (float)(v12 * v12);
    v16 = 1.0 / fsqrt(v15);
    v17 = (float)(3.0 - (float)((float)(v16 * v15) * v16)) * (float)(v16 * 0.5);
    v18 = v14 * v17;
    v19 = v12 * v17;
    v20 = v13 * v17;
    if ( m_nSegsDrawn <= 1 )
    {
      vNormal.y = v20;
      vNormal.z = v18;
      v27 = v19;
    }
    else
    {
      v21 = 0.5 * (float)(this->m_vNormalLast.x + v20);
      v22 = (float)(this->m_vNormalLast.y + v18) * 0.5;
      v23 = (float)(this->m_vNormalLast.z + v19) * 0.5;
      v24 = (float)((float)((float)(v21 * v21) + 0.00000011920929) + (float)(v22 * v22)) + (float)(v23 * v23);
      vNormal.x = 1.0 / fsqrt(v24);
      v25 = (float)(3.0 - (float)((float)(vNormal.x * v24) * vNormal.x)) * (float)(vNormal.x * 0.5);
      vNormal.y = v21 * v25;
      vNormal.z = v22 * v25;
      v27 = v23 * v25;
    }
    this->m_vNormalLast.x = v20;
    this->m_vNormalLast.y = v18;
    this->m_vNormalLast.z = v19;
    CBeamSegDraw::SpecifySeg(this, vecCameraPos: &this->m_vecCameraPos, vNormal: (Vector *)&vNormal.y);
  }
  this->m_Seg = *pSeg;
  if ( ++this->m_nSegsDrawn == this->m_nTotalSegs )
    CBeamSegDraw::SpecifySeg(this, vecCameraPos: &this->m_vecCameraPos, vNormal: &this->m_vNormalLast);
}

//------------------------------------------------------------------------------
// Address: 0x10406F8A
// Name: public: void CSmartDockingManager::Start(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::Start(CSmartDockingManager *this, CWnd *pDockingWnd)
{
  CObject *v3; // eax
  CObject *v4; // eax
  CObject *v5; // eax
  CSmartDockingStandaloneGuide **m_arMarkers; // edi
  unsigned int m_dwEnabledAlignment; // eax
  tagRECT v8; // [esp-10h] [ebp-1Ch] BYREF
  CSmartDockingStandaloneGuide::SDMarkerPlace i; // [esp+14h] [ebp+8h]

  if ( this->m_bCreated != 0 && this->m_bStarted == 0 )
  {
    this->m_nHiliteSideNo = sdNONE;
    this->m_pDockingWnd = pDockingWnd;
    this->m_wndPlaceMarker.m_pDockingWnd = pDockingWnd;
    this->m_dwEnabledAlignment = 61440;
    if ( pDockingWnd != nullptr )
    {
      v3 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: pDockingWnd);
      if ( v3 != nullptr )
      {
        v4 = (CObject *)((int (__thiscall *)(CObject *))v3->__vftable[35].dtr_CObject)(a1: v3);
        v5 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: v4);
        if ( v5 != nullptr )
          this->m_dwEnabledAlignment = ((int (__thiscall *)(CObject *))v5->__vftable[33].Serialize)(a1: v5);
      }
    }
    i = sdLEFT;
    m_arMarkers = this->m_arMarkers;
    do
    {
      CopyRect(lprcDst: &v8, lprcSrc: &this->m_rcOuter);
      ((void (__thiscall *)(CSmartDockingStandaloneGuide *, int, int, int, int))(*m_arMarkers)->AdjustPos)(
        a1: *m_arMarkers,
        a2: v8.left,
        a3: v8.top,
        a4: v8.right,
        a5: v8.bottom);
      m_dwEnabledAlignment = this->m_dwEnabledAlignment;
      if ( (m_dwEnabledAlignment & 0x1000) != 0 && i == sdLEFT
        || (m_dwEnabledAlignment & 0x4000) != 0 && i == sdRIGHT
        || (m_dwEnabledAlignment & 0x2000) != 0 && i == sdTOP
        || (m_dwEnabledAlignment & 0x8000) != 0 && i == sdBOTTOM )
      {
        (*m_arMarkers)->Show(this: *m_arMarkers, a2: 1);
      }
      ++i;
      ++m_arMarkers;
    }
    while ( i <= sdBOTTOM );
    this->m_bCentralGroupShown = 0;
    this->m_bShown = 1;
    this->m_bStarted = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040707D
// Name: public: void CSmartDockingManager::Stop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::Stop(CSmartDockingManager *this)
{
  CSmartDockingStandaloneGuide **m_arMarkers; // edi
  int i; // ebx

  if ( this->m_bStarted != 0 )
  {
    this->m_nHiliteSideNo = sdNONE;
    CSmartDockingHighlighterWnd::Hide(this: &this->m_wndPlaceMarker);
    m_arMarkers = this->m_arMarkers;
    for ( i = 4; i != 0; --i )
    {
      (*m_arMarkers)->Show(this: *m_arMarkers, a2: 0);
      ++m_arMarkers;
    }
    this->m_pCentralGroup->Show(this: this->m_pCentralGroup, a2: 0);
    this->m_bStarted = 0;
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036F900
// Name: public: void CBeamSegDraw::End(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::End(CBeamSegDraw *this)
{
  CMeshBuilder *p_m_Mesh; // esi
  MaterialPrimitiveType_t m_Type; // edi
  int v3; // eax

  if ( this->m_pMeshBuilder != nullptr )
  {
    this->m_pMeshBuilder = nullptr;
  }
  else
  {
    p_m_Mesh = &this->m_Mesh;
    if ( this->m_Mesh.m_bGenerateIndices )
    {
      m_Type = this->m_Mesh.m_Type;
      v3 = CMeshBuilder::IndicesFromVertices(
             this: &this->m_Mesh,
             type: m_Type,
             nVertexCount: this->m_Mesh.m_VertexBuilder.m_nVertexCount);
      CIndexBuilder::GenerateIndices(this: &p_m_Mesh->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v3);
    }
    p_m_Mesh->m_pMesh->UnlockMesh(
      this: p_m_Mesh->m_pMesh,
      a2: p_m_Mesh->m_VertexBuilder.m_nVertexCount,
      a3: p_m_Mesh->m_IndexBuilder.m_nIndexCount,
      a4: p_m_Mesh);
    p_m_Mesh->m_IndexBuilder.m_pIndexBuffer = nullptr;
    p_m_Mesh->m_IndexBuilder.m_nMaxIndexCount = 0;
    p_m_Mesh->m_VertexBuilder.m_nMaxVertexCount = 0;
    p_m_Mesh->m_VertexBuilder.m_pVertexBuffer = nullptr;
    p_m_Mesh->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    p_m_Mesh->m_pMesh->Draw_2(this: p_m_Mesh->m_pMesh, a2: -1, a3: 0);
    p_m_Mesh->m_pMesh = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F9A0
// Name: public: void CBeamSegDraw::Start(class IMatRenderContext __near *,int,class IMaterial __near *,class CMeshBuilder __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::Start(
        CBeamSegDraw *this,
        IMatRenderContext *pRenderContext,
        int nSegs,
        IMaterial *pMaterial,
        CMeshBuilder *pMeshBuilder,
        int nMeshVertCount)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMesh *v8; // edi
  CMeshBuilder *p_m_Mesh; // esi

  this->m_pRenderContext = pRenderContext;
  this->m_nSegsDrawn = 0;
  this->m_nTotalSegs = nSegs;
  pRenderContext->GetWorldSpaceCameraPosition(this: pRenderContext, a2: &this->m_vecCameraPos);
  if ( pMeshBuilder != nullptr )
  {
    this->m_pMeshBuilder = pMeshBuilder;
    this->m_nMeshVertCount = nMeshVertCount;
  }
  else
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pMeshBuilder = nullptr;
    this->m_nMeshVertCount = 0;
    v8 = m_pRenderContext->GetDynamicMesh(this: m_pRenderContext, a2: true, a3: nullptr, a4: nullptr, a5: pMaterial);
    p_m_Mesh = &this->m_Mesh;
    p_m_Mesh->m_pMesh = v8;
    p_m_Mesh->m_bGenerateIndices = true;
    p_m_Mesh->m_Type = MATERIAL_TRIANGLE_STRIP;
    v8->SetPrimitiveType(this: v8, a2: MATERIAL_TRIANGLE_STRIP);
    p_m_Mesh->m_pMesh->LockMesh(this: p_m_Mesh->m_pMesh, a2: 2 * nSegs, a3: 2 * nSegs, a4: p_m_Mesh, a5: nullptr);
    p_m_Mesh->m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
    p_m_Mesh->m_IndexBuilder.m_nIndexCount = 0;
    p_m_Mesh->m_IndexBuilder.m_nMaxIndexCount = 2 * nSegs;
    p_m_Mesh->m_IndexBuilder.m_bModify = false;
    p_m_Mesh->m_IndexBuilder.m_nIndexOffset = p_m_Mesh->m_nFirstVertex;
    p_m_Mesh->m_IndexBuilder.m_pIndices = p_m_Mesh->m_pIndices;
    p_m_Mesh->m_IndexBuilder.m_nIndexSize = p_m_Mesh->m_nIndexSize;
    p_m_Mesh->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &p_m_Mesh->m_VertexBuilder, pMesh: v8, nMaxVertexCount: 2 * nSegs, desc: p_m_Mesh);
    p_m_Mesh->m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &p_m_Mesh->m_VertexBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036FAC0
// Name: protected: void CBeamSegDraw::SpecifySeg(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBeamSegDraw::SpecifySeg(CBeamSegDraw *this, const Vector *vecCameraPos, const Vector *vNormal)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float y; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float m_flWidth; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float z; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm4_4
  float *m_pCurrPosition; // eax
  float m_flTexCoord; // xmm0_4
  float *v26; // eax
  float v27; // xmm0_4
  float *v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float v32; // xmm0_4
  float v33; // xmm0_4
  float *v34; // eax
  float *v35; // eax
  int m_nSegsDrawn; // eax
  int v37; // ecx
  CMeshBuilder *m_pMeshBuilder; // eax
  CMeshBuilder *v39; // eax
  CMeshBuilder *v40; // eax
  CMeshBuilder *v41; // eax
  CMeshBuilder *v42; // eax
  CMeshBuilder *v43; // esi
  float *v44; // eax
  float *v45; // eax
  float v46; // xmm0_4
  float *v47; // eax
  float v48; // xmm0_4
  float *v49; // eax
  float *v50; // eax
  float *v51; // eax
  float v52; // xmm0_4
  float v53; // xmm0_4
  float *v54; // esi
  float *v55; // eax
  float v56; // [esp-10h] [ebp-2Ch]
  float v57; // [esp-Ch] [ebp-28h]
  float vPoint2; // [esp+0h] [ebp-1Ch]
  float vPoint2_4; // [esp+4h] [ebp-18h]
  float vPoint2_8; // [esp+8h] [ebp-14h]
  CVertexBuilder *vTangentY; // [esp+Ch] [ebp-10h]

  v4 = this->m_Seg.m_vPos.x - vecCameraPos->x;
  v5 = this->m_Seg.m_vPos.y - vecCameraPos->y;
  v6 = this->m_Seg.m_vPos.z - vecCameraPos->z;
  y = vNormal->y;
  v8 = (float)(vNormal->z * v5) - (float)(y * v6);
  v9 = vNormal->z * v4;
  v10 = (float)(y * v4) - (float)(vNormal->x * v5);
  v11 = (float)(vNormal->x * v6) - v9;
  v12 = (float)((float)((float)(v8 * v8) + 0.00000011920929) + (float)(v11 * v11)) + (float)(v10 * v10);
  v56 = 1.0 / fsqrt(v12);
  v13 = (float)(3.0 - (float)((float)(v56 * v12) * v56)) * (float)(v56 * 0.5);
  vPoint2 = v8 * v13;
  vPoint2_4 = v11 * v13;
  vPoint2_8 = v10 * v13;
  m_flWidth = this->m_Seg.m_flWidth;
  v15 = m_flWidth * -0.5;
  v16 = m_flWidth * 0.5;
  v17 = vNormal->y;
  z = vNormal->z;
  v19 = (float)(v17 * v15) + this->m_Seg.m_vPos.y;
  v20 = (float)(z * v15) + this->m_Seg.m_vPos.z;
  v21 = (float)(vNormal->x * v16) + this->m_Seg.m_vPos.x;
  v22 = (float)(v17 * v16) + this->m_Seg.m_vPos.y;
  v23 = (float)(z * v16) + this->m_Seg.m_vPos.z;
  v57 = (float)(vNormal->x * v15) + this->m_Seg.m_vPos.x;
  if ( this->m_pMeshBuilder != nullptr )
  {
    m_pCurrPosition = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
    *m_pCurrPosition = v21;
    m_pCurrPosition[1] = v22;
    m_pCurrPosition[2] = v23;
    *(_DWORD *)this->m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                                  | ((this->m_Seg.m_color.g
                                                                    | ((this->m_Seg.m_color.r
                                                                      | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    m_flTexCoord = this->m_Seg.m_flTexCoord;
    v26 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v26 = 0.0;
    v26[1] = m_flTexCoord;
    v27 = this->m_Seg.m_flTexCoord;
    v28 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
    *v28 = 0.0;
    v28[1] = v27;
    *(Vector *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentS
              + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentS
              * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex) = *vNormal;
    v29 = (float *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentT
                  + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentT
                  * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex);
    *v29 = vPoint2;
    v29[1] = vPoint2_4;
    v29[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_pMeshBuilder->m_VertexBuilder);
    v30 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v30 = v57;
    v30[1] = v19;
    v30[2] = v20;
    *(_DWORD *)this->m_pMeshBuilder->m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                                  | ((this->m_Seg.m_color.g
                                                                    | ((this->m_Seg.m_color.r
                                                                      | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v31 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    v32 = this->m_Seg.m_flTexCoord;
    *v31 = 1.0;
    v31[1] = v32;
    v33 = this->m_Seg.m_flTexCoord;
    v34 = this->m_pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1];
    *v34 = 1.0;
    v34[1] = v33;
    *(Vector *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentS
              + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentS
              * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex) = *vNormal;
    v35 = (float *)((char *)this->m_pMeshBuilder->m_VertexBuilder.m_pTangentT
                  + this->m_pMeshBuilder->m_VertexBuilder.m_VertexSize_TangentT
                  * this->m_pMeshBuilder->m_VertexBuilder.m_nCurrentVertex);
    *v35 = vPoint2;
    v35[1] = vPoint2_4;
    v35[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_pMeshBuilder->m_VertexBuilder);
    m_nSegsDrawn = this->m_nSegsDrawn;
    if ( m_nSegsDrawn > 1 )
    {
      v37 = this->m_nMeshVertCount + 2 * m_nSegsDrawn - 4;
      m_pMeshBuilder = this->m_pMeshBuilder;
      m_pMeshBuilder->m_IndexBuilder.m_pIndices[m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                                                + LOWORD(m_pMeshBuilder->m_IndexBuilder.m_nIndexOffset);
      m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex += m_pMeshBuilder->m_IndexBuilder.m_nIndexSize;
      m_pMeshBuilder->m_IndexBuilder.m_nIndexCount = m_pMeshBuilder->m_IndexBuilder.m_nCurrentIndex;
      v39 = this->m_pMeshBuilder;
      v39->m_IndexBuilder.m_pIndices[v39->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v39->m_IndexBuilder.m_nIndexOffset)
                                                                          + 1;
      v39->m_IndexBuilder.m_nCurrentIndex += v39->m_IndexBuilder.m_nIndexSize;
      v39->m_IndexBuilder.m_nIndexCount = v39->m_IndexBuilder.m_nCurrentIndex;
      v40 = this->m_pMeshBuilder;
      v40->m_IndexBuilder.m_pIndices[v40->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v40->m_IndexBuilder.m_nIndexOffset)
                                                                          + 2;
      v40->m_IndexBuilder.m_nCurrentIndex += v40->m_IndexBuilder.m_nIndexSize;
      v40->m_IndexBuilder.m_nIndexCount = v40->m_IndexBuilder.m_nCurrentIndex;
      v41 = this->m_pMeshBuilder;
      v41->m_IndexBuilder.m_pIndices[v41->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v41->m_IndexBuilder.m_nIndexOffset)
                                                                          + 1;
      v41->m_IndexBuilder.m_nCurrentIndex += v41->m_IndexBuilder.m_nIndexSize;
      v41->m_IndexBuilder.m_nIndexCount = v41->m_IndexBuilder.m_nCurrentIndex;
      v42 = this->m_pMeshBuilder;
      v42->m_IndexBuilder.m_pIndices[v42->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v42->m_IndexBuilder.m_nIndexOffset)
                                                                          + 3;
      v42->m_IndexBuilder.m_nCurrentIndex += v42->m_IndexBuilder.m_nIndexSize;
      v42->m_IndexBuilder.m_nIndexCount = v42->m_IndexBuilder.m_nCurrentIndex;
      v43 = this->m_pMeshBuilder;
      v43->m_IndexBuilder.m_pIndices[v43->m_IndexBuilder.m_nCurrentIndex] = v37
                                                                          + LOWORD(v43->m_IndexBuilder.m_nIndexOffset)
                                                                          + 2;
      v43->m_IndexBuilder.m_nCurrentIndex += v43->m_IndexBuilder.m_nIndexSize;
      v43->m_IndexBuilder.m_nIndexCount = v43->m_IndexBuilder.m_nCurrentIndex;
    }
  }
  else
  {
    v44 = this->m_Mesh.m_VertexBuilder.m_pCurrPosition;
    *v44 = v21;
    v44[1] = v22;
    v44[2] = v23;
    *(_DWORD *)this->m_Mesh.m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                         | ((this->m_Seg.m_color.g
                                                           | ((this->m_Seg.m_color.r | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v45 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[0];
    v46 = this->m_Seg.m_flTexCoord;
    *v45 = 0.0;
    v45[1] = v46;
    v47 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[1];
    v48 = this->m_Seg.m_flTexCoord;
    *v47 = 0.0;
    v47[1] = v48;
    vTangentY = &this->m_Mesh.m_VertexBuilder;
    *(Vector *)((char *)this->m_Mesh.m_VertexBuilder.m_pTangentS
              + this->m_Mesh.m_VertexBuilder.m_nCurrentVertex * this->m_Mesh.m_VertexBuilder.m_VertexSize_TangentS) = *vNormal;
    v49 = (float *)((char *)this->m_Mesh.m_VertexBuilder.m_pTangentT
                  + this->m_Mesh.m_VertexBuilder.m_nCurrentVertex * this->m_Mesh.m_VertexBuilder.m_VertexSize_TangentT);
    *v49 = vPoint2;
    v49[1] = vPoint2_4;
    v49[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: &this->m_Mesh.m_VertexBuilder);
    v50 = this->m_Mesh.m_VertexBuilder.m_pCurrPosition;
    *v50 = v57;
    v50[1] = v19;
    v50[2] = v20;
    *(_DWORD *)this->m_Mesh.m_VertexBuilder.m_pCurrColor = this->m_Seg.m_color.b
                                                         | ((this->m_Seg.m_color.g
                                                           | ((this->m_Seg.m_color.r | (this->m_Seg.m_color.a << 8)) << 8)) << 8);
    v51 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[0];
    v52 = this->m_Seg.m_flTexCoord;
    *v51 = 1.0;
    v51[1] = v52;
    v53 = this->m_Seg.m_flTexCoord;
    v54 = this->m_Mesh.m_VertexBuilder.m_pCurrTexCoord[1];
    *v54 = 1.0;
    v54[1] = v53;
    *(Vector *)((char *)vTangentY->m_pTangentS + vTangentY->m_nCurrentVertex * vTangentY->m_VertexSize_TangentS) = *vNormal;
    v55 = (float *)((char *)vTangentY->m_pTangentT + vTangentY->m_nCurrentVertex * vTangentY->m_VertexSize_TangentT);
    *v55 = vPoint2;
    v55[1] = vPoint2_4;
    v55[2] = vPoint2_8;
    CVertexBuilder::AdvanceVertex(this: vTangentY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10370180
// Name: public: virtual void CBeamSegDraw::NextSeg(struct BeamSeg_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBeamSegDraw::NextSeg(CBeamSegDraw *this@<ecx>, float a2@<ebp>, BeamSeg_t *pSeg)
{
  int m_nSegsDrawn; // ecx
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  Vector vNormal; // [esp+0h] [ebp-1Ch] BYREF
  float v27; // [esp+Ch] [ebp-10h]
  Vector vAveNormal; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  vAveNormal.x = a2;
  vAveNormal.y = retaddr;
  m_nSegsDrawn = this->m_nSegsDrawn;
  if ( m_nSegsDrawn > 0 )
  {
    v5 = this->m_Seg.m_vPos.x - pSeg->m_vPos.x;
    v6 = this->m_Seg.m_vPos.x - this->m_vecCameraPos.x;
    v7 = this->m_Seg.m_vPos.y - pSeg->m_vPos.y;
    v8 = this->m_Seg.m_vPos.y - this->m_vecCameraPos.y;
    v9 = this->m_Seg.m_vPos.z - pSeg->m_vPos.z;
    v10 = this->m_Seg.m_vPos.z - this->m_vecCameraPos.z;
    v11 = v9 * v8;
    v12 = (float)(v8 * v5) - (float)(v7 * v6);
    v13 = (float)(v10 * v7) - v11;
    v14 = (float)(v9 * v6) - (float)(v10 * v5);
    v15 = (float)((float)((float)(v13 * v13) + 0.00000011920929) + (float)(v14 * v14)) + (float)(v12 * v12);
    v16 = 1.0 / fsqrt(v15);
    v17 = (float)(3.0 - (float)((float)(v16 * v15) * v16)) * (float)(v16 * 0.5);
    v18 = v14 * v17;
    v19 = v12 * v17;
    v20 = v13 * v17;
    if ( m_nSegsDrawn <= 1 )
    {
      vNormal.y = v20;
      vNormal.z = v18;
      v27 = v19;
    }
    else
    {
      v21 = 0.5 * (float)(this->m_vNormalLast.x + v20);
      v22 = (float)(this->m_vNormalLast.y + v18) * 0.5;
      v23 = (float)(this->m_vNormalLast.z + v19) * 0.5;
      v24 = (float)((float)((float)(v21 * v21) + 0.00000011920929) + (float)(v22 * v22)) + (float)(v23 * v23);
      vNormal.x = 1.0 / fsqrt(v24);
      v25 = (float)(3.0 - (float)((float)(vNormal.x * v24) * vNormal.x)) * (float)(vNormal.x * 0.5);
      vNormal.y = v21 * v25;
      vNormal.z = v22 * v25;
      v27 = v23 * v25;
    }
    this->m_vNormalLast.x = v20;
    this->m_vNormalLast.y = v18;
    this->m_vNormalLast.z = v19;
    CBeamSegDraw::SpecifySeg(this, vecCameraPos: &this->m_vecCameraPos, vNormal: (Vector *)&vNormal.y);
  }
  this->m_Seg = *pSeg;
  if ( ++this->m_nSegsDrawn == this->m_nTotalSegs )
    CBeamSegDraw::SpecifySeg(this, vecCameraPos: &this->m_vecCameraPos, vNormal: &this->m_vNormalLast);
}

} // namespace client
