// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/simplemapfile.cpp
// Functions: 58
// ============================================================

#include "vbsp2lib\simplemapfile.h"

//------------------------------------------------------------------------------
// Address: 0x100625B0
// Name: public: class Vector4D __near & Vector4D::operator=(class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::operator=(Vector4D *this, const Vector4D *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100625E0
// Name: public: static bool CInstancingHelper::ResolveInstancePath(class IFileSystem __near *,char const __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CInstancingHelper::ResolveInstancePath(
        IFileSystem *pFileSystem,
        char *pBaseFilename,
        char *pInstanceFilename,
        const char *pInstanceDirectory,
        char *pResolvedInstanceFilename,
        const char *nBufferSize)
{
  IBaseFileSystem *v6; // edi
  const char *v7; // ecx
  unsigned int v9; // eax
  char *v10; // ecx
  char instanceDirectoryRelativeFilename[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char fixedInstanceFilename[260]; // [esp+110h] [ebp-108h] BYREF
  char *pMapPathPosition; // [esp+214h] [ebp-4h]

  V_strncpy(pDest: fixedInstanceFilename, pSrc: pInstanceFilename, maxLen: 260);
  V_SetExtension(path: fixedInstanceFilename, extension: ".vmf", pathStringLength: 260);
  V_FixSlashes(pname: fixedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: fixedInstanceFilename);
  V_strncpy(pDest: pResolvedInstanceFilename, pSrc: pBaseFilename, maxLen: (int)nBufferSize);
  V_StripFilename(path: pResolvedInstanceFilename);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: "\\",
    destBufferSize: (unsigned int)nBufferSize,
    max_chars_to_copy: -1);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: fixedInstanceFilename,
    destBufferSize: (unsigned int)nBufferSize,
    max_chars_to_copy: -1);
  V_RemoveDotSlashes(pFilename: pResolvedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: pResolvedInstanceFilename);
  V_FixSlashes(pname: pResolvedInstanceFilename, separator: 92);
  v6 = &pFileSystem->IBaseFileSystem;
  if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: pResolvedInstanceFilename, a3: nullptr) )
    return 1;
  pMapPathPosition = V_stristr(a1: v7, a2: nBufferSize, pStr: pResolvedInstanceFilename, pSearch: "\\maps\\");
  if ( pMapPathPosition != nullptr )
  {
    v9 = _V_strlen(str: "\\maps\\");
    v10 = &pMapPathPosition[v9];
  }
  else
  {
    if ( V_strnicmp(s1: pResolvedInstanceFilename, s2: "maps\\", n: 5) != 0 )
      goto LABEL_9;
    v10 = pResolvedInstanceFilename + 5;
  }
  if ( v10 != nullptr )
  {
    *v10 = 0;
    V_strncat(
      pDest: pResolvedInstanceFilename,
      pSrc: fixedInstanceFilename,
      destBufferSize: (unsigned int)nBufferSize,
      max_chars_to_copy: -1);
    if ( v6->FileExists(this: v6, a2: pResolvedInstanceFilename, a3: nullptr) )
      return 1;
  }
