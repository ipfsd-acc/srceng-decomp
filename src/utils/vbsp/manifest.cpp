// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/manifest.cpp
// Functions: 18
// ============================================================

#include "utils\vbsp\manifest.h"

//------------------------------------------------------------------------------
// Address: 0x004177B0
// Name: public: void CMapError::ReportError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapError::ReportError(CMapError *this, const char *pErrorString)
{
  _Error(
    a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
    this->m_brushID,
    pErrorString,
    this->m_sideIndex,
    this->m_textureName);
}

//------------------------------------------------------------------------------
// Address: 0x004177E0
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestMapKeyCallback(char const __near *,char const __near *,class CManifestMap __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestMapKeyCallback(
        const char *szKey,
        const char *szValue,
        CManifestMap *pManifestMap)
{
  if ( _V_stricmp(s1: szKey, s2: "Name") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "File") == 0 )
    {
      strcpy(pManifestMap->m_RelativeMapFileName, szValue);
      return ChunkFile_Ok;
    }
    if ( _V_stricmp(s1: szKey, s2: "IsPrimary") != 0
      && _V_stricmp(s1: szKey, s2: "IsProtected") != 0
      && _V_stricmp(s1: szKey, s2: "TopLevel") == 0 )
    {
      pManifestMap->m_bTopLevelMap = atoi(nptr: szValue) == 1;
    }
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00417880
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonBoxKeyCallback(char const __near *,char const __near *,class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonBoxKeyCallback(const char *szKey, const char *szValue, BoundBox *pBox)
{
  if ( _V_stricmp(s1: szKey, s2: "mins") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "maxs") == 0 )
      CChunkFile::ReadKeyValuePoint(pszValue: szValue, Point: &pBox->bmaxs);
    return ChunkFile_Ok;
  }
  else
  {
    CChunkFile::ReadKeyValuePoint(pszValue: szValue, Point: &pBox->bmins);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004178E0
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonKeyCallback(char const __near *,char const __near *,struct Cordon_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonKeyCallback(const char *szKey, const char *szValue, Cordon_t *pCordon)
{
  if ( _V_stricmp(s1: szKey, s2: "name") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "active") == 0 )
      CChunkFile::ReadKeyValueBool(pszValue: szValue, bBool: &pCordon->m_bActive);
    return ChunkFile_Ok;
  }
  else
  {
    CUtlString::Set(this: &pCordon->m_szName, pValue: szValue);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417940
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonsKeyCallback(char const __near *,char const __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonsKeyCallback(
        const char *szKey,
        const char *szValue,
        CManifest *pManifest)
{
  if ( _V_stricmp(s1: szKey, s2: "active") == 0 )
    CChunkFile::ReadKeyValueBool(pszValue: szValue, bBool: &pManifest->m_bIsCordoning);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00417980
// Name: public: struct epair_t __near * CManifest::CreateEPair(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
epair_t *__thiscall CManifest::CreateEPair(CManifest *this, char *pKey, char *pValue)
{
  _DWORD *v3; // esi
  void *v4; // eax
  _BYTE *v5; // edx
  char *v6; // ecx
  char v7; // al
  _BYTE *v8; // edx
  char *v9; // ecx
  char v10; // al

  v3 = MemAlloc_Alloc(nSize: 0xCu);
  v3[1] = MemAlloc_Alloc(nSize: strlen(pKey) + 1);
  v4 = MemAlloc_Alloc(nSize: strlen(pValue) + 1);
  v5 = (_BYTE *)v3[1];
  v3[2] = v4;
  v6 = pKey;
  do
  {
    v7 = *v6;
    *v5++ = *v6++;
  }
  while ( v7 != 0 );
  v8 = (_BYTE *)v3[2];
  v9 = pValue;
  do
  {
    v10 = *v9;
    *v8++ = *v9++;
  }
  while ( v10 != 0 );
  return (epair_t *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00417A10
// Name: public: bool CManifest::LoadSubMaps(class CMapFile __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::LoadSubMaps(CManifest *this, CMapFile *pMapFile, const char *pszFileName)
{
  CMapFile *v3; // esi
  char *v5; // ebx
  epair_t *EPair; // eax
  bool v7; // cc
  int v8; // ebx
  int v9; // eax
  char *v10; // esi
  epair_t *v11; // eax
  epair_t *v12; // eax
  epair_t *v13; // eax
  epair_t *v14; // eax
  epair_t *v15; // eax
  char FileName[260]; // [esp+Ch] [ebp-188h] BYREF
  char temp[128]; // [esp+110h] [ebp-84h] BYREF
  int i; // [esp+190h] [ebp-4h]

  v3 = pMapFile;
  v5 = (char *)&unk_12E1028 + (_DWORD)pMapFile + 44 * (*(_DWORD *)((char *)&unk_12E1024 + (_DWORD)pMapFile))++;
  memset(dst: (unsigned __int8 *)v5, value: 0, count: 0x2Cu);
  *(_DWORD *)v5 = 0;
  *((_DWORD *)v5 + 1) = 0;
  *((_DWORD *)v5 + 2) = 0;
  EPair = CManifest::CreateEPair(this, pKey: "classname", pValue: "worldspawn");
  EPair->next = *((epair_t **)v5 + 5);
  *((_DWORD *)v5 + 5) = EPair;
  v7 = this->m_Maps.m_Size <= 0;
  i = 0;
  if ( !v7 )
  {
    while ( 1 )
    {
      v8 = i;
      sprintf(
        string: FileName,
        format: "%s%s",
        this->m_InstancePath,
        this->m_Maps.m_Memory.m_pMemory[i]->m_RelativeMapFileName);
      v9 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v3);
      v10 = (char *)&unk_12E1028 + (_DWORD)v3 + 44 * v9;
      *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)pMapFile) = v9 + 1;
      memset(dst: (unsigned __int8 *)v10, value: 0, count: 0x2Cu);
      *(_DWORD *)v10 = 0;
      *((_DWORD *)v10 + 1) = 0;
      *((_DWORD *)v10 + 2) = 0;
      v11 = CManifest::CreateEPair(this, pKey: "angles", pValue: "0 0 0");
      v11->next = *((epair_t **)v10 + 5);
      *((_DWORD *)v10 + 5) = v11;
      sprintf(string: temp, format: "%d", 2);
      v12 = CManifest::CreateEPair(this, pKey: "fixup_style", pValue: temp);
      v12->next = *((epair_t **)v10 + 5);
      *((_DWORD *)v10 + 5) = v12;
      v13 = CManifest::CreateEPair(this, pKey: "classname", pValue: "func_instance");
      v13->next = *((epair_t **)v10 + 5);
      *((_DWORD *)v10 + 5) = v13;
      v14 = CManifest::CreateEPair(
              this,
              pKey: "file",
              pValue: this->m_Maps.m_Memory.m_pMemory[v8]->m_RelativeMapFileName);
      v14->next = *((epair_t **)v10 + 5);
      *((_DWORD *)v10 + 5) = v14;
      if ( this->m_Maps.m_Memory.m_pMemory[v8]->m_bTopLevelMap )
      {
        v15 = CManifest::CreateEPair(this, pKey: "toplevel", pValue: "1");
        v15->next = *((epair_t **)v10 + 5);
        *((_DWORD *)v10 + 5) = v15;
      }
      if ( ++i >= this->m_Maps.m_Size )
        break;
      v3 = pMapFile;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00417BB0
// Name: public: void CManifest::CordonWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManifest::CordonWorld(CManifest *this)
{
  CManifest *v1; // ebx
  CMapFile *v2; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // edi
  int *v8; // eax
  int v9; // edi
  int v10; // esi
  bool v11; // cc
  int v12; // esi
  int v13; // edx
  Cordon_t *v14; // eax
  int v15; // esi
  int v16; // edi
  char v17; // al
  int nIndex; // [esp+4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-18h]
  int v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+10h] [ebp-10h]
  int nCordon; // [esp+14h] [ebp-Ch]
  int nCordona; // [esp+14h] [ebp-Ch]
  int nBox; // [esp+18h] [ebp-8h]
  int nBrushNum; // [esp+1Ch] [ebp-4h]
  int nBrushNuma; // [esp+1Ch] [ebp-4h]

  v1 = this;
  if ( this->m_bIsCordoning )
  {
    v2 = g_MainMap;
    v3 = 0;
    for ( i = 0; v3 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v2); i = v3 )
    {
      v4 = 0;
      if ( v3 != 0 )
      {
        v13 = 44 * v3;
        v22 = v13;
        if ( (entity_t *)((char *)&unk_12E1028 + (_DWORD)v2 + v13) != v1->m_CordoningMapEnt
          && (*(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v2 + v13) != 0
           || *(_DWORD *)((char *)&unk_12E103C + (_DWORD)v2 + v13) != 0) )
        {
          nCordona = 0;
          if ( v1->m_Cordons.m_Size <= 0 )
          {
LABEL_29:
            *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v2 + v13) = 0;
            *(_DWORD *)((char *)&unk_12E103C + (_DWORD)g_MainMap + v13) = 0;
            v2 = g_MainMap;
          }
          else
          {
            nBrushNuma = 0;
            while ( 1 )
            {
              v14 = (Cordon_t *)((char *)v1->m_Cordons.m_Memory.m_pMemory + v4);
              if ( v14->m_bActive )
              {
                v15 = 0;
                if ( v14->m_Boxes.m_Size > 0 )
                  break;
              }
LABEL_28:
              v4 = nBrushNuma * 40 + 40;
              ++nCordona;
              ++nBrushNuma;
              if ( nCordona >= v1->m_Cordons.m_Size )
                goto LABEL_29;
            }
            v16 = 0;
            while ( 1 )
            {
              v17 = BoundBox::ContainsPoint(
                      this: &v14->m_Boxes.m_Memory.m_pMemory[v16],
                      pt: (const Vector *)((char *)&unk_12E1028 + (_DWORD)v2 + v13));
              v2 = g_MainMap;
              if ( v17 == 1 )
                break;
              v14 = &v1->m_Cordons.m_Memory.m_pMemory[nBrushNuma];
              v13 = v22;
              ++v15;
              ++v16;
              if ( v15 >= v14->m_Boxes.m_Size )
                goto LABEL_28;
            }
          }
        }
      }
      else
      {
        v5 = 0;
        nBrushNum = 0;
        if ( *(int *)((char *)&unk_12E1038 + (_DWORD)v2) > 0 )
        {
          do
          {
            v6 = 0;
            v7 = v5 + *(_DWORD *)((char *)&unk_12E1034 + (_DWORD)v2);
            nIndex = v7;
            nCordon = 0;
            if ( v1->m_Cordons.m_Size <= 0 )
            {
LABEL_14:
              memmove(
                dst: (unsigned __int8 *)&v2->mapbrushes[v7],
                src: (unsigned __int8 *)&v2->mapbrushes[v7 + 1],
                count: 48 * (*(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v2) - v5) - 48);
              --*(_DWORD *)((char *)&unk_12E1038 + (_DWORD)g_MainMap);
              v12 = v5 - 1;
            }
            else
            {
              v21 = 0;
              while ( 1 )
              {
                v8 = (int *)((char *)v1->m_Cordons.m_Memory.m_pMemory + v6);
                if ( *((_BYTE *)v8 + 16) != 0 )
                {
                  nBox = 0;
                  if ( v8[8] > 0 )
                    break;
                }
LABEL_13:
                v6 += 40;
                ++nCordon;
                v21 = v6;
                if ( nCordon >= v1->m_Cordons.m_Size )
                  goto LABEL_14;
              }
              v9 = v7;
              v10 = 0;
              while ( 1 )
              {
                v1 = this;
                if ( (**(unsigned __int8 (__thiscall ***)(int, int, int))(v8[5] + v10))(
                       a1: v10 + v8[5],
                       a2: (int)&v2->mapbrushes[v9].mins,
                       a3: (int)&v2->mapbrushes[v9].maxs) == 1 )
                  break;
                v6 = v21;
                v8 = (int *)((char *)this->m_Cordons.m_Memory.m_pMemory + v21);
                v10 += 28;
                v11 = ++nBox < v8[8];
                v2 = g_MainMap;
                if ( !v11 )
                {
                  v7 = nIndex;
                  v5 = nBrushNum;
                  goto LABEL_13;
                }
              }
              v12 = nBrushNum;
            }
            v2 = g_MainMap;
            v5 = v12 + 1;
            nBrushNum = v5;
          }
          while ( v5 < *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)g_MainMap) );
        }
      }
      v3 = i + 1;
    }
    if ( v1->m_CordoningMapEnt != nullptr )
    {
      CMapFile::MoveBrushesToWorldGeneral(this: v2, mapent: v1->m_CordoningMapEnt);
      v1->m_CordoningMapEnt->numbrushes = 0;
      v1->m_CordoningMapEnt->epairs = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E90
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestVMFCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestVMFCallback(CChunkFile *pFile, CManifest *pManifest)
{
  CManifestMap *v2; // eax
  CManifestMap *v3; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CManifestMap **m_pMemory; // ecx
  int v7; // eax
  CManifestMap **v8; // eax

  v2 = (CManifestMap *)MemAlloc_Alloc(nSize: 0x105u);
  if ( v2 != nullptr )
  {
    v2->m_RelativeMapFileName[0] = 0;
    v2->m_bTopLevelMap = false;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  m_nAllocationCount = pManifest->m_Maps.m_Memory.m_nAllocationCount;
  m_Size = pManifest->m_Maps.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)pManifest, num: m_Size - m_nAllocationCount + 1);
  ++pManifest->m_Maps.m_Size;
  m_pMemory = pManifest->m_Maps.m_Memory.m_pMemory;
  v7 = pManifest->m_Maps.m_Size - m_Size - 1;
  pManifest->m_Maps.m_pElements = pManifest->m_Maps.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &pManifest->m_Maps.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadManifestMapKeyCallback,
           pData: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00417F20
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestMapsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestMapsCallback(CChunkFile *pFile, CManifest *pManifest)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-Ch] BYREF

  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "VMF",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestVMFCallback,
    pData: pManifest);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x00417F80
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonBoxCallback(class CChunkFile __near *,struct Cordon_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonBoxCallback(CChunkFile *pFile, Cordon_t *pCordon)
{
  CUtlVector<BoundBox,CUtlMemory<BoundBox,int>>::InsertBefore(this: &pCordon->m_Boxes, elem: pCordon->m_Boxes.m_Size);
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadCordonBoxKeyCallback,
           pData: &pCordon->m_Boxes.m_Memory.m_pMemory[pCordon->m_Boxes.m_Size - 1]);
}

//------------------------------------------------------------------------------
// Address: 0x00418050
// Name: public: CMapFile::CMapFile(void)
// Source: json
//------------------------------------------------------------------------------
CMapFile *__thiscall CMapFile::CMapFile(CMapFile *this)
{
  int v2; // ecx
  float *p_z; // eax
  int v4; // edx
  int *p_m_nGrowSize; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax

  v2 = 0xFFFF;
  p_z = &this->mapplanes[0].normal.z;
  do
  {
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z += 6;
    --v2;
  }
  while ( v2 >= 0 );
  v4 = 0xFFFF;
  p_m_nGrowSize = &this->brushsides[0].aOverlayIds.m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize[3] = 0;
    p_m_nGrowSize[4] = 0;
    p_m_nGrowSize[5] = 0;
    p_m_nGrowSize[6] = 0;
    p_m_nGrowSize[7] = 0;
    p_m_nGrowSize += 23;
    --v4;
  }
  while ( v4 >= 0 );
  v6 = (_DWORD *)((char *)&unk_7A1024 + (_DWORD)this);
  v7 = 0xFFFF;
  v8 = (_DWORD *)((char *)&unk_7A1024 + (_DWORD)this + 20);
  do
  {
    *v6 = 0;
    *(v8 - 4) = 0;
    *(v8 - 3) = 0;
    *(v8 - 2) = 0;
    *(v8 - 1) = 0;
    *v8 = 0;
    v6 += 45;
    v8 += 45;
    --v7;
  }
  while ( v7 >= 0 );
  CMapFile::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004180F0
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonCallback(CChunkFile *pFile, CManifest *pManifest)
{
  Cordon_t *v2; // esi
  ChunkFileResult_t Chunk; // esi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-Ch] BYREF

  CUtlVector<Cordon_t,CUtlMemory<Cordon_t,int>>::InsertBefore(
    this: &pManifest->m_Cordons,
    elem: pManifest->m_Cordons.m_Size);
  v2 = &pManifest->m_Cordons.m_Memory.m_pMemory[pManifest->m_Cordons.m_Size - 1];
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "box",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadCordonBoxCallback,
    pData: v2);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadCordonKeyCallback,
            pData: v2);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x00418170
// Name: public: static enum ChunkFileResult_t CManifest::LoadCordonsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadCordonsCallback(CChunkFile *pFile, CManifest *pManifest)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-Ch] BYREF

  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "cordon",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadCordonCallback,
    pData: pManifest);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CManifest::LoadCordonsKeyCallback,
            pData: pManifest);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x004181D0
