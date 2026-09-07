// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiodraw.cpp
// Functions: 77
// ============================================================

#include "studiorender\r_studiodraw.h"

//------------------------------------------------------------------------------
// Address: 0x10008920
// Name: public: void CVertexBuilder::SelectVertex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::SelectVertex(CVertexBuilder *this, int nIndex)
{
  float *v2; // edx

  v2 = (float *)((char *)this->m_pPosition + nIndex * this->m_VertexSize_Position);
  this->m_nCurrentVertex = nIndex;
  this->m_pCurrPosition = v2;
  this->m_pCurrNormal = (float *)((char *)this->m_pNormal + nIndex * this->m_VertexSize_Normal);
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pTexCoord[0] + nIndex * this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pTexCoord[1] + nIndex * this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pTexCoord[2] + nIndex * this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pTexCoord[3] + nIndex * this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pTexCoord[4] + nIndex * this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pTexCoord[5] + nIndex * this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pTexCoord[6] + nIndex * this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pTexCoord[7] + nIndex * this->m_VertexSize_TexCoord[7]);
  this->m_pCurrColor = &this->m_pColor[nIndex * this->m_VertexSize_Color];
}

//------------------------------------------------------------------------------
// Address: 0x100089E0
// Name: private: void CStudioRender::ComputeEyelidStateFACS(struct mstudiomodel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ComputeEyelidStateFACS(CStudioRender *this, mstudiomodel_t *pSubModel)
{
  int v2; // ebx
  eyeballstate_t *m_pEyeballState; // edi
  int j; // [esp+8h] [ebp-8h]
  CStudioRender *v5; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v5 = this;
  j = 0;
  if ( pSubModel->numeyeballs > 0 )
  {
    m_pEyeballState = this->m_pEyeballState;
    while ( 1 )
    {
      CStudioRender::R_StudioEyeballPosition(
        this,
        peyeball: (const mstudioeyeball_t *)&pSubModel->name[v2 + pSubModel->eyeballindex],
        pstate: m_pEyeballState);
      CStudioRender::R_StudioEyelidFACS(
        this: v5,
        peyeball: (const mstudioeyeball_t *)&pSubModel->name[v2 + pSubModel->eyeballindex],
        pstate: m_pEyeballState++);
      v2 += 172;
      if ( ++j >= pSubModel->numeyeballs )
        break;
      this = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008A40
// Name: struct matrix3x4_t __near * ComputeSkinMatrix(struct mstudioboneweight_t __near &,struct matrix3x4_t __near *,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl ComputeSkinMatrix(
        mstudioboneweight_t *boneweights,
        matrix3x4_t *pPoseToWorld,
        matrix3x4_t *scratchMatrix)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm3_4
  float *v9; // edx
  float *v10; // ecx
  float *v11; // esi
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // ecx
  float v15; // xmm3_4
  float *v16; // ecx
  int v17; // edx
  float v18; // xmm2_4
  float *v19; // edx

  switch ( boneweights->numbones )
  {
    case 2u:
      v12 = boneweights->weight[1];
      v13 = boneweights->weight[0];
      v14 = boneweights->bone[0];
      v15 = pPoseToWorld[v14].m_flMatVal[0][0] * boneweights->weight[0];
      v16 = (float *)&pPoseToWorld[v14];
      v17 = boneweights->bone[1];
      scratchMatrix->m_flMatVal[0][0] = (float)(pPoseToWorld[v17].m_flMatVal[0][0] * v12) + v15;
      v18 = pPoseToWorld[v17].m_flMatVal[0][1] * v12;
      v19 = (float *)&pPoseToWorld[v17];
      scratchMatrix->m_flMatVal[0][1] = v18 + (float)(v16[1] * v13);
      scratchMatrix->m_flMatVal[0][2] = (float)(v19[2] * v12) + (float)(v16[2] * v13);
      scratchMatrix->m_flMatVal[0][3] = (float)(v19[3] * v12) + (float)(v16[3] * v13);
      scratchMatrix->m_flMatVal[1][0] = (float)(v19[4] * v12) + (float)(v16[4] * v13);
      scratchMatrix->m_flMatVal[1][1] = (float)(v19[5] * v12) + (float)(v16[5] * v13);
      scratchMatrix->m_flMatVal[1][2] = (float)(v19[6] * v12) + (float)(v16[6] * v13);
      scratchMatrix->m_flMatVal[1][3] = (float)(v19[7] * v12) + (float)(v16[7] * v13);
      scratchMatrix->m_flMatVal[2][0] = (float)(v19[8] * v12) + (float)(v16[8] * v13);
      scratchMatrix->m_flMatVal[2][1] = (float)(v19[9] * v12) + (float)(v16[9] * v13);
      scratchMatrix->m_flMatVal[2][2] = (float)(v19[10] * v12) + (float)(v16[10] * v13);
      scratchMatrix->m_flMatVal[2][3] = (float)(v19[11] * v12) + (float)(v16[11] * v13);
      return scratchMatrix;
    case 3u:
      v4 = boneweights->weight[0];
      v5 = boneweights->weight[1];
      v6 = boneweights->weight[2];
      v7 = boneweights->bone[1];
      v8 = pPoseToWorld[v7].m_flMatVal[0][0] * v5;
      v9 = (float *)&pPoseToWorld[v7];
      v10 = (float *)&pPoseToWorld[boneweights->bone[0]];
      v11 = (float *)&pPoseToWorld[boneweights->bone[2]];
      scratchMatrix->m_flMatVal[0][0] = (float)(v8 + (float)(boneweights->weight[0] * *v10)) + (float)(*v11 * v6);
      scratchMatrix->m_flMatVal[0][1] = (float)((float)(v9[1] * v5) + (float)(v10[1] * v4)) + (float)(v11[1] * v6);
      scratchMatrix->m_flMatVal[0][2] = (float)((float)(v9[2] * v5) + (float)(v10[2] * v4)) + (float)(v11[2] * v6);
      scratchMatrix->m_flMatVal[0][3] = (float)((float)(v9[3] * v5) + (float)(v10[3] * v4)) + (float)(v11[3] * v6);
      scratchMatrix->m_flMatVal[1][0] = (float)((float)(v9[4] * v5) + (float)(v10[4] * v4)) + (float)(v11[4] * v6);
      scratchMatrix->m_flMatVal[1][1] = (float)((float)(v9[5] * v5) + (float)(v10[5] * v4)) + (float)(v11[5] * v6);
      scratchMatrix->m_flMatVal[1][2] = (float)((float)(v9[6] * v5) + (float)(v10[6] * v4)) + (float)(v11[6] * v6);
      scratchMatrix->m_flMatVal[1][3] = (float)((float)(v9[7] * v5) + (float)(v10[7] * v4)) + (float)(v11[7] * v6);
      scratchMatrix->m_flMatVal[2][0] = (float)((float)(v9[8] * v5) + (float)(v10[8] * v4)) + (float)(v11[8] * v6);
      scratchMatrix->m_flMatVal[2][1] = (float)((float)(v9[9] * v5) + (float)(v10[9] * v4)) + (float)(v11[9] * v6);
      scratchMatrix->m_flMatVal[2][2] = (float)((float)(v9[10] * v5) + (float)(v10[10] * v4)) + (float)(v11[10] * v6);
      scratchMatrix->m_flMatVal[2][3] = (float)((float)(v9[11] * v5) + (float)(v10[11] * v4)) + (float)(v11[11] * v6);
      return scratchMatrix;
    case 4u:
      return scratchMatrix;
    default:
      return &pPoseToWorld[boneweights->bone[0]];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008E00
// Name: void ComputeSkinMatrixToMemorySSE(struct mstudioboneweight_t __near &,struct matrix3x4_t __near *,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeSkinMatrixToMemorySSE(matrix3x4_t *boneweights, matrix3x4_t *pPoseToWorld, matrix3x4_t *result)
{
  int v4; // eax
  __int64 v5; // xmm0_8
  matrix3x4_t *v6; // eax
  __m128 *v7; // eax
  __m128 *v8; // ecx
  __m128 v9; // xmm6
  __m128 v10; // xmm7
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  __m128 *v13; // eax
  __m128 *v14; // ecx
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm7
  __m128 *v18; // eax
  __m128 *v19; // ecx
  __m128 *v20; // edx
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  __m128 *boneMat3; // [esp+24h] [ebp+8h]
  __m128 *boneMat3a; // [esp+24h] [ebp+8h]

  if ( HIBYTE(boneweights->m_flMatVal[0][3]) == 2 )
  {
    v7 = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
    v8 = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
    v9 = _mm_shuffle_ps(
           (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
           (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
           0);
    v10 = _mm_shuffle_ps(
            (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
            (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
            0);
    v11 = _mm_add_ps(_mm_mul_ps(v7[1], v9), _mm_mul_ps(v8[1], v10));
    v12 = _mm_add_ps(_mm_mul_ps(v7[2], v9), _mm_mul_ps(v8[2], v10));
    *(__m128 *)&result->m_flMatVal[0][0] = _mm_add_ps(_mm_mul_ps(*v7, v9), _mm_mul_ps(*v8, v10));
    *(__m128 *)&result->m_flMatVal[1][0] = v11;
    *(__m128 *)&result->m_flMatVal[2][0] = v12;
    goto LABEL_6;
  }
  if ( HIBYTE(boneweights->m_flMatVal[0][3]) == 3 )
  {
LABEL_6:
    boneMat3 = (__m128 *)&pPoseToWorld[BYTE2(boneweights->m_flMatVal[0][3])];
    v13 = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
    v14 = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
    v15 = _mm_shuffle_ps(
            (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
            (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
            0);
    v16 = _mm_shuffle_ps(
            (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
            (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
            0);
    v17 = _mm_shuffle_ps(
            (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
            (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
            0);
    *(__m128 *)&result->m_flMatVal[0][0] = _mm_add_ps(
                                             _mm_add_ps(_mm_mul_ps(*v13, v15), _mm_mul_ps(*v14, v16)),
                                             _mm_mul_ps(*boneMat3, v17));
    *(__m128 *)&result->m_flMatVal[1][0] = _mm_add_ps(
                                             _mm_add_ps(_mm_mul_ps(v13[1], v15), _mm_mul_ps(v14[1], v16)),
                                             _mm_mul_ps(boneMat3[1], v17));
    *(__m128 *)&result->m_flMatVal[2][0] = _mm_add_ps(
                                             _mm_add_ps(_mm_mul_ps(v13[2], v15), _mm_mul_ps(v14[2], v16)),
                                             _mm_mul_ps(boneMat3[2], v17));
    goto LABEL_7;
  }
  if ( HIBYTE(boneweights->m_flMatVal[0][3]) != 4 )
  {
    v4 = LOBYTE(boneweights->m_flMatVal[0][3]);
    v5 = *(_QWORD *)&pPoseToWorld[v4].m_flMatVal[0][0];
    v6 = &pPoseToWorld[v4];
    *(_QWORD *)&result->m_flMatVal[0][0] = v5;
    *(_QWORD *)&result->m_flMatVal[0][2] = *(_QWORD *)&v6->m_flMatVal[0][2];
    *(_QWORD *)&result->m_flMatVal[1][0] = *(_QWORD *)&v6->m_flMatVal[1][0];
    *(_QWORD *)&result->m_flMatVal[1][2] = *(_QWORD *)&v6->m_flMatVal[1][2];
    *(_QWORD *)&result->m_flMatVal[2][0] = *(_QWORD *)&v6->m_flMatVal[2][0];
    *(_QWORD *)&result->m_flMatVal[2][2] = *(_QWORD *)&v6->m_flMatVal[2][2];
    return;
  }
LABEL_7:
  boneMat3a = (__m128 *)&pPoseToWorld[HIBYTE(boneweights->m_flMatVal[0][3])];
  v18 = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
  v19 = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
  v20 = (__m128 *)&pPoseToWorld[BYTE2(boneweights->m_flMatVal[0][3])];
  v21 = _mm_shuffle_ps(
          (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
          (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
          0);
  v22 = _mm_shuffle_ps(
          (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
          (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
          0);
  v23 = _mm_shuffle_ps(
          (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
          (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
          0);
  v24 = _mm_shuffle_ps(
          (__m128)LODWORD(boneweights->m_flMatVal[0][3]),
          (__m128)LODWORD(boneweights->m_flMatVal[0][3]),
          0);
  *(__m128 *)&result->m_flMatVal[0][0] = _mm_add_ps(
                                           _mm_add_ps(_mm_mul_ps(*v18, v21), _mm_mul_ps(*v19, v22)),
                                           _mm_add_ps(_mm_mul_ps(*v20, v23), _mm_mul_ps(*boneMat3a, v24)));
  *(__m128 *)&result->m_flMatVal[1][0] = _mm_add_ps(
                                           _mm_add_ps(_mm_mul_ps(v18[1], v21), _mm_mul_ps(v19[1], v22)),
                                           _mm_add_ps(_mm_mul_ps(v20[1], v23), _mm_mul_ps(boneMat3a[1], v24)));
  *(__m128 *)&result->m_flMatVal[2][0] = _mm_add_ps(
                                           _mm_add_ps(_mm_mul_ps(v18[2], v21), _mm_mul_ps(v19[2], v22)),
                                           _mm_add_ps(_mm_mul_ps(v20[2], v23), _mm_mul_ps(boneMat3a[2], v24)));
}

//------------------------------------------------------------------------------
// Address: 0x10009310
// Name: private: void CStudioRender::R_StudioProcessFlexedMesh_StreamOffset(struct mstudiomesh_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioProcessFlexedMesh_StreamOffset(
        CStudioRender *this,
        mstudiomesh_t *pmesh,
        int lod)
{
  mstudioflex_t *v5; // esi
  int flexpair; // eax
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  CCachedRenderData *p_m_VertexCache; // ecx
  studiohdr_t *m_pStudioHdr; // [esp+4h] [ebp-3Ch]
  mstudiovertanim_wrinkle_t *v13; // [esp+Ch] [ebp-34h]
  float w4; // [esp+30h] [ebp-10h]
  float w3; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  int vertCount; // [esp+3Ch] [ebp-4h]
  float w2; // [esp+48h] [ebp+8h]
  float w1; // [esp+4Ch] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ProcessFlexedMesh_SO",
    a3: 0,
    a4: "HW_Morphing",
    a5: false,
    a6: 4);
  if ( !CCachedRenderData::IsFlexComputationDone(this: &this->m_VertexCache) )
  {
    vertCount = pmesh->vertexdata.numLODVertexes[lod];
    CCachedRenderData::SetupComputation(this: &this->m_VertexCache, pMesh: pmesh, flexComputation: true);
    v5 = (mstudioflex_t *)((char *)pmesh + pmesh->flexindex);
    for ( i = 0; i < pmesh->numflexes; ++i )
    {
      w1 = CStudioRender::RampFlexWeight(this, flex: v5, w: this->m_pFlexWeights[v5->flexdesc]);
      w2 = CStudioRender::RampFlexWeight(this, flex: v5, w: this->m_pFlexDelayedWeights[v5->flexdesc]);
      flexpair = v5->flexpair;
      v7 = w1;
      v8 = w2;
      if ( flexpair != 0 )
      {
        w3 = CStudioRender::RampFlexWeight(this, flex: v5, w: this->m_pFlexWeights[flexpair]);
        w4 = CStudioRender::RampFlexWeight(this, flex: v5, w: this->m_pFlexDelayedWeights[v5->flexpair]);
        v9 = w3;
        v10 = w4;
        v8 = w2;
        v7 = w1;
      }
      else
      {
        v9 = w1;
        v10 = w2;
      }
      if ( v7 <= -0.001
        || v7 >= 0.001
        || v8 <= -0.001
        || v8 >= 0.001
        || v9 <= -0.001
        || v9 >= 0.001
        || v10 <= -0.001
        || v10 >= 0.001 )
      {
        v13 = (mstudiovertanim_wrinkle_t *)((char *)v5 + v5->vertindex);
        p_m_VertexCache = &this->m_VertexCache;
        m_pStudioHdr = this->m_pStudioHdr;
        if ( v5->vertanimtype != 0 )
          CCachedRenderData::ComputeFlexedVertexWrinkle_StreamOffset_Optimized(
            this: p_m_VertexCache,
            pStudioHdr: m_pStudioHdr,
            pflex: v5,
            pvanim: v13,
            vertCount,
            w1: v7,
            w2: v8,
            w3: v9,
            w4: v10);
        else
          CCachedRenderData::ComputeFlexedVertex_StreamOffset_Optimized(
            this: p_m_VertexCache,
            pStudioHdr: m_pStudioHdr,
            pflex: v5,
            pvanim: v13,
            vertCount,
            w1: v7,
            w2: v8,
            w3: v9,
            w4: v10);
      }
      ++v5;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10009510
// Name: private: int CStudioRender::R_StudioDrawGroupHWSkin(class IMatRenderContext __near *,struct studiomeshgroup_t __near *,class IMesh __near *,struct ColorMeshInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioDrawGroupHWSkin(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        studiomeshgroup_t *pGroup,
        IMesh *pMesh,
        ColorMeshInfo_t *pColorMeshInfo)
{
  bool v6; // zf
  IMatRenderContext *v7; // edi
  IMesh *v8; // ebx
  OptimizedModel::StripHeader_t *v9; // esi
  int i; // edi
  int v11; // eax
  int v12; // ecx
  IMesh_vtbl *v13; // edi
  int PrimitiveTypeForStripHeaderFlags; // eax
  Vector4D vecDiffuseModulation; // [esp+Ch] [ebp-1Ch] BYREF
  int j; // [esp+1Ch] [ebp-Ch]
  CStudioRender *v18; // [esp+20h] [ebp-8h]
  int numFacesRendered; // [esp+24h] [ebp-4h]
  ColorMeshInfo_t *pColorMeshInfoa; // [esp+3Ch] [ebp+14h]

  v6 = this->m_pStudioHdr->numbones == 1;
  v7 = pRenderContext;
  v18 = this;
  numFacesRendered = 0;
  if ( v6 )
  {
    pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
    pRenderContext->LoadMatrix(this: pRenderContext, a2: this->m_PoseToWorld);
    pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: 0);
  }
  v8 = pMesh;
  if ( pColorMeshInfo != nullptr )
    pMesh->SetColorMesh(this: pMesh, a2: pColorMeshInfo->m_pMesh, a3: pColorMeshInfo->m_nVertOffsetInBytes);
  else
    pMesh->SetColorMesh(this: pMesh, a2: nullptr, a3: 0);
  CStudioRender::ComputeDiffuseModulation(this, pDiffuseModulation: &vecDiffuseModulation);
  j = 0;
  if ( pGroup->m_NumStrips > 0 )
  {
    pColorMeshInfoa = nullptr;
    while ( 1 )
    {
      v9 = (OptimizedModel::StripHeader_t *)((char *)pColorMeshInfoa + (unsigned int)pGroup->m_pStripData);
      if ( v18->m_pStudioHdr->numbones > 1 )
      {
        v7->SetNumBoneWeights(this: v7, a2: v9->numBones);
        for ( i = 0; i < v9->numBoneStateChanges; ++i )
        {
          v11 = v9->boneStateChangeOffset + 8 * i;
          v12 = *(int *)((char *)&v9->indexOffset + v11);
          if ( v12 < 0 )
            break;
          pRenderContext->LoadBoneMatrix(
            this: pRenderContext,
            a2: *(int *)((char *)&v9->numIndices + v11),
            a3: &v18->m_PoseToWorld[v12]);
          v8 = pMesh;
        }
      }
      v13 = v8->IVertexBuffer::__vftable;
      PrimitiveTypeForStripHeaderFlags = GetPrimitiveTypeForStripHeaderFlags(Flags: v9->flags);
      v13->SetPrimitiveType(this: v8, a2: (MaterialPrimitiveType_t)PrimitiveTypeForStripHeaderFlags);
      v8->DrawModulated(this: v8, a2: &vecDiffuseModulation, a3: v9->indexOffset, a4: v9->numIndices);
      numFacesRendered += pGroup->m_pUniqueFaces[j];
      pColorMeshInfoa = (ColorMeshInfo_t *)((char *)pColorMeshInfoa + 35);
      if ( ++j >= pGroup->m_NumStrips )
        break;
      v7 = pRenderContext;
    }
  }
  v8->SetColorMesh(this: v8, a2: nullptr, a3: 0);
  return numFacesRendered;
}

//------------------------------------------------------------------------------
// Address: 0x10009680
// Name: private: void CStudioRender::ComputeFlexWeights(int,struct mstudioflex_t __near *,struct MorphWeight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ComputeFlexWeights(
        CStudioRender *this,
        int nFlexCount,
        mstudioflex_t *pFlex,
        MorphWeight_t *pWeights)
{
  float *v6; // ebx
  int flexpair; // eax
  float pWeightsa; // [esp+20h] [ebp+10h]

  if ( nFlexCount > 0 )
  {
    v6 = &pWeights->m_pWeight[2];
    do
    {
      *(v6 - 2) = CStudioRender::RampFlexWeight(this, flex: pFlex, w: this->m_pFlexWeights[pFlex->flexdesc]);
      pWeightsa = CStudioRender::RampFlexWeight(this, flex: pFlex, w: this->m_pFlexDelayedWeights[pFlex->flexdesc]);
      *(v6 - 1) = pWeightsa;
      flexpair = pFlex->flexpair;
      if ( flexpair != 0 )
      {
        *v6 = CStudioRender::RampFlexWeight(this, flex: pFlex, w: this->m_pFlexWeights[flexpair]);
        v6[1] = CStudioRender::RampFlexWeight(this, flex: pFlex, w: this->m_pFlexDelayedWeights[pFlex->flexpair]);
      }
      else
      {
        *v6 = *(v6 - 2);
        v6[1] = pWeightsa;
      }
      v6 += 4;
      ++pFlex;
      --nFlexCount;
    }
    while ( nFlexCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009750
// Name: private: void CStudioRender::SetEyeMaterialVars(class IMaterial __near *,struct mstudioeyeball_t __near *,class Vector const __near &,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::SetEyeMaterialVars(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        IMaterial *pMaterial,
        mstudioeyeball_t *peyeball,
        const Vector *eyeOrigin,
        const matrix3x4_t *irisTransform,
        const matrix3x4_t *glintTransform)
{
  IMaterialVar *v7; // eax
  IMaterialVar *v8; // eax
  int v9; // eax
  IMaterialVar *v10; // eax
  IMaterialVar *v11; // eax
  int v12; // eax

  if ( pMaterial != nullptr )
  {
    v7 = pMaterial->FindVarFast(this: pMaterial, a2: "$eyeorigin", a3: &eyeOriginCache);
    if ( v7 != nullptr )
      v7->SetVecValue_4(this: v7, a2: &eyeOrigin->x, a3: 3);
    v8 = pMaterial->FindVarFast(this: pMaterial, a2: "$eyeup", a3: &eyeUpCache);
    if ( v8 != nullptr )
      v8->SetVecValue_4(this: v8, a2: &peyeball->up.x, a3: 3);
    v9 = ((int (__thiscall *)(IMaterial *, const char *, unsigned int *, int))pMaterial->FindVarFast)(
           a1: pMaterial,
           a2: "$irisu",
           a3: &irisUCache,
           a4: a2);
    if ( v9 != 0 )
      (*(void (__thiscall **)(int, const matrix3x4_t *, int))(*(_DWORD *)v9 + 52))(a1: v9, a2: irisTransform, a3: 4);
    v10 = pMaterial->FindVarFast(this: pMaterial, a2: "$irisv", a3: &irisVCache);
    if ( v10 != nullptr )
      v10->SetVecValue_4(this: v10, a2: irisTransform->m_flMatVal[1], a3: 4);
    v11 = pMaterial->FindVarFast(this: pMaterial, a2: "$glintu", a3: &glintUCache);
    if ( v11 != nullptr )
      v11->SetVecValue_4(this: v11, a2: (const float *)glintTransform, a3: 4);
    v12 = ((int (__thiscall *)(IMaterial *, const char *))pMaterial->FindVarFast)(a1: pMaterial, a2: "$glintv");
    if ( v12 != 0 )
      (*(void (__thiscall **)(int, float *, int))(*(_DWORD *)v12 + 52))(
        a1: v12,
        a2: glintTransform->m_flMatVal[1],
        a3: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009860
// Name: public: void CVertexBuilder::CompressedNormal3f<1>(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::CompressedNormal3f<1>(CVertexBuilder *this, float nx, float ny, float nz)
{
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm7_4

  v4 = -1.0;
  if ( nx >= 0.0 )
    v5 = 1.0;
  else
    v5 = -1.0;
  if ( ny >= 0.0 )
    v6 = 1.0;
  else
    v6 = -1.0;
  if ( nz >= 0.0 )
    v4 = 1.0;
  v7 = (float)((float)(v6 * ny) + (float)(v5 * nx)) + (float)(v4 * nz);
  *(_DWORD *)this->m_pCurrNormal = (unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)((float)((float)(1.0 / v7) * (float)(v5 * nx)) * 63.0) * v5)
                                                                                               - (float)((float)(1.0 - v5) * 0.5))
                                                                                       + 64.0)
                                                                               * v4)
                                                                       - (float)((float)(1.0 - v4) * 0.5))
                                                               + 128.0)
                                 | ((unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)(1.0 / v7) * (float)(v6 * ny))
                                                                                                * 63.0)
                                                                                        * v6)
                                                                                - (float)((float)(1.0 - v6) * 0.5))
                                                                        + 64.0)
                                                                + 128.0) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x10009970
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x100099F0
// Name: public: void CMeshBuilder::BeginModify(class IMesh __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::BeginModify(
        CMeshBuilder *this,
        IMesh *pMesh,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount)
{
  if ( nVertexCount < 0 )
    nVertexCount = pMesh->VertexCount(this: pMesh);
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->ModifyBeginEx(
    this: pMesh,
    a2: false,
    a3: nFirstVertex,
    a4: nVertexCount,
    a5: nFirstIndex,
    a6: nIndexCount,
    a7: this);
  this->m_IndexBuilder.m_nIndexCount = nIndexCount;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_VertexBuilder.m_pVertexBuffer = pMesh;
  qmemcpy(&this->m_VertexBuilder, this, 0xA4u);
  this->m_VertexBuilder.m_nVertexCount = nVertexCount;
  this->m_VertexBuilder.m_nMaxVertexCount = nVertexCount;
  this->m_VertexBuilder.m_NumBoneWeights = this->m_VertexBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  this->m_VertexBuilder.m_bModify = true;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10009AE0
// Name: struct mstudio_meshvertexdata_t const __near * GetFatVertexData(struct mstudiomesh_t __near *,struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__cdecl GetFatVertexData(mstudiomesh_t *pMesh, studiohdr_t *pStudioHdr)
{
  const vertexFileHeader_t *result; // eax
  const mstudio_modelvertexdata_t *v3; // eax
  mstudio_meshvertexdata_t *p_vertexdata; // esi
  unsigned int v5; // ecx

  result = mstudiomodel_t::CacheVertexData(
             this: (mstudiomodel_t *)((char *)pMesh + pMesh->modelindex),
             pModelData: pStudioHdr);
  if ( result != nullptr )
  {
    mstudiomodel_t::GetVertexData(this: (mstudiomodel_t *)((char *)pMesh + pMesh->modelindex), pModelData: pStudioHdr);
    v3 = (const mstudio_modelvertexdata_t *)((char *)&pMesh->unused[6] + pMesh->modelindex);
    pMesh->vertexdata.modelvertexdata = v3;
    if ( v3->pVertexData != nullptr )
    {
      p_vertexdata = &pMesh->vertexdata;
      if ( pMesh != (mstudiomesh_t *)-48 )
        return (const vertexFileHeader_t *)p_vertexdata;
    }
    else
    {
      p_vertexdata = nullptr;
    }
    v5 = `GetFatVertexData'::`8'::warnCount++;
    if ( v5 < 0x14 )
      _Warning(
        a1: "ERROR: model verts have been compressed or you don't have them in memory on a console, cannot render! (use \"-no"
        "_compressed_vvds\")");
    return (const vertexFileHeader_t *)p_vertexdata;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009B50
// Name: private: void CStudioRender::R_StudioSoftwareProcessMesh(struct mstudiomesh_t __near *,class CMeshBuilder __near &,int,unsigned short __near *,enum StudioModelLighting_t,bool,float,bool,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioSoftwareProcessMesh(
        CStudioRender *this,
        mstudiomesh_t *pmesh,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh,
        StudioModelLighting_t lighting,
        bool doFlex,
        float r_blend,
        bool bNeedsTangentSpace,
        IMaterial *pMaterial)
{
  unsigned int v11; // esi
  const vertexFileHeader_t *FatVertexData; // eax

  v11 = (int)(float)(r_blend * 255.0);
  if ( v11 > 0xFF )
    v11 = 255;
  FatVertexData = GetFatVertexData(pMesh: pmesh, pStudioHdr: this->m_pStudioHdr);
  if ( FatVertexData != nullptr )
    (*(&g_SoftwareProcessMeshFunc[4 * bNeedsTangentSpace] + 2 * bNeedsTangentSpace + 2 * doFlex + doFlex + lighting))(
      a1: (const mstudio_meshvertexdata_t *)FatVertexData,
      a2: this->m_PoseToWorld,
      a3: &this->m_VertexCache,
      a4: meshBuilder,
      a5: numVertices,
      a6: pGroupToMesh,
      a7: v11 << 24,
      a8: pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10009BF0
// Name: private: void CStudioRender::R_StudioSoftwareProcessMesh_Normals(struct mstudiomesh_t __near *,class CMeshBuilder __near &,int,unsigned short __near *,enum StudioModelLighting_t,bool,float,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::R_StudioSoftwareProcessMesh_Normals(
        CStudioRender *this@<ecx>,
        Vector4D *a2@<ebp>,
        mstudiomesh_t *pmesh,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh,
        StudioModelLighting_t lighting,
        bool doFlex,
        float r_blend,
        bool bShowNormals,
        bool bShowTangentS,
        bool bShowTangentT)
{
  studiohdr_t *m_pStudioHdr; // eax
  const vertexFileHeader_t *FatVertexData; // eax
  _DWORD *id; // esi
  int v15; // edi
  unsigned int v16; // ecx
  float v17; // eax
  mstudioboneweight_t *v18; // edi
  Vector *v19; // eax
  float *v20; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  float *p_x; // ecx
  float z; // edi
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm7_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  float v33; // xmm2_4
  float v34; // xmm2_4
  float v35; // xmm4_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm5_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm6_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm6_4
  float v50; // xmm3_4
  float v51; // xmm7_4
  float v52; // xmm6_4
  float v53; // xmm4_4
  float v54; // xmm7_4
  float v55; // xmm6_4
  float v56; // xmm5_4
  float v57; // xmm6_4
  float v58; // xmm5_4
  float v59; // xmm1_4
  float v60; // xmm3_4
  float v61; // xmm4_4
  float v62; // xmm7_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm7_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm7_4
  float v69; // xmm5_4
  float v70; // xmm2_4
  float v71; // xmm4_4
  float v72; // xmm2_4
  float v73; // xmm6_4
  float v74; // xmm2_4
  float *m_pCurrPosition; // eax
  float *v76; // eax
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm0_4
  float v80; // xmm1_4
  float v81; // xmm2_4
  float *v82; // eax
  float *v83; // eax
  float v84; // xmm1_4
  float v85; // xmm2_4
  float v86; // xmm0_4
  float v87; // xmm1_4
  float v88; // xmm2_4
  float *v89; // eax
  float *v90; // eax
  float v91; // xmm1_4
  float v92; // xmm2_4
  float v93; // xmm0_4
  float v94; // xmm2_4
  float v95; // xmm1_4
  int v96; // [esp-Ch] [ebp-15Ch] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-150h]
  float v98; // [esp+40h] [ebp-110h]
  float v99; // [esp+44h] [ebp-10Ch]
  float v100; // [esp+48h] [ebp-108h]
  Vector vTangentSPos; // [esp+4Ch] [ebp-104h]
  Vector vTangentTPos; // [esp+58h] [ebp-F8h]
  Vector normalPos; // [esp+64h] [ebp-ECh] BYREF
  Vector4D tang; // [esp+70h] [ebp-E0h]
  int v105; // [esp+80h] [ebp-D0h]
  int v106; // [esp+84h] [ebp-CCh]
  int v107; // [esp+88h] [ebp-C8h]
  int v108; // [esp+8Ch] [ebp-C4h]
  int v109; // [esp+90h] [ebp-C0h]
  int v110; // [esp+94h] [ebp-BCh]
  int v111; // [esp+98h] [ebp-B8h]
  unsigned int v112; // [esp+9Ch] [ebp-B4h]
  int v113; // [esp+A0h] [ebp-B0h]
  int v114; // [esp+A4h] [ebp-ACh]
  mstudiovertex_t *pVertices; // [esp+A8h] [ebp-A8h]
  int v116; // [esp+ACh] [ebp-A4h]
  int v117; // [esp+B0h] [ebp-A0h]
  int v118; // [esp+B4h] [ebp-9Ch]
  int v119; // [esp+B8h] [ebp-98h]
  int v120; // [esp+BCh] [ebp-94h]
  int v121; // [esp+C0h] [ebp-90h]
  float v122; // [esp+C4h] [ebp-8Ch]
  float v123; // [esp+C8h] [ebp-88h]
  float v124; // [esp+CCh] [ebp-84h]
  float v125; // [esp+E0h] [ebp-70h]
  float v126; // [esp+E4h] [ebp-6Ch]
  float v127; // [esp+E8h] [ebp-68h]
  float v128; // [esp+ECh] [ebp-64h]
  float v129; // [esp+100h] [ebp-50h]
  float v130; // [esp+104h] [ebp-4Ch]
  float v131; // [esp+108h] [ebp-48h]
  float v132; // [esp+10Ch] [ebp-44h]
  int v133; // [esp+110h] [ebp-40h]
  float v134; // [esp+114h] [ebp-3Ch]
  int v135; // [esp+118h] [ebp-38h]
  Vector4D *pTangentS; // [esp+11Ch] [ebp-34h]
  CStudioRender *v137; // [esp+120h] [ebp-30h]
  int j; // [esp+124h] [ebp-2Ch]
  float v139; // [esp+128h] [ebp-28h]
  float v140; // [esp+12Ch] [ebp-24h]
  VectorAligned pos; // [esp+130h] [ebp-20h]
  float v142; // [esp+140h] [ebp-10h]
  Vector4D *pSrcTangentS; // [esp+144h] [ebp-Ch]
  void *v144; // [esp+148h] [ebp-8h]
  void *retaddr; // [esp+150h] [ebp+0h]

  pSrcTangentS = a2;
  v144 = retaddr;
  m_pStudioHdr = this->m_pStudioHdr;
  v137 = this;
  pos.z = 0.0;
  FatVertexData = GetFatVertexData(pMesh: pmesh, pStudioHdr: m_pStudioHdr);
  if ( FatVertexData != nullptr )
  {
    id = (_DWORD *)FatVertexData->id;
    if ( *(_DWORD *)(FatVertexData->id + 4) == 0 )
    {
      bShowTangentT = false;
      bShowTangentS = false;
    }
    v15 = FatVertexData[-1].numLODVertexes[3];
    v16 = *id + 48 * (v15 + *(id - 6) / 0x30u);
    v112 = v16;
    v133 = 0;
    if ( bShowTangentS || bShowTangentT )
      v133 = id[1] + 16 * (v15 + (*(id - 5) >> 4));
    v135 = 0;
    if ( numVertices > 0 )
    {
      while ( 1 )
      {
        LODWORD(v17) = pGroupToMesh[v135];
        v18 = (mstudioboneweight_t *)(v16 + 48 * LODWORD(v17));
        v142 = v17;
        if ( bShowTangentS || bShowTangentT )
        {
          v19 = (Vector *)(v133 + 16 * LODWORD(v17));
          normalPos = *v19;
          tang.x = v19[1].x;
        }
        v20 = (float *)ComputeSkinMatrix(
                         boneweights: v18,
                         pPoseToWorld: v137->m_PoseToWorld,
                         scratchMatrix: (matrix3x4_t *)&v96);
        m_pFirstFlexIndex = v137->m_VertexCache.m_pFirstFlexIndex;
        if ( m_pFirstFlexIndex != nullptr && m_pFirstFlexIndex[LODWORD(v142)].m_Tag == v137->m_VertexCache.m_CurrentTag )
        {
          p_x = &v137->m_VertexCache.m_pFlexVerts[v137->m_VertexCache.m_pFirstFlexIndex[LODWORD(v142)].m_VertexIndex].m_Position.x;
          LODWORD(v142) = &v137->m_VertexCache.m_pFlexVerts[v137->m_VertexCache.m_pFirstFlexIndex[LODWORD(v142)].m_VertexIndex].m_Normal;
          if ( !bShowTangentS && !bShowTangentT )
            goto LABEL_25;
          LODWORD(z) = p_x + 8;
          LODWORD(pos.z) = p_x + 8;
        }
        else
        {
          p_x = v18[1].weight;
          LODWORD(v142) = v18[1].bone;
          if ( !bShowTangentS && !bShowTangentT )
          {
LABEL_25:
            z = pos.z;
            goto LABEL_26;
          }
          LODWORD(pos.z) = &normalPos;
          z = COERCE_FLOAT(&normalPos);
        }
        if ( (bShowTangentS || bShowTangentT) && z != 0.0 )
        {
          v24 = p_x[1];
          v25 = *p_x;
          v26 = *v20;
          v27 = v20[1];
          v28 = v20[2];
          v125 = p_x[2];
          v29 = *(float *)(LODWORD(v142) + 4);
          pos.w = *(float *)LODWORD(v142);
          pTangentS = *(Vector4D **)(LODWORD(v142) + 8);
          v131 = v29;
          v30 = (float)((float)((float)(v26 * v25) + (float)(v24 * v27)) + (float)(v125 * v28)) + v20[3];
          v31 = (float)((float)(pos.w * v26) + (float)(v29 * v27)) + (float)(*(float *)&pTangentS * v28);
          v32 = *(float *)(LODWORD(z) + 4) * v27;
          v33 = *(float *)(LODWORD(z) + 8);
          v126 = v31;
          v34 = v33 * v28;
          v35 = v20[6];
          v36 = *(float *)LODWORD(z) * v26;
          v37 = v20[5];
          v134 = v25;
          v38 = (float)(v36 + v32) + v34;
          v39 = v20[4];
          v122 = v38;
          tang.w = v24;
          v40 = (float)((float)((float)(v39 * v25) + (float)(v37 * v24)) + (float)(v35 * v125)) + v20[7];
          v41 = (float)(v39 * pos.w) + (float)(v37 * v131);
          v42 = (float)(v39 * *(float *)LODWORD(z)) + (float)(v37 * *(float *)(LODWORD(z) + 4));
          v43 = v20[8];
          v44 = v35 * *(float *)&pTangentS;
          v45 = v42 + (float)(v35 * *(float *)(LODWORD(z) + 8));
          v46 = v20[9];
          v123 = v45;
          v127 = v41 + v44;
          v47 = v20[10];
          *(float *)&j = v30;
          v139 = v40;
          v48 = (float)((float)(v43 * v134) + (float)(v46 * tang.w)) + (float)(v47 * v125);
          v49 = v43 * pos.w;
          v50 = v43 * *(float *)LODWORD(z);
          v142 = v49;
          v51 = v49;
          v52 = v46 * v131;
          v53 = v46 * *(float *)(LODWORD(z) + 4);
          v54 = v51 + v52;
          v55 = v47 * *(float *)&pTangentS;
          v56 = v47 * *(float *)(LODWORD(z) + 8);
          v142 = v54;
          v128 = v54 + v55;
          v124 = (float)(v50 + v53) + v56;
          goto LABEL_27;
        }
LABEL_26:
        v57 = p_x[1];
        v58 = *p_x;
        v59 = *v20;
        v60 = v20[4];
        v61 = v20[6];
        v130 = p_x[2];
        v62 = *(float *)LODWORD(v142);
        v30 = (float)((float)((float)(v57 * v20[1]) + (float)(v59 * v58)) + (float)(v130 * v20[2])) + v20[3];
        v129 = *(float *)(LODWORD(v142) + 4);
        v63 = v129 * v20[1];
        pos.w = v62;
        v132 = *(float *)(LODWORD(v142) + 8);
        v126 = (float)(v63 + (float)(v59 * v62)) + (float)(v132 * v20[2]);
        v64 = v20[5];
        v65 = v60;
        v66 = (float)(v64 * v129) + (float)(v60 * pos.w);
        v67 = v20[9];
        v134 = v58;
        v68 = v65 * v58;
        v69 = v61 * v130;
        v70 = v66 + (float)(v61 * v132);
        v71 = v20[8];
        v127 = v70;
        v40 = (float)((float)((float)(v64 * v57) + v68) + v69) + v20[7];
        v72 = (float)(v67 * v57) + (float)(v71 * v134);
        v73 = v20[10];
        *(float *)&j = v30;
        v139 = v40;
        v48 = v72 + (float)(v73 * v130);
        v128 = (float)((float)(v67 * v129) + (float)(v71 * pos.w)) + (float)(v73 * v132);
LABEL_27:
        v74 = v48 + v20[11];
        v140 = v74;
        if ( bShowNormals )
        {
          m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
          *m_pCurrPosition = v30;
          m_pCurrPosition[1] = v40;
          m_pCurrPosition[2] = v74;
          v119 = 1258291455;
          v105 = 1258291200;
          tang.y = 8388608.0;
          *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
          v76 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
          v77 = v127;
          v78 = v128;
          v79 = (float)(v126 * 0.5) + *(float *)&j;
          *v76 = v79;
          vTangentTPos.x = v79;
          v80 = (float)(v77 * 0.5) + v139;
          v76[1] = v80;
          v81 = (float)(v78 * 0.5) + v140;
          v76[2] = v81;
          vTangentTPos.y = v80;
          vTangentTPos.z = v81;
          v121 = 1258291455;
          v117 = 1258291200;
          tang.z = 8388608.0;
          *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
          v74 = v140;
          v40 = v139;
          v30 = *(float *)&j;
        }
        if ( (bShowTangentS || bShowTangentT) && z != 0.0 )
        {
          if ( bShowTangentS )
          {
            v82 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            *v82 = v30;
            v82[1] = v40;
            v82[2] = v74;
            v113 = 1258291200;
            v111 = 1258291200;
            pVertices = (mstudiovertex_t *)1258291455;
            *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -65536;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
            v83 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            v84 = v123;
            v85 = v124;
            v86 = (float)(v122 * 0.5) + *(float *)&j;
            *v83 = v86;
            v98 = v86;
            v87 = (float)(v84 * 0.5) + v139;
            v83[1] = v87;
            v88 = (float)(v85 * 0.5) + v140;
            v83[2] = v88;
            v99 = v87;
            v100 = v88;
            v110 = 1258291200;
            v107 = 1258291200;
            v109 = 1258291455;
            *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -65536;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
            v74 = v140;
            v40 = v139;
            v30 = *(float *)&j;
          }
          if ( bShowTangentT )
          {
            v89 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            *v89 = v30;
            v89[1] = v40;
            v89[2] = v74;
            v120 = 1258291200;
            v108 = 1258291455;
            v106 = 1258291200;
            *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -16711936;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
            v90 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            v91 = (float)(v123 * v126) - (float)(v127 * v122);
            temp.m_flMatVal[2][1] = (float)(v124 * v127) - (float)(v123 * v128);
            temp.m_flMatVal[2][3] = v91;
            v92 = (float)(v128 * v122) - (float)(v124 * v126);
            temp.m_flMatVal[2][2] = v92;
            v93 = (float)(temp.m_flMatVal[2][1] * 0.5) + *(float *)&j;
            *v90 = v93;
            vTangentSPos.x = v93;
            v94 = (float)(v92 * 0.5) + v139;
            v90[1] = v94;
            v95 = (float)(v91 * 0.5) + v140;
            v90[2] = v95;
            vTangentSPos.z = v95;
            vTangentSPos.y = v94;
            v114 = 1258291200;
            v116 = 1258291455;
            v118 = 1258291200;
            *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -16711936;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
          }
        }
        if ( ++v135 >= numVertices )
          return;
        v16 = v112;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A4D0
// Name: public: static void CProcessMeshWrapper<0,0,0>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,0,0>::R_StudioSoftwareProcessMesh(
        mstudiovertex_t *a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // esi
  unsigned int v8; // ecx
  int i; // edx
  float v10; // eax
  unsigned __int16 *v11; // edx
  float *v12; // edi
  unsigned int v13; // esi
  float *v14; // eax
  int v15; // edi
  unsigned int v16; // edx
  float *m_pCurrPosition; // ecx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  int v20; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  float *v24; // [esp+80h] [ebp-20h]
  int v25; // [esp+84h] [ebp-1Ch]
  unsigned int v26; // [esp+88h] [ebp-18h]
  int v27; // [esp+8Ch] [ebp-14h]
  unsigned __int16 *fIllum; // [esp+90h] [ebp-10h]
  mstudiovertex_t *pVertices; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int retaddr; // [esp+A0h] [ebp+0h]

  pVertices = a1;
  j = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  v26 = v8;
  v25 = 1065353216;
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  v27 = 0;
  if ( numVertices > 0 )
  {
    v11 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    fIllum = pGroupToMesh + 4;
    while ( 1 )
    {
      _mm_prefetch((const char *)((unsigned int)(v11 + 1) & 0xFFFFFFE0), 0);
      v12 = &temp.m_flMatVal[2][(v27 & 3) + 2];
      v13 = v8 + 48 * *(_DWORD *)v12;
      *(_DWORD *)v12 = *v11;
      v14 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v13,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v20);
      forward.x = (float)((float)((float)(v14[1] * *(float *)(v13 + 20)) + (float)(*(float *)(v13 + 16) * *v14))
                        + (float)(*(float *)(v13 + 24) * v14[2]))
                + v14[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v13 + 28) * *v14) + (float)(*(float *)(v13 + 32) * v14[1]))
                                + (float)(*(float *)(v13 + 36) * v14[2]);
      forward.y = (float)((float)((float)(*(float *)(v13 + 16) * v14[4]) + (float)(*(float *)(v13 + 20) * v14[5]))
                        + (float)(*(float *)(v13 + 24) * v14[6]))
                + v14[7];
      v15 = *(_DWORD *)v12;
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v13 + 32) * v14[5]) + (float)(*(float *)(v13 + 28) * v14[4]))
                                + (float)(*(float *)(v13 + 36) * v14[6]);
      v16 = v26;
      forward.z = (float)((float)((float)(v14[9] * *(float *)(v13 + 20)) + (float)(v14[8] * *(float *)(v13 + 16)))
                        + (float)(*(float *)(v13 + 24) * v14[10]))
                + v14[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v13 + 32) * v14[9]) + (float)(v14[8] * *(float *)(v13 + 28)))
                                + (float)(*(float *)(v13 + 36) * v14[10]);
      _mm_prefetch((const char *)(v26 + 48 * v15), 0);
      _mm_prefetch((const char *)(v16 + 48 * v15 + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = *(float *)(v13 + 40);
      dstVertex.m_vecNormal.y = *(float *)(v13 + 44);
      v24 = m_pCurrPosition;
      v18 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v19 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v18);
      _mm_stream_ps(m_pCurrPosition + 8, v19);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++fIllum;
      if ( ++v27 >= numVertices )
        break;
      v11 = fIllum;
      v8 = v26;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000A760
// Name: public: static void CProcessMeshWrapper<0,0,1>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,0,1>::R_StudioSoftwareProcessMesh(
        mstudiovertex_t *a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  unsigned int v8; // esi
  int i; // ecx
  float v10; // eax
  unsigned __int16 *v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  float *v14; // edi
  unsigned int v15; // esi
  float *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  float *m_pCurrPosition; // ecx
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  int v22; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  float *v26; // [esp+80h] [ebp-20h]
  int v27; // [esp+84h] [ebp-1Ch]
  unsigned int v28; // [esp+88h] [ebp-18h]
  int v29; // [esp+8Ch] [ebp-14h]
  unsigned __int16 *fIllum; // [esp+90h] [ebp-10h]
  mstudiovertex_t *pVertices; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int retaddr; // [esp+A0h] [ebp+0h]

  pVertices = a1;
  j = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  v28 = v8;
  v27 = 1065353216;
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  v29 = 0;
  if ( numVertices > 0 )
  {
    v11 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( fIllum = pGroupToMesh + 4; ; v11 = fIllum )
    {
      v12 = (unsigned int)(v11 + 1);
      v13 = *v11;
      _mm_prefetch((const char *)(v12 & 0xFFFFFFE0), 0);
      v14 = &temp.m_flMatVal[2][(v29 & 3) + 2];
      v15 = v28 + 48 * *(_DWORD *)v14;
      *(_DWORD *)v14 = v13;
      v16 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v22);
      forward.x = (float)((float)((float)(v16[1] * *(float *)(v15 + 20)) + (float)(*(float *)(v15 + 16) * *v16))
                        + (float)(*(float *)(v15 + 24) * v16[2]))
                + v16[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v15 + 28) * *v16) + (float)(*(float *)(v15 + 32) * v16[1]))
                                + (float)(*(float *)(v15 + 36) * v16[2]);
      forward.y = (float)((float)((float)(*(float *)(v15 + 16) * v16[4]) + (float)(*(float *)(v15 + 20) * v16[5]))
                        + (float)(*(float *)(v15 + 24) * v16[6]))
                + v16[7];
      v17 = *(_DWORD *)v14;
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v15 + 32) * v16[5]) + (float)(*(float *)(v15 + 28) * v16[4]))
                                + (float)(*(float *)(v15 + 36) * v16[6]);
      v18 = v28;
      forward.z = (float)((float)((float)(v16[9] * *(float *)(v15 + 20)) + (float)(v16[8] * *(float *)(v15 + 16)))
                        + (float)(*(float *)(v15 + 24) * v16[10]))
                + v16[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v15 + 32) * v16[9]) + (float)(v16[8] * *(float *)(v15 + 28)))
                                + (float)(*(float *)(v15 + 36) * v16[10]);
      _mm_prefetch((const char *)(v28 + 48 * v17), 0);
      _mm_prefetch((const char *)(v18 + 48 * v17 + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = *(float *)(v15 + 40);
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      v26 = m_pCurrPosition;
      v20 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v21 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v20);
      _mm_stream_ps(m_pCurrPosition + 8, v21);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++fIllum;
      if ( ++v29 >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA00
// Name: public: static void CProcessMeshWrapper<0,0,2>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,0,2>::R_StudioSoftwareProcessMesh(
        float a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  unsigned int v8; // esi
  int i; // ecx
  float v10; // eax
  unsigned __int16 *v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  float *v14; // edi
  unsigned int v15; // esi
  float *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  float *m_pCurrPosition; // ecx
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  int v22; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  int ntemp[4]; // [esp+34h] [ebp-6Ch] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  float *v27; // [esp+80h] [ebp-20h]
  unsigned int v28; // [esp+84h] [ebp-1Ch]
  float v29; // [esp+88h] [ebp-18h] BYREF
  unsigned __int16 *j; // [esp+8Ch] [ebp-14h]
  mstudiovertex_t *pVertices; // [esp+90h] [ebp-10h]
  float fIllum; // [esp+94h] [ebp-Ch]
  void *v33; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  fIllum = a1;
  v33 = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  v28 = v8;
  v29 = 1.0;
  CStudioRender::R_MouthComputeLightingValues(this: &g_StudioRender, fIllum: &v29, forward: (Vector *)&ntemp[1]);
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  pVertices = nullptr;
  if ( numVertices > 0 )
  {
    v11 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( j = pGroupToMesh + 4; ; v11 = j )
    {
      v12 = (unsigned int)(v11 + 1);
      v13 = *v11;
      _mm_prefetch((const char *)(v12 & 0xFFFFFFE0), 0);
      v14 = &temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      v15 = v28 + 48 * *(_DWORD *)v14;
      *(_DWORD *)v14 = v13;
      v16 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v22);
      forward.x = (float)((float)((float)(v16[1] * *(float *)(v15 + 20)) + (float)(*(float *)(v15 + 16) * *v16))
                        + (float)(*(float *)(v15 + 24) * v16[2]))
                + v16[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v15 + 28) * *v16) + (float)(*(float *)(v15 + 32) * v16[1]))
                                + (float)(*(float *)(v15 + 36) * v16[2]);
      forward.y = (float)((float)((float)(*(float *)(v15 + 16) * v16[4]) + (float)(*(float *)(v15 + 20) * v16[5]))
                        + (float)(*(float *)(v15 + 24) * v16[6]))
                + v16[7];
      v17 = *(_DWORD *)v14;
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v15 + 32) * v16[5]) + (float)(*(float *)(v15 + 28) * v16[4]))
                                + (float)(*(float *)(v15 + 36) * v16[6]);
      v18 = v28;
      forward.z = (float)((float)((float)(v16[9] * *(float *)(v15 + 20)) + (float)(v16[8] * *(float *)(v15 + 16)))
                        + (float)(*(float *)(v15 + 24) * v16[10]))
                + v16[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v15 + 32) * v16[9]) + (float)(v16[8] * *(float *)(v15 + 28)))
                                + (float)(*(float *)(v15 + 36) * v16[10]);
      _mm_prefetch((const char *)(v28 + 48 * v17), 0);
      _mm_prefetch((const char *)(v18 + 48 * v17 + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = *(float *)(v15 + 40);
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      v27 = m_pCurrPosition;
      v20 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v21 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v20);
      _mm_stream_ps(m_pCurrPosition + 8, v21);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++j;
      pVertices = (mstudiovertex_t *)((char *)pVertices + 1);
      if ( (int)pVertices >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACB0
// Name: public: static void CProcessMeshWrapper<0,1,0>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,1,0>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  unsigned int v8; // edx
  int i; // ecx
  float v10; // eax
  mstudiovertex_t *v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  float *v14; // edi
  unsigned int v15; // esi
  float *v16; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v18; // ecx
  Vector4D *p_m_Normal; // edx
  float v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // ecx
  float v24; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  int v28; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  unsigned int v32; // [esp+80h] [ebp-20h]
  int v33; // [esp+84h] [ebp-1Ch]
  int v34; // [esp+88h] [ebp-18h]
  mstudiovertex_t *pVertices; // [esp+8Ch] [ebp-14h]
  float fIllum; // [esp+90h] [ebp-10h]
  int j; // [esp+94h] [ebp-Ch]
  void *v38; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  j = a1;
  v38 = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  v32 = v8;
  v33 = 1065353216;
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  v34 = 0;
  if ( numVertices > 0 )
  {
    v11 = (mstudiovertex_t *)(pGroupToMesh + 4);
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    pVertices = (mstudiovertex_t *)(pGroupToMesh + 4);
    while ( 1 )
    {
      v12 = (unsigned int)v11->m_BoneWeights.weight + 2;
      v13 = LOWORD(v11->m_BoneWeights.weight[0]);
      _mm_prefetch((const char *)(v12 & 0xFFFFFFE0), 0);
      v14 = &temp.m_flMatVal[2][(v34 & 3) + 2];
      fIllum = *v14;
      v15 = v8 + 48 * LODWORD(fIllum);
      *(_DWORD *)v14 = v13;
      v16 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v28);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(fIllum)].m_Tag == vertexCache->m_CurrentTag )
      {
        v18 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex].m_Normal;
      }
      else
      {
LABEL_9:
        v18 = (CachedPosNormTan_t *)(v15 + 16);
        p_m_Normal = (Vector4D *)(v15 + 28);
      }
      forward.x = (float)((float)((float)(v18->m_Position.y * v16[1]) + (float)(v18->m_Position.x * *v16))
                        + (float)(v16[2] * v18->m_Position.z))
                + v16[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v16) + (float)(p_m_Normal->y * v16[1]))
                                + (float)(v16[2] * p_m_Normal->z);
      forward.y = (float)((float)((float)(v18->m_Position.y * v16[5]) + (float)(v18->m_Position.x * v16[4]))
                        + (float)(v16[6] * v18->m_Position.z))
                + v16[7];
      v20 = *v14;
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->x * v16[4]) + (float)(v16[5] * p_m_Normal->y))
                                + (float)(v16[6] * p_m_Normal->z);
      v21 = (float)(v18->m_Position.y * v16[9]) + (float)(v18->m_Position.x * v16[8]);
      v22 = v16[10] * v18->m_Position.z;
      v23 = v32;
      forward.z = (float)(v21 + v22) + v16[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->x * v16[8]) + (float)(p_m_Normal->y * v16[9]))
                                + (float)(v16[10] * p_m_Normal->z);
      v24 = *(float *)(v15 + 40);
      _mm_prefetch((const char *)(v32 + 48 * LODWORD(v20)), 0);
      _mm_prefetch((const char *)(v23 + 48 * LODWORD(v20) + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v24;
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      LODWORD(fIllum) = m_pCurrPosition;
      v26 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v27 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v26);
      _mm_stream_ps(m_pCurrPosition + 8, v27);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      pVertices = (mstudiovertex_t *)((char *)pVertices + 2);
      if ( ++v34 >= numVertices )
        break;
      v11 = pVertices;
      v8 = v32;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000AF80
// Name: public: static void CProcessMeshWrapper<0,1,1>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,1,1>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  unsigned int v8; // esi
  int i; // ecx
  float v10; // eax
  mstudiovertex_t *v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  float *v14; // edi
  unsigned int v15; // esi
  float *v16; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v18; // ecx
  Vector4D *p_m_Normal; // edx
  float v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // ecx
  float v24; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  int v28; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  unsigned int v32; // [esp+80h] [ebp-20h]
  int v33; // [esp+84h] [ebp-1Ch]
  int v34; // [esp+88h] [ebp-18h]
  mstudiovertex_t *pVertices; // [esp+8Ch] [ebp-14h]
  float fIllum; // [esp+90h] [ebp-10h]
  int j; // [esp+94h] [ebp-Ch]
  void *v38; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  j = a1;
  v38 = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  v32 = v8;
  v33 = 1065353216;
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  v34 = 0;
  if ( numVertices > 0 )
  {
    v11 = (mstudiovertex_t *)(pGroupToMesh + 4);
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( pVertices = (mstudiovertex_t *)(pGroupToMesh + 4); ; v11 = pVertices )
    {
      v12 = (unsigned int)v11->m_BoneWeights.weight + 2;
      v13 = LOWORD(v11->m_BoneWeights.weight[0]);
      _mm_prefetch((const char *)(v12 & 0xFFFFFFE0), 0);
      v14 = &temp.m_flMatVal[2][(v34 & 3) + 2];
      fIllum = *v14;
      v15 = v32 + 48 * LODWORD(fIllum);
      *(_DWORD *)v14 = v13;
      v16 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v28);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(fIllum)].m_Tag == vertexCache->m_CurrentTag )
      {
        v18 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex].m_Normal;
      }
      else
      {
LABEL_9:
        v18 = (CachedPosNormTan_t *)(v15 + 16);
        p_m_Normal = (Vector4D *)(v15 + 28);
      }
      forward.x = (float)((float)((float)(v18->m_Position.y * v16[1]) + (float)(v18->m_Position.x * *v16))
                        + (float)(v16[2] * v18->m_Position.z))
                + v16[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v16) + (float)(p_m_Normal->y * v16[1]))
                                + (float)(v16[2] * p_m_Normal->z);
      forward.y = (float)((float)((float)(v18->m_Position.y * v16[5]) + (float)(v18->m_Position.x * v16[4]))
                        + (float)(v16[6] * v18->m_Position.z))
                + v16[7];
      v20 = *v14;
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->x * v16[4]) + (float)(v16[5] * p_m_Normal->y))
                                + (float)(v16[6] * p_m_Normal->z);
      v21 = (float)(v18->m_Position.y * v16[9]) + (float)(v18->m_Position.x * v16[8]);
      v22 = v16[10] * v18->m_Position.z;
      v23 = v32;
      forward.z = (float)(v21 + v22) + v16[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->x * v16[8]) + (float)(p_m_Normal->y * v16[9]))
                                + (float)(v16[10] * p_m_Normal->z);
      v24 = *(float *)(v15 + 40);
      _mm_prefetch((const char *)(v32 + 48 * LODWORD(v20)), 0);
      _mm_prefetch((const char *)(v23 + 48 * LODWORD(v20) + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v24;
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      LODWORD(fIllum) = m_pCurrPosition;
      v26 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v27 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v26);
      _mm_stream_ps(m_pCurrPosition + 8, v27);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      pVertices = (mstudiovertex_t *)((char *)pVertices + 2);
      if ( ++v34 >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000B260
// Name: public: static void CProcessMeshWrapper<0,1,2>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<0,1,2>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  unsigned int v8; // esi
  int i; // ecx
  float v10; // eax
  unsigned __int16 *v11; // ecx
  unsigned int v12; // eax
  int v13; // ecx
  float *v14; // edi
  unsigned int v15; // esi
  float *v16; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v18; // ecx
  Vector4D *p_m_Normal; // edx
  float v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  unsigned int v23; // ecx
  float v24; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  int v28; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  int ntemp[4]; // [esp+34h] [ebp-6Ch] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  unsigned int v33; // [esp+80h] [ebp-20h]
  float v34; // [esp+84h] [ebp-1Ch] BYREF
  unsigned __int16 *k; // [esp+88h] [ebp-18h]
  mstudiovertex_t *pVertices; // [esp+8Ch] [ebp-14h]
  float fIllum; // [esp+90h] [ebp-10h]
  int v38; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int retaddr; // [esp+A0h] [ebp+0h]

  v38 = a1;
  j = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v8 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  v33 = v8;
  v34 = 1.0;
  CStudioRender::R_MouthComputeLightingValues(this: &g_StudioRender, fIllum: &v34, forward: (Vector *)&ntemp[1]);
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v10) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v10;
    LODWORD(v10) *= 6;
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10)), 0);
    _mm_prefetch((const char *)(v8 + 8 * LODWORD(v10) + 32), 0);
  }
  pVertices = nullptr;
  if ( numVertices > 0 )
  {
    v11 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( k = pGroupToMesh + 4; ; v11 = k )
    {
      v12 = (unsigned int)(v11 + 1);
      v13 = *v11;
      _mm_prefetch((const char *)(v12 & 0xFFFFFFE0), 0);
      v14 = &temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      fIllum = *v14;
      v15 = v33 + 48 * LODWORD(fIllum);
      *(_DWORD *)v14 = v13;
      v16 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v28);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(fIllum)].m_Tag == vertexCache->m_CurrentTag )
      {
        v18 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(fIllum)].m_VertexIndex].m_Normal;
      }
      else
      {
LABEL_9:
        v18 = (CachedPosNormTan_t *)(v15 + 16);
        p_m_Normal = (Vector4D *)(v15 + 28);
      }
      forward.x = (float)((float)((float)(v18->m_Position.y * v16[1]) + (float)(v18->m_Position.x * *v16))
                        + (float)(v16[2] * v18->m_Position.z))
                + v16[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v16) + (float)(p_m_Normal->y * v16[1]))
                                + (float)(v16[2] * p_m_Normal->z);
      forward.y = (float)((float)((float)(v18->m_Position.y * v16[5]) + (float)(v18->m_Position.x * v16[4]))
                        + (float)(v16[6] * v18->m_Position.z))
                + v16[7];
      v20 = *v14;
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->x * v16[4]) + (float)(v16[5] * p_m_Normal->y))
                                + (float)(v16[6] * p_m_Normal->z);
      v21 = (float)(v18->m_Position.y * v16[9]) + (float)(v18->m_Position.x * v16[8]);
      v22 = v16[10] * v18->m_Position.z;
      v23 = v33;
      forward.z = (float)(v21 + v22) + v16[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->x * v16[8]) + (float)(p_m_Normal->y * v16[9]))
                                + (float)(v16[10] * p_m_Normal->z);
      v24 = *(float *)(v15 + 40);
      _mm_prefetch((const char *)(v33 + 48 * LODWORD(v20)), 0);
      _mm_prefetch((const char *)(v23 + 48 * LODWORD(v20) + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v24;
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      LODWORD(fIllum) = m_pCurrPosition;
      v26 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v27 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v26);
      _mm_stream_ps(m_pCurrPosition + 8, v27);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++k;
      pVertices = (mstudiovertex_t *)((char *)pVertices + 1);
      if ( (int)pVertices >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000B550
// Name: public: static void CProcessMeshWrapper<1,0,0>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,0,0>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // esi
  unsigned int v9; // edx
  float v10; // edi
  int i; // esi
  float v12; // eax
  unsigned __int16 *v13; // ecx
  float v14; // edi
  unsigned int v15; // esi
  int v16; // edx
  float *v17; // eax
  float *v18; // ecx
  unsigned int v19; // edi
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // eax
  float v23; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  int v27; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  unsigned int v31; // [esp+80h] [ebp-20h]
  Vector4D *pStudioTangentS; // [esp+84h] [ebp-1Ch]
  unsigned __int16 *v33; // [esp+88h] [ebp-18h]
  mstudiovertex_t *pVertices; // [esp+8Ch] [ebp-14h]
  float *fIllum; // [esp+90h] [ebp-10h]
  int v36; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int retaddr; // [esp+A0h] [ebp+0h]

  v36 = a1;
  j = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v9 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  LODWORD(v10) = (char *)modelvertexdata->pTangentData
               + 16 * ((_DWORD)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4));
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  v31 = v9;
  dstVertex.m_vecUserData.z = v10;
  pStudioTangentS = (Vector4D *)1065353216;
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v12) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v12;
    _mm_prefetch((const char *)(v9 + 48 * LODWORD(v12)), 0);
    _mm_prefetch((const char *)(v9 + 48 * LODWORD(v12) + 32), 0);
    _mm_prefetch((const char *)(LODWORD(v10) + 16 * LODWORD(v12)), 0);
  }
  pVertices = nullptr;
  if ( numVertices > 0 )
  {
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    v13 = pGroupToMesh + 4;
    v33 = pGroupToMesh + 4;
    while ( 1 )
    {
      _mm_prefetch((const char *)((unsigned int)(v13 + 1) & 0xFFFFFFE0), 0);
      v14 = temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      v15 = v9 + 48 * LODWORD(v14);
      v16 = *v13;
      fIllum = &temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      *(_DWORD *)fIllum = v16;
      v17 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v27);
      forward.x = (float)((float)((float)(*(float *)(v15 + 16) * *v17) + (float)(v17[1] * *(float *)(v15 + 20)))
                        + (float)(v17[2] * *(float *)(v15 + 24)))
                + v17[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v15 + 32) * v17[1]) + (float)(*(float *)(v15 + 28) * *v17))
                                + (float)(v17[2] * *(float *)(v15 + 36));
      forward.y = (float)((float)((float)(*(float *)(v15 + 16) * v17[4]) + (float)(v17[5] * *(float *)(v15 + 20)))
                        + (float)(v17[6] * *(float *)(v15 + 24)))
                + v17[7];
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v15 + 28) * v17[4]) + (float)(v17[5] * *(float *)(v15 + 32)))
                                + (float)(v17[6] * *(float *)(v15 + 36));
      forward.z = (float)((float)((float)(v17[9] * *(float *)(v15 + 20)) + (float)(*(float *)(v15 + 16) * v17[8]))
                        + (float)(v17[10] * *(float *)(v15 + 24)))
                + v17[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v15 + 32) * v17[9]) + (float)(*(float *)(v15 + 28) * v17[8]))
                                + (float)(v17[10] * *(float *)(v15 + 36));
      v18 = (float *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * LODWORD(v14));
      dstVertex.m_vecNormal.z = (float)((float)(v17[1] * v18[1]) + (float)(*v18 * *v17)) + (float)(v17[2] * v18[2]);
      v19 = v31;
      dstVertex.m_vecTexCoord.x = (float)((float)(v17[5] * v18[1]) + (float)(v17[4] * *v18)) + (float)(v17[6] * v18[2]);
      v20 = (float)(*v18 * v17[8]) + (float)(v17[9] * v18[1]);
      v21 = v17[10] * v18[2];
      v22 = *(_DWORD *)fIllum;
      dstVertex.m_vecTexCoord.y = v20 + v21;
      dstVertex.m_vecUserData.x = v18[3];
      v23 = *(float *)(v15 + 40);
      _mm_prefetch((const char *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * v22), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      _mm_prefetch((const char *)(v19 + 48 * v22), 0);
      _mm_prefetch((const char *)(v19 + 48 * v22 + 32), 0);
      dstVertex.m_vecNormal.x = v23;
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      fIllum = m_pCurrPosition;
      v25 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v26 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v25);
      _mm_stream_ps(m_pCurrPosition + 8, v26);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++v33;
      pVertices = (mstudiovertex_t *)((char *)pVertices + 1);
      if ( (int)pVertices >= numVertices )
        break;
      v13 = v33;
      v9 = v31;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000B890
