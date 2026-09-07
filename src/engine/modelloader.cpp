// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/modelloader.cpp
// Functions: 144
// ============================================================

#include "engine\modelloader.h"

//------------------------------------------------------------------------------
// Address: 0x100E7B00
// Name: void NotifyHunkBeginMapLoad(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyHunkBeginMapLoad(const char *pszMapName)
{
  int v1; // esi

  v1 = 0;
  while ( EstimatedHunkSizes[v1].pszMapRoot != nullptr
       && V_stristr(pStr: pszMapName, pSearch: EstimatedHunkSizes[v1].pszMapRoot) == nullptr )
  {
    if ( ++v1 != 0 )
      return;
  }
  Hunk_OnMapStart(nEstimatedBytes: *(&nEstimatedBytes + 2 * v1));
}

//------------------------------------------------------------------------------
// Address: 0x100E7B50
// Name: char __near * GetMapPathNameOnDisk(char __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetMapPathNameOnDisk(char *pDiskName, char *pFullMapName, unsigned int nDiskNameSize)
{
  if ( pFullMapName != pDiskName )
    V_strncpy(pDest: pDiskName, pSrc: pFullMapName, maxLen: nDiskNameSize);
  return pDiskName;
}

//------------------------------------------------------------------------------
// Address: 0x100E7B80
// Name: public: static void CMapLoadHelper::Init(struct model_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapLoadHelper::Init(
        int a1@<ebx>,
        int a2@<edi>,
        lumpfileheader_t *p_lumpHeader@<esi>,
        model_t *pMapModel,
        char *pPathName)
{
  void *v6; // eax
  int i; // edi
  int v8; // eax
  void *v9; // esi
  int lumpID; // ecx
  void *file; // eax
  int lumpOffset; // edx
  int v13; // eax
  int lumpLength; // edx
  int mapRevision; // ecx
  char szNameOnDisk[260]; // [esp+0h] [ebp-21Ch] BYREF
  char lumpfilename[260]; // [esp+104h] [ebp-118h] BYREF
  lumpfileheader_t lumpHeader; // [esp+208h] [ebp-14h] BYREF

  if ( ++s_nMapLoadRecursion <= 1 )
  {
    s_pMap = nullptr;
    s_MapFileHandle = nullptr;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    if ( pMapModel != nullptr )
      pPathName = pMapModel->szPathName;
    V_strncpy(pDest: s_szMapPathName, pSrc: pPathName, maxLen: 260);
    V_strncpy(pDest: szNameOnDisk, pSrc: s_szMapPathName, maxLen: 260);
    v6 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: szNameOnDisk, a3: "rb", a4: 0, a5: 0, a6: 0);
    s_MapFileHandle = v6;
    if ( v6 != nullptr )
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &s_MapHeader, a3: 1036, a4: v6);
      if ( s_MapHeader.ident == 1347633750 )
      {
        if ( (unsigned int)(s_MapHeader.m_nVersion - 19) > 2 )
        {
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
          s_MapFileHandle = nullptr;
          Host_Error(
            error: "CMapLoadHelper::Init, map %s has wrong version (%i when expecting %i)\n",
            szNameOnDisk,
            s_MapHeader.m_nVersion,
            21);
        }
        else
        {
          if ( g_ServerGlobalVariables.mapversion == 0 )
            g_ServerGlobalVariables.mapversion = s_MapHeader.mapRevision;
          InitDLightGlobals(nMapVersion: s_MapHeader.m_nVersion);
          s_pMap = &g_ModelLoader.m_worldBrushData;
          for ( i = 0; i < 128; ++i )
          {
            GenerateLumpFileName(bspfilename: s_szMapPathName, lumpfilename, iBufferSize: 260, iIndex: i);
            if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: lumpfilename, a3: nullptr) )
              break;
            v8 = ((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, lumpfileheader_t *, int, int))g_pFileSystem->Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: lumpfilename,
                   a3: "rb",
                   a4: 0,
                   a5: p_lumpHeader,
                   a6: a2,
                   a7: a1);
            v9 = (void *)v8;
            if ( v8 == 0 )
            {
              Host_Error(error: "CMapLoadHelper::Init, failed to load lump file %s\n", lumpfilename);
              return;
            }
            a1 = v8;
            memset(&lumpHeader, 0, sizeof(lumpHeader));
            a2 = 20;
            p_lumpHeader = &lumpHeader;
            ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Read)(a1: &g_pFileSystem->IBaseFileSystem);
            lumpID = lumpHeader.lumpID;
            if ( lumpHeader.lumpID > 0x3Fu )
            {
              _Warning(a1: "Found invalid lump file '%s'. Lump Id: %d\n", lumpfilename, lumpHeader.lumpID);
            }
            else
            {
              file = s_MapLumpFiles[lumpHeader.lumpID].file;
              if ( file != nullptr )
              {
                g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
                lumpID = lumpHeader.lumpID;
              }
              lumpOffset = lumpHeader.lumpOffset;
              v13 = lumpID;
              s_MapLumpFiles[v13].file = v9;
              s_MapLumpFiles[v13].lumpfileindex = i;
              s_MapLumpFiles[v13].header.lumpOffset = lumpOffset;
              lumpLength = lumpHeader.lumpLength;
              s_MapLumpFiles[v13].header.lumpID = lumpID;
              s_MapLumpFiles[v13].header.lumpVersion = lumpHeader.lumpVersion;
              mapRevision = lumpHeader.mapRevision;
              s_MapLumpFiles[v13].header.lumpLength = lumpLength;
              s_MapLumpFiles[v13].header.mapRevision = mapRevision;
            }
          }
        }
      }
      else
      {
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
        s_MapFileHandle = nullptr;
        Host_Error(error: "CMapLoadHelper::Init, map %s has wrong identifier\n", szNameOnDisk);
      }
    }
    else if ( !g_bClearingClientState )
    {
      Host_Error(error: "CMapLoadHelper::Init, unable to open %s\n", szNameOnDisk);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7E80
// Name: public: static void CMapLoadHelper::InitFromMemory(struct model_t __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapLoadHelper::InitFromMemory(model_t *pMapModel, void *pData, int nDataSize)
{
  char szNameOnDisk[260]; // [esp+0h] [ebp-104h] BYREF

  if ( ++s_nMapLoadRecursion <= 1 )
  {
    s_pMap = nullptr;
    s_MapFileHandle = nullptr;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    V_strncpy(pDest: s_szMapPathName, pSrc: pMapModel->szPathName, maxLen: 260);
    V_strncpy(pDest: szNameOnDisk, pSrc: s_szMapPathName, maxLen: 260);
    CUtlBuffer::SetExternalBuffer(
      this: &s_MapBuffer,
      pMemory: pData,
      nSize: nDataSize,
      nInitialPut: nDataSize,
      nFlags: 0);
    g_ModelLoader.m_worldBrushData.m_nBSPFileSize = nDataSize;
    _V_memcpy(dest: &s_MapHeader, src: pData, count: 1036);
    if ( s_MapHeader.ident == 1347633750 )
    {
      if ( (unsigned int)(s_MapHeader.m_nVersion - 19) > 2 )
      {
        Host_Error(
          error: "CMapLoadHelper::Init, map %s has wrong version (%i when expecting %i)\n",
          szNameOnDisk,
          s_MapHeader.m_nVersion,
          21);
      }
      else
      {
        g_ServerGlobalVariables.mapversion = s_MapHeader.mapRevision;
        InitDLightGlobals(nMapVersion: s_MapHeader.m_nVersion);
        s_pMap = &g_ModelLoader.m_worldBrushData;
      }
    }
    else
    {
      Host_Error(error: "CMapLoadHelper::Init, map %s has wrong identifier\n", szNameOnDisk);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7FA0
// Name: public: void CMapLoadHelper::LoadLumpElement(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::LoadLumpElement(CMapLoadHelper *this, int nElemIndex, int nElemSize, void *pData)
{
  if ( nElemSize != 0 && this->m_nLumpSize != 0 && nElemSize * (nElemIndex + 1) <= this->m_nLumpSize )
    _V_memcpy(dest: pData, src: &this->m_pData[nElemSize * nElemIndex], count: nElemSize);
}

//------------------------------------------------------------------------------
// Address: 0x100E7FE0
// Name: public: void CMapLoadHelper::LoadLumpData(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::LoadLumpData(CMapLoadHelper *this, int offset, int size, void *pData)
{
  if ( size != 0 && this->m_nLumpSize != 0 && offset + size <= this->m_nLumpSize )
    _V_memcpy(dest: pData, src: &this->m_pData[offset], count: size);
}

//------------------------------------------------------------------------------
// Address: 0x100E8020
// Name: public: CMapLoadHelper::~CMapLoadHelper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::~CMapLoadHelper(CMapLoadHelper *this)
{
  unsigned __int8 *m_pRawData; // eax

  m_pRawData = this->m_pRawData;
  if ( m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100E8040
// Name: public: void CMapLoadHelper::UncompressLump(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::UncompressLump(CMapLoadHelper *this, unsigned __int8 *pExternalBuffer)
{
  unsigned __int8 *v3; // eax
  int v4; // edx
  unsigned __int8 *m_pData; // [esp-8h] [ebp-Ch]
  unsigned int m_nUncompressedLumpSize; // [esp-4h] [ebp-8h]

  if ( this->m_pUncompressedData == nullptr )
  {
    v3 = pExternalBuffer;
    if ( pExternalBuffer != nullptr )
    {
      this->m_bUncompressedDataExternal = true;
    }
    else
    {
      v3 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nUncompressedLumpSize);
      this->m_bUncompressedDataExternal = false;
    }
    m_nUncompressedLumpSize = this->m_nUncompressedLumpSize;
    m_pData = this->m_pData;
    this->m_pUncompressedData = v3;
    memcpy(dst: v3, src: m_pData, count: m_nUncompressedLumpSize);
    v4 = this->m_nUncompressedLumpSize;
    this->m_pData = this->m_pUncompressedData;
    this->m_nLumpSize = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E80A0
// Name: public: struct worldbrushdata_t __near * CMapLoadHelper::GetMap(void)
// Source: json
//------------------------------------------------------------------------------
worldbrushdata_t *__thiscall CMapLoadHelper::GetMap(CMapLoadHelper *this)
{
  return s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E80B0
// Name: public: char __near * CMapLoadHelper::GetLoadName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLoadHelper::GetLoadName(CMapLoadHelper *this)
{
  char *result; // eax

  result = this->m_szLumpFilename;
  if ( s_MapLumpFiles[this->m_nLumpID].file == nullptr )
    return s_szMapPathName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E80D0
// Name: public: char __near * CMapLoadHelper::GetDiskName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLoadHelper::GetDiskName(CMapLoadHelper *this)
{
  char *m_szLumpFilename; // eax

  m_szLumpFilename = this->m_szLumpFilename;
  if ( s_MapLumpFiles[this->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  if ( m_szLumpFilename != s_szMapPathNameOnDisk )
    V_strncpy(pDest: s_szMapPathNameOnDisk, pSrc: m_szLumpFilename, maxLen: 260);
  return s_szMapPathNameOnDisk;
}

//------------------------------------------------------------------------------
// Address: 0x100E8110
// Name: void DeallocateLightingData(struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeallocateLightingData(worldbrushdata_t *pBrushData)
{
  CMemoryStack *m_pLightingDataStack; // ecx

  if ( pBrushData != nullptr && pBrushData->lightdata != nullptr )
  {
    if ( !g_bHunkAllocLightmaps )
    {
      m_pLightingDataStack = pBrushData->m_pLightingDataStack;
      if ( m_pLightingDataStack != nullptr && CMemoryStack::GetSize(this: m_pLightingDataStack) != 0 )
        CMemoryStack::Term(this: pBrushData->m_pLightingDataStack);
      else
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBrushData->lightdata);
    }
    pBrushData->lightdata = nullptr;
    pBrushData->m_nLightingDataSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8180
// Name: void Mod_SetParent(struct mnode_t __near *,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_SetParent(mnode_t *node, mnode_t *parent)
{
  mnode_t *v2; // esi
  bool v3; // sf
  mnode_t *v4; // eax

  v2 = node;
  v3 = node->contents < 0;
  node->parent = parent;
  if ( v3 )
  {
    do
    {
      Mod_SetParent(node: v2->children[0], parent: v2);
      v4 = v2;
      v2 = v2->children[1];
      v2->parent = v4;
    }
    while ( v2->contents < 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E81B0
// Name: MarkSmallNode
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkSmallNode(mnode_t *node)
{
  mnode_t *i; // esi
  mnode_t *v2; // [esp-4h] [ebp-8h]

  for ( i = node; i->contents < 0; i = i->children[1] )
  {
    v2 = i->children[0];
    i->contents = -2;
    MarkSmallNode(node: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E81E0
// Name: CheckSmallVolumeDifferences
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckSmallVolumeDifferences(mnode_t *pNode, const Vector *parentSize)
{
  mnode_t *i; // esi
  mnode_t *v3; // [esp-Ch] [ebp-10h]

  for ( i = pNode; i->contents < 0; i = i->children[1] )
  {
    if ( (float)(parentSize->x - i->m_vecHalfDiagonal.x) >= 5.0 )
      break;
    if ( (float)(parentSize->y - i->m_vecHalfDiagonal.y) >= 5.0 )
      break;
    if ( (float)(parentSize->z - i->m_vecHalfDiagonal.z) >= 5.0 )
      break;
    v3 = i->children[0];
    i->contents = -3;
    CheckSmallVolumeDifferences(pNode: v3, parentSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8250
// Name: void Mod_LoadLeafs_Version_0(class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs_Version_0(int lh)
{
  signed int v1; // esi
  char *v2; // eax
  const char *v3; // eax
  mleaf_t *v4; // ebx
  worldbrushdata_t *v5; // eax
  worldbrushdata_t *v6; // edi
  dleafambientindex_t *m_pLeafAmbient; // ecx
  int v8; // eax
  float *p_y; // esi
  __int16 *v10; // edi
  unsigned __int8 *v11; // ebx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  int v15; // edx
  float v16; // xmm7_4
  int count; // [esp+Ch] [ebp-Ch]
  dleafambientindex_t *pTable; // [esp+10h] [ebp-8h]
  unsigned __int8 *in; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  in = *(unsigned __int8 **)(lh + 16);
  if ( *(_DWORD *)lh % 0x38u != 0 )
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
  v1 = *(_DWORD *)lh / 0x38u;
  count = v1;
  v2 = (char *)(lh + 36);
  if ( s_MapLumpFiles[*(_DWORD *)(lh + 32)].file == nullptr )
    v2 = s_szMapPathName;
  v3 = va(format: "%s [%s]", v2, "leafs");
  v4 = (mleaf_t *)Hunk_AllocName(size: v1 << 6, name: v3, bClear: true);
  v5 = s_pMap;
  s_pMap->leafs = v4;
  v5->numleafs = v1;
  v5->m_pLeafAmbient = (dleafambientindex_t *)Hunk_AllocName(size: 4 * v1, name: "LeafAmbient", bClear: true);
  v6 = s_pMap;
  v6->m_pAmbientSamples = (dleafambientlighting_t *)Hunk_AllocName(
                                                      size: 28 * v1,
                                                      name: "LeafAmbientSamples",
                                                      bClear: true);
  m_pLeafAmbient = s_pMap->m_pLeafAmbient;
  v8 = 0;
  pTable = m_pLeafAmbient;
  i = 0;
  if ( v1 > 0 )
  {
    p_y = &v4->m_vecCenter.y;
    v10 = (__int16 *)(in + 14);
    v11 = &s_pMap->m_pAmbientSamples->y;
    while ( 1 )
    {
      v12 = (float)*v10;
      v13 = (float)v10[1];
      v14 = (float)*(v10 - 1);
      v15 = v10[2];
      v16 = v12 + (float)*(v10 - 3);
      *p_y = v13 + (float)*(v10 - 2);
      p_y[1] = (float)v15 + v14;
      *(p_y - 1) = v16 * 0.5;
      *p_y = *p_y * 0.5;
      p_y[1] = p_y[1] * 0.5;
      p_y[3] = v12 - *(p_y - 1);
      p_y[4] = v13 - *p_y;
      p_y[5] = (float)v15 - p_y[1];
      m_pLeafAmbient[v8].firstAmbientSample = v8;
      m_pLeafAmbient[v8].ambientSampleCount = 1;
      *(_WORD *)v11 = -32640;
      *(v11 - 1) = 0x80;
      v11[2] = 0;
      _V_memcpy(dest: v11 - 25, src: v10 + 8, count: 24);
      *(p_y - 5) = *(float *)(v10 - 7);
      *((_WORD *)p_y + 14) = *(v10 - 5);
      *((_WORD *)p_y - 4) = (__int16)(*(v10 - 4) << 7) >> 7;
      *((_WORD *)p_y - 3) = *(v10 - 4) >> 9;
      *((_WORD *)p_y + 16) = v10[3];
      *((_WORD *)p_y + 17) = v10[4];
      *(p_y - 3) = 0.0;
      *((_WORD *)p_y + 21) = 0;
      *((_WORD *)p_y + 15) = v10[7];
      v11 += 28;
      v10 += 28;
      ++i;
      p_y += 16;
      if ( i >= count )
        break;
      v8 = i;
      m_pLeafAmbient = pTable;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E84C0
// Name: void Mod_LoadLeafs_Version_1(class CMapLoadHelper __near &,class CMapLoadHelper __near &,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs_Version_1(
        CMapLoadHelper *lh,
        CompressedLightCube *ambientLightingLump,
        CMapLoadHelper *ambientLightingTable)
{
  CMapLoadHelper *v3; // esi
  bool v4; // zf
  int v5; // ebx
  const char *m_szLumpFilename; // eax
  const char *v7; // eax
  mleaf_t *v8; // eax
  CompressedLightCube *v9; // edi
  mleaf_t *v10; // ecx
  worldbrushdata_t *v11; // eax
  CMapLoadHelper *v12; // esi
  int m_nLumpSize; // ecx
  void *v14; // eax
  CMapLoadHelper *v15; // edx
  void *v16; // eax
  worldbrushdata_t *v17; // edi
  dleafambientlighting_t *m_pAmbientSamples; // esi
  int v19; // edi
  unsigned __int8 *p_y; // esi
  dleafambientlighting_t *v21; // eax
  dleafambientindex_t *v22; // ecx
  __int16 *maxs; // ecx
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  int v28; // esi
  float v29; // xmm7_4
  int v30; // [esp-1Ch] [ebp-44h]
  Vector gray; // [esp+8h] [ebp-20h] BYREF
  mleaf_t *out; // [esp+14h] [ebp-14h]
  dleaf_t *in; // [esp+18h] [ebp-10h]
  dleafambientindex_t *pTable; // [esp+1Ch] [ebp-Ch]
  dleafambientlighting_t *pSamples; // [esp+20h] [ebp-8h]
  void *src; // [esp+24h] [ebp-4h]

  v3 = lh;
  v4 = (lh->m_nLumpSize & 0x1F) == 0;
  in = (dleaf_t *)lh->m_pData;
  if ( !v4 )
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
  v5 = (unsigned int)v3->m_nLumpSize >> 5;
  m_szLumpFilename = v3->m_szLumpFilename;
  if ( s_MapLumpFiles[v3->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v7 = va(format: "%s [%s]", m_szLumpFilename, "leafs");
  v8 = (mleaf_t *)Hunk_AllocName(size: v5 << 6, name: v7, bClear: true);
  v9 = ambientLightingLump;
  v10 = v8;
  v11 = s_pMap;
  s_pMap->leafs = v10;
  v11->numleafs = v5;
  v4 = *(_DWORD *)&v9->m_Color[2] == 1;
  out = v10;
  if ( v4
    && (v12 = ambientLightingTable,
        m_nLumpSize = ambientLightingTable->m_nLumpSize,
        ambientLightingTable->m_nLumpSize != 0) )
  {
    lh = (CMapLoadHelper *)v11;
    v14 = Hunk_AllocName(size: m_nLumpSize, name: "LeafAmbient", bClear: true);
    v15 = (CMapLoadHelper *)s_pMap;
    *(_DWORD *)&lh->m_szLumpFilename[208] = v14;
    v30 = (int)v9->m_Color[0];
    lh = v15;
    v16 = Hunk_AllocName(size: v30, name: "LeafAmbientSamples", bClear: true);
    *(_DWORD *)&lh->m_szLumpFilename[212] = v16;
    _V_memcpy(dest: s_pMap->m_pLeafAmbient, src: v12->m_pData, count: v12->m_nLumpSize);
    _V_memcpy(dest: s_pMap->m_pAmbientSamples, src: *(const void **)&v9->m_Color[4], count: *(_DWORD *)v9->m_Color);
  }
  else
  {
    v4 = *(_DWORD *)v9->m_Color == 0;
    ambientLightingLump = nullptr;
    if ( !v4 )
      ambientLightingLump = (CompressedLightCube *)v9->m_Color[4];
    v11->m_pLeafAmbient = (dleafambientindex_t *)Hunk_AllocName(size: 4 * v5, name: "LeafAmbient", bClear: true);
    v17 = s_pMap;
    v17->m_pAmbientSamples = (dleafambientlighting_t *)Hunk_AllocName(
                                                         size: 28 * v5,
                                                         name: "LeafAmbientSamples",
                                                         bClear: true);
    m_pAmbientSamples = s_pMap->m_pAmbientSamples;
    pTable = s_pMap->m_pLeafAmbient;
    pSamples = m_pAmbientSamples;
    gray.x = 0.5;
    gray.y = 0.5;
    gray.z = 0.5;
    VectorToColorRGBExp32(vin: &gray, c: (ColorRGBExp32 *)&lh);
    v19 = 0;
    if ( v5 > 0 )
    {
      p_y = &m_pAmbientSamples->y;
      v21 = (dleafambientlighting_t *)&pSamples->cube.m_Color[2];
      src = ambientLightingLump;
      pSamples = (dleafambientlighting_t *)((char *)pSamples + 8);
      do
      {
        v4 = ambientLightingLump == nullptr;
        v22 = pTable;
        pTable[v19].ambientSampleCount = 1;
        v22[v19].firstAmbientSample = v19;
        *(_WORD *)p_y = -32640;
        *(p_y - 1) = 0x80;
        p_y[2] = 0;
        if ( v4 )
        {
          v21[-1].cube.m_Color[5] = (ColorRGBExp32)lh;
          *(_DWORD *)&v21[-1].x = lh;
          v21->cube.m_Color[0] = (ColorRGBExp32)lh;
          v21->cube.m_Color[1] = (ColorRGBExp32)lh;
          v21->cube.m_Color[2] = (ColorRGBExp32)lh;
          v21->cube.m_Color[3] = (ColorRGBExp32)lh;
        }
        else
        {
          _V_memcpy(dest: p_y - 25, src, count: 24);
          v21 = pSamples;
        }
        src = (char *)src + 24;
        ++v19;
        ++v21;
        p_y += 28;
        pSamples = v21;
      }
      while ( v19 < v5 );
    }
  }
  if ( v5 > 0 )
  {
    maxs = in->maxs;
    v24 = &out->m_vecCenter.y;
    do
    {
      v25 = (float)*maxs;
      v26 = (float)maxs[1];
      v27 = (float)*(maxs - 1);
      v28 = maxs[2];
      v29 = v25 + (float)*(maxs - 3);
      *v24 = v26 + (float)*(maxs - 2);
      v24[1] = (float)v28 + v27;
      *(v24 - 1) = v29 * 0.5;
      *v24 = *v24 * 0.5;
      v24[1] = v24[1] * 0.5;
      v24[3] = v25 - *(v24 - 1);
      v24[4] = v26 - *v24;
      v24[5] = (float)v28 - v24[1];
      *(v24 - 5) = *(float *)(maxs - 7);
      *((_WORD *)v24 + 14) = *(maxs - 5);
      *((_WORD *)v24 - 4) = (__int16)(*(maxs - 4) << 7) >> 7;
      *((_WORD *)v24 - 3) = *(maxs - 4) >> 9;
      *((_WORD *)v24 + 16) = maxs[3];
      *((_WORD *)v24 + 17) = maxs[4];
      *(v24 - 3) = 0.0;
      *((_WORD *)v24 + 21) = 0;
      *((_WORD *)v24 + 15) = maxs[7];
      maxs += 16;
      v24 += 16;
      --v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8810
// Name: private: void CMDLCacheNotify::SetBoundsFromStudioHdr(struct model_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::SetBoundsFromStudioHdr(CMDLCacheNotify *this, model_t *pModel, int handle)
{
  studiohdr_t *v3; // eax
  long double v4; // st7
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  float handlea; // [esp+Ch] [ebp+Ch]
  float handleb; // [esp+Ch] [ebp+Ch]
  float handlec; // [esp+Ch] [ebp+Ch]
  float handled; // [esp+Ch] [ebp+Ch]
  float handlee; // [esp+Ch] [ebp+Ch]
  float handlef; // [esp+Ch] [ebp+Ch]

  v3 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: handle);
  pModel->mins = v3->hull_min;
  pModel->maxs = v3->hull_max;
  pModel->radius = 0.0;
  v4 = fabs(pModel->mins.x);
  if ( v4 > pModel->radius )
  {
    handlea = v4;
    pModel->radius = handlea;
  }
  v5 = fabs(pModel->maxs.x);
  if ( v5 > pModel->radius )
  {
    handleb = v5;
    pModel->radius = handleb;
  }
  v6 = fabs(pModel->mins.y);
  if ( v6 > pModel->radius )
  {
    handlec = v6;
    pModel->radius = handlec;
  }
  v7 = fabs(pModel->maxs.y);
  if ( v7 > pModel->radius )
  {
    handled = v7;
    pModel->radius = handled;
  }
  v8 = fabs(pModel->mins.z);
  if ( v8 > pModel->radius )
  {
    handlee = v8;
    pModel->radius = handlee;
  }
  v9 = fabs(pModel->maxs.z);
  if ( v9 > pModel->radius )
  {
    handlef = v9;
    pModel->radius = handlef;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8950
// Name: void ConnectMDLCacheNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectMDLCacheNotify()
{
  g_pMDLCache->SetCacheNotify(this: g_pMDLCache, a2: &s_MDLCacheNotify);
}

//------------------------------------------------------------------------------
// Address: 0x100E8970
// Name: void DisconnectMDLCacheNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectMDLCacheNotify()
{
  g_pMDLCache->SetCacheNotify(this: g_pMDLCache, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100E8980
// Name: public: virtual char const __near * CModelLoader::GetName(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModelLoader::GetName(CModelLoader *this, const model_t *pModel)
{
  if ( pModel != nullptr )
    return pModel->szPathName;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E89A0
// Name: BuildSpriteLoadName
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildSpriteLoadName(char *pName@<edi>, char *pOut, int outLen, bool *bIsAVI, bool *bIsBIK)
{
  const char *FileExtension; // esi
  bool v7; // al
  int v8; // eax
  int v9; // eax
  const char *v10; // esi
  const char *v11; // [esp+0h] [ebp-110h]
  char szBase[260]; // [esp+Ch] [ebp-104h] BYREF
  bool bIsVMT_3; // [esp+123h] [ebp+13h]

  FileExtension = V_GetFileExtension(path: v11);
  *bIsAVI = _V_stricmp(s1: FileExtension, s2: "avi") == 0;
  *bIsBIK = _V_stricmp(s1: FileExtension, s2: "bik") == 0;
  v7 = _V_stricmp(s1: FileExtension, s2: "vmt") == 0;
  bIsVMT_3 = v7;
  if ( (*bIsAVI || *bIsBIK || v7)
    && ((strchr(string: (unsigned __int8 *)pName, chr: 0x2Fu), v8 != 0)
     || (strchr(string: (unsigned __int8 *)pName, chr: 0x5Cu), v9 != 0)) )
  {
    if ( bIsVMT_3 )
    {
      v10 = pName;
      if ( V_stristr(pStr: pName, pSearch: "materials/") == pName
        || V_stristr(pStr: pName, pSearch: "materials\\") == pName )
      {
        v10 = pName + 10;
      }
      V_StripExtension(in: v10, out: pOut, outSize: outLen);
    }
    else
    {
      V_strncpy(pDest: pOut, pSrc: pName, maxLen: outLen);
    }
  }
  else
  {
    V_FileBase(in: pName, out: szBase, maxlen: 260);
    V_snprintf(pDest: pOut, maxLen: outLen, pFormat: "sprites/%s", szBase);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8AC0
// Name: public: virtual void CModelLoader::UnreferenceModel(struct model_t __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnreferenceModel(
        CModelLoader *this,
        model_t *model,
        IModelLoader::REFERENCETYPE referencetype)
{
  model->nLoadFlags &= ~referencetype;
}

//------------------------------------------------------------------------------
// Address: 0x100E8AE0
// Name: enum RenderableTranslucencyType_t Mod_ComputeTranslucencyType(struct model_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_ComputeTranslucencyType(model_t *mod, int nSkin, int nBody)
{
  int v3; // ebx
  int v5; // edi
  int v6; // esi
  IMaterial *v7; // ecx
  int flags; // eax
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-200h] BYREF

  if ( mod->type == mod_brush )
  {
    flags = mod->flags;
    if ( (flags & 2) != 0 )
      return ((flags & 8) != 0) + 1;
    return 0;
  }
  if ( mod->type == mod_sprite )
    return 1;
  if ( mod->type != mod_studio )
    return 0;
  v3 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: mod->studio);
  if ( (*(_BYTE *)(v3 + 152) & 4) != 0 )
    return 0;
  v5 = ((int (__stdcall *)(_DWORD, int, int, int, IMaterial **))g_pStudioRender->GetMaterialListFromBodyAndSkin)(
         a1: mod->studio,
         a2: nSkin,
         a3: nBody,
         a4: 128,
         a5: pMaterials);
  v6 = 0;
  if ( v5 <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = pMaterials[v6];
    if ( v7 != nullptr && v7->IsTranslucent(this: v7) )
      break;
    if ( ++v6 >= v5 )
      return 0;
  }
  return ((*(_BYTE *)(v3 + 152) & 8) != 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E8BE0
// Name: private: void CModelLoader::Map_UnloadCubemapSamples(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_UnloadCubemapSamples(CModelLoader *this, model_t *mod)
{
  worldbrushdata_t *pShared; // eax
  int v3; // esi
  int v4; // edi
  ITexture *pTexture; // ecx

  pShared = mod->brush.pShared;
  v3 = 0;
  if ( pShared->m_nCubemapSamples > 0 )
  {
    v4 = 0;
    do
    {
      pTexture = pShared->m_pCubemapSamples[v4].pTexture;
      pTexture->DecrementReferenceCount(this: pTexture);
      pShared = mod->brush.pShared;
      ++v3;
      ++v4;
    }
    while ( v3 < pShared->m_nCubemapSamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8C30
// Name: public: struct model_t __near & model_t::operator=(struct model_t const __near &)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall model_t::operator=(model_t *this, const model_t *__that)
{
  model_t *result; // eax
  char *szPathName; // esi
  int i; // edx

  result = this;
  this->fnHandle = __that->fnHandle;
  szPathName = this->szPathName;
  for ( i = 260; i != 0; --i )
  {
    *szPathName = szPathName[(char *)__that - (char *)this];
    ++szPathName;
  }
  this->nLoadFlags = __that->nLoadFlags;
  this->nServerCount = __that->nServerCount;
  this->type = __that->type;
  this->flags = __that->flags;
  this->mins = __that->mins;
  this->maxs = __that->maxs;
  this->radius = __that->radius;
  this->m_pKeyValues = __that->m_pKeyValues;
  this->___u10 = __that->___u10;
  this->sprite = __that->sprite;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E8D80
// Name: GetSpriteInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSpriteInfo(const char *pName, bool bIsAVI, bool bIsBIK, int *nWidth, int *nHeight, int *nFrameCount)
{
  IMaterial *v6; // esi
  int v7; // edi
  int v8; // ebx
  unsigned __int16 v9; // ax
  IMaterial *Material; // eax

  *nFrameCount = 1;
  v6 = nullptr;
  v7 = 0xFFFF;
  *nHeight = 1;
  *nWidth = 1;
  v8 = 0xFFFF;
  if ( bIsAVI )
  {
    v7 = avi->CreateAVIMaterial(this: avi, a2: pName, a3: pName, a4: "GAME");
    avi->GetFrameSize(this: avi, a2: v7, a3: nWidth, a4: nHeight);
    *nFrameCount = avi->GetFrameCount(this: avi, a2: v7);
    if ( (_WORD)v7 != 0xFFFF )
      v6 = avi->GetMaterial(this: avi, a2: v7);
  }
  else if ( bIsBIK )
  {
    v9 = bik->CreateMaterial(this: bik, a2: pName, a3: pName, a4: "GAME", a5: 0);
    v8 = v9;
    if ( v9 != 0xFFFF )
    {
      bik->GetFrameSize(this: bik, a2: v9, a3: nWidth, a4: nHeight);
      *nFrameCount = bik->GetFrameCount(this: bik, a2: v8);
      v6 = bik->GetMaterial(this: bik, a2: v8);
    }
  }
  else
  {
    Material = GL_LoadMaterial(pName, pTextureGroupName: "Other textures", bPrecache: false);
    v6 = Material;
    if ( Material != nullptr )
    {
      *nWidth = Material->GetMappingWidth(this: Material);
      *nHeight = v6->GetMappingHeight(this: v6);
      *nFrameCount = v6->GetNumAnimationFrames(this: v6);
    }
  }
  if ( v6 == g_materialEmpty )
    DevMsg(a1: "Missing sprite material %s\n", pName);
  if ( (_WORD)v7 != 0xFFFF )
    avi->DestroyAVIMaterial(this: avi, a2: v7);
  if ( (_WORD)v8 != 0xFFFF )
    bik->DestroyMaterial(this: bik, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100E8F10
// Name: private: void CModelLoader::Sprite_LoadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Sprite_LoadModel(CModelLoader *this, model_t *mod)
{
  model_t *v2; // esi
  void *v3; // edi
  unsigned int v4; // eax
  int nLightstyleLastComputedFrame; // esi
  char loadName[260]; // [esp+8h] [ebp-108h] BYREF
  BOOL bIsAVI; // [esp+10Ch] [ebp-4h] BYREF

  v2 = mod;
  mod->nLoadFlags |= 1u;
  v3 = nullptr;
  if ( g_ClientDLL != nullptr )
  {
    v4 = g_ClientDLL->GetSpriteSize(this: g_ClientDLL);
    if ( v4 != 0 )
      v3 = MemAlloc_Alloc(nSize: v4);
  }
  v2->brush.nLightstyleLastComputedFrame = (int)v3;
  v2->type = mod_sprite;
  v2->maxs.y = 0.0;
  v2->maxs.z = 0.0;
  v2->maxs.x = 0.0;
  v2->mins.x = 0.0;
  v2->mins.y = v2->maxs.y;
  v2->mins.z = v2->maxs.z;
  BuildSpriteLoadName(pName: v2->szPathName, pOut: loadName, outLen: 260, (bool *)&bIsAVI, bIsBIK: (bool *)&mod);
  GetSpriteInfo(
    pName: loadName,
    bIsAVI,
    bIsBIK: (bool)mod,
    nWidth: &v2->brush.firstmodelsurface,
    nHeight: &v2->brush.nummodelsurfaces,
    nFrameCount: (int *)&v2->___u10);
  if ( g_ClientDLL != nullptr )
  {
    nLightstyleLastComputedFrame = v2->brush.nLightstyleLastComputedFrame;
    if ( nLightstyleLastComputedFrame != 0 )
      ((void (__stdcall *)(int, char *))g_ClientDLL->InitSprite)(a1: nLightstyleLastComputedFrame, a2: loadName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9010
// Name: public: virtual bool CModelLoader::IsLoaded(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::IsLoaded(CModelLoader *this, const model_t *mod)
{
  return mod->nLoadFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E9030
// Name: public: virtual bool CModelLoader::LastLoadedMapHasHDRLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelLoader::LastLoadedMapHasHDRLighting(CModelLoader *this)
{
  return this->m_bMapHasHDRLighting;
}

//------------------------------------------------------------------------------
// Address: 0x100E9040
// Name: public: virtual void __near * CModelLoader::GetExtraData(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
struct CEngineSprite *__thiscall CModelLoader::GetExtraData(CModelLoader *this, model_t *model)
{
  if ( model != nullptr )
  {
    if ( model->type == mod_sprite )
    {
      if ( (model->nLoadFlags & 1) != 0 )
        return model->sprite.sprite;
    }
    else if ( model->type == mod_studio )
    {
      return (struct CEngineSprite *)((void *(__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E9090
// Name: public: virtual bool CModelLoader::Map_GetRenderInfoAllocated(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelLoader::Map_GetRenderInfoAllocated(CModelLoader *this)
{
  return this->m_bMapRenderInfoLoaded;
}

//------------------------------------------------------------------------------
// Address: 0x100E90A0
// Name: public: virtual void CModelLoader::Map_SetRenderInfoAllocated(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_SetRenderInfoAllocated(CModelLoader *this, bool allocated)
{
  this->m_bMapRenderInfoLoaded = allocated;
}

//------------------------------------------------------------------------------
// Address: 0x100E90B0
// Name: public: virtual bool CModelLoader::Map_IsValid(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelLoader::Map_IsValid(CModelLoader *this, const char *pBaseMapName, bool bQuiet)
{
  void *v3; // esi
  int v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  BSPHeader_t header; // [esp+4h] [ebp-510h] BYREF
  char mapname[260]; // [esp+410h] [ebp-104h] BYREF

  if ( pBaseMapName != nullptr && *pBaseMapName != 0 )
  {
    V_snprintf(pDest: mapname, maxLen: 260, pFormat: "maps/%s.bsp", pBaseMapName);
    v3 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: mapname, a3: "rb", a4: 0, a5: "GAME", a6: 0);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &header, a3: 1036, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      if ( header.ident == 1347633750 )
      {
        if ( (unsigned int)(header.m_nVersion - 19) <= 2 )
        {
          V_strncpy(pDest: s_szBaseMapName, pSrc: pBaseMapName, maxLen: 32);
          return 1;
        }
        if ( !bQuiet )
          _Warning(
            a1: "CModelLoader::Map_IsValid:  Map '%s' bsp version %i, expecting %i\n",
            mapname,
            header.m_nVersion,
            21);
      }
      else if ( !bQuiet )
      {
        _Warning(a1: "CModelLoader::Map_IsValid: '%s' is not a valid BSP file\n", mapname);
      }
    }
    else if ( !bQuiet )
    {
      _Warning(a1: "CModelLoader::Map_IsValid:  No such map '%s'\n", mapname);
    }
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-dumpvidmemstats", a3: 0) != 0 )
    {
      TraceType = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    return 0;
  }
  else
  {
    if ( !bQuiet )
      ConMsg(a1: "CModelLoader::Map_IsValid:  Empty mapname!!!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9240
// Name: public: enum modtype_t CModelLoader::GetTypeFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetTypeFromName(CModelLoader *this, const char *pModelName)
{
  const char *FileExtension; // eax
  const char *v3; // esi

  FileExtension = V_GetFileExtension(path: pModelName);
  v3 = FileExtension;
  if ( FileExtension != nullptr )
  {
    if ( _V_stricmp(s1: FileExtension, s2: "spr") == 0
      || _V_stricmp(s1: v3, s2: "vmt") == 0
      || _V_stricmp(s1: v3, s2: "avi") == 0
      || _V_stricmp(s1: v3, s2: "bik") == 0 )
    {
      return 2;
    }
    if ( _V_stricmp(s1: v3, s2: "bsp") == 0 )
      return 1;
    if ( _V_stricmp(s1: v3, s2: "mdl") == 0 )
      return 3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E92F0
// Name: void Mod_LeafAmbientColorAtPos(class Vector __near *,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LeafAmbientColorAtPos(Vector *pOut, const Vector *pos, int leafIndex)
{
  float v3; // xmm6_4
  int v4; // ebx
  dleafambientindex_t *m_pLeafAmbient; // ecx
  dleafambientindex_t *v6; // eax
  int firstAmbientSample; // esi
  int ambientSampleCount; // ecx
  mleaf_t *v9; // ebx
  unsigned __int8 *p_y; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float *p_z; // esi
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  bool v18; // zf
  Vector v; // [esp+0h] [ebp-20h] BYREF
  float factor; // [esp+Ch] [ebp-14h]
  float totalFactor; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-4h]
  const ColorRGBExp32 *leafIndexa; // [esp+30h] [ebp+10h]

  v3 = 0.0;
  v4 = leafIndex;
  pOut->x = 0.0;
  pOut[1].x = 0.0;
  pOut->y = 0.0;
  pOut->z = 0.0;
  pOut[1].y = 0.0;
  pOut[1].z = 0.0;
  pOut[2].x = 0.0;
  pOut[2].y = 0.0;
  pOut[2].z = 0.0;
  pOut[3].x = 0.0;
  pOut[3].y = 0.0;
  pOut[3].z = 0.0;
  pOut[4].x = 0.0;
  pOut[4].y = 0.0;
  pOut[4].z = 0.0;
  pOut[5].x = 0.0;
  pOut[5].y = 0.0;
  pOut[5].z = 0.0;
  m_pLeafAmbient = host_state.worldbrush->m_pLeafAmbient;
  v6 = &m_pLeafAmbient[leafIndex];
  if ( v6->ambientSampleCount == 0 )
  {
    firstAmbientSample = v6->firstAmbientSample;
    if ( (_WORD)firstAmbientSample != 0 )
    {
      v4 = v6->firstAmbientSample;
      v6 = &m_pLeafAmbient[firstAmbientSample];
    }
  }
  ambientSampleCount = v6->ambientSampleCount;
  if ( v6->ambientSampleCount != 0 )
  {
    v9 = &host_state.worldbrush->leafs[v4];
    p_y = &host_state.worldbrush->m_pAmbientSamples[v6->firstAmbientSample].y;
    if ( ambientSampleCount > 0 )
    {
      v24 = p_y;
      v22 = ambientSampleCount;
      while ( 1 )
      {
        v11 = (float)((float)((float)((float)*(p_y - 1) * v9->m_vecHalfDiagonal.x) * 0.0078431377)
                    + (float)(v9->m_vecCenter.x - v9->m_vecHalfDiagonal.x))
            - pos->x;
        v12 = (float)((float)((float)((float)*p_y * v9->m_vecHalfDiagonal.y) * 0.0078431377)
                    + (float)(v9->m_vecCenter.y - v9->m_vecHalfDiagonal.y))
            - pos->y;
        v13 = (float)((float)((float)((float)p_y[1] * v9->m_vecHalfDiagonal.z) * 0.0078431377)
                    + (float)(v9->m_vecCenter.z - v9->m_vecHalfDiagonal.z))
            - pos->z;
        factor = 1.0 / (float)((float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13)) + 1.0);
        totalFactor = factor + v3;
        p_z = &pOut->z;
        leafIndexa = (const ColorRGBExp32 *)(p_y - 25);
        for ( i = 6; i != 0; --i )
        {
          ColorRGBExp32ToVector(in: leafIndexa++, out: &v);
          v15 = v.z * factor;
          v16 = *(p_z - 2) + (float)(v.x * factor);
          *(p_z - 1) = *(p_z - 1) + (float)(v.y * factor);
          v17 = *p_z + v15;
          *(p_z - 2) = v16;
          *p_z = v17;
          p_z += 3;
        }
        v24 += 28;
        v18 = v22-- == 1;
        v3 = totalFactor;
        if ( v18 )
          break;
        p_y = v24;
      }
    }
    pOut->x = (float)(1.0 / v3) * pOut->x;
    pOut->y = pOut->y * (float)(1.0 / v3);
    pOut->z = pOut->z * (float)(1.0 / v3);
    pOut[1].x = (float)(1.0 / v3) * pOut[1].x;
    pOut[1].y = pOut[1].y * (float)(1.0 / v3);
    pOut[1].z = pOut[1].z * (float)(1.0 / v3);
    pOut[2].x = (float)(1.0 / v3) * pOut[2].x;
    pOut[2].y = pOut[2].y * (float)(1.0 / v3);
    pOut[2].z = pOut[2].z * (float)(1.0 / v3);
    pOut[3].x = (float)(1.0 / v3) * pOut[3].x;
    pOut[3].y = pOut[3].y * (float)(1.0 / v3);
    pOut[3].z = pOut[3].z * (float)(1.0 / v3);
    pOut[4].x = (float)(1.0 / v3) * pOut[4].x;
    pOut[4].y = pOut[4].y * (float)(1.0 / v3);
    pOut[4].z = pOut[4].z * (float)(1.0 / v3);
    pOut[5].x = (float)(1.0 / v3) * pOut[5].x;
    pOut[5].y = pOut[5].y * (float)(1.0 / v3);
    pOut[5].z = pOut[5].z * (float)(1.0 / v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9610
// Name: int ComputeSize(struct studiohwdata_t __near *,int __near *,int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeSize(studiohwdata_t *hwData, int *numVerts, int *pTriCount, bool onlyTopLod)
{
  studiohwdata_t *v4; // esi
  int m_NumLODs; // eax
  studioloddata_t *v7; // edx
  int v8; // ecx
  int *p_m_NumGroup; // eax
  _DWORD *v10; // esi
  int (__thiscall ***v11)(_DWORD); // edi
  int v12; // ecx
  int v13; // edi
  studioloddata_t *pLOD; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  studiomeshdata_t *pMeshData; // [esp+18h] [ebp-Ch]
  int k; // [esp+1Ch] [ebp-8h]
  unsigned int size; // [esp+20h] [ebp-4h]
  int *pTriCounta; // [esp+34h] [ebp+10h]
  int onlyTopLoda; // [esp+38h] [ebp+14h]

  v4 = hwData;
  size = 0;
  m_NumLODs = 1;
  if ( !onlyTopLod )
    m_NumLODs = hwData->m_NumLODs;
  *pTriCount = 0;
  if ( m_NumLODs <= 0 )
    return 0;
  pTriCounta = nullptr;
  for ( i = m_NumLODs; i != 0; --i )
  {
    v7 = (studioloddata_t *)((char *)pTriCounta + (unsigned int)v4->m_pLODs);
    v8 = 0;
    pLOD = v7;
    for ( j = 0; v8 < v4->m_NumStudioMeshes; j = v8 )
    {
      p_m_NumGroup = &v7->m_pMeshData[v8].m_NumGroup;
      pMeshData = (studiomeshdata_t *)p_m_NumGroup;
      k = 0;
      if ( *p_m_NumGroup > 0 )
      {
        onlyTopLoda = 0;
        while ( 1 )
        {
          v10 = (_DWORD *)(onlyTopLoda + p_m_NumGroup[1]);
          v11 = (int (__thiscall ***)(_DWORD))*v10;
          size += (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 104))(a1: *v10) + 2 * v10[5];
          *numVerts += (**v11)(a1: v11);
          v12 = 0;
          if ( (int)v10[1] > 0 )
          {
            v13 = 0;
            do
            {
              *pTriCount += *(_DWORD *)(v13 + v10[3]) / 3;
              ++v12;
              v13 += 35;
            }
            while ( v12 < v10[1] );
          }
          onlyTopLoda += 44;
          if ( ++k >= pMeshData->m_NumGroup )
            break;
          p_m_NumGroup = &pMeshData->m_NumGroup;
        }
        v4 = hwData;
        v8 = j;
        v7 = pLOD;
      }
      ++v8;
    }
    pTriCounta += 8;
  }
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x100E9860
// Name: public: static int CMapLoadHelper::LumpSize(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapLoadHelper::LumpSize(int lumpId)
{
  if ( s_MapLumpFiles[lumpId].file != nullptr )
    return s_MapLumpFiles[lumpId].header.lumpLength;
  else
    return s_MapHeader.lumps[lumpId].filelen;
}

//------------------------------------------------------------------------------
// Address: 0x100E9890
// Name: void EnableHDR(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall EnableHDR(int a1@<esi>, BOOL bEnable)
{
  if ( g_pMaterialSystemHardwareConfig->GetHDREnabled(this: g_pMaterialSystemHardwareConfig) != bEnable )
  {
    g_pMaterialSystemHardwareConfig->SetHDREnabled(this: g_pMaterialSystemHardwareConfig, a2: bEnable);
    materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
    ShutdownWellKnownRenderTargets(a1);
    InitWellKnownRenderTargets(a1);
    UpdateMaterialSystemConfig();
    materials->ReleaseResources(this: materials);
    materials->ReacquireResources(this: materials);
    materials->FinishRenderTargetAllocation(this: materials);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9910
// Name: void Mod_LoadWorldlights(class CMapLoadHelper __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadWorldlights(CMapLoadHelper *lh, bool bIsHDR)
{
  worldbrushdata_t *v2; // ecx
  CMapLoadHelper *v3; // ebx
  unsigned int m_nLumpSize; // edx
  int m_nLumpVersion; // eax
  char *m_szLumpFilename; // eax
  int v7; // esi
  worldbrushdata_t *v8; // edi
  const char *v9; // eax
  dworldlight_t *v10; // eax
  worldbrushdata_t *v11; // esi
  signed int v12; // esi
  char *v13; // eax
  worldbrushdata_t *v14; // edi
  const char *v15; // eax
  dworldlight_t *v16; // eax
  worldbrushdata_t *v17; // ecx
  unsigned __int8 *m_pData; // edx
  float *p_x; // edi
  float *v20; // eax
  unsigned __int8 *v21; // ecx
  int v22; // ebx
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  int v30; // ebx
  double v31; // st7
  double v32; // st7
  int v33; // ebx
  double v34; // st7
  int v35; // ebx
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  int v40; // ebx
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  int v48; // ebx
  int v49; // ebx
  int v50; // ebx
  int v51; // ebx
  int v52; // ebx
  int v53; // ebx
  int v54; // esi
  float *v55; // eax
  unsigned __int8 *v56; // ecx
  int v57; // edx
  double v58; // st7
  double v59; // st7
  int v60; // edx
  double v61; // st7
  int v62; // edx
  double v63; // st7
  int v64; // edx
  double v65; // st7
  int v66; // edx
  double v67; // st7
  int v68; // edx
  double v69; // st7
  int v70; // edi
  const char *v71; // ebx
  const char *v72; // eax
  int v73; // ebx
  int v74; // edi
  dworldlight_t *v75; // ecx
  emittype_t type; // eax
  dworldlight_t *worldlights; // ecx
  float exponent; // xmm2_4
  _DWORD *p_exponent; // ecx
  dworldlight_t *v80; // edx
  long double v81; // st7
  dworldlight_t *v82; // edx
  unsigned int v83; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = s_pMap;
  v3 = lh;
  s_pMap->shadowzbuffers = nullptr;
  m_nLumpSize = lh->m_nLumpSize;
  if ( lh->m_nLumpSize == 0 )
  {
    v2->numworldlights = 0;
    v2->worldlights = nullptr;
    return;
  }
  m_nLumpVersion = lh->m_nLumpVersion;
  if ( m_nLumpVersion != 0 )
  {
    if ( m_nLumpVersion == 1 )
    {
      v2->numworldlights = m_nLumpSize / 0x64;
      m_szLumpFilename = lh->m_szLumpFilename;
      if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
        m_szLumpFilename = s_szMapPathName;
      v7 = lh->m_nLumpSize;
      v8 = v2;
      v9 = va(format: "%s [%s]", m_szLumpFilename, "worldlights");
      v10 = (dworldlight_t *)Hunk_AllocName(size: v7, name: v9, bClear: true);
      v11 = s_pMap;
      v8->worldlights = v10;
      memcpy(dst: (unsigned __int8 *)v11->worldlights, src: lh->m_pData, count: lh->m_nLumpSize);
      goto LABEL_19;
    }
    Host_Error(error: "Invalid worldlight lump version!\n");
  }
  else
  {
    v12 = m_nLumpSize / 0x58;
    v2->numworldlights = m_nLumpSize / 0x58;
    v13 = lh->m_szLumpFilename;
    if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
      v13 = s_szMapPathName;
    v14 = v2;
    v15 = va(format: "%s [%s]", v13, "worldlights");
    v16 = (dworldlight_t *)Hunk_AllocName(size: 100 * v12, name: v15, bClear: true);
    v17 = s_pMap;
    v14->worldlights = v16;
    m_pData = lh->m_pData;
    p_x = &v17->worldlights->origin.x;
    i = 0;
    if ( v12 >= 4 )
    {
      v83 = ((unsigned int)(v12 - 4) >> 2) + 1;
      v20 = p_x + 5;
      v21 = m_pData + 20;
      i = 4 * v83;
      do
      {
        v22 = *((_DWORD *)v21 + 4);
        *p_x = *(float *)m_pData;
        *(v20 - 4) = *((float *)v21 - 4);
        *(v20 - 3) = *((float *)v21 - 3);
        *(v20 - 2) = *((float *)v21 - 2);
        *(v20 - 1) = *((float *)v21 - 1);
        *v20 = *(float *)v21;
        v20[1] = *((float *)v21 + 1);
        v20[2] = *((float *)v21 + 2);
        v20[3] = *((float *)v21 + 3);
        v20[4] = 0.0;
        v23 = *((float *)v21 + 7);
        v20[5] = 0.0;
        v20[6] = 0.0;
        v20[10] = v23;
        v24 = *((float *)v21 + 8);
        *((_DWORD *)v20 + 7) = v22;
        v20[11] = v24;
        v25 = *((float *)v21 + 9);
        v20[8] = *((float *)v21 + 5);
        v20[12] = v25;
        v26 = *((float *)v21 + 10);
        v20[9] = *((float *)v21 + 6);
        v20[13] = v26;
        v27 = *((float *)v21 + 11);
        v20[17] = *((float *)v21 + 14);
        v20[14] = v27;
        v28 = *((float *)v21 + 12);
        v20[18] = *((float *)v21 + 15);
        v20[15] = v28;
        v29 = *((float *)v21 + 13);
        v20[19] = *((float *)v21 + 16);
        v20[16] = v29;
        v30 = *((_DWORD *)v21 + 26);
        v20[20] = *((float *)v21 + 17);
        v20[21] = *((float *)v21 + 18);
        v20[22] = *((float *)v21 + 19);
        v20[23] = *((float *)v21 + 20);
        v20[24] = *((float *)v21 + 21);
        v20[25] = *((float *)v21 + 22);
        v20[26] = *((float *)v21 + 23);
        v20[27] = *((float *)v21 + 24);
        v20[28] = *((float *)v21 + 25);
        v20[29] = 0.0;
        v31 = *((float *)v21 + 29);
        v20[30] = 0.0;
        v20[31] = 0.0;
        v20[35] = v31;
        v32 = *((float *)v21 + 30);
        *((_DWORD *)v20 + 32) = v30;
        v33 = *((_DWORD *)v21 + 27);
        v20[36] = v32;
        v34 = *((float *)v21 + 31);
        *((_DWORD *)v20 + 33) = v33;
        v35 = *((_DWORD *)v21 + 28);
        v20[37] = v34;
        v36 = *((float *)v21 + 32);
        *((_DWORD *)v20 + 34) = v35;
        v20[38] = v36;
        v37 = *((float *)v21 + 33);
        v20[42] = *((float *)v21 + 36);
        v20[39] = v37;
        v38 = *((float *)v21 + 34);
        v20[43] = *((float *)v21 + 37);
        v20[40] = v38;
        v39 = *((float *)v21 + 35);
        v20[44] = *((float *)v21 + 38);
        v20[41] = v39;
        v40 = *((_DWORD *)v21 + 48);
        v20[45] = *((float *)v21 + 39);
        v20[46] = *((float *)v21 + 40);
        v20[47] = *((float *)v21 + 41);
        v20[48] = *((float *)v21 + 42);
        v20[49] = *((float *)v21 + 43);
        v20[50] = *((float *)v21 + 44);
        v20[51] = *((float *)v21 + 45);
        v20[52] = *((float *)v21 + 46);
        v20[53] = *((float *)v21 + 47);
        v20[54] = 0.0;
        v41 = *((float *)v21 + 51);
        v20[55] = 0.0;
        v20[56] = 0.0;
        v20[60] = v41;
        v42 = *((float *)v21 + 52);
        *((_DWORD *)v20 + 57) = v40;
        v20[61] = v42;
        v43 = *((float *)v21 + 53);
        v20[58] = *((float *)v21 + 49);
        v20[62] = v43;
        v44 = *((float *)v21 + 54);
        v20[59] = *((float *)v21 + 50);
        v20[63] = v44;
        v45 = *((float *)v21 + 55);
        v20[67] = *((float *)v21 + 58);
        v20[64] = v45;
        v46 = *((float *)v21 + 56);
        v20[68] = *((float *)v21 + 59);
        v20[65] = v46;
        v47 = *((float *)v21 + 57);
        v20[69] = *((float *)v21 + 60);
        v20[66] = v47;
        v20[70] = *((float *)v21 + 61);
        v20[71] = *((float *)v21 + 62);
        v20[72] = *((float *)v21 + 63);
        v20[73] = *((float *)v21 + 64);
        v20[74] = *((float *)v21 + 65);
        v20[75] = *((float *)v21 + 66);
        v20[76] = *((float *)v21 + 67);
        v20[77] = *((float *)v21 + 68);
        v20[78] = *((float *)v21 + 69);
        v20[79] = 0.0;
        v20[80] = 0.0;
        v20[81] = 0.0;
        v48 = *((_DWORD *)v21 + 70);
        v20[85] = *((float *)v21 + 73);
        *((_DWORD *)v20 + 82) = v48;
        v49 = *((_DWORD *)v21 + 71);
        v20[86] = *((float *)v21 + 74);
        *((_DWORD *)v20 + 83) = v49;
        v50 = *((_DWORD *)v21 + 72);
        v20[87] = *((float *)v21 + 75);
        *((_DWORD *)v20 + 84) = v50;
        v51 = *((_DWORD *)v21 + 80);
        v20[88] = *((float *)v21 + 76);
        *((_DWORD *)v20 + 92) = v51;
        v52 = *((_DWORD *)v21 + 81);
        v20[89] = *((float *)v21 + 77);
        *((_DWORD *)v20 + 93) = v52;
        v53 = *((_DWORD *)v21 + 82);
        v20[90] = *((float *)v21 + 78);
        *((_DWORD *)v20 + 94) = v53;
        m_pData += 352;
        v20[91] = *((float *)v21 + 79);
        v21 += 352;
        p_x += 100;
        v20 += 100;
        --v83;
      }
      while ( v83 != 0 );
      v3 = lh;
    }
    if ( i < v12 )
    {
      v54 = v12 - i;
      v55 = p_x + 5;
      v56 = m_pData + 20;
      do
      {
        v57 = *((_DWORD *)v56 + 4);
        *(v55 - 5) = *((float *)v56 - 5);
        v56 += 88;
        v55 += 25;
        --v54;
        *(v55 - 29) = *((float *)v56 - 26);
        *(v55 - 28) = *((float *)v56 - 25);
        *(v55 - 27) = *((float *)v56 - 24);
        *(v55 - 26) = *((float *)v56 - 23);
        *(v55 - 25) = *((float *)v56 - 22);
        *(v55 - 24) = *((float *)v56 - 21);
        *(v55 - 23) = *((float *)v56 - 20);
        *(v55 - 22) = *((float *)v56 - 19);
        *(v55 - 21) = 0.0;
        v58 = *((float *)v56 - 15);
        *(v55 - 20) = 0.0;
        *(v55 - 19) = 0.0;
        *(v55 - 15) = v58;
        v59 = *((float *)v56 - 14);
        *((_DWORD *)v55 - 18) = v57;
        v60 = *((_DWORD *)v56 - 17);
        *(v55 - 14) = v59;
        v61 = *((float *)v56 - 13);
        *((_DWORD *)v55 - 17) = v60;
        v62 = *((_DWORD *)v56 - 16);
        *(v55 - 13) = v61;
        v63 = *((float *)v56 - 12);
        *((_DWORD *)v55 - 16) = v62;
        v64 = *((_DWORD *)v56 - 8);
        *(v55 - 12) = v63;
        v65 = *((float *)v56 - 11);
        *((_DWORD *)v55 - 8) = v64;
        v66 = *((_DWORD *)v56 - 7);
        *(v55 - 11) = v65;
        v67 = *((float *)v56 - 10);
        *((_DWORD *)v55 - 7) = v66;
        v68 = *((_DWORD *)v56 - 6);
        *(v55 - 10) = v67;
        v69 = *((float *)v56 - 9);
        *((_DWORD *)v55 - 6) = v68;
        *(v55 - 9) = v69;
      }
      while ( v54 != 0 );
    }
  }
  v11 = s_pMap;
LABEL_19:
  if ( r_lightcache_zbuffercache.m_pParent != nullptr && r_lightcache_zbuffercache.m_pParent->m_Value.m_nValue != 0 )
  {
    v70 = 3072 * v11->numworldlights;
    if ( s_MapLumpFiles[v3->m_nLumpID].file != nullptr )
      v71 = v3->m_szLumpFilename;
    else
      v71 = s_szMapPathName;
    v72 = va(format: "%s [%s]", v71, "shadowzbuffers");
    v11->shadowzbuffers = (CCubeMap<LightShadowZBufferSample_t,8> *)Hunk_AllocName(size: v70, name: v72, bClear: true);
    v11 = s_pMap;
    memset(dst: (unsigned __int8 *)s_pMap->shadowzbuffers, value: 0, count: v70);
  }
  v73 = 0;
  if ( v11->numworldlights > 0 )
  {
    v74 = 0;
    do
    {
      v75 = &v11->worldlights[v74];
      type = v75->type;
      if ( type == emit_spotlight )
      {
        if ( v75->constant_attn == 0.0 && v75->linear_attn == 0.0 && v75->quadratic_attn == 0.0 )
          v75->quadratic_attn = 1.0;
        worldlights = v11->worldlights;
        exponent = worldlights[v74].exponent;
        p_exponent = (_DWORD *)&worldlights[v74].exponent;
        if ( exponent == 0.0 )
          *p_exponent = 1065353216;
      }
      else if ( type == emit_point && v75->constant_attn == 0.0 && v75->linear_attn == 0.0 && v75->quadratic_attn == 0.0 )
      {
        v75->quadratic_attn = 1.0;
      }
      v80 = v11->worldlights;
      if ( v80[v74].radius < 1.0 )
      {
        v81 = ComputeLightRadius(pLight: &v80[v74], bIsHDR);
        v82 = v11->worldlights;
        v11 = s_pMap;
        v82[v74].radius = v81;
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v11->numworldlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA070
// Name: CheckSurfaceLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall CheckSurfaceLighting(worldbrushdata_t *pBrushData@<eax>, float a2@<ebp>, msurface2_t *maxLight_8)
{
  char *v3; // esi
  bool v4; // zf
  int v5; // edi
  int v6; // ecx
  int i; // eax
  int v8; // ecx
  const ColorRGBExp32 *v9; // eax
  const ColorRGBExp32 *v10; // edi
  float v11; // xmm3_4
  unsigned __int8 v12; // al
  int v13; // edi
  char *v14; // esi
  char *v15; // edx
  float x; // eax
  Vector v17; // [esp+24h] [ebp-4Ch] BYREF
  Vector f; // [esp+30h] [ebp-40h] BYREF
  int v19; // [esp+3Ch] [ebp-34h]
  int v20; // [esp+40h] [ebp-30h]
  float v21; // [esp+44h] [ebp-2Ch]
  char *v22; // [esp+48h] [ebp-28h]
  int v23; // [esp+4Ch] [ebp-24h]
  unsigned __int8 v24; // [esp+50h] [ebp-20h]
  unsigned __int8 v25; // [esp+51h] [ebp-1Fh]
  int v26; // [esp+54h] [ebp-1Ch]
  int v27; // [esp+58h] [ebp-18h]
  int v28; // [esp+5Ch] [ebp-14h]
  Vector c; // [esp+60h] [ebp-10h]
  float maxLight_4; // [esp+70h] [ebp+0h]

  c.y = a2;
  c.z = maxLight_4;
  host_state.worldbrush = pBrushData;
  v3 = (char *)pBrushData->surfacelighting + (((char *)maxLight_8 - (char *)pBrushData->surfaces2) & 0xFFFFFFE0);
  v4 = *((_DWORD *)v3 + 7) == 0;
  v22 = v3;
  if ( !v4 )
  {
    v5 = (*((__int16 *)v3 + 2) + 1) * (*((__int16 *)v3 + 3) + 1);
    v28 = v5;
    if ( SurfHasBumpedLightmaps(surfID: maxLight_8) )
    {
      v28 = 4 * v5;
      v5 *= 4;
    }
    v6 = 0;
    c.x = 0.0;
    for ( i = 1; i < 4; ++i )
    {
      if ( v3[i + 24] == -1 )
        break;
      LODWORD(c.x) = i;
      v6 = i;
    }
    if ( v6 >= 1 )
    {
      v27 = v6;
      v8 = 4 * v5 * v6;
      v26 = v8;
      v19 = -4 * v5;
      while ( 1 )
      {
        v9 = (const ColorRGBExp32 *)(v8 + *((_DWORD *)v3 + 7));
        v21 = -1.0;
        memset(&f, 0, sizeof(f));
        if ( v5 > 0 )
        {
          v10 = v9;
          v23 = v28;
          do
          {
            ColorRGBExp32ToVector(in: v10, out: &v17);
            v11 = fsqrt((float)((float)(v17.y * v17.y) + (float)(v17.z * v17.z)) + (float)(v17.x * v17.x));
            if ( v11 > v21 )
            {
              f = v17;
              v21 = v11;
            }
            ++v10;
            --v23;
          }
          while ( v23 != 0 );
          v5 = v28;
        }
        v24 = LinearToScreenGamma(f: f.x);
        v25 = LinearToScreenGamma(f: f.y);
        v12 = LinearToScreenGamma(f: f.z);
        if ( v24 <= 1u && v25 <= 1u && v12 <= 1u )
        {
          if ( v27 < SLODWORD(c.x) )
          {
            v13 = 4 * v27;
            v14 = &v3[v27 + 24];
            v23 = v26;
            v20 = LODWORD(c.x) - v27;
            do
            {
              memcpy(
                dst: (unsigned __int8 *)(v23 + *((_DWORD *)v22 + 7)),
                src: (unsigned __int8 *)(v23 + *((_DWORD *)v22 + 7) + 4 * v28),
                count: 4 * v28);
              v15 = v22;
              *v14 = v14[1];
              *(_DWORD *)(*((_DWORD *)v15 + 7) - v13 - 4) = *(_DWORD *)(*((_DWORD *)v15 + 7) - v13 - 8);
              v23 += 4 * v28;
              ++v14;
              v13 += 4;
              --v20;
            }
            while ( v20 != 0 );
            v3 = v22;
            v5 = v28;
          }
          x = c.x;
          v3[LODWORD(c.x) + 24] = -1;
          LODWORD(c.x) = LODWORD(x) - 1;
        }
        v26 += v19;
        if ( --v27 == 0 )
          break;
        v8 = v26;
      }
      if ( LODWORD(c.x) == 0 )
        maxLight_8->flags &= ~0x400u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA2D0
// Name: CalcSurfaceExtents
// Source: json
//------------------------------------------------------------------------------
void __usercall CalcSurfaceExtents(msurface2_t *surfID@<edi>)
{
  float v1; // xmm4_4
  mtexinfo_t *v2; // ebx
  bool v3; // zf
  float v4; // xmm5_4
  int firstvertindex; // eax
  unsigned __int16 *vertindices; // edx
  mvertex_t *vertexes; // esi
  float y; // xmm6_4
  unsigned __int16 *v9; // edx
  msurface2_t **flags_high; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // esi
  int v17; // ecx
  float v18; // xmm0_4
  const char *v19; // eax
  int bmins[2]; // [esp+0h] [ebp-4Ch]
  int bmaxs[2]; // [esp+8h] [ebp-44h]
  float textureMins[2]; // [esp+10h] [ebp-3Ch]
  float textureMaxs[2]; // [esp+18h] [ebp-34h]
  float v24; // [esp+20h] [ebp-2Ch]
  float v25; // [esp+24h] [ebp-28h]
  float x; // [esp+28h] [ebp-24h]
  float z; // [esp+2Ch] [ebp-20h]
  int w_low; // [esp+30h] [ebp-1Ch]
  float v29; // [esp+34h] [ebp-18h]
  int y_low; // [esp+38h] [ebp-14h]
  int z_low; // [esp+3Ch] [ebp-10h]
  float w; // [esp+40h] [ebp-Ch]
  int v33; // [esp+44h] [ebp-8h]
  msurface2_t **p_surfaces2; // [esp+48h] [ebp-4h]

  v1 = 999999.0;
  v2 = &s_pMap->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v3 = HIBYTE(surfID->flags) == 0;
  v4 = 999999.0;
  textureMins[1] = 999999.0;
  textureMins[0] = 999999.0;
  textureMaxs[1] = -99999.0;
  textureMaxs[0] = -99999.0;
  if ( !v3 )
  {
    firstvertindex = surfID->firstvertindex;
    vertindices = s_pMap->vertindices;
    vertexes = s_pMap->vertexes;
    y = v2->textureVecsTexelsPerWorldUnits[0].y;
    x = v2->textureVecsTexelsPerWorldUnits[0].x;
    z = v2->textureVecsTexelsPerWorldUnits[0].z;
    w_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[0].w);
    y_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[1].y);
    v29 = v2->textureVecsTexelsPerWorldUnits[1].x;
    v9 = &vertindices[firstvertindex];
    flags_high = (msurface2_t **)HIBYTE(surfID->flags);
    z_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[1].z);
    w = v2->textureVecsTexelsPerWorldUnits[1].w;
    p_surfaces2 = flags_high;
    do
    {
      v11 = vertexes[*v9].position.y;
      v12 = vertexes[*v9].position.x;
      v13 = vertexes[*v9].position.z;
      v14 = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      if ( v4 > v14 )
        v4 = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      if ( v14 > textureMaxs[0] )
        textureMaxs[0] = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      v15 = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11)) + (float)(*(float *)&z_low * v13)) + w;
      if ( v1 > v15 )
        v1 = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11)) + (float)(*(float *)&z_low * v13))
           + w;
      if ( v15 > textureMaxs[1] )
        textureMaxs[1] = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11))
                               + (float)(*(float *)&z_low * v13))
                       + w;
      ++v9;
      p_surfaces2 = (msurface2_t **)((char *)p_surfaces2 - 1);
    }
    while ( p_surfaces2 != nullptr );
    textureMins[1] = v1;
    textureMins[0] = v4;
  }
  v16 = 0;
  LODWORD(z) = &s_pMap->surfaces1;
  p_surfaces2 = &s_pMap->surfaces2;
  LODWORD(x) = &s_pMap->surfacelighting;
  do
  {
    if ( *(_WORD *)(*(_DWORD *)LODWORD(x) + 2 * (v16 + 16 * (surfID - *p_surfaces2)) + 4) == 0
      && *(_DWORD *)(32 * (surfID - *p_surfaces2) + *(_DWORD *)LODWORD(x) + 28) == 0 )
    {
      surfID->flags |= 1u;
    }
    v25 = textureMins[v16];
    v33 = LOBYTE(w) | 0xC00;
    z_low = (int)v25;
    v17 = z_low;
    v18 = textureMaxs[v16];
    bmins[v16] = z_low;
    v24 = v18;
    y_low = LOBYTE(v29) | 0x800;
    w_low = (int)v18;
    bmaxs[v16] = w_low;
    *(_DWORD *)(*(_DWORD *)LODWORD(z) + 4 * (v16 + 4 * (surfID - *p_surfaces2))) = v17;
    *(_WORD *)(*(_DWORD *)LODWORD(z) + 2 * (v16 + 8 * (surfID - *p_surfaces2)) + 8) = LOWORD(bmaxs[v16])
                                                                                    - LOWORD(bmins[v16]);
    if ( (v2->flags & 0x400) == 0
      && *(__int16 *)(*(_DWORD *)LODWORD(x) + 2 * (v16 + 16 * (surfID - *p_surfaces2)) + 4) > ((surfID->flags & 0x800) != 0
                                                                                             ? 128
                                                                                             : 35) )
    {
      v19 = v2->material->GetName(this: v2->material);
      Sys_Error(error: "Bad surface extents on texture %s", v19);
    }
    ++v16;
  }
  while ( v16 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x100EA590
// Name: bool Mod_NeedsLightstyleUpdate(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Mod_NeedsLightstyleUpdate(model_t *pModel)
{
  int nLightstyleCount; // edx
  int v2; // eax

  nLightstyleCount = pModel->brush.nLightstyleCount;
  if ( (_WORD)nLightstyleCount == 0 )
    return 0;
  v2 = 0;
  while ( d_lightstyleframe[g_ModelLoader.m_LightStyleList.m_Memory.m_pMemory[pModel->brush.nLightstyleIndex + v2]] <= pModel->brush.nLightstyleLastComputedFrame )
  {
    if ( ++v2 >= nLightstyleCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EA5E0
// Name: int Mod_GetModelMaterials(struct model_t __near *,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GetModelMaterials(model_t *pModel, int count, IMaterial **ppMaterials)
{
  int result; // eax
  studiohdr_t *v4; // eax
  int i; // edi
  worldbrushdata_t *pShared; // edx
  int v7; // ecx
  IMaterial *material; // edx
  int v9; // ecx

  result = 0;
  if ( pModel->type == mod_brush )
  {
    for ( i = 0; i < pModel->brush.nummodelsurfaces; ++i )
    {
      pShared = pModel->brush.pShared;
      v7 = (int)&pShared->surfaces2[i + pModel->brush.firstmodelsurface];
      if ( (*(_BYTE *)v7 & 0x10) == 0 )
      {
        material = pShared->texinfo[*(unsigned __int16 *)(v7 + 22) >> 1].material;
        v9 = result - 1;
        if ( result < 1 )
          goto LABEL_11;
        while ( ppMaterials[v9] != material )
        {
          if ( --v9 < 0 )
            goto LABEL_11;
        }
        if ( v9 < 0 )
LABEL_11:
          ppMaterials[result++] = material;
        if ( result >= count )
          break;
      }
    }
  }
  else if ( pModel->type == mod_studio )
  {
    v4 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: pModel->studio);
    return g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v4, a3: count, a4: ppMaterials);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EA6A0
// Name: MarkWaterSurfaces_ProcessLeafNode
// Source: json
//------------------------------------------------------------------------------
void __usercall MarkWaterSurfaces_ProcessLeafNode(mleaf_t *pLeaf@<esi>)
{
  worldbrushdata_t *worldbrush; // eax
  int v2; // ecx
  int v3; // ebx
  msurface2_t *v4; // edi
  unsigned int flags; // eax
  int v6; // edi
  IDispInfo *v7; // eax
  msurface2_t *v8; // eax
  msurface2_t **pHandle; // [esp+8h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  v3 = pLeaf->leafWaterDataID != -1 ? 0x20000 : 0x40000;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v4 = pHandle[v2];
      flags = v4->flags;
      if ( (v4->flags & 0x10000) == 0 && (flags & 0x800) == 0 )
        v4->flags = v3 | flags;
      ++v2;
    }
    while ( v2 < pLeaf->nummarksurfaces );
    worldbrush = host_state.worldbrush;
  }
  v6 = 0;
  if ( pLeaf->dispCount != 0 )
  {
    while ( 1 )
    {
      v7 = DispInfo_IndexArray(
             hArray: (_DWORD *)worldbrush->hDispInfos,
             iElement: worldbrush->m_pDispInfoReferences[v6 + pLeaf->dispListStart]);
      v8 = v7->GetParent(this: v7);
      v8->flags |= v3;
      if ( ++v6 >= pLeaf->dispCount )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA760
// Name: void MarkWaterSurfaces_r(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkWaterSurfaces_r(mnode_t *node)
{
  mnode_t *v1; // esi
  int contents; // eax

  v1 = node;
  contents = node->contents;
  if ( node->contents != 1 )
  {
    while ( contents < 0 )
    {
      MarkWaterSurfaces_r(node: v1->children[0]);
      v1 = v1->children[1];
      contents = v1->contents;
      if ( v1->contents == 1 )
        return;
    }
    MarkWaterSurfaces_ProcessLeafNode(pLeaf: (mleaf_t *)v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA7A0
// Name: SurfFlagsToSortGroup
// Source: json
//------------------------------------------------------------------------------
int __usercall SurfFlagsToSortGroup@<eax>(msurface2_t *surfID@<edi>, int flags@<eax>)
{
  IMaterial *material; // ecx
  const char *v5; // eax
  Vector pVecCentroid; // [esp+18h] [ebp-10h] BYREF
  float v7; // [esp+24h] [ebp-4h]

  if ( (flags & 0x10000) != 0 )
    return 3;
  if ( (flags & 0x60000) == 0x60000 )
    return 2;
  if ( (flags & 0x20000) != 0 )
    return 1;
  if ( (flags & 0x40000) == 0 && ++warningcount < 10 )
  {
    Surf_ComputeCentroid(surfID, pVecCentroid: (Vector *)&pVecCentroid.y);
    material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
    v5 = (const char *)material->GetName(this: material);
    DevWarning(a1: "SurfFlagsToSortGroup:  unhandled flags (%X) (%s)!\n", flags, v5);
    DevWarning(a1: "- This implies you have a surface (usually a displacement) embedded in solid.\n");
    DevWarning(a1: "- Look near (%.1f, %.1f, %.1f)\n", pVecCentroid.y, pVecCentroid.z, v7);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EA870
// Name: bool Mod_MarkWaterSurfaces(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Mod_MarkWaterSurfaces(model_t *pModel)
{
  int v1; // ebx
  int v2; // esi
  worldbrushdata_t *pShared; // eax
  int i; // esi
  msurface2_t *surfaces2; // edi
  int flags; // eax
  msurface2_t *v7; // edi
  int v8; // eax
  model_t *pSaveModel; // [esp+Ch] [ebp-8h]
  bool bHasWaterSurfaces; // [esp+13h] [ebp-1h]

  v1 = 0;
  bHasWaterSurfaces = false;
  pSaveModel = host_state.worldmodel;
  CCommonHostState::SetWorldModel(this: &host_state, pModel);
  v2 = *(_DWORD *)(pModel->sprite.numframes + 84);
  if ( *(_DWORD *)v2 != 1 )
  {
    if ( *(int *)v2 < 0 )
    {
      MarkWaterSurfaces_r(node: *(mnode_t **)(v2 + 52));
      MarkWaterSurfaces_r(node: *(mnode_t **)(v2 + 56));
    }
    else
    {
      MarkWaterSurfaces_ProcessLeafNode(pLeaf: (mleaf_t *)v2);
    }
  }
  pShared = pModel->brush.pShared;
  for ( i = 0; i < pShared->numsurfaces; ++v1 )
  {
    surfaces2 = pShared->surfaces2;
    flags = surfaces2[v1].flags;
    v7 = &surfaces2[v1];
    v8 = SurfFlagsToSortGroup(surfID: v7, flags);
    if ( v8 == 3 )
      bHasWaterSurfaces = true;
    v7->flags |= (v8 & 3) << 22;
    pShared = pModel->brush.pShared;
    ++i;
  }
  CCommonHostState::SetWorldModel(this: &host_state, pModel: pSaveModel);
  return bHasWaterSurfaces;
}

//------------------------------------------------------------------------------
// Address: 0x100EA920
// Name: public: void CBrushBSPIterator::MarkModelSurfaces(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBSPIterator::MarkModelSurfaces(CBrushBSPIterator *this, int flags)
{
  int nummodelsurfaces; // esi
  int i; // edx
  msurface2_t *v4; // eax

  nummodelsurfaces = this->m_pBrush->brush.nummodelsurfaces;
  for ( i = 0; i < nummodelsurfaces; v4->flags = flags | v4->flags & 0xFFF9FFFF )
  {
    v4 = &this->m_pShared->surfaces2[i + this->m_pBrush->brush.firstmodelsurface];
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA970
// Name: private: void CModelLoader::Sprite_UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Sprite_UnloadModel(CModelLoader *this, model_t *mod)
{
  model_t *v2; // esi
  IMaterial *v3; // eax
  IMaterial *v4; // edi
  char loadName[263]; // [esp+8h] [ebp-108h] BYREF
  bool bIsAVI; // [esp+10Fh] [ebp-1h] BYREF

  v2 = mod;
  mod->nLoadFlags &= ~1u;
  BuildSpriteLoadName(pName: v2->szPathName, pOut: loadName, outLen: 260, &bIsAVI, bIsBIK: (bool *)&mod + 3);
  v3 = materials->FindMaterial(this: materials, a2: loadName, a3: "Other textures", a4: 1, a5: 0);
  v4 = v3;
  if ( v3 != nullptr && !v3->IsErrorMaterial(this: v3) )
    GL_UnloadMaterial(pMaterial: v4);
  if ( g_ClientDLL != nullptr && v2->brush.nLightstyleLastComputedFrame != 0 )
    ((void (__stdcall *)(int))g_ClientDLL->ShutdownSprite)(a1: v2->brush.nLightstyleLastComputedFrame);
  free(pMem: v2->sprite.sprite);
  v2->brush.nLightstyleLastComputedFrame = 0;
  v2->sprite.numframes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EAA30
// Name: private: void CModelLoader::Studio_UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Studio_UnloadModel(CModelLoader *this, model_t *pModel)
{
  int ModelMaterials; // ebx
  int i; // esi
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-200h] BYREF

  if ( (pModel->nLoadFlags & 0x20000) != 0 )
  {
    ModelMaterials = Mod_GetModelMaterials(pModel, count: 128, ppMaterials: pMaterials);
    for ( i = 0; i < ModelMaterials; ++i )
      pMaterials[i]->DecrementReferenceCount(this: pMaterials[i]);
    pModel->nLoadFlags &= ~0x20000u;
  }
  pModel->nLoadFlags &= 0xFFFEFFFE;
  ((void (__stdcall *)(_DWORD))g_pMDLCache->Release)(a1: pModel->studio);
  pModel->studio = -1;
  pModel->type = mod_bad;
}

//------------------------------------------------------------------------------
// Address: 0x100EAAD0
// Name: public: static void CMapLoadHelper::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMapLoadHelper::Shutdown()
{
  lumpfiles_t *v0; // esi

  if ( --s_nMapLoadRecursion <= 0 )
  {
    if ( s_MapFileHandle != nullptr )
    {
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
      s_MapFileHandle = nullptr;
    }
    v0 = s_MapLumpFiles;
    do
    {
      if ( v0->file != nullptr )
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0->file);
      ++v0;
    }
    while ( (int)v0 < (int)s_szMapPathNameOnDisk );
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    s_szMapPathName[0] = 0;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    s_pMap = nullptr;
    if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_MapBuffer.m_Memory.m_pMemory);
      CUtlBuffer::SetExternalBuffer(this: &s_MapBuffer, pMemory: nullptr, nSize: 0, nInitialPut: 0, nFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EABA0
// Name: public: CMapLoadHelper::CMapLoadHelper(int,bool)
// Source: json
//------------------------------------------------------------------------------
CMapLoadHelper *__thiscall CMapLoadHelper::CMapLoadHelper(
        CMapLoadHelper *this,
        unsigned int lumpToLoad,
        bool bUncompress)
{
  lump_t *v4; // eax
  void *v5; // ecx
  void *file; // ecx
  bool v8; // al
  int m_nLumpOffset; // edi
  int m_nLumpSize; // ebx
  unsigned __int8 *v11; // eax
  unsigned int nBufferAlign; // [esp+Ch] [ebp-10h] BYREF
  unsigned int nSizeAlign; // [esp+10h] [ebp-Ch] BYREF
  unsigned int nOffsetAlign; // [esp+14h] [ebp-8h] BYREF
  void *fileToUse; // [esp+18h] [ebp-4h]

  if ( lumpToLoad >= 0x40 )
    Sys_Error(error: "Can't load lump %i, range is 0 to %i!!!", lumpToLoad, 63);
  v4 = &s_MapHeader.lumps[lumpToLoad];
  this->m_nLumpSize = 0;
  this->m_nLumpOffset = -1;
  this->m_nLumpID = lumpToLoad;
  this->m_pData = nullptr;
  this->m_pRawData = nullptr;
  this->m_pUncompressedData = nullptr;
  this->m_nUncompressedLumpSize = 0;
  this->m_bUncompressedDataExternal = false;
  this->m_nLumpSize = v4->filelen;
  v5 = s_MapFileHandle;
  this->m_nLumpOffset = v4->fileofs;
  this->m_nLumpVersion = v4->version;
  fileToUse = v5;
  file = s_MapLumpFiles[lumpToLoad].file;
  if ( file != nullptr )
  {
    this->m_nLumpSize = s_MapLumpFiles[lumpToLoad].header.lumpLength;
    fileToUse = file;
    this->m_nLumpOffset = s_MapLumpFiles[lumpToLoad].header.lumpOffset;
    this->m_nLumpVersion = s_MapLumpFiles[lumpToLoad].header.lumpVersion;
    GenerateLumpFileName(
      bspfilename: s_szMapPathName,
      lumpfilename: this->m_szLumpFilename,
      iBufferSize: 260,
      iIndex: s_MapLumpFiles[lumpToLoad].lumpfileindex);
  }
  if ( this->m_nLumpSize == 0 )
    return this;
  if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
  {
    this->m_pData = &s_MapBuffer.m_Memory.m_pMemory[this->m_nLumpOffset];
    this->m_nUncompressedLumpSize = this->m_nLumpSize;
    return this;
  }
  if ( s_MapFileHandle == nullptr )
    Sys_Error(error: "Can't load map from invalid handle!!!");
  v8 = g_pFileSystem->GetOptimalIOConstraints(
         this: g_pFileSystem,
         a2: fileToUse,
         a3: &nOffsetAlign,
         a4: &nSizeAlign,
         a5: &nBufferAlign);
  if ( v8 )
    v8 = this->m_nLumpOffset % 4 == 0;
  m_nLumpOffset = this->m_nLumpOffset;
  m_nLumpSize = this->m_nLumpSize;
  if ( this->m_nLumpSize == 0 )
    m_nLumpSize = 1;
  if ( v8 )
  {
    m_nLumpOffset &= ~(nOffsetAlign - 1);
    m_nLumpSize = ~(nSizeAlign - 1) & (m_nLumpSize + this->m_nLumpOffset - m_nLumpOffset + nSizeAlign - 1);
  }
  v11 = (unsigned __int8 *)g_pFileSystem->AllocOptimalReadBuffer(
                             this: g_pFileSystem,
                             a2: fileToUse,
                             a3: m_nLumpSize,
                             a4: m_nLumpOffset);
  this->m_pRawData = v11;
  if ( v11 != nullptr )
    goto LABEL_19;
  if ( this->m_nLumpSize != 0 )
  {
    Sys_Error(error: "Can't load lump %i, allocation of %i bytes failed!!!", lumpToLoad, this->m_nLumpSize + 1);
LABEL_19:
    if ( this->m_nLumpSize != 0 )
    {
      g_pFileSystem->Seek(
        this: &g_pFileSystem->IBaseFileSystem,
        a2: fileToUse,
        a3: m_nLumpOffset,
        a4: FILESYSTEM_SEEK_HEAD);
      g_pFileSystem->ReadEx(this: g_pFileSystem, a2: this->m_pRawData, a3: m_nLumpSize, a4: m_nLumpSize, a5: fileToUse);
      this->m_pData = &this->m_pRawData[this->m_nLumpOffset - m_nLumpOffset];
    }
  }
  this->m_nUncompressedLumpSize = this->m_nLumpSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EAD90
// Name: void Map_CheckFeatureFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_CheckFeatureFlags()
{
  int lumpLength; // eax
  int v1; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  lumpLength = s_MapLumpFiles[59].header.lumpLength;
  g_bLoadedMapHasBakedPropLighting = false;
  g_bBakedPropLightingNoSeparateHDR = false;
  if ( s_MapLumpFiles[59].file == nullptr )
    lumpLength = s_MapHeader.lumps[59].filelen;
  if ( lumpLength > 0 )
  {
    CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x3Bu, bUncompress: true);
    v1 = *(_DWORD *)lh.m_pData;
    g_bLoadedMapHasBakedPropLighting = (*(_DWORD *)lh.m_pData & 3) != 0;
    g_bBakedPropLightingNoSeparateHDR = (v1 & 2) == 0;
    if ( lh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAE20
// Name: bool Map_CheckForHDR(struct model_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall Map_CheckForHDR@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        lumpfileheader_t *a3@<esi>,
        model_t *pModel,
        char *pMapPathName)
{
  int lumpLength; // eax
  int filelen; // eax
  char v7; // bl
  int v8; // eax
  BOOL bEnableHDR; // [esp+0h] [ebp-4h]

  CMapLoadHelper::Init(a1, a2, p_lumpHeader: a3, pMapModel: pModel, pPathName: pMapPathName);
  lumpLength = s_MapLumpFiles[53].header.lumpLength;
  if ( s_MapLumpFiles[53].file == nullptr )
    lumpLength = s_MapHeader.lumps[53].filelen;
  if ( lumpLength <= 0 )
    goto LABEL_8;
  filelen = s_MapLumpFiles[54].header.lumpLength;
  if ( s_MapLumpFiles[54].file == nullptr )
    filelen = s_MapHeader.lumps[54].filelen;
  if ( filelen <= 0 )
LABEL_8:
    v7 = 0;
  else
    v7 = 1;
  if ( s_MapHeader.m_nVersion >= 20 )
  {
    v8 = s_MapLumpFiles[55].header.lumpLength;
    if ( s_MapLumpFiles[55].file == nullptr )
      v8 = s_MapHeader.lumps[55].filelen;
    if ( v8 == 0 )
    {
      v7 = 0;
LABEL_18:
      LOBYTE(bEnableHDR) = 0;
      goto LABEL_19;
    }
  }
  if ( v7 == 0 )
    goto LABEL_18;
  if ( mat_hdr_level.m_pParent == nullptr )
    goto LABEL_18;
  if ( mat_hdr_level.m_pParent->m_Value.m_nValue < 2 )
    goto LABEL_18;
  LOBYTE(bEnableHDR) = 1;
  if ( g_pMaterialSystemHardwareConfig->GetHardwareHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
    goto LABEL_18;
LABEL_19:
  EnableHDR(a1: (int)a3, bEnable: bEnableHDR);
  Map_CheckFeatureFlags();
  CMapLoadHelper::Shutdown();
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100EAEE0
// Name: AllocateLightingData
// Source: json
//------------------------------------------------------------------------------
void __usercall AllocateLightingData(worldbrushdata_t *pBrushData@<edi>, unsigned int nSize)
{
  int v2; // esi
  ColorRGBExp32 *v3; // eax
  CMemoryStack *m_pLightingDataStack; // ecx
  CMemoryStack *v5; // esi
  unsigned int m_alignment; // eax
  unsigned int v7; // ecx
  int v8; // ecx
  ColorRGBExp32 *m_pNextAlloc; // eax
  unsigned __int8 *v10; // ebx
  ColorRGBExp32 *v11; // [esp+4h] [ebp-4h]

  if ( r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0
    || r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue != 0
    || r_hunkalloclightmaps.m_pParent == nullptr
    || r_hunkalloclightmaps.m_pParent->m_Value.m_nValue == 0 )
  {
    g_bHunkAllocLightmaps = false;
    if ( r_keepstyledlightmapsonly.m_pParent == nullptr
      || r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue == 0
      || r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue != 0
      || (m_pLightingDataStack = pBrushData->m_pLightingDataStack) == nullptr )
    {
      v2 = nSize;
      v3 = (ColorRGBExp32 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
      goto LABEL_22;
    }
    CMemoryStack::Term(this: m_pLightingDataStack);
    CMemoryStack::Init(
      this: pBrushData->m_pLightingDataStack,
      pszAllocOwner: "LightingData",
      maxSize: nSize,
      commitSize: 0,
      initialCommit: 0,
      alignment: 0x10u);
    v5 = pBrushData->m_pLightingDataStack;
    m_alignment = v5->m_alignment;
    v7 = nSize;
    if ( nSize <= m_alignment )
      v7 = v5->m_alignment;
    v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
    m_pNextAlloc = (ColorRGBExp32 *)v5->m_pNextAlloc;
    v10 = &v5->m_pNextAlloc[v8];
    v11 = (ColorRGBExp32 *)v5->m_pNextAlloc;
    if ( v10 > v5->m_pCommitLimit )
    {
      if ( CMemoryStack::CommitTo(this: v5, pNextAlloc: v10) == 0 )
      {
        m_pNextAlloc = nullptr;
LABEL_20:
        pBrushData->lightdata = m_pNextAlloc;
        pBrushData->m_nLightingDataSize = nSize;
        pBrushData->m_bUnloadedAllLightmaps = false;
        return;
      }
      m_pNextAlloc = v11;
    }
    v5->m_pNextAlloc = v10;
    goto LABEL_20;
  }
  v2 = nSize;
  g_bHunkAllocLightmaps = true;
  v3 = (ColorRGBExp32 *)Hunk_AllocName(size: nSize, name: "Lightmaps", bClear: false);
LABEL_22:
  pBrushData->m_nLightingDataSize = v2;
  pBrushData->lightdata = v3;
  pBrushData->m_bUnloadedAllLightmaps = false;
}

//------------------------------------------------------------------------------
// Address: 0x100EB010
// Name: void Mod_LoadLighting(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLighting(bool bLoadHDR)
{
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: bLoadHDR ? 53 : 8, bUncompress: false);
  if ( lh.m_nLumpSize != 0 )
  {
    AllocateLightingData(pBrushData: s_pMap, nSize: lh.m_nUncompressedLumpSize);
    if ( s_pMap->lightdata != nullptr )
      CMapLoadHelper::UncompressLump(this: &lh, pExternalBuffer: (unsigned __int8 *)s_pMap->lightdata);
  }
  else
  {
    s_pMap->lightdata = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB0B0
// Name: void Mod_LoadFaceBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadFaceBrushes()
{
  worldbrushdata_t *v0; // eax
  worldbrushdata_t *v1; // esi
  worldbrushdata_t *v2; // esi
  unsigned __int16 *v3; // eax
  worldbrushdata_t *v4; // ecx
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x17u, bUncompress: true);
  if ( lh.m_nLumpSize != 0 )
  {
    v1 = s_pMap;
    v1->m_pSurfaceBrushList = (dfacebrushlist_t *)Hunk_AllocName(
                                                    size: lh.m_nLumpSize,
                                                    name: "FaceBrushLists",
                                                    bClear: false);
    memcpy(dst: (unsigned __int8 *)s_pMap->m_pSurfaceBrushList, src: lh.m_pData, count: lh.m_nLumpSize);
    if ( lh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
    CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x16u, bUncompress: true);
    v2 = s_pMap;
    v3 = (unsigned __int16 *)Hunk_AllocName(size: lh.m_nLumpSize, name: "FaceBrushes", bClear: false);
    v4 = s_pMap;
    v2->m_pSurfaceBrushes = v3;
    memcpy(dst: (unsigned __int8 *)v4->m_pSurfaceBrushes, src: lh.m_pData, count: lh.m_nLumpSize);
  }
  else
  {
    v0 = s_pMap;
    s_pMap->m_pSurfaceBrushes = nullptr;
    v0->m_pSurfaceBrushList = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB1C0
// Name: void Mod_LoadVertices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertices()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // esi
  signed int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  mvertex_t *v5; // eax
  worldbrushdata_t *v6; // ecx
  int v7; // ebx
  unsigned int v8; // ecx
  double v9; // st7
  unsigned __int8 *v10; // edx
  int v11; // esi
  float *p_z; // ecx
  int v13; // edi
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 3u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadVertices: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "vertexes");
  v5 = (mvertex_t *)Hunk_AllocName(size: 12 * v2, name: v4, bClear: true);
  v6 = s_pMap;
  v7 = 0;
  s_pMap->vertexes = v5;
  v6->numvertexes = v2;
  if ( v2 >= 4 )
  {
    v8 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v7 = 4 * v8;
    do
    {
      v9 = *(float *)m_pData;
      m_pData += 48;
      v5->position.x = v9;
      v5 += 4;
      --v8;
      v5[-4].position.y = *((float *)m_pData - 11);
      v5[-4].position.z = *((float *)m_pData - 10);
      v5[-3].position.x = *((float *)m_pData - 9);
      v5[-3].position.y = *((float *)m_pData - 8);
      v5[-3].position.z = *((float *)m_pData - 7);
      v5[-2].position.x = *((float *)m_pData - 6);
      v5[-2].position.y = *((float *)m_pData - 5);
      v5[-2].position.z = *((float *)m_pData - 4);
      v5[-1].position.x = *((float *)m_pData - 3);
      v5[-1].position.y = *((float *)m_pData - 2);
      v5[-1].position.z = *((float *)m_pData - 1);
    }
    while ( v8 != 0 );
  }
  if ( v7 < v2 )
  {
    v10 = m_pData + 8;
    v11 = m_pData - (unsigned __int8 *)v5;
    p_z = &v5->position.z;
    v13 = v2 - v7;
    do
    {
      v10 += 12;
      *(p_z - 2) = *(float *)((char *)p_z + v11 - 8);
      p_z += 3;
      --v13;
      *(p_z - 4) = *((float *)v10 - 4);
      *(p_z - 3) = *((float *)v10 - 3);
    }
    while ( v13 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB330
// Name: struct medge_t __near * Mod_LoadEdges(void)
// Source: json
//------------------------------------------------------------------------------
medge_t *__cdecl Mod_LoadEdges()
{
  unsigned int m_nLumpSize; // eax
  unsigned __int8 *m_pData; // esi
  int v2; // edi
  _BYTE *v3; // eax
  _BYTE *v4; // ebx
  int v5; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xCu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 3) != 0 )
  {
    Host_Error(error: "Mod_LoadEdges: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 2;
  v3 = MemAlloc_Alloc(nSize: (unsigned __int64)(m_nLumpSize >> 2) >> 30 != 0 ? -1 : 4 * (m_nLumpSize >> 2));
  v4 = v3;
  if ( v2 > 0 )
  {
    v5 = v3 - m_pData;
    do
    {
      *(_WORD *)&m_pData[v5] = *(_WORD *)m_pData;
      *(_WORD *)&m_pData[v5 + 2] = *((_WORD *)m_pData + 1);
      m_pData += 4;
      --v2;
    }
    while ( v2 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
  return (medge_t *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100EB3E0
// Name: void Mod_LoadTexinfo(class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadTexinfo(CMapLoadHelper *lh)
{
  signed int v1; // esi
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  mtexinfo_t *v4; // eax
  worldbrushdata_t *v5; // edx
  int m_nValue; // ecx
  unsigned __int8 *v7; // edi
  float *i; // esi
  int v9; // eax
  float v10; // [esp-1Ch] [ebp-2Ch]
  unsigned __int8 *m_pData; // [esp-Ch] [ebp-1Ch]
  signed int v12; // [esp-8h] [ebp-18h]
  int v13; // [esp-4h] [ebp-14h]
  bool in_3; // [esp+3h] [ebp-Dh]

  m_pData = lh->m_pData;
  if ( lh->m_nLumpSize % 0x48u != 0 )
    Host_Error(error: "Mod_LoadTexinfo: funny lump size in %s", s_szMapPathName);
  v1 = lh->m_nLumpSize / 0x48u;
  v12 = v1;
  m_szLumpFilename = lh->m_szLumpFilename;
  if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "texinfo");
  v4 = (mtexinfo_t *)Hunk_AllocName(size: 80 * v1, name: v3, bClear: true);
  v5 = s_pMap;
  s_pMap->texinfo = v4;
  v5->numtexinfo = v1;
  if ( mat_loadtextures.m_pParent != nullptr )
    m_nValue = mat_loadtextures.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  in_3 = m_nValue != 0;
  v13 = 0;
  if ( v1 > 0 )
  {
    v7 = m_pData + 4;
    for ( i = &v4->lightmapVecsLuxelsPerWorldUnits[0].y; ; i += 20 )
    {
      *(i - 9) = *((float *)v7 - 1);
      *(i - 1) = *((float *)v7 + 7);
      *(i - 8) = *(float *)v7;
      *i = *((float *)v7 + 8);
      *(i - 7) = *((float *)v7 + 1);
      i[1] = *((float *)v7 + 9);
      *(i - 6) = *((float *)v7 + 2);
      i[2] = *((float *)v7 + 10);
      *(i - 5) = *((float *)v7 + 3);
      i[3] = *((float *)v7 + 11);
      *(i - 4) = *((float *)v7 + 4);
      i[4] = *((float *)v7 + 12);
      *(i - 3) = *((float *)v7 + 5);
      i[5] = *((float *)v7 + 13);
      *(i - 2) = *((float *)v7 + 6);
      i[6] = *((float *)v7 + 14);
      v10 = fsqrt((float)((float)(*(i - 1) * *(i - 1)) + (float)(i[1] * i[1])) + (float)(*i * *i));
      i[7] = v10;
      i[8] = 1.0 / v10;
      *((_WORD *)i + 18) = *((_WORD *)v7 + 30);
      *((_WORD *)i + 19) = 0;
      if ( !in_3 )
        break;
      v9 = *((_DWORD *)v7 + 16);
      if ( v9 < 0 )
      {
        DevMsg(a1: "Mod_LoadTexinfo: texdata < 0 (index==%i/%i)\n", v13, v12);
        i[10] = 0.0;
      }
      else
      {
        *((_DWORD *)i + 10) = GL_LoadMaterial(
                                pName: v5->texdata[v9].name,
                                pTextureGroupName: "World textures",
                                bPrecache: false);
      }
      if ( *((_DWORD *)i + 10) == 0 )
      {
        *((_DWORD *)i + 10) = g_materialEmpty;
LABEL_18:
        g_materialEmpty->IncrementReferenceCount(this: g_materialEmpty);
      }
      v7 += 72;
      if ( ++v13 >= v12 )
        return;
      v5 = s_pMap;
    }
    *((_DWORD *)i + 10) = g_materialEmpty;
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB610
// Name: void Mod_LoadVertNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertNormals()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // ebx
  unsigned int v2; // edi
  char *m_szLumpFilename; // eax
  int v4; // esi
  const char *v5; // eax
  unsigned __int8 *v6; // esi
  worldbrushdata_t *v7; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x1Eu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadVertNormals: funny lump size in %s!\n", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = m_nLumpSize;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "vertnormals");
  v6 = (unsigned __int8 *)Hunk_AllocName(size: v4, name: v5, bClear: true);
  memcpy(dst: v6, src: m_pData, count: lh.m_nLumpSize);
  v7 = s_pMap;
  s_pMap->numvertnormals = v2;
  v7->vertnormals = (Vector *)v6;
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB700
// Name: void Mod_LoadVertNormalIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertNormalIndices()
{
  int m_nLumpSize; // esi
  unsigned __int8 *m_pData; // ebx
  unsigned int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  worldbrushdata_t *v6; // eax
  unsigned int v7; // esi
  int v8; // edi
  int v9; // edx
  msurface2_t *surfaces2; // ecx
  char *v11; // edx
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int v13; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x1Fu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  v2 = (unsigned int)lh.m_nLumpSize >> 1;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "vertnormalindices");
  v5 = (unsigned __int8 *)Hunk_AllocName(size: m_nLumpSize, name: v4, bClear: true);
  memcpy(dst: v5, src: m_pData, count: lh.m_nLumpSize);
  v6 = s_pMap;
  s_pMap->vertnormalindices = (unsigned __int16 *)v5;
  v6->numvertnormalindices = v2;
  v7 = 0;
  v8 = 0;
  if ( v6->numsurfaces > 0 )
  {
    v9 = 0;
    v13 = 0;
    do
    {
      surfaces2 = v6->surfaces2;
      v11 = (char *)surfaces2 + v9;
      v6->surfacenormals[(v11 - (char *)surfaces2) >> 5].firstvertnormal = v7;
      v7 += (unsigned __int8)v11[3];
      ++v8;
      v9 = v13 + 32;
      v13 += 32;
    }
    while ( v8 < v6->numsurfaces );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB7F0
// Name: void Mod_LoadPrimitives(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimitives()
{
  unsigned int m_nLumpSize; // ecx
  signed int v1; // esi
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  unsigned __int8 *v4; // ebx
  worldbrushdata_t *v5; // eax
  unsigned __int16 *v6; // ecx
  unsigned __int16 *p_firstVert; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  dprimitive_t *in; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x25u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (dprimitive_t *)lh.m_pData;
  if ( lh.m_nLumpSize % 0xAu != 0 )
  {
    Host_Error(error: "Mod_LoadPrimitives: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize / 0xA;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "primitives");
  v4 = (unsigned __int8 *)Hunk_AllocName(size: 12 * v1, name: v3, bClear: true);
  memset(dst: v4, value: 0, count: 12 * v1);
  v5 = s_pMap;
  s_pMap->primitives = (mprimitive_t *)v4;
  v5->numprimitives = v1;
  if ( v1 > 0 )
  {
    v6 = (unsigned __int16 *)(v4 + 8);
    p_firstVert = &in->firstVert;
    do
    {
      *(v6 - 2) = *(p_firstVert - 2);
      *v6 = *p_firstVert;
      *(v6 - 1) = *(p_firstVert - 1);
      *((_DWORD *)v6 - 2) = *((unsigned __int8 *)p_firstVert - 6);
      v6[1] = p_firstVert[1];
      p_firstVert += 5;
      v6 += 6;
      --v1;
    }
    while ( v1 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB920
// Name: void Mod_LoadPrimVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimVerts()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // edi
  signed int v2; // ebx
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  worldbrushdata_t *v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // edi
  int v12; // ebx
  double v13; // st7
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  unsigned int count; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x26u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadPrimVerts: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  count = 28 * v2;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "primverts");
  v5 = (unsigned __int8 *)Hunk_AllocName(size: 28 * v2, name: v4, bClear: true);
  memset(dst: v5, value: 0, count);
  v6 = s_pMap;
  v7 = 0;
  s_pMap->primverts = (mprimvert_t *)v5;
  v6->numprimverts = v2;
  if ( v2 >= 4 )
  {
    v8 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v7 = 4 * v8;
    do
    {
      v9 = *(float *)m_pData;
      m_pData += 48;
      *(float *)v5 = v9;
      v5 += 112;
      --v8;
      *((float *)v5 - 27) = *((float *)m_pData - 11);
      *((float *)v5 - 26) = *((float *)m_pData - 10);
      *((float *)v5 - 21) = *((float *)m_pData - 9);
      *((float *)v5 - 20) = *((float *)m_pData - 8);
      *((float *)v5 - 19) = *((float *)m_pData - 7);
      *((float *)v5 - 14) = *((float *)m_pData - 6);
      *((float *)v5 - 13) = *((float *)m_pData - 5);
      *((float *)v5 - 12) = *((float *)m_pData - 4);
      *((float *)v5 - 7) = *((float *)m_pData - 3);
      *((float *)v5 - 6) = *((float *)m_pData - 2);
      *((float *)v5 - 5) = *((float *)m_pData - 1);
    }
    while ( v8 != 0 );
  }
  if ( v7 < v2 )
  {
    v10 = v5 + 8;
    v11 = m_pData + 8;
    v12 = v2 - v7;
    do
    {
      v13 = *((float *)v11 - 2);
      v11 += 12;
      *((float *)v10 - 2) = v13;
      v10 += 28;
      --v12;
      *((float *)v10 - 8) = *((float *)v11 - 4);
      *((float *)v10 - 7) = *((float *)v11 - 3);
    }
    while ( v12 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBAB0
// Name: void Mod_LoadPrimIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimIndices()
{
  unsigned int m_nLumpSize; // ebx
  unsigned int v1; // ebx
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  unsigned __int8 *v4; // edi
  worldbrushdata_t *v5; // eax
  unsigned __int8 *v6; // [esp-20h] [ebp-158h]
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  unsigned __int16 *in; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x27u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (unsigned __int16 *)lh.m_pData;
  if ( (lh.m_nLumpSize & 1) != 0 )
  {
    Host_Error(error: "Mod_LoadPrimIndices: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize >> 1;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "primindices");
  v4 = (unsigned __int8 *)Hunk_AllocName(size: 2 * v1, name: v3, bClear: true);
  memset(dst: v4, value: 0, count: 2 * v1);
  v5 = s_pMap;
  v6 = (unsigned __int8 *)in;
  s_pMap->primindices = (unsigned __int16 *)v4;
  v5->numprimindices = v1;
  memcpy(dst: v4, src: v6, count: 2 * v1);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBB90
// Name: void Mod_LoadLump(struct model_t __near *,int,char __near *,int,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLump(
        model_t *loadmodel,
        unsigned int iLump,
        char *loadname,
        int elementSize,
        void **ppData,
        int *nElements)
{
  int m_nLumpSize; // ecx
  void *v7; // eax
  unsigned int v8; // edx
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: iLump, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  if ( lh.m_nLumpSize % elementSize != 0 )
  {
    Host_Error(error: "Mod_LoadLump: funny lump size in %s", loadmodel->szPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  *nElements = m_nLumpSize / elementSize;
  v7 = Hunk_AllocName(size: m_nLumpSize, name: loadname, bClear: true);
  v8 = lh.m_nLumpSize;
  *ppData = v7;
  memcpy(dst: (unsigned __int8 *)v7, src: lh.m_pData, count: v8);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBC30
// Name: void Mod_LoadFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadFaces()
{
  unsigned int v0; // esi
  int lumpLength; // eax
  unsigned int m_nLumpSize; // ecx
  signed int v3; // ebx
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  unsigned __int8 *v6; // edi
  bool v7; // zf
  char *v8; // eax
  const char *v9; // eax
  int v10; // esi
  unsigned __int8 *v11; // edi
  unsigned int v12; // edi
  char *v13; // eax
  const char *v14; // eax
  msurface1_t *v15; // edx
  msurfacelighting_t *v16; // ecx
  worldbrushdata_t *v17; // eax
  char *v18; // eax
  const char *v19; // eax
  worldbrushdata_t *v20; // ecx
  __int16 *p_numedges; // esi
  msurface2_t *v22; // edi
  int v23; // eax
  int v24; // edx
  int v25; // ebx
  __int16 v26; // ax
  int v27; // ebx
  msurfacelighting_t *v28; // eax
  ColorRGBExp32 *lightdata; // ecx
  int v30; // edx
  unsigned __int8 v31; // cl
  int v32; // eax
  msurface1_t *v33; // ebx
  unsigned __int16 *v34; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-148h] BYREF
  msurfacelighting_t *v36; // [esp+134h] [ebp-20h]
  msurface2_t **p_surfaces2; // [esp+138h] [ebp-1Ch]
  worldbrushdata_t *pBrushData; // [esp+13Ch] [ebp-18h]
  unsigned __int16 *p_firstPrimID; // [esp+140h] [ebp-14h]
  msurfacelighting_t *pLighting; // [esp+144h] [ebp-10h]
  dface_t *in; // [esp+148h] [ebp-Ch]
  unsigned __int8 *v42; // [esp+14Ch] [ebp-8h]
  msurface1_t *out1; // [esp+150h] [ebp-4h]
  int savedregs; // [esp+154h] [ebp+0h] BYREF

  v0 = 7;
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
  {
    lumpLength = s_MapLumpFiles[58].header.lumpLength;
    if ( s_MapLumpFiles[58].file == nullptr )
      lumpLength = s_MapHeader.lumps[58].filelen;
    if ( lumpLength > 0 )
      v0 = 58;
  }
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: v0, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (dface_t *)lh.m_pData;
  if ( lh.m_nLumpSize % 0x38u != 0 )
  {
    Host_Error(error: "Mod_LoadFaces: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v3 = m_nLumpSize / 0x38;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "surface1");
  v6 = (unsigned __int8 *)Hunk_AllocName(size: 16 * (v3 + 1) + 16, name: v5, bClear: true);
  memset(dst: v6, value: 0, count: 16 * (v3 + 1) + 16);
  v7 = s_MapLumpFiles[lh.m_nLumpID].file == nullptr;
  out1 = (msurface1_t *)((unsigned int)(v6 + 15) & 0xFFFFFFF0);
  v8 = lh.m_szLumpFilename;
  if ( v7 )
    v8 = s_szMapPathName;
  v9 = va(format: "%s [%s]", v8, "surface2");
  v10 = 32 * (v3 + 1) + 32;
  v11 = (unsigned __int8 *)Hunk_AllocName(size: v10, name: v9, bClear: true);
  memset(dst: v11, value: 0, count: v10);
  v12 = (unsigned int)(v11 + 31) & 0xFFFFFFE0;
  v13 = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    v13 = s_szMapPathName;
  v14 = va(format: "%s [%s]", v13, "surfacelighting");
  v42 = (unsigned __int8 *)Hunk_AllocName(size: v10, name: v14, bClear: true);
  memset(dst: v42, value: 0, count: v10);
  v15 = out1;
  v16 = (msurfacelighting_t *)((unsigned int)(v42 + 31) & 0xFFFFFFE0);
  v36 = v16;
  v17 = s_pMap;
  s_pMap->surfacelighting = v16;
  v17->surfaces1 = v15;
  v17->surfaces2 = (msurface2_t *)v12;
  pLighting = v16;
  v18 = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    v18 = s_szMapPathName;
  v19 = va(format: "%s [%s]", v18, "surfacenormal");
  v42 = (unsigned __int8 *)Hunk_AllocName(size: 4 * v3 + 4, name: v19, bClear: true);
  memset(dst: v42, value: 0, count: 4 * v3 + 4);
  v20 = s_pMap;
  s_pMap->surfacenormals = (msurfacenormal_t *)((unsigned int)(v42 + 1) & 0xFFFFFFFE);
  v20->numsurfaces = v3;
  pBrushData = v20;
  if ( v3 > 0 )
  {
    p_numedges = &in->numedges;
    p_surfaces2 = &v20->surfaces2;
    p_firstPrimID = &out1->prims.firstPrimID;
    in = nullptr;
    out1 = (msurface1_t *)&pLighting->m_nStyles[v12 - (_DWORD)v36];
    v42 = (unsigned __int8 *)v3;
    while ( 1 )
    {
      v22 = (msurface2_t *)((char *)*p_surfaces2 + (_DWORD)in);
      v22->firstvertindex = *((_DWORD *)p_numedges - 1);
      v23 = *p_numedges << 24;
      v22->flags = v23;
      v24 = (unsigned __int16)*(p_numedges - 4);
      if ( *((_BYTE *)p_numedges - 5) != 0 )
        v22->flags = v23 | 2;
      if ( *((_BYTE *)p_numedges - 6) != 0 )
        v22->flags |= 0x40u;
      out1[-2].prims = (msurface1_t::<unnamed_type_prims>)&v20->planes[v24];
      v25 = p_numedges[1];
      if ( v25 < 0 || v25 >= v20->numtexinfo )
      {
        Host_Error(error: "Mod_LoadFaces: bad texinfo number");
        v20 = s_pMap;
      }
      v26 = (2 * v25) | *((_WORD *)v22 + 11) & 1;
      *((_WORD *)v22 + 11) = v26;
      *((_WORD *)v22 + 11) = v26 & 0xFFFE | (p_numedges[20] >= 0);
      v27 = (int)&v20->texinfo[v25];
      if ( *(_DWORD *)(v27 + 76) == 0 )
      {
        *(_DWORD *)(v27 + 76) = g_materialEmpty;
        g_materialEmpty->IncrementReferenceCount(this: g_materialEmpty);
        v20 = s_pMap;
      }
      v28 = pLighting;
      lightdata = v20->lightdata;
      pLighting->m_LightmapExtents[0] = p_numedges[14];
      v28->m_LightmapExtents[1] = p_numedges[16];
      v28->m_LightmapMins[0] = p_numedges[10];
      v28->m_LightmapMins[1] = p_numedges[12];
      v30 = *((_DWORD *)p_numedges + 3);
      if ( v30 == -1 || lightdata == nullptr )
      {
        v28->m_pSamples = nullptr;
        *(_DWORD *)v28->m_nStyles = -1;
      }
      else
      {
        v28->m_pSamples = (ColorRGBExp32 *)((char *)lightdata + v30);
        v28->m_nStyles[0] = *((_BYTE *)p_numedges + 8);
        v28->m_nStyles[1] = *((_BYTE *)p_numedges + 9);
        v28->m_nStyles[2] = *((_BYTE *)p_numedges + 10);
        v28->m_nStyles[3] = *((_BYTE *)p_numedges + 11);
      }
      v31 = v28->m_nStyles[0];
      if ( v31 != 0 && v31 != 0xFF || v28->m_nStyles[1] != 0xFF )
        v22->flags |= 0x400u;
      if ( (*(_WORD *)(v27 + 72) & 0x400) != 0 )
        v22->flags |= 1u;
      if ( (*(_WORD *)(v27 + 72) & 0x1000) != 0 )
        v22->flags |= 0x2000u;
      if ( (*(_BYTE *)(v27 + 72) & 8) != 0 )
        v22->flags |= 0x10000u;
      if ( (*(_BYTE *)(v27 + 72) & 4) != 0 )
        v22->flags |= 4u;
      if ( (*(_WORD *)(v27 + 72) & 0x2000) != 0 )
        v22->flags |= 0x100000u;
      v32 = p_numedges[2];
      v33 = out1;
      out1->textureMins[0] = 0;
      if ( v32 == -1 )
      {
        v34 = p_firstPrimID;
        *(p_firstPrimID - 1) = p_numedges[20] & 0x7FFF;
        *v34 = p_numedges[21];
        if ( (p_numedges[20] & 0x7FFF) != 0 )
        {
          v22->flags |= 0x8000u;
          if ( pBrushData->primitives[(unsigned __int16)p_numedges[21]].vertCount != 0 )
            v22->flags |= 0x80u;
        }
      }
      else
      {
        v22->flags |= 0x800u;
      }
      v33[-1].textureMins[1] = -1;
      v33[-1].textureExtents[0] = -1;
      CalcSurfaceExtents(surfID: v22);
      CheckSurfaceLighting(pBrushData, a2: COERCE_FLOAT(&savedregs), maxLight_8: v22);
      p_firstPrimID += 8;
      in = (dface_t *)((char *)in + 32);
      ++pLighting;
      p_numedges += 28;
      v7 = v42-- == (unsigned __int8 *)1;
      out1 = v33 + 2;
      if ( v7 )
        break;
      v20 = s_pMap;
    }
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC100
// Name: void Mod_LoadNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadNodes()
{
  unsigned int m_nLumpSize; // eax
  unsigned __int8 *m_pData; // ebx
  int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  mnode_t *v5; // eax
  worldbrushdata_t *v6; // esi
  __int16 *v7; // ecx
  float *p_y; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  int v12; // edx
  float v13; // xmm7_4
  int v14; // edx
  int v15; // edx
  mnode_t *nodes; // edx
  bool v17; // sf
  mnode_t *v18; // edx
  mnode_t *v19; // esi
  float *p_z; // ecx
  int j; // ebx
  const Vector *v22; // edi
  int *v23; // edx
  int v24; // edx
  int *v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  mnode_t *v31; // [esp-8h] [ebp-140h]
  mnode_t *v32; // [esp-8h] [ebp-140h]
  mnode_t *v33; // [esp-4h] [ebp-13Ch]
  mnode_t *v34; // [esp-4h] [ebp-13Ch]
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int i; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 5u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 0x1F) != 0 )
  {
    Host_Error(error: "Mod_LoadNodes: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 5;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "nodes");
  v5 = (mnode_t *)Hunk_AllocName(size: v2 << 6, name: v4, bClear: true);
  v6 = s_pMap;
  s_pMap->nodes = v5;
  v6->numnodes = v2;
  if ( v2 > 0 )
  {
    v7 = (__int16 *)(m_pData + 18);
    p_y = &v5->m_vecCenter.y;
    for ( i = v2; i != 0; --i )
    {
      v9 = (float)*v7;
      v10 = (float)v7[1];
      v11 = (float)*(v7 - 1);
      v12 = v7[2];
      v13 = v9 + (float)*(v7 - 3);
      *p_y = v10 + (float)*(v7 - 2);
      p_y[1] = (float)v12 + v11;
      *(p_y - 1) = v13 * 0.5;
      *p_y = *p_y * 0.5;
      p_y[1] = p_y[1] * 0.5;
      p_y[3] = v9 - *(p_y - 1);
      p_y[4] = v10 - *p_y;
      p_y[5] = (float)v12 - p_y[1];
      *((_DWORD *)p_y + 7) = &v6->planes[*(_DWORD *)(v7 - 9)];
      *((_WORD *)p_y + 20) = v7[3];
      *((_WORD *)p_y + 21) = v7[4];
      *((_WORD *)p_y - 4) = v7[5];
      *(p_y - 5) = NAN;
      v14 = *(_DWORD *)(v7 - 7);
      if ( v14 < 0 )
        *((_DWORD *)p_y + 8) = &v6->leafs[-v14 - 1];
      else
        *((_DWORD *)p_y + 8) = &v6->nodes[v14];
      v15 = *(_DWORD *)(v7 - 5);
      if ( v15 < 0 )
        *((_DWORD *)p_y + 9) = &v6->leafs[-v15 - 1];
      else
        *((_DWORD *)p_y + 9) = &v6->nodes[v15];
      v7 += 16;
      p_y += 16;
    }
  }
  nodes = v6->nodes;
  v17 = nodes->contents < 0;
  nodes->parent = nullptr;
  if ( v17 )
  {
    Mod_SetParent(node: nodes->children[0], parent: nodes);
    Mod_SetParent(node: v18->children[1], parent: v18);
  }
  v19 = v6->nodes;
  if ( v2 > 0 )
  {
    p_z = &v19->m_vecHalfDiagonal.z;
    for ( j = v2; j != 0; --j )
    {
      if ( v19->contents == -1 )
      {
        v22 = (const Vector *)(p_z - 2);
        if ( *(p_z - 2) > 50.0 || *(p_z - 1) > 50.0 || *p_z > 50.0 )
        {
          v27 = *((_DWORD *)p_z + 3);
          if ( *(int *)v27 < 0
            && (float)(v22->x - *(float *)(v27 + 32)) < 5.0
            && (float)(*(p_z - 1) - *(float *)(v27 + 36)) < 5.0
            && (float)(*p_z - *(float *)(v27 + 40)) < 5.0 )
          {
            v31 = *(mnode_t **)(v27 + 52);
            *(_DWORD *)v27 = -3;
            CheckSmallVolumeDifferences(pNode: v31, parentSize: (const Vector *)(p_z - 2));
            CheckSmallVolumeDifferences(pNode: *(mnode_t **)(v28 + 56), parentSize: v22);
          }
          v29 = *((_DWORD *)p_z + 4);
          if ( *(int *)v29 < 0
            && (float)(v22->x - *(float *)(v29 + 32)) < 5.0
            && (float)(*(p_z - 1) - *(float *)(v29 + 36)) < 5.0
            && (float)(*p_z - *(float *)(v29 + 40)) < 5.0 )
          {
            v32 = *(mnode_t **)(v29 + 52);
            *(_DWORD *)v29 = -3;
            CheckSmallVolumeDifferences(pNode: v32, parentSize: v22);
            CheckSmallVolumeDifferences(pNode: *(mnode_t **)(v30 + 56), parentSize: v22);
          }
        }
        else
        {
          v23 = *((int **)p_z + 3);
          if ( *v23 < 0 )
          {
            v33 = (mnode_t *)v23[13];
            *v23 = -2;
            MarkSmallNode(node: v33);
            MarkSmallNode(node: *(mnode_t **)(v24 + 56));
          }
          v25 = *((int **)p_z + 4);
          if ( *v25 < 0 )
          {
            v34 = (mnode_t *)v25[13];
            *v25 = -2;
            MarkSmallNode(node: v34);
            MarkSmallNode(node: *(mnode_t **)(v26 + 56));
          }
        }
      }
      ++v19;
      p_z += 16;
    }
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC460
// Name: void Mod_LoadLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs()
{
  int lumpLength; // eax
  unsigned __int8 *m_pRawData; // eax
  worldbrushdata_t *v2; // edx
  int v3; // esi
  worldbrushdata_t *v4; // ecx
  int v5; // ecx
  unsigned __int16 *p_dispListStart; // eax
  CMapLoadHelper ambientLightingLump; // [esp+0h] [ebp-5D0h] BYREF
  CMapLoadHelper mlh; // [esp+128h] [ebp-4A8h] BYREF
  CMapLoadHelper ambientLightingTable; // [esp+250h] [ebp-380h] BYREF
  CMapLoadHelper mlhTable; // [esp+378h] [ebp-258h] BYREF
  CMapLoadHelper lh; // [esp+4A0h] [ebp-130h] BYREF
  int *p_numleafs; // [esp+5C8h] [ebp-8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xAu, bUncompress: true);
  if ( lh.m_nLumpVersion != 0 )
  {
    if ( lh.m_nLumpVersion == 1 )
    {
      if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
        goto LABEL_11;
      lumpLength = s_MapLumpFiles[55].header.lumpLength;
      if ( s_MapLumpFiles[55].file == nullptr )
        lumpLength = s_MapHeader.lumps[55].filelen;
      if ( lumpLength > 0 )
      {
        CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0x37u, bUncompress: true);
        CMapLoadHelper::CMapLoadHelper(this: &mlhTable, lumpToLoad: 0x33u, bUncompress: true);
        Mod_LoadLeafs_Version_1(&lh, ambientLightingLump: (CompressedLightCube *)&mlh, ambientLightingTable: &mlhTable);
        if ( mlhTable.m_pRawData != nullptr )
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: mlhTable.m_pRawData);
        m_pRawData = mlh.m_pRawData;
      }
      else
      {
LABEL_11:
        CMapLoadHelper::CMapLoadHelper(this: &ambientLightingLump, lumpToLoad: 0x38u, bUncompress: true);
        CMapLoadHelper::CMapLoadHelper(this: &ambientLightingTable, lumpToLoad: 0x34u, bUncompress: true);
        Mod_LoadLeafs_Version_1(&lh, (CompressedLightCube *)&ambientLightingLump, &ambientLightingTable);
        if ( ambientLightingTable.m_pRawData != nullptr )
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: ambientLightingTable.m_pRawData);
        m_pRawData = ambientLightingLump.m_pRawData;
      }
      if ( m_pRawData != nullptr )
        g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
    }
    else
    {
      _Error(a1: "Unknown LUMP_LEAFS version\n");
    }
  }
  else
  {
    Mod_LoadLeafs_Version_0((int)&lh);
  }
  v2 = s_pMap;
  v3 = 0;
  v4 = s_pMap;
  p_numleafs = &s_pMap->numleafs;
  if ( s_pMap->numleafs > 0 )
  {
    v5 = 0;
    p_dispListStart = &g_BSPData.map_leafs.m_pArray->dispListStart;
    do
    {
      v2->leafs[v5].dispCount = p_dispListStart[1];
      v2->leafs[v5].dispListStart = *p_dispListStart;
      ++v3;
      p_dispListStart += 8;
      ++v5;
    }
    while ( v3 < *p_numleafs );
    v4 = v2;
  }
  v4->m_pDispInfoReferences = g_BSPData.map_dispList.m_pArray;
  v4->m_nDispInfoReferences = g_BSPData.numdisplist;
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC630
// Name: void Mod_LoadLeafWaterData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafWaterData()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // edi
  unsigned int v2; // kr00_4
  signed int v3; // esi
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  mleafwaterdata_t *v6; // eax
  worldbrushdata_t *v7; // ecx
  __int16 *p_surfaceTexInfoID; // edx
  float *v9; // ecx
  int v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  __int16 *p_leafWaterDataID; // edx
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x24u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize;
  v3 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "leafwaterdata");
  v6 = (mleafwaterdata_t *)Hunk_AllocName(size: 12 * v3, name: v5, bClear: true);
  v7 = s_pMap;
  s_pMap->leafwaterdata = v6;
  v7->numleafwaterdata = v3;
  if ( v3 > 0 )
  {
    p_surfaceTexInfoID = &v6->surfaceTexInfoID;
    v9 = (float *)(m_pData + 8);
    v10 = (char *)v6 - (char *)m_pData - 8;
    v11 = v2 / 0xC;
    do
    {
      p_surfaceTexInfoID += 6;
      *((float *)p_surfaceTexInfoID - 4) = *(v9 - 1);
      *(p_surfaceTexInfoID - 6) = *(_WORD *)v9;
      *(float *)((char *)v9 + v10) = *(v9 - 2);
      *(p_surfaceTexInfoID - 5) = -1;
      v9 += 3;
      --v11;
    }
    while ( v11 != 0 );
    v7 = s_pMap;
  }
  if ( v3 == 1 )
  {
    v12 = 0;
    if ( v7->numleafs > 0 )
    {
      p_leafWaterDataID = &v7->leafs->leafWaterDataID;
      while ( *p_leafWaterDataID < 0 )
      {
        ++v12;
        p_leafWaterDataID += 32;
        if ( v12 >= v7->numleafs )
          goto LABEL_16;
      }
      v7->leafwaterdata->firstLeafIndex = v12;
    }
  }
LABEL_16:
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC780
// Name: void Mod_LoadLeafMinDistToWater(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafMinDistToWater()
{
  unsigned int m_nLumpSize; // edx
  int v1; // eax
  unsigned __int8 *m_pData; // ebx
  unsigned int v3; // edx
  char *m_szLumpFilename; // eax
  int v5; // esi
  const char *v6; // eax
  unsigned __int8 *v7; // edi
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x2Eu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  v1 = 0;
  if ( (unsigned int)lh.m_nLumpSize >> 1 == 0 )
    goto LABEL_5;
  m_pData = lh.m_pData;
  while ( *(_WORD *)&lh.m_pData[2 * v1] == 0xFFFF )
  {
    if ( ++v1 >= (signed int)((unsigned int)lh.m_nLumpSize >> 1) )
      goto LABEL_5;
  }
  if ( lh.m_nLumpSize != 0 && g_pMaterialSystemHardwareConfig != nullptr )
  {
    if ( (lh.m_nLumpSize & 1) != 0 )
    {
      Host_Error(error: "Mod_LoadLeafMinDistToWater: funny lump size in %s", s_szMapPathName);
      m_nLumpSize = lh.m_nLumpSize;
    }
    v3 = m_nLumpSize >> 1;
    m_szLumpFilename = lh.m_szLumpFilename;
    if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
      m_szLumpFilename = s_szMapPathName;
    v5 = 2 * v3;
    v6 = va(format: "%s [%s]", m_szLumpFilename, "leafmindisttowater");
    v7 = (unsigned __int8 *)Hunk_AllocName(size: v5, name: v6, bClear: true);
    memcpy(dst: v7, src: m_pData, count: v5);
    s_pMap->m_LeafMinDistToWater = (unsigned __int16 *)v7;
  }
  else
  {
LABEL_5:
    s_pMap->m_LeafMinDistToWater = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC880
// Name: void Mod_LoadMarksurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadMarksurfaces()
{
  unsigned int m_nLumpSize; // eax
  int v1; // edi
  msurface2_t **v2; // eax
  worldbrushdata_t *v3; // ecx
  int v4; // ebx
  int v5; // esi
  msurface2_t *v6; // esi
  char *m_szLumpFilename; // eax
  const char *v8; // eax
  worldbrushdata_t *v9; // eax
  mleaf_t *leafs; // ecx
  int v11; // esi
  int v12; // edi
  unsigned __int16 *v13; // ecx
  msurface2_t *v14; // edx
  int v15; // edx
  msurface2_t **v16; // [esp-10h] [ebp-160h]
  CMapLoadHelper lh; // [esp+0h] [ebp-150h] BYREF
  msurface2_t ***p_marksurfaces; // [esp+128h] [ebp-28h]
  int *p_nummarksurfaces; // [esp+12Ch] [ebp-24h]
  int firstMark; // [esp+130h] [ebp-20h]
  worldbrushdata_t *pBrushData; // [esp+134h] [ebp-1Ch]
  msurface2_t **tempDiskData; // [esp+138h] [ebp-18h]
  int numMark; // [esp+13Ch] [ebp-14h]
  int numMarkNode; // [esp+140h] [ebp-10h]
  msurface2_t **surfList; // [esp+144h] [ebp-Ch]
  int realCount; // [esp+148h] [ebp-8h]
  int i; // [esp+14Ch] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x10u, bUncompress: true);
  surfList = (msurface2_t **)lh.m_pData;
  m_nLumpSize = lh.m_nLumpSize;
  if ( (lh.m_nLumpSize & 1) != 0 )
  {
    Host_Error(error: "Mod_LoadMarksurfaces: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize >> 1;
  v2 = (msurface2_t **)MemAlloc_Alloc(nSize: (unsigned __int64)(m_nLumpSize >> 1) >> 30 != 0 ? -1 : 4 * (m_nLumpSize >> 1));
  v3 = s_pMap;
  v4 = 0;
  p_marksurfaces = &s_pMap->marksurfaces;
  s_pMap->marksurfaces = v2;
  tempDiskData = v2;
  pBrushData = v3;
  p_nummarksurfaces = &v3->nummarksurfaces;
  v3->nummarksurfaces = v1;
  realCount = 0;
  if ( v1 > 0 )
  {
    i = (int)&v3->surfaces2;
    do
    {
      v5 = *((unsigned __int16 *)surfList + v4);
      if ( v5 >= v3->numsurfaces )
      {
        Host_Error(error: "Mod_LoadMarksurfaces: bad surface number");
        v3 = s_pMap;
      }
      v6 = (msurface2_t *)(*(_DWORD *)i + 32 * v5);
      tempDiskData[v4] = v6;
      if ( (v6->flags & 0x800) == 0 && (v6->flags & 0x10) == 0 )
        ++realCount;
      ++v4;
    }
    while ( v4 < v1 );
  }
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v8 = va(format: "%s [%s]", m_szLumpFilename, "surfacehandle");
  surfList = (msurface2_t **)Hunk_AllocName(size: 4 * realCount, name: v8, bClear: true);
  v9 = pBrushData;
  leafs = pBrushData->leafs;
  v11 = 0;
  v12 = 0;
  i = 0;
  if ( pBrushData->numleafs > 0 )
  {
    v13 = &leafs->nummarksurfaces;
    do
    {
      firstMark = v12;
      numMark = 0;
      numMarkNode = 0;
      if ( *v13 != 0 )
      {
        do
        {
          v14 = *(&tempDiskData[v11] + *(v13 - 1));
          if ( (v14->flags & 0x800) == 0 && (v14->flags & 0x10) == 0 )
          {
            surfList[v12] = v14;
            ++numMark;
            ++v12;
            if ( (v14->flags & 2) != 0 )
              ++numMarkNode;
          }
          ++v11;
        }
        while ( v11 < *v13 );
        v9 = pBrushData;
        v11 = 0;
      }
      *v13 = numMark;
      *(v13 - 1) = firstMark;
      v13[1] = numMarkNode;
      v13 += 32;
      ++i;
    }
    while ( i < v9->numleafs );
  }
  v15 = realCount;
  *p_marksurfaces = surfList;
  v16 = tempDiskData;
  *p_nummarksurfaces = v15;
  free(pMem: v16);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100ECA80
// Name: void Mod_LoadSurfedges(struct medge_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadSurfedges(medge_t *pedges)
{
  unsigned int m_nLumpSize; // eax
  int v2; // eax
  int v3; // esi
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  unsigned __int16 *v6; // eax
  worldbrushdata_t *v7; // ecx
  int i; // ecx
  int v9; // edx
  int v10; // edi
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  int *in; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xDu, bUncompress: true);
  in = (int *)lh.m_pData;
  m_nLumpSize = lh.m_nLumpSize;
  if ( (lh.m_nLumpSize & 3) != 0 )
  {
    Host_Error(error: "Mod_LoadSurfedges: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 2;
  v3 = v2;
  if ( v2 == 0 || v2 >= 512000 )
    Host_Error(error: "Mod_LoadSurfedges: bad surfedges count in %s: %i", s_szMapPathName, v2);
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "surfedges");
  v6 = (unsigned __int16 *)Hunk_AllocName(size: 2 * v3, name: v5, bClear: true);
  v7 = s_pMap;
  s_pMap->vertindices = v6;
  v7->numvertindices = v3;
  for ( i = 0; i < v3; ++i )
  {
    v9 = in[i];
    v10 = 0;
    if ( v9 < 0 )
    {
      v9 = -v9;
      v10 = 1;
    }
    v6[i] = pedges[v9].v[v10];
  }
  free(pMem: pedges);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100ECBA0
// Name: int Mod_GameLumpVersion(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GameLumpVersion(int lumpId)
{
  int v1; // eax
  dgamelump_t *i; // ecx

  v1 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 < 0 )
    return 0;
  for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v1]; i->id != lumpId; --i )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return g_GameLumpDict.m_Memory.m_pMemory[v1].version;
}

//------------------------------------------------------------------------------
// Address: 0x100ECBE0
// Name: int Mod_GameLumpSize(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GameLumpSize(int lumpId)
{
  int v1; // eax
  dgamelump_t *i; // ecx

  v1 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 < 0 )
    return 0;
  for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v1]; i->id != lumpId; --i )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return g_GameLumpDict.m_Memory.m_pMemory[v1].filelen;
}

//------------------------------------------------------------------------------
// Address: 0x100ECC20
// Name: bool Mod_LoadGameLump(int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall Mod_LoadGameLump@<al>(int a1@<ebx>, int a2@<edi>, int lumpId, void *pOutBuffer, int size)
{
  int v5; // eax
  dgamelump_t *i; // ecx
  int v8; // eax
  int v9; // ebx
  int filelen; // edi
  char v11; // al
  int v12; // ebx
  void *v13; // esi
  bool v14; // bl
  void *v15; // ebx
  int v16; // eax
  void (__thiscall *Close)(IBaseFileSystem *, void *); // edx
  char szNameOnDisk[263]; // [esp+4h] [ebp-108h] BYREF
  bool bOK; // [esp+10Bh] [ebp-1h]

  v5 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 >= 0 )
  {
    for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v5]; i->id != lumpId; --i )
    {
      if ( --v5 < 0 )
        return 0;
    }
    if ( v5 >= 0 )
    {
      v8 = v5;
      v9 = v8 * 16;
      filelen = g_GameLumpDict.m_Memory.m_pMemory[v8].filelen;
      if ( size >= filelen )
      {
        v11 = g_GameLumpDict.m_Memory.m_pMemory[v8].flags & 1;
        bOK = *((_BYTE *)&g_GameLumpDict.m_Memory.m_pMemory->flags + v9) & 1;
        if ( bOK )
          filelen = *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory[1].fileofs + v9)
                  - *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9);
        if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
        {
          v12 = *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9);
          if ( v12 + filelen <= s_MapBuffer.m_nMaxPut && v11 == 0 )
          {
            _V_memcpy(dest: pOutBuffer, src: &s_MapBuffer.m_Memory.m_pMemory[v12], count: filelen);
            return 1;
          }
        }
        else
        {
          V_strncpy(pDest: szNameOnDisk, pSrc: g_GameLumpFilename, maxLen: 260);
          v13 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: szNameOnDisk, a3: "rb", a4: 0, a5: 0, a6: 0);
          if ( v13 != nullptr )
          {
            ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD, _DWORD, int, int))g_pFileSystem->Seek)(
              a1: &g_pFileSystem->IBaseFileSystem,
              a2: v13,
              a3: *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9),
              a4: 0,
              a5: a2,
              a6: a1);
            if ( !bOK )
            {
              v14 = ((int (__thiscall *)(IBaseFileSystem *, void *))g_pFileSystem->Read)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: pOutBuffer) > 0;
              g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
              return v14;
            }
            v15 = MemAlloc_Alloc(nSize: filelen);
            v16 = ((int (__thiscall *)(IBaseFileSystem *, void *))g_pFileSystem->Read)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: v15);
            Close = g_pFileSystem->Close;
            bOK = v16 > 0;
            Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
            if ( !bOK )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
          }
        }
      }
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ECDC0
// Name: void Mod_TouchAllData(struct model_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_TouchAllData(model_t *pModel, int nServerCount)
{
  CStatTime *v2; // ecx
  IMDLCache *v3; // edi
  int v4; // esi
  CStatTime *v5; // ecx
  int v6; // ebx
  int v7; // edi
  _DWORD *v8; // eax
  int v9; // edx
  double t1; // [esp+8h] [ebp-Ch]
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-4h]

  t1 = _Plat_FloatTime(this: v2);
  v3 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v4 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVirtualModel)(a1: pModel->studio);
  g_flAccumulatedModelLoadTimeVirtualModel = _Plat_FloatTime(this: v5) - t1 + g_flAccumulatedModelLoadTimeVirtualModel;
  if ( v4 != 0 )
  {
    v6 = 1;
    if ( nServerCount >= 1 && *(int *)(v4 + 100) > 1 )
    {
      v7 = 144;
      do
      {
        v8 = g_pMDLCache->GetUserData(this: g_pMDLCache, a2: *(unsigned __int16 *)(v7 + *(_DWORD *)(v4 + 88)));
        if ( v8 != nullptr )
        {
          v9 = v8[66] | pModel->nLoadFlags & 0x7E;
          v8[67] = nServerCount;
          v8[66] = v9 & 0xFFFEFFFE | 1;
        }
        ++v6;
        v7 += 144;
      }
      while ( v6 < *(_DWORD *)(v4 + 100) );
      v3 = cacheCriticalSection;
    }
  }
  if ( mod_forcetouchdata.m_pParent != nullptr && mod_forcetouchdata.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__stdcall *)(_DWORD))g_pMDLCache->TouchAllData)(a1: pModel->studio);
    v3->EndLock(this: v3);
  }
  else
  {
    v3->EndLock(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECED0
// Name: private: void CMDLCacheNotify::ComputeModelFlags(struct model_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::ComputeModelFlags(CMDLCacheNotify *this, model_t *pModel, int handle)
{
  studiohdr_t *v3; // eax
  int v5; // ebx
  IMaterial *v6; // edi
  IMaterial *materials[128]; // [esp+Ch] [ebp-200h] BYREF
  int materialCount; // [esp+214h] [ebp+8h]
  bool handle_3; // [esp+21Bh] [ebp+Fh]

  v3 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: handle);
  pModel->flags &= 0xFFFFD8E0;
  handle_3 = (v3->flags & 4) != 0;
  if ( (v3->flags & 8) != 0 )
    pModel->flags |= 8u;
  if ( (v3->flags & 0x20) != 0 )
    pModel->flags |= 0x100u;
  if ( (v3->flags & 0x10) != 0 )
    pModel->flags |= 0x2000u;
  if ( SLOBYTE(v3->flags) < 0 )
    pModel->flags |= 0x200u;
  if ( (v3->flags & 2) != 0 )
    pModel->flags |= 0x400u;
  if ( (v3->flags & 0x10000) != 0 )
    pModel->flags |= 0x800u;
  if ( (v3->flags & 0x20000) != 0 )
    pModel->flags |= 0x1000u;
  v5 = 0;
  materialCount = Mod_GetModelMaterials(pModel, count: 128, ppMaterials: materials);
  if ( materialCount > 0 )
  {
    do
    {
      v6 = materials[v5];
      if ( v6 != nullptr )
      {
        if ( v6->IsVertexLit(this: materials[v5]) )
          pModel->flags |= 4u;
        if ( !handle_3 && v6->IsTranslucent(this: v6) )
          pModel->flags |= 2u;
        if ( v6->HasProxy(this: v6) )
          pModel->flags |= 1u;
        if ( v6->NeedsPowerOfTwoFrameBufferTexture(this: v6, a2: false) )
          pModel->flags |= 0x10u;
      }
      ++v5;
    }
    while ( v5 < materialCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED030
// Name: public: virtual void CMDLCacheNotify::OnDataLoaded(enum MDLCacheDataType_t,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::OnDataLoaded(CMDLCacheNotify *this, MDLCacheDataType_t type, int handle)
{
  model_t *v4; // esi
  vcollide_t *v5; // eax
  Vector *p_maxs; // edi
  Vector *p_mins; // esi
  Vector *v8; // [esp-4h] [ebp-28h]
  Vector maxs; // [esp+Ch] [ebp-18h] BYREF
  Vector mins; // [esp+18h] [ebp-Ch] BYREF

  v4 = (model_t *)g_pMDLCache->GetUserData(this: g_pMDLCache, a2: handle);
  if ( v4 != nullptr )
  {
    if ( type != MDLCACHE_STUDIOHDR )
    {
      if ( type == MDLCACHE_STUDIOHWDATA )
      {
        CMDLCacheNotify::ComputeModelFlags(this, pModel: v4, handle);
      }
      else if ( type == MDLCACHE_VCOLLIDE )
      {
        CMDLCacheNotify::SetBoundsFromStudioHdr(this, pModel: v4, handle);
        v5 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: handle);
        if ( v5 != nullptr )
        {
          physcollision->CollideGetAABB(
            this: physcollision,
            a2: &mins,
            a3: &maxs,
            a4: *v5->solids,
            a5: &vec3_origin,
            a6: &vec3_angle);
          p_maxs = &v4->maxs;
          v8 = &v4->maxs;
          p_mins = &v4->mins;
          AddPointToBounds(v: &mins, mins: p_mins, maxs: v8);
          AddPointToBounds(v: &maxs, mins: p_mins, maxs: p_maxs);
        }
      }
    }
    else
    {
      CMDLCacheNotify::SetBoundsFromStudioHdr(this, pModel: v4, handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED100
// Name: void InitStudioModelState(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitStudioModelState(model_t *pModel)
{
  int studio; // edi
  model_t *v2; // eax
  int v3; // edi
  model_t *v4; // eax
  int v5; // edi
  model_t *v6; // eax
  model_t *v7; // esi
  vcollide_t *v8; // eax
  Vector *p_maxs; // edi
  Vector *p_mins; // esi
  Vector *v11; // [esp-4h] [ebp-24h]
  Vector v12; // [esp+8h] [ebp-18h] BYREF
  Vector v; // [esp+14h] [ebp-Ch] BYREF

  if ( ((unsigned __int8 (__stdcall *)(_DWORD, _DWORD))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 0) != 0 )
  {
    studio = pModel->studio;
    v2 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: studio);
    if ( v2 != nullptr )
      CMDLCacheNotify::SetBoundsFromStudioHdr(this: &s_MDLCacheNotify, pModel: v2, handle: studio);
  }
  if ( ((unsigned __int8 (__stdcall *)(_DWORD, int))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 1) != 0 )
  {
    v3 = pModel->studio;
    v4 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: v3);
    if ( v4 != nullptr )
      CMDLCacheNotify::ComputeModelFlags(this: &s_MDLCacheNotify, pModel: v4, handle: v3);
  }
  if ( ((unsigned __int8 (__stdcall *)(_DWORD, int))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 2) != 0 )
  {
    v5 = pModel->studio;
    v6 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: v5);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CMDLCacheNotify::SetBoundsFromStudioHdr(this: &s_MDLCacheNotify, pModel: v6, handle: v5);
      v8 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: v5);
      if ( v8 != nullptr )
      {
        physcollision->CollideGetAABB(
          this: physcollision,
          a2: &v,
          a3: &v12,
          a4: *v8->solids,
          a5: &vec3_origin,
          a6: &vec3_angle);
        p_maxs = &v7->maxs;
        v11 = &v7->maxs;
        p_mins = &v7->mins;
        AddPointToBounds(&v, mins: p_mins, maxs: v11);
        AddPointToBounds(v: &v12, mins: p_mins, maxs: p_maxs);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED240
// Name: private: static void CResourcePreloadModel::QueuedLoaderMapCallback(void __near *,void __near *,void const __near *,int,enum LoaderError_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CResourcePreloadModel::QueuedLoaderMapCallback(
        model_t *pContext,
        void *pContext2,
        void *pData,
        int nSize,
        LoaderError_t loaderError)
{
  if ( loaderError == LOADERERROR_NONE )
    CMapLoadHelper::InitFromMemory(pMapModel: pContext, pData, nDataSize: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x100ED260
// Name: private: virtual void CResourcePreloadModel::OnEndMapLoading(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CResourcePreloadModel::OnEndMapLoading(CResourcePreloadModel *this, bool bAbort)
{
  CMapLoadHelper::Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x100ED270
// Name: public: virtual int CModelLoader::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetCount(CModelLoader *this)
{
  return this->m_Models.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x100ED280
// Name: public: virtual bool CBrushBSPIterator::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushBSPIterator::EnumerateLeaf(CBrushBSPIterator *this, int leaf, int __formal)
{
  CBrushBSPIterator::MarkModelSurfaces(
    this,
    flags: this->m_pShared->leafs[leaf].leafWaterDataID != -1 ? 0x20000 : 0x40000);
  ++this->m_count;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ED2C0
// Name: private: void CModelLoader::Map_LoadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_LoadModel(CModelLoader *this, model_t *mod)
{
  IEngineVGuiInternal *v3; // eax
  CStatTime *v4; // ecx
  CStatTime *v5; // ecx
  double v6; // st7
  double v7; // [esp+14h] [ebp-8h]

  v3 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, int))v3->UpdateProgressBar)(a1: v3, a2: 3);
  _COM_TimestampedLog(a1: "Map_LoadModel: Start");
  v7 = _Plat_FloatTime(this: v4);
  this->m_pWorldModel = mod;
  mod->nLoadFlags |= 1u;
  mod->type = mod_brush;
  mod->sprite.numframes = (int)&this->m_worldBrushData;
  mod->brush.renderHandle = 0;
  CMapLoadHelper::Init(
    a1: (int)_COM_TimestampedLog,
    a2: (int)this,
    p_lumpHeader: (lumpfileheader_t *)mod,
    pMapModel: mod,
    pPathName: mod->szPathName);
  CModelLoader::Map_LoadModelGuts(this, mod);
  CMapLoadHelper::Shutdown();
  v6 = _Plat_FloatTime(this: v5);
  _COM_TimestampedLog(a1: "Map_LoadModel: Finish - loading took %.4f seconds", v6 - v7);
}

//------------------------------------------------------------------------------
// Address: 0x100ED360
// Name: private: void CModelLoader::Studio_LoadModel(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::Studio_LoadModel(
        CModelLoader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        model_t *pModel,
        int bTouchAllData)
{
  int nLoadFlags; // eax
  bool v8; // bl
  int v9; // eax
  CStatTime *v10; // ecx
  studiohdr_t *v11; // esi
  CStatTime *v12; // ecx
  double v13; // st7
  CStatTime *v14; // ecx
  int v15; // ebx
  int v16; // esi
  bool v17; // zf
  double v18; // st7
  int ServerCount; // eax
  IMaterial *pMaterials[128]; // [esp+0h] [ebp-208h] BYREF
  double t1; // [esp+200h] [ebp-8h]
  unsigned __int8 bPreLoaded_3; // [esp+213h] [ebp+Bh]

  if ( mod_touchalldata.m_pParent == nullptr || mod_touchalldata.m_pParent->m_Value.m_nValue == 0 )
    LOBYTE(bTouchAllData) = 0;
  nLoadFlags = pModel->nLoadFlags;
  bPreLoaded_3 = BYTE2(nLoadFlags) & 1;
  v8 = nLoadFlags != 16;
  pModel->nLoadFlags = nLoadFlags & 0xFFFEFFFE | 1;
  if ( (nLoadFlags & 0x10000) == 0 )
  {
    v9 = ((int (__thiscall *)(IMDLCache *, char *))g_pMDLCache->FindMDL)(a1: g_pMDLCache, a2: pModel->szPathName);
    pModel->studio = v9;
    g_pMDLCache->SetUserData(this: g_pMDLCache, a2: v9, a3: pModel);
    InitStudioModelState(pModel);
  }
  v11 = (studiohdr_t *)((int (__stdcall *)(_DWORD, int, int, int))g_pMDLCache->GetStudioHdr)(
                         a1: pModel->studio,
                         a2: a3,
                         a3: a4,
                         a4: a2);
  if ( v8 && bPreLoaded_3 == 0 )
  {
    t1 = _Plat_FloatTime(this: v10);
    ((void (__stdcall *)(_DWORD, int))g_pMDLCache->GetVCollideEx)(a1: pModel->studio, a2: bTouchAllData);
    v13 = _Plat_FloatTime(this: v12) - t1;
    if ( (_BYTE)bTouchAllData != 0 )
      g_flAccumulatedModelLoadTimeVCollideSync = v13 + g_flAccumulatedModelLoadTimeVCollideSync;
    else
      g_flAccumulatedModelLoadTimeVCollideAsync = v13 + g_flAccumulatedModelLoadTimeVCollideAsync;
  }
  t1 = _Plat_FloatTime(this: v10);
  v15 = g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v11, a3: 128, a4: pMaterials);
  v16 = 0;
  v17 = v15 == 0;
  if ( v15 > 0 )
  {
    do
    {
      pMaterials[v16]->IncrementReferenceCount(this: pMaterials[v16]);
      ++v16;
    }
    while ( v16 < v15 );
    v17 = v15 == 0;
  }
  if ( !v17 )
    pModel->nLoadFlags |= 0x20000u;
  v18 = _Plat_FloatTime(this: v14);
  g_flAccumulatedModelLoadTimeMaterialNamesOnly = v18 - t1 + g_flAccumulatedModelLoadTimeMaterialNamesOnly;
  if ( __PAIR16__(bTouchAllData, bPreLoaded_3) != 0 )
  {
    ServerCount = Host_GetServerCount();
    Mod_TouchAllData(pModel, nServerCount: ServerCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED4E0
// Name: public: virtual void CModelLoader::Map_LoadDisplacements(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::Map_LoadDisplacements(
        CModelLoader *this@<ecx>,
        int a2@<ebx>,
        model_t *pModel,
        bool bRestoring)
{
  if ( pModel != nullptr )
  {
    V_FileBase(in: pModel->szPathName, out: this->m_szBaseName, maxlen: 64);
    CMapLoadHelper::Init(
      a1: a2,
      a2: (int)pModel->szPathName,
      p_lumpHeader: (lumpfileheader_t *)pModel,
      pMapModel: pModel,
      pPathName: pModel->szPathName);
    DispInfo_LoadDisplacements(pWorld: pModel, bRestoring);
    CMapLoadHelper::Shutdown();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED9C0
// Name: void Mod_LoadCubemapSamples(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Mod_LoadCubemapSamples(int a1@<edi>)
{
  char *m_szLumpFilename; // eax
  unsigned int m_nLumpSize; // ebx
  unsigned __int8 *m_pData; // edi
  int v4; // ebx
  bool v5; // zf
  char *v6; // eax
  const char *v7; // eax
  mcubemapsample_t *v8; // esi
  worldbrushdata_t *v9; // eax
  HDRType_t (__thiscall *GetHDRType)(IMaterialSystemHardwareConfig *); // edx
  float *p_pTexture; // esi
  unsigned int *v12; // edi
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  ITexture *v15; // eax
  ITexture *v16; // eax
  const char *v17; // eax
  IMatRenderContext *v18; // eax
  IMatRenderContext *v19; // edi
  int v20; // eax
  int v21; // eax
  ITexture *v22; // esi
  char *v24; // [esp-Ch] [ebp-444h]
  char textureName[512]; // [esp+0h] [ebp-438h] BYREF
  char loadName[260]; // [esp+200h] [ebp-238h] BYREF
  CMapLoadHelper lh; // [esp+304h] [ebp-134h] BYREF
  int count; // [esp+42Ch] [ebp-Ch]
  int v29; // [esp+430h] [ebp-8h]
  char *pHDRExtension; // [esp+434h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x2Au, bUncompress: true);
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  V_StripExtension(in: m_szLumpFilename, out: loadName, outSize: 260);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 0xF) != 0 )
  {
    Host_Error(error: "Mod_LoadCubemapSamples: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v4 = m_nLumpSize >> 4;
  v5 = s_MapLumpFiles[lh.m_nLumpID].file == nullptr;
  count = v4;
  v6 = lh.m_szLumpFilename;
  if ( v5 )
    v6 = s_szMapPathName;
  v7 = va(format: "%s [%s]", v6, "cubemapsample");
  v8 = (mcubemapsample_t *)Hunk_AllocName(size: 20 * v4, name: v7, bClear: true);
  v9 = s_pMap;
  s_pMap->m_pCubemapSamples = v8;
  v9->m_nCubemapSamples = v4;
  GetHDRType = g_pMaterialSystemHardwareConfig->GetHDRType;
  pHDRExtension = (char *)defaultValue;
  if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))GetHDRType)(
         a1: g_pMaterialSystemHardwareConfig,
         a2: a1) != 0 )
    pHDRExtension = ".hdr";
  if ( v4 > 0 )
  {
    p_pTexture = (float *)&v8->pTexture;
    v29 = v4;
    v12 = (unsigned int *)(m_pData + 8);
    do
    {
      v13 = _mm_cvtsi32_si128(*v12);
      v14 = _mm_cvtsi32_si128(*(v12 - 2));
      v24 = pHDRExtension;
      *(p_pTexture - 2) = (float)(int)*(v12 - 1);
      *((_DWORD *)p_pTexture - 1) = _mm_cvtepi32_ps(v13).m128_u32[0];
      *((_DWORD *)p_pTexture - 3) = _mm_cvtepi32_ps(v14).m128_u32[0];
      *((_BYTE *)p_pTexture + 4) = *((_BYTE *)v12 + 4);
      V_snprintf(
        pDest: textureName,
        maxLen: 512,
        pFormat: "%s/c%d_%d_%d%s",
        loadName,
        *(v12 - 2),
        *(v12 - 1),
        *v12,
        v24);
      v15 = materials->FindTexture(this: materials, a2: textureName, a3: "CubeMap textures", a4: 1, a5: 0);
      *(_DWORD *)p_pTexture = v15;
      if ( v15 == nullptr || v15->IsError(this: v15) )
      {
        if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
        {
          _Warning(a1: "Couldn't get HDR '%s' -- ", textureName);
          V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/c%d_%d_%d", loadName, *(v12 - 2), *(v12 - 1), *v12);
          _Warning(a1: "Trying non HDR '%s'\n", textureName);
          *(_DWORD *)p_pTexture = materials->FindTexture(
                                    this: materials,
                                    a2: textureName,
                                    a3: "CubeMap textures",
                                    a4: 1,
                                    a5: 0);
        }
        if ( *(_DWORD *)p_pTexture == 0
          || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)p_pTexture + 60))(a1: *(_DWORD *)p_pTexture) != 0 )
        {
          V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/cubemapdefault", loadName);
          v16 = materials->FindTexture(this: materials, a2: textureName, a3: "CubeMap textures", a4: 1, a5: 0);
          *(_DWORD *)p_pTexture = v16;
          if ( v16 == nullptr || v16->IsError(this: v16) )
            *(_DWORD *)p_pTexture = materials->FindTexture(
                                      this: materials,
                                      a2: "engine/defaultcubemap",
                                      a3: "CubeMap textures",
                                      a4: 1,
                                      a5: 0);
          v17 = (const char *)(***(int (__thiscall ****)(_DWORD))p_pTexture)(a1: *(_DWORD *)p_pTexture);
          _Warning(a1: "Failed, using default cubemap '%s'\n", v17);
        }
      }
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)p_pTexture + 40))(a1: *(_DWORD *)p_pTexture);
      v12 += 4;
      p_pTexture += 5;
      --v29;
    }
    while ( v29 != 0 );
    v4 = count;
  }
  v18 = materials->GetRenderContext(this: materials);
  v19 = v18;
  if ( v18 != nullptr )
    v18->BeginRender(this: v18);
  if ( v4 != 0 )
  {
    v19->BindLocalCubemap(this: v19, a2: s_pMap->m_pCubemapSamples->pTexture);
  }
  else
  {
    v20 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(
           a1: v20,
           a2: "-requirecubemaps",
           a3: 0) != 0 )
      Sys_Error(error: "Map \"%s\" does not have cubemaps!", s_szMapPathName);
    V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/cubemapdefault", loadName);
    v21 = ((int (__thiscall *)(IMaterialSystem *, char *, const char *))materials->FindTexture)(
            a1: materials,
            a2: textureName,
            a3: "CubeMap textures");
    v22 = (ITexture *)v21;
    if ( v21 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v21 + 60))(a1: v21) != 0 )
      v22 = materials->FindTexture(this: materials, a2: "engine/defaultcubemap", a3: "CubeMap textures", a4: 1, a5: 0);
    v22->IncrementReferenceCount(this: v22);
    v19->BindLocalCubemap(this: v19, a2: v22);
  }
  v19->EndRender(this: v19);
  v19->Release(this: v19);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EDDD0
// Name: public: virtual struct model_t __near * CModelLoader::GetModelForIndex(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::GetModelForIndex(CModelLoader *this, int i)
{
  if ( i < 0 || i >= (unsigned int)this->m_Models.m_Tree.m_NumElements )
    return nullptr;
  else
    return this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.modelpointer;
}

//------------------------------------------------------------------------------
// Address: 0x100EDE00
// Name: private: struct model_t __near * CModelLoader::LoadModel(struct model_t __near *,enum IModelLoader::REFERENCETYPE __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
model_t *__thiscall CModelLoader::LoadModel(
        CModelLoader *this,
        model_t *mod,
        IModelLoader::REFERENCETYPE *pReferencetype)
{
  char v3; // bl
  int ServerCount; // eax
  CStatTime *v5; // ecx
  int v6; // edi
  CModelLoader *v8; // ebx
  const char *v9; // edi
  modtype_t TypeFromName; // eax
  ConVar *m_pParent; // ecx
  IMDLCache *v12; // edi
  CStatTime *v13; // ecx
  CStatTime *v14; // ecx
  IMDLCache *v15; // edi
  CStatTime *v16; // ecx
  CStatTime *v17; // ecx
  vgui::PropertyPage *v18; // ecx
  CStatTime *v19; // ecx
  double v20; // st7
  double v21; // st7
  double v22; // st7
  char string[24]; // [esp+14h] [ebp-218h] BYREF
  char szExcludePath[260]; // [esp+2Ch] [ebp-200h] BYREF
  __int128 szNameOnDisk_236; // [esp+21Ch] [ebp-10h] OVERLAPPED
  float st_4; // [esp+238h] [ebp+Ch]

  HIDWORD(szNameOnDisk_236) = this;
  if ( pReferencetype != nullptr )
    mod->nLoadFlags |= *pReferencetype;
  v3 = 0;
  LOBYTE(pReferencetype) = 0;
  ServerCount = Host_GetServerCount();
  v6 = ServerCount;
  if ( mod->nServerCount != ServerCount )
  {
    v3 = 1;
    mod->nServerCount = ServerCount;
    LOBYTE(pReferencetype) = 1;
  }
  if ( mod->type != mod_studio || (mod->nLoadFlags & 0x10000) != 0 )
  {
    if ( (mod->nLoadFlags & 1) == 0 )
    {
      *(double *)&szNameOnDisk_236 = _Plat_FloatTime(this: v5);
      v8 = (CModelLoader *)HIDWORD(szNameOnDisk_236);
      v9 = (const char *)(HIDWORD(szNameOnDisk_236) + 368);
      V_FileBase(in: mod->szPathName, out: (char *)(HIDWORD(szNameOnDisk_236) + 368), maxlen: 64);
      if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "Loading: %s\n", mod->szPathName);
      TypeFromName = CModelLoader::GetTypeFromName(
                       this: (CModelLoader *)HIDWORD(szNameOnDisk_236),
                       pModelName: mod->szPathName);
      mod->type = TypeFromName;
      m_pParent = developer.m_pParent;
      if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "Loading type: %d\n", TypeFromName);
      if ( mod->type == mod_bad )
        mod->type = mod_studio;
      switch ( mod->type )
      {
        case mod_brush:
          *((double *)&szNameOnDisk_236 + 1) = _Plat_FloatTime(this: (CStatTime *)m_pParent);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading brush, compacting heap...\n");
          _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
          if ( mod->szPathName != &szExcludePath[236] )
            V_strncpy(pDest: &szExcludePath[236], pSrc: mod->szPathName, maxLen: 260);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: %s\n", &szExcludePath[236]);
          g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: &szExcludePath[236], a3: "GAME", a4: PATH_ADD_TO_HEAD);
          if ( mat_excludetextures.m_pParent != nullptr && mat_excludetextures.m_pParent->m_Value.m_nValue != 0 )
          {
            sprintf(string, format: "//MOD/maps/%s_exclude.lst", v9);
            if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
              DevMsg(a1: "Setting excluded textures: %s\n", string);
            g_pMaterialSystem->SetExcludedTextures(this: g_pMaterialSystem, a2: string);
          }
          NotifyHunkBeginMapLoad(pszMapName: v9);
          if ( mat_excludetextures.m_pParent != nullptr && mat_excludetextures.m_pParent->m_Value.m_nValue != 0 )
            g_pMaterialSystem->UpdateExcludedTextures(this: g_pMaterialSystem);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: BeginLoadingUpdates...\n");
          CColorBalanceUIPanel::Init(this: v18);
          g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: Map_LoadModel...\n");
          CModelLoader::Map_LoadModel(this: v8, mod);
          g_pFileSystem->EndMapAccess(this: g_pFileSystem);
          v20 = _Plat_FloatTime(this: v19);
          g_flAccumulatedModelLoadTimeBrush = v20
                                            - *((double *)&szNameOnDisk_236 + 1)
                                            + g_flAccumulatedModelLoadTimeBrush;
          break;
        case mod_sprite:
          v15 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          *((double *)&szNameOnDisk_236 + 1) = _Plat_FloatTime(this: v16);
          CModelLoader::Sprite_LoadModel(this: v8, mod);
          g_flAccumulatedModelLoadTimeSprite = _Plat_FloatTime(this: v17)
                                             - *((double *)&szNameOnDisk_236 + 1)
                                             + g_flAccumulatedModelLoadTimeSprite;
          v15->EndLock(this: v15);
          break;
        case mod_studio:
          v12 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          *((double *)&szNameOnDisk_236 + 1) = _Plat_FloatTime(this: v13);
          CModelLoader::Studio_LoadModel(
            this: v8,
            a2: (int)v8,
            a3: (int)v12,
            a4: (int)mod,
            pModel: mod,
            bTouchAllData: (int)pReferencetype);
          g_flAccumulatedModelLoadTimeStudio = _Plat_FloatTime(this: v14)
                                             - *((double *)&szNameOnDisk_236 + 1)
                                             + g_flAccumulatedModelLoadTimeStudio;
          v12->EndLock(this: v12);
          break;
        default:
          break;
      }
      v21 = _Plat_FloatTime(this: (CStatTime *)m_pParent);
      v22 = v21 - *(double *)&szNameOnDisk_236;
      st_4 = v22;
      _COM_TimestampedLog(a1: "Load of %s took %.3f msec", mod->szPathName, v22 * 1000.0);
      g_flAccumulatedModelLoadTime = st_4 + g_flAccumulatedModelLoadTime;
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: mod->studio);
    if ( v3 != 0 )
    {
      Mod_TouchAllData(pModel: mod, nServerCount: v6);
      return mod;
    }
  }
  return mod;
}

//------------------------------------------------------------------------------
// Address: 0x100EE1A0
// Name: public: virtual void CModelLoader::UnreferenceAllModels(enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnreferenceAllModels(CModelLoader *this, IModelLoader::REFERENCETYPE referencetype)
{
  int m_NumElements; // ebx
  int v4; // edi

  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  v4 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
      this->UnreferenceModel(
        this,
        a2: this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4++].m_Data.elem.modelpointer,
        a3: referencetype);
    while ( v4 < m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE1E0
// Name: public: virtual void CModelLoader::ReloadFilesInList(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::ReloadFilesInList(
        CModelLoader *this@<ecx>,
        int studio@<edi>,
        int a3@<esi>,
        IFileList *pFilesToReload)
{
  CModelLoader *v4; // ebx
  int m_NumElements; // ecx
  int v6; // eax
  model_t *modelpointer; // esi
  IMDLCache *v8; // edi
  studiohdr_t *v9; // eax
  int v10; // ebx
  int v11; // edi
  IMaterial *v12; // ecx
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-20Ch] BYREF
  int c; // [esp+204h] [ebp-Ch]
  int i; // [esp+208h] [ebp-8h]
  CModelLoader *v18; // [esp+20Ch] [ebp-4h]

  v4 = this;
  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  LOWORD(v6) = 0;
  v18 = v4;
  c = m_NumElements;
  i = 0;
  if ( m_NumElements != 0 )
  {
    do
    {
      modelpointer = v4->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v6].m_Data.elem.modelpointer;
      if ( modelpointer->type == mod_studio
        && v4->IsLoaded(this: v4, a2: modelpointer)
        && modelpointer->type == mod_studio )
      {
        if ( ((int (__thiscall *)(IFileList *, char *, int, int))pFilesToReload->IsFileInList)(
               a1: pFilesToReload,
               a2: modelpointer->szPathName,
               a3: studio,
               a4: a3) != 0 )
        {
          a3 = 2147483643;
          studio = modelpointer->studio;
          ((void (*)(void))g_pMDLCache->Flush)();
          v8 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
          ((void (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: modelpointer->studio);
          v8->EndLock(this: v8);
        }
        else
        {
          a3 = 1;
          studio = modelpointer->studio;
          if ( ((unsigned __int8 (*)(void))g_pMDLCache->IsDataLoaded)() != 0 )
          {
            v9 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
            if ( v9 != nullptr )
            {
              v10 = g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v9, a3: 128, a4: pMaterials);
              v11 = 0;
              if ( v10 > 0 )
              {
                while ( 1 )
                {
                  v12 = pMaterials[v11];
                  if ( v12 != nullptr && v12->WasReloadedFromWhitelist(this: v12) )
                    break;
                  if ( ++v11 >= v10 )
                    goto LABEL_15;
                }
                ((void (__stdcall *)(_DWORD, int))g_pMDLCache->Flush)(a1: modelpointer->studio, a2: 2);
              }
LABEL_15:
              v4 = v18;
            }
          }
        }
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE370
// Name: public: virtual void CModelLoader::Studio_ReloadModels(enum IModelLoader::ReloadType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Studio_ReloadModels(CModelLoader *this, IModelLoader::ReloadType_t reloadType)
{
  CModelLoader *v2; // esi
  int v3; // ebx
  model_t *modelpointer; // edi
  IMDLCache *v5; // esi
  int c; // [esp+8h] [ebp-8h]

  v2 = this;
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  if ( serverGameDLL != nullptr )
    serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  modelrender->RemoveAllDecalsFromAllModels(this: modelrender);
  modelrender->ReleaseAllStaticPropColorData(this: modelrender);
  g_pMDLCache->Flush_2(this: g_pMDLCache, a2: (MDLCacheFlush_t)2147483643);
  v3 = 0;
  c = v2->m_Models.m_Tree.m_NumElements;
  if ( v2->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      modelpointer = v2->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( v2->IsLoaded(this: v2, a2: modelpointer) && modelpointer->type == mod_studio )
      {
        v5 = g_pMDLCache;
        g_pMDLCache->BeginLock(this: g_pMDLCache);
        ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
        ((void (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: modelpointer->studio);
        v5->EndLock(this: v5);
        v2 = this;
      }
      ++v3;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE460
// Name: public: virtual void CModelLoader::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Print(CModelLoader *this)
{
  CModelLoader *v1; // esi
  int v2; // edi
  model_t *modelpointer; // esi
  modtype_t type; // eax
  int v5; // eax
  int c; // [esp+Ch] [ebp-8h]

  v1 = this;
  ConMsg(a1: "Models:\n");
  v2 = 0;
  c = v1->m_Models.m_Tree.m_NumElements;
  if ( v1->m_Models.m_Tree.m_NumElements != 0 )
  {
    while ( 1 )
    {
      modelpointer = v1->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v2].m_Data.elem.modelpointer;
      type = modelpointer->type;
      if ( type == mod_studio )
      {
        v5 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetRef)(a1: modelpointer->studio);
      }
      else
      {
        if ( type != mod_bad )
        {
          ConMsg(a1: "%4d: Flags:0x%8.8x %s\n", v2, modelpointer->nLoadFlags, modelpointer->szPathName);
          goto LABEL_10;
        }
        v5 = 0;
      }
      ConMsg(a1: "%4d: Flags:0x%8.8x RefCount:%2d %s\n", v2, modelpointer->nLoadFlags, v5, modelpointer->szPathName);
LABEL_10:
      if ( ++v2 >= c )
        return;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF0E0
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF160
// Name: void Mod_LoadOcclusion(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadOcclusion()
{
  worldbrushdata_t *v0; // eax
  int *p_numoccluderpolys; // ecx
  int *p_numoccluders; // esi
  doccluderpolydata_t **p_occluderpolys; // edi
  doccluderdata_t **p_occluders; // ebx
  int v5; // eax
  int v6; // esi
  unsigned __int8 *v7; // eax
  int Int; // eax
  doccluderdata_t *v9; // eax
  bool v10; // cc
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  unsigned __int8 *v15; // eax
  int v16; // eax
  int v17; // esi
  unsigned __int8 *v18; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-198h] BYREF
  doccluderdataV1_t temp; // [esp+134h] [ebp-70h] BYREF
  CUtlBuffer buf; // [esp+158h] [ebp-4Ch] BYREF
  doccluderpolydata_t **v22; // [esp+188h] [ebp-1Ch]
  int *v23; // [esp+18Ch] [ebp-18h]
  int i; // [esp+190h] [ebp-14h]
  int *v25; // [esp+194h] [ebp-10h]
  int *p_numoccludervertindices; // [esp+198h] [ebp-Ch]
  _DWORD *p_occludervertindices; // [esp+19Ch] [ebp-8h]
  int v28; // [esp+1A0h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 9u, bUncompress: true);
  v0 = s_pMap;
  p_numoccluderpolys = &s_pMap->numoccluderpolys;
  p_numoccluders = &s_pMap->numoccluders;
  p_occluderpolys = &s_pMap->occluderpolys;
  p_occluders = &s_pMap->occluders;
  s_pMap->numoccluderpolys = 0;
  v25 = p_numoccluderpolys;
  *p_numoccluders = 0;
  *p_occluders = nullptr;
  *p_occluderpolys = nullptr;
  v0->numoccludervertindices = 0;
  p_occludervertindices = &v0->occludervertindices;
  v0->occludervertindices = nullptr;
  v23 = p_numoccluders;
  v22 = p_occluderpolys;
  p_numoccludervertindices = &v0->numoccludervertindices;
  if ( lh.m_nLumpSize == 0 )
    goto LABEL_21;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: lh.m_pData, nSize: lh.m_nLumpSize, nFlags: 8u);
  if ( lh.m_nLumpVersion != 0 )
  {
    if ( lh.m_nLumpVersion == 1 )
    {
      Int = CUtlBuffer::GetInt(this: &buf);
      *p_numoccluders = Int;
      if ( Int != 0 )
      {
        v9 = (doccluderdata_t *)Hunk_AllocName(size: 40 * Int, name: "occluder data", bClear: true);
        v10 = *p_numoccluders <= 0;
        *p_occluders = v9;
        i = 0;
        if ( !v10 )
        {
          v28 = 0;
          do
          {
            CUtlBuffer::Get(this: &buf, pMem: (unsigned __int8 *)&temp, size: 36);
            v11 = i;
            *(doccluderdataV1_t *)((char *)&(*p_occluders)->flags + v28) = temp;
            v12 = v28;
            *(int *)((char *)&(*p_occluders)->area + v28) = 1;
            v28 = v12 + 40;
            i = v11 + 1;
          }
          while ( v11 + 1 < *v23 );
          p_occluderpolys = v22;
        }
      }
    }
    else
    {
      if ( lh.m_nLumpVersion != 2 )
      {
        Host_Error(error: "Invalid occlusion lump version!\n");
        goto LABEL_17;
      }
      v5 = CUtlBuffer::GetInt(this: &buf);
      *p_numoccluders = v5;
      if ( v5 != 0 )
      {
        v6 = 40 * v5;
        v7 = (unsigned __int8 *)Hunk_AllocName(size: 40 * v5, name: "occluder data", bClear: true);
        *p_occluders = (doccluderdata_t *)v7;
        CUtlBuffer::Get(this: &buf, pMem: v7, size: v6);
      }
    }
    v13 = CUtlBuffer::GetInt(this: &buf);
    *v25 = v13;
    if ( v13 != 0 )
    {
      v14 = 12 * v13;
      v15 = (unsigned __int8 *)Hunk_AllocName(size: 12 * v13, name: "occluder poly data", bClear: true);
      *p_occluderpolys = (doccluderpolydata_t *)v15;
      CUtlBuffer::Get(this: &buf, pMem: v15, size: v14);
    }
    v16 = CUtlBuffer::GetInt(this: &buf);
    *p_numoccludervertindices = v16;
    if ( v16 != 0 )
    {
      v17 = 4 * v16;
      v18 = (unsigned __int8 *)Hunk_AllocName(size: 4 * v16, name: "occluder vertices", bClear: true);
      *p_occludervertindices = v18;
      CUtlBuffer::Get(this: &buf, pMem: v18, size: v17);
    }
  }
LABEL_17:
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
LABEL_21:
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EF5D0
// Name: void Mod_LoadGameLumpDict(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadGameLumpDict()
{
  int v0; // ebx
  unsigned __int8 *m_pRawData; // eax
  bool v2; // zf
  unsigned __int8 *v3; // edi
  int m_Size; // ecx
  int v5; // esi
  dgamelump_t *v6; // esi
  CMapLoadHelper lh; // [esp+4h] [ebp-12Ch] BYREF
  dgamelumpheader_t *pGameLumpHeader; // [esp+12Ch] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x23u, bUncompress: true);
  v0 = 0;
  g_GameLumpDict.m_Size = 0;
  V_strncpy(pDest: g_GameLumpFilename, pSrc: s_szMapPathName, maxLen: 260);
  if ( lh.m_nLumpSize != 0 )
  {
    pGameLumpHeader = (dgamelumpheader_t *)lh.m_pData;
    v3 = lh.m_pData + 4;
    if ( *(int *)lh.m_pData > 0 )
    {
      m_Size = g_GameLumpDict.m_Size;
      do
      {
        v5 = m_Size;
        if ( m_Size + 1 > g_GameLumpDict.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_GameLumpDict,
            num: m_Size - g_GameLumpDict.m_Memory.m_nAllocationCount + 1);
          m_Size = g_GameLumpDict.m_Size;
        }
        g_GameLumpDict.m_Size = ++m_Size;
        g_GameLumpDict.m_pElements = g_GameLumpDict.m_Memory.m_pMemory;
        if ( m_Size - v5 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_GameLumpDict.m_Memory.m_pMemory[v5 + 1],
            src: &g_GameLumpDict.m_Memory.m_pMemory[v5],
            count: 16 * (m_Size - v5 - 1));
          m_Size = g_GameLumpDict.m_Size;
        }
        v6 = &g_GameLumpDict.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          v6->id = *(_DWORD *)v3;
          *(_DWORD *)&v6->flags = *((_DWORD *)v3 + 1);
          v6->fileofs = *((_DWORD *)v3 + 2);
          v6->filelen = *((_DWORD *)v3 + 3);
          m_Size = g_GameLumpDict.m_Size;
        }
        ++v0;
        v3 += 16;
      }
      while ( v0 < pGameLumpHeader->lumpCount );
    }
    m_pRawData = lh.m_pRawData;
    v2 = lh.m_pRawData == nullptr;
  }
  else
  {
    m_pRawData = lh.m_pRawData;
    v2 = lh.m_pRawData == nullptr;
  }
  if ( !v2 )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EF700
// Name: public: virtual void CModelLoader::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Init(CModelLoader *this)
{
  CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Models.m_Tree);
  this->m_InlineModels.m_Size = 0;
  if ( this->m_InlineModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InlineModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InlineModels.m_Memory.m_pMemory);
      this->m_InlineModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_InlineModels.m_pElements = this->m_InlineModels.m_Memory.m_pMemory;
  this->m_pWorldModel = nullptr;
  *(_WORD *)&this->m_bMapRenderInfoLoaded = 0;
  g_bLoadedMapHasBakedPropLighting = false;
  this->m_worldBrushData.m_pLightingDataStack = &this->m_WorldLightingDataStack;
  CollisionBSPData_LinkPhysics();
}

//------------------------------------------------------------------------------
// Address: 0x100EF760
// Name: public: void CModelLoader::AllocateLightstyles(struct model_t __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::AllocateLightstyles(
        CModelLoader *this,
        model_t *pModel,
        unsigned __int8 *pStyles,
        int nStyleCount)
{
  unsigned __int16 m_Size; // dx
  int v5; // ebx
  CUtlMemory<char,int> *p_m_LightStyleList; // esi
  char *m_pMemory; // edi
  int m_nAllocationCount; // eax
  char *v9; // ecx
  int v10; // eax
  char *v11; // eax
  unsigned __int16 nLast; // [esp+8h] [ebp-4h]

  m_Size = this->m_LightStyleList.m_Size;
  v5 = 0;
  nLast = m_Size;
  if ( nStyleCount <= 0 )
  {
    pModel->brush.nLightstyleCount = nStyleCount;
    pModel->brush.nLightstyleIndex = m_Size;
  }
  else
  {
    p_m_LightStyleList = (CUtlMemory<char,int> *)&this->m_LightStyleList;
    do
    {
      m_pMemory = p_m_LightStyleList[1].m_pMemory;
      m_nAllocationCount = p_m_LightStyleList->m_nAllocationCount;
      if ( (int)(m_pMemory + 1) > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: p_m_LightStyleList, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
      ++p_m_LightStyleList[1].m_pMemory;
      v9 = p_m_LightStyleList->m_pMemory;
      v10 = p_m_LightStyleList[1].m_pMemory - m_pMemory - 1;
      p_m_LightStyleList[1].m_nAllocationCount = (int)p_m_LightStyleList->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: v10);
      v11 = &m_pMemory[(unsigned int)p_m_LightStyleList->m_pMemory];
      if ( v11 != nullptr )
        *v11 = pStyles[v5];
      ++v5;
    }
    while ( v5 < nStyleCount );
    pModel->brush.nLightstyleCount = nStyleCount;
    pModel->brush.nLightstyleIndex = nLast;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF810
// Name: Mod_ComputeBrushModelFlags
// Source: json
//------------------------------------------------------------------------------
void __usercall Mod_ComputeBrushModelFlags(int a1@<edi>, model_t *mod)
{
  model_t *v2; // eax
  int nummodelsurfaces; // edx
  worldbrushdata_t *pShared; // ecx
  int v5; // esi
  unsigned int v6; // eax
  int v7; // edi
  int v8; // ebx
  char *v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // bl
  int m_Size; // ecx
  int v13; // eax
  unsigned __int8 *m_pMemory; // edi
  int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // esi
  int v18; // ecx
  model_t *v19; // eax
  unsigned __int8 *v21; // [esp-8h] [ebp-38h]
  int v22; // [esp-4h] [ebp-34h]
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > lightStyles; // [esp+4h] [ebp-2Ch] BYREF
  int scount; // [esp+18h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-14h]
  char *v26; // [esp+20h] [ebp-10h]
  worldbrushdata_t *pBrushData; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  bool bHasTranslucentSurfaces; // [esp+2Eh] [ebp-2h]
  bool bHasOpaqueSurfaces; // [esp+2Fh] [ebp-1h]

  v2 = mod;
  nummodelsurfaces = mod->brush.nummodelsurfaces;
  pShared = mod->brush.pShared;
  pBrushData = pShared;
  mod->flags = 32;
  scount = nummodelsurfaces;
  bHasOpaqueSurfaces = false;
  bHasTranslucentSurfaces = false;
  mod->brush.nLightstyleIndex = 0;
  mod->brush.nLightstyleCount = 0;
  memset(&lightStyles, 0, sizeof(lightStyles));
  i = 0;
  if ( nummodelsurfaces <= 0 )
    goto LABEL_43;
  while ( 2 )
  {
    v5 = (int)&pShared->surfaces2[i + v2->brush.firstmodelsurface];
    v6 = *(unsigned __int16 *)(v5 + 22);
    *(_DWORD *)v5 &= 0xFFFFADDF;
    v7 = (int)&pShared->texinfo[v6 >> 1];
    v8 = *(_DWORD *)(v7 + 76);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 84))(a1: v8, a2: a1) != 0 )
      mod->flags |= 1u;
    a1 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 96))(a1: v8) != 0 )
      mod->flags |= 0x10u;
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 132))(a1: v8) != 0 )
      *(_DWORD *)v5 |= 0x200u;
    if ( (*(_BYTE *)(v7 + 72) & 0x10) != 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8) != 0 )
    {
      mod->flags |= 2u;
      *(_DWORD *)v5 |= 0x20u;
      bHasTranslucentSurfaces = true;
    }
    else
    {
      bHasOpaqueSurfaces = true;
    }
    if ( (*(_WORD *)(v7 + 72) & 0x2000) != 0
      || (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 120))(a1: v8, a2: 0x4000000) != 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 72))(a1: v8) != 0 )
    {
      *(_DWORD *)v5 |= 0x4000u;
    }
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 72))(a1: v8) != 0 )
      *(_DWORD *)v5 |= 0x1000u;
    v9 = (char *)pBrushData->surfacelighting + ((v5 - (unsigned int)pBrushData->surfaces2) & 0xFFFFFFE0);
    v10 = (unsigned __int8 *)(v9 + 24);
    v26 = v9 + 24;
    v25 = -24 - (_DWORD)v9;
    do
    {
      v11 = *v10;
      if ( *v10 == 0xFF )
        break;
      m_Size = lightStyles.m_Size;
      v13 = 0;
      if ( lightStyles.m_Size <= 0 )
      {
        m_pMemory = lightStyles.m_Memory.m_pMemory;
      }
      else
      {
        while ( 1 )
        {
          m_pMemory = lightStyles.m_Memory.m_pMemory;
          if ( lightStyles.m_Memory.m_pMemory[v13] == v11 )
            break;
          if ( ++v13 >= lightStyles.m_Size )
            goto LABEL_29;
        }
        if ( v13 != -1 )
          goto LABEL_35;
      }
LABEL_29:
      v15 = lightStyles.m_Size;
      if ( lightStyles.m_Size + 1 > lightStyles.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<char,int> *)&lightStyles,
          num: lightStyles.m_Size - lightStyles.m_Memory.m_nAllocationCount + 1);
        m_Size = lightStyles.m_Size;
        m_pMemory = lightStyles.m_Memory.m_pMemory;
      }
      v16 = m_Size + 1;
      lightStyles.m_Size = v16;
      lightStyles.m_pElements = m_pMemory;
      if ( v16 - v15 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: v16 - v15 - 1);
      v17 = &m_pMemory[v15];
      if ( v17 != nullptr )
        *v17 = v11;
LABEL_35:
      v10 = (unsigned __int8 *)(v26 + 1);
      v18 = (int)&(++v26)[v25];
    }
    while ( v18 < 4 );
    if ( ++i < scount )
    {
      v2 = mod;
      pShared = pBrushData;
      continue;
    }
    break;
  }
  if ( bHasOpaqueSurfaces && bHasTranslucentSurfaces )
  {
    v19 = mod;
    mod->flags |= 8u;
  }
  else
  {
    v19 = mod;
  }
  if ( lightStyles.m_Size != 0 )
  {
    v22 = lightStyles.m_Size;
    v21 = lightStyles.m_Memory.m_pMemory;
    v19->brush.nLightstyleLastComputedFrame = 0;
    CModelLoader::AllocateLightstyles(this: &g_ModelLoader, pModel: v19, pStyles: v21, nStyleCount: v22);
  }
LABEL_43:
  if ( lightStyles.m_Memory.m_nGrowSize >= 0 && lightStyles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lightStyles.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100EFA60
// Name: int Mod_GetMaterialCount(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GetMaterialCount(model_t *mod)
{
  model_t *v1; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_Size; // esi
  IMaterial **v5; // eax
  int v6; // edx
  IMaterial **m_pMemory; // edi
  worldbrushdata_t *pShared; // ecx
  int v9; // eax
  IMaterial *material; // ecx
  int v11; // eax
  int v12; // ebx
  IMaterial **v13; // ebx
  CUtlVector<IMaterial *,CUtlMemory<IMaterial *,int> > uniqueMaterials; // [esp+4h] [ebp-1Ch] BYREF
  int i; // [esp+18h] [ebp-8h]
  IMaterial *pMaterial; // [esp+1Ch] [ebp-4h]

  v1 = mod;
  if ( mod->type != mod_brush )
    return 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  m_Size = 0;
  uniqueMaterials.m_Memory.m_nAllocationCount = 32;
  uniqueMaterials.m_Memory.m_nGrowSize = 0;
  v5 = (IMaterial **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  v6 = 0;
  m_pMemory = v5;
  uniqueMaterials.m_Memory.m_pMemory = v5;
  uniqueMaterials.m_Size = 0;
  uniqueMaterials.m_pElements = v5;
  i = 0;
  if ( mod->brush.nummodelsurfaces > 0 )
  {
    do
    {
      pShared = v1->brush.pShared;
      v9 = (int)&pShared->surfaces2[v6 + v1->brush.firstmodelsurface];
      if ( (*(_BYTE *)v9 & 0x10) == 0 )
      {
        material = pShared->texinfo[*(unsigned __int16 *)(v9 + 22) >> 1].material;
        v11 = 0;
        pMaterial = material;
        if ( m_Size <= 0 )
          goto LABEL_10;
        while ( m_pMemory[v11] != material )
        {
          if ( ++v11 >= m_Size )
            goto LABEL_10;
        }
        if ( v11 < 0 )
        {
LABEL_10:
          v12 = m_Size;
          if ( m_Size + 1 > uniqueMaterials.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&uniqueMaterials,
              num: m_Size - uniqueMaterials.m_Memory.m_nAllocationCount + 1);
            m_Size = uniqueMaterials.m_Size;
            m_pMemory = uniqueMaterials.m_Memory.m_pMemory;
            material = pMaterial;
          }
          uniqueMaterials.m_Size = ++m_Size;
          uniqueMaterials.m_pElements = m_pMemory;
          if ( m_Size - v12 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * (m_Size - v12 - 1));
            material = pMaterial;
          }
          v13 = &m_pMemory[v12];
          if ( v13 != nullptr )
            *v13 = material;
          v1 = mod;
        }
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < v1->brush.nummodelsurfaces );
  }
  if ( uniqueMaterials.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100EFBA0
// Name: public: virtual void CModelLoader::RecomputeSurfaceFlags(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::RecomputeSurfaceFlags(CModelLoader *this, model_t *mod)
{
  worldbrushdata_t *pShared; // eax
  int v4; // ebx
  model_t *v5; // esi
  worldbrushdata_t *v6; // eax
  CBrushBSPIterator v7; // [esp+8h] [ebp-1Ch] BYREF
  model_t *pModel; // [esp+1Ch] [ebp-8h]
  CModelLoader *v9; // [esp+20h] [ebp-4h]
  model_t *moda; // [esp+2Ch] [ebp+8h]

  pShared = mod->brush.pShared;
  v4 = 0;
  v9 = this;
  if ( pShared->numsubmodels > 0 )
  {
    moda = nullptr;
    do
    {
      v5 = (model_t *)((char *)moda + (unsigned int)v9->m_InlineModels.m_Memory.m_pMemory);
      Mod_ComputeBrushModelFlags(mod: v5);
      if ( v4 != 0 )
      {
        v6 = v5->brush.pShared;
        pModel = host_state.worldmodel;
        v7.__vftable = (CBrushBSPIterator_vtbl *)&CBrushBSPIterator::`vftable';
        v7.m_pWorld = mod;
        v7.m_pBrush = v5;
        v7.m_pShared = v6;
        v7.m_count = 0;
        CCommonHostState::SetWorldModel(this: &host_state, pModel: mod);
        g_pToolBSPTree->EnumerateLeavesInBox(this: g_pToolBSPTree, a2: &v5->mins, a3: &v5->maxs, a4: &v7, a5: (int)v5);
        if ( v7.m_count == 0 )
          CBrushBSPIterator::MarkModelSurfaces(this: &v7, flags: 0x40000);
        CCommonHostState::SetWorldModel(this: &host_state, pModel);
      }
      ++moda;
      ++v4;
    }
    while ( v4 < mod->brush.pShared->numsubmodels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFC70
// Name: private: void CModelLoader::Map_UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_UnloadModel(CModelLoader *this, model_t *mod)
{
  IOverlayMgr *v3; // eax
  int v4; // edi
  int v5; // ebx
  mtexinfo_t *v6; // eax
  CModelLoader_vtbl *v7; // eax

  mod->nLoadFlags &= ~1u;
  v3 = OverlayMgr();
  v3->UnloadOverlays(this: v3);
  DeallocateLightingData(pBrushData: &this->m_worldBrushData);
  DispInfo_ReleaseMaterialSystemObjects(pWorld: mod);
  if ( g_pSimpleWorldModel != nullptr )
    CModelLoader::UnloadModel(this, pModel: g_pSimpleWorldModel);
  if ( g_pSimpleWorldModelWater != nullptr )
    CModelLoader::UnloadModel(this, pModel: g_pSimpleWorldModelWater);
  g_pSimpleWorldModel = nullptr;
  g_pSimpleWorldModelWater = nullptr;
  CModelLoader::Map_UnloadCubemapSamples(this, mod);
  R_DecalTerm(pBrushData: &this->m_worldBrushData, term_permanent_decals: true);
  v4 = 0;
  if ( this->m_worldBrushData.hDispInfos != nullptr )
  {
    DispInfo_DeleteArray(hArray: this->m_worldBrushData.hDispInfos);
    this->m_worldBrushData.hDispInfos = nullptr;
  }
  if ( this->m_worldBrushData.numtexinfo > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->m_worldBrushData.texinfo[v5];
      if ( v6 != nullptr )
        GL_UnloadMaterial(pMaterial: v6->material);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_worldBrushData.numtexinfo );
  }
  MaterialSystem_DestroySortinfo();
  this->m_pWorldModel = nullptr;
  this->m_InlineModels.m_Size = 0;
  if ( this->m_InlineModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InlineModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InlineModels.m_Memory.m_pMemory);
      this->m_InlineModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_InlineModels.m_pElements = this->m_InlineModels.m_Memory.m_pMemory;
  memset(dst: (unsigned __int8 *)&this->m_worldBrushData, value: 0, count: sizeof(this->m_worldBrushData));
  v7 = this->__vftable;
  this->m_worldBrushData.m_pLightingDataStack = &this->m_WorldLightingDataStack;
  v7->Map_SetRenderInfoAllocated(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100EFDA0
// Name: public: int CModelLoader::FindNext(int,struct model_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::FindNext(CModelLoader *this, int iIndex, model_t **ppModel)
{
  unsigned __int16 Inorder; // si
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short> *p_m_Models; // edi
  int result; // eax

  Inorder = iIndex;
  if ( iIndex != -1 )
  {
    if ( this->m_Models.m_Tree.m_NumElements != 0 )
    {
      p_m_Models = &this->m_Models;
      if ( (unsigned __int16)iIndex < this->m_Models.m_Tree.m_Elements.m_nAllocationCount
        && (unsigned __int16)iIndex <= this->m_Models.m_Tree.m_LastAlloc.index
        && CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_Models.m_Tree,
             i: iIndex) != (_WORD)iIndex )
      {
        goto LABEL_8;
      }
    }
LABEL_10:
    *ppModel = nullptr;
    return -1;
  }
  if ( this->m_Models.m_Tree.m_NumElements == 0 )
    goto LABEL_10;
  p_m_Models = &this->m_Models;
  Inorder = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Models.m_Tree);
LABEL_8:
  *ppModel = this->m_Models.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem.modelpointer;
  result = (unsigned __int16)CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                               this: &p_m_Models->m_Tree,
                               i: Inorder);
  if ( (unsigned __int16)result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EFE40
// Name: public: void CModelLoader::UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadModel(CModelLoader *this, model_t *pModel)
{
  KeyValues *m_pKeyValues; // ecx
  char szNameOnDisk[260]; // [esp+4h] [ebp-104h] BYREF

  switch ( pModel->type )
  {
    case mod_brush:
      CModelLoader::Map_UnloadModel(this, mod: pModel);
      g_pStringTableDictionary->OnBSPFullyUnloaded(this: g_pStringTableDictionary);
      if ( pModel->szPathName != szNameOnDisk )
        V_strncpy(pDest: szNameOnDisk, pSrc: pModel->szPathName, maxLen: 260);
      g_pFileSystem->RemoveSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME");
      break;
    case mod_sprite:
      CModelLoader::Sprite_UnloadModel(this, mod: pModel);
      break;
    case mod_studio:
      CModelLoader::Studio_UnloadModel(this, pModel);
      break;
    default:
      break;
  }
  m_pKeyValues = pModel->m_pKeyValues;
  if ( m_pKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pKeyValues);
    pModel->m_pKeyValues = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFF60
// Name: public: CModelLoader::CModelLoader(void)
// Source: json
//------------------------------------------------------------------------------
CModelLoader *__thiscall CModelLoader::CModelLoader(CModelLoader *this)
{
  this->__vftable = (CModelLoader_vtbl *)&CModelLoader::`vftable';
  this->m_Models.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  this->m_Models.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Models.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Models.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Models.m_Tree.m_pElements = this->m_Models.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Models.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Models.m_Tree.m_FirstFree = -1;
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ModelPool,
    blockSize: 336,
    numElements: 1024,
    growMode: 1,
    pszAllocOwner: "CModelLoader::m_ModelPool",
    nAlignment: 0);
  this->m_InlineModels.m_Memory.m_pMemory = nullptr;
  this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  this->m_InlineModels.m_Memory.m_nGrowSize = 0;
  this->m_InlineModels.m_Size = 0;
  this->m_InlineModels.m_pElements = nullptr;
  this->m_LightStyleList.m_Memory.m_pMemory = nullptr;
  this->m_LightStyleList.m_Memory.m_nAllocationCount = 0;
  this->m_LightStyleList.m_Memory.m_nGrowSize = 0;
  this->m_LightStyleList.m_Size = 0;
  this->m_LightStyleList.m_pElements = nullptr;
  CMemoryStack::CMemoryStack(this: &this->m_WorldLightingDataStack);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EFFF0
// Name: void Mod_LoadSubmodels(class CUtlVector<struct mmodel_t,class CUtlMemory<struct mmodel_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Mod_LoadSubmodels(dmodel_t *a1@<ebp>, CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > *submodelList)
{
  unsigned int v2; // ecx
  signed int v3; // edi
  worldbrushdata_t *v4; // eax
  signed int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  mmodel_t *v9; // edi
  long double v10; // st7
  long double v11; // st6
  float v12; // xmm2_4
  long double v13; // st7
  long double v14; // st6
  float v15; // xmm1_4
  long double v16; // st7
  long double v17; // st6
  float v18; // xmm0_4
  float v19; // xmm1_4
  __int128 v20; // xmm0
  bool v21; // zf
  unsigned int v22; // [esp-Ch] [ebp-154h] BYREF
  _BYTE lh[300]; // [esp+0h] [ebp-148h] OVERLAPPED
  int v24; // [esp+12Ch] [ebp-1Ch]
  signed int v25; // [esp+130h] [ebp-18h]
  float v26; // [esp+134h] [ebp-14h]
  float v27; // [esp+138h] [ebp-10h]
  dmodel_t *in; // [esp+13Ch] [ebp-Ch]
  void *v29; // [esp+140h] [ebp-8h]
  void *retaddr; // [esp+148h] [ebp+0h]

  in = a1;
  v29 = retaddr;
  CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v22, lumpToLoad: 0xEu, bUncompress: true);
  v2 = v22;
  v25 = *(_DWORD *)&lh[4];
  if ( v22 % 0x30 != 0 )
  {
    Host_Error(error: "Mod_LoadSubmodels: funny lump size in %s", s_szMapPathName);
    v2 = v22;
  }
  v3 = v2 / 0x30;
  submodelList->m_Size = 0;
  CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int>>::InsertMultipleBefore(this: submodelList, elem: 0, num: v2 / 0x30);
  v4 = s_pMap;
  v5 = v25;
  s_pMap->numsubmodels = v3;
  v4->nWorldFaceCount = *(_DWORD *)(v5 + 44);
  if ( v3 > 0 )
  {
    v6 = 24;
    v7 = 0;
    v8 = v5 + 24;
    v24 = 24;
    v25 = v3;
    do
    {
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 24) = *(float *)(v8 - 24) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 12) = *(float *)(v8 - 12) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.x + v6) = *(float *)v8;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 20) = *(float *)(v8 - 20) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 8) = *(float *)(v8 - 8) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.y + v6) = *(float *)(v8 + 4);
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 16) = *(float *)(v8 - 16) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 4) = *(float *)(v8 - 4) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.z + v6) = *(float *)(v8 + 8);
      v9 = &submodelList->m_Memory.m_pMemory[v7];
      v10 = fabs(v9->mins.x);
      v27 = v10;
      v11 = fabs(v9->maxs.x);
      v26 = v11;
      if ( v10 <= v11 )
        v12 = v26;
      else
        v12 = v27;
      v13 = fabs(v9->mins.y);
      v26 = v13;
      v14 = fabs(v9->maxs.y);
      v27 = v14;
      if ( v13 <= v14 )
        v15 = v27;
      else
        v15 = v26;
      v16 = fabs(v9->mins.z);
      v26 = v16;
      v17 = fabs(v9->maxs.z);
      v27 = v17;
      if ( v16 <= v17 )
        v18 = v27;
      else
        v18 = v26;
      v19 = (float)(v15 * v15) + (float)(v18 * v18);
      v20 = 0;
      *(float *)&v20 = fsqrt(v19 + (float)(v12 * v12));
      *(_OWORD *)&lh[284] = v20;
      LODWORD(v9->radius) = v20;
      submodelList->m_Memory.m_pMemory[v7].headnode = *(_DWORD *)(v8 + 12);
      submodelList->m_Memory.m_pMemory[v7].firstface = *(_DWORD *)(v8 + 16);
      submodelList->m_Memory.m_pMemory[v7].numfaces = *(_DWORD *)(v8 + 20);
      v6 = v24 + 52;
      ++v7;
      v8 += 48;
      v21 = v25-- == 1;
      v24 += 52;
    }
    while ( !v21 );
  }
  if ( *(_DWORD *)lh != 0 )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: *(void **)lh);
}

//------------------------------------------------------------------------------
// Address: 0x100F0230
// Name: private: void CResourcePreloadModel::PurgeModels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeModels(CResourcePreloadModel *this, bool bPurgeAll)
{
  int v2; // esi
  int m_Size; // edi
  int v4; // ebx
  model_t *v5; // esi
  bool v6; // al
  int v7; // esi
  model_t **m_pMemory; // ecx
  model_t **v9; // eax
  int i; // esi
  CUtlVector<model_t *,CUtlMemory<model_t *,int> > firstList; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<model_t *,CUtlMemory<model_t *,int> > otherList; // [esp+20h] [ebp-20h] BYREF
  int iIndex; // [esp+34h] [ebp-Ch]
  model_t *pModel; // [esp+38h] [ebp-8h] BYREF
  bool bSpew; // [esp+3Fh] [ebp-1h]

  v2 = 0;
  bSpew = (g_pQueuedLoader->GetSpewDetail(this: g_pQueuedLoader) & 8) != 0;
  m_Size = 0;
  v4 = 0;
  memset(&firstList, 0, sizeof(firstList));
  memset(&otherList, 0, sizeof(otherList));
  iIndex = CModelLoader::FindNext(this: &g_ModelLoader, iIndex: -1, ppModel: &pModel);
  if ( iIndex != -1 )
  {
    do
    {
      v5 = pModel;
      if ( pModel == nullptr )
        break;
      if ( pModel->type == mod_studio )
      {
        v6 = bPurgeAll || (pModel->nLoadFlags & 0x8000) == 0;
        pModel->nLoadFlags &= ~0x8000u;
        if ( v6 )
        {
          if ( bSpew )
            _Msg(a1: "CResourcePreloadModel: Purging: %s\n", v5->szPathName);
          if ( g_pMDLCache->IsDataLoaded(this: g_pMDLCache, a2: v5->studio, a3: MDLCACHE_VIRTUALMODEL) )
          {
            v7 = m_Size;
            if ( m_Size + 1 > firstList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&firstList,
                num: m_Size - firstList.m_Memory.m_nAllocationCount + 1);
              m_Size = firstList.m_Size;
            }
            m_pMemory = firstList.m_Memory.m_pMemory;
            firstList.m_Size = ++m_Size;
            firstList.m_pElements = firstList.m_Memory.m_pMemory;
            if ( m_Size - v7 - 1 > 0 )
            {
              _V_memmove(
                dest: &firstList.m_Memory.m_pMemory[v7 + 1],
                src: &firstList.m_Memory.m_pMemory[v7],
                count: 4 * (m_Size - v7 - 1));
              m_pMemory = firstList.m_Memory.m_pMemory;
            }
          }
          else
          {
            v7 = v4;
            if ( v4 + 1 > otherList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&otherList,
                num: v4 - otherList.m_Memory.m_nAllocationCount + 1);
              v4 = otherList.m_Size;
            }
            m_pMemory = otherList.m_Memory.m_pMemory;
            otherList.m_Size = ++v4;
            otherList.m_pElements = otherList.m_Memory.m_pMemory;
            if ( v4 - v7 - 1 > 0 )
            {
              _V_memmove(
                dest: &otherList.m_Memory.m_pMemory[v7 + 1],
                src: &otherList.m_Memory.m_pMemory[v7],
                count: 4 * (v4 - v7 - 1));
              m_pMemory = otherList.m_Memory.m_pMemory;
            }
          }
          v9 = &m_pMemory[v7];
          if ( v9 != nullptr )
            *v9 = pModel;
        }
      }
      iIndex = CModelLoader::FindNext(this: &g_ModelLoader, iIndex, ppModel: &pModel);
    }
    while ( iIndex != -1 );
    v2 = 0;
  }
  if ( m_Size > 0 )
  {
    do
      CModelLoader::UnloadModel(this: &g_ModelLoader, pModel: firstList.m_Memory.m_pMemory[v2++]);
    while ( v2 < m_Size );
  }
  for ( i = 0; i < v4; ++i )
    CModelLoader::UnloadModel(this: &g_ModelLoader, pModel: otherList.m_Memory.m_pMemory[i]);
  if ( bPurgeAll || !g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader) )
    g_pMDLCache->Flush_2(this: g_pMDLCache, a2: MDLCACHE_FLUSH_ANIMBLOCK);
  if ( otherList.m_Memory.m_nGrowSize >= 0 && otherList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: otherList.m_Memory.m_pMemory);
  if ( firstList.m_Memory.m_nGrowSize >= 0 && firstList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: firstList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F0470
// Name: private: virtual void CResourcePreloadModel::PurgeUnreferencedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeUnreferencedResources(CResourcePreloadModel *this)
{
  CResourcePreloadModel::PurgeModels(this, bPurgeAll: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F0480
// Name: private: virtual void CResourcePreloadModel::PurgeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeAll(CResourcePreloadModel *this)
{
  CResourcePreloadModel::PurgeModels(this, bPurgeAll: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F0490
// Name: private: void CModelLoader::UnloadAllModels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadAllModels(CModelLoader *this, bool bCheckReference)
{
  int v3; // esi
  model_t *modelpointer; // eax
  int c; // [esp+8h] [ebp-4h]

  v3 = 0;
  c = this->m_Models.m_Tree.m_NumElements;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    while ( 1 )
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( !bCheckReference )
        break;
      if ( (modelpointer->nLoadFlags & 0x7E) == 0 )
        goto LABEL_7;
      if ( modelpointer->type == mod_studio )
        g_pMDLCache->MarkAsLoaded(this: g_pMDLCache, a2: modelpointer->studio);
LABEL_9:
      if ( ++v3 >= c )
        return;
    }
    modelpointer->nLoadFlags &= 0xFFFFFF81;
LABEL_7:
    if ( (modelpointer->nLoadFlags & 0x10001) != 0 )
      CModelLoader::UnloadModel(this, pModel: modelpointer);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0520
// Name: public: virtual void CModelLoader::UnloadUnreferencedModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadUnreferencedModels(CModelLoader *this)
{
  CModelLoader::UnloadAllModels(this, bCheckReference: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F0530
// Name: public: virtual void CModelLoader::PurgeUnusedModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::PurgeUnusedModels(CModelLoader *this)
{
  int ServerCount; // eax
  int m_NumElements; // ebx
  int v4; // esi
  model_t *modelpointer; // edx
  int nLoadFlags; // ecx
  int v7; // ebx
  int v8; // esi
  model_t *v9; // eax
  int v10; // ecx

  ServerCount = Host_GetServerCount();
  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  v4 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem.modelpointer;
      nLoadFlags = modelpointer->nLoadFlags;
      if ( (nLoadFlags & 1) != 0 && modelpointer->nServerCount != ServerCount )
        modelpointer->nLoadFlags = nLoadFlags & 0xFFFFFF81;
      ++v4;
    }
    while ( v4 < m_NumElements );
  }
  v7 = this->m_Models.m_Tree.m_NumElements;
  v8 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      v9 = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.modelpointer;
      v10 = v9->nLoadFlags;
      if ( (v10 & 0x7E) != 0 )
      {
        if ( v9->type == mod_studio )
          g_pMDLCache->MarkAsLoaded(this: g_pMDLCache, a2: v9->studio);
      }
      else if ( (v10 & 0x10001) != 0 )
      {
        CModelLoader::UnloadModel(
          this,
          pModel: this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.modelpointer);
      }
      ++v8;
    }
    while ( v8 < v7 );
  }
  materials->UncacheUnusedMaterials(this: materials, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F05F0
// Name: private: void CModelLoader::SetupSubModels(struct model_t __near *,class CUtlVector<struct mmodel_t,class CUtlMemory<struct mmodel_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::SetupSubModels(
        CModelLoader *this,
        model_t *mod,
        CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > *list)
{
  int v4; // ebx
  CUtlVector<model_t,CUtlMemory<model_t,int> > *p_m_InlineModels; // ecx
  mmodel_t *v6; // edi
  model_t *v7; // esi
  int headnode_low; // ecx
  int numsubmodels; // [esp-4h] [ebp-10h]
  CModelLoader *v10; // [esp+8h] [ebp-4h]

  v4 = 0;
  numsubmodels = this->m_worldBrushData.numsubmodels;
  p_m_InlineModels = &this->m_InlineModels;
  v10 = this;
  p_m_InlineModels->m_Size = 0;
  CUtlVector<model_t,CUtlMemory<model_t,int>>::InsertMultipleBefore(this: p_m_InlineModels, elem: 0, num: numsubmodels);
  if ( this->m_worldBrushData.numsubmodels > 0 )
  {
    do
    {
      v6 = &list->m_Memory.m_pMemory[v4];
      v7 = &v10->m_InlineModels.m_Memory.m_pMemory[v4];
      model_t::operator=(this: v7, __that: mod);
      v7->brush.firstmodelsurface = v6->firstface;
      v7->brush.nummodelsurfaces = v6->numfaces;
      headnode_low = LOWORD(v6->headnode);
      v7->brush.firstnode = headnode_low;
      if ( headnode_low >= v10->m_worldBrushData.numnodes )
        Sys_Error(error: "Inline model %i has bad firstnode", v4);
      v7->maxs.x = v6->maxs.x;
      v7->maxs.y = v6->maxs.y;
      v7->maxs.z = v6->maxs.z;
      v7->mins.x = v6->mins.x;
      v7->mins.y = v6->mins.y;
      v7->mins.z = v6->mins.z;
      v7->radius = v6->radius;
      if ( v4 != 0 )
      {
        V_snprintf(pDest: v7->szPathName, maxLen: 260, pFormat: "*%d", v4);
        v7->fnHandle = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: v7->szPathName);
      }
      else
      {
        model_t::operator=(this: mod, __that: v7);
      }
      ++v4;
    }
    while ( v4 < v10->m_worldBrushData.numsubmodels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0700
// Name: public: void CModelLoader::DumpVCollideStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::DumpVCollideStats(CModelLoader *this)
{
  CModelLoader *v1; // ebx
  bool v2; // sf
  int v3; // edi
  model_t *modelpointer; // esi
  int studio; // eax
  int v6; // edi
  int v7; // ecx
  vcollide_t *v8; // esi
  int v9; // ebx
  int v10; // edi
  int v11; // ebx
  int m_Size; // esi
  int v13; // edi
  int *p_size; // esi
  CUtlSortVector<modelsize_t,CModelsize_Less> list; // [esp+Ch] [ebp-3Ch] BYREF
  modelsize_t src; // [esp+28h] [ebp-20h] BYREF
  int bboxCount; // [esp+30h] [ebp-18h] BYREF
  int bboxSize; // [esp+34h] [ebp-14h] BYREF
  int size; // [esp+38h] [ebp-10h] BYREF
  CModelLoader *v20; // [esp+3Ch] [ebp-Ch]
  modelsize_t elem; // [esp+40h] [ebp-8h] BYREF

  v1 = this;
  v3 = this->m_Models.m_Tree.m_NumElements - 1;
  v2 = this->m_Models.m_Tree.m_NumElements == 0;
  v20 = this;
  memset(&list, 0, 25);
  if ( !v2 )
  {
    do
    {
      modelpointer = v1->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( modelpointer != nullptr && modelpointer->type == mod_studio )
      {
        studio = modelpointer->studio;
        size = 0;
        if ( g_pMDLCache->GetVCollideSize(this: g_pMDLCache, a2: studio, a3: &size) && size != 0 )
        {
          elem.size = size;
          elem.pName = modelpointer->szPathName;
          CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(this: &list, src: &elem);
        }
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
  v6 = v1->m_InlineModels.m_Size - 1;
  size = v6;
  if ( v6 >= 0 )
  {
    v7 = 336 * v6;
    for ( elem.size = 336 * v6; ; v7 = elem.size )
    {
      v8 = CM_VCollideForModel(
             modelindex: v6 + 1,
             pModel: (const model_t *)((char *)v1->m_InlineModels.m_Memory.m_pMemory + v7));
      if ( v8 != nullptr )
      {
        v9 = 0;
        v10 = 0;
        if ( (*(_WORD *)v8 & 0x7FFF) != 0 )
        {
          do
            v9 += physcollision->CollideSize(this: physcollision, a2: v8->solids[v10++]);
          while ( v10 < (*(_WORD *)v8 & 0x7FFF) );
        }
        v11 = v8->descSize + v9;
        if ( v11 != 0 )
        {
          src.pName = &v20->m_InlineModels.m_Memory.m_pMemory->szPathName[elem.size];
          src.size = v11;
          CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(this: &list, &src);
        }
        v6 = size;
        v1 = v20;
      }
      elem.size -= 336;
      size = --v6;
      if ( v6 < 0 )
        break;
    }
  }
  m_Size = list.m_Size;
  _Msg(a1: "VCollides loaded: %d\n", list.m_Size);
  v13 = 0;
  if ( m_Size > 0 )
  {
    p_size = &list.m_Memory.m_pMemory->size;
    size = list.m_Size;
    do
    {
      _Msg(a1: "%8d bytes:%s\n", *p_size, (const char *)*(p_size - 1));
      v13 += *p_size;
      p_size += 2;
      --size;
    }
    while ( size != 0 );
  }
  physcollision->GetBBoxCacheSize(this: physcollision, a2: &bboxSize, a3: &bboxCount);
  _Msg(a1: "%8d bytes BBox physics: %d boxes\n", bboxSize, bboxCount);
  _Msg(a1: "--------------\n%8d bytes total VCollide Memory\n", v13 + bboxSize);
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F08F0
// Name: vx_model_list
// Source: json
//------------------------------------------------------------------------------
void __cdecl vx_model_list()
{
  int (__thiscall *GetCount)(IModelLoader *); // edx
  int v1; // esi
  int v2; // eax
  int v3; // edi
  model_t *(__thiscall *GetModelForIndex)(IModelLoader *, int); // edx
  const char *v5; // ebx
  int v6; // eax
  model_t *v7; // edi
  studiohwdata_t *v8; // eax
  studiohwdata_t *v9; // esi
  int m_NumLODs; // edx
  _DWORD *v11; // eax
  xModelList_t *v12; // eax
  xModelList_t *v13; // edi
  const char *v14; // ecx
  int v15; // edi
  char v16; // dl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  const char *v25; // eax
  void *v26; // ebx
  int *p_numLODs; // esi
  char csvFileName[260]; // [esp+Ch] [ebp-148h] BYREF
  CUtlVector<xModelList_t,CUtlMemory<xModelList_t,int> > modelList; // [esp+110h] [ebp-44h] BYREF
  int numVerts; // [esp+124h] [ebp-30h] BYREF
  xModelList_t *m_pMemory; // [esp+128h] [ebp-2Ch]
  int numMeshes; // [esp+12Ch] [ebp-28h]
  int numVertsLod0; // [esp+130h] [ebp-24h] BYREF
  int numLODs; // [esp+134h] [ebp-20h]
  int nTriCount; // [esp+138h] [ebp-1Ch] BYREF
  int numParts; // [esp+13Ch] [ebp-18h]
  int dataSize; // [esp+140h] [ebp-14h]
  int nTriCountLod0; // [esp+144h] [ebp-10h] BYREF
  int dataSizeLod0; // [esp+148h] [ebp-Ch]
  int numActualModels; // [esp+14Ch] [ebp-8h]
  int i; // [esp+150h] [ebp-4h]

  GetCount = modelloader->GetCount;
  v1 = 0;
  memset(&modelList, 0, sizeof(modelList));
  v2 = GetCount(this: modelloader);
  CUtlVector<xModelList_t,CUtlMemory<xModelList_t,int>>::InsertMultipleBefore(this: &modelList, elem: 0, num: v2);
  v3 = 0;
  numActualModels = 0;
  i = 0;
  if ( modelList.m_Size > 0 )
  {
    m_pMemory = modelList.m_Memory.m_pMemory;
    while ( 1 )
    {
      GetModelForIndex = modelloader->GetModelForIndex;
      v5 = "Unknown";
      dataSizeLod0 = 0;
      dataSize = 0;
      numParts = 0;
      numVertsLod0 = 0;
      numVerts = 0;
      numLODs = 0;
      numMeshes = 0;
      nTriCount = 0;
      nTriCountLod0 = 0;
      v6 = (int)GetModelForIndex(this: modelloader, a2: i);
      v7 = (model_t *)v6;
      if ( v6 == 0 )
        goto LABEL_8;
      if ( *(_DWORD *)(v6 + 272) == 3 )
        break;
LABEL_11:
      v1 = 0;
      if ( ++i >= modelList.m_Size )
      {
        v3 = numActualModels;
        goto LABEL_13;
      }
    }
    v5 = (const char *)(v6 + 4);
    v8 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: *(unsigned __int16 *)(v6 + 312));
    v9 = v8;
    if ( v8 != nullptr )
    {
      m_NumLODs = v8->m_NumLODs;
      numMeshes = v8->m_NumStudioMeshes;
      numLODs = m_NumLODs;
      dataSize = ComputeSize(hwData: v8, &numVerts, pTriCount: &nTriCount, onlyTopLod: false);
      dataSizeLod0 = ComputeSize(hwData: v9, numVerts: &numVertsLod0, pTriCount: &nTriCountLod0, onlyTopLod: true);
    }
    v11 = modelloader->GetExtraData(this: modelloader, a2: v7);
    v1 = v11[39];
    numParts = v11[58];
LABEL_8:
    ++numActualModels;
    v12 = m_pMemory;
    v13 = m_pMemory++;
    v14 = v5;
    v15 = (char *)v13 - v5;
    do
    {
      v16 = *v14;
      v14[v15] = *v14;
      ++v14;
    }
    while ( v16 != 0 );
    v17 = numVerts;
    v12->dataSize = dataSize;
    v18 = nTriCount;
    v12->numVertices = v17;
    v19 = dataSizeLod0;
    v12->triCount = v18;
    v20 = numVertsLod0;
    v12->dataSizeLod0 = v19;
    v21 = nTriCountLod0;
    v12->numVerticesLod0 = v20;
    v22 = numParts;
    v12->triCountLod0 = v21;
    v23 = numLODs;
    v12->numParts = v22;
    v24 = numMeshes;
    v12->numBones = v1;
    v12->numLODs = v23;
    v12->numMeshes = v24;
    goto LABEL_11;
  }
LABEL_13:
  v25 = engineClient->GetLevelNameShort(this: engineClient);
  V_snprintf(pDest: csvFileName, maxLen: 260, pFormat: "modellist_%s.csv", v25);
  _Msg(a1: "Writing model list to %s...\n", csvFileName);
  v26 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: csvFileName, a3: "w", a4: 0);
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: v26,
    a3: "Model,DataSize,Tris,Verts,DataSize (LOD0),Tris (LOD0),Verts (LOD0),Parts,Bones,LODs,Meshes\n");
  if ( v3 > 0 )
  {
    p_numLODs = &modelList.m_Memory.m_pMemory->numLODs;
    do
    {
      g_pFullFileSystem->FPrintf(
        this: g_pFullFileSystem,
        a2: v26,
        a3: "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        p_numLODs - 73,
        *(p_numLODs - 8),
        *(p_numLODs - 6),
        *(p_numLODs - 7),
        *(p_numLODs - 5),
        *(p_numLODs - 3),
        *(p_numLODs - 4),
        *(p_numLODs - 1),
        *(p_numLODs - 2),
        *p_numLODs,
        p_numLODs[1]);
      p_numLODs += 75;
      --v3;
    }
    while ( v3 != 0 );
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v26);
  if ( modelList.m_Memory.m_nGrowSize >= 0 && modelList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: modelList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F0C00
// Name: mem_vcollide
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_vcollide()
{
  CModelLoader::DumpVCollideStats(this: &g_ModelLoader);
}

//------------------------------------------------------------------------------
// Address: 0x100F0C10
// Name: public: virtual void CModelLoader::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Shutdown(CModelLoader *this)
{
  this->m_pWorldModel = nullptr;
  CModelLoader::UnloadAllModels(this, bCheckReference: false);
  CUtlMemoryPool::Clear(this: &this->m_ModelPool);
}

//------------------------------------------------------------------------------
// Address: 0x100F0C30
// Name: public: struct model_t __near * CModelLoader::FindModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::FindModel(CModelLoader *this, char *pName)
{
  int v4; // eax
  int v5; // edi
  int numsubmodels; // eax
  void *v8; // edi
  unsigned __int16 v9; // ax
  model_t *modelpointer; // esi
  CMapReslistGenerator *v11; // eax
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short> *pNamea; // [esp+1Ch] [ebp+8h]

  if ( pName == nullptr || *pName == 0 )
    Sys_Error(error: "CModelLoader::FindModel: NULL name");
  if ( *pName == 42 )
  {
    v4 = atoi(nptr: pName + 1);
    v5 = v4;
    if ( this->m_pWorldModel == nullptr )
      Sys_Error(error: "bad inline model number %i, worldmodel not yet setup", v4);
    if ( v5 < 1
      || (this->m_pWorldModel != nullptr ? (numsubmodels = this->m_worldBrushData.numsubmodels) : (numsubmodels = 0),
          v5 >= numsubmodels) )
    {
      Sys_Error(error: "bad inline model number %i", v5);
    }
    return &this->m_InlineModels.m_Memory.m_pMemory[v5];
  }
  else
  {
    v8 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pName);
    search.key = v8;
    pNamea = &this->m_Models;
    v9 = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Models.m_Tree,
           &search);
    if ( v9 == 0xFFFF )
    {
      modelpointer = (model_t *)CUtlMemoryPool::Alloc(this: &this->m_ModelPool);
      memset(dst: (unsigned __int8 *)modelpointer, value: 0, count: sizeof(model_t));
      modelpointer->fnHandle = v8;
      modelpointer->nLoadFlags = 0;
      V_strncpy(pDest: modelpointer->szPathName, pSrc: pName, maxLen: 260);
      V_RemoveDotSlashes(pFilename: modelpointer->szPathName, separator: 47);
      search.key = v8;
      search.elem.modelpointer = modelpointer;
      CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: &pNamea->m_Tree,
        insert: &search);
    }
    else
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem.modelpointer;
    }
    v11 = MapReslistGenerator();
    CMapReslistGenerator::OnModelPrecached(this: v11, relativePathFileName: pName);
    return modelpointer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0D60
// Name: public: virtual struct model_t __near * CModelLoader::GetModelForName(char const __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::GetModelForName(
        CModelLoader *this,
        const char *name,
        IModelLoader::REFERENCETYPE referencetype)
{
  model_t *Model; // eax

  Model = CModelLoader::FindModel(this, pName: name);
  return CModelLoader::LoadModel(this, mod: Model, pReferencetype: &referencetype);
}

//------------------------------------------------------------------------------
// Address: 0x100F0D80
// Name: public: virtual struct model_t __near * CModelLoader::ReferenceModel(char const __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::ReferenceModel(
        CModelLoader *this,
        const char *name,
        IModelLoader::REFERENCETYPE referencetype)
{
  model_t *result; // eax

  result = CModelLoader::FindModel(this, pName: name);
  result->nLoadFlags |= referencetype;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0DA0
// Name: public: virtual int CModelLoader::GetModelFileSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetModelFileSize(CModelLoader *this, const char *name)
{
  char *szPathName; // esi
  const char *v4; // eax
  char spritename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( name == nullptr || *name == 0 )
    return -1;
  szPathName = CModelLoader::FindModel(this, pName: name)->szPathName;
  if ( V_stristr(pStr: szPathName, pSearch: ".spr") == nullptr
    && V_stristr(pStr: szPathName, pSearch: ".vmt") == nullptr )
  {
    return COM_FileSize(filename: name);
  }
  v4 = va(format: "materials/%s", szPathName);
  V_StripExtension(in: v4, out: spritename, outSize: 260);
  V_DefaultExtension(path: spritename, extension: ".vmt", pathStringLength: 260);
  return COM_FileSize(filename: spritename);
}

//------------------------------------------------------------------------------
// Address: 0x100F0E60
// Name: void Mod_LoadSimpleWorldModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadSimpleWorldModel(const char *pMapBaseName)
{
  model_t *Model; // eax
  model_t *v2; // eax
  char modelPathWater[260]; // [esp+4h] [ebp-20Ch] BYREF
  char modelPath[260]; // [esp+108h] [ebp-108h] BYREF
  IModelLoader::REFERENCETYPE pReferencetype; // [esp+20Ch] [ebp-4h] BYREF

  V_stristr(pStr: pMapBaseName, pSearch: "mp_coop_");
  V_snprintf(pDest: modelPath, maxLen: 260, pFormat: "models/maps/%s/simpleworldmodel.mdl", pMapBaseName);
  V_snprintf(pDest: modelPathWater, maxLen: 260, pFormat: "models/maps/%s/simpleworldmodel_water.mdl", pMapBaseName);
  pReferencetype = FMODELLOADER_SIMPLEWORLD;
  Model = CModelLoader::FindModel(this: &g_ModelLoader, pName: modelPath);
  g_pSimpleWorldModel = CModelLoader::LoadModel(this: &g_ModelLoader, mod: Model, &pReferencetype);
  pReferencetype = FMODELLOADER_SIMPLEWORLD;
  v2 = CModelLoader::FindModel(this: &g_ModelLoader, pName: modelPathWater);
  g_pSimpleWorldModelWater = CModelLoader::LoadModel(this: &g_ModelLoader, mod: v2, &pReferencetype);
  if ( g_pSimpleWorldModel == nullptr )
    _Warning(
      a1: "\n"
      "\n"
      "###########################################\n"
      "## !!FAILED TO LOAD SIMPLE WORLD MODEL!! ##\n"
      "##        (perf will be terrible)        ##\n"
      "##           (image is broken)           ##\n"
      "###########################################\n"
      "\n"
      "\n");
}

//------------------------------------------------------------------------------
// Address: 0x100F0F20
// Name: private: virtual bool CResourcePreloadModel::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadModel::CreateResource(CResourcePreloadModel *this, char *pName)
{
  int TypeFromName; // eax
  unsigned __int16 v3; // ax
  model_t *modelpointer; // edi
  char *szPathName; // ebx
  int lumpOffset; // esi
  const char *v7; // esi
  model_t *Model; // esi
  int nLoadFlags; // eax
  int v11; // eax
  char szFilename[260]; // [esp+8h] [ebp-260h] BYREF
  char szNameOnDisk[260]; // [esp+10Ch] [ebp-15Ch] BYREF
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t search; // [esp+210h] [ebp-58h] BYREF
  LoaderJob_t loaderJobAIN; // [esp+218h] [ebp-50h] BYREF
  LoaderJob_t loaderJobBSP; // [esp+240h] [ebp-28h] BYREF

  TypeFromName = CModelLoader::GetTypeFromName(this: &g_ModelLoader, pModelName: pName);
  if ( TypeFromName == 1 )
  {
    search.key = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pName);
    v3 = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &g_ModelLoader.m_Models.m_Tree,
           &search);
    if ( v3 != 0xFFFF )
    {
      modelpointer = g_ModelLoader.m_Models.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.modelpointer;
      if ( modelpointer != nullptr )
      {
        szPathName = modelpointer->szPathName;
        CMapLoadHelper::Init(
          a1: (int)modelpointer->szPathName,
          a2: (int)modelpointer,
          p_lumpHeader: (lumpfileheader_t *)pName,
          pMapModel: modelpointer,
          pPathName: modelpointer->szPathName);
        lumpOffset = s_MapLumpFiles[40].header.lumpOffset;
        if ( s_MapLumpFiles[40].file == nullptr )
          lumpOffset = s_MapHeader.lumps[40].fileofs;
        CMapLoadHelper::Shutdown();
        if ( szPathName != szNameOnDisk )
          V_strncpy(pDest: szNameOnDisk, pSrc: modelpointer->szPathName, maxLen: 260);
        memset(&loaderJobBSP.m_pContext2, 0, 24);
        loaderJobBSP.m_pFilename = szNameOnDisk;
        loaderJobBSP.m_pPathID = "GAME";
        loaderJobBSP.m_pCallback = CResourcePreloadModel::QueuedLoaderMapCallback;
        loaderJobBSP.m_pContext = modelpointer;
        loaderJobBSP.m_pTargetData = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: lumpOffset);
        loaderJobBSP.m_nBytesToRead = lumpOffset;
        loaderJobBSP.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
        g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJobBSP);
        v7 = V_UnqualifiedFileName(in: com_gamedir);
        if ( StringAfterPrefix(str: v7, prefix: "portal2") == nullptr
          && StringAfterPrefix(str: v7, prefix: "left4dead") == nullptr )
        {
          V_FileBase(in: szPathName, out: szFilename, maxlen: 260);
          V_snprintf(pDest: szNameOnDisk, maxLen: 260, pFormat: "maps/graphs/%s.ain", szFilename);
          memset(&loaderJobAIN.m_pCallback, 0, 24);
          *(_DWORD *)&loaderJobAIN.m_bPersistTargetData = 0;
          loaderJobAIN.m_pFilename = szNameOnDisk;
          loaderJobAIN.m_pPathID = "GAME";
          loaderJobAIN.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
          g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJobAIN);
        }
        return 1;
      }
    }
    return 0;
  }
  if ( TypeFromName != 3 )
    return 0;
  V_ComposeFileName(path: "models", filename: pName, dest: szFilename, destSize: 260);
  Model = CModelLoader::FindModel(this: &g_ModelLoader, pName: szFilename);
  Model->nLoadFlags |= 0x8000u;
  nLoadFlags = Model->nLoadFlags;
  if ( (nLoadFlags & 0x10001) == 0 )
  {
    Model->nLoadFlags = nLoadFlags | 0x10000;
    Model->type = mod_studio;
    v11 = ((int (__thiscall *)(IMDLCache *, char *))g_pMDLCache->FindMDL)(a1: g_pMDLCache, a2: Model->szPathName);
    Model->studio = v11;
    g_pMDLCache->SetUserData(this: g_pMDLCache, a2: v11, a3: Model);
    ((void (__stdcall *)(_DWORD))g_pMDLCache->PreloadModel)(a1: Model->studio);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F11A0
// Name: private: void CModelLoader::Map_LoadModelGuts(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_LoadModelGuts(CModelLoader *this, model_t *mod)
{
  unsigned int m_nLumpSize; // ecx
  worldbrushdata_t *v5; // eax
  worldbrushdata_t *v6; // eax
  IEngineVGuiInternal *v7; // eax
  int lumpLength; // eax
  IEngineVGuiInternal *v9; // eax
  IEngineVGuiInternal *v10; // eax
  IOverlayMgr *v11; // eax
  IEngineVGuiInternal *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  int filelen; // eax
  IEngineVGuiInternal *v17; // eax
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  CMapLoadHelper mlh; // [esp+Ch] [ebp-270h] BYREF
  CMapLoadHelper lhTexinfo; // [esp+134h] [ebp-148h] BYREF
  unsigned int checksum; // [esp+25Ch] [ebp-20h] BYREF
  CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > submodelList; // [esp+260h] [ebp-1Ch] BYREF
  int texinfoCount; // [esp+274h] [ebp-8h]
  texinfo_s *pTexinfo; // [esp+278h] [ebp-4h]
  char *bLoadHDR; // [esp+284h] [ebp+8h]
  medge_t *bLoadHDRb; // [esp+284h] [ebp+8h]
  bool bLoadHDRa; // [esp+284h] [ebp+8h]

  ++g_nMapLoadCount;
  _COM_TimestampedLog(a1: "  Map_CheckForHDR");
  bLoadHDR = mod->szPathName;
  this->m_bMapHasHDRLighting = Map_CheckForHDR(pModel: mod, pMapPathName: bLoadHDR);
  CMapLoadHelper::CMapLoadHelper(this: &lhTexinfo, lumpToLoad: 6u, bUncompress: true);
  m_nLumpSize = lhTexinfo.m_nLumpSize;
  pTexinfo = (texinfo_s *)lhTexinfo.m_pData;
  if ( lhTexinfo.m_nLumpSize % 0x48u != 0 )
  {
    Host_Error(error: "Map_LoadModelGuts: bad LUMP_TEXINFO size in %s", bLoadHDR);
    m_nLumpSize = lhTexinfo.m_nLumpSize;
  }
  texinfoCount = m_nLumpSize / 0x48;
  if ( m_nLumpSize / 0x48 != 0 )
  {
    if ( (int)(m_nLumpSize / 0x48) > 12288 )
      Sys_Error(error: "Map_LoadModelGuts: Map has too many surfaces, %s", bLoadHDR);
    _COM_TimestampedLog(a1: "  CM_LoadMap");
    CM_LoadMap(pPathName: bLoadHDR, allowReusePrevious: false, pTexinfo, texinfoCount, &checksum);
    _COM_TimestampedLog(a1: "  Mod_LoadVertices");
    Mod_LoadVertices();
    _COM_TimestampedLog(a1: "  Mod_LoadEdges");
    bLoadHDRb = Mod_LoadEdges();
    _COM_TimestampedLog(a1: "  Mod_LoadSurfedges");
    Mod_LoadSurfedges(pedges: bLoadHDRb);
    _COM_TimestampedLog(a1: "  Mod_LoadPlanes");
    v5 = s_pMap;
    s_pMap->planes = g_BSPData.map_planes.m_pArray;
    v5->numplanes = g_BSPData.numplanes;
    _COM_TimestampedLog(a1: "  Mod_LoadOcclusion");
    Mod_LoadOcclusion();
    _COM_TimestampedLog(a1: "  Mod_LoadTexdata");
    v6 = s_pMap;
    s_pMap->numtexdata = g_BSPData.numtextures;
    v6->texdata = g_BSPData.map_surfaces.m_pArray;
    _COM_TimestampedLog(a1: "  Mod_LoadTexinfo");
    Mod_LoadTexinfo(lh: &lhTexinfo);
    v7 = EngineVGui();
    v7->UpdateProgressBar(this: v7, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadLighting");
    if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
      goto LABEL_12;
    lumpLength = s_MapLumpFiles[53].header.lumpLength;
    if ( s_MapLumpFiles[53].file == nullptr )
      lumpLength = s_MapHeader.lumps[53].filelen;
    bLoadHDRa = true;
    if ( lumpLength <= 0 )
LABEL_12:
      bLoadHDRa = false;
    Mod_LoadLighting(bLoadHDR: bLoadHDRa);
    _COM_TimestampedLog(a1: "  Mod_LoadPrimitives");
    Mod_LoadPrimitives();
    _COM_TimestampedLog(a1: "  Mod_LoadPrimVerts");
    Mod_LoadPrimVerts();
    _COM_TimestampedLog(a1: "  Mod_LoadPrimIndices");
    Mod_LoadPrimIndices();
    v9 = EngineVGui();
    v9->UpdateProgressBar(this: v9, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadFaces");
    Mod_LoadFaces();
    Mod_LoadFaceBrushes();
    _COM_TimestampedLog(a1: "  Mod_LoadVertNormals");
    Mod_LoadVertNormals();
    _COM_TimestampedLog(a1: "  Mod_LoadVertNormalIndices");
    Mod_LoadVertNormalIndices();
    v10 = EngineVGui();
    v10->UpdateProgressBar(this: v10, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadLeafs");
    Mod_LoadLeafs();
    _COM_TimestampedLog(a1: "  Mod_LoadMarksurfaces");
    Mod_LoadMarksurfaces();
    _COM_TimestampedLog(a1: "  Mod_LoadNodes");
    Mod_LoadNodes();
    _COM_TimestampedLog(a1: "  Mod_LoadLeafWaterData");
    Mod_LoadLeafWaterData();
    _COM_TimestampedLog(a1: "  OverlayMgr()->LoadOverlays");
    v11 = OverlayMgr();
    v11->LoadOverlays(this: v11);
    _COM_TimestampedLog(a1: "  Mod_LoadLeafMinDistToWater");
    Mod_LoadLeafMinDistToWater();
    v12 = EngineVGui();
    v12->UpdateProgressBar(this: v12, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  LUMP_CLIPPORTALVERTS");
    v13 = va(format: "%s [%s]", this->m_szBaseName, "clipportalverts");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 41,
      loadname: v13,
      elementSize: 12,
      ppData: (void **)&this->m_worldBrushData.m_pClipPortalVerts,
      nElements: &this->m_worldBrushData.m_nClipPortalVerts);
    _COM_TimestampedLog(a1: "  LUMP_AREAPORTALS");
    v14 = va(format: "%s [%s]", this->m_szBaseName, "areaportals");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 21,
      loadname: v14,
      elementSize: 12,
      ppData: (void **)&this->m_worldBrushData.m_pAreaPortals,
      nElements: &this->m_worldBrushData.m_nAreaPortals);
    _COM_TimestampedLog(a1: "  LUMP_AREAS");
    v15 = va(format: "%s [%s]", this->m_szBaseName, "areas");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 20,
      loadname: v15,
      elementSize: 8,
      ppData: (void **)&this->m_worldBrushData.m_pAreas,
      nElements: &this->m_worldBrushData.m_nAreas);
    _COM_TimestampedLog(a1: "  Mod_LoadWorldlights");
    if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
      goto LABEL_18;
    filelen = s_MapLumpFiles[54].header.lumpLength;
    if ( s_MapLumpFiles[54].file == nullptr )
      filelen = s_MapHeader.lumps[54].filelen;
    if ( filelen > 0 )
    {
      CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0x36u, bUncompress: true);
      Mod_LoadWorldlights(lh: &mlh, bIsHDR: true);
    }
    else
    {
LABEL_18:
      CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0xFu, bUncompress: true);
      Mod_LoadWorldlights(lh: &mlh, bIsHDR: false);
    }
    if ( mlh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: mlh.m_pRawData);
    _COM_TimestampedLog(a1: "  Mod_LoadCubemapSamples");
    Mod_LoadCubemapSamples();
    _COM_TimestampedLog(a1: "  Mod_LoadSimpleWorldModel");
    Mod_LoadSimpleWorldModel(pMapBaseName: this->m_szBaseName);
    _COM_TimestampedLog(a1: "  Mod_LoadGameLumpDict");
    Mod_LoadGameLumpDict();
    v17 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, int))v17->UpdateProgressBar)(a1: v17, a2: 3);
    _COM_TimestampedLog(a1: "  Mod_LoadSubmodels");
    memset(&submodelList, 0, sizeof(submodelList));
    Mod_LoadSubmodels(&submodelList);
    v18 = EngineVGui();
    v18->UpdateProgressBar(this: v18, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  SetupSubModels");
    CModelLoader::SetupSubModels(this, mod, list: &submodelList);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&submodelList);
    _COM_TimestampedLog(a1: "  RecomputeSurfaceFlags");
    this->RecomputeSurfaceFlags(this, a2: mod);
    v19 = EngineVGui();
    v19->UpdateProgressBar(this: v19, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Map_VisClear");
    Map_VisClear();
    _COM_TimestampedLog(a1: "  Map_SetRenderInfoAllocated");
    this->Map_SetRenderInfoAllocated(this, a2: false);
  }
  else if ( !g_bClearingClientState )
  {
    Sys_Error(error: "Map_LoadModelGuts: Map with no texinfo, %s", bLoadHDR);
  }
  if ( lhTexinfo.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lhTexinfo.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x10316130
// Name: _dynamic_initializer_for__mod_touchalldata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_touchalldata__()
{
  ConVar::ConVar(
    this: &mod_touchalldata,
    pName: "mod_touchalldata",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Touch model data during level startup");
  return atexit(func: dynamic_atexit_destructor_for__mod_touchalldata__);
}

//------------------------------------------------------------------------------
// Address: 0x10316160
// Name: _dynamic_initializer_for__mod_forcetouchdata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_forcetouchdata__()
{
  ConVar::ConVar(
    this: &mod_forcetouchdata,
    pName: "mod_forcetouchdata",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Forces all model file data into cache on model load.");
  return atexit(func: dynamic_atexit_destructor_for__mod_forcetouchdata__);
}

//------------------------------------------------------------------------------
// Address: 0x10316290
// Name: lump_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *lump_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<lump_t>(__formal: nullptr);
  lump_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103162A0
// Name: BSPHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BSPHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BSPHeader_t>(__formal: nullptr);
  BSPHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031D9D0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DA00
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x10323890
// Name: _dynamic_atexit_destructor_for__mod_touchalldata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_touchalldata__()
{
  ConVar::~ConVar(this: &mod_touchalldata);
}

//------------------------------------------------------------------------------
// Address: 0x103238A0
// Name: _dynamic_atexit_destructor_for__mod_forcetouchdata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_forcetouchdata__()
{
  ConVar::~ConVar(this: &mod_forcetouchdata);
}

//------------------------------------------------------------------------------
// Address: 0x10326820
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x10326830
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x103162B0
// Name: _dynamic_initializer_for__g_ModelLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelLoader__()
{
  CModelLoader::CModelLoader(this: &g_ModelLoader);
  return atexit(func: dynamic_atexit_destructor_for__g_ModelLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DA30
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DA50
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DAA0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DAB0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10326840
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x10326850
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10326860
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: (CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100E7890
// Name: void NotifyHunkBeginMapLoad(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyHunkBeginMapLoad(const char *pszMapName)
{
  int v1; // esi

  v1 = 0;
  while ( EstimatedHunkSizes[v1].pszMapRoot != nullptr
       && V_stristr(pStr: pszMapName, pSearch: EstimatedHunkSizes[v1].pszMapRoot) == nullptr )
  {
    if ( ++v1 != 0 )
      return;
  }
  Hunk_OnMapStart(nEstimatedBytes: *(&nEstimatedBytes + 2 * v1));
}

//------------------------------------------------------------------------------
// Address: 0x100E78E0
// Name: char __near * GetMapPathNameOnDisk(char __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetMapPathNameOnDisk(char *pDiskName, char *pFullMapName, unsigned int nDiskNameSize)
{
  if ( pFullMapName != pDiskName )
    V_strncpy(pDest: pDiskName, pSrc: pFullMapName, maxLen: nDiskNameSize);
  return pDiskName;
}

//------------------------------------------------------------------------------
// Address: 0x100E7910
// Name: public: static void CMapLoadHelper::Init(struct model_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapLoadHelper::Init(
        int a1@<ebx>,
        int a2@<edi>,
        lumpfileheader_t *p_lumpHeader@<esi>,
        model_t *pMapModel,
        char *pPathName)
{
  void *v6; // eax
  int i; // edi
  int v8; // eax
  void *v9; // esi
  int lumpID; // ecx
  void *file; // eax
  int lumpOffset; // edx
  int v13; // eax
  int lumpLength; // edx
  int mapRevision; // ecx
  char szNameOnDisk[260]; // [esp+0h] [ebp-21Ch] BYREF
  char lumpfilename[260]; // [esp+104h] [ebp-118h] BYREF
  lumpfileheader_t lumpHeader; // [esp+208h] [ebp-14h] BYREF

  if ( ++s_nMapLoadRecursion <= 1 )
  {
    s_pMap = nullptr;
    s_MapFileHandle = nullptr;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    if ( pMapModel != nullptr )
      pPathName = pMapModel->szPathName;
    V_strncpy(pDest: s_szMapPathName, pSrc: pPathName, maxLen: 260);
    V_strncpy(pDest: szNameOnDisk, pSrc: s_szMapPathName, maxLen: 260);
    v6 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: szNameOnDisk, a3: "rb", a4: 0, a5: 0, a6: 0);
    s_MapFileHandle = v6;
    if ( v6 != nullptr )
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &s_MapHeader, a3: 1036, a4: v6);
      if ( s_MapHeader.ident == 1347633750 )
      {
        if ( (unsigned int)(s_MapHeader.m_nVersion - 19) > 2 )
        {
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
          s_MapFileHandle = nullptr;
          Host_Error(
            error: "CMapLoadHelper::Init, map %s has wrong version (%i when expecting %i)\n",
            szNameOnDisk,
            s_MapHeader.m_nVersion,
            21);
        }
        else
        {
          if ( g_ServerGlobalVariables.mapversion == 0 )
            g_ServerGlobalVariables.mapversion = s_MapHeader.mapRevision;
          InitDLightGlobals(nMapVersion: s_MapHeader.m_nVersion);
          s_pMap = &g_ModelLoader.m_worldBrushData;
          for ( i = 0; i < 128; ++i )
          {
            GenerateLumpFileName(bspfilename: s_szMapPathName, lumpfilename, iBufferSize: 260, iIndex: i);
            if ( !g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: lumpfilename, a3: nullptr) )
              break;
            v8 = ((int (__thiscall *)(IBaseFileSystem *, char *, const char *, _DWORD, lumpfileheader_t *, int, int))g_pFileSystem->Open)(
                   a1: &g_pFileSystem->IBaseFileSystem,
                   a2: lumpfilename,
                   a3: "rb",
                   a4: 0,
                   a5: p_lumpHeader,
                   a6: a2,
                   a7: a1);
            v9 = (void *)v8;
            if ( v8 == 0 )
            {
              Host_Error(error: "CMapLoadHelper::Init, failed to load lump file %s\n", lumpfilename);
              return;
            }
            a1 = v8;
            memset(&lumpHeader, 0, sizeof(lumpHeader));
            a2 = 20;
            p_lumpHeader = &lumpHeader;
            ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Read)(a1: &g_pFileSystem->IBaseFileSystem);
            lumpID = lumpHeader.lumpID;
            if ( lumpHeader.lumpID > 0x3Fu )
            {
              _Warning(a1: "Found invalid lump file '%s'. Lump Id: %d\n", lumpfilename, lumpHeader.lumpID);
            }
            else
            {
              file = s_MapLumpFiles[lumpHeader.lumpID].file;
              if ( file != nullptr )
              {
                g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
                lumpID = lumpHeader.lumpID;
              }
              lumpOffset = lumpHeader.lumpOffset;
              v13 = lumpID;
              s_MapLumpFiles[v13].file = v9;
              s_MapLumpFiles[v13].lumpfileindex = i;
              s_MapLumpFiles[v13].header.lumpOffset = lumpOffset;
              lumpLength = lumpHeader.lumpLength;
              s_MapLumpFiles[v13].header.lumpID = lumpID;
              s_MapLumpFiles[v13].header.lumpVersion = lumpHeader.lumpVersion;
              mapRevision = lumpHeader.mapRevision;
              s_MapLumpFiles[v13].header.lumpLength = lumpLength;
              s_MapLumpFiles[v13].header.mapRevision = mapRevision;
            }
          }
        }
      }
      else
      {
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
        s_MapFileHandle = nullptr;
        Host_Error(error: "CMapLoadHelper::Init, map %s has wrong identifier\n", szNameOnDisk);
      }
    }
    else if ( !g_bClearingClientState )
    {
      Host_Error(error: "CMapLoadHelper::Init, unable to open %s\n", szNameOnDisk);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7C10
// Name: public: static void CMapLoadHelper::InitFromMemory(struct model_t __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapLoadHelper::InitFromMemory(model_t *pMapModel, void *pData, int nDataSize)
{
  char szNameOnDisk[260]; // [esp+0h] [ebp-104h] BYREF

  if ( ++s_nMapLoadRecursion <= 1 )
  {
    s_pMap = nullptr;
    s_MapFileHandle = nullptr;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    V_strncpy(pDest: s_szMapPathName, pSrc: pMapModel->szPathName, maxLen: 260);
    V_strncpy(pDest: szNameOnDisk, pSrc: s_szMapPathName, maxLen: 260);
    CUtlBuffer::SetExternalBuffer(
      this: &s_MapBuffer,
      pMemory: pData,
      nSize: nDataSize,
      nInitialPut: nDataSize,
      nFlags: 0);
    g_ModelLoader.m_worldBrushData.m_nBSPFileSize = nDataSize;
    _V_memcpy(dest: &s_MapHeader, src: pData, count: 1036);
    if ( s_MapHeader.ident == 1347633750 )
    {
      if ( (unsigned int)(s_MapHeader.m_nVersion - 19) > 2 )
      {
        Host_Error(
          error: "CMapLoadHelper::Init, map %s has wrong version (%i when expecting %i)\n",
          szNameOnDisk,
          s_MapHeader.m_nVersion,
          21);
      }
      else
      {
        g_ServerGlobalVariables.mapversion = s_MapHeader.mapRevision;
        InitDLightGlobals(nMapVersion: s_MapHeader.m_nVersion);
        s_pMap = &g_ModelLoader.m_worldBrushData;
      }
    }
    else
    {
      Host_Error(error: "CMapLoadHelper::Init, map %s has wrong identifier\n", szNameOnDisk);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7D30
// Name: public: void CMapLoadHelper::LoadLumpElement(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::LoadLumpElement(CMapLoadHelper *this, int nElemIndex, int nElemSize, void *pData)
{
  if ( nElemSize != 0 && this->m_nLumpSize != 0 && nElemSize * (nElemIndex + 1) <= this->m_nLumpSize )
    _V_memcpy(dest: pData, src: &this->m_pData[nElemSize * nElemIndex], count: nElemSize);
}

//------------------------------------------------------------------------------
// Address: 0x100E7D70
// Name: public: void CMapLoadHelper::LoadLumpData(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::LoadLumpData(CMapLoadHelper *this, int offset, int size, void *pData)
{
  if ( size != 0 && this->m_nLumpSize != 0 && offset + size <= this->m_nLumpSize )
    _V_memcpy(dest: pData, src: &this->m_pData[offset], count: size);
}

//------------------------------------------------------------------------------
// Address: 0x100E7DB0
// Name: public: CMapLoadHelper::~CMapLoadHelper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::~CMapLoadHelper(CMapLoadHelper *this)
{
  unsigned __int8 *m_pRawData; // eax

  m_pRawData = this->m_pRawData;
  if ( m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100E7DD0
// Name: public: void CMapLoadHelper::UncompressLump(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLoadHelper::UncompressLump(CMapLoadHelper *this, unsigned __int8 *pExternalBuffer)
{
  unsigned __int8 *v3; // eax
  int v4; // edx
  unsigned __int8 *m_pData; // [esp-8h] [ebp-Ch]
  unsigned int m_nUncompressedLumpSize; // [esp-4h] [ebp-8h]

  if ( this->m_pUncompressedData == nullptr )
  {
    v3 = pExternalBuffer;
    if ( pExternalBuffer != nullptr )
    {
      this->m_bUncompressedDataExternal = true;
    }
    else
    {
      v3 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: this->m_nUncompressedLumpSize);
      this->m_bUncompressedDataExternal = false;
    }
    m_nUncompressedLumpSize = this->m_nUncompressedLumpSize;
    m_pData = this->m_pData;
    this->m_pUncompressedData = v3;
    memcpy(dst: v3, src: m_pData, count: m_nUncompressedLumpSize);
    v4 = this->m_nUncompressedLumpSize;
    this->m_pData = this->m_pUncompressedData;
    this->m_nLumpSize = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7E30
// Name: public: struct worldbrushdata_t __near * CMapLoadHelper::GetMap(void)
// Source: json
//------------------------------------------------------------------------------
worldbrushdata_t *__thiscall CMapLoadHelper::GetMap(CMapLoadHelper *this)
{
  return s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E7E40
// Name: public: char __near * CMapLoadHelper::GetLoadName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLoadHelper::GetLoadName(CMapLoadHelper *this)
{
  char *result; // eax

  result = this->m_szLumpFilename;
  if ( s_MapLumpFiles[this->m_nLumpID].file == nullptr )
    return s_szMapPathName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E7E60
// Name: public: char __near * CMapLoadHelper::GetDiskName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMapLoadHelper::GetDiskName(CMapLoadHelper *this)
{
  char *m_szLumpFilename; // eax

  m_szLumpFilename = this->m_szLumpFilename;
  if ( s_MapLumpFiles[this->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  if ( m_szLumpFilename != s_szMapPathNameOnDisk )
    V_strncpy(pDest: s_szMapPathNameOnDisk, pSrc: m_szLumpFilename, maxLen: 260);
  return s_szMapPathNameOnDisk;
}

//------------------------------------------------------------------------------
// Address: 0x100E7EB0
// Name: void DeallocateLightingData(struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeallocateLightingData(worldbrushdata_t *pBrushData)
{
  CMemoryStack *m_pLightingDataStack; // ecx

  if ( pBrushData != nullptr && pBrushData->lightdata != nullptr )
  {
    if ( !g_bHunkAllocLightmaps )
    {
      m_pLightingDataStack = pBrushData->m_pLightingDataStack;
      if ( m_pLightingDataStack != nullptr && CMemoryStack::GetSize(this: m_pLightingDataStack) != 0 )
        CMemoryStack::Term(this: pBrushData->m_pLightingDataStack);
      else
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBrushData->lightdata);
    }
    pBrushData->lightdata = nullptr;
    pBrushData->m_nLightingDataSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7F20
// Name: void Mod_SetParent(struct mnode_t __near *,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_SetParent(mnode_t *node, mnode_t *parent)
{
  mnode_t *v2; // esi
  bool v3; // sf
  mnode_t *v4; // eax

  v2 = node;
  v3 = node->contents < 0;
  node->parent = parent;
  if ( v3 )
  {
    do
    {
      Mod_SetParent(node: v2->children[0], parent: v2);
      v4 = v2;
      v2 = v2->children[1];
      v2->parent = v4;
    }
    while ( v2->contents < 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7F50
// Name: MarkSmallNode
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkSmallNode(mnode_t *node)
{
  mnode_t *i; // esi
  mnode_t *v2; // [esp-4h] [ebp-8h]

  for ( i = node; i->contents < 0; i = i->children[1] )
  {
    v2 = i->children[0];
    i->contents = -2;
    MarkSmallNode(node: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7F80
// Name: CheckSmallVolumeDifferences
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckSmallVolumeDifferences(mnode_t *pNode, const Vector *parentSize)
{
  mnode_t *i; // esi
  mnode_t *v3; // [esp-Ch] [ebp-10h]

  for ( i = pNode; i->contents < 0; i = i->children[1] )
  {
    if ( (float)(parentSize->x - i->m_vecHalfDiagonal.x) >= 5.0 )
      break;
    if ( (float)(parentSize->y - i->m_vecHalfDiagonal.y) >= 5.0 )
      break;
    if ( (float)(parentSize->z - i->m_vecHalfDiagonal.z) >= 5.0 )
      break;
    v3 = i->children[0];
    i->contents = -3;
    CheckSmallVolumeDifferences(pNode: v3, parentSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E7FF0
// Name: void Mod_LoadLeafs_Version_0(class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs_Version_0(int lh)
{
  signed int v1; // esi
  char *v2; // eax
  const char *v3; // eax
  mleaf_t *v4; // ebx
  worldbrushdata_t *v5; // eax
  worldbrushdata_t *v6; // edi
  dleafambientindex_t *m_pLeafAmbient; // ecx
  int v8; // eax
  float *p_y; // esi
  __int16 *v10; // edi
  unsigned __int8 *v11; // ebx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  int v15; // edx
  float v16; // xmm7_4
  int count; // [esp+Ch] [ebp-Ch]
  dleafambientindex_t *pTable; // [esp+10h] [ebp-8h]
  unsigned __int8 *in; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  in = *(unsigned __int8 **)(lh + 16);
  if ( *(_DWORD *)lh % 0x38u != 0 )
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
  v1 = *(_DWORD *)lh / 0x38u;
  count = v1;
  v2 = (char *)(lh + 36);
  if ( s_MapLumpFiles[*(_DWORD *)(lh + 32)].file == nullptr )
    v2 = s_szMapPathName;
  v3 = va(format: "%s [%s]", v2, "leafs");
  v4 = (mleaf_t *)Hunk_AllocName(size: v1 << 6, name: v3, bClear: true);
  v5 = s_pMap;
  s_pMap->leafs = v4;
  v5->numleafs = v1;
  v5->m_pLeafAmbient = (dleafambientindex_t *)Hunk_AllocName(size: 4 * v1, name: "LeafAmbient", bClear: true);
  v6 = s_pMap;
  v6->m_pAmbientSamples = (dleafambientlighting_t *)Hunk_AllocName(
                                                      size: 28 * v1,
                                                      name: "LeafAmbientSamples",
                                                      bClear: true);
  m_pLeafAmbient = s_pMap->m_pLeafAmbient;
  v8 = 0;
  pTable = m_pLeafAmbient;
  i = 0;
  if ( v1 > 0 )
  {
    p_y = &v4->m_vecCenter.y;
    v10 = (__int16 *)(in + 14);
    v11 = &s_pMap->m_pAmbientSamples->y;
    while ( 1 )
    {
      v12 = (float)*v10;
      v13 = (float)v10[1];
      v14 = (float)*(v10 - 1);
      v15 = v10[2];
      v16 = v12 + (float)*(v10 - 3);
      *p_y = v13 + (float)*(v10 - 2);
      p_y[1] = (float)v15 + v14;
      *(p_y - 1) = v16 * 0.5;
      *p_y = *p_y * 0.5;
      p_y[1] = p_y[1] * 0.5;
      p_y[3] = v12 - *(p_y - 1);
      p_y[4] = v13 - *p_y;
      p_y[5] = (float)v15 - p_y[1];
      m_pLeafAmbient[v8].firstAmbientSample = v8;
      m_pLeafAmbient[v8].ambientSampleCount = 1;
      *(_WORD *)v11 = -32640;
      *(v11 - 1) = 0x80;
      v11[2] = 0;
      _V_memcpy(dest: v11 - 25, src: v10 + 8, count: 24);
      *(p_y - 5) = *(float *)(v10 - 7);
      *((_WORD *)p_y + 14) = *(v10 - 5);
      *((_WORD *)p_y - 4) = (__int16)(*(v10 - 4) << 7) >> 7;
      *((_WORD *)p_y - 3) = *(v10 - 4) >> 9;
      *((_WORD *)p_y + 16) = v10[3];
      *((_WORD *)p_y + 17) = v10[4];
      *(p_y - 3) = 0.0;
      *((_WORD *)p_y + 21) = 0;
      *((_WORD *)p_y + 15) = v10[7];
      v11 += 28;
      v10 += 28;
      ++i;
      p_y += 16;
      if ( i >= count )
        break;
      v8 = i;
      m_pLeafAmbient = pTable;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8260
// Name: void Mod_LoadLeafs_Version_1(class CMapLoadHelper __near &,class CMapLoadHelper __near &,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs_Version_1(
        CMapLoadHelper *lh,
        CompressedLightCube *ambientLightingLump,
        CMapLoadHelper *ambientLightingTable)
{
  CMapLoadHelper *v3; // esi
  bool v4; // zf
  int v5; // ebx
  const char *m_szLumpFilename; // eax
  const char *v7; // eax
  mleaf_t *v8; // eax
  CompressedLightCube *v9; // edi
  mleaf_t *v10; // ecx
  worldbrushdata_t *v11; // eax
  CMapLoadHelper *v12; // esi
  int m_nLumpSize; // ecx
  void *v14; // eax
  CMapLoadHelper *v15; // edx
  void *v16; // eax
  worldbrushdata_t *v17; // edi
  dleafambientlighting_t *m_pAmbientSamples; // esi
  int v19; // edi
  unsigned __int8 *p_y; // esi
  dleafambientlighting_t *v21; // eax
  dleafambientindex_t *v22; // ecx
  __int16 *maxs; // ecx
  float *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  int v28; // esi
  float v29; // xmm7_4
  int v30; // [esp-1Ch] [ebp-44h]
  Vector gray; // [esp+8h] [ebp-20h] BYREF
  mleaf_t *out; // [esp+14h] [ebp-14h]
  dleaf_t *in; // [esp+18h] [ebp-10h]
  dleafambientindex_t *pTable; // [esp+1Ch] [ebp-Ch]
  dleafambientlighting_t *pSamples; // [esp+20h] [ebp-8h]
  void *src; // [esp+24h] [ebp-4h]

  v3 = lh;
  v4 = (lh->m_nLumpSize & 0x1F) == 0;
  in = (dleaf_t *)lh->m_pData;
  if ( !v4 )
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
  v5 = (unsigned int)v3->m_nLumpSize >> 5;
  m_szLumpFilename = v3->m_szLumpFilename;
  if ( s_MapLumpFiles[v3->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v7 = va(format: "%s [%s]", m_szLumpFilename, "leafs");
  v8 = (mleaf_t *)Hunk_AllocName(size: v5 << 6, name: v7, bClear: true);
  v9 = ambientLightingLump;
  v10 = v8;
  v11 = s_pMap;
  s_pMap->leafs = v10;
  v11->numleafs = v5;
  v4 = *(_DWORD *)&v9->m_Color[2] == 1;
  out = v10;
  if ( v4
    && (v12 = ambientLightingTable,
        m_nLumpSize = ambientLightingTable->m_nLumpSize,
        ambientLightingTable->m_nLumpSize != 0) )
  {
    lh = (CMapLoadHelper *)v11;
    v14 = Hunk_AllocName(size: m_nLumpSize, name: "LeafAmbient", bClear: true);
    v15 = (CMapLoadHelper *)s_pMap;
    *(_DWORD *)&lh->m_szLumpFilename[208] = v14;
    v30 = (int)v9->m_Color[0];
    lh = v15;
    v16 = Hunk_AllocName(size: v30, name: "LeafAmbientSamples", bClear: true);
    *(_DWORD *)&lh->m_szLumpFilename[212] = v16;
    _V_memcpy(dest: s_pMap->m_pLeafAmbient, src: v12->m_pData, count: v12->m_nLumpSize);
    _V_memcpy(dest: s_pMap->m_pAmbientSamples, src: *(const void **)&v9->m_Color[4], count: *(_DWORD *)v9->m_Color);
  }
  else
  {
    v4 = *(_DWORD *)v9->m_Color == 0;
    ambientLightingLump = nullptr;
    if ( !v4 )
      ambientLightingLump = (CompressedLightCube *)v9->m_Color[4];
    v11->m_pLeafAmbient = (dleafambientindex_t *)Hunk_AllocName(size: 4 * v5, name: "LeafAmbient", bClear: true);
    v17 = s_pMap;
    v17->m_pAmbientSamples = (dleafambientlighting_t *)Hunk_AllocName(
                                                         size: 28 * v5,
                                                         name: "LeafAmbientSamples",
                                                         bClear: true);
    m_pAmbientSamples = s_pMap->m_pAmbientSamples;
    pTable = s_pMap->m_pLeafAmbient;
    pSamples = m_pAmbientSamples;
    gray.x = 0.5;
    gray.y = 0.5;
    gray.z = 0.5;
    VectorToColorRGBExp32(vin: &gray, c: (ColorRGBExp32 *)&lh);
    v19 = 0;
    if ( v5 > 0 )
    {
      p_y = &m_pAmbientSamples->y;
      v21 = (dleafambientlighting_t *)&pSamples->cube.m_Color[2];
      src = ambientLightingLump;
      pSamples = (dleafambientlighting_t *)((char *)pSamples + 8);
      do
      {
        v4 = ambientLightingLump == nullptr;
        v22 = pTable;
        pTable[v19].ambientSampleCount = 1;
        v22[v19].firstAmbientSample = v19;
        *(_WORD *)p_y = -32640;
        *(p_y - 1) = 0x80;
        p_y[2] = 0;
        if ( v4 )
        {
          v21[-1].cube.m_Color[5] = (ColorRGBExp32)lh;
          *(_DWORD *)&v21[-1].x = lh;
          v21->cube.m_Color[0] = (ColorRGBExp32)lh;
          v21->cube.m_Color[1] = (ColorRGBExp32)lh;
          v21->cube.m_Color[2] = (ColorRGBExp32)lh;
          v21->cube.m_Color[3] = (ColorRGBExp32)lh;
        }
        else
        {
          _V_memcpy(dest: p_y - 25, src, count: 24);
          v21 = pSamples;
        }
        src = (char *)src + 24;
        ++v19;
        ++v21;
        p_y += 28;
        pSamples = v21;
      }
      while ( v19 < v5 );
    }
  }
  if ( v5 > 0 )
  {
    maxs = in->maxs;
    v24 = &out->m_vecCenter.y;
    do
    {
      v25 = (float)*maxs;
      v26 = (float)maxs[1];
      v27 = (float)*(maxs - 1);
      v28 = maxs[2];
      v29 = v25 + (float)*(maxs - 3);
      *v24 = v26 + (float)*(maxs - 2);
      v24[1] = (float)v28 + v27;
      *(v24 - 1) = v29 * 0.5;
      *v24 = *v24 * 0.5;
      v24[1] = v24[1] * 0.5;
      v24[3] = v25 - *(v24 - 1);
      v24[4] = v26 - *v24;
      v24[5] = (float)v28 - v24[1];
      *(v24 - 5) = *(float *)(maxs - 7);
      *((_WORD *)v24 + 14) = *(maxs - 5);
      *((_WORD *)v24 - 4) = (__int16)(*(maxs - 4) << 7) >> 7;
      *((_WORD *)v24 - 3) = *(maxs - 4) >> 9;
      *((_WORD *)v24 + 16) = maxs[3];
      *((_WORD *)v24 + 17) = maxs[4];
      *(v24 - 3) = 0.0;
      *((_WORD *)v24 + 21) = 0;
      *((_WORD *)v24 + 15) = maxs[7];
      maxs += 16;
      v24 += 16;
      --v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E85B0
// Name: private: void CMDLCacheNotify::SetBoundsFromStudioHdr(struct model_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::SetBoundsFromStudioHdr(CMDLCacheNotify *this, model_t *pModel, int handle)
{
  studiohdr_t *v3; // eax
  long double v4; // st7
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  float handlea; // [esp+Ch] [ebp+Ch]
  float handleb; // [esp+Ch] [ebp+Ch]
  float handlec; // [esp+Ch] [ebp+Ch]
  float handled; // [esp+Ch] [ebp+Ch]
  float handlee; // [esp+Ch] [ebp+Ch]
  float handlef; // [esp+Ch] [ebp+Ch]

  v3 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: handle);
  pModel->mins = v3->hull_min;
  pModel->maxs = v3->hull_max;
  pModel->radius = 0.0;
  v4 = fabs(pModel->mins.x);
  if ( v4 > pModel->radius )
  {
    handlea = v4;
    pModel->radius = handlea;
  }
  v5 = fabs(pModel->maxs.x);
  if ( v5 > pModel->radius )
  {
    handleb = v5;
    pModel->radius = handleb;
  }
  v6 = fabs(pModel->mins.y);
  if ( v6 > pModel->radius )
  {
    handlec = v6;
    pModel->radius = handlec;
  }
  v7 = fabs(pModel->maxs.y);
  if ( v7 > pModel->radius )
  {
    handled = v7;
    pModel->radius = handled;
  }
  v8 = fabs(pModel->mins.z);
  if ( v8 > pModel->radius )
  {
    handlee = v8;
    pModel->radius = handlee;
  }
  v9 = fabs(pModel->maxs.z);
  if ( v9 > pModel->radius )
  {
    handlef = v9;
    pModel->radius = handlef;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E86F0
// Name: void ConnectMDLCacheNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConnectMDLCacheNotify()
{
  g_pMDLCache->SetCacheNotify(this: g_pMDLCache, a2: &s_MDLCacheNotify);
}

//------------------------------------------------------------------------------
// Address: 0x100E8710
// Name: void DisconnectMDLCacheNotify(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisconnectMDLCacheNotify()
{
  g_pMDLCache->SetCacheNotify(this: g_pMDLCache, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100E8720
// Name: public: virtual char const __near * CModelLoader::GetName(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CModelLoader::GetName(CModelLoader *this, const model_t *pModel)
{
  if ( pModel != nullptr )
    return pModel->szPathName;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E8740
// Name: BuildSpriteLoadName
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildSpriteLoadName(char *pName@<edi>, char *pOut, int outLen, bool *bIsAVI, bool *bIsBIK)
{
  const char *FileExtension; // esi
  bool v7; // al
  int v8; // eax
  int v9; // eax
  const char *v10; // esi
  const char *v11; // [esp+0h] [ebp-110h]
  char szBase[260]; // [esp+Ch] [ebp-104h] BYREF
  bool bIsVMT_3; // [esp+123h] [ebp+13h]

  FileExtension = V_GetFileExtension(path: v11);
  *bIsAVI = _V_stricmp(s1: FileExtension, s2: "avi") == 0;
  *bIsBIK = _V_stricmp(s1: FileExtension, s2: "bik") == 0;
  v7 = _V_stricmp(s1: FileExtension, s2: "vmt") == 0;
  bIsVMT_3 = v7;
  if ( (*bIsAVI || *bIsBIK || v7)
    && ((strchr(string: pName, chr: 0x2Fu), v8 != 0) || (strchr(string: pName, chr: 0x5Cu), v9 != 0)) )
  {
    if ( bIsVMT_3 )
    {
      v10 = pName;
      if ( V_stristr(pStr: pName, pSearch: "materials/") == pName
        || V_stristr(pStr: pName, pSearch: "materials\\") == pName )
      {
        v10 = pName + 10;
      }
      V_StripExtension(in: v10, out: pOut, outSize: outLen);
    }
    else
    {
      V_strncpy(pDest: pOut, pSrc: pName, maxLen: outLen);
    }
  }
  else
  {
    V_FileBase(in: pName, out: szBase, maxlen: 260);
    V_snprintf(pDest: pOut, maxLen: outLen, pFormat: "sprites/%s", szBase);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8860
// Name: public: virtual void CModelLoader::UnreferenceModel(struct model_t __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnreferenceModel(
        CModelLoader *this,
        model_t *model,
        IModelLoader::REFERENCETYPE referencetype)
{
  model->nLoadFlags &= ~referencetype;
}

//------------------------------------------------------------------------------
// Address: 0x100E8880
// Name: enum RenderableTranslucencyType_t Mod_ComputeTranslucencyType(struct model_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_ComputeTranslucencyType(model_t *mod, int nSkin, int nBody)
{
  int v3; // ebx
  int v5; // edi
  int v6; // esi
  IMaterial *v7; // ecx
  int flags; // eax
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-200h] BYREF

  if ( mod->type == mod_brush )
  {
    flags = mod->flags;
    if ( (flags & 2) != 0 )
      return ((flags & 8) != 0) + 1;
    return 0;
  }
  if ( mod->type == mod_sprite )
    return 1;
  if ( mod->type != mod_studio )
    return 0;
  v3 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: mod->studio);
  if ( (*(_BYTE *)(v3 + 152) & 4) != 0 )
    return 0;
  v5 = ((int (__stdcall *)(_DWORD, int, int, int, IMaterial **))g_pStudioRender->GetMaterialListFromBodyAndSkin)(
         a1: mod->studio,
         a2: nSkin,
         a3: nBody,
         a4: 128,
         a5: pMaterials);
  v6 = 0;
  if ( v5 <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = pMaterials[v6];
    if ( v7 != nullptr && v7->IsTranslucent(this: v7) )
      break;
    if ( ++v6 >= v5 )
      return 0;
  }
  return ((*(_BYTE *)(v3 + 152) & 8) != 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E89D0
// Name: public: struct model_t __near & model_t::operator=(struct model_t const __near &)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall model_t::operator=(model_t *this, const model_t *__that)
{
  model_t *result; // eax
  char *szPathName; // esi
  int i; // edx

  result = this;
  this->fnHandle = __that->fnHandle;
  szPathName = this->szPathName;
  for ( i = 260; i != 0; --i )
  {
    *szPathName = szPathName[(char *)__that - (char *)this];
    ++szPathName;
  }
  this->nLoadFlags = __that->nLoadFlags;
  this->nServerCount = __that->nServerCount;
  this->type = __that->type;
  this->flags = __that->flags;
  this->mins = __that->mins;
  this->maxs = __that->maxs;
  this->radius = __that->radius;
  this->m_pKeyValues = __that->m_pKeyValues;
  this->___u10 = __that->___u10;
  this->sprite = __that->sprite;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100E8B20
// Name: GetSpriteInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSpriteInfo(const char *pName, bool bIsAVI, bool bIsBIK, int *nWidth, int *nHeight, int *nFrameCount)
{
  IMaterial *v6; // esi
  int v7; // edi
  int v8; // ebx
  unsigned __int16 v9; // ax
  IMaterial *Material; // eax

  *nFrameCount = 1;
  v6 = nullptr;
  v7 = 0xFFFF;
  *nHeight = 1;
  *nWidth = 1;
  v8 = 0xFFFF;
  if ( bIsAVI )
  {
    v7 = avi->CreateAVIMaterial(this: avi, a2: pName, a3: pName, a4: "GAME");
    avi->GetFrameSize(this: avi, a2: v7, a3: nWidth, a4: nHeight);
    *nFrameCount = avi->GetFrameCount(this: avi, a2: v7);
    if ( (_WORD)v7 != 0xFFFF )
      v6 = avi->GetMaterial(this: avi, a2: v7);
  }
  else if ( bIsBIK )
  {
    v9 = bik->CreateMaterial(this: bik, a2: pName, a3: pName, a4: "GAME", a5: 0);
    v8 = v9;
    if ( v9 != 0xFFFF )
    {
      bik->GetFrameSize(this: bik, a2: v9, a3: nWidth, a4: nHeight);
      *nFrameCount = bik->GetFrameCount(this: bik, a2: v8);
      v6 = bik->GetMaterial(this: bik, a2: v8);
    }
  }
  else
  {
    Material = GL_LoadMaterial(pName, pTextureGroupName: "Other textures", bPrecache: false);
    v6 = Material;
    if ( Material != nullptr )
    {
      *nWidth = Material->GetMappingWidth(this: Material);
      *nHeight = v6->GetMappingHeight(this: v6);
      *nFrameCount = v6->GetNumAnimationFrames(this: v6);
    }
  }
  if ( v6 == g_materialEmpty )
    DevMsg(a1: "Missing sprite material %s\n", pName);
  if ( (_WORD)v7 != 0xFFFF )
    avi->DestroyAVIMaterial(this: avi, a2: v7);
  if ( (_WORD)v8 != 0xFFFF )
    bik->DestroyMaterial(this: bik, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100E8CB0
// Name: private: void CModelLoader::Sprite_LoadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Sprite_LoadModel(CModelLoader *this, model_t *mod)
{
  model_t *v2; // esi
  void *v3; // edi
  unsigned int v4; // eax
  int nLightstyleLastComputedFrame; // esi
  char loadName[260]; // [esp+8h] [ebp-108h] BYREF
  BOOL bIsAVI; // [esp+10Ch] [ebp-4h] BYREF

  v2 = mod;
  mod->nLoadFlags |= 1u;
  v3 = nullptr;
  if ( g_ClientDLL != nullptr )
  {
    v4 = g_ClientDLL->GetSpriteSize(this: g_ClientDLL);
    if ( v4 != 0 )
      v3 = MemAlloc_Alloc(nSize: v4);
  }
  v2->brush.nLightstyleLastComputedFrame = (int)v3;
  v2->type = mod_sprite;
  v2->maxs.y = 0.0;
  v2->maxs.z = 0.0;
  v2->maxs.x = 0.0;
  v2->mins.x = 0.0;
  v2->mins.y = v2->maxs.y;
  v2->mins.z = v2->maxs.z;
  BuildSpriteLoadName(pName: v2->szPathName, pOut: loadName, outLen: 260, (bool *)&bIsAVI, bIsBIK: (bool *)&mod);
  GetSpriteInfo(
    pName: loadName,
    bIsAVI,
    bIsBIK: (bool)mod,
    nWidth: &v2->brush.firstmodelsurface,
    nHeight: &v2->brush.nummodelsurfaces,
    nFrameCount: (int *)&v2->___u10);
  if ( g_ClientDLL != nullptr )
  {
    nLightstyleLastComputedFrame = v2->brush.nLightstyleLastComputedFrame;
    if ( nLightstyleLastComputedFrame != 0 )
      ((void (__stdcall *)(int, char *))g_ClientDLL->InitSprite)(a1: nLightstyleLastComputedFrame, a2: loadName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8DB0
// Name: public: virtual bool CModelLoader::IsLoaded(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::IsLoaded(CModelLoader *this, const model_t *mod)
{
  return mod->nLoadFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100E8DD0
// Name: public: virtual bool CModelLoader::LastLoadedMapHasHDRLighting(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelLoader::LastLoadedMapHasHDRLighting(CModelLoader *this)
{
  return this->m_bMapHasHDRLighting;
}

//------------------------------------------------------------------------------
// Address: 0x100E8DE0
// Name: public: virtual void __near * CModelLoader::GetExtraData(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
struct CEngineSprite *__thiscall CModelLoader::GetExtraData(CModelLoader *this, model_t *model)
{
  if ( model != nullptr )
  {
    if ( model->type == mod_sprite )
    {
      if ( (model->nLoadFlags & 1) != 0 )
        return model->sprite.sprite;
    }
    else if ( model->type == mod_studio )
    {
      return (struct CEngineSprite *)((void *(__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: model->studio);
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100E8E30
// Name: public: virtual bool CModelLoader::Map_GetRenderInfoAllocated(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CModelLoader::Map_GetRenderInfoAllocated(CModelLoader *this)
{
  return this->m_bMapRenderInfoLoaded;
}

//------------------------------------------------------------------------------
// Address: 0x100E8E40
// Name: public: virtual void CModelLoader::Map_SetRenderInfoAllocated(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_SetRenderInfoAllocated(CModelLoader *this, bool allocated)
{
  this->m_bMapRenderInfoLoaded = allocated;
}

//------------------------------------------------------------------------------
// Address: 0x100E8E50
// Name: public: virtual bool CModelLoader::Map_IsValid(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CModelLoader::Map_IsValid(CModelLoader *this, const char *pBaseMapName, bool bQuiet)
{
  void *v3; // esi
  int v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  BSPHeader_t header; // [esp+4h] [ebp-510h] BYREF
  char mapname[260]; // [esp+410h] [ebp-104h] BYREF

  if ( pBaseMapName != nullptr && *pBaseMapName != 0 )
  {
    V_snprintf(pDest: mapname, maxLen: 260, pFormat: "maps/%s.bsp", pBaseMapName);
    v3 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: mapname, a3: "rb", a4: 0, a5: "GAME", a6: 0);
    if ( v3 != nullptr )
    {
      memset(dst: (unsigned __int8 *)&header, value: 0, count: sizeof(header));
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &header, a3: 1036, a4: v3);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      if ( header.ident == 1347633750 )
      {
        if ( (unsigned int)(header.m_nVersion - 19) <= 2 )
        {
          V_strncpy(pDest: s_szBaseMapName, pSrc: pBaseMapName, maxLen: 32);
          return 1;
        }
        if ( !bQuiet )
          _Warning(
            a1: "CModelLoader::Map_IsValid:  Map '%s' bsp version %i, expecting %i\n",
            mapname,
            header.m_nVersion,
            21);
      }
      else if ( !bQuiet )
      {
        _Warning(a1: "CModelLoader::Map_IsValid: '%s' is not a valid BSP file\n", mapname);
      }
    }
    else if ( !bQuiet )
    {
      _Warning(a1: "CModelLoader::Map_IsValid:  No such map '%s'\n", mapname);
    }
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-dumpvidmemstats", a3: 0) != 0 )
    {
      TraceType = CTraceFilter::GetTraceType(this: v6);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    return 0;
  }
  else
  {
    if ( !bQuiet )
      ConMsg(a1: "CModelLoader::Map_IsValid:  Empty mapname!!!\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E8FE0
// Name: public: enum modtype_t CModelLoader::GetTypeFromName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetTypeFromName(CModelLoader *this, const char *pModelName)
{
  const char *FileExtension; // eax
  const char *v3; // esi

  FileExtension = V_GetFileExtension(path: pModelName);
  v3 = FileExtension;
  if ( FileExtension != nullptr )
  {
    if ( _V_stricmp(s1: FileExtension, s2: "spr") == 0
      || _V_stricmp(s1: v3, s2: "vmt") == 0
      || _V_stricmp(s1: v3, s2: "avi") == 0
      || _V_stricmp(s1: v3, s2: "bik") == 0 )
    {
      return 2;
    }
    if ( _V_stricmp(s1: v3, s2: "bsp") == 0 )
      return 1;
    if ( _V_stricmp(s1: v3, s2: "mdl") == 0 )
      return 3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100E93B0
// Name: int ComputeSize(struct studiohwdata_t __near *,int __near *,int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeSize(studiohwdata_t *hwData, int *numVerts, int *pTriCount, bool onlyTopLod)
{
  studiohwdata_t *v4; // esi
  int m_NumLODs; // eax
  studioloddata_t *v7; // edx
  int v8; // ecx
  int *p_m_NumGroup; // eax
  _DWORD *v10; // esi
  int (__thiscall ***v11)(_DWORD); // edi
  int v12; // ecx
  int v13; // edi
  studioloddata_t *pLOD; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  studiomeshdata_t *pMeshData; // [esp+18h] [ebp-Ch]
  int k; // [esp+1Ch] [ebp-8h]
  unsigned int size; // [esp+20h] [ebp-4h]
  int *pTriCounta; // [esp+34h] [ebp+10h]
  int onlyTopLoda; // [esp+38h] [ebp+14h]

  v4 = hwData;
  size = 0;
  m_NumLODs = 1;
  if ( !onlyTopLod )
    m_NumLODs = hwData->m_NumLODs;
  *pTriCount = 0;
  if ( m_NumLODs <= 0 )
    return 0;
  pTriCounta = nullptr;
  for ( i = m_NumLODs; i != 0; --i )
  {
    v7 = (studioloddata_t *)((char *)pTriCounta + (unsigned int)v4->m_pLODs);
    v8 = 0;
    pLOD = v7;
    for ( j = 0; v8 < v4->m_NumStudioMeshes; j = v8 )
    {
      p_m_NumGroup = &v7->m_pMeshData[v8].m_NumGroup;
      pMeshData = (studiomeshdata_t *)p_m_NumGroup;
      k = 0;
      if ( *p_m_NumGroup > 0 )
      {
        onlyTopLoda = 0;
        while ( 1 )
        {
          v10 = (_DWORD *)(onlyTopLoda + p_m_NumGroup[1]);
          v11 = (int (__thiscall ***)(_DWORD))*v10;
          size += (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 104))(a1: *v10) + 2 * v10[5];
          *numVerts += (**v11)(a1: v11);
          v12 = 0;
          if ( (int)v10[1] > 0 )
          {
            v13 = 0;
            do
            {
              *pTriCount += *(_DWORD *)(v13 + v10[3]) / 3;
              ++v12;
              v13 += 35;
            }
            while ( v12 < v10[1] );
          }
          onlyTopLoda += 44;
          if ( ++k >= pMeshData->m_NumGroup )
            break;
          p_m_NumGroup = &pMeshData->m_NumGroup;
        }
        v4 = hwData;
        v8 = j;
        v7 = pLOD;
      }
      ++v8;
    }
    pTriCounta += 8;
  }
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x100E9690
// Name: public: static int CMapLoadHelper::LumpSize(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CMapLoadHelper::LumpSize(int lumpId)
{
  if ( s_MapLumpFiles[lumpId].file != nullptr )
    return s_MapLumpFiles[lumpId].header.lumpLength;
  else
    return s_MapHeader.lumps[lumpId].filelen;
}

//------------------------------------------------------------------------------
// Address: 0x100E96C0
// Name: void EnableHDR(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall EnableHDR(int a1@<esi>, BOOL bEnable)
{
  if ( g_pMaterialSystemHardwareConfig->GetHDREnabled(this: g_pMaterialSystemHardwareConfig) != bEnable )
  {
    g_pMaterialSystemHardwareConfig->SetHDREnabled(this: g_pMaterialSystemHardwareConfig, a2: bEnable);
    materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
    ShutdownWellKnownRenderTargets(a1);
    InitWellKnownRenderTargets(a1);
    UpdateMaterialSystemConfig();
    materials->ReleaseResources(this: materials);
    materials->ReacquireResources(this: materials);
    materials->FinishRenderTargetAllocation(this: materials);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9740
// Name: void Mod_LoadWorldlights(class CMapLoadHelper __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadWorldlights(CMapLoadHelper *lh, bool bIsHDR)
{
  worldbrushdata_t *v2; // ecx
  CMapLoadHelper *v3; // ebx
  unsigned int m_nLumpSize; // edx
  int m_nLumpVersion; // eax
  char *m_szLumpFilename; // eax
  int v7; // esi
  worldbrushdata_t *v8; // edi
  const char *v9; // eax
  dworldlight_t *v10; // eax
  worldbrushdata_t *v11; // esi
  signed int v12; // esi
  char *v13; // eax
  worldbrushdata_t *v14; // edi
  const char *v15; // eax
  dworldlight_t *v16; // eax
  worldbrushdata_t *v17; // ecx
  unsigned __int8 *m_pData; // edx
  float *p_x; // edi
  float *v20; // eax
  unsigned __int8 *v21; // ecx
  int v22; // ebx
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  int v30; // ebx
  double v31; // st7
  double v32; // st7
  int v33; // ebx
  double v34; // st7
  int v35; // ebx
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  int v40; // ebx
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  int v48; // ebx
  int v49; // ebx
  int v50; // ebx
  int v51; // ebx
  int v52; // ebx
  int v53; // ebx
  int v54; // esi
  float *v55; // eax
  unsigned __int8 *v56; // ecx
  int v57; // edx
  double v58; // st7
  double v59; // st7
  int v60; // edx
  double v61; // st7
  int v62; // edx
  double v63; // st7
  int v64; // edx
  double v65; // st7
  int v66; // edx
  double v67; // st7
  int v68; // edx
  double v69; // st7
  int v70; // edi
  const char *v71; // ebx
  const char *v72; // eax
  int v73; // ebx
  int v74; // edi
  dworldlight_t *v75; // ecx
  emittype_t type; // eax
  dworldlight_t *worldlights; // ecx
  float exponent; // xmm2_4
  _DWORD *p_exponent; // ecx
  dworldlight_t *v80; // edx
  long double v81; // st7
  dworldlight_t *v82; // edx
  unsigned int v83; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v2 = s_pMap;
  v3 = lh;
  s_pMap->shadowzbuffers = nullptr;
  m_nLumpSize = lh->m_nLumpSize;
  if ( lh->m_nLumpSize == 0 )
  {
    v2->numworldlights = 0;
    v2->worldlights = nullptr;
    return;
  }
  m_nLumpVersion = lh->m_nLumpVersion;
  if ( m_nLumpVersion != 0 )
  {
    if ( m_nLumpVersion == 1 )
    {
      v2->numworldlights = m_nLumpSize / 0x64;
      m_szLumpFilename = lh->m_szLumpFilename;
      if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
        m_szLumpFilename = s_szMapPathName;
      v7 = lh->m_nLumpSize;
      v8 = v2;
      v9 = va(format: "%s [%s]", m_szLumpFilename, "worldlights");
      v10 = (dworldlight_t *)Hunk_AllocName(size: v7, name: v9, bClear: true);
      v11 = s_pMap;
      v8->worldlights = v10;
      memcpy(dst: (unsigned __int8 *)v11->worldlights, src: lh->m_pData, count: lh->m_nLumpSize);
      goto LABEL_19;
    }
    Host_Error(error: "Invalid worldlight lump version!\n");
  }
  else
  {
    v12 = m_nLumpSize / 0x58;
    v2->numworldlights = m_nLumpSize / 0x58;
    v13 = lh->m_szLumpFilename;
    if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
      v13 = s_szMapPathName;
    v14 = v2;
    v15 = va(format: "%s [%s]", v13, "worldlights");
    v16 = (dworldlight_t *)Hunk_AllocName(size: 100 * v12, name: v15, bClear: true);
    v17 = s_pMap;
    v14->worldlights = v16;
    m_pData = lh->m_pData;
    p_x = &v17->worldlights->origin.x;
    i = 0;
    if ( v12 >= 4 )
    {
      v83 = ((unsigned int)(v12 - 4) >> 2) + 1;
      v20 = p_x + 5;
      v21 = m_pData + 20;
      i = 4 * v83;
      do
      {
        v22 = *((_DWORD *)v21 + 4);
        *p_x = *(float *)m_pData;
        *(v20 - 4) = *((float *)v21 - 4);
        *(v20 - 3) = *((float *)v21 - 3);
        *(v20 - 2) = *((float *)v21 - 2);
        *(v20 - 1) = *((float *)v21 - 1);
        *v20 = *(float *)v21;
        v20[1] = *((float *)v21 + 1);
        v20[2] = *((float *)v21 + 2);
        v20[3] = *((float *)v21 + 3);
        v20[4] = 0.0;
        v23 = *((float *)v21 + 7);
        v20[5] = 0.0;
        v20[6] = 0.0;
        v20[10] = v23;
        v24 = *((float *)v21 + 8);
        *((_DWORD *)v20 + 7) = v22;
        v20[11] = v24;
        v25 = *((float *)v21 + 9);
        v20[8] = *((float *)v21 + 5);
        v20[12] = v25;
        v26 = *((float *)v21 + 10);
        v20[9] = *((float *)v21 + 6);
        v20[13] = v26;
        v27 = *((float *)v21 + 11);
        v20[17] = *((float *)v21 + 14);
        v20[14] = v27;
        v28 = *((float *)v21 + 12);
        v20[18] = *((float *)v21 + 15);
        v20[15] = v28;
        v29 = *((float *)v21 + 13);
        v20[19] = *((float *)v21 + 16);
        v20[16] = v29;
        v30 = *((_DWORD *)v21 + 26);
        v20[20] = *((float *)v21 + 17);
        v20[21] = *((float *)v21 + 18);
        v20[22] = *((float *)v21 + 19);
        v20[23] = *((float *)v21 + 20);
        v20[24] = *((float *)v21 + 21);
        v20[25] = *((float *)v21 + 22);
        v20[26] = *((float *)v21 + 23);
        v20[27] = *((float *)v21 + 24);
        v20[28] = *((float *)v21 + 25);
        v20[29] = 0.0;
        v31 = *((float *)v21 + 29);
        v20[30] = 0.0;
        v20[31] = 0.0;
        v20[35] = v31;
        v32 = *((float *)v21 + 30);
        *((_DWORD *)v20 + 32) = v30;
        v33 = *((_DWORD *)v21 + 27);
        v20[36] = v32;
        v34 = *((float *)v21 + 31);
        *((_DWORD *)v20 + 33) = v33;
        v35 = *((_DWORD *)v21 + 28);
        v20[37] = v34;
        v36 = *((float *)v21 + 32);
        *((_DWORD *)v20 + 34) = v35;
        v20[38] = v36;
        v37 = *((float *)v21 + 33);
        v20[42] = *((float *)v21 + 36);
        v20[39] = v37;
        v38 = *((float *)v21 + 34);
        v20[43] = *((float *)v21 + 37);
        v20[40] = v38;
        v39 = *((float *)v21 + 35);
        v20[44] = *((float *)v21 + 38);
        v20[41] = v39;
        v40 = *((_DWORD *)v21 + 48);
        v20[45] = *((float *)v21 + 39);
        v20[46] = *((float *)v21 + 40);
        v20[47] = *((float *)v21 + 41);
        v20[48] = *((float *)v21 + 42);
        v20[49] = *((float *)v21 + 43);
        v20[50] = *((float *)v21 + 44);
        v20[51] = *((float *)v21 + 45);
        v20[52] = *((float *)v21 + 46);
        v20[53] = *((float *)v21 + 47);
        v20[54] = 0.0;
        v41 = *((float *)v21 + 51);
        v20[55] = 0.0;
        v20[56] = 0.0;
        v20[60] = v41;
        v42 = *((float *)v21 + 52);
        *((_DWORD *)v20 + 57) = v40;
        v20[61] = v42;
        v43 = *((float *)v21 + 53);
        v20[58] = *((float *)v21 + 49);
        v20[62] = v43;
        v44 = *((float *)v21 + 54);
        v20[59] = *((float *)v21 + 50);
        v20[63] = v44;
        v45 = *((float *)v21 + 55);
        v20[67] = *((float *)v21 + 58);
        v20[64] = v45;
        v46 = *((float *)v21 + 56);
        v20[68] = *((float *)v21 + 59);
        v20[65] = v46;
        v47 = *((float *)v21 + 57);
        v20[69] = *((float *)v21 + 60);
        v20[66] = v47;
        v20[70] = *((float *)v21 + 61);
        v20[71] = *((float *)v21 + 62);
        v20[72] = *((float *)v21 + 63);
        v20[73] = *((float *)v21 + 64);
        v20[74] = *((float *)v21 + 65);
        v20[75] = *((float *)v21 + 66);
        v20[76] = *((float *)v21 + 67);
        v20[77] = *((float *)v21 + 68);
        v20[78] = *((float *)v21 + 69);
        v20[79] = 0.0;
        v20[80] = 0.0;
        v20[81] = 0.0;
        v48 = *((_DWORD *)v21 + 70);
        v20[85] = *((float *)v21 + 73);
        *((_DWORD *)v20 + 82) = v48;
        v49 = *((_DWORD *)v21 + 71);
        v20[86] = *((float *)v21 + 74);
        *((_DWORD *)v20 + 83) = v49;
        v50 = *((_DWORD *)v21 + 72);
        v20[87] = *((float *)v21 + 75);
        *((_DWORD *)v20 + 84) = v50;
        v51 = *((_DWORD *)v21 + 80);
        v20[88] = *((float *)v21 + 76);
        *((_DWORD *)v20 + 92) = v51;
        v52 = *((_DWORD *)v21 + 81);
        v20[89] = *((float *)v21 + 77);
        *((_DWORD *)v20 + 93) = v52;
        v53 = *((_DWORD *)v21 + 82);
        v20[90] = *((float *)v21 + 78);
        *((_DWORD *)v20 + 94) = v53;
        m_pData += 352;
        v20[91] = *((float *)v21 + 79);
        v21 += 352;
        p_x += 100;
        v20 += 100;
        --v83;
      }
      while ( v83 != 0 );
      v3 = lh;
    }
    if ( i < v12 )
    {
      v54 = v12 - i;
      v55 = p_x + 5;
      v56 = m_pData + 20;
      do
      {
        v57 = *((_DWORD *)v56 + 4);
        *(v55 - 5) = *((float *)v56 - 5);
        v56 += 88;
        v55 += 25;
        --v54;
        *(v55 - 29) = *((float *)v56 - 26);
        *(v55 - 28) = *((float *)v56 - 25);
        *(v55 - 27) = *((float *)v56 - 24);
        *(v55 - 26) = *((float *)v56 - 23);
        *(v55 - 25) = *((float *)v56 - 22);
        *(v55 - 24) = *((float *)v56 - 21);
        *(v55 - 23) = *((float *)v56 - 20);
        *(v55 - 22) = *((float *)v56 - 19);
        *(v55 - 21) = 0.0;
        v58 = *((float *)v56 - 15);
        *(v55 - 20) = 0.0;
        *(v55 - 19) = 0.0;
        *(v55 - 15) = v58;
        v59 = *((float *)v56 - 14);
        *((_DWORD *)v55 - 18) = v57;
        v60 = *((_DWORD *)v56 - 17);
        *(v55 - 14) = v59;
        v61 = *((float *)v56 - 13);
        *((_DWORD *)v55 - 17) = v60;
        v62 = *((_DWORD *)v56 - 16);
        *(v55 - 13) = v61;
        v63 = *((float *)v56 - 12);
        *((_DWORD *)v55 - 16) = v62;
        v64 = *((_DWORD *)v56 - 8);
        *(v55 - 12) = v63;
        v65 = *((float *)v56 - 11);
        *((_DWORD *)v55 - 8) = v64;
        v66 = *((_DWORD *)v56 - 7);
        *(v55 - 11) = v65;
        v67 = *((float *)v56 - 10);
        *((_DWORD *)v55 - 7) = v66;
        v68 = *((_DWORD *)v56 - 6);
        *(v55 - 10) = v67;
        v69 = *((float *)v56 - 9);
        *((_DWORD *)v55 - 6) = v68;
        *(v55 - 9) = v69;
      }
      while ( v54 != 0 );
    }
  }
  v11 = s_pMap;
LABEL_19:
  if ( r_lightcache_zbuffercache.m_pParent != nullptr && r_lightcache_zbuffercache.m_pParent->m_Value.m_nValue != 0 )
  {
    v70 = 3072 * v11->numworldlights;
    if ( s_MapLumpFiles[v3->m_nLumpID].file != nullptr )
      v71 = v3->m_szLumpFilename;
    else
      v71 = s_szMapPathName;
    v72 = va(format: "%s [%s]", v71, "shadowzbuffers");
    v11->shadowzbuffers = (CCubeMap<LightShadowZBufferSample_t,8> *)Hunk_AllocName(size: v70, name: v72, bClear: true);
    v11 = s_pMap;
    memset(dst: (unsigned __int8 *)s_pMap->shadowzbuffers, value: 0, count: v70);
  }
  v73 = 0;
  if ( v11->numworldlights > 0 )
  {
    v74 = 0;
    do
    {
      v75 = &v11->worldlights[v74];
      type = v75->type;
      if ( type == emit_spotlight )
      {
        if ( v75->constant_attn == 0.0 && v75->linear_attn == 0.0 && v75->quadratic_attn == 0.0 )
          v75->quadratic_attn = 1.0;
        worldlights = v11->worldlights;
        exponent = worldlights[v74].exponent;
        p_exponent = (_DWORD *)&worldlights[v74].exponent;
        if ( exponent == 0.0 )
          *p_exponent = 1065353216;
      }
      else if ( type == emit_point && v75->constant_attn == 0.0 && v75->linear_attn == 0.0 && v75->quadratic_attn == 0.0 )
      {
        v75->quadratic_attn = 1.0;
      }
      v80 = v11->worldlights;
      if ( v80[v74].radius < 1.0 )
      {
        v81 = ComputeLightRadius(pLight: &v80[v74], bIsHDR);
        v82 = v11->worldlights;
        v11 = s_pMap;
        v82[v74].radius = v81;
      }
      ++v73;
      ++v74;
    }
    while ( v73 < v11->numworldlights );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E9EA0
// Name: CheckSurfaceLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall CheckSurfaceLighting(worldbrushdata_t *pBrushData@<eax>, int a2@<ebp>, msurface2_t *a3)
{
  char *v3; // esi
  bool v4; // zf
  int v5; // edi
  int v6; // ecx
  int i; // eax
  msurfacelighting_t *v8; // ecx
  const ColorRGBExp32 *v9; // eax
  const ColorRGBExp32 *v10; // edi
  float v11; // xmm3_4
  unsigned __int8 v12; // al
  int v13; // edi
  char *v14; // esi
  char *v15; // edx
  int v16; // eax
  Vector v17; // [esp+24h] [ebp-4Ch] BYREF
  Vector c; // [esp+30h] [ebp-40h] BYREF
  Vector maxLight; // [esp+3Ch] [ebp-34h]
  char *v20; // [esp+48h] [ebp-28h]
  msurfacelighting_t *v21; // [esp+4Ch] [ebp-24h]
  float maxLen; // [esp+50h] [ebp-20h]
  msurfacelighting_t *pLighting; // [esp+54h] [ebp-1Ch]
  int v24; // [esp+58h] [ebp-18h]
  unsigned __int8 color[4]; // [esp+5Ch] [ebp-14h]
  int v26; // [esp+60h] [ebp-10h]
  int maps; // [esp+64h] [ebp-Ch]
  int offset; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  maps = a2;
  offset = retaddr;
  host_state.worldbrush = pBrushData;
  v3 = (char *)pBrushData->surfacelighting + (((char *)a3 - (char *)pBrushData->surfaces2) & 0xFFFFFFE0);
  v4 = *((_DWORD *)v3 + 7) == 0;
  v20 = v3;
  if ( !v4 )
  {
    v5 = (*((__int16 *)v3 + 2) + 1) * (*((__int16 *)v3 + 3) + 1);
    *(_DWORD *)color = v5;
    if ( SurfHasBumpedLightmaps(surfID: a3) )
    {
      *(_DWORD *)color = 4 * v5;
      v5 *= 4;
    }
    v6 = 0;
    v26 = 0;
    for ( i = 1; i < 4; ++i )
    {
      if ( v3[i + 24] == -1 )
        break;
      v26 = i;
      v6 = i;
    }
    if ( v6 >= 1 )
    {
      v24 = v6;
      v8 = (msurfacelighting_t *)(4 * v5 * v6);
      pLighting = v8;
      LODWORD(maxLight.x) = -4 * v5;
      while ( 1 )
      {
        v9 = (const ColorRGBExp32 *)((char *)v8 + *((_DWORD *)v3 + 7));
        maxLight.z = -1.0;
        memset(&c, 0, sizeof(c));
        if ( v5 > 0 )
        {
          v10 = v9;
          v21 = *(msurfacelighting_t **)color;
          do
          {
            ColorRGBExp32ToVector(in: v10, out: &v17);
            v11 = fsqrt((float)((float)(v17.y * v17.y) + (float)(v17.z * v17.z)) + (float)(v17.x * v17.x));
            if ( v11 > maxLight.z )
            {
              c = v17;
              maxLight.z = v11;
            }
            ++v10;
            v21 = (msurfacelighting_t *)((char *)v21 - 1);
          }
          while ( v21 != nullptr );
          v5 = *(_DWORD *)color;
        }
        LOBYTE(maxLen) = LinearToScreenGamma(f: c.x);
        BYTE1(maxLen) = LinearToScreenGamma(f: c.y);
        v12 = LinearToScreenGamma(f: c.z);
        if ( LOBYTE(maxLen) <= 1u && BYTE1(maxLen) <= 1u && v12 <= 1u )
        {
          if ( v24 < v26 )
          {
            v13 = 4 * v24;
            v14 = &v3[v24 + 24];
            v21 = pLighting;
            LODWORD(maxLight.y) = v26 - v24;
            do
            {
              memcpy(
                dst: (unsigned __int8 *)v21 + *((_DWORD *)v20 + 7),
                src: (unsigned __int8 *)v21 + 4 * *(_DWORD *)color + *((_DWORD *)v20 + 7),
                count: 4 * *(_DWORD *)color);
              v15 = v20;
              *v14 = v14[1];
              *(_DWORD *)(*((_DWORD *)v15 + 7) - v13 - 4) = *(_DWORD *)(*((_DWORD *)v15 + 7) - v13 - 8);
              v21 = (msurfacelighting_t *)((char *)v21 + 4 * *(_DWORD *)color);
              ++v14;
              v13 += 4;
              --LODWORD(maxLight.y);
            }
            while ( LODWORD(maxLight.y) != 0 );
            v3 = v20;
            v5 = *(_DWORD *)color;
          }
          v16 = v26;
          v3[v26 + 24] = -1;
          v26 = v16 - 1;
        }
        pLighting = (msurfacelighting_t *)((char *)pLighting + LODWORD(maxLight.x));
        if ( --v24 == 0 )
          break;
        v8 = pLighting;
      }
      if ( v26 == 0 )
        a3->flags &= ~0x400u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA100
// Name: CalcSurfaceExtents
// Source: json
//------------------------------------------------------------------------------
void __usercall CalcSurfaceExtents(msurface2_t *surfID@<edi>)
{
  float v1; // xmm4_4
  mtexinfo_t *v2; // ebx
  bool v3; // zf
  float v4; // xmm5_4
  int firstvertindex; // eax
  unsigned __int16 *vertindices; // edx
  mvertex_t *vertexes; // esi
  float y; // xmm6_4
  unsigned __int16 *v9; // edx
  msurface2_t **flags_high; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // esi
  int v17; // ecx
  float v18; // xmm0_4
  const char *v19; // eax
  int bmins[2]; // [esp+0h] [ebp-4Ch]
  int bmaxs[2]; // [esp+8h] [ebp-44h]
  float textureMins[2]; // [esp+10h] [ebp-3Ch]
  float textureMaxs[2]; // [esp+18h] [ebp-34h]
  float v24; // [esp+20h] [ebp-2Ch]
  float v25; // [esp+24h] [ebp-28h]
  float x; // [esp+28h] [ebp-24h]
  float z; // [esp+2Ch] [ebp-20h]
  int w_low; // [esp+30h] [ebp-1Ch]
  float v29; // [esp+34h] [ebp-18h]
  int y_low; // [esp+38h] [ebp-14h]
  int z_low; // [esp+3Ch] [ebp-10h]
  float w; // [esp+40h] [ebp-Ch]
  int v33; // [esp+44h] [ebp-8h]
  msurface2_t **p_surfaces2; // [esp+48h] [ebp-4h]

  v1 = 999999.0;
  v2 = &s_pMap->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v3 = HIBYTE(surfID->flags) == 0;
  v4 = 999999.0;
  textureMins[1] = 999999.0;
  textureMins[0] = 999999.0;
  textureMaxs[1] = -99999.0;
  textureMaxs[0] = -99999.0;
  if ( !v3 )
  {
    firstvertindex = surfID->firstvertindex;
    vertindices = s_pMap->vertindices;
    vertexes = s_pMap->vertexes;
    y = v2->textureVecsTexelsPerWorldUnits[0].y;
    x = v2->textureVecsTexelsPerWorldUnits[0].x;
    z = v2->textureVecsTexelsPerWorldUnits[0].z;
    w_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[0].w);
    y_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[1].y);
    v29 = v2->textureVecsTexelsPerWorldUnits[1].x;
    v9 = &vertindices[firstvertindex];
    flags_high = (msurface2_t **)HIBYTE(surfID->flags);
    z_low = SLODWORD(v2->textureVecsTexelsPerWorldUnits[1].z);
    w = v2->textureVecsTexelsPerWorldUnits[1].w;
    p_surfaces2 = flags_high;
    do
    {
      v11 = vertexes[*v9].position.y;
      v12 = vertexes[*v9].position.x;
      v13 = vertexes[*v9].position.z;
      v14 = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      if ( v4 > v14 )
        v4 = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      if ( v14 > textureMaxs[0] )
        textureMaxs[0] = (float)((float)((float)(x * v12) + (float)(y * v11)) + (float)(z * v13)) + *(float *)&w_low;
      v15 = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11)) + (float)(*(float *)&z_low * v13)) + w;
      if ( v1 > v15 )
        v1 = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11)) + (float)(*(float *)&z_low * v13))
           + w;
      if ( v15 > textureMaxs[1] )
        textureMaxs[1] = (float)((float)((float)(v29 * v12) + (float)(*(float *)&y_low * v11))
                               + (float)(*(float *)&z_low * v13))
                       + w;
      ++v9;
      p_surfaces2 = (msurface2_t **)((char *)p_surfaces2 - 1);
    }
    while ( p_surfaces2 != nullptr );
    textureMins[1] = v1;
    textureMins[0] = v4;
  }
  v16 = 0;
  LODWORD(z) = &s_pMap->surfaces1;
  p_surfaces2 = &s_pMap->surfaces2;
  LODWORD(x) = &s_pMap->surfacelighting;
  do
  {
    if ( *(_WORD *)(*(_DWORD *)LODWORD(x) + 2 * (v16 + 16 * (surfID - *p_surfaces2)) + 4) == 0
      && *(_DWORD *)(32 * (surfID - *p_surfaces2) + *(_DWORD *)LODWORD(x) + 28) == 0 )
    {
      surfID->flags |= 1u;
    }
    v25 = textureMins[v16];
    v33 = LOBYTE(w) | 0xC00;
    z_low = (int)v25;
    v17 = z_low;
    v18 = textureMaxs[v16];
    bmins[v16] = z_low;
    v24 = v18;
    y_low = LOBYTE(v29) | 0x800;
    w_low = (int)v18;
    bmaxs[v16] = w_low;
    *(_DWORD *)(*(_DWORD *)LODWORD(z) + 4 * (v16 + 4 * (surfID - *p_surfaces2))) = v17;
    *(_WORD *)(*(_DWORD *)LODWORD(z) + 2 * (v16 + 8 * (surfID - *p_surfaces2)) + 8) = LOWORD(bmaxs[v16])
                                                                                    - LOWORD(bmins[v16]);
    if ( (v2->flags & 0x400) == 0
      && *(__int16 *)(*(_DWORD *)LODWORD(x) + 2 * (v16 + 16 * (surfID - *p_surfaces2)) + 4) > ((surfID->flags & 0x800) != 0
                                                                                             ? 128
                                                                                             : 35) )
    {
      v19 = v2->material->GetName(this: v2->material);
      Sys_Error(error: "Bad surface extents on texture %s", v19);
    }
    ++v16;
  }
  while ( v16 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x100EA3C0
// Name: bool Mod_NeedsLightstyleUpdate(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Mod_NeedsLightstyleUpdate(model_t *pModel)
{
  int nLightstyleCount; // edx
  int v2; // eax

  nLightstyleCount = pModel->brush.nLightstyleCount;
  if ( (_WORD)nLightstyleCount == 0 )
    return 0;
  v2 = 0;
  while ( d_lightstyleframe[g_ModelLoader.m_LightStyleList.m_Memory.m_pMemory[pModel->brush.nLightstyleIndex + v2]] <= pModel->brush.nLightstyleLastComputedFrame )
  {
    if ( ++v2 >= nLightstyleCount )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EA410
// Name: int Mod_GetModelMaterials(struct model_t __near *,int,class IMaterial __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GetModelMaterials(model_t *pModel, int count, IMaterial **ppMaterials)
{
  int result; // eax
  studiohdr_t *v4; // eax
  int i; // edi
  worldbrushdata_t *pShared; // edx
  int v7; // ecx
  IMaterial *material; // edx
  int v9; // ecx

  result = 0;
  if ( pModel->type == mod_brush )
  {
    for ( i = 0; i < pModel->brush.nummodelsurfaces; ++i )
    {
      pShared = pModel->brush.pShared;
      v7 = (int)&pShared->surfaces2[i + pModel->brush.firstmodelsurface];
      if ( (*(_BYTE *)v7 & 0x10) == 0 )
      {
        material = pShared->texinfo[*(unsigned __int16 *)(v7 + 22) >> 1].material;
        v9 = result - 1;
        if ( result < 1 )
          goto LABEL_11;
        while ( ppMaterials[v9] != material )
        {
          if ( --v9 < 0 )
            goto LABEL_11;
        }
        if ( v9 < 0 )
LABEL_11:
          ppMaterials[result++] = material;
        if ( result >= count )
          break;
      }
    }
  }
  else if ( pModel->type == mod_studio )
  {
    v4 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: pModel->studio);
    return g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v4, a3: count, a4: ppMaterials);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EA4D0
// Name: MarkWaterSurfaces_ProcessLeafNode
// Source: json
//------------------------------------------------------------------------------
void __usercall MarkWaterSurfaces_ProcessLeafNode(mleaf_t *pLeaf@<esi>)
{
  worldbrushdata_t *worldbrush; // eax
  int v2; // ecx
  int v3; // ebx
  msurface2_t *v4; // edi
  unsigned int flags; // eax
  int v6; // edi
  IDispInfo *v7; // eax
  msurface2_t *v8; // eax
  msurface2_t **pHandle; // [esp+8h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v2 = 0;
  v3 = pLeaf->leafWaterDataID != -1 ? 0x20000 : 0x40000;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v4 = pHandle[v2];
      flags = v4->flags;
      if ( (v4->flags & 0x10000) == 0 && (flags & 0x800) == 0 )
        v4->flags = v3 | flags;
      ++v2;
    }
    while ( v2 < pLeaf->nummarksurfaces );
    worldbrush = host_state.worldbrush;
  }
  v6 = 0;
  if ( pLeaf->dispCount != 0 )
  {
    while ( 1 )
    {
      v7 = DispInfo_IndexArray(
             hArray: (_DWORD *)worldbrush->hDispInfos,
             iElement: worldbrush->m_pDispInfoReferences[v6 + pLeaf->dispListStart]);
      v8 = v7->GetParent(this: v7);
      v8->flags |= v3;
      if ( ++v6 >= pLeaf->dispCount )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA5D0
// Name: SurfFlagsToSortGroup
// Source: json
//------------------------------------------------------------------------------
int __usercall SurfFlagsToSortGroup@<eax>(msurface2_t *surfID@<edi>, int flags@<eax>)
{
  IMaterial *material; // ecx
  const char *v5; // eax
  Vector vecCenter; // [esp+1Ch] [ebp-Ch] BYREF

  if ( (flags & 0x10000) != 0 )
    return 3;
  if ( (flags & 0x60000) == 0x60000 )
    return 2;
  if ( (flags & 0x20000) != 0 )
    return 1;
  if ( (flags & 0x40000) == 0 && ++warningcount < 10 )
  {
    Surf_ComputeCentroid(surfID, pVecCentroid: &vecCenter);
    material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
    v5 = (const char *)material->GetName(this: material);
    DevWarning(a1: "SurfFlagsToSortGroup:  unhandled flags (%X) (%s)!\n", flags, v5);
    DevWarning(a1: "- This implies you have a surface (usually a displacement) embedded in solid.\n");
    DevWarning(a1: "- Look near (%.1f, %.1f, %.1f)\n", vecCenter.x, vecCenter.y, vecCenter.z);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EA750
// Name: public: void CBrushBSPIterator::MarkModelSurfaces(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushBSPIterator::MarkModelSurfaces(CBrushBSPIterator *this, int flags)
{
  int nummodelsurfaces; // esi
  int i; // edx
  msurface2_t *v4; // eax

  nummodelsurfaces = this->m_pBrush->brush.nummodelsurfaces;
  for ( i = 0; i < nummodelsurfaces; v4->flags = flags | v4->flags & 0xFFF9FFFF )
  {
    v4 = &this->m_pShared->surfaces2[i + this->m_pBrush->brush.firstmodelsurface];
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EA860
// Name: private: void CModelLoader::Studio_UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Studio_UnloadModel(CModelLoader *this, model_t *pModel)
{
  int ModelMaterials; // ebx
  int i; // esi
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-200h] BYREF

  if ( (pModel->nLoadFlags & 0x20000) != 0 )
  {
    ModelMaterials = Mod_GetModelMaterials(pModel, count: 128, ppMaterials: pMaterials);
    for ( i = 0; i < ModelMaterials; ++i )
      pMaterials[i]->DecrementReferenceCount(this: pMaterials[i]);
    pModel->nLoadFlags &= ~0x20000u;
  }
  pModel->nLoadFlags &= 0xFFFEFFFE;
  ((void (__stdcall *)(_DWORD))g_pMDLCache->Release)(a1: pModel->studio);
  pModel->studio = -1;
  pModel->type = mod_bad;
}

//------------------------------------------------------------------------------
// Address: 0x100EA990
// Name: public: static void CMapLoadHelper::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMapLoadHelper::Shutdown()
{
  lumpfiles_t *v0; // esi

  if ( --s_nMapLoadRecursion <= 0 )
  {
    if ( s_MapFileHandle != nullptr )
    {
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: s_MapFileHandle);
      s_MapFileHandle = nullptr;
    }
    v0 = s_MapLumpFiles;
    do
    {
      if ( v0->file != nullptr )
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0->file);
      ++v0;
    }
    while ( (int)v0 < (int)s_szMapPathNameOnDisk );
    _V_memset(dest: s_MapLumpFiles, fill: 0, count: 1792);
    s_szMapPathName[0] = 0;
    _V_memset(dest: &s_MapHeader, fill: 0, count: 1036);
    s_pMap = nullptr;
    if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_MapBuffer.m_Memory.m_pMemory);
      CUtlBuffer::SetExternalBuffer(this: &s_MapBuffer, pMemory: nullptr, nSize: 0, nInitialPut: 0, nFlags: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAA60
// Name: public: CMapLoadHelper::CMapLoadHelper(int,bool)
// Source: json
//------------------------------------------------------------------------------
CMapLoadHelper *__thiscall CMapLoadHelper::CMapLoadHelper(
        CMapLoadHelper *this,
        unsigned int lumpToLoad,
        bool bUncompress)
{
  lump_t *v4; // eax
  void *v5; // ecx
  void *file; // ecx
  bool v8; // al
  int m_nLumpOffset; // edi
  int m_nLumpSize; // ebx
  unsigned __int8 *v11; // eax
  unsigned int nBufferAlign; // [esp+Ch] [ebp-10h] BYREF
  unsigned int nSizeAlign; // [esp+10h] [ebp-Ch] BYREF
  unsigned int nOffsetAlign; // [esp+14h] [ebp-8h] BYREF
  void *fileToUse; // [esp+18h] [ebp-4h]

  if ( lumpToLoad >= 0x40 )
    Sys_Error(error: "Can't load lump %i, range is 0 to %i!!!", lumpToLoad, 63);
  v4 = &s_MapHeader.lumps[lumpToLoad];
  this->m_nLumpSize = 0;
  this->m_nLumpOffset = -1;
  this->m_nLumpID = lumpToLoad;
  this->m_pData = nullptr;
  this->m_pRawData = nullptr;
  this->m_pUncompressedData = nullptr;
  this->m_nUncompressedLumpSize = 0;
  this->m_bUncompressedDataExternal = false;
  this->m_nLumpSize = v4->filelen;
  v5 = s_MapFileHandle;
  this->m_nLumpOffset = v4->fileofs;
  this->m_nLumpVersion = v4->version;
  fileToUse = v5;
  file = s_MapLumpFiles[lumpToLoad].file;
  if ( file != nullptr )
  {
    this->m_nLumpSize = s_MapLumpFiles[lumpToLoad].header.lumpLength;
    fileToUse = file;
    this->m_nLumpOffset = s_MapLumpFiles[lumpToLoad].header.lumpOffset;
    this->m_nLumpVersion = s_MapLumpFiles[lumpToLoad].header.lumpVersion;
    GenerateLumpFileName(
      bspfilename: s_szMapPathName,
      lumpfilename: this->m_szLumpFilename,
      iBufferSize: 260,
      iIndex: s_MapLumpFiles[lumpToLoad].lumpfileindex);
  }
  if ( this->m_nLumpSize == 0 )
    return this;
  if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
  {
    this->m_pData = &s_MapBuffer.m_Memory.m_pMemory[this->m_nLumpOffset];
    this->m_nUncompressedLumpSize = this->m_nLumpSize;
    return this;
  }
  if ( s_MapFileHandle == nullptr )
    Sys_Error(error: "Can't load map from invalid handle!!!");
  v8 = g_pFileSystem->GetOptimalIOConstraints(
         this: g_pFileSystem,
         a2: fileToUse,
         a3: &nOffsetAlign,
         a4: &nSizeAlign,
         a5: &nBufferAlign);
  if ( v8 )
    v8 = this->m_nLumpOffset % 4 == 0;
  m_nLumpOffset = this->m_nLumpOffset;
  m_nLumpSize = this->m_nLumpSize;
  if ( this->m_nLumpSize == 0 )
    m_nLumpSize = 1;
  if ( v8 )
  {
    m_nLumpOffset &= ~(nOffsetAlign - 1);
    m_nLumpSize = ~(nSizeAlign - 1) & (m_nLumpSize + this->m_nLumpOffset - m_nLumpOffset + nSizeAlign - 1);
  }
  v11 = (unsigned __int8 *)g_pFileSystem->AllocOptimalReadBuffer(
                             this: g_pFileSystem,
                             a2: fileToUse,
                             a3: m_nLumpSize,
                             a4: m_nLumpOffset);
  this->m_pRawData = v11;
  if ( v11 != nullptr )
    goto LABEL_19;
  if ( this->m_nLumpSize != 0 )
  {
    Sys_Error(error: "Can't load lump %i, allocation of %i bytes failed!!!", lumpToLoad, this->m_nLumpSize + 1);
LABEL_19:
    if ( this->m_nLumpSize != 0 )
    {
      g_pFileSystem->Seek(
        this: &g_pFileSystem->IBaseFileSystem,
        a2: fileToUse,
        a3: m_nLumpOffset,
        a4: FILESYSTEM_SEEK_HEAD);
      g_pFileSystem->ReadEx(this: g_pFileSystem, a2: this->m_pRawData, a3: m_nLumpSize, a4: m_nLumpSize, a5: fileToUse);
      this->m_pData = &this->m_pRawData[this->m_nLumpOffset - m_nLumpOffset];
    }
  }
  this->m_nUncompressedLumpSize = this->m_nLumpSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EAC50
// Name: void Map_CheckFeatureFlags(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_CheckFeatureFlags()
{
  int lumpLength; // eax
  int v1; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  lumpLength = s_MapLumpFiles[59].header.lumpLength;
  g_bLoadedMapHasBakedPropLighting = false;
  g_bBakedPropLightingNoSeparateHDR = false;
  if ( s_MapLumpFiles[59].file == nullptr )
    lumpLength = s_MapHeader.lumps[59].filelen;
  if ( lumpLength > 0 )
  {
    CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x3Bu, bUncompress: true);
    v1 = *(_DWORD *)lh.m_pData;
    g_bLoadedMapHasBakedPropLighting = (*(_DWORD *)lh.m_pData & 3) != 0;
    g_bBakedPropLightingNoSeparateHDR = (v1 & 2) == 0;
    if ( lh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EACE0
// Name: bool Map_CheckForHDR(struct model_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall Map_CheckForHDR@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        lumpfileheader_t *a3@<esi>,
        model_t *pModel,
        char *pMapPathName)
{
  int lumpLength; // eax
  int filelen; // eax
  char v7; // bl
  int v8; // eax
  BOOL bEnableHDR; // [esp+0h] [ebp-4h]

  CMapLoadHelper::Init(a1, a2, p_lumpHeader: a3, pMapModel: pModel, pPathName: pMapPathName);
  lumpLength = s_MapLumpFiles[53].header.lumpLength;
  if ( s_MapLumpFiles[53].file == nullptr )
    lumpLength = s_MapHeader.lumps[53].filelen;
  if ( lumpLength <= 0 )
    goto LABEL_8;
  filelen = s_MapLumpFiles[54].header.lumpLength;
  if ( s_MapLumpFiles[54].file == nullptr )
    filelen = s_MapHeader.lumps[54].filelen;
  if ( filelen <= 0 )
LABEL_8:
    v7 = 0;
  else
    v7 = 1;
  if ( s_MapHeader.m_nVersion >= 20 )
  {
    v8 = s_MapLumpFiles[55].header.lumpLength;
    if ( s_MapLumpFiles[55].file == nullptr )
      v8 = s_MapHeader.lumps[55].filelen;
    if ( v8 == 0 )
    {
      v7 = 0;
LABEL_18:
      LOBYTE(bEnableHDR) = 0;
      goto LABEL_19;
    }
  }
  if ( v7 == 0 )
    goto LABEL_18;
  if ( mat_hdr_level.m_pParent == nullptr )
    goto LABEL_18;
  if ( mat_hdr_level.m_pParent->m_Value.m_nValue < 2 )
    goto LABEL_18;
  LOBYTE(bEnableHDR) = 1;
  if ( g_pMaterialSystemHardwareConfig->GetHardwareHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
    goto LABEL_18;
LABEL_19:
  EnableHDR(a1: (int)a3, bEnable: bEnableHDR);
  Map_CheckFeatureFlags();
  CMapLoadHelper::Shutdown();
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100EADA0
// Name: AllocateLightingData
// Source: json
//------------------------------------------------------------------------------
void __usercall AllocateLightingData(worldbrushdata_t *pBrushData@<edi>, unsigned int nSize)
{
  int v2; // esi
  ColorRGBExp32 *v3; // eax
  CMemoryStack *m_pLightingDataStack; // ecx
  CMemoryStack *v5; // esi
  unsigned int m_alignment; // eax
  unsigned int v7; // ecx
  int v8; // ecx
  ColorRGBExp32 *m_pNextAlloc; // eax
  unsigned __int8 *v10; // ebx
  ColorRGBExp32 *v11; // [esp+4h] [ebp-4h]

  if ( r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0
    || r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue != 0
    || r_hunkalloclightmaps.m_pParent == nullptr
    || r_hunkalloclightmaps.m_pParent->m_Value.m_nValue == 0 )
  {
    g_bHunkAllocLightmaps = false;
    if ( r_keepstyledlightmapsonly.m_pParent == nullptr
      || r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue == 0
      || r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue != 0
      || (m_pLightingDataStack = pBrushData->m_pLightingDataStack) == nullptr )
    {
      v2 = nSize;
      v3 = (ColorRGBExp32 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
      goto LABEL_22;
    }
    CMemoryStack::Term(this: m_pLightingDataStack);
    CMemoryStack::Init(
      this: pBrushData->m_pLightingDataStack,
      pszAllocOwner: "LightingData",
      maxSize: nSize,
      commitSize: 0,
      initialCommit: 0,
      alignment: 0x10u);
    v5 = pBrushData->m_pLightingDataStack;
    m_alignment = v5->m_alignment;
    v7 = nSize;
    if ( nSize <= m_alignment )
      v7 = v5->m_alignment;
    v8 = ~(m_alignment - 1) & (m_alignment + v7 - 1);
    m_pNextAlloc = (ColorRGBExp32 *)v5->m_pNextAlloc;
    v10 = &v5->m_pNextAlloc[v8];
    v11 = (ColorRGBExp32 *)v5->m_pNextAlloc;
    if ( v10 > v5->m_pCommitLimit )
    {
      if ( !CMemoryStack::CommitTo(this: v5, pNextAlloc: v10) )
      {
        m_pNextAlloc = nullptr;
LABEL_20:
        pBrushData->lightdata = m_pNextAlloc;
        pBrushData->m_nLightingDataSize = nSize;
        pBrushData->m_bUnloadedAllLightmaps = false;
        return;
      }
      m_pNextAlloc = v11;
    }
    v5->m_pNextAlloc = v10;
    goto LABEL_20;
  }
  v2 = nSize;
  g_bHunkAllocLightmaps = true;
  v3 = (ColorRGBExp32 *)Hunk_AllocName(size: nSize, name: "Lightmaps", bClear: false);
LABEL_22:
  pBrushData->m_nLightingDataSize = v2;
  pBrushData->lightdata = v3;
  pBrushData->m_bUnloadedAllLightmaps = false;
}

//------------------------------------------------------------------------------
// Address: 0x100EAED0
// Name: void Mod_LoadLighting(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLighting(bool bLoadHDR)
{
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: bLoadHDR ? 53 : 8, bUncompress: false);
  if ( lh.m_nLumpSize != 0 )
  {
    AllocateLightingData(pBrushData: s_pMap, nSize: lh.m_nUncompressedLumpSize);
    if ( s_pMap->lightdata != nullptr )
      CMapLoadHelper::UncompressLump(this: &lh, pExternalBuffer: (unsigned __int8 *)s_pMap->lightdata);
  }
  else
  {
    s_pMap->lightdata = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EAF70
// Name: void Mod_LoadFaceBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadFaceBrushes()
{
  worldbrushdata_t *v0; // eax
  worldbrushdata_t *v1; // esi
  worldbrushdata_t *v2; // esi
  unsigned __int16 *v3; // eax
  worldbrushdata_t *v4; // ecx
  CMapLoadHelper lh; // [esp+0h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x17u, bUncompress: true);
  if ( lh.m_nLumpSize != 0 )
  {
    v1 = s_pMap;
    v1->m_pSurfaceBrushList = (dfacebrushlist_t *)Hunk_AllocName(
                                                    size: lh.m_nLumpSize,
                                                    name: "FaceBrushLists",
                                                    bClear: false);
    memcpy(dst: (unsigned __int8 *)s_pMap->m_pSurfaceBrushList, src: lh.m_pData, count: lh.m_nLumpSize);
    if ( lh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
    CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x16u, bUncompress: true);
    v2 = s_pMap;
    v3 = (unsigned __int16 *)Hunk_AllocName(size: lh.m_nLumpSize, name: "FaceBrushes", bClear: false);
    v4 = s_pMap;
    v2->m_pSurfaceBrushes = v3;
    memcpy(dst: (unsigned __int8 *)v4->m_pSurfaceBrushes, src: lh.m_pData, count: lh.m_nLumpSize);
  }
  else
  {
    v0 = s_pMap;
    s_pMap->m_pSurfaceBrushes = nullptr;
    v0->m_pSurfaceBrushList = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB080
// Name: void Mod_LoadVertices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertices()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // esi
  signed int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  mvertex_t *v5; // eax
  worldbrushdata_t *v6; // ecx
  int v7; // ebx
  unsigned int v8; // ecx
  double v9; // st7
  unsigned __int8 *v10; // edx
  int v11; // esi
  float *p_z; // ecx
  int v13; // edi
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 3u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadVertices: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "vertexes");
  v5 = (mvertex_t *)Hunk_AllocName(size: 12 * v2, name: v4, bClear: true);
  v6 = s_pMap;
  v7 = 0;
  s_pMap->vertexes = v5;
  v6->numvertexes = v2;
  if ( v2 >= 4 )
  {
    v8 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v7 = 4 * v8;
    do
    {
      v9 = *(float *)m_pData;
      m_pData += 48;
      v5->position.x = v9;
      v5 += 4;
      --v8;
      v5[-4].position.y = *((float *)m_pData - 11);
      v5[-4].position.z = *((float *)m_pData - 10);
      v5[-3].position.x = *((float *)m_pData - 9);
      v5[-3].position.y = *((float *)m_pData - 8);
      v5[-3].position.z = *((float *)m_pData - 7);
      v5[-2].position.x = *((float *)m_pData - 6);
      v5[-2].position.y = *((float *)m_pData - 5);
      v5[-2].position.z = *((float *)m_pData - 4);
      v5[-1].position.x = *((float *)m_pData - 3);
      v5[-1].position.y = *((float *)m_pData - 2);
      v5[-1].position.z = *((float *)m_pData - 1);
    }
    while ( v8 != 0 );
  }
  if ( v7 < v2 )
  {
    v10 = m_pData + 8;
    v11 = m_pData - (unsigned __int8 *)v5;
    p_z = &v5->position.z;
    v13 = v2 - v7;
    do
    {
      v10 += 12;
      *(p_z - 2) = *(float *)((char *)p_z + v11 - 8);
      p_z += 3;
      --v13;
      *(p_z - 4) = *((float *)v10 - 4);
      *(p_z - 3) = *((float *)v10 - 3);
    }
    while ( v13 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB1F0
// Name: struct medge_t __near * Mod_LoadEdges(void)
// Source: json
//------------------------------------------------------------------------------
medge_t *__cdecl Mod_LoadEdges()
{
  unsigned int m_nLumpSize; // eax
  unsigned __int8 *m_pData; // esi
  int v2; // edi
  _BYTE *v3; // eax
  _BYTE *v4; // ebx
  int v5; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xCu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 3) != 0 )
  {
    Host_Error(error: "Mod_LoadEdges: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 2;
  v3 = MemAlloc_Alloc(nSize: (unsigned __int64)(m_nLumpSize >> 2) >> 30 != 0 ? -1 : 4 * (m_nLumpSize >> 2));
  v4 = v3;
  if ( v2 > 0 )
  {
    v5 = v3 - m_pData;
    do
    {
      *(_WORD *)&m_pData[v5] = *(_WORD *)m_pData;
      *(_WORD *)&m_pData[v5 + 2] = *((_WORD *)m_pData + 1);
      m_pData += 4;
      --v2;
    }
    while ( v2 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
  return (medge_t *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100EB2A0
// Name: void Mod_LoadTexinfo(class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadTexinfo(CMapLoadHelper *lh)
{
  signed int v1; // esi
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  mtexinfo_t *v4; // eax
  worldbrushdata_t *v5; // edx
  int m_nValue; // ecx
  unsigned __int8 *v7; // edi
  float *i; // esi
  int v9; // eax
  float v10; // [esp-1Ch] [ebp-2Ch]
  unsigned __int8 *m_pData; // [esp-Ch] [ebp-1Ch]
  signed int v12; // [esp-8h] [ebp-18h]
  int v13; // [esp-4h] [ebp-14h]
  bool in_3; // [esp+3h] [ebp-Dh]

  m_pData = lh->m_pData;
  if ( lh->m_nLumpSize % 0x48u != 0 )
    Host_Error(error: "Mod_LoadTexinfo: funny lump size in %s", s_szMapPathName);
  v1 = lh->m_nLumpSize / 0x48u;
  v12 = v1;
  m_szLumpFilename = lh->m_szLumpFilename;
  if ( s_MapLumpFiles[lh->m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "texinfo");
  v4 = (mtexinfo_t *)Hunk_AllocName(size: 80 * v1, name: v3, bClear: true);
  v5 = s_pMap;
  s_pMap->texinfo = v4;
  v5->numtexinfo = v1;
  if ( mat_loadtextures.m_pParent != nullptr )
    m_nValue = mat_loadtextures.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  in_3 = m_nValue != 0;
  v13 = 0;
  if ( v1 > 0 )
  {
    v7 = m_pData + 4;
    for ( i = &v4->lightmapVecsLuxelsPerWorldUnits[0].y; ; i += 20 )
    {
      *(i - 9) = *((float *)v7 - 1);
      *(i - 1) = *((float *)v7 + 7);
      *(i - 8) = *(float *)v7;
      *i = *((float *)v7 + 8);
      *(i - 7) = *((float *)v7 + 1);
      i[1] = *((float *)v7 + 9);
      *(i - 6) = *((float *)v7 + 2);
      i[2] = *((float *)v7 + 10);
      *(i - 5) = *((float *)v7 + 3);
      i[3] = *((float *)v7 + 11);
      *(i - 4) = *((float *)v7 + 4);
      i[4] = *((float *)v7 + 12);
      *(i - 3) = *((float *)v7 + 5);
      i[5] = *((float *)v7 + 13);
      *(i - 2) = *((float *)v7 + 6);
      i[6] = *((float *)v7 + 14);
      v10 = fsqrt((float)((float)(*(i - 1) * *(i - 1)) + (float)(i[1] * i[1])) + (float)(*i * *i));
      i[7] = v10;
      i[8] = 1.0 / v10;
      *((_WORD *)i + 18) = *((_WORD *)v7 + 30);
      *((_WORD *)i + 19) = 0;
      if ( !in_3 )
        break;
      v9 = *((_DWORD *)v7 + 16);
      if ( v9 < 0 )
      {
        DevMsg(a1: "Mod_LoadTexinfo: texdata < 0 (index==%i/%i)\n", v13, v12);
        i[10] = 0.0;
      }
      else
      {
        *((_DWORD *)i + 10) = GL_LoadMaterial(
                                pName: v5->texdata[v9].name,
                                pTextureGroupName: "World textures",
                                bPrecache: false);
      }
      if ( *((_DWORD *)i + 10) == 0 )
      {
        *((_DWORD *)i + 10) = g_materialEmpty;
LABEL_18:
        g_materialEmpty->IncrementReferenceCount(this: g_materialEmpty);
      }
      v7 += 72;
      if ( ++v13 >= v12 )
        return;
      v5 = s_pMap;
    }
    *((_DWORD *)i + 10) = g_materialEmpty;
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EB4D0
// Name: void Mod_LoadVertNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertNormals()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // ebx
  unsigned int v2; // edi
  char *m_szLumpFilename; // eax
  int v4; // esi
  const char *v5; // eax
  unsigned __int8 *v6; // esi
  worldbrushdata_t *v7; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x1Eu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadVertNormals: funny lump size in %s!\n", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = m_nLumpSize;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "vertnormals");
  v6 = (unsigned __int8 *)Hunk_AllocName(size: v4, name: v5, bClear: true);
  memcpy(dst: v6, src: m_pData, count: lh.m_nLumpSize);
  v7 = s_pMap;
  s_pMap->numvertnormals = v2;
  v7->vertnormals = (Vector *)v6;
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB5C0
// Name: void Mod_LoadVertNormalIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadVertNormalIndices()
{
  int m_nLumpSize; // esi
  unsigned __int8 *m_pData; // ebx
  unsigned int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  worldbrushdata_t *v6; // eax
  unsigned int v7; // esi
  int v8; // edi
  int v9; // edx
  msurface2_t *surfaces2; // ecx
  char *v11; // edx
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int v13; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x1Fu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  v2 = (unsigned int)lh.m_nLumpSize >> 1;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "vertnormalindices");
  v5 = (unsigned __int8 *)Hunk_AllocName(size: m_nLumpSize, name: v4, bClear: true);
  memcpy(dst: v5, src: m_pData, count: lh.m_nLumpSize);
  v6 = s_pMap;
  s_pMap->vertnormalindices = (unsigned __int16 *)v5;
  v6->numvertnormalindices = v2;
  v7 = 0;
  v8 = 0;
  if ( v6->numsurfaces > 0 )
  {
    v9 = 0;
    v13 = 0;
    do
    {
      surfaces2 = v6->surfaces2;
      v11 = (char *)surfaces2 + v9;
      v6->surfacenormals[(v11 - (char *)surfaces2) >> 5].firstvertnormal = v7;
      v7 += (unsigned __int8)v11[3];
      ++v8;
      v9 = v13 + 32;
      v13 += 32;
    }
    while ( v8 < v6->numsurfaces );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB6B0
// Name: void Mod_LoadPrimitives(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimitives()
{
  unsigned int m_nLumpSize; // ecx
  signed int v1; // esi
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  unsigned __int8 *v4; // ebx
  worldbrushdata_t *v5; // eax
  unsigned __int16 *v6; // ecx
  unsigned __int16 *p_firstVert; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  dprimitive_t *in; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x25u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (dprimitive_t *)lh.m_pData;
  if ( lh.m_nLumpSize % 0xAu != 0 )
  {
    Host_Error(error: "Mod_LoadPrimitives: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize / 0xA;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "primitives");
  v4 = (unsigned __int8 *)Hunk_AllocName(size: 12 * v1, name: v3, bClear: true);
  memset(dst: v4, value: 0, count: 12 * v1);
  v5 = s_pMap;
  s_pMap->primitives = (mprimitive_t *)v4;
  v5->numprimitives = v1;
  if ( v1 > 0 )
  {
    v6 = (unsigned __int16 *)(v4 + 8);
    p_firstVert = &in->firstVert;
    do
    {
      *(v6 - 2) = *(p_firstVert - 2);
      *v6 = *p_firstVert;
      *(v6 - 1) = *(p_firstVert - 1);
      *((_DWORD *)v6 - 2) = *((unsigned __int8 *)p_firstVert - 6);
      v6[1] = p_firstVert[1];
      p_firstVert += 5;
      v6 += 6;
      --v1;
    }
    while ( v1 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB7E0
// Name: void Mod_LoadPrimVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimVerts()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // edi
  signed int v2; // ebx
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  worldbrushdata_t *v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  double v9; // st7
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // edi
  int v12; // ebx
  double v13; // st7
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  unsigned int count; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x26u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadPrimVerts: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  count = 28 * v2;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "primverts");
  v5 = (unsigned __int8 *)Hunk_AllocName(size: 28 * v2, name: v4, bClear: true);
  memset(dst: v5, value: 0, count);
  v6 = s_pMap;
  v7 = 0;
  s_pMap->primverts = (mprimvert_t *)v5;
  v6->numprimverts = v2;
  if ( v2 >= 4 )
  {
    v8 = ((unsigned int)(v2 - 4) >> 2) + 1;
    v7 = 4 * v8;
    do
    {
      v9 = *(float *)m_pData;
      m_pData += 48;
      *(float *)v5 = v9;
      v5 += 112;
      --v8;
      *((float *)v5 - 27) = *((float *)m_pData - 11);
      *((float *)v5 - 26) = *((float *)m_pData - 10);
      *((float *)v5 - 21) = *((float *)m_pData - 9);
      *((float *)v5 - 20) = *((float *)m_pData - 8);
      *((float *)v5 - 19) = *((float *)m_pData - 7);
      *((float *)v5 - 14) = *((float *)m_pData - 6);
      *((float *)v5 - 13) = *((float *)m_pData - 5);
      *((float *)v5 - 12) = *((float *)m_pData - 4);
      *((float *)v5 - 7) = *((float *)m_pData - 3);
      *((float *)v5 - 6) = *((float *)m_pData - 2);
      *((float *)v5 - 5) = *((float *)m_pData - 1);
    }
    while ( v8 != 0 );
  }
  if ( v7 < v2 )
  {
    v10 = v5 + 8;
    v11 = m_pData + 8;
    v12 = v2 - v7;
    do
    {
      v13 = *((float *)v11 - 2);
      v11 += 12;
      *((float *)v10 - 2) = v13;
      v10 += 28;
      --v12;
      *((float *)v10 - 8) = *((float *)v11 - 4);
      *((float *)v10 - 7) = *((float *)v11 - 3);
    }
    while ( v12 != 0 );
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EB970
// Name: void Mod_LoadPrimIndices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadPrimIndices()
{
  unsigned int m_nLumpSize; // ebx
  unsigned int v1; // ebx
  char *m_szLumpFilename; // eax
  const char *v3; // eax
  unsigned __int8 *v4; // edi
  worldbrushdata_t *v5; // eax
  unsigned __int8 *v6; // [esp-20h] [ebp-158h]
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  unsigned __int16 *in; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x27u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (unsigned __int16 *)lh.m_pData;
  if ( (lh.m_nLumpSize & 1) != 0 )
  {
    Host_Error(error: "Mod_LoadPrimIndices: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize >> 1;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v3 = va(format: "%s [%s]", m_szLumpFilename, "primindices");
  v4 = (unsigned __int8 *)Hunk_AllocName(size: 2 * v1, name: v3, bClear: true);
  memset(dst: v4, value: 0, count: 2 * v1);
  v5 = s_pMap;
  v6 = (unsigned __int8 *)in;
  s_pMap->primindices = (unsigned __int16 *)v4;
  v5->numprimindices = v1;
  memcpy(dst: v4, src: v6, count: 2 * v1);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBA50
// Name: void Mod_LoadLump(struct model_t __near *,int,char __near *,int,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLump(
        model_t *loadmodel,
        unsigned int iLump,
        char *loadname,
        int elementSize,
        void **ppData,
        int *nElements)
{
  int m_nLumpSize; // ecx
  void *v7; // eax
  unsigned int v8; // edx
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: iLump, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  if ( lh.m_nLumpSize % elementSize != 0 )
  {
    Host_Error(error: "Mod_LoadLump: funny lump size in %s", loadmodel->szPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  *nElements = m_nLumpSize / elementSize;
  v7 = Hunk_AllocName(size: m_nLumpSize, name: loadname, bClear: true);
  v8 = lh.m_nLumpSize;
  *ppData = v7;
  memcpy(dst: (unsigned __int8 *)v7, src: lh.m_pData, count: v8);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBAF0
// Name: void Mod_LoadFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadFaces()
{
  unsigned int v0; // esi
  int lumpLength; // eax
  unsigned int m_nLumpSize; // ecx
  signed int v3; // ebx
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  unsigned __int8 *v6; // edi
  bool v7; // zf
  char *v8; // eax
  const char *v9; // eax
  int v10; // esi
  unsigned __int8 *v11; // edi
  unsigned int v12; // edi
  char *v13; // eax
  const char *v14; // eax
  msurface1_t *v15; // edx
  msurfacelighting_t *v16; // ecx
  worldbrushdata_t *v17; // eax
  char *v18; // eax
  const char *v19; // eax
  worldbrushdata_t *v20; // ecx
  __int16 *p_numedges; // esi
  msurface2_t *v22; // edi
  int v23; // eax
  int v24; // edx
  int v25; // ebx
  __int16 v26; // ax
  int v27; // ebx
  msurfacelighting_t *v28; // eax
  ColorRGBExp32 *lightdata; // ecx
  int v30; // edx
  unsigned __int8 v31; // cl
  int v32; // eax
  msurface1_t *v33; // ebx
  unsigned __int16 *v34; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-148h] BYREF
  msurfacelighting_t *v36; // [esp+134h] [ebp-20h]
  msurface2_t **p_surfaces2; // [esp+138h] [ebp-1Ch]
  worldbrushdata_t *pBrushData; // [esp+13Ch] [ebp-18h]
  unsigned __int16 *p_firstPrimID; // [esp+140h] [ebp-14h]
  msurfacelighting_t *pLighting; // [esp+144h] [ebp-10h]
  dface_t *in; // [esp+148h] [ebp-Ch]
  unsigned __int8 *v42; // [esp+14Ch] [ebp-8h]
  msurface1_t *out1; // [esp+150h] [ebp-4h]
  int savedregs; // [esp+154h] [ebp+0h] BYREF

  v0 = 7;
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
  {
    lumpLength = s_MapLumpFiles[58].header.lumpLength;
    if ( s_MapLumpFiles[58].file == nullptr )
      lumpLength = s_MapHeader.lumps[58].filelen;
    if ( lumpLength > 0 )
      v0 = 58;
  }
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: v0, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  in = (dface_t *)lh.m_pData;
  if ( lh.m_nLumpSize % 0x38u != 0 )
  {
    Host_Error(error: "Mod_LoadFaces: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v3 = m_nLumpSize / 0x38;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "surface1");
  v6 = (unsigned __int8 *)Hunk_AllocName(size: 16 * (v3 + 1) + 16, name: v5, bClear: true);
  memset(dst: v6, value: 0, count: 16 * (v3 + 1) + 16);
  v7 = s_MapLumpFiles[lh.m_nLumpID].file == nullptr;
  out1 = (msurface1_t *)((unsigned int)(v6 + 15) & 0xFFFFFFF0);
  v8 = lh.m_szLumpFilename;
  if ( v7 )
    v8 = s_szMapPathName;
  v9 = va(format: "%s [%s]", v8, "surface2");
  v10 = 32 * (v3 + 1) + 32;
  v11 = (unsigned __int8 *)Hunk_AllocName(size: v10, name: v9, bClear: true);
  memset(dst: v11, value: 0, count: v10);
  v12 = (unsigned int)(v11 + 31) & 0xFFFFFFE0;
  v13 = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    v13 = s_szMapPathName;
  v14 = va(format: "%s [%s]", v13, "surfacelighting");
  v42 = (unsigned __int8 *)Hunk_AllocName(size: v10, name: v14, bClear: true);
  memset(dst: v42, value: 0, count: v10);
  v15 = out1;
  v16 = (msurfacelighting_t *)((unsigned int)(v42 + 31) & 0xFFFFFFE0);
  v36 = v16;
  v17 = s_pMap;
  s_pMap->surfacelighting = v16;
  v17->surfaces1 = v15;
  v17->surfaces2 = (msurface2_t *)v12;
  pLighting = v16;
  v18 = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    v18 = s_szMapPathName;
  v19 = va(format: "%s [%s]", v18, "surfacenormal");
  v42 = (unsigned __int8 *)Hunk_AllocName(size: 4 * v3 + 4, name: v19, bClear: true);
  memset(dst: v42, value: 0, count: 4 * v3 + 4);
  v20 = s_pMap;
  s_pMap->surfacenormals = (msurfacenormal_t *)((unsigned int)(v42 + 1) & 0xFFFFFFFE);
  v20->numsurfaces = v3;
  pBrushData = v20;
  if ( v3 > 0 )
  {
    p_numedges = &in->numedges;
    p_surfaces2 = &v20->surfaces2;
    p_firstPrimID = &out1->prims.firstPrimID;
    in = nullptr;
    out1 = (msurface1_t *)&pLighting->m_nStyles[v12 - (_DWORD)v36];
    v42 = (unsigned __int8 *)v3;
    while ( 1 )
    {
      v22 = (msurface2_t *)((char *)*p_surfaces2 + (_DWORD)in);
      v22->firstvertindex = *((_DWORD *)p_numedges - 1);
      v23 = *p_numedges << 24;
      v22->flags = v23;
      v24 = (unsigned __int16)*(p_numedges - 4);
      if ( *((_BYTE *)p_numedges - 5) != 0 )
        v22->flags = v23 | 2;
      if ( *((_BYTE *)p_numedges - 6) != 0 )
        v22->flags |= 0x40u;
      out1[-2].prims = (msurface1_t::<unnamed_type_prims>)&v20->planes[v24];
      v25 = p_numedges[1];
      if ( v25 < 0 || v25 >= v20->numtexinfo )
      {
        Host_Error(error: "Mod_LoadFaces: bad texinfo number");
        v20 = s_pMap;
      }
      v26 = (2 * v25) | *((_WORD *)v22 + 11) & 1;
      *((_WORD *)v22 + 11) = v26;
      *((_WORD *)v22 + 11) = v26 & 0xFFFE | (p_numedges[20] >= 0);
      v27 = (int)&v20->texinfo[v25];
      if ( *(_DWORD *)(v27 + 76) == 0 )
      {
        *(_DWORD *)(v27 + 76) = g_materialEmpty;
        g_materialEmpty->IncrementReferenceCount(this: g_materialEmpty);
        v20 = s_pMap;
      }
      v28 = pLighting;
      lightdata = v20->lightdata;
      pLighting->m_LightmapExtents[0] = p_numedges[14];
      v28->m_LightmapExtents[1] = p_numedges[16];
      v28->m_LightmapMins[0] = p_numedges[10];
      v28->m_LightmapMins[1] = p_numedges[12];
      v30 = *((_DWORD *)p_numedges + 3);
      if ( v30 == -1 || lightdata == nullptr )
      {
        v28->m_pSamples = nullptr;
        *(_DWORD *)v28->m_nStyles = -1;
      }
      else
      {
        v28->m_pSamples = (ColorRGBExp32 *)((char *)lightdata + v30);
        v28->m_nStyles[0] = *((_BYTE *)p_numedges + 8);
        v28->m_nStyles[1] = *((_BYTE *)p_numedges + 9);
        v28->m_nStyles[2] = *((_BYTE *)p_numedges + 10);
        v28->m_nStyles[3] = *((_BYTE *)p_numedges + 11);
      }
      v31 = v28->m_nStyles[0];
      if ( v31 != 0 && v31 != 0xFF || v28->m_nStyles[1] != 0xFF )
        v22->flags |= 0x400u;
      if ( (*(_WORD *)(v27 + 72) & 0x400) != 0 )
        v22->flags |= 1u;
      if ( (*(_WORD *)(v27 + 72) & 0x1000) != 0 )
        v22->flags |= 0x2000u;
      if ( (*(_BYTE *)(v27 + 72) & 8) != 0 )
        v22->flags |= 0x10000u;
      if ( (*(_BYTE *)(v27 + 72) & 4) != 0 )
        v22->flags |= 4u;
      if ( (*(_WORD *)(v27 + 72) & 0x2000) != 0 )
        v22->flags |= 0x100000u;
      v32 = p_numedges[2];
      v33 = out1;
      out1->textureMins[0] = 0;
      if ( v32 == -1 )
      {
        v34 = p_firstPrimID;
        *(p_firstPrimID - 1) = p_numedges[20] & 0x7FFF;
        *v34 = p_numedges[21];
        if ( (p_numedges[20] & 0x7FFF) != 0 )
        {
          v22->flags |= 0x8000u;
          if ( pBrushData->primitives[(unsigned __int16)p_numedges[21]].vertCount != 0 )
            v22->flags |= 0x80u;
        }
      }
      else
      {
        v22->flags |= 0x800u;
      }
      v33[-1].textureMins[1] = -1;
      v33[-1].textureExtents[0] = -1;
      CalcSurfaceExtents(surfID: v22);
      CheckSurfaceLighting(pBrushData, a2: (int)&savedregs, a3: v22);
      p_firstPrimID += 8;
      in = (dface_t *)((char *)in + 32);
      ++pLighting;
      p_numedges += 28;
      v7 = v42-- == (unsigned __int8 *)1;
      out1 = v33 + 2;
      if ( v7 )
        break;
      v20 = s_pMap;
    }
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EBFC0
// Name: void Mod_LoadNodes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadNodes()
{
  unsigned int m_nLumpSize; // eax
  unsigned __int8 *m_pData; // ebx
  int v2; // edi
  char *m_szLumpFilename; // eax
  const char *v4; // eax
  mnode_t *v5; // eax
  worldbrushdata_t *v6; // esi
  __int16 *v7; // ecx
  float *p_y; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  int v12; // edx
  float v13; // xmm7_4
  int v14; // edx
  int v15; // edx
  mnode_t *nodes; // edx
  bool v17; // sf
  mnode_t *v18; // edx
  mnode_t *v19; // esi
  float *p_z; // ecx
  int j; // ebx
  const Vector *v22; // edi
  int *v23; // edx
  int v24; // edx
  int *v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  mnode_t *v31; // [esp-8h] [ebp-140h]
  mnode_t *v32; // [esp-8h] [ebp-140h]
  mnode_t *v33; // [esp-4h] [ebp-13Ch]
  mnode_t *v34; // [esp-4h] [ebp-13Ch]
  CMapLoadHelper lh; // [esp+Ch] [ebp-12Ch] BYREF
  int i; // [esp+134h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 5u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 0x1F) != 0 )
  {
    Host_Error(error: "Mod_LoadNodes: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 5;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v4 = va(format: "%s [%s]", m_szLumpFilename, "nodes");
  v5 = (mnode_t *)Hunk_AllocName(size: v2 << 6, name: v4, bClear: true);
  v6 = s_pMap;
  s_pMap->nodes = v5;
  v6->numnodes = v2;
  if ( v2 > 0 )
  {
    v7 = (__int16 *)(m_pData + 18);
    p_y = &v5->m_vecCenter.y;
    for ( i = v2; i != 0; --i )
    {
      v9 = (float)*v7;
      v10 = (float)v7[1];
      v11 = (float)*(v7 - 1);
      v12 = v7[2];
      v13 = v9 + (float)*(v7 - 3);
      *p_y = v10 + (float)*(v7 - 2);
      p_y[1] = (float)v12 + v11;
      *(p_y - 1) = v13 * 0.5;
      *p_y = *p_y * 0.5;
      p_y[1] = p_y[1] * 0.5;
      p_y[3] = v9 - *(p_y - 1);
      p_y[4] = v10 - *p_y;
      p_y[5] = (float)v12 - p_y[1];
      *((_DWORD *)p_y + 7) = &v6->planes[*(_DWORD *)(v7 - 9)];
      *((_WORD *)p_y + 20) = v7[3];
      *((_WORD *)p_y + 21) = v7[4];
      *((_WORD *)p_y - 4) = v7[5];
      *(p_y - 5) = NAN;
      v14 = *(_DWORD *)(v7 - 7);
      if ( v14 < 0 )
        *((_DWORD *)p_y + 8) = &v6->leafs[-v14 - 1];
      else
        *((_DWORD *)p_y + 8) = &v6->nodes[v14];
      v15 = *(_DWORD *)(v7 - 5);
      if ( v15 < 0 )
        *((_DWORD *)p_y + 9) = &v6->leafs[-v15 - 1];
      else
        *((_DWORD *)p_y + 9) = &v6->nodes[v15];
      v7 += 16;
      p_y += 16;
    }
  }
  nodes = v6->nodes;
  v17 = nodes->contents < 0;
  nodes->parent = nullptr;
  if ( v17 )
  {
    Mod_SetParent(node: nodes->children[0], parent: nodes);
    Mod_SetParent(node: v18->children[1], parent: v18);
  }
  v19 = v6->nodes;
  if ( v2 > 0 )
  {
    p_z = &v19->m_vecHalfDiagonal.z;
    for ( j = v2; j != 0; --j )
    {
      if ( v19->contents == -1 )
      {
        v22 = (const Vector *)(p_z - 2);
        if ( *(p_z - 2) > 50.0 || *(p_z - 1) > 50.0 || *p_z > 50.0 )
        {
          v27 = *((_DWORD *)p_z + 3);
          if ( *(int *)v27 < 0
            && (float)(v22->x - *(float *)(v27 + 32)) < 5.0
            && (float)(*(p_z - 1) - *(float *)(v27 + 36)) < 5.0
            && (float)(*p_z - *(float *)(v27 + 40)) < 5.0 )
          {
            v31 = *(mnode_t **)(v27 + 52);
            *(_DWORD *)v27 = -3;
            CheckSmallVolumeDifferences(pNode: v31, parentSize: (const Vector *)(p_z - 2));
            CheckSmallVolumeDifferences(pNode: *(mnode_t **)(v28 + 56), parentSize: v22);
          }
          v29 = *((_DWORD *)p_z + 4);
          if ( *(int *)v29 < 0
            && (float)(v22->x - *(float *)(v29 + 32)) < 5.0
            && (float)(*(p_z - 1) - *(float *)(v29 + 36)) < 5.0
            && (float)(*p_z - *(float *)(v29 + 40)) < 5.0 )
          {
            v32 = *(mnode_t **)(v29 + 52);
            *(_DWORD *)v29 = -3;
            CheckSmallVolumeDifferences(pNode: v32, parentSize: v22);
            CheckSmallVolumeDifferences(pNode: *(mnode_t **)(v30 + 56), parentSize: v22);
          }
        }
        else
        {
          v23 = *((int **)p_z + 3);
          if ( *v23 < 0 )
          {
            v33 = (mnode_t *)v23[13];
            *v23 = -2;
            MarkSmallNode(node: v33);
            MarkSmallNode(node: *(mnode_t **)(v24 + 56));
          }
          v25 = *((int **)p_z + 4);
          if ( *v25 < 0 )
          {
            v34 = (mnode_t *)v25[13];
            *v25 = -2;
            MarkSmallNode(node: v34);
            MarkSmallNode(node: *(mnode_t **)(v26 + 56));
          }
        }
      }
      ++v19;
      p_z += 16;
    }
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC320
// Name: void Mod_LoadLeafs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafs()
{
  int lumpLength; // eax
  unsigned __int8 *m_pRawData; // eax
  worldbrushdata_t *v2; // edx
  int v3; // esi
  worldbrushdata_t *v4; // ecx
  int v5; // ecx
  unsigned __int16 *p_dispListStart; // eax
  CMapLoadHelper ambientLightingLump; // [esp+0h] [ebp-5D0h] BYREF
  CMapLoadHelper mlh; // [esp+128h] [ebp-4A8h] BYREF
  CMapLoadHelper ambientLightingTable; // [esp+250h] [ebp-380h] BYREF
  CMapLoadHelper mlhTable; // [esp+378h] [ebp-258h] BYREF
  CMapLoadHelper lh; // [esp+4A0h] [ebp-130h] BYREF
  int *p_numleafs; // [esp+5C8h] [ebp-8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xAu, bUncompress: true);
  if ( lh.m_nLumpVersion != 0 )
  {
    if ( lh.m_nLumpVersion == 1 )
    {
      if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
        goto LABEL_11;
      lumpLength = s_MapLumpFiles[55].header.lumpLength;
      if ( s_MapLumpFiles[55].file == nullptr )
        lumpLength = s_MapHeader.lumps[55].filelen;
      if ( lumpLength > 0 )
      {
        CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0x37u, bUncompress: true);
        CMapLoadHelper::CMapLoadHelper(this: &mlhTable, lumpToLoad: 0x33u, bUncompress: true);
        Mod_LoadLeafs_Version_1(&lh, ambientLightingLump: (CompressedLightCube *)&mlh, ambientLightingTable: &mlhTable);
        if ( mlhTable.m_pRawData != nullptr )
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: mlhTable.m_pRawData);
        m_pRawData = mlh.m_pRawData;
      }
      else
      {
LABEL_11:
        CMapLoadHelper::CMapLoadHelper(this: &ambientLightingLump, lumpToLoad: 0x38u, bUncompress: true);
        CMapLoadHelper::CMapLoadHelper(this: &ambientLightingTable, lumpToLoad: 0x34u, bUncompress: true);
        Mod_LoadLeafs_Version_1(&lh, (CompressedLightCube *)&ambientLightingLump, &ambientLightingTable);
        if ( ambientLightingTable.m_pRawData != nullptr )
          g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: ambientLightingTable.m_pRawData);
        m_pRawData = ambientLightingLump.m_pRawData;
      }
      if ( m_pRawData != nullptr )
        g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
    }
    else
    {
      _Error(a1: "Unknown LUMP_LEAFS version\n");
    }
  }
  else
  {
    Mod_LoadLeafs_Version_0((int)&lh);
  }
  v2 = s_pMap;
  v3 = 0;
  v4 = s_pMap;
  p_numleafs = &s_pMap->numleafs;
  if ( s_pMap->numleafs > 0 )
  {
    v5 = 0;
    p_dispListStart = &g_BSPData.map_leafs.m_pArray->dispListStart;
    do
    {
      v2->leafs[v5].dispCount = p_dispListStart[1];
      v2->leafs[v5].dispListStart = *p_dispListStart;
      ++v3;
      p_dispListStart += 8;
      ++v5;
    }
    while ( v3 < *p_numleafs );
    v4 = v2;
  }
  v4->m_pDispInfoReferences = g_BSPData.map_dispList.m_pArray;
  v4->m_nDispInfoReferences = g_BSPData.numdisplist;
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC4F0
// Name: void Mod_LoadLeafWaterData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafWaterData()
{
  unsigned int m_nLumpSize; // ecx
  unsigned __int8 *m_pData; // edi
  unsigned int v2; // kr00_4
  signed int v3; // esi
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  mleafwaterdata_t *v6; // eax
  worldbrushdata_t *v7; // ecx
  __int16 *p_surfaceTexInfoID; // edx
  float *v9; // ecx
  int v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  __int16 *p_leafWaterDataID; // edx
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x24u, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( lh.m_nLumpSize % 0xCu != 0 )
  {
    Host_Error(error: "Mod_LoadLeafs: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize;
  v3 = m_nLumpSize / 0xC;
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "leafwaterdata");
  v6 = (mleafwaterdata_t *)Hunk_AllocName(size: 12 * v3, name: v5, bClear: true);
  v7 = s_pMap;
  s_pMap->leafwaterdata = v6;
  v7->numleafwaterdata = v3;
  if ( v3 > 0 )
  {
    p_surfaceTexInfoID = &v6->surfaceTexInfoID;
    v9 = (float *)(m_pData + 8);
    v10 = (char *)v6 - (char *)m_pData - 8;
    v11 = v2 / 0xC;
    do
    {
      p_surfaceTexInfoID += 6;
      *((float *)p_surfaceTexInfoID - 4) = *(v9 - 1);
      *(p_surfaceTexInfoID - 6) = *(_WORD *)v9;
      *(float *)((char *)v9 + v10) = *(v9 - 2);
      *(p_surfaceTexInfoID - 5) = -1;
      v9 += 3;
      --v11;
    }
    while ( v11 != 0 );
    v7 = s_pMap;
  }
  if ( v3 == 1 )
  {
    v12 = 0;
    if ( v7->numleafs > 0 )
    {
      p_leafWaterDataID = &v7->leafs->leafWaterDataID;
      while ( *p_leafWaterDataID < 0 )
      {
        ++v12;
        p_leafWaterDataID += 32;
        if ( v12 >= v7->numleafs )
          goto LABEL_16;
      }
      v7->leafwaterdata->firstLeafIndex = v12;
    }
  }
LABEL_16:
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC640
// Name: void Mod_LoadLeafMinDistToWater(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadLeafMinDistToWater()
{
  unsigned int m_nLumpSize; // edx
  int v1; // eax
  unsigned __int8 *m_pData; // ebx
  unsigned int v3; // edx
  char *m_szLumpFilename; // eax
  int v5; // esi
  const char *v6; // eax
  unsigned __int8 *v7; // edi
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x2Eu, bUncompress: true);
  m_nLumpSize = lh.m_nLumpSize;
  v1 = 0;
  if ( (unsigned int)lh.m_nLumpSize >> 1 == 0 )
    goto LABEL_5;
  m_pData = lh.m_pData;
  while ( *(_WORD *)&lh.m_pData[2 * v1] == 0xFFFF )
  {
    if ( ++v1 >= (signed int)((unsigned int)lh.m_nLumpSize >> 1) )
      goto LABEL_5;
  }
  if ( lh.m_nLumpSize != 0 && g_pMaterialSystemHardwareConfig != nullptr )
  {
    if ( (lh.m_nLumpSize & 1) != 0 )
    {
      Host_Error(error: "Mod_LoadLeafMinDistToWater: funny lump size in %s", s_szMapPathName);
      m_nLumpSize = lh.m_nLumpSize;
    }
    v3 = m_nLumpSize >> 1;
    m_szLumpFilename = lh.m_szLumpFilename;
    if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
      m_szLumpFilename = s_szMapPathName;
    v5 = 2 * v3;
    v6 = va(format: "%s [%s]", m_szLumpFilename, "leafmindisttowater");
    v7 = (unsigned __int8 *)Hunk_AllocName(size: v5, name: v6, bClear: true);
    memcpy(dst: v7, src: m_pData, count: v5);
    s_pMap->m_LeafMinDistToWater = (unsigned __int16 *)v7;
  }
  else
  {
LABEL_5:
    s_pMap->m_LeafMinDistToWater = nullptr;
  }
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC740
// Name: void Mod_LoadMarksurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadMarksurfaces()
{
  unsigned int m_nLumpSize; // eax
  int v1; // edi
  msurface2_t **v2; // eax
  worldbrushdata_t *v3; // ecx
  int v4; // ebx
  int v5; // esi
  msurface2_t *v6; // esi
  char *m_szLumpFilename; // eax
  const char *v8; // eax
  worldbrushdata_t *v9; // eax
  mleaf_t *leafs; // ecx
  int v11; // esi
  int v12; // edi
  unsigned __int16 *v13; // ecx
  msurface2_t *v14; // edx
  int v15; // edx
  msurface2_t **v16; // [esp-10h] [ebp-160h]
  CMapLoadHelper lh; // [esp+0h] [ebp-150h] BYREF
  msurface2_t ***p_marksurfaces; // [esp+128h] [ebp-28h]
  int *p_nummarksurfaces; // [esp+12Ch] [ebp-24h]
  int firstMark; // [esp+130h] [ebp-20h]
  worldbrushdata_t *pBrushData; // [esp+134h] [ebp-1Ch]
  msurface2_t **tempDiskData; // [esp+138h] [ebp-18h]
  int numMark; // [esp+13Ch] [ebp-14h]
  int numMarkNode; // [esp+140h] [ebp-10h]
  msurface2_t **surfList; // [esp+144h] [ebp-Ch]
  int realCount; // [esp+148h] [ebp-8h]
  int i; // [esp+14Ch] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x10u, bUncompress: true);
  surfList = (msurface2_t **)lh.m_pData;
  m_nLumpSize = lh.m_nLumpSize;
  if ( (lh.m_nLumpSize & 1) != 0 )
  {
    Host_Error(error: "Mod_LoadMarksurfaces: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v1 = m_nLumpSize >> 1;
  v2 = (msurface2_t **)MemAlloc_Alloc(nSize: (unsigned __int64)(m_nLumpSize >> 1) >> 30 != 0 ? -1 : 4 * (m_nLumpSize >> 1));
  v3 = s_pMap;
  v4 = 0;
  p_marksurfaces = &s_pMap->marksurfaces;
  s_pMap->marksurfaces = v2;
  tempDiskData = v2;
  pBrushData = v3;
  p_nummarksurfaces = &v3->nummarksurfaces;
  v3->nummarksurfaces = v1;
  realCount = 0;
  if ( v1 > 0 )
  {
    i = (int)&v3->surfaces2;
    do
    {
      v5 = *((unsigned __int16 *)surfList + v4);
      if ( v5 >= v3->numsurfaces )
      {
        Host_Error(error: "Mod_LoadMarksurfaces: bad surface number");
        v3 = s_pMap;
      }
      v6 = (msurface2_t *)(*(_DWORD *)i + 32 * v5);
      tempDiskData[v4] = v6;
      if ( (v6->flags & 0x800) == 0 && (v6->flags & 0x10) == 0 )
        ++realCount;
      ++v4;
    }
    while ( v4 < v1 );
  }
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v8 = va(format: "%s [%s]", m_szLumpFilename, "surfacehandle");
  surfList = (msurface2_t **)Hunk_AllocName(size: 4 * realCount, name: v8, bClear: true);
  v9 = pBrushData;
  leafs = pBrushData->leafs;
  v11 = 0;
  v12 = 0;
  i = 0;
  if ( pBrushData->numleafs > 0 )
  {
    v13 = &leafs->nummarksurfaces;
    do
    {
      firstMark = v12;
      numMark = 0;
      numMarkNode = 0;
      if ( *v13 != 0 )
      {
        do
        {
          v14 = *(&tempDiskData[v11] + *(v13 - 1));
          if ( (v14->flags & 0x800) == 0 && (v14->flags & 0x10) == 0 )
          {
            surfList[v12] = v14;
            ++numMark;
            ++v12;
            if ( (v14->flags & 2) != 0 )
              ++numMarkNode;
          }
          ++v11;
        }
        while ( v11 < *v13 );
        v9 = pBrushData;
        v11 = 0;
      }
      *v13 = numMark;
      *(v13 - 1) = firstMark;
      v13[1] = numMarkNode;
      v13 += 32;
      ++i;
    }
    while ( i < v9->numleafs );
  }
  v15 = realCount;
  *p_marksurfaces = surfList;
  v16 = tempDiskData;
  *p_nummarksurfaces = v15;
  free(pMem: v16);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EC940
// Name: void Mod_LoadSurfedges(struct medge_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadSurfedges(medge_t *pedges)
{
  unsigned int m_nLumpSize; // eax
  int v2; // eax
  int v3; // esi
  char *m_szLumpFilename; // eax
  const char *v5; // eax
  unsigned __int16 *v6; // eax
  worldbrushdata_t *v7; // ecx
  int i; // ecx
  int v9; // edx
  int v10; // edi
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  int *in; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xDu, bUncompress: true);
  in = (int *)lh.m_pData;
  m_nLumpSize = lh.m_nLumpSize;
  if ( (lh.m_nLumpSize & 3) != 0 )
  {
    Host_Error(error: "Mod_LoadSurfedges: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v2 = m_nLumpSize >> 2;
  v3 = v2;
  if ( v2 == 0 || v2 >= 512000 )
    Host_Error(error: "Mod_LoadSurfedges: bad surfedges count in %s: %i", s_szMapPathName, v2);
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  v5 = va(format: "%s [%s]", m_szLumpFilename, "surfedges");
  v6 = (unsigned __int16 *)Hunk_AllocName(size: 2 * v3, name: v5, bClear: true);
  v7 = s_pMap;
  s_pMap->vertindices = v6;
  v7->numvertindices = v3;
  for ( i = 0; i < v3; ++i )
  {
    v9 = in[i];
    v10 = 0;
    if ( v9 < 0 )
    {
      v9 = -v9;
      v10 = 1;
    }
    v6[i] = pedges[v9].v[v10];
  }
  free(pMem: pedges);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100ECA60
// Name: int Mod_GameLumpVersion(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GameLumpVersion(int lumpId)
{
  int v1; // eax
  dgamelump_t *i; // ecx

  v1 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 < 0 )
    return 0;
  for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v1]; i->id != lumpId; --i )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return g_GameLumpDict.m_Memory.m_pMemory[v1].version;
}

//------------------------------------------------------------------------------
// Address: 0x100ECAA0
// Name: int Mod_GameLumpSize(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GameLumpSize(int lumpId)
{
  int v1; // eax
  dgamelump_t *i; // ecx

  v1 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 < 0 )
    return 0;
  for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v1]; i->id != lumpId; --i )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return g_GameLumpDict.m_Memory.m_pMemory[v1].filelen;
}

//------------------------------------------------------------------------------
// Address: 0x100ECAE0
// Name: bool Mod_LoadGameLump(int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __usercall Mod_LoadGameLump@<al>(int a1@<ebx>, int a2@<edi>, int lumpId, void *pOutBuffer, int size)
{
  int v5; // eax
  dgamelump_t *i; // ecx
  int v8; // eax
  int v9; // ebx
  int filelen; // edi
  char v11; // al
  int v12; // ebx
  void *v13; // esi
  bool v14; // bl
  void *v15; // ebx
  int v16; // eax
  void (__thiscall *Close)(IBaseFileSystem *, void *); // edx
  char szNameOnDisk[263]; // [esp+4h] [ebp-108h] BYREF
  bool bOK; // [esp+10Bh] [ebp-1h]

  v5 = g_GameLumpDict.m_Size - 1;
  if ( g_GameLumpDict.m_Size - 1 >= 0 )
  {
    for ( i = &g_GameLumpDict.m_Memory.m_pMemory[v5]; i->id != lumpId; --i )
    {
      if ( --v5 < 0 )
        return 0;
    }
    if ( v5 >= 0 )
    {
      v8 = v5;
      v9 = v8 * 16;
      filelen = g_GameLumpDict.m_Memory.m_pMemory[v8].filelen;
      if ( size >= filelen )
      {
        v11 = g_GameLumpDict.m_Memory.m_pMemory[v8].flags & 1;
        bOK = *((_BYTE *)&g_GameLumpDict.m_Memory.m_pMemory->flags + v9) & 1;
        if ( bOK )
          filelen = *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory[1].fileofs + v9)
                  - *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9);
        if ( s_MapBuffer.m_Memory.m_pMemory != nullptr )
        {
          v12 = *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9);
          if ( v12 + filelen <= s_MapBuffer.m_nMaxPut && v11 == 0 )
          {
            _V_memcpy(dest: pOutBuffer, src: &s_MapBuffer.m_Memory.m_pMemory[v12], count: filelen);
            return 1;
          }
        }
        else
        {
          V_strncpy(pDest: szNameOnDisk, pSrc: g_GameLumpFilename, maxLen: 260);
          v13 = g_pFileSystem->OpenEx(this: g_pFileSystem, a2: szNameOnDisk, a3: "rb", a4: 0, a5: 0, a6: 0);
          if ( v13 != nullptr )
          {
            ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD, _DWORD, int, int))g_pFileSystem->Seek)(
              a1: &g_pFileSystem->IBaseFileSystem,
              a2: v13,
              a3: *(int *)((char *)&g_GameLumpDict.m_Memory.m_pMemory->fileofs + v9),
              a4: 0,
              a5: a2,
              a6: a1);
            if ( !bOK )
            {
              v14 = ((int (__thiscall *)(IBaseFileSystem *, void *))g_pFileSystem->Read)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: pOutBuffer) > 0;
              g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
              return v14;
            }
            v15 = MemAlloc_Alloc(nSize: filelen);
            v16 = ((int (__thiscall *)(IBaseFileSystem *, void *))g_pFileSystem->Read)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: v15);
            Close = g_pFileSystem->Close;
            bOK = v16 > 0;
            Close(this: &g_pFileSystem->IBaseFileSystem, a2: v13);
            if ( !bOK )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
          }
        }
      }
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ECC80
// Name: void Mod_TouchAllData(struct model_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_TouchAllData(model_t *pModel, int nServerCount)
{
  int v2; // ecx
  IMDLCache *v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // ebx
  int v7; // edi
  _DWORD *v8; // eax
  int v9; // edx
  double t1; // [esp+8h] [ebp-Ch]
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-4h]

  t1 = _Plat_FloatTime(a1: v2);
  v3 = g_pMDLCache;
  cacheCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v4 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetVirtualModel)(a1: pModel->studio);
  g_flAccumulatedModelLoadTimeVirtualModel = _Plat_FloatTime(a1: v5) - t1 + g_flAccumulatedModelLoadTimeVirtualModel;
  if ( v4 != 0 )
  {
    v6 = 1;
    if ( nServerCount >= 1 && *(int *)(v4 + 100) > 1 )
    {
      v7 = 144;
      do
      {
        v8 = g_pMDLCache->GetUserData(this: g_pMDLCache, a2: *(unsigned __int16 *)(v7 + *(_DWORD *)(v4 + 88)));
        if ( v8 != nullptr )
        {
          v9 = v8[66] | pModel->nLoadFlags & 0x7E;
          v8[67] = nServerCount;
          v8[66] = v9 & 0xFFFEFFFE | 1;
        }
        ++v6;
        v7 += 144;
      }
      while ( v6 < *(_DWORD *)(v4 + 100) );
      v3 = cacheCriticalSection;
    }
  }
  if ( mod_forcetouchdata.m_pParent != nullptr && mod_forcetouchdata.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__stdcall *)(_DWORD))g_pMDLCache->TouchAllData)(a1: pModel->studio);
    v3->EndLock(this: v3);
  }
  else
  {
    v3->EndLock(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECD90
// Name: private: void CMDLCacheNotify::ComputeModelFlags(struct model_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::ComputeModelFlags(CMDLCacheNotify *this, model_t *pModel, int handle)
{
  studiohdr_t *v3; // eax
  int v5; // ebx
  IMaterial *v6; // edi
  IMaterial *materials[128]; // [esp+Ch] [ebp-200h] BYREF
  int materialCount; // [esp+214h] [ebp+8h]
  bool handle_3; // [esp+21Bh] [ebp+Fh]

  v3 = g_pMDLCache->GetStudioHdr(this: g_pMDLCache, a2: handle);
  pModel->flags &= 0xFFFFD8E0;
  handle_3 = (v3->flags & 4) != 0;
  if ( (v3->flags & 8) != 0 )
    pModel->flags |= 8u;
  if ( (v3->flags & 0x20) != 0 )
    pModel->flags |= 0x100u;
  if ( (v3->flags & 0x10) != 0 )
    pModel->flags |= 0x2000u;
  if ( SLOBYTE(v3->flags) < 0 )
    pModel->flags |= 0x200u;
  if ( (v3->flags & 2) != 0 )
    pModel->flags |= 0x400u;
  if ( (v3->flags & 0x10000) != 0 )
    pModel->flags |= 0x800u;
  if ( (v3->flags & 0x20000) != 0 )
    pModel->flags |= 0x1000u;
  v5 = 0;
  materialCount = Mod_GetModelMaterials(pModel, count: 128, ppMaterials: materials);
  if ( materialCount > 0 )
  {
    do
    {
      v6 = materials[v5];
      if ( v6 != nullptr )
      {
        if ( v6->IsVertexLit(this: materials[v5]) )
          pModel->flags |= 4u;
        if ( !handle_3 && v6->IsTranslucent(this: v6) )
          pModel->flags |= 2u;
        if ( v6->HasProxy(this: v6) )
          pModel->flags |= 1u;
        if ( v6->NeedsPowerOfTwoFrameBufferTexture(this: v6, a2: false) )
          pModel->flags |= 0x10u;
      }
      ++v5;
    }
    while ( v5 < materialCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECEF0
// Name: public: virtual void CMDLCacheNotify::OnDataLoaded(enum MDLCacheDataType_t,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLCacheNotify::OnDataLoaded(CMDLCacheNotify *this, MDLCacheDataType_t type, int handle)
{
  model_t *v4; // esi
  vcollide_t *v5; // eax
  Vector *p_maxs; // edi
  Vector *p_mins; // esi
  Vector *v8; // [esp-4h] [ebp-28h]
  Vector maxs; // [esp+Ch] [ebp-18h] BYREF
  Vector mins; // [esp+18h] [ebp-Ch] BYREF

  v4 = (model_t *)g_pMDLCache->GetUserData(this: g_pMDLCache, a2: handle);
  if ( v4 != nullptr )
  {
    if ( type != MDLCACHE_STUDIOHDR )
    {
      if ( type == MDLCACHE_STUDIOHWDATA )
      {
        CMDLCacheNotify::ComputeModelFlags(this, pModel: v4, handle);
      }
      else if ( type == MDLCACHE_VCOLLIDE )
      {
        CMDLCacheNotify::SetBoundsFromStudioHdr(this, pModel: v4, handle);
        v5 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: handle);
        if ( v5 != nullptr )
        {
          physcollision->CollideGetAABB(
            this: physcollision,
            a2: &mins,
            a3: &maxs,
            a4: *v5->solids,
            a5: &vec3_origin,
            a6: &vec3_angle);
          p_maxs = &v4->maxs;
          v8 = &v4->maxs;
          p_mins = &v4->mins;
          AddPointToBounds(v: &mins, mins: p_mins, maxs: v8);
          AddPointToBounds(v: &maxs, mins: p_mins, maxs: p_maxs);
        }
      }
    }
    else
    {
      CMDLCacheNotify::SetBoundsFromStudioHdr(this, pModel: v4, handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ECFC0
// Name: void InitStudioModelState(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitStudioModelState(model_t *pModel)
{
  int studio; // edi
  model_t *v2; // eax
  int v3; // edi
  model_t *v4; // eax
  int v5; // edi
  model_t *v6; // eax
  model_t *v7; // esi
  vcollide_t *v8; // eax
  Vector *p_maxs; // edi
  Vector *p_mins; // esi
  Vector *v11; // [esp-4h] [ebp-24h]
  Vector v12; // [esp+8h] [ebp-18h] BYREF
  Vector v; // [esp+14h] [ebp-Ch] BYREF

  if ( ((unsigned __int8 (__stdcall *)(_DWORD, _DWORD))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 0) != 0 )
  {
    studio = pModel->studio;
    v2 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: studio);
    if ( v2 != nullptr )
      CMDLCacheNotify::SetBoundsFromStudioHdr(this: &s_MDLCacheNotify, pModel: v2, handle: studio);
  }
  if ( ((unsigned __int8 (__stdcall *)(_DWORD, int))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 1) != 0 )
  {
    v3 = pModel->studio;
    v4 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: v3);
    if ( v4 != nullptr )
      CMDLCacheNotify::ComputeModelFlags(this: &s_MDLCacheNotify, pModel: v4, handle: v3);
  }
  if ( ((unsigned __int8 (__stdcall *)(_DWORD, int))g_pMDLCache->IsDataLoaded)(a1: pModel->studio, a2: 2) != 0 )
  {
    v5 = pModel->studio;
    v6 = (model_t *)((int (__stdcall *)(int))g_pMDLCache->GetUserData)(a1: v5);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CMDLCacheNotify::SetBoundsFromStudioHdr(this: &s_MDLCacheNotify, pModel: v6, handle: v5);
      v8 = g_pMDLCache->GetVCollide(this: g_pMDLCache, a2: v5);
      if ( v8 != nullptr )
      {
        physcollision->CollideGetAABB(
          this: physcollision,
          a2: &v,
          a3: &v12,
          a4: *v8->solids,
          a5: &vec3_origin,
          a6: &vec3_angle);
        p_maxs = &v7->maxs;
        v11 = &v7->maxs;
        p_mins = &v7->mins;
        AddPointToBounds(&v, mins: p_mins, maxs: v11);
        AddPointToBounds(v: &v12, mins: p_mins, maxs: p_maxs);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED120
// Name: private: virtual void CResourcePreloadModel::OnEndMapLoading(bool)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CResourcePreloadModel::OnEndMapLoading(CResourcePreloadModel *this, bool bAbort)
{
  CMapLoadHelper::Shutdown();
}

//------------------------------------------------------------------------------
// Address: 0x100ED130
// Name: public: virtual int CModelLoader::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetCount(CModelLoader *this)
{
  return this->m_Models.m_Tree.m_NumElements;
}

//------------------------------------------------------------------------------
// Address: 0x100ED140
// Name: public: virtual bool CBrushBSPIterator::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushBSPIterator::EnumerateLeaf(CBrushBSPIterator *this, int leaf, int __formal)
{
  CBrushBSPIterator::MarkModelSurfaces(
    this,
    flags: this->m_pShared->leafs[leaf].leafWaterDataID != -1 ? 0x20000 : 0x40000);
  ++this->m_count;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ED180
// Name: private: void CModelLoader::Map_LoadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_LoadModel(CModelLoader *this, model_t *mod)
{
  IEngineVGuiInternal *v3; // eax
  int v4; // ecx
  int v5; // ecx
  double v6; // st7
  double startTime; // [esp+1Ch] [ebp-8h]

  v3 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, int))v3->UpdateProgressBar)(a1: v3, a2: 3);
  _COM_TimestampedLog(a1: "Map_LoadModel: Start");
  startTime = _Plat_FloatTime(a1: v4);
  this->m_pWorldModel = mod;
  mod->nLoadFlags |= 1u;
  mod->type = mod_brush;
  mod->sprite.numframes = (int)&this->m_worldBrushData;
  mod->brush.renderHandle = 0;
  CMapLoadHelper::Init(
    a1: (int)_COM_TimestampedLog,
    a2: (int)this,
    p_lumpHeader: (lumpfileheader_t *)mod,
    pMapModel: mod,
    pPathName: mod->szPathName);
  CModelLoader::Map_LoadModelGuts(this, mod);
  CMapLoadHelper::Shutdown();
  v6 = _Plat_FloatTime(a1: v5);
  _COM_TimestampedLog(a1: "Map_LoadModel: Finish - loading took %.4f seconds", v6 - startTime);
}

//------------------------------------------------------------------------------
// Address: 0x100ED220
// Name: private: void CModelLoader::Studio_LoadModel(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::Studio_LoadModel(
        CModelLoader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        model_t *pModel,
        int bTouchAllData)
{
  int nLoadFlags; // eax
  bool v8; // bl
  int v9; // eax
  int v10; // ecx
  studiohdr_t *v11; // esi
  int v12; // ecx
  double v13; // st7
  int v14; // ecx
  int v15; // ebx
  int v16; // esi
  bool v17; // zf
  double v18; // st7
  int ServerCount; // eax
  IMaterial *pMaterials[128]; // [esp+0h] [ebp-208h] BYREF
  double t1; // [esp+200h] [ebp-8h]
  unsigned __int8 bPreLoaded_3; // [esp+213h] [ebp+Bh]

  if ( mod_touchalldata.m_pParent == nullptr || mod_touchalldata.m_pParent->m_Value.m_nValue == 0 )
    LOBYTE(bTouchAllData) = 0;
  nLoadFlags = pModel->nLoadFlags;
  bPreLoaded_3 = BYTE2(nLoadFlags) & 1;
  v8 = nLoadFlags != 16;
  pModel->nLoadFlags = nLoadFlags & 0xFFFEFFFE | 1;
  if ( (nLoadFlags & 0x10000) == 0 )
  {
    v9 = ((int (__thiscall *)(IMDLCache *, char *))g_pMDLCache->FindMDL)(a1: g_pMDLCache, a2: pModel->szPathName);
    pModel->studio = v9;
    g_pMDLCache->SetUserData(this: g_pMDLCache, a2: v9, a3: pModel);
    InitStudioModelState(pModel);
  }
  v11 = (studiohdr_t *)((int (__stdcall *)(_DWORD, int, int, int))g_pMDLCache->GetStudioHdr)(
                         a1: pModel->studio,
                         a2: a3,
                         a3: a4,
                         a4: a2);
  if ( v8 && bPreLoaded_3 == 0 )
  {
    t1 = _Plat_FloatTime(a1: v10);
    ((void (__stdcall *)(_DWORD, int))g_pMDLCache->GetVCollideEx)(a1: pModel->studio, a2: bTouchAllData);
    v13 = _Plat_FloatTime(a1: v12) - t1;
    if ( (_BYTE)bTouchAllData != 0 )
      g_flAccumulatedModelLoadTimeVCollideSync = v13 + g_flAccumulatedModelLoadTimeVCollideSync;
    else
      g_flAccumulatedModelLoadTimeVCollideAsync = v13 + g_flAccumulatedModelLoadTimeVCollideAsync;
  }
  t1 = _Plat_FloatTime(a1: v10);
  v15 = g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v11, a3: 128, a4: pMaterials);
  v16 = 0;
  v17 = v15 == 0;
  if ( v15 > 0 )
  {
    do
    {
      pMaterials[v16]->IncrementReferenceCount(this: pMaterials[v16]);
      ++v16;
    }
    while ( v16 < v15 );
    v17 = v15 == 0;
  }
  if ( !v17 )
    pModel->nLoadFlags |= 0x20000u;
  v18 = _Plat_FloatTime(a1: v14);
  g_flAccumulatedModelLoadTimeMaterialNamesOnly = v18 - t1 + g_flAccumulatedModelLoadTimeMaterialNamesOnly;
  if ( __PAIR16__(bTouchAllData, bPreLoaded_3) != 0 )
  {
    ServerCount = Host_GetServerCount();
    Mod_TouchAllData(pModel, nServerCount: ServerCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED3A0
// Name: public: virtual void CModelLoader::Map_LoadDisplacements(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::Map_LoadDisplacements(
        CModelLoader *this@<ecx>,
        int a2@<ebx>,
        model_t *pModel,
        bool bRestoring)
{
  if ( pModel != nullptr )
  {
    V_FileBase(in: pModel->szPathName, out: this->m_szBaseName, maxlen: 64);
    CMapLoadHelper::Init(
      a1: a2,
      a2: (int)pModel->szPathName,
      p_lumpHeader: (lumpfileheader_t *)pModel,
      pMapModel: pModel,
      pPathName: pModel->szPathName);
    DispInfo_LoadDisplacements(pWorld: pModel, bRestoring);
    CMapLoadHelper::Shutdown();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED880
// Name: void Mod_LoadCubemapSamples(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Mod_LoadCubemapSamples(int a1@<edi>)
{
  char *m_szLumpFilename; // eax
  unsigned int m_nLumpSize; // ebx
  unsigned __int8 *m_pData; // edi
  int v4; // ebx
  bool v5; // zf
  char *v6; // eax
  const char *v7; // eax
  mcubemapsample_t *v8; // esi
  worldbrushdata_t *v9; // eax
  HDRType_t (__thiscall *GetHDRType)(IMaterialSystemHardwareConfig *); // edx
  float *p_pTexture; // esi
  unsigned int *v12; // edi
  __m128i v13; // xmm1
  __m128i v14; // xmm2
  ITexture *v15; // eax
  ITexture *v16; // eax
  const char *v17; // eax
  IMatRenderContext *v18; // eax
  IMatRenderContext *v19; // edi
  int v20; // eax
  int v21; // eax
  ITexture *v22; // esi
  char *v24; // [esp-Ch] [ebp-444h]
  char textureName[512]; // [esp+0h] [ebp-438h] BYREF
  char loadName[260]; // [esp+200h] [ebp-238h] BYREF
  CMapLoadHelper lh; // [esp+304h] [ebp-134h] BYREF
  int count; // [esp+42Ch] [ebp-Ch]
  int v29; // [esp+430h] [ebp-8h]
  char *pHDRExtension; // [esp+434h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x2Au, bUncompress: true);
  m_szLumpFilename = lh.m_szLumpFilename;
  if ( s_MapLumpFiles[lh.m_nLumpID].file == nullptr )
    m_szLumpFilename = s_szMapPathName;
  V_StripExtension(in: m_szLumpFilename, out: loadName, outSize: 260);
  m_nLumpSize = lh.m_nLumpSize;
  m_pData = lh.m_pData;
  if ( (lh.m_nLumpSize & 0xF) != 0 )
  {
    Host_Error(error: "Mod_LoadCubemapSamples: funny lump size in %s", s_szMapPathName);
    m_nLumpSize = lh.m_nLumpSize;
  }
  v4 = m_nLumpSize >> 4;
  v5 = s_MapLumpFiles[lh.m_nLumpID].file == nullptr;
  count = v4;
  v6 = lh.m_szLumpFilename;
  if ( v5 )
    v6 = s_szMapPathName;
  v7 = va(format: "%s [%s]", v6, "cubemapsample");
  v8 = (mcubemapsample_t *)Hunk_AllocName(size: 20 * v4, name: v7, bClear: true);
  v9 = s_pMap;
  s_pMap->m_pCubemapSamples = v8;
  v9->m_nCubemapSamples = v4;
  GetHDRType = g_pMaterialSystemHardwareConfig->GetHDRType;
  pHDRExtension = (char *)defaultValue;
  if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))GetHDRType)(
         a1: g_pMaterialSystemHardwareConfig,
         a2: a1) != 0 )
    pHDRExtension = ".hdr";
  if ( v4 > 0 )
  {
    p_pTexture = (float *)&v8->pTexture;
    v29 = v4;
    v12 = (unsigned int *)(m_pData + 8);
    do
    {
      v13 = _mm_cvtsi32_si128(*v12);
      v14 = _mm_cvtsi32_si128(*(v12 - 2));
      v24 = pHDRExtension;
      *(p_pTexture - 2) = (float)(int)*(v12 - 1);
      *((_DWORD *)p_pTexture - 1) = _mm_cvtepi32_ps(v13).m128_u32[0];
      *((_DWORD *)p_pTexture - 3) = _mm_cvtepi32_ps(v14).m128_u32[0];
      *((_BYTE *)p_pTexture + 4) = *((_BYTE *)v12 + 4);
      V_snprintf(
        pDest: textureName,
        maxLen: 512,
        pFormat: "%s/c%d_%d_%d%s",
        loadName,
        *(v12 - 2),
        *(v12 - 1),
        *v12,
        v24);
      v15 = materials->FindTexture(this: materials, a2: textureName, a3: "CubeMap textures", a4: 1, a5: 0);
      *(_DWORD *)p_pTexture = v15;
      if ( v15 == nullptr || v15->IsError(this: v15) )
      {
        if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
        {
          _Warning(a1: "Couldn't get HDR '%s' -- ", textureName);
          V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/c%d_%d_%d", loadName, *(v12 - 2), *(v12 - 1), *v12);
          _Warning(a1: "Trying non HDR '%s'\n", textureName);
          *(_DWORD *)p_pTexture = materials->FindTexture(
                                    this: materials,
                                    a2: textureName,
                                    a3: "CubeMap textures",
                                    a4: 1,
                                    a5: 0);
        }
        if ( *(_DWORD *)p_pTexture == 0
          || (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)p_pTexture + 60))(a1: *(_DWORD *)p_pTexture) != 0 )
        {
          V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/cubemapdefault", loadName);
          v16 = materials->FindTexture(this: materials, a2: textureName, a3: "CubeMap textures", a4: 1, a5: 0);
          *(_DWORD *)p_pTexture = v16;
          if ( v16 == nullptr || v16->IsError(this: v16) )
            *(_DWORD *)p_pTexture = materials->FindTexture(
                                      this: materials,
                                      a2: "engine/defaultcubemap",
                                      a3: "CubeMap textures",
                                      a4: 1,
                                      a5: 0);
          v17 = (const char *)(***(int (__thiscall ****)(_DWORD))p_pTexture)(a1: *(_DWORD *)p_pTexture);
          _Warning(a1: "Failed, using default cubemap '%s'\n", v17);
        }
      }
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)p_pTexture + 40))(a1: *(_DWORD *)p_pTexture);
      v12 += 4;
      p_pTexture += 5;
      --v29;
    }
    while ( v29 != 0 );
    v4 = count;
  }
  v18 = materials->GetRenderContext(this: materials);
  v19 = v18;
  if ( v18 != nullptr )
    v18->BeginRender(this: v18);
  if ( v4 != 0 )
  {
    v19->BindLocalCubemap(this: v19, a2: s_pMap->m_pCubemapSamples->pTexture);
  }
  else
  {
    v20 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v20 + 12))(
           a1: v20,
           a2: "-requirecubemaps",
           a3: 0) != 0 )
      Sys_Error(error: "Map \"%s\" does not have cubemaps!", s_szMapPathName);
    V_snprintf(pDest: textureName, maxLen: 512, pFormat: "%s/cubemapdefault", loadName);
    v21 = ((int (__thiscall *)(IMaterialSystem *, char *, const char *))materials->FindTexture)(
            a1: materials,
            a2: textureName,
            a3: "CubeMap textures");
    v22 = (ITexture *)v21;
    if ( v21 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v21 + 60))(a1: v21) != 0 )
      v22 = materials->FindTexture(this: materials, a2: "engine/defaultcubemap", a3: "CubeMap textures", a4: 1, a5: 0);
    v22->IncrementReferenceCount(this: v22);
    v19->BindLocalCubemap(this: v19, a2: v22);
  }
  v19->EndRender(this: v19);
  v19->Release(this: v19);
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EDC90
// Name: public: virtual struct model_t __near * CModelLoader::GetModelForIndex(int)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::GetModelForIndex(CModelLoader *this, int i)
{
  if ( i < 0 || i >= (unsigned int)this->m_Models.m_Tree.m_NumElements )
    return nullptr;
  else
    return this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem.modelpointer;
}

//------------------------------------------------------------------------------
// Address: 0x100EDCC0
// Name: private: struct model_t __near * CModelLoader::LoadModel(struct model_t __near *,enum IModelLoader::REFERENCETYPE __near *)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::LoadModel(
        CModelLoader *this,
        model_t *mod,
        IModelLoader::REFERENCETYPE *pReferencetype)
{
  char v3; // bl
  int ServerCount; // eax
  int v5; // ecx
  int v6; // edi
  CModelLoader *v8; // ebx
  const char *v9; // edi
  modtype_t TypeFromName; // eax
  ConVar *m_pParent; // ecx
  IMDLCache *v12; // edi
  int v13; // ecx
  int v14; // ecx
  IMDLCache *v15; // edi
  int v16; // ecx
  int v17; // ecx
  vgui::PropertyPage *v18; // ecx
  int v19; // ecx
  double v20; // st7
  double v21; // st7
  double v22; // st7
  char szExcludePath[260]; // [esp+24h] [ebp-218h] BYREF
  char szNameOnDisk[260]; // [esp+128h] [ebp-114h] BYREF
  double st; // [esp+22Ch] [ebp-10h]
  double t1; // [esp+234h] [ebp-8h]
  float bTouchAllData; // [esp+248h] [ebp+Ch]

  HIDWORD(t1) = this;
  if ( pReferencetype != nullptr )
    mod->nLoadFlags |= *pReferencetype;
  v3 = 0;
  LOBYTE(pReferencetype) = 0;
  ServerCount = Host_GetServerCount();
  v6 = ServerCount;
  if ( mod->nServerCount != ServerCount )
  {
    v3 = 1;
    mod->nServerCount = ServerCount;
    LOBYTE(pReferencetype) = 1;
  }
  if ( mod->type != mod_studio || (mod->nLoadFlags & 0x10000) != 0 )
  {
    if ( (mod->nLoadFlags & 1) == 0 )
    {
      st = _Plat_FloatTime(a1: v5);
      v8 = (CModelLoader *)HIDWORD(t1);
      v9 = (const char *)(HIDWORD(t1) + 368);
      V_FileBase(in: mod->szPathName, out: (char *)(HIDWORD(t1) + 368), maxlen: 64);
      if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "Loading: %s\n", mod->szPathName);
      TypeFromName = CModelLoader::GetTypeFromName(this: (CModelLoader *)HIDWORD(t1), pModelName: mod->szPathName);
      mod->type = TypeFromName;
      m_pParent = developer.m_pParent;
      if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
        DevMsg(a1: "Loading type: %d\n", TypeFromName);
      if ( mod->type == mod_bad )
        mod->type = mod_studio;
      switch ( mod->type )
      {
        case mod_brush:
          t1 = _Plat_FloatTime(a1: m_pParent);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading brush, compacting heap...\n");
          _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
          if ( mod->szPathName != szNameOnDisk )
            V_strncpy(pDest: szNameOnDisk, pSrc: mod->szPathName, maxLen: 260);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: %s\n", szNameOnDisk);
          g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME", a4: PATH_ADD_TO_HEAD);
          if ( mat_excludetextures.m_pParent != nullptr && mat_excludetextures.m_pParent->m_Value.m_nValue != 0 )
          {
            sprintf(string: szExcludePath, format: "//MOD/maps/%s_exclude.lst", v9);
            if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
              DevMsg(a1: "Setting excluded textures: %s\n", szExcludePath);
            g_pMaterialSystem->SetExcludedTextures(this: g_pMaterialSystem, a2: szExcludePath);
          }
          NotifyHunkBeginMapLoad(pszMapName: v9);
          if ( mat_excludetextures.m_pParent != nullptr && mat_excludetextures.m_pParent->m_Value.m_nValue != 0 )
            g_pMaterialSystem->UpdateExcludedTextures(this: g_pMaterialSystem);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: BeginLoadingUpdates...\n");
          CColorBalanceUIPanel::Init(this: v18);
          g_pFileSystem->BeginMapAccess(this: g_pFileSystem);
          if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1 )
            DevMsg(a1: "Loading map: Map_LoadModel...\n");
          CModelLoader::Map_LoadModel(this: v8, mod);
          g_pFileSystem->EndMapAccess(this: g_pFileSystem);
          v20 = _Plat_FloatTime(a1: v19);
          g_flAccumulatedModelLoadTimeBrush = v20 - t1 + g_flAccumulatedModelLoadTimeBrush;
          break;
        case mod_sprite:
          v15 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          t1 = _Plat_FloatTime(a1: v16);
          CModelLoader::Sprite_LoadModel(this: v8, mod);
          g_flAccumulatedModelLoadTimeSprite = _Plat_FloatTime(a1: v17) - t1 + g_flAccumulatedModelLoadTimeSprite;
          v15->EndLock(this: v15);
          break;
        case mod_studio:
          v12 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          t1 = _Plat_FloatTime(a1: v13);
          CModelLoader::Studio_LoadModel(
            this: v8,
            a2: (int)v8,
            a3: (int)v12,
            a4: (int)mod,
            pModel: mod,
            bTouchAllData: (int)pReferencetype);
          g_flAccumulatedModelLoadTimeStudio = _Plat_FloatTime(a1: v14) - t1 + g_flAccumulatedModelLoadTimeStudio;
          v12->EndLock(this: v12);
          break;
        default:
          break;
      }
      v21 = _Plat_FloatTime(a1: m_pParent);
      v22 = v21 - st;
      bTouchAllData = v22;
      _COM_TimestampedLog(a1: "Load of %s took %.3f msec", mod->szPathName, v22 * 1000.0);
      g_flAccumulatedModelLoadTime = bTouchAllData + g_flAccumulatedModelLoadTime;
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: mod->studio);
    if ( v3 != 0 )
    {
      Mod_TouchAllData(pModel: mod, nServerCount: v6);
      return mod;
    }
  }
  return mod;
}

//------------------------------------------------------------------------------
// Address: 0x100EE060
// Name: public: virtual void CModelLoader::UnreferenceAllModels(enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnreferenceAllModels(CModelLoader *this, IModelLoader::REFERENCETYPE referencetype)
{
  int m_NumElements; // ebx
  int v4; // edi

  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  v4 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
      this->UnreferenceModel(
        this,
        a2: this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4++].m_Data.elem.modelpointer,
        a3: referencetype);
    while ( v4 < m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE0A0
// Name: public: virtual void CModelLoader::ReloadFilesInList(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CModelLoader::ReloadFilesInList(
        CModelLoader *this@<ecx>,
        int studio@<edi>,
        int a3@<esi>,
        IFileList *pFilesToReload)
{
  CModelLoader *v4; // ebx
  int m_NumElements; // ecx
  int v6; // eax
  model_t *modelpointer; // esi
  IMDLCache *v8; // edi
  studiohdr_t *v9; // eax
  int v10; // ebx
  int v11; // edi
  IMaterial *v12; // ecx
  IMaterial *pMaterials[128]; // [esp+4h] [ebp-20Ch] BYREF
  int c; // [esp+204h] [ebp-Ch]
  int i; // [esp+208h] [ebp-8h]
  CModelLoader *v18; // [esp+20Ch] [ebp-4h]

  v4 = this;
  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  LOWORD(v6) = 0;
  v18 = v4;
  c = m_NumElements;
  i = 0;
  if ( m_NumElements != 0 )
  {
    do
    {
      modelpointer = v4->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v6].m_Data.elem.modelpointer;
      if ( modelpointer->type == mod_studio
        && v4->IsLoaded(this: v4, a2: modelpointer)
        && modelpointer->type == mod_studio )
      {
        if ( ((int (__thiscall *)(IFileList *, char *, int, int))pFilesToReload->IsFileInList)(
               a1: pFilesToReload,
               a2: modelpointer->szPathName,
               a3: studio,
               a4: a3) != 0 )
        {
          a3 = 2147483643;
          studio = modelpointer->studio;
          ((void (*)(void))g_pMDLCache->Flush)();
          v8 = g_pMDLCache;
          g_pMDLCache->BeginLock(this: g_pMDLCache);
          ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
          ((void (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: modelpointer->studio);
          v8->EndLock(this: v8);
        }
        else
        {
          a3 = 1;
          studio = modelpointer->studio;
          if ( ((unsigned __int8 (*)(void))g_pMDLCache->IsDataLoaded)() != 0 )
          {
            v9 = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
            if ( v9 != nullptr )
            {
              v10 = g_pStudioRender->GetMaterialList(this: g_pStudioRender, a2: v9, a3: 128, a4: pMaterials);
              v11 = 0;
              if ( v10 > 0 )
              {
                while ( 1 )
                {
                  v12 = pMaterials[v11];
                  if ( v12 != nullptr && v12->WasReloadedFromWhitelist(this: v12) )
                    break;
                  if ( ++v11 >= v10 )
                    goto LABEL_15;
                }
                ((void (__stdcall *)(_DWORD, int))g_pMDLCache->Flush)(a1: modelpointer->studio, a2: 2);
              }
LABEL_15:
              v4 = v18;
            }
          }
        }
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE230
// Name: public: virtual void CModelLoader::Studio_ReloadModels(enum IModelLoader::ReloadType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Studio_ReloadModels(CModelLoader *this, IModelLoader::ReloadType_t reloadType)
{
  CModelLoader *v2; // esi
  int v3; // ebx
  model_t *modelpointer; // edi
  IMDLCache *v5; // esi
  int c; // [esp+8h] [ebp-8h]

  v2 = this;
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->InvalidateMdlCache(this: g_ClientDLL);
  if ( serverGameDLL != nullptr )
    serverGameDLL->InvalidateMdlCache(this: serverGameDLL);
  modelrender->RemoveAllDecalsFromAllModels(this: modelrender);
  modelrender->ReleaseAllStaticPropColorData(this: modelrender);
  g_pMDLCache->Flush_2(this: g_pMDLCache, a2: (MDLCacheFlush_t)2147483643);
  v3 = 0;
  c = v2->m_Models.m_Tree.m_NumElements;
  if ( v2->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      modelpointer = v2->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( v2->IsLoaded(this: v2, a2: modelpointer) && modelpointer->type == mod_studio )
      {
        v5 = g_pMDLCache;
        g_pMDLCache->BeginLock(this: g_pMDLCache);
        ((void (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: modelpointer->studio);
        ((void (__stdcall *)(_DWORD))g_pMDLCache->GetVCollide)(a1: modelpointer->studio);
        v5->EndLock(this: v5);
        v2 = this;
      }
      ++v3;
    }
    while ( v3 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE320
// Name: public: virtual void CModelLoader::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Print(CModelLoader *this)
{
  CModelLoader *v1; // esi
  int v2; // edi
  model_t *modelpointer; // esi
  modtype_t type; // eax
  int v5; // eax
  int c; // [esp+Ch] [ebp-8h]

  v1 = this;
  ConMsg(a1: "Models:\n");
  v2 = 0;
  c = v1->m_Models.m_Tree.m_NumElements;
  if ( v1->m_Models.m_Tree.m_NumElements != 0 )
  {
    while ( 1 )
    {
      modelpointer = v1->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v2].m_Data.elem.modelpointer;
      type = modelpointer->type;
      if ( type == mod_studio )
      {
        v5 = ((int (__stdcall *)(_DWORD))g_pMDLCache->GetRef)(a1: modelpointer->studio);
      }
      else
      {
        if ( type != mod_bad )
        {
          ConMsg(a1: "%4d: Flags:0x%8.8x %s\n", v2, modelpointer->nLoadFlags, modelpointer->szPathName);
          goto LABEL_10;
        }
        v5 = 0;
      }
      ConMsg(a1: "%4d: Flags:0x%8.8x RefCount:%2d %s\n", v2, modelpointer->nLoadFlags, v5, modelpointer->szPathName);
LABEL_10:
      if ( ++v2 >= c )
        return;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEFA0
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    free(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF020
// Name: void Mod_LoadOcclusion(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadOcclusion()
{
  worldbrushdata_t *v0; // eax
  int *p_numoccluderpolys; // ecx
  int *p_numoccluders; // esi
  doccluderpolydata_t **p_occluderpolys; // edi
  doccluderdata_t **p_occluders; // ebx
  int v5; // eax
  int v6; // esi
  doccluderdata_t *v7; // eax
  int Int; // eax
  doccluderdata_t *v9; // eax
  bool v10; // cc
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // esi
  doccluderpolydata_t *v15; // eax
  int v16; // eax
  int v17; // esi
  int *v18; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-198h] BYREF
  doccluderdataV1_t temp; // [esp+134h] [ebp-70h] BYREF
  CUtlBuffer buf; // [esp+158h] [ebp-4Ch] BYREF
  doccluderpolydata_t **v22; // [esp+188h] [ebp-1Ch]
  int *v23; // [esp+18Ch] [ebp-18h]
  int i; // [esp+190h] [ebp-14h]
  int *v25; // [esp+194h] [ebp-10h]
  int *p_numoccludervertindices; // [esp+198h] [ebp-Ch]
  int **p_occludervertindices; // [esp+19Ch] [ebp-8h]
  int v28; // [esp+1A0h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 9u, bUncompress: true);
  v0 = s_pMap;
  p_numoccluderpolys = &s_pMap->numoccluderpolys;
  p_numoccluders = &s_pMap->numoccluders;
  p_occluderpolys = &s_pMap->occluderpolys;
  p_occluders = &s_pMap->occluders;
  s_pMap->numoccluderpolys = 0;
  v25 = p_numoccluderpolys;
  *p_numoccluders = 0;
  *p_occluders = nullptr;
  *p_occluderpolys = nullptr;
  v0->numoccludervertindices = 0;
  p_occludervertindices = &v0->occludervertindices;
  v0->occludervertindices = nullptr;
  v23 = p_numoccluders;
  v22 = p_occluderpolys;
  p_numoccludervertindices = &v0->numoccludervertindices;
  if ( lh.m_nLumpSize == 0 )
    goto LABEL_21;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: lh.m_pData, nSize: lh.m_nLumpSize, nFlags: 8);
  if ( lh.m_nLumpVersion != 0 )
  {
    if ( lh.m_nLumpVersion == 1 )
    {
      Int = CUtlBuffer::GetInt(this: &buf);
      *p_numoccluders = Int;
      if ( Int != 0 )
      {
        v9 = (doccluderdata_t *)Hunk_AllocName(size: 40 * Int, name: "occluder data", bClear: true);
        v10 = *p_numoccluders <= 0;
        *p_occluders = v9;
        i = 0;
        if ( !v10 )
        {
          v28 = 0;
          do
          {
            CUtlBuffer::Get(this: &buf, pMem: &temp, size: 36);
            v11 = i;
            *(doccluderdataV1_t *)((char *)&(*p_occluders)->flags + v28) = temp;
            v12 = v28;
            *(int *)((char *)&(*p_occluders)->area + v28) = 1;
            v28 = v12 + 40;
            i = v11 + 1;
          }
          while ( v11 + 1 < *v23 );
          p_occluderpolys = v22;
        }
      }
    }
    else
    {
      if ( lh.m_nLumpVersion != 2 )
      {
        Host_Error(error: "Invalid occlusion lump version!\n");
        goto LABEL_17;
      }
      v5 = CUtlBuffer::GetInt(this: &buf);
      *p_numoccluders = v5;
      if ( v5 != 0 )
      {
        v6 = 40 * v5;
        v7 = (doccluderdata_t *)Hunk_AllocName(size: 40 * v5, name: "occluder data", bClear: true);
        *p_occluders = v7;
        CUtlBuffer::Get(this: &buf, pMem: v7, size: v6);
      }
    }
    v13 = CUtlBuffer::GetInt(this: &buf);
    *v25 = v13;
    if ( v13 != 0 )
    {
      v14 = 12 * v13;
      v15 = (doccluderpolydata_t *)Hunk_AllocName(size: 12 * v13, name: "occluder poly data", bClear: true);
      *p_occluderpolys = v15;
      CUtlBuffer::Get(this: &buf, pMem: v15, size: v14);
    }
    v16 = CUtlBuffer::GetInt(this: &buf);
    *p_numoccludervertindices = v16;
    if ( v16 != 0 )
    {
      v17 = 4 * v16;
      v18 = (int *)Hunk_AllocName(size: 4 * v16, name: "occluder vertices", bClear: true);
      *p_occludervertindices = v18;
      CUtlBuffer::Get(this: &buf, pMem: v18, size: v17);
    }
  }
LABEL_17:
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
LABEL_21:
  if ( lh.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lh.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EF410
// Name: void Mod_LoadGameLumpDict(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadGameLumpDict()
{
  int v0; // ebx
  unsigned __int8 *m_pRawData; // eax
  bool v2; // zf
  unsigned __int8 *v3; // edi
  int m_Size; // ecx
  int v5; // esi
  dgamelump_t *v6; // esi
  CMapLoadHelper lh; // [esp+4h] [ebp-12Ch] BYREF
  dgamelumpheader_t *pGameLumpHeader; // [esp+12Ch] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x23u, bUncompress: true);
  v0 = 0;
  g_GameLumpDict.m_Size = 0;
  V_strncpy(pDest: g_GameLumpFilename, pSrc: s_szMapPathName, maxLen: 260);
  if ( lh.m_nLumpSize != 0 )
  {
    pGameLumpHeader = (dgamelumpheader_t *)lh.m_pData;
    v3 = lh.m_pData + 4;
    if ( *(int *)lh.m_pData > 0 )
    {
      m_Size = g_GameLumpDict.m_Size;
      do
      {
        v5 = m_Size;
        if ( m_Size + 1 > g_GameLumpDict.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CPortalRect,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_GameLumpDict,
            num: m_Size - g_GameLumpDict.m_Memory.m_nAllocationCount + 1);
          m_Size = g_GameLumpDict.m_Size;
        }
        g_GameLumpDict.m_Size = ++m_Size;
        g_GameLumpDict.m_pElements = g_GameLumpDict.m_Memory.m_pMemory;
        if ( m_Size - v5 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_GameLumpDict.m_Memory.m_pMemory[v5 + 1],
            src: &g_GameLumpDict.m_Memory.m_pMemory[v5],
            count: 16 * (m_Size - v5 - 1));
          m_Size = g_GameLumpDict.m_Size;
        }
        v6 = &g_GameLumpDict.m_Memory.m_pMemory[v5];
        if ( v6 != nullptr )
        {
          v6->id = *(_DWORD *)v3;
          *(_DWORD *)&v6->flags = *((_DWORD *)v3 + 1);
          v6->fileofs = *((_DWORD *)v3 + 2);
          v6->filelen = *((_DWORD *)v3 + 3);
          m_Size = g_GameLumpDict.m_Size;
        }
        ++v0;
        v3 += 16;
      }
      while ( v0 < pGameLumpHeader->lumpCount );
    }
    m_pRawData = lh.m_pRawData;
    v2 = lh.m_pRawData == nullptr;
  }
  else
  {
    m_pRawData = lh.m_pRawData;
    v2 = lh.m_pRawData == nullptr;
  }
  if ( !v2 )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x100EF540
// Name: public: virtual void CModelLoader::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Init(CModelLoader *this)
{
  CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Models.m_Tree);
  this->m_InlineModels.m_Size = 0;
  if ( this->m_InlineModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InlineModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InlineModels.m_Memory.m_pMemory);
      this->m_InlineModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_InlineModels.m_pElements = this->m_InlineModels.m_Memory.m_pMemory;
  this->m_pWorldModel = nullptr;
  *(_WORD *)&this->m_bMapRenderInfoLoaded = 0;
  g_bLoadedMapHasBakedPropLighting = false;
  this->m_worldBrushData.m_pLightingDataStack = &this->m_WorldLightingDataStack;
  CollisionBSPData_LinkPhysics();
}

//------------------------------------------------------------------------------
// Address: 0x100EF5A0
// Name: public: void CModelLoader::AllocateLightstyles(struct model_t __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::AllocateLightstyles(
        CModelLoader *this,
        model_t *pModel,
        unsigned __int8 *pStyles,
        int nStyleCount)
{
  unsigned __int16 m_Size; // dx
  int v5; // ebx
  CUtlMemory<char,int> *p_m_LightStyleList; // esi
  char *m_pMemory; // edi
  int m_nAllocationCount; // eax
  char *v9; // ecx
  int v10; // eax
  char *v11; // eax
  unsigned __int16 nLast; // [esp+8h] [ebp-4h]

  m_Size = this->m_LightStyleList.m_Size;
  v5 = 0;
  nLast = m_Size;
  if ( nStyleCount <= 0 )
  {
    pModel->brush.nLightstyleCount = nStyleCount;
    pModel->brush.nLightstyleIndex = m_Size;
  }
  else
  {
    p_m_LightStyleList = (CUtlMemory<char,int> *)&this->m_LightStyleList;
    do
    {
      m_pMemory = p_m_LightStyleList[1].m_pMemory;
      m_nAllocationCount = p_m_LightStyleList->m_nAllocationCount;
      if ( (int)(m_pMemory + 1) > m_nAllocationCount )
        CUtlMemory<bool,int>::Grow(this: p_m_LightStyleList, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
      ++p_m_LightStyleList[1].m_pMemory;
      v9 = p_m_LightStyleList->m_pMemory;
      v10 = p_m_LightStyleList[1].m_pMemory - m_pMemory - 1;
      p_m_LightStyleList[1].m_nAllocationCount = (int)p_m_LightStyleList->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: v10);
      v11 = &m_pMemory[(unsigned int)p_m_LightStyleList->m_pMemory];
      if ( v11 != nullptr )
        *v11 = pStyles[v5];
      ++v5;
    }
    while ( v5 < nStyleCount );
    pModel->brush.nLightstyleCount = nStyleCount;
    pModel->brush.nLightstyleIndex = nLast;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF650
// Name: Mod_ComputeBrushModelFlags
// Source: json
//------------------------------------------------------------------------------
void __usercall Mod_ComputeBrushModelFlags(int a1@<edi>, model_t *mod)
{
  model_t *v2; // eax
  int nummodelsurfaces; // edx
  worldbrushdata_t *pShared; // ecx
  int v5; // esi
  unsigned int v6; // eax
  int v7; // edi
  int v8; // ebx
  char *v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // bl
  int m_Size; // ecx
  int v13; // eax
  unsigned __int8 *m_pMemory; // edi
  int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // esi
  int v18; // ecx
  model_t *v19; // eax
  unsigned __int8 *v21; // [esp-8h] [ebp-38h]
  int v22; // [esp-4h] [ebp-34h]
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > lightStyles; // [esp+4h] [ebp-2Ch] BYREF
  int scount; // [esp+18h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-14h]
  char *v26; // [esp+20h] [ebp-10h]
  worldbrushdata_t *pBrushData; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  bool bHasTranslucentSurfaces; // [esp+2Eh] [ebp-2h]
  bool bHasOpaqueSurfaces; // [esp+2Fh] [ebp-1h]

  v2 = mod;
  nummodelsurfaces = mod->brush.nummodelsurfaces;
  pShared = mod->brush.pShared;
  pBrushData = pShared;
  mod->flags = 32;
  scount = nummodelsurfaces;
  bHasOpaqueSurfaces = false;
  bHasTranslucentSurfaces = false;
  mod->brush.nLightstyleIndex = 0;
  mod->brush.nLightstyleCount = 0;
  memset(&lightStyles, 0, sizeof(lightStyles));
  i = 0;
  if ( nummodelsurfaces <= 0 )
    goto LABEL_43;
  while ( 2 )
  {
    v5 = (int)&pShared->surfaces2[i + v2->brush.firstmodelsurface];
    v6 = *(unsigned __int16 *)(v5 + 22);
    *(_DWORD *)v5 &= 0xFFFFADDF;
    v7 = (int)&pShared->texinfo[v6 >> 1];
    v8 = *(_DWORD *)(v7 + 76);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 84))(a1: v8, a2: a1) != 0 )
      mod->flags |= 1u;
    a1 = 0;
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 96))(a1: v8) != 0 )
      mod->flags |= 0x10u;
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 132))(a1: v8) != 0 )
      *(_DWORD *)v5 |= 0x200u;
    if ( (*(_BYTE *)(v7 + 72) & 0x10) != 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 68))(a1: v8) != 0 )
    {
      mod->flags |= 2u;
      *(_DWORD *)v5 |= 0x20u;
      bHasTranslucentSurfaces = true;
    }
    else
    {
      bHasOpaqueSurfaces = true;
    }
    if ( (*(_WORD *)(v7 + 72) & 0x2000) != 0
      || (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 120))(a1: v8, a2: 0x4000000) != 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 72))(a1: v8) != 0 )
    {
      *(_DWORD *)v5 |= 0x4000u;
    }
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 72))(a1: v8) != 0 )
      *(_DWORD *)v5 |= 0x1000u;
    v9 = (char *)pBrushData->surfacelighting + ((v5 - (unsigned int)pBrushData->surfaces2) & 0xFFFFFFE0);
    v10 = (unsigned __int8 *)(v9 + 24);
    v26 = v9 + 24;
    v25 = -24 - (_DWORD)v9;
    do
    {
      v11 = *v10;
      if ( *v10 == 0xFF )
        break;
      m_Size = lightStyles.m_Size;
      v13 = 0;
      if ( lightStyles.m_Size <= 0 )
      {
        m_pMemory = lightStyles.m_Memory.m_pMemory;
      }
      else
      {
        while ( 1 )
        {
          m_pMemory = lightStyles.m_Memory.m_pMemory;
          if ( lightStyles.m_Memory.m_pMemory[v13] == v11 )
            break;
          if ( ++v13 >= lightStyles.m_Size )
            goto LABEL_29;
        }
        if ( v13 != -1 )
          goto LABEL_35;
      }
LABEL_29:
      v15 = lightStyles.m_Size;
      if ( lightStyles.m_Size + 1 > lightStyles.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<char,int> *)&lightStyles,
          num: lightStyles.m_Size - lightStyles.m_Memory.m_nAllocationCount + 1);
        m_Size = lightStyles.m_Size;
        m_pMemory = lightStyles.m_Memory.m_pMemory;
      }
      v16 = m_Size + 1;
      lightStyles.m_Size = v16;
      lightStyles.m_pElements = m_pMemory;
      if ( v16 - v15 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: v16 - v15 - 1);
      v17 = &m_pMemory[v15];
      if ( v17 != nullptr )
        *v17 = v11;
LABEL_35:
      v10 = (unsigned __int8 *)(v26 + 1);
      v18 = (int)&(++v26)[v25];
    }
    while ( v18 < 4 );
    if ( ++i < scount )
    {
      v2 = mod;
      pShared = pBrushData;
      continue;
    }
    break;
  }
  if ( bHasOpaqueSurfaces && bHasTranslucentSurfaces )
  {
    v19 = mod;
    mod->flags |= 8u;
  }
  else
  {
    v19 = mod;
  }
  if ( lightStyles.m_Size != 0 )
  {
    v22 = lightStyles.m_Size;
    v21 = lightStyles.m_Memory.m_pMemory;
    v19->brush.nLightstyleLastComputedFrame = 0;
    CModelLoader::AllocateLightstyles(this: &g_ModelLoader, pModel: v19, pStyles: v21, nStyleCount: v22);
  }
LABEL_43:
  if ( lightStyles.m_Memory.m_nGrowSize >= 0 && lightStyles.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lightStyles.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100EF8A0
// Name: int Mod_GetMaterialCount(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Mod_GetMaterialCount(model_t *mod)
{
  model_t *v1; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  int m_Size; // esi
  IMaterial **v5; // eax
  int v6; // edx
  IMaterial **m_pMemory; // edi
  worldbrushdata_t *pShared; // ecx
  int v9; // eax
  IMaterial *material; // ecx
  int v11; // eax
  int v12; // ebx
  IMaterial **v13; // ebx
  CUtlVector<IMaterial *,CUtlMemory<IMaterial *,int> > uniqueMaterials; // [esp+4h] [ebp-1Ch] BYREF
  int i; // [esp+18h] [ebp-8h]
  IMaterial *pMaterial; // [esp+1Ch] [ebp-4h]

  v1 = mod;
  if ( mod->type != mod_brush )
    return 0;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  m_Size = 0;
  uniqueMaterials.m_Memory.m_nAllocationCount = 32;
  uniqueMaterials.m_Memory.m_nGrowSize = 0;
  v5 = (IMaterial **)Alloc_2(this: _g_pMemAlloc, a2: 128u);
  v6 = 0;
  m_pMemory = v5;
  uniqueMaterials.m_Memory.m_pMemory = v5;
  uniqueMaterials.m_Size = 0;
  uniqueMaterials.m_pElements = v5;
  i = 0;
  if ( mod->brush.nummodelsurfaces > 0 )
  {
    do
    {
      pShared = v1->brush.pShared;
      v9 = (int)&pShared->surfaces2[v6 + v1->brush.firstmodelsurface];
      if ( (*(_BYTE *)v9 & 0x10) == 0 )
      {
        material = pShared->texinfo[*(unsigned __int16 *)(v9 + 22) >> 1].material;
        v11 = 0;
        pMaterial = material;
        if ( m_Size <= 0 )
          goto LABEL_10;
        while ( m_pMemory[v11] != material )
        {
          if ( ++v11 >= m_Size )
            goto LABEL_10;
        }
        if ( v11 < 0 )
        {
LABEL_10:
          v12 = m_Size;
          if ( m_Size + 1 > uniqueMaterials.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&uniqueMaterials,
              num: m_Size - uniqueMaterials.m_Memory.m_nAllocationCount + 1);
            m_Size = uniqueMaterials.m_Size;
            m_pMemory = uniqueMaterials.m_Memory.m_pMemory;
            material = pMaterial;
          }
          uniqueMaterials.m_Size = ++m_Size;
          uniqueMaterials.m_pElements = m_pMemory;
          if ( m_Size - v12 - 1 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * (m_Size - v12 - 1));
            material = pMaterial;
          }
          v13 = &m_pMemory[v12];
          if ( v13 != nullptr )
            *v13 = material;
          v1 = mod;
        }
      }
      v6 = i + 1;
      i = v6;
    }
    while ( v6 < v1->brush.nummodelsurfaces );
  }
  if ( uniqueMaterials.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100EF9E0
// Name: public: virtual void CModelLoader::RecomputeSurfaceFlags(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::RecomputeSurfaceFlags(CModelLoader *this, model_t *mod)
{
  worldbrushdata_t *pShared; // eax
  int v4; // ebx
  model_t *v5; // esi
  worldbrushdata_t *v6; // eax
  CBrushBSPIterator v7; // [esp+8h] [ebp-1Ch] BYREF
  model_t *pModel; // [esp+1Ch] [ebp-8h]
  CModelLoader *v9; // [esp+20h] [ebp-4h]
  model_t *moda; // [esp+2Ch] [ebp+8h]

  pShared = mod->brush.pShared;
  v4 = 0;
  v9 = this;
  if ( pShared->numsubmodels > 0 )
  {
    moda = nullptr;
    do
    {
      v5 = (model_t *)((char *)moda + (unsigned int)v9->m_InlineModels.m_Memory.m_pMemory);
      Mod_ComputeBrushModelFlags(a1: (int)mod, mod: v5);
      if ( v4 != 0 )
      {
        v6 = v5->brush.pShared;
        pModel = host_state.worldmodel;
        v7.__vftable = (CBrushBSPIterator_vtbl *)&CBrushBSPIterator::`vftable';
        v7.m_pWorld = mod;
        v7.m_pBrush = v5;
        v7.m_pShared = v6;
        v7.m_count = 0;
        CCommonHostState::SetWorldModel(this: &host_state, pModel: mod);
        g_pToolBSPTree->EnumerateLeavesInBox(this: g_pToolBSPTree, a2: &v5->mins, a3: &v5->maxs, a4: &v7, a5: (int)v5);
        if ( v7.m_count == 0 )
          CBrushBSPIterator::MarkModelSurfaces(this: &v7, flags: 0x40000);
        CCommonHostState::SetWorldModel(this: &host_state, pModel);
      }
      ++moda;
      ++v4;
    }
    while ( v4 < mod->brush.pShared->numsubmodels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFAB0
// Name: private: void CModelLoader::Map_UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_UnloadModel(CModelLoader *this, model_t *mod)
{
  IOverlayMgr *v3; // eax
  int v4; // edi
  int v5; // ebx
  mtexinfo_t *v6; // eax
  CModelLoader_vtbl *v7; // eax

  mod->nLoadFlags &= ~1u;
  v3 = OverlayMgr();
  v3->UnloadOverlays(this: v3);
  DeallocateLightingData(pBrushData: &this->m_worldBrushData);
  DispInfo_ReleaseMaterialSystemObjects(pWorld: mod);
  if ( g_pSimpleWorldModel != nullptr )
    CModelLoader::UnloadModel(this, pModel: g_pSimpleWorldModel);
  if ( g_pSimpleWorldModelWater != nullptr )
    CModelLoader::UnloadModel(this, pModel: g_pSimpleWorldModelWater);
  g_pSimpleWorldModel = nullptr;
  g_pSimpleWorldModelWater = nullptr;
  CModelLoader::Map_UnloadCubemapSamples(this, mod);
  R_DecalTerm(pBrushData: &this->m_worldBrushData, term_permanent_decals: true);
  v4 = 0;
  if ( this->m_worldBrushData.hDispInfos != nullptr )
  {
    DispInfo_DeleteArray(hArray: this->m_worldBrushData.hDispInfos);
    this->m_worldBrushData.hDispInfos = nullptr;
  }
  if ( this->m_worldBrushData.numtexinfo > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->m_worldBrushData.texinfo[v5];
      if ( v6 != nullptr )
        GL_UnloadMaterial(pMaterial: v6->material);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_worldBrushData.numtexinfo );
  }
  MaterialSystem_DestroySortinfo();
  this->m_pWorldModel = nullptr;
  this->m_InlineModels.m_Size = 0;
  if ( this->m_InlineModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_InlineModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_InlineModels.m_Memory.m_pMemory);
      this->m_InlineModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_InlineModels.m_pElements = this->m_InlineModels.m_Memory.m_pMemory;
  memset(dst: (unsigned __int8 *)&this->m_worldBrushData, value: 0, count: sizeof(this->m_worldBrushData));
  v7 = this->__vftable;
  this->m_worldBrushData.m_pLightingDataStack = &this->m_WorldLightingDataStack;
  v7->Map_SetRenderInfoAllocated(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100EFBE0
// Name: public: int CModelLoader::FindNext(int,struct model_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::FindNext(CModelLoader *this, int iIndex, model_t **ppModel)
{
  unsigned __int16 Inorder; // si
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short> *p_m_Models; // edi
  int result; // eax

  Inorder = iIndex;
  if ( iIndex != -1 )
  {
    if ( this->m_Models.m_Tree.m_NumElements != 0 )
    {
      p_m_Models = &this->m_Models;
      if ( (unsigned __int16)iIndex < this->m_Models.m_Tree.m_Elements.m_nAllocationCount
        && (unsigned __int16)iIndex <= this->m_Models.m_Tree.m_LastAlloc.index
        && CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
             this: &this->m_Models.m_Tree,
             i: iIndex) != (_WORD)iIndex )
      {
        goto LABEL_8;
      }
    }
LABEL_10:
    *ppModel = nullptr;
    return -1;
  }
  if ( this->m_Models.m_Tree.m_NumElements == 0 )
    goto LABEL_10;
  p_m_Models = &this->m_Models;
  Inorder = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Models.m_Tree);
LABEL_8:
  *ppModel = this->m_Models.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem.modelpointer;
  result = (unsigned __int16)CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                               this: &p_m_Models->m_Tree,
                               i: Inorder);
  if ( (unsigned __int16)result == 0xFFFF )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EFC80
// Name: public: void CModelLoader::UnloadModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadModel(CModelLoader *this, model_t *pModel)
{
  KeyValues *m_pKeyValues; // ecx
  char szNameOnDisk[260]; // [esp+4h] [ebp-104h] BYREF

  switch ( pModel->type )
  {
    case mod_brush:
      CModelLoader::Map_UnloadModel(this, mod: pModel);
      g_pStringTableDictionary->OnBSPFullyUnloaded(this: g_pStringTableDictionary);
      if ( pModel->szPathName != szNameOnDisk )
        V_strncpy(pDest: szNameOnDisk, pSrc: pModel->szPathName, maxLen: 260);
      g_pFileSystem->RemoveSearchPath(this: g_pFileSystem, a2: szNameOnDisk, a3: "GAME");
      break;
    case mod_sprite:
      CModelLoader::Sprite_UnloadModel(this, mod: pModel);
      break;
    case mod_studio:
      CModelLoader::Studio_UnloadModel(this, pModel);
      break;
    default:
      break;
  }
  m_pKeyValues = pModel->m_pKeyValues;
  if ( m_pKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pKeyValues);
    pModel->m_pKeyValues = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFE20
// Name: public: CModelLoader::CModelLoader(void)
// Source: json
//------------------------------------------------------------------------------
CModelLoader *__thiscall CModelLoader::CModelLoader(CModelLoader *this)
{
  this->__vftable = (CModelLoader_vtbl *)&CModelLoader::`vftable';
  this->m_Models.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(void *const *, void *const *))CDmxSerializationDictionary::LessFunc;
  this->m_Models.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Models.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Models.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Models.m_Tree.m_pElements = this->m_Models.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Models.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Models.m_Tree.m_FirstFree = -1;
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_ModelPool,
    blockSize: 336,
    numElements: 1024,
    growMode: 1,
    pszAllocOwner: "CModelLoader::m_ModelPool",
    nAlignment: 0);
  this->m_InlineModels.m_Memory.m_pMemory = nullptr;
  this->m_InlineModels.m_Memory.m_nAllocationCount = 0;
  this->m_InlineModels.m_Memory.m_nGrowSize = 0;
  this->m_InlineModels.m_Size = 0;
  this->m_InlineModels.m_pElements = nullptr;
  this->m_LightStyleList.m_Memory.m_pMemory = nullptr;
  this->m_LightStyleList.m_Memory.m_nAllocationCount = 0;
  this->m_LightStyleList.m_Memory.m_nGrowSize = 0;
  this->m_LightStyleList.m_Size = 0;
  this->m_LightStyleList.m_pElements = nullptr;
  CMemoryStack::CMemoryStack(this: &this->m_WorldLightingDataStack);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EFEB0
// Name: void Mod_LoadSubmodels(class CUtlVector<struct mmodel_t,class CUtlMemory<struct mmodel_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Mod_LoadSubmodels(dmodel_t *a1@<ebp>, CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > *submodelList)
{
  unsigned int v2; // ecx
  signed int v3; // edi
  worldbrushdata_t *v4; // eax
  signed int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  mmodel_t *v9; // edi
  long double v10; // st7
  long double v11; // st6
  float v12; // xmm2_4
  long double v13; // st7
  long double v14; // st6
  float v15; // xmm1_4
  long double v16; // st7
  long double v17; // st6
  float v18; // xmm0_4
  float v19; // xmm1_4
  __int128 v20; // xmm0
  bool v21; // zf
  unsigned int v22; // [esp-Ch] [ebp-154h] BYREF
  _BYTE lh[300]; // [esp+0h] [ebp-148h] OVERLAPPED
  int v24; // [esp+12Ch] [ebp-1Ch]
  signed int v25; // [esp+130h] [ebp-18h]
  float v26; // [esp+134h] [ebp-14h]
  float v27; // [esp+138h] [ebp-10h]
  dmodel_t *in; // [esp+13Ch] [ebp-Ch]
  void *v29; // [esp+140h] [ebp-8h]
  void *retaddr; // [esp+148h] [ebp+0h]

  in = a1;
  v29 = retaddr;
  CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v22, lumpToLoad: 0xEu, bUncompress: true);
  v2 = v22;
  v25 = *(_DWORD *)&lh[4];
  if ( v22 % 0x30 != 0 )
  {
    Host_Error(error: "Mod_LoadSubmodels: funny lump size in %s", s_szMapPathName);
    v2 = v22;
  }
  v3 = v2 / 0x30;
  submodelList->m_Size = 0;
  CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int>>::InsertMultipleBefore(this: submodelList, elem: 0, num: v2 / 0x30);
  v4 = s_pMap;
  v5 = v25;
  s_pMap->numsubmodels = v3;
  v4->nWorldFaceCount = *(_DWORD *)(v5 + 44);
  if ( v3 > 0 )
  {
    v6 = 24;
    v7 = 0;
    v8 = v5 + 24;
    v24 = 24;
    v25 = v3;
    do
    {
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 24) = *(float *)(v8 - 24) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 12) = *(float *)(v8 - 12) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.x + v6) = *(float *)v8;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 20) = *(float *)(v8 - 20) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 8) = *(float *)(v8 - 8) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.y + v6) = *(float *)(v8 + 4);
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 16) = *(float *)(v8 - 16) - 1.0;
      *(float *)((char *)submodelList->m_Memory.m_pMemory + v6 - 4) = *(float *)(v8 - 4) + 1.0;
      *(float *)((char *)&submodelList->m_Memory.m_pMemory->mins.z + v6) = *(float *)(v8 + 8);
      v9 = &submodelList->m_Memory.m_pMemory[v7];
      v10 = fabs(v9->mins.x);
      v27 = v10;
      v11 = fabs(v9->maxs.x);
      v26 = v11;
      if ( v10 <= v11 )
        v12 = v26;
      else
        v12 = v27;
      v13 = fabs(v9->mins.y);
      v26 = v13;
      v14 = fabs(v9->maxs.y);
      v27 = v14;
      if ( v13 <= v14 )
        v15 = v27;
      else
        v15 = v26;
      v16 = fabs(v9->mins.z);
      v26 = v16;
      v17 = fabs(v9->maxs.z);
      v27 = v17;
      if ( v16 <= v17 )
        v18 = v27;
      else
        v18 = v26;
      v19 = (float)(v15 * v15) + (float)(v18 * v18);
      v20 = 0;
      *(float *)&v20 = fsqrt(v19 + (float)(v12 * v12));
      *(_OWORD *)&lh[284] = v20;
      LODWORD(v9->radius) = v20;
      submodelList->m_Memory.m_pMemory[v7].headnode = *(_DWORD *)(v8 + 12);
      submodelList->m_Memory.m_pMemory[v7].firstface = *(_DWORD *)(v8 + 16);
      submodelList->m_Memory.m_pMemory[v7].numfaces = *(_DWORD *)(v8 + 20);
      v6 = v24 + 52;
      ++v7;
      v8 += 48;
      v21 = v25-- == 1;
      v24 += 52;
    }
    while ( !v21 );
  }
  if ( *(_DWORD *)lh != 0 )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: *(void **)lh);
}

//------------------------------------------------------------------------------
// Address: 0x100F00F0
// Name: private: void CResourcePreloadModel::PurgeModels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeModels(CResourcePreloadModel *this, bool bPurgeAll)
{
  int v2; // esi
  int m_Size; // edi
  int v4; // ebx
  model_t *v5; // esi
  bool v6; // al
  int v7; // esi
  model_t **m_pMemory; // ecx
  model_t **v9; // eax
  int i; // esi
  CUtlVector<model_t *,CUtlMemory<model_t *,int> > firstList; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<model_t *,CUtlMemory<model_t *,int> > otherList; // [esp+20h] [ebp-20h] BYREF
  int iIndex; // [esp+34h] [ebp-Ch]
  model_t *pModel; // [esp+38h] [ebp-8h] BYREF
  bool bSpew; // [esp+3Fh] [ebp-1h]

  v2 = 0;
  bSpew = (g_pQueuedLoader->GetSpewDetail(this: g_pQueuedLoader) & 8) != 0;
  m_Size = 0;
  v4 = 0;
  memset(&firstList, 0, sizeof(firstList));
  memset(&otherList, 0, sizeof(otherList));
  iIndex = CModelLoader::FindNext(this: &g_ModelLoader, iIndex: -1, ppModel: &pModel);
  if ( iIndex != -1 )
  {
    do
    {
      v5 = pModel;
      if ( pModel == nullptr )
        break;
      if ( pModel->type == mod_studio )
      {
        v6 = bPurgeAll || (pModel->nLoadFlags & 0x8000) == 0;
        pModel->nLoadFlags &= ~0x8000u;
        if ( v6 )
        {
          if ( bSpew )
            _Msg(a1: "CResourcePreloadModel: Purging: %s\n", v5->szPathName);
          if ( g_pMDLCache->IsDataLoaded(this: g_pMDLCache, a2: v5->studio, a3: MDLCACHE_VIRTUALMODEL) )
          {
            v7 = m_Size;
            if ( m_Size + 1 > firstList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&firstList,
                num: m_Size - firstList.m_Memory.m_nAllocationCount + 1);
              m_Size = firstList.m_Size;
            }
            m_pMemory = firstList.m_Memory.m_pMemory;
            firstList.m_Size = ++m_Size;
            firstList.m_pElements = firstList.m_Memory.m_pMemory;
            if ( m_Size - v7 - 1 > 0 )
            {
              _V_memmove(
                dest: &firstList.m_Memory.m_pMemory[v7 + 1],
                src: &firstList.m_Memory.m_pMemory[v7],
                count: 4 * (m_Size - v7 - 1));
              m_pMemory = firstList.m_Memory.m_pMemory;
            }
          }
          else
          {
            v7 = v4;
            if ( v4 + 1 > otherList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&otherList,
                num: v4 - otherList.m_Memory.m_nAllocationCount + 1);
              v4 = otherList.m_Size;
            }
            m_pMemory = otherList.m_Memory.m_pMemory;
            otherList.m_Size = ++v4;
            otherList.m_pElements = otherList.m_Memory.m_pMemory;
            if ( v4 - v7 - 1 > 0 )
            {
              _V_memmove(
                dest: &otherList.m_Memory.m_pMemory[v7 + 1],
                src: &otherList.m_Memory.m_pMemory[v7],
                count: 4 * (v4 - v7 - 1));
              m_pMemory = otherList.m_Memory.m_pMemory;
            }
          }
          v9 = &m_pMemory[v7];
          if ( v9 != nullptr )
            *v9 = pModel;
        }
      }
      iIndex = CModelLoader::FindNext(this: &g_ModelLoader, iIndex, ppModel: &pModel);
    }
    while ( iIndex != -1 );
    v2 = 0;
  }
  if ( m_Size > 0 )
  {
    do
      CModelLoader::UnloadModel(this: &g_ModelLoader, pModel: firstList.m_Memory.m_pMemory[v2++]);
    while ( v2 < m_Size );
  }
  for ( i = 0; i < v4; ++i )
    CModelLoader::UnloadModel(this: &g_ModelLoader, pModel: otherList.m_Memory.m_pMemory[i]);
  if ( bPurgeAll || !g_pQueuedLoader->IsSameMapLoading(this: g_pQueuedLoader) )
    g_pMDLCache->Flush_2(this: g_pMDLCache, a2: MDLCACHE_FLUSH_ANIMBLOCK);
  if ( otherList.m_Memory.m_nGrowSize >= 0 && otherList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: otherList.m_Memory.m_pMemory);
  if ( firstList.m_Memory.m_nGrowSize >= 0 && firstList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: firstList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F0330
// Name: private: virtual void CResourcePreloadModel::PurgeUnreferencedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeUnreferencedResources(CResourcePreloadModel *this)
{
  CResourcePreloadModel::PurgeModels(this, bPurgeAll: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F0340
// Name: private: virtual void CResourcePreloadModel::PurgeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourcePreloadModel::PurgeAll(CResourcePreloadModel *this)
{
  CResourcePreloadModel::PurgeModels(this, bPurgeAll: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F0350
// Name: private: void CModelLoader::UnloadAllModels(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadAllModels(CModelLoader *this, bool bCheckReference)
{
  int v3; // esi
  model_t *modelpointer; // eax
  int c; // [esp+8h] [ebp-4h]

  v3 = 0;
  c = this->m_Models.m_Tree.m_NumElements;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    while ( 1 )
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( !bCheckReference )
        break;
      if ( (modelpointer->nLoadFlags & 0x7E) == 0 )
        goto LABEL_7;
      if ( modelpointer->type == mod_studio )
        g_pMDLCache->MarkAsLoaded(this: g_pMDLCache, a2: modelpointer->studio);
LABEL_9:
      if ( ++v3 >= c )
        return;
    }
    modelpointer->nLoadFlags &= 0xFFFFFF81;
LABEL_7:
    if ( (modelpointer->nLoadFlags & 0x10001) != 0 )
      CModelLoader::UnloadModel(this, pModel: modelpointer);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F03E0
// Name: public: virtual void CModelLoader::UnloadUnreferencedModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::UnloadUnreferencedModels(CModelLoader *this)
{
  CModelLoader::UnloadAllModels(this, bCheckReference: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F03F0
// Name: public: virtual void CModelLoader::PurgeUnusedModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::PurgeUnusedModels(CModelLoader *this)
{
  int ServerCount; // eax
  int m_NumElements; // ebx
  int v4; // esi
  model_t *modelpointer; // edx
  int nLoadFlags; // ecx
  int v7; // ebx
  int v8; // esi
  model_t *v9; // eax
  int v10; // ecx

  ServerCount = Host_GetServerCount();
  m_NumElements = this->m_Models.m_Tree.m_NumElements;
  v4 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v4].m_Data.elem.modelpointer;
      nLoadFlags = modelpointer->nLoadFlags;
      if ( (nLoadFlags & 1) != 0 && modelpointer->nServerCount != ServerCount )
        modelpointer->nLoadFlags = nLoadFlags & 0xFFFFFF81;
      ++v4;
    }
    while ( v4 < m_NumElements );
  }
  v7 = this->m_Models.m_Tree.m_NumElements;
  v8 = 0;
  if ( this->m_Models.m_Tree.m_NumElements != 0 )
  {
    do
    {
      v9 = this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.modelpointer;
      v10 = v9->nLoadFlags;
      if ( (v10 & 0x7E) != 0 )
      {
        if ( v9->type == mod_studio )
          g_pMDLCache->MarkAsLoaded(this: g_pMDLCache, a2: v9->studio);
      }
      else if ( (v10 & 0x10001) != 0 )
      {
        CModelLoader::UnloadModel(
          this,
          pModel: this->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v8].m_Data.elem.modelpointer);
      }
      ++v8;
    }
    while ( v8 < v7 );
  }
  materials->UncacheUnusedMaterials(this: materials, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100F04B0
// Name: private: void CModelLoader::SetupSubModels(struct model_t __near *,class CUtlVector<struct mmodel_t,class CUtlMemory<struct mmodel_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::SetupSubModels(
        CModelLoader *this,
        model_t *mod,
        CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > *list)
{
  int v4; // ebx
  CUtlVector<model_t,CUtlMemory<model_t,int> > *p_m_InlineModels; // ecx
  mmodel_t *v6; // edi
  model_t *v7; // esi
  int headnode_low; // ecx
  int numsubmodels; // [esp-4h] [ebp-10h]
  CModelLoader *v10; // [esp+8h] [ebp-4h]

  v4 = 0;
  numsubmodels = this->m_worldBrushData.numsubmodels;
  p_m_InlineModels = &this->m_InlineModels;
  v10 = this;
  p_m_InlineModels->m_Size = 0;
  CUtlVector<model_t,CUtlMemory<model_t,int>>::InsertMultipleBefore(this: p_m_InlineModels, elem: 0, num: numsubmodels);
  if ( this->m_worldBrushData.numsubmodels > 0 )
  {
    do
    {
      v6 = &list->m_Memory.m_pMemory[v4];
      v7 = &v10->m_InlineModels.m_Memory.m_pMemory[v4];
      model_t::operator=(this: v7, __that: mod);
      v7->brush.firstmodelsurface = v6->firstface;
      v7->brush.nummodelsurfaces = v6->numfaces;
      headnode_low = LOWORD(v6->headnode);
      v7->brush.firstnode = headnode_low;
      if ( headnode_low >= v10->m_worldBrushData.numnodes )
        Sys_Error(error: "Inline model %i has bad firstnode", v4);
      v7->maxs.x = v6->maxs.x;
      v7->maxs.y = v6->maxs.y;
      v7->maxs.z = v6->maxs.z;
      v7->mins.x = v6->mins.x;
      v7->mins.y = v6->mins.y;
      v7->mins.z = v6->mins.z;
      v7->radius = v6->radius;
      if ( v4 != 0 )
      {
        V_snprintf(pDest: v7->szPathName, maxLen: 260, pFormat: "*%d", v4);
        v7->fnHandle = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: v7->szPathName);
      }
      else
      {
        model_t::operator=(this: mod, __that: v7);
      }
      ++v4;
    }
    while ( v4 < v10->m_worldBrushData.numsubmodels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F05C0
// Name: public: void CModelLoader::DumpVCollideStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::DumpVCollideStats(CModelLoader *this)
{
  CModelLoader *v1; // ebx
  bool v2; // sf
  int v3; // edi
  model_t *modelpointer; // esi
  int studio; // eax
  int v6; // edi
  int v7; // ecx
  vcollide_t *v8; // esi
  int v9; // ebx
  int v10; // edi
  int v11; // ebx
  int m_Size; // esi
  int v13; // edi
  int *p_size; // esi
  CUtlSortVector<modelsize_t,CModelsize_Less> list; // [esp+Ch] [ebp-3Ch] BYREF
  modelsize_t src; // [esp+28h] [ebp-20h] BYREF
  int bboxCount; // [esp+30h] [ebp-18h] BYREF
  int bboxSize; // [esp+34h] [ebp-14h] BYREF
  int size; // [esp+38h] [ebp-10h] BYREF
  CModelLoader *v20; // [esp+3Ch] [ebp-Ch]
  modelsize_t elem; // [esp+40h] [ebp-8h] BYREF

  v1 = this;
  v3 = this->m_Models.m_Tree.m_NumElements - 1;
  v2 = this->m_Models.m_Tree.m_NumElements == 0;
  v20 = this;
  memset(&list, 0, 25);
  if ( !v2 )
  {
    do
    {
      modelpointer = v1->m_Models.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v3].m_Data.elem.modelpointer;
      if ( modelpointer != nullptr && modelpointer->type == mod_studio )
      {
        studio = modelpointer->studio;
        size = 0;
        if ( g_pMDLCache->GetVCollideSize(this: g_pMDLCache, a2: studio, a3: &size) && size != 0 )
        {
          elem.size = size;
          elem.pName = modelpointer->szPathName;
          CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(this: &list, src: &elem);
        }
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
  v6 = v1->m_InlineModels.m_Size - 1;
  size = v6;
  if ( v6 >= 0 )
  {
    v7 = 336 * v6;
    for ( elem.size = 336 * v6; ; v7 = elem.size )
    {
      v8 = CM_VCollideForModel(
             modelindex: v6 + 1,
             pModel: (const model_t *)((char *)v1->m_InlineModels.m_Memory.m_pMemory + v7));
      if ( v8 != nullptr )
      {
        v9 = 0;
        v10 = 0;
        if ( (*(_WORD *)v8 & 0x7FFF) != 0 )
        {
          do
            v9 += physcollision->CollideSize(this: physcollision, a2: v8->solids[v10++]);
          while ( v10 < (*(_WORD *)v8 & 0x7FFF) );
        }
        v11 = v8->descSize + v9;
        if ( v11 != 0 )
        {
          src.pName = &v20->m_InlineModels.m_Memory.m_pMemory->szPathName[elem.size];
          src.size = v11;
          CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(this: &list, &src);
        }
        v6 = size;
        v1 = v20;
      }
      elem.size -= 336;
      size = --v6;
      if ( v6 < 0 )
        break;
    }
  }
  m_Size = list.m_Size;
  _Msg(a1: "VCollides loaded: %d\n", list.m_Size);
  v13 = 0;
  if ( m_Size > 0 )
  {
    p_size = &list.m_Memory.m_pMemory->size;
    size = list.m_Size;
    do
    {
      _Msg(a1: "%8d bytes:%s\n", *p_size, (const char *)*(p_size - 1));
      v13 += *p_size;
      p_size += 2;
      --size;
    }
    while ( size != 0 );
  }
  physcollision->GetBBoxCacheSize(this: physcollision, a2: &bboxSize, a3: &bboxCount);
  _Msg(a1: "%8d bytes BBox physics: %d boxes\n", bboxSize, bboxCount);
  _Msg(a1: "--------------\n%8d bytes total VCollide Memory\n", v13 + bboxSize);
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F07B0
// Name: vx_model_list
// Source: json
//------------------------------------------------------------------------------
void __cdecl vx_model_list()
{
  int (__thiscall *GetCount)(IModelLoader *); // edx
  int v1; // esi
  int v2; // eax
  int v3; // edi
  model_t *(__thiscall *GetModelForIndex)(IModelLoader *, int); // edx
  const char *v5; // ebx
  int v6; // eax
  model_t *v7; // edi
  studiohwdata_t *v8; // eax
  studiohwdata_t *v9; // esi
  int m_NumLODs; // edx
  _DWORD *v11; // eax
  xModelList_t *v12; // eax
  xModelList_t *v13; // edi
  const char *v14; // ecx
  int v15; // edi
  char v16; // dl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  const char *v25; // eax
  void *v26; // ebx
  int *p_numLODs; // esi
  char csvFileName[260]; // [esp+Ch] [ebp-148h] BYREF
  CUtlVector<xModelList_t,CUtlMemory<xModelList_t,int> > modelList; // [esp+110h] [ebp-44h] BYREF
  int numVerts; // [esp+124h] [ebp-30h] BYREF
  xModelList_t *m_pMemory; // [esp+128h] [ebp-2Ch]
  int numMeshes; // [esp+12Ch] [ebp-28h]
  int numVertsLod0; // [esp+130h] [ebp-24h] BYREF
  int numLODs; // [esp+134h] [ebp-20h]
  int nTriCount; // [esp+138h] [ebp-1Ch] BYREF
  int numParts; // [esp+13Ch] [ebp-18h]
  int dataSize; // [esp+140h] [ebp-14h]
  int nTriCountLod0; // [esp+144h] [ebp-10h] BYREF
  int dataSizeLod0; // [esp+148h] [ebp-Ch]
  int numActualModels; // [esp+14Ch] [ebp-8h]
  int i; // [esp+150h] [ebp-4h]

  GetCount = modelloader->GetCount;
  v1 = 0;
  memset(&modelList, 0, sizeof(modelList));
  v2 = GetCount(this: modelloader);
  CUtlVector<xModelList_t,CUtlMemory<xModelList_t,int>>::InsertMultipleBefore(this: &modelList, elem: 0, num: v2);
  v3 = 0;
  numActualModels = 0;
  i = 0;
  if ( modelList.m_Size > 0 )
  {
    m_pMemory = modelList.m_Memory.m_pMemory;
    while ( 1 )
    {
      GetModelForIndex = modelloader->GetModelForIndex;
      v5 = "Unknown";
      dataSizeLod0 = 0;
      dataSize = 0;
      numParts = 0;
      numVertsLod0 = 0;
      numVerts = 0;
      numLODs = 0;
      numMeshes = 0;
      nTriCount = 0;
      nTriCountLod0 = 0;
      v6 = (int)GetModelForIndex(this: modelloader, a2: i);
      v7 = (model_t *)v6;
      if ( v6 == 0 )
        goto LABEL_8;
      if ( *(_DWORD *)(v6 + 272) == 3 )
        break;
LABEL_11:
      v1 = 0;
      if ( ++i >= modelList.m_Size )
      {
        v3 = numActualModels;
        goto LABEL_13;
      }
    }
    v5 = (const char *)(v6 + 4);
    v8 = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: *(unsigned __int16 *)(v6 + 312));
    v9 = v8;
    if ( v8 != nullptr )
    {
      m_NumLODs = v8->m_NumLODs;
      numMeshes = v8->m_NumStudioMeshes;
      numLODs = m_NumLODs;
      dataSize = ComputeSize(hwData: v8, &numVerts, pTriCount: &nTriCount, onlyTopLod: false);
      dataSizeLod0 = ComputeSize(hwData: v9, numVerts: &numVertsLod0, pTriCount: &nTriCountLod0, onlyTopLod: true);
    }
    v11 = modelloader->GetExtraData(this: modelloader, a2: v7);
    v1 = v11[39];
    numParts = v11[58];
LABEL_8:
    ++numActualModels;
    v12 = m_pMemory;
    v13 = m_pMemory++;
    v14 = v5;
    v15 = (char *)v13 - v5;
    do
    {
      v16 = *v14;
      v14[v15] = *v14;
      ++v14;
    }
    while ( v16 != 0 );
    v17 = numVerts;
    v12->dataSize = dataSize;
    v18 = nTriCount;
    v12->numVertices = v17;
    v19 = dataSizeLod0;
    v12->triCount = v18;
    v20 = numVertsLod0;
    v12->dataSizeLod0 = v19;
    v21 = nTriCountLod0;
    v12->numVerticesLod0 = v20;
    v22 = numParts;
    v12->triCountLod0 = v21;
    v23 = numLODs;
    v12->numParts = v22;
    v24 = numMeshes;
    v12->numBones = v1;
    v12->numLODs = v23;
    v12->numMeshes = v24;
    goto LABEL_11;
  }
LABEL_13:
  v25 = engineClient->GetLevelNameShort(this: engineClient);
  V_snprintf(pDest: csvFileName, maxLen: 260, pFormat: "modellist_%s.csv", v25);
  _Msg(a1: "Writing model list to %s...\n", csvFileName);
  v26 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: csvFileName, a3: "w", a4: 0);
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: v26,
    a3: "Model,DataSize,Tris,Verts,DataSize (LOD0),Tris (LOD0),Verts (LOD0),Parts,Bones,LODs,Meshes\n");
  if ( v3 > 0 )
  {
    p_numLODs = &modelList.m_Memory.m_pMemory->numLODs;
    do
    {
      g_pFullFileSystem->FPrintf(
        this: g_pFullFileSystem,
        a2: v26,
        a3: "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        p_numLODs - 73,
        *(p_numLODs - 8),
        *(p_numLODs - 6),
        *(p_numLODs - 7),
        *(p_numLODs - 5),
        *(p_numLODs - 3),
        *(p_numLODs - 4),
        *(p_numLODs - 1),
        *(p_numLODs - 2),
        *p_numLODs,
        p_numLODs[1]);
      p_numLODs += 75;
      --v3;
    }
    while ( v3 != 0 );
  }
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v26);
  if ( modelList.m_Memory.m_nGrowSize >= 0 && modelList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: modelList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100F0AC0
// Name: mem_vcollide
// Source: json
//------------------------------------------------------------------------------
void __cdecl mem_vcollide()
{
  CModelLoader::DumpVCollideStats(this: &g_ModelLoader);
}

//------------------------------------------------------------------------------
// Address: 0x100F0AD0
// Name: public: virtual void CModelLoader::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Shutdown(CModelLoader *this)
{
  this->m_pWorldModel = nullptr;
  CModelLoader::UnloadAllModels(this, bCheckReference: false);
  CUtlMemoryPool::Clear(this: &this->m_ModelPool);
}

//------------------------------------------------------------------------------
// Address: 0x100F0AF0
// Name: public: struct model_t __near * CModelLoader::FindModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::FindModel(CModelLoader *this, const char *pName)
{
  int v4; // eax
  int v5; // edi
  int numsubmodels; // eax
  void *v8; // edi
  unsigned __int16 v9; // ax
  model_t *modelpointer; // esi
  CMapReslistGenerator *v11; // eax
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short> *pNamea; // [esp+1Ch] [ebp+8h]

  if ( pName == nullptr || *pName == 0 )
    Sys_Error(error: "CModelLoader::FindModel: NULL name");
  if ( *pName == 42 )
  {
    v4 = atoi(nptr: pName + 1);
    v5 = v4;
    if ( this->m_pWorldModel == nullptr )
      Sys_Error(error: "bad inline model number %i, worldmodel not yet setup", v4);
    if ( v5 < 1
      || (this->m_pWorldModel != nullptr ? (numsubmodels = this->m_worldBrushData.numsubmodels) : (numsubmodels = 0),
          v5 >= numsubmodels) )
    {
      Sys_Error(error: "bad inline model number %i", v5);
    }
    return &this->m_InlineModels.m_Memory.m_pMemory[v5];
  }
  else
  {
    v8 = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pName);
    search.key = v8;
    pNamea = &this->m_Models;
    v9 = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Models.m_Tree,
           &search);
    if ( v9 == 0xFFFF )
    {
      modelpointer = (model_t *)CUtlMemoryPool::Alloc(this: &this->m_ModelPool);
      memset(dst: (unsigned __int8 *)modelpointer, value: 0, count: sizeof(model_t));
      modelpointer->fnHandle = v8;
      modelpointer->nLoadFlags = 0;
      V_strncpy(pDest: modelpointer->szPathName, pSrc: pName, maxLen: 260);
      V_RemoveDotSlashes(pFilename: modelpointer->szPathName, separator: 47);
      search.key = v8;
      search.elem.modelpointer = modelpointer;
      CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
        this: &pNamea->m_Tree,
        insert: &search);
    }
    else
    {
      modelpointer = this->m_Models.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem.modelpointer;
    }
    v11 = MapReslistGenerator();
    CMapReslistGenerator::OnModelPrecached(this: v11, relativePathFileName: pName);
    return modelpointer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0C20
// Name: public: virtual struct model_t __near * CModelLoader::GetModelForName(char const __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::GetModelForName(
        CModelLoader *this,
        const char *name,
        IModelLoader::REFERENCETYPE referencetype)
{
  model_t *Model; // eax

  Model = CModelLoader::FindModel(this, pName: name);
  return CModelLoader::LoadModel(this, mod: Model, pReferencetype: &referencetype);
}

//------------------------------------------------------------------------------
// Address: 0x100F0C40
// Name: public: virtual struct model_t __near * CModelLoader::ReferenceModel(char const __near *,enum IModelLoader::REFERENCETYPE)
// Source: json
//------------------------------------------------------------------------------
model_t *__thiscall CModelLoader::ReferenceModel(
        CModelLoader *this,
        const char *name,
        IModelLoader::REFERENCETYPE referencetype)
{
  model_t *result; // eax

  result = CModelLoader::FindModel(this, pName: name);
  result->nLoadFlags |= referencetype;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0C60
// Name: public: virtual int CModelLoader::GetModelFileSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelLoader::GetModelFileSize(CModelLoader *this, const char *name)
{
  char *szPathName; // esi
  const char *v4; // eax
  char spritename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( name == nullptr || *name == 0 )
    return -1;
  szPathName = CModelLoader::FindModel(this, pName: name)->szPathName;
  if ( V_stristr(pStr: szPathName, pSearch: ".spr") == nullptr
    && V_stristr(pStr: szPathName, pSearch: ".vmt") == nullptr )
  {
    return COM_FileSize(filename: name);
  }
  v4 = va(format: "materials/%s", szPathName);
  V_StripExtension(in: v4, out: spritename, outSize: 260);
  V_DefaultExtension(path: spritename, extension: ".vmt", pathStringLength: 260);
  return COM_FileSize(filename: spritename);
}

//------------------------------------------------------------------------------
// Address: 0x100F0D20
// Name: void Mod_LoadSimpleWorldModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Mod_LoadSimpleWorldModel(const char *pMapBaseName)
{
  model_t *Model; // eax
  model_t *v2; // eax
  char modelPathWater[260]; // [esp+4h] [ebp-20Ch] BYREF
  char modelPath[260]; // [esp+108h] [ebp-108h] BYREF
  IModelLoader::REFERENCETYPE pReferencetype; // [esp+20Ch] [ebp-4h] BYREF

  V_stristr(pStr: pMapBaseName, pSearch: "mp_coop_");
  V_snprintf(pDest: modelPath, maxLen: 260, pFormat: "models/maps/%s/simpleworldmodel.mdl", pMapBaseName);
  V_snprintf(pDest: modelPathWater, maxLen: 260, pFormat: "models/maps/%s/simpleworldmodel_water.mdl", pMapBaseName);
  pReferencetype = FMODELLOADER_SIMPLEWORLD;
  Model = CModelLoader::FindModel(this: &g_ModelLoader, pName: modelPath);
  g_pSimpleWorldModel = CModelLoader::LoadModel(this: &g_ModelLoader, mod: Model, &pReferencetype);
  pReferencetype = FMODELLOADER_SIMPLEWORLD;
  v2 = CModelLoader::FindModel(this: &g_ModelLoader, pName: modelPathWater);
  g_pSimpleWorldModelWater = CModelLoader::LoadModel(this: &g_ModelLoader, mod: v2, &pReferencetype);
  if ( g_pSimpleWorldModel == nullptr )
    _Warning(
      a1: "\n"
      "\n"
      "###########################################\n"
      "## !!FAILED TO LOAD SIMPLE WORLD MODEL!! ##\n"
      "##        (perf will be terrible)        ##\n"
      "##           (image is broken)           ##\n"
      "###########################################\n"
      "\n"
      "\n");
}

//------------------------------------------------------------------------------
// Address: 0x100F0DE0
// Name: private: virtual bool CResourcePreloadModel::CreateResource(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourcePreloadModel::CreateResource(CResourcePreloadModel *this, char *pName)
{
  int TypeFromName; // eax
  unsigned __int16 v3; // ax
  model_t *modelpointer; // edi
  char *szPathName; // ebx
  int lumpOffset; // esi
  const char *v7; // esi
  model_t *Model; // esi
  int nLoadFlags; // eax
  int v11; // eax
  char szFilename[260]; // [esp+8h] [ebp-260h] BYREF
  char szNameOnDisk[260]; // [esp+10Ch] [ebp-15Ch] BYREF
  CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t search; // [esp+210h] [ebp-58h] BYREF
  LoaderJob_t loaderJobAIN; // [esp+218h] [ebp-50h] BYREF
  LoaderJob_t loaderJobBSP; // [esp+240h] [ebp-28h] BYREF

  TypeFromName = CModelLoader::GetTypeFromName(this: &g_ModelLoader, pModelName: pName);
  if ( TypeFromName == 1 )
  {
    search.key = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: pName);
    v3 = CUtlRBTree<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<void *,CModelLoader::ModelEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &g_ModelLoader.m_Models.m_Tree,
           &search);
    if ( v3 != 0xFFFF )
    {
      modelpointer = g_ModelLoader.m_Models.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.modelpointer;
      if ( modelpointer != nullptr )
      {
        szPathName = modelpointer->szPathName;
        CMapLoadHelper::Init(
          a1: (int)modelpointer->szPathName,
          a2: (int)modelpointer,
          p_lumpHeader: (lumpfileheader_t *)pName,
          pMapModel: modelpointer,
          pPathName: modelpointer->szPathName);
        lumpOffset = s_MapLumpFiles[40].header.lumpOffset;
        if ( s_MapLumpFiles[40].file == nullptr )
          lumpOffset = s_MapHeader.lumps[40].fileofs;
        CMapLoadHelper::Shutdown();
        if ( szPathName != szNameOnDisk )
          V_strncpy(pDest: szNameOnDisk, pSrc: modelpointer->szPathName, maxLen: 260);
        memset(&loaderJobBSP.m_pContext2, 0, 24);
        loaderJobBSP.m_pFilename = szNameOnDisk;
        loaderJobBSP.m_pPathID = "GAME";
        loaderJobBSP.m_pCallback = CResourcePreloadModel::QueuedLoaderMapCallback;
        loaderJobBSP.m_pContext = modelpointer;
        loaderJobBSP.m_pTargetData = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: lumpOffset);
        loaderJobBSP.m_nBytesToRead = lumpOffset;
        loaderJobBSP.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
        g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJobBSP);
        v7 = V_UnqualifiedFileName(in: com_gamedir);
        if ( StringAfterPrefix(str: v7, prefix: "portal2") == nullptr
          && StringAfterPrefix(str: v7, prefix: "left4dead") == nullptr )
        {
          V_FileBase(in: szPathName, out: szFilename, maxlen: 260);
          V_snprintf(pDest: szNameOnDisk, maxLen: 260, pFormat: "maps/graphs/%s.ain", szFilename);
          memset(&loaderJobAIN.m_pCallback, 0, 24);
          *(_DWORD *)&loaderJobAIN.m_bPersistTargetData = 0;
          loaderJobAIN.m_pFilename = szNameOnDisk;
          loaderJobAIN.m_pPathID = "GAME";
          loaderJobAIN.m_Priority = LOADERPRIORITY_DURINGPRELOAD;
          g_pQueuedLoader->AddJob(this: g_pQueuedLoader, a2: &loaderJobAIN);
        }
        return 1;
      }
    }
    return 0;
  }
  if ( TypeFromName != 3 )
    return 0;
  V_ComposeFileName(path: "models", filename: pName, dest: szFilename, destSize: 260);
  Model = CModelLoader::FindModel(this: &g_ModelLoader, pName: szFilename);
  Model->nLoadFlags |= 0x8000u;
  nLoadFlags = Model->nLoadFlags;
  if ( (nLoadFlags & 0x10001) == 0 )
  {
    Model->nLoadFlags = nLoadFlags | 0x10000;
    Model->type = mod_studio;
    v11 = ((int (__thiscall *)(IMDLCache *, char *))g_pMDLCache->FindMDL)(a1: g_pMDLCache, a2: Model->szPathName);
    Model->studio = v11;
    g_pMDLCache->SetUserData(this: g_pMDLCache, a2: v11, a3: Model);
    ((void (__stdcall *)(_DWORD))g_pMDLCache->PreloadModel)(a1: Model->studio);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1060
// Name: private: void CModelLoader::Map_LoadModelGuts(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelLoader::Map_LoadModelGuts(CModelLoader *this, model_t *mod)
{
  unsigned int m_nLumpSize; // ecx
  worldbrushdata_t *v5; // eax
  worldbrushdata_t *v6; // eax
  IEngineVGuiInternal *v7; // eax
  int lumpLength; // eax
  IEngineVGuiInternal *v9; // eax
  IEngineVGuiInternal *v10; // eax
  IOverlayMgr *v11; // eax
  IEngineVGuiInternal *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  int filelen; // eax
  IEngineVGuiInternal *v17; // eax
  IEngineVGuiInternal *v18; // eax
  IEngineVGuiInternal *v19; // eax
  CMapLoadHelper mlh; // [esp+Ch] [ebp-270h] BYREF
  CMapLoadHelper lhTexinfo; // [esp+134h] [ebp-148h] BYREF
  unsigned int checksum; // [esp+25Ch] [ebp-20h] BYREF
  CUtlVector<mmodel_t,CUtlMemory<mmodel_t,int> > submodelList; // [esp+260h] [ebp-1Ch] BYREF
  int texinfoCount; // [esp+274h] [ebp-8h]
  texinfo_s *pTexinfo; // [esp+278h] [ebp-4h]
  int savedregs; // [esp+27Ch] [ebp+0h] BYREF
  char *bLoadHDR; // [esp+284h] [ebp+8h]
  medge_t *bLoadHDRb; // [esp+284h] [ebp+8h]
  bool bLoadHDRa; // [esp+284h] [ebp+8h]

  ++g_nMapLoadCount;
  _COM_TimestampedLog(a1: "  Map_CheckForHDR");
  bLoadHDR = mod->szPathName;
  this->m_bMapHasHDRLighting = Map_CheckForHDR(
                                 a1: (int)mod,
                                 a2: (int)this,
                                 a3: (lumpfileheader_t *)_COM_TimestampedLog,
                                 pModel: mod,
                                 pMapPathName: bLoadHDR);
  CMapLoadHelper::CMapLoadHelper(this: &lhTexinfo, lumpToLoad: 6u, bUncompress: true);
  m_nLumpSize = lhTexinfo.m_nLumpSize;
  pTexinfo = (texinfo_s *)lhTexinfo.m_pData;
  if ( lhTexinfo.m_nLumpSize % 0x48u != 0 )
  {
    Host_Error(error: "Map_LoadModelGuts: bad LUMP_TEXINFO size in %s", bLoadHDR);
    m_nLumpSize = lhTexinfo.m_nLumpSize;
  }
  texinfoCount = m_nLumpSize / 0x48;
  if ( m_nLumpSize / 0x48 != 0 )
  {
    if ( (int)(m_nLumpSize / 0x48) > 12288 )
      Sys_Error(error: "Map_LoadModelGuts: Map has too many surfaces, %s", bLoadHDR);
    _COM_TimestampedLog(a1: "  CM_LoadMap");
    CM_LoadMap(pPathName: bLoadHDR, allowReusePrevious: false, pTexinfo, texinfoCount, &checksum);
    _COM_TimestampedLog(a1: "  Mod_LoadVertices");
    Mod_LoadVertices();
    _COM_TimestampedLog(a1: "  Mod_LoadEdges");
    bLoadHDRb = Mod_LoadEdges();
    _COM_TimestampedLog(a1: "  Mod_LoadSurfedges");
    Mod_LoadSurfedges(pedges: bLoadHDRb);
    _COM_TimestampedLog(a1: "  Mod_LoadPlanes");
    v5 = s_pMap;
    s_pMap->planes = g_BSPData.map_planes.m_pArray;
    v5->numplanes = g_BSPData.numplanes;
    _COM_TimestampedLog(a1: "  Mod_LoadOcclusion");
    Mod_LoadOcclusion();
    _COM_TimestampedLog(a1: "  Mod_LoadTexdata");
    v6 = s_pMap;
    s_pMap->numtexdata = g_BSPData.numtextures;
    v6->texdata = g_BSPData.map_surfaces.m_pArray;
    _COM_TimestampedLog(a1: "  Mod_LoadTexinfo");
    Mod_LoadTexinfo(lh: &lhTexinfo);
    v7 = EngineVGui();
    v7->UpdateProgressBar(this: v7, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadLighting");
    if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
      goto LABEL_12;
    lumpLength = s_MapLumpFiles[53].header.lumpLength;
    if ( s_MapLumpFiles[53].file == nullptr )
      lumpLength = s_MapHeader.lumps[53].filelen;
    bLoadHDRa = true;
    if ( lumpLength <= 0 )
LABEL_12:
      bLoadHDRa = false;
    Mod_LoadLighting(bLoadHDR: bLoadHDRa);
    _COM_TimestampedLog(a1: "  Mod_LoadPrimitives");
    Mod_LoadPrimitives();
    _COM_TimestampedLog(a1: "  Mod_LoadPrimVerts");
    Mod_LoadPrimVerts();
    _COM_TimestampedLog(a1: "  Mod_LoadPrimIndices");
    Mod_LoadPrimIndices();
    v9 = EngineVGui();
    v9->UpdateProgressBar(this: v9, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadFaces");
    Mod_LoadFaces();
    Mod_LoadFaceBrushes();
    _COM_TimestampedLog(a1: "  Mod_LoadVertNormals");
    Mod_LoadVertNormals();
    _COM_TimestampedLog(a1: "  Mod_LoadVertNormalIndices");
    Mod_LoadVertNormalIndices();
    v10 = EngineVGui();
    v10->UpdateProgressBar(this: v10, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Mod_LoadLeafs");
    Mod_LoadLeafs();
    _COM_TimestampedLog(a1: "  Mod_LoadMarksurfaces");
    Mod_LoadMarksurfaces();
    _COM_TimestampedLog(a1: "  Mod_LoadNodes");
    Mod_LoadNodes();
    _COM_TimestampedLog(a1: "  Mod_LoadLeafWaterData");
    Mod_LoadLeafWaterData();
    _COM_TimestampedLog(a1: "  OverlayMgr()->LoadOverlays");
    v11 = OverlayMgr();
    v11->LoadOverlays(this: v11);
    _COM_TimestampedLog(a1: "  Mod_LoadLeafMinDistToWater");
    Mod_LoadLeafMinDistToWater();
    v12 = EngineVGui();
    v12->UpdateProgressBar(this: v12, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  LUMP_CLIPPORTALVERTS");
    v13 = va(format: "%s [%s]", this->m_szBaseName, "clipportalverts");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 0x29u,
      loadname: v13,
      elementSize: 12,
      ppData: (void **)&this->m_worldBrushData.m_pClipPortalVerts,
      nElements: &this->m_worldBrushData.m_nClipPortalVerts);
    _COM_TimestampedLog(a1: "  LUMP_AREAPORTALS");
    v14 = va(format: "%s [%s]", this->m_szBaseName, "areaportals");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 0x15u,
      loadname: v14,
      elementSize: 12,
      ppData: (void **)&this->m_worldBrushData.m_pAreaPortals,
      nElements: &this->m_worldBrushData.m_nAreaPortals);
    _COM_TimestampedLog(a1: "  LUMP_AREAS");
    v15 = va(format: "%s [%s]", this->m_szBaseName, "areas");
    Mod_LoadLump(
      loadmodel: mod,
      iLump: 0x14u,
      loadname: v15,
      elementSize: 8,
      ppData: (void **)&this->m_worldBrushData.m_pAreas,
      nElements: &this->m_worldBrushData.m_nAreas);
    _COM_TimestampedLog(a1: "  Mod_LoadWorldlights");
    if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE )
      goto LABEL_18;
    filelen = s_MapLumpFiles[54].header.lumpLength;
    if ( s_MapLumpFiles[54].file == nullptr )
      filelen = s_MapHeader.lumps[54].filelen;
    if ( filelen > 0 )
    {
      CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0x36u, bUncompress: true);
      Mod_LoadWorldlights(lh: &mlh, bIsHDR: true);
    }
    else
    {
LABEL_18:
      CMapLoadHelper::CMapLoadHelper(this: &mlh, lumpToLoad: 0xFu, bUncompress: true);
      Mod_LoadWorldlights(lh: &mlh, bIsHDR: false);
    }
    if ( mlh.m_pRawData != nullptr )
      g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: mlh.m_pRawData);
    _COM_TimestampedLog(a1: "  Mod_LoadCubemapSamples");
    Mod_LoadCubemapSamples(a1: (int)this);
    _COM_TimestampedLog(a1: "  Mod_LoadSimpleWorldModel");
    Mod_LoadSimpleWorldModel(pMapBaseName: this->m_szBaseName);
    _COM_TimestampedLog(a1: "  Mod_LoadGameLumpDict");
    Mod_LoadGameLumpDict();
    v17 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, int))v17->UpdateProgressBar)(a1: v17, a2: 3);
    _COM_TimestampedLog(a1: "  Mod_LoadSubmodels");
    memset(&submodelList, 0, sizeof(submodelList));
    Mod_LoadSubmodels(a1: (dmodel_t *)&savedregs, &submodelList);
    v18 = EngineVGui();
    v18->UpdateProgressBar(this: v18, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  SetupSubModels");
    CModelLoader::SetupSubModels(this, mod, list: &submodelList);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&submodelList);
    _COM_TimestampedLog(a1: "  RecomputeSurfaceFlags");
    this->RecomputeSurfaceFlags(this, a2: mod);
    v19 = EngineVGui();
    v19->UpdateProgressBar(this: v19, a2: PROGRESS_LOADWORLDMODEL, a3: true);
    _COM_TimestampedLog(a1: "  Map_VisClear");
    Map_VisClear();
    _COM_TimestampedLog(a1: "  Map_SetRenderInfoAllocated");
    this->Map_SetRenderInfoAllocated(this, a2: false);
  }
  else if ( !g_bClearingClientState )
  {
    Sys_Error(error: "Map_LoadModelGuts: Map with no texinfo, %s", bLoadHDR);
  }
  if ( lhTexinfo.m_pRawData != nullptr )
    g_pFileSystem->FreeOptimalReadBuffer(this: g_pFileSystem, a2: lhTexinfo.m_pRawData);
}

//------------------------------------------------------------------------------
// Address: 0x10316300
// Name: _dynamic_initializer_for__mod_touchalldata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_touchalldata__()
{
  ConVar::ConVar(
    this: &mod_touchalldata,
    pName: "mod_touchalldata",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Touch model data during level startup");
  return atexit(func: dynamic_atexit_destructor_for__mod_touchalldata__);
}

//------------------------------------------------------------------------------
// Address: 0x10316330
// Name: _dynamic_initializer_for__mod_forcetouchdata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_forcetouchdata__()
{
  ConVar::ConVar(
    this: &mod_forcetouchdata,
    pName: "mod_forcetouchdata",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Forces all model file data into cache on model load.");
  return atexit(func: dynamic_atexit_destructor_for__mod_forcetouchdata__);
}

//------------------------------------------------------------------------------
// Address: 0x10316460
// Name: lump_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *lump_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<lump_t>();
  lump_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10316470
// Name: BSPHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *BSPHeader_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<BSPHeader_t>();
  BSPHeader_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031BF60
// Name: _dynamic_initializer_for__load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__load_command__()
{
  ConCommand::ConCommand(
    this: &load_command,
    pName: "load",
    callback: (void (__cdecl *)())Host_Loadgame_f,
    pHelpString: "Load a saved game.",
    flags: 0,
    completionFunc: g_load_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DBC0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DBF0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x10323A70
// Name: _dynamic_atexit_destructor_for__mod_touchalldata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_touchalldata__()
{
  ConVar::~ConVar(this: &mod_touchalldata);
}

//------------------------------------------------------------------------------
// Address: 0x10323A80
// Name: _dynamic_atexit_destructor_for__mod_forcetouchdata__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_forcetouchdata__()
{
  ConVar::~ConVar(this: &mod_forcetouchdata);
}

//------------------------------------------------------------------------------
// Address: 0x10325E50
// Name: _dynamic_atexit_destructor_for__load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__load_command__()
{
  ConCommand::~ConCommand(this: &load_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326A10
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x10326A20
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: semantic_dyn_pfx_mod
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x10316480
// Name: _dynamic_initializer_for__g_ModelLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ModelLoader__()
{
  CModelLoader::CModelLoader(this: &g_ModelLoader);
  return atexit(func: dynamic_atexit_destructor_for__g_ModelLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DC20
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DC40
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DC90
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DCA0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10326A30
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x10326A40
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10326A50
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<DispCollPlaneIndex_t,CPlaneIndexHashFuncs,CPlaneIndexHashFuncs>::Purge(this: (CUtlHash<CGameSaveRestoreInfo::CHashElement,CGameSaveRestoreInfo::CHashFuncs,CGameSaveRestoreInfo::CHashFuncs> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>::~CUtlVector<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,CUtlMemory<CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>,int>>(this: (CUtlVector<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,CUtlMemory<CUtlVector<CGameSaveRestoreInfo::CHashElement,CUtlMemory<CGameSaveRestoreInfo::CHashElement,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

} // namespace engine_xlsp
