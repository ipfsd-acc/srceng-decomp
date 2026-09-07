// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiosubd.cpp
// Functions: 10
// ============================================================

#include "studiorender\r_studiosubd.h"

//------------------------------------------------------------------------------
// Address: 0x100090A0
// Name: struct matrix3x4_t __near * ComputeSkinMatrixSSE(struct mstudioboneweight_t __near &,struct matrix3x4_t __near *,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__cdecl ComputeSkinMatrixSSE(
        matrix3x4_t *boneweights,
        matrix3x4_t *pPoseToWorld,
        matrix3x4_t *scratchMatrix)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm5
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 *v8; // edx
  __m128 v9; // xmm5
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  __m128 *v12; // ecx
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 *boneMat1; // [esp+4h] [ebp-10h]
  __m128 *boneMat1a; // [esp+4h] [ebp-10h]
  __m128 *boneMat0; // [esp+8h] [ebp-Ch]
  __m128 *boneMat0a; // [esp+8h] [ebp-Ch]
  __m128 *pWeights; // [esp+Ch] [ebp-8h]
  __m128 *boneMat2; // [esp+10h] [ebp-4h]

  switch ( HIBYTE(boneweights->m_flMatVal[0][3]) )
  {
    case 2:
      boneMat1a = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
      v12 = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
      v13 = _mm_shuffle_ps(
              (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
              (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
              0);
      v14 = _mm_shuffle_ps(
              (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
              (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
              0);
      v15 = _mm_add_ps(_mm_mul_ps(boneMat1a[1], v13), _mm_mul_ps(v12[1], v14));
      v16 = _mm_add_ps(_mm_mul_ps(boneMat1a[2], v13), _mm_mul_ps(v12[2], v14));
      *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(_mm_mul_ps(*boneMat1a, v13), _mm_mul_ps(*v12, v14));
      *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = v15;
      *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = v16;
      return scratchMatrix;
    case 3:
      boneMat0a = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
      boneMat1 = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
      v8 = (__m128 *)&pPoseToWorld[BYTE2(boneweights->m_flMatVal[0][3])];
      v9 = _mm_shuffle_ps(
             (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
             (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
             0);
      v10 = _mm_shuffle_ps(
              (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
              (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
              0);
      v11 = _mm_shuffle_ps(
              (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
              (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
              0);
      *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(
                                                      _mm_add_ps(_mm_mul_ps(*boneMat0a, v9), _mm_mul_ps(*boneMat1, v10)),
                                                      _mm_mul_ps(*v8, v11));
      *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat0a[1], v9),
                                                        _mm_mul_ps(boneMat1[1], v10)),
                                                      _mm_mul_ps(v8[1], v11));
      *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat0a[2], v9),
                                                        _mm_mul_ps(boneMat1[2], v10)),
                                                      _mm_mul_ps(v8[2], v11));
      return scratchMatrix;
    case 4:
      boneMat0 = (__m128 *)&pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
      pWeights = (__m128 *)&pPoseToWorld[BYTE1(boneweights->m_flMatVal[0][3])];
      boneMat2 = (__m128 *)&pPoseToWorld[BYTE2(boneweights->m_flMatVal[0][3])];
      v4 = _mm_shuffle_ps(
             (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
             (__m128)LODWORD(boneweights->m_flMatVal[0][0]),
             0);
      v5 = _mm_shuffle_ps(
             (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
             (__m128)LODWORD(boneweights->m_flMatVal[0][1]),
             0);
      v6 = _mm_shuffle_ps(
             (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
             (__m128)LODWORD(boneweights->m_flMatVal[0][2]),
             0);
      v7 = _mm_shuffle_ps(
             (__m128)LODWORD(boneweights->m_flMatVal[0][3]),
             (__m128)LODWORD(boneweights->m_flMatVal[0][3]),
             0);
      *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(
                                                      _mm_add_ps(_mm_mul_ps(*boneMat0, v4), _mm_mul_ps(*pWeights, v5)),
                                                      _mm_add_ps(
                                                        _mm_mul_ps(*boneMat2, v6),
                                                        _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[0][0], v7)));
      *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat0[1], v4),
                                                        _mm_mul_ps(pWeights[1], v5)),
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat2[1], v6),
                                                        _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[1][0], v7)));
      *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat0[2], v4),
                                                        _mm_mul_ps(pWeights[2], v5)),
                                                      _mm_add_ps(
                                                        _mm_mul_ps(boneMat2[2], v6),
                                                        _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[2][0], v7)));
      return scratchMatrix;
    default:
      return &pPoseToWorld[LOBYTE(boneweights->m_flMatVal[0][3])];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100450A0
