// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/staticprop.cpp
// Functions: 19
// ============================================================

#include "utils\vbsp\staticprop.h"

//------------------------------------------------------------------------------
// Address: 0x00408A90
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
// Address: 0x004265D0
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
// Address: 0x00426750
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
// Address: 0x00426920
// Name: bool StudioKeyValues(struct studiohdr_t __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StudioKeyValues(studiohdr_t *pStudioHdr, KeyValues *pValue)
{
  const char *v3; // esi
  int studiohdr2index; // eax
  int v5; // edx
  char *v6; // eax
  int v7; // ecx

  if ( pStudioHdr == nullptr )
    return false;
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
// Address: 0x004269A0
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
  if ( StudioKeyValues(pStudioHdr: pHdr, pValue: v7)
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
// Address: 0x00426A70
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
// Address: 0x00426B70
// Name: TestLeafAgainstCollide
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TestLeafAgainstCollide(
        unsigned int depth,
        int *pNodeList,
        const Vector *origin,
        const QAngle *angles,
        CPhysCollide *pCollide)
{
  void *v5; // esp
  unsigned int v6; // eax
  int v7; // ebx
  int *v8; // edx
  float *v9; // eax
  int v10; // edi
  BOOL v11; // ecx
  int v12; // esi
  int v13; // ecx
  dplane_t *v14; // ecx
  int v15; // edi
  BOOL v16; // ecx
  int v17; // esi
  int v18; // ecx
  dplane_t *v19; // ecx
  BOOL v20; // ecx
  int v21; // esi
  int v22; // ecx
  dplane_t *v23; // ecx
  int v24; // edi
  BOOL v25; // ecx
  int v26; // esi
  int v27; // ecx
  dplane_t *v28; // ecx
  float *v29; // ecx
  int v30; // esi
  int v31; // edx
  int v32; // eax
  dplane_t *v33; // eax
  const struct CPhysCollide *v35; // esi
  _BYTE v36[8]; // [esp+4h] [ebp-70h] BYREF
  int v37; // [esp+Ch] [ebp-68h] BYREF
  _BYTE v38[84]; // [esp+10h] [ebp-64h] BYREF
  int v39; // [esp+64h] [ebp-10h] BYREF
  unsigned int v40; // [esp+6Ch] [ebp-8h]
  unsigned int v41; // [esp+70h] [ebp-4h]

  v5 = alloca(16 * depth);
  v6 = 0;
  v7 = depth - 1;
  if ( (int)(depth - 1) >= 0 )
  {
    if ( (int)depth >= 4 )
    {
      v41 = depth >> 2;
      v8 = &pNodeList[v7 - 2];
      v9 = (float *)&v37;
      v40 = 4 * (depth >> 2);
      v7 -= v40;
      do
      {
        v10 = v8[2];
        v11 = v10 >= 0;
        v12 = 2 * v11 - 1;
        if ( 2 * v11 != 0 )
          v13 = v8[2];
        else
          v13 = -1 - v10;
        v14 = &dplanes[dnodes[v13].planenum];
        *(v9 - 2) = (float)v12 * v14->normal.x;
        *(v9 - 1) = v14->normal.y * (float)v12;
        *v9 = v14->normal.z * (float)v12;
        v9[1] = v14->dist * (float)v12;
        v15 = v8[1];
        v16 = v15 >= 0;
        v17 = 2 * v16 - 1;
        if ( 2 * v16 != 0 )
          v18 = v8[1];
        else
          v18 = -1 - v15;
        v19 = &dplanes[dnodes[v18].planenum];
        v9[2] = (float)v17 * v19->normal.x;
        v9[3] = v19->normal.y * (float)v17;
        v9[4] = v19->normal.z * (float)v17;
        v9[5] = v19->dist * (float)v17;
        v20 = *v8 >= 0;
        v21 = 2 * v20 - 1;
        if ( 2 * v20 != 0 )
          v22 = *v8;
        else
          v22 = -1 - *v8;
        v23 = &dplanes[dnodes[v22].planenum];
        v9[6] = (float)v21 * v23->normal.x;
        v9[7] = v23->normal.y * (float)v21;
        v9[8] = v23->normal.z * (float)v21;
        v9[9] = v23->dist * (float)v21;
        v24 = *(v8 - 1);
        v25 = v24 >= 0;
        v26 = 2 * v25 - 1;
        if ( 2 * v25 != 0 )
          v27 = *(v8 - 1);
        else
          v27 = -1 - v24;
        v28 = &dplanes[dnodes[v27].planenum];
        v9[10] = (float)v26 * v28->normal.x;
        v9[11] = v28->normal.y * (float)v26;
        v9[12] = v28->normal.z * (float)v26;
        v9[13] = v28->dist * (float)v26;
        v9 += 16;
        v8 -= 4;
        --v41;
      }
      while ( v41 != 0 );
      v6 = v40;
    }
    if ( v7 >= 0 )
    {
      v29 = (float *)&v36[16 * v6 + 8];
      do
      {
        v30 = pNodeList[v7];
        v31 = 2 * (v30 >= 0) - 1;
        if ( 2 * (v30 >= 0) != 0 )
          v32 = pNodeList[v7];
        else
          v32 = -1 - v30;
        v33 = &dplanes[dnodes[v32].planenum];
        *(v29 - 2) = (float)v31 * v33->normal.x;
        *(v29 - 1) = v33->normal.y * (float)v31;
        *v29 = v33->normal.z * (float)v31;
        v29[1] = v33->dist * (float)v31;
        v29 += 4;
        --v7;
      }
      while ( v7 >= 0 );
    }
  }
  v39 = ((int (__stdcall *)(_BYTE *, unsigned int, _DWORD))s_pPhysCollision->ConvexFromPlanes)(
          a1: v36,
          a2: depth,
          a3: 0);
  if ( v39 == 0 )
    return false;
  v35 = s_pPhysCollision->ConvertConvexToCollide(this: s_pPhysCollision, a2: &v39, a3: 1);
  s_pPhysCollision->TraceCollide(
    this: s_pPhysCollision,
    a2: &vec3_origin,
    a3: &vec3_origin,
    a4: v35,
    a5: &vec3_angle,
    a6: pCollide,
    a7: origin,
    a8: angles,
    a9: (CGameTrace *)v38);
  s_pPhysCollision->DestroyCollide(this: s_pPhysCollision, a2: v35);
  return v38[55] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426FA0
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
// Address: 0x004274C0
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
// Address: 0x00427E70
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, _DWORD *pModelData)
{
  const vertexFileHeader_t *result; // eax
  int vertexDataStart; // ecx
  char *v5; // edx
  mstudio_modelvertexdata_t *p_vertexdata; // ecx
  int tangentDataStart; // esi

  result = mstudiomodel_t::CacheVertexData(this, pModelData);
  if ( result != nullptr )
  {
    if ( result->id == 1448297545 && (vertexDataStart = result->vertexDataStart) != 0 )
      v5 = (char *)result + vertexDataStart;
    else
      v5 = nullptr;
    p_vertexdata = &this->vertexdata;
    this->vertexdata.pVertexData = v5;
    if ( result->id == 1448297545 && (tangentDataStart = result->tangentDataStart) != 0 )
    {
      this->vertexdata.pTangentData = (char *)result + tangentDataStart;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
    else
    {
      this->vertexdata.pTangentData = nullptr;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427EE0
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
// Address: 0x00428140
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
// Address: 0x00428230
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
        CPhysCollide *pCollide,
        bool bSkipTrace,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafList)
{
  int v11; // edi
  const Vector *v12; // ecx
  dnode_t *v13; // esi
  float *p_x; // eax
  double v15; // st7
  float dist; // xmm3_4
  int m_nAllocationCount; // eax
  unsigned __int16 v18; // dx
  int m_Size; // edi
  unsigned __int16 v20; // bx
  unsigned __int16 *m_pMemory; // ecx
  int v22; // eax
  unsigned __int16 *v23; // eax
  Vector cornermin; // [esp+Ch] [ebp-2Ch] BYREF
  Vector cornermax; // [esp+18h] [ebp-20h] BYREF
  dplane_t *pPlane; // [esp+24h] [ebp-14h]
  char *v27; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int v29; // [esp+30h] [ebp-8h]
  int v30; // [esp+34h] [ebp-4h]
  int nodea; // [esp+40h] [ebp+8h]

  v11 = node;
  if ( node >= 0 )
  {
    v12 = maxs;
    nodea = (char *)&cornermin - (char *)maxs;
    v30 = (char *)mins - (char *)maxs;
    v29 = (char *)&cornermax - (char *)maxs;
    do
    {
      v13 = &dnodes[v11];
      pPlane = &dplanes[v13->planenum];
      p_x = &v12->x;
      v27 = (char *)((char *)pPlane - (char *)v12);
      for ( i = 3; i != 0; --i )
      {
        if ( *(float *)((char *)p_x + (_DWORD)v27) < 0.0 )
        {
          *(float *)((char *)p_x + nodea) = *p_x;
          v15 = *(float *)((char *)p_x + v30);
        }
        else
        {
          *(float *)((char *)p_x + nodea) = *(float *)((char *)p_x + v30);
          v15 = *p_x;
        }
        *(float *)((char *)p_x++ + v29) = v15;
      }
      dist = pPlane->dist;
      if ( dist < (float)((float)((float)(pPlane->normal.x * cornermax.x) + (float)(pPlane->normal.y * cornermax.y))
                        + (float)(pPlane->normal.z * cornermax.z)) )
      {
        if ( (float)((float)((float)(pPlane->normal.x * cornermin.x) + (float)(pPlane->normal.y * cornermin.y))
                   + (float)(pPlane->normal.z * cornermin.z)) < dist )
        {
          pNodeList[depth++] = v11;
          ComputeConvexHullLeaves_R(
            node: v13->children[1],
            depth,
            pNodeList,
            mins,
            maxs: v12,
            origin,
            angles,
            pCollide,
            bSkipTrace,
            leafList);
          pNodeList[depth - 1] = -1 - v11;
          v12 = maxs;
        }
        else
        {
          pNodeList[depth++] = -1 - v11;
        }
        v11 = v13->children[0];
      }
      else
      {
        pNodeList[depth] = v11;
        v11 = v13->children[1];
        ++depth;
      }
    }
    while ( v11 >= 0 );
  }
  if ( (dleafs[-v11 - 1].contents & 1) == 0
    && (bSkipTrace || TestLeafAgainstCollide(depth, pNodeList, origin, angles, pCollide)) )
  {
    m_nAllocationCount = leafList->m_Memory.m_nAllocationCount;
    v18 = -1 - v11;
    m_Size = leafList->m_Size;
    v20 = v18;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: &leafList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++leafList->m_Size;
    m_pMemory = leafList->m_Memory.m_pMemory;
    v22 = leafList->m_Size - m_Size - 1;
    leafList->m_pElements = leafList->m_Memory.m_pMemory;
    if ( v22 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v22);
    v23 = &leafList->m_Memory.m_pMemory[m_Size];
    if ( v23 != nullptr )
      *v23 = v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428420
// Name: ComputeStaticPropLeaves
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeStaticPropLeaves(
        const Vector *origin@<edi>,
        const QAngle *angles@<esi>,
        CPhysCollide *pCollide,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *leafList)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  int pNodeList[1024]; // [esp+Ch] [ebp-101Ch] BYREF
  bool bSkipTrace[4]; // [esp+100Ch] [ebp-1Ch]
  Vector mins; // [esp+1010h] [ebp-18h] BYREF
  Vector maxs; // [esp+101Ch] [ebp-Ch] BYREF

  ((void (__thiscall *)(IPhysicsCollision *, Vector *, Vector *, CPhysCollide *))s_pPhysCollision->CollideGetAABB)(
    a1: s_pPhysCollision,
    a2: &mins,
    a3: &maxs,
    a4: pCollide);
  v4 = maxs.z - mins.z;
  v5 = maxs.y - mins.y;
  bSkipTrace[0] = false;
  if ( (float)(maxs.x - mins.x) < 0.0099999998 || v5 < 0.0099999998 || v4 < 0.0099999998 )
  {
    bSkipTrace[0] = true;
    if ( (float)(maxs.x - mins.x) < 0.0099999998 )
    {
      mins.x = mins.x - 1.0;
      maxs.x = maxs.x + 1.0;
    }
    if ( v5 < 0.0099999998 )
    {
      mins.y = mins.y - 1.0;
      maxs.y = maxs.y + 1.0;
    }
    if ( v4 < 0.0099999998 )
    {
      mins.z = mins.z - 1.0;
      maxs.z = maxs.z + 1.0;
    }
  }
  ComputeConvexHullLeaves_R(
    node: 0,
    depth: 0,
    pNodeList,
    &mins,
    &maxs,
    origin,
    angles,
    pCollide,
    bSkipTrace: bSkipTrace[0],
    leafList);
}

//------------------------------------------------------------------------------
// Address: 0x00428590
// Name: ComputeConvexHull
// Source: json
//------------------------------------------------------------------------------
CPhysConvex *__cdecl ComputeConvexHull(studiohdr_t *pStudioHdr, mstudiomesh_t *pMesh)
{
  int numvertices; // eax
  int v3; // esi
  const mstudio_modelvertexdata_t *v4; // eax
  mstudio_meshvertexdata_t *v5; // edi
  float *p_z; // ecx
  float *v7; // edx
  Vector **m_pMemory; // edx
  Vector **v9; // esi
  CPhysConvex *v10; // edi
  CUtlVector<Vector,CUtlMemory<Vector,int> > vertCopy; // [esp+Ch] [ebp-3Ch] BYREF
  CUtlVector<Vector *,CUtlMemory<Vector *,int> > ppVerts; // [esp+20h] [ebp-28h] BYREF
  float v14; // [esp+34h] [ebp-14h]
  float v15; // [esp+38h] [ebp-10h]
  float v16; // [esp+3Ch] [ebp-Ch]
  int v17; // [esp+40h] [ebp-8h]
  int v18; // [esp+44h] [ebp-4h]

  numvertices = pMesh->numvertices;
  v3 = 0;
  memset(&vertCopy, 0, sizeof(vertCopy));
  memset(&ppVerts, 0, sizeof(ppVerts));
  if ( numvertices > 0 )
    CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
      this: &vertCopy,
      elem: 0,
      num: numvertices);
  if ( pMesh->numvertices > 0 )
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&ppVerts,
      elem: 0,
      num: pMesh->numvertices);
  mstudiomodel_t::GetVertexData(this: (mstudiomodel_t *)((char *)pMesh + pMesh->modelindex), pModelData: pStudioHdr);
  v4 = (const mstudio_modelvertexdata_t *)((char *)&pMesh->unused[6] + pMesh->modelindex);
  pMesh->vertexdata.modelvertexdata = v4;
  v5 = v4->pVertexData != nullptr ? &pMesh->vertexdata : nullptr;
  if ( pMesh->numvertices > 0 )
  {
    p_z = &vertCopy.m_Memory.m_pMemory->z;
    do
    {
      v7 = (float *)((char *)v5->modelvertexdata->pVertexData
                   + 48 * ((int)v5[-1].modelvertexdata + (unsigned int)v5->modelvertexdata[-3].pVertexData / 0x30 + v3)
                   + 16);
      *(p_z - 2) = *v7;
      *(p_z - 1) = v7[1];
      *p_z = v7[2];
      v16 = *(p_z - 2);
      *(p_z - 2) = (float)(int)v16;
      v15 = *(p_z - 1);
      v18 = (int)v15;
      *(p_z - 1) = (float)v18;
      v14 = *p_z;
      v17 = (int)v14;
      m_pMemory = ppVerts.m_Memory.m_pMemory;
      *p_z = (float)v17;
      m_pMemory[v3++] = (Vector *)(p_z - 2);
      p_z += 3;
    }
    while ( v3 < pMesh->numvertices );
  }
  v9 = ppVerts.m_Memory.m_pMemory;
  v10 = s_pPhysCollision->ConvexFromVerts(
          this: s_pPhysCollision,
          a2: ppVerts.m_Memory.m_pMemory,
          a3: pMesh->numvertices);
  if ( ppVerts.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
  if ( vertCopy.m_Memory.m_nGrowSize >= 0 && vertCopy.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertCopy.m_Memory.m_pMemory);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x00428710
// Name: class CPhysCollide __near * ComputeConvexHull(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__cdecl ComputeConvexHull(studiohdr_t *pStudioHdr)
{
  studiohdr_t *v1; // esi
  CPhysConvex **v2; // edi
  int m_Size; // ebx
  int v4; // eax
  mstudiobodyparts_t *v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // esi
  CPhysConvex **m_pMemory; // ecx
  CPhysConvex **v10; // eax
  CPhysCollide *v11; // esi
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexHulls; // [esp+Ch] [ebp-34h] BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+20h] [ebp-20h]
  CPhysConvex *pConvex; // [esp+24h] [ebp-1Ch]
  int body; // [esp+28h] [ebp-18h]
  int v17; // [esp+2Ch] [ebp-14h]
  int v18; // [esp+30h] [ebp-10h]
  int model; // [esp+34h] [ebp-Ch]
  int v20; // [esp+38h] [ebp-8h]
  int mesh; // [esp+3Ch] [ebp-4h]

  v1 = pStudioHdr;
  v2 = nullptr;
  m_Size = 0;
  memset(&convexHulls, 0, sizeof(convexHulls));
  body = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v18 = 0;
    do
    {
      v4 = v18 + v1->bodypartindex;
      model = 0;
      v5 = (mstudiobodyparts_t *)((char *)v1 + v4);
      pBodyPart = v5;
      if ( v5->nummodels > 0 )
      {
        v6 = 0;
        v17 = 0;
        do
        {
          v7 = (int)v5 + v6 + v5->modelindex;
          mesh = 0;
          if ( *(int *)(v7 + 72) > 0 )
          {
            v20 = 0;
            do
            {
              pConvex = ComputeConvexHull(pStudioHdr: v1, pMesh: (mstudiomesh_t *)(v7 + v20 + *(_DWORD *)(v7 + 76)));
              if ( pConvex != nullptr )
              {
                v8 = m_Size;
                if ( m_Size + 1 > convexHulls.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CClassInput *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&convexHulls,
                    num: m_Size - convexHulls.m_Memory.m_nAllocationCount + 1);
                  m_Size = convexHulls.m_Size;
                }
                m_pMemory = convexHulls.m_Memory.m_pMemory;
                convexHulls.m_Size = ++m_Size;
                convexHulls.m_pElements = convexHulls.m_Memory.m_pMemory;
                if ( m_Size - v8 - 1 > 0 )
                {
                  _V_memmove(
                    dest: &convexHulls.m_Memory.m_pMemory[v8 + 1],
                    src: &convexHulls.m_Memory.m_pMemory[v8],
                    count: 4 * (m_Size - v8 - 1));
                  m_pMemory = convexHulls.m_Memory.m_pMemory;
                }
                v10 = &m_pMemory[v8];
                v1 = pStudioHdr;
                if ( v10 != nullptr )
                  *v10 = pConvex;
              }
              else
              {
                _Warning(a1: "Can't create hull for mesh %d/%d of model %s\n", mesh, model, v1->name);
              }
              v20 += 116;
              ++mesh;
            }
            while ( mesh < *(_DWORD *)(v7 + 72) );
            v5 = pBodyPart;
          }
          v6 = v17 + 148;
          ++model;
          v17 += 148;
        }
        while ( model < v5->nummodels );
        v2 = convexHulls.m_Memory.m_pMemory;
      }
      v18 += 16;
      ++body;
    }
    while ( body < v1->numbodyparts );
  }
  v11 = s_pPhysCollision->ConvertConvexToCollide(this: s_pPhysCollision, a2: v2, a3: m_Size);
  if ( convexHulls.m_Memory.m_nGrowSize >= 0 && v2 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00428900
// Name: GetCollisionModel
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__usercall GetCollisionModel@<eax>(const char *pModelName@<edi>)
{
  void *v1; // esp
  _BYTE *v2; // eax
  unsigned __int16 v3; // ax
  studiohdr_t *v5; // esi
  CPhysCollide *m_pCollide; // esi
  char v7[4]; // [esp+0h] [ebp-C0h] BYREF
  char string[128]; // [esp+4h] [ebp-BCh] BYREF
  CUtlBuffer buf; // [esp+84h] [ebp-3Ch] BYREF
  CUtlSymbol v10; // [esp+B6h] [ebp-Ah] BYREF
  ModelCollisionLookup_t search; // [esp+B8h] [ebp-8h] BYREF

  v1 = alloca(strlen(pModelName) + 1);
  strcpy(v7, pModelName);
  strlwr(string: v7);
  strchr(string: (unsigned __int8 *)v7, chr: 0x5Cu);
  while ( v2 != nullptr )
  {
    *v2 = 47;
    strchr(string: (unsigned __int8 *)v7, chr: 0x5Cu);
  }
  search.m_Name.m_Id = -1;
  CUtlSymbol::CUtlSymbol(this: &v10, pStr: v7);
  search.m_Name = v10;
  v3 = CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Find(
         this: &s_ModelCollisionCache,
         &search);
  if ( v3 != 0xFFFF )
    return s_ModelCollisionCache.m_Elements.m_pMemory[v3].m_Data.m_pCollide;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( LoadStudioModel(pModelName, pEntityType: "prop_static", &buf) != 0 )
  {
    g_pActiveStudioHdr = (studiohdr_t *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
    search.m_pCollide = ComputeConvexHull(pStudioHdr: (studiohdr_t *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset]);
    CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Insert(
      this: &s_ModelCollisionCache,
      insert: &search);
    if ( search.m_pCollide == nullptr )
      _Warning(a1: "Bad geometry on \"%s\"!\n", pModelName);
    if ( g_DumpStaticProps != 0 )
    {
      sprintf(string, format: "staticprop%03d.txt", propNum);
      DumpCollideToGlView(a1: (int)pModelName, pCollide: (Vector *)search.m_pCollide, pFilename: string);
      ++propNum;
    }
    v5 = g_pActiveStudioHdr;
    if ( g_pActiveStudioHdr->pVertexBase != nullptr )
    {
      free(pMem: g_pActiveStudioHdr->pVertexBase);
      v5->pVertexBase = nullptr;
    }
    m_pCollide = search.m_pCollide;
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return m_pCollide;
  }
  else
  {
    _Warning(a1: "Error loading studio model \"%s\"!\n", pModelName);
    search.m_pCollide = nullptr;
    CUtlRBTree<ModelCollisionLookup_t,unsigned short,bool (__cdecl *)(ModelCollisionLookup_t const &,ModelCollisionLookup_t const &),CUtlMemory<UtlRBTreeNode_t<ModelCollisionLookup_t,unsigned short>,unsigned short>>::Insert(
      this: &s_ModelCollisionCache,
      insert: &search);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428AE0
// Name: AddStaticPropToLump
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddStaticPropToLump(const StaticPropBuild_t *build)
{
  CPhysCollide *CollisionModel; // eax
  Vector *p_m_Origin; // edi
  StaticPropLump_t *v3; // esi
  unsigned __int8 m_Flags; // al
  const char *m_pLightingOrigin; // eax
  int v6; // ebx
  int m_Size; // ecx
  unsigned __int16 v8; // di
  int v9; // esi
  StaticPropLeafLump_t *v10; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > leafList; // [esp+24h] [ebp-14h] BYREF

  CollisionModel = GetCollisionModel(pModelName: build->m_pModelName);
  if ( CollisionModel != nullptr )
  {
    memset(&leafList, 0, sizeof(leafList));
    p_m_Origin = &build->m_Origin;
    ComputeStaticPropLeaves(origin: &build->m_Origin, angles: &build->m_Angles, pCollide: CollisionModel, &leafList);
    if ( leafList.m_Size != 0 )
    {
      v3 = &s_StaticPropLump.m_Memory.m_pMemory[CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int>>::AddToTail(this: &s_StaticPropLump)];
      v3->m_PropType = AddStaticPropDictLump(pModelName: (char *)build->m_pModelName);
      v3->m_Origin.x = p_m_Origin->x;
      v3->m_Origin.y = build->m_Origin.y;
      v3->m_Origin.z = build->m_Origin.z;
      v3->m_Angles = build->m_Angles;
      v3->m_FirstLeaf = s_StaticPropLeafLump.m_Size;
      v3->m_LeafCount = leafList.m_Size;
      v3->m_Solid = build->m_Solid;
      v3->m_Skin = build->m_Skin;
      m_Flags = build->m_Flags;
      v3->m_Flags = m_Flags;
      if ( build->m_FadesOut )
        v3->m_Flags = m_Flags | 1;
      v3->m_FadeMinDist = build->m_FadeMinDist;
      v3->m_FadeMaxDist = build->m_FadeMaxDist;
      v3->m_flForcedFadeScale = build->m_flForcedFadeScale;
      v3->m_nMinCPULevel = build->m_nMinCPULevel;
      v3->m_nMaxCPULevel = build->m_nMaxCPULevel;
      v3->m_nMinGPULevel = build->m_nMinGPULevel;
      v3->m_nMaxGPULevel = build->m_nMaxGPULevel;
      v3->m_DiffuseModulation = build->m_DiffuseModulation;
      v3->m_bDisableX360 = false;
      m_pLightingOrigin = build->m_pLightingOrigin;
      if ( m_pLightingOrigin != nullptr
        && *m_pLightingOrigin != 0
        && ComputeLightingOrigin(build, lightingOrigin: &v3->m_LightingOrigin) != 0 )
      {
        v3->m_Flags |= 2u;
      }
      v6 = 0;
      if ( leafList.m_Size > 0 )
      {
        m_Size = s_StaticPropLeafLump.m_Size;
        do
        {
          v8 = leafList.m_Memory.m_pMemory[v6];
          v9 = m_Size;
          if ( m_Size + 1 > s_StaticPropLeafLump.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
              this: (CUtlMemory<unsigned short,int> *)&s_StaticPropLeafLump,
              num: m_Size - s_StaticPropLeafLump.m_Memory.m_nAllocationCount + 1);
            m_Size = s_StaticPropLeafLump.m_Size;
          }
          s_StaticPropLeafLump.m_Size = ++m_Size;
          s_StaticPropLeafLump.m_pElements = s_StaticPropLeafLump.m_Memory.m_pMemory;
          if ( m_Size - v9 - 1 > 0 )
          {
            _V_memmove(
              dest: &s_StaticPropLeafLump.m_Memory.m_pMemory[v9 + 1],
              src: &s_StaticPropLeafLump.m_Memory.m_pMemory[v9],
              count: 2 * (m_Size - v9 - 1));
            m_Size = s_StaticPropLeafLump.m_Size;
          }
          v10 = &s_StaticPropLeafLump.m_Memory.m_pMemory[v9];
          if ( v10 != nullptr )
          {
            v10->m_Leaf = v8;
            m_Size = s_StaticPropLeafLump.m_Size;
          }
          ++v6;
        }
        while ( v6 < leafList.m_Size );
      }
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&leafList);
    }
    else
    {
      _Warning(
        a1: "Static prop %s outside the map (%.2f, %.2f, %.2f)\n",
        build->m_pModelName,
        p_m_Origin->x,
        build->m_Origin.y,
        build->m_Origin.z);
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&leafList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428CE0
// Name: void EmitStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitStaticProps()
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  int v1; // eax
  int v2; // edi
  entity_t *v3; // ebx
  const char *v4; // eax
  int m_Size; // esi
  int *v6; // eax
  entity_t *v7; // esi
  const char *v8; // edi
  char *v9; // eax
  double v10; // st7
  float m_FadeMaxDist; // xmm0_4
  unsigned __int8 v12; // al
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  int *m_pMemory; // ecx
  int v17; // esi
  StaticPropBuild_t build; // [esp+24h] [ebp-4Ch] BYREF
  int i; // [esp+68h] [ebp-8h]
  color32_s tmp; // [esp+6Ch] [ebp-4h] BYREF

  PhysicsFactory = GetPhysicsFactory();
  if ( PhysicsFactory == nullptr
    || (s_pPhysCollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr),
        s_pPhysCollision != nullptr) )
  {
    v1 = num_entities;
    v2 = 0;
    if ( num_entities > 0 )
    {
      v3 = (entity_t *)&entities;
      do
      {
        v4 = ValueForKey(ent: v3, key: "classname");
        if ( _V_strcmp(s1: v4, s2: "info_lighting") == 0 )
        {
          m_Size = s_LightingInfo.m_Size;
          if ( s_LightingInfo.m_Size + 1 > s_LightingInfo.m_Memory.m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&s_LightingInfo,
              num: s_LightingInfo.m_Size - s_LightingInfo.m_Memory.m_nAllocationCount + 1);
          ++s_LightingInfo.m_Size;
          s_LightingInfo.m_pElements = s_LightingInfo.m_Memory.m_pMemory;
          if ( s_LightingInfo.m_Size - m_Size - 1 > 0 )
            _V_memmove(
              dest: &s_LightingInfo.m_Memory.m_pMemory[m_Size + 1],
              src: &s_LightingInfo.m_Memory.m_pMemory[m_Size],
              count: 4 * (s_LightingInfo.m_Size - m_Size - 1));
          v6 = &s_LightingInfo.m_Memory.m_pMemory[m_Size];
          if ( v6 != nullptr )
            *v6 = v2;
        }
        v1 = num_entities;
        ++v2;
        ++v3;
      }
      while ( v2 < num_entities );
    }
    i = 0;
    if ( v1 > 0 )
    {
      v7 = (entity_t *)&entities;
      while ( 1 )
      {
        v8 = ValueForKey(ent: v7, key: "classname");
        if ( strcmp(v8, "static_prop") == 0 || strcmp(v8, "prop_static") == 0 )
          break;
LABEL_53:
        ++v7;
        if ( ++i >= num_entities )
          goto LABEL_54;
      }
      GetVectorForKey(ent: v7, key: "origin", angle: (QAngle *)&build.m_Origin);
      GetVectorForKey(ent: v7, key: "angles", angle: &build.m_Angles);
      build.m_pModelName = ValueForKey(ent: v7, key: "model");
      build.m_Solid = IntForKey(ent: v7, key: "solid");
      build.m_Skin = IntForKey(ent: v7, key: "skin");
      build.m_FadeMaxDist = FloatForKey(ent: v7, key: "fademaxdist");
      build.m_Flags = 0;
      if ( IntForKey(ent: v7, key: "ignorenormals") == 1 )
        build.m_Flags |= 8u;
      if ( IntForKey(ent: v7, key: "disableshadows") == 1 )
        build.m_Flags |= 0x10u;
      if ( IntForKey(ent: v7, key: "disableflashlight") == 1 )
        build.m_Flags |= 4u;
      if ( IntForKey(ent: v7, key: "drawinfastreflection") == 1 )
        build.m_Flags |= 0x20u;
      if ( IntForKey(ent: v7, key: "disablevertexlighting") == 1 )
        build.m_Flags |= 0x40u;
      if ( IntForKey(ent: v7, key: "disableselfshadowing") == 1 )
        build.m_Flags |= 0x80u;
      if ( IntForKey(ent: v7, key: "screenspacefade") == 1 )
        _Warning(
          a1: "Encountered obsolete static prop option to do its fade in screen space @ %.2f %.2f %.2f\n",
          build.m_Origin.x,
          build.m_Origin.y,
          build.m_Origin.z);
      v9 = ValueForKey(ent: v7, key: "fadescale");
      if ( v9 != nullptr && *v9 != 0 )
        build.m_flForcedFadeScale = FloatForKey(ent: v7, key: "fadescale");
      else
        build.m_flForcedFadeScale = 1.0;
      build.m_FadesOut = build.m_FadeMaxDist > 0.0;
      build.m_pLightingOrigin = ValueForKey(ent: v7, key: "lightingorigin");
      if ( build.m_FadesOut )
      {
        v10 = FloatForKey(ent: v7, key: "fademindist");
        build.m_FadeMinDist = v10;
        if ( v10 >= 0.0 )
          goto LABEL_40;
        m_FadeMaxDist = build.m_FadeMaxDist;
      }
      else
      {
        m_FadeMaxDist = 0.0;
      }
      build.m_FadeMinDist = m_FadeMaxDist;
LABEL_40:
      build.m_nMinCPULevel = IntForKey(ent: v7, key: "mincpulevel");
      build.m_nMaxCPULevel = IntForKey(ent: v7, key: "maxcpulevel");
      build.m_nMinGPULevel = IntForKey(ent: v7, key: "mingpulevel");
      v12 = IntForKey(ent: v7, key: "maxgpulevel");
      build.m_nMaxGPULevel = v12;
      if ( build.m_nMaxCPULevel != 0 && build.m_nMaxCPULevel < build.m_nMinCPULevel )
        build.m_nMaxCPULevel = build.m_nMinCPULevel;
      if ( v12 != 0 && v12 < build.m_nMinGPULevel )
        build.m_nMaxGPULevel = build.m_nMinGPULevel;
      v13 = ValueForKey(ent: v7, key: "rendercolor");
      if ( *v13 != 0 )
      {
        V_StringToColor32(color: &tmp, pString: v13);
        *(_WORD *)&build.m_DiffuseModulation.r = *(_WORD *)&tmp.r;
        build.m_DiffuseModulation.b = tmp.b;
      }
      else
      {
        *(_WORD *)&build.m_DiffuseModulation.g = -1;
        build.m_DiffuseModulation.r = -1;
      }
      v14 = ValueForKey(ent: v7, key: "renderamt");
      if ( *v14 != 0 )
        build.m_DiffuseModulation.a = V_atoi(str: v14);
      else
        build.m_DiffuseModulation.a = -1;
      AddStaticPropToLump(&build);
      v7->epairs = nullptr;
      goto LABEL_53;
    }
LABEL_54:
    v15 = s_LightingInfo.m_Size - 1;
    if ( s_LightingInfo.m_Size - 1 >= 0 )
    {
      m_pMemory = s_LightingInfo.m_Memory.m_pMemory;
      do
      {
        v17 = 44 * m_pMemory[v15--];
        *(_DWORD *)((char *)&unk_7351A3C + v17) = 0;
      }
      while ( v15 >= 0 );
    }
    SetLumpData_0();
  }
}
