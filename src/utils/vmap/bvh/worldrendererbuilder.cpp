// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/worldrendererbuilder.cpp
// Functions: 18
// ============================================================

#include "utils\vmap\bvh\worldrendererbuilder.h"

//------------------------------------------------------------------------------
// Address: 0x004120B0
// Name: void SaveFileSpace(struct _iobuf __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveFileSpace(_iobuf *fp, unsigned __int64 nSizeBytes)
{
  int v3; // ebx
  unsigned __int64 v4; // kr08_8
  unsigned int v5; // ecx
  int v6; // esi
  unsigned __int8 data[1028]; // [esp+Ch] [ebp-408h] BYREF
  unsigned int v8; // [esp+410h] [ebp-4h]
  unsigned int nSizeBytesa; // [esp+420h] [ebp+Ch]
  int nSizeBytes_4; // [esp+424h] [ebp+10h]

  v8 = (nSizeBytes / 0xFFFFFFFF) >> 32;
  v3 = nSizeBytes / 0xFFFFFFFF;
  memset(dst: data, value: 0, count: 0x400u);
  if ( v3 > 0 )
  {
    nSizeBytes_4 = nSizeBytes / 0xFFFFFFFF;
    do
    {
      fwrite(buffer: data, size: 0x400u, count: 0x3FFFFFu, stream: fp);
      --nSizeBytes_4;
    }
    while ( nSizeBytes_4 != 0 );
  }
  v4 = nSizeBytes - 0xFFFFFFFF * __PAIR64__(v8, v3);
  v5 = v4 >> 10;
  v6 = 0;
  for ( nSizeBytesa = v5; v6 < __PAIR64__(HIDWORD(v4) >> 10, nSizeBytesa); ++v6 )
    fwrite(buffer: data, size: 0x400u, count: 1u, stream: fp);
  fwrite(buffer: data, size: v4 & 0x3FF, count: 1u, stream: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00412190
// Name: bool CompileShaders(struct IDirect3DDevice9 __near *,struct IDirect3DVertexShader9 __near * __near *,struct IDirect3DPixelShader9 __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompileShaders(IDirect3DDevice9 *pd3dDevice, IDirect3DVertexShader9 **ppVS, IDirect3DPixelShader9 **ppPS)
{
  const char *v3; // eax
  const char *v5; // eax
  IDirect3DDevice9_vtbl *v6; // edi
  int v7; // eax
  int v8; // edi
  IDirect3DDevice9_vtbl *v9; // edi
  int v10; // eax
  int v11; // esi
  ID3DXBuffer *pPSBuffer; // [esp+4h] [ebp-10h] BYREF
  ID3DXBuffer *pVSBuffer; // [esp+8h] [ebp-Ch] BYREF
  ID3DXBuffer *pErrorBufferPS; // [esp+Ch] [ebp-8h] BYREF
  ID3DXBuffer *pErrorBufferVS; // [esp+10h] [ebp-4h] BYREF

  pVSBuffer = nullptr;
  pPSBuffer = nullptr;
  pErrorBufferVS = nullptr;
  pErrorBufferPS = nullptr;
  if ( D3DXCompileShader(
         a1: szShader,
         a2: 0x178u,
         a3: nullptr,
         a4: nullptr,
         a5: (int)"VS",
         a6: (int)"vs_3_0",
         a7: 0,
         a8: (int)&pVSBuffer,
         a9: &pErrorBufferVS,
         a10: 0) >= 0 )
  {
    if ( D3DXCompileShader(
           a1: szShader,
           a2: 0x178u,
           a3: nullptr,
           a4: nullptr,
           a5: (int)"PS",
           a6: (int)"ps_3_0",
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
             a2: ppVS);
      v8 = ((int (__stdcall *)(IDirect3DDevice9 *, int))v6->CreateVertexShader)(a1: pd3dDevice, a2: v7);
      pVSBuffer->Release(this: pVSBuffer);
      if ( v8 >= 0 )
      {
        v9 = pd3dDevice->__vftable;
        v10 = ((int (__stdcall *)(ID3DXBuffer *, IDirect3DPixelShader9 **))pPSBuffer->GetBufferPointer)(
                a1: pPSBuffer,
                a2: ppPS);
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
// Address: 0x004122C0
// Name: private: bool CWorldRendererBuilder::InitD3DParams(struct IDirect3DDevice9 __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorldRendererBuilder::InitD3DParams(
        CWorldRendererBuilder *this,
        IDirect3DDevice9 *pd3dDevice,
        IDirect3DVertexShader9 *Width,
        IDirect3DSurface9 *Height,
        float flGutterSize)
{
  IDirect3DDevice9 *v5; // esi
  HRESULT (__stdcall *CreateVertexDeclaration)(IDirect3DDevice9 *, const _D3DVERTEXELEMENT9 *, IDirect3DVertexDeclaration9 **); // eax
  IDirect3DSurface9 *v9; // edx
  IDirect3DVertexShader9 *v10; // eax
  IDirect3DPixelShader9 *v11; // ecx
  IDirect3DVertexDeclaration9 *v12; // edx
  _D3DVERTEXELEMENT9 paramvertexDecl[3]; // [esp+Ch] [ebp-20h] BYREF
  IDirect3DVertexDeclaration9 *pDecl; // [esp+24h] [ebp-8h] BYREF
  IDirect3DPixelShader9 *pPS; // [esp+28h] [ebp-4h] BYREF

  v5 = pd3dDevice;
  if ( pd3dDevice->CreateTexture(
         this: pd3dDevice,
         a2: (unsigned int)Width,
         a3: (unsigned int)Height,
         a4: 1u,
         a5: 1u,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_DEFAULT,
         a8: (IDirect3DTexture9 **)&pd3dDevice,
         a9: nullptr) < 0 )
    return 0;
  ((void (__stdcall *)(IDirect3DDevice9 *, _DWORD, IDirect3DSurface9 **))pd3dDevice->GetBackBuffer)(
    a1: pd3dDevice,
    a2: 0,
    a3: &Height);
  if ( !CompileShaders(pd3dDevice: v5, ppVS: &Width, ppPS: &pPS) )
    return 0;
  *(_DWORD *)&paramvertexDecl[0].Stream = 0;
  CreateVertexDeclaration = v5->CreateVertexDeclaration;
  *(_DWORD *)&paramvertexDecl[0].Type = 1;
  *(_DWORD *)&paramvertexDecl[1].Stream = 0x80000;
  *(_DWORD *)&paramvertexDecl[1].Type = 327681;
  *(_DWORD *)&paramvertexDecl[2].Stream = 255;
  *(_DWORD *)&paramvertexDecl[2].Type = 17;
  if ( CreateVertexDeclaration(this: v5, a2: paramvertexDecl, a3: &pDecl) < 0 )
    return 0;
  v9 = Height;
  v10 = Width;
  this->m_D3DParams.m_pRenderTarget = (IDirect3DTexture9 *)pd3dDevice;
  v11 = pPS;
  this->m_D3DParams.m_pRTSurface = v9;
  v12 = pDecl;
  this->m_D3DParams.m_pd3dDevice = v5;
  this->m_D3DParams.m_pVS = v10;
  this->m_D3DParams.m_pPS = v11;
  this->m_D3DParams.m_pDecl = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004123F0
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int v2; // ebx
  int m_nBlocks; // edi
  IMemAlloc_vtbl *v5; // edx
  CacheOptimizedTriangle **v6; // eax
  unsigned int v7; // ebx

  v2 = nBlocks;
  m_nBlocks = this->m_nBlocks;
  this->m_nBlocks = nBlocks;
  if ( nBlocks < m_nBlocks )
  {
    do
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[v2++]);
    while ( v2 < m_nBlocks );
  }
  v5 = _g_pMemAlloc->__vftable;
  if ( this->m_pMemory != nullptr )
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(CacheOptimizedTriangle **, int))v5->Realloc_2)(
                                      a1: this->m_pMemory,
                                      a2: 4 * this->m_nBlocks);
  else
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * this->m_nBlocks);
  this->m_pMemory = v6;
  if ( v6 == nullptr )
    _Error(a1: "CUtlBlockMemory overflow!\n");
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[m_nBlocks++] = (CacheOptimizedTriangle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    while ( m_nBlocks < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004124A0
// Name: public: bool CWorldRendererBuilder::ReorderResourceFile(char __near *,char __near *,class CUtlVector<class CBVHNodeBuilder __near *,class CUtlMemory<class CBVHNodeBuilder __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorldRendererBuilder::ReorderResourceFile(
        CWorldRendererBuilder *this,
        char *pszInputFile,
        char *pszOutputFile,
        CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > *OrderedNodes)
{
  CWorldRendererBuilder *v4; // esi
  CResourceDictionaryBuilder *v5; // eax
  int m_Size; // edi
  int *v8; // ebx
  CBVHDictionaryEntry *v9; // esi
  void *v10; // edi
  int v11; // edi
  CBVHNodeBuilder *v12; // ecx
  int v13; // edx
  int v14; // eax
  int v15; // edi
  int v16; // esi
  unsigned int v17; // ebx
  void *v18; // edi
  unsigned int elementSize; // [esp+14h] [ebp-2Ch]
  int nNodes; // [esp+18h] [ebp-28h]
  int nOldResource; // [esp+1Ch] [ebp-24h]
  int *pEntryMap; // [esp+20h] [ebp-20h]
  int nInstancedEntries; // [esp+24h] [ebp-1Ch]
  CBVHNodeBuilder *pNode; // [esp+28h] [ebp-18h]
  int nResources; // [esp+2Ch] [ebp-14h]
  _iobuf *fpOut; // [esp+30h] [ebp-10h]
  _iobuf *fpIn; // [esp+34h] [ebp-Ch]
  CResourceDictionaryBuilder *m_pNewBuilder; // [esp+3Ch] [ebp-4h]
  int r; // [esp+48h] [ebp+8h]
  int ra; // [esp+48h] [ebp+8h]
  int n; // [esp+4Ch] [ebp+Ch]
  int na; // [esp+4Ch] [ebp+Ch]

  v4 = this;
  v5 = (CResourceDictionaryBuilder *)MemAlloc_Alloc(nSize: 0x118u);
  if ( v5 != nullptr )
    m_pNewBuilder = CResourceDictionaryBuilder::CResourceDictionaryBuilder(this: v5);
  else
    m_pNewBuilder = nullptr;
  V_strncpy(pDest: m_pNewBuilder->m_pPageFile, pSrc: v4->m_pDictionaryBuilder->m_pPageFile, maxLen: 64);
  fpIn = fopen(file: pszInputFile, mode: "rb");
  if ( fpIn == nullptr )
    return 0;
  fpOut = fopen(file: pszOutputFile, mode: "wb");
  if ( fpOut == nullptr )
    return 0;
  m_Size = v4->m_pDictionaryBuilder->m_EntryList.m_Size;
  v8 = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)m_Size >> 30 != 0 ? -1 : 4 * m_Size);
  pEntryMap = v8;
  if ( v8 == nullptr )
    return 0;
  if ( m_Size > 0 )
    memset(v8, 0xFFu, 4 * m_Size);
  nInstancedEntries = v4->m_pDictionaryBuilder->m_nInstancedEntries;
  r = 0;
  if ( nInstancedEntries > 0 )
  {
    n = 0;
    do
    {
      v9 = &v4->m_pDictionaryBuilder->m_EntryList.m_Memory.m_pMemory[n];
      v8[r] = CResourceDictionaryBuilder::AddEntry(
                this: m_pNewBuilder,
                nFlags: v9->m_Flags,
                nSizeBytes: v9->m_ChunkDesc.m_nSize,
                nResourceType: v9->m_nResourceType,
                pName: v9->m_pName,
                bInstanced: v9->m_nResourceType != 18);
      elementSize = v9->m_ChunkDesc.m_nSize;
      v10 = MemAlloc_Alloc(nSize: elementSize);
      if ( v10 == nullptr )
        return 0;
      _fseeki64(stream: fpIn, offset: v9->m_ChunkDesc.m_nOffset, whence: 0);
      fread(buffer: v10, elementSize, count: 1u, stream: fpIn);
      fwrite(buffer: v10, size: elementSize, count: 1u, stream: fpOut);
      free(pMem: v10);
      ++n;
      v4 = this;
    }
    while ( ++r < nInstancedEntries );
  }
  v11 = 0;
  nNodes = OrderedNodes->m_Size;
  na = 0;
  if ( nNodes > 0 )
  {
    do
    {
      v12 = OrderedNodes->m_Memory.m_pMemory[v11];
      v13 = v12->m_ResourceEntryList.m_Size;
      v14 = 0;
      pNode = v12;
      nResources = v13;
      ra = 0;
      if ( v13 > 0 )
      {
        do
        {
          v15 = v12->m_ResourceEntryList.m_Memory.m_pMemory[v14];
          nOldResource = v15;
          if ( v8[v15] == -1 )
          {
            v16 = (int)&v4->m_pDictionaryBuilder->m_EntryList.m_Memory.m_pMemory[v15];
            v8[v15] = CResourceDictionaryBuilder::AddEntry(
                        this: m_pNewBuilder,
                        nFlags: *(_BYTE *)(v16 + 100),
                        nSizeBytes: *(_QWORD *)(v16 + 16),
                        nResourceType: *(_DWORD *)(v16 + 32),
                        pName: (char *)(v16 + 36),
                        bInstanced: false);
            v17 = *(_DWORD *)(v16 + 16);
            v18 = MemAlloc_Alloc(nSize: v17);
            if ( v18 == nullptr )
              return 0;
            _fseeki64(stream: fpIn, offset: *(_QWORD *)(v16 + 8), whence: 0);
            fread(buffer: v18, elementSize: v17, count: 1u, stream: fpIn);
            fwrite(buffer: v18, size: v17, count: 1u, stream: fpOut);
            free(pMem: v18);
            v8 = pEntryMap;
            v12 = pNode;
            v13 = nResources;
            v14 = ra;
            v15 = nOldResource;
          }
          v12->m_ResourceEntryList.m_Memory.m_pMemory[v14] = v8[v15];
          v4 = this;
          ra = ++v14;
        }
        while ( v14 < v13 );
        v11 = na;
      }
      na = ++v11;
    }
    while ( v11 < nNodes );
  }
  fclose(stream: fpIn);
  fclose(stream: fpOut);
  free(pMem: v8);
  if ( v4->m_pDictionaryBuilder != nullptr )
    ((void (__thiscall *)(CResourceDictionaryBuilder *, int))v4->m_pDictionaryBuilder->dtr_CResourceDictionaryBuilder)(
      a1: v4->m_pDictionaryBuilder,
      a2: 1);
  v4->m_pDictionaryBuilder = m_pNewBuilder;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412770
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004127B0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412800
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412860
// Name: public: unsigned __int64 CWorldRendererBuilder::BuildEntityChunk(class CUtlBuffer __near *,struct entity_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CWorldRendererBuilder::BuildEntityChunk(
        CWorldRendererBuilder *this,
        CUtlBuffer *pOutputBuffer,
        entity_t *pEntities,
        int nEntities)
{
  entity_t *v6; // ecx
  const char *v7; // edi
  epair_t *i; // edi
  char *key; // ecx
  char *v10; // edx
  char v11; // al
  char *value; // ecx
  char *v13; // edx
  char v14; // al
  bool v15; // zf
  int m_Put; // eax
  char string[2048]; // [esp+8h] [ebp-1000h] BYREF
  char v19[1024]; // [esp+808h] [ebp-800h] BYREF
  char e[1024]; // [esp+C08h] [ebp-400h] BYREF
  epair_t **p_epairs; // [esp+1010h] [ebp+8h]
  int v22; // [esp+1014h] [ebp+Ch]
  Vector *p_origin; // [esp+1018h] [ebp+10h]

  CUtlBuffer::EnsureCapacity(this: pOutputBuffer, num: 0x40000);
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "\"Entities\"\n");
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "{\n");
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "\"Traversal\"\n");
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "{\n");
  if ( nEntities > 0 )
  {
    v6 = (entity_t *)&entities;
    p_origin = &entities;
    p_epairs = &pEntities->epairs;
    v22 = nEntities;
    do
    {
      if ( v6->epairs != nullptr )
      {
        v7 = ValueForKey(ent: v6, key: "classname");
        if ( v7 != nullptr )
        {
          CUtlBuffer::PutString(this: pOutputBuffer, pString: "\"");
          CUtlBuffer::PutString(this: pOutputBuffer, pString: v7);
          CUtlBuffer::PutString(this: pOutputBuffer, pString: "\"");
          CUtlBuffer::PutString(this: pOutputBuffer, pString: "\n");
        }
        else
        {
          CUtlBuffer::PutString(this: pOutputBuffer, pString: "\"SomeEntity\"\n");
        }
        CUtlBuffer::PutString(this: pOutputBuffer, pString: "{\n");
        for ( i = *p_epairs; i != nullptr; i = i->next )
        {
          key = i->key;
          v10 = e;
          do
          {
            v11 = *key;
            *v10++ = *key++;
          }
          while ( v11 != 0 );
          StripTrailing(e);
          value = i->value;
          v13 = v19;
          do
          {
            v14 = *value;
            *v13++ = *value++;
          }
          while ( v14 != 0 );
          StripTrailing(e: v19);
          sprintf(string, format: "\"%s\" \"%s\"\n", e, v19);
          CUtlBuffer::PutString(this: pOutputBuffer, pString: string);
        }
        CUtlBuffer::PutString(this: pOutputBuffer, pString: "}\n");
        v6 = (entity_t *)p_origin;
      }
      p_epairs += 11;
      ++v6;
      v15 = v22-- == 1;
      p_origin = &v6->origin;
    }
    while ( !v15 );
  }
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "}\n");
  CUtlBuffer::PutString(this: pOutputBuffer, pString: "}\n");
  if ( (pOutputBuffer->m_Flags & 1) != 0 )
  {
    m_Put = pOutputBuffer->m_Put;
    if ( m_Put != 0 && pOutputBuffer->m_Memory.m_pMemory[m_Put - pOutputBuffer->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: pOutputBuffer);
  }
  if ( CUtlBuffer::CheckPut(this: pOutputBuffer, nSize: 1) )
  {
    pOutputBuffer->m_Memory.m_pMemory[pOutputBuffer->m_Put++ - pOutputBuffer->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: pOutputBuffer, nPut: pOutputBuffer->m_Put);
  }
  return pOutputBuffer->m_Put;
}