// Name: public: static void CProcessMeshWrapper<1,0,1>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,0,1>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // edi
  float v9; // esi
  int i; // edx
  float v11; // eax
  const char *v12; // ecx
  Vector4D *v13; // ecx
  unsigned int v14; // eax
  int x_low; // ecx
  float v16; // edi
  int v17; // esi
  float *v18; // eax
  float *v19; // ecx
  unsigned int v20; // edi
  int v21; // eax
  float v22; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  int v26; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  int v30; // [esp+80h] [ebp-20h]
  Vector4D *pStudioTangentS; // [esp+84h] [ebp-1Ch]
  int v32; // [esp+88h] [ebp-18h]
  unsigned int fIllum; // [esp+8Ch] [ebp-14h]
  float *v34; // [esp+90h] [ebp-10h]
  int j; // [esp+94h] [ebp-Ch]
  mstudiovertex_t *pVertices; // [esp+98h] [ebp-8h]
  mstudiovertex_t *retaddr; // [esp+A0h] [ebp+0h]

  j = a1;
  pVertices = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  LODWORD(v9) = (char *)modelvertexdata->pTangentData
              + 16 * ((_DWORD)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4));
  fIllum = (unsigned int)modelvertexdata->pVertexData
         + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  dstVertex.m_vecUserData.z = v9;
  v30 = 1065353216;
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v11) = pGroupToMesh[i];
    v12 = (const char *)(fIllum + 48 * LODWORD(v11));
    temp.m_flMatVal[2][i + 2] = v11;
    _mm_prefetch(v12, 0);
    _mm_prefetch(v12 + 32, 0);
    _mm_prefetch((const char *)(LODWORD(v9) + 16 * LODWORD(v11)), 0);
  }
  v32 = 0;
  if ( numVertices > 0 )
  {
    v13 = (Vector4D *)(pGroupToMesh + 4);
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( pStudioTangentS = (Vector4D *)(pGroupToMesh + 4); ; v13 = pStudioTangentS )
    {
      v14 = (unsigned int)&v13->x + 2;
      x_low = LOWORD(v13->x);
      _mm_prefetch((const char *)(v14 & 0xFFFFFFE0), 0);
      v16 = temp.m_flMatVal[2][(v32 & 3) + 2];
      v34 = &temp.m_flMatVal[2][(v32 & 3) + 2];
      *(_DWORD *)v34 = x_low;
      v17 = fIllum + 48 * LODWORD(v16);
      v18 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v17,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v26);
      forward.x = (float)((float)((float)(*(float *)(v17 + 16) * *v18) + (float)(v18[1] * *(float *)(v17 + 20)))
                        + (float)(v18[2] * *(float *)(v17 + 24)))
                + v18[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v17 + 32) * v18[1]) + (float)(*(float *)(v17 + 28) * *v18))
                                + (float)(v18[2] * *(float *)(v17 + 36));
      forward.y = (float)((float)((float)(*(float *)(v17 + 16) * v18[4]) + (float)(v18[5] * *(float *)(v17 + 20)))
                        + (float)(v18[6] * *(float *)(v17 + 24)))
                + v18[7];
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v17 + 28) * v18[4]) + (float)(v18[5] * *(float *)(v17 + 32)))
                                + (float)(v18[6] * *(float *)(v17 + 36));
      forward.z = (float)((float)((float)(v18[9] * *(float *)(v17 + 20)) + (float)(*(float *)(v17 + 16) * v18[8]))
                        + (float)(v18[10] * *(float *)(v17 + 24)))
                + v18[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v17 + 32) * v18[9]) + (float)(*(float *)(v17 + 28) * v18[8]))
                                + (float)(v18[10] * *(float *)(v17 + 36));
      v19 = (float *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * LODWORD(v16));
      dstVertex.m_vecNormal.z = (float)((float)(v18[1] * v19[1]) + (float)(*v19 * *v18)) + (float)(v18[2] * v19[2]);
      v20 = fIllum;
      dstVertex.m_vecTexCoord.x = (float)((float)(v18[5] * v19[1]) + (float)(v18[4] * *v19)) + (float)(v18[6] * v19[2]);
      dstVertex.m_vecTexCoord.y = (float)((float)(*v19 * v18[8]) + (float)(v18[9] * v19[1])) + (float)(v18[10] * v19[2]);
      v21 = *(_DWORD *)v34;
      dstVertex.m_vecUserData.x = v19[3];
      v22 = *(float *)(v17 + 40);
      _mm_prefetch((const char *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * v21), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      _mm_prefetch((const char *)(v20 + 48 * v21), 0);
      _mm_prefetch((const char *)(v20 + 48 * v21 + 32), 0);
      dstVertex.m_vecNormal.x = v22;
      dstVertex.m_vecNormal.y = *(float *)(v17 + 44);
      v34 = m_pCurrPosition;
      v24 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v25 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v24);
      _mm_stream_ps(m_pCurrPosition + 8, v25);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      pStudioTangentS = (Vector4D *)((char *)pStudioTangentS + 2);
      if ( ++v32 >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBE0
// Name: public: static void CProcessMeshWrapper<1,0,2>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,0,2>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // edi
  char *v9; // esi
  float v10; // esi
  int i; // edx
  float v12; // eax
  const char *v13; // ecx
  unsigned __int16 *v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  float v17; // edi
  int v18; // esi
  float *v19; // eax
  float *v20; // ecx
  unsigned int v21; // edi
  int v22; // eax
  float v23; // xmm0_4
  float *m_pCurrPosition; // edx
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  int v27; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  int ntemp[4]; // [esp+34h] [ebp-6Ch] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  float v32; // [esp+80h] [ebp-20h] BYREF
  Vector4D *pStudioTangentS; // [esp+84h] [ebp-1Ch]
  unsigned __int16 *k; // [esp+88h] [ebp-18h]
  unsigned int fIllum; // [esp+8Ch] [ebp-14h]
  int j; // [esp+90h] [ebp-10h]
  int v37; // [esp+94h] [ebp-Ch]
  mstudiovertex_t *pVertices; // [esp+98h] [ebp-8h]
  mstudiovertex_t *retaddr; // [esp+A0h] [ebp+0h]

  v37 = a1;
  pVertices = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v9 = (char *)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4);
  fIllum = (unsigned int)modelvertexdata->pVertexData
         + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  LODWORD(v10) = (char *)modelvertexdata->pTangentData + 16 * (_DWORD)v9;
  dstVertex.m_vecUserData.z = v10;
  v32 = 1.0;
  CStudioRender::R_MouthComputeLightingValues(this: &g_StudioRender, fIllum: &v32, forward: (Vector *)&ntemp[1]);
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v12) = pGroupToMesh[i];
    v13 = (const char *)(fIllum + 48 * LODWORD(v12));
    temp.m_flMatVal[2][i + 2] = v12;
    _mm_prefetch(v13, 0);
    _mm_prefetch(v13 + 32, 0);
    _mm_prefetch((const char *)(LODWORD(v10) + 16 * LODWORD(v12)), 0);
  }
  pStudioTangentS = nullptr;
  if ( numVertices > 0 )
  {
    v14 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.w) = &forward;
    for ( k = pGroupToMesh + 4; ; v14 = k )
    {
      v15 = (unsigned int)(v14 + 1);
      v16 = *v14;
      _mm_prefetch((const char *)(v15 & 0xFFFFFFE0), 0);
      v17 = temp.m_flMatVal[2][((unsigned __int8)pStudioTangentS & 3) + 2];
      j = (int)&temp.m_flMatVal[2][((unsigned __int8)pStudioTangentS & 3) + 2];
      *(_DWORD *)j = v16;
      v18 = fIllum + 48 * LODWORD(v17);
      v19 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v18,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v27);
      forward.x = (float)((float)((float)(*(float *)(v18 + 16) * *v19) + (float)(v19[1] * *(float *)(v18 + 20)))
                        + (float)(v19[2] * *(float *)(v18 + 24)))
                + v19[3];
      dstVertex.m_vecPosition.x = (float)((float)(*(float *)(v18 + 32) * v19[1]) + (float)(*(float *)(v18 + 28) * *v19))
                                + (float)(v19[2] * *(float *)(v18 + 36));
      forward.y = (float)((float)((float)(*(float *)(v18 + 16) * v19[4]) + (float)(v19[5] * *(float *)(v18 + 20)))
                        + (float)(v19[6] * *(float *)(v18 + 24)))
                + v19[7];
      dstVertex.m_vecPosition.y = (float)((float)(*(float *)(v18 + 28) * v19[4]) + (float)(v19[5] * *(float *)(v18 + 32)))
                                + (float)(v19[6] * *(float *)(v18 + 36));
      forward.z = (float)((float)((float)(v19[9] * *(float *)(v18 + 20)) + (float)(*(float *)(v18 + 16) * v19[8]))
                        + (float)(v19[10] * *(float *)(v18 + 24)))
                + v19[11];
      dstVertex.m_vecPosition.z = (float)((float)(*(float *)(v18 + 32) * v19[9]) + (float)(*(float *)(v18 + 28) * v19[8]))
                                + (float)(v19[10] * *(float *)(v18 + 36));
      v20 = (float *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * LODWORD(v17));
      dstVertex.m_vecNormal.z = (float)((float)(v19[1] * v20[1]) + (float)(*v20 * *v19)) + (float)(v19[2] * v20[2]);
      v21 = fIllum;
      dstVertex.m_vecTexCoord.x = (float)((float)(v19[5] * v20[1]) + (float)(v19[4] * *v20)) + (float)(v19[6] * v20[2]);
      dstVertex.m_vecTexCoord.y = (float)((float)(*v20 * v19[8]) + (float)(v19[9] * v20[1])) + (float)(v19[10] * v20[2]);
      v22 = *(_DWORD *)j;
      dstVertex.m_vecUserData.x = v20[3];
      v23 = *(float *)(v18 + 40);
      _mm_prefetch((const char *)(LODWORD(dstVertex.m_vecUserData.z) + 16 * v22), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      _mm_prefetch((const char *)(v21 + 48 * v22), 0);
      _mm_prefetch((const char *)(v21 + 48 * v22 + 32), 0);
      dstVertex.m_vecNormal.x = v23;
      dstVertex.m_vecNormal.y = *(float *)(v18 + 44);
      j = (int)m_pCurrPosition;
      v25 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 16);
      v26 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.w) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.w));
      _mm_stream_ps(m_pCurrPosition + 4, v25);
      _mm_stream_ps(m_pCurrPosition + 8, v26);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++k;
      pStudioTangentS = (Vector4D *)((char *)pStudioTangentS + 1);
      if ( (int)pStudioTangentS >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: public: static void CProcessMeshWrapper<1,1,0>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,1,0>::R_StudioSoftwareProcessMesh(
        int a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // esi
  unsigned int v9; // edx
  float v10; // edi
  int i; // esi
  float v12; // eax
  mstudiovertex_t *v13; // ecx
  float v14; // esi
  unsigned int v15; // edi
  float v16; // edx
  float *v17; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v19; // edx
  Vector4D *p_m_Normal; // esi
  float *p_x; // ecx
  float v22; // xmm0_4
  float v23; // xmm1_4
  float x; // eax
  int v25; // edx
  float v26; // xmm0_4
  Vector4D *m_pCurrPosition; // ecx
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  int v30; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  int v34; // [esp+80h] [ebp-20h]
  int n; // [esp+84h] [ebp-1Ch]
  Vector4D *pStudioTangentS; // [esp+88h] [ebp-18h]
  int fIllum; // [esp+8Ch] [ebp-14h]
  mstudiovertex_t *pVertices; // [esp+90h] [ebp-10h]
  int v39; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int retaddr; // [esp+A0h] [ebp+0h]

  v39 = a1;
  j = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v9 = (unsigned int)modelvertexdata->pVertexData
     + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  LODWORD(v10) = (char *)modelvertexdata->pTangentData
               + 16 * ((_DWORD)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4));
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  n = v9;
  dstVertex.m_vecUserData.w = v10;
  v34 = 1065353216;
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v12) = pGroupToMesh[i];
    temp.m_flMatVal[2][i + 2] = v12;
    _mm_prefetch((const char *)(v9 + 48 * LODWORD(v12)), 0);
    _mm_prefetch((const char *)(v9 + 48 * LODWORD(v12) + 32), 0);
    _mm_prefetch((const char *)(LODWORD(v10) + 16 * LODWORD(v12)), 0);
  }
  fIllum = 0;
  if ( numVertices > 0 )
  {
    LODWORD(dstVertex.m_vecUserData.y) = &forward;
    v13 = (mstudiovertex_t *)(pGroupToMesh + 4);
    pVertices = (mstudiovertex_t *)(pGroupToMesh + 4);
    while ( 1 )
    {
      _mm_prefetch((const char *)(((unsigned int)v13->m_BoneWeights.weight + 2) & 0xFFFFFFE0), 0);
      v14 = temp.m_flMatVal[2][(fIllum & 3) + 2];
      v15 = v9 + 48 * LODWORD(v14);
      LODWORD(v16) = LOWORD(v13->m_BoneWeights.weight[0]);
      pStudioTangentS = (Vector4D *)&temp.m_flMatVal[2][(fIllum & 3) + 2];
      pStudioTangentS->x = v16;
      dstVertex.m_vecUserData.z = v14;
      v17 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v15,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v30);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(v14)].m_Tag == vertexCache->m_CurrentTag )
      {
        v19 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v14)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v14)].m_VertexIndex].m_Normal;
        p_x = &v19->m_TangentS.x;
      }
      else
      {
LABEL_9:
        p_x = (float *)(LODWORD(dstVertex.m_vecUserData.w) + 16 * LODWORD(dstVertex.m_vecUserData.z));
        v19 = (CachedPosNormTan_t *)(v15 + 16);
        p_m_Normal = (Vector4D *)(v15 + 28);
      }
      forward.x = (float)((float)((float)(v17[1] * v19->m_Position.y) + (float)(v19->m_Position.x * *v17))
                        + (float)(v19->m_Position.z * v17[2]))
                + v17[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v17) + (float)(p_m_Normal->y * v17[1]))
                                + (float)(p_m_Normal->z * v17[2]);
      forward.y = (float)((float)((float)(v19->m_Position.x * v17[4]) + (float)(v19->m_Position.y * v17[5]))
                        + (float)(v19->m_Position.z * v17[6]))
                + v17[7];
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->y * v17[5]) + (float)(p_m_Normal->x * v17[4]))
                                + (float)(p_m_Normal->z * v17[6]);
      forward.z = (float)((float)((float)(v17[9] * v19->m_Position.y) + (float)(v17[8] * v19->m_Position.x))
                        + (float)(v19->m_Position.z * v17[10]))
                + v17[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->y * v17[9]) + (float)(v17[8] * p_m_Normal->x))
                                + (float)(p_m_Normal->z * v17[10]);
      dstVertex.m_vecNormal.z = (float)((float)(v17[1] * p_x[1]) + (float)(*p_x * *v17)) + (float)(p_x[2] * v17[2]);
      dstVertex.m_vecTexCoord.x = (float)((float)(p_x[1] * v17[5]) + (float)(*p_x * v17[4])) + (float)(p_x[2] * v17[6]);
      v22 = (float)(v17[9] * p_x[1]) + (float)(v17[8] * *p_x);
      v23 = p_x[2] * v17[10];
      x = pStudioTangentS->x;
      v25 = n;
      dstVertex.m_vecTexCoord.y = v22 + v23;
      dstVertex.m_vecUserData.x = p_x[3];
      _mm_prefetch((const char *)(LODWORD(dstVertex.m_vecUserData.w) + 16 * LODWORD(x)), 0);
      v26 = *(float *)(v15 + 40);
      _mm_prefetch((const char *)(v25 + 48 * LODWORD(x)), 0);
      _mm_prefetch((const char *)(v25 + 48 * LODWORD(x) + 32), 0);
      m_pCurrPosition = (Vector4D *)meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v26;
      dstVertex.m_vecNormal.y = *(float *)(v15 + 44);
      pStudioTangentS = m_pCurrPosition;
      v28 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 16);
      v29 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 32);
      _mm_stream_ps(&m_pCurrPosition->x, *(__m128 *)LODWORD(dstVertex.m_vecUserData.y));
      _mm_stream_ps(&m_pCurrPosition[1].x, v28);
      _mm_stream_ps(&m_pCurrPosition[2].x, v29);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      pVertices = (mstudiovertex_t *)((char *)pVertices + 2);
      if ( ++fIllum >= numVertices )
        break;
      v13 = pVertices;
      v9 = n;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000C2C0
