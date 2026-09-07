// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/subdbaker/subdmesh.cpp
// Functions: 137
// ============================================================

#include "utils\subdbaker\subdmesh.h"

//------------------------------------------------------------------------------
// Address: 0x00402560
// Name: public: int CUtlVector<struct OptimizedModel::Orientation,class CUtlMemory<struct OptimizedModel::Orientation,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int>>::InsertMultipleBefore(
        CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  OptimizedModel::Orientation *m_pMemory; // ecx
  int v8; // eax
  int i; // ecx
  OptimizedModel::Orientation *v10; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v8);
  for ( i = 0; i < num; ++i )
  {
    v10 = &this->m_Memory.m_pMemory[i + elem];
    if ( v10 != nullptr )
      *(_BYTE *)v10 &= 0xF3u;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00408700
// Name: public: bool CUtlVector<class CScheduleQueue __near *,class CUtlMemory<class CScheduleQueue __near *,int>>::FindAndRemove(class CScheduleQueue __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int>>::FindAndRemove(
        CUtlVector<CScheduleQueue *,CUtlMemory<CScheduleQueue *,int> > *this,
        CScheduleQueue **src)
{
  int m_Size; // edx
  int v4; // eax
  CScheduleQueue **m_pMemory; // ebx
  CScheduleQueue **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040D530
// Name: public: void CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>::Grow(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)_realloc_crt(
                                                                  ptr: m_pMemory,
                                                                  size: 20 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)operator new(nSize: 20 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D5D0
// Name: public: void CUtlMemory<class Vector,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<Vector,int>::Grow(CUtlMemory<Vector,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  Vector *m_pMemory; // ecx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (Vector *)_realloc_crt(ptr: m_pMemory, size: 12 * m_nAllocationCount);
    else
      this->m_pMemory = (Vector *)operator new(nSize: 12 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E7E0
// Name: public: CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::~CUtlVector<class Vector,class CUtlMemory<class Vector,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::~CUtlVector<Vector,CUtlMemory<Vector,int>>(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this)
{
  bool v2; // sf
  Vector *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F3E0
// Name: public: int CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00411340
// Name: public: void CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  int v1; // edi
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          free(pMem: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          free(pMem: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413830
// Name: public: CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>::~CUtlVector<class CUtlVector<int,class CUtlMemory<int,int>>,class CUtlMemory<class CUtlVector<int,class CUtlMemory<int,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::~CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419100
// Name: public: CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::~CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::~CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this)
{
  int i; // edi
  int j; // edi
  CacheOptimizedTriangle **m_pMemory; // [esp-4h] [ebp-10h]
  CacheOptimizedTriangle **v5; // [esp-4h] [ebp-10h]

  this->m_Size = 0;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_Memory.m_nBlocks; ++i )
      free(pMem: this->m_Memory.m_pMemory[i]);
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
  this->m_pElements = nullptr;
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    for ( j = 0; j < this->m_Memory.m_nBlocks; ++j )
      free(pMem: this->m_Memory.m_pMemory[j]);
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nBlocks = 0;
    free(pMem: v5);
    this->m_Memory.m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AF40
// Name: private: void CSubDMesh::DestroyRenderData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::DestroyRenderData(CSubDMesh *this)
{
  IDirect3DVertexBuffer9 *m_pPatchRenderBuffer; // eax
  IDirect3DTexture9 *m_pPatchUVandIDRT; // eax
  IDirect3DTexture9 *m_pPatchTanURT; // eax
  IDirect3DVertexDeclaration9 *m_pPRBDecl; // eax
  IDirect3DVertexShader9 *m_pVS; // eax
  IDirect3DPixelShader9 *m_pPS; // eax

  m_pPatchRenderBuffer = this->m_pPatchRenderBuffer;
  if ( m_pPatchRenderBuffer != nullptr )
  {
    m_pPatchRenderBuffer->Release(this: m_pPatchRenderBuffer);
    this->m_pPatchRenderBuffer = nullptr;
  }
  m_pPatchUVandIDRT = this->m_pPatchUVandIDRT;
  if ( m_pPatchUVandIDRT != nullptr )
  {
    m_pPatchUVandIDRT->Release(this: this->m_pPatchUVandIDRT);
    this->m_pPatchUVandIDRT = nullptr;
  }
  m_pPatchTanURT = this->m_pPatchTanURT;
  if ( m_pPatchTanURT != nullptr )
  {
    m_pPatchTanURT->Release(this: this->m_pPatchTanURT);
    this->m_pPatchTanURT = nullptr;
  }
  m_pPRBDecl = this->m_pPRBDecl;
  if ( m_pPRBDecl != nullptr )
  {
    m_pPRBDecl->Release(this: this->m_pPRBDecl);
    this->m_pPRBDecl = nullptr;
  }
  m_pVS = this->m_pVS;
  if ( m_pVS != nullptr )
  {
    m_pVS->Release(this: this->m_pVS);
    this->m_pVS = nullptr;
  }
  m_pPS = this->m_pPS;
  if ( m_pPS != nullptr )
  {
    m_pPS->Release(this: this->m_pPS);
    this->m_pPS = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AFE0
// Name: private: bool CSubDMesh::CreateUVandIDTexture(struct IDirect3DDevice9 __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSubDMesh::CreateUVandIDTexture(
        CSubDMesh *this,
        IDirect3DDevice9 *pd3dDevice,
        unsigned int Width,
        unsigned int Height)
{
  return pd3dDevice->CreateTexture(
           this: pd3dDevice,
           a2: Width,
           a3: Height,
           a4: 1u,
           a5: 1u,
           a6: D3DFMT_A32B32G32R32F,
           a7: D3DPOOL_DEFAULT,
           a8: &this->m_pPatchUVandIDRT,
           a9: nullptr) >= 0
      && pd3dDevice->CreateTexture(
           this: pd3dDevice,
           a2: Width,
           a3: Height,
           a4: 1u,
           a5: 1u,
           a6: D3DFMT_A32B32G32R32F,
           a7: D3DPOOL_DEFAULT,
           a8: &this->m_pPatchTanURT,
           a9: nullptr) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B050
// Name: private: bool CSubDMesh::CompileShaders(struct IDirect3DDevice9 __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSubDMesh::CompileShaders(CSubDMesh *this, IDirect3DDevice9 *pd3dDevice)
{
  const char *v3; // eax
  const char *v5; // eax
  IDirect3DDevice9_vtbl *v6; // edi
  int v7; // eax
  int v8; // edi
  IDirect3DDevice9_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  ID3DXBuffer *pPSBuffer; // [esp+8h] [ebp-10h] BYREF
  ID3DXBuffer *pVSBuffer; // [esp+Ch] [ebp-Ch] BYREF
  ID3DXBuffer *pErrorBufferPS; // [esp+10h] [ebp-8h] BYREF
  ID3DXBuffer *pErrorBufferVS; // [esp+14h] [ebp-4h] BYREF

  pVSBuffer = nullptr;
  pPSBuffer = nullptr;
  pErrorBufferVS = nullptr;
  pErrorBufferPS = nullptr;
  if ( D3DXCompileShader(
         a1: szShader,
         a2: 0x2FDu,
         a3: nullptr,
         a4: nullptr,
         a5: (int)"VS",
         a6: (int)"vs_2_0",
         a7: 0,
         a8: (int)&pVSBuffer,
         a9: &pErrorBufferVS,
         a10: 0) >= 0 )
  {
    if ( D3DXCompileShader(
           a1: szShader,
           a2: 0x2FDu,
           a3: nullptr,
           a4: nullptr,
           a5: (int)"PS",
           a6: (int)"ps_2_0",
           a7: 0,
           a8: (int)&pPSBuffer,
           a9: &pErrorBufferPS,
           a10: 0) >= 0 )
    {
      if ( pErrorBufferVS != nullptr )
        pErrorBufferVS->Release(this: pErrorBufferVS);
      if ( pErrorBufferPS != nullptr )
        pErrorBufferPS->Release(this: pErrorBufferPS);
      v6 = pd3dDevice->__vftable;
      v7 = ((int (__stdcall *)(ID3DXBuffer *, IDirect3DVertexShader9 **))pVSBuffer->GetBufferPointer)(
             a1: pVSBuffer,
             a2: &this->m_pVS);
      v8 = ((int (__stdcall *)(IDirect3DDevice9 *, int))v6->CreateVertexShader)(a1: pd3dDevice, a2: v7);
      pVSBuffer->Release(this: pVSBuffer);
      if ( v8 >= 0 )
      {
        v9 = pd3dDevice->__vftable;
        v10 = ((int (__stdcall *)(ID3DXBuffer *, IDirect3DPixelShader9 **))pPSBuffer->GetBufferPointer)(
                a1: pPSBuffer,
                a2: &this->m_pPS);
        v11 = ((int (__stdcall *)(IDirect3DDevice9 *, int))v9->CreatePixelShader)(a1: pd3dDevice, a2: v10);
        pPSBuffer->Release(this: pPSBuffer);
        return v11 >= 0;
      }
      else
      {
        return false;
      }
    }
    else
    {
      v5 = (const char *)pErrorBufferPS->GetBufferPointer(this: pErrorBufferPS);
      OutputDebugStringA(lpOutputString: v5);
      return false;
    }
  }
  else
  {
    v3 = (const char *)pErrorBufferVS->GetBufferPointer(this: pErrorBufferVS);
    OutputDebugStringA(lpOutputString: v3);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B190
// Name: private: void CSubDMesh::CopyFromSurface(struct IDirect3DSurface9 __near *,class Vector2D __near *,unsigned int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::CopyFromSurface(
        CSubDMesh *this,
        IDirect3DSurface9 *pSurf,
        Vector2D *pPatchUVTexture,
        unsigned int *pPatchIDTexture,
        int Width,
        int Height)
{
  IDirect3DSurface9 *v6; // edi
  char *pBits; // ebx
  float *v10; // ecx
  int j; // edi
  double v12; // st7
  _D3DLOCKED_RECT LockedRect; // [esp+10h] [ebp-10h] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  v6 = pSurf;
  pSurf->LockRect(this: pSurf, a2: &LockedRect, a3: nullptr, a4: 0);
  pBits = (char *)LockedRect.pBits;
  if ( Height > 0 )
  {
    v14 = LockedRect.Pitch & 0xFFFFFFF0;
    for ( i = Height; i != 0; --i )
    {
      if ( Width > 0 )
      {
        v10 = (float *)(pBits + 8);
        for ( j = Width; j != 0; --j )
        {
          ++pPatchUVTexture;
          ++pPatchIDTexture;
          pPatchUVTexture[-1].x = *(v10 - 2);
          pPatchUVTexture[-1].y = *(v10 - 1);
          v12 = *v10;
          v10 += 4;
          *(pPatchIDTexture - 1) = (__int64)v12;
        }
        v6 = pSurf;
      }
      pBits += v14;
    }
  }
  v6->UnlockRect(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0041B230
// Name: private: void CSubDMesh::CopyFromSurface(struct IDirect3DSurface9 __near *,class Vector4D __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::CopyFromSurface(
        CSubDMesh *this,
        IDirect3DSurface9 *pSurf,
        Vector4D *pPatchTanTexture,
        int Width,
        Vector4D *Height)
{
  IDirect3DSurface9 *v5; // esi
  unsigned __int8 *pBits; // edi
  unsigned int v9; // esi
  _D3DLOCKED_RECT LockedRect; // [esp+Ch] [ebp-8h] BYREF
  Vector4D *pPatchTanTexturea; // [esp+20h] [ebp+Ch]
  unsigned int Heighta; // [esp+28h] [ebp+14h]

  v5 = pSurf;
  pSurf->LockRect(this: pSurf, a2: &LockedRect, a3: nullptr, a4: 0);
  pBits = (unsigned __int8 *)LockedRect.pBits;
  if ( (int)Height > 0 )
  {
    Heighta = LockedRect.Pitch & 0xFFFFFFF0;
    v9 = 16 * Width;
    pPatchTanTexturea = Height;
    do
    {
      memcpy(dst: (unsigned __int8 *)pPatchTanTexture, src: pBits, count: v9);
      pBits += Heighta;
      pPatchTanTexture = (Vector4D *)((char *)pPatchTanTexture + v9);
      pPatchTanTexturea = (Vector4D *)((char *)pPatchTanTexturea - 1);
    }
    while ( pPatchTanTexturea != nullptr );
    v5 = pSurf;
  }
  v5->UnlockRect(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0041B2A0
// Name: private: void CSubDMesh::CopyFromSurface(struct IDirect3DSurface9 __near *,unsigned char __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::CopyFromSurface(
        CSubDMesh *this,
        IDirect3DSurface9 *pSurf,
        unsigned __int8 *pEdgeTexture,
        int Width,
        int Height,
        int DestPitch)
{
  IDirect3DSurface9 *v6; // ebx
  _BYTE *pBits; // ecx
  int v9; // eax
  _D3DLOCKED_RECT LockedRect; // [esp+4h] [ebp-8h] BYREF

  v6 = pSurf;
  pSurf->LockRect(this: pSurf, a2: &LockedRect, a3: nullptr, a4: 0);
  pBits = LockedRect.pBits;
  if ( Height > 0 )
  {
    do
    {
      v9 = 0;
      if ( Width > 0 )
      {
        do
        {
          pEdgeTexture[v9] = pBits[4 * v9];
          ++v9;
        }
        while ( v9 < Width );
        v6 = pSurf;
      }
      pBits += LockedRect.Pitch;
      pEdgeTexture += DestPitch;
      --Height;
    }
    while ( Height != 0 );
  }
  v6->UnlockRect(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0041B310
// Name: private: void CSubDMesh::GutterPixel(int,int,class Vector2D __near *,unsigned int __near *,class Vector4D __near *,int,int,int,class Vector2D __near *,unsigned int __near *,class Vector4D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::GutterPixel(
        CSubDMesh *this,
        int X,
        int Y,
        Vector2D *pSrcUVs,
        unsigned int *pSrcIDs,
        Vector4D *pSrcTanU,
        int SrcPitch,
        int FullWidth,
        int FullHeight,
        Vector2D *pOutGutteredUV,
        unsigned int *pOutGutteredID,
        Vector4D *pOutGutteredTanU)
{
  float v12; // xmm0_4
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // esi
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float z; // xmm4_4
  float w; // xmm5_4
  int v21; // eax
  int v22; // eax
  unsigned int v23; // edx
  Vector4D *v24; // eax
  int v25; // eax
  Vector4D *v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int v29; // edx
  Vector4D *v30; // eax
  int y; // [esp+0h] [ebp-4h]

  v12 = 0.0;
  v13 = Y - 1;
  v14 = 0;
  v15 = SrcPitch * (Y - 1);
  v16 = 0.0;
  v17 = 0.0;
  v18 = 0.0;
  z = 0.0;
  w = 0.0;
  y = -1;
  do
  {
    v21 = X - 1;
    if ( X - 1 >= 0 && v13 >= 0 && v21 < FullWidth && v13 < FullHeight )
    {
      v22 = v15 + v21;
      v23 = pSrcIDs[v22];
      if ( v23 > v14 )
      {
        v12 = pSrcUVs[v22].x;
        v16 = pSrcUVs[v22].y;
        v24 = &pSrcTanU[v22];
        v14 = v23;
        v17 = v24->x;
        v18 = v24->y;
        z = v24->z;
        w = v24->w;
      }
    }
    if ( X >= 0 && v13 >= 0 && X < FullWidth && v13 < FullHeight && y != 0 )
    {
      v25 = v15 + X;
      if ( pSrcIDs[v15 + X] > v14 )
      {
        v12 = pSrcUVs[v25].x;
        v16 = pSrcUVs[v25].y;
        v26 = &pSrcTanU[v25];
        v14 = pSrcIDs[v15 + X];
        v17 = v26->x;
        v18 = v26->y;
        z = v26->z;
        w = v26->w;
      }
    }
    v27 = X + 1;
    if ( X + 1 >= 0 && v13 >= 0 && v27 < FullWidth && v13 < FullHeight )
    {
      v28 = v15 + v27;
      v29 = pSrcIDs[v28];
      if ( v29 > v14 )
      {
        v12 = pSrcUVs[v28].x;
        v16 = pSrcUVs[v28].y;
        v30 = &pSrcTanU[v28];
        v14 = v29;
        v17 = v30->x;
        v18 = v30->y;
        z = v30->z;
        w = v30->w;
      }
    }
    v15 += SrcPitch;
    ++v13;
    ++y;
  }
  while ( y < 2 );
  pOutGutteredUV->x = v12;
  pOutGutteredUV->y = v16;
  *pOutGutteredID = v14;
  pOutGutteredTanU->x = v17;
  pOutGutteredTanU->y = v18;
  pOutGutteredTanU->z = z;
  pOutGutteredTanU->w = w;
}

//------------------------------------------------------------------------------
// Address: 0x0041B460
// Name: private: void CSubDMesh::GutterMapBits(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::GutterMapBits(CSubDMesh *this, int iTile, int Width, int Height, int GutterSize)
{
  int v5; // edi
  int v6; // esi
  CSubDMesh *v7; // ebx
  Vector4D *v8; // esi
  int v9; // ecx
  unsigned int *v10; // edx
  Vector2D *v11; // edi
  float *v12; // esi
  unsigned int *v13; // ebx
  int v14; // eax
  float *v15; // ecx
  bool v16; // zf
  Vector2D *v17; // eax
  unsigned int *v18; // eax
  unsigned int *v19; // [esp+Ch] [ebp-48h]
  int v20; // [esp+18h] [ebp-3Ch]
  int v21; // [esp+1Ch] [ebp-38h]
  int v23; // [esp+24h] [ebp-30h]
  int y; // [esp+28h] [ebp-2Ch]
  int x; // [esp+2Ch] [ebp-28h]
  float *v26; // [esp+30h] [ebp-24h]
  float *p_y; // [esp+34h] [ebp-20h]
  float *p_w; // [esp+38h] [ebp-1Ch]
  unsigned int *pSrcID; // [esp+3Ch] [ebp-18h]
  Vector2D *pSrcUV; // [esp+40h] [ebp-14h]
  unsigned int *pScratchID; // [esp+44h] [ebp-10h]
  Vector2D *pScratchUV; // [esp+48h] [ebp-Ch]
  Vector4D *pScratchTanU; // [esp+4Ch] [ebp-8h]
  Vector4D *pSrcTanU; // [esp+50h] [ebp-4h]
  int GutterSizea; // [esp+68h] [ebp+14h]

  v5 = Width;
  v6 = Height * Width;
  v7 = this;
  pScratchUV = (Vector2D *)operator new(nSize: 8 * Height * Width);
  if ( pScratchUV != nullptr )
  {
    pScratchID = (unsigned int *)operator new(nSize: 4 * v6);
    if ( pScratchID != nullptr )
    {
      v8 = (Vector4D *)operator new(nSize: 16 * v6);
      pScratchTanU = v8;
      if ( v8 != nullptr )
      {
        v9 = iTile;
        pSrcUV = v7->m_ppPatchUVTextureTile[iTile];
        pSrcID = v7->m_ppPatchIDTextureTile[iTile];
        pSrcTanU = v7->m_ppPatchTanUTextureTile[iTile];
        if ( GutterSize > 0 )
        {
          v21 = GutterSize;
          do
          {
            y = 0;
            if ( Height > 0 )
            {
              v10 = pScratchID;
              v20 = 16 * v5;
              GutterSizea = (int)pScratchUV;
              p_y = &v8->y;
              p_w = &pSrcTanU->w;
              do
              {
                x = 0;
                if ( v5 > 0 )
                {
                  v11 = (Vector2D *)GutterSizea;
                  v26 = p_w;
                  v12 = p_y;
                  v23 = (char *)pSrcID - (char *)pScratchID;
                  v13 = v10;
                  GutterSizea += 8 * Width;
                  p_w = (float *)((char *)p_w + v20);
                  v14 = (char *)pSrcUV - (char *)pScratchUV;
                  p_y = (float *)((char *)p_y + v20);
                  v15 = v26;
                  v19 = &v10[Width];
                  do
                  {
                    if ( *(unsigned int *)((char *)v13 + v23) != 0 )
                    {
                      v11->x = *(float *)((char *)&v11->x + v14);
                      v11->y = *(float *)((char *)&v11->y + v14);
                      *v13 = *(unsigned int *)((char *)v13 + v23);
                      *(v12 - 1) = *(v15 - 3);
                      *v12 = *(float *)((char *)v12 + (char *)pSrcTanU - (char *)pScratchTanU);
                      v12[1] = *(v15 - 1);
                      v12[2] = *v15;
                    }
                    else
                    {
                      CSubDMesh::GutterPixel(
                        this,
                        X: x,
                        Y: y,
                        pSrcUVs: pSrcUV,
                        pSrcIDs: pSrcID,
                        pSrcTanU,
                        SrcPitch: Width,
                        FullWidth: Width,
                        FullHeight: Height,
                        pOutGutteredUV: v11,
                        pOutGutteredID: v13,
                        pOutGutteredTanU: (Vector4D *)(v12 - 1));
                      v15 = v26;
                      v14 = (char *)pSrcUV - (char *)pScratchUV;
                    }
                    v15 += 4;
                    ++v11;
                    ++v13;
                    v12 += 4;
                    v26 = v15;
                    ++x;
                  }
                  while ( x < Width );
                  v9 = iTile;
                  v7 = this;
                  v5 = Width;
                  v10 = v19;
                }
                ++y;
              }
              while ( y < Height );
              v8 = pScratchTanU;
            }
            v16 = v21-- == 1;
            v17 = pScratchUV;
            pScratchUV = pSrcUV;
            pSrcUV = v17;
            v18 = pScratchID;
            pScratchID = pSrcID;
            pSrcID = v18;
            pScratchTanU = pSrcTanU;
            pSrcTanU = v8;
            v8 = pScratchTanU;
          }
          while ( !v16 );
        }
        v7->m_ppPatchUVTextureTile[v9] = pScratchUV;
        v7->m_ppPatchIDTextureTile[v9] = pScratchID;
        v7->m_ppPatchTanUTextureTile[v9] = v8;
        free(pMem: pSrcUV);
        free(pMem: pSrcID);
        free(pMem: pSrcTanU);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B6D0
// Name: private: bool CSubDMesh::FillIBForPreTessPatch(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::FillIBForPreTessPatch(CSubDMesh *this, int NumDivisionsPerSide)
{
  int v2; // edi
  unsigned __int16 *v4; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = NumDivisionsPerSide;
  this->m_NumPreTessIndices = 4 * NumDivisionsPerSide * NumDivisionsPerSide;
  v4 = (unsigned __int16 *)operator new(nSize: 8 * NumDivisionsPerSide * NumDivisionsPerSide);
  this->m_pPreTessPatchIndices = v4;
  if ( v4 == nullptr )
    return 0;
  v6 = 0;
  v7 = 0;
  if ( NumDivisionsPerSide > 0 )
  {
    v10 = NumDivisionsPerSide;
    while ( 1 )
    {
      v8 = (unsigned __int16)(v2 + v6 + 2);
      v11 = v2;
      do
      {
        this->m_pPreTessPatchIndices[v7] = v6;
        v9 = v7 + 1;
        this->m_pPreTessPatchIndices[v9] = v8 + -1 - NumDivisionsPerSide;
        this->m_pPreTessPatchIndices[v9 + 1] = v8;
        v9 += 2;
        this->m_pPreTessPatchIndices[v9] = v8 - 1;
        v7 = v9 + 1;
        ++v6;
        ++v8;
        --v11;
      }
      while ( v11 != 0 );
      ++v6;
      if ( --v10 == 0 )
        break;
      v2 = NumDivisionsPerSide;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B790
// Name: EvaluateCubicACCPosPatch
// Source: json
//------------------------------------------------------------------------------
Vector4D *__usercall EvaluateCubicACCPosPatch@<eax>(
        Vector4D *BasisU@<edx>,
        Vector4D *BasisV@<esi>,
        Vector4D *cpP@<ecx>,
        float *a4)
{
  float w; // xmm5_4
  float z; // xmm0_4
  float v7; // xmm1_4
  float y; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm5_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  float x; // xmm0_4
  float v40; // [esp+Ch] [ebp-54h]
  float v41; // [esp+10h] [ebp-50h]
  float v42; // [esp+14h] [ebp-4Ch]
  float v43; // [esp+14h] [ebp-4Ch]
  float v44; // [esp+18h] [ebp-48h]
  float v45; // [esp+18h] [ebp-48h]
  float v46; // [esp+1Ch] [ebp-44h]
  float v47; // [esp+1Ch] [ebp-44h]
  float v48; // [esp+20h] [ebp-40h]
  float v49; // [esp+24h] [ebp-3Ch]
  float v50; // [esp+24h] [ebp-3Ch]
  float v51; // [esp+28h] [ebp-38h]
  float v52; // [esp+28h] [ebp-38h]
  float v53; // [esp+2Ch] [ebp-34h]
  float v54; // [esp+2Ch] [ebp-34h]
  float v55; // [esp+30h] [ebp-30h]
  float v56; // [esp+34h] [ebp-2Ch]
  float v57; // [esp+38h] [ebp-28h]
  float v58; // [esp+38h] [ebp-28h]
  float v59; // [esp+3Ch] [ebp-24h]
  float v60; // [esp+3Ch] [ebp-24h]
  float v61; // [esp+40h] [ebp-20h]
  float v62; // [esp+44h] [ebp-1Ch]
  float v63; // [esp+48h] [ebp-18h]
  float v64; // [esp+48h] [ebp-18h]
  float v65; // [esp+4Ch] [ebp-14h]
  float v66; // [esp+50h] [ebp-10h]
  float v67; // [esp+50h] [ebp-10h]
  float v68; // [esp+54h] [ebp-Ch]
  float v69; // [esp+54h] [ebp-Ch]
  float v70; // [esp+54h] [ebp-Ch]
  float v71; // [esp+58h] [ebp-8h]
  float v72; // [esp+58h] [ebp-8h]
  float v73; // [esp+58h] [ebp-8h]
  float v74; // [esp+5Ch] [ebp-4h]

  w = BasisU->w;
  z = BasisU->z;
  v66 = cpP[14].x * z;
  v68 = cpP[14].y * z;
  v71 = cpP[14].z * z;
  v7 = cpP[14].w * z;
  y = BasisU->y;
  v42 = cpP[13].y * y;
  v44 = cpP[13].z * y;
  v46 = cpP[13].w * y;
  v9 = (float)(w * cpP[15].x) + (float)((float)((float)(BasisU->x * cpP[12].x) + (float)(cpP[13].x * y)) + v66);
  v10 = BasisV->w;
  v43 = (float)((float)((float)((float)(cpP[12].y * BasisU->x) + v42) + v68) + (float)(cpP[15].y * w)) * v10;
  v41 = v9 * v10;
  v45 = (float)((float)((float)((float)(cpP[12].z * BasisU->x) + v44) + v71) + (float)(cpP[15].z * w)) * v10;
  v47 = (float)((float)((float)((float)(cpP[12].w * BasisU->x) + v46) + v7) + (float)(cpP[15].w * w)) * v10;
  v11 = BasisU->z;
  v69 = cpP[10].y * v11;
  v72 = cpP[10].z * v11;
  v12 = cpP[10].w * v11;
  v13 = BasisU->y;
  v49 = cpP[9].y * v13;
  v51 = cpP[9].z * v13;
  v53 = cpP[9].w * v13;
  v14 = (float)((float)(cpP[9].x * v13) + (float)(cpP[8].x * BasisU->x)) + (float)(BasisU->z * cpP[10].x);
  v15 = BasisV->z;
  v50 = (float)((float)((float)((float)(cpP[8].y * BasisU->x) + v49) + v69) + (float)(cpP[11].y * w)) * v15;
  v16 = (float)(v14 + (float)(w * cpP[11].x)) * v15;
  v17 = (float)((float)((float)((float)(cpP[8].z * BasisU->x) + v51) + v72) + (float)(cpP[11].z * w)) * v15;
  v18 = (float)((float)((float)((float)(cpP[8].w * BasisU->x) + v53) + v12) + (float)(cpP[11].w * w)) * v15;
  v63 = cpP[7].z * w;
  v65 = cpP[7].w * w;
  v19 = BasisU->z;
  v67 = cpP[6].x * v19;
  v70 = cpP[6].y * v19;
  v73 = cpP[6].z * v19;
  v20 = cpP[6].w * v19;
  v21 = BasisU->y;
  v48 = v16;
  v52 = v17;
  v54 = v18;
  v74 = v20;
  v57 = cpP[5].z * v21;
  v59 = cpP[5].w * v21;
  v22 = (float)((float)((float)(cpP[4].y * BasisU->x) + (float)(cpP[5].y * v21)) + v70) + (float)(cpP[7].y * w);
  v23 = (float)(cpP[7].x * w) + (float)((float)((float)(cpP[4].x * BasisU->x) + (float)(v21 * cpP[5].x)) + v67);
  v24 = BasisV->y;
  v56 = v22 * v24;
  v25 = v23 * v24;
  v26 = (float)((float)((float)((float)(cpP[4].z * BasisU->x) + v57) + v73) + v63) * v24;
  v27 = (float)((float)((float)((float)(cpP[4].w * BasisU->x) + v59) + v74) + v65) * v24;
  v28 = BasisU->w;
  v40 = cpP[3].w * v28;
  v55 = v25;
  v29 = cpP[3].x * v28;
  v30 = cpP[3].y * v28;
  v31 = cpP[3].z * v28;
  v32 = BasisU->z;
  v61 = cpP[2].x * v32;
  v62 = cpP[2].y * v32;
  v64 = cpP[2].z * v32;
  v33 = cpP[2].w * v32;
  v34 = BasisU->y;
  v58 = v26;
  v60 = v27;
  v35 = (float)((float)((float)(cpP->w * BasisU->x) + (float)(cpP[1].w * v34)) + v33) + v40;
  v36 = (float)((float)((float)(cpP->y * BasisU->x) + (float)(cpP[1].y * v34)) + v62) + v30;
  v37 = (float)((float)((float)(cpP->z * BasisU->x) + (float)(cpP[1].z * v34)) + v64) + v31;
  v38 = (float)((float)((float)(BasisU->x * cpP->x) + (float)(v34 * cpP[1].x)) + v61) + v29;
  x = BasisV->x;
  *a4 = (float)((float)((float)(v38 * BasisV->x) + v55) + v48) + v41;
  a4[1] = (float)((float)((float)(v36 * x) + v56) + v50) + v43;
  a4[2] = (float)((float)((float)(v37 * x) + v58) + v52) + v45;
  a4[3] = (float)((float)((float)(v35 * x) + v60) + v54) + v47;
  return (Vector4D *)a4;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD00
// Name: EvaluateCubicACCTanPatches
// Source: json
//------------------------------------------------------------------------------
void __usercall EvaluateCubicACCTanPatches(
        Vector4D *cpU@<ecx>,
        Vector4D *cpV@<eax>,
        Vector4D *pOutTanU@<edi>,
        Vector4D *pOutTanV@<esi>,
        Vector4D *BasisU,
        Vector4D *BasisV,
        float U,
        float V)
{
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float w; // xmm3_4
  float z; // xmm3_4
  float y; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float x; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm5_4
  float v36; // xmm0_4
  float v37; // xmm6_4
  float v38; // xmm7_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // [esp+18h] [ebp-58h]
  float v47; // [esp+1Ch] [ebp-54h]
  float v48; // [esp+1Ch] [ebp-54h]
  float v49; // [esp+1Ch] [ebp-54h]
  float v50; // [esp+20h] [ebp-50h]
  float v51; // [esp+20h] [ebp-50h]
  float v52; // [esp+20h] [ebp-50h]
  float v53; // [esp+24h] [ebp-4Ch]
  float v54; // [esp+28h] [ebp-48h]
  float v55; // [esp+2Ch] [ebp-44h]
  float v56; // [esp+30h] [ebp-40h]
  float v57; // [esp+30h] [ebp-40h]
  float v58; // [esp+34h] [ebp-3Ch]
  float v59; // [esp+34h] [ebp-3Ch]
  float v60; // [esp+34h] [ebp-3Ch]
  float v61; // [esp+34h] [ebp-3Ch]
  float v62; // [esp+38h] [ebp-38h]
  float v63; // [esp+38h] [ebp-38h]
  float v64; // [esp+38h] [ebp-38h]
  float v65; // [esp+38h] [ebp-38h]
  float v66; // [esp+3Ch] [ebp-34h]
  float v67; // [esp+3Ch] [ebp-34h]
  float v68; // [esp+3Ch] [ebp-34h]
  float v69; // [esp+3Ch] [ebp-34h]
  float v70; // [esp+40h] [ebp-30h]
  float v71; // [esp+40h] [ebp-30h]
  float v72; // [esp+48h] [ebp-28h]
  float v73; // [esp+4Ch] [ebp-24h]
  float v74; // [esp+50h] [ebp-20h]
  float v75; // [esp+50h] [ebp-20h]
  float v76; // [esp+54h] [ebp-1Ch]
  float v77; // [esp+58h] [ebp-18h]
  float v78; // [esp+58h] [ebp-18h]
  float v79; // [esp+5Ch] [ebp-14h]
  float v80; // [esp+5Ch] [ebp-14h]
  float v81; // [esp+60h] [ebp-10h]
  float qBasisV_4; // [esp+68h] [ebp-8h]

  v8 = (float)(1.0 - V) * (float)(1.0 - V);
  qBasisV_4 = (float)((float)(1.0 - V) * 2.0) * V;
  v9 = (float)(1.0 - U) * (float)(1.0 - U);
  v10 = (float)((float)(1.0 - U) * 2.0) * U;
  w = BasisV->w;
  v53 = (float)((float)((float)(cpU[9].x * v9) + (float)(v10 * cpU[10].x)) + (float)(cpU[11].x * (float)(U * U))) * w;
  v54 = (float)((float)((float)(cpU[9].y * v9) + (float)(cpU[10].y * v10)) + (float)(cpU[11].y * (float)(U * U))) * w;
  v55 = (float)((float)((float)(cpU[9].z * v9) + (float)(cpU[10].z * v10)) + (float)(cpU[11].z * (float)(U * U))) * w;
  v56 = (float)((float)((float)(cpU[9].w * v9) + (float)(cpU[10].w * v10)) + (float)(cpU[11].w * (float)(U * U))) * w;
  z = BasisV->z;
  v62 = (float)((float)((float)(cpU[6].y * v9) + (float)(cpU[7].y * v10)) + (float)(cpU[8].y * (float)(U * U))) * z;
  v66 = (float)((float)((float)(cpU[6].z * v9) + (float)(cpU[7].z * v10)) + (float)(cpU[8].z * (float)(U * U))) * z;
  v58 = (float)((float)((float)(cpU[6].x * v9) + (float)(cpU[7].x * v10)) + (float)(cpU[8].x * (float)(U * U))) * z;
  v70 = (float)((float)((float)(cpU[6].w * v9) + (float)(cpU[7].w * v10)) + (float)(cpU[8].w * (float)(U * U))) * z;
  y = BasisV->y;
  v77 = (float)((float)((float)(cpU[3].y * v9) + (float)(cpU[4].y * v10)) + (float)(cpU[5].y * (float)(U * U))) * y;
  v14 = (float)((float)((float)(cpU[3].x * v9) + (float)(v10 * cpU[4].x)) + (float)(cpU[5].x * (float)(U * U))) * y;
  v79 = (float)((float)((float)(cpU[3].z * v9) + (float)(cpU[4].z * v10)) + (float)(cpU[5].z * (float)(U * U))) * y;
  v73 = cpU[1].z * v10;
  v74 = cpU[1].w * v10;
  v81 = (float)((float)((float)(cpU[3].w * v9) + (float)(cpU[4].w * v10)) + (float)(cpU[5].w * (float)(U * U))) * y;
  v15 = (float)(cpU->x * v9) + (float)(cpU[1].x * v10);
  v16 = (float)((float)(cpU->y * v9) + (float)(cpU[1].y * v10)) + (float)(cpU[2].y * (float)(U * U));
  v17 = (float)((float)(cpU->z * v9) + v73) + (float)(cpU[2].z * (float)(U * U));
  v18 = cpU->w * v9;
  x = BasisV->x;
  v20 = (float)(v18 + v74) + (float)(cpU[2].w * (float)(U * U));
  v21 = (float)((float)((float)(v16 * BasisV->x) + v77) + v62) + v54;
  pOutTanU->x = (float)((float)((float)((float)(v15 + (float)(cpU[2].x * (float)(U * U))) * BasisV->x) + v14) + v58)
              + v53;
  pOutTanU->y = v21;
  pOutTanU->z = (float)((float)((float)(v17 * x) + v79) + v66) + v55;
  pOutTanU->w = (float)((float)((float)(v20 * x) + v81) + v70) + v56;
  v22 = BasisU->w;
  v46 = cpV[11].y * v22;
  v47 = cpV[11].z * v22;
  v50 = cpV[11].w * v22;
  v23 = BasisU->z;
  v59 = cpV[10].x * v23;
  v63 = cpV[10].y * v23;
  v67 = cpV[10].z * v23;
  v24 = cpV[10].w * v23;
  v25 = BasisU->y;
  v26 = (float)((float)((float)(cpV[8].z * BasisU->x) + (float)(cpV[9].z * v25)) + v67) + v47;
  v27 = (float)((float)((float)(cpV[8].w * BasisU->x) + (float)(cpV[9].w * v25)) + v24) + v50;
  v76 = (float)((float)((float)((float)(cpV[8].x * BasisU->x) + (float)(v25 * cpV[9].x)) + v59)
              + (float)(BasisU->w * cpV[11].x))
      * (float)(V * V);
  v78 = (float)((float)((float)((float)(cpV[8].y * BasisU->x) + (float)(cpV[9].y * v25)) + v63) + v46) * (float)(V * V);
  v28 = BasisU->w;
  v48 = cpV[7].z * v28;
  v51 = cpV[7].w * v28;
  v29 = cpV[7].y * v28;
  v30 = cpV[7].x * v28;
  v31 = BasisU->z;
  v60 = cpV[6].x * v31;
  v64 = cpV[6].y * v31;
  v68 = cpV[6].z * v31;
  v32 = cpV[6].w * v31;
  v33 = BasisU->y;
  v57 = cpV[5].w * v33;
  v80 = v26 * (float)(V * V);
  v34 = (float)((float)((float)(cpV[4].z * BasisU->x) + (float)(cpV[5].z * v33)) + v68) + v48;
  v35 = (float)((float)((float)(cpV[4].x * BasisU->x) + (float)(cpV[5].x * v33)) + v60) + v30;
  v72 = (float)((float)((float)((float)(cpV[4].y * BasisU->x) + (float)(cpV[5].y * v33)) + v64) + v29) * qBasisV_4;
  v36 = BasisU->w;
  v49 = cpV[3].z * v36;
  v75 = (float)((float)((float)((float)(cpV[4].w * BasisU->x) + v57) + v32) + v51) * qBasisV_4;
  v37 = cpV[3].x * v36;
  v38 = cpV[3].y * v36;
  v39 = cpV[3].w * v36;
  v40 = BasisU->z;
  v52 = v39;
  v61 = cpV[2].x * v40;
  v65 = cpV[2].y * v40;
  v69 = cpV[2].z * v40;
  v41 = cpV[2].w * v40;
  v42 = BasisU->y;
  v71 = v41;
  v43 = (float)((float)((float)((float)((float)((float)(cpV->y * BasisU->x) + (float)(cpV[1].y * v42)) + v65) + v38) * v8)
              + v72)
      + v78;
  v44 = (float)((float)((float)((float)((float)((float)(cpV->z * BasisU->x) + (float)(cpV[1].z * v42)) + v69) + v49) * v8)
              + (float)(v34 * qBasisV_4))
      + v80;
  v45 = (float)((float)((float)((float)((float)((float)(cpV->w * BasisU->x) + (float)(cpV[1].w * v42)) + v71) + v52) * v8)
              + v75)
      + (float)(v27 * (float)(V * V));
  pOutTanV->x = (float)((float)((float)((float)((float)((float)(BasisU->x * cpV->x) + (float)(cpV[1].x * v42)) + v61)
                                      + v37)
                              * v8)
                      + (float)(v35 * qBasisV_4))
              + v76;
  pOutTanV->y = v43;
  pOutTanV->z = v44;
  pOutTanV->w = v45;
}

//------------------------------------------------------------------------------
// Address: 0x0041C600
// Name: public: void CSubDMesh::EvalulateACCPatchAtUV(int,float,float,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::EvalulateACCPatchAtUV(
        CSubDMesh *this,
        int iPatchID,
        float U,
        float V,
        Vector *pOutPosition,
        Vector *pOutNormal)
{
  Vector4D *v7; // eax
  Vector4D *m_pPatchScratchACCU; // ecx
  float z; // xmm0_4
  Vector4D *m_pPatchScratchACCV; // eax
  float v11; // xmm1_4
  float v12; // xmm5_4
  Vector4D TanU4; // [esp+14h] [ebp-50h] BYREF
  Vector4D TanV4; // [esp+24h] [ebp-40h] BYREF
  Vector4D Pos4; // [esp+34h] [ebp-30h]
  Vector Normal; // [esp+44h] [ebp-20h] BYREF
  float v17; // [esp+50h] [ebp-14h]
  Vector4D BasisU; // [esp+54h] [ebp-10h] BYREF

  BasisU.x = CubicBasis0(t: U);
  BasisU.y = CubicBasis1(t: U);
  BasisU.z = CubicBasis2(t: U);
  BasisU.w = CubicBasis3(t: U);
  Normal.x = CubicBasis0(t: V);
  Normal.y = CubicBasis1(t: V);
  Normal.z = CubicBasis2(t: V);
  v17 = CubicBasis3(t: V);
  v7 = EvaluateCubicACCPosPatch(
         &BasisU,
         BasisV: (Vector4D *)&Normal,
         cpP: &this->m_pPatchScratchACCPos[16 * iPatchID],
         a4: &TanU4.x);
  m_pPatchScratchACCU = this->m_pPatchScratchACCU;
  Pos4.x = v7->x;
  Pos4.y = v7->y;
  z = v7->z;
  m_pPatchScratchACCV = this->m_pPatchScratchACCV;
  Pos4.z = z;
  EvaluateCubicACCTanPatches(
    cpU: &m_pPatchScratchACCU[12 * iPatchID],
    cpV: &m_pPatchScratchACCV[12 * iPatchID],
    pOutTanU: &TanU4,
    pOutTanV: &TanV4,
    &BasisU,
    BasisV: (Vector4D *)&Normal,
    U,
    V);
  v11 = TanV4.z * TanU4.x;
  Normal.y = (float)(TanV4.z * TanU4.y) - (float)(TanV4.y * TanU4.z);
  v12 = TanV4.x * TanU4.z;
  v17 = (float)(TanV4.y * TanU4.x) - (float)(TanV4.x * TanU4.y);
  pOutPosition->x = Pos4.x;
  pOutPosition->y = Pos4.y;
  pOutPosition->z = Pos4.z;
  Normal.z = v12 - v11;
  *(_QWORD *)&BasisU.y = *(_QWORD *)&Normal.y;
  BasisU.w = v17;
  VectorNormalize(vec: (Vector *)&BasisU.y);
  *pOutNormal = *(Vector *)&BasisU.y;
}

//------------------------------------------------------------------------------
// Address: 0x0041C7D0
// Name: private: bool CSubDMesh::CreatePatchesBuffer(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::CreatePatchesBuffer(CSubDMesh *this)
{
  int m_Size; // edi
  void *v3; // eax
  Vector4D *v4; // ecx
  unsigned int v5; // edi
  void *v6; // eax
  Vector4D *v7; // ecx
  void *v8; // eax
  Vector4D *v9; // ecx
  unsigned __int8 *m_pPatchScratchACCPos; // eax
  unsigned int count; // [esp+Ch] [ebp-4h]

  m_Size = this->m_SubDPatches.m_Size;
  if ( this->m_pPatchScratchACCPos != nullptr )
  {
    free(pMem: this->m_pPatchScratchACCPos);
    this->m_pPatchScratchACCPos = nullptr;
  }
  if ( this->m_pPatchScratchACCU != nullptr )
  {
    free(pMem: this->m_pPatchScratchACCU);
    this->m_pPatchScratchACCU = nullptr;
  }
  if ( this->m_pPatchScratchACCV != nullptr )
  {
    free(pMem: this->m_pPatchScratchACCV);
    this->m_pPatchScratchACCV = nullptr;
  }
  count = m_Size << 8;
  v3 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: (m_Size << 8) + 19);
  if ( v3 != nullptr )
  {
    v4 = (Vector4D *)(((unsigned int)v3 + 19) & 0xFFFFFFF0);
    LODWORD(v4[-1].w) = v3;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pPatchScratchACCPos = v4;
  v5 = 192 * m_Size;
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v5 + 19);
  if ( v6 != nullptr )
  {
    v7 = (Vector4D *)(((unsigned int)v6 + 19) & 0xFFFFFFF0);
    LODWORD(v7[-1].w) = v6;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pPatchScratchACCU = v7;
  v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v5 + 19);
  if ( v8 != nullptr )
  {
    v9 = (Vector4D *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
    LODWORD(v9[-1].w) = v8;
  }
  else
  {
    v9 = nullptr;
  }
  m_pPatchScratchACCPos = (unsigned __int8 *)this->m_pPatchScratchACCPos;
  this->m_pPatchScratchACCV = v9;
  if ( m_pPatchScratchACCPos == nullptr || this->m_pPatchScratchACCU == nullptr || v9 == nullptr )
    return 0;
  memset(dst: m_pPatchScratchACCPos, value: 0, count);
  memset(dst: (unsigned __int8 *)this->m_pPatchScratchACCU, value: 0, count: v5);
  memset(dst: (unsigned __int8 *)this->m_pPatchScratchACCV, value: 0, count: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C8E0
// Name: private: bool CSubDMesh::FillVBForPreTessPatch(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::FillVBForPreTessPatch(CSubDMesh *this, int NumDivisionsPerSide)
{
  int v3; // ebx
  PreTessPatchVertex_t *v5; // eax
  int v7; // eax
  float t; // xmm0_4
  int v9; // esi
  PreTessPatchVertex_t *m_pPreTessPatchVertices; // eax
  bool v11; // zf
  float uDelta; // [esp+14h] [ebp-14h]
  int iVertex; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  float uStart; // [esp+24h] [ebp-4h]
  float vStart; // [esp+30h] [ebp+8h]

  v3 = NumDivisionsPerSide + 1;
  this->m_NumPreTessVertices = (NumDivisionsPerSide + 1) * (NumDivisionsPerSide + 1);
  v14 = NumDivisionsPerSide + 1;
  v5 = (PreTessPatchVertex_t *)operator new(nSize: 40 * v3 * v3);
  this->m_pPreTessPatchVertices = v5;
  if ( v5 == nullptr )
    return 0;
  vStart = 0.0;
  v7 = 0;
  uDelta = 1.0 / (float)NumDivisionsPerSide;
  if ( v3 > 0 )
  {
    v15 = v3;
    while ( 1 )
    {
      t = 0.0;
      v9 = v7;
      uStart = 0.0;
      iVertex = v3 + v7;
      do
      {
        m_pPreTessPatchVertices = this->m_pPreTessPatchVertices;
        m_pPreTessPatchVertices[v9].m_UV.x = t;
        m_pPreTessPatchVertices[v9].m_UV.y = vStart;
        this->m_pPreTessPatchVertices[v9].m_BasisU.x = CubicBasis0(t);
        this->m_pPreTessPatchVertices[v9].m_BasisU.y = CubicBasis1(t: uStart);
        this->m_pPreTessPatchVertices[v9].m_BasisU.z = CubicBasis2(t: uStart);
        this->m_pPreTessPatchVertices[v9].m_BasisU.w = CubicBasis3(t: uStart);
        this->m_pPreTessPatchVertices[v9].m_BasisV.x = CubicBasis0(t: vStart);
        this->m_pPreTessPatchVertices[v9].m_BasisV.y = CubicBasis1(t: vStart);
        this->m_pPreTessPatchVertices[v9].m_BasisV.z = CubicBasis2(t: vStart);
        this->m_pPreTessPatchVertices[v9].m_BasisV.w = CubicBasis3(t: vStart);
        t = uStart + uDelta;
        ++v9;
        --v3;
        uStart = uStart + uDelta;
      }
      while ( v3 != 0 );
      v11 = v15-- == 1;
      vStart = uDelta + vStart;
      if ( v11 )
        break;
      v3 = v14;
      v7 = iVertex;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CAA0
// Name: public: bool CSubDMesh::CreatePreTessPatch(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::CreatePreTessPatch(CSubDMesh *this, int NumDivisionsPerSide)
{
  char result; // al

  result = CSubDMesh::FillIBForPreTessPatch(this, NumDivisionsPerSide);
  if ( result != 0 )
    return CSubDMesh::FillVBForPreTessPatch(this, NumDivisionsPerSide);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CAD0
// Name: public: void CUtlMemory<struct OptimizedModel::Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<OptimizedModel::Vertex_t,int>::Grow(CUtlMemory<OptimizedModel::Vertex_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  OptimizedModel::Vertex_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 9 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (OptimizedModel::Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (OptimizedModel::Vertex_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CB60
// Name: ComputeACCPatchControlPoints
// Source: json
//------------------------------------------------------------------------------
void __fastcall ComputeACCPatchControlPoints(
        Vector4D *pos,
        Vector4D *tanV,
        CUtlVector<OptimizedModel::SubD_Face_t,CUtlMemory<OptimizedModel::SubD_Face_t,int> > *patches,
        __m128 *vertices,
        Vector4D *tanU)
{
  int m_Size; // eax
  Vector4D *v6; // ebx
  int v7; // edx
  OptimizedModel::SubD_Face_t *v8; // eax
  TopologyIndexStruct tIdx; // [esp+4h] [ebp-88h] BYREF
  TopologyIndexStruct v10; // [esp+40h] [ebp-4Ch]
  int v11; // [esp+7Ch] [ebp-10h]
  int v12; // [esp+80h] [ebp-Ch]
  Vector4D *v13; // [esp+84h] [ebp-8h]
  unsigned int v14; // [esp+88h] [ebp-4h]

  m_Size = patches->m_Size;
  v6 = tanU;
  if ( m_Size != 0 )
  {
    v7 = (char *)tanV - (char *)tanU;
    v14 = 0;
    v13 = pos;
    v11 = v7;
    v12 = m_Size;
    while ( 1 )
    {
      v8 = &patches->m_Memory.m_pMemory[v14 / 0x12C];
      v10.vtx1RingSize = v8->vtx1RingSize;
      v10.vtx1RingCenterQuadOffset = v8->vtx1RingCenterQuadOffset;
      v10.valences = v8->valences;
      v10.bndVtx = v8->bndVtx;
      v10.bndEdge = v8->bndEdge;
      v10.cornerVtx = v8->cornerVtx;
      v10.loopGapAngle = v8->loopGapAngle;
      v10.nbCornerVtx = v8->nbCornerVtx;
      v10.edgeBias = v8->edgeBias;
      v10.oneRing = v8->oneRing;
      v10.vUV0 = v8->vUV0;
      v10.vUV1 = v8->vUV1;
      v10.vUV2 = v8->vUV2;
      v10.vUV3 = v8->vUV3;
      tIdx = v10;
      ComputeACCAllPatches(
        pPos: vertices,
        quad: &tIdx,
        Pos: v13,
        TanU: v6,
        TanV: (Vector4D *)((char *)v6 + v7),
        bRegularPatch: false);
      v14 += 300;
      v13 += 16;
      v6 += 12;
      if ( --v12 == 0 )
        break;
      v7 = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CC70
// Name: public: void CSubDMesh::UpdateSubDPatches(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::UpdateSubDPatches(CSubDMesh *this, bool cornerCorrection, bool accGeometryTangents)
{
  Vector4D *m_pPatchScratchACCU; // ebx
  Vector4D *m_pPatchScratchACCPos; // edi
  Vector4D *pPatchScratchACCV; // [esp+Ch] [ebp-4h]

  m_pPatchScratchACCU = this->m_pPatchScratchACCU;
  m_pPatchScratchACCPos = this->m_pPatchScratchACCPos;
  pPatchScratchACCV = this->m_pPatchScratchACCV;
  set_CornerCorrection(v: cornerCorrection);
  set_ShowACCGeometryTangents(v: accGeometryTangents);
  ComputeACCPatchControlPoints(
    pos: m_pPatchScratchACCPos,
    tanV: pPatchScratchACCV,
    patches: &this->m_SubDPatches,
    vertices: this->m_VertexPositions,
    tanU: m_pPatchScratchACCU);
}

//------------------------------------------------------------------------------
// Address: 0x0041CCC0
// Name: private: bool CSubDMesh::CreateTriangleList(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::CreateTriangleList(CSubDMesh *this)
{
  int m_Size; // edi
  Vector *v3; // eax
  unsigned int v5; // ecx
  OptimizedModel::SubD_Face_t *v6; // eax
  Vector *p_m_vecPosition; // edi
  Vector *m_pTriangleVertList; // edx
  Vector *v9; // edx
  Vector *v10; // edi
  Vector *v11; // edx
  Vector *v12; // edi
  Vector *v13; // edi
  Vector *v14; // edx
  Vector *v15; // edx
  Vector *v16; // edi
  Vector *v17; // eax
  Vector *v18; // edx
  bool v19; // zf
  int v20; // [esp+8h] [ebp-8h]
  int v21; // [esp+Ch] [ebp-4h]

  m_Size = this->m_SubDPatches.m_Size;
  this->m_NumTriangles = 2 * m_Size;
  v3 = (Vector *)operator new(nSize: 72 * m_Size);
  this->m_pTriangleVertList = v3;
  if ( v3 == nullptr )
    return 0;
  if ( m_Size != 0 )
  {
    v21 = 0;
    v5 = 3;
    v20 = m_Size;
    do
    {
      v6 = &this->m_SubDPatches.m_Memory.m_pMemory[v21];
      p_m_vecPosition = &this->m_pStudioVertices[v6->vtxIDs[vLookup[0]]].m_vecPosition;
      m_pTriangleVertList = this->m_pTriangleVertList;
      m_pTriangleVertList[v5 - 3].x = p_m_vecPosition->x;
      *((float *)&m_pTriangleVertList[v5 - 2] - 2) = p_m_vecPosition->y;
      *((float *)&m_pTriangleVertList[v5 - 2] - 1) = p_m_vecPosition->z;
      v9 = &this->m_pStudioVertices[v6->vtxIDs[dword_521204]].m_vecPosition;
      v10 = &this->m_pTriangleVertList[v5 - 2];
      v10->x = v9->x;
      v10->y = v9->y;
      v10->z = v9->z;
      v11 = &this->m_pStudioVertices[v6->vtxIDs[dword_521208]].m_vecPosition;
      v12 = &this->m_pTriangleVertList[v5 - 1];
      v12->x = v11->x;
      v12->y = v11->y;
      v12->z = v11->z;
      v13 = &this->m_pStudioVertices[v6->vtxIDs[dword_52120C]].m_vecPosition;
      v14 = this->m_pTriangleVertList;
      v14[v5].x = v13->x;
      v14[v5].y = v13->y;
      v14[v5].z = v13->z;
      v15 = &this->m_pStudioVertices[v6->vtxIDs[dword_521210]].m_vecPosition;
      v16 = &this->m_pTriangleVertList[v5 + 1];
      v16->x = v15->x;
      v16->y = v15->y;
      v16->z = v15->z;
      v17 = &this->m_pStudioVertices[v6->vtxIDs[dword_521214]].m_vecPosition;
      v18 = &this->m_pTriangleVertList[v5 + 2];
      v18->x = v17->x;
      ++v21;
      v18->y = v17->y;
      v5 += 6;
      v19 = v20-- == 1;
      v18->z = v17->z;
    }
    while ( !v19 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041CE60
// Name: private: bool CSubDMesh::CreatePatchRenderBuffer(struct IDirect3DDevice9 __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSubDMesh::CreatePatchRenderBuffer(CSubDMesh *this, IDirect3DDevice9 *pd3dDevice)
{
  IDirect3DDevice9 *v2; // edi
  IDirect3DDevice9_vtbl *v3; // edx
  int v5; // ebx
  IDirect3DVertexBuffer9 *m_pPatchRenderBuffer; // eax
  int v8; // ecx
  int v9; // edx
  char *v10; // eax
  Vector2D *p_m_vecTexCoord; // edi
  double v12; // st7
  int v13; // edx
  mstudiovertex_t *m_pStudioVertices; // ebx
  float v15; // xmm0_4
  PatchRenderVertex_t *v16; // ecx
  int v17; // edx
  mstudiovertex_t *v18; // ebx
  PatchRenderVertex_t *v19; // ecx
  int v20; // edx
  mstudiovertex_t *v21; // ebx
  int v22; // ecx
  int v23; // edx
  mstudiovertex_t *v24; // ebx
  int v25; // ecx
  int v26; // edx
  mstudiovertex_t *v27; // ebx
  int v28; // ebx
  int v29; // ecx
  int v30; // eax
  PatchRenderVertex_t *v31; // ecx
  Vector4D *v32; // eax
  double w; // st7
  IDirect3DDevice9_vtbl *v34; // ecx
  HRESULT (__stdcall *CreateVertexDeclaration)(IDirect3DDevice9 *, const _D3DVERTEXELEMENT9 *, IDirect3DVertexDeclaration9 **); // eax
  _D3DVERTEXELEMENT9 paramvertexDecl[4]; // [esp+Ch] [ebp-38h] BYREF
  int v37; // [esp+2Ch] [ebp-18h]
  PatchRenderVertex_t *v38; // [esp+30h] [ebp-14h]
  unsigned int NumPatches; // [esp+34h] [ebp-10h]
  int v40; // [esp+38h] [ebp-Ch]
  unsigned int v41; // [esp+3Ch] [ebp-8h]
  PatchRenderVertex_t *pVertices; // [esp+40h] [ebp-4h] BYREF

  v2 = pd3dDevice;
  v3 = pd3dDevice->__vftable;
  NumPatches = this->m_SubDPatches.m_Size;
  v5 = 0;
  if ( v3->CreateVertexBuffer(
         this: pd3dDevice,
         a2: 216 * NumPatches,
         a3: 0,
         a4: 0,
         a5: D3DPOOL_MANAGED,
         a6: &this->m_pPatchRenderBuffer,
         a7: nullptr) < 0 )
    return false;
  m_pPatchRenderBuffer = this->m_pPatchRenderBuffer;
  pVertices = nullptr;
  if ( m_pPatchRenderBuffer->Lock(this: m_pPatchRenderBuffer, a2: 0, a3: 0, a4: (void **)&pVertices, a5: 0) < 0 )
    return false;
  if ( NumPatches != 0 )
  {
    v41 = 1;
    v40 = 0;
    do
    {
      v8 = vLookup_0[0];
      v9 = 2 * vLookup_0[0];
      v10 = (char *)this->m_SubDPatches.m_Memory.m_pMemory + v5;
      p_m_vecTexCoord = &this->m_pStudioVertices[*(unsigned __int16 *)&v10[2 * vLookup_0[0] + 2]].m_vecTexCoord;
      v38 = pVertices;
      pVertices->TexUV = *p_m_vecTexCoord;
      pVertices->PatchUV.x = UVs[v8][0];
      pVertices->PatchUV.y = flt_52121C[2 * v8];
      pVertices->TanU = this->m_tanU._Myfirst[*(unsigned __int16 *)&v10[v9 + 2]];
      v12 = (double)v41;
      *(float *)&v37 = v12;
      pVertices->PatchID = v12;
      v13 = dword_52123C;
      m_pStudioVertices = this->m_pStudioVertices;
      ++pVertices;
      v38 = (PatchRenderVertex_t *)(2 * dword_52123C);
      v15 = *(float *)&v37;
      pVertices->TexUV = m_pStudioVertices[*(unsigned __int16 *)&v10[2 * dword_52123C + 2]].m_vecTexCoord;
      pVertices->PatchUV.x = UVs[v13][0];
      v16 = v38;
      pVertices->PatchUV.y = flt_52121C[2 * v13];
      pVertices->TanU = this->m_tanU._Myfirst[*(unsigned __int16 *)&v10[(_DWORD)v16 + 2]];
      pVertices->PatchID = v12;
      v17 = dword_521240;
      v18 = this->m_pStudioVertices;
      ++pVertices;
      v38 = (PatchRenderVertex_t *)(2 * dword_521240);
      pVertices->TexUV = v18[*(unsigned __int16 *)&v10[2 * dword_521240 + 2]].m_vecTexCoord;
      pVertices->PatchUV.x = UVs[v17][0];
      v19 = v38;
      pVertices->PatchUV.y = flt_52121C[2 * v17];
      pVertices->TanU = this->m_tanU._Myfirst[*(unsigned __int16 *)&v10[(_DWORD)v19 + 2]];
      pVertices->PatchID = v15;
      v20 = dword_521244;
      ++pVertices;
      v21 = this->m_pStudioVertices;
      v37 = 2 * dword_521244;
      pVertices->TexUV = v21[*(unsigned __int16 *)&v10[2 * dword_521244 + 2]].m_vecTexCoord;
      pVertices->PatchUV.x = UVs[v20][0];
      v22 = v37;
      pVertices->PatchUV.y = flt_52121C[2 * v20];
      pVertices->TanU = this->m_tanU._Myfirst[*(unsigned __int16 *)&v10[v22 + 2]];
      pVertices->PatchID = v15;
      v23 = dword_521248;
      v24 = this->m_pStudioVertices;
      ++pVertices;
      v37 = 2 * dword_521248;
      pVertices->TexUV = v24[*(unsigned __int16 *)&v10[2 * dword_521248 + 2]].m_vecTexCoord;
      pVertices->PatchUV.x = UVs[v23][0];
      v25 = v37;
      pVertices->PatchUV.y = flt_52121C[2 * v23];
      pVertices->TanU = this->m_tanU._Myfirst[*(unsigned __int16 *)&v10[v25 + 2]];
      pVertices->PatchID = v15;
      v26 = dword_52124C;
      v27 = this->m_pStudioVertices;
      ++pVertices;
      v37 = 2 * dword_52124C;
      pVertices->TexUV = v27[*(unsigned __int16 *)&v10[2 * dword_52124C + 2]].m_vecTexCoord;
      v28 = v40;
      pVertices->PatchUV.x = UVs[v26][0];
      v29 = v37;
      pVertices->PatchUV.y = flt_52121C[2 * v26];
      v30 = *(unsigned __int16 *)&v10[v29 + 2];
      v31 = pVertices;
      v32 = &this->m_tanU._Myfirst[v30];
      v5 = v28 + 300;
      v40 = v5;
      pVertices->TanU.x = v32->x;
      v31->TanU.y = v32->y;
      v31->TanU.z = v32->z;
      w = v32->w;
      ++v41;
      v31->TanU.w = w;
      pVertices->PatchID = v15;
      ++pVertices;
      --NumPatches;
    }
    while ( NumPatches != 0 );
    v2 = pd3dDevice;
  }
  this->m_pPatchRenderBuffer->Unlock(this: this->m_pPatchRenderBuffer);
  v34 = v2->__vftable;
  *(_DWORD *)&paramvertexDecl[0].Stream = 0;
  CreateVertexDeclaration = v34->CreateVertexDeclaration;
  *(_DWORD *)&paramvertexDecl[0].Type = 3;
  *(_DWORD *)&paramvertexDecl[1].Stream = 0x100000;
  *(_DWORD *)&paramvertexDecl[1].Type = 327683;
  *(_DWORD *)&paramvertexDecl[2].Stream = 0x200000;
  *(_DWORD *)&paramvertexDecl[2].Type = 17104896;
  *(_DWORD *)&paramvertexDecl[3].Stream = 255;
  *(_DWORD *)&paramvertexDecl[3].Type = 17;
  return CreateVertexDeclaration(this: v2, a2: paramvertexDecl, a3: &this->m_pPRBDecl) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D250
// Name: public: bool CSubDMesh::RenderMeshToUVandIDTexture(struct IDirect3DDevice9 __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSubDMesh::RenderMeshToUVandIDTexture@<al>(
        CSubDMesh *this@<ecx>,
        int a2@<ebx>,
        IDirect3DDevice9 *pd3dDevice,
        int Width,
        int Height,
        int GutterSize)
{
  IDirect3DDevice9 *v6; // esi
  unsigned int v9; // ebx
  IDirect3DDevice9 v10; // ecx
  HRESULT (__stdcall *SetViewport)(IDirect3DDevice9 *, const _D3DVIEWPORT9 *); // eax
  int v12; // eax
  int v13; // ebx
  bool v14; // cc
  HRESULT (__stdcall *SetVertexShaderConstantF)(IDirect3DDevice9 *, unsigned int, const float *, unsigned int); // eax
  HRESULT (__stdcall *CreateTexture)(IDirect3DDevice9 *, unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DPOOL, IDirect3DTexture9 **, void **); // edx
  _D3DVIEWPORT9 vp; // [esp+B8h] [ebp-44h] BYREF
  float vOffsets[4]; // [esp+D0h] [ebp-2Ch] BYREF
  float v20; // [esp+E0h] [ebp-1Ch]
  int v; // [esp+E4h] [ebp-18h]
  int u; // [esp+E8h] [ebp-14h]
  IDirect3DTexture9 *pScratchTexture; // [esp+ECh] [ebp-10h] BYREF
  unsigned int nTotalRes; // [esp+F0h] [ebp-Ch]
  IDirect3DSurface9 *pRenderSurface1; // [esp+F4h] [ebp-8h] BYREF
  IDirect3DSurface9 *pRenderSurface0; // [esp+F8h] [ebp-4h] BYREF

  v6 = pd3dDevice;
  if ( !CSubDMesh::CreatePatchRenderBuffer(this, pd3dDevice) || !CSubDMesh::CompileShaders(this, pd3dDevice: v6) )
    return 0;
  v9 = Height;
  if ( CSubDMesh::CreateUVandIDTexture(this, pd3dDevice: v6, Width, Height) && v6->BeginScene(this: v6) >= 0 )
  {
    ((void (__stdcall *)(IDirect3DDevice9 *, IDirect3DVertexShader9 *, int))v6->SetVertexShader)(
      a1: v6,
      a2: this->m_pVS,
      a3: a2);
    v6->SetPixelShader(this: v6, a2: this->m_pPS);
    v10.__vftable = v6->__vftable;
    vp.X = 0;
    vp.Y = 0;
    vp.Width = Width;
    SetViewport = v10.SetViewport;
    vp.MinZ = 0.0;
    vp.Height = v9;
    vp.MaxZ = 1.0;
    SetViewport(this: v6, a2: &vp);
    v6->SetRenderState(this: v6, a2: D3DRS_ZENABLE, a3: 0);
    v6->SetRenderState(this: v6, a2: D3DRS_ZFUNC, a3: 8u);
    v6->SetRenderState(this: v6, a2: D3DRS_CULLMODE, a3: 1u);
    v6->SetStreamSource(this: v6, a2: 0, a3: this->m_pPatchRenderBuffer, a4: 0, a5: 36u);
    v6->SetVertexDeclaration(this: v6, a2: this->m_pPRBDecl);
    nTotalRes = Height * Width;
    v12 = 0;
    v13 = 0;
    v = 0;
    if ( this->m_NumTextureTilesV <= 0 )
    {
LABEL_13:
      ((void (__cdecl *)(IDirect3DDevice9 *))v6->EndScene)(a1: v6);
      CSubDMesh::DestroyRenderData(this);
      return 1;
    }
    while ( 1 )
    {
      v14 = this->m_NumTextureTilesU <= 0;
      u = 0;
      if ( !v14 )
        break;
LABEL_12:
      v = ++v12;
      if ( v12 >= this->m_NumTextureTilesV )
        goto LABEL_13;
    }
    v20 = (float)v12;
    while ( 1 )
    {
      SetVertexShaderConstantF = v6->SetVertexShaderConstantF;
      vOffsets[0] = (float)u;
      vOffsets[1] = v20;
      vOffsets[2] = 0.0;
      vOffsets[3] = 0.0;
      ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD, float *))SetVertexShaderConstantF)(a1: v6, a2: 0, a3: vOffsets);
      pRenderSurface0 = nullptr;
      pRenderSurface1 = nullptr;
      this->m_pPatchUVandIDRT->GetSurfaceLevel(this: this->m_pPatchUVandIDRT, a2: 0, a3: &pRenderSurface0);
      this->m_pPatchTanURT->GetSurfaceLevel(this: this->m_pPatchTanURT, a2: 0, a3: &pRenderSurface1);
      v6->SetRenderTarget(this: v6, a2: 0, a3: pRenderSurface0);
      v6->SetRenderTarget(this: v6, a2: 1u, a3: pRenderSurface1);
      v6->SetDepthStencilSurface(this: v6, a2: nullptr);
      ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD, _DWORD, int, _DWORD, int, _DWORD))v6->Clear)(
        a1: v6,
        a2: 0,
        a3: 0,
        a4: 1,
        a5: 0,
        a6: 1065353216,
        a7: 0);
      v6->DrawPrimitive(this: v6, a2: D3DPT_TRIANGLELIST, a3: 0, a4: 2 * this->m_SubDPatches.m_Size);
      this->m_ppPatchUVTextureTile[v13] = (Vector2D *)operator new(nSize: 8 * nTotalRes);
      this->m_ppPatchIDTextureTile[v13] = (unsigned int *)operator new(nSize: 4 * nTotalRes);
      this->m_ppPatchTanUTextureTile[v13] = (Vector4D *)operator new(nSize: 16 * nTotalRes);
      CreateTexture = v6->CreateTexture;
      pd3dDevice = nullptr;
      pScratchTexture = nullptr;
      if ( CreateTexture(
             this: v6,
             a2: Width,
             a3: Height,
             a4: 1u,
             a5: 0,
             a6: D3DFMT_A32B32G32R32F,
             a7: D3DPOOL_SYSTEMMEM,
             a8: &pScratchTexture,
             a9: nullptr) < 0 )
        break;
      ((void (__stdcall *)(IDirect3DTexture9 *, _DWORD, IDirect3DDevice9 **, int))pScratchTexture->GetSurfaceLevel)(
        a1: pScratchTexture,
        a2: 0,
        a3: &pd3dDevice,
        a4: 1);
      D3DXLoadSurfaceFromSurface(
        a1: (struct IDirect3DSurface9 *)pd3dDevice,
        a2: nullptr,
        a3: nullptr,
        a4: pRenderSurface0,
        a5: nullptr,
        a6: nullptr,
        a7: 1u,
        a8: 0);
      CSubDMesh::CopyFromSurface(
        this,
        pSurf: (IDirect3DSurface9 *)pd3dDevice,
        pPatchUVTexture: this->m_ppPatchUVTextureTile[v13],
        pPatchIDTexture: this->m_ppPatchIDTextureTile[v13],
        Width,
        Height);
      D3DXLoadSurfaceFromSurface(
        a1: (struct IDirect3DSurface9 *)pd3dDevice,
        a2: nullptr,
        a3: nullptr,
        a4: pRenderSurface1,
        a5: nullptr,
        a6: nullptr,
        a7: 1u,
        a8: 0);
      CSubDMesh::CopyFromSurface(
        this,
        pSurf: (IDirect3DSurface9 *)pd3dDevice,
        pPatchTanTexture: this->m_ppPatchTanUTextureTile[v13],
        Width,
        (Vector4D *)Height);
      pRenderSurface0->Release(this: pRenderSurface0);
      pRenderSurface1->Release(this: pRenderSurface1);
      pd3dDevice->Release(this: pd3dDevice);
      pScratchTexture->Release(this: pScratchTexture);
      CSubDMesh::GutterMapBits(this, iTile: v13++, Width, Height, GutterSize);
      if ( ++u >= this->m_NumTextureTilesU )
      {
        v12 = v;
        goto LABEL_12;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041D600
// Name: public: void CSubDMesh::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::Destroy(CSubDMesh *this)
{
  unsigned int v2; // ebx
  Vector4D *m_pPatchScratchACCPos; // eax
  Vector4D *m_pPatchScratchACCU; // eax
  Vector4D *m_pPatchScratchACCV; // eax
  __m128 *m_VertexPositions; // eax
  Vector2D *m_pHardEdgeBuffer; // eax
  unsigned int v8; // edi

  v2 = 0;
  if ( this->m_pStudioVertices != nullptr )
  {
    free(pMem: this->m_pStudioVertices);
    this->m_pStudioVertices = nullptr;
  }
  if ( this->m_pTriangleVertList != nullptr )
  {
    free(pMem: this->m_pTriangleVertList);
    this->m_pTriangleVertList = nullptr;
    this->m_NumTriangles = 0;
  }
  m_pPatchScratchACCPos = this->m_pPatchScratchACCPos;
  if ( m_pPatchScratchACCPos != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pPatchScratchACCPos & 0xFFFFFFFC) - 4));
    this->m_pPatchScratchACCPos = nullptr;
  }
  m_pPatchScratchACCU = this->m_pPatchScratchACCU;
  if ( m_pPatchScratchACCU != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pPatchScratchACCU & 0xFFFFFFFC) - 4));
    this->m_pPatchScratchACCU = nullptr;
  }
  m_pPatchScratchACCV = this->m_pPatchScratchACCV;
  if ( m_pPatchScratchACCV != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_pPatchScratchACCV & 0xFFFFFFFC) - 4));
    this->m_pPatchScratchACCV = nullptr;
  }
  m_VertexPositions = this->m_VertexPositions;
  if ( m_VertexPositions != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((unsigned int)m_VertexPositions & 0xFFFFFFFC) - 4));
    this->m_VertexPositions = nullptr;
  }
  m_pHardEdgeBuffer = this->m_pHardEdgeBuffer;
  this->m_NumHardEdges = 0;
  if ( m_pHardEdgeBuffer != nullptr )
  {
    free(pMem: m_pHardEdgeBuffer);
    this->m_pHardEdgeBuffer = nullptr;
  }
  v8 = this->m_NumTextureTilesU * this->m_NumTextureTilesV;
  if ( this->m_ppPatchUVTextureTile != nullptr )
  {
    if ( v8 != 0 )
    {
      do
        free(pMem: this->m_ppPatchUVTextureTile[v2++]);
      while ( v2 < v8 );
    }
    free(pMem: this->m_ppPatchUVTextureTile);
    this->m_ppPatchUVTextureTile = nullptr;
    v2 = 0;
  }
  if ( this->m_ppPatchIDTextureTile != nullptr )
  {
    if ( v8 != 0 )
    {
      do
        free(pMem: this->m_ppPatchIDTextureTile[v2++]);
      while ( v2 < v8 );
    }
    free(pMem: this->m_ppPatchIDTextureTile);
    this->m_ppPatchIDTextureTile = nullptr;
    v2 = 0;
  }
  if ( this->m_ppPatchTanUTextureTile != nullptr )
  {
    if ( v8 != 0 )
    {
      do
        free(pMem: this->m_ppPatchTanUTextureTile[v2++]);
      while ( v2 < v8 );
    }
    free(pMem: this->m_ppPatchTanUTextureTile);
    this->m_ppPatchTanUTextureTile = nullptr;
  }
  if ( this->m_pPreTessPatchIndices != nullptr )
  {
    free(pMem: this->m_pPreTessPatchIndices);
    this->m_pPreTessPatchIndices = nullptr;
  }
  if ( this->m_pPreTessPatchVertices != nullptr )
  {
    free(pMem: this->m_pPreTessPatchVertices);
    this->m_pPreTessPatchVertices = nullptr;
  }
  this->m_NumTextureTilesU = 0;
  this->m_NumTextureTilesV = 0;
  this->m_SubDPatches.m_Size = 0;
  CSubDMesh::DestroyRenderData(this);
}

//------------------------------------------------------------------------------
// Address: 0x0041D7B0
// Name: public: CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>>::~CUtlVector<struct OptimizedModel::Vertex_t,class CUtlMemory<struct OptimizedModel::Vertex_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::~CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(
        CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *this)
{
  OptimizedModel::Orientation *m_pMemory; // eax

  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D840
// Name: public: OptimizedModel::COptimizeSubDBuilder::~COptimizeSubDBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OptimizedModel::COptimizeSubDBuilder::~COptimizeSubDBuilder(OptimizedModel::COptimizeSubDBuilder *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_IndexRemapTable; // esi
  int *m_pMemory; // eax

  p_m_IndexRemapTable = &this->m_IndexRemapTable;
  this->m_IndexRemapTable.m_Size = 0;
  if ( this->m_IndexRemapTable.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_IndexRemapTable->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_IndexRemapTable->m_Memory.m_pMemory);
      p_m_IndexRemapTable->m_Memory.m_pMemory = nullptr;
    }
    p_m_IndexRemapTable->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_IndexRemapTable->m_Memory.m_pMemory;
  p_m_IndexRemapTable->m_pElements = p_m_IndexRemapTable->m_Memory.m_pMemory;
  if ( p_m_IndexRemapTable->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_IndexRemapTable->m_Memory.m_pMemory = nullptr;
    }
    p_m_IndexRemapTable->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D8D0
// Name: public: bool CSubDMesh::RenderHardEdgesToTexture(struct IDirect3DDevice9 __near *,int,int,float,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::RenderHardEdgesToTexture(
        CSubDMesh *this,
        IDirect3DDevice9 *pd3dDevice,
        int Width,
        int Height,
        float fLineWidth,
        char *pszFileName)
{
  struct IDirect3DDevice9 *v6; // esi
  int v7; // edi
  HRESULT (__stdcall *CreateTexture)(IDirect3DDevice9 *, unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DPOOL, IDirect3DTexture9 **, void **); // edx
  HRESULT (__stdcall *v11)(IDirect3DDevice9 *, unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DPOOL, IDirect3DTexture9 **, void **); // edx
  HRESULT (__stdcall *v12)(IDirect3DDevice9 *, unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, _D3DPOOL, IDirect3DTexture9 **, void **); // edx
  IDirect3DDevice9_vtbl *v13; // ecx
  HRESULT (__stdcall *SetViewport)(IDirect3DDevice9 *, const _D3DVIEWPORT9 *); // eax
  int v15; // eax
  HRESULT (__stdcall *SetVertexShaderConstantF)(IDirect3DDevice9 *, unsigned int, const float *, unsigned int); // edx
  float v17; // xmm3_4
  float v18; // xmm4_4
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  CP4File *v22; // edi
  bool (__thiscall *Add)(CP4File *); // eax
  void (__thiscall *dtr_CP4File)(CP4File *); // eax
  char szOutFile[260]; // [esp+F0h] [ebp-17Ch] BYREF
  _D3DVIEWPORT9 vp; // [esp+1F4h] [ebp-78h] BYREF
  float vOffsets[4]; // [esp+20Ch] [ebp-60h] BYREF
  Vector2D Edge[2]; // [esp+21Ch] [ebp-50h] BYREF
  _D3DLOCKED_RECT LockedRect; // [esp+22Ch] [ebp-40h] BYREF
  float v30; // [esp+234h] [ebp-38h]
  float v31; // [esp+238h] [ebp-34h]
  float v32; // [esp+23Ch] [ebp-30h]
  float v33; // [esp+240h] [ebp-2Ch]
  IDirect3DTexture9 *pCopyTexture; // [esp+244h] [ebp-28h] BYREF
  IDirect3DTexture9 *pRTTexture; // [esp+248h] [ebp-24h] BYREF
  int v; // [esp+24Ch] [ebp-20h]
  IDirect3DSurface9 *pLocalSurface; // [esp+250h] [ebp-1Ch] BYREF
  int u; // [esp+254h] [ebp-18h]
  CP4AutoAddFile autop4; // [esp+258h] [ebp-14h]
  IDirect3DTexture9 *pSaveTexture; // [esp+25Ch] [ebp-10h] BYREF
  int v41; // [esp+268h] [ebp-4h]

  v6 = pd3dDevice;
  v7 = 0;
  CreateTexture = pd3dDevice->CreateTexture;
  pRTTexture = nullptr;
  if ( CreateTexture(
         this: pd3dDevice,
         a2: Width,
         a3: Height,
         a4: 1u,
         a5: 1u,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_DEFAULT,
         a8: &pRTTexture,
         a9: nullptr) < 0 )
    return 0;
  v11 = v6->CreateTexture;
  pCopyTexture = nullptr;
  if ( v11(
         this: v6,
         a2: Width,
         a3: Height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_SYSTEMMEM,
         a8: &pCopyTexture,
         a9: nullptr) < 0 )
    return 0;
  v12 = v6->CreateTexture;
  pSaveTexture = nullptr;
  if ( v12(
         this: v6,
         a2: Width,
         a3: Height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_L8,
         a7: D3DPOOL_SYSTEMMEM,
         a8: &pSaveTexture,
         a9: nullptr) < 0 )
    return 0;
  if ( v6->BeginScene(this: v6) < 0 )
    return 0;
  v13 = v6->__vftable;
  vp.Width = Width;
  vp.Height = Height;
  SetViewport = v13->SetViewport;
  vp.MinZ = 0.0;
  vp.X = 0;
  vp.Y = 0;
  vp.MaxZ = 1.0;
  SetViewport(this: v6, a2: &vp);
  v6->SetRenderState(this: v6, a2: D3DRS_ZENABLE, a3: 0);
  v6->SetRenderState(this: v6, a2: D3DRS_ZFUNC, a3: 8u);
  v6->SetRenderState(this: v6, a2: D3DRS_CULLMODE, a3: 1u);
  pd3dDevice = nullptr;
  if ( D3DXCreateLine(a1: v6, a2: (int)&pd3dDevice) < 0 )
    return 0;
  ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD))pd3dDevice->SetCursorPosition)(
    a1: pd3dDevice,
    a2: LODWORD(fLineWidth));
  ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD))pd3dDevice->CreateAdditionalSwapChain)(a1: pd3dDevice, a2: 0);
  v15 = 0;
  for ( v = 0; v15 < this->m_NumTextureTilesV; v = v15 )
  {
    u = 0;
    if ( this->m_NumTextureTilesU > 0 )
    {
      v33 = (float)v15;
      do
      {
        SetVertexShaderConstantF = v6->SetVertexShaderConstantF;
        v30 = (float)u;
        vOffsets[0] = (float)u;
        vOffsets[1] = v33;
        vOffsets[2] = 0.0;
        vOffsets[3] = 0.0;
        SetVertexShaderConstantF(this: v6, a2: 0, a3: vOffsets, a4: 1u);
        fLineWidth = 0.0;
        pRTTexture->GetSurfaceLevel(this: pRTTexture, a2: 0, a3: (IDirect3DSurface9 **)&fLineWidth);
        v6->SetRenderTarget(this: v6, a2: 0, a3: (IDirect3DSurface9 *)LODWORD(fLineWidth));
        v6->SetDepthStencilSurface(this: v6, a2: nullptr);
        ((void (__stdcall *)(struct IDirect3DDevice9 *, _DWORD, _DWORD, int, int, int, _DWORD))v6->Clear)(
          a1: v6,
          a2: 0,
          a3: 0,
          a4: 1,
          a5: -1,
          a6: 1065353216,
          a7: 0);
        pd3dDevice->GetAvailableTextureMem(this: pd3dDevice);
        if ( this->m_NumHardEdges > 0 )
        {
          v17 = (float)Width;
          v18 = (float)Height;
          v31 = (float)Width;
          v32 = (float)Height;
          autop4.m_spImpl.m_p = nullptr;
          while ( 1 )
          {
            v19 = (float *)((char *)&this->m_pHardEdgeBuffer->x + (unsigned int)autop4.m_spImpl.m_p);
            v20 = 1.0 - (float)(v19[1] - v33);
            Edge[0].x = v17 * (float)(*v19 - v30);
            Edge[0].y = v18 * v20;
            v21 = v18 * (float)(1.0 - (float)(v19[3] - v33));
            Edge[1].x = v17 * (float)(v19[2] - v30);
            Edge[1].y = v21;
            ((void (__stdcall *)(IDirect3DDevice9 *, Vector2D *, int, int))pd3dDevice->EvictManagedResources)(
              a1: pd3dDevice,
              a2: Edge,
              a3: 2,
              a4: -16777216);
            autop4.m_spImpl.m_p = (CP4File *)((char *)autop4.m_spImpl.m_p + 16);
            if ( ++v7 >= this->m_NumHardEdges )
              break;
            v17 = v31;
            v18 = v32;
          }
        }
        ((void (__stdcall *)(IDirect3DDevice9 *))pd3dDevice->Present)(a1: pd3dDevice);
        pLocalSurface = nullptr;
        pCopyTexture->GetSurfaceLevel(this: pCopyTexture, a2: 0, a3: &pLocalSurface);
        v6->GetRenderTargetData(this: v6, a2: (IDirect3DSurface9 *)LODWORD(fLineWidth), a3: pLocalSurface);
        pSaveTexture->LockRect(this: pSaveTexture, a2: 0, a3: &LockedRect, a4: nullptr, a5: 0);
        CSubDMesh::CopyFromSurface(
          this,
          pSurf: pLocalSurface,
          pEdgeTexture: (unsigned __int8 *)LockedRect.pBits,
          Width,
          Height,
          DestPitch: LockedRect.Pitch);
        pSaveTexture->UnlockRect(this: pSaveTexture, a2: 0);
        sprintf_s(string: szOutFile, sizeInBytes: 0x104u, format: "%s_edge_U%d_V%d.tga", pszFileName, u, v);
        D3DXSaveTextureToFileA(a1: szOutFile, a2: D3DXIFF_TGA, a3: (int)pSaveTexture, a4: nullptr);
        v22 = CP4Factory::AccessFile(this: g_p4factory, szFilename: szOutFile);
        autop4.m_spImpl.m_p = v22;
        Add = v22->Add;
        v41 = 0;
        Add(this: v22);
        dtr_CP4File = v22->dtr_CP4File;
        v41 = -1;
        ((void (__thiscall *)(CP4File *, int))dtr_CP4File)(a1: v22, a2: 1);
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)LODWORD(fLineWidth) + 8))(a1: LODWORD(fLineWidth));
        pLocalSurface->Release(this: pLocalSurface);
        v7 = 0;
        ++u;
      }
      while ( u < this->m_NumTextureTilesU );
      v15 = v;
    }
    ++v15;
  }
  v6->EndScene(this: v6);
  pRTTexture->Release(this: pRTTexture);
  pCopyTexture->Release(this: pCopyTexture);
  pSaveTexture->Release(this: pSaveTexture);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041DD20
// Name: public: CSubDMesh::CSubDMesh(void)
// Source: json
//------------------------------------------------------------------------------
CSubDMesh *__thiscall CSubDMesh::CSubDMesh(CSubDMesh *this)
{
  this->m_SubDPatches.m_Memory.m_pMemory = nullptr;
  this->m_SubDPatches.m_Memory.m_nAllocationCount = 0;
  this->m_SubDPatches.m_Memory.m_nGrowSize = 0;
  this->m_SubDPatches.m_Size = 0;
  this->m_SubDPatches.m_pElements = nullptr;
  this->m_pStudioVertices = nullptr;
  this->m_tanU._Myfirst = nullptr;
  this->m_tanU._Mylast = nullptr;
  this->m_tanU._Myend = nullptr;
  this->m_NumTriangles = 0;
  this->m_pTriangleVertList = nullptr;
  this->m_VertexPositions = nullptr;
  this->m_pPatchScratchACCPos = nullptr;
  this->m_pPatchScratchACCU = nullptr;
  this->m_pPatchScratchACCV = nullptr;
  this->m_NumHardEdges = 0;
  this->m_pHardEdgeBuffer = nullptr;
  this->m_NumTextureTilesU = 0;
  this->m_NumTextureTilesV = 0;
  this->m_ppPatchUVTextureTile = nullptr;
  this->m_ppPatchIDTextureTile = nullptr;
  this->m_ppPatchTanUTextureTile = nullptr;
  this->m_pPreTessPatchIndices = nullptr;
  this->m_pPreTessPatchVertices = nullptr;
  this->m_pPatchRenderBuffer = nullptr;
  this->m_pPatchUVandIDRT = nullptr;
  this->m_pPatchTanURT = nullptr;
  this->m_pPRBDecl = nullptr;
  this->m_pVS = nullptr;
  this->m_pPS = nullptr;
  FillTables();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041DDD0
// Name: public: CSubDMesh::~CSubDMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubDMesh::~CSubDMesh(CSubDMesh *this)
{
  OptimizedModel::SubD_Face_t *m_pMemory; // eax

  CSubDMesh::Destroy(this);
  if ( this->m_tanU._Myfirst != nullptr )
    free(pMem: this->m_tanU._Myfirst);
  this->m_tanU._Myfirst = nullptr;
  this->m_tanU._Mylast = nullptr;
  this->m_tanU._Myend = nullptr;
  this->m_SubDPatches.m_Size = 0;
  if ( this->m_SubDPatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SubDPatches.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SubDPatches.m_Memory.m_pMemory);
      this->m_SubDPatches.m_Memory.m_pMemory = nullptr;
    }
    this->m_SubDPatches.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_SubDPatches.m_Memory.m_pMemory;
  this->m_SubDPatches.m_pElements = this->m_SubDPatches.m_Memory.m_pMemory;
  if ( this->m_SubDPatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_SubDPatches.m_Memory.m_pMemory = nullptr;
    }
    this->m_SubDPatches.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DE80
// Name: private: bool CSubDMesh::CreateHardEdgeBuffer(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSubDMesh::CreateHardEdgeBuffer(CSubDMesh *this)
{
  Vector2D *Mylast; // eax
  CSubDMesh *v2; // edx
  Vector2D *Myfirst; // ebx
  int m_Size; // ecx
  int v5; // edi
  mstudiovertex_t *m_pStudioVertices; // ecx
  mstudiovertex_t *v7; // edx
  float *p_x; // edi
  int v9; // edi
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // esi
  unsigned int v13; // esi
  double y; // st7
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // esi
  unsigned int v18; // esi
  Vector2D *v19; // eax
  float *v20; // edi
  int v21; // edi
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // esi
  unsigned int v25; // esi
  double v26; // st7
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // esi
  int v31; // edi
  Vector2D *v32; // eax
  CSubDMesh *v33; // esi
  int v35; // edx
  int v36; // edx
  unsigned int v37; // edi
  float *p_y; // eax
  Vector2D *m_pHardEdgeBuffer; // ecx
  char *v40; // edx
  float *v41; // ecx
  int v42; // ecx
  char *v43; // ecx
  Vector2D *v44; // eax
  int v45; // ecx
  double x; // st7
  OptimizedModel::SubD_Face_t Face; // [esp+Ch] [ebp-160h]
  int e; // [esp+138h] [ebp-34h]
  int NumPatches; // [esp+13Ch] [ebp-30h]
  int i; // [esp+140h] [ebp-2Ch]
  mstudiovertex_t *v1; // [esp+144h] [ebp-28h]
  std::vector<Vector2D> LineList; // [esp+148h] [ebp-24h] BYREF
  CSubDMesh *v53; // [esp+158h] [ebp-14h]
  int NumLinePoints; // [esp+15Ch] [ebp-10h]
  int v55; // [esp+168h] [ebp-4h]

  Mylast = nullptr;
  v2 = this;
  Myfirst = nullptr;
  v53 = this;
  memset(&LineList, 0, 12);
  m_Size = this->m_SubDPatches.m_Size;
  v55 = 0;
  NumPatches = m_Size;
  i = 0;
  if ( m_Size <= 0 )
    goto LABEL_60;
  NumLinePoints = 0;
  while ( 2 )
  {
    Face = *(OptimizedModel::SubD_Face_t *)((char *)v2->m_SubDPatches.m_Memory.m_pMemory + NumLinePoints);
    v5 = 0;
    e = 0;
    while ( 1 )
    {
      if ( Face.bndEdge[v5] == 0 )
        goto LABEL_58;
      m_pStudioVertices = v2->m_pStudioVertices;
      v7 = &m_pStudioVertices[Face.vtxIDs[(v5 + 1) % 4]];
      p_x = &m_pStudioVertices[Face.vtxIDs[v5]].m_vecTexCoord.x;
      v1 = v7;
      if ( p_x >= (float *)Mylast || Myfirst > (Vector2D *)p_x )
      {
        if ( Mylast == LineList._Myend )
        {
          v15 = Mylast - Myfirst;
          if ( v15 > 0x1FFFFFFE )
            goto LABEL_64;
          v16 = v15 + 1;
          v17 = LineList._Myend - Myfirst;
          if ( v16 > v17 )
          {
            if ( 0x1FFFFFFF - (v17 >> 1) >= v17 )
              v18 = (v17 >> 1) + v17;
            else
              v18 = 0;
            if ( v18 < v16 )
              v18 = v16;
            std::vector<Vector2D>::reserve(this: &LineList, _Count: v18);
            Mylast = LineList._Mylast;
            Myfirst = LineList._Myfirst;
            v7 = v1;
          }
        }
        if ( Mylast != nullptr )
        {
          Mylast->x = *p_x;
          y = p_x[1];
          goto LABEL_31;
        }
      }
      else
      {
        v9 = ((char *)p_x - (char *)Myfirst) >> 3;
        if ( Mylast == LineList._Myend )
        {
          v10 = Mylast - Myfirst;
          if ( v10 > 0x1FFFFFFE )
            goto LABEL_64;
          v11 = v10 + 1;
          v12 = LineList._Myend - Myfirst;
          if ( v11 > v12 )
          {
            if ( 0x1FFFFFFF - (v12 >> 1) >= v12 )
              v13 = (v12 >> 1) + v12;
            else
              v13 = 0;
            if ( v13 < v11 )
              v13 = v11;
            std::vector<Vector2D>::reserve(this: &LineList, _Count: v13);
            Mylast = LineList._Mylast;
            Myfirst = LineList._Myfirst;
            v7 = v1;
          }
        }
        if ( Mylast != nullptr )
        {
          Mylast->x = Myfirst[v9].x;
          y = Myfirst[v9].y;
LABEL_31:
          Mylast->y = y;
        }
      }
      v19 = Mylast + 1;
      v20 = &v7->m_vecTexCoord.x;
      LineList._Mylast = v19;
      if ( &v7->m_vecTexCoord >= v19 || Myfirst > (Vector2D *)v20 )
      {
        if ( v19 == LineList._Myend )
        {
          v27 = v19 - Myfirst;
          if ( v27 > 0x1FFFFFFE )
LABEL_64:
            std::_Xlength_error(_Message: "vector<T> too long");
          v28 = v27 + 1;
          v29 = LineList._Myend - Myfirst;
          if ( v28 > v29 )
          {
            if ( 0x1FFFFFFF - (v29 >> 1) >= v29 )
              v30 = (v29 >> 1) + v29;
            else
              v30 = 0;
            if ( v30 < v28 )
              v30 = v28;
            std::vector<Vector2D>::reserve(this: &LineList, _Count: v30);
            v19 = LineList._Mylast;
            Myfirst = LineList._Myfirst;
          }
        }
        if ( v19 == nullptr )
          goto LABEL_57;
        v19->x = *v20;
        v26 = v20[1];
      }
      else
      {
        v21 = ((char *)v20 - (char *)Myfirst) >> 3;
        if ( v19 == LineList._Myend )
        {
          v22 = v19 - Myfirst;
          if ( v22 > 0x1FFFFFFE )
            goto LABEL_64;
          v23 = v22 + 1;
          v24 = LineList._Myend - Myfirst;
          if ( v23 > v24 )
          {
            if ( 0x1FFFFFFF - (v24 >> 1) >= v24 )
              v25 = (v24 >> 1) + v24;
            else
              v25 = 0;
            if ( v25 < v23 )
              v25 = v23;
            std::vector<Vector2D>::reserve(this: &LineList, _Count: v25);
            v19 = LineList._Mylast;
            Myfirst = LineList._Myfirst;
          }
        }
        if ( v19 == nullptr )
          goto LABEL_57;
        v19->x = Myfirst[v21].x;
        v26 = Myfirst[v21].y;
      }
      v19->y = v26;
LABEL_57:
      v5 = e;
      Mylast = v19 + 1;
      LineList._Mylast = Mylast;
LABEL_58:
      e = ++v5;
      if ( v5 >= 4 )
        break;
      v2 = v53;
    }
    NumLinePoints += 300;
    if ( ++i < NumPatches )
    {
      v2 = v53;
      continue;
    }
    break;
  }
LABEL_60:
  v31 = Mylast - Myfirst;
  NumLinePoints = v31;
  v32 = (Vector2D *)operator new(nSize: 8 * v31);
  v33 = v53;
  v53->m_pHardEdgeBuffer = v32;
  if ( v32 != nullptr )
  {
    v35 = 0;
    if ( v31 >= 4 )
    {
      i = -4 - (_DWORD)Myfirst;
      v36 = -20 - (_DWORD)Myfirst;
      v37 = ((unsigned int)(v31 - 4) >> 2) + 1;
      v1 = (mstudiovertex_t *)(4 - (_DWORD)Myfirst);
      p_y = &Myfirst[2].y;
      NumPatches = -20 - (_DWORD)Myfirst;
      v53 = (CSubDMesh *)(4 * v37);
      while ( 1 )
      {
        m_pHardEdgeBuffer = v33->m_pHardEdgeBuffer;
        v40 = (char *)p_y + v36;
        *(float *)&v40[(_DWORD)m_pHardEdgeBuffer] = *(p_y - 5);
        p_y += 8;
        *(float *)&v40[(_DWORD)m_pHardEdgeBuffer + 4] = *(p_y - 12);
        v41 = (float *)((char *)&v33->m_pHardEdgeBuffer[1].x + (unsigned int)v40);
        *v41 = *(p_y - 11);
        v41[1] = *(p_y - 10);
        v42 = (int)v33->m_pHardEdgeBuffer + i;
        *(float *)((char *)p_y + v42 - 32) = *(p_y - 9);
        *(float *)((char *)p_y + v42 - 28) = *(p_y - 8);
        v43 = (char *)v1 + (unsigned int)v33->m_pHardEdgeBuffer;
        --v37;
        *(float *)((char *)p_y + (_DWORD)v43 - 32) = *(p_y - 7);
        *(float *)((char *)p_y + (_DWORD)v43 - 28) = *(p_y - 6);
        if ( v37 == 0 )
          break;
        v36 = NumPatches;
      }
      v35 = (int)v53;
      v31 = NumLinePoints;
    }
    for ( ; v35 < v31; v44[v45].y = Myfirst[v45].y )
    {
      v44 = v33->m_pHardEdgeBuffer;
      v45 = v35;
      x = Myfirst[v35++].x;
      v44[v45].x = x;
    }
    v33->m_NumHardEdges = v31 / 2;
    if ( Myfirst != nullptr )
      free(pMem: Myfirst);
    return 1;
  }
  else
  {
    if ( Myfirst != nullptr )
      free(pMem: Myfirst);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E240
// Name: public: bool CSubDMesh::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CSubDMesh::Load@<al>(CSubDMesh *this@<ecx>, int a2@<ebp>, const char *strOBJFileName)
{
  CSubDMesh *v3; // esi
  int v4; // edi
  int v5; // ecx
  OBJ_VERTEX **v6; // edi
  int v7; // eax
  unsigned int v8; // eax
  int m_nGrowSize; // ecx
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  OptimizedModel::SubD_Face_t *m_pMemory; // edx
  int v13; // ecx
  OptimizedModel::SubD_Face_t *v14; // eax
  std::vector<OBJ_VERTEX> *v15; // edi
  mstudiovertex_t *v16; // eax
  void *v18; // eax
  unsigned int v19; // ecx
  float v20; // xmm4_4
  int v21; // edi
  int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  __m128 v25; // xmm3
  mstudiovertex_t *m_pStudioVertices; // eax
  int *v27; // ecx
  int v28; // eax
  mstudiovertex_t *v29; // ecx
  int v30; // eax
  int p_m_vecNormal; // ecx
  double v32; // st7
  _DWORD *v33; // eax
  double v34; // st7
  int v35; // eax
  mstudiovertex_t *v36; // ecx
  mstudiovertex_t *v37; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  Vector4D *Mylast; // ecx
  const mstudio_meshvertexdata_t *v41; // eax
  Vector4D *Myfirst; // edx
  const mstudio_meshvertexdata_t *v43; // eax
  float *p_x; // ecx
  int v45; // eax
  float v46; // xmm0_4
  int v47; // eax
  int v48; // edi
  Vector2D **v49; // eax
  int v50; // ecx
  unsigned int **v51; // eax
  int v52; // ecx
  Vector4D **v53; // eax
  OptimizedModel::Vertex_t *v54; // ecx
  int v55; // edx
  signed int v56; // edi
  OptimizedModel::Vertex_t *v57; // edi
  char *v58; // eax
  char v59; // cl
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *m_vtxList; // eax
  std::vector<unsigned int> *v61; // eax
  char TriangleList; // al
  _BYTE v63[300]; // [esp+14h] [ebp-324h]
  mstudiomodel_t Model; // [esp+150h] [ebp-1E8h] BYREF
  std::vector<OBJ_VERTEX> *v65; // [esp+1E4h] [ebp-154h]
  mstudiomesh_t Mesh; // [esp+1E8h] [ebp-150h] BYREF
  OptimizedModel::COptimizeSubDBuilder builder; // [esp+264h] [ebp-D4h] BYREF
  CObjLoader objLoader; // [esp+288h] [ebp-B0h] BYREF
  char v69; // [esp+2D4h] [ebp-64h]
  _BYTE vt[12]; // [esp+2D8h] [ebp-60h] OVERLAPPED
  std::vector<OBJ_VERTEX> *pVertices; // [esp+2E4h] [ebp-54h]
  std::vector<unsigned int> *pIndices; // [esp+2E8h] [ebp-50h] BYREF
  int v73; // [esp+2ECh] [ebp-4Ch]
  int NumVertices; // [esp+2F0h] [ebp-48h]
  CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > vtxList; // [esp+2F4h] [ebp-44h]
  int v76; // [esp+310h] [ebp-28h]
  std::vector<OBJ_VERTEX> *j; // [esp+314h] [ebp-24h]
  const mstudio_meshvertexdata_t *v78[2]; // [esp+318h] [ebp-20h] BYREF
  int i; // [esp+320h] [ebp-18h]
  void *v80; // [esp+324h] [ebp-14h]
  int v81; // [esp+328h] [ebp-10h]
  int v82; // [esp+32Ch] [ebp-Ch]
  void *v83; // [esp+330h] [ebp-8h]
  int v84; // [esp+334h] [ebp-4h] BYREF
  void *retaddr; // [esp+338h] [ebp+0h]

  v82 = a2;
  v83 = retaddr;
  v81 = -1;
  v80 = &_ehhandler__Load_CSubDMesh__QAE_NPBD_Z;
  i = (int)NtCurrentTeb()->NtTib.ExceptionList;
  v78[1] = (const mstudio_meshvertexdata_t *)&v84;
  v3 = this;
  v78[0] = (const mstudio_meshvertexdata_t *)this;
  memset(&builder.m_IndexRemapTable.m_Memory.m_nGrowSize, 0, 12);
  memset(&objLoader.m_Vertices._Mylast, 0, 12);
  memset(&objLoader.m_Indices._Mylast, 0, 12);
  v81 = 0;
  if ( !CObjLoader::LoadObj(
          this: (CObjLoader *)&builder.m_IndexRemapTable.m_Memory.m_nGrowSize,
          pszFileName: strOBJFileName,
          LoadFlags: OBJ_LOAD_QUADS_ONLY,
          bComputeTangents: true) )
    goto LABEL_82;
  v4 = (char *)objLoader.m_Vertices._Myend - (char *)objLoader.m_Vertices._Mylast;
  v5 = *((builder.m_IndexRemapTable.m_Size - builder.m_IndexRemapTable.m_Memory.m_nGrowSize) / -52 != 0
       ? &builder.m_IndexRemapTable.m_Size
       : (int *)4)
     - *((builder.m_IndexRemapTable.m_Size - builder.m_IndexRemapTable.m_Memory.m_nGrowSize) / -52 != 0
       ? &builder.m_IndexRemapTable.m_Memory.m_nGrowSize
       : nullptr);
  *(_DWORD *)vt = (builder.m_IndexRemapTable.m_Size - builder.m_IndexRemapTable.m_Memory.m_nGrowSize) / -52 != 0
                ? &builder.m_IndexRemapTable.m_Memory.m_nGrowSize
                : nullptr;
  LODWORD(v3->m_vecMinBounds.x) = objLoader.m_VertexCache._Mylast;
  LODWORD(v3->m_vecMinBounds.y) = objLoader.m_VertexCache._Myend;
  pVertices = (std::vector<OBJ_VERTEX> *)(v5 / 52);
  v6 = (v4 & 0xFFFFFFFC) != 0 ? &objLoader.m_Vertices._Mylast : nullptr;
  v7 = (char *)v6[1] - (char *)*v6;
  v3->m_vecMinBounds.z = *(float *)&objLoader.m_VertexCache._Alval.std::_Allocator_base<CacheEntry *>;
  v3->m_vecMaxBounds = objLoader.m_vecMinBounds;
  v8 = (unsigned int)(v7 >> 2) >> 2;
  *(_DWORD *)&vt[8] = v6;
  if ( v8 != 0 )
  {
    m_nGrowSize = 0;
    for ( j = (std::vector<OBJ_VERTEX> *)v8; j != nullptr; j = (std::vector<OBJ_VERTEX> *)((char *)j - 1) )
    {
      *(_WORD *)&v63[2] = *(_WORD *)((char *)&(*v6)->pos.x + m_nGrowSize);
      *(_WORD *)&v63[4] = *(_WORD *)((char *)&(*v6)->pos.y + m_nGrowSize);
      *(_WORD *)&v63[8] = *(_WORD *)((char *)&(*v6)->pos.w + m_nGrowSize);
      m_Size = v3->m_SubDPatches.m_Size;
      *(_WORD *)&v63[6] = *(_WORD *)((char *)&(*v6)->pos.z + m_nGrowSize);
      vtxList.m_Memory.m_nGrowSize = m_nGrowSize + 16;
      m_nAllocationCount = v3->m_SubDPatches.m_Memory.m_nAllocationCount;
      v76 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<OptimizedModel::SubD_Face_t,int>::Grow(
          this: &v3->m_SubDPatches.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = v76;
      }
      ++v3->m_SubDPatches.m_Size;
      m_pMemory = v3->m_SubDPatches.m_Memory.m_pMemory;
      v13 = v3->m_SubDPatches.m_Size - m_Size - 1;
      v3->m_SubDPatches.m_pElements = v3->m_SubDPatches.m_Memory.m_pMemory;
      if ( v13 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v76 + 1], src: &m_pMemory[v76], count: 300 * v13);
        m_Size = v76;
      }
      m_nGrowSize = vtxList.m_Memory.m_nGrowSize;
      v14 = &v3->m_SubDPatches.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
      {
        qmemcpy(v14, v63, sizeof(OptimizedModel::SubD_Face_t));
        v6 = *(OBJ_VERTEX ***)&vt[8];
        v3 = (CSubDMesh *)v78[0];
        m_nGrowSize = vtxList.m_Memory.m_nGrowSize;
      }
    }
  }
  v15 = pVertices;
  v16 = (mstudiovertex_t *)operator new(nSize: 48 * (_DWORD)pVertices);
  v3->m_pStudioVertices = v16;
  if ( v16 != nullptr )
  {
    v18 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * (_DWORD)v15 + 19);
    if ( v18 != nullptr )
    {
      v19 = ((unsigned int)v18 + 19) & 0xFFFFFFF0;
      *(_DWORD *)(v19 - 4) = v18;
    }
    else
    {
      v19 = 0;
    }
    v3->m_VertexPositions = (__m128 *)v19;
    if ( v19 == 0 )
    {
      if ( objLoader.m_Indices._Mylast != nullptr )
        free(pMem: objLoader.m_Indices._Mylast);
      memset(&objLoader.m_Indices._Mylast, 0, 12);
      if ( objLoader.m_Vertices._Mylast != nullptr )
        free(pMem: objLoader.m_Vertices._Mylast);
      goto LABEL_16;
    }
    v20 = 0.0;
    objLoader.m_vecMaxBounds.z = 1.0;
    objLoader.m_LoadFlags = 1065353216;
    *(_DWORD *)&vt[4] = 0;
    *(_DWORD *)&vt[8] = 0;
    if ( (int)v15 > 0 )
    {
      v76 = 0;
      v21 = 0;
      vtxList.m_Memory.m_nGrowSize = 0;
      j = pVertices;
      do
      {
        v22 = v76;
        v23 = *(float *)(**(_DWORD **)vt + v76 + 4);
        v24 = *(float *)(**(_DWORD **)vt + v76 + 8);
        v25 = 0;
        v25.m128_f32[0] = *(float *)(**(_DWORD **)vt + v76);
        *(__m128 *)((char *)v3->m_VertexPositions + vtxList.m_Memory.m_nGrowSize) = v25;
        m_pStudioVertices = v3->m_pStudioVertices;
        v27 = *(int **)vt;
        LODWORD(m_pStudioVertices[v21].m_vecPosition.x) = v25.m128_i32[0];
        m_pStudioVertices[v21].m_vecPosition.y = v23;
        m_pStudioVertices[v21].m_vecPosition.z = v24;
        v28 = *v27;
        v29 = v3->m_pStudioVertices;
        v29[v21].m_vecNormal.x = *(float *)(v28 + v22 + 16);
        v30 = v28 + v22 + 16;
        p_m_vecNormal = (int)&v29[v21].m_vecNormal;
        *(float *)(p_m_vecNormal + 4) = *(float *)(v30 + 4);
        v32 = *(float *)(v30 + 8);
        v33 = *(_DWORD **)vt;
        *(float *)(p_m_vecNormal + 8) = v32;
        v34 = *(float *)(*v33 + v22 + 28);
        v35 = *v33 + v22 + 28;
        v36 = v3->m_pStudioVertices;
        v36[v21].m_vecTexCoord.x = v34;
        v36[v21].m_vecTexCoord.y = *(float *)(v35 + 4);
        v37 = v3->m_pStudioVertices;
        x = v37[v21].m_vecTexCoord.x;
        if ( x <= objLoader.m_vecMaxBounds.z )
          objLoader.m_vecMaxBounds.z = v37[v21].m_vecTexCoord.x;
        y = v37[v21].m_vecTexCoord.y;
        if ( y <= *(float *)&objLoader.m_LoadFlags )
          objLoader.m_LoadFlags = LODWORD(v37[v21].m_vecTexCoord.y);
        if ( v20 <= x )
        {
          v20 = x;
          *(float *)&vt[4] = x;
        }
        if ( v20 <= y )
          *(float *)&vt[8] = y;
        else
          *(float *)&vt[8] = v20;
        Mylast = v3->m_tanU._Mylast;
        v41 = (const mstudio_meshvertexdata_t *)(**(_DWORD **)vt + v22 + 36);
        v78[0] = v41;
        if ( v41 >= (const mstudio_meshvertexdata_t *)Mylast || (Myfirst = v3->m_tanU._Myfirst) > (Vector4D *)v41 )
        {
          if ( Mylast == v3->m_tanU._Myend )
          {
            std::vector<Vector4D>::_Reserve(this: &v3->m_tanU, _Count: 1u);
            v20 = *(float *)&vt[4];
            v41 = v78[0];
          }
        }
        else
        {
          v43 = (const mstudio_meshvertexdata_t *)(((char *)v41 - (char *)Myfirst) >> 4);
          v78[0] = v43;
          if ( Mylast == v3->m_tanU._Myend )
          {
            std::vector<Vector4D>::_Reserve(this: &v3->m_tanU, _Count: 1u);
            v20 = *(float *)&vt[4];
            v43 = v78[0];
          }
          v41 = (const mstudio_meshvertexdata_t *)&v3->m_tanU._Myfirst[(_DWORD)v43];
        }
        p_x = &v3->m_tanU._Mylast->x;
        if ( p_x != nullptr )
        {
          *p_x = *(float *)&v41->modelvertexdata;
          p_x[1] = *(float *)v41->numLODVertexes;
          p_x[2] = *(float *)&v41->numLODVertexes[1];
          p_x[3] = *(float *)&v41->numLODVertexes[2];
        }
        v76 += 52;
        ++v3->m_tanU._Mylast;
        vtxList.m_Memory.m_nGrowSize += 16;
        ++v21;
        j = (std::vector<OBJ_VERTEX> *)((char *)j - 1);
      }
      while ( j != nullptr );
    }
    v45 = (int)ceil(X: (float)(v20 - objLoader.m_vecMaxBounds.z));
    v46 = *(float *)&vt[8] - *(float *)&objLoader.m_LoadFlags;
    v3->m_NumTextureTilesU = v45;
    v47 = (int)ceil(X: v46);
    v48 = v47 * v3->m_NumTextureTilesU;
    v3->m_NumTextureTilesV = v47;
    v49 = (Vector2D **)operator new(nSize: 4 * v48);
    v50 = 0;
    v3->m_ppPatchUVTextureTile = v49;
    if ( v49 != nullptr )
    {
      LOBYTE(v50) = (unsigned __int64)(unsigned int)v48 >> 30 != 0;
      v51 = (unsigned int **)operator new(nSize: (4 * v48) | -v50);
      v52 = 0;
      v3->m_ppPatchIDTextureTile = v51;
      if ( v51 != nullptr )
      {
        LOBYTE(v52) = (unsigned __int64)(unsigned int)v48 >> 30 != 0;
        v53 = (Vector4D **)operator new(nSize: (4 * v48) | -v52);
        v3->m_ppPatchTanUTextureTile = v53;
        if ( v53 != nullptr )
        {
          v56 = 4 * v48;
          memset(dst: (unsigned __int8 *)v3->m_ppPatchUVTextureTile, value: 0, count: v56);
          memset(dst: (unsigned __int8 *)v3->m_ppPatchIDTextureTile, value: 0, count: v56);
          memset(dst: (unsigned __int8 *)v3->m_ppPatchTanUTextureTile, value: 0, count: v56);
          v54 = nullptr;
          Model.attachmentindex = (int)v3->m_pStudioVertices;
          LODWORD(Mesh.center.x) = &Model.attachmentindex;
          v55 = 0;
          v65 = pVertices;
          Mesh.material = 0;
          pIndices = nullptr;
          v73 = 0;
          NumVertices = 0;
          vtxList.m_Memory.m_pMemory = nullptr;
          vtxList.m_Memory.m_nAllocationCount = 0;
          LOWORD(v56) = 0;
          LOBYTE(v81) = 1;
          j = nullptr;
          if ( (int)pVertices > 0 )
          {
            while ( 1 )
            {
              LOWORD(objLoader.m_LoadFlags) = v56;
              v57 = v54;
              if ( (int)&v54->boneWeightIndex[1] > v55 )
              {
                CUtlMemory<OptimizedModel::Vertex_t,int>::Grow(
                  this: (CUtlMemory<OptimizedModel::Vertex_t,int> *)&pIndices,
                  num: (int)&v54->boneWeightIndex[-v55 + 1]);
                v54 = vtxList.m_Memory.m_pMemory;
              }
              v54 = (OptimizedModel::Vertex_t *)((char *)v54 + 1);
              vtxList.m_Memory.m_pMemory = v54;
              vtxList.m_Memory.m_nAllocationCount = (int)pIndices;
              if ( (char *)v54 - (char *)v57 - 1 > 0 )
              {
                _V_memmove(
                  dest: (char *)&pIndices->_Myend + 8 * (_DWORD)v57 + (_DWORD)v57 + 1,
                  src: (char *)pIndices + 8 * (_DWORD)v57 + (_DWORD)v57,
                  count: 9 * ((char *)v54 - (char *)v57 - 1));
                v54 = vtxList.m_Memory.m_pMemory;
              }
              v58 = (char *)pIndices + 8 * (_DWORD)v57 + (_DWORD)v57;
              if ( v58 != nullptr )
              {
                v59 = v69;
                *(_QWORD *)v58 = *(_QWORD *)&objLoader.m_vecMaxBounds.z;
                v58[8] = v59;
                v54 = vtxList.m_Memory.m_pMemory;
              }
              v56 = (signed int)&j->_Myfirst + 1;
              j = (std::vector<OBJ_VERTEX> *)v56;
              if ( v56 >= (int)pVertices )
                break;
              v55 = v73;
            }
          }
          v78[0] = (const mstudio_meshvertexdata_t *)&Mesh.center;
          OptimizedModel::COptimizeSubDBuilder::COptimizeSubDBuilder(
            this: (OptimizedModel::COptimizeSubDBuilder *)&Mesh.unused[7],
            subDFaceList: &v3->m_SubDPatches,
            vertexList: (const CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)&pIndices,
            vertexData: v78,
            bIsTagged: false,
            bMendVertices: false);
          LOBYTE(v81) = 2;
          if ( CSubDMesh::CreatePatchesBuffer(this: v3) == 0 )
          {
            v78[0] = (const mstudio_meshvertexdata_t *)&builder.m_vtxList;
            m_vtxList = (CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int> > *)builder.m_vtxList;
            LOBYTE(v81) = 3;
            builder.m_IndexRemapTable.m_Memory.m_pMemory = nullptr;
            if ( builder.m_numPatches >= 0 )
            {
              if ( builder.m_vtxList != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)builder.m_vtxList);
                m_vtxList = nullptr;
                builder.m_vtxList = nullptr;
              }
              builder.m_vtxData = nullptr;
            }
            builder.m_IndexRemapTable.m_Memory.m_nAllocationCount = (int)m_vtxList;
            LOBYTE(v81) = 1;
            if ( builder.m_numPatches >= 0 )
            {
              if ( m_vtxList != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_vtxList);
                builder.m_vtxList = nullptr;
              }
              builder.m_vtxData = nullptr;
            }
            v61 = pIndices;
            LOBYTE(v81) = 4;
            vtxList.m_Memory.m_pMemory = nullptr;
            if ( NumVertices >= 0 )
            {
              if ( pIndices != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pIndices);
                v61 = nullptr;
                pIndices = nullptr;
              }
              v73 = 0;
            }
            vtxList.m_Memory.m_nAllocationCount = (int)v61;
            LOBYTE(v81) = 0;
            if ( NumVertices >= 0 )
            {
              if ( v61 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v61);
                pIndices = nullptr;
              }
              v73 = 0;
            }
            goto LABEL_12;
          }
          if ( CSubDMesh::CreateHardEdgeBuffer(this: v3) != 0 )
          {
            TriangleList = CSubDMesh::CreateTriangleList(this: v3);
            LOBYTE(v81) = 1;
            if ( TriangleList != 0 )
            {
              OptimizedModel::COptimizeSubDBuilder::~COptimizeSubDBuilder(this: (OptimizedModel::COptimizeSubDBuilder *)&Mesh.unused[7]);
              LOBYTE(v81) = 0;
              CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::~CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(this: (CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *)&pIndices);
              CObjLoader::~CObjLoader(this: (CObjLoader *)&builder.m_IndexRemapTable.m_Memory.m_nGrowSize);
              return 1;
            }
          }
          else
          {
            LOBYTE(v81) = 1;
          }
          OptimizedModel::COptimizeSubDBuilder::~COptimizeSubDBuilder(this: (OptimizedModel::COptimizeSubDBuilder *)&Mesh.unused[7]);
          LOBYTE(v81) = 0;
          CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>::~CUtlVector<OptimizedModel::Vertex_t,CUtlMemory<OptimizedModel::Vertex_t,int>>(this: (CUtlVector<OptimizedModel::Orientation,CUtlMemory<OptimizedModel::Orientation,int> > *)&pIndices);
        }
LABEL_82:
        CObjLoader::~CObjLoader(this: (CObjLoader *)&builder.m_IndexRemapTable.m_Memory.m_nGrowSize);
        return 0;
      }
    }
  }
LABEL_12:
  if ( objLoader.m_Indices._Mylast != nullptr )
    free(pMem: objLoader.m_Indices._Mylast);
  memset(&objLoader.m_Indices._Mylast, 0, 12);
  if ( objLoader.m_Vertices._Mylast != nullptr )
    free(pMem: objLoader.m_Vertices._Mylast);
LABEL_16:
  memset(&objLoader.m_Vertices._Mylast, 0, 12);
  if ( builder.m_IndexRemapTable.m_Memory.m_nGrowSize != 0 )
    free(pMem: (void *)builder.m_IndexRemapTable.m_Memory.m_nGrowSize);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C2DE0
// Name: public: void CUtlMemory<struct CacheOptimizedKDNode,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CacheOptimizedKDNode,int>::Grow(CUtlMemory<CacheOptimizedKDNode,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CacheOptimizedKDNode *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CacheOptimizedKDNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CacheOptimizedKDNode *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4480
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int num)
{
  Vector *m_pMemory; // edx
  unsigned int v4; // eax
  Vector *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C44F0
// Name: public: int CUtlVector<struct CacheOptimizedKDNode,class CUtlMemory<struct CacheOptimizedKDNode,int>>::InsertBefore(int,struct CacheOptimizedKDNode const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int>>::InsertBefore(
        CUtlVector<CacheOptimizedKDNode,CUtlMemory<CacheOptimizedKDNode,int> > *this,
        int elem,
        const CacheOptimizedKDNode *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CacheOptimizedKDNode *m_pMemory; // ecx
  int v7; // eax
  CacheOptimizedKDNode *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C4560
// Name: public: int CUtlVector<struct CacheOptimizedTriangle,class CUtlBlockMemory<struct CacheOptimizedTriangle,int>>::InsertBefore(int,struct CacheOptimizedTriangle const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int>>::InsertBefore(
        CUtlVector<CacheOptimizedTriangle,CUtlBlockMemory<CacheOptimizedTriangle,int> > *this,
        int elem,
        const CacheOptimizedTriangle *src)
{
  int m_nBlocks; // ebx
  int m_Size; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  CacheOptimizedTriangle *v10; // eax

  m_nBlocks = this->m_Memory.m_nBlocks;
  m_Size = this->m_Size;
  v6 = ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5) + 1;
  if ( m_Size + 1 > v6 * m_nBlocks )
  {
    v7 = m_Size - v6 * m_nBlocks + 1;
    if ( v7 > 0 )
      CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        this: &this->m_Memory,
        nBlocks: m_nBlocks + (v6 + v7 - 1) / v6);
  }
  v8 = ++this->m_Size - elem - 1;
  this->m_pElements = nullptr;
  if ( v8 > 0 )
  {
    v9 = *((_DWORD *)&this->m_Memory + 2);
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[(elem + 1) >> (v9 >> 27)][(elem + 1) & ((32 * v9) >> 5)],
      src: &this->m_Memory.m_pMemory[elem >> (v9 >> 27)][elem & ((32 * v9) >> 5)],
      count: 48 * v8);
  }
  v10 = &this->m_Memory.m_pMemory[elem >> (*((int *)&this->m_Memory + 2) >> 27)][elem
                                                                               & ((32 * *((_DWORD *)&this->m_Memory + 2)) >> 5)];
  if ( v10 != nullptr )
    *v10 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C4670
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        const Vector *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C9500
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EA2A
// Name: Direct3DCreate9(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
IDirect3D9 *__stdcall Direct3DCreate9(UINT SDKVersion)
{
  return __imp__Direct3DCreate9@4(SDKVersion);
}

//------------------------------------------------------------------------------
// Address: 0x0041EA30
// Name: struct _D3DXFORMAT_INFO const __near * D3DXTex::GetFormatInfo(enum _D3DFORMAT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct _D3DXFORMAT_INFO *__stdcall D3DXTex::GetFormatInfo(D3DXTex *this, enum _D3DFORMAT a2)
{
  const struct _D3DXFORMAT_INFO *result; // eax

  result = (const struct _D3DXFORMAT_INFO *)&unk_4EC650;
  if ( off_521268 <= &unk_4EC650 )
    return (const struct _D3DXFORMAT_INFO *)&unk_4EC628;
  while ( this != *(D3DXTex **)result )
  {
    result = (const struct _D3DXFORMAT_INFO *)((char *)result + 36);
    if ( result >= (const struct _D3DXFORMAT_INFO *)off_521268 )
      return (const struct _D3DXFORMAT_INFO *)&unk_4EC628;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EA5B
// Name: sub_41EA5B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall sub_41EA5B(int a1, int a2)
{
  unsigned int result; // eax
  unsigned int *v3; // esi
  int v4; // edi
  int i; // ebx
  unsigned int v6; // ecx
  unsigned int v7; // edx
  int v8; // [esp+4h] [ebp-4h]

  result = 0;
  if ( dword_4ECE58[5 * *(_DWORD *)(a1 + 4) + *(_DWORD *)(a2 + 4)] == 0 )
    return -1;
  v8 = 0;
  v3 = (unsigned int *)(a1 + 12);
  v4 = a2 - a1;
  for ( i = 5; i != 0; --i )
  {
    v6 = *v3;
    if ( *v3 != 0 )
      ++v8;
    v7 = *(unsigned int *)((char *)v3 + v4);
    if ( v6 >= v7 )
    {
      if ( v6 > v7 )
      {
        if ( v7 != 0 )
          result += (v6 - v7) << 16;
        else
          result += 0x1000000;
      }
    }
    else if ( v6 != 0 )
    {
      result += v7 - v6;
    }
    else
    {
      result += 256;
    }
    ++v3;
  }
  if ( v8 == HIBYTE(result) )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041EAD2
// Name: enum _D3DFORMAT D3DXTex::FindClosestFormat(enum _D3DFORMAT const __near *,struct tagPALETTEENTRY const __near *,struct _D3DXFORMAT_INFO const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DFORMAT __stdcall D3DXTex::FindClosestFormat(
        D3DXTex **this,
        const enum _D3DFORMAT *a2,
        const struct tagPALETTEENTRY *a3,
        const struct _D3DXFORMAT_INFO *a4)
{
  D3DXTex **v4; // eax
  unsigned int v5; // ebx
  const struct _D3DXFORMAT_INFO *v6; // edi
  const struct _D3DXFORMAT_INFO *FormatInfo; // esi
  unsigned int v8; // eax
  D3DXTex *v9; // eax
  enum _D3DFORMAT v11; // [esp+0h] [ebp-Ch]

  v4 = this;
  v5 = -1;
  v6 = (const struct _D3DXFORMAT_INFO *)&unk_4EC628;
  while ( 1 )
  {
    v9 = *v4;
    if ( v9 == nullptr )
      return *(_DWORD *)v6;
    FormatInfo = D3DXTex::GetFormatInfo(this: v9, a2: v11);
    if ( *(_DWORD *)FormatInfo != 0 && (*((_DWORD *)FormatInfo + 1) != 1 || a2 != nullptr) )
      break;
LABEL_11:
    v4 = ++this;
  }
  if ( *a3 != *(_DWORD *)FormatInfo )
  {
    v8 = sub_41EA5B(a1: (int)a3, a2: (int)FormatInfo);
    if ( v8 != -1 && v8 <= v5 && (v8 != v5 || *((_DWORD *)FormatInfo + 2) < *((_DWORD *)v6 + 2)) )
    {
      v5 = v8;
      v6 = FormatInfo;
    }
    goto LABEL_11;
  }
  return (enum _D3DFORMAT)*a3;
}

//------------------------------------------------------------------------------
// Address: 0x0041EB43
// Name: enum _D3DFORMAT D3DXTex::FindClosestDeviceFormat(struct IDirect3DDevice9 __near *,unsigned long,enum _D3DRESOURCETYPE,struct _D3DXFORMAT_INFO const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum _D3DFORMAT __stdcall D3DXTex::FindClosestDeviceFormat(
        D3DXTex *this,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        const struct _D3DXFORMAT_INFO *a5)
{
  unsigned int v5; // ebx
  _DWORD *v6; // edi
  _DWORD *v7; // esi
  unsigned int v8; // eax
  _DWORD v10[76]; // [esp+Ch] [ebp-154h] BYREF
  _BYTE v11[12]; // [esp+13Ch] [ebp-24h] BYREF
  int v12; // [esp+148h] [ebp-18h]
  _BYTE v13[16]; // [esp+14Ch] [ebp-14h] BYREF
  int v14; // [esp+15Ch] [ebp-4h] BYREF

  v14 = 0;
  D3DXDebugMuteInt(a1: 1);
  if ( this != nullptr )
  {
    (*(void (__stdcall **)(D3DXTex *, int *))(*(_DWORD *)this + 24))(a1: this, a2: &v14);
    (*(void (__stdcall **)(D3DXTex *, _DWORD *))(*(_DWORD *)this + 28))(a1: this, a2: v10);
    (*(void (__stdcall **)(D3DXTex *, _DWORD, _BYTE *))(*(_DWORD *)this + 32))(a1: this, a2: 0, a3: v11);
    if ( (a2 & 0x100000) != 0 )
    {
      (*(void (__stdcall **)(D3DXTex *, _BYTE *))(*(_DWORD *)this + 36))(a1: this, a2: v13);
      if ( (v13[12] & 0x20) != 0 )
        a2 |= 0x10u;
    }
  }
  v5 = -1;
  v6 = &unk_4EC628;
  v7 = &unk_4EC650;
  if ( off_521268 > &unk_4EC650 )
  {
    do
    {
      if ( *v7 != 0
        && (v14 == 0
         || (*(int (__stdcall **)(int, _DWORD, _DWORD, int, unsigned int, unsigned int, _DWORD))(*(_DWORD *)v14 + 40))(
              a1: v14,
              a2: v10[1],
              a3: v10[0],
              a4: v12,
              a5: a2,
              a6: a3,
              a7: *v7) >= 0) )
      {
        if ( *a4 == *v7 )
        {
          v6 = v7;
          break;
        }
        if ( v7[8] != 0 )
        {
          v8 = sub_41EA5B(a1: (int)a4, a2: (int)v7);
          if ( v8 != -1 && v8 <= v5 && (v8 != v5 || v7[2] < v6[2]) )
          {
            v5 = v8;
            v6 = v7;
          }
        }
      }
      v7 += 9;
    }
    while ( v7 < (_DWORD *)off_521268 );
  }
  if ( v14 != 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(a1: v14);
    v14 = 0;
  }
  D3DXDebugMuteInt(a1: 0);
  return *v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041EC41
// Name: D3DXLoadSurfaceFromMemory(x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXLoadSurfaceFromMemory(
        struct IDirect3DSurface9 *a1,
        const struct tagPALETTEENTRY *a2,
        struct tagRECT *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        _DWORD *a8,
        unsigned int a9,
        int a10)
{
  int v10; // ebx
  int v11; // eax
  _BYTE v13[72]; // [esp+4h] [ebp-C8h] BYREF
  int v14; // [esp+4Ch] [ebp-80h]
  _BYTE v15[20]; // [esp+58h] [ebp-74h] BYREF
  _DWORD v16[4]; // [esp+6Ch] [ebp-60h] BYREF
  _DWORD v17[17]; // [esp+7Ch] [ebp-50h]
  _BYTE v18[12]; // [esp+C0h] [ebp-Ch] BYREF

  D3DXTex::CBlt::CBlt(this: (D3DXTex::CBlt *)v18);
  D3DXTex::CLockSurface::CLockSurface(a1: v15);
  v10 = 0;
  if ( a1 != nullptr )
  {
    if ( a4 != 0 && a8 != nullptr )
    {
      if ( a9 == -1 )
        a9 = 524292;
      v11 = D3DXTex::CLockSurface::Lock(
              this: (D3DXTex::CLockSurface *)v15,
              a2: (struct D3DX_BLT *)v13,
              a3: a1,
              a4: a2,
              a5: a3,
              a6: 0,
              a7: 0);
      if ( v11 < 0 )
        goto LABEL_10;
      v16[1] = a5;
      v16[2] = a6;
      v16[0] = a4;
      v16[3] = 0;
      v17[0] = *a8;
      v17[1] = a8[1];
      v17[2] = a8[2];
      v17[3] = a8[3];
      v17[4] = 0;
      v17[5] = 1;
      qmemcpy(&v17[6], v17, 24);
      v17[14] = v14;
      v17[15] = a10;
      v17[16] = a7;
      v11 = D3DXTex::CBlt::Blt(
              this: (D3DXTex::CBlt *)v18,
              a2: (struct D3DX_BLT *)v13,
              a3: (struct D3DX_BLT *)v16,
              a4: a9);
      if ( v11 < 0 )
LABEL_10:
        v10 = v11;
    }
    else
    {
      v10 = -2005530516;
    }
  }
  else
  {
    v10 = -2005530516;
  }
  D3DXTex::CLockSurface::~CLockSurface(this: (D3DXTex::CLockSurface *)v15);
  D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v18);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED29
// Name: sub_41ED29
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_41ED29@<eax>(
        D3DXTex *a1@<edx>,
        enum _D3DFORMAT a2@<esi>,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        int *a6,
        unsigned int a7,
        D3DXTex **a8,
        unsigned int a9,
        unsigned int a10)
{
  const struct _D3DXFORMAT_INFO *FormatInfo; // eax
  int v13; // edx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  bool v18; // cc
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edi
  int v23; // eax
  int v24; // ecx
  unsigned int v25; // esi
  unsigned int i; // eax
  unsigned int v27; // ecx
  unsigned int j; // eax
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // eax
  const struct _D3DXFORMAT_INFO *v32; // [esp-4h] [ebp-150h]
  char v33[60]; // [esp+8h] [ebp-144h] BYREF
  int v34; // [esp+44h] [ebp-108h]
  unsigned int v35; // [esp+60h] [ebp-ECh]
  unsigned int v36; // [esp+64h] [ebp-E8h]
  unsigned int v37; // [esp+68h] [ebp-E4h]
  int v38; // [esp+70h] [ebp-DCh]
  unsigned int v39; // [esp+138h] [ebp-14h]
  D3DXTex *ClosestDeviceFormat; // [esp+13Ch] [ebp-10h]
  unsigned int v41; // [esp+140h] [ebp-Ch]
  unsigned int v42; // [esp+144h] [ebp-8h]
  unsigned int v43; // [esp+148h] [ebp-4h]

  if ( a1 == nullptr )
    return -2005530516;
  if ( a7 == -1 )
    a7 = 0;
  if ( (a7 & 0xFFE039EC) != 0 || a9 >= 4 )
    return -2005530516;
  if ( a8 != nullptr )
    ClosestDeviceFormat = *a8;
  else
    ClosestDeviceFormat = nullptr;
  if ( a9 == 3 )
  {
    if ( ClosestDeviceFormat == nullptr )
      ClosestDeviceFormat = (D3DXTex *)21;
  }
  else
  {
    FormatInfo = D3DXTex::GetFormatInfo(this: ClosestDeviceFormat, a2);
    ClosestDeviceFormat = (D3DXTex *)D3DXTex::FindClosestDeviceFormat(
                                       this: a1,
                                       a2: a7,
                                       a3: a10,
                                       a4: FormatInfo,
                                       a5: v32);
    if ( ClosestDeviceFormat == nullptr )
      return -2005530518;
  }
  if ( a3 != nullptr )
    v42 = *a3;
  else
    v42 = -1;
  if ( a4 != nullptr )
    v43 = *a4;
  else
    v43 = -1;
  if ( a5 != nullptr )
    v41 = *a5;
  else
    v41 = -1;
  if ( a6 != nullptr )
    v39 = *a6;
  else
    v39 = -1;
  if ( v42 == -1 )
  {
    if ( v43 == -1 )
    {
      v43 = 256;
      v42 = 256;
      goto LABEL_38;
    }
    v42 = v43;
  }
  else if ( v43 == -1 )
  {
    v43 = v42;
  }
  if ( v42 == 0 )
    v42 = 1;
  if ( v43 == 0 )
    v43 = 1;
LABEL_38:
  if ( a10 == 5 )
  {
    if ( v42 > v43 )
      v43 = v42;
    v42 = v43;
  }
  if ( v41 == -1 || v41 == 0 )
    v41 = 1;
  if ( a9 != 3 )
  {
    (*(void (__stdcall **)(D3DXTex *, char *))(*(_DWORD *)a1 + 28))(a1, a2: v33);
    v13 = v34;
    if ( a10 == 4 )
    {
      v14 = v37;
      if ( v41 > v37 )
        v41 = v37;
      if ( v42 > v37 )
        v42 = v37;
    }
    else
    {
      if ( v42 > v35 )
        v42 = v35;
      if ( v43 > v36 )
        v43 = v36;
      if ( a10 != 3 )
        goto LABEL_65;
      v15 = (v34 & 0x20) != 0 ? 1 : v38;
      if ( v15 == 0 )
        goto LABEL_65;
      if ( v42 > v43 * v15 )
        v42 = v43 * v15;
      v14 = v42 * v15;
    }
    if ( v43 > v14 )
      v43 = v14;
LABEL_65:
    switch ( a10 )
    {
      case 3u:
        v16 = 2;
        break;
      case 4u:
        v16 = 0x40000;
        break;
      case 5u:
        v16 = 0x20000;
        break;
      default:
        v16 = a10;
        break;
    }
    if ( v39 == 1
      && (v34 & 0x100) != 0
      && ClosestDeviceFormat != (D3DXTex *)827611204
      && ClosestDeviceFormat != (D3DXTex *)844388420
      && ClosestDeviceFormat != (D3DXTex *)861165636
      && ClosestDeviceFormat != (D3DXTex *)877942852
      && ClosestDeviceFormat != (D3DXTex *)894720068 )
    {
      v16 = 0;
    }
    if ( (v16 & v34) != 0 )
    {
      v17 = v42;
      v18 = v42 <= 1;
      v42 = 1;
      if ( !v18 )
      {
        do
          v42 *= 2;
        while ( v42 < v17 );
      }
      v19 = v43;
      v18 = v43 <= 1;
      v43 = 1;
      if ( !v18 )
      {
        do
          v43 *= 2;
        while ( v43 < v19 );
      }
      v20 = v41;
      v18 = v41 <= 1;
      v41 = 1;
      if ( !v18 )
      {
        do
          v41 *= 2;
        while ( v41 < v20 );
      }
    }
    goto LABEL_89;
  }
  v13 = v34;
LABEL_89:
  if ( ClosestDeviceFormat == (D3DXTex *)827611204
    || ClosestDeviceFormat == (D3DXTex *)844388420
    || ClosestDeviceFormat == (D3DXTex *)861165636
    || ClosestDeviceFormat == (D3DXTex *)877942852
    || ClosestDeviceFormat == (D3DXTex *)894720068 )
  {
    v21 = (v42 + 3) & 0xFFFFFFFC;
    v22 = (v43 + 3) & 0xFFFFFFFC;
    v42 = v21;
    v43 = v22;
  }
  else
  {
    v21 = v42;
    v22 = v43;
  }
  switch ( a10 )
  {
    case 3u:
      v23 = 0x4000;
      break;
    case 4u:
      v23 = 0x8000;
      break;
    case 5u:
      v23 = 0x10000;
      break;
    default:
      v23 = a10;
      break;
  }
  if ( a9 != 3
    && ((v23 & v13) == 0
     || (v13 & 0x100) != 0 && (((v21 - 1) & v21) != 0 || ((v22 - 1) & v22) != 0 || ((v41 - 1) & v41) != 0)) )
  {
    v39 = 1;
    v24 = 1;
  }
  else
  {
    v25 = 0;
    for ( i = v21; i != 0; ++v25 )
      i >>= 1;
    v27 = 0;
    for ( j = v22; j != 0; ++v27 )
      j >>= 1;
    v29 = v41;
    v30 = 0;
    while ( v29 != 0 )
    {
      v29 >>= 1;
      ++v30;
    }
    v31 = v25;
    if ( v25 <= v27 )
      v31 = v27;
    if ( a10 == 4 && v30 > v31 )
      v31 = v30;
    v24 = v39;
    if ( v39 > v31 || v39 == 0 )
      v24 = v31;
    if ( v24 != 1 && (a7 & 0x400) != 0 )
      v24 = 0;
  }
  if ( a3 != nullptr )
    *a3 = v42;
  if ( a4 != nullptr )
    *a4 = v43;
  if ( a5 != nullptr )
    *a5 = v41;
  if ( a6 != nullptr )
    *a6 = v24;
  if ( a8 != nullptr )
    *a8 = ClosestDeviceFormat;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F0DE
// Name: D3DXCheckTextureRequirements(x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXCheckTextureRequirements@<eax>(
        enum _D3DFORMAT a1@<esi>,
        D3DXTex *a2,
        unsigned int *a3,
        unsigned int *a4,
        int *a5,
        unsigned int a6,
        D3DXTex **a7,
        unsigned int a8)
{
  return sub_41ED29(a1: a2, a2: a1, a3, a4, a5: nullptr, a6: a5, a7: a6, a8: a7, a9: a8, a10: 3u);
}

//------------------------------------------------------------------------------
// Address: 0x0041F105
// Name: D3DXCreateTexture(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCreateTexture(
        D3DXTex *a1,
        int a2,
        int a3,
        int a4,
        enum _D3DFORMAT a5,
        int a6,
        unsigned int a7,
        int a8)
{
  int result; // eax
  enum _D3DFORMAT v9; // esi

  if ( a1 == nullptr || a8 == 0 )
    return -2005530516;
  v9 = a5;
  if ( a5 == (D3DFMT_FORCE_DWORD|0x80000000) )
    v9 = D3DFMT_UNKNOWN;
  result = D3DXCheckTextureRequirements(
             a1: v9,
             a2: a1,
             a3: (unsigned int *)&a2,
             a4: (unsigned int *)&a3,
             a5: &a4,
             a6: v9,
             a7: (D3DXTex **)&a6,
             a8: a7);
  if ( result >= 0 )
  {
    result = (*(int (__stdcall **)(D3DXTex *, int, int, int, unsigned __int32, int, unsigned int, int, _DWORD))(*(_DWORD *)a1 + 92))(
               a1,
               a2,
               a3,
               a4,
               a5: v9 & 0xFFE07FFF,
               a6,
               a7,
               a8,
               a9: 0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041F1A1
// Name: D3DXLoadSurfaceFromSurface(x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXLoadSurfaceFromSurface@<eax>(
        int a1@<edi>,
        struct IDirect3DSurface9 *a2,
        const struct tagPALETTEENTRY *a3,
        struct tagRECT *a4,
        struct IDirect3DSurface9 *a5,
        const struct tagPALETTEENTRY *a6,
        struct tagRECT *a7,
        unsigned int a8,
        int a9)
{
  int v9; // esi
  struct IDirect3DSurface9 *v10; // ebx
  int right; // edx
  int bottom; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  int v19; // esi
  int v22[10]; // [esp+4h] [ebp-C8h] BYREF
  int v23[11]; // [esp+2Ch] [ebp-A0h] BYREF
  _BYTE v24[20]; // [esp+58h] [ebp-74h] BYREF
  _BYTE v25[12]; // [esp+6Ch] [ebp-60h] BYREF
  int v26; // [esp+78h] [ebp-54h]
  int v27; // [esp+84h] [ebp-48h]
  int v28; // [esp+88h] [ebp-44h]
  char v29; // [esp+8Ch] [ebp-40h] BYREF
  int v30; // [esp+98h] [ebp-34h]
  int v31; // [esp+A4h] [ebp-28h]
  int v32; // [esp+A8h] [ebp-24h]
  struct tagRECT v33; // [esp+ACh] [ebp-20h] BYREF
  struct tagRECT v34; // [esp+BCh] [ebp-10h] BYREF

  D3DXTex::CLockSurface::CLockSurface(a1: v24);
  if ( a2 != nullptr )
  {
    v10 = a5;
    if ( a5 == nullptr )
    {
      v9 = -2005530516;
      goto LABEL_36;
    }
    a2->GetDesc(this: a2, a2: (_D3DSURFACE_DESC *)v25);
    v10->GetDesc(this: v10, a2: (_D3DSURFACE_DESC *)&v29);
    if ( (unsigned __int16)a8 == 5
      || a9 != 0
      || a3 != a6 && (a3 == nullptr || a6 == nullptr || memcmp(a3, a6, 0x400u) != 0) )
    {
      goto LABEL_26;
    }
    if ( a4 != nullptr )
    {
      v34 = *a4;
      bottom = v34.bottom;
      right = v34.right;
    }
    else
    {
      right = v27;
      bottom = v28;
      v34.left = 0;
      v34.top = 0;
      v34.right = v27;
      v34.bottom = v28;
    }
    if ( a7 != nullptr )
    {
      v33 = *a7;
      v13 = v33.bottom;
      v14 = v33.right;
      bottom = v34.bottom;
    }
    else
    {
      v13 = v32;
      v33.left = 0;
      v33.top = 0;
      v14 = v31;
      v33.right = v31;
      v33.bottom = v32;
    }
    if ( right - v34.left != v14 - v33.left || bottom - v34.top != v13 - v33.top )
    {
LABEL_26:
      v17 = 1;
      if ( a2 == v10 )
        v17 = 65537;
      v18 = D3DXTex::CLockSurface::Lock(
              this: (D3DXTex::CLockSurface *)v24,
              a2: (struct D3DX_BLT *)v22,
              a3: v10,
              a4: a6,
              a5: a7,
              a6: 0,
              a7: v17);
      if ( v18 < 0
        || (v18 = D3DXLoadSurfaceFromMemory(
                    a1: a2,
                    a2: a3,
                    a3: a4,
                    a4: v22[0],
                    a5: v22[1],
                    a6: v22[2],
                    a7: (int)a6,
                    a8: v23,
                    a9: a8,
                    a10: a9)) < 0 )
      {
        v9 = v18;
        goto LABEL_36;
      }
      if ( v30 == 0 && v26 != 0 )
      {
        v10->GetDevice(this: v10, (IDirect3DDevice9 **)&a2);
        v19 = ((int (__stdcall *)(struct IDirect3DSurface9 *))a2->GetDevice)(a1: a2);
        a2->Release(this: a2);
        if ( v19 != 0 )
        {
          v9 = -2005530520;
          goto LABEL_36;
        }
      }
LABEL_35:
      v9 = 0;
      goto LABEL_36;
    }
    ((void (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 **, int))v10->GetDevice)(
      a1: v10,
      a2: &a5,
      a3: a1);
    D3DXDebugMuteInt(a1: 1);
    v15 = -2147467259;
    if ( v26 == 0 )
    {
      if ( v30 != 0 )
      {
        if ( v30 != 2 )
          goto LABEL_25;
        v16 = ((int (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 *, struct tagRECT *, struct IDirect3DSurface9 *, struct tagRECT *))a5->__vftable[1].LockRect)(
                a1: a5,
                a2: v10,
                a3: &v33,
                a4: a2,
                a5: &v34);
      }
      else
      {
        v16 = ((int (__stdcall *)(struct IDirect3DSurface9 *, struct IDirect3DSurface9 *, struct tagRECT *, struct IDirect3DSurface9 *, struct tagRECT *, _DWORD))a5->__vftable[2].QueryInterface)(
                a1: a5,
                a2: v10,
                a3: &v33,
                a4: a2,
                a5: &v34,
                a6: 0);
      }
      v15 = v16;
    }
LABEL_25:
    D3DXDebugMuteInt(a1: 0);
    ((void (__cdecl *)(struct IDirect3DSurface9 *))a5->Release)(a1: a5);
    if ( v15 >= 0 )
      goto LABEL_35;
    goto LABEL_26;
  }
  v9 = -2005530516;
LABEL_36:
  D3DXTex::CLockSurface::~CLockSurface(this: (D3DXTex::CLockSurface *)v24);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0041F451
// Name: sub_41F451
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_41F451(
        void *a1,
        enum _D3DXIMAGE_FILEFORMAT a2,
        int a3,
        const struct tagPALETTEENTRY *a4,
        unsigned int a5)
{
  int v5; // esi
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ebx
  unsigned int *v13; // eax
  D3DXTex::CLockSurface *v14; // esi
  unsigned int *v15; // eax
  D3DXTex::CLockVolume *v16; // esi
  void *v17; // eax
  unsigned int v18; // ecx
  void *v19; // edi
  void *v20; // eax
  int v21; // edi
  D3DXTex::CImage *v22; // eax
  D3DXTex::CImage *v23; // eax
  int v24; // esi
  D3DXTex::CImage *v25; // eax
  D3DXTex::CImage *v26; // eax
  int v27; // esi
  int v28; // eax
  void *v29; // edx
  int v30; // eax
  unsigned int v31; // esi
  _DWORD *v32; // edi
  unsigned int v33; // esi
  _DWORD *v34; // edi
  _BYTE v36[84]; // [esp+8h] [ebp-11Ch] BYREF
  _BYTE v37[84]; // [esp+5Ch] [ebp-C8h] BYREF
  char v38[12]; // [esp+B0h] [ebp-74h] BYREF
  int v39; // [esp+BCh] [ebp-68h]
  char v40[12]; // [esp+CCh] [ebp-58h] BYREF
  int v41; // [esp+D8h] [ebp-4Ch]
  int v42; // [esp+ECh] [ebp-38h]
  int v43; // [esp+F0h] [ebp-34h]
  int v44; // [esp+F4h] [ebp-30h]
  D3DXTex::CImage *v45; // [esp+F8h] [ebp-2Ch]
  D3DXTex::CImage *v46; // [esp+FCh] [ebp-28h]
  unsigned int v47; // [esp+100h] [ebp-24h]
  D3DXTex::CLockSurface *v48; // [esp+104h] [ebp-20h]
  unsigned int v49; // [esp+108h] [ebp-1Ch]
  int v50; // [esp+10Ch] [ebp-18h]
  D3DXTex::CLockVolume *v51; // [esp+110h] [ebp-14h]
  unsigned int v52; // [esp+114h] [ebp-10h]
  void *v53; // [esp+118h] [ebp-Ch]
  int v54; // [esp+11Ch] [ebp-8h]
  void *pMem; // [esp+120h] [ebp-4h]

  D3DXTex::CImage::CImage(this: (D3DXTex::CImage *)v37);
  if ( a1 == nullptr )
  {
    v5 = -2005530516;
    goto LABEL_80;
  }
  v6 = a3;
  if ( a3 == 0 )
  {
LABEL_4:
    v5 = -2005530516;
    goto LABEL_80;
  }
  v7 = (*(int (__stdcall **)(int))(*(_DWORD *)a3 + 40))(a1: a3);
  v42 = v7;
  if ( v7 == 3 )
    goto LABEL_8;
  if ( v7 != 4 )
  {
    if ( v7 != 5 )
      goto LABEL_4;
LABEL_8:
    v8 = *(_DWORD *)v6;
    v50 = v6;
    (*(void (__stdcall **)(int, _DWORD, char *))(v8 + 68))(a1: v6, a2: 0, a3: v40);
    v9 = v41;
    goto LABEL_9;
  }
  v11 = *(_DWORD *)v6;
  v50 = v6;
  (*(void (__stdcall **)(int, _DWORD, char *))(v11 + 68))(a1: v6, a2: 0, a3: v38);
  v9 = v39;
LABEL_9:
  v44 = v9;
  if ( a2 == D3DXIFF_DDS )
  {
    v47 = v7 != 5 ? 1 : 6;
    v10 = (*(int (__stdcall **)(int))(*(_DWORD *)v6 + 52))(a1: v6);
  }
  else
  {
    v10 = 1;
    v47 = 1;
  }
  v12 = v47 * v10;
  v49 = v10;
  pMem = nullptr;
  v53 = nullptr;
  v48 = nullptr;
  v51 = nullptr;
  if ( v7 != 4 )
  {
    v13 = (unsigned int *)operator new(nSize: 20 * v12 + 4);
    if ( v13 != nullptr )
    {
      v14 = (D3DXTex::CLockSurface *)(v13 + 1);
      *v13 = v12;
      `vector constructor iterator'(__t: v13 + 1, __s: 0x14u, __n: v12, __f: D3DXTex::CLockSurface::CLockSurface);
      v48 = v14;
    }
    else
    {
      v48 = nullptr;
    }
    if ( v48 != nullptr )
    {
      v20 = operator new(nSize: 4 * v12);
      pMem = v20;
      if ( v20 != nullptr )
      {
        v18 = 4 * v12;
        v19 = v20;
        goto LABEL_26;
      }
    }
LABEL_82:
    a3 = -2147024882;
    goto LABEL_63;
  }
  v15 = (unsigned int *)operator new(nSize: 4 * v12 + 4);
  if ( v15 != nullptr )
  {
    v16 = (D3DXTex::CLockVolume *)(v15 + 1);
    *v15 = v12;
    `vector constructor iterator'(__t: v15 + 1, __s: 4u, __n: v12, __f: D3DXTex::CLockVolume::CLockVolume);
    v51 = v16;
  }
  else
  {
    v51 = nullptr;
  }
  if ( v51 == nullptr )
    goto LABEL_82;
  v17 = operator new(nSize: 4 * v12);
  v53 = v17;
  if ( v17 == nullptr )
    goto LABEL_82;
  v18 = 4 * v12;
  v19 = v17;
LABEL_26:
  memset(v19, 0, v18);
  v21 = a3;
  v46 = (D3DXTex::CImage *)v37;
  v52 = 0;
  if ( v47 != 0 )
  {
    v43 = 0;
    do
    {
      if ( v52 != 0 )
      {
        v22 = (D3DXTex::CImage *)operator new(nSize: 0x54u);
        if ( v22 != nullptr )
          v23 = (D3DXTex::CImage *)D3DXTex::CImage::CImage(this: v22);
        else
          v23 = nullptr;
        if ( v23 == nullptr )
          goto LABEL_82;
        *((_DWORD *)v46 + 20) = v23;
        v46 = v23;
      }
      v54 = 0;
      v45 = v46;
      if ( v49 != 0 )
      {
        while ( 1 )
        {
          v24 = v54;
          if ( v54 != 0 )
          {
            v25 = (D3DXTex::CImage *)operator new(nSize: 0x54u);
            if ( v25 != nullptr )
              v26 = (D3DXTex::CImage *)D3DXTex::CImage::CImage(this: v25);
            else
              v26 = nullptr;
            if ( v26 == nullptr )
              goto LABEL_82;
            *((_DWORD *)v45 + 19) = v26;
            v45 = v26;
          }
          v27 = v43 + v24;
          if ( v42 == 3 )
            break;
          if ( v42 == 4 )
          {
            v29 = v53;
LABEL_47:
            v28 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v50 + 72))(a1: v50, a2: v54, a3: (int)v29 + 4 * v27);
            goto LABEL_48;
          }
          if ( v42 == 5 )
          {
            v28 = (*(int (__stdcall **)(int, unsigned int, int, char *))(*(_DWORD *)v50 + 72))(
                    a1: v50,
                    a2: v52,
                    a3: v54,
                    a4: (char *)pMem + 4 * v27);
LABEL_48:
            a3 = v28;
          }
          if ( a3 < 0 )
            goto LABEL_63;
          switch ( v42 )
          {
            case 3:
LABEL_53:
              v30 = D3DXTex::CLockSurface::Lock(
                      this: (D3DXTex::CLockSurface *)((char *)v48 + 20 * v27),
                      a2: (struct D3DX_BLT *)v36,
                      a3: *((struct IDirect3DSurface9 **)pMem + v27),
                      a4,
                      a5: nullptr,
                      a6: 0,
                      a7: 1u);
LABEL_54:
              a3 = v30;
              break;
            case 4:
              v30 = D3DXTex::CLockVolume::Lock(
                      this: (D3DXTex::CLockVolume *)((char *)v51 + 4 * v27),
                      a2: (struct D3DX_BLT *)v36,
                      a3: *((struct IDirect3DVolume9 **)v53 + v27),
                      a4,
                      a5: nullptr,
                      a6: 0,
                      a7: 1u);
              goto LABEL_54;
            case 5:
              goto LABEL_53;
            default:
              break;
          }
          if ( a3 < 0 )
            goto LABEL_63;
          a3 = D3DXTex::CImage::Initialize(this: v45, a2: (struct D3DX_BLT *)v36);
          if ( a3 < 0 )
            goto LABEL_63;
          if ( ++v54 >= v49 )
            goto LABEL_58;
        }
        v29 = pMem;
        goto LABEL_47;
      }
LABEL_58:
      ++v52;
      v43 += v49;
    }
    while ( v52 < v47 );
  }
  a3 = D3DXTex::CImage::Save(this: (D3DXTex::CImage *)v37, a2: a1, a3: a2, a4: a5);
  if ( a3 >= 0 )
  {
    if ( v44 == 0 )
    {
      (*(void (__stdcall **)(int, int *))(*(_DWORD *)v21 + 12))(a1: v21, a2: &a3);
      (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 12))(a1: a3);
      (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 8))(a1: a3);
    }
    a3 = 0;
  }
LABEL_63:
  v31 = 0;
  if ( v48 != nullptr )
    D3DXTex::CLockSurface::`vector deleting destructor'(this: v48, a2: 3);
  if ( v51 != nullptr )
    D3DXTex::CLockVolume::`vector deleting destructor'(this: v51, a2: 3);
  if ( pMem != nullptr )
  {
    if ( v12 != 0 )
    {
      do
      {
        v32 = (char *)pMem + 4 * v31;
        if ( *v32 != 0 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v32 + 8))(a1: *v32);
          *v32 = 0;
        }
        ++v31;
      }
      while ( v31 < v12 );
    }
    free(pMem);
  }
  v33 = 0;
  if ( v53 != nullptr )
  {
    if ( v12 != 0 )
    {
      do
      {
        v34 = (char *)v53 + 4 * v33;
        if ( *v34 != 0 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v34 + 8))(a1: *v34);
          *v34 = 0;
        }
        ++v33;
      }
      while ( v33 < v12 );
    }
    free(pMem: v53);
  }
  v5 = a3;
LABEL_80:
  D3DXTex::CImage::~CImage(this: (D3DXTex::CImage *)v37);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041F824
// Name: D3DXSaveTextureToFileA(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXSaveTextureToFileA(void *a1, enum _D3DXIMAGE_FILEFORMAT a2, int a3, const struct tagPALETTEENTRY *a4)
{
  return sub_41F451(a1, a2, a3, a4, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041F840
// Name: D3DXCompileShader(x,x,x,x,x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCompileShader(
        void *a1,
        unsigned int a2,
        struct _D3DXMACRO *a3,
        struct ID3DXInclude *a4,
        char *a5,
        char *a6,
        int a7,
        struct ID3DXBuffer **a8,
        struct ID3DXBuffer **a9,
        struct ID3DXConstantTable **a10)
{
  _BYTE v12[24]; // [esp+Ch] [ebp-370h] BYREF
  std::_System_error_category v13; // [esp+24h] [ebp-358h] BYREF
  _BYTE v14[184]; // [esp+2BCh] [ebp-C0h] BYREF
  struct ID3DXConstantTable *v15; // [esp+374h] [ebp-8h] BYREF
  struct ID3DXBuffer *v16; // [esp+378h] [ebp-4h] BYREF
  int v17; // [esp+3A0h] [ebp+24h]

  v16 = nullptr;
  v15 = nullptr;
  D3DXShader::CPreProcessor::CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  if ( a8 != nullptr )
    *a8 = nullptr;
  if ( a10 != nullptr )
    *a10 = nullptr;
  if ( (a7 & 0xFFFFF9C0) != 0 )
  {
    v17 = -2005530516;
  }
  else
  {
    v17 = D3DXShader::CPreProcessor::InitializeFromMemory(
            this: (D3DXShader::CPreProcessor *)v12,
            a2: a1,
            a3: a2,
            a4: a3,
            a5: a4);
    if ( v17 >= 0 )
    {
      D3DXShader::CCompiler::CCompiler(this: (D3DXShader::CCompiler *)v14);
      v17 = D3DXShader::CCompiler::Compile(
              this: (D3DXShader::CCompiler *)v14,
              a2: (struct D3DXShader::CPreProcessor *)v12,
              a3: nullptr,
              a4: a5,
              a5: 0,
              a6,
              a7: a7 | 0x100,
              a8: &v16,
              a9: &v15);
      if ( v17 >= 0 )
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
        if ( D3DXShader::CTErrors::GetErrorCount(this: &v13) != nullptr )
        {
          v17 = -2005529767;
        }
        else
        {
          if ( a8 != nullptr )
          {
            *a8 = v16;
            v16 = nullptr;
          }
          if ( a10 != nullptr )
          {
            *a10 = v15;
            v15 = nullptr;
          }
        }
      }
      else
      {
        D3DXShader::CCompiler::~CCompiler(this: (D3DXShader::CCompiler *)v14);
      }
    }
  }
  if ( a9 != nullptr )
    D3DXShader::CTErrors::GetErrorBuffer(this: (D3DXShader::CTErrors *)&v13, a2: a9);
  if ( v15 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXConstantTable *))v15->Release)(a1: v15);
    v15 = nullptr;
  }
  if ( v16 != nullptr )
  {
    ((void (__cdecl *)(struct ID3DXBuffer *))v16->Release)(a1: v16);
    v16 = nullptr;
  }
  D3DXShader::CPreProcessor::~CPreProcessor(this: (D3DXShader::CPreProcessor *)v12);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x0041F972
// Name: D3DXFindShaderComment(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXFindShaderComment(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // ebx
  unsigned int v6; // eax
  unsigned int *i; // ecx
  unsigned int v8; // eax
  int v9; // esi
  unsigned int v10; // eax

  if ( a3 != nullptr )
    *a3 = 0;
  v4 = a4;
  if ( a4 != nullptr )
    *a4 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v6 = *a1 & 0xFFFF0000;
  if ( v6 != 1180172288 && v6 != 1415053312 && v6 != 2147352576 && v6 != 2147418112 && v6 != -131072 && v6 != -65536 )
    return -2005529767;
  for ( i = a1 + 1; ; ++i )
  {
    v8 = *i;
    if ( (*i & 0x80000000) == 0 )
    {
      v9 = (unsigned __int16)*i;
      if ( v9 == 0xFFFF )
        return 1;
      if ( v9 == 65534 )
        break;
      if ( (unsigned __int16)*a1 >= 0x200u )
      {
        v10 = HIBYTE(v8) & 0xF;
LABEL_28:
        i += v10;
        goto LABEL_31;
      }
      if ( v9 == 81 )
        i += 5;
    }
LABEL_31:
    v4 = a4;
  }
  v10 = HIWORD(v8) & 0x7FFF;
  if ( v10 <= 1 || a2 != i[1] )
    goto LABEL_28;
  if ( a3 != nullptr )
    *a3 = i + 2;
  if ( v4 != nullptr )
    *v4 = 4 * v10 - 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FA7A
// Name: D3DXGetTargetDescByName(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByName(const char *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // edx
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // [esp+0h] [ebp-4h]

  v3 = 0;
  if ( a1 == nullptr )
    return -2005530516;
  v5 = 44;
  v9 = 44;
  while ( 1 )
  {
    v6 = (v3 + v5) >> 1;
    v7 = strcmp((&off_4ECED0)[3 * v6], a1);
    if ( v7 == 0 )
      break;
    if ( v7 >= 0 )
      v9 = v6;
    else
      v3 = v6 + 1;
    v5 = v9;
    if ( v3 >= v9 )
      return -2147467259;
  }
  v8 = 3 * v6;
  if ( (a2 & dword_4ECED8[v8]) != a2 )
    return -2147467259;
  if ( a3 != nullptr )
  {
    *a3 = (&off_4ECED0)[v8];
    a3[1] = (&off_4ECED0)[v8 + 1];
    a3[2] = (&off_4ECED0)[v8 + 2];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB18
// Name: D3DXGetTargetDescByVersion(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetTargetDescByVersion(int a1, int a2, _DWORD *a3)
{
  int v3; // ecx
  const char *v4; // eax
  int v5; // edx
  char **v7; // esi

  v3 = 44;
  v4 = "vs_3_0";
  while ( 1 )
  {
    v5 = *((_DWORD *)v4 - 4);
    v4 -= 12;
    --v3;
    if ( v5 == a1 && (a2 & *(_DWORD *)v4) == a2 )
      break;
    if ( v4 <= (const char *)dword_4ECED8 )
      return -2147467259;
  }
  if ( a3 != nullptr )
  {
    v7 = &(&off_4ECED0)[3 * v3];
    *a3 = *v7++;
    a3[1] = *v7;
    a3[2] = v7[1];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041FB67
// Name: D3DXGetShaderConstantTable(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXGetShaderConstantTable(unsigned int *a1, D3DXShader::CConstantTable **a2)
{
  D3DXShader::CConstantTable *v2; // esi
  unsigned int v4; // eax
  D3DXShader::CConstantTable *v5; // eax
  int v6; // edi

  v2 = nullptr;
  if ( a2 != nullptr )
    *a2 = nullptr;
  if ( a1 == nullptr || a2 == nullptr )
    return -2005530516;
  v4 = *a1 & 0xFFFF0000;
  if ( v4 != -131072 && v4 != -65536 )
    goto LABEL_14;
  v5 = (D3DXShader::CConstantTable *)operator new(nSize: 0x20u);
  if ( v5 != nullptr )
    v2 = (D3DXShader::CConstantTable *)D3DXShader::CConstantTable::CConstantTable(this: v5);
  if ( v2 == nullptr )
    return -2147024882;
  v6 = D3DXShader::CConstantTable::Initialize(this: v2, a2: a1, a3: nullptr);
  if ( v6 < 0 )
  {
    D3DXShader::CConstantTable::`scalar deleting destructor'(this: v2, a2: 1);
    return v6;
  }
  else
  {
LABEL_14:
    *a2 = v2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FC09
// Name: D3DXCreateLine(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXCreateLine(struct IDirect3DDevice9 *a1, D3DXCore::CLine **a2)
{
  D3DXCore::CLine *v3; // eax
  D3DXCore::CLine *v4; // esi
  int v5; // edi

  if ( a1 == nullptr )
    return -2005530516;
  if ( a2 == nullptr )
    return -2005530516;
  v3 = (D3DXCore::CLine *)operator new(nSize: 0x64u);
  if ( v3 != nullptr )
    v4 = (D3DXCore::CLine *)D3DXCore::CLine::CLine(this: v3);
  else
    v4 = nullptr;
  if ( v4 == nullptr )
    return -2147024882;
  v5 = D3DXCore::CLine::Initialize(this: v4, a2: a1);
  if ( v5 >= 0 )
  {
    *a2 = v4;
    return 0;
  }
  else
  {
    D3DXCore::CLine::`scalar deleting destructor'(this: v4, a2: 1);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FC78
// Name: sub_41FC78
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall sub_41FC78(unsigned __int8 *a1, LPCSTR lpValueName, unsigned __int8 *Type, unsigned int cbData)
{
  LSTATUS v4; // esi
  BOOL result; // eax
  HKEY__ *phkResult; // [esp+0h] [ebp-4h] BYREF

  phkResult = nullptr;
  result = false;
  if ( RegOpenKeyA(hKey: HKEY_LOCAL_MACHINE, lpSubKey: "Software\\Microsoft\\Direct3D", &phkResult) == 0 )
  {
    v4 = RegQueryValueExA(
           hKey: phkResult,
           lpValueName,
           lpReserved: nullptr,
           lpType: (LPDWORD)&Type,
           lpData: Type,
           lpcbData: &cbData);
    RegCloseKey(hKey: phkResult);
    if ( v4 == 0 && Type == a1 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FCD7
// Name: int D3DXDebugMuteInt(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXDebugMuteInt(int a1)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  v4 = dword_5532A8;
  dword_5532A8 = a1;
  if ( DebugSetMute == nullptr && DebugSetMute_0 == nullptr )
  {
    if ( GetModuleHandleA(lpModuleName: "d3d9.dll") != nullptr )
    {
      LibraryA = LoadLibraryA(lpLibFileName: "d3d9.dll");
      if ( LibraryA != nullptr )
        DebugSetMute = (int (__cdecl *)(_DWORD))GetProcAddress(hModule: LibraryA, lpProcName: "DebugSetMute");
    }
    if ( GetModuleHandleA(lpModuleName: "d3d9d.dll") != nullptr )
    {
      v2 = LoadLibraryA(lpLibFileName: "d3d9d.dll");
      if ( v2 != nullptr )
        DebugSetMute_0 = (int (__cdecl *)(_DWORD))GetProcAddress(hModule: v2, lpProcName: "DebugSetMute");
    }
  }
  if ( dword_52126C != -1 )
  {
LABEL_14:
    if ( dword_52126C != 0 )
      return v4;
    goto LABEL_15;
  }
  if ( !sub_41FC78(
          a1: (unsigned __int8 *)4,
          lpValueName: "D3DXDoNotMute",
          Type: (unsigned __int8 *)&dword_52126C,
          cbData: 4u) )
    dword_52126C = 0;
  if ( dword_52126C != 0 )
  {
    dword_52126C = 1;
    goto LABEL_14;
  }
LABEL_15:
  if ( DebugSetMute != nullptr )
    DebugSetMute(a1);
  if ( DebugSetMute_0 != nullptr )
    DebugSetMute_0(a1);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041FDC0
// Name: void D3DXCheckNewDelete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall D3DXCheckNewDelete()
{
  void *v0; // edi
  void *v1; // eax
  void *v2; // ebx
  int v3; // [esp+4h] [ebp-4h]

  if ( dword_5532B4 == 0 )
  {
    dword_5532B4 = 1;
    v3 = 0;
    v0 = operator new(nSize: 0);
    v1 = operator new(nSize: 0);
    v2 = v1;
    if ( v0 == nullptr || v1 == nullptr || v0 == v1 )
      v3 = 1;
    if ( v0 != nullptr )
      free(pMem: v0);
    if ( v2 != nullptr && v2 != v0 )
      free(pMem: v2);
    free(pMem: nullptr);
    if ( v3 != 0 )
    {
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) Overloaded ::new and ::delete operators do not conform to C++ standards:\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) An allocation of zero bytes should return a unique non-null pointer to at\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) least zero bytes. Deletion of a null pointer should quietly do nothing.\r\n");
      OutputDebugStringA(lpOutputString: "D3DX: (WARN) D3DX relies upon this behavior.\r\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FE4F
// Name: public: D3DXTex::CDataCollector::CDataCollector(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXTex::CDataCollector *__thiscall D3DXTex::CDataCollector::CDataCollector(D3DXTex::CDataCollector *this)
{
  D3DXCore::CFile::CFile(this);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041FE6E
// Name: public: long D3DXTex::CDataCollector::Setup(void const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CDataCollector::Setup(
        D3DXTex::CDataCollector *this,
        struct D3DXCore::CBuffer **lpWideCharStr,
        unsigned int a3)
{
  int v3; // ebx
  int result; // eax
  void *v6; // eax

  v3 = 1;
  if ( a3 >= 2 )
  {
    v3 = 2;
    if ( a3 != 2 )
      return -2147467259;
    result = D3DXCore::CBuffer::Create(a1: 0x400u, a2: lpWideCharStr);
    if ( result < 0 )
      return result;
    *((_DWORD *)this + 5) = *lpWideCharStr;
LABEL_9:
    *((_DWORD *)this + 4) = v3;
    return 0;
  }
  v6 = operator new(nSize: 0x10000u);
  *((_DWORD *)this + 6) = v6;
  if ( v6 == nullptr )
    return -2147024882;
  result = D3DXCore::CFile::Create(this, (LPCWCH)lpWideCharStr, a3: a3 == 1);
  if ( result >= 0 )
    goto LABEL_9;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041FEE8
// Name: public: long D3DXTex::CDataCollector::WriteData(void const __near *,unsigned long,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CDataCollector::WriteData(
        D3DXTex::CDataCollector *this,
        char *lpBuffer,
        unsigned int a3,
        LPDWORD lpNumberOfBytesWritten)
{
  int v5; // eax
  int v6; // eax
  int result; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  int v10; // edx
  unsigned int v11; // eax
  char *v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // esi
  unsigned int v16; // [esp+Ch] [ebp-4h]
  char *lpBuffera; // [esp+18h] [ebp+8h]

  v16 = 0;
  v5 = *((_DWORD *)this + 4);
  if ( v5 == 0 )
    return 0;
  v6 = v5 - 1;
  if ( v6 == 0 )
  {
    v10 = *((_DWORD *)this + 7);
    if ( v10 + a3 > 0x10000 )
    {
      if ( v10 == 0x10000 || v10 == 0 )
      {
        v12 = lpBuffer;
      }
      else
      {
        qmemcpy((void *)(v10 + *((_DWORD *)this + 6)), lpBuffer, 0x10000 - v10);
        v10 = *((_DWORD *)this + 7);
        v12 = &lpBuffer[-v10 + 0x10000];
      }
      lpBuffera = v12;
      if ( v10 != 0 )
      {
        if ( !WriteFile(
                hFile: *(HANDLE *)this,
                lpBuffer: *((LPCVOID *)this + 6),
                nNumberOfBytesToWrite: 0x10000u,
                lpNumberOfBytesWritten,
                lpOverlapped: nullptr) )
          return -2147467259;
        *((_DWORD *)this + 8) += 0x10000;
        v13 = 0x10000 - *((_DWORD *)this + 7);
        *((_DWORD *)this + 7) = 0;
        v16 = v13;
      }
      v14 = (a3 - v16) >> 16;
      if ( v14 != 0 )
      {
        v15 = v14 << 16;
        if ( !WriteFile(
                hFile: *(HANDLE *)this,
                lpBuffer: lpBuffera,
                nNumberOfBytesToWrite: v14 << 16,
                lpNumberOfBytesWritten,
                lpOverlapped: nullptr) )
          return -2147467259;
        *((_DWORD *)this + 8) += v15;
        v16 += v15;
        lpBuffera += v15;
      }
      if ( v16 < a3 )
      {
        qmemcpy(*((void **)this + 6), lpBuffera, a3 - v16);
        *((_DWORD *)this + 7) = a3 - v16;
      }
      v11 = a3;
    }
    else
    {
      v11 = a3;
      qmemcpy((void *)(v10 + *((_DWORD *)this + 6)), lpBuffer, a3);
      *((_DWORD *)this + 7) += a3;
    }
    *lpNumberOfBytesWritten = v11;
    return 0;
  }
  if ( v6 != 1 )
    return -2147467259;
  if ( a3 + *((_DWORD *)this + 8) <= (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 5) + 16))(a1: *((_DWORD *)this + 5))
    || ((v8 = *((_DWORD *)this + 8) + a3) <= 2
                                           * (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 5) + 16))(a1: *((_DWORD *)this + 5))
      ? (v9 = 2 * (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 5) + 16))(a1: *((_DWORD *)this + 5)))
      : (v9 = v8),
        (result = D3DXCore::CBuffer::Grow(this: *((D3DXCore::CBuffer **)this + 5), a2: v9)) >= 0) )
  {
    qmemcpy(
      (void *)(*((_DWORD *)this + 8)
             + (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 5) + 12))(a1: *((_DWORD *)this + 5))),
      lpBuffer,
      a3);
    *lpNumberOfBytesWritten = a3;
    *((_DWORD *)this + 8) += a3;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042008A
// Name: public: long D3DXTex::CDataCollector::Flush(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CDataCollector::Flush(D3DXTex::CDataCollector *this)
{
  int v2; // eax
  int v3; // eax
  DWORD v5; // eax
  unsigned int NumberOfBytesWritten; // [esp+4h] [ebp-4h] BYREF

  v2 = *((_DWORD *)this + 4);
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    if ( v3 != 0 )
    {
      if ( v3 != 1 )
        return -2147467259;
    }
    else
    {
      v5 = *((_DWORD *)this + 7);
      if ( v5 != 0 )
      {
        if ( !WriteFile(
                hFile: *(HANDLE *)this,
                lpBuffer: *((LPCVOID *)this + 6),
                nNumberOfBytesToWrite: v5,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          return -2147467259;
        *((_DWORD *)this + 8) += *((_DWORD *)this + 7);
        *((_DWORD *)this + 7) = 0;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004200D4
// Name: public: D3DXTex::CImage::CImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXTex::CImage *__thiscall D3DXTex::CImage::CImage(D3DXTex::CImage *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004200ED
// Name: public: D3DXTex::CImage::~CImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXTex::CImage::~CImage(D3DXTex::CImage *this)
{
  void *v2; // edi
  D3DXTex::CImage *v3; // esi

  if ( *((_DWORD *)this + 1) != 0 && *((_DWORD *)this + 14) != 0 )
    free(pMem: *((void **)this + 1));
  if ( *((_DWORD *)this + 2) != 0 && *((_DWORD *)this + 15) != 0 )
    free(pMem: *((void **)this + 2));
  v2 = *((void **)this + 19);
  if ( v2 != nullptr )
  {
    D3DXTex::CImage::~CImage(this: *((D3DXTex::CImage **)this + 19));
    free(pMem: v2);
  }
  v3 = *((D3DXTex::CImage **)this + 20);
  if ( v3 != nullptr )
  {
    D3DXTex::CImage::~CImage(this: v3);
    free(pMem: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420148
// Name: public: long D3DXTex::CImage::Initialize(struct D3DX_BLT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::Initialize(void **this, struct D3DX_BLT *a2)
{
  _DWORD *v3; // edx
  void *v4; // eax
  int v5; // eax

  if ( *(this + 1) != nullptr && *(this + 14) != nullptr )
    free(pMem: *(this + 1));
  if ( *(this + 2) != nullptr && *(this + 15) != nullptr )
    free(pMem: *(this + 2));
  *this = *((void **)a2 + 1);
  *(this + 1) = *(void **)a2;
  *(this + 2) = *((void **)a2 + 20);
  v3 = this + 6;
  qmemcpy(this + 6, (char *)a2 + 40, 0x18u);
  *(this + 12) = *((void **)a2 + 2);
  *(this + 13) = *((void **)a2 + 3);
  v4 = *this;
  if ( (int)*this <= 877942852 )
  {
    if ( *this == (void *)877942852 || v4 == (void *)827611204 || v4 == (void *)844388420 )
      goto LABEL_13;
    if ( v4 != (void *)844715353 )
    {
      if ( v4 == (void *)861165636 )
      {
LABEL_13:
        *v3 &= 0xFFFFFFFC;
        *(this + 7) = (void *)((unsigned int)*(this + 7) & 0xFFFFFFFC);
        goto LABEL_14;
      }
      goto LABEL_14;
    }
LABEL_19:
    *v3 &= ~1u;
    goto LABEL_14;
  }
  if ( v4 == (void *)894720068 )
    goto LABEL_13;
  if ( v4 == (void *)1111970375 || v4 == (void *)1195525970 || v4 == (void *)1498831189 )
    goto LABEL_19;
LABEL_14:
  v5 = (int)*(this + 8) - *v3;
  *(this + 14) = nullptr;
  *(this + 15) = nullptr;
  *(this + 3) = (void *)v5;
  *(this + 4) = (void *)((_BYTE *)*(this + 9) - (_BYTE *)*(this + 7));
  *(this + 5) = (void *)((_BYTE *)*(this + 11) - (_BYTE *)*(this + 10));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00420222
// Name: private: long D3DXTex::CImage::SaveDIB(class D3DXTex::CDataCollector __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SaveDIB(D3DXTex::CImage *this, struct D3DXTex::CDataCollector *a2, int a3)
{
  int v4; // eax
  unsigned int v5; // esi
  bool v6; // zf
  bool v7; // cc
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char *v11; // esi
  unsigned int v12; // edi
  int v13; // ecx
  int v14; // eax
  char v15; // dl
  int v16; // eax
  int v17; // eax
  unsigned int i; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  unsigned int v22; // esi
  int v23; // ecx
  unsigned int v24; // eax
  char *v25; // edi
  char v27; // [esp+Ch] [ebp-4A4h] BYREF
  _BYTE v28[1023]; // [esp+Dh] [ebp-4A3h] BYREF
  __int16 Buffer; // [esp+40Ch] [ebp-A4h] BYREF
  unsigned int v30; // [esp+40Eh] [ebp-A2h]
  __int16 v31; // [esp+412h] [ebp-9Eh]
  __int16 v32; // [esp+414h] [ebp-9Ch]
  unsigned int v33; // [esp+416h] [ebp-9Ah]
  unsigned int v34; // [esp+41Ch] [ebp-94h]
  unsigned int v35; // [esp+420h] [ebp-90h]
  unsigned int v36; // [esp+424h] [ebp-8Ch]
  _DWORD v37[27]; // [esp+428h] [ebp-88h] BYREF
  char v38[4]; // [esp+494h] [ebp-1Ch] BYREF
  D3DXTex::CDataCollector *v39; // [esp+498h] [ebp-18h]
  unsigned int v40; // [esp+49Ch] [ebp-14h]
  unsigned int v41; // [esp+4A0h] [ebp-10h] BYREF
  _BYTE v42[4]; // [esp+4A4h] [ebp-Ch]
  unsigned int v43; // [esp+4A8h] [ebp-8h]

  v39 = a2;
  memset(v37, 0, sizeof(v37));
  v4 = *(_DWORD *)this;
  v5 = 0;
  v6 = *(_DWORD *)this == 41;
  v7 = *(_DWORD *)this <= 41;
  v38[0] = 0;
  v38[1] = 0;
  v38[2] = 0;
  v38[3] = 0;
  v41 = -5614336;
  v42[0] = 0;
  v42[1] = 36;
  v42[2] = 73;
  v42[3] = 109;
  v43 = -2378094;
  v40 = 0;
  if ( v7 )
  {
    if ( v6 )
    {
      v10 = *((_DWORD *)this + 2);
      v37[4] = 0;
      v11 = (char *)(v10 + 2);
      v12 = 0;
      v37[0] = 40;
      HIWORD(v37[3]) = 8;
      v40 = 1024;
      v13 = v10 - (_DWORD)v28;
      do
      {
        v14 = 4 * v12;
        v28[v14 + 1] = v28[4 * v12 + v13];
        v28[v14] = *(v11 - 1);
        v15 = *v11;
        ++v12;
        v11 += 4;
        v28[v14 - 1] = v15;
        v28[v14 + 2] = 0;
      }
      while ( v12 < 0x100 );
    }
    else
    {
      switch ( v4 )
      {
        case 20:
          v37[0] = 40;
          v37[4] = 0;
          HIWORD(v37[3]) = 24;
          goto LABEL_32;
        case 21:
        case 22:
          v37[0] = 40;
          v37[4] = 0;
          HIWORD(v37[3]) = 32;
          goto LABEL_32;
        case 23:
          v37[0] = 52;
          v37[4] = 3;
          HIWORD(v37[3]) = 16;
          v37[10] = 63488;
          v37[11] = 2016;
          v37[12] = 31;
          goto LABEL_32;
        case 24:
          v37[0] = 40;
          v37[4] = 0;
          HIWORD(v37[3]) = 16;
          goto LABEL_32;
        case 25:
          v37[0] = 56;
          v37[4] = 3;
          HIWORD(v37[3]) = 16;
          v37[10] = 31744;
          v37[11] = 992;
          v37[12] = 31;
          v37[13] = 0x8000;
          goto LABEL_32;
        case 26:
          v37[0] = 56;
          v37[4] = 3;
          HIWORD(v37[3]) = 16;
          v37[10] = 3840;
          v37[11] = 240;
          v37[12] = 15;
          v37[13] = 61440;
          goto LABEL_32;
        case 27:
          v37[0] = 40;
          v37[4] = 0;
          HIWORD(v37[3]) = 8;
          v40 = 1024;
          do
          {
            v8 = 4 * v5;
            v28[v8 + 1] = v42[v5 >> 5];
            v28[v8] = v42[(v5 >> 2) & 7];
            v9 = v42[(v5++ & 3) - 4];
            v28[v8 - 1] = v9;
            v28[v8 + 2] = 0;
          }
          while ( v5 < 0x100 );
          goto LABEL_32;
        case 29:
          v37[4] = 3;
          v37[10] = 224;
          v37[11] = 28;
          v37[12] = 3;
          goto LABEL_15;
        case 30:
          v37[0] = 52;
          v37[4] = 3;
          HIWORD(v37[3]) = 16;
          v37[10] = 3840;
          v37[11] = 240;
          v37[12] = 15;
          goto LABEL_32;
        case 31:
          v37[10] = 1023;
          v37[12] = 1072693248;
          break;
        case 32:
          v37[0] = 56;
          v37[4] = 3;
          HIWORD(v37[3]) = 32;
          v37[10] = 255;
          v37[11] = 65280;
          v37[12] = 16711680;
          v37[13] = -16777216;
          goto LABEL_32;
        case 33:
          v37[0] = 52;
          v37[4] = 3;
          HIWORD(v37[3]) = 32;
          v37[10] = 255;
          v37[11] = 65280;
          v37[12] = 16711680;
          goto LABEL_32;
        case 34:
          v37[0] = 52;
          v37[4] = 3;
          HIWORD(v37[3]) = 32;
          v37[10] = 0xFFFF;
          v37[11] = -65536;
          v37[12] = 0;
          goto LABEL_32;
        case 35:
          v37[10] = 1072693248;
          v37[12] = 1023;
          break;
        default:
          return -2147467259;
      }
      v37[0] = 56;
      v37[4] = 3;
      HIWORD(v37[3]) = 32;
      v37[11] = 1047552;
      v37[13] = -1073741824;
    }
  }
  else
  {
    v16 = v4 - 50;
    if ( v16 != 0 )
    {
      v17 = v16 - 1;
      if ( v17 != 0 )
      {
        if ( v17 != 30 )
          return -2147467259;
        v37[0] = 52;
        v37[4] = 3;
        HIWORD(v37[3]) = 16;
        v37[10] = 0xFFFF;
        v37[11] = 0xFFFF;
        v37[12] = 0xFFFF;
      }
      else
      {
        v37[4] = 3;
        v37[10] = 255;
        v37[11] = 255;
        v37[12] = 255;
LABEL_15:
        v37[0] = 56;
        HIWORD(v37[3]) = 16;
        v37[13] = 65280;
      }
    }
    else
    {
      v37[0] = 40;
      v37[4] = 0;
      HIWORD(v37[3]) = 8;
      v40 = 1024;
      for ( i = 0; i < 0x100; ++i )
      {
        v19 = 4 * i;
        v28[v19 + 1] = i;
        v28[v19] = i;
        v28[v19 - 1] = i;
        v28[v19 + 2] = 0;
      }
    }
  }
LABEL_32:
  v20 = *((_DWORD *)this + 3);
  v21 = *((_DWORD *)this + 4);
  v37[6] = 2834;
  v37[7] = 2834;
  v37[1] = v20;
  v37[2] = v21;
  v36 = (HIWORD(v37[3]) >> 3) * v20;
  v43 = HIWORD(v37[3]) >> 3;
  v35 = (v36 + 3) & 0xFFFFFFFC;
  Buffer = 19778;
  v31 = 0;
  v32 = 0;
  v22 = ((v37[0] + v35 * v21 + v40 + 17) & 0xFFFFFFFC) - (v37[0] + v35 * v21 + v40 + 14);
  v30 = (v37[0] + v35 * v21 + v40 + 17) & 0xFFFFFFFC;
  LOWORD(v37[3]) = 1;
  v34 = v37[0];
  v33 = v37[0] + v40 + 14;
  if ( a3 != 0
    && D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: (char *)&Buffer, a3: 0xEu, lpNumberOfBytesWritten: &v41) < 0
    || v34 != 0
    && D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: (char *)v37, a3: v34, lpNumberOfBytesWritten: &v41) < 0
    || v40 != 0
    && D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: &v27, a3: v40, lpNumberOfBytesWritten: &v41) < 0 )
  {
    return -2147467259;
  }
  v23 = *((_DWORD *)this + 12);
  v24 = *((_DWORD *)this + 1) + v23 * *((_DWORD *)this + 7) + v43 * *((_DWORD *)this + 6);
  v25 = (char *)(v24 + v23 * *((_DWORD *)this + 4) - v23);
  v43 = v24;
  if ( (unsigned int)v25 >= v24 )
  {
    while ( D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: v25, a3: v36, lpNumberOfBytesWritten: &v41) >= 0
         && (v36 >= v35
          || D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: v38, a3: v35 - v36, lpNumberOfBytesWritten: &v41) >= 0) )
    {
      v25 -= *((_DWORD *)this + 12);
      if ( (unsigned int)v25 < v43 )
        goto LABEL_43;
    }
    return -2147467259;
  }
LABEL_43:
  if ( v22 != 0
    && D3DXTex::CDataCollector::WriteData(this: v39, lpBuffer: v38, a3: v22, lpNumberOfBytesWritten: &v41) < 0 )
  {
    return -2147467259;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00420821
// Name: sub_420821
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_420821(int a1)
{
  (*(void (__cdecl **)(int))(*(_DWORD *)a1 + 8))(a1);
  longjmp(Buf: (int *)(*(_DWORD *)a1 + 132), Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00420840
// Name: void D3DX::png_do_write_transformations(struct D3DX::png_struct_def __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall D3DX::png_do_write_transformations(D3DX *this, struct D3DX::png_struct_def *a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00420843
// Name: sub_420843
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__stdcall sub_420843(int a1)
{
  _DWORD *v1; // esi
  void *result; // eax

  v1 = *(_DWORD **)(a1 + 24);
  result = operator new(nSize: 0x1000u);
  v1[6] = result;
  *v1 = result;
  v1[1] = 4096;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042086B
// Name: sub_42086B
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_42086B(unsigned int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 24);
  D3DXTex::CDataCollector::WriteData(
    this: *(D3DXTex::CDataCollector **)(v1 + 20),
    lpBuffer: *(char **)(v1 + 24),
    a3: 0x1000u,
    lpNumberOfBytesWritten: &a1);
  *(_DWORD *)v1 = *(_DWORD *)(v1 + 24);
  *(_DWORD *)(v1 + 4) = 4096;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042089F
// Name: sub_42089F
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_42089F(unsigned int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 24);
  if ( *(_DWORD *)(result + 4) != 4096 )
    return D3DXTex::CDataCollector::WriteData(
             this: *(D3DXTex::CDataCollector **)(result + 20),
             lpBuffer: *(char **)(result + 24),
             a3: 4096 - *(_DWORD *)(result + 4),
             lpNumberOfBytesWritten: &a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004208C8
// Name: private: long D3DXTex::CImage::SaveJPG(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SaveJPG(D3DXTex **this, struct D3DXTex::CDataCollector *a2)
{
  D3DXTex::CImage *v2; // esi
  int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edi
  bool v6; // zf
  int v7; // eax
  int v8; // ecx
  D3DXTex *v10; // [esp-4h] [ebp-28Ch]
  enum _D3DFORMAT v11; // [esp+0h] [ebp-288h]
  unsigned int v12; // [esp+0h] [ebp-288h]
  struct D3DX::jpeg_error_mgr *v13; // [esp+0h] [ebp-288h]
  int v14; // [esp+0h] [ebp-288h]
  struct D3DX::jpeg_compress_struct *v15; // [esp+0h] [ebp-288h]
  int v16; // [esp+0h] [ebp-288h]
  struct D3DX::jpeg_compress_struct *v17; // [esp+0h] [ebp-288h]
  struct D3DX::jpeg_compress_struct *v18; // [esp+0h] [ebp-288h]
  char v19; // [esp+Ch] [ebp-27Ch] BYREF
  void *(__stdcall *v20)(int); // [esp+14h] [ebp-274h]
  int (__stdcall *v21)(unsigned int); // [esp+18h] [ebp-270h]
  int (__stdcall *v22)(unsigned int); // [esp+1Ch] [ebp-26Ch]
  struct D3DXTex::CDataCollector *v23; // [esp+20h] [ebp-268h]
  void *v24; // [esp+24h] [ebp-264h]
  int v25; // [esp+28h] [ebp-260h]
  D3DXTex::CImage *v26; // [esp+2Ch] [ebp-25Ch]
  int v27; // [esp+30h] [ebp-258h]
  unsigned int v28; // [esp+34h] [ebp-254h]
  unsigned int v29; // [esp+38h] [ebp-250h]
  void *pMem; // [esp+3Ch] [ebp-24Ch] BYREF
  _DWORD v31[33]; // [esp+40h] [ebp-248h] BYREF
  _BYTE v32[64]; // [esp+C4h] [ebp-1C4h] BYREF
  _DWORD v33[12]; // [esp+104h] [ebp-184h] BYREF
  double v34; // [esp+134h] [ebp-154h]

  v10 = *this;
  v26 = (D3DXTex::CImage *)this;
  v27 = 0;
  pMem = nullptr;
  v23 = a2;
  v24 = nullptr;
  v20 = sub_420843;
  v21 = sub_42086B;
  v22 = sub_42089F;
  v25 = *((_DWORD *)D3DXTex::GetFormatInfo(this: v10, a2: v11) + 2) >> 3;
  D3DX::jpeg_CreateCompress(this: (D3DX *)v33, a2: (struct D3DX::jpeg_compress_struct *)0x3E, a3: 384, a4: v12);
  v33[0] = D3DX::jpeg_std_error(this: (D3DX *)v31, a2: v13);
  v31[0] = sub_420821;
  v31[2] = D3DX::png_do_write_transformations;
  if ( _setjmp3(a1: v32, a2: 0, a3: v14) != 0 )
  {
    v27 = -2147467259;
  }
  else
  {
    v33[10] = 2;
    D3DX::jpeg_set_defaults(this: (D3DX *)v33, a2: v15);
    v2 = v26;
    v34 = 2.2;
    v33[7] = *((_DWORD *)v26 + 3);
    v33[8] = *((_DWORD *)v26 + 4);
    v33[6] = &v19;
    v33[9] = 3;
    D3DX::jpeg_start_compress(this: (D3DX *)v33, a2: (struct D3DX::jpeg_compress_struct *)1, a3: v16);
    pMem = operator new(nSize: 3 * *((_DWORD *)v2 + 3));
    if ( pMem != nullptr )
    {
      v3 = *((_DWORD *)v2 + 12);
      v4 = *((_DWORD *)v2 + 1) + v25 * *((_DWORD *)v2 + 6) + v3 * *((_DWORD *)v2 + 7);
      v5 = v4 + v3 * *((_DWORD *)v2 + 4);
      while ( 1 )
      {
        v28 = v4;
        if ( v4 >= v5 )
          break;
        v6 = *((_DWORD *)v2 + 3) == 0;
        v29 = 0;
        if ( !v6 )
        {
          v7 = 0;
          do
          {
            v8 = *(_DWORD *)(v28 + 4 * v29);
            *((_BYTE *)pMem + v7) = BYTE2(v8);
            ++v29;
            *((_BYTE *)pMem + v7 + 1) = BYTE1(v8);
            *((_BYTE *)pMem + v7 + 2) = v8;
            v7 += 3;
          }
          while ( v29 < *((_DWORD *)v2 + 3) );
        }
        D3DX::jpeg_write_scanlines(
          this: (D3DX *)v33,
          a2: (struct D3DX::jpeg_compress_struct *)&pMem,
          a3: (unsigned __int8 **)1,
          a4: (unsigned int)v17);
        v4 = *((_DWORD *)v2 + 12) + v28;
      }
      D3DX::jpeg_finish_compress(this: (D3DX *)v33, a2: v17);
      D3DX::jpeg_destroy_compress(this: (D3DX *)v33, a2: v18);
    }
    else
    {
      v27 = -2147024882;
    }
  }
  free(pMem);
  free(pMem: v24);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x00420AFD
// Name: private: long D3DXTex::CImage::SaveTGA(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SaveTGA(D3DXTex::CImage *this, struct D3DXTex::CDataCollector *a2)
{
  bool v3; // zf
  __int16 v4; // ax
  int result; // eax
  char Buffer[3]; // [esp+8h] [ebp-18h] BYREF
  __int16 v7; // [esp+Bh] [ebp-15h]
  __int16 v8; // [esp+Dh] [ebp-13h]
  char v9; // [esp+Fh] [ebp-11h]
  __int16 v10; // [esp+10h] [ebp-10h]
  __int16 v11; // [esp+12h] [ebp-Eh]
  __int16 v12; // [esp+14h] [ebp-Ch]
  __int16 v13; // [esp+16h] [ebp-Ah]
  unsigned __int8 v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+19h] [ebp-7h]
  unsigned int v16; // [esp+1Ch] [ebp-4h] BYREF

  v3 = *(_DWORD *)this == 21;
  v12 = *((_WORD *)this + 6);
  v4 = *((_WORD *)this + 8);
  Buffer[0] = 13;
  Buffer[1] = 0;
  Buffer[2] = 2;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v13 = v4;
  if ( v3 )
  {
    v14 = 32;
    v15 = 40;
  }
  else
  {
    v14 = 24;
    v15 = 32;
  }
  v16 = 0;
  result = D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: Buffer, a3: 0x12u, lpNumberOfBytesWritten: &v16);
  if ( result >= 0 )
  {
    result = D3DXTex::CDataCollector::WriteData(
               this: a2,
               lpBuffer: "Saved by D3DX",
               a3: 0xDu,
               lpNumberOfBytesWritten: &v16);
    if ( result >= 0 )
      return D3DXTex::CDataCollector::WriteData(
               this: a2,
               lpBuffer: *((char **)this + 1),
               a3: *((_DWORD *)this + 4) * *((_DWORD *)this + 3) * (v14 >> 3),
               lpNumberOfBytesWritten: &v16);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420BA5
// Name: sub_420BA5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_420BA5(jmp_buf Buf)
{
  longjmp(Buf, Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00420BB5
// Name: sub_420BB5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_420BB5(D3DX *a1, char *lpBuffer, unsigned int a3)
{
  struct D3DX::png_struct_def *v3; // ecx
  D3DXTex::CDataCollector *io_ptr; // eax
  unsigned int v6; // [esp+0h] [ebp-4h] BYREF

  io_ptr = (D3DXTex::CDataCollector *)D3DX::png_get_io_ptr(this: a1, a2: v3);
  v6 = 0;
  return D3DXTex::CDataCollector::WriteData(this: io_ptr, lpBuffer, a3, lpNumberOfBytesWritten: &v6);
}

//------------------------------------------------------------------------------
// Address: 0x00420BDA
// Name: private: long D3DXTex::CImage::SavePNG(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SavePNG(D3DXTex::CImage *this, struct D3DXTex::CDataCollector *a2)
{
  unsigned int v2; // edi
  D3DX *v3; // eax
  int v4; // esi
  unsigned int v5; // ebx
  int *v6; // eax
  int v7; // ecx
  int v8; // edx
  _BYTE *v9; // eax
  int v10; // ecx
  _BYTE v12[12]; // [esp+0h] [ebp-2Ch]
  void (__cdecl *v13)(struct D3DX::png_struct_def *, const char *); // [esp+8h] [ebp-24h]
  struct D3DX::png_struct_def *v14; // [esp+8h] [ebp-24h]
  struct D3DX::png_info_struct *v15; // [esp+8h] [ebp-24h]
  struct D3DX::png_info_struct *v16; // [esp+8h] [ebp-24h]
  unsigned int v18; // [esp+18h] [ebp-14h]
  unsigned int v19; // [esp+1Ch] [ebp-10h]
  struct D3DX::png_struct_def *info_struct; // [esp+20h] [ebp-Ch] BYREF
  D3DX *v21; // [esp+24h] [ebp-8h] BYREF
  void *pMem; // [esp+28h] [ebp-4h] BYREF

  v2 = 0;
  info_struct = nullptr;
  pMem = nullptr;
  v3 = D3DX::png_create_write_struct(
         this: (D3DX *)"1.0.5",
         a2: nullptr,
         a3: sub_420BA5,
         a4: (void (__cdecl *)(struct D3DX::png_struct_def *, const char *))D3DXTex::CCodecYUV::QuantizeColorKey,
         a5: v13);
  v21 = v3;
  if ( v3 == nullptr )
    goto LABEL_20;
  info_struct = D3DX::png_create_info_struct(this: v3, a2: v14);
  if ( info_struct == nullptr )
    goto LABEL_20;
  if ( _setjmp3(a1: v21, a2: 0, a3: v14) != 0 )
  {
    v4 = -2147467259;
    goto LABEL_21;
  }
  v5 = 8 * (*(_DWORD *)this == 36) + 8;
  D3DX::png_set_IHDR(
    this: v21,
    a2: info_struct,
    a3: *((struct D3DX::png_info_struct **)this + 3),
    a4: *((_DWORD *)this + 4),
    a5: v5,
    a6: 2,
    a7: 0,
    a8: 0,
    a9: 0,
    a10: (int)v14);
  *(double *)v12 = 2.2;
  D3DX::png_set_gAMA(
    this: v21,
    a2: info_struct,
    a3: (struct D3DX::png_info_struct *)COERCE_UNSIGNED_INT64(2.2),
    a4: *(double *)&v12[4]);
  pMem = operator new(nSize: 3 * *((_DWORD *)this + 3) * (v5 >> 3));
  if ( pMem != nullptr )
  {
    D3DX::png_set_write_fn(
      this: v21,
      a2,
      a3: sub_420BB5,
      a4: (void (__cdecl *)(struct D3DX::png_struct_def *, unsigned __int8 *, unsigned int))D3DXTex::CCodecYUV::QuantizeColorKey,
      a5: (void (__cdecl *)(struct D3DX::png_struct_def *))v14);
    D3DX::png_write_info(this: v21, a2: info_struct, a3: v15);
    v19 = 0;
    if ( v5 == 8 )
    {
      if ( *((_DWORD *)this + 4) != 0 )
      {
        do
        {
          v6 = (int *)(*((_DWORD *)this + 1) + v19 * *((_DWORD *)this + 12));
          v18 = 0;
          if ( *((_DWORD *)this + 3) != 0 )
          {
            v7 = 0;
            do
            {
              v8 = *v6;
              *((_BYTE *)pMem + v7) = BYTE2(*v6);
              ++v18;
              *((_BYTE *)pMem + v7 + 1) = BYTE1(v8);
              *((_BYTE *)pMem + v7 + 2) = v8;
              v7 += 3;
              ++v6;
            }
            while ( v18 < *((_DWORD *)this + 3) );
          }
          D3DX::png_write_rows(
            this: v21,
            a2: (struct D3DX::png_struct_def *)&pMem,
            a3: (unsigned __int8 **)1,
            a4: (unsigned int)v16);
          ++v19;
        }
        while ( v19 < *((_DWORD *)this + 4) );
      }
    }
    else if ( *((_DWORD *)this + 4) != 0 )
    {
      do
      {
        v9 = (_BYTE *)(*((_DWORD *)this + 1) + v19 * *((_DWORD *)this + 12));
        if ( *((_DWORD *)this + 3) != 0 )
        {
          v10 = 0;
          do
          {
            *((_BYTE *)pMem + v10) = v9[1];
            *((_BYTE *)pMem + v10 + 1) = *v9;
            *((_BYTE *)pMem + v10 + 2) = v9[3];
            *((_BYTE *)pMem + v10 + 3) = v9[2];
            *((_BYTE *)pMem + v10 + 4) = v9[5];
            *((_BYTE *)pMem + v10 + 5) = v9[4];
            ++v2;
            v10 += 6;
            v9 += 8;
          }
          while ( v2 < *((_DWORD *)this + 3) );
          v2 = 0;
        }
        D3DX::png_write_rows(
          this: v21,
          a2: (struct D3DX::png_struct_def *)&pMem,
          a3: (unsigned __int8 **)1,
          a4: (unsigned int)v16);
        ++v19;
      }
      while ( v19 < *((_DWORD *)this + 4) );
    }
    D3DX::png_write_end(this: v21, a2: info_struct, a3: v16);
    v4 = 0;
  }
  else
  {
LABEL_20:
    v4 = -2147024882;
  }
LABEL_21:
  if ( v21 != nullptr )
    D3DX::png_destroy_write_struct(this: (D3DX *)&v21, a2: &info_struct, a3: (struct D3DX::png_info_struct **)v14);
  free(pMem);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00420DDC
// Name: private: long D3DXTex::CImage::SaveDDS(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SaveDDS(D3DXTex **this, struct D3DXTex::CDataCollector *a2)
{
  D3DXTex **i; // eax
  int v4; // eax
  int *v5; // ebx
  D3DXTex *v6; // ecx
  int v8; // eax
  D3DXTex **v9; // esi
  int v10; // ebx
  unsigned int v11; // eax
  D3DXTex **v12; // esi
  int v13; // edi
  int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  char *v17; // eax
  enum _D3DFORMAT v18; // [esp+0h] [ebp-9Ch]
  _DWORD v19[31]; // [esp+8h] [ebp-94h] BYREF
  int Buffer; // [esp+84h] [ebp-18h] BYREF
  const struct _D3DXFORMAT_INFO *FormatInfo; // [esp+88h] [ebp-14h]
  D3DXTex **v22; // [esp+8Ch] [ebp-10h]
  unsigned int v23; // [esp+90h] [ebp-Ch] BYREF
  int v24; // [esp+94h] [ebp-8h]
  D3DXTex **v25; // [esp+98h] [ebp-4h]

  v25 = nullptr;
  v22 = this;
  for ( i = this; i != nullptr; v25 = (D3DXTex **)((char *)v25 + 1) )
    i = (D3DXTex **)i[19];
  v4 = dword_5213B8;
  v5 = &dword_5213B8;
  if ( dword_5213B8 != 0 )
  {
    v6 = *this;
    do
    {
      if ( (D3DXTex *)v4 == v6 )
        break;
      v5 += 9;
      v4 = *v5;
    }
    while ( *v5 != 0 );
  }
  if ( *v5 == 0 )
    return -2147467259;
  FormatInfo = D3DXTex::GetFormatInfo(this: *this, a2: v18);
  v24 = *((_DWORD *)FormatInfo + 2) >> 3;
  Buffer = 542327876;
  if ( D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: (char *)&Buffer, a3: 4u, lpNumberOfBytesWritten: &v23) < 0 )
    return -2147467259;
  memset(v19, 0, sizeof(v19));
  v19[2] = *(this + 4);
  v19[3] = *(this + 3);
  v8 = v5[2];
  v19[0] = 124;
  v19[1] = 4103;
  qmemcpy(&v19[18], v5 + 1, 0x20u);
  v19[26] = 4096;
  if ( (v8 & 3) != 0 )
    v19[26] = 4098;
  if ( (v8 & 0x20) != 0 )
    BYTE1(v19[26]) |= 1u;
  v9 = v22;
  v10 = 0;
  if ( v22[19] != nullptr )
  {
    v19[26] |= 0x400008u;
    v19[1] = 135175;
    v19[6] = v25;
  }
  if ( v22[20] != nullptr )
  {
    v19[26] |= 8u;
    BYTE1(v19[27]) |= 0xFEu;
  }
  v11 = (unsigned int)v22[5];
  if ( v11 > 1 )
  {
    BYTE2(v19[1]) |= 0x80u;
    BYTE2(v19[27]) |= 0x20u;
    v19[5] = v11;
  }
  if ( D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: (char *)v19, a3: 0x7Cu, lpNumberOfBytesWritten: &v23) < 0
    || *((_DWORD *)FormatInfo + 1) == 1
    && D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: (char *)v9[2], a3: 0x400u, lpNumberOfBytesWritten: &v23) < 0 )
  {
    return -2147467259;
  }
  v25 = v9;
  do
  {
    v12 = v25;
    while ( v12 != nullptr )
    {
      if ( v12[5] != nullptr )
      {
        while ( 1 )
        {
          v13 = 0;
          if ( v12[4] != nullptr )
            break;
LABEL_38:
          if ( ++v10 >= (unsigned int)v12[5] )
            goto LABEL_39;
        }
        while ( 2 )
        {
          v14 = (int)*v22;
          if ( (int)*v22 > 877942852 )
          {
            if ( v14 != 894720068 )
            {
              if ( v14 != 1111970375 && v14 != 1195525970 && v14 != 1498831189 )
                goto LABEL_49;
              goto LABEL_50;
            }
LABEL_34:
            v15 = 16 * ((unsigned int)v12[6] >> 2)
                + (_DWORD)v12[13] * ((_DWORD)v12[10] + v10)
                + (_DWORD)v12[12] * (((unsigned int)v12[7] + v13) >> 2);
            v16 = 16 * (((unsigned int)v12[3] + 3) >> 2);
          }
          else
          {
            if ( *v22 == (D3DXTex *)877942852 )
              goto LABEL_34;
            if ( v14 != 827611204 )
            {
              if ( v14 == 844388420 )
                goto LABEL_34;
              if ( v14 != 844715353 )
              {
                if ( v14 == 861165636 )
                  goto LABEL_34;
LABEL_49:
                v17 = (char *)v12[1]
                    + v24 * (_DWORD)v12[6]
                    + (_DWORD)v12[13] * ((_DWORD)v12[10] + v10)
                    + (_DWORD)v12[12] * ((_DWORD)v12[7] + v13);
                v16 = v24 * (_DWORD)v12[3];
LABEL_36:
                if ( D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: v17, a3: v16, lpNumberOfBytesWritten: &v23) < 0 )
                  return -2147467259;
                if ( ++v13 >= (unsigned int)v12[4] )
                  goto LABEL_38;
                continue;
              }
LABEL_50:
              v17 = (char *)v12[1]
                  + v24 * (_DWORD)v12[6]
                  + (_DWORD)v12[13] * ((_DWORD)v12[10] + v10)
                  + (_DWORD)v12[12] * ((_DWORD)v12[7] + v13);
              v16 = 4 * (((unsigned int)v12[3] + 1) >> 1);
              goto LABEL_36;
            }
            v15 = (_DWORD)v12[13] * ((_DWORD)v12[10] + v10)
                + (_DWORD)v12[12] * (((unsigned int)v12[7] + v13) >> 2)
                + 8 * ((unsigned int)v12[6] >> 2);
            v16 = 8 * (((unsigned int)v12[3] + 3) >> 2);
          }
          break;
        }
        v17 = (char *)v12[1] + v15;
        v13 += 3;
        goto LABEL_36;
      }
LABEL_39:
      v12 = (D3DXTex **)v12[19];
      v10 = 0;
    }
    v25 = (D3DXTex **)v25[20];
  }
  while ( v25 != nullptr );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004210CB
// Name: long StringVPrintfWorkerA(char __near *,unsigned int,char const __near *,char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall StringVPrintfWorkerA(char *string, unsigned int a2, char *format, char *ap)
{
  int v4; // ebx
  unsigned int v5; // esi
  int v6; // eax

  v4 = 0;
  if ( a2 != 0 )
  {
    v5 = a2 - 1;
    v6 = _vsnprintf(string, count: a2 - 1, format, ap);
    if ( v6 < 0 || v6 > v5 )
    {
      v4 = -2147024774;
    }
    else if ( v6 != v5 )
    {
      return v4;
    }
    string[v5] = 0;
    return v4;
  }
  return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x00421117
// Name: public: D3DXTex::CDataCollector::~CDataCollector(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXTex::CDataCollector::~CDataCollector(void **this)
{
  D3DXTex::CDataCollector::Flush((D3DXTex::CDataCollector *)this);
  if ( *(this + 5) != nullptr )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*(this + 5) + 8))(a1: *(this + 5));
  if ( *(this + 6) != nullptr )
    free(pMem: *(this + 6));
  D3DXCore::CFile::~CFile((D3DXCore::CFile *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00421146
// Name: long StringCbPrintfA(char __near *,unsigned int,char const __near *,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int StringCbPrintfA(char *string, unsigned int a2, char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  if ( a2 <= 0x7FFFFFFF )
    return StringVPrintfWorkerA(string, a2, format, ap);
  else
    return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x0042116F
// Name: private: long D3DXTex::CImage::SavePFM(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SavePFM(D3DXTex::CImage *this, struct D3DXTex::CDataCollector *a2)
{
  D3DXTex::CDataCollector *v2; // ebx
  int v5; // eax
  int v6; // eax
  char *v7; // edi
  char *v8; // edx
  char *v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // [esp+Ch] [ebp-114h]
  int v13; // [esp+10h] [ebp-110h]
  char *pMem; // [esp+14h] [ebp-10Ch]
  unsigned int v15; // [esp+18h] [ebp-108h] BYREF
  char string[256]; // [esp+1Ch] [ebp-104h] BYREF

  v15 = 0;
  v2 = a2;
  v12 = -2147467259;
  pMem = (char *)operator new(nSize: 12 * *((_DWORD *)this + 3));
  if ( pMem == nullptr )
    return -2147024882;
  if ( *(_DWORD *)this == 116 )
  {
    v5 = D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: "PF\n", a3: 3u, lpNumberOfBytesWritten: &v15);
LABEL_7:
    if ( v5 >= 0 )
    {
      StringCbPrintfA(string, a2: 0x100u, format: "%u %u\n-1.000000\n", *((_DWORD *)this + 3), *((_DWORD *)this + 4));
      if ( D3DXTex::CDataCollector::WriteData(
             this: a2,
             lpBuffer: string,
             a3: strlen(string),
             lpNumberOfBytesWritten: &v15) >= 0 )
      {
        v6 = *((_DWORD *)this + 4) - 1;
        v7 = (char *)(*((_DWORD *)this + 1) + v6 * *((_DWORD *)this + 12));
        v13 = v6;
        if ( v6 < 0 )
        {
LABEL_19:
          v12 = 0;
        }
        else
        {
          while ( 1 )
          {
            v8 = v7;
            if ( *(_DWORD *)this == 116 )
            {
              v9 = &v7[16 * *((_DWORD *)this + 3)];
              if ( v7 != v9 )
              {
                v10 = pMem + 8;
                do
                {
                  *(v10 - 2) = *(_DWORD *)v8;
                  *(v10 - 1) = *((_DWORD *)v8 + 1);
                  *v10 = *((_DWORD *)v8 + 2);
                  v8 += 16;
                  v10 += 3;
                }
                while ( v8 != v9 );
                v2 = a2;
              }
              v11 = D3DXTex::CDataCollector::WriteData(
                      this: v2,
                      lpBuffer: pMem,
                      a3: 12 * *((_DWORD *)this + 3),
                      lpNumberOfBytesWritten: &v15);
            }
            else
            {
              v11 = D3DXTex::CDataCollector::WriteData(
                      this: v2,
                      lpBuffer: v7,
                      a3: 4 * *((_DWORD *)this + 3),
                      lpNumberOfBytesWritten: &v15);
            }
            if ( v11 < 0 )
              break;
            --v13;
            v7 -= *((_DWORD *)this + 12);
            if ( v13 < 0 )
              goto LABEL_19;
          }
        }
      }
    }
    goto LABEL_20;
  }
  if ( *(_DWORD *)this == 114 )
  {
    v5 = D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: "Pf\n", a3: 3u, lpNumberOfBytesWritten: &v15);
    goto LABEL_7;
  }
LABEL_20:
  free(pMem);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x00421319
// Name: private: long D3DXTex::CImage::SaveHDR(class D3DXTex::CDataCollector __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::SaveHDR(D3DXTex::CImage *this, struct D3DXTex::CDataCollector *a2)
{
  struct D3DXTex::CDataCollector *v2; // ebx
  unsigned int v4; // edx
  unsigned int v5; // eax
  const void *v6; // eax
  int v7; // eax
  float *v8; // edi
  unsigned __int8 *v9; // ebx
  double v10; // st7
  float v11; // eax
  long double v12; // st7
  long double v13; // st7
  long double v14; // st6
  __int64 v15; // rax
  bool v16; // zf
  unsigned int v17; // eax
  char *v18; // edi
  unsigned int v19; // ecx
  unsigned __int8 v20; // bl
  int v21; // eax
  _BYTE *v22; // edx
  char v23; // cl
  float v25; // [esp+18h] [ebp-140h]
  int v26; // [esp+1Ch] [ebp-13Ch]
  int expptr; // [esp+20h] [ebp-138h] BYREF
  unsigned int v28; // [esp+24h] [ebp-134h]
  LPCVOID lpBuffer; // [esp+28h] [ebp-130h]
  D3DXTex::CDataCollector *v30; // [esp+2Ch] [ebp-12Ch]
  unsigned int v31; // [esp+30h] [ebp-128h]
  void *pMem; // [esp+34h] [ebp-124h]
  char Buffer; // [esp+38h] [ebp-120h] BYREF
  char v34; // [esp+39h] [ebp-11Fh]
  char v35; // [esp+3Ah] [ebp-11Eh]
  char v36; // [esp+3Bh] [ebp-11Dh]
  char v37; // [esp+3Fh] [ebp-119h]
  float v38; // [esp+40h] [ebp-118h]
  float v39; // [esp+44h] [ebp-114h]
  unsigned int v40; // [esp+48h] [ebp-110h] BYREF
  float v41; // [esp+4Ch] [ebp-10Ch]
  unsigned __int8 v42; // [esp+53h] [ebp-105h] BYREF
  char buffer[256]; // [esp+54h] [ebp-104h] BYREF

  v40 = 0;
  v2 = a2;
  v4 = *((_DWORD *)this + 4);
  v30 = a2;
  v26 = -2147467259;
  if ( v4 <= 0x7FFF )
  {
    v5 = *((_DWORD *)this + 3);
    if ( v5 <= 0x7FFF )
    {
      pMem = operator new(nSize: 4 * v4 * v5);
      v6 = operator new(nSize: 0x80u);
      lpBuffer = v6;
      if ( pMem != nullptr && v6 != nullptr )
      {
        if ( D3DXTex::CDataCollector::WriteData(
               this: a2,
               lpBuffer: (char *)D3DXTex::pHDRHeaderString,
               a3: strlen((const char *)D3DXTex::pHDRHeaderString),
               lpNumberOfBytesWritten: &v40) >= 0 )
        {
          _strtime(buffer);
          if ( D3DXTex::CDataCollector::WriteData(
                 this: a2,
                 lpBuffer: buffer,
                 a3: strlen(buffer),
                 lpNumberOfBytesWritten: &v40) >= 0
            && D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: " ", a3: 1u, lpNumberOfBytesWritten: &v40) >= 0 )
          {
            _strdate(buffer);
            if ( D3DXTex::CDataCollector::WriteData(
                   this: a2,
                   lpBuffer: buffer,
                   a3: strlen(buffer),
                   lpNumberOfBytesWritten: &v40) >= 0
              && D3DXTex::CDataCollector::WriteData(this: a2, lpBuffer: "\n\n", a3: 2u, lpNumberOfBytesWritten: &v40) >= 0 )
            {
              StringCbPrintfA(
                string: buffer,
                a2: 0x100u,
                format: "-Y %u +X %u\n",
                *((_DWORD *)this + 4),
                *((_DWORD *)this + 3));
              if ( D3DXTex::CDataCollector::WriteData(
                     this: a2,
                     lpBuffer: buffer,
                     a3: strlen(buffer),
                     lpNumberOfBytesWritten: &v40) >= 0 )
              {
                v31 = 0;
                if ( *((_DWORD *)this + 4) != 0 )
                {
                  do
                  {
                    v7 = *((_DWORD *)this + 3);
                    v8 = (float *)(*((_DWORD *)this + 1) + v31 * *((_DWORD *)this + 12));
                    v28 = 0;
                    v9 = (unsigned __int8 *)pMem + 4 * v31 * v7;
                    if ( v7 != 0 )
                    {
                      do
                      {
                        if ( *v8 <= 0.0 )
                          v38 = 0.0;
                        else
                          v38 = *v8;
                        if ( v8[1] <= 0.0 )
                          v39 = 0.0;
                        else
                          v39 = v8[1];
                        if ( v8[2] <= 0.0 )
                          v10 = 0.0;
                        else
                          v10 = v8[2];
                        v25 = v10;
                        v11 = v38;
                        if ( v38 <= (double)v39 )
                          v11 = v39;
                        v41 = v11;
                        if ( v11 <= v10 )
                          v41 = v10;
                        if ( v41 <= 1.0e-32 )
                        {
                          v9[3] = 0;
                          v9[2] = 0;
                          v9[1] = 0;
                          *v9 = 0;
                        }
                        else
                        {
                          v12 = frexp(x: v41, &expptr);
                          expptr += 128;
                          v13 = v12 / v41 * 256.0;
                          v14 = v39 * v13;
                          v42 = (__int64)(v38 * v13);
                          *v9 = v42;
                          v37 = (__int64)v14;
                          v9[1] = v37;
                          v15 = (__int64)(v13 * v25);
                          v16 = v42 == 0;
                          v9[2] = v15;
                          if ( !v16 || v37 != 0 || (_BYTE)v15 != 0 )
                            LOBYTE(v15) = 1;
                          v9[3] = (_BYTE)v15 == 0 ? 0 : expptr;
                        }
                        ++v28;
                        v8 += 4;
                        v9 += 4;
                      }
                      while ( v28 < *((_DWORD *)this + 3) );
                    }
                    ++v31;
                  }
                  while ( v31 < *((_DWORD *)this + 4) );
                  v2 = v30;
                }
                v38 = 0.0;
                if ( *((_DWORD *)this + 4) != 0 )
                {
                  while ( 1 )
                  {
                    v35 = BYTE1(*((_DWORD *)this + 3));
                    v36 = *((_BYTE *)this + 12);
                    Buffer = 2;
                    v34 = 2;
                    if ( D3DXTex::CDataCollector::WriteData(
                           this: v2,
                           lpBuffer: &Buffer,
                           a3: 4u,
                           lpNumberOfBytesWritten: &v40) < 0 )
                      break;
                    v39 = 0.0;
                    do
                    {
                      v17 = *((_DWORD *)this + 3);
                      v41 = 0.0;
                      v18 = (char *)pMem + 4 * LODWORD(v38) * v17 + LODWORD(v39);
                      if ( v17 != 0 )
                      {
                        do
                        {
                          v19 = LODWORD(v41) + 1;
                          v20 = 1;
                          if ( LODWORD(v41) + 1 >= v17 )
                            goto LABEL_47;
                          do
                          {
                            if ( v20 >= 0x7Fu )
                              break;
                            if ( v18[4 * v20] != *v18 )
                              break;
                            ++v20;
                          }
                          while ( LODWORD(v41) + (unsigned int)v20 < v17 );
                          if ( v20 <= 1u )
                          {
LABEL_47:
                            v22 = lpBuffer;
                            v42 = 1;
                            *(_BYTE *)lpBuffer = *v18;
                            if ( v19 < *((_DWORD *)this + 3) )
                            {
                              do
                              {
                                if ( v42 >= 0x7Fu )
                                  break;
                                v23 = v18[4 * v42];
                                if ( v18[4 * v42 - 4] == v23 )
                                  break;
                                v22[v42++] = v23;
                              }
                              while ( LODWORD(v41) + (unsigned int)v42 < *((_DWORD *)this + 3) );
                            }
                            if ( D3DXTex::CDataCollector::WriteData(
                                   this: v30,
                                   lpBuffer: (char *)&v42,
                                   a3: 1u,
                                   lpNumberOfBytesWritten: &v40) < 0
                              || D3DXTex::CDataCollector::WriteData(
                                   this: v30,
                                   (char *)lpBuffer,
                                   a3: v42,
                                   lpNumberOfBytesWritten: &v40) < 0 )
                            {
                              goto LABEL_60;
                            }
                            v21 = v42;
                          }
                          else
                          {
                            Buffer = v20 + 0x80;
                            v34 = *v18;
                            if ( D3DXTex::CDataCollector::WriteData(
                                   this: v30,
                                   lpBuffer: &Buffer,
                                   a3: 2u,
                                   lpNumberOfBytesWritten: &v40) < 0 )
                              goto LABEL_60;
                            v21 = v20;
                          }
                          LODWORD(v41) += v21;
                          v18 += 4 * v21;
                          v17 = *((_DWORD *)this + 3);
                        }
                        while ( LODWORD(v41) < v17 );
                        v2 = v30;
                      }
                      ++LODWORD(v39);
                    }
                    while ( SLODWORD(v39) < 4 );
                    if ( ++LODWORD(v38) >= *((_DWORD *)this + 4) )
                      goto LABEL_58;
                  }
                }
                else
                {
LABEL_58:
                  v26 = 0;
                }
              }
            }
          }
        }
      }
      else
      {
        v26 = -2147024882;
      }
LABEL_60:
      if ( pMem != nullptr )
        free(pMem);
      if ( lpBuffer != nullptr )
        free(pMem: (void *)lpBuffer);
    }
  }
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004218BF
// Name: public: long D3DXTex::CImage::Save(void const __near *,enum _D3DXIMAGE_FILEFORMAT,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CImage::Save(
        D3DXTex::CImage *this,
        struct D3DXCore::CBuffer **lpWideCharStr,
        enum _D3DXIMAGE_FILEFORMAT a3,
        unsigned int a4)
{
  D3DXTex::CImage *v4; // esi
  D3DXTex **v5; // edi
  const struct tagPALETTEENTRY *FormatInfo; // eax
  enum _D3DFORMAT ClosestFormat; // eax
  D3DXTex *v8; // edi
  char *v9; // eax
  D3DXTex::CImage *v10; // ebx
  int v11; // esi
  int v12; // eax
  const char *v13; // eax
  char *v14; // eax
  struct D3DXCore::CBuffer *v15; // edi
  unsigned int v16; // ebx
  const void *v17; // esi
  enum _D3DFORMAT v19; // [esp+0h] [ebp-F8h]
  const struct _D3DXFORMAT_INFO *v20; // [esp+0h] [ebp-F8h]
  enum _D3DFORMAT v21; // [esp+0h] [ebp-F8h]
  _DWORD v22[4]; // [esp+Ch] [ebp-ECh] BYREF
  _BYTE v23[24]; // [esp+1Ch] [ebp-DCh] BYREF
  _DWORD v24[11]; // [esp+34h] [ebp-C4h] BYREF
  _DWORD v25[2]; // [esp+60h] [ebp-98h] BYREF
  int v26; // [esp+68h] [ebp-90h]
  int v27; // [esp+6Ch] [ebp-8Ch]
  _DWORD v28[6]; // [esp+70h] [ebp-88h]
  _DWORD v29[11]; // [esp+88h] [ebp-70h]
  _BYTE v30[12]; // [esp+B4h] [ebp-44h] BYREF
  void *v31[5]; // [esp+C0h] [ebp-38h] BYREF
  int v32; // [esp+D4h] [ebp-24h]
  unsigned int v33; // [esp+E0h] [ebp-18h]
  enum _D3DFORMAT v34; // [esp+E4h] [ebp-14h]
  D3DXTex::CImage *v35; // [esp+E8h] [ebp-10h]
  void *pMem; // [esp+ECh] [ebp-Ch]
  D3DXTex::CImage *v37; // [esp+F0h] [ebp-8h]
  char *_locale; // [esp+F4h] [ebp-4h]
  enum _D3DXIMAGE_FILEFORMAT v39; // [esp+104h] [ebp+Ch]

  v4 = this;
  v35 = this;
  D3DXTex::CDataCollector::CDataCollector(this: (D3DXTex::CDataCollector *)v31);
  switch ( a3 )
  {
    case D3DXIFF_BMP:
    case D3DXIFF_DIB:
      v5 = (D3DXTex **)&unk_521270;
      goto LABEL_8;
    case D3DXIFF_JPG:
      v5 = (D3DXTex **)&unk_5212CC;
      goto LABEL_8;
    case D3DXIFF_TGA:
      v5 = (D3DXTex **)&unk_5212C0;
      goto LABEL_8;
    case D3DXIFF_PNG:
      v5 = (D3DXTex **)&unk_5212D4;
      goto LABEL_8;
    case D3DXIFF_DDS:
      v5 = (D3DXTex **)&unk_5212F0;
      goto LABEL_8;
    case D3DXIFF_HDR:
    case D3DXIFF_PFM:
      v5 = (D3DXTex **)&unk_5212E4;
LABEL_8:
      FormatInfo = (const struct tagPALETTEENTRY *)D3DXTex::GetFormatInfo(this: *(D3DXTex **)v4, a2: v19);
      ClosestFormat = D3DXTex::FindClosestFormat(
                        this: v5,
                        a2: *((const enum _D3DFORMAT **)v4 + 2),
                        a3: FormatInfo,
                        a4: v20);
      v8 = (D3DXTex *)ClosestFormat;
      v34 = ClosestFormat;
      if ( ClosestFormat == D3DFMT_UNKNOWN )
        goto LABEL_45;
      if ( ClosestFormat == *(_DWORD *)v4 )
        goto LABEL_21;
      D3DXTex::CBlt::CBlt(this: (D3DXTex::CBlt *)v30);
      v9 = (char *)(*((_DWORD *)D3DXTex::GetFormatInfo(this: v8, a2: v21) + 2) >> 3);
      _locale = v9;
      v37 = v4;
      break;
    default:
LABEL_45:
      v11 = -2005530516;
      goto LABEL_46;
  }
  do
  {
    v10 = v37;
    if ( v37 != nullptr )
    {
      while ( 1 )
      {
        pMem = operator new(nSize: (_DWORD)v9 * *((_DWORD *)v10 + 3) * *((_DWORD *)v10 + 5) * *((_DWORD *)v10 + 4));
        if ( pMem == nullptr )
        {
          D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v30);
          v11 = -2147024882;
          goto LABEL_46;
        }
        v22[0] = *((_DWORD *)v10 + 1);
        v22[1] = *(_DWORD *)v10;
        v22[2] = *((_DWORD *)v10 + 12);
        v22[3] = *((_DWORD *)v10 + 13);
        qmemcpy(v23, (char *)v10 + 24, sizeof(v23));
        qmemcpy(v24, (char *)v10 + 24, 0x18u);
        v24[9] = 0;
        v24[6] = 1;
        v24[10] = *((_DWORD *)v10 + 2);
        v25[0] = pMem;
        v25[1] = v34;
        v26 = (_DWORD)_locale * *((_DWORD *)v10 + 3);
        v27 = (_DWORD)_locale * *((_DWORD *)v10 + 3) * *((_DWORD *)v10 + 4);
        v28[0] = 0;
        v28[1] = 0;
        v28[2] = *((_DWORD *)v10 + 3);
        v28[3] = *((_DWORD *)v10 + 4);
        v28[4] = 0;
        v28[5] = *((_DWORD *)v10 + 5);
        qmemcpy(v29, v28, 24);
        v29[9] = 0;
        v29[6] = 1;
        v29[10] = *((_DWORD *)v10 + 2);
        v11 = D3DXTex::CBlt::Blt(
                this: (D3DXTex::CBlt *)v30,
                a2: (struct D3DX_BLT *)v25,
                a3: (struct D3DX_BLT *)v22,
                a4: 0x80001u);
        if ( v11 < 0 )
          break;
        if ( *((_DWORD *)v10 + 1) != 0 && *((_DWORD *)v10 + 14) != 0 )
        {
          free(pMem: *((void **)v10 + 1));
          *((_DWORD *)v10 + 1) = 0;
        }
        *(_DWORD *)v10 = v34;
        *((_DWORD *)v10 + 1) = pMem;
        qmemcpy((char *)v10 + 24, v29, 24);
        *((_DWORD *)v10 + 12) = v26;
        *((_DWORD *)v10 + 13) = v27;
        v9 = _locale;
        *((_DWORD *)v10 + 14) = 1;
        v10 = *((D3DXTex::CImage **)v10 + 19);
        if ( v10 == nullptr )
        {
          v4 = v35;
          goto LABEL_19;
        }
      }
      free(pMem);
      D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v30);
      goto LABEL_46;
    }
LABEL_19:
    v37 = *((D3DXTex::CImage **)v37 + 20);
  }
  while ( v37 != nullptr );
  D3DXTex::CBlt::~CBlt(this: (D3DXTex::CBlt *)v30);
LABEL_21:
  v12 = D3DXTex::CDataCollector::Setup(this: (D3DXTex::CDataCollector *)v31, lpWideCharStr, a3: a4);
  if ( v12 < 0 )
    goto LABEL_22;
  v13 = setlocale(_category: 4, _locale: nullptr);
  v14 = _strdup(string: v13);
  _locale = v14;
  if ( v14 == nullptr || (v4 = v35, strcmp(v14, "C") != 0) )
    setlocale(_category: 4, _locale: "C");
  switch ( a3 )
  {
    case D3DXIFF_BMP:
    case D3DXIFF_DIB:
      D3DXTex::CImage::SaveDIB(this: v4, a2: (struct D3DXTex::CDataCollector *)v31, a3: 1);
      break;
    case D3DXIFF_JPG:
      D3DXTex::CImage::SaveJPG(this: (D3DXTex **)v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    case D3DXIFF_TGA:
      D3DXTex::CImage::SaveTGA(this: v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    case D3DXIFF_PNG:
      D3DXTex::CImage::SavePNG(this: v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    case D3DXIFF_DDS:
      D3DXTex::CImage::SaveDDS(this: (D3DXTex **)v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    case D3DXIFF_PPM:
      break;
    case D3DXIFF_HDR:
      D3DXTex::CImage::SaveHDR(this: v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    case D3DXIFF_PFM:
      D3DXTex::CImage::SavePFM(this: v4, a2: (struct D3DXTex::CDataCollector *)v31);
      break;
    default:
      goto LABEL_45;
  }
  v39 = D3DXTex::CDataCollector::Flush(this: (D3DXTex::CDataCollector *)v31);
  if ( _locale != nullptr )
  {
    if ( strcmp(_locale, "C") != 0 )
      setlocale(_category: 4, _locale);
    free(pMem: _locale);
  }
  v11 = v39;
  if ( v39 >= D3DXIFF_BMP )
  {
    if ( a4 == 2 )
    {
      v12 = D3DXCore::CBuffer::Create(a1: v33, a2: lpWideCharStr);
      if ( v12 < 0 )
      {
LABEL_22:
        v11 = v12;
        goto LABEL_46;
      }
      v15 = *lpWideCharStr;
      v16 = v33;
      v17 = (const void *)(*(int (__stdcall **)(int))(*(_DWORD *)v32 + 12))(a1: v32);
      qmemcpy((void *)(*(int (__stdcall **)(struct D3DXCore::CBuffer *))(*(_DWORD *)v15 + 12))(a1: v15), v17, v16);
    }
    v11 = 0;
  }
LABEL_46:
  D3DXTex::CDataCollector::~CDataCollector(this: v31);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00421C98
// Name: public: D3DXTex::CBlt::CBlt(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXTex::CBlt *__thiscall D3DXTex::CBlt::CBlt(D3DXTex::CBlt *this)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421CA2
// Name: public: D3DXTex::CBlt::~CBlt(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXTex::CBlt::~CBlt(D3DXTex::CBlt *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 1);
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  if ( *(_DWORD *)this != 0 )
    (***(void (__thiscall ****)(_DWORD, int))this)(a1: *(_DWORD *)this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00421CC2
// Name: floorf(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __stdcall floorf(float a1)
{
  return floor(X: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00421CDA
// Name: public: D3DXTex::TF_Row::TF_Row(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXTex::TF_Row::TF_Row(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421CE7
// Name: public: D3DXTex::TF_Row::~TF_Row(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXTex::TF_Row::~TF_Row(void **this)
{
  free(pMem: *this);
}

//------------------------------------------------------------------------------
// Address: 0x00421CF0
// Name: sub_421CF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__stdcall sub_421CF0(unsigned int a1, signed int a2, int a3)
{
  unsigned int v3; // edi
  double v4; // st7
  double v5; // st6
  unsigned int v6; // esi
  __int64 v7; // rax
  _DWORD *v8; // edi
  int v9; // ebx
  int v10; // esi
  double v11; // st7
  double v12; // st7
  int v13; // edx
  double v14; // st7
  int v15; // ecx
  float *v16; // eax
  double v17; // st6
  float *v18; // eax
  float v20; // [esp+0h] [ebp-4Ch]
  _DWORD *v21; // [esp+10h] [ebp-3Ch]
  int v22; // [esp+14h] [ebp-38h]
  float v23; // [esp+18h] [ebp-34h]
  float v24; // [esp+1Ch] [ebp-30h]
  float v25; // [esp+20h] [ebp-2Ch]
  float v26; // [esp+24h] [ebp-28h]
  int i; // [esp+28h] [ebp-24h]
  float v28; // [esp+2Ch] [ebp-20h]
  float v29; // [esp+30h] [ebp-1Ch]
  unsigned int v30; // [esp+34h] [ebp-18h]
  float v31; // [esp+38h] [ebp-14h]
  float v32; // [esp+3Ch] [ebp-10h]
  unsigned int v33; // [esp+40h] [ebp-Ch]
  float v34; // [esp+44h] [ebp-8h]
  float v35; // [esp+48h] [ebp-4h]

  v3 = 0;
  if ( a1 != 0 && a2 != 0 )
  {
    v29 = (float)(unsigned int)a2;
    v4 = (double)a1;
    v24 = v4;
    v5 = v29 / v4;
    v6 = 16;
    v26 = v5;
    v23 = 0.5 / v5;
    do
    {
      v7 = (__int64)(((double)v3 - 0.5) * v5 + v5 - ((double)v3 - 0.5) * v5 + (double)(a3 != 0) + 1.0);
      ++v3;
      v6 += 16 * v7 + 12;
    }
    while ( v3 < a1 );
    v8 = operator new(nSize: v6);
    if ( v8 != nullptr )
    {
      v9 = 0;
      v30 = 0;
      v35 = 0.0;
      v10 = 1;
      while ( 1 )
      {
        v33 = 0;
        v21 = &v8[v10];
        v22 = v10 * 4;
        ++v10;
        do
        {
          v25 = (float)v30;
          v11 = (double)v33 + v25 - 0.5;
          v32 = v11;
          v12 = v11 * v26;
          v28 = v12;
          v34 = v26 + v12;
          if ( a3 == 0 )
          {
            if ( v12 < 0.0 )
            {
              v12 = 0.0;
              v28 = 0.0;
            }
            if ( v34 > (double)v29 )
              v34 = (float)(unsigned int)a2;
          }
          v20 = v12;
          v13 = (__int64)floorf(a1: v20);
          v14 = (double)v13;
          if ( v14 < v34 )
          {
            v15 = v13 - a2;
            for ( i = v13 - a2; ; v15 = i )
            {
              v31 = v14 + 1.0;
              if ( v13 >= 0 )
              {
                if ( v13 < a2 )
                  v15 = v13;
              }
              else
              {
                v15 = v13 + a2;
              }
              if ( v15 != v9 )
              {
                if ( v35 > 0.0000099999997 )
                {
                  v16 = (float *)&v8[v10];
                  *(_DWORD *)v16 = v9;
                  v10 += 2;
                  v16[1] = v35;
                }
                v9 = v15;
                v35 = 0.0;
              }
              if ( v14 < v28 )
                v14 = v28;
              if ( v31 > (double)v34 )
                v31 = v34;
              if ( a3 != 0 )
                goto LABEL_33;
              if ( v32 < 0.0 )
              {
                v17 = 1.0;
                goto LABEL_34;
              }
              if ( v32 + 1.0 < v24 )
LABEL_33:
                v17 = (v31 + v14) * v23 - v32;
              else
                v17 = 0.0;
LABEL_34:
              if ( v33 != 0 )
                v17 = 1.0 - v17;
              ++v13;
              ++i;
              v35 = (v31 - v14) * v17 + v35;
              v14 = (double)v13;
              if ( v14 >= v34 )
                break;
            }
          }
          ++v33;
        }
        while ( v33 < 2 );
        if ( v35 > 0.0000099999997 )
        {
          v18 = (float *)&v8[v10];
          v10 += 2;
          *(_DWORD *)v18 = v9;
          v18[1] = v35;
        }
        v35 = 0.0;
        ++v30;
        *v21 = v10 * 4 - v22;
        if ( v30 >= a1 )
        {
          *v8 = v10 * 4;
          return v8;
        }
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00421FAE
// Name: protected: long D3DXTex::CBlt::BltSame_DXTn(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltSame_DXTn(D3DXTex::CBlt *this)
{
  _DWORD *v2; // esi
  int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi
  int v7; // edx
  _DWORD *v8; // eax
  int v9; // edx
  D3DXTex::CBlt *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // esi
  char *v14; // edi
  int v15; // ecx
  int v16; // esi
  unsigned int v17; // [esp+8h] [ebp-18h]
  D3DXTex::CBlt *v18; // [esp+Ch] [ebp-14h]
  char *i; // [esp+Ch] [ebp-14h]
  char *v20; // [esp+10h] [ebp-10h]
  unsigned int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+1Ch] [ebp-4h]
  unsigned int v24; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD **)this;
  v3 = *(_DWORD *)(*(_DWORD *)this + 68) | *(_DWORD *)(*(_DWORD *)this + 72);
  v4 = *(_DWORD *)(*(_DWORD *)this + 64);
  v5 = v2[15];
  v18 = this;
  if ( (((unsigned __int8)v4 | (unsigned __int8)(v5 | v3)) & 3) != 0 )
    return -2147467259;
  if ( ((*(_BYTE *)(*((_DWORD *)this + 1) + 60)
       | (unsigned __int8)(*(_BYTE *)(*((_DWORD *)this + 1) + 64)
                         | *(_BYTE *)(*((_DWORD *)this + 1) + 68)
                         | *(_BYTE *)(*((_DWORD *)this + 1) + 72)))
      & 3) != 0 )
    return -2147467259;
  v7 = *(_DWORD *)(*((_DWORD *)this + 1) + 4);
  if ( v7 == 827611204 )
  {
    v23 = 8;
  }
  else
  {
    if ( v7 != 844388420 && v7 != 861165636 && v7 != 877942852 && v7 != 894720068 )
      return -2147467259;
    v23 = 16;
  }
  v8 = *((_DWORD **)this + 1);
  v17 = v23 * (v8[26] >> 2);
  v21 = 0;
  v9 = v8[8] + v23 * (v8[15] >> 2) + v8[19] * v8[25] + v8[24] * (v8[16] >> 2);
  v10 = v18;
  v22 = v2[8] + v23 * (v5 >> 2) + v2[19] * v2[25] + v2[24] * (v4 >> 2);
  v11 = *((_DWORD *)v18 + 1);
  if ( *(_DWORD *)(v11 + 112) != 0 )
  {
    v12 = *(_DWORD *)(v11 + 108);
    do
    {
      v13 = (char *)v22;
      v24 = 0;
      v14 = (char *)v9;
      v20 = (char *)v9;
      for ( i = (char *)v22; v24 < v12; i = v13 )
      {
        v24 += 4;
        qmemcpy(v14, v13, v17);
        v15 = *((_DWORD *)v10 + 1);
        v14 = &v20[*(_DWORD *)(v15 + 96)];
        v13 = &i[*(_DWORD *)(*(_DWORD *)v10 + 96)];
        v12 = *(_DWORD *)(v15 + 108);
        v20 = v14;
      }
      v16 = *((_DWORD *)v10 + 1);
      v22 += *(_DWORD *)(*(_DWORD *)v10 + 100);
      v9 += *(_DWORD *)(v16 + 100);
      ++v21;
    }
    while ( v21 < *(_DWORD *)(v16 + 112) );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422106
// Name: long D3DXTex::c_BoxFilter2D_A8R8G8B8(unsigned int __near *,unsigned int __near *,unsigned int,unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall D3DXTex::c_BoxFilter2D_A8R8G8B8(
        D3DXTex *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  unsigned int *v7; // edx
  unsigned int v8; // edi
  unsigned int *v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // ebx
  _DWORD *v12; // ecx
  bool v13; // zf
  unsigned int *v15; // [esp+4h] [ebp-14h]
  unsigned int v16; // [esp+8h] [ebp-10h]
  unsigned int *v17; // [esp+Ch] [ebp-Ch]
  unsigned int v18; // [esp+10h] [ebp-8h]
  D3DXTex *v19; // [esp+14h] [ebp-4h]
  unsigned int *v20; // [esp+28h] [ebp+10h]
  unsigned int *v21; // [esp+2Ch] [ebp+14h]

  v7 = a2;
  v8 = a5;
  v15 = (unsigned int *)((char *)a2 + a5 * a4);
  if ( a2 < v15 )
  {
    v21 = &a2[(_DWORD)a3];
    do
    {
      v19 = this;
      if ( v7 < v21 )
      {
        v9 = v7 + 1;
        v17 = v7 + 1;
        v16 = ((unsigned int)((char *)v21 - (char *)v7 - 1) >> 3) + 1;
        do
        {
          v18 = *(unsigned int *)((char *)v9 + v8 - 4);
          v20 = *(unsigned int **)((char *)v9 + v8);
          v10 = *v9;
          v8 = a5;
          v11 = ((((unsigned int)v20 >> 2) & 0x3FC03FC0)
               + ((v18 >> 2) & 0x3FC03FC0)
               + ((*(v9 - 1) >> 2) & 0x3FC03FC0)
               + ((v10 >> 2) & 0x3FC03FC0)
               + 8388736)
              ^ (((((unsigned int)v20 & 0xFF00FF) + (v18 & 0xFF00FF) + (*(v9 - 1) & 0xFF00FF) + (v10 & 0xFF00FF) + 131074) >> 2)
               ^ ((((unsigned int)v20 >> 2) & 0x3FC03FC0)
                + ((v18 >> 2) & 0x3FC03FC0)
                + ((*(v9 - 1) >> 2) & 0x3FC03FC0)
                + ((v10 >> 2) & 0x3FC03FC0)
                - 8388480))
              & 0xFF00FF;
          v12 = v19;
          v19 = (D3DXTex *)((char *)v19 + 4);
          *v12 = v11;
          v9 = v17 + 2;
          v13 = v16-- == 1;
          v17 += 2;
        }
        while ( !v13 );
        v7 = a2;
      }
      this = (D3DXTex *)((char *)this + a6);
      v21 = (unsigned int *)((char *)v21 + 2 * v8);
      v7 = (unsigned int *)((char *)v7 + 2 * v8);
      a2 = v7;
    }
    while ( v7 < v15 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422230
// Name: protected: long D3DXTex::CBlt::BltBox2D_A8R8G8B8(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A8R8G8B8(D3DXTex::CBlt *this)
{
  return D3DXTex::g_pBoxFilter2D_A8R8G8B8();
}

//------------------------------------------------------------------------------
// Address: 0x00422252
// Name: sub_422252
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_422252(unsigned int *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax
  unsigned int v7; // edi
  _DWORD *v8; // esi
  unsigned int v9; // ebx
  unsigned int *v10; // eax
  bool v11; // zf
  unsigned int v13; // [esp+4h] [ebp-14h]
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int *v15; // [esp+28h] [ebp+10h]
  unsigned int v16; // [esp+2Ch] [ebp+14h]

  v6 = a5;
  v7 = a2;
  v13 = a2 + a5 * a4;
  if ( a2 < v13 )
  {
    v16 = a2 + 4 * a3;
    do
    {
      v15 = a1;
      if ( v7 < v16 )
      {
        v8 = (_DWORD *)(v7 + 4);
        v14 = ((v16 - v7 - 1) >> 3) + 1;
        do
        {
          v9 = ((*(_DWORD *)((char *)v8 + v6) & 0xFF00)
              + (*(_DWORD *)((char *)v8 + v6 - 4) & 0xFF00)
              + (*(v8 - 1) & 0xFF00)
              + (*v8 & 0xFF00)
              + 512)
             & 0x3FC00
             | ((*(_DWORD *)((char *)v8 + v6) & 0xFF00FF)
              + (*(_DWORD *)((char *)v8 + v6 - 4) & 0xFF00FF)
              + (*(v8 - 1) & 0xFF00FF)
              + (*v8 & 0xFF00FF)
              + 131074)
             & 0x3FC03FC;
          v10 = v15++;
          v8 += 2;
          v11 = v14-- == 1;
          *v10 = v9 >> 2;
          v6 = a5;
        }
        while ( !v11 );
        v7 = a2;
      }
      a1 = (unsigned int *)((char *)a1 + a6);
      v16 += 2 * v6;
      v7 += 2 * v6;
      a2 = v7;
    }
    while ( v7 < v13 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042233E
// Name: sub_42233E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_42233E(
        D3DXTex *a1,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  unsigned int *v7; // eax
  D3DXTex *i; // edx
  __m64 *v9; // edi
  __m64 *v10; // esi
  __m64 *v11; // ebx
  __m64 *j; // eax
  __m64 v13; // mm5
  __m64 v14; // mm7
  __m64 v15; // mm2
  __m64 v16; // mm3
  __m64 *v17; // ecx
  __m64 v18; // mm0
  unsigned int v19; // [esp+0h] [ebp-18h]
  unsigned int *v20; // [esp+10h] [ebp-8h]
  unsigned int *v21; // [esp+28h] [ebp+10h]
  unsigned int *v22; // [esp+2Ch] [ebp+14h]

  if ( ((unsigned __int8)a3 & 3) != 0 )
    return D3DXTex::c_BoxFilter2D_A8R8G8B8(this: a1, a2, a3, a4, a5, a6, a7: v19);
  v22 = (unsigned int *)((char *)a2 + a5 * a4);
  _m_empty();
  v21 = (unsigned int *)(4 * (_DWORD)a3);
  v7 = a2;
  for ( i = a1; (int)v7 < (int)v22; i = (D3DXTex *)((char *)i + a6) )
  {
    v9 = (__m64 *)v7;
    v10 = (__m64 *)((char *)v7 + a5);
    v11 = (__m64 *)((char *)v7 + (_DWORD)v21);
    v20 = v7;
    for ( j = (__m64 *)i;
          (int)v9 < (int)v11;
          v17->m64_u64 = (unsigned __int64)_m_packuswb(
                                             _m_psrawi(
                                               _m_paddw(_m_paddw(_m_paddw(v18, v15), v16), (__m64)0x2000200020002LL),
                                               2u),
                                             _m_psrawi(
                                               _m_paddw(
                                                 _m_paddw(
                                                   _m_paddw(
                                                     _m_paddw(_m_punpcklbw(v13, 0), _m_punpckhbw(v13, 0)),
                                                     _m_punpcklbw(v14, 0)),
                                                   _m_punpckhbw(v14, 0)),
                                                 (__m64)0x2000200020002LL),
                                               2u)) )
    {
      v13 = v9[1];
      v14 = v10[1];
      v15 = _m_punpcklbw((__m64)v10->m64_u64, 0);
      v16 = _m_punpckhbw((__m64)v10->m64_u64, 0);
      v17 = j;
      v18 = _m_paddw(_m_punpcklbw((__m64)v9->m64_u64, 0), _m_punpckhbw((__m64)v9->m64_u64, 0));
      v9 += 2;
      v10 += 2;
      ++j;
    }
    v7 = (unsigned int *)((char *)v20 + a5 + a5);
  }
  _m_empty();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422458
// Name: sub_422458
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_422458()
{
  if ( isMMXprocessor() != 0 )
  {
    D3DXTex::g_pBoxFilter2D_A8R8G8B8 = (_DWORD (*)())sub_42233E;
    D3DXTex::g_pBoxFilter2D_X8R8G8B8 = (int (__stdcall *)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int))sub_42233E;
  }
  else
  {
    D3DXTex::g_pBoxFilter2D_A8R8G8B8 = (_DWORD (*)())D3DXTex::c_BoxFilter2D_A8R8G8B8;
    D3DXTex::g_pBoxFilter2D_X8R8G8B8 = (int (__stdcall *)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int))sub_422252;
  }
  return D3DXTex::g_pBoxFilter2D_A8R8G8B8();
}

//------------------------------------------------------------------------------
// Address: 0x00422492
// Name: sub_422492
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall sub_422492(
        D3DXTex *a1,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  int (__stdcall *v6)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int); // eax

  if ( isMMXprocessor() != 0 )
  {
    v6 = (int (__stdcall *)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int))sub_42233E;
    D3DXTex::g_pBoxFilter2D_A8R8G8B8 = (_DWORD (*)())sub_42233E;
  }
  else
  {
    D3DXTex::g_pBoxFilter2D_A8R8G8B8 = (_DWORD (*)())D3DXTex::c_BoxFilter2D_A8R8G8B8;
    v6 = (int (__stdcall *)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int))sub_422252;
  }
  D3DXTex::g_pBoxFilter2D_X8R8G8B8 = v6;
  return v6((unsigned int *)a1, a2, (unsigned int)a3, a4, a5, a6);
}

//------------------------------------------------------------------------------
// Address: 0x004224C3
// Name: protected: long D3DXTex::CBlt::BltBox2D_X8R8G8B8(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_X8R8G8B8(D3DXTex::CBlt *this)
{
  return D3DXTex::g_pBoxFilter2D_X8R8G8B8(
           a1: *(unsigned int **)(*((_DWORD *)this + 1) + 32),
           a2: *(unsigned int **)(*(_DWORD *)this + 32),
           a3: *(_DWORD *)(*(_DWORD *)this + 104),
           a4: *(_DWORD *)(*(_DWORD *)this + 108),
           a5: *(_DWORD *)(*(_DWORD *)this + 96),
           a6: *(_DWORD *)(*((_DWORD *)this + 1) + 96));
}

//------------------------------------------------------------------------------
// Address: 0x004224E5
// Name: protected: long D3DXTex::CBlt::BltBox2D_R5G6B5(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_R5G6B5(D3DXTex::CBlt *this)
{
  _DWORD *v2; // edx
  _WORD *v3; // ecx
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // esi
  _WORD *v6; // edi
  __int16 v7; // dx
  unsigned __int16 v8; // si
  unsigned __int16 v9; // cx
  int v10; // ebx
  __int16 v11; // di
  int v12; // edx
  _WORD *v13; // ecx
  unsigned __int16 *i; // [esp+Ch] [ebp-24h]
  unsigned __int16 *v16; // [esp+10h] [ebp-20h]
  unsigned __int16 *v17; // [esp+18h] [ebp-18h]
  _WORD *v18; // [esp+1Ch] [ebp-14h]
  _WORD *v19; // [esp+20h] [ebp-10h]
  unsigned __int16 *v20; // [esp+24h] [ebp-Ch]
  _WORD *v21; // [esp+28h] [ebp-8h]
  __int16 v22; // [esp+2Ch] [ebp-4h]

  v2 = *(_DWORD **)this;
  v3 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v4 = (unsigned __int16 *)v2[8];
  v5 = (unsigned __int16 *)((char *)v4 + v2[24] * v2[27]);
  v18 = v3;
  v17 = v4;
  for ( i = v5; v4 < v5; v17 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + v2[24]);
    v21 = v3;
    v20 = v4;
    v19 = v6;
    v16 = &v4[v2[26]];
    if ( v4 < v16 )
    {
      do
      {
        v7 = v6[1];
        v8 = v4[1];
        v22 = *v6;
        v9 = *v4;
        v10 = *v4;
        LOWORD(v10) = v10 & 0xF81F;
        v11 = (((v22 & 0x7E0) + (v9 & 0x7E0) + (v7 & 0x7E0) + (v8 & 0x7E0u) + 64) >> 2)
            ^ (((v22 & 0xF81F) + v10 + (v7 & 0xF81F) + (v8 & 0xF81Fu) + 4098) >> 2);
        v12 = (v22 & 0xF81F) + (v9 & 0xF81F) + (v7 & 0xF81F);
        v13 = v21++;
        *v13 = ((v12 + (v8 & 0xF81Fu) + 4098) >> 2) ^ v11 & 0x7E0;
        v4 = v20 + 2;
        v6 = v19 + 2;
        v20 = v4;
        v19 += 2;
      }
      while ( v4 < v16 );
      v3 = v18;
      v4 = v17;
      v5 = i;
    }
    v3 = (_WORD *)((char *)v3 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v2 = *(_DWORD **)this;
    v4 += *(_DWORD *)(*(_DWORD *)this + 96);
    v18 = v3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422619
// Name: protected: long D3DXTex::CBlt::BltBox2D_X1R5G5B5(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_X1R5G5B5(D3DXTex::CBlt *this)
{
  _DWORD *v2; // edx
  _WORD *v3; // ecx
  char *v4; // ebx
  char *v5; // esi
  __int16 *v6; // edi
  __int16 v7; // dx
  _WORD *v8; // ecx
  char *i; // [esp+Ch] [ebp-20h]
  char *v11; // [esp+10h] [ebp-1Ch]
  char *v12; // [esp+18h] [ebp-14h]
  _WORD *v13; // [esp+1Ch] [ebp-10h]
  char *v14; // [esp+20h] [ebp-Ch]
  __int16 v15; // [esp+24h] [ebp-8h]
  _WORD *v16; // [esp+28h] [ebp-4h]

  v2 = *(_DWORD **)this;
  v3 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v4 = (char *)v2[8];
  v5 = &v4[v2[24] * v2[27]];
  v13 = v3;
  v12 = v4;
  for ( i = v5; v4 < v5; v12 = v4 )
  {
    v6 = (__int16 *)&v4[v2[24]];
    v16 = v3;
    v14 = v4;
    v11 = &v4[2 * v2[26]];
    if ( v4 < v11 )
    {
      do
      {
        v7 = v6[1];
        v15 = *v6;
        v6 += 2;
        v8 = v16++;
        *v8 = (((v15 & 0x7C1F) + (*(_WORD *)v4 & 0x7C1F) + (v7 & 0x7C1F) + (*((_WORD *)v4 + 1) & 0x7C1Fu) + 2050) >> 2)
            & 0x7C1F
            | (((v15 & 0x3E0) + (*(_WORD *)v4 & 0x3E0) + (v7 & 0x3E0) + (*((_WORD *)v4 + 1) & 0x3E0u) + 64) >> 2)
            & 0x3E0;
        v4 = v14 + 4;
        v14 += 4;
      }
      while ( v14 < v11 );
      v3 = v13;
      v4 = v12;
      v5 = i;
    }
    v3 = (_WORD *)((char *)v3 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v2 = *(_DWORD **)this;
    v4 += 2 * *(_DWORD *)(*(_DWORD *)this + 96);
    v13 = v3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042271E
// Name: protected: long D3DXTex::CBlt::BltBox2D_A1R5G5B5(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A1R5G5B5(D3DXTex::CBlt *this)
{
  int v1; // eax
  _DWORD *v2; // ecx
  char *v3; // ebx
  _WORD *v4; // esi
  char *v5; // edi
  __int16 v6; // si
  __int16 v7; // cx
  __int16 v8; // di
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  int v11; // esi
  _WORD *v12; // ecx
  char *i; // [esp+8h] [ebp-2Ch]
  char *v16; // [esp+10h] [ebp-24h]
  char *v17; // [esp+18h] [ebp-1Ch]
  _WORD *v18; // [esp+1Ch] [ebp-18h]
  char *v19; // [esp+20h] [ebp-14h]
  char *v20; // [esp+24h] [ebp-10h]
  _WORD *v21; // [esp+28h] [ebp-Ch]
  __int16 v22; // [esp+2Ch] [ebp-8h]
  __int16 v23; // [esp+30h] [ebp-4h]

  v1 = *((_DWORD *)this + 1);
  v2 = *(_DWORD **)this;
  v3 = (char *)v2[8];
  v4 = *(_WORD **)(v1 + 32);
  v18 = v4;
  v17 = v3;
  for ( i = &v3[v2[24] * v2[27]]; v3 < i; v17 = v3 )
  {
    v5 = &v3[v2[24]];
    v21 = v4;
    v20 = v3;
    v19 = v5;
    v16 = &v3[2 * v2[26]];
    if ( v3 < v16 )
    {
      do
      {
        v6 = *((_WORD *)v5 + 1);
        v22 = *((_WORD *)v3 + 1);
        v7 = *(_WORD *)v5;
        v8 = *(_WORD *)v3;
        v23 = v7;
        v9 = (v7 & 0x83E0) + (*(_WORD *)v3 & 0x83E0) + (v6 & 0x83E0) + (v22 & 0x83E0) + 65600;
        v10 = ((v7 & 0x7C1F) + (v8 & 0x7C1F) + (v6 & 0x7C1F) + (v22 & 0x7C1Fu) + 2050) >> 2;
        v11 = (v23 & 0x83E0) + (v8 & 0x83E0) + (v6 & 0x83E0);
        v5 = v19 + 4;
        v19 += 4;
        LOWORD(v9) = ((v11 + (v22 & 0x83E0u) + 65600) >> 2) ^ (v10 ^ (v9 >> 2)) & 0x7C1F;
        v12 = v21++;
        *v12 = v9;
        v3 = v20 + 4;
        v20 += 4;
      }
      while ( v20 < v16 );
      v3 = v17;
    }
    v4 = (_WORD *)((char *)v18 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v2 = *(_DWORD **)this;
    v3 += 2 * *(_DWORD *)(*(_DWORD *)this + 96);
    v18 = v4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422847
// Name: protected: long D3DXTex::CBlt::BltBox2D_A4R4G4B4(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A4R4G4B4(D3DXTex::CBlt *this)
{
  _DWORD *v2; // edx
  _WORD *v3; // ecx
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // esi
  _WORD *v6; // edi
  __int16 v7; // dx
  unsigned __int16 v8; // si
  unsigned __int16 v9; // cx
  int v10; // ebx
  __int16 v11; // di
  int v12; // edx
  _WORD *v13; // ecx
  unsigned __int16 *i; // [esp+Ch] [ebp-24h]
  unsigned __int16 *v16; // [esp+10h] [ebp-20h]
  unsigned __int16 *v17; // [esp+18h] [ebp-18h]
  _WORD *v18; // [esp+1Ch] [ebp-14h]
  _WORD *v19; // [esp+20h] [ebp-10h]
  unsigned __int16 *v20; // [esp+24h] [ebp-Ch]
  _WORD *v21; // [esp+28h] [ebp-8h]
  __int16 v22; // [esp+2Ch] [ebp-4h]

  v2 = *(_DWORD **)this;
  v3 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v4 = (unsigned __int16 *)v2[8];
  v5 = (unsigned __int16 *)((char *)v4 + v2[24] * v2[27]);
  v18 = v3;
  v17 = v4;
  for ( i = v5; v4 < v5; v17 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + v2[24]);
    v21 = v3;
    v20 = v4;
    v19 = v6;
    v16 = &v4[v2[26]];
    if ( v4 < v16 )
    {
      do
      {
        v7 = v6[1];
        v8 = v4[1];
        v22 = *v6;
        v9 = *v4;
        v10 = *v4;
        LOWORD(v10) = v10 & 0xF0F0;
        v11 = (((v22 & 0xF0F) + (v9 & 0xF0F) + (v7 & 0xF0F) + (v8 & 0xF0Fu) + 514) >> 2)
            ^ (((v22 & 0xF0F0) + v10 + (v7 & 0xF0F0) + (v8 & 0xF0F0u) + 8224) >> 2);
        v12 = (v22 & 0xF0F0) + (v9 & 0xF0F0) + (v7 & 0xF0F0);
        v13 = v21++;
        *v13 = ((v12 + (v8 & 0xF0F0u) + 8224) >> 2) ^ v11 & 0xF0F;
        v4 = v20 + 2;
        v6 = v19 + 2;
        v20 = v4;
        v19 += 2;
      }
      while ( v4 < v16 );
      v3 = v18;
      v4 = v17;
      v5 = i;
    }
    v3 = (_WORD *)((char *)v3 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v2 = *(_DWORD **)this;
    v4 += *(_DWORD *)(*(_DWORD *)this + 96);
    v18 = v3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042297E
// Name: protected: long D3DXTex::CBlt::BltBox2D_R3G3B2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_R3G3B2(D3DXTex::CBlt *this)
{
  _BYTE *v2; // ecx
  _DWORD *v3; // eax
  _BYTE *v4; // ebx
  _BYTE *v5; // edi
  _BYTE *v6; // edx
  char v7; // al
  char v8; // di
  char v9; // dl
  _BYTE *v10; // eax
  D3DXTex::CBlt *v12; // [esp+8h] [ebp-28h]
  _BYTE *i; // [esp+Ch] [ebp-24h]
  _BYTE *v14; // [esp+10h] [ebp-20h]
  _BYTE *v15; // [esp+18h] [ebp-18h]
  _BYTE *v16; // [esp+1Ch] [ebp-14h]
  _BYTE *v17; // [esp+20h] [ebp-10h]
  _BYTE *v18; // [esp+24h] [ebp-Ch]
  _BYTE *v19; // [esp+28h] [ebp-8h]
  char v20; // [esp+2Ch] [ebp-4h]

  v2 = *(_BYTE **)(*((_DWORD *)this + 1) + 32);
  v12 = this;
  v3 = *(_DWORD **)this;
  v4 = (_BYTE *)v3[8];
  v5 = &v4[v3[24] * v3[27]];
  v16 = v2;
  v15 = v4;
  for ( i = v5; v4 < v5; v15 = v4 )
  {
    v6 = &v4[v3[24]];
    v19 = v2;
    v18 = v4;
    v17 = v6;
    v14 = &v4[v3[26]];
    if ( v4 < v14 )
    {
      do
      {
        v7 = v6[1];
        v8 = v4[1];
        v20 = *v6;
        v9 = (((v20 & 0xE3) + (*v4 & 0xE3) + (v7 & 0xE3) + (v8 & 0xE3u) + 66) >> 2)
           ^ ((((v20 & 0xE3) + (*v4 & 0xE3) + (v7 & 0xE3) + (v8 & 0xE3u) + 66) >> 2)
            ^ (((v20 & 0x1C) + (*v4 & 0x1C) + (v7 & 0x1C) + (v8 & 0x1Cu) + 8) >> 2))
           & 0x1C;
        v10 = v19++;
        *v10 = v9;
        v4 = v18 + 2;
        v6 = v17 + 2;
        v18 = v4;
        v17 += 2;
      }
      while ( v4 < v14 );
      v2 = v16;
      v4 = v15;
      v5 = i;
    }
    v2 += *(_DWORD *)(*((_DWORD *)v12 + 1) + 96);
    v3 = *(_DWORD **)v12;
    v4 += 2 * *(_DWORD *)(*(_DWORD *)v12 + 96);
    v16 = v2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422A9C
// Name: protected: long D3DXTex::CBlt::BltBox2D_A8(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A8(D3DXTex::CBlt *this)
{
  _BYTE *v1; // ebx
  int v2; // eax
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // edx
  unsigned int v6; // eax
  unsigned __int8 *v7; // edx
  int v8; // ecx
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // ebx
  D3DXTex::CBlt *v13; // [esp+Ch] [ebp-10h]
  _BYTE *v14; // [esp+10h] [ebp-Ch]
  _BYTE *v15; // [esp+14h] [ebp-8h]
  unsigned __int8 *v16; // [esp+18h] [ebp-4h]

  v1 = *(_BYTE **)(*((_DWORD *)this + 1) + 32);
  v2 = *(_DWORD *)this;
  v3 = *(unsigned __int8 **)(*(_DWORD *)this + 32);
  v13 = this;
  v4 = &v3[*(_DWORD *)(*(_DWORD *)this + 96) * *(_DWORD *)(*(_DWORD *)this + 108)];
  while ( 1 )
  {
    v14 = v1;
    if ( v3 >= v4 )
      break;
    v5 = *(_DWORD *)(v2 + 96);
    v6 = (unsigned int)&v3[*(_DWORD *)(v2 + 104)];
    v7 = &v3[v5];
    v15 = v1;
    v16 = v3;
    if ( (unsigned int)v3 < v6 )
    {
      do
      {
        v8 = *v7 + v16[1] + v7[1];
        v9 = *v16;
        v16 += 2;
        v10 = v8 + v9 + 2;
        v11 = v15++;
        v7 += 2;
        *v11 = v10 >> 2;
      }
      while ( (unsigned int)v16 < v6 );
      v1 = v14;
      this = v13;
    }
    v1 += *(_DWORD *)(*((_DWORD *)this + 1) + 96);
    v2 = *(_DWORD *)this;
    v3 += 2 * *(_DWORD *)(*(_DWORD *)this + 96);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422B28
// Name: protected: long D3DXTex::CBlt::BltBox2D_A8R3G3B2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A8R3G3B2(D3DXTex::CBlt *this)
{
  _WORD *v2; // ecx
  int v3; // esi
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // edi
  unsigned __int16 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  unsigned int v13; // edx
  int v14; // edi
  _WORD *v15; // ecx
  unsigned __int16 *i; // [esp+10h] [ebp-24h]
  unsigned __int16 *v18; // [esp+14h] [ebp-20h]
  unsigned __int16 *v19; // [esp+18h] [ebp-1Ch]
  _WORD *v20; // [esp+1Ch] [ebp-18h]
  unsigned __int16 *v21; // [esp+20h] [ebp-14h]
  unsigned __int16 *v22; // [esp+24h] [ebp-10h]
  unsigned __int16 v23; // [esp+28h] [ebp-Ch]
  _WORD *v24; // [esp+2Ch] [ebp-8h]
  int v25; // [esp+30h] [ebp-4h]

  v2 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v3 = *(_DWORD *)this;
  v4 = *(unsigned __int16 **)(*(_DWORD *)this + 32);
  v5 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(*(_DWORD *)this + 96) * *(_DWORD *)(*(_DWORD *)this + 108));
  v20 = v2;
  v19 = v4;
  for ( i = v5; v4 < v5; v19 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(v3 + 96));
    v24 = v2;
    v22 = v4;
    v21 = v6;
    v18 = &v4[*(_DWORD *)(v3 + 104)];
    if ( v4 < v18 )
    {
      do
      {
        v7 = v6[1];
        v8 = *v6;
        v9 = *v4;
        v10 = v4[1];
        v25 = v8;
        v23 = *v4;
        LOWORD(v9) = *v4 & 0xE3;
        v11 = (v8 & 0xE3) + v9 + (v7 & 0xE3);
        HIWORD(v8) = HIWORD(v7);
        v12 = v7 & 0xFF1C;
        LOWORD(v8) = v12;
        v13 = v11 + (v10 & 0xE3) + 66;
        HIWORD(v11) = HIWORD(v10);
        v14 = v10 & 0xFF1C;
        LOWORD(v11) = v14;
        LOWORD(v13) = (((v25 & 0xFF1C) + (v23 & 0xFF1Cu) + v12 + v14 + 520) >> 2)
                    ^ ((unsigned __int8)(((v25 & 0xFFFFFF1C) + (v23 & 0xFF1C) + v8 + v11 + 520) >> 2)
                     ^ (unsigned __int8)(v13 >> 2))
                    & 0xE3;
        v15 = v24++;
        *v15 = v13;
        v4 = v22 + 2;
        v6 = v21 + 2;
        v22 = v4;
        v21 += 2;
      }
      while ( v4 < v18 );
      v2 = v20;
      v4 = v19;
      v5 = i;
    }
    v2 = (_WORD *)((char *)v2 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v3 = *(_DWORD *)this;
    v4 += *(_DWORD *)(*(_DWORD *)this + 96);
    v20 = v2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422C56
// Name: protected: long D3DXTex::CBlt::BltBox2D_X4R4G4B4(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_X4R4G4B4(D3DXTex::CBlt *this)
{
  _WORD *v1; // edi
  int v2; // eax
  char *v3; // ebx
  char *v4; // edx
  char *v5; // esi
  int v6; // edx
  int v7; // edi
  unsigned int v8; // ebx
  int v9; // eax
  _WORD *v10; // eax
  char *i; // [esp+8h] [ebp-20h]
  D3DXTex::CBlt *v13; // [esp+Ch] [ebp-1Ch]
  char *v14; // [esp+10h] [ebp-18h]
  __int16 v15; // [esp+14h] [ebp-14h]
  char *v16; // [esp+18h] [ebp-10h]
  _WORD *v17; // [esp+1Ch] [ebp-Ch]
  char *v18; // [esp+20h] [ebp-8h]
  _WORD *v19; // [esp+24h] [ebp-4h]

  v1 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v2 = *(_DWORD *)this;
  v3 = *(char **)(*(_DWORD *)this + 32);
  v4 = &v3[*(_DWORD *)(*(_DWORD *)this + 96) * *(_DWORD *)(*(_DWORD *)this + 108)];
  v13 = this;
  v17 = v1;
  v16 = v3;
  for ( i = v4; v3 < v4; v16 = v3 )
  {
    v5 = &v3[*(_DWORD *)(v2 + 96)];
    v19 = v1;
    v18 = v3;
    v14 = &v3[2 * *(_DWORD *)(v2 + 104)];
    if ( v3 < v14 )
    {
      do
      {
        v6 = *((unsigned __int16 *)v3 + 1);
        v7 = *(unsigned __int16 *)v5;
        v15 = *(_WORD *)v3;
        v8 = (v7 & 0xF0) + (*(_WORD *)v3 & 0xF0) + (*((_WORD *)v5 + 1) & 0xF0) + (v6 & 0xF0) + 32;
        v9 = (v15 & 0xF0F) + (*((_WORD *)v5 + 1) & 0xF0F);
        LOWORD(v7) = v7 & 0xF0F;
        LOWORD(v6) = v6 & 0xF0F;
        v5 += 4;
        LOWORD(v8) = ((unsigned int)(v7 + v9 + v6 + 514) >> 2) & 0xF0F | (v8 >> 2) & 0xF0;
        v10 = v19++;
        *v10 = v8;
        v3 = v18 + 4;
        v18 += 4;
      }
      while ( v18 < v14 );
      this = v13;
      v1 = v17;
      v3 = v16;
      v4 = i;
    }
    v1 = (_WORD *)((char *)v1 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v2 = *(_DWORD *)this;
    v3 += 2 * *(_DWORD *)(*(_DWORD *)this + 96);
    v17 = v1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422D5F
// Name: protected: long D3DXTex::CBlt::BltBox2D_A8L8(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A8L8(D3DXTex::CBlt *this)
{
  _WORD *v2; // ecx
  int v3; // esi
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // edi
  unsigned __int16 *v6; // edx
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  unsigned int v13; // edx
  int v14; // edi
  _WORD *v15; // ecx
  unsigned __int16 *i; // [esp+10h] [ebp-24h]
  unsigned __int16 *v18; // [esp+14h] [ebp-20h]
  unsigned __int16 *v19; // [esp+18h] [ebp-1Ch]
  _WORD *v20; // [esp+1Ch] [ebp-18h]
  unsigned __int16 *v21; // [esp+20h] [ebp-14h]
  unsigned __int16 *v22; // [esp+24h] [ebp-10h]
  unsigned __int16 v23; // [esp+28h] [ebp-Ch]
  _WORD *v24; // [esp+2Ch] [ebp-8h]
  int v25; // [esp+30h] [ebp-4h]

  v2 = *(_WORD **)(*((_DWORD *)this + 1) + 32);
  v3 = *(_DWORD *)this;
  v4 = *(unsigned __int16 **)(*(_DWORD *)this + 32);
  v5 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(*(_DWORD *)this + 96) * *(_DWORD *)(*(_DWORD *)this + 108));
  v20 = v2;
  v19 = v4;
  for ( i = v5; v4 < v5; v19 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + *(_DWORD *)(v3 + 96));
    v24 = v2;
    v22 = v4;
    v21 = v6;
    v18 = &v4[*(_DWORD *)(v3 + 104)];
    if ( v4 < v18 )
    {
      do
      {
        v7 = v6[1];
        v8 = *v6;
        v9 = *v4;
        v10 = v4[1];
        v25 = v8;
        v23 = *v4;
        LOWORD(v9) = (unsigned __int8)*v4;
        v11 = (unsigned __int8)v8 + v9 + (unsigned __int8)v7;
        HIWORD(v8) = HIWORD(v7);
        v12 = v7 & 0xFF00;
        LOWORD(v8) = v12;
        v13 = v11 + (unsigned __int8)v10 + 2;
        HIWORD(v11) = HIWORD(v10);
        v14 = v10 & 0xFF00;
        LOWORD(v11) = v14;
        LOWORD(v13) = (((v25 & 0xFF00) + (v23 & 0xFF00u) + v12 + v14 + 512) >> 2)
                    ^ (unsigned __int8)((((v25 & 0xFFFFFF00) + (v23 & 0xFF00) + v8 + v11 + 512) >> 2) ^ (v13 >> 2));
        v15 = v24++;
        *v15 = v13;
        v4 = v22 + 2;
        v6 = v21 + 2;
        v22 = v4;
        v21 += 2;
      }
      while ( v4 < v18 );
      v2 = v20;
      v4 = v19;
      v5 = i;
    }
    v2 = (_WORD *)((char *)v2 + *(_DWORD *)(*((_DWORD *)this + 1) + 96));
    v3 = *(_DWORD *)this;
    v4 += *(_DWORD *)(*(_DWORD *)this + 96);
    v20 = v2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422E8D
// Name: protected: long D3DXTex::CBlt::BltBox2D_A4L4(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltBox2D_A4L4(D3DXTex::CBlt *this)
{
  _BYTE *v2; // ecx
  _DWORD *v3; // eax
  _BYTE *v4; // ebx
  _BYTE *v5; // edi
  _BYTE *v6; // edx
  char v7; // al
  char v8; // di
  char v9; // dl
  _BYTE *v10; // eax
  D3DXTex::CBlt *v12; // [esp+8h] [ebp-28h]
  _BYTE *i; // [esp+Ch] [ebp-24h]
  _BYTE *v14; // [esp+10h] [ebp-20h]
  _BYTE *v15; // [esp+18h] [ebp-18h]
  _BYTE *v16; // [esp+1Ch] [ebp-14h]
  _BYTE *v17; // [esp+20h] [ebp-10h]
  _BYTE *v18; // [esp+24h] [ebp-Ch]
  _BYTE *v19; // [esp+28h] [ebp-8h]
  char v20; // [esp+2Ch] [ebp-4h]

  v2 = *(_BYTE **)(*((_DWORD *)this + 1) + 32);
  v12 = this;
  v3 = *(_DWORD **)this;
  v4 = (_BYTE *)v3[8];
  v5 = &v4[v3[24] * v3[27]];
  v16 = v2;
  v15 = v4;
  for ( i = v5; v4 < v5; v15 = v4 )
  {
    v6 = &v4[v3[24]];
    v19 = v2;
    v18 = v4;
    v17 = v6;
    v14 = &v4[v3[26]];
    if ( v4 < v14 )
    {
      do
      {
        v7 = v6[1];
        v8 = v4[1];
        v20 = *v6;
        v9 = (((v20 & 0xF0) + (*v4 & 0xF0) + (v7 & 0xF0) + (v8 & 0xF0u) + 32) >> 2)
           ^ ((((v20 & 0xF0) + (*v4 & 0xF0) + (v7 & 0xF0) + (v8 & 0xF0u) + 32) >> 2)
            ^ (((v20 & 0xF) + (*v4 & 0xF) + (v7 & 0xF) + (v8 & 0xFu) + 2) >> 2))
           & 0xF;
        v10 = v19++;
        *v10 = v9;
        v4 = v18 + 2;
        v6 = v17 + 2;
        v18 = v4;
        v17 += 2;
      }
      while ( v4 < v14 );
      v2 = v16;
      v4 = v15;
      v5 = i;
    }
    v2 += *(_DWORD *)(*((_DWORD *)v12 + 1) + 96);
    v3 = *(_DWORD **)v12;
    v4 += 2 * *(_DWORD *)(*(_DWORD *)v12 + 96);
    v16 = v2;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422FAB
// Name: protected: long D3DXTex::CBlt::BltSame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltSame(D3DXTex::CBlt *this)
{
  D3DXTex::CBlt *v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  const void *v5; // esi
  const void *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  unsigned int v9; // edi
  char *v10; // eax
  char *v11; // edx
  unsigned int v12; // ebx
  char *v13; // edi
  char *v14; // esi
  char v15; // cl
  D3DXTex::CBlt *v16; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  unsigned int v18; // [esp+10h] [ebp-4h]

  v1 = this;
  v2 = *((_DWORD **)this + 1);
  v3 = *(_DWORD **)this;
  v16 = v1;
  if ( v2[1] != v3[1] || v3[6] != 0 )
    return -2147467259;
  if ( v2[26] != v3[26] || v2[27] != v3[27] || v2[28] != v3[28] || v2[4] != v3[4] )
    return -2147467259;
  if ( v2[3] == 0 )
    return D3DXTex::CBlt::BltSame_DXTn(this: v1);
  if ( v2[7] != 0 )
  {
    v5 = (const void *)v2[14];
    v6 = (const void *)v3[14];
    if ( v5 != v6 && memcmp(v5, v6, 0x400u) != 0 )
      return -2147467259;
  }
  v2[4] = 0;
  *(_DWORD *)(*(_DWORD *)v1 + 16) = 0;
  v7 = *((_DWORD **)v1 + 1);
  v18 = 0;
  if ( v7[28] != 0 )
  {
    v8 = *(_DWORD *)v1;
    v9 = v7[27];
    do
    {
      v10 = (char *)(*(_DWORD *)(*((_DWORD *)v1 + 1) + 32) + v18 * *(_DWORD *)(*((_DWORD *)v1 + 1) + 100));
      v11 = (char *)(*(_DWORD *)(v8 + 32) + v18 * *(_DWORD *)(v8 + 100));
      for ( i = 0; i < v9; v9 = v7[27] )
      {
        v12 = v7[29];
        qmemcpy(v10, v11, 4 * (v12 >> 2));
        v14 = &v11[4 * (v12 >> 2)];
        v13 = &v10[4 * (v12 >> 2)];
        v15 = v12;
        v1 = v16;
        qmemcpy(v13, v14, v15 & 3);
        v7 = *((_DWORD **)v16 + 1);
        v8 = *(_DWORD *)v16;
        v10 += v7[24];
        v11 += *(_DWORD *)(*(_DWORD *)v16 + 96);
        ++i;
      }
      ++v18;
      v7 = *((_DWORD **)v1 + 1);
    }
    while ( v18 < v7[28] );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004230B5
// Name: protected: long D3DXTex::CBlt::BltCopy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltCopy(D3DXTex::CBlt *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  int v4; // edi
  void *v5; // eax
  void *v6; // ebx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned int i; // edi
  void *pMem; // [esp+Ch] [ebp-4h]

  v2 = *((_DWORD **)this + 1);
  v3 = *(_DWORD **)this;
  v4 = v2[26];
  if ( v4 != v3[26] || v2[27] != v3[27] || v2[28] != v3[28] )
    return -2147467259;
  v5 = operator new(nSize: 16 * v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    `vector constructor iterator'(__t: v5, __s: 0x10u, __n: v4, __f: D3DXShader::CArgument::CArgument);
    pMem = v6;
  }
  else
  {
    pMem = nullptr;
  }
  if ( pMem == nullptr )
    return -2147467259;
  v7 = *((_DWORD *)this + 1);
  if ( *(_DWORD *)(v7 + 16) != 0 && *(_DWORD *)(*(_DWORD *)this + 16) != 0 )
  {
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(*(_DWORD *)this + 16) = 0;
  }
  v8 = *((_DWORD *)this + 1);
  v9 = 0;
  if ( *(_DWORD *)(v8 + 112) != 0 )
  {
    v10 = *(_DWORD *)(v8 + 108);
    do
    {
      for ( i = 0; i < v10; ++i )
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**(_DWORD **)this + 4))(
          a1: *(_DWORD *)this,
          a2: i,
          a3: v9,
          a4: pMem);
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**((_DWORD **)this + 1) + 8))(
          a1: *((_DWORD *)this + 1),
          a2: i,
          a3: v9,
          a4: pMem);
        v10 = *(_DWORD *)(*((_DWORD *)this + 1) + 108);
      }
      ++v9;
    }
    while ( v9 < *(_DWORD *)(*((_DWORD *)this + 1) + 112) );
  }
  free(pMem);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423188
// Name: protected: long D3DXTex::CBlt::BltNone(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltNone(D3DXTex::CBlt *this)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  void *v7; // eax
  void *v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  unsigned int j; // edi
  unsigned int k; // edi
  int v13; // eax
  unsigned int v14; // eax
  unsigned int m; // edi
  unsigned int v16; // [esp+4h] [ebp-14h]
  unsigned int v17; // [esp+8h] [ebp-10h]
  unsigned int __n; // [esp+Ch] [ebp-Ch]
  int __na; // [esp+Ch] [ebp-Ch]
  void *__nb; // [esp+Ch] [ebp-Ch]
  void *v21; // [esp+10h] [ebp-8h]
  void *v22; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-8h]
  void *pMem; // [esp+14h] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 1 )
    return -2147467259;
  v3 = *((_DWORD **)this + 1);
  v4 = *(_DWORD **)this;
  __n = v3[26];
  if ( __n <= v4[26] )
    __n = v4[26];
  v16 = v3[27];
  if ( v16 >= v4[27] )
    v16 = v4[27];
  v5 = v4[28];
  v17 = v3[28];
  if ( v17 >= v5 )
    v17 = v5;
  v6 = 16 * __n;
  v7 = operator new(nSize: 16 * __n);
  v21 = v7;
  if ( v7 != nullptr )
  {
    `vector constructor iterator'(__t: v7, __s: 0x10u, __n, __f: D3DXShader::CArgument::CArgument);
    pMem = v21;
  }
  else
  {
    pMem = nullptr;
  }
  if ( pMem == nullptr )
    return -2147467259;
  __na = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v8 = operator new(nSize: 16 * __na);
  v22 = v8;
  if ( v8 != nullptr )
  {
    `vector constructor iterator'(__t: v8, __s: 0x10u, __n: __na, __f: D3DXShader::CArgument::CArgument);
    __nb = v22;
  }
  else
  {
    __nb = nullptr;
  }
  if ( __nb != nullptr )
  {
    memset(pMem, 0, v6);
    memset(__nb, 0, 16 * *(_DWORD *)(*((_DWORD *)this + 1) + 104));
    v9 = *((_DWORD *)this + 1);
    if ( *(_DWORD *)(v9 + 16) != 0 && *(_DWORD *)(*(_DWORD *)this + 16) != 0 )
    {
      *(_DWORD *)(v9 + 16) = 0;
      *(_DWORD *)(*(_DWORD *)this + 16) = 0;
    }
    v10 = v17;
    for ( i = 0; i < v17; v10 = v17 )
    {
      for ( j = 0; j < v16; ++j )
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**(_DWORD **)this + 4))(
          a1: *(_DWORD *)this,
          a2: j,
          a3: i,
          a4: pMem);
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**((_DWORD **)this + 1) + 8))(
          a1: *((_DWORD *)this + 1),
          a2: j,
          a3: i,
          a4: pMem);
      }
      for ( k = v16; k < *(_DWORD *)(*((_DWORD *)this + 1) + 108); ++k )
        (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**((_DWORD **)this + 1) + 8))(
          a1: *((_DWORD *)this + 1),
          a2: k,
          a3: i,
          a4: __nb);
      ++i;
    }
    v13 = *((_DWORD *)this + 1);
    if ( v10 < *(_DWORD *)(v13 + 112) )
    {
      v14 = *(_DWORD *)(v13 + 108);
      do
      {
        for ( m = 0; m < v14; ++m )
        {
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, void *))(**((_DWORD **)this + 1) + 8))(
            a1: *((_DWORD *)this + 1),
            a2: m,
            a3: v10,
            a4: __nb);
          v14 = *(_DWORD *)(*((_DWORD *)this + 1) + 108);
        }
        ++v10;
      }
      while ( v10 < *(_DWORD *)(*((_DWORD *)this + 1) + 112) );
    }
    free(pMem);
    free(pMem: __nb);
    return 0;
  }
  else
  {
    free(pMem);
    return -2147467259;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042335B
// Name: protected: long D3DXTex::CBlt::BltPoint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltPoint(D3DXTex::CBlt *this)
{
  int v3; // edi
  char *v4; // eax
  int v5; // edi
  _DWORD *v6; // eax
  int v7; // eax
  _DWORD *v8; // esi
  _DWORD *i; // eax
  unsigned int v10; // esi
  _DWORD *v11; // eax
  unsigned int v12; // esi
  char *v13; // esi
  int v14; // [esp+4h] [ebp-30h]
  int v15; // [esp+8h] [ebp-2Ch]
  int v16; // [esp+Ch] [ebp-28h]
  char *v17; // [esp+10h] [ebp-24h]
  _DWORD *v18; // [esp+10h] [ebp-24h]
  int v19; // [esp+10h] [ebp-24h]
  int v20; // [esp+14h] [ebp-20h]
  unsigned int v21; // [esp+18h] [ebp-1Ch]
  unsigned int v22; // [esp+1Ch] [ebp-18h]
  unsigned int v23; // [esp+20h] [ebp-14h]
  unsigned int v24; // [esp+24h] [ebp-10h]
  unsigned int v25; // [esp+28h] [ebp-Ch]
  _DWORD *v26; // [esp+2Ch] [ebp-8h]
  char *pMem; // [esp+30h] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 2 )
    return -2147467259;
  v3 = *(_DWORD *)(*(_DWORD *)this + 104);
  v4 = (char *)operator new(nSize: 16 * v3);
  v17 = v4;
  if ( v4 != nullptr )
  {
    `vector constructor iterator'(__t: v4, __s: 0x10u, __n: v3, __f: D3DXShader::CArgument::CArgument);
    pMem = v17;
  }
  else
  {
    pMem = nullptr;
  }
  if ( pMem == nullptr )
    return -2147024882;
  v5 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v6 = operator new(nSize: 16 * v5);
  v18 = v6;
  if ( v6 != nullptr )
  {
    `vector constructor iterator'(__t: v6, __s: 0x10u, __n: v5, __f: D3DXShader::CArgument::CArgument);
    v26 = v18;
  }
  else
  {
    v26 = nullptr;
  }
  if ( v26 != nullptr )
  {
    v7 = *((_DWORD *)this + 1);
    if ( *(_DWORD *)(v7 + 16) != 0 && *(_DWORD *)(*(_DWORD *)this + 16) != 0 )
    {
      *(_DWORD *)(v7 + 16) = 0;
      *(_DWORD *)(*(_DWORD *)this + 16) = 0;
    }
    v8 = *((_DWORD **)this + 1);
    v21 = 0;
    v24 = 0;
    v16 = (*(_DWORD *)(*(_DWORD *)this + 104) << 16) / v8[26];
    v15 = (*(_DWORD *)(*(_DWORD *)this + 108) << 16) / v8[27];
    v14 = (*(_DWORD *)(*(_DWORD *)this + 112) << 16) / v8[28];
    for ( i = v8; v24 < i[28]; i = *((_DWORD **)this + 1) )
    {
      v20 = -1;
      v10 = 0;
      v19 = 0;
      v25 = 0;
      if ( i[27] != 0 )
      {
        do
        {
          v23 = 0;
          v22 = 0;
          if ( ((v10 ^ v20) & 0xFFFF0000) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *))(**(_DWORD **)this + 4))(
              a1: *(_DWORD *)this,
              a2: HIWORD(v10),
              a3: HIWORD(v21),
              a4: pMem);
            v20 = v10;
          }
          if ( *(_DWORD *)(*((_DWORD *)this + 1) + 104) != 0 )
          {
            v11 = v26;
            do
            {
              v12 = v23;
              v23 += v16;
              v13 = &pMem[16 * HIWORD(v12)];
              ++v22;
              *v11 = *(_DWORD *)v13;
              v13 += 4;
              v11[1] = *(_DWORD *)v13;
              v13 += 4;
              v11[2] = *(_DWORD *)v13;
              v11[3] = *((_DWORD *)v13 + 1);
              v11 += 4;
            }
            while ( v22 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
          }
          (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, _DWORD *))(**((_DWORD **)this + 1) + 8))(
            a1: *((_DWORD *)this + 1),
            a2: v25,
            a3: v24,
            a4: v26);
          v10 = v15 + v19;
          ++v25;
          v19 += v15;
        }
        while ( v25 < *(_DWORD *)(*((_DWORD *)this + 1) + 108) );
      }
      v21 += v14;
      ++v24;
    }
    free(pMem);
    free(pMem: v26);
    return 0;
  }
  else
  {
    free(pMem);
    return -2147024882;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423531
// Name: protected: long D3DXTex::CBlt::BltBox2D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXTex::CBlt::BltBox2D@<eax>(D3DXTex::CBlt *this@<ecx>, int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // esi
  float *v15; // eax
  int v16; // esi
  char *v17; // eax
  char *v18; // esi
  char *v19; // eax
  int v20; // esi
  char *v21; // eax
  int v22; // esi
  unsigned int v23; // edx
  float *v24; // eax
  float *v25; // ecx
  double v26; // st6
  float *v27; // edi
  double v28; // st5
  double v29; // st4
  float *v30; // eax
  double v31; // st6
  double v32; // st5
  double v33; // st4
  float *v34; // eax
  float v37; // [esp+4h] [ebp-5Ch]
  float v38; // [esp+8h] [ebp-58h]
  float v39; // [esp+14h] [ebp-4Ch]
  float v40; // [esp+20h] [ebp-40h]
  float v41; // [esp+2Ch] [ebp-34h]
  float v42; // [esp+30h] [ebp-30h]
  float v43; // [esp+34h] [ebp-2Ch]
  float v44; // [esp+38h] [ebp-28h]
  float v45; // [esp+3Ch] [ebp-24h]
  float v46; // [esp+40h] [ebp-20h]
  float *pMem; // [esp+44h] [ebp-1Ch]
  char *pMema; // [esp+44h] [ebp-1Ch]
  char *pMemb; // [esp+44h] [ebp-1Ch]
  char *pMemc; // [esp+44h] [ebp-1Ch]
  char *v51; // [esp+48h] [ebp-18h]
  float *v52; // [esp+4Ch] [ebp-14h]
  float *v53; // [esp+50h] [ebp-10h]
  unsigned int v54; // [esp+54h] [ebp-Ch]
  char *v55; // [esp+58h] [ebp-8h]
  char *v56; // [esp+5Ch] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 5 )
    return -2147467259;
  v5 = *(_DWORD **)this;
  v6 = *(_DWORD *)(*(_DWORD *)this + 104);
  v7 = *((_DWORD **)this + 1);
  v8 = v7[26];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[27];
  if ( v9 != v5[27] >> 1 && (v9 != 1 || v5[27] != 1) )
    return -2147467259;
  if ( v7[28] != 1 || v5[28] != 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[26] &= ~1u;
    *(_DWORD *)(*(_DWORD *)this + 116) -= *(_DWORD *)(*(_DWORD *)this + 120);
  }
  if ( *(_DWORD *)(*(_DWORD *)this + 108) > 1u )
    *(_DWORD *)(*(_DWORD *)this + 108) &= ~1u;
  if ( (*((_BYTE *)this + 10) & 8) == 0 )
  {
    v10 = *(_DWORD **)this;
    v11 = *((_DWORD *)this + 1);
    v12 = *(_DWORD *)(*(_DWORD *)this + 4);
    if ( v12 == *(_DWORD *)(v11 + 4) && v10[26] >= 2u && v10[27] >= 2u && *(_DWORD *)(v11 + 16) == 0 && v10[4] == 0 )
    {
      if ( v12 <= 29 )
      {
        if ( v12 != 29 )
        {
          switch ( v12 )
          {
            case 21:
              goto LABEL_37;
            case 22:
              goto LABEL_36;
            case 23:
              v13 = D3DXTex::CBlt::BltBox2D_R5G6B5(this);
              goto LABEL_45;
            case 24:
              v13 = D3DXTex::CBlt::BltBox2D_X1R5G5B5(this);
              goto LABEL_45;
            case 25:
              v13 = D3DXTex::CBlt::BltBox2D_A1R5G5B5(this);
              goto LABEL_45;
            case 26:
              v13 = D3DXTex::CBlt::BltBox2D_A4R4G4B4(this);
              goto LABEL_45;
            case 27:
              v13 = D3DXTex::CBlt::BltBox2D_R3G3B2(this);
              goto LABEL_45;
            case 28:
              goto LABEL_44;
            default:
              goto LABEL_47;
          }
        }
        v13 = D3DXTex::CBlt::BltBox2D_A8R3G3B2(this);
LABEL_45:
        if ( v13 >= 0 )
          return 0;
        goto LABEL_47;
      }
      if ( v12 > 41 )
      {
        switch ( v12 )
        {
          case '2':
LABEL_44:
            v13 = D3DXTex::CBlt::BltBox2D_A8(this);
            goto LABEL_45;
          case '3':
            v13 = D3DXTex::CBlt::BltBox2D_A8L8(this);
            goto LABEL_45;
          case '4':
            v13 = D3DXTex::CBlt::BltBox2D_A4L4(this);
            goto LABEL_45;
          default:
            break;
        }
      }
      else if ( *(_DWORD *)(*(_DWORD *)this + 4) != 41 )
      {
        switch ( v12 )
        {
          case 30:
            v13 = D3DXTex::CBlt::BltBox2D_X4R4G4B4(this);
            goto LABEL_45;
          case 32:
LABEL_37:
            v13 = D3DXTex::CBlt::BltBox2D_A8R8G8B8(this);
            goto LABEL_45;
          case 33:
LABEL_36:
            v13 = D3DXTex::CBlt::BltBox2D_X8R8G8B8(this);
            goto LABEL_45;
          default:
            break;
        }
      }
    }
  }
LABEL_47:
  v14 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v15 = (float *)operator new(nSize: 16 * v14);
  pMem = v15;
  if ( v15 != nullptr )
  {
    `vector constructor iterator'(__t: v15, __s: 0x10u, __n: v14, __f: D3DXShader::CArgument::CArgument);
    v53 = pMem;
  }
  else
  {
    v53 = nullptr;
  }
  if ( v53 == nullptr )
    return -2147024882;
  v16 = *(_DWORD *)(*(_DWORD *)this + 104);
  if ( *(_DWORD *)(*(_DWORD *)this + 108) == 1 )
  {
    v17 = (char *)operator new(nSize: 16 * v16);
    pMema = v17;
    if ( v17 != nullptr )
    {
      `vector constructor iterator'(__t: v17, __s: 0x10u, __n: v16, __f: D3DXShader::CArgument::CArgument);
      v18 = pMema;
      v56 = pMema;
    }
    else
    {
      v56 = nullptr;
      v18 = nullptr;
    }
    v19 = v18;
    v55 = v18;
  }
  else
  {
    v20 = 2 * v16;
    v21 = (char *)operator new(nSize: 16 * v20);
    pMemb = v21;
    if ( v21 != nullptr )
    {
      `vector constructor iterator'(__t: v21, __s: 0x10u, __n: v20, __f: D3DXShader::CArgument::CArgument);
      v56 = pMemb;
    }
    else
    {
      v56 = nullptr;
    }
    v18 = v56;
    v19 = &v56[16 * *(_DWORD *)(*(_DWORD *)this + 104)];
    v55 = v19;
  }
  if ( v18 != nullptr )
  {
    if ( *(_DWORD *)(*(_DWORD *)this + 104) == 1 )
    {
      v51 = v18;
    }
    else
    {
      v51 = v18 + 16;
      v19 += 16;
    }
    v54 = 0;
    for ( pMemc = v19; v54 < *(_DWORD *)(*((_DWORD *)this + 1) + 108); ++v54 )
    {
      (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *, int, float *))(**(_DWORD **)this + 4))(
        a1: *(_DWORD *)this,
        a2: 2 * v54,
        a3: 0,
        a4: v18,
        a5: a2,
        a6: a3);
      if ( v55 != v18 )
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, char *))(**(_DWORD **)this + 4))(
          a1: *(_DWORD *)this,
          a2: 2 * v54 + 1,
          a3: 0,
          a4: v55);
      v23 = 0;
      if ( *(_DWORD *)(*((_DWORD *)this + 1) + 104) != 0 )
      {
        v52 = v53;
        do
        {
          v24 = (float *)&v51[32 * v23];
          v25 = (float *)&v56[32 * v23];
          v26 = *v24 + *v25;
          v27 = v52;
          v28 = v24[1];
          v52 += 4;
          v41 = v24[2] + v25[2];
          v29 = v24[3];
          v30 = (float *)&v55[32 * v23];
          v42 = v29 + v25[3];
          v39 = v26 + *v30;
          v31 = v28 + v25[1] + v30[1];
          v32 = v41 + v30[2];
          v33 = v42 + v30[3];
          v34 = (float *)&pMemc[32 * v23];
          v40 = v33;
          ++v23;
          v37 = v39 + *v34;
          v38 = v31 + v34[1];
          v43 = v37 * 0.25;
          v44 = v38 * 0.25;
          v45 = (v32 + v34[2]) * 0.25;
          v46 = (v40 + v34[3]) * 0.25;
          *v27++ = v43;
          *v27++ = v44;
          *v27 = v45;
          v27[1] = v46;
        }
        while ( v23 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
        v18 = v56;
      }
      a3 = v53;
      a2 = 0;
      (*(void (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)this + 1) + 8))(a1: *((_DWORD *)this + 1), a2: v54);
    }
    free(pMem: v18);
    v22 = 0;
  }
  else
  {
    v22 = -2147024882;
  }
  free(pMem: v53);
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x004238F9
// Name: protected: long D3DXTex::CBlt::BltBox3D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall D3DXTex::CBlt::BltBox3D@<eax>(D3DXTex::CBlt *this@<ecx>, unsigned int a2@<edi>, float *a3@<esi>)
{
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  _DWORD *v7; // esi
  int v8; // edi
  int v9; // edx
  int v10; // esi
  float *v11; // eax
  int v12; // esi
  int v13; // esi
  char *v14; // eax
  char *v15; // eax
  _DWORD *v16; // ecx
  char *v17; // esi
  char *v18; // edx
  int v19; // esi
  char *v20; // eax
  char *v21; // edi
  int v22; // esi
  int v23; // eax
  int v24; // edi
  float *v25; // ecx
  float *v26; // edx
  double v27; // st6
  double v28; // st5
  double v29; // st4
  float *v30; // ecx
  double v31; // st6
  double v32; // st5
  double v33; // st4
  float *v34; // ecx
  double v35; // st6
  double v36; // st5
  float *v37; // ecx
  double v38; // st5
  float *v39; // ecx
  double v40; // st6
  double v41; // st5
  double v42; // st4
  float *v43; // ecx
  float *v44; // eax
  float *v45; // edi
  float v48; // [esp+4h] [ebp-B4h]
  float v49; // [esp+10h] [ebp-A8h]
  float v50; // [esp+14h] [ebp-A4h]
  float v51; // [esp+20h] [ebp-98h]
  float v52; // [esp+2Ch] [ebp-8Ch]
  float v53; // [esp+30h] [ebp-88h]
  float v54; // [esp+3Ch] [ebp-7Ch]
  float v55; // [esp+40h] [ebp-78h]
  float v56; // [esp+44h] [ebp-74h]
  float v57; // [esp+48h] [ebp-70h]
  float v58; // [esp+54h] [ebp-64h]
  float v59; // [esp+58h] [ebp-60h]
  float v60; // [esp+5Ch] [ebp-5Ch]
  float v61; // [esp+60h] [ebp-58h]
  float v62; // [esp+68h] [ebp-50h]
  float v63; // [esp+6Ch] [ebp-4Ch]
  float v64; // [esp+70h] [ebp-48h]
  float v65; // [esp+74h] [ebp-44h]
  float v66; // [esp+78h] [ebp-40h]
  float v67; // [esp+7Ch] [ebp-3Ch]
  char *v68; // [esp+84h] [ebp-34h]
  char *v69; // [esp+88h] [ebp-30h]
  char *v70; // [esp+8Ch] [ebp-2Ch]
  float *v71; // [esp+90h] [ebp-28h]
  char *v72; // [esp+94h] [ebp-24h]
  char *v73; // [esp+98h] [ebp-20h]
  unsigned int v74; // [esp+9Ch] [ebp-1Ch]
  char *v75; // [esp+A0h] [ebp-18h]
  unsigned int v76; // [esp+A4h] [ebp-14h]
  float *v77; // [esp+A8h] [ebp-10h]
  float *v78; // [esp+ACh] [ebp-Ch]
  char *v79; // [esp+ACh] [ebp-Ch]
  char *v80; // [esp+ACh] [ebp-Ch]
  char *v81; // [esp+ACh] [ebp-Ch]
  unsigned int v82; // [esp+B0h] [ebp-8h]
  char *pMem; // [esp+B4h] [ebp-4h]

  if ( *((_BYTE *)this + 8) != 5 )
    return -2147467259;
  v5 = *(_DWORD **)this;
  v6 = *(_DWORD *)(*(_DWORD *)this + 104);
  v7 = *((_DWORD **)this + 1);
  v8 = v7[26];
  if ( v8 != v6 >> 1 && (v8 != 1 || v6 != 1) )
    return -2147467259;
  v9 = v7[27];
  if ( v9 != v5[27] >> 1 && (v9 != 1 || v5[27] != 1) )
    return -2147467259;
  if ( v7[28] != v5[28] >> 1 )
    return -2147467259;
  if ( v6 > 1 && (v6 & 1) != 0 )
  {
    v5[26] &= ~1u;
    *(_DWORD *)(*(_DWORD *)this + 116) -= *(_DWORD *)(*(_DWORD *)this + 120);
  }
  if ( *(_DWORD *)(*(_DWORD *)this + 108) > 1u )
    *(_DWORD *)(*(_DWORD *)this + 108) &= ~1u;
  if ( *(_DWORD *)(*(_DWORD *)this + 112) > 1u )
    *(_DWORD *)(*(_DWORD *)this + 112) &= ~1u;
  v10 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v11 = (float *)operator new(nSize: 16 * v10);
  v78 = v11;
  if ( v11 != nullptr )
  {
    `vector constructor iterator'(__t: v11, __s: 0x10u, __n: v10, __f: D3DXShader::CArgument::CArgument);
    v77 = v78;
  }
  else
  {
    v77 = nullptr;
  }
  if ( v77 == nullptr )
    return -2147024882;
  v12 = *(_DWORD *)(*(_DWORD *)this + 104);
  if ( *(_DWORD *)(*(_DWORD *)this + 108) == 1 )
  {
    v13 = 2 * v12;
    v14 = (char *)operator new(nSize: 16 * v13);
    v79 = v14;
    if ( v14 != nullptr )
    {
      `vector constructor iterator'(__t: v14, __s: 0x10u, __n: v13, __f: D3DXShader::CArgument::CArgument);
      pMem = v79;
    }
    else
    {
      pMem = nullptr;
    }
    v15 = pMem;
    v16 = (_DWORD *)(*(_DWORD *)this + 104);
    v17 = &pMem[16 * *v16];
    v18 = v17;
    v72 = v17;
    v75 = pMem;
    v73 = v17;
  }
  else
  {
    v19 = 4 * v12;
    v20 = (char *)operator new(nSize: 16 * v19);
    v80 = v20;
    if ( v20 != nullptr )
    {
      `vector constructor iterator'(__t: v20, __s: 0x10u, __n: v19, __f: D3DXShader::CArgument::CArgument);
      pMem = v80;
    }
    else
    {
      pMem = nullptr;
    }
    v16 = (_DWORD *)(*(_DWORD *)this + 104);
    v72 = &pMem[16 * *v16];
    v17 = v72;
    v75 = &pMem[32 * *v16];
    v73 = &pMem[48 * *v16];
    v15 = v75;
    v18 = v73;
  }
  v21 = pMem;
  if ( pMem != nullptr )
  {
    if ( *v16 == 1 )
    {
      v69 = pMem;
      v70 = v17;
    }
    else
    {
      v69 = pMem + 16;
      v15 += 16;
      v70 = v17 + 16;
      v18 += 16;
    }
    v76 = 0;
    v68 = v15;
    v23 = *((_DWORD *)this + 1);
    v81 = v18;
    if ( *(_DWORD *)(v23 + 112) != 0 )
    {
      do
      {
        v82 = 0;
        if ( *(_DWORD *)(v23 + 108) != 0 )
        {
          do
          {
            v24 = 2 * v76;
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, char *, unsigned int, float *))(**(_DWORD **)this + 4))(
              a1: *(_DWORD *)this,
              a2: 2 * v82,
              a3: 2 * v76,
              a4: pMem,
              a5: a2,
              a6: a3);
            if ( v17 != pMem )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: 2 * v82,
                a3: v24 + 1,
                a4: v17);
            if ( v75 != pMem )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: 2 * v82 + 1,
                a3: v24,
                a4: v75);
            if ( v73 != v17 && v73 != v75 )
              (*(void (__thiscall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: 2 * v82 + 1,
                a3: v24 + 1,
                a4: v73);
            v74 = 0;
            if ( *(_DWORD *)(*((_DWORD *)this + 1) + 104) != 0 )
            {
              v71 = v77;
              do
              {
                v25 = (float *)&v69[32 * v74];
                v26 = (float *)&pMem[32 * v74];
                v27 = *v25 + *v26;
                v28 = v25[1] + v26[1];
                v54 = v25[2] + v26[2];
                v29 = v25[3];
                v30 = (float *)&v17[32 * v74];
                v55 = v29 + v26[3];
                v50 = v27 + *v30;
                v31 = v28 + v30[1];
                v32 = v54 + v30[2];
                v33 = v55 + v30[3];
                v34 = (float *)&v70[32 * v74];
                v51 = v33;
                v56 = v50 + *v34;
                v57 = v31 + v34[1];
                v35 = v32 + v34[2];
                v36 = v51 + v34[3];
                v37 = (float *)&v75[32 * v74];
                v65 = v56 + *v37;
                v66 = v57 + v37[1];
                v67 = v35 + v37[2];
                v38 = v36 + v37[3];
                v39 = (float *)&v68[32 * v74];
                v40 = v38;
                v41 = v65 + *v39;
                v62 = v66 + v39[1];
                v63 = v67 + v39[2];
                v42 = v40 + v39[3];
                v43 = (float *)&v73[32 * v74];
                v64 = v42;
                v52 = v63 + v43[2];
                v44 = (float *)&v81[32 * v74];
                v53 = v64 + v43[3];
                v45 = v71;
                ++v74;
                v48 = v41 + *v43 + *v44;
                v71 += 4;
                v49 = v53 + v44[3];
                v58 = v48 * 0.125;
                v59 = (v62 + v43[1] + v44[1]) * 0.125;
                v60 = (v52 + v44[2]) * 0.125;
                v61 = v49 * 0.125;
                *v45++ = v58;
                *v45++ = v59;
                *v45 = v60;
                v45[1] = v61;
                v17 = v72;
              }
              while ( v74 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
            }
            a3 = v77;
            a2 = v76;
            (*(void (__thiscall **)(_DWORD, unsigned int))(**((_DWORD **)this + 1) + 8))(
              a1: *((_DWORD *)this + 1),
              a2: v82++);
          }
          while ( v82 < *(_DWORD *)(*((_DWORD *)this + 1) + 108) );
        }
        ++v76;
        v23 = *((_DWORD *)this + 1);
      }
      while ( v76 < *(_DWORD *)(v23 + 112) );
      v21 = pMem;
    }
    free(pMem: v21);
    v22 = 0;
  }
  else
  {
    v22 = -2147024882;
  }
  free(pMem: v77);
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x00423D01
// Name: sub_423D01
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *__userpurge sub_423D01@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, int a3)
{
  float *result; // eax
  float *v4; // ecx
  int v5; // eax
  int v6; // edx
  double v7; // st7
  float *v8; // [esp+0h] [ebp-1Ch]
  float v9; // [esp+10h] [ebp-Ch]
  float v10; // [esp+14h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp-4h]

  result = (float *)operator new(nSize: 16 * a1);
  v4 = result;
  if ( result != nullptr )
  {
    v8 = result;
    for ( i = 0; i < a1; *(v4 - 1) = 1.0 - v7 )
    {
      v9 = (double)a2 / (double)a1;
      v10 = ((double)i + 0.5) * v9 + 0.5;
      v5 = (int)v10;
      v6 = v5 - 1;
      v7 = (double)v5 + 1.0 - v10;
      if ( v5 - 1 < 0 )
        v6 = a3 != 0 ? a2 - 1 : 0;
      if ( v5 >= a2 )
        v5 = a3 == 0 ? a2 - 1 : 0;
      v4[1] = v7;
      *(_DWORD *)v4 = v6;
      *((_DWORD *)v4 + 2) = v5;
      v4 += 4;
      ++i;
    }
    return v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423DED
// Name: protected: long D3DXTex::CBlt::BltLinear2D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltLinear2D(D3DXTex::CBlt *this)
{
  int v2; // eax
  int v4; // esi
  float *v5; // eax
  int v6; // edi
  float *v7; // eax
  int v8; // edi
  char *v9; // eax
  char *v10; // edi
  int *v11; // esi
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  float *v15; // eax
  double v16; // st7
  int v17; // ecx
  double v18; // st7
  double v19; // st6
  int v20; // esi
  float *v21; // edx
  double v22; // st5
  float *v23; // ecx
  float *v24; // esi
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  float *v29; // edi
  double v30; // st5
  int v31; // esi
  float v32; // [esp+4h] [ebp-C0h]
  float v33; // [esp+8h] [ebp-BCh]
  float v34; // [esp+Ch] [ebp-B8h]
  float v35; // [esp+10h] [ebp-B4h]
  float v36; // [esp+14h] [ebp-B0h]
  float v37; // [esp+18h] [ebp-ACh]
  float v38; // [esp+1Ch] [ebp-A8h]
  float v39; // [esp+24h] [ebp-A0h]
  float v40; // [esp+28h] [ebp-9Ch]
  float v41; // [esp+2Ch] [ebp-98h]
  float v42; // [esp+38h] [ebp-8Ch]
  float v43; // [esp+3Ch] [ebp-88h]
  float v44; // [esp+40h] [ebp-84h]
  float v45; // [esp+44h] [ebp-80h]
  float v46; // [esp+48h] [ebp-7Ch]
  float v47; // [esp+4Ch] [ebp-78h]
  float v48; // [esp+54h] [ebp-70h]
  float v49; // [esp+58h] [ebp-6Ch]
  float v50; // [esp+5Ch] [ebp-68h]
  float v51; // [esp+64h] [ebp-60h]
  float v52; // [esp+68h] [ebp-5Ch]
  float v53; // [esp+6Ch] [ebp-58h]
  float v54; // [esp+78h] [ebp-4Ch]
  float v55; // [esp+7Ch] [ebp-48h]
  float v56; // [esp+80h] [ebp-44h]
  float v57; // [esp+84h] [ebp-40h]
  float v58; // [esp+88h] [ebp-3Ch]
  float v59; // [esp+8Ch] [ebp-38h]
  unsigned int v60; // [esp+94h] [ebp-30h]
  int v61; // [esp+98h] [ebp-2Ch]
  float *v62; // [esp+9Ch] [ebp-28h]
  float *pMem; // [esp+A0h] [ebp-24h]
  char *v64; // [esp+A4h] [ebp-20h]
  unsigned int v65; // [esp+A8h] [ebp-1Ch]
  int v66; // [esp+ACh] [ebp-18h]
  BOOL v67; // [esp+B0h] [ebp-14h]
  float *v68; // [esp+B0h] [ebp-14h]
  char *v69; // [esp+B4h] [ebp-10h]
  char *v70; // [esp+B8h] [ebp-Ch]
  float *v71; // [esp+BCh] [ebp-8h]
  float *v72; // [esp+C0h] [ebp-4h]
  char *v73; // [esp+C0h] [ebp-4h]
  int *v74; // [esp+C0h] [ebp-4h]

  v71 = nullptr;
  v69 = nullptr;
  v2 = *((_DWORD *)this + 2);
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v4 = *((_DWORD *)this + 1);
  if ( *(_DWORD *)(v4 + 112) != 1 || *(_DWORD *)(*(_DWORD *)this + 112) != 1 )
    return -2147467259;
  v67 = (v2 & 0x20000) == 0;
  pMem = sub_423D01(a1: *(_DWORD *)(v4 + 104), a2: *(_DWORD *)(*(_DWORD *)this + 104), a3: (v2 & 0x10000) == 0);
  v5 = sub_423D01(a1: *(_DWORD *)(*((_DWORD *)this + 1) + 108), a2: *(_DWORD *)(*(_DWORD *)this + 108), a3: v67);
  v68 = v5;
  if ( pMem == nullptr || v5 == nullptr )
    goto LABEL_29;
  v6 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v7 = (float *)operator new(nSize: 16 * v6);
  v72 = v7;
  if ( v7 != nullptr )
  {
    `vector constructor iterator'(__t: v7, __s: 0x10u, __n: v6, __f: D3DXShader::CArgument::CArgument);
    v71 = v72;
  }
  else
  {
    v71 = nullptr;
  }
  if ( v71 != nullptr
    && ((v8 = 2 * *(_DWORD *)(*(_DWORD *)this + 104),
         v9 = (char *)operator new(nSize: 32 * *(_DWORD *)(*(_DWORD *)this + 104)),
         v73 = v9,
         v9 == nullptr)
      ? (v69 = nullptr)
      : (`vector constructor iterator'(__t: v9, __s: 0x10u, __n: v8, __f: D3DXShader::CArgument::CArgument), v69 = v73),
        v69 != nullptr) )
  {
    v65 = 0;
    v61 = -1;
    v66 = -1;
    v10 = &v69[16 * *(_DWORD *)(*(_DWORD *)this + 104)];
    v64 = v69;
    v70 = v10;
    if ( *(_DWORD *)(*((_DWORD *)this + 1) + 108) != 0 )
    {
      v11 = (int *)(v68 + 2);
      v74 = (int *)(v68 + 2);
      do
      {
        v12 = *(v11 - 2);
        v60 = 0;
        if ( v12 != v61 )
        {
          v13 = v66;
          if ( v12 == v66 )
          {
            v14 = v64;
            v66 = -1;
            v64 = v10;
            v61 = v13;
            v70 = v14;
            v10 = v14;
          }
          else
          {
            v61 = *(v11 - 2);
            (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)this + 4))(
              a1: *(_DWORD *)this,
              a2: v12,
              a3: 0,
              a4: v64);
          }
        }
        if ( *v11 != v66 )
        {
          v66 = *v11;
          (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)this + 4))(
            a1: *(_DWORD *)this,
            a2: *v11,
            a3: 0,
            a4: v10);
        }
        if ( *(_DWORD *)(*((_DWORD *)this + 1) + 104) != 0 )
        {
          v15 = pMem + 2;
          v62 = v71;
          do
          {
            v16 = v15[1];
            v17 = 16 * *(_DWORD *)v15;
            v48 = v16 * *(float *)&v10[v17];
            v49 = v16 * *(float *)&v10[v17 + 4];
            v50 = v16 * *(float *)&v10[v17 + 8];
            v18 = v16 * *(float *)&v10[v17 + 12];
            v19 = *(v15 - 1);
            v20 = 16 * *((_DWORD *)v15 - 2);
            v21 = (float *)&v10[v20];
            v22 = v19 * *(float *)&v10[v20];
            v23 = (float *)&v64[v17];
            v24 = (float *)&v64[v20];
            v42 = v19 * v21[1];
            v43 = v19 * v21[2];
            v44 = v19 * v21[3];
            v57 = v22 + v48;
            v58 = v42 + v49;
            v59 = v43 + v50;
            v25 = *((float *)v74 + 1);
            v39 = v57 * v25;
            v40 = v58 * v25;
            v41 = v59 * v25;
            v26 = (v18 + v44) * v25;
            v27 = v15[1];
            v36 = v27 * *v23;
            v37 = v27 * v23[1];
            v38 = v27 * v23[2];
            v28 = *(v15 - 1);
            v54 = v28 * v24[1];
            v55 = v28 * v24[2];
            v56 = v28 * v24[3];
            v51 = v28 * *v24 + v36;
            v29 = v62;
            v62 += 4;
            v15 += 4;
            ++v60;
            v52 = v54 + v37;
            v53 = v55 + v38;
            v30 = *((float *)v74 - 1);
            v45 = v51 * v30;
            v46 = v52 * v30;
            v47 = v53 * v30;
            v32 = v45 + v39;
            v33 = v46 + v40;
            v34 = v47 + v41;
            v35 = (v27 * v23[3] + v56) * v30 + v26;
            *v29++ = v32;
            *v29++ = v33;
            *v29 = v34;
            v29[1] = v35;
            v10 = v70;
          }
          while ( v60 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
          v11 = v74;
        }
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, float *))(**((_DWORD **)this + 1) + 8))(
          a1: *((_DWORD *)this + 1),
          a2: v65,
          a3: 0,
          a4: v71);
        v11 += 4;
        ++v65;
        v74 = v11;
      }
      while ( v65 < *(_DWORD *)(*((_DWORD *)this + 1) + 108) );
    }
    v31 = 0;
  }
  else
  {
LABEL_29:
    v31 = -2147024882;
  }
  free(pMem);
  free(pMem: v68);
  free(pMem: v71);
  free(pMem: v69);
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x0042418F
// Name: protected: long D3DXTex::CBlt::BltLinear3D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltLinear3D(D3DXTex::CBlt *this)
{
  int v2; // eax
  float *v4; // eax
  int v5; // esi
  float *v6; // eax
  int v7; // esi
  char *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  char *v12; // esi
  float *v13; // edi
  int v14; // eax
  int v15; // ecx
  char *v16; // ecx
  char *v17; // eax
  float *v18; // eax
  double v19; // st7
  int v20; // esi
  double v21; // st7
  double v22; // st6
  int v23; // ecx
  float *v24; // esi
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st5
  double v30; // st7
  double v31; // st6
  int v32; // edx
  double v33; // st7
  double v34; // st6
  double v35; // st6
  double v36; // st5
  float *v37; // edx
  float *v38; // ecx
  double v39; // st5
  double v40; // st6
  double v41; // st5
  double v42; // st4
  double v43; // st4
  double v44; // st3
  double v45; // st5
  float *v46; // edi
  int v47; // esi
  float v48; // [esp+4h] [ebp-194h]
  float v49; // [esp+8h] [ebp-190h]
  float v50; // [esp+Ch] [ebp-18Ch]
  float v51; // [esp+10h] [ebp-188h]
  float v52; // [esp+14h] [ebp-184h]
  float v53; // [esp+18h] [ebp-180h]
  float v54; // [esp+1Ch] [ebp-17Ch]
  float v55; // [esp+24h] [ebp-174h]
  float v56; // [esp+28h] [ebp-170h]
  float v57; // [esp+2Ch] [ebp-16Ch]
  float v58; // [esp+34h] [ebp-164h]
  float v59; // [esp+38h] [ebp-160h]
  float v60; // [esp+3Ch] [ebp-15Ch]
  float v61; // [esp+44h] [ebp-154h]
  float v62; // [esp+48h] [ebp-150h]
  float v63; // [esp+4Ch] [ebp-14Ch]
  float v64; // [esp+54h] [ebp-144h]
  float v65; // [esp+58h] [ebp-140h]
  float v66; // [esp+5Ch] [ebp-13Ch]
  float v67; // [esp+64h] [ebp-134h]
  float v68; // [esp+68h] [ebp-130h]
  float v69; // [esp+6Ch] [ebp-12Ch]
  float v70; // [esp+74h] [ebp-124h]
  float v71; // [esp+78h] [ebp-120h]
  float v72; // [esp+7Ch] [ebp-11Ch]
  float v73; // [esp+84h] [ebp-114h]
  float v74; // [esp+88h] [ebp-110h]
  float v75; // [esp+8Ch] [ebp-10Ch]
  float v76; // [esp+94h] [ebp-104h]
  float v77; // [esp+98h] [ebp-100h]
  float v78; // [esp+9Ch] [ebp-FCh]
  float v79; // [esp+A4h] [ebp-F4h]
  float v80; // [esp+A8h] [ebp-F0h]
  float v81; // [esp+ACh] [ebp-ECh]
  float v82; // [esp+B4h] [ebp-E4h]
  float v83; // [esp+B8h] [ebp-E0h]
  float v84; // [esp+BCh] [ebp-DCh]
  float v85; // [esp+C4h] [ebp-D4h]
  float v86; // [esp+C8h] [ebp-D0h]
  float v87; // [esp+CCh] [ebp-CCh]
  float v88; // [esp+D4h] [ebp-C4h]
  float v89; // [esp+D8h] [ebp-C0h]
  float v90; // [esp+DCh] [ebp-BCh]
  float v91; // [esp+E8h] [ebp-B0h]
  float v92; // [esp+ECh] [ebp-ACh]
  float v93; // [esp+F0h] [ebp-A8h]
  float v94; // [esp+F8h] [ebp-A0h]
  float v95; // [esp+FCh] [ebp-9Ch]
  float v96; // [esp+100h] [ebp-98h]
  float v97; // [esp+104h] [ebp-94h]
  float v98; // [esp+108h] [ebp-90h]
  float v99; // [esp+10Ch] [ebp-8Ch]
  float v100; // [esp+114h] [ebp-84h]
  float v101; // [esp+118h] [ebp-80h]
  float v102; // [esp+11Ch] [ebp-7Ch]
  float v103; // [esp+124h] [ebp-74h]
  float v104; // [esp+128h] [ebp-70h]
  float v105; // [esp+12Ch] [ebp-6Ch]
  float v106; // [esp+138h] [ebp-60h]
  float v107; // [esp+13Ch] [ebp-5Ch]
  float v108; // [esp+140h] [ebp-58h]
  float v109; // [esp+148h] [ebp-50h]
  float v110; // [esp+14Ch] [ebp-4Ch]
  float v111; // [esp+150h] [ebp-48h]
  unsigned int v112; // [esp+154h] [ebp-44h]
  float *pMem; // [esp+158h] [ebp-40h]
  float *v114; // [esp+15Ch] [ebp-3Ch]
  float *v115; // [esp+160h] [ebp-38h]
  char *v116; // [esp+164h] [ebp-34h]
  BOOL v117; // [esp+168h] [ebp-30h]
  float *v118; // [esp+168h] [ebp-30h]
  char *v119; // [esp+16Ch] [ebp-2Ch]
  char *v120; // [esp+170h] [ebp-28h]
  char *v121; // [esp+174h] [ebp-24h]
  unsigned int v122; // [esp+178h] [ebp-20h]
  unsigned int v123; // [esp+17Ch] [ebp-1Ch]
  int v124; // [esp+180h] [ebp-18h]
  char *v125; // [esp+184h] [ebp-14h]
  int v126; // [esp+188h] [ebp-10h]
  float *v127; // [esp+18Ch] [ebp-Ch]
  float *v128; // [esp+190h] [ebp-8h]
  BOOL v129; // [esp+194h] [ebp-4h]
  float *v130; // [esp+194h] [ebp-4h]
  char *v131; // [esp+194h] [ebp-4h]
  float *v132; // [esp+194h] [ebp-4h]

  v127 = nullptr;
  v121 = nullptr;
  v2 = *((_DWORD *)this + 2);
  if ( (_BYTE)v2 != 3 )
    return -2147467259;
  v129 = (v2 & 0x40000) == 0;
  v117 = (v2 & 0x20000) == 0;
  pMem = sub_423D01(
           a1: *(_DWORD *)(*((_DWORD *)this + 1) + 104),
           a2: *(_DWORD *)(*(_DWORD *)this + 104),
           a3: (v2 & 0x10000) == 0);
  v114 = sub_423D01(a1: *(_DWORD *)(*((_DWORD *)this + 1) + 108), a2: *(_DWORD *)(*(_DWORD *)this + 108), a3: v117);
  v4 = sub_423D01(a1: *(_DWORD *)(*((_DWORD *)this + 1) + 112), a2: *(_DWORD *)(*(_DWORD *)this + 112), a3: v129);
  v118 = v4;
  if ( pMem == nullptr || v114 == nullptr || v4 == nullptr )
    goto LABEL_31;
  v5 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
  v6 = (float *)operator new(nSize: 16 * v5);
  v130 = v6;
  if ( v6 != nullptr )
  {
    `vector constructor iterator'(__t: v6, __s: 0x10u, __n: v5, __f: D3DXShader::CArgument::CArgument);
    v127 = v130;
  }
  else
  {
    v127 = nullptr;
  }
  if ( v127 != nullptr
    && ((v7 = 4 * *(_DWORD *)(*(_DWORD *)this + 104),
         v8 = (char *)operator new(nSize: *(_DWORD *)(*(_DWORD *)this + 104) << 6),
         v131 = v8,
         v8 == nullptr)
      ? (v121 = nullptr)
      : (`vector constructor iterator'(__t: v8, __s: 0x10u, __n: v7, __f: D3DXShader::CArgument::CArgument), v121 = v131),
        v121 != nullptr) )
  {
    v9 = *(_DWORD *)(*(_DWORD *)this + 104);
    v122 = 0;
    v125 = &v121[16 * v9];
    v10 = 3 * v9;
    v11 = *((_DWORD *)this + 1);
    v12 = &v121[16 * v10];
    v116 = v121;
    v120 = &v121[32 * *(_DWORD *)(*(_DWORD *)this + 104)];
    v119 = v12;
    if ( *(_DWORD *)(v11 + 112) != 0 )
    {
      v128 = v118 + 2;
      do
      {
        v123 = 0;
        v124 = -1;
        v126 = -1;
        if ( *(_DWORD *)(v11 + 108) != 0 )
        {
          v13 = v114 + 2;
          v132 = v114 + 2;
          do
          {
            v14 = *((_DWORD *)v13 - 2);
            v112 = 0;
            if ( v14 != v124 )
            {
              v15 = v126;
              if ( v14 == v126 )
              {
                v126 = -1;
                v124 = v15;
                v16 = v125;
                v125 = v116;
                v17 = v120;
                v120 = v12;
                v116 = v16;
                v119 = v17;
                v12 = v17;
              }
              else
              {
                v124 = *((_DWORD *)v13 - 2);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)this + 4))(
                  a1: *(_DWORD *)this,
                  a2: v14,
                  a3: *((_DWORD *)v128 - 2),
                  a4: v116);
                (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)this + 4))(
                  a1: *(_DWORD *)this,
                  a2: v124,
                  a3: *(_DWORD *)v128,
                  a4: v120);
              }
            }
            if ( *(_DWORD *)v13 != v126 )
            {
              v126 = *(_DWORD *)v13;
              (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, char *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: *(_DWORD *)v13,
                a3: *((_DWORD *)v128 - 2),
                a4: v125);
              (*(void (__thiscall **)(_DWORD, int, _DWORD, char *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: v126,
                a3: *(_DWORD *)v128,
                a4: v12);
            }
            if ( *(_DWORD *)(*((_DWORD *)this + 1) + 104) != 0 )
            {
              v18 = pMem + 2;
              v115 = v127;
              do
              {
                v19 = v18[1];
                v20 = 16 * *(_DWORD *)v18;
                v76 = v19 * *(float *)&v119[v20];
                v77 = v19 * *(float *)&v119[v20 + 4];
                v78 = v19 * *(float *)&v119[v20 + 8];
                v21 = v19 * *(float *)&v119[v20 + 12];
                v22 = *(v18 - 1);
                v23 = 16 * *((_DWORD *)v18 - 2);
                v109 = v22 * *(float *)&v119[v23 + 4];
                v110 = v22 * *(float *)&v119[v23 + 8];
                v24 = (float *)&v120[v20];
                v111 = v22 * *(float *)&v119[v23 + 12];
                v100 = v22 * *(float *)&v119[v23] + v76;
                v101 = v109 + v77;
                v102 = v110 + v78;
                v25 = v13[1];
                v58 = v100 * v25;
                v59 = v101 * v25;
                v60 = v102 * v25;
                v26 = (v21 + v111) * v25;
                v27 = v18[1];
                v52 = v27 * *v24;
                v53 = v27 * v24[1];
                v54 = v27 * v24[2];
                v28 = *(v18 - 1);
                v94 = v28 * *(float *)&v120[v23 + 4];
                v95 = v28 * *(float *)&v120[v23 + 8];
                v96 = v28 * *(float *)&v120[v23 + 12];
                v70 = v28 * *(float *)&v120[v23] + v52;
                v71 = v94 + v53;
                v72 = v95 + v54;
                v29 = *(v13 - 1);
                v88 = v70 * v29;
                v89 = v71 * v29;
                v90 = v72 * v29;
                v82 = v88 + v58;
                v83 = v89 + v59;
                v84 = v90 + v60;
                v30 = v26 + (v27 * v24[3] + v96) * v29;
                v31 = v128[1];
                v32 = 16 * *(_DWORD *)v18;
                v55 = v82 * v31;
                v56 = v83 * v31;
                v57 = v84 * v31;
                v33 = v30 * v31;
                v34 = v18[1];
                v64 = v34 * *(float *)&v125[v32];
                v65 = v34 * *(float *)&v125[v32 + 4];
                v66 = v34 * *(float *)&v125[v32 + 8];
                v35 = v34 * *(float *)&v125[v32 + 12];
                v36 = *(v18 - 1);
                v106 = v36 * *(float *)&v125[v23 + 4];
                v107 = v36 * *(float *)&v125[v23 + 8];
                v108 = v36 * *(float *)&v125[v23 + 12];
                v103 = v36 * *(float *)&v125[v23] + v64;
                v37 = (float *)&v116[v32];
                v38 = (float *)&v116[v23];
                v104 = v106 + v65;
                v105 = v107 + v66;
                v39 = v13[1];
                v73 = v103 * v39;
                v74 = v104 * v39;
                v75 = v105 * v39;
                v40 = (v35 + v108) * v39;
                v41 = v18[1];
                v97 = v41 * *v37;
                v98 = v41 * v37[1];
                v99 = v41 * v37[2];
                v42 = *(v18 - 1);
                v91 = v42 * v38[1];
                v92 = v42 * v38[2];
                v93 = v42 * v38[3];
                v85 = v42 * *v38 + v97;
                v86 = v91 + v98;
                v87 = v92 + v99;
                v43 = *(v13 - 1);
                v79 = v85 * v43;
                v80 = v86 * v43;
                v81 = v87 * v43;
                v44 = (v41 * v37[3] + v93) * v43;
                v67 = v79 + v73;
                v68 = v80 + v74;
                v69 = v81 + v75;
                v45 = *(v128 - 1);
                v46 = v115;
                v115 += 4;
                v18 += 4;
                ++v112;
                v61 = v67 * v45;
                v62 = v68 * v45;
                v63 = v69 * v45;
                v48 = v61 + v55;
                v49 = v62 + v56;
                v50 = v63 + v57;
                v51 = (v40 + v44) * v45 + v33;
                *v46++ = v48;
                *v46++ = v49;
                *v46 = v50;
                v46[1] = v51;
                v13 = v132;
              }
              while ( v112 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
              v12 = v119;
            }
            (*(void (__thiscall **)(_DWORD, unsigned int, unsigned int, float *))(**((_DWORD **)this + 1) + 8))(
              a1: *((_DWORD *)this + 1),
              a2: v123,
              a3: v122,
              a4: v127);
            v13 += 4;
            ++v123;
            v132 = v13;
          }
          while ( v123 < *(_DWORD *)(*((_DWORD *)this + 1) + 108) );
        }
        v128 += 4;
        ++v122;
        v11 = *((_DWORD *)this + 1);
      }
      while ( v122 < *(_DWORD *)(v11 + 112) );
    }
    v47 = 0;
  }
  else
  {
LABEL_31:
    v47 = -2147024882;
  }
  free(pMem);
  free(pMem: v114);
  free(pMem: v118);
  free(pMem: v127);
  free(pMem: v121);
  return v47;
}

//------------------------------------------------------------------------------
// Address: 0x004248A0
// Name: protected: long D3DXTex::CBlt::BltTriangle3D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltTriangle3D(D3DXTex::CBlt *this)
{
  int v2; // edi
  BOOL v3; // edi
  unsigned int v4; // ebx
  int v5; // edi
  int *v6; // eax
  int v7; // edi
  float *v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // edx
  _DWORD *i; // ecx
  float *v12; // eax
  double v13; // st7
  void **v14; // ebx
  int v15; // edi
  void *v16; // eax
  void *v17; // eax
  float *v18; // edx
  float *v19; // eax
  float *k; // ebx
  int v21; // eax
  float *m; // ecx
  double v23; // st7
  float *v24; // edi
  float *v25; // ebx
  void **v26; // edi
  bool v27; // zf
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  unsigned int v31; // edx
  float *v32; // ecx
  double v33; // st6
  double v34; // st6
  double v35; // st6
  double v36; // st6
  unsigned int v37; // edx
  float *v38; // ecx
  double v39; // st6
  double v40; // st6
  double v41; // st6
  double v42; // st6
  unsigned int v43; // edx
  float *v44; // ecx
  double v45; // st6
  double v46; // st6
  double v47; // st6
  double v48; // st6
  int v49; // esi
  BOOL v51; // [esp-4h] [ebp-58h]
  unsigned int v52; // [esp+Ch] [ebp-48h]
  BOOL v53; // [esp+10h] [ebp-44h]
  D3DXTex::TF_Row *v54; // [esp+10h] [ebp-44h]
  float *v55; // [esp+10h] [ebp-44h]
  float *v56; // [esp+10h] [ebp-44h]
  unsigned int v57; // [esp+14h] [ebp-40h]
  unsigned int v58; // [esp+18h] [ebp-3Ch]
  float *v59; // [esp+1Ch] [ebp-38h]
  int v60; // [esp+20h] [ebp-34h]
  void *v61; // [esp+24h] [ebp-30h]
  float *v62; // [esp+24h] [ebp-30h]
  float *v63; // [esp+28h] [ebp-2Ch]
  int v64; // [esp+2Ch] [ebp-28h]
  float *v65; // [esp+30h] [ebp-24h]
  float *v66; // [esp+34h] [ebp-20h]
  float *v67; // [esp+38h] [ebp-1Ch]
  _DWORD *pMem; // [esp+3Ch] [ebp-18h]
  void **v69; // [esp+40h] [ebp-14h]
  float *v70; // [esp+44h] [ebp-10h]
  float *v71; // [esp+48h] [ebp-Ch]
  D3DXTex::TF_Row *v72; // [esp+4Ch] [ebp-8h]
  float *j; // [esp+50h] [ebp-4h]
  float *v74; // [esp+50h] [ebp-4h]
  unsigned int n; // [esp+50h] [ebp-4h]

  v2 = *((_DWORD *)this + 2);
  v53 = (v2 & 0x40000) == 0;
  v51 = (v2 & 0x10000) == 0;
  v67 = nullptr;
  pMem = nullptr;
  v72 = nullptr;
  v69 = nullptr;
  v71 = nullptr;
  v3 = (v2 & 0x20000) == 0;
  v59 = (float *)sub_421CF0(
                   a1: *(_DWORD *)(*(_DWORD *)this + 104),
                   a2: *(_DWORD *)(*((_DWORD *)this + 1) + 104),
                   a3: v51);
  if ( v59 != nullptr
    && (v67 = (float *)sub_421CF0(
                         a1: *(_DWORD *)(*(_DWORD *)this + 108),
                         a2: *(_DWORD *)(*((_DWORD *)this + 1) + 108),
                         a3: v3)) != nullptr
    && (pMem = sub_421CF0(a1: *(_DWORD *)(*(_DWORD *)this + 112), a2: *(_DWORD *)(*((_DWORD *)this + 1) + 112), a3: v53)) != nullptr )
  {
    v58 = (unsigned int)v59 + *(_DWORD *)v59;
    v57 = (unsigned int)v67 + *(_DWORD *)v67;
    v4 = (unsigned int)pMem + *pMem;
    v5 = *(_DWORD *)(*((_DWORD *)this + 1) + 112);
    v52 = v4;
    v6 = (int *)operator new(nSize: 12 * v5 + 4);
    if ( v6 != nullptr )
    {
      *v6 = v5;
      v54 = (D3DXTex::TF_Row *)(v6 + 1);
      `vector constructor iterator'(
        __t: v6 + 1,
        __s: 0xCu,
        __n: v5,
        __f: (void *(__thiscall *)(void *))D3DXTex::TF_Row::TF_Row);
      v72 = v54;
    }
    else
    {
      v72 = nullptr;
    }
    if ( v72 != nullptr
      && ((v7 = *(_DWORD *)(*(_DWORD *)this + 104), v8 = (float *)operator new(nSize: 16 * v7), v55 = v8, v8 == nullptr)
        ? (v71 = nullptr)
        : (`vector constructor iterator'(__t: v8, __s: 0x10u, __n: v7, __f: D3DXShader::CArgument::CArgument), v71 = v55),
          v71 != nullptr) )
    {
      v9 = pMem + 1;
      if ( (unsigned int)(pMem + 1) < v4 )
      {
        do
        {
          v10 = (_DWORD *)((char *)v9 + *v9);
          for ( i = v9 + 1; i < v10; i += 2 )
            ++*((_DWORD *)v72 + 3 * *i + 2);
          v9 = v10;
        }
        while ( (unsigned int)v10 < v4 );
      }
      v12 = (float *)(pMem + 1);
      v60 = 0;
      if ( (unsigned int)(pMem + 1) < v4 )
      {
        v13 = -1.0;
        do
        {
          v70 = (float *)((char *)v12 + *(_DWORD *)v12);
          v56 = v12 + 1;
          for ( j = v12 + 1; j < v70; j += 2 )
          {
            v14 = (void **)((char *)v72 + 12 * *(_DWORD *)j);
            if ( *v14 == nullptr )
            {
              if ( v69 != nullptr )
              {
                *v14 = *v69;
                *v69 = nullptr;
                v69 = (void **)v69[1];
              }
              else
              {
                v15 = *(_DWORD *)(*((_DWORD *)this + 1) + 104) * *(_DWORD *)(*((_DWORD *)this + 1) + 108);
                v16 = operator new(nSize: 16 * v15);
                v61 = v16;
                if ( v16 != nullptr )
                {
                  `vector constructor iterator'(__t: v16, __s: 0x10u, __n: v15, __f: D3DXShader::CArgument::CArgument);
                  v17 = v61;
                }
                else
                {
                  v17 = nullptr;
                }
                *v14 = v17;
                if ( v17 == nullptr )
                  goto LABEL_128;
                v13 = -1.0;
              }
              memset(*v14, 0, 16 * *(_DWORD *)(*((_DWORD *)this + 1) + 104) * *(_DWORD *)(*((_DWORD *)this + 1) + 108));
            }
          }
          v64 = 0;
          v62 = v67 + 1;
          if ( (unsigned int)(v67 + 1) < v57 )
          {
            do
            {
              v63 = (float *)((char *)v62 + *(_DWORD *)v62);
              (*(void (__thiscall **)(_DWORD, int, int, float *))(**(_DWORD **)this + 4))(
                a1: *(_DWORD *)this,
                a2: v64,
                a3: v60,
                a4: v71);
              v65 = v59 + 1;
              if ( (unsigned int)(v59 + 1) < v58 )
              {
                v18 = v71 + 2;
                do
                {
                  v66 = (float *)((char *)v65 + *(_DWORD *)v65);
                  v19 = v56;
                  v74 = v56;
                  while ( v19 < v70 )
                  {
                    for ( k = v62 + 1; k < v63; k += 2 )
                    {
                      v21 = *((_DWORD *)v72 + 3 * *(_DWORD *)v74)
                          + 16 * *(_DWORD *)k * *(_DWORD *)(*((_DWORD *)this + 1) + 104);
                      for ( m = v65 + 1; m < v66; m += 2 )
                      {
                        v23 = m[1] * v74[1] * k[1];
                        *(float *)(v21 + 16 * *(_DWORD *)m) = v23 * *(v18 - 2) + *(float *)(v21 + 16 * *(_DWORD *)m);
                        *(float *)(16 * *(_DWORD *)m + v21 + 4) = v23 * *(v18 - 1)
                                                                + *(float *)(16 * *(_DWORD *)m + v21 + 4);
                        *(float *)(16 * *(_DWORD *)m + v21 + 8) = v23 * *v18 + *(float *)(16 * *(_DWORD *)m + v21 + 8);
                        v24 = (float *)(16 * *(_DWORD *)m + v21 + 12);
                        *v24 = v23 * v18[1] + *v24;
                      }
                    }
                    v74 += 2;
                    v19 = v74;
                  }
                  v18 += 4;
                  v65 = v66;
                }
                while ( (unsigned int)v66 < v58 );
              }
              ++v64;
              v62 = v63;
            }
            while ( (unsigned int)v63 < v57 );
            v13 = -1.0;
          }
          v25 = v56;
          v12 = v70;
          while ( v25 < v12 )
          {
            v26 = (void **)((char *)v72 + 12 * *(_DWORD *)v25);
            v27 = v26[2] == (void *)1;
            v26[2] = (char *)v26[2] - 1;
            if ( v27 )
            {
              v28 = *((_DWORD *)this + 1);
              for ( n = 0; n < *(_DWORD *)(v28 + 108); v28 = *((_DWORD *)this + 1) )
              {
                v29 = *(_DWORD *)(v28 + 104);
                v30 = (int)*v26 + 16 * n * v29;
                switch ( *(_DWORD *)(*(_DWORD *)this + 8) )
                {
                  case 1:
                    v43 = 0;
                    if ( v29 != 0 )
                    {
                      v44 = (float *)(v30 + 8);
                      do
                      {
                        if ( *(v44 - 2) >= 0.0 )
                        {
                          if ( *(v44 - 2) >= 1.0 )
                            v45 = 1.0;
                          else
                            v45 = *(v44 - 2);
                        }
                        else
                        {
                          v45 = 0.0;
                        }
                        *(v44 - 2) = v45;
                        if ( *(v44 - 1) >= 0.0 )
                        {
                          if ( *(v44 - 1) >= 1.0 )
                            v46 = 1.0;
                          else
                            v46 = *(v44 - 1);
                        }
                        else
                        {
                          v46 = 0.0;
                        }
                        *(v44 - 1) = v46;
                        if ( *v44 >= 0.0 )
                        {
                          if ( *v44 >= 1.0 )
                            v47 = 1.0;
                          else
                            v47 = *v44;
                        }
                        else
                        {
                          v47 = 0.0;
                        }
                        *v44 = v47;
                        if ( v44[1] >= 0.0 )
                        {
                          if ( v44[1] >= 1.0 )
                            v48 = 1.0;
                          else
                            v48 = v44[1];
                        }
                        else
                        {
                          v48 = 0.0;
                        }
                        v44[1] = v48;
                        ++v43;
                        v44 += 4;
                      }
                      while ( v43 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
                    }
                    break;
                  case 2:
                    v37 = 0;
                    if ( v29 != 0 )
                    {
                      v38 = (float *)(v30 + 8);
                      do
                      {
                        if ( v13 <= *(v38 - 2) )
                        {
                          if ( *(v38 - 2) >= 1.0 )
                            v39 = 1.0;
                          else
                            v39 = *(v38 - 2);
                        }
                        else
                        {
                          v39 = v13;
                        }
                        *(v38 - 2) = v39;
                        if ( v13 <= *(v38 - 1) )
                        {
                          if ( *(v38 - 1) >= 1.0 )
                            v40 = 1.0;
                          else
                            v40 = *(v38 - 1);
                        }
                        else
                        {
                          v40 = v13;
                        }
                        *(v38 - 1) = v40;
                        if ( v13 <= *v38 )
                        {
                          if ( *v38 >= 1.0 )
                            v41 = 1.0;
                          else
                            v41 = *v38;
                        }
                        else
                        {
                          v41 = v13;
                        }
                        *v38 = v41;
                        if ( v38[1] >= 0.0 )
                        {
                          if ( v38[1] >= 1.0 )
                            v42 = 1.0;
                          else
                            v42 = v38[1];
                        }
                        else
                        {
                          v42 = 0.0;
                        }
                        v38[1] = v42;
                        ++v37;
                        v38 += 4;
                      }
                      while ( v37 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
                    }
                    break;
                  case 3:
                    v31 = 0;
                    if ( v29 != 0 )
                    {
                      v32 = (float *)(v30 + 8);
                      do
                      {
                        if ( v13 <= *(v32 - 2) )
                        {
                          if ( *(v32 - 2) >= 1.0 )
                            v33 = 1.0;
                          else
                            v33 = *(v32 - 2);
                        }
                        else
                        {
                          v33 = v13;
                        }
                        *(v32 - 2) = v33;
                        if ( v13 <= *(v32 - 1) )
                        {
                          if ( *(v32 - 1) >= 1.0 )
                            v34 = 1.0;
                          else
                            v34 = *(v32 - 1);
                        }
                        else
                        {
                          v34 = v13;
                        }
                        *(v32 - 1) = v34;
                        if ( v13 <= *v32 )
                        {
                          if ( *v32 >= 1.0 )
                            v35 = 1.0;
                          else
                            v35 = *v32;
                        }
                        else
                        {
                          v35 = v13;
                        }
                        *v32 = v35;
                        if ( v13 <= v32[1] )
                        {
                          if ( v32[1] >= 1.0 )
                            v36 = 1.0;
                          else
                            v36 = v32[1];
                        }
                        else
                        {
                          v36 = v13;
                        }
                        v32[1] = v36;
                        ++v31;
                        v32 += 4;
                      }
                      while ( v31 < *(_DWORD *)(*((_DWORD *)this + 1) + 104) );
                    }
                    break;
                  default:
                    break;
                }
                (*(void (__stdcall **)(unsigned int, _DWORD, unsigned int))(**((_DWORD **)this + 1) + 8))(
                  a1: n,
                  a2: *(_DWORD *)v25,
                  a3: (unsigned int)*v26 + 16 * n * *(_DWORD *)(*((_DWORD *)this + 1) + 104));
                v13 = -1.0;
                ++n;
              }
              v26[1] = v69;
              v12 = v70;
              v69 = v26;
            }
            v25 += 2;
          }
          ++v60;
        }
        while ( (unsigned int)v12 < v52 );
      }
      v49 = 0;
    }
    else
    {
LABEL_128:
      v49 = -2147024882;
    }
  }
  else
  {
    v49 = -2147467259;
  }
  if ( v72 != nullptr )
    D3DXTex::TF_Row::`vector deleting destructor'(this: v72, a2: 3);
  free(pMem);
  free(pMem: v67);
  free(pMem: v59);
  free(pMem: v71);
  free(pMem: nullptr);
  return v49;
}

//------------------------------------------------------------------------------
// Address: 0x00424F26
// Name: protected: long D3DXTex::CBlt::BltTriangle2D(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::BltTriangle2D(D3DXTex::CBlt *this)
{
  int v2; // edx
  BOOL v3; // edi
  unsigned int v4; // edi
  int v5; // esi
  int *v6; // eax
  int v7; // esi
  float *v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // edx
  _DWORD *i; // ecx
  char *v12; // eax
  char *v13; // ecx
  void **v14; // edi
  int v15; // esi
  void *v16; // eax
  void *v17; // eax
  float *v18; // eax
  float *v19; // edx
  float *v20; // edi
  int v21; // ecx
  float *k; // eax
  double v23; // st7
  float *v24; // esi
  char *v25; // edi
  void **v26; // esi
  bool v27; // zf
  int v28; // edx
  unsigned int ii; // edi
  float *v30; // ecx
  double v31; // st5
  float *v32; // ecx
  double v33; // st5
  float *v34; // ecx
  double v35; // st5
  float *v36; // ecx
  double v37; // st5
  int v38; // edx
  unsigned int n; // edi
  float *v40; // ecx
  double v41; // st5
  float *v42; // ecx
  double v43; // st5
  float *v44; // ecx
  double v45; // st5
  float *v46; // ecx
  double v47; // st5
  int v48; // edx
  unsigned int m; // edi
  float *v50; // ecx
  double v51; // st6
  float *v52; // ecx
  double v53; // st6
  float *v54; // ecx
  double v55; // st6
  float *v56; // ecx
  double v57; // st6
  int v58; // esi
  unsigned int v60; // [esp+Ch] [ebp-30h]
  D3DXTex::TF_Row *v61; // [esp+10h] [ebp-2Ch]
  char *v62; // [esp+10h] [ebp-2Ch]
  unsigned int v63; // [esp+14h] [ebp-28h]
  void *v64; // [esp+18h] [ebp-24h]
  float *v65; // [esp+18h] [ebp-24h]
  float *v66; // [esp+1Ch] [ebp-20h]
  float *v67; // [esp+20h] [ebp-1Ch]
  int v68; // [esp+20h] [ebp-1Ch]
  _DWORD *pMem; // [esp+24h] [ebp-18h]
  void **v70; // [esp+28h] [ebp-14h]
  char *v71; // [esp+2Ch] [ebp-10h]
  float *v72; // [esp+30h] [ebp-Ch]
  D3DXTex::TF_Row *v73; // [esp+34h] [ebp-8h]
  char *j; // [esp+38h] [ebp-4h]
  float *v75; // [esp+38h] [ebp-4h]
  char *v76; // [esp+38h] [ebp-4h]

  v2 = *((_DWORD *)this + 1);
  pMem = nullptr;
  v73 = nullptr;
  v70 = nullptr;
  v72 = nullptr;
  if ( *(_DWORD *)(v2 + 112) != 1 || *(_DWORD *)(*(_DWORD *)this + 112) != 1 )
    return -2147467259;
  v3 = (*((_DWORD *)this + 2) & 0x20000) == 0;
  v66 = (float *)sub_421CF0(
                   a1: *(_DWORD *)(*(_DWORD *)this + 104),
                   a2: *(_DWORD *)(v2 + 104),
                   a3: (*((_DWORD *)this + 2) & 0x10000) == 0);
  if ( v66 != nullptr
    && (pMem = sub_421CF0(a1: *(_DWORD *)(*(_DWORD *)this + 108), a2: *(_DWORD *)(*((_DWORD *)this + 1) + 108), a3: v3)) != nullptr )
  {
    v63 = (unsigned int)v66 + *(_DWORD *)v66;
    v4 = (unsigned int)pMem + *pMem;
    v5 = *(_DWORD *)(*((_DWORD *)this + 1) + 108);
    v60 = v4;
    v6 = (int *)operator new(nSize: 12 * v5 + 4);
    if ( v6 != nullptr )
    {
      *v6 = v5;
      v61 = (D3DXTex::TF_Row *)(v6 + 1);
      `vector constructor iterator'(
        __t: v6 + 1,
        __s: 0xCu,
        __n: v5,
        __f: (void *(__thiscall *)(void *))D3DXTex::TF_Row::TF_Row);
      v73 = v61;
    }
    else
    {
      v73 = nullptr;
    }
    if ( v73 != nullptr
      && ((v7 = *(_DWORD *)(*(_DWORD *)this + 104), v8 = (float *)operator new(nSize: 16 * v7), v67 = v8, v8 == nullptr)
        ? (v72 = nullptr)
        : (`vector constructor iterator'(__t: v8, __s: 0x10u, __n: v7, __f: D3DXShader::CArgument::CArgument), v72 = v67),
          v72 != nullptr) )
    {
      v9 = pMem + 1;
      if ( (unsigned int)(pMem + 1) < v4 )
      {
        do
        {
          v10 = (_DWORD *)((char *)v9 + *v9);
          for ( i = v9 + 1; i < v10; i += 2 )
            ++*((_DWORD *)v73 + 3 * *i + 2);
          v9 = v10;
        }
        while ( (unsigned int)v10 < v4 );
      }
      v12 = (char *)(pMem + 1);
      v68 = 0;
      if ( (unsigned int)(pMem + 1) < v4 )
      {
        do
        {
          v13 = &v12[*(_DWORD *)v12];
          v71 = v13;
          v62 = v12 + 4;
          for ( j = v12 + 4; j < v13; j += 8 )
          {
            v14 = (void **)((char *)v73 + 12 * *(_DWORD *)j);
            if ( *v14 == nullptr )
            {
              if ( v70 != nullptr )
              {
                *v14 = *v70;
                *v70 = nullptr;
                v70 = (void **)v70[1];
              }
              else
              {
                v15 = *(_DWORD *)(*((_DWORD *)this + 1) + 104);
                v16 = operator new(nSize: 16 * v15);
                v64 = v16;
                if ( v16 != nullptr )
                {
                  `vector constructor iterator'(__t: v16, __s: 0x10u, __n: v15, __f: D3DXShader::CArgument::CArgument);
                  v17 = v64;
                }
                else
                {
                  v17 = nullptr;
                }
                *v14 = v17;
                if ( v17 == nullptr )
                  goto LABEL_116;
              }
              memset(*v14, 0, 16 * *(_DWORD *)(*((_DWORD *)this + 1) + 104));
              v13 = v71;
            }
          }
          (*(void (__thiscall **)(_DWORD, int, _DWORD, float *))(**(_DWORD **)this + 4))(
            a1: *(_DWORD *)this,
            a2: v68,
            a3: 0,
            a4: v72);
          v18 = v66 + 1;
          if ( (unsigned int)(v66 + 1) < v63 )
          {
            v19 = v72 + 2;
            do
            {
              v20 = (float *)((char *)v18 + *(_DWORD *)v18);
              v75 = (float *)v62;
              if ( v62 < v71 )
              {
                v65 = v18 + 1;
                do
                {
                  v21 = *((_DWORD *)v73 + 3 * *(_DWORD *)v75);
                  for ( k = v65; k < v20; k += 2 )
                  {
                    v23 = k[1] * v75[1];
                    *(float *)(v21 + 16 * *(_DWORD *)k) = v23 * *(v19 - 2) + *(float *)(v21 + 16 * *(_DWORD *)k);
                    *(float *)(16 * *(_DWORD *)k + v21 + 4) = v23 * *(v19 - 1) + *(float *)(16 * *(_DWORD *)k + v21 + 4);
                    *(float *)(16 * *(_DWORD *)k + v21 + 8) = v23 * *v19 + *(float *)(16 * *(_DWORD *)k + v21 + 8);
                    v24 = (float *)(16 * *(_DWORD *)k + v21 + 12);
                    *v24 = v23 * v19[1] + *v24;
                  }
                  v75 += 2;
                }
                while ( v75 < (float *)v71 );
              }
              v19 += 4;
              v18 = v20;
            }
            while ( (unsigned int)v20 < v63 );
          }
          v25 = v62;
          v12 = v71;
          while ( 1 )
          {
            v76 = v25;
            if ( v25 >= v12 )
              break;
            v26 = (void **)((char *)v73 + 12 * *(_DWORD *)v25);
            v27 = v26[2] == (void *)1;
            v26[2] = (char *)v26[2] - 1;
            if ( v27 )
            {
              switch ( *(_DWORD *)(*(_DWORD *)this + 8) )
              {
                case 1:
                  v48 = 0;
                  for ( m = 0; m < *(_DWORD *)(*((_DWORD *)this + 1) + 104); v48 += 16 )
                  {
                    v50 = (float *)((char *)*v26 + v48);
                    if ( *v50 >= 0.0 )
                    {
                      if ( *v50 >= 1.0 )
                        v51 = 1.0;
                      else
                        v51 = *v50;
                    }
                    else
                    {
                      v51 = 0.0;
                    }
                    *v50 = v51;
                    v52 = (float *)((char *)*v26 + v48 + 4);
                    if ( *v52 >= 0.0 )
                    {
                      if ( *v52 >= 1.0 )
                        v53 = 1.0;
                      else
                        v53 = *v52;
                    }
                    else
                    {
                      v53 = 0.0;
                    }
                    *v52 = v53;
                    v54 = (float *)((char *)*v26 + v48 + 8);
                    if ( *v54 >= 0.0 )
                    {
                      if ( *v54 >= 1.0 )
                        v55 = 1.0;
                      else
                        v55 = *v54;
                    }
                    else
                    {
                      v55 = 0.0;
                    }
                    *v54 = v55;
                    v56 = (float *)((char *)*v26 + v48 + 12);
                    if ( *v56 >= 0.0 )
                    {
                      if ( *v56 >= 1.0 )
                        v57 = 1.0;
                      else
                        v57 = *v56;
                    }
                    else
                    {
                      v57 = 0.0;
                    }
                    *v56 = v57;
                    ++m;
                  }
                  break;
                case 2:
                  v38 = 0;
                  for ( n = 0; n < *(_DWORD *)(*((_DWORD *)this + 1) + 104); v38 += 16 )
                  {
                    v40 = (float *)((char *)*v26 + v38);
                    if ( *v40 >= -1.0 )
                    {
                      if ( *v40 >= 1.0 )
                        v41 = 1.0;
                      else
                        v41 = *v40;
                    }
                    else
                    {
                      v41 = -1.0;
                    }
                    *v40 = v41;
                    v42 = (float *)((char *)*v26 + v38 + 4);
                    if ( *v42 >= -1.0 )
                    {
                      if ( *v42 >= 1.0 )
                        v43 = 1.0;
                      else
                        v43 = *v42;
                    }
                    else
                    {
                      v43 = -1.0;
                    }
                    *v42 = v43;
                    v44 = (float *)((char *)*v26 + v38 + 8);
                    if ( *v44 >= -1.0 )
                    {
                      if ( *v44 >= 1.0 )
                        v45 = 1.0;
                      else
                        v45 = *v44;
                    }
                    else
                    {
                      v45 = -1.0;
                    }
                    *v44 = v45;
                    v46 = (float *)((char *)*v26 + v38 + 12);
                    if ( *v46 >= 0.0 )
                    {
                      if ( *v46 >= 1.0 )
                        v47 = 1.0;
                      else
                        v47 = *v46;
                    }
                    else
                    {
                      v47 = 0.0;
                    }
                    *v46 = v47;
                    ++n;
                  }
                  break;
                case 3:
                  v28 = 0;
                  for ( ii = 0; ii < *(_DWORD *)(*((_DWORD *)this + 1) + 104); v28 += 16 )
                  {
                    v30 = (float *)((char *)*v26 + v28);
                    if ( *v30 >= -1.0 )
                    {
                      if ( *v30 >= 1.0 )
                        v31 = 1.0;
                      else
                        v31 = *v30;
                    }
                    else
                    {
                      v31 = -1.0;
                    }
                    *v30 = v31;
                    v32 = (float *)((char *)*v26 + v28 + 4);
                    if ( *v32 >= -1.0 )
                    {
                      if ( *v32 >= 1.0 )
                        v33 = 1.0;
                      else
                        v33 = *v32;
                    }
                    else
                    {
                      v33 = -1.0;
                    }
                    *v32 = v33;
                    v34 = (float *)((char *)*v26 + v28 + 8);
                    if ( *v34 >= -1.0 )
                    {
                      if ( *v34 >= 1.0 )
                        v35 = 1.0;
                      else
                        v35 = *v34;
                    }
                    else
                    {
                      v35 = -1.0;
                    }
                    *v34 = v35;
                    v36 = (float *)((char *)*v26 + v28 + 12);
                    if ( *v36 >= -1.0 )
                    {
                      if ( *v36 >= 1.0 )
                        v37 = 1.0;
                      else
                        v37 = *v36;
                    }
                    else
                    {
                      v37 = -1.0;
                    }
                    *v36 = v37;
                    ++ii;
                  }
                  break;
                default:
                  break;
              }
              v25 = v76;
              (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, void *))(**((_DWORD **)this + 1) + 8))(
                a1: *((_DWORD *)this + 1),
                a2: *(_DWORD *)v76,
                a3: 0,
                a4: *v26);
              v26[1] = v70;
              v12 = v71;
              v70 = v26;
            }
            v25 += 8;
          }
          ++v68;
        }
        while ( (unsigned int)v12 < v60 );
      }
      v58 = 0;
    }
    else
    {
LABEL_116:
      v58 = -2147024882;
    }
  }
  else
  {
    v58 = -2147467259;
  }
  if ( v73 != nullptr )
    D3DXTex::TF_Row::`vector deleting destructor'(this: v73, a2: 3);
  free(pMem);
  free(pMem: v66);
  free(pMem: v72);
  free(pMem: nullptr);
  return v58;
}

//------------------------------------------------------------------------------
// Address: 0x004254E6
// Name: public: long D3DXTex::CBlt::Blt(struct D3DX_BLT __near *,struct D3DX_BLT __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CBlt::Blt(D3DXTex::CBlt *this, struct D3DX_BLT *a2, struct D3DX_BLT *a3, unsigned int a4)
{
  struct D3DXTex::CCodec *v5; // eax
  struct D3DXTex::CCodec *v6; // eax
  int v7; // edi
  void (__thiscall ***v8)(_DWORD, int); // ecx

  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 2) = a4;
  if ( (_WORD)a4 == 0 || (unsigned __int16)a4 > 5u || (a4 & 0xFF800000) != 0 )
    return -2005530516;
  *((_DWORD *)a3 + 18) = a4 & 0x200000;
  *((_DWORD *)a2 + 18) = a4 & 0x400000;
  *((_DWORD *)a2 + 16) = a4 & 0x80000;
  *((_DWORD *)a2 + 17) = a4 & 0x100000;
  v5 = D3DXTex::CCodec::Create(a1: a2);
  *((_DWORD *)this + 1) = v5;
  if ( v5 == nullptr )
    goto LABEL_18;
  v6 = D3DXTex::CCodec::Create(a1: a3);
  *(_DWORD *)this = v6;
  if ( v6 == nullptr )
    goto LABEL_18;
  v7 = D3DXTex::CCodec::ConvertFrom(this: *((D3DXTex::CCodec **)this + 1), a2: v6);
  if ( v7 >= 0 )
  {
    if ( D3DXTex::CBlt::BltSame(this) >= 0
      || D3DXTex::CBlt::BltCopy(this) >= 0
      || D3DXTex::CBlt::BltNone(this) >= 0
      || D3DXTex::CBlt::BltPoint(this) >= 0
      || D3DXTex::CBlt::BltBox2D(this, a2: v7, a3: (float *)this) >= 0
      || D3DXTex::CBlt::BltBox3D(this, a2: v7, a3: (float *)this) >= 0
      || D3DXTex::CBlt::BltLinear2D(this) >= 0
      || D3DXTex::CBlt::BltLinear3D(this) >= 0
      || D3DXTex::CBlt::BltTriangle2D(this) >= 0
      || D3DXTex::CBlt::BltTriangle3D(this) >= 0 )
    {
      v7 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v7 = -2147467259;
  }
LABEL_19:
  v8 = *((void (__thiscall ****)(_DWORD, int))this + 1);
  if ( v8 != nullptr )
  {
    (**v8)(a1: v8, a2: 1);
    *((_DWORD *)this + 1) = 0;
  }
  if ( *(_DWORD *)this != 0 )
  {
    (***(void (__thiscall ****)(_DWORD, int))this)(a1: *(_DWORD *)this, a2: 1);
    *(_DWORD *)this = 0;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00425623
// Name: public: D3DXTex::CLockSurface::CLockSurface(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXTex::CLockSurface::CLockSurface(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *(this + 4) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425636
// Name: long D3DXTex::InternalCopy(struct IDirect3DSurface9 __near *,struct IDirect3DSurface9 __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge D3DXTex::InternalCopy@<eax>(
        int a1@<edi>,
        D3DXTex *this,
        struct IDirect3DSurface9 *a3,
        struct IDirect3DSurface9 *a4)
{
  D3DXTex *v4; // ebx
  int v5; // esi
  int result; // eax
  struct IDirect3DSurface9 *v7; // edi
  int v8; // eax
  unsigned int v9; // ecx
  char *v10; // eax
  char *v11; // edx
  int v13[7]; // [esp+8h] [ebp-38h] BYREF
  unsigned int v14; // [esp+24h] [ebp-1Ch]
  _DWORD v15[2]; // [esp+28h] [ebp-18h] BYREF
  _DWORD v16[2]; // [esp+30h] [ebp-10h] BYREF
  unsigned int v17; // [esp+38h] [ebp-8h]
  unsigned int v18; // [esp+3Ch] [ebp-4h]

  v4 = this;
  (*(void (__stdcall **)(D3DXTex *, int *))(*(_DWORD *)this + 48))(a1: this, a2: v13);
  v5 = 0;
  result = (*(int (__stdcall **)(D3DXTex *, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v4 + 52))(
             a1: v4,
             a2: v16,
             a3: 0,
             a4: 0);
  if ( result >= 0 )
  {
    v7 = a3;
    v8 = ((int (__stdcall *)(struct IDirect3DSurface9 *, _DWORD *, _DWORD, _DWORD, int))a3->LockRect)(
           a1: a3,
           a2: v15,
           a3: 0,
           a4: 0,
           a5: a1);
    if ( v8 >= 0 )
    {
      if ( v13[0] == 827611204
        || v13[0] == 844388420
        || v13[0] == 861165636
        || v13[0] == 877942852
        || v13[0] == 894720068 )
      {
        v9 = (v14 + 3) >> 2;
        v14 = v9;
      }
      else
      {
        v9 = v14;
      }
      v17 = v15[0];
      if ( v15[0] >= v16[0] )
        v17 = v16[0];
      v10 = (char *)v16[1];
      v11 = (char *)v15[1];
      v18 = 0;
      if ( v9 != 0 )
      {
        do
        {
          qmemcpy(v11, v10, v17);
          v10 += v16[0];
          v11 += v15[0];
          ++v18;
        }
        while ( v18 < v14 );
        v7 = a3;
        v4 = this;
        v5 = 0;
      }
      v7->UnlockRect(this: v7);
    }
    else
    {
      v5 = v8;
    }
    (*(void (__cdecl **)(D3DXTex *))(*(_DWORD *)v4 + 56))(a1: v4);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425715
// Name: public: long D3DXTex::CLockSurface::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CLockSurface::Unlock(D3DXTex::CLockSurface *this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  struct IDirect3DSurface9 *v9; // [esp+0h] [ebp-8h]

  v2 = *((_DWORD *)this + 2);
  if ( v2 != 0 || (v2 = *((_DWORD *)this + 1)) != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 56))(a1: v2);
  if ( *((_DWORD *)this + 1) != 0
    && *((_DWORD *)this + 2) != 0
    && *((_DWORD *)this + 4) != 0
    && (*(_BYTE *)this & 1) == 0 )
  {
    D3DXDebugMuteInt(a1: 1);
    v3 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**((_DWORD **)this + 4) + 120))(
           a1: *((_DWORD *)this + 4),
           a2: *((_DWORD *)this + 2),
           a3: 0,
           a4: *((_DWORD *)this + 1),
           a5: 0);
    D3DXDebugMuteInt(a1: 0);
    if ( v3 < 0 )
    {
      D3DXDebugMuteInt(a1: 1);
      D3DXTex::InternalCopy(a1: 0, this: *((D3DXTex **)this + 2), a3: *((struct IDirect3DSurface9 **)this + 1), a4: v9);
      D3DXDebugMuteInt(a1: 0);
    }
  }
  v4 = *((_DWORD *)this + 2);
  if ( v4 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(a1: *((_DWORD *)this + 2));
    *((_DWORD *)this + 2) = 0;
  }
  v5 = *((_DWORD *)this + 3);
  if ( v5 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(a1: *((_DWORD *)this + 3));
    *((_DWORD *)this + 3) = 0;
  }
  v6 = *((_DWORD *)this + 4);
  if ( v6 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(a1: *((_DWORD *)this + 4));
    *((_DWORD *)this + 4) = 0;
  }
  v7 = *((_DWORD *)this + 1);
  if ( v7 != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(a1: *((_DWORD *)this + 1));
    *((_DWORD *)this + 1) = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004257C8
// Name: public: D3DXTex::CLockVolume::CLockVolume(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXTex::CLockVolume::CLockVolume(_DWORD *this)
{
  *this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004257CE
// Name: public: long D3DXTex::CLockVolume::Unlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CLockVolume::Unlock(D3DXTex::CLockVolume *this)
{
  if ( *(_DWORD *)this != 0 )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)this + 40))(a1: *(_DWORD *)this);
    if ( *(_DWORD *)this != 0 )
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)this + 8))(a1: *(_DWORD *)this);
      *(_DWORD *)this = 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004257F2
// Name: public: D3DXTex::CLockSurface::~CLockSurface(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall D3DXTex::CLockSurface::~CLockSurface(D3DXTex::CLockSurface *this)
{
  D3DXTex::CLockSurface::Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x004257F7
// Name: public: long D3DXTex::CLockSurface::Lock(struct D3DX_BLT __near *,struct IDirect3DSurface9 __near *,struct tagPALETTEENTRY const __near *,struct tagRECT const __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXTex::CLockSurface::Lock(
        D3DXTex::CLockSurface *this,
        struct D3DX_BLT *a2,
        struct IDirect3DSurface9 *a3,
        const struct tagPALETTEENTRY *a4,
        const struct tagRECT *a5,
        unsigned int a6,
        unsigned int a7)
{
  BOOL v7; // eax
  int result; // eax
  D3DXTex::CLockSurface *v9; // ebx
  _DWORD *v10; // esi
  _DWORD *v11; // ebx
  struct IDirect3DSurface9 **v12; // edi
  D3DXTex::CLockSurface *v13; // edi
  int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  bool v18; // zf
  unsigned int v19; // eax
  int v20; // esi
  D3DXTex::CLockSurface *v21; // ecx
  struct IDirect3DSurface9 *v22; // [esp+0h] [ebp-7Ch]
  struct IDirect3DSurface9 *v23; // [esp+0h] [ebp-7Ch]
  int v24; // [esp+Ch] [ebp-70h] BYREF
  char v25; // [esp+15h] [ebp-67h]
  int v26; // [esp+18h] [ebp-64h]
  unsigned int v27; // [esp+24h] [ebp-58h]
  unsigned int v28; // [esp+28h] [ebp-54h]
  struct tagRECT v29; // [esp+2Ch] [ebp-50h] BYREF
  struct tagRECT v30; // [esp+3Ch] [ebp-40h]
  _DWORD v31[2]; // [esp+4Ch] [ebp-30h] BYREF
  unsigned int v32; // [esp+54h] [ebp-28h]
  unsigned int v33; // [esp+58h] [ebp-24h]
  unsigned int v34; // [esp+5Ch] [ebp-20h]
  int v35; // [esp+60h] [ebp-1Ch] BYREF
  BOOL v36; // [esp+64h] [ebp-18h]
  D3DXTex::CLockSurface *v37; // [esp+68h] [ebp-14h]
  D3DXTex *v38; // [esp+6Ch] [ebp-10h] BYREF
  int v39; // [esp+70h] [ebp-Ch]
  int v40; // [esp+74h] [ebp-8h]
  int v41; // [esp+78h] [ebp-4h]

  v37 = this;
  D3DXTex::CLockSurface::Unlock(this);
  a3->GetDesc(this: a3, a2: (_D3DSURFACE_DESC *)&v24);
  if ( a5 != nullptr )
  {
    v30 = *a5;
    if ( v30.left < 0
      || v30.right > v27
      || v30.left > v30.right
      || v30.top < 0
      || v30.bottom > v28
      || v30.top > v30.bottom )
    {
      return -2005530516;
    }
    v7 = true;
    if ( v30.left != 0 || v30.right != v27 || v30.top != 0 || (v41 = 0, v30.bottom != v28) )
      v41 = 1;
    if ( (a7 & 1) != 0 || v41 != 0 )
    {
      v36 = false;
      goto LABEL_19;
    }
  }
  else
  {
    v30.right = v27;
    v30.bottom = v28;
    v30.left = 0;
    v30.top = 0;
    v41 = 0;
    v7 = (a7 & 1) == 0;
  }
  v36 = v7;
LABEL_19:
  v32 = a7 & 0x10000;
  if ( (a7 & 0x10000) != 0 )
  {
    v33 = v27;
    v34 = v28;
    v39 = 0;
    if ( (v24 == 827611204 || v24 == 844388420 || v24 == 861165636 || v24 == 877942852 || v24 == 894720068)
      && (((unsigned __int8)v27 | (unsigned __int8)v28) & 3) != 0 )
    {
      do
        ++v39;
      while ( (((v27 | v28) << v39) & 3) != 0 );
    }
    v9 = v37;
    v10 = (_DWORD *)((char *)v37 + 16);
    a3->GetDevice(this: a3, a2: (IDirect3DDevice9 **)((char *)v37 + 16));
    v11 = (_DWORD *)((char *)v9 + 12);
    v40 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, int, _DWORD, int, int, _DWORD *, _DWORD))(*(_DWORD *)*v10 + 92))(
            a1: *v10,
            a2: v33 << v39,
            a3: v34 << v39,
            a4: v39 + 1,
            a5: 0,
            a6: v24,
            a7: (v26 == 3) + 2,
            a8: v11,
            a9: 0);
    if ( v40 < 0
      || (v12 = (struct IDirect3DSurface9 **)((char *)v37 + 8),
          (v40 = (*(int (__stdcall **)(_DWORD, int, char *))(*(_DWORD *)*v11 + 72))(
                   a1: *v11,
                   a2: v39,
                   a3: (char *)v37 + 8)) < 0) )
    {
      v13 = v37;
      v14 = *((_DWORD *)v37 + 2);
      if ( v14 != 0 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 8))(a1: *((_DWORD *)v37 + 2));
        *((_DWORD *)v13 + 2) = 0;
      }
      goto LABEL_38;
    }
    if ( !v36 )
    {
      v38 = nullptr;
      D3DXDebugMuteInt(a1: 1);
      v40 = D3DXTex::InternalCopy(a1: (int)v12, this: (D3DXTex *)a3, a3: *v12, a4: v22);
      D3DXDebugMuteInt(a1: 0);
      if ( v40 < 0 )
      {
        if ( v39 != 0 )
          goto LABEL_36;
        v40 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, int, _DWORD, _DWORD, int, D3DXTex **, _DWORD))(*(_DWORD *)*v10 + 112))(
                a1: *v10,
                a2: v33,
                a3: v34,
                a4: v24,
                a5: 0,
                a6: 0,
                a7: 1,
                a8: &v38,
                a9: 0);
        if ( v40 < 0 )
          goto LABEL_36;
        v40 = (*(int (__stdcall **)(_DWORD, struct IDirect3DSurface9 *, _DWORD, D3DXTex *, _DWORD, _DWORD))(*(_DWORD *)*v10 + 136))(
                a1: *v10,
                a2: a3,
                a3: 0,
                a4: v38,
                a5: 0,
                a6: 0);
        if ( v40 < 0 )
        {
          (*(void (__stdcall **)(D3DXTex *))(*(_DWORD *)v38 + 8))(a1: v38);
          goto LABEL_36;
        }
        v40 = D3DXTex::InternalCopy(a1: (int)v12, this: v38, a3: *v12, a4: v23);
        (*(void (__stdcall **)(D3DXTex *))(*(_DWORD *)v38 + 8))(a1: v38);
        if ( v40 < 0 )
        {
LABEL_36:
          if ( *v12 != nullptr )
          {
            (*v12)->Release(this: *v12);
            *v12 = nullptr;
          }
LABEL_38:
          if ( *v11 != 0 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v11 + 8))(a1: *v11);
            *v11 = 0;
          }
          if ( *v10 != 0 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v10 + 8))(a1: *v10);
            *v10 = 0;
          }
          return v40;
        }
      }
    }
    v38 = (D3DXTex *)*v12;
  }
  else
  {
    v38 = (D3DXTex *)a3;
  }
  v15 = 16 * (a7 & 1 | 0x80);
  if ( v36 && v32 == 0 && (v25 & 2) != 0 )
  {
    if ( (a7 & 0x20000) != 0 )
    {
      v15 |= 0x2000u;
      v41 = 0;
      goto LABEL_88;
    }
    D3DXDebugMuteInt(a1: 1);
    if ( a3->GetContainer(this: a3, a2: &IID_IDirect3DTexture9, a3: (void **)&v35) >= 0 )
    {
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)v35 + 52))(a1: v35) == 1 )
      {
        v15 |= 0x2000u;
        v41 = 0;
      }
      if ( v35 != 0 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v35 + 8))(a1: v35);
        v35 = 0;
      }
    }
    D3DXDebugMuteInt(a1: 0);
  }
  if ( v41 != 0 )
  {
    if ( v24 > 877942852 )
    {
      if ( v24 != 894720068 )
      {
        if ( v24 != 1111970375 && v24 != 1195525970 && v24 != 1498831189 )
          goto LABEL_79;
        goto LABEL_80;
      }
    }
    else if ( v24 != 877942852 && v24 != 827611204 && v24 != 844388420 )
    {
      if ( v24 != 844715353 )
      {
        if ( v24 == 861165636 )
          goto LABEL_65;
LABEL_79:
        v29 = v30;
        goto LABEL_87;
      }
LABEL_80:
      v19 = (v30.right + 1) & 0xFFFFFFFE;
      v29.left = v30.left & 0xFFFFFFFE;
      v29.right = v19;
      v29.top = v30.top;
      v29.bottom = v30.bottom;
      if ( v19 > v27 )
      {
        v19 = v27;
        v29.right = v27;
      }
      if ( (v30.left & 0xFFFFFFFE) == 0 && v19 == v27 && v30.top == 0 )
      {
        v18 = v30.bottom == v28;
LABEL_73:
        if ( v18 )
        {
          v41 = 0;
          goto LABEL_87;
        }
      }
LABEL_86:
      v41 = 1;
      goto LABEL_87;
    }
LABEL_65:
    v16 = (v30.right + 3) & 0xFFFFFFFC;
    v17 = (v30.bottom + 3) & 0xFFFFFFFC;
    v29.left = v30.left & 0xFFFFFFFC;
    v29.right = v16;
    v29.top = v30.top & 0xFFFFFFFC;
    v29.bottom = v17;
    if ( v16 > v27 )
    {
      v16 = v27;
      v29.right = v27;
    }
    if ( v17 > v28 )
    {
      v17 = v28;
      v29.bottom = v28;
    }
    if ( (v30.left & 0xFFFFFFFC) == 0 && v16 == v27 && (v30.top & 0xFFFFFFFC) == 0 )
    {
      v18 = v17 == v28;
      goto LABEL_73;
    }
    goto LABEL_86;
  }
LABEL_87:
  if ( v32 != 0 )
  {
    result = (*(int (__stdcall **)(D3DXTex *, _DWORD *, struct tagRECT *, unsigned int))(*(_DWORD *)v38 + 52))(
               a1: v38,
               a2: v31,
               a3: v41 != 0 ? &v29 : nullptr,
               a4: v15);
    if ( result < 0 )
      return result;
    goto LABEL_91;
  }
LABEL_88:
  D3DXDebugMuteInt(a1: 1);
  v20 = (*(int (__stdcall **)(D3DXTex *, _DWORD *, struct tagRECT *, unsigned int))(*(_DWORD *)v38 + 52))(
          a1: v38,
          a2: v31,
          a3: v41 != 0 ? &v29 : nullptr,
          a4: v15);
  D3DXDebugMuteInt(a1: 0);
  if ( v20 < 0 )
    return D3DXTex::CLockSurface::Lock(this: v37, a2, a3, a4, a5, a6, a7: a7 | 0x10000);
LABEL_91:
  if ( v41 != 0 )
  {
    v30.left -= v29.left;
    v30.right -= v29.left;
    v30.top -= v29.top;
    v30.bottom -= v29.top;
  }
  *(_DWORD *)a2 = v31[1];
  *((_DWORD *)a2 + 1) = v24;
  *((_DWORD *)a2 + 2) = v31[0];
  *((_DWORD *)a2 + 6) = v27;
  *((_DWORD *)a2 + 7) = v28;
  *((_DWORD *)a2 + 10) = v30.left;
  *((_DWORD *)a2 + 9) = 1;
  *((_DWORD *)a2 + 11) = v30.top;
  *((_DWORD *)a2 + 15) = 1;
  *((_DWORD *)a2 + 16) = 1;
  *((_DWORD *)a2 + 19) = a6;
  *((_DWORD *)a2 + 12) = v30.right;
  *((_DWORD *)a2 + 3) = 0;
  *((_DWORD *)a2 + 4) = 0;
  *((_DWORD *)a2 + 5) = 0;
  *((_DWORD *)a2 + 8) = 0;
  *((_DWORD *)a2 + 14) = 0;
  *((_DWORD *)a2 + 17) = 0;
  *((_DWORD *)a2 + 18) = 0;
  *((_DWORD *)a2 + 20) = a4;
  v21 = v37;
  *((_DWORD *)a2 + 13) = v30.bottom;
  *((_DWORD *)v21 + 1) = a3;
  *(_DWORD *)v21 = a7;
  a3->AddRef(this: a3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425CE6
// Name: public: D3DXTex::CLockVolume::~CLockVolume(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall D3DXTex::CLockVolume::~CLockVolume(D3DXTex::CLockVolume *this)
{
  D3DXTex::CLockVolume::Unlock(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425CEB
// Name: public: long D3DXTex::CLockVolume::Lock(struct D3DX_BLT __near *,struct IDirect3DVolume9 __near *,struct tagPALETTEENTRY const __near *,struct _D3DBOX const __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall D3DXTex::CLockVolume::Lock(
        D3DXTex::CLockVolume *this,
        struct D3DX_BLT *a2,
        struct IDirect3DVolume9 *a3,
        const struct tagPALETTEENTRY *a4,
        const struct _D3DBOX *a5,
        unsigned int a6,
        unsigned int a7)
{
  bool v7; // zf
  unsigned int Back; // ebx
  BOOL v9; // eax
  HRESULT result; // eax
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // edx
  int v16; // ecx
  unsigned int v17; // edx
  D3DXTex::CLockVolume *v18; // ecx
  int v19; // [esp+Ch] [ebp-64h] BYREF
  int v20; // [esp+14h] [ebp-5Ch]
  int v21; // [esp+18h] [ebp-58h]
  unsigned int v22; // [esp+1Ch] [ebp-54h]
  unsigned int v23; // [esp+20h] [ebp-50h]
  unsigned int v24; // [esp+24h] [ebp-4Ch]
  struct _D3DBOX v25; // [esp+28h] [ebp-48h] BYREF
  struct _D3DBOX v26; // [esp+40h] [ebp-30h]
  _DWORD v27[3]; // [esp+58h] [ebp-18h] BYREF
  D3DXTex::CLockVolume *v28; // [esp+64h] [ebp-Ch]
  unsigned int v29; // [esp+68h] [ebp-8h]
  int v30; // [esp+6Ch] [ebp-4h] BYREF
  int v31; // [esp+84h] [ebp+14h]

  v7 = *(_DWORD *)this == 0;
  v28 = this;
  if ( !v7 )
    D3DXTex::CLockVolume::Unlock(this);
  a3->GetDesc(this: a3, a2: (_D3DVOLUME_DESC *)&v19);
  if ( a5 != nullptr )
  {
    v26 = *a5;
    if ( v26.Right > v22 )
      return -2005530516;
    if ( v26.Left > v26.Right )
      return -2005530516;
    if ( v26.Bottom > v23 )
      return -2005530516;
    if ( v26.Top > v26.Bottom )
      return -2005530516;
    Back = v26.Back;
    if ( v26.Back > v24 || v26.Front > v26.Back )
      return -2005530516;
    if ( v26.Left != 0
      || v26.Right != v22
      || v26.Top != 0
      || v26.Bottom != v23
      || v26.Front != 0
      || (v31 = 0, v26.Back != v24) )
    {
      v31 = 1;
    }
    v9 = (a7 & 1) == 0 && v31 == 0;
  }
  else
  {
    Back = v24;
    v31 = 0;
    v26.Right = v22;
    v26.Bottom = v23;
    v9 = (a7 & 1) == 0;
    v26.Left = 0;
    v26.Top = 0;
    v26.Front = 0;
    v26.Back = v24;
  }
  if ( v21 == 0 && (v20 & 0x200) == 0 )
    return -2005530516;
  v11 = 16 * (a7 & 1 | 0x80);
  v29 = v11;
  if ( v9 && (v20 & 0x200) != 0 )
  {
    if ( (a7 & 0x20000) != 0 )
    {
      v11 |= 0x2000u;
      goto LABEL_54;
    }
    D3DXDebugMuteInt(a1: 1);
    if ( a3->GetContainer(this: a3, a2: &IID_IDirect3DVolumeTexture9, a3: (void **)&v30) >= 0 )
    {
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)v30 + 52))(a1: v30) == 1 )
      {
        v11 |= 0x2000u;
        v29 = v11;
        v31 = 0;
      }
      if ( v30 != 0 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v30 + 8))(a1: v30);
        v30 = 0;
      }
    }
    D3DXDebugMuteInt(a1: 0);
  }
  if ( v31 == 0 )
    goto LABEL_54;
  if ( v19 > 877942852 )
  {
    if ( v19 == 894720068 )
      goto LABEL_42;
    if ( v19 != 1111970375 && v19 != 1195525970 && v19 != 1498831189 )
    {
LABEL_60:
      v25 = v26;
LABEL_70:
      v11 = v29;
LABEL_71:
      result = a3->LockBox(this: a3, a2: (_D3DLOCKED_BOX *)v27, a3: &v25, a4: v11);
      if ( result < 0 )
        return result;
      v26.Left -= v25.Left;
      v26.Right -= v25.Left;
      v26.Top -= v25.Top;
      v26.Bottom -= v25.Top;
      v26.Front -= v25.Front;
      v26.Back = Back - v25.Front;
      goto LABEL_73;
    }
LABEL_61:
    v14 = (v26.Right + 1) & 0xFFFFFFFE;
    v25.Bottom = v26.Bottom;
    v25.Left = v26.Left & 0xFFFFFFFE;
    v25.Right = v14;
    v25.Top = v26.Top;
    v25.Front = v26.Front;
    v25.Back = Back;
    if ( v14 > v22 )
    {
      v14 = v22;
      v25.Right = v22;
    }
    if ( (v26.Left & 0xFFFFFFFE) != 0
      || v14 != v22
      || v26.Top != 0
      || v26.Bottom != v23
      || v26.Front != 0
      || Back != v24 )
    {
      goto LABEL_71;
    }
    goto LABEL_54;
  }
  if ( v19 != 877942852 && v19 != 827611204 && v19 != 844388420 )
  {
    if ( v19 == 844715353 )
      goto LABEL_61;
    if ( v19 != 861165636 )
      goto LABEL_60;
  }
LABEL_42:
  v12 = (v26.Right + 3) & 0xFFFFFFFC;
  v13 = (v26.Bottom + 3) & 0xFFFFFFFC;
  v25.Left = v26.Left & 0xFFFFFFFC;
  v25.Right = v12;
  v25.Top = v26.Top & 0xFFFFFFFC;
  v25.Bottom = v13;
  v25.Front = v26.Front;
  v25.Back = Back;
  if ( v12 > v22 )
  {
    v12 = v22;
    v25.Right = v22;
  }
  if ( v13 > v23 )
  {
    v13 = v23;
    v25.Bottom = v23;
  }
  if ( (v26.Left & 0xFFFFFFFC) != 0
    || v12 != v22
    || (v26.Top & 0xFFFFFFFC) != 0
    || v13 != v23
    || v26.Front != 0
    || Back != v24 )
  {
    goto LABEL_70;
  }
  v11 = v29;
LABEL_54:
  result = a3->LockBox(this: a3, a2: (_D3DLOCKED_BOX *)v27, a3: nullptr, a4: v11);
  if ( result >= 0 )
  {
LABEL_73:
    v15 = v22;
    *(_DWORD *)a2 = v27[2];
    v16 = v19;
    *((_DWORD *)a2 + 17) = 0;
    *((_DWORD *)a2 + 18) = 0;
    *((_DWORD *)a2 + 1) = v16;
    *((_DWORD *)a2 + 2) = v27[0];
    *((_DWORD *)a2 + 3) = v27[1];
    *((_DWORD *)a2 + 4) = 0;
    *((_DWORD *)a2 + 5) = 0;
    *((_DWORD *)a2 + 8) = 0;
    *((_DWORD *)a2 + 9) = v24;
    qmemcpy((char *)a2 + 40, &v26, 24);
    *((_DWORD *)a2 + 19) = a6;
    *((_DWORD *)a2 + 6) = v15;
    v17 = v23;
    *((_DWORD *)a2 + 20) = a4;
    v18 = v28;
    *((_DWORD *)a2 + 7) = v17;
    *((_DWORD *)a2 + 16) = 1;
    *(_DWORD *)v18 = a3;
    a3->AddRef(this: a3);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427094
// Name: float D3DXTex::TableEncodeGamma22(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __stdcall D3DXTex::TableEncodeGamma22(D3DXTex *this, float a2)
{
  float thisa; // [esp+10h] [ebp+8h]

  thisa = TableInvSqrt(a1: *(float *)&this) * *(float *)&this * 254.0;
  return flt_4ED4A8[thisa] + (flt_4ED4AC[thisa] - flt_4ED4A8[thisa]) * (thisa - (double)(unsigned int)(int)thisa);
}

//------------------------------------------------------------------------------
// Address: 0x004270E6
// Name: float D3DXTex::TableDecodeGamma22(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __stdcall D3DXTex::TableDecodeGamma22(D3DXTex *this, float a2)
{
  float thisa; // [esp+Ch] [ebp+8h]

  thisa = *(float *)&this * *(float *)&this * 254.0;
  return flt_4ED8A8[thisa] + (flt_4ED8AC[thisa] - flt_4ED8A8[thisa]) * (thisa - (double)(unsigned int)(int)thisa);
}