//------------------------------------------------------------------------------
// Address: 0x00412A60
// Name: public: void CWorldRendererBuilder::SaveToDmeWorld(char const __near *,struct BVHBuilderParams_t __near &,class CUtlVector<class CBVHNodeBuilder __near *,class CUtlMemory<class CBVHNodeBuilder __near *,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRendererBuilder::SaveToDmeWorld(
        CWorldRendererBuilder *this,
        int pMapName,
        BVHBuilderParams_t *params,
        CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > *orderedNodes,
        const char *pEntities)
{
  DmFileId_t v5; // ebx
  DmElementHandle_t (__thiscall *CreateElement_2)(IDataModel *, CUtlSymbolLarge, const char *, DmFileId_t, const UniqueId_t *); // eax
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  CDmAttribute *Attribute; // eax
  DmElementHandle_t v14; // eax
  CDmElement *v15; // eax
  CVTFTexture *v16; // esi
  CDmElement *v17; // eax
  BVHBuilderParams_t *v18; // esi
  CDmElement *v19; // eax
  CDmElement *v20; // eax
  CDmElement *v21; // eax
  CDmElement *v22; // eax
  CDmElement *v23; // eax
  CDmElement *v24; // eax
  CDmElement *v25; // eax
  CDmElement *v26; // eax
  CDmElement *v27; // eax
  CDmElement *v28; // eax
  CDmElement *v29; // eax
  CDmElement *v30; // eax
  CDmElement *v31; // eax
  CDmElement *v32; // eax
  CDmElement *v33; // eax
  CDmElement *v34; // eax
  int v35; // ebx
  DmElementHandle_t v36; // eax
  CDmElement *v37; // eax
  CDmElement *v38; // esi
  DmElementHandle_t v39; // eax
  const char *v40; // eax
  CVTFTexture *v41; // ecx
  CDmElement *v42; // eax
  CDmElement *v43; // eax
  CBVHNodeBuilder *m_pParentNode; // eax
  int v45; // eax
  DmElementHandle_t v46; // edx
  CDmElement *v47; // eax
  BVHNodeHeader_t *m_pHeader; // eax
  __int64 v49; // xmm0_8
  DmElementHandle_t v50; // eax
  CDmElement *v51; // eax
  BVHNodeHeader_t *v52; // eax
  __int64 v53; // xmm0_8
  DmElementHandle_t v54; // eax
  CDmElement *v55; // eax
  BVHNodeHeader_t *v56; // eax
  __int64 v57; // xmm0_8
  DmElementHandle_t v58; // eax
  CDmElement *v59; // eax
  DmElementHandle_t v60; // edx
  CDmElement *v61; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  int v63; // eax
  CDmElement *v64; // eax
  char pDmeWorldName[260]; // [esp+Ch] [ebp-150h] BYREF
  CDisableUndoScopeGuard guard; // [esp+110h] [ebp-4Ch]
  CUtlSymbolLarge value; // [esp+118h] [ebp-44h] BYREF
  __int64 v68; // [esp+11Ch] [ebp-40h] BYREF
  _QWORD v69[2]; // [esp+124h] [ebp-38h] BYREF
  int m_nID; // [esp+134h] [ebp-28h] BYREF
  float m_flMinimumDistance; // [esp+138h] [ebp-24h] BYREF
  int nNodes; // [esp+13Ch] [ebp-20h]
  int m_Flags; // [esp+140h] [ebp-1Ch] BYREF
  DmElementHandle_t src; // [esp+144h] [ebp-18h] BYREF
  int nChildID; // [esp+148h] [ebp-14h] BYREF
  int v76; // [esp+14Ch] [ebp-10h] BYREF
  DmElementHandle_t CenterVertIndex; // [esp+150h] [ebp-Ch] BYREF
  DmFileId_t dmFileId; // [esp+154h] [ebp-8h]
  CDmElement *v79; // [esp+158h] [ebp-4h]

  guard.m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  V_snprintf(pDest: pDmeWorldName, maxLen: 260, pFormat: "maps/%s/world.wld", (const char *)pMapName);
  v5 = g_pDataModel->FindOrCreateFileId(this: g_pDataModel, a2: pDmeWorldName);
  CreateElement_2 = g_pDataModel->CreateElement_2;
  dmFileId = v5;
  v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))CreateElement_2)(
         a1: g_pDataModel,
         a2: (CUtlSymbolLarge)CDmElement::m_classType.u.m_Id,
         a3: "root",
         a4: v5,
         a5: nullptr);
  v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
  v9 = v8;
  if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
  {
    v79 = v9;
  }
  else
  {
    v79 = nullptr;
    v9 = nullptr;
  }
  v10 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeWorld::m_classType.u.m_Id,
          a3: "world",
          a4: v5,
          a5: nullptr);
  v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
  v12 = v11;
  if ( v11 != nullptr && v11->IsA(this: v11, a2: CDmeWorld::m_classType) )
  {
    pMapName = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v12);
  }
  else
  {
    v12 = nullptr;
    pMapName = -1;
  }
  Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "world");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "world", type: AT_FIRST_VALUE_TYPE)) != nullptr )
  {
    CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: (const DmElementHandle_t *)&pMapName);
  }
  v14 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
          a1: g_pDataModel,
          a2: (CUtlSymbolLarge)CDmeWorldBuilderParams::m_classType.u.m_Id,
          a3: "builderparams",
          a4: v5,
          a5: nullptr);
  v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
  v16 = (CVTFTexture *)v15;
  if ( v15 == nullptr || !v15->IsA(this: v15, a2: CDmeWorldBuilderParams::m_classType) )
    v16 = nullptr;
  if ( v16 != nullptr )
    pMapName = CCoreDispNode::GetCenterVertIndex(this: v16);
  else
    pMapName = -1;
  CDmAttribute::SetValue<enum DmElementHandle_t>(
    this: *(CDmAttribute **)&v12[1].m_Id.m_Value[4],
    value: (const DmElementHandle_t *)&pMapName);
  v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  v18 = params;
  CDmAttribute::SetValue<int>(this: *(CDmAttribute **)v17[1].m_Id.m_Value, value: &params->m_nSizeBytesPerVoxel);
  v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: *(CDmAttribute **)&v19[1].m_Id.m_Value[8], value: &v18->m_flMinDrawVolumeSize);
  v20 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: (CDmAttribute *)v20[1].m_Name.m_Storage.u.m_Id, value: &v18->m_flMinDistToCamera);
  v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: (CDmAttribute *)v21[1].m_ref.m_hElement, value: &v18->m_flMinAtlasDist);
  v22 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: *((CDmAttribute **)&v22[1].m_ref + 2), value: &v18->m_flMinSimplifiedDist);
  v23 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: (CDmAttribute *)v23[1].m_ref.m_attributes.m_pNext, value: &v18->m_flHorzFOV);
  v24 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: (CDmAttribute *)v24[1].m_Type.u.m_Id, value: &v18->m_flHalfScreenWidth);
  v25 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: *((CDmAttribute **)&v25[1] + 15), value: &v18->m_nAtlasTextureSizeX);
  v26 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: (CDmAttribute *)v26[2].__vftable, value: &v18->m_nAtlasTextureSizeY);
  v27 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v27[2].m_Id.m_Value[4], value: &v18->m_nUniqueTextureSizeX);
  v28 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v28[2].m_Id.m_Value[12], value: &v18->m_nUniqueTextureSizeY);
  v29 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: v29[2].m_Name.m_pAttribute, value: &v18->m_nCompressedAtlasSize);
  v30 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(this: *((CDmAttribute **)&v30[2].m_ref + 1), value: &v18->m_flGutterSize);
  v31 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<float>(
    this: (CDmAttribute *)v31[2].m_ref.m_attributes.m_hAttribute,
    value: &v18->m_flUVMapThreshold);
  v32 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<Vector>(this: (CDmAttribute *)v32[2].m_fileId, value: &v18->m_vWorldUnitsPerTile);
  v33 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<int>(this: *((CDmAttribute **)&v33[2] + 16), value: &v18->m_nMaxTexScaleSlots);
  v34 = g_pDataModel->GetElement(this: g_pDataModel, a2: v12[1].__vftable);
  CDmAttribute::SetValue<bool>(this: *(CDmAttribute **)v34[3].m_Id.m_Value, value: &v18->m_bWrapInAtlas);
  v35 = 0;
  nNodes = orderedNodes->m_Size;
  if ( nNodes > 0 )
  {
    do
    {
      v36 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeWorldNodeReference::m_classType.u.m_Id,
              a3: "worldnodereference",
              a4: dmFileId,
              a5: nullptr);
      v37 = g_pDataModel->GetElement(this: g_pDataModel, a2: v36);
      v38 = v37;
      if ( v37 == nullptr || !v37->IsA(this: v37, a2: CDmeWorldNodeReference::m_classType) )
        v38 = nullptr;
      g_pDataModel->GetSymbol(
        this: g_pDataModel,
        result: &value,
        a3: orderedNodes->m_Memory.m_pMemory[v35]->m_pDmeNodeName);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)v38[1].m_Id.m_Value, &value);
      v39 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pDataModel->CreateElement_2)(
              a1: g_pDataModel,
              a2: (CUtlSymbolLarge)CDmeNodeData::m_classType.u.m_Id,
              a3: "nodedata",
              a4: dmFileId,
              a5: nullptr);
      v40 = (const char *)g_pDataModel->GetElement(this: g_pDataModel, a2: v39);
      pMapName = (int)v40;
      if ( v40 != nullptr
        && (*(unsigned __int8 (__thiscall **)(const char *, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v40 + 16))(
             a1: v40,
             a2: CDmeNodeData::m_classType.u) != 0 )
      {
        v41 = (CVTFTexture *)pMapName;
      }
      else
      {
        v41 = nullptr;
      }
      if ( v41 != nullptr )
        CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: v41);
      else
        CenterVertIndex = DMELEMENT_HANDLE_INVALID;
      CDmAttribute::SetValue<enum DmElementHandle_t>(
        this: *(CDmAttribute **)&v38[1].m_Id.m_Value[12],
        value: &CenterVertIndex);
      m_nID = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader->m_nID;
      v42 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)&v38[1].m_Id.m_Value[4]);
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)v42[1].m_Id.m_Value, value: &m_nID);
      m_Flags = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader->m_Flags;
      v43 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)&v38[1].m_Id.m_Value[4]);
      CDmAttribute::SetValue<int>(this: *(CDmAttribute **)&v43[1].m_Id.m_Value[8], value: &m_Flags);
      m_pParentNode = orderedNodes->m_Memory.m_pMemory[v35]->m_pParentNode;
      if ( m_pParentNode != nullptr )
        v45 = m_pParentNode->m_pHeader->m_nID;
      else
        v45 = -1;
      v46 = *(_DWORD *)&v38[1].m_Id.m_Value[4];
      v76 = v45;
      v47 = g_pDataModel->GetElement(this: g_pDataModel, a2: v46);
      CDmAttribute::SetValue<int>(this: (CDmAttribute *)v47[1].m_Name.m_Storage.u.m_Id, value: &v76);
      m_pHeader = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader;
      v68 = *(_QWORD *)&m_pHeader->m_Origin.m_vTile.x;
      v69[0] = *(_QWORD *)&m_pHeader->m_Origin.m_vTile.z;
      v49 = *(_QWORD *)&m_pHeader->m_Origin.m_vLocal.y;
      v50 = *(_DWORD *)&v38[1].m_Id.m_Value[4];
      v69[1] = v49;
      v51 = g_pDataModel->GetElement(this: g_pDataModel, a2: v50);
      CDmAttribute::SetValue<Vector>(
        this: *((CDmAttribute **)&v51[1].m_ref + 2),
        value: (const Vector *)((char *)v69 + 4));
      v52 = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader;
      v68 = *(_QWORD *)&v52->m_Bounds.m_vMinBounds.x;
      v69[0] = *(_QWORD *)&v52->m_Bounds.m_vMinBounds.z;
      v53 = *(_QWORD *)&v52->m_Bounds.m_vMaxBounds.y;
      v54 = *(_DWORD *)&v38[1].m_Id.m_Value[4];
      v69[1] = v53;
      v55 = g_pDataModel->GetElement(this: g_pDataModel, a2: v54);
      CDmAttribute::SetValue<Vector>(this: (CDmAttribute *)v55[1].m_Type.u.m_Id, value: (const Vector *)&v68);
      v56 = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader;
      v68 = *(_QWORD *)&v56->m_Bounds.m_vMinBounds.x;
      v69[0] = *(_QWORD *)&v56->m_Bounds.m_vMinBounds.z;
      v57 = *(_QWORD *)&v56->m_Bounds.m_vMaxBounds.y;
      v58 = *(_DWORD *)&v38[1].m_Id.m_Value[4];
      v69[1] = v57;
      v59 = g_pDataModel->GetElement(this: g_pDataModel, a2: v58);
      CDmAttribute::SetValue<Vector>(this: (CDmAttribute *)v59[2].__vftable, value: (const Vector *)((char *)v69 + 4));
      v60 = *(_DWORD *)&v38[1].m_Id.m_Value[4];
      m_flMinimumDistance = orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader->m_flMinimumDistance;
      v61 = g_pDataModel->GetElement(this: g_pDataModel, a2: v60);
      CDmAttribute::SetValue<float>(this: *(CDmAttribute **)&v61[2].m_Id.m_Value[4], value: &m_flMinimumDistance);
      GetElement = g_pDataModel->GetElement;
      params = (BVHBuilderParams_t *)orderedNodes->m_Memory.m_pMemory[v35]->m_pHeader->m_nChildren;
      v63 = (int)GetElement(this: g_pDataModel, a2: *(DmElementHandle_t *)&v38[1].m_Id.m_Value[4]);
      CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
        this: (CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int> > > > *)(v63 + 148),
        num: (int)params);
      for ( pMapName = 0; pMapName < (int)params; ++pMapName )
      {
        nChildID = orderedNodes->m_Memory.m_pMemory[v35]->m_ChildNodeArray.m_Memory.m_pMemory[pMapName]->m_pHeader->m_nID;
        v64 = g_pDataModel->GetElement(this: g_pDataModel, a2: *(_DWORD *)&v38[1].m_Id.m_Value[4]);
        CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
          this: (CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int> > > > *)&v64[2].m_Id.m_Value[8],
          i: pMapName,
          value: &nChildID);
      }
      src = CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)v38);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: (CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > > *)&v12[1].m_Id.m_Value[8],
        &src);
      ++v35;
    }
    while ( v35 < nNodes );
  }
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&orderedNodes, a3: pEntities);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: (CDmAttribute *)v12[1].m_ref.m_attributes.m_pNext,
    value: (const CUtlSymbolLarge *)&orderedNodes);
  if ( !g_pDataModel->SaveToFile(this: g_pDataModel, a2: pDmeWorldName, a3: nullptr, a4: nullptr, a5: "world", a6: v79) )
    _Warning(a1: "SaveMeshesToDMX: SaveToFile \"%s\" failed!\n", pDmeWorldName);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: *(_DWORD *)&guard.m_bOldValue);
}

