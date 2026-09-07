// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/filesystem_tools.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040D930
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x0040D9B0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBA0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x0040DBC0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

// ============================================================
// Overlay from getbugs (Missing functions)
// ============================================================
namespace getbugs {

//------------------------------------------------------------------------------
// Address: 0x00403250
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x004032D0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x004034E0
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace getbugs

// ============================================================
// Overlay from glview (Missing functions)
// ============================================================
namespace glview {

//------------------------------------------------------------------------------
// Address: 0x00405820
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x004058A0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405A90
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

} // namespace glview

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x004059D0
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace localization_check

// ============================================================
// Overlay from mdlcheck (Missing functions)
// ============================================================
namespace mdlcheck {

//------------------------------------------------------------------------------
// Address: 0x00402E40
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00402EC0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004030B0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x004030D0
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace mdlcheck

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004161B0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

} // namespace mdlcompile

// ============================================================
// Overlay from motionmapper (Missing functions)
// ============================================================
namespace motionmapper {

//------------------------------------------------------------------------------
// Address: 0x004035B0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403820
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

} // namespace motionmapper

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1001C130
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(char *pFilename, char *pGameInfoPath)
{
  char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x1001C1B0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( Sys_LoadInterface(
         pModuleName: "filesystem_stdio",
         pInterfaceVersionName: "VFileSystem017",
         pOutModule: &g_pFullFileSystemModule,
         pOutInterface: (void **)&g_pFullFileSystem) == 0
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001C3A0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(char *pBSPFilename, int maxMemoryUsage, FSInitType_t initType, bool bOnlyUseFilename)
{
  char result; // al
  IFileSystem *v5; // eax
  IFileSystem *v6; // eax

  if ( !g_bUseMPI )
    return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
  if ( g_bMPIMaster )
  {
    result = FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
    if ( result != 0 )
    {
      v5 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: g_pFullFileSystem);
      g_pFullFileSystem = v5;
      if ( v5 != nullptr )
        g_pFileSystem = &v5->IBaseFileSystem;
      else
        g_pFileSystem = nullptr;
      SendQDirInfo();
      return 1;
    }
  }
  else
  {
    v6 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: nullptr);
    g_pFullFileSystem = v6;
    if ( v6 != nullptr )
      g_pFileSystem = &v6->IBaseFileSystem;
    else
      g_pFileSystem = nullptr;
    RecvQDirInfo();
    return 1;
  }
  return result;
}

} // namespace shadercompile_dll

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0040EE30
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

} // namespace studiomdl

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x0040C1A0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x0040C220
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C410
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x0040C430
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

