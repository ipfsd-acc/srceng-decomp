// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/map_shared.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0044A7C0
// Name: enum ChunkFileResult_t LoadEntityKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadEntityKeyCallback(const char *szKey, const char *szValue, LoadEntity_t *pLoadEntity)
{
  if ( _V_stricmp(s1: szKey, s2: "classname") == 0 )
  {
    if ( _V_stricmp(s1: szValue, s2: "func_detail") != 0 )
    {
      if ( _V_stricmp(s1: szValue, s2: "func_ladder") != 0 )
      {
        if ( _V_stricmp(s1: szValue, s2: "func_water") == 0 )
          pLoadEntity->nBaseContents = 32;
      }
      else
      {
        pLoadEntity->nBaseContents = 0x20000000;
      }
    }
    else
    {
      pLoadEntity->nBaseContents = (int)&g_WaterOverlays[7253].aFaces[48];
    }
    goto LABEL_4;
  }
  if ( _V_stricmp(s1: szKey, s2: "id") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "mapversion") != 0 )
    {
LABEL_4:
      SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
      return ChunkFile_Ok;
    }
    g_MapRevision = atoi(nptr: szValue);
    SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
  else
  {
    SetKeyValue(ent: pLoadEntity->pEntity, key: "hammerid", value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
}

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00455B50
// Name: enum ChunkFileResult_t LoadEntityKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadEntityKeyCallback(const char *szKey, const char *szValue, LoadEntity_t *pLoadEntity)
{
  if ( _V_stricmp(s1: szKey, s2: "classname") == 0 )
  {
    if ( _V_stricmp(s1: szValue, s2: "func_detail") != 0 )
    {
      if ( _V_stricmp(s1: szValue, s2: "func_ladder") != 0 )
      {
        if ( _V_stricmp(s1: szValue, s2: "func_water") == 0 )
          pLoadEntity->nBaseContents = 32;
      }
      else
      {
        pLoadEntity->nBaseContents = 0x20000000;
      }
    }
    else
    {
      pLoadEntity->nBaseContents = 0x8000000;
    }
    goto LABEL_4;
  }
  if ( _V_stricmp(s1: szKey, s2: "id") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "mapversion") != 0 )
    {
LABEL_4:
      SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
      return ChunkFile_Ok;
    }
    g_MapRevision = atoi(nptr: szValue);
    SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
  else
  {
    SetKeyValue(ent: pLoadEntity->pEntity, key: "hammerid", value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10049320
// Name: enum ChunkFileResult_t LoadEntityKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadEntityKeyCallback(const char *szKey, const char *szValue, LoadEntity_t *pLoadEntity)
{
  if ( _V_stricmp(s1: szKey, s2: "classname") == 0 )
  {
    if ( _V_stricmp(s1: szValue, s2: "func_detail") != 0 )
    {
      if ( _V_stricmp(s1: szValue, s2: "func_ladder") != 0 )
      {
        if ( _V_stricmp(s1: szValue, s2: "func_water") == 0 )
          pLoadEntity->nBaseContents = 32;
      }
      else
      {
        pLoadEntity->nBaseContents = 0x20000000;
      }
    }
    else
    {
      pLoadEntity->nBaseContents = 0x8000000;
    }
    goto LABEL_4;
  }
  if ( _V_stricmp(s1: szKey, s2: "id") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "mapversion") != 0 )
    {
LABEL_4:
      SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
      return ChunkFile_Ok;
    }
    g_MapRevision = atoi(nptr: szValue);
    SetKeyValue(ent: pLoadEntity->pEntity, key: szKey, value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
  else
  {
    SetKeyValue(ent: pLoadEntity->pEntity, key: "hammerid", value: szValue, bAllowDuplicates: false);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049420
// Name: LoadEntityCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadEntityCallback(CChunkFile *pFile)
{
  entity_t *v1; // esi
  LoadEntity_t LoadEntity; // [esp+0h] [ebp-10h] BYREF

  if ( num_entities == 0x4000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "num_entities == MAX_MAP_ENTITIES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v1 = &entities[num_entities++];
  memset(dst: (unsigned __int8 *)v1, value: 0, count: sizeof(entity_t));
  v1->numbrushes = 0;
  LoadEntity.pEntity = v1;
  LoadEntity.nBaseFlags = 0;
  LoadEntity.nBaseContents = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadEntityKeyCallback,
           pData: &LoadEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100494B0
// Name: bool LoadEntsFromMapFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadEntsFromMapFile(const char *pFilename)
{
  ChunkFileResult_t v1; // eax
  const char *ErrorText; // eax
  CChunkFile File; // [esp+0h] [ebp-350h] BYREF
  CChunkHandlerMap Handlers; // [esp+344h] [ebp-Ch] BYREF

  g_nMapFileVersion = 400;
  CChunkFile::CChunkFile(this: &File);
  v1 = CChunkFile::Open(this: &File, pszFileName: pFilename, eMode: ChunkFile_Read);
  if ( v1 != ChunkFile_Ok )
  {
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v1);
    _Error(a1: "Error in LoadEntsFromMapFile (in-memory file): %s.\n", ErrorText);
    CChunkFile::~CChunkFile(this: &File);
    return 0;
  }
  else
  {
    num_entities = 0;
    CExpressionEvaluator::CExpressionEvaluator(this: (CEvent *)&Handlers);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "entity",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadEntityCallback,
      pData: nullptr);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    while ( CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr) == ChunkFile_Ok )
      ;
    CChunkFile::PopHandlers(this: &File);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    CChunkFile::~CChunkFile(this: &File);
    return 1;
  }
}

} // namespace vrad_dll