// Name: public: static enum ChunkFileResult_t CManifest::LoadManifestCordoningPrefsCallback(class CChunkFile __near *,class CManifest __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CManifest::LoadManifestCordoningPrefsCallback(CChunkFile *pFile, CManifest *pDoc)
{
  ChunkFileResult_t Chunk; // edi
  LoadEntity_t LoadEntity; // [esp+8h] [ebp-1Ch] BYREF
  CChunkHandlerMap Handlers; // [esp+18h] [ebp-Ch] BYREF

  pDoc->m_CordoningMapEnt = (entity_t *)((char *)&unk_12E1028
                                       + (_DWORD)g_MainMap
                                       + 44 * (*(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap))++);
  memset(dst: (unsigned __int8 *)pDoc->m_CordoningMapEnt, value: 0, count: sizeof(entity_t));
  pDoc->m_CordoningMapEnt->firstbrush = g_MainMap->nummapbrushes;
  pDoc->m_CordoningMapEnt->numbrushes = 0;
  LoadEntity.pEntity = pDoc->m_CordoningMapEnt;
  LoadEntity.nBaseFlags = 0;
  LoadEntity.nBaseContents = 0;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "cordons",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadCordonsCallback,
    pData: pDoc);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadSolidCallback,
    pData: &LoadEntity);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x004182B0
