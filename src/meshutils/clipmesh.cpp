// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/clipmesh.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00408D80
// Name: void ClipTriangle(float __near *,float __near *,int __near *,int __near *,int,float __near * __near *,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipTriangle(
        float *pBackOut,
        float *pFrontOut,
        int *pNumBackOut,
        int *pNumFrontOut,
        int nStrideFloats,
        float **ppVertsIn,
        Vector4D *vClipPlane)
{
  int v8; // ebp
  int v9; // ebx
  float *v10; // eax
  double v11; // st4
  float *flLerp; // [esp+0h] [ebp-58h]
  float flLerpa; // [esp+0h] [ebp-58h]
  int nFront; // [esp+1Ch] [ebp-3Ch]
  int flDot2; // [esp+20h] [ebp-38h]
  float flDot1; // [esp+24h] [ebp-34h]
  int nxtVert; // [esp+28h] [ebp-30h]
  int vPlaneNormal; // [esp+30h] [ebp-28h]
  float vPlaneNormal_4; // [esp+34h] [ebp-24h]
  float vPlaneNormal_8; // [esp+38h] [ebp-20h]
  float vPos1; // [esp+3Ch] [ebp-1Ch]

  v8 = 0;
  vPlaneNormal_4 = vClipPlane->x;
  nFront = 0;
  flDot2 = 0;
  vPlaneNormal_8 = vClipPlane->y;
  vPos1 = vClipPlane->z;
  v9 = 4 * nStrideFloats;
  do
  {
    vPlaneNormal = v8 + 1;
    flLerp = ppVertsIn[v8];
    v10 = ppVertsIn[(v8 + 1) % 3];
    v11 = flLerp[1] * vPlaneNormal_8 + vPlaneNormal_4 * *flLerp + flLerp[2] * vPos1 - vClipPlane->w;
    *(float *)&nxtVert = v11;
    flDot1 = vPos1 * v10[2] + vPlaneNormal_4 * *v10 + vPlaneNormal_8 * v10[1] - vClipPlane->w;
    if ( v11 >= 0.0 )
    {
      CopyVertex(pOut: pFrontOut, pIn: flLerp, nFloats: nStrideFloats);
      ++flDot2;
      pFrontOut = (float *)((char *)pFrontOut + v9);
    }
    else
    {
      CopyVertex(pOut: pBackOut, pIn: flLerp, nFloats: nStrideFloats);
      ++nFront;
      pBackOut = (float *)((char *)pBackOut + v9);
    }
    if ( flDot1 * *(float *)&nxtVert < 0.0 )
    {
      flLerpa = -1.0 / (flDot1 - *(float *)&nxtVert) * *(float *)&nxtVert;
      LerpVertex(
        pOutput: pBackOut,
        pLeft: ppVertsIn[v8],
        pRight: ppVertsIn[(v8 + 1) % 3],
        flLerp: flLerpa,
        nFloats: nStrideFloats);
      CopyVertex(pOut: pFrontOut, pIn: pBackOut, nFloats: nStrideFloats);
      ++nFront;
      ++flDot2;
      pBackOut = (float *)((char *)pBackOut + v9);
      pFrontOut = (float *)((char *)pFrontOut + v9);
    }
    ++v8;
  }
  while ( vPlaneNormal < 3 );
  *pNumBackOut = nFront;
  *pNumFrontOut = flDot2;
}

