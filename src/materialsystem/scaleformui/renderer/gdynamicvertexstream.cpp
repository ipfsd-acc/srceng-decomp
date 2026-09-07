// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/renderer/gdynamicvertexstream.cpp
// Functions: 14
// ============================================================

#include "materialsystem\scaleformui\renderer\gdynamicvertexstream.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: void GDynamicVertexStream::SetVertexData(void const __near *,int,enum GRenderer::VertexFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::SetVertexData(
        GDynamicVertexStream *this,
        const void *pVertices,
        unsigned int numVertices,
        GRenderer::VertexFormat vf)
{
  this->m_pVertexData = pVertices;
  this->m_vertexCount = numVertices;
  this->m_vertexFmt = vf;
  this->m_VBDataInBuffer = false;
  this->m_vertexSize = 4;
  if ( vf != Vertex_None )
  {
    if ( vf == Vertex_XY16iC32 )
    {
      this->m_vertexSize = 8;
    }
    else if ( vf == Vertex_XY16iCF32 )
    {
      this->m_vertexSize = 12;
    }
  }
  else
  {
    this->m_vertexSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: public: void GDynamicVertexStream::SetIndexData(void const __near *,int,enum GRenderer::IndexFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::SetIndexData(
        GDynamicVertexStream *this,
        const void *pIndices,
        unsigned int numIndices,
        GRenderer::IndexFormat idxf)
{
  this->m_pIndexData = pIndices;
  this->m_indexCount = numIndices;
  this->m_IBDataInBuffer = false;
  if ( idxf != Index_None )
  {
    if ( idxf == Index_16 )
    {
      this->m_indexFmt = D3DFMT_INDEX16;
    }
    else if ( idxf == Index_32 )
    {
      this->m_indexFmt = D3DFMT_INDEX32;
    }
  }
  else
  {
    this->m_indexFmt = D3DFMT_UNKNOWN;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: private: void GDynamicVertexStream::InitVerticesFromIndex(void __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::InitVerticesFromIndex(
        GDynamicVertexStream *this,
        char *pvertexDest,
        int baseVertexIndex,
        unsigned int vertexSize,
        unsigned __int8 *startIndex,
        int triangleCount)
{
  char *v6; // edi
  unsigned __int16 *v7; // esi
  int v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // ecx
  _DWORD *v13; // eax
  unsigned __int8 *pDest; // [esp+20h] [ebp+14h]

  v6 = (char *)this->m_pVertexData + vertexSize * baseVertexIndex;
  v7 = (unsigned __int16 *)((char *)this->m_pIndexData + 2 * (_DWORD)startIndex);
  pDest = (unsigned __int8 *)pvertexDest;
  switch ( vertexSize )
  {
    case 4u:
      v12 = triangleCount;
      if ( triangleCount > 0 )
      {
        v13 = pvertexDest + 8;
        do
        {
          *(v13 - 2) = *(_DWORD *)&v6[4 * *v7];
          *(v13 - 1) = *(_DWORD *)&v6[4 * v7[1]];
          *v13 = *(_DWORD *)&v6[4 * v7[2]];
          v7 += 3;
          v13 += 3;
          --v12;
        }
        while ( v12 != 0 );
      }
      break;
    case 8u:
      v10 = triangleCount;
      if ( triangleCount > 0 )
      {
        v11 = pvertexDest + 8;
        do
        {
          *(v11 - 2) = *(_DWORD *)&v6[8 * *v7];
          *(v11 - 1) = *(_DWORD *)&v6[8 * *v7 + 4];
          *v11 = *(_DWORD *)&v6[8 * v7[1]];
          v11[1] = *(_DWORD *)&v6[8 * v7[1] + 4];
          v11[2] = *(_DWORD *)&v6[8 * v7[2]];
          v11[3] = *(_DWORD *)&v6[8 * v7[2] + 4];
          v7 += 3;
          v11 += 6;
          --v10;
        }
        while ( v10 != 0 );
      }
      break;
    case 0xCu:
      v8 = triangleCount;
      if ( triangleCount > 0 )
      {
        v9 = pvertexDest + 8;
        do
        {
          *(v9 - 2) = *(_DWORD *)&v6[12 * *v7];
          *(v9 - 1) = *(_DWORD *)&v6[12 * *v7 + 4];
          *v9 = *(_DWORD *)&v6[12 * *v7 + 8];
          v9[1] = *(_DWORD *)&v6[12 * v7[1]];
          v9[2] = *(_DWORD *)&v6[12 * v7[1] + 4];
          v9[3] = *(_DWORD *)&v6[12 * v7[1] + 8];
          v9[4] = *(_DWORD *)&v6[12 * v7[2]];
          v9[5] = *(_DWORD *)&v6[12 * v7[2] + 4];
          v9[6] = *(_DWORD *)&v6[12 * v7[2] + 8];
          v7 += 3;
          v9 += 9;
          --v8;
        }
        while ( v8 != 0 );
      }
      break;
    default:
      if ( triangleCount > 0 )
      {
        do
        {
          memcpy(dst: pDest, src: (unsigned __int8 *)&v6[vertexSize * *v7], count: vertexSize);
          memcpy(dst: pDest, src: (unsigned __int8 *)&v6[vertexSize * v7[1]], count: vertexSize);
          memcpy(dst: pDest, src: (unsigned __int8 *)&v6[vertexSize * v7[2]], count: vertexSize);
          pDest += 3 * vertexSize;
          v7 += 3;
          --triangleCount;
        }
        while ( triangleCount != 0 );
      }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: GDynamicVertexStream::GDynamicVertexStream(void)
// Source: json
//------------------------------------------------------------------------------
GDynamicVertexStream *__thiscall GDynamicVertexStream::GDynamicVertexStream(GDynamicVertexStream *this)
{
  this->m_pVertexBuffer.pObject = nullptr;
  this->m_pIndexBuffer.pObject = nullptr;
  this->m_primitive.m_baseVertexIndex = 0;
  this->m_primitive.m_minVertexIndex = 0;
  this->m_primitive.m_numVertices = 0;
  this->m_primitive.m_startIndex = 0;
  this->m_primitive.m_triangleCount = 0;
  this->m_pDevice = nullptr;
  this->m_lostDevice = false;
  this->m_pVertexData = nullptr;
  this->m_pIndexData = nullptr;
  this->m_indexFmt = D3DFMT_UNKNOWN;
  this->m_vertexFmt = Vertex_None;
  this->m_vertexCount = 0;
  this->m_indexCount = 0;
  this->m_nextIBOffset = 0;
  this->m_nextVBOffset = 0;
  *(_WORD *)&this->m_VBDataInBuffer = 0;
  this->m_VBDataOffset = 0;
  this->m_IBDataOffset = 0;
  this->m_VBDataIndex = 0;
  this->m_pTempVertexBuffer = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: private: bool GDynamicVertexStream::CreateDynamicBuffers(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDynamicVertexStream::CreateDynamicBuffers(GDynamicVertexStream *this)
{
  bool v2; // zf
  GPtr<IDirect3DVertexBuffer9> *p_m_pVertexBuffer; // ebx
  unsigned int m_vertexBufferSize; // eax
  unsigned int m_indexBufferSize; // eax

  v2 = this->m_pVertexBuffer.pObject == nullptr;
  p_m_pVertexBuffer = &this->m_pVertexBuffer;
  this->m_vertexBufferSize = 786432;
  this->m_indexBufferSize = 196608;
  if ( v2 )
  {
    while ( this->m_pDevice->CreateVertexBuffer(
              this: this->m_pDevice,
              a2: this->m_vertexBufferSize,
              a3: 520u,
              a4: 0,
              a5: D3DPOOL_DEFAULT,
              a6: (IDirect3DVertexBuffer9 **)p_m_pVertexBuffer,
              a7: nullptr) < 0 )
    {
      m_vertexBufferSize = this->m_vertexBufferSize;
      if ( m_vertexBufferSize <= 0x18000 )
      {
        this->m_vertexBufferSize = 0;
        return 0;
      }
      this->m_vertexBufferSize = m_vertexBufferSize >> 1;
    }
  }
  if ( this->m_pIndexBuffer.pObject == nullptr )
  {
    while ( this->m_pDevice->CreateIndexBuffer(
              this: this->m_pDevice,
              a2: this->m_indexBufferSize,
              a3: 520u,
              a4: D3DFMT_INDEX16,
              a5: D3DPOOL_DEFAULT,
              a6: (IDirect3DIndexBuffer9 **)&this->m_pIndexBuffer,
              a7: nullptr) < 0 )
    {
      m_indexBufferSize = this->m_indexBufferSize;
      if ( m_indexBufferSize <= 0xC000 )
      {
        if ( p_m_pVertexBuffer->pObject != nullptr )
          p_m_pVertexBuffer->pObject->Release(this: p_m_pVertexBuffer->pObject);
        p_m_pVertexBuffer->pObject = nullptr;
        this->m_indexBufferSize = 0;
        this->m_vertexBufferSize = 0;
        return 0;
      }
      this->m_indexBufferSize = m_indexBufferSize >> 1;
    }
  }
  this->m_nextIBOffset = 0;
  *(_WORD *)&this->m_VBDataInBuffer = 0;
  this->m_VBDataOffset = 0;
  this->m_IBDataOffset = 0;
  this->m_vertexSizeInBuffer = 0;
  this->m_renderMethod = RM_None;
  this->m_maxTriangleCount = 0;
  this->m_lostDevice = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: public: void GDynamicVertexStream::ReleaseDynamicBuffers(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::ReleaseDynamicBuffers(GDynamicVertexStream *this, bool lostDevice)
{
  IDirect3DVertexBuffer9 *pObject; // eax
  IDirect3DIndexBuffer9 *v4; // eax

  pObject = this->m_pVertexBuffer.pObject;
  if ( pObject != nullptr )
    pObject->Release(this: pObject);
  this->m_pVertexBuffer.pObject = nullptr;
  v4 = this->m_pIndexBuffer.pObject;
  if ( v4 != nullptr )
    v4->Release(this: this->m_pIndexBuffer.pObject);
  this->m_pIndexBuffer.pObject = nullptr;
  this->m_vertexBufferSize = 0;
  this->m_indexBufferSize = 0;
  this->m_renderMethod = RM_None;
  this->m_maxTriangleCount = 0;
  this->m_lostDevice = lostDevice;
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: void __near * GDynamicVertexStream::LockVertexBuffer(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GDynamicVertexStream::LockVertexBuffer(
        GDynamicVertexStream *this,
        unsigned int vertexCount,
        unsigned int vertexSize)
{
  void *result; // eax
  unsigned int m_vertexBufferSize; // eax
  unsigned int v6; // edi
  unsigned int m_nextVBOffset; // ebx
  void *pBuffer; // [esp+4h] [ebp-4h] BYREF
  unsigned int lockFlags; // [esp+10h] [ebp+8h]

  if ( this->m_lostDevice )
    return nullptr;
  m_vertexBufferSize = this->m_vertexBufferSize;
  v6 = vertexSize * vertexCount;
  if ( vertexSize * vertexCount > m_vertexBufferSize || this->m_pVertexBuffer.pObject == nullptr )
    return nullptr;
  m_nextVBOffset = this->m_nextVBOffset;
  pBuffer = nullptr;
  this->m_VBDataInBuffer = false;
  if ( vertexSize + m_nextVBOffset + v6 >= m_vertexBufferSize )
  {
    m_nextVBOffset = 0;
    this->m_nextVBOffset = v6;
    lockFlags = 0x2000;
  }
  else
  {
    this->m_nextVBOffset = m_nextVBOffset + v6;
    lockFlags = 4096;
  }
  this->m_pDevice->SetStreamSource(this: this->m_pDevice, a2: 0, a3: nullptr, a4: 0, a5: 0);
  if ( this->m_pVertexBuffer.pObject->Lock(
         this: this->m_pVertexBuffer.pObject,
         a2: m_nextVBOffset,
         a3: v6,
         a4: &pBuffer,
         a5: lockFlags) < 0 )
    return nullptr;
  result = pBuffer;
  this->m_VBDataOffset = m_nextVBOffset;
  this->m_vertexSizeInBuffer = vertexSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: void GDynamicVertexStream::UnlockVertexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::UnlockVertexBuffer(GDynamicVertexStream *this)
{
  this->m_pVertexBuffer.pObject->Unlock(this: this->m_pVertexBuffer.pObject);
  this->m_pDevice->SetStreamSource(
    this: this->m_pDevice,
    a2: 0,
    a3: this->m_pVertexBuffer.pObject,
    a4: this->m_VBDataOffset,
    a5: this->m_vertexSizeInBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: void __near * GDynamicVertexStream::LockIndexBuffer(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GDynamicVertexStream::LockIndexBuffer(
        GDynamicVertexStream *this,
        unsigned int indexCount,
        void *indexSize)
{
  void *result; // eax
  unsigned int m_indexBufferSize; // ecx
  unsigned int v6; // edi
  unsigned int m_nextIBOffset; // eax
  unsigned int v8; // ebx
  unsigned int lockFlags; // [esp+Ch] [ebp+8h]

  if ( this->m_lostDevice )
    return nullptr;
  m_indexBufferSize = this->m_indexBufferSize;
  v6 = (_DWORD)indexSize * indexCount;
  if ( (unsigned int)indexSize * indexCount > m_indexBufferSize || this->m_pIndexBuffer.pObject == nullptr )
    return nullptr;
  m_nextIBOffset = this->m_nextIBOffset;
  indexSize = nullptr;
  this->m_IBDataInBuffer = false;
  if ( m_indexBufferSize - m_nextIBOffset <= v6 )
  {
    v8 = 0;
    this->m_nextIBOffset = v6;
    lockFlags = 0x2000;
  }
  else
  {
    v8 = m_nextIBOffset;
    this->m_nextIBOffset = v6 + m_nextIBOffset;
    lockFlags = 4096;
  }
  this->m_pDevice->SetIndices(this: this->m_pDevice, a2: nullptr);
  if ( this->m_pIndexBuffer.pObject->Lock(
         this: this->m_pIndexBuffer.pObject,
         a2: v8,
         a3: v6,
         a4: &indexSize,
         a5: lockFlags) < 0 )
    return nullptr;
  result = indexSize;
  this->m_IBDataOffset = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: public: void GDynamicVertexStream::UnlockIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::UnlockIndexBuffer(GDynamicVertexStream *this)
{
  this->m_pIndexBuffer.pObject->Unlock(this: this->m_pIndexBuffer.pObject);
  this->m_pDevice->SetIndices(this: this->m_pDevice, a2: this->m_pIndexBuffer.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100015A0
// Name: public: void GDynamicVertexStream::BeginDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::BeginDisplay(GDynamicVertexStream *this)
{
  if ( this->m_lostDevice )
    GDynamicVertexStream::CreateDynamicBuffers(this);
  this->m_pDevice->SetStreamSourceFreq(this: this->m_pDevice, a2: 0, a3: 1u);
  this->m_pDevice->SetIndices(this: this->m_pDevice, a2: this->m_pIndexBuffer.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: GDynamicVertexStream::~GDynamicVertexStream(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::~GDynamicVertexStream(GDynamicVertexStream *this)
{
  IDirect3DVertexBuffer9 *pObject; // eax
  IDirect3DIndexBuffer9 *v3; // eax
  unsigned __int8 *m_pTempVertexBuffer; // eax
  IDirect3DIndexBuffer9 *v5; // eax
  IDirect3DVertexBuffer9 *v6; // esi

  pObject = this->m_pVertexBuffer.pObject;
  if ( pObject != nullptr )
    pObject->Release(this: pObject);
  this->m_pVertexBuffer.pObject = nullptr;
  v3 = this->m_pIndexBuffer.pObject;
  if ( v3 != nullptr )
    v3->Release(this: this->m_pIndexBuffer.pObject);
  this->m_pIndexBuffer.pObject = nullptr;
  m_pTempVertexBuffer = this->m_pTempVertexBuffer;
  this->m_vertexBufferSize = 0;
  this->m_indexBufferSize = 0;
  this->m_renderMethod = RM_None;
  this->m_maxTriangleCount = 0;
  this->m_lostDevice = false;
  if ( m_pTempVertexBuffer != nullptr )
    free(pMem: m_pTempVertexBuffer);
  v5 = this->m_pIndexBuffer.pObject;
  if ( v5 != nullptr )
    v5->Release(this: v5);
  v6 = this->m_pVertexBuffer.pObject;
  if ( v6 != nullptr )
    v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10001690
// Name: public: bool GDynamicVertexStream::PrepareVertexData(struct GDynamicVertexStream::PrimitiveDesc const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDynamicVertexStream::PrepareVertexData(
        GDynamicVertexStream *this,
        const GDynamicVertexStream::PrimitiveDesc *prim)
{
  unsigned int m_vertexCount; // edx
  unsigned int v5; // eax
  unsigned int m_vertexSize; // ecx
  unsigned int m_vertexBufferSize; // eax
  unsigned __int8 *v8; // eax
  unsigned int m_indexBufferSize; // eax
  int v10; // edi
  unsigned __int8 *v11; // eax

  if ( this->m_lostDevice )
    return 0;
  m_vertexCount = this->m_vertexCount;
  this->m_primitive = *prim;
  if ( m_vertexCount < 0x20 )
  {
    v5 = this->m_vertexBufferSize / (3 * this->m_vertexSize);
    this->m_renderMethod = RM_NotIndexed;
    this->m_maxTriangleCount = v5;
    return 1;
  }
  if ( !this->m_VBDataInBuffer )
  {
    m_vertexSize = this->m_vertexSize;
    m_vertexBufferSize = this->m_vertexBufferSize;
    if ( m_vertexCount * this->m_vertexSize > m_vertexBufferSize )
    {
      this->m_renderMethod = RM_NotIndexed;
      this->m_maxTriangleCount = m_vertexBufferSize / (3 * m_vertexSize);
      return 1;
    }
    v8 = (unsigned __int8 *)GDynamicVertexStream::LockVertexBuffer(
                              this,
                              vertexCount: m_vertexCount,
                              vertexSize: this->m_vertexSize);
    if ( v8 == nullptr )
      goto LABEL_16;
    memcpy(dst: v8, src: (unsigned __int8 *)this->m_pVertexData, count: this->m_vertexSize * this->m_vertexCount);
    GDynamicVertexStream::UnlockVertexBuffer(this);
    this->m_VBDataInBuffer = true;
  }
  if ( this->m_IBDataInBuffer )
  {
LABEL_15:
    this->m_renderMethod = RM_Indexed;
    return 1;
  }
  m_indexBufferSize = this->m_indexBufferSize;
  v10 = 2 * (this->m_indexFmt != D3DFMT_INDEX16) + 2;
  if ( v10 * this->m_indexCount > m_indexBufferSize )
  {
    this->m_renderMethod = RM_IndexedInChunks;
    this->m_maxTriangleCount = m_indexBufferSize / (3 * v10);
    return 1;
  }
  v11 = (unsigned __int8 *)GDynamicVertexStream::LockIndexBuffer(
                             this,
                             indexCount: this->m_indexCount,
                             indexSize: (void *)(2 * (this->m_indexFmt != D3DFMT_INDEX16) + 2));
  if ( v11 != nullptr )
  {
    memcpy(dst: v11, src: (unsigned __int8 *)this->m_pIndexData, count: v10 * this->m_indexCount);
    GDynamicVertexStream::UnlockIndexBuffer(this);
    this->m_IBDataInBuffer = true;
    goto LABEL_15;
  }
LABEL_16:
  this->m_renderMethod = RM_None;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100017D0
// Name: public: void GDynamicVertexStream::DrawTriangles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDynamicVertexStream::DrawTriangles(GDynamicVertexStream *this)
{
  GDynamicVertexStream::RenderMethodType m_renderMethod; // eax
  int v3; // edi
  int v4; // ebx
  int i; // ebx
  signed int m_maxTriangleCount; // edi
  unsigned __int8 *v7; // eax
  unsigned int indexSize; // [esp+4h] [ebp-4h]

  m_renderMethod = this->m_renderMethod;
  switch ( m_renderMethod )
  {
    case RM_Indexed:
      this->m_pDevice->DrawIndexedPrimitive(
        this: this->m_pDevice,
        a2: D3DPT_TRIANGLELIST,
        a3: this->m_primitive.m_baseVertexIndex,
        a4: this->m_primitive.m_minVertexIndex,
        a5: this->m_primitive.m_numVertices,
        a6: this->m_primitive.m_startIndex + (this->m_IBDataOffset >> 1),
        a7: this->m_primitive.m_triangleCount);
      break;
    case RM_NotIndexed:
      v3 = 0;
      if ( this->m_pTempVertexBuffer == nullptr )
        this->m_pTempVertexBuffer = (unsigned __int8 *)MemAlloc_Alloc(nSize: 6144 * this->m_vertexSize);
      if ( this->m_primitive.m_triangleCount > 0 )
      {
        do
        {
          v4 = this->m_primitive.m_triangleCount - v3;
          if ( v4 >= 2048 )
            v4 = 2048;
          GDynamicVertexStream::InitVerticesFromIndex(
            this,
            pvertexDest: (char *)this->m_pTempVertexBuffer,
            baseVertexIndex: this->m_primitive.m_baseVertexIndex,
            vertexSize: this->m_vertexSize,
            startIndex: (unsigned __int8 *)(this->m_primitive.m_startIndex + 3 * v3),
            triangleCount: v4);
          this->m_pDevice->DrawPrimitiveUP(
            this: this->m_pDevice,
            a2: D3DPT_TRIANGLELIST,
            a3: v4,
            a4: this->m_pTempVertexBuffer,
            a5: this->m_vertexSize);
          v3 += v4;
        }
        while ( v3 < this->m_primitive.m_triangleCount );
      }
      break;
    case RM_IndexedInChunks:
      for ( i = 0; i < this->m_primitive.m_triangleCount; i += m_maxTriangleCount )
      {
        m_maxTriangleCount = this->m_maxTriangleCount;
        if ( this->m_primitive.m_triangleCount - i < m_maxTriangleCount )
          m_maxTriangleCount = this->m_primitive.m_triangleCount - i;
        indexSize = 2 * (this->m_indexFmt != D3DFMT_INDEX16) + 2;
        v7 = (unsigned __int8 *)GDynamicVertexStream::LockIndexBuffer(
                                  this,
                                  indexCount: 3 * m_maxTriangleCount,
                                  (void *)indexSize);
        if ( v7 == nullptr )
          break;
        memcpy(
          dst: v7,
          src: (unsigned __int8 *)this->m_pIndexData + indexSize * (this->m_primitive.m_startIndex + 3 * i),
          count: 3 * m_maxTriangleCount * indexSize);
        this->m_pIndexBuffer.pObject->Unlock(this: this->m_pIndexBuffer.pObject);
        this->m_pDevice->SetIndices(this: this->m_pDevice, a2: this->m_pIndexBuffer.pObject);
        this->m_pDevice->DrawIndexedPrimitive(
          this: this->m_pDevice,
          a2: D3DPT_TRIANGLELIST,
          a3: this->m_primitive.m_baseVertexIndex,
          a4: this->m_primitive.m_minVertexIndex,
          a5: this->m_primitive.m_numVertices,
          a6: this->m_IBDataOffset >> 1,
          a7: m_maxTriangleCount);
      }
      break;
    default:
      break;
  }
}