// Name: private: bool CManifest::LoadVMFManifestUserPrefs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CManifest::LoadVMFManifestUserPrefs(CManifest *this, const char *pszFileName)
{
  unsigned int v3; // eax
  char *v4; // edi
  char v5; // cl
  CChunkFile File; // [esp+4h] [ebp-660h] BYREF
  char UserName[260]; // [esp+348h] [ebp-31Ch] BYREF
  char FileName[260]; // [esp+44Ch] [ebp-218h] BYREF
  char UserPrefsFileName[260]; // [esp+550h] [ebp-114h] BYREF
  CChunkHandlerMap Handlers; // [esp+654h] [ebp-10h] BYREF
  unsigned int UserNameSize; // [esp+660h] [ebp-4h] BYREF

  UserNameSize = 260;
  if ( !GetUserNameA(lpBuffer: UserName, pcbBuffer: &UserNameSize) )
    strcpy(UserPrefsFileName, "default");
  sprintf(string: UserPrefsFileName, format: "\\%s.vmm_prefs", UserName);
  V_StripExtension(in: pszFileName, out: FileName, outSize: 260);
  v3 = strlen(UserPrefsFileName) + 1;
  v4 = &UserName[259];
  do
    v5 = *++v4;
  while ( v5 != 0 );
  qmemcpy(v4, UserPrefsFileName, v3);
  if ( fopen(file: FileName, mode: "rb") == nullptr )
    return 0;
  CChunkFile::CChunkFile(this: &File);
  if ( CChunkFile::Open(this: &File, pszFileName: FileName, eMode: ChunkFile_Read) == ChunkFile_Ok )
  {
    CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "cordoning",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestCordoningPrefsCallback,
      pData: this);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    while ( CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr) == ChunkFile_Ok )
      ;
    CChunkFile::PopHandlers(this: &File);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  }
  CChunkFile::~CChunkFile(this: &File);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418410