// Name: void __near * MemAlloc_AllocAlignedUnattributed(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_AllocAlignedUnattributed(unsigned int size, unsigned int align)
{
  unsigned int v2; // eax
  void *result; // eax
  unsigned int v4; // esi

  v2 = align;
  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( align <= 4 )
    v2 = 4;
  v4 = v2 - 1;
  result = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size + v2 - 1 + 4);
  if ( result != nullptr )
  {
    *(_DWORD *)((~v4 & ((unsigned int)result + v4 + 4)) - 4) = result;
    return (void *)(~v4 & ((unsigned int)result + v4 + 4));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100450F0
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x10045190
// Name: ComputeSkinMatrixSSE
// Source: json
//------------------------------------------------------------------------------
matrix3x4_t *__usercall ComputeSkinMatrixSSE@<eax>(
        mstudioboneweight_t *boneweights@<ecx>,
        matrix3x4_t *pPoseToWorld@<eax>,
        matrix3x4_t *scratchMatrix)
{
  int v5; // eax
  matrix3x4_t *v6; // esi
  __m128 *v8; // eax
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm7
  __m128 *v13; // edx
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 *v17; // eax
  __m128 *v18; // ecx
  __m128 v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 *boneMat1; // [esp+10h] [ebp-10h]
  __m128 *boneMat0; // [esp+14h] [ebp-Ch]
  __m128 *boneMat0a; // [esp+14h] [ebp-Ch]
  __m128 *pWeights; // [esp+18h] [ebp-8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ComputeSkinMatrixSSE",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  if ( boneweights->numbones == 2 )
  {
    v17 = (__m128 *)&pPoseToWorld[boneweights->bone[0]];
    v18 = (__m128 *)&pPoseToWorld[boneweights->bone[1]];
    v19 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[0]), (__m128)LODWORD(boneweights->weight[0]), 0);
    v20 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[1]), (__m128)LODWORD(boneweights->weight[1]), 0);
    v21 = _mm_add_ps(_mm_mul_ps(v17[1], v19), _mm_mul_ps(v18[1], v20));
    v22 = _mm_add_ps(_mm_mul_ps(v17[2], v19), _mm_mul_ps(v18[2], v20));
    *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(_mm_mul_ps(*v17, v19), _mm_mul_ps(*v18, v20));
    *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = v21;
    *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = v22;
  }
  else if ( boneweights->numbones == 3 )
  {
    boneMat0a = (__m128 *)&pPoseToWorld[boneweights->bone[0]];
    boneMat1 = (__m128 *)&pPoseToWorld[boneweights->bone[1]];
    v13 = (__m128 *)&pPoseToWorld[boneweights->bone[2]];
    v14 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[0]), (__m128)LODWORD(boneweights->weight[0]), 0);
    v15 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[1]), (__m128)LODWORD(boneweights->weight[1]), 0);
    v16 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[2]), (__m128)LODWORD(boneweights->weight[2]), 0);
    *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(
                                                    _mm_add_ps(_mm_mul_ps(*boneMat0a, v14), _mm_mul_ps(*boneMat1, v15)),
                                                    _mm_mul_ps(*v13, v16));
    *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(boneMat0a[1], v14),
                                                      _mm_mul_ps(boneMat1[1], v15)),
                                                    _mm_mul_ps(v13[1], v16));
    *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(boneMat0a[2], v14),
                                                      _mm_mul_ps(boneMat1[2], v15)),
                                                    _mm_mul_ps(v13[2], v16));
  }
  else
  {
    v5 = boneweights->bone[0];
    if ( boneweights->numbones != 4 )
    {
      v6 = &pPoseToWorld[v5];
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v6;
    }
    boneMat0 = (__m128 *)&pPoseToWorld[boneweights->bone[1]];
    pWeights = (__m128 *)&pPoseToWorld[boneweights->bone[2]];
    v8 = (__m128 *)&pPoseToWorld[v5];
    v9 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[0]), (__m128)LODWORD(boneweights->weight[0]), 0);
    v10 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[1]), (__m128)LODWORD(boneweights->weight[1]), 0);
    v11 = _mm_shuffle_ps((__m128)LODWORD(boneweights->weight[2]), (__m128)LODWORD(boneweights->weight[2]), 0);
    v12 = _mm_shuffle_ps((__m128)*(unsigned int *)boneweights->bone, (__m128)*(unsigned int *)boneweights->bone, 0);
    *(__m128 *)&scratchMatrix->m_flMatVal[0][0] = _mm_add_ps(
                                                    _mm_add_ps(_mm_mul_ps(*v8, v9), _mm_mul_ps(*boneMat0, v10)),
                                                    _mm_add_ps(
                                                      _mm_mul_ps(*pWeights, v11),
                                                      _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[0][0], v12)));
    *(__m128 *)&scratchMatrix->m_flMatVal[1][0] = _mm_add_ps(
                                                    _mm_add_ps(_mm_mul_ps(v8[1], v9), _mm_mul_ps(boneMat0[1], v10)),
                                                    _mm_add_ps(
                                                      _mm_mul_ps(pWeights[1], v11),
                                                      _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[1][0], v12)));
    *(__m128 *)&scratchMatrix->m_flMatVal[2][0] = _mm_add_ps(
                                                    _mm_add_ps(_mm_mul_ps(v8[2], v9), _mm_mul_ps(boneMat0[2], v10)),
                                                    _mm_add_ps(
                                                      _mm_mul_ps(pWeights[2], v11),
                                                      _mm_mul_ps(*(__m128 *)&pPoseToWorld[4].m_flMatVal[2][0], v12)));
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return scratchMatrix;
}