//------------------------------------------------------------------------------
// Address: 0x00408F30
// Name: bool ClipMeshToHalfSpace(class CMesh __near *,class CMesh __near *,class CMesh const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipMeshToHalfSpace(CMesh *pMeshBack, CMesh *pMeshFront, CMesh *inputMesh, Vector4D *vClipPlane)
{
  CMesh *v4; // ebx
  int m_nIndexCount; // eax
  float *m_pVerts; // edx
  int m_nVertexStrideFloats; // edi
  unsigned int v9; // esi
  float *v10; // ebp
  float *v11; // ebx
  int v12; // edx
  unsigned __int8 *v13; // eax
  float *v14; // eax
  float *v15; // ebx
  float *v16; // ebp
  float *v17; // ebx
  bool v18; // zf
  int v19; // eax
  int i; // eax
  int v21; // eax
  int j; // eax
  int nFrontOut; // [esp+4h] [ebp-8Ch] BYREF
  unsigned int *pIndices; // [esp+8h] [ebp-88h] BYREF
  float *pFrontOut; // [esp+Ch] [ebp-84h]
  float *v26; // [esp+10h] [ebp-80h]
  float *v27; // [esp+14h] [ebp-7Ch]
  float *pVertices; // [esp+18h] [ebp-78h]
  float *pBackOut; // [esp+1Ch] [ebp-74h]
  float *ppVerts[3]; // [esp+20h] [ebp-70h] BYREF
  CUtlBuffer frontMeshVerts; // [esp+2Ch] [ebp-64h] BYREF
  CUtlBuffer backMeshVerts; // [esp+5Ch] [ebp-34h] BYREF

  v4 = inputMesh;
  if ( CMesh::FindFirstAttributeOffset(this: inputMesh, nType: VERTEX_ELEMENT_POSITION) != 0 )
    return 0;
  m_nIndexCount = inputMesh->m_nIndexCount;
  m_pVerts = inputMesh->m_pVerts;
  m_nVertexStrideFloats = inputMesh->m_nVertexStrideFloats;
  pFrontOut = (float *)inputMesh->m_pIndices;
  nFrontOut = m_nIndexCount;
  pBackOut = m_pVerts;
  v9 = 4 * m_nVertexStrideFloats;
  v10 = (float *)operator new(nSize: 16 * m_nVertexStrideFloats);
  ppVerts[0] = v10;
  v26 = (float *)operator new(nSize: 16 * m_nVertexStrideFloats);
  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&backMeshVerts.m_Memory.m_nAllocationCount,
    growSize: 0,
    initSize: 0,
    nFlags: 0);
  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&frontMeshVerts.m_Memory.m_nAllocationCount,
    growSize: 0,
    initSize: 0,
    nFlags: 0);
  if ( nFrontOut > 0 )
  {
    v11 = pFrontOut + 2;
    v27 = pFrontOut + 2;
    pFrontOut = (float *)((nFrontOut - 1) / 3u + 1);
    do
    {
      v12 = m_nVertexStrideFloats * *((_DWORD *)v11 - 1);
      ppVerts[1] = &pBackOut[m_nVertexStrideFloats * *((_DWORD *)v11 - 2)];
      v13 = (unsigned __int8 *)&pBackOut[m_nVertexStrideFloats * *(_DWORD *)v11];
      ppVerts[2] = &pBackOut[v12];
      frontMeshVerts.m_Memory.m_pMemory = v13;
      nFrontOut = 0;
      pIndices = nullptr;
      ClipTriangle(
        pBackOut: v10,
        pFrontOut: v26,
        pNumBackOut: &nFrontOut,
        pNumFrontOut: (int *)&pIndices,
        nStrideFloats: m_nVertexStrideFloats,
        ppVertsIn: &ppVerts[1],
        vClipPlane);
      v14 = (float *)(nFrontOut - 2);
      if ( nFrontOut - 2 > 0 )
      {
        nFrontOut = (int)&v10[2 * m_nVertexStrideFloats];
        v15 = &v10[v9 / 4];
        pVertices = v14;
        do
        {
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&backMeshVerts.m_Memory.m_nAllocationCount,
            pMem: v10,
            size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&backMeshVerts.m_Memory.m_nAllocationCount,
            pMem: v15,
            size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&backMeshVerts.m_Memory.m_nAllocationCount,
            pMem: (const void *)nFrontOut,
            size: 4 * m_nVertexStrideFloats);
          nFrontOut += v9;
          v15 = (float *)((char *)v15 + v9);
          pVertices = (float *)((char *)pVertices - 1);
        }
        while ( pVertices != nullptr );
        v11 = v27;
      }
      if ( (int)pIndices - 2 > 0 )
      {
        v16 = &v26[2 * m_nVertexStrideFloats];
        v17 = &v26[v9 / 4];
        pIndices = (unsigned int *)((char *)pIndices - 2);
        do
        {
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&frontMeshVerts.m_Memory.m_nAllocationCount,
            pMem: v26,
            size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&frontMeshVerts.m_Memory.m_nAllocationCount,
            pMem: v17,
            size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(
            this: (CUtlBuffer *)&frontMeshVerts.m_Memory.m_nAllocationCount,
            pMem: v16,
            size: 4 * m_nVertexStrideFloats);
          v17 = (float *)((char *)v17 + v9);
          v16 = (float *)((char *)v16 + v9);
          pIndices = (unsigned int *)((char *)pIndices - 1);
        }
        while ( pIndices != nullptr );
        v10 = ppVerts[0];
        v11 = v27;
      }
      v11 += 3;
      v18 = pFrontOut == (float *)1;
      pFrontOut = (float *)((char *)pFrontOut - 1);
      v27 = v11;
    }
    while ( !v18 );
    v4 = inputMesh;
  }
  free(pMem: v10);
  free(pMem: v26);
  if ( pMeshBack != nullptr )
  {
    v19 = *(_DWORD *)&backMeshVerts.m_Error / v9;
    v18 = *(_DWORD *)&backMeshVerts.m_Error / v9 == 0;
    pMeshBack->m_nVertexCount = *(_DWORD *)&backMeshVerts.m_Error / v9;
    if ( !v18 )
    {
      CMesh::AllocateMesh(
        this: pMeshBack,
        nVertexCount: v19,
        nIndexCount: v19,
        nVertexStride: m_nVertexStrideFloats,
        pAttributes: v4->m_pAttributes,
        nAtrributeCount: v4->m_nAttributeCount);
      memcpy(
        dst: (unsigned __int8 *)pMeshBack->m_pVerts,
        src: (unsigned __int8 *)backMeshVerts.m_Memory.m_nAllocationCount,
        count: *(unsigned int *)&backMeshVerts.m_Error);
      for ( i = 0; i < pMeshBack->m_nIndexCount; ++i )
        pMeshBack->m_pIndices[i] = i;
    }
  }
  if ( pMeshFront != nullptr )
  {
    v21 = *(_DWORD *)&frontMeshVerts.m_Error / v9;
    v18 = *(_DWORD *)&frontMeshVerts.m_Error / v9 == 0;
    pMeshFront->m_nVertexCount = *(_DWORD *)&frontMeshVerts.m_Error / v9;
    if ( !v18 )
    {
      CMesh::AllocateMesh(
        this: pMeshFront,
        nVertexCount: v21,
        nIndexCount: v21,
        nVertexStride: m_nVertexStrideFloats,
        pAttributes: v4->m_pAttributes,
        nAtrributeCount: v4->m_nAttributeCount);
      memcpy(
        dst: (unsigned __int8 *)pMeshFront->m_pVerts,
        src: (unsigned __int8 *)frontMeshVerts.m_Memory.m_nAllocationCount,
        count: *(unsigned int *)&frontMeshVerts.m_Error);
      for ( j = 0; j < pMeshFront->m_nIndexCount; ++j )
        pMeshFront->m_pIndices[j] = j;
    }
  }
  if ( frontMeshVerts.m_Get >= 0 )
  {
    if ( frontMeshVerts.m_Memory.m_nAllocationCount != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)frontMeshVerts.m_Memory.m_nAllocationCount);
      frontMeshVerts.m_Memory.m_nAllocationCount = 0;
    }
    frontMeshVerts.m_Memory.m_nGrowSize = 0;
  }
  if ( backMeshVerts.m_Get >= 0 && backMeshVerts.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)backMeshVerts.m_Memory.m_nAllocationCount);
  return 1;
}

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005769A0
// Name: void ClipTriangle(float __near *,float __near *,int __near *,int __near *,int,float __near * __near *,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipTriangle(
        float *pBackOut,
        float *pFrontOut,
        int *pNumBackOut,
        int *pNumFrontOut,
        int nStrideFloats,
        float **ppVertsIn,
        Vector4D *vClipPlane)
{
  int v8; // edi
  float *v9; // ecx
  float *v10; // eax
  float v11; // xmm0_4
  __int64 vPlaneNormal; // [esp+2Ch] [ebp-28h]
  float vPlaneNormal_8; // [esp+34h] [ebp-20h]
  int v14; // [esp+38h] [ebp-1Ch]
  float flDot1; // [esp+40h] [ebp-14h]
  float flDot2; // [esp+44h] [ebp-10h]
  int nFront; // [esp+48h] [ebp-Ch]
  int nBack; // [esp+4Ch] [ebp-8h]

  v8 = 0;
  nBack = 0;
  nFront = 0;
  vPlaneNormal = *(_QWORD *)&vClipPlane->x;
  vPlaneNormal_8 = vClipPlane->z;
  do
  {
    v14 = v8 + 1;
    v9 = ppVertsIn[v8];
    v10 = ppVertsIn[(v8 + 1) % 3];
    v11 = (float)((float)((float)(v9[1] * *((float *)&vPlaneNormal + 1)) + (float)(*(float *)&vPlaneNormal * *v9))
                + (float)(v9[2] * vPlaneNormal_8))
        + vClipPlane->w;
    flDot1 = v11;
    flDot2 = (float)((float)((float)(v10[1] * *((float *)&vPlaneNormal + 1)) + (float)(*v10 * *(float *)&vPlaneNormal))
                   + (float)(v10[2] * vPlaneNormal_8))
           + vClipPlane->w;
    if ( v11 == 0.0 )
    {
      v11 = 0.0099999998;
      flDot1 = 0.0099999998;
    }
    if ( (float)((float)((float)((float)(v10[1] * *((float *)&vPlaneNormal + 1))
                               + (float)(*v10 * *(float *)&vPlaneNormal))
                       + (float)(v10[2] * vPlaneNormal_8))
               + vClipPlane->w) == 0.0 )
      flDot2 = 0.0099999998;
    if ( v11 >= 0.0 )
    {
      CopyVertex(pOut: pFrontOut, pIn: v9, nFloats: nStrideFloats);
      ++nFront;
      pFrontOut += nStrideFloats;
    }
    else
    {
      CopyVertex(pOut: pBackOut, pIn: v9, nFloats: nStrideFloats);
      ++nBack;
      pBackOut += nStrideFloats;
    }
    if ( (float)(flDot2 * flDot1) < 0.0 )
    {
      LerpVertex(
        pOutput: pBackOut,
        pLeft: ppVertsIn[v8],
        pRight: ppVertsIn[(v8 + 1) % 3],
        flLerp: (float)(-1.0 / (float)(flDot2 - flDot1)) * flDot1,
        nFloats: nStrideFloats);
      CopyVertex(pOut: pFrontOut, pIn: pBackOut, nFloats: nStrideFloats);
      ++nBack;
      ++nFront;
      pBackOut += nStrideFloats;
      pFrontOut += nStrideFloats;
    }
    ++v8;
  }
  while ( v14 < 3 );
  *pNumBackOut = nBack;
  *pNumFrontOut = nFront;
}

