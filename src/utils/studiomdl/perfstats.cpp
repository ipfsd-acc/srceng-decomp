// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/perfstats.cpp
// Functions: 8
// ============================================================

#include "utils\studiomdl\perfstats.h"

//------------------------------------------------------------------------------
// Address: 0x00425FB0
// Name: int Studio_LoadVertexes(struct vertexFileHeader_t const __near *,struct vertexFileHeader_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Studio_LoadVertexes(
        vertexFileHeader_t *pTempVvdHdr,
        vertexFileHeader_t *pNewVvdHdr,
        int rootLOD,
        bool bNeedsTangentS)
{
  int j; // ecx
  int *numLODVertexes; // eax
  int result; // eax
  _DWORD *v9; // ebx
  unsigned int vertexDataStart; // [esp-4h] [ebp-10h]
  int numVertexes; // [esp+14h] [ebp+8h]
  int numVertexesa; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  vertexDataStart = pTempVvdHdr->vertexDataStart;
  numVertexes = pTempVvdHdr->numLODVertexes[rootLOD];
  memcpy(dst: (unsigned __int8 *)pNewVvdHdr, src: (unsigned __int8 *)pTempVvdHdr, count: vertexDataStart);
  j = 0;
  if ( rootLOD > 0 )
  {
    numLODVertexes = pNewVvdHdr->numLODVertexes;
    for ( j = rootLOD; j != 0; --j )
      *numLODVertexes++ = pNewVvdHdr->numLODVertexes[rootLOD];
  }
  if ( bNeedsTangentS )
    pNewVvdHdr->tangentDataStart = pNewVvdHdr->vertexDataStart + 48 * numVertexes;
  else
    pNewVvdHdr->tangentDataStart = j;
  if ( pNewVvdHdr->numFixups == j )
  {
    memcpy(
      dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->vertexDataStart,
      src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->vertexDataStart,
      count: 48 * numVertexes);
    if ( bNeedsTangentS )
      memcpy(
        dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->tangentDataStart,
        src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->tangentDataStart,
        count: 16 * numVertexes);
    return numVertexes;
  }
  else
  {
    result = 0;
    numVertexesa = 0;
    i = j;
    if ( pTempVvdHdr->numFixups > j )
    {
      v9 = (int *)((char *)&pTempVvdHdr->checksum + pTempVvdHdr->fixupTableStart);
      do
      {
        if ( *(v9 - 2) >= rootLOD )
        {
          memcpy(
            dst: (unsigned __int8 *)pNewVvdHdr + 48 * result + pNewVvdHdr->vertexDataStart,
            src: (unsigned __int8 *)pTempVvdHdr + 48 * *(v9 - 1) + pTempVvdHdr->vertexDataStart,
            count: 48 * *v9);
          if ( bNeedsTangentS )
            memcpy(
              dst: (unsigned __int8 *)pNewVvdHdr + 16 * numVertexesa + pNewVvdHdr->tangentDataStart,
              src: (unsigned __int8 *)pTempVvdHdr + 16 * *(v9 - 1) + pTempVvdHdr->tangentDataStart,
              count: 16 * *v9);
          numVertexesa += *v9;
          result = numVertexesa;
        }
        v9 += 3;
        ++i;
      }
      while ( i < pTempVvdHdr->numFixups );
      j = 0;
    }
    pNewVvdHdr->numFixups = j;
    pNewVvdHdr->fixupTableStart = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426100
// Name: public: virtual struct vertexFileHeader_t __near * CStudioDataCache::CacheVertexData(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CStudioDataCache::CacheVertexData(CStudioDataCache *this, studiohdr_t *pStudioHdr)
{
  return (vertexFileHeader_t *)pStudioHdr->pVertexBase;
}

//------------------------------------------------------------------------------
// Address: 0x00426110
// Name: UpdateStudioRenderConfig
// Source: json
//------------------------------------------------------------------------------
int UpdateStudioRenderConfig()
{
  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  *((_BYTE *)&s_StudioRenderConfig + 36) = 113;
  s_StudioRenderConfig.fEyeShiftX = 0.0;
  s_StudioRenderConfig.fEyeShiftY = 0.0;
  s_StudioRenderConfig.fEyeShiftZ = 0.0;
  s_StudioRenderConfig.fEyeSize = 10.0;
  s_StudioRenderConfig.drawEntities = 1;
  s_StudioRenderConfig.skin = 0;
  s_StudioRenderConfig.maxDecalsPerModel = 0;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) &= 0xC2u;
  return ((int (__thiscall *)(IStudioRender *, StudioRenderConfig_t *))g_pStudioRender->UpdateConfig)(
           a1: g_pStudioRender,
           a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x004261B0
// Name: public: virtual void CBaseAppSystem<class IDmSerializers>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IDmSerializers>::Reconnect(
        CBaseAppSystem<IDmSerializers> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x004261D0
// Name: void SpewPerfStats(struct studiohdr_t __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SpewPerfStats(
        studiohwdata_t *p_studioHWData@<esi>,
        studiohdr_t *pStudioHdr,
        const char *pFilename,
        char flags)
{
  char *v4; // eax
  char v5; // cl
  unsigned int File; // ebx
  vertexFileHeader_t *v7; // esi
  int version; // eax
  int checksum; // eax
  vertexFileHeader_t *v10; // eax
  vertexFileHeader_t *v11; // edi
  unsigned int v12; // eax
  const char *v13; // esi
  char *v14; // edi
  char v15; // cl
  char *v16; // edi
  unsigned int v17; // ecx
  int v18; // edi
  OptimizedModel::FileHeader_t *v19; // eax
  int v20; // ecx
  vertexFileHeader_t *v21; // edx
  int i; // esi
  DrawModelInfo_t drawModelInfo; // [esp+8h] [ebp-3A4h] BYREF
  char fileName[260]; // [esp+1E8h] [ebp-1C4h] BYREF
  CUtlBuffer statsOutput; // [esp+2ECh] [ebp-C0h] BYREF
  DrawModelResults_t results; // [esp+31Ch] [ebp-90h] BYREF
  studiohwdata_t studioHWData; // [esp+36Ch] [ebp-40h] BYREF
  const char *prefix[3]; // [esp+388h] [ebp-24h]
  int v30; // [esp+394h] [ebp-18h]
  int v31; // [esp+398h] [ebp-14h]
  int numVtxFiles; // [esp+39Ch] [ebp-10h]
  int j; // [esp+3A0h] [ebp-Ch]
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+3A4h] [ebp-8h] BYREF
  vertexFileHeader_t *pVvdHdr; // [esp+3A8h] [ebp-4h] BYREF

  pVvdHdr = nullptr;
  pVtxHdr = nullptr;
  prefix[0] = ".dx90.vtx";
  prefix[1] = ".dx80.vtx";
  prefix[2] = ".sw.vtx";
  if ( !g_gameinfo.bSupportsDX8 || (numVtxFiles = 3, g_bFastBuild) )
    numVtxFiles = 1;
  v31 = flags & 1;
  if ( (flags & 1) == 0 )
  {
    _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
    _LoggingSystem_RegisterLoggingListener(a1: &s_BufferedLoggingListener);
  }
  if ( pStudioHdr->numbodyparts != 0 )
  {
    UpdateStudioRenderConfig();
    V_StripExtension(in: pFilename, out: fileName, outSize: 260);
    v4 = (char *)&drawModelInfo.m_LightingState.m_pLocalLightDesc[3].m_RangeSquared + 3;
    do
      v5 = *++v4;
    while ( v5 != 0 );
    strcpy(v4, ".vvd");
    if ( FileExists(filename: fileName) == 0 )
      MdlError(fmt: "Could not open '%s'\n", fileName);
    File = LoadFile(a1: (int)pStudioHdr, filename: fileName, bufferptr: (void **)&pVvdHdr);
    v7 = pVvdHdr;
    if ( pVvdHdr->id != 1448297545 )
      MdlError(fmt: "Bad id for '%s' (got %d expected %d)\n", fileName, pVvdHdr->id, 1448297545);
    version = pVvdHdr->version;
    if ( version != 4 )
      MdlError(fmt: "Bad version for '%s' (got %d expected %d)\n", fileName, version, 4);
    checksum = pVvdHdr->checksum;
    if ( checksum != pStudioHdr->checksum )
      MdlError(fmt: "Bad checksum for '%s' (got %d expected %d)\n", fileName, checksum, pStudioHdr->checksum);
    if ( pVvdHdr->numFixups != 0 )
    {
      v10 = (vertexFileHeader_t *)MemAlloc_Alloc(nSize: File);
      v11 = v10;
      if ( v10 == nullptr )
        MdlError(fmt: "Error allocating %d bytes for Vertex File '%s'\n", File, fileName);
      Studio_LoadVertexes(pTempVvdHdr: v7, pNewVvdHdr: v10, rootLOD: 0, bNeedsTangentS: true);
      free(pMem: pVvdHdr);
      v7 = v11;
      pVvdHdr = v11;
    }
    j = 0;
    if ( numVtxFiles > 0 )
    {
      v30 = flags & 2;
      do
      {
        V_StripExtension(in: pFilename, out: fileName, outSize: 260);
        v12 = &prefix[j][strlen(prefix[j]) + 1] - prefix[j];
        v13 = prefix[j];
        v14 = (char *)&drawModelInfo.m_LightingState.m_pLocalLightDesc[3].m_RangeSquared + 3;
        do
          v15 = *++v14;
        while ( v15 != 0 );
        qmemcpy(v14, v13, 4 * (v12 >> 2));
        v16 = &v14[4 * (v12 >> 2)];
        v17 = v12 & 3;
        qmemcpy(v16, &v13[4 * (v12 >> 2)], v17);
        v18 = (int)&v16[v17];
        if ( FileExists(filename: fileName) == 0 )
          MdlError(fmt: "Could not open '%s'\n", fileName);
        LoadFile(a1: v18, filename: fileName, bufferptr: (void **)&pVtxHdr);
        v19 = pVtxHdr;
        if ( pVtxHdr->version != 7 )
          MdlError(fmt: "Bad version for '%s' (got %d expected %d)\n", fileName, pVtxHdr->version, 7);
        v20 = pVtxHdr->checkSum;
        if ( v20 != pStudioHdr->checksum )
          MdlError(fmt: "Bad checksum for '%s' (got %d expected %d)\n", fileName, v20, pStudioHdr->checksum);
        v21 = pVvdHdr;
        pStudioHdr->pIndexBase = pVtxHdr;
        pStudioHdr->pVertexBase = v21;
        ((void (__thiscall *)(IStudioRender *, studiohdr_t *, OptimizedModel::FileHeader_t *, studiohwdata_t *, studiohwdata_t *))g_pStudioRender->LoadModel)(
          a1: g_pStudioRender,
          a2: pStudioHdr,
          a3: v19,
          a4: &studioHWData,
          a5: p_studioHWData);
        if ( v30 != 0 )
        {
          if ( (flags & 4) != 0 )
          {
            printf(format: "%s,%s,%d,", fileName, prefix[j], studioHWData.m_NumLODs - studioHWData.m_RootLOD);
          }
          else
          {
            printf(format: "\n");
            printf(format: "Performance Stats: %s\n", fileName);
            printf(format: "------------------\n");
          }
          for ( i = studioHWData.m_RootLOD; i < studioHWData.m_NumLODs; ++i )
          {
            memset(&drawModelInfo.m_Skin, 0, 16);
            drawModelInfo.m_pColorMeshes = nullptr;
            drawModelInfo.m_pStudioHdr = pStudioHdr;
            drawModelInfo.m_pHardwareData = &studioHWData;
            CUtlBuffer::CUtlBuffer(this: &statsOutput, growSize: 0, initSize: 0, nFlags: 1);
            if ( (flags & 4) == 0 )
              printf(format: "LOD:%d\n", i);
            results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
            drawModelInfo.m_Lod = i;
            results.m_RenderTime.m_Duration.m_Int64 = 0;
            results.m_Materials.m_Size = 0;
            g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &results, a3: &drawModelInfo, a4: &statsOutput);
            if ( (flags & 4) != 0 )
            {
              printf(format: "%d,%d,%d,", results.m_ActualTriCount, results.m_NumBatches, results.m_NumMaterials);
            }
            else
            {
              printf(format: "    actual tris:%d\n", results.m_ActualTriCount);
              printf(
                format: "    texture memory bytes: %d (only valid in a rendering app)\n",
                results.m_TextureMemoryBytes);
              printf(format: (const char *)statsOutput.m_Memory.m_pMemory);
            }
            results.m_Materials.m_Size = 0;
            results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
            if ( statsOutput.m_Memory.m_nGrowSize >= 0 && statsOutput.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: statsOutput.m_Memory.m_pMemory);
          }
          if ( (flags & 4) != 0 )
            printf(format: "\n");
        }
        p_studioHWData = &studioHWData;
        ((void (__thiscall *)(IStudioRender *))g_pStudioRender->UnloadModel)(a1: g_pStudioRender);
        free(pMem: pVtxHdr);
        ++j;
      }
      while ( j < numVtxFiles );
      v7 = pVvdHdr;
    }
    if ( v7 != nullptr )
      free(pMem: v7);
    if ( v31 == 0 )
    {
      _LoggingSystem_PopLoggingState(a1: 0);
      CBufferedLoggingListener::EmitBufferedSpew(this: &s_BufferedLoggingListener);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8A90
// Name: public: virtual bool CStudioDataCache::VerifyHeaders(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioDataCache::VerifyHeaders(
        CDmElementFramework *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D93D0
// Name: public: virtual void __near * CBaseAppSystem<class IStudioDataCache>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAppSystem<IStudioDataCache>::QueryInterface(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004260F0
// Name: __CreateCStudioDataCacheIStudioDataCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStudioDataCache *__cdecl _CreateCStudioDataCacheIStudioDataCache_interface()
{
  return &g_StudioDataCache;
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0041EBC0
// Name: int Studio_LoadVertexes(struct vertexFileHeader_t const __near *,struct vertexFileHeader_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Studio_LoadVertexes(
        vertexFileHeader_t *pTempVvdHdr,
        vertexFileHeader_t *pNewVvdHdr,
        int rootLOD,
        bool bNeedsTangentS)
{
  int j; // ecx
  int *numLODVertexes; // eax
  int result; // eax
  _DWORD *v9; // ebx
  unsigned int vertexDataStart; // [esp-4h] [ebp-10h]
  int numVertexes; // [esp+14h] [ebp+8h]
  int numVertexesa; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  vertexDataStart = pTempVvdHdr->vertexDataStart;
  numVertexes = pTempVvdHdr->numLODVertexes[rootLOD];
  memcpy(dst: (unsigned __int8 *)pNewVvdHdr, src: (unsigned __int8 *)pTempVvdHdr, count: vertexDataStart);
  j = 0;
  if ( rootLOD > 0 )
  {
    numLODVertexes = pNewVvdHdr->numLODVertexes;
    for ( j = rootLOD; j != 0; --j )
      *numLODVertexes++ = pNewVvdHdr->numLODVertexes[rootLOD];
  }
  if ( bNeedsTangentS )
    pNewVvdHdr->tangentDataStart = pNewVvdHdr->vertexDataStart + 48 * numVertexes;
  else
    pNewVvdHdr->tangentDataStart = j;
  if ( pNewVvdHdr->numFixups == j )
  {
    memcpy(
      dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->vertexDataStart,
      src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->vertexDataStart,
      count: 48 * numVertexes);
    if ( bNeedsTangentS )
      memcpy(
        dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->tangentDataStart,
        src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->tangentDataStart,
        count: 16 * numVertexes);
    return numVertexes;
  }
  else
  {
    result = 0;
    numVertexesa = 0;
    i = j;
    if ( pTempVvdHdr->numFixups > j )
    {
      v9 = (int *)((char *)&pTempVvdHdr->checksum + pTempVvdHdr->fixupTableStart);
      do
      {
        if ( *(v9 - 2) >= rootLOD )
        {
          memcpy(
            dst: (unsigned __int8 *)pNewVvdHdr + 48 * result + pNewVvdHdr->vertexDataStart,
            src: (unsigned __int8 *)pTempVvdHdr + 48 * *(v9 - 1) + pTempVvdHdr->vertexDataStart,
            count: 48 * *v9);
          if ( bNeedsTangentS )
            memcpy(
              dst: (unsigned __int8 *)pNewVvdHdr + 16 * numVertexesa + pNewVvdHdr->tangentDataStart,
              src: (unsigned __int8 *)pTempVvdHdr + 16 * *(v9 - 1) + pTempVvdHdr->tangentDataStart,
              count: 16 * *v9);
          numVertexesa += *v9;
          result = numVertexesa;
        }
        v9 += 3;
        ++i;
      }
      while ( i < pTempVvdHdr->numFixups );
      j = 0;
    }
    pNewVvdHdr->numFixups = j;
    pNewVvdHdr->fixupTableStart = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED10
// Name: public: virtual struct vertexFileHeader_t __near * CStudioDataCache::CacheVertexData(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
vertexFileHeader_t *__thiscall CStudioDataCache::CacheVertexData(CStudioDataCache *this, studiohdr_t *pStudioHdr)
{
  return (vertexFileHeader_t *)pStudioHdr->pVertexBase;
}

//------------------------------------------------------------------------------
// Address: 0x0041ED20
// Name: UpdateStudioRenderConfig
// Source: json
//------------------------------------------------------------------------------
int UpdateStudioRenderConfig()
{
  memset(dst: (unsigned __int8 *)&s_StudioRenderConfig, value: 0, count: sizeof(s_StudioRenderConfig));
  *((_BYTE *)&s_StudioRenderConfig + 36) = 113;
  s_StudioRenderConfig.fEyeShiftX = 0.0;
  s_StudioRenderConfig.fEyeShiftY = 0.0;
  s_StudioRenderConfig.fEyeShiftZ = 0.0;
  s_StudioRenderConfig.fEyeSize = 10.0;
  s_StudioRenderConfig.drawEntities = 1;
  s_StudioRenderConfig.skin = 0;
  s_StudioRenderConfig.maxDecalsPerModel = 0;
  s_StudioRenderConfig.fullbright = 0;
  *((_BYTE *)&s_StudioRenderConfig + 37) &= 0xC2u;
  return ((int (__thiscall *)(IStudioRender *, StudioRenderConfig_t *))g_pStudioRender->UpdateConfig)(
           a1: g_pStudioRender,
           a2: &s_StudioRenderConfig);
}

//------------------------------------------------------------------------------
// Address: 0x0041EDC0
// Name: public: virtual void __near * CBaseAppSystem<class IStudioDataCache>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CBaseAppSystem<IStudioDataCache>::QueryInterface(CImportCommentary *this, KeyValues *pKeyValues)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041EDD0
// Name: void SpewPerfStats(struct studiohdr_t __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SpewPerfStats(
        studiohwdata_t *p_studioHWData@<esi>,
        studiohdr_t *pStudioHdr,
        const char *pFilename,
        char flags)
{
  char *v4; // eax
  char v5; // cl
  unsigned int File; // ebx
  vertexFileHeader_t *v7; // esi
  int version; // eax
  int checksum; // eax
  vertexFileHeader_t *v10; // eax
  vertexFileHeader_t *v11; // edi
  unsigned int v12; // eax
  char *v13; // edi
  char v14; // cl
  OptimizedModel::FileHeader_t *v15; // eax
  int v16; // ecx
  vertexFileHeader_t *v17; // edx
  int i; // esi
  DrawModelInfo_t drawModelInfo; // [esp+8h] [ebp-3A4h] BYREF
  char fileName[260]; // [esp+1E8h] [ebp-1C4h] BYREF
  CUtlBuffer statsOutput; // [esp+2ECh] [ebp-C0h] BYREF
  DrawModelResults_t results; // [esp+31Ch] [ebp-90h] BYREF
  studiohwdata_t studioHWData; // [esp+36Ch] [ebp-40h] BYREF
  const char *prefix[3]; // [esp+388h] [ebp-24h]
  int v26; // [esp+394h] [ebp-18h]
  int v27; // [esp+398h] [ebp-14h]
  int numVtxFiles; // [esp+39Ch] [ebp-10h]
  int j; // [esp+3A0h] [ebp-Ch]
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+3A4h] [ebp-8h] BYREF
  vertexFileHeader_t *pVvdHdr; // [esp+3A8h] [ebp-4h] BYREF

  pVvdHdr = nullptr;
  pVtxHdr = nullptr;
  prefix[0] = ".dx90.vtx";
  prefix[1] = ".dx80.vtx";
  prefix[2] = ".sw.vtx";
  if ( !g_gameinfo.bSupportsDX8 || (numVtxFiles = 3, g_bFastBuild) )
    numVtxFiles = 1;
  v27 = flags & 1;
  if ( (flags & 1) == 0 )
  {
    _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
    _LoggingSystem_RegisterLoggingListener(a1: &s_BufferedLoggingListener);
  }
  if ( pStudioHdr->numbodyparts != 0 )
  {
    UpdateStudioRenderConfig();
    V_StripExtension(in: pFilename, out: fileName, outSize: 260);
    v4 = (char *)&drawModelInfo.m_LightingState.m_pLocalLightDesc[3].m_RangeSquared + 3;
    do
      v5 = *++v4;
    while ( v5 != 0 );
    strcpy(v4, ".vvd");
    if ( FileExists(filename: fileName) == 0 )
      MdlError(fmt: "Could not open '%s'\n", fileName);
    File = LoadFile(filename: fileName, bufferptr: (void **)&pVvdHdr);
    v7 = pVvdHdr;
    if ( pVvdHdr->id != 1448297545 )
      MdlError(fmt: "Bad id for '%s' (got %d expected %d)\n", fileName, pVvdHdr->id, 1448297545);
    version = pVvdHdr->version;
    if ( version != 4 )
      MdlError(fmt: "Bad version for '%s' (got %d expected %d)\n", fileName, version, 4);
    checksum = pVvdHdr->checksum;
    if ( checksum != pStudioHdr->checksum )
      MdlError(fmt: "Bad checksum for '%s' (got %d expected %d)\n", fileName, checksum, pStudioHdr->checksum);
    if ( pVvdHdr->numFixups != 0 )
    {
      v10 = (vertexFileHeader_t *)MemAlloc_Alloc(nSize: File);
      v11 = v10;
      if ( v10 == nullptr )
        MdlError(fmt: "Error allocating %d bytes for Vertex File '%s'\n", File, fileName);
      Studio_LoadVertexes(pTempVvdHdr: v7, pNewVvdHdr: v10, rootLOD: 0, bNeedsTangentS: true);
      free(pMem: pVvdHdr);
      v7 = v11;
      pVvdHdr = v11;
    }
    j = 0;
    if ( numVtxFiles > 0 )
    {
      v26 = flags & 2;
      do
      {
        V_StripExtension(in: pFilename, out: fileName, outSize: 260);
        v12 = &prefix[j][strlen(prefix[j]) + 1] - prefix[j];
        v13 = (char *)&drawModelInfo.m_LightingState.m_pLocalLightDesc[3].m_RangeSquared + 3;
        do
          v14 = *++v13;
        while ( v14 != 0 );
        qmemcpy(v13, prefix[j], v12);
        if ( FileExists(filename: fileName) == 0 )
          MdlError(fmt: "Could not open '%s'\n", fileName);
        LoadFile(filename: fileName, bufferptr: (void **)&pVtxHdr);
        v15 = pVtxHdr;
        if ( pVtxHdr->version != 7 )
          MdlError(fmt: "Bad version for '%s' (got %d expected %d)\n", fileName, pVtxHdr->version, 7);
        v16 = pVtxHdr->checkSum;
        if ( v16 != pStudioHdr->checksum )
          MdlError(fmt: "Bad checksum for '%s' (got %d expected %d)\n", fileName, v16, pStudioHdr->checksum);
        v17 = pVvdHdr;
        pStudioHdr->pIndexBase = pVtxHdr;
        pStudioHdr->pVertexBase = v17;
        ((void (__thiscall *)(IStudioRender *, studiohdr_t *, OptimizedModel::FileHeader_t *, studiohwdata_t *, studiohwdata_t *))g_pStudioRender->LoadModel)(
          a1: g_pStudioRender,
          a2: pStudioHdr,
          a3: v15,
          a4: &studioHWData,
          a5: p_studioHWData);
        if ( v26 != 0 )
        {
          if ( (flags & 4) != 0 )
          {
            printf(format: "%s,%s,%d,", fileName, prefix[j], studioHWData.m_NumLODs - studioHWData.m_RootLOD);
          }
          else
          {
            printf(format: "\n");
            printf(format: "Performance Stats: %s\n", fileName);
            printf(format: "------------------\n");
          }
          for ( i = studioHWData.m_RootLOD; i < studioHWData.m_NumLODs; ++i )
          {
            memset(&drawModelInfo.m_Skin, 0, 16);
            drawModelInfo.m_pColorMeshes = nullptr;
            drawModelInfo.m_pStudioHdr = pStudioHdr;
            drawModelInfo.m_pHardwareData = &studioHWData;
            CUtlBuffer::CUtlBuffer(this: &statsOutput, growSize: 0, initSize: 0, nFlags: 1);
            if ( (flags & 4) == 0 )
              printf(format: "LOD:%d\n", i);
            results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
            drawModelInfo.m_Lod = i;
            results.m_RenderTime.m_Duration.m_Int64 = 0;
            results.m_Materials.m_Size = 0;
            g_pStudioRender->GetPerfStats(this: g_pStudioRender, a2: &results, a3: &drawModelInfo, a4: &statsOutput);
            if ( (flags & 4) != 0 )
            {
              printf(format: "%d,%d,%d,", results.m_ActualTriCount, results.m_NumBatches, results.m_NumMaterials);
            }
            else
            {
              printf(format: "    actual tris:%d\n", results.m_ActualTriCount);
              printf(
                format: "    texture memory bytes: %d (only valid in a rendering app)\n",
                results.m_TextureMemoryBytes);
              printf(format: (const char *)statsOutput.m_Memory.m_pMemory);
            }
            results.m_Materials.m_Size = 0;
            results.m_Materials.m_pElements = (IMaterial **)&results.m_Materials;
            if ( statsOutput.m_Memory.m_nGrowSize >= 0 && statsOutput.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: statsOutput.m_Memory.m_pMemory);
          }
          if ( (flags & 4) != 0 )
            printf(format: "\n");
        }
        p_studioHWData = &studioHWData;
        ((void (__thiscall *)(IStudioRender *))g_pStudioRender->UnloadModel)(a1: g_pStudioRender);
        free(pMem: pVtxHdr);
        ++j;
      }
      while ( j < numVtxFiles );
      v7 = pVvdHdr;
    }
    if ( v7 != nullptr )
      free(pMem: v7);
    if ( v27 == 0 )
    {
      _LoggingSystem_PopLoggingState(a1: 0);
      CBufferedLoggingListener::EmitBufferedSpew(this: &s_BufferedLoggingListener);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B1EE0
// Name: public: virtual bool CStudioDataCache::VerifyHeaders(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStudioDataCache::VerifyHeaders(
        CDmElementFramework *this,
        void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C08F0
// Name: public: virtual void CBaseAppSystem<class IDmSerializers>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IDmSerializers>::Reconnect(
        CBaseAppSystem<IDmSerializers> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x0041ED00
// Name: __CreateCStudioDataCacheIStudioDataCache_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CStudioDataCache *__cdecl _CreateCStudioDataCacheIStudioDataCache_interface()
{
  return &g_StudioDataCache;
}

//------------------------------------------------------------------------------
// Address: 0x004C0910
// Name: class CDmElement __near * CreateElement<class CDmElement>(char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl CreateElement<CDmElement>(
        const char *pElementType,
        const char *pObjectName,
        DmFileId_t fileid,
        const UniqueId_t *pObjectID)
{
  int v4; // eax
  int v5; // eax
  int v6; // esi

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pElementType,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v4);
  v6 = v5;
  if ( v5 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
         a1: v5,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v6;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0970
// Name: class CDmElement __near * FindReferringElement<class CDmElement>(class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl FindReferringElement<CDmElement>(
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v4; // esi
  int v5; // eax
  DmAttributeReferenceIterator_t v6; // eax
  DmFileId_t m_pMemory; // edi
  DmAttributeReferenceIterator_t v8; // esi
  CDmElement *result; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v4 = *(_DWORD *)g_pDataModel.u.m_Id;
    v5 = CExpressionCalculator::VariableCount(this: pElement);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v4 + 436))(a1: g_pDataModel.u, a2: v5);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
    v8 = v6;
    it.m_curr = v6;
  }
  else
  {
    v8 = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  it.m_fileid = m_pMemory;
  if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
    return nullptr;
  while ( 1 )
  {
    result = CAttributeReferenceIterator::FilterReference<CDmElement>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( result != nullptr )
      break;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 440))(
           a1: g_pDataModel.u,
           a2: v8);
    it.m_curr = v8;
    if ( v8 == DMATTRIBUTE_REFERENCE_ITERATOR_INVALID )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0A00
// Name: class CDmElement __near * FindReferringElement<class CDmElement>(class CDmElement const __near *,char const __near *,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl FindReferringElement<CDmElement>(
        CExpressionCalculator *pElement,
        int pAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  CUtlSymbolLarge *p_pAttrName; // eax

  if ( pAttrName != 0 )
  {
    p_pAttrName = (CUtlSymbolLarge *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, int))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                       a1: g_pDataModel.u,
                                       a2: &pAttrName,
                                       a3: pAttrName);
  }
  else
  {
    pAttrName = -1;
    p_pAttrName = (CUtlSymbolLarge *)&pAttrName;
  }
  return FindReferringElement<CDmElement>(
           pElement,
           symAttrName: (CUtlSymbolLarge)p_pAttrName->u.m_Id,
           bMustBeInSameFile,
           depth);
}

//------------------------------------------------------------------------------
// Address: 0x004C0A50
// Name: class CDmElement __near * CreateElement<class CDmElement>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl CreateElement<CDmElement>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmElement::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v5;
  }
  else
  {
    return nullptr;
  }
}

} // namespace studiomdl
