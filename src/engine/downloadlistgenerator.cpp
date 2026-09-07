// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/downloadlistgenerator.cpp
// Functions: 7
// ============================================================

#include "engine\downloadlistgenerator.h"

//------------------------------------------------------------------------------
// Address: 0x10164430
// Name: class CDownloadListGenerator __near & DownloadListGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CDownloadListGenerator *__cdecl DownloadListGenerator()
{
  return &g_DownloadListGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x10164440
// Name: public: void CDownloadListGenerator::OnLevelLoadEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnLevelLoadEnd(CDownloadListGenerator *this)
{
  void *m_hReslistFile; // eax

  m_hReslistFile = this->m_hReslistFile;
  if ( m_hReslistFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: m_hReslistFile);
    this->m_hReslistFile = nullptr;
  }
  this->m_pStringTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164480
// Name: public: void CDownloadListGenerator::OnResourcePrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnResourcePrecached(
        CDownloadListGenerator *this,
        const char *pRelativePathFileName)
{
  const char *v2; // esi
  char *FileExtension; // esi
  void *m_hReslistFile; // esi
  IBaseFileSystem_vtbl *v6; // ebx
  int v7; // eax
  char pRelativePath[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = pRelativePathFileName;
  if ( *pRelativePathFileName != 0 && *pRelativePathFileName != 42 )
  {
    if ( V_IsAbsolutePath(pStr: pRelativePathFileName) )
    {
      _Warning(a1: "*** CDownloadListGenerator::OnResourcePrecached: Encountered full path %s!\n", v2);
    }
    else
    {
      V_strncpy(pDest: pRelativePath, pSrc: v2, maxLen: 260);
      V_FixSlashes(pname: pRelativePath, separator: 47);
      if ( CUtlSymbolTable::Find(
             this: &this->m_AlreadyWrittenFileNames,
             result: (CUtlSymbol *)&pRelativePathFileName + 1,
             pString: pRelativePath)->m_Id == 0xFFFF )
      {
        CUtlSymbolTable::AddString(
          this: &this->m_AlreadyWrittenFileNames,
          result: (CUtlSymbol *)&pRelativePathFileName + 1,
          pString: pRelativePath);
        if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pRelativePath, a3: "GAME") )
        {
          FileExtension = (char *)V_GetFileExtension(path: pRelativePath);
          if ( _V_stricmp(s1: FileExtension, s2: "mdl") == 0 )
          {
            V_strncpy(pDest: FileExtension, pSrc: "vvd", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "ani", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "dx90.vtx", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "phy", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "jpg", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
          }
          m_hReslistFile = this->m_hReslistFile;
          if ( m_hReslistFile != nullptr )
          {
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: m_hReslistFile);
            v6 = g_pFileSystem->IBaseFileSystem::__vftable;
            v7 = _V_strlen(str: pRelativePath);
            v6->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pRelativePath, a3: v7, a4: m_hReslistFile);
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: m_hReslistFile);
          }
          if ( this->m_pStringTable != nullptr )
            this->m_pStringTable->AddString(
              this: this->m_pStringTable,
              a2: true,
              a3: pRelativePath,
              a4: -1,
              a5: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101646A0
// Name: public: void CDownloadListGenerator::ForceExactFile(char const __near *,enum ConsistencyType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDownloadListGenerator::ForceExactFile(
        CDownloadListGenerator *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        char *relativePathFileName,
        ConsistencyType consistency)
{
  const char *v6; // esi
  char *v7; // edi
  bool v8; // al
  INetworkStringTable *m_pStringTable; // ecx
  int v10; // eax
  INetworkStringTable_vtbl *v11; // edx
  char relativeFileName[260]; // [esp+4h] [ebp-210h] BYREF
  char file[260]; // [esp+108h] [ebp-10Ch] BYREF
  ExactFileUserData userData; // [esp+20Ch] [ebp-8h]

  if ( this->m_pStringTable != nullptr )
  {
    if ( consistency != CONSISTENCY_EXACT && consistency != CONSISTENCY_SIMPLE_MATERIAL )
      consistency = CONSISTENCY_EXACT;
    v6 = relativePathFileName;
    v7 = relativePathFileName;
    if ( _V_strstr(s1: relativePathFileName, search: ".vmt") != nullptr || _V_strstr(s1: v6, search: ".vtf") != nullptr )
    {
      if ( V_strnicmp(s1: v6, s2: "materials", n: 9) != 0 )
        V_snprintf(pDest: file, maxLen: 260, pFormat: "materials\\%s", v6);
      else
        V_strncpy(pDest: file, pSrc: v6, maxLen: 260);
      v8 = CRC_File(crcvalue: (unsigned int *)&relativePathFileName, pszFileName: file);
      v7 = file;
    }
    else
    {
      v8 = CRC_File(crcvalue: (unsigned int *)&relativePathFileName, pszFileName: v6);
    }
    if ( v8 )
    {
      V_strncpy(pDest: relativeFileName, pSrc: v7, maxLen: 260);
      V_FixSlashes(pname: relativeFileName, separator: 47);
      userData.consistencyType = consistency;
      m_pStringTable = this->m_pStringTable;
      userData.crc = (unsigned int)relativePathFileName;
      v10 = ((int (__thiscall *)(INetworkStringTable *, char *, int, int))m_pStringTable->FindStringIndex)(
              a1: m_pStringTable,
              a2: relativeFileName,
              a3: a2,
              a4: a3);
      v11 = this->m_pStringTable->__vftable;
      if ( v10 == 0xFFFF )
        ((void (__stdcall *)(int, char *))v11->AddString)(a1: 1, a2: relativeFileName);
      else
        ((void (__stdcall *)(int))v11->SetStringUserData)(a1: v10);
    }
    else
    {
      DevWarning(a1: "Failed to CRC %s\n", v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164810
// Name: public: void CDownloadListGenerator::SetStringTable(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::SetStringTable(CDownloadListGenerator *this, INetworkStringTable *pStringTable)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  IBaseFileSystem *v8; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  char resfilename[260]; // [esp+Ch] [ebp-208h] BYREF
  char path[260]; // [esp+110h] [ebp-104h] BYREF
  bool useNodeGraph_3; // [esp+21Fh] [ebp+Bh]

  this->m_pStringTable = pStringTable;
  CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.bsp", this->m_mapName);
  CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  useNodeGraph_3 = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ModInfo");
  else
    v4 = nullptr;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    useNodeGraph_3 = KeyValues::GetInt(this: v4, keyName: "nodegraph", defaultValue: 1) != 0;
  }
  KeyValues::deleteThis(this: v4);
  if ( useNodeGraph_3 )
  {
    V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\graphs\\%s.ain", this->m_mapName);
    CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  }
  V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.nav", this->m_mapName);
  CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "resourefiles");
  else
    v7 = nullptr;
  V_snprintf(pDest: resfilename, maxLen: 260, pFormat: "maps/%s.res", this->m_mapName);
  if ( g_pFileSystem != nullptr )
    v8 = &g_pFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v7,
         filesystem: v8,
         resourceName: resfilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v7); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: Name);
    }
    KeyValues::deleteThis(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101649C0
// Name: public: void CDownloadListGenerator::OnLevelLoadStart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnLevelLoadStart(CDownloadListGenerator *this, const char *levelName)
{
  void *m_hReslistFile; // eax
  char path[260]; // [esp+8h] [ebp-104h] BYREF

  m_hReslistFile = this->m_hReslistFile;
  if ( m_hReslistFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: m_hReslistFile);
    this->m_hReslistFile = nullptr;
  }
  CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
  if ( sv_logdownloadlist.m_pParent != nullptr && sv_logdownloadlist.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "DownloadLists", a3: "MOD");
    V_snprintf(pDest: path, maxLen: 260, pFormat: "DownloadLists/%s.lst", levelName);
    this->m_hReslistFile = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: path, a3: "wt", a4: "GAME");
  }
  V_snprintf(pDest: this->m_gameDir, maxLen: 256, pFormat: "%s/", com_gamedir);
  V_FixSlashes(pname: this->m_gameDir, separator: 47);
  V_snprintf(pDest: this->m_mapName, maxLen: 64, pFormat: levelName);
}