// Name: public: bool CManifest::LoadVMFManifest(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CManifest::LoadVMFManifest(CManifest *this, const char *pszFileName)
{
  char *m_InstancePath; // esi
  ChunkFileResult_t v3; // eax
  const char *ErrorText; // eax
  ChunkFileResult_t v6; // eax
  ChunkFileResult_t v7; // ebx
  CMapFile *v8; // eax
  CMapFile *v9; // edi
  int m_Size; // eax
  int v11; // esi
  CMapFile **m_pMemory; // ecx
  int v13; // eax
  CMapFile **v14; // eax
  CMapFile *v15; // ecx
  CManifest *v16; // esi
  CChunkFile File; // [esp+Ch] [ebp-354h] BYREF
  CChunkHandlerMap Handlers; // [esp+350h] [ebp-10h] BYREF
  void *pData; // [esp+35Ch] [ebp-4h]

  m_InstancePath = this->m_InstancePath;
  pData = this;
  V_StripExtension(in: pszFileName, out: this->m_InstancePath, outSize: 260);
  strcat(m_InstancePath, "\\");
  CChunkFile::CChunkFile(this: &File);
  v3 = CChunkFile::Open(this: &File, pszFileName, eMode: ChunkFile_Read);
  if ( v3 != ChunkFile_Ok )
  {
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v3);
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      ErrorText,
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
    CChunkFile::~CChunkFile(this: &File);
    return false;
  }
  else
  {
    CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "Maps",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CManifest::LoadManifestMapsCallback,
      pData);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    do
    {
      v6 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
      v7 = v6;
    }
    while ( v6 == ChunkFile_Ok );
    if ( v6 == ChunkFile_EOF )
      v7 = ChunkFile_Ok;
    CChunkFile::PopHandlers(this: &File);
    if ( v7 == ChunkFile_Ok )
    {
      v8 = (CMapFile *)MemAlloc_Alloc(nSize: (unsigned int)&unk_1391044);
      if ( v8 != nullptr )
        v9 = CMapFile::CMapFile(this: v8);
      else
        v9 = nullptr;
      m_Size = g_Maps.m_Size;
      v11 = g_Maps.m_Size;
      if ( g_Maps.m_Size + 1 > g_Maps.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CClassInput *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_Maps,
          num: g_Maps.m_Size - g_Maps.m_Memory.m_nAllocationCount + 1);
        m_Size = g_Maps.m_Size;
      }
      m_pMemory = g_Maps.m_Memory.m_pMemory;
      g_Maps.m_Size = m_Size + 1;
      v13 = m_Size - v11;
      g_Maps.m_pElements = g_Maps.m_Memory.m_pMemory;
      if ( v13 > 0 )
      {
        _V_memmove(dest: &g_Maps.m_Memory.m_pMemory[v11 + 1], src: &g_Maps.m_Memory.m_pMemory[v11], count: 4 * v13);
        m_pMemory = g_Maps.m_Memory.m_pMemory;
      }
      v14 = &m_pMemory[v11];
      if ( v14 != nullptr )
      {
        *v14 = v9;
        m_pMemory = g_Maps.m_Memory.m_pMemory;
      }
      v15 = m_pMemory[v11];
      g_LoadingMap = v15;
      if ( g_MainMap == nullptr )
        g_MainMap = v15;
      v16 = (CManifest *)pData;
      CManifest::LoadSubMaps(this: (CManifest *)pData, pMapFile: v15, pszFileName);
      CManifest::LoadVMFManifestUserPrefs(this: v16, pszFileName);
    }
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    CChunkFile::~CChunkFile(this: &File);
    return v7 == ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004185E0
// Name: public: CManifest::CManifest(void)
// Source: json
//------------------------------------------------------------------------------
CManifest *__thiscall CManifest::CManifest(CManifest *this)
{
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  this->m_Cordons.m_Memory.m_pMemory = nullptr;
  this->m_Cordons.m_Memory.m_nAllocationCount = 0;
  this->m_Cordons.m_Memory.m_nGrowSize = 0;
  this->m_Cordons.m_Size = 0;
  this->m_Cordons.m_pElements = nullptr;
  this->m_InstancePath[0] = 0;
  this->m_bIsCordoning = false;
  this->m_CordoningMapEnt = nullptr;
  return this;
}
