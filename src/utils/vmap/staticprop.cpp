// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/staticprop.cpp
// Functions: 29
// ============================================================

#include "utils\vmap\staticprop.h"

//------------------------------------------------------------------------------
// Address: 0x00419060
// Name: SetLumpData
// Source: json
//------------------------------------------------------------------------------
void SetLumpData()
{
  unsigned __int16 GameLumpHandle; // si
  int v1; // ebx
  int v2; // edi
  int v3; // esi
  unsigned __int16 GameLump; // ax
  const void *v5; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  int nSize; // [esp+3Ch] [ebp-4h]

  qsort(
    base: s_DetailObjectLump.m_Memory.m_pMemory,
    num: s_DetailObjectLump.m_Size,
    width: 0x34u,
    comp: (int (__cdecl *)(const void *, const void *))SortFunc);
  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1685090928);
  if ( GameLumpHandle != CGameLump::InvalidGameLump(this: &g_GameLumps) )
    CGameLump::DestroyGameLump(this: &g_GameLumps, handle: GameLumpHandle);
  v1 = 52 * s_DetailObjectLump.m_Size;
  v2 = 32 * s_DetailSpriteDictLump.m_Size;
  v3 = s_DetailObjectDictLump.m_Size << 7;
  nSize = 52 * s_DetailObjectLump.m_Size
        + 32 * s_DetailSpriteDictLump.m_Size
        + (s_DetailObjectDictLump.m_Size << 7)
        + 12;
  GameLump = CGameLump::CreateGameLump(this: &g_GameLumps, id: 1685090928, size: nSize, flags: 0, version: 4);
  v5 = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLump);
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v5, nSize, nFlags: 0);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_DetailObjectDictLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_DetailObjectDictLump.m_Size);
  if ( v3 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_DetailObjectDictLump.m_Memory.m_pMemory, size: v3);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_DetailSpriteDictLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_DetailSpriteDictLump.m_Size);
  if ( v2 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_DetailSpriteDictLump.m_Memory.m_pMemory, size: v2);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_DetailObjectLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_DetailObjectLump.m_Size);
  if ( v1 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_DetailObjectLump.m_Memory.m_pMemory, size: v1);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0042D230