// Name: public: static void CProcessMeshWrapper<1,1,1>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,1,1>::R_StudioSoftwareProcessMesh(
        mstudiovertex_t *a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // edi
  int v9; // esi
  int i; // edx
  float v11; // eax
  const char *v12; // ecx
  unsigned __int16 *v13; // ecx
  unsigned int v14; // eax
  float v15; // ecx
  float v16; // esi
  int v17; // edi
  float *v18; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v20; // edx
  Vector4D *p_m_Normal; // esi
  float *p_x; // ecx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float x; // eax
  unsigned int v26; // edx
  float v27; // xmm0_4
  Vector4D *m_pCurrPosition; // ecx
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  int v31; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  int v35; // [esp+80h] [ebp-20h]
  int n; // [esp+84h] [ebp-1Ch]
  unsigned int fIllum; // [esp+88h] [ebp-18h]
  Vector4D *pStudioTangentS; // [esp+8Ch] [ebp-14h]
  int j; // [esp+90h] [ebp-10h]
  mstudiovertex_t *pVertices; // [esp+94h] [ebp-Ch]
  void *v41; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  pVertices = a1;
  v41 = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v9 = (int)modelvertexdata->pTangentData + 16 * ((_DWORD)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4));
  fIllum = (unsigned int)modelvertexdata->pVertexData
         + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  v35 = v9;
  dstVertex.m_vecUserData.w = 1.0;
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v11) = pGroupToMesh[i];
    v12 = (const char *)(fIllum + 48 * LODWORD(v11));
    temp.m_flMatVal[2][i + 2] = v11;
    _mm_prefetch(v12, 0);
    _mm_prefetch(v12 + 32, 0);
    _mm_prefetch((const char *)(v9 + 16 * LODWORD(v11)), 0);
  }
  n = 0;
  if ( numVertices > 0 )
  {
    v13 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.y) = &forward;
    for ( j = (int)(pGroupToMesh + 4); ; v13 = (unsigned __int16 *)j )
    {
      v14 = (unsigned int)(v13 + 1);
      LODWORD(v15) = *v13;
      _mm_prefetch((const char *)(v14 & 0xFFFFFFE0), 0);
      v16 = temp.m_flMatVal[2][(n & 3) + 2];
      pStudioTangentS = (Vector4D *)&temp.m_flMatVal[2][(n & 3) + 2];
      pStudioTangentS->x = v15;
      v17 = fIllum + 48 * LODWORD(v16);
      dstVertex.m_vecUserData.z = v16;
      v18 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v17,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v31);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(v16)].m_Tag == vertexCache->m_CurrentTag )
      {
        v20 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v16)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v16)].m_VertexIndex].m_Normal;
        p_x = &v20->m_TangentS.x;
      }
      else
      {
LABEL_9:
        p_x = (float *)(v35 + 16 * LODWORD(dstVertex.m_vecUserData.z));
        v20 = (CachedPosNormTan_t *)(v17 + 16);
        p_m_Normal = (Vector4D *)(v17 + 28);
      }
      forward.x = (float)((float)((float)(v18[1] * v20->m_Position.y) + (float)(v20->m_Position.x * *v18))
                        + (float)(v20->m_Position.z * v18[2]))
                + v18[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v18) + (float)(p_m_Normal->y * v18[1]))
                                + (float)(p_m_Normal->z * v18[2]);
      forward.y = (float)((float)((float)(v20->m_Position.x * v18[4]) + (float)(v20->m_Position.y * v18[5]))
                        + (float)(v20->m_Position.z * v18[6]))
                + v18[7];
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->y * v18[5]) + (float)(p_m_Normal->x * v18[4]))
                                + (float)(p_m_Normal->z * v18[6]);
      forward.z = (float)((float)((float)(v18[9] * v20->m_Position.y) + (float)(v18[8] * v20->m_Position.x))
                        + (float)(v20->m_Position.z * v18[10]))
                + v18[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->y * v18[9]) + (float)(v18[8] * p_m_Normal->x))
                                + (float)(p_m_Normal->z * v18[10]);
      dstVertex.m_vecNormal.z = (float)((float)(v18[1] * p_x[1]) + (float)(*p_x * *v18)) + (float)(p_x[2] * v18[2]);
      dstVertex.m_vecTexCoord.x = (float)((float)(p_x[1] * v18[5]) + (float)(*p_x * v18[4])) + (float)(p_x[2] * v18[6]);
      v23 = (float)(v18[9] * p_x[1]) + (float)(v18[8] * *p_x);
      v24 = p_x[2] * v18[10];
      x = pStudioTangentS->x;
      v26 = fIllum;
      dstVertex.m_vecTexCoord.y = v23 + v24;
      dstVertex.m_vecUserData.x = p_x[3];
      _mm_prefetch((const char *)(v35 + 16 * LODWORD(x)), 0);
      v27 = *(float *)(v17 + 40);
      _mm_prefetch((const char *)(v26 + 48 * LODWORD(x)), 0);
      _mm_prefetch((const char *)(v26 + 48 * LODWORD(x) + 32), 0);
      m_pCurrPosition = (Vector4D *)meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v27;
      dstVertex.m_vecNormal.y = *(float *)(v17 + 44);
      pStudioTangentS = m_pCurrPosition;
      v29 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 16);
      v30 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 32);
      _mm_stream_ps(&m_pCurrPosition->x, *(__m128 *)LODWORD(dstVertex.m_vecUserData.y));
      _mm_stream_ps(&m_pCurrPosition[1].x, v29);
      _mm_stream_ps(&m_pCurrPosition[2].x, v30);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      j += 2;
      if ( ++n >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000C650
// Name: public: static void CProcessMeshWrapper<1,1,2>::R_StudioSoftwareProcessMesh(struct mstudio_meshvertexdata_t const __near *,struct matrix3x4_t __near *,class CCachedRenderData __near &,class CMeshBuilder __near &,int,unsigned short __near *,unsigned int,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProcessMeshWrapper<1,1,2>::R_StudioSoftwareProcessMesh(
        float a1@<ebp>,
        const mstudio_meshvertexdata_t *vertData,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  const mstudio_modelvertexdata_t *v8; // edi
  char *v9; // esi
  float v10; // esi
  int i; // edx
  float v12; // eax
  const char *v13; // ecx
  unsigned __int16 *v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  float v17; // esi
  int v18; // edi
  float *v19; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  CachedPosNormTan_t *v21; // edx
  Vector4D *p_m_Normal; // esi
  float *p_x; // ecx
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // edx
  float v28; // xmm0_4
  float *m_pCurrPosition; // ecx
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  int v32; // [esp-Ch] [ebp-ACh] BYREF
  matrix3x4_t temp; // [esp+0h] [ebp-A0h] BYREF
  int ntemp[4]; // [esp+34h] [ebp-6Ch] BYREF
  Vector forward; // [esp+44h] [ebp-5Ch] BYREF
  ModelVertexDX8_t dstVertex; // [esp+50h] [ebp-50h]
  float *v37; // [esp+80h] [ebp-20h]
  int n; // [esp+84h] [ebp-1Ch]
  Vector4D *pStudioTangentS; // [esp+88h] [ebp-18h] BYREF
  unsigned __int16 *j; // [esp+8Ch] [ebp-14h]
  mstudiovertex_t *pVertices; // [esp+90h] [ebp-10h]
  float fIllum; // [esp+94h] [ebp-Ch]
  void *v43; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  fIllum = a1;
  v43 = retaddr;
  modelvertexdata = vertData->modelvertexdata;
  v8 = vertData[-1].modelvertexdata;
  dstVertex.m_vecNormal.z = 1.0;
  dstVertex.m_vecTexCoord.x = 0.0;
  dstVertex.m_vecTexCoord.y = 0.0;
  dstVertex.m_vecUserData.x = 1.0;
  v9 = (char *)v8 + ((unsigned int)modelvertexdata[-3].pTangentData >> 4);
  n = (int)modelvertexdata->pVertexData + 48 * ((_DWORD)v8 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30);
  LODWORD(v10) = (char *)modelvertexdata->pTangentData + 16 * (_DWORD)v9;
  dstVertex.m_vecUserData.w = v10;
  pStudioTangentS = (Vector4D *)1065353216;
  CStudioRender::R_MouthComputeLightingValues(
    this: &g_StudioRender,
    fIllum: (float *)&pStudioTangentS,
    forward: (Vector *)&ntemp[1]);
  CStudioRender::R_InitLightEffectsWorld3(this: &g_StudioRender);
  _mm_prefetch((const char *)((unsigned int)pGroupToMesh & 0xFFFFFFE0), 0);
  for ( i = 0; i < 4; ++i )
  {
    LODWORD(v12) = pGroupToMesh[i];
    v13 = (const char *)(n + 48 * LODWORD(v12));
    temp.m_flMatVal[2][i + 2] = v12;
    _mm_prefetch(v13, 0);
    _mm_prefetch(v13 + 32, 0);
    _mm_prefetch((const char *)(LODWORD(v10) + 16 * LODWORD(v12)), 0);
  }
  pVertices = nullptr;
  if ( numVertices > 0 )
  {
    v14 = pGroupToMesh + 4;
    LODWORD(dstVertex.m_vecUserData.y) = &forward;
    for ( j = pGroupToMesh + 4; ; v14 = j )
    {
      v15 = (unsigned int)(v14 + 1);
      v16 = *v14;
      _mm_prefetch((const char *)(v15 & 0xFFFFFFE0), 0);
      v17 = temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      v37 = &temp.m_flMatVal[2][((unsigned __int8)pVertices & 3) + 2];
      *(_DWORD *)v37 = v16;
      v18 = n + 48 * LODWORD(v17);
      dstVertex.m_vecUserData.z = v17;
      v19 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)v18,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v32);
      m_pFirstFlexIndex = vertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex == nullptr )
        goto LABEL_9;
      if ( m_pFirstFlexIndex[LODWORD(v17)].m_Tag == vertexCache->m_CurrentTag )
      {
        v21 = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v17)].m_VertexIndex];
        p_m_Normal = &vertexCache->m_pFlexVerts[vertexCache->m_pFirstFlexIndex[LODWORD(v17)].m_VertexIndex].m_Normal;
        p_x = &v21->m_TangentS.x;
      }
      else
      {
LABEL_9:
        p_x = (float *)(LODWORD(dstVertex.m_vecUserData.w) + 16 * LODWORD(dstVertex.m_vecUserData.z));
        v21 = (CachedPosNormTan_t *)(v18 + 16);
        p_m_Normal = (Vector4D *)(v18 + 28);
      }
      forward.x = (float)((float)((float)(v19[1] * v21->m_Position.y) + (float)(v21->m_Position.x * *v19))
                        + (float)(v21->m_Position.z * v19[2]))
                + v19[3];
      dstVertex.m_vecPosition.x = (float)((float)(p_m_Normal->x * *v19) + (float)(p_m_Normal->y * v19[1]))
                                + (float)(p_m_Normal->z * v19[2]);
      forward.y = (float)((float)((float)(v21->m_Position.x * v19[4]) + (float)(v21->m_Position.y * v19[5]))
                        + (float)(v21->m_Position.z * v19[6]))
                + v19[7];
      dstVertex.m_vecPosition.y = (float)((float)(p_m_Normal->y * v19[5]) + (float)(p_m_Normal->x * v19[4]))
                                + (float)(p_m_Normal->z * v19[6]);
      forward.z = (float)((float)((float)(v19[9] * v21->m_Position.y) + (float)(v19[8] * v21->m_Position.x))
                        + (float)(v21->m_Position.z * v19[10]))
                + v19[11];
      dstVertex.m_vecPosition.z = (float)((float)(p_m_Normal->y * v19[9]) + (float)(v19[8] * p_m_Normal->x))
                                + (float)(p_m_Normal->z * v19[10]);
      dstVertex.m_vecNormal.z = (float)((float)(v19[1] * p_x[1]) + (float)(*p_x * *v19)) + (float)(p_x[2] * v19[2]);
      dstVertex.m_vecTexCoord.x = (float)((float)(p_x[1] * v19[5]) + (float)(*p_x * v19[4])) + (float)(p_x[2] * v19[6]);
      v24 = (float)(v19[9] * p_x[1]) + (float)(v19[8] * *p_x);
      v25 = p_x[2] * v19[10];
      v26 = *(_DWORD *)v37;
      v27 = n;
      dstVertex.m_vecTexCoord.y = v24 + v25;
      dstVertex.m_vecUserData.x = p_x[3];
      _mm_prefetch((const char *)(LODWORD(dstVertex.m_vecUserData.w) + 16 * v26), 0);
      v28 = *(float *)(v18 + 40);
      _mm_prefetch((const char *)(v27 + 48 * v26), 0);
      _mm_prefetch((const char *)(v27 + 48 * v26 + 32), 0);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      dstVertex.m_vecNormal.x = v28;
      dstVertex.m_vecNormal.y = *(float *)(v18 + 44);
      v37 = m_pCurrPosition;
      v30 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 16);
      v31 = *(__m128 *)(LODWORD(dstVertex.m_vecUserData.y) + 32);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)LODWORD(dstVertex.m_vecUserData.y));
      _mm_stream_ps(m_pCurrPosition + 4, v30);
      _mm_stream_ps(m_pCurrPosition + 8, v31);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      ++j;
      pVertices = (mstudiovertex_t *)((char *)pVertices + 1);
      if ( (int)pVertices >= numVertices )
        break;
    }
  }
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += numVertices;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
}

