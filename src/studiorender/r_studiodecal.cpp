// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/r_studiodecal.cpp
// Functions: 59
// ============================================================

#include "studiorender\r_studiodecal.h"

//------------------------------------------------------------------------------
// Address: 0x10001E20
// Name: bool IsErrorMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsErrorMaterial(IMaterial *pMat)
{
  return pMat == nullptr || pMat->IsErrorMaterial(this: pMat);
}

//------------------------------------------------------------------------------
// Address: 0x10001E50
// Name: private: void thinModelVertices_t::GetNormal(int,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall thinModelVertices_t::GetNormal(thinModelVertices_t *this, int vertIndex, Vector *pNormal)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm5_4
  float v14; // xmm2_4
  float v15; // [esp+0h] [ebp-8h]
  float v16; // [esp+4h] [ebp-4h]
  float vertIndexa; // [esp+10h] [ebp+8h]

  v3 = 0.0;
  v4 = (float)(unsigned __int8)this->m_vecNormals[vertIndex] - 128.0;
  if ( v4 >= 0.0 )
    v5 = 0.0;
  else
    v5 = 1.0;
  if ( (float)((float)(unsigned __int8)HIBYTE(this->m_vecNormals[vertIndex]) - 128.0) < 0.0 )
    v3 = 1.0;
  v15 = -(float)((float)(v5 * 2.0) - 1.0);
  v6 = (float)((float)(v15 * v4) - v5) - 64.0;
  v7 = 0.0;
  v8 = (float)((float)((float)-(float)((float)(v3 * 2.0) - 1.0)
                     * (float)((float)(unsigned __int8)HIBYTE(this->m_vecNormals[vertIndex]) - 128.0))
             - v3)
     - 64.0;
  v16 = v8;
  if ( v6 >= 0.0 )
    vertIndexa = 0.0;
  else
    vertIndexa = 1.0;
  if ( v8 < 0.0 )
    v7 = 1.0;
  v9 = -(float)((float)(vertIndexa * 2.0) - 1.0);
  v10 = -(float)((float)(v7 * 2.0) - 1.0);
  v11 = (float)((float)(v9 * v6) - vertIndexa) * 0.015873017;
  v12 = (float)((float)(v10 * v16) - v7) * 0.015873017;
  v13 = (float)(1.0 - v11) - v12;
  v14 = 1.0 / fsqrt((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13));
  pNormal->x = (float)(v14 * v9) * v11;
  pNormal->y = (float)(v14 * v10) * v12;
  pNormal->z = (float)(v14 * v15) * v13;
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: private: void thinModelVertices_t::GetBoneWeights(int,struct mstudioboneweight_t restrict __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall thinModelVertices_t::GetBoneWeights(
        thinModelVertices_t *this,
        int vertIndex,
        mstudioboneweight_t *pBoneWeights)
{
  int m_numBoneInfluences; // ebx
  int v4; // edx
  float *v5; // edi
  unsigned __int8 *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm3_4
  unsigned __int8 v9; // cl
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned __int8 v12; // cl
  float v13; // xmm0_4
  unsigned __int8 v14; // al

  m_numBoneInfluences = this->m_numBoneInfluences;
  v4 = this->m_numBoneInfluences - 1;
  v5 = &this->m_boneWeights[vertIndex * (v4 < 0 ? 0 : v4)];
  v6 = &this->m_boneIndices[vertIndex * this->m_numBoneInfluences];
  if ( v4 <= 0 )
  {
    v7 = 1.0;
    v8 = 1.0;
  }
  else
  {
    v7 = *v5;
    v8 = *v5;
  }
  pBoneWeights->weight[0] = v7;
  if ( m_numBoneInfluences <= 0 )
    v9 = 0;
  else
    v9 = *v6;
  pBoneWeights->bone[0] = v9;
  if ( v4 <= 1 )
  {
    v10 = 1.0 - v8;
    v11 = 1.0;
  }
  else
  {
    v10 = v5[1];
    v11 = v10 + v8;
  }
  pBoneWeights->weight[1] = v10;
  if ( m_numBoneInfluences <= 1 )
    v12 = 0;
  else
    v12 = v6[1];
  pBoneWeights->bone[1] = v12;
  if ( v4 <= 2 )
    v13 = 1.0 - v11;
  else
    v13 = v5[2];
  pBoneWeights->weight[2] = v13;
  if ( m_numBoneInfluences <= 2 )
    v14 = 0;
  else
    v14 = v6[2];
  pBoneWeights->bone[2] = v14;
  if ( m_numBoneInfluences != 0 )
    pBoneWeights->numbones = m_numBoneInfluences;
  else
    pBoneWeights->numbones = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100020B0
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, studiohdr_t *pModelData)
{
  const vertexFileHeader_t *result; // eax
  int vertexDataStart; // ecx
  char *v5; // edx
  mstudio_modelvertexdata_t *p_vertexdata; // ecx
  int tangentDataStart; // esi

  result = mstudiomodel_t::CacheVertexData(this, pModelData);
  if ( result != nullptr )
  {
    if ( result->id == 1448297545 && (vertexDataStart = result->vertexDataStart) != 0 )
      v5 = (char *)result + vertexDataStart;
    else
      v5 = nullptr;
    p_vertexdata = &this->vertexdata;
    this->vertexdata.pVertexData = v5;
    if ( result->id == 1448297545 && (tangentDataStart = result->tangentDataStart) != 0 )
    {
      this->vertexdata.pTangentData = (char *)result + tangentDataStart;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
    else
    {
      this->vertexdata.pTangentData = nullptr;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002120
// Name: public: class IMorph __near * DecalVertex_t::GetMorph(struct studiohdr_t __near *,struct studiomeshdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMorph *__thiscall DecalVertex_t::GetMorph(DecalVertex_t *this, studiohdr_t *pHdr, studiomeshdata_t *pStudioMeshes)
{
  int m_Body; // eax
  int m_Model; // edi
  int m_Mesh; // esi
  int m_Group; // edx
  char *v7; // ecx
  char *v8; // eax

  m_Body = this->m_Body;
  if ( (_WORD)m_Body == 0xFFFF )
    return nullptr;
  m_Model = this->m_Model;
  if ( (_WORD)m_Model == 0xFFFF )
    return nullptr;
  m_Mesh = this->m_Mesh;
  if ( (_WORD)m_Mesh == 0xFFFF )
    return nullptr;
  m_Group = this->m_Group;
  if ( (_WORD)m_Group == 0xFFFF )
    return nullptr;
  v7 = (char *)pHdr + 16 * m_Body + pHdr->bodypartindex;
  v8 = &v7[148 * m_Model + *((_DWORD *)v7 + 3)];
  return pStudioMeshes[*(_DWORD *)&v8[116 * m_Mesh + 32 + *((_DWORD *)v8 + 19)]].m_pMeshGroup[m_Group].m_pMorph;
}

//------------------------------------------------------------------------------
// Address: 0x100021A0
// Name: private: void CStudioRender::R_StudioTransform(class Vector __near &,struct mstudioboneweight_t __near *,struct matrix3x4_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioTransform(
        CStudioRender *this,
        Vector *in1,
        mstudioboneweight_t *pboneweight,
        matrix3x4_t *pPoseToWorld,
        Vector *out1)
{
  int v5; // edi
  float v6; // xmm0_4
  Vector out2; // [esp+4h] [ebp-Ch] BYREF

  if ( pboneweight->numbones == 1 )
  {
    VectorTransform(in1: &in1->x, in2: &pPoseToWorld[pboneweight->bone[0]], out: &out1->x);
  }
  else
  {
    *(_QWORD *)&out1->y = 0;
    out1->x = 0.0;
    v5 = 0;
    if ( pboneweight->numbones != 0 )
    {
      do
      {
        VectorTransform(in1: &in1->x, in2: &pPoseToWorld[pboneweight->bone[v5]], out: &out2.x);
        v6 = pboneweight->weight[v5];
        out1->x = (float)(out2.x * v6) + out1->x;
        out1->y = (float)(v6 * out2.y) + out1->y;
        out1->z = (float)(out2.z * v6) + out1->z;
        ++v5;
      }
      while ( v5 < pboneweight->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002270
// Name: private: void CStudioRender::R_StudioRotate(class Vector __near &,struct mstudioboneweight_t __near *,struct matrix3x4_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::R_StudioRotate(
        CStudioRender *this,
        Vector *in1,
        mstudioboneweight_t *pboneweight,
        matrix3x4_t *pPoseToWorld,
        Vector *out1)
{
  int v5; // edi
  float v6; // xmm0_4
  Vector out2; // [esp+4h] [ebp-Ch] BYREF

  if ( pboneweight->numbones == 1 )
  {
    VectorRotate(in1: &in1->x, in2: &pPoseToWorld[pboneweight->bone[0]], out: &out1->x);
  }
  else
  {
    *(_QWORD *)&out1->y = 0;
    out1->x = 0.0;
    v5 = 0;
    if ( pboneweight->numbones != 0 )
    {
      do
      {
        VectorRotate(in1: &in1->x, in2: &pPoseToWorld[pboneweight->bone[v5]], out: &out2.x);
        v6 = pboneweight->weight[v5];
        out1->x = (float)(out2.x * v6) + out1->x;
        out1->y = (float)(v6 * out2.y) + out1->y;
        out1->z = (float)(out2.z * v6) + out1->z;
        ++v5;
      }
      while ( v5 < pboneweight->numbones );
    }
    VectorNormalize(vec: out1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002340
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023B0
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002560
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: private: bool CStudioRender::IsFrontFacing(class Vector const __near *,struct mstudioboneweight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CStudioRender::IsFrontFacing(
        CStudioRender *this,
        const Vector *pnorm,
        const mstudioboneweight_t *pboneweight)
{
  CStudioRender *v4; // esi
  matrix3x4_t *m_PoseToDecal; // ecx
  float *v6; // eax
  float v7; // xmm1_4
  int v8; // eax
  matrix3x4_t *v9; // edi
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  int v13; // ecx
  float *v14; // esi
  float v15; // xmm0_4
  float v16; // xmm1_4
  matrix3x4_t *v17; // edi
  float v18; // xmm4_4
  CStudioRender *v20; // [esp+4h] [ebp-4h]
  CStudioRender *pboneweighta; // [esp+14h] [ebp+Ch]

  v4 = this;
  LOBYTE(this) = pboneweight->numbones;
  v20 = v4;
  if ( (_BYTE)this == 1 )
  {
    m_PoseToDecal = v4->m_PoseToDecal;
    v6 = m_PoseToDecal[pboneweight->bone[0]].m_flMatVal[2];
    v7 = (float)((float)(m_PoseToDecal[pboneweight->bone[0]].m_flMatVal[2][1] * pnorm->y) + (float)(pnorm->x * *v6))
       + (float)(v6[2] * pnorm->z);
  }
  else
  {
    v7 = 0.0;
    this = (CStudioRender *)(unsigned __int8)this;
    v8 = 0;
    pboneweighta = this;
    if ( (unsigned __int8)this >= 4u )
    {
      v9 = v4->m_PoseToDecal;
      y = pnorm->y;
      x = pnorm->x;
      z = pnorm->z;
      v13 = (unsigned __int8)this - 3;
      v14 = &pboneweight->weight[2];
      do
      {
        v15 = (float)((float)((float)((float)(v9[pboneweight->bone[v8 + 2]].m_flMatVal[2][1] * y)
                                    + (float)(x * v9[pboneweight->bone[v8 + 2]].m_flMatVal[2][0]))
                            + (float)(v9[pboneweight->bone[v8 + 2]].m_flMatVal[2][2] * z))
                    * *v14)
            + (float)((float)((float)((float)((float)(v9[pboneweight->bone[v8 + 1]].m_flMatVal[2][1] * y)
                                            + (float)(x * v9[pboneweight->bone[v8 + 1]].m_flMatVal[2][0]))
                                    + (float)(v9[pboneweight->bone[v8 + 1]].m_flMatVal[2][2] * z))
                            * *(v14 - 1))
                    + (float)((float)((float)((float)((float)(v9[pboneweight->bone[v8]].m_flMatVal[2][1] * y)
                                                    + (float)(x * v9[pboneweight->bone[v8]].m_flMatVal[2][0]))
                                            + (float)(v9[pboneweight->bone[v8]].m_flMatVal[2][2] * z))
                                    * *(v14 - 2))
                            + v7));
        v16 = (float)((float)((float)(v9[pboneweight->bone[v8 + 3]].m_flMatVal[2][1] * y)
                            + (float)(x * v9[pboneweight->bone[v8 + 3]].m_flMatVal[2][0]))
                    + (float)(v9[pboneweight->bone[v8 + 3]].m_flMatVal[2][2] * z))
            * v14[1];
        v8 += 4;
        v14 += 4;
        v7 = v16 + v15;
      }
      while ( v8 < v13 );
      this = pboneweighta;
      v4 = v20;
    }
    for ( ; v8 < (int)this; v7 = v7 + v18 )
    {
      v17 = v4->m_PoseToDecal;
      v18 = (float)((float)((float)(v17[pboneweight->bone[v8]].m_flMatVal[2][1] * pnorm->y)
                          + (float)(pnorm->x * v17[pboneweight->bone[v8]].m_flMatVal[2][0]))
                  + (float)(v17[pboneweight->bone[v8]].m_flMatVal[2][2] * pnorm->z))
          * pboneweight->weight[v8];
      ++v8;
    }
  }
  return v7 >= 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x100027D0
// Name: private: bool CStudioRender::TransformToDecalSpace(struct CStudioRender::DecalBuildInfo_t __near &,class Vector const __near &,struct mstudioboneweight_t __near *,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStudioRender::TransformToDecalSpace(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        const Vector *pos,
        mstudioboneweight_t *pboneweight,
        Vector2D *uv)
{
  float v5; // xmm1_4
  matrix3x4_t *m_PoseToDecal; // esi
  int v7; // edx
  int v8; // edx
  int v9; // esi
  matrix3x4_t *v10; // ecx
  float v11; // xmm3_4
  float y; // xmm4_4
  int v13; // edx
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float *v17; // edx
  float v18; // xmm0_4
  int v20; // eax
  unsigned int v21; // ecx
  signed int v22; // edx
  float v23; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  matrix3x4_t *v26; // ecx
  float *v27; // esi
  int v28; // edi
  float v29; // xmm0_4
  int v30; // edi
  float v31; // xmm1_4
  int v32; // edi
  float v33; // xmm0_4
  int v34; // edi
  float v35; // xmm1_4
  matrix3x4_t *v36; // edi
  unsigned __int8 *v37; // esi
  mstudioboneweight_t *v38; // eax
  unsigned int v39; // edx
  float v40; // xmm4_4
  CStudioRender *v41; // [esp+0h] [ebp-4h]
  Vector2D *uva; // [esp+18h] [ebp+14h]
  unsigned __int8 uv_3; // [esp+1Bh] [ebp+17h]

  v5 = 0.0;
  v41 = this;
  if ( pboneweight->numbones == 1 )
  {
    m_PoseToDecal = this->m_PoseToDecal;
    v7 = pboneweight->bone[0];
    uv->x = (float)((float)((float)(m_PoseToDecal[v7].m_flMatVal[0][1] * pos->y)
                          + (float)(m_PoseToDecal[v7].m_flMatVal[0][0] * pos->x))
                  + (float)(m_PoseToDecal[v7].m_flMatVal[0][2] * pos->z))
          + m_PoseToDecal[v7].m_flMatVal[0][3];
    v8 = pboneweight->bone[0];
    uv->y = (float)((float)((float)(m_PoseToDecal[v8].m_flMatVal[1][1] * pos->y)
                          + (float)(pos->x * m_PoseToDecal[v8].m_flMatVal[1][0]))
                  + (float)(m_PoseToDecal[v8].m_flMatVal[1][2] * pos->z))
          + m_PoseToDecal[v8].m_flMatVal[1][3];
  }
  else
  {
    uv->y = 0.0;
    uv->x = 0.0;
    v9 = 0;
    if ( pboneweight->numbones != 0 )
    {
      v10 = this->m_PoseToDecal;
      v11 = 0.0;
      do
      {
        y = pos->y;
        v13 = pboneweight->bone[v9];
        v14 = v10[v13].m_flMatVal[1][1];
        v15 = v10[v13].m_flMatVal[1][0] * pos->x;
        v16 = pos->x * v10[v13].m_flMatVal[0][0];
        v17 = (float *)&v10[v13];
        v18 = (float)((float)((float)(v14 * y) + v15) + (float)(v17[6] * pos->z)) + v17[7];
        uv->x = (float)((float)((float)((float)((float)(v17[1] * y) + v16) + (float)(v17[2] * pos->z)) + v17[3])
                      * pboneweight->weight[v9])
              + uv->x;
        v11 = (float)(pboneweight->weight[v9] * v18) + v11;
        uv->y = v11;
        ++v9;
      }
      while ( v9 < pboneweight->numbones );
      this = v41;
    }
  }
  if ( !build->m_NoPokeThru )
    return true;
  uv_3 = pboneweight->numbones;
  if ( uv_3 == 1 )
  {
    v20 = pboneweight->bone[0];
    v5 = (float)((float)((float)(this->m_PoseToDecal[v20].m_flMatVal[2][1] * pos->y)
                       + (float)(pos->x * this->m_PoseToDecal[v20].m_flMatVal[2][0]))
               + (float)(this->m_PoseToDecal[v20].m_flMatVal[2][2] * pos->z))
       + this->m_PoseToDecal[v20].m_flMatVal[2][3];
  }
  else
  {
    v21 = uv_3;
    v22 = 0;
    uva = (Vector2D *)v21;
    if ( v21 >= 4 )
    {
      v23 = pos->y;
      x = pos->x;
      z = pos->z;
      v26 = v41->m_PoseToDecal;
      v27 = &pboneweight->weight[2];
      do
      {
        v28 = pboneweight->bone[v22];
        v29 = (float)((float)((float)((float)((float)(v26[v28].m_flMatVal[2][1] * v23)
                                            + (float)(x * v26[v28].m_flMatVal[2][0]))
                                    + (float)(v26[v28].m_flMatVal[2][2] * z))
                            + v26[v28].m_flMatVal[2][3])
                    * *(v27 - 2))
            + v5;
        v30 = pboneweight->bone[v22 + 1];
        v31 = (float)((float)((float)((float)((float)(v26[v30].m_flMatVal[2][1] * v23)
                                            + (float)(x * v26[v30].m_flMatVal[2][0]))
                                    + (float)(v26[v30].m_flMatVal[2][2] * z))
                            + v26[v30].m_flMatVal[2][3])
                    * *(v27 - 1))
            + v29;
        v32 = pboneweight->bone[v22 + 2];
        v33 = (float)((float)((float)((float)((float)(v26[v32].m_flMatVal[2][1] * v23)
                                            + (float)(x * v26[v32].m_flMatVal[2][0]))
                                    + (float)(v26[v32].m_flMatVal[2][2] * z))
                            + v26[v32].m_flMatVal[2][3])
                    * *v27)
            + v31;
        v34 = pboneweight->bone[v22 + 3];
        v35 = (float)((float)((float)((float)(v26[v34].m_flMatVal[2][1] * v23) + (float)(x * v26[v34].m_flMatVal[2][0]))
                            + (float)(v26[v34].m_flMatVal[2][2] * z))
                    + v26[v34].m_flMatVal[2][3])
            * v27[1];
        v22 += 4;
        v27 += 4;
        v5 = v35 + v33;
      }
      while ( v22 < (int)&uva[-1].y + 1 );
      v21 = (unsigned int)uva;
    }
    if ( v22 < (int)v21 )
    {
      v37 = &pboneweight->bone[v22];
      v38 = &pboneweight[v22 / 4u];
      v39 = v21 - v22;
      do
      {
        v36 = v41->m_PoseToDecal;
        v40 = (float)((float)((float)((float)(v36[*v37].m_flMatVal[2][1] * pos->y)
                                    + (float)(pos->x * v36[*v37].m_flMatVal[2][0]))
                            + (float)(v36[*v37].m_flMatVal[2][2] * pos->z))
                    + v36[*v37].m_flMatVal[2][3])
            * v38->weight[0];
        ++v37;
        v38 = (mstudioboneweight_t *)((char *)v38 + 4);
        --v39;
        v5 = v5 + v40;
      }
      while ( v39 != 0 );
    }
  }
  return build->m_flMaxDepth > COERCE_FLOAT(LODWORD(v5) & _mask__AbsFloat_);
}

//------------------------------------------------------------------------------
// Address: 0x10002B70
// Name: IntersectPlane
// Source: json
//------------------------------------------------------------------------------
int __usercall IntersectPlane@<eax>(int start@<eax>, int normalInd@<ecx>, DecalClipState_t *state, int end, float val)
{
  DecalVertex_t *v5; // edi
  DecalVertex_t *v6; // ebx
  float v7; // xmm0_4
  DecalVertex_t *v8; // esi
  float y; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // ecx
  float v13; // xmm0_4
  Vector vec; // [esp+Ch] [ebp-Ch] BYREF
  int enda; // [esp+24h] [ebp+Ch]
  float t; // [esp+28h] [ebp+10h]

  v5 = &state->m_ClipVerts[start];
  v6 = &state->m_ClipVerts[end];
  vec.y = state->m_ClipVerts[end].m_TexCoord.x - state->m_ClipVerts[start].m_TexCoord.x;
  vec.z = state->m_ClipVerts[end].m_TexCoord.y - state->m_ClipVerts[start].m_TexCoord.y;
  v7 = (float)(val - *(&v5->m_TexCoord.x + normalInd)) / *(&vec.y + normalInd);
  v8 = &state->m_ClipVerts[state->m_ClipVertCount];
  enda = state->m_ClipVertCount;
  state->m_ClipVertCount = enda + 1;
  *(_DWORD *)&v8->m_Model = -1;
  v8->m_MeshVertexIndex = -1;
  v8->m_Body = -1;
  v8->m_Position.x = (float)(v6->m_Position.x * v7) + (float)(v5->m_Position.x * (float)(1.0 - v7));
  v8->m_Position.y = (float)(v6->m_Position.y * v7)
                   + (float)(state->m_ClipVerts[start].m_Position.y * (float)(1.0 - v7));
  v8->m_Position.z = (float)((float)(1.0 - v7) * state->m_ClipVerts[start].m_Position.z)
                   + (float)(v6->m_Position.z * v7);
  y = state->m_ClipVerts[start].m_Position.y;
  vec.x = (float)(v6->m_Position.x * v7) + (float)(v5->m_Position.x * (float)(1.0 - v7));
  v10 = (float)(1.0 - v7) * state->m_ClipVerts[start].m_Position.z;
  vec.y = (float)(v6->m_Position.y * v7) + (float)(y * (float)(1.0 - v7));
  t = v7;
  vec.z = v10 + (float)(v6->m_Position.z * v7);
  VectorNormalize(&vec);
  v8->m_Normal = vec;
  v11 = (float)((float)(v6->m_TexCoord.x - v5->m_TexCoord.x) * v7) + v5->m_TexCoord.x;
  v8->m_TexCoord.y = (float)((float)(v6->m_TexCoord.y - v5->m_TexCoord.y) * t) + v5->m_TexCoord.y;
  v12 = 0;
  v8->m_TexCoord.x = v11;
  if ( v11 >= 0.0 )
  {
    if ( v11 > 1.0 )
      v12 = 4;
  }
  else
  {
    v12 = 1;
  }
  v13 = v8->m_TexCoord.y;
  if ( v13 >= 0.0 )
  {
    if ( v13 > 1.0 )
      v12 |= 8u;
    state->m_ClipFlags[enda] = v12;
    return enda;
  }
  else
  {
    state->m_ClipFlags[enda] = v12 | 2;
    return enda;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D50
// Name: ClipTriangleAgainstPlane
// Source: json
//------------------------------------------------------------------------------
void __usercall ClipTriangleAgainstPlane(DecalClipState_t *state@<esi>, int normalInd, int flag, float val)
{
  int v4; // eax
  int v5; // edi
  bool v6; // dl
  int v7; // ebx
  bool v8; // zf
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+13h] [ebp-1h]

  v4 = *(&state->m_VertCount + 7 * state->m_Pass + state->m_VertCount);
  v5 = 0;
  i = 0;
  v6 = (flag & state->m_ClipFlags[v4]) == 0;
  if ( state->m_VertCount > 0 )
  {
    while ( 1 )
    {
      v7 = state->m_Indices[(unsigned __int8)state->m_Pass][i];
      endInside = (flag & state->m_ClipFlags[v7]) == 0;
      if ( (flag & state->m_ClipFlags[v7]) == 0 )
        break;
      if ( v6 )
      {
        state->m_Indices[!state->m_Pass][v5] = IntersectPlane(start: v4, normalInd, state, end: v7, val);
LABEL_8:
        ++v5;
      }
      v6 = endInside;
      v4 = v7;
      if ( ++i >= state->m_VertCount )
        goto LABEL_10;
    }
    if ( !v6 )
      state->m_Indices[!state->m_Pass][v5++] = IntersectPlane(start: v4, normalInd, state, end: v7, val);
    state->m_Indices[!state->m_Pass][v5] = v7;
    goto LABEL_8;
  }
LABEL_10:
  v8 = !state->m_Pass;
  state->m_VertCount = v5;
  state->m_Pass = v8;
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: private: bool CStudioRender::ComputePoseToDecal(struct Ray_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::ComputePoseToDecal(CStudioRender *this, const Ray_t *ray, const Vector *up)
{
  float z; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  studiohdr_t *m_pStudioHdr; // eax
  float y; // xmm0_4
  float x; // xmm4_4
  int v15; // ebx
  int v16; // edi
  matrix3x4_t worldToDecal; // [esp+0h] [ebp-48h] BYREF
  Vector decalU; // [esp+30h] [ebp-18h] BYREF
  Vector decalN; // [esp+3Ch] [ebp-Ch] BYREF
  float raya; // [esp+50h] [ebp+8h]

  decalN.x = ray->m_Delta.x * -1.0;
  decalN.y = ray->m_Delta.y * -1.0;
  decalN.z = ray->m_Delta.z * -1.0;
  if ( VectorNormalize(vec: &decalN) == 0.0 )
    return 0;
  z = up->z;
  v7 = up->y * decalN.x;
  decalU.x = (float)(up->y * decalN.z) - (float)(z * decalN.y);
  v8 = (float)(up->x * decalN.y) - v7;
  decalU.y = (float)(z * decalN.x) - (float)(up->x * decalN.z);
  decalU.z = v8;
  if ( VectorNormalize(vec: &decalU) < 0.001 )
  {
    v9 = up->z;
    v10 = (float)(up->x * decalN.x) - (float)(decalN.z * up->y);
    v11 = (float)(decalN.y * up->y) - (float)(v9 * decalN.x);
    decalU.x = (float)(v9 * decalN.z) - (float)(up->x * decalN.y);
    decalU.y = v10;
    decalU.z = v11;
    if ( VectorNormalize(vec: &decalU) < 0.001 )
      return 0;
  }
  m_pStudioHdr = this->m_pStudioHdr;
  worldToDecal.m_flMatVal[2][0] = decalN.x;
  y = ray->m_Start.y;
  raya = ray->m_Start.z;
  *(Vector *)&worldToDecal.m_flMatVal[0][0] = decalU;
  *(_QWORD *)&worldToDecal.m_flMatVal[2][1] = *(_QWORD *)&decalN.y;
  x = ray->m_Start.x;
  worldToDecal.m_flMatVal[1][1] = (float)(decalN.z * decalU.x) - (float)(decalU.z * decalN.x);
  worldToDecal.m_flMatVal[1][0] = (float)(decalU.z * decalN.y) - (float)(decalU.y * decalN.z);
  v15 = 0;
  worldToDecal.m_flMatVal[1][2] = (float)(decalU.y * decalN.x) - (float)(decalN.y * decalU.x);
  worldToDecal.m_flMatVal[0][3] = -(float)((float)((float)(y * decalU.y) + (float)(x * decalU.x))
                                         + (float)(raya * decalU.z));
  worldToDecal.m_flMatVal[1][3] = -(float)((float)((float)(y * worldToDecal.m_flMatVal[1][1])
                                                 + (float)(x * worldToDecal.m_flMatVal[1][0]))
                                         + (float)(raya * worldToDecal.m_flMatVal[1][2]));
  worldToDecal.m_flMatVal[2][3] = -(float)((float)((float)(y * decalN.y) + (float)(x * decalN.x))
                                         + (float)(raya * decalN.z));
  if ( m_pStudioHdr->numbones > 0 )
  {
    v16 = 0;
    do
    {
      ConcatTransforms(in1: &worldToDecal, in2: &this->m_PoseToWorld[v16], out: &this->m_PoseToDecal[v16]);
      ++v15;
      ++v16;
    }
    while ( v15 < this->m_pStudioHdr->numbones );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003110
// Name: private: int CStudioRender::ComputeTotalMeshCount(int,int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::ComputeTotalMeshCount(CStudioRender *this, int iRootLOD, int iMaxLOD, int body)
{
  studiohdr_t *m_pStudioHdr; // eax
  int v6; // esi
  int i; // edi
  mstudiomodel_t *pSubModel; // [esp+Ch] [ebp-4h] BYREF

  m_pStudioHdr = this->m_pStudioHdr;
  v6 = 0;
  for ( i = 0; v6 < m_pStudioHdr->numbodyparts; ++v6 )
  {
    R_StudioSetupModel(bodypart: v6, entity_body: body, ppSubModel: &pSubModel, pStudioHdr: m_pStudioHdr);
    m_pStudioHdr = this->m_pStudioHdr;
    i += pSubModel->nummeshes;
  }
  return i * (iMaxLOD - iRootLOD + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10003170
// Name: private: int CStudioRender::ComputeVertexAllocation(int,int,struct studiohwdata_t __near *,struct MeshVertexInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::ComputeVertexAllocation(
        CStudioRender *this,
        int iMaxLOD,
        int body,
        studiohwdata_t *pHardwareData,
        MeshVertexInfo_t *pMeshVertices)
{
  studiohwdata_t *v5; // esi
  CStudioRender *v6; // edi
  studiohdr_t *m_pStudioHdr; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // esi
  mstudiomodel_t *v12; // eax
  MeshVertexInfo_t *v13; // ecx
  int *p_m_nIndex; // edi
  mstudiomesh_t *v15; // esi
  int v16; // eax
  IMaterial *v17; // ebx
  int v18; // eax
  IMaterial **ppMaterials; // [esp+Ch] [ebp-28h]
  int v21; // [esp+10h] [ebp-24h]
  int i; // [esp+14h] [ebp-20h]
  int k; // [esp+18h] [ebp-1Ch]
  CStudioRender *v24; // [esp+1Ch] [ebp-18h]
  mstudiomodel_t *pSubModel; // [esp+20h] [ebp-14h] BYREF
  int nCurrMesh; // [esp+24h] [ebp-10h]
  int meshID; // [esp+28h] [ebp-Ch]
  int nVertexCount; // [esp+2Ch] [ebp-8h]
  bool bSuppressTlucDecal; // [esp+33h] [ebp-1h]
  int iMaxLODa; // [esp+3Ch] [ebp+8h]

  v5 = pHardwareData;
  v6 = this;
  m_pStudioHdr = this->m_pStudioHdr;
  bSuppressTlucDecal = (m_pStudioHdr->flags & 8) != 0;
  v8 = iMaxLOD - 1;
  v9 = 0;
  v24 = v6;
  nCurrMesh = 0;
  nVertexCount = 0;
  i = iMaxLOD - 1;
  if ( iMaxLOD - 1 < pHardwareData->m_RootLOD )
    return 0;
  v10 = 32 * v8;
  v21 = 32 * v8;
  do
  {
    ppMaterials = *(IMaterial ***)((char *)&v5->m_pLODs->ppMaterials + v10);
    v11 = 0;
    k = 0;
    if ( m_pStudioHdr->numbodyparts > 0 )
    {
      do
      {
        R_StudioSetupModel(bodypart: v11, entity_body: body, ppSubModel: &pSubModel, pStudioHdr: m_pStudioHdr);
        v12 = pSubModel;
        meshID = 0;
        if ( pSubModel->nummeshes > 0 )
        {
          iMaxLODa = 0;
          v13 = pMeshVertices;
          p_m_nIndex = &pMeshVertices[v9].m_nIndex;
          while ( 1 )
          {
            v15 = (mstudiomesh_t *)&v12->name[iMaxLODa + v12->meshindex];
            *(p_m_nIndex - 1) = (int)v15;
            v16 = v9 - 1;
            if ( v9 < 1 )
              goto LABEL_12;
            while ( v13[v16].m_pMesh != v15 )
            {
              if ( --v16 < 0 )
                goto LABEL_12;
            }
            *p_m_nIndex = v13[v16].m_nIndex;
            if ( v16 < 0 )
            {
LABEL_12:
              v17 = ppMaterials[*(__int16 *)((char *)&v24->m_pStudioHdr->id
                                           + 2 * v15->material
                                           + v24->m_pStudioHdr->skinindex)];
              if ( bSuppressTlucDecal && v17->IsTranslucent(this: v17) )
              {
                *p_m_nIndex = -1;
              }
              else if ( v17->GetMaterialVarFlag(this: v17, a2: MATERIAL_VAR_SUPPRESS_DECALS) )
              {
                *p_m_nIndex = -1;
              }
              else
              {
                v18 = nVertexCount;
                *p_m_nIndex = nVertexCount;
                nVertexCount = v15->numvertices + v18;
              }
            }
            v12 = pSubModel;
            iMaxLODa += 116;
            v9 = nCurrMesh + 1;
            p_m_nIndex += 2;
            ++meshID;
            ++nCurrMesh;
            if ( meshID >= pSubModel->nummeshes )
              break;
            v13 = pMeshVertices;
          }
          v11 = k;
          v6 = v24;
        }
        m_pStudioHdr = v6->m_pStudioHdr;
        k = ++v11;
      }
      while ( v11 < m_pStudioHdr->numbodyparts );
      v8 = i;
      v10 = v21;
    }
    v5 = pHardwareData;
    --v8;
    v10 -= 32;
    i = v8;
    v21 = v10;
  }
  while ( v8 >= pHardwareData->m_RootLOD );
  return nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x10003310
// Name: private: bool CStudioRender::PreDrawDecal(class IMatRenderContext __near *,struct DrawModelInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::PreDrawDecal(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        const DrawModelInfo_t *drawInfo)
{
  StudioRenderContext_t *m_pRC; // ecx
  Vector *m_vecAmbientCube; // esi
  StudioRenderContext_t *v7; // eax

  if ( !drawInfo->m_bStaticLighting )
    return 0;
  m_pRC = this->m_pRC;
  if ( m_pRC->m_Config.fullbright != 0 )
  {
    m_vecAmbientCube = s_pWhite;
    m_pRC->m_NumLocalLights = 0;
  }
  else
  {
    m_vecAmbientCube = drawInfo->m_LightingState.m_vecAmbientCube;
    this->m_pRC->m_NumLocalLights = CopyLocalLightingState(
                                      nMaxLights: 4,
                                      pDest: m_pRC->m_LocalLights,
                                      nLightCount: drawInfo->m_LightingState.m_nLocalLightCount,
                                      pSrc: drawInfo->m_LightingState.m_pLocalLightDesc);
  }
  v7 = this->m_pRC;
  v7->m_LightBoxColors[0].x = m_vecAmbientCube->x;
  v7->m_LightBoxColors[0].y = m_vecAmbientCube->y;
  v7->m_LightBoxColors[0].z = m_vecAmbientCube->z;
  v7->m_LightBoxColors[0].w = 1.0;
  v7->m_LightBoxColors[1].x = m_vecAmbientCube[1].x;
  v7->m_LightBoxColors[1].y = m_vecAmbientCube[1].y;
  v7->m_LightBoxColors[1].z = m_vecAmbientCube[1].z;
  v7->m_LightBoxColors[1].w = 1.0;
  v7->m_LightBoxColors[2].x = m_vecAmbientCube[2].x;
  v7->m_LightBoxColors[2].y = m_vecAmbientCube[2].y;
  v7->m_LightBoxColors[2].z = m_vecAmbientCube[2].z;
  v7->m_LightBoxColors[2].w = 1.0;
  v7->m_LightBoxColors[3].x = m_vecAmbientCube[3].x;
  v7->m_LightBoxColors[3].y = m_vecAmbientCube[3].y;
  v7->m_LightBoxColors[3].z = m_vecAmbientCube[3].z;
  v7->m_LightBoxColors[3].w = 1.0;
  v7->m_LightBoxColors[4].x = m_vecAmbientCube[4].x;
  v7->m_LightBoxColors[4].y = m_vecAmbientCube[4].y;
  v7->m_LightBoxColors[4].z = m_vecAmbientCube[4].z;
  v7->m_LightBoxColors[4].w = 1.0;
  v7->m_LightBoxColors[5].x = m_vecAmbientCube[5].x;
  v7->m_LightBoxColors[5].y = m_vecAmbientCube[5].y;
  v7->m_LightBoxColors[5].z = m_vecAmbientCube[5].z;
  v7->m_LightBoxColors[5].w = 1.0;
  CStudioRender::SetLightingRenderState(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003450
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003590
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::Decal_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: m_pMemory,
                                                                                        a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                        this: _g_pMemAlloc,
                                                                                        a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003640
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003760
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003790
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10003850
// Name: private: void CStudioRender::ConvertMeshVertexToDecalVertex(struct CStudioRender::DecalBuildInfo_t __near &,int,struct DecalVertex_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ConvertMeshVertexToDecalVertex(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int meshIndex,
        DecalVertex_t *decalVertex,
        unsigned __int16 nGroupIndex)
{
  DecalVertex_t *v5; // ecx
  Vector *v6; // eax
  mstudiomesh_t *m_pMesh; // ebx
  const thinModelVertices_t *m_pMeshThinVertexData; // ecx
  Vector *m_vecPositions; // edx
  float x; // xmm0_4
  Vector *v11; // eax
  const mstudio_modelvertexdata_t *modelvertexdata; // edx
  unsigned int v13; // edx
  Vector normal; // [esp+Ch] [ebp-18h] BYREF
  Vector position; // [esp+18h] [ebp-Ch]

  if ( build->m_pMeshVertexData != nullptr )
  {
    v5 = decalVertex;
    decalVertex->m_Position = *(Vector *)((char *)build->m_pMeshVertexData->modelvertexdata->pVertexData
                                        + 48
                                        * ((int)build->m_pMeshVertexData[-1].modelvertexdata
                                         + (unsigned int)build->m_pMeshVertexData->modelvertexdata[-3].pVertexData
                                         / 0x30
                                         + meshIndex)
                                        + 16);
    v6 = (Vector *)((char *)build->m_pMeshVertexData->modelvertexdata->pVertexData
                  + 48
                  * ((int)build->m_pMeshVertexData[-1].modelvertexdata
                   + (unsigned int)build->m_pMeshVertexData->modelvertexdata[-3].pVertexData / 0x30
                   + meshIndex)
                  + 28);
    decalVertex->m_Normal = *v6;
  }
  else
  {
    m_pMesh = build->m_pMesh;
    m_pMeshThinVertexData = build->m_pMeshThinVertexData;
    m_vecPositions = m_pMeshThinVertexData->m_vecPositions;
    x = m_vecPositions[meshIndex
                     + m_pMesh->vertexoffset
                     + (unsigned int)m_pMesh->vertexdata.modelvertexdata[-3].pVertexData / 0x30].x;
    v11 = &m_vecPositions[meshIndex
                        + m_pMesh->vertexoffset
                        + (unsigned int)m_pMesh->vertexdata.modelvertexdata[-3].pVertexData / 0x30];
    modelvertexdata = m_pMesh->vertexdata.modelvertexdata;
    position.x = x;
    position.y = v11->y;
    v13 = m_pMesh->vertexoffset + (unsigned int)modelvertexdata[-3].pVertexData / 0x30;
    position.z = v11->z;
    thinModelVertices_t::GetNormal(this: m_pMeshThinVertexData, vertIndex: meshIndex + v13, pNormal: &normal);
    v5 = decalVertex;
    decalVertex->m_Position = position;
    decalVertex->m_Normal = normal;
  }
  v5->m_TexCoord = build->m_pVertexInfo[meshIndex].m_UV;
  v5->m_MeshVertexIndex = meshIndex;
  v5->m_Mesh = build->m_Mesh;
  v5->m_Model = build->m_Model;
  v5->m_Body = build->m_Body;
  v5->m_Group = build->m_Group;
  v5->m_GroupIndex = nGroupIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100039C0
// Name: private: void CStudioRender::ProjectDecalsOntoMeshes(struct CStudioRender::DecalBuildInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::ProjectDecalsOntoMeshes(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int nMeshCount)
{
  int v3; // eax
  float v4; // xmm0_4
  MeshVertexInfo_t *v5; // ecx
  int m_nIndex; // eax
  mstudiomesh_t *m_pMesh; // ebx
  float m_Radius; // xmm1_4
  const Vector *v9; // ecx
  mstudiomodel_t *v10; // ecx
  mstudiomodel_t *v11; // edx
  _DWORD **v12; // edi
  thinModelVertices_t *v13; // ecx
  const vertexFileHeader_t *v14; // eax
  int vertexDataStart; // ecx
  thinModelVertices_t *v16; // eax
  bool v17; // cc
  _BYTE *v18; // esi
  unsigned int v19; // eax
  Vector *v20; // ecx
  mstudioboneweight_t *p_pBoneWeights; // ebx
  int v22; // edi
  Vector *m_vecPositions; // eax
  float x; // xmm0_4
  Vector *v25; // eax
  CStudioRender *v26; // ecx
  CStudioRender *v27; // ecx
  bool v28; // al
  float v29; // xmm0_4
  float v30; // xmm2_4
  const Vector *v31; // [esp-18h] [ebp-68h]
  const Vector *v32; // [esp-14h] [ebp-64h]
  studiohdr_t *m_pStudioHdr; // [esp-10h] [ebp-60h]
  mstudioboneweight_t pBoneWeights; // [esp+0h] [ebp-50h] BYREF
  Vector pNormal; // [esp+10h] [ebp-40h] BYREF
  _DWORD v36[3]; // [esp+1Ch] [ebp-34h] BYREF
  Vector *p_pNormal; // [esp+28h] [ebp-28h]
  int i; // [esp+2Ch] [ebp-24h]
  mstudiomesh_t *v39; // [esp+30h] [ebp-20h]
  _DWORD **v40; // [esp+34h] [ebp-1Ch]
  float v41; // [esp+38h] [ebp-18h]
  CStudioRender *v42; // [esp+3Ch] [ebp-14h]
  const Vector *pos; // [esp+40h] [ebp-10h]
  int nMaxVertexIndex; // [esp+44h] [ebp-Ch]
  int v45; // [esp+48h] [ebp-8h]
  thinModelVertices_t *v46; // [esp+4Ch] [ebp-4h]

  v3 = 0;
  v42 = this;
  nMaxVertexIndex = -1;
  i = 0;
  if ( nMeshCount > 0 )
  {
    while ( 1 )
    {
      v4 = 1.0;
      v5 = &build->m_pMeshVertices[v3];
      m_nIndex = v5->m_nIndex;
      if ( m_nIndex >= 0 && m_nIndex > nMaxVertexIndex )
      {
        m_pMesh = v5->m_pMesh;
        m_Radius = build->m_Radius;
        nMaxVertexIndex = v5->m_nIndex;
        v9 = (const Vector *)&build->m_pVertexBuffer[m_nIndex];
        v39 = m_pMesh;
        pos = v9;
        if ( m_Radius != 0.0 )
          v4 = 1.0 / m_Radius;
        m_pStudioHdr = build->m_pStudioHdr;
        v10 = (mstudiomodel_t *)((char *)m_pMesh + m_pMesh->modelindex);
        v41 = v4;
        mstudiomodel_t::GetVertexData(this: v10, pModelData: m_pStudioHdr);
        v11 = (mstudiomodel_t *)((char *)m_pMesh + m_pMesh->modelindex);
        m_pMesh->vertexdata.modelvertexdata = &v11->vertexdata;
        v12 = v11->vertexdata.pVertexData != nullptr ? (_DWORD **)&m_pMesh->vertexdata : nullptr;
        v13 = nullptr;
        v40 = v12;
        v46 = nullptr;
        if ( v12 != nullptr )
          goto LABEL_14;
        v14 = mstudiomodel_t::CacheVertexData(this: v11, pModelData: build->m_pStudioHdr);
        if ( v14 != nullptr && v14->id == 1447248969 && (vertexDataStart = v14->vertexDataStart) != 0 )
          v16 = (thinModelVertices_t *)((char *)v14 + vertexDataStart);
        else
          v16 = nullptr;
        v46 = v16;
        if ( v16 != nullptr )
          break;
      }
LABEL_23:
      v3 = i + 1;
      i = v3;
      if ( v3 >= nMeshCount )
        return;
    }
    v13 = v16;
LABEL_14:
    v17 = m_pMesh->numvertices <= 0;
    v45 = 0;
    if ( !v17 )
    {
      v18 = (char *)&pos->z + 3;
      while ( 1 )
      {
        if ( v12 != nullptr )
        {
          v19 = **v12 + 48 * ((_DWORD)*(v12 - 9) + *(*v12 - 6) / 0x30u + v45);
          pos = (const Vector *)(v19 + 16);
          v20 = (Vector *)(v19 + 28);
          p_pBoneWeights = (mstudioboneweight_t *)v19;
        }
        else
        {
          v22 = m_pMesh->vertexoffset + (unsigned int)m_pMesh->vertexdata.modelvertexdata[-3].pVertexData / 0x30 + v45;
          m_vecPositions = v13->m_vecPositions;
          x = m_vecPositions[v22].x;
          v25 = &m_vecPositions[v22];
          *(float *)v36 = x;
          v36[1] = LODWORD(v25->y);
          v36[2] = LODWORD(v25->z);
          pos = (const Vector *)v36;
          thinModelVertices_t::GetNormal(this: v13, vertIndex: v22, &pNormal);
          p_pNormal = &pNormal;
          thinModelVertices_t::GetBoneWeights(this: v46, vertIndex: v22, &pBoneWeights);
          v12 = v40;
          v20 = p_pNormal;
          p_pBoneWeights = &pBoneWeights;
        }
        v32 = v20;
        v26 = v42;
        *(_DWORD *)(v18 - 3) = 0xFFFFFF;
        if ( CStudioRender::IsFrontFacing(this: v26, pnorm: v32, pboneweight: p_pBoneWeights) )
        {
          v31 = pos;
          v27 = v42;
          *v18 = 1;
          v28 = CStudioRender::TransformToDecalSpace(
                  this: v27,
                  build,
                  pos: v31,
                  pboneweight: p_pBoneWeights,
                  uv: (Vector2D *)(v18 - 11));
          v29 = v41 * 0.5;
          *v18 |= 2 * v28;
          v30 = *(float *)(v18 - 11) * v29;
          *(float *)(v18 - 7) = v29 * *(float *)(v18 - 7);
          *(float *)(v18 - 11) = v30 + 0.5;
          v12 = v40;
          *(float *)(v18 - 7) = *(float *)(v18 - 7) + 0.5;
        }
        v18 += 12;
        if ( ++v45 >= v39->numvertices )
          break;
        v13 = v46;
        m_pMesh = v39;
      }
    }
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003BF0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: m_pMemory,
                                                                                                a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                this: _g_pMemAlloc,
                                                                                                a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CA0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalHistory_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: m_pMemory,
                                                                                               a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D50
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10003DD0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalModelList_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 20 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 20 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 20 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10003E50
// Name: public: void CCachedRenderData::SetBodyModelMesh(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::SetBodyModelMesh(CCachedRenderData *this, int body, int model, int mesh)
{
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *m_pMemory; // edi
  CCachedRenderData::CacheDict_t *v5; // eax

  this->m_Body = body;
  m_pMemory = this->m_CacheDict.m_Memory.m_pMemory;
  this->m_Model = model;
  this->m_Mesh = mesh;
  v5 = &m_pMemory[body].m_Memory.m_pMemory[model].m_Memory.m_pMemory[mesh];
  if ( v5->m_Tag == this->m_CurrentTag )
  {
    this->m_pFirstFlexIndex = &this->m_pFlexIndex[v5->m_FirstIndex];
    this->m_pFirstThinFlexIndex = &this->m_pThinFlexIndex[v5->m_FirstIndex];
    this->m_pFirstWorldIndex = &this->m_pWorldIndex[v5->m_FirstIndex];
  }
  else
  {
    this->m_pFirstFlexIndex = nullptr;
    this->m_pFirstThinFlexIndex = nullptr;
    this->m_pFirstWorldIndex = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004630
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CStudioRender::DecalLRU_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100046B0
// Name: private: void CStudioRender::DrawSingleBoneDecals(class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawSingleBoneDecals(
        CStudioRender *this,
        CMeshBuilder *meshBuilder,
        const CStudioRender::DecalMaterial_t *decalMaterial)
{
  unsigned __int16 i; // cx
  float *m_pCurrPosition; // edx
  float *m_pCurrNormal; // esi
  int v6; // edi
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v7; // ecx
  float *v8; // edx
  double y; // st7
  unsigned __int8 *m_pCurrColor; // ecx
  int v11; // ecx

  for ( i = decalMaterial->m_Vertices.m_Head; i != 0xFFFF; i = decalMaterial->m_Vertices.m_Memory.m_pMemory[v6].m_Next )
  {
    m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
    v6 = i;
    v7 = &decalMaterial->m_Vertices.m_Memory.m_pMemory[v6];
    *m_pCurrPosition = v7->m_Element.m_Position.x;
    m_pCurrPosition[1] = v7->m_Element.m_Position.y;
    m_pCurrPosition[2] = v7->m_Element.m_Position.z;
    v8 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *m_pCurrNormal = v7->m_Element.m_Normal.x;
    m_pCurrNormal[1] = v7->m_Element.m_Normal.y;
    m_pCurrNormal[2] = v7->m_Element.m_Normal.z;
    *v8 = v7->m_Element.m_TexCoord.x;
    y = v7->m_Element.m_TexCoord.y;
    m_pCurrColor = meshBuilder->m_VertexBuilder.m_pCurrColor;
    v8[1] = y;
    *(_DWORD *)m_pCurrColor = -1;
    v11 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
    if ( v11 > meshBuilder->m_VertexBuilder.m_nVertexCount )
      meshBuilder->m_VertexBuilder.m_nVertexCount = v11;
    meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                           + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
    meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                         + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
    meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
    meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                              + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004790
// Name: private: void CStudioRender::DrawSingleBoneFlexedDecals(class IMatRenderContext __near *,class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawSingleBoneFlexedDecals(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        CMeshBuilder *meshBuilder,
        CStudioRender::DecalMaterial_t *decalMaterial)
{
  unsigned __int16 m_Head; // ax
  CCachedRenderData *p_m_VertexCache; // ebx
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // edi
  int v8; // eax
  int m_Mesh; // edx
  int m_Body; // ecx
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v11; // edi
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  int m_MeshVertexIndex; // eax
  int m_VertexIndex; // eax
  float *m_pCurrPosition; // ecx
  float *p_x; // eax
  float *m_pCurrNormal; // ecx
  double z; // st7
  float *v19; // eax
  float *v20; // eax
  int v21; // eax
  CMeshBuilder *meshBuildera; // [esp+Ch] [ebp+Ch]

  m_Head = decalMaterial->m_Vertices.m_Head;
  if ( m_Head != 0xFFFF )
  {
    p_m_VertexCache = &this->m_VertexCache;
    do
    {
      m_pMemory = decalMaterial->m_Vertices.m_Memory.m_pMemory;
      v8 = m_Head;
      m_Mesh = m_pMemory[v8].m_Element.m_Mesh;
      m_Body = m_pMemory[v8].m_Element.m_Body;
      v11 = &m_pMemory[v8];
      meshBuildera = (CMeshBuilder *)(v8 * 48);
      CCachedRenderData::SetBodyModelMesh(
        this: p_m_VertexCache,
        body: m_Body,
        model: v11->m_Element.m_Model,
        mesh: m_Mesh);
      m_pFirstFlexIndex = p_m_VertexCache->m_pFirstFlexIndex;
      if ( m_pFirstFlexIndex != nullptr
        && (m_MeshVertexIndex = v11->m_Element.m_MeshVertexIndex,
            m_pFirstFlexIndex[m_MeshVertexIndex].m_Tag == p_m_VertexCache->m_CurrentTag) )
      {
        m_VertexIndex = m_pFirstFlexIndex[m_MeshVertexIndex].m_VertexIndex;
        m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        p_x = &p_m_VertexCache->m_pFlexVerts[m_VertexIndex].m_Position.x;
        *m_pCurrPosition = *p_x;
        m_pCurrPosition[1] = p_x[1];
        m_pCurrPosition[2] = p_x[2];
        m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *m_pCurrNormal = p_x[4];
        m_pCurrNormal[1] = p_x[5];
        z = p_x[6];
      }
      else
      {
        v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *v19 = v11->m_Element.m_Position.x;
        v19[1] = v11->m_Element.m_Position.y;
        v19[2] = v11->m_Element.m_Position.z;
        *m_pCurrNormal = v11->m_Element.m_Normal.x;
        m_pCurrNormal[1] = v11->m_Element.m_Normal.y;
        z = v11->m_Element.m_Normal.z;
      }
      v20 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      m_pCurrNormal[2] = z;
      *v20 = v11->m_Element.m_TexCoord.x;
      v20[1] = v11->m_Element.m_TexCoord.y;
      *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
      v21 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
      if ( v21 > meshBuilder->m_VertexBuilder.m_nVertexCount )
        meshBuilder->m_VertexBuilder.m_nVertexCount = v21;
      meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                           + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
      meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
      meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      m_Head = *(unsigned __int16 *)((char *)&decalMaterial->m_Vertices.m_Memory.m_pMemory->m_Next
                                   + (unsigned int)meshBuildera);
    }
    while ( m_Head != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100048F0
// Name: private: bool CStudioRender::DrawMultiBoneDecals(class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t __near &,struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::DrawMultiBoneDecals(
        CStudioRender *this,
        CMeshBuilder *meshBuilder,
        CStudioRender::DecalMaterial_t *decalMaterial,
        studiohdr_t *pStudioHdr)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // edx
  int v6; // eax
  int m_Body; // edi
  int m_MeshVertexIndex; // ebx
  DecalVertex_t *p_m_Element; // edx
  int m_Mesh; // esi
  char *v11; // ecx
  int v12; // eax
  mstudiomesh_t *v13; // esi
  CCachedRenderData *p_m_VertexCache; // edi
  CCachedRenderData::CacheIndex_t *m_pFirstWorldIndex; // eax
  float *p_x; // ecx
  CMeshBuilder *v17; // eax
  float *m_pCurrPosition; // edx
  float *m_pCurrNormal; // edx
  CachedPosNorm_t *WorldVertex; // edi
  mstudiomodel_t *v21; // ecx
  mstudiomodel_t *v22; // ecx
  const vertexFileHeader_t *v23; // eax
  int vertexDataStart; // ecx
  const mstudio_modelvertexdata_t *modelvertexdata; // esi
  unsigned int v26; // ebx
  mstudioboneweight_t *v27; // ebx
  float *v28; // esi
  const mstudio_modelvertexdata_t *v29; // edx
  int vertexoffset; // esi
  __int64 v31; // rax
  int v32; // esi
  CStudioRender *v33; // ebx
  double x; // st7
  float *v35; // eax
  float *v36; // eax
  int v37; // ecx
  int v39; // [esp-Ch] [ebp-60h]
  matrix3x4_t *m_PoseToWorld; // [esp-8h] [ebp-5Ch]
  mstudioboneweight_t boneWeights; // [esp+Ch] [ebp-48h] BYREF
  Vector normal; // [esp+1Ch] [ebp-38h] BYREF
  Vector position; // [esp+28h] [ebp-2Ch] BYREF
  int v44; // [esp+34h] [ebp-20h]
  DecalVertex_t *vertex; // [esp+38h] [ebp-1Ch]
  const mstudio_modelvertexdata_t *v46; // [esp+3Ch] [ebp-18h]
  int n; // [esp+40h] [ebp-14h]
  mstudiomesh_t *pLastMesh; // [esp+44h] [ebp-10h]
  const thinModelVertices_t *thinVertData; // [esp+48h] [ebp-Ch]
  const mstudio_meshvertexdata_t *vertData; // [esp+4Ch] [ebp-8h]
  CStudioRender *v51; // [esp+50h] [ebp-4h]

  thinVertData = nullptr;
  vertData = nullptr;
  pLastMesh = nullptr;
  m_Head = decalMaterial->m_Vertices.m_Head;
  v51 = this;
  if ( m_Head == 0xFFFF )
    return 1;
  while ( 1 )
  {
    m_pMemory = decalMaterial->m_Vertices.m_Memory.m_pMemory;
    v6 = m_Head;
    m_Body = m_pMemory[v6].m_Element.m_Body;
    m_MeshVertexIndex = m_pMemory[v6].m_Element.m_MeshVertexIndex;
    p_m_Element = &m_pMemory[v6].m_Element;
    v44 = v6 * 48;
    vertex = p_m_Element;
    n = m_MeshVertexIndex;
    if ( (_WORD)m_Body == 0xFFFF || p_m_Element->m_Model == 0xFFFF || (_WORD)(m_Mesh = p_m_Element->m_Mesh) == 0xFFFF )
    {
      v13 = nullptr;
    }
    else
    {
      v11 = (char *)pStudioHdr + 16 * m_Body + pStudioHdr->bodypartindex;
      v12 = *((_DWORD *)v11 + 3) + 148 * p_m_Element->m_Model;
      v13 = (mstudiomesh_t *)&v11[116 * m_Mesh + v12 + *(_DWORD *)&v11[v12 + 76]];
    }
    v39 = m_Body;
    p_m_VertexCache = &v51->m_VertexCache;
    CCachedRenderData::SetBodyModelMesh(
      this: &v51->m_VertexCache,
      body: v39,
      model: p_m_Element->m_Model,
      mesh: p_m_Element->m_Mesh);
    m_pFirstWorldIndex = p_m_VertexCache->m_pFirstWorldIndex;
    if ( m_pFirstWorldIndex == nullptr || m_pFirstWorldIndex[m_MeshVertexIndex].m_Tag != p_m_VertexCache->m_CurrentTag )
      break;
    p_x = &p_m_VertexCache->m_pWorldVerts[m_pFirstWorldIndex[m_MeshVertexIndex].m_VertexIndex].m_Position.x;
    v17 = meshBuilder;
    m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *m_pCurrPosition = *p_x;
    m_pCurrPosition[1] = p_x[1];
    m_pCurrPosition[2] = p_x[2];
    m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
    *m_pCurrNormal = p_x[4];
    m_pCurrNormal[1] = p_x[5];
    m_pCurrNormal[2] = p_x[6];
LABEL_25:
    *(Vector2D *)v17->m_VertexBuilder.m_pCurrTexCoord[0] = vertex->m_TexCoord;
    *(_DWORD *)v17->m_VertexBuilder.m_pCurrColor = -1;
    v37 = ++v17->m_VertexBuilder.m_nCurrentVertex;
    if ( v37 > v17->m_VertexBuilder.m_nVertexCount )
      v17->m_VertexBuilder.m_nVertexCount = v37;
    v17->m_VertexBuilder.m_pCurrPosition = (float *)((char *)v17->m_VertexBuilder.m_pCurrPosition
                                                   + v17->m_VertexBuilder.m_VertexSize_Position);
    v17->m_VertexBuilder.m_pCurrNormal = (float *)((char *)v17->m_VertexBuilder.m_pCurrNormal
                                                 + v17->m_VertexBuilder.m_VertexSize_Normal);
    v17->m_VertexBuilder.m_pCurrColor += v17->m_VertexBuilder.m_VertexSize_Color;
    v17->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)v17->m_VertexBuilder.m_pCurrTexCoord[0]
                                                      + v17->m_VertexBuilder.m_VertexSize_TexCoord[0]);
    m_Head = *(unsigned __int16 *)((char *)&decalMaterial->m_Vertices.m_Memory.m_pMemory->m_Next + v44);
    if ( m_Head == 0xFFFF )
      return 1;
  }
  CCachedRenderData::SetupComputation(this: p_m_VertexCache, pMesh: v13, flexComputation: false);
  WorldVertex = CCachedRenderData::CreateWorldVertex(this: p_m_VertexCache, vertex: m_MeshVertexIndex);
  if ( pLastMesh != v13 )
  {
    v21 = (mstudiomodel_t *)((char *)v13 + v13->modelindex);
    pLastMesh = v13;
    mstudiomodel_t::GetVertexData(this: v21, pModelData: pStudioHdr);
    v22 = (mstudiomodel_t *)((char *)v13 + v13->modelindex);
    v13->vertexdata.modelvertexdata = &v22->vertexdata;
    if ( v22->vertexdata.pVertexData == nullptr )
    {
      vertData = nullptr;
LABEL_13:
      v23 = mstudiomodel_t::CacheVertexData(this: v22, pModelData: pStudioHdr);
      if ( v23 != nullptr && v23->id == 1447248969 && (vertexDataStart = v23->vertexDataStart) != 0 )
        thinVertData = (const thinModelVertices_t *)((char *)v23 + vertexDataStart);
      else
        thinVertData = nullptr;
      goto LABEL_22;
    }
    vertData = &v13->vertexdata;
    if ( v13 == (mstudiomesh_t *)-48 )
      goto LABEL_13;
    thinVertData = nullptr;
  }
  if ( vertData != nullptr )
  {
    modelvertexdata = vertData->modelvertexdata;
    v26 = 3
        * ((int)vertData[-1].modelvertexdata
         + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30
         + m_MeshVertexIndex);
    v46 = vertData[-1].modelvertexdata;
    v27 = (mstudioboneweight_t *)((char *)modelvertexdata->pVertexData + 16 * v26);
    CStudioRender::R_StudioTransform(
      this: v51,
      in1: (Vector *)((char *)modelvertexdata->pVertexData
               + 48 * ((_DWORD)v46 + (unsigned int)modelvertexdata[-3].pVertexData / 0x30 + n)
               + 16),
      pboneweight: v27,
      pPoseToWorld: v51->m_PoseToWorld,
      out1: (Vector *)WorldVertex);
    v28 = &WorldVertex->m_Normal.x;
    m_PoseToWorld = v51->m_PoseToWorld;
    v46 = vertData->modelvertexdata;
    CStudioRender::R_StudioRotate(
      this: v51,
      in1: (Vector *)((char *)v46->pVertexData
               + 48 * ((int)vertData[-1].modelvertexdata + (unsigned int)v46[-3].pVertexData / 0x30 + n)
               + 28),
      pboneweight: v27,
      pPoseToWorld: m_PoseToWorld,
      out1: (Vector *)&WorldVertex->m_Normal);
LABEL_24:
    WorldVertex->m_Position.x = (float)(*v28 * 0.1) + WorldVertex->m_Position.x;
    x = WorldVertex->m_Position.x;
    WorldVertex->m_Position.y = (float)(v28[1] * 0.1) + WorldVertex->m_Position.y;
    WorldVertex->m_Position.z = (float)(v28[2] * 0.1) + WorldVertex->m_Position.z;
    v35 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v35 = x;
    v35[1] = WorldVertex->m_Position.y;
    v35[2] = WorldVertex->m_Position.z;
    v36 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
    *v36 = *v28;
    v36[1] = v28[1];
    v36[2] = v28[2];
    v17 = meshBuilder;
    goto LABEL_25;
  }
LABEL_22:
  if ( thinVertData != nullptr )
  {
    v29 = v13->vertexdata.modelvertexdata;
    vertexoffset = v13->vertexoffset;
    v46 = v29;
    v31 = 2863311531LL * (unsigned int)v29[-3].pVertexData;
    n = vertexoffset;
    v32 = m_MeshVertexIndex + (HIDWORD(v31) >> 5) + vertexoffset;
    thinModelVertices_t::GetBoneWeights(this: thinVertData, vertIndex: v32, pBoneWeights: &boneWeights);
    position = thinVertData->m_vecPositions[v32];
    thinModelVertices_t::GetNormal(
      this: thinVertData,
      vertIndex: m_MeshVertexIndex + n + (unsigned int)v46[-3].pVertexData / 0x30,
      pNormal: &normal);
    v33 = v51;
    CStudioRender::R_StudioTransform(
      this: v51,
      in1: &position,
      pboneweight: &boneWeights,
      pPoseToWorld: v51->m_PoseToWorld,
      out1: (Vector *)WorldVertex);
    v28 = &WorldVertex->m_Normal.x;
    CStudioRender::R_StudioRotate(
      this: v33,
      in1: &normal,
      pboneweight: &boneWeights,
      pPoseToWorld: v33->m_PoseToWorld,
      out1: (Vector *)&WorldVertex->m_Normal);
    goto LABEL_24;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004CE0
// Name: private: bool CStudioRender::DrawMultiBoneFlexedDecals(class IMatRenderContext __near *,class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t __near &,struct studiohdr_t __near *,struct studioloddata_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::DrawMultiBoneFlexedDecals(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        CachedPosNorm_t *meshBuilder,
        CStudioRender::DecalMaterial_t *decalMaterial,
        studiohdr_t *pStudioHdr,
        mstudioboneweight_t *pStudioLOD)
{
  mstudio_meshvertexdata_t *p_vertexdata; // ebx
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi
  DecalVertex_t *v12; // ecx
  char *v13; // eax
  char *v14; // edx
  mstudiomesh_t *v15; // eax
  mstudiomodel_t *v16; // ebx
  const vertexFileHeader_t *v17; // eax
  int vertexDataStart; // ecx
  char *v19; // ecx
  int tangentDataStart; // ecx
  char *v21; // eax
  const mstudio_modelvertexdata_t *v22; // eax
  IMorph *Morph; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstWorldIndex; // eax
  CCachedRenderData *p_m_VertexCache; // ecx
  float *p_x; // eax
  float *v27; // ecx
  float *v28; // ecx
  double v29; // st7
  Vector *WorldVertex; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstThinFlexIndex; // ecx
  CachedPosNorm_t *v32; // ecx
  float *v33; // eax
  float v34; // xmm0_4
  unsigned int v35; // eax
  const mstudio_modelvertexdata_t *v36; // edx
  float *v37; // eax
  int v38; // edx
  float *v39; // edi
  float v40; // xmm0_4
  int v41; // eax
  CCachedRenderData::CacheIndex_t *m_pFirstFlexIndex; // ecx
  int m_VertexIndex; // ecx
  CStudioRender *v44; // edi
  double v45; // st7
  float *v46; // ecx
  unsigned __int8 *v47; // edx
  DecalVertex_t *v48; // ecx
  float *v49; // eax
  const mstudio_modelvertexdata_t *modelvertexdata; // ecx
  float *pVertexData; // edx
  double v52; // st7
  unsigned int v53; // eax
  float *w_low; // edx
  unsigned int v55; // kr04_4
  float *v56; // ecx
  unsigned __int8 *y_low; // edx
  double v58; // st7
  unsigned int v59; // eax
  float *x_low; // ecx
  DecalVertex_t *v61; // ecx
  float *z_low; // eax
  double y; // st7
  const mstudio_modelvertexdata_t *v64; // ecx
  float *v65; // eax
  unsigned int v66; // edx
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  matrix3x4_t *m_PoseToWorld; // [esp-8h] [ebp-4Ch]
  matrix3x4_t *v73; // [esp-8h] [ebp-4Ch]
  Vector vecNormal; // [esp+Ch] [ebp-38h] BYREF
  Vector vecPosition; // [esp+18h] [ebp-2Ch] BYREF
  Vector2D morphUV; // [esp+24h] [ebp-20h] BYREF
  int v77; // [esp+2Ch] [ebp-18h]
  CachedPosNormTan_t *pFlexedVertex; // [esp+30h] [ebp-14h]
  mstudiomesh_t *pLastMesh; // [esp+34h] [ebp-10h]
  int *pBoneRemap; // [esp+38h] [ebp-Ch]
  DecalVertex_t *vertex; // [esp+3Ch] [ebp-8h]
  CStudioRender *v82; // [esp+40h] [ebp-4h]
  mstudiomesh_t *pCachedVert; // [esp+50h] [ebp+Ch]
  CachedPosNorm_t *pCachedVerta; // [esp+50h] [ebp+Ch]
  mstudioboneweight_t *pBoneWeights; // [esp+5Ch] [ebp+18h]

  p_vertexdata = nullptr;
  v82 = this;
  if ( pStudioLOD != nullptr )
    pBoneRemap = (int *)LODWORD(pStudioLOD[1].weight[2]);
  else
    pBoneRemap = nullptr;
  m_Head = decalMaterial->m_Vertices.m_Head;
  pLastMesh = nullptr;
  if ( m_Head == 0xFFFF )
    return 1;
  while ( 1 )
  {
    m_pMemory = decalMaterial->m_Vertices.m_Memory.m_pMemory;
    v10 = 48 * m_Head;
    v11 = *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_MeshVertexIndex + v10);
    v12 = (DecalVertex_t *)((char *)&m_pMemory->m_Element + v10);
    v77 = v10;
    LOWORD(v10) = v12->m_Body;
    vertex = v12;
    if ( (_WORD)v10 == 0xFFFF || v12->m_Model == 0xFFFF || v12->m_Mesh == 0xFFFF )
    {
      pCachedVert = nullptr;
      v15 = nullptr;
    }
    else
    {
      v13 = (char *)pStudioHdr + 16 * v12->m_Body + pStudioHdr->bodypartindex;
      v14 = &v13[148 * v12->m_Model + *((_DWORD *)v13 + 3)];
      v15 = (mstudiomesh_t *)&v14[116 * v12->m_Mesh + *((_DWORD *)v14 + 19)];
      pCachedVert = v15;
    }
    if ( pLastMesh != v15 )
      break;
LABEL_23:
    if ( p_vertexdata == nullptr )
      return 0;
    if ( pBoneRemap != nullptr )
    {
      Morph = DecalVertex_t::GetMorph(this: v12, pHdr: v82->m_pStudioHdr, pStudioMeshes: v82->m_pStudioMeshes);
      if ( Morph != nullptr
        && pRenderContext->GetMorphAccumulatorTexCoord(
             this: pRenderContext,
             a2: &morphUV,
             a3: Morph,
             a4: vertex->m_GroupIndex) )
      {
        modelvertexdata = p_vertexdata->modelvertexdata;
        pVertexData = (float *)p_vertexdata->modelvertexdata->pVertexData;
        v52 = pVertexData[12
                        * ((int)p_vertexdata[-1].modelvertexdata
                         + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                         + v11)
                        + 4];
        v53 = (unsigned int)&pVertexData[12
                                       * ((int)p_vertexdata[-1].modelvertexdata
                                        + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                                        + v11)
                                       + 4];
        w_low = (float *)LODWORD(meshBuilder[13].m_Position.w);
        *w_low = v52;
        w_low[1] = *(float *)(v53 + 4);
        w_low[2] = *(float *)(v53 + 8);
        v55 = (unsigned int)modelvertexdata[-3].pVertexData;
        v56 = (float *)modelvertexdata->pVertexData;
        y_low = (unsigned __int8 *)LODWORD(meshBuilder[13].m_Normal.y);
        v58 = v56[12 * ((int)p_vertexdata[-1].modelvertexdata + v55 / 0x30 + v11) + 7];
        v59 = (unsigned int)&v56[12 * ((int)p_vertexdata[-1].modelvertexdata + v55 / 0x30 + v11) + 7];
        x_low = (float *)LODWORD(meshBuilder[13].m_Normal.x);
        *x_low = v58;
        x_low[1] = *(float *)(v59 + 4);
        x_low[2] = *(float *)(v59 + 8);
        v61 = vertex;
        *(_DWORD *)y_low = -1;
        z_low = (float *)LODWORD(meshBuilder[13].m_Normal.z);
        *z_low = v61->m_TexCoord.x;
        y = v61->m_TexCoord.y;
        v64 = p_vertexdata->modelvertexdata;
        z_low[1] = y;
        v65 = (float *)LODWORD(meshBuilder[14].m_Position.x);
        *(Vector2D *)v65 = morphUV;
        v65[2] = 1.0;
        v66 = (unsigned int)v64->pVertexData
            + 48 * ((int)p_vertexdata[-1].modelvertexdata + (unsigned int)v64[-3].pVertexData / 0x30 + v11);
        if ( SLODWORD(meshBuilder[10].m_Position.y) > 0 )
          *(float *)(LODWORD(meshBuilder[7].m_Normal.z) * LODWORD(meshBuilder[13].m_Position.z)
                   + LODWORD(meshBuilder[10].m_Position.w)) = *(float *)v66;
        if ( SLODWORD(meshBuilder[10].m_Position.y) > 1 )
          *(float *)(LODWORD(meshBuilder[7].m_Normal.z) * LODWORD(meshBuilder[13].m_Position.z)
                   + LODWORD(meshBuilder[10].m_Position.w)
                   + 4) = *(float *)(v66 + 4);
        if ( SLODWORD(meshBuilder[10].m_Position.y) > 2 )
          *(float *)(LODWORD(meshBuilder[7].m_Normal.z) * LODWORD(meshBuilder[13].m_Position.z)
                   + LODWORD(meshBuilder[10].m_Position.w)
                   + 8) = (float)(1.0 - *(float *)(v66 + 4)) - *(float *)v66;
        if ( SLODWORD(meshBuilder[10].m_Position.y) > 3 )
          *(_DWORD *)(LODWORD(meshBuilder[7].m_Normal.z) * LODWORD(meshBuilder[13].m_Position.z)
                    + LODWORD(meshBuilder[10].m_Position.w)
                    + 12) = 0;
        v67 = pBoneRemap[*(unsigned __int8 *)(v66 + 12)];
        if ( v67 == 255 )
          LOBYTE(v67) = 0;
        *(_BYTE *)(LODWORD(meshBuilder[7].m_Normal.w) * LODWORD(meshBuilder[13].m_Position.z)
                 + LODWORD(meshBuilder[10].m_Normal.x)) = v67;
        v68 = pBoneRemap[*(unsigned __int8 *)(v66 + 13)];
        if ( v68 == 255 )
          LOBYTE(v68) = 0;
        *(_BYTE *)(LODWORD(meshBuilder[7].m_Normal.w) * LODWORD(meshBuilder[13].m_Position.z)
                 + LODWORD(meshBuilder[10].m_Normal.x)
                 + 1) = v68;
        v69 = pBoneRemap[*(unsigned __int8 *)(v66 + 14)];
        if ( v69 == 255 )
          LOBYTE(v69) = 0;
        *(_BYTE *)(LODWORD(meshBuilder[7].m_Normal.w) * LODWORD(meshBuilder[13].m_Position.z)
                 + LODWORD(meshBuilder[10].m_Normal.x)
                 + 2) = v69;
        *(_BYTE *)(LODWORD(meshBuilder[7].m_Normal.w) * LODWORD(meshBuilder[13].m_Position.z)
                 + LODWORD(meshBuilder[10].m_Normal.x)
                 + 3) = 0;
        goto LABEL_56;
      }
      v12 = vertex;
    }
    pBoneWeights = (mstudioboneweight_t *)((char *)p_vertexdata->modelvertexdata->pVertexData
                                         + 48
                                         * ((int)p_vertexdata[-1].modelvertexdata
                                          + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                                          + v11));
    CCachedRenderData::SetBodyModelMesh(
      this: &v82->m_VertexCache,
      body: v12->m_Body,
      model: v12->m_Model,
      mesh: v12->m_Mesh);
    m_pFirstWorldIndex = v82->m_VertexCache.m_pFirstWorldIndex;
    p_m_VertexCache = &v82->m_VertexCache;
    if ( m_pFirstWorldIndex != nullptr && m_pFirstWorldIndex[v11].m_Tag == v82->m_VertexCache.m_CurrentTag )
    {
      p_x = &p_m_VertexCache->m_pWorldVerts[m_pFirstWorldIndex[v11].m_VertexIndex].m_Position.x;
      v27 = (float *)LODWORD(meshBuilder[13].m_Position.w);
      *v27 = *p_x;
      v27[1] = p_x[1];
      v27[2] = p_x[2];
      v28 = (float *)LODWORD(meshBuilder[13].m_Normal.x);
      *v28 = p_x[4];
      v28[1] = p_x[5];
      v29 = p_x[6];
    }
    else
    {
      CCachedRenderData::SetupComputation(this: p_m_VertexCache, pMesh: pCachedVert, flexComputation: false);
      WorldVertex = (Vector *)CCachedRenderData::CreateWorldVertex(this: &v82->m_VertexCache, vertex: v11);
      m_pFirstThinFlexIndex = v82->m_VertexCache.m_pFirstThinFlexIndex;
      pCachedVerta = (CachedPosNorm_t *)WorldVertex;
      if ( m_pFirstThinFlexIndex != nullptr && m_pFirstThinFlexIndex[v11].m_Tag == v82->m_VertexCache.m_CurrentTag )
      {
        v32 = &v82->m_VertexCache.m_pThinFlexVerts[v82->m_VertexCache.m_pFirstThinFlexIndex[v11].m_VertexIndex];
        v33 = (float *)p_vertexdata->modelvertexdata->pVertexData;
        v34 = v33[12
                * ((int)p_vertexdata[-1].modelvertexdata
                 + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                 + v11)
                + 4]
            + v32->m_Position.x;
        v35 = (unsigned int)&v33[12
                               * ((int)p_vertexdata[-1].modelvertexdata
                                + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                                + v11)
                               + 4];
        v36 = p_vertexdata->modelvertexdata;
        vecPosition.x = v34;
        vecPosition.y = *(float *)(v35 + 4) + v32->m_Position.y;
        vecPosition.z = *(float *)(v35 + 8) + v32->m_Position.z;
        v37 = (float *)p_vertexdata->modelvertexdata->pVertexData;
        v38 = (int)p_vertexdata[-1].modelvertexdata + (unsigned int)v36[-3].pVertexData / 0x30 + v11;
        v39 = &pCachedVerta->m_Position.x;
        v38 *= 6;
        v40 = v32->m_Normal.x + v37[2 * v38 + 7];
        v41 = (int)&v37[2 * v38 + 7];
        vecNormal.x = v40;
        vecNormal.y = *(float *)(v41 + 4) + v32->m_Normal.y;
        m_PoseToWorld = v82->m_PoseToWorld;
        vecNormal.z = *(float *)(v41 + 8) + v32->m_Normal.z;
        CStudioRender::R_StudioTransform(
          this: v82,
          in1: &vecPosition,
          pboneweight: pBoneWeights,
          pPoseToWorld: m_PoseToWorld,
          out1: (Vector *)pCachedVerta);
        CStudioRender::R_StudioRotate(
          this: v82,
          in1: &vecNormal,
          pboneweight: pBoneWeights,
          pPoseToWorld: v82->m_PoseToWorld,
          out1: (Vector *)&pCachedVerta->m_Normal);
        VectorNormalize(vec: (Vector *)&pCachedVerta->m_Normal);
      }
      else
      {
        m_pFirstFlexIndex = v82->m_VertexCache.m_pFirstFlexIndex;
        if ( m_pFirstFlexIndex != nullptr && m_pFirstFlexIndex[v11].m_Tag == v82->m_VertexCache.m_CurrentTag )
        {
          m_VertexIndex = v82->m_VertexCache.m_pFirstFlexIndex[v11].m_VertexIndex;
          v44 = v82;
          v73 = v82->m_PoseToWorld;
          pFlexedVertex = &v82->m_VertexCache.m_pFlexVerts[m_VertexIndex];
          CStudioRender::R_StudioTransform(
            this: v82,
            in1: (Vector *)pFlexedVertex,
            pboneweight: pBoneWeights,
            pPoseToWorld: v73,
            out1: WorldVertex);
          CStudioRender::R_StudioRotate(
            this: v44,
            in1: (Vector *)&pFlexedVertex->m_Normal,
            pboneweight: pBoneWeights,
            pPoseToWorld: v44->m_PoseToWorld,
            out1: (Vector *)&pCachedVerta->m_Normal);
        }
        else
        {
          CStudioRender::R_StudioTransform(
            this: v82,
            in1: (Vector *)((char *)p_vertexdata->modelvertexdata->pVertexData
                     + 48
                     * ((int)p_vertexdata[-1].modelvertexdata
                      + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                      + v11)
                     + 16),
            pboneweight: pBoneWeights,
            pPoseToWorld: v82->m_PoseToWorld,
            out1: WorldVertex);
          CStudioRender::R_StudioRotate(
            this: v82,
            in1: (Vector *)((char *)p_vertexdata->modelvertexdata->pVertexData
                     + 48
                     * ((int)p_vertexdata[-1].modelvertexdata
                      + (unsigned int)p_vertexdata->modelvertexdata[-3].pVertexData / 0x30
                      + v11)
                     + 28),
            pboneweight: pBoneWeights,
            pPoseToWorld: v82->m_PoseToWorld,
            out1: (Vector *)&pCachedVerta->m_Normal);
        }
        v39 = &pCachedVerta->m_Position.x;
      }
      *v39 = (float)(v39[4] * 0.1) + *v39;
      v45 = *v39;
      v39[1] = (float)(v39[5] * 0.1) + v39[1];
      v39[2] = (float)(v39[6] * 0.1) + v39[2];
      v46 = (float *)LODWORD(meshBuilder[13].m_Position.w);
      *v46 = v45;
      v46[1] = v39[1];
      v46[2] = v39[2];
      v28 = (float *)LODWORD(meshBuilder[13].m_Normal.x);
      *v28 = v39[4];
      v28[1] = v39[5];
      v29 = v39[6];
    }
    v47 = (unsigned __int8 *)LODWORD(meshBuilder[13].m_Normal.y);
    v28[2] = v29;
    v48 = vertex;
    *(_DWORD *)v47 = -1;
    *(Vector2D *)LODWORD(meshBuilder[13].m_Normal.z) = v48->m_TexCoord;
    v49 = (float *)LODWORD(meshBuilder[14].m_Position.x);
    *v49 = 0.0;
    v49[1] = 0.0;
    v49[2] = 0.0;
LABEL_56:
    v70 = ++LODWORD(meshBuilder[13].m_Position.z);
    if ( v70 > SLODWORD(meshBuilder[13].m_Position.y) )
      LODWORD(meshBuilder[13].m_Position.y) = v70;
    LODWORD(meshBuilder[13].m_Position.w) += LODWORD(meshBuilder[7].m_Normal.y);
    LODWORD(meshBuilder[13].m_Normal.x) += LODWORD(meshBuilder[8].m_Position.x);
    LODWORD(meshBuilder[13].m_Normal.y) += LODWORD(meshBuilder[8].m_Position.y);
    LODWORD(meshBuilder[13].m_Normal.z) += LODWORD(meshBuilder[8].m_Position.w);
    LODWORD(meshBuilder[13].m_Normal.w) += LODWORD(meshBuilder[8].m_Normal.x);
    LODWORD(meshBuilder[14].m_Position.x) += LODWORD(meshBuilder[8].m_Normal.y);
    m_Head = *(unsigned __int16 *)((char *)&decalMaterial->m_Vertices.m_Memory.m_pMemory->m_Next + v77);
    if ( m_Head == 0xFFFF )
      return 1;
  }
  v16 = (mstudiomodel_t *)((char *)v15 + v15->modelindex);
  pLastMesh = v15;
  v17 = mstudiomodel_t::CacheVertexData(this: v16, pModelData: pStudioHdr);
  if ( v17 != nullptr )
  {
    if ( v17->id == 1448297545 && (vertexDataStart = v17->vertexDataStart) != 0 )
      v19 = (char *)v17 + vertexDataStart;
    else
      v19 = nullptr;
    v16->vertexdata.pVertexData = v19;
    if ( v17->id == 1448297545 && (tangentDataStart = v17->tangentDataStart) != 0 )
      v21 = (char *)v17 + tangentDataStart;
    else
      v21 = nullptr;
    v16->vertexdata.pTangentData = v21;
  }
  v22 = (const mstudio_modelvertexdata_t *)((char *)&pCachedVert->unused[6] + pCachedVert->modelindex);
  p_vertexdata = &pCachedVert->vertexdata;
  pCachedVert->vertexdata.modelvertexdata = v22;
  if ( v22->pVertexData != nullptr )
  {
    v12 = vertex;
    goto LABEL_23;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005430
// Name: private: void CStudioRender::BuildDecalIndices(class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::BuildDecalIndices(
        CStudioRender *this,
        CMeshBuilder *meshBuilder,
        const CStudioRender::DecalMaterial_t *decalMaterial)
{
  int m_Next; // ecx
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v5; // eax
  int v6; // esi
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *m_pMemory; // esi
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v8; // esi
  int indexCount; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int nVertexCount; // [esp+10h] [ebp-8h]
  int indicesRemaining; // [esp+14h] [ebp-4h]
  __int16 vertexOffset; // [esp+24h] [ebp+Ch]

  LOWORD(m_Next) = decalMaterial->m_Decals.m_Head;
  v5 = &decalMaterial->m_Decals.m_Memory.m_pMemory[(unsigned __int16)m_Next];
  indicesRemaining = v5->m_Element.m_IndexCount;
  v6 = 0;
  indexCount = decalMaterial->m_Indices.m_Size;
  nVertexCount = v5->m_Element.m_VertexCount;
  vertexOffset = 0;
  i = 0;
  if ( indexCount > 0 )
  {
    do
    {
      meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = vertexOffset
                                                                                          + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                          + decalMaterial->m_Indices.m_Memory.m_pMemory[v6];
      meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
      meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
      if ( --indicesRemaining <= 0 )
      {
        vertexOffset += nVertexCount;
        m_pMemory = decalMaterial->m_Decals.m_Memory.m_pMemory;
        m_Next = m_pMemory[(unsigned __int16)m_Next].m_Next;
        if ( (_WORD)m_Next != 0xFFFF )
        {
          v8 = &m_pMemory[m_Next];
          indicesRemaining = v8->m_Element.m_IndexCount;
          nVertexCount = v8->m_Element.m_VertexCount;
        }
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < indexCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005500
// Name: private: void CStudioRender::DrawInstancedMultiBoneDecals(class CMeshBuilder __near &,struct CStudioRender::DecalMaterial_t const __near &,struct studiohdr_t __near *,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawInstancedMultiBoneDecals(
        CStudioRender *this@<ecx>,
        int a2@<ebp>,
        CMeshBuilder *meshBuilder,
        const CStudioRender::DecalMaterial_t *decalMaterial,
        studiohdr_t *pStudioHdr,
        matrix3x4_t *pPoseToWorld)
{
  void *v6; // esp
  unsigned __int16 m_Head; // ax
  int v8; // edx
  int v9; // edi
  int v10; // edx
  int v11; // eax
  char *v12; // eax
  char *v13; // ecx
  char *v14; // eax
  mstudiomodel_t *v15; // ecx
  const vertexFileHeader_t *v16; // eax
  int vertexDataStart; // ecx
  char *v18; // ecx
  mstudiomodel_t *v19; // edx
  int tangentDataStart; // ecx
  char *v21; // eax
  mstudiomodel_t *v22; // ecx
  mstudiomodel_t *v23; // edx
  bool v24; // zf
  const vertexFileHeader_t *v25; // eax
  int v26; // ecx
  thinModelVertices_t *v27; // eax
  _DWORD *v28; // ecx
  unsigned int v29; // edx
  float *v30; // eax
  unsigned int v31; // kr00_4
  float *v32; // eax
  double v33; // st7
  mstudioboneweight_t *v34; // eax
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v35; // ecx
  int v36; // edx
  int v37; // eax
  Vector *v38; // ecx
  int v39; // eax
  __m128 *v40; // ecx
  int v41; // eax
  int i; // edi
  __m128 v43; // xmm3
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm6
  __m128 v50; // xmm2
  __m128 v51; // xmm7
  __m128 v52; // xmm4
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  int v57; // edi
  int v58; // eax
  float *v59; // ecx
  float *m_pCurrPosition; // edi
  float *m_pCurrNormal; // edi
  double v62; // st7
  float *v63; // edi
  int v64; // edi
  double v65; // st7
  float *v66; // edi
  float *v67; // edi
  double v68; // st7
  float *v69; // edi
  int v70; // edi
  double v71; // st7
  float *v72; // edi
  float *v73; // edi
  double v74; // st7
  float *v75; // edi
  int v76; // edi
  double v77; // st7
  float *v78; // edi
  float *v79; // edi
  double v80; // st7
  float *v81; // edi
  int v82; // edi
  int v83; // eax
  float *v84; // ecx
  float *v85; // ecx
  double v86; // st7
  int v87; // edi
  float *v88; // ecx
  int v89; // ecx
  matrix3x4_t *v90; // [esp-1E74h] [ebp-1E80h]
  int v91; // [esp-1E60h] [ebp-1E6Ch] BYREF
  _BYTE v92[5100]; // [esp-1E40h] [ebp-1E4Ch] BYREF
  _BYTE v93[2548]; // [esp-A54h] [ebp-A60h] BYREF
  __m128 v94; // [esp-60h] [ebp-6Ch]
  mstudioboneweight_t v95[2]; // [esp-50h] [ebp-5Ch] BYREF
  char *v96; // [esp-24h] [ebp-30h]
  thinModelVertices_t *v97; // [esp-20h] [ebp-2Ch]
  mstudiomodel_t *v98; // [esp-1Ch] [ebp-28h]
  matrix3x4_t *v99; // [esp-18h] [ebp-24h]
  int v100; // [esp-14h] [ebp-20h]
  int v101; // [esp-10h] [ebp-1Ch]
  _DWORD *pTangentData; // [esp-Ch] [ebp-18h]
  int v103; // [esp-8h] [ebp-14h]
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *m_pMemory; // [esp-4h] [ebp-10h]
  int v105; // [esp+0h] [ebp-Ch]
  void *v106; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v105 = a2;
  v106 = retaddr;
  v6 = alloca(7784);
  v97 = nullptr;
  v98 = nullptr;
  v96 = nullptr;
  m_Head = decalMaterial->m_Vertices.m_Head;
  v101 = m_Head;
  do
  {
    v8 = 0;
    v100 = 0;
    if ( m_Head == 0xFFFF )
      return;
    v99 = (matrix3x4_t *)&v91;
    v9 = 0;
    while ( v9 != 1024 )
    {
      v10 = 48 * (unsigned __int16)v101;
      m_pMemory = decalMaterial->m_Vertices.m_Memory.m_pMemory;
      v11 = *(unsigned __int16 *)((char *)&m_pMemory->m_Next + v10);
      v101 = v10;
      if ( (_WORD)v11 != 0xFFFF )
        _mm_prefetch((const char *)&m_pMemory[v11], 1);
      v103 = *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_MeshVertexIndex + v10);
      if ( *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Body + v10) == 0xFFFF
        || *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Model + v10) == 0xFFFF
        || *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Mesh + v10) == 0xFFFF )
      {
        pTangentData = nullptr;
        v14 = nullptr;
      }
      else
      {
        v12 = (char *)pStudioHdr
            + 16 * *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Body + v10)
            + pStudioHdr->bodypartindex;
        v13 = &v12[148 * *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Model + v10) + *((_DWORD *)v12 + 3)];
        v14 = &v13[116 * *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Mesh + v10) + *((_DWORD *)v13 + 19)];
        pTangentData = v14;
      }
      if ( v96 != v14 )
      {
        v15 = (mstudiomodel_t *)&v14[*((_DWORD *)v14 + 1)];
        v96 = v14;
        v98 = v15;
        v16 = mstudiomodel_t::CacheVertexData(this: v15, pModelData: pStudioHdr);
        if ( v16 != nullptr )
        {
          if ( v16->id == 1448297545 && (vertexDataStart = v16->vertexDataStart) != 0 )
            v18 = (char *)v16 + vertexDataStart;
          else
            v18 = nullptr;
          v19 = v98;
          v98->vertexdata.pVertexData = v18;
          if ( v16->id == 1448297545 && (tangentDataStart = v16->tangentDataStart) != 0 )
            v21 = (char *)v16 + tangentDataStart;
          else
            v21 = nullptr;
          v19->vertexdata.pTangentData = v21;
        }
        v22 = (mstudiomodel_t *)((char *)pTangentData + pTangentData[1]);
        v23 = (mstudiomodel_t *)(pTangentData + 12);
        v24 = v22->vertexdata.pVertexData == nullptr;
        pTangentData[12] = &v22->vertexdata;
        if ( v24 )
        {
          v98 = nullptr;
LABEL_26:
          v25 = mstudiomodel_t::CacheVertexData(this: v22, pModelData: pStudioHdr);
          if ( v25 != nullptr && v25->id == 1447248969 && (v26 = v25->vertexDataStart) != 0 )
            v27 = (thinModelVertices_t *)((char *)v25 + v26);
          else
            v27 = nullptr;
          v97 = v27;
        }
        else
        {
          v98 = v23;
          if ( v23 == nullptr )
            goto LABEL_26;
        }
        v14 = (char *)pTangentData;
        v10 = v101;
      }
      *(float *)&v92[8 * v100 + 5088] = *(float *)((char *)&m_pMemory->m_Element.m_TexCoord.x + v10);
      *(float *)&v92[8 * v100 + 5092] = *(float *)((char *)&m_pMemory->m_Element.m_TexCoord.y + v10);
      if ( v98 != nullptr )
      {
        v28 = *(_DWORD **)v98->name;
        pTangentData = v98[-1].vertexdata.pTangentData;
        v29 = (unsigned int)pTangentData + *(v28 - 6) / 0x30u + v103;
        *(_DWORD *)&v92[v9 + 4076] = 0;
        *(_DWORD *)&v92[v9 + 3052] = 0;
        m_pMemory = (UtlLinkedListElem_t<DecalVertex_t,unsigned short> *)(*v28 + 48 * v29);
        v30 = (float *)(*v28 + 48 * ((_DWORD)pTangentData + *(v28 - 6) / 0x30u + v103) + 16);
        *(float *)&v92[v9 + 4064] = *v30;
        *(float *)&v92[v9 + 4068] = v30[1];
        v31 = *(v28 - 6);
        *(float *)&v92[v9 + 4072] = v30[2];
        v90 = v99;
        v32 = (float *)(*v28 + 48 * ((_DWORD)pTangentData + v31 / 0x30 + v103) + 28);
        *(float *)&v92[v9 + 3040] = *v32;
        *(float *)&v92[v9 + 3044] = v32[1];
        v33 = v32[2];
        v34 = (mstudioboneweight_t *)m_pMemory;
        *(float *)&v92[v9 + 3048] = v33;
        ComputeSkinMatrixToMemorySSE(boneweights: v34, pPoseToWorld, result: v90);
LABEL_37:
        v10 = v101;
        goto LABEL_38;
      }
      if ( v97 != nullptr )
      {
        v35 = *((UtlLinkedListElem_t<DecalVertex_t,unsigned short> **)v14 + 3);
        pTangentData = *((_DWORD **)v14 + 12);
        v36 = (int)v35 + *(pTangentData - 6) / 0x30u + v103;
        m_pMemory = v35;
        thinModelVertices_t::GetBoneWeights(this: v97, vertIndex: v36, pBoneWeights: v95);
        v37 = (int)m_pMemory + *(pTangentData - 6) / 0x30u + v103;
        v38 = &v97->m_vecPositions[v37];
        *(float *)&v92[v9 + 4064] = v38->x;
        *(float *)&v92[v9 + 4068] = v38->y;
        *(float *)&v92[v9 + 4072] = v38->z;
        thinModelVertices_t::GetNormal(this: v97, vertIndex: v37, pNormal: (Vector *)&v92[v9 + 3040]);
        ComputeSkinMatrixToMemorySSE(boneweights: v95, pPoseToWorld, result: v99);
        goto LABEL_37;
      }
LABEL_38:
      v39 = *(unsigned __int16 *)((char *)&decalMaterial->m_Vertices.m_Memory.m_pMemory->m_Next + v10);
      ++v100;
      ++v99;
      v9 += 16;
      v8 = v100;
      v101 = v39;
      if ( (_WORD)v39 == 0xFFFF )
        break;
    }
    if ( v8 == 0 )
      break;
    if ( v8 > 0 )
    {
      v94 = _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0);
      v40 = (__m128 *)v92;
      v41 = 0;
      for ( i = v8; i != 0; --i )
      {
        v43 = v40[-1];
        v44 = v40[-2];
        v45 = _mm_shuffle_ps(v44, v43, 238);
        v46 = _mm_shuffle_ps(v44, v43, 68);
        v47 = v45;
        v48 = _mm_shuffle_ps(*v40, Four_Origin, 68);
        v49 = _mm_shuffle_ps(*v40, Four_Origin, 238);
        v50 = *(__m128 *)&v92[v41 + 3040];
        v51 = _mm_shuffle_ps(v46, v48, 221);
        v52 = _mm_shuffle_ps(v46, v48, 136);
        v53 = *(__m128 *)&v92[v41 + 4064];
        v95[1] = (mstudioboneweight_t)v51;
        v54 = _mm_shuffle_ps(v47, v49, 136);
        v55 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v51), _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v52)),
                _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v54));
        v56 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v53, v53, 170), v54),
                    _mm_mul_ps(_mm_shuffle_ps(v53, v53, 85), v51)),
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v52), _mm_shuffle_ps(v47, v49, 221))),
                _mm_mul_ps(v94, v55));
        *(__m128 *)&v93[v41 + 500] = v55;
        *(__m128 *)&v93[v41 + 1524] = v56;
        v40 += 3;
        v41 += 16;
      }
    }
    v57 = 0;
    v103 = 0;
    if ( v8 >= 4 )
    {
      v99 = (matrix3x4_t *)(((unsigned int)(v8 - 4) >> 2) + 1);
      v58 = 0;
      v59 = (float *)v93;
      v103 = 4 * (_DWORD)v99;
      do
      {
        m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *m_pCurrPosition = *(float *)&v93[v58 + 1524];
        m_pCurrPosition[1] = *(float *)&v93[v58 + 1528];
        m_pCurrPosition[2] = *(float *)&v93[v58 + 1532];
        m_pCurrNormal = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *m_pCurrNormal = *(float *)&v93[v58 + 500];
        m_pCurrNormal[1] = *(float *)&v93[v58 + 504];
        m_pCurrNormal[2] = *(float *)&v93[v58 + 508];
        v62 = *(v59 - 3);
        *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
        v63 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v63 = v62;
        v63[1] = *(v59 - 2);
        v64 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v64 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v64;
        v65 = *(float *)&v93[v58 + 1540];
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v66 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *v66 = v65;
        v66[1] = *(float *)&v93[v58 + 1544];
        v66[2] = *(float *)&v93[v58 + 1548];
        v67 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *v67 = *(float *)&v93[v58 + 516];
        v67[1] = *(float *)&v93[v58 + 520];
        v67[2] = *(float *)&v93[v58 + 524];
        v68 = *(v59 - 1);
        *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
        v69 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v69 = v68;
        v69[1] = *v59;
        v70 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v70 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v70;
        v71 = *(float *)&v93[v58 + 1556];
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v72 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *v72 = v71;
        v72[1] = *(float *)&v93[v58 + 1560];
        v72[2] = *(float *)&v93[v58 + 1564];
        v73 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *v73 = *(float *)&v93[v58 + 532];
        v73[1] = *(float *)&v93[v58 + 536];
        v73[2] = *(float *)&v93[v58 + 540];
        v74 = v59[1];
        *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
        v75 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v75 = v74;
        v75[1] = v59[2];
        v76 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v76 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v76;
        v77 = *(float *)&v93[v58 + 1572];
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v78 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *v78 = v77;
        v78[1] = *(float *)&v93[v58 + 1576];
        v78[2] = *(float *)&v93[v58 + 1580];
        v79 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *v79 = *(float *)&v93[v58 + 548];
        v79[1] = *(float *)&v93[v58 + 552];
        v79[2] = *(float *)&v93[v58 + 556];
        v80 = v59[3];
        *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
        v81 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v81 = v80;
        v81[1] = v59[4];
        v82 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v82 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v82;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v58 += 64;
        v59 += 8;
        v99 = (matrix3x4_t *)((char *)v99 - 1);
      }
      while ( v99 != nullptr );
      v57 = v103;
    }
    if ( v57 < v100 )
    {
      v83 = 16 * v57;
      while ( 1 )
      {
        v84 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *v84 = *(float *)&v93[v83 + 1524];
        v84[1] = *(float *)&v93[v83 + 1528];
        v84[2] = *(float *)&v93[v83 + 1532];
        v85 = meshBuilder->m_VertexBuilder.m_pCurrNormal;
        *v85 = *(float *)&v93[v83 + 500];
        v85[1] = *(float *)&v93[v83 + 504];
        v85[2] = *(float *)&v93[v83 + 508];
        v86 = *(float *)&v92[8 * v57 + 5088];
        v87 = v103;
        *(_DWORD *)meshBuilder->m_VertexBuilder.m_pCurrColor = -1;
        v88 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v88 = v86;
        v88[1] = *(float *)&v92[8 * v87 + 5092];
        v89 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v89 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v89;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrNormal
                                                             + meshBuilder->m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder->m_VertexBuilder.m_pCurrColor += meshBuilder->m_VertexBuilder.m_VertexSize_Color;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v83 += 16;
        v103 = v87 + 1;
        if ( v87 + 1 >= v100 )
          break;
        v57 = v103;
      }
    }
    m_Head = v101;
  }
  while ( (_WORD)v101 != 0xFFFF );
}

//------------------------------------------------------------------------------
// Address: 0x10005D70
// Name: private: void CStudioRender::DrawModelArrayDecals(class IMatRenderContext __near *,struct studiohdr_t __near *,int,struct CStudioRender::DecalRenderData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DrawModelArrayDecals(
        CStudioRender *this,
        IMatRenderContext *pRenderContext,
        studiohdr_t *pStudioHdr,
        studiohdr_t *nCount,
        StudioArrayInstanceData_t *pRenderData,
        int nFlashlightMask)
{
  void (__thiscall *SetNumBoneWeights)(IMatRenderContext *, int); // edx
  bool *v9; // ebx
  const CStudioRender::DecalMaterial_t *v10; // esi
  const MaterialLightingState_t *m_pLightingState; // eax
  IMesh *v12; // ebx
  int v13; // eax
  bool v14; // zf
  bool *p_m_pPoseToWorld; // ebx
  const CStudioRender::DecalMaterial_t *v17; // esi
  const MaterialLightingState_t *m_pDecalLightingState; // eax
  int m_Size; // edx
  IMesh *v20; // ebx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F4h] BYREF
  int m_ElementCount; // [esp+1F4h] [ebp-Ch]
  int nIndexCount; // [esp+1F8h] [ebp-8h]
  CStudioRender *v25; // [esp+1FCh] [ebp-4h]
  int savedregs; // [esp+200h] [ebp+0h] BYREF
  int nVertexCounta; // [esp+208h] [ebp+8h]
  int nVertexCount; // [esp+208h] [ebp+8h]
  studiohdr_t *pStudioHdra; // [esp+20Ch] [ebp+Ch]
  bool *nCounta; // [esp+210h] [ebp+10h]
  bool *nCountb; // [esp+210h] [ebp+10h]
  StudioArrayInstanceData_t *pCurrInstance; // [esp+214h] [ebp+14h]
  StudioArrayInstanceData_t *pCurrInstanceb; // [esp+214h] [ebp+14h]
  StudioArrayInstanceData_t *pCurrInstancea; // [esp+214h] [ebp+14h]

  SetNumBoneWeights = pRenderContext->SetNumBoneWeights;
  v25 = this;
  SetNumBoneWeights(this: pRenderContext, a2: 0);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  if ( pStudioHdr->numbones > 1 )
  {
    pRenderContext->LoadIdentity(this: pRenderContext);
    if ( (int)nCount > 0 )
    {
      p_m_pPoseToWorld = (bool *)&pRenderData->m_pPoseToWorld;
      nCountb = (bool *)&pRenderData->m_pPoseToWorld;
      nVertexCount = (int)nCount;
      do
      {
        v17 = *((const CStudioRender::DecalMaterial_t **)p_m_pPoseToWorld - 3);
        pCurrInstancea = *((StudioArrayInstanceData_t **)p_m_pPoseToWorld - 2);
        if ( nFlashlightMask == 0
          || *p_m_pPoseToWorld && (nFlashlightMask & *(_DWORD *)(*((_DWORD *)p_m_pPoseToWorld - 2) + 40)) != 0 )
        {
          pRenderContext->Bind(this: pRenderContext, a2: *((IMaterial **)p_m_pPoseToWorld - 1), a3: nullptr);
          if ( *p_m_pPoseToWorld )
          {
            m_pDecalLightingState = pCurrInstancea->m_pDecalLightingState;
            if ( m_pDecalLightingState != nullptr
              || (m_pDecalLightingState = pCurrInstancea->m_pLightingState) != nullptr )
            {
              pRenderContext->SetLightingState(this: pRenderContext, a2: m_pDecalLightingState);
            }
          }
          m_Size = v17->m_Indices.m_Size;
          m_ElementCount = v17->m_Vertices.m_ElementCount;
          nIndexCount = m_Size;
          CMeshBuilder::CMeshBuilder(this: &meshBuilder);
          v20 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: v20,
            type: MATERIAL_TRIANGLES,
            nVertexCount: m_ElementCount,
            nIndexCount,
            pMeshSettings: nullptr);
          CStudioRender::DrawInstancedMultiBoneDecals(
            this: v25,
            a2: (int)&savedregs,
            &meshBuilder,
            decalMaterial: v17,
            pStudioHdr,
            pPoseToWorld: pCurrInstancea->m_pPoseToWorld);
          CStudioRender::BuildDecalIndices(this: v25, &meshBuilder, decalMaterial: v17);
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
          v20->Draw_2(this: v20, a2: -1, a3: 0);
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
          p_m_pPoseToWorld = nCountb;
        }
        p_m_pPoseToWorld += 16;
        v14 = nVertexCount-- == 1;
        nCountb = p_m_pPoseToWorld;
      }
      while ( !v14 );
    }
  }
  else if ( (int)nCount > 0 )
  {
    v9 = (bool *)&pRenderData->m_pPoseToWorld;
    nCounta = (bool *)&pRenderData->m_pPoseToWorld;
    pStudioHdra = nCount;
    do
    {
      v10 = *((const CStudioRender::DecalMaterial_t **)v9 - 3);
      pCurrInstance = *((StudioArrayInstanceData_t **)v9 - 2);
      if ( nFlashlightMask == 0 || *v9 && (nFlashlightMask & *(_DWORD *)(*((_DWORD *)v9 - 2) + 40)) != 0 )
      {
        pRenderContext->Bind(this: pRenderContext, a2: *((IMaterial **)v9 - 1), a3: nullptr);
        pRenderContext->LoadMatrix(this: pRenderContext, a2: pCurrInstance->m_pPoseToWorld);
        if ( *v9 )
        {
          m_pLightingState = pCurrInstance->m_pDecalLightingState;
          if ( m_pLightingState != nullptr || (m_pLightingState = pCurrInstance->m_pLightingState) != nullptr )
            pRenderContext->SetLightingState(this: pRenderContext, a2: m_pLightingState);
        }
        nVertexCounta = v10->m_Vertices.m_ElementCount;
        pCurrInstanceb = (StudioArrayInstanceData_t *)v10->m_Indices.m_Size;
        CMeshBuilder::CMeshBuilder(this: &meshBuilder);
        v12 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v12,
          type: MATERIAL_TRIANGLES,
          nVertexCount: nVertexCounta,
          nIndexCount: (int)pCurrInstanceb,
          pMeshSettings: nullptr);
        CStudioRender::DrawSingleBoneDecals(this: v25, &meshBuilder, decalMaterial: v10);
        CStudioRender::BuildDecalIndices(this: v25, &meshBuilder, decalMaterial: v10);
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v13 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v13 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v13 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v13 = 0;
              break;
            default:
              v13 = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v13);
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
        v12->Draw_2(this: v12, a2: -1, a3: 0);
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
        v9 = nCounta;
      }
      v9 += 16;
      v14 = pStudioHdra == (studiohdr_t *)1;
      pStudioHdra = (studiohdr_t *)((char *)pStudioHdra - 1);
      nCounta = v9;
    }
    while ( !v14 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100061B0
// Name: private: void CStudioRender::DrawDecalMaterial(class IMatRenderContext __near *,struct CStudioRender::DecalMaterial_t __near &,struct studiohdr_t __near *,struct studioloddata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawDecalMaterial(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        CStudioRender::DecalMaterial_t *decalMaterial,
        studiohdr_t *pStudioHdr,
        studioloddata_t *pStudioLOD)
{
  void (__thiscall *BindMorph)(IMatRenderContext *, IMorph *); // eax
  IMesh *v10; // eax
  int m_ElementCount; // ebx
  studiohdr_t *m_pStudioHdr; // eax
  char v13; // bl
  char v14; // al
  int m_nVertexCount; // eax
  IMesh_vtbl *v16; // edx
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  int indexCount; // [esp+1F0h] [ebp-8h]
  IMesh *pMesh; // [esp+1F4h] [ebp-4h]
  char bUseHWMorphing_3; // [esp+203h] [ebp+Bh]

  indexCount = decalMaterial->m_Indices.m_Size;
  if ( indexCount == 0 )
    return;
  if ( (*((_BYTE *)&this->m_pRC->m_Config + 56) & 4) != 0 )
  {
    if ( pStudioLOD != nullptr && pStudioLOD->m_pHWMorphDecalBoneRemap != nullptr )
    {
      BindMorph = pRenderContext->BindMorph;
      bUseHWMorphing_3 = 1;
      BindMorph(this: pRenderContext, a2: (IMorph *)1);
      goto LABEL_8;
    }
  }
  else
  {
    pStudioLOD = nullptr;
  }
  bUseHWMorphing_3 = 0;
LABEL_8:
  if ( (*((_BYTE *)&this->m_pRC->m_Config.StudioRenderConfig_t + 37) & 0x20) != 0 )
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))pRenderContext->Bind)(
      a1: pRenderContext,
      a2: this->m_pMaterialWireframe[0][0],
      a3: 0,
      a4: a2);
  else
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))pRenderContext->Bind)(
      a1: pRenderContext,
      a2: decalMaterial->m_pMaterial,
      a3: 0,
      a4: a2);
  v10 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
  m_ElementCount = decalMaterial->m_Vertices.m_ElementCount;
  pMesh = v10;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: m_ElementCount,
    nIndexCount: indexCount,
    pMeshSettings: nullptr);
  m_pStudioHdr = this->m_pStudioHdr;
  v13 = 1;
  if ( m_pStudioHdr->numbones > 1 )
  {
    if ( m_pStudioHdr->numflexdesc != 0 )
      v14 = CStudioRender::DrawMultiBoneFlexedDecals(
              this,
              pRenderContext,
              (CachedPosNorm_t *)&meshBuilder,
              decalMaterial,
              pStudioHdr,
              (mstudioboneweight_t *)pStudioLOD);
    else
      v14 = CStudioRender::DrawMultiBoneDecals(this, &meshBuilder, decalMaterial, pStudioHdr);
    if ( v14 == 0 )
      v13 = 0;
  }
  else if ( m_pStudioHdr->numflexdesc != 0 )
  {
    CStudioRender::DrawSingleBoneFlexedDecals(this, pRenderContext, &meshBuilder, decalMaterial);
  }
  else
  {
    CStudioRender::DrawSingleBoneDecals(this, &meshBuilder, decalMaterial);
  }
  CStudioRender::BuildDecalIndices(this, &meshBuilder, decalMaterial);
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
  ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v16 = pMesh->IVertexBuffer::__vftable;
  if ( v13 != 0 )
    ((void (__stdcall *)(int, _DWORD))v16->Draw_2)(a1: -1, a2: 0);
  else
    ((void (*)(void))v16->MarkAsDrawn)();
  if ( bUseHWMorphing_3 != 0 )
    pRenderContext->BindMorph(this: pRenderContext, a2: nullptr);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10006400