//------------------------------------------------------------------------------
// Address: 0x00413200
// Name: public: void CWorldRendererBuilder::BuildEntityBuffer(struct entity_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRendererBuilder::BuildEntityBuffer(
        CWorldRendererBuilder *this,
        entity_t *pEntities,
        int nEntities)
{
  CUtlBuffer *v4; // eax
  CUtlBuffer *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  CUtlBuffer *m_pEntityBuffer; // edx

  this->m_nEntities = nEntities;
  v4 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
  if ( v4 != nullptr )
    v5 = CUtlBuffer::CUtlBuffer(this: v4, growSize: 0, initSize: 0, nFlags: 1);
  else
    v5 = nullptr;
  this->m_pEntityBuffer = v5;
  this->m_nEntityChunkSize = CWorldRendererBuilder::BuildEntityChunk(this, pOutputBuffer: v5, pEntities, nEntities) + 4;
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "Entities");
  else
    v7 = nullptr;
  m_pEntityBuffer = this->m_pEntityBuffer;
  this->m_pEntities = v7;
  if ( !KeyValues::LoadFromBuffer(
          this: v7,
          resourceName: "Entities",
          pBuffer: (const char *)m_pEntityBuffer->m_Memory.m_pMemory,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
    _Warning(a1: "Cannot create entities!\n");
}

//------------------------------------------------------------------------------
// Address: 0x004132A0
// Name: public: CWorldRendererBuilder::~CWorldRendererBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRendererBuilder::~CWorldRendererBuilder(CWorldRendererBuilder *this)
{
  CResourceDictionaryBuilder *m_pDictionaryBuilder; // ecx

  m_pDictionaryBuilder = this->m_pDictionaryBuilder;
  if ( m_pDictionaryBuilder != nullptr )
    ((void (__thiscall *)(CResourceDictionaryBuilder *, int))m_pDictionaryBuilder->dtr_CResourceDictionaryBuilder)(
      a1: m_pDictionaryBuilder,
      a2: 1);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_worldLighting.m_virtualPointLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_worldLighting.m_spotLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_worldLighting.m_hemiLights);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_worldLighting);
}