//------------------------------------------------------------------------------
// Address: 0x1000C9F0
// Name: private: void CStudioRender::R_StudioDrawHulls(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::R_StudioDrawHulls(
        CStudioRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        mstudiobbox_t *hitboxset,
        bool translucent)
{
  studiohdr_t *m_pStudioHdr; // ecx
  int v7; // eax
  bool v8; // zf
  mstudiohitboxset_t *v9; // eax
  IMatRenderContext *m_pObject; // edi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  IMaterial *m_pMaterialTranslucentModelHulls; // ecx
  mstudiobbox_t *v13; // eax
  char v14; // cl
  Vector *k; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  int v19; // esi
  void (__thiscall *SetVecValue_2)(IMaterialVar *, float, float, float); // eax
  int v21; // esi
  IMesh *v22; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v24; // edi
  float *m_pPosition; // ecx
  _DWORD *v26; // esi
  Vector *v27; // eax
  int m_nVertexCount; // eax
  int m_nIndexCount; // [esp+20h] [ebp-27Ch]
  CMeshBuilder *p_meshBuilder; // [esp+24h] [ebp-278h]
  Vector p[8]; // [esp+2Ch] [ebp-270h] BYREF
  CMeshBuilder meshBuilder; // [esp+8Ch] [ebp-210h] BYREF
  CStudioRender *v33; // [esp+274h] [ebp-28h]
  IMesh *pMesh; // [esp+278h] [ebp-24h]
  Vector tmp; // [esp+27Ch] [ebp-20h] BYREF
  int i; // [esp+288h] [ebp-14h]
  IMaterialVar *colorVar; // [esp+28Ch] [ebp-10h]
  mstudiohitboxset_t *s; // [esp+290h] [ebp-Ch]
  CMatRenderContextPtr pRenderContext; // [esp+294h] [ebp-8h]
  int j; // [esp+298h] [ebp-4h]
  mstudiobbox_t *pbbox; // [esp+2A4h] [ebp+8h]

  m_pStudioHdr = this->m_pStudioHdr;
  v7 = m_pStudioHdr->hitboxsetindex + 12 * (_DWORD)hitboxset;
  v8 = (studiohdr_t *)((char *)m_pStudioHdr + v7) == nullptr;
  v9 = (mstudiohitboxset_t *)((char *)m_pStudioHdr + v7);
  v33 = this;
  s = v9;
  if ( !v8 )
  {
    pbbox = (mstudiobbox_t *)((char *)v9 + v9->hitboxindex);
    if ( pbbox != nullptr )
    {
      m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))g_pMaterialSystem->GetRenderContext)(
                                         a1: g_pMaterialSystem,
                                         a2: a3,
                                         a3: a2);
      pRenderContext.m_pObject = m_pObject;
      if ( m_pObject != nullptr )
        m_pObject->BeginRender(this: m_pObject);
      Bind = m_pObject->Bind;
      if ( translucent )
      {
        Bind(this: m_pObject, a2: this->m_pMaterialTranslucentModelHulls, a3: nullptr);
        m_pMaterialTranslucentModelHulls = this->m_pMaterialTranslucentModelHulls;
        p_meshBuilder = (CMeshBuilder *)&s_nTranslucentModelHullCache;
      }
      else
      {
        Bind(this: m_pObject, a2: this->m_pMaterialSolidModelHulls, a3: nullptr);
        m_pMaterialTranslucentModelHulls = this->m_pMaterialSolidModelHulls;
        p_meshBuilder = (CMeshBuilder *)&s_nSolidModelHullCache;
      }
      colorVar = (IMaterialVar *)((int (__thiscall *)(IMaterial *, const char *))m_pMaterialTranslucentModelHulls->FindVarFast)(
                                   a1: m_pMaterialTranslucentModelHulls,
                                   a2: "$color");
      i = 0;
      if ( s->numhitboxes > 0 )
      {
        v13 = pbbox;
        v14 = 0;
        j = 0;
        for ( k = p; ; k = p )
        {
          while ( 1 )
          {
            v16 = (v14 & 1) != 0 ? v13->bbmin.x : v13->bbmax.x;
            tmp.x = v16;
            v17 = (v14 & 2) != 0 ? v13->bbmin.y : v13->bbmax.y;
            tmp.y = v17;
            v18 = (v14 & 4) != 0 ? v13->bbmin.z : v13->bbmax.z;
            tmp.z = v18;
            VectorTransform(in1: &tmp.x, in2: &v33->m_pBoneToWorld[v13->bone], out: &k->x);
            ++k;
            if ( ++j >= 8 )
              break;
            v14 = j;
            v13 = pbbox;
          }
          v19 = pbbox->group % 8;
          g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: false);
          if ( colorVar != nullptr )
          {
            SetVecValue_2 = colorVar->SetVecValue_2;
            v21 = v19;
            if ( translucent )
              ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))SetVecValue_2)(
                a1: hullcolor[v21].x * 0.2,
                a2: hullcolor[v21].y * 0.2,
                a3: hullcolor[v21].z * 0.2);
            else
              ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))SetVecValue_2)(
                a1: LODWORD(hullcolor[v21].x),
                a2: LODWORD(hullcolor[v21].y),
                a3: LODWORD(hullcolor[v21].z));
          }
          j = (int)boxpnt;
          do
          {
            v22 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int, CMeshBuilder *))m_pObject->GetDynamicMesh)(
                             a1: m_pObject,
                             a2: 1,
                             a3: 0,
                             a4: 0,
                             a5: 0,
                             a6: m_nIndexCount,
                             a7: p_meshBuilder);
            meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
            meshBuilder.m_pMesh = v22;
            meshBuilder.m_bGenerateIndices = true;
            meshBuilder.m_Type = MATERIAL_QUADS;
            SetPrimitiveType = v22->SetPrimitiveType;
            pMesh = v22;
            SetPrimitiveType(this: v22, a2: MATERIAL_TRIANGLES);
            meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
            meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v22->IIndexBuffer;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = v22;
            meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
            meshBuilder.m_IndexBuilder.m_bModify = false;
            meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
            meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
            meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
            v24 = 4;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
            meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
            meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_bModify = false;
            if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
            {
              meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
              meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
              meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
            }
            m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
            v26 = (_DWORD *)j;
            meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
            qmemcpy(
              meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
              meshBuilder.m_VertexBuilder.m_pTexCoord,
              sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
            meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
            meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
            meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
            while ( 1 )
            {
              v27 = &p[*v26];
              *m_pPosition = v27->x;
              m_pPosition[1] = v27->y;
              m_pPosition[2] = v27->z;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              ++v26;
              if ( --v24 == 0 )
                break;
              m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
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
            p_meshBuilder = &meshBuilder;
            m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
            ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
              a1: meshBuilder.m_pMesh,
              a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
            meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
            meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
            meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
            meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
            meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            meshBuilder.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
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
            m_pObject = pRenderContext.m_pObject;
            j = (int)v26;
          }
          while ( (int)v26 < (int)hullcolor );
          ++pbbox;
          if ( ++i >= s->numhitboxes )
            break;
          v13 = pbbox;
          v14 = 0;
          j = 0;
        }
      }
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CF20
// Name: private: void CStudioRender::R_StudioDrawBones(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioDrawBones(CStudioRender *this)
{
  CStudioRender *v1; // esi
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *m_pObject; // edi
  studiohdr_t *m_pStudioHdr; // eax
  float v5; // xmm1_4
  int v6; // ecx
  int v7; // edx
  matrix3x4_t *m_pBoneToWorld; // eax
  int v9; // esi
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  matrix3x4_t *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  int v21; // ecx
  float *p_z; // eax
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  IMesh *v27; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v29; // edi
  float *m_pPosition; // ecx
  mstudiobone_t *v31; // esi
  Vector *v32; // eax
  int m_nVertexCount; // eax
  studiohdr_t *v34; // edx
  Vector p[8]; // [esp+Ch] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+6Ch] [ebp-234h] BYREF
  float v37; // [esp+254h] [ebp-4Ch]
  float v38; // [esp+258h] [ebp-48h]
  IMesh *pMesh; // [esp+25Ch] [ebp-44h]
  float v40; // [esp+260h] [ebp-40h]
  CMatRenderContextPtr pRenderContext; // [esp+264h] [ebp-3Ch]
  int v42; // [esp+268h] [ebp-38h]
  int i; // [esp+26Ch] [ebp-34h]
  Vector up; // [esp+270h] [ebp-30h] BYREF
  Vector forward; // [esp+27Ch] [ebp-24h] BYREF
  int *p_parent; // [esp+288h] [ebp-18h]
  CStudioRender *v47; // [esp+28Ch] [ebp-14h]
  Vector right; // [esp+290h] [ebp-10h] BYREF
  mstudiobone_t *pbones; // [esp+29Ch] [ebp-4h]

  v1 = this;
  pbones = (mstudiobone_t *)((char *)this->m_pStudioHdr + this->m_pStudioHdr->boneindex);
  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v47 = this;
  m_pObject = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pStudioHdr = v1->m_pStudioHdr;
  i = 0;
  if ( m_pStudioHdr->numbones > 0 )
  {
    v5 = 1.0;
    v6 = 0;
    v42 = 0;
    p_parent = &pbones->parent;
    while ( 1 )
    {
      v7 = *p_parent;
      if ( *p_parent != -1 )
        break;
LABEL_45:
      v34 = v1->m_pStudioHdr;
      p_parent += 54;
      v6 += 48;
      ++i;
      v42 = v6;
      if ( i >= v34->numbones )
        goto LABEL_46;
    }
    m_pBoneToWorld = v1->m_pBoneToWorld;
    v9 = v7;
    v10 = *(float *)((char *)&m_pBoneToWorld->m_flMatVal[0][3] + v6) - m_pBoneToWorld[v7].m_flMatVal[0][3];
    up.x = v10;
    up.y = *(float *)((char *)&m_pBoneToWorld->m_flMatVal[1][3] + v6) - m_pBoneToWorld[v7].m_flMatVal[1][3];
    v11 = *(float *)((char *)&m_pBoneToWorld->m_flMatVal[2][3] + v6) - m_pBoneToWorld[v7].m_flMatVal[2][3];
    v12 = 1.0;
    v13 = 1.0;
    up.z = v11;
    if ( v10 <= up.y )
    {
      if ( up.y > v11 )
      {
        v5 = 0.0;
        goto LABEL_12;
      }
    }
    else if ( v10 > v11 )
    {
      v13 = 0.0;
      goto LABEL_12;
    }
    v12 = 0.0;
LABEL_12:
    right.x = (float)(v12 * up.y) - (float)(v5 * v11);
    right.y = (float)(v11 * v13) - (float)(v12 * v10);
    right.z = (float)(v5 * v10) - (float)(up.y * v13);
    VectorNormalize(vec: &right);
    forward.x = (float)(right.z * up.y) - (float)(right.y * up.z);
    forward.y = (float)(up.z * right.x) - (float)(right.z * up.x);
    forward.z = (float)(right.y * up.x) - (float)(up.y * right.x);
    VectorNormalize(vec: &forward);
    v14 = v47->m_pBoneToWorld;
    v15 = right.x * 2.0;
    v16 = right.y * 2.0;
    v17 = right.z * 2.0;
    v18 = forward.x * 2.0;
    v19 = forward.y * 2.0;
    v20 = forward.z * 2.0;
    right.x = right.x * 2.0;
    right.y = right.y * 2.0;
    right.z = right.z * 2.0;
    forward.x = forward.x * 2.0;
    forward.y = forward.y * 2.0;
    forward.z = forward.z * 2.0;
    v38 = v14[v9].m_flMatVal[0][3];
    v40 = v14[v9].m_flMatVal[1][3];
    v21 = 0;
    v37 = v14[v9].m_flMatVal[2][3];
    p_z = &p[0].z;
    do
    {
      *(p_z - 2) = v38;
      *(p_z - 1) = v40;
      *p_z = v37;
      v23 = *(p_z - 2);
      if ( (v21 & 1) != 0 )
      {
        *(p_z - 2) = v23 - v15;
        *(p_z - 1) = *(p_z - 1) - v16;
        v24 = *p_z - v17;
      }
      else
      {
        *(p_z - 2) = v23 + v15;
        *(p_z - 1) = v16 + *(p_z - 1);
        v24 = *p_z + v17;
      }
      *p_z = v24;
      v25 = *(p_z - 2);
      if ( (v21 & 2) != 0 )
      {
        *(p_z - 2) = v25 - v18;
        *(p_z - 1) = *(p_z - 1) - v19;
        v26 = *p_z - v20;
      }
      else
      {
        *(p_z - 2) = v25 + v18;
        *(p_z - 1) = v19 + *(p_z - 1);
        v26 = *p_z + v20;
      }
      *p_z = v26;
      if ( (v21 & 4) == 0 )
      {
        *(p_z - 2) = *(p_z - 2) + up.x;
        *(p_z - 1) = up.y + *(p_z - 1);
        *p_z = *p_z + up.z;
      }
      ++v21;
      p_z += 3;
    }
    while ( v21 < 8 );
    VectorNormalize(vec: &up);
    VectorNormalize(vec: &right);
    VectorNormalize(vec: &forward);
    m_pObject->Bind(this: m_pObject, a2: v47->m_pMaterialModelBones, a3: nullptr);
    pbones = (mstudiobone_t *)boxpnt;
    do
    {
      v27 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v27;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      SetPrimitiveType = v27->SetPrimitiveType;
      pMesh = v27;
      SetPrimitiveType(this: v27, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v27->IIndexBuffer;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v27;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      v29 = 4;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 4;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      v31 = pbones;
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      while ( 1 )
      {
        v32 = &p[v31->sznameindex];
        *m_pPosition = v32->x;
        m_pPosition[1] = v32->y;
        m_pPosition[2] = v32->z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v31 = (mstudiobone_t *)((char *)v31 + 4);
        if ( --v29 == 0 )
          break;
        m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
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
      m_pObject = pRenderContext.m_pObject;
      pbones = v31;
    }
    while ( (int)v31 < (int)hullcolor );
    v5 = 1.0;
    v6 = v42;
    v1 = v47;
    goto LABEL_45;
  }
LABEL_46:
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D600
// Name: private: void CStudioRender::GenerateMorphAccumulator(struct mstudiomodel_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::GenerateMorphAccumulator(CStudioRender *this, mstudiomodel_t *pSubModel)
{
  StudioRenderContext_t *m_pRC; // eax
  bool v4; // zf
  int nummeshes; // ecx
  char *v6; // edi
  IMatRenderContext *v7; // eax
  int v8; // esi
  int v9; // ecx
  _DWORD *p_BeginRender; // eax
  int v11; // eax
  int v12; // edi
  IMatRenderContext *v13; // eax
  IMatRenderContext *m_pObject; // esi
  mstudiomesh_t *v15; // esi
  int numflexes; // ebx
  studiomeshdata_t *v17; // edi
  void *v18; // esp
  int v19; // esi
  IMorph *v20; // eax
  mstudioflex_t *v21; // [esp-8h] [ebp-828h]
  _BYTE v22[12]; // [esp+0h] [ebp-820h] BYREF
  mstudiomesh_t *ppMeshes[512]; // [esp+Ch] [ebp-814h]
  MorphWeight_t *pWeights; // [esp+80Ch] [ebp-14h]
  CStudioRender *v25; // [esp+810h] [ebp-10h]
  int i; // [esp+814h] [ebp-Ch]
  int nActiveMeshCount; // [esp+818h] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+81Ch] [ebp-4h]
  mstudiomodel_t *pSubModela; // [esp+828h] [ebp+8h]
  mstudiomodel_t *pSubModelb; // [esp+828h] [ebp+8h]

  m_pRC = this->m_pRC;
  v4 = (*((_BYTE *)&m_pRC->m_Config + 56) & 4) == 0;
  v25 = this;
  if ( !v4
    && (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) != 0
    && (*((_BYTE *)this + 3685872) & 2) == 0
    && g_pMaterialSystemHardwareConfig->HasFastVertexTextures(this: g_pMaterialSystemHardwareConfig) )
  {
    nummeshes = pSubModel->nummeshes;
    nActiveMeshCount = 0;
    if ( nummeshes > 0 )
    {
      pRenderContext.m_pObject = (IMatRenderContext *)this->m_pStudioMeshes;
      v6 = &pSubModel->name[pSubModel->meshindex + 16];
      for ( pSubModela = (mstudiomodel_t *)nummeshes;
            pSubModela != nullptr;
            pSubModela = (mstudiomodel_t *)((char *)pSubModela - 1) )
      {
        v7 = &pRenderContext.m_pObject[2 * *((_DWORD *)v6 + 4)];
        if ( *(_DWORD *)v6 != 0 )
        {
          v8 = (int)v7->__vftable;
          v9 = 0;
          if ( (int)v7->__vftable > 0 )
          {
            p_BeginRender = &v7[1].BeginRender;
            while ( (*p_BeginRender & 4) == 0 )
            {
              ++v9;
              p_BeginRender += 11;
              if ( v9 >= v8 )
                goto LABEL_14;
            }
            v11 = nActiveMeshCount;
            ppMeshes[nActiveMeshCount] = (mstudiomesh_t *)(v6 - 16);
            nActiveMeshCount = v11 + 1;
          }
        }
LABEL_14:
        v6 += 116;
      }
      v12 = nActiveMeshCount;
      if ( nActiveMeshCount != 0 )
      {
        v13 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
        m_pObject = v13;
        pRenderContext.m_pObject = v13;
        if ( v13 != nullptr )
          v13->BeginRender(this: v13);
        m_pObject->BeginMorphAccumulation(this: m_pObject);
        i = 0;
        if ( v12 > 0 )
        {
          do
          {
            v15 = ppMeshes[i];
            numflexes = v15->numflexes;
            v17 = &v25->m_pStudioMeshes[v15->meshid];
            v18 = alloca(16 * numflexes);
            v21 = (mstudioflex_t *)((char *)v15 + v15->flexindex);
            pWeights = (MorphWeight_t *)v22;
            CStudioRender::ComputeFlexWeights(
              this: v25,
              nFlexCount: numflexes,
              pFlex: v21,
              pWeights: (MorphWeight_t *)v22);
            v19 = 0;
            if ( v17->m_NumGroup > 0 )
            {
              pSubModelb = nullptr;
              do
              {
                v20 = *(IMorph **)&pSubModelb->name[(unsigned int)v17->m_pMeshGroup + 40];
                if ( v20 != nullptr )
                  pRenderContext.m_pObject->AccumulateMorph(
                    this: pRenderContext.m_pObject,
                    a2: v20,
                    a3: numflexes,
                    a4: pWeights);
                pSubModelb = (mstudiomodel_t *)((char *)pSubModelb + 44);
                ++v19;
              }
              while ( v19 < v17->m_NumGroup );
            }
            ++i;
          }
          while ( i < nActiveMeshCount );
          m_pObject = pRenderContext.m_pObject;
        }
        m_pObject->EndMorphAccumulation(this: m_pObject);
        m_pObject->EndRender(this: m_pObject);
        m_pObject->Release(this: m_pObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D7C0
// Name: public: void CStudioRender::PushScissor(struct FlashlightState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::PushScissor(CStudioRender *this, FlashlightState_t *state)
{
  IMatRenderContext *v2; // esi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  if ( r_flashlightscissor.m_pParent != nullptr
    && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0
    && state->m_bScissor
    && v2->GetRenderTarget(this: v2) == nullptr )
  {
    v2->PushScissorRect(this: v2, a2: state->m_nLeft, a3: state->m_nTop, a4: state->m_nRight, a5: state->m_nBottom);
  }
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D850
// Name: public: void CStudioRender::PopScissor(struct FlashlightState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::PopScissor(CStudioRender *this, FlashlightState_t *state)
{
  IMatRenderContext *v2; // esi

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  if ( r_flashlightscissor.m_pParent != nullptr
    && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0
    && state->m_bScissor
    && v2->GetRenderTarget(this: v2) == nullptr )
  {
    v2->PopScissorRect(this: v2);
  }
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D8D0
// Name: private: void CStudioRender::DrawFlashlightDecals(struct DrawModelInfo_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawFlashlightDecals(
        CStudioRender *this@<ecx>,
        int a2@<ebx>,
        const DrawModelInfo_t *info,
        int lod)
{
  int v5; // edi
  int v6; // ebx
  CStudioRender::ShadowState_t *m_pMemory; // eax
  int i; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( this->m_ShadowState.m_Size != 0 )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 336))(a1: v6, a2: 1);
    for ( i = 0; i < this->m_ShadowState.m_Size; ++i )
    {
      m_pMemory = this->m_ShadowState.m_Memory.m_pMemory;
      if ( m_pMemory[v5].m_pMaterial == nullptr
        && m_pMemory[v5].m_pFlashlightState != nullptr
        && m_pMemory[v5].m_pWorldToTexture != nullptr )
      {
        (*(void (__thiscall **)(int, FlashlightState_t *, VMatrix *, ITexture *))(*(_DWORD *)v6 + 516))(
          a1: v6,
          a2: m_pMemory[v5].m_pFlashlightState,
          a3: m_pMemory[v5].m_pWorldToTexture,
          a4: m_pMemory[v5].m_pFlashlightDepthTexture);
        CStudioRender::PushScissor(this, state: this->m_ShadowState.m_Memory.m_pMemory[v5].m_pFlashlightState);
        CStudioRender::DrawDecal(this, a2: (int)this, drawInfo: info, lod, body: info->m_Body);
        CStudioRender::PopScissor(this, state: this->m_ShadowState.m_Memory.m_pMemory[v5].m_pFlashlightState);
      }
      ++v5;
    }
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 336))(a1: v6, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D9C0
// Name: private: void CStudioRender::R_StudioFlexMeshGroup(struct studiomeshgroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioFlexMeshGroup(CStudioRender *this, studiomeshgroup_t *pGroup)
{
  IMatRenderContext *v2; // edi
  IMesh *v3; // eax
  int v4; // esi
  int v5; // ebx
  float *m_pCurrPosition; // ecx
  CCachedRenderData *p_m_VertexCache; // esi
  CCachedRenderData::CacheIndex_t *m_pFirstThinFlexIndex; // edx
  int v9; // eax
  float *p_x; // eax
  float *m_pCurrNormal; // edx
  float *v12; // eax
  int m_nVertexCount; // eax
  int v14; // ecx
  IMesh *m_pMesh; // ecx
  int m_NumVertices; // [esp-Ch] [ebp-20Ch]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F4h] BYREF
  CStudioRender *v18; // [esp+1F4h] [ebp-Ch]
  IMesh *pMesh; // [esp+1F8h] [ebp-8h]
  int nVertexOffsetInBytes; // [esp+1FCh] [ebp-4h]

  v18 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "R_StudioFlexMeshGroup",
    a3: 0,
    a4: "Other_Model_Rendering",
    a5: false,
    a6: 4);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v3 = v2->GetFlexMesh(this: v2);
  m_NumVertices = pGroup->m_NumVertices;
  pMesh = v3;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v3,
    type: MATERIAL_HETEROGENOUS,
    nVertexCount: m_NumVertices,
    nIndexCount: 0,
    pMeshSettings: nullptr);
  v4 = meshBuilder.m_VertexBuilder.m_ActualVertexSize * meshBuilder.m_VertexBuilder.m_nFirstVertex;
  v5 = 0;
  nVertexOffsetInBytes = meshBuilder.m_VertexBuilder.m_ActualVertexSize * meshBuilder.m_VertexBuilder.m_nFirstVertex;
  if ( pGroup->m_NumVertices <= 0 )
  {
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    p_m_VertexCache = &v18->m_VertexCache;
    do
    {
      m_pFirstThinFlexIndex = p_m_VertexCache->m_pFirstThinFlexIndex;
      v9 = pGroup->m_pGroupIndexToMeshIndex[v5];
      if ( m_pFirstThinFlexIndex != nullptr && m_pFirstThinFlexIndex[v9].m_Tag == p_m_VertexCache->m_CurrentTag )
      {
        p_x = &p_m_VertexCache->m_pThinFlexVerts[p_m_VertexCache->m_pFirstThinFlexIndex[v9].m_VertexIndex].m_Position.x;
        *m_pCurrPosition = *p_x;
        m_pCurrPosition[1] = p_x[1];
        m_pCurrPosition[2] = p_x[2];
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_x[4];
        m_pCurrNormal[1] = p_x[5];
        m_pCurrNormal[2] = p_x[6];
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pWrinkle
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_Wrinkle) = p_x[3];
      }
      else
      {
        *m_pCurrPosition = 0.0;
        m_pCurrPosition[1] = 0.0;
        m_pCurrPosition[2] = 0.0;
        v12 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
        v12[1] = 0.0;
        v12[2] = 0.0;
        *(float *)((char *)meshBuilder.m_VertexBuilder.m_pWrinkle
                 + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_Wrinkle) = 0.0;
      }
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v14 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v14;
      if ( v14 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      {
        m_nVertexCount = v14;
        meshBuilder.m_VertexBuilder.m_nVertexCount = v14;
      }
      meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                          + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
      m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      ++v5;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
    }
    while ( v5 < pGroup->m_NumVertices );
    v4 = nVertexOffsetInBytes;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  m_pMesh = pGroup->m_pMesh;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  m_pMesh->SetFlexMesh(this: m_pMesh, a2: pMesh, a3: v4);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
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
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC80
// Name: private: void CStudioRender::R_StudioProcessFlexedMesh(struct mstudiomesh_t __near *,class CMeshBuilder __near &,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioProcessFlexedMesh(
        CStudioRender *this,
        mstudiomesh_t *pmesh,
        CMeshBuilder *meshBuilder,
        int numVertices,
        unsigned __int16 *pGroupToMesh)
{
  CStudioRender *v5; // edi
  const vertexFileHeader_t *FatVertexData; // eax
  _DWORD *id; // ecx
  unsigned int v8; // esi
  int v9; // eax
  int v10; // edx
  float *v11; // ecx
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // esi
  float *m_pCurrPosition; // esi
  int v14; // edx
  float *m_pCurrNormal; // edi
  float *v16; // esi
  _QWORD *v17; // ecx
  __int64 v18; // xmm2_8
  float *v19; // edi
  float *v20; // edi
  float *v21; // esi
  _QWORD *p_x; // edx
  int v23; // ecx
  int v24; // ecx
  float *v25; // edx
  CCachedRenderData::CacheIndex_t *v26; // esi
  float *v27; // esi
  float *v28; // ecx
  double v29; // st7
  float *v30; // ecx
  float *v31; // esi
  double v32; // st7
  float *v33; // esi
  float *v34; // ecx
  int v35; // ecx
  Vector4D *pStudioTangentS; // [esp+8h] [ebp-Ch]
  mstudiovertex_t *pVertices; // [esp+10h] [ebp-4h]
  int j; // [esp+1Ch] [ebp+8h]
  int ja; // [esp+1Ch] [ebp+8h]
  int jb; // [esp+1Ch] [ebp+8h]

  v5 = this;
  FatVertexData = GetFatVertexData(pMesh: pmesh, pStudioHdr: this->m_pStudioHdr);
  if ( FatVertexData != nullptr )
  {
    id = (_DWORD *)FatVertexData->id;
    j = FatVertexData[-1].numLODVertexes[3];
    v8 = *id + 48 * (j + *(id - 6) / 0x30u);
    pVertices = (mstudiovertex_t *)v8;
    if ( *(_DWORD *)(FatVertexData->id + 4) != 0 )
    {
      v9 = j + (*(id - 5) >> 4);
      ja = 0;
      pStudioTangentS = (Vector4D *)(id[1] + 16 * v9);
      if ( numVertices > 0 )
      {
        while ( 1 )
        {
          v10 = pGroupToMesh[ja];
          v11 = (float *)(v8 + 48 * v10);
          m_pFirstFlexIndex = v5->m_VertexCache.m_pFirstFlexIndex;
          if ( m_pFirstFlexIndex != nullptr && m_pFirstFlexIndex[v10].m_Tag == v5->m_VertexCache.m_CurrentTag )
          {
            m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            v14 = (int)&v5->m_VertexCache.m_pFlexVerts[v5->m_VertexCache.m_pFirstFlexIndex[v10].m_VertexIndex];
            *m_pCurrPosition = *(float *)v14;
            m_pCurrPosition[1] = *(float *)(v14 + 4);
            m_pCurrPosition[2] = *(float *)(v14 + 8);
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 0 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 1 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 4) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 2 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 8) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 3 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 12) = 0.0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 1] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 2] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 3] = 0;
            m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
            v16 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
            *m_pCurrNormal = *(float *)(v14 + 16);
            m_pCurrNormal[1] = *(float *)(v14 + 20);
            m_pCurrNormal[2] = *(float *)(v14 + 24);
            *v16 = v11[10];
            v16[1] = v11[11];
            v17 = (_QWORD *)((char *)meshBuilder->m_VertexBuilder.m_pUserData
                           + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                           * meshBuilder->m_VertexBuilder.m_VertexSize_UserData);
            *v17 = *(_QWORD *)(v14 + 32);
            v18 = *(_QWORD *)(v14 + 40);
          }
          else
          {
            v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            *v19 = v11[4];
            v19[1] = v11[5];
            v19[2] = v11[6];
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 0 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 1 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 4) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 2 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 8) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 3 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 12) = 0.0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 1] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 2] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 3] = 0;
            v20 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
            v21 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
            *v20 = v11[7];
            p_x = (_QWORD *)&pStudioTangentS[v10].x;
            v20[1] = v11[8];
            v20[2] = v11[9];
            *v21 = v11[10];
            v21[1] = v11[11];
            v17 = (_QWORD *)((char *)meshBuilder->m_VertexBuilder.m_pUserData
                           + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                           * meshBuilder->m_VertexBuilder.m_VertexSize_UserData);
            *v17 = *p_x;
            v18 = p_x[1];
          }
          v17[1] = v18;
          v23 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
          if ( v23 > meshBuilder->m_VertexBuilder.m_nVertexCount )
            meshBuilder->m_VertexBuilder.m_nVertexCount = v23;
          meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                                 + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          if ( ++ja >= numVertices )
            break;
          v5 = this;
          v8 = (unsigned int)pVertices;
        }
      }
    }
    else
    {
      jb = 0;
      if ( numVertices > 0 )
      {
        while ( 1 )
        {
          v24 = pGroupToMesh[jb];
          v25 = (float *)(v8 + 48 * v24);
          v26 = v5->m_VertexCache.m_pFirstFlexIndex;
          if ( v26 != nullptr && v26[v24].m_Tag == v5->m_VertexCache.m_CurrentTag )
          {
            v27 = &v5->m_VertexCache.m_pFlexVerts[v5->m_VertexCache.m_pFirstFlexIndex[v24].m_VertexIndex].m_Position.x;
            v28 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            *v28 = *v27;
            v28[1] = v27[1];
            v28[2] = v27[2];
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 0 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 1 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 4) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 2 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 8) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 3 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 12) = 0.0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 1] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 2] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 3] = 0;
            v5 = this;
            v29 = v27[4];
            v30 = v27 + 4;
            v31 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
            *v31 = v29;
            v31[1] = v30[1];
            v32 = v30[2];
          }
          else
          {
            v33 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
            *v33 = v25[4];
            v33[1] = v25[5];
            v33[2] = v25[6];
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 0 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 1 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 4) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 2 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 8) = 0.0;
            if ( meshBuilder->m_VertexBuilder.m_NumBoneWeights > 3 )
              *(float *)((char *)meshBuilder->m_VertexBuilder.m_pBoneWeight
                       + meshBuilder->m_VertexBuilder.m_nCurrentVertex
                       * meshBuilder->m_VertexBuilder.m_VertexSize_BoneWeight
                       + 12) = 0.0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 1] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 2] = 0;
            meshBuilder->m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder->m_VertexBuilder.m_nCurrentVertex
                                                          * meshBuilder->m_VertexBuilder.m_VertexSize_BoneMatrixIndex
                                                          + 3] = 0;
            v31 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
            *v31 = v25[7];
            v31[1] = v25[8];
            v32 = v25[9];
          }
          v34 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
          v31[2] = v32;
          *v34 = v25[10];
          v34[1] = v25[11];
          v35 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
          if ( v35 > meshBuilder->m_VertexBuilder.m_nVertexCount )
            meshBuilder->m_VertexBuilder.m_nVertexCount = v35;
          meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                                 + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          if ( ++jb >= numVertices )
            break;
          v8 = (unsigned int)pVertices;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E330