LABEL_9:
  if ( *pInstanceDirectory != 0 )
  {
    V_snprintf(
      pDest: instanceDirectoryRelativeFilename,
      maxLen: (unsigned int)nBufferSize,
      pFormat: "%s/%s",
      pInstanceDirectory,
      fixedInstanceFilename);
    V_SetExtension(path: instanceDirectoryRelativeFilename, extension: ".vmf", pathStringLength: 260);
    V_FixSlashes(pname: instanceDirectoryRelativeFilename, separator: 92);
    V_RemoveDotSlashes(pFilename: instanceDirectoryRelativeFilename, separator: 92);
    V_FixDoubleSlashes(pStr: instanceDirectoryRelativeFilename);
    pFileSystem->RelativePathToFullPath(
      this: pFileSystem,
      a2: instanceDirectoryRelativeFilename,
      a3: "GAME",
      a4: pResolvedInstanceFilename,
      a5: (int)nBufferSize,
      a6: FILTER_NONE,
      a7: nullptr);
    if ( v6->FileExists(this: v6, a2: instanceDirectoryRelativeFilename, a3: "GAME") )
      return 1;
  }
  pFileSystem->RelativePathToFullPath(
    this: pFileSystem,
    a2: fixedInstanceFilename,
    a3: "GAME",
    a4: pResolvedInstanceFilename,
    a5: (int)nBufferSize,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( v6->FileExists(this: v6, a2: fixedInstanceFilename, a3: "GAME") )
    return 1;
  if ( (int)nBufferSize > 0 )
    *pResolvedInstanceFilename = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10062800
// Name: struct MapEntityKeyValuePair_t const __near * FindPair(char const __near *,struct MapEntityKeyValuePair_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
MapEntityKeyValuePair_t *__cdecl FindPair(const char *pKeyName, MapEntityKeyValuePair_t *pPairs, int nNumPairs)
{
  int v3; // esi
  MapEntityKeyValuePair_t *i; // edi

  v3 = 0;
  if ( nNumPairs <= 0 )
    return nullptr;
  for ( i = pPairs; _V_stricmp(s1: i->m_pKey, s2: pKeyName) != 0; ++i )
  {
    if ( ++v3 >= nNumPairs )
      return nullptr;
  }
  return &pPairs[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10062850
// Name: char const __near * GetPairValue(struct MapEntityKeyValuePair_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetPairValue(const MapEntityKeyValuePair_t *pPair)
{
  const char *result; // eax

  if ( pPair == nullptr )
    return szDescription;
  result = pPair->m_pValue;
  if ( result == nullptr )
    return szDescription;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062870
// Name: public: struct MapBrushTexture_t __near & MapBrushTexture_t::operator=(struct MapBrushTexture_t const __near &)
// Source: json
//------------------------------------------------------------------------------
MapBrushTexture_t *__thiscall MapBrushTexture_t::operator=(MapBrushTexture_t *this, const MapBrushTexture_t *__that)
{
  MapBrushTexture_t *result; // eax
  char *m_MaterialName; // esi
  int v4; // edx

  result = this;
  this->m_vUAxis = __that->m_vUAxis;
  m_MaterialName = this->m_MaterialName;
  v4 = 128;
  this->m_vVAxis = __that->m_vVAxis;
  *(_QWORD *)this->m_flShift = *(_QWORD *)__that->m_flShift;
  *(_QWORD *)this->m_flTextureWorldUnitsPerTexel = *(_QWORD *)__that->m_flTextureWorldUnitsPerTexel;
  this->m_flLightmapWorldUnitsPerLuxel = __that->m_flLightmapWorldUnitsPerLuxel;
  do
  {
    *m_MaterialName = m_MaterialName[(char *)__that - (char *)this];
    ++m_MaterialName;
    --v4;
  }
  while ( v4 != 0 );
  this->m_SurfaceFlags = __that->m_SurfaceFlags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062900
// Name: private: void CSimpleMapFile::FixupInstanceKeyValuePair(struct MapEntityKeyValuePair_t __near *,char const __near *,struct MapEntityKeyValuePair_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::FixupInstanceKeyValuePair(
        CSimpleMapFile *this,
        MapEntityKeyValuePair_t *pNewKeyValuePair,
        char *pOriginalValue,
        const MapEntityKeyValuePair_t *pInstancePairs,
        int nNumPairs)
{
  int i; // ebx
  unsigned int v7; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // esi
  char tempCopy[1024]; // [esp+4h] [ebp-C04h] BYREF
  char replaceValue[1024]; // [esp+404h] [ebp-804h] BYREF
  char newValue[1024]; // [esp+804h] [ebp-404h] BYREF
  CSimpleMapFile *v13; // [esp+C04h] [ebp-4h]

  v13 = this;
  V_strncpy(pDest: newValue, pSrc: pOriginalValue, maxLen: 1024);
  for ( i = 0; i < nNumPairs; ++pInstancePairs )
  {
    v7 = _V_strlen(str: "replace");
    if ( V_strnicmp(s1: pInstancePairs->m_pKey, s2: "replace", n: v7) == 0 )
    {
      V_strncpy(pDest: replaceValue, pSrc: (char *)pInstancePairs->m_pValue, maxLen: 1024);
      strchr(string: replaceValue, chr: 0x20u);
      v9 = v8;
      if ( v8 != nullptr )
      {
        *v8 = 0;
        V_strncpy(pDest: tempCopy, pSrc: newValue, maxLen: 1024);
        if ( !V_StrSubst(
                pIn: tempCopy,
                pMatch: replaceValue,
                pReplaceWith: v9 + 1,
                pOut: newValue,
                outLen: 1024,
                bCaseSensitive: false) )
          break;
      }
    }
    ++i;
  }
  pNewKeyValuePair->m_pValue = CStringPool::Allocate(this: &v13->m_KeyValueStringPool, pszValue: newValue);
}

//------------------------------------------------------------------------------
// Address: 0x10062A10
// Name: StringIsTrue
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall StringIsTrue@<eax>(const char *str@<esi>)
{
  return CRoomTemplateListPanel::CompareFolders(s1: str, s2: "true") == 0
      || CRoomTemplateListPanel::CompareFolders(s1: str, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10062A40
// Name: public: void CUtlMemory<struct CMapDisplacement::Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapDisplacement::Vertex_t,int>::Grow(
        CUtlMemory<CMapDisplacement::Vertex_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMapDisplacement::Vertex_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMapDisplacement::Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CMapDisplacement::Vertex_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062AE0
// Name: private: void CSimpleMapFile::ReportParseError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::ReportParseError(CSimpleMapFile *this, const char *pErrorString)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
}

//------------------------------------------------------------------------------
// Address: 0x10062D20
// Name: public: void CUtlMemory<struct CSimpleMapFile::MaterialInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSimpleMapFile::MaterialInfo_t,int>::Grow(
        CUtlMemory<CSimpleMapFile::MaterialInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSimpleMapFile::MaterialInfo_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 136 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSimpleMapFile::MaterialInfo_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CSimpleMapFile::MaterialInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062DC0
// Name: public: int CSimpleMapFile::FindEntity(char const __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::FindEntity(
        CSimpleMapFile *this,
        const char *pClassName,
        const char *pKeyName,
        const char *pValue,
        int nStartingIndex)
{
  int v5; // eax
  int v6; // esi
  MapEntityKeyValuePair_t *v7; // ebx
  int v8; // edi
  MapEntityKeyValuePair_t *v9; // eax
  const char *m_pValue; // eax
  int v11; // edi
  const char **p_m_pKey; // ebx
  MapEntityKeyValuePair_t *v13; // eax
  CSimpleMapFile *v15; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  MapEntityKeyValuePair_t *pEntityPairs; // [esp+14h] [ebp-4h]

  v15 = this;
  if ( nStartingIndex >= this->m_Entities.m_Size )
    return -1;
  v5 = 28 * nStartingIndex;
  for ( i = 28 * nStartingIndex; ; v5 = i )
  {
    v6 = *(int *)((char *)&this->m_Entities.m_Memory.m_pMemory->m_nFirstKVPairIndex + v5);
    v7 = &this->m_KeyValuePairs.m_Memory.m_pMemory[v6];
    v8 = 0;
    pEntityPairs = v7;
    if ( v6 <= 0 )
      goto LABEL_10;
    while ( _V_stricmp(s1: v7->m_pKey, s2: "classname") != 0 )
    {
      ++v8;
      ++v7;
      if ( v8 >= v6 )
        goto LABEL_10;
    }
    v9 = &pEntityPairs[v8];
    if ( v9 == nullptr || (m_pValue = v9->m_pValue) == nullptr )
LABEL_10:
      m_pValue = szDescription;
    if ( pClassName == nullptr || _V_stricmp(s1: pClassName, s2: m_pValue) == 0 )
    {
      if ( pKeyName == nullptr )
        break;
      v11 = 0;
      if ( v6 <= 0 )
      {
LABEL_18:
        v13 = nullptr;
      }
      else
      {
        p_m_pKey = &pEntityPairs->m_pKey;
        while ( _V_stricmp(s1: *p_m_pKey, s2: pKeyName) != 0 )
        {
          ++v11;
          p_m_pKey += 3;
          if ( v11 >= v6 )
            goto LABEL_18;
        }
        v13 = &pEntityPairs[v11];
      }
      if ( pValue == nullptr || _V_stricmp(s1: v13->m_pValue, s2: pValue) == 0 )
        break;
    }
    this = v15;
    i += 28;
    if ( ++nStartingIndex >= v15->m_Entities.m_Size )
      return -1;
  }
  return nStartingIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10062EF0
// Name: private: int CSimpleMapFile::ComputeBrushContents(struct MapBrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSimpleMapFile::ComputeBrushContents(CSimpleMapFile *this, MapBrush_t *pBrush)
{
  int m_nNumSides; // esi
  MapBrushSide_t *v3; // edx
  int v4; // ecx
  unsigned int result; // eax

  m_nNumSides = pBrush->m_nNumSides;
  v3 = &this->m_BrushSides.m_Memory.m_pMemory[pBrush->m_nFirstSideIndex];
  v4 = 0;
  result = v3->m_ContentsFlags;
  if ( m_nNumSides > 0 )
  {
    do
    {
      v4 |= v3->m_ContentsFlags;
      ++v3;
      --m_nNumSides;
    }
    while ( m_nNumSides != 0 );
  }
  if ( (v4 & 0x3A) != 0 )
    result = v4 & 0x3A | result & 0xEFFFFFFE | 0x10000000;
  if ( (v4 & 0x20000000) != 0 )
    result |= 0x20000000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062F40
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementNormalsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementNormalsKeyHandler(const char *pKey, char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  int v5; // esi
  int v6; // edi
  const char *v7; // ebx
  int v8; // eax
  int v9; // edi
  HashedPlane_t *m_pElements; // esi
  HashedPlane_t *v11; // esi
  HashedPlane_t *v12; // esi
  char *v13; // eax
  char valueBuf[1024]; // [esp+8h] [ebp-414h] BYREF
  int nRow; // [esp+408h] [ebp-14h]
  int nColumns; // [esp+40Ch] [ebp-10h]
  char *pVal1; // [esp+410h] [ebp-Ch]
  char *pVal2; // [esp+414h] [ebp-8h]
  int nIndex; // [esp+418h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) == 0 )
    {
      V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
      nColumns = (1 << (int)pData[1]->m_pFileSystem) + 1;
      v5 = nColumns;
      v6 = atoi(nptr: pKey + 3);
      nRow = v6;
      if ( v6 >= v5 )
      {
        CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement normals.");
        return 1;
      }
      v7 = strtok(string: valueBuf, control: " ");
      pVal1 = strtok(string: nullptr, control: " ");
      pVal2 = strtok(string: nullptr, control: " ");
      v8 = v5 * v6;
      nIndex = v5 * v6;
      if ( v7 != nullptr )
      {
        v9 = 4 * v8;
        while ( pVal1 != nullptr && pVal2 != nullptr )
        {
          if ( v8 >= v5 * (nRow + 1) )
          {
            CSimpleMapFile::ReportParseError(
              this: *pData,
              pErrorString: "Too many elements in displacement normal row.");
            return 1;
          }
          m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          m_pElements[v9].m_vNormal.z = atof(nptr: v7);
          v11 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v11[v9].m_flDistance = atof(nptr: pVal1);
          v12 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          *(float *)&v12[v9].m_Type = atof(nptr: pVal2);
          v7 = strtok(string: nullptr, control: " ");
          pVal1 = strtok(string: nullptr, control: " ");
          v13 = strtok(string: nullptr, control: " ");
          ++nIndex;
          v9 += 4;
          pVal2 = v13;
          if ( v7 == nullptr )
            return 0;
          v5 = nColumns;
          v8 = nIndex;
        }
      }
    }
    return 0;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063130
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementDistancesKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementDistancesKeyHandler(const char *pKey, char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  int v5; // ebx
  int v6; // esi
  const char *v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // ebx
  HashedPlane_t *m_pElements; // esi
  char valueBuf[1024]; // [esp+8h] [ebp-404h] BYREF
  int v13; // [esp+408h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v5 = (1 << (int)pData[1]->m_pFileSystem) + 1;
    v6 = atoi(nptr: pKey + 3);
    if ( v6 >= v5 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement distances.");
      return 1;
    }
    v7 = strtok(string: valueBuf, control: " ");
    v8 = v5 * v6;
    if ( v7 == nullptr )
    {
      return 0;
    }
    else
    {
      v9 = v5 * (v6 + 1);
      v13 = v9;
      v10 = 4 * v8;
      while ( v8 < v9 )
      {
        m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
        m_pElements[v10].m_vNormal.y = atof(nptr: v7);
        v7 = strtok(string: nullptr, control: " ");
        ++v8;
        v10 += 4;
        if ( v7 == nullptr )
          return 0;
        v9 = v13;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many elements in displacement distance row.");
      return 1;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063290
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementOffsetsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementOffsetsKeyHandler(const char *pKey, char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  int v5; // esi
  int v6; // edi
  const char *v7; // ebx
  int v8; // eax
  int v9; // edi
  HashedPlane_t *m_pElements; // esi
  HashedPlane_t *v11; // esi
  HashedPlane_t *v12; // esi
  char *v13; // eax
  char valueBuf[1024]; // [esp+8h] [ebp-414h] BYREF
  int nRow; // [esp+408h] [ebp-14h]
  int nColumns; // [esp+40Ch] [ebp-10h]
  char *pVal1; // [esp+410h] [ebp-Ch]
  char *pVal2; // [esp+414h] [ebp-8h]
  int nIndex; // [esp+418h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) == 0 )
    {
      V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
      nColumns = (1 << (int)pData[1]->m_pFileSystem) + 1;
      v5 = nColumns;
      v6 = atoi(nptr: pKey + 3);
      nRow = v6;
      if ( v6 >= v5 )
      {
        CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement offsets.");
        return 1;
      }
      v7 = strtok(string: valueBuf, control: " ");
      pVal1 = strtok(string: nullptr, control: " ");
      pVal2 = strtok(string: nullptr, control: " ");
      v8 = v5 * v6;
      nIndex = v5 * v6;
      if ( v7 != nullptr )
      {
        v9 = 4 * v8;
        while ( pVal1 != nullptr && pVal2 != nullptr )
        {
          if ( v8 >= v5 * (nRow + 1) )
          {
            CSimpleMapFile::ReportParseError(
              this: *pData,
              pErrorString: "Too many elements in displacement offset row.");
            return 1;
          }
          m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          *(float *)&m_pElements[v9].m_nNextPlaneIndex = atof(nptr: v7);
          v11 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v11[v9 + 1].m_vNormal.x = atof(nptr: pVal1);
          v12 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v12[v9 + 1].m_vNormal.y = atof(nptr: pVal2);
          v7 = strtok(string: nullptr, control: " ");
          pVal1 = strtok(string: nullptr, control: " ");
          v13 = strtok(string: nullptr, control: " ");
          ++nIndex;
          v9 += 4;
          pVal2 = v13;
          if ( v7 == nullptr )
            return 0;
          v5 = nColumns;
          v8 = nIndex;
        }
      }
    }
    return 0;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063480
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementAlphasKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementAlphasKeyHandler(const char *pKey, char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  int v5; // ebx
  int v6; // esi
  const char *v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // ebx
  HashedPlane_t *m_pElements; // esi
  char valueBuf[1024]; // [esp+8h] [ebp-404h] BYREF
  int v13; // [esp+408h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v5 = (1 << (int)pData[1]->m_pFileSystem) + 1;
    v6 = atoi(nptr: pKey + 3);
    if ( v6 >= v5 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement alpha.");
      return 1;
    }
    v7 = strtok(string: valueBuf, control: " ");
    v8 = v5 * v6;
    if ( v7 == nullptr )
    {
      return 0;
    }
    else
    {
      v9 = v5 * (v6 + 1);
      v13 = v9;
      v10 = 4 * v8;
      while ( v8 < v9 )
      {
        m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
        m_pElements[v10].m_vNormal.x = atof(nptr: v7);
        v7 = strtok(string: nullptr, control: " ");
        ++v8;
        v10 += 4;
        if ( v7 == nullptr )
          return 0;
        v9 = v13;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many elements in displacement alpha row.");
      return 1;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100635E0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementTriangleTagsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementTriangleTagsKeyHandler(const char *pKey, char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  int v5; // edi
  int v6; // ebx
  const char *v7; // eax
  int v8; // esi
  int v9; // ebx
  char v10; // al
  char v11; // cl
  bool v12; // dl
  __int16 v13; // ax
  char valueBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v5 = 1 << (int)pData[1]->m_pFileSystem;
    v6 = atoi(nptr: pKey + 3);
    if ( v6 >= v5 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement triangle tags.");
      return 1;
    }
    v7 = strtok(string: valueBuf, control: " ");
    v8 = 2 * v5 * v6;
    if ( v7 == nullptr )
    {
      return 0;
    }
    else
    {
      v9 = 2 * v5 * (v6 + 1);
      while ( v8 < v9 )
      {
        v10 = atoi(nptr: v7);
        v11 = v10 & 1;
        if ( (v10 & 2) != 0 )
          v11 = (v10 & 4) != 0;
        v12 = (v10 & 8) != 0;
        if ( (v10 & 0x10) != 0 )
          v12 = (v10 & 0x20) != 0;
        v13 = 0;
        if ( v11 != 0 )
          v13 = 2;
        if ( v12 )
          v13 |= 4u;
        *(_WORD *)(pData[1]->m_PlaneHash.m_HashTable[4] + 2 * v8) = v13;
        v7 = strtok(string: nullptr, control: " ");
        ++v8;
        if ( v7 == nullptr )
          return 0;
      }
      CSimpleMapFile::ReportParseError(
        this: *pData,
        pErrorString: "Too many elements in displacement triangle tags row.");
      return 1;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063770
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendKeyHandler(
        const char *pKey,
        const char *pValue,
        _DWORD **pData)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  int v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vMultiBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: pKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, pValue);
  v3 = (1 << *pData[1]) + 1;
  v4 = atoi(nptr: pKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = 96 * v6;
    do
    {
      vMultiBlend.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlend.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlend.z = atof(nptr: v9);
      v10 = strtok(string: nullptr, control: " ");
      vMultiBlend.w = atof(nptr: v10);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector4D *)(pData[1][7] + v7 + 32) = vMultiBlend;
      v7 += 96;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10063880
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColorKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColorKeyHandler(
        const char *pKey,
        const char *pValue,
        _DWORD **pData)
{
  int v3; // edi
  int v4; // ebx
  const char *v5; // eax
  int v6; // ebx
  int v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  char szBuf[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vMultiBlendColor; // [esp+404h] [ebp-Ch]

  if ( V_strncasecmp(s1: pKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, pValue);
  v3 = (1 << *pData[1]) + 1;
  v4 = atoi(nptr: pKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = 2 * v6;
    do
    {
      vMultiBlendColor.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.z = atof(nptr: v9);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector *)(pData[1][7] + 12 * (_DWORD)&pData[2][v7 + 1]) = vMultiBlendColor;
      v7 += 2;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x10063980
// Name: private: void CSimpleMapFile::MakeBrushPolygons(struct MapBrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MakeBrushPolygons(CSimpleMapFile *this, MapBrush_t *pBrush)
{
  MapBrushSide_t *v4; // eax
  HashedPlane_t *v5; // ecx
  Polygon_t *p_m_Polygon; // esi
  int v7; // eax
  int v8; // eax
  Vector *p_m_vMaxBounds; // eax
  bool v10; // zf
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]
  int v14; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  Vector *v16; // [esp+1Ch] [ebp+8h]

  ClearBounds(mins: &pBrush->m_vMinBounds, maxs: &pBrush->m_vMaxBounds);
  for ( i = 0; i < pBrush->m_nNumSides; ++i )
  {
    v4 = &this->m_BrushSides.m_Memory.m_pMemory[i + pBrush->m_nFirstSideIndex];
    v5 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v4->m_nPlaneIndex];
    p_m_Polygon = &v4->m_Polygon;
    v4->m_Polygon.m_Points.m_Size = 0;
    CreatePolygonFromPlane(vNormal: &v5->m_vNormal, flDistance: v5->m_flDistance, pPolygon: &v4->m_Polygon);
    v7 = 0;
    for ( j = 0; v7 < pBrush->m_nNumSides; j = v7 )
    {
      if ( i != v7 )
      {
        v8 = this->m_BrushSides.m_Memory.m_pMemory[v7 + pBrush->m_nFirstSideIndex].m_nPlaneIndex ^ 1;
        ChopPolygonInPlace(
          pPolygon: p_m_Polygon,
          vNormal: &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v8].m_vNormal,
          flDistance: this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v8].m_flDistance);
        v7 = j;
      }
      ++v7;
    }
    v11 = 0;
    if ( p_m_Polygon->m_Points.m_Size > 0 )
    {
      v14 = 0;
      do
      {
        AddPointToBounds(
          v: &p_m_Polygon->m_Points.m_Memory.m_pMemory[v14++],
          mins: &pBrush->m_vMinBounds,
          maxs: &pBrush->m_vMaxBounds);
        ++v11;
      }
      while ( v11 < p_m_Polygon->m_Points.m_Size );
    }
  }
  p_m_vMaxBounds = &pBrush->m_vMaxBounds;
  v16 = &pBrush->m_vMaxBounds;
  v12 = 3;
  do
  {
    if ( p_m_vMaxBounds[-1].x < -16384.0 || p_m_vMaxBounds->x > 16384.0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Brush %d: bounds out of range.\n");
      p_m_vMaxBounds = v16;
    }
    if ( p_m_vMaxBounds[-1].x > 16384.0 || p_m_vMaxBounds->x < -16384.0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Brush %d: no visible sides on brush.\n");
      p_m_vMaxBounds = v16;
    }
    p_m_vMaxBounds = (Vector *)((char *)p_m_vMaxBounds + 4);
    v10 = v12-- == 1;
    v16 = p_m_vMaxBounds;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x10063B70
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementNormalsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementNormalsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementNormalsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063B90
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementDistancesChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementDistancesChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementDistancesKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063BB0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementOffsetsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementOffsetsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementOffsetsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063BD0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementAlphasChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementAlphasChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementAlphasKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063BF0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementTriangleTagsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementTriangleTagsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementTriangleTagsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063C10
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendChunkHandler(CChunkFile *pFile, _DWORD *pData)
{
  *(_DWORD *)(pData[1] + 8) |= 0x40000000u;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063C30
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor0(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor0(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063C50
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor1(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor1(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 1;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063C70
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor2(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor2(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 2;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063C90
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor3(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor3(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 3;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x10063E70
// Name: private: struct MapEntity_t __near * CSimpleMapFile::AllocateNewEntity(void)
// Source: json
//------------------------------------------------------------------------------
MapEntity_t *__thiscall CSimpleMapFile::AllocateNewEntity(CSimpleMapFile *this)
{
  CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int> > *p_m_Entities; // esi
  int v3; // eax

  p_m_Entities = &this->m_Entities;
  CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int>>::InsertBefore(
    this: &this->m_Entities,
    elem: this->m_Entities.m_Size);
  v3 = (int)&p_m_Entities->m_Memory.m_pMemory[this->m_Entities.m_Size - 1];
  *(_QWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0;
  *(_QWORD *)(v3 + 16) = 0;
  *(_DWORD *)(v3 + 24) = 0;
  return &p_m_Entities->m_Memory.m_pMemory[this->m_Entities.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10063ED0
// Name: private: struct MapBrush_t __near * CSimpleMapFile::AllocateNewBrush(void)
// Source: json
//------------------------------------------------------------------------------
MapBrush_t *__thiscall CSimpleMapFile::AllocateNewBrush(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapBrush_t *m_pMemory; // ecx
  int v5; // eax
  MapBrush_t *v6; // eax

  m_nAllocationCount = this->m_Brushes.m_Memory.m_nAllocationCount;
  m_Size = this->m_Brushes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTilegenRule::SubstitutionVariable_t,int>::Grow(
      this: &this->m_Brushes.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Brushes.m_Size;
  m_pMemory = this->m_Brushes.m_Memory.m_pMemory;
  v5 = this->m_Brushes.m_Size - m_Size - 1;
  this->m_Brushes.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 36 * v5);
  v6 = &this->m_Brushes.m_Memory.m_pMemory[this->m_Brushes.m_Size - 1];
  *(_QWORD *)&v6->m_ContentsFlags = 0;
  *(_QWORD *)&v6->m_nNumSides = 0;
  *(_QWORD *)&v6->m_vMinBounds.y = 0;
  *(_QWORD *)&v6->m_vMaxBounds.x = 0;
  v6->m_vMaxBounds.z = 0.0;
  return &this->m_Brushes.m_Memory.m_pMemory[this->m_Brushes.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10063F80
// Name: private: struct MapBrushTexture_t __near * CSimpleMapFile::AllocateNewBrushTexture(void)
// Source: json
//------------------------------------------------------------------------------
MapBrushTexture_t *__thiscall CSimpleMapFile::AllocateNewBrushTexture(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapBrushTexture_t *m_pMemory; // ecx
  int v5; // eax
  unsigned __int8 *v6; // esi

  m_nAllocationCount = this->m_BrushTextures.m_Memory.m_nAllocationCount;
  m_Size = this->m_BrushTextures.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapBrushTexture_t,int>::Grow(this: &this->m_BrushTextures.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_BrushTextures.m_Size;
  m_pMemory = this->m_BrushTextures.m_Memory.m_pMemory;
  v5 = this->m_BrushTextures.m_Size - m_Size - 1;
  this->m_BrushTextures.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 176 * v5);
  v6 = (unsigned __int8 *)&this->m_BrushTextures.m_Memory.m_pMemory[this->m_BrushTextures.m_Size - 1];
  memset(dst: v6, value: 0, count: 0xB0u);
  return (MapBrushTexture_t *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x10064020
// Name: private: struct MapEntityKeyValuePair_t __near * CSimpleMapFile::AllocateNewKeyValuePair(void)
// Source: json
//------------------------------------------------------------------------------
MapEntityKeyValuePair_t *__thiscall CSimpleMapFile::AllocateNewKeyValuePair(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapEntityKeyValuePair_t *m_pMemory; // ecx
  int v5; // eax
  MapEntityKeyValuePair_t *result; // eax

  m_nAllocationCount = this->m_KeyValuePairs.m_Memory.m_nAllocationCount;
  m_Size = this->m_KeyValuePairs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_KeyValuePairs,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_KeyValuePairs.m_Size;
  m_pMemory = this->m_KeyValuePairs.m_Memory.m_pMemory;
  v5 = this->m_KeyValuePairs.m_Size - m_Size - 1;
  this->m_KeyValuePairs.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 12 * v5);
  result = &this->m_KeyValuePairs.m_Memory.m_pMemory[this->m_KeyValuePairs.m_Size - 1];
  *(_QWORD *)&result->m_pKey = 0;
  *(_DWORD *)&result->m_bIsConnection = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100640B0
// Name: private: void CSimpleMapFile::MoveEntityBrushesToWorld(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MoveEntityBrushesToWorld(CSimpleMapFile *this, int nEntityIndex)
{
  MapEntity_t *m_pMemory; // eax
  int m_nNumBrushes; // ebx
  MapEntity_t *v5; // ecx
  MapBrush_t *v6; // edx
  int v7; // edi
  MapBrush_t *v8; // ebx
  int v9; // ecx
  MapEntity_t *v10; // eax
  int m_nFirstBrushIndex; // edx
  MapEntity_t *v12; // eax
  const MapBrush_t *v13; // [esp-4h] [ebp-28h]
  CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int> > tempMapBrushes; // [esp+Ch] [ebp-18h] BYREF
  MapEntity_t *pEntity; // [esp+20h] [ebp-4h]
  int nEntityIndexb; // [esp+2Ch] [ebp+8h]
  int nEntityIndexa; // [esp+2Ch] [ebp+8h]

  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  m_nNumBrushes = m_pMemory->m_nNumBrushes;
  v5 = &m_pMemory[nEntityIndex];
  v6 = this->m_Brushes.m_Memory.m_pMemory;
  v7 = v5->m_nNumBrushes;
  pEntity = v5;
  v13 = &v6[v5->m_nFirstBrushIndex];
  memset(&tempMapBrushes, 0, sizeof(tempMapBrushes));
  CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int>>::InsertMultipleBefore(
    this: &tempMapBrushes,
    elem: 0,
    num: v7,
    pToInsert: v13);
  nEntityIndexb = m_nNumBrushes;
  memmove(
    dst: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[v7 + m_nNumBrushes],
    src: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[m_nNumBrushes],
    count: 36 * (pEntity->m_nFirstBrushIndex - m_nNumBrushes));
  v8 = tempMapBrushes.m_Memory.m_pMemory;
  memcpy(
    dst: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[nEntityIndexb],
    src: (unsigned __int8 *)tempMapBrushes.m_Memory.m_pMemory,
    count: 36 * v7);
  v9 = 1;
  if ( this->m_Entities.m_Size > 1 )
  {
    nEntityIndexa = 1;
    do
    {
      v10 = &this->m_Entities.m_Memory.m_pMemory[nEntityIndexa];
      m_nFirstBrushIndex = v10->m_nFirstBrushIndex;
      if ( m_nFirstBrushIndex < pEntity->m_nFirstBrushIndex )
        v10->m_nFirstBrushIndex = v7 + m_nFirstBrushIndex;
      ++nEntityIndexa;
      ++v9;
    }
    while ( v9 < this->m_Entities.m_Size );
    v8 = tempMapBrushes.m_Memory.m_pMemory;
  }
  this->m_Entities.m_Memory.m_pMemory->m_nNumBrushes += v7;
  v12 = pEntity;
  pEntity->m_nNumBrushes = 0;
  v12->m_nNumKVPairs = 0;
  if ( tempMapBrushes.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x100641D0
// Name: private: int CSimpleMapFile::FindOrCreateTextureData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::FindOrCreateTextureData(CSimpleMapFile *this, const char *pTextureName)
{
  int v3; // esi
  int v4; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapTextureData_t *m_pMemory; // ecx
  int v8; // eax
  MapTextureData_t *v9; // esi
  void *Material; // ebx
  bool found; // [esp+Fh] [ebp-1h] BYREF

  v3 = 0;
  if ( this->m_TextureData.m_Size <= 0 )
  {
LABEL_5:
    m_Size = this->m_TextureData.m_Size;
    m_nAllocationCount = this->m_TextureData.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<MapTextureData_t,int>::Grow(this: &this->m_TextureData.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_TextureData.m_Size;
    m_pMemory = this->m_TextureData.m_Memory.m_pMemory;
    v8 = this->m_TextureData.m_Size - m_Size - 1;
    this->m_TextureData.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 148 * v8);
    v9 = &this->m_TextureData.m_Memory.m_pMemory[this->m_TextureData.m_Size - 1];
    memset(dst: (unsigned __int8 *)v9, value: 0, count: sizeof(MapTextureData_t));
    _V_strcpy(dest: v9->m_MaterialName, src: pTextureName);
    Material = FindMaterial(materialName: pTextureName, pFound: &found, bComplain: true);
    if ( Material != nullptr )
    {
      GetMaterialDimensions(materialHandle: Material, width: &v9->m_nWidth, height: &v9->m_nHeight);
      GetMaterialReflectivity(materialHandle: Material, reflectivityVect: &v9->m_vReflectivity.x);
    }
    else
    {
      v9->m_nHeight = 0;
      v9->m_nWidth = 0;
      v9->m_vReflectivity = vec3_origin;
    }
    return this->m_TextureData.m_Size - 1;
  }
  else
  {
    v4 = 0;
    while ( _V_stricmp(s1: pTextureName, s2: this->m_TextureData.m_Memory.m_pMemory[v4].m_MaterialName) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->m_TextureData.m_Size )
        goto LABEL_5;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064330
// Name: private: int CSimpleMapFile::FindOrCreateTextureInfo(struct MapTextureInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::FindOrCreateTextureInfo(CSimpleMapFile *this, MapTextureInfo_t *textureInfo)
{
  int v3; // esi
  int v4; // edi
  MapTextureInfo_t *v5; // eax
  int m_nTextureDataIndex; // edx
  _DWORD *v7; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  MapTextureInfo_t *m_pMemory; // ecx
  int v11; // eax
  MapTextureInfo_t *v12; // edi

  v3 = 0;
  if ( this->m_TextureInfos.m_Size <= 0 )
  {
LABEL_6:
    m_Size = this->m_TextureInfos.m_Size;
    m_nAllocationCount = this->m_TextureInfos.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_TextureInfos.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_TextureInfos.m_Size;
    m_pMemory = this->m_TextureInfos.m_Memory.m_pMemory;
    v11 = this->m_TextureInfos.m_Size - m_Size - 1;
    this->m_TextureInfos.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 72 * v11);
    v12 = &this->m_TextureInfos.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      qmemcpy(v12, textureInfo, sizeof(MapTextureInfo_t));
    return this->m_TextureInfos.m_Size - 1;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = this->m_TextureInfos.m_Memory.m_pMemory;
      m_nTextureDataIndex = v5[v4].m_nTextureDataIndex;
      v7 = (_DWORD *)v5[v4].m_flTextureVectors[0];
      if ( m_nTextureDataIndex == textureInfo->m_nTextureDataIndex
        && _V_memcmp(m1: v7, m2: textureInfo, count: 0x48u) == 0 )
      {
        return v3;
      }
      ++v3;
      ++v4;
      if ( v3 >= this->m_TextureInfos.m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064420
// Name: private: void CSimpleMapFile::PreLoadInstances(class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::PreLoadInstances(CSimpleMapFile *this, GameData *pGD)
{
  CSimpleMapFile *v2; // esi
  MapEntity_t *v3; // ebx
  int m_nNumKVPairs; // edi
  MapEntityKeyValuePair_t *v5; // eax
  int v6; // esi
  MapEntityKeyValuePair_t *v7; // eax
  const char *m_pValue; // eax
  GDclass *v9; // eax
  bool v10; // cc
  GDinputvariable *VariableAt; // eax
  int v12; // edi
  int v13; // esi
  MapEntityKeyValuePair_t *v14; // ebx
  MapEntityKeyValuePair_t *NewKeyValuePair; // esi
  const char *v16; // eax
  char *m_szName; // edi
  char remappedValue[1024]; // [esp+8h] [ebp-4B8h] BYREF
  char NameFixup[128]; // [esp+408h] [ebp-B8h] BYREF
  Vector InstanceOrigin; // [esp+488h] [ebp-38h] BYREF
  QAngle InstanceAngle; // [esp+494h] [ebp-2Ch] BYREF
  int i; // [esp+4A0h] [ebp-20h]
  GDclass *pEntClass; // [esp+4A4h] [ebp-1Ch]
  GDinputvariable *pEntityGDVariable; // [esp+4A8h] [ebp-18h]
  unsigned int v25; // [esp+4ACh] [ebp-14h]
  MapEntity_t *pEntity; // [esp+4B0h] [ebp-10h]
  MapEntityKeyValuePair_t *pEntityPairs; // [esp+4B4h] [ebp-Ch]
  CSimpleMapFile *v28; // [esp+4B8h] [ebp-8h]
  int iIndex; // [esp+4BCh] [ebp-4h]

  v2 = this;
  v28 = this;
  memset(NameFixup, 0, sizeof(NameFixup));
  InstanceOrigin = vec3_origin;
  InstanceAngle = vec3_angle;
  GameData::BeginInstancing(this: pGD, nPass: 2);
  i = 0;
  if ( v2->m_Entities.m_Size > 0 )
  {
    v25 = 0;
    while ( 1 )
    {
      v3 = &v2->m_Entities.m_Memory.m_pMemory[v25 / 0x1C];
      m_nNumKVPairs = v3->m_nNumKVPairs;
      v5 = &v2->m_KeyValuePairs.m_Memory.m_pMemory[v3->m_nFirstKVPairIndex];
      v6 = 0;
      pEntity = v3;
      pEntityPairs = v5;
      if ( m_nNumKVPairs <= 0 )
        goto LABEL_11;
      iIndex = (int)v5;
      while ( _V_stricmp(s1: *(const char **)iIndex, s2: "classname") != 0 )
      {
        iIndex += 12;
        if ( ++v6 >= m_nNumKVPairs )
          goto LABEL_11;
      }
      v7 = &pEntityPairs[v6];
      if ( v7 == nullptr || (m_pValue = v7->m_pValue) == nullptr )
LABEL_11:
        m_pValue = szDescription;
      v9 = GameData::BeginInstanceRemap(
             this: pGD,
             pszClassName: m_pValue,
             pszInstancePrefix: NameFixup,
             Origin: &InstanceOrigin,
             Angle: &InstanceAngle);
      pEntClass = v9;
      if ( v9 != nullptr )
      {
        v10 = v9->m_nVariables <= 0;
        iIndex = 0;
        if ( !v10 )
          break;
      }
LABEL_32:
      v25 += 28;
      if ( ++i >= v28->m_Entities.m_Size )
        return;
      v2 = v28;
    }
    while ( 1 )
    {
      VariableAt = GDclass::GetVariableAt(this: v9, iIndex);
      v12 = v3->m_nNumKVPairs;
      v13 = 0;
      pEntityGDVariable = VariableAt;
      if ( v12 <= 0 )
      {
LABEL_21:
        NewKeyValuePair = nullptr;
      }
      else
      {
        v14 = pEntityPairs;
        while ( _V_stricmp(s1: v14->m_pKey, s2: pEntityGDVariable->m_szName) != 0 )
        {
          ++v13;
          ++v14;
          if ( v13 >= v12 )
          {
            v3 = pEntity;
            goto LABEL_21;
          }
        }
        NewKeyValuePair = &pEntityPairs[v13];
        if ( NewKeyValuePair != nullptr )
        {
          v16 = NewKeyValuePair->m_pValue;
          if ( v16 != nullptr )
          {
            v3 = pEntity;
            goto LABEL_27;
          }
        }
        v3 = pEntity;
      }
      v16 = szDescription;
LABEL_27:
      m_szName = pEntityGDVariable->m_szName;
      if ( GameData::RemapKeyValue(
             this: pGD,
             pszKey: pEntityGDVariable->m_szName,
             pszInValue: v16,
             pszOutValue: remappedValue,
             NameFixup: NAME_FIXUP_NONE) )
      {
        if ( NewKeyValuePair == nullptr )
        {
          NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: v28);
          NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &v28->m_KeyValueStringPool, pszValue: m_szName);
          ++v3->m_nNumKVPairs;
        }
        NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &v28->m_KeyValueStringPool, pszValue: remappedValue);
      }
      if ( ++iIndex >= pEntClass->m_nVariables )
        goto LABEL_32;
      v9 = pEntClass;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064640
// Name: private: void CSimpleMapFile::MergeBrushes(int,class CSimpleMapFile const __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeBrushes(
        CSimpleMapFile *this,
        int nEntityIndex,
        const CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        const matrix3x4_t *transform)
{
  CSimpleMapFile *v7; // ebx
  MapBrush_t *NewBrush; // eax
  int v9; // ebx
  int i; // [esp+Ch] [ebp-4h]
  const CSimpleMapFile *pInstanceMapa; // [esp+1Ch] [ebp+Ch]

  v7 = this;
  i = 0;
  if ( pInstanceMap->m_Brushes.m_Size > 0 )
  {
    pInstanceMapa = nullptr;
    while ( 1 )
    {
      NewBrush = CSimpleMapFile::AllocateNewBrush(this: v7);
      *NewBrush = *(MapBrush_t *)((char *)&pInstanceMapa->m_pFileSystem
                                + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory);
      NewBrush->m_nFirstSideIndex += v7->m_BrushSides.m_Size;
      v9 = i;
      if ( i < pInstanceMap->m_Entities.m_Memory.m_pMemory->m_nNumBrushes
        || (NewBrush->m_ContentsFlags & 0x20000000) != 0 )
      {
        TransformAABB(
          transform,
          vecMinsIn: (const Vector *)((char *)&pInstanceMapa->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >
                         + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory),
          vecMaxsIn: (const Vector *)((char *)&pInstanceMapa->m_PlaneHash.m_Planes.m_Size
                         + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory),
          vecMinsOut: &NewBrush->m_vMinBounds,
          vecMaxsOut: &NewBrush->m_vMaxBounds);
      }
      pInstanceMapa = (const CSimpleMapFile *)((char *)pInstanceMapa + 36);
      ++i;
      if ( v9 + 1 >= pInstanceMap->m_Brushes.m_Size )
        break;
      v7 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064720
// Name: private: void CSimpleMapFile::MergeEntities(int,class CSimpleMapFile const __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeEntities(
        CSimpleMapFile *this,
        MapEntityKeyValuePair_t *nEntityIndex,
        const CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        const matrix3x4_t *transform,
        GameData *pGameData)
{
  CSimpleMapFile *v7; // edi
  MapEntity_t *v8; // eax
  int v9; // esi
  int m_nNumKVPairs; // ebx
  GDclass *v11; // edx
  MapEntityKeyValuePair_t *v12; // eax
  int v13; // esi
  MapEntityKeyValuePair_t *v14; // eax
  char *m_pValue; // eax
  MapEntity_t *m_pMemory; // edx
  int v17; // ebx
  char *v18; // eax
  int v19; // esi
  char *v20; // eax
  const char *v21; // eax
  int v22; // eax
  int v23; // esi
  const char **p_m_pKey; // ebx
  MapEntityKeyValuePair_t *v25; // eax
  const char *v26; // eax
  bool v27; // cc
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapEntity_t *v30; // ecx
  int v31; // eax
  char *v32; // esi
  int v33; // eax
  int v34; // ebx
  MapEntity_t *v35; // eax
  double v36; // st7
  float *v37; // eax
  GDclass *v38; // edx
  MapEntityKeyValuePair_t *NewKeyValuePair; // esi
  int v40; // esi
  char *v41; // eax
  float v42; // eax
  int v43; // esi
  int v44; // edx
  int v45; // esi
  int v46; // esi
  _BYTE *v47; // eax
  int v48; // eax
  float z; // ecx
  __int64 v50; // xmm0_8
  GDclass *v51; // eax
  int v52; // esi
  char *v53; // esi
  const char *v54; // eax
  GDclass *p_m_pValue; // eax
  _BYTE *v56; // eax
  _BYTE *v57; // esi
  unsigned int v58; // kr00_4
  char *v59; // eax
  char v60; // dl
  int v61; // eax
  char v62; // cl
  int v63; // eax
  int v64; // eax
  int v65; // esi
  char *v66; // esi
  const char *v67; // eax
  int v68; // eax
  char v69; // cl
  char *v70; // eax
  char *v71; // esi
  char v72; // cl
  const char *v73; // edx
  unsigned int v74; // eax
  char *v75; // edi
  char v76; // cl
  int v77; // eax
  char v78; // cl
  char *v79; // eax
  GameData::TNameFixup v80; // [esp-4h] [ebp-1140h]
  char dest[1024]; // [esp+Ch] [ebp-1130h] BYREF
  char pszOutValue[1024]; // [esp+40Ch] [ebp-D30h] BYREF
  char pszInValue[1023]; // [esp+80Ch] [ebp-930h] BYREF
  char v84; // [esp+C0Bh] [ebp-531h] BYREF
  char v85[1024]; // [esp+C0Ch] [ebp-530h] BYREF
  char pszValue[100]; // [esp+100Ch] [ebp-130h] BYREF
  char pDest[128]; // [esp+1070h] [ebp-CCh] BYREF
  QAngle Angle; // [esp+10F0h] [ebp-4Ch] BYREF
  CSimpleMapFile *v89; // [esp+10FCh] [ebp-40h]
  int nEntityIndexa; // [esp+1100h] [ebp-3Ch]
  int v91; // [esp+1104h] [ebp-38h]
  Vector in1; // [esp+1108h] [ebp-34h] BYREF
  int v93; // [esp+1114h] [ebp-28h]
  GameData::TNameFixup NameFixup; // [esp+1118h] [ebp-24h]
  int nNumPairs; // [esp+111Ch] [ebp-20h]
  int v96; // [esp+1120h] [ebp-1Ch]
  int v97; // [esp+1124h] [ebp-18h]
  char *pszClassName; // [esp+1128h] [ebp-14h]
  char *pSrc; // [esp+112Ch] [ebp-10h]
  const char *VariableAt; // [esp+1130h] [ebp-Ch]
  int iIndex; // [esp+1134h] [ebp-8h]
  GDclass *v102; // [esp+1138h] [ebp-4h]
  MapEntityKeyValuePair_t *pInstancePairs; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsa; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsb; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsc; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsd; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairse; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsf; // [esp+1144h] [ebp+8h]
  char pInstancePairs_3; // [esp+1147h] [ebp+Bh]

  v7 = this;
  v91 = 28 * (_DWORD)nEntityIndex;
  v8 = &this->m_Entities.m_Memory.m_pMemory[(_DWORD)nEntityIndex];
  v9 = 0;
  m_nNumKVPairs = v8->m_nNumKVPairs;
  v11 = (GDclass *)&this->m_KeyValuePairs.m_Memory.m_pMemory[v8->m_nFirstKVPairIndex];
  v89 = this;
  pInstancePairs = (MapEntityKeyValuePair_t *)v11;
  nNumPairs = m_nNumKVPairs;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_8;
  v102 = v11;
  while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "targetname") != 0 )
  {
    v102 = (GDclass *)((char *)v102 + 12);
    if ( ++v9 >= m_nNumKVPairs )
      goto LABEL_8;
  }
  v12 = &pInstancePairs[v9];
  if ( v12 == nullptr || (pSrc = (char *)v12->m_pValue) == nullptr )
LABEL_8:
    pSrc = (char *)szDescription;
  v13 = 0;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_16;
  v102 = (GDclass *)pInstancePairs;
  while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "name") != 0 )
  {
    v102 = (GDclass *)((char *)v102 + 12);
    if ( ++v13 >= m_nNumKVPairs )
      goto LABEL_16;
  }
  v14 = &pInstancePairs[v13];
  if ( v14 == nullptr || (m_pValue = (char *)v14->m_pValue) == nullptr )
LABEL_16:
    m_pValue = (char *)szDescription;
  if ( *pSrc != 0 )
  {
    V_strncpy(pDest, pSrc, maxLen: 128);
  }
  else if ( *m_pValue != 0 )
  {
    V_strncpy(pDest, pSrc: m_pValue, maxLen: 128);
  }
  else
  {
    V_snprintf(pDest, maxLen: 0x80u, pFormat: "InstanceAuto%d", v7->m_nInstanceCount);
  }
  v93 = 0;
  v97 = 0;
  if ( v7->m_Entities.m_Size > 0 )
  {
    iIndex = 0;
    do
    {
      m_pMemory = v7->m_Entities.m_Memory.m_pMemory;
      v17 = *(int *)((char *)&m_pMemory->m_nNumKVPairs + iIndex);
      v18 = (char *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(int *)((char *)&m_pMemory->m_nFirstKVPairIndex + iIndex)];
      v19 = 0;
      pSrc = v18;
      if ( v17 > 0 )
      {
        v102 = (GDclass *)v18;
        while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "hammerid") != 0 )
        {
          v102 = (GDclass *)((char *)v102 + 12);
          if ( ++v19 >= v17 )
            goto LABEL_34;
        }
        v20 = &pSrc[12 * v19];
        if ( v20 != nullptr )
        {
          v21 = *((const char **)v20 + 1);
          if ( v21 != nullptr && *v21 != 0 )
          {
            v22 = atoi(nptr: v21);
            if ( v22 > v93 )
              v93 = v22;
          }
        }
      }
LABEL_34:
      iIndex += 28;
      ++v97;
    }
    while ( v97 < v7->m_Entities.m_Size );
  }
  v23 = 0;
  if ( nNumPairs <= 0 )
    goto LABEL_42;
  p_m_pKey = &pInstancePairs->m_pKey;
  while ( _V_stricmp(s1: *p_m_pKey, s2: "fixup_style") != 0 )
  {
    ++v23;
    p_m_pKey += 3;
    if ( v23 >= nNumPairs )
      goto LABEL_42;
  }
  v25 = &pInstancePairs[v23];
  if ( v25 == nullptr || (v26 = v25->m_pValue) == nullptr )
LABEL_42:
    v26 = szDescription;
  NameFixup = atoi(nptr: v26);
  v27 = pInstanceMap->m_Entities.m_Size <= 0;
  nEntityIndexa = v7->m_Entities.m_Size;
  v97 = 0;
  if ( !v27 )
  {
    pSrc = nullptr;
    while ( 1 )
    {
      m_Size = v7->m_Entities.m_Size;
      m_nAllocationCount = v7->m_Entities.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<vgui::CSizerBase::CSizerMember,int>::Grow(
          this: (CUtlMemory<vgui::CSizerBase::CSizerMember,int> *)&v7->m_Entities,
          num: m_Size - m_nAllocationCount + 1);
      ++v7->m_Entities.m_Size;
      v30 = v7->m_Entities.m_Memory.m_pMemory;
      v31 = v7->m_Entities.m_Size - m_Size - 1;
      v7->m_Entities.m_pElements = v30;
      if ( v31 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v30[m_Size + 1], src: (unsigned __int8 *)&v30[m_Size], count: 28 * v31);
      v32 = pSrc;
      v33 = (int)&v7->m_Entities.m_Memory.m_pMemory[v7->m_Entities.m_Size - 1];
      *(_QWORD *)v33 = 0;
      *(_QWORD *)(v33 + 8) = 0;
      *(_QWORD *)(v33 + 16) = 0;
      *(_DWORD *)(v33 + 24) = 0;
      v34 = (int)&v7->m_Entities.m_Memory.m_pMemory[v7->m_Entities.m_Size - 1];
      v35 = pInstanceMap->m_Entities.m_Memory.m_pMemory;
      v36 = *(float *)&v32[(_DWORD)v35];
      v37 = (float *)((int)&v35->m_vOrigin.x + (_DWORD)v32);
      *(float *)v34 = v36;
      iIndex = 0;
      *(float *)(v34 + 4) = v37[1];
      *(float *)(v34 + 8) = v37[2];
      *(float *)(v34 + 12) = v37[3];
      *(float *)(v34 + 16) = v37[4];
      *(float *)(v34 + 20) = v37[5];
      *(float *)(v34 + 24) = v37[6];
      *(_DWORD *)(v34 + 12) += v7->m_Brushes.m_Size - pInstanceMap->m_Brushes.m_Size;
      v27 = *(_DWORD *)(v34 + 24) <= 0;
      *(_DWORD *)(v34 + 20) = v7->m_KeyValuePairs.m_Size;
      v38 = (GDclass *)&pInstanceMap->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)&v32[(unsigned int)pInstanceMap->m_Entities.m_Memory.m_pMemory
                                                                                       + 20]];
      v102 = v38;
      if ( !v27 )
      {
        pInstancePairsa = (MapEntityKeyValuePair_t *)v38;
        do
        {
          NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: v7);
          NewKeyValuePair->m_pKey = CStringPool::Allocate(
                                      this: &v7->m_KeyValueStringPool,
                                      pszValue: pInstancePairsa->m_pKey);
          NewKeyValuePair->m_pValue = nullptr;
          NewKeyValuePair->m_bIsConnection = pInstancePairsa->m_bIsConnection;
          ++iIndex;
          ++pInstancePairsa;
        }
        while ( iIndex < *(_DWORD *)(v34 + 24) );
      }
      v40 = 0;
      VariableAt = *(const char **)(v34 + 24);
      if ( (int)VariableAt <= 0 )
        goto LABEL_59;
      pInstancePairsb = (MapEntityKeyValuePair_t *)v102;
      while ( _V_stricmp(s1: pInstancePairsb->m_pKey, s2: "classname") != 0 )
      {
        ++pInstancePairsb;
        if ( ++v40 >= (int)VariableAt )
          goto LABEL_59;
      }
      v41 = (char *)v102 + 12 * v40;
      if ( v41 == nullptr || (pszClassName = *((char **)v41 + 1)) == nullptr )
LABEL_59:
        pszClassName = (char *)szDescription;
      if ( v97 != 0 )
      {
        v42 = *(float *)(v34 + 8);
        *(_QWORD *)&in1.x = *(_QWORD *)v34;
        in1.z = v42;
        VectorTransform(in1: &in1.x, in2: transform, out: (float *)v34);
        v43 = 0;
        pInstancePairsc = &v7->m_KeyValuePairs.m_Memory.m_pMemory[v7->m_Entities.m_Memory.m_pMemory[v91 / 0x1Cu].m_nFirstKVPairIndex];
        if ( *(int *)(v34 + 24) > 0 )
        {
          iIndex = (int)&v102->m_rgbColor;
          do
          {
            CSimpleMapFile::FixupInstanceKeyValuePair(
              this: v7,
              pNewKeyValuePair: &v7->m_KeyValuePairs.m_Memory.m_pMemory[v43 + *(_DWORD *)(v34 + 20)],
              pOriginalValue: *(char **)iIndex,
              pInstancePairs: pInstancePairsc,
              nNumPairs);
            iIndex += 12;
            ++v43;
          }
          while ( v43 < *(_DWORD *)(v34 + 24) );
        }
        v44 = (int)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)];
        v45 = 0;
        VariableAt = *(const char **)(v34 + 24);
        iIndex = v44;
        if ( (int)VariableAt > 0 )
        {
          pInstancePairsd = (MapEntityKeyValuePair_t *)v44;
          while ( _V_stricmp(s1: pInstancePairsd->m_pKey, s2: "hammerid") != 0 )
          {
            ++pInstancePairsd;
            if ( ++v45 >= (int)VariableAt )
              goto LABEL_73;
          }
          v46 = iIndex + 12 * v45;
          if ( v46 != 0 )
          {
            v47 = *(_BYTE **)(v46 + 4);
            if ( v47 != nullptr && *v47 != 0 )
            {
              v48 = atoi(nptr: *(const char **)(v46 + 4));
              V_snprintf(pDest: pszValue, maxLen: 0x64u, pFormat: "%d", v93 + v48);
              *(_DWORD *)(v46 + 4) = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue);
            }
          }
        }
LABEL_73:
        in1.x = vOrigin->x;
        in1.y = vOrigin->y;
        z = orientation->z;
        in1.z = vOrigin->z;
        v50 = *(_QWORD *)&orientation->x;
        Angle.z = z;
        *(_QWORD *)&Angle.x = v50;
        v51 = GameData::BeginInstanceRemap(
                this: pGameData,
                pszClassName,
                pszInstancePrefix: pDest,
                Origin: &in1,
                &Angle);
        v102 = v51;
        if ( v51 != nullptr )
        {
          v27 = v51->m_nVariables <= 0;
          iIndex = 0;
          if ( !v27 )
          {
            do
            {
              pszClassName = (char *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)];
              VariableAt = (const char *)GDclass::GetVariableAt(this: v102, iIndex);
              v52 = 0;
              v96 = *(_DWORD *)(v34 + 24);
              if ( v96 <= 0 )
              {
LABEL_79:
                v53 = nullptr;
              }
              else
              {
                pInstancePairse = (MapEntityKeyValuePair_t *)pszClassName;
                while ( _V_stricmp(s1: pInstancePairse->m_pKey, s2: VariableAt + 20) != 0 )
                {
                  ++pInstancePairse;
                  if ( ++v52 >= v96 )
                    goto LABEL_79;
                }
                v53 = &pszClassName[12 * v52];
                if ( v53 != nullptr )
                {
                  v54 = *((const char **)v53 + 1);
                  if ( v54 != nullptr )
                    goto LABEL_83;
                }
              }
              v54 = szDescription;
LABEL_83:
              pInstancePairsf = (MapEntityKeyValuePair_t *)(VariableAt + 20);
              if ( GameData::RemapKeyValue(
                     this: pGameData,
                     pszKey: VariableAt + 20,
                     pszInValue: v54,
                     pszOutValue,
                     NameFixup) )
              {
                if ( v53 == nullptr )
                {
                  v53 = (char *)CSimpleMapFile::AllocateNewKeyValuePair(this: v7);
                  *(_DWORD *)v53 = CStringPool::Allocate(
                                     this: &v7->m_KeyValueStringPool,
                                     pszValue: (const char *)pInstancePairsf);
                  ++*(_DWORD *)(v34 + 24);
                }
                *((_DWORD *)v53 + 1) = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue: pszOutValue);
              }
              ++iIndex;
            }
            while ( iIndex < v102->m_nVariables );
          }
        }
        v27 = *(_DWORD *)(v34 + 24) <= 0;
        p_m_pValue = (GDclass *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)].m_pValue;
        pszClassName = nullptr;
        if ( !v27 )
          break;
      }
LABEL_116:
      pSrc += 28;
      if ( ++v97 >= pInstanceMap->m_Entities.m_Size )
        goto LABEL_117;
    }
    v102 = p_m_pValue;
    while ( 1 )
    {
      if ( p_m_pValue->m_rgbColor.r != 0 )
      {
        pInstancePairs_3 = 0;
        V_strncpy(pDest: pszInValue, pSrc: (char *)p_m_pValue->Parent, maxLen: 1024);
        strchr(string: pszInValue, chr: 0x1Bu);
        v57 = v56;
        if ( v56 != nullptr )
          *v56 = 0;
        if ( GameData::RemapNameField(this: pGameData, pszInValue, pszOutValue: v85, NameFixup) )
        {
          if ( v57 != nullptr )
          {
            v58 = strlen(v85);
            v85[v58] = 27;
            v59 = v57 + 1;
            do
            {
              v60 = *v59;
              v85[v58 - (_DWORD)(v57 + 1) + 1 + (_DWORD)v59] = *v59;
              ++v59;
            }
            while ( v60 != 0 );
          }
          pInstancePairs_3 = 1;
          v61 = 0;
          do
          {
            v62 = v85[v61];
            pszInValue[v61++] = v62;
          }
          while ( v62 != 0 );
        }
        strchr(string: pszInValue, chr: 0x1Bu);
        iIndex = v63;
        if ( v63 != 0 )
        {
          iIndex = v63 + 1;
          strchr(string: (char *)(v63 + 1), chr: 0x1Bu);
          v65 = v64;
          if ( v64 != 0 && V_strncasecmp(s1: (const char *)iIndex, s2: "setparent", n: v64 - iIndex) == 0 )
          {
            v66 = (char *)(v65 + 1);
            strchr(string: v66, chr: 0x1Bu);
            VariableAt = v67;
            if ( v67 != nullptr )
            {
              v96 = v67 - v66;
              strncpy((unsigned __int8 *)dest, source: (unsigned __int8 *)v66, count: v67 - v66);
              v80 = NameFixup;
              dest[v96] = 0;
              if ( GameData::RemapNameField(this: pGameData, pszInValue: dest, pszOutValue, NameFixup: v80) )
              {
                v68 = 0;
                do
                {
                  v69 = pszInValue[v68];
                  v85[v68++] = v69;
                }
                while ( v69 != 0 );
                v70 = pszOutValue;
                v71 = &v85[v66 - pszOutValue - (_DWORD)pszInValue];
                do
                {
                  v72 = *v70;
                  v70[(_DWORD)v71] = *v70;
                  ++v70;
                }
                while ( v72 != 0 );
                v73 = VariableAt;
                v74 = strlen(VariableAt) + 1;
                v75 = &v84;
                do
                  v76 = *++v75;
                while ( v76 != 0 );
                qmemcpy(v75, VariableAt, 4 * (v74 >> 2));
                qmemcpy(&v75[4 * (v74 >> 2)], &v73[4 * (v74 >> 2)], v74 & 3);
                v77 = 0;
                do
                {
                  v78 = v85[v77];
                  pszInValue[v77++] = v78;
                }
                while ( v78 != 0 );
                v7 = v89;
LABEL_114:
                v79 = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue: v85);
                v102->Parent = (GameData *)v79;
                goto LABEL_115;
              }
            }
          }
        }
        if ( pInstancePairs_3 == 1 )
          goto LABEL_114;
      }
LABEL_115:
      p_m_pValue = (GDclass *)&v102->m_bKeyFrame;
      ++pszClassName;
      v102 = (GDclass *)((char *)v102 + 12);
      if ( (int)pszClassName >= *(_DWORD *)(v34 + 24) )
        goto LABEL_116;
    }
  }
LABEL_117:
  CSimpleMapFile::MoveEntityBrushesToWorld(this: v7, nEntityIndex: nEntityIndexa);
}

//------------------------------------------------------------------------------
// Address: 0x10065030
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::EntityKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::EntityKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  unsigned int v3; // eax
  int v5; // eax
  MapEntityKeyValuePair_t *NewKeyValuePair; // ebx

  if ( _V_stricmp(s1: pKey, s2: "classname") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "origin") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "id") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "mapversion") == 0 )
          (*pData)->m_nMapRevision = atoi(nptr: pValue);
      }
      else
      {
        pKey = "hammerid";
        v5 = atoi(nptr: pValue);
        if ( v5 > (*pData)->m_nHighestID )
          (*pData)->m_nHighestID = v5;
      }
    }
    else if ( sscanf(string: pValue, format: "%f %f %f", pData[1], &pData[1]->m_pFilename, &pData[1]->m_PlaneHash) != 3 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Entity origin malformed.");
      return 1;
    }
  }
  else
  {
    if ( _V_stricmp(s1: pValue, s2: "func_detail") != 0 )
    {
      if ( _V_stricmp(s1: pValue, s2: "func_instance_parms") != 0 )
      {
        if ( _V_stricmp(s1: pValue, s2: "func_viscluster") != 0
          && _V_stricmp(s1: pValue, s2: "func_ladder") != 0
          && _V_stricmp(s1: pValue, s2: "func_simpleladder") != 0
          && _V_stricmp(s1: pValue, s2: "func_envcubemap") != 0
          && _V_stricmp(s1: pValue, s2: "test_sidelist") != 0
          && _V_stricmp(s1: pValue, s2: "info_overlay") != 0
          && _V_stricmp(s1: pValue, s2: "info_overlay_transition") != 0
          && _V_stricmp(s1: pValue, s2: "info_no_dynamic_shadow") != 0 )
        {
          v3 = _V_strlen(str: "func_areaportal");
          if ( V_strnicmp(s1: pValue, s2: "func_areaportal", n: v3) != 0 )
            goto LABEL_25;
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Entity type not supported: %s.\n");
      }
      return 9;
    }
    pData[2] = (CSimpleMapFile *)0x8000000;
  }
LABEL_25:
  NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: *pData);
  NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pKey);
  NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pValue);
  ++pData[1]->m_PlaneHash.m_Planes.m_Size;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10065260
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::ConnectionsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::ConnectionsKeyHandler(
        const char *pKey,
        const char *pValue,
        CSimpleMapFile **pData)
{
  MapEntityKeyValuePair_t *NewKeyValuePair; // edi

  NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: *pData);
  NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pKey);
  NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pValue);
  NewKeyValuePair->m_bIsConnection = true;
  ++pData[1]->m_PlaneHash.m_Planes.m_Size;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x100652B0
// Name: private: struct CSimpleMapFile::MaterialInfo_t __near * CSimpleMapFile::FindMaterialInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleMapFile::MaterialInfo_t *__thiscall CSimpleMapFile::FindMaterialInfo(CSimpleMapFile *this, const char *pName)
{
  int v3; // ebx
  int v4; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CSimpleMapFile::MaterialInfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // ebx
  const char *v10; // edx
  CSimpleMapFile::MaterialInfo_t *v11; // eax
  char v12; // cl
  void *Material; // eax
  void *v14; // esi
  const char *MaterialVar; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  int v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  bool v34; // zf
  __int16 *p_m_SurfaceFlags; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  BOOL IsTrue; // eax
  const char *v43; // eax
  const char *v44; // eax
  const char *MaterialShaderName; // eax
  const char *v46; // esi
  const char *v47; // eax
  int MaterialShaderPropertyInt; // eax
  CSimpleMapFile::MaterialInfo_t *v49; // ecx
  int *p_m_ContentsFlags; // ecx
  __int16 *v51; // eax
  void *matID; // [esp+Ch] [ebp-8h]
  bool found; // [esp+12h] [ebp-2h] BYREF
  bool bKeepLighting; // [esp+13h] [ebp-1h]
  const char *checkWindow; // [esp+1Ch] [ebp+8h]
  const char *checkWindowa; // [esp+1Ch] [ebp+8h]
  const char *checkWindowb; // [esp+1Ch] [ebp+8h]
  const char *checkWindowc; // [esp+1Ch] [ebp+8h]
  const char *checkWindowd; // [esp+1Ch] [ebp+8h]
  const char *checkWindowe; // [esp+1Ch] [ebp+8h]
  char checkWindow_3; // [esp+1Fh] [ebp+Bh]

  v3 = 0;
  if ( this->m_MaterialInfos.m_Size > 0 )
  {
    v4 = 0;
    while ( _V_stricmp(s1: pName, s2: this->m_MaterialInfos.m_Memory.m_pMemory[v4].m_Name) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->m_MaterialInfos.m_Size )
        goto LABEL_5;
    }
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v3];
  }
LABEL_5:
  m_Size = this->m_MaterialInfos.m_Size;
  m_nAllocationCount = this->m_MaterialInfos.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSimpleMapFile::MaterialInfo_t,int>::Grow(
      this: &this->m_MaterialInfos.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_MaterialInfos.m_Size;
  m_pMemory = this->m_MaterialInfos.m_Memory.m_pMemory;
  v8 = this->m_MaterialInfos.m_Size - m_Size - 1;
  this->m_MaterialInfos.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 136 * v8);
  v9 = v3;
  v10 = pName;
  v11 = &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  do
  {
    v12 = *v10;
    v11->m_Name[0] = *v10++;
    v11 = (CSimpleMapFile::MaterialInfo_t *)((char *)v11 + 1);
  }
  while ( v12 != 0 );
  this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags = 0;
  this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 0;
  Material = FindMaterial(materialName: pName, pFound: &found, bComplain: true);
  v14 = Material;
  matID = Material;
  if ( Material == nullptr || !found )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Material not found!: %s\n");
    return nullptr;
  }
  MaterialVar = GetMaterialVar(materialHandle: Material, propertyName: "%compileSky");
  checkWindow = MaterialVar;
  if ( MaterialVar != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: MaterialVar, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindow, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x404u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v17 = GetMaterialVar(materialHandle: v14, propertyName: "%compile2DSky");
  checkWindowa = v17;
  if ( v17 != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: v17, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindowa, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x406u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v18 = GetMaterialVar(materialHandle: v14, propertyName: "%compileHint");
  checkWindowb = v18;
  if ( v18 != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: v18, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindowb, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x580u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v19 = GetMaterialVar(materialHandle: v14, propertyName: "%compileSkip");
  checkWindowc = v19;
  if ( v19 != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: v19, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindowc, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x680u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v20 = GetMaterialVar(materialHandle: v14, propertyName: "%compileOrigin");
  checkWindowd = v20;
  if ( v20 != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: v20, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindowd, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x9000000u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v21 = GetMaterialVar(materialHandle: v14, propertyName: "%compileClip");
  checkWindowe = v21;
  if ( v21 != nullptr
    && (CRoomTemplateListPanel::CompareFolders(s1: v21, s2: "true") == 0
     || CRoomTemplateListPanel::CompareFolders(s1: checkWindowe, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x30000u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v22 = GetMaterialVar(materialHandle: v14, propertyName: "%playerClip");
  if ( v22 != nullptr )
  {
    if ( StringIsTrue(str: v22) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x10000u;
LABEL_45:
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v23 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNpcClip");
  if ( v23 != nullptr )
  {
    if ( StringIsTrue(str: v23) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20000u;
      goto LABEL_45;
    }
    v14 = matID;
  }
  v24 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoChop");
  if ( v24 != nullptr )
  {
    if ( StringIsTrue(str: v24) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x4000u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v25 = GetMaterialVar(materialHandle: v14, propertyName: "%compileTrigger");
  if ( v25 != nullptr )
  {
    if ( StringIsTrue(str: v25) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x440u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v26 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoLight");
  if ( v26 != nullptr )
  {
    if ( StringIsTrue(str: v26) )
    {
      v27 = GetMaterialVar(materialHandle: matID, propertyName: "%compileWater");
      if ( v27 == nullptr || !StringIsTrue(str: v27) )
      {
        this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x400u;
        return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
      }
    }
    v14 = matID;
  }
  v28 = GetMaterialVar(materialHandle: v14, propertyName: "%compileLadder");
  if ( v28 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v28) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20000000u;
  }
  v29 = GetMaterialVar(materialHandle: v14, propertyName: "%compileTeam");
  if ( v29 != nullptr )
  {
    v30 = atoi(nptr: v29);
    if ( v30 == 1 )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x800u;
    }
    else if ( v30 == 2 )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x1000u;
    }
  }
  v31 = GetMaterialVar(materialHandle: v14, propertyName: "%noPortal");
  if ( v31 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v31) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x20u;
  }
  v32 = GetMaterialVar(materialHandle: v14, propertyName: "%hotSurface");
  if ( v32 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v32) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x20u;
  }
  v33 = GetMaterialVar(materialHandle: v14, propertyName: "%compilePassBullets");
  if ( v33 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v33) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 8u;
    }
  }
  if ( GetMaterialShaderPropertyBool(materialHandle: v14, propID: 0) != 0 )
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x800u;
  v34 = GetMaterialShaderPropertyBool(materialHandle: v14, propID: 1) == 0;
  p_m_SurfaceFlags = &this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags;
  if ( v34 )
    *p_m_SurfaceFlags |= 0x400u;
  else
    *p_m_SurfaceFlags &= ~0x400u;
  v36 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoDraw");
  if ( v36 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v36) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
  }
  v37 = GetMaterialVar(materialHandle: v14, propertyName: "%compileInvisible");
  if ( v37 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v37) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 8u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    }
  }
  checkWindow_3 = 1;
  v38 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNonsolid");
  if ( v38 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v38) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 128;
      checkWindow_3 = 0;
    }
  }
  v39 = GetMaterialVar(materialHandle: v14, propertyName: "%compileBlockLOS");
  if ( v39 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v39) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 64;
      checkWindow_3 = 0;
    }
  }
  v40 = GetMaterialVar(materialHandle: v14, propertyName: "%compileDetail");
  if ( v40 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v40) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x8000000u;
  }
  v41 = GetMaterialVar(materialHandle: v14, propertyName: "%compileKeepLight");
  if ( v41 == nullptr || (IsTrue = StringIsTrue(str: v41), bKeepLighting = true, !IsTrue) )
    bKeepLighting = false;
  v43 = GetMaterialVar(materialHandle: matID, propertyName: "%compileWater");
  if ( v43 != nullptr && StringIsTrue(str: v43) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= 0xF7FFFFFE;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x3008u;
  }
  v44 = GetMaterialVar(materialHandle: matID, propertyName: "%compileNoShadows");
  if ( v44 != nullptr && StringIsTrue(str: v44) )
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x1000u;
  MaterialShaderName = GetMaterialShaderName(materialHandle: matID);
  v46 = MaterialShaderName;
  if ( !bKeepLighting && V_strncasecmp(s1: MaterialShaderName, s2: "water", n: 5) == 0
    || V_strncasecmp(s1: v46, s2: "UnlitGeneric", n: 12) == 0 )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x400u;
  }
  v47 = GetMaterialVar(materialHandle: matID, propertyName: "%compileSlime");
  if ( v47 != nullptr && StringIsTrue(str: v47) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= 0xF7FFFFFE;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x10u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x2000u;
  }
  MaterialShaderPropertyInt = GetMaterialShaderPropertyInt(materialHandle: matID, propID: 2);
  if ( checkWindow_3 != 0 && MaterialShaderPropertyInt != 1 )
  {
    v49 = this->m_MaterialInfos.m_Memory.m_pMemory;
    v34 = (v49[v9].m_ContentsFlags & 0x28) == 0;
    p_m_ContentsFlags = &v49[v9].m_ContentsFlags;
    if ( v34 )
      *p_m_ContentsFlags |= 2u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
    if ( MaterialShaderPropertyInt == 2 )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x10u;
  }
  v51 = &this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags;
  if ( (*v51 & 0x400) != 0 )
    *v51 &= ~0x800u;
  return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
}

//------------------------------------------------------------------------------
// Address: 0x10065DB0
// Name: public: void CSimpleMapFile::AddFuncInstance(char const __near *,class QAngle,class Vector,struct MapEntityKeyValuePair_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSimpleMapFile::AddFuncInstance(
        CSimpleMapFile *this,
        const char *pFilename,
        QAngle angles,
        Vector vOrigin,
        MapEntityKeyValuePair_t *pExtraKeyValues,
        int nExtraKeyValues)
{
  MapEntity_t *NewEntity; // esi
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char *v19; // eax
  int v20; // [esp-34h] [ebp-1B8h]
  char pDest[8]; // [esp+0h] [ebp-184h] BYREF
  char originString[128]; // [esp+24h] [ebp-160h] BYREF
  char anglesString[128]; // [esp+A4h] [ebp-E0h] BYREF
  MapEntityKeyValuePair_t *idString_92; // [esp+180h] [ebp-4h] OVERLAPPED

  V_snprintf(pDest: &originString[92], maxLen: 0x80u, pFormat: "%f %f %f", angles.x, angles.y, angles.z);
  V_snprintf(pDest, maxLen: 0x80u, pFormat: "%f %f %f", vOrigin.x, vOrigin.y, vOrigin.z);
  v20 = this->m_nHighestID + 1;
  this->m_nHighestID = v20;
  V_snprintf(pDest: &anglesString[92], maxLen: 0x80u, pFormat: "%d", v20);
  NewEntity = CSimpleMapFile::AllocateNewEntity(this);
  NewEntity->m_nFirstBrushIndex = 0;
  NewEntity->m_nNumBrushes = 0;
  NewEntity->m_nFirstKVPairIndex = this->m_KeyValuePairs.m_Size;
  NewEntity->m_nNumKVPairs = 0;
  NewEntity->m_vOrigin = vOrigin;
  idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
  v8 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "hammerid");
  idString_92->m_pKey = v8;
  v9 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: &anglesString[92]);
  idString_92->m_pValue = v9;
  ++NewEntity->m_nNumKVPairs;
  idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
  v10 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "classname");
  idString_92->m_pKey = v10;
  v11 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "func_instance");
  idString_92->m_pValue = v11;
  ++NewEntity->m_nNumKVPairs;
  idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
  v12 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "angles");
  idString_92->m_pKey = v12;
  v13 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: &originString[92]);
  idString_92->m_pValue = v13;
  ++NewEntity->m_nNumKVPairs;
  idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
  v14 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "file");
  idString_92->m_pKey = v14;
  v15 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: pFilename);
  idString_92->m_pValue = v15;
  ++NewEntity->m_nNumKVPairs;
  idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
  v16 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: "origin");
  idString_92->m_pKey = v16;
  v17 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: pDest);
  idString_92->m_pValue = v17;
  ++NewEntity->m_nNumKVPairs;
  if ( nExtraKeyValues > 0 )
  {
    do
    {
      idString_92 = CSimpleMapFile::AllocateNewKeyValuePair(this);
      v18 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: pExtraKeyValues->m_pKey);
      idString_92->m_pKey = v18;
      v19 = CStringPool::Allocate(this: &this->m_KeyValueStringPool, pszValue: pExtraKeyValues->m_pValue);
      ++pExtraKeyValues;
      idString_92->m_pValue = v19;
      ++NewEntity->m_nNumKVPairs;
      --nExtraKeyValues;
    }
    while ( nExtraKeyValues != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066030
// Name: private: int CSimpleMapFile::GetTextureInfoForBrushTexture(struct MapBrushTexture_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::GetTextureInfoForBrushTexture(
        CSimpleMapFile *this,
        MapBrushTexture_t *pBrushTexture,
        const Vector *vRelativeOrigin)
{
  int i; // ecx
  MapBrushTexture_t *p_m_vVAxis; // esi
  float x; // xmm2_4
  int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float y; // xmm2_4
  float z; // xmm2_4
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  MapTextureInfo_t texInfo; // [esp+0h] [ebp-48h] BYREF

  memset(&texInfo, 0, sizeof(texInfo));
  for ( i = 0; i < 2; ++i )
  {
    if ( pBrushTexture->m_flTextureWorldUnitsPerTexel[i] == 0.0 )
      pBrushTexture->m_flTextureWorldUnitsPerTexel[i] = 1.0;
    p_m_vVAxis = pBrushTexture;
    if ( i != 0 )
      p_m_vVAxis = (MapBrushTexture_t *)&pBrushTexture->m_vVAxis;
    x = p_m_vVAxis->m_vUAxis.x;
    v7 = i;
    v8 = 1.0 / pBrushTexture->m_flTextureWorldUnitsPerTexel[i];
    texInfo.m_flTextureVectors[v7][0] = p_m_vVAxis->m_vUAxis.x * v8;
    v9 = 1.0 / pBrushTexture->m_flLightmapWorldUnitsPerLuxel;
    texInfo.m_flLightmapVectors[v7][0] = x * v9;
    y = p_m_vVAxis->m_vUAxis.y;
    texInfo.m_flTextureVectors[v7][1] = y * v8;
    texInfo.m_flLightmapVectors[v7][1] = y * v9;
    z = p_m_vVAxis->m_vUAxis.z;
    texInfo.m_flTextureVectors[v7][2] = z * v8;
    texInfo.m_flLightmapVectors[v7][2] = z * v9;
    v12 = i;
    v13 = texInfo.m_flLightmapVectors[i][1] * vRelativeOrigin->y;
    v14 = texInfo.m_flLightmapVectors[i][2] * vRelativeOrigin->z;
    texInfo.m_flTextureVectors[v12][3] = (float)((float)((float)(texInfo.m_flTextureVectors[i][0] * vRelativeOrigin->x)
                                                       + (float)(texInfo.m_flTextureVectors[i][1] * vRelativeOrigin->y))
                                               + (float)(texInfo.m_flTextureVectors[i][2] * vRelativeOrigin->z))
                                       + pBrushTexture->m_flShift[i];
    v15 = (float)((float)(texInfo.m_flLightmapVectors[i][0] * vRelativeOrigin->x) + v13) + v14;
    v16 = (float)(pBrushTexture->m_flTextureWorldUnitsPerTexel[i] * v9) * pBrushTexture->m_flShift[i];
    texInfo.m_flLightmapVectors[v12][3] = v15 + v16;
  }
  texInfo.m_SurfaceFlags = pBrushTexture->m_SurfaceFlags;
  texInfo.m_nTextureDataIndex = CSimpleMapFile::FindOrCreateTextureData(
                                  this,
                                  pTextureName: pBrushTexture->m_MaterialName);
  return CSimpleMapFile::FindOrCreateTextureInfo(this, textureInfo: &texInfo);
}