//------------------------------------------------------------------------------
// Address: 0x10045420
// Name: unsigned short __near * InitializeTopologyIndexStruct(struct TopologyIndexStruct __near &,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl InitializeTopologyIndexStruct(TopologyIndexStruct *quad, unsigned __int16 *topologyIndex)
{
  quad->vtx1RingSize = topologyIndex;
  quad->vtx1RingCenterQuadOffset = topologyIndex + 4;
  quad->valences = topologyIndex + 8;
  quad->minOneRingOffset = topologyIndex + 12;
  quad->bndVtx = topologyIndex + 16;
  quad->bndEdge = topologyIndex + 20;
  quad->cornerVtx = topologyIndex + 24;
  quad->loopGapAngle = topologyIndex + 28;
  quad->nbCornerVtx = topologyIndex + 32;
  quad->edgeBias = topologyIndex + 36;
  quad->vUV0 = topologyIndex + 44;
  quad->vUV1 = topologyIndex + 48;
  quad->vUV2 = topologyIndex + 52;
  quad->vUV3 = topologyIndex + 56;
  quad->oneRing = topologyIndex + 60;
  return &topologyIndex[*quad->vtx1RingSize + 60 + quad->vtx1RingSize[1] + quad->vtx1RingSize[2] + quad->vtx1RingSize[3]];
}

