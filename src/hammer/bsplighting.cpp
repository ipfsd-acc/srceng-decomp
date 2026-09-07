// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/bsplighting.cpp
// Functions: 16
// ============================================================

#include "hammer\bsplighting.h"

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: CVertexBuilder::~CVertexBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::~CVertexBuilder(CVertexBuilder *this)
{
  if ( this->m_pVertexBuffer != nullptr && this->m_pVertexBuffer->IsDynamic(this: this->m_pVertexBuffer) )
    this->m_pVertexBuffer->EndCastBuffer(this: this->m_pVertexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100028F0
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
// Address: 0x10002960
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
// Address: 0x100029E0
// Name: public: CIndexBuilder::~CIndexBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::~CIndexBuilder(CIndexBuilder *this)
{
  if ( this->m_pIndexBuffer != nullptr && this->m_pIndexBuffer->IsDynamic(this: this->m_pIndexBuffer) )
    this->m_pIndexBuffer->EndCastBuffer(this: this->m_pIndexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
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
// Address: 0x10002AE0
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
// Address: 0x10002B70
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
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
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
// Address: 0x10002C10
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
// Address: 0x10002D10
// Name: private: int CMeshBuilder::IndicesFromVertices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshBuilder::IndicesFromVertices(CMeshBuilder *this, MaterialPrimitiveType_t type, int nVertexCount)
{
  int result; // eax

  switch ( type )
  {
    case MATERIAL_LINE_STRIP:
      result = 2 * nVertexCount - 2;
      break;
    case MATERIAL_LINE_LOOP:
      result = 2 * nVertexCount;
      break;
    case MATERIAL_POLYGON:
      result = 3 * nVertexCount - 6;
      break;
    case MATERIAL_QUADS:
      result = 6 * nVertexCount / 4;
      break;
    case MATERIAL_INSTANCED_QUADS:
      result = 0;
      break;
    default:
      result = nVertexCount;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002D90
// Name: public: void CMeshBuilder::End(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::End(CMeshBuilder *this, bool bSpewData, bool bDraw)
{
  MaterialPrimitiveType_t m_Type; // edi
  int v5; // eax

  if ( this->m_bGenerateIndices )
  {
    m_Type = this->m_Type;
    v5 = CMeshBuilder::IndicesFromVertices(this, type: m_Type, nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v5);
  }
  if ( bSpewData )
    this->m_pMesh->Spew_2(
      this: this->m_pMesh,
      a2: this->m_VertexBuilder.m_nVertexCount,
      a3: this->m_IndexBuilder.m_nIndexCount,
      a4: this);
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  if ( bDraw )
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  this->m_pMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002E50
// Name: public: CRefPtr<class IMatRenderContext>::~CRefPtr<class IMatRenderContext>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefPtr<IMatRenderContext>::~CRefPtr<IMatRenderContext>(CRefPtr<IMatRenderContext> *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: public: CMatRenderContextPtr::~CMatRenderContextPtr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::~CMatRenderContextPtr(CMatRenderContextPtr *this)
{
  IMatRenderContext *m_pObject; // ecx

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->EndRender(this: m_pObject);
  if ( this->m_pObject != nullptr )
    ((void (__thiscall *)(IMatRenderContext *, CMatRenderContextPtr *))this->m_pObject->Release)(
      a1: this->m_pObject,
      a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10002EC0
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
// Address: 0x10002F40
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
// Address: 0x10003050
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
// Address: 0x10003110
// Name: public: CMatRenderContextPtr::CMatRenderContextPtr(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextPtr *__thiscall CMatRenderContextPtr::CMatRenderContextPtr(
        CMatRenderContextPtr *this,
        IMaterialSystem *pFrom)
{
  this->m_pObject = pFrom->GetRenderContext(this: pFrom);
  if ( this->m_pObject != nullptr )
    this->m_pObject->BeginRender(this: this->m_pObject);
  return this;
}