// Name: private: void CStudioRender::DrawDecal(struct DrawModelInfo_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawDecal(
        CStudioRender *this@<ecx>,
        int a2@<esi>,
        const DrawModelInfo_t *drawInfo,
        int lod,
        int body)
{
  IMatRenderContext *v6; // esi
  studiohdr_t *m_pStudioHdr; // eax
  bool v8; // cc
  studioloddata_t *v9; // eax
  bool v10; // zf
  int v11; // ebx
  unsigned __int16 m_Next; // ax
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // ecx
  int v14; // ebx
  matrix3x4_t identity; // [esp+8h] [ebp-3Ch] BYREF
  StudioDecalHandle_t__ *handle; // [esp+38h] [ebp-Ch]
  int nHWBone; // [esp+3Ch] [ebp-8h]
  studioloddata_t *pStudioLOD; // [esp+40h] [ebp-4h]
  const DrawModelInfo_t *drawInfoa; // [esp+4Ch] [ebp+8h]

  handle = drawInfo->m_Decals;
  if ( handle != nullptr )
  {
    v6 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                a1: g_pMaterialSystem,
                                a2);
    if ( v6 != nullptr )
      v6->BeginRender(this: v6);
    CStudioRender::PreDrawDecal(this, pRenderContext: v6, drawInfo);
    m_pStudioHdr = drawInfo->m_pStudioHdr;
    this->m_pStudioHdr = drawInfo->m_pStudioHdr;
    v8 = m_pStudioHdr->numbones <= 1;
    pStudioLOD = nullptr;
    if ( v8 )
    {
      v6->SetNumBoneWeights(this: v6, a2: 0);
      v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
      v6->LoadMatrix(this: v6, a2: this->m_PoseToWorld);
    }
    else
    {
      v9 = &drawInfo->m_pHardwareData->m_pLODs[lod];
      v10 = (*((_BYTE *)&this->m_pRC->m_Config + 56) & 4) == 0;
      pStudioLOD = v9;
      if ( v10 || v9->m_pHWMorphDecalBoneRemap == nullptr )
      {
        v6->SetNumBoneWeights(this: v6, a2: 0);
        v6->MatrixMode(this: v6, a2: MATERIAL_MODEL);
        v6->LoadIdentity(this: v6);
      }
      else
      {
        v6->SetNumBoneWeights(this: v6, a2: v9->m_nDecalBoneCount);
        SetIdentityMatrix(matrix: &identity);
        v6->LoadBoneMatrix(this: v6, a2: 0, a3: &identity);
        v11 = 0;
        if ( this->m_pStudioHdr->numbones > 0 )
        {
          drawInfoa = nullptr;
          do
          {
            nHWBone = pStudioLOD->m_pHWMorphDecalBoneRemap[v11];
            if ( nHWBone > 0 )
              v6->LoadBoneMatrix(
                this: v6,
                a2: nHWBone,
                a3: (matrix3x4_t *)((char *)drawInfoa + (unsigned int)this->m_PoseToWorld));
            drawInfoa = (const DrawModelInfo_t *)((char *)drawInfoa + 48);
            ++v11;
          }
          while ( v11 < this->m_pStudioHdr->numbones );
        }
      }
    }
    m_Next = *(_WORD *)(32 * lod + *((_DWORD *)handle + 1));
    if ( m_Next != 0xFFFF )
    {
      m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
      do
      {
        v14 = m_Next;
        CStudioRender::DrawDecalMaterial(
          this,
          a2: (int)this,
          pRenderContext: v6,
          decalMaterial: &m_pMemory[v14].m_Element,
          pStudioHdr: this->m_pStudioHdr,
          pStudioLOD);
        m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
        m_Next = m_pMemory[v14].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v6->EndRender(this: v6);
    v6->Release(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100065C0
// Name: public: void CStudioRender::DrawStaticPropDecals(struct DrawModelInfo_t const __near &,struct StudioRenderContext_t const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CStudioRender::DrawStaticPropDecals(
        CStudioRender *this@<ecx>,
        int a2@<edi>,
        const DrawModelInfo_t *drawInfo,
        StudioRenderContext_t *rc,
        const matrix3x4_t *modelToWorld)
{
  int v6; // eax
  IMatRenderContext *v7; // edi
  unsigned __int16 m_Next; // ax
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // ecx
  int v10; // esi
  StudioDecalHandle_t__ *handle; // [esp+8h] [ebp-4h]

  handle = drawInfo->m_Decals;
  if ( handle != nullptr )
  {
    this->m_pRC = rc;
    v6 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    v7 = (IMatRenderContext *)v6;
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    CStudioRender::PreDrawDecal(this, pRenderContext: v7, drawInfo);
    v7->MatrixMode(this: v7, a2: MATERIAL_MODEL);
    v7->LoadMatrix(this: v7, a2: modelToWorld);
    this->m_pStudioHdr = drawInfo->m_pStudioHdr;
    m_Next = *(_WORD *)(32 * drawInfo->m_Lod + *((_DWORD *)handle + 1));
    if ( m_Next != 0xFFFF )
    {
      m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
      do
      {
        v10 = m_Next;
        CStudioRender::DrawDecalMaterial(
          this,
          a2: (int)v7,
          pRenderContext: v7,
          decalMaterial: &m_pMemory[v10].m_Element,
          pStudioHdr: drawInfo->m_pStudioHdr,
          pStudioLOD: nullptr);
        m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
        m_Next = m_pMemory[v10].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    this->m_pRC = nullptr;
    v7->EndRender(this: v7);
    v7->Release(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006730
// Name: public: CStudioRender::DecalMaterial_t::DecalMaterial_t(void)
// Source: json
//------------------------------------------------------------------------------
CStudioRender::DecalMaterial_t *__thiscall CStudioRender::DecalMaterial_t::DecalMaterial_t(
        CStudioRender::DecalMaterial_t *this)
{
  CStudioRender::DecalMaterial_t *result; // eax
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *m_pMemory; // ecx

  result = this;
  this->m_Indices.m_Memory.m_pMemory = nullptr;
  this->m_Indices.m_Memory.m_nAllocationCount = 0;
  this->m_Indices.m_Memory.m_nGrowSize = 0;
  this->m_Indices.m_Size = 0;
  this->m_Indices.m_pElements = nullptr;
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_LastAlloc.index = -1;
  this->m_Vertices.m_Head = -1;
  this->m_Vertices.m_Tail = -1;
  this->m_Vertices.m_FirstFree = -1;
  this->m_Vertices.m_ElementCount = 0;
  this->m_Vertices.m_NumAlloced = 0;
  this->m_Vertices.m_pElements = this->m_Vertices.m_Memory.m_pMemory;
  this->m_Decals.m_Memory.m_pMemory = nullptr;
  this->m_Decals.m_Memory.m_nAllocationCount = 0;
  this->m_Decals.m_Memory.m_nGrowSize = 0;
  this->m_Decals.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Decals.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Decals.m_Memory.m_pMemory;
  *(_DWORD *)&result->m_Decals.m_Head = -1;
  result->m_Decals.m_NumAlloced = 0;
  result->m_Decals.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100067A0
// Name: public: CStudioRender::DecalMaterial_t::~DecalMaterial_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DecalMaterial_t::~DecalMaterial_t(CStudioRender::DecalMaterial_t *this)
{
  CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Decals);
  if ( this->m_Decals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Decals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Decals.m_Memory.m_pMemory);
      this->m_Decals.m_Memory.m_pMemory = nullptr;
    }
    this->m_Decals.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Vertices);
  if ( this->m_Vertices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Vertices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Vertices.m_Memory.m_pMemory);
      this->m_Vertices.m_Memory.m_pMemory = nullptr;
    }
    this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_Indices);
}

//------------------------------------------------------------------------------
// Address: 0x10007130
// Name: private: void CStudioRender::RemoveDecalListFromLRU(struct StudioDecalHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::RemoveDecalListFromLRU(CStudioRender *this, StudioDecalHandle_t__ *h)
{
  unsigned int m_Head; // esi
  int v3; // ebx
  unsigned int v4; // eax
  CUtlFixedLinkedList<CStudioRender::DecalLRU_t> *p_m_DecalLRU; // edi
  int v6; // eax
  int v7; // eax
  CStudioRender *v8; // [esp+4h] [ebp-8h]

  m_Head = this->m_DecalLRU.m_Head;
  v8 = this;
  if ( m_Head != 0 )
  {
    do
    {
      v3 = *(_DWORD *)(m_Head + 12);
      v4 = v3;
      if ( *(StudioDecalHandle_t__ **)m_Head == h )
      {
        p_m_DecalLRU = &this->m_DecalLRU;
        if ( !CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::IsIdxAfter(
                this: &this->m_DecalLRU.m_Memory,
                i: m_Head,
                it: &this->m_DecalLRU.m_LastAlloc) )
        {
          v6 = *(_DWORD *)(m_Head + 8);
          if ( v6 != m_Head )
          {
            if ( v6 != 0 )
              *(_DWORD *)(v6 + 12) = v3;
            else
              p_m_DecalLRU->m_Head = v3;
            v7 = *(_DWORD *)(m_Head + 12);
            if ( v7 != 0 )
              *(_DWORD *)(v7 + 8) = *(_DWORD *)(m_Head + 8);
            else
              p_m_DecalLRU->m_Tail = *(_DWORD *)(m_Head + 8);
            *(_DWORD *)(m_Head + 12) = m_Head;
            *(_DWORD *)(m_Head + 8) = m_Head;
            --p_m_DecalLRU->m_ElementCount;
          }
        }
        this = v8;
        *(_DWORD *)(m_Head + 12) = p_m_DecalLRU->m_FirstFree;
        v4 = v3;
        p_m_DecalLRU->m_FirstFree = m_Head;
      }
      m_Head = v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100071C0
// Name: private: int CStudioRender::GetDecalMaterial(struct CStudioRender::DecalLod_t __near &,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStudioRender::GetDecalMaterial(
        CStudioRender *this,
        CStudioRender::DecalLod_t *decalLod,
        IMaterial *pDecalMaterial)
{
  int result; // eax
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pMemory; // esi
  int v5; // edx
  CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *p_m_DecalMaterial; // edi
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // si
  CStudioRender::DecalMaterial_t *p_m_Element; // ecx

  LOWORD(result) = decalLod->m_FirstMaterial;
  if ( decalLod->m_FirstMaterial == 0xFFFF )
  {
LABEL_5:
    p_m_DecalMaterial = &this->m_DecalMaterial;
    v7 = CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_DecalMaterial,
           multilist: true);
    v8 = v7;
    if ( v7 == 0xFFFF )
    {
      v8 = -1;
    }
    else
    {
      p_m_Element = &p_m_DecalMaterial->m_Memory.m_pMemory[v7].m_Element;
      if ( p_m_Element != nullptr )
        CStudioRender::DecalMaterial_t::DecalMaterial_t(this: p_m_Element);
    }
    if ( decalLod->m_FirstMaterial != 0xFFFF )
      CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::LinkBefore(
        this: p_m_DecalMaterial,
        before: decalLod->m_FirstMaterial,
        elem: v8);
    decalLod->m_FirstMaterial = v8;
    p_m_DecalMaterial->m_Memory.m_pMemory[v8].m_Element.m_pMaterial = pDecalMaterial;
    return v8;
  }
  else
  {
    m_pMemory = this->m_DecalMaterial.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = (unsigned __int16)result;
      if ( m_pMemory[v5].m_Element.m_pMaterial == pDecalMaterial )
        return (unsigned __int16)result;
      LOWORD(result) = m_pMemory[v5].m_Next;
      if ( (_WORD)result == 0xFFFF )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007270
// Name: private: void CStudioRender::RetireDecal(struct CStudioRender::DecalModelList_t __near &,unsigned short,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::RetireDecal(
        CStudioRender *this,
        CStudioRender::DecalModelList_t *list,
        unsigned __int16 nRetireID,
        int iLOD,
        int iMaxLOD)
{
  unsigned int m_Head; // esi
  CUtlFixedLinkedList<CStudioRender::DecalLRU_t> *p_m_DecalLRU; // edi
  int v7; // eax
  int v8; // eax
  CStudioRender::DecalModelList_t *v9; // edx
  int v10; // edi
  int v11; // eax
  CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *v12; // ecx
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *m_pMemory; // ecx
  bool v14; // zf
  UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *v15; // eax
  unsigned __int16 m_Next; // cx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v17; // edi
  unsigned __int16 v18; // bx
  int m_VertexCount; // ecx
  CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *p_m_Vertices; // esi
  UtlLinkedListElem_t<DecalVertex_t,unsigned short> *v21; // ecx
  int m_IndexCount; // esi
  bool v23; // sf
  int m_Decal; // ebx
  UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short> *v25; // ecx
  int v26; // [esp+8h] [ebp-28h]
  CStudioRender::Decal_t *decalToRemove; // [esp+Ch] [ebp-24h]
  unsigned __int16 next; // [esp+14h] [ebp-1Ch]
  int v30; // [esp+1Ch] [ebp-14h]
  int iLod; // [esp+20h] [ebp-10h]
  unsigned __int16 iNext; // [esp+24h] [ebp-Ch]
  int vertsToRemove; // [esp+28h] [ebp-8h]
  CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *pHistoryList; // [esp+2Ch] [ebp-4h]
  unsigned __int16 iList; // [esp+40h] [ebp+10h]
  int iMaxLODa; // [esp+44h] [ebp+14h]

  m_Head = this->m_DecalLRU.m_Head;
  if ( m_Head != 0 )
  {
    while ( nRetireID != *(_WORD *)(m_Head + 4) )
    {
      m_Head = *(_DWORD *)(m_Head + 12);
      if ( m_Head == 0 )
        goto LABEL_15;
    }
    p_m_DecalLRU = &this->m_DecalLRU;
    if ( !CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>::IsIdxAfter(
            this: &this->m_DecalLRU.m_Memory,
            i: m_Head,
            it: &this->m_DecalLRU.m_LastAlloc) )
    {
      v7 = *(_DWORD *)(m_Head + 8);
      if ( v7 != m_Head )
      {
        if ( v7 != 0 )
          *(_DWORD *)(v7 + 12) = *(_DWORD *)(m_Head + 12);
        else
          p_m_DecalLRU->m_Head = *(_DWORD *)(m_Head + 12);
        v8 = *(_DWORD *)(m_Head + 12);
        if ( v8 != 0 )
          *(_DWORD *)(v8 + 8) = *(_DWORD *)(m_Head + 8);
        else
          p_m_DecalLRU->m_Tail = *(_DWORD *)(m_Head + 8);
        *(_DWORD *)(m_Head + 12) = m_Head;
        *(_DWORD *)(m_Head + 8) = m_Head;
        --p_m_DecalLRU->m_ElementCount;
      }
    }
    *(_DWORD *)(m_Head + 12) = p_m_DecalLRU->m_FirstFree;
    p_m_DecalLRU->m_FirstFree = m_Head;
  }
LABEL_15:
  v9 = list;
  if ( list->m_pLod[iLOD].m_DecalHistory.m_ElementCount != 0 )
  {
    v10 = iMaxLOD - 1;
    iLod = iMaxLOD - 1;
    if ( iMaxLOD - 1 >= list->m_pHardwareData->m_RootLOD )
    {
      v11 = 32 * v10;
      v30 = 32 * v10;
      do
      {
        v12 = (CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *)((char *)&v9->m_pLod->m_DecalHistory + v11);
        pHistoryList = v12;
        if ( (CStudioRender::DecalLod_t *)((char *)v9->m_pLod + v11) != (CStudioRender::DecalLod_t *)-4 )
        {
          iList = *(unsigned __int16 *)((char *)&v9->m_pLod->m_DecalHistory.m_Head + v11);
          if ( iList != 0xFFFF )
          {
            while ( 1 )
            {
              m_pMemory = v12->m_Memory.m_pMemory;
              v26 = iList;
              v14 = &m_pMemory[v26] == nullptr;
              v15 = &m_pMemory[v26];
              m_Next = m_pMemory[v26].m_Next;
              iMaxLODa = (int)v15;
              iNext = m_Next;
              if ( v14 || v15->m_Element.m_nId != nRetireID )
              {
                iList = m_Next;
              }
              else
              {
                v17 = &this->m_DecalMaterial.m_Memory.m_pMemory[v15->m_Element.m_Material];
                if ( v17 != nullptr )
                {
                  v18 = v17->m_Element.m_Vertices.m_Head;
                  decalToRemove = &v17->m_Element.m_Decals.m_Memory.m_pMemory[v15->m_Element.m_Decal].m_Element;
                  m_VertexCount = decalToRemove->m_VertexCount;
                  p_m_Vertices = &v17->m_Element.m_Vertices;
                  vertsToRemove = m_VertexCount;
                  if ( m_VertexCount > 0 )
                  {
                    g_nTotalDecalVerts -= m_VertexCount;
                    do
                    {
                      next = p_m_Vertices->m_Memory.m_pMemory[v18].m_Next;
                      CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::Unlink(
                        this: p_m_Vertices,
                        elem: v18);
                      v17->m_Element.m_Vertices.m_Memory.m_pMemory[v18].m_Next = v17->m_Element.m_Vertices.m_FirstFree;
                      v17->m_Element.m_Vertices.m_FirstFree = v18;
                      v18 = next;
                      --vertsToRemove;
                    }
                    while ( vertsToRemove > 0 );
                    v15 = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)iMaxLODa;
                  }
                  if ( v17->m_Element.m_Vertices.m_ElementCount == 0 )
                  {
                    CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_Vertices);
                    if ( v17->m_Element.m_Vertices.m_Memory.m_nGrowSize >= 0 )
                    {
                      if ( p_m_Vertices->m_Memory.m_pMemory != nullptr )
                      {
                        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Vertices->m_Memory.m_pMemory);
                        p_m_Vertices->m_Memory.m_pMemory = nullptr;
                      }
                      v17->m_Element.m_Vertices.m_Memory.m_nAllocationCount = 0;
                    }
                    v15 = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)iMaxLODa;
                    v17->m_Element.m_Vertices.m_FirstFree = -1;
                    v21 = p_m_Vertices->m_Memory.m_pMemory;
                    *(_DWORD *)&v17->m_Element.m_Vertices.m_NumAlloced = -65536;
                    v17->m_Element.m_Vertices.m_pElements = v21;
                  }
                  m_IndexCount = decalToRemove->m_IndexCount;
                  if ( v17->m_Element.m_Indices.m_Size - decalToRemove->m_IndexCount > 0 && m_IndexCount > 0 )
                  {
                    _V_memmove(
                      dest: v17->m_Element.m_Indices.m_Memory.m_pMemory,
                      src: &v17->m_Element.m_Indices.m_Memory.m_pMemory[m_IndexCount],
                      count: 2 * (v17->m_Element.m_Indices.m_Size - decalToRemove->m_IndexCount));
                    v15 = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)iMaxLODa;
                  }
                  v17->m_Element.m_Indices.m_Size -= m_IndexCount;
                  if ( v17->m_Element.m_Indices.m_Size == 0 )
                  {
                    v23 = v17->m_Element.m_Indices.m_Memory.m_nGrowSize < 0;
                    v17->m_Element.m_Indices.m_Size = 0;
                    if ( !v23 )
                    {
                      if ( v17->m_Element.m_Indices.m_Memory.m_pMemory != nullptr )
                      {
                        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17->m_Element.m_Indices.m_Memory.m_pMemory);
                        v15 = (UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> *)iMaxLODa;
                        v17->m_Element.m_Indices.m_Memory.m_pMemory = nullptr;
                      }
                      v17->m_Element.m_Indices.m_Memory.m_nAllocationCount = 0;
                    }
                    v17->m_Element.m_Indices.m_pElements = v17->m_Element.m_Indices.m_Memory.m_pMemory;
                  }
                  m_Decal = v15->m_Element.m_Decal;
                  CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::Unlink(
                    this: &v17->m_Element.m_Decals,
                    elem: v15->m_Element.m_Decal);
                  v17->m_Element.m_Decals.m_Memory.m_pMemory[m_Decal].m_Next = v17->m_Element.m_Decals.m_FirstFree;
                  v17->m_Element.m_Decals.m_FirstFree = m_Decal;
                  if ( v17->m_Element.m_Decals.m_ElementCount == 0 )
                  {
                    CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::RemoveAll(this: &v17->m_Element.m_Decals);
                    if ( v17->m_Element.m_Decals.m_Memory.m_nGrowSize >= 0 )
                    {
                      if ( v17->m_Element.m_Decals.m_Memory.m_pMemory != nullptr )
                      {
                        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17->m_Element.m_Decals.m_Memory.m_pMemory);
                        v17->m_Element.m_Decals.m_Memory.m_pMemory = nullptr;
                      }
                      v17->m_Element.m_Decals.m_Memory.m_nAllocationCount = 0;
                    }
                    v17->m_Element.m_Decals.m_FirstFree = -1;
                    v25 = v17->m_Element.m_Decals.m_Memory.m_pMemory;
                    *(_DWORD *)&v17->m_Element.m_Decals.m_NumAlloced = -65536;
                    v17->m_Element.m_Decals.m_pElements = v25;
                  }
                }
                CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::Unlink(
                  this: pHistoryList,
                  elem: iList);
                pHistoryList->m_Memory.m_pMemory[v26].m_Next = pHistoryList->m_FirstFree;
                pHistoryList->m_FirstFree = iList;
                m_Next = iNext;
                iList = iNext;
                v9 = list;
              }
              if ( m_Next == 0xFFFF )
                break;
              v12 = pHistoryList;
            }
            v11 = v30;
            v10 = iLod;
          }
        }
        --v10;
        v11 -= 32;
        iLod = v10;
        v30 = v11;
      }
      while ( v10 >= v9->m_pHardwareData->m_RootLOD );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100075A0
// Name: public: void CStudioRender::DestroyDecalList(struct StudioDecalHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::DestroyDecalList(CStudioRender *this, StudioDecalHandle_t__ *hDecal)
{
  StudioDecalHandle_t__ *v2; // esi
  CStudioRender *v3; // edi
  unsigned __int16 v4; // cx
  CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short> > *p_m_DecalMaterial; // ebx
  int v6; // edi
  unsigned __int16 m_Next; // dx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v8; // esi
  bool v9; // sf
  unsigned __int16 *m_pMemory; // eax
  CStudioRender::DecalLod_t *v11; // ecx
  CThreadFastMutex *p_m_DecalMutex; // ebx
  DWORD CurrentThreadId; // ecx
  StudioDecalHandle_t__ *v14; // eax
  StudioDecalHandle_t__ *v15; // eax
  unsigned __int16 next; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v20; // [esp+18h] [ebp-8h]
  unsigned __int16 mat; // [esp+1Ch] [ebp-4h]

  v2 = hDecal;
  v3 = this;
  if ( hDecal == nullptr )
    return;
  CStudioRender::RemoveDecalListFromLRU(this, h: hDecal);
  i = 0;
  if ( *((int *)hDecal + 2) > 0 )
  {
    v20 = 0;
    do
    {
      v4 = *(_WORD *)(v20 + *((_DWORD *)v2 + 1));
      mat = v4;
      if ( v4 != 0xFFFF )
      {
        p_m_DecalMaterial = &v3->m_DecalMaterial;
        while ( 1 )
        {
          v6 = v4;
          m_Next = p_m_DecalMaterial->m_Memory.m_pMemory[v6].m_Next;
          g_nTotalDecalVerts -= p_m_DecalMaterial->m_Memory.m_pMemory[v6].m_Element.m_Vertices.m_ElementCount;
          next = m_Next;
          CUtlLinkedList<CStudioRender::DecalMaterial_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short>,unsigned short>>::Unlink(
            this: p_m_DecalMaterial,
            elem: v4);
          v8 = &p_m_DecalMaterial->m_Memory.m_pMemory[v6];
          CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::RemoveAll(this: &v8->m_Element.m_Decals);
          if ( v8->m_Element.m_Decals.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v8->m_Element.m_Decals.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Element.m_Decals.m_Memory.m_pMemory);
              v8->m_Element.m_Decals.m_Memory.m_pMemory = nullptr;
            }
            v8->m_Element.m_Decals.m_Memory.m_nAllocationCount = 0;
          }
          CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::RemoveAll(this: &v8->m_Element.m_Vertices);
          if ( v8->m_Element.m_Vertices.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v8->m_Element.m_Vertices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Element.m_Vertices.m_Memory.m_pMemory);
              v8->m_Element.m_Vertices.m_Memory.m_pMemory = nullptr;
            }
            v8->m_Element.m_Vertices.m_Memory.m_nAllocationCount = 0;
          }
          v9 = v8->m_Element.m_Indices.m_Memory.m_nGrowSize < 0;
          v8->m_Element.m_Indices.m_Size = 0;
          if ( !v9 )
          {
            if ( v8->m_Element.m_Indices.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Element.m_Indices.m_Memory.m_pMemory);
              v8->m_Element.m_Indices.m_Memory.m_pMemory = nullptr;
            }
            v8->m_Element.m_Indices.m_Memory.m_nAllocationCount = 0;
          }
          v9 = v8->m_Element.m_Indices.m_Memory.m_nGrowSize < 0;
          m_pMemory = v8->m_Element.m_Indices.m_Memory.m_pMemory;
          v8->m_Element.m_Indices.m_pElements = m_pMemory;
          if ( !v9 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              v8->m_Element.m_Indices.m_Memory.m_pMemory = nullptr;
            }
            v8->m_Element.m_Indices.m_Memory.m_nAllocationCount = 0;
          }
          v8->m_Next = p_m_DecalMaterial->m_FirstFree;
          p_m_DecalMaterial->m_FirstFree = mat;
          mat = next;
          if ( next == 0xFFFF )
            break;
          v4 = next;
        }
        v2 = hDecal;
        v3 = this;
      }
      v20 += 32;
      ++i;
    }
    while ( i < *((_DWORD *)v2 + 2) );
  }
  v11 = *((CStudioRender::DecalLod_t **)v2 + 1);
  if ( v11 != nullptr )
    CStudioRender::DecalLod_t::`vector deleting destructor'(this: v11, a2: 3u);
  *((_DWORD *)v2 + 1) = 0;
  p_m_DecalMutex = &v3->m_DecalMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == v3->m_DecalMutex.m_ownerID )
    goto LABEL_31;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)p_m_DecalMutex, CurrentThreadId, 0) == 0 )
  {
    v3 = this;
LABEL_31:
    ++p_m_DecalMutex->m_depth;
    goto LABEL_33;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: p_m_DecalMutex, a2: CurrentThreadId, a3: 0);
  v3 = this;
LABEL_33:
  if ( !CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>::IsIdxAfter(
          this: &v3->m_DecalList.m_Memory,
          i: (unsigned int)v2,
          it: &v3->m_DecalList.m_LastAlloc) )
  {
    v14 = *((StudioDecalHandle_t__ **)v2 + 3);
    if ( v14 != v2 )
    {
      if ( v14 != nullptr )
        v14[4] = v2[4];
      else
        v3->m_DecalList.m_Head = (int)v2[4];
      v15 = *((StudioDecalHandle_t__ **)v2 + 4);
      if ( v15 != nullptr )
        v15[3] = v2[3];
      else
        v3->m_DecalList.m_Tail = (int)v2[3];
      *((_DWORD *)v2 + 4) = v2;
      *((_DWORD *)v2 + 3) = v2;
      --v3->m_DecalList.m_ElementCount;
    }
  }
  v2[4] = (StudioDecalHandle_t__)v3->m_DecalList.m_FirstFree;
  v3->m_DecalList.m_FirstFree = (int)v2;
  if ( p_m_DecalMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_DecalMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100077E0
// Name: private: unsigned short CStudioRender::AddVertexToDecal(struct CStudioRender::DecalBuildInfo_t __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStudioRender::AddVertexToDecal(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int nMeshIndex,
        unsigned __int16 nGroupIndex)
{
  CStudioRender::DecalBuildVertexInfo_t *v5; // edi
  CStudioRender::DecalMaterial_t *m_pDecalMaterial; // ebx
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // bx
  CStudioRender::DecalMaterial_t *v9; // ecx
  unsigned __int16 builda; // [esp+14h] [ebp+8h]

  v5 = &build->m_pVertexInfo[nMeshIndex];
  if ( v5->m_UniqueID == build->m_nGlobalMeshIndex )
    return v5->m_VertexIndex;
  v5->m_UniqueID = build->m_nGlobalMeshIndex;
  m_pDecalMaterial = build->m_pDecalMaterial;
  v7 = CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &m_pDecalMaterial->m_Vertices,
         multilist: false);
  builda = v7;
  if ( v7 == 0xFFFF )
  {
    v8 = -1;
  }
  else
  {
    CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::LinkBefore(
      this: &m_pDecalMaterial->m_Vertices,
      before: 0xFFFFu,
      elem: v7);
    v8 = builda;
  }
  v9 = build->m_pDecalMaterial;
  ++g_nTotalDecalVerts;
  CStudioRender::ConvertMeshVertexToDecalVertex(
    this,
    build,
    meshIndex: nMeshIndex,
    decalVertex: &v9->m_Vertices.m_Memory.m_pMemory[v8].m_Element,
    nGroupIndex);
  v5->m_VertexIndex = build->m_VertexCount++;
  if ( build->m_FirstVertex == 0xFFFF )
    build->m_FirstVertex = v8;
  return v5->m_VertexIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100078A0
// Name: private: unsigned short CStudioRender::AddVertexToDecal(struct CStudioRender::DecalBuildInfo_t __near &,struct DecalVertex_t __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CStudioRender::AddVertexToDecal(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        DecalVertex_t *vert)
{
  CStudioRender::DecalBuildInfo_t *v4; // esi
  unsigned __int16 m_FirstVertex; // cx
  CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short> > *p_m_Vertices; // edi
  char *v7; // esi
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  char *v11; // edx
  char *v12; // ecx
  unsigned __int16 result; // ax
  unsigned __int16 v14; // ax
  __int16 v15; // ax
  int v16; // eax
  __int16 vertexCount; // [esp+14h] [ebp-4h]
  unsigned __int16 builda; // [esp+20h] [ebp+8h]
  DecalVertex_t *verta; // [esp+24h] [ebp+Ch]

  v4 = build;
  m_FirstVertex = build->m_FirstVertex;
  p_m_Vertices = &build->m_pDecalMaterial->m_Vertices;
  vertexCount = 0;
  if ( m_FirstVertex == 0xFFFF )
    goto LABEL_18;
  verta = &p_m_Vertices->m_Memory.m_pMemory->m_Element;
  do
  {
    v7 = (char *)verta + 48 * m_FirstVertex;
    v8 = *((unsigned __int16 *)v7 + 17);
    if ( (_WORD)v8 != 0xFFFF )
    {
      v9 = *((unsigned __int16 *)v7 + 18);
      if ( (_WORD)v9 != 0xFFFF )
      {
        v10 = *((unsigned __int16 *)v7 + 19);
        if ( (_WORD)v10 != 0xFFFF )
        {
          v11 = (char *)build->m_pStudioHdr + 16 * v8 + build->m_pStudioHdr->bodypartindex;
          v12 = &v11[148 * v9 + *((_DWORD *)v11 + 3)];
          if ( &v12[116 * v10 + *((_DWORD *)v12 + 19)] != nullptr )
          {
            p_m_Vertices = &build->m_pDecalMaterial->m_Vertices;
            goto LABEL_16;
          }
        }
        p_m_Vertices = &build->m_pDecalMaterial->m_Vertices;
      }
    }
    if ( fabs(*(float *)v7 - vert->m_Position.x) <= 0.001
      && fabs(*((float *)v7 + 1) - vert->m_Position.y) <= 0.001
      && fabs(*((float *)v7 + 2) - vert->m_Position.z) <= 0.001
      && fabs(*((float *)v7 + 3) - vert->m_Normal.x) <= 0.001
      && fabs(*((float *)v7 + 4) - vert->m_Normal.y) <= 0.001
      && fabs(*((float *)v7 + 5) - vert->m_Normal.z) <= 0.001 )
    {
      return vertexCount;
    }
LABEL_16:
    m_FirstVertex = *((_WORD *)v7 + 23);
    ++vertexCount;
  }
  while ( m_FirstVertex != 0xFFFF );
  v4 = build;
LABEL_18:
  v14 = CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::AllocInternal(
          this: p_m_Vertices,
          multilist: false);
  builda = v14;
  if ( v14 == 0xFFFF )
  {
    v15 = -1;
  }
  else
  {
    CUtlLinkedList<DecalVertex_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<DecalVertex_t,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_Vertices,
      before: 0xFFFFu,
      elem: v14);
    v16 = (int)&p_m_Vertices->m_Memory.m_pMemory[builda];
    if ( v16 != 0 )
    {
      *(float *)v16 = vert->m_Position.x;
      *(float *)(v16 + 4) = vert->m_Position.y;
      *(float *)(v16 + 8) = vert->m_Position.z;
      *(float *)(v16 + 12) = vert->m_Normal.x;
      *(float *)(v16 + 16) = vert->m_Normal.y;
      *(float *)(v16 + 20) = vert->m_Normal.z;
      *(float *)(v16 + 24) = vert->m_TexCoord.x;
      *(float *)(v16 + 28) = vert->m_TexCoord.y;
      *(_WORD *)(v16 + 32) = vert->m_MeshVertexIndex;
      *(_WORD *)(v16 + 34) = vert->m_Body;
      *(_WORD *)(v16 + 36) = vert->m_Model;
      *(_WORD *)(v16 + 38) = vert->m_Mesh;
      *(_WORD *)(v16 + 40) = vert->m_GroupIndex;
      *(_WORD *)(v16 + 42) = vert->m_Group;
    }
    v15 = builda;
  }
  ++g_nTotalDecalVerts;
  if ( v4->m_FirstVertex == 0xFFFF )
    v4->m_FirstVertex = v15;
  result = v4->m_VertexCount;
  v4->m_VertexCount = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007AE0
// Name: private: void CStudioRender::AddClippedDecalToTriangle(struct CStudioRender::DecalBuildInfo_t __near &,struct DecalClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::AddClippedDecalToTriangle(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int clipState)
{
  int j; // esi
  int v6; // eax
  unsigned __int16 v7; // ax
  CStudioRender::DecalMaterial_t *m_pDecalMaterial; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v12; // eax
  unsigned __int16 *v13; // eax
  CStudioRender::DecalMaterial_t *v14; // esi
  int v15; // edi
  int v16; // eax
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 *v19; // eax
  CStudioRender::DecalMaterial_t *v20; // esi
  int v21; // edi
  int v22; // eax
  unsigned __int16 *v23; // ecx
  int v24; // eax
  unsigned __int16 *v25; // eax
  unsigned __int16 indices[8]; // [esp+Ch] [ebp-10h]
  int i; // [esp+28h] [ebp+Ch]

  for ( j = 0; j < *(_DWORD *)clipState; ++j )
  {
    v6 = *(_DWORD *)(clipState + 4 * (j + 7 * *(unsigned __int8 *)(clipState + 60)) + 4);
    if ( v6 >= 3 )
      v7 = CStudioRender::AddVertexToDecal(this, build, vert: (DecalVertex_t *)(44 * v6 + clipState + 68));
    else
      v7 = CStudioRender::AddVertexToDecal(
             this,
             build,
             nMeshIndex: *(unsigned __int16 *)(44 * v6 + clipState + 100),
             nGroupIndex: 0xFFFFu);
    indices[j] = v7;
  }
  for ( i = 1; i < *(_DWORD *)clipState - 1; ++i )
  {
    m_pDecalMaterial = build->m_pDecalMaterial;
    m_Size = m_pDecalMaterial->m_Indices.m_Size;
    m_nAllocationCount = m_pDecalMaterial->m_Indices.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<unsigned short,int>::Grow(
        this: &m_pDecalMaterial->m_Indices.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++m_pDecalMaterial->m_Indices.m_Size;
    m_pMemory = m_pDecalMaterial->m_Indices.m_Memory.m_pMemory;
    v12 = m_pDecalMaterial->m_Indices.m_Size - m_Size - 1;
    m_pDecalMaterial->m_Indices.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v12);
    v13 = &m_pDecalMaterial->m_Indices.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = indices[0];
    v14 = build->m_pDecalMaterial;
    v15 = v14->m_Indices.m_Size;
    v16 = v14->m_Indices.m_Memory.m_nAllocationCount;
    if ( v15 + 1 > v16 )
      CUtlMemory<unsigned short,int>::Grow(this: &v14->m_Indices.m_Memory, num: v15 - v16 + 1);
    ++v14->m_Indices.m_Size;
    v17 = v14->m_Indices.m_Memory.m_pMemory;
    v18 = v14->m_Indices.m_Size - v15 - 1;
    v14->m_Indices.m_pElements = v17;
    if ( v18 > 0 )
      _V_memmove(dest: &v17[v15 + 1], src: &v17[v15], count: 2 * v18);
    v19 = &v14->m_Indices.m_Memory.m_pMemory[v15];
    if ( v19 != nullptr )
      *v19 = indices[i];
    v20 = build->m_pDecalMaterial;
    v21 = v20->m_Indices.m_Size;
    v22 = v20->m_Indices.m_Memory.m_nAllocationCount;
    if ( v21 + 1 > v22 )
      CUtlMemory<unsigned short,int>::Grow(this: &v20->m_Indices.m_Memory, num: v21 - v22 + 1);
    ++v20->m_Indices.m_Size;
    v23 = v20->m_Indices.m_Memory.m_pMemory;
    v24 = v20->m_Indices.m_Size - v21 - 1;
    v20->m_Indices.m_pElements = v23;
    if ( v24 > 0 )
      _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 2 * v24);
    v25 = &v20->m_Indices.m_Memory.m_pMemory[v21];
    if ( v25 != nullptr )
      *v25 = indices[i + 1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007C90
// Name: private: bool CStudioRender::ClipDecal(struct CStudioRender::DecalBuildInfo_t __near &,int,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::ClipDecal(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int i1,
        int i2,
        int i3,
        int *pClipFlags)
{
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  DecalClipState_t clipState; // [esp+10h] [ebp-344h] BYREF

  clipState.m_VertCount = 3;
  CStudioRender::ConvertMeshVertexToDecalVertex(
    this,
    build,
    meshIndex: i1,
    decalVertex: clipState.m_ClipVerts,
    nGroupIndex: 0xFFFFu);
  CStudioRender::ConvertMeshVertexToDecalVertex(
    this,
    build,
    meshIndex: i2,
    decalVertex: &clipState.m_ClipVerts[1],
    nGroupIndex: 0xFFFFu);
  CStudioRender::ConvertMeshVertexToDecalVertex(
    this,
    build,
    meshIndex: i3,
    decalVertex: &clipState.m_ClipVerts[2],
    nGroupIndex: 0xFFFFu);
  v7 = *pClipFlags;
  v8 = pClipFlags[1];
  v9 = pClipFlags[2];
  clipState.m_ClipVertCount = 3;
  clipState.m_ClipFlags[0] = v7;
  *(_QWORD *)&clipState.m_Indices[0][0] = 0x100000000LL;
  clipState.m_ClipFlags[1] = v8;
  clipState.m_ClipFlags[2] = v9;
  clipState.m_Indices[0][2] = 2;
  clipState.m_Pass = false;
  ClipTriangleAgainstPlane(state: &clipState, normalInd: 0, flag: 1, val: 0.0);
  if ( clipState.m_VertCount < 3 )
    return 0;
  ClipTriangleAgainstPlane(state: &clipState, normalInd: 0, flag: 4, val: 1.0);
  if ( clipState.m_VertCount < 3 )
    return 0;
  ClipTriangleAgainstPlane(state: &clipState, normalInd: 1, flag: 2, val: 0.0);
  if ( clipState.m_VertCount < 3 )
    return 0;
  ClipTriangleAgainstPlane(state: &clipState, normalInd: 1, flag: 8, val: 1.0);
  if ( clipState.m_VertCount < 3 )
    return 0;
  if ( build->m_UseClipVert )
    CStudioRender::AddClippedDecalToTriangle(this, build, (int)&clipState);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007DF0
// Name: private: void CStudioRender::AddTriangleToDecal(struct CStudioRender::DecalBuildInfo_t __near &,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::AddTriangleToDecal(
        CStudioRender *this,
        CStudioRender::DecalBuildInfo_t *build,
        int i1,
        int i2,
        int i3,
        unsigned __int16 gi1,
        unsigned __int16 gi2,
        unsigned __int16 gi3)
{
  CStudioRender::DecalBuildVertexInfo_t *m_pVertexInfo; // eax
  CStudioRender::DecalBuildVertexInfo_t *v11; // edi
  CStudioRender::DecalBuildVertexInfo_t *v12; // ecx
  unsigned __int8 m_Flags; // al
  unsigned __int8 v14; // dl
  unsigned __int8 v15; // cl
  int v16; // edx
  float y; // xmm0_4
  float v18; // xmm0_4
  int v19; // ecx
  float v20; // xmm0_4
  float x; // xmm0_4
  int v22; // eax
  float v23; // xmm0_4
  char v24; // al
  unsigned __int16 v25; // ax
  CStudioRender::DecalMaterial_t *m_pDecalMaterial; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v30; // eax
  unsigned __int16 *v31; // edi
  CStudioRender::DecalMaterial_t *v32; // esi
  int v33; // edi
  int v34; // eax
  unsigned __int16 *v35; // ecx
  int v36; // eax
  unsigned __int16 *v37; // edi
  CStudioRender::DecalMaterial_t *v38; // esi
  int v39; // edi
  int v40; // eax
  unsigned __int16 *v41; // ecx
  int v42; // eax
  unsigned __int16 *v43; // eax
  int clipFlags[3]; // [esp+Ch] [ebp-10h] BYREF
  CStudioRender::DecalBuildVertexInfo_t *v45; // [esp+18h] [ebp-4h]
  CStudioRender::DecalBuildInfo_t *builda; // [esp+24h] [ebp+8h]
  unsigned __int16 i1a; // [esp+28h] [ebp+Ch]
  unsigned __int16 i2a; // [esp+2Ch] [ebp+10h]
  unsigned __int16 i3a; // [esp+30h] [ebp+14h]

  m_pVertexInfo = build->m_pVertexInfo;
  v11 = &m_pVertexInfo[i1];
  v12 = &m_pVertexInfo[i2];
  v45 = &m_pVertexInfo[i3];
  m_Flags = v45->m_Flags;
  builda = (CStudioRender::DecalBuildInfo_t *)v12;
  v14 = v12->m_Flags & m_Flags;
  v15 = v11->m_Flags;
  if ( (v15 & v14 & 1) != 0 && ((v15 | (unsigned __int8)(HIBYTE(builda->m_pMesh) | m_Flags)) & 2) != 0 )
  {
    v16 = 0;
    if ( v11->m_UV.x >= 0.0 )
    {
      if ( v11->m_UV.x > 1.0 )
        v16 = 4;
    }
    else
    {
      v16 = 1;
    }
    y = v11->m_UV.y;
    if ( y >= 0.0 )
    {
      if ( y > 1.0 )
        v16 |= 8u;
    }
    else
    {
      v16 |= 2u;
    }
    v18 = *(float *)&builda->m_ppMaterials;
    v19 = 0;
    clipFlags[0] = v16;
    if ( v18 >= 0.0 )
    {
      if ( v18 > 1.0 )
        v19 = 4;
    }
    else
    {
      v19 = 1;
    }
    v20 = *(float *)&builda->m_pStudioHdr;
    if ( v20 >= 0.0 )
    {
      if ( v20 > 1.0 )
        v19 |= 8u;
    }
    else
    {
      v19 |= 2u;
    }
    x = v45->m_UV.x;
    v22 = 0;
    clipFlags[1] = v19;
    if ( x >= 0.0 )
    {
      if ( x > 1.0 )
        v22 = 4;
    }
    else
    {
      v22 = 1;
    }
    v23 = v45->m_UV.y;
    if ( v23 >= 0.0 )
    {
      if ( v23 > 1.0 )
        v22 |= 8u;
    }
    else
    {
      v22 |= 2u;
    }
    clipFlags[2] = v22;
    if ( (v19 & v22 & v16) == 0 )
    {
      if ( !build->m_UseClipVert && (v16 == 0 || v19 == 0 || v22 == 0)
        || v16 == 0 && v19 == 0 && v22 == 0
        || (v24 = CStudioRender::ClipDecal(this, build, i1, i2, i3, pClipFlags: clipFlags), !build->m_UseClipVert)
        && v24 != 0 )
      {
        i1a = CStudioRender::AddVertexToDecal(this, build, nMeshIndex: i1, nGroupIndex: gi1);
        i2a = CStudioRender::AddVertexToDecal(this, build, nMeshIndex: i2, nGroupIndex: gi2);
        v25 = CStudioRender::AddVertexToDecal(this, build, nMeshIndex: i3, nGroupIndex: gi3);
        m_pDecalMaterial = build->m_pDecalMaterial;
        m_Size = m_pDecalMaterial->m_Indices.m_Size;
        i3a = v25;
        m_nAllocationCount = m_pDecalMaterial->m_Indices.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<unsigned short,int>::Grow(
            this: &m_pDecalMaterial->m_Indices.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++m_pDecalMaterial->m_Indices.m_Size;
        m_pMemory = m_pDecalMaterial->m_Indices.m_Memory.m_pMemory;
        v30 = m_pDecalMaterial->m_Indices.m_Size - m_Size - 1;
        m_pDecalMaterial->m_Indices.m_pElements = m_pMemory;
        if ( v30 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v30);
        v31 = &m_pDecalMaterial->m_Indices.m_Memory.m_pMemory[m_Size];
        if ( v31 != nullptr )
          *v31 = i1a;
        v32 = build->m_pDecalMaterial;
        v33 = v32->m_Indices.m_Size;
        v34 = v32->m_Indices.m_Memory.m_nAllocationCount;
        if ( v33 + 1 > v34 )
          CUtlMemory<unsigned short,int>::Grow(this: &v32->m_Indices.m_Memory, num: v33 - v34 + 1);
        ++v32->m_Indices.m_Size;
        v35 = v32->m_Indices.m_Memory.m_pMemory;
        v36 = v32->m_Indices.m_Size - v33 - 1;
        v32->m_Indices.m_pElements = v35;
        if ( v36 > 0 )
          _V_memmove(dest: &v35[v33 + 1], src: &v35[v33], count: 2 * v36);
        v37 = &v32->m_Indices.m_Memory.m_pMemory[v33];
        if ( v37 != nullptr )
          *v37 = i2a;
        v38 = build->m_pDecalMaterial;
        v39 = v38->m_Indices.m_Size;
        v40 = v38->m_Indices.m_Memory.m_nAllocationCount;
        if ( v39 + 1 > v40 )
          CUtlMemory<unsigned short,int>::Grow(this: &v38->m_Indices.m_Memory, num: v39 - v40 + 1);
        ++v38->m_Indices.m_Size;
        v41 = v38->m_Indices.m_Memory.m_pMemory;
        v42 = v38->m_Indices.m_Size - v39 - 1;
        v38->m_Indices.m_pElements = v41;
        if ( v42 > 0 )
          _V_memmove(dest: &v41[v39 + 1], src: &v41[v39], count: 2 * v42);
        v43 = &v38->m_Indices.m_Memory.m_pMemory[v39];
        if ( v43 != nullptr )
          *v43 = i3a;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100080A0
// Name: private: void CStudioRender::AddDecalToMesh(struct CStudioRender::DecalBuildInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::AddDecalToMesh(CStudioRender *this, CStudioRender::DecalBuildInfo_t *build)
{
  CStudioRender::DecalBuildInfo_t *v2; // eax
  int m_nIndex; // ecx
  int v4; // edx
  studiomeshdata_t *m_pMeshData; // ecx
  studiomeshgroup_t *v6; // ecx
  OptimizedModel::StripHeader_t *v7; // ebx
  int v8; // esi
  unsigned __int16 *m_pIndices; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // edi
  int j; // [esp+8h] [ebp-14h]
  int k; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  studiomeshgroup_t *pGroup; // [esp+18h] [ebp-4h]

  v2 = build;
  m_nIndex = build->m_pMeshVertices[build->m_nGlobalMeshIndex].m_nIndex;
  if ( m_nIndex >= 0 )
  {
    build->m_pVertexInfo = &build->m_pVertexBuffer[m_nIndex];
    v4 = 0;
    j = 0;
    if ( build->m_pMeshData->m_NumGroup > 0 )
    {
      v16 = 0;
      do
      {
        m_pMeshData = v2->m_pMeshData;
        v2->m_Group = v4;
        v6 = &m_pMeshData->m_pMeshGroup[v16];
        k = 0;
        pGroup = v6;
        if ( v6->m_NumStrips > 0 )
        {
          v17 = 0;
          do
          {
            v7 = &v6->m_pStripData[v17];
            if ( (v7->flags & 1) != 0 )
            {
              v8 = 0;
              if ( v7->numIndices > 0 )
              {
                do
                {
                  m_pIndices = v6->m_pIndices;
                  v10 = v8 + v7->indexOffset;
                  v11 = m_pIndices[v10 + 2];
                  v12 = m_pIndices[v10 + 1];
                  CStudioRender::AddTriangleToDecal(
                    this,
                    build,
                    i1: pGroup->m_pGroupIndexToMeshIndex[m_pIndices[v10]],
                    i2: pGroup->m_pGroupIndexToMeshIndex[v12],
                    i3: pGroup->m_pGroupIndexToMeshIndex[v11],
                    gi1: m_pIndices[v10],
                    gi2: v12,
                    gi3: v11);
                  v6 = pGroup;
                  v8 += 3;
                }
                while ( v8 < v7->numIndices );
                v2 = build;
              }
            }
            ++v17;
            ++k;
          }
          while ( k < v6->m_NumStrips );
          v4 = j;
        }
        ++v16;
        j = ++v4;
      }
      while ( v4 < v2->m_pMeshData->m_NumGroup );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008190
// Name: private: bool CStudioRender::AddDecalToModel(struct CStudioRender::DecalBuildInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioRender::AddDecalToModel(CStudioRender *this, CStudioRender::DecalBuildInfo_t *buildInfo)
{
  mstudiomesh_t *v3; // eax
  mstudiomesh_t *m_pMesh; // ebx
  studiomeshdata_t *v5; // edx
  studiohdr_t *m_pStudioHdr; // eax
  mstudiomodel_t *v7; // edi
  const vertexFileHeader_t *v8; // eax
  int vertexDataStart; // ecx
  char *v10; // ecx
  int tangentDataStart; // ecx
  char *v12; // eax
  const mstudio_modelvertexdata_t *v13; // eax
  mstudio_meshvertexdata_t *p_vertexdata; // ebx
  const mstudio_meshvertexdata_t *v15; // eax
  const vertexFileHeader_t *v16; // eax
  int v17; // ecx
  const thinModelVertices_t *v18; // eax
  CStudioRender *v20; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  CStudioRender::DecalBuildInfo_t *buildInfoa; // [esp+1Ch] [ebp+8h]

  v20 = this;
  i = 0;
  if ( this->m_pSubModel->nummeshes <= 0 )
    return 1;
  for ( buildInfoa = nullptr; ; buildInfoa = (CStudioRender::DecalBuildInfo_t *)((char *)buildInfoa + 116) )
  {
    buildInfo->m_Mesh = i;
    v3 = (mstudiomesh_t *)((char *)buildInfoa + this->m_pSubModel->meshindex + (unsigned int)this->m_pSubModel);
    buildInfo->m_pMesh = v3;
    m_pMesh = buildInfo->m_pMesh;
    v5 = &this->m_pStudioMeshes[v3->meshid];
    m_pStudioHdr = buildInfo->m_pStudioHdr;
    buildInfo->m_pMeshData = v5;
    v7 = (mstudiomodel_t *)((char *)m_pMesh + m_pMesh->modelindex);
    v8 = mstudiomodel_t::CacheVertexData(this: v7, pModelData: m_pStudioHdr);
    if ( v8 != nullptr )
    {
      if ( v8->id == 1448297545 && (vertexDataStart = v8->vertexDataStart) != 0 )
        v10 = (char *)v8 + vertexDataStart;
      else
        v10 = nullptr;
      v7->vertexdata.pVertexData = v10;
      if ( v8->id == 1448297545 && (tangentDataStart = v8->tangentDataStart) != 0 )
        v12 = (char *)v8 + tangentDataStart;
      else
        v12 = nullptr;
      v7->vertexdata.pTangentData = v12;
    }
    v13 = (const mstudio_modelvertexdata_t *)((char *)&m_pMesh->unused[6] + m_pMesh->modelindex);
    p_vertexdata = &m_pMesh->vertexdata;
    p_vertexdata->modelvertexdata = v13;
    v15 = v13->pVertexData != nullptr ? p_vertexdata : nullptr;
    buildInfo->m_pMeshVertexData = v15;
    if ( v15 == nullptr )
    {
      v16 = mstudiomodel_t::CacheVertexData(
              this: (mstudiomodel_t *)((char *)buildInfo->m_pMesh + buildInfo->m_pMesh->modelindex),
              pModelData: buildInfo->m_pStudioHdr);
      if ( v16 != nullptr && v16->id == 1447248969 && (v17 = v16->vertexDataStart) != 0 )
        v18 = (const thinModelVertices_t *)((char *)v16 + v17);
      else
        v18 = nullptr;
      buildInfo->m_pMeshThinVertexData = v18;
      if ( v18 == nullptr )
        break;
    }
    CStudioRender::AddDecalToMesh(this: v20, build: buildInfo);
    ++buildInfo->m_nGlobalMeshIndex;
    if ( ++i >= v20->m_pSubModel->nummeshes )
      return 1;
    this = v20;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100082B0
// Name: public: void CStudioRender::AddDecal(struct StudioDecalHandle_t__ __near *,struct StudioRenderContext_t const __near &,struct matrix3x4_t __near *,struct studiohdr_t __near *,struct Ray_t const __near &,class Vector const __near &,class IMaterial __near *,float,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStudioRender::AddDecal(
        CStudioRender *this,
        CStudioRender::DecalModelList_t *hDecal,
        StudioRenderContext_t *rc,
        int pBoneToWorld,
        studiohdr_t *pStudioHdr,
        const Ray_t *ray,
        const Vector *decalUp,
        IMaterial *pDecalMaterial,
        float radius,
        int body,
        int noPokethru,
        int maxLODToDecal)
{
  CStudioRender::DecalModelList_t *v12; // edi
  StudioRenderContext_t *v14; // eax
  matrix3x4_t *v15; // ecx
  studiohdr_t *v16; // edx
  IMaterialVar *v17; // eax
  IMaterialSystem_vtbl *v18; // ebx
  int v19; // eax
  IMaterial *v20; // ebx
  studiohdr_t *m_pStudioHdr; // eax
  bool v22; // cc
  int v23; // edx
  int *p_m_RootLOD; // eax
  int v25; // eax
  int v26; // ebx
  char *v27; // eax
  void *v28; // esp
  void *v29; // esp
  int m_RootLOD; // ebx
  CStudioRender::DecalLod_t *m_pLod; // ecx
  __m128i v32; // xmm0
  double v33; // xmm1_8
  int p_m_DecalHistory; // eax
  studiohwdata_t *v35; // edx
  int v36; // eax
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *v37; // ebx
  studiohwdata_t *v38; // edx
  studiohwdata_t *v39; // eax
  int v40; // ebx
  const Ray_t *DecalMaterial; // eax
  studiomeshdata_t *m_pMeshData; // ecx
  UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *m_pDecalMaterial; // eax
  matrix3x4_t *m_Size; // ecx
  studiohdr_t *v45; // edx
  studiohdr_t *v46; // ecx
  studiohdr_t *v47; // ecx
  const Vector *v48; // ecx
  int v49; // eax
  unsigned __int16 v50; // ax
  int v51; // eax
  int m_VertexCount; // edx
  int v53; // eax
  unsigned __int16 v54; // ax
  int v55; // eax
  studiohwdata_t *v56; // edx
  int v57; // eax
  int v58; // ebx
  matrix3x4_t *m_PoseToWorld; // [esp-14h] [ebp-6Ch]
  studiohwdata_t *m_pHardwareData; // [esp-8h] [ebp-60h]
  const matrix3x4_t *v61; // [esp-4h] [ebp-5Ch]
  studiohdr_t *v62; // [esp-4h] [ebp-5Ch]
  MeshVertexInfo_t v63; // [esp+0h] [ebp-58h] BYREF
  CStudioRender::DecalBuildInfo_t buildInfo; // [esp+Ch] [ebp-4Ch] BYREF

  v12 = hDecal;
  if ( hDecal == nullptr || hDecal->m_pHardwareData->m_NumStudioMeshes == 0 )
    return;
  v14 = rc;
  v15 = (matrix3x4_t *)pBoneToWorld;
  v16 = pStudioHdr;
  v61 = (const matrix3x4_t *)pBoneToWorld;
  this->m_pRC = rc;
  this->m_pBoneToWorld = v15;
  m_PoseToWorld = this->m_PoseToWorld;
  this->m_pStudioHdr = v16;
  ComputePoseToWorld(
    pPoseToWorld: m_PoseToWorld,
    pStudioHdr: v16,
    boneMask: 524032,
    vecViewOrigin: &v14->m_ViewOrigin,
    pBoneToWorld: v61);
  if ( CStudioRender::ComputePoseToDecal(this, ray, up: decalUp) == 0 )
  {
    this->m_pStudioHdr = nullptr;
    this->m_pRC = nullptr;
    this->m_pBoneToWorld = nullptr;
    return;
  }
  v17 = pDecalMaterial->FindVar(this: pDecalMaterial, a2: "$modelmaterial", a3: (char *)&hDecal + 3, a4: 0);
  if ( HIBYTE(hDecal) != 0 )
  {
    v18 = g_pMaterialSystem->__vftable;
    v19 = ((int (__thiscall *)(IMaterialVar *, const char *, _DWORD, _DWORD))v17->GetStringValue)(
            a1: v17,
            a2: "Decal textures",
            a3: 0,
            a4: 0);
    v20 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, int))v18->FindMaterial)(a1: g_pMaterialSystem, a2: v19);
    if ( !IsErrorMaterial(pMat: v20) )
      pDecalMaterial = v20;
  }
  buildInfo.m_Radius = radius;
  if ( radius <= 8.0 )
    buildInfo.m_flMaxDepth = 8.0;
  else
    buildInfo.m_flMaxDepth = radius;
  buildInfo.m_NoPokeThru = noPokethru;
  m_pStudioHdr = this->m_pStudioHdr;
  v22 = m_pStudioHdr->numbones <= 1;
  buildInfo.m_pStudioHdr = pStudioHdr;
  if ( !v22 || (buildInfo.m_UseClipVert = true, m_pStudioHdr->numflexdesc != 0) )
    buildInfo.m_UseClipVert = false;
  v23 = maxLODToDecal;
  p_m_RootLOD = &v12->m_pHardwareData->m_RootLOD;
  buildInfo.m_nGlobalMeshIndex = 0;
  buildInfo.m_pMeshVertexData = nullptr;
  if ( maxLODToDecal == -1 )
  {
    v23 = p_m_RootLOD[1];
LABEL_17:
    noPokethru = v23;
    goto LABEL_18;
  }
  noPokethru = p_m_RootLOD[1];
  if ( noPokethru >= maxLODToDecal )
    goto LABEL_17;
LABEL_18:
  v25 = *p_m_RootLOD;
  pBoneToWorld = noPokethru - 1;
  v26 = CStudioRender::ComputeTotalMeshCount(this, iRootLOD: v25, iMaxLOD: noPokethru - 1, body);
  if ( v26 < 255 )
  {
    v28 = alloca(8 * v26);
    m_pHardwareData = v12->m_pHardwareData;
    buildInfo.m_pMeshVertices = &v63;
    v29 = alloca(
            12
          * CStudioRender::ComputeVertexAllocation(
              this,
              iMaxLOD: noPokethru,
              body,
              pHardwareData: m_pHardwareData,
              pMeshVertices: &v63));
    buildInfo.m_pVertexBuffer = (CStudioRender::DecalBuildVertexInfo_t *)&v63;
    CStudioRender::ProjectDecalsOntoMeshes(this, build: &buildInfo, nMeshCount: v26);
    m_RootLOD = v12->m_pHardwareData->m_RootLOD;
    m_pLod = v12->m_pLod;
    v32 = _mm_cvtsi32_si128(this->m_DecalLRU.m_ElementCount);
    pStudioHdr = (studiohdr_t *)v12->m_pHardwareData->m_NumLODs;
    v33 = (double)this->m_pRC->m_Config.maxDecalsPerModel * 1.5;
    p_m_DecalHistory = (int)&m_pLod[m_RootLOD].m_DecalHistory;
    decalUp = (const Vector *)m_RootLOD;
    noPokethru = p_m_DecalHistory;
    if ( _mm_cvtepi32_pd(v32).m128d_f64[0] >= v33 )
    {
      CStudioRender::RetireDecal(
        this,
        list: *(CStudioRender::DecalModelList_t **)this->m_DecalLRU.m_Head,
        nRetireID: *(_WORD *)(this->m_DecalLRU.m_Head + 4),
        iLOD: ***(_DWORD ***)this->m_DecalLRU.m_Head,
        iMaxLOD: *(_DWORD *)(**(_DWORD **)this->m_DecalLRU.m_Head + 4));
      p_m_DecalHistory = noPokethru;
    }
    if ( *(unsigned __int16 *)(p_m_DecalHistory + 18) >= this->m_pRC->m_Config.maxDecalsPerModel )
      CStudioRender::RetireDecal(
        this,
        list: v12,
        nRetireID: *(_WORD *)(*(_DWORD *)p_m_DecalHistory + 12 * *(unsigned __int16 *)(p_m_DecalHistory + 12) + 4),
        iLOD: m_RootLOD,
        iMaxLOD: (int)pStudioHdr);
    v35 = v12->m_pHardwareData;
    rc = (StudioRenderContext_t *)pBoneToWorld;
    if ( pBoneToWorld >= v35->m_RootLOD )
    {
      v36 = 32 * pBoneToWorld;
      for ( noPokethru = 32 * pBoneToWorld; ; v36 = noPokethru )
      {
        v37 = &this->m_DecalMaterial.m_Memory.m_pMemory[(unsigned __int16)CStudioRender::GetDecalMaterial(
                                                                            this,
                                                                            decalLod: (CStudioRender::DecalLod_t *)((char *)v12->m_pLod + v36),
                                                                            pDecalMaterial)];
        while ( v37->m_Element.m_Indices.m_Size > 2048 )
          CStudioRender::RetireDecal(
            this,
            list: v12,
            nRetireID: (*(UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short> **)((char *)&v12->m_pLod->m_DecalHistory.m_Memory.m_pMemory
                                                                                   + noPokethru))[*(unsigned __int16 *)((char *)&v12->m_pLod->m_DecalHistory.m_Head + noPokethru)].m_Element.m_nId,
            iLOD: (int)decalUp,
            iMaxLOD: (int)pStudioHdr);
        v38 = v12->m_pHardwareData;
        noPokethru -= 32;
        rc = (StudioRenderContext_t *)((char *)rc - 1);
        if ( (int)rc < v38->m_RootLOD )
          break;
      }
    }
    v39 = v12->m_pHardwareData;
    HIBYTE(noPokethru) = 0;
    rc = (StudioRenderContext_t *)pBoneToWorld;
    if ( pBoneToWorld >= v39->m_RootLOD )
    {
      v40 = pBoneToWorld;
      do
      {
        DecalMaterial = (const Ray_t *)CStudioRender::GetDecalMaterial(
                                         this,
                                         decalLod: &v12->m_pLod[v40],
                                         pDecalMaterial);
        m_pMeshData = v12->m_pHardwareData->m_pLODs[v40].m_pMeshData;
        ray = DecalMaterial;
        m_pDecalMaterial = &this->m_DecalMaterial.m_Memory.m_pMemory[(unsigned __int16)DecalMaterial];
        this->m_pStudioMeshes = m_pMeshData;
        m_Size = (matrix3x4_t *)m_pDecalMaterial->m_Element.m_Indices.m_Size;
        buildInfo.m_ppMaterials = v12->m_pHardwareData->m_pLODs[v40].ppMaterials;
        v45 = this->m_pStudioHdr;
        pBoneToWorld = (int)m_Size;
        v46 = nullptr;
        buildInfo.m_pDecalMaterial = &m_pDecalMaterial->m_Element;
        *(_DWORD *)&buildInfo.m_FirstVertex = 0xFFFF;
        pStudioHdr = nullptr;
        if ( v45->numbodyparts > 0 )
        {
          while ( 1 )
          {
            v62 = this->m_pStudioHdr;
            buildInfo.m_Body = (int)v46;
            buildInfo.m_Model = R_StudioSetupModel(
                                  bodypart: (int)v46,
                                  entity_body: body,
                                  ppSubModel: &this->m_pSubModel,
                                  pStudioHdr: v62);
            if ( CStudioRender::AddDecalToModel(this, &buildInfo) == 0 )
              break;
            v47 = this->m_pStudioHdr;
            pStudioHdr = (studiohdr_t *)((char *)pStudioHdr + 1);
            if ( (int)pStudioHdr >= v47->numbodyparts )
              break;
            v46 = pStudioHdr;
          }
          m_pDecalMaterial = (UtlLinkedListElem_t<CStudioRender::DecalMaterial_t,unsigned short> *)buildInfo.m_pDecalMaterial;
          v46 = pStudioHdr;
        }
        if ( v46 == (studiohdr_t *)this->m_pStudioHdr->numbodyparts )
        {
          v48 = (const Vector *)(m_pDecalMaterial->m_Element.m_Indices.m_Size - pBoneToWorld);
          decalUp = v48;
          if ( buildInfo.m_VertexCount != 0 || v48 != nullptr )
          {
            HIBYTE(noPokethru) = 1;
            pStudioHdr = (studiohdr_t *)&m_pDecalMaterial->m_Element.m_Decals;
            v49 = CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::AllocInternal(
                    this: &m_pDecalMaterial->m_Element.m_Decals,
                    multilist: false);
            pBoneToWorld = v49;
            if ( (_WORD)v49 == 0xFFFF )
            {
              v50 = -1;
            }
            else
            {
              CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short>>::LinkBefore(
                this: (CUtlLinkedList<CStudioRender::Decal_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::Decal_t,unsigned short>,unsigned short> > *)pStudioHdr,
                before: 0xFFFFu,
                elem: v49);
              v50 = pBoneToWorld;
            }
            LODWORD(radius) = v50;
            v51 = pStudioHdr->id + 24 * v50;
            m_VertexCount = buildInfo.m_VertexCount;
            *(_DWORD *)v51 = decalUp;
            *(_DWORD *)(v51 + 4) = m_VertexCount;
            *(_DWORD *)(v51 + 8) = 0;
            *(_QWORD *)(v51 + 12) = 0;
            pStudioHdr = (studiohdr_t *)&v12->m_pLod[v40].m_DecalHistory;
            v53 = CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::AllocInternal(
                    this: (CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *)pStudioHdr,
                    multilist: false);
            pBoneToWorld = v53;
            if ( (_WORD)v53 == 0xFFFF )
            {
              v54 = -1;
            }
            else
            {
              CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short>>::LinkBefore(
                this: (CUtlLinkedList<CStudioRender::DecalHistory_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CStudioRender::DecalHistory_t,unsigned short>,unsigned short> > *)pStudioHdr,
                before: 0xFFFFu,
                elem: v53);
              v54 = pBoneToWorld;
            }
            v55 = v54;
            v12->m_pLod[v40].m_DecalHistory.m_Memory.m_pMemory[v55].m_Element.m_Material = (unsigned __int16)ray;
            v12->m_pLod[v40].m_DecalHistory.m_Memory.m_pMemory[v55].m_Element.m_Decal = LOWORD(radius);
            v12->m_pLod[v40].m_DecalHistory.m_Memory.m_pMemory[v55].m_Element.m_nId = this->m_nDecalId;
            v12->m_pLod[v40].m_DecalHistory.m_Memory.m_pMemory[v55].m_Element.m_nPad = 0;
          }
        }
        v56 = v12->m_pHardwareData;
        --v40;
        rc = (StudioRenderContext_t *)((char *)rc - 1);
      }
      while ( (int)rc >= v56->m_RootLOD );
      if ( HIBYTE(noPokethru) != 0 )
      {
        v57 = CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::AllocInternal(
                this: &this->m_DecalLRU,
                multilist: false);
        v58 = v57;
        if ( v57 != 0 )
          CUtlLinkedList<CStudioRender::DecalLRU_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalLRU_t,int>>>::LinkBefore(
            this: &this->m_DecalLRU,
            before: 0,
            elem: v57);
        *(_WORD *)(v58 + 4) = this->m_nDecalId;
        *(_DWORD *)v58 = v12;
        ++this->m_nDecalId;
      }
    }
  }
  else
  {
    v27 = studiohdr_t::pszName(this: this->m_pStudioHdr);
    _Warning(a1: "Unable to apply decals to model (%s), it has more than 255 unique meshes!\n", v27);
  }
  this->m_pBoneToWorld = nullptr;
  this->m_pRC = nullptr;
  this->m_pStudioHdr = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100087E0
// Name: public: struct StudioDecalHandle_t__ __near * CStudioRender::CreateDecalList(struct studiohwdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
StudioDecalHandle_t__ *__thiscall CStudioRender::CreateDecalList(CStudioRender *this, studiohwdata_t *pHardwareData)
{
  CThreadFastMutex *p_m_DecalMutex; // edi
  DWORD CurrentThreadId; // ecx
  int v5; // eax
  _DWORD *v6; // esi
  int m_NumLODs; // edi
  int v9; // ecx
  int *v10; // eax
  studiohwdata_t *v11; // eax
  int v12; // ecx
  int *p_m_NumStudioMeshes; // eax
  int v14; // eax
  int v15; // ecx
  studiohwdata_t *pHardwareDataa; // [esp+10h] [ebp+8h]

  if ( pHardwareData == nullptr || pHardwareData->m_NumLODs <= 0 )
    return nullptr;
  p_m_DecalMutex = &this->m_DecalMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_DecalMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_DecalMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_DecalMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_DecalMutex->m_depth;
  }
  v5 = CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::AllocInternal(
         this: &this->m_DecalList,
         multilist: false);
  v6 = (_DWORD *)v5;
  if ( v5 != 0 )
    CUtlLinkedList<CStudioRender::DecalModelList_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CStudioRender::DecalModelList_t,int>>>::LinkBefore(
      this: &this->m_DecalList,
      before: 0,
      elem: v5);
  if ( p_m_DecalMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_DecalMutex, 0);
  *v6 = pHardwareData;
  m_NumLODs = pHardwareData->m_NumLODs;
  v9 = (unsigned __int64)(unsigned int)m_NumLODs >> 27 != 0 ? -1 : 32 * m_NumLODs;
  v10 = (int *)operator new(nSize: __CFADD__(v9, 4) ? -1 : v9 + 4);
  if ( v10 != nullptr )
  {
    *v10 = m_NumLODs;
    v11 = (studiohwdata_t *)(v10 + 1);
    v12 = m_NumLODs - 1;
    pHardwareDataa = v11;
    if ( m_NumLODs - 1 >= 0 )
    {
      p_m_NumStudioMeshes = &v11->m_NumStudioMeshes;
      do
      {
        *(p_m_NumStudioMeshes - 2) = 0;
        *(p_m_NumStudioMeshes - 1) = 0;
        *p_m_NumStudioMeshes = 0;
        *((_WORD *)p_m_NumStudioMeshes + 7) = -1;
        *((_WORD *)p_m_NumStudioMeshes + 2) = -1;
        *((_WORD *)p_m_NumStudioMeshes + 3) = -1;
        *((_WORD *)p_m_NumStudioMeshes + 4) = -1;
        *((_WORD *)p_m_NumStudioMeshes + 5) = 0;
        *((_WORD *)p_m_NumStudioMeshes + 6) = 0;
        p_m_NumStudioMeshes[4] = *(p_m_NumStudioMeshes - 2);
        p_m_NumStudioMeshes += 8;
        --v12;
      }
      while ( v12 >= 0 );
      v11 = pHardwareDataa;
    }
  }
  else
  {
    v11 = nullptr;
  }
  v6[1] = v11;
  v6[2] = pHardwareData->m_NumLODs;
  v14 = 0;
  if ( pHardwareData->m_NumLODs > 0 )
  {
    v15 = 0;
    do
    {
      *(_WORD *)(v15 + v6[1]) = -1;
      ++v14;
      v15 += 32;
    }
    while ( v14 < pHardwareData->m_NumLODs );
  }
  return (StudioDecalHandle_t__ *)v6;
}