// Name: private: int CStudioRender::R_StudioDrawGroupSWSkin(struct studiomeshgroup_t __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioDrawGroupSWSkin(CStudioRender *this, studiomeshgroup_t *pGroup, IMesh *pMesh)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *m_pObject; // esi
  OptimizedModel::StripHeader_t *v6; // esi
  IMesh_vtbl *v7; // edi
  int PrimitiveTypeForStripHeaderFlags; // eax
  Vector4D vecDiffuseModulation; // [esp+Ch] [ebp-20h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  int numFacesRendered; // [esp+24h] [ebp-8h]
  unsigned int v14; // [esp+28h] [ebp-4h]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  numFacesRendered = 0;
  m_pObject = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pObject->SetNumBoneWeights(this: m_pObject, a2: 0);
  CStudioRender::ComputeDiffuseModulation(this, pDiffuseModulation: &vecDiffuseModulation);
  j = 0;
  if ( pGroup->m_NumStrips > 0 )
  {
    v14 = 0;
    do
    {
      v6 = &pGroup->m_pStripData[v14 / 0x23];
      v7 = pMesh->IVertexBuffer::__vftable;
      PrimitiveTypeForStripHeaderFlags = GetPrimitiveTypeForStripHeaderFlags(Flags: v6->flags);
      v7->SetPrimitiveType(this: pMesh, a2: (MaterialPrimitiveType_t)PrimitiveTypeForStripHeaderFlags);
      pMesh->DrawModulated(this: pMesh, a2: &vecDiffuseModulation, a3: v6->indexOffset, a4: v6->numIndices);
      numFacesRendered += pGroup->m_pUniqueFaces[j];
      v14 += 35;
      ++j;
    }
    while ( j < pGroup->m_NumStrips );
    m_pObject = pRenderContext.m_pObject;
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return numFacesRendered;
}

//------------------------------------------------------------------------------
// Address: 0x1000E490
// Name: private: void CStudioRender::R_StudioRestoreMesh<1>(struct mstudiomesh_t __near *,struct studiomeshgroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioRestoreMesh<1>(
        CStudioRender *this,
        Vector4D *pmesh,
        studiomeshgroup_t *pMeshData)
{
  const vertexFileHeader_t *FatVertexData; // eax
  int v4; // ebx
  _DWORD *id; // ecx
  int v6; // esi
  int v7; // edi
  float *m_pCurrPosition; // ecx
  mstudiovertex_t *v9; // esi
  float *v10; // eax
  int v11; // edx
  float v12; // xmm4_4
  int v13; // edi
  float z; // xmm3_4
  float y; // xmm7_4
  float x; // xmm0_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  CMeshBuilder meshBuilder; // [esp+18h] [ebp-1F8h] BYREF
  float v22; // [esp+200h] [ebp-10h]
  float w; // [esp+204h] [ebp-Ch]
  mstudiovertex_t *pVertices; // [esp+208h] [ebp-8h]
  float v25; // [esp+20Ch] [ebp-4h]
  Vector4D *pStudioTangentS; // [esp+218h] [ebp+8h]

  FatVertexData = GetFatVertexData(pMesh: (mstudiomesh_t *)pmesh, pStudioHdr: this->m_pStudioHdr);
  v4 = 0;
  if ( FatVertexData != nullptr )
  {
    id = (_DWORD *)FatVertexData->id;
    v6 = FatVertexData[-1].numLODVertexes[3];
    pVertices = (mstudiovertex_t *)(*id + 48 * (v6 + *(id - 6) / 0x30u));
    if ( id[1] != 0 )
      pStudioTangentS = (Vector4D *)(id[1] + 16 * (v6 + (*(id - 5) >> 4)));
    else
      pStudioTangentS = nullptr;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::BeginModify(
      this: &meshBuilder,
      pMesh: pMeshData->m_pMesh,
      nFirstVertex: 0,
      nVertexCount: -1,
      nFirstIndex: 0,
      nIndexCount: 0);
    meshBuilder.m_CompressionType = VERTEX_COMPRESSION_ON;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_ON;
    if ( meshBuilder.m_VertexBuilder.m_nVertexCount > 0 )
    {
      do
      {
        CVertexBuilder::SelectVertex(this: &meshBuilder.m_VertexBuilder, nIndex: v4);
        v7 = pMeshData->m_pGroupIndexToMeshIndex[v4];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v9 = &pVertices[v7];
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->m_vecPosition.x;
        m_pCurrPosition[1] = v9->m_vecPosition.y;
        m_pCurrPosition[2] = v9->m_vecPosition.z;
        CVertexBuilder::CompressedNormal3f<1>(
          this: &meshBuilder.m_VertexBuilder,
          nx: v9->m_vecNormal.x,
          ny: v9->m_vecNormal.y,
          nz: v9->m_vecNormal.z);
        v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v9->m_vecTexCoord.x;
        v10[1] = v9->m_vecTexCoord.y;
        if ( pStudioTangentS != nullptr )
        {
          v11 = *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrNormal;
          v12 = -1.0;
          v13 = v7;
          z = pStudioTangentS[v13].z;
          y = pStudioTangentS[v13].y;
          w = pStudioTangentS[v13].w;
          x = pStudioTangentS[v13].x;
          v22 = z;
          if ( x >= 0.0 )
            v17 = 1.0;
          else
            v17 = -1.0;
          if ( y >= 0.0 )
            v18 = 1.0;
          else
            v18 = -1.0;
          if ( z >= 0.0 )
            v12 = 1.0;
          v19 = v17 * x;
          v20 = 1.0 / (float)((float)((float)(v18 * y) + (float)(v17 * x)) + (float)(v12 * v22));
          v25 = 1.0 - v17;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrNormal = v11
                                                               | (((unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)((float)(v20 * v19) * 63.0) * v17) - (float)((float)(1.0 - v17) * 0.5)) + 64.0) * v12) - (float)((float)(1.0 - v12) * 0.5))
                                                                                               + 128.0)
                                                                 | ((unsigned __int8)(int)(float)((float)((float)((float)((float)((float)((float)((float)(v20 * (float)(v18 * y)) * 63.0) * v18) - (float)((float)(1.0 - v18) * 0.5)) + 64.0) * w) - (float)((float)(1.0 - w) * 0.5))
                                                                                                + 128.0) << 8)) << 16);
        }
        ++v4;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      }
      while ( v4 < meshBuilder.m_VertexBuilder.m_nVertexCount );
    }
    meshBuilder.m_pMesh->ModifyEnd(this: meshBuilder.m_pMesh, a2: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E720
// Name: private: void CStudioRender::R_StudioRestoreMesh<0>(struct mstudiomesh_t __near *,struct studiomeshgroup_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioRestoreMesh<0>(
        CStudioRender *this,
        Vector4D *pmesh,
        studiomeshgroup_t *pMeshData)
{
  const vertexFileHeader_t *FatVertexData; // eax
  int v4; // edi
  _DWORD *id; // ecx
  int v6; // ebx
  mstudiovertex_t *v7; // esi
  int v8; // edx
  mstudiovertex_t *v9; // eax
  float *m_pCurrPosition; // esi
  float *m_pCurrNormal; // ecx
  float y; // xmm0_4
  float z; // xmm1_4
  float *v14; // ecx
  int v15; // edx
  _QWORD *v16; // eax
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-1ECh] BYREF
  mstudiovertex_t *pVertices; // [esp+1ECh] [ebp-4h]
  Vector4D *pStudioTangentS; // [esp+1F8h] [ebp+8h]

  FatVertexData = GetFatVertexData(pMesh: (mstudiomesh_t *)pmesh, pStudioHdr: this->m_pStudioHdr);
  v4 = 0;
  if ( FatVertexData != nullptr )
  {
    id = (_DWORD *)FatVertexData->id;
    v6 = FatVertexData[-1].numLODVertexes[3];
    v7 = (mstudiovertex_t *)(*id + 48 * (v6 + *(id - 6) / 0x30u));
    pVertices = v7;
    if ( id[1] != 0 )
      pStudioTangentS = (Vector4D *)(id[1] + 16 * (v6 + (*(id - 5) >> 4)));
    else
      pStudioTangentS = nullptr;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::BeginModify(
      this: &meshBuilder,
      pMesh: pMeshData->m_pMesh,
      nFirstVertex: 0,
      nVertexCount: -1,
      nFirstIndex: 0,
      nIndexCount: 0);
    meshBuilder.m_CompressionType = VERTEX_COMPRESSION_NONE;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_NONE;
    if ( meshBuilder.m_VertexBuilder.m_nVertexCount > 0 )
    {
      while ( 1 )
      {
        CVertexBuilder::SelectVertex(this: &meshBuilder.m_VertexBuilder, nIndex: v4);
        v8 = pMeshData->m_pGroupIndexToMeshIndex[v4];
        v9 = &v7[v8];
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v9->m_vecPosition.x;
        m_pCurrPosition[1] = v9->m_vecPosition.y;
        m_pCurrPosition[2] = v9->m_vecPosition.z;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        y = v9->m_vecNormal.y;
        z = v9->m_vecNormal.z;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = v9->m_vecNormal.x;
        m_pCurrNormal[1] = y;
        m_pCurrNormal[2] = z;
        v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v9->m_vecTexCoord.x;
        v14[1] = v9->m_vecTexCoord.y;
        if ( pStudioTangentS != nullptr )
        {
          v15 = v8;
          v16 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                         + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                         * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
          *v16 = *(_QWORD *)&pStudioTangentS[v15].x;
          v16[1] = *(_QWORD *)&pStudioTangentS[v15].z;
        }
        ++v4;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
        if ( v4 >= meshBuilder.m_VertexBuilder.m_nVertexCount )
          break;
        v7 = pVertices;
      }
    }
    meshBuilder.m_pMesh->ModifyEnd(this: meshBuilder.m_pMesh, a2: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E880
// Name: private: int CStudioRender::R_StudioDrawStaticMesh(class IMatRenderContext __near *,struct mstudiomesh_t __near *,struct studiomeshgroup_t __near *,enum StudioModelLighting_t,float,class IMaterial __near *,int,struct ColorMeshInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioDrawStaticMesh(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        Vector4D *pmesh,
        studiomeshgroup_t *pGroup,
        StudioModelLighting_t lighting,
        float r_blend,
        IMaterial *pMaterial,
        int lod,
        ColorMeshInfo_t *pColorMeshes)
{
  StudioRenderContext_t *m_pRC; // eax
  IMaterial *v11; // esi
  IMesh *v15; // esi
  int m_nVertexCount; // eax
  int v17; // esi
  __int16 m_ColorMeshID; // ax
  int v19; // eax
  CMeshBuilder meshBuilder; // [esp+34h] [ebp-1E8h] BYREF
  int numFacesRendered; // [esp+228h] [ebp+Ch]
  char bUseSOFlex_3; // [esp+233h] [ebp+17h]
  char bUseHWFlex_3; // [esp+23Bh] [ebp+1Fh]
  bool bTangentSpace; // [esp+240h] [ebp+24h]

  if ( pColorMeshes != nullptr )
  {
LABEL_9:
    if ( pGroup->m_MeshNeedsRestore )
    {
      if ( (pGroup->m_pMesh->GetVertexFormat(this: pGroup->m_pMesh) & 0x400) != 0 )
        CStudioRender::R_StudioRestoreMesh<1>(this, pmesh, pMeshData: pGroup);
      else
        CStudioRender::R_StudioRestoreMesh<0>(this, pmesh, pMeshData: pGroup);
      pGroup->m_MeshNeedsRestore = false;
    }
    if ( (*((_BYTE *)&this->m_pRC->m_Config + 56) & 4) == 0
      || pGroup->m_pMorph == nullptr
      || (bUseHWFlex_3 = 1, (*((_BYTE *)this + 3685872) & 2) != 0) )
    {
      bUseHWFlex_3 = 0;
    }
    if ( !g_pMaterialSystemHardwareConfig->SupportsStreamOffset(this: g_pMaterialSystemHardwareConfig)
      || (bUseSOFlex_3 = 1, bUseHWFlex_3 != 0) )
    {
      bUseSOFlex_3 = 0;
    }
    if ( (pGroup->m_Flags & 4) != 0 && (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) != 0 )
    {
      if ( bUseHWFlex_3 != 0 )
        pRenderContext->BindMorph(this: pRenderContext, a2: pGroup->m_pMorph);
      if ( bUseSOFlex_3 != 0 )
      {
        CStudioRender::R_StudioProcessFlexedMesh_StreamOffset(this, (mstudiomesh_t *)pmesh, lod);
        CStudioRender::R_StudioFlexMeshGroup(this, pGroup);
      }
    }
    if ( pColorMeshes == nullptr || (m_ColorMeshID = pGroup->m_ColorMeshID) == -1 )
      v19 = CStudioRender::R_StudioDrawGroupHWSkin(
              this,
              pRenderContext,
              pGroup,
              pMesh: pGroup->m_pMesh,
              pColorMeshInfo: nullptr);
    else
      v19 = CStudioRender::R_StudioDrawGroupHWSkin(
              this,
              pRenderContext,
              pGroup,
              pMesh: pGroup->m_pMesh,
              pColorMeshInfo: &pColorMeshes[m_ColorMeshID]);
    numFacesRendered = v19;
    if ( (pGroup->m_Flags & 4) != 0 && (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) != 0 )
    {
      if ( bUseHWFlex_3 != 0 )
        pRenderContext->BindMorph(this: pRenderContext, a2: nullptr);
      if ( bUseSOFlex_3 != 0 )
        pGroup->m_pMesh->DisableFlexMesh(this: pGroup->m_pMesh);
    }
    return numFacesRendered;
  }
  m_pRC = this->m_pRC;
  if ( (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 2) != 0
    || (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37) & 3) != 0 )
  {
    v11 = pMaterial;
  }
  else
  {
    v11 = pMaterial;
    if ( (pMaterial == nullptr || !pMaterial->NeedsSoftwareSkinning(this: pMaterial))
      && (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 37) & 8) == 0
      && (lighting == LIGHTING_HARDWARE || lighting == LIGHTING_MOUTH) )
    {
      goto LABEL_9;
    }
  }
  if ( (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) & 8) != 0 )
    return 0;
  bTangentSpace = v11 != nullptr && v11->NeedsTangentSpace(this: v11);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->LoadIdentity(this: pRenderContext);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v15 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, IMesh *, _DWORD))pRenderContext->GetDynamicMeshEx)(
                   a1: pRenderContext,
                   a2: 655619,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: pGroup->m_pMesh,
                   a7: 0);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v15,
    type: MATERIAL_HETEROGENOUS,
    nVertexCount: pGroup->m_NumVertices,
    nIndexCount: 0,
    pMeshSettings: nullptr);
  CStudioRender::R_StudioSoftwareProcessMesh(
    this,
    (mstudiomesh_t *)pmesh,
    &meshBuilder,
    numVertices: pGroup->m_NumVertices,
    pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
    lighting,
    doFlex: false,
    r_blend,
    bNeedsTangentSpace: bTangentSpace,
    pMaterial);
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
  v17 = CStudioRender::R_StudioDrawGroupSWSkin(this, pGroup, pMesh: v15);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBB0
