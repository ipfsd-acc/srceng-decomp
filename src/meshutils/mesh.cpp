// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/mesh.cpp
// Functions: 24
// ============================================================

#include "meshutils\mesh.h"

//------------------------------------------------------------------------------
// Address: 0x004073A0
// Name: public: CMesh::CMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMesh *__thiscall CMesh::CMesh(CMesh *this)
{
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_nVertexCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nAttributeCount = 0;
  this->m_nIndexCount = 0;
  this->m_bAllocatedMeshData = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004073C0
// Name: public: void CMesh::AllocateMesh(int,int,int,class CMeshVertexAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::AllocateMesh(
        CMesh *this,
        int nVertexCount,
        int nIndexCount,
        int nVertexStride,
        CMeshVertexAttribute *pAttributes,
        int nAtrributeCount)
{
  int i; // eax

  if ( this->m_bAllocatedMeshData )
  {
    free(pMem: this->m_pVerts);
    free(pMem: this->m_pAttributes);
    free(pMem: this->m_pIndices);
  }
  this->m_nVertexCount = nVertexCount;
  this->m_nVertexStrideFloats = nVertexStride;
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_nIndexCount = nIndexCount;
  this->m_nAttributeCount = nAtrributeCount;
  this->m_bAllocatedMeshData = true;
  this->m_pVerts = (float *)operator new(nSize: 4 * nVertexStride * nVertexCount);
  this->m_pIndices = (unsigned int *)operator new(nSize: 4 * nIndexCount);
  this->m_pAttributes = (CMeshVertexAttribute *)operator new(nSize: 8 * nAtrributeCount);
  for ( i = 0; i < nAtrributeCount; ++i )
    this->m_pAttributes[i] = pAttributes[i];
}

//------------------------------------------------------------------------------
// Address: 0x00407490
// Name: public: int CMesh::FindFirstAttributeOffset(enum VertexElement_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMesh::FindFirstAttributeOffset(CMesh *this, VertexElement_t nType)
{
  int m_nAttributeCount; // edx
  int v3; // eax
  CMeshVertexAttribute *m_pAttributes; // esi
  VertexElement_t *i; // ecx

  m_nAttributeCount = this->m_nAttributeCount;
  v3 = 0;
  if ( m_nAttributeCount <= 0 )
    return -1;
  m_pAttributes = this->m_pAttributes;
  for ( i = &m_pAttributes->m_nType; *i != nType; i += 2 )
  {
    if ( ++v3 >= m_nAttributeCount )
      return -1;
  }
  return m_pAttributes[v3].m_nOffsetFloats;
}