//------------------------------------------------------------------------------
// Address: 0x10164AA0
// Name: public: void CDownloadListGenerator::ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDownloadListGenerator::ForceModelBounds(
        CDownloadListGenerator *this@<ecx>,
        int a2@<edi>,
        const char *relativePathFileName,
        const Vector *mins,
        const Vector *maxs)
{
  const char *v6; // edi
  INetworkStringTable *m_pStringTable; // ecx
  float z; // xmm0_4
  int v9; // eax
  INetworkStringTable_vtbl *v10; // edx
  char relativeFileName[260]; // [esp+4h] [ebp-120h] BYREF
  ModelBoundsUserData userData; // [esp+108h] [ebp-1Ch]

  if ( this->m_pStringTable != nullptr )
  {
    v6 = relativePathFileName;
    if ( relativePathFileName == nullptr )
      v6 = defaultValue;
    if ( V_stristr(pStr: v6, pSearch: ".mdl") != nullptr )
    {
      V_strncpy(pDest: relativeFileName, pSrc: v6, maxLen: 260);
      V_FixSlashes(pname: relativeFileName, separator: 47);
      m_pStringTable = this->m_pStringTable;
      userData.mins = *mins;
      userData.maxs.x = maxs->x;
      userData.maxs.y = maxs->y;
      z = maxs->z;
      userData.consistencyType = 3;
      userData.maxs.z = z;
      v9 = ((int (__thiscall *)(INetworkStringTable *, char *, int))m_pStringTable->FindStringIndex)(
             a1: m_pStringTable,
             a2: relativeFileName,
             a3: a2);
      v10 = this->m_pStringTable->__vftable;
      if ( v9 == 0xFFFF )
        ((void (__stdcall *)(int, char *, int))v10->AddString)(a1: 1, a2: relativeFileName, a3: 28);
      else
        ((void (__stdcall *)(int, int))v10->SetStringUserData)(a1: v9, a2: 28);
    }
    else
    {
      DevWarning(a1: "Warning - trying to enforce model bounds on %s\n", v6);
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10164640
// Name: class CDownloadListGenerator __near & DownloadListGenerator(void)
// Source: json
//------------------------------------------------------------------------------
CDownloadListGenerator *__cdecl DownloadListGenerator()
{
  return &g_DownloadListGenerator;
}

//------------------------------------------------------------------------------
// Address: 0x10164650
// Name: public: void CDownloadListGenerator::OnLevelLoadEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnLevelLoadEnd(CDownloadListGenerator *this)
{
  void *m_hReslistFile; // eax

  m_hReslistFile = this->m_hReslistFile;
  if ( m_hReslistFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: m_hReslistFile);
    this->m_hReslistFile = nullptr;
  }
  this->m_pStringTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10164690
// Name: public: void CDownloadListGenerator::OnResourcePrecached(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnResourcePrecached(
        CDownloadListGenerator *this,
        const char *pRelativePathFileName)
{
  const char *v2; // esi
  char *FileExtension; // esi
  void *m_hReslistFile; // esi
  IBaseFileSystem_vtbl *v6; // ebx
  int v7; // eax
  char pRelativePath[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = pRelativePathFileName;
  if ( *pRelativePathFileName != 0 && *pRelativePathFileName != 42 )
  {
    if ( V_IsAbsolutePath(pStr: pRelativePathFileName) )
    {
      _Warning(a1: "*** CDownloadListGenerator::OnResourcePrecached: Encountered full path %s!\n", v2);
    }
    else
    {
      V_strncpy(pDest: pRelativePath, pSrc: v2, maxLen: 260);
      V_FixSlashes(pname: pRelativePath, separator: 47);
      if ( CUtlSymbolTable::Find(
             this: &this->m_AlreadyWrittenFileNames,
             result: (CUtlSymbol *)&pRelativePathFileName + 1,
             pString: pRelativePath)->m_Id == 0xFFFF )
      {
        CUtlSymbolTable::AddString(
          this: &this->m_AlreadyWrittenFileNames,
          result: (CUtlSymbol *)&pRelativePathFileName + 1,
          pString: pRelativePath);
        if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pRelativePath, a3: "GAME") )
        {
          FileExtension = (char *)V_GetFileExtension(path: pRelativePath);
          if ( _V_stricmp(s1: FileExtension, s2: "mdl") == 0 )
          {
            V_strncpy(pDest: FileExtension, pSrc: "vvd", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "ani", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "dx90.vtx", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "phy", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
            V_strncpy(pDest: FileExtension, pSrc: "jpg", maxLen: 10);
            CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: pRelativePath);
          }
          m_hReslistFile = this->m_hReslistFile;
          if ( m_hReslistFile != nullptr )
          {
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"", a3: 1, a4: m_hReslistFile);
            v6 = g_pFileSystem->IBaseFileSystem::__vftable;
            v7 = _V_strlen(str: pRelativePath);
            v6->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pRelativePath, a3: v7, a4: m_hReslistFile);
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: "\"\n", a3: 2, a4: m_hReslistFile);
          }
          if ( this->m_pStringTable != nullptr )
            this->m_pStringTable->AddString(
              this: this->m_pStringTable,
              a2: true,
              a3: pRelativePath,
              a4: -1,
              a5: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101648B0
// Name: public: void CDownloadListGenerator::ForceExactFile(char const __near *,enum ConsistencyType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDownloadListGenerator::ForceExactFile(
        CDownloadListGenerator *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        char *relativePathFileName,
        ConsistencyType consistency)
{
  char *v6; // esi
  char *v7; // edi
  char v8; // al
  INetworkStringTable *m_pStringTable; // ecx
  int v10; // eax
  INetworkStringTable_vtbl *v11; // edx
  char relativeFileName[260]; // [esp+4h] [ebp-210h] BYREF
  char file[260]; // [esp+108h] [ebp-10Ch] BYREF
  ExactFileUserData userData; // [esp+20Ch] [ebp-8h]

  if ( this->m_pStringTable != nullptr )
  {
    if ( consistency != CONSISTENCY_EXACT && consistency != CONSISTENCY_SIMPLE_MATERIAL )
      consistency = CONSISTENCY_EXACT;
    v6 = relativePathFileName;
    v7 = relativePathFileName;
    if ( _V_strstr(s1: relativePathFileName, search: ".vmt") != nullptr || _V_strstr(s1: v6, search: ".vtf") != nullptr )
    {
      if ( V_strnicmp(s1: v6, s2: "materials", n: 9) != 0 )
        V_snprintf(pDest: file, maxLen: 260, pFormat: "materials\\%s", v6);
      else
        V_strncpy(pDest: file, pSrc: v6, maxLen: 260);
      v8 = CRC_File(crcvalue: (unsigned int *)&relativePathFileName, pszFileName: file);
      v7 = file;
    }
    else
    {
      v8 = CRC_File(crcvalue: (unsigned int *)&relativePathFileName, pszFileName: v6);
    }
    if ( v8 != 0 )
    {
      V_strncpy(pDest: relativeFileName, pSrc: v7, maxLen: 260);
      V_FixSlashes(pname: relativeFileName, separator: 47);
      userData.consistencyType = consistency;
      m_pStringTable = this->m_pStringTable;
      userData.crc = (unsigned int)relativePathFileName;
      v10 = ((int (__thiscall *)(INetworkStringTable *, char *, int, int))m_pStringTable->FindStringIndex)(
              a1: m_pStringTable,
              a2: relativeFileName,
              a3: a2,
              a4: a3);
      v11 = this->m_pStringTable->__vftable;
      if ( v10 == 0xFFFF )
        ((void (__stdcall *)(int, char *))v11->AddString)(a1: 1, a2: relativeFileName);
      else
        ((void (__stdcall *)(int))v11->SetStringUserData)(a1: v10);
    }
    else
    {
      DevWarning(a1: "Failed to CRC %s\n", v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164A20
// Name: public: void CDownloadListGenerator::SetStringTable(class INetworkStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::SetStringTable(CDownloadListGenerator *this, INetworkStringTable *pStringTable)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  IBaseFileSystem *v8; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  char resfilename[260]; // [esp+Ch] [ebp-208h] BYREF
  char path[260]; // [esp+110h] [ebp-104h] BYREF
  bool useNodeGraph_3; // [esp+21Fh] [ebp+Bh]

  this->m_pStringTable = pStringTable;
  CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
  V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.bsp", this->m_mapName);
  CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  useNodeGraph_3 = true;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ModInfo");
  else
    v4 = nullptr;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    useNodeGraph_3 = KeyValues::GetInt(this: v4, keyName: "nodegraph", defaultValue: 1) != 0;
  }
  KeyValues::deleteThis(this: v4);
  if ( useNodeGraph_3 )
  {
    V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\graphs\\%s.ain", this->m_mapName);
    CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  }
  V_snprintf(pDest: path, maxLen: 260, pFormat: "maps\\%s.nav", this->m_mapName);
  CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: path);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "resourefiles");
  else
    v7 = nullptr;
  V_snprintf(pDest: resfilename, maxLen: 260, pFormat: "maps/%s.res", this->m_mapName);
  if ( g_pFileSystem != nullptr )
    v8 = &g_pFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v7,
         filesystem: v8,
         resourceName: resfilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( i = KeyValues::GetFirstSubKey(this: v7); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      CDownloadListGenerator::OnResourcePrecached(this, pRelativePathFileName: Name);
    }
    KeyValues::deleteThis(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164BD0
// Name: public: void CDownloadListGenerator::OnLevelLoadStart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDownloadListGenerator::OnLevelLoadStart(CDownloadListGenerator *this, const char *levelName)
{
  void *m_hReslistFile; // eax
  char path[260]; // [esp+8h] [ebp-104h] BYREF

  m_hReslistFile = this->m_hReslistFile;
  if ( m_hReslistFile != nullptr )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: m_hReslistFile);
    this->m_hReslistFile = nullptr;
  }
  CUtlSymbolTable::RemoveAll(this: &this->m_AlreadyWrittenFileNames);
  if ( sv_logdownloadlist.m_pParent != nullptr && sv_logdownloadlist.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "DownloadLists", a3: "MOD");
    V_snprintf(pDest: path, maxLen: 260, pFormat: "DownloadLists/%s.lst", levelName);
    this->m_hReslistFile = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: path, a3: "wt", a4: "GAME");
  }
  V_snprintf(pDest: this->m_gameDir, maxLen: 256, pFormat: "%s/", com_gamedir);
  V_FixSlashes(pname: this->m_gameDir, separator: 47);
  V_snprintf(pDest: this->m_mapName, maxLen: 64, pFormat: levelName);
}

//------------------------------------------------------------------------------
// Address: 0x10164CB0
// Name: public: void CDownloadListGenerator::ForceModelBounds(char const __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDownloadListGenerator::ForceModelBounds(
        CDownloadListGenerator *this@<ecx>,
        int a2@<edi>,
        const char *relativePathFileName,
        const Vector *mins,
        const Vector *maxs)
{
  const char *v6; // edi
  INetworkStringTable *m_pStringTable; // ecx
  float z; // xmm0_4
  int v9; // eax
  INetworkStringTable_vtbl *v10; // edx
  char relativeFileName[260]; // [esp+4h] [ebp-120h] BYREF
  ModelBoundsUserData userData; // [esp+108h] [ebp-1Ch]

  if ( this->m_pStringTable != nullptr )
  {
    v6 = relativePathFileName;
    if ( relativePathFileName == nullptr )
      v6 = defaultValue;
    if ( V_stristr(pStr: v6, pSearch: ".mdl") != nullptr )
    {
      V_strncpy(pDest: relativeFileName, pSrc: v6, maxLen: 260);
      V_FixSlashes(pname: relativeFileName, separator: 47);
      m_pStringTable = this->m_pStringTable;
      userData.mins = *mins;
      userData.maxs.x = maxs->x;
      userData.maxs.y = maxs->y;
      z = maxs->z;
      userData.consistencyType = 3;
      userData.maxs.z = z;
      v9 = ((int (__thiscall *)(INetworkStringTable *, char *, int))m_pStringTable->FindStringIndex)(
             a1: m_pStringTable,
             a2: relativeFileName,
             a3: a2);
      v10 = this->m_pStringTable->__vftable;
      if ( v9 == 0xFFFF )
        ((void (__stdcall *)(int, char *, int))v10->AddString)(a1: 1, a2: relativeFileName, a3: 28);
      else
        ((void (__stdcall *)(int, int))v10->SetStringUserData)(a1: v9, a2: 28);
    }
    else
    {
      DevWarning(a1: "Warning - trying to enforce model bounds on %s\n", v6);
    }
  }
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
    callback: Host_Loadgame_f,
    pHelpString: "Load a saved game.",
    flags: 0,
    completionFunc: g_load_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__load_command__);
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

} // namespace engine_xlsp