// Name: private: int CStudioRender::R_StudioDrawDynamicMesh(class IMatRenderContext __near *,struct mstudiomesh_t __near *,struct studiomeshgroup_t __near *,enum StudioModelLighting_t,float,class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall CStudioRender::R_StudioDrawDynamicMesh(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        Vector4D *pmesh,
        studiomeshgroup_t *pGroup,
        StudioModelLighting_t lighting,
        float r_blend,
        IMaterial *pMaterial,
        int lod)
{
  bool v9; // zf
  CStudioRender *v10; // ebx
  StudioRenderContext_t *m_pRC; // ecx
  char v12; // al
  const vertexFileHeader_t *result; // eax
  int m_NumStrips; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // edx
  int *m_pUniqueFaces; // eax
  unsigned int v20; // ecx
  int v21; // ebx
  int v22; // ebx
  int m_nVertexCount; // eax
  int v24; // eax
  IMesh *v25; // ebx
  int v26; // ecx
  int v27; // eax
  IMesh *v28; // ebx
  int m_NumVertices; // eax
  int v30; // eax
  IMesh *v31; // ebx
  int v32; // ecx
  int v33; // eax
  __int64 v34; // [esp+D4h] [ebp-408h]
  CMeshBuilder meshBuilder; // [esp+F8h] [ebp-3E4h] BYREF
  CMeshBuilder v36; // [esp+2E0h] [ebp-1FCh] BYREF
  int s; // [esp+4C8h] [ebp-14h]
  BOOL bTangentSpace; // [esp+4CCh] [ebp-10h]
  int TotalFaces; // [esp+4D0h] [ebp-Ch]
  CStudioRender *v40; // [esp+4D4h] [ebp-8h]
  BOOL bDoFlex; // [esp+4D8h] [ebp-4h]
  int savedregs; // [esp+4DCh] [ebp+0h] BYREF
  IMesh *pMesh; // [esp+4E4h] [ebp+8h]
  IMesh *pMesha; // [esp+4E4h] [ebp+8h]
  IMesh *pMeshb; // [esp+4E4h] [ebp+8h]
  IMesh *pMeshc; // [esp+4E4h] [ebp+8h]
  bool bSWSkin_3; // [esp+4EFh] [ebp+13h]
  int numFacesRendered; // [esp+4FCh] [ebp+20h]
  int numFacesRendereda; // [esp+4FCh] [ebp+20h]

  v9 = (pGroup->m_Flags & 4) == 0;
  v10 = this;
  v40 = this;
  if ( v9 || (v9 = (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) & 0x40) == 0, LOBYTE(bDoFlex) = 1, v9) )
    LOBYTE(bDoFlex) = 0;
  LOBYTE(TotalFaces) = (pGroup->m_pStripData->flags & 6) != 0;
  m_pRC = this->m_pRC;
  v12 = *((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37);
  bSWSkin_3 = (v12 & 8) != 0
           || lighting != LIGHTING_HARDWARE && lighting != LIGHTING_MOUTH
           || (v12 & 3) != 0
           || (pGroup->m_Flags & 2) == 0
           || (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 2) != 0
           || (_BYTE)TotalFaces != 0
           || pMaterial != nullptr && pMaterial->NeedsSoftwareSkinning(this: pMaterial);
  if ( !bDoFlex && !bSWSkin_3 )
    return (const vertexFileHeader_t *)CStudioRender::R_StudioDrawStaticMesh(
                                         this: v10,
                                         pRenderContext,
                                         pmesh,
                                         pGroup,
                                         lighting,
                                         r_blend,
                                         pMaterial,
                                         lod,
                                         pColorMeshes: nullptr);
  result = GetFatVertexData(pMesh: (mstudiomesh_t *)pmesh, pStudioHdr: v10->m_pStudioHdr);
  if ( result != nullptr )
  {
    pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
    pRenderContext->LoadIdentity(this: pRenderContext);
    if ( bDoFlex )
      CStudioRender::R_StudioFlexVerts(this: v10, (mstudiomesh_t *)pmesh, lod, bQuadList: TotalFaces);
    if ( (_BYTE)TotalFaces != 0 )
      CStudioRender::GenerateBicubicPatches(this: v10, (mstudiomesh_t *)pmesh, pGroup, bDoFlex);
    LOBYTE(bTangentSpace) = pMaterial != nullptr && pMaterial->NeedsTangentSpace(this: pMaterial);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v34 = (unsigned __int8)TotalFaces != 0 ? 133635 : 655619;
    pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, IMesh *, _DWORD))pRenderContext->GetDynamicMeshEx)(
                       a1: pRenderContext,
                       a2: v34,
                       a3: HIDWORD(v34),
                       a4: 0,
                       a5: 0,
                       a6: pGroup->m_pMesh,
                       a7: 0);
    if ( (_BYTE)TotalFaces != 0 )
    {
      m_NumStrips = pGroup->m_NumStrips;
      v16 = 0;
      v17 = 0;
      v18 = 0;
      numFacesRendered = 0;
      TotalFaces = 0;
      if ( m_NumStrips >= 2 )
      {
        m_pUniqueFaces = pGroup->m_pUniqueFaces;
        v20 = ((unsigned int)(m_NumStrips - 2) >> 1) + 1;
        s = 2 * v20;
        v21 = 0;
        do
        {
          v18 += *m_pUniqueFaces;
          v21 += m_pUniqueFaces[1];
          m_pUniqueFaces += 2;
          --v20;
        }
        while ( v20 != 0 );
        v16 = s;
        numFacesRendered = v21;
        v17 = TotalFaces;
      }
      if ( v16 < pGroup->m_NumStrips )
        v17 = pGroup->m_pUniqueFaces[v16];
      v22 = v18 + numFacesRendered + v17;
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh,
        type: MATERIAL_HETEROGENOUS,
        nVertexCount: 4 * v22,
        nIndexCount: 0,
        pMeshSettings: nullptr);
      CStudioRender::SoftwareProcessQuadMesh(
        this: v40,
        (mstudiomesh_t *)pmesh,
        &meshBuilder,
        numFaces: v22,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
        pTopologyIndices: pGroup->m_pTopologyIndices,
        bTangentSpace,
        bDoFlex);
      v10 = v40;
    }
    else if ( bSWSkin_3 )
    {
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh,
        type: MATERIAL_HETEROGENOUS,
        nVertexCount: pGroup->m_NumVertices,
        nIndexCount: 0,
        pMeshSettings: nullptr);
      CStudioRender::R_StudioSoftwareProcessMesh(
        this: v10,
        (mstudiomesh_t *)pmesh,
        &meshBuilder,
        numVertices: pGroup->m_NumVertices,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
        lighting,
        doFlex: bDoFlex,
        r_blend,
        bNeedsTangentSpace: bTangentSpace,
        pMaterial);
    }
    else if ( bDoFlex )
    {
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh,
        type: MATERIAL_HETEROGENOUS,
        nVertexCount: pGroup->m_NumVertices,
        nIndexCount: 0,
        pMeshSettings: nullptr);
      CStudioRender::R_StudioProcessFlexedMesh(
        this: v10,
        (mstudiomesh_t *)pmesh,
        &meshBuilder,
        numVertices: pGroup->m_NumVertices,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex);
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
    if ( bSWSkin_3 )
      v24 = CStudioRender::R_StudioDrawGroupSWSkin(this: v10, pGroup, pMesh);
    else
      v24 = CStudioRender::R_StudioDrawGroupHWSkin(this: v10, pRenderContext, pGroup, pMesh, pColorMeshInfo: nullptr);
    numFacesRendereda = v24;
    if ( (*((_BYTE *)&v10->m_pRC->m_Config.StudioRenderConfig_t + 37) & 1) != 0 )
    {
      pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: 0);
      pRenderContext->Bind(this: pRenderContext, a2: v40->m_pMaterialTangentFrame, a3: nullptr);
      CMeshBuilder::CMeshBuilder(this: &v36);
      v25 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
      v26 = 2 * pGroup->m_NumVertices;
      v36.m_pMesh = v25;
      v36.m_bGenerateIndices = true;
      v36.m_Type = MATERIAL_LINES;
      pMesha = (IMesh *)v26;
      v25->SetPrimitiveType(this: v25, a2: MATERIAL_LINES);
      v36.m_pMesh->LockMesh(this: v36.m_pMesh, a2: (int)pMesha, a3: (int)pMesha, a4: &v36, a5: nullptr);
      v36.m_IndexBuilder.m_nIndexCount = 0;
      v36.m_IndexBuilder.m_bModify = false;
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      v36.m_IndexBuilder.m_nIndexOffset = v36.m_nFirstVertex;
      v36.m_IndexBuilder.m_pIndexBuffer = &v25->IIndexBuffer;
      v36.m_IndexBuilder.m_pIndices = v36.m_pIndices;
      v36.m_IndexBuilder.m_nMaxIndexCount = (int)pMesha;
      v36.m_IndexBuilder.m_nIndexSize = v36.m_nIndexSize;
      CVertexBuilder::AttachBegin(this: &v36.m_VertexBuilder, pMesh: v25, nMaxVertexCount: (int)pMesha, desc: &v36);
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &v36.m_VertexBuilder);
      CStudioRender::R_StudioSoftwareProcessMesh_Normals(
        this: v40,
        a2: (Vector4D *)&savedregs,
        (mstudiomesh_t *)pmesh,
        meshBuilder: &v36,
        numVertices: pGroup->m_NumVertices,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
        lighting,
        doFlex: bDoFlex,
        r_blend,
        bShowNormals: true,
        bShowTangentS: false,
        bShowTangentT: false);
      if ( v36.m_bGenerateIndices )
      {
        switch ( v36.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v27 = 2 * v36.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v27 = 2 * v36.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v27 = 3 * v36.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v27 = 6 * v36.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v27 = 0;
            break;
          default:
            v27 = v36.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(this: &v36.m_IndexBuilder, primitiveType: v36.m_Type, nIndexCount: v27);
      }
      v36.m_pMesh->UnlockMesh(
        this: v36.m_pMesh,
        a2: v36.m_VertexBuilder.m_nVertexCount,
        a3: v36.m_IndexBuilder.m_nIndexCount,
        a4: &v36);
      v36.m_IndexBuilder.m_pIndexBuffer = nullptr;
      v36.m_IndexBuilder.m_nMaxIndexCount = 0;
      v36.m_VertexBuilder.m_nMaxVertexCount = 0;
      v36.m_VertexBuilder.m_pVertexBuffer = nullptr;
      v36.m_pMesh = nullptr;
      v36.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v25->Draw_2(this: v25, a2: -1, a3: 0);
      pRenderContext->Bind(this: pRenderContext, a2: pMaterial, a3: nullptr);
      CMeshBuilder::~CMeshBuilder(this: &v36);
      v10 = v40;
    }
    if ( (*((_BYTE *)&v10->m_pRC->m_Config.StudioRenderConfig_t + 37) & 2) != 0 )
    {
      pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: 0);
      pRenderContext->Bind(this: pRenderContext, a2: v40->m_pMaterialTangentFrame, a3: nullptr);
      CMeshBuilder::CMeshBuilder(this: &v36);
      v28 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
      m_NumVertices = pGroup->m_NumVertices;
      v36.m_pMesh = v28;
      v36.m_bGenerateIndices = true;
      v36.m_Type = MATERIAL_LINES;
      pMeshb = (IMesh *)(2 * m_NumVertices);
      v28->SetPrimitiveType(this: v28, a2: MATERIAL_LINES);
      v36.m_pMesh->LockMesh(this: v36.m_pMesh, a2: (int)pMeshb, a3: (int)pMeshb, a4: &v36, a5: nullptr);
      v36.m_IndexBuilder.m_nIndexCount = 0;
      v36.m_IndexBuilder.m_bModify = false;
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      v36.m_IndexBuilder.m_nIndexOffset = v36.m_nFirstVertex;
      v36.m_IndexBuilder.m_pIndexBuffer = &v28->IIndexBuffer;
      v36.m_IndexBuilder.m_pIndices = v36.m_pIndices;
      v36.m_IndexBuilder.m_nMaxIndexCount = (int)pMeshb;
      v36.m_IndexBuilder.m_nIndexSize = v36.m_nIndexSize;
      CVertexBuilder::AttachBegin(this: &v36.m_VertexBuilder, pMesh: v28, nMaxVertexCount: (int)pMeshb, desc: &v36);
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &v36.m_VertexBuilder);
      CStudioRender::R_StudioSoftwareProcessMesh_Normals(
        this: v40,
        a2: (Vector4D *)&savedregs,
        (mstudiomesh_t *)pmesh,
        meshBuilder: &v36,
        numVertices: pGroup->m_NumVertices,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
        lighting,
        doFlex: bDoFlex,
        r_blend,
        bShowNormals: false,
        bShowTangentS: true,
        bShowTangentT: false);
      if ( v36.m_bGenerateIndices )
      {
        switch ( v36.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v30 = 2 * v36.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v30 = 2 * v36.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v30 = 3 * v36.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v30 = 6 * v36.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v30 = 0;
            break;
          default:
            v30 = v36.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(this: &v36.m_IndexBuilder, primitiveType: v36.m_Type, nIndexCount: v30);
      }
      v36.m_pMesh->UnlockMesh(
        this: v36.m_pMesh,
        a2: v36.m_VertexBuilder.m_nVertexCount,
        a3: v36.m_IndexBuilder.m_nIndexCount,
        a4: &v36);
      v36.m_IndexBuilder.m_pIndexBuffer = nullptr;
      v36.m_IndexBuilder.m_nMaxIndexCount = 0;
      v36.m_VertexBuilder.m_nMaxVertexCount = 0;
      v36.m_VertexBuilder.m_pVertexBuffer = nullptr;
      v36.m_pMesh = nullptr;
      v36.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v28->Draw_2(this: v28, a2: -1, a3: 0);
      v31 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
      v32 = 2 * pGroup->m_NumVertices;
      v36.m_pMesh = v31;
      v36.m_bGenerateIndices = true;
      v36.m_Type = MATERIAL_LINES;
      pMeshc = (IMesh *)v32;
      v31->SetPrimitiveType(this: v31, a2: MATERIAL_LINES);
      v36.m_pMesh->LockMesh(this: v36.m_pMesh, a2: (int)pMeshc, a3: (int)pMeshc, a4: &v36, a5: nullptr);
      v36.m_IndexBuilder.m_nIndexCount = 0;
      v36.m_IndexBuilder.m_bModify = false;
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      v36.m_IndexBuilder.m_nIndexOffset = v36.m_nFirstVertex;
      v36.m_IndexBuilder.m_pIndexBuffer = &v31->IIndexBuffer;
      v36.m_IndexBuilder.m_pIndices = v36.m_pIndices;
      v36.m_IndexBuilder.m_nMaxIndexCount = (int)pMeshc;
      v36.m_IndexBuilder.m_nIndexSize = v36.m_nIndexSize;
      CVertexBuilder::AttachBegin(this: &v36.m_VertexBuilder, pMesh: v31, nMaxVertexCount: (int)pMeshc, desc: &v36);
      v36.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &v36.m_VertexBuilder);
      CStudioRender::R_StudioSoftwareProcessMesh_Normals(
        this: v40,
        a2: (Vector4D *)&savedregs,
        (mstudiomesh_t *)pmesh,
        meshBuilder: &v36,
        numVertices: pGroup->m_NumVertices,
        pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
        lighting,
        doFlex: bDoFlex,
        r_blend,
        bShowNormals: false,
        bShowTangentS: false,
        bShowTangentT: true);
      if ( v36.m_bGenerateIndices )
      {
        switch ( v36.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v33 = 2 * v36.m_VertexBuilder.m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v33 = 2 * v36.m_VertexBuilder.m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v33 = 3 * v36.m_VertexBuilder.m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v33 = 6 * v36.m_VertexBuilder.m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v33 = 0;
            break;
          default:
            v33 = v36.m_VertexBuilder.m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(this: &v36.m_IndexBuilder, primitiveType: v36.m_Type, nIndexCount: v33);
      }
      v36.m_pMesh->UnlockMesh(
        this: v36.m_pMesh,
        a2: v36.m_VertexBuilder.m_nVertexCount,
        a3: v36.m_IndexBuilder.m_nIndexCount,
        a4: &v36);
      v36.m_IndexBuilder.m_pIndexBuffer = nullptr;
      v36.m_IndexBuilder.m_nMaxIndexCount = 0;
      v36.m_VertexBuilder.m_nMaxVertexCount = 0;
      v36.m_VertexBuilder.m_pVertexBuffer = nullptr;
      v36.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v36.m_pMesh = nullptr;
      v31->Draw_2(this: v31, a2: -1, a3: 0);
      pRenderContext->Bind(this: pRenderContext, a2: pMaterial, a3: nullptr);
      CMeshBuilder::~CMeshBuilder(this: &v36);
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
    return (const vertexFileHeader_t *)numFacesRendereda;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F5B0
// Name: private: int CStudioRender::R_StudioDrawEyeball(class IMatRenderContext __near *,struct mstudiomesh_t __near *,struct studiomeshdata_t __near *,enum StudioModelLighting_t,class IMaterial __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CStudioRender::R_StudioDrawEyeball@<eax>(
        CStudioRender *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int m_nIndexCount@<edi>,
        IMatRenderContext *pRenderContext,
        mstudiomesh_t *pmesh,
        studiomeshdata_t *pMeshData,
        StudioModelLighting_t lighting,
        IMaterial *pMaterial,
        int lod)
{
  unsigned __int8 v10; // al
  int m_NumGroup; // eax
  char v13; // dl
  OptimizedModel::StripHeader_t **p_m_pStripData; // ecx
  int m; // edi
  int v16; // eax
  mstudioeyeball_t *v18; // eax
  const matrix3x4_t *v19; // edx
  IMaterialVar *v20; // eax
  int v21; // eax
  const mstudio_modelvertexdata_t *v22; // eax
  unsigned int v23; // ecx
  IMatRenderContext_vtbl *v24; // edx
  float v25; // xmm0_4
  int v26; // eax
  StudioRenderContext_t *m_pRC; // esi
  bool v28; // zf
  studiomeshgroup_t *v29; // esi
  IMesh *(__thiscall *GetDynamicMeshEx)(IMatRenderContext *, unsigned __int64, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v31; // eax
  int m_NumStrips; // ecx
  int v33; // edx
  int v34; // edi
  int v35; // eax
  int *m_pUniqueFaces; // eax
  unsigned int v37; // ecx
  mstudiovertex_t *v38; // edi
  char *v39; // edi
  int m_nVertexCount; // eax
  int v41; // eax
  CStudioRender *v42; // esi
  CachedPosNorm_t *WorldVertex; // edi
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // eax
  matrix3x4_t *m_PoseToWorld; // edx
  const Vector *p_m_Normal; // esi
  float *m_pCurrPosition; // eax
  float *m_pCurrNormal; // eax
  mstudioeyeball_t *v49; // eax
  float v50; // xmm0_4
  float x; // xmm4_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float *v55; // ecx
  CStudioRender *v56; // eax
  float v57; // xmm0_4
  CStudioRender *v58; // edi
  int v59; // eax
  int v60; // eax
  unsigned __int8 v61; // cl
  int v62; // eax
  int v63; // ecx
  int v64; // edi
  int v65; // ecx
  int v66; // eax
  int *v67; // eax
  unsigned int v68; // ecx
  int v69; // edx
  int v70; // edi
  StudioRenderContext_t *v71; // edx
  IMatRenderContext_vtbl *v72; // edx
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v74; // esi
  int m_NumVertices; // eax
  int v76; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int v78; // eax
  IMesh *(__thiscall *v79)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v80; // esi
  int v81; // eax
  int v82; // edi
  void (__thiscall *v83)(IMesh *, MaterialPrimitiveType_t); // eax
  int v84; // eax
  IMesh *v85; // esi
  int v86; // eax
  int v87; // edi
  void (__thiscall *v88)(IMesh *, MaterialPrimitiveType_t); // eax
  int v89; // eax
  int v90; // [esp+ECh] [ebp-4ACh]
  int v91; // [esp+ECh] [ebp-4ACh]
  int v92; // [esp+ECh] [ebp-4ACh]
  unsigned __int16 *m_pGroupIndexToMeshIndex; // [esp+F0h] [ebp-4A8h]
  unsigned __int16 *v94; // [esp+F0h] [ebp-4A8h]
  unsigned __int16 *v95; // [esp+F0h] [ebp-4A8h]
  IMesh *m_pMesh; // [esp+FCh] [ebp-49Ch]
  CMeshBuilder meshBuilder; // [esp+110h] [ebp-488h] BYREF
  matrix3x4_t glintMat; // [esp+2F8h] [ebp-2A0h] BYREF
  float v101; // [esp+328h] [ebp-270h]
  mstudiovertex_t *pVertices; // [esp+32Ch] [ebp-26Ch]
  float v103; // [esp+330h] [ebp-268h]
  float v104; // [esp+334h] [ebp-264h]
  unsigned __int64 fmt; // [esp+338h] [ebp-260h]
  CMeshBuilder v106; // [esp+340h] [ebp-258h] BYREF
  Vector4D vecDiffuseModulation; // [esp+528h] [ebp-70h] BYREF
  mstudioeyeball_t *peyeball; // [esp+538h] [ebp-60h]
  BOOL bTangentSpace; // [esp+53Ch] [ebp-5Ch]
  int v110; // [esp+540h] [ebp-58h]
  int v111; // [esp+544h] [ebp-54h]
  int v112; // [esp+548h] [ebp-50h]
  Vector org; // [esp+54Ch] [ebp-4Ch] BYREF
  BOOL bQuadList; // [esp+558h] [ebp-40h]
  int v115; // [esp+55Ch] [ebp-3Ch]
  BOOL bFlexStatic; // [esp+560h] [ebp-38h]
  Vector color; // [esp+564h] [ebp-34h] BYREF
  int j; // [esp+570h] [ebp-28h]
  int i; // [esp+574h] [ebp-24h]
  int numFacesRendered; // [esp+578h] [ebp-20h]
  IMesh *pMesh; // [esp+57Ch] [ebp-1Ch]
  studiomeshgroup_t *pGroup; // [esp+580h] [ebp-18h]
  mstudiovertex_t *vert; // [esp+584h] [ebp-14h]
  int k; // [esp+588h] [ebp-10h]
  unsigned __int8 r; // [esp+58Fh] [ebp-9h]
  CStudioRender *v126; // [esp+590h] [ebp-8h]
  bool bIsHardwareSkinnedData; // [esp+597h] [ebp-1h]
  int savedregs; // [esp+598h] [ebp+0h] BYREF
  mstudiomesh_t *pmesha; // [esp+5A4h] [ebp+Ch]
  studiohdr_t *useHWLighting; // [esp+5B4h] [ebp+1Ch]
  mstudio_meshvertexdata_t *useHWLightinga; // [esp+5B4h] [ebp+1Ch]
  char useHWLighting_3; // [esp+5B7h] [ebp+1Fh]

  v10 = *((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36);
  v126 = this;
  r = v10;
  if ( (v10 & 0x20) == 0 )
    return 0;
  m_NumGroup = pMeshData->m_NumGroup;
  v13 = 0;
  numFacesRendered = 0;
  LOBYTE(bFlexStatic) = 0;
  bIsHardwareSkinnedData = false;
  LOBYTE(bQuadList) = 0;
  if ( m_NumGroup <= 0 )
    goto LABEL_16;
  p_m_pStripData = &pMeshData->m_pMeshGroup->m_pStripData;
  for ( m = m_NumGroup; m != 0; --m )
  {
    v16 = (int)*(p_m_pStripData - 1);
    if ( (v16 & 4) != 0 )
      v13 = 1;
    if ( (v16 & 2) != 0 )
      bIsHardwareSkinnedData = true;
    if ( ((*p_m_pStripData)->flags & 6) != 0 )
    {
      bIsHardwareSkinnedData = false;
      LOBYTE(bQuadList) = 1;
    }
    p_m_pStripData += 11;
  }
  LOBYTE(bFlexStatic) = v13;
  if ( !bIsHardwareSkinnedData
    || v13 == 0
    || lighting == LIGHTING_SOFTWARE
    || (bIsHardwareSkinnedData = true, (r & 2) != 0) )
  {
LABEL_16:
    bIsHardwareSkinnedData = false;
  }
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->LoadIdentity(this: pRenderContext);
  if ( bFlexStatic && !bIsHardwareSkinnedData )
    CStudioRender::R_StudioFlexVerts(this, pmesh, lod, bQuadList);
  v18 = (mstudioeyeball_t *)((char *)this->m_pSubModel + 172 * pmesh->materialparam + this->m_pSubModel->eyeballindex);
  v19 = &this->m_pBoneToWorld[v18->bone];
  peyeball = v18;
  VectorTransform(in1: &v18->org.x, in2: v19, out: &org.x);
  CStudioRender::ComputeGlintTextureProjection(
    this,
    pState: &this->m_pEyeballState[pmesh->materialparam],
    vright: &this->m_pRC->m_ViewRight,
    vup: &this->m_pRC->m_ViewUp,
    mat: &glintMat);
  if ( *((char *)&this->m_pRC->m_Config.StudioRenderConfig_t + 36) >= 0 )
  {
    v20 = pMaterial->FindVarFast(this: pMaterial, a2: "$glint", a3: &glintCache);
    if ( v20 != nullptr )
      CStudioRender::R_StudioEyeballGlint(
        this,
        pstate: &this->m_pEyeballState[pmesh->materialparam],
        pGlintVar: v20,
        vright: &this->m_pRC->m_ViewRight,
        vup: &this->m_pRC->m_ViewUp,
        r_origin: &this->m_pRC->m_ViewOrigin);
    CStudioRender::SetEyeMaterialVars(
      this,
      a2: (int)pmesh,
      pMaterial,
      peyeball,
      eyeOrigin: &org,
      irisTransform: &this->m_pEyeballState[pmesh->materialparam].mat,
      glintTransform: &glintMat);
  }
  if ( !bIsHardwareSkinnedData )
  {
    useHWLighting = this->m_pStudioHdr;
    if ( mstudiomodel_t::CacheVertexData(
           this: (mstudiomodel_t *)((char *)pmesh + pmesh->modelindex),
           pModelData: useHWLighting) == nullptr )
      return 0;
    mstudiomodel_t::GetVertexData(
      this: (mstudiomodel_t *)((char *)pmesh + pmesh->modelindex),
      pModelData: useHWLighting);
    v22 = (const mstudio_modelvertexdata_t *)((char *)&pmesh->unused[6] + pmesh->modelindex);
    pmesh->vertexdata.modelvertexdata = v22;
    if ( v22->pVertexData != nullptr )
    {
      useHWLightinga = &pmesh->vertexdata;
      if ( pmesh != (mstudiomesh_t *)-48 )
      {
LABEL_37:
        v24 = pRenderContext->__vftable;
        pVertices = (mstudiovertex_t *)((char *)useHWLightinga->modelvertexdata->pVertexData
                                      + 48
                                      * ((int)useHWLightinga[-1].modelvertexdata
                                       + (unsigned int)useHWLightinga->modelvertexdata[-3].pVertexData / 0x30));
        v24->SetNumBoneWeights(this: pRenderContext, a2: 0);
        CCachedRenderData::SetupComputation(this: &this->m_VertexCache, pMesh: pmesh, flexComputation: false);
        v25 = this->m_pRC->m_AlphaMod * 255.0;
        v115 = LODWORD(v25);
        v26 = (int)v25;
        if ( v26 >= 0 )
        {
          v112 = 255;
          if ( v26 <= 255 )
            v112 = (int)v25;
        }
        else
        {
          v112 = 0;
        }
        CStudioRender::R_InitLightEffectsWorld3(this);
        CStudioRender::ComputeDiffuseModulation(this, pDiffuseModulation: &vecDiffuseModulation);
        CMeshBuilder::CMeshBuilder(this: &meshBuilder);
        LOBYTE(bTangentSpace) = pMaterial != nullptr && pMaterial->NeedsTangentSpace(this: pMaterial);
        m_pRC = this->m_pRC;
        v28 = (*((_BYTE *)&m_pRC->m_Config + 56) & 1) == 0;
        fmt = bQuadList ? 133635 : 655619;
        if ( v28 || (useHWLighting_3 = 1, (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 37) & 8) != 0) )
          useHWLighting_3 = 0;
        j = 0;
        if ( pMeshData->m_NumGroup <= 0 )
        {
LABEL_141:
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
          return numFacesRendered;
        }
        while ( 1 )
        {
          v29 = &pMeshData->m_pMeshGroup[j];
          GetDynamicMeshEx = pRenderContext->GetDynamicMeshEx;
          m_pMesh = v29->m_pMesh;
          pGroup = v29;
          v31 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, IMesh *, _DWORD, int, CMeshBuilder *))GetDynamicMeshEx)(
                           a1: pRenderContext,
                           a2: fmt,
                           a3: HIDWORD(fmt),
                           a4: 0,
                           a5: 0,
                           a6: m_pMesh,
                           a7: 0,
                           a8: m_nIndexCount,
                           a9: p_meshBuilder);
          pMesh = v31;
          if ( bQuadList )
          {
            m_NumStrips = v29->m_NumStrips;
            v33 = 0;
            v34 = 0;
            v35 = 0;
            vert = nullptr;
            if ( m_NumStrips >= 2 )
            {
              m_pUniqueFaces = v29->m_pUniqueFaces;
              v37 = ((unsigned int)(m_NumStrips - 2) >> 1) + 1;
              i = 2 * v37;
              v38 = nullptr;
              do
              {
                v33 += *m_pUniqueFaces;
                v38 = (mstudiovertex_t *)((char *)v38 + m_pUniqueFaces[1]);
                m_pUniqueFaces += 2;
                --v37;
              }
              while ( v37 != 0 );
              v35 = i;
              vert = v38;
              v34 = 0;
            }
            if ( v35 < v29->m_NumStrips )
              v34 = v29->m_pUniqueFaces[v35];
            v39 = (char *)vert + v33 + v34;
            CStudioRender::GenerateBicubicPatches(this: v126, pmesh, pGroup: v29, bDoFlex: bFlexStatic);
            CMeshBuilder::Begin(
              this: &meshBuilder,
              pMesh,
              type: MATERIAL_SUBD_QUADS_EXTRA,
              nVertexCount: (int)v39,
              nIndexCount: 0,
              pMeshSettings: nullptr);
            CStudioRender::SoftwareProcessQuadMesh(
              this: v126,
              pmesh,
              &meshBuilder,
              numFaces: (int)v39,
              pGroupToMesh: v29->m_pGroupIndexToMeshIndex,
              pTopologyIndices: v29->m_pTopologyIndices,
              bTangentSpace,
              bDoFlex: bFlexStatic);
          }
          else
          {
            CMeshBuilder::Begin(
              this: &meshBuilder,
              pMesh: v31,
              type: MATERIAL_TRIANGLES,
              nVertexCount: pmesh->numvertices,
              nIndexCount: 0,
              pMeshSettings: nullptr);
            i = 0;
            if ( v29->m_NumVertices > 0 )
            {
              do
              {
                v41 = pGroup->m_pGroupIndexToMeshIndex[i];
                v42 = v126;
                vert = &pVertices[v41];
                k = v41;
                WorldVertex = CCachedRenderData::CreateWorldVertex(this: &v126->m_VertexCache, vertex: v41);
                m_pFirstFlexIndex = v42->m_VertexCache.m_pFirstFlexIndex;
                if ( m_pFirstFlexIndex != nullptr && m_pFirstFlexIndex[k].m_Tag == v42->m_VertexCache.m_CurrentTag )
                {
                  m_PoseToWorld = v126->m_PoseToWorld;
                  k = (int)&v42->m_VertexCache.m_pFlexVerts[v42->m_VertexCache.m_pFirstFlexIndex[k].m_VertexIndex];
                  CStudioRender::R_StudioTransform(
                    this: v126,
                    in1: (Vector *)k,
                    pboneweight: &vert->m_BoneWeights,
                    pPoseToWorld: m_PoseToWorld,
                    out1: (Vector *)WorldVertex);
                  p_m_Normal = (const Vector *)&WorldVertex->m_Normal;
                  CStudioRender::R_StudioRotate(
                    this: v126,
                    in1: (Vector *)(k + 16),
                    pboneweight: &vert->m_BoneWeights,
                    pPoseToWorld: v126->m_PoseToWorld,
                    out1: (Vector *)&WorldVertex->m_Normal);
                }
                else
                {
                  CStudioRender::R_StudioTransform(
                    this: v42,
                    in1: &vert->m_vecPosition,
                    pboneweight: &vert->m_BoneWeights,
                    pPoseToWorld: v42->m_PoseToWorld,
                    out1: (Vector *)WorldVertex);
                  p_m_Normal = (const Vector *)&WorldVertex->m_Normal;
                  CStudioRender::R_StudioRotate(
                    this: v126,
                    in1: &vert->m_vecNormal,
                    pboneweight: &vert->m_BoneWeights,
                    pPoseToWorld: v126->m_PoseToWorld,
                    out1: (Vector *)&WorldVertex->m_Normal);
                }
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = WorldVertex->m_Position.x;
                m_pCurrPosition[1] = WorldVertex->m_Position.y;
                m_pCurrPosition[2] = WorldVertex->m_Position.z;
                if ( useHWLighting_3 != 0 )
                {
                  m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_m_Normal->x;
                  m_pCurrNormal[1] = p_m_Normal->y;
                  m_pCurrNormal[2] = p_m_Normal->z;
                }
                else
                {
                  v49 = peyeball;
                  p_m_Normal->x = WorldVertex->m_Position.x - org.x;
                  v50 = WorldVertex->m_Position.y - org.y;
                  x = p_m_Normal->x;
                  p_m_Normal->y = v50;
                  v52 = WorldVertex->m_Position.z - org.z;
                  p_m_Normal->z = v52;
                  v53 = v50;
                  v54 = (float)((float)((float)(v49->up.y * v50) + (float)(x * v49->up.x)) + (float)(v49->up.z * v52))
                      * -0.5;
                  p_m_Normal->x = (float)(v54 * v49->up.x) + p_m_Normal->x;
                  p_m_Normal->y = (float)(v49->up.y * v54) + v53;
                  p_m_Normal->z = (float)(v49->up.z * v54) + p_m_Normal->z;
                  VectorNormalize(vec: p_m_Normal);
                  v55 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                  *meshBuilder.m_VertexBuilder.m_pCurrNormal = p_m_Normal->x;
                  v55[1] = p_m_Normal->y;
                  v56 = v126;
                  v55[2] = p_m_Normal->z;
                  if ( v56->m_pRC->m_Config.fullbright != 0 )
                  {
                    v57 = 1.0;
                    color.x = 1.0;
                    color.y = 1.0;
                    color.z = 1.0;
                  }
                  else
                  {
                    R_LightStrengthWorld(
                      vert: (const Vector *)WorldVertex,
                      lightcount: v56->m_pRC->m_NumLocalLights,
                      pDesc: v56->m_pRC->m_LocalLights,
                      light: lightpos);
                    v58 = v126;
                    R_LightAmbient_4D(normal: p_m_Normal, pLightBoxColor: v126->m_pRC->m_LightBoxColors, lv: &color);
                    v58->R_LightEffectsWorld3(a1: v58->m_pRC->m_LocalLights, a2: lightpos, a3: p_m_Normal, a4: &color);
                    v57 = color.x;
                  }
                  v103 = v57 * 1024.0;
                  v111 = (int)(float)(v57 * 1024.0);
                  v59 = v111;
                  if ( (unsigned int)v111 > 0xFFF )
                    v59 = v111 < 0 ? 0 : 0xFFF;
                  r = lineartolightmap[v59];
                  v101 = color.y * 1024.0;
                  v110 = (int)(float)(color.y * 1024.0);
                  v60 = v110;
                  if ( (unsigned int)v110 > 0xFFF )
                    v60 = v110 < 0 ? 0 : 0xFFF;
                  v61 = lineartolightmap[v60];
                  v104 = color.z * 1024.0;
                  v115 = (int)(float)(color.z * 1024.0);
                  v62 = v115;
                  if ( (unsigned int)v115 > 0xFFF )
                    v62 = v115 < 0 ? 0 : 0xFFF;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = lineartolightmap[v62]
                                                                      | ((v61 | ((r | ((unsigned __int8)v112 << 8)) << 8)) << 8);
                }
                *(Vector2D *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = vert->m_vecTexCoord;
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                v63 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                meshBuilder.m_VertexBuilder.m_nCurrentVertex = v63;
                if ( v63 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                {
                  m_nVertexCount = v63;
                  meshBuilder.m_VertexBuilder.m_nVertexCount = v63;
                }
                meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                    + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                         + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                ++i;
              }
              while ( i < pGroup->m_NumVertices );
              v29 = pGroup;
              goto LABEL_57;
            }
          }
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
LABEL_57:
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount *= 2;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: m_nVertexCount);
            m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          }
          p_meshBuilder = &meshBuilder;
          m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
          ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
            a1: meshBuilder.m_pMesh,
            a2: m_nVertexCount);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          v64 = 0;
          pMesh->DrawModulated(this: pMesh, a2: &vecDiffuseModulation, a3: -1, a4: 0);
          v65 = v29->m_NumStrips;
          v66 = 0;
          if ( v65 < 2 )
          {
            v69 = 0;
          }
          else
          {
            v67 = v29->m_pUniqueFaces;
            v68 = ((unsigned int)(v65 - 2) >> 1) + 1;
            k = 2 * v68;
            v69 = 0;
            do
            {
              v64 += *v67;
              v69 += v67[1];
              v67 += 2;
              --v68;
            }
            while ( v68 != 0 );
            v66 = k;
          }
          if ( v66 < v29->m_NumStrips )
            numFacesRendered += v29->m_pUniqueFaces[v66];
          v70 = v69 + v64;
          v71 = v126->m_pRC;
          numFacesRendered += v70;
          if ( (*((_BYTE *)&v71->m_Config.StudioRenderConfig_t + 37) & 1) != 0 )
          {
            ((void (__thiscall *)(IMatRenderContext *, _DWORD, int, CMeshBuilder *))pRenderContext->SetNumBoneWeights)(
              a1: pRenderContext,
              a2: 0,
              a3: m_nIndexCount,
              a4: &meshBuilder);
            pRenderContext->Bind(this: pRenderContext, a2: v126->m_pMaterialTangentFrame, a3: nullptr);
            v72 = pRenderContext->__vftable;
            v106.m_IndexBuilder.m_nBufferOffset = -1;
            v106.m_VertexBuilder.m_nBufferOffset = -1;
            v106.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            GetDynamicMesh = v72->GetDynamicMesh;
            v106.m_pMesh = nullptr;
            v106.m_bGenerateIndices = false;
            memset(&v106.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            v106.m_IndexBuilder.m_nCurrentIndex = 0;
            v106.m_IndexBuilder.m_nTotalIndexCount = 0;
            v106.m_IndexBuilder.m_nBufferFirstIndex = 0;
            v106.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v106.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&v106.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            v106.m_VertexBuilder.m_nTotalVertexCount = 0;
            v74 = GetDynamicMesh(this: pRenderContext, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
            m_NumVertices = pGroup->m_NumVertices;
            v106.m_pMesh = v74;
            v106.m_bGenerateIndices = true;
            v106.m_Type = MATERIAL_LINES;
            v76 = 2 * m_NumVertices;
            SetPrimitiveType = v74->SetPrimitiveType;
            pMesh = v74;
            k = v76;
            SetPrimitiveType(this: v74, a2: MATERIAL_LINES);
            v106.m_pMesh->LockMesh(this: v106.m_pMesh, a2: v76, a3: v76, a4: &v106, a5: nullptr);
            v106.m_IndexBuilder.m_pIndexBuffer = &v74->IIndexBuffer;
            v106.m_IndexBuilder.m_nIndexOffset = v106.m_nFirstVertex;
            v106.m_IndexBuilder.m_nMaxIndexCount = v76;
            v106.m_VertexBuilder.m_pVertexBuffer = v74;
            v106.m_IndexBuilder.m_nIndexCount = 0;
            v106.m_IndexBuilder.m_bModify = false;
            v106.m_IndexBuilder.m_pIndices = v106.m_pIndices;
            v106.m_IndexBuilder.m_nIndexSize = v106.m_nIndexSize;
            v106.m_VertexBuilder.VertexDesc_t = v106.VertexDesc_t;
            v106.m_VertexBuilder.m_nMaxVertexCount = k;
            v106.m_VertexBuilder.m_NumBoneWeights = v106.m_NumBoneWeights != 0 ? 2 : 0;
            v106.m_VertexBuilder.m_nVertexCount = 0;
            v106.m_VertexBuilder.m_bModify = false;
            if ( v106.m_VertexBuilder.m_nBufferOffset == -1 )
            {
              v106.m_VertexBuilder.m_nTotalVertexCount = 0;
              v106.m_VertexBuilder.m_nBufferOffset = v106.MeshDesc_t::VertexDesc_t::m_nOffset;
              v106.m_VertexBuilder.m_nBufferFirstVertex = v106.m_nFirstVertex;
            }
            v106.m_VertexBuilder.m_pCurrNormal = v106.m_VertexBuilder.m_pNormal;
            qmemcpy(
              v106.m_VertexBuilder.m_pCurrTexCoord,
              v106.m_VertexBuilder.m_pTexCoord,
              sizeof(v106.m_VertexBuilder.m_pCurrTexCoord));
            v106.m_VertexBuilder.m_pCurrPosition = v106.m_VertexBuilder.m_pPosition;
            v106.m_VertexBuilder.m_pCurrColor = v106.m_VertexBuilder.m_pColor;
            m_pGroupIndexToMeshIndex = pGroup->m_pGroupIndexToMeshIndex;
            v90 = pGroup->m_NumVertices;
            v106.m_IndexBuilder.m_nCurrentIndex = 0;
            v106.m_VertexBuilder.m_nCurrentVertex = 0;
            CStudioRender::R_StudioSoftwareProcessMesh_Normals(
              this: v126,
              a2: (Vector4D *)&savedregs,
              pmesh,
              meshBuilder: &v106,
              numVertices: v90,
              pGroupToMesh: m_pGroupIndexToMeshIndex,
              lighting,
              doFlex: true,
              r_blend: 0.0,
              bShowNormals: true,
              bShowTangentS: false,
              bShowTangentT: false);
            if ( v106.m_bGenerateIndices )
            {
              switch ( v106.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  v78 = 2 * v106.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  v78 = 2 * v106.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  v78 = 3 * v106.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  v78 = 6 * v106.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  v78 = 0;
                  break;
                default:
                  v78 = v106.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(this: &v106.m_IndexBuilder, primitiveType: v106.m_Type, nIndexCount: v78);
            }
            p_meshBuilder = &v106;
            m_nIndexCount = v106.m_IndexBuilder.m_nIndexCount;
            ((void (__thiscall *)(IMesh *, int))v106.m_pMesh->UnlockMesh)(
              a1: v106.m_pMesh,
              a2: v106.m_VertexBuilder.m_nVertexCount);
            v106.m_IndexBuilder.m_pIndexBuffer = nullptr;
            v106.m_IndexBuilder.m_nMaxIndexCount = 0;
            v106.m_VertexBuilder.m_nMaxVertexCount = 0;
            v106.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v106.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v106.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
            pRenderContext->Bind(this: pRenderContext, a2: pMaterial, a3: nullptr);
            if ( v106.m_VertexBuilder.m_pVertexBuffer != nullptr
              && v106.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v106.m_VertexBuilder.m_pVertexBuffer) )
            {
              v106.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v106.m_VertexBuilder.m_pVertexBuffer);
            }
            if ( v106.m_IndexBuilder.m_pIndexBuffer != nullptr
              && v106.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v106.m_IndexBuilder.m_pIndexBuffer) )
            {
              v106.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v106.m_IndexBuilder.m_pIndexBuffer);
            }
          }
          if ( (*((_BYTE *)&v126->m_pRC->m_Config.StudioRenderConfig_t + 37) & 2) != 0 )
          {
            ((void (__thiscall *)(IMatRenderContext *, _DWORD, int, CMeshBuilder *))pRenderContext->SetNumBoneWeights)(
              a1: pRenderContext,
              a2: 0,
              a3: m_nIndexCount,
              a4: p_meshBuilder);
            pRenderContext->Bind(this: pRenderContext, a2: v126->m_pMaterialTangentFrame, a3: nullptr);
            v106.m_IndexBuilder.m_nBufferOffset = -1;
            v106.m_VertexBuilder.m_nBufferOffset = -1;
            v106.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v79 = pRenderContext->GetDynamicMesh;
            v106.m_pMesh = nullptr;
            v106.m_bGenerateIndices = false;
            memset(&v106.m_IndexBuilder.m_pIndexBuffer, 0, 12);
            v106.m_IndexBuilder.m_nCurrentIndex = 0;
            v106.m_IndexBuilder.m_nTotalIndexCount = 0;
            v106.m_IndexBuilder.m_nBufferFirstIndex = 0;
            v106.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v106.m_VertexBuilder.m_nBufferFirstVertex = 0;
            memset(&v106.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
            v106.m_VertexBuilder.m_nTotalVertexCount = 0;
            v80 = v79(this: pRenderContext, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
            v81 = pGroup->m_NumVertices;
            v106.m_pMesh = v80;
            v106.m_bGenerateIndices = true;
            v106.m_Type = MATERIAL_LINES;
            v82 = 2 * v81;
            v83 = v80->SetPrimitiveType;
            pMesh = v80;
            k = v82;
            v83(this: v80, a2: MATERIAL_LINES);
            v106.m_pMesh->LockMesh(this: v106.m_pMesh, a2: v82, a3: v82, a4: &v106, a5: nullptr);
            v106.m_IndexBuilder.m_pIndexBuffer = &v80->IIndexBuffer;
            v106.m_IndexBuilder.m_nIndexOffset = v106.m_nFirstVertex;
            v106.m_IndexBuilder.m_nMaxIndexCount = v82;
            v106.m_VertexBuilder.m_pVertexBuffer = v80;
            v106.m_IndexBuilder.m_nIndexCount = 0;
            v106.m_IndexBuilder.m_bModify = false;
            v106.m_IndexBuilder.m_pIndices = v106.m_pIndices;
            v106.m_IndexBuilder.m_nIndexSize = v106.m_nIndexSize;
            v106.m_VertexBuilder.VertexDesc_t = v106.VertexDesc_t;
            v106.m_VertexBuilder.m_nMaxVertexCount = k;
            v106.m_VertexBuilder.m_NumBoneWeights = v106.m_NumBoneWeights != 0 ? 2 : 0;
            v106.m_VertexBuilder.m_nVertexCount = 0;
            v106.m_VertexBuilder.m_bModify = false;
            if ( v106.m_VertexBuilder.m_nBufferOffset == -1 )
            {
              v106.m_VertexBuilder.m_nTotalVertexCount = 0;
              v106.m_VertexBuilder.m_nBufferOffset = v106.MeshDesc_t::VertexDesc_t::m_nOffset;
              v106.m_VertexBuilder.m_nBufferFirstVertex = v106.m_nFirstVertex;
            }
            v106.m_VertexBuilder.m_pCurrNormal = v106.m_VertexBuilder.m_pNormal;
            qmemcpy(
              v106.m_VertexBuilder.m_pCurrTexCoord,
              v106.m_VertexBuilder.m_pTexCoord,
              sizeof(v106.m_VertexBuilder.m_pCurrTexCoord));
            v106.m_VertexBuilder.m_pCurrPosition = v106.m_VertexBuilder.m_pPosition;
            v106.m_VertexBuilder.m_pCurrColor = v106.m_VertexBuilder.m_pColor;
            v94 = pGroup->m_pGroupIndexToMeshIndex;
            v91 = pGroup->m_NumVertices;
            v106.m_IndexBuilder.m_nCurrentIndex = 0;
            v106.m_VertexBuilder.m_nCurrentVertex = 0;
            CStudioRender::R_StudioSoftwareProcessMesh_Normals(
              this: v126,
              a2: (Vector4D *)&savedregs,
              pmesh,
              meshBuilder: &v106,
              numVertices: v91,
              pGroupToMesh: v94,
              lighting,
              doFlex: true,
              r_blend: 0.0,
              bShowNormals: false,
              bShowTangentS: true,
              bShowTangentT: false);
            if ( v106.m_bGenerateIndices )
            {
              switch ( v106.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  v84 = 2 * v106.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  v84 = 2 * v106.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  v84 = 3 * v106.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  v84 = 6 * v106.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  v84 = 0;
                  break;
                default:
                  v84 = v106.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(this: &v106.m_IndexBuilder, primitiveType: v106.m_Type, nIndexCount: v84);
            }
            v106.m_pMesh->UnlockMesh(
              this: v106.m_pMesh,
              a2: v106.m_VertexBuilder.m_nVertexCount,
              a3: v106.m_IndexBuilder.m_nIndexCount,
              a4: &v106);
            v106.m_IndexBuilder.m_pIndexBuffer = nullptr;
            v106.m_IndexBuilder.m_nMaxIndexCount = 0;
            v106.m_VertexBuilder.m_nMaxVertexCount = 0;
            v106.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v106.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v106.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
            v85 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
            v86 = pGroup->m_NumVertices;
            v106.m_pMesh = v85;
            v106.m_bGenerateIndices = true;
            v106.m_Type = MATERIAL_LINES;
            v87 = 2 * v86;
            v88 = v85->SetPrimitiveType;
            pMesh = v85;
            k = v87;
            v88(this: v85, a2: MATERIAL_LINES);
            v106.m_pMesh->LockMesh(this: v106.m_pMesh, a2: v87, a3: v87, a4: &v106, a5: nullptr);
            v106.m_IndexBuilder.m_pIndexBuffer = &v85->IIndexBuffer;
            v106.m_IndexBuilder.m_nIndexOffset = v106.m_nFirstVertex;
            v106.m_IndexBuilder.m_pIndices = v106.m_pIndices;
            v106.m_IndexBuilder.m_nMaxIndexCount = v87;
            v106.m_VertexBuilder.m_pVertexBuffer = v85;
            v106.m_IndexBuilder.m_nIndexCount = 0;
            v106.m_IndexBuilder.m_bModify = false;
            v106.m_IndexBuilder.m_nIndexSize = v106.m_nIndexSize;
            v106.m_VertexBuilder.VertexDesc_t = v106.VertexDesc_t;
            v106.m_VertexBuilder.m_nMaxVertexCount = k;
            v106.m_VertexBuilder.m_NumBoneWeights = v106.m_NumBoneWeights != 0 ? 2 : 0;
            v106.m_VertexBuilder.m_nVertexCount = 0;
            v106.m_VertexBuilder.m_bModify = false;
            if ( v106.m_VertexBuilder.m_nBufferOffset == -1 )
            {
              v106.m_VertexBuilder.m_nTotalVertexCount = 0;
              v106.m_VertexBuilder.m_nBufferOffset = v106.MeshDesc_t::VertexDesc_t::m_nOffset;
              v106.m_VertexBuilder.m_nBufferFirstVertex = v106.m_nFirstVertex;
            }
            v106.m_VertexBuilder.m_pCurrNormal = v106.m_VertexBuilder.m_pNormal;
            qmemcpy(
              v106.m_VertexBuilder.m_pCurrTexCoord,
              v106.m_VertexBuilder.m_pTexCoord,
              sizeof(v106.m_VertexBuilder.m_pCurrTexCoord));
            v106.m_VertexBuilder.m_pCurrPosition = v106.m_VertexBuilder.m_pPosition;
            v106.m_VertexBuilder.m_pCurrColor = v106.m_VertexBuilder.m_pColor;
            v95 = pGroup->m_pGroupIndexToMeshIndex;
            v92 = pGroup->m_NumVertices;
            v106.m_IndexBuilder.m_nCurrentIndex = 0;
            v106.m_VertexBuilder.m_nCurrentVertex = 0;
            CStudioRender::R_StudioSoftwareProcessMesh_Normals(
              this: v126,
              a2: (Vector4D *)&savedregs,
              pmesh,
              meshBuilder: &v106,
              numVertices: v92,
              pGroupToMesh: v95,
              lighting,
              doFlex: true,
              r_blend: 0.0,
              bShowNormals: false,
              bShowTangentS: false,
              bShowTangentT: true);
            if ( v106.m_bGenerateIndices )
            {
              switch ( v106.m_Type )
              {
                case MATERIAL_LINE_STRIP:
                  v89 = 2 * v106.m_VertexBuilder.m_nVertexCount - 2;
                  break;
                case MATERIAL_LINE_LOOP:
                  v89 = 2 * v106.m_VertexBuilder.m_nVertexCount;
                  break;
                case MATERIAL_POLYGON:
                  v89 = 3 * v106.m_VertexBuilder.m_nVertexCount - 6;
                  break;
                case MATERIAL_QUADS:
                  v89 = 6 * v106.m_VertexBuilder.m_nVertexCount / 4;
                  break;
                case MATERIAL_INSTANCED_QUADS:
                  v89 = 0;
                  break;
                default:
                  v89 = v106.m_VertexBuilder.m_nVertexCount;
                  break;
              }
              CIndexBuilder::GenerateIndices(this: &v106.m_IndexBuilder, primitiveType: v106.m_Type, nIndexCount: v89);
            }
            p_meshBuilder = &v106;
            m_nIndexCount = v106.m_IndexBuilder.m_nIndexCount;
            ((void (__thiscall *)(IMesh *, int))v106.m_pMesh->UnlockMesh)(
              a1: v106.m_pMesh,
              a2: v106.m_VertexBuilder.m_nVertexCount);
            v106.m_IndexBuilder.m_pIndexBuffer = nullptr;
            v106.m_IndexBuilder.m_nMaxIndexCount = 0;
            v106.m_VertexBuilder.m_nMaxVertexCount = 0;
            v106.m_VertexBuilder.m_pVertexBuffer = nullptr;
            v106.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
            v106.m_pMesh = nullptr;
            pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
            pRenderContext->Bind(this: pRenderContext, a2: pMaterial, a3: nullptr);
            if ( v106.m_VertexBuilder.m_pVertexBuffer != nullptr
              && v106.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v106.m_VertexBuilder.m_pVertexBuffer) )
            {
              v106.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v106.m_VertexBuilder.m_pVertexBuffer);
            }
            if ( v106.m_IndexBuilder.m_pIndexBuffer != nullptr
              && v106.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v106.m_IndexBuilder.m_pIndexBuffer) )
            {
              v106.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v106.m_IndexBuilder.m_pIndexBuffer);
            }
          }
          if ( ++j >= pMeshData->m_NumGroup )
            goto LABEL_141;
        }
      }
    }
    else
    {
      useHWLightinga = nullptr;
    }
    v23 = `GetFatVertexData'::`8'::warnCount++;
    if ( v23 < 0x14 )
      _Warning(
        a1: "ERROR: model verts have been compressed or you don't have them in memory on a console, cannot render! (use \"-no"
        "_compressed_vvds\")");
    if ( useHWLightinga == nullptr )
      return 0;
    goto LABEL_37;
  }
  j = 0;
  if ( pMeshData->m_NumGroup <= 0 )
    return numFacesRendered;
  pmesha = nullptr;
  do
  {
    v21 = CStudioRender::R_StudioDrawStaticMesh(
            this,
            pRenderContext,
            (Vector4D *)pmesh,
            pGroup: (studiomeshgroup_t *)((char *)pmesha + (unsigned int)pMeshData->m_pMeshGroup),
            lighting,
            r_blend: this->m_pRC->m_AlphaMod,
            pMaterial,
            lod,
            pColorMeshes: nullptr);
    numFacesRendered += v21;
    pmesha = (mstudiomesh_t *)((char *)pmesha + 44);
    ++j;
  }
  while ( j < pMeshData->m_NumGroup );
  return numFacesRendered;
}