//------------------------------------------------------------------------------
// Address: 0x004074D0
// Name: void DuplicateMesh(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DuplicateMesh(CMesh *pMeshOut, const CMesh *inputMesh)
{
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: inputMesh->m_nVertexCount,
    nIndexCount: inputMesh->m_nIndexCount,
    nVertexStride: inputMesh->m_nVertexStrideFloats,
    pAttributes: inputMesh->m_pAttributes,
    nAtrributeCount: inputMesh->m_nAttributeCount);
  memcpy(
    dst: (unsigned __int8 *)pMeshOut->m_pVerts,
    src: (unsigned __int8 *)inputMesh->m_pVerts,
    count: 4 * inputMesh->m_nVertexCount * inputMesh->m_nVertexStrideFloats);
  memcpy(
    dst: (unsigned __int8 *)pMeshOut->m_pIndices,
    src: (unsigned __int8 *)inputMesh->m_pIndices,
    count: 4 * inputMesh->m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x00407530
// Name: bool RationalizeUVsInPlace(class CMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RationalizeUVsInPlace(CMesh *pMesh)
{
  CMesh *v1; // ecx
  int m_nAttributeCount; // edx
  int v3; // eax
  CMeshVertexAttribute *m_pAttributes; // edi
  VertexElement_t *p_m_nType; // esi
  int m_nOffsetFloats; // esi
  int v7; // eax
  CMeshVertexAttribute *v8; // edi
  VertexElement_t *i; // esi
  int m_nIndexCount; // edx
  float *m_pVerts; // edi
  unsigned int v13; // edx
  double v14; // st6
  float *v15; // ebx
  double v16; // st7
  double v17; // st4
  int m_nVertexStrideFloats; // ecx
  float *v19; // edi
  double v20; // st5
  double v21; // st4
  double v22; // st6
  double v23; // rt1
  double v24; // st5
  double v25; // st7
  float *v26; // edi
  double X; // st5
  double v28; // st7
  bool v29; // zf
  float *v30; // eax
  float *v31; // eax
  unsigned int v32; // [esp+2Ch] [ebp-1Ch]
  float *v33; // [esp+30h] [ebp-18h]
  float *pTriVerts; // [esp+34h] [ebp-14h]
  float vMin_4; // [esp+3Ch] [ebp-Ch]
  float vMinFloor; // [esp+40h] [ebp-8h]

  v1 = pMesh;
  m_nAttributeCount = pMesh->m_nAttributeCount;
  v3 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_7;
  m_pAttributes = pMesh->m_pAttributes;
  p_m_nType = &m_pAttributes->m_nType;
  while ( *p_m_nType != VERTEX_ELEMENT_TEXCOORD2D_0 )
  {
    ++v3;
    p_m_nType += 2;
    if ( v3 >= m_nAttributeCount )
      goto LABEL_7;
  }
  m_nOffsetFloats = m_pAttributes[v3].m_nOffsetFloats;
  if ( m_nOffsetFloats < 0 )
  {
LABEL_7:
    v7 = 0;
    if ( m_nAttributeCount <= 0 )
      return 0;
    v8 = pMesh->m_pAttributes;
    for ( i = &v8->m_nType; *i != VERTEX_ELEMENT_TEXCOORD3D_0; i += 2 )
    {
      if ( ++v7 >= m_nAttributeCount )
        return 0;
    }
    m_nOffsetFloats = v8[v7].m_nOffsetFloats;
    if ( m_nOffsetFloats < 0 )
      return 0;
  }
  m_nIndexCount = pMesh->m_nIndexCount;
  if ( pMesh->m_nVertexCount != m_nIndexCount )
    return 0;
  m_pVerts = pMesh->m_pVerts;
  v13 = (unsigned __int64)(1431655766LL * m_nIndexCount) >> 32;
  if ( (int)(v13 + (v13 >> 31)) > 0 )
  {
    v32 = v13 + (v13 >> 31);
    while ( 1 )
    {
      v14 = 3.4028235e38;
      v15 = &m_pVerts[m_nOffsetFloats];
      v33 = v15 + 1;
      vMin_4 = 3.4028235e38;
      pTriVerts = m_pVerts;
      v16 = v15[1];
      if ( *v15 > 3.4028235e38 )
      {
        v17 = 3.4028235e38;
      }
      else
      {
        v17 = 3.4028235e38;
        v14 = *v15;
      }
      if ( v17 < v16 )
        v16 = 3.4028235e38;
      else
        vMin_4 = *v33;
      m_nVertexStrideFloats = v1->m_nVertexStrideFloats;
      v19 = &m_pVerts[m_nVertexStrideFloats];
      v20 = v19[m_nOffsetFloats];
      v21 = v14;
      v22 = v19[m_nOffsetFloats + 1];
      if ( v21 < v20 )
        v20 = v21;
      v23 = v20;
      v24 = v16;
      v25 = v23;
      if ( v24 < v22 )
        v22 = v24;
      else
        vMin_4 = v19[m_nOffsetFloats + 1];
      v26 = &v19[m_nVertexStrideFloats];
      X = v26[m_nOffsetFloats];
      if ( v25 < X )
        X = v25;
      if ( v22 >= v26[m_nOffsetFloats + 1] )
        vMin_4 = v26[m_nOffsetFloats + 1];
      m_pVerts = &v26[m_nVertexStrideFloats];
      vMinFloor = floor(X);
      v28 = floor(X: vMin_4);
      v29 = v32-- == 1;
      *v15 = *v15 - vMinFloor;
      *v33 = *v33 - v28;
      v30 = &pTriVerts[pMesh->m_nVertexStrideFloats];
      v30[m_nOffsetFloats] = v30[m_nOffsetFloats] - vMinFloor;
      v30[m_nOffsetFloats + 1] = v30[m_nOffsetFloats + 1] - v28;
      v31 = &v30[pMesh->m_nVertexStrideFloats];
      v31[m_nOffsetFloats] = v31[m_nOffsetFloats] - vMinFloor;
      v31[m_nOffsetFloats + 1] = v31[m_nOffsetFloats + 1] - v28;
      if ( v29 )
        break;
      v1 = pMesh;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407700
// Name: void DeIndexMesh(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeIndexMesh(CMesh *pMeshOut, const CMesh *inputMesh)
{
  float *m_pVerts; // ebx
  int i; // edi
  int m_nVertexStrideFloats; // ecx

  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: inputMesh->m_nIndexCount,
    nIndexCount: inputMesh->m_nIndexCount,
    nVertexStride: inputMesh->m_nVertexStrideFloats,
    pAttributes: inputMesh->m_pAttributes,
    nAtrributeCount: inputMesh->m_nAttributeCount);
  m_pVerts = pMeshOut->m_pVerts;
  for ( i = 0; i < inputMesh->m_nIndexCount; m_pVerts += m_nVertexStrideFloats )
  {
    CopyVertex(
      pOut: m_pVerts,
      pIn: &inputMesh->m_pVerts[inputMesh->m_nVertexStrideFloats * inputMesh->m_pIndices[i]],
      nFloats: inputMesh->m_nVertexStrideFloats);
    m_nVertexStrideFloats = inputMesh->m_nVertexStrideFloats;
    pMeshOut->m_pIndices[i] = i;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407770
// Name: void TessellateTriangle(class CUtlBuffer __near *,float const __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TessellateTriangle(CUtlBuffer *pOutTriangles, float **ppVertsIn, int nTexcoordOffset, int nVertexStride)
{
  double v4; // st6
  long double v5; // st5
  float *v6; // ebp
  const float *v7; // ecx
  int v8; // ebx
  long double v9; // st3
  long double v10; // st4
  double v11; // st7
  long double v12; // st7
  double v13; // rt2
  const float *v14; // edi
  long double v15; // st4
  long double v16; // st5
  double v17; // st6
  long double v18; // rt0
  double v19; // st5
  double v20; // rt2
  double v21; // st7
  double v22; // rtt
  long double v23; // st4
  long double v24; // st5
  double v25; // st6
  long double v26; // rt1
  double v27; // st5
  double v28; // rtt
  long double v29; // st7
  bool v30; // c0
  bool v31; // c3
  float *v32; // ebp
  int v33; // ebx
  const float *v34; // ecx
  const float *v35; // edx
  int pEdgeVertex1; // [esp+18h] [ebp-30h]
  int pEdgeVertex1a; // [esp+18h] [ebp-30h]
  float *nCornerPlus1; // [esp+1Ch] [ebp-2Ch]
  const float *pVerts0[3]; // [esp+20h] [ebp-28h] BYREF
  const float *pVerts1[3]; // [esp+2Ch] [ebp-1Ch] BYREF
  const float *pVerts2[3]; // [esp+38h] [ebp-10h] BYREF
  float *v42; // [esp+44h] [ebp-4h]

  v4 = -1.0;
  v5 = -1.0;
  v6 = *ppVertsIn;
  v7 = &ppVertsIn[1][nTexcoordOffset];
  pVerts0[0] = &(*ppVertsIn)[nTexcoordOffset + 1];
  v8 = -1;
  pEdgeVertex1 = -1;
  v9 = fabs(*v7 - (*ppVertsIn)[nTexcoordOffset]);
  v10 = fabs(v7[1] - *pVerts0[0]);
  if ( v9 > -1.0 )
  {
    v4 = v9;
    pEdgeVertex1 = -1;
    v8 = 0;
    v5 = -1.0;
  }
  if ( v10 <= v4 )
  {
    v12 = v10;
    if ( v10 <= -1.0 )
      v12 = v5;
    else
      pEdgeVertex1 = 0;
    v13 = v4;
    v4 = v12;
    v11 = v13;
  }
  else
  {
    pEdgeVertex1 = v8;
    v11 = v10;
    v8 = 0;
  }
  v14 = &ppVertsIn[2][nTexcoordOffset];
  v15 = fabs(*v14 - *v7);
  v16 = fabs(v14[1] - v7[1]);
  if ( v15 <= v11 )
  {
    if ( v15 > v4 )
    {
      v4 = v15;
      pEdgeVertex1 = 1;
    }
    v18 = v16;
    v19 = v11;
    v11 = v4;
    v20 = v19;
    v16 = v18;
    v17 = v20;
  }
  else
  {
    pEdgeVertex1 = v8;
    v17 = v15;
    v8 = 1;
  }
  if ( v16 <= v17 )
  {
    if ( v16 > v11 )
    {
      v11 = v16;
      pEdgeVertex1 = 1;
    }
    v22 = v17;
    v17 = v11;
    v21 = v22;
  }
  else
  {
    pEdgeVertex1 = v8;
    v21 = v16;
    v8 = 1;
  }
  v23 = fabs(v6[nTexcoordOffset] - *v14);
  v24 = fabs(*pVerts0[0] - v14[1]);
  if ( v23 <= v21 )
  {
    if ( v23 > v17 )
    {
      v17 = v23;
      pEdgeVertex1 = 2;
    }
    v26 = v24;
    v27 = v21;
    v21 = v17;
    v28 = v27;
    v24 = v26;
    v25 = v28;
  }
  else
  {
    pEdgeVertex1 = v8;
    v25 = v23;
    v8 = 2;
  }
  if ( v24 <= v25 )
  {
    v30 = v24 < v21;
    v31 = v24 == v21;
    v29 = v25;
    if ( !v30 && !v31 )
      pEdgeVertex1 = 2;
  }
  else
  {
    pEdgeVertex1 = v8;
    v29 = v24;
    v8 = 2;
  }
  if ( v29 <= 1.0 )
  {
    CUtlBuffer::Put(this: pOutTriangles, pMem: v6, size: 4 * nVertexStride);
    CUtlBuffer::Put(this: pOutTriangles, pMem: ppVertsIn[1], size: 4 * nVertexStride);
    CUtlBuffer::Put(this: pOutTriangles, pMem: ppVertsIn[2], size: 4 * nVertexStride);
  }
  else
  {
    v32 = (float *)operator new(nSize: 4 * nVertexStride);
    nCornerPlus1 = (float *)operator new(nSize: 4 * nVertexStride);
    v33 = pCornerTable[2 * v8 + v8 + pEdgeVertex1];
    pEdgeVertex1a = (v33 + 2) % 3;
    LerpVertex(
      pOutput: v32,
      pLeft: ppVertsIn[v33],
      pRight: ppVertsIn[(v33 + 1) % 3],
      flLerp: 0.5,
      nFloats: nVertexStride);
    LerpVertex(
      pOutput: nCornerPlus1,
      pLeft: ppVertsIn[pEdgeVertex1a],
      pRight: ppVertsIn[v33],
      flLerp: 0.5,
      nFloats: nVertexStride);
    pVerts0[1] = ppVertsIn[v33];
    pVerts0[2] = v32;
    pVerts1[0] = nCornerPlus1;
    TessellateTriangle(pOutTriangles, ppVertsIn: &pVerts0[1], nTexcoordOffset, nVertexStride);
    v34 = ppVertsIn[pEdgeVertex1a];
    pVerts1[2] = ppVertsIn[(v33 + 1) % 3];
    pVerts1[1] = v32;
    pVerts2[0] = v34;
    TessellateTriangle(pOutTriangles, ppVertsIn: &pVerts1[1], nTexcoordOffset, nVertexStride);
    v35 = ppVertsIn[pEdgeVertex1a];
    pVerts2[1] = v32;
    pVerts2[2] = v35;
    v42 = nCornerPlus1;
    TessellateTriangle(pOutTriangles, ppVertsIn: &pVerts2[1], nTexcoordOffset, nVertexStride);
    free(pMem: v32);
    free(pMem: nCornerPlus1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407A60
// Name: bool Vertex_CompareFunc(float __near * const __near &,float __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Vertex_CompareFunc(float *const *src1, float *const *src2)
{
  int v2; // edx
  char *i; // ecx

  v2 = 0;
  if ( g_nVertexStrideFloats <= 0 )
    return 1;
  for ( i = (char *)*src2;
        fabs(*(float *)&i[(char *)*src1 - (char *)*src2] - *(float *)i) <= *(float *)&i[(char *)g_pHashEpsilons
                                                                                      - (char *)*src2];
        i += 4 )
  {
    if ( ++v2 >= g_nVertexStrideFloats )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407AB0
// Name: unsigned int Vertex_HashFunc(float __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Vertex_HashFunc(float *const *pVertex)
{
  unsigned int v1; // ecx

  v1 = (**(_DWORD **)pVertex + 11 * *((_DWORD *)*pVertex + 1) - 17 * *((_DWORD *)*pVertex + 2)) & 0x7FFFFFFF;
  return v1 ^ ((v1 ^ (v1 >> 10)) >> 12);
}

//------------------------------------------------------------------------------
// Address: 0x00407AE0
// Name: public: int CUtlScalarHash<struct EdgeHash_t>::Insert(unsigned int,struct EdgeHash_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<EdgeHash_t>::Insert(
        CUtlScalarHash<EdgeHash_t> *this,
        unsigned int uiKey,
        const EdgeHash_t *data)
{
  unsigned int m_uiBucketMask; // edx
  CUtlScalarHash<EdgeHash_t>::HashScalarData_t *m_pData; // edi
  unsigned int result; // eax

  if ( this->m_dataCount > this->m_maxData )
    CUtlScalarHash<EdgeHash_t>::Grow(this);
  m_uiBucketMask = this->m_uiBucketMask;
  m_pData = this->m_pData;
  ++this->m_dataCount;
  for ( result = m_uiBucketMask
               & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
        m_pData[result].m_uiKey != -1;
        result = m_uiBucketMask & (result + 1) )
  {
    ;
  }
  m_pData[result].m_uiKey = uiKey;
  this->m_pData[result].m_Data = *data;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407B80
// Name: public: int CUtlScalarHash<struct EdgeHash_t>::Find(unsigned int,struct EdgeHash_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<EdgeHash_t>::Find(
        CUtlScalarHash<EdgeHash_t> *this,
        unsigned int uiKey,
        const EdgeHash_t *dataRecord)
{
  CUtlScalarHash<EdgeHash_t>::HashScalarData_t *m_pData; // edx
  unsigned int m_uiBucketMask; // edi
  unsigned int result; // eax
  unsigned int m_uiKey; // esi
  CUtlScalarHash<EdgeHash_t>::HashScalarData_t *v7; // ecx

  m_pData = this->m_pData;
  m_uiBucketMask = this->m_uiBucketMask;
  result = this->m_uiBucketMask
         & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  m_uiKey = m_pData[result].m_uiKey;
  v7 = &m_pData[result];
  if ( m_uiKey == -1 )
    return -1;
  while ( m_uiKey != uiKey || dataRecord->m_nV0 != v7->m_Data.m_nV0 || dataRecord->m_nV1 != v7->m_Data.m_nV1 )
  {
    result = m_uiBucketMask & (result + 1);
    m_uiKey = m_pData[result].m_uiKey;
    v7 = &m_pData[result];
    if ( m_uiKey == -1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407C20
// Name: public: void CUtlScalarHash<struct EdgeHash_t>::Grow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlScalarHash<EdgeHash_t>::Grow(CUtlScalarHash<EdgeHash_t> *this)
{
  int v2; // edi
  CUtlScalarHash<EdgeHash_t>::HashScalarData_t *m_pData; // ebx
  int v4; // ebp
  unsigned int v5; // eax
  int v6; // eax
  CUtlScalarHash<EdgeHash_t>::HashScalarData_t *v7; // ebp

  v2 = 2 * this->m_maxData;
  m_pData = this->m_pData;
  v4 = 4 * this->m_maxData;
  v5 = 80 * this->m_maxData;
  this->m_maxData = v2;
  this->m_pData = (CUtlScalarHash<EdgeHash_t>::HashScalarData_t *)operator new(nSize: v5);
  this->m_uiBucketMask = v4 - 1;
  this->m_dataCount = 0;
  if ( v4 > 0 )
  {
    v6 = 0;
    do
    {
      this->m_pData[v6++].m_uiKey = -1;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v2 > 0 )
  {
    v7 = m_pData;
    do
    {
      if ( v7->m_uiKey != -1 )
        CUtlScalarHash<EdgeHash_t>::Insert(this, uiKey: v7->m_uiKey, data: &v7->m_Data);
      ++v7;
      --v2;
    }
    while ( v2 != 0 );
  }
  free(pMem: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: public: CMesh::~CMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::~CMesh(CMesh *this)
{
  if ( this->m_bAllocatedMeshData )
  {
    free(pMem: this->m_pVerts);
    free(pMem: this->m_pAttributes);
    free(pMem: this->m_pIndices);
  }
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_bAllocatedMeshData = false;
  this->m_nAttributeCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nVertexCount = 0;
  this->m_nIndexCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00407DB0
// Name: public: bool CMesh::CalculateBounds(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateBounds(CMesh *this, Vector *pMinOut, Vector *pMaxOut)
{
  double v3; // st7
  int m_nAttributeCount; // esi
  double v5; // st6
  double v6; // st5
  int v7; // eax
  double v8; // st4
  double v9; // st3
  double v10; // st2
  CMeshVertexAttribute *m_pAttributes; // edi
  VertexElement_t *i; // edx
  int m_nOffsetFloats; // eax
  float *v15; // edx
  int m_nVertexCount; // eax
  int v17; // ecx
  int v18; // esi
  double v19; // rt0
  double v20; // st2
  double v21; // st6
  double v22; // rt1
  double v23; // st2
  double v24; // st5
  double v25; // rt2
  double v26; // st2
  double v27; // st7
  double v28; // rtt
  double v29; // st2
  double v30; // st3
  double v31; // rt0
  double v32; // st2
  double v33; // st6
  double v34; // rt1
  double v35; // st2
  double v36; // st4
  double v37; // rt2
  double v38; // st2
  double v39; // st3
  double v40; // rtt
  double v41; // st2
  double v42; // rt0
  double v43; // st2
  double v44; // rt1
  double v45; // st2
  double v46; // rt2
  double v47; // st2
  double v48; // rtt

  v3 = 3.4028235e38;
  m_nAttributeCount = this->m_nAttributeCount;
  v5 = 3.4028235e38;
  v6 = 3.4028235e38;
  v7 = 0;
  v8 = -3.4028235e38;
  v9 = -3.4028235e38;
  v10 = -3.4028235e38;
  if ( m_nAttributeCount <= 0 )
    return 0;
  m_pAttributes = this->m_pAttributes;
  for ( i = &m_pAttributes->m_nType; *i != VERTEX_ELEMENT_POSITION; i += 2 )
  {
    if ( ++v7 >= m_nAttributeCount )
      return 0;
  }
  m_nOffsetFloats = m_pAttributes[v7].m_nOffsetFloats;
  if ( m_nOffsetFloats < 0 )
    return 0;
  v15 = &this->m_pVerts[m_nOffsetFloats];
  m_nVertexCount = this->m_nVertexCount;
  if ( m_nVertexCount > 0 )
  {
    v17 = 4 * this->m_nVertexStrideFloats;
    v18 = m_nVertexCount;
    do
    {
      v19 = v10;
      v20 = v5;
      v21 = v19;
      if ( v20 > *v15 )
        v20 = *v15;
      v22 = v20;
      v23 = v6;
      v24 = v22;
      if ( v23 > v15[1] )
        v23 = v15[1];
      v25 = v23;
      v26 = v3;
      v27 = v25;
      if ( v26 > v15[2] )
        v26 = v15[2];
      v28 = v26;
      v29 = v9;
      v30 = v28;
      if ( v29 < *v15 )
        v29 = *v15;
      v31 = v29;
      v32 = v21;
      v33 = v31;
      if ( v32 < v15[1] )
        v32 = v15[1];
      v34 = v32;
      v35 = v8;
      v36 = v34;
      if ( v35 < v15[2] )
        v35 = v15[2];
      v37 = v35;
      v38 = v30;
      v39 = v37;
      v15 = (float *)((char *)v15 + v17);
      --v18;
      v40 = v38;
      v41 = v27;
      v3 = v40;
      v42 = v41;
      v43 = v24;
      v6 = v42;
      v44 = v43;
      v45 = v33;
      v5 = v44;
      v46 = v45;
      v47 = v39;
      v9 = v46;
      v48 = v47;
      v10 = v36;
      v8 = v48;
    }
    while ( v18 != 0 );
  }
  pMinOut->x = v5;
  pMinOut->y = v6;
  pMinOut->z = v3;
  pMaxOut->x = v9;
  pMaxOut->y = v10;
  pMaxOut->z = v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407EC0
// Name: bool RationalizeUVs(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RationalizeUVs(CMesh *pRationalMeshOut, const CMesh *inputMesh)
{
  if ( inputMesh->m_nVertexCount == inputMesh->m_nIndexCount )
    CMesh::AllocateMesh(
      this: pRationalMeshOut,
      nVertexCount: inputMesh->m_nIndexCount,
      nIndexCount: inputMesh->m_nIndexCount,
      nVertexStride: inputMesh->m_nVertexStrideFloats,
      pAttributes: inputMesh->m_pAttributes,
      nAtrributeCount: inputMesh->m_nAttributeCount);
  else
    DeIndexMesh(pMeshOut: pRationalMeshOut, inputMesh);
  return RationalizeUVsInPlace(pMesh: pRationalMeshOut);
}

//------------------------------------------------------------------------------
// Address: 0x00407F10
// Name: public: bool CUtlScalarHash<struct EdgeHash_t>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlScalarHash<EdgeHash_t>::Init(CUtlScalarHash<EdgeHash_t> *this, int nBucketCount)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  bool v6; // sf
  int v7; // ecx

  v3 = (((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 8)
      | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 4)
      | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
      | ((unsigned int)(nBucketCount - 1) >> 1)
      | (nBucketCount - 1)
      | ((((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
            | ((unsigned int)(nBucketCount - 1) >> 1)
            | (nBucketCount - 1)) >> 4)
          | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 8)
        | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 16))
     + 1;
  v4 = 2 * v3;
  this->m_maxData = v3;
  this->m_pData = (CUtlScalarHash<EdgeHash_t>::HashScalarData_t *)operator new(nSize: 40 * v3);
  v5 = 2 * this->m_maxData;
  v6 = (this->m_maxData & 0x40000000) != 0;
  this->m_uiBucketMask = v4 - 1;
  if ( !v6 && v5 != 0 )
  {
    v7 = 0;
    do
    {
      this->m_pData[v7++].m_uiKey = -1;
      --v5;
    }
    while ( v5 != 0 );
  }
  this->m_dataCount = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408050
// Name: public: bool CMesh::CalculateAdjacency(int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateAdjacency(CMesh *this, int *pAdjacencyOut, int nSizeAdjacencyOut)
{
  int m_nIndexCount; // eax
  int v6; // ebp
  int m_uiBucketMask; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  unsigned int *m_pIndices; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // eax
  bool v18; // cc
  int v19; // ebp
  int v20; // eax
  int v21; // edi
  int v22; // ebx
  unsigned int *v23; // esi
  int v24; // ecx
  int v25; // edx
  int v26; // eax
  unsigned int v27; // eax
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // [esp+4h] [ebp-2Ch]
  int v32; // [esp+4h] [ebp-2Ch]
  CUtlScalarHash<EdgeHash_t> edgeHash; // [esp+Ch] [ebp-24h] BYREF
  EdgeHash_t tmp; // [esp+1Ch] [ebp-14h] BYREF
  int v36; // [esp+2Ch] [ebp-4h]
  int nIndex; // [esp+38h] [ebp+8h]
  int nIndexa; // [esp+38h] [ebp+8h]

  m_nIndexCount = this->m_nIndexCount;
  if ( nSizeAdjacencyOut != m_nIndexCount )
    return 0;
  v6 = 0;
  memset(&edgeHash.m_pData, 0, 12);
  tmp.m_nV0 = 0;
  CUtlScalarHash<EdgeHash_t>::Init(
    this: (CUtlScalarHash<EdgeHash_t> *)&edgeHash.m_pData,
    nBucketCount: 2 * m_nIndexCount);
  m_uiBucketMask = this->m_nIndexCount / 3;
  v8 = 0;
  edgeHash.m_uiBucketMask = m_uiBucketMask;
  nIndex = 0;
  v31 = 0;
  if ( m_uiBucketMask > 0 )
  {
    v36 = -1;
    do
    {
      v9 = 0;
      tmp.m_nTri1 = v8;
      v10 = v6;
      do
      {
        v11 = v9 + 1;
        m_pIndices = this->m_pIndices;
        v13 = m_pIndices[v10];
        v14 = nIndex + (v9 + 1) % 3;
        v15 = m_pIndices[v14];
        if ( v15 < v13 )
        {
          v15 = m_pIndices[v10];
          v13 = m_pIndices[v14];
        }
        tmp.m_nV1 = v13;
        v16 = v15 ^ __ROL4__(v13, 16);
        tmp.m_nTri0 = v15;
        v17 = CUtlScalarHash<EdgeHash_t>::Find(
                this: (CUtlScalarHash<EdgeHash_t> *)&edgeHash.m_pData,
                uiKey: v16,
                dataRecord: (const EdgeHash_t *)&tmp.m_nV1);
        if ( v17 == -1 )
          CUtlScalarHash<EdgeHash_t>::Insert(
            this: (CUtlScalarHash<EdgeHash_t> *)&edgeHash.m_pData,
            uiKey: v16,
            data: (const EdgeHash_t *)&tmp.m_nV1);
        else
          *(_DWORD *)(edgeHash.m_maxData + 20 * v17 + 16) = v31;
        v9 = v11;
        ++v10;
      }
      while ( v11 < 3 );
      m_uiBucketMask = edgeHash.m_uiBucketMask;
      v8 = v31 + 1;
      v6 = nIndex + 3;
      v18 = v31 + 1 < (signed int)edgeHash.m_uiBucketMask;
      nIndex += 3;
      ++v31;
    }
    while ( v18 );
  }
  v19 = 0;
  nIndexa = 0;
  v32 = 0;
  if ( m_uiBucketMask > 0 )
  {
    tmp.m_nTri1 = -1;
    v36 = -1;
    do
    {
      v20 = 0;
      v21 = v19;
      do
      {
        v22 = v20 + 1;
        v23 = this->m_pIndices;
        v24 = v23[v21];
        v25 = nIndexa + (v20 + 1) % 3;
        v26 = v23[v25];
        if ( v26 < v24 )
        {
          v26 = v23[v21];
          v24 = v23[v25];
        }
        tmp.m_nV1 = v24;
        tmp.m_nTri0 = v26;
        v27 = CUtlScalarHash<EdgeHash_t>::Find(
                this: (CUtlScalarHash<EdgeHash_t> *)&edgeHash.m_pData,
                uiKey: v26 ^ __ROL4__(v24, 16),
                dataRecord: (const EdgeHash_t *)&tmp.m_nV1);
        v28 = v32;
        v29 = edgeHash.m_maxData + 20 * v27 + 4;
        v30 = *(_DWORD *)(v29 + 8);
        if ( v30 == v32 )
          pAdjacencyOut[v21] = *(_DWORD *)(v29 + 12);
        else
          pAdjacencyOut[v21] = v30;
        v20 = v22;
        ++v21;
      }
      while ( v22 < 3 );
      v19 = nIndexa + 3;
      nIndexa += 3;
      ++v32;
    }
    while ( v28 + 1 < (int)edgeHash.m_uiBucketMask );
  }
  free(pMem: (void *)edgeHash.m_maxData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408240
// Name: protected: bool CUtlHash<float __near *,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &)>::DoFind(float __near * const __near &,unsigned int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::DoFind(
        CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *this,
        float *const *src,
        unsigned int *pBucket,
        int *pIndex)
{
  unsigned int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // edx
  int m_Size; // ebp
  CUtlVector<float *,CUtlMemory<float *,int> > *v9; // ebx
  int i; // esi

  v5 = this->m_KeyFunc(a1: src);
  if ( this->m_bPowerOfTwo )
    v6 = v5 & this->m_ModMask;
  else
    v6 = v5 % this->m_Buckets.m_Size;
  *pBucket = v6;
  v7 = v6;
  m_Size = this->m_Buckets.m_Memory.m_pMemory[v7].m_Size;
  v9 = &this->m_Buckets.m_Memory.m_pMemory[v7];
  for ( i = 0; i < m_Size; ++i )
  {
    if ( this->m_CompareFunc(a1: &v9->m_Memory.m_pMemory[i], a2: src) )
      break;
  }
  if ( i == m_Size )
    return 0;
  *pIndex = i;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408440
// Name: public: void CUtlHash<float __near *,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &)>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::Purge(
        CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *this)
{
  int v1; // edi
  int m_Size; // ebx
  CUtlVector<float *,CUtlMemory<float *,int> > *v3; // esi
  bool v4; // sf
  CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *v5; // [esp+4h] [ebp-4h]

  v5 = this;
  if ( this->m_Buckets.m_Size > 0 )
  {
    v1 = 0;
    m_Size = this->m_Buckets.m_Size;
    do
    {
      v3 = &this->m_Buckets.m_Memory.m_pMemory[v1];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v5;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      ++v1;
      --m_Size;
      v3->m_pElements = v3->m_Memory.m_pMemory;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408510
// Name: bool TessellateOnWrappedUV(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TessellateOnWrappedUV(CMesh *pMeshOut, const CMesh *inputMesh)
{
  int m_nAttributeCount; // ecx
  int v3; // eax
  CMeshVertexAttribute *m_pAttributes; // esi
  VertexElement_t *p_m_nType; // edx
  int m_nOffsetFloats; // ebx
  int v7; // eax
  CMeshVertexAttribute *v8; // esi
  VertexElement_t *i; // edx
  int j; // esi
  unsigned int *m_pIndices; // ecx
  int m_nVertexStrideFloats; // eax
  float *m_pVerts; // edx
  const float *v15; // ebp
  unsigned __int8 *v16; // edx
  int v17; // ecx
  signed int v18; // esi
  signed int k; // eax
  char v20; // bl
  const float *pVerts[3]; // [esp+8h] [ebp-40h] BYREF
  CUtlBuffer triangleBuffer; // [esp+14h] [ebp-34h] BYREF

  m_nAttributeCount = inputMesh->m_nAttributeCount;
  v3 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_7;
  m_pAttributes = inputMesh->m_pAttributes;
  p_m_nType = &m_pAttributes->m_nType;
  while ( *p_m_nType != VERTEX_ELEMENT_TEXCOORD2D_0 )
  {
    ++v3;
    p_m_nType += 2;
    if ( v3 >= m_nAttributeCount )
      goto LABEL_7;
  }
  m_nOffsetFloats = m_pAttributes[v3].m_nOffsetFloats;
  if ( m_nOffsetFloats < 0 )
  {
LABEL_7:
    v7 = 0;
    if ( m_nAttributeCount <= 0 )
      return 0;
    v8 = inputMesh->m_pAttributes;
    for ( i = &v8->m_nType; *i != VERTEX_ELEMENT_TEXCOORD3D_0; i += 2 )
    {
      if ( ++v7 >= m_nAttributeCount )
        return 0;
    }
    m_nOffsetFloats = v8[v7].m_nOffsetFloats;
    if ( m_nOffsetFloats < 0 )
      return 0;
  }
  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&triangleBuffer.m_Memory.m_nAllocationCount,
    growSize: 0,
    initSize: 0,
    nFlags: 0);
  for ( j = 0; j < inputMesh->m_nIndexCount; j += 3 )
  {
    m_pIndices = inputMesh->m_pIndices;
    m_nVertexStrideFloats = inputMesh->m_nVertexStrideFloats;
    m_pVerts = inputMesh->m_pVerts;
    pVerts[1] = &inputMesh->m_pVerts[m_nVertexStrideFloats * m_pIndices[j]];
    v15 = &m_pVerts[m_nVertexStrideFloats * m_pIndices[j + 1]];
    v16 = (unsigned __int8 *)&m_pVerts[m_nVertexStrideFloats * m_pIndices[j + 2]];
    pVerts[2] = v15;
    triangleBuffer.m_Memory.m_pMemory = v16;
    TessellateTriangle(
      pOutTriangles: (CUtlBuffer *)&triangleBuffer.m_Memory.m_nAllocationCount,
      ppVertsIn: (float **)&pVerts[1],
      nTexcoordOffset: m_nOffsetFloats,
      nVertexStride: m_nVertexStrideFloats);
  }
  v17 = inputMesh->m_nVertexStrideFloats;
  v18 = *(_DWORD *)&triangleBuffer.m_Error / (unsigned int)(4 * v17);
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: v18,
    nIndexCount: v18,
    nVertexStride: v17,
    pAttributes: inputMesh->m_pAttributes,
    nAtrributeCount: inputMesh->m_nAttributeCount);
  memcpy(
    dst: (unsigned __int8 *)pMeshOut->m_pVerts,
    src: (unsigned __int8 *)triangleBuffer.m_Memory.m_nAllocationCount,
    count: *(unsigned int *)&triangleBuffer.m_Error);
  for ( k = 0; k < v18; ++k )
    pMeshOut->m_pIndices[k] = k;
  v20 = RationalizeUVsInPlace(pMesh: pMeshOut);
  if ( triangleBuffer.m_Get >= 0 && triangleBuffer.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)triangleBuffer.m_Memory.m_nAllocationCount);
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x00408710
// Name: public: unsigned int CUtlHash<float __near *,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &)>::Insert(float __near * const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::Insert(
        CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *this,
        unsigned int src,
        bool *pDidInsert)
{
  KeyValues **v3; // ebx
  unsigned int result; // eax
  unsigned int v6; // esi
  int pIndex; // [esp+8h] [ebp-4h] BYREF

  v3 = (KeyValues **)src;
  if ( CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::DoFind(
         this,
         (float *const *)src,
         pBucket: &src,
         &pIndex) != 0 )
  {
    result = pIndex | (src << 16);
    *pDidInsert = false;
  }
  else
  {
    v6 = src;
    *pDidInsert = true;
    return (v6 << 16)
         | CUtlVector<float *,CUtlMemory<float *,int>>::InsertBefore(
             this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&this->m_Buckets.m_Memory.m_pMemory[v6],
             elem: this->m_Buckets.m_Memory.m_pMemory[v6].m_Size,
             src: v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004089E0
// Name: public: bool CMesh::CalculateIndicentFacesForVertices(class CUtlLinkedList<int,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<int,unsigned short>,unsigned short>> __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateIndicentFacesForVertices(
        CMesh *this,
        CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short> > *pFacesPerVertex,
        int nFacesPerVertexSize)
{
  int m_nIndexCount; // kr00_4
  int v5; // esi
  unsigned int *m_pIndices; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // ebx
  CMesh *nFaces; // [esp+0h] [ebp-8h]

  nFaces = this;
  if ( nFacesPerVertexSize != this->m_nVertexCount )
    return 0;
  m_nIndexCount = this->m_nIndexCount;
  v5 = 0;
  nFacesPerVertexSize = 0;
  if ( m_nIndexCount / 3 > 0 )
  {
    while ( 1 )
    {
      m_pIndices = this->m_pIndices;
      v7 = *(unsigned int *)((char *)m_pIndices + v5);
      v8 = *(unsigned int *)((char *)m_pIndices + v5 + 4);
      v9 = v5 + 4;
      v10 = *(unsigned int *)((char *)m_pIndices + v9 + 4);
      v5 = v9 + 8;
      CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AddToTail(
        this: &pFacesPerVertex[v7],
        src: &nFacesPerVertexSize);
      CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AddToTail(
        this: &pFacesPerVertex[v8],
        src: &nFacesPerVertexSize);
      CUtlLinkedList<int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<int,unsigned short>,unsigned short>>::AddToTail(
        this: &pFacesPerVertex[v10],
        src: &nFacesPerVertexSize);
      if ( ++nFacesPerVertexSize >= m_nIndexCount / 3 )
        break;
      this = nFaces;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408AA0
// Name: public: CUtlHash<float __near *,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &)>::CUtlHash<float __near *,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &)>(int,int,int,bool (*)(float __near * const __near &,float __near * const __near &),unsigned int (*)(float __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *__thiscall CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>(
        CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *this,
        bool (__cdecl *bucketCount)(float *const *, float *const *),
        int growCount,
        int initCount,
        bool (__cdecl *compareFunc)(float *const *, float *const *),
        unsigned int (__cdecl *keyFunc)(float *const *))
{
  int v7; // ebx
  int v8; // esi
  CUtlMemory<KeyValues *,int> *v9; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v12; // eax
  bool v13; // zf
  bool (__cdecl *compareFunca)(float *const *, float *const *); // [esp+1Ch] [ebp+10h]

  v7 = 0;
  this->m_KeyFunc = keyFunc;
  this->m_Buckets.m_Memory.m_pMemory = nullptr;
  this->m_Buckets.m_Memory.m_nAllocationCount = 0;
  this->m_Buckets.m_Memory.m_nGrowSize = 0;
  this->m_Buckets.m_Size = 0;
  this->m_Buckets.m_pElements = nullptr;
  this->m_CompareFunc = compareFunc;
  CUtlVector<CUtlVector<float *,CUtlMemory<float *,int>>,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>>::RemoveAll(this: &this->m_Buckets);
  v8 = (int)bucketCount;
  CUtlVector<CUtlVector<float *,CUtlMemory<float *,int>>,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>>::InsertMultipleBefore(
    this: &this->m_Buckets,
    elem: this->m_Buckets.m_Size,
    num: (int)bucketCount,
    pToInsert: nullptr);
  if ( (int)bucketCount > 0 )
  {
    for ( compareFunca = bucketCount;
          compareFunca != nullptr;
          compareFunca = (bool (__cdecl *)(float *const *, float *const *))((char *)compareFunca - 1) )
    {
      v9 = (CUtlMemory<KeyValues *,int> *)&this->m_Buckets.m_Memory.m_pMemory[v7];
      v9[1].m_pMemory = nullptr;
      if ( initCount != 0 )
      {
        m_nAllocationCount = v9->m_nAllocationCount;
        if ( initCount > m_nAllocationCount )
          CUtlMemory<KeyValues *,int>::Grow(this: v9, num: initCount - m_nAllocationCount);
        v9[1].m_pMemory = (KeyValues **)((char *)v9[1].m_pMemory + initCount);
        m_pMemory = (unsigned __int8 *)v9->m_pMemory;
        v12 = (int)v9[1].m_pMemory - initCount;
        v13 = v9[1].m_pMemory == (KeyValues **)initCount;
        v9[1].m_nAllocationCount = (int)v9->m_pMemory;
        if ( v12 >= 0 && !v13 && initCount > 0 )
          memmove(dst: &m_pMemory[4 * initCount], src: m_pMemory, count: 4 * v12);
      }
      this->m_Buckets.m_Memory.m_pMemory[v7++].m_Memory.m_nGrowSize = growCount;
    }
    v8 = (int)bucketCount;
  }
  this->m_bPowerOfTwo = ((v8 - 1) & v8) == 0;
  if ( ((v8 - 1) & v8) != 0 )
    this->m_ModMask = 0;
  else
    this->m_ModMask = v8 - 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408B90
// Name: bool WeldVertices(class CMesh __near *,class CMesh const __near &,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WeldVertices(CMesh *pMeshOut, const CMesh *inputMesh, float *pEpsilons, float *nEpsilons)
{
  const CMesh *v4; // esi
  unsigned __int8 *v6; // ebp
  int v7; // edi
  float **m_pElements; // ebx
  bool v9; // cc
  unsigned int v10; // eax
  int v11; // eax
  int i; // edi
  int j; // eax
  CUtlVector<float *,CUtlMemory<float *,int> > inOrderVertices; // [esp+0h] [ebp-3Ch] BYREF
  CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> vertexHash; // [esp+14h] [ebp-28h] BYREF

  v4 = inputMesh;
  if ( nEpsilons != (float *)inputMesh->m_nVertexStrideFloats )
    return 0;
  v6 = (unsigned __int8 *)operator new(nSize: 4 * inputMesh->m_nVertexCount);
  v7 = 0;
  if ( v6 == nullptr )
    return 0;
  memset(dst: v6, value: 0xFFu, count: 4 * v4->m_nVertexCount);
  g_pHashEpsilons = pEpsilons;
  g_nVertexStrideFloats = v4->m_nVertexStrideFloats;
  CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>(
    this: (CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *)&vertexHash.m_Buckets.m_Memory.m_nAllocationCount,
    bucketCount: (bool (__cdecl *)(float *const *, float *const *))v4->m_nVertexCount,
    growCount: 0,
    initCount: 0,
    compareFunc: (bool (__cdecl *)(float *const *, float *const *))Vertex_CompareFunc,
    keyFunc: Vertex_HashFunc);
  m_pElements = nullptr;
  v9 = v4->m_nVertexCount <= 0;
  memset(&inOrderVertices.m_Memory.m_nAllocationCount, 0, 16);
  vertexHash.m_Buckets.m_Memory.m_pMemory = nullptr;
  if ( !v9 )
  {
    do
    {
      nEpsilons = &v4->m_pVerts[v7 * v4->m_nVertexStrideFloats];
      LOBYTE(inputMesh) = 0;
      v10 = CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::Insert(
              this: (CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *)&vertexHash.m_Buckets.m_Memory.m_nAllocationCount,
              src: (unsigned int)&nEpsilons,
              pDidInsert: (bool *)&inputMesh);
      if ( (_BYTE)inputMesh != 0 )
      {
        v11 = CUtlVector<float *,CUtlMemory<float *,int>>::InsertBefore(
                this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&inOrderVertices.m_Memory.m_nAllocationCount,
                elem: (int)m_pElements,
                src: (KeyValues **)&nEpsilons);
        m_pElements = inOrderVertices.m_pElements;
        *(_DWORD *)&v6[4 * v7] = v11;
      }
      else
      {
        *(_DWORD *)&v6[4 * v7] = *(_DWORD *)&v6[4
                                              * (((signed int)(*(_DWORD *)(*(_DWORD *)(vertexHash.m_Buckets.m_Memory.m_nAllocationCount
                                                                                     + 20 * HIWORD(v10))
                                                                         + 4 * (unsigned __int16)v10)
                                                             - (unsigned int)v4->m_pVerts) >> 2)
                                               / v4->m_nVertexStrideFloats)];
      }
      ++v7;
    }
    while ( v7 < v4->m_nVertexCount );
  }
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: (int)m_pElements,
    nIndexCount: v4->m_nIndexCount,
    nVertexStride: v4->m_nVertexStrideFloats,
    pAttributes: v4->m_pAttributes,
    nAtrributeCount: v4->m_nAttributeCount);
  for ( i = 0; i < (int)inOrderVertices.m_pElements; ++i )
    CopyVertex(
      pOut: &pMeshOut->m_pVerts[i * pMeshOut->m_nVertexStrideFloats],
      pIn: *(const float **)(inOrderVertices.m_Memory.m_nAllocationCount + 4 * i),
      nFloats: v4->m_nVertexStrideFloats);
  for ( j = 0; j < v4->m_nIndexCount; ++j )
    pMeshOut->m_pIndices[j] = *(_DWORD *)&v6[4 * v4->m_pIndices[j]];
  free(pMem: v6);
  if ( inOrderVertices.m_Size >= 0 && inOrderVertices.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)inOrderVertices.m_Memory.m_nAllocationCount);
  CUtlHash<float *,bool (__cdecl *)(float * const &,float * const &),unsigned int (__cdecl *)(float * const &)>::Purge(this: (CUtlHash<float *,bool (__cdecl*)(float * const &,float * const &),unsigned int (__cdecl*)(float * const &)> *)&vertexHash.m_Buckets.m_Memory.m_nAllocationCount);
  CUtlVector<CUtlVector<float *,CUtlMemory<float *,int>>,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<float *,CUtlMemory<float *,int> >,CUtlMemory<CUtlVector<float *,CUtlMemory<float *,int> >,int> > *)&vertexHash.m_Buckets.m_Memory.m_nAllocationCount);
  if ( vertexHash.m_Buckets.m_Size >= 0 && vertexHash.m_Buckets.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)vertexHash.m_Buckets.m_Memory.m_nAllocationCount);
  return 1;
}

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00570480
// Name: public: void CMesh::FreeAllMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::FreeAllMemory(CMesh *this)
{
  if ( this->m_bAllocatedMeshData )
  {
    free(pMem: this->m_pVerts);
    free(pMem: this->m_pAttributes);
    free(pMem: this->m_pIndices);
  }
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_bAllocatedMeshData = false;
  this->m_nAttributeCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nVertexCount = 0;
  this->m_nIndexCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005704D0
// Name: public: void CMesh::AllocateMesh(int,int,int,class CMeshVertexAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::AllocateMesh(
        CMesh *this,
        int nVertexCount,
        unsigned int nIndexCount,
        int nVertexStride,
        CMeshVertexAttribute *pAttributes,
        int nAtrributeCount)
{
  CMeshVertexAttribute *v7; // ebx
  int v8; // edi
  int i; // eax
  CMeshVertexAttribute *m_pAttributes; // ecx

  if ( this->m_bAllocatedMeshData )
  {
    free(pMem: this->m_pVerts);
    free(pMem: this->m_pAttributes);
    free(pMem: this->m_pIndices);
  }
  v7 = pAttributes;
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_bAllocatedMeshData = false;
  this->m_nAttributeCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nVertexCount = 0;
  this->m_nIndexCount = 0;
  if ( pAttributes != nullptr )
  {
    v8 = nAtrributeCount;
  }
  else
  {
    v7 = &g_PositionAttribute;
    v8 = 1;
  }
  this->m_nVertexCount = nVertexCount;
  this->m_nVertexStrideFloats = nVertexStride;
  this->m_nIndexCount = nIndexCount;
  this->m_nAttributeCount = v8;
  this->m_bAllocatedMeshData = true;
  this->m_pVerts = (float *)MemAlloc_Alloc(
                              nSize: (unsigned __int64)(unsigned int)(nVertexStride * nVertexCount) >> 30 != 0
                            ? -1
                            : 4 * nVertexStride * nVertexCount);
  this->m_pIndices = (unsigned int *)MemAlloc_Alloc(nSize: (unsigned __int64)nIndexCount >> 30 != 0 ? -1 : 4 * nIndexCount);
  this->m_pAttributes = (CMeshVertexAttribute *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v8 >> 29 != 0 ? -1 : 8 * v8);
  for ( i = 0; i < v8; ++i )
  {
    m_pAttributes = this->m_pAttributes;
    m_pAttributes[i].m_nOffsetFloats = v7[i].m_nOffsetFloats;
    m_pAttributes[i].m_nType = v7[i].m_nType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005705C0
// Name: public: void CMesh::AllocateAndCopyMesh(int,float const __near *,int,unsigned int const __near *,int,class CMeshVertexAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::AllocateAndCopyMesh(
        CMesh *this,
        int nInputVertexCount,
        const float *pInputVerts,
        unsigned int nInputIndexCount,
        const unsigned int *pInputIndices,
        int nVertexStride,
        CMeshVertexAttribute *pAttributes,
        int nAtrributeCount)
{
  CMesh::AllocateMesh(
    this,
    nVertexCount: nInputVertexCount,
    nIndexCount: nInputIndexCount,
    nVertexStride,
    pAttributes,
    nAtrributeCount);
  _V_memcpy(dest: this->m_pVerts, src: pInputVerts, count: 4 * this->m_nVertexCount * this->m_nVertexStrideFloats);
  _V_memcpy(dest: this->m_pIndices, src: pInputIndices, count: 4 * this->m_nIndexCount);
}

//------------------------------------------------------------------------------
// Address: 0x00570620
// Name: public: void CMesh::AppendMesh(class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::AppendMesh(CMesh *this, const CMesh *inputMesh)
{
  int v4; // ebx
  int v5; // eax
  unsigned int *v6; // ecx
  unsigned int v7; // edx
  int nTotalVertices; // [esp+Ch] [ebp-Ch]
  int nCurrentIndex; // [esp+10h] [ebp-8h]
  unsigned int *pNewIB; // [esp+14h] [ebp-4h]
  float *pNewVB; // [esp+20h] [ebp+8h]

  v4 = inputMesh->m_nIndexCount + this->m_nIndexCount;
  nTotalVertices = this->m_nVertexCount + inputMesh->m_nVertexCount;
  pNewVB = (float *)MemAlloc_Alloc(
                      nSize: (unsigned __int64)(unsigned int)(nTotalVertices * this->m_nVertexStrideFloats) >> 30 != 0
                    ? -1
                    : 4 * nTotalVertices * this->m_nVertexStrideFloats);
  pNewIB = (unsigned int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v4 >> 30 != 0 ? -1 : 4 * v4);
  _V_memcpy(dest: pNewVB, src: this->m_pVerts, count: 4 * this->m_nVertexCount * this->m_nVertexStrideFloats);
  _V_memcpy(dest: pNewIB, src: this->m_pIndices, count: 4 * this->m_nIndexCount);
  nCurrentIndex = this->m_nIndexCount;
  _V_memcpy(
    dest: &pNewVB[this->m_nVertexStrideFloats * this->m_nVertexCount],
    src: inputMesh->m_pVerts,
    count: 4 * this->m_nVertexStrideFloats * inputMesh->m_nVertexCount);
  v5 = 0;
  if ( inputMesh->m_nIndexCount > 0 )
  {
    v6 = &pNewIB[nCurrentIndex];
    do
    {
      v7 = this->m_nVertexCount + inputMesh->m_pIndices[v5++];
      *v6++ = v7;
    }
    while ( v5 < inputMesh->m_nIndexCount );
  }
  free(pMem: this->m_pVerts);
  free(pMem: this->m_pIndices);
  this->m_nIndexCount = v4;
  this->m_pVerts = pNewVB;
  this->m_pIndices = pNewIB;
  this->m_nVertexCount = nTotalVertices;
}

//------------------------------------------------------------------------------
// Address: 0x00570730
// Name: public: int CMesh::FindFirstAttributeOffset(enum VertexElement_t)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMesh::FindFirstAttributeOffset(CMesh *this, VertexElement_t nType)
{
  int m_nAttributeCount; // edx
  int v3; // eax
  CMeshVertexAttribute *m_pAttributes; // esi
  VertexElement_t *i; // ecx

  m_nAttributeCount = this->m_nAttributeCount;
  v3 = 0;
  if ( m_nAttributeCount <= 0 )
    return -1;
  m_pAttributes = this->m_pAttributes;
  for ( i = &m_pAttributes->m_nType; *i != nType; i += 2 )
  {
    if ( ++v3 >= m_nAttributeCount )
      return -1;
  }
  return m_pAttributes[v3].m_nOffsetFloats;
}

//------------------------------------------------------------------------------
// Address: 0x00570770
// Name: private: void CMesh::RestrideVertexBuffer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::RestrideVertexBuffer(CMesh *this, int nNewStrideFloats)
{
  float *v3; // eax
  int m_nVertexStrideFloats; // ecx
  int v5; // edi
  float *i; // ebx
  float *pNewMemory; // [esp+Ch] [ebp-8h]
  int nMinStride; // [esp+10h] [ebp-4h]

  v3 = (float *)MemAlloc_Alloc(
                  nSize: (unsigned __int64)(unsigned int)(nNewStrideFloats * this->m_nVertexCount) >> 30 != 0
                ? -1
                : 4 * nNewStrideFloats * this->m_nVertexCount);
  m_nVertexStrideFloats = this->m_nVertexStrideFloats;
  pNewMemory = v3;
  if ( nNewStrideFloats < m_nVertexStrideFloats )
    m_nVertexStrideFloats = nNewStrideFloats;
  v5 = 0;
  nMinStride = 4 * m_nVertexStrideFloats;
  for ( i = v3; v5 < this->m_nVertexCount; i += nNewStrideFloats )
  {
    _V_memcpy(dest: i, src: &this->m_pVerts[v5 * this->m_nVertexStrideFloats], count: nMinStride);
    ++v5;
  }
  free(pMem: this->m_pVerts);
  this->m_pVerts = pNewMemory;
  this->m_nVertexStrideFloats = nNewStrideFloats;
  this->m_bAllocatedMeshData = true;
}

//------------------------------------------------------------------------------
// Address: 0x00570810
// Name: public: void CMesh::AddAttributes(class CMeshVertexAttribute __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::AddAttributes(CMesh *this, CMeshVertexAttribute *pAttributes, int nAttributeCount)
{
  CMeshVertexAttribute *v4; // edx
  int v5; // eax
  CMeshVertexAttribute *m_pAttributes; // ecx
  int m_nVertexStrideFloats; // esi
  int i; // ebx
  VertexElement_t m_nType; // edi
  int v10; // eax
  int m_nOffsetFloats; // ecx
  int v12; // eax
  int v13; // eax
  VertexElement_t v14; // ecx
  CMeshVertexAttribute *pNewAttributes; // [esp+Ch] [ebp-8h]

  v4 = (CMeshVertexAttribute *)MemAlloc_Alloc(
                                 nSize: (unsigned __int64)(unsigned int)(nAttributeCount + this->m_nAttributeCount) >> 29 != 0
                               ? -1
                               : 8 * (nAttributeCount + this->m_nAttributeCount));
  v5 = 0;
  for ( pNewAttributes = v4; v5 < this->m_nAttributeCount; ++v5 )
  {
    m_pAttributes = this->m_pAttributes;
    v4[v5].m_nOffsetFloats = m_pAttributes[v5].m_nOffsetFloats;
    v4[v5].m_nType = m_pAttributes[v5].m_nType;
  }
  m_nVertexStrideFloats = this->m_nVertexStrideFloats;
  for ( i = 0; i < nAttributeCount; v4[v13].m_nType = v14 )
  {
    m_nType = pAttributes[i].m_nType;
    switch ( m_nType )
    {
      case VERTEX_ELEMENT_POSITION:
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_TANGENT_S:
      case VERTEX_ELEMENT_TANGENT_T:
      case VERTEX_ELEMENT_BONEWEIGHTS3:
      case VERTEX_ELEMENT_USERDATA3:
      case VERTEX_ELEMENT_TEXCOORD3D_0:
      case VERTEX_ELEMENT_TEXCOORD3D_1:
      case VERTEX_ELEMENT_TEXCOORD3D_2:
      case VERTEX_ELEMENT_TEXCOORD3D_3:
      case VERTEX_ELEMENT_TEXCOORD3D_4:
      case VERTEX_ELEMENT_TEXCOORD3D_5:
      case VERTEX_ELEMENT_TEXCOORD3D_6:
      case VERTEX_ELEMENT_TEXCOORD3D_7:
        v10 = 12;
        break;
      case VERTEX_ELEMENT_POSITION4D:
      case VERTEX_ELEMENT_NORMAL4D:
      case VERTEX_ELEMENT_BONEWEIGHTS4:
      case VERTEX_ELEMENT_USERDATA4:
      case VERTEX_ELEMENT_TEXCOORD4D_0:
      case VERTEX_ELEMENT_TEXCOORD4D_1:
      case VERTEX_ELEMENT_TEXCOORD4D_2:
      case VERTEX_ELEMENT_TEXCOORD4D_3:
      case VERTEX_ELEMENT_TEXCOORD4D_4:
      case VERTEX_ELEMENT_TEXCOORD4D_5:
      case VERTEX_ELEMENT_TEXCOORD4D_6:
      case VERTEX_ELEMENT_TEXCOORD4D_7:
        v10 = 16;
        break;
      case VERTEX_ELEMENT_COLOR:
      case VERTEX_ELEMENT_SPECULAR:
      case VERTEX_ELEMENT_WRINKLE:
      case VERTEX_ELEMENT_BONEINDEX:
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_USERDATA1:
      case VERTEX_ELEMENT_TEXCOORD1D_0:
      case VERTEX_ELEMENT_TEXCOORD1D_1:
      case VERTEX_ELEMENT_TEXCOORD1D_2:
      case VERTEX_ELEMENT_TEXCOORD1D_3:
      case VERTEX_ELEMENT_TEXCOORD1D_4:
      case VERTEX_ELEMENT_TEXCOORD1D_5:
      case VERTEX_ELEMENT_TEXCOORD1D_6:
      case VERTEX_ELEMENT_TEXCOORD1D_7:
        v10 = 4;
        break;
      case VERTEX_ELEMENT_BONEWEIGHTS2:
      case VERTEX_ELEMENT_USERDATA2:
      case VERTEX_ELEMENT_TEXCOORD2D_0:
      case VERTEX_ELEMENT_TEXCOORD2D_1:
      case VERTEX_ELEMENT_TEXCOORD2D_2:
      case VERTEX_ELEMENT_TEXCOORD2D_3:
      case VERTEX_ELEMENT_TEXCOORD2D_4:
      case VERTEX_ELEMENT_TEXCOORD2D_5:
      case VERTEX_ELEMENT_TEXCOORD2D_6:
      case VERTEX_ELEMENT_TEXCOORD2D_7:
        v10 = 8;
        break;
      default:
        v10 = 0;
        break;
    }
    m_nOffsetFloats = pAttributes[i].m_nOffsetFloats;
    if ( m_nOffsetFloats + v10 / 4 > m_nVertexStrideFloats )
    {
      switch ( m_nType )
      {
        case VERTEX_ELEMENT_POSITION:
        case VERTEX_ELEMENT_NORMAL:
        case VERTEX_ELEMENT_TANGENT_S:
        case VERTEX_ELEMENT_TANGENT_T:
        case VERTEX_ELEMENT_BONEWEIGHTS3:
        case VERTEX_ELEMENT_USERDATA3:
        case VERTEX_ELEMENT_TEXCOORD3D_0:
        case VERTEX_ELEMENT_TEXCOORD3D_1:
        case VERTEX_ELEMENT_TEXCOORD3D_2:
        case VERTEX_ELEMENT_TEXCOORD3D_3:
        case VERTEX_ELEMENT_TEXCOORD3D_4:
        case VERTEX_ELEMENT_TEXCOORD3D_5:
        case VERTEX_ELEMENT_TEXCOORD3D_6:
        case VERTEX_ELEMENT_TEXCOORD3D_7:
          v12 = 12;
          break;
        case VERTEX_ELEMENT_POSITION4D:
        case VERTEX_ELEMENT_NORMAL4D:
        case VERTEX_ELEMENT_BONEWEIGHTS4:
        case VERTEX_ELEMENT_USERDATA4:
        case VERTEX_ELEMENT_TEXCOORD4D_0:
        case VERTEX_ELEMENT_TEXCOORD4D_1:
        case VERTEX_ELEMENT_TEXCOORD4D_2:
        case VERTEX_ELEMENT_TEXCOORD4D_3:
        case VERTEX_ELEMENT_TEXCOORD4D_4:
        case VERTEX_ELEMENT_TEXCOORD4D_5:
        case VERTEX_ELEMENT_TEXCOORD4D_6:
        case VERTEX_ELEMENT_TEXCOORD4D_7:
          v12 = 16;
          break;
        case VERTEX_ELEMENT_COLOR:
        case VERTEX_ELEMENT_SPECULAR:
        case VERTEX_ELEMENT_WRINKLE:
        case VERTEX_ELEMENT_BONEINDEX:
        case VERTEX_ELEMENT_BONEWEIGHTS1:
        case VERTEX_ELEMENT_USERDATA1:
        case VERTEX_ELEMENT_TEXCOORD1D_0:
        case VERTEX_ELEMENT_TEXCOORD1D_1:
        case VERTEX_ELEMENT_TEXCOORD1D_2:
        case VERTEX_ELEMENT_TEXCOORD1D_3:
        case VERTEX_ELEMENT_TEXCOORD1D_4:
        case VERTEX_ELEMENT_TEXCOORD1D_5:
        case VERTEX_ELEMENT_TEXCOORD1D_6:
        case VERTEX_ELEMENT_TEXCOORD1D_7:
          v12 = 4;
          break;
        case VERTEX_ELEMENT_BONEWEIGHTS2:
        case VERTEX_ELEMENT_USERDATA2:
        case VERTEX_ELEMENT_TEXCOORD2D_0:
        case VERTEX_ELEMENT_TEXCOORD2D_1:
        case VERTEX_ELEMENT_TEXCOORD2D_2:
        case VERTEX_ELEMENT_TEXCOORD2D_3:
        case VERTEX_ELEMENT_TEXCOORD2D_4:
        case VERTEX_ELEMENT_TEXCOORD2D_5:
        case VERTEX_ELEMENT_TEXCOORD2D_6:
        case VERTEX_ELEMENT_TEXCOORD2D_7:
          v12 = 8;
          break;
        default:
          v12 = 0;
          break;
      }
      m_nVertexStrideFloats = m_nOffsetFloats + v12 / 4;
    }
    v13 = i + this->m_nAttributeCount;
    v4[v13].m_nOffsetFloats = pAttributes[i].m_nOffsetFloats;
    v14 = pAttributes[i++].m_nType;
  }
  free(pMem: this->m_pAttributes);
  this->m_nAttributeCount += nAttributeCount;
  this->m_pAttributes = pNewAttributes;
  if ( m_nVertexStrideFloats > this->m_nVertexStrideFloats )
    CMesh::RestrideVertexBuffer(this, nNewStrideFloats: m_nVertexStrideFloats);
}

//------------------------------------------------------------------------------
// Address: 0x00570AE0
// Name: public: bool CMesh::CalculateTangentSpaceWorldLengthsPerFace(class Vector2D __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateTangentSpaceWorldLengthsPerFace(
        CMesh *this,
        Vector2D *pLengthsOut,
        int nLengthsOut,
        float flMaxWorldPerUV)
{
  int m_nAttributeCount; // eax
  int v5; // edx
  CMeshVertexAttribute *m_pAttributes; // edi
  VertexElement_t *p_m_nType; // esi
  int m_nOffsetFloats; // esi
  int v9; // edx
  VertexElement_t *v10; // edi
  int v11; // edi
  int v12; // edx
  VertexElement_t *v13; // edi
  int v14; // eax
  int m_nVertexStrideFloats; // edx
  float *m_pVerts; // ecx
  float *v17; // eax
  float v18; // xmm6_4
  float v19; // xmm0_4
  float *v20; // eax
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float *v24; // eax
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  int v35; // eax
  float v36; // xmm0_4
  float v38; // [esp-Ch] [ebp-94h]
  float v39; // [esp-8h] [ebp-90h]
  float v40; // [esp+1Ch] [ebp-6Ch]
  float v41; // [esp+20h] [ebp-68h]
  float vPos_4; // [esp+28h] [ebp-60h]
  float vPos_8; // [esp+2Ch] [ebp-5Ch]
  int v44; // [esp+48h] [ebp-40h]
  CMesh *v45; // [esp+60h] [ebp-28h]
  float v46; // [esp+64h] [ebp-24h]
  float v47; // [esp+68h] [ebp-20h]
  int sdir; // [esp+70h] [ebp-18h]
  unsigned int *sdir_8; // [esp+78h] [ebp-10h]

  m_nAttributeCount = this->m_nAttributeCount;
  v5 = 0;
  v45 = this;
  if ( m_nAttributeCount <= 0 )
  {
LABEL_5:
    m_nOffsetFloats = -1;
  }
  else
  {
    m_pAttributes = this->m_pAttributes;
    p_m_nType = &m_pAttributes->m_nType;
    while ( *p_m_nType != VERTEX_ELEMENT_POSITION )
    {
      ++v5;
      p_m_nType += 2;
      if ( v5 >= m_nAttributeCount )
        goto LABEL_5;
    }
    m_nOffsetFloats = m_pAttributes[v5].m_nOffsetFloats;
  }
  v9 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_13;
  v10 = &this->m_pAttributes->m_nType;
  while ( *v10 != VERTEX_ELEMENT_TEXCOORD2D_0 )
  {
    ++v9;
    v10 += 2;
    if ( v9 >= m_nAttributeCount )
      goto LABEL_13;
  }
  v11 = this->m_pAttributes[v9].m_nOffsetFloats;
  if ( v11 == -1 )
  {
LABEL_13:
    v12 = 0;
    if ( m_nAttributeCount <= 0 )
    {
LABEL_17:
      v11 = -1;
    }
    else
    {
      v13 = &this->m_pAttributes->m_nType;
      while ( *v13 != VERTEX_ELEMENT_TEXCOORD3D_0 )
      {
        ++v12;
        v13 += 2;
        if ( v12 >= m_nAttributeCount )
          goto LABEL_17;
      }
      v11 = this->m_pAttributes[v12].m_nOffsetFloats;
    }
  }
  if ( m_nOffsetFloats == -1 || v11 == -1 )
  {
    _Msg(a1: "Need valid position and texcoord when creating world space tangent lengths!\n");
    return 0;
  }
  v14 = this->m_nIndexCount / 3;
  v44 = v14;
  if ( nLengthsOut < v14 )
    return 0;
  sdir = 0;
  if ( v14 > 0 )
  {
    sdir_8 = this->m_pIndices + 2;
    while ( 1 )
    {
      m_nVertexStrideFloats = this->m_nVertexStrideFloats;
      m_pVerts = this->m_pVerts;
      v17 = &m_pVerts[m_nVertexStrideFloats * *(sdir_8 - 2)];
      v18 = v17[m_nOffsetFloats];
      v40 = v17[m_nOffsetFloats + 1];
      v41 = v17[m_nOffsetFloats + 2];
      v38 = v17[v11];
      v19 = v17[v11 + 1];
      v20 = &m_pVerts[m_nVertexStrideFloats * *(sdir_8 - 1)];
      vPos_4 = v20[m_nOffsetFloats + 1];
      v39 = v19;
      v21 = v20[m_nOffsetFloats];
      v22 = v20[v11 + 1] - v39;
      vPos_8 = v20[m_nOffsetFloats + 2];
      v23 = v20[v11] - v38;
      v24 = &m_pVerts[m_nVertexStrideFloats * *sdir_8];
      v25 = v24[v11 + 1] - v39;
      v26 = v24[v11] - v38;
      v46 = 0.0;
      v47 = 0.0;
      v27 = v23;
      v28 = (float)(v22 * (float)(v24[m_nOffsetFloats] - v18)) - (float)(v25 * (float)(v21 - v18));
      v29 = (float)(v25 * v23) - (float)(v26 * v22);
      if ( COERCE_FLOAT(LODWORD(v29) & _mask__AbsFloat_) > 1.0e-12 )
        LODWORD(v46) = COERCE_UNSIGNED_INT(v28 / v29) ^ _mask__NegFloat_;
      if ( fabs((float)(v25 * v27) - (float)(v26 * v22)) > 1.0e-12 )
        v47 = -(float)((float)((float)(v22 * (float)(v24[m_nOffsetFloats + 1] - v40))
                             - (float)(v25 * (float)(vPos_4 - v40)))
                     / (float)((float)(v25 * v27) - (float)(v26 * v22)));
      v30 = (float)(v25 * v27) - (float)(v26 * v22);
      if ( fabs(v30) <= 1.0e-12 )
        v31 = 0.0;
      else
        LODWORD(v31) = COERCE_UNSIGNED_INT(
                         (float)((float)(v22 * (float)(v24[m_nOffsetFloats + 2] - v41))
                               - (float)(v25 * (float)(vPos_8 - v41)))
                       / v30)
                     ^ _mask__NegFloat_;
      v32 = flMaxWorldPerUV;
      v33 = (float)((float)(v47 * v47) + (float)(v31 * v31)) + (float)(v46 * v46);
      v34 = fsqrt(v33);
      if ( v34 > flMaxWorldPerUV )
        v34 = flMaxWorldPerUV;
      v35 = sdir;
      pLengthsOut[sdir].x = v34;
      v36 = fsqrt(v33);
      if ( v36 <= flMaxWorldPerUV )
        v32 = v36;
      sdir_8 += 3;
      pLengthsOut[sdir++].y = v32;
      if ( v35 + 1 >= v44 )
        break;
      this = v45;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00570EA0
// Name: public: bool CMesh::CalculateFaceCenters(class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateFaceCenters(CMesh *this, Vector *pCentersOut, int nCentersOut)
{
  int m_nAttributeCount; // esi
  int v4; // eax
  CMeshVertexAttribute *m_pAttributes; // edi
  VertexElement_t *p_m_nType; // edx
  int m_nOffsetFloats; // edi
  int v9; // esi
  float *p_z; // eax
  unsigned int *v11; // edx
  float *m_pVerts; // ebx
  unsigned int v13; // esi
  float *v14; // ebx
  unsigned int v15; // esi
  float *v16; // ebx
  unsigned int v17; // esi
  int nCentersOuta; // [esp+14h] [ebp+Ch]

  m_nAttributeCount = this->m_nAttributeCount;
  v4 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_7;
  m_pAttributes = this->m_pAttributes;
  p_m_nType = &m_pAttributes->m_nType;
  while ( *p_m_nType != VERTEX_ELEMENT_POSITION )
  {
    ++v4;
    p_m_nType += 2;
    if ( v4 >= m_nAttributeCount )
      goto LABEL_7;
  }
  m_nOffsetFloats = m_pAttributes[v4].m_nOffsetFloats;
  if ( m_nOffsetFloats == -1 )
  {
LABEL_7:
    _Msg(a1: "Need valid position to calculate face centers!\n");
    return 0;
  }
  v9 = this->m_nIndexCount / 3;
  if ( nCentersOut < v9 )
    return 0;
  if ( v9 > 0 )
  {
    p_z = &pCentersOut->z;
    v11 = this->m_pIndices + 2;
    nCentersOuta = this->m_nIndexCount / 3;
    do
    {
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      m_pVerts = this->m_pVerts;
      v13 = m_nOffsetFloats + this->m_nVertexStrideFloats * *(v11 - 2);
      *(p_z - 2) = this->m_pVerts[v13] + 0.0;
      *(p_z - 1) = m_pVerts[v13 + 1] + *(p_z - 1);
      *p_z = m_pVerts[v13 + 2] + *p_z;
      v14 = this->m_pVerts;
      v15 = m_nOffsetFloats + this->m_nVertexStrideFloats * *(v11 - 1);
      *(p_z - 2) = this->m_pVerts[v15] + *(p_z - 2);
      *(p_z - 1) = v14[v15 + 1] + *(p_z - 1);
      *p_z = v14[v15 + 2] + *p_z;
      v16 = this->m_pVerts;
      v17 = m_nOffsetFloats + this->m_nVertexStrideFloats * *v11;
      *(p_z - 2) = this->m_pVerts[v17] + *(p_z - 2);
      *(p_z - 1) = v16[v17 + 1] + *(p_z - 1);
      *p_z = v16[v17 + 2] + *p_z;
      *(p_z - 2) = *(p_z - 2) * 0.33333334;
      *(p_z - 1) = *(p_z - 1) * 0.33333334;
      *p_z = *p_z * 0.33333334;
      v11 += 3;
      p_z += 3;
      --nCentersOuta;
    }
    while ( nCentersOuta != 0 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00571020
// Name: void DuplicateMesh(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DuplicateMesh(CMesh *pMeshOut, const CMesh *inputMesh)
{
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: inputMesh->m_nVertexCount,
    nIndexCount: inputMesh->m_nIndexCount,
    nVertexStride: inputMesh->m_nVertexStrideFloats,
    pAttributes: inputMesh->m_pAttributes,
    nAtrributeCount: inputMesh->m_nAttributeCount);
  _V_memcpy(
    dest: pMeshOut->m_pVerts,
    src: inputMesh->m_pVerts,
    count: 4 * inputMesh->m_nVertexCount * inputMesh->m_nVertexStrideFloats);
  _V_memcpy(dest: pMeshOut->m_pIndices, src: inputMesh->m_pIndices, count: 4 * inputMesh->m_nIndexCount);
  CUtlString::operator=(this: &pMeshOut->m_materialName, src: &inputMesh->m_materialName);
}

//------------------------------------------------------------------------------
// Address: 0x00571090
// Name: bool RationalizeUVsInPlace(class CMesh __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RationalizeUVsInPlace(CMesh *pMesh)
{
  int m_nAttributeCount; // edx
  int v3; // eax
  CMeshVertexAttribute *m_pAttributes; // esi
  VertexElement_t *p_m_nType; // ecx
  int m_nOffsetFloats; // ecx
  int v7; // eax
  CMeshVertexAttribute *v8; // esi
  VertexElement_t *i; // ecx
  int m_nIndexCount; // edx
  int v12; // eax
  float *m_pVerts; // edx
  float *v14; // esi
  float v15; // xmm5_4
  __m128 v16; // xmm2
  int m_nVertexStrideFloats; // eax
  float *v18; // edx
  float *v19; // edx
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  bool v28; // zf
  float *v29; // eax
  float *v30; // eax
  float vMin_4; // [esp+Ch] [ebp-8h]
  float *pTriVerts; // [esp+10h] [ebp-4h]
  CMesh *pMesha; // [esp+1Ch] [ebp+8h]

  m_nAttributeCount = pMesh->m_nAttributeCount;
  v3 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_7;
  m_pAttributes = pMesh->m_pAttributes;
  p_m_nType = &m_pAttributes->m_nType;
  while ( *p_m_nType != VERTEX_ELEMENT_TEXCOORD2D_0 )
  {
    ++v3;
    p_m_nType += 2;
    if ( v3 >= m_nAttributeCount )
      goto LABEL_7;
  }
  m_nOffsetFloats = m_pAttributes[v3].m_nOffsetFloats;
  if ( m_nOffsetFloats < 0 )
  {
LABEL_7:
    v7 = 0;
    if ( m_nAttributeCount <= 0 )
      return 0;
    v8 = pMesh->m_pAttributes;
    for ( i = &v8->m_nType; *i != VERTEX_ELEMENT_TEXCOORD3D_0; i += 2 )
    {
      if ( ++v7 >= m_nAttributeCount )
        return 0;
    }
    m_nOffsetFloats = v8[v7].m_nOffsetFloats;
    if ( m_nOffsetFloats < 0 )
      return 0;
  }
  m_nIndexCount = pMesh->m_nIndexCount;
  if ( pMesh->m_nVertexCount != m_nIndexCount )
    return 0;
  v12 = m_nIndexCount / 3;
  m_pVerts = pMesh->m_pVerts;
  if ( v12 > 0 )
  {
    pMesha = (CMesh *)v12;
    do
    {
      v14 = &m_pVerts[m_nOffsetFloats];
      v15 = 3.4028235e38;
      v16 = (__m128)0x7F7FFFFFu;
      vMin_4 = 3.4028235e38;
      pTriVerts = m_pVerts;
      if ( *v14 <= 3.4028235e38 )
        v16 = (__m128)LODWORD(m_pVerts[m_nOffsetFloats]);
      if ( m_pVerts[m_nOffsetFloats + 1] <= 3.4028235e38 )
      {
        v15 = m_pVerts[m_nOffsetFloats + 1];
        vMin_4 = v15;
      }
      m_nVertexStrideFloats = pMesh->m_nVertexStrideFloats;
      v18 = &m_pVerts[m_nVertexStrideFloats];
      if ( v18[m_nOffsetFloats] <= v16.m128_f32[0] )
        v16 = (__m128)LODWORD(v18[m_nOffsetFloats]);
      if ( v18[m_nOffsetFloats + 1] <= v15 )
      {
        v15 = v18[m_nOffsetFloats + 1];
        vMin_4 = v15;
      }
      v19 = &v18[m_nVertexStrideFloats];
      if ( v19[m_nOffsetFloats] <= v16.m128_f32[0] )
        v16 = (__m128)LODWORD(v19[m_nOffsetFloats]);
      if ( v19[m_nOffsetFloats + 1] <= v15 )
        vMin_4 = v19[m_nOffsetFloats + 1];
      v20 = _mm_and_ps((__m128)0x80000000, v16);
      v21.m128_i32[0] = v20.m128_i32[0];
      v22.m128_i32[0] = 1258291200;
      v22.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v20), v22).m128_f32[0]) & 0x4B000000
                      | v20.m128_i32[0];
      v23 = v16;
      v23.m128_f32[0] = (float)(v16.m128_f32[0] + v22.m128_f32[0]) - v22.m128_f32[0];
      v24 = v23;
      v24.m128_f32[0] = v23.m128_f32[0] - v16.m128_f32[0];
      v21.m128_f32[0] = v23.m128_f32[0]
                      - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v24, v21).m128_f32[0]) & 0x3F800000);
      v25 = _mm_and_ps((__m128)0x80000000, (__m128)LODWORD(vMin_4));
      v24.m128_i32[0] = 1258291200;
      v24.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps((__m128)LODWORD(vMin_4), v25), v24).m128_f32[0])
                      & 0x4B000000
                      | v25.m128_i32[0];
      v26 = (__m128)LODWORD(vMin_4);
      v26.m128_f32[0] = (float)(vMin_4 + v24.m128_f32[0]) - v24.m128_f32[0];
      v27 = v26;
      v27.m128_f32[0] = v26.m128_f32[0] - vMin_4;
      v26.m128_f32[0] = v26.m128_f32[0]
                      - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v27, v25).m128_f32[0]) & 0x3F800000);
      *v14 = *v14 - v21.m128_f32[0];
      v14[1] = v14[1] - v26.m128_f32[0];
      m_pVerts = &v19[m_nVertexStrideFloats];
      v28 = pMesha == (CMesh *)1;
      pMesha = (CMesh *)((char *)pMesha - 1);
      v29 = &pTriVerts[pMesh->m_nVertexStrideFloats];
      v29[m_nOffsetFloats] = v29[m_nOffsetFloats] - v21.m128_f32[0];
      v29[m_nOffsetFloats + 1] = v29[m_nOffsetFloats + 1] - v26.m128_f32[0];
      v30 = &v29[pMesh->m_nVertexStrideFloats];
      v30[m_nOffsetFloats] = v30[m_nOffsetFloats] - v21.m128_f32[0];
      v30[m_nOffsetFloats + 1] = v30[m_nOffsetFloats + 1] - v26.m128_f32[0];
    }
    while ( !v28 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005712C0
// Name: bool ConcatMeshes(class CMesh __near *,class CMesh __near * __near *,int,class CMeshVertexAttribute __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConcatMeshes(
        CMesh *pMeshOut,
        CMesh **ppMeshIn,
        int nInputMeshes,
        CMeshVertexAttribute *pAttributeOverride,
        int nAttributeOverrideCount,
        int nStrideOverride)
{
  int v6; // ecx
  int v7; // edi
  unsigned int v8; // edx
  int v9; // esi
  CMeshVertexAttribute *m_pAttributes; // ebx
  CMesh *v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  CMesh *v15; // esi
  int v16; // edi
  int v17; // eax
  int m; // [esp+Ch] [ebp-Ch]
  int nCurrentIndex; // [esp+10h] [ebp-8h]
  int nCurrentIndexa; // [esp+10h] [ebp-8h]
  int nStrideFloats; // [esp+14h] [ebp-4h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  m_pAttributes = nullptr;
  nCurrentIndex = 0;
  nStrideFloats = 0;
  if ( nInputMeshes > 0 )
  {
    while ( 1 )
    {
      v11 = ppMeshIn[v6];
      v8 += v11->m_nIndexCount;
      v9 += v11->m_nVertexCount;
      if ( v6 != 0 )
      {
        if ( nStrideOverride == 0 && nStrideFloats != v11->m_nVertexStrideFloats )
        {
          _Warning(a1: "Trying to concatenate differently strided meshes!\n");
          return 0;
        }
      }
      else
      {
        m_pAttributes = v11->m_pAttributes;
        nCurrentIndex = v11->m_nAttributeCount;
        nStrideFloats = v11->m_nVertexStrideFloats;
      }
      if ( ++v6 >= nInputMeshes )
      {
        v7 = nCurrentIndex;
        break;
      }
    }
  }
  if ( pAttributeOverride != nullptr && nAttributeOverrideCount > 0 )
  {
    m_pAttributes = pAttributeOverride;
    v7 = nAttributeOverrideCount;
  }
  if ( nStrideOverride > 0 )
    nStrideFloats = nStrideOverride;
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: v9,
    nIndexCount: v8,
    nVertexStride: nStrideFloats,
    pAttributes: m_pAttributes,
    nAtrributeCount: v7);
  v12 = 0;
  v13 = 0;
  v14 = 0;
  nCurrentIndexa = 0;
  for ( m = 0; v12 < nInputMeshes; m = v12 )
  {
    v15 = ppMeshIn[v12];
    v16 = 0;
    if ( v15->m_nVertexCount > 0 )
    {
      do
      {
        CopyVertex(
          pOut: &pMeshOut->m_pVerts[pMeshOut->m_nVertexStrideFloats * (v16 + v14)],
          pIn: &v15->m_pVerts[v16 * v15->m_nVertexStrideFloats],
          nFloats: nStrideFloats);
        ++v16;
      }
      while ( v16 < v15->m_nVertexCount );
      v13 = nCurrentIndexa;
    }
    v17 = 0;
    if ( v15->m_nIndexCount > 0 )
    {
      do
        pMeshOut->m_pIndices[v13++] = v14 + v15->m_pIndices[v17++];
      while ( v17 < v15->m_nIndexCount );
      nCurrentIndexa = v13;
    }
    v14 += v15->m_nVertexCount;
    v12 = m + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00571400
// Name: public: int CUtlScalarHash<struct EdgeHash_t,class CDefaultHash32>::Insert(unsigned int,struct EdgeHash_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Insert(
        CUtlScalarHash<EdgeHash_t,CDefaultHash32> *this,
        unsigned int uiKey,
        const EdgeHash_t *data)
{
  unsigned int m_uiBucketMask; // edi
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ecx
  unsigned int result; // eax

  if ( this->m_dataCount >= this->m_maxData )
    CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Grow(this);
  m_uiBucketMask = this->m_uiBucketMask;
  ++this->m_dataCount;
  m_pData = this->m_pData;
  for ( result = m_uiBucketMask
               & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
        m_pData[result].m_uiKey != -1;
        result = m_uiBucketMask & (result + 1) )
  {
    ;
  }
  this->m_pData[result].m_uiKey = uiKey;
  this->m_pData[result].m_Data = *data;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005714B0
// Name: public: int CUtlScalarHash<struct EdgeHash_t,class CDefaultHash32>::Find(unsigned int,struct EdgeHash_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Find(
        CUtlScalarHash<EdgeHash_t,CDefaultHash32> *this,
        unsigned int uiKey,
        const EdgeHash_t *dataRecord)
{
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ebx
  unsigned int result; // eax
  unsigned int m_uiBucketMask; // edi
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *v6; // ecx
  unsigned int m_uiKey; // edx

  m_pData = this->m_pData;
  if ( m_pData == nullptr )
    return -1;
  m_uiBucketMask = this->m_uiBucketMask;
  result = this->m_uiBucketMask
         & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  v6 = &m_pData[result];
  m_uiKey = v6->m_uiKey;
  if ( v6->m_uiKey == -1 )
    return -1;
  while ( m_uiKey != uiKey || dataRecord->m_nV0 != v6->m_Data.m_nV0 || dataRecord->m_nV1 != v6->m_Data.m_nV1 )
  {
    result = m_uiBucketMask & (result + 1);
    m_uiKey = m_pData[result].m_uiKey;
    v6 = &m_pData[result];
    if ( m_uiKey == -1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00571560
// Name: public: void CUtlScalarHash<struct EdgeHash_t,class CDefaultHash32>::Grow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Grow(CUtlScalarHash<EdgeHash_t,CDefaultHash32> *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  unsigned int *p_m_uiKey; // ecx
  unsigned int v7; // edi
  unsigned int m_uiBucketMask; // edx
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ecx
  int i; // eax
  int v11; // eax
  EdgeHash_t *p_m_Data; // eax
  bool v13; // zf
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *pOldData; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *v16; // [esp+14h] [ebp-4h]

  v2 = 2 * this->m_maxData;
  pOldData = this->m_pData;
  v3 = v2;
  if ( v2 <= 16 )
    v3 = 16;
  v4 = 2 * v3;
  this->m_maxData = v3;
  this->m_pData = (CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *)MemAlloc_Alloc(
                                                                                   nSize: (20
                                                                                  * (unsigned __int64)(unsigned int)(2 * v3)) >> 32 != 0
                                                                                 ? -1
                                                                                 : 40 * v3);
  this->m_uiBucketMask = v4 - 1;
  this->m_dataCount = 0;
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      this->m_pData[v5++].m_uiKey = -1;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v2 > 0 )
  {
    p_m_uiKey = &pOldData->m_uiKey;
    v16 = pOldData;
    v15 = v2;
    do
    {
      v7 = *p_m_uiKey;
      if ( *p_m_uiKey != -1 )
      {
        if ( this->m_dataCount >= this->m_maxData )
          CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Grow(this);
        m_uiBucketMask = this->m_uiBucketMask;
        ++this->m_dataCount;
        m_pData = this->m_pData;
        for ( i = m_uiBucketMask & (HIBYTE(v7) + 33 * (BYTE2(v7) + 33 * (33 * (unsigned __int8)v7 + BYTE1(v7) - 22)));
              m_pData[i].m_uiKey != -1;
              i = m_uiBucketMask & (i + 1) )
        {
          ;
        }
        v11 = i;
        this->m_pData[v11].m_uiKey = v7;
        p_m_uiKey = &v16->m_uiKey;
        p_m_Data = &this->m_pData[v11].m_Data;
        *(_QWORD *)&p_m_Data->m_nV0 = *(_QWORD *)&v16->m_Data.m_nV0;
        *(_QWORD *)&p_m_Data->m_nTri0 = *(_QWORD *)&v16->m_Data.m_nTri0;
      }
      p_m_uiKey += 5;
      v13 = v15-- == 1;
      v16 = (CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *)p_m_uiKey;
    }
    while ( !v13 );
  }
  free(pMem: pOldData);
}

//------------------------------------------------------------------------------
// Address: 0x005716B0
// Name: public: bool CMesh::CalculateBounds(class Vector __near *,class Vector __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateBounds(
        CMesh *this,
        Vector *pMinOut,
        Vector *pMaxOut,
        int nStartVertex,
        int nVertexCount)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  int m_nAttributeCount; // esi
  int v8; // eax
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  CMeshVertexAttribute *m_pAttributes; // edi
  VertexElement_t *i; // edx
  int m_nOffsetFloats; // eax
  float *v16; // eax
  int m_nVertexCount; // edx
  bool v18; // cc
  int v19; // ecx
  float v20; // xmm3_4
  float v21; // xmm2_4
  float vMin; // [esp+0h] [ebp-Ch]

  v5 = 3.4028235e38;
  v6 = -3.4028235e38;
  m_nAttributeCount = this->m_nAttributeCount;
  v8 = 0;
  vMin = 3.4028235e38;
  v9 = 3.4028235e38;
  v10 = -3.4028235e38;
  v11 = -3.4028235e38;
  if ( m_nAttributeCount <= 0 )
    return 0;
  m_pAttributes = this->m_pAttributes;
  for ( i = &m_pAttributes->m_nType; *i != VERTEX_ELEMENT_POSITION; i += 2 )
  {
    if ( ++v8 >= m_nAttributeCount )
      return 0;
  }
  m_nOffsetFloats = m_pAttributes[v8].m_nOffsetFloats;
  if ( m_nOffsetFloats < 0 )
    return 0;
  v16 = &this->m_pVerts[m_nOffsetFloats + nStartVertex * this->m_nVertexStrideFloats];
  m_nVertexCount = nVertexCount;
  v18 = nVertexCount <= 0;
  if ( nVertexCount == 0 )
  {
    m_nVertexCount = this->m_nVertexCount;
    v18 = m_nVertexCount <= 0;
  }
  if ( !v18 )
  {
    v19 = 4 * this->m_nVertexStrideFloats;
    do
    {
      if ( vMin > *v16 )
        vMin = *v16;
      v20 = v16[1];
      if ( v9 > v20 )
        v9 = v16[1];
      v21 = v16[2];
      if ( v5 > v21 )
        v5 = v16[2];
      if ( *v16 > v10 )
        v10 = *v16;
      if ( v20 > v11 )
        v11 = v16[1];
      if ( v21 > v6 )
        v6 = v16[2];
      v16 = (float *)((char *)v16 + v19);
      --m_nVertexCount;
    }
    while ( m_nVertexCount != 0 );
  }
  pMinOut->x = vMin;
  pMinOut->y = v9;
  pMinOut->z = v5;
  pMaxOut->x = v10;
  pMaxOut->y = v11;
  pMaxOut->z = v6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005717B0
// Name: public: bool CUtlScalarHash<struct EdgeHash_t,class CDefaultHash32>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Init(
        CUtlScalarHash<EdgeHash_t,CDefaultHash32> *this,
        int nBucketCount)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx

  v3 = (((((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
            | ((unsigned int)(nBucketCount - 1) >> 1)
            | (nBucketCount - 1)) >> 4)
          | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 8)
        | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 16)
      | ((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 8)
      | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 4)
      | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
      | ((unsigned int)(nBucketCount - 1) >> 1)
      | (nBucketCount - 1))
     + 1;
  v4 = 2 * v3;
  this->m_maxData = v3;
  this->m_pData = (CUtlScalarHash<EdgeHash_t,CDefaultHash32>::HashScalarData_t *)MemAlloc_Alloc(
                                                                                   nSize: (20
                                                                                  * (unsigned __int64)(unsigned int)(2 * v3)) >> 32 != 0
                                                                                 ? -1
                                                                                 : 40 * v3);
  v5 = 2 * this->m_maxData;
  this->m_uiBucketMask = v4 - 1;
  if ( v5 > 0 )
  {
    v6 = 0;
    do
    {
      this->m_pData[v6++].m_uiKey = -1;
      --v5;
    }
    while ( v5 != 0 );
  }
  this->m_dataCount = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00571830
// Name: public: bool CMesh::CalculateAdjacency(int __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMesh::CalculateAdjacency(CMesh *this, int *pAdjacencyOut, int nSizeAdjacencyOut)
{
  int m_nIndexCount; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  unsigned int *m_pIndices; // esi
  int v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  unsigned int v16; // esi
  unsigned int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // edi
  unsigned int *v21; // esi
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // eax
  EdgeHash_t *p_m_Data; // eax
  int m_nTri0; // ecx
  int v29; // edx
  EdgeHash_t tmp; // [esp+4h] [ebp-30h] BYREF
  CUtlScalarHash<EdgeHash_t,CDefaultHash32> edgeHash; // [esp+14h] [ebp-20h] BYREF
  int nFaces; // [esp+24h] [ebp-10h]
  CMesh *v33; // [esp+28h] [ebp-Ch]
  int f; // [esp+2Ch] [ebp-8h]
  int v35; // [esp+30h] [ebp-4h]
  int nIndex; // [esp+40h] [ebp+Ch]
  int nIndexa; // [esp+40h] [ebp+Ch]

  m_nIndexCount = this->m_nIndexCount;
  v33 = this;
  if ( nSizeAdjacencyOut != m_nIndexCount )
    return 0;
  v6 = 0;
  memset(&edgeHash, 0, sizeof(edgeHash));
  CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Init(this: &edgeHash, nBucketCount: 2 * m_nIndexCount);
  v7 = this->m_nIndexCount / 3;
  v8 = 0;
  nFaces = v7;
  nIndex = 0;
  f = 0;
  if ( v7 > 0 )
  {
    tmp.m_nTri1 = -1;
    do
    {
      tmp.m_nTri0 = v8;
      v9 = 0;
      v35 = 4 * v6;
      do
      {
        m_pIndices = v33->m_pIndices;
        v11 = v9 + 1;
        v12 = *(unsigned int *)((char *)m_pIndices + v35);
        v13 = nIndex + (v9 + 1) % 3;
        v14 = m_pIndices[v13];
        if ( v14 < v12 )
        {
          v14 = *(unsigned int *)((char *)m_pIndices + v35);
          v12 = m_pIndices[v13];
        }
        tmp.m_nV0 = v12;
        v15 = __ROL4__(v12, 16);
        v16 = (v14 ^ v15) != -1 ? v14 ^ v15 : 0;
        tmp.m_nV1 = v14;
        v17 = CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Find(this: &edgeHash, uiKey: v16, dataRecord: &tmp);
        if ( v17 == -1 )
          CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Insert(this: &edgeHash, uiKey: v16, data: &tmp);
        else
          edgeHash.m_pData[v17].m_Data.m_nTri1 = f;
        v35 += 4;
        v9 = v11;
      }
      while ( v11 < 3 );
      v7 = nFaces;
      v8 = f + 1;
      v6 = nIndex + 3;
      nIndex += 3;
      f = v8;
    }
    while ( v8 < nFaces );
  }
  v18 = 0;
  nIndexa = 0;
  f = 0;
  if ( v7 > 0 )
  {
    tmp.m_nTri0 = -1;
    tmp.m_nTri1 = -1;
    do
    {
      v19 = 0;
      v20 = v18;
      do
      {
        v35 = v19 + 1;
        v21 = v33->m_pIndices;
        v22 = v21[v20];
        v23 = nIndexa + (v19 + 1) % 3;
        v24 = v21[v23];
        if ( v24 < v22 )
        {
          v24 = v21[v20];
          v22 = v21[v23];
        }
        tmp.m_nV0 = v22;
        v25 = __ROL4__(v22, 16);
        tmp.m_nV1 = v24;
        v26 = CUtlScalarHash<EdgeHash_t,CDefaultHash32>::Find(
                this: &edgeHash,
                uiKey: (v24 ^ v25) != -1 ? v24 ^ v25 : 0,
                dataRecord: &tmp);
        p_m_Data = &edgeHash.m_pData[v26].m_Data;
        m_nTri0 = p_m_Data->m_nTri0;
        v29 = f;
        if ( m_nTri0 == f )
          pAdjacencyOut[v20] = p_m_Data->m_nTri1;
        else
          pAdjacencyOut[v20] = m_nTri0;
        v19 = v35;
        ++v20;
      }
      while ( v35 < 3 );
      v18 = nIndexa + 3;
      nIndexa += 3;
      f = v29 + 1;
    }
    while ( v29 + 1 < nFaces );
  }
  free(pMem: edgeHash.m_pData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00571A10
// Name: private: int CVertexKDTree::FindMidpointIndex(int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVertexKDTree::FindMidpointIndex(CVertexKDTree *this, int nStart, int nCount, int nAxis, float flSplit)
{
  const float **v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ebx
  unsigned int v10; // edi
  const float **v11; // ecx
  const float *v12; // ebx
  const float *v13; // edx
  const float *v14; // edx
  const float *v15; // ebx
  const float *v16; // edx
  const float *v17; // edx
  const float *v18; // ebx
  const float *v19; // ecx
  const float *v20; // edx
  int v21; // edi
  const float **v22; // edx
  const float **v23; // ecx
  const float *v24; // ebx
  const float *v25; // edi
  const float *v26; // ebx
  const float *v27; // edi
  const float *v28; // edi
  const float *v29; // ebx
  const float *v30; // edi
  const float **v31; // ecx
  const float *v32; // ebx
  const float *v33; // edx
  int nCounta; // [esp+Ch] [ebp+Ch]
  int i; // [esp+14h] [ebp+14h]
  int ia; // [esp+14h] [ebp+14h]

  v6 = &this->m_vertexList.m_Memory.m_pMemory[nStart];
  v7 = nCount;
  v8 = nCount / 2;
  v9 = nCount / 2;
  if ( nCount / 2 < nCount )
  {
    if ( nCount - v8 >= 4 )
    {
      v10 = ((unsigned int)(nCount - v8 - 4) >> 2) + 1;
      v11 = &v6[v8 + 2];
      i = v8 + 4 * v10;
      do
      {
        v12 = *(v11 - 2);
        if ( flSplit > v12[nAxis] )
        {
          v13 = v6[v8];
          v6[v8] = v12;
          *(v11 - 2) = v13;
          ++v8;
        }
        v14 = *(v11 - 1);
        if ( flSplit > v14[nAxis] )
        {
          v15 = v6[v8];
          v6[v8] = v14;
          *(v11 - 1) = v15;
          ++v8;
        }
        if ( flSplit > (*v11)[nAxis] )
        {
          v16 = v6[v8];
          v6[v8] = *v11;
          *v11 = v16;
          ++v8;
        }
        v17 = v11[1];
        if ( flSplit > v17[nAxis] )
        {
          v18 = v6[v8];
          v6[v8] = v17;
          v11[1] = v18;
          ++v8;
        }
        v11 += 4;
        --v10;
      }
      while ( v10 != 0 );
      v9 = i;
      v7 = nCount;
    }
    for ( ; v9 < v7; ++v9 )
    {
      v19 = v6[v9];
      if ( flSplit > v19[nAxis] )
      {
        v20 = v6[v8];
        v6[v8] = v19;
        v6[v9] = v20;
        ++v8;
      }
    }
  }
  v21 = v8 - 1;
  if ( v8 - 1 >= 0 )
  {
    if ( v8 >= 4 )
    {
      nCounta = (unsigned int)v8 >> 2;
      v22 = &v6[v21 - 2];
      v23 = &v6[v8 - 1];
      ia = v21 - 4 * ((unsigned int)v8 >> 2);
      do
      {
        v24 = v22[2];
        if ( v24[nAxis] >= flSplit )
        {
          v25 = *v23;
          *v23 = v24;
          --v8;
          v22[2] = v25;
          --v23;
        }
        v26 = v22[1];
        if ( v26[nAxis] >= flSplit )
        {
          v27 = *v23;
          *v23 = v26;
          --v8;
          v22[1] = v27;
          --v23;
        }
        if ( (*v22)[nAxis] >= flSplit )
        {
          v28 = *v23;
          *v23 = *v22;
          --v8;
          *v22 = v28;
          --v23;
        }
        v29 = *(v22 - 1);
        if ( v29[nAxis] >= flSplit )
        {
          v30 = *v23;
          *v23 = v29;
          --v8;
          *(v22 - 1) = v30;
          --v23;
        }
        v22 -= 4;
        --nCounta;
      }
      while ( nCounta != 0 );
      v21 = ia;
    }
    if ( v21 >= 0 )
    {
      v31 = &v6[v8 - 1];
      do
      {
        v32 = v6[v21];
        if ( v32[nAxis] >= flSplit )
        {
          v33 = *v31;
          *v31 = v32;
          --v8;
          v6[v21] = v33;
          --v31;
        }
        --v21;
      }
      while ( v21 >= 0 );
    }
  }
  return nStart + v8;
}

//------------------------------------------------------------------------------
// Address: 0x00571BC0
// Name: private: void CVertexKDTree::ComputeBounds(class Vector __near *,class Vector __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexKDTree::ComputeBounds(CVertexKDTree *this, Vector *pMins, Vector *pMaxs, int nStart, int nCount)
{
  float **v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float **v12; // eax
  int v13; // edx
  float *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4

  v5 = (float **)&this->m_vertexList.m_Memory.m_pMemory[nStart];
  v6 = (*v5)[2];
  v7 = (*v5)[1];
  v8 = **v5;
  v9 = v7;
  v10 = v8;
  v11 = v6;
  if ( nCount > 1 )
  {
    v12 = v5 + 1;
    v13 = nCount - 1;
    do
    {
      v14 = *v12;
      v15 = **v12;
      if ( v15 <= v8 )
        v8 = **v12;
      if ( v10 <= v15 )
        v10 = **v12;
      v16 = v14[1];
      if ( v16 <= v7 )
        v7 = v14[1];
      if ( v9 <= v16 )
        v9 = v14[1];
      v17 = v14[2];
      if ( v17 <= v6 )
        v6 = v14[2];
      if ( v11 <= v17 )
        v11 = v14[2];
      ++v12;
      --v13;
    }
    while ( v13 != 0 );
  }
  if ( pMins != nullptr )
  {
    pMins->x = v8;
    pMins->y = v7;
    pMins->z = v6;
  }
  if ( pMaxs != nullptr )
  {
    pMaxs->x = v10;
    pMaxs->y = v9;
    pMaxs->z = v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571C90
// Name: public: CMesh::~CMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::~CMesh(CMesh *this)
{
  if ( this->m_bAllocatedMeshData )
  {
    free(pMem: this->m_pVerts);
    free(pMem: this->m_pAttributes);
    free(pMem: this->m_pIndices);
  }
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_bAllocatedMeshData = false;
  this->m_nAttributeCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nVertexCount = 0;
  this->m_nIndexCount = 0;
  this->m_materialName.m_Storage.m_nActualLength = 0;
  if ( this->m_materialName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_materialName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_materialName.m_Storage.m_Memory.m_pMemory);
      this->m_materialName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_materialName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00571D00
// Name: public: CMesh::CMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMesh *__thiscall CMesh::CMesh(CMesh *this)
{
  this->m_pVerts = nullptr;
  this->m_pAttributes = nullptr;
  this->m_pIndices = nullptr;
  this->m_nVertexCount = 0;
  this->m_nVertexStrideFloats = 0;
  this->m_nAttributeCount = 0;
  this->m_nIndexCount = 0;
  CUtlString::CUtlString(this: &this->m_materialName);
  this->m_bAllocatedMeshData = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00571E10
// Name: private: int CVertexKDTree::BuildNode(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVertexKDTree::BuildNode(CVertexKDTree *this, unsigned int nStart, int nCount)
{
  int v3; // ebx
  float v5; // xmm2_4
  int MidpointIndex; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  float v11; // xmm0_4
  int v12; // edx
  CVertexKDNode *v13; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CVertexKDNode *m_pMemory; // ecx
  int v18; // eax
  CVertexKDNode *v19; // eax
  Vector mins; // [esp+10h] [ebp-24h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-18h] BYREF
  float flSplit; // [esp+28h] [ebp-Ch]
  int nSplit; // [esp+2Ch] [ebp-8h]
  int nAxis; // [esp+30h] [ebp-4h]
  int nIndex; // [esp+40h] [ebp+Ch]

  v3 = nCount;
  if ( nCount <= 8 )
    goto LABEL_11;
  CVertexKDTree::ComputeBounds(this, pMins: &mins, pMaxs: &maxs, nStart, nCount);
  v5 = maxs.z - mins.z;
  if ( (float)(maxs.x - mins.x) < (float)(maxs.y - mins.y) )
  {
    nAxis = 1;
    if ( (float)(maxs.y - mins.y) > v5 )
      goto LABEL_7;
  }
  else if ( (float)(maxs.x - mins.x) > v5 )
  {
    nAxis = 0;
    goto LABEL_7;
  }
  nAxis = 2;
LABEL_7:
  flSplit = (float)(*(&maxs.x + nAxis) + *(&mins.x + nAxis)) * 0.5;
  MidpointIndex = CVertexKDTree::FindMidpointIndex(this, nStart, nCount, nAxis, flSplit);
  v7 = MidpointIndex - nStart;
  v8 = nCount + nStart - MidpointIndex;
  nSplit = MidpointIndex;
  if ( MidpointIndex != nStart && v8 != 0 )
  {
    nIndex = CUtlVector<CVertexKDNode,CUtlMemory<CVertexKDNode,int>>::AddToTail(this: &this->m_tree);
    v9 = CVertexKDTree::BuildNode(this, nStart, nCount: v7);
    v10 = CVertexKDTree::BuildNode(this, nStart: nSplit, nCount: v8);
    v11 = flSplit;
    v12 = nIndex;
    v13 = &this->m_tree.m_Memory.m_pMemory[nIndex];
    v13->m_nAxis = nAxis;
    v13->m_flSplit = v11;
    v13->m_nChildren[0] = -1;
    v13->m_nChildren[1] = -1;
    this->m_tree.m_Memory.m_pMemory[v12].m_nChildren[0] = v9;
    this->m_tree.m_Memory.m_pMemory[v12].m_nChildren[1] = v10;
    return nIndex;
  }
  v3 = nCount;
LABEL_11:
  m_Size = this->m_tree.m_Size;
  m_nAllocationCount = this->m_tree.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_tree.m_Size;
  m_pMemory = this->m_tree.m_Memory.m_pMemory;
  v18 = this->m_tree.m_Size - m_Size - 1;
  this->m_tree.m_pElements = this->m_tree.m_Memory.m_pMemory;
  if ( v18 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v18);
  v19 = &this->m_tree.m_Memory.m_pMemory[m_Size];
  v19->m_nChildren[1] = v3;
  v19->m_nAxis = 255;
  v19->m_flSplit = 0.0;
  v19->m_nChildren[0] = nStart;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00571FA0
// Name: public: void CVertexKDTree::FindVertsInBox(class CUtlVectorFixedGrowable<float const __near *,64> __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexKDTree::FindVertsInBox(
        CVertexKDTree *this,
        CUtlVectorFixedGrowable<float const *,64> *list,
        const Vector *mins,
        const Vector *maxs,
        const float *nStartNode)
{
  CVertexKDNode *v6; // esi
  int m_nAxis; // edi
  const Vector *v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // esi
  int i; // edi
  const float *v13; // eax
  float v14; // xmm0_4
  bool v15; // cf
  float v16; // xmm0_4
  float v17; // xmm0_4

  v6 = &this->m_tree.m_Memory.m_pMemory[(_DWORD)nStartNode];
  m_nAxis = v6->m_nAxis;
  if ( m_nAxis == 255 )
  {
    v8 = mins;
LABEL_8:
    v9 = v6->m_nChildren[1];
    v10 = v6->m_nChildren[0];
    if ( v9 > 0 )
    {
      v11 = v10;
      for ( i = v9; i != 0; --i )
      {
        v13 = this->m_vertexList.m_Memory.m_pMemory[v11];
        v14 = *v13;
        v15 = *v13 < v8->x;
        nStartNode = v13;
        if ( !v15 && maxs->x >= v14 )
        {
          v16 = v13[1];
          if ( v16 >= v8->y && maxs->y >= v16 )
          {
            v17 = v13[2];
            if ( v17 >= v8->z && maxs->z >= v17 )
            {
              CUtlVector<float const *,CUtlMemoryFixedGrowable<float const *,64,int>>::InsertBefore(
                this: list,
                elem: list->m_Size,
                src: &nStartNode);
              v8 = mins;
            }
          }
        }
        ++v11;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v8 = mins;
      if ( v6->m_flSplit >= *(&mins->x + m_nAxis) )
      {
        CVertexKDTree::FindVertsInBox(this, list, mins, maxs, nStartNode: v6->m_nChildren[0]);
        v8 = mins;
      }
      if ( *(&maxs->x + m_nAxis) < v6->m_flSplit )
        break;
      v6 = &this->m_tree.m_Memory.m_pMemory[v6->m_nChildren[1]];
      m_nAxis = v6->m_nAxis;
      if ( m_nAxis == 255 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00572090
// Name: bool WeldVertices(class CMesh __near *,class CMesh const __near &,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl WeldVertices(CMesh *pMeshOut, int inputMesh, float *pEpsilons, const float *nEpsilons)
{
  float *v6; // eax
  int v7; // edi
  int v8; // eax
  const float *v9; // ecx
  int v10; // eax
  float v11; // xmm0_4
  float *v12; // edi
  float v13; // xmm1_4
  float v14; // xmm2_4
  int v15; // eax
  int v16; // esi
  int v17; // eax
  unsigned int *m_pMemory; // edx
  float *v19; // ecx
  int v20; // edi
  char *v21; // eax
  int v22; // edx
  int m_Size; // esi
  int v24; // eax
  const float **v25; // ecx
  int v26; // eax
  float **v27; // eax
  int k; // edi
  int m; // eax
  const float **v30; // eax
  const float **v31; // eax
  CVertexKDNode *v32; // eax
  int v33; // [esp-Ch] [ebp-19Ch]
  CUtlVectorFixedGrowable<float const *,64> list; // [esp+4h] [ebp-18Ch] BYREF
  Vector maxs; // [esp+11Ch] [ebp-74h] BYREF
  Vector mins; // [esp+128h] [ebp-68h] BYREF
  int v37; // [esp+134h] [ebp-5Ch]
  int nMatchIndex; // [esp+138h] [ebp-58h]
  int j; // [esp+13Ch] [ebp-54h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > remapTable; // [esp+140h] [ebp-50h] BYREF
  CVertexKDTree searchTree; // [esp+154h] [ebp-3Ch] BYREF
  CUtlVector<float const *,CUtlMemory<float const *,int> > inOrderVertices; // [esp+17Ch] [ebp-14h] BYREF
  int i; // [esp+19Ch] [ebp+Ch]
  int ia; // [esp+19Ch] [ebp+Ch]
  int ib; // [esp+19Ch] [ebp+Ch]
  const float *pVertex; // [esp+1A4h] [ebp+14h]
  const float *pVertexa; // [esp+1A4h] [ebp+14h]

  i = *(_DWORD *)(inputMesh + 16);
  if ( nEpsilons != (const float *)i )
    return 0;
  v6 = *(float **)inputMesh;
  v7 = *(_DWORD *)(inputMesh + 12);
  memset(&searchTree, 0, sizeof(searchTree));
  pVertex = v6;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&searchTree.m_vertexList,
    elem: 0,
    num: v7);
  v8 = 0;
  if ( v7 > 0 )
  {
    v9 = pVertex;
    ia = 4 * i;
    do
    {
      searchTree.m_vertexList.m_Memory.m_pMemory[v8] = v9;
      v9 = (const float *)((char *)v9 + ia);
      ++v8;
    }
    while ( v8 < v7 );
  }
  CVertexKDTree::BuildNode(this: &searchTree, nStart: 0, nCount: v7);
  v33 = *(_DWORD *)(inputMesh + 12);
  memset(&inOrderVertices, 0, sizeof(inOrderVertices));
  memset(&remapTable, 0, sizeof(remapTable));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&remapTable,
    elem: 0,
    num: v33);
  if ( remapTable.m_Size > 0 )
    memset(remapTable.m_Memory.m_pMemory, 0xFFu, 4 * remapTable.m_Size);
  list.m_Memory.m_pMemory = list.m_Memory.m_pFixedMemory;
  v10 = 0;
  list.m_Memory.m_nAllocationCount = 64;
  list.m_Memory.m_nGrowSize = -1;
  list.m_Memory.m_nMallocGrowSize = 0;
  list.m_Size = 0;
  list.m_pElements = list.m_Memory.m_pFixedMemory;
  ib = 0;
  if ( *(int *)(inputMesh + 12) <= 0 )
    goto LABEL_28;
  do
  {
    if ( remapTable.m_Memory.m_pMemory[v10] != -1 )
      goto LABEL_27;
    v11 = *pEpsilons;
    v12 = (float *)(*(_DWORD *)inputMesh + 4 * v10 * *(_DWORD *)(inputMesh + 16));
    mins.x = *v12 - *pEpsilons;
    v13 = pEpsilons[1];
    mins.y = v12[1] - v13;
    v14 = pEpsilons[2];
    mins.z = v12[2] - v14;
    maxs.x = v11 + *v12;
    maxs.y = v13 + v12[1];
    pVertexa = v12;
    maxs.z = v14 + v12[2];
    list.m_Size = 0;
    CVertexKDTree::FindVertsInBox(this: &searchTree, &list, &mins, &maxs, nStartNode: nullptr);
    v15 = 0;
    j = 0;
    if ( list.m_Size <= 0 )
      goto LABEL_18;
    while ( list.m_Memory.m_pMemory[v15] >= v12 )
    {
LABEL_63:
      j = ++v15;
      if ( v15 >= list.m_Size )
        goto LABEL_18;
    }
    v16 = *(_DWORD *)(inputMesh + 16);
    v17 = (((int)list.m_Memory.m_pMemory[v15] - *(_DWORD *)inputMesh) >> 2) / v16;
    m_pMemory = remapTable.m_Memory.m_pMemory;
    v19 = (float *)inOrderVertices.m_Memory.m_pMemory[remapTable.m_Memory.m_pMemory[v17]];
    v20 = 0;
    nMatchIndex = v17;
    if ( v16 > 0 )
    {
      v37 = (char *)pVertexa - (char *)v19;
      v21 = (char *)((char *)pEpsilons - (char *)v19);
      v22 = (char *)pVertexa - (char *)v19;
      while ( fabs(*(float *)((char *)v19 + v22) - *v19) <= *(float *)((char *)v19 + (_DWORD)v21) )
      {
        ++v20;
        ++v19;
        if ( v20 >= v16 )
        {
          m_pMemory = remapTable.m_Memory.m_pMemory;
          v17 = nMatchIndex;
          goto LABEL_17;
        }
      }
      v15 = j;
      v12 = (float *)pVertexa;
      goto LABEL_63;
    }
LABEL_17:
    v12 = (float *)pVertexa;
    m_pMemory[ib] = m_pMemory[v17];
LABEL_18:
    if ( remapTable.m_Memory.m_pMemory[ib] == -1 )
    {
      m_Size = inOrderVertices.m_Size;
      v24 = inOrderVertices.m_Size;
      if ( inOrderVertices.m_Size + 1 > inOrderVertices.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&inOrderVertices,
          num: inOrderVertices.m_Size - inOrderVertices.m_Memory.m_nAllocationCount + 1);
        v24 = inOrderVertices.m_Size;
      }
      v25 = inOrderVertices.m_Memory.m_pMemory;
      inOrderVertices.m_Size = v24 + 1;
      v26 = v24 - m_Size;
      inOrderVertices.m_pElements = inOrderVertices.m_Memory.m_pMemory;
      if ( v26 > 0 )
      {
        _V_memmove(
          dest: &inOrderVertices.m_Memory.m_pMemory[m_Size + 1],
          src: &inOrderVertices.m_Memory.m_pMemory[m_Size],
          count: 4 * v26);
        v25 = inOrderVertices.m_Memory.m_pMemory;
      }
      v27 = (float **)&v25[m_Size];
      if ( v27 != nullptr )
        *v27 = v12;
      remapTable.m_Memory.m_pMemory[ib] = m_Size;
    }
    v10 = ib;
LABEL_27:
    ib = ++v10;
  }
  while ( v10 < *(_DWORD *)(inputMesh + 12) );
LABEL_28:
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: inOrderVertices.m_Size,
    nIndexCount: *(_DWORD *)(inputMesh + 24),
    nVertexStride: *(_DWORD *)(inputMesh + 16),
    pAttributes: *(CMeshVertexAttribute **)(inputMesh + 4),
    nAtrributeCount: *(_DWORD *)(inputMesh + 20));
  for ( k = 0; k < inOrderVertices.m_Size; ++k )
    CopyVertex(
      pOut: &pMeshOut->m_pVerts[k * pMeshOut->m_nVertexStrideFloats],
      pIn: inOrderVertices.m_Memory.m_pMemory[k],
      nFloats: *(_DWORD *)(inputMesh + 16));
  for ( m = 0; m < *(_DWORD *)(inputMesh + 24); ++m )
    pMeshOut->m_pIndices[m] = remapTable.m_Memory.m_pMemory[*(_DWORD *)(*(_DWORD *)(inputMesh + 8) + 4 * m)];
  v30 = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      v30 = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = v30;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v30 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v30);
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  if ( remapTable.m_Memory.m_nGrowSize >= 0 && remapTable.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: remapTable.m_Memory.m_pMemory);
  if ( inOrderVertices.m_Memory.m_nGrowSize >= 0 && inOrderVertices.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: inOrderVertices.m_Memory.m_pMemory);
  v31 = searchTree.m_vertexList.m_Memory.m_pMemory;
  searchTree.m_vertexList.m_Size = 0;
  if ( searchTree.m_vertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( searchTree.m_vertexList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: searchTree.m_vertexList.m_Memory.m_pMemory);
      v31 = nullptr;
      searchTree.m_vertexList.m_Memory.m_pMemory = nullptr;
    }
    searchTree.m_vertexList.m_Memory.m_nAllocationCount = 0;
  }
  searchTree.m_vertexList.m_pElements = v31;
  if ( searchTree.m_vertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v31 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
      searchTree.m_vertexList.m_Memory.m_pMemory = nullptr;
    }
    searchTree.m_vertexList.m_Memory.m_nAllocationCount = 0;
  }
  v32 = searchTree.m_tree.m_Memory.m_pMemory;
  searchTree.m_tree.m_Size = 0;
  if ( searchTree.m_tree.m_Memory.m_nGrowSize >= 0 )
  {
    if ( searchTree.m_tree.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: searchTree.m_tree.m_Memory.m_pMemory);
      v32 = nullptr;
      searchTree.m_tree.m_Memory.m_pMemory = nullptr;
    }
    searchTree.m_tree.m_Memory.m_nAllocationCount = 0;
  }
  searchTree.m_tree.m_pElements = v32;
  if ( searchTree.m_tree.m_Memory.m_nGrowSize >= 0 && v32 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00572510
// Name: void CleanMesh(class CMesh __near *,class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CleanMesh(CMesh *pMeshOut, int inputMesh)
{
  int v3; // ebx
  unsigned int *m_pMemory; // edi
  int i; // eax
  int v6; // edx
  unsigned int *v7; // eax
  unsigned int v8; // ecx
  int v9; // ebx
  unsigned int v10; // eax
  int v11; // ebx
  int v12; // edx
  int v13; // eax
  unsigned int *v14; // ecx
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // [esp-4h] [ebp-30h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > indexMap; // [esp+Ch] [ebp-20h] BYREF
  int nV2; // [esp+20h] [ebp-Ch]
  int nV0; // [esp+24h] [ebp-8h]
  int nIndexOut; // [esp+28h] [ebp-4h]
  int v; // [esp+38h] [ebp+Ch]
  int va; // [esp+38h] [ebp+Ch]
  int vb; // [esp+38h] [ebp+Ch]

  v3 = 0;
  v17 = *(_DWORD *)(inputMesh + 12);
  memset(&indexMap, 0, sizeof(indexMap));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&indexMap,
    elem: 0,
    num: v17);
  m_pMemory = indexMap.m_Memory.m_pMemory;
  for ( i = 0; i < *(_DWORD *)(inputMesh + 12); ++i )
    m_pMemory[i] = -1;
  v6 = 0;
  nIndexOut = 0;
  v = 0;
  if ( *(int *)(inputMesh + 24) > 0 )
  {
    do
    {
      v7 = *(unsigned int **)(inputMesh + 8);
      v8 = v7[v3];
      nV0 = v7[v3 + 1];
      v9 = v;
      v10 = v7[v + 2];
      if ( v8 != nV0 )
      {
        v11 = nV0;
        if ( nV0 != v10 && v8 != v10 )
        {
          if ( m_pMemory[v8] == -1 )
            m_pMemory[v8] = v6++;
          if ( m_pMemory[v11] == -1 )
            m_pMemory[v11] = v6++;
          if ( m_pMemory[v10] == -1 )
            m_pMemory[v10] = v6++;
          nIndexOut += 3;
        }
        v9 = v;
      }
      v3 = v9 + 3;
      v = v3;
    }
    while ( v3 < *(_DWORD *)(inputMesh + 24) );
  }
  CMesh::AllocateMesh(
    this: pMeshOut,
    nVertexCount: v6,
    nIndexCount: nIndexOut,
    nVertexStride: *(_DWORD *)(inputMesh + 16),
    pAttributes: *(CMeshVertexAttribute **)(inputMesh + 4),
    nAtrributeCount: *(_DWORD *)(inputMesh + 20));
  v12 = 0;
  va = 0;
  if ( *(int *)(inputMesh + 24) > 0 )
  {
    v13 = 0;
    do
    {
      v14 = *(unsigned int **)(inputMesh + 8);
      nV0 = v14[v12];
      nIndexOut = v14[va + 1];
      nV2 = v14[va + 2];
      if ( nV0 != nIndexOut && nIndexOut != nV2 && nV0 != nV2 )
      {
        pMeshOut->m_pIndices[v13] = m_pMemory[nV0];
        pMeshOut->m_pIndices[v13 + 1] = m_pMemory[nIndexOut];
        pMeshOut->m_pIndices[v13 + 2] = m_pMemory[nV2];
        v13 += 3;
      }
      v12 = va + 3;
      va = v12;
    }
    while ( v12 < *(_DWORD *)(inputMesh + 24) );
  }
  v15 = 0;
  for ( vb = 0; v15 < *(_DWORD *)(inputMesh + 12); vb = v15 )
  {
    v16 = m_pMemory[v15];
    if ( v16 != -1 )
    {
      CopyVertex(
        pOut: &pMeshOut->m_pVerts[v16 * pMeshOut->m_nVertexStrideFloats],
        pIn: (const float *)(*(_DWORD *)inputMesh + 4 * v15 * *(_DWORD *)(inputMesh + 16)),
        nFloats: *(_DWORD *)(inputMesh + 16));
      v15 = vb;
    }
    ++v15;
  }
  if ( indexMap.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005726B0
// Name: public: void CMesh::CalculateTangents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMesh::CalculateTangents(CMesh *this)
{
  int m_nAttributeCount; // eax
  int v3; // ecx
  CMeshVertexAttribute *m_pAttributes; // esi
  VertexElement_t *p_m_nType; // edx
  int m_nOffsetFloats; // edi
  int v7; // ecx
  CMeshVertexAttribute *v8; // esi
  VertexElement_t *v9; // edx
  int v10; // ecx
  CMeshVertexAttribute *v11; // esi
  VertexElement_t *v12; // edx
  int v13; // esi
  int v14; // ecx
  CMeshVertexAttribute *v15; // esi
  VertexElement_t *v16; // edx
  int v17; // ebx
  unsigned int *m_pIndices; // eax
  unsigned int v19; // ecx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *v22; // esi
  S3RGBA *m_pMemory; // ecx
  int v24; // eax
  int *v25; // ebx
  bool v26; // zf
  _DWORD *v27; // ebx
  int m_nVertexStrideFloats; // ecx
  float *m_pVerts; // edx
  int v30; // eax
  float v31; // xmm0_4
  float *v32; // eax
  float v33; // xmm0_4
  float *v34; // eax
  bool v35; // cc
  int v36; // ebx
  int *p_m_Size; // edi
  float v38; // xmm0_4
  int v39; // esi
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm5_4
  float v44; // xmm4_4
  int v45; // eax
  Vector *v46; // ecx
  Vector *v47; // ecx
  int v48; // eax
  int v49; // xmm0_4
  CMesh *v50; // ecx
  int m_nVertexCount; // [esp-4h] [ebp-B4h]
  Vector vPos[3]; // [esp+Ch] [ebp-A4h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > faceSVect; // [esp+30h] [ebp-80h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > faceTVect; // [esp+44h] [ebp-6Ch] BYREF
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > vertToFaceMap; // [esp+58h] [ebp-58h] BYREF
  unsigned int *v56; // [esp+6Ch] [ebp-44h]
  Vector tVect; // [esp+70h] [ebp-40h] BYREF
  Vector v58; // [esp+7Ch] [ebp-34h] BYREF
  int nNormalOffset; // [esp+88h] [ebp-28h]
  int nTangentOffset; // [esp+8Ch] [ebp-24h]
  int nTexOffset; // [esp+90h] [ebp-20h]
  int v62; // [esp+94h] [ebp-1Ch]
  CMesh *v63; // [esp+98h] [ebp-18h]
  int vertID; // [esp+9Ch] [ebp-14h]
  int faceID; // [esp+A0h] [ebp-10h]
  Vector vec; // [esp+A4h] [ebp-Ch] BYREF

  m_nAttributeCount = this->m_nAttributeCount;
  v3 = 0;
  v63 = this;
  if ( m_nAttributeCount <= 0 )
  {
LABEL_5:
    m_nOffsetFloats = -1;
  }
  else
  {
    m_pAttributes = this->m_pAttributes;
    p_m_nType = &m_pAttributes->m_nType;
    while ( *p_m_nType != VERTEX_ELEMENT_POSITION )
    {
      ++v3;
      p_m_nType += 2;
      if ( v3 >= m_nAttributeCount )
        goto LABEL_5;
    }
    m_nOffsetFloats = m_pAttributes[v3].m_nOffsetFloats;
  }
  v7 = 0;
  if ( m_nAttributeCount <= 0 )
  {
LABEL_10:
    nNormalOffset = -1;
  }
  else
  {
    v8 = this->m_pAttributes;
    v9 = &v8->m_nType;
    while ( *v9 != VERTEX_ELEMENT_NORMAL )
    {
      ++v7;
      v9 += 2;
      if ( v7 >= m_nAttributeCount )
        goto LABEL_10;
    }
    nNormalOffset = v8[v7].m_nOffsetFloats;
  }
  v10 = 0;
  if ( m_nAttributeCount <= 0 )
    goto LABEL_19;
  v11 = this->m_pAttributes;
  v12 = &v11->m_nType;
  while ( *v12 != VERTEX_ELEMENT_TEXCOORD2D_0 )
  {
    ++v10;
    v12 += 2;
    if ( v10 >= m_nAttributeCount )
      goto LABEL_19;
  }
  v13 = v11[v10].m_nOffsetFloats;
  nTexOffset = v13;
  if ( v13 == -1 )
  {
LABEL_19:
    v14 = 0;
    if ( m_nAttributeCount <= 0 )
    {
LABEL_23:
      nTexOffset = -1;
    }
    else
    {
      v15 = this->m_pAttributes;
      v16 = &v15->m_nType;
      while ( *v16 != VERTEX_ELEMENT_TEXCOORD3D_0 )
      {
        ++v14;
        v16 += 2;
        if ( v14 >= m_nAttributeCount )
          goto LABEL_23;
      }
      nTexOffset = v15[v14].m_nOffsetFloats;
    }
    v13 = nTexOffset;
  }
  if ( m_nOffsetFloats == -1 || v13 == -1 || nNormalOffset == -1 )
  {
    _Msg(a1: "Need valid position, normal, and texcoord when creating tangent frames!\n");
  }
  else
  {
    nTangentOffset = CMesh::FindFirstAttributeOffset(this, nType: VERTEX_ELEMENT_TEXCOORD4D_7);
    if ( nTangentOffset == -1 )
    {
      nTangentOffset = this->m_nVertexStrideFloats;
      LODWORD(vec.y) = nTangentOffset;
      LODWORD(vec.z) = 49;
      CMesh::AddAttributes(this, pAttributes: (CMeshVertexAttribute *)&vec.y, nAttributeCount: 1);
    }
    v17 = this->m_nIndexCount / 3;
    m_nVertexCount = v63->m_nVertexCount;
    vertID = v17;
    memset(&vertToFaceMap, 0, sizeof(vertToFaceMap));
    CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&vertToFaceMap,
      elem: 0,
      num: m_nVertexCount);
    m_pIndices = v63->m_pIndices;
    LODWORD(vec.z) = m_pIndices;
    faceID = 0;
    if ( v17 > 0 )
    {
      do
      {
        v56 = m_pIndices;
        v62 = 3;
        do
        {
          v19 = *m_pIndices;
          m_Size = vertToFaceMap.m_Memory.m_pMemory[*m_pIndices].m_Size;
          m_nAllocationCount = vertToFaceMap.m_Memory.m_pMemory[*m_pIndices].m_Memory.m_nAllocationCount;
          v22 = (CUtlMemory<S3RGBA,int> *)&vertToFaceMap.m_Memory.m_pMemory[v19];
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(this: v22, num: m_Size - m_nAllocationCount + 1);
          ++v22[1].m_pMemory;
          m_pMemory = v22->m_pMemory;
          v24 = (int)v22[1].m_pMemory - m_Size - 1;
          v22[1].m_nAllocationCount = (int)v22->m_pMemory;
          if ( v24 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v24);
          v25 = (int *)&v22->m_pMemory[m_Size];
          if ( v25 != nullptr )
            *v25 = faceID;
          m_pIndices = v56 + 1;
          v26 = v62-- == 1;
          ++v56;
        }
        while ( !v26 );
        ++faceID;
      }
      while ( faceID < vertID );
      v13 = nTexOffset;
      v17 = vertID;
    }
    memset(&faceSVect, 0, sizeof(faceSVect));
    memset(&faceTVect, 0, sizeof(faceTVect));
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&faceSVect,
      elem: 0,
      num: v17);
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&faceTVect,
      elem: 0,
      num: v17);
    if ( v17 > 0 )
    {
      v27 = (_DWORD *)(LODWORD(vec.z) + 8);
      LODWORD(vec.z) = (char *)faceTVect.m_Memory.m_pMemory - (char *)faceSVect.m_Memory.m_pMemory;
      faceID = (int)faceSVect.m_Memory.m_pMemory;
      v62 = vertID;
      do
      {
        m_nVertexStrideFloats = v63->m_nVertexStrideFloats;
        m_pVerts = v63->m_pVerts;
        v30 = (int)&v63->m_pVerts[m_nVertexStrideFloats * *(v27 - 2)];
        vPos[0] = *(Vector *)(v30 + 4 * m_nOffsetFloats);
        tVect.x = *(float *)(v30 + 4 * v13);
        v31 = *(float *)(v30 + 4 * v13 + 4);
        v32 = &m_pVerts[m_nVertexStrideFloats * *(v27 - 1)];
        tVect.y = v31;
        vPos[1] = *(Vector *)&v32[m_nOffsetFloats];
        tVect.z = v32[v13];
        v33 = v32[v13 + 1];
        v34 = &m_pVerts[m_nVertexStrideFloats * *v27];
        v58.x = v33;
        vPos[2] = *(Vector *)&v34[m_nOffsetFloats];
        v58.y = v34[v13];
        v58.z = v34[v13 + 1];
        CalcTriangleTangentSpace(
          p0: vPos,
          p1: &vPos[1],
          p2: &vPos[2],
          t0: (const Vector2D *)&tVect,
          t1: (const Vector2D *)&tVect.z,
          t2: (const Vector2D *)&v58.y,
          sVect: (Vector *)faceID,
          tVect: (Vector *)(faceID + LODWORD(vec.z)));
        faceID += 12;
        v27 += 3;
        --v62;
      }
      while ( v62 != 0 );
    }
    v35 = v63->m_nVertexCount <= 0;
    vertID = 0;
    if ( !v35 )
    {
      v36 = 4 * nNormalOffset;
      nTangentOffset *= 4;
      p_m_Size = &vertToFaceMap.m_Memory.m_pMemory->m_Size;
      do
      {
        v38 = 0.0;
        v39 = (int)&v63->m_pVerts[vertID * v63->m_nVertexStrideFloats];
        v40 = 0.0;
        v41 = 0.0;
        v42 = 0.0;
        v43 = 0.0;
        v44 = 0.0;
        v45 = 0;
        memset(&vec, 0, sizeof(vec));
        memset(&v58, 0, sizeof(v58));
        if ( *p_m_Size > 0 )
        {
          do
          {
            v40 = v40 + faceSVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v45)].x;
            v46 = &faceSVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v45)];
            vec.x = v40;
            v41 = v41 + v46->y;
            vec.y = v41;
            v42 = v42 + v46->z;
            vec.z = v42;
            v43 = v43 + faceTVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v45)].x;
            v47 = &faceTVect.m_Memory.m_pMemory[*(_DWORD *)(*(p_m_Size - 3) + 4 * v45)];
            v58.x = v43;
            v38 = v38 + v47->y;
            v58.y = v38;
            v44 = v44 + v47->z;
            ++v45;
            v58.z = v44;
          }
          while ( v45 < *p_m_Size );
        }
        if ( (float)((float)((float)(*(float *)(v36 + v39) * (float)((float)(v44 * v41) - (float)(v38 * v42)))
                           + (float)(*(float *)(v36 + v39 + 4) * (float)((float)(v42 * v43) - (float)(v44 * v40))))
                   + (float)(*(float *)(v36 + v39 + 8) * (float)((float)(v38 * v40) - (float)(v41 * v43)))) < 0.0 )
        {
          v58.x = (float)(*(float *)(v36 + v39 + 8) * v41) - (float)(*(float *)(v36 + v39 + 4) * v42);
          v58.y = (float)(*(float *)(v36 + v39) * v42) - (float)(*(float *)(v36 + v39 + 8) * v40);
          v58.z = (float)(*(float *)(v36 + v39 + 4) * v40) - (float)(*(float *)(v36 + v39) * v41);
          vec.x = (float)(*(float *)(v36 + v39 + 4) * v58.z) - (float)(*(float *)(v36 + v39 + 8) * v58.y);
          vec.y = (float)(*(float *)(v36 + v39 + 8) * v58.x) - (float)(*(float *)(v36 + v39) * v58.z);
          vec.z = (float)(*(float *)(v36 + v39) * v58.y) - (float)(*(float *)(v36 + v39 + 4) * v58.x);
          VectorNormalize(&vec);
          VectorNormalize(vec: &v58);
          v48 = nTangentOffset;
          *(Vector *)(nTangentOffset + v39) = vec;
          v49 = -1082130432;
        }
        else
        {
          v58.x = (float)(*(float *)(v36 + v39 + 4) * v42) - (float)(*(float *)(v36 + v39 + 8) * v41);
          v58.y = (float)(*(float *)(v36 + v39 + 8) * v40) - (float)(*(float *)(v36 + v39) * v42);
          v58.z = (float)(*(float *)(v36 + v39) * v41) - (float)(*(float *)(v36 + v39 + 4) * v40);
          vec.x = (float)(*(float *)(v36 + v39 + 8) * v58.y) - (float)(*(float *)(v36 + v39 + 4) * v58.z);
          vec.y = (float)(*(float *)(v36 + v39) * v58.z) - (float)(*(float *)(v36 + v39 + 8) * v58.x);
          vec.z = (float)(*(float *)(v36 + v39 + 4) * v58.x) - (float)(*(float *)(v36 + v39) * v58.y);
          VectorNormalize(&vec);
          VectorNormalize(vec: &v58);
          v48 = nTangentOffset;
          *(Vector *)(nTangentOffset + v39) = vec;
          v49 = 1065353216;
        }
        v50 = v63;
        *(_DWORD *)(v48 + v39 + 12) = v49;
        p_m_Size += 5;
        ++vertID;
      }
      while ( vertID < v50->m_nVertexCount );
    }
    if ( faceTVect.m_Memory.m_nGrowSize >= 0 && faceTVect.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceTVect.m_Memory.m_pMemory);
    if ( faceSVect.m_Memory.m_nGrowSize >= 0 && faceSVect.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceSVect.m_Memory.m_pMemory);
    CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&vertToFaceMap);
    if ( vertToFaceMap.m_Memory.m_nGrowSize >= 0 && vertToFaceMap.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertToFaceMap.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00573DA0
// Name: public: int CUtlScalarHash<struct edge_hash_t,class CDefaultHash32>::Insert(unsigned int,struct edge_hash_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<edge_hash_t,CDefaultHash32>::Insert(
        CUtlScalarHash<edge_hash_t,CDefaultHash32> *this,
        unsigned int uiKey,
        const edge_hash_t *data)
{
  unsigned int m_uiBucketMask; // edi
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ecx
  unsigned int result; // eax

  if ( this->m_dataCount >= this->m_maxData )
    CUtlScalarHash<edge_hash_t,CDefaultHash32>::Grow(this);
  m_uiBucketMask = this->m_uiBucketMask;
  ++this->m_dataCount;
  m_pData = this->m_pData;
  for ( result = m_uiBucketMask
               & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
        m_pData[result].m_uiKey != -1;
        result = m_uiBucketMask & (result + 1) )
  {
    ;
  }
  this->m_pData[result].m_uiKey = uiKey;
  this->m_pData[result].m_Data = *data;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00573E50
// Name: public: void CUtlScalarHash<struct edge_hash_t,class CDefaultHash32>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlScalarHash<edge_hash_t,CDefaultHash32>::Remove(
        CUtlScalarHash<edge_hash_t,CDefaultHash32> *this,
        unsigned int hHash)
{
  unsigned int m_uiBucketMask; // eax
  unsigned int v3; // eax
  unsigned int v4; // edi
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ebx
  unsigned int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // [esp+8h] [ebp-Ch]
  int mid; // [esp+Ch] [ebp-8h]
  unsigned int index; // [esp+10h] [ebp-4h]

  m_uiBucketMask = this->m_uiBucketMask;
  this->m_pData[hHash].m_uiKey = -1;
  --this->m_dataCount;
  index = this->m_uiBucketMask & (hHash + 1);
  v3 = (m_uiBucketMask + 1) >> 1;
  v4 = index;
  mid = v3;
  if ( this->m_pData[index].m_uiKey != -1 )
  {
    v9 = -v3;
    do
    {
      m_pData = this->m_pData;
      v6 = this->m_uiBucketMask;
      v7 = (this->m_uiBucketMask
          & (HIBYTE(m_pData[v4].m_uiKey)
           + 33
           * ((unsigned __int8)BYTE2(m_pData[v4].m_uiKey)
            + 33 * (33 * (unsigned __int8)m_pData[v4].m_uiKey + (unsigned __int8)BYTE1(m_pData[v4].m_uiKey) - 22))))
         - hHash;
      if ( v7 > mid )
        v7 += -1 - v6;
      if ( v7 < v9 )
        v7 += v6 + 1;
      if ( v7 <= 0 )
      {
        v8 = hHash;
        *(_QWORD *)&m_pData[v8].m_uiKey = *(_QWORD *)&m_pData[v4].m_uiKey;
        *(_QWORD *)&m_pData[v8].m_Data.m_nV0 = *(_QWORD *)&m_pData[v4].m_Data.m_nV0;
        hHash = index;
        this->m_pData[v4].m_uiKey = -1;
      }
      index = this->m_uiBucketMask & (index + 1);
      v4 = index;
    }
    while ( this->m_pData[index].m_uiKey != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00573F50
// Name: public: int CUtlScalarHash<struct edge_hash_t,class CDefaultHash32>::Find(unsigned int,struct edge_hash_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlScalarHash<edge_hash_t,CDefaultHash32>::Find(
        CUtlScalarHash<edge_hash_t,CDefaultHash32> *this,
        unsigned int uiKey,
        const edge_hash_t *dataRecord)
{
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ebx
  unsigned int result; // eax
  unsigned int m_uiBucketMask; // edi
  unsigned int m_uiKey; // edx
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *v7; // ecx

  m_pData = this->m_pData;
  if ( m_pData == nullptr )
    return -1;
  m_uiBucketMask = this->m_uiBucketMask;
  result = this->m_uiBucketMask
         & (HIBYTE(uiKey) + 33 * (BYTE2(uiKey) + 33 * (33 * (unsigned __int8)uiKey + BYTE1(uiKey) - 22)));
  m_uiKey = m_pData[result].m_uiKey;
  v7 = &m_pData[result];
  if ( m_uiKey == -1 )
    return -1;
  while ( m_uiKey != uiKey || dataRecord->m_nV0 != v7->m_Data.m_nV0 || dataRecord->m_nV1 != v7->m_Data.m_nV1 )
  {
    result = m_uiBucketMask & (result + 1);
    m_uiKey = m_pData[result].m_uiKey;
    v7 = &m_pData[result];
    if ( m_uiKey == -1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00574000
// Name: public: void CUtlScalarHash<struct edge_hash_t,class CDefaultHash32>::Grow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlScalarHash<edge_hash_t,CDefaultHash32>::Grow(CUtlScalarHash<edge_hash_t,CDefaultHash32> *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  unsigned int *p_m_uiKey; // ecx
  unsigned int v7; // edi
  unsigned int m_uiBucketMask; // edx
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *m_pData; // ecx
  int i; // eax
  int v11; // eax
  edge_hash_t *p_m_Data; // eax
  bool v13; // zf
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *pOldData; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *v16; // [esp+14h] [ebp-4h]

  v2 = 2 * this->m_maxData;
  pOldData = this->m_pData;
  v3 = v2;
  if ( v2 <= 16 )
    v3 = 16;
  v4 = 2 * v3;
  this->m_maxData = v3;
  this->m_pData = (CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *)MemAlloc_Alloc(
                                                                                    nSize: (unsigned __int64)(unsigned int)(2 * v3) >> 28 != 0
                                                                                  ? -1
                                                                                  : 32 * v3);
  this->m_uiBucketMask = v4 - 1;
  this->m_dataCount = 0;
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      this->m_pData[v5++].m_uiKey = -1;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v2 > 0 )
  {
    p_m_uiKey = &pOldData->m_uiKey;
    v16 = pOldData;
    v15 = v2;
    do
    {
      v7 = *p_m_uiKey;
      if ( *p_m_uiKey != -1 )
      {
        if ( this->m_dataCount >= this->m_maxData )
          CUtlScalarHash<edge_hash_t,CDefaultHash32>::Grow(this);
        m_uiBucketMask = this->m_uiBucketMask;
        ++this->m_dataCount;
        m_pData = this->m_pData;
        for ( i = m_uiBucketMask & (HIBYTE(v7) + 33 * (BYTE2(v7) + 33 * (33 * (unsigned __int8)v7 + BYTE1(v7) - 22)));
              m_pData[i].m_uiKey != -1;
              i = m_uiBucketMask & (i + 1) )
        {
          ;
        }
        v11 = i;
        this->m_pData[v11].m_uiKey = v7;
        p_m_uiKey = &v16->m_uiKey;
        p_m_Data = &this->m_pData[v11].m_Data;
        *(_QWORD *)&p_m_Data->m_pSharedEdge = *(_QWORD *)&v16->m_Data.m_pSharedEdge;
        p_m_Data->m_nV1 = v16->m_Data.m_nV1;
      }
      p_m_uiKey += 4;
      v13 = v15-- == 1;
      v16 = (CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *)p_m_uiKey;
    }
    while ( !v13 );
  }
  free(pMem: pOldData);
}

//------------------------------------------------------------------------------
// Address: 0x00574810
// Name: public: bool CUtlScalarHash<struct edge_hash_t,class CDefaultHash32>::Init(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlScalarHash<edge_hash_t,CDefaultHash32>::Init(
        CUtlScalarHash<edge_hash_t,CDefaultHash32> *this,
        int nBucketCount)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx

  v3 = (((((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
            | ((unsigned int)(nBucketCount - 1) >> 1)
            | (nBucketCount - 1)) >> 4)
          | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 8)
        | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 16)
      | ((((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
          | ((unsigned int)(nBucketCount - 1) >> 1)
          | (nBucketCount - 1)) >> 4)
        | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 8)
      | ((((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
        | ((unsigned int)(nBucketCount - 1) >> 1)
        | (nBucketCount - 1)) >> 4)
      | ((((unsigned int)(nBucketCount - 1) >> 1) | (nBucketCount - 1)) >> 2)
      | ((unsigned int)(nBucketCount - 1) >> 1)
      | (nBucketCount - 1))
     + 1;
  v4 = 2 * v3;
  this->m_maxData = v3;
  this->m_pData = (CUtlScalarHash<edge_hash_t,CDefaultHash32>::HashScalarData_t *)MemAlloc_Alloc(
                                                                                    nSize: (unsigned __int64)(unsigned int)(2 * v3) >> 28 != 0
                                                                                  ? -1
                                                                                  : 32 * v3);
  v5 = 2 * this->m_maxData;
  this->m_uiBucketMask = v4 - 1;
  if ( v5 > 0 )
  {
    v6 = 0;
    do
    {
      this->m_pData[v6++].m_uiKey = -1;
      --v5;
    }
    while ( v5 != 0 );
  }
  this->m_dataCount = 0;
  return 1;
}

} // namespace vmap