//------------------------------------------------------------------------------
// Address: 0x004132E0
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlBlockVector<CacheOptimizedTriangle> *p_OptimizedTriangleList; // ecx
  unsigned int v3; // eax
  int v4; // ecx
  __m128 v5; // xmm1

  p_OptimizedTriangleList = &this->OptimizedTriangleList;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  this->OptimizedKDTree.m_Size = 0;
  this->OptimizedKDTree.m_pElements = nullptr;
  p_OptimizedTriangleList->m_Memory.m_pMemory = nullptr;
  p_OptimizedTriangleList->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&p_OptimizedTriangleList->m_Memory + 2) = 0;
  CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>::Purge(this: (CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> *)p_OptimizedTriangleList);
  v3 = 1023;
  v4 = 1024;
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = 1023;
  do
  {
    v4 >>= 1;
    v3 = ((v3 & 0xF8000000) + 0x8000000) ^ v3 & 0x7FFFFFF;
  }
  while ( v4 > 1 );
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = v3;
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = nullptr;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = nullptr;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = nullptr;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = nullptr;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v5 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v5;
  this->BackgroundColor.z = v5;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004133E0
// Name: public: CWorldRendererBuilder::CWorldRendererBuilder(class CBVHNodeBuilder __near *)
// Source: json
//------------------------------------------------------------------------------
CWorldRendererBuilder *__thiscall CWorldRendererBuilder::CWorldRendererBuilder(
        CWorldRendererBuilder *this,
        CBVHNodeBuilder *pRootNode)
{
  CResourceDictionaryBuilder *v3; // eax

  this->m_pRootNode = pRootNode;
  this->m_worldLighting.m_pointLights.m_Memory.m_pMemory = nullptr;
  this->m_worldLighting.m_pointLights.m_Memory.m_nAllocationCount = 0;
  this->m_worldLighting.m_pointLights.m_Memory.m_nGrowSize = 0;
  this->m_worldLighting.m_pointLights.m_Size = 0;
  this->m_worldLighting.m_pointLights.m_pElements = nullptr;
  this->m_worldLighting.m_hemiLights.m_Memory.m_pMemory = nullptr;
  this->m_worldLighting.m_hemiLights.m_Memory.m_nAllocationCount = 0;
  this->m_worldLighting.m_hemiLights.m_Memory.m_nGrowSize = 0;
  this->m_worldLighting.m_hemiLights.m_Size = 0;
  this->m_worldLighting.m_hemiLights.m_pElements = nullptr;
  this->m_worldLighting.m_spotLights.m_Memory.m_pMemory = nullptr;
  this->m_worldLighting.m_spotLights.m_Memory.m_nAllocationCount = 0;
  this->m_worldLighting.m_spotLights.m_Memory.m_nGrowSize = 0;
  this->m_worldLighting.m_spotLights.m_Size = 0;
  this->m_worldLighting.m_spotLights.m_pElements = nullptr;
  this->m_worldLighting.m_virtualPointLights.m_Memory.m_pMemory = nullptr;
  this->m_worldLighting.m_virtualPointLights.m_Memory.m_nAllocationCount = 0;
  this->m_worldLighting.m_virtualPointLights.m_Memory.m_nGrowSize = 0;
  this->m_worldLighting.m_virtualPointLights.m_Size = 0;
  this->m_worldLighting.m_virtualPointLights.m_pElements = nullptr;
  v3 = (CResourceDictionaryBuilder *)MemAlloc_Alloc(nSize: 0x118u);
  if ( v3 != nullptr )
    this->m_pDictionaryBuilder = CResourceDictionaryBuilder::CResourceDictionaryBuilder(this: v3);
  else
    this->m_pDictionaryBuilder = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413460
// Name: public: int CWorldRendererBuilder::CreateTree(char const __near *,char __near *,char __near *,struct IDirect3DDevice9 __near *,struct BVHBuilderParams_t __near &,struct entity_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CBVHNodeBuilder *__userpurge CWorldRendererBuilder::CreateTree@<eax>(
        CWorldRendererBuilder *this@<ecx>,
        int a2@<ebp>,
        const char *pMapName,
        char *pTempFileName,
        char *pPageFileName,
        IDirect3DDevice9 *pd3dDevice,
        BVHBuilderParams_t *params,
        entity_t *pEntities,
        int nEntities)
{
  int v11; // edi
  _iobuf *v12; // edi
  int v13; // eax
  void *m_nGrowSize; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  void **v18; // eax
  int i; // edi
  int j; // edi
  void *v21; // eax
  _BYTE v22[12]; // [esp+14h] [ebp-ECh] BYREF
  RayTracingEnvironment kdTree; // [esp+20h] [ebp-E0h]
  CBVHNodeBuilder *m_Size; // [esp+F0h] [ebp-10h]
  _DWORD v25[2]; // [esp+F4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+100h] [ebp+0h]

  v25[0] = a2;
  v25[1] = retaddr;
  if ( CWorldRendererBuilder::InitD3DParams(
         this,
         pd3dDevice,
         Width: (IDirect3DVertexShader9 *)params->m_nAtlasTextureSizeX,
         Height: (IDirect3DSurface9 *)params->m_nAtlasTextureSizeY,
         flGutterSize: params->m_flGutterSize) == 0 )
    return nullptr;
  CWorldRendererBuilder::BuildEntityBuffer(this, pEntities: (entity_t *)&entities, nEntities: num_entities);
  if ( this->m_pRootNode->m_InstanceContainers.m_Size > 0 )
  {
    v11 = 0;
    m_Size = (CBVHNodeBuilder *)this->m_pRootNode->m_InstanceContainers.m_Size;
    do
    {
      CResourceDictionaryBuilder::AddInstanceGeometry(
        this: this->m_pDictionaryBuilder,
        pInstanceGeometry: this->m_pRootNode->m_InstanceContainers.m_Memory.m_pMemory[v11++].m_pInstanceGeometry);
      m_Size = (CBVHNodeBuilder *)((char *)m_Size - 1);
    }
    while ( m_Size != nullptr );
  }
  this->m_pRootNode->m_pHeader->m_Flags |= 0x20u;
  CBVHNodeBuilder::InitTextureData(this: this->m_pRootNode);
  CResourceDictionaryBuilder::InitTextureData(this: this->m_pDictionaryBuilder);
  CBVHNodeBuilder::CleanupMeshes(this: this->m_pRootNode);
  CBVHNodeBuilder::ExpandMeshesToMaterialFormats(this: this->m_pRootNode);
  v12 = fopen(file: pTempFileName, mode: "wb");
  V_strncpy(pDest: this->m_pDictionaryBuilder->m_pPageFile, pSrc: pPageFileName, maxLen: 64);
  RayTracingEnvironment::RayTracingEnvironment(this: (RayTracingEnvironment *)v22);
  v13 = CBVHNodeBuilder::CreateKDTree(
          this: this->m_pRootNode,
          Dictionary: this->m_pDictionaryBuilder,
          fp: v12,
          rteTree: (RayTracingEnvironment *)v22);
  _Msg(a1: "KD-tree is %d bytes\n", v13);
  CWorldLighting::CalculateLighting(
    this: &this->m_worldLighting,
    a2: (unsigned int)v25,
    pWorldBuilder: this,
    kdTree: (RayTracingEnvironment *)v22);
  CResourceDictionaryBuilder::CreateInstanceEntries(this: this->m_pDictionaryBuilder, fp: v12);
  m_Size = CBVHNodeBuilder::CreateTree(
             this: this->m_pRootNode,
             pMapName,
             d3dparams: &this->m_D3DParams,
             params,
             Dictionary: this->m_pDictionaryBuilder,
             fp: v12,
             pWorldLighting: &this->m_worldLighting,
             bAttemptSplit: true);
  fclose(stream: v12);
  m_nGrowSize = (void *)kdTree.TriangleColors.m_Memory.m_nGrowSize;
  kdTree.TriangleMaterials.m_Memory.m_pMemory = nullptr;
  if ( (int)kdTree.TriangleColors.m_pElements >= 0 )
  {
    if ( kdTree.TriangleColors.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)kdTree.TriangleColors.m_Memory.m_nGrowSize);
      m_nGrowSize = nullptr;
      kdTree.TriangleColors.m_Memory.m_nGrowSize = 0;
    }
    kdTree.TriangleColors.m_Size = 0;
  }
  kdTree.TriangleMaterials.m_Memory.m_nAllocationCount = (int)m_nGrowSize;
  if ( (int)kdTree.TriangleColors.m_pElements >= 0 )
  {
    if ( m_nGrowSize != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nGrowSize);
      kdTree.TriangleColors.m_Memory.m_nGrowSize = 0;
    }
    kdTree.TriangleColors.m_Size = 0;
  }
  v15 = (void *)kdTree.LightList.m_Memory.m_nGrowSize;
  kdTree.TriangleColors.m_Memory.m_pMemory = nullptr;
  if ( (int)kdTree.LightList.m_pElements >= 0 )
  {
    if ( kdTree.LightList.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)kdTree.LightList.m_Memory.m_nGrowSize);
      v15 = nullptr;
      kdTree.LightList.m_Memory.m_nGrowSize = 0;
    }
    kdTree.LightList.m_Size = 0;
  }
  kdTree.TriangleColors.m_Memory.m_nAllocationCount = (int)v15;
  if ( (int)kdTree.LightList.m_pElements >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      kdTree.LightList.m_Memory.m_nGrowSize = 0;
    }
    kdTree.LightList.m_Size = 0;
  }
  v16 = (void *)kdTree.TriangleIndexList.m_Memory.m_nGrowSize;
  kdTree.LightList.m_Memory.m_pMemory = nullptr;
  if ( (int)kdTree.TriangleIndexList.m_pElements >= 0 )
  {
    if ( kdTree.TriangleIndexList.m_Memory.m_nGrowSize != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)kdTree.TriangleIndexList.m_Memory.m_nGrowSize);
      v16 = nullptr;
      kdTree.TriangleIndexList.m_Memory.m_nGrowSize = 0;
    }
    kdTree.TriangleIndexList.m_Size = 0;
  }
  kdTree.LightList.m_Memory.m_nAllocationCount = (int)v16;
  if ( (int)kdTree.TriangleIndexList.m_pElements >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      kdTree.TriangleIndexList.m_Memory.m_nGrowSize = 0;
    }
    kdTree.TriangleIndexList.m_Size = 0;
  }
  v17 = *((void **)&kdTree.OptimizedTriangleList.m_Memory + 2);
  kdTree.TriangleIndexList.m_Memory.m_pMemory = nullptr;
  if ( (int)kdTree.OptimizedTriangleList.m_pElements >= 0 )
  {
    if ( *((_DWORD *)&kdTree.OptimizedTriangleList.m_Memory + 2) != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&kdTree.OptimizedTriangleList.m_Memory + 2));
      v17 = nullptr;
      *((_DWORD *)&kdTree.OptimizedTriangleList.m_Memory + 2) = 0;
    }
    kdTree.OptimizedTriangleList.m_Size = 0;
  }
  kdTree.TriangleIndexList.m_Memory.m_nAllocationCount = (int)v17;
  if ( (int)kdTree.OptimizedTriangleList.m_pElements >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      *((_DWORD *)&kdTree.OptimizedTriangleList.m_Memory + 2) = 0;
    }
    kdTree.OptimizedTriangleList.m_Size = 0;
  }
  v18 = (void **)kdTree.OptimizedKDTree.m_Memory.m_nGrowSize;
  kdTree.OptimizedTriangleList.m_Memory.m_pMemory = nullptr;
  if ( kdTree.OptimizedKDTree.m_Memory.m_nGrowSize != 0 )
  {
    for ( i = 0; i < kdTree.OptimizedKDTree.m_Size; ++i )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18[i]);
      v18 = (void **)kdTree.OptimizedKDTree.m_Memory.m_nGrowSize;
    }
    kdTree.OptimizedKDTree.m_Size = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
    v18 = nullptr;
    kdTree.OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  }
  kdTree.OptimizedTriangleList.m_Memory.m_nBlocks = 0;
  if ( v18 != nullptr )
  {
    for ( j = 0; j < kdTree.OptimizedKDTree.m_Size; ++j )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18[j]);
      v18 = (void **)kdTree.OptimizedKDTree.m_Memory.m_nGrowSize;
    }
    kdTree.OptimizedKDTree.m_Size = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
    kdTree.OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  }
  v21 = (void *)kdTree.BackgroundColor.z.m128_i32[1];
  kdTree.OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  if ( kdTree.BackgroundColor.z.m128_i32[3] >= 0 )
  {
    if ( kdTree.BackgroundColor.z.m128_i32[1] != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)kdTree.BackgroundColor.z.m128_i32[1]);
      v21 = nullptr;
      kdTree.BackgroundColor.z.m128_i32[1] = 0;
    }
    kdTree.BackgroundColor.z.m128_i32[2] = 0;
  }
  kdTree.OptimizedKDTree.m_Memory.m_nAllocationCount = (int)v21;
  if ( kdTree.BackgroundColor.z.m128_i32[3] >= 0 && v21 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004137C0
// Name: private: void CWorldRendererBuilder::OrderTreeBreadthFirst(class CUtlVector<class CBVHNodeBuilder __near *,class CUtlMemory<class CBVHNodeBuilder __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRendererBuilder::OrderTreeBreadthFirst(
        CWorldRendererBuilder *this,
        CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > *OrderedNodes)
{
  CBVHNodeBuilder **m_pMemory; // ebx
  int v3; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBVHNodeBuilder **v6; // ecx
  int v7; // eax
  CBVHNodeBuilder *m_current; // eax
  CBVHNodeBuilder **v9; // ecx
  int v10; // edi
  CBVHNodeBuilder **v11; // ebx
  CUtlQueue<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > WorkQueue; // [esp+Ch] [ebp-28h] BYREF
  int nChildren; // [esp+24h] [ebp-10h]
  CBVHNodeBuilder *v14; // [esp+28h] [ebp-Ch]
  CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > *p_m_ChildNodeArray; // [esp+2Ch] [ebp-8h]
  int c; // [esp+30h] [ebp-4h]

  c = (int)this;
  memset(&WorkQueue, 0, 20);
  CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&WorkQueue, num: 1);
  m_pMemory = WorkQueue.m_heap.m_Memory.m_pMemory;
  v3 = WorkQueue.m_heap.m_Size + 1;
  WorkQueue.m_heap.m_pElements = WorkQueue.m_heap.m_Memory.m_pMemory;
  if ( WorkQueue.m_heap.m_Size > 0 )
    _V_memmove(
      dest: WorkQueue.m_heap.m_Memory.m_pMemory + 1,
      src: WorkQueue.m_heap.m_Memory.m_pMemory,
      count: 4 * WorkQueue.m_heap.m_Size);
  for ( *m_pMemory = *(CBVHNodeBuilder **)(c + 4); v3 != 0; m_pMemory = WorkQueue.m_heap.m_Memory.m_pMemory )
  {
    --v3;
    WorkQueue.m_current = *m_pMemory;
    if ( v3 > 0 )
      _V_memmove(dest: m_pMemory, src: m_pMemory + 1, count: 4 * v3);
    m_Size = OrderedNodes->m_Size;
    m_nAllocationCount = OrderedNodes->m_Memory.m_nAllocationCount;
    WorkQueue.m_heap.m_Size = v3;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)OrderedNodes,
        num: m_Size - m_nAllocationCount + 1);
    ++OrderedNodes->m_Size;
    v6 = OrderedNodes->m_Memory.m_pMemory;
    v7 = OrderedNodes->m_Size - m_Size - 1;
    OrderedNodes->m_pElements = OrderedNodes->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_Size + 1], src: &v6[m_Size], count: 4 * v7);
    m_current = WorkQueue.m_current;
    v9 = &OrderedNodes->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = WorkQueue.m_current;
    m_current->m_pHeader->m_nID = m_Size;
    nChildren = m_current->m_pHeader->m_nChildren;
    c = 0;
    if ( nChildren > 0 )
    {
      p_m_ChildNodeArray = &m_current->m_ChildNodeArray;
      do
      {
        v14 = p_m_ChildNodeArray->m_Memory.m_pMemory[c];
        v10 = v3;
        if ( v3 + 1 > WorkQueue.m_heap.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&WorkQueue,
            num: v3 - WorkQueue.m_heap.m_Memory.m_nAllocationCount + 1);
          v3 = WorkQueue.m_heap.m_Size;
        }
        v11 = WorkQueue.m_heap.m_Memory.m_pMemory;
        WorkQueue.m_heap.m_Size = ++v3;
        WorkQueue.m_heap.m_pElements = WorkQueue.m_heap.m_Memory.m_pMemory;
        if ( v3 - v10 - 1 > 0 )
          _V_memmove(
            dest: &WorkQueue.m_heap.m_Memory.m_pMemory[v10 + 1],
            src: &WorkQueue.m_heap.m_Memory.m_pMemory[v10],
            count: 4 * (v3 - v10 - 1));
        v11[v10] = v14;
        ++c;
      }
      while ( c < nChildren );
    }
  }
  if ( WorkQueue.m_heap.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00413950
// Name: public: void CWorldRendererBuilder::GetEntities(char __near *,class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRendererBuilder::GetEntities(
        CWorldRendererBuilder *this,
        char *pEntityName,
        KeyValues *entityList)
{
  KeyValues *i; // ebx
  const char *Name; // eax
  int m_iValue; // edi
  int m_sValue; // eax
  KeyValues **v9; // ecx
  int v10; // eax
  KeyValues **v11; // eax
  KeyValues *pTraversalKey; // [esp+14h] [ebp+Ch]

  if ( -entityList->m_iValue < 0 || entityList->m_iValue == 0 )
  {
    if ( entityList->m_iValue > 0 )
      entityList->m_iValue = 0;
  }
  else
  {
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)entityList,
      elem: entityList->m_iValue,
      num: -entityList->m_iValue);
  }
  for ( pTraversalKey = KeyValues::GetFirstTrueSubKey(this: this->m_pEntities);
        pTraversalKey != nullptr;
        pTraversalKey = KeyValues::GetNextTrueSubKey(this: pTraversalKey) )
  {
    for ( i = KeyValues::GetFirstTrueSubKey(this: pTraversalKey); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: pEntityName, s2: Name) == 0 )
      {
        m_iValue = entityList->m_iValue;
        m_sValue = (int)entityList->m_sValue;
        if ( m_iValue + 1 > m_sValue )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)entityList,
            num: m_iValue - m_sValue + 1);
        ++entityList->m_iValue;
        v9 = *(KeyValues ***)entityList;
        v10 = entityList->m_iValue - m_iValue - 1;
        *(_DWORD *)&entityList->m_iDataType = *(_DWORD *)entityList;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[m_iValue + 1], src: &v9[m_iValue], count: 4 * v10);
        v11 = (KeyValues **)(*(_DWORD *)entityList + 4 * m_iValue);
        if ( v11 != nullptr )
          *v11 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413A30