//------------------------------------------------------------------------------
// Address: 0x0040C440
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x0040C460
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

} // namespace subdbaker

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x100062E0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(char *pFilename, char *pGameInfoPath)
{
  char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10006360
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( Sys_LoadInterface(
         pModuleName: "filesystem_stdio",
         pInterfaceVersionName: "VFileSystem017",
         pOutModule: &g_pFullFileSystemModule,
         pOutInterface: (void **)&g_pFullFileSystem) == 0
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006550
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(char *pBSPFilename, int maxMemoryUsage, FSInitType_t initType, bool bOnlyUseFilename)
{
  char result; // al
  IFileSystem *v5; // eax
  IFileSystem *v6; // eax

  if ( !g_bUseMPI )
    return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
  if ( g_bMPIMaster )
  {
    result = FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
    if ( result != 0 )
    {
      v5 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: g_pFullFileSystem);
      g_pFullFileSystem = v5;
      if ( v5 != nullptr )
        g_pFileSystem = &v5->IBaseFileSystem;
      else
        g_pFileSystem = nullptr;
      SendQDirInfo();
      return 1;
    }
  }
  else
  {
    v6 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: nullptr);
    g_pFullFileSystem = v6;
    if ( v6 != nullptr )
      g_pFileSystem = &v6->IBaseFileSystem;
    else
      g_pFileSystem = nullptr;
    RecvQDirInfo();
    return 1;
  }
  return result;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from unusedcontent (Missing functions)
// ============================================================
namespace unusedcontent {

//------------------------------------------------------------------------------
// Address: 0x00403480
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00403500
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004036F0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace unusedcontent

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0044A4D0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x0044A550
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044A740
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x0044A760
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044A7B0
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x004048E0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00404960
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B50
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x00404B70
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BC0
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace vbsp2

// ============================================================
// Overlay from vcd_sound_check (Missing functions)
// ============================================================
namespace vcd_sound_check {

//------------------------------------------------------------------------------
// Address: 0x00403840
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace vcd_sound_check

// ============================================================
// Overlay from vice (Missing functions)
// ============================================================
namespace vice {

//------------------------------------------------------------------------------
// Address: 0x00403240
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x004032C0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004034B0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

} // namespace vice

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00454EB0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00454F30
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00455120
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x00455140
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00455190
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace vmap

// ============================================================
// Overlay from vmf_tweak (Missing functions)
// ============================================================
namespace vmf_tweak {

//------------------------------------------------------------------------------
// Address: 0x00403930
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x004039B0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403BA0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x00403BC0
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace vmf_tweak

// ============================================================
// Overlay from vmtcheck (Missing functions)
// ============================================================
namespace vmtcheck {

//------------------------------------------------------------------------------
// Address: 0x00403350
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403540
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x00403560
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  if ( g_pFullFileSystem != nullptr )
  {
    g_pFullFileSystem->Shutdown(this: g_pFullFileSystem);
    g_pFullFileSystem = nullptr;
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace vmtcheck

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x100837E0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(char *pFilename, char *pGameInfoPath)
{
  char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10083860
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( Sys_LoadInterface(
         pModuleName: "filesystem_stdio",
         pInterfaceVersionName: "VFileSystem017",
         pOutModule: &g_pFullFileSystemModule,
         pOutInterface: (void **)&g_pFullFileSystem) == 0
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10083A50
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(char *pBSPFilename, int maxMemoryUsage, FSInitType_t initType, bool bOnlyUseFilename)
{
  char result; // al
  IFileSystem *v5; // eax
  IFileSystem *v6; // eax

  if ( !g_bUseMPI )
    return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
  if ( g_bMPIMaster )
  {
    result = FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
    if ( result != 0 )
    {
      v5 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: g_pFullFileSystem);
      g_pFullFileSystem = v5;
      if ( v5 != nullptr )
        g_pFileSystem = &v5->IBaseFileSystem;
      else
        g_pFileSystem = nullptr;
      SendQDirInfo();
      return 1;
    }
  }
  else
  {
    v6 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: nullptr);
    g_pFullFileSystem = v6;
    if ( v6 != nullptr )
      g_pFileSystem = &v6->IBaseFileSystem;
    else
      g_pFileSystem = nullptr;
    RecvQDirInfo();
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083B20
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  IFileSystem *v0; // eax

  if ( g_bUseMPI )
  {
    v0 = VMPI_FileSystem_Term();
    g_pFullFileSystem = v0;
    if ( v0 == nullptr )
      goto LABEL_7;
    g_pFileSystem = &v0->IBaseFileSystem;
  }
  else
  {
    v0 = g_pFullFileSystem;
  }
  if ( v0 != nullptr )
  {
    v0->Shutdown(this: v0);
    g_pFullFileSystem = nullptr;
LABEL_7:
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vsoundedit (Missing functions)
// ============================================================
namespace vsoundedit {

//------------------------------------------------------------------------------
// Address: 0x004128C0
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x00412940
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412B30
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

} // namespace vsoundedit

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(const char *pFilename, const char *pGameInfoPath)
{
  const char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x100032B0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(const char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: (KeyValues *)&loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent((int)&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: (KeyValues *)&searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( !Sys_LoadInterface(
          pModuleName: "filesystem_stdio",
          pInterfaceVersionName: "VFileSystem017",
          pOutModule: &g_pFullFileSystemModule,
          pOutInterface: (void **)&g_pFullFileSystem)
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(
        const char *pBSPFilename,
        int maxMemoryUsage,
        FSInitType_t initType,
        bool bOnlyUseFilename)
{
  return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
}

//------------------------------------------------------------------------------
// Address: 0x100034C0
// Name: void __near * (*FileSystem_GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl FileSystem_GetFactory())(const char *, int *)
{
  return Sys_GetFactory(pModule: g_pFullFileSystemModule);
}

} // namespace vtex_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10021F40
// Name: void FileSystem_SetupStandardDirectories(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_SetupStandardDirectories(char *pFilename, char *pGameInfoPath)
{
  char *v2; // eax

  v2 = pFilename;
  if ( pFilename == nullptr )
    v2 = ".";
  V_MakeAbsolutePath(pOut: qdir, outLen: 1024, pPath: v2, pStartingDir: nullptr);
  V_StripFilename(path: qdir);
  _V_strlower(start: qdir);
  if ( qdir[0] != 0 )
    V_AppendSlash(pStr: qdir, strSize: 1024);
  V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: pGameInfoPath, pStartingDir: nullptr);
  V_AppendSlash(pStr: gamedir, strSize: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10021FC0
// Name: bool FileSystem_Init_Normal(char const __near *,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init_Normal(char *pFilename, FSInitType_t initType, bool bOnlyUseDirectoryName)
{
  CFSSearchPathsInit searchPathsInit; // [esp+4h] [ebp-538h] BYREF
  char fileSystemDLLName[260]; // [esp+210h] [ebp-32Ch] BYREF
  CFSLoadModuleInfo loadModuleInfo; // [esp+314h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+530h] [ebp-Ch] BYREF

  if ( initType == FS_INIT_FULL )
  {
    if ( FileSystem_GetFileSystemDLLName(pFileSystemDLL: fileSystemDLLName, nMaxLen: 260, bSteam: (bool *)&initType + 3) == FS_OK )
    {
      FileSystem_SetupSteamInstallPath();
      CFSLoadModuleInfo::CFSLoadModuleInfo(this: &loadModuleInfo);
      loadModuleInfo.m_pFileSystemDLLName = fileSystemDLLName;
      loadModuleInfo.m_pDirectoryName = pFilename;
      loadModuleInfo.m_bOnlyUseDirectoryName = bOnlyUseDirectoryName;
      loadModuleInfo.m_ConnectFactory = Sys_GetFactoryThis();
      loadModuleInfo.m_bSteam = HIBYTE(initType);
      loadModuleInfo.m_bToolsMode = true;
      if ( FileSystem_LoadFileSystemModule(fsInfo: &loadModuleInfo) == FS_OK )
      {
        CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
        mountContentInfo.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
        mountContentInfo.m_pFileSystem = loadModuleInfo.m_pFileSystem;
        mountContentInfo.m_bToolsMode = true;
        if ( FileSystem_MountContent(&mountContentInfo) == FS_OK )
        {
          CFSSearchPathsInit::CFSSearchPathsInit(this: &searchPathsInit);
          searchPathsInit.m_pDirectoryName = loadModuleInfo.m_GameInfoPath;
          searchPathsInit.m_pFileSystem = loadModuleInfo.m_pFileSystem;
          if ( FileSystem_LoadSearchPaths(initInfo: &searchPathsInit) == FS_OK )
          {
            g_pFullFileSystem = loadModuleInfo.m_pFileSystem;
            if ( loadModuleInfo.m_pFileSystem != nullptr )
              g_pFileSystem = &loadModuleInfo.m_pFileSystem->IBaseFileSystem;
            else
              g_pFileSystem = nullptr;
            g_pFullFileSystemModule = loadModuleInfo.m_pModule;
            FileSystem_AddSearchPath_Platform(
              pFileSystem: loadModuleInfo.m_pFileSystem,
              szGameInfoPath: loadModuleInfo.m_GameInfoPath);
            FileSystem_SetupStandardDirectories(pFilename, pGameInfoPath: loadModuleInfo.m_GameInfoPath);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  if ( Sys_LoadInterface(
         pModuleName: "filesystem_stdio",
         pInterfaceVersionName: "VFileSystem017",
         pOutModule: &g_pFullFileSystemModule,
         pOutInterface: (void **)&g_pFullFileSystem) == 0
    || g_pFullFileSystem->Init(this: g_pFullFileSystem) != INIT_OK )
  {
    return 0;
  }
  g_pFullFileSystem->RemoveAllSearchPaths(this: g_pFullFileSystem);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "../platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: ".", a3: "GAME", a4: PATH_ADD_TO_TAIL);
  if ( g_pFullFileSystem != nullptr )
    g_pFileSystem = &g_pFullFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100221B0
// Name: bool FileSystem_Init(char const __near *,int,enum FSInitType_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FileSystem_Init(char *pBSPFilename, int maxMemoryUsage, FSInitType_t initType, bool bOnlyUseFilename)
{
  char result; // al
  IFileSystem *v5; // eax
  IFileSystem *v6; // eax

  if ( !g_bUseMPI )
    return FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
  if ( g_bMPIMaster )
  {
    result = FileSystem_Init_Normal(pFilename: pBSPFilename, initType, bOnlyUseDirectoryName: bOnlyUseFilename);
    if ( result != 0 )
    {
      v5 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: g_pFullFileSystem);
      g_pFullFileSystem = v5;
      if ( v5 != nullptr )
        g_pFileSystem = &v5->IBaseFileSystem;
      else
        g_pFileSystem = nullptr;
      SendQDirInfo();
      return 1;
    }
  }
  else
  {
    v6 = VMPI_FileSystem_Init(maxMemoryUsage, pPassThru: nullptr);
    g_pFullFileSystem = v6;
    if ( v6 != nullptr )
      g_pFileSystem = &v6->IBaseFileSystem;
    else
      g_pFileSystem = nullptr;
    RecvQDirInfo();
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022280
// Name: void FileSystem_Term(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FileSystem_Term()
{
  IFileSystem *v0; // eax

  if ( g_bUseMPI )
  {
    v0 = VMPI_FileSystem_Term();
    g_pFullFileSystem = v0;
    if ( v0 == nullptr )
      goto LABEL_7;
    g_pFileSystem = &v0->IBaseFileSystem;
  }
  else
  {
    v0 = g_pFullFileSystem;
  }
  if ( v0 != nullptr )
  {
    v0->Shutdown(this: v0);
    g_pFullFileSystem = nullptr;
LABEL_7:
    g_pFileSystem = nullptr;
  }
  if ( g_pFullFileSystemModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pFullFileSystemModule);
    g_pFullFileSystemModule = nullptr;
  }
}

} // namespace vvis_dll