//------------------------------------------------------------------------------
// Address: 0x10010880
// Name: private: int CStudioRender::R_StudioDrawMesh(class IMatRenderContext __near *,struct mstudiomesh_t __near *,struct studiomeshdata_t __near *,enum StudioModelLighting_t,class IMaterial __near *,struct ColorMeshInfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioDrawMesh(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        Vector4D *pmesh,
        studiomeshdata_t *pMeshData,
        StudioModelLighting_t lighting,
        IMaterial *pMaterial,
        ColorMeshInfo_t *pColorMeshes,
        int lod)
{
  int result; // eax
  studiomeshgroup_t *m_pMeshGroup; // eax
  studiomeshgroup_t *v11; // ecx
  bool v12; // dl
  bool v13; // al
  StudioRenderContext_t *v14; // eax
  char v15; // dl
  const vertexFileHeader_t *v16; // eax
  StudioRenderContext_t *m_pRC; // eax
  int j; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int numFacesRendered; // [esp+24h] [ebp-4h]

  result = 0;
  numFacesRendered = 0;
  j = 0;
  if ( pMeshData->m_NumGroup > 0 )
  {
    for ( i = 0; ; ++i )
    {
      m_pMeshGroup = pMeshData->m_pMeshGroup;
      v11 = &m_pMeshGroup[i];
      v12 = (m_pMeshGroup[i].m_Flags & 2) != 0;
      v13 = (m_pMeshGroup->m_pStripData->flags & 6) != 0;
      if ( !v12
        || v13
        || lighting == LIGHTING_SOFTWARE
        || (*((_BYTE *)&(v14 = this->m_pRC)->m_Config.StudioRenderConfig_t + 37) & 3) != 0
        || (v15 = *((_BYTE *)&v14->m_Config.StudioRenderConfig_t + 36)) < 0 )
      {
        m_pRC = this->m_pRC;
        if ( (*((_BYTE *)&m_pRC->m_Config.StudioRenderConfig_t + 36) & 8) == 0 )
        {
          v16 = CStudioRender::R_StudioDrawDynamicMesh(
                  this,
                  pRenderContext,
                  pmesh,
                  pGroup: v11,
                  lighting,
                  r_blend: m_pRC->m_AlphaMod,
                  pMaterial,
                  lod);
          goto LABEL_12;
        }
      }
      else if ( (v15 & 4) == 0 )
      {
        v16 = (const vertexFileHeader_t *)CStudioRender::R_StudioDrawStaticMesh(
                                            this,
                                            pRenderContext,
                                            pmesh,
                                            pGroup: v11,
                                            lighting,
                                            r_blend: v14->m_AlphaMod,
                                            pMaterial,
                                            lod,
                                            pColorMeshes);
LABEL_12:
        numFacesRendered += (int)v16;
      }
      if ( ++j >= pMeshData->m_NumGroup )
        return numFacesRendered;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010970
// Name: private: int CStudioRender::R_StudioDrawPoints(class IMatRenderContext __near *,int,void __near *,class IMaterial __near * __near *,int __near *,int,int,struct ColorMeshInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioDrawPoints(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        int skin,
        void *pClientEntity,
        IMaterial **ppMaterials,
        int *pMaterialFlags,
        int boneMask,
        int lod,
        ColorMeshInfo_t *pColorMeshes)
{
  bool v10; // zf
  StudioRenderContext_t *m_pRC; // edx
  int v13; // ecx
  studiohdr_t *m_pStudioHdr; // eax
  mstudiomodel_t *m_pSubModel; // eax
  int v16; // esi
  int v17; // edx
  mstudiomesh_t *v18; // esi
  CMeshBuilder *v19; // ebx
  int materialtype; // eax
  int v21; // eax
  studiomeshdata_t *pMeshData; // [esp+4h] [ebp-18h]
  __int16 *pskinref; // [esp+8h] [ebp-14h]
  int v24; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  StudioModelLighting_t lighting; // [esp+14h] [ebp-8h] BYREF
  int numFacesRendered; // [esp+18h] [ebp-4h]
  char bHasMaterialOverride_3; // [esp+2Bh] [ebp+Fh]

  v10 = this->m_pStudioMeshes == nullptr;
  numFacesRendered = 0;
  if ( v10 )
    return 0;
  m_pRC = this->m_pRC;
  if ( *((char *)&m_pRC->m_Config.StudioRenderConfig_t + 36) < 0 && (*((_BYTE *)this + 3685872) & 2) != 0 )
    return 0;
  v13 = m_pRC->m_Config.skin;
  if ( v13 != 0 )
  {
    if ( v13 >= this->m_pStudioHdr->numskinfamilies )
      v13 = 0;
  }
  else
  {
    v13 = skin;
  }
  m_pStudioHdr = this->m_pStudioHdr;
  pskinref = (__int16 *)((char *)m_pStudioHdr + m_pStudioHdr->skinindex);
  if ( v13 > 0 && v13 < m_pStudioHdr->numskinfamilies )
    pskinref = (__int16 *)((char *)m_pStudioHdr + 2 * v13 * m_pStudioHdr->numskinref + m_pStudioHdr->skinindex);
  if ( m_pRC->m_pForcedMaterial != nullptr
    || (bHasMaterialOverride_3 = 0, m_pRC->m_nForcedMaterialType == OVERRIDE_DEPTH_WRITE) )
  {
    bHasMaterialOverride_3 = 1;
  }
  m_pSubModel = this->m_pSubModel;
  i = 0;
  if ( m_pSubModel->nummeshes > 0 )
  {
    v24 = 0;
    do
    {
      v16 = v24 + m_pSubModel->meshindex;
      v17 = *(_DWORD *)&m_pSubModel->name[v16 + 32];
      v18 = (mstudiomesh_t *)&m_pSubModel->name[v16];
      pMeshData = &this->m_pStudioMeshes[v17];
      if ( pMeshData->m_NumGroup != 0 && pMaterialFlags != nullptr )
      {
        lighting = LIGHTING_HARDWARE;
        v19 = (CMeshBuilder *)CStudioRender::R_StudioSetupSkinAndLighting(
                                this,
                                pRenderContext,
                                index: pskinref[v18->material],
                                ppMaterials,
                                materialFlags: pMaterialFlags[pskinref[v18->material]],
                                pClientRenderable: pClientEntity,
                                pColorMeshes,
                                &lighting);
        if ( v19 != nullptr )
        {
          CCachedRenderData::SetMesh(this: &this->m_VertexCache, mesh: i);
          if ( bHasMaterialOverride_3 != 0 )
            materialtype = 0;
          else
            materialtype = v18->materialtype;
          if ( materialtype == 1 )
            v21 = CStudioRender::R_StudioDrawEyeball(
                    this,
                    p_meshBuilder: v19,
                    m_nIndexCount: (int)this,
                    pRenderContext,
                    pmesh: v18,
                    pMeshData,
                    lighting,
                    pMaterial: (IMaterial *)v19,
                    lod);
          else
            v21 = CStudioRender::R_StudioDrawMesh(
                    this,
                    pRenderContext,
                    pmesh: (Vector4D *)v18,
                    pMeshData,
                    lighting,
                    pMaterial: (IMaterial *)v19,
                    pColorMeshes,
                    lod);
          numFacesRendered += v21;
        }
      }
      m_pSubModel = this->m_pSubModel;
      v24 += 116;
      ++i;
    }
    while ( i < m_pSubModel->nummeshes );
  }
  pRenderContext->SetNumBoneWeights(this: pRenderContext, a2: 0);
  return numFacesRendered;
}

//------------------------------------------------------------------------------
// Address: 0x10010B30
// Name: private: int CStudioRender::R_StudioRenderFinal(class IMatRenderContext __near *,int,int,struct CStudioRender::BodyPartInfo_t __near *,void __near *,class IMaterial __near * __near *,int __near *,int,int,struct ColorMeshInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::R_StudioRenderFinal(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        int skin,
        int nBodyPartCount,
        CStudioRender::BodyPartInfo_t *pBodyPartInfo,
        void *pClientEntity,
        IMaterial **ppMaterials,
        int *pMaterialFlags,
        int boneMask,
        int lod,
        ColorMeshInfo_t *pColorMeshes)
{
  int result; // eax
  int v12; // edi
  mstudiomodel_t *m_pSubModel; // [esp-8h] [ebp-14h]
  int numFacesRendered; // [esp+8h] [ebp-4h]

  result = 0;
  v12 = 0;
  numFacesRendered = 0;
  if ( nBodyPartCount > 0 )
  {
    do
    {
      m_pSubModel = pBodyPartInfo[v12].m_pSubModel;
      this->m_pSubModel = m_pSubModel;
      CStudioRender::ComputeEyelidStateFACS(this, pSubModel: m_pSubModel);
      CStudioRender::GenerateMorphAccumulator(this, pSubModel: this->m_pSubModel);
      CCachedRenderData::SetBodyPart(this: &this->m_VertexCache, bodypart: v12);
      CCachedRenderData::SetModel(this: &this->m_VertexCache, model: pBodyPartInfo[v12].m_nSubModelIndex);
      numFacesRendered += CStudioRender::R_StudioDrawPoints(
                            this,
                            pRenderContext,
                            skin,
                            pClientEntity,
                            ppMaterials,
                            pMaterialFlags,
                            boneMask,
                            lod,
                            pColorMeshes);
      ++v12;
    }
    while ( v12 < nBodyPartCount );
    return numFacesRendered;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010BC0
// Name: public: void studiohwdata_t::UpdateFacesRenderedCount(struct studiohdr_t __near *,class CUtlHash<struct studiohwdata_t __near *,bool (*)(struct studiohwdata_t __near * const __near &,struct studiohwdata_t __near * const __near &),unsigned int (*)(struct studiohwdata_t __near * const __near &)> __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall studiohwdata_t::UpdateFacesRenderedCount(
        studiohwdata_t *this,
        studiohdr_t *pStudioHdr,
        CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *hwDataHash,
        int nLOD,
        int nInstances,
        int nFacesOverride)
{
  CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *v6; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v10; // esi
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ecx
  int v12; // eax
  void (__cdecl **v13)(IConVar *, const char *, float); // edi
  int m_NumFaces; // eax
  studiohwdata_t *src; // [esp+Ch] [ebp-8h] BYREF
  int pIndex; // [esp+10h] [ebp-4h] BYREF

  v6 = hwDataHash;
  src = this;
  pIndex = 0;
  if ( CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::DoFind(
         this: hwDataHash,
         &src,
         pBucket: (unsigned int *)&hwDataHash,
         &pIndex) == 0
    || (pIndex | ((_DWORD)hwDataHash << 16)) == 0xFFFFFFFF )
  {
    this->m_pStudioHdr = pStudioHdr;
    this->m_NumFacesRenderedThisFrame = 0;
    this->m_NumTimesRenderedThisFrame = 0;
    hwDataHash = (CUtlHash<studiohwdata_t *,bool (__cdecl*)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl*)(studiohwdata_t * const &)> *)this;
    if ( CUtlHash<studiohwdata_t *,bool (__cdecl *)(studiohwdata_t * const &,studiohwdata_t * const &),unsigned int (__cdecl *)(studiohwdata_t * const &)>::DoFind(
           this: v6,
           src: (studiohwdata_t *const *)&hwDataHash,
           pBucket: (unsigned int *)&pStudioHdr,
           pIndex: (int *)&src) == 0 )
    {
      m_Size = v6->m_Buckets.m_Memory.m_pMemory[(_DWORD)pStudioHdr].m_Size;
      m_nAllocationCount = v6->m_Buckets.m_Memory.m_pMemory[(_DWORD)pStudioHdr].m_Memory.m_nAllocationCount;
      v10 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&v6->m_Buckets.m_Memory.m_pMemory[(_DWORD)pStudioHdr];
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<int,int>::Grow(this: v10, num: m_Size - m_nAllocationCount + 1);
      ++v10[1].m_pMemory;
      m_pMemory = v10->m_pMemory;
      v12 = (int)v10[1].m_pMemory - m_Size - 1;
      v10[1].m_nAllocationCount = (int)v10->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &v10->m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = (void (__cdecl *)(IConVar *, const char *, float))hwDataHash;
    }
  }
  m_NumFaces = nFacesOverride;
  if ( nFacesOverride == -1 )
  {
    if ( nLOD >= this->m_NumLODs )
      m_NumFaces = 0;
    else
      m_NumFaces = this->m_pLODs[nLOD].m_NumFaces;
  }
  this->m_NumFacesRenderedThisFrame += m_NumFaces * nInstances;
  ++this->m_NumTimesRenderedThisFrame;
}

//------------------------------------------------------------------------------
// Address: 0x10010CC0
// Name: private: int CStudioRender::R_StudioRenderModel(class IMatRenderContext __near *,int,int,int,void __near *,class IMaterial __near * __near *,int __near *,int,int,int,struct ColorMeshInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CStudioRender::R_StudioRenderModel@<eax>(
        CStudioRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IMatRenderContext *pRenderContext,
        int skin,
        int body,
        mstudiobbox_t *hitboxset,
        void *pEntity,
        IMaterial **ppMaterials,
        int *pMaterialFlags,
        char flags,
        int boneMask,
        int lod,
        ColorMeshInfo_t *pColorMeshes)
{
  int drawEntities; // ecx
  int v16; // eax
  int v18; // edi
  void *v19; // esp
  int v20; // edi
  char v21; // al
  CStudioRender::BodyPartInfo_t v22; // [esp+0h] [ebp-14h] BYREF
  int numFacesRendered; // [esp+Ch] [ebp-8h]
  int nDrawGroup; // [esp+10h] [ebp-4h]
  int hitboxseta; // [esp+28h] [ebp+14h]
  int numPasses; // [esp+38h] [ebp+24h]

  drawEntities = this->m_pRC->m_Config.drawEntities;
  v16 = flags & 3;
  nDrawGroup = v16;
  if ( drawEntities == 2 )
  {
    if ( v16 != 2 )
      CStudioRender::R_StudioDrawBones(this);
    return 0;
  }
  else if ( drawEntities == 3 )
  {
    if ( v16 != 2 )
      CStudioRender::R_StudioDrawHulls(this, a2, a3, hitboxset, translucent: false);
    return 0;
  }
  else
  {
    hitboxseta = this->m_pStudioHdr->numbodyparts;
    v18 = 0;
    numFacesRendered = 0;
    numPasses = 0;
    v19 = alloca(8 * hitboxseta);
    if ( hitboxseta > 0 )
    {
      do
      {
        *(&v22.m_nSubModelIndex + 2 * v18) = R_StudioSetupModel(
                                               bodypart: v18,
                                               entity_body: body,
                                               ppSubModel: &v22.m_pSubModel + 2 * v18,
                                               pStudioHdr: this->m_pStudioHdr);
        ++v18;
      }
      while ( v18 < this->m_pStudioHdr->numbodyparts );
    }
    if ( nDrawGroup == 2 )
    {
      *((_BYTE *)this + 3685872) |= 1u;
      v20 = numFacesRendered;
    }
    else
    {
      *((_BYTE *)this + 3685872) &= 0xFCu;
      v20 = CStudioRender::R_StudioRenderFinal(
              this,
              pRenderContext,
              skin,
              nBodyPartCount: this->m_pStudioHdr->numbodyparts,
              pBodyPartInfo: &v22,
              pClientEntity: pEntity,
              ppMaterials,
              pMaterialFlags,
              boneMask,
              lod,
              pColorMeshes);
      numPasses = 1;
    }
    v21 = *((_BYTE *)this + 3685872);
    if ( (v21 & 1) != 0 && nDrawGroup != 1 )
    {
      *((_BYTE *)this + 3685872) = v21 | 2;
      v20 += CStudioRender::R_StudioRenderFinal(
               this,
               pRenderContext,
               skin,
               nBodyPartCount: this->m_pStudioHdr->numbodyparts,
               pBodyPartInfo: &v22,
               pClientEntity: pEntity,
               ppMaterials,
               pMaterialFlags,
               boneMask,
               lod,
               pColorMeshes);
      ++numPasses;
    }
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      ConVarRef::ConVarRef(this: &mat_rendered_faces_count, pName: "mat_rendered_faces_count");
    }
    if ( (_S1 & 2) == 0 )
    {
      _S1 |= 2u;
      ConVarRef::ConVarRef(this: &mat_print_top_model_vert_counts, pName: "mat_print_top_model_vert_counts");
    }
    if ( numPasses != 0
      && (mat_rendered_faces_count.m_pConVarState->m_Value.m_nValue != 0
       || mat_print_top_model_vert_counts.m_pConVarState->m_Value.m_nValue != 0) )
    {
      studiohwdata_t::UpdateFacesRenderedCount(
        this: this->m_pStudioHWData,
        pStudioHdr: this->m_pStudioHdr,
        hwDataHash: &this->m_ModelFaceCountHash,
        nLOD: lod,
        nInstances: 1,
        nFacesOverride: v20);
    }
    return v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010EB0
// Name: private: void CStudioRender::DrawShadows(struct DrawModelInfo_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawShadows(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        const DrawModelInfo_t *info,
        char flags,
        int boneMask)
{
  StudioRenderContext_t *m_pRC; // eax
  IMatRenderContext *v7; // ebx
  bool v8; // zf
  IMatRenderContext_vtbl *v9; // eax
  CStudioRender::ShadowState_t *v11; // eax
  VMatrix *m_pWorldToTexture; // ecx
  CStudioRender::ShadowState_t *m_pMemory; // eax
  studioloddata_t *v14; // ecx
  int v15; // ecx
  IMaterial *v16; // eax
  OverrideType_t nForcedType; // [esp+4h] [ebp-10h]
  IMaterial *pForcedMat; // [esp+8h] [ebp-Ch]
  FlashlightState_t *m_pFlashlightState; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  const DrawModelInfo_t *infoa; // [esp+1Ch] [ebp+8h]
  const DrawModelInfo_t *infob; // [esp+1Ch] [ebp+8h]

  if ( this->m_ShadowState.m_Size != 0 )
  {
    m_pRC = this->m_pRC;
    pForcedMat = m_pRC->m_pForcedMaterial;
    nForcedType = m_pRC->m_nForcedMaterialType;
    v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    v8 = !v7->SinglePassFlashlightModeEnabled(this: v7);
    v9 = v7->__vftable;
    if ( v8 )
    {
      ((void (__thiscall *)(IMatRenderContext *, int, int))v9->SetFlashlightMode)(a1: v7, a2: 1, a3: a2);
      i = 0;
      if ( this->m_ShadowState.m_Size > 0 )
      {
        infoa = nullptr;
        do
        {
          v11 = (CStudioRender::ShadowState_t *)((char *)infoa + (unsigned int)this->m_ShadowState.m_Memory.m_pMemory);
          if ( v11->m_pMaterial == nullptr )
          {
            m_pFlashlightState = v11->m_pFlashlightState;
            if ( m_pFlashlightState != nullptr )
            {
              m_pWorldToTexture = v11->m_pWorldToTexture;
              if ( m_pWorldToTexture != nullptr )
              {
                v7->SetFlashlightStateEx(
                  this: v7,
                  a2: m_pFlashlightState,
                  a3: m_pWorldToTexture,
                  a4: v11->m_pFlashlightDepthTexture);
                m_pMemory = this->m_ShadowState.m_Memory.m_pMemory;
                this->m_pCurrentFlashlight = *(FlashlightState_t **)((char *)&infoa->m_Decals + (_DWORD)m_pMemory);
                CStudioRender::PushScissor(
                  this,
                  state: *(FlashlightState_t **)((char *)&infoa->m_Decals + (_DWORD)m_pMemory));
                v14 = &info->m_pHardwareData->m_pLODs[info->m_Lod];
                CStudioRender::R_StudioRenderModel(
                  this,
                  a2: (int)v7,
                  a3: (int)info,
                  pRenderContext: v7,
                  skin: info->m_Skin,
                  body: info->m_Body,
                  hitboxset: (mstudiobbox_t *)info->m_HitboxSet,
                  pEntity: info->m_pClientEntity,
                  ppMaterials: v14->ppMaterials,
                  pMaterialFlags: v14->pMaterialFlags,
                  flags,
                  boneMask,
                  lod: info->m_Lod,
                  pColorMeshes: info->m_pColorMeshes);
                CStudioRender::PopScissor(
                  this,
                  state: *(FlashlightState_t **)((char *)&this->m_ShadowState.m_Memory.m_pMemory->m_pFlashlightState
                                        + (unsigned int)infoa));
                this->m_pCurrentFlashlight = nullptr;
              }
            }
          }
          infoa = (const DrawModelInfo_t *)((char *)infoa + 20);
          ++i;
        }
        while ( i < this->m_ShadowState.m_Size );
      }
      v7->SetFlashlightMode(this: v7, a2: false);
      v15 = 0;
      infob = nullptr;
      if ( this->m_ShadowState.m_Size > 0 )
      {
        ia = 0;
        do
        {
          v16 = *(IMaterial **)((char *)&this->m_ShadowState.m_Memory.m_pMemory->m_pMaterial + v15);
          if ( v16 != nullptr )
          {
            this->m_pRC->m_pForcedMaterial = v16;
            this->m_pRC->m_nForcedMaterialType = OVERRIDE_NORMAL;
            CStudioRender::R_StudioRenderModel(
              this,
              a2: (int)v7,
              a3: (int)info,
              pRenderContext: v7,
              skin: 0,
              body: info->m_Body,
              hitboxset: nullptr,
              pEntity: *(void **)((char *)&this->m_ShadowState.m_Memory.m_pMemory->m_pProxyData + v15),
              ppMaterials: nullptr,
              pMaterialFlags: nullptr,
              flags,
              boneMask,
              lod: info->m_Lod,
              pColorMeshes: nullptr);
            v15 = ia;
          }
          v15 += 20;
          infob = (const DrawModelInfo_t *)((char *)infob + 1);
          ia = v15;
        }
        while ( (int)infob < this->m_ShadowState.m_Size );
      }
      this->m_pRC->m_pForcedMaterial = pForcedMat;
      this->m_pRC->m_nForcedMaterialType = nForcedType;
      v7->EndRender(this: v7);
      v7->Release(this: v7);
    }
    else
    {
      v9->EndRender(this: v7);
      v7->Release(this: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100110D0
// Name: public: void CStudioRender::DrawStaticPropShadows(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawStaticPropShadows(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        const DrawModelInfo_t *info,
        StudioRenderContext_t *rc,
        const matrix3x4_t *rootToWorld,
        char flags)
{
  matrix3x4_t *m_PoseToWorld; // edx
  matrix3x4_t *p_m_StaticPropRootToWorld; // ecx

  *(_QWORD *)&this->m_StaticPropRootToWorld.m_flMatVal[0][0] = *(_QWORD *)&rootToWorld->m_flMatVal[0][0];
  m_PoseToWorld = this->m_PoseToWorld;
  *(_QWORD *)&this->m_StaticPropRootToWorld.m_flMatVal[0][2] = *(_QWORD *)&rootToWorld->m_flMatVal[0][2];
  *(_OWORD *)&this->m_StaticPropRootToWorld.m_flMatVal[1][0] = *(_OWORD *)&rootToWorld->m_flMatVal[1][0];
  *(_QWORD *)&this->m_StaticPropRootToWorld.m_flMatVal[2][0] = *(_QWORD *)&rootToWorld->m_flMatVal[2][0];
  p_m_StaticPropRootToWorld = &this->m_StaticPropRootToWorld;
  *(_QWORD *)&p_m_StaticPropRootToWorld->m_flMatVal[2][2] = *(_QWORD *)&rootToWorld->m_flMatVal[2][2];
  *m_PoseToWorld = *rootToWorld;
  this->m_pRC = rc;
  this->m_pBoneToWorld = p_m_StaticPropRootToWorld;
  this->m_pStudioHdr = info->m_pStudioHdr;
  this->m_pStudioMeshes = info->m_pHardwareData->m_pLODs[info->m_Lod].m_pMeshData;
  this->m_pStudioHWData = info->m_pHardwareData;
  CStudioRender::DrawShadows(this, a2, info, flags, boneMask: 524032);
  this->m_pRC = nullptr;
  this->m_pBoneToWorld = nullptr;
  this->m_pStudioHdr = nullptr;
  this->m_pStudioMeshes = nullptr;
  this->m_pStudioHWData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1006CDD0
// Name: _dynamic_initializer_for__studio_queue_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__studio_queue_mode__()
{
  ConVar::ConVar(
    this: &studio_queue_mode,
    pName: "studio_queue_mode",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: str,
    callback: (void (__cdecl *)(IConVar *, const char *, float))StudioChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__studio_queue_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1006D060
// Name: _dynamic_atexit_destructor_for__studio_queue_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__studio_queue_mode__()
{
  ConVar::~ConVar(this: &studio_queue_mode);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE00
// Name: _dynamic_initializer_for__s_StudioRenderContext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_StudioRenderContext__()
{
  CStudioRenderContext::CStudioRenderContext(this: &s_StudioRenderContext);
  return atexit(func: dynamic_atexit_destructor_for__s_StudioRenderContext__);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE20
// Name: _dynamic_initializer_for____g_CreateCStudioRenderContextIStudioRender_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCStudioRenderContextIStudioRender_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCStudioRenderContextIStudioRender_reg,
           fn: (void *(__cdecl *)())_CreateCStudioRenderContextIStudioRender_interface,
           pName: "VStudioRender026");
}

//------------------------------------------------------------------------------
// Address: 0x1006CE40
// Name: _dynamic_initializer_for__r_hwmorph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_hwmorph__()
{
  ConVar::ConVar(this: &r_hwmorph, pName: "r_hwmorph", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_hwmorph__);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE70
// Name: _dynamic_initializer_for__r_randomflex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_randomflex__()
{
  ConVar::ConVar(this: &r_randomflex, pName: "r_randomflex", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_randomflex__);
}

//------------------------------------------------------------------------------
// Address: 0x1006CEA0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1006CEC0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x1006CEE0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006CEF0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006CF50
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006CF80
// Name: _dynamic_atexit_destructor_for__r_flashlightscissor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightscissor__()
{
  ConVar::~ConVar(this: &r_flashlightscissor);
}

//------------------------------------------------------------------------------
// Address: 0x1006CF90
// Name: _dynamic_atexit_destructor_for__g_cv_morph_path__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_morph_path__()
{
  ConVar::~ConVar(this: &g_cv_morph_path);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFA0
// Name: _dynamic_atexit_destructor_for__g_cv_morph_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_morph_debug__()
{
  ConVar::~ConVar(this: &g_cv_morph_debug);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFB0
// Name: _dynamic_atexit_destructor_for__r_glint_procedural__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_glint_procedural__()
{
  ConVar::~ConVar(this: &r_glint_procedural);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFC0
// Name: _dynamic_atexit_destructor_for__r_glint_alwaysdraw__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_glint_alwaysdraw__()
{
  ConVar::~ConVar(this: &r_glint_alwaysdraw);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFD0
// Name: _dynamic_atexit_destructor_for__mat_tessellation_update_buffers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tessellation_update_buffers__()
{
  ConVar::~ConVar(this: &mat_tessellation_update_buffers);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFE0
// Name: _dynamic_atexit_destructor_for__mat_tessellation_cornertangents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tessellation_cornertangents__()
{
  ConVar::~ConVar(this: &mat_tessellation_cornertangents);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFF0
// Name: _dynamic_atexit_destructor_for__mat_tessellation_accgeometrytangents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_tessellation_accgeometrytangents__()
{
  ConVar::~ConVar(this: &mat_tessellation_accgeometrytangents);
}

//------------------------------------------------------------------------------
// Address: 0x1006D000
// Name: _dynamic_atexit_destructor_for__r_lod_switch_scale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_lod_switch_scale__()
{
  ConVar::~ConVar(this: &r_lod_switch_scale);
}

//------------------------------------------------------------------------------
// Address: 0x1006D010
// Name: _dynamic_atexit_destructor_for__mat_rendered_faces_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_rendered_faces_count__()
{
  ConVar::~ConVar(this: &mat_rendered_faces_count_0);
}

//------------------------------------------------------------------------------
// Address: 0x1006D020
// Name: _dynamic_atexit_destructor_for__mat_print_top_model_vert_counts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_print_top_model_vert_counts__()
{
  ConVar::~ConVar(this: &mat_print_top_model_vert_counts_0);
}

//------------------------------------------------------------------------------
// Address: 0x1006D030
// Name: _dynamic_atexit_destructor_for__cl_skipslowpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_skipslowpath__()
{
  ConVar::~ConVar(this: &cl_skipslowpath);
}

//------------------------------------------------------------------------------
// Address: 0x1006D040
// Name: _dynamic_atexit_destructor_for__mat_rendered_faces_spew_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_rendered_faces_spew_command__()
{
  ConCommand::~ConCommand(this: &mat_rendered_faces_spew_command);
}

//------------------------------------------------------------------------------
// Address: 0x1006D050
// Name: _dynamic_atexit_destructor_for__g_StudioRender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioRender__()
{
  CStudioRender::~CStudioRender(this: &g_StudioRender);
}

//------------------------------------------------------------------------------
// Address: 0x1006D070
// Name: _dynamic_atexit_destructor_for__r_hwmorph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_hwmorph__()
{
  ConVar::~ConVar(this: &r_hwmorph);
}

//------------------------------------------------------------------------------
// Address: 0x1006D080
// Name: _dynamic_atexit_destructor_for__r_randomflex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_randomflex__()
{
  ConVar::~ConVar(this: &r_randomflex);
}

//------------------------------------------------------------------------------
// Address: 0x1006D090
// Name: _dynamic_atexit_destructor_for__s_StudioRenderContext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_StudioRenderContext__()
{
  s_StudioRenderContext.__vftable = (CStudioRenderContext_vtbl *)&CStudioRenderContext::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1006D0A0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1006D0F0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}