// Name: public: unsigned __int64 CWorldRendererBuilder::Serialize(char const __near *,struct IDirect3DDevice9 __near *,char __near *,char __near *,char __near *,enum TreeOrder_t,struct BVHBuilderParams_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorldRendererBuilder::Serialize(
        CWorldRendererBuilder *this,
        const char *pMapName,
        IDirect3DDevice9 *pd3dDevice,
        char *pszFileName,
        char *pszTempFile,
        char *pszPageFile,
        CBVHNodeBuilder *TreeOrder,
        BVHBuilderParams_t *params)
{
  int v8; // ebx
  CBVHNodeBuilder **m_pMemory; // edx
  int m_Size; // esi
  int v12; // eax
  _iobuf *v14; // eax
  _iobuf *v15; // ebx
  unsigned __int64 v16; // rax
  int m_nEntities; // ecx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rax
  unsigned int m_nEntityChunkSize; // eax
  unsigned __int64 v21; // rax
  __int64 v22; // rax
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rax
  int m_nAtlasTextureSizeX; // eax
  int m_nSizeBytesPerVoxel; // edx
  int m_nAtlasTextureSizeY; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float m_flMinSimplifiedDist; // xmm3_4
  int m_nUniqueTextureSizeY; // eax
  int m_nUniqueTextureSizeX; // edx
  float m_flHalfScreenWidth; // xmm3_4
  int m_nCompressedAtlasSize; // ecx
  int m_nMaxTexScaleSlots; // edx
  float m_flGutterSize; // xmm3_4
  float m_flUVMapThreshold; // xmm3_4
  unsigned int v39; // eax
  unsigned int m_nEntityChunkSize_high; // ecx
  unsigned int v41; // esi
  unsigned __int64 v42; // kr10_8
  BVHChunkDescriptor_t entityChunk; // [esp+Ch] [ebp-F4h] BYREF
  BVHChunkDescriptor_t hierChunk; // [esp+24h] [ebp-DCh] BYREF
  BVHChunkDescriptor_t dictChunk; // [esp+3Ch] [ebp-C4h] BYREF
  WorldFileHeader_t FileHeader; // [esp+54h] [ebp-ACh] BYREF
  HierarchyChunkHeader_t hierHeader; // [esp+B4h] [ebp-4Ch] BYREF
  EntityChunkHeader_t entityHeader; // [esp+C0h] [ebp-40h] BYREF
  unsigned __int64 nNodeStart; // [esp+C4h] [ebp-3Ch]
  unsigned __int64 nDictionaryBytes; // [esp+CCh] [ebp-34h]
  unsigned __int64 nEntityStart; // [esp+D4h] [ebp-2Ch]
  CUtlVector<CBVHNodeBuilder *,CUtlMemory<CBVHNodeBuilder *,int> > OrderedNodes; // [esp+DCh] [ebp-24h] BYREF
  unsigned __int64 nNodeBytes; // [esp+F0h] [ebp-10h]
  unsigned __int64 nMaxNodeSize; // [esp+F8h] [ebp-8h]
  int n; // [esp+110h] [ebp+10h]
  int na; // [esp+110h] [ebp+10h]
  CBVHNodeBuilder *pNode; // [esp+11Ch] [ebp+1Ch]
  CBVHNodeBuilder *pNodea; // [esp+11Ch] [ebp+1Ch]

  v8 = 0;
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&OrderedNodes, 0, sizeof(OrderedNodes));
  if ( TreeOrder == (CBVHNodeBuilder *)1 )
  {
    CWorldRendererBuilder::OrderTreeBreadthFirst(this, &OrderedNodes);
    m_Size = OrderedNodes.m_Size;
    m_pMemory = OrderedNodes.m_Memory.m_pMemory;
  }
  if ( this->m_worldLighting.m_bCanSeeSky )
  {
    v12 = 0;
    if ( m_Size > 0 )
    {
      do
        m_pMemory[v12++]->m_pHeader->m_Flags |= 0x40u;
      while ( v12 < m_Size );
      v8 = 0;
    }
  }
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      CBVHNodeBuilder::SaveToDmeWorldNode(this: m_pMemory[v8++], pMapName);
      if ( v8 >= m_Size )
        break;
      m_pMemory = OrderedNodes.m_Memory.m_pMemory;
    }
  }
  if ( CWorldRendererBuilder::ReorderResourceFile(
         this,
         pszInputFile: pszTempFile,
         pszOutputFile: pszPageFile,
         &OrderedNodes) == 0 )
  {
    _Error(a1: "Cannot reorder resource file!\n");
LABEL_13:
    if ( OrderedNodes.m_Memory.m_nGrowSize >= 0 && OrderedNodes.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: OrderedNodes.m_Memory.m_pMemory);
    return 0;
  }
  v14 = fopen(file: pszFileName, mode: "wb");
  v15 = v14;
  if ( v14 == nullptr )
  {
    _Error(a1: "Can't open %s for writing, make sure it's checked out!\n", pszFileName);
    goto LABEL_13;
  }
  SaveFileSpace(fp: v14, nSizeBytes: 0xA8u);
  v16 = CResourceDictionaryBuilder::Serialize(this: this->m_pDictionaryBuilder, fp: v15);
  m_nEntities = this->m_nEntities;
  nDictionaryBytes = v16;
  nEntityStart = v16 + 168;
  entityHeader.m_nEntities = m_nEntities;
  fwrite(buffer: &entityHeader, size: 4u, count: 1u, stream: v15);
  fwrite(buffer: this->m_pEntityBuffer->m_Memory.m_pMemory, size: this->m_pEntityBuffer->m_Put, count: 1u, stream: v15);
  nMaxNodeSize = 0;
  for ( n = 0; n < m_Size; ++n )
  {
    pNode = OrderedNodes.m_Memory.m_pMemory[n];
    LODWORD(v18) = CBVHNodeBuilder::CalculateMaxAtomicResourceSize(this: pNode, Dictionary: this->m_pDictionaryBuilder);
    if ( nMaxNodeSize <= v18 )
    {
      LODWORD(v19) = CBVHNodeBuilder::CalculateMaxAtomicResourceSize(
                       this: pNode,
                       Dictionary: this->m_pDictionaryBuilder);
      nMaxNodeSize = v19;
    }
  }
  m_nEntityChunkSize = this->m_nEntityChunkSize;
  hierHeader.m_nNodes = m_Size;
  nNodeStart = nEntityStart + __PAIR64__(HIDWORD(this->m_nEntityChunkSize), m_nEntityChunkSize);
  hierHeader.m_nAvgNodeSizeBytes = params->m_nSizeBytesPerVoxel;
  v21 = 3 * hierHeader.m_nAvgNodeSizeBytes;
  if ( v21 >= nMaxNodeSize )
  {
    HIDWORD(nNodeBytes) = HIDWORD(nMaxNodeSize);
    LODWORD(v21) = nMaxNodeSize;
  }
  else
  {
    HIDWORD(nNodeBytes) = (3 * hierHeader.m_nAvgNodeSizeBytes) >> 31;
  }
  hierHeader.m_nMaxNodeSizeBytes = v21 + 4096;
  fwrite(buffer: &hierHeader, size: 0xCu, count: 1u, stream: v15);
  nNodeBytes = 12;
  for ( na = 0; na < OrderedNodes.m_Size; ++na )
  {
    pNodea = OrderedNodes.m_Memory.m_pMemory[na];
    LODWORD(v22) = CBVHNodeBuilder::Serialize(this: pNodea, fp: v15);
    nNodeBytes += v22;
    LODWORD(v23) = CBVHNodeBuilder::CalculateMaxAtomicResourceSize(this: pNodea, Dictionary: this->m_pDictionaryBuilder);
    if ( nMaxNodeSize <= v23 )
    {
      LODWORD(v24) = CBVHNodeBuilder::CalculateMaxAtomicResourceSize(
                       this: pNodea,
                       Dictionary: this->m_pDictionaryBuilder);
      nMaxNodeSize = v24;
    }
  }
  CWorldRendererBuilder::SaveToDmeWorld(
    this,
    (int)pMapName,
    params,
    orderedNodes: &OrderedNodes,
    pEntities: (const char *)this->m_pEntityBuffer->m_Memory.m_pMemory);
  _fseeki64(stream: v15, offset: 0, whence: 0);
  m_nAtlasTextureSizeX = params->m_nAtlasTextureSizeX;
  m_nSizeBytesPerVoxel = params->m_nSizeBytesPerVoxel;
  m_nAtlasTextureSizeY = params->m_nAtlasTextureSizeY;
  x = params->m_vWorldUnitsPerTile.x;
  y = params->m_vWorldUnitsPerTile.y;
  z = params->m_vWorldUnitsPerTile.z;
  FileHeader.m_BuilderParams.m_flMinDrawVolumeSize = params->m_flMinDrawVolumeSize;
  FileHeader.m_BuilderParams.m_flMinDistToCamera = params->m_flMinDistToCamera;
  FileHeader.m_BuilderParams.m_flMinAtlasDist = params->m_flMinAtlasDist;
  m_flMinSimplifiedDist = params->m_flMinSimplifiedDist;
  FileHeader.m_BuilderParams.m_nAtlasTextureSizeX = m_nAtlasTextureSizeX;
  m_nUniqueTextureSizeY = params->m_nUniqueTextureSizeY;
  FileHeader.m_BuilderParams.m_nSizeBytesPerVoxel = m_nSizeBytesPerVoxel;
  m_nUniqueTextureSizeX = params->m_nUniqueTextureSizeX;
  FileHeader.m_BuilderParams.m_flMinSimplifiedDist = m_flMinSimplifiedDist;
  FileHeader.m_BuilderParams.m_flHorzFOV = params->m_flHorzFOV;
  m_flHalfScreenWidth = params->m_flHalfScreenWidth;
  FileHeader.m_BuilderParams.m_nUniqueTextureSizeY = m_nUniqueTextureSizeY;
  LOBYTE(m_nUniqueTextureSizeY) = params->m_bWrapInAtlas;
  FileHeader.m_BuilderParams.m_nAtlasTextureSizeY = m_nAtlasTextureSizeY;
  m_nCompressedAtlasSize = params->m_nCompressedAtlasSize;
  FileHeader.m_BuilderParams.m_nUniqueTextureSizeX = m_nUniqueTextureSizeX;
  m_nMaxTexScaleSlots = params->m_nMaxTexScaleSlots;
  FileHeader.m_BuilderParams.m_flHalfScreenWidth = m_flHalfScreenWidth;
  m_flGutterSize = params->m_flGutterSize;
  FileHeader.m_BuilderParams.m_bWrapInAtlas = m_nUniqueTextureSizeY;
  FileHeader.m_BuilderParams.m_nCompressedAtlasSize = m_nCompressedAtlasSize;
  LOWORD(m_nCompressedAtlasSize) = *(_WORD *)params->m_padding;
  FileHeader.m_BuilderParams.m_nMaxTexScaleSlots = m_nMaxTexScaleSlots;
  LOBYTE(m_nMaxTexScaleSlots) = params->m_padding[2];
  FileHeader.m_BuilderParams.m_flGutterSize = m_flGutterSize;
  m_flUVMapThreshold = params->m_flUVMapThreshold;
  FileHeader.m_nFileVersion = 101;
  FileHeader.m_vWorldUnitsPerTile.x = x;
  FileHeader.m_vWorldUnitsPerTile.y = y;
  FileHeader.m_vWorldUnitsPerTile.z = z;
  FileHeader.m_nChunks = 3;
  FileHeader.m_BuilderParams.m_flUVMapThreshold = m_flUVMapThreshold;
  FileHeader.m_BuilderParams.m_vWorldUnitsPerTile.x = x;
  FileHeader.m_BuilderParams.m_vWorldUnitsPerTile.y = y;
  FileHeader.m_BuilderParams.m_vWorldUnitsPerTile.z = z;
  *(_WORD *)FileHeader.m_BuilderParams.m_padding = m_nCompressedAtlasSize;
  FileHeader.m_BuilderParams.m_padding[2] = m_nMaxTexScaleSlots;
  fwrite(buffer: &FileHeader, size: 0x60u, count: 1u, stream: v15);
  dictChunk.m_nChunkType = CHUNK_TYPE_RESOURCE_DICTIONARY;
  dictChunk.m_nOffset = 168;
  dictChunk.m_nSize = nDictionaryBytes;
  fwrite(buffer: &dictChunk, size: 0x18u, count: 1u, stream: v15);
  v39 = this->m_nEntityChunkSize;
  entityChunk.m_nOffset = nEntityStart;
  m_nEntityChunkSize_high = HIDWORD(this->m_nEntityChunkSize);
  entityChunk.m_nChunkType = CHUNK_TYPE_ENTITIES;
  entityChunk.m_nSize = __PAIR64__(m_nEntityChunkSize_high, v39);
  fwrite(buffer: &entityChunk, size: 0x18u, count: 1u, stream: v15);
  v41 = nNodeBytes;
  hierChunk.m_nOffset = nNodeStart;
  hierChunk.m_nChunkType = CHUNK_TYPE_HEIRARCHY;
  hierChunk.m_nSize = nNodeBytes;
  fwrite(buffer: &hierChunk, size: 0x18u, count: 1u, stream: v15);
  fclose(stream: v15);
  v42 = nDictionaryBytes + __PAIR64__(HIDWORD(nNodeBytes), v41) + this->m_nEntityChunkSize + 168;
  if ( OrderedNodes.m_Memory.m_nGrowSize >= 0 && OrderedNodes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: OrderedNodes.m_Memory.m_pMemory);
  return v42;
}
