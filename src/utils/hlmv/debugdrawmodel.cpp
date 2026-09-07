// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/debugdrawmodel.cpp
// Functions: 18
// ============================================================

#include "utils\hlmv\debugdrawmodel.h"

//------------------------------------------------------------------------------
// Address: 0x00404AE0
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
// Address: 0x00404B50
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
// Address: 0x00404BD0
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
// Address: 0x00404CA0
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
// Address: 0x00404D00
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
// Address: 0x00404D70
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E70
// Name: public: CMatchedVert::CMatchedVert(struct GetTriangles_Vertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CMatchedVert *__thiscall CMatchedVert::CMatchedVert(CMatchedVert *this, const GetTriangles_Vertex_t *vert)
{
  this->m_pos.x = vert->m_Position.x;
  this->m_pos.y = vert->m_Position.y;
  this->m_pos.z = vert->m_Position.z;
  this->m_bones = vert->m_BoneIndex[0]
                + (((vert->m_BoneIndex[1] <= 0 ? 0 : vert->m_BoneIndex[1])
                  + ((vert->m_BoneIndex[2] <= 0 ? 0 : vert->m_BoneIndex[1]) << 8)) << 8);
  this->m_count = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404EC0
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
// Address: 0x00404F40
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebx
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebx
  IMesh *v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v4 = type;
  v5 = pMesh;
  pMesh = nullptr;
  type = 0;
  v9 = numPrimitives;
  this->m_pMesh = v5;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v4,
    nPrimitiveCount: v9);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  v8 = pMesh;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x00405050
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
// Address: 0x00405110
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(class CMatchedVert const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int v3; // esi
  int v4; // edx
  CMatchedVert *m_pMemory; // edi
  float v6; // xmm0_4
  int result; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = (float)((float)(src->m_pos.y + src->m_pos.x) + src->m_pos.z) + (float)src->m_bones;
    do
    {
      result = (v4 + v3) >> 1;
      if ( v6 <= (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x)
                               + m_pMemory[result].m_pos.z)
                       + (float)m_pMemory[result].m_bones) )
      {
        if ( (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x) + m_pMemory[result].m_pos.z)
                   + (float)m_pMemory[result].m_bones) <= v6 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00405210
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::Find(class CMatchedVert const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int v3; // esi
  int v4; // edx
  CMatchedVert *m_pMemory; // edi
  float v6; // xmm0_4
  int result; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = (float)((float)(src->m_pos.y + src->m_pos.x) + src->m_pos.z) + (float)src->m_bones;
    do
    {
      result = (v4 + v3) >> 1;
      if ( v6 <= (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x)
                               + m_pMemory[result].m_pos.z)
                       + (float)m_pMemory[result].m_bones) )
      {
        if ( (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x) + m_pMemory[result].m_pos.z)
                   + (float)m_pMemory[result].m_bones) <= v6 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00405310
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::Insert(class CMatchedVert const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Insert(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CMatchedVert *m_pMemory; // ecx
  int v8; // eax
  CMatchedVert *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 150);
  }
  LessOrEqual = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      (CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 20 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00405550
// Name: int DebugDrawModelBadVerts(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __usercall DebugDrawModelBadVerts@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // edi
  float *v8; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  float v10; // eax
  float v11; // xmm0_4
  int v12; // edi
  int v13; // xmm1_4
  float *v14; // edx
  const float *v15; // ecx
  const matrix3x4_t *v16; // esi
  float v17; // xmm3_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  int v20; // eax
  int v21; // eax
  __int64 v22; // xmm1_8
  _QWORD *v23; // eax
  __int128 v24; // xmm1
  __int128 v25; // xmm2
  float v26; // xmm1_4
  float x; // ecx
  float v28; // edi
  int v29; // eax
  int v30; // eax
  _BYTE v32[12]; // [esp-Ch] [ebp-284h] BYREF
  _BYTE meshBuilder_168[324]; // [esp+A8h] [ebp-1D0h] OVERLAPPED BYREF
  float v34; // [esp+1F8h] [ebp-80h]
  int v35; // [esp+1FCh] [ebp-7Ch]
  float *v36; // [esp+200h] [ebp-78h]
  int v37; // [esp+204h] [ebp-74h]
  IMatRenderContext *v38; // [esp+208h] [ebp-70h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+20Ch] [ebp-6Ch]
  const float *v40; // [esp+210h] [ebp-68h]
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-64h]
  __int64 pBuildMesh; // [esp+218h] [ebp-60h] OVERLAPPED
  _BYTE k[20]; // [esp+220h] [ebp-58h] OVERLAPPED
  const Vector *normal; // [esp+234h] [ebp-44h]
  int batchID; // [esp+238h] [ebp-40h]
  Vector skinnedPos; // [esp+23Ch] [ebp-3Ch] BYREF
  int indexStart; // [esp+248h] [ebp-30h]
  Vector tmp; // [esp+24Ch] [ebp-2Ch] BYREF
  Vector skinnedNormal; // [esp+258h] [ebp-20h]
  int v50; // [esp+264h] [ebp-14h]
  int v51; // [esp+268h] [ebp-10h]
  int v52; // [esp+26Ch] [ebp-Ch]
  int vertID; // [esp+270h] [ebp-8h]
  int retaddr; // [esp+278h] [ebp+0h]

  v52 = a1;
  vertID = retaddr;
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    tris.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris.m_MaterialBatches.m_Size = 0;
    tris.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  ((void (__thiscall *)(IStudioRender *, DrawModelInfo_t *, matrix3x4_t *, GetTriangles_Output_t *, int, int))pStudioRender->GetTriangles)(
    a1: pStudioRender,
    a2: info,
    a3: pBoneToWorld,
    a4: &tris,
    a5: a2,
    a6: a3);
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  v38 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v7->MatrixMode(this: v7, a2: MATERIAL_MODEL);
  v7->PushMatrix(this: v7);
  v7->LoadIdentity(this: v7);
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)v32);
  *(_DWORD *)&k[12] = 0;
  if ( tris.m_MaterialBatches.m_Size > 0 )
  {
    skinnedNormal.z = 0.0;
    do
    {
      v8 = (float *)((char *)tris.m_MaterialBatches.m_Memory.m_pMemory + LODWORD(skinnedNormal.z));
      Bind = v7->Bind;
      v36 = (float *)((char *)tris.m_MaterialBatches.m_Memory.m_pMemory + LODWORD(skinnedNormal.z));
      Bind(this: v7, a2: g_materialVertexColor, a3: nullptr);
      materialBatch = (GetTriangles_MaterialBatch_t *)v7->GetDynamicMesh(
                                                        this: v7,
                                                        a2: false,
                                                        a3: nullptr,
                                                        a4: nullptr,
                                                        a5: nullptr);
      v10 = v8[9];
      skinnedPos.x = 0.0;
      if ( SLODWORD(v10) > 0 )
      {
        do
        {
          skinnedNormal.x = v10;
          if ( SLODWORD(v10) >= 32766 )
            LODWORD(skinnedNormal.x) = 32766;
          CMeshBuilder::Begin(
            this: (CMeshBuilder *)v32,
            pMesh: (IMesh *)materialBatch,
            type: MATERIAL_TRIANGLES,
            nVertexCount: *((_DWORD *)v8 + 4),
            nIndexCount: SLODWORD(skinnedNormal.x),
            pMeshSettings: nullptr);
          v50 = 0;
          if ( *((int *)v8 + 4) > 0 )
          {
            skinnedNormal.y = 0.0;
            do
            {
              v11 = 0.0;
              v12 = LODWORD(skinnedNormal.y) + *((_DWORD *)v8 + 1);
              *(_DWORD *)&k[16] = 0;
              v13 = *(_DWORD *)(v12 + 36);
              v14 = (float *)(v12 + 12);
              v15 = (const float *)(v12 + 24);
              *(_DWORD *)&k[8] = v12 + 12;
              v40 = (const float *)(v12 + 24);
              *(float *)&normal = 0.0;
              *(float *)&batchID = 0.0;
              memset(&tmp, 0, sizeof(tmp));
              pBuildMesh = 0;
              *(_DWORD *)k = 0;
              *(_DWORD *)&k[4] = v13;
              pRenderContext.m_pObject = nullptr;
              if ( *(int *)(v12 + 80) > 0 )
              {
                v51 = v12 + 48;
                do
                {
                  v16 = &tris.m_PoseToWorld[*(_DWORD *)(v51 + 16)];
                  VectorTransform(in1: (const float *)v12, in2: v16, out: &skinnedPos.y);
                  v17 = *(float *)v51;
                  *(float *)&k[16] = (float)(skinnedPos.y * *(float *)v51) + *(float *)&k[16];
                  *(float *)&normal = (float)(skinnedPos.z * v17) + *(float *)&normal;
                  *(float *)&batchID = (float)(*(float *)&indexStart * v17) + *(float *)&batchID;
                  VectorRotate(in1: *(const float **)&k[8], in2: v16, out: &skinnedPos.y);
                  v18 = *(float *)v51;
                  tmp.z = (float)(*(float *)&indexStart * *(float *)v51) + tmp.z;
                  VectorRotate(
                    in1: v40,
                    in2: COERCE_CONST_MATRIX3X4_T_((float)(skinnedPos.y * v18) + tmp.x),
                    out: COERCE_FLOAT_((float)(skinnedPos.z * v18) + COERCE_FLOAT((Vector *)&skinnedPos.y)));
                  v19 = *(float *)v51;
                  *(float *)&pBuildMesh = (float)(skinnedPos.y * *(float *)v51) + *(float *)&pBuildMesh;
                  *((float *)&pBuildMesh + 1) = (float)(skinnedPos.z * v19) + *((float *)&pBuildMesh + 1);
                  *(float *)k = (float)(*(float *)&indexStart * v19) + *(float *)k;
                  ++pRenderContext.m_pObject;
                  v51 += 4;
                }
                while ( (int)pRenderContext.m_pObject < *(_DWORD *)(v12 + 80) );
                v11 = 0.0;
                v15 = v40;
                v14 = *(float **)&k[8];
                v8 = v36;
              }
              v20 = *(_DWORD *)&meshBuilder_168[248];
              **(_DWORD **)&meshBuilder_168[248] = *(_DWORD *)&k[16];
              *(float *)(v20 + 4) = *(float *)&normal;
              *(float *)(v20 + 8) = *(float *)&batchID;
              **(Vector **)&meshBuilder_168[252] = tmp;
              v21 = *(_DWORD *)&meshBuilder_168[260];
              v22 = pBuildMesh;
              **(float **)&meshBuilder_168[260] = *(float *)(v12 + 40);
              *(float *)(v21 + 4) = *(float *)(v12 + 44);
              v23 = (_QWORD *)(*(_DWORD *)&meshBuilder_168[216]
                             + *(_DWORD *)&meshBuilder_168[244] * *(_DWORD *)&meshBuilder_168[132]);
              *v23 = v22;
              v23[1] = *(_QWORD *)k;
              v24 = 0;
              *(float *)&v24 = fsqrt((float)((float)(*v15 * *v15) + (float)(v15[1] * v15[1])) + (float)(v15[2] * v15[2]));
              *(_OWORD *)&meshBuilder_168[308] = v24;
              if ( *(float *)&v24 < 0.89999998 || *(float *)&meshBuilder_168[308] > 1.1 )
                v11 = 1.0;
              v25 = 0;
              *(float *)&v25 = fsqrt((float)((float)(*v14 * *v14) + (float)(v14[1] * v14[1])) + (float)(v14[2] * v14[2]));
              *(_OWORD *)&meshBuilder_168[308] = v25;
              if ( *(float *)&v25 < 0.89999998 || *(float *)&meshBuilder_168[308] > 1.1 )
                v11 = 1.0;
              v26 = (float)((float)(v14[1] * v15[1]) + (float)(*v15 * *v14)) + (float)(v14[2] * v15[2]);
              if ( v26 > 0.95 || v26 < -0.95 )
                v11 = 1.0;
              v37 = 1258291200;
              v35 = 1258291200;
              v34 = (float)(v11 * 255.0) + 8388608.0;
              **(_DWORD **)&meshBuilder_168[256] = (LOBYTE(v34) | 0xFFFFFF00) << 16;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_168[64]);
              LODWORD(skinnedNormal.y) += 84;
              ++v50;
            }
            while ( v50 < *((_DWORD *)v8 + 4) );
          }
          x = skinnedPos.x;
          LODWORD(v28) = LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x);
          v50 = LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x);
          if ( SLODWORD(skinnedPos.x) < LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x) )
          {
            v29 = *(_DWORD *)&meshBuilder_168[44];
            do
            {
              *(_WORD *)(*(_DWORD *)&meshBuilder_168[12] + 2 * v29) = *(_WORD *)&meshBuilder_168[40]
                                                                    + *(_WORD *)(*((_DWORD *)v8 + 6) + 4 * LODWORD(x));
              v29 = *(_DWORD *)&meshBuilder_168[24] + *(_DWORD *)&meshBuilder_168[44];
              v28 = *(float *)&v50;
              ++LODWORD(x);
              *(_DWORD *)&meshBuilder_168[44] = v29;
              *(_DWORD *)&meshBuilder_168[36] = v29;
            }
            while ( SLODWORD(x) < v50 );
          }
          if ( meshBuilder_168[8] != 0 )
          {
            switch ( *(_DWORD *)&meshBuilder_168[4] )
            {
              case 4:
                v30 = 2 * *(_DWORD *)&meshBuilder_168[240] - 2;
                break;
              case 5:
                v30 = 2 * *(_DWORD *)&meshBuilder_168[240];
                break;
              case 6:
                v30 = 3 * *(_DWORD *)&meshBuilder_168[240] - 6;
                break;
              case 7:
                v30 = 6 * *(_DWORD *)&meshBuilder_168[240] / 4;
                break;
              case 0xA:
                v30 = 0;
                break;
              default:
                v30 = *(_DWORD *)&meshBuilder_168[240];
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: (CIndexBuilder *)&meshBuilder_168[12],
              primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder_168[4],
              nIndexCount: v30);
          }
          (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _BYTE *))(**(_DWORD **)meshBuilder_168 + 80))(
            a1: *(_DWORD *)meshBuilder_168,
            a2: *(_DWORD *)&meshBuilder_168[240],
            a3: *(_DWORD *)&meshBuilder_168[36],
            a4: v32);
          *(_DWORD *)&meshBuilder_168[28] = 0;
          *(_DWORD *)&meshBuilder_168[32] = 0;
          *(_DWORD *)&meshBuilder_168[236] = 0;
          *(_DWORD *)&meshBuilder_168[228] = 0;
          *(_DWORD *)meshBuilder_168 = 0;
          *(_DWORD *)&meshBuilder_168[140] = -1;
          ((void (__thiscall *)(GetTriangles_MaterialBatch_t *, int, _DWORD))materialBatch->m_pMaterial[12].__vftable)(
            a1: materialBatch,
            a2: -1,
            a3: 0);
          v10 = v8[9];
          skinnedPos.x = v28;
        }
        while ( SLODWORD(v28) < SLODWORD(v10) );
        v7 = v38;
      }
      LODWORD(skinnedNormal.z) += 44;
      ++*(_DWORD *)&k[12];
    }
    while ( *(int *)&k[12] < tris.m_MaterialBatches.m_Size );
  }
  v7->MatrixMode(this: v7, a2: MATERIAL_MODEL);
  v7->PopMatrix(this: v7);
  if ( *(_DWORD *)&meshBuilder_168[228] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[228] + 8))(a1: *(_DWORD *)&meshBuilder_168[228]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[228] + 16))(a1: *(_DWORD *)&meshBuilder_168[228]);
  }
  if ( *(_DWORD *)&meshBuilder_168[28] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[28] + 8))(a1: *(_DWORD *)&meshBuilder_168[28]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[28] + 16))(a1: *(_DWORD *)&meshBuilder_168[28]);
  }
  v7->EndRender(this: v7);
  v7->Release(this: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405BE0
// Name: int DebugDrawModelWireframe(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelWireframe(
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld,
        const Vector *modelOrigin,
        const Vector *color)
{
  IMatRenderContext *v5; // eax
  IMatRenderContext *m_pObject; // edi
  GetTriangles_MaterialBatch_t *v7; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  GetTriangles_Vertex_t *v10; // edi
  Vector4D *p_m_BoneWeight; // ebx
  const matrix3x4_t *v12; // esi
  float x; // xmm3_4
  float v14; // xmm3_4
  float v15; // xmm3_4
  float *v16; // eax
  __int64 v17; // xmm0_8
  _QWORD *v18; // eax
  int v19; // ecx
  int v20; // edi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-24Ch] BYREF
  float v25; // [esp+1F0h] [ebp-64h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-60h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+1F8h] [ebp-5Ch]
  float v28; // [esp+1FCh] [ebp-58h]
  float v29; // [esp+200h] [ebp-54h]
  int batchID; // [esp+204h] [ebp-50h]
  int k; // [esp+208h] [ebp-4Ch]
  Vector4D skinnedTangentS; // [esp+20Ch] [ebp-48h] BYREF
  int vertID; // [esp+21Ch] [ebp-38h]
  IMesh *pBuildMesh; // [esp+220h] [ebp-34h]
  Vector skinnedPos; // [esp+224h] [ebp-30h] BYREF
  Vector skinnedNormal; // [esp+230h] [ebp-24h] BYREF
  Vector tmp; // [esp+23Ch] [ebp-18h] BYREF
  int nClampedIndices; // [esp+248h] [ebp-Ch]
  unsigned int v39; // [esp+24Ch] [ebp-8h]
  unsigned int v40; // [esp+250h] [ebp-4h]
  int indexStart; // [esp+25Ch] [ebp+8h]

  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    tris_0.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_0.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_0.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_0.m_MaterialBatches.m_Size = 0;
    tris_0.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_0);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  m_pObject = v5;
  pRenderContext.m_pObject = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  batchID = 0;
  if ( tris_0.m_MaterialBatches.m_Size > 0 )
  {
    v40 = 0;
    do
    {
      v7 = &tris_0.m_MaterialBatches.m_Memory.m_pMemory[v40 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_0.m_MaterialBatches.m_Memory.m_pMemory[v40 / 0x2C];
      Bind(this: m_pObject, a2: g_materialWireframeVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v7->m_TriListIndices.m_Size;
      indexStart = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nClampedIndices = m_Size - indexStart;
          if ( m_Size - indexStart >= 32766 )
            nClampedIndices = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v7->m_Verts.m_Size,
            nIndexCount: nClampedIndices,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v7->m_Verts.m_Size > 0 )
          {
            v39 = 0;
            do
            {
              v10 = &v7->m_Verts.m_Memory.m_pMemory[v39 / 0x54];
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              memset(&skinnedTangentS, 0, 12);
              skinnedTangentS.w = v10->m_TangentS.w;
              k = 0;
              if ( v10->m_NumBones > 0 )
              {
                p_m_BoneWeight = &v10->m_BoneWeight;
                do
                {
                  v12 = &tris_0.m_PoseToWorld[LODWORD(p_m_BoneWeight[1].x)];
                  VectorTransform(in1: &v10->m_Position.x, in2: v12, out: &tmp.x);
                  x = p_m_BoneWeight->x;
                  skinnedPos.x = (float)(tmp.x * p_m_BoneWeight->x) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * x) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * x) + skinnedPos.z;
                  VectorRotate(in1: &v10->m_Normal.x, in2: v12, out: &tmp.x);
                  v14 = p_m_BoneWeight->x;
                  skinnedNormal.x = (float)(tmp.x * p_m_BoneWeight->x) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v14) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v14) + skinnedNormal.z;
                  VectorRotate(in1: &v10->m_TangentS.x, in2: v12, out: &tmp.x);
                  v15 = p_m_BoneWeight->x;
                  p_m_BoneWeight = (Vector4D *)((char *)p_m_BoneWeight + 4);
                  skinnedTangentS.x = (float)(tmp.x * v15) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v15) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v15) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < v10->m_NumBones );
                v7 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v10->m_TexCoord.x;
              v17 = *(_QWORD *)&skinnedTangentS.x;
              v16[1] = v10->m_TexCoord.y;
              v18 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v18 = v17;
              v18[1] = *(_QWORD *)&skinnedTangentS.z;
              v28 = (float)(color->z * 255.0) + 8388608.0;
              v25 = (float)(color->y * 255.0) + 8388608.0;
              v29 = (float)(color->x * 255.0) + 8388608.0;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v28)
                                                                  | ((LOBYTE(v25) | ((LOBYTE(v29) | 0xFFFFFF00) << 8)) << 8);
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v39 += 84;
              ++vertID;
            }
            while ( vertID < v7->m_Verts.m_Size );
          }
          v19 = indexStart;
          v20 = indexStart + nClampedIndices;
          if ( indexStart < indexStart + nClampedIndices )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v7->m_TriListIndices.m_Memory.m_pMemory[v19]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v19;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v19 < v20 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v7->m_TriListIndices.m_Size;
          indexStart = v20;
        }
        while ( v20 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v40 += 44;
      ++batchID;
    }
    while ( batchID < tris_0.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406150
// Name: int DebugDrawModelBoneWeights(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelBoneWeights(IStudioRender *pStudioRender, DrawModelInfo_t *info, matrix3x4_t *pBoneToWorld)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *m_pObject; // esi
  GetTriangles_MaterialBatch_t *v5; // ebx
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  float v8; // xmm0_4
  char *v9; // edi
  bool v10; // cc
  float v11; // xmm1_4
  char *v12; // ebx
  const matrix3x4_t *v13; // esi
  float v14; // xmm3_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  float *v17; // eax
  __int64 v18; // xmm1_8
  _QWORD *v19; // eax
  int v20; // edx
  int v21; // ebx
  float v22; // xmm2_4
  unsigned int v23; // ecx
  char *v24; // eax
  int v25; // edi
  int v26; // edx
  int v27; // ecx
  char v28; // dl
  int v29; // ecx
  int v30; // esi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-28Ch] BYREF
  int v35; // [esp+1F0h] [ebp-A4h]
  int v36; // [esp+1F4h] [ebp-A0h]
  int v37; // [esp+1F8h] [ebp-9Ch]
  float v38; // [esp+1FCh] [ebp-98h]
  int v39; // [esp+200h] [ebp-94h]
  int v40; // [esp+204h] [ebp-90h]
  int v41; // [esp+208h] [ebp-8Ch]
  float v42; // [esp+20Ch] [ebp-88h]
  int v43; // [esp+210h] [ebp-84h]
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-80h]
  int v45; // [esp+218h] [ebp-7Ch]
  int v46; // [esp+21Ch] [ebp-78h]
  int v47; // [esp+220h] [ebp-74h]
  int v48; // [esp+224h] [ebp-70h]
  int v49; // [esp+228h] [ebp-6Ch]
  int v50; // [esp+22Ch] [ebp-68h]
  int v51; // [esp+230h] [ebp-64h]
  int v52; // [esp+234h] [ebp-60h]
  int v53; // [esp+238h] [ebp-5Ch]
  int v54; // [esp+23Ch] [ebp-58h]
  IMesh *pBuildMesh; // [esp+240h] [ebp-54h]
  int k; // [esp+244h] [ebp-50h]
  Vector4D skinnedTangentS; // [esp+248h] [ebp-4Ch] BYREF
  int batchID; // [esp+258h] [ebp-3Ch]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+25Ch] [ebp-38h]
  int vertID; // [esp+260h] [ebp-34h]
  Vector skinnedPos; // [esp+264h] [ebp-30h] BYREF
  Vector skinnedNormal; // [esp+270h] [ebp-24h] BYREF
  Vector tmp; // [esp+27Ch] [ebp-18h] BYREF
  int indexStart; // [esp+288h] [ebp-Ch]
  int nIndexCount; // [esp+28Ch] [ebp-8h]
  unsigned int v66; // [esp+290h] [ebp-4h]
  IStudioRender *pStudioRendera; // [esp+29Ch] [ebp+8h]

  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    tris_1.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_1.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_1.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_1.m_MaterialBatches.m_Size = 0;
    tris_1.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_1);
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  m_pObject = v3;
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  batchID = 0;
  if ( tris_1.m_MaterialBatches.m_Size > 0 )
  {
    v66 = 0;
    do
    {
      v5 = &tris_1.m_MaterialBatches.m_Memory.m_pMemory[v66 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_1.m_MaterialBatches.m_Memory.m_pMemory[v66 / 0x2C];
      Bind(this: m_pObject, a2: g_materialVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v5->m_TriListIndices.m_Size;
      indexStart = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nIndexCount = m_Size;
          if ( m_Size >= 32766 )
            nIndexCount = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v5->m_Verts.m_Size,
            nIndexCount,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v5->m_Verts.m_Size > 0 )
          {
            pStudioRendera = nullptr;
            do
            {
              v8 = 0.0;
              v9 = (char *)pStudioRendera + (unsigned int)v5->m_Verts.m_Memory.m_pMemory;
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              v10 = *((_DWORD *)v9 + 20) <= 0;
              v11 = *((float *)v9 + 9);
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              memset(&skinnedTangentS, 0, 12);
              skinnedTangentS.w = v11;
              k = 0;
              if ( !v10 )
              {
                v12 = v9 + 48;
                do
                {
                  v13 = &tris_1.m_PoseToWorld[*((_DWORD *)v12 + 4)];
                  VectorTransform(in1: (const float *)v9, in2: v13, out: &tmp.x);
                  v14 = *(float *)v12;
                  skinnedPos.x = (float)(tmp.x * *(float *)v12) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * v14) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * v14) + skinnedPos.z;
                  VectorRotate(in1: (const float *)v9 + 3, in2: v13, out: &tmp.x);
                  v15 = *(float *)v12;
                  skinnedNormal.x = (float)(tmp.x * *(float *)v12) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v15) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v15) + skinnedNormal.z;
                  VectorRotate(in1: (const float *)v9 + 6, in2: v13, out: &tmp.x);
                  v16 = *(float *)v12;
                  v12 += 4;
                  skinnedTangentS.x = (float)(tmp.x * v16) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v16) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v16) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < *((_DWORD *)v9 + 20) );
                v8 = 0.0;
                v5 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v18 = *(_QWORD *)&skinnedTangentS.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *((float *)v9 + 10);
              v17[1] = *((float *)v9 + 11);
              v19 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v19 = v18;
              v19[1] = *(_QWORD *)&skinnedTangentS.z;
              if ( g_viewerSettings.highlightBone < 0 )
              {
                switch ( *((_DWORD *)v9 + 20) )
                {
                  case 0:
                    v51 = 1258291200;
                    v43 = 1258291200;
                    v36 = 1258291200;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
                    break;
                  case 1:
                    v41 = 1258291200;
                    v27 = 0;
                    v54 = 1258291455;
                    v35 = 1258291200;
                    v28 = 0;
                    goto LABEL_44;
                  case 2:
                    v45 = 1258291200;
                    v37 = 1258291455;
                    v47 = 1258291455;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
                    break;
                  case 3:
                    v52 = 1258291200;
                    v53 = 1258291200;
                    v39 = 1258291455;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
                    break;
                  default:
                    v46 = 1258291455;
                    v27 = 255;
                    v48 = 1258291455;
                    v50 = 1258291455;
                    v28 = -1;
LABEL_44:
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v27
                                                                        | ((((*(_DWORD *)&v28 | 0xFFFFFF00) << 8) | 0xFF) << 8);
                    break;
                }
              }
              else
              {
                v20 = *((_DWORD *)v9 + 20);
                v21 = 0;
                v22 = 0.0;
                if ( v20 >= 4 )
                {
                  v23 = ((unsigned int)(v20 - 4) >> 2) + 1;
                  v24 = v9 + 48;
                  v21 = 4 * v23;
                  do
                  {
                    if ( *((_DWORD *)v24 + 4) == g_viewerSettings.highlightBone )
                      v22 = *(float *)v24;
                    if ( *((_DWORD *)v24 + 5) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 1);
                    if ( *((_DWORD *)v24 + 6) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 2);
                    if ( *((_DWORD *)v24 + 7) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 3);
                    v24 += 16;
                    --v23;
                  }
                  while ( v23 != 0 );
                }
                if ( v21 < v20 )
                {
                  v25 = (int)&v9[4 * v21 + 48];
                  v26 = v20 - v21;
                  do
                  {
                    if ( *(_DWORD *)(v25 + 16) == g_viewerSettings.highlightBone )
                      v22 = *(float *)v25;
                    v25 += 4;
                    --v26;
                  }
                  while ( v26 != 0 );
                }
                if ( v22 >= 0.0 )
                {
                  if ( v22 <= 1.0 )
                    v8 = v22;
                  else
                    v8 = 1.0;
                }
                v5 = materialBatch;
                v38 = (float)((float)(1.0 - v8) * 255.0) + 8388608.0;
                v40 = 1258291455;
                v42 = v38;
                v49 = 1258291328;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v38)
                                                                    | ((((LOBYTE(v38) | 0x8000) << 8) | 0xFF) << 8);
              }
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              pStudioRendera += 21;
              ++vertID;
            }
            while ( vertID < v5->m_Verts.m_Size );
          }
          v29 = indexStart;
          v30 = indexStart + nIndexCount;
          if ( indexStart < indexStart + nIndexCount )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v5->m_TriListIndices.m_Memory.m_pMemory[v29]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v29;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v29 < v30 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v5->m_TriListIndices.m_Size;
          indexStart = v30;
        }
        while ( v30 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v66 += 44;
      ++batchID;
    }
    while ( batchID < tris_1.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004068E0
// Name: int DebugDrawModelVertColocation(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall DebugDrawModelVertColocation@<eax>(
        int a1@<edi>,
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld)
{
  unsigned int v4; // eax
  DrawModelInfo_t *v5; // eax
  unsigned int v6; // edx
  GetTriangles_MaterialBatch_t *m_pMemory; // edx
  DrawModelInfo_t *v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // eax
  IMatRenderContext *m_pObject; // esi
  GetTriangles_MaterialBatch_t *v13; // edi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  char *v16; // esi
  int v17; // eax
  bool v18; // zf
  bool v19; // sf
  int v20; // eax
  float v21; // xmm0_4
  char *v22; // ebx
  const matrix3x4_t *v23; // edi
  float v24; // xmm3_4
  float v25; // xmm3_4
  float v26; // xmm3_4
  float *v27; // eax
  __int64 v28; // xmm0_8
  _QWORD *v29; // eax
  int v30; // eax
  int m_count; // eax
  int v32; // ecx
  char v33; // dl
  int v34; // ecx
  int v35; // esi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-2A0h] BYREF
  CMatchedVert mv; // [esp+1F0h] [ebp-B8h] BYREF
  CMatchedVert src; // [esp+204h] [ebp-A4h] BYREF
  int v43; // [esp+218h] [ebp-90h]
  int v44; // [esp+21Ch] [ebp-8Ch]
  int v45; // [esp+220h] [ebp-88h]
  int v46; // [esp+224h] [ebp-84h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+228h] [ebp-80h]
  int v48; // [esp+22Ch] [ebp-7Ch]
  int v49; // [esp+230h] [ebp-78h]
  int v50; // [esp+234h] [ebp-74h]
  int v51; // [esp+238h] [ebp-70h]
  int v52; // [esp+23Ch] [ebp-6Ch]
  int v53; // [esp+240h] [ebp-68h]
  CMatRenderContextPtr pRenderContext; // [esp+244h] [ebp-64h]
  int v55; // [esp+248h] [ebp-60h]
  int v56; // [esp+24Ch] [ebp-5Ch]
  int v57; // [esp+250h] [ebp-58h]
  int v58; // [esp+254h] [ebp-54h]
  int v59; // [esp+258h] [ebp-50h]
  int k; // [esp+25Ch] [ebp-4Ch]
  Vector4D skinnedTangentS; // [esp+260h] [ebp-48h] BYREF
  int vertID; // [esp+270h] [ebp-38h]
  Vector skinnedPos; // [esp+274h] [ebp-34h] BYREF
  Vector skinnedNormal; // [esp+280h] [ebp-28h] BYREF
  Vector tmp; // [esp+28Ch] [ebp-1Ch] BYREF
  int nClampedIndices; // [esp+298h] [ebp-10h]
  unsigned int v67; // [esp+29Ch] [ebp-Ch]
  int batchID; // [esp+2A0h] [ebp-8h]
  IMesh *pBuildMesh; // [esp+2A4h] [ebp-4h]
  int indexStart; // [esp+2B0h] [ebp+8h]
  int indexStarta; // [esp+2B0h] [ebp+8h]
  DrawModelInfo_t *infoa; // [esp+2B4h] [ebp+Ch]
  DrawModelInfo_t *infob; // [esp+2B4h] [ebp+Ch]

  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    tris_2.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_2.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_2.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_2.m_MaterialBatches.m_Size = 0;
    tris_2.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_2);
  v4 = _S8;
  if ( (_S8 & 2) == 0 )
  {
    v4 = _S8 | 2;
    _S8 |= 2u;
  }
  if ( (v4 & 4) == 0 )
  {
    _S8 = v4 | 4;
    sortedVector.m_Memory.m_pMemory = nullptr;
    sortedVector.m_Memory.m_nAllocationCount = 0;
    sortedVector.m_Memory.m_nGrowSize = 0;
    sortedVector.m_Size = 0;
    sortedVector.m_pElements = nullptr;
    sortedVector.m_pLessContext = nullptr;
    sortedVector.m_bNeedsSort = false;
    atexit(func: DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__);
  }
  v5 = &cached_info;
  v6 = 480;
  while ( *(studiohdr_t **)((char *)&v5->m_pStudioHdr + (char *)info - (char *)&cached_info) == v5->m_pStudioHdr )
  {
    v6 -= 4;
    v5 = (DrawModelInfo_t *)((char *)v5 + 4);
    if ( v6 < 4 )
      goto LABEL_21;
  }
  sortedVector.m_Size = 0;
  cached_info = *info;
  indexStart = 0;
  if ( tris_2.m_MaterialBatches.m_Size > 0 )
  {
    m_pMemory = tris_2.m_MaterialBatches.m_Memory.m_pMemory;
    v8 = nullptr;
    infoa = nullptr;
    do
    {
      v9 = 0;
      pBuildMesh = (IMesh *)((char *)&m_pMemory->m_Verts.m_Size + (_DWORD)v8);
      if ( (int)pBuildMesh->IVertexBuffer::__vftable > 0 )
      {
        batchID = (int)&m_pMemory->m_Verts + (_DWORD)v8;
        v10 = 0;
        do
        {
          CMatchedVert::CMatchedVert(this: &mv, vert: (const GetTriangles_Vertex_t *)(v10 + *(_DWORD *)batchID));
          v11 = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(this: &sortedVector, src: &mv);
          if ( v11 == -1 )
            CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Insert(this: &sortedVector, src: &mv);
          else
            ++sortedVector.m_Memory.m_pMemory[v11].m_count;
          ++v9;
          v10 += 84;
        }
        while ( v9 < (int)pBuildMesh->IVertexBuffer::__vftable );
        m_pMemory = tris_2.m_MaterialBatches.m_Memory.m_pMemory;
        v8 = infoa;
      }
      v8 = (DrawModelInfo_t *)((char *)v8 + 44);
      ++indexStart;
      infoa = v8;
    }
    while ( indexStart < tris_2.m_MaterialBatches.m_Size );
  }