//------------------------------------------------------------------------------
// Address: 0x100454A0
// Name: private: void CStudioRender::SkinSubDCage(struct mstudiovertex_t __near *,int,struct matrix3x4_t __near *,class CCachedRenderData __near &,unsigned short __near *,union __m128 __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CStudioRender::SkinSubDCage(
        CStudioRender *this@<ecx>,
        int a2@<ebp>,
        mstudiovertex_t *pVertices,
        int nNumVertices,
        matrix3x4_t *pPoseToWorld,
        CCachedRenderData *vertexCache,
        unsigned __int16 *pGroupToMesh,
        __m128 *vOutput,
        bool bDoFlex)
{
  mstudiovertex_t *v9; // edi
  float *v10; // esi
  CCachedRenderData::CacheIndex_t *v11; // eax
  int m_VertexIndex; // eax
  CachedPosNormTan_t *p_m_vecPosition; // edi
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm4_4
  int v18; // ecx
  int v19; // eax
  int v20; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE temp_36[20]; // [esp+24h] [ebp-3Ch] OVERLAPPED
  int v22; // [esp+50h] [ebp-10h]
  int v23; // [esp+54h] [ebp-Ch]
  void *v24; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStudioRender::SkinSubDCage",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v22 = 0;
  if ( nNumVertices > 0 )
  {
    *(_DWORD *)&temp_36[12] = 1065353216;
    *(_DWORD *)&temp_36[16] = vOutput;
    do
    {
      v9 = &pVertices[pGroupToMesh[v22]];
      v10 = (float *)ComputeSkinMatrixSSE(
                       boneweights: &v9->m_BoneWeights,
                       pPoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v20);
      if ( bDoFlex
        && vertexCache->m_pFirstFlexIndex != nullptr
        && (v11 = &vertexCache->m_pFirstFlexIndex[pGroupToMesh[v22]])->m_Tag == vertexCache->m_CurrentTag )
      {
        m_VertexIndex = v11->m_VertexIndex;
        p_m_vecPosition = &vertexCache->m_pFlexVerts[m_VertexIndex];
        vertexCache->m_pFlexVerts[m_VertexIndex].m_TangentS.w = vertexCache->m_pFlexVerts[m_VertexIndex].m_Position.w;
      }
      else
      {
        p_m_vecPosition = (CachedPosNormTan_t *)&v9->m_vecPosition;
      }
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "R_TransformVert",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      y = p_m_vecPosition->m_Position.y;
      x = p_m_vecPosition->m_Position.x;
      z = p_m_vecPosition->m_Position.z;
      v17 = v10[5];
      *(float *)temp_36 = (float)((float)((float)(v10[1] * y) + (float)(*v10 * p_m_vecPosition->m_Position.x))
                                + (float)(v10[2] * z))
                        + v10[3];
      *(float *)&temp_36[4] = (float)((float)((float)(v10[4] * x) + (float)(v17 * y)) + (float)(v10[6] * z)) + v10[7];
      *(float *)&temp_36[8] = (float)((float)((float)(v10[8] * x) + (float)(v10[9] * y)) + (float)(v10[10] * z))
                            + v10[11];
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      v18 = *(_DWORD *)&temp_36[16];
      v19 = v22 + 1;
      **(_OWORD **)&temp_36[16] = *(_OWORD *)temp_36;
      v22 = v19;
      *(_DWORD *)&temp_36[16] = v18 + 16;
    }
    while ( v19 < nNumVertices );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10045660
// Name: void GenerateWorldSpacePatches(float __near *,int,unsigned short __near *,union __m128 __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall GenerateWorldSpacePatches(
        unsigned __int16 *a1@<ebp>,
        float *pSubDBuff,
        unsigned __int16 *nNumPatches,
        unsigned __int16 *pTopologyIndices,
        __m128 *pWSVertices,
        bool bRegularPatch)
{
  unsigned __int16 *v6; // esi
  int m_nValue; // eax
  int v8; // eax
  float *v9; // edi
  float *v10; // eax
  float *v11; // ecx
  int v12; // edx
  double v13; // st7
  float *p_z; // eax
  float *v15; // ecx
  int v16; // edx
  double v17; // st7
  float *v18; // eax
  float *v19; // ecx
  int v20; // edx
  double v21; // st7
  int v22; // ecx
  bool v23; // zf
  int v24; // [esp-Ch] [ebp-2CCh] BYREF
  int v25; // [esp-8h] [ebp-2C8h] BYREF
  Vector4D Geo[16]; // [esp+0h] [ebp-2C0h] BYREF
  Vector4D TanV[12]; // [esp+100h] [ebp-1C0h] BYREF
  Vector4D TanU[12]; // [esp+1C0h] [ebp-100h] BYREF
  TopologyIndexStruct quad; // [esp+280h] [ebp-40h]
  unsigned __int16 *retaddr; // [esp+2C0h] [ebp+0h]

  quad.vUV2 = a1;
  quad.vUV3 = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStudioRender::GenerateWorldSpacePatches",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  v6 = InitializeTopologyIndexStruct(quad: (TopologyIndexStruct *)&TanU[11].y, topologyIndex: pTopologyIndices);
  if ( mat_tessellation_accgeometrytangents.m_pParent != nullptr )
    m_nValue = mat_tessellation_accgeometrytangents.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  set_ShowACCGeometryTangents(v: m_nValue != 0);
  if ( mat_tessellation_cornertangents.m_pParent != nullptr )
    v8 = mat_tessellation_cornertangents.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  set_UseCornerTangents(v: v8 != 0);
  if ( (int)nNumPatches > 0 )
  {
    v9 = pSubDBuff + 49;
    quad.vUV1 = nNumPatches;
    do
    {
      ComputeACCAllPatches(
        pPos: pWSVertices,
        quad: (TopologyIndexStruct *)&TanU[11].y,
        Pos: (Vector4D *)&v24,
        TanU: (Vector4D *)&TanV[11].y,
        TanV: (Vector4D *)&Geo[15].y,
        bRegularPatch);
      v10 = (float *)&v25;
      v11 = v9 - 47;
      v12 = 2;
      do
      {
        v13 = *(v10 - 1);
        v10 += 32;
        *(v11 - 2) = v13;
        v11 += 24;
        --v12;
        *(v11 - 25) = *(v10 - 32);
        *(v11 - 24) = *(v10 - 31);
        *(v11 - 23) = *(v10 - 29);
        *(v11 - 22) = *(v10 - 28);
        *(v11 - 21) = *(v10 - 27);
        *(v11 - 20) = *(v10 - 25);
        *(v11 - 19) = *(v10 - 24);
        *(v11 - 18) = *(v10 - 23);
        *(v11 - 17) = *(v10 - 21);
        *(v11 - 16) = *(v10 - 20);
        *(v11 - 15) = *(v10 - 19);
        *(v11 - 14) = *(v10 - 17);
        *(v11 - 13) = *(v10 - 16);
        *(v11 - 12) = *(v10 - 15);
        *(v11 - 11) = *(v10 - 13);
        *(v11 - 10) = *(v10 - 12);
        *(v11 - 9) = *(v10 - 11);
        *(v11 - 8) = *(v10 - 9);
        *(v11 - 7) = *(v10 - 8);
        *(v11 - 6) = *(v10 - 7);
        *(v11 - 5) = *(v10 - 5);
        *(v11 - 4) = *(v10 - 4);
        *(v11 - 3) = *(v10 - 3);
      }
      while ( v12 != 0 );
      p_z = &TanV[11].z;
      v15 = v9;
      v16 = 2;
      do
      {
        v17 = *(p_z - 1);
        p_z += 24;
        *(v15 - 1) = v17;
        v15 += 18;
        --v16;
        *(v15 - 18) = *(p_z - 24);
        *(v15 - 17) = *(p_z - 23);
        *(v15 - 16) = *(p_z - 21);
        *(v15 - 15) = *(p_z - 20);
        *(v15 - 14) = *(p_z - 19);
        *(v15 - 13) = *(p_z - 17);
        *(v15 - 12) = *(p_z - 16);
        *(v15 - 11) = *(p_z - 15);
        *(v15 - 10) = *(p_z - 13);
        *(v15 - 9) = *(p_z - 12);
        *(v15 - 8) = *(p_z - 11);
        *(v15 - 7) = *(p_z - 9);
        *(v15 - 6) = *(p_z - 8);
        *(v15 - 5) = *(p_z - 7);
        *(v15 - 4) = *(p_z - 5);
        *(v15 - 3) = *(p_z - 4);
        *(v15 - 2) = *(p_z - 3);
      }
      while ( v16 != 0 );
      v18 = &Geo[15].z;
      v19 = v9 + 36;
      v20 = 2;
      do
      {
        v21 = *(v18 - 1);
        v18 += 24;
        *(v19 - 1) = v21;
        v19 += 18;
        --v20;
        *(v19 - 18) = *(v18 - 24);
        *(v19 - 17) = *(v18 - 23);
        *(v19 - 16) = *(v18 - 21);
        *(v19 - 15) = *(v18 - 20);
        *(v19 - 14) = *(v18 - 19);
        *(v19 - 13) = *(v18 - 17);
        *(v19 - 12) = *(v18 - 16);
        *(v19 - 11) = *(v18 - 15);
        *(v19 - 10) = *(v18 - 13);
        *(v19 - 9) = *(v18 - 12);
        *(v19 - 8) = *(v18 - 11);
        *(v19 - 7) = *(v18 - 9);
        *(v19 - 6) = *(v18 - 8);
        *(v19 - 5) = *(v18 - 7);
        *(v19 - 4) = *(v18 - 5);
        *(v19 - 3) = *(v18 - 4);
        *(v19 - 2) = *(v18 - 3);
      }
      while ( v20 != 0 );
      LODWORD(TanU[11].z) = v6 + 4;
      LODWORD(TanU[11].w) = v6 + 8;
      quad.vtx1RingSize = v6 + 12;
      quad.vtx1RingCenterQuadOffset = v6 + 16;
      quad.valences = v6 + 20;
      quad.minOneRingOffset = v6 + 24;
      quad.bndVtx = v6 + 28;
      quad.cornerVtx = v6 + 32;
      quad.bndEdge = v6 + 36;
      quad.edgeBias = v6 + 44;
      quad.nbCornerVtx = v6 + 48;
      quad.oneRing = v6 + 52;
      quad.vUV0 = v6 + 56;
      LODWORD(TanU[11].y) = v6;
      quad.loopGapAngle = v6 + 60;
      v22 = *v6 + v6[1] + v6[2] + v6[3];
      v9 += 120;
      v23 = quad.vUV1-- == (unsigned __int16 *)1;
      v6 += v22 + 60;
    }
    while ( !v23 );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10045980
// Name: private: void CStudioRender::SoftwareProcessQuadMesh(struct mstudiomesh_t __near *,class CMeshBuilder __near &,int,unsigned short __near *,unsigned short __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CStudioRender::SoftwareProcessQuadMesh(
        CStudioRender *this@<ecx>,
        int a2@<ebp>,
        mstudiomesh_t *pmesh,
        CMeshBuilder *meshBuilder,
        Vector4D *numFaces,
        unsigned __int16 *pGroupToMesh,
        unsigned __int16 *pTopologyIndices,
        bool bTangentSpace,
        bool bDoFlex)
{
  int modelindex; // ecx
  const mstudio_modelvertexdata_t *v11; // eax
  int vertexoffset; // esi
  unsigned int v13; // edi
  Vector4D *v14; // eax
  studiohdr_t *nbCornerVtx; // eax
  int v16; // ecx
  float *v17; // esi
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // edx
  int v19; // eax
  float *v20; // eax
  float *v21; // eax
  float *m_pCurrPosition; // ecx
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  bool v25; // zf
  int v26; // edi
  int v27; // esi
  int v28; // esi
  int v29; // edi
  int v30; // edx
  int v31; // [esp-Ch] [ebp-ECh] BYREF
  matrix3x4_t matTemp; // [esp+0h] [ebp-E0h] BYREF
  TopologyIndexStruct quad; // [esp+30h] [ebp-B0h]
  int v34; // [esp+6Ch] [ebp-74h]
  char *v35; // [esp+70h] [ebp-70h]
  float v36[3]; // [esp+74h] [ebp-6Ch] BYREF
  QuadTessVertex_t quadVertex; // [esp+80h] [ebp-60h]
  unsigned int v38; // [esp+B0h] [ebp-30h]
  CStudioRender *v39; // [esp+B4h] [ebp-2Ch]
  int v40; // [esp+B8h] [ebp-28h]
  mstudiovertex_t *pVertices; // [esp+BCh] [ebp-24h]
  int v42; // [esp+C0h] [ebp-20h]
  Vector4D *pStudioTangentS; // [esp+C4h] [ebp-1Ch]
  unsigned __int16 *nextPatchIndices; // [esp+C8h] [ebp-18h]
  studiohdr_t *m_pStudioHdr; // [esp+CCh] [ebp-14h]
  int p_m_TangentS; // [esp+D0h] [ebp-10h]
  int patchCorner; // [esp+D4h] [ebp-Ch]
  void *v48; // [esp+D8h] [ebp-8h]
  void *retaddr; // [esp+E0h] [ebp+0h]

  patchCorner = a2;
  v48 = retaddr;
  v39 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStudioRender::SoftwareProcessQuadMesh",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  modelindex = pmesh->modelindex;
  m_pStudioHdr = this->m_pStudioHdr;
  v40 = 0;
  v36[0] = 1.0;
  v36[1] = 0.0;
  v36[2] = 0.0;
  quadVertex.m_vTangent.x = 1.0;
  mstudiomodel_t::GetVertexData(this: (mstudiomodel_t *)((char *)pmesh + modelindex), pModelData: m_pStudioHdr);
  v11 = (const mstudio_modelvertexdata_t *)((char *)&pmesh->unused[6] + pmesh->modelindex);
  pmesh->vertexdata.modelvertexdata = v11;
  if ( v11->pVertexData == nullptr || pmesh == (mstudiomesh_t *)-48 )
    goto LABEL_22;
  vertexoffset = pmesh->vertexoffset;
  v13 = (unsigned int)v11->pVertexData + 48 * vertexoffset + 48 * ((unsigned int)v11[-3].pVertexData / 0x30);
  v38 = v13;
  if ( bTangentSpace )
    v40 = (int)v11->pTangentData + 16 * vertexoffset + 16 * ((unsigned int)v11[-3].pTangentData >> 4);
  pVertices = (mstudiovertex_t *)InitializeTopologyIndexStruct(
                                   quad: (TopologyIndexStruct *)&matTemp.m_flMatVal[2][1],
                                   topologyIndex: pTopologyIndices);
  v14 = numFaces;
  if ( (int)numFaces <= 0 )
    goto LABEL_21;
  pStudioTangentS = numFaces;
  nbCornerVtx = (studiohdr_t *)quad.nbCornerVtx;
  quad.vUV2 = (unsigned __int16 *)v36;
  while ( 2 )
  {
    quad.vUV3 = (unsigned __int16 *)((char *)quad.edgeBias - (char *)nbCornerVtx);
    v35 = (char *)((char *)quad.oneRing - (char *)nbCornerVtx);
    quad.vUV1 = (unsigned __int16 *)((char *)quad.vUV0 - (char *)nbCornerVtx);
    nextPatchIndices = nullptr;
    m_pStudioHdr = nbCornerVtx;
    v34 = LODWORD(matTemp.m_flMatVal[2][1]) - (_DWORD)nbCornerVtx;
    v42 = 4;
    while ( 1 )
    {
      v16 = quad.loopGapAngle[(_DWORD)nextPatchIndices];
      p_m_TangentS = v16;
      if ( !bTangentSpace )
        goto LABEL_18;
      v17 = (float *)ComputeSkinMatrixSSE(
                       boneweights: (mstudioboneweight_t *)(v13 + 48 * v16),
                       pPoseToWorld: v39->m_PoseToWorld,
                       scratchMatrix: (matrix3x4_t *)&v31);
      if ( !bDoFlex || (m_pFirstFlexIndex = v39->m_VertexCache.m_pFirstFlexIndex) == nullptr )
      {
        v19 = p_m_TangentS;
LABEL_16:
        p_m_TangentS = v40 + 16 * v19;
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "R_TransformTangent",
          a3: 0,
          a4: "SubD Rendering",
          a5: false,
          a6: 4);
        v21 = (float *)p_m_TangentS;
        v36[0] = (float)((float)(v17[1] * v21[1]) + (float)(*v21 * *v17)) + (float)(v17[2] * v21[2]);
        v36[1] = (float)((float)(v17[4] * *v21) + (float)(v17[5] * v21[1])) + (float)(v17[6] * v21[2]);
        v36[2] = (float)((float)(v17[8] * *v21) + (float)(v17[9] * v21[1]))
               + (float)(v17[10] * *(float *)(p_m_TangentS + 8));
        quadVertex.m_vTangent.x = *(float *)(p_m_TangentS + 12);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        quadVertex.m_vTangent.x = quadVertex.m_vTangent.x * 2.0;
        goto LABEL_17;
      }
      v19 = p_m_TangentS;
      if ( m_pFirstFlexIndex[p_m_TangentS].m_Tag != v39->m_VertexCache.m_CurrentTag )
        goto LABEL_16;
      p_m_TangentS = (int)&v39->m_VertexCache.m_pFlexVerts[v39->m_VertexCache.m_pFirstFlexIndex[p_m_TangentS].m_VertexIndex].m_TangentS;
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "R_TransformTangent",
        a3: 0,
        a4: "SubD Rendering",
        a5: false,
        a6: 4);
      v20 = (float *)p_m_TangentS;
      v36[0] = (float)((float)(v17[1] * v20[1]) + (float)(*v20 * *v17)) + (float)(v17[2] * v20[2]);
      v36[1] = (float)((float)(v17[4] * *v20) + (float)(v17[5] * v20[1])) + (float)(v17[6] * v20[2]);
      v36[2] = (float)((float)(v17[8] * *v20) + (float)(v17[9] * v20[1]))
             + (float)(v17[10] * *(float *)(p_m_TangentS + 8));
      quadVertex.m_vTangent.x = *(float *)(p_m_TangentS + 12);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
LABEL_17:
      nbCornerVtx = m_pStudioHdr;
LABEL_18:
      quadVertex.m_vTangent.y = *(float *)(v13
                                         + 48 * *(unsigned __int16 *)((char *)quad.vUV3 + (unsigned int)nbCornerVtx)
                                         + 40);
      quadVertex.m_vTangent.z = *(float *)(v13
                                         + 48 * *(unsigned __int16 *)((char *)quad.vUV3 + (unsigned int)nbCornerVtx)
                                         + 44);
      quadVertex.m_vTangent.w = *(float *)(v13 + 48 * LOWORD(nbCornerVtx->id) + 40);
      quadVertex.m_vUV01.x = *(float *)(v13 + 48 * LOWORD(nbCornerVtx->id) + 44);
      quadVertex.m_vUV01.y = *(float *)(v13 + 48 * *(unsigned __int16 *)((char *)&nbCornerVtx->id + (_DWORD)v35) + 40);
      quadVertex.m_vUV01.z = *(float *)(v13 + 48 * *(unsigned __int16 *)((char *)&nbCornerVtx->id + (_DWORD)v35) + 44);
      quadVertex.m_vUV01.w = *(float *)(v13
                                      + 48 * *(unsigned __int16 *)((char *)quad.vUV1 + (unsigned int)nbCornerVtx)
                                      + 40);
      m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
      quadVertex.m_vUV23.x = *(float *)(v13
                                      + 48 * *(unsigned __int16 *)((char *)quad.vUV1 + (unsigned int)nbCornerVtx)
                                      + 44);
      p_m_TangentS = (int)m_pCurrPosition;
      v23 = *((__m128 *)quad.vUV2 + 1);
      v24 = *((__m128 *)quad.vUV2 + 2);
      _mm_stream_ps(m_pCurrPosition, *(__m128 *)quad.vUV2);
      _mm_stream_ps(m_pCurrPosition + 4, v23);
      _mm_stream_ps(m_pCurrPosition + 8, v24);
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      nextPatchIndices = (unsigned __int16 *)((char *)nextPatchIndices
                                            + *(unsigned __int16 *)((char *)&m_pStudioHdr->id + v34));
      v25 = v42-- == 1;
      m_pStudioHdr = (studiohdr_t *)((char *)m_pStudioHdr + 2);
      if ( v25 )
        break;
      v13 = v38;
      nbCornerVtx = m_pStudioHdr;
    }
    v26 = LOWORD(pVertices->m_BoneWeights.weight[1]);
    v27 = HIWORD(pVertices->m_BoneWeights.weight[1]);
    quad.edgeBias = (unsigned __int16 *)&pVertices[1].m_vecTexCoord;
    nbCornerVtx = (studiohdr_t *)&pVertices[2];
    v28 = v26 + v27;
    v29 = HIWORD(pVertices->m_BoneWeights.weight[0]);
    quad.oneRing = (unsigned __int16 *)&pVertices[2].m_BoneWeights.weight[2];
    LODWORD(matTemp.m_flMatVal[2][1]) = pVertices;
    v30 = LOWORD(pVertices->m_BoneWeights.weight[0]);
    quad.vUV0 = (unsigned __int16 *)&pVertices[2].m_vecPosition;
    v25 = pStudioTangentS == (Vector4D *)1;
    pStudioTangentS = (Vector4D *)((char *)pStudioTangentS - 1);
    quad.loopGapAngle = (unsigned __int16 *)&pVertices[2].m_vecPosition.z;
    pVertices = (mstudiovertex_t *)((char *)pVertices + 2 * v30 + 2 * v29 + 2 * v28 + 120);
    if ( !v25 )
    {
      v13 = v38;
      continue;
    }
    break;
  }
  v14 = numFaces;
LABEL_21:
  meshBuilder->m_VertexBuilder.m_nCurrentVertex += 4 * (_DWORD)v14;
  meshBuilder->m_VertexBuilder.m_nVertexCount = meshBuilder->m_VertexBuilder.m_nCurrentVertex;
LABEL_22:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10045E50
// Name: public: void CUtlMemoryAligned<union __m128,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<__m128,16>::Grow(CUtlMemoryAligned<__m128,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  __m128 *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  __m128 *v9; // ecx

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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (__m128 *)MemAlloc_ReallocAligned(ptr: (unsigned __int8 *)m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (__m128 *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        v9[-1].m128_i32[3] = (int)v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045F50
// Name: private: void CStudioRender::GenerateBicubicPatches(struct mstudiomesh_t __near *,struct studiomeshgroup_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::GenerateBicubicPatches(
        CStudioRender *this,
        mstudiomesh_t *pmesh,
        studiomeshgroup_t *pGroup,
        bool bDoFlex)
{
  const mstudio_modelvertexdata_t *v5; // eax
  mstudio_meshvertexdata_t *v6; // ecx
  mstudiovertex_t *v7; // ebx
  int m_NumStrips; // ecx
  int v10; // ebx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  int *m_pUniqueFaces; // eax
  unsigned int v15; // ecx
  int v16; // ebx
  IMatRenderContext *v17; // eax
  IMatRenderContext *m_pObject; // edi
  OptimizedModel::StripHeader_t *v19; // edi
  unsigned __int16 *v20; // ebx
  int m_NumVertices; // [esp-4h] [ebp-1Ch]
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-Ch]
  CUtlVector<__m128,CUtlMemoryAligned<__m128,16> > *p_m_vSkinnedSubDVertices; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF
  int totalIndices; // [esp+20h] [ebp+8h]
  int s; // [esp+24h] [ebp+Ch]
  float *sa; // [esp+24h] [ebp+Ch]
  int bDoFlexa; // [esp+28h] [ebp+10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CStudioRender::GenerateBicubicPatches",
    a3: 0,
    a4: "SubD Rendering",
    a5: false,
    a6: 4);
  FillTables();
  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pmesh + pmesh->modelindex),
    pModelData: this->m_pStudioHdr);
  v5 = (const mstudio_modelvertexdata_t *)((char *)&pmesh->unused[6] + pmesh->modelindex);
  pmesh->vertexdata.modelvertexdata = v5;
  v6 = v5->pVertexData != nullptr ? &pmesh->vertexdata : nullptr;
  v7 = (mstudiovertex_t *)((char *)v6->modelvertexdata->pVertexData
                         + 48 * ((int)v6[-1].modelvertexdata + (unsigned int)v6->modelvertexdata[-3].pVertexData / 0x30));
  m_NumVertices = pGroup->m_NumVertices;
  p_m_vSkinnedSubDVertices = &this->m_vSkinnedSubDVertices;
  this->m_vSkinnedSubDVertices.m_Size = 0;
  CUtlVector<__m128,CUtlMemoryAligned<__m128,16>>::InsertMultipleBefore(
    this: &this->m_vSkinnedSubDVertices,
    elem: 0,
    num: m_NumVertices);
  CStudioRender::SkinSubDCage(
    this,
    a2: (int)&savedregs,
    pVertices: v7,
    nNumVertices: pGroup->m_NumVertices,
    pPoseToWorld: this->m_PoseToWorld,
    vertexCache: &this->m_VertexCache,
    pGroupToMesh: pGroup->m_pGroupIndexToMeshIndex,
    vOutput: this->m_vSkinnedSubDVertices.m_Memory.m_pMemory,
    bDoFlex);
  if ( mat_tessellation_update_buffers.m_pParent != nullptr
    && mat_tessellation_update_buffers.m_pParent->m_Value.m_nValue != 0 )
  {
    m_NumStrips = pGroup->m_NumStrips;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = 0;
    if ( m_NumStrips >= 2 )
    {
      m_pUniqueFaces = pGroup->m_pUniqueFaces;
      v15 = ((unsigned int)(m_NumStrips - 2) >> 1) + 1;
      s = 2 * v15;
      do
      {
        v11 += *m_pUniqueFaces;
        v12 += m_pUniqueFaces[1];
        m_pUniqueFaces += 2;
        --v15;
      }
      while ( v15 != 0 );
      v10 = 0;
      v13 = s;
    }
    if ( v13 < pGroup->m_NumStrips )
      v10 = pGroup->m_pUniqueFaces[v13];
    v16 = v12 + v11 + v10;
    v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    m_pObject = v17;
    pRenderContext.m_pObject = v17;
    if ( v17 != nullptr )
      v17->BeginRender(this: v17);
    totalIndices = 0;
    sa = m_pObject->LockSubDBuffer(this: m_pObject, a2: v16);
    bDoFlexa = 0;
    if ( pGroup->m_NumStrips > 0 )
    {
      v24 = 0;
      do
      {
        v19 = &pGroup->m_pStripData[v24];
        v20 = (unsigned __int16 *)pGroup->m_pUniqueFaces[bDoFlexa];
        GenerateWorldSpacePatches(
          a1: (unsigned __int16 *)&savedregs,
          pSubDBuff: sa,
          nNumPatches: v20,
          pTopologyIndices: &pGroup->m_pTopologyIndices[totalIndices],
          pWSVertices: p_m_vSkinnedSubDVertices->m_Memory.m_pMemory,
          bRegularPatch: (v19->flags & 2) != 0);
        totalIndices += v19->numTopologyIndices;
        sa += 120 * (_DWORD)v20;
        ++v24;
        ++bDoFlexa;
      }
      while ( bDoFlexa < pGroup->m_NumStrips );
      m_pObject = pRenderContext.m_pObject;
    }
    m_pObject->UnlockSubDBuffer(this: m_pObject);
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}