//------------------------------------------------------------------------------
// Address: 0x100661D0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::ConnectionsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::ConnectionsChunkHandler(CChunkFile *pFile, void *pData)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap connectionsChunkHandlers; // [esp+8h] [ebp-Ch] BYREF

  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&connectionsChunkHandlers);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &connectionsChunkHandlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::ConnectionsKeyHandler,
            pData);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &connectionsChunkHandlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x10066220
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SideKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::SideKeyHandler(const char *pKey, const char *pValue, char *pData)
{
  CSimpleMapFile::MaterialInfo_t *MaterialInfo; // eax
  _DWORD *v5; // esi
  int v6; // eax

  if ( _V_stricmp(s1: pKey, s2: "plane") == 0 )
  {
    if ( sscanf(
           string: pValue,
           format: "(%f %f %f) (%f %f %f) (%f %f %f)",
           pData + 12,
           pData + 16,
           pData + 20,
           pData + 24,
           pData + 28,
           pData + 32,
           pData + 36,
           pData + 40,
           pData + 44) != 9 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "Plane definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "material") == 0 )
  {
    _V_strcpy(dest: pData + 92, src: pValue);
    MaterialInfo = CSimpleMapFile::FindMaterialInfo(this: *(CSimpleMapFile **)pData, pName: pData + 92);
    **((_DWORD **)pData + 2) = MaterialInfo->m_ContentsFlags;
    *(_WORD *)(*((_DWORD *)pData + 2) + 4) = MaterialInfo->m_SurfaceFlags;
    *((_WORD *)pData + 110) = MaterialInfo->m_SurfaceFlags;
    *((_DWORD *)pData + 22) = 1098907648;
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "uaxis") == 0 )
  {
    if ( sscanf(string: pValue, format: "[%f %f %f %f] %f", pData + 48, pData + 52, pData + 56, pData + 72, pData + 80) != 5 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "U axis definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "vaxis") == 0 )
  {
    if ( sscanf(string: pValue, format: "[%f %f %f %f] %f", pData + 60, pData + 64, pData + 68, pData + 76, pData + 84) != 5 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "V axis definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "contents") == 0 )
  {
LABEL_13:
    v5 = *((_DWORD **)pData + 2);
    *v5 |= atoi(nptr: pValue);
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "lightmapscale") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "contents") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "flags") == 0 )
      {
        *((_WORD *)pData + 110) |= atoi(nptr: pValue);
        *(_WORD *)(*((_DWORD *)pData + 2) + 4) = *((_WORD *)pData + 110);
        return 0;
      }
      if ( _V_stricmp(s1: pKey, s2: "smoothing_groups") != 0 )
        _V_stricmp(s1: pKey, s2: "id");
      return 0;
    }
    goto LABEL_13;
  }
  v6 = atoi(nptr: pValue);
  if ( v6 <= 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Invalid 'lightmapscale' specified (%s); must be >= 1.");
    v6 = 16;
  }
  *((float *)pData + 22) = (float)v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100664D0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  int v3; // eax
  CSimpleMapFile *v4; // edx
  int v5; // esi
  CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *v6; // ecx

  if ( _V_stricmp(s1: pKey, s2: "power") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "flags") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "startposition") != 0
        || sscanf(
             string: pValue,
             format: "[%f %f %f]",
             &pData[1]->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount,
             &pData[1]->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize,
             &pData[1]->m_PlaneHash.m_Planes.m_Size) == 3 )
      {
        return 0;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Start position definition malformed.");
      return 1;
    }
    else
    {
      pData[1]->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)atoi(nptr: pValue);
      return 0;
    }
  }
  else
  {
    v3 = atoi(nptr: pValue);
    pData[1]->m_pFileSystem = (IFileSystem *)v3;
    if ( (unsigned int)(v3 - 2) <= 2 )
    {
      v4 = pData[1];
      v5 = 1 << v3;
      v4->m_PlaneHash.m_HashTable[2] = 0;
      CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int> > *)&v4->m_PlaneHash.m_Planes.m_pElements,
        elem: 0,
        num: ((1 << v3) + 1) * ((1 << v3) + 1));
      v6 = (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&pData[1]->m_PlaneHash.m_HashTable[4];
      v6->m_Size = 0;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        this: v6,
        elem: 0,
        num: 2 * v5 * v5);
      return 0;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066630
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DispInfoChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DispInfoChunkHandler(CChunkFile *pFile, CSimpleMapFile **pData)
{
  CSimpleMapFile *v2; // esi
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *p_m_Displacements; // edi
  ChunkFileResult_t v4; // edi
  CChunkHandlerMap dispInfoChunkHandlers; // [esp+Ch] [ebp-18h] BYREF
  DisplacementLoadingInfo_t displacementLoadingInfo; // [esp+18h] [ebp-Ch] BYREF

  v2 = *pData;
  p_m_Displacements = &(*pData)->m_Displacements;
  *(_QWORD *)&displacementLoadingInfo.m_pDisplacement = 0;
  displacementLoadingInfo.m_pMapFile = v2;
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
    this: p_m_Displacements,
    elem: p_m_Displacements->m_Size);
  displacementLoadingInfo.m_pDisplacement = &p_m_Displacements->m_Memory.m_pMemory[v2->m_Displacements.m_Size - 1];
  displacementLoadingInfo.m_pDisplacement->m_nFlags = 0;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&dispInfoChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "normals",
    pfnHandler: CSimpleMapFile::DisplacementNormalsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "distances",
    pfnHandler: CSimpleMapFile::DisplacementDistancesChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "offsets",
    pfnHandler: CSimpleMapFile::DisplacementOffsetsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "alphas",
    pfnHandler: CSimpleMapFile::DisplacementAlphasChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "triangle_tags",
    pfnHandler: CSimpleMapFile::DisplacementTriangleTagsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_0",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor0,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_1",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor1,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_2",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor2,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_3",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor3,
    pData: &displacementLoadingInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &dispInfoChunkHandlers);
  v4 = CChunkFile::ReadChunk(
         this: pFile,
         pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementKeyHandler,
         pData: &displacementLoadingInfo);
  CChunkFile::PopHandlers(this: pFile);
  if ( v4 != ChunkFile_Ok )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    CChunkHandlerMap::~CChunkHandlerMap(this: &dispInfoChunkHandlers);
    return v4;
  }
  else
  {
    pData[2]->m_PlaneHash.m_HashTable[2] = (*pData)->m_Displacements.m_Size - 1;
    CChunkHandlerMap::~CChunkHandlerMap(this: &dispInfoChunkHandlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066890
// Name: private: struct MapBrushSide_t __near * CSimpleMapFile::AllocateNewBrushSide(void)
// Source: json
//------------------------------------------------------------------------------
MapBrushSide_t *__thiscall CSimpleMapFile::AllocateNewBrushSide(CSimpleMapFile *this)
{
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::InsertBefore(
    this: &this->m_BrushSides,
    elem: this->m_BrushSides.m_Size);
  memset(
    dst: (unsigned __int8 *)&this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1],
    value: 0,
    count: sizeof(this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1]));
  this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1].m_nDisplacementIndex = -1;
  return &this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10066900
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SideChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::SideChunkHandler(CChunkFile *pFile, char *pData)
{
  MapBrushSide_t *NewBrushSide; // edi
  int i; // ebx
  int m_nPlaneIndex; // ecx
  int v7; // eax
  MapBrushTexture_t *NewBrushTexture; // ebx
  CChunkHandlerMap sideChunkHandlers; // [esp+Ch] [ebp-Ch] BYREF
  ChunkFileResult_t Chunk; // [esp+24h] [ebp+Ch]

  NewBrushSide = CSimpleMapFile::AllocateNewBrushSide(this: *(CSimpleMapFile **)pData);
  *((_DWORD *)pData + 2) = NewBrushSide;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&sideChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &sideChunkHandlers,
    pszChunkName: "dispinfo",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DispInfoChunkHandler,
    pData);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &sideChunkHandlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::SideKeyHandler,
            pData);
  CChunkFile::PopHandlers(this: pFile);
  if ( Chunk != ChunkFile_Ok )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    CChunkHandlerMap::~CChunkHandlerMap(this: &sideChunkHandlers);
    return Chunk;
  }
  else
  {
    NewBrushSide->m_ContentsFlags |= *((_DWORD *)pData + 56);
    if ( (*(_BYTE *)(*(_DWORD *)pData + 4272) & 1) != 0 )
      NewBrushSide->m_ContentsFlags |= 0x8000000u;
    if ( (NewBrushSide->m_ContentsFlags & 0x30000) != 0 )
      NewBrushSide->m_ContentsFlags |= 0x8000000u;
    if ( (NewBrushSide->m_ContentsFlags & 0x300FF) == 0 )
      NewBrushSide->m_ContentsFlags |= 1u;
    if ( (NewBrushSide->m_SurfaceFlags & 0x300) != 0 )
      NewBrushSide->m_ContentsFlags = 0;
    NewBrushSide->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(
                                    this: (CPlaneHash *)(*(_DWORD *)pData + 8),
                                    vPoints: (Vector *)pData + 1);
    for ( i = 0; i < *(_DWORD *)(*((_DWORD *)pData + 1) + 8); ++i )
    {
      m_nPlaneIndex = NewBrushSide->m_nPlaneIndex;
      v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)pData + 4188) + 44 * (i + *(_DWORD *)(*((_DWORD *)pData + 1) + 4)) + 8);
      if ( (v7 == m_nPlaneIndex || v7 == (m_nPlaneIndex ^ 1))
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Duplicate or mirrored plane.\n");
      }
    }
    if ( i == *(_DWORD *)(*((_DWORD *)pData + 1) + 8) )
    {
      NewBrushTexture = CSimpleMapFile::AllocateNewBrushTexture(this: *(CSimpleMapFile **)pData);
      MapBrushTexture_t::operator=(this: NewBrushTexture, __that: (const MapBrushTexture_t *)(pData + 48));
      NewBrushSide->m_nTextureInfoIndex = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                            this: *(CSimpleMapFile **)pData,
                                            pBrushTexture: NewBrushTexture,
                                            vRelativeOrigin: &vec3_origin);
      ++*(_DWORD *)(*((_DWORD *)pData + 1) + 8);
    }
    *((_DWORD *)pData + 2) = 0;
    CChunkHandlerMap::~CChunkHandlerMap(this: &sideChunkHandlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066AD0
// Name: private: CSimpleMapFile::CSimpleMapFile(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleMapFile *__thiscall CSimpleMapFile::CSimpleMapFile(
        CSimpleMapFile *this,
        IFileSystem *pFileSystem,
        const char *pVMFFilename)
{
  this->m_pFilename = pVMFFilename;
  this->m_pFileSystem = pFileSystem;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_Entities.m_Memory.m_pMemory = nullptr;
  this->m_Entities.m_Memory.m_nAllocationCount = 0;
  this->m_Entities.m_Memory.m_nGrowSize = 0;
  this->m_Entities.m_Size = 0;
  this->m_Entities.m_pElements = nullptr;
  this->m_Brushes.m_Memory.m_pMemory = nullptr;
  this->m_Brushes.m_Memory.m_nAllocationCount = 0;
  this->m_Brushes.m_Memory.m_nGrowSize = 0;
  this->m_Brushes.m_Size = 0;
  this->m_Brushes.m_pElements = nullptr;
  this->m_Displacements.m_Memory.m_pMemory = nullptr;
  this->m_Displacements.m_Memory.m_nAllocationCount = 0;
  this->m_Displacements.m_Memory.m_nGrowSize = 0;
  this->m_Displacements.m_Size = 0;
  this->m_Displacements.m_pElements = nullptr;
  this->m_BrushSides.m_Memory.m_pMemory = nullptr;
  this->m_BrushSides.m_Memory.m_nAllocationCount = 0;
  this->m_BrushSides.m_Memory.m_nGrowSize = 0;
  this->m_BrushSides.m_Size = 0;
  this->m_BrushSides.m_pElements = nullptr;
  this->m_BrushTextures.m_Memory.m_pMemory = nullptr;
  this->m_BrushTextures.m_Memory.m_nAllocationCount = 0;
  this->m_BrushTextures.m_Memory.m_nGrowSize = 0;
  this->m_BrushTextures.m_Size = 0;
  this->m_BrushTextures.m_pElements = nullptr;
  this->m_TextureInfos.m_Memory.m_pMemory = nullptr;
  this->m_TextureInfos.m_Memory.m_nAllocationCount = 0;
  this->m_TextureInfos.m_Memory.m_nGrowSize = 0;
  this->m_TextureInfos.m_Size = 0;
  this->m_TextureInfos.m_pElements = nullptr;
  this->m_TextureData.m_Memory.m_pMemory = nullptr;
  this->m_TextureData.m_Memory.m_nAllocationCount = 0;
  this->m_TextureData.m_Memory.m_nGrowSize = 0;
  this->m_TextureData.m_Size = 0;
  this->m_TextureData.m_pElements = nullptr;
  this->m_nInstanceCount = 0;
  this->m_InstanceFlags = NO_FLAGS;
  this->m_KeyValuePairs.m_Memory.m_pMemory = nullptr;
  this->m_KeyValuePairs.m_Memory.m_nAllocationCount = 0;
  this->m_KeyValuePairs.m_Memory.m_nGrowSize = 0;
  this->m_KeyValuePairs.m_Size = 0;
  this->m_KeyValuePairs.m_pElements = nullptr;
  CStringPool::CStringPool(this: &this->m_KeyValueStringPool, caseSensitivity: StringPoolCaseInsensitive);
  this->m_nMapRevision = 0;
  this->m_nHighestID = 0;
  this->m_MaterialInfos.m_Memory.m_pMemory = nullptr;
  this->m_MaterialInfos.m_Memory.m_nAllocationCount = 0;
  this->m_MaterialInfos.m_Memory.m_nGrowSize = 0;
  this->m_MaterialInfos.m_Size = 0;
  this->m_MaterialInfos.m_pElements = nullptr;
  ClearBounds(mins: &this->m_vMinBounds, maxs: &this->m_vMaxBounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066C40
// Name: private: void CSimpleMapFile::MergeBrushSides(int,class CSimpleMapFile __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeBrushSides(
        CSimpleMapFile *this,
        int nEntityIndex,
        CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        CSimpleMapFile *transform)
{
  HashedPlane_t *m_pMemory; // ecx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapBrushSide_t *v10; // ecx
  int v11; // eax
  MapBrushSide_t *v12; // ebx
  char *v13; // ebx
  MapBrushSide_t *v14; // edi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v15; // eax
  int v16; // ebx
  CSimpleMapFile *v17; // eax
  MapEntity_t *v18; // edx
  int m_nNumBrushes; // ecx
  int v20; // ebx
  int *p_m_nNumSides; // eax
  int v22; // edx
  const HashedPlane_t *v23; // ebx
  MapBrush_t *v24; // eax
  int m_nFirstSideIndex; // edx
  Vector *v26; // eax
  MapBrushTexture_t *NewBrushTexture; // ebx
  int v28; // esi
  CMapDisplacement *v29; // esi
  CMapDisplacement *v30; // eax
  CSimpleMapFile *v31; // eax
  int TextureInfoForBrushTexture; // eax
  char *v33; // [esp-Ch] [ebp-7Ch]
  Vector out; // [esp+4h] [ebp-6Ch] BYREF
  cplane_t outPlane; // [esp+10h] [ebp-60h] BYREF
  cplane_t inPlane; // [esp+24h] [ebp-4Ch] BYREF
  __int64 in1; // [esp+38h] [ebp-38h] BYREF
  int v38; // [esp+40h] [ebp-30h]
  Vector vPosition; // [esp+44h] [ebp-2Ch] BYREF
  Vector vNormal; // [esp+50h] [ebp-20h]
  const HashedPlane_t *pInstancePlanes; // [esp+5Ch] [ebp-14h]
  float flDistance; // [esp+60h] [ebp-10h]
  int v43; // [esp+64h] [ebp-Ch]
  CSimpleMapFile *v44; // [esp+68h] [ebp-8h]
  int v45; // [esp+6Ch] [ebp-4h]

  m_pMemory = pInstanceMap->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
  v44 = this;
  LODWORD(vNormal.x) = m_pMemory;
  v43 = 0;
  if ( pInstanceMap->m_BrushSides.m_Size > 0 )
  {
    flDistance = 0.0;
    vNormal.z = 0.0;
    do
    {
      m_Size = this->m_BrushSides.m_Size;
      m_nAllocationCount = this->m_BrushSides.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<MapBrushSide_t,int>::Grow(this: &this->m_BrushSides.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->m_BrushSides.m_Size;
      v10 = this->m_BrushSides.m_Memory.m_pMemory;
      v11 = this->m_BrushSides.m_Size - m_Size - 1;
      this->m_BrushSides.m_pElements = v10;
      if ( v11 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v10[m_Size + 1], src: (unsigned __int8 *)&v10[m_Size], count: 44 * v11);
      v12 = &this->m_BrushSides.m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
      {
        v12->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        v12->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
        v12->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
        v12->m_Polygon.m_Points.m_Size = 0;
        v12->m_Polygon.m_Points.m_pElements = nullptr;
        v12->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      }
      memset(
        dst: (unsigned __int8 *)&this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1],
        value: 0,
        count: sizeof(this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1]));
      this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1].m_nDisplacementIndex = -1;
      v13 = (char *)pInstanceMap->m_BrushSides.m_Memory.m_pMemory + LODWORD(vNormal.z);
      v14 = &this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1];
      v14->m_ContentsFlags = *(_DWORD *)v13;
      v14->m_SurfaceFlags = *((_WORD *)v13 + 2);
      v14->m_nPlaneIndex = *((_DWORD *)v13 + 2);
      v14->m_nTextureInfoIndex = *((_DWORD *)v13 + 3);
      if ( v13 == (char *)-16 )
        v15 = nullptr;
      else
        v15 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)(v13 + 20);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: &v14->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        other: v15);
      v16 = *((_DWORD *)v13 + 10);
      v14->m_nDisplacementIndex = v16;
      HIBYTE(v45) = v16 != -1;
      if ( v16 == -1 )
      {
        v17 = pInstanceMap;
        v18 = pInstanceMap->m_Entities.m_Memory.m_pMemory;
        m_nNumBrushes = v18->m_nNumBrushes;
        v20 = 0;
        if ( m_nNumBrushes <= 0 )
        {
LABEL_19:
          v23 = (const HashedPlane_t *)v17->m_Brushes.m_Size;
          pInstancePlanes = v23;
          if ( m_nNumBrushes < (int)v23 )
          {
            v24 = &v17->m_Brushes.m_Memory.m_pMemory[m_nNumBrushes];
            do
            {
              m_nFirstSideIndex = v24->m_nFirstSideIndex;
              if ( (v24->m_ContentsFlags & 0x20000000) != 0 )
              {
                if ( v43 >= m_nFirstSideIndex && v43 < m_nFirstSideIndex + v24->m_nNumSides )
                  goto LABEL_28;
                v23 = pInstancePlanes;
              }
              ++m_nNumBrushes;
              ++v24;
            }
            while ( m_nNumBrushes < (int)v23 );
          }
        }
        else
        {
          p_m_nNumSides = &pInstanceMap->m_Brushes.m_Memory.m_pMemory[v18->m_nFirstBrushIndex].m_nNumSides;
          while ( 1 )
          {
            v22 = *(p_m_nNumSides - 1);
            if ( v43 >= v22 && v43 < v22 + *p_m_nNumSides )
              break;
            ++v20;
            p_m_nNumSides += 9;
            if ( v20 >= m_nNumBrushes )
            {
              this = v44;
              v17 = pInstanceMap;
              goto LABEL_19;
            }
          }
          this = v44;
LABEL_28:
          HIBYTE(v45) = 1;
        }
      }
      v26 = (Vector *)(LODWORD(vNormal.x) + 24 * v14->m_nPlaneIndex);
      vPosition = *v26;
      vNormal.y = *(float *)(LODWORD(vNormal.x) + 24 * v14->m_nPlaneIndex + 12);
      NewBrushTexture = CSimpleMapFile::AllocateNewBrushTexture(this);
      MapBrushTexture_t::operator=(
        this: NewBrushTexture,
        __that: (const MapBrushTexture_t *)((char *)pInstanceMap->m_BrushTextures.m_Memory.m_pMemory + LODWORD(flDistance)));
      if ( HIBYTE(v45) != 0 )
      {
        v28 = 0;
        if ( v14->m_Polygon.m_Points.m_Size > 0 )
        {
          pInstancePlanes = nullptr;
          do
          {
            v33 = (char *)v14->m_Polygon.m_Points.m_Memory.m_pMemory + (unsigned int)pInstancePlanes;
            in1 = *(_QWORD *)v33;
            v38 = *((_DWORD *)v33 + 2);
            VectorTransform((float *)&in1, in2: (const matrix3x4_t *)transform, out: (float *)v33);
            pInstancePlanes = (const HashedPlane_t *)((char *)pInstancePlanes + 12);
            ++v28;
          }
          while ( v28 < v14->m_Polygon.m_Points.m_Size );
        }
        *(Vector *)&outPlane.normal.z = vPosition;
        inPlane.normal.x = vNormal.y;
        VectorRotate(in1: &outPlane.normal.z, in2: (const matrix3x4_t *)transform, out: &out.x);
        outPlane.normal.x = (float)((float)((float)(*(float *)&transform->m_PlaneHash.m_Planes.m_pElements * out.y)
                                          + (float)(*(float *)&transform->m_PlaneHash.m_Planes.m_Memory.m_pMemory * out.x))
                                  + (float)(*(float *)&transform->m_PlaneHash.m_HashTable[3] * out.z))
                          + (float)((float)((float)((float)(out.x * out.x) + (float)(out.y * out.y))
                                          + (float)(out.z * out.z))
                                  * inPlane.normal.x);
        v14->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(
                               this: &v44->m_PlaneHash,
                               vNormal: &out,
                               flDistance: outPlane.normal.x);
        VectorRotate(
          in1: (float *)((char *)&pInstanceMap->m_BrushTextures.m_Memory.m_pMemory->m_vUAxis.x + LODWORD(flDistance)),
          in2: (const matrix3x4_t *)transform,
          out: &NewBrushTexture->m_vUAxis.x);
        VectorRotate(
          in1: (float *)((char *)&pInstanceMap->m_BrushTextures.m_Memory.m_pMemory->m_vVAxis.x + LODWORD(flDistance)),
          in2: (const matrix3x4_t *)transform,
          out: &NewBrushTexture->m_vVAxis.x);
        NewBrushTexture->m_flShift[0] = NewBrushTexture->m_flShift[0]
                                      - (float)((float)((float)((float)(NewBrushTexture->m_vUAxis.y * vOrigin->y)
                                                              + (float)(vOrigin->x * NewBrushTexture->m_vUAxis.x))
                                                      + (float)(NewBrushTexture->m_vUAxis.z * vOrigin->z))
                                              / NewBrushTexture->m_flTextureWorldUnitsPerTexel[0]);
        this = v44;
        NewBrushTexture->m_flShift[1] = NewBrushTexture->m_flShift[1]
                                      - (float)((float)((float)((float)(NewBrushTexture->m_vVAxis.y * vOrigin->y)
                                                              + (float)(NewBrushTexture->m_vVAxis.x * vOrigin->x))
                                                      + (float)(NewBrushTexture->m_vVAxis.z * vOrigin->z))
                                              / NewBrushTexture->m_flTextureWorldUnitsPerTexel[1]);
        if ( v14->m_nDisplacementIndex != -1 )
        {
          CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
            this: &this->m_Displacements,
            elem: this->m_Displacements.m_Size);
          v29 = &this->m_Displacements.m_Memory.m_pMemory[this->m_Displacements.m_Size - 1];
          v30 = &pInstanceMap->m_Displacements.m_Memory.m_pMemory[v14->m_nDisplacementIndex];
          v29->m_nPower = v30->m_nPower;
          v29->m_nOriginalBrushSide = v30->m_nOriginalBrushSide;
          v29->m_nFlags = v30->m_nFlags;
          v29->m_ContentsFlags = v30->m_ContentsFlags;
          v29->m_vStartPosition.x = v30->m_vStartPosition.x;
          v29->m_vStartPosition.y = v30->m_vStartPosition.y;
          v29->m_vStartPosition.z = v30->m_vStartPosition.z;
          pInstancePlanes = (const HashedPlane_t *)v29->m_Vertices.m_Memory.m_nGrowSize;
          v29->m_Vertices.m_Memory.m_nGrowSize = v30->m_Vertices.m_Memory.m_nGrowSize;
          v30->m_Vertices.m_Memory.m_nGrowSize = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_Vertices.m_Memory.m_pMemory;
          v29->m_Vertices.m_Memory.m_pMemory = v30->m_Vertices.m_Memory.m_pMemory;
          v30->m_Vertices.m_Memory.m_pMemory = (CMapDisplacement::Vertex_t *)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_Vertices.m_Memory.m_nAllocationCount;
          v29->m_Vertices.m_Memory.m_nAllocationCount = v30->m_Vertices.m_Memory.m_nAllocationCount;
          v30->m_Vertices.m_Memory.m_nAllocationCount = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_Vertices.m_Size;
          v29->m_Vertices.m_Size = v30->m_Vertices.m_Size;
          v30->m_Vertices.m_Size = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_Vertices.m_pElements;
          v29->m_Vertices.m_pElements = v30->m_Vertices.m_pElements;
          v30->m_Vertices.m_pElements = (CMapDisplacement::Vertex_t *)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_TriangleTags.m_Memory.m_nGrowSize;
          v29->m_TriangleTags.m_Memory.m_nGrowSize = v30->m_TriangleTags.m_Memory.m_nGrowSize;
          v30->m_TriangleTags.m_Memory.m_nGrowSize = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_TriangleTags.m_Memory.m_pMemory;
          v29->m_TriangleTags.m_Memory.m_pMemory = v30->m_TriangleTags.m_Memory.m_pMemory;
          v30->m_TriangleTags.m_Memory.m_pMemory = (unsigned __int16 *)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_TriangleTags.m_Memory.m_nAllocationCount;
          v29->m_TriangleTags.m_Memory.m_nAllocationCount = v30->m_TriangleTags.m_Memory.m_nAllocationCount;
          v30->m_TriangleTags.m_Memory.m_nAllocationCount = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_TriangleTags.m_Size;
          v29->m_TriangleTags.m_Size = v30->m_TriangleTags.m_Size;
          v30->m_TriangleTags.m_Size = (int)pInstancePlanes;
          pInstancePlanes = (const HashedPlane_t *)v29->m_TriangleTags.m_pElements;
          v29->m_TriangleTags.m_pElements = v30->m_TriangleTags.m_pElements;
          v30->m_TriangleTags.m_pElements = (unsigned __int16 *)pInstancePlanes;
          *(_QWORD *)&inPlane.normal.z = *(_QWORD *)&v29->m_vStartPosition.x;
          *(float *)&inPlane.type = v29->m_vStartPosition.z;
          VectorTransform(in1: &inPlane.normal.z, in2: (const matrix3x4_t *)transform, out: &v29->m_vStartPosition.x);
          v31 = v44;
          v29->m_nOriginalBrushSide = v44->m_BrushSides.m_Size - 1;
          v14->m_nDisplacementIndex = v31->m_Displacements.m_Size - 1;
          this = v31;
        }
      }
      else
      {
        v14->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(
                               this: &this->m_PlaneHash,
                               vNormal: &vPosition,
                               flDistance: vNormal.y);
      }
      TextureInfoForBrushTexture = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                     this,
                                     pBrushTexture: NewBrushTexture,
                                     vRelativeOrigin: &vec3_origin);
      LODWORD(vNormal.z) += 44;
      LODWORD(flDistance) += 176;
      v14->m_nTextureInfoIndex = TextureInfoForBrushTexture;
      ++v43;
    }
    while ( v43 < pInstanceMap->m_BrushSides.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100671C0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SolidChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::SolidChunkHandler(CChunkFile *pFile, int *pData)
{
  CSimpleMapFile *v3; // ecx
  int v4; // edi
  MapBrush_t *NewBrush; // esi
  CSimpleMapFile *v6; // eax
  int j; // eax
  int v9; // ecx
  int m_nFirstSideIndex; // edx
  int v11; // eax
  int v12; // eax
  int v13; // edi
  MapBrushSide_t *v14; // ecx
  int m_nDisplacementIndex; // eax
  CMapDisplacement *v16; // eax
  int v17; // eax
  BrushSideLoadingInfo_t brushSideLoadingInfo; // [esp+Ch] [ebp-104h] BYREF
  CMapDisplacement *pDisplacement; // [esp+F0h] [ebp-20h]
  int nContainingEntityIndex; // [esp+F4h] [ebp-1Ch]
  MapBrushSide_t *pSide; // [esp+F8h] [ebp-18h]
  CChunkHandlerMap solidChunkHandlers; // [esp+FCh] [ebp-14h] BYREF
  int k; // [esp+108h] [ebp-8h]
  int i; // [esp+10Ch] [ebp-4h]
  ChunkFileResult_t bHasDisplacements; // [esp+11Ch] [ebp+Ch]
  char bHasDisplacements_3; // [esp+11Fh] [ebp+Fh]

  v3 = (CSimpleMapFile *)*pData;
  v4 = *(_DWORD *)(*pData + 4140) - 1;
  nContainingEntityIndex = v4;
  NewBrush = CSimpleMapFile::AllocateNewBrush(this: v3);
  NewBrush->m_nFirstSideIndex = *(_DWORD *)(*pData + 4200);
  NewBrush->m_nNumSides = 0;
  *(_QWORD *)&brushSideLoadingInfo.m_pBrush = 0;
  memset(
    dst: (unsigned __int8 *)&brushSideLoadingInfo.m_Texture,
    value: 0,
    count: sizeof(brushSideLoadingInfo.m_Texture));
  v6 = (CSimpleMapFile *)*pData;
  brushSideLoadingInfo.m_BaseContentsFlags = pData[2];
  brushSideLoadingInfo.m_pMapFile = v6;
  brushSideLoadingInfo.m_pBrush = NewBrush;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&solidChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &solidChunkHandlers,
    pszChunkName: "side",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::SideChunkHandler,
    pData: &brushSideLoadingInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &solidChunkHandlers);
  bHasDisplacements = CChunkFile::ReadChunk(
                        this: pFile,
                        pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))BlankImage::GetNumFrames,
                        pData: (void *)NewBrush);
  CChunkFile::PopHandlers(this: pFile);
  if ( bHasDisplacements != ChunkFile_Ok )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
    CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
    return bHasDisplacements;
  }
  else
  {
    NewBrush->m_ContentsFlags = CSimpleMapFile::ComputeBrushContents(this: (CSimpleMapFile *)*pData, pBrush: NewBrush);
    CSimpleMapFile::MakeBrushPolygons(this: (CSimpleMapFile *)*pData, pBrush: NewBrush);
    if ( v4 == 0 && (NewBrush->m_ContentsFlags & 0x30000) != 0 )
    {
      for ( j = 0; j < NewBrush->m_nNumSides; *(_DWORD *)(v9 + *(_DWORD *)(*pData + 4188) + 12) = -1 )
      {
        v9 = 44 * (j + NewBrush->m_nFirstSideIndex);
        ++j;
      }
    }
    if ( (NewBrush->m_ContentsFlags & 0x1000000) != 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Origin brushes not currently supported.\n");
      CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
      return 9;
    }
    else
    {
      m_nFirstSideIndex = NewBrush->m_nFirstSideIndex;
      v11 = m_nFirstSideIndex + NewBrush->m_nNumSides;
      bHasDisplacements_3 = 0;
      i = m_nFirstSideIndex;
      if ( m_nFirstSideIndex >= v11 )
        goto LABEL_29;
      v12 = 44 * m_nFirstSideIndex;
      for ( k = 44 * m_nFirstSideIndex; ; v12 = k )
      {
        v13 = *pData;
        v14 = (MapBrushSide_t *)(v12 + *(_DWORD *)(*pData + 4188));
        m_nDisplacementIndex = v14->m_nDisplacementIndex;
        pSide = v14;
        if ( m_nDisplacementIndex != -1 )
        {
          bHasDisplacements_3 = 1;
          pDisplacement = (CMapDisplacement *)(*(_DWORD *)(v13 + 4168) + 68 * m_nDisplacementIndex);
          if ( nContainingEntityIndex != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
              _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
            v14 = pSide;
          }
          m_nFirstSideIndex = i;
          if ( v14->m_Polygon.m_Points.m_Size != 4 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
              _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "%s\n(Entity %i, Brush %i, Side %i)\n");
            m_nFirstSideIndex = i;
          }
          v16 = pDisplacement;
          pDisplacement->m_nOriginalBrushSide = m_nFirstSideIndex;
          v16->m_ContentsFlags = NewBrush->m_ContentsFlags;
        }
        v17 = NewBrush->m_nFirstSideIndex + NewBrush->m_nNumSides;
        k += 44;
        i = ++m_nFirstSideIndex;
        if ( m_nFirstSideIndex >= v17 )
          break;
      }
      if ( bHasDisplacements_3 != 0 )
      {
        --*(_DWORD *)(*pData + 4160);
        CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
        return 0;
      }
      else
      {
LABEL_29:
        ++*(_DWORD *)(pData[1] + 16);
        CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
        return 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100674D0
// Name: private: void CSimpleMapFile::MergeInstance(int,class CSimpleMapFile __near *,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeInstance(
        CSimpleMapFile *this,
        int nEntityIndex,
        CSimpleMapFile *pInstanceMap,
        GameData *pGameData)
{
  MapEntity_t *v5; // eax
  int m_nNumKVPairs; // ebx
  MapEntityKeyValuePair_t *v7; // eax
  int v8; // edi
  MapEntityKeyValuePair_t *v9; // eax
  const char *m_pValue; // eax
  matrix3x4_t instanceTransform; // [esp+8h] [ebp-50h] BYREF
  Vector vInstanceOrigin; // [esp+38h] [ebp-20h] BYREF
  QAngle instanceAngles; // [esp+44h] [ebp-14h] BYREF
  MapEntityKeyValuePair_t *v14; // [esp+50h] [ebp-8h]
  const char **p_m_pKey; // [esp+54h] [ebp-4h]

  v5 = &this->m_Entities.m_Memory.m_pMemory[nEntityIndex];
  vInstanceOrigin = v5->m_vOrigin;
  m_nNumKVPairs = v5->m_nNumKVPairs;
  v7 = &this->m_KeyValuePairs.m_Memory.m_pMemory[v5->m_nFirstKVPairIndex];
  v8 = 0;
  v14 = v7;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_8;
  p_m_pKey = &v7->m_pKey;
  while ( _V_stricmp(s1: *p_m_pKey, s2: "angles") != 0 )
  {
    p_m_pKey += 3;
    if ( ++v8 >= m_nNumKVPairs )
      goto LABEL_8;
  }
  v9 = &v14[v8];
  if ( v9 == nullptr || (m_pValue = v9->m_pValue) == nullptr )
LABEL_8:
    m_pValue = szDescription;
  sscanf(string: m_pValue, format: "%f %f %f", &instanceAngles, &instanceAngles.y, &instanceAngles.z);
  AngleMatrix(angles: &instanceAngles, position: &vInstanceOrigin, matrix: &instanceTransform);
  ++this->m_nInstanceCount;
  GameData::BeginMapInstance(this: pGameData);
  CSimpleMapFile::MergeBrushes(
    this,
    nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: &instanceTransform);
  CSimpleMapFile::MergeBrushSides(
    this,
    nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: (CSimpleMapFile *)&instanceTransform);
  CSimpleMapFile::MergeEntities(
    this,
    (MapEntityKeyValuePair_t *)nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: &instanceTransform,
    pGameData);
}

//------------------------------------------------------------------------------
// Address: 0x100675F0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::EntityChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
CChunkFile *__cdecl CSimpleMapFile::EntityChunkHandler(CChunkFile *pFile, CSimpleMapFile *pData)
{
  MapEntity_t *NewEntity; // edi
  int m_BaseContentsFlags; // esi
  MapBrush_t *m_pMemory; // ecx
  bool v7; // cc
  MapBrush_t *v8; // eax
  float x; // xmm1_4
  int v10; // esi
  int v11; // edx
  HashedPlane_t *v12; // eax
  float v13; // xmm1_4
  float z; // xmm0_4
  int TextureInfoForBrushTexture; // eax
  int v16; // ecx
  Vector vNormal; // [esp+10h] [ebp-2Ch] BYREF
  CChunkHandlerMap v18; // [esp+1Ch] [ebp-20h] BYREF
  CSimpleMapFile *v19; // [esp+28h] [ebp-14h] BYREF
  EntityLoadingInfo_t entityLoadingInfo; // [esp+2Ch] [ebp-10h]
  int i; // [esp+38h] [ebp-4h]
  CChunkFile *pFilea; // [esp+48h] [ebp+Ch]
  CChunkFile *pFileb; // [esp+48h] [ebp+Ch]

  NewEntity = CSimpleMapFile::AllocateNewEntity(this: pData);
  NewEntity->m_nFirstBrushIndex = pData->m_Brushes.m_Size;
  NewEntity->m_nNumBrushes = 0;
  NewEntity->m_nFirstKVPairIndex = pData->m_KeyValuePairs.m_Size;
  NewEntity->m_nNumKVPairs = 0;
  entityLoadingInfo.m_pEntity = nullptr;
  v19 = pData;
  entityLoadingInfo.m_pMapFile = (CSimpleMapFile *)NewEntity;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&v18);
  CChunkHandlerMap::AddHandler(
    this: &v18,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::SolidChunkHandler,
    pData: &v19);
  CChunkHandlerMap::AddHandler(
    this: &v18,
    pszChunkName: "connections",
    pfnHandler: CSimpleMapFile::ConnectionsChunkHandler,
    pData: &v19);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &v18);
  pFilea = (CChunkFile *)CChunkFile::ReadChunk(
                           this: pFile,
                           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::EntityKeyHandler,
                           pData: &v19);
  CChunkFile::PopHandlers(this: pFile);
  if ( pFilea == (CChunkFile *)9 )
  {
    --pData->m_Entities.m_Size;
    CChunkHandlerMap::~CChunkHandlerMap(this: &v18);
    return nullptr;
  }
  else if ( pFilea != nullptr )
  {
    CSimpleMapFile::ReportParseError(this: pData, pErrorString: "Error parsing entity.");
    CChunkHandlerMap::~CChunkHandlerMap(this: &v18);
    return pFilea;
  }
  else
  {
    if ( NewEntity->m_vOrigin.x != 0.0 || NewEntity->m_vOrigin.y != 0.0 || NewEntity->m_vOrigin.z != 0.0 )
    {
      m_BaseContentsFlags = 0;
      for ( entityLoadingInfo.m_BaseContentsFlags = 0;
            m_BaseContentsFlags < NewEntity->m_nNumBrushes;
            entityLoadingInfo.m_BaseContentsFlags = m_BaseContentsFlags )
      {
        m_pMemory = pData->m_Brushes.m_Memory.m_pMemory;
        v7 = m_pMemory[m_BaseContentsFlags + NewEntity->m_nFirstBrushIndex].m_nNumSides <= 0;
        v8 = &m_pMemory[m_BaseContentsFlags + NewEntity->m_nFirstBrushIndex];
        i = (int)v8;
        pFileb = nullptr;
        if ( !v7 )
        {
          do
          {
            x = NewEntity->m_vOrigin.x;
            v10 = (int)&pData->m_BrushSides.m_Memory.m_pMemory[(int)pFileb + v8->m_nFirstSideIndex];
            v11 = *(_DWORD *)(v10 + 8);
            v12 = pData->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
            *(_QWORD *)&vNormal.x = *(_QWORD *)&v12[*(_DWORD *)(v10 + 8)].m_vNormal.x;
            v13 = (float)(x * vNormal.x) + (float)(NewEntity->m_vOrigin.y * vNormal.y);
            z = NewEntity->m_vOrigin.z;
            vNormal.z = v12[v11].m_vNormal.z;
            *(_DWORD *)(v10 + 8) = CPlaneHash::FindPlaneIndex(
                                     this: &pData->m_PlaneHash,
                                     &vNormal,
                                     flDistance: v12[v11].m_flDistance - (float)(v13 + (float)(z * vNormal.z)));
            TextureInfoForBrushTexture = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                           this: pData,
                                           pBrushTexture: &pData->m_BrushTextures.m_Memory.m_pMemory[(int)pFileb + *(_DWORD *)(i + 4)],
                                           vRelativeOrigin: &NewEntity->m_vOrigin);
            v16 = i;
            *(_DWORD *)(v10 + 12) = TextureInfoForBrushTexture;
            v7 = (int)&pFileb->m_TokenReader.m_file.m_Memory.m_pMemory + 1 < *(_DWORD *)(v16 + 8);
            pFileb = (CChunkFile *)((char *)pFileb + 1);
            v8 = (MapBrush_t *)v16;
          }
          while ( v7 );
          m_BaseContentsFlags = entityLoadingInfo.m_BaseContentsFlags;
        }
        CSimpleMapFile::MakeBrushPolygons(this: pData, pBrush: v8);
        ++m_BaseContentsFlags;
      }
    }
    if ( ((int)entityLoadingInfo.m_pEntity & 0x8000000) != 0 )
      CSimpleMapFile::MoveEntityBrushesToWorld(this: pData, nEntityIndex: pData->m_Entities.m_Size - 1);
    CChunkHandlerMap::~CChunkHandlerMap(this: &v18);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067820