LABEL_21:
  m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                     a1: g_pMaterialSystem,
                                     a2: a1);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_bGenerateIndices = false;
  memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
  memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
  meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  batchID = 0;
  if ( tris_2.m_MaterialBatches.m_Size > 0 )
  {
    v67 = 0;
    do
    {
      v13 = &tris_2.m_MaterialBatches.m_Memory.m_pMemory[v67 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_2.m_MaterialBatches.m_Memory.m_pMemory[v67 / 0x2C];
      Bind(this: m_pObject, a2: g_materialVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v13->m_TriListIndices.m_Size;
      indexStarta = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nClampedIndices = m_Size - indexStarta;
          if ( m_Size - indexStarta >= 32766 )
            nClampedIndices = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v13->m_Verts.m_Size,
            nIndexCount: nClampedIndices,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v13->m_Verts.m_Size > 0 )
          {
            infob = nullptr;
            do
            {
              v16 = (char *)infob + (unsigned int)v13->m_Verts.m_Memory.m_pMemory;
              v17 = *((_DWORD *)v16 + 17);
              src.m_pos.x = *(float *)v16;
              src.m_pos.y = *((float *)v16 + 1);
              v18 = *((_DWORD *)v16 + 18) == 0;
              v19 = *((int *)v16 + 18) < 0;
              src.m_pos.z = *((float *)v16 + 2);
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              v20 = *((_DWORD *)v16 + 16) + (((v17 <= 0 ? 0 : v17) + ((v19 || v18 ? 0 : v17) << 8)) << 8);
              memset(&skinnedTangentS, 0, 12);
              v21 = *((float *)v16 + 9);
              src.m_bones = v20;
              src.m_count = 1;
              skinnedTangentS.w = v21;
              k = 0;
              if ( *((int *)v16 + 20) > 0 )
              {
                v22 = v16 + 48;
                do
                {
                  v23 = &tris_2.m_PoseToWorld[*((_DWORD *)v22 + 4)];
                  VectorTransform(in1: (const float *)v16, in2: v23, out: &tmp.x);
                  v24 = *(float *)v22;
                  skinnedPos.x = (float)(tmp.x * *(float *)v22) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * v24) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * v24) + skinnedPos.z;
                  VectorRotate(in1: (const float *)v16 + 3, in2: v23, out: &tmp.x);
                  v25 = *(float *)v22;
                  skinnedNormal.x = (float)(tmp.x * *(float *)v22) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v25) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v25) + skinnedNormal.z;
                  VectorRotate(in1: (const float *)v16 + 6, in2: v23, out: &tmp.x);
                  v26 = *(float *)v22;
                  v22 += 4;
                  skinnedTangentS.x = (float)(tmp.x * v26) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v26) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v26) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < *((_DWORD *)v16 + 20) );
                v13 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v28 = *(_QWORD *)&skinnedTangentS.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *((float *)v16 + 10);
              v27[1] = *((float *)v16 + 11);
              v29 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v29 = v28;
              v29[1] = *(_QWORD *)&skinnedTangentS.z;
              v30 = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(this: &sortedVector, &src);
              if ( v30 < 0 )
                m_count = 0;
              else
                m_count = sortedVector.m_Memory.m_pMemory[v30].m_count;
              switch ( m_count )
              {
                case 0:
                  v48 = 1258291200;
                  v50 = 1258291200;
                  v52 = 1258291200;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
                  break;
                case 1:
                  v43 = 1258291455;
                  v32 = 255;
                  v57 = 1258291200;
                  v46 = 1258291200;
                  v33 = 0;
                  goto LABEL_43;
                case 2:
                  v53 = 1258291200;
                  v59 = 1258291455;
                  v55 = 1258291200;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
                  break;
                case 3:
                  v45 = 1258291200;
                  v51 = 1258291455;
                  v44 = 1258291455;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
                  break;
                default:
                  v56 = 1258291200;
                  v32 = 0;
                  v58 = 1258291200;
                  v49 = 1258291455;
                  v33 = -1;
LABEL_43:
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v32 | ((*(_DWORD *)&v33 | 0xFFFFFF00) << 16);
                  break;
              }
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              infob = (DrawModelInfo_t *)((char *)infob + 84);
              ++vertID;
            }
            while ( vertID < v13->m_Verts.m_Size );
          }
          v34 = indexStarta;
          v35 = indexStarta + nClampedIndices;
          if ( indexStarta < indexStarta + nClampedIndices )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v13->m_TriListIndices.m_Memory.m_pMemory[v34]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v34;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v34 < v35 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v13->m_TriListIndices.m_Size;
          indexStarta = v35;
        }
        while ( v35 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v67 += 44;
      ++batchID;
    }
    while ( batchID < tris_2.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407180
// Name: int DebugDrawModelTexCoord(class IStudioRender __near *,char const __near *,struct DrawModelInfo_t const __near &,struct matrix3x4_t __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelTexCoord(
        IStudioRender *pStudioRender,
        const char *pMaterialName,
        const DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld,
        float w,
        float h)
{
  int *m_pMemory; // ebx
  int m_Size; // edi
  int v8; // eax
  const char *v9; // eax
  int v10; // esi
  int *v11; // esi
  IMaterialVar *v13; // esi
  IMaterialVar *v14; // eax
  IMaterialVar_vtbl *v15; // edi
  int v16; // eax
  IMatRenderContext *v17; // esi
  GetTriangles_MaterialBatch_t *v18; // edi
  GetTriangles_Vertex_t *v19; // edi
  int j; // ebx
  Vector *v21; // eax
  float z; // ecx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float *m_pCurrPosition; // ecx
  float *m_pCurrNormal; // ecx
  double y; // st7
  float *v28; // ecx
  _QWORD *v29; // eax
  GetTriangles_MaterialBatch_t *v30; // edi
  IMesh *v31; // ecx
  int v32; // eax
  float *v33; // eax
  float *v34; // ecx
  float v35; // xmm1_4
  float *v36; // edx
  _QWORD *v37; // ecx
  int v38; // ecx
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+78h] [ebp-25Ch] BYREF
  Vector *pUV[4]; // [esp+260h] [ebp-74h]
  Vector uv2; // [esp+270h] [ebp-64h] BYREF
  Vector uv1; // [esp+27Ch] [ebp-58h] BYREF
  Vector uv3; // [esp+288h] [ebp-4Ch] BYREF
  Vector uv0; // [esp+294h] [ebp-40h] BYREF
  IMesh *v47; // [esp+2A0h] [ebp-34h]
  Vector p; // [esp+2A4h] [ebp-30h]
  CUtlVector<int,CUtlMemory<int,int> > batchList; // [esp+2B0h] [ebp-24h] BYREF
  int vertID; // [esp+2C4h] [ebp-10h]
  IMesh *pBuildMesh; // [esp+2C8h] [ebp-Ch]
  int i; // [esp+2CCh] [ebp-8h]
  bool bFound; // [esp+2D3h] [ebp-1h] BYREF
  int batchID; // [esp+2DCh] [ebp+8h]
  int batchIDa; // [esp+2DCh] [ebp+8h]

  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    tris_3.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_3.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_3.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_3.m_MaterialBatches.m_Size = 0;
    tris_3.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_3);
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&batchList, 0, sizeof(batchList));
  batchID = 0;
  if ( tris_3.m_MaterialBatches.m_Size <= 0 )
    goto LABEL_16;
  v8 = 0;
  i = 0;
  do
  {
    if ( *(int *)((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_Verts.m_Size + v8) != 0 )
    {
      v9 = (const char *)(***(int (__thiscall ****)(_DWORD))((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_pMaterial
                                                           + v8))(a1: *(IMaterial **)((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_pMaterial
                                                                                    + v8));
      if ( _V_stricmp(s1: v9, s2: pMaterialName) == 0 )
      {
        v10 = m_Size;
        if ( m_Size + 1 > batchList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IFacePoserToolWindow *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&batchList,
            num: m_Size - batchList.m_Memory.m_nAllocationCount + 1);
          m_Size = batchList.m_Size;
          m_pMemory = batchList.m_Memory.m_pMemory;
        }
        batchList.m_Size = ++m_Size;
        batchList.m_pElements = m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        v11 = &m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = batchID;
      }
    }
    v8 = i + 44;
    ++batchID;
    i += 44;
  }
  while ( batchID < tris_3.m_MaterialBatches.m_Size );
  if ( m_Size != 0 )
  {
    bFound = false;
    v13 = g_materialDebugCopyBaseTexture->FindVar(
            this: g_materialDebugCopyBaseTexture,
            a2: "$basetexture",
            a3: &bFound,
            a4: 1);
    if ( !bFound
      || (v14 = tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory].m_pMaterial->FindVar(
                  this: tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory].m_pMaterial,
                  a2: "$basetexture",
                  a3: &bFound,
                  a4: 1),
          !bFound) )
    {
      CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&batchList);
      return 0;
    }
    v15 = v13->__vftable;
    v16 = v14->GetTextureValue(this: v14);
    v15->SetTextureValue(this: v13, a2: (ITexture *)v16);
    v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v17 != nullptr )
      v17->BeginRender(this: v17);
    v17->OverrideDepthEnable(this: v17, a2: false, a3: false, a4: true);
    v17->MatrixMode(this: v17, a2: MATERIAL_MODEL);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))v17->Ortho)(
      a1: v17,
      a2: 0,
      a3: 0,
      a4: COERCE_UNSIGNED_INT64(h),
      a5: HIDWORD(COERCE_UNSIGNED_INT64(h)),
      a6: COERCE_UNSIGNED_INT64(w),
      a7: HIDWORD(COERCE_UNSIGNED_INT64(w)),
      a8: 0,
      a9: 0,
      a10: 0,
      a11: -1074790400,
      a12: 0,
      a13: 1072693248);
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v18 = &tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory];
    v17->Bind(this: v17, a2: g_materialDebugCopyBaseTexture, a3: nullptr);
    pBuildMesh = v17->GetDynamicMesh(this: v17, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: pBuildMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 4,
      nIndexCount: 6,
      pMeshSettings: nullptr);
    v19 = v18->m_Verts.m_Memory.m_pMemory;
    pUV[0] = &uv0;
    memset(&uv0, 0, sizeof(uv0));
    uv1.x = 1.0;
    uv1.y = 0.0;
    uv1.z = 0.0;
    uv2.x = 1.0;
    uv2.y = 1.0;
    uv2.z = 0.0;
    uv3.x = 0.0;
    uv3.y = 1.0;
    uv3.z = 0.0;
    pUV[1] = &uv1;
    pUV[2] = &uv2;
    pUV[3] = &uv3;
    for ( j = 0; j < 4; ++j )
    {
      v21 = pUV[j];
      z = v21->z;
      *(_QWORD *)&p.x = *(_QWORD *)&v21->x;
      v23 = p.x * w;
      v24 = p.y * h;
      p.z = z;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = p.x * w;
      m_pCurrPosition[1] = v24;
      p.x = v23;
      m_pCurrPosition[2] = p.z;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = v19->m_Normal.x;
      y = v19->m_Normal.y;
      p.y = v24;
      m_pCurrNormal[1] = y;
      m_pCurrNormal[2] = v19->m_Normal.z;
      v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v21->x;
      v28[1] = v21->y;
      v29 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
      *v29 = *(_QWORD *)&v19->m_TangentS.x;
      v29[1] = *(_QWORD *)&v19->m_TangentS.z;
      i = 1258291455;
      vertID = 1258291455;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    }
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 1;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 2;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 2;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 3;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2);
          break;
        case MATERIAL_LINE_LOOP:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 2 * meshBuilder.m_VertexBuilder.m_nVertexCount);
          break;
        case MATERIAL_POLYGON:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6);
          break;
        case MATERIAL_QUADS:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4);
          break;
        case MATERIAL_INSTANCED_QUADS:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 0);
          break;
        default:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: meshBuilder.m_VertexBuilder.m_nVertexCount);
          break;
      }
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
    pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
    for ( i = 0; i < batchList.m_Size; ++i )
    {
      v30 = &tris_3.m_MaterialBatches.m_Memory.m_pMemory[batchList.m_Memory.m_pMemory[i]];
      v17->Bind(this: v17, a2: g_materialWireframeVertexColorNoCull, a3: nullptr);
      v31 = v17->GetDynamicMesh(this: v17, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      v32 = v30->m_TriListIndices.m_Size;
      v47 = v31;
      batchIDa = v32;
      if ( v32 >= 32766 )
        batchIDa = 32766;
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: v31,
        type: MATERIAL_TRIANGLES,
        nVertexCount: v30->m_Verts.m_Size,
        nIndexCount: batchIDa,
        pMeshSettings: nullptr);
      vertID = 0;
      if ( v30->m_Verts.m_Size > 0 )
      {
        pBuildMesh = nullptr;
        do
        {
          v33 = (float *)((char *)pBuildMesh + (unsigned int)v30->m_Verts.m_Memory.m_pMemory);
          v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v35 = v33[11] * h;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33[10] * w;
          v34[1] = v35;
          v34[2] = 0.0;
          v36 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = v33[3];
          v36[1] = v33[4];
          v36[2] = v33[5];
          v37 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                         + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                         * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
          *v37 = *((_QWORD *)v33 + 3);
          v37[1] = *((_QWORD *)v33 + 4);
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0xFFFF;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          pBuildMesh = (IMesh *)((char *)pBuildMesh + 84);
          ++vertID;
        }
        while ( vertID < v30->m_Verts.m_Size );
      }
      v38 = 0;
      if ( batchIDa > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                 + LOWORD(v30->m_TriListIndices.m_Memory.m_pMemory[v38]);
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          ++v38;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( v38 < batchIDa );
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
      v47->Draw_2(this: v47, a2: -1, a3: 0);
    }
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_MODEL);
    v17->PopMatrix(this: v17);
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
    v17->EndRender(this: v17);
    v17->Release(this: v17);
    if ( batchList.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchList.m_Memory.m_pMemory);
  }
  else
  {
LABEL_16:
    if ( batchList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return 0;
    }
  }
  return 0;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0040D390
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
// Address: 0x0040D400
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
// Address: 0x0040D480
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
// Address: 0x0040D550
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
// Address: 0x0040D5B0
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
// Address: 0x0040D620
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D720
// Name: public: CMatchedVert::CMatchedVert(struct GetTriangles_Vertex_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CMatchedVert *__thiscall CMatchedVert::CMatchedVert(CMatchedVert *this, const GetTriangles_Vertex_t *vert)
{
  this->m_pos.x = vert->m_Position.x;
  this->m_pos.y = vert->m_Position.y;
  this->m_pos.z = vert->m_Position.z;
  this->m_bones = vert->m_BoneIndex[0]
                + (((vert->m_BoneIndex[1] <= 0 ? 0 : vert->m_BoneIndex[1])
                  + ((vert->m_BoneIndex[2] <= 0 ? 0 : vert->m_BoneIndex[1]) << 8)) << 8);
  this->m_count = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D770
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040D7C0
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D7E0
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
// Address: 0x0040D860
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebx
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebx
  IMesh *v8; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  v4 = type;
  v5 = pMesh;
  pMesh = nullptr;
  type = 0;
  v9 = numPrimitives;
  this->m_pMesh = v5;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v4,
    nPrimitiveCount: v9);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  v8 = pMesh;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x0040D970
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
// Address: 0x0040DA30
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(class CMatchedVert const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int v3; // esi
  int v4; // edx
  CMatchedVert *m_pMemory; // edi
  float v6; // xmm0_4
  int result; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = (float)((float)(src->m_pos.y + src->m_pos.x) + src->m_pos.z) + (float)src->m_bones;
    do
    {
      result = (v4 + v3) >> 1;
      if ( v6 <= (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x)
                               + m_pMemory[result].m_pos.z)
                       + (float)m_pMemory[result].m_bones) )
      {
        if ( (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x) + m_pMemory[result].m_pos.z)
                   + (float)m_pMemory[result].m_bones) <= v6 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB30
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // eax

  v3 = pFrom->GetRenderContext(this: pFrom);
  this->m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040DB60
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::Find(class CMatchedVert const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int v3; // esi
  int v4; // edx
  CMatchedVert *m_pMemory; // edi
  float v6; // xmm0_4
  int result; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = (float)((float)(src->m_pos.y + src->m_pos.x) + src->m_pos.z) + (float)src->m_bones;
    do
    {
      result = (v4 + v3) >> 1;
      if ( v6 <= (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x)
                               + m_pMemory[result].m_pos.z)
                       + (float)m_pMemory[result].m_bones) )
      {
        if ( (float)((float)((float)(m_pMemory[result].m_pos.y + m_pMemory[result].m_pos.x) + m_pMemory[result].m_pos.z)
                   + (float)m_pMemory[result].m_bones) <= v6 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DC60
// Name: public: int CUtlSortVector<class CMatchedVert,class CMatchedVert::CMatchedVertLessFunc>::Insert(class CMatchedVert const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Insert(
        CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc> *this,
        const CMatchedVert *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CMatchedVert *m_pMemory; // ecx
  int v8; // eax
  CMatchedVert *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 20 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040DDB0
// Name: int DebugDrawModelBadVerts(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __usercall DebugDrawModelBadVerts@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld)
{
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // edi
  float *v8; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  float v10; // eax
  float v11; // xmm0_4
  int v12; // edi
  int v13; // xmm1_4
  float *v14; // edx
  const float *v15; // ecx
  const matrix3x4_t *v16; // esi
  float v17; // xmm3_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  int v20; // eax
  int v21; // eax
  __int64 v22; // xmm1_8
  _QWORD *v23; // eax
  __int128 v24; // xmm1
  __int128 v25; // xmm2
  float v26; // xmm1_4
  float x; // ecx
  float v28; // edi
  int v29; // eax
  int v30; // eax
  _BYTE v32[12]; // [esp-Ch] [ebp-284h] BYREF
  _BYTE meshBuilder_168[324]; // [esp+A8h] [ebp-1D0h] OVERLAPPED BYREF
  float v34; // [esp+1F8h] [ebp-80h]
  int v35; // [esp+1FCh] [ebp-7Ch]
  float *v36; // [esp+200h] [ebp-78h]
  int v37; // [esp+204h] [ebp-74h]
  IMatRenderContext *v38; // [esp+208h] [ebp-70h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+20Ch] [ebp-6Ch]
  const float *v40; // [esp+210h] [ebp-68h]
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-64h]
  __int64 pBuildMesh; // [esp+218h] [ebp-60h] OVERLAPPED
  _BYTE k[20]; // [esp+220h] [ebp-58h] OVERLAPPED
  const Vector *normal; // [esp+234h] [ebp-44h]
  int batchID; // [esp+238h] [ebp-40h]
  Vector skinnedPos; // [esp+23Ch] [ebp-3Ch] BYREF
  int indexStart; // [esp+248h] [ebp-30h]
  Vector tmp; // [esp+24Ch] [ebp-2Ch] BYREF
  Vector skinnedNormal; // [esp+258h] [ebp-20h]
  int v50; // [esp+264h] [ebp-14h]
  int v51; // [esp+268h] [ebp-10h]
  int v52; // [esp+26Ch] [ebp-Ch]
  int vertID; // [esp+270h] [ebp-8h]
  int retaddr; // [esp+278h] [ebp+0h]

  v52 = a1;
  vertID = retaddr;
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    tris.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris.m_MaterialBatches.m_Size = 0;
    tris.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelBadVerts_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  ((void (__thiscall *)(IStudioRender *, DrawModelInfo_t *, matrix3x4_t *, GetTriangles_Output_t *, int, int))pStudioRender->GetTriangles)(
    a1: pStudioRender,
    a2: info,
    a3: pBoneToWorld,
    a4: &tris,
    a5: a2,
    a6: a3);
  v6 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v7 = v6;
  v38 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  v7->MatrixMode(this: v7, a2: MATERIAL_MODEL);
  v7->PushMatrix(this: v7);
  v7->LoadIdentity(this: v7);
  CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)v32);
  *(_DWORD *)&k[12] = 0;
  if ( tris.m_MaterialBatches.m_Size > 0 )
  {
    skinnedNormal.z = 0.0;
    do
    {
      v8 = (float *)((char *)tris.m_MaterialBatches.m_Memory.m_pMemory + LODWORD(skinnedNormal.z));
      Bind = v7->Bind;
      v36 = (float *)((char *)tris.m_MaterialBatches.m_Memory.m_pMemory + LODWORD(skinnedNormal.z));
      Bind(this: v7, a2: g_materialVertexColor, a3: nullptr);
      materialBatch = (GetTriangles_MaterialBatch_t *)v7->GetDynamicMesh(
                                                        this: v7,
                                                        a2: false,
                                                        a3: nullptr,
                                                        a4: nullptr,
                                                        a5: nullptr);
      v10 = v8[9];
      skinnedPos.x = 0.0;
      if ( SLODWORD(v10) > 0 )
      {
        do
        {
          skinnedNormal.x = v10;
          if ( SLODWORD(v10) >= 32766 )
            LODWORD(skinnedNormal.x) = 32766;
          CMeshBuilder::Begin(
            this: (CMeshBuilder *)v32,
            pMesh: (IMesh *)materialBatch,
            type: MATERIAL_TRIANGLES,
            nVertexCount: *((_DWORD *)v8 + 4),
            nIndexCount: SLODWORD(skinnedNormal.x),
            pMeshSettings: nullptr);
          v50 = 0;
          if ( *((int *)v8 + 4) > 0 )
          {
            skinnedNormal.y = 0.0;
            do
            {
              v11 = 0.0;
              v12 = LODWORD(skinnedNormal.y) + *((_DWORD *)v8 + 1);
              *(_DWORD *)&k[16] = 0;
              v13 = *(_DWORD *)(v12 + 36);
              v14 = (float *)(v12 + 12);
              v15 = (const float *)(v12 + 24);
              *(_DWORD *)&k[8] = v12 + 12;
              v40 = (const float *)(v12 + 24);
              *(float *)&normal = 0.0;
              *(float *)&batchID = 0.0;
              memset(&tmp, 0, sizeof(tmp));
              pBuildMesh = 0;
              *(_DWORD *)k = 0;
              *(_DWORD *)&k[4] = v13;
              pRenderContext.m_pObject = nullptr;
              if ( *(int *)(v12 + 80) > 0 )
              {
                v51 = v12 + 48;
                do
                {
                  v16 = &tris.m_PoseToWorld[*(_DWORD *)(v51 + 16)];
                  VectorTransform(in1: (const float *)v12, in2: v16, out: &skinnedPos.y);
                  v17 = *(float *)v51;
                  *(float *)&k[16] = (float)(skinnedPos.y * *(float *)v51) + *(float *)&k[16];
                  *(float *)&normal = (float)(skinnedPos.z * v17) + *(float *)&normal;
                  *(float *)&batchID = (float)(*(float *)&indexStart * v17) + *(float *)&batchID;
                  VectorRotate(in1: *(const float **)&k[8], in2: v16, out: &skinnedPos.y);
                  v18 = *(float *)v51;
                  tmp.z = (float)(*(float *)&indexStart * *(float *)v51) + tmp.z;
                  VectorRotate(
                    in1: v40,
                    in2: COERCE_CONST_MATRIX3X4_T_((float)(skinnedPos.y * v18) + tmp.x),
                    out: COERCE_FLOAT_((float)(skinnedPos.z * v18) + COERCE_FLOAT((Vector *)&skinnedPos.y)));
                  v19 = *(float *)v51;
                  *(float *)&pBuildMesh = (float)(skinnedPos.y * *(float *)v51) + *(float *)&pBuildMesh;
                  *((float *)&pBuildMesh + 1) = (float)(skinnedPos.z * v19) + *((float *)&pBuildMesh + 1);
                  *(float *)k = (float)(*(float *)&indexStart * v19) + *(float *)k;
                  ++pRenderContext.m_pObject;
                  v51 += 4;
                }
                while ( (int)pRenderContext.m_pObject < *(_DWORD *)(v12 + 80) );
                v11 = 0.0;
                v15 = v40;
                v14 = *(float **)&k[8];
                v8 = v36;
              }
              v20 = *(_DWORD *)&meshBuilder_168[248];
              **(_DWORD **)&meshBuilder_168[248] = *(_DWORD *)&k[16];
              *(float *)(v20 + 4) = *(float *)&normal;
              *(float *)(v20 + 8) = *(float *)&batchID;
              **(Vector **)&meshBuilder_168[252] = tmp;
              v21 = *(_DWORD *)&meshBuilder_168[260];
              v22 = pBuildMesh;
              **(float **)&meshBuilder_168[260] = *(float *)(v12 + 40);
              *(float *)(v21 + 4) = *(float *)(v12 + 44);
              v23 = (_QWORD *)(*(_DWORD *)&meshBuilder_168[216]
                             + *(_DWORD *)&meshBuilder_168[244] * *(_DWORD *)&meshBuilder_168[132]);
              *v23 = v22;
              v23[1] = *(_QWORD *)k;
              v24 = 0;
              *(float *)&v24 = fsqrt((float)((float)(*v15 * *v15) + (float)(v15[1] * v15[1])) + (float)(v15[2] * v15[2]));
              *(_OWORD *)&meshBuilder_168[308] = v24;
              if ( *(float *)&v24 < 0.89999998 || *(float *)&meshBuilder_168[308] > 1.1 )
                v11 = 1.0;
              v25 = 0;
              *(float *)&v25 = fsqrt((float)((float)(*v14 * *v14) + (float)(v14[1] * v14[1])) + (float)(v14[2] * v14[2]));
              *(_OWORD *)&meshBuilder_168[308] = v25;
              if ( *(float *)&v25 < 0.89999998 || *(float *)&meshBuilder_168[308] > 1.1 )
                v11 = 1.0;
              v26 = (float)((float)(v14[1] * v15[1]) + (float)(*v15 * *v14)) + (float)(v14[2] * v15[2]);
              if ( v26 > 0.95 || v26 < -0.95 )
                v11 = 1.0;
              v37 = 1258291200;
              v35 = 1258291200;
              v34 = (float)(v11 * 255.0) + 8388608.0;
              **(_DWORD **)&meshBuilder_168[256] = (LOBYTE(v34) | 0xFFFFFF00) << 16;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder_168[64]);
              LODWORD(skinnedNormal.y) += 84;
              ++v50;
            }
            while ( v50 < *((_DWORD *)v8 + 4) );
          }
          x = skinnedPos.x;
          LODWORD(v28) = LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x);
          v50 = LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x);
          if ( SLODWORD(skinnedPos.x) < LODWORD(skinnedPos.x) + LODWORD(skinnedNormal.x) )
          {
            v29 = *(_DWORD *)&meshBuilder_168[44];
            do
            {
              *(_WORD *)(*(_DWORD *)&meshBuilder_168[12] + 2 * v29) = *(_WORD *)&meshBuilder_168[40]
                                                                    + *(_WORD *)(*((_DWORD *)v8 + 6) + 4 * LODWORD(x));
              v29 = *(_DWORD *)&meshBuilder_168[24] + *(_DWORD *)&meshBuilder_168[44];
              v28 = *(float *)&v50;
              ++LODWORD(x);
              *(_DWORD *)&meshBuilder_168[44] = v29;
              *(_DWORD *)&meshBuilder_168[36] = v29;
            }
            while ( SLODWORD(x) < v50 );
          }
          if ( meshBuilder_168[8] != 0 )
          {
            switch ( *(_DWORD *)&meshBuilder_168[4] )
            {
              case 4:
                v30 = 2 * *(_DWORD *)&meshBuilder_168[240] - 2;
                break;
              case 5:
                v30 = 2 * *(_DWORD *)&meshBuilder_168[240];
                break;
              case 6:
                v30 = 3 * *(_DWORD *)&meshBuilder_168[240] - 6;
                break;
              case 7:
                v30 = 6 * *(_DWORD *)&meshBuilder_168[240] / 4;
                break;
              case 0xA:
                v30 = 0;
                break;
              default:
                v30 = *(_DWORD *)&meshBuilder_168[240];
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: (CIndexBuilder *)&meshBuilder_168[12],
              primitiveType: *(MaterialPrimitiveType_t *)&meshBuilder_168[4],
              nIndexCount: v30);
          }
          (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _BYTE *))(**(_DWORD **)meshBuilder_168 + 80))(
            a1: *(_DWORD *)meshBuilder_168,
            a2: *(_DWORD *)&meshBuilder_168[240],
            a3: *(_DWORD *)&meshBuilder_168[36],
            a4: v32);
          *(_DWORD *)&meshBuilder_168[28] = 0;
          *(_DWORD *)&meshBuilder_168[32] = 0;
          *(_DWORD *)&meshBuilder_168[236] = 0;
          *(_DWORD *)&meshBuilder_168[228] = 0;
          *(_DWORD *)meshBuilder_168 = 0;
          *(_DWORD *)&meshBuilder_168[140] = -1;
          ((void (__thiscall *)(GetTriangles_MaterialBatch_t *, int, _DWORD))materialBatch->m_pMaterial[12].__vftable)(
            a1: materialBatch,
            a2: -1,
            a3: 0);
          v10 = v8[9];
          skinnedPos.x = v28;
        }
        while ( SLODWORD(v28) < SLODWORD(v10) );
        v7 = v38;
      }
      LODWORD(skinnedNormal.z) += 44;
      ++*(_DWORD *)&k[12];
    }
    while ( *(int *)&k[12] < tris.m_MaterialBatches.m_Size );
  }
  v7->MatrixMode(this: v7, a2: MATERIAL_MODEL);
  v7->PopMatrix(this: v7);
  if ( *(_DWORD *)&meshBuilder_168[228] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[228] + 8))(a1: *(_DWORD *)&meshBuilder_168[228]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[228] + 16))(a1: *(_DWORD *)&meshBuilder_168[228]);
  }
  if ( *(_DWORD *)&meshBuilder_168[28] != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[28] + 8))(a1: *(_DWORD *)&meshBuilder_168[28]) != 0 )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&meshBuilder_168[28] + 16))(a1: *(_DWORD *)&meshBuilder_168[28]);
  }
  v7->EndRender(this: v7);
  v7->Release(this: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E440
// Name: int DebugDrawModelWireframe(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelWireframe(
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld,
        const Vector *modelOrigin,
        const Vector *color)
{
  IMatRenderContext *v5; // eax
  IMatRenderContext *m_pObject; // edi
  GetTriangles_MaterialBatch_t *v7; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  GetTriangles_Vertex_t *v10; // edi
  Vector4D *p_m_BoneWeight; // ebx
  const matrix3x4_t *v12; // esi
  float x; // xmm3_4
  float v14; // xmm3_4
  float v15; // xmm3_4
  float *v16; // eax
  __int64 v17; // xmm0_8
  _QWORD *v18; // eax
  int v19; // ecx
  int v20; // edi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-24Ch] BYREF
  float v25; // [esp+1F0h] [ebp-64h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-60h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+1F8h] [ebp-5Ch]
  float v28; // [esp+1FCh] [ebp-58h]
  float v29; // [esp+200h] [ebp-54h]
  int batchID; // [esp+204h] [ebp-50h]
  int k; // [esp+208h] [ebp-4Ch]
  Vector4D skinnedTangentS; // [esp+20Ch] [ebp-48h] BYREF
  int vertID; // [esp+21Ch] [ebp-38h]
  IMesh *pBuildMesh; // [esp+220h] [ebp-34h]
  Vector skinnedPos; // [esp+224h] [ebp-30h] BYREF
  Vector skinnedNormal; // [esp+230h] [ebp-24h] BYREF
  Vector tmp; // [esp+23Ch] [ebp-18h] BYREF
  int nClampedIndices; // [esp+248h] [ebp-Ch]
  unsigned int v39; // [esp+24Ch] [ebp-8h]
  unsigned int v40; // [esp+250h] [ebp-4h]
  int indexStart; // [esp+25Ch] [ebp+8h]

  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    tris_0.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_0.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_0.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_0.m_MaterialBatches.m_Size = 0;
    tris_0.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelWireframe_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_0);
  v5 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  m_pObject = v5;
  pRenderContext.m_pObject = v5;
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  batchID = 0;
  if ( tris_0.m_MaterialBatches.m_Size > 0 )
  {
    v40 = 0;
    do
    {
      v7 = &tris_0.m_MaterialBatches.m_Memory.m_pMemory[v40 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_0.m_MaterialBatches.m_Memory.m_pMemory[v40 / 0x2C];
      Bind(this: m_pObject, a2: g_materialWireframeVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v7->m_TriListIndices.m_Size;
      indexStart = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nClampedIndices = m_Size - indexStart;
          if ( m_Size - indexStart >= 32766 )
            nClampedIndices = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v7->m_Verts.m_Size,
            nIndexCount: nClampedIndices,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v7->m_Verts.m_Size > 0 )
          {
            v39 = 0;
            do
            {
              v10 = &v7->m_Verts.m_Memory.m_pMemory[v39 / 0x54];
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              memset((void *)&skinnedTangentS, 0, 12);
              skinnedTangentS.w = v10->m_TangentS.w;
              k = 0;
              if ( v10->m_NumBones > 0 )
              {
                p_m_BoneWeight = &v10->m_BoneWeight;
                do
                {
                  v12 = &tris_0.m_PoseToWorld[LODWORD(p_m_BoneWeight[1].x)];
                  VectorTransform(in1: &v10->m_Position.x, in2: v12, out: &tmp.x);
                  x = p_m_BoneWeight->x;
                  skinnedPos.x = (float)(tmp.x * p_m_BoneWeight->x) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * x) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * x) + skinnedPos.z;
                  VectorRotate(in1: &v10->m_Normal.x, in2: v12, out: &tmp.x);
                  v14 = p_m_BoneWeight->x;
                  skinnedNormal.x = (float)(tmp.x * p_m_BoneWeight->x) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v14) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v14) + skinnedNormal.z;
                  VectorRotate(in1: &v10->m_TangentS.x, in2: v12, out: &tmp.x);
                  v15 = p_m_BoneWeight->x;
                  p_m_BoneWeight = (Vector4D *)((char *)p_m_BoneWeight + 4);
                  skinnedTangentS.x = (float)(tmp.x * v15) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v15) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v15) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < v10->m_NumBones );
                v7 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v10->m_TexCoord.x;
              v17 = *(_QWORD *)&skinnedTangentS.x;
              v16[1] = v10->m_TexCoord.y;
              v18 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v18 = v17;
              v18[1] = *(_QWORD *)&skinnedTangentS.z;
              v28 = (float)(color->z * 255.0) + 8388608.0;
              v25 = (float)(color->y * 255.0) + 8388608.0;
              v29 = (float)(color->x * 255.0) + 8388608.0;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v28)
                                                                  | ((LOBYTE(v25) | ((LOBYTE(v29) | 0xFFFFFF00) << 8)) << 8);
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v39 += 84;
              ++vertID;
            }
            while ( vertID < v7->m_Verts.m_Size );
          }
          v19 = indexStart;
          v20 = indexStart + nClampedIndices;
          if ( indexStart < indexStart + nClampedIndices )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v7->m_TriListIndices.m_Memory.m_pMemory[v19]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v19;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v19 < v20 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v7->m_TriListIndices.m_Size;
          indexStart = v20;
        }
        while ( v20 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v40 += 44;
      ++batchID;
    }
    while ( batchID < tris_0.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9B0
// Name: int DebugDrawModelBoneWeights(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelBoneWeights(IStudioRender *pStudioRender, DrawModelInfo_t *info, matrix3x4_t *pBoneToWorld)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *m_pObject; // esi
  GetTriangles_MaterialBatch_t *v5; // ebx
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  float v8; // xmm0_4
  char *v9; // edi
  bool v10; // cc
  float v11; // xmm1_4
  char *v12; // ebx
  const matrix3x4_t *v13; // esi
  float v14; // xmm3_4
  float v15; // xmm3_4
  float v16; // xmm3_4
  float *v17; // eax
  __int64 v18; // xmm1_8
  _QWORD *v19; // eax
  int v20; // edx
  int v21; // ebx
  float v22; // xmm2_4
  unsigned int v23; // ecx
  char *v24; // eax
  int v25; // edi
  int v26; // edx
  int v27; // ecx
  char v28; // dl
  int v29; // ecx
  int v30; // esi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-28Ch] BYREF
  int v35; // [esp+1F0h] [ebp-A4h]
  int v36; // [esp+1F4h] [ebp-A0h]
  int v37; // [esp+1F8h] [ebp-9Ch]
  float v38; // [esp+1FCh] [ebp-98h]
  int v39; // [esp+200h] [ebp-94h]
  int v40; // [esp+204h] [ebp-90h]
  int v41; // [esp+208h] [ebp-8Ch]
  float v42; // [esp+20Ch] [ebp-88h]
  int v43; // [esp+210h] [ebp-84h]
  CMatRenderContextPtr pRenderContext; // [esp+214h] [ebp-80h]
  int v45; // [esp+218h] [ebp-7Ch]
  int v46; // [esp+21Ch] [ebp-78h]
  int v47; // [esp+220h] [ebp-74h]
  int v48; // [esp+224h] [ebp-70h]
  int v49; // [esp+228h] [ebp-6Ch]
  int v50; // [esp+22Ch] [ebp-68h]
  int v51; // [esp+230h] [ebp-64h]
  int v52; // [esp+234h] [ebp-60h]
  int v53; // [esp+238h] [ebp-5Ch]
  int v54; // [esp+23Ch] [ebp-58h]
  IMesh *pBuildMesh; // [esp+240h] [ebp-54h]
  int k; // [esp+244h] [ebp-50h]
  Vector4D skinnedTangentS; // [esp+248h] [ebp-4Ch] BYREF
  int batchID; // [esp+258h] [ebp-3Ch]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+25Ch] [ebp-38h]
  int vertID; // [esp+260h] [ebp-34h]
  Vector skinnedPos; // [esp+264h] [ebp-30h] BYREF
  Vector skinnedNormal; // [esp+270h] [ebp-24h] BYREF
  Vector tmp; // [esp+27Ch] [ebp-18h] BYREF
  int indexStart; // [esp+288h] [ebp-Ch]
  int nIndexCount; // [esp+28Ch] [ebp-8h]
  unsigned int v66; // [esp+290h] [ebp-4h]
  IStudioRender *pStudioRendera; // [esp+29Ch] [ebp+8h]

  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    tris_1.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_1.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_1.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_1.m_MaterialBatches.m_Size = 0;
    tris_1.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelBoneWeights_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_1);
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  m_pObject = v3;
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  batchID = 0;
  if ( tris_1.m_MaterialBatches.m_Size > 0 )
  {
    v66 = 0;
    do
    {
      v5 = &tris_1.m_MaterialBatches.m_Memory.m_pMemory[v66 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_1.m_MaterialBatches.m_Memory.m_pMemory[v66 / 0x2C];
      Bind(this: m_pObject, a2: g_materialVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v5->m_TriListIndices.m_Size;
      indexStart = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nIndexCount = m_Size;
          if ( m_Size >= 32766 )
            nIndexCount = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v5->m_Verts.m_Size,
            nIndexCount,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v5->m_Verts.m_Size > 0 )
          {
            pStudioRendera = nullptr;
            do
            {
              v8 = 0.0;
              v9 = (char *)pStudioRendera + (unsigned int)v5->m_Verts.m_Memory.m_pMemory;
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              v10 = *((_DWORD *)v9 + 20) <= 0;
              v11 = *((float *)v9 + 9);
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              memset((void *)&skinnedTangentS, 0, 12);
              skinnedTangentS.w = v11;
              k = 0;
              if ( !v10 )
              {
                v12 = v9 + 48;
                do
                {
                  v13 = &tris_1.m_PoseToWorld[*((_DWORD *)v12 + 4)];
                  VectorTransform(in1: (const float *)v9, in2: v13, out: &tmp.x);
                  v14 = *(float *)v12;
                  skinnedPos.x = (float)(tmp.x * *(float *)v12) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * v14) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * v14) + skinnedPos.z;
                  VectorRotate(in1: (const float *)v9 + 3, in2: v13, out: &tmp.x);
                  v15 = *(float *)v12;
                  skinnedNormal.x = (float)(tmp.x * *(float *)v12) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v15) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v15) + skinnedNormal.z;
                  VectorRotate(in1: (const float *)v9 + 6, in2: v13, out: &tmp.x);
                  v16 = *(float *)v12;
                  v12 += 4;
                  skinnedTangentS.x = (float)(tmp.x * v16) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v16) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v16) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < *((_DWORD *)v9 + 20) );
                v8 = 0.0;
                v5 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v18 = *(_QWORD *)&skinnedTangentS.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *((float *)v9 + 10);
              v17[1] = *((float *)v9 + 11);
              v19 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v19 = v18;
              v19[1] = *(_QWORD *)&skinnedTangentS.z;
              if ( g_viewerSettings.highlightBone < 0 )
              {
                switch ( *((_DWORD *)v9 + 20) )
                {
                  case 0:
                    v51 = 1258291200;
                    v43 = 1258291200;
                    v36 = 1258291200;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
                    break;
                  case 1:
                    v41 = 1258291200;
                    v27 = 0;
                    v54 = 1258291455;
                    v35 = 1258291200;
                    v28 = 0;
                    goto LABEL_44;
                  case 2:
                    v45 = 1258291200;
                    v37 = 1258291455;
                    v47 = 1258291455;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
                    break;
                  case 3:
                    v52 = 1258291200;
                    v53 = 1258291200;
                    v39 = 1258291455;
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
                    break;
                  default:
                    v46 = 1258291455;
                    v27 = 255;
                    v48 = 1258291455;
                    v50 = 1258291455;
                    v28 = -1;
LABEL_44:
                    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v27
                                                                        | ((((*(_DWORD *)&v28 | 0xFFFFFF00) << 8) | 0xFF) << 8);
                    break;
                }
              }
              else
              {
                v20 = *((_DWORD *)v9 + 20);
                v21 = 0;
                v22 = 0.0;
                if ( v20 >= 4 )
                {
                  v23 = ((unsigned int)(v20 - 4) >> 2) + 1;
                  v24 = v9 + 48;
                  v21 = 4 * v23;
                  do
                  {
                    if ( *((_DWORD *)v24 + 4) == g_viewerSettings.highlightBone )
                      v22 = *(float *)v24;
                    if ( *((_DWORD *)v24 + 5) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 1);
                    if ( *((_DWORD *)v24 + 6) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 2);
                    if ( *((_DWORD *)v24 + 7) == g_viewerSettings.highlightBone )
                      v22 = *((float *)v24 + 3);
                    v24 += 16;
                    --v23;
                  }
                  while ( v23 != 0 );
                }
                if ( v21 < v20 )
                {
                  v25 = (int)&v9[4 * v21 + 48];
                  v26 = v20 - v21;
                  do
                  {
                    if ( *(_DWORD *)(v25 + 16) == g_viewerSettings.highlightBone )
                      v22 = *(float *)v25;
                    v25 += 4;
                    --v26;
                  }
                  while ( v26 != 0 );
                }
                if ( v22 >= 0.0 )
                {
                  if ( v22 <= 1.0 )
                    v8 = v22;
                  else
                    v8 = 1.0;
                }
                v5 = materialBatch;
                v38 = (float)((float)(1.0 - v8) * 255.0) + 8388608.0;
                v40 = 1258291455;
                v42 = v38;
                v49 = 1258291328;
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = LOBYTE(v38)
                                                                    | ((((LOBYTE(v38) | 0x8000) << 8) | 0xFF) << 8);
              }
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              pStudioRendera += 21;
              ++vertID;
            }
            while ( vertID < v5->m_Verts.m_Size );
          }
          v29 = indexStart;
          v30 = indexStart + nIndexCount;
          if ( indexStart < indexStart + nIndexCount )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v5->m_TriListIndices.m_Memory.m_pMemory[v29]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v29;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v29 < v30 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v5->m_TriListIndices.m_Size;
          indexStart = v30;
        }
        while ( v30 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v66 += 44;
      ++batchID;
    }
    while ( batchID < tris_1.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040F140
// Name: int DebugDrawModelVertColocation(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __usercall DebugDrawModelVertColocation@<eax>(
        int a1@<edi>,
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld)
{
  unsigned int v4; // eax
  DrawModelInfo_t *v5; // eax
  unsigned int v6; // edx
  GetTriangles_MaterialBatch_t *m_pMemory; // edx
  DrawModelInfo_t *v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // eax
  IMatRenderContext *m_pObject; // esi
  GetTriangles_MaterialBatch_t *v13; // edi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int m_Size; // eax
  char *v16; // esi
  int v17; // eax
  bool v18; // zf
  bool v19; // sf
  int v20; // eax
  float v21; // xmm0_4
  char *v22; // ebx
  const matrix3x4_t *v23; // edi
  float v24; // xmm3_4
  float v25; // xmm3_4
  float v26; // xmm3_4
  float *v27; // eax
  __int64 v28; // xmm0_8
  _QWORD *v29; // eax
  int v30; // eax
  int m_count; // eax
  int v32; // ecx
  char v33; // dl
  int v34; // ecx
  int v35; // esi
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-2A0h] BYREF
  CMatchedVert mv; // [esp+1F0h] [ebp-B8h] BYREF
  CMatchedVert src; // [esp+204h] [ebp-A4h] BYREF
  int v43; // [esp+218h] [ebp-90h]
  int v44; // [esp+21Ch] [ebp-8Ch]
  int v45; // [esp+220h] [ebp-88h]
  int v46; // [esp+224h] [ebp-84h]
  GetTriangles_MaterialBatch_t *materialBatch; // [esp+228h] [ebp-80h]
  int v48; // [esp+22Ch] [ebp-7Ch]
  int v49; // [esp+230h] [ebp-78h]
  int v50; // [esp+234h] [ebp-74h]
  int v51; // [esp+238h] [ebp-70h]
  int v52; // [esp+23Ch] [ebp-6Ch]
  int v53; // [esp+240h] [ebp-68h]
  CMatRenderContextPtr pRenderContext; // [esp+244h] [ebp-64h]
  int v55; // [esp+248h] [ebp-60h]
  int v56; // [esp+24Ch] [ebp-5Ch]
  int v57; // [esp+250h] [ebp-58h]
  int v58; // [esp+254h] [ebp-54h]
  int v59; // [esp+258h] [ebp-50h]
  int k; // [esp+25Ch] [ebp-4Ch]
  Vector4D skinnedTangentS; // [esp+260h] [ebp-48h] BYREF
  int vertID; // [esp+270h] [ebp-38h]
  Vector skinnedPos; // [esp+274h] [ebp-34h] BYREF
  Vector skinnedNormal; // [esp+280h] [ebp-28h] BYREF
  Vector tmp; // [esp+28Ch] [ebp-1Ch] BYREF
  int nClampedIndices; // [esp+298h] [ebp-10h]
  unsigned int v67; // [esp+29Ch] [ebp-Ch]
  int batchID; // [esp+2A0h] [ebp-8h]
  IMesh *pBuildMesh; // [esp+2A4h] [ebp-4h]
  int indexStart; // [esp+2B0h] [ebp+8h]
  int indexStarta; // [esp+2B0h] [ebp+8h]
  DrawModelInfo_t *infoa; // [esp+2B4h] [ebp+Ch]
  DrawModelInfo_t *infob; // [esp+2B4h] [ebp+Ch]

  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    tris_2.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_2.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_2.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_2.m_MaterialBatches.m_Size = 0;
    tris_2.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_2);
  v4 = _S8;
  if ( (_S8 & 2) == 0 )
  {
    v4 = _S8 | 2;
    _S8 |= 2u;
  }
  if ( (v4 & 4) == 0 )
  {
    _S8 = v4 | 4;
    sortedVector.m_Memory.m_pMemory = nullptr;
    sortedVector.m_Memory.m_nAllocationCount = 0;
    sortedVector.m_Memory.m_nGrowSize = 0;
    sortedVector.m_Size = 0;
    sortedVector.m_pElements = nullptr;
    sortedVector.m_pLessContext = nullptr;
    sortedVector.m_bNeedsSort = false;
    atexit(func: DebugDrawModelVertColocation_::_2_::_dynamic_atexit_destructor_for__sortedVector__);
  }
  v5 = &cached_info;
  v6 = 480;
  while ( *(studiohdr_t **)((char *)&v5->m_pStudioHdr + (char *)info - (char *)&cached_info) == v5->m_pStudioHdr )
  {
    v6 -= 4;
    v5 = (DrawModelInfo_t *)((char *)v5 + 4);
    if ( v6 < 4 )
      goto LABEL_21;
  }
  sortedVector.m_Size = 0;
  cached_info = *info;
  indexStart = 0;
  if ( tris_2.m_MaterialBatches.m_Size > 0 )
  {
    m_pMemory = tris_2.m_MaterialBatches.m_Memory.m_pMemory;
    v8 = nullptr;
    infoa = nullptr;
    do
    {
      v9 = 0;
      pBuildMesh = (IMesh *)((char *)&m_pMemory->m_Verts.m_Size + (_DWORD)v8);
      if ( (int)pBuildMesh->IVertexBuffer::__vftable > 0 )
      {
        batchID = (int)&m_pMemory->m_Verts + (_DWORD)v8;
        v10 = 0;
        do
        {
          CMatchedVert::CMatchedVert(this: &mv, vert: (const GetTriangles_Vertex_t *)(v10 + *(_DWORD *)batchID));
          v11 = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(this: &sortedVector, src: &mv);
          if ( v11 == -1 )
            CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Insert(this: &sortedVector, src: &mv);
          else
            ++sortedVector.m_Memory.m_pMemory[v11].m_count;
          ++v9;
          v10 += 84;
        }
        while ( v9 < (int)pBuildMesh->IVertexBuffer::__vftable );
        m_pMemory = tris_2.m_MaterialBatches.m_Memory.m_pMemory;
        v8 = infoa;
      }
      v8 = (DrawModelInfo_t *)((char *)v8 + 44);
      ++indexStart;
      infoa = v8;
    }
    while ( indexStart < tris_2.m_MaterialBatches.m_Size );
  }