// Name: bool Studio_ConvertStudioHdrToNewVersion(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Studio_ConvertStudioHdrToNewVersion(studiohdr_t *pStudioHdr)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  int k; // edx
  int v8; // ecx
  char *v9; // ecx
  int m; // edi
  int v11; // ecx
  char *v12; // ecx
  int v13; // edx
  int j; // edx
  int v15; // ecx
  char *v16; // ecx
  int version; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  char bResult_3; // [esp+1Bh] [ebp+Bh]

  v2 = pStudioHdr->version;
  version = v2;
  if ( v2 == 49 )
    return 1;
  bResult_3 = 1;
  if ( v2 < 46 )
  {
    v4 = 0;
    for ( i = 0; v4 < pStudioHdr->numlocalanim; i = v4 )
    {
      v5 = v4;
      if ( v4 < 0 || v4 >= pStudioHdr->numlocalanim )
        v5 = 0;
      v6 = (unsigned __int8 *)pStudioHdr + 100 * v5 + pStudioHdr->localanimindex;
      if ( *((_DWORD *)v6 + 21) != 0 )
      {
        memset(dst: v6 + 16, value: 0, count: 0x54u);
        v4 = i;
        *((_DWORD *)v6 + 4) = 1;
        v2 = version;
        *((_DWORD *)v6 + 13) = -1;
        bResult_3 = 0;
      }
      ++v4;
    }
  }
  if ( v2 >= 47 )
  {
    if ( v2 == 47 )
    {
      for ( j = 0; j < pStudioHdr->numlocalanim; ++j )
      {
        v15 = j;
        if ( j < 0 || j >= pStudioHdr->numlocalanim )
          v15 = 0;
        v16 = (char *)pStudioHdr + 100 * v15 + pStudioHdr->localanimindex;
        if ( *((_DWORD *)v16 + 23) != 0 )
        {
          *((_DWORD *)v16 + 23) = 0;
          *((_WORD *)v16 + 44) = 0;
          bResult_3 = 0;
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( pStudioHdr->unused4 != 0 )
    {
      pStudioHdr->unused4 = 0;
      bResult_3 = 0;
    }
    for ( k = 0; k < pStudioHdr->numlocalanim; *((_WORD *)v9 + 44) = 0 )
    {
      v8 = k;
      if ( k < 0 || k >= pStudioHdr->numlocalanim )
        v8 = 0;
      v9 = (char *)pStudioHdr + 100 * v8 + pStudioHdr->localanimindex;
      ++k;
      *((_DWORD *)v9 + 23) = 0;
    }
  }
  if ( v2 < 49 )
  {
LABEL_20:
    for ( m = 0; m < pStudioHdr->numlocalanim; ++m )
    {
      v11 = m;
      if ( m < 0 || m >= pStudioHdr->numlocalanim )
        v11 = 0;
      v12 = (char *)pStudioHdr + 100 * v11 + pStudioHdr->localanimindex;
      v13 = *((_DWORD *)v12 + 3);
      if ( (v13 & 0x40) != 0 )
      {
        *((_DWORD *)v12 + 3) = v13 & 0xFFFFFFBF;
        bResult_3 = 0;
      }
    }
  }
  pStudioHdr->version = 49;
  return bResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x0042D3B0
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
// Address: 0x0042D510
// Name: GetTextureName
// Source: json
//------------------------------------------------------------------------------
char *__fastcall GetTextureName(
        OptimizedModel::FileHeader_t *pVtxHeader,
        int lodID,
        studiohdr_t *phdr,
        int inMaterialID)
{
  int v4; // eax
  int v5; // edx
  char *v6; // eax
  int v7; // ecx
  char *i; // esi

  v4 = pVtxHeader->materialReplacementListOffset + 8 * lodID;
  v5 = *(int *)((char *)&pVtxHeader->version + v4);
  v6 = (char *)pVtxHeader + v4;
  v7 = 0;
  if ( v5 <= 0 )
    return (char *)phdr
         + 64 * inMaterialID
         + phdr->textureindex
         + *(int *)((char *)&phdr->id + 64 * inMaterialID + phdr->textureindex);
  for ( i = &v6[*((_DWORD *)v6 + 1)]; *(__int16 *)i != inMaterialID; i += 6 )
  {
    if ( ++v7 >= v5 )
      return (char *)phdr
           + 64 * inMaterialID
           + phdr->textureindex
           + *(int *)((char *)&phdr->id + 64 * inMaterialID + phdr->textureindex);
  }
  return &i[*(_DWORD *)(i + 2)];
}

//------------------------------------------------------------------------------
// Address: 0x0042D570
// Name: public: CModelBatch::~CModelBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBatch::~CModelBatch(CModelBatch *this)
{
  free(pMem: this->m_pIndex);
  free(pMem: this->m_pVertex);
}

//------------------------------------------------------------------------------
// Address: 0x0042D590
// Name: public: void CModelBatch::Init(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBatch::Init(
        CModelBatch *this,
        unsigned int nIndexCount,
        unsigned int nVertexCount,
        int nTextureIndex)
{
  BaseWorldVertex_t *v5; // eax
  int v6; // edx
  _DWORD *p_z; // ecx

  this->m_nMaterial = nTextureIndex;
  this->m_nIndexCount = nIndexCount;
  this->m_nVertexCount = nVertexCount;
  this->m_pIndex = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)nIndexCount >> 30 != 0 ? -1 : 4 * nIndexCount);
  v5 = (BaseWorldVertex_t *)MemAlloc_Alloc(nSize: (36 * (unsigned __int64)nVertexCount) >> 32 != 0 ? -1 : 36 * nVertexCount);
  if ( v5 == nullptr )
  {
    v5 = nullptr;
    goto LABEL_7;
  }
  v6 = nVertexCount - 1;
  if ( (int)(nVertexCount - 1) < 0 )
  {
LABEL_7:
    this->m_pVertex = v5;
    return;
  }
  p_z = (_DWORD *)&v5->m_vNormal.z;
  do
  {
    *(p_z - 5) = 0;
    *(p_z - 4) = 0;
    *(p_z - 3) = 0;
    *(p_z - 2) = 0;
    *(p_z - 1) = 0;
    *p_z = 0;
    p_z[1] = 0;
    p_z[2] = 0;
    p_z[3] = 0;
    p_z += 9;
    --v6;
  }
  while ( v6 >= 0 );
  this->m_pVertex = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0042D640
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042D670
// Name: bool StudioKeyValues(struct studiohdr_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl StudioKeyValues(studiohdr_t *pStudioHdr, KeyValues *pValue)
{
  const char *v3; // esi
  int studiohdr2index; // eax
  int v5; // edx
  char *v6; // eax
  int v7; // ecx

  if ( pStudioHdr == nullptr )
    return 0;
  if ( pStudioHdr->keyvaluesize != 0 )
    v3 = (char *)pStudioHdr + pStudioHdr->keyvalueindex;
  else
    v3 = nullptr;
  studiohdr2index = pStudioHdr->studiohdr2index;
  if ( studiohdr2index == 0 )
    return KeyValues::LoadFromBuffer(
             this: pValue,
             resourceName: pStudioHdr->name,
             pBuffer: v3,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
  v5 = *(_DWORD *)&pStudioHdr->name[studiohdr2index + 8];
  v6 = (char *)pStudioHdr + studiohdr2index;
  if ( v5 == 0 || &v6[v5] == nullptr )
    return KeyValues::LoadFromBuffer(
             this: pValue,
             resourceName: pStudioHdr->name,
             pBuffer: v3,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
  v7 = *((_DWORD *)v6 + 5);
  if ( v7 != 0 )
    return KeyValues::LoadFromBuffer(
             this: pValue,
             resourceName: &v6[v7],
             pBuffer: v3,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
  else
    return KeyValues::LoadFromBuffer(
             this: pValue,
             resourceName: nullptr,
             pBuffer: v3,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042D6F0
// Name: enum isstaticprop_ret IsStaticProp(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IsStaticProp(studiohdr_t *pHdr)
{
  KeyValues *v2; // eax
  int studiohdr2index; // edx
  int v4; // esi
  char *v5; // edx
  int v6; // esi
  KeyValues *v7; // esi
  KeyValues *Key; // eax

  if ( (pHdr->flags & 0x10) == 0 )
    return 1;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    studiohdr2index = pHdr->studiohdr2index;
    if ( studiohdr2index != 0
      && (v4 = *(_DWORD *)&pHdr->name[studiohdr2index + 8], v5 = (char *)pHdr + studiohdr2index, v4 != 0)
      && &v5[v4] != nullptr )
    {
      v6 = *((_DWORD *)v5 + 5);
      if ( v6 != 0 )
        v7 = KeyValues::KeyValues(this: v2, setName: &v5[v6]);
      else
        v7 = KeyValues::KeyValues(this: v2, setName: nullptr);
    }
    else
    {
      v7 = KeyValues::KeyValues(this: v2, setName: pHdr->name);
    }
  }
  else
  {
    v7 = nullptr;
  }
  if ( StudioKeyValues(pStudioHdr: pHdr, pValue: v7) != 0
    && (Key = KeyValues::FindKey(this: v7, keyName: "prop_data", bCreate: false)) != nullptr
    && KeyValues::GetInt(this: Key, keyName: "allowstatic", defaultValue: 0) == 0 )
  {
    KeyValues::deleteThis(this: v7);
    return 2;
  }
  else
  {
    KeyValues::deleteThis(this: v7);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D7C0
// Name: bool LoadStudioModel(char const __near *,char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadStudioModel(const char *pModelName, const char *pEntityType, CUtlBuffer *buf)
{
  IMapDataFilesMgr *MapDataFilesMgr; // eax
  studiohdr_t *v5; // edi
  int v6; // eax

  MapDataFilesMgr = GetMapDataFilesMgr();
  if ( !MapDataFilesMgr->ReadRegisteredFile(this: MapDataFilesMgr, a2: pModelName, a3: buf)
    && !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: pModelName,
          a3: nullptr,
          a4: buf,
          a5: 0,
          a6: 0,
          a7: nullptr)
    || strncmp(first: (const char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], last: "IDST", count: 4u) != 0
    && strncmp(first: (const char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], last: "IDAG", count: 4u) != 0 )
  {
    return 0;
  }
  v5 = (studiohdr_t *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
  Studio_ConvertStudioHdrToNewVersion(pStudioHdr: v5);
  if ( v5->version != 49 )
    return 0;
  v6 = IsStaticProp(pHdr: v5);
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      _Warning(
        a1: "Error! To use model \"%s\"\n      with %s, it must be compiled with $staticprop!\n",
        pModelName,
        pEntityType);
      return 0;
    }
    if ( v6 == 2 )
      _Warning(
        a1: "Error! %s using model \"%s\", which must be used on a dynamic entity (i.e. prop_physics). Deleted.\n",
        pEntityType,
        pModelName);
    return 0;
  }
  v5->pVertexBase = nullptr;
  v5->pIndexBase = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D8C0
// Name: bool LoadVTXFile(char const __near *,struct studiohdr_t const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadVTXFile(const char *pModelName, const studiohdr_t *pStudioHdr, CUtlBuffer *buf)
{
  char *v3; // eax
  char v4; // cl
  IZip *PakFile; // eax
  int v7; // ecx
  int v8; // eax
  int checksum; // ecx
  char v10; // [esp-1h] [ebp-105h] BYREF
  char filename[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: pModelName, out: filename, outSize: 260);
  v3 = &v10;
  do
    v4 = *++v3;
  while ( v4 != 0 );
  strcpy(v3, ".dx90.vtx");
  PakFile = GetPakFile();
  if ( ReadFileFromPak(pak: PakFile, pRelativeName: filename, bTextMode: false, buf)
    || g_pFullFileSystem != nullptr
    && g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: filename,
         a3: nullptr,
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v7 = *(_DWORD *)buf->m_Memory.m_pMemory;
    if ( v7 == 7 )
    {
      v8 = *((_DWORD *)buf->m_Memory.m_pMemory + 4);
      checksum = pStudioHdr->checksum;
      if ( v8 == checksum )
      {
        return 1;
      }
      else
      {
        _Warning(a1: "Error! Invalid VTX file checksum: %d, expected %d \"%s\"\n", v8, checksum, filename);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error! Invalid VTX file version: %d, expected %d \"%s\"\n", v7, 7, filename);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error! Unable to load file \"%s\"\n", filename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DD40
// Name: ComputeLightingOrigin
// Source: json
//------------------------------------------------------------------------------
char __cdecl ComputeLightingOrigin(const StaticPropBuild_t *build, Vector *lightingOrigin)
{
  int v2; // edi
  int v3; // esi
  const char *v4; // eax

  v2 = s_LightingInfo.m_Size - 1;
  if ( s_LightingInfo.m_Size - 1 < 0 )
    return 0;
  while ( 1 )
  {
    v3 = s_LightingInfo.m_Memory.m_pMemory[v2];
    v4 = ValueForKey(ent: (entity_t *)&entities + v3, key: "targetname");
    if ( _V_strcmp(s1: v4, s2: build->m_pLightingOrigin) == 0 )
      break;
    if ( --v2 < 0 )
      return 0;
  }
  GetVectorForKey(ent: (entity_t *)&entities + v3, key: "origin", angle: (QAngle *)lightingOrigin);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042DDB0
// Name: public: void CStaticPropBuilder::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::Cleanup(CStaticPropBuilder *this)
{
  int v1; // ebx
  propbatch_list_t *m_pMemory; // esi
  int m; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( m = 0; m < this->m_modelList.m_Size; ++m )
  {
    m_pMemory = this->m_modelList.m_Memory.m_pMemory;
    if ( this->m_modelList.m_Memory.m_pMemory[v1].m_pPropIndices != nullptr )
    {
      free(pMem: this->m_modelList.m_Memory.m_pMemory[v1].m_pPropIndices);
      m_pMemory[v1].m_pPropIndices = nullptr;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA40
// Name: public: struct vertexFileHeader_t const __near * mstudiomodel_t::CacheVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::CacheVertexData(mstudiomodel_t *this, _DWORD *pModelData)
{
  const vertexFileHeader_t *result; // eax
  int v3; // eax
  int v4; // ecx
  char *v5; // eax
  int v6; // ecx
  const char *v7; // eax
  const char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char *v12; // eax
  char v13; // cl
  IMapDataFilesMgr *MapDataFilesMgr; // eax
  unsigned int m_Put; // esi
  vertexFileHeader_t *m_pMemory; // edi
  int version; // eax
  int checksum; // eax
  vertexFileHeader_t *v19; // esi
  bool v20; // sf
  char v21; // [esp-1h] [ebp-139h] BYREF
  char fileName[260]; // [esp+0h] [ebp-138h] BYREF
  CUtlBuffer bufFileData; // [esp+104h] [ebp-34h] BYREF
  int vvdSize; // [esp+134h] [ebp-4h]

  result = (const vertexFileHeader_t *)pModelData[92];
  if ( result == nullptr )
  {
    strcpy(fileName, "models/");
    v3 = pModelData[100];
    if ( v3 != 0
      && (v4 = *(_DWORD *)((char *)pModelData + v3 + 20), v5 = (char *)pModelData + v3, v4 != 0)
      && &v5[v4] != nullptr )
    {
      v6 = *((_DWORD *)v5 + 5);
      if ( v6 != 0 )
        v7 = &v5[v6];
      else
        v7 = nullptr;
    }
    else
    {
      v7 = (const char *)(pModelData + 3);
    }
    v8 = v7;
    v9 = strlen(v7) + 1;
    v10 = &v21;
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, v8, v9);
    V_StripExtension(in: fileName, out: fileName, outSize: 260);
    v12 = &v21;
    do
      v13 = *++v12;
    while ( v13 != 0 );
    strcpy(v12, ".vvd");
    CUtlBuffer::CUtlBuffer(this: &bufFileData, growSize: 0, initSize: 0, nFlags: 0);
    MapDataFilesMgr = GetMapDataFilesMgr();
    if ( !MapDataFilesMgr->ReadRegisteredFile(this: MapDataFilesMgr, a2: fileName, a3: &bufFileData)
      && !g_pFileSystem->ReadFile(
            this: g_pFileSystem,
            a2: fileName,
            a3: nullptr,
            a4: &bufFileData,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      _Error(a1: "Unable to load vertex data \"%s\"\n", fileName);
    }
    m_Put = bufFileData.m_Put;
    vvdSize = bufFileData.m_Put;
    if ( bufFileData.m_Put == 0 )
      _Error(a1: "Bad size for vertex data \"%s\"\n", fileName);
    m_pMemory = (vertexFileHeader_t *)bufFileData.m_Memory.m_pMemory;
    if ( *(_DWORD *)bufFileData.m_Memory.m_pMemory != 1448297545 )
      _Error(
        a1: "Error Vertex File %s id %d should be %d\n",
        fileName,
        *(_DWORD *)bufFileData.m_Memory.m_pMemory,
        1448297545);
    version = m_pMemory->version;
    if ( version != 4 )
      _Error(a1: "Error Vertex File %s version %d should be %d\n", fileName, version, 4);
    checksum = m_pMemory->checksum;
    if ( checksum != pModelData[2] )
      _Error(a1: "Error Vertex File %s checksum %d should be %d\n", fileName, checksum, pModelData[2]);
    v19 = (vertexFileHeader_t *)MemAlloc_Alloc(nSize: m_Put);
    if ( v19 == nullptr )
      _Error(a1: "Error allocating %d bytes for Vertex File '%s'\n", vvdSize, fileName);
    Studio_LoadVertexes(pTempVvdHdr: m_pMemory, pNewVvdHdr: v19, rootLOD: 0, bNeedsTangentS: true);
    v20 = bufFileData.m_Memory.m_nGrowSize < 0;
    pModelData[92] = v19;
    if ( !v20 && bufFileData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFileData.m_Memory.m_pMemory);
    return v19;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042FB50
// Name: FindInModelCache
// Source: json
//------------------------------------------------------------------------------
int __usercall FindInModelCache@<eax>(const char *pModelName@<edi>, ModelCollisionLookup_t *lookup)
{
  void *v2; // esp
  _BYTE *v3; // eax
  char v5[6]; // [esp+0h] [ebp-8h] BYREF
  CUtlSymbol v6; // [esp+6h] [ebp-2h] BYREF

  v2 = alloca(strlen(pModelName) + 1);
  strcpy(v5, pModelName);
  strlwr(string: v5);
  strchr(string: (unsigned __int8 *)v5, chr: 0x5Cu);
  while ( v3 != nullptr )
  {
    *v3 = 47;
    strchr(string: (unsigned __int8 *)v5, chr: 0x5Cu);
  }
  CUtlSymbol::CUtlSymbol(this: &v6, pStr: v5);
  lookup->m_Name = v6;
  lookup->m_pVtxFile = nullptr;
  lookup->m_pStudioHdr = nullptr;
  return CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Find(
           this: &s_ModelCollisionCache,
           search: lookup);
}

//------------------------------------------------------------------------------
// Address: 0x0042FBE0
// Name: SetLumpData_0
// Source: json
//------------------------------------------------------------------------------
void SetLumpData_0()
{
  unsigned __int16 GameLumpHandle; // si
  int v1; // edi
  int v2; // esi
  int v3; // ebx
  unsigned __int16 GameLump; // ax
  const void *v5; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-34h] BYREF
  int leafsize; // [esp+3Ch] [ebp-4h]

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1936749168);
  if ( GameLumpHandle != CGameLump::InvalidGameLump(this: &g_GameLumps) )
    CGameLump::DestroyGameLump(this: &g_GameLumps, handle: GameLumpHandle);
  v1 = 72 * s_StaticPropLump.m_Size;
  leafsize = 2 * s_StaticPropLeafLump.m_Size;
  v2 = s_StaticPropDictLump.m_Size << 7;
  v3 = 72 * s_StaticPropLump.m_Size + 2 * s_StaticPropLeafLump.m_Size + (s_StaticPropDictLump.m_Size << 7) + 12;
  GameLump = CGameLump::CreateGameLump(this: &g_GameLumps, id: 1936749168, size: v3, flags: 0, version: 9);
  v5 = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLump);
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v5, nSize: v3, nFlags: 0);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_StaticPropDictLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_StaticPropDictLump.m_Size);
  if ( v2 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_StaticPropDictLump.m_Memory.m_pMemory, size: v2);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_StaticPropLeafLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_StaticPropLeafLump.m_Size);
  if ( leafsize != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_StaticPropLeafLump.m_Memory.m_pMemory, size: leafsize);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", s_StaticPropLump.m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: s_StaticPropLump.m_Size);
  if ( v1 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: s_StaticPropLump.m_Memory.m_pMemory, size: v1);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0042FEA0
// Name: AddStaticPropDictLump
// Source: json
//------------------------------------------------------------------------------
int __usercall AddStaticPropDictLump@<eax>(char *pModelName@<eax>)
{
  int m_Size; // eax
  int v2; // esi
  char *v3; // edi
  unsigned int v4; // edx
  StaticPropDictLump_t *i; // ecx
  int v6; // ebx
  int v7; // eax
  StaticPropDictLump_t *v8; // edi
  StaticPropDictLump_t dictLump; // [esp+Ch] [ebp-80h] BYREF

  strncpy(dest: (unsigned __int8 *)&dictLump, source: (unsigned __int8 *)pModelName, count: 0x80u);
  m_Size = s_StaticPropDictLump.m_Size;
  v2 = s_StaticPropDictLump.m_Size - 1;
  if ( s_StaticPropDictLump.m_Size - 1 >= 0 )
  {
    v3 = &s_StaticPropDictLump.m_Memory.m_pMemory->m_Name[(v2 << 7) - (_DWORD)&dictLump];
    while ( 2 )
    {
      v4 = 128;
      for ( i = &dictLump; ; i = (StaticPropDictLump_t *)((char *)i + 4) )
      {
        if ( v4 < 4 )
          return v2;
        if ( *(_DWORD *)&i->m_Name[(_DWORD)v3] != *(_DWORD *)i->m_Name )
          break;
        v4 -= 4;
      }
      v3 -= 128;
      if ( --v2 >= 0 )
        continue;
      break;
    }
  }
  v6 = s_StaticPropDictLump.m_Size;
  if ( s_StaticPropDictLump.m_Size + 1 > s_StaticPropDictLump.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<StaticPropDictLump_t,int>::Grow(
      this: (CUtlMemory<DetailObjectDictLump_t,int> *)&s_StaticPropDictLump,
      num: s_StaticPropDictLump.m_Size - s_StaticPropDictLump.m_Memory.m_nAllocationCount + 1);
    m_Size = s_StaticPropDictLump.m_Size;
  }
  s_StaticPropDictLump.m_Size = m_Size + 1;
  v7 = m_Size - v6;
  s_StaticPropDictLump.m_pElements = s_StaticPropDictLump.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: &s_StaticPropDictLump.m_Memory.m_pMemory[v6 + 1],
      src: &s_StaticPropDictLump.m_Memory.m_pMemory[v6],
      count: v7 << 7);
  v8 = &s_StaticPropDictLump.m_Memory.m_pMemory[v6];
  if ( v8 != nullptr )
    *v8 = dictLump;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0042FF90
// Name: ComputeConvexHullLeaves_R
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeConvexHullLeaves_R(
        int node,
        int depth,
        int *pNodeList,
        const Vector *mins,
        const Vector *maxs,
        const Vector *origin,
        const QAngle *angles,
        struct CPhysCollide *pCollide,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafList)
{
  int v9; // edi
  const Vector *v10; // ecx
  dnode_t *v12; // esi
  float *p_x; // eax
  double v14; // st7
  float dist; // xmm3_4
  int m_nAllocationCount; // eax
  unsigned __int16 v17; // cx
  int m_Size; // edi
  unsigned __int16 v19; // bx
  unsigned __int16 *m_pMemory; // ecx
  int v21; // eax
  unsigned __int16 *v22; // eax
  Vector cornermin; // [esp+Ch] [ebp-2Ch] BYREF
  Vector cornermax; // [esp+18h] [ebp-20h] BYREF
  dplane_t *pPlane; // [esp+24h] [ebp-14h]
  char *v26; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int v28; // [esp+30h] [ebp-8h]
  int v29; // [esp+34h] [ebp-4h]
  int nodea; // [esp+40h] [ebp+8h]

  v9 = node;
  if ( node >= 0 )
  {
    v10 = maxs;
    nodea = (char *)&cornermin - (char *)maxs;
    v29 = (char *)mins - (char *)maxs;
    v28 = (char *)&cornermax - (char *)maxs;
    do
    {
      v12 = &dnodes[v9];
      pPlane = &dplanes[v12->planenum];
      p_x = &v10->x;
      v26 = (char *)((char *)pPlane - (char *)v10);
      for ( i = 3; i != 0; --i )
      {
        if ( *(float *)((char *)p_x + (_DWORD)v26) < 0.0 )
        {
          *(float *)((char *)p_x + nodea) = *p_x;
          v14 = *(float *)((char *)p_x + v29);
        }
        else
        {
          *(float *)((char *)p_x + nodea) = *(float *)((char *)p_x + v29);
          v14 = *p_x;
        }
        *(float *)((char *)p_x++ + v28) = v14;
      }
      dist = pPlane->dist;
      if ( dist < (float)((float)((float)(pPlane->normal.x * cornermax.x) + (float)(pPlane->normal.y * cornermax.y))
                        + (float)(pPlane->normal.z * cornermax.z)) )
      {
        if ( (float)((float)((float)(pPlane->normal.x * cornermin.x) + (float)(pPlane->normal.y * cornermin.y))
                   + (float)(pPlane->normal.z * cornermin.z)) < dist )
        {
          pNodeList[depth++] = v9;
          ComputeConvexHullLeaves_R(
            node: v12->children[1],
            depth,
            pNodeList,
            mins,
            maxs: v10,
            origin,
            angles,
            pCollide,
            leafList);
          pNodeList[depth - 1] = -1 - v9;
          v10 = maxs;
        }
        else
        {
          pNodeList[depth++] = -1 - v9;
        }
        v9 = v12->children[0];
      }
      else
      {
        pNodeList[depth] = v9;
        v9 = v12->children[1];
        ++depth;
      }
    }
    while ( v9 >= 0 );
  }
  if ( (dleafs[-v9 - 1].contents & 1) == 0 )
  {
    m_nAllocationCount = leafList->m_Memory.m_nAllocationCount;
    v17 = -1 - v9;
    m_Size = leafList->m_Size;
    v19 = v17;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
        this: (CUtlMemory<short,int> *)leafList,
        num: m_Size - m_nAllocationCount + 1);
    ++leafList->m_Size;
    m_pMemory = leafList->m_Memory.m_pMemory;
    v21 = leafList->m_Size - m_Size - 1;
    leafList->m_pElements = leafList->m_Memory.m_pMemory;
    if ( v21 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v21);
    v22 = &leafList->m_Memory.m_pMemory[m_Size];
    if ( v22 != nullptr )
      *v22 = v19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004301C0
// Name: ComputeConvexHull
// Source: json
//------------------------------------------------------------------------------
CPhysConvex *__cdecl ComputeConvexHull(int vertexCount, const mstudio_meshvertexdata_t *vertData)
{
  int v2; // esi
  Vector **v3; // edi
  float *p_z; // ecx
  float *v5; // edx
  float *v6; // eax
  Vector **m_pMemory; // edx
  CPhysConvex *v8; // ebx
  CUtlVector<Vector,CUtlMemory<Vector,int> > vertCopy; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlVector<Vector *,CUtlMemory<Vector *,int> > ppVerts; // [esp+20h] [ebp-28h] BYREF
  float v12; // [esp+34h] [ebp-14h]
  float v13; // [esp+38h] [ebp-10h]
  float v14; // [esp+3Ch] [ebp-Ch]
  int v15; // [esp+40h] [ebp-8h]
  int v16; // [esp+44h] [ebp-4h]

  v2 = 0;
  v3 = nullptr;
  memset(&vertCopy, 0, sizeof(vertCopy));
  memset(&ppVerts, 0, sizeof(ppVerts));
  if ( vertexCount > 0 )
  {
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&vertCopy,
      elem: 0,
      num: vertexCount);
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&ppVerts,
      elem: 0,
      num: vertexCount);
    p_z = &vertCopy.m_Memory.m_pMemory->z;
    do
    {
      v5 = (float *)((char *)vertData->modelvertexdata->pVertexData
                   + 48
                   * ((int)vertData[-1].modelvertexdata
                    + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30
                    + v2)
                   + 16);
      v6 = p_z - 2;
      *v6 = *v5;
      *(p_z - 1) = v5[1];
      *p_z = v5[2];
      v14 = *(p_z - 2);
      *v6 = (float)(int)v14;
      v13 = *(p_z - 1);
      v16 = (int)v13;
      *(p_z - 1) = (float)v16;
      v12 = *p_z;
      v15 = (int)v12;
      m_pMemory = ppVerts.m_Memory.m_pMemory;
      *p_z = (float)v15;
      m_pMemory[v2++] = (Vector *)(p_z - 2);
      p_z += 3;
    }
    while ( v2 < vertexCount );
    v3 = m_pMemory;
  }
  v8 = s_pPhysCollision->ConvexFromVerts(this: s_pPhysCollision, a2: v3, a3: vertexCount);
  if ( ppVerts.m_Memory.m_nGrowSize >= 0 && v3 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
  if ( vertCopy.m_Memory.m_nGrowSize >= 0 && vertCopy.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertCopy.m_Memory.m_pMemory);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00430310
// Name: ComputeConvexHull_0
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__usercall ComputeConvexHull_0@<eax>(CUtlBuffer *vtxFile@<eax>, studiohdr_t *pStudioHdr)
{
  studiohdr_t *v2; // edx
  int m_Size; // ebx
  int v4; // ecx
  mstudiobodyparts_t *v5; // ecx
  int v6; // eax
  mstudiomodel_t *v7; // eax
  int v8; // esi
  int v9; // edi
  char *v10; // esi
  mstudiomodel_t *v11; // edi
  const vertexFileHeader_t *v12; // eax
  int vertexDataStart; // ecx
  char *v14; // ecx
  int tangentDataStart; // ecx
  char *v16; // eax
  char *v17; // eax
  const mstudio_meshvertexdata_t *v18; // eax
  int v19; // esi
  CPhysConvex **m_pMemory; // edi
  CPhysConvex **v21; // eax
  bool v22; // cc
  struct CPhysCollide *v23; // esi
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexHulls; // [esp+4h] [ebp-38h] BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+18h] [ebp-24h]
  CPhysConvex *v27; // [esp+1Ch] [ebp-20h]
  int bodyID; // [esp+20h] [ebp-1Ch]
  int v29; // [esp+24h] [ebp-18h]
  int modelID; // [esp+28h] [ebp-14h]
  mstudiomodel_t *pStudioModel; // [esp+2Ch] [ebp-10h]
  int nMesh; // [esp+30h] [ebp-Ch]
  int v33; // [esp+34h] [ebp-8h]
  int v34; // [esp+38h] [ebp-4h]

  v2 = pStudioHdr;
  if ( pStudioHdr == nullptr || vtxFile->m_Memory.m_pMemory == nullptr )
    return nullptr;
  m_Size = 0;
  memset(&convexHulls, 0, sizeof(convexHulls));
  bodyID = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v33 = 0;
    do
    {
      v4 = v33 + v2->bodypartindex;
      modelID = 0;
      v5 = (mstudiobodyparts_t *)((char *)v2 + v4);
      pBodyPart = v5;
      if ( v5->nummodels > 0 )
      {
        v6 = 0;
        v29 = 0;
        do
        {
          v7 = (mstudiomodel_t *)((char *)v5 + v6 + v5->modelindex);
          nMesh = 0;
          pStudioModel = v7;
          if ( v7->nummeshes > 0 )
          {
            v34 = 0;
            while ( 1 )
            {
              v8 = v34 + v7->meshindex;
              v9 = *(_DWORD *)&v7->name[v8 + 4];
              v10 = &v7->name[v8];
              v11 = (mstudiomodel_t *)&v10[v9];
              v12 = mstudiomodel_t::CacheVertexData(this: v11, pModelData: v2);
              if ( v12 != nullptr )
              {
                if ( v12->id == 1448297545 && (vertexDataStart = v12->vertexDataStart) != 0 )
                  v14 = (char *)v12 + vertexDataStart;
                else
                  v14 = nullptr;
                v11->vertexdata.pVertexData = v14;
                if ( v12->id == 1448297545 && (tangentDataStart = v12->tangentDataStart) != 0 )
                  v16 = (char *)v12 + tangentDataStart;
                else
                  v16 = nullptr;
                v11->vertexdata.pTangentData = v16;
              }
              v17 = &v10[*((_DWORD *)v10 + 1) + 108];
              *((_DWORD *)v10 + 12) = v17;
              v18 = *(_DWORD *)v17 != 0 ? (const mstudio_meshvertexdata_t *)(v10 + 48) : nullptr;
              v27 = ComputeConvexHull(vertexCount: v18->numLODVertexes[0], vertData: v18);
              v19 = m_Size;
              if ( m_Size + 1 > convexHulls.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&convexHulls,
                  num: m_Size - convexHulls.m_Memory.m_nAllocationCount + 1);
                m_Size = convexHulls.m_Size;
              }
              m_pMemory = convexHulls.m_Memory.m_pMemory;
              convexHulls.m_Size = ++m_Size;
              convexHulls.m_pElements = convexHulls.m_Memory.m_pMemory;
              if ( m_Size - v19 - 1 > 0 )
                _V_memmove(
                  dest: &convexHulls.m_Memory.m_pMemory[v19 + 1],
                  src: &convexHulls.m_Memory.m_pMemory[v19],
                  count: 4 * (m_Size - v19 - 1));
              v21 = &m_pMemory[v19];
              if ( v21 != nullptr )
                *v21 = v27;
              v34 += 116;
              v22 = nMesh + 1 < pStudioModel->nummeshes;
              v2 = pStudioHdr;
              ++nMesh;
              if ( !v22 )
                break;
              v7 = pStudioModel;
            }
            v5 = pBodyPart;
          }
          v6 = v29 + 148;
          ++modelID;
          v29 += 148;
        }
        while ( modelID < v5->nummodels );
      }
      v33 += 16;
      ++bodyID;
    }
    while ( bodyID < v2->numbodyparts );
  }
  v23 = s_pPhysCollision->ConvertConvexToCollide(this: s_pPhysCollision, a2: convexHulls.m_Memory.m_pMemory, a3: m_Size);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&convexHulls);
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x004304E0
// Name: private: int CStaticPropBuilder::FindOrAddModel(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStaticPropBuilder::FindOrAddModel(CStaticPropBuilder *this, int nModelIndex)
{
  int m_Size; // edi
  int result; // eax
  propbatch_list_t *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  propbatch_list_t *v7; // ecx
  int v8; // eax
  propbatch_list_t *v9; // eax

  m_Size = this->m_modelList.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_modelList.m_Memory.m_pMemory;
  while ( m_pMemory->m_nModelIndex != nModelIndex )
  {
    ++result;
    ++m_pMemory;
    if ( result >= m_Size )
      goto LABEL_7;
  }
  if ( result < 0 )
  {
LABEL_7:
    m_nAllocationCount = this->m_modelList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
        (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *)this,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_modelList.m_Size;
    v7 = this->m_modelList.m_Memory.m_pMemory;
    v8 = this->m_modelList.m_Size - m_Size - 1;
    this->m_modelList.m_pElements = this->m_modelList.m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[m_Size + 1], src: &v7[m_Size], count: 24 * v8);
    v9 = &this->m_modelList.m_Memory.m_pMemory[m_Size];
    v9->m_nModelIndex = nModelIndex;
    v9->m_nPropCount = 0;
    v9->m_nBatchCount = 0;
    v9->m_nFirstBatch = 0;
    v9->m_nCurrentProp = 0;
    v9->m_pPropIndices = nullptr;
    return m_Size;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430580
// Name: private: void CStaticPropBuilder::AddBatchesFromModel(int,int __near *,struct studiohdr_t __near *,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::AddBatchesFromModel(
        CStaticPropBuilder *this,
        int nModelOutputIndex,
        int *pTextureList,
        studiohdr_t *pStudioHdr,
        const mstudio_meshvertexdata_t *vtxFile,
        int nLod)
{
  unsigned __int8 *modelvertexdata; // edx
  studiohdr_t *v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // ecx
  OptimizedModel::BodyPartHeader_t *v11; // ebx
  int v12; // edx
  int v13; // ecx
  mstudiomodel_t *v14; // eax
  int v15; // esi
  int v16; // edi
  mstudiomesh_t *v17; // esi
  int *p_numStripGroups; // ebx
  mstudiomodel_t *v19; // edi
  const vertexFileHeader_t *v20; // eax
  int vertexDataStart; // ecx
  char *v22; // ecx
  int tangentDataStart; // ecx
  char *v24; // eax
  const mstudio_modelvertexdata_t *v25; // eax
  mstudio_meshvertexdata_t *p_vertexdata; // esi
  int v27; // eax
  unsigned int *v28; // esi
  propbatch_list_t *v29; // ebx
  int v30; // ecx
  int m_nAllocationCount; // eax
  CModelBatch *m_pMemory; // edx
  int v33; // eax
  int v34; // eax
  CModelBatch *v35; // ecx
  CModelBatch *v36; // edi
  char *v37; // eax
  int v38; // eax
  int v39; // edx
  int *v40; // eax
  int v41; // ecx
  int v42; // edx
  int v43; // ebx
  const mstudio_modelvertexdata_t *v44; // ecx
  unsigned int v45; // eax
  float *v46; // edx
  BaseWorldVertex_t *m_pVertex; // eax
  float *v48; // eax
  BaseWorldVertex_t *v49; // edx
  int p_m_vNormal; // edx
  int v51; // xmm1_4
  _DWORD *p_x; // eax
  unsigned __int8 *pVtxHdr; // [esp+4h] [ebp-5Ch]
  mstudiobodyparts_t *pBodyPart; // [esp+8h] [ebp-58h]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+10h] [ebp-50h]
  mstudiomesh_t *pMesh; // [esp+14h] [ebp-4Ch]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+20h] [ebp-40h]
  int bodyID; // [esp+24h] [ebp-3Ch]
  int modelID; // [esp+28h] [ebp-38h]
  mstudiomodel_t *pStudioModel; // [esp+2Ch] [ebp-34h]
  int nMesh; // [esp+30h] [ebp-30h]
  OptimizedModel::MeshHeader_t *pVtxMesh; // [esp+34h] [ebp-2Ch]
  int nGroup; // [esp+38h] [ebp-28h]
  int v65; // [esp+3Ch] [ebp-24h]
  signed int v66; // [esp+3Ch] [ebp-24h]
  int nStrip; // [esp+40h] [ebp-20h]
  int v68; // [esp+44h] [ebp-1Ch]
  int v69; // [esp+48h] [ebp-18h]
  int v70; // [esp+4Ch] [ebp-14h]
  int v71; // [esp+50h] [ebp-10h]
  int v72; // [esp+54h] [ebp-Ch]
  int i; // [esp+58h] [ebp-8h]
  int ia; // [esp+58h] [ebp-8h]
  int ib; // [esp+58h] [ebp-8h]
  int vertID; // [esp+5Ch] [ebp-4h]
  int vertIDa; // [esp+5Ch] [ebp-4h]
  const mstudio_meshvertexdata_t *vertData; // [esp+74h] [ebp+14h]

  modelvertexdata = (unsigned __int8 *)vtxFile->modelvertexdata;
  v7 = pStudioHdr;
  v8 = 0;
  pVtxHdr = (unsigned __int8 *)vtxFile->modelvertexdata;
  bodyID = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v68 = 0;
    do
    {
      v9 = (int)v7 + v68 + v7->bodypartindex;
      v10 = 0;
      v11 = (OptimizedModel::BodyPartHeader_t *)&modelvertexdata[8 * v8 + *((_DWORD *)modelvertexdata + 8)];
      pVtxBodyPart = v11;
      pBodyPart = (mstudiobodyparts_t *)v9;
      modelID = 0;
      if ( *(int *)(v9 + 4) > 0 )
      {
        v12 = 12 * nLod;
        v69 = 0;
        do
        {
          v13 = (int)&v11[v10] + v11->modelOffset + v12 + *(int *)((char *)&v11[v10].modelOffset + v11->modelOffset);
          v14 = (mstudiomodel_t *)(v9 + v69 + *(_DWORD *)(v9 + 12));
          pStudioModel = v14;
          pVtxLOD = (OptimizedModel::ModelLODHeader_t *)v13;
          nMesh = 0;
          if ( v14->nummeshes > 0 )
          {
            v70 = 0;
            v71 = 0;
            while ( 1 )
            {
              v15 = v71 + v14->meshindex;
              v16 = *(_DWORD *)&v14->name[v15 + 4];
              v17 = (mstudiomesh_t *)&v14->name[v15];
              p_numStripGroups = (int *)(v13 + v70 + *(_DWORD *)(v13 + 4));
              v19 = (mstudiomodel_t *)((char *)v17 + v16);
              pMesh = v17;
              pVtxMesh = (OptimizedModel::MeshHeader_t *)p_numStripGroups;
              v20 = mstudiomodel_t::CacheVertexData(this: v19, pModelData: pStudioHdr);
              if ( v20 != nullptr )
              {
                if ( v20->id == 1448297545 && (vertexDataStart = v20->vertexDataStart) != 0 )
                  v22 = (char *)v20 + vertexDataStart;
                else
                  v22 = nullptr;
                v19->vertexdata.pVertexData = v22;
                if ( v20->id == 1448297545 && (tangentDataStart = v20->tangentDataStart) != 0 )
                  v24 = (char *)v20 + tangentDataStart;
                else
                  v24 = nullptr;
                v19->vertexdata.pTangentData = v24;
              }
              v25 = (const mstudio_modelvertexdata_t *)((char *)&v17->unused[6] + v17->modelindex);
              p_vertexdata = &v17->vertexdata;
              p_vertexdata->modelvertexdata = v25;
              vertData = v25->pVertexData != nullptr ? p_vertexdata : nullptr;
              nGroup = 0;
              if ( *p_numStripGroups > 0 )
              {
                v27 = nModelOutputIndex;
                v72 = 0;
                while ( 1 )
                {
                  v28 = (unsigned int *)((char *)p_numStripGroups + v72 + p_numStripGroups[1]);
                  v29 = &this->m_modelList.m_Memory.m_pMemory[v27];
                  if ( v29->m_nBatchCount == 0 )
                    v29->m_nFirstBatch = this->m_batchList.m_Size;
                  m_nAllocationCount = this->m_batchList.m_Memory.m_nAllocationCount;
                  i = this->m_batchList.m_Size;
                  v30 = i;
                  if ( i + 1 > m_nAllocationCount )
                  {
                    CUtlMemory<CSpotLight,int>::Grow(
                      this: (CUtlMemory<CSpotLight,int> *)&this->m_batchList,
                      num: i - m_nAllocationCount + 1);
                    v30 = i;
                  }
                  ++this->m_batchList.m_Size;
                  m_pMemory = this->m_batchList.m_Memory.m_pMemory;
                  v33 = this->m_batchList.m_Size - v30 - 1;
                  this->m_batchList.m_pElements = m_pMemory;
                  if ( v33 > 0 )
                  {
                    _V_memmove(dest: &m_pMemory[v30 + 1], src: &m_pMemory[v30], count: 84 * v33);
                    v30 = i;
                  }
                  v34 = v30;
                  v35 = &this->m_batchList.m_Memory.m_pMemory[v30];
                  if ( v35 != nullptr )
                  {
                    v35->m_nIndexCount = 0;
                    v35->m_nVertexCount = 0;
                    v35->m_nMaterial = 0;
                    v35->m_pIndex = nullptr;
                    v35->m_pVertex = nullptr;
                  }
                  ++v29->m_nBatchCount;
                  v36 = &this->m_batchList.m_Memory.m_pMemory[v34];
                  CModelBatch::Init(
                    this: v36,
                    nIndexCount: v28[2],
                    nVertexCount: *v28,
                    nTextureIndex: pTextureList[pMesh->material]);
                  v37 = studiohdr_t::pszName(this: pStudioHdr);
                  V_strncpy(pDest: v36->m_pPropName, pSrc: v37, maxLen: 64);
                  v38 = 0;
                  v39 = 0;
                  vertID = 0;
                  nStrip = 0;
                  if ( (int)v28[4] > 0 )
                  {
                    v65 = 0;
                    do
                    {
                      v40 = (int *)((char *)v28 + v38 + v28[5]);
                      v41 = 0;
                      ia = 0;
                      if ( *v40 > 0 )
                      {
                        v42 = v39;
                        do
                        {
                          v36->m_pIndex[v42] = v40[1] + *(unsigned __int16 *)((char *)v28 + 2 * v41 + v28[3]);
                          v41 = ia + 1;
                          ++v42;
                          ia = v41;
                        }
                        while ( v41 < *v40 );
                        v39 = vertID;
                      }
                      v39 += *v40;
                      v38 = v65 + 35;
                      vertID = v39;
                      ++nStrip;
                      v65 += 35;
                    }
                    while ( nStrip < (int)v28[4] );
                  }
                  v43 = 0;
                  v66 = 0;
                  if ( (int)*v28 > 0 )
                  {
                    v44 = vertData->modelvertexdata;
                    ib = 0;
                    do
                    {
                      v45 = ib + v28[1];
                      ib += 9;
                      vertIDa = *(unsigned __int16 *)((char *)v28 + v45 + 4);
                      v46 = (float *)((char *)v44->pVertexData
                                    + 48
                                    * ((int)vertData[-1].modelvertexdata
                                     + (unsigned int)v44[-3].pVertexData / 0x30
                                     + vertIDa)
                                    + 16);
                      m_pVertex = v36->m_pVertex;
                      m_pVertex[v43].m_vPos.x = *v46;
                      m_pVertex[v43].m_vPos.y = v46[1];
                      m_pVertex[v43].m_vPos.z = v46[2];
                      v48 = (float *)((char *)v44->pVertexData
                                    + 48
                                    * ((int)vertData[-1].modelvertexdata
                                     + (unsigned int)v44[-3].pVertexData / 0x30
                                     + vertIDa)
                                    + 28);
                      v49 = v36->m_pVertex;
                      v49[v43].m_vNormal.x = *v48;
                      p_m_vNormal = (int)&v49[v43].m_vNormal;
                      *(float *)(p_m_vNormal + 4) = v48[1];
                      *(float *)(p_m_vNormal + 8) = v48[2];
                      v51 = *((_DWORD *)v44->pVertexData
                            + 12
                            * ((int)vertData[-1].modelvertexdata + (unsigned int)v44[-3].pVertexData / 0x30 + vertIDa)
                            + 11);
                      p_x = (_DWORD *)&v36->m_pVertex[v43].m_vTexcoord.x;
                      *p_x = *((_DWORD *)v44->pVertexData
                             + 12
                             * ((int)vertData[-1].modelvertexdata + (unsigned int)v44[-3].pVertexData / 0x30 + vertIDa)
                             + 10);
                      p_x[1] = v51;
                      p_x[2] = 0;
                      ++v43;
                      ++v66;
                    }
                    while ( v66 < (int)*v28 );
                  }
                  v72 += 33;
                  if ( ++nGroup >= pVtxMesh->numStripGroups )
                    break;
                  v27 = nModelOutputIndex;
                  p_numStripGroups = &pVtxMesh->numStripGroups;
                }
              }
              v71 += 116;
              v70 += 9;
              if ( ++nMesh >= pStudioModel->nummeshes )
                break;
              v14 = pStudioModel;
              v13 = (int)pVtxLOD;
            }
            v11 = pVtxBodyPart;
            v12 = 12 * nLod;
            v9 = (int)pBodyPart;
          }
          v69 += 148;
          v10 = modelID + 1;
          modelID = v10;
        }
        while ( v10 < *(_DWORD *)(v9 + 4) );
        v7 = pStudioHdr;
        modelvertexdata = pVtxHdr;
        v8 = bodyID;
      }
      v68 += 16;
      bodyID = ++v8;
    }
    while ( v8 < v7->numbodyparts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430950
// Name: public: void CStaticPropBuilder::AddInstances(class CBVHNodeBuilder __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::AddInstances(
        CStaticPropBuilder *this,
        CBVHNodeBuilder *rootNode,
        CUtlVector<int,CUtlMemory<int,int> > *propList,
        bool bFlipWinding)
{
  propbatch_list_t *v4; // ebx
  InstanceGeometry_t *v5; // esi
  int m_nBatchCount; // edi
  int v7; // ecx
  int *v8; // eax
  int v9; // eax
  int v10; // edi
  int v11; // edi
  int v12; // ebx
  unsigned int StrideForInputLayout; // eax
  CBuilderMesh *v14; // edx
  unsigned int *m_pIndices; // ecx
  int v16; // eax
  char *key; // ebx
  int v18; // eax
  int m_nMeshes; // edi
  CMesh **m_pMemory; // ecx
  int v21; // eax
  int v22; // edx
  CMesh **v23; // eax
  int v24; // edi
  StaticPropLump_t *v25; // eax
  matrix3x4_t *v26; // edi
  CMeshVertexAttribute *AttributesForInputLayout; // [esp-14h] [ebp-28Ch]
  int AttributeCountForInputLayout; // [esp-10h] [ebp-288h]
  char pDMXName[260]; // [esp+0h] [ebp-278h] BYREF
  char pFileName[260]; // [esp+104h] [ebp-174h] BYREF
  matrix3x4_t xform; // [esp+208h] [ebp-70h] BYREF
  CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int> > propTransforms; // [esp+238h] [ebp-40h] BYREF
  propbatch_list_t *pModel; // [esp+24Ch] [ebp-2Ch]
  int p; // [esp+250h] [ebp-28h]
  unsigned int v35; // [esp+254h] [ebp-24h]
  int v36; // [esp+258h] [ebp-20h]
  CUtlVector<CMesh *,CUtlMemory<CMesh *,int> > saveMeshes; // [esp+25Ch] [ebp-1Ch] BYREF
  CStaticPropBuilder *v38; // [esp+270h] [ebp-8h]
  int m; // [esp+274h] [ebp-4h]

  v38 = this;
  p = 0;
  if ( this->m_modelList.m_Size > 0 )
  {
    v35 = 0;
    do
    {
      pModel = &this->m_modelList.m_Memory.m_pMemory[v35 / 0x18];
      v4 = pModel;
      v5 = (InstanceGeometry_t *)MemAlloc_Alloc(nSize: 0x15Cu);
      v5->m_pOriginalModelName[0] = 0;
      m_nBatchCount = v4->m_nBatchCount;
      v7 = (372 * (unsigned __int64)(unsigned int)m_nBatchCount) >> 32 != 0;
      v5->m_nMeshes = m_nBatchCount;
      v8 = (int *)MemAlloc_Alloc(nSize: __CFADD__((372 * m_nBatchCount) | -v7, 4) ? -1 : ((372 * m_nBatchCount) | -v7)
                                                                                       + 4);
      if ( v8 != nullptr )
      {
        *v8 = m_nBatchCount;
        v9 = (int)(v8 + 1);
        v10 = m_nBatchCount - 1;
        v36 = v9;
        m = v9;
        if ( v10 >= 0 )
        {
          do
          {
            CBuilderMesh::CBuilderMesh(this: (CBuilderMesh *)m);
            m += 372;
            --v10;
          }
          while ( v10 >= 0 );
          v9 = v36;
        }
      }
      else
      {
        v9 = 0;
      }
      v5->m_pMeshes = (CBuilderMesh *)v9;
      v5->m_flMinCameraDistance = 1000.0;
      v5->m_pNextLOD = nullptr;
      v5->m_pEntryCounts = nullptr;
      v5->m_ppEntries = nullptr;
      v5->m_pDMXFileName[0] = 0;
      memset(&propTransforms, 0, sizeof(propTransforms));
      m = 0;
      if ( v5->m_nMeshes > 0 )
      {
        v11 = 0;
        do
        {
          v12 = (int)&v38->m_batchList.m_Memory.m_pMemory[m + v4->m_nFirstBatch];
          if ( v5->m_pOriginalModelName[0] == 0 )
            V_strncpy(pDest: v5->m_pOriginalModelName, pSrc: (const char *)(v12 + 20), maxLen: 64);
          v5->m_pMeshes[v11].m_Combo.m_nInputLayout = 0;
          v5->m_pMeshes[v11].m_Combo.m_nIndicesPerFace = 3;
          AttributeCountForInputLayout = GetAttributeCountForInputLayout(nLayout: 0);
          AttributesForInputLayout = GetAttributesForInputLayout(nLayout: 0);
          StrideForInputLayout = GetStrideForInputLayout(nLayout: 0);
          CMesh::AllocateAndCopyMesh(
            this: &v5->m_pMeshes[v11].m_mesh,
            nInputVertexCount: *(_DWORD *)(v12 + 4),
            pInputVerts: *(const float **)(v12 + 16),
            nInputIndexCount: *(_DWORD *)v12,
            pInputIndices: *(const unsigned int **)(v12 + 12),
            nVertexStride: StrideForInputLayout >> 2,
            pAttributes: AttributesForInputLayout,
            nAtrributeCount: AttributeCountForInputLayout);
          if ( bFlipWinding )
          {
            v14 = &v5->m_pMeshes[v11];
            m_pIndices = v14->m_mesh.m_pIndices;
            v16 = 0;
            if ( v14->m_mesh.m_nIndexCount > 0 )
            {
              do
              {
                v36 = m_pIndices[v16];
                m_pIndices[v16] = m_pIndices[v16 + 2];
                m_pIndices[v16 + 2] = v36;
                v16 += 3;
              }
              while ( v16 < v5->m_pMeshes[v11].m_mesh.m_nIndexCount );
            }
          }
          key = (char *)v38->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[*(_DWORD *)(v12 + 8)].m_Data.key;
          CUtlString::operator=(this: &v5->m_pMeshes[v11].m_mesh.m_materialName, src: key);
          if ( CreateMaterialFromVMT(pMaterialOut: &v5->m_pMeshes[v11].m_Material, pVMTName: key) == 0 )
            _Warning(a1: "Cannot load prop material %s\n", key);
          V_strncpy(
            pDest: v5->m_pMeshes[v11].m_Material.m_Material.m_szShaderVS,
            pSrc: "maps/worldgenericvs",
            maxLen: 48);
          V_strncpy(
            pDest: v5->m_pMeshes[v11].m_Material.m_Material.m_szShaderPS,
            pSrc: "maps/worldgenericps",
            maxLen: 48);
          v18 = m;
          v4 = pModel;
          v5->m_pMeshes[v11++].m_Material.m_Material.m_bInstanced = true;
          m = v18 + 1;
        }
        while ( v18 + 1 < v5->m_nMeshes );
      }
      V_FileBase(in: v5->m_pOriginalModelName, out: pFileName, maxlen: 260);
      V_StripExtension(in: pFileName, out: pFileName, outSize: 260);
      V_snprintf(pDest: pDMXName, maxLen: 260, pFormat: "maps/props/%s.dmx", pFileName);
      V_strncpy(pDest: v5->m_pDMXFileName, pSrc: pDMXName, maxLen: 260);
      m_nMeshes = v5->m_nMeshes;
      m_pMemory = nullptr;
      memset(&saveMeshes, 0, sizeof(saveMeshes));
      if ( m_nMeshes > 0 )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&saveMeshes, num: m_nMeshes);
        m_pMemory = saveMeshes.m_Memory.m_pMemory;
        saveMeshes.m_Size += m_nMeshes;
        saveMeshes.m_pElements = saveMeshes.m_Memory.m_pMemory;
        if ( saveMeshes.m_Size - m_nMeshes > 0 )
        {
          _V_memmove(
            dest: &saveMeshes.m_Memory.m_pMemory[m_nMeshes],
            src: saveMeshes.m_Memory.m_pMemory,
            count: 4 * (saveMeshes.m_Size - m_nMeshes));
          m_pMemory = saveMeshes.m_Memory.m_pMemory;
        }
      }
      v21 = 0;
      if ( v5->m_nMeshes > 0 )
      {
        v22 = 0;
        while ( 1 )
        {
          m_pMemory[v21++] = &v5->m_pMeshes[v22++].m_mesh;
          if ( v21 >= v5->m_nMeshes )
            break;
          m_pMemory = saveMeshes.m_Memory.m_pMemory;
        }
      }
      if ( !SaveMeshesToDMX(inputMeshes: &saveMeshes, pDMXFile: pDMXName, bForce2DTexcoords: true) )
        _Warning(a1: "Cannot save mesh to dmx!\n");
      v23 = saveMeshes.m_Memory.m_pMemory;
      v24 = 0;
      saveMeshes.m_Size = 0;
      if ( saveMeshes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( saveMeshes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: saveMeshes.m_Memory.m_pMemory);
          v23 = nullptr;
          saveMeshes.m_Memory.m_pMemory = nullptr;
        }
        saveMeshes.m_Memory.m_nAllocationCount = 0;
      }
      saveMeshes.m_pElements = v23;
      if ( saveMeshes.m_Memory.m_nGrowSize >= 0 && v23 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      if ( v4->m_nPropCount > 0 )
      {
        do
        {
          v25 = &s_StaticPropLump.m_Memory.m_pMemory[propList->m_Memory.m_pMemory[v4->m_pPropIndices[v24]]];
          AngleMatrix(angles: &v25->m_Angles, position: &v25->m_Origin, matrix: &xform);
          CUtlVector<matrix3x4_t,CUtlMemory<matrix3x4_t,int>>::InsertBefore(
            this: &propTransforms,
            elem: propTransforms.m_Size,
            src: &xform);
          ++v24;
        }
        while ( v24 < v4->m_nPropCount );
      }
      v26 = propTransforms.m_Memory.m_pMemory;
      CBVHNodeBuilder::AddInstances(
        this: rootNode,
        pInstanceGeometry: v5,
        nTransforms: propTransforms.m_Size,
        pTransforms: propTransforms.m_Memory.m_pMemory);
      if ( propTransforms.m_Memory.m_nGrowSize >= 0 && v26 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v26);
      this = v38;
      v35 += 24;
      ++p;
    }
    while ( p < v38->m_modelList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430DC0
// Name: GetCollisionModel
// Source: json
//------------------------------------------------------------------------------
struct CPhysCollide *__usercall GetCollisionModel@<eax>(const char *pModelName@<eax>)
{
  int v2; // eax
  studiohdr_t *v4; // esi
  CUtlBuffer *v5; // eax
  CUtlBuffer *v6; // eax
  struct CPhysCollide *v7; // eax
  unsigned int m_nAllocationCount; // esi
  struct CPhysCollide *m_pCollide; // esi
  CUtlBuffer buf; // [esp+4h] [ebp-40h] BYREF
  ModelCollisionLookup_t lookup; // [esp+34h] [ebp-10h] BYREF

  lookup.m_Name.m_Id = -1;
  v2 = FindInModelCache(pModelName, &lookup);
  if ( v2 != 0xFFFF )
    return s_ModelCollisionCache.m_Elements.m_pMemory[(unsigned __int16)v2].m_Data.m_pCollide;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( LoadStudioModel(pModelName, pEntityType: "prop_static", &buf) != 0 )
  {
    v4 = (studiohdr_t *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
    v5 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
    if ( v5 != nullptr )
      v6 = CUtlBuffer::CUtlBuffer(this: v5, growSize: 0, initSize: 0, nFlags: 0);
    else
      v6 = nullptr;
    lookup.m_pVtxFile = v6;
    LoadVTXFile(pModelName, pStudioHdr: v4, buf: v6);
    v7 = ComputeConvexHull_0(vtxFile: lookup.m_pVtxFile, pStudioHdr: v4);
    m_nAllocationCount = buf.m_Memory.m_nAllocationCount;
    lookup.m_pCollide = v7;
    lookup.m_pStudioHdr = (studiohdr_t *)MemAlloc_Alloc(nSize: buf.m_Memory.m_nAllocationCount);
    memcpy(dst: (unsigned __int8 *)lookup.m_pStudioHdr, src: buf.m_Memory.m_pMemory, count: m_nAllocationCount);
    CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Insert(
      this: &s_ModelCollisionCache,
      insert: &lookup);
    if ( lookup.m_pCollide == nullptr )
      _Warning(a1: "Bad geometry on \"%s\"!\n", pModelName);
    m_pCollide = lookup.m_pCollide;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return m_pCollide;
  }
  else
  {
    _Warning(a1: "Error loading studio model \"%s\"!\n", pModelName);
    lookup.m_pCollide = nullptr;
    CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Insert(
      this: &s_ModelCollisionCache,
      insert: &lookup);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430F10
// Name: AddStaticPropToLump
// Source: json
//------------------------------------------------------------------------------
void __usercall AddStaticPropToLump(const StaticPropBuild_t *build@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  struct CPhysCollide *CollisionModel; // eax
  Vector *p_m_Origin; // ebx
  int v6; // esi
  int v7; // eax
  void (__thiscall *CollideGetAABB)(IPhysicsCollision *, Vector *, Vector *, const struct CPhysCollide *, const Vector *, const QAngle *); // edx
  bbox_t *m_pMemory; // ecx
  int v10; // eax
  Vector *p_maxs; // eax
  StaticPropLump_t *v12; // esi
  unsigned __int8 m_Flags; // al
  const char *m_pLightingOrigin; // eax
  int v15; // ebx
  int m_Size; // ecx
  unsigned __int16 v17; // di
  int v18; // esi
  StaticPropLeafLump_t *v19; // eax
  unsigned __int16 *v20; // eax
  int pNodeList[1024]; // [esp+38h] [ebp-104Ch] BYREF
  Vector maxs; // [esp+1038h] [ebp-4Ch] BYREF
  Vector mins; // [esp+1044h] [ebp-40h] BYREF
  _DWORD v25[3]; // [esp+1050h] [ebp-34h] BYREF
  _DWORD v26[3]; // [esp+105Ch] [ebp-28h] BYREF
  int v27; // [esp+1068h] [ebp-1Ch]
  struct CPhysCollide *pCollide; // [esp+106Ch] [ebp-18h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > leafList; // [esp+1070h] [ebp-14h] BYREF

  CollisionModel = GetCollisionModel(pModelName: build->m_pModelName);
  pCollide = CollisionModel;
  if ( CollisionModel != nullptr )
  {
    p_m_Origin = &build->m_Origin;
    memset(&leafList, 0, sizeof(leafList));
    ((void (__thiscall *)(IPhysicsCollision *, Vector *, Vector *, struct CPhysCollide *, Vector *, QAngle *, int, int))s_pPhysCollision->CollideGetAABB)(
      a1: s_pPhysCollision,
      a2: &mins,
      a3: &maxs,
      a4: CollisionModel,
      a5: &build->m_Origin,
      a6: &build->m_Angles,
      a7: a3,
      a8: a2);
    ComputeConvexHullLeaves_R(
      node: 0,
      depth: 0,
      pNodeList,
      &mins,
      &maxs,
      origin: &build->m_Origin,
      angles: &build->m_Angles,
      pCollide,
      &leafList);
    if ( leafList.m_Size == 0 )
      _Warning(
        a1: "Static prop %s outside the map (%.2f, %.2f, %.2f)\n",
        build->m_pModelName,
        p_m_Origin->x,
        build->m_Origin.y,
        build->m_Origin.z);
    v6 = CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int>>::AddToTail(this: &s_StaticPropLump);
    v7 = CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int>>::AddToTail(this: (CUtlVector<CDmElementDictionary::AttributeInfo_t,CUtlMemory<CDmElementDictionary::AttributeInfo_t,int> > *)&s_StaticPropBounds);
    CollideGetAABB = s_pPhysCollision->CollideGetAABB;
    v27 = v7;
    ((void (__thiscall *)(IPhysicsCollision *, _DWORD *, _DWORD *, struct CPhysCollide *))CollideGetAABB)(
      a1: s_pPhysCollision,
      a2: v25,
      a3: v26,
      a4: pCollide);
    m_pMemory = s_StaticPropBounds.m_Memory.m_pMemory;
    v10 = v27;
    LODWORD(s_StaticPropBounds.m_Memory.m_pMemory[v10].mins.x) = v25[0];
    LODWORD(m_pMemory[v10].mins.y) = v25[1];
    LODWORD(m_pMemory[v10].mins.z) = v25[2];
    p_maxs = &s_StaticPropBounds.m_Memory.m_pMemory[v10].maxs;
    LODWORD(p_maxs->x) = v26[0];
    LODWORD(p_maxs->y) = v26[1];
    LODWORD(p_maxs->z) = v26[2];
    v12 = &s_StaticPropLump.m_Memory.m_pMemory[v6];
    v12->m_PropType = AddStaticPropDictLump(pModelName: (char *)build->m_pModelName);
    v12->m_Origin.x = p_m_Origin->x;
    v12->m_Origin.y = build->m_Origin.y;
    v12->m_Origin.z = build->m_Origin.z;
    v12->m_Angles.x = build->m_Angles.x;
    v12->m_Angles.y = build->m_Angles.y;
    v12->m_Angles.z = build->m_Angles.z;
    v12->m_FirstLeaf = s_StaticPropLeafLump.m_Size;
    v12->m_LeafCount = leafList.m_Size;
    v12->m_Solid = build->m_Solid;
    v12->m_Skin = build->m_Skin;
    m_Flags = build->m_Flags;
    v12->m_Flags = m_Flags;
    if ( build->m_FadesOut )
      v12->m_Flags = m_Flags | 1;
    v12->m_FadeMinDist = build->m_FadeMinDist;
    v12->m_FadeMaxDist = build->m_FadeMaxDist;
    v12->m_flForcedFadeScale = build->m_flForcedFadeScale;
    v12->m_nMinCPULevel = build->m_nMinCPULevel;
    v12->m_nMaxCPULevel = build->m_nMaxCPULevel;
    v12->m_nMinGPULevel = build->m_nMinGPULevel;
    v12->m_nMaxGPULevel = build->m_nMaxGPULevel;
    v12->m_bDisableX360 = false;
    m_pLightingOrigin = build->m_pLightingOrigin;
    if ( m_pLightingOrigin != nullptr
      && *m_pLightingOrigin != 0
      && ComputeLightingOrigin(build, lightingOrigin: &v12->m_LightingOrigin) != 0 )
    {
      v12->m_Flags |= 2u;
    }
    v15 = 0;
    if ( leafList.m_Size > 0 )
    {
      m_Size = s_StaticPropLeafLump.m_Size;
      do
      {
        v17 = leafList.m_Memory.m_pMemory[v15];
        v18 = m_Size;
        if ( m_Size + 1 > s_StaticPropLeafLump.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
            this: (CUtlMemory<short,int> *)&s_StaticPropLeafLump,
            num: m_Size - s_StaticPropLeafLump.m_Memory.m_nAllocationCount + 1);
          m_Size = s_StaticPropLeafLump.m_Size;
        }
        s_StaticPropLeafLump.m_Size = ++m_Size;
        s_StaticPropLeafLump.m_pElements = s_StaticPropLeafLump.m_Memory.m_pMemory;
        if ( m_Size - v18 - 1 > 0 )
        {
          _V_memmove(
            dest: &s_StaticPropLeafLump.m_Memory.m_pMemory[v18 + 1],
            src: &s_StaticPropLeafLump.m_Memory.m_pMemory[v18],
            count: 2 * (m_Size - v18 - 1));
          m_Size = s_StaticPropLeafLump.m_Size;
        }
        v19 = &s_StaticPropLeafLump.m_Memory.m_pMemory[v18];
        if ( v19 != nullptr )
        {
          v19->m_Leaf = v17;
          m_Size = s_StaticPropLeafLump.m_Size;
        }
        ++v15;
      }
      while ( v15 < leafList.m_Size );
    }
    v20 = leafList.m_Memory.m_pMemory;
    leafList.m_Size = 0;
    if ( leafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( leafList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leafList.m_Memory.m_pMemory);
        v20 = nullptr;
        leafList.m_Memory.m_pMemory = nullptr;
      }
      leafList.m_Memory.m_nAllocationCount = 0;
    }
    leafList.m_pElements = v20;
    if ( leafList.m_Memory.m_nGrowSize >= 0 && v20 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431200
// Name: void EmitStaticProps(class CStaticPropList __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitStaticProps(CStaticPropList *list)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  int v2; // eax
  int v3; // edi
  entity_t *v4; // ebx
  const char *v5; // eax
  int m_Size; // esi
  int *v7; // eax
  entity_t *v8; // esi
  const char *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  char *v12; // eax
  double v13; // st7
  float m_FadeMaxDist; // xmm0_4
  int v15; // eax
  int *m_pMemory; // ecx
  int v17; // edx
  IMemAlloc_vtbl *v18; // edx
  staticpropelem_t *v19; // eax
  int v20; // edi
  int v21; // esi
  int m_nAllocationCount; // ecx
  staticpropleafref_t *v23; // ecx
  int v24; // eax
  int j; // eax
  int v26; // edi
  CStaticPropList *v27; // edx
  int v28; // esi
  int v29; // eax
  staticpropelem_t *v30; // ecx
  int v31; // eax
  bbox_t *v32; // ecx
  int v33; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v34; // esi
  float *v35; // ecx
  double v36; // st7
  int v37; // ecx
  StaticPropLump_t *v38; // eax
  int v39; // ecx
  int v40; // ecx
  int v41; // edx
  staticpropleafref_t *v42; // eax
  int *p_propCount; // eax
  int v44; // esi
  CUtlVector<int,CUtlMemory<int,int> > *p_leafProps; // edi
  int v46; // ecx
  int v47; // edx
  int *v48; // edx
  int v49; // eax
  int v50; // ecx
  int v51; // edx
  int v52; // esi
  staticpropleafref_t *v53; // eax
  int v54; // ecx
  StaticPropBuild_t build; // [esp+0h] [ebp-54h] BYREF
  int v56; // [esp+44h] [ebp-10h]
  int leafLumpIndex; // [esp+48h] [ebp-Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > *v58; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  PhysicsFactory = GetPhysicsFactory();
  if ( PhysicsFactory == nullptr
    || (s_pPhysCollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr),
        s_pPhysCollision != nullptr) )
  {
    _Msg(a1: "Adding static props to leaves...\n");
    v2 = num_entities;
    v3 = 0;
    if ( num_entities > 0 )
    {
      v4 = (entity_t *)&entities;
      do
      {
        v5 = ValueForKey(ent: v4, key: "classname");
        if ( _V_strcmp(s1: v5, s2: "info_lighting") == 0 )
        {
          m_Size = s_LightingInfo.m_Size;
          if ( s_LightingInfo.m_Size + 1 > s_LightingInfo.m_Memory.m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&s_LightingInfo,
              num: s_LightingInfo.m_Size - s_LightingInfo.m_Memory.m_nAllocationCount + 1);
          ++s_LightingInfo.m_Size;
          s_LightingInfo.m_pElements = s_LightingInfo.m_Memory.m_pMemory;
          if ( s_LightingInfo.m_Size - m_Size - 1 > 0 )
            _V_memmove(
              dest: &s_LightingInfo.m_Memory.m_pMemory[m_Size + 1],
              src: &s_LightingInfo.m_Memory.m_pMemory[m_Size],
              count: 4 * (s_LightingInfo.m_Size - m_Size - 1));
          v7 = &s_LightingInfo.m_Memory.m_pMemory[m_Size];
          if ( v7 != nullptr )
            *v7 = v3;
        }
        v2 = num_entities;
        ++v3;
        ++v4;
      }
      while ( v3 < num_entities );
    }
    i = 0;
    if ( v2 > 0 )
    {
      v8 = (entity_t *)&entities;
      while ( 1 )
      {
        v9 = ValueForKey(ent: v8, key: "classname");
        if ( strcmp(v9, "static_prop") != 0 && strcmp(v9, "prop_static") != 0 )
          goto LABEL_41;
        GetVectorForKey(ent: v8, key: "origin", angle: (QAngle *)&build.m_Origin);
        GetVectorForKey(ent: v8, key: "angles", angle: &build.m_Angles);
        build.m_pModelName = ValueForKey(ent: v8, key: "model");
        build.m_Solid = IntForKey(ent: v8, key: "solid");
        build.m_Skin = IntForKey(ent: v8, key: "skin");
        build.m_FadeMaxDist = FloatForKey(ent: v8, key: "fademaxdist");
        build.m_Flags = 0;
        build.m_nMinCPULevel = IntForKey(ent: v8, key: "mincpulevel");
        build.m_nMaxCPULevel = IntForKey(ent: v8, key: "maxcpulevel");
        build.m_nMinGPULevel = IntForKey(ent: v8, key: "mingpulevel");
        build.m_nMaxGPULevel = IntForKey(ent: v8, key: "maxgpulevel");
        v10 = ValueForKey(ent: v8, key: "rendercolor");
        if ( *v10 != 0 )
        {
          V_StringToColor32(color: (color32_s *)&leafLumpIndex, pString: v10);
          *(_WORD *)&build.m_DiffuseModulation.r = leafLumpIndex;
          build.m_DiffuseModulation.b = BYTE2(leafLumpIndex);
        }
        else
        {
          *(_WORD *)&build.m_DiffuseModulation.g = -1;
          build.m_DiffuseModulation.r = -1;
        }
        v11 = ValueForKey(ent: v8, key: "renderamt");
        if ( *v11 != 0 )
          build.m_DiffuseModulation.a = V_atoi(str: v11);
        else
          build.m_DiffuseModulation.a = -1;
        if ( IntForKey(ent: v8, key: "ignorenormals") == 1 )
          build.m_Flags |= 8u;
        if ( IntForKey(ent: v8, key: "disableshadows") == 1 )
          build.m_Flags |= 0x10u;
        if ( IntForKey(ent: v8, key: "disablevertexlighting") == 1 )
          build.m_Flags |= 0x40u;
        if ( IntForKey(ent: v8, key: "disableselfshadowing") == 1 )
          build.m_Flags |= 0x80u;
        v12 = ValueForKey(ent: v8, key: "fadescale");
        if ( v12 != nullptr && *v12 != 0 )
          build.m_flForcedFadeScale = FloatForKey(ent: v8, key: "fadescale");
        else
          build.m_flForcedFadeScale = 1.0;
        build.m_FadesOut = build.m_FadeMaxDist > 0.0;
        build.m_pLightingOrigin = ValueForKey(ent: v8, key: "lightingorigin");
        if ( !build.m_FadesOut )
          break;
        v13 = FloatForKey(ent: v8, key: "fademindist");
        build.m_FadeMinDist = v13;
        if ( v13 < 0.0 )
        {
          m_FadeMaxDist = build.m_FadeMaxDist;
LABEL_39:
          build.m_FadeMinDist = m_FadeMaxDist;
        }
        AddStaticPropToLump(&build, a2: 0, a3: (int)v8);
        v8->epairs = nullptr;
LABEL_41:
        ++v8;
        if ( ++i >= num_entities )
          goto LABEL_42;
      }
      m_FadeMaxDist = 0.0;
      goto LABEL_39;
    }
LABEL_42:
    v15 = s_LightingInfo.m_Size - 1;
    if ( s_LightingInfo.m_Size - 1 >= 0 )
    {
      m_pMemory = s_LightingInfo.m_Memory.m_pMemory;
      do
      {
        v17 = 44 * m_pMemory[v15--];
        *(_DWORD *)((char *)&unk_5CD4964 + v17) = 0;
      }
      while ( v15 >= 0 );
    }
    if ( list->props.m_Memory.m_nAllocationCount < s_StaticPropLump.m_Size && list->props.m_Memory.m_nGrowSize >= 0 )
    {
      list->props.m_Memory.m_nAllocationCount = s_StaticPropLump.m_Size;
      v18 = _g_pMemAlloc->__vftable;
      if ( list->props.m_Memory.m_pMemory != nullptr )
        v19 = (staticpropelem_t *)((int (__stdcall *)(staticpropelem_t *, int))v18->Realloc_2)(
                                    a1: list->props.m_Memory.m_pMemory,
                                    a2: 32 * s_StaticPropLump.m_Size);
      else
        v19 = (staticpropelem_t *)((int (__stdcall *)(int))v18->Alloc_2)(a1: 32 * s_StaticPropLump.m_Size);
      list->props.m_Memory.m_pMemory = v19;
    }
    list->props.m_pElements = list->props.m_Memory.m_pMemory;
    v20 = list->leafList.m_Size;
    if ( v20 < numleafs )
    {
      v21 = numleafs - v20;
      if ( numleafs != v20 )
      {
        m_nAllocationCount = list->leafList.m_Memory.m_nAllocationCount;
        leafLumpIndex = numleafs;
        if ( numleafs > m_nAllocationCount )
          CUtlMemory<CacheOptimizedKDNode,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&list->leafList,
            num: numleafs - m_nAllocationCount);
        list->leafList.m_Size += v21;
        v23 = list->leafList.m_Memory.m_pMemory;
        v24 = list->leafList.m_Size - v20 - v21;
        list->leafList.m_pElements = v23;
        if ( v24 > 0 && v21 > 0 )
          _V_memmove(dest: &v23[leafLumpIndex], src: &v23[v20], count: 8 * v24);
      }
    }
    for ( j = 0; j < numleafs; ++j )
    {
      list->leafList.m_Memory.m_pMemory[j].propStart = 0;
      list->leafList.m_Memory.m_pMemory[j].propCount = 0;
    }
    i = 0;
    if ( s_StaticPropLump.m_Size <= 0 )
    {
      v38 = s_StaticPropLump.m_Memory.m_pMemory;
    }
    else
    {
      v26 = 0;
      v58 = nullptr;
      v27 = list;
      do
      {
        v28 = v27->props.m_Size;
        v29 = v27->props.m_Memory.m_nAllocationCount;
        if ( v28 + 1 > v29 )
        {
          CUtlMemory<staticpropelem_t,int>::Grow(
            this: (CUtlMemory<CDmElementDictionary::DmIdPair_t,int> *)list,
            num: v28 - v29 + 1);
          v27 = list;
        }
        ++v27->props.m_Size;
        v30 = v27->props.m_Memory.m_pMemory;
        v31 = v27->props.m_Size - v28 - 1;
        v27->props.m_pElements = v27->props.m_Memory.m_pMemory;
        if ( v31 > 0 )
        {
          _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 32 * v31);
          v27 = list;
        }
        v32 = s_StaticPropBounds.m_Memory.m_pMemory;
        v33 = (int)&v27->props.m_Memory.m_pMemory[v28];
        v34 = v58;
        *(float *)v33 = *(float *)((char *)&s_StaticPropBounds.m_Memory.m_pMemory->mins.x + (unsigned int)v58);
        *(float *)(v33 + 4) = *(float *)((char *)&v34->m_Memory.m_nAllocationCount + (_DWORD)v32);
        *(float *)(v33 + 8) = *(float *)((char *)&v34->m_Memory.m_nGrowSize + (_DWORD)v32);
        v35 = (float *)((char *)&v34->m_Size + (unsigned int)s_StaticPropBounds.m_Memory.m_pMemory);
        *(float *)(v33 + 12) = *v35;
        *(float *)(v33 + 16) = v35[1];
        v36 = v35[2];
        v37 = i;
        *(float *)(v33 + 20) = v36;
        *(_DWORD *)(v33 + 24) = v37;
        *(_DWORD *)(v33 + 28) = s_StaticPropLump.m_Memory.m_pMemory[v26].m_PropType;
        v38 = s_StaticPropLump.m_Memory.m_pMemory;
        leafLumpIndex = s_StaticPropLump.m_Memory.m_pMemory[v26].m_FirstLeaf;
        v39 = 0;
        if ( s_StaticPropLump.m_Memory.m_pMemory[v26].m_LeafCount != 0 )
        {
          leafLumpIndex *= 2;
          do
          {
            ++list->leafList.m_Memory.m_pMemory[*(unsigned __int16 *)((char *)&s_StaticPropLeafLump.m_Memory.m_pMemory->m_Leaf
                                                                    + leafLumpIndex)].propCount;
            leafLumpIndex += 2;
            v38 = s_StaticPropLump.m_Memory.m_pMemory;
            ++v39;
          }
          while ( v39 < s_StaticPropLump.m_Memory.m_pMemory[v26].m_LeafCount );
        }
        v58 = (CUtlVector<int,CUtlMemory<int,int> > *)((char *)v58 + 24);
        ++v26;
        ++i;
      }
      while ( i < s_StaticPropLump.m_Size );
    }
    v40 = 0;
    v41 = 0;
    if ( numleafs > 0 )
    {
      do
      {
        list->leafList.m_Memory.m_pMemory[v41].propStart = v40;
        v42 = list->leafList.m_Memory.m_pMemory;
        v40 += v42[v41].propCount;
        p_propCount = &v42[v41++].propCount;
        *p_propCount = 0;
      }
      while ( v41 < numleafs );
      v38 = s_StaticPropLump.m_Memory.m_pMemory;
    }
    v44 = list->leafProps.m_Size;
    p_leafProps = &list->leafProps;
    v58 = &list->leafProps;
    if ( v44 < v40 )
    {
      v46 = v40 - v44;
      leafLumpIndex = v46;
      if ( v46 != 0 )
      {
        v47 = list->leafProps.m_Memory.m_nAllocationCount;
        i = v44 + v46;
        if ( v44 + v46 > v47 )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&list->leafProps,
            num: leafLumpIndex + v44 - v47);
          v46 = leafLumpIndex;
        }
        list->leafProps.m_Size += v46;
        v48 = p_leafProps->m_Memory.m_pMemory;
        v49 = list->leafProps.m_Size - v44 - v46;
        list->leafProps.m_pElements = list->leafProps.m_Memory.m_pMemory;
        if ( v49 > 0 && v46 > 0 )
          _V_memmove(dest: &v48[i], src: &v48[v44], count: 4 * v49);
        v38 = s_StaticPropLump.m_Memory.m_pMemory;
      }
    }
    v50 = 0;
    i = 0;
    if ( s_StaticPropLump.m_Size > 0 )
    {
      leafLumpIndex = 0;
      do
      {
        v56 = *(unsigned __int16 *)((char *)&v38->m_FirstLeaf + v50);
        v51 = 0;
        if ( *(unsigned __int16 *)((char *)&v38->m_LeafCount + v50) != 0 )
        {
          v52 = v56;
          do
          {
            v53 = &list->leafList.m_Memory.m_pMemory[s_StaticPropLeafLump.m_Memory.m_pMemory[v52].m_Leaf];
            v54 = v53->propStart + v53->propCount++;
            p_leafProps->m_Memory.m_pMemory[v54] = i;
            v38 = s_StaticPropLump.m_Memory.m_pMemory;
            v50 = leafLumpIndex;
            ++v51;
            ++v52;
            p_leafProps = v58;
          }
          while ( v51 < *(unsigned __int16 *)((char *)&s_StaticPropLump.m_Memory.m_pMemory->m_LeafCount + leafLumpIndex) );
        }
        v50 += 72;
        ++i;
        leafLumpIndex = v50;
      }
      while ( i < s_StaticPropLump.m_Size );
    }
    SetLumpData_0();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004318B0
// Name: private: void CStaticPropBuilder::ComputeInstances(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::ComputeInstances(CStaticPropBuilder *this)
{
  int Inorder; // eax
  int v3; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // eax
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  propbatch_list_t *v10; // ecx
  int v11; // eax
  int m_nMaterial; // eax
  int v13; // eax
  int v14; // ecx
  propinstance_list_t *v15; // edx
  int v16; // ecx
  int v17; // ecx
  int v18; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int> *v19; // edi
  int v20; // eax
  int j; // [esp+Ch] [ebp-Ch]
  int ja; // [esp+Ch] [ebp-Ch]
  int nTotalInstances; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  int ia; // [esp+14h] [ebp-4h]

  nTotalInstances = 0;
  this->m_materialLinearList.m_Size = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_materialList.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v3 = 32 * Inorder;
      *(int *)((char *)&this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.m_nInstanceCount + v3) = 0;
      m_Size = this->m_materialLinearList.m_Size;
      m_nAllocationCount = this->m_materialLinearList.m_Memory.m_nAllocationCount;
      j = v3;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_materialLinearList,
          num: m_Size - m_nAllocationCount + 1);
        v3 = j;
      }
      ++this->m_materialLinearList.m_Size;
      m_pMemory = this->m_materialLinearList.m_Memory.m_pMemory;
      v7 = this->m_materialLinearList.m_Size - m_Size - 1;
      this->m_materialLinearList.m_pElements = m_pMemory;
      if ( v7 > 0 )
      {
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
        v3 = j;
      }
      v8 = &this->m_materialLinearList.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = i;
      *(int *)((char *)&this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.elem.m_nMaterialDictionaryIndex
             + v3) = m_Size;
      i = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::NextInorder(
            this: &this->m_materialList.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
  }
  v9 = 0;
  ia = 0;
  if ( this->m_modelList.m_Size > 0 )
  {
    v10 = this->m_modelList.m_Memory.m_pMemory;
    do
    {
      v11 = 0;
      for ( ja = 0; v11 < v10[v9].m_nBatchCount; ja = v11 )
      {
        m_nMaterial = this->m_batchList.m_Memory.m_pMemory[v11 + v10[v9].m_nFirstBatch].m_nMaterial;
        if ( m_nMaterial >= 0 )
        {
          this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[m_nMaterial].m_Data.elem.m_nInstanceCount += v10[v9].m_nPropCount;
          v10 = this->m_modelList.m_Memory.m_pMemory;
          nTotalInstances += this->m_modelList.m_Memory.m_pMemory[v9].m_nPropCount;
        }
        v11 = ja + 1;
      }
      ++v9;
      ++ia;
    }
    while ( ia < this->m_modelList.m_Size );
  }
  v13 = nTotalInstances;
  this->m_instanceList.m_Size = 0;
  if ( nTotalInstances != 0 )
  {
    v14 = this->m_instanceList.m_Memory.m_nAllocationCount;
    if ( nTotalInstances > v14 )
    {
      CUtlMemory<propinstance_list_t,int>::Grow(
        this: (CUtlMemory<CMDLAttachmentData,int> *)&this->m_instanceList,
        num: nTotalInstances - v14);
      v13 = nTotalInstances;
    }
    this->m_instanceList.m_Size += v13;
    v15 = this->m_instanceList.m_Memory.m_pMemory;
    v16 = this->m_instanceList.m_Size - v13;
    this->m_instanceList.m_pElements = v15;
    if ( v16 > 0 && v13 > 0 )
      _V_memmove(dest: &v15[v13], src: v15, count: 52 * v16);
  }
  v17 = 0;
  v18 = 0;
  if ( this->m_materialLinearList.m_Size > 0 )
  {
    v19 = this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      v20 = this->m_materialLinearList.m_Memory.m_pMemory[v18];
      v19[v20].m_Data.elem.m_nFirstInstance = v17;
      v19 = this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory;
      v17 += v19[v20].m_Data.elem.m_nInstanceCount;
      ++v18;
    }
    while ( v18 < this->m_materialLinearList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431A60
// Name: private: void CStaticPropBuilder::AddTexturesFromModel(int __near *,int,struct studiohdr_t __near *,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::AddTexturesFromModel(
        CStaticPropBuilder *this,
        int *pTextureList,
        int nTextureListMax,
        studiohdr_t *pStudioHdr,
        CUtlBuffer *vtxFile,
        int nLod)
{
  studiohdr_t *v6; // esi
  int numtextures; // eax
  CUtlDict<propmaterial_list_t,int> *p_m_materialList; // ebx
  int i; // edi
  char *TextureName; // eax
  int v11; // ecx
  char v12; // dl
  const char *v13; // ecx
  int v14; // eax
  char *v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // edi
  int v19; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int> *v20; // eax
  int v21; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int> *m_pMemory; // eax
  CUtlMap<char const *,propmaterial_list_t,int>::Node_t *p_m_Data; // eax
  CStaticPropBuilder *v24; // ecx
  char pathName[260]; // [esp+4h] [ebp-238h] BYREF
  char fileName[260]; // [esp+108h] [ebp-134h] BYREF
  CUtlMap<char const *,propmaterial_list_t,int>::Node_t search; // [esp+20Ch] [ebp-30h] BYREF
  CUtlMap<char const *,propmaterial_list_t,int>::Node_t insert; // [esp+21Ch] [ebp-20h] BYREF
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+22Ch] [ebp-10h]
  CStaticPropBuilder *v30; // [esp+230h] [ebp-Ch]
  int parent; // [esp+234h] [ebp-8h] BYREF
  int nTextureCount; // [esp+238h] [ebp-4h]
  int t; // [esp+248h] [ebp+Ch]

  v6 = pStudioHdr;
  numtextures = pStudioHdr->numtextures;
  pVtxHdr = (OptimizedModel::FileHeader_t *)vtxFile->m_Memory.m_pMemory;
  v30 = this;
  nTextureCount = nTextureListMax;
  if ( nTextureListMax >= numtextures )
    nTextureCount = numtextures;
  t = 0;
  if ( nTextureCount > 0 )
  {
    p_m_materialList = &this->m_materialList;
    do
    {
      for ( i = 0; i < v6->numcdtextures; ++i )
      {
        TextureName = GetTextureName(pVtxHeader: pVtxHdr, lodID: nLod, phdr: v6, inMaterialID: t);
        if ( *TextureName == 92 || *TextureName == 47 )
          ++TextureName;
        v11 = *(int *)((char *)&v6->id + 4 * i + v6->cdtextureindex);
        v12 = *((_BYTE *)&v6->id + v11);
        v13 = (char *)v6 + v11;
        if ( v12 == 92 || v12 == 47 )
          ++v13;
        V_ComposeFileName(path: v13, filename: TextureName, dest: fileName, destSize: 260);
        V_snprintf(pDest: pathName, maxLen: 260, pFormat: "materials\\%s.vmt", fileName);
        _V_strlower(start: pathName);
        V_FixSlashes(pname: pathName, separator: 92);
        if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pathName, a3: "GAME") )
          break;
      }
      search.key = fileName;
      v14 = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::Find(
              this: &p_m_materialList->m_Elements.m_Tree,
              &search);
      if ( v14 == -1 )
      {
        v15 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(fileName) + 1);
        if ( v15 != nullptr )
          strcpy(v15, fileName);
        else
          v15 = nullptr;
        insert.key = v15;
        parent = -1;
        HIBYTE(vtxFile) = 0;
        CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::FindInsertionPosition(
          this: &p_m_materialList->m_Elements.m_Tree,
          &insert,
          &parent,
          leftchild: (bool *)&vtxFile + 3);
        v16 = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::NewNode(this: &p_m_materialList->m_Elements.m_Tree);
        v17 = parent;
        v18 = v16;
        v19 = v16;
        v20 = &p_m_materialList->m_Elements.m_Tree.m_Elements.m_pMemory[v16];
        v20->m_Parent = parent;
        v20->m_Right = -1;
        v20->m_Left = -1;
        v20->m_Tag = 0;
        if ( v17 == -1 )
        {
          p_m_materialList->m_Elements.m_Tree.m_Root = v18;
        }
        else
        {
          v21 = v17;
          if ( HIBYTE(vtxFile) != 0 )
            p_m_materialList->m_Elements.m_Tree.m_Elements.m_pMemory[v21].m_Left = v18;
          else
            p_m_materialList->m_Elements.m_Tree.m_Elements.m_pMemory[v21].m_Right = v18;
        }
        CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::InsertRebalance(
          this: &p_m_materialList->m_Elements.m_Tree,
          elem: v18);
        m_pMemory = p_m_materialList->m_Elements.m_Tree.m_Elements.m_pMemory;
        ++p_m_materialList->m_Elements.m_Tree.m_NumElements;
        p_m_Data = &m_pMemory[v19].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
        v24 = v30;
        v14 = v18;
        v30->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem.m_nFirstInstance = 0;
        v24->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem.m_nInstanceCount = 0;
        v24->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem.m_nMaterialDictionaryIndex = 0;
        v6 = pStudioHdr;
      }
      pTextureList[t++] = v14;
    }
    while ( t < nTextureCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431CB0
// Name: public: void CStaticPropBuilder::Generate(class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::Generate(CStaticPropBuilder *this, CUtlVector<int,CUtlMemory<int,int> > *propList)
{
  CUtlVector<int,CUtlMemory<int,int> > *v2; // edi
  char *v3; // ebx
  int v5; // ecx
  int m_PropType; // edi
  int v7; // eax
  unsigned __int16 v8; // bx
  int v9; // eax
  int *m_pMemory; // edx
  int v11; // edi
  int v12; // eax
  studiohdr_t *m_pStudioHdr; // ebx
  unsigned int *v14; // edi
  void *v15; // eax
  int v16; // edi
  CUtlBuffer *m_pVtxFile; // ecx
  int v18; // ecx
  int v19; // eax
  propbatch_list_t *v20; // edi
  int v21; // eax
  int v22; // edx
  int m_nMaterial; // eax
  propmaterial_list_t *p_elem; // ecx
  int m_nMaterialDictionaryIndex; // eax
  int v26; // ecx
  propinstance_list_t *v27; // eax
  char *v28; // eax
  StaticPropLump_t *v29; // [esp-8h] [ebp-874h]
  int m_Size; // [esp-4h] [ebp-870h]
  int nTextureIndex[512]; // [esp+Ch] [ebp-860h] BYREF
  matrix3x4_t xform; // [esp+80Ch] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > propModels; // [esp+83Ch] [ebp-30h] BYREF
  ModelCollisionLookup_t lookup; // [esp+850h] [ebp-1Ch] BYREF
  int v35; // [esp+860h] [ebp-Ch]
  int j; // [esp+864h] [ebp-8h]
  int i; // [esp+868h] [ebp-4h]

  v2 = propList;
  v3 = nullptr;
  m_Size = propList->m_Size;
  memset(&propModels, 0, sizeof(propModels));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&propModels,
    elem: 0,
    num: m_Size);
  v5 = 0;
  i = 0;
  if ( propList->m_Size > 0 )
  {
    while ( 1 )
    {
      m_PropType = s_StaticPropLump.m_Memory.m_pMemory[v2->m_Memory.m_pMemory[v5]].m_PropType;
      propModels.m_Memory.m_pMemory[v5] = -1;
      LOWORD(lookup.m_pCollide) = -1;
      v7 = FindInModelCache(
             pModelName: s_StaticPropDictLump.m_Memory.m_pMemory[m_PropType].m_Name,
             lookup: (ModelCollisionLookup_t *)&lookup.m_pCollide);
      v8 = v7;
      if ( v7 != 0xFFFF )
      {
        v9 = CStaticPropBuilder::FindOrAddModel(this, nModelIndex: v7);
        m_pMemory = propModels.m_Memory.m_pMemory;
        v11 = v9;
        v9 *= 24;
        ++*(int *)((char *)&this->m_modelList.m_Memory.m_pMemory->m_nPropCount + v9);
        m_pMemory[i] = v11;
        if ( *(int *)((char *)&this->m_modelList.m_Memory.m_pMemory->m_nPropCount + v9) <= 1 )
        {
          v12 = v8;
          m_pStudioHdr = s_ModelCollisionCache.m_Elements.m_pMemory[v8].m_Data.m_pStudioHdr;
          j = (int)s_ModelCollisionCache.m_Elements.m_pMemory[v12].m_Data.m_pVtxFile;
          CStaticPropBuilder::AddTexturesFromModel(
            this,
            pTextureList: nTextureIndex,
            nTextureListMax: 512,
            pStudioHdr: m_pStudioHdr,
            vtxFile: (CUtlBuffer *)j,
            nLod: 0);
          CStaticPropBuilder::AddBatchesFromModel(
            this,
            nModelOutputIndex: v11,
            pTextureList: nTextureIndex,
            pStudioHdr: m_pStudioHdr,
            vtxFile: (const mstudio_meshvertexdata_t *)j,
            nLod: 0);
        }
      }
      if ( ++i >= propList->m_Size )
        break;
      v5 = i;
      v2 = propList;
    }
    v3 = nullptr;
  }
  if ( this->m_modelList.m_Size > 0 )
  {
    i = 0;
    do
    {
      v14 = (unsigned int *)((char *)this->m_modelList.m_Memory.m_pMemory + i);
      v15 = MemAlloc_Alloc(nSize: (unsigned __int64)v14[1] >> 30 != 0 ? -1 : 4 * v14[1]);
      i += 24;
      ++v3;
      v14[5] = (unsigned int)v15;
      v14[4] = 0;
    }
    while ( (int)v3 < this->m_modelList.m_Size );
    v3 = nullptr;
  }
  CStaticPropBuilder::ComputeInstances(this);
  v16 = this->m_materialLinearList.m_Size;
  m_pVtxFile = nullptr;
  memset(&lookup, 0, sizeof(lookup));
  v35 = 0;
  if ( v16 != 0 )
  {
    if ( v16 > 0 )
    {
      CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&lookup, num: v16);
      v3 = *(char **)&lookup.m_Name.m_Id;
      m_pVtxFile = lookup.m_pVtxFile;
    }
    m_pVtxFile = (CUtlBuffer *)((char *)m_pVtxFile + v16);
    lookup.m_pVtxFile = m_pVtxFile;
    if ( (int)m_pVtxFile - v16 > 0 && v16 > 0 )
    {
      _V_memmove(dest: &v3[4 * v16], src: v3, count: 4 * ((_DWORD)m_pVtxFile - v16));
      m_pVtxFile = lookup.m_pVtxFile;
    }
  }
  if ( (int)m_pVtxFile > 0 )
    memset(v3, 0, 4 * (_DWORD)m_pVtxFile);
  v18 = 0;
  for ( i = 0; v18 < propList->m_Size; i = v18 )
  {
    v19 = propModels.m_Memory.m_pMemory[v18];
    if ( v19 >= 0 )
    {
      v20 = &this->m_modelList.m_Memory.m_pMemory[v19];
      v20->m_pPropIndices[v20->m_nCurrentProp++] = v18;
      v29 = &s_StaticPropLump.m_Memory.m_pMemory[propList->m_Memory.m_pMemory[v18]];
      AngleMatrix(angles: &v29->m_Angles, position: &v29->m_Origin, matrix: &xform);
      v21 = 0;
      for ( j = 0; v21 < v20->m_nBatchCount; j = v21 )
      {
        v22 = v21 + v20->m_nFirstBatch;
        m_nMaterial = this->m_batchList.m_Memory.m_pMemory[v22].m_nMaterial;
        if ( m_nMaterial >= 0 )
        {
          p_elem = &this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[m_nMaterial].m_Data.elem;
          m_nMaterialDictionaryIndex = this->m_materialList.m_Elements.m_Tree.m_Elements.m_pMemory[m_nMaterial].m_Data.elem.m_nMaterialDictionaryIndex;
          v26 = *(_DWORD *)&v3[4 * m_nMaterialDictionaryIndex] + p_elem->m_nFirstInstance;
          ++*(_DWORD *)&v3[4 * m_nMaterialDictionaryIndex];
          v26 *= 52;
          *(int *)((char *)&this->m_instanceList.m_Memory.m_pMemory->m_nBatchIndex + v26) = v22;
          v27 = this->m_instanceList.m_Memory.m_pMemory;
          *(_QWORD *)((char *)v27->m_xform.m_flMatVal[0] + v26) = *(_QWORD *)&xform.m_flMatVal[0][0];
          v28 = (char *)v27 + v26;
          *((_QWORD *)v28 + 1) = *(_QWORD *)&xform.m_flMatVal[0][2];
          *((_OWORD *)v28 + 1) = *(_OWORD *)&xform.m_flMatVal[1][0];
          *((_OWORD *)v28 + 2) = *(_OWORD *)&xform.m_flMatVal[2][0];
        }
        v21 = j + 1;
      }
      v18 = i;
    }
    ++v18;
  }
  if ( (int)lookup.m_pStudioHdr >= 0 && v3 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
  if ( propModels.m_Memory.m_nGrowSize >= 0 && propModels.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: propModels.m_Memory.m_pMemory);
}
