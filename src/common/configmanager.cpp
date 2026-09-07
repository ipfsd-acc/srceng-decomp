// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/configmanager.cpp
// Functions: 17
// ============================================================

#include "common\configmanager.h"

//------------------------------------------------------------------------------
// Address: 0x10015320
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10015340
// Name: public: KeyValues::AutoDelete::~AutoDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall KeyValues::AutoDelete::~AutoDelete(KeyValues::AutoDelete *this)
{
  KeyValues *m_pKeyValues; // ecx

  m_pKeyValues = this->m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10015350
// Name: public: CGameConfigManager::CGameConfigManager(void)
// Source: json
//------------------------------------------------------------------------------
CGameConfigManager *__thiscall CGameConfigManager::CGameConfigManager(CGameConfigManager *this)
{
  char *m_szBaseDirectory; // edi
  HMODULE ModuleHandleA; // eax
  char *v5; // [esp-8h] [ebp-10h]

  m_szBaseDirectory = this->m_szBaseDirectory;
  v5 = this->m_szBaseDirectory;
  this->m_LoadStatus = LOADSTATUS_NONE;
  this->m_pData = nullptr;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: v5, nSize: 0x104u);
  V_StripLastDir(dirName: m_szBaseDirectory, maxlen: 260);
  V_StripTrailingSlash(ppath: m_szBaseDirectory);
  this->m_eSDKEpoch = CSS15;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100153A0
// Name: public: CGameConfigManager::~CGameConfigManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfigManager::~CGameConfigManager(CGameConfigManager *this)
{
  KeyValues *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    KeyValues::deleteThis(this: m_pData);
}

//------------------------------------------------------------------------------
// Address: 0x100153B0
// Name: public: char const __near * CGameConfigManager::GetRootDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CGameConfigManager::GetRootDirectory(CGameConfigManager *this)
{
  if ( path[0] == 0 )
  {
    V_strncpy(pDest: path, pSrc: this->m_szBaseDirectory, maxLen: 260);
    V_StripLastDir(dirName: path, maxlen: 260);
    V_StripTrailingSlash(ppath: path);
    if ( g_pFullFileSystem != nullptr && g_pFullFileSystem->IsSteam(this: g_pFullFileSystem) )
    {
      V_StripLastDir(dirName: path, maxlen: 260);
      V_StripTrailingSlash(ppath: path);
      V_StripLastDir(dirName: path, maxlen: 260);
      V_StripTrailingSlash(ppath: path);
      V_StripLastDir(dirName: path, maxlen: 260);
      V_StripTrailingSlash(ppath: path);
    }
  }
  return path;
}

//------------------------------------------------------------------------------
// Address: 0x10015460
// Name: public: class KeyValues __near * CGameConfigManager::GetGameBlock(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CGameConfigManager::GetGameBlock(CGameConfigManager *this)
{
  KeyValues *m_pData; // ecx

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
    return KeyValues::FindKey(this: m_pData, keyName: "Games", bCreate: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015480
// Name: public: void CGameConfigManager::SetBaseDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfigManager::SetBaseDirectory(CGameConfigManager *this, const char *pDirectory)
{
  char *m_szBaseDirectory; // esi

  if ( pDirectory != nullptr && *pDirectory != 0 )
  {
    m_szBaseDirectory = this->m_szBaseDirectory;
    V_strncpy(pDest: this->m_szBaseDirectory, pSrc: pDirectory, maxLen: 260);
    V_StripTrailingSlash(ppath: m_szBaseDirectory);
  }
  else
  {
    this->m_szBaseDirectory[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100154C0
// Name: bool ReadUtlBufferFromFile(class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReadUtlBufferFromFile(CUtlBuffer *buffer, const char *szPath)
{
  int v3; // esi
  int v4; // eax
  _stat64i32 fileInfo; // [esp+4h] [ebp-30h] BYREF

  if ( _stat64i32(name: szPath, buf: &fileInfo) == -1 )
    return 0;
  CUtlBuffer::EnsureCapacity(this: buffer, num: fileInfo.st_size);
  v3 = _open(path: szPath, oflag: 0x8000, pmode: 0);
  if ( v3 == -1 )
    return 0;
  v4 = _read(fh: v3, buf: buffer->m_Memory.m_pMemory, cnt: fileInfo.st_size);
  if ( v4 != fileInfo.st_size )
  {
    _close(fh: v3);
    return 0;
  }
  _close(fh: v3);
  CUtlBuffer::SeekPut(this: buffer, type: SEEK_HEAD, offset: fileInfo.st_size);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015550
// Name: public: bool CGameConfigManager::AddDefaultConfig(struct defaultConfigInfo_t const __near &,class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::AddDefaultConfig(
        CGameConfigManager *this,
        const defaultConfigInfo_t *info,
        KeyValues *out,
        const char *rootDirectory,
        const char *gameExeDir)
{
  KeyValues *v5; // eax
  KeyValues *v7; // esi
  const char *v9; // ebx
  KeyValues *Key; // esi
  char *FGD; // edi
  const char *m_szBaseDirectory; // edi
  KeyValues *FirstTrueSubKey; // eax
  KeyValues *NextTrueSubKey; // esi
  char contentMapDir[260]; // [esp+Ch] [ebp-424h] BYREF
  char contentRootDir[260]; // [esp+110h] [ebp-320h] BYREF
  char rootGameDir[260]; // [esp+214h] [ebp-21Ch] BYREF
  char szPath[260]; // [esp+318h] [ebp-118h] BYREF
  KeyValues::AutoDelete autodelete_key; // [esp+41Ch] [ebp-14h]
  CGameConfigManager *v20; // [esp+420h] [ebp-10h]
  int v21; // [esp+42Ch] [ebp-4h]
  KeyValues *infoa; // [esp+438h] [ebp+8h]

  v20 = this;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  autodelete_key.m_pKeyValues = v5;
  v21 = 0;
  if ( v5 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v5, setName: info->gameName);
    infoa = v7;
  }
  else
  {
    infoa = nullptr;
    v7 = nullptr;
  }
  autodelete_key.m_pKeyValues = v7;
  v21 = 1;
  if ( !KeyValues::LoadFromBuffer(
          this: v7,
          resourceName: "defaultcfg.txt",
          pBuffer: "\"%gamename%\"{\t\"GameDir\"\t\"%gamedir%\"\t\"Hammer\"\t{\t\t\"TextureFormat\"\t\t\"5\"\t\t\"MapFormat\"\t\t\""
          "4\"\t\t\"DefaultTextureScale\"\t\"0.250000\"\t\t\"DefaultLightmapScale\"\t\"16\"\t\t\"DefaultSolidEntity\"\t\""
          "func_detail\"\t\t\"DefaultPointEntity\"\t\"%defaultpointentity%\"\t\t\"GameExeDir\"\t\t\"%gameexe%\"\t\t\"MapD"
          "ir\"\t\t\"%gamemaps%\"\t\t\"CordonTexture\"\t\t\"tools\\toolsskybox\"\t\t\"MaterialExcludeCount\"\t\"0\"\t\t\""
          "GameExe\"\t\"%gameEXE%\"\t\t\"BSP\"\t\t\"%bspdir%\"\t\t\"Vis\"\t\t\"%visdir%\"\t\t\"Light\"\t\"%lightdir%\"}}",
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    v21 = -1;
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    return 0;
  }
  KeyValues::SetName(this: v7, setName: info->gameName);
  if ( g_pFullFileSystem != nullptr
    && g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    && info != (const defaultConfigInfo_t *)-780
    && info->steamPath[0] != 0 )
  {
    v9 = rootDirectory;
    V_snprintf(pDest: rootGameDir, maxLen: 260, pFormat: "%s\\%s", rootDirectory, info->steamPath);
  }
  else
  {
    v9 = rootDirectory;
    V_strncpy(pDest: rootGameDir, pSrc: rootDirectory, maxLen: 260);
  }
  if ( g_pFullFileSystem != nullptr && g_pFullFileSystem->IsSteam(this: g_pFullFileSystem) )
    V_snprintf(pDest: contentRootDir, maxLen: 260, pFormat: "%s\\sourcesdk_content", v9);
  else
    V_snprintf(pDest: contentRootDir, maxLen: 260, pFormat: "%s\\content", v9);
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", rootGameDir, info->gameDir);
  KeyValues::SetString(this: v7, keyName: "GameDir", value: szPath);
  Key = KeyValues::FindKey(this: v7, keyName: "Hammer", bCreate: false);
  if ( Key != nullptr )
  {
    KeyValues::SetString(this: Key, keyName: "GameExeDir", value: gameExeDir);
    KeyValues::SetString(this: Key, keyName: "DefaultPointEntity", value: info->defaultPointEntity);
    V_snprintf(pDest: contentMapDir, maxLen: 260, pFormat: "%s\\%s\\mapsrc", contentRootDir, info->gameDir);
    KeyValues::SetString(this: Key, keyName: "MapDir", value: contentMapDir);
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s\\maps", rootGameDir, info->gameDir);
    KeyValues::SetString(this: Key, keyName: "BSPDir", value: szPath);
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", gameExeDir, info->exeName);
    KeyValues::SetString(this: Key, keyName: "GameEXE", value: szPath);
    FGD = info->FGD;
    if ( *FGD != 0 )
    {
      V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", v20->m_szBaseDirectory, FGD);
      KeyValues::SetString(this: Key, keyName: "GameData0", value: szPath);
    }
    m_szBaseDirectory = v20->m_szBaseDirectory;
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\vbsp.exe", v20->m_szBaseDirectory);
    KeyValues::SetString(this: Key, keyName: "BSP", value: szPath);
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\vvis.exe", m_szBaseDirectory);
    KeyValues::SetString(this: Key, keyName: "Vis", value: szPath);
    V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\vrad.exe", m_szBaseDirectory);
    KeyValues::SetString(this: Key, keyName: "Light", value: szPath);
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: out);
    NextTrueSubKey = FirstTrueSubKey;
    autodelete_key.m_pKeyValues = nullptr;
    if ( FirstTrueSubKey != nullptr )
    {
      if ( KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey) != nullptr )
      {
        do
          NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: NextTrueSubKey);
        while ( KeyValues::GetNextTrueSubKey(this: NextTrueSubKey) != nullptr );
      }
      KeyValues::SetNextKey(this: NextTrueSubKey, pDat: infoa);
    }
    else
    {
      KeyValues::AddSubKey(this: out, pSubkey: infoa);
    }
    return 1;
  }
  else
  {
    v21 = -1;
    if ( infoa == nullptr )
      return 0;
    KeyValues::deleteThis(this: infoa);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100159B0
// Name: public: bool CGameConfigManager::SaveConfigs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::SaveConfigs(CGameConfigManager *this, const char *baseDir)
{
  int v4; // esi
  char v5; // bl
  int m_nMaxPut; // edi
  char szPath[260]; // [esp+4h] [ebp-140h] BYREF
  CUtlBuffer buffer; // [esp+108h] [ebp-3Ch] BYREF
  int v9; // [esp+140h] [ebp-4h]

  if ( this->m_pData == nullptr )
    return 0;
  if ( baseDir != nullptr && *baseDir != 0 )
    CGameConfigManager::SetBaseDirectory(this, pDirectory: baseDir);
  V_strncpy(pDest: szPath, pSrc: this->m_szBaseDirectory, maxLen: 260);
  V_AppendSlash(pStr: szPath, strSize: 260);
  V_strncat(pDest: szPath, pSrc: "GameConfig.txt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  v9 = 0;
  KeyValues::RecursiveSaveToFile(this: this->m_pData, buf: &buffer, indentLevel: 0);
  v4 = _open(path: szPath, oflag: 17154, pmode: 128);
  if ( v4 == -1 )
  {
    v5 = 0;
  }
  else
  {
    m_nMaxPut = buffer.m_nMaxPut;
    if ( _write(fh: v4, buf: buffer.m_Memory.m_pMemory, cnt: buffer.m_nMaxPut) >= m_nMaxPut )
    {
      _close(fh: v4);
      v5 = 1;
    }
    else
    {
      _close(fh: v4);
      v5 = 0;
    }
  }
  v9 = -1;
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10015B80
// Name: private: void CGameConfigManager::VersionConfig(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfigManager::VersionConfig(CGameConfigManager *this)
{
  KeyValues *m_pData; // ecx
  KeyValues *Key; // eax
  eSDKEpochs m_eSDKEpoch; // edi

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    Key = KeyValues::FindKey(this: m_pData, keyName: "SDKVersion", bCreate: false);
    if ( Key != nullptr )
    {
      m_eSDKEpoch = this->m_eSDKEpoch;
      if ( KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) == m_eSDKEpoch )
        return;
      KeyValues::SetInt(this: this->m_pData, keyName: "SDKVersion", value: m_eSDKEpoch);
    }
    else
    {
      KeyValues::SetInt(this: this->m_pData, keyName: "SDKVersion", value: this->m_eSDKEpoch);
    }
    CGameConfigManager::SaveConfigs(this, baseDir: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015BE0
// Name: public: bool CGameConfigManager::GetDefaultGameBlock(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::GetDefaultGameBlock(CGameConfigManager *this, KeyValues *pIn)
{
  int v2; // edi
  CGameConfigManager *v3; // ebx
  eSDKEpochs m_eSDKEpoch; // eax
  int steamAppID; // esi
  ISteamApps *m_pSteamApps; // ecx
  char *steamPath; // esi
  char *RootDirectory; // ebx
  CGameConfigManager *v10; // esi
  const defaultConfigInfo_t *v11; // ebx
  char *v12; // eax
  defaultConfigInfo_t *m_pMemory; // eax
  char szPath[260]; // [esp+8h] [ebp-12Ch] BYREF
  CGameConfigManager *v15; // [esp+10Ch] [ebp-28h]
  int i; // [esp+110h] [ebp-24h]
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > defaultConfigs; // [esp+114h] [ebp-20h] BYREF
  int v18; // [esp+130h] [ebp-4h]

  v2 = 0;
  v3 = this;
  v15 = this;
  memset(&defaultConfigs, 0, sizeof(defaultConfigs));
  v18 = 1;
  m_eSDKEpoch = this->m_eSDKEpoch;
  if ( m_eSDKEpoch == HL2 || m_eSDKEpoch == EP1 )
  {
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &HL2Info);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &CStrikeInfo);
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &HL2DMInfo);
  }
  if ( v3->m_eSDKEpoch == EP1 )
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &Episode1Info);
  if ( v3->m_eSDKEpoch == EP2 )
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &Episode2Info);
  if ( v3->m_eSDKEpoch == SWARM )
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &SwarmInfo);
  if ( v3->m_eSDKEpoch == CSS15 )
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::InsertBefore(
      this: &defaultConfigs,
      elem: defaultConfigs.m_Size,
      src: &CStrike15Info);
  if ( pIn != nullptr )
  {
    if ( defaultConfigs.m_Size > 0 )
    {
      for ( i = defaultConfigs.m_Size; i != 0; --i )
      {
        steamAppID = defaultConfigs.m_Memory.m_pMemory[v2].steamAppID;
        if ( g_pFullFileSystem == nullptr
          || !g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
          || (m_pSteamApps = steamapicontext->m_pSteamApps) != nullptr
          && m_pSteamApps->BIsSubscribedApp(this: m_pSteamApps, a2: steamAppID) )
        {
          steamPath = defaultConfigs.m_Memory.m_pMemory[v2].steamPath;
          RootDirectory = CGameConfigManager::GetRootDirectory(this: v3);
          if ( g_pFullFileSystem != nullptr
            && g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
            && steamPath != nullptr
            && *steamPath != 0 )
          {
            V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", RootDirectory, steamPath);
          }
          else
          {
            V_strncpy(pDest: szPath, pSrc: RootDirectory, maxLen: 260);
          }
          v10 = v15;
          v11 = &defaultConfigs.m_Memory.m_pMemory[v2];
          v12 = CGameConfigManager::GetRootDirectory(this: v15);
          CGameConfigManager::AddDefaultConfig(this: v10, info: v11, out: pIn, rootDirectory: v12, gameExeDir: szPath);
          v3 = v10;
        }
        ++v2;
      }
    }
    v18 = 2;
    m_pMemory = defaultConfigs.m_Memory.m_pMemory;
    defaultConfigs.m_Size = 0;
    if ( defaultConfigs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( defaultConfigs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultConfigs.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        defaultConfigs.m_Memory.m_pMemory = nullptr;
      }
      defaultConfigs.m_Memory.m_nAllocationCount = 0;
    }
    defaultConfigs.m_pElements = m_pMemory;
    v18 = -1;
    if ( defaultConfigs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( defaultConfigs.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: defaultConfigs.m_Memory.m_pMemory);
        defaultConfigs.m_Memory.m_pMemory = nullptr;
      }
      defaultConfigs.m_Memory.m_nAllocationCount = 0;
    }
    return 1;
  }
  else
  {
    v18 = -1;
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: &defaultConfigs);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015E60
// Name: private: void CGameConfigManager::UpdateConfigsInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConfigManager::UpdateConfigsInternal(CGameConfigManager *this)
{
  KeyValues *m_pData; // ecx
  KeyValues *v3; // esi
  KeyValues *Key; // eax
  KeyValues *v5; // ecx
  KeyValues *v6; // edi
  KeyValues *v7; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ecx
  KeyValues *Copy; // eax
  KeyValues *v13; // [esp+Ch] [ebp-10h]

  m_pData = this->m_pData;
  v3 = nullptr;
  if ( m_pData != nullptr )
  {
    Key = KeyValues::FindKey(this: m_pData, keyName: "SDKVersion", bCreate: false);
    if ( Key == nullptr || KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != this->m_eSDKEpoch )
    {
      v5 = this->m_pData;
      if ( v5 != nullptr && (v6 = KeyValues::FindKey(this: v5, keyName: "Games", bCreate: false)) != nullptr )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
        {
          v3 = KeyValues::KeyValues(this: v7, setName: "DefaultConfigs");
          v13 = v3;
        }
        else
        {
          v13 = nullptr;
        }
        if ( v3 != nullptr )
        {
          CGameConfigManager::GetDefaultGameBlock(this, pIn: v3);
          for ( i = KeyValues::GetFirstTrueSubKey(this: v3); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: v11) )
          {
            Name = KeyValues::GetName(this: i);
            v10 = KeyValues::FindKey(this: v6, keyName: Name, bCreate: false);
            v11 = i;
            if ( v10 == nullptr )
            {
              Copy = KeyValues::MakeCopy(this: i);
              KeyValues::AddSubKey(this: v6, pSubkey: Copy);
              v11 = i;
            }
          }
          KeyValues::deleteThis(this: v13);
        }
        CGameConfigManager::SaveConfigs(this, baseDir: nullptr);
        CGameConfigManager::VersionConfig(this);
      }
      else
      {
        CGameConfigManager::ResetConfigs(this, baseDir: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015F90
// Name: private: bool CGameConfigManager::CreateAllDefaultConfigs(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameConfigManager::CreateAllDefaultConfigs(CGameConfigManager *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  KeyValues *NewKey; // esi
  int v5; // esi
  char szPath[260]; // [esp+Ch] [ebp-148h] BYREF
  CUtlBuffer buffer; // [esp+110h] [ebp-44h] BYREF
  void *pMem; // [esp+140h] [ebp-14h]
  bool bRetVal; // [esp+147h] [ebp-Dh]
  int v11; // [esp+150h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  pMem = v2;
  v3 = nullptr;
  v11 = 0;
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "Configs");
  v11 = -1;
  NewKey = KeyValues::CreateNewKey(this: v3);
  KeyValues::SetName(this: NewKey, setName: "Games");
  CGameConfigManager::GetDefaultGameBlock(this, pIn: NewKey);
  bRetVal = !KeyValues::IsEmpty(this: NewKey, keyName: nullptr);
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", this->m_szBaseDirectory, "GameConfig.txt");
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  v11 = 1;
  KeyValues::RecursiveSaveToFile(this: v3, buf: &buffer, indentLevel: 0);
  v5 = _open(path: szPath, oflag: 17154, pmode: 128);
  if ( v5 != -1 )
  {
    pMem = (void *)buffer.m_nMaxPut;
    _write(fh: v5, buf: buffer.m_Memory.m_pMemory, cnt: buffer.m_nMaxPut);
    _close(fh: v5);
  }
  KeyValues::deleteThis(this: v3);
  this->m_LoadStatus = LOADSTATUS_CREATED;
  v11 = -1;
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  return bRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x100160E0
// Name: private: bool CGameConfigManager::LoadConfigsInternal(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::LoadConfigsInternal(
        CGameConfigManager *this,
        const char *baseDir,
        bool bRecursiveCall)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  bool ConfigsInternal; // bl
  char szPath[260]; // [esp+8h] [ebp-144h] BYREF
  void *pMem; // [esp+10Ch] [ebp-40h]
  CUtlBuffer buffer; // [esp+110h] [ebp-3Ch] BYREF
  int v11; // [esp+148h] [ebp-4h]

  if ( this->m_pData == nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    pMem = v4;
    v11 = 0;
    v5 = v4 != nullptr ? KeyValues::KeyValues(this: v4, setName: "GameConfig.txt") : nullptr;
    v11 = -1;
    this->m_pData = v5;
    if ( v5 == nullptr )
    {
      this->m_LoadStatus = LOADSTATUS_ERROR;
      return 0;
    }
  }
  KeyValues::Clear(this: this->m_pData);
  if ( baseDir != nullptr && *baseDir != 0 )
  {
    V_strncpy(pDest: this->m_szBaseDirectory, pSrc: baseDir, maxLen: 260);
    V_StripTrailingSlash(ppath: this->m_szBaseDirectory);
  }
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", this->m_szBaseDirectory, "GameConfig.txt");
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 1);
  v11 = 1;
  if ( ReadUtlBufferFromFile(&buffer, szPath) != 0
    && KeyValues::LoadFromBuffer(
         this: this->m_pData,
         resourceName: szPath,
         buf: &buffer,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    CGameConfigManager::UpdateConfigsInternal(this);
    v11 = -1;
    if ( buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
        buffer.m_Memory.m_pMemory = nullptr;
      }
      buffer.m_Memory.m_nAllocationCount = 0;
    }
    return 1;
  }
  else
  {
    if ( CGameConfigManager::CreateAllDefaultConfigs(this) )
    {
      if ( !bRecursiveCall )
      {
        ConfigsInternal = CGameConfigManager::LoadConfigsInternal(this, baseDir, bRecursiveCall: true);
        v11 = -1;
        CUtlBuffer::~CUtlBuffer(this: &buffer);
        return ConfigsInternal;
      }
      CGameConfigManager::VersionConfig(this);
    }
    this->m_LoadStatus = LOADSTATUS_ERROR;
    v11 = -1;
    if ( buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
        buffer.m_Memory.m_pMemory = nullptr;
      }
      buffer.m_Memory.m_nAllocationCount = 0;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100162C0
// Name: public: bool CGameConfigManager::ResetConfigs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::ResetConfigs(CGameConfigManager *this, const char *baseDir)
{
  char szPath[260]; // [esp+8h] [ebp-104h] BYREF

  if ( baseDir != nullptr && *baseDir != 0 )
  {
    V_strncpy(pDest: this->m_szBaseDirectory, pSrc: baseDir, maxLen: 260);
    V_StripTrailingSlash(ppath: this->m_szBaseDirectory);
  }
  V_snprintf(pDest: szPath, maxLen: 260, pFormat: "%s\\%s", this->m_szBaseDirectory, "GameConfig.txt");
  if ( unlink(path: szPath) != 0 || CGameConfigManager::LoadConfigsInternal(this, baseDir, bRecursiveCall: false) == 0 )
    return 0;
  else
    return CGameConfigManager::SaveConfigs(this, baseDir);
}

//------------------------------------------------------------------------------
// Address: 0x10016350
// Name: public: bool CGameConfigManager::LoadConfigs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameConfigManager::LoadConfigs(CGameConfigManager *this, const char *baseDir)
{
  return CGameConfigManager::LoadConfigsInternal(this, baseDir, bRecursiveCall: false);
}