//------------------------------------------------------------------------------
// Address: 0x00576B70
// Name: bool ClipMeshToHalfSpace(class CMesh __near *,class CMesh __near *,class CMesh const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipMeshToHalfSpace(CMesh *pMeshBack, CMesh *pMeshFront, CMesh *inputMesh, Vector4D *vClipPlane)
{
  int m_nIndexCount; // eax
  float *m_pVerts; // edx
  int m_nVertexStrideFloats; // edi
  unsigned int v8; // esi
  float *v9; // ebx
  _DWORD *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  unsigned __int8 *v14; // ebx
  int v15; // eax
  int i; // eax
  int v17; // eax
  int j; // eax
  CUtlBuffer backMeshVerts; // [esp+4h] [ebp-90h] BYREF
  CUtlBuffer frontMeshVerts; // [esp+34h] [ebp-60h] BYREF
  float *ppVerts[3]; // [esp+64h] [ebp-30h] BYREF
  float *pBackOut; // [esp+70h] [ebp-24h]
  float *pVertices; // [esp+74h] [ebp-20h]
  int v24; // [esp+78h] [ebp-1Ch]
  void *pMem; // [esp+7Ch] [ebp-18h]
  int v26; // [esp+80h] [ebp-14h]
  float *pFrontOut; // [esp+84h] [ebp-10h]
  int nIndexCount; // [esp+88h] [ebp-Ch]
  int nFrontOut; // [esp+8Ch] [ebp-8h] BYREF
  int nBackOut; // [esp+90h] [ebp-4h] BYREF

  if ( CMesh::FindFirstAttributeOffset(this: inputMesh, nType: VERTEX_ELEMENT_POSITION) != 0 )
    return 0;
  m_nIndexCount = inputMesh->m_nIndexCount;
  m_pVerts = inputMesh->m_pVerts;
  m_nVertexStrideFloats = inputMesh->m_nVertexStrideFloats;
  nFrontOut = (int)inputMesh->m_pIndices;
  nIndexCount = m_nIndexCount;
  pVertices = m_pVerts;
  v8 = 4 * m_nVertexStrideFloats;
  v9 = (float *)MemAlloc_Alloc(
                  nSize: (unsigned __int64)(unsigned int)(4 * m_nVertexStrideFloats) >> 30 != 0
                ? -1
                : 16 * m_nVertexStrideFloats);
  pBackOut = v9;
  pFrontOut = (float *)MemAlloc_Alloc(
                         nSize: (unsigned __int64)(unsigned int)(4 * m_nVertexStrideFloats) >> 30 != 0
                       ? -1
                       : 16 * m_nVertexStrideFloats);
  CUtlBuffer::CUtlBuffer(this: &backMeshVerts, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &frontMeshVerts, growSize: 0, initSize: 0, nFlags: 0);
  if ( nIndexCount > 0 )
  {
    v10 = (_DWORD *)(nFrontOut + 8);
    v26 = nFrontOut + 8;
    nIndexCount = (nIndexCount - 1) / 3u + 1;
    while ( 1 )
    {
      ppVerts[0] = &pVertices[m_nVertexStrideFloats * *(v10 - 2)];
      v11 = *(v10 - 1);
      v12 = m_nVertexStrideFloats * *v10;
      ppVerts[1] = &pVertices[m_nVertexStrideFloats * v11];
      nBackOut = 0;
      nFrontOut = 0;
      ppVerts[2] = &pVertices[v12];
      ClipTriangle(
        pBackOut: v9,
        pFrontOut,
        pNumBackOut: &nBackOut,
        pNumFrontOut: &nFrontOut,
        nStrideFloats: m_nVertexStrideFloats,
        ppVertsIn: ppVerts,
        vClipPlane);
      v13 = nBackOut - 2;
      if ( nBackOut - 2 > 0 )
      {
        nBackOut = (int)&v9[2 * m_nVertexStrideFloats];
        pMem = &v9[v8 / 4];
        v24 = v13;
        do
        {
          CUtlBuffer::Put(this: &backMeshVerts, pMem: (unsigned __int8 *)v9, size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(this: &backMeshVerts, (unsigned __int8 *)pMem, size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(this: &backMeshVerts, pMem: (unsigned __int8 *)nBackOut, size: 4 * m_nVertexStrideFloats);
          pMem = (char *)pMem + v8;
          nBackOut += v8;
          --v24;
        }
        while ( v24 != 0 );
      }
      if ( nFrontOut - 2 > 0 )
      {
        nBackOut = (int)&pFrontOut[2 * m_nVertexStrideFloats];
        v14 = (unsigned __int8 *)&pFrontOut[v8 / 4];
        nFrontOut -= 2;
        do
        {
          CUtlBuffer::Put(this: &frontMeshVerts, pMem: (unsigned __int8 *)pFrontOut, size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(this: &frontMeshVerts, pMem: v14, size: 4 * m_nVertexStrideFloats);
          CUtlBuffer::Put(this: &frontMeshVerts, pMem: (unsigned __int8 *)nBackOut, size: 4 * m_nVertexStrideFloats);
          nBackOut += v8;
          v14 += v8;
          --nFrontOut;
        }
        while ( nFrontOut != 0 );
        v9 = pBackOut;
      }
      v26 += 12;
      if ( --nIndexCount == 0 )
        break;
      v10 = (_DWORD *)v26;
    }
  }
  free(pMem: v9);
  free(pMem: pFrontOut);
  if ( pMeshBack != nullptr )
  {
    v15 = backMeshVerts.m_Put / v8;
    pMeshBack->m_nVertexCount = backMeshVerts.m_Put / v8;
    if ( v15 != 0 )
    {
      CMesh::AllocateMesh(
        this: pMeshBack,
        nVertexCount: v15,
        nIndexCount: v15,
        nVertexStride: m_nVertexStrideFloats,
        pAttributes: inputMesh->m_pAttributes,
        nAtrributeCount: inputMesh->m_nAttributeCount);
      _V_memcpy(dest: pMeshBack->m_pVerts, src: backMeshVerts.m_Memory.m_pMemory, count: backMeshVerts.m_Put);
      for ( i = 0; i < pMeshBack->m_nIndexCount; ++i )
        pMeshBack->m_pIndices[i] = i;
    }
  }
  if ( pMeshFront != nullptr )
  {
    v17 = frontMeshVerts.m_Put / v8;
    pMeshFront->m_nVertexCount = frontMeshVerts.m_Put / v8;
    if ( v17 != 0 )
    {
      CMesh::AllocateMesh(
        this: pMeshFront,
        nVertexCount: v17,
        nIndexCount: v17,
        nVertexStride: m_nVertexStrideFloats,
        pAttributes: inputMesh->m_pAttributes,
        nAtrributeCount: inputMesh->m_nAttributeCount);
      _V_memcpy(dest: pMeshFront->m_pVerts, src: frontMeshVerts.m_Memory.m_pMemory, count: frontMeshVerts.m_Put);
      for ( j = 0; j < pMeshFront->m_nIndexCount; ++j )
        pMeshFront->m_pIndices[j] = j;
    }
  }
  if ( frontMeshVerts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( frontMeshVerts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: frontMeshVerts.m_Memory.m_pMemory);
      frontMeshVerts.m_Memory.m_pMemory = nullptr;
    }
    frontMeshVerts.m_Memory.m_nAllocationCount = 0;
  }
  if ( backMeshVerts.m_Memory.m_nGrowSize >= 0 && backMeshVerts.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: backMeshVerts.m_Memory.m_pMemory);
  return 1;
}

} // namespace vmap