// Name: public: static void CSimpleMapFile::LoadFromFile(class IFileSystem __near *,char const __near *,class CSimpleMapFile __near * __near *,enum CSimpleMapFile::ResolveInstanceFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSimpleMapFile::LoadFromFile(
        IFileSystem *pFileSystem,
        const char *pVMFFilename,
        CSimpleMapFile **ppNewMapFile,
        CSimpleMapFile::ResolveInstanceFlags_t instanceFlags)
{
  ChunkFileResult_t v4; // edi
  CSimpleMapFile *v5; // eax
  CSimpleMapFile *v6; // eax
  ChunkFileResult_t v7; // edi
  int v8; // ebx
  int v9; // edi
  MapBrush_t *m_pMemory; // ecx
  float x; // xmm0_4
  const Vector *p_m_vMinBounds; // ecx
  int v13; // edi
  MapBrush_t *v14; // eax
  int m_Size; // ecx
  CChunkFile chunkFile; // [esp+Ch] [ebp-350h] BYREF
  CChunkHandlerMap VMFChunkHandlers; // [esp+350h] [ebp-Ch] BYREF

  CChunkFile::CChunkFile(this: &chunkFile);
  v4 = CChunkFile::Open(this: &chunkFile, pszFileName: pVMFFilename, eMode: ChunkFile_Read);
  *ppNewMapFile = nullptr;
  if ( v4 != ChunkFile_Ok )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    {
      CChunkFile::GetErrorText(this: &chunkFile, eResult: v4);
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error opening %s: %s.\n");
      CChunkFile::~CChunkFile(this: &chunkFile);
      return;
    }
  }
  else
  {
    v5 = (CSimpleMapFile *)operator new(nSize: 0x1118u);
    if ( v5 != nullptr )
      v6 = CSimpleMapFile::CSimpleMapFile(this: v5, pFileSystem, pVMFFilename);
    else
      v6 = nullptr;
    *ppNewMapFile = v6;
    v6->m_InstanceFlags = instanceFlags;
    CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&VMFChunkHandlers);
    CChunkHandlerMap::AddHandler(
      this: &VMFChunkHandlers,
      pszChunkName: "world",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::EntityChunkHandler,
      pData: *ppNewMapFile);
    CChunkHandlerMap::AddHandler(
      this: &VMFChunkHandlers,
      pszChunkName: "entity",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::EntityChunkHandler,
      pData: *ppNewMapFile);
    CChunkFile::PushHandlers(this: &chunkFile, pHandlerMap: &VMFChunkHandlers);
    do
      v7 = CChunkFile::ReadChunk(this: &chunkFile, pfnKeyHandler: nullptr, pData: nullptr);
    while ( v7 == ChunkFile_Ok );
    CChunkFile::PopHandlers(this: &chunkFile);
    CChunkFile::Close(this: &chunkFile);
    if ( v7 == ChunkFile_EOF )
    {
      if ( (*ppNewMapFile)->m_Entities.m_Size != 0 )
      {
        v8 = 0;
        if ( (*ppNewMapFile)->m_Entities.m_Memory.m_pMemory->m_nNumBrushes > 0 )
        {
          v9 = 0;
          do
          {
            m_pMemory = (*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory;
            x = m_pMemory[v9].m_vMinBounds.x;
            p_m_vMinBounds = &m_pMemory[v9].m_vMinBounds;
            if ( x <= 16384.0 )
            {
              AddPointToBounds(
                v: p_m_vMinBounds,
                mins: &(*ppNewMapFile)->m_vMinBounds,
                maxs: &(*ppNewMapFile)->m_vMaxBounds);
              AddPointToBounds(
                v: &(*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory[v9].m_vMaxBounds,
                mins: &(*ppNewMapFile)->m_vMinBounds,
                maxs: &(*ppNewMapFile)->m_vMaxBounds);
            }
            ++v8;
            ++v9;
          }
          while ( v8 < (*ppNewMapFile)->m_Entities.m_Memory.m_pMemory->m_nNumBrushes );
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(a1: LOG_VBSP2, a2: 0, a3: "VBSP2: Done processing map file.\n");
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(
            a1: LOG_VBSP2,
            a2: 0,
            a3: "Entities: %d\nBrushes: %d\nBrush Sides: %d\nPlanes: %d\nDisplacements: %d\n");
        v13 = 0;
        if ( (*ppNewMapFile)->m_Brushes.m_Size > 0 )
        {
          v14 = (*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory;
          m_Size = (*ppNewMapFile)->m_Brushes.m_Size;
          do
          {
            if ( (v14->m_ContentsFlags & 0x8000000) != 0 )
              ++v13;
            ++v14;
            --m_Size;
          }
          while ( m_Size != 0 );
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(a1: LOG_VBSP2, a2: 0, a3: "Detail brushes: %d\nNon-detail brushes: %d\n");
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Did not successfully parse world entity.\n");
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    {
      CChunkFile::GetErrorText(this: &chunkFile, eResult: v7);
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error reading %s: %s.\n");
    }
    CChunkHandlerMap::~CChunkHandlerMap(this: &VMFChunkHandlers);
  }
  CChunkFile::~CChunkFile(this: &chunkFile);
}

//------------------------------------------------------------------------------
// Address: 0x10067B30
// Name: public: bool CSimpleMapFile::ResolveInstances(enum CSimpleMapFile::ResolveInstanceFlags_t,void (*)(void __near *,class CSimpleMapFile __near *,struct MapEntityKeyValuePair_t __near *,int),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSimpleMapFile::ResolveInstances(
        CSimpleMapFile *this,
        CSimpleMapFile::ResolveInstanceFlags_t instanceFlags,
        void (__cdecl *pPostLoadInstanceHandler)(void *, CSimpleMapFile *, MapEntityKeyValuePair_t *, int),
        void *pHandlerContext)
{
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  IBaseFileSystem *v7; // eax
  char *String; // eax
  char *v10; // esi
  MapEntity_t *v11; // eax
  int m_nNumKVPairs; // ebx
  CSimpleMapFile *v13; // ecx
  int v14; // esi
  char *v15; // eax
  const char *v16; // eax
  int v17; // ebx
  int v18; // esi
  MapEntityKeyValuePair_t *v19; // ebx
  char *v20; // eax
  char *v21; // esi
  CSimpleMapFile *v22; // esi
  unsigned int v23; // eax
  IFileSystem *m_pFileSystem; // [esp-14h] [ebp-584h]
  char gameDataFilePath[260]; // [esp+8h] [ebp-568h] BYREF
  char resolvedInstancePath[260]; // [esp+10Ch] [ebp-464h] BYREF
  char gameInfoPath[260]; // [esp+210h] [ebp-360h] BYREF
  char fixedInstanceDirectory[260]; // [esp+314h] [ebp-25Ch] BYREF
  GameData gameDataFile; // [esp+418h] [ebp-158h] BYREF
  int i; // [esp+560h] [ebp-10h]
  unsigned int v31; // [esp+564h] [ebp-Ch]
  CSimpleMapFile *pInstanceMapFile; // [esp+568h] [ebp-8h] BYREF
  const char **v33; // [esp+56Ch] [ebp-4h]

  if ( this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: "gameinfo.txt",
         a3: "MOD",
         a4: gameInfoPath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to find gameinfo.txt; required to look up InstancePath.\n");
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: gameInfoPath);
  else
    v6 = nullptr;
  if ( this->m_pFileSystem != nullptr )
    v7 = &this->m_pFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v6,
          filesystem: v7,
          resourceName: gameInfoPath,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load gameinfo.txt; required to look up InstancePath.\n");
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  String = KeyValues::GetString(this: v6, keyName: "InstancePath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    V_strncpy(pDest: fixedInstanceDirectory, pSrc: String, maxLen: 260);
    _V_strlower(start: fixedInstanceDirectory);
    V_FixSlashes(pname: fixedInstanceDirectory, separator: 92);
  }
  else
  {
    fixedInstanceDirectory[0] = 0;
  }
  v10 = KeyValues::GetString(this: v6, keyName: "GameData", defaultValue: nullptr);
  if ( v10 == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load GameData key in %s.\n");
LABEL_24:
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  if ( this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: v10,
         a3: "EXECUTABLE_PATH",
         a4: gameDataFilePath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr
    && this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: v10,
         a3: szDescription,
         a4: gameDataFilePath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Could not find GameData file %s.\n");
    goto LABEL_24;
  }
  KeyValues::deleteThis(this: v6);
  GameData::GameData(this: &gameDataFile);
  GameData::Load(this: &gameDataFile, pszFilename: gameDataFilePath);
  CSimpleMapFile::PreLoadInstances(this, pGD: &gameDataFile);
  GameData::BeginInstancing(this: &gameDataFile, nPass: 1);
  i = 0;
  if ( this->m_Entities.m_Size <= 0 )
  {
LABEL_51:
    GameData::~GameData(this: &gameDataFile);
    return 1;
  }
  v31 = 0;
  while ( 1 )
  {
    v11 = &this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C];
    m_nNumKVPairs = v11->m_nNumKVPairs;
    v13 = (CSimpleMapFile *)&this->m_KeyValuePairs.m_Memory.m_pMemory[v11->m_nFirstKVPairIndex];
    v14 = 0;
    pInstanceMapFile = v13;
    if ( m_nNumKVPairs <= 0 )
      goto LABEL_34;
    v33 = (const char **)v13;
    while ( _V_stricmp(s1: *v33, s2: "classname") != 0 )
    {
      v33 += 3;
      if ( ++v14 >= m_nNumKVPairs )
        goto LABEL_34;
    }
    v15 = (char *)pInstanceMapFile + 12 * v14;
    if ( v15 == nullptr || (v16 = *((const char **)v15 + 1)) == nullptr )
LABEL_34:
      v16 = szDescription;
    if ( _V_stricmp(s1: v16, s2: "func_instance") != 0 )
      goto LABEL_50;
    v17 = this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumKVPairs;
    v18 = 0;
    if ( v17 > 0 )
    {
      v33 = (const char **)pInstanceMapFile;
      while ( _V_stricmp(s1: *v33, s2: "file") != 0 )
      {
        v33 += 3;
        if ( ++v18 >= v17 )
          goto LABEL_49;
      }
      v19 = (MapEntityKeyValuePair_t *)pInstanceMapFile;
      v20 = (char *)pInstanceMapFile + 12 * v18;
      if ( v20 != nullptr )
      {
        v21 = *((char **)v20 + 1);
        if ( v21 != nullptr && *v21 != 0 )
          break;
      }
    }
LABEL_49:
    v23 = v31;
    this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumBrushes = 0;
    *(int *)((char *)&this->m_Entities.m_Memory.m_pMemory->m_nNumKVPairs + v23) = 0;
LABEL_50:
    v31 += 28;
    if ( ++i >= this->m_Entities.m_Size )
      goto LABEL_51;
  }
  if ( CInstancingHelper::ResolveInstancePath(
         pFileSystem: g_pFullFileSystem,
         pBaseFilename: (char *)this->m_pFilename,
         pInstanceFilename: v21,
         pInstanceDirectory: fixedInstanceDirectory,
         pResolvedInstanceFilename: resolvedInstancePath,
         nBufferSize: (const char *)0x104) != 0 )
  {
    m_pFileSystem = this->m_pFileSystem;
    pInstanceMapFile = nullptr;
    CSimpleMapFile::LoadFromFile(
      pFileSystem: m_pFileSystem,
      pVMFFilename: resolvedInstancePath,
      ppNewMapFile: &pInstanceMapFile,
      instanceFlags);
    v22 = pInstanceMapFile;
    if ( pInstanceMapFile == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load instance file %s.\n");
      goto LABEL_56;
    }
    if ( pPostLoadInstanceHandler != nullptr )
      pPostLoadInstanceHandler(
        a1: pHandlerContext,
        a2: pInstanceMapFile,
        a3: v19,
        a4: this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumKVPairs);
    CSimpleMapFile::MergeInstance(this, nEntityIndex: i, pInstanceMap: v22, pGameData: &gameDataFile);
    CSimpleMapFile::~CSimpleMapFile(this: v22);
    free(pMem: v22);
    goto LABEL_49;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Could not find instance %s.\n");
LABEL_56:
  GameData::~GameData(this: &gameDataFile);
  return 0;
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x0041B760
// Name: public: static bool CInstancingHelper::ResolveInstancePath(class IFileSystem __near *,char const __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CInstancingHelper::ResolveInstancePath(
        IFileSystem *pFileSystem,
        const char *pBaseFilename,
        const char *pInstanceFilename,
        const char *pInstanceDirectory,
        char *pResolvedInstanceFilename,
        const char *nBufferSize)
{
  IBaseFileSystem *v6; // edi
  const char *v7; // ecx
  unsigned int v9; // eax
  char *v10; // ecx
  char instanceDirectoryRelativeFilename[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char fixedInstanceFilename[260]; // [esp+110h] [ebp-108h] BYREF
  char *pMapPathPosition; // [esp+214h] [ebp-4h]

  V_strncpy(pDest: fixedInstanceFilename, pSrc: pInstanceFilename, maxLen: 260);
  V_SetExtension(path: fixedInstanceFilename, extension: ".vmf", pathStringLength: 260);
  V_FixSlashes(pname: fixedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: fixedInstanceFilename);
  V_strncpy(pDest: pResolvedInstanceFilename, pSrc: pBaseFilename, maxLen: (int)nBufferSize);
  V_StripFilename(path: pResolvedInstanceFilename);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: "\\",
    destBufferSize: (unsigned int)nBufferSize,
    max_chars_to_copy: -1);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: fixedInstanceFilename,
    destBufferSize: (unsigned int)nBufferSize,
    max_chars_to_copy: -1);
  V_RemoveDotSlashes(pFilename: pResolvedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: pResolvedInstanceFilename);
  V_FixSlashes(pname: pResolvedInstanceFilename, separator: 92);
  v6 = &pFileSystem->IBaseFileSystem;
  if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: pResolvedInstanceFilename, a3: nullptr) )
    return 1;
  pMapPathPosition = V_stristr(a1: v7, a2: nBufferSize, pStr: pResolvedInstanceFilename, pSearch: "\\maps\\");
  if ( pMapPathPosition != nullptr )
  {
    v9 = _V_strlen(str: "\\maps\\");
    v10 = &pMapPathPosition[v9];
  }
  else
  {
    if ( V_strnicmp(s1: pResolvedInstanceFilename, s2: "maps\\", n: 5) != 0 )
      goto LABEL_9;
    v10 = pResolvedInstanceFilename + 5;
  }
  if ( v10 != nullptr )
  {
    *v10 = 0;
    V_strncat(
      pDest: pResolvedInstanceFilename,
      pSrc: fixedInstanceFilename,
      destBufferSize: (unsigned int)nBufferSize,
      max_chars_to_copy: -1);
    if ( v6->FileExists(this: v6, a2: pResolvedInstanceFilename, a3: nullptr) )
      return 1;
  }
LABEL_9:
  if ( *pInstanceDirectory != 0 )
  {
    V_snprintf(
      pDest: instanceDirectoryRelativeFilename,
      maxLen: (int)nBufferSize,
      pFormat: "%s/%s",
      pInstanceDirectory,
      fixedInstanceFilename);
    V_SetExtension(path: instanceDirectoryRelativeFilename, extension: ".vmf", pathStringLength: 260);
    V_FixSlashes(pname: instanceDirectoryRelativeFilename, separator: 92);
    V_RemoveDotSlashes(pFilename: instanceDirectoryRelativeFilename, separator: 92);
    V_FixDoubleSlashes(pStr: instanceDirectoryRelativeFilename);
    pFileSystem->RelativePathToFullPath(
      this: pFileSystem,
      a2: instanceDirectoryRelativeFilename,
      a3: "GAME",
      a4: pResolvedInstanceFilename,
      a5: (int)nBufferSize,
      a6: FILTER_NONE,
      a7: nullptr);
    if ( v6->FileExists(this: v6, a2: instanceDirectoryRelativeFilename, a3: "GAME") )
      return 1;
  }
  pFileSystem->RelativePathToFullPath(
    this: pFileSystem,
    a2: fixedInstanceFilename,
    a3: "GAME",
    a4: pResolvedInstanceFilename,
    a5: (int)nBufferSize,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( v6->FileExists(this: v6, a2: fixedInstanceFilename, a3: "GAME") )
    return 1;
  if ( (int)nBufferSize > 0 )
    *pResolvedInstanceFilename = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B980
// Name: struct MapEntityKeyValuePair_t const __near * FindPair(char const __near *,struct MapEntityKeyValuePair_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const MapEntityKeyValuePair_t *__cdecl FindPair(
        const char *pKeyName,
        const MapEntityKeyValuePair_t *pPairs,
        int nNumPairs)
{
  int v3; // esi
  const MapEntityKeyValuePair_t *i; // edi

  v3 = 0;
  if ( nNumPairs <= 0 )
    return nullptr;
  for ( i = pPairs; _V_stricmp(s1: i->m_pKey, s2: pKeyName) != 0; ++i )
  {
    if ( ++v3 >= nNumPairs )
      return nullptr;
  }
  return &pPairs[v3];
}

//------------------------------------------------------------------------------
// Address: 0x0041B9D0
// Name: char const __near * GetPairValue(struct MapEntityKeyValuePair_t const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetPairValue(const MapEntityKeyValuePair_t *pPair)
{
  const char *result; // eax

  if ( pPair == nullptr )
    return defaultValue;
  result = pPair->m_pValue;
  if ( result == nullptr )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B9F0
// Name: public: struct MapBrushTexture_t __near & MapBrushTexture_t::operator=(struct MapBrushTexture_t const __near &)
// Source: json
//------------------------------------------------------------------------------
MapBrushTexture_t *__thiscall MapBrushTexture_t::operator=(MapBrushTexture_t *this, const MapBrushTexture_t *__that)
{
  MapBrushTexture_t *result; // eax
  char *m_MaterialName; // esi
  int v4; // edx

  result = this;
  this->m_vUAxis = __that->m_vUAxis;
  m_MaterialName = this->m_MaterialName;
  v4 = 128;
  this->m_vVAxis = __that->m_vVAxis;
  *(_QWORD *)this->m_flShift = *(_QWORD *)__that->m_flShift;
  *(_QWORD *)this->m_flTextureWorldUnitsPerTexel = *(_QWORD *)__that->m_flTextureWorldUnitsPerTexel;
  this->m_flLightmapWorldUnitsPerLuxel = __that->m_flLightmapWorldUnitsPerLuxel;
  do
  {
    *m_MaterialName = m_MaterialName[(char *)__that - (char *)this];
    ++m_MaterialName;
    --v4;
  }
  while ( v4 != 0 );
  this->m_SurfaceFlags = __that->m_SurfaceFlags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA80
// Name: private: void CSimpleMapFile::FixupInstanceKeyValuePair(struct MapEntityKeyValuePair_t __near *,char const __near *,struct MapEntityKeyValuePair_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::FixupInstanceKeyValuePair(
        CSimpleMapFile *this,
        MapEntityKeyValuePair_t *pNewKeyValuePair,
        const char *pOriginalValue,
        const MapEntityKeyValuePair_t *pInstancePairs,
        int nNumPairs)
{
  int i; // ebx
  unsigned int v7; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // esi
  char tempCopy[1024]; // [esp+4h] [ebp-C04h] BYREF
  char replaceValue[1024]; // [esp+404h] [ebp-804h] BYREF
  char newValue[1024]; // [esp+804h] [ebp-404h] BYREF
  CSimpleMapFile *v13; // [esp+C04h] [ebp-4h]

  v13 = this;
  V_strncpy(pDest: newValue, pSrc: pOriginalValue, maxLen: 1024);
  for ( i = 0; i < nNumPairs; ++pInstancePairs )
  {
    v7 = _V_strlen(str: "replace");
    if ( V_strnicmp(s1: pInstancePairs->m_pKey, s2: "replace", n: v7) == 0 )
    {
      V_strncpy(pDest: replaceValue, pSrc: pInstancePairs->m_pValue, maxLen: 1024);
      strchr(string: (unsigned __int8 *)replaceValue, chr: 0x20u);
      v9 = v8;
      if ( v8 != nullptr )
      {
        *v8 = 0;
        V_strncpy(pDest: tempCopy, pSrc: newValue, maxLen: 1024);
        if ( !V_StrSubst(
                pIn: tempCopy,
                pMatch: replaceValue,
                pReplaceWith: v9 + 1,
                pOut: newValue,
                outLen: 1024,
                bCaseSensitive: false) )
          break;
      }
    }
    ++i;
  }
  pNewKeyValuePair->m_pValue = CStringPool::Allocate(this: &v13->m_KeyValueStringPool, pszValue: newValue);
}

//------------------------------------------------------------------------------
// Address: 0x0041BB80
// Name: StringIsTrue
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall StringIsTrue@<eax>(const char *str@<esi>)
{
  return V_strcasecmp(s1: str, s2: "true") == 0 || V_strcasecmp(s1: str, s2: "1") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041BBB0
// Name: public: void CUtlMemory<struct CMapDisplacement::Vertex_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMapDisplacement::Vertex_t,int>::Grow(
        CUtlMemory<CMapDisplacement::Vertex_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMapDisplacement::Vertex_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMapDisplacement::Vertex_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CMapDisplacement::Vertex_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BC50
// Name: private: void CSimpleMapFile::ReportParseError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::ReportParseError(CSimpleMapFile *this, const char *pErrorString)
{
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 3,
      a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
      pErrorString,
      this->m_Entities.m_Size - 1,
      this->m_Brushes.m_Size - 1,
      this->m_BrushSides.m_Size - 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041C080
// Name: public: void CUtlMemory<struct CSimpleMapFile::MaterialInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSimpleMapFile::MaterialInfo_t,int>::Grow(
        CUtlMemory<CSimpleMapFile::MaterialInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSimpleMapFile::MaterialInfo_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 136 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSimpleMapFile::MaterialInfo_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CSimpleMapFile::MaterialInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C120
// Name: private: int CSimpleMapFile::ComputeBrushContents(struct MapBrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSimpleMapFile::ComputeBrushContents(CSimpleMapFile *this, MapBrush_t *pBrush)
{
  int m_nNumSides; // esi
  MapBrushSide_t *v3; // edx
  int v4; // ecx
  unsigned int result; // eax

  m_nNumSides = pBrush->m_nNumSides;
  v3 = &this->m_BrushSides.m_Memory.m_pMemory[pBrush->m_nFirstSideIndex];
  v4 = 0;
  result = v3->m_ContentsFlags;
  if ( m_nNumSides > 0 )
  {
    do
    {
      v4 |= v3->m_ContentsFlags;
      ++v3;
      --m_nNumSides;
    }
    while ( m_nNumSides != 0 );
  }
  if ( (v4 & 0x3A) != 0 )
    result = v4 & 0x3A | result & 0xEFFFFFFE | 0x10000000;
  if ( (v4 & 0x20000000) != 0 )
    result |= 0x20000000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C170
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementNormalsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementNormalsKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  CSimpleMapFile *v4; // esi
  int v6; // esi
  int v7; // edi
  const char *v8; // ebx
  int v9; // eax
  int v10; // edi
  HashedPlane_t *m_pElements; // esi
  HashedPlane_t *v12; // esi
  HashedPlane_t *v13; // esi
  char *v14; // eax
  char valueBuf[1024]; // [esp+8h] [ebp-414h] BYREF
  int nRow; // [esp+408h] [ebp-14h]
  int nColumns; // [esp+40Ch] [ebp-10h]
  char *pVal1; // [esp+410h] [ebp-Ch]
  char *pVal2; // [esp+414h] [ebp-8h]
  int nIndex; // [esp+418h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) == 0 )
    {
      V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
      nColumns = (1 << (int)pData[1]->m_pFileSystem) + 1;
      v6 = nColumns;
      v7 = atoi(nptr: pKey + 3);
      nRow = v7;
      if ( v7 >= v6 )
      {
        CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement normals.");
        return 1;
      }
      v8 = strtok(string: valueBuf, control: " ");
      pVal1 = strtok(string: nullptr, control: " ");
      pVal2 = strtok(string: nullptr, control: " ");
      v9 = v6 * v7;
      nIndex = v6 * v7;
      if ( v8 != nullptr )
      {
        v10 = 4 * v9;
        while ( pVal1 != nullptr && pVal2 != nullptr )
        {
          if ( v9 >= v6 * (nRow + 1) )
          {
            CSimpleMapFile::ReportParseError(
              this: *pData,
              pErrorString: "Too many elements in displacement normal row.");
            return 1;
          }
          m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          m_pElements[v10].m_vNormal.z = atof(nptr: v8);
          v12 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v12[v10].m_flDistance = atof(nptr: pVal1);
          v13 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          *(float *)&v13[v10].m_Type = atof(nptr: pVal2);
          v8 = strtok(string: nullptr, control: " ");
          pVal1 = strtok(string: nullptr, control: " ");
          v14 = strtok(string: nullptr, control: " ");
          ++nIndex;
          v10 += 4;
          pVal2 = v14;
          if ( v8 == nullptr )
            return 0;
          v6 = nColumns;
          v9 = nIndex;
        }
      }
    }
    return 0;
  }
  else
  {
    v4 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Vertices for displacement not allocated.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C360
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementDistancesKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementDistancesKeyHandler(
        const char *pKey,
        const char *pValue,
        CSimpleMapFile **pData)
{
  int *v3; // eax
  CSimpleMapFile *v4; // esi
  int v6; // ebx
  int v7; // esi
  const char *v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // ebx
  HashedPlane_t *m_pElements; // esi
  char valueBuf[1024]; // [esp+8h] [ebp-404h] BYREF
  int v14; // [esp+408h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v6 = (1 << (int)pData[1]->m_pFileSystem) + 1;
    v7 = atoi(nptr: pKey + 3);
    if ( v7 >= v6 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement distances.");
      return 1;
    }
    v8 = strtok(string: valueBuf, control: " ");
    v9 = v6 * v7;
    if ( v8 == nullptr )
    {
      return 0;
    }
    else
    {
      v10 = v6 * (v7 + 1);
      v14 = v10;
      v11 = 4 * v9;
      while ( v9 < v10 )
      {
        m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
        m_pElements[v11].m_vNormal.y = atof(nptr: v8);
        v8 = strtok(string: nullptr, control: " ");
        ++v9;
        v11 += 4;
        if ( v8 == nullptr )
          return 0;
        v10 = v14;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many elements in displacement distance row.");
      return 1;
    }
  }
  else
  {
    v4 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Vertices for displacement not allocated.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C4C0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementOffsetsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementOffsetsKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  CSimpleMapFile *v4; // esi
  int v6; // esi
  int v7; // edi
  const char *v8; // ebx
  int v9; // eax
  int v10; // edi
  HashedPlane_t *m_pElements; // esi
  HashedPlane_t *v12; // esi
  HashedPlane_t *v13; // esi
  char *v14; // eax
  char valueBuf[1024]; // [esp+8h] [ebp-414h] BYREF
  int nRow; // [esp+408h] [ebp-14h]
  int nColumns; // [esp+40Ch] [ebp-10h]
  char *pVal1; // [esp+410h] [ebp-Ch]
  char *pVal2; // [esp+414h] [ebp-8h]
  int nIndex; // [esp+418h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) == 0 )
    {
      V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
      nColumns = (1 << (int)pData[1]->m_pFileSystem) + 1;
      v6 = nColumns;
      v7 = atoi(nptr: pKey + 3);
      nRow = v7;
      if ( v7 >= v6 )
      {
        CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement offsets.");
        return 1;
      }
      v8 = strtok(string: valueBuf, control: " ");
      pVal1 = strtok(string: nullptr, control: " ");
      pVal2 = strtok(string: nullptr, control: " ");
      v9 = v6 * v7;
      nIndex = v6 * v7;
      if ( v8 != nullptr )
      {
        v10 = 4 * v9;
        while ( pVal1 != nullptr && pVal2 != nullptr )
        {
          if ( v9 >= v6 * (nRow + 1) )
          {
            CSimpleMapFile::ReportParseError(
              this: *pData,
              pErrorString: "Too many elements in displacement offset row.");
            return 1;
          }
          m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          *(float *)&m_pElements[v10].m_nNextPlaneIndex = atof(nptr: v8);
          v12 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v12[v10 + 1].m_vNormal.x = atof(nptr: pVal1);
          v13 = pData[1]->m_PlaneHash.m_Planes.m_pElements;
          v13[v10 + 1].m_vNormal.y = atof(nptr: pVal2);
          v8 = strtok(string: nullptr, control: " ");
          pVal1 = strtok(string: nullptr, control: " ");
          v14 = strtok(string: nullptr, control: " ");
          ++nIndex;
          v10 += 4;
          pVal2 = v14;
          if ( v8 == nullptr )
            return 0;
          v6 = nColumns;
          v9 = nIndex;
        }
      }
    }
    return 0;
  }
  else
  {
    v4 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Vertices for displacement not allocated.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C6B0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementAlphasKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementAlphasKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  int *v3; // eax
  CSimpleMapFile *v4; // esi
  int v6; // ebx
  int v7; // esi
  const char *v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // ebx
  HashedPlane_t *m_pElements; // esi
  char valueBuf[1024]; // [esp+8h] [ebp-404h] BYREF
  int v14; // [esp+408h] [ebp-4h]

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v6 = (1 << (int)pData[1]->m_pFileSystem) + 1;
    v7 = atoi(nptr: pKey + 3);
    if ( v7 >= v6 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement alpha.");
      return 1;
    }
    v8 = strtok(string: valueBuf, control: " ");
    v9 = v6 * v7;
    if ( v8 == nullptr )
    {
      return 0;
    }
    else
    {
      v10 = v6 * (v7 + 1);
      v14 = v10;
      v11 = 4 * v9;
      while ( v9 < v10 )
      {
        m_pElements = pData[1]->m_PlaneHash.m_Planes.m_pElements;
        m_pElements[v11].m_vNormal.x = atof(nptr: v8);
        v8 = strtok(string: nullptr, control: " ");
        ++v9;
        v11 += 4;
        if ( v8 == nullptr )
          return 0;
        v10 = v14;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many elements in displacement alpha row.");
      return 1;
    }
  }
  else
  {
    v4 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Vertices for displacement not allocated.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C810
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementTriangleTagsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementTriangleTagsKeyHandler(
        const char *pKey,
        const char *pValue,
        CSimpleMapFile **pData)
{
  int *v3; // eax
  CSimpleMapFile *v4; // esi
  int v6; // edi
  int v7; // ebx
  const char *v8; // eax
  int v9; // esi
  int v10; // ebx
  char v11; // al
  char v12; // cl
  bool v13; // dl
  __int16 v14; // ax
  char valueBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  v3 = (int *)pData[1];
  if ( v3[10] > 0 && *v3 > 0 )
  {
    if ( V_strnicmp(s1: pKey, s2: "row", n: 3) != 0 )
      return 0;
    V_strncpy(pDest: valueBuf, pSrc: pValue, maxLen: 1024);
    v6 = 1 << (int)pData[1]->m_pFileSystem;
    v7 = atoi(nptr: pKey + 3);
    if ( v7 >= v6 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Too many rows for displacement triangle tags.");
      return 1;
    }
    v8 = strtok(string: valueBuf, control: " ");
    v9 = 2 * v6 * v7;
    if ( v8 == nullptr )
    {
      return 0;
    }
    else
    {
      v10 = 2 * v6 * (v7 + 1);
      while ( v9 < v10 )
      {
        v11 = atoi(nptr: v8);
        v12 = v11 & 1;
        if ( (v11 & 2) != 0 )
          v12 = (v11 & 4) != 0;
        v13 = (v11 & 8) != 0;
        if ( (v11 & 0x10) != 0 )
          v13 = (v11 & 0x20) != 0;
        v14 = 0;
        if ( v12 != 0 )
          v14 = 2;
        if ( v13 )
          v14 |= 4u;
        *(_WORD *)(pData[1]->m_PlaneHash.m_HashTable[4] + 2 * v9) = v14;
        v8 = strtok(string: nullptr, control: " ");
        ++v9;
        if ( v8 == nullptr )
          return 0;
      }
      CSimpleMapFile::ReportParseError(
        this: *pData,
        pErrorString: "Too many elements in displacement triangle tags row.");
      return 1;
    }
  }
  else
  {
    v4 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Vertices for displacement not allocated.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C9A0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendKeyHandler(
        const char *pKey,
        const char *pValue,
        _DWORD **pData)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  int v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vMultiBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: pKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, pValue);
  v3 = (1 << *pData[1]) + 1;
  v4 = atoi(nptr: pKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = 96 * v6;
    do
    {
      vMultiBlend.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlend.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlend.z = atof(nptr: v9);
      v10 = strtok(string: nullptr, control: " ");
      vMultiBlend.w = atof(nptr: v10);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector4D *)(pData[1][7] + v7 + 32) = vMultiBlend;
      v7 += 96;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041CAB0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColorKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColorKeyHandler(
        const char *pKey,
        const char *pValue,
        _DWORD **pData)
{
  int v3; // edi
  int v4; // ebx
  const char *v5; // eax
  int v6; // ebx
  int v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  char szBuf[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vMultiBlendColor; // [esp+404h] [ebp-Ch]

  if ( V_strncasecmp(s1: pKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, pValue);
  v3 = (1 << *pData[1]) + 1;
  v4 = atoi(nptr: pKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = 2 * v6;
    do
    {
      vMultiBlendColor.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.z = atof(nptr: v9);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector *)(pData[1][7] + 12 * (_DWORD)&pData[2][v7 + 1]) = vMultiBlendColor;
      v7 += 2;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041CBB0
// Name: private: void CSimpleMapFile::MakeBrushPolygons(struct MapBrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MakeBrushPolygons(CSimpleMapFile *this, int pBrush)
{
  MapBrushSide_t *v4; // eax
  HashedPlane_t *v5; // ecx
  Polygon_t *p_m_Polygon; // esi
  int v7; // eax
  int v8; // eax
  Vector *v9; // eax
  bool v10; // zf
  int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]
  int ja; // [esp+18h] [ebp-4h]
  int i; // [esp+24h] [ebp+8h]
  Vector *ia; // [esp+24h] [ebp+8h]

  ClearBounds(mins: (Vector *)(pBrush + 12), maxs: (Vector *)(pBrush + 24));
  for ( i = 0; i < *(_DWORD *)(pBrush + 8); ++i )
  {
    v4 = &this->m_BrushSides.m_Memory.m_pMemory[i + *(_DWORD *)(pBrush + 4)];
    v5 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v4->m_nPlaneIndex];
    p_m_Polygon = &v4->m_Polygon;
    v4->m_Polygon.m_Points.m_Size = 0;
    CreatePolygonFromPlane(vNormal: &v5->m_vNormal, flDistance: v5->m_flDistance, pPolygon: &v4->m_Polygon);
    v7 = 0;
    for ( j = 0; v7 < *(_DWORD *)(pBrush + 8); j = v7 )
    {
      if ( i != v7 )
      {
        v8 = this->m_BrushSides.m_Memory.m_pMemory[v7 + *(_DWORD *)(pBrush + 4)].m_nPlaneIndex ^ 1;
        ChopPolygonInPlace(
          pPolygon: p_m_Polygon,
          vNormal: &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v8].m_vNormal,
          flDistance: this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v8].m_flDistance);
        v7 = j;
      }
      ++v7;
    }
    v11 = 0;
    if ( p_m_Polygon->m_Points.m_Size > 0 )
    {
      ja = 0;
      do
      {
        AddPointToBounds(
          v: &p_m_Polygon->m_Points.m_Memory.m_pMemory[ja++],
          mins: (Vector *)(pBrush + 12),
          maxs: (Vector *)(pBrush + 24));
        ++v11;
      }
      while ( v11 < p_m_Polygon->m_Points.m_Size );
    }
  }
  v9 = (Vector *)(pBrush + 24);
  ia = (Vector *)(pBrush + 24);
  v12 = 3;
  do
  {
    if ( v9[-1].x < -16384.0 || v9->x > 16384.0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_VBSP2,
          a2: 1,
          a3: "Brush %d: bounds out of range.\n",
          (signed int)(pBrush - (unsigned int)this->m_Brushes.m_Memory.m_pMemory) / 36);
      v9 = ia;
    }
    if ( v9[-1].x > 16384.0 || v9->x < -16384.0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_VBSP2,
          a2: 1,
          a3: "Brush %d: no visible sides on brush.\n",
          (signed int)(pBrush - (unsigned int)this->m_Brushes.m_Memory.m_pMemory) / 36);
      v9 = ia;
    }
    v9 = (Vector *)((char *)v9 + 4);
    v10 = v12-- == 1;
    ia = v9;
  }
  while ( !v10 );
}

//------------------------------------------------------------------------------
// Address: 0x0041CDA0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementNormalsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementNormalsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementNormalsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CDC0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementDistancesChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementDistancesChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementDistancesKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CDE0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementOffsetsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementOffsetsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementOffsetsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE00
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementAlphasChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementAlphasChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementAlphasKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE20
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementTriangleTagsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementTriangleTagsChunkHandler(CChunkFile *pFile, void *pData)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementTriangleTagsKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE40
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendChunkHandler(CChunkFile *pFile, _DWORD *pData)
{
  *(_DWORD *)(pData[1] + 8) |= 0x40000000u;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE60
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor0(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor0(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE80
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor1(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor1(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 1;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CEA0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor2(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor2(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 2;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041CEC0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementMultiBlendColor3(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DisplacementMultiBlendColor3(CChunkFile *pFile, _DWORD *pData)
{
  pData[2] = 3;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementMultiBlendColorKeyHandler,
           pData);
}

//------------------------------------------------------------------------------
// Address: 0x0041D0A0
// Name: private: struct MapEntity_t __near * CSimpleMapFile::AllocateNewEntity(void)
// Source: json
//------------------------------------------------------------------------------
MapEntity_t *__thiscall CSimpleMapFile::AllocateNewEntity(CSimpleMapFile *this)
{
  CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int> > *p_m_Entities; // esi
  int v3; // eax

  p_m_Entities = &this->m_Entities;
  CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int>>::InsertBefore(
    this: &this->m_Entities,
    elem: this->m_Entities.m_Size);
  v3 = (int)&p_m_Entities->m_Memory.m_pMemory[this->m_Entities.m_Size - 1];
  *(_QWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0;
  *(_QWORD *)(v3 + 16) = 0;
  *(_DWORD *)(v3 + 24) = 0;
  return &p_m_Entities->m_Memory.m_pMemory[this->m_Entities.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x0041D100
// Name: private: struct MapBrush_t __near * CSimpleMapFile::AllocateNewBrush(void)
// Source: json
//------------------------------------------------------------------------------
MapBrush_t *__thiscall CSimpleMapFile::AllocateNewBrush(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapBrush_t *m_pMemory; // ecx
  int v5; // eax
  MapBrush_t *v6; // eax

  m_nAllocationCount = this->m_Brushes.m_Memory.m_nAllocationCount;
  m_Size = this->m_Brushes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(
      this: &this->m_Brushes.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Brushes.m_Size;
  m_pMemory = this->m_Brushes.m_Memory.m_pMemory;
  v5 = this->m_Brushes.m_Size - m_Size - 1;
  this->m_Brushes.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 36 * v5);
  v6 = &this->m_Brushes.m_Memory.m_pMemory[this->m_Brushes.m_Size - 1];
  *(_QWORD *)&v6->m_ContentsFlags = 0;
  *(_QWORD *)&v6->m_nNumSides = 0;
  *(_QWORD *)&v6->m_vMinBounds.y = 0;
  *(_QWORD *)&v6->m_vMaxBounds.x = 0;
  v6->m_vMaxBounds.z = 0.0;
  return &this->m_Brushes.m_Memory.m_pMemory[this->m_Brushes.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x0041D1B0
// Name: private: struct MapBrushTexture_t __near * CSimpleMapFile::AllocateNewBrushTexture(void)
// Source: json
//------------------------------------------------------------------------------
MapBrushTexture_t *__thiscall CSimpleMapFile::AllocateNewBrushTexture(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapBrushTexture_t *m_pMemory; // ecx
  int v5; // eax
  unsigned __int8 *v6; // esi

  m_nAllocationCount = this->m_BrushTextures.m_Memory.m_nAllocationCount;
  m_Size = this->m_BrushTextures.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapBrushTexture_t,int>::Grow(this: &this->m_BrushTextures.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_BrushTextures.m_Size;
  m_pMemory = this->m_BrushTextures.m_Memory.m_pMemory;
  v5 = this->m_BrushTextures.m_Size - m_Size - 1;
  this->m_BrushTextures.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 176 * v5);
  v6 = (unsigned __int8 *)&this->m_BrushTextures.m_Memory.m_pMemory[this->m_BrushTextures.m_Size - 1];
  memset(dst: v6, value: 0, count: 0xB0u);
  return (MapBrushTexture_t *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x0041D250
// Name: private: struct MapEntityKeyValuePair_t __near * CSimpleMapFile::AllocateNewKeyValuePair(void)
// Source: json
//------------------------------------------------------------------------------
MapEntityKeyValuePair_t *__thiscall CSimpleMapFile::AllocateNewKeyValuePair(CSimpleMapFile *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MapEntityKeyValuePair_t *m_pMemory; // ecx
  int v5; // eax
  MapEntityKeyValuePair_t *result; // eax

  m_nAllocationCount = this->m_KeyValuePairs.m_Memory.m_nAllocationCount;
  m_Size = this->m_KeyValuePairs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(this: &this->m_KeyValuePairs.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_KeyValuePairs.m_Size;
  m_pMemory = this->m_KeyValuePairs.m_Memory.m_pMemory;
  v5 = this->m_KeyValuePairs.m_Size - m_Size - 1;
  this->m_KeyValuePairs.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  result = &this->m_KeyValuePairs.m_Memory.m_pMemory[this->m_KeyValuePairs.m_Size - 1];
  *(_QWORD *)&result->m_pKey = 0;
  *(_DWORD *)&result->m_bIsConnection = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041D2E0
// Name: private: void CSimpleMapFile::MoveEntityBrushesToWorld(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MoveEntityBrushesToWorld(CSimpleMapFile *this, int nEntityIndex)
{
  MapEntity_t *m_pMemory; // eax
  int m_nNumBrushes; // ebx
  MapEntity_t *v5; // ecx
  MapBrush_t *v6; // edx
  int v7; // edi
  MapBrush_t *v8; // ebx
  int v9; // ecx
  MapEntity_t *v10; // eax
  int m_nFirstBrushIndex; // edx
  MapEntity_t *v12; // eax
  const MapBrush_t *v13; // [esp-4h] [ebp-28h]
  CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int> > tempMapBrushes; // [esp+Ch] [ebp-18h] BYREF
  MapEntity_t *pEntity; // [esp+20h] [ebp-4h]
  int nEntityIndexb; // [esp+2Ch] [ebp+8h]
  int nEntityIndexa; // [esp+2Ch] [ebp+8h]

  m_pMemory = this->m_Entities.m_Memory.m_pMemory;
  m_nNumBrushes = m_pMemory->m_nNumBrushes;
  v5 = &m_pMemory[nEntityIndex];
  v6 = this->m_Brushes.m_Memory.m_pMemory;
  v7 = v5->m_nNumBrushes;
  pEntity = v5;
  v13 = &v6[v5->m_nFirstBrushIndex];
  memset(&tempMapBrushes, 0, sizeof(tempMapBrushes));
  CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int>>::InsertMultipleBefore(
    this: &tempMapBrushes,
    elem: 0,
    num: v7,
    pToInsert: v13);
  nEntityIndexb = m_nNumBrushes;
  memmove(
    dst: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[v7 + m_nNumBrushes],
    src: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[m_nNumBrushes],
    count: 36 * (pEntity->m_nFirstBrushIndex - m_nNumBrushes));
  v8 = tempMapBrushes.m_Memory.m_pMemory;
  memcpy(
    dst: (unsigned __int8 *)&this->m_Brushes.m_Memory.m_pMemory[nEntityIndexb],
    src: (unsigned __int8 *)tempMapBrushes.m_Memory.m_pMemory,
    count: 36 * v7);
  v9 = 1;
  if ( this->m_Entities.m_Size > 1 )
  {
    nEntityIndexa = 1;
    do
    {
      v10 = &this->m_Entities.m_Memory.m_pMemory[nEntityIndexa];
      m_nFirstBrushIndex = v10->m_nFirstBrushIndex;
      if ( m_nFirstBrushIndex < pEntity->m_nFirstBrushIndex )
        v10->m_nFirstBrushIndex = v7 + m_nFirstBrushIndex;
      ++nEntityIndexa;
      ++v9;
    }
    while ( v9 < this->m_Entities.m_Size );
    v8 = tempMapBrushes.m_Memory.m_pMemory;
  }
  this->m_Entities.m_Memory.m_pMemory->m_nNumBrushes += v7;
  v12 = pEntity;
  pEntity->m_nNumBrushes = 0;
  v12->m_nNumKVPairs = 0;
  if ( tempMapBrushes.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x0041D400
// Name: private: int CSimpleMapFile::FindOrCreateTextureData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::FindOrCreateTextureData(CSimpleMapFile *this, const char *pTextureName)
{
  int v3; // esi
  int v4; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapTextureData_t *m_pMemory; // ecx
  int v8; // eax
  MapTextureData_t *v9; // esi
  void *Material; // ebx
  bool found; // [esp+Fh] [ebp-1h] BYREF

  v3 = 0;
  if ( this->m_TextureData.m_Size <= 0 )
  {
LABEL_5:
    m_Size = this->m_TextureData.m_Size;
    m_nAllocationCount = this->m_TextureData.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<MapTextureData_t,int>::Grow(this: &this->m_TextureData.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_TextureData.m_Size;
    m_pMemory = this->m_TextureData.m_Memory.m_pMemory;
    v8 = this->m_TextureData.m_Size - m_Size - 1;
    this->m_TextureData.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 148 * v8);
    v9 = &this->m_TextureData.m_Memory.m_pMemory[this->m_TextureData.m_Size - 1];
    memset(dst: (unsigned __int8 *)v9, value: 0, count: sizeof(MapTextureData_t));
    _V_strcpy(dest: v9->m_MaterialName, src: pTextureName);
    Material = FindMaterial(materialName: pTextureName, pFound: &found, bComplain: true);
    if ( Material != nullptr )
    {
      GetMaterialDimensions(materialHandle: Material, width: &v9->m_nWidth, height: &v9->m_nHeight);
      GetMaterialReflectivity(materialHandle: Material, reflectivityVect: &v9->m_vReflectivity.x);
    }
    else
    {
      v9->m_nHeight = 0;
      v9->m_nWidth = 0;
      v9->m_vReflectivity = vec3_origin;
    }
    return this->m_TextureData.m_Size - 1;
  }
  else
  {
    v4 = 0;
    while ( _V_stricmp(s1: pTextureName, s2: this->m_TextureData.m_Memory.m_pMemory[v4].m_MaterialName) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->m_TextureData.m_Size )
        goto LABEL_5;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D560
// Name: private: int CSimpleMapFile::FindOrCreateTextureInfo(struct MapTextureInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::FindOrCreateTextureInfo(CSimpleMapFile *this, MapTextureInfo_t *textureInfo)
{
  int v3; // esi
  int v4; // edi
  MapTextureInfo_t *v5; // eax
  int m_nTextureDataIndex; // edx
  _DWORD *v7; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  MapTextureInfo_t *m_pMemory; // ecx
  int v11; // eax
  MapTextureInfo_t *v12; // edi

  v3 = 0;
  if ( this->m_TextureInfos.m_Size <= 0 )
  {
LABEL_6:
    m_Size = this->m_TextureInfos.m_Size;
    m_nAllocationCount = this->m_TextureInfos.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<StaticPropLump_t,int>::Grow(this: &this->m_TextureInfos.m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++this->m_TextureInfos.m_Size;
    m_pMemory = this->m_TextureInfos.m_Memory.m_pMemory;
    v11 = this->m_TextureInfos.m_Size - m_Size - 1;
    this->m_TextureInfos.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 72 * v11);
    v12 = &this->m_TextureInfos.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      qmemcpy(v12, textureInfo, sizeof(MapTextureInfo_t));
    return this->m_TextureInfos.m_Size - 1;
  }
  else
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = this->m_TextureInfos.m_Memory.m_pMemory;
      m_nTextureDataIndex = v5[v4].m_nTextureDataIndex;
      v7 = (_DWORD *)v5[v4].m_flTextureVectors[0];
      if ( m_nTextureDataIndex == textureInfo->m_nTextureDataIndex
        && _V_memcmp(m1: v7, m2: textureInfo, count: 0x48u) == 0 )
      {
        return v3;
      }
      ++v3;
      ++v4;
      if ( v3 >= this->m_TextureInfos.m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D650
// Name: private: void CSimpleMapFile::PreLoadInstances(class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::PreLoadInstances(CSimpleMapFile *this, GameData *pGD)
{
  CSimpleMapFile *v2; // esi
  MapEntity_t *v3; // ebx
  int m_nNumKVPairs; // edi
  MapEntityKeyValuePair_t *v5; // eax
  int v6; // esi
  MapEntityKeyValuePair_t *v7; // eax
  const char *m_pValue; // eax
  GDclass *v9; // eax
  bool v10; // cc
  GDinputvariable *VariableAt; // eax
  int v12; // edi
  int v13; // esi
  MapEntityKeyValuePair_t *v14; // ebx
  MapEntityKeyValuePair_t *NewKeyValuePair; // esi
  char *v16; // eax
  char *m_szName; // edi
  char remappedValue[1024]; // [esp+8h] [ebp-4B8h] BYREF
  char NameFixup[128]; // [esp+408h] [ebp-B8h] BYREF
  Vector InstanceOrigin; // [esp+488h] [ebp-38h] BYREF
  QAngle InstanceAngle; // [esp+494h] [ebp-2Ch] BYREF
  int i; // [esp+4A0h] [ebp-20h]
  GDclass *pEntClass; // [esp+4A4h] [ebp-1Ch]
  GDinputvariable *pEntityGDVariable; // [esp+4A8h] [ebp-18h]
  unsigned int v25; // [esp+4ACh] [ebp-14h]
  MapEntity_t *pEntity; // [esp+4B0h] [ebp-10h]
  MapEntityKeyValuePair_t *pEntityPairs; // [esp+4B4h] [ebp-Ch]
  CSimpleMapFile *v28; // [esp+4B8h] [ebp-8h]
  int iIndex; // [esp+4BCh] [ebp-4h]

  v2 = this;
  v28 = this;
  memset(NameFixup, 0, sizeof(NameFixup));
  InstanceOrigin = vec3_origin;
  InstanceAngle = vec3_angle;
  GameData::BeginInstancing(this: pGD, nPass: 2);
  i = 0;
  if ( v2->m_Entities.m_Size > 0 )
  {
    v25 = 0;
    while ( 1 )
    {
      v3 = &v2->m_Entities.m_Memory.m_pMemory[v25 / 0x1C];
      m_nNumKVPairs = v3->m_nNumKVPairs;
      v5 = &v2->m_KeyValuePairs.m_Memory.m_pMemory[v3->m_nFirstKVPairIndex];
      v6 = 0;
      pEntity = v3;
      pEntityPairs = v5;
      if ( m_nNumKVPairs <= 0 )
        goto LABEL_11;
      iIndex = (int)v5;
      while ( _V_stricmp(s1: *(const char **)iIndex, s2: "classname") != 0 )
      {
        iIndex += 12;
        if ( ++v6 >= m_nNumKVPairs )
          goto LABEL_11;
      }
      v7 = &pEntityPairs[v6];
      if ( v7 == nullptr || (m_pValue = v7->m_pValue) == nullptr )
LABEL_11:
        m_pValue = defaultValue;
      v9 = GameData::BeginInstanceRemap(
             this: pGD,
             pszClassName: m_pValue,
             pszInstancePrefix: NameFixup,
             Origin: &InstanceOrigin,
             Angle: &InstanceAngle);
      pEntClass = v9;
      if ( v9 != nullptr )
      {
        v10 = v9->m_nVariables <= 0;
        iIndex = 0;
        if ( !v10 )
          break;
      }
LABEL_32:
      v25 += 28;
      if ( ++i >= v28->m_Entities.m_Size )
        return;
      v2 = v28;
    }
    while ( 1 )
    {
      VariableAt = GDclass::GetVariableAt(this: v9, iIndex);
      v12 = v3->m_nNumKVPairs;
      v13 = 0;
      pEntityGDVariable = VariableAt;
      if ( v12 <= 0 )
      {
LABEL_21:
        NewKeyValuePair = nullptr;
      }
      else
      {
        v14 = pEntityPairs;
        while ( _V_stricmp(s1: v14->m_pKey, s2: pEntityGDVariable->m_szName) != 0 )
        {
          ++v13;
          ++v14;
          if ( v13 >= v12 )
          {
            v3 = pEntity;
            goto LABEL_21;
          }
        }
        NewKeyValuePair = &pEntityPairs[v13];
        if ( NewKeyValuePair != nullptr )
        {
          v16 = (char *)NewKeyValuePair->m_pValue;
          if ( v16 != nullptr )
          {
            v3 = pEntity;
            goto LABEL_27;
          }
        }
        v3 = pEntity;
      }
      v16 = (char *)defaultValue;
LABEL_27:
      m_szName = pEntityGDVariable->m_szName;
      if ( GameData::RemapKeyValue(
             this: pGD,
             pszKey: pEntityGDVariable->m_szName,
             pszInValue: v16,
             pszOutValue: remappedValue,
             NameFixup: NAME_FIXUP_NONE) )
      {
        if ( NewKeyValuePair == nullptr )
        {
          NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: v28);
          NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &v28->m_KeyValueStringPool, pszValue: m_szName);
          ++v3->m_nNumKVPairs;
        }
        NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &v28->m_KeyValueStringPool, pszValue: remappedValue);
      }
      if ( ++iIndex >= pEntClass->m_nVariables )
        goto LABEL_32;
      v9 = pEntClass;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D870
// Name: private: void CSimpleMapFile::MergeBrushes(int,class CSimpleMapFile const __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeBrushes(
        CSimpleMapFile *this,
        int nEntityIndex,
        const CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        const matrix3x4_t *transform)
{
  CSimpleMapFile *v7; // ebx
  MapBrush_t *NewBrush; // eax
  int v9; // ebx
  int i; // [esp+Ch] [ebp-4h]
  const CSimpleMapFile *pInstanceMapa; // [esp+1Ch] [ebp+Ch]

  v7 = this;
  i = 0;
  if ( pInstanceMap->m_Brushes.m_Size > 0 )
  {
    pInstanceMapa = nullptr;
    while ( 1 )
    {
      NewBrush = CSimpleMapFile::AllocateNewBrush(this: v7);
      *NewBrush = *(MapBrush_t *)((char *)&pInstanceMapa->m_pFileSystem
                                + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory);
      NewBrush->m_nFirstSideIndex += v7->m_BrushSides.m_Size;
      v9 = i;
      if ( i < pInstanceMap->m_Entities.m_Memory.m_pMemory->m_nNumBrushes
        || (NewBrush->m_ContentsFlags & 0x20000000) != 0 )
      {
        TransformAABB(
          transform,
          vecMinsIn: (const Vector *)((char *)&pInstanceMapa->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >
                         + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory),
          vecMaxsIn: (const Vector *)((char *)&pInstanceMapa->m_PlaneHash.m_Planes.m_Size
                         + (unsigned int)pInstanceMap->m_Brushes.m_Memory.m_pMemory),
          vecMinsOut: &NewBrush->m_vMinBounds,
          vecMaxsOut: &NewBrush->m_vMaxBounds);
      }
      pInstanceMapa = (const CSimpleMapFile *)((char *)pInstanceMapa + 36);
      ++i;
      if ( v9 + 1 >= pInstanceMap->m_Brushes.m_Size )
        break;
      v7 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D950
// Name: private: void CSimpleMapFile::MergeEntities(int,class CSimpleMapFile const __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeEntities(
        CSimpleMapFile *this,
        MapEntityKeyValuePair_t *nEntityIndex,
        const CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        const matrix3x4_t *transform,
        GameData *pGameData)
{
  CSimpleMapFile *v7; // edi
  MapEntity_t *v8; // eax
  int v9; // esi
  int m_nNumKVPairs; // ebx
  GDclass *v11; // edx
  MapEntityKeyValuePair_t *v12; // eax
  int v13; // esi
  MapEntityKeyValuePair_t *v14; // eax
  const char *m_pValue; // eax
  MapEntity_t *m_pMemory; // edx
  int v17; // ebx
  char *v18; // eax
  int v19; // esi
  char *v20; // eax
  const char *v21; // eax
  int v22; // eax
  int v23; // esi
  const char **p_m_pKey; // ebx
  MapEntityKeyValuePair_t *v25; // eax
  const char *v26; // eax
  bool v27; // cc
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapEntity_t *v30; // ecx
  int v31; // eax
  char *v32; // esi
  int v33; // eax
  int v34; // ebx
  MapEntity_t *v35; // eax
  double v36; // st7
  float *v37; // eax
  GDclass *v38; // edx
  MapEntityKeyValuePair_t *NewKeyValuePair; // esi
  int v40; // esi
  char *v41; // eax
  float v42; // eax
  int v43; // esi
  int v44; // edx
  int v45; // esi
  int v46; // esi
  _BYTE *v47; // eax
  int v48; // eax
  float z; // ecx
  __int64 v50; // xmm0_8
  GDclass *v51; // eax
  int v52; // esi
  char *v53; // esi
  char *v54; // eax
  GDclass *p_m_pValue; // eax
  _BYTE *v56; // eax
  _BYTE *v57; // esi
  unsigned int v58; // kr00_4
  char *v59; // eax
  char v60; // dl
  int v61; // eax
  char v62; // cl
  int v63; // eax
  int v64; // eax
  int v65; // esi
  unsigned __int8 *v66; // esi
  const char *v67; // eax
  int v68; // eax
  char v69; // cl
  char *v70; // eax
  char *v71; // esi
  char v72; // cl
  const char *v73; // edx
  unsigned int v74; // eax
  char *v75; // edi
  char v76; // cl
  int v77; // eax
  char v78; // cl
  char *v79; // eax
  GameData::TNameFixup v80; // [esp-4h] [ebp-1140h]
  char dest[1024]; // [esp+Ch] [ebp-1130h] BYREF
  char pszOutValue[1024]; // [esp+40Ch] [ebp-D30h] BYREF
  char pszInValue[1023]; // [esp+80Ch] [ebp-930h] BYREF
  char v84; // [esp+C0Bh] [ebp-531h] BYREF
  char v85[1024]; // [esp+C0Ch] [ebp-530h] BYREF
  char pszValue[100]; // [esp+100Ch] [ebp-130h] BYREF
  char pDest[128]; // [esp+1070h] [ebp-CCh] BYREF
  QAngle Angle; // [esp+10F0h] [ebp-4Ch] BYREF
  CSimpleMapFile *v89; // [esp+10FCh] [ebp-40h]
  int nEntityIndexa; // [esp+1100h] [ebp-3Ch]
  int v91; // [esp+1104h] [ebp-38h]
  Vector in1; // [esp+1108h] [ebp-34h] BYREF
  int v93; // [esp+1114h] [ebp-28h]
  GameData::TNameFixup NameFixup; // [esp+1118h] [ebp-24h]
  int nNumPairs; // [esp+111Ch] [ebp-20h]
  int v96; // [esp+1120h] [ebp-1Ch]
  int v97; // [esp+1124h] [ebp-18h]
  char *pszClassName; // [esp+1128h] [ebp-14h]
  char *pSrc; // [esp+112Ch] [ebp-10h]
  const char *VariableAt; // [esp+1130h] [ebp-Ch]
  int iIndex; // [esp+1134h] [ebp-8h]
  GDclass *v102; // [esp+1138h] [ebp-4h]
  MapEntityKeyValuePair_t *pInstancePairs; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsa; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsb; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsc; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsd; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairse; // [esp+1144h] [ebp+8h]
  MapEntityKeyValuePair_t *pInstancePairsf; // [esp+1144h] [ebp+8h]
  char pInstancePairs_3; // [esp+1147h] [ebp+Bh]

  v7 = this;
  v91 = 28 * (_DWORD)nEntityIndex;
  v8 = &this->m_Entities.m_Memory.m_pMemory[(_DWORD)nEntityIndex];
  v9 = 0;
  m_nNumKVPairs = v8->m_nNumKVPairs;
  v11 = (GDclass *)&this->m_KeyValuePairs.m_Memory.m_pMemory[v8->m_nFirstKVPairIndex];
  v89 = this;
  pInstancePairs = (MapEntityKeyValuePair_t *)v11;
  nNumPairs = m_nNumKVPairs;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_8;
  v102 = v11;
  while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "targetname") != 0 )
  {
    v102 = (GDclass *)((char *)v102 + 12);
    if ( ++v9 >= m_nNumKVPairs )
      goto LABEL_8;
  }
  v12 = &pInstancePairs[v9];
  if ( v12 == nullptr || (pSrc = (char *)v12->m_pValue) == nullptr )
LABEL_8:
    pSrc = (char *)defaultValue;
  v13 = 0;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_16;
  v102 = (GDclass *)pInstancePairs;
  while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "name") != 0 )
  {
    v102 = (GDclass *)((char *)v102 + 12);
    if ( ++v13 >= m_nNumKVPairs )
      goto LABEL_16;
  }
  v14 = &pInstancePairs[v13];
  if ( v14 == nullptr || (m_pValue = v14->m_pValue) == nullptr )
LABEL_16:
    m_pValue = defaultValue;
  if ( *pSrc != 0 )
  {
    V_strncpy(pDest, pSrc, maxLen: 128);
  }
  else if ( *m_pValue != 0 )
  {
    V_strncpy(pDest, pSrc: m_pValue, maxLen: 128);
  }
  else
  {
    V_snprintf(pDest, maxLen: 128, pFormat: "InstanceAuto%d", v7->m_nInstanceCount);
  }
  v93 = 0;
  v97 = 0;
  if ( v7->m_Entities.m_Size > 0 )
  {
    iIndex = 0;
    do
    {
      m_pMemory = v7->m_Entities.m_Memory.m_pMemory;
      v17 = *(int *)((char *)&m_pMemory->m_nNumKVPairs + iIndex);
      v18 = (char *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(int *)((char *)&m_pMemory->m_nFirstKVPairIndex + iIndex)];
      v19 = 0;
      pSrc = v18;
      if ( v17 > 0 )
      {
        v102 = (GDclass *)v18;
        while ( _V_stricmp(s1: (const char *)v102->Parent, s2: "hammerid") != 0 )
        {
          v102 = (GDclass *)((char *)v102 + 12);
          if ( ++v19 >= v17 )
            goto LABEL_34;
        }
        v20 = &pSrc[12 * v19];
        if ( v20 != nullptr )
        {
          v21 = *((const char **)v20 + 1);
          if ( v21 != nullptr && *v21 != 0 )
          {
            v22 = atoi(nptr: v21);
            if ( v22 > v93 )
              v93 = v22;
          }
        }
      }
LABEL_34:
      iIndex += 28;
      ++v97;
    }
    while ( v97 < v7->m_Entities.m_Size );
  }
  v23 = 0;
  if ( nNumPairs <= 0 )
    goto LABEL_42;
  p_m_pKey = &pInstancePairs->m_pKey;
  while ( _V_stricmp(s1: *p_m_pKey, s2: "fixup_style") != 0 )
  {
    ++v23;
    p_m_pKey += 3;
    if ( v23 >= nNumPairs )
      goto LABEL_42;
  }
  v25 = &pInstancePairs[v23];
  if ( v25 == nullptr || (v26 = v25->m_pValue) == nullptr )
LABEL_42:
    v26 = defaultValue;
  NameFixup = atoi(nptr: v26);
  v27 = pInstanceMap->m_Entities.m_Size <= 0;
  nEntityIndexa = v7->m_Entities.m_Size;
  v97 = 0;
  if ( !v27 )
  {
    pSrc = nullptr;
    while ( 1 )
    {
      m_Size = v7->m_Entities.m_Size;
      m_nAllocationCount = v7->m_Entities.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<MapEntity_t,int>::Grow(this: &v7->m_Entities.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v7->m_Entities.m_Size;
      v30 = v7->m_Entities.m_Memory.m_pMemory;
      v31 = v7->m_Entities.m_Size - m_Size - 1;
      v7->m_Entities.m_pElements = v30;
      if ( v31 > 0 )
        _V_memmove(dest: &v30[m_Size + 1], src: &v30[m_Size], count: 28 * v31);
      v32 = pSrc;
      v33 = (int)&v7->m_Entities.m_Memory.m_pMemory[v7->m_Entities.m_Size - 1];
      *(_QWORD *)v33 = 0;
      *(_QWORD *)(v33 + 8) = 0;
      *(_QWORD *)(v33 + 16) = 0;
      *(_DWORD *)(v33 + 24) = 0;
      v34 = (int)&v7->m_Entities.m_Memory.m_pMemory[v7->m_Entities.m_Size - 1];
      v35 = pInstanceMap->m_Entities.m_Memory.m_pMemory;
      v36 = *(float *)&v32[(_DWORD)v35];
      v37 = (float *)((int)&v35->m_vOrigin.x + (_DWORD)v32);
      *(float *)v34 = v36;
      iIndex = 0;
      *(float *)(v34 + 4) = v37[1];
      *(float *)(v34 + 8) = v37[2];
      *(float *)(v34 + 12) = v37[3];
      *(float *)(v34 + 16) = v37[4];
      *(float *)(v34 + 20) = v37[5];
      *(float *)(v34 + 24) = v37[6];
      *(_DWORD *)(v34 + 12) += v7->m_Brushes.m_Size - pInstanceMap->m_Brushes.m_Size;
      v27 = *(_DWORD *)(v34 + 24) <= 0;
      *(_DWORD *)(v34 + 20) = v7->m_KeyValuePairs.m_Size;
      v38 = (GDclass *)&pInstanceMap->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)&v32[(unsigned int)pInstanceMap->m_Entities.m_Memory.m_pMemory
                                                                                       + 20]];
      v102 = v38;
      if ( !v27 )
      {
        pInstancePairsa = (MapEntityKeyValuePair_t *)v38;
        do
        {
          NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: v7);
          NewKeyValuePair->m_pKey = CStringPool::Allocate(
                                      this: &v7->m_KeyValueStringPool,
                                      pszValue: pInstancePairsa->m_pKey);
          NewKeyValuePair->m_pValue = nullptr;
          NewKeyValuePair->m_bIsConnection = pInstancePairsa->m_bIsConnection;
          ++iIndex;
          ++pInstancePairsa;
        }
        while ( iIndex < *(_DWORD *)(v34 + 24) );
      }
      v40 = 0;
      VariableAt = *(const char **)(v34 + 24);
      if ( (int)VariableAt <= 0 )
        goto LABEL_59;
      pInstancePairsb = (MapEntityKeyValuePair_t *)v102;
      while ( _V_stricmp(s1: pInstancePairsb->m_pKey, s2: "classname") != 0 )
      {
        ++pInstancePairsb;
        if ( ++v40 >= (int)VariableAt )
          goto LABEL_59;
      }
      v41 = (char *)v102 + 12 * v40;
      if ( v41 == nullptr || (pszClassName = *((char **)v41 + 1)) == nullptr )
LABEL_59:
        pszClassName = (char *)defaultValue;
      if ( v97 != 0 )
      {
        v42 = *(float *)(v34 + 8);
        *(_QWORD *)&in1.x = *(_QWORD *)v34;
        in1.z = v42;
        VectorTransform(in1: &in1.x, in2: transform, out: (float *)v34);
        v43 = 0;
        pInstancePairsc = &v7->m_KeyValuePairs.m_Memory.m_pMemory[v7->m_Entities.m_Memory.m_pMemory[v91 / 0x1Cu].m_nFirstKVPairIndex];
        if ( *(int *)(v34 + 24) > 0 )
        {
          iIndex = (int)&v102->m_rgbColor;
          do
          {
            CSimpleMapFile::FixupInstanceKeyValuePair(
              this: v7,
              pNewKeyValuePair: &v7->m_KeyValuePairs.m_Memory.m_pMemory[v43 + *(_DWORD *)(v34 + 20)],
              pOriginalValue: *(const char **)iIndex,
              pInstancePairs: pInstancePairsc,
              nNumPairs);
            iIndex += 12;
            ++v43;
          }
          while ( v43 < *(_DWORD *)(v34 + 24) );
        }
        v44 = (int)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)];
        v45 = 0;
        VariableAt = *(const char **)(v34 + 24);
        iIndex = v44;
        if ( (int)VariableAt > 0 )
        {
          pInstancePairsd = (MapEntityKeyValuePair_t *)v44;
          while ( _V_stricmp(s1: pInstancePairsd->m_pKey, s2: "hammerid") != 0 )
          {
            ++pInstancePairsd;
            if ( ++v45 >= (int)VariableAt )
              goto LABEL_73;
          }
          v46 = iIndex + 12 * v45;
          if ( v46 != 0 )
          {
            v47 = *(_BYTE **)(v46 + 4);
            if ( v47 != nullptr && *v47 != 0 )
            {
              v48 = atoi(nptr: *(const char **)(v46 + 4));
              V_snprintf(pDest: pszValue, maxLen: 100, pFormat: "%d", v93 + v48);
              *(_DWORD *)(v46 + 4) = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue);
            }
          }
        }
LABEL_73:
        in1.x = vOrigin->x;
        in1.y = vOrigin->y;
        z = orientation->z;
        in1.z = vOrigin->z;
        v50 = *(_QWORD *)&orientation->x;
        Angle.z = z;
        *(_QWORD *)&Angle.x = v50;
        v51 = GameData::BeginInstanceRemap(
                this: pGameData,
                pszClassName,
                pszInstancePrefix: pDest,
                Origin: &in1,
                &Angle);
        v102 = v51;
        if ( v51 != nullptr )
        {
          v27 = v51->m_nVariables <= 0;
          iIndex = 0;
          if ( !v27 )
          {
            do
            {
              pszClassName = (char *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)];
              VariableAt = (const char *)GDclass::GetVariableAt(this: v102, iIndex);
              v52 = 0;
              v96 = *(_DWORD *)(v34 + 24);
              if ( v96 <= 0 )
              {
LABEL_79:
                v53 = nullptr;
              }
              else
              {
                pInstancePairse = (MapEntityKeyValuePair_t *)pszClassName;
                while ( _V_stricmp(s1: pInstancePairse->m_pKey, s2: VariableAt + 20) != 0 )
                {
                  ++pInstancePairse;
                  if ( ++v52 >= v96 )
                    goto LABEL_79;
                }
                v53 = &pszClassName[12 * v52];
                if ( v53 != nullptr )
                {
                  v54 = *((char **)v53 + 1);
                  if ( v54 != nullptr )
                    goto LABEL_83;
                }
              }
              v54 = (char *)defaultValue;
LABEL_83:
              pInstancePairsf = (MapEntityKeyValuePair_t *)(VariableAt + 20);
              if ( GameData::RemapKeyValue(
                     this: pGameData,
                     pszKey: VariableAt + 20,
                     pszInValue: v54,
                     pszOutValue,
                     NameFixup) )
              {
                if ( v53 == nullptr )
                {
                  v53 = (char *)CSimpleMapFile::AllocateNewKeyValuePair(this: v7);
                  *(_DWORD *)v53 = CStringPool::Allocate(
                                     this: &v7->m_KeyValueStringPool,
                                     pszValue: (const char *)pInstancePairsf);
                  ++*(_DWORD *)(v34 + 24);
                }
                *((_DWORD *)v53 + 1) = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue: pszOutValue);
              }
              ++iIndex;
            }
            while ( iIndex < v102->m_nVariables );
          }
        }
        v27 = *(_DWORD *)(v34 + 24) <= 0;
        p_m_pValue = (GDclass *)&v7->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v34 + 20)].m_pValue;
        pszClassName = nullptr;
        if ( !v27 )
          break;
      }
LABEL_116:
      pSrc += 28;
      if ( ++v97 >= pInstanceMap->m_Entities.m_Size )
        goto LABEL_117;
    }
    v102 = p_m_pValue;
    while ( 1 )
    {
      if ( p_m_pValue->m_rgbColor.r != 0 )
      {
        pInstancePairs_3 = 0;
        V_strncpy(pDest: pszInValue, pSrc: (const char *)p_m_pValue->Parent, maxLen: 1024);
        strchr(string: (unsigned __int8 *)pszInValue, chr: 0x1Bu);
        v57 = v56;
        if ( v56 != nullptr )
          *v56 = 0;
        if ( GameData::RemapNameField(this: pGameData, pszInValue, pszOutValue: v85, NameFixup) )
        {
          if ( v57 != nullptr )
          {
            v58 = strlen(v85);
            v85[v58] = 27;
            v59 = v57 + 1;
            do
            {
              v60 = *v59;
              v85[v58 - (_DWORD)(v57 + 1) + 1 + (_DWORD)v59] = *v59;
              ++v59;
            }
            while ( v60 != 0 );
          }
          pInstancePairs_3 = 1;
          v61 = 0;
          do
          {
            v62 = v85[v61];
            pszInValue[v61++] = v62;
          }
          while ( v62 != 0 );
        }
        strchr(string: (unsigned __int8 *)pszInValue, chr: 0x1Bu);
        iIndex = v63;
        if ( v63 != 0 )
        {
          iIndex = v63 + 1;
          strchr(string: (unsigned __int8 *)(v63 + 1), chr: 0x1Bu);
          v65 = v64;
          if ( v64 != 0 && V_strncasecmp(s1: (const char *)iIndex, s2: "setparent", n: v64 - iIndex) == 0 )
          {
            v66 = (unsigned __int8 *)(v65 + 1);
            strchr(string: v66, chr: 0x1Bu);
            VariableAt = v67;
            if ( v67 != nullptr )
            {
              v96 = v67 - (const char *)v66;
              strncpy((unsigned __int8 *)dest, source: v66, count: v67 - (const char *)v66);
              v80 = NameFixup;
              dest[v96] = 0;
              if ( GameData::RemapNameField(this: pGameData, pszInValue: dest, pszOutValue, NameFixup: v80) )
              {
                v68 = 0;
                do
                {
                  v69 = pszInValue[v68];
                  v85[v68++] = v69;
                }
                while ( v69 != 0 );
                v70 = pszOutValue;
                v71 = &v85[v66 - (unsigned __int8 *)pszOutValue - (_DWORD)pszInValue];
                do
                {
                  v72 = *v70;
                  v70[(_DWORD)v71] = *v70;
                  ++v70;
                }
                while ( v72 != 0 );
                v73 = VariableAt;
                v74 = strlen(VariableAt) + 1;
                v75 = &v84;
                do
                  v76 = *++v75;
                while ( v76 != 0 );
                qmemcpy(v75, VariableAt, 4 * (v74 >> 2));
                qmemcpy(&v75[4 * (v74 >> 2)], &v73[4 * (v74 >> 2)], v74 & 3);
                v77 = 0;
                do
                {
                  v78 = v85[v77];
                  pszInValue[v77++] = v78;
                }
                while ( v78 != 0 );
                v7 = v89;
LABEL_114:
                v79 = CStringPool::Allocate(this: &v7->m_KeyValueStringPool, pszValue: v85);
                v102->Parent = (GameData *)v79;
                goto LABEL_115;
              }
            }
          }
        }
        if ( pInstancePairs_3 == 1 )
          goto LABEL_114;
      }
LABEL_115:
      p_m_pValue = (GDclass *)&v102->m_bKeyFrame;
      ++pszClassName;
      v102 = (GDclass *)((char *)v102 + 12);
      if ( (int)pszClassName >= *(_DWORD *)(v34 + 24) )
        goto LABEL_116;
    }
  }
LABEL_117:
  CSimpleMapFile::MoveEntityBrushesToWorld(this: v7, nEntityIndex: nEntityIndexa);
}

//------------------------------------------------------------------------------
// Address: 0x0041E260
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::EntityKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::EntityKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  unsigned int v3; // eax
  int v5; // eax
  MapEntityKeyValuePair_t *NewKeyValuePair; // ebx

  if ( _V_stricmp(s1: pKey, s2: "classname") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "origin") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "id") != 0 )
      {
        if ( _V_stricmp(s1: pKey, s2: "mapversion") == 0 )
          (*pData)->m_nMapRevision = atoi(nptr: pValue);
      }
      else
      {
        pKey = "hammerid";
        v5 = atoi(nptr: pValue);
        if ( v5 > (*pData)->m_nHighestID )
          (*pData)->m_nHighestID = v5;
      }
    }
    else if ( sscanf(string: pValue, format: "%f %f %f", pData[1], &pData[1]->m_pFilename, &pData[1]->m_PlaneHash) != 3 )
    {
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Entity origin malformed.");
      return 1;
    }
  }
  else
  {
    if ( _V_stricmp(s1: pValue, s2: "func_detail") != 0 )
    {
      if ( _V_stricmp(s1: pValue, s2: "func_instance_parms") != 0 )
      {
        if ( _V_stricmp(s1: pValue, s2: "func_viscluster") != 0
          && _V_stricmp(s1: pValue, s2: "func_ladder") != 0
          && _V_stricmp(s1: pValue, s2: "func_simpleladder") != 0
          && _V_stricmp(s1: pValue, s2: "func_envcubemap") != 0
          && _V_stricmp(s1: pValue, s2: "test_sidelist") != 0
          && _V_stricmp(s1: pValue, s2: "info_overlay") != 0
          && _V_stricmp(s1: pValue, s2: "info_overlay_transition") != 0
          && _V_stricmp(s1: pValue, s2: "info_no_dynamic_shadow") != 0 )
        {
          v3 = _V_strlen(str: "func_areaportal");
          if ( V_strnicmp(s1: pValue, s2: "func_areaportal", n: v3) != 0 )
            goto LABEL_25;
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Entity type not supported: %s.\n", pValue);
      }
      return 9;
    }
    pData[2] = (CSimpleMapFile *)0x8000000;
  }
LABEL_25:
  NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: *pData);
  NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pKey);
  NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pValue);
  ++pData[1]->m_PlaneHash.m_Planes.m_Size;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E490
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::ConnectionsKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::ConnectionsKeyHandler(
        const char *pKey,
        const char *pValue,
        CSimpleMapFile **pData)
{
  MapEntityKeyValuePair_t *NewKeyValuePair; // edi

  NewKeyValuePair = CSimpleMapFile::AllocateNewKeyValuePair(this: *pData);
  NewKeyValuePair->m_pKey = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pKey);
  NewKeyValuePair->m_pValue = CStringPool::Allocate(this: &(*pData)->m_KeyValueStringPool, pszValue: pValue);
  NewKeyValuePair->m_bIsConnection = true;
  ++pData[1]->m_PlaneHash.m_Planes.m_Size;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041E4E0
// Name: private: struct CSimpleMapFile::MaterialInfo_t __near * CSimpleMapFile::FindMaterialInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleMapFile::MaterialInfo_t *__thiscall CSimpleMapFile::FindMaterialInfo(CSimpleMapFile *this, const char *pName)
{
  int v3; // ebx
  int v4; // esi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CSimpleMapFile::MaterialInfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // ebx
  const char *v10; // edx
  CSimpleMapFile::MaterialInfo_t *v11; // eax
  char v12; // cl
  void *Material; // eax
  void *v14; // esi
  const char *MaterialVar; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  int v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  bool v34; // zf
  __int16 *p_m_SurfaceFlags; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  BOOL IsTrue; // eax
  const char *v43; // eax
  const char *v44; // eax
  const char *MaterialShaderName; // eax
  const char *v46; // esi
  const char *v47; // eax
  int MaterialShaderPropertyInt; // eax
  CSimpleMapFile::MaterialInfo_t *v49; // ecx
  int *p_m_ContentsFlags; // ecx
  __int16 *v51; // eax
  void *matID; // [esp+Ch] [ebp-8h]
  bool found; // [esp+12h] [ebp-2h] BYREF
  bool bKeepLighting; // [esp+13h] [ebp-1h]
  const char *checkWindow; // [esp+1Ch] [ebp+8h]
  const char *checkWindowa; // [esp+1Ch] [ebp+8h]
  const char *checkWindowb; // [esp+1Ch] [ebp+8h]
  const char *checkWindowc; // [esp+1Ch] [ebp+8h]
  const char *checkWindowd; // [esp+1Ch] [ebp+8h]
  const char *checkWindowe; // [esp+1Ch] [ebp+8h]
  char checkWindow_3; // [esp+1Fh] [ebp+Bh]

  v3 = 0;
  if ( this->m_MaterialInfos.m_Size > 0 )
  {
    v4 = 0;
    while ( _V_stricmp(s1: pName, s2: this->m_MaterialInfos.m_Memory.m_pMemory[v4].m_Name) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->m_MaterialInfos.m_Size )
        goto LABEL_5;
    }
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v3];
  }
LABEL_5:
  m_Size = this->m_MaterialInfos.m_Size;
  m_nAllocationCount = this->m_MaterialInfos.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CSimpleMapFile::MaterialInfo_t,int>::Grow(
      this: &this->m_MaterialInfos.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_MaterialInfos.m_Size;
  m_pMemory = this->m_MaterialInfos.m_Memory.m_pMemory;
  v8 = this->m_MaterialInfos.m_Size - m_Size - 1;
  this->m_MaterialInfos.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 136 * v8);
  v9 = v3;
  v10 = pName;
  v11 = &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  do
  {
    v12 = *v10;
    v11->m_Name[0] = *v10++;
    v11 = (CSimpleMapFile::MaterialInfo_t *)((char *)v11 + 1);
  }
  while ( v12 != 0 );
  this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags = 0;
  this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 0;
  Material = FindMaterial(materialName: pName, pFound: &found, bComplain: true);
  v14 = Material;
  matID = Material;
  if ( Material == nullptr || !found )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Material not found!: %s\n", pName);
    return nullptr;
  }
  MaterialVar = GetMaterialVar(materialHandle: Material, propertyName: "%compileSky");
  checkWindow = MaterialVar;
  if ( MaterialVar != nullptr
    && (V_strcasecmp(s1: MaterialVar, s2: "true") == 0 || V_strcasecmp(s1: checkWindow, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x404u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v17 = GetMaterialVar(materialHandle: v14, propertyName: "%compile2DSky");
  checkWindowa = v17;
  if ( v17 != nullptr && (V_strcasecmp(s1: v17, s2: "true") == 0 || V_strcasecmp(s1: checkWindowa, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x406u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v18 = GetMaterialVar(materialHandle: v14, propertyName: "%compileHint");
  checkWindowb = v18;
  if ( v18 != nullptr && (V_strcasecmp(s1: v18, s2: "true") == 0 || V_strcasecmp(s1: checkWindowb, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x580u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v19 = GetMaterialVar(materialHandle: v14, propertyName: "%compileSkip");
  checkWindowc = v19;
  if ( v19 != nullptr && (V_strcasecmp(s1: v19, s2: "true") == 0 || V_strcasecmp(s1: checkWindowc, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x680u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v20 = GetMaterialVar(materialHandle: v14, propertyName: "%compileOrigin");
  checkWindowd = v20;
  if ( v20 != nullptr && (V_strcasecmp(s1: v20, s2: "true") == 0 || V_strcasecmp(s1: checkWindowd, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x9000000u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v21 = GetMaterialVar(materialHandle: v14, propertyName: "%compileClip");
  checkWindowe = v21;
  if ( v21 != nullptr && (V_strcasecmp(s1: v21, s2: "true") == 0 || V_strcasecmp(s1: checkWindowe, s2: "1") == 0) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x30000u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
  }
  v22 = GetMaterialVar(materialHandle: v14, propertyName: "%playerClip");
  if ( v22 != nullptr )
  {
    if ( StringIsTrue(str: v22) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x10000u;
LABEL_45:
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v23 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNpcClip");
  if ( v23 != nullptr )
  {
    if ( StringIsTrue(str: v23) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20000u;
      goto LABEL_45;
    }
    v14 = matID;
  }
  v24 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoChop");
  if ( v24 != nullptr )
  {
    if ( StringIsTrue(str: v24) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x4000u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v25 = GetMaterialVar(materialHandle: v14, propertyName: "%compileTrigger");
  if ( v25 != nullptr )
  {
    if ( StringIsTrue(str: v25) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x440u;
      return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
    }
    v14 = matID;
  }
  v26 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoLight");
  if ( v26 != nullptr )
  {
    if ( StringIsTrue(str: v26) )
    {
      v27 = GetMaterialVar(materialHandle: matID, propertyName: "%compileWater");
      if ( v27 == nullptr || !StringIsTrue(str: v27) )
      {
        this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x400u;
        return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
      }
    }
    v14 = matID;
  }
  v28 = GetMaterialVar(materialHandle: v14, propertyName: "%compileLadder");
  if ( v28 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v28) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20000000u;
  }
  v29 = GetMaterialVar(materialHandle: v14, propertyName: "%compileTeam");
  if ( v29 != nullptr )
  {
    v30 = atoi(nptr: v29);
    if ( v30 == 1 )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x800u;
    }
    else if ( v30 == 2 )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x1000u;
    }
  }
  v31 = GetMaterialVar(materialHandle: v14, propertyName: "%noPortal");
  if ( v31 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v31) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x20u;
  }
  v32 = GetMaterialVar(materialHandle: v14, propertyName: "%hotSurface");
  if ( v32 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v32) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x20u;
  }
  v33 = GetMaterialVar(materialHandle: v14, propertyName: "%compilePassBullets");
  if ( v33 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v33) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 8u;
    }
  }
  if ( GetMaterialShaderPropertyBool(materialHandle: v14, propID: 0) != 0 )
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x800u;
  v34 = GetMaterialShaderPropertyBool(materialHandle: v14, propID: 1) == 0;
  p_m_SurfaceFlags = &this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags;
  if ( v34 )
    *p_m_SurfaceFlags |= 0x400u;
  else
    *p_m_SurfaceFlags &= ~0x400u;
  v36 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNoDraw");
  if ( v36 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v36) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
  }
  v37 = GetMaterialVar(materialHandle: v14, propertyName: "%compileInvisible");
  if ( v37 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v37) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 8u;
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x480u;
    }
  }
  checkWindow_3 = 1;
  v38 = GetMaterialVar(materialHandle: v14, propertyName: "%compileNonsolid");
  if ( v38 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v38) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 128;
      checkWindow_3 = 0;
    }
  }
  v39 = GetMaterialVar(materialHandle: v14, propertyName: "%compileBlockLOS");
  if ( v39 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v39) )
    {
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags = 64;
      checkWindow_3 = 0;
    }
  }
  v40 = GetMaterialVar(materialHandle: v14, propertyName: "%compileDetail");
  if ( v40 != nullptr )
  {
    v14 = matID;
    if ( StringIsTrue(str: v40) )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x8000000u;
  }
  v41 = GetMaterialVar(materialHandle: v14, propertyName: "%compileKeepLight");
  if ( v41 == nullptr || (IsTrue = StringIsTrue(str: v41), bKeepLighting = true, !IsTrue) )
    bKeepLighting = false;
  v43 = GetMaterialVar(materialHandle: matID, propertyName: "%compileWater");
  if ( v43 != nullptr && StringIsTrue(str: v43) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= 0xF7FFFFFE;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x20u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x3008u;
  }
  v44 = GetMaterialVar(materialHandle: matID, propertyName: "%compileNoShadows");
  if ( v44 != nullptr && StringIsTrue(str: v44) )
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x1000u;
  MaterialShaderName = GetMaterialShaderName(materialHandle: matID);
  v46 = MaterialShaderName;
  if ( !bKeepLighting && V_strncasecmp(s1: MaterialShaderName, s2: "water", n: 5) == 0
    || V_strncasecmp(s1: v46, s2: "UnlitGeneric", n: 12) == 0 )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x400u;
  }
  v47 = GetMaterialVar(materialHandle: matID, propertyName: "%compileSlime");
  if ( v47 != nullptr && StringIsTrue(str: v47) )
  {
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= 0xF7FFFFFE;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags |= 0x10u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x2000u;
  }
  MaterialShaderPropertyInt = GetMaterialShaderPropertyInt(materialHandle: matID, propID: 2);
  if ( checkWindow_3 != 0 && MaterialShaderPropertyInt != 1 )
  {
    v49 = this->m_MaterialInfos.m_Memory.m_pMemory;
    v34 = (v49[v9].m_ContentsFlags & 0x28) == 0;
    p_m_ContentsFlags = &v49[v9].m_ContentsFlags;
    if ( v34 )
      *p_m_ContentsFlags |= 2u;
    this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_ContentsFlags &= ~1u;
    if ( MaterialShaderPropertyInt == 2 )
      this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags |= 0x10u;
  }
  v51 = &this->m_MaterialInfos.m_Memory.m_pMemory[v9].m_SurfaceFlags;
  if ( (*v51 & 0x400) != 0 )
    *v51 &= ~0x800u;
  return &this->m_MaterialInfos.m_Memory.m_pMemory[v9];
}

//------------------------------------------------------------------------------
// Address: 0x0041EFE0
// Name: private: int CSimpleMapFile::GetTextureInfoForBrushTexture(struct MapBrushTexture_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimpleMapFile::GetTextureInfoForBrushTexture(
        CSimpleMapFile *this,
        MapBrushTexture_t *pBrushTexture,
        const Vector *vRelativeOrigin)
{
  int i; // ecx
  MapBrushTexture_t *p_m_vVAxis; // esi
  float x; // xmm2_4
  int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float y; // xmm2_4
  float z; // xmm2_4
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  MapTextureInfo_t texInfo; // [esp+0h] [ebp-48h] BYREF

  memset(&texInfo, 0, sizeof(texInfo));
  for ( i = 0; i < 2; ++i )
  {
    if ( pBrushTexture->m_flTextureWorldUnitsPerTexel[i] == 0.0 )
      pBrushTexture->m_flTextureWorldUnitsPerTexel[i] = 1.0;
    p_m_vVAxis = pBrushTexture;
    if ( i != 0 )
      p_m_vVAxis = (MapBrushTexture_t *)&pBrushTexture->m_vVAxis;
    x = p_m_vVAxis->m_vUAxis.x;
    v7 = i;
    v8 = 1.0 / pBrushTexture->m_flTextureWorldUnitsPerTexel[i];
    texInfo.m_flTextureVectors[v7][0] = p_m_vVAxis->m_vUAxis.x * v8;
    v9 = 1.0 / pBrushTexture->m_flLightmapWorldUnitsPerLuxel;
    texInfo.m_flLightmapVectors[v7][0] = x * v9;
    y = p_m_vVAxis->m_vUAxis.y;
    texInfo.m_flTextureVectors[v7][1] = y * v8;
    texInfo.m_flLightmapVectors[v7][1] = y * v9;
    z = p_m_vVAxis->m_vUAxis.z;
    texInfo.m_flTextureVectors[v7][2] = z * v8;
    texInfo.m_flLightmapVectors[v7][2] = z * v9;
    v12 = i;
    v13 = texInfo.m_flLightmapVectors[i][1] * vRelativeOrigin->y;
    v14 = texInfo.m_flLightmapVectors[i][2] * vRelativeOrigin->z;
    texInfo.m_flTextureVectors[v12][3] = (float)((float)((float)(texInfo.m_flTextureVectors[i][0] * vRelativeOrigin->x)
                                                       + (float)(texInfo.m_flTextureVectors[i][1] * vRelativeOrigin->y))
                                               + (float)(texInfo.m_flTextureVectors[i][2] * vRelativeOrigin->z))
                                       + pBrushTexture->m_flShift[i];
    v15 = (float)((float)(texInfo.m_flLightmapVectors[i][0] * vRelativeOrigin->x) + v13) + v14;
    v16 = (float)(pBrushTexture->m_flTextureWorldUnitsPerTexel[i] * v9) * pBrushTexture->m_flShift[i];
    texInfo.m_flLightmapVectors[v12][3] = v15 + v16;
  }
  texInfo.m_SurfaceFlags = pBrushTexture->m_SurfaceFlags;
  texInfo.m_nTextureDataIndex = CSimpleMapFile::FindOrCreateTextureData(
                                  this,
                                  pTextureName: pBrushTexture->m_MaterialName);
  return CSimpleMapFile::FindOrCreateTextureInfo(this, textureInfo: &texInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041F180
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::ConnectionsChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::ConnectionsChunkHandler(CChunkFile *pFile, void *pData)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap connectionsChunkHandlers; // [esp+8h] [ebp-Ch] BYREF

  CExpressionEvaluator::CExpressionEvaluator(this: &connectionsChunkHandlers);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &connectionsChunkHandlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::ConnectionsKeyHandler,
            pData);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &connectionsChunkHandlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x0041F1D0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SideKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::SideKeyHandler(const char *pKey, const char *pValue, char *pData)
{
  CSimpleMapFile::MaterialInfo_t *MaterialInfo; // eax
  _DWORD *v5; // esi
  int v6; // eax

  if ( _V_stricmp(s1: pKey, s2: "plane") == 0 )
  {
    if ( sscanf(
           string: pValue,
           format: "(%f %f %f) (%f %f %f) (%f %f %f)",
           pData + 12,
           pData + 16,
           pData + 20,
           pData + 24,
           pData + 28,
           pData + 32,
           pData + 36,
           pData + 40,
           pData + 44) != 9 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "Plane definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "material") == 0 )
  {
    _V_strcpy(dest: pData + 92, src: pValue);
    MaterialInfo = CSimpleMapFile::FindMaterialInfo(this: *(CSimpleMapFile **)pData, pName: pData + 92);
    **((_DWORD **)pData + 2) = MaterialInfo->m_ContentsFlags;
    *(_WORD *)(*((_DWORD *)pData + 2) + 4) = MaterialInfo->m_SurfaceFlags;
    *((_WORD *)pData + 110) = MaterialInfo->m_SurfaceFlags;
    *((_DWORD *)pData + 22) = 1098907648;
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "uaxis") == 0 )
  {
    if ( sscanf(string: pValue, format: "[%f %f %f %f] %f", pData + 48, pData + 52, pData + 56, pData + 72, pData + 80) != 5 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "U axis definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "vaxis") == 0 )
  {
    if ( sscanf(string: pValue, format: "[%f %f %f %f] %f", pData + 60, pData + 64, pData + 68, pData + 76, pData + 84) != 5 )
    {
      CSimpleMapFile::ReportParseError(this: *(CSimpleMapFile **)pData, pErrorString: "V axis definition malformed.");
      return 1;
    }
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "contents") == 0 )
  {
LABEL_13:
    v5 = *((_DWORD **)pData + 2);
    *v5 |= atoi(nptr: pValue);
    return 0;
  }
  if ( _V_stricmp(s1: pKey, s2: "lightmapscale") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "contents") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "flags") == 0 )
      {
        *((_WORD *)pData + 110) |= atoi(nptr: pValue);
        *(_WORD *)(*((_DWORD *)pData + 2) + 4) = *((_WORD *)pData + 110);
        return 0;
      }
      if ( _V_stricmp(s1: pKey, s2: "smoothing_groups") != 0 )
        _V_stricmp(s1: pKey, s2: "id");
      return 0;
    }
    goto LABEL_13;
  }
  v6 = atoi(nptr: pValue);
  if ( v6 <= 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Invalid 'lightmapscale' specified (%s); must be >= 1.", pValue);
    v6 = 16;
  }
  *((float *)pData + 22) = (float)v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041F480
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DisplacementKeyHandler(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::DisplacementKeyHandler(const char *pKey, const char *pValue, CSimpleMapFile **pData)
{
  int v3; // eax
  CSimpleMapFile *v4; // edx
  int v5; // esi
  CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *v6; // ecx
  CSimpleMapFile *v8; // edi

  if ( _V_stricmp(s1: pKey, s2: "power") != 0 )
  {
    if ( _V_stricmp(s1: pKey, s2: "flags") != 0 )
    {
      if ( _V_stricmp(s1: pKey, s2: "startposition") != 0
        || sscanf(
             string: pValue,
             format: "[%f %f %f]",
             &pData[1]->m_PlaneHash.m_Planes.m_Memory.m_nAllocationCount,
             &pData[1]->m_PlaneHash.m_Planes.m_Memory.m_nGrowSize,
             &pData[1]->m_PlaneHash.m_Planes.m_Size) == 3 )
      {
        return 0;
      }
      CSimpleMapFile::ReportParseError(this: *pData, pErrorString: "Start position definition malformed.");
      return 1;
    }
    else
    {
      pData[1]->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)atoi(nptr: pValue);
      return 0;
    }
  }
  else
  {
    v3 = atoi(nptr: pValue);
    pData[1]->m_pFileSystem = (IFileSystem *)v3;
    if ( (unsigned int)(v3 - 2) <= 2 )
    {
      v4 = pData[1];
      v5 = 1 << v3;
      v4->m_PlaneHash.m_HashTable[2] = 0;
      CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int> > *)&v4->m_PlaneHash.m_Planes.m_pElements,
        elem: 0,
        num: ((1 << v3) + 1) * ((1 << v3) + 1));
      v6 = (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&pData[1]->m_PlaneHash.m_HashTable[4];
      v6->m_Size = 0;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        this: v6,
        elem: 0,
        num: 2 * v5 * v5);
      return 0;
    }
    v8 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Invalid displacement power.",
        v8->m_Entities.m_Size - 1,
        v8->m_Brushes.m_Size - 1,
        v8->m_BrushSides.m_Size - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F5E0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::DispInfoChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::DispInfoChunkHandler(CChunkFile *pFile, CSimpleMapFile **pData)
{
  CSimpleMapFile *v2; // esi
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *p_m_Displacements; // edi
  ChunkFileResult_t v4; // edi
  CSimpleMapFile *v5; // ebx
  CChunkHandlerMap dispInfoChunkHandlers; // [esp+Ch] [ebp-18h] BYREF
  DisplacementLoadingInfo_t displacementLoadingInfo; // [esp+18h] [ebp-Ch] BYREF

  v2 = *pData;
  p_m_Displacements = &(*pData)->m_Displacements;
  *(_QWORD *)&displacementLoadingInfo.m_pDisplacement = 0;
  displacementLoadingInfo.m_pMapFile = v2;
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
    this: p_m_Displacements,
    elem: p_m_Displacements->m_Size);
  displacementLoadingInfo.m_pDisplacement = &p_m_Displacements->m_Memory.m_pMemory[v2->m_Displacements.m_Size - 1];
  displacementLoadingInfo.m_pDisplacement->m_nFlags = 0;
  CExpressionEvaluator::CExpressionEvaluator(this: &dispInfoChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "normals",
    pfnHandler: CSimpleMapFile::DisplacementNormalsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "distances",
    pfnHandler: CSimpleMapFile::DisplacementDistancesChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "offsets",
    pfnHandler: CSimpleMapFile::DisplacementOffsetsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "alphas",
    pfnHandler: CSimpleMapFile::DisplacementAlphasChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "triangle_tags",
    pfnHandler: CSimpleMapFile::DisplacementTriangleTagsChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendChunkHandler,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_0",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor0,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_1",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor1,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_2",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor2,
    pData: &displacementLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &dispInfoChunkHandlers,
    pszChunkName: "multiblend_color_3",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DisplacementMultiBlendColor3,
    pData: &displacementLoadingInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &dispInfoChunkHandlers);
  v4 = CChunkFile::ReadChunk(
         this: pFile,
         pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::DisplacementKeyHandler,
         pData: &displacementLoadingInfo);
  CChunkFile::PopHandlers(this: pFile);
  if ( v4 != ChunkFile_Ok )
  {
    v5 = *pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Error parsing displacement info.",
        v5->m_Entities.m_Size - 1,
        v5->m_Brushes.m_Size - 1,
        v5->m_BrushSides.m_Size - 1);
    CChunkHandlerMap::~CChunkHandlerMap(this: &dispInfoChunkHandlers);
    return v4;
  }
  else
  {
    pData[2]->m_PlaneHash.m_HashTable[2] = (*pData)->m_Displacements.m_Size - 1;
    CChunkHandlerMap::~CChunkHandlerMap(this: &dispInfoChunkHandlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F840
// Name: private: struct MapBrushSide_t __near * CSimpleMapFile::AllocateNewBrushSide(void)
// Source: json
//------------------------------------------------------------------------------
MapBrushSide_t *__thiscall CSimpleMapFile::AllocateNewBrushSide(CSimpleMapFile *this)
{
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::InsertBefore(
    this: &this->m_BrushSides,
    elem: this->m_BrushSides.m_Size);
  memset(
    dst: (unsigned __int8 *)&this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1],
    value: 0,
    count: sizeof(this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1]));
  this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1].m_nDisplacementIndex = -1;
  return &this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x0041F8B0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SideChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::SideChunkHandler(CChunkFile *pFile, char *pData)
{
  MapBrushSide_t *NewBrushSide; // edi
  CSimpleMapFile *v4; // esi
  int i; // ebx
  int m_nPlaneIndex; // ecx
  int v8; // eax
  MapBrushTexture_t *NewBrushTexture; // ebx
  CChunkHandlerMap sideChunkHandlers; // [esp+Ch] [ebp-Ch] BYREF
  ChunkFileResult_t Chunk; // [esp+24h] [ebp+Ch]

  NewBrushSide = CSimpleMapFile::AllocateNewBrushSide(this: *(CSimpleMapFile **)pData);
  *((_DWORD *)pData + 2) = NewBrushSide;
  CExpressionEvaluator::CExpressionEvaluator(this: &sideChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &sideChunkHandlers,
    pszChunkName: "dispinfo",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::DispInfoChunkHandler,
    pData);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &sideChunkHandlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::SideKeyHandler,
            pData);
  CChunkFile::PopHandlers(this: pFile);
  if ( Chunk != ChunkFile_Ok )
  {
    v4 = *(CSimpleMapFile **)pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Error parsing brush side keys.",
        v4->m_Entities.m_Size - 1,
        v4->m_Brushes.m_Size - 1,
        v4->m_BrushSides.m_Size - 1);
    CChunkHandlerMap::~CChunkHandlerMap(this: &sideChunkHandlers);
    return Chunk;
  }
  else
  {
    NewBrushSide->m_ContentsFlags |= *((_DWORD *)pData + 56);
    if ( (*(_BYTE *)(*(_DWORD *)pData + 4272) & 1) != 0 )
      NewBrushSide->m_ContentsFlags |= 0x8000000u;
    if ( (NewBrushSide->m_ContentsFlags & 0x30000) != 0 )
      NewBrushSide->m_ContentsFlags |= 0x8000000u;
    if ( (NewBrushSide->m_ContentsFlags & 0x300FF) == 0 )
      NewBrushSide->m_ContentsFlags |= 1u;
    if ( (NewBrushSide->m_SurfaceFlags & 0x300) != 0 )
      NewBrushSide->m_ContentsFlags = 0;
    NewBrushSide->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(
                                    this: (CPlaneHash *)(*(_DWORD *)pData + 8),
                                    vPoints: (Vector *)pData + 1);
    for ( i = 0; i < *(_DWORD *)(*((_DWORD *)pData + 1) + 8); ++i )
    {
      m_nPlaneIndex = NewBrushSide->m_nPlaneIndex;
      v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)pData + 4188) + 44 * (i + *(_DWORD *)(*((_DWORD *)pData + 1) + 4)) + 8);
      if ( (v8 == m_nPlaneIndex || v8 == (m_nPlaneIndex ^ 1))
        && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Duplicate or mirrored plane.\n");
      }
    }
    if ( i == *(_DWORD *)(*((_DWORD *)pData + 1) + 8) )
    {
      NewBrushTexture = CSimpleMapFile::AllocateNewBrushTexture(this: *(CSimpleMapFile **)pData);
      MapBrushTexture_t::operator=(this: NewBrushTexture, __that: (const MapBrushTexture_t *)(pData + 48));
      NewBrushSide->m_nTextureInfoIndex = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                            this: *(CSimpleMapFile **)pData,
                                            pBrushTexture: NewBrushTexture,
                                            vRelativeOrigin: &vec3_origin);
      ++*(_DWORD *)(*((_DWORD *)pData + 1) + 8);
    }
    *((_DWORD *)pData + 2) = 0;
    CChunkHandlerMap::~CChunkHandlerMap(this: &sideChunkHandlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FA80
// Name: private: CSimpleMapFile::CSimpleMapFile(class IFileSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleMapFile *__thiscall CSimpleMapFile::CSimpleMapFile(
        CSimpleMapFile *this,
        IFileSystem *pFileSystem,
        const char *pVMFFilename)
{
  this->m_pFilename = pVMFFilename;
  this->m_pFileSystem = pFileSystem;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_Entities.m_Memory.m_pMemory = nullptr;
  this->m_Entities.m_Memory.m_nAllocationCount = 0;
  this->m_Entities.m_Memory.m_nGrowSize = 0;
  this->m_Entities.m_Size = 0;
  this->m_Entities.m_pElements = nullptr;
  this->m_Brushes.m_Memory.m_pMemory = nullptr;
  this->m_Brushes.m_Memory.m_nAllocationCount = 0;
  this->m_Brushes.m_Memory.m_nGrowSize = 0;
  this->m_Brushes.m_Size = 0;
  this->m_Brushes.m_pElements = nullptr;
  this->m_Displacements.m_Memory.m_pMemory = nullptr;
  this->m_Displacements.m_Memory.m_nAllocationCount = 0;
  this->m_Displacements.m_Memory.m_nGrowSize = 0;
  this->m_Displacements.m_Size = 0;
  this->m_Displacements.m_pElements = nullptr;
  this->m_BrushSides.m_Memory.m_pMemory = nullptr;
  this->m_BrushSides.m_Memory.m_nAllocationCount = 0;
  this->m_BrushSides.m_Memory.m_nGrowSize = 0;
  this->m_BrushSides.m_Size = 0;
  this->m_BrushSides.m_pElements = nullptr;
  this->m_BrushTextures.m_Memory.m_pMemory = nullptr;
  this->m_BrushTextures.m_Memory.m_nAllocationCount = 0;
  this->m_BrushTextures.m_Memory.m_nGrowSize = 0;
  this->m_BrushTextures.m_Size = 0;
  this->m_BrushTextures.m_pElements = nullptr;
  this->m_TextureInfos.m_Memory.m_pMemory = nullptr;
  this->m_TextureInfos.m_Memory.m_nAllocationCount = 0;
  this->m_TextureInfos.m_Memory.m_nGrowSize = 0;
  this->m_TextureInfos.m_Size = 0;
  this->m_TextureInfos.m_pElements = nullptr;
  this->m_TextureData.m_Memory.m_pMemory = nullptr;
  this->m_TextureData.m_Memory.m_nAllocationCount = 0;
  this->m_TextureData.m_Memory.m_nGrowSize = 0;
  this->m_TextureData.m_Size = 0;
  this->m_TextureData.m_pElements = nullptr;
  this->m_nInstanceCount = 0;
  this->m_InstanceFlags = NO_FLAGS;
  this->m_KeyValuePairs.m_Memory.m_pMemory = nullptr;
  this->m_KeyValuePairs.m_Memory.m_nAllocationCount = 0;
  this->m_KeyValuePairs.m_Memory.m_nGrowSize = 0;
  this->m_KeyValuePairs.m_Size = 0;
  this->m_KeyValuePairs.m_pElements = nullptr;
  CStringPool::CStringPool(this: &this->m_KeyValueStringPool, caseSensitivity: StringPoolCaseInsensitive);
  this->m_nMapRevision = 0;
  this->m_nHighestID = 0;
  this->m_MaterialInfos.m_Memory.m_pMemory = nullptr;
  this->m_MaterialInfos.m_Memory.m_nAllocationCount = 0;
  this->m_MaterialInfos.m_Memory.m_nGrowSize = 0;
  this->m_MaterialInfos.m_Size = 0;
  this->m_MaterialInfos.m_pElements = nullptr;
  ClearBounds(mins: &this->m_vMinBounds, maxs: &this->m_vMaxBounds);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041FBF0
// Name: private: void CSimpleMapFile::MergeBrushSides(int,class CSimpleMapFile __near *,class Vector const __near &,class QAngle const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeBrushSides(
        CSimpleMapFile *this,
        int nEntityIndex,
        CSimpleMapFile *pInstanceMap,
        const Vector *vOrigin,
        const QAngle *orientation,
        const matrix3x4_t *transform)
{
  HashedPlane_t *m_pMemory; // ecx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  MapBrushSide_t *v10; // ecx
  int v11; // eax
  MapBrushSide_t *v12; // ebx
  MapBrushSide_t *v13; // ebx
  MapBrushSide_t *v14; // edi
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v15; // eax
  int m_nDisplacementIndex; // ebx
  CSimpleMapFile *v17; // eax
  MapEntity_t *v18; // edx
  int m_nNumBrushes; // ecx
  int v20; // ebx
  int *p_m_nNumSides; // eax
  int v22; // edx
  int v23; // ebx
  MapBrush_t *v24; // eax
  int m_nFirstSideIndex; // edx
  const HashedPlane_t *v26; // eax
  MapBrushTexture_t *NewBrushTexture; // ebx
  int v28; // esi
  CMapDisplacement *v29; // esi
  CMapDisplacement *v30; // eax
  CSimpleMapFile *v31; // eax
  int TextureInfoForBrushTexture; // eax
  Vector *v33; // [esp+0h] [ebp-7Ch]
  cplane_t outPlane; // [esp+10h] [ebp-6Ch] BYREF
  cplane_t inPlane; // [esp+24h] [ebp-58h] BYREF
  __int64 in1; // [esp+38h] [ebp-44h] BYREF
  float z; // [esp+40h] [ebp-3Ch]
  Vector vPosition; // [esp+44h] [ebp-38h] BYREF
  Vector vNormal; // [esp+50h] [ebp-2Ch] BYREF
  const HashedPlane_t *pInstancePlanes; // [esp+5Ch] [ebp-20h]
  float flDistance; // [esp+60h] [ebp-1Ch]
  unsigned int v42; // [esp+64h] [ebp-18h]
  CMapDisplacement::Vertex_t *m_nGrowSize; // [esp+68h] [ebp-14h]
  unsigned int v44; // [esp+6Ch] [ebp-10h]
  int i; // [esp+70h] [ebp-Ch]
  CSimpleMapFile *v46; // [esp+74h] [ebp-8h]
  bool bNeedsTransformation; // [esp+7Bh] [ebp-1h]

  m_pMemory = pInstanceMap->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
  v46 = this;
  pInstancePlanes = m_pMemory;
  i = 0;
  if ( pInstanceMap->m_BrushSides.m_Size > 0 )
  {
    v44 = 0;
    v42 = 0;
    do
    {
      m_Size = this->m_BrushSides.m_Size;
      m_nAllocationCount = this->m_BrushSides.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<MapBrushSide_t,int>::Grow(this: &this->m_BrushSides.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++this->m_BrushSides.m_Size;
      v10 = this->m_BrushSides.m_Memory.m_pMemory;
      v11 = this->m_BrushSides.m_Size - m_Size - 1;
      this->m_BrushSides.m_pElements = v10;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 44 * v11);
      v12 = &this->m_BrushSides.m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
      {
        v12->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
        v12->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
        v12->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
        v12->m_Polygon.m_Points.m_Size = 0;
        v12->m_Polygon.m_Points.m_pElements = nullptr;
        v12->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
      }
      memset(
        dst: (unsigned __int8 *)&this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1],
        value: 0,
        count: sizeof(this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1]));
      this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1].m_nDisplacementIndex = -1;
      v13 = &pInstanceMap->m_BrushSides.m_Memory.m_pMemory[v42 / 0x2C];
      v14 = &this->m_BrushSides.m_Memory.m_pMemory[this->m_BrushSides.m_Size - 1];
      v14->m_ContentsFlags = v13->m_ContentsFlags;
      v14->m_SurfaceFlags = v13->m_SurfaceFlags;
      v14->m_nPlaneIndex = v13->m_nPlaneIndex;
      v14->m_nTextureInfoIndex = v13->m_nTextureInfoIndex;
      if ( v13 == (MapBrushSide_t *)-16 )
        v15 = nullptr;
      else
        v15 = &v13->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: &v14->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
        other: v15);
      m_nDisplacementIndex = v13->m_nDisplacementIndex;
      v14->m_nDisplacementIndex = m_nDisplacementIndex;
      bNeedsTransformation = m_nDisplacementIndex != -1;
      if ( m_nDisplacementIndex == -1 )
      {
        v17 = pInstanceMap;
        v18 = pInstanceMap->m_Entities.m_Memory.m_pMemory;
        m_nNumBrushes = v18->m_nNumBrushes;
        v20 = 0;
        if ( m_nNumBrushes <= 0 )
        {
LABEL_19:
          v23 = v17->m_Brushes.m_Size;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v23;
          if ( m_nNumBrushes < v23 )
          {
            v24 = &v17->m_Brushes.m_Memory.m_pMemory[m_nNumBrushes];
            do
            {
              m_nFirstSideIndex = v24->m_nFirstSideIndex;
              if ( (v24->m_ContentsFlags & 0x20000000) != 0 )
              {
                if ( i >= m_nFirstSideIndex && i < m_nFirstSideIndex + v24->m_nNumSides )
                  goto LABEL_28;
                v23 = (int)m_nGrowSize;
              }
              ++m_nNumBrushes;
              ++v24;
            }
            while ( m_nNumBrushes < v23 );
          }
        }
        else
        {
          p_m_nNumSides = &pInstanceMap->m_Brushes.m_Memory.m_pMemory[v18->m_nFirstBrushIndex].m_nNumSides;
          while ( 1 )
          {
            v22 = *(p_m_nNumSides - 1);
            if ( i >= v22 && i < v22 + *p_m_nNumSides )
              break;
            ++v20;
            p_m_nNumSides += 9;
            if ( v20 >= m_nNumBrushes )
            {
              this = v46;
              v17 = pInstanceMap;
              goto LABEL_19;
            }
          }
          this = v46;
LABEL_28:
          bNeedsTransformation = true;
        }
      }
      v26 = &pInstancePlanes[v14->m_nPlaneIndex];
      vNormal = v26->m_vNormal;
      flDistance = pInstancePlanes[v14->m_nPlaneIndex].m_flDistance;
      NewBrushTexture = CSimpleMapFile::AllocateNewBrushTexture(this);
      MapBrushTexture_t::operator=(
        this: NewBrushTexture,
        __that: &pInstanceMap->m_BrushTextures.m_Memory.m_pMemory[v44 / 0xB0]);
      if ( bNeedsTransformation )
      {
        v28 = 0;
        if ( v14->m_Polygon.m_Points.m_Size > 0 )
        {
          m_nGrowSize = nullptr;
          do
          {
            v33 = (Vector *)((char *)v14->m_Polygon.m_Points.m_Memory.m_pMemory + (unsigned int)m_nGrowSize);
            vPosition = *v33;
            VectorTransform(in1: &vPosition.x, in2: transform, out: &v33->x);
            m_nGrowSize = (CMapDisplacement::Vertex_t *)((char *)m_nGrowSize + 12);
            ++v28;
          }
          while ( v28 < v14->m_Polygon.m_Points.m_Size );
        }
        inPlane.normal = vNormal;
        inPlane.dist = flDistance;
        VectorRotate(in1: &inPlane.normal.x, in2: transform, out: &outPlane.normal.x);
        outPlane.dist = (float)((float)((float)(transform->m_flMatVal[1][3] * outPlane.normal.y)
                                      + (float)(transform->m_flMatVal[0][3] * outPlane.normal.x))
                              + (float)(transform->m_flMatVal[2][3] * outPlane.normal.z))
                      + (float)((float)((float)((float)(outPlane.normal.x * outPlane.normal.x)
                                              + (float)(outPlane.normal.y * outPlane.normal.y))
                                      + (float)(outPlane.normal.z * outPlane.normal.z))
                              * inPlane.dist);
        v14->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(
                               this: &v46->m_PlaneHash,
                               vNormal: &outPlane.normal,
                               flDistance: outPlane.dist);
        VectorRotate(
          in1: &pInstanceMap->m_BrushTextures.m_Memory.m_pMemory[v44 / 0xB0].m_vUAxis.x,
          in2: transform,
          out: &NewBrushTexture->m_vUAxis.x);
        VectorRotate(
          in1: &pInstanceMap->m_BrushTextures.m_Memory.m_pMemory[v44 / 0xB0].m_vVAxis.x,
          in2: transform,
          out: &NewBrushTexture->m_vVAxis.x);
        NewBrushTexture->m_flShift[0] = NewBrushTexture->m_flShift[0]
                                      - (float)((float)((float)((float)(NewBrushTexture->m_vUAxis.y * vOrigin->y)
                                                              + (float)(vOrigin->x * NewBrushTexture->m_vUAxis.x))
                                                      + (float)(NewBrushTexture->m_vUAxis.z * vOrigin->z))
                                              / NewBrushTexture->m_flTextureWorldUnitsPerTexel[0]);
        this = v46;
        NewBrushTexture->m_flShift[1] = NewBrushTexture->m_flShift[1]
                                      - (float)((float)((float)((float)(NewBrushTexture->m_vVAxis.y * vOrigin->y)
                                                              + (float)(NewBrushTexture->m_vVAxis.x * vOrigin->x))
                                                      + (float)(NewBrushTexture->m_vVAxis.z * vOrigin->z))
                                              / NewBrushTexture->m_flTextureWorldUnitsPerTexel[1]);
        if ( v14->m_nDisplacementIndex != -1 )
        {
          CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
            this: &this->m_Displacements,
            elem: this->m_Displacements.m_Size);
          v29 = &this->m_Displacements.m_Memory.m_pMemory[this->m_Displacements.m_Size - 1];
          v30 = &pInstanceMap->m_Displacements.m_Memory.m_pMemory[v14->m_nDisplacementIndex];
          v29->m_nPower = v30->m_nPower;
          v29->m_nOriginalBrushSide = v30->m_nOriginalBrushSide;
          v29->m_nFlags = v30->m_nFlags;
          v29->m_ContentsFlags = v30->m_ContentsFlags;
          v29->m_vStartPosition.x = v30->m_vStartPosition.x;
          v29->m_vStartPosition.y = v30->m_vStartPosition.y;
          v29->m_vStartPosition.z = v30->m_vStartPosition.z;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_Vertices.m_Memory.m_nGrowSize;
          v29->m_Vertices.m_Memory.m_nGrowSize = v30->m_Vertices.m_Memory.m_nGrowSize;
          v30->m_Vertices.m_Memory.m_nGrowSize = (int)m_nGrowSize;
          m_nGrowSize = v29->m_Vertices.m_Memory.m_pMemory;
          v29->m_Vertices.m_Memory.m_pMemory = v30->m_Vertices.m_Memory.m_pMemory;
          v30->m_Vertices.m_Memory.m_pMemory = m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_Vertices.m_Memory.m_nAllocationCount;
          v29->m_Vertices.m_Memory.m_nAllocationCount = v30->m_Vertices.m_Memory.m_nAllocationCount;
          v30->m_Vertices.m_Memory.m_nAllocationCount = (int)m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_Vertices.m_Size;
          v29->m_Vertices.m_Size = v30->m_Vertices.m_Size;
          v30->m_Vertices.m_Size = (int)m_nGrowSize;
          m_nGrowSize = v29->m_Vertices.m_pElements;
          v29->m_Vertices.m_pElements = v30->m_Vertices.m_pElements;
          v30->m_Vertices.m_pElements = m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_TriangleTags.m_Memory.m_nGrowSize;
          v29->m_TriangleTags.m_Memory.m_nGrowSize = v30->m_TriangleTags.m_Memory.m_nGrowSize;
          v30->m_TriangleTags.m_Memory.m_nGrowSize = (int)m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_TriangleTags.m_Memory.m_pMemory;
          v29->m_TriangleTags.m_Memory.m_pMemory = v30->m_TriangleTags.m_Memory.m_pMemory;
          v30->m_TriangleTags.m_Memory.m_pMemory = (unsigned __int16 *)m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_TriangleTags.m_Memory.m_nAllocationCount;
          v29->m_TriangleTags.m_Memory.m_nAllocationCount = v30->m_TriangleTags.m_Memory.m_nAllocationCount;
          v30->m_TriangleTags.m_Memory.m_nAllocationCount = (int)m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_TriangleTags.m_Size;
          v29->m_TriangleTags.m_Size = v30->m_TriangleTags.m_Size;
          v30->m_TriangleTags.m_Size = (int)m_nGrowSize;
          m_nGrowSize = (CMapDisplacement::Vertex_t *)v29->m_TriangleTags.m_pElements;
          v29->m_TriangleTags.m_pElements = v30->m_TriangleTags.m_pElements;
          v30->m_TriangleTags.m_pElements = (unsigned __int16 *)m_nGrowSize;
          in1 = *(_QWORD *)&v29->m_vStartPosition.x;
          z = v29->m_vStartPosition.z;
          VectorTransform((float *)&in1, in2: transform, out: &v29->m_vStartPosition.x);
          v31 = v46;
          v29->m_nOriginalBrushSide = v46->m_BrushSides.m_Size - 1;
          v14->m_nDisplacementIndex = v31->m_Displacements.m_Size - 1;
          this = v31;
        }
      }
      else
      {
        v14->m_nPlaneIndex = CPlaneHash::FindPlaneIndex(this: &this->m_PlaneHash, &vNormal, flDistance);
      }
      TextureInfoForBrushTexture = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                     this,
                                     pBrushTexture: NewBrushTexture,
                                     vRelativeOrigin: &vec3_origin);
      v42 += 44;
      v44 += 176;
      v14->m_nTextureInfoIndex = TextureInfoForBrushTexture;
      ++i;
    }
    while ( i < pInstanceMap->m_BrushSides.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420170
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::SolidChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CSimpleMapFile::SolidChunkHandler(CChunkFile *pFile, int *pData)
{
  CSimpleMapFile *v3; // ecx
  int v4; // edi
  MapBrush_t *NewBrush; // esi
  CSimpleMapFile *v6; // eax
  _DWORD *v7; // ebx
  int j; // eax
  int v10; // ecx
  int m_nFirstSideIndex; // edx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // edi
  MapBrushSide_t *v15; // ecx
  int m_nDisplacementIndex; // eax
  _DWORD *v17; // edi
  CMapDisplacement *v18; // eax
  int v19; // eax
  BrushSideLoadingInfo_t brushSideLoadingInfo; // [esp+Ch] [ebp-104h] BYREF
  CMapDisplacement *pDisplacement; // [esp+F0h] [ebp-20h]
  int nContainingEntityIndex; // [esp+F4h] [ebp-1Ch]
  MapBrushSide_t *pSide; // [esp+F8h] [ebp-18h]
  CChunkHandlerMap solidChunkHandlers; // [esp+FCh] [ebp-14h] BYREF
  int k; // [esp+108h] [ebp-8h]
  int i; // [esp+10Ch] [ebp-4h]
  ChunkFileResult_t bHasDisplacements; // [esp+11Ch] [ebp+Ch]
  char bHasDisplacements_3; // [esp+11Fh] [ebp+Fh]

  v3 = (CSimpleMapFile *)*pData;
  v4 = *(_DWORD *)(*pData + 4140) - 1;
  nContainingEntityIndex = v4;
  NewBrush = CSimpleMapFile::AllocateNewBrush(this: v3);
  NewBrush->m_nFirstSideIndex = *(_DWORD *)(*pData + 4200);
  NewBrush->m_nNumSides = 0;
  *(_QWORD *)&brushSideLoadingInfo.m_pBrush = 0;
  memset(
    dst: (unsigned __int8 *)&brushSideLoadingInfo.m_Texture,
    value: 0,
    count: sizeof(brushSideLoadingInfo.m_Texture));
  v6 = (CSimpleMapFile *)*pData;
  brushSideLoadingInfo.m_BaseContentsFlags = pData[2];
  brushSideLoadingInfo.m_pMapFile = v6;
  brushSideLoadingInfo.m_pBrush = NewBrush;
  CExpressionEvaluator::CExpressionEvaluator(this: &solidChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &solidChunkHandlers,
    pszChunkName: "side",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::SideChunkHandler,
    pData: &brushSideLoadingInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &solidChunkHandlers);
  bHasDisplacements = CChunkFile::ReadChunk(
                        this: pFile,
                        pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))_wcsdup,
                        pData: (void *)NewBrush);
  CChunkFile::PopHandlers(this: pFile);
  if ( bHasDisplacements != ChunkFile_Ok )
  {
    v7 = (_DWORD *)*pData;
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 3,
        a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
        "Error parsing brush/solid.",
        v7[1035] - 1,
        v7[1040] - 1,
        v7[1050] - 1);
    CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
    return bHasDisplacements;
  }
  else
  {
    NewBrush->m_ContentsFlags = CSimpleMapFile::ComputeBrushContents(this: (CSimpleMapFile *)*pData, pBrush: NewBrush);
    CSimpleMapFile::MakeBrushPolygons(this: (CSimpleMapFile *)*pData, pBrush: (int)NewBrush);
    if ( v4 == 0 && (NewBrush->m_ContentsFlags & 0x30000) != 0 )
    {
      for ( j = 0; j < NewBrush->m_nNumSides; *(_DWORD *)(v10 + *(_DWORD *)(*pData + 4188) + 12) = -1 )
      {
        v10 = 44 * (j + NewBrush->m_nFirstSideIndex);
        ++j;
      }
    }
    if ( (NewBrush->m_ContentsFlags & 0x1000000) != 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Origin brushes not currently supported.\n");
      CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
      return 9;
    }
    else
    {
      m_nFirstSideIndex = NewBrush->m_nFirstSideIndex;
      v12 = m_nFirstSideIndex + NewBrush->m_nNumSides;
      bHasDisplacements_3 = 0;
      i = m_nFirstSideIndex;
      if ( m_nFirstSideIndex >= v12 )
        goto LABEL_29;
      v13 = 44 * m_nFirstSideIndex;
      for ( k = 44 * m_nFirstSideIndex; ; v13 = k )
      {
        v14 = (_DWORD *)*pData;
        v15 = (MapBrushSide_t *)(v13 + *(_DWORD *)(*pData + 4188));
        m_nDisplacementIndex = v15->m_nDisplacementIndex;
        pSide = v15;
        if ( m_nDisplacementIndex != -1 )
        {
          bHasDisplacements_3 = 1;
          pDisplacement = (CMapDisplacement *)(v14[1042] + 68 * m_nDisplacementIndex);
          if ( nContainingEntityIndex != 0 )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
              _LoggingSystem_Log(
                a1: LOG_VBSP2,
                a2: 3,
                a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
                "Displacements not supported on entities.",
                v14[1035] - 1,
                v14[1040] - 1,
                v14[1050] - 1);
            v15 = pSide;
          }
          m_nFirstSideIndex = i;
          if ( v15->m_Polygon.m_Points.m_Size != 4 )
          {
            v17 = (_DWORD *)*pData;
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
              _LoggingSystem_Log(
                a1: LOG_VBSP2,
                a2: 3,
                a3: "%s\n(Entity %i, Brush %i, Side %i)\n",
                "Displacement faces must have 4 sides.",
                v17[1035] - 1,
                v17[1040] - 1,
                v17[1050] - 1);
            m_nFirstSideIndex = i;
          }
          v18 = pDisplacement;
          pDisplacement->m_nOriginalBrushSide = m_nFirstSideIndex;
          v18->m_ContentsFlags = NewBrush->m_ContentsFlags;
        }
        v19 = NewBrush->m_nFirstSideIndex + NewBrush->m_nNumSides;
        k += 44;
        i = ++m_nFirstSideIndex;
        if ( m_nFirstSideIndex >= v19 )
          break;
      }
      if ( bHasDisplacements_3 != 0 )
      {
        --*(_DWORD *)(*pData + 4160);
        CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
        return 0;
      }
      else
      {
LABEL_29:
        ++*(_DWORD *)(pData[1] + 16);
        CChunkHandlerMap::~CChunkHandlerMap(this: &solidChunkHandlers);
        return 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420480
// Name: private: void CSimpleMapFile::MergeInstance(int,class CSimpleMapFile __near *,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::MergeInstance(
        CSimpleMapFile *this,
        int nEntityIndex,
        CSimpleMapFile *pInstanceMap,
        GameData *pGameData)
{
  MapEntity_t *v5; // eax
  int m_nNumKVPairs; // ebx
  MapEntityKeyValuePair_t *v7; // eax
  int v8; // edi
  MapEntityKeyValuePair_t *v9; // eax
  const char *m_pValue; // eax
  matrix3x4_t instanceTransform; // [esp+8h] [ebp-50h] BYREF
  Vector vInstanceOrigin; // [esp+38h] [ebp-20h] BYREF
  QAngle instanceAngles; // [esp+44h] [ebp-14h] BYREF
  MapEntityKeyValuePair_t *v14; // [esp+50h] [ebp-8h]
  const char **p_m_pKey; // [esp+54h] [ebp-4h]

  v5 = &this->m_Entities.m_Memory.m_pMemory[nEntityIndex];
  vInstanceOrigin = v5->m_vOrigin;
  m_nNumKVPairs = v5->m_nNumKVPairs;
  v7 = &this->m_KeyValuePairs.m_Memory.m_pMemory[v5->m_nFirstKVPairIndex];
  v8 = 0;
  v14 = v7;
  if ( m_nNumKVPairs <= 0 )
    goto LABEL_8;
  p_m_pKey = &v7->m_pKey;
  while ( _V_stricmp(s1: *p_m_pKey, s2: "angles") != 0 )
  {
    p_m_pKey += 3;
    if ( ++v8 >= m_nNumKVPairs )
      goto LABEL_8;
  }
  v9 = &v14[v8];
  if ( v9 == nullptr || (m_pValue = v9->m_pValue) == nullptr )
LABEL_8:
    m_pValue = defaultValue;
  sscanf(string: m_pValue, format: "%f %f %f", &instanceAngles, &instanceAngles.y, &instanceAngles.z);
  AngleMatrix(angles: &instanceAngles, position: &vInstanceOrigin, matrix: &instanceTransform);
  ++this->m_nInstanceCount;
  GameData::BeginMapInstance(this: pGameData);
  CSimpleMapFile::MergeBrushes(
    this,
    nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: &instanceTransform);
  CSimpleMapFile::MergeBrushSides(
    this,
    nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: &instanceTransform);
  CSimpleMapFile::MergeEntities(
    this,
    (MapEntityKeyValuePair_t *)nEntityIndex,
    pInstanceMap,
    vOrigin: &vInstanceOrigin,
    orientation: &instanceAngles,
    transform: &instanceTransform,
    pGameData);
}

//------------------------------------------------------------------------------
// Address: 0x004205A0
// Name: private: static enum ChunkFileResult_t CSimpleMapFile::EntityChunkHandler(class CChunkFile __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CSimpleMapFile::EntityChunkHandler(CChunkFile *pFile, CSimpleMapFile *pData)
{
  MapEntity_t *NewEntity; // edi
  int v5; // esi
  MapBrush_t *m_pMemory; // ecx
  bool v7; // cc
  MapBrush_t *v8; // eax
  float x; // xmm1_4
  int v10; // esi
  int v11; // edx
  HashedPlane_t *v12; // eax
  float v13; // xmm1_4
  float z; // xmm0_4
  int TextureInfoForBrushTexture; // eax
  MapBrush_t *v16; // ecx
  Vector vNormal; // [esp+10h] [ebp-2Ch] BYREF
  CChunkHandlerMap entityChunkHandlers; // [esp+1Ch] [ebp-20h] BYREF
  EntityLoadingInfo_t entityLoadingInfo; // [esp+28h] [ebp-14h] BYREF
  int i; // [esp+34h] [ebp-8h]
  MapBrush_t *pBrush; // [esp+38h] [ebp-4h]
  ChunkFileResult_t j; // [esp+48h] [ebp+Ch]
  int ja; // [esp+48h] [ebp+Ch]

  NewEntity = CSimpleMapFile::AllocateNewEntity(this: pData);
  NewEntity->m_nFirstBrushIndex = pData->m_Brushes.m_Size;
  NewEntity->m_nNumBrushes = 0;
  NewEntity->m_nFirstKVPairIndex = pData->m_KeyValuePairs.m_Size;
  NewEntity->m_nNumKVPairs = 0;
  entityLoadingInfo.m_BaseContentsFlags = 0;
  entityLoadingInfo.m_pMapFile = pData;
  entityLoadingInfo.m_pEntity = NewEntity;
  CExpressionEvaluator::CExpressionEvaluator(this: &entityChunkHandlers);
  CChunkHandlerMap::AddHandler(
    this: &entityChunkHandlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::SolidChunkHandler,
    pData: &entityLoadingInfo);
  CChunkHandlerMap::AddHandler(
    this: &entityChunkHandlers,
    pszChunkName: "connections",
    pfnHandler: CSimpleMapFile::ConnectionsChunkHandler,
    pData: &entityLoadingInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &entityChunkHandlers);
  j = CChunkFile::ReadChunk(
        this: pFile,
        pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))CSimpleMapFile::EntityKeyHandler,
        pData: &entityLoadingInfo);
  CChunkFile::PopHandlers(this: pFile);
  if ( j == ChunkFile_NotHandled )
  {
    --pData->m_Entities.m_Size;
    CChunkHandlerMap::~CChunkHandlerMap(this: &entityChunkHandlers);
    return ChunkFile_Ok;
  }
  else if ( j != ChunkFile_Ok )
  {
    CSimpleMapFile::ReportParseError(this: pData, pErrorString: "Error parsing entity.");
    CChunkHandlerMap::~CChunkHandlerMap(this: &entityChunkHandlers);
    return j;
  }
  else
  {
    if ( NewEntity->m_vOrigin.x != 0.0 || NewEntity->m_vOrigin.y != 0.0 || NewEntity->m_vOrigin.z != 0.0 )
    {
      v5 = 0;
      for ( i = 0; v5 < NewEntity->m_nNumBrushes; i = v5 )
      {
        m_pMemory = pData->m_Brushes.m_Memory.m_pMemory;
        v7 = m_pMemory[v5 + NewEntity->m_nFirstBrushIndex].m_nNumSides <= 0;
        v8 = &m_pMemory[v5 + NewEntity->m_nFirstBrushIndex];
        pBrush = v8;
        ja = 0;
        if ( !v7 )
        {
          do
          {
            x = NewEntity->m_vOrigin.x;
            v10 = (int)&pData->m_BrushSides.m_Memory.m_pMemory[ja + v8->m_nFirstSideIndex];
            v11 = *(_DWORD *)(v10 + 8);
            v12 = pData->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
            *(_QWORD *)&vNormal.x = *(_QWORD *)&v12[*(_DWORD *)(v10 + 8)].m_vNormal.x;
            v13 = (float)(x * vNormal.x) + (float)(NewEntity->m_vOrigin.y * vNormal.y);
            z = NewEntity->m_vOrigin.z;
            vNormal.z = v12[v11].m_vNormal.z;
            *(_DWORD *)(v10 + 8) = CPlaneHash::FindPlaneIndex(
                                     this: &pData->m_PlaneHash,
                                     &vNormal,
                                     flDistance: v12[v11].m_flDistance - (float)(v13 + (float)(z * vNormal.z)));
            TextureInfoForBrushTexture = CSimpleMapFile::GetTextureInfoForBrushTexture(
                                           this: pData,
                                           pBrushTexture: &pData->m_BrushTextures.m_Memory.m_pMemory[ja + pBrush->m_nFirstSideIndex],
                                           vRelativeOrigin: &NewEntity->m_vOrigin);
            v16 = pBrush;
            *(_DWORD *)(v10 + 12) = TextureInfoForBrushTexture;
            v7 = ++ja < v16->m_nNumSides;
            v8 = v16;
          }
          while ( v7 );
          v5 = i;
        }
        CSimpleMapFile::MakeBrushPolygons(this: pData, pBrush: (int)v8);
        ++v5;
      }
    }
    if ( (entityLoadingInfo.m_BaseContentsFlags & 0x8000000) != 0 )
      CSimpleMapFile::MoveEntityBrushesToWorld(this: pData, nEntityIndex: pData->m_Entities.m_Size - 1);
    CChunkHandlerMap::~CChunkHandlerMap(this: &entityChunkHandlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004207D0
// Name: public: static void CSimpleMapFile::LoadFromFile(class IFileSystem __near *,char const __near *,class CSimpleMapFile __near * __near *,enum CSimpleMapFile::ResolveInstanceFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSimpleMapFile::LoadFromFile(
        IFileSystem *pFileSystem,
        const char *pVMFFilename,
        CSimpleMapFile **ppNewMapFile,
        CSimpleMapFile::ResolveInstanceFlags_t instanceFlags)
{
  ChunkFileResult_t v4; // edi
  const char *ErrorText; // eax
  CSimpleMapFile *v6; // eax
  CSimpleMapFile *v7; // eax
  ChunkFileResult_t v8; // edi
  const char *v9; // eax
  int v10; // ebx
  int v11; // edi
  MapBrush_t *m_pMemory; // ecx
  float x; // xmm0_4
  const Vector *p_m_vMinBounds; // ecx
  int v15; // edi
  MapBrush_t *v16; // eax
  int m_Size; // ecx
  CChunkFile chunkFile; // [esp+Ch] [ebp-350h] BYREF
  CChunkHandlerMap VMFChunkHandlers; // [esp+350h] [ebp-Ch] BYREF

  CChunkFile::CChunkFile(this: &chunkFile);
  v4 = CChunkFile::Open(this: &chunkFile, pszFileName: pVMFFilename, eMode: ChunkFile_Read);
  *ppNewMapFile = nullptr;
  if ( v4 != ChunkFile_Ok )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    {
      ErrorText = CChunkFile::GetErrorText(this: &chunkFile, eResult: v4);
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error opening %s: %s.\n", pVMFFilename, ErrorText);
      CChunkFile::~CChunkFile(this: &chunkFile);
      return;
    }
  }
  else
  {
    v6 = (CSimpleMapFile *)operator new(nSize: 0x1118u);
    if ( v6 != nullptr )
      v7 = CSimpleMapFile::CSimpleMapFile(this: v6, pFileSystem, pVMFFilename);
    else
      v7 = nullptr;
    *ppNewMapFile = v7;
    v7->m_InstanceFlags = instanceFlags;
    CExpressionEvaluator::CExpressionEvaluator(this: &VMFChunkHandlers);
    CChunkHandlerMap::AddHandler(
      this: &VMFChunkHandlers,
      pszChunkName: "world",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::EntityChunkHandler,
      pData: *ppNewMapFile);
    CChunkHandlerMap::AddHandler(
      this: &VMFChunkHandlers,
      pszChunkName: "entity",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CSimpleMapFile::EntityChunkHandler,
      pData: *ppNewMapFile);
    CChunkFile::PushHandlers(this: &chunkFile, pHandlerMap: &VMFChunkHandlers);
    do
      v8 = CChunkFile::ReadChunk(this: &chunkFile, pfnKeyHandler: nullptr, pData: nullptr);
    while ( v8 == ChunkFile_Ok );
    CChunkFile::PopHandlers(this: &chunkFile);
    CChunkFile::Close(this: &chunkFile);
    if ( v8 == ChunkFile_EOF )
    {
      if ( (*ppNewMapFile)->m_Entities.m_Size != 0 )
      {
        v10 = 0;
        if ( (*ppNewMapFile)->m_Entities.m_Memory.m_pMemory->m_nNumBrushes > 0 )
        {
          v11 = 0;
          do
          {
            m_pMemory = (*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory;
            x = m_pMemory[v11].m_vMinBounds.x;
            p_m_vMinBounds = &m_pMemory[v11].m_vMinBounds;
            if ( x <= 16384.0 )
            {
              AddPointToBounds(
                v: p_m_vMinBounds,
                mins: &(*ppNewMapFile)->m_vMinBounds,
                maxs: &(*ppNewMapFile)->m_vMaxBounds);
              AddPointToBounds(
                v: &(*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory[v11].m_vMaxBounds,
                mins: &(*ppNewMapFile)->m_vMinBounds,
                maxs: &(*ppNewMapFile)->m_vMaxBounds);
            }
            ++v10;
            ++v11;
          }
          while ( v10 < (*ppNewMapFile)->m_Entities.m_Memory.m_pMemory->m_nNumBrushes );
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(a1: LOG_VBSP2, a2: 0, a3: "VBSP2: Done processing map file.\n");
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(
            a1: LOG_VBSP2,
            a2: 0,
            a3: "Entities: %d\nBrushes: %d\nBrush Sides: %d\nPlanes: %d\nDisplacements: %d\n",
            (*ppNewMapFile)->m_Entities.m_Size,
            (*ppNewMapFile)->m_Brushes.m_Size,
            (*ppNewMapFile)->m_BrushSides.m_Size,
            (*ppNewMapFile)->m_PlaneHash.m_Planes.m_Size,
            (*ppNewMapFile)->m_Displacements.m_Size);
        v15 = 0;
        if ( (*ppNewMapFile)->m_Brushes.m_Size > 0 )
        {
          v16 = (*ppNewMapFile)->m_Brushes.m_Memory.m_pMemory;
          m_Size = (*ppNewMapFile)->m_Brushes.m_Size;
          do
          {
            if ( (v16->m_ContentsFlags & 0x8000000) != 0 )
              ++v15;
            ++v16;
            --m_Size;
          }
          while ( m_Size != 0 );
        }
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
          _LoggingSystem_Log(
            a1: LOG_VBSP2,
            a2: 0,
            a3: "Detail brushes: %d\nNon-detail brushes: %d\n",
            v15,
            (*ppNewMapFile)->m_Brushes.m_Size - v15);
      }
      else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      {
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Did not successfully parse world entity.\n");
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    {
      v9 = CChunkFile::GetErrorText(this: &chunkFile, eResult: v8);
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Error reading %s: %s.\n", pVMFFilename, v9);
    }
    CChunkHandlerMap::~CChunkHandlerMap(this: &VMFChunkHandlers);
  }
  CChunkFile::~CChunkFile(this: &chunkFile);
}

//------------------------------------------------------------------------------
// Address: 0x00420AE0
// Name: public: bool CSimpleMapFile::ResolveInstances(enum CSimpleMapFile::ResolveInstanceFlags_t,void (*)(void __near *,class CSimpleMapFile __near *,struct MapEntityKeyValuePair_t __near *,int),void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSimpleMapFile::ResolveInstances(
        CSimpleMapFile *this,
        CSimpleMapFile::ResolveInstanceFlags_t instanceFlags,
        void (__cdecl *pPostLoadInstanceHandler)(void *, CSimpleMapFile *, MapEntityKeyValuePair_t *, int),
        void *pHandlerContext)
{
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  IBaseFileSystem *v7; // eax
  char *String; // eax
  char *v10; // esi
  MapEntity_t *v11; // eax
  int m_nNumKVPairs; // ebx
  CSimpleMapFile *v13; // ecx
  int v14; // esi
  char *v15; // eax
  const char *v16; // eax
  int v17; // ebx
  int v18; // esi
  MapEntityKeyValuePair_t *v19; // ebx
  char *v20; // eax
  const char *v21; // esi
  CSimpleMapFile *v22; // esi
  unsigned int v23; // eax
  IFileSystem *m_pFileSystem; // [esp-14h] [ebp-584h]
  char gameDataFilePath[260]; // [esp+8h] [ebp-568h] BYREF
  char resolvedInstancePath[260]; // [esp+10Ch] [ebp-464h] BYREF
  char gameInfoPath[260]; // [esp+210h] [ebp-360h] BYREF
  char fixedInstanceDirectory[260]; // [esp+314h] [ebp-25Ch] BYREF
  GameData gameDataFile; // [esp+418h] [ebp-158h] BYREF
  int i; // [esp+560h] [ebp-10h]
  unsigned int v31; // [esp+564h] [ebp-Ch]
  CSimpleMapFile *pInstanceMapFile; // [esp+568h] [ebp-8h] BYREF
  const char **v33; // [esp+56Ch] [ebp-4h]

  if ( this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: "gameinfo.txt",
         a3: "MOD",
         a4: gameInfoPath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to find gameinfo.txt; required to look up InstancePath.\n");
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: gameInfoPath);
  else
    v6 = nullptr;
  if ( this->m_pFileSystem != nullptr )
    v7 = &this->m_pFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v6,
          filesystem: v7,
          resourceName: gameInfoPath,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load gameinfo.txt; required to look up InstancePath.\n");
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  String = KeyValues::GetString(this: v6, keyName: "InstancePath", defaultValue: nullptr);
  if ( String != nullptr )
  {
    V_strncpy(pDest: fixedInstanceDirectory, pSrc: String, maxLen: 260);
    _V_strlower(start: fixedInstanceDirectory);
    V_FixSlashes(pname: fixedInstanceDirectory, separator: 92);
  }
  else
  {
    fixedInstanceDirectory[0] = 0;
  }
  v10 = KeyValues::GetString(this: v6, keyName: "GameData", defaultValue: nullptr);
  if ( v10 == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load GameData key in %s.\n", gameInfoPath);
LABEL_24:
    KeyValues::deleteThis(this: v6);
    return 0;
  }
  if ( this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: v10,
         a3: "EXECUTABLE_PATH",
         a4: gameDataFilePath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr
    && this->m_pFileSystem->RelativePathToFullPath(
         this: this->m_pFileSystem,
         a2: v10,
         a3: defaultValue,
         a4: gameDataFilePath,
         a5: 260,
         a6: 0,
         a7: 0) == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Could not find GameData file %s.\n", v10);
    goto LABEL_24;
  }
  KeyValues::deleteThis(this: v6);
  GameData::GameData(this: &gameDataFile);
  GameData::Load(this: &gameDataFile, pszFilename: gameDataFilePath);
  CSimpleMapFile::PreLoadInstances(this, pGD: &gameDataFile);
  GameData::BeginInstancing(this: &gameDataFile, nPass: 1);
  i = 0;
  if ( this->m_Entities.m_Size <= 0 )
  {
LABEL_51:
    GameData::~GameData(this: &gameDataFile);
    return 1;
  }
  v31 = 0;
  while ( 1 )
  {
    v11 = &this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C];
    m_nNumKVPairs = v11->m_nNumKVPairs;
    v13 = (CSimpleMapFile *)&this->m_KeyValuePairs.m_Memory.m_pMemory[v11->m_nFirstKVPairIndex];
    v14 = 0;
    pInstanceMapFile = v13;
    if ( m_nNumKVPairs <= 0 )
      goto LABEL_34;
    v33 = (const char **)v13;
    while ( _V_stricmp(s1: *v33, s2: "classname") != 0 )
    {
      v33 += 3;
      if ( ++v14 >= m_nNumKVPairs )
        goto LABEL_34;
    }
    v15 = (char *)pInstanceMapFile + 12 * v14;
    if ( v15 == nullptr || (v16 = *((const char **)v15 + 1)) == nullptr )
LABEL_34:
      v16 = defaultValue;
    if ( _V_stricmp(s1: v16, s2: "func_instance") != 0 )
      goto LABEL_50;
    v17 = this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumKVPairs;
    v18 = 0;
    if ( v17 > 0 )
    {
      v33 = (const char **)pInstanceMapFile;
      while ( _V_stricmp(s1: *v33, s2: "file") != 0 )
      {
        v33 += 3;
        if ( ++v18 >= v17 )
          goto LABEL_49;
      }
      v19 = (MapEntityKeyValuePair_t *)pInstanceMapFile;
      v20 = (char *)pInstanceMapFile + 12 * v18;
      if ( v20 != nullptr )
      {
        v21 = *((const char **)v20 + 1);
        if ( v21 != nullptr && *v21 != 0 )
          break;
      }
    }
LABEL_49:
    v23 = v31;
    this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumBrushes = 0;
    *(int *)((char *)&this->m_Entities.m_Memory.m_pMemory->m_nNumKVPairs + v23) = 0;
LABEL_50:
    v31 += 28;
    if ( ++i >= this->m_Entities.m_Size )
      goto LABEL_51;
  }
  if ( CInstancingHelper::ResolveInstancePath(
         pFileSystem: g_pFullFileSystem,
         pBaseFilename: this->m_pFilename,
         pInstanceFilename: v21,
         pInstanceDirectory: fixedInstanceDirectory,
         pResolvedInstanceFilename: resolvedInstancePath,
         nBufferSize: (const char *)0x104) != 0 )
  {
    m_pFileSystem = this->m_pFileSystem;
    pInstanceMapFile = nullptr;
    CSimpleMapFile::LoadFromFile(
      pFileSystem: m_pFileSystem,
      pVMFFilename: resolvedInstancePath,
      ppNewMapFile: &pInstanceMapFile,
      instanceFlags);
    v22 = pInstanceMapFile;
    if ( pInstanceMapFile == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
        _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Failed to load instance file %s.\n", resolvedInstancePath);
      goto LABEL_56;
    }
    if ( pPostLoadInstanceHandler != nullptr )
      pPostLoadInstanceHandler(
        a1: pHandlerContext,
        a2: pInstanceMapFile,
        a3: v19,
        a4: this->m_Entities.m_Memory.m_pMemory[v31 / 0x1C].m_nNumKVPairs);
    CSimpleMapFile::MergeInstance(this, nEntityIndex: i, pInstanceMap: v22, pGameData: &gameDataFile);
    CSimpleMapFile::~CSimpleMapFile(this: v22);
    free(pMem: v22);
    goto LABEL_49;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Could not find instance %s.\n", v21);
LABEL_56:
  GameData::~GameData(this: &gameDataFile);
  return 0;
}

} // namespace vbsp2
