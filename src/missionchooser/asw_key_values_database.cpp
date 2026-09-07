// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_key_values_database.cpp
// Functions: 7
// ============================================================

#include "missionchooser\asw_key_values_database.h"

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: public: void CUtlMemory<struct CASW_KeyValuesDatabase::FileEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CASW_KeyValuesDatabase::FileEntry_t,int>::Grow(
        CUtlMemory<CASW_KeyValuesDatabase::FileEntry_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CASW_KeyValuesDatabase::FileEntry_t *m_pMemory; // edx
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
    v7 = 264 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CASW_KeyValuesDatabase::FileEntry_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (CASW_KeyValuesDatabase::FileEntry_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: public: class KeyValues __near * CASW_KeyValuesDatabase::GetFileByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_KeyValuesDatabase::GetFileByName(CASW_KeyValuesDatabase *this, const char *pFilename)
{
  int v3; // edi
  int i; // ebx

  v3 = 0;
  if ( this->m_Files.m_Size <= 0 )
    return nullptr;
  for ( i = 0; _V_stricmp(s1: pFilename, s2: this->m_Files.m_Memory.m_pMemory[i].m_Filename) != 0; ++i )
  {
    if ( ++v3 >= this->m_Files.m_Size )
      return nullptr;
  }
  return this->m_Files.m_Memory.m_pMemory[v3].m_pKeyValues;
}

//------------------------------------------------------------------------------
// Address: 0x10001130
// Name: public: class KeyValues __near * CASW_KeyValuesDatabase::ReloadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_KeyValuesDatabase::ReloadFile(CASW_KeyValuesDatabase *this, const char *pFilename)
{
  int v3; // edi
  int i; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  IBaseFileSystem *v8; // eax
  int v9; // edi

  v3 = 0;
  if ( this->m_Files.m_Size > 0 )
  {
    for ( i = 0; _V_stricmp(s1: pFilename, s2: this->m_Files.m_Memory.m_pMemory[i].m_Filename) != 0; ++i )
    {
      if ( ++v3 >= this->m_Files.m_Size )
        return nullptr;
    }
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: pFilename);
    else
      v7 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v8 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v8 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v7,
           filesystem: v8,
           resourceName: pFilename,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      v9 = v3;
      KeyValues::deleteThis(this: this->m_Files.m_Memory.m_pMemory[v9].m_pKeyValues);
      this->m_Files.m_Memory.m_pMemory[v9].m_pKeyValues = v7;
      return v7;
    }
    _Warning(a1: "Error: failed to reload file: %s\n", pFilename);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: public: CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CASW_KeyValuesDatabase *__thiscall CASW_KeyValuesDatabase::CASW_KeyValuesDatabase(CASW_KeyValuesDatabase *this)
{
  this->m_Files.m_Memory.m_pMemory = nullptr;
  this->m_Files.m_Memory.m_nAllocationCount = 0;
  this->m_Files.m_Memory.m_nGrowSize = 0;
  this->m_Files.m_Size = 0;
  this->m_Files.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: void CASW_KeyValuesDatabase::AddFile(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_KeyValuesDatabase::AddFile(
        CASW_KeyValuesDatabase *this,
        KeyValues *pKeyValues,
        const char *pFilename)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CASW_KeyValuesDatabase::FileEntry_t *m_pMemory; // ecx
  int v7; // eax
  CASW_KeyValuesDatabase::FileEntry_t *v8; // esi
  int v9; // eax

  m_nAllocationCount = this->m_Files.m_Memory.m_nAllocationCount;
  m_Size = this->m_Files.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CASW_KeyValuesDatabase::FileEntry_t,int>::Grow(
      this: &this->m_Files.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Files.m_Size;
  m_pMemory = this->m_Files.m_Memory.m_pMemory;
  v7 = this->m_Files.m_Size - m_Size - 1;
  this->m_Files.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 264 * v7);
  v8 = &this->m_Files.m_Memory.m_pMemory[this->m_Files.m_Size - 1];
  V_strncpy(pDest: v8->m_Filename, pSrc: pFilename, maxLen: 260);
  V_FixSlashes(pname: v8->m_Filename, separator: 92);
  v8->m_pKeyValues = pKeyValues;
  v9 = _V_strlen(str: this->m_RootFolder);
  KeyValues::SetString(this: pKeyValues, keyName: "Filename", value: &v8->m_Filename[v9]);
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: private: void CASW_KeyValuesDatabase::LoadFilesInFolder(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_KeyValuesDatabase::LoadFilesInFolder(CASW_KeyValuesDatabase *this, const char *pPath)
{
  const char *i; // esi
  const char *FileExtension; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  char mapwild[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char fullFileName[260]; // [esp+110h] [ebp-108h] BYREF
  int tagsfind; // [esp+214h] [ebp-4h] BYREF

  tagsfind = -1;
  V_snprintf(pDest: mapwild, maxLen: 260, pFormat: "%s*", pPath);
  for ( i = Sys_FindFirst(searchhandle: &tagsfind, path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(searchhandle: &tagsfind, basename: nullptr, namelength: 0) )
  {
    if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: tagsfind) )
    {
      if ( _V_strcmp(s1: i, s2: ".") != 0 && _V_strcmp(s1: i, s2: "..") != 0 )
      {
        V_snprintf(pDest: fullFileName, maxLen: 260, pFormat: "%s%s/", pPath, i);
        CASW_KeyValuesDatabase::LoadFilesInFolder(this, pPath: fullFileName);
      }
    }
    else
    {
      FileExtension = V_GetFileExtension(path: i);
      if ( FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "txt") == 0 )
      {
        V_snprintf(pDest: &fullFileName[4], maxLen: 256, pFormat: "%s%s", pPath, i);
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: i);
        else
          v6 = nullptr;
        if ( g_pFullFileSystem != nullptr )
          v7 = &g_pFullFileSystem->IBaseFileSystem;
        else
          v7 = nullptr;
        if ( KeyValues::LoadFromFile(
               this: v6,
               filesystem: v7,
               resourceName: &fullFileName[4],
               pathID: "GAME",
               pfnEvaluateSymbolProc: nullptr) )
        {
          CASW_KeyValuesDatabase::AddFile(this, pKeyValues: v6, pFilename: &fullFileName[4]);
        }
        else
        {
          _Msg(a1: "Error: failed to load file: %s\n", &fullFileName[4]);
        }
      }
    }
  }
  Sys_FindClose(searchhandle: &tagsfind);
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: void CASW_KeyValuesDatabase::LoadFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_KeyValuesDatabase::LoadFiles(CASW_KeyValuesDatabase *this, const char *pFolderName)
{
  if ( !CASW_KeyValuesDatabase::m_bLoadedLocalization )
  {
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "tilegen/missions_%language%.txt", a3: nullptr, a4: false);
    CASW_KeyValuesDatabase::m_bLoadedLocalization = true;
  }
  this->m_Files.m_Size = 0;
  V_strncpy(pDest: this->m_RootFolder, pSrc: pFolderName, maxLen: 260);
  _V_strlen(str: this->m_RootFolder);
  CASW_KeyValuesDatabase::LoadFilesInFolder(this, pPath: this->m_RootFolder);
}