LABEL_21:
  m_pObject = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
                                     a1: g_pMaterialSystem,
                                     a2: a1);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PushMatrix(this: m_pObject);
  m_pObject->LoadIdentity(this: m_pObject);
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_bGenerateIndices = false;
  memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
  memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
  meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  batchID = 0;
  if ( tris_2.m_MaterialBatches.m_Size > 0 )
  {
    v67 = 0;
    do
    {
      v13 = &tris_2.m_MaterialBatches.m_Memory.m_pMemory[v67 / 0x2C];
      Bind = m_pObject->Bind;
      materialBatch = &tris_2.m_MaterialBatches.m_Memory.m_pMemory[v67 / 0x2C];
      Bind(this: m_pObject, a2: g_materialVertexColor, a3: nullptr);
      pBuildMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      m_Size = v13->m_TriListIndices.m_Size;
      indexStarta = 0;
      if ( m_Size > 0 )
      {
        do
        {
          nClampedIndices = m_Size - indexStarta;
          if ( m_Size - indexStarta >= 32766 )
            nClampedIndices = 32766;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh: pBuildMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: v13->m_Verts.m_Size,
            nIndexCount: nClampedIndices,
            pMeshSettings: nullptr);
          vertID = 0;
          if ( v13->m_Verts.m_Size > 0 )
          {
            infob = nullptr;
            do
            {
              v16 = (char *)infob + (unsigned int)v13->m_Verts.m_Memory.m_pMemory;
              v17 = *((_DWORD *)v16 + 17);
              src.m_pos.x = *(float *)v16;
              src.m_pos.y = *((float *)v16 + 1);
              v18 = *((_DWORD *)v16 + 18) == 0;
              v19 = *((int *)v16 + 18) < 0;
              src.m_pos.z = *((float *)v16 + 2);
              memset(&skinnedPos, 0, sizeof(skinnedPos));
              memset(&skinnedNormal, 0, sizeof(skinnedNormal));
              v20 = *((_DWORD *)v16 + 16) + (((v17 <= 0 ? 0 : v17) + ((v19 || v18 ? 0 : v17) << 8)) << 8);
              memset((void *)&skinnedTangentS, 0, 12);
              v21 = *((float *)v16 + 9);
              src.m_bones = v20;
              src.m_count = 1;
              skinnedTangentS.w = v21;
              k = 0;
              if ( *((int *)v16 + 20) > 0 )
              {
                v22 = v16 + 48;
                do
                {
                  v23 = &tris_2.m_PoseToWorld[*((_DWORD *)v22 + 4)];
                  VectorTransform(in1: (const float *)v16, in2: v23, out: &tmp.x);
                  v24 = *(float *)v22;
                  skinnedPos.x = (float)(tmp.x * *(float *)v22) + skinnedPos.x;
                  skinnedPos.y = (float)(tmp.y * v24) + skinnedPos.y;
                  skinnedPos.z = (float)(tmp.z * v24) + skinnedPos.z;
                  VectorRotate(in1: (const float *)v16 + 3, in2: v23, out: &tmp.x);
                  v25 = *(float *)v22;
                  skinnedNormal.x = (float)(tmp.x * *(float *)v22) + skinnedNormal.x;
                  skinnedNormal.y = (float)(tmp.y * v25) + skinnedNormal.y;
                  skinnedNormal.z = (float)(tmp.z * v25) + skinnedNormal.z;
                  VectorRotate(in1: (const float *)v16 + 6, in2: v23, out: &tmp.x);
                  v26 = *(float *)v22;
                  v22 += 4;
                  skinnedTangentS.x = (float)(tmp.x * v26) + skinnedTangentS.x;
                  skinnedTangentS.y = (float)(tmp.y * v26) + skinnedTangentS.y;
                  skinnedTangentS.z = (float)(tmp.z * v26) + skinnedTangentS.z;
                  ++k;
                }
                while ( k < *((_DWORD *)v16 + 20) );
                v13 = materialBatch;
              }
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = skinnedPos;
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = skinnedNormal;
              v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
              v28 = *(_QWORD *)&skinnedTangentS.x;
              *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *((float *)v16 + 10);
              v27[1] = *((float *)v16 + 11);
              v29 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                             + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                             * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
              *v29 = v28;
              v29[1] = *(_QWORD *)&skinnedTangentS.z;
              v30 = CUtlSortVector<CMatchedVert,CMatchedVert::CMatchedVertLessFunc>::Find(this: &sortedVector, &src);
              if ( v30 < 0 )
                m_count = 0;
              else
                m_count = sortedVector.m_Memory.m_pMemory[v30].m_count;
              switch ( m_count )
              {
                case 0:
                  v48 = 1258291200;
                  v50 = 1258291200;
                  v52 = 1258291200;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
                  break;
                case 1:
                  v43 = 1258291455;
                  v32 = 255;
                  v57 = 1258291200;
                  v46 = 1258291200;
                  v33 = 0;
                  goto LABEL_43;
                case 2:
                  v53 = 1258291200;
                  v59 = 1258291455;
                  v55 = 1258291200;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
                  break;
                case 3:
                  v45 = 1258291200;
                  v51 = 1258291455;
                  v44 = 1258291455;
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -256;
                  break;
                default:
                  v56 = 1258291200;
                  v32 = 0;
                  v58 = 1258291200;
                  v49 = 1258291455;
                  v33 = -1;
LABEL_43:
                  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v32 | ((*(_DWORD *)&v33 | 0xFFFFFF00) << 16);
                  break;
              }
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              infob = (DrawModelInfo_t *)((char *)infob + 84);
              ++vertID;
            }
            while ( vertID < v13->m_Verts.m_Size );
          }
          v34 = indexStarta;
          v35 = indexStarta + nClampedIndices;
          if ( indexStarta < indexStarta + nClampedIndices )
          {
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            do
            {
              meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                     + LOWORD(v13->m_TriListIndices.m_Memory.m_pMemory[v34]);
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              ++v34;
              meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
              meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
            }
            while ( v34 < v35 );
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
          pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
          m_Size = v13->m_TriListIndices.m_Size;
          indexStarta = v35;
        }
        while ( v35 < m_Size );
        m_pObject = pRenderContext.m_pObject;
      }
      v67 += 44;
      ++batchID;
    }
    while ( batchID < tris_2.m_MaterialBatches.m_Size );
  }
  m_pObject->MatrixMode(this: m_pObject, a2: MATERIAL_MODEL);
  m_pObject->PopMatrix(this: m_pObject);
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
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040F9E0
// Name: int DebugDrawModelTexCoord(class IStudioRender __near *,char const __near *,struct DrawModelInfo_t const __near &,struct matrix3x4_t __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugDrawModelTexCoord(
        IStudioRender *pStudioRender,
        const char *pMaterialName,
        const DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld,
        float w,
        float h)
{
  int *m_pMemory; // ebx
  int m_Size; // edi
  int v8; // eax
  const char *v9; // eax
  int v10; // esi
  int *v11; // esi
  IMaterialVar *v13; // esi
  IMaterialVar *v14; // eax
  IMaterialVar_vtbl *v15; // edi
  int v16; // eax
  IMatRenderContext *v17; // esi
  GetTriangles_MaterialBatch_t *v18; // edi
  GetTriangles_Vertex_t *v19; // edi
  int j; // ebx
  Vector *v21; // eax
  float z; // ecx
  float v23; // xmm0_4
  float v24; // xmm1_4
  float *m_pCurrPosition; // ecx
  float *m_pCurrNormal; // ecx
  double y; // st7
  float *v28; // ecx
  _QWORD *v29; // eax
  GetTriangles_MaterialBatch_t *v30; // edi
  IMesh *v31; // ecx
  int v32; // eax
  float *v33; // eax
  float *v34; // ecx
  float v35; // xmm1_4
  float *v36; // edx
  _QWORD *v37; // ecx
  int v38; // ecx
  unsigned int m_nCurrentIndex; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+78h] [ebp-25Ch] BYREF
  Vector *pUV[4]; // [esp+260h] [ebp-74h]
  Vector uv2; // [esp+270h] [ebp-64h] BYREF
  Vector uv1; // [esp+27Ch] [ebp-58h] BYREF
  Vector uv3; // [esp+288h] [ebp-4Ch] BYREF
  Vector uv0; // [esp+294h] [ebp-40h] BYREF
  IMesh *v47; // [esp+2A0h] [ebp-34h]
  Vector p; // [esp+2A4h] [ebp-30h]
  CUtlVector<int,CUtlMemory<int,int> > batchList; // [esp+2B0h] [ebp-24h] BYREF
  int vertID; // [esp+2C4h] [ebp-10h]
  IMesh *pBuildMesh; // [esp+2C8h] [ebp-Ch]
  int i; // [esp+2CCh] [ebp-8h]
  bool bFound; // [esp+2D3h] [ebp-1h] BYREF
  int batchID; // [esp+2DCh] [ebp+8h]
  int batchIDa; // [esp+2DCh] [ebp+8h]

  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    tris_3.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_3.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_3.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_3.m_MaterialBatches.m_Size = 0;
    tris_3.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugDrawModelTexCoord_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  pStudioRender->GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_3);
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&batchList, 0, sizeof(batchList));
  batchID = 0;
  if ( tris_3.m_MaterialBatches.m_Size <= 0 )
    goto LABEL_16;
  v8 = 0;
  i = 0;
  do
  {
    if ( *(int *)((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_Verts.m_Size + v8) != 0 )
    {
      v9 = (const char *)(***(int (__thiscall ****)(_DWORD))((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_pMaterial
                                                           + v8))(a1: *(IMaterial **)((char *)&tris_3.m_MaterialBatches.m_Memory.m_pMemory->m_pMaterial
                                                                                    + v8));
      if ( _V_stricmp(s1: v9, s2: pMaterialName) == 0 )
      {
        v10 = m_Size;
        if ( m_Size + 1 > batchList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&batchList,
            num: m_Size - batchList.m_Memory.m_nAllocationCount + 1);
          m_Size = batchList.m_Size;
          m_pMemory = batchList.m_Memory.m_pMemory;
        }
        batchList.m_Size = ++m_Size;
        batchList.m_pElements = m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        v11 = &m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = batchID;
      }
    }
    v8 = i + 44;
    ++batchID;
    i += 44;
  }
  while ( batchID < tris_3.m_MaterialBatches.m_Size );
  if ( m_Size != 0 )
  {
    bFound = false;
    v13 = g_materialDebugCopyBaseTexture->FindVar(
            this: g_materialDebugCopyBaseTexture,
            a2: "$basetexture",
            a3: &bFound,
            a4: 1);
    if ( !bFound
      || (v14 = tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory].m_pMaterial->FindVar(
                  this: tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory].m_pMaterial,
                  a2: "$basetexture",
                  a3: &bFound,
                  a4: 1),
          !bFound) )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&batchList);
      return 0;
    }
    v15 = v13->__vftable;
    v16 = v14->GetTextureValue(this: v14);
    v15->SetTextureValue(this: v13, a2: (ITexture *)v16);
    v17 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v17 != nullptr )
      v17->BeginRender(this: v17);
    v17->OverrideDepthEnable(this: v17, a2: false, a3: false, a4: true);
    v17->MatrixMode(this: v17, a2: MATERIAL_MODEL);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int))v17->Ortho)(
      a1: v17,
      a2: 0,
      a3: 0,
      a4: COERCE_UNSIGNED_INT64(h),
      a5: HIDWORD(COERCE_UNSIGNED_INT64(h)),
      a6: COERCE_UNSIGNED_INT64(w),
      a7: HIDWORD(COERCE_UNSIGNED_INT64(w)),
      a8: 0,
      a9: 0,
      a10: 0,
      a11: -1074790400,
      a12: 0,
      a13: 1072693248);
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PushMatrix(this: v17);
    v17->LoadIdentity(this: v17);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    v18 = &tris_3.m_MaterialBatches.m_Memory.m_pMemory[*m_pMemory];
    v17->Bind(this: v17, a2: g_materialDebugCopyBaseTexture, a3: nullptr);
    pBuildMesh = v17->GetDynamicMesh(this: v17, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: pBuildMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 4,
      nIndexCount: 6,
      pMeshSettings: nullptr);
    v19 = v18->m_Verts.m_Memory.m_pMemory;
    pUV[0] = &uv0;
    memset(&uv0, 0, sizeof(uv0));
    uv1.x = 1.0;
    uv1.y = 0.0;
    uv1.z = 0.0;
    uv2.x = 1.0;
    uv2.y = 1.0;
    uv2.z = 0.0;
    uv3.x = 0.0;
    uv3.y = 1.0;
    uv3.z = 0.0;
    pUV[1] = &uv1;
    pUV[2] = &uv2;
    pUV[3] = &uv3;
    for ( j = 0; j < 4; ++j )
    {
      v21 = pUV[j];
      z = v21->z;
      *(_QWORD *)&p.x = *(_QWORD *)&v21->x;
      v23 = p.x * w;
      v24 = p.y * h;
      p.z = z;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = p.x * w;
      m_pCurrPosition[1] = v24;
      p.x = v23;
      m_pCurrPosition[2] = p.z;
      m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
      *meshBuilder.m_VertexBuilder.m_pCurrNormal = v19->m_Normal.x;
      y = v19->m_Normal.y;
      p.y = v24;
      m_pCurrNormal[1] = y;
      m_pCurrNormal[2] = v19->m_Normal.z;
      v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v21->x;
      v28[1] = v21->y;
      v29 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                     + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
      *v29 = *(_QWORD *)&v19->m_TangentS.x;
      v29[1] = *(_QWORD *)&v19->m_TangentS.z;
      i = 1258291455;
      vertID = 1258291455;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    }
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 1;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 2;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = meshBuilder.m_IndexBuilder.m_nIndexOffset;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 2;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                      + 3;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2);
          break;
        case MATERIAL_LINE_LOOP:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 2 * meshBuilder.m_VertexBuilder.m_nVertexCount);
          break;
        case MATERIAL_POLYGON:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6);
          break;
        case MATERIAL_QUADS:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4);
          break;
        case MATERIAL_INSTANCED_QUADS:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: 0);
          break;
        default:
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: meshBuilder.m_VertexBuilder.m_nVertexCount);
          break;
      }
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
    pBuildMesh->Draw_2(this: pBuildMesh, a2: -1, a3: 0);
    for ( i = 0; i < batchList.m_Size; ++i )
    {
      v30 = &tris_3.m_MaterialBatches.m_Memory.m_pMemory[batchList.m_Memory.m_pMemory[i]];
      v17->Bind(this: v17, a2: g_materialWireframeVertexColorNoCull, a3: nullptr);
      v31 = v17->GetDynamicMesh(this: v17, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
      v32 = v30->m_TriListIndices.m_Size;
      v47 = v31;
      batchIDa = v32;
      if ( v32 >= 32766 )
        batchIDa = 32766;
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: v31,
        type: MATERIAL_TRIANGLES,
        nVertexCount: v30->m_Verts.m_Size,
        nIndexCount: batchIDa,
        pMeshSettings: nullptr);
      vertID = 0;
      if ( v30->m_Verts.m_Size > 0 )
      {
        pBuildMesh = nullptr;
        do
        {
          v33 = (float *)((char *)pBuildMesh + (unsigned int)v30->m_Verts.m_Memory.m_pMemory);
          v34 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v35 = v33[11] * h;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v33[10] * w;
          v34[1] = v35;
          v34[2] = 0.0;
          v36 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
          *meshBuilder.m_VertexBuilder.m_pCurrNormal = v33[3];
          v36[1] = v33[4];
          v36[2] = v33[5];
          v37 = (_QWORD *)((char *)meshBuilder.m_VertexBuilder.m_pUserData
                         + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                         * meshBuilder.m_VertexBuilder.m_VertexSize_UserData);
          *v37 = *((_QWORD *)v33 + 3);
          v37[1] = *((_QWORD *)v33 + 4);
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0xFFFF;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          pBuildMesh = (IMesh *)((char *)pBuildMesh + 84);
          ++vertID;
        }
        while ( vertID < v30->m_Verts.m_Size );
      }
      v38 = 0;
      if ( batchIDa > 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                 + LOWORD(v30->m_TriListIndices.m_Memory.m_pMemory[v38]);
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          ++v38;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( v38 < batchIDa );
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
      v47->Draw_2(this: v47, a2: -1, a3: 0);
    }
    v17->MatrixMode(this: v17, a2: MATERIAL_VIEW);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_PROJECTION);
    v17->PopMatrix(this: v17);
    v17->MatrixMode(this: v17, a2: MATERIAL_MODEL);
    v17->PopMatrix(this: v17);
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
    v17->EndRender(this: v17);
    v17->Release(this: v17);
    if ( batchList.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchList.m_Memory.m_pMemory);
  }
  else
  {
LABEL_16:
    if ( batchList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410360
// Name: int DebugModelVertExtents(class IStudioRender __near *,struct DrawModelInfo_t __near &,struct matrix3x4_t __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DebugModelVertExtents(
        IStudioRender *pStudioRender,
        DrawModelInfo_t *info,
        matrix3x4_t *pBoneToWorld,
        Vector *vecMin,
        Vector *vecMax)
{
  int v5; // ebx
  Vector *v6; // edi
  void (__thiscall *GetTriangles)(IStudioRender *, const DrawModelInfo_t *, matrix3x4_t *, GetTriangles_Output_t *); // eax
  GetTriangles_MaterialBatch_t *m_pMemory; // eax
  int v9; // edx
  int *v10; // ecx
  const float *v11; // esi
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  char *v15; // edi
  float v16; // xmm3_4
  double x; // xmm3_8
  float y; // xmm4_4
  float v19; // xmm3_4
  double v20; // xmm3_8
  double v21; // xmm4_8
  float z; // xmm4_4
  float v23; // xmm3_4
  double v24; // xmm3_8
  double v25; // xmm4_8
  float v26; // xmm3_4
  double v27; // xmm0_8
  float v28; // xmm0_4
  double v29; // xmm0_8
  float v30; // xmm1_4
  float v31; // xmm0_4
  double v32; // xmm0_8
  double v33; // xmm1_8
  int v34; // eax
  Vector tmp; // [esp+8h] [ebp-2Ch] BYREF
  Vector skinnedPos; // [esp+14h] [ebp-20h] BYREF
  int *v38; // [esp+20h] [ebp-14h]
  _DWORD *v39; // [esp+24h] [ebp-10h]
  int v40; // [esp+28h] [ebp-Ch]
  int batchID; // [esp+2Ch] [ebp-8h]
  int vertID; // [esp+30h] [ebp-4h]
  IStudioRender *pStudioRendera; // [esp+3Ch] [ebp+8h]

  v5 = 0;
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    tris_4.m_MaterialBatches.m_Memory.m_pMemory = nullptr;
    tris_4.m_MaterialBatches.m_Memory.m_nAllocationCount = 0;
    tris_4.m_MaterialBatches.m_Memory.m_nGrowSize = 0;
    tris_4.m_MaterialBatches.m_Size = 0;
    tris_4.m_MaterialBatches.m_pElements = nullptr;
    atexit(func: DebugModelVertExtents_::_2_::_dynamic_atexit_destructor_for__tris__);
  }
  v6 = vecMax;
  vecMin->x = 999999.0;
  vecMin->y = 999999.0;
  vecMin->z = 999999.0;
  GetTriangles = pStudioRender->GetTriangles;
  vecMax->x = -999999.0;
  vecMax->y = -999999.0;
  vecMax->z = -999999.0;
  GetTriangles(this: pStudioRender, a2: info, a3: pBoneToWorld, a4: &tris_4);
  batchID = 0;
  if ( tris_4.m_MaterialBatches.m_Size > 0 )
  {
    m_pMemory = tris_4.m_MaterialBatches.m_Memory.m_pMemory;
    v9 = 0;
    v40 = 0;
    do
    {
      v10 = (int *)((char *)&m_pMemory->m_Verts.m_Size + v9);
      vertID = 0;
      v38 = v10;
      if ( *v10 > 0 )
      {
        v39 = (GetTriangles_Vertex_t **)((char *)&m_pMemory->m_Verts.m_Memory.m_pMemory + v9);
        pStudioRendera = nullptr;
        do
        {
          v11 = (const float *)((char *)pStudioRendera + *v39);
          v12 = 0.0;
          v13 = 0.0;
          v14 = 0.0;
          memset(&skinnedPos, 0, sizeof(skinnedPos));
          if ( *((int *)v11 + 20) > 0 )
          {
            v15 = (char *)(v11 + 12);
            do
            {
              VectorTransform(in1: v11, in2: &tris_4.m_PoseToWorld[*((_DWORD *)v15 + 4)], out: &tmp.x);
              v16 = *(float *)v15;
              ++v5;
              v12 = (float)(tmp.x * *(float *)v15) + skinnedPos.x;
              v13 = (float)(tmp.y * *(float *)v15) + skinnedPos.y;
              v14 = (float)(tmp.z * *(float *)v15) + skinnedPos.z;
              v15 += 4;
              skinnedPos.x = (float)(tmp.x * v16) + skinnedPos.x;
              skinnedPos.y = (float)(tmp.y * v16) + skinnedPos.y;
              skinnedPos.z = (float)(tmp.z * v16) + skinnedPos.z;
            }
            while ( v5 < *((_DWORD *)v11 + 20) );
            v6 = vecMax;
            v10 = v38;
            v5 = 0;
          }
          x = v12;
          if ( v12 > (double)vecMin->x )
            x = vecMin->x;
          y = vecMin->y;
          v19 = x;
          vecMin->x = v19;
          v20 = v13;
          v21 = y;
          if ( v13 > v21 )
            v20 = v21;
          z = vecMin->z;
          v23 = v20;
          vecMin->y = v23;
          v24 = v14;
          v25 = z;
          if ( v14 > v25 )
            v24 = v25;
          v26 = v24;
          vecMin->z = v26;
          v27 = v12;
          if ( v27 < v6->x )
            v27 = v6->x;
          v28 = v27;
          v6->x = v28;
          v29 = v13;
          if ( v13 < (double)v6->y )
            v29 = v6->y;
          v30 = v6->z;
          v31 = v29;
          v6->y = v31;
          v32 = v14;
          v33 = v30;
          if ( v14 < v33 )
            v32 = v33;
          pStudioRendera += 21;
          v34 = vertID + 1;
          v6->z = v32;
          vertID = v34;
        }
        while ( v34 < *v10 );
        m_pMemory = tris_4.m_MaterialBatches.m_Memory.m_pMemory;
        v9 = v40;
      }
      v9 += 44;
      ++batchID;
      v40 = v9;
    }
    while ( batchID < tris_4.m_MaterialBatches.m_Size );
  }
  return 0;
}

} // namespace hlmv
